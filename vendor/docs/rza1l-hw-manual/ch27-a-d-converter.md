# 27. A/D Converter

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1441–1465. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI includes a 12-bit successive-approximation A/D converter allowing selection of up to eight analog input channels.

## 27.1 Features

- Resolution: 12 bits

- Input channels: Eight channels

- Minimum conversion time: 5.0  s per channel

- Absolute accuracy:  11 LSB

- Operating modes: Three

   - Single mode: A/D conversion on one channel

   - Multi mode: A/D conversion on one to four channels or on one to eight channels

   - Scan mode: Continuous A/D conversion on one to four channels or on one to eight channels

- Data registers: Eight

Conversion results are held in a 16-bit data register for each channel

- Sample-and-hold function

- A/D conversion start methods: Three methods

   - Software

   - Conversion start trigger from the multi-function timer pulse unit 2

   - External trigger signal

- Interrupt source: Two sources

An A/D conversion end interrupt (ADI) request can be generated on completion of A/D conversion.

An over-limit interrupt (LMTI) request can be generated when a result of conversion exceeds the upper or lower limit for each channel.*

Note: * This is only available when 10-bit precision is in use.

- Module standby mode can be set

Figure 27.1 shows a block diagram of the A/D converter.

**==> picture [340 x 280] intentionally omitted <==**

**----- Start of picture text -----**<br>
Module data bus<br>Peripheral bus<br>AVCC<br>AVref 12-bit<br>D/A<br>AVSS<br>AN0<br>AN1<br>AN2 +<br>AN4AN3 – Control circuit ADTRG,  conversion start  trigger from<br>AN5 Comparator multi-function timer<br>AN6 pulse unit 2<br>AN7 Sample-and-hold<br>circuit<br>ADI<br>interrupt signal<br>LMTI<br>interrupt signal<br>A/D converter<br>[Legend]<br>ADCSR : A/D control/status register<br>ADDRA to ADDRH : A/D data registers A to H<br>ADCMPLA to ADCMPLH : A/D comparison lower limit value registers A to H<br>ADCMPHA to ADCMPHH : A/D comparison lower upper value registers A to H<br>ADCMPER : A/D comparison interrupt enable register<br>ADCMPSR : A/D comparison status register<br>Bus interface<br>Successive-  register  ADCMPER ADCMPSR ADCSR<br> approximation<br>ADDRA to ADDRH ADCMPLA to ADCMPLH ADCMPHA to ADCMPHH<br>Analog<br>multiplexer<br>**----- End of picture text -----**<br>

**Figure 27.1 Block Diagram of A/D Converter**

## 27.2 Input/Output Pins

Table 27.1 shows the A/D converter pins.

## **Table 27.1 Pin Configuration**

|**Table 27.1**<br>**Pin Configuration**||
|---|---|
|**Pin Name**|**Symbol**<br>**I/O**<br>**Function**|
|Analog power supply pin|AVcc<br>Input<br>Analog power supply pin|
|Analog ground pin|AVss<br>Input<br>Analog ground pin and A/D conversion reference<br>ground|
|Analog reference voltage pin|AVref<br>Input<br>A/D converter reference voltage pin|
|Analog input pin 0|AN0<br>Input<br>Analog input<br>AN1<br>Input<br>AN2<br>Input<br>AN3<br>Input<br>AN4<br>Input<br>AN5<br>Input<br>AN6<br>Input<br>AN7<br>Input|
|Analog input pin 1||
|Analog input pin 2||
|Analog input pin 3||
|Analog input pin 4||
|Analog input pin 5||
|Analog input pin 6||
|Analog input pin 7||
|A/D external trigger input pin|ADTRG<br>Input<br>External trigger input to start A/D conversion|

## 27.3 Register Descriptions

The A/D converter has the following registers.

## **Table 27.2 Register Configuration**

||||||Access|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|Size|
|A/D data register A|ADDRA|R|H'0000|H'E8005800|16|
|A/D data register B|ADDRB|R|H'0000|H'E8005802|16|
|A/D data register C|ADDRC|R|H'0000|H'E8005804|16|
|A/D data register D|ADDRD|R|H'0000|H'E8005806|16|
|A/D data register E|ADDRE|R|H'0000|H'E8005808|16|
|A/D data register F|ADDRF|R|H'0000|H'E800580A|16|
|A/D data register G|ADDRG|R|H'0000|H'E800580C|16|
|A/D data register H|ADDRH|R|H'0000|H'E800580E|16|
|A/D comparison upper limit value|ADCMPHA|R/W|H'0000|H’E8005820|16|
|register A||||||
|A/D comparison lower limit value|ADCMPLA|R/W|H'0000|H’E8005822|16|
|register A||||||
|A/D comparison upper limit value|ADCMPHB|R/W|H'0000|H’E8005824|16|
|register B||||||
|A/D comparison lower limit value|ADCMPLB|R/W|H'0000|H’E8005826|16|
|register B||||||
|A/D comparison upper limit value|ADCMPHC|R/W|H'0000|H’E8005828|16|
|register C||||||
|A/D comparison lower limit value|ADCMPLC|R/W|H'0000|H’E800582A|16|
|register C||||||
|A/D comparison upper limit value|ADCMPHD|R/W|H'0000|H’E800582C|16|
|register D||||||
|A/D comparison lower limit value|ADCMPLD|R/W|H'0000|H’E800582E|16|
|register D||||||
|A/D comparison upper limit value|ADCMPHE|R/W|H'0000|H’E8005830|16|
|register E||||||
|A/D comparison lower limit value|ADCMPLE|R/W|H'0000|H’E8005832|16|
|register E||||||
|A/D comparison upper limit value|ADCMPHF|R/W|H'0000|H’E8005834|16|
|register F||||||
|A/D comparison lower limit value|ADCMPLF|R/W|H'0000|H’E8005836|16|
|register F||||||
|A/D comparison upper limit value|ADCMPHG|R/W|H'0000|H’E8005838|16|
|register G||||||
|A/D comparison lower limit value|ADCMPLG|R/W|H'0000|H’E800583A|16|
|register G||||||
|A/D comparison upper limit value|ADCMPHH|R/W|H'0000|H’E800583C|16|
|register H||||||
|A/D comparison lower limit value|ADCMPLH|R/W|H'0000|H’E800583E|16|
|register H||||||
|A/D control/status register|ADCSR|R/W|H’0000|H’E8005860|16|
|A/D comparison interrupt enable|ADCMPER|R/W|H’0000|H’E8005862|16|
|register||||||
|A/D comparison status register|ADCMPSR|R/W|H'0000|H’E8005864|16|

