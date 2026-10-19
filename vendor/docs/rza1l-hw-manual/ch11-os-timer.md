# 11. OS Timer

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 527–541. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 11.1 Functional Overview

The OS timer has the following features.

- Two operating modes

– Interval timer mode

– Free-running comparison mode

- Choice between startup of DMA by compare match and generation of interrupt

## 11.1.1 Features of OSTM

## Channels

This product has the following number of channels of the OS timer.

## **Table 11.1 Channels of OS timer**

||**OS Timer**|
|---|---|
|Number of Channels|2|
|Name|OSTMn|

## Meaning of n

Throughout this section, the individual channels of the OS timer are identified by the index "n" (n = 0, 1), for example OSTMnTO for the OS timer n output register.

## Register address

The register addresses of the OS timer are given as offsets from the individual base addresses <OSTMn_base>.

The register base addresses of each OSTMn are listed in the following table.

## **Table 11.2 Register Base Addresses**

|**Base Address Name**|**Base Address**|
|---|---|
|<OSTM0_base>|FCFE C000H|
|<OSTM1_base>|FCFE C400H|

## Interrupts

The OS timers can generate the following interrupt requests.

## **Table 11.3 OSTMn Interrupt Requests**

|**OSTMn Signal**|**Function**|**Startup of Direct Memory Access Controller**|
|---|---|---|
|OSTM0TINT|OSTM0interrupt|√|
|OSTM1TINT|OSTM1interrupt|√|

## 11.2 Registers

The OS timer is controlled and operated by the following registers.

## 11.2.1 Registers Overview

The list of OSTMn (n = 0, 1) registers and the memory addresses are as follows.

For the base addresses, see the Table 11.2 .

For the actual addresses, the offset values indicated in the following table are added to the base addresses.

|**Register**<br>**Name**<br>**Function**<br>**R/W**<br>**Reset Value**|**Access Unit**<br>**(bit)**<br>**Address**<br>**8**<br>**16**<br>**32**|
|---|---|
|OSTMnCMP<br>OSTM compare register<br>R/W<br>0000 0000H|—<br>—<br>√<br><OSTMn_base> + 00H|
|OSTMnCNT<br>OSTM counter register<br>R<br>FFFF FFFFH|—<br>—<br>√<br><OSTMn_base> + 04H|
|OSTMnTE<br>OSTM count enable status register<br>R<br>00H|√<br>—<br>—<br><OSTMn_base> + 10H|
|OSTMnTS<br>OSTM count start trigger register<br>W<br>00H|√<br>—<br>—<br><OSTMn_base> + 14H|
|OSTMnTT<br>OSTM count stop trigger register<br>W<br>00H|√<br>—<br>—<br><OSTMn_base> + 18H|
|OSTMnCTL<br>OSTM control register<br>R/W<br>00H|√<br>—<br>—<br><OSTMn_base> + 20H|

## 11.2.2 Details of OSTM Registers

## 11.2.2.1 OSTMnCMP — OSTM Compare Register

Depending on the mode of operation, this register holds the start value for the down-counter or the value for comparison with that of the counter.

**Access:** This register is readable/writable in 32-bit units. **Address:** <OSTMn_base> **Initial value:** 0000 0000H Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 OSTMnCMP[31:16] R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W Bit 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 OSTMnCMP[15:0] R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W

## **Table 11.4 OSTMnCMP register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 0|OSTMnCMP|In interval timer mode: start value of the down-counter|
|||[31:0]|In free-running comparison mode: value for comparison|

## 11.2.2.2 OSTMnCNT — OSTM Counter Register

This register indicates the counter value of the timer.

**Access:** This register is readable in 32-bit units. **Address:** OSTMn_base> + 4H **Initial value:** The initial value depends on the operating mode of the OS timer. Refer to Table 11.6, Correspondence between Operating Mode, Counting Direction and Initial Value.

**==> picture [468 x 111] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>OSTMnCNT[31:16]<br>R/W R R R R R R R R R R R R R R R R<br>Bit 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>OSTMnCNT[15:0]<br>R/W R R R R R R R R R R R R R R R R<br>**----- End of picture text -----**<br>

## **Table 11.5 OSTMnCNT register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 0|OSTMnCNT|32-bit counter value|
|||[31:0]||

The following table shows the correspondence between operating mode, counting direction and initial value. The initial value is the value read from the counter after a change to the operating mode.

## **Table 11.6 Correspondence between Operating Mode, Counting Direction and Initial Value**

