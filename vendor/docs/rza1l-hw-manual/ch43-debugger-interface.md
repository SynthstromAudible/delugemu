# 43. Debugger Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2264–2284. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI incorporates a debugger interface to support the boundary scan function and connection to the emulator.

## 43.1 Features

The debugger interface is a serial input/output interface which has a JTAG (Joint Test Action Group, IEEE Std.1149.1 and IEEE Standard Test Access Port and Boundary-Scan Architecture) interface and CoreSight debug interface.

This module has TAP controllers for the boundary scan and CoreSight debug function.

Driving the BSCANP pin high selects the boundary-scan TAP controller, and driving the BSCANP pin low selects the CoreSight debug TAP controller.

Figure 43.1 is a block diagram of this module and Table 43.1 shows the JTAG pin mode.

**==> picture [267 x 211] intentionally omitted <==**

**----- Start of picture text -----**<br>
Pin multiplexer<br>Boundary-scan TAP<br>controller<br>BSBPR<br>TDI BSIR<br>SDBSR<br>BSID<br>TDO<br>TCK<br>TMS<br>CoreSight debug TAP<br>TRST controller<br>BSCANP<br>**----- End of picture text -----**<br>

**Figure 43.1 Block Diagram**

## **Table 43.1 JTAG Pin Mode**

|**BSCANP**|**JTAG Pin Mode**|
|---|---|
|0|Normal operation (CoreSight debug mode)|
|1|Boundary-scan mode|

The following lists the features of CoreSight.

- JTAG interface Supports JTAG and serial wire debug mode (SWD)

- Trace interface Outputs 4-bit × 66-Mbps (33-MHz DDR) trace data

   - 4-Kbyte Embedded Trace FIFO (ETF)

- Controls by ICE registers

   - Control of resetting, debug-enable signal supplied to the CPU, and disabling power shut-off in deep-standby mode during debugging (fake debug mode)

Figure 43.2 is a block diagram of CoreSight, Table 43.2 to Table 43.5 show the input/output pins of the cross-trigger interface (CTI), and Table 43.6 shows the address map for CoreSight. For details of CoreSight other than ICE registers, see the technical reference manual issued by Arm Ltd.

**==> picture [395 x 233] intentionally omitted <==**

**----- Start of picture text -----**<br>
AHB, APB<br>JTAG/SWD DAP<br>Debug-APB<br>SYS SYS SYS<br>DAP<br>ROM ICEReg CTI0 CTI1 CTI2<br>(Not used) (Not used) (Not used)<br>CTM<br>CTM<br>Trace<br>output<br>2nd CPU CA9<br>CPU ETF PTM-A9 CA9 CPU<br>DAP Trace CTI<br>ROM TPIU 4 KBytes Funnel  × 1  × 1 × 1 CTICS<br>Debug-APB<br>Debug-APB<br>**----- End of picture text -----**<br>

**Figure 43.2 Block Diagram of CoreSight**

**Table 43.2 CA9 CTI Trigger Inputs**

|**Trigger Input Bit**|**Trigger Signal**|**Source Device**|
|---|---|---|
|[7]|Not used|—|
|[6]|TRIGGER|PTM-A9|
|[5]|COMMRX|CA9|
|[4]|COMMTX|CA9|
|[3]|EXTOUT[1]|PTM-A9|
|[2]|EXTOUT[0]|PTM-A9|
|[1]|PMUIRQ|CA9|
|[0]|DBGACK|CA9|

**Table 43.3 CA9 CTI Trigger Outputs**

|**Trigger Input Bit**|**Trigger Signal**|**Destination Device**|
|---|---|---|
|[7]|DBGRESTART|CA9|
|[6]|nCTIIRQ|INTC|
|[5]|Not used|—|
|[4]|EXTIN[3]|PTM-A9|
|[3]|EXTIN[2]|PTM-A9|
|[2]|EXTIN[1]|PTM-A9|
|[1]|EXTIN[0]|PTM-A9|
|[0]|EDBGRQ|CA9|

## **Table 43.4 CPU CTICS Trigger Inputs**

|**Trigger Input Bit**|**Trigger Signal**|**Source Device**|
|---|---|---|
|[7]|Not used|—|
|[6]|Not used|—|
|[5]|Not used|—|
|[4]|Not used|—|
|[3]|ACQCOMP|ETF|
|[2]|FULL|ETF|
|[1]|Not used|—|
|[0]|Not used|—|

## **Table 43.5 CA9 CTI Trigger Outputs**

|**Trigger Input Bit**|**Trigger Signal**|**Destination Device**|
|---|---|---|
|[7]|Not used|—|
|[6]|Not used|—|
|[5]|Not used|—|
|[4]|Not used|—|
|[3]|TRIGIN|CPU TPIU|
|[2]|FLUSHIN|CPU TPIU|
|[1]|TRIGIN|ETF|
|[0]|FLUSHIN|ETF|

## **Table 43.6 Address Map for CoreSight**

|**System Address (Viewed from CPU)**|**Debug-APB Address (Viewed from Debugger)**|**Module**|
|---|---|---|
|H'FC000000 to H'FC000FFF|H'80000000 to H'80000FFF|DAP ROM|
|H'FC001000 to H'FC001FFF|H'80001000 to H'80001FFF|Reserved|
|H'FC002000 to H'FC002FFF|H'80002000 to H'80002FFF|SYS-CTI0|
|H'FC003000 to H'FC003FFF|H'80003000 to H'80003FFF|Reserved|
|H'FC004000 to H'FC004FFF|H'80004000 to H'80004FFF|Reserved|
|H'FC005000 to H'FC005FFF|H'80005000 to H'80005FFF|Reserved|
|H'FC006000 to H'FC006FFF|H'80006000 to H'80006FFF|Reserved|
|H'FC007000 to H'FC007FFF|H'80007000 to H'80007FFF|Reserved|
|H'FC008000 to H'FC008FFF|H'80008000 to H'80008FFF|SYS-CTI2|
|H'FC009000 to H'FC009FFF|H'80009000 to H'80009FFF|Reserved|
|H'FC00A000 to H'FC00AFFF|H'8000A000 to H'8000AFFF|Reserved|
|H'FC00B000 to H'FC00BFFF|H'8000B000 to H'8000BFFF|Reserved|
|H'FC00C000 to H'FC00CFFF|H'8000C000 to H'8000CFFF|SYS-CTI1|
|H'FC00D000 to H'FC00DFFF|H'8000D000 to H'8000DFFF|Reserved|
|H'FC00E000 to H'FC00EFFF|H'8000E000 to H'8000EFFF|Reserved|
|H'FC00F000 to H'FC00FFFF|H'8000F000 to H'8000FFFF|ICE registers (ICEReg)|
|H'FC010000 to H'FC010FFF|H'80010000 to H'80010FFF|Reserved|
|H'FC011000 to H'FC011FFF|H'80011000 to H'80011FFF|Reserved|
|H'FC012000 to H'FC012FFF|H'80012000 to H'80012FFF|Reserved|
|H'FC013000 to H'FC013FFF|H'80013000 to H'80013FFF|Reserved|
|H'FC014000 to H'FC014FFF|H'80014000 to H'80014FFF|Reserved|
|H'FC015000 to H'FC015FFF|H'80015000 to H'80015FFF|Reserved|

**Table 43.6 Address Map for CoreSight**