## 27.3.1 A/D Data Registers A to H (ADDRA to ADDRH)

The eight A/D data registers, ADDRA to ADDRH, are 16-bit read-only registers that store the results of A/D conversion. An A/D conversion produces 12-bit data, which is transferred for storage into bits 15 to 4 of the ADDR corresponding to the selected channel. Bits 3 to 0 of ADDR are reserved bits that are always read as 0.

Access to ADDR in 8-bit units is prohibited. ADDR must always be accessed in 16-bit units. Table 27.3 indicates the correspondence between analog input channels and ADDR.

||Bit:||15|14||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||-|-|-|-||
||Initial value:||0|0||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:||R|R||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||||**Initial**|||||||||||||||
|**Bit**|**Bit Name**||||**Value**|||**R/W**||**Description**||||||||||
|15 to 4|||||All 0|||R||Bit Data (12bits)||||||||||
|3 to 0|―||||All 0|||R||Reserved||||||||||
|||||||||||These bits are always read as||||0. The write||value|should always be 0.|||

## **Table 27.3 Correspondence between Analog Input Channels and ADDR**

|**Analog Input Channel**|**A/D Data Register where Conversion Result is Stored**|
|---|---|
|AN0|ADDRA|
|AN1|ADDRB|
|AN2|ADDRC|
|AN3|ADDRD|
|AN4|ADDRE|
|AN5|ADDRF|
|AN6|ADDRG|
|AN7|ADDRH|

## 27.3.2 A/D Comparison Upper Limit Value Registers A to H (ADCMPHA to ADCMPHH)

ADCMPH is a 16-bit readable/writable register that holds the upper limit value to be compared with an A/D conversion result. Eight registers, ADCMPHA to ADCMPHH, are provided.

On completion of A/D conversion on each channel, the A/D conversion result is compared with the data stored in the corresponding upper limit value register. When the result is greater than the upper limit value, the corresponding bit in the A/D comparison status register (ADCMPSR) is set. Comparison with the upper limit value is performed only when the corresponding bit in the A/D comparison interrupt enable register (ADCMPER) is set.

Access to ADCMPH in 8-bit units is prohibited. ADCMPH must always be accessed in 16-bit units.

Table 27.4 indicates the correspondence between the ADDR registers and the ADCMPH/ADCMPL registers.

||Bit:|15|14||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||-|-|-|-|-|-||
||Initial value:|0|0||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R/W|R/W||R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R|R|R|R|R|R||
|||||**Initial**|||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**||||||||||
|15 to 6||||All 0|||R/W||Comparison Upper Limit Value (10 bits)||||||||||
|5 to 0|―|||All 0|||R||Reserved||||||||||
||||||||||These bits|are always read as 0. The write value should always be 0.|||||||||

## 27.3.3 A/D Comparison Lower Limit Value Registers A to H (ADCMPLA to ADCMPLH)

ADCMPL is a 16-bit readable/writable register that holds the lower limit value to be compared with an A/D conversion result. Eight registers, ADCMPLA to ADCMPLH, are provided.

On completion of A/D conversion on each channel, the A/D conversion result is compared with the data stored in the

corresponding lower limit value register. When the result is smaller than the lower limit value, the corresponding bit in the A/D comparison status register (ADCMPSR) is set. Comparison with the lower limit value is performed only when the corresponding bit in the A/D comparison interrupt enable register (ADCMPER) is set.

Access to ADCMPL in 8-bit units is prohibited. ADCMPL must always be accessed in 16-bit units. Table 27.4 indicates the correspondence between the ADDR registers and the ADCMPH/ADCMPL registers.

||Bit:|15|14||13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||-|-|-|-|-|-||
||Initial value:|0|0||0|0|0|0|0|0|0|0|0|0|0|0|0|0||
||R/W:|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R|R||
|||||**Initial**||||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||||
|15 to 6||||All 0|||R/W||Comparison Lower Limit Value (10 bits)|||||||||||
|5 to 0|―|||All 0|||R||Reserved|||||||||||
||||||||||These bits are always read as 0. The write value should always be 0.|||||||||||

## **Table 27.4 Correspondence between ADDR and ADCMPH/ADCMPL Registers**

|**ADDR where Conversion Result is Stored**|**ADCMPH/ADCMPL (Target for Comparison)**|
|---|---|
|ADDRA|ADCMPHA/ADCMPLA|
|ADDRB|ADCMPHB/ADCMPLB|
|ADDRC|ADCMPHC/ADCMPLC|
|ADDRD|ADCMPHD/ADCMPLD|
|ADDRE|ADCMPHE/ADCMPLE|
|ADDRF|ADCMPHF/ADCMPLF|
|ADDRG|ADCMPHG/ADCMPLG|
|ADDRH|ADCMPHH/ADCMPLH|

## 27.3.4 A/D Control/Status Register (ADCSR)