|**Timer Operating Mode**|**OSTMnCTL.OSTMnMD1**|**Counting Direction**|**Initial value**|
|---|---|---|---|
|Interval timer mode|0 *1|Down|FFFFFFFFH|
|Free-running comparison mode|1|Up|00000000H|

Note 1. Value after reset

## 11.2.2.3 OSTMnTE — OSTM Count Enable Status Register

This register indicates whether the counter is enabled or disabled.

||||**Access:**|**Access:**|This register is readable in 8-bit units.|This register is readable in 8-bit units.|||||
|---|---|---|---|---|---|---|---|---|---|---|
||||**Address:**||<OSTMn_base>+ 10H||||||
||||**Initial value:**||00H||||||
|Bit|||7||6|5<br>4|3|2|1|0|
||||0||0|0<br>0|0|0|0|OSTMnTE|
|R/W|||R||R|R<br>R|R|R|R|R|
||**Table 11.7**||||**OSTMnTE register contents**||||||
|||**Bit Position**||**Bit Name**||**Function**|||||
|||7 to|1|Reserved||Reserved|||||
|||||||These bits are always read as 0. The||write value should always be 0.|||
|||0||OSTMnTE||This bit indicates whether the counter is enabled or|||disabled.||
|||||||0: Counter disabled|||||
|||||||1: Counter enabled|||||
|||||||This bit is set to 1 in response to OSTMnTS.OSTMnTS being set to 1.|||||
|||||||This bit is reset to 0 in|response to OSTMnTT.OSTMnTT being set to 1.||||

## **NOTE**

When OSTMnTE = 0, the counter retains its value.

If the counter is restarted, it

 restarts counting down from the value in the OSTMnCMP register if it is in interval timer mode or

- restarts counting up from the counter value 0000 0000H if it is in free running comparison mode.

## 11.2.2.4 OSTMnTS — OSTM Count Start Trigger Register

This register starts the counter.

|||**Access:**|**Access:**|This register is writable in 8-bit units. It is always read as 00H.|This register is writable in 8-bit units. It is always read as 00H.|This register is writable in 8-bit units. It is always read as 00H.|This register is writable in 8-bit units. It is always read as 00H.|This register is writable in 8-bit units. It is always read as 00H.||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|||**Address:**||<OSTMn_base>+ 14H||||||||
|||**Initial value:**||00H||||||||
|Bit||7||6|5|4|3||2|1|0|
|||0||0|0|0|0||0|0|OSTMnTS|
|R/W||R||R|R|R|R||R|R|W|

## **Table 11.8 OSTMnTS register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 1|Reserved|Reserved|
|||These bits are always read as 0. The write value should always be 0.|
|0|OSTMnTS|This bit starts the counter.|
|||0: This setting has no effect.|
|||1: Starts the counter and sets OSTMnTE.OSTMnTE = 1.|
|||In interval timer mode, a forced restart is executed if this bit is set while|
|||OSTMnTE.OSTMnTE = 1.|
|||In free-running comparison mode, setting this bit is ignored as long as|
|||OSTMnTE.OSTMnTE = 1.|

## 11.2.2.5 OSTMnTT — OSTM Count Stop Trigger Register

This register stops the counter.

|||**Access:**|**Access:**|This register is writable in 8-bit units. It is always read as 00H.|This register is writable in 8-bit units. It is always read as 00H.|This register is writable in 8-bit units. It is always read as 00H.|This register is writable in 8-bit units. It is always read as 00H.|This register is writable in 8-bit units. It is always read as 00H.||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|||**Address:**||<OSTMn_base>+ 18H||||||||
|||**Initial value:**||00H||||||||
|Bit||7||6|5|4|3||2|1|0|
|||0||0|0|0|0||0|0|OSTMnTT|
|R/W||R||R|R|R|R||R|R|W|

## **Table 11.9 OSTMnTT register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 1|Reserved|Reserved|
|||These bits are always read as 0. The write value should always be 0.|
|0|OSTMnTT|Stops the counter.|
|||0: This setting has no effect.|
|||1: Stops the counter and clears the OSTMnTE.OSTMnTE bit.|

## 11.2.2.6 OSTMnCTL — OSTM  Control Register

This register specifies the operating mode for the counter and controls enabling/disabling of OSTMnTINT interrupt requests when counting starts.