|**System Address (Viewed from CPU)**|**Debug-APB Address (Viewed from Debugger)**|**Module**|
|---|---|---|
|H'FC016000 to H'FC016FFF|H'80016000 to H'80016FFF|Reserved|
|H'FC017000 to H'FC017FFF|H'80017000 to H'80017FFF|Reserved|
|H'FC018000 to H'FC018FFF|H'80018000 to H'80018FFF|Reserved|
|H'FC019000 to H'FC019FFF|H'80019000 to H'80019FFF|Reserved|
|H'FC01A000 to H'FC01AFFF|H'8001A000 to H'8001AFFF|Reserved|
|H'FC01B000 to H'FC01BFFF|H'8001B000 to H'8001BFFF|Reserved|
|H'FC01C000 to H'FC01CFFF|H'8001C000 to H'8001CFFF|Reserved|
|H'FC01D000 to H'FC01DFFF|H'8001D000 to H'8001DFFF|Reserved|
|H'FC01E000 to H'FC01EFFF|H'8001E000 to H'8001EFFF|Reserved|
|H'FC01F000 to H'FC01FFFF|H'8001F000 to H'8001FFFF|Reserved|
|H'FC020000 to H'FC020FFF|H'80020000 to H'80020FFF|2nd DAP ROM|
|H'FC021000 to H'FC021FFF|H'80021000 to H'80021FFF|CPU-ETF|
|H'FC022000 to H'FC022FFF|H'80022000 to H'80022FFF|CPU-CTICS|
|H'FC023000 to H'FC023FFF|H'80023000 to H'80023FFF|CPU-TPIU|
|H'FC024000 to H'FC024FFF|H'80024000 to H'80024FFF|CPU-Trace Funnel|
|H'FC025000 to H'FC025FFF|H'80025000 to H'80025FFF|Reserved|
|H'FC026000 to H'FC026FFF|H'80026000 to H'80026FFF|Reserved|
|H'FC027000 to H'FC027FFF|H'80027000 to H'80027FFF|Reserved|
|H'FC028000 to H'FC028FFF|H'80028000 to H'80028FFF|Reserved|
|H'FC029000 to H'FC029FFF|H'80029000 to H'80029FFF|Reserved|
|H'FC02A000 to H'FC02AFFF|H'8002A000 to H'8002AFFF|Reserved|
|H'FC02B000 to H'FC02BFFF|H'8002B000 to H'8002BFFF|Reserved|
|H'FC02C000 to H'FC02CFFF|H'8002C000 to H'8002CFFF|Reserved|
|H'FC02D000 to H'FC02DFFF|H'8002D000 to H'8002DFFF|Reserved|
|H'FC02E000 to H'FC02EFFF|H'8002E000 to H'8002EFFF|Reserved|
|H'FC02F000 to H'FC02FFFF|H'8002F000 to H'8002FFFF|Reserved|
|H'FC030000 to H'FC030FFF|H'80030000 to H'80030FFF|CA9-DBG (CPU0)|
|H'FC031000 to H'FC031FFF|H'80031000 to H'80031FFF|CA9-PMU (CPU0)|
|H'FC032000 to H'FC032FFF|H'80032000 to H'80032FFF|Reserved|
|H'FC033000 to H'FC033FFF|H'80033000 to H'80033FFF|Reserved|
|H'FC034000 to H'FC034FFF|H'80034000 to H'80034FFF|Reserved|
|H'FC035000 to H'FC035FFF|H'80035000 to H'80035FFF|Reserved|
|H'FC036000 to H'FC036FFF|H'80036000 to H'80036FFF|Reserved|
|H'FC037000 to H'FC037FFF|H'80037000 to H'80037FFF|Reserved|
|H'FC038000 to H'FC038FFF|H'80038000 to H'80038FFF|CA9 CTI (CPU0)|
|H'FC039000 to H'FC039FFF|H'80039000 to H'80039FFF|Reserved|
|H'FC03A000 to H'FC03AFFF|H'8003A000 to H'8003AFFF|Reserved|
|H'FC03B000 to H'FC03BFFF|H'8003B000 to H'8003BFFF|Reserved|
|H'FC03C000 to H'FC03CFFF|H'8003C000 to H'8003CFFF|PTM-A9 (CPU0)|
|H'FC03D000 to H'FC03DFFF|H'8003D000 to H'8003DFFF|Reserved|
|H'FC03E000 to H'FC03EFFF|H'8003E000 to H'8003EFFF|Reserved|
|H'FC03F000 to H'FC03FFFF|H'8003F000 to H'8003FFFF|Reserved|

## 43.2 Input/Output Pins

Table 43.7 shows the pin configuration of the debugger interface.

## **Table 43.7 Pin Configuration**