ADCSR is a 16-bit readable/writable register that selects the operating mode, controls the A/D converter, and enables or disables starting of A/D conversion by external trigger input.

|Bit:|15|14|13|12|11<br>10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||ADF|ADIE|ADST||TRGS[3:0]|||CKS[2:0]|||MDS[2:0]|||CH[2:0]||
|Initial value:|0|0|0|0|0<br>0|0|0|0|0|0|0|0|0|0|0|
|R/W:<br>R/(W)*1 R/W|||R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Note:<br>*1|Only 0 can be written to clear||||the flag after 1 is read.|||||||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|ADF|0|R/(W)*1|A/D End Flag|
|||||Status flag indicating the end of A/D conversion.|
|||||[Clearing conditions]|
|||||Cleared by reading ADF while ADF = 1, then writing 0 to ADF|
|||||Cleared when the direct memory access controller is activated by ADI|
|||||interrupt and ADDR is read|
|||||[Setting conditions]|
|||||A/D conversion ends in single mode|
|||||A/D conversion ends for all the selected channels in multi mode|
|||||A/D conversion ends for all the selected channels in scan mode|
|14|ADIE|0|R/W|A/D Interrupt Enable|
|||||Enables or disables the interrupt (ADI) requested at the end of A/D|
|||||conversion. Set the ADIE bit while A/D conversion is not being performed.|
|||||0: A/D conversion end interrupt (ADI) request is disabled|
|||||1: A/D conversion end interrupt (ADI) request is enabled|
|13|ADST|0|R/W*2|A/D Start|
|||||Starts or stops A/D conversion. This bit remains set to 1 during A/D|
|||||conversion.|
|||||0: A/D conversion is stopped|
|||||1: Single mode: A/D conversion starts. This bit is automatically cleared to|
|||||0 when A/D conversion ends on the selected channel.|
|||||Multi mode: A/D conversion starts. This bit is automatically cleared to 0|
|||||when A/D conversion is completed cycling through the selected|
|||||channels.|
|||||Scan mode: A/D conversion starts. A/D conversion is continuously|
|||||performed until this bit is cleared to 0 by software, by a power-on reset|
|||||as well as by a transition to deep standby mode.|
|12 to 9|TRGS[3:0]|0000|R/W|Timer Trigger Select|
|||||These bits enable or disable starting of A/D conversion by a trigger signal.|
|||||0000: Start of A/D conversion by external trigger input is disabled|
|||||0001: A/D conversion is started by conversion trigger TRGAN from the|
|||||multi-function timer pulse unit 2|
|||||0010: A/D conversion is started by conversion trigger TRG0N from the|
|||||multi-function timer pulse unit 2|
|||||0011: A/D conversion is started by conversion trigger TRG4AN from the|
|||||multi-function timer pulse unit 2|
|||||0100: A/D conversion is started by conversion trigger TRG4BN from the|
|||||multi-function timer pulse unit 2|
|||||1001: A/D conversion is started by ADTRG|
|||||Other than above: Setting prohibited|
|8 to 6|CKS[2:0]|000|R/W|Clock Select|
|||||These bits select the A/D conversion time.*3Set the A/D conversion time|
|||||while A/D conversion is halted (ADST = 0).|
|||||000: Conversion time = 256 tcyc*4(maximum)|
|||||001: Conversion time = 298 tcyc*4(maximum)|
|||||010: Conversion time = 340 tcyc*4(maximum)|
|||||011: Conversion time = 382 tcyc*4(maximum)|
|||||100, 101, 110, 111: Setting prohibited|

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**|**Description**|
|---|---|
|5 to 3<br>MDS[2:0]<br>000<br>R/W|Multi-scan Mode<br>These bits select the operating mode for A/D conversion.<br>0xx: Single mode<br>100: Multi mode: A/D conversion on 1 to 4 channels<br>101: Multi mode: A/D conversion on 1 to 8 channels<br>110: Scan mode: A/D conversion on 1 to 4 channels<br>111: Scan mode: A/D conversion on 1 to 8 channels|
|2 to 0<br>CH[2:0]<br>000<br>R/W|Channel Select<br>These bits and the MDS bits in ADCSR select the<br>analog input channels.<br>**MDS = 0xx**<br>**MDS = 100 or MDS =**<br>**110**<br>**MDS = 101 or MDS =**<br>**111**<br>000: AN0<br>000: AN0<br>000: AN0<br>001: AN1<br>001: AN0, AN1<br>001: AN0, AN1<br>010: AN2<br>010: AN0 to AN2<br>010: AN0 to AN2<br>011: AN3<br>011: AN0 to AN3<br>011: AN0 to AN3<br>100: AN4<br>100: AN4<br>100: AN0 to AN4<br>101: AN5<br>101: AN4, AN5<br>101: AN0 to AN5<br>110: AN6<br>110: AN4 to AN6<br>110: AN0 to AN6<br>111: AN7<br>111: AN4 to AN7<br>111: AN0 to AN7|

[Legend]

x: Don't care

Note 1. Only 0 can be written to clear the flag after 1 is read. Note 2. Clear the ADST to stop A/D conversion before transition to software standby mode or module standby mode. Note 3. Set the A/D conversion time to at least the minimum value to obtain the absolute accuracy specified for the A/D converter. Note 4. tcyc indicates a cycle time of the peripheral clock 1 (P1φ).

## 27.3.5 A/D Comparison Interrupt Enable Register (ADCMPER)

ADCMPER is a 16-bit readable/writable register that enables or disables comparison between the A/D data register (ADDR) that holds the A/D conversion result on each channel and the A/D comparison upper/lower limit value register (ADCMPH/ADCMPL), and enables or disables interrupt request.

