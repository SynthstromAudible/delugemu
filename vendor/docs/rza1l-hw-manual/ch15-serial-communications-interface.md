# 15. Serial Communications Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 621–689. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI has two independent serial communications interface (SCI) channels. The SCI can handle both asynchronous and clock synchronous serial communications.

Asynchronous serial data communications can be carried out with standard asynchronous communications chips such as a Universal Asynchronous Receiver/Transmitter (UART) or Asynchronous Communications Interface Adapter (ACIA). As an extended function in asynchronous communications mode, the SCI also supports smart card (IC card) interfaces conforming to ISO/IEC 7816-3 (standard for Identification Cards).

## 15.1 Overview

Table 15.1 lists the specifications of the SCI module. Figure 15.1 is a block diagram of the SCI module.

## **Table 15.1 Specifications of SCI**

|**Table 15.1**<br>**Specifications of SCI**|**Table 15.1**<br>**Specifications of SCI**||
|---|---|---|
|**Item**||**Specifications**|
|Serial communications mode||Asynchronous operation<br>Clock synchronous operation<br>Smart card interface|
|Transfer speed||Bit rate specifiable with on-chip baud rate generator.|
|Full-duplex communications||Transmitter: Enables continuous transmission by double-buffering.<br>Receiver: Enables continuous reception by double-buffering.|
|I/O pins||See Table 15.2.|
|Data transfer||Selectable as LSB-first or MSB-first transfer|
|Interrupt sources||Transmit-end, transmit-data-empty, receive-data-full, and receive error|
|Power consumption reduction function||Module-standby state can be set for each channel.|
|Asynchronous mode|Data length|7 or 8 bits|
||Transmission stop bit|1 or 2 bits|
||Parity|Even, odd, or none|
||Receive error detection|Parity, overrun, and framing errors|
||Hardware flow control|CTSn and RTSn pins can be used in transfer control.|
||Break detection|Break can be detected by reading RXDn pin level directly in case of a framing error|
||Clock source|Selectable from internal or external clock|
||Multi-processor<br>communications function|Serial communication among multiple processors|
||Noise cancellation|The signal paths from input on the RXDn pins incorporate digital noise filters.|
|Clock synchronous<br>mode|Data length|8 bits|
||Receive error detection|Overrun errors|
||Hardware flow control|CTSn and RTSn pins can be used in transfer control.|
|Smart card interface<br>mode|Error processing|An error signal can be automatically transmitted on detection of a parity error during<br>reception|
|||Data can be automatically re-transmitted on receiving an error signal during<br>transmission|
||Data type|Both direct convention and inverse convention are supported.|

**==> picture [442 x 348] intentionally omitted <==**

**----- Start of picture text -----**<br>
Module data bus<br>RDR TDR SCMR BRR<br>SSR<br>SCR P1φ<br>SCI_RXD RSR TSR SMR Baud rate  P1φ /4<br>generator<br>SEMR<br>P1φ /16<br>SCI_TXD SNFR<br>P1φ /64<br>SECR<br>SCI_CTS/<br>Transmission<br>RTS Parity error occurrence<br>and reception<br>Parity check control Clock<br>External clock<br>SCI_SCK<br>TEI<br>TXI<br>RXI<br>ERI<br>RSR: Receive shift register SSR:    Serial status register<br>RDR: Receive data register SCMR: Smart card mode register<br>TSR: Transmit shift register BRR:    Bit rate register<br>TDR: Transmit data register SEMR: Serial extended mode register<br>SMR: Serial mode register SNFR:  Noise filter setting register<br>SCR: Serial control register SECR:  Extended function control register<br>Bus interface<br>Internal peripheral bus<br>**----- End of picture text -----**<br>

**Figure 15.1 Block Diagram of SCI**

Table 15.2 lists the pin configuration of the SCIs.

**Table 15.2 Input and Output Pins of the SCIs**

|**Table 15.2**|**Input and Output Pins of the SCIs**|**Input and Output Pins of the SCIs**|
|---|---|---|
|**Channel**|**Pin Name**<br>**I/O**<br>**Function**||
|SCI0|SCI_SCK0<br>I/O<br>SCI0 clock input/output||
||SCI_RXD0<br>Input<br>SCI0 receive data input||
||SCI_TXD0|Output<br>SCI0 transmit data output|
||SCI_CTS0<br>/RTS0<br>I/O<br>SCI0 transfer start control input/output||
|SCI1|SCI_SCK1<br>I/O<br>SCI1 clock input/output||
||SCI_RXD1<br>Input<br>SCI1 receive data input||
||SCI_TXD1|Output<br>SCI1 transmit data output|
||SCI_CTS1<br>/RTS1<br>I/O<br>SCI1 transfer start control input/output||

Note: • These pins are referred to as SCKn, RXDn, TXDn, RTSn#, and CTSn# in the text in this section.

## 15.2 Register Descriptions

Table 15.3 is a list of registers.

## **Table 15.3 List of Registers**

|**Table 15.3**|**List of Registers**|||||
|---|---|---|---|---|---|
|Channel|Register Name|Symbol|Value after Reset|Address|Access size|
|0|Serial mode register 0|SMR0|H'00|H'E800B000|8|
||Bit rate register 0|BRR0|H'FF|H'E800B001|8|
||Serial control register 0|SCR0|H'00|H'E800B002|8|
||Transmit data register 0|TDR0|H'FF|H'E800B003|8|
||Serial status register 0|SSR0|H'84|H'E800B004|8|
||Receive data register 0|RDR0|H'00|H'E800B005|8|
||Smart card mode register 0|SCMR0|H'F2|H'E800B006|8|
||Serial extended mode register 0|SEMR0|H'00|H'E800B007|8|
||Noise filter setting register 0|SNFR0|H'00|H'E800B008|8|
||Extended function control register 0|SECR0|H'00|H'E800B00D|8|
|1|Serial mode register 1|SMR1|H'00|H'E800B800|8|
||Bit rate register 1|BRR1|H'FF|H'E800B801|8|
||Serial control register 1|SCR1|H'00|H'E800B802|8|
||Transmit data register 1|TDR1|H'FF|H'E800B803|8|
||Serial status register 1|SSR1|H'84|H'E800B804|8|
||Receive data register 1|RDR1|H'00|H'E800B805|8|
||Smart card mode register 1|SCMR1|H'F2|H'E800B806|8|
||Serial extended mode register 1|SEMR1|H'00|H'E800B807|8|
||Noise filter setting register 1|SNFR1|H'00|H'E800B808|8|
||Extended function control register 1|SECR1|H'00|H'E800B80D|8|

## 15.2.1 Receive Shift Register (RSR)

RSR is a shift register which is used to receive serial data input from the RXDn pin and converts it into parallel data. When one frame of data has been received, it is transferred to RDR automatically. RSR cannot be directly accessed by the CPU.

## 15.2.2 Receive Data Register (RDR)

**==> picture [266 x 40] intentionally omitted <==**

**----- Start of picture text -----**<br>
b7 b6 b5 b4 b3 b2 b1 b0<br>Value after reset: 0 0 0 0 0 0 0 0<br>**----- End of picture text -----**<br>

RDR is an 8-bit register that stores receive data.

When the SCI has received one frame of serial data, it transfers the received serial data from RSR to RDR where it is stored. This allows RSR to receive the next data.

Since RSR and RDR function as a double buffer in this way, continuous receive operations can be performed.

Only read RDR once after each instance of the receive data full interrupt (RXI). Note that if next one frame of data is received before reading receive data from RDR, an overrun error occurs.

RDR cannot be written to by the CPU.

## 15.2.3 Transmit Data Register (TDR)

**==> picture [266 x 40] intentionally omitted <==**

**----- Start of picture text -----**<br>
b7 b6 b5 b4 b3 b2 b1 b0<br>Value after reset: 1 1 1 1 1 1 1 1<br>**----- End of picture text -----**<br>

TDR is an 8-bit register that stores transmit data.

When the SCI detects that TSR is empty, it transfers the transmit data written in TDR to TSR and starts transmission. The double-buffered structures of TDR and TSR enable continuous serial transmission. If the next transmit data has already been written to TDR when one frame of data is transmitted, the SCI transfers the written data to TSR to continue transmission.

The CPU is able to read from or write to TDR at any time. Only write data for transmission to TDR once after each instance of the transmit data empty interrupt (TXI).

## 15.2.4 Transmit Shift Register (TSR)

TSR is a shift register that transmits serial data.

To perform serial data transmission, the SCI first automatically transfers transmit data from TDR to TSR, and then sends the data to the TXDn pin.

TSR cannot be directly accessed by the CPU.

## 15.2.5 Serial Mode Register (SMR)

Note: • Some bits in SMR have different functions in serial communications interface mode and smart card interface mode.

## (1) Serial Communications Interface Mode (SMIF in SCMR = 0)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|
|---|---|---|---|---|---|---|---|
||CM|CHR|PE|PM|STOP|MP|CKS[1:0]|
||<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|||||||

|**Bit**|**Symbol**|**Bit Name**|**Description**|**R/W**|
|---|---|---|---|---|
|b1, b0|CKS[1:0]|Clock Select|b1  b0<br>0  0: P1clock (n = 0)*1|R/W*4|
||||0  1: P1/4 clock (n = 1)*1||
||||1  0: P1/16 clock (n = 2)*1||
||||1  1: P1/64 clock (n = 3)*1||
|b2|MP|Multi-Processor Mode|(Valid only in asynchronous mode)|R/W*4|
||||0: Multi-processor communications function is disabled||
||||1: Multi-processor communications function is enabled||
|b3|STOP|Stop Bit Length|(Valid only in asynchronous mode)|R/W*4|
||||0: 1 stop bit||
||||1: 2 stop bits||
|b4|PM|Parity Mode|(Valid only when the PE bit is 1 in asynchronous mode)|R/W*4|
||||0: Selects even parity||
||||1: Selects odd parity||
|b5|PE|Parity Enable|(Valid only in asynchronous mode)|R/W*4|
||||When transmitting||
||||0: Parity bit addition is not performed||
||||1: The parity bit is added||
||||When receiving||
||||0: Parity bit checking is not performed||
||||1: The parity bit is checked||
|b6|CHR|Character Length|(Valid only in asynchronous mode)|R/W*4|
||||0: Selects 8 bits as the data length*2||
||||1: Selects 7 bits as the data length*3||
|b7|CM|Communications Mode|0: Asynchronous mode|R/W*4|
||||1: Clock synchronous mode||

Note 1. n is the decimal notation of the value of n in BRR (see section 15.2.9, Bit Rate Register (BRR)). Note 2. In clock synchronous mode, this bit setting is invalid and a fixed data length of 8 bits is used. Note 3. LSB-first is fixed and the MSB (bit 7) in TDR is not transmitted in transmission.

Note 4. Writable only when TE in SCR = 0 and RE in SCR = 0 (both serial transmission and reception are disabled).

## **CKS[1:0] Bits (Clock Select)**

These bits select the clock source for the on-chip baud rate generator.

For the relation between the settings of these bits and the baud rate, see section 15.2.9, Bit Rate Register (BRR) .

## **MP Bit (Multi-Processor Mode)**

Disables/enables the multi-processor communications function. The settings of the PE bit and PM bit are invalid in multi-processor mode.

## **STOP Bit (Stop Bit Length)**

## Selects the stop bit length in transmission.

In reception, only the first stop bit is checked regardless of this bit setting. If the second stop bit is 0, it is treated as the start bit of the next transmit frame.

## **PM Bit (Parity Mode)**

Selects the parity mode (even or odd) for transmission and reception. The setting of the PM bit is invalid in multi-processor mode.

## **PE Bit (Parity Enable)**

When this bit is set to 1, the parity bit is added to transmit data, and the parity bit is checked in reception. Irrespective of the setting of the PE bit, the parity bit is not added or checked in multi-processor format.

## **CHR Bit (Character Length)**

Selects the data length for transmission and reception.

In clock synchronous mode, a fixed data length of 8 bits is used.

## (2) Smart Card Interface Mode (SMIF in SCMR = 1)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|
|---|---|---|---|---|---|---|
||GM|BLK|PE|PM|BCP[1:0]|CKS[1:0]|
||<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||||||

|**Bit**|**Symbol**|**Bit Name**|**Description**|**R/W**|
|---|---|---|---|---|
|b1, b0|CKS[1:0]|Clock Select|b1  b0<br>0  0: P1clock (n = 0)*1|R/W*3|
||||0  1: P1/4 clock (n = 1)*1||
||||1  0: P1/16 clock (n = 2)*1||
||||1  1: P1/64 clock (n = 3)*1||
|b3, b2|BCP[1:0]|Base Clock Pulse|Selects the number of base clock cycles in combination with the BCP2 bit in|R/W*3|
||||SCMR.||
||||Setting values in BCP2 bit in SCMR and BCP[1:0] bits in SMR:||
||||BCP2     b3      b2||
||||0       0       0: 93 clock cycles (S = 93)*2||
||||0       0       1: 128 clock cycles (S = 128)*2||
||||0       1       0: 186 clock cycles (S = 186)*2||
||||0       1       1: 512 clock cycles (S = 512)*2||
||||1       0       0: 32 clock cycles (S = 32)*2(Initial value)||
||||1       0       1: 64 clock cycles (S = 64)*2||
||||1       1       0: 372 clock cycles (S = 372)*2||
||||1       1       1: 256 clock cycles (S = 256)*2||
|b4|PM|Parity Mode|(Valid only when the PE bit is 1 in asynchronous mode)|R/W*3|
||||0: Selects even parity||
||||1: Selects odd parity||
|b5|PE|Parity Enable|When this bit is set to 1, a parity bit is added to data for transmission, and|R/W*3|
||||the parity of received data is checked. Set this bit to 1 in smart card interface||
||||mode.||
|b6|BLK|Block Transfer Mode|0: Normal mode operation|R/W*3|
||||1: Block transfer mode operation||
|b7|GM|GSM Mode|0: Normal mode operation|R/W*3|
||||1: GSM mode operation||

Note 1. n is the decimal notation of the value of n in BRR (see section 15.2.9, Bit Rate Register (BRR)). Note 2. S is the value of S in BRR (see section 15.2.9, Bit Rate Register (BRR)). Note 3. Writable only when TE in SCR = 0 and RE in SCR = 0 (both serial transmission and reception are disabled).

## **CKS[1:0] Bits (Clock Select)**

These bits select the clock source for the on-chip baud rate generator.

For the relationship between the settings of these bits and the baud rate, see section 15.2.9, Bit Rate Register (BRR) .

## **BCP[1:0] Bits (Base Clock Pulse)**

These bits select the number of base clock cycles in a 1-bit data transfer time in smart card interface mode. Set these bits in combination with the BCP2 bit in SCMR.

For details, see section 15.6.4, Receive Data Sampling Timing and Reception Margin .

## **PM Bit (Parity Mode)**

Selects the parity mode for transmission and reception (even or odd).

For details on the usage of this bit in smart card interface mode, see section 15.6.2, Data Format (Except in Block Transfer Mode) .

## **PE Bit (Parity Enable)**

Set the PE bit to 1.

The parity bit is added to transmit data before transmission, and the parity bit is checked in reception.

## **BLK Bit (Block Transfer Mode)**

Setting this bit to 1 allows block transfer mode operation.

For details, see section 15.6.3, Block Transfer Mode .

## **GM Bit (GSM Mode)**

Setting this bit to 1 allows GSM mode operation.

In GSM mode, the SSR.TEND flag set timing is put forward to 11.0 etu (elementary time unit = 1-bit transfer time) from the start and the clock output control function is appended. For details, see section 15.6.6, Serial Data Transmission (Except in Block Transfer Mode) and section 15.6.8, Clock Output Control .

## 15.2.6 Serial Control Register (SCR)

Note: • Some bits in SCR have different functions in serial communications interface mode and smart card interface mode.

## (1) Serial Communications Interface Mode (SMIF in SCMR = 0)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|
|---|---|---|---|---|---|---|---|
||TIE|RIE|TE|RE|MPIE|TEIE|CKE[1:0]|
||<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|||||||

