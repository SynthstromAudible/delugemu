#!/usr/bin/env python3
"""Render folded stacks ("a;b;c count" lines, e.g. from tools/perf/flame.py) as a self-contained HTML flame graph.

Hover a frame for its counts, click to zoom into it (click the bottom bar to zoom out), type in the search box to
highlight matching frames with their total share. With several inputs, each becomes a tab.

  tools/perf/flamegraph.py -o flame.html --title "MYAD" build/perf/flame-myad/stacks.folded
  tools/perf/flamegraph.py -o flame.html myad=a/stacks.folded cordae=b/stacks.folded
"""
import argparse
import html
import json
import os


def tree(path):
    root = {"n": "all", "v": 0, "c": {}}
    for line in open(path):
        line = line.rstrip("\n")
        if not line:
            continue
        stack, count = line.rsplit(" ", 1)
        count = int(count)
        node = root
        node["v"] += count
        for frame in stack.split(";"):
            node = node["c"].setdefault(frame, {"n": frame, "v": 0, "c": {}})
            node["v"] += count

    def pack(n):
        return [n["n"], n["v"], [pack(c) for c in sorted(n["c"].values(), key=lambda c: -c["v"])]]

    return pack(root)


PAGE = r"""<!DOCTYPE html>
<html><head><meta charset="utf-8"><title>%(title)s</title>
<style>
body { font: 12px -apple-system, Helvetica, sans-serif; margin: 12px; background: #fafafa; color: #222; }
#bar { display: flex; gap: 8px; align-items: center; margin-bottom: 6px; flex-wrap: wrap; }
#bar button { font: inherit; padding: 3px 10px; border: 1px solid #bbb; background: #fff; border-radius: 4px; cursor: pointer; }
#bar button.on { background: #333; color: #fff; border-color: #333; }
#search { font: inherit; padding: 3px 6px; width: 260px; }
#info { height: 1.4em; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: #444; }
#graph { position: relative; width: 100%%; }
.f { position: absolute; height: 17px; box-sizing: border-box; border: 0.5px solid #fafafa; overflow: hidden;
     white-space: nowrap; font-size: 11px; line-height: 16px; padding-left: 3px; cursor: pointer; }
.f.hit { background: #e040fb !important; }
</style></head><body>
<h3 style="margin:0 0 6px 0">%(title)s</h3>
<div id="bar"><span id="tabs"></span><input id="search" placeholder="search (regex)"><span id="match"></span></div>
<div id="info">%(subtitle)s</div>
<div id="graph"></div>
<script>
const DATA = %(data)s;
const H = 17;
let cur = 0, zoom = null, re = null;
const graph = document.getElementById('graph'), info = document.getElementById('info');
function hue(name) {
  let h = 0; for (let i = 0; i < name.length; i++) h = (h * 31 + name.charCodeAt(i)) | 0;
  const r = 205 + (Math.abs(h) %% 50), g = 80 + (Math.abs(h >> 8) %% 130), b = 40 + (Math.abs(h >> 16) %% 40);
  return `rgb(${r},${g},${b})`;
}
// Label: qualified name without the parameter list or clone suffix (the tooltip has the full name)
function short(name) {
  const s = name.replace(/\(anonymous namespace\)/g, '(anon)').replace(/ \[clone [^\]]*\]/g, '');
  const i = s.indexOf('(', s.startsWith('(anon)') ? 6 : 0);
  return i > 0 ? s.slice(0, i) : s;
}
function depthOf(n) { let d = 0; for (const c of n[2]) d = Math.max(d, depthOf(c)); return d + 1; }
function render() {
  const root = DATA[cur].tree, total = root[1];
  const base = zoom || {node: root, path: [root]};
  const width = graph.clientWidth, maxd = depthOf(base.node) + base.path.length - 1;
  graph.innerHTML = ''; graph.style.height = (maxd * H + 4) + 'px';
  let matched = 0;
  const frag = document.createDocumentFragment();
  function box(n, x, w, d, ancestor) {
    const el = document.createElement('div');
    el.className = 'f'; el.style.left = x + 'px'; el.style.width = Math.max(w, 1) + 'px';
    el.style.top = ((maxd - 1 - d) * H) + 'px'; el.style.background = ancestor ? '#ddd' : hue(n[0]);
    if (w > 30) el.textContent = short(n[0]);
    const pct = (100 * n[1] / total).toFixed(2);
    el.title = `${n[0]}\n${n[1].toLocaleString()} instructions (${pct}%%)`;
    el.onmouseenter = () => info.textContent = `${n[0]} — ${n[1].toLocaleString()} instructions, ${pct}%% of total`;
    el.onclick = (e) => { e.stopPropagation(); zoomTo(n, d); };
    if (re && re.test(n[0])) el.classList.add('hit');
    frag.appendChild(el);
  }
  // ancestors of the zoomed frame, full width
  base.path.slice(0, -1).forEach((n, d) => box(n, 0, width, d, true));
  const d0 = base.path.length - 1;
  (function walk(n, x, w, d) {
    if (w < 0.3) return;
    box(n, x, w, d, false);
    let cx = x;
    for (const c of n[2]) { const cw = w * c[1] / n[1]; walk(c, cx, cw, d + 1); cx += cw; }
  })(base.node, 0, width, d0);
  graph.appendChild(frag);
  if (re) {
    // total share of matching frames, not double counting nested matches
    (function m(n, inside) {
      const hit = !inside && re.test(n[0]);
      if (hit) matched += n[1];
      for (const c of n[2]) m(c, inside || hit);
    })(root, false);
    document.getElementById('match').textContent = `matched ${(100 * matched / total).toFixed(2)}%%`;
  } else document.getElementById('match').textContent = '';
}
function zoomTo(n, d) {
  const root = DATA[cur].tree;
  if (n === root) { zoom = null; render(); return; }
  // find the path to this node
  const path = [];
  (function find(x) {
    path.push(x);
    if (x === n) return true;
    for (const c of x[2]) if (find(c)) return true;
    path.pop(); return false;
  })(root);
  zoom = {node: n, path};
  render();
}
const tabs = document.getElementById('tabs');
DATA.forEach((d, i) => {
  const b = document.createElement('button'); b.textContent = d.name;
  b.onclick = () => { cur = i; zoom = null; [...tabs.children].forEach((x, j) => x.classList.toggle('on', j === i)); render(); };
  tabs.appendChild(b);
});
if (DATA.length > 1) tabs.children[0].classList.add('on'); else tabs.style.display = 'none';
document.getElementById('search').oninput = (e) => {
  try { re = e.target.value ? new RegExp(e.target.value) : null; } catch (_) { re = null; }
  render();
};
window.onresize = render;
render();
</script></body></html>
"""


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("inputs", nargs="+", help="stacks.folded, or name=stacks.folded")
    ap.add_argument("-o", "--output", required=True)
    ap.add_argument("--title", default="Flame graph")
    ap.add_argument("--subtitle", default="Instructions executed, by call stack. Hover for counts, click to zoom.")
    args = ap.parse_args()

    data = []
    for spec in args.inputs:
        name, _, path = spec.rpartition("=")
        data.append({"name": name or os.path.basename(os.path.dirname(os.path.abspath(path))), "tree": tree(path)})
    with open(args.output, "w") as f:
        f.write(PAGE % {"title": html.escape(args.title), "subtitle": html.escape(args.subtitle),
                        "data": json.dumps(data, separators=(",", ":")).replace("</", "<\\/")})
    print(args.output)


if __name__ == "__main__":
    main()