||Bit:|15|14|13|12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|---|
|||HLMENH|HLMENG|HLMENF|HLMENE|HLMEND|HLMENC|HLMENB HLMENA LLMENH LLMENG LLMENF LLMENE LLMEND LLMENC LLMENB LLMENA||
||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||||**Initial**||||||
|**Bit**|**Bit Name**|||**Value**||**R/W**||**Description**||
|15 to 8|HLMENH|||All 0||R/W||Comparison with Upper Limit Value and Interrupt Enable||
||to|||||||Enables or disables comparison between an A/D conversion result and||
||HLMENA|||||||the upper limit value as well as an LMTI interrupt request in the|case of|
|||||||||the result being greater than the upper limit value.||
|||||||||0: Disables comparison between an A/D conversion result and the upper||
|||||||||limit value as well as an over-limit interrupt (LMTI) request.||
|||||||||1: Enables comparison between an A/D conversion result and the upper||
|||||||||limit value as well as an over-limit interrupt (LMTI) request.||
|7 to 0|LLMENH|||All 0||R/W||Comparison with Lower Limit Value and Interrupt Enable||
||to|||||||Enables or disables comparison between an A/D conversion result and||
||LLMENA|||||||the lower limit value as well as an LMTI interrupt request in the case of||
|||||||||the result being smaller than the lower limit value.||
|||||||||0: Disables comparison between an A/D conversion result and the lower||
|||||||||limit value as well as an over-limit interrupt (LMTI) request.||
|||||||||1: Enables comparison between an A/D conversion result and the lower||
|||||||||limit value as well as an over-limit interrupt (LMTI) request.||

## 27.3.6 A/D Comparison Status Register (ADCMPSR)

ADCMPSR is a 16-bit read-only register that indicates the results of comparison between the A/D data register (ADDR) that holds an A/D conversion result on each channel and the A/D comparison upper/lower limit value register (ADCMPH/ADCMPL).

The bits in this register are valid only when the comparison and an LMTI interrupt are enabled in the A/D comparison interrupt enable register (ADCMPER). When they are disabled, the bits are always in the cleared state. When an A/D conversion result exceeds the upper or lower limit value, the corresponding bit is set to 1.

||Bit:|15|14|13|12|11|10|9<br>8<br>7<br>6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|---|---|
|||HOVRH|HOVRG|HOVRF|HOVRE|HOVRD|HOVRC|HOVRB<br>HOVRA<br>LUDRH<br>LUDRG|LUDRF<br>LUDRE<br>LUDRD<br>LUDRC<br>LUDRB<br>LUDRA||
||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0|0<br>0<br>0<br>0<br>0<br>0||
||R/W:|R|R|R|R|R|R|R<br>R<br>R<br>R|R<br>R<br>R<br>R<br>R<br>R||
|||||**Initial**|||||||
|**Bit**|**Bit Name**|||**Value**||**R/W**||**Description**|||
|15 to 8|HOVRH|||All 0||R||Upper Limit Over Flag|||
||to|||||||Status flag that indicates that an A/D conversion result on each||channel|
||HOVRA|||||||has exceeded the upper limit value in ADCMPH.|||
|||||||||[Clearing condition]|||
|||||||||Cleared by writing 0 to the HLMENn bit for the corresponding||channel|
|||||||||in ADCMPER register|||
|||||||||[Setting condition]|||
|||||||||The HLMEN bit for the corresponding channel in ADCMPER is||1, and an|
|||||||||A/D conversion result for the corresponding channel that is greater than|||
|||||||||the upper limit value in ADCMPH is stored in the ADDR register|||
|7 to 0|LUDRH|||All 0||R||Lower Limit Under Flag|||
||to|||||||Status flag that indicates that an A/D conversion result on each||channel|
||LUDRA|||||||has exceeded the lower limit value in ADCMPL.|||
|||||||||[Clearing condition]|||
|||||||||Cleared by writing 0 to the LLMENn bit for the corresponding channel in|||
|||||||||ADCMPER register|||
|||||||||[Setting condition]|||
|||||||||The LLMEN bit for the corresponding channel in ADCMPER is 1, and an|||
|||||||||A/D conversion result for the corresponding channel that is smaller than|||
|||||||||the lower limit value in ADCMPL is stored in the ADDR register|||

## 27.4 Operation

The A/D converter uses the successive-approximation method, and the resolution is 12 bits. It has three operating modes: single mode, multi mode, and scan mode. Switching the operating mode or analog input channels must be done while the ADST bit in ADCSR is 0 to prevent incorrect operation. The ADST bit can be set at the same time as the operating mode or analog input channels are changed.

## 27.4.1 Single Mode

Single mode should be selected when only A/D conversion on one channel is required.

In single mode, A/D conversion is performed once for the specified one analog input channel, as follows:

1. A/D conversion for the selected channel starts when the ADST bit in ADCSR is set to 1 by software, the multifunction timer pulse unit 2, or external trigger input.

2. When A/D conversion is completed, the A/D conversion result is transferred to the A/D data register corresponding to the channel.

3. After A/D conversion has completed, the ADF bit in ADCSR is set to 1. If the ADIE bit is set to 1 at this time, an ADI interrupt request is generated.

4. The ADST bit that remains 1 during A/D conversion is automatically cleared to 0 when A/D conversion is completed, and the A/D converter becomes idle.

When the operating mode or analog input channel selection must be changed during A/D conversion, to prevent incorrect operation, first clear the ADST bit to 0 to halt A/D conversion. After making the necessary changes, set the ADST bit to 1 to start A/D conversion again. The ADST bit can be set at the same time as the mode or channel selection is switched.

Typical operations when a single channel (AN1) is selected in single mode (MDS[2] = 0) are described next. Figure 27.2 shows a timing diagram for this example (the bits which are set in this example belong to ADCSR).