|**Bit**|**Symbol**|**Bit Name**|**Description**|**R/W**|
|---|---|---|---|---|
|b1, b0|CKE[1:0]|Clock Enable|(Asynchronous mode)|R/W*1|
||||b1  b0||
||||0  0: On-chip baud rate generator||
||||The SCKn pin functions as general-purpose I/O port.||
||||0  1: On-chip baud rate generator||
||||The clock with the same frequency as the bit rate is output||
||||from the SCKn pin.||
||||1  x: External clock||
||||SEMR.ABCS bit is 0:||
||||The clock with a frequency 16 times the bit rate should be||
||||input from the SCKn pin.||
||||SEMR.ABCS bit is 1:||
||||The clock with a frequency eight times the bit rate should||
||||be input from the SCKn pin.||
||||(Clock synchronous mode)||
||||b1  b0||
||||0  x: Internal clock||
||||The SCKn pin functions as the clock output pin.||
||||1  x: External clock||
||||The SCKn pin functions as the clock input pin.||
|b2|TEIE|Transmit End Interrupt Enable|0: A TEI interrupt request is disabled|R/W|
||||1: A TEI interrupt request is enabled||
|b3|MPIE|Multi-Processor Interrupt Enable|(Valid in asynchronous mode when SMR.MP = 1)|R/W|
||||0: Normal reception||
||||1: When the data with the multi-processor bit set to 0 is received,||
||||the data is not read, and setting the status flags ORER and||
||||FER in SSR to 1 is disabled. When the data with the multi-||
||||processor bit set to 1 is received, the MPIE bit is automatically||
||||cleared to 0, and normal reception is resumed.||
|b4|RE|Receive Enable|0: Serial reception is disabled|R/W*2|
||||1: Serial reception is enabled||
|b5|TE|Transmit Enable|0: Serial transmission is disabled|R/W*2|
||||1: Serial transmission is enabled||
|b6|RIE|Receive Interrupt Enable|0: RXI and ERI interrupt requests are disabled|R/W|
||||1: RXI and ERI interrupt requests are enabled||
|b7|TIE|Transmit Interrupt Enable|0: A TXI interrupt request is disabled|R/W|
||||1: A TXI interrupt request is enabled||

x: Don’t care

Note 1. Writable only when TE = 0 and RE = 0.

Note 2. A 1 can be written only when TE = 0 and RE = 0, while the SMR.CM bit is 1. After setting TE or RE to 1, only 0 can be written in TE and RE. While the SMR.CM bit is 0, writing is enabled under any condition.

## **CKE[1:0] Bits (Clock Enable)**

These bits select the clock source and SCKn pin function.

## **TEIE Bit (Transmit End Interrupt Enable)**

Enables or disables a TEI interrupt request.

A TEI interrupt request is disabled by clearing the TEIE bit to 0.

## **MPIE Bit (Multi-Processor Interrupt Enable)**

When this bit is set to 1 and the data with the multi-processor bit set to 0 is received, the data is not read and setting the status flags ORER and FER in SSR to 1 is disabled. When the data with the multi-processor bit set to 1 is received, the MPIE is automatically cleared to 0, and normal reception is resumed. For details, see section 15.4, Multi-Processor Communications Function .

When the receive data includes the MPB bit is SSR set to 0, the receive data is not transferred from the RSR to the RDR, a receive error is not detected, and setting the flags ORER and FER to 1 is disabled.

When the receive data includes the MPB bit set to 1, the MPB bit is set to 1, the MPIE bit is automatically cleared to 0, the RXI and ERI interrupt requests are enabled (if the RIE bit in SCR is set to 1), and setting the flags ORER and FER to 1 is enabled.

MPIE should be set to 0 if multi-processor communications function is not to be used.

## **RE Bit (Receive Enable)**

Enables or disables serial reception.

When this bit is set to 1, serial reception is started by detecting the start bit in asynchronous mode or the synchronous clock input in clock synchronous mode. Note that SMR should be set prior to setting the RE bit to 1 in order to designate the reception format.

Even if reception is halted by clearing the RE bit to 0, the ORER, FER, and PER flags in SSR are not affected and the previous value is retained.

## **TE Bit (Transmit Enable)**

Enables or disables serial transmission.

When this bit is set to 1, serial transmission is started by writing transmit data to TDR. Note that SMR should be set prior to setting the TE bit to 1 in order to designate the transmission format.

## **RIE Bit (Receive Interrupt Enable)**

Enables or disables RXI and ERI interrupt requests.

An RXI interrupt request is disabled by clearing the RIE bit to 0.

An ERI interrupt request can be cancelled by reading 1 from the ORER, FER, or PER flag in SSR and then clearing the flag to 0, or clearing the RIE bit to 0.

## **TIE Bit (Transmit Interrupt Enable)**

Enables or disables notification of a TXI interrupt request.

Notification of a TXI interrupt request is disabled by clearing the TIE bit to 0.

## (2) Smart Card Interface Mode (SMIF in SCMR = 1)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|
|---|---|---|---|---|---|---|---|
||TIE|RIE|TE|RE|MPIE|TEIE|CKE[1:0]|
||<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|||||||

|**Bit**|**Symbol**|**Bit Name**|**Description**|**R/W**|
|---|---|---|---|---|
|b1, b0|CKE[1:0]|Clock Enable|When GM in SMR = 0|R/W*1|
||||b1  b0||
||||0  0: Output disabled (The SCKn pin is available for use as an I/||
||||O port in accord with the general-purpose I/O port settings.)||
||||0  1: Clock output||
||||1  x: (Setting prohibited)||
||||When GM in SMR = 1||
||||b1  b0||
||||0  0: Output fixed low||
||||x  1: Clock output||
||||1  0: Output fixed high||
|b2|TEIE|Transmit End Interrupt Enable|This bit should be 0 in smart card interface mode.|R/W|
|b3|MPIE|Multi-Processor Interrupt Enable|This bit should be 0 in smart card interface mode.|R/W|
|b4|RE|Receive Enable|0: Serial reception is disabled|R/W*2|
||||1: Serial reception is enabled||
|b5|TE|Transmit Enable|0: Serial transmission is disabled|R/W*2|
||||1: Serial transmission is enabled||
|b6|RIE|Receive Interrupt Enable|0: RXI and ERI interrupt requests are disabled|R/W|
||||1: RXI and ERI interrupt requests are enabled||
|b7|TIE|Transmit Interrupt Enable|0: A TXI interrupt request is disabled|R/W|
||||1: A TXI interrupt request is enabled||

x: Don’t care

Note 1. Writable only when TE = 0 and RE = 0.

Note 2. A 1 can be written only when TE = 0 and RE = 0, while the SMR.CM bit is 1. After setting TE or RE to 1, only 0 can be written in TE and RE. While the SMR.CM bit is 0, writing is enabled under any condition.

For details on interrupt requests, see section 15.8, Interrupt Sources .

## **CKE[1:0] Bits (Clock Enable)**

These bits control the clock output from the SCKn pin.

In GSM mode, clock output can be dynamically switched. For details, see section 15.6.8, Clock Output Control .

## **TEIE Bit (Transmit End Interrupt Enable)**

This bit should be 0 in smart card interface mode.

## **MPIE Bit (Multi-Processor Interrupt Enable)**

This bit should be 0 in smart card interface mode.

## **RE Bit (Receive Enable)**

Enables or disables serial reception.

When this bit is set to 1, serial reception is started by detecting the start bit. Note that SMR should be set prior to setting the RE bit to 1 in order to designate the reception format.

Even if reception is halted by clearing the RE bit to 0, the ORER, FER, and PER flags in SSR are not affected and the previous value is retained.

## **TE Bit (Transmit Enable)**

Enables or disables serial transmission.

When this bit is set to 1, serial transmission is started by writing transmit data to TDR. Note that SMR should be set prior to setting the TE bit to 1 in order to designate the transmission format.

## **RIE Bit (Receive Interrupt Enable)**

Enables or disables RXI and ERI interrupt requests.

An RXI interrupt request is disabled by clearing the RIE bit to 0.

An ERI interrupt request can be cancelled by reading 1 from the ORER, FER, or PER flag in SSR and then clearing the flag to 0, or clearing the RIE bit to 0.

## **TIE Bit (Transmit Interrupt Enable)**

Enables or disables notification of a TXI interrupt request.

Notification of a TXI interrupt request is disabled by clearing the TIE bit to 0.

## 15.2.7 Serial Status Register (SSR)

Note: • Some bits in SSR have different functions in serial communications interface mode and smart card interface mode.

## (1) Serial Communications Interface Mode (SMIF in SCMR = 0)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|
|---|---|---|---|---|---|---|---|---|
||—|—|ORER|FER|PER|TEND|MPB|MPBT|
||<br>x<br>x<br>0<br>0<br>0<br>1<br>0<br>0||||||||

x: Undefined

|**Bit**|**Symbol**|**Bit Name**|**Description**|**R/W**|
|---|---|---|---|---|
|b0|MPBT|Multi-Processor Bit Transfer|Sets the multi-processor bit for adding to the transmission frame|R/W|
||||0: Data transmission cycles||
||||1: ID transmission cycles||
|b1|MPB|Multi-Processor|Value of the multi-processor bit in the reception frame|R|
||||0: Data transmission cycles||
||||1: ID transmission cycles||
|b2|TEND|Transmit End Flag|0: A character is being transmitted.|R|
||||1: Character transfer has been completed.||
|b3|PER|Parity Error Flag|0: No parity error occurred|R/(W)|
||||1: A parity error has occurred|*1|
|b4|FER|Framing Error Flag|0: No framing error occurred|R/(W)|
||||1: A framing error has occurred|*1|
|b5|ORER|Overrun Error Flag|0: No overrun error occurred|R/(W)|
||||1: An overrun error has occurred|*1|
|b7, b6|—|Reserved|The read value is undefined. The write value should be 1.|R|

Note 1. Only 0 can be written to this bit, to clear the flag.

## **MPB Bit (Multi-Processor)**

Holds the value of the multi-processor bit in the reception frame. This bit does not change when the RE bit in SCR is 0.

## **TEND Flag (Transmission End Flag)**

## Indicates completion of transmission.

## [Setting conditions]

- Clearing of the SCR.TE bit to 0 (disabling serial transmission operations) When the SCR.TE bit is changed from 0 to 1, the TEND flag is not affected and retains the value 1.

- The TDR is not updated at the time of transmission of the tail-end bit of a character being transmitted

- [Clearing condition]

- When data for transmission are written to the TDR while the SCR.TE is 1 When the TEND flag is cleared in response to writing of data for transmission to the TDR, dummy read the TEND flag before return from interrupt exception processing for TEI interrupt requests when the latter are enabled.

## **PER Bit (Parity Error Flag)**

Indicates that a parity error has occurred during reception in asynchronous mode and the reception ends abnormally.

[Setting condition]

- When a parity error is detected during reception Although receive data when the parity error occurs is transferred to RDR, no RXI interrupt request occurs. Note that when the PER flag is being set to 1, the subsequent receive data is not transferred to RDR.

- [Clearing condition]

- When 0 is written to PER after reading PER = 1 (after writing 0 to it, read the PER bit to check that it has actually been cleared to 0.)

Even when the RE bit in SCR is cleared to 0 (which indicates that serial reception is disabled), the PER flag is not affected and retains its previous value.

## **FER Bit (Framing Error Flag)**

Indicates that a framing error has occurred during reception in asynchronous mode and the reception ends abnormally.

[Setting condition]

- When the stop bit is 0

   - In 2-stop-bit mode, only the first stop bit is checked whether it is 1 but the second stop bit is not checked. Note that although receive data when the framing error occurs is transferred to RDR, no RXI interrupt request occurs. In addition, when the FER flag is being set to 1, the subsequent receive data is not transferred to RDR.

- [Clearing condition]

- When 0 is written to FER after reading FER = 1 (after writing 0 to it, read the FER bit to check that it has actually been cleared to 0.)

Even when the RE bit in SCR is cleared to 0, the FER flag is not affected and retains its previous value.

## **ORER Bit (Overrun Error Flag)**

Indicates that an overrun error has occurred during reception and the reception ends abnormally.

[Setting condition]

- When the next data is received before receive data is read from RDR

   - In RDR, receive data prior to an overrun error occurrence is retained, but data received after the overrun error occurrence is lost. When the ORER flag is set to 1, subsequent serial reception cannot be performed. Note that, in clock synchronous mode, serial transmission also cannot continue.

- [Clearing condition]

- When a 0 is written to ORER after reading ORER = 1 (after writing a 0 to it, read the ORER bit to check that it has actually been cleared to 0.)

Even when the RE bit in SCR is cleared to 0, the ORER flag is not affected and retains its previous value.

## (2) Smart Card Interface Mode (SMIF in SCMR = 1)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|
|---|---|---|---|---|---|---|---|---|
||—|—|ORER|ERS|PER|TEND|MPB|MPBT|
||<br>x<br>x<br>0<br>0<br>0<br>1<br>0<br>0||||||||

x: Undefined

|**Bit**|**Symbol**|**Bit Name**|**Description**|**R/W**|
|---|---|---|---|---|
|b0|MPBT|Multi-Processor Bit Transfer|This bit should be set to 0 in smart card interface mode.|R/W|
|b1|MPB|Multi-Processor|This bit is not used in smart card interface mode. It should be set|R|
||||to 0.||
|b2|TEND|Transmit End Flag|0: A character is being transmitted.|R|
||||1: Character transfer has been completed.||
|b3|PER|Parity Error Flag|0: No parity error occurred|R/(W)|
||||1: A parity error has occurred|*1|
|b4|ERS|Error Signal Status Flag|0: Low error signal not responded|R/(W)|
||||1: Low error signal responded|*1|
|b5|ORER|Overrun Error Flag|0: No overrun error occurred|R/(W)|
||||1: An overrun error has occurred|*1|
|b7, b6|—|Reserved|The read value is undefined. The write value should be 1.|R|

Note 1. Only 0 can be written to this bit, to clear the flag.

## **MPBT Bit (Multi-Processor Bit Transfer)**

This bit should be set to 0 in smart card interface mode.

## **MPB Bit (Multi-Processor)**

This bit is not used in smart card interface mode. It should be set to 0.

## **TEND Flag (Transmission End Flag)**

With no error signal from the receiving side, this bit is set to 1 when further data for transfer is ready to be transferred to the TDR register.

## [Setting conditions]

- When SCR.TE bit = 0 (disabling serial transmission operations)

When the SCR.TE bit is changed from 0 to 1, the TEND flag is not affected and retains the value 1.

- When a specified period has elapsed after the latest transmission of one byte, the ERS flag is 0, and the TDR register is not updated

The set timing is determined by register settings as listed below.

When SMR.GM = 0 and SMR.BLK = 0, 12.5 etu after the start of transmission When SMR.GM = 0 and SMR.BLK = 1, 11.5 etu after the start of transmission When SMR.GM = 1 and SMR.BLK = 0, 11.0 etu after the start of transmission When SMR.GM = 1 and SMR.BLK = 1, 11.0 etu after the start of transmission

- [Clearing condition]

- When data for transmission are written to the TDR while the SCR.TE is 1

## **PER Flag (Parity Error Flag)**

Indicates that a parity error has occurred during reception in asynchronous mode and the reception ends abnormally.

[Setting condition]

- When a parity error is detected during reception

   - Although receive data when the parity error occurs is transferred to RDR, no RXI interrupt request occurs. Note that when the PER flag is being set to 1, the subsequent receive data is not transferred to RDR.

- [Clearing condition]

- When 0 is written to PER after reading PER = 1 (After writing 0 to it, read the PER bit to check that it has actually been cleared to 0.)

Even when the RE bit in SCR is cleared to 0 (which indicates that serial reception is disabled), the PER flag is not affected and retains its previous value.

## **ERS Flag (Error Signal Status Flag)**

[Setting condition]

- When a low error signal is sampled

- [Clearing condition]

- When 0 is written to ERS after reading ERS = 1

## **ORER Flag (Overrun Error Flag)**

Indicates that an overrun error has occurred during reception and the reception ends abnormally.

[Setting condition]

- When the next data is received before receive data is read from RDR In RDR, the receive data prior to an overrun error occurrence is retained, but data received following the overrun error occurrence is lost. When the ORER flag is set to 1, subsequent serial reception cannot be performed.

- [Clearing condition]

- When 0 is written to ORER after reading ORER = 1 (After writing 0 to it, read the ORER bit to check that it has actually been cleared to 0.)

Even when the RE bit in SCR is cleared to 0, the ORER flag is not affected and retains its previous value.