||**Access:**|**Access:**|This register is readable/writable in 8-bit units. Writing to this register is only possible if the counter is disabled|This register is readable/writable in 8-bit units. Writing to this register is only possible if the counter is disabled|This register is readable/writable in 8-bit units. Writing to this register is only possible if the counter is disabled|This register is readable/writable in 8-bit units. Writing to this register is only possible if the counter is disabled|This register is readable/writable in 8-bit units. Writing to this register is only possible if the counter is disabled|This register is readable/writable in 8-bit units. Writing to this register is only possible if the counter is disabled|
|---|---|---|---|---|---|---|---|---|
||||(OSTMnTOE.OSTMnTOE|= 0).|||||
||**Address:**||<OSTMn_base>+ 20H||||||
||**Initial value:**||00H||||||
|Bit|7||6<br>5|4|3|2|1|0|
||0||0<br>0|0|0|0|OSTMnMD1|OSTMnMD0|
|R/W|R||R<br>R|R|R|R|R/W|R/W|

## **Table 11.10 OSTMnCTL register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 2|Reserved|Reserved|
|||These bits are always read as 0. The write value should always be 0.|
|1|OSTMnMD1|Specifies the operating mode for the counter.|
|||0: Interval timer mode|
|||1: Free-running comparison mode|
|0|OSTMnMD0|Controls enabling/disabling of OSTMnTINT interrupt requests when counting|
|||starts.|
|||0: Disables the interrupts when counting starts.|
|||1: Enables the interrupts when counting starts.|

## 11.3 Functional Description

Each OS timer is a 32-bit timer/counter.

The settings for operating mode specify the direction of counting (up or down) and the generation of interrupt requests.

## 11.3.1 Block Diagram

The following block diagram shows the main components of OSTM.

**==> picture [454 x 223] intentionally omitted <==**

**----- Start of picture text -----**<br>
Count clock<br>underflow<br>32-bit counter<br>on match OSTMTINT<br>OSTMnCNT OSTMnCMP<br>Start trigger<br>control Set<br>OSTMnTE<br>Reset<br>OSTMnTS OSTMnTT OSTMnCTL<br>Internal bus<br>Start interrupt enable/ disable selection<br>INT  generation<br>Count enable<br>Timer mode selection<br>**----- End of picture text -----**<br>

**Figure 11.1 Block Diagram of OSTM**

## 11.3.2 Count Clock

The count clock of OSTMn is P0  .

## 11.3.3 Generation of Interrupt Request

An OSTMnTINT interrupt request is generated whenever the counter reaches 0000 0000H (in interval timer mode) or matches the comparison value (in free-running comparison mode).

An interrupt request can also be generated on starting and restarting of the counter. This is controlled by the OSTMnCTL.OSTMnMD0 bit.

This operation is shown in the following figure.

**==> picture [394 x 322] intentionally omitted <==**

**----- Start of picture text -----**<br>
OSTMnTS<br>OSTMnTT<br>OSTMnTE Counter operating Counter operating<br>OSTMnCMP A B<br>FFFF FFFFH<br>OSTMnCNT<br>A A<br>0000 0000H B B B B B<br>A + 1 A + 1 B + 1 B + 1 B + 1<br>OSTMnMD0 = 1 (Enabling an interrupt at the start of counting)<br>OSTMTINT<br>OSTMnMD0 = 0 (Disabling an interrupt at the start of counting)<br>OSTMTINT<br>**----- End of picture text -----**<br>

**Figure 11.2 Generating an Interrupt when Counting Starts (in Interval Timer Mode)**

## 11.3.4 Starting and Stopping the Timer

The OS timer is started and stopped as follows.

## Starting the timer

The timer is started in either of the following way:

- setting the OSTMnTS.OSTMnTSF bit to 1

Status bit OSTMnTE.OSTMnTE is set to 1.

The counter starts to count up or down in accord with the settings for operating mode.

## Stopping the timer

Setting the OSTMnTT.OSTMnTT bit to 1 stops the timer.

This also clears the OSTMnTE.OSTMnTE status flag.

## 11.3.5 Interval Timer Mode

Select the interval timer mode when an OS timer is to be used as a reference timer for generating interrupt requests at a fixed interval.

## 11.3.5.1 Basic Operation in Interval Timer Mode

In interval timer mode, the timer counts down from the value specified in the OSTMnCMP register. An OSTMnTINT interrupt request is generated when the counter reaches 0000 0000H.

Select interval timer mode by setting OSTMnCTL.OSTMnMD1 = 0.

New values can be written to the OSTMnCMP register at any time. If it is rewritten during count operation, the counter loads the new OSTMnCMP value when the next 0000 0000H is reached.