1. Single mode is selected, input channel AN1 is selected (CH[2:0] = 001), the A/D interrupt is enabled (ADIE = 1), and A/D conversion is started (ADST = 1).

2. When A/D conversion is completed, the A/D conversion result is transferred into ADDRB. At the same time the ADF flag is set to 1, the ADST bit is cleared to 0, and the A/D converter becomes idle.

3. Since ADF = 1 and ADIE = 1, an ADI interrupt is requested.

4. The A/D interrupt handling routine starts.

5. The routine reads ADF = 1, and then writes 0 to the ADF flag.

6. The routine reads and processes the A/D conversion result (ADDRB).

7. Execution of the A/D interrupts handling routine ends. Then, when the ADST bit is set to 1, A/D conversion starts and steps 2 to 7 are executed.

**==> picture [275 x 454] intentionally omitted <==**

**----- Start of picture text -----**<br>
*<br>Waiting<br>Clear Read conversion result A/D conversion result 2<br>time 2<br>*<br>Conversion<br>Set<br>*<br>Waiting A/D conversion result 1<br>Clear Read conversion result<br>time 1<br>* *<br>Conversion<br>Set Set<br>Waiting Waiting Waiting Waiting  )indicate instruction execution by software.<br>A/D conversion starts<br>Vertical arrows(<br>*<br>Note:<br>ADIE ADST ADF Channel 0 (AN0) operating Channel 1 (AN1) operating Channel 2 (AN2) operating Channel 3 (AN3) operating ADDRA ADDRB ADDRC ADDRD<br>**----- End of picture text -----**<br>

**Figure 27.2 Example of A/D Converter Operation (Single Mode, One Channel (AN1) Selected)**

## 27.4.2 Multi Mode

Multi mode should be selected when performing A/D conversion once on one or more channels.

In multi mode, A/D conversion is performed once for a maximum of eight specified analog input channels, as follows:

1. A/D conversion starts from the analog input channel with the lowest number (e.g. AN0, AN1, …, AN3) when the ADST bit in ADCSR is set to 1 by software, the multi-function timer pulse unit 2, or external trigger input.

2. When A/D conversion is completed on each channel, the A/D conversion result is sequentially transferred to the A/D data register corresponding to that channel.

3. After A/D conversion on all selected channels has completed, the ADF bit in ADCSR is set to 1. If the ADIE bit is set to 1 at this time, an ADI interrupt request is generated.

4. The ADST bit that remains 1 during A/D conversion is automatically cleared to 0 when A/D conversion is completed, and the A/D converter becomes idle. If the ADST bit is cleared to 0 during A/D conversion, A/D conversion is halted and the A/D converter becomes idle. The ADF bit is cleared by reading ADF while ADF = 1, then writing 0 to the ADF bit.

A/D conversion is to be performed once on all the specified channels. The conversion results are transferred for storage into the A/D data registers (ADDR) corresponding to the channels.

When the operating mode or analog input channel selection must be changed during A/D conversion, to prevent incorrect operation, first clear the ADST bit to 0 to halt A/D conversion. After making the necessary changes, set the ADST bit to 1. A/D conversion will start again from the first channel in the group. The ADST bit can be set at the same time as the mode or channel selection is changed.

Typical operations when three channels (AN0 to AN2) are selected in multi mode are described next. Figure 27.3 shows a timing diagram for this example.

1. Multi mode is selected (MDS[2] = 1, MDS[1] = 0), analog input channels AN0 to AN2 are selected (CH[2:0] = 010), and A/D conversion is started (ADST = 1).

2. A/D conversion of the first channel (AN0) starts. When A/D conversion is completed, the A/D conversion result is transferred into ADDRA.

3. Next, the second channel (AN1) is selected automatically and A/D conversion starts.

4. Conversion proceeds in the same way through the third channel (AN2).

5. When conversion of all selected channels (AN0 to AN2) is completed, the ADF flag is set to 1 and the ADST bit is cleared to 0.

6. If the ADIE bit is set to 1 at this time, an ADI interrupt is requested.

**==> picture [282 x 432] intentionally omitted <==**

**----- Start of picture text -----**<br>
*<br>Clear<br>Waiting Waiting Waiting<br>* A/D conversion result 3<br>Clear A/D conversion result 2<br>Conversion  time 3<br>A/D conversion result 1<br>A/D conversion Conversion  time 2<br>*<br>Set Conversion  time 1<br>indicate instruction execution by software.<br>Waiting Waiting Waiting Waiting<br> Vertical arrows(   )<br>*<br>Note:<br>ADST ADF Channel 0 (AN0) operating Channel 1 (AN1) operating Channel 2 (AN2) operating Channel 3 (AN3) operating ADDRA ADDRB ADDRC ADDRD<br>**----- End of picture text -----**<br>

**Figure 27.3 Example of A/D Converter Operation (Multi Mode, Three Channels (AN0 to AN2) Selected)**

## 27.4.3 Scan Mode

Scan mode is useful for monitoring analog inputs in a group of one or more channels at all times. In scan mode, A/D conversion is performed sequentially for a maximum of eight specified analog input channels, as follows:

1. A/D conversion starts from the analog input channel with the lowest number (e.g. AN0, AN1, …, AN3) when the ADST bit in ADCSR is set to 1 by software, the multi-function timer pulse unit 2, or external trigger input.

2. When A/D conversion is completed on each channel, the A/D conversion result is sequentially transferred to the A/D data register corresponding to that channel.

3. After A/D conversion on all selected channels has completed, the ADF bit in ADCSR is set to 1. If the ADIE bit is set to 1 at this time, an ADI interrupt request is generated. The A/D converter starts A/D conversion again from the channel with the lowest number.

4. The ADST bit is not cleared automatically, so steps 2. and 3. are repeated as long as the ADST bit remains set to 1. When the ADST bit is cleared to 0, A/D conversion halts and the A/D converter becomes idle. The ADF bit is cleared by reading ADF while ADF = 1, then writing 0 to the ADF bit.

When the operating mode or analog input channel selection must be changed during A/D conversion, to prevent incorrect operation, first clear the ADST bit to 0 to halt A/D conversion. After making the necessary changes, set the ADST bit to 1. A/D conversion will start again from the first channel in the group. The ADST bit can be set at the same time as the mode or channel selection is changed.

Typical operations when three channels (AN0 to AN2) are selected in scan mode are described as follows. Figure 27.4 shows a timing diagram for this example.

1. Scan mode is selected (MDS[2] = 1, MDS[1] = 1), analog input channels AN0 to AN2 are selected (CH[2:0] = 010), and A/D conversion is started (ADST = 1).

2. A/D conversion of the first channel (AN0) starts. When A/D conversion is completed, the A/D conversion result is transferred into ADDRA.

3. Next, the second channel (AN1) is selected automatically and A/D conversion starts.

4. Conversion proceeds in the same way through the third channel (AN2).

5. When conversion of all the selected channels (AN0 to AN2) is completed, the ADF flag is set to 1 and conversion of the first channel (AN0) starts again. If the ADIE bit is set to 1 at this time, an ADI interrupt is requested after A/D conversion of the third channel.

6. The ADST bit is not cleared automatically, so steps 2. to 4. are repeated as long as the ADST bit remains set to 1. When steps 2. to 4. are repeated, the ADF flag is kept to 1. When the ADST bit is cleared to 0, A/D conversion stops. The ADF bit is cleared by reading ADF while ADF = 1, then writing 0 to the ADF bit.

If both the ADF flag and ADIE bit are set to 1 while steps 2. to 4. are repeated, an ADI interrupt is requested at all times. To generate an interrupt on completing conversion of the third channel, clear the ADF bit to 0 after an interrupt is requested.

**==> picture [289 x 432] intentionally omitted <==**

**----- Start of picture text -----**<br>
1*<br>Clear Waiting Waiting Waiting<br>1<br>*<br>Clear 2*<br>time 5 A/D conversion result 4<br>Conversion<br>A/D conversion result 3<br>time 4<br>Conversion<br>A/D conversion result 2<br>Waiting<br>time 3<br>Conversion<br>Continuous A/D conversion A/D conversion result 1<br>time 2<br>Conversion<br>Waiting<br>1* time 1<br>Conversion<br>Set<br>Waiting Waiting Waiting Waiting<br>2. A/D conversion data is invalid.<br>Notes:  1. Vertical arrows(    )indicate instruction execution by software.<br>ADST ADF Channel 0 (AN0) operating Channel 1 (AN1) operating Channel 2 (AN2) operating Channel 3 (AN3) operating ADDRA ADDRB ADDRC ADDRD<br>**----- End of picture text -----**<br>

**Figure 27.4 Example of A/D Converter Operation (Scan Mode, Three Channels (AN0 to AN2) Selected)**

## 27.4.4 A/D Converter Activation by External Trigger or Multi-Function Timer Pulse Unit 2

The A/D converter can be independently activated by an external trigger or an A/D conversion request from the multifunction timer pulse unit 2. To activate the A/D converter by an external trigger or the multi-function timer pulse unit 2, set the A/D trigger enable bits (TRGS[3:0]). When an external trigger or an A/D conversion request from the multifunction timer pulse unit 2 is generated with this bit setting, the ADST bit is set to 1 to start A/D conversion. The channel combination is determined by bits CH2 to CH0 in ADCSR. The timing from setting of the ADST bit until the start of A/ D conversion is the same as when 1 is written to the ADST bit by software.

## 27.4.5 Input Sampling and A/D Conversion Time

The A/D converter has a built-in sample-and-hold circuit. The A/D converter samples the analog input at the A/D conversion start delay time (tD) after the ADST bit in ADCSR is set to 1, then starts conversion. Figure 27.5 shows the A/D conversion timing. Table 27.5 indicates the A/D conversion time.

As indicated in Figure 27.5 , the A/D conversion time (tCONV) includes tD and the input sampling time(tSPL). The length of tD varies depending on the timing of the write access to ADCSR. The total conversion time therefore varies within the ranges indicated in Table 27.5 .

In multi mode and scan mode, the values given in Table 27.5 apply to the first conversion. In the second and subsequent conversions, time is the values given in Table 27.6 .

**==> picture [285 x 311] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1)<br>P1φ<br>Address (2)<br>Write<br>signal<br>Input sampling<br>timing<br>ADF<br>tD tSPL<br>tCONV<br>[Legend]<br>(1): ADCSR write cycle<br>(2):  ADCSR address<br>P1φ:   Peripheral clock 1<br>tD: A/D conversion start delay time<br>tSPL: Input sampling time<br>tCONV: A/D conversion time<br>**----- End of picture text -----**<br>