## 15.2.8 Smart Card Mode Register (SCMR)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0<br>BCP2<br>—<br>—<br>—<br>SDIR<br>SINV<br>—<br>SMIF<br> <br>1<br>1<br>1<br>1<br>0<br>0<br>1<br>0|
|---|---|
|**Bit**<br>**Symbol**<br>**Bit Name**<br>**Description**<br>**R/W**||
|b0<br>SMIF<br>Smart Card Interface Mode<br>Select<br>0: Serial communications interface mode<br>1: Smart card interface mode<br>R/W*1||
|b1<br>—<br>Reserved<br>This bit is read as 1. The write value should be 1.<br>R||
|b2<br>SINV<br>Transmitted/Received Data<br>Invert<br>0: TDR contents are transmitted as they are. Receive data is stored as<br>it is in RDR.<br>1: TDR contents are inverted before being transmitted. Receive data is<br>stored in inverted form in RDR.<br>R/W*1||
|b3<br>SDIR<br>Transmitted/Received Data<br>Transfer Direction<br>0: Transfer with LSB-first<br>1: Transfer with MSB-first<br>R/W*1||
|b6 to b4<br>—<br>Reserved<br>This bit is read as 1. The write value should be 1.<br>R||
|b7<br>BCP2<br>Base Clock Pulse 2<br>Selects the number of base clock cycles in combination with the<br>SMR.BCP[1:0] bits.<br>Setting values in the SCMR.BCP2 bit and SMR.BCP[1:0] bits<br>BCP2  BCP1  BCP0<br>0       0       0: 93 clock cycles (S = 93)*2<br>0       0       1: 128 clock cycles (S = 128)*2<br>0       1       0: 186 clock cycles (S = 186)*2<br>0       1       1: 512 clock cycles (S = 512)*2<br>1       0       0: 32 clock cycles (S = 32)*2(Initial Value)<br>1       0       1: 64 clock cycles (S = 64)*2<br>1       1       0: 372 clock cycles (S = 372)*2<br>1       1       1: 256 clock cycles (S = 256)*2<br>R/W*1||

Note 1. Writable only when TE in SCR = 0 and RE in SCR = 0 (both serial transmission and reception are disabled). Note 2. S is the value of S in BRR (see section 15.2.9, Bit Rate Register (BRR)).

## **SMIF Bit (Smart Card Interface Mode Select)**

When this bit is set to 1, smart card interface mode is selected.

When this bit is set to 0, asynchronous or clock synchronous mode is selected.

## **SINV Bit (Transmitted/Received Data Invert)**

Inverts the transmit/receive data logic level. This bit does not affect the logic level of the parity bit. To invert the parity bit, invert the PM bit in SMR.

## **SDIR Bit (Transmitted/Received Data Transfer Direction)**

Selects the serial/parallel conversion format.

## **BCP2 Bit (Base Clock Pulse 2)**

Selects the number of base clock cycles in a 1-bit data transfer time in smart card interface mode. Set this bit in combination with the SMR.BCP[1:0] bits.

## 15.2.9 Bit Rate Register (BRR)

**==> picture [266 x 40] intentionally omitted <==**

**----- Start of picture text -----**<br>
b7 b6 b5 b4 b3 b2 b1 b0<br>Value after reset: 1 1 1 1 1 1 1 1<br>**----- End of picture text -----**<br>

## BRR is an 8-bit register that adjusts the bit rate.

As each SCI channel has independent baud-rate generator control, different bit rates can be set for each. Table 15.4 lists the relationships between the setting (N) in the BRR and the bit rate (B) for normal asynchronous mode, multi-processor transfer, clock synchronous mode, and smart card interface mode.

The initial value of BRR is FFh.

BRR can be read from by the CPU at all times, but it can be written to only when the TE and RE bits in SCR are 0.

**Table 15.4 Relationships between N Setting in BRR and Bit Rate B**

||||||–1 }×100<br>**Error**<br>–1 }×100<br>–1 }×100<br>P1φ ×106<br>B×64×22n-1×(N+1)<br>P1φ ×106<br>B×32×22n-1×(N+1)<br>P1φ ×106<br>B×S×22n+1×(N+1)|
|---|---|---|---|---|---|
|**Mode**|**ABCS Bit in SEMR**||**BRR Setting**||**Error**|
|Asynchronous,<br>multi-processor<br>transfer|0|N =|–1<br>64×22n-1×B<br>P1φ<br>×106|Error (%) = {|–1 }×100<br>P1φ ×106<br>B×64×22n-1×(N+1)|
||1|N =|–1<br>32×22n-1×B<br>P1φ ×106|Error (%) = {|–1 }×100<br>P1φ ×106<br>B×32×22n-1×(N+1)|
|Clock synchronous||N =|–1<br>8×22n-1×B<br>P1φ ×106|||
|Smart card interface||N =|–1<br>S×22n+1×B<br>P1φ ×106|Error (%) = {|–1 }×100<br>P1φ ×106<br>B×S×22n+1×(N+1)|
|||||||

B: Bit rate (bps)

N: BRR setting for baud rate generator (0  N 255)

P1: Operating frequency (MHz)

n and S: Determined by the SMR setting listed in the following table.

**Table 15.5 Clock Source Settings**

|**SMR Setting**|||
|---|---|---|
|**CKS[1:0] Bits**|**Clock Source**|**n**|
|0 0|P1clock|0|
|0 1|P1/4 clock|1|
|1 0|P1/16 clock|2|
|1 1|P1/64 clock|3|

**Table 15.6 Base Clock Settings in Smart Card Interface Mode**

|**SCMR**|**Setting**|**SMR Setting**|**Base Clock Cycles for**||
|---|---|---|---|---|
|**BCP2**|**Bit**|**BCP[1:0] Bits**|**One-bit Period**|**S**|
|0||0 0|93 clock cycles|93|
|0||0 1|128 clock cycles|128|
|0||1 0|186 clock cycles|186|
|0||1 1|512 clock cycles|512|
|1||0 0|32 clock cycles|32|
|1||0 1|64 clock cycles|64|
|1||1 0|372 clock cycles|372|
|1||1 1|256 clock cycles|256|

Table 15.7 lists sample N settings in BRR in normal asynchronous mode. Table 15.8 lists the maximum bit rate settable for each operating frequency. Examples of BRR (N) settings in clock synchronous mode are listed in Table 15.10 . Examples of BRR (N) settings in smart card interface mode are listed in Table 15.12 . In smart card interface mode, the number of base clock cycles S in a 1-bit data transfer time can be selected. For details, see section 15.6.4, Receive Data Sampling Timing and Reception Margin . Table 15.9 and Table 15.11 list the maximum bit rates with external clock input.

When the asynchronous mode base clock select bit (ABCS) in the serial extended mode register (SEMR) is set to 1 in asynchronous mode, the bit rate is two times that of listed in Table 15.7 .

**Table 15.7 Examples of BRR Settings for Various Bit Rates (Asynchronous Mode)**

|**Table 15.7**<br>**Examples**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|**of BRR Settings for Various Bit Rates (Asynchronous Mode)**|
|---|---|---|---|---|---|---|---|---|---|
|**Bit Rate (bps)**|**Operating Frequency P1****(MHz)**|||||||||
||**50**|||**64**|||**66.67**|||
||**n**|**N**|**Error (%)**|**n**|**N**|**Error (%)**|**n**|**N**|**Error (%)**|
|110|3|221|–0.02|||||||
|150|3|162|–0.15|3|207|0.16|3|216|0.01|
|300|3|80|0.47|3|103|0.16|3|108|–0.45|
|600|2|162|–0.15|2|207|0.16|2|216|0.01|
|1200|2|80|0.47|2|103|0.16|2|108|–0.45|
|2400|1|162|–0.15|1|207|0.16|1|216|0.01|
|4800|1|80|0.47|1|103|0.16|1|108|–0.45|
|9600|0|162|–0.15|1|51|0.16|0|216|0.01|
|19200|0|80|0.47|0|103|0.16|0|108|–0.45|
|31250|0|49|0.00|0|63|0.00|0|66|–0.50|
|38400|0|40|–0.76|0|51|0.16|0|53|0.47|

[Legend]

Space: Setting prohibited.

## -: Can be set, but there will be error.

Note: • This is an example when the ABCS bit in SEMR is 0. When the ABCS bit is set to 1, the bit rate is two times.

**Table 15.8 Maximum Bit Rate for Each Operating Frequency (Asynchronous Mode)**

|**P1****(MHz)**|**Maximum Bit Rate(bps)**|**n**|**N**|
|---|---|---|---|
|50|1562500|0|0|
|64|2000000|0|0|
|66.67|2083333|0|0|

Note: • When the ABCS bit in SEMR is set to 1, the bit rate is two times.

## **Table 15.9 Maximum Bit Rate with External Clock Input (Asynchronous Mode)**

|**P1****(MHz)**|**External Input Clock(MHz)**|**Maximum Bit Rate(bps)**|**Maximum Bit Rate(bps)**|
|---|---|---|---|
|||**SEMR.ABCS bit = 0**|**SEMR.ABCS bit = 1**|
|50|12.5|781250|1562500|
|64|16|1000000|2000000|
|66.67|16.667|1041667|2083333|

## **Table 15.10 BRR Settings for Various Bit Rates (Clock Synchronous Mode)**

|**Table 15.10**<br>**BRR Settings for**|**Various Bit Rates (Clock Synchronous Mode)**|**Various Bit Rates (Clock Synchronous Mode)**|**Various Bit Rates (Clock Synchronous Mode)**|**Various Bit Rates (Clock Synchronous Mode)**|**Various Bit Rates (Clock Synchronous Mode)**|**Various Bit Rates (Clock Synchronous Mode)**|
|---|---|---|---|---|---|---|
|**Bit Rate (bps)**|**Operating Frequency P1****(MHz)**||||||
||**50**||**64**||**66.67**||
||**n**|**N**|**n**|**N**|**n**|**N**|
|110|||||||
|250|||||||
|500|||||||
|1k|3|194|3|249|||
|2.5k|3|77|3|99|3|103|
|5k|2|155|2|199|2|207|
|10k|2|77|2|99|2|103|
|25k|1|124|1|159|1|166|
|50k|1|62|1|79|1|82|
|100k|0|124|0|159|0|166|
|250k|0|49|0|63|0|66|
|500k|0|24|0|31|0|32|
|1M|—|—|0|15|0|16|
|2.5M|0|4|—|—|—|—|
|5M|—|—|—|—|—|—|

Space: Setting prohibited.

—: Can be set, but there will be error.

**Table 15.11 Maximum Bit Rate with External Clock Input (Clock Synchronous Mode)**

|**P1****(MHz)**|**External Input Clock (MHz)**|**Maximum Bit Rate (bps)**|
|---|---|---|
|50|8.3333|8333333.3|
|64|10.6667|10666666.7|
|66.67|11.1111|11111100|

**Table 15.12 BRR Settings for Various Bit Rates (Smart Card Interface Mode, n = 0, S = 372)**

|**Bit Rate (bps)**|**P1****(MHz)**|**P1****(MHz)**|**P1****(MHz)**|**P1****(MHz)**|**P1****(MHz)**|**P1****(MHz)**|**P1****(MHz)**|**P1****(MHz)**|**P1****(MHz)**|
|---|---|---|---|---|---|---|---|---|---|
||**50**|||**64**|||**66.67**|||
||**n**|**N**|**Error (%)**|**n**|**N**|**Error (%)**|**n**|**N**|**Error (%)**|
|9600|0|6|0.01|0|8|0.44|0|8|3.72|

**Table 15.13 Maximum Bit Rate for Each Operating Frequency (Smart Card Interface Mode, S = 372)**

|**P1****(MHz)**|**Maximum Bit Rate (bps)**|**n**|**N**|
|---|---|---|---|
|50|67204|0|0|
|64|86022|0|0|
|66.67|89610|0|0|

## 15.2.10 Serial Extended Mode Register (SEMR)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|
|---|---|---|---|---|---|---|---|---|
||—|—|NFEN|ABCS|—|—|—|—|
||<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||||||||

|**Bit**|**Symbol**|**Bit Name**|**Description**|**R/W**|
|---|---|---|---|---|
|b3 to b0|—|Reserved|These bits are read as 0. The write value should be 0.|R|
|b4|ABCS|Asynchronous Mode|(Valid only in asynchronous mode)|R/W*1|
|||Base Clock Select|0: Selects 16 base clock cycles for 1-bit period||
||||1: Selects 8 base clock cycles for 1-bit period||
|b5|NFEN|Digital Noise Filter|(In asynchronous mode)|R/W*1|
|||Function Enable|0: Noise cancellation function for the RXDn input signal is disabled.||
||||1: Noise cancellation function for the RXDn input signal is enabled.||
||||The NFEN bit should be 0 in any mode other than above.||
|b7, b6|—|Reserved|These bits are read as 0. The write value should be 0.|R|

Note 1. Writable only when TE in SCR = 0 and RE in SCR = 0 (both serial transmission and reception are disabled).

## **NFEN Bit (Digital Noise Filter Function Enable)**

This bit enables or disables the digital noise filter function.

When the function is enabled, noise cancellation is applied to the RXDn input signal in asynchronous mode. In any mode other than above, set the NFEN bit to 0 to disable the digital noise filter function. When the function is disabled, input signals are transferred as is, as internal signals.

## 15.2.11 Noise Filter Setting Register (SNFR)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0<br>—<br>—<br>—<br>—<br>—<br>NFCS[2:0]<br> <br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|
|---|---|
|**Bit**<br>**Symbol**<br>**Bit Name**<br>**Description**<br>**R/W**||
|b2 to b0<br>NFCS[2:0]<br>Noise Filter Clock Select<br>In asynchronous mode, the standard setting for the base clock is as<br>follows.<br>b2      b0<br>0  0  0: The clock signal divided by 1 is used with the noise filter.<br>Other values: Do not make settings other than those listed above.<br>R/W*1||
|b7 to b3<br>—<br>Reserved<br>These bits are read as 0. The write value should be 0.<br>R||

Note 1. Writing to these bits is only possible when the RE and TE bits in the SCR are 0. (both serial transmission and reception are disabled.)

## **NFCS[2:0] Bits (Noise Filter Clock Select)**

These bits select the sampling clock for the digital noise filter. To use the noise filter in asynchronous mode, set these bits to 000b.

## 15.2.12 Extended Function Control Register (SECR)

|Value after reset:|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|b7<br>b6<br>b5<br>b4<br>b3<br>b2<br>b1<br>b0|
|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|CTSE|—|
||<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||||||||

|**Bit**||**Symbol**|**Bit Name**|**Description**|**R/W**|
|---|---|---|---|---|---|
|b0||—|Reserved|This bit is read as 0. The write value should be 0.|R|
|b1||CTSE|CTS Enable|0: CTS pin function is disabled (RTS output function is enabled).|R/W*1|
|||||1: CTS pin function is enabled||
|b7|to b2|—|Reserved|These bits are read as 0. The write value should be 0.|R|

Note 1. Writing to this bit is only possible when the RE and TE bits in the SCR are 0 (both serial transmission and reception are disabled).

SECR is used to select the extension settings in asynchronous and clock-synchronous modes.

## **CTSE Bit (CTS Enable)**

Set this bit to 1 if the CTS control signal is used for control of transmission and reception. The RTS signal is output when this bit is set to 0. Set this bit to 0 in smart card interface mode.

## 15.3 Operation in Asynchronous Mode

Figure 15.2 shows the general format for asynchronous serial communications.

One frame consists of a start bit (low level), transmit/receive data, a parity bit, and stop bits (high level).

In asynchronous serial communications, the communications line is usually held in the mark state (high level).

The SCI monitors the communications line, and when it goes to the space state (low level), recognizes a start bit and starts serial communications.

Inside the SCI, the transmitter and receiver are independent units, enabling full-duplex communications. Both the transmitter and the receiver also have a double-buffered structure, so that data can be read or written during transmission or reception, enabling continuous data transmission and reception.

**==> picture [424 x 149] intentionally omitted <==**

**----- Start of picture text -----**<br>
Idle state<br>(mark state)<br>1 LSB MSB 1<br>Serial data 0 D0 D1 D2 D3 D4 D5 D6 D7 0/1 1 1<br>Start  Transmit/receive data Parity  Stop bit<br>bit bit<br>1 bit 7 or 8 bits 1 or 0 bit 1 or 2 bits<br>One unit of transfer data (character or frame)<br>**----- End of picture text -----**<br>

**Figure 15.2 Data Format in Asynchronous Serial Communications (Example with 8-Bit Data, Parity, Two Stop Bits)**

## 15.3.1 Serial Data Transfer Format

Table 15.14 lists the serial data transfer formats that can be used in asynchronous mode.

Any of 12 transfer formats can be selected according to the SMR setting. For details of multi-processor function, see section 15.4, Multi-Processor Communications Function .

**Table 15.14 Serial Transfer Formats (Asynchronous Mode)**