## Cycles of OSTMnTINT output

The cycle of OSTMnTINT output is as follows.

- OSTMnTINT generation cycle = counter-clock cycle × (OSTMnCMP + 1)

The following figure shows the basic operation of OSTM when counter-start interrupts is enabled in interval timer mode.

**==> picture [394 x 255] intentionally omitted <==**

**----- Start of picture text -----**<br>
OSTMnTS<br>OSTMnTT<br>OSTMnTE Counter operating Counter operating<br>OSTMnCMP A B<br>FFFF FFFFH<br>OSTMnCNT<br>A A<br>0000 0000H B B B B B<br>A + 1 A + 1 B + 1 B + 1 B + 1<br>OSTMTINT<br>(1) (2) (2) (2) (2) (3) (4) (2)<br>**----- End of picture text -----**<br>

**Figure 11.3 Timing Diagram of OSTM in Interval Timer Mode**

The timing diagram above shows the following:

- (1) The counter starts counting when OSTMnTS.OSTMnTS = 1. The OSTMnTE.OSTMnTE bit is set to indicate enabling of the counter. The counter starts counting down from the value of OSTMnCMP. If OSTMnCTL.OSTMnMD0 is 1, OSTMTINT interrupt requests are generated at the start of counting. The OSTMnCNT register contains the current value as the counter.

- (2) When the counter reaches 0000 0000H, an OSTMTINT interrupt request is generated. The counter loads the new start value from OSTMnCMP and continues counting down.

- (3) When the counter is stopped (OSTMnTT.OSTMnTT = 1), the OSTMnTE.OSTMnTE bit is cleared to indicate disabling of the counter. The counter retains its current value until it is restarted.

- (4) When counting is restarted (OSTMnTS.OSTMnTS = 1), the counter loads the new start value from OSTMnCMP and starts counting down.

## Forced restart

The counter is forcibly restarted by setting OSTMnTS.OSTMnTS = 1 during counting.

The counter loads the start value from the OSTMnCMP register and continues to count down.

The following figure shows the forced restart of the OS Timer in interval timer mode, with counterstart interrupts enabled (OSTMnCTL.OSTMnMD0 = 1).

**==> picture [387 x 232] intentionally omitted <==**

**----- Start of picture text -----**<br>
OSTMnTS<br>OSTMnTT<br>Counter operating<br>OSTMnTE<br>OSTMnCMP A B<br>FFFF FFFFH<br>A A A A<br>OSTMnCNT<br>0000 0000H B B B B<br>OSTMTINT<br>(1) (2)<br>**----- End of picture text -----**<br>

**Figure 11.4 Timing Diagram of Forced Restart in Interval Timer Mode**

Operations shown in the above timing diagram are as follows.

- (1) The counter is started and stopped as described under Figure 11.3, Timing Diagram of OSTM in Interval Timer Mode .

- (2) Setting OSTMnTS.OSTMnTS = 1 restarts the counter while counting is in progress (i.e. while OSTMnTE.OSTMnTE = 1).

   - The counter immediately restarts counting down, starting with the current value of OSTMnCMP. When OSTMnCTL.OSTMnMD0 = 1, an OSTMTINT interrupt request is generated when counting starts.

## 11.3.5.2 Operation when OSTMnCMP = 0000 0000H

When OSTMnCMP = 0000 0000H, OSTM behaves as follows.

- When the counter is enabled, the OSTMTINT interrupt request is always set to 1.

The following figure shows operations of OSTM when OSTMnCMP = 0000 0000H, and counter-start interrupts are enabled.

**==> picture [391 x 242] intentionally omitted <==**

**----- Start of picture text -----**<br>
Count Clock<br>OSTMnTS<br>OSTMnTT<br>Counter operating Counter operating<br>OSTMnTE<br>OSTMnCMP 0000 0000H<br>FFFF FFFFH<br>OSTMnCNT<br>0000 0000H<br>OSTMTINT<br>(1) (2) (3)<br>**----- End of picture text -----**<br>

**Figure 11.5 Timing Diagram when OSTMnCMP = 0000 0000H in Interval Timer Mode**

The timing diagram above shows the following operations:

- (1) The counter is reloaded with the value in OSTMnCMP as soon as it starts counting, so the value 0000 0000H is retained in OSTMnCMP.

- (2) The OSTMTINT interrupt request is continuously asserted.

- (3) After the counter stops, the OSTMTINT interrupt request signal is deasserted.