**Figure 27.5 A/D Conversion Timing**

**Table 27.5 A/D Conversion Time (Single Mode)**

|**Item**<br>**Symbol**|**CKS1 = 0**<br>**CKS1 = 1**|
|---|---|
||**CKS0 = 0**<br>**CKS0 = 1**<br>**CKS0 = 0**<br>**CKS0 = 1**|
||**Min.**<br>**Typ.**<br>**Max.**<br>**Min.**<br>**Typ.**<br>**Max.**<br>**Min.**<br>**Typ.**<br>**Max.**<br>**Min.**<br>**Typ.**<br>**Max.**|
|A/D conversion<br>start delay time<br>tD|9<br>—<br>14<br>10<br>—<br>16<br>11<br>—<br>18<br>12<br>—<br>20|
|Input sampling<br>time<br>tSPL|—<br>78<br>—<br>—<br>91<br>—<br>—<br>104<br>—<br>—<br>117<br>—|
|A/D conversion<br>time<br>tCONV|251<br>—<br>256<br>292<br>—<br>298<br>333<br>—<br>340<br>374<br>—<br>382|

Note: Values in the table are represented in terms of tcyc. tcyc indicates a cycle time of the peripheral clock 1 (P1φ).

## **Table 27.6 A/D Conversion Time (Multi Mode and Scan Mode)**