|**SMR Setting**|**SMR Setting**|**SMR Setting**|**SMR Setting**||**1**|**Serial Transfer Format and Frame Length**<br>**2**<br>**3**<br>**4**<br>**5**<br>**6**<br>**7**<br>**8**<br>**9**<br>**10**<br>**11**<br>**12**|**Serial Transfer Format and Frame Length**<br>**2**<br>**3**<br>**4**<br>**5**<br>**6**<br>**7**<br>**8**<br>**9**<br>**10**<br>**11**<br>**12**|**Serial Transfer Format and Frame Length**<br>**2**<br>**3**<br>**4**<br>**5**<br>**6**<br>**7**<br>**8**<br>**9**<br>**10**<br>**11**<br>**12**|
|---|---|---|---|---|---|---|---|---|
|**CHR**|**PE**|**MP**|**STO**<br>**P**||||||
|0|0|0|0||S|8-bit data<br>STOP|||
|||||||8-bit data|||
||||||||||
|0|0|0|1||S|8-bit data<br>STOP<br>STOP|||
|||||||8-bit data|||
||||||||||
|0|1|0|0||S|8-bit data<br>P<br>STOP|||
|||||||8-bit data||P|
||||||||||
|0|1|0|1||S|8-bit data<br>P<br>STOP<br>STOP|||
|||||||8-bit data||P|
||||||||||
|1|0|0|0||S|7-bit data<br>STOP|||
|||||||7-bit data|||
||||||||||
|1|0|0|1||S|7-bit data<br>STOP<br>STOP|||
|||||||7-bit data|||
||||||||||
|1|1|0|0||S|7-bit data<br>P<br>STOP|||
|||||||7-bit data|P||
||||||||||
|1|1|0|1||S|7-bit data<br>P<br>STOP<br>STOP|||
|||||||7-bit data|P||
||||||||||
|0|—|1|0||S|8-bit data<br>MPB<br>STOP|||
|||||||8-bit data||MPB|
||||||||||
|0|—|1|1||S|8-bit data<br>MPB<br>STOP<br>STOP|||
|||||||8-bit data||MPB|
||||||||||
|1|—|1|0||S|7-bit data<br>MPB<br>STOP|||
|||||||7-bit data|MPB||
||||||||||
|1|—|1|1||S|7-bit data<br>MPB<br>STOP<br>STOP|||
|||||||7-bit data|MPB||
||||||||||

S: Start bit

STOP: Stop bit

P: Parity bit

MPB: Multi-processor bit

## 15.3.2 Receive Data Sampling Timing and Reception Margin in Asynchronous Mode

In asynchronous mode, the SCI operates on a base clock with a frequency of 16 times *[1] the bit rate.

In reception, the SCI samples the falling edge of the start bit using the base clock, and performs internal synchronization. Since receive data is sampled at the rising edge of the 8th pulse *[1] of the base clock, data is latched at the middle of each bit, as shown in Figure 15.3 . Thus the reception margin in asynchronous mode is determined by formula (1) below.

**==> picture [275 x 26] intentionally omitted <==**

## M: Reception margin

N: Ratio of bit rate to clock (N = 16 when ABCS in SEMR = 0, N = 8 when ABCS in SEMR = 1)

D: Duty cycle of clock (D = 0.5 to 1.0)

L: Frame length (L = 9 to 12)

F: Absolute value of clock frequency deviation

Assuming values of F = 0 and D = 0.5 in formula (1), the reception margin is determined by the formula below.

## M = {0.5 - 1/(2 x 16)}  100 (%) = 46.875%

However, this is only the computed value, and a margin of 20% to 30% should be allowed in system design.

Note 1. This is an example when the ABCS bit in SEMR is 0. When the ABCS bit is 1, a frequency of 8 times the bit rate is used as a base clock and receive data is sampled at the rising edge of the 4th pulse of the base clock

**==> picture [463 x 194] intentionally omitted <==**

**----- Start of picture text -----**<br>
16 clock pulses<br>8 clock pulses<br>0 7 15 0 7 15 0<br>Internal base clock<br>Receive data (RXDn) Start bit D0 D1<br>Synchronization<br>sampling timing<br>Data sampling<br>timing<br>**----- End of picture text -----**<br>

**Figure 15.3 Receive Data Sampling Timing in Asynchronous Mode**

## 15.3.3 Clock

Either an internal clock generated by the on-chip baud rate generator or an external clock input to the SCKn pin can be selected as the SCI’s transfer clock, according to the setting of the CM bit in SMR and the CKE[1:0] bits in SCR. When an external clock is input to the SCKn pin, the clock frequency should be 16 times the bit rate (when ABCS in SEMR = 0) and 8 times the bit rate (when ABCS in SEMR = 1).

When the SCI is operated on an internal clock, the clock can be output from the SCKn pin. The frequency of the clock output in this case is equal to the bit rate, and the phase is such that the rising edge of the clock is in the middle of the transmit data, as shown in Figure 15.4 .

**==> picture [467 x 81] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCKn<br>TXDn 0 D0 D1 D2 D3 D4 D5 D6 D7 0/1 1 1<br>1 frame<br>**----- End of picture text -----**<br>

**Figure 15.4 Phase Relationship between Output Clock and Transmit Data (Asynchronous Mode: SMR.CHR = 0, PE = 1, MP = 0, STOP = 1)**

## 15.3.4 CTS and RTS Functions

The CTS function is the use of input on the CTSn# pin in transmission control. Setting the SECR.CTSE bit to 1 enables the CTS function. When the CTS function is enabled, placing the low level on the CTSn# pin causes transmission to start.

Applying the low level to the CTS# pin while transmission is in progress does not affect transmission of the current frame, which continues.

In the RTS function, by using the function of output on the RTSn# pin, a low level is output when reception becomes possible. Conditions for output of the low and high level are shown below.

## [Conditions for low-level output]

Satisfaction of all conditions listed below

- The value of the RE bit in the SCR is 1

- Reception is not in progress

- There are no received data yet to be read

- The ORER, FER, and PER flags in the SSR are all 0

## [Condition for high-level output]

- Any of the conditions for the low level not being satisfied

## 15.3.5 SCI Initialization (Asynchronous Mode)

Before transmitting and receiving data, start by writing the initial value “00h” to SCR and then continue through the procedure for SCI given in the sample flowchart ( Figure 15.5 ). Whenever the operating mode or transfer format is changed, SCR must be initialized before the change is made.

When the external clock is used in asynchronous mode, ensure that the clock signal is supplied even during initialization. Note that clearing the SCR.RE bit to 0 initializes neither the ORER, FER, and PER flags in SSR nor RDR.

Moreover, note that switching the value of the SCR.TE bit from 1 to 0 or 0 to 1 while the SCR.TIE bit is 1 leads to the generation of a TXI interrupt request.

|Start initialization|Start initialization||[ 1 ] Make I/O port settings to enable input and output functions|
|---|---|---|---|
||||as required for TXDn, RXDn, and SCKn pins.|
|Clear the SCR.TIE, RIE, TE, RE, and||||
|TEIE bits to 0|||[ 2 ] Set the clock selection in SCR.|
||||When the clock output is selected in asynchronous mode,|
||||the clock is output immediately after SCR settings are made.|
|Set the I/O port functions||[ 1 ]||
||||[ 3 ] Set data transmission/reception format in SMR, SCMR, and|
|Set bits CKE[1:0] in SCR||[ 2 ]|SEMR.|
||||[ 4 ] Write a value corresponding to the bit rate to BRR.|
|Set the data transmission/reception format in<br>SMR, SCMR, and SEMR||[ 3 ]|This step is not necessary if an external clock is used.|
||||[ 5 ] Set the SCR.TE or RE bit to 1. Also set the SCR.TIE and|
||||RIE bits.|
|Set a value in BRR||[ 4 ]|Setting the TE and RE bits allows TXDn and RXDn to be|
||||used.|
|Set the SCR.TE or RE bit to 1, and<br>set the SCR.TIE and RIE bits||[ 5 ]||
|<Initialization completion>||||

**Figure 15.5 Sample SCI Initialization Flowchart (Asynchronous Mode)**

## 15.3.6 Serial Data Transmission (Asynchronous Mode)

Figure 15.6 shows an example of the operation for serial transmission in asynchronous mode. In serial transmission, the SCI operates as described below.

1. The SCI transfers data from TDR to TSR when data is written to TDR in the TXI interrupt processing routine. The TXI interrupt request at the beginning of transmission is generated when the TE bit in SCR is set to 1 after the TIE bit in SCR is set to 1 or when these two bits are set to 1 simultaneously by a single instruction.

2. Transmission starts after the CTSE bit in SECR is set to 0 (disabling the CTS function) and a low level on the CTS# pin causes data transfer from TDR to TSR. If the TIE bit in SCR is 1 at this time, a TXI interrupt request is generated. Continuous transmission is obtainable by writing the next data for transmission to TDR in the TXI interrupt processing routine before transmission of the current data for transmission is completed. When TEI interrupt requests are in use, set the SCR.TIE bit to 0 (disabling TXI requests) and the SCR.TEIE bit to 1 (enabling TEI requests) after the last of the data to be transmitted are written to the TDR from the processing routine for TXI requests.

3. Data is sent from the TXDn pin in the following order: start bit, transmit data, parity bit or multi-processor bit (may be omitted depending on the format), and stop bit.

4. The SCI checks for updating of (writing to) TDR at the time of stop bit output.

5. When TDR is updated, setting of the CTSE bit in SECR to 0 (CTS function disabled) or a low level input on the CTSn# pin cause the next transfer of the next data for transmission from TDR to TSR and sending of the stop bit, after which serial transmission of the next frame starts.

6. If TDR is not updated, the TEND flag in SSR is set to 1, the stop bit is sent, and then the mark state is entered in which 1 is output. If the TEIE flag in SCR is 1 at this time, the TEND flag in SSR is set to 1 and a TEI interrupt request is generated.

Figure 15.7 shows a sample flowchart for serial transmission in asynchronous mode.

**==> picture [464 x 207] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start bit Parity bit Stop bit<br>Data<br>1 0 D0 D1 D7 0/1 1 0 D0 D1 D7 0/1 1 0 D0 D1 D7 0/1 1 Idle state<br>(mark state)<br>(TIE = 1)<br>TXI interrupt flag<br>(TIE = 0)<br>SSR.TEND flag<br>TXI interrupt  Data written to  TXI interrupt  Data written to TDR in TXI  TEI interrupt<br>request  TDR in TXI  request  interrupt processing routine request generated<br>generated interrupt  generated (Set the TIE bit to 0 and the<br>processing  TEIE bit to 1 after writing the<br>routine last data)<br>1 frame<br>**----- End of picture text -----**<br>

**Figure 15.6 Example of Operation for Serial Transmission in Asynchronous Mode (from the Middle of Transmission until Transmission Completion) (Example with 8-Bit Data, Parity, One Stop Bit)**

|Initialization|Initialization|[ 1 ]<br>[ 1 ]<br>Initialization:<br>The TXDn automatically becomes the output pin for data<br>being transmitted.<br>After the TE bit in SCR is set to 1, 1 is output for a<br>frame, and transmission is enabled.<br>[ 2 ]<br>Transmit data write to TDR by a TXI interrupt request:<br>When transmit data is transferred from TDR to TSR, a<br>transmit data empty interrupt (TXI) request is generated.<br>Write transmit data to TDR once in the TXI interrupt<br>processing routine.<br>[ 3 ]<br>Serial transmission continuation procedure:<br>To continue serial transmission, write transmit data to<br>TDR once using a TXI interrupt request.<br>Transmit data can also be written to TDR by activating<br>the direct access memory controller.<br>When TEI interrupt requests are in use, set the SCR.TIE<br>bit to 0 and the SCR.TEIE bit to 1 after the last of the<br>data to be transmitted are written to the TDR.<br>[ 4 ]<br>Break output at the end of serial transmission:<br>To output a break in serial transmission, set the general-<br>purpose I/O port function corresponding to the TXDn pin<br>(corresponding to output of the low level), and after<br>switching the TXDn pin to the general-purpose I/O port<br>function, set the TE bit in the SCR to 0.<br>[ 2 ]<br>No<br>No<br>No<br>No<br>[ 4 ]<br>[ 3 ]|
|---|---|---|
|Start data tr<br>TXI in|ansmission<br>Yes<br>terrupt||
|Write transmi|t data to TDR||
|All data|Yes<br>written?||
|Clear TIE bit<br>Set TEIE bit|in SCR to 0<br>in SCR to 1||
|TEI in<br>Break|Yes<br>Yes<br>terrupt<br>output||
|Set the I/O p|ort functions||
||||
|Clear bits TIE, TE, and TEIE<br>in SCR to 0|||
|<End>|||

**Figure 15.7 Example of Serial Transmission Flowchart in Asynchronous Mode**

## 15.3.7 Serial Data Reception (Asynchronous Mode)

Figure 15.8 and Figure 15.9 show examples of the operation for serial data reception in asynchronous mode. In serial data reception, the SCI operates as described below.

1. When the value of the RE bit in SCR becomes 1, the output signal on the RTSn# pin goes to the low level.

2. When the SCI monitors the communications line and detects a start bit, it performs internal synchronization, stores receive data in RSR, and checks the parity bit and stop bit.

3. If an overrun error occurs, the ORER flag in SSR is set to 1. If the RIE bit in SCR is 1 at this time, an ERI interrupt request is generated. Receive data is not transferred to RDR.

4. If a parity error is detected, the PER bit in SSR is set to 1 and receive data is transferred to RDR. If the RIE bit in SCR is 1 at this time, an ERI interrupt request is generated.

5. If a framing error (when the stop bit is 0) is detected, the FER bit in SSR is set to 1 and receive data is transferred to RDR. If the RIE bit in SCR is 1 at this time, an ERI interrupt request is generated.

6. When reception finishes successfully, receive data is transferred to RDR. If the RIE bit in SCR is 1 at this time, an RXI interrupt request is generated. Continuous reception is enabled by reading the receive data transferred to RDR in this RXI interrupt processing routine before reception of the next receive data is completed. Reading out the received data that have been transferred to RDR causes the RTSn# pin to output the low level.