- (4) When interrupts on starting of the counter are disabled, no interrupt is generated when counting starts.

## 11.3.6 Free-Running Comparison Mode

## 11.3.6.1 Basic Operation in Free-Running Comparison Mode

In free-running comparison mode, the counter counts up from 0000 0000H to FFFF FFFFH. An OSTMnTINT interrupt request is output when the current value of the counter matches the value of the OSTMnCMP register. The free-running comparison mode is selected by setting the OSTMnCTL.OSTMnMD1 bit to 1.

New values can be written to the OSTMnCMP register at any time.

The following figure shows the basic operation of OSTM in free-run compare mode with the start of counting enabled (OSTMnCTL.OSTMnMD0 = 1).

**==> picture [386 x 205] intentionally omitted <==**

**----- Start of picture text -----**<br>
OSTMnTS<br>OSTMnTT<br>OSTMnTE Counter operating<br>OSTMnCMP A B C D E<br>FFFF FFFFH A A C<br>OSTMnCNT B D E<br>0000 0000H<br>(a) (b) (c) (d)<br>OSTMTINT<br>(1) (2) (2) (2) (2) (2) (3) (4) (2)<br>**----- End of picture text -----**<br>

**Figure 11.6 Timing Diagram of OSTM in Free-Run Compare Mode**

The timing diagram above shows the following:

- (1) The counter starts counting when OSTMnTS.OSTMnTS = 1. The OSTMnTE.OSTMnTE bit is set to indicate enabling of the counter. The counter counts up from 0000 0000H to FFFF FFFFH. The OSTMnCNT register is the counter, so it contains the current value.

When OSTMnCTL.OSTMnMD0 = 1, an OSTMTINT interrupt request is generated at the start of counting.

- (2) When the current counter value matches the value in the OSTMnCMP register, an OSTMTINT interrupt request is generated.

- (3) When the counter is stopped (OSTMnTT.OSTMnTT = 1), the OSTMnTE.OSTMnTE bit is cleared to indicate disabling of the counter. The counter retains its current value until it is restarted.

- (4) Counting by the counter restarts from 0000 0000H when OSTMnTS.OSTMnTS = 1.

## OSTMTINT period

The OSTMTINT generation period is different at the start of counting and depends on the old and new compare values if OSTMnCMP is rewritten during operation.

## **Table 11.11 OSTMTINT Generation Timing**

|**Old Value for**<br>**Comparison**|**New Value for**<br>**Comparison**|**Counter Value at**<br>**Time of Rewriting**|**Period of OSTMTINT Generation**|**Label in**<br>**Timing**<br>**Diagram**|
|---|---|---|---|---|
|Counter starts|||(A + 1)×counter clock period|(a)|
|A|A|No rewriting|(FFFF FFFFH+ 1)×counter clock period|(b)|
|B|C > B|B < counter value < C|(C – B)×counter clock period|(c)|
|C|D < C|Counter value > D,C|(FFFF FFFFH– C + D + 1)×counter clock period|(d)|

## Forced restart

Forced restarting does not proceed during counting even if the OSTMnTS.OSTMnTS bit is set.

The counter ignores the attempted setting and continues counting.

## 11.3.6.2 Operation when OSTMnCMP = 0000 0000H

The following figure shows the operation of OSTM when OSTMnCMP = 0000 0000H, and counterstart interrupts are enabled (OSTMnCTL.OSTMnMD0 = 1).

**==> picture [370 x 227] intentionally omitted <==**

**----- Start of picture text -----**<br>
Count Clock<br>OSTMnTS<br>OSTMnTE Counter operating<br>OSTMnCMP 0000 0000H<br>FFFF FFFFH<br>OSTMnCNT<br>0000 0000H<br>OSTMTINT<br>(1)(2)(3) (4) (4) (4)<br>**----- End of picture text -----**<br>

**Figure 11.7 Timing Diagram when OSTMnCMP = 0000 0000H in Free-Run Compare Mode**

The timing diagram above shows the following operations.

- (1) Once the counter starts, it counts up from 0000 0000H to FFFF FFFFH.

- (2) An OSTMTINT interrupt request is generated when counting starts.

- (3) If the current counter value matches OSTMnCMP, an OSTMTINT interrupt request is generated. If OSTMnCMP = 0000 0000H in the above case, OSTMTINT is generated over two clock cycles.

(4) Every (FFFF FFFFH + 1) clock cycles the OSTMTINT interrupt request is asserted.

When interrupts on starting of the counter are disabled, no interrupt is generated when counting starts.