|**CKS1**|**CKS0**<br>**Conversion Time (tcyc)**|
|---|---|
|0|0<br>240 (constant)|
||1<br>280 (constant)|
|1|0<br>320 (constant)|
||1<br>360 (constant)|

Note: Values in the table are represented in terms of tcyc. tcyc indicates a cycle time of the peripheral clock 1 (P1φ).

## 27.4.6 External Trigger Input Timing

A/D conversion can also be externally triggered. When the TRGS[3:0] bits in ADCSR are set to B'1001, an external trigger is input to the ADTRG pin. The ADST bit in ADCSR is set to 1 at the falling edge of the ADTRG pin, thus starting A/D conversion. Other operations, regardless of the operating mode, are the same as when the ADST bit has been set to 1 by software. Figure 27.6 shows the timing.

**==> picture [271 x 122] intentionally omitted <==**

**----- Start of picture text -----**<br>
P1φ<br>ADTRG<br>Internal trigger<br>signal<br>ADST<br>A/D conversion<br>**----- End of picture text -----**<br>

**Figure 27.6 External Trigger Input Timing**

## 27.5 Interrupt Sources and DMA Transfer Request

The A/D converter generates an A/D conversion end interrupt (ADI) and an over-limit interrupt (LMTI). The direct memory access controller can be activated by an ADI interrupt request depending on the setting of the direct memory access controller.

Table 27.7 shows the relationship between interrupt sources and the DMA transfer request.

## **Table 27.7 Relation between Interrupt Sources and DMA Transfer Request**

||||**Direct Memory Access Controller**|
|---|---|---|---|
|**Name**|**Interrupt Source**|**Interrupt Flag**|**Activation**|
|ADI|A/D conversion end|ADF in ADCSR|Possible|
|LMTI|Conversion result exceeding the limit|HOVRA to HOVRH and|Impossible|
||value|LUDRA to LUDRH||
|||in ADCMPSR||

## (a) ADI Interrupt

The A/D converter generates an A/D conversion end interrupt (ADI) at the end of A/D conversion. An ADI interrupt request is generated if the ADIE bit is set to 1 when the ADF bit in ADCSR is set to 1 on completion of A/D conversion. Note that the direct memory access controller can be activated by an ADI interrupt depending on the setting of the direct memory access controller. In this case, an interrupt is not issued to the CPU. If the setting to activate the direct memory access controller has not been made, an interrupt request is sent to the CPU. Having the converted data read by the direct memory access controller in response to an ADI interrupt enables continuous conversion to be achieved without imposing a load on software.

In single mode, set the direct memory access controller so that DMA transfer initiated by an ADI interrupt only proceeds once (single transfer mode). In the case of A/D conversion on multiple channels in scan mode or multi mode, setting the number of DMA transfers to one causes DMA transfer to finish after transferring only one channel of data. To make the direct memory access controller transfer all conversion data, set the ADDR where A/D conversion data is stored as the transfer source address, and the number of converted channels as the number of transfers (the number of DMA transactions in block transfer mode).

For details, see section 9, Direct Memory Access Controller .

When the direct memory access controller is activated by ADI, the ADF bit in ADCSR is automatically cleared to 0 when data is transferred by the direct memory access controller.

## (b) LMTI Interrupt

An A/D conversion result is compared with the upper or lower limit value on each channel, and if the result exceeds the limit, the over-limit interrupt (LMTI) is generated. While the HLMEN bit in ADCMPER is 1, a conversion result is compared with the upper limit in ADCMPH the instant the conversion value is determined. When the value exceeds the upper limit, the corresponding bit in ADCMPSR is set to 1, which causes an LMTI interrupt to be generated. In the same way, while the LLMEN bit in ADCMPER is 1, a conversion result is compared with the lower limit. If it exceeds the limit, an LMTI interrupt request is generated.

The ADCMPSR register can be referenced in the LMTI interrupt handling to identify the channel causing over-limit value and to know whether the result has exceeded the upper limit value or the lower one.

## 27.6 Definitions of A/D Conversion Accuracy

The A/D converter compares an analog value input from an analog input channel with its analog reference value and converts it to 12-bit digital data. The absolute accuracy of this A/D conversion is the deviation between the input analog value and the output digital value. It includes the following errors:

- Offset error

- Full-scale error

- Quantization error

- Nonlinearity error

These four error quantities are explained below with reference to Figure 27.7 . In the figure, the 12-bit A/D converter is illustrated as the 3-bit A/D converter for explanation. Offset error is the deviation between actual and ideal A/D conversion characteristics when the digital output value changes from the minimum (zero voltage) B'000000000000 (000 in the figure) to B'000000000001 (001 in the figure) ( Figure 27.7 , item (1)). Full-scale error is the deviation between actual and ideal A/D conversion characteristics when the digital output value changes from B'111111111110 (110 in the figure) to the maximum B'111111111111 (111 in the figure)( Figure 27.7 , item (2)). Quantization error is the intrinsic error of the A/D converter and is expressed as 1/2 LSB ( Figure 27.7 , item (3)). Nonlinearity error is the deviation between actual and ideal A/D conversion characteristics between zero voltage and full-scale voltage ( Figure 27.7 , item (4)). Note that it does not include offset, full-scale, or quantization error.

