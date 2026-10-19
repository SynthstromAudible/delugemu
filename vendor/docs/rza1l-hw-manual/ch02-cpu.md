# 2. CPU

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 79–80. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This product incorporates the Arm single-core Cortex-A9 MPCore, where the IP version is r3p0.

## 2.1 Features[*][1]

- Instruction cache size: 32 Kbytes

- Data cache size[*2] : 32 Kbytes

- TLB entries: 128 entries

- Jazelle architecture extension: Full

- Media processing engine with NEON technology: Included

- FPU: Included

- PTM interface: Included

- Wrappers to support for power off and dormant mode: Not included

- Preload engine: Not included

- Number of interrupts: 0 (On-chip interrupt controller is not used.)

- Accelerator Coherence Port: Not included

Note 1. For details, refer to Cortex-A9 MPCore Technical Reference Manual issued by Arm Ltd.

Note 2. Contents of memory regions which are set as write-through are not cached even if data caching is enabled. For details, refer to Cortex-A9 Technical Reference Manual issued by Arm Ltd.

## 2.2 Configuration Signals

Table 2.1 shows the Cortex-A9 configuration signals and the settings.

## **Table 2.1 Cortex-A9 Configuration Signal Settings**

|**Configuration Signal**|**Setting Values**|
|---|---|
|CFGEND|1’b0|
|CFGNMIF|1’b1|
|CLUSTERID|4'h0|
|FILTEREN*1|1’b1|
|FILTERSTART[31:20]*1|12’hE00|
|FILTEREND[31:20]*1|12’hFFF|
|PERIPHBASE[31:13]*2|19’b111_1000_0000_0000_0000|
|TEINIT|1’b0|
|VINITHI|NOR, SRAM boot: 1’b0; on-chip ROM boot: 1’b1|

Note 1. Do not change the initial settings of these signals by software.

Note 2. The base address for the private memory area in the Cortex-A9 processor is H'F0000000. For details  and overview of the registers located in the addresses relative to this base address, refer to Cortex-A9 MPCore Technical Reference Manual issued by Arm Ltd.