|**Name**|**Pin Name**<br>**Input/**<br>**Output**<br>**Function**|
|---|---|
|Test clock|TCK/SWDCLK<br>Input<br>Data is input in serial to this module via the data input pin (TDI) or data<br>is output via the data output pin (TDO) in synchronization with this<br>signal.<br>Functions as the SWDCLK pin in serial wire debug (SWD) mode.|
|Test mode select|TMS/SWDIO<br>Input,<br>Input/<br>Output<br>Changing this signal in synchronization with the TCK signal<br>determines the state of the TAP controller circuit.<br>Its protocol conforms to the subset of the JTAG standard (IEEE<br>standard 1149.1).<br>Functions as the SWDIO pin in serial wire debug (SWD) mode.|
|Test reset|TRST<br>*1<br>Input<br>This signal is received asynchronously with the TCK signal. Asserting<br>this signal resets this module. When power is supplied, this pin should<br>be asserted for a given period regardless of whether or not this<br>module function is used.<br>For details on resetting, see section 43.5.2, Reset Signal Setting.|
|Test data input|TDI<br>Input<br>Data is sent to this module by changing this signal in synchronization<br>with the TCK signal.|
|Test data output|TDO<br>Output<br>Data is read from this module by reading this signal in synchronization<br>with the TCK signal.<br>This pin also functions as an output pin in the serial wire debug (SWD)<br>mode. However, a fixed value (the high level) is output because this<br>product does not support the SWO function.|
|Boundary scan setting|BSCANP<br>Input<br>Input a high-level signal during boundary-scan testing.<br>Input a low-level signal during normal use.|
|Clock output|TRACECLK<br>Output<br>Trace clock output pin|
|Enable output|TRACECTL<br>Output<br>Trace enable output pin|
|Data output|TRACEDAT3 to<br>TRACEDATA0<br>Output<br>Trace data output pins|

Note 1. When designing a board that can use an emulator, the RES and TRST pin circuits should be designed so that they can be set low and the TRST pin can be controlled independently at power-on. When the TRST pin is not in use, it should be either fixed to low level or connected to the RES pin (or another pin which operates in the same manner as the RES pin).

## 43.3 Registers for Boundary-Scan TAP Controller

The boundary-scan TAP controller has the following registers.

## **Table 43.8 List of Registers of Boundary-Scan TAP Controller**

|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Bypass register|BSBPR|—|—|—|—|
|Instruction register|BSIR|—|H’55|—|—|
|Boundary scan register|SDBSR|—|—|—|—|
|ID register|BSID|—|H'081A6447*1|—|—|
||||H'082F4447*2|||

Note 1. RZ/A1L Note 2. RZ/A1LU and RZ/A1LC

## 43.3.1 Bypass Register (BSBPR)

BSBPR is a 1-bit register that cannot be accessed by the CPU.  When the BSIR register is set to BYPASS mode, BSBPR is connected between the TDI and TDO pins. The initial value is undefined.

## 43.3.2 Instruction Register (BSIR)

BSIR is an 8-bit register. This register is initialized by TRST assertion or in the TAP test-logic-reset state.  BSIR cannot be accessed by the CPU.

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|7 to 0|TI[7:0]|01010101|—|Test Instruction|
|||||The instructions of this module are transferred to BSIR by a serial input. For|
|||||commands, see Table 43.9.|

## **Table 43.9 Commands Supported for Boundary-Scan TAP Controller**

## **Bits 7 to 0**

|**TI7**|**TI6**|**TI5**|**TI4**|**TI3**|**TI2**|**TI1**|**TI0**|**Description**|
|---|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|0|EXTEST|
|0|1|0|0|0|0|0|0|SAMPLE/PRELOAD|
|0|1|0|1|0|1|0|1|IDCODE (Initial value)|
|1|1|0|1|0|0|0|0|CLAMP|
|1|0|0|0|0|0|0|0|HIGHZ|
|1|1|1|1|1|1|1|1|BYPASS|
|Other|than|above||||||Reserved|

## 43.3.3 Boundary Scan Register (SDBSR)

SDBSR is a shift register, located on the PAD, for controlling the input/output pins of this LSI. SDBSR cannot be accessed by the CPU. The initial value is undefined.

Using the EXTEST, SAMPLE/PRELOAD, CLAMP, and HIGHZ commands, a boundary scan test conforming to the JTAG standard can be carried out. Table 43.10 shows the correspondence between the pins of the RZ/A1L and RZ/ A1LC group products and the boundary scan register bits.

Table 43.11 shows the correspondence between the pins of the RZ/A1LU group products and the boundary scan register bits.

**Table 43.10 Correspondence between the Pins of the RZ/A1L and RZ/A1LC Group Products and the Boundary Scan Register Bits**

|**208-pin**<br>**Bit Number**|**176-pin**<br>**Bit Number**|**Pin Name*1**|**Type**||**208-pin**<br>**Bit Number**|**176-pin**<br>**Bit Number**|**Pin Name*1**|**Type**|
|---|---|---|---|---|---|---|---|---|
|From TDI|||||293|-|P9_5|CONTROL|
|327|327|P3_0|OUTPUT||292|-|P9_5|INPUT|
|326|326|P3_0|CONTROL||291|291|P3_8|OUTPUT|
|325|325|P3_0|INPUT||290|290|P3_8|CONTROL|
|324|324|P3_1|OUTPUT||289|289|P3_8|INPUT|
|323|323|P3_1|CONTROL||288|288|P3_9|OUTPUT|
|322|322|P3_1|INPUT||287|287|P3_9|CONTROL|
|321|321|P3_2|OUTPUT||286|286|P3_9|INPUT|
|320|320|P3_2|CONTROL||285|285|P3_10|OUTPUT|
|319|319|P3_2|INPUT||284|284|P3_10|CONTROL|
|318|318|P3_3|OUTPUT||283|283|P3_10|INPUT|
|317|317|P3_3|CONTROL||282|282|P3_11|OUTPUT|
|316|316|P3_3|INPUT||281|281|P3_11|CONTROL|
|315|315|P3_4|OUTPUT||280|280|P3_11|INPUT|
|314|314|P3_4|CONTROL||279|279|P3_12|OUTPUT|
|313|313|P3_4|INPUT||278|278|P3_12|CONTROL|
|312|-|P9_2|OUTPUT||277|277|P3_12|INPUT|
|311|-|P9_2|CONTROL||276|276|P3_13|OUTPUT|
|310|-|P9_2|INPUT||275|275|P3_13|CONTROL|
|309|-|P9_3|OUTPUT||274|274|P3_13|INPUT|
|308|-|P9_3|CONTROL||273|273|P3_14|OUTPUT|
|307|-|P9_3|INPUT||272|272|P3_14|CONTROL|
|306|306|P3_5|OUTPUT||271|271|P3_14|INPUT|
|305|305|P3_5|CONTROL||270|270|P1_0|OUTPUT*2|
|304|304|P3_5|INPUT||269|269|P1_0|INPUT|
|303|303|P3_6|OUTPUT||268|268|P1_1|OUTPUT*2|
|302|302|P3_6|CONTROL||267|267|P1_1|INPUT|
|301|301|P3_6|INPUT||266|266|P1_2|OUTPUT*2|
|300|300|P3_7|OUTPUT||265|265|P1_2|INPUT|
|299|299|P3_7|CONTROL||264|264|P1_3|OUTPUT*2|
|298|298|P3_7|INPUT||263|263|P1_3|INPUT|
|297|-|P9_4|OUTPUT||262|262|P1_4|OUTPUT*2|
|296|-|P9_4|CONTROL||261|261|P1_4|INPUT|
|295|-|P9_4|INPUT||260|260|P1_5|OUTPUT*2|
|294|-|P9_5|OUTPUT||259|259|P1_5|INPUT|

**Table 43.10 Correspondence between the Pins of the RZ/A1L and RZ/A1LC Group Products and the Boundary Scan Register Bits**

|**208-pin**<br>**Bit Number**|**176-pin**<br>**Bit Number**|**Pin Name*1**|**Type**||**208-pin**<br>**Bit Number**|**176-pin**<br>**Bit Number**|**Pin Name*1**|**Type**|
|---|---|---|---|---|---|---|---|---|
|258|258|P1_6|OUTPUT*2||214|-|P8_2|CONTROL|
|257|257|P1_6|INPUT||213|-|P8_2|INPUT|
|256|256|P1_7|OUTPUT*2||212|-|P8_3|OUTPUT|
|255|255|P1_7|INPUT||211|-|P8_3|CONTROL|
|254|254|P3_15|OUTPUT||210|-|P8_3|INPUT|
|253|253|P3_15|CONTROL||209|-|P8_4|OUTPUT|
|252|252|P3_15|INPUT||208|-|P8_4|CONTROL|
|251|251|P2_6|OUTPUT||207|-|P8_4|INPUT|
|250|250|P2_6|CONTROL||206|-|P8_5|OUTPUT|
|249|249|P2_6|INPUT||205|-|P8_5|CONTROL|
|248|248|P2_7|OUTPUT||204|-|P8_5|INPUT|
|247|247|P2_7|CONTROL||203|203|P4_6|OUTPUT|
|246|246|P2_7|INPUT||202|202|P4_6|CONTROL|
|245|245|P2_8|OUTPUT||201|201|P4_6|INPUT|
|244|244|P2_8|CONTROL||200|200|P4_7|OUTPUT|
|243|243|P2_8|INPUT||199|199|P4_7|CONTROL|
|242|242|P2_9|OUTPUT||198|198|P4_7|INPUT|
|241|241|P2_9|CONTROL||197|197|P5_0|OUTPUT|
|240|240|P2_9|INPUT||196|196|P5_0|CONTROL|
|239|239|P4_0|OUTPUT||195|195|P5_0|INPUT|
|238|238|P4_0|CONTROL||194|194|P5_1|OUTPUT|
|237|237|P4_0|INPUT||193|193|P5_1|CONTROL|
|236|236|P4_1|OUTPUT||192|192|P5_1|INPUT|
|235|235|P4_1|CONTROL||191|191|P5_2|OUTPUT|
|234|234|P4_1|INPUT||190|190|P5_2|CONTROL|
|233|233|P4_2|OUTPUT||189|189|P5_2|INPUT|
|232|232|P4_2|CONTROL||188|188|P5_3|OUTPUT|
|231|231|P4_2|INPUT||187|187|P5_3|CONTROL|
|230|230|P4_3|OUTPUT||186|186|P5_3|INPUT|
|229|229|P4_3|CONTROL||185|185|P5_4|OUTPUT|
|228|228|P4_3|INPUT||184|184|P5_4|CONTROL|
|227|-|P8_0|OUTPUT||183|183|P5_4|INPUT|
|226|-|P8_0|CONTROL||182|182|P5_5|OUTPUT|
|225|-|P8_0|INPUT||181|181|P5_5|CONTROL|
|224|-|P8_1|OUTPUT||180|180|P5_5|INPUT|
|223|-|P8_1|CONTROL||179|179|P5_6|OUTPUT|
|222|-|P8_1|INPUT||178|178|P5_6|CONTROL|
|221|221|P4_4|OUTPUT||177|177|P5_6|INPUT|
|220|220|P4_4|CONTROL||176|176|P5_7|OUTPUT|
|219|219|P4_4|INPUT||175|175|P5_7|CONTROL|
|218|218|P4_5|OUTPUT||174|174|P5_7|INPUT|
|217|217|P4_5|CONTROL||173|173|P5_8|OUTPUT|
|216|216|P4_5|INPUT||172|172|P5_8|CONTROL|
|215|-|P8_2|OUTPUT||171|171|P5_8|INPUT|

**Table 43.10 Correspondence between the Pins of the RZ/A1L and RZ/A1LC Group Products and the Boundary Scan Register Bits**

|**208-pin**<br>**Bit Number**|**176-pin**<br>**Bit Number**|**Pin Name*1**|**Type**||**208-pin**<br>**Bit Number**|**176-pin**<br>**Bit Number**|**Pin Name*1**|**Type**|
|---|---|---|---|---|---|---|---|---|
|170|170|P5_9|OUTPUT||126|-|P8_7|INPUT|
|169|169|P5_9|CONTROL||125|-|P8_8|OUTPUT|
|168|168|P5_9|INPUT||124|-|P8_8|CONTROL|
|167|167|P5_10|OUTPUT||123|-|P8_8|INPUT|
|166|166|P5_10|CONTROL||122|-|P8_9|OUTPUT|
|165|165|P5_10|INPUT||121|-|P8_9|CONTROL|
|164|164|P5_11|OUTPUT||120|-|P8_9|INPUT|
|163|163|P5_11|CONTROL||119|119|P6_6|OUTPUT|
|162|162|P5_11|INPUT||118|118|P6_6|CONTROL|
|161|161|P5_12|OUTPUT||117|117|P6_6|INPUT|
|160|160|P5_12|CONTROL||116|116|P6_7|OUTPUT|
|159|159|P5_12|INPUT||115|115|P6_7|CONTROL|
|158|158|P5_13|OUTPUT||114|114|P6_7|INPUT|
|157|157|P5_13|CONTROL||113|113|P6_8|OUTPUT|
|156|156|P5_13|INPUT||112|112|P6_8|CONTROL|
|155|155|P5_14|OUTPUT||111|111|P6_8|INPUT|
|154|154|P5_14|CONTROL||110|-|P8_10|OUTPUT|
|153|153|P5_14|INPUT||109|-|P8_10|CONTROL|
|152|152|P5_15|OUTPUT||108|-|P8_10|INPUT|
|151|151|P5_15|CONTROL||107|-|P8_11|OUTPUT|
|150|150|P5_15|INPUT||106|-|P8_11|CONTROL|
|149|149|P6_0|OUTPUT||105|-|P8_11|INPUT|
|148|148|P6_0|CONTROL||104|104|P6_9|OUTPUT|
|147|147|P6_0|INPUT||103|103|P6_9|CONTROL|
|146|146|P6_1|OUTPUT||102|102|P6_9|INPUT|
|145|145|P6_1|CONTROL||101|101|P6_10|OUTPUT|
|144|144|P6_1|INPUT||100|100|P6_10|CONTROL|
|143|143|P6_2|OUTPUT||99|99|P6_10|INPUT|
|142|142|P6_2|CONTROL||98|98|P6_11|OUTPUT|
|141|141|P6_2|INPUT||97|97|P6_11|CONTROL|
|140|140|P6_3|OUTPUT||96|96|P6_11|INPUT|
|139|139|P6_3|CONTROL||95|95|P6_12|OUTPUT|
|138|138|P6_3|INPUT||94|94|P6_12|CONTROL|
|137|137|P6_4|OUTPUT||93|93|P6_12|INPUT|
|136|136|P6_4|CONTROL||92|92|P6_13|OUTPUT|
|135|135|P6_4|INPUT||91|91|P6_13|CONTROL|
|134|134|P6_5|OUTPUT||90|90|P6_13|INPUT|
|133|133|P6_5|CONTROL||89|89|P6_14|OUTPUT|
|132|132|P6_5|INPUT||88|88|P6_14|CONTROL|
|131|-|P8_6|OUTPUT||87|87|P6_14|INPUT|
|130|-|P8_6|CONTROL||86|86|P6_15|OUTPUT|
|129|-|P8_6|INPUT||85|85|P6_15|CONTROL|
|128|-|P8_7|OUTPUT||84|84|P6_15|INPUT|
|127|-|P8_7|CONTROL||83|83|P7_0|OUTPUT|

**Table 43.10 Correspondence between the Pins of the RZ/A1L and RZ/A1LC Group Products and the Boundary Scan Register Bits**

|**208-pin**<br>**Bit Number**|**176-pin**<br>**Bit Number**|**Pin Name*1**|**Type**||**208-pin**<br>**Bit Number**|**176-pin**<br>**Bit Number**|**Pin Name*1**|**Type**|
|---|---|---|---|---|---|---|---|---|
|82|82|P7_0|CONTROL||40|40|P2_0|CONTROL|
|81|81|P7_0|INPUT||39|39|P2_0|INPUT|
|80|80|P7_1|OUTPUT||38|38|P2_1|OUTPUT|
|79|79|P7_1|CONTROL||37|37|P2_1|CONTROL|
|78|78|P7_1|INPUT||36|36|P2_1|INPUT|
|77|77|P7_2|OUTPUT||35|-|P8_14|OUTPUT|
|76|76|P7_2|CONTROL||34|-|P8_14|CONTROL|
|75|75|P7_2|INPUT||33|-|P8_14|INPUT|
|74|74|P7_3|OUTPUT||32|-|P8_15|OUTPUT|
|73|73|P7_3|CONTROL||31|-|P8_15|CONTROL|
|72|72|P7_3|INPUT||30|-|P8_15|INPUT|
|71|71|P7_4|OUTPUT||29|-|P9_0|OUTPUT|
|70|70|P7_4|CONTROL||28|-|P9_0|CONTROL|
|69|69|P7_4|INPUT||27|-|P9_0|INPUT|
|68|68|P7_5|OUTPUT||26|-|P9_1|OUTPUT|
|67|67|P7_5|CONTROL||25|-|P9_1|CONTROL|
|66|66|P7_5|INPUT||24|-|P9_1|INPUT|
|65|65|P7_6|OUTPUT||23|23|P2_2|OUTPUT|
|64|64|P7_6|CONTROL||22|22|P2_2|CONTROL|
|63|63|P7_6|INPUT||21|21|P2_2|INPUT|
|62|62|P7_7|OUTPUT||20|20|P2_3|OUTPUT|
|61|61|P7_7|CONTROL||19|19|P2_3|CONTROL|
|60|60|P7_7|INPUT||18|18|P2_3|INPUT|
|59|59|P7_8|OUTPUT||17|17|P0_0|INPUT|
|58|58|P7_8|CONTROL||16|16|P0_1|INPUT|
|57|57|P7_8|INPUT||15|15|P0_2|INPUT|
|56|56|P7_9|OUTPUT||14|14|NMI|INPUT|
|55|55|P7_9|CONTROL||13|13|P1_8|INPUT|
|54|54|P7_9|INPUT||12|12|P1_9|INPUT|
|53|53|P7_10|OUTPUT||11|11|P1_10|INPUT|
|52|52|P7_10|CONTROL||10|10|P1_11|INPUT|
|51|51|P7_10|INPUT||9|9|P1_12|INPUT|
|50|50|P7_11|OUTPUT||8|8|P1_13|INPUT|
|49|49|P7_11|CONTROL||7|7|P1_14|INPUT|
|48|48|P7_11|INPUT||6|6|P1_15|INPUT|
|47|-|P8_12|OUTPUT||5|5|P2_4|OUTPUT|
|46|-|P8_12|CONTROL||4|4|P2_4|CONTROL|
|45|-|P8_12|INPUT||3|3|P2_4|INPUT|
|44|-|P8_13|OUTPUT||2|2|P2_5|OUTPUT|
|43|-|P8_13|CONTROL||1|1|P2_5|CONTROL|
|42|-|P8_13|INPUT||0|0|P2_5|INPUT|
|41|41|P2_0|OUTPUT||||||

Note 1. The pin names are as listed in the “Port function/dedicated function” column of Table 1.4, List of Pins in section 1.6, List of Pins. Note 2. Open-drain pin. Setting the data bit for the pin to 0 makes the pin output a low-level signal and setting the data bit for the pin to 1 places the pin in the hi-Z state.

Note 3. Bits of type “control” are active low. When the control bit is at the low level, the corresponding pin becomes an output.

**Table 43.11 Correspondence between the Pins of the RZ/A1LU Group Products and the Boundary Scan Register Bits**

|208-pin<br>233-pin<br>Bit Number|176-pin<br>Bit Number|Pin Name*1|Type||208-pin<br>233-pin<br>Bit Number|176-pin<br>Bit Number|Pin Name*1|Type|
|---|---|---|---|---|---|---|---|---|
|From TDI|||||287|287|P3_9|CONTROL|
|327|327|P3_0|OUTPUT||286|286|P3_9|INPUT|
|326|326|P3_0|CONTROL||285|285|P3_10|OUTPUT|
|325|325|P3_0|INPUT||284|284|P3_10|CONTROL|
|324|324|P3_1|OUTPUT||283|283|P3_10|INPUT|
|323|323|P3_1|CONTROL||282|282|P3_11|OUTPUT|
|322|322|P3_1|INPUT||281|281|P3_11|CONTROL|
|321|321|P3_2|OUTPUT||280|280|P3_11|INPUT|
|320|320|P3_2|CONTROL||279|279|P3_12|OUTPUT|
|319|319|P3_2|INPUT||278|278|P3_12|CONTROL|
|318|318|P3_3|OUTPUT||277|277|P3_12|INPUT|
|317|317|P3_3|CONTROL||276|276|P3_13|OUTPUT|
|316|316|P3_3|INPUT||275|275|P3_13|CONTROL|
|315|315|P3_4|OUTPUT||274|274|P3_13|INPUT|
|314|314|P3_4|CONTROL||273|273|P3_14|OUTPUT|
|313|313|P3_4|INPUT||272|272|P3_14|CONTROL|
|312|-|P9_2|OUTPUT||271|271|P3_14|INPUT|
|311|-|P9_2|CONTROL||270|270|P1_0|OUTPUT|
|310|-|P9_2|INPUT||269|269|P1_0|INPUT|
|309|-|P9_3|OUTPUT||268|268|P1_1|OUTPUT*2|
|308|-|P9_3|CONTROL||267|267|P1_1|INPUT|
|307|-|P9_3|INPUT||266|266|P1_2|OUTPUT*2|
|306|306|P3_5|OUTPUT||265|265|P1_2|INPUT|
|305|305|P3_5|CONTROL||264|264|P1_3|OUTPUT*2|
|304|304|P3_5|INPUT||263|263|P1_3|INPUT|
|303|303|P3_6|OUTPUT||262|262|P1_4|OUTPUT*2|
|302|302|P3_6|CONTROL||261|261|P1_4|INPUT|
|301|301|P3_6|INPUT||260|260|P1_5|OUTPUT*2|
|300|300|P3_7|OUTPUT||259|259|P1_5|INPUT|
|299|299|P3_7|CONTROL||258|258|P1_6|OUTPUT*2|
|298|298|P3_7|INPUT||257|257|P1_6|INPUT|
|297|-|P9_4|OUTPUT||256|256|P1_7|OUTPUT*2|
|296|-|P9_4|CONTROL||255|255|P1_7|INPUT|
|295|-|P9_4|INPUT||254|254|P3_15|OUTPUT|
|294|-|P9_5|OUTPUT||253|253|P3_15|CONTROL|
|293|-|P9_5|CONTROL||252|252|P3_15|INPUT|
|292|-|P9_5|INPUT||251|251|P2_6|OUTPUT|
|291|291|P3_8|OUTPUT||250|250|P2_6|CONTROL|
|290|290|P3_8|CONTROL||249|249|P2_6|INPUT|
|289|289|P3_8|INPUT||248|248|P2_7|OUTPUT|
|288|288|P3_9|OUTPUT||247|247|P2_7|CONTROL|

**Table 43.11 Correspondence between the Pins of the RZ/A1LU Group Products and the Boundary Scan Register Bits**

|208-pin<br>233-pin<br>Bit Number|176-pin<br>Bit Number|Pin Name*1|Type||208-pin<br>233-pin<br>Bit Number|176-pin<br>Bit Number|Pin Name*1|Type|
|---|---|---|---|---|---|---|---|---|
|246|246|P2_7|INPUT||203|203|P4_6|OUTPUT|
|245|245|P2_8|OUTPUT||202|202|P4_6|CONTROL|
|244|244|P2_8|CONTROL||201|201|P4_6|INPUT|
|243|243|P2_8|INPUT||200|200|P4_7|OUTPUT|
|242|242|P2_9|OUTPUT||199|199|P4_7|CONTROL|
|241|241|P2_9|CONTROL||198|198|P4_7|INPUT|
|240|240|P2_9|INPUT||197|197|P5_0|OUTPUT|
|239|239|P4_0|OUTPUT||196|196|P5_0|CONTROL|
|238|238|P4_0|CONTROL||195|195|P5_0|INPUT|
|237|237|P4_0|INPUT||194|194|P5_1|OUTPUT|
|236|236|P4_1|OUTPUT||193|193|P5_1|CONTROL|
|235|235|P4_1|CONTROL||192|192|P5_1|INPUT|
|234|234|P4_1|INPUT||191|191|P5_2|OUTPUT|
|233|233|P4_2|OUTPUT||190|190|P5_2|CONTROL|
|232|232|P4_2|CONTROL||189|189|P5_2|INPUT|
|231|231|P4_2|INPUT||188|188|P5_3|OUTPUT|
|230|230|P4_3|OUTPUT||187|187|P5_3|CONTROL|
|229|229|P4_3|CONTROL||186|186|P5_3|INPUT|
|228|228|P4_3|INPUT||185|185|P5_4|OUTPUT|
|227|-|P8_0|OUTPUT||184|184|P5_4|CONTROL|
|226|-|P8_0|CONTROL||183|183|P5_4|INPUT|
|225|-|P8_0|INPUT||182|182|P5_5|OUTPUT|
|224|-|P8_1|OUTPUT||181|181|P5_5|CONTROL|
|223|-|P8_1|CONTROL||180|180|P5_5|INPUT|
|222|-|P8_1|INPUT||179|179|P5_6|OUTPUT|
|221|221|P4_4|OUTPUT||178|178|P5_6|CONTROL|
|220|220|P4_4|CONTROL||177|177|P5_6|INPUT|
|219|219|P4_4|INPUT||176|176|P5_7|OUTPUT|
|218|218|P4_5|OUTPUT||175|175|P5_7|CONTROL|
|217|217|P4_5|CONTROL||174|174|P5_7|INPUT|
|216|216|P4_5|INPUT||173|173|P5_8|OUTPUT|
|215|-|P8_2|OUTPUT||172|172|P5_8|CONTROL|
|214|-|P8_2|CONTROL||171|171|P5_8|INPUT|
|213|-|P8_2|INPUT||170|170|P5_9|OUTPUT|
|212|-|P8_3|OUTPUT||169|169|P5_9|CONTROL|
|211|-|P8_3|CONTROL||168|168|P5_9|INPUT|
|210|-|P8_3|INPUT||167|167|P5_10|OUTPUT|
|209|-|P8_4|OUTPUT||166|166|P5_10|CONTROL|
|208|-|P8_4|CONTROL||165|165|P5_10|INPUT|
|207|-|P8_4|INPUT||164|164|P5_11|OUTPUT|
|206|-|P8_5|OUTPUT||163|163|P5_11|CONTROL|
|205|-|P8_5|CONTROL||162|162|P5_11|INPUT|
|204|-|P8_5|INPUT||161|161|P5_12|OUTPUT|

**Table 43.11 Correspondence between the Pins of the RZ/A1LU Group Products and the Boundary Scan Register Bits**

|208-pin<br>233-pin<br>Bit Number|176-pin<br>Bit Number|Pin Name*1|Type||208-pin<br>233-pin<br>Bit Number|176-pin<br>Bit Number|Pin Name*1|Type|
|---|---|---|---|---|---|---|---|---|
|160|160|P5_12|CONTROL||117|117|P6_6|INPUT|
|159|159|P5_12|INPUT||116|116|P6_7|OUTPUT|
|158|158|P5_13|OUTPUT||115|115|P6_7|CONTROL|
|157|157|P5_13|CONTROL||114|114|P6_7|INPUT|
|156|156|P5_13|INPUT||113|113|P6_8|OUTPUT|
|155|155|P5_14|OUTPUT||112|112|P6_8|CONTROL|
|154|154|P5_14|CONTROL||111|111|P6_8|INPUT|
|153|153|P5_14|INPUT||110|-|P8_10|OUTPUT|
|152|152|P5_15|OUTPUT||109|-|P8_10|CONTROL|
|151|151|P5_15|CONTROL||108|-|P8_10|INPUT|
|150|150|P5_15|INPUT||107|-|P8_11|OUTPUT|
|149|149|P6_0|OUTPUT||106|-|P8_11|CONTROL|
|148|148|P6_0|CONTROL||105|-|P8_11|INPUT|
|147|147|P6_0|INPUT||104|104|P6_9|OUTPUT|
|146|146|P6_1|OUTPUT||103|103|P6_9|CONTROL|
|145|145|P6_1|CONTROL||102|102|P6_9|INPUT|
|144|144|P6_1|INPUT||101|101|P6_10|OUTPUT|
|143|143|P6_2|OUTPUT||100|100|P6_10|CONTROL|
|142|142|P6_2|CONTROL||99|99|P6_10|INPUT|
|141|141|P6_2|INPUT||98|98|P6_11|OUTPUT|
|140|140|P6_3|OUTPUT||97|97|P6_11|CONTROL|
|139|139|P6_3|CONTROL||96|96|P6_11|INPUT|
|138|138|P6_3|INPUT||95|95|P6_12|OUTPUT|
|137|137|P6_4|OUTPUT||94|94|P6_12|CONTROL|
|136|136|P6_4|CONTROL||93|93|P6_12|INPUT|
|135|135|P6_4|INPUT||92|92|P6_13|OUTPUT|
|134|134|P6_5|OUTPUT||91|91|P6_13|CONTROL|
|133|133|P6_5|CONTROL||90|90|P6_13|INPUT|
|132|132|P6_5|INPUT||89|89|P6_14|OUTPUT|
|131|-|P8_6|OUTPUT||88|88|P6_14|CONTROL|
|130|-|P8_6|CONTROL||87|87|P6_14|INPUT|
|129|-|P8_6|INPUT||86|86|P6_15|OUTPUT|
|128|-|P8_7|OUTPUT||85|85|P6_15|CONTROL|
|127|-|P8_7|CONTROL||84|84|P6_15|INPUT|
|126|-|P8_7|INPUT||83|83|P7_0|OUTPUT|
|125|-|P8_8|OUTPUT||82|82|P7_0|CONTROL|
|124|-|P8_8|CONTROL||81|81|P7_0|INPUT|
|123|-|P8_8|INPUT||80|80|P7_1|OUTPUT|
|122|-|P8_9|OUTPUT||79|79|P7_1|CONTROL|
|121|-|P8_9|CONTROL||78|78|P7_1|INPUT|
|120|-|P8_9|INPUT||77|77|P7_2|OUTPUT|
|119|119|P6_6|OUTPUT||76|76|P7_2|CONTROL|
|118|118|P6_6|CONTROL||75|75|P7_2|INPUT|

**Table 43.11 Correspondence between the Pins of the RZ/A1LU Group Products and the Boundary Scan Register Bits**

|208-pin<br>233-pin<br>Bit Number|176-pin<br>Bit Number|Pin Name*1|Type||208-pin<br>233-pin<br>Bit Number|176-pin<br>Bit Number|Pin Name*1|Type|
|---|---|---|---|---|---|---|---|---|
|74|74|P7_3|OUTPUT||36|36|P2_1|INPUT|
|73|73|P7_3|CONTROL||35|-|P8_14|OUTPUT|
|72|72|P7_3|INPUT||34|-|P8_14|CONTROL|
|71|71|P7_4|OUTPUT||33|-|P8_14|INPUT|
|70|70|P7_4|CONTROL||32|-|P8_15|OUTPUT|
|69|69|P7_4|INPUT||31|-|P8_15|CONTROL|
|68|68|P7_5|OUTPUT||30|-|P8_15|INPUT|
|67|67|P7_5|CONTROL||29|-|P9_0|OUTPUT|
|66|66|P7_5|INPUT||28|-|P9_0|CONTROL|
|65|65|P7_6|OUTPUT||27|-|P9_0|INPUT|
|64|64|P7_6|CONTROL||26|-|P9_1|OUTPUT|
|63|63|P7_6|INPUT||25|-|P9_1|CONTROL|
|62|62|P7_7|OUTPUT||24|-|P9_1|INPUT|
|61|61|P7_7|CONTROL||23|23|P2_2|OUTPUT|
|60|60|P7_7|INPUT||22|22|P2_2|CONTROL|
|59|59|P7_8|OUTPUT||21|21|P2_2|INPUT|
|58|58|P7_8|CONTROL||20|20|P2_3|OUTPUT|
|57|57|P7_8|INPUT||19|19|P2_3|CONTROL|
|56|56|P7_9|OUTPUT||18|18|P2_3|INPUT|
|55|55|P7_9|CONTROL||17|17|P0_0|INPUT|
|54|54|P7_9|INPUT||16|16|P0_1|INPUT|
|53|-|P8_12|OUTPUT||15|15|P0_2|INPUT|
|52|-|P8_12|CONTROL||14|14|NMI|INPUT|
|51|-|P8_12|INPUT||13|13|P1_8|INPUT|
|50|-|P8_13|OUTPUT||12|12|P1_9|INPUT|
|49|-|P8_13|CONTROL||11|11|P1_10|INPUT|
|48|-|P8_13|INPUT||10|10|P1_11|INPUT|
|47|47|P7_10|OUTPUT||9|9|P1_12|INPUT|
|46|46|P7_10|CONTROL||8|8|P1_13|INPUT|
|45|45|P7_10|INPUT||7|7|P1_14|INPUT|
|44|44|P7_11|OUTPUT||6|6|P1_15|INPUT|
|43|43|P7_11|CONTROL||5|5|P2_4|OUTPUT|
|42|42|P7_11|INPUT||4|4|P2_4|CONTROL|
|41|41|P2_0|OUTPUT||3|3|P2_4|INPUT|
|40|40|P2_0|CONTROL||2|2|P2_5|OUTPUT|
|39|39|P2_0|INPUT||1|1|P2_5|CONTROL|
|38|38|P2_1|OUTPUT||0|0|P2_5|INPUT|
|37|37|P2_1|CONTROL||||||

Note 1. The pin names are as listed in the “Port function/dedicated function” column of Table 1.4, List of Pins in section 1.6, List of Pins. Note 2. Open-drain pin. Setting the data bit for the pin to 0 makes the pin output a low-level signal and setting the data bit for the pin to 1 places the pin in the hi-Z state. Note 3. Bits of type “control” are active low. When the control bit is at the low level, the corresponding pin becomes an output.

## 43.3.4 ID Register (BSID)

BSID is a 32-bit read-only register that cannot be accessed by the CPU. BSID can be only be read from the pins when the  IDCODE command is set.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||DID[31:16]|||||||||
|||Initial value:||*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|
||||R/W:|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||DID[15:0]|||||||||
|||Initial value:||*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|
||||R/W:|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
||||*: RZ/A1L|0|0|0|0|1|0|0|0|0|0|0|1|1|0|1|0|
|||||0|1|1|0|0|1|0|0|0|1|0|0|0|1|1|1|
|||*:|RZ/A1LU|0|0|0|0|1|0|0|0|0|0|1|0|1|1|1|1|
||||and|0|1|0|0|0|1|0|0|0|1|0|0|0|1|1|1|
||||RZ/A1LC|||||||||||||||||
|**Bit**|||**Bit Name**||**Initial**|**Value**||**R/W**|**Description**|||||||||||
|31|to|0|DID[31:0]||H'081A6447*1|||—|Device IDCODE|||||||||||
||||||H'082F4447*2||||This is the ID register|||stipulated by JTAG. Note that the|||||higher-order||four bits may|
||||||||||be changed depending on||||the version of the chip.|||||||

Note 1. RZ/A1L

Note 2. RZ/A1LU and RZ/A1LC

## 43.4 ICE Registers

The debugger interface has the following ICE registers.

ICE registers are exclusively for use in debugging. Do not use these registers other than for debugging.

## **Table 43.12 Configuration of ICE Registers**

|**Table 43.12**<br>**Configuration of ICE Registers**||
|---|---|
|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**|**Address**<br>**Access**<br>**Size**<br>**Viewed from**<br>**CPU**<br>**Viewed from**<br>**Debugger**|
|Mode reset control<br>register<br>ICEREGMDRSTCTL<br>R/W<br>H'0000111E|H'FC00F000<br>H'8000F000<br>32|
|JTAG trace select<br>register<br>ICEREGJTTRCSEL<br>R/W<br>H'00800000|H'FC00F004<br>H'8000F004<br>32|
|Clock power control<br>register<br>ICEREGCLKPWRCTRL<br>R/W<br>H'00000000|H'FC00F014<br>H'8000F014<br>32|
|Lock access<br>register<br>ICEREGLOCKACCES<br>W<br>—|H'FC00FFB0<br>H'8000FFB0<br>32|

## 43.4.1 Mode Reset Control Register (ICEREGMDRSTCTL)

ICEREGMDRSTCTL is used to set the debug mode and to perform software reset.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||NIDEN_||||DBGEN|
|||—|—|—|—|—|—|—|—|—|—|—|CPU0|—|—|—|_CPU0|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||RSTRB_||||RSTRB_||||RSTRB_||RSTRB_|RSTRB_||
|||—|—|—|CPU0_|—|—|—|CPU0_|—|—|—|SYS_|—|CPU_|CPU_|—|
||||||DERSTZ||||CPURSTZ||||SYSRSTZ||PRSTDBGZ|SYSRSTZ||
|Initial value:||0|0|0|1|0|0|0|1|0|0|0|1|1|1|1|0|
|R/W:||R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|R/W|R/W|R/W|R|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 21|—|All 0|R|Reserved|
|||||The read value is always 0.|
|20|NIDEN_CPU0|0|R/W|CPU Noninvasive Debug Enable|
|||||Controls the noninvasive debug enable signal (NIDEN/SPNIDEN)|
|||||supplied to the CPU.|
|||||This bit is only effective when the PINSETEN bit in ICEREGJTTRCSEL is|
|||||set to 0.|
|19 to 17|—|All 0|R|Reserved|
|||||The read value is always 0.|
|16|DBGEN_CPU0|0|R/W|CPU Debug Enable|
|||||Controls the debug enable signal (DBGEN/SPIDEN) supplied to the|
|||||CPU. This bit is only effective when the PINSETEN bit in|
|||||ICEREGJTTRCSEL is set to 0.|
|15 to 13|—|All 0|R|Reserved|
|||||The read value is always 0.|
|12|RSTRB_CPU0_|1|R/W|NEON Reset (low-active)|
||DERSTZ|||Resets the NEON unit in the CPU.|
|11 to 9|—|All 0|R|Reserved|
|||||The read value is always 0.|
|8|RSTRB_CPU0_|1|R/W|CPU Reset (low-active)|
||CPURSTZ|||Resets all systems on the CPU block other than debugging resources.|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|7 to 5|—|All 0|R|Reserved|
|||||The read value is always 0.|
|4|RSTRB_SYS_|1|R/W|System Reset (low-active)|
||SYSRSTZ|||Resets all systems on the chip other than debugging resources.|
|3|—|1|R/W|Reserved|
|||||The read value is always 1. The write value should always be 1.|
|2|RSTRB_CPU_|1|R/W|CPU Subsystem Debug Peripheral Reset (low-active)|
||PRSTDBGZ|||Resets the debug-APB block in the CPU subsystem.|
|1|RSTRB_CPU_|1|R/W|CPU Subsystem Reset (low-active)|
||SYSRSTZ|||Resets the CPU subsystem other than those for debugging.|
|0|—|0|R|Reserved|
|||||The read value is always 0.|

## 43.4.2 JTAG Trace Select Register (ICEREGJTTRCSEL)

ICEREGJTTRCSEL is used to control trace data output to the respective pins and debug enable signal supplied to the CPU.

|||Bit:|Bit:|31|30|||29|28|27|26|25|24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—|—|||—|—|—|—|—|—<br>PINSET<br>—|—|TRCMU|—|—|—|—||
||||||||||||||EN||X_SEL||||||
||Initial|value:||0|0|||0|0|0|0|0|0<br>1<br>0|0|0|0|0|0|0||
|||R/W:||R|R|||R|R|R|R|R|R<br>R/W<br>R|R|R/W|R|R|R|R||
|||Bit:||15|14|||13|12|11|10|9|8<br>7<br>6|5|4|3|2|1|0||
|||||||||||||||—|—||||||
|||||—|—|||—|—|—|—|—|—<br>—<br>—|||—|—|—|—||
||Initial|value:||0|0|||0|0|0|0|0|0<br>0<br>0|0|0|0|0|0|0||
|||R/W:||R|R|||R|R|R|R|R|R<br>R<br>R|R|R|R|R|R|R||
|**Bit**||**Bit Name**||||**Initial Value**||||**R/W**|**Description**||||||||||
|31 to 24||—||||All||0||R|Reserved||||||||||
||||||||||||The read value is always 0.||||||||||
|23||PINSETEN||||1||||R/W|Selects control method of debug enable signal supplied to the CPU.||||||||||
||||||||||||0: Supply of the DBGEN and NIDEN signals is determined|||||||by the|||
||||||||||||ICEREGMDRSTCTL register.||||||||||
||||||||||||1: Supply of the DBGEN and NIDEN signals is determined|||||||by the|BSCANP pin.||
|22,|21|—||||All||0||R|Reserved||||||||||
||||||||||||The read value is always 0.||||||||||
|20||TRCMUX_||||0||||R/W|Sets the priority of the function multiplexed on the pins to which trace output is||||||||||
|||SEL|||||||||assigned.||||||||||
||||||||||||0: The function of the pins depends on the general I/O port setting.||||||||||
||||||||||||1: The pins act as trace outputs regardless of the general I/O port||||||||setting.||
|19 to 0||—||||All||0||R|Reserved||||||||||
||||||||||||The read value is always 0.||||||||||

## 43.4.3 Clock Power Control Register (ICEREGCLKPWRCTRL)

ICEREGCLKPWRCTRL is used to set the fake debug mode.

||Bit:|Bit:|31|30|||29|28|27|26<br>25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|—|||—|—|—|—<br>—<br>—<br>—<br>—|—|—|—|—|—|—||
|Initial value:|||0|0|||0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:||R|R|||R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|R|R|R||
||Bit:||15|14|||13|12|11|10<br>9<br>8<br>7<br>6|5|4|3|2|1|0||
||||—|—|||—|—|—|—<br>—<br>—<br>FAKED<br>BGCTR<br>L<br>—|—|—|—|—|—|FAKED<br>BG||
|Initial value:|||0|0|||0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:||R|R|||R|R|R|R<br>R<br>R<br>R/W<br>R|R|R|R|R|R|R/W||
|**Bit**|**Bit Name**||||**Initial Value**||||**R/W**|**Description**||||||||
|31 to 8|—||||All||0||R|Reserved||||||||
|||||||||||The read value is always 0.||||||||
|7|FAKEDBGCTRL||||0||||R/W|Enables or disables the fake debug mode.||||||||
|||||||||||0: The power control is determined by||the standby control register 1 (STBCR1).||||||
|||||||||||1: The power control is determined by||this register.||||||
|6 to 1|—||||All||0||R|Reserved||||||||
|||||||||||The read value is always 0.||||||||
|0|FAKEDBG||||0||||R/W|Selects whether or not to stop the power supply in deep standby mode.||||||||
|||||||||||0: The power supply is actually|stopped in deep standby mode.|||||||
|||||||||||1: The power supply is not stopped even in deep standby mode.||||||||

## 43.4.4 Lock Access Register (ICEREGLOCKACCESS)

ICEREGLOCKACCESS is used to enable access to ICE registers by the CPU.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||ICEREGLOCKACCESS||||||||||
|||Initial|value:|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
||||R/W:|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||ICEREGLOCKACCESS||||||||||
|||Initial|value:|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
||||R/W:|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|
|**Bit**|||**Bit Name**|||**Initial**|**Value**|**R/W**|**Description**|||||||||||
|31|to|0|ICEREGLOCKA|||—||W|To|enable access||to ICE|registers by||the CPU,|first|write|H'C5AC|CE55 to this|
||||CCESS||||||register.|||||||||||

## 43.5 Operation

## 43.5.1 TAP Controller

Figure 43.3 shows the internal states of the TAP controller. State transitions basically conform to the JTAG standard.

**==> picture [447 x 311] intentionally omitted <==**

**----- Start of picture text -----**<br>
TRST=0<br>1  Test Logic Reset<br>0<br>1 1 1<br>0  Run Test / Idle  Select DR Scan  Select IR Scan<br>0  0<br>Capture DR  Capture IR<br>1  1<br>0  0<br>0  Shift DR  0  Shift IR<br>1  1<br>Exit1 DR  Exit1 IR<br>0  0<br>0  0<br>0  Pause DR  0  Pause IR<br>1  1<br>Exit2 DR  Exit2 IR<br>1  1  1  1<br>Update DR  Update IR<br>1  0  1  0<br>**----- End of picture text -----**<br>

**Figure 43.3 State Transitions of TAP Controller**

Note: State transition occur according to the TMS value at the rising edge of the TCK signal. The TDI value sampled at the rising edge of the TCK signal and shifted at the falling edge of the TCK signal. TDO value is output at the rising edge of the TCK signal. The TDO signal is in a Hi-Z state for TAP controller states other than Shift-DR and Shift-IR. A transition to the Test-Logic-Reset state by clearing TRST to 0 is performed asynchronously with the TCK signal.

## 43.5.2 Reset Signal Setting

## **Table 43.13 Reset Signal Setting**

|**RES**|**TRST**<br>**Chip State**|
|---|---|
|L|L<br>The chip is power-on reset and this module is reset.*1|
||H<br>The chip is power-on reset.*1|
|H|L<br>This module is only reset.*2|
||H<br>Normal operation*2|

Note 1. By asserting the RES and TRST signals, the CPU and CoreSight enter the reset state. Set the debugging function while asserting the RES signal after negating the TRST signal.

Note 2. Do not negate the TRST signal while the RES signal is at the high-level.

Note 3. When the TRST pin is to be negated, make sure that the specification for RES input rise time (tRSr) or RES negating hold time (tRSNH) in Table 47.6, Control Signal Timing, is satisfied.

## 43.6 Boundary Scan

Commands can be set in BSIR by this module to place this module's pins in boundary scan mode stipulated by JTAG.

## 43.6.1 Supported Instructions

This LSI supports three mandatory instructions stipulated by JTAG standard (BYPASS, SAMPLE/PRELOAD, and EXTEST) and three option instructions (IDCODE, CLAMP, and HIGHZ).

## (1) BYPASS

BYPASS is a mandatory instruction that operates the bypass register. This instruction is used to shorten the shift path to speed up serial data transfer involving other LSI on the printed circuit board. This LSI's system circuits are not affected by execution of this instruction.

## (2) SAMPLE/PRELOAD

SAMPLE/PRELOAD is used to input data from this LSI’s internal circuit to the boundary scan register, outputs data from the scan path, and loads data onto the scan path. While this instruction is being executed, signals input to this LSI pins are transmitted directly to the internal circuit, and the values of the internal circuit are directly output externally from the output pins. This LSI's system circuits are not affected by execution of this instruction.

In a SAMPLE operation, a snapshot of a value to be transferred from an input pin to the internal circuit, or a value to be transferred from the internal circuit to an output pin, is latched into the boundary scan register and read from the scan path. Snapshot latching is performed in synchronization with the rising edge of the TCK signal in the Capture-DR state. Snapshot latching does not affect normal operation of this LSI.

In a PRELOAD operation, an initial value is set in the parallel output latch of the boundary scan register from the scan path prior to the EXTEST instruction. Without a PRELOAD operation, when the EXTEST instruction was executed an undefined value would be output from the output pin until completion of the initial scan sequence (transfer to the output latch) (with the EXTEST instruction, the parallel output latch value is constantly output to the output pin).

## (3) EXTEST

This instruction is provided to test external circuit when this LSI is mounted on a printed circuit board. When this instruction is executed, output pins are used to output test data (previously set by the SAMPLE/PRELOAD instruction) from the boundary scan register to the printed circuit board, and input pins are used to latch test results into the boundary scan register from the printed circuit board. If testing is carried out by using the EXTEST instruction N times, the Nth test data is scanned-in when test data (N-1) is scanned out. The data loaded into the output pin boundary scan register in the Capture-DR state are not used for external circuit testing (data are replaced by the shift operation).

## (4) IDCODE

Commands can be set in BSIR via pins of this module to place the module’s pins in the IDCODE mode stipulated by JTAG. When this module is initialized (TRST is asserted or TAP is in the Test-Logic-Reset state), the IDCODE mode is entered.

## (5) CLAMP, HIGHZ

Commands can be set in BSIR via pins of this module to place the module’s pins in the CLAMP or HIGHZ mode stipulated by JTAG.

## 43.6.2 Points for Attention

1. Boundary scan mode does not cover clock-related signals (EXTAL, XTAL, CKIO, AUDIO_X1, AUDIO_X2, USB_X1, USB_X2, RTC_X1, and RTC_X2).

2. Boundary scan mode does not cover reset-related signal (RES).

3. Boundary scan mode does not cover this module’s signals (TCK, TDI, TDO, TMS, TRST, and BSCANP).

4. Boundary scan mode does not cover USB-related signals (DP0, DP1, DM0, DM1, VBUS0, VBUS1, and REFRIN). 5. Boundary scan mode does not cover P0_3.

## 43.7 Usage Notes

1. Once a command of this module is set, it will not be modified unless another command is reissued. If the same command is given continuously, the command must be set after a command (BYPASS, etc.) that does not affect LSI operations is once set.

2. Regardless of whether or not this module is to be used, it should be initialized by asserting the TRST signal when power is supplied and on release from deep standby mode (excluding fake debug mode) through assertion of the RES signal.

3. Be sure to wait for at least 200 ns after negating the TRST signal before starting TAP controller operation.

4. Be sure to fix the TMS pin to the high level until 200 ns have elapsed after negation of the TRST signal.