**==> picture [370 x 179] intentionally omitted <==**

**----- Start of picture text -----**<br>
Digital output Digital output (2) Full-scale error<br>Ideal A/D Ideal A/D<br>111 conversion conversion<br>characteristic characteristic<br>110<br>101<br>100<br>(4) Nonlinearity<br>011<br>     error<br>010 (3) Quantization<br>     error Actual A/D<br>001 conversion<br>characteristic<br>000<br>0 1 2 40944095 FS FS<br>40964096 40964096 Analog input Analog input<br>voltage (1) Offset error voltage<br>[Legend]<br>FS:  Full-scale voltage<br>**----- End of picture text -----**<br>

**Figure 27.7 Definitions of A/D Conversion Accuracy**

## 27.7 Usage Notes

When using the A/D converter, note the following points.

## 27.7.1 Module Standby Mode Setting

Operation of the A/D converter can be disabled or enabled using the standby control register. The initial setting is for operation of the A/D converter to be halted. Register access is enabled by clearing module standby mode. For details, see section 42, Power-Down Modes . The wait time (20 μs) is required after release from the module standby state. After the wait time has elapsed, perform conversion by the A/D converter.

## 27.7.2 Setting Analog Input Voltage

Using the LSI outside the following voltage ranges may impair the LSI reliability.

## 1. Analog input range

During A/D conversion, voltages on the analog input pins ANn should not go beyond the following range: AVss  ANn  AVcc (n = 0 to 7).

2. AVcc and AVss input voltages

Input voltages AVcc and AVss should be PVcc  0.3 V  AVcc  PVcc and AVss = Vss. Do not leave the AVcc and AVss pins open even when the A/D converter is not in use and in software standby mode. When not in use, connect AVcc to the power supply (PVcc) and AVss to the ground (Vss).

3. Setting range of AVref input voltage

Set the reference voltage range of the AVref pin as 3.0 V  AVref  AVcc.

## 27.7.3 Notes on Board Design

In board design, digital circuitry and analog circuitry should be as mutually isolated as possible, and layout in which digital circuit signal lines and analog circuit signal lines cross or are in close proximity should be avoided as far as possible. Failure to do so may result in incorrect operation of the analog circuitry due to inductance, adversely affecting A/D conversion values.

Digital circuitry must be isolated from the analog input signals (AN0 to AN7), analog reference voltage (AVref), and analog power supply (AVcc) by the analog ground (AVss). Also, the analog ground (AVss) should be connected at one point to a stable digital ground (Vss) on the board.

## 27.7.4 Processing of Analog Input Pins

To prevent damage from voltage surges at the analog input pins (AN0 to AN7), connect an input protection circuit like the one shown in Figure 27.8 . The circuit shown also includes a CR filter to suppress noise. This circuit is shown as an example; the circuit constants should be selected according to actual application conditions.

**==> picture [301 x 243] intentionally omitted <==**

**----- Start of picture text -----**<br>
AVcc<br>AVref<br>* [2] [R][in] 100 Ω This LSI<br>* [1] * [1] AN0 to AN7<br>0.1 μF<br>AVss<br>Notes:  Values are reference values.<br>1.<br>10 μF 0.01 μF<br>2.  Rin: Input impedance<br>**----- End of picture text -----**<br>

**Figure 27.8 Example of Analog Input Protection Circuit**

## 27.7.5 Permissible Signal Source Impedance

This LSI's analog input is designed such that conversion precision is guaranteed for an input signal for which the signal source impedance is 3 k  or less. This specification is provided to enable the A/D converter's sample-and-hold circuit input capacitance to be charged within the sampling time; if the sensor output impedance exceeds 3 k  , charging may be insufficient and it may not be possible to guarantee A/D conversion precision. However, for A/D conversion in single mode with a large capacitance provided externally for A/D conversion in single mode, the input load will essentially comprise only the internal input resistance of 1 k  , and the signal source impedance is ignored. However, as a low-pass filter effect is obtained in this case, it may not be possible to follow an analog signal with a large differential coefficient (e.g., 5 mV/  s or greater) (see Figure 27.9 ). When converting a high-speed analog signal or performing A/D conversion in scan mode, a low-impedance buffer should be inserted.

**==> picture [310 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>A/D converter<br>Sensor output impedance<br>equivalent circuit<br>Rz Rs<br>Sensor input<br>Cz Cs<br>**----- End of picture text -----**<br>

**Figure 27.9 Example of Analog Input Circuit**

## **Table 27.8 Analog Input Pin Ratings**

|**Item**|**Symbol**<br>**Min.**<br>**Max.**<br>**Unit**|
|---|---|
|Permissible Signal Source Impedance|Rz<br>―<br>3<br>kΩ|
|Low-Pass Filter|Cz<br>―<br>0.1<br>μF|
|Equivalent Circuit of A/D Converter|Rs<br>―<br>1<br>kΩ|
||Cs<br>―<br>20<br>pF|

Note: Values are reference values.

## 27.7.6 Influences on Absolute Precision

Adding capacitance results in coupling with GND, and therefore noise in GND may adversely affect absolute precision. Be sure to connect AVss, etc. to an electrically stable GND.

Care is also required to insure that filter circuits do not communicate with digital signals on the mounting board (i.e., acting as antennas).

## 27.7.7 Usage Note on Port Pins

The analog input pins (AN0 to AN7) are multiplexed with general-purpose I/O port pin functions (pins P1_8 to P1_15) and the latter can be used as digital inputs. Do not use these general-purpose I/O port pins as digital inputs while the A/D converter is in use with 12-bit precision.