**==> picture [469 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start bit Data Parity  Stop  Start bit Data Parity  Stop<br>1 bit bit bit bit 1<br>0 D0 D1 D7 0/1 1 0 D0 D1 D7 0/1 0 Idle state<br>(mark state)<br>RXI interrupt flag<br>SSR.FER flag<br>RXI interrupt  RDR data read in RXI interrupt<br>request  processing routine ERI interrupt request generated<br>generated by framing error<br>1 frame<br>**----- End of picture text -----**<br>

**Figure 15.8 Example of SCI Operation for Serial Reception in Asynchronous Mode (1) (when RTS Function is not Used) (Example with 8-Bit Data, Parity, One Stop Bit)**

**==> picture [471 x 197] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start bit Data Parity  Stop  Start bit Data Parity  Stop  Start bit Data<br>1 bit bit bit bit 1<br>0 D0 D7 0/1 1 0 D0 D7 0/1 0 Idle state  0 D0<br>(mark state)<br>RXI interrupt flag<br>SSR.FER flag<br>RXI interrupt  RDR data read in RXI interrupt<br>request  processing routine<br>generated ERI interrupt request  Error flag is cleared<br>generated by framing error<br>RTSn# pin<br>1 frame<br>**----- End of picture text -----**<br>

**Figure 15.9 Example of SCI Operation for Serial Reception in Asynchronous Mode (2) (when RTS Function Is Used) (Example with 8-Bit Data, Parity, One Stop Bit)**

Table 15.15 lists the states of the SSR status flags and receive data handling when a receive error is detected. If a receive error is detected, an ERI interrupt request is generated but an RXI interrupt request is not generated. Data reception cannot be resumed while the receive error flag is 1. Accordingly, clear the ORER, FER, and PER bits to 0 before resuming reception. Moreover, be sure to read the RDR during overrun error processing. Figure 15.10 and Figure 15.11 show samples of flowcharts for serial data reception.

**Table 15.15 SSR Status Flags and Receive Data Handling**

||**SSR Status**|**Flag**|||
|---|---|---|---|---|
|**ORER**|**FER**|**PER**|**Receive Data**|**Receive Error Type**|
|1|0|0|Lost|Overrun error|
|0|1|0|Transferred to RDR|Framing error|
|0|0|1|Transferred to RDR|Parity error|
|1|1|0|Lost|Overrun error + framing error|
|1|0|1|Lost|Overrun error + parity error|
|0|1|1|Transferred to RDR|Framing error + parity error|
|1|1|1|Lost|Overrun error + framing error + parity error|

**==> picture [468 x 449] intentionally omitted <==**

**----- Start of picture text -----**<br>
Initialization [ 1 ]<br>[ 1 ] Initialization:<br>Start data reception<br>The RXDn automatically becomes the input pin<br>for data being received.<br>[ 2 ] [ 3 ]  Receive error processing and break<br>Read ORER, PER, and FER flags in SSR [ 2 ] detection:<br>If a receive error occurs, an ERI interrupt is<br>generated. An error is identified by reading the<br>ORER, PER, and FER flags in SSR. After<br>SSR.ORER flag = 1, Yes performing the appropriate error processing, be<br>SSR.PER flag = 1, or<br>sure to clear the ORER, PER, and FER flags to<br>SSR.FER flag = 1 [ 3 ]<br>0. Reception cannot be resumed if any of these<br>No Error processing flags is set to 1. In the case of a framing error, a<br>break can be detected by reading the value of<br>(Continued to next page)<br>the input port corresponding to the RxDn pin.<br>[ 4 ] Read the receive data in RDR once in the RXI<br>interrupt processing routine.<br>No<br>[ 5 ] Serial reception continuation procedure:<br>RXI interrupt<br>To continue serial reception, before the stop bit<br>of the current frame is received, read data from<br>Yes<br>RDR in the RXI interrupt processing routine. The<br>RDR data can also be read by activating the<br>DMAC.<br>Read receive data in RDR [ 4 ]<br>No<br>All data received? [ 5 ]<br>Yes<br>Clear bits RIE and RE in SCR to 0<br><End><br>**----- End of picture text -----**<br>

**Figure 15.10 Example of Serial Reception Flowchart (1) (Asynchronous Mode)**

**==> picture [454 x 592] intentionally omitted <==**

**----- Start of picture text -----**<br>
[ 3 ]<br>Error processing<br>No<br>SSR.ORER flag = 1<br>Yes<br>Overrun error processing* [1] [ 6 ] [ 6 ] Processing in response to an overrun error:<br>Read the RDR. In combination with step [ 7 ], this<br>will make correct reception of the next frame possible.<br>No<br>SSR.FER flag = 1<br>Yes<br>Yes<br>Break?<br>No<br>Framing error processing Clear RE bit in SCR to 0<br>No<br>SSR.PER flag = 1<br>Yes<br>Parity error processing<br>Clear the SSR.ORER, PER,<br>[ 7 ] [ 7 ] Clearing the error flag:<br>and FER flags to 0.<br>Write 0 to the error flag.<br>Read the SSR.ORER, PER, and FER flags. [ 8 ] [ 8 ] Confirming that the error flag is actually clear:<br>Read the error flag to confirm that its value is<br>actually 0.<br><End><br>**----- End of picture text -----**<br>

**Figure 15.11 Example of Serial Reception Flowchart (2) (Asynchronous Mode)**

## 15.4 Multi-Processor Communications Function

Using the multi-processor communication functions enables to transmit and receive data by sharing a communication line between multiple processors by using asynchronous serial communication in which the multi-processor bit is added. In multi-processor communication, a unique ID code is allocated to each receiving station. Serial communication cycles consist of an ID transmission cycle to specify the receiving station and a data transmission cycle to transmit data to the specified receiving station. The multi-processor bit is used to distinguish between the ID transmission cycle and the data transmission cycle. When the multi-processor bit is set to 1, it indicates the ID transmission cycle and when the multiprocessor bit is set to 0, it indicates the data transmission cycle. Figure 15.12 shows an example of communication between processors by using a multi-processor format. First, a transmitting station transmits communication data in which the multi-processor bit set to 1 is added to the ID code of the receiving station. Next, the transmitting station transmits the communication data in which the multi-processor bit set to 0 is added to the transmission data. Upon receiving the communication data in which the multi-processor bit is set to 1, the receiving station compares the received ID with the ID of the receiving station itself and if the two match, receives the communication data that is subsequently transmitted. If the received ID does not match with the ID of the receiving station, the receiving station skips the communication data until again receiving the communication data in which the multi-processor bit is set to 1. For supporting this function, the SCI provides the MPIE bit in SCR. When the MPIE bit in SCR is set to 1, transfer of receive data from the RSR to the RDR, detection of a reception error, and setting the respective status flags ORER and FER in SSR are disabled until reception of data in which the multi-processor bit is set to 1. Upon receiving a reception character in which the multi-processor bit is set to 1, the MPBT bit in SSR is set to 1 and the MPIE bit in SCR is automatically cleared, thus returning to a normal reception operation. During this time, an RXI interrupt is generated if the RIE bit in SCR is set.

When the multi-processor format is specified, specification of the parity bit is disabled. Apart from this, there is no difference from the operation in the normal asynchronous mode. A clock which is used for the multi-processor communication is also the same as the clock used in the normal asynchronous mode.

**==> picture [444 x 245] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transmitting<br>station<br>Communication line<br>Receiving  Receiving  Receiving  Receiving<br>station A station B station C station D<br>(ID = 01) (ID = 02) (ID = 03) (ID = 04)<br>(MPB = 1)<br>Serial data<br>01h AAh<br>(MPB = 1) (MPB = 0)<br>ID transmission cycle =  Data transmission cycle = data<br>specification of a receiving station transmission to the receiving<br>station specified by ID<br>MPB: Multi-processor bit<br>**----- End of picture text -----**<br>

**Figure 15.12 An Example of Communication using the Multi-Processor Format (Example of Transmission of Data AAh to Receiving Station A)**

## 15.4.1 Multi-Processor Serial Data Transmission

Figure 15.13 is a sample flowchart of multi-processor data transmission. In the ID transmission cycle, the ID should be transmitted with the MPBT bit in SSR set to 1. In the data transmission cycle, the data should be transmitted with the MPBT bit set to 0. The other operations are the same as the operations in asynchronous mode.

**==> picture [463 x 553] intentionally omitted <==**

**----- Start of picture text -----**<br>
Initialization<br>[ 1 ] [ 1 ] Initialization:<br>The TXDn automatically becomes the output pin for<br>data being transmitted.<br>Start data transmission After the TE bit in SCR is set to 1, 1 is output for a<br>frame, and transmission is enabled.<br>[ 2 ] TXI interrupt request:<br>No When transmit data is transferred from TDR to TSR,<br>TXI interrupt [ 2 ]<br>a transmit data empty interrupt (TXI) request is<br>generated.<br>Yes Set the MPBT bit in SSR to 0 or 1, and write transmit<br>data to TDR once in the TXI interrupt processing<br>Set MPBT bit in SSR routine.<br>[ 3 ] Serial transmission continuation procedure:<br>Write transmit data to TDR To continue serial transmission, write transmit data to<br>TDR once using a TXI interrupt request.<br>Transmit data can also be written to TDR by<br>No activating the DMAC.<br>All data written? [ 3 ] When TEI interrupt requests are in use, set the<br>SCR.TIE bit to 0 and the SCR.TEIE bit to 1 after the<br>last of the data to be transmitted are written to the<br>Yes<br>TDR.<br> Clear the SCR.TIE bit to 0, and set the<br>SCR.TEIE bit to 1<br>[ 4 ] Break output at the end of serial transmission:<br>To output a break in serial transmission, set the<br>general-purpose I/O port corresponding to the TXDn<br>No pin (corresponding to output of the low level), and<br>TEI interrupt<br>after switching the TXDn pin to the general-purpose<br>I/O port function, set the TE bit in the SCR to 0.<br>Yes<br>No<br>[ 4 ]<br>Break output<br>Yes<br>Set the general-purpose I/O port<br>Clear bits TE, TIE, and TEIE in SCR to 0<br><End><br>**----- End of picture text -----**<br>

**Figure 15.13 Example of Multi-Processor Serial Transmission Flowchart**

## 15.4.2 Multi-Processor Serial Data Reception

Figure 15.15 and Figure 15.16 are sample flowcharts of multi-processor data reception. When the MPIE bit in SCR is set to 1, reading the communication data is skipped until reception of the communication data in which the multiprocessor bit is set to 1. When the communication data in which the multi-processor bit is set to 1 is received, the received data is transferred to RDR. During this time, the RXI interrupt request is generated. The other operations are the same as the operations in asynchronous mode. Figure 15.14 is the example of operation for reception.

**==> picture [468 x 462] intentionally omitted <==**

**----- Start of picture text -----**<br>
Data (ID1) Data (Data1)<br>1 Start bit MPB Stop bit Start bit MPB Stop bit 1<br>0 D0 D1 D7 1 1 0 D0 D1 D7 0 1 Idle state<br>(mark state)<br>MPIE<br>RXI interrupt signal<br>RDR value ID1<br>MPIE = 0 RXI interrupt request  RDR data read in RXI  RXI interrupt request not<br>(multi-processor  interrupt processing  MPIE bit set to 1 again when the received ID  generated. RDR retains<br>interrupt) generated routine the state.<br>does not match the ID of<br>the receiving station itself<br>(a) When the received ID does not match the ID of the receiving station itself<br>Data (ID2) Data (Data2)<br>1 Start bit MPB Stop bit Start bit MPB Stop bit 1<br>0 D0 D1 D7 1 1 0 D0 D1 D7 0 1 Idle state<br>(mark state)<br>MPIE<br>RXI interrupt signal<br>RDR value ID1 ID2 Data2<br>MPIE = 0 RXI interrupt request  RDR data read in RXI  Since the received ID matches  MPIE bit set to 1 again<br>(multi-processor  interrupt processing  the ID of the receiving station<br>interrupt) generated routine itself, reception continued and<br>data received in RXI interrupt<br>processing routine<br>(b) When the received ID matches the ID of the receiving station itself<br>**----- End of picture text -----**<br>

**Figure 15.14 Example of Reception (8-Bit Data/Multi-Processor Bit/One Stop Bit)**

**==> picture [465 x 623] intentionally omitted <==**

**----- Start of picture text -----**<br>
Initialization [ 1 ]<br>[ 1 ] Initialization:<br>The RXDn automatically becomes the input pin for<br>data being received.<br>Start data reception<br>[ 2 ] ID reception cycle:<br>Set the MPIE bit in SCR to 1 and wait for ID<br>Set MPIE bit in SCR to 1. [ 2 ]<br>reception.<br>[ 3 ] SCI status confirmation and reception and<br>No comparison of ID:<br>RXI interrupt? [ 3 ]<br>Read data in RDR at the first RXI interrupt, and<br>compare it with the ID of the receiving station itself.<br>Yes<br>If the ID does not match the ID of the receiving<br>station itself, set the MPIE bit to 1 again, and wait for<br>Read ORER and FER flags in SSR.<br>another RXI interrupt.<br>Yes [ 4 ] Data reception at an RXI interrupt:<br>FER flag = 1 or ORER flag = 1 Read data in RDR once in the RXI interrupt routine.<br>No  [5 ] Receive error processing and break detection:<br>If a receive error occurs, an error is identified by<br>Read receive data in RDR.<br>reading the ORER and FER flags in SSR. After<br>performing the appropriate error processing, be sure<br>to clear the ORER and FER flags to 0. Reception<br>No<br>ID of receiving station itself? cannot be resumed if any of these flags is set to 1.<br>In the case of a framing error, a break can be<br>Yes detected by reading the value of the RXDn pin.<br>No<br>RXI interrupt? [ 4 ]<br>Yes<br>Read ORER and FER flags in SSR.<br>Yes<br>FER flag = 1 or ORER flag = 1<br>No<br>Read receive data in RDR.<br>No<br>All data received? [ 5 ]<br>Error processing<br>Yes<br>(Continued to next page)<br>Clear RE and RIE bits in SCR to 0.<br><End><br>**----- End of picture text -----**<br>

**Figure 15.15 Example of Multi-Processor Serial Reception Flowchart (1)**

**==> picture [438 x 456] intentionally omitted <==**

**----- Start of picture text -----**<br>
[ 5 ]<br>Error processing<br>No<br>SSR.ORER flag = 1<br>Yes<br>Overrun error processing* [1] [ 6 ] [ 6 ] Processing in response to an overrun error:<br>Read the RDR. In combination with step [ 7 ],<br>this will make correct reception of the next frame<br>possible.<br>No<br>SSR.FER flag = 1<br>Yes<br>Yes<br>Break?<br>No<br>Framing error processing Clear RE bit in SCR to 0<br>Clear the SSR.ORER, PER,<br>[ 7 ] [ 7 ] Clearing the error flag:<br>and FER flags to 0.<br>Write 0 to the error flag.<br>Read the SSR.ORER, PER, and FER flags. [ 8 ] [ 8 ] Confirming that the error flag is actually clear:<br>Read the error flag to confirm that its value is<br>actually 0.<br><End><br>**----- End of picture text -----**<br>

**Figure 15.16 Example of Multi-Processor Serial Reception Flowchart (2)**

## 15.5 Operation in Clock Synchronous Mode

Figure 15.17 shows the data format for clock synchronous serial data communications.

In clock synchronous mode, data is transmitted or received in synchronization with clock pulses. One character in transfer data consists of 8-bit data. In clock synchronous mode, no parity bit can be added.

In data transmission, the SCI outputs data from one falling edge of the synchronization clock to the next. In data reception, the SCI receives data in synchronization with the rising edge of the synchronization clock. After 8-bit data is output, the transmission line holds the last bit output state.

Inside the SCI, the transmitter and receiver are independent units, enabling full-duplex communications by use of a common clock. Both the transmitter and the receiver also have a double-buffered structure, so that the next transmit data can be written during transmission or the previous receive data can be read during reception, enabling continuous data transfer.

**==> picture [467 x 146] intentionally omitted <==**

**----- Start of picture text -----**<br>
One unit of transfer data (character or frame)<br>* [1] * [1]<br>Synchronization<br>clock<br>LSB MSB<br>Serial data Bit 0 Bit 1 Bit 2 Bit 3 Bit 4 Bit 5 Bit 6 Bit 7<br>Don’t care Don’t care<br>Note 1.  Holds a high level except during continuous transfer.<br>**----- End of picture text -----**<br>

**Figure 15.17 Data Format in Clock Synchronous Serial Communications (LSB-First)**

## 15.5.1 Clock

Either an internal clock generated by the on-chip baud rate generator or an external synchronization clock input at the SCKn pin can be selected, according to the setting of the CKE[1:0] bits in SCR.

When the SCI is operated on an internal clock, the synchronization clock is output from the SCKn pin. Eight

synchronization clock pulses are output in the transfer of one character, and when no transfer is performed the clock is held high. However, when only data reception is performed, output of the synchronizing clock signal continues until the CTS function is enabled and the high level is input on the CTSn# pin, an overflow error occurs, or the RE bit in SCR is set to 0. When the CTS function is enabled, the synchronous clock signal output is stopped if the CTSn# pin input is high on completion of the frame reception.

## 15.5.2 CTS and RTS Functions

In the CTS function, CTSn# pin input is used to control reception/transmission start when the clock source is the internal clock. Setting the SECR.CTSE bit to 1 enables the CTS function.

When the CTS function is enabled, placing the low level on the CTSn# pin causes reception/transmission to start.

In the RTS function, RTSn# pin output is used to request reception/transmission start when the clock source is an external synchronizing clock. A low level is output when serial communications become possible. Conditions for output of the low and high level are shown below.

[Conditions for low-level output]

Satisfaction of all conditions listed below

- The value of the RE or TE bit in the SCR is 1

- Neither transmission nor reception is in progress

- There are no received data yet to be read (when the SCR.RE bit is 1)

- Transmit data has been written (when the SCR.TE bit is 1)

- ORER flag in SSR is 0

## [Condition for high-level output]

Any of the conditions for the low level not being satisfied

## 15.5.3 Initialization (Clock Synchronous Mode)

Before transmitting and receiving data, start by writing the initial value “00h” to the SCR and then continue through the procedure for SCI given in the sample flowchart ( Figure 15.18 ). Whenever the operating mode or transfer format is changed, the SCR must be initialized before the change is made.

Note that clearing the SCR.RE bit to 0 initializes neither the ORER, FER, and PER flags in SSR nor RDR.

Moreover, note that switching the value of the SCR.TE bit from 1 to 0 or 0 to 1 while the SCR.TIE bit is 1 leads to the generation of a TXI interrupt request.

**==> picture [447 x 301] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start initialization [ 1 ] Make general-purpose I/O port settings to enable<br>input and output functions as required for TXDn,<br>RXDn, and SCKn pins.<br>Clear bits TIE, RIE, TE, RE, and TEIE in<br>SCR to 0<br>[ 2 ] Set the clock selection in SCR.<br>When an internal clock is selected, the SCK pin<br>Set the general-purpose I/O port [ 1 ] functions as the clock output pin.<br>[ 3 ] Set the data transmission/reception format in SMR<br>Set bits CKE[1:0] in SCR [ 2 ]<br>and SCMR.<br>Set data transmission/reception format in  [ 4 ] Write a value corresponding to the bit rate to BRR.<br>[ 3 ]<br>SMR and SCMR This step is not necessary if an external clock is<br>used.<br>Set a value in BRR [ 4 ]<br>[ 5 ] Set the TE bit or RE bit in SCR to 1. Also set the<br>TIE and RIE bits in SCR.<br>Set TE or RE bit in SCR to 1, and set TIE and  Setting the TE and RE bits allows TXDn and RXDn<br>RIE bits in SCR [ 5 ] to be used.<br><Transmission/reception><br>Note: • In simultaneous transmit and receive operations, the TE and RE bits in SCR should both be to 0 or<br>set to 1 simultaneously.<br>**----- End of picture text -----**<br>

**Figure 15.18 Example of Initialization Flowchart (Clock Synchronous Mode)**

## 15.5.4 Serial Data Transmission (Clock Synchronous Mode)

Figure 15.19 shows an example of the operation for serial transmission in clock synchronous mode. In serial data transmission, the SCI operates as described below.

1. The SCI transfers data from TDR to TSR when data is written to TDR in the TXI interrupt processing routine. The TXI interrupt request at the beginning of transmission is generated when the TE bit in SCR is set to 1 after the TIE bit in SCR is set to 1 or when these two bits are set to 1 simultaneously by a single instruction.

2. After transferring data from TDR to TSR, the SCI starts transmission. When the SCR.TIE bit is set to 1 at this time, a TXI interrupt request is generated. Continuous transmission is enabled by writing the next transmit data to TDR in this TXI interrupt processing routine before transmission of the current transmit data has finished. When TEI interrupt requests are in use, set the SCR.TIE bit to 0 (disabling TXI requests) and the SCR.TEIE bit to 1 (enabling TEI requests) after the last of the data to be transmitted are written to the TDR from the processing routine for TXI requests.

3. 8-bit data is sent from the TXDn pin in synchronization with the output clock when clock output mode has been specified and in synchronization with the input clock when use of an external clock has been specified. Output of the clock signal is suspended until the input CTS signal is at the low level while the CTSE bit in SECR is 1 (enabling the CTS function).

4. The SCI checks for updating of (writing to) the TDR at the time of the last bit output.

5. When TDR is updated, the next transmit data is transferred from TDR to TSR, and serial transmission of the next frame is started.

6. If TDR is not updated, set the SSR flag in TEND to 1 and the TXDn pin retains the output state of the last bit. If the TEIE bit in SCR is 1 at this time, a TEI interrupt request is generated. The SCKn pin is held high.

## Figure 15.20 shows a sample flowchart of serial data transmission.

Transmission will not start while a receive error flag (ORER, FER, or PER in SSR) is set to 1. Be sure to clear the receive error flags to 0 before starting transmission. Note that clearing the RE bit in SCR to 0 does not clear the receive error flags.

**==> picture [461 x 216] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronization<br>clock<br>Bit 0 Bit 1 Bit 7 Bit 0 Bit 1 Bit 7 Bit 0 Bit 1 Bit 7<br>Serial data<br>(TIE = 1)<br>TXI interrupt flag<br>(TIE = 0)<br>SSR.TEND flag<br>TXI interrupt  Data written to TDR in  TXI interrupt  Data written to TDR in TXI  TEI interrupt<br>request  TXI interrupt processing  request  interrupt processing routine request<br>generated routine generated (Set the TIE bit to 0 and the  generated<br>TEIE bit to 1 after writing the<br>last data)<br>1 frame<br>**----- End of picture text -----**<br>

**Figure 15.19 Example of Operation for Serial Transmission in Clock Synchronous Mode (from the Middle of Transmission until Transmission Completion)**

**==> picture [455 x 370] intentionally omitted <==**

**----- Start of picture text -----**<br>
Initialization [ 1 ] [ 1 ] Initialization:<br>The TXDn automatically becomes the output pin for<br>data being transmitted.<br>Start transmission<br>[ 2 ] Writing transmit data write to TDR by a TXI interrupt<br>request:<br>No [ 2 ] When transmit data is transferred from TDR to TSR, a<br>TXI interrupt transmit data empty interrupt (TXI) request is<br>generated.<br>Transmit data is written to TDR once from the<br>Yes<br>processing routine for TXI requests.<br>Write transmit data to TDR<br>[ 3 ] Serial transmission continuation procedure:<br>To continue serial transmission, write transmit data to<br>No<br>All data transmitted? [ 3 ] TDR upon accepting a transmit data empty interrupt<br>(TXI). Transmit data can also be written to TDR by<br>activating the DMAC by the TXI interrupt request.<br>Yes<br>         When TEI interrupt requests are in use, set the<br>SCR.TIE bit to 0 and the SCR.TEIE bit to 1 after the<br>Clear the TIE bit in SCR to 0, and<br>set the TEIE bit in SCR to 1 last of the data to be transmitted are written to the<br>TDR.<br>No<br>TEI interrupt<br>Yes<br>Clear bits TIE, TE, and TEIE in SCR to 0<br><End><br>**----- End of picture text -----**<br>

Note: • When the external clock is in use (the value of the SCR.CKE[1:0] bits is 10b or 11b), the rising edge on the SCK pin for the last bit sets the SSR.TEND flag to 1. Clearing the SCR.TE bit to 0 immediately after this may lead to insufficient received-data hold time on the receiver side.

**Figure 15.20 Example of Serial Transmission Flowchart (Clock Synchronous Mode)**

## 15.5.5 Serial Data Reception (Clock Synchronous Mode)

Figure 15.21 and Figure 15.22 show examples of SCI operation for serial reception in clock synchronous mode. In serial data reception, the SCI operates as described below.

1. The value of the RE bit in SCR becoming 1 places the signal output on the RTS pin at the low level (when the RTS function is in use).

2. The SCI performs internal initialization and starts receiving data in synchronization with a synchronization clock input or output, and stores the receive data in RSR.

3. If an overrun error occurs, the ORER bit in SSR is set to 1. If the RIE bit in SCR is 1 at this time, an ERI interrupt request is generated. Receive data is not transferred to RDR.

4. When reception finishes successfully, receive data is transferred to RDR. If the RIE bit in SCR is 1 at this time, an RXI interrupt request is generated. Continuous reception is enabled by reading the receive data transferred to RDR in this RXI interrupt processing routine before reception of the next receive data is completed. Reading out the received data that have been transferred to RDR causes the RTSn# pin to output the low level (when the RTS function is in use).

**==> picture [470 x 198] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronization<br>clock<br>Serial data Bit 7 Bit 0 Bit 7 Bit 0 Bit 1 Bit 6 Bit 7<br>RXI interrupt flag<br>SSR.ORER flag<br>RXI interrupt  RDR data read in RXI  RXI interrupt  ERI interrupt request<br>request  request  generated by overrun error<br>interrupt processing routine<br>generated generated<br>1 frame<br>**----- End of picture text -----**<br>

**Figure 15.21 Example of Operation for Serial Reception in Clock Synchronous Mode (1) (when RTS Function is not Used)**

**==> picture [459 x 234] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronization<br>clock<br>Serial data Bit 7 Bit 0 Bit 6 Bit 7 Bit 0<br>RXI interrupt flag<br>SSR.ORER flag<br>RXI interrupt  RDR data read in RXI  RXI interrupt  RDR data read in RXI<br>request  interrupt processing  request  interrupt processing<br>generated routine generated routine<br>RTSn# pin<br>1 frame<br>**----- End of picture text -----**<br>

**Figure 15.22 Example of Operation for Serial Reception in Clock Synchronous Mode (2) (when RTS Function is Used)**

Data transfer cannot be resumed while a receive error flag is 1. Accordingly, clear the ORER, FER, and PER bits in SSR to 0 before resuming reception. Moreover, be sure to read the RDR during overrun error processing. Figure 15.23 shows a sample flowchart for serial data reception.

**==> picture [466 x 584] intentionally omitted <==**

**----- Start of picture text -----**<br>
Initialization [ 1 ] [ 1 ] Initialization:<br>Make input port-pin settings for pins to be used<br>as RXDn pins.<br>Start data reception<br>[ 2 ] [ 3 ] Receive error processing:<br>If a receive error occurs, read the ORER flag in<br>Read ORER flag in SSR [ 2 ]<br>SSR, perform the relevant error processing, and<br>then clear the ORER flag to 0. Data reception<br>Yes cannot be resumed while the ORER flag is 1.<br>SSR.ORER = 1 [ 3 ]<br>[ 4 ] Read the receive data in RDR once in the<br>No receive data full interrupt (RXI) request<br>Error processing<br>processing routine.<br>(Continued below)<br>[ 5 ] Serial reception continuation procedure:<br>No To continue serial reception, before the MSB (bit<br>RXI interrupt<br>7) of the current frame is received, finish reading<br>the receive data in RDR. The RDR data can also<br>Yes be read by activating the DMAC by an RXI<br>interrupt request.<br>Read receive data in RDR [ 4 ]<br>No<br>All data received? [ 5 ]<br>Yes<br>Clear bits RIE and RE in SCR to 0<br><End><br>[ 3 ] Error processing<br>[ 6 ] Clearing the error flag:<br>Clear the error flag to 0.<br>After writing 0, confirm that the flag is actually<br>Overrun error processing * [1] cleared.<br>Clear the SSR.ORER flag to 0. [ 6 ]<br><End><br>Note1.  Read RDR.<br>**----- End of picture text -----**<br>

**Figure 15.23 Example of Serial Reception Flowchart (Clock Synchronous Mode)**

## 15.5.6 Simultaneous Serial Data Transmission and Reception (Clock Synchronous Mode)

Figure 15.24 shows a sample flowchart for simultaneous serial transmit and receive operations in clock synchronous mode.

After initializing the SCI, the following procedure should be used for simultaneous serial data transmit and receive operations.

To switch from transmit mode to simultaneous transmit and receive mode, check that the SCI has finished transmission by reading that the TEND flag in SSR is 1, and then initialize the SCR register. Then set the TIE, RIE, TE, and RE bits in SCR to 1 simultaneously by a single instruction.

To switch from receive mode to simultaneous transmit and receive mode, check that the SCI has finished reception, and then clear the RIE and RE bits to 0. Then check that the receive error flags (ORER, FER, and PER in SSR) are 0, and then set the TIE, RIE, TE, and RE bits in SCR to 1 simultaneously by a single instruction.

**==> picture [424 x 425] intentionally omitted <==**

**----- Start of picture text -----**<br>
Initialization [ 1 ] [ 1 ] Initialization:<br>The TXDn pin can act as the output pin for<br>transmitted data and the RXDn pin can act as<br>Start data transmission/reception the input pin for received data at the same time.<br>[ 2 ] Transmit data write:<br>Write transmit data to TDR once in the TXI<br>No<br>TXI interrupt interrupt request processing routine.<br>Yes [ 3 ] Receive error processing:<br>If a receive error occurs, read the ORER flag in<br>Write transmit data to TDR [ 2 ]<br>SSR, perform the relevant error processing, and<br>then clear the ORER flag to 0. Data reception<br>cannot be resumed while the ORER flag is 1.<br>Read ORER flag in SSR<br>[ 4 ] Reading receive data:<br>Read the receive data in RDR once in the RXI<br>SSR.ORER = 1 Yes interrupt request processing routine.<br>[ 3 ]<br>No Error processing [ 5 ] Serial transmission/reception continuation<br>procedure:<br>No To continue serial transmission and reception,<br>RXI interrupt<br>before the MSB (bit 7) of the current frame is<br>received, finish reading the receive data in RDR<br>Yes<br>by the RXI interrupt. Also, before the MSB (bit<br>Read receive data in RDR [ 4 ] 7) of the current frame is transmitted, write data<br>to TDR by the TXI interrupt.<br>Transmit data can also be written to TDR by<br>No activating the DMAC by a transmit data empty<br>All data received? [ 5 ] interrupt (TXI) request. Similarly, the RDR data<br>can also be read by activating the DMAC by a<br>Yes<br>receive data full interrupt (RXI) request.<br>Clear TIE, RIE, TE, RE, and TEIE<br>bits in SCR to 0<br><End><br>**----- End of picture text -----**<br>

Note: • When switching from transmit or receive operation to simultaneous transmit and receive operations, first clear the TIE, RIE, TE, RE, and TEIE bits in SCR to 0, and then set TIE, RIE, TE, and RE bits to 1 simultaneously.

**Figure 15.24 Example of Simultaneous Serial Transmission and Reception Flowchart (Clock Synchronous Mode)**

## 15.6 Operation in Smart Card Interface Mode

The SCI supports the smart card (IC card) interface conforming to the ISO/IEC 7816-3 (Identification Card) standard. Smart card interface mode can be selected using the appropriate register.

## 15.6.1 Sample Connection

Figure 15.25 shows a sample connection between a smart card (IC card) and this LSI.

As in the figure, since this LSI communicates with an IC card using a single transmission line, interconnect the TXDn and RXDn pins and pull up the data transmission line to Vcc using a resistor.

Setting the TE and RE bits in SCR to 1 with an IC card disconnected enables closed transmission/reception allowing self-diagnosis.

To supply an IC card with the clock pulses generated by the SCI, input the SCKn pin output to the CLK pin of an IC card. The output port of this LSI can be used to output a reset signal.

**==> picture [342 x 143] intentionally omitted <==**

**----- Start of picture text -----**<br>
VCC<br>TXDn<br>I/O<br>RXDn Data line<br>SCKn CLK<br>Clock line<br>Port RST<br>Reset line<br>This LSI IC card<br>Main unit of the device to<br>be connected<br>**----- End of picture text -----**<br>

**Figure 15.25 Sample Connection with a Smart Card (IC Card)**

## 15.6.2 Data Format (Except in Block Transfer Mode)

Figure 15.26 shows the data transfer formats in smart card interface mode.

- One frame consists of 8-bit data and a parity bit in asynchronous mode.

- During transmission, at least 2 etu (elementary time unit: time required for transferring one bit) is secured as a guard time from the end of the parity bit until the start of the next frame.

- If a parity error is detected during reception, a low-level error signal is output for 1 etu after 10.5 etu has passed from the start bit.

- If an error signal is sampled during transmission, the same data is automatically re-transmitted after at least 2 etu.

**==> picture [420 x 277] intentionally omitted <==**

**----- Start of picture text -----**<br>
In normal transmission/reception<br>Ds D0 D1 D2 D3 D4 D5 D6 D7 Dp<br>Output from the transmitting station<br>When a parity error occurs<br>Ds D0 D1 D2 D3 D4 D5 D6 D7 Dp DE<br>Output from the transmitting station<br>Output from the<br>receiving station<br>Ds: Start bit<br>D0 to D7: Data bits<br>Dp: Parity bit<br>DE: Error signal<br>**----- End of picture text -----**<br>

**Figure 15.26 Data Formats in Smart Card Interface Mode**

For communications with IC cards of the direct convention type and inverse convention type, follow the procedure below.

## (1) Direct Convention Type

For the direct convention type, logic levels 1 and 0 correspond to states Z and A, respectively, and data is transferred with LSB-first as the start character, as shown in Figure 15.27 . Therefore, data in the start character in the figure is 3Bh. When using the direct convention type, write 0 to both the SDIR and SINV bits in SCMR. Write 0 to the PM bit in SMR in order to use even parity, which is prescribed by the smart card standard.

**==> picture [280 x 46] intentionally omitted <==**

**----- Start of picture text -----**<br>
(Z) A Z Z A Z Z Z A A Z (Z) state<br>Ds D0 D1 D2 D3 D4 D5 D6 D7 Dp<br>**----- End of picture text -----**<br>

**Figure 15.27 Direct Convention (SDIR in SCMR = 0, SINV in SCMR = 0, PM in SMR = 0)**

## (2) Inverse Convention Type

For the inverse convention type, logic levels 1 and 0 correspond to states A and Z, respectively and data is transferred with MSB-first as the start character, as shown in Figure 15.28 . Therefore, data in the start character in the figure is 3Fh. When using the inverse convention type, write 1 to both the SDIR and SINV bits in SCMR. The parity bit is logic level 0 to produce even parity, which is prescribed by the smart card standard, and corresponds to state Z. Since the SCMR.SINV bit of this LSI only inverts data bits D7 to D0, write 1 to the PM bit in SMR to invert the parity bit for both transmission and reception.

**==> picture [281 x 47] intentionally omitted <==**

**----- Start of picture text -----**<br>
(Z) A Z Z A A A A A A Z (Z) state<br>Ds D7 D6 D5 D4 D3 D2 D1 D0 Dp<br>**----- End of picture text -----**<br>

**Figure 15.28 Inverse Convention (SDIR in SCMR = 1, SINV in SCMR = 1, PM in SMR = 1)**

## 15.6.3 Block Transfer Mode

Block transfer mode is different from normal smart card interface mode in the following respects.

- Even if a parity error is detected during reception, no error signal is output. Since the PER bit in SSR is set by error detection, clear the PER bit before receiving the parity bit of the next frame.

- During transmission, at least 1 etu is secured as a guard time from the end of the parity bit until the start of the next frame.

- Since the same data is not re-transmitted during transmission, the TEND flag in SSR is set 11.5 etu after transmission start.

- In block transfer mode, the ERS flag in SSR indicates the error signal status as in normal smart card interface mode, but the flag is always read as 0 because no error signal is transferred.

## 15.6.4 Receive Data Sampling Timing and Reception Margin

Only the internal clock generated by the on-chip baud rate generator can be used as a transfer clock in smart card interface mode.

In this mode, the SCI can operate on a base clock with a frequency of 32, 64, 372, 256, 93, 128, 186, or 512 times the bit rate according to the settings of the BCP2 bit in SCMR and the BCP[1:0] bits in SMR (the frequency is always 16 times the bit rate in normal asynchronous mode).

For data reception, the falling edge of the start bit is sampled with the base clock to perform internal synchronization. Receive data is sampled on the 16th, 32nd, 186th, 128th, 46th, 64th, 93rd, and 256th rising edges of the base clock so that it can be latched at the middle of each bit as shown in Figure 15.29 . The reception margin here is determined by the following formula.

**==> picture [244 x 27] intentionally omitted <==**

- M: Reception margin (%)

- N: Ratio of bit rate to clock (N = 32, 64, 372, 256)

- D: Duty cycle of clock (D = 0 to 1.0)

- L: Frame length (L = 10)

- F: Absolute value of clock frequency deviation

Assuming values of F = 0, D = 0.5, and N = 372 in the above formula, the reception margin is determined by the formula below.

M = {0.5 - 1/(2 × 372)}  100 [%] = 49.866%

**==> picture [456 x 241] intentionally omitted <==**

**----- Start of picture text -----**<br>
372 clock cycles 372 clock cycles<br>186 clock cycles 186 clock cycles<br>0 185 371 0 185 371 0<br>Internal base clock<br>Start bit<br>Receive data (RXDn) D0 D1<br>Synchronization sampling<br>timing<br>Data sampling timing<br>**----- End of picture text -----**<br>

**Figure 15.29 Receive Data Sampling Timing in Smart Card Interface Mode (When Clock Frequency is 372 Times the Bit Rate)**

## 15.6.5 Initialization (Smart Card Interface Mode)

Before transmitting and receiving data, initialize the SCI using the following procedure. Initialization is also necessary before switching from transmission to reception and vice versa.

1. Write the initial value “00h” to the SCR.

2. Make general-purpose I/O port settings to enable input and output functions as required for TXDn, RXDn, and SCKn pins.

3. Set the error flags ORER, ERS, and PER in SSR to 0.

4. Set bits GM, BLK, PM, BCP[1:0], and CKS[1:0] in SMR and the BCP2 bit in SCMR appropriately. Also set the PE bit in SMR to 1.

5. Set bits SDIR, SINV, and SMIF in SCMR appropriately. Then, the TXDn and RXDn pins are placed in the high impedance state.

6. Set the value corresponding to the bit rate in BRR.

7. Set the CKE[1:0] bits in SCR appropriately, and set bits TIE, RIE, TE, RE, and TEIE in SCR to 0 at the same time. When the CKE[1:0] bit in SCR is set to 1, the SCKn pin is allowed to output clock pulses.

8. Set the TIE, RIE, TE, and RE bits in SCR to 1. Setting the TE and RE bits to 1 simultaneously is prohibited except for self-diagnosis.

To change reception mode to transmission mode, first check that reception has completed, and then initialize the SCI. At the end of initialization, set SCR.TE = 1 and SCR.RE = 0. Reception completion can be verified by reading the RXI request, ORER, or PER flag in SSR.

To change transmission mode to reception mode, first check that transmission has completed, and then initialize the SCI. At the end of initialization, set SCR.TE = 0 and SCR.RE = 1. Transmission completion can be verified by reading the TEND flag in SSR.

## 15.6.6 Serial Data Transmission (Except in Block Transfer Mode)

Serial data transmission in smart card interface mode (except in block transfer mode), in that an error signal is sampled and data can be re-transmitted, is different from that in normal serial communications interface mode. Figure 15.30 shows the data retransfer operation during transmission.

1. When an error signal from the receiver end is sampled after one-frame data has been transmitted, the ERS flag in SSR is set to 1. If the RIE bit in SCR is 1 at this time, an ERI interrupt request is generated. Clear the ERS flag in SSR to 0 before the next parity bit is sampled.

2. For a frame in which an error signal is received, the TEND flag in SSR is not set. Data is retransferred from TDR to TSR allowing automatic data retransmission.

3. If no error signal is returned from the receiver, the ERS flag in SSR is not set to 1.

4. In this case, the SCI judges that transmission of one-frame data (including retransfer) has been completed, and the TEND flag is set. If the TIE bit in SCR is 1 at this time, a TXI interrupt request is generated. Writing transmit data to TDR starts transmission of the next data.

Figure 15.32 shows a sample flowchart of serial transmission. All the processing steps are automatically performed using a TXI interrupt request to activate the DMAC.

When the TEND flag in SSR is set to 1 in transmission, if the TIE bit in SCR is 1, a TXI interrupt request is generated. The DMAC is activated by a TXI interrupt request if the TXI interrupt request is specified as a source of DMAC activation beforehand, allowing transfer of transmit data. The TEND flag in SSR is automatically cleared to 0 when the DMAC transfers the data.

If an error occurs, the SCI automatically re-transmits the same data. During this retransmission, the TEND flag in SSR  is kept to 0 and the DMAC is not activated. Therefore, the SCI and DMAC automatically transmit the specified number of bytes, including retransmission in the case of error occurrence. However, since the ERS flag in SSR is not automatically cleared, set the RIE bit in SCR to 1 beforehand to enable an ERI interrupt request to be generated at error occurrence, and clear the ERS flag in SSR to 0.

When transmitting/receiving data using the DMAC, be sure to make settings to enable the DMAC before making SCI settings.

For DMAC settings, see section 9, Direct Memory Access Controller .

**==> picture [470 x 122] intentionally omitted <==**

**----- Start of picture text -----**<br>
(n + 1)-th transfer<br>n-th transfer frame Retransfer frame frame<br>(DE)<br>Ds D0 D1 D2 D3 D4 D5 D6 D7 Dp DE Ds D0 D1 D2 D3 D4 D5 D6 D7 Dp Ds D0 D1 D2 D3 D4<br>TXI interrupt signal<br>[2] [4]<br>SSR.FER flag/<br>SSR.ERS flag<br>[1] [3]<br>**----- End of picture text -----**<br>

**Figure 15.30 Data Retransfer Operation in Transmission Mode**

Note that the SSR.TEND flag is set in different timings depending on the GM bit setting in SMR. Figure 15.31 shows the SSR.TEND flag generation timing.

**==> picture [448 x 206] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ds D0 D1 D2 D3 D4 D5 D6 D7 Dp DE<br>SSR.TEND flag Guard<br>(TXI interrupt) time<br>12.5 etu (11.5 etu in block transfer mode)<br>When GM bit in SMR = 0<br>11.0 etu<br>When GM bit in SMR = 1<br>Ds:  Start bit<br>D0 to D7:  Data bits<br>Dp:  Parity bit<br>DE:  Error signal<br>**----- End of picture text -----**<br>

**Figure 15.31 SSR.TEND Flag Generation Timing during Transmission**

**==> picture [348 x 470] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Initialization<br>Start data transmission<br>No<br>SSR.ERS flag = 0?<br>Yes<br>Error processing<br>No<br>TXI interrupt<br>Yes<br>Write transmit data to TDR<br>No<br>Write all transmit data<br>Yes<br>No<br>SSR.ERS flag = 0?<br>Yes<br>Error processing<br>No<br>TXI interrupt<br>Yes<br>Clear bits TIE, RIE, and TE<br>in SCR to 0<br>End<br>**----- End of picture text -----**<br>

**Figure 15.32 Sample Smart Card Interface Transmission Flowchart**

## 15.6.7 Serial Data Reception (Except in Block Transfer Mode)

Serial data reception in smart card interface mode is similar to that in serial communications interface mode. Figure 15.33 shows the data retransfer operation in reception mode.

1. If a parity error is detected in receive data, the PER flag in SSR is set to 1. When the RIE bit in SCR is 1 at this time, an ERI interrupt request is generated. Clear the PER flag in SSR to 0 before the next parity bit is sampled.

2. For a frame in which a parity error is detected, no RXI interrupt is generated.

3. When no parity error is detected, the PER flag in SSR is not set to 1.

4. In this case, data is determined to have been received successfully. When the RIE bit in SCR is 1, an RXI interrupt request is generated.

Figure 15.34 shows a sample flowchart for serial data reception. All the processing steps are automatically performed using an RXI interrupt request to activate the DMAC.

In reception, setting the RIE bit in SCR to 1 allows an RXI interrupt request to be generated. The DMAC is activated by an RXI interrupt request if the RXI interrupt request is specified as a source of DMAC activation beforehand, allowing transfer of receive data.

If an error occurs during reception and either the ORER or PER flag in SSR is set to 1, a receive error interrupt (ERI) request is generated. Clear the error flag after the error occurrence. If an error occurs, the DMAC is not activated and receive data is skipped. Therefore, the number of bytes of receive data specified in the DMAC is transferred. Even if a parity error occurs and the PER flag in SSR is set to 1 during reception, receive data is transferred to RDR, thus allowing the data to be read.

Note 1. For operations in block transfer mode, see section 15.3, Operation in Asynchronous Mode.

**==> picture [468 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
(n + 1)-th transfer<br>n-th transfer frame Retransfer frame frame<br>Ds D0 D1 D2 D3 D4 D5 D6 D7 Dp DE Ds D0 D1 D2 D3 D4 D5 D6 D7 Dp Ds D0 D1 D2 D3 D4<br>RXI interrupt signal<br>[2] [4]<br>SSR.PER flag<br>[1] [3]<br>**----- End of picture text -----**<br>

**Figure 15.33 Data Retransfer Operation in Reception Mode**

**==> picture [367 x 356] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Initialization<br>Start data reception<br>SSR.ORER = 0 and  No<br>SSR.PER = 0?<br>Yes<br>Error processing<br>No<br>RXI interrupt<br>Yes<br>Read data from RDR<br>No<br>All data received?<br>Yes<br>Clear bits RIE and RE<br>in SCR to 0<br>**----- End of picture text -----**<br>

**Figure 15.34 Sample Smart Card Interface Reception Flowchart**

## 15.6.8 Clock Output Control

Clock output can be fixed using the CKE[1:0] bits in SCR when the GM bit in SMR is 1. Specifically, the minimum width of a clock pulse can be specified.

Figure 15.35 shows an example of clock output fixing timing when the CKE0 bit is controlled with SMR.GM = 1 and SCR.CKE1 = 0.

**==> picture [423 x 106] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCR.CKE0 bit<br>SCKn<br>Given pulse width Given pulse width<br>**----- End of picture text -----**<br>

**Figure 15.35 Clock Output Fixing Timing**

At power-on and transitions to/from software standby mode, use the following procedure to secure the appropriate clock duty cycle.

## (1) At Power-On

To secure the appropriate clock duty cycle simultaneously with power-on, use the following procedure.

1. Initially, port input is enabled in the high-impedance state. To fix the potential level, use a pull-up or pull-down resistor.

2. Fix the SCKn pin to the specified output by setting the SCR.CKE[1] bit and general-purpose I/O port.

3. Set SMR and SCMR to enable smart card interface mode.

4. Set the SCR.CKE[0] bit to 1 to start clock output.

## (2) At Mode Switching

## (a) At transition from smart card interface mode to software standby mode

1. Set low power consumption mode to make the SCKn pin fixed with a desired output value in software standby mode.

2. Write 0 to the TE and RE bits in SCR to stop transmission/reception.

   - Simultaneously, set the SCR.CKE[1] bit to the value for the output fixed state in software standby mode.

3. Write 0 to the SCR.CKE[0] bit to stop the clock.

4. Wait for one cycle of the serial clock. In the mean time, the clock output is fixed to the specified level with the duty cycle retained.

5. After switching the SCKn pin to the general-purpose I/O port function, make a transition to software standby mode.

## (b) Return from software standby mode to smart card interface mode

6. Cancel software standby mode.

7. Set the SCR.CKE[0] bit to 1 to start clock output. A clock signal with the appropriate duty cycle is then generated.

**==> picture [400 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
Software<br>Normal operation standby mode Normal operation<br>SCKn<br>[1] [2] [3] [4] [5] [6] [7]<br>**----- End of picture text -----**<br>

**Figure 15.36 Clock Stop and Restart Procedure**

## 15.7 Noise Cancellation Function

Figure 15.37 shows the configuration of the noise filter used for noise cancellation. The noise filter consists of two stages of flip-flop circuits and a match-detection circuit. When the level on the pin matches in three consecutive samples taken at the set sampling interval, the matching level continues to be conveyed internally until the level on the pin again matches in three consecutive samples.

In asynchronous mode, the noise cancellation function can be applied on the RXDn input signal. The period of the base clock (1/16th of a bit-period when SEMR.ABCS = 0 and 1/8th of a bit-period when SEMR.ABCS = 1) is the sampling interval.

If the base clock is stopped with the noise filter enabled and then the clock input is started again, the noise filter operation resumes from where the clock was stopped. If SCR.TE and SCR.RE are set to 0 during base clock input, all of the noise filter flip-flop values are initialized to 1. Accordingly, if the input data is 1 when reception operation resumes, it is determined that a level match is detected and is conveyed to the internal signal. When the level being input corresponds to 0, the initial output of the noise filter is retained until the level matches in three consecutive samples.

**==> picture [453 x 236] intentionally omitted <==**

**----- Start of picture text -----**<br>
RXDn<br>internal signal<br>Not match<br>Match D Q<br>Com- CLK<br>parator<br>RXDn<br>D Q D Q<br>input signal<br>CLK CLK<br>Base clock for<br>asynchronous mode<br>Bit NFEN<br>**----- End of picture text -----**<br>

**Figure 15.37 Block Diagram of Digital Noise Filter Circuit**

## 15.8 Interrupt Sources

## 15.8.1 Interrupts in Serial Communications Interface Mode

Table 15.16 lists interrupt sources in serial communication interface mode. Individual interrupt sources can be enabled or disabled with the enable bits in SCR.

If the SCR.TIE bit is 1, a TXI interrupt request is generated when data for transmission are transferred from the TDR to the TSR. A TXI interrupt request can also be generated by setting the SCR.TE bit to 1 after setting the SCR.TIE bit to 1 or by using a single instruction to set the SCR.TE and SCR.TIE bit to 1 at the same time. A TXI interrupt request can activate the DMAC to handle data transfer.

A TXI interrupt request is not generated by setting the SCR.TE bit to 1 while the setting of the SCR.TIE bit is 0 or by setting the SCR.TIE bit to 1 while the setting of the SCR.TE bit is 1. *[1]

When new data are not written by the time of transmission of the last bit of the current data for transmission and the setting of the SCR.TEIE bit is 1, the SSR.TEND flag becomes 1 and a TEI interrupt request is generated. Furthermore, when the setting of the SCR.TE bit is 1, the SSR.TEND flag retains the value 1 until further data for transmission are written to the TDR, and setting the SCR.TEIE bit to 1 leads to the generation of a TEI interrupt request.

Writing data to the TDR leads to clearing of the SSR.TEND flag and, after a certain time, discarding of the TEI interrupt request.

If the SCR.RIE bit is 1, an RXI interrupt request is generated when received data are stored in the RDR. An RXI interrupt request can activate the DMAC to handle data transfer.

Setting of any from among the ORER, FER, and PER flags in the SSR to 1 while the SCR.RIE bit is 1 leads to the generation of an ERI interrupt request. An RXI interrupt request is not generated at this time. Clearing all three flags (ORER, FER, and PER) leads to discarding of the ERI interrupt request.

- Note 1. To temporarily prohibit TXI interrupts at the time of transmission of the last of the data and so on when you wish a new round of transmission to start after handling of the transmission-completed interrupt, control prohibiting and permitting of the interrupt by using the interrupt request enable bit in the interrupt controller rather than using the SCR.TIE bit. This can prevent the suppression of TXI interrupt requests in the transfer of new data.

**Table 15.16 Interrupt Sources**

|**Table 15.16**|**Interrupt Sources**|||
|---|---|---|---|
|**Name**|**Interrupt Source**|**Interrupt Flag**|**DMAC Activation**|
|ERI|Receive error|ORER, FER, or PER|Not possible|
|RXI|Receive data full|—|Possible|
|TXI|Transmit data empty|—|Possible|
|TEI|Transmit end|TEND|Not possible|

## 15.8.2 Interrupts in Smart Card Interface Mode

Table 15.17 lists interrupt sources in smart card interface mode. A transmit end interrupt (TEI) request cannot be used in this mode.

## **Table 15.17 Interrupt Sources**

|**Table 15.17**|**Interrupt Sources**|||
|---|---|---|---|
|**Name**|**Interrupt Source**|**Interrupt Flag**|**DMAC Activation**|
|ERI|Receive error or error signal detection|ORER, PER, or ERS|Not possible|
|RXI|Receive data full|—|Possible|
|TXI|Transmit data empty|TEND|Possible|

Data transmission/reception using the DMAC is also possible in smart card interface mode. In transmission, when the TEND flag in SSR is set to 1, a TXI interrupt request is generated. This TXI interrupt request activates the DMAC allowing transfer of transmit data if the TXI request is specified beforehand as a source of DMAC activation. The TEND flag in SSR is automatically cleared to 0 when the DMAC transfers the data.

If an error occurs, the SCI automatically re-transmits the same data. During the retransmission, the TEND flag in SSR is kept to 0 and the DMAC is not activated. Therefore, the SCI and DMAC automatically transmit the specified number of bytes, including retransmission in the case of error occurrence. However, the ERS flag in SSR is not automatically cleared to 0 at error occurrence. Therefore, the ERS flag in SSR must be cleared by previously setting the RIE bit in SCR to 1 to enable an ERI interrupt request to be generated at error occurrence.

When transmitting/receiving data using the DMAC, be sure to make settings to enable the DMAC before making SCI settings. For DMAC settings, see section 9, Direct Memory Access Controller .

In reception, an RXI interrupt request is generated when receive data is set to RDR. This RXI interrupt request activates the DMAC allowing transfer of receive data if the RXI request is specified beforehand as a source of DMAC activation. If an error occurs, the error flag is set. Therefore, the DMAC is not activated and an ERI interrupt request is issued to the CPU instead; the error flag must be cleared.

## 15.9 Usage Notes

## 15.9.1 Setting the Module Standby Function

SCI operation can be started and stopped by setting the module standby mode. With the value after a reset, SCI operations are stopped. The registers of the modules only become accessible after release from the module standby state. For details, refer to section 42, Power-Down Modes .

## 15.9.2 Break Detection and Processing

When a framing error is detected, a break can be detected by reading the RXDn pin value directly. In a break, the input from the RXDn pin becomes all 0s, and so the FER flag in SSR is set to 1 (framing error), and the PER flag in SSR may also be set to 1 (parity error). The SCI continues the receive operation even after a break is received. Therefore, note that even if the FER flag in SSR is cleared to 0 (no framing error), it will be set to 1 again.

## 15.9.3 The Mark State and Production of Breaks

When the SCR.TE bit is 0 (prohibiting serial transmission), setting the general-purpose I/O port makes selection of the level and direction (input or output) of the TXDn pin possible. If this is done, the TXDn pin can be placed in the mark state to send a break at the time of data transmission. Until the SCR.TE bit is set to 1 (permitting serial transmission), the general-purpose I/O port is used to set the TXDn pin to output 1 and set the pin mode to a general-purpose I/O port pin, and thus place the transfer circuit in the mark state (state of having the value 1). On the other hand, to output a break at the time of data transmission, set the TXDn pin to output 0 and make the pin mode settings for a general-purpose I/O port pin. When the SCR.TE bit is set to 0, the transmission section is initialized regardless of the current state of transmission.

## 15.9.4 Receive Error Flags and Transmit Operations (Clock Synchronous Mode Only)

Transmission cannot be started when a receive error flag (ORER) in SSR is set to 1, even if data is written to TDR. Be sure to clear the receive error flags to 0 before starting transmission. Note also that the receive error flags cannot be cleared to 0 even if the RE bit in SCR is cleared to 0 (serial reception disabled).

## 15.9.5 Writing Data to TDR

Data can always be written to TDR. However, if new data is written to TDR when transmit data is remaining in TDR, the previous data in TDR is lost because it has not been transferred to TSR yet. Be sure to write transmit data to TDR in the TXI interrupt request processing routine.

## 15.9.6 Restrictions on Clock Synchronous Transmission

When the external clock source is used as a synchronization clock, update TDR by the DMAC and wait for at least five P1  clock cycles before allowing the transmit clock to be input. If the transmit clock is input within four clock cycles after TDR is updated, the SCI may malfunction.

## 15.9.7 Restrictions on Using DMAC

When using the DMAC to read RDR, be sure to set the receive end interrupt (RXI) as the activation source of the relevant channel.

## 15.9.8 Points to Note on Starting Transfer

On the generation of an interrupt request for the interrupt controller at the point where transfer starts, follow the procedure below to clear interrupt requests before permitting operations (by setting the SCR.TE or SCR.RE bit to 1).

- Confirm that transfer has stopped (the setting of the SCR.TE or SCR.RE bits is 0).

- Set the corresponding interrupt enable bit (SCR.TIE or SCR.RIE) to 0.

- Read out the corresponding interrupt enable bit (SCR.TIE or SCR.RIE bit) to check that it has actually become 0.

- Clear the interrupt status flag in the interrupt controller to 0.

## 15.9.9 SCI Operations during Low Power Consumption State

## (1) Transmission

When making settings for the module standby state or in transitions to software standby, stop operations (by setting the TIE, TE, and TEIE bits in the SCR to 0) after switching the TXDn pin to the general-purpose I/O port pin function. Clearing the TE bit in SCR to 0 resets the TSR and the TEND bit in the SSR. The states of the output pins in the software standby mode depend on the settings for the power-down modes. When transitions to these states are made during transmission, the data being transmitted become indeterminate.

To transmit data in the same transmission mode after cancellation of the low power consumption state, set the TE bit in SCR to 1, read SSR, and write data to TDR sequentially to start data transmission. To transmit data with a different transmission mode, initialize the SCI first.

Figure 15.38 shows a sample flowchart for transition to software standby mode during transmission.

## (2) Reception

Before specifying the module standby state or making a transition to software standby mode, stop the receive operations (RE = 0 in SCR). If transition is made during data reception, the data being received will be invalid.

To receive data in the same reception mode after cancellation of the low power consumption state, set the RE bit in SCR to 1, and then start reception. To receive data in a different reception mode, initialize the SCI first.

Figure 15.39 shows a sample flowchart for transition to software standby mode during reception.

**==> picture [452 x 453] intentionally omitted <==**

**----- Start of picture text -----**<br>
<Data transmission><br>No [ 1 ] [ 1 ] Data being transmitted is lost halfway. Data can be<br>All data transmitted?<br>normally transmitted from the CPU by setting the TE<br>bit in SCR to 1, reading SSR, and writing data to<br>Yes TDR after canceling software standby mode.<br>However, if the DMAC has been activated, the data<br>Read TEND flag in SSR remaining in the DMAC will be transmitted when both<br>the TE and TIE bits in SCR are set to 1.<br>SSR.TEND = 1 No [ 2 ] Clear the TIE and TEIE bits in the SCR if they are<br>currently set to 1.<br>Yes [ 3 ] This includes the setting for the module standby<br>state.<br>SCR.TE bit = 0 [ 2 ]<br>Make transition to software standby mode [ 3 ]<br>Cancel software standby mode<br>No<br>Change operating mode?<br>Yes<br>Initialization<br>SCR.TE = 1<br><Start data transmission><br>**----- End of picture text -----**<br>

**Figure 15.38 Example of Flowchart for Transition to Software Standby Mode during Transmission**

**==> picture [408 x 395] intentionally omitted <==**

**----- Start of picture text -----**<br>
<Data reception><br>No [ 1 ] [ 1 ] Data being received is invalid.<br>RXI interrupt<br>Yes<br>Read receive data in RDR<br>SCR.RE = 0<br>Make transition to software standby mode [ 2 ] [ 2 ] Setting for the module standby state is<br>included.<br>Cancel software standby mode<br>No<br>Change operating mode?<br>Yes<br>Initialization SCR.RE = 1<br><Start data reception><br>**----- End of picture text -----**<br>

**Figure 15.39 Example of Flowchart for Transition to Software Standby Mode during Reception**

## 15.9.10 External Clock Input in Clock Synchronous Mode

In clock synchronous mode, the external clock SCKn must be input as follows:

High-pulse period, low-pulse period = 2 P1  clock cycles or more, period = 6 P1  clock cycles or more

## 15.10 IrDA Communications

In combination with the on-chip IrDA module, the channel 0 serial communications interface (SCI) transmits and receives waveforms conforming with version 1.0 of the Infrared Data Association (IrDA) standard.

When the IrDA function is enabled by the IRE bit in the IRCR register, the SCI_TXD0 and SCI_RXD0 signals transmitted and received on channel 0 are encoded to and decoded from waveforms conforming with the standard. Connecting these signals to an infrared transceiver enables infrared transmission and reception conforming with the standard.

The standard allows starting communications at a transfer rate of 9600 bps and changing the rate as required. The IrDA module does not have the function of automatically changing the transfer rate. To change the transfer rate of IrDA communications, change the transfer rate of the SCI.

Figure 15.40 shows the block diagram. Table 15.18 shows the pin configuration of the IrDA.

**==> picture [443 x 182] intentionally omitted <==**

**----- Start of picture text -----**<br>
IrDA SCI ch0<br>IRE = 0<br>SCI_TXD0 TXD<br>Phase inversion Pulse encoder<br>IRE = 1<br>IRE = 1<br>SCI_RXD0 Phase inversion Pulse decoder RXD<br>IRE = 0<br>IRCR<br>Internal data bus<br>**----- End of picture text -----**<br>

**Figure 15.40 Block Diagram**

**Table 15.18 Pin Configuration**

|**Name**|**Pin Name**|**I/O**|**Description**|
|---|---|---|---|
|IrDA transmit data pin|SCI_TXD0|O|IrDA transmit data output|
|IrDA receive data pin|SCI_RXD0|I|IrDA receive data input|

## 15.11 IrDA Register Description

Table 15.19 shows the register configuration.

## **Table 15.19 Register Configuration**

|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|IrDA control register|IRCR|R/W|H’00|H'E8014000|8|

## 15.11.1 IrDA Control Register (IRCR)

IRCR is the register which sets the operation of the IrDA module.

|Bit:<br>Initial value:<br>R/W:|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>IRE<br>IRCKS[2:0]<br>IRTXINV IRRXINV<br>—<br>—<br> <br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br><br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R|
|---|---|
|**Bit**|**Bit Name**<br>**Initial Value**<br>**R/W**<br>**Description**|
|7|IRE<br>0<br>R/W<br>IrDA Enable<br>Sets whether the SCI_TXD0 and SCI_RXD0 pins have normal serial function<br>or IrDA function.<br>0: IrDA function is disabled<br>(The TXD signal transmitted on channel 0 is directly output to the<br>SCI_TXD0 pin)<br>The RXD signal received on channel 0 is directly input to the SCI_RXD0<br>pin)<br>1: IrDA function is enabled<br>(The TXD signal transmitted on channel 0 is output to the SCI_TXD0 pin<br>after encoded)<br>The RXD signal received on channel 0 is input to the SCI_RXD0 pin after<br>decoded)|
|6 to 4|IRCKS[2:0]<br>000<br>R/W<br>IrDA Clock Select<br>Sets the pulse width when the SCI_TXD0 output pulse is encoded with the<br>IRE bit set to 1.<br>000: B3/16 (B = bit rate)<br>001: P1/2<br>010: P1/4<br>011: P1/8<br>100: P1/16<br>101: P1/32<br>110: P1/64<br>111: P1/128|
|3|IRTXINV<br>0<br>R/W<br>SCI_TXD0 Data Sense Switch<br>Sets whether or not to invert the logic levels for SCI_TXD0 output.<br>0: Data for transmission are directly output to SCI_TXD0.<br>The pulse width set by the IRCKS bits is the width at the high level.<br>1: Data for transmission are output to SCI_TXD0 after inversion.<br>The pulse width set by the IRCKS bits is the width at the low level.|
|2|IRRXINV<br>0<br>R/W<br>SCI_RXD0 Data Sense Switch<br>Sets whether or not to invert the logic levels of SCI_RXD0 input.<br>0: SCI_RXD0 input is directly used as receive data.<br>1: SCI_RXD0 input is used as receive data after inversion.|
|1, 0|—<br>All 0<br>R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|

## 15.12 IrDA Operation

## 15.12.1 Flow of IrDA Setting

To set the operation of the IrDA module, follow the procedure below.

1. Make the general-purpose I/O port settings.

2. Set the IRCR register.

3. Set the relevant registers of the SCI.

## 15.12.2 Transmission

In transmission with the IrDA function enabled, serial data from the TXD pin for the SCI (UART frame data) are converted to IR frames (see Figure 15.41 ). When the IRTXINV bit is 0 and the value of the serial data is 0, a high-level pulse is output to the SCI_TXD0 pin for three sixteenths of one-bit period (initial value). The width of the high-level pulse can be changed by the IRCKS[2:0] bits in the IRCR register. The IrDA standard stipulates that the high-level pulse width is at least 1.41  s and no greater than ((3/16 + 2.5%)  bit rate) or ((3/16  bit rate) + 1.08)  s. When P1  is 66.67 MHz, the width of the high-level pulse can be set from 1.41  s to 1.92  s. When the value of a bit of the serial data is 1, no pulse is output.

**==> picture [391 x 228] intentionally omitted <==**

**----- Start of picture text -----**<br>
UART frame<br>Start bit Data Stop bit<br>0         1        0         1         0        0         1         1        0         1<br>Transmission<br>Reception<br>IR frame<br>Start bit Data Stop bit<br>0     1            0     1            0         0     1         1            0     1<br>Bit   The pulse width is from 1.41 μs to (3/16 of bit cycle + 1.08) μs.<br>cycle<br>**----- End of picture text -----**<br>

**Figure 15.41 Example of IrDA Transmission and Reception**

## 15.12.3 Reception

In reception with the IRDA function enabled, IR frame data from the SCI_RXD0 pin are converted to serial data and output to the RXD pin for the SCI. When the IRRXINV bit is 0, a bit with the value 0 is output on the detection of a highlevel pulse. When no pulse is received during one-bit period, a bit with the value 1 is output. Pulses shorter than the lower limit (1.41  s) are not recognized.

## 15.12.4 Selection of High-Level Pulse Width

Table 15.20 shows the correspondence between the applicable IRCKS[2:0] bit setting (shortest pulse width), operating frequency P1  , and bit rate when the pulse width is shortened below (bit rate  3/16) in transmission.

**Table 15.20 IRCKS[2:0] Bit Setting**

|**Table 15.20**|**IRCKS[2:0] Bit Setting**|
|---|---|
|**P1****(MHz)**|**Bit Rate (bps) (Upper Row) / Bit Cycle****3/16 (****s) (Lower Row)**|
||**2400**<br>**9600**<br>**19200**<br>**38400**<br>**57600**<br>**115200**|
||**78.13**<br>**19.53**<br>**9.77**<br>**4.88**<br>**3.26**<br>**1.63**|
|50|111<br>111<br>111<br>111<br>111<br>—*1|
|64|111<br>111<br>111<br>111<br>111<br>—*2|
|66.67|111<br>111<br>111<br>111<br>111<br>—*2|

Note 1. The bit rate cannot be set at the SCI.

Note 2. A pulse width shorter than (bit rate  3/16) cannot be set.

## 15.13 Notes on Using the IrDA Module

## 15.13.1 Shortest Pulse Width in Reception

Pulses shorter than the lower limit (1.41  s) are not recognized.

## 15.13.2 Asynchronous Basic Clock for Serial Communication Interface

The IrDA module receives the basic clock with a frequency which is 16 times as high as the communication bit rate from the SCI and operates in combination with the clock. Although one-bit period of the SCI can be set to 16 or 8 clock cycles, the IrDA module supports the SCI that one-bit period is set to 16 clock cycles.
