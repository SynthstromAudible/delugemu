# 14. Serial Communication Interface with FIFO

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 571–620. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI has a five-channel serial communication interface with FIFO that supports both asynchronous and clock synchronous serial communication. It also has 16-stage FIFO registers for both transmission and reception independently for each channel that enable this LSI to perform efficient high-speed continuous communication.

## 14.1 Features

- Asynchronous serial communication:

   - Serial data communication is performed by start-stop in character units. This module can communicate with a universal asynchronous receiver/transmitter (UART), an asynchronous communication interface adapter (ACIA), or any other communications chip that employs a standard asynchronous serial system. There are eight selectable serial data communication formats.

   - Data length: 7 or 8 bits

   - Stop bit length: 1 or 2 bits

   - Parity: Even, odd, or none

   - Receive error detection: Parity, framing, and overrun errors

   - Break detection: Break is detected when a framing error is followed by at least one frame at the space 0 level (low level). It is also detected by reading the RxD pin level directly from the serial port register when a framing error occurs.

- Clock synchronous serial communication:

   - Serial data communication is synchronized with a clock signal. This module can communicate with other chips having a clock synchronous communication function. There is one serial data communication format.

   - Data length: 8 bits

   - Receive error detection: Overrun errors

- Full duplex communication: The transmitting and receiving sections are independent, so this module can transmit and receive simultaneously. Both sections use 16-stage FIFO buffering, so high-speed continuous data transfer is possible in both the transmit and receive directions.

- On-chip baud rate generator with selectable bit rates

- Internal or external transmit/receive clock source: From either baud rate generator (internal) or SCK pin (external)

- Four types of interrupts: Transmit-FIFO-data-empty interrupt, break interrupt, receive-FIFO-data-full interrupt, and receive-error interrupt are requested independently.

- When this module is not in use, it can be stopped by halting the clock supplied to it, saving power.

- In asynchronous mode, on-chip modem control functions (RTS and CTS) (only channels 0, 1, and 2).

- The quantity of data in the transmit and receive FIFO data registers and the number of receive errors of the receive data in the receive FIFO data register can be ascertained.

- A time-out error (DR) can be detected when receiving in asynchronous mode.

- In asynchronous mode, the base clock frequency can be either 16 or 8 times the bit rate.

- When an internal clock is selected as a clock source and the SCK pin is used as an input pin in asynchronous mode, either normal mode or double-speed mode can be selected for the baud rate generator.

Figure 14.1 shows a block diagram. However, certain channels do not have the CTS and RTS pins.

**==> picture [395 x 302] intentionally omitted <==**

**----- Start of picture text -----**<br>
Module data bus<br>Peripheral<br>bus<br>SCFRDR (16 stages) SCFTDR (16 stages) SCSMR SCBRR<br>SCLSR SCEMR<br>SCFDR<br>SCFCR<br>Baud rate P1φ<br>RxD SCRSR SCTSR SCFSR generator<br>P1φ/4<br>SCSCR<br>P1φ/16<br>SCSPTR<br>P1φ/64<br>Transmission/reception<br>TxD control<br>Parity generation Clock<br>Parity check<br>External clock<br>SCK<br>TXI<br>CTS RXI<br>ERI<br>RTS BRI<br>Serial communication interface with FIFO<br>[Legend]<br>SCRSR: Receive shift register SCFSR: Serial status register<br>SCFRDR: Receive FIFO data register SCBRR: Bit rate register<br>SCTSR: Transmit shift register SCSPTR:Serial port register<br>SCFTDR: Transmit FIFO data register SCFCR: FIFO control register<br>SCSMR: Serial mode register SCFDR: FIFO data count set register<br>SCSCR: Serial control register SCLSR: Line status register<br>SCEMR: Serial extension mode register<br>Bus interface<br>**----- End of picture text -----**<br>

**Figure 14.1 Block Diagram**

## 14.2 Input/Output Pins

Table 14.1 shows the pin configuration.

## **Table 14.1 Pin Configuration**

|**Channel**|**Pin Name**|**Symbol**<br>**I/O**<br>**Function**|**Symbol**<br>**I/O**<br>**Function**|**Symbol**<br>**I/O**<br>**Function**|
|---|---|---|---|---|
|0 to 4|Serial clock pins|SCK0 to SCK4<br>I/O<br>Clock I/O|||
||Receive data pins|RxD0 to RxD4<br>Input<br>Receive data input|||
||Transmit data pins|TxD0 to TxD4<br>Output<br>Transmit data output|||
|0, 1, 2|Request to send pin|RTS0<br>,|RTS1<br>,|RTS<br>2<br>I/O<br>Request to send|
||Clear to send pin|CTS0<br>,|CTS1<br>,|CTS2<br>I/O<br>Clear to send|

## 14.3 Register Descriptions

## This module has the following registers. **Table 14.2 Register Configuration**

|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|---|---|
|0|Serial mode register_0<br>SCSMR_0<br>R/W<br>H'0000<br>H'E8007000<br>16|
||Bit rate register_0<br>SCBRR_0<br>R/W<br>H'FF<br>H'E8007004<br>8|
||Serial control register_0<br>SCSCR_0<br>R/W<br>H'0000<br>H'E8007008<br>16|
||Transmit FIFO data register_0<br>SCFTDR_0<br>W<br>Undefined<br>H'E800700C<br>8|
||Serial status register_0<br>SCFSR_0<br>R/(W)*1<br>H'0060<br>H'E8007010<br>16|
||Receive FIFO data register_0<br>SCFRDR_0<br>R<br>Undefined<br>H'E8007014<br>8|
||FIFO control register_0<br>SCFCR_0<br>R/W<br>H'0000<br>H'E8007018<br>16|
||FIFO data count set register_0<br>SCFDR_0<br>R<br>H'0000<br>H'E800701C<br>16|
||Serial port register_0<br>SCSPTR_0<br>R/W<br>H'0050<br>H'E8007020<br>16|
||Line status register_0<br>SCLSR_0<br>R/(W)*2<br>H'0000<br>H'E8007024<br>16|
||Serial extension mode register_0<br>SCEMR_0<br>R/W<br>H'0000<br>H'E8007028<br>16|
|1|Serial mode register_1<br>SCSMR_1<br>R/W<br>H'0000<br>H'E8007800<br>16|
||Bit rate register_1<br>SCBRR_1<br>R/W<br>H'FF<br>H'E8007804<br>8|
||Serial control register_1<br>SCSCR_1<br>R/W<br>H'0000<br>H'E8007808<br>16|
||Transmit FIFO data register_1<br>SCFTDR_1<br>W<br>Undefined<br>H'E800780C<br>8|
||Serial status register_1<br>SCFSR_1<br>R/(W)*1<br>H'0060<br>H'E8007810<br>16|
||Receive FIFO data register_1<br>SCFRDR_1<br>R<br>Undefined<br>H'E8007814<br>8|
||FIFO control register_1<br>SCFCR_1<br>R/W<br>H'0000<br>H'E8007818<br>16|
||FIFO data count set register_1<br>SCFDR_1<br>R<br>H'0000<br>H'E800781C<br>16|
||Serial port register_1<br>SCSPTR_1<br>R/W<br>H'0050<br>H'E8007820<br>16|
||Line status register_1<br>SCLSR_1<br>R/(W)*2<br>H'0000<br>H'E8007824<br>16|
||Serial extension mode register_1<br>SCEMR_1<br>R/W<br>H’0000<br>H'E8007828<br>16|
|2|Serial mode register_2<br>SCSMR_2<br>R/W<br>H'0000<br>H’E8008000<br>16|
||Bit rate register_2<br>SCBRR_2<br>R/W<br>H'FF<br>H’E8008004<br>8|
||Serial control register_2<br>SCSCR_2<br>R/W<br>H'0000<br>H’E8008008<br>16|
||Transmit FIFO data register_2<br>SCFTDR_2<br>W<br>Undefined<br>H’E800800C<br>8|
||Serial status register_2<br>SCFSR_2<br>R/(W)*1<br>H'0060<br>H’E8008010<br>16|
||Receive FIFO data register_2<br>SCFRDR_2<br>R<br>Undefined<br>H’E8008014<br>8|
||FIFO control register_2<br>SCFCR_2<br>R/W<br>H'0000<br>H’E8008018<br>16|
||FIFO data count set register_2<br>SCFDR_2<br>R<br>H'0000<br>H’E800801C<br>16|
||Serial port register_2<br>SCSPTR_2<br>R/W<br>H'0050<br>H’E8008020<br>16|
||Line status register_2<br>SCLSR_2<br>R/(W)*2<br>H'0000<br>H’E8008024<br>16|
||Serial extension mode register_2<br>SCEMR_2<br>R/W<br>H'0000<br>H’E8008028<br>16|
|3|Serial mode register_3<br>SCSMR_3<br>R/W<br>H'0000<br>H’E8008800<br>16|
||Bit rate register_3<br>SCBRR_3<br>R/W<br>H'FF<br>H’E8008804<br>8|
||Serial control register_3<br>SCSCR_3<br>R/W<br>H'0000<br>H’E8008808<br>16|
||Transmit FIFO data register_3<br>SCFTDR_3<br>W<br>Undefined<br>H’E800880C<br>8|
||Serial status register_3<br>SCFSR_3<br>R/(W)*1<br>H'0060<br>H’E8008810<br>16|
||Receive FIFO data register_3<br>SCFRDR_3<br>R<br>Undefined<br>H’E8008814<br>8|
||FIFO control register_3<br>SCFCR_3<br>R/W<br>H'0000<br>H’E8008818<br>16|
||FIFO data count set register_3<br>SCFDR_3<br>R<br>H'0000<br>H’E800881C<br>16|
||Serial port register_3<br>SCSPTR_3<br>R/W<br>H'0050<br>H’E8008820<br>16|
||Line status register_3<br>SCLSR_3<br>R/(W)*2<br>H'0000<br>H’E8008824<br>16|
||Serial extension mode register_3<br>SCEMR_3<br>R/W<br>H'0000<br>H’E8008828<br>16|

|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|---|---|
|4|Serial mode register_4<br>SCSMR_4<br>R/W<br>H'0000<br>H’E8009000<br>16|
||Bit rate register_4<br>SCBRR_4<br>R/W<br>H'FF<br>H’E8009004<br>8|
||Serial control register_4<br>SCSCR_4<br>R/W<br>H'0000<br>H’E8009008<br>16|
||Transmit FIFO data register_4<br>SCFTDR_4<br>W<br>Undefined<br>H’E800900C<br>8|
||Serial status register_4<br>SCFSR_4<br>R/(W)*1<br>H'0060<br>H’E8009010<br>16|
||Receive FIFO data register_4<br>SCFRDR_4<br>R<br>Undefined<br>H’E8009014<br>8|
||FIFO control register_4<br>SCFCR_4<br>R/W<br>H'0000<br>H’E8009018<br>16|
||FIFO data count set register_4<br>SCFDR_4<br>R<br>H'0000<br>H’E800901C<br>16|
||Serial port register_4<br>SCSPTR_4<br>R/W<br>H'0050<br>H’E8009020<br>16|
||Line status register_4<br>SCLSR_4<br>R/(W)*2<br>H'0000<br>H’E8009024<br>16|
||Serial extension mode register_4<br>SCEMR_4<br>R/W<br>H'0000<br>H’E8009028<br>16|

Note 1. Only 0 can be written to clear the flag. Bits 15 to 8, 3, and 2 are read-only bits that cannot be modified. Note 2. Only 0 can be written to clear the flag. Bits 15 to 1 are read-only bits that cannot be modified.

## 14.3.1 Receive Shift Register (SCRSR)

SCRSR receives serial data. Data input at the RxD pin is loaded into SCRSR in the order received, LSB (bit 0) first, being converted to parallel form. When one byte has been received, it is automatically transferred to the receive FIFO data register (SCFRDR).

The CPU cannot read from or write to SCRSR directly.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||||||||||
|Initial value:|-|-|-|-|-|-|-|-|
|R/W:|-|-|-|-|-|-|-|-|

## 14.3.2 Receive FIFO Data Register (SCFRDR)

SCFRDR is a 16-stage FIFO register that stores serial receive data. The reception of one byte of serial data is complete when the received data is moved from the receive shift register (SCRSR) to SCFRDR for storage. Continuous reception is possible until 16 bytes are stored. The CPU can read but not write to SCFRDR. If data is read when there is no receive data in the SCFRDR, the value is undefined.

When SCFRDR is full of receive data, subsequent serial data is lost.

**==> picture [226 x 43] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 7 6 5 4 3 2 1 0<br>Initial value: - - - - - - - -<br>R/W: R R R R R R R R<br>**----- End of picture text -----**<br>

## 14.3.3 Transmit Shift Register (SCTSR)

SCTSR transmits serial data. Transmit data is loaded from the transmit FIFO data register (SCFTDR) into SCTSR, then the data is transmitted serially from the TxD pin, LSB (bit 0) first. After one data byte has been transmitted, the next transmit data is automatically loaded from SCFTDR into SCTSR and transmission is started again.

The CPU cannot read from or write to SCTSR directly.

**==> picture [226 x 44] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 7 6 5 4 3 2 1 0<br>Initial value: - - - - - - - -<br>R/W: - - - - - - - -<br>**----- End of picture text -----**<br>

## 14.3.4 Transmit FIFO Data Register (SCFTDR)

SCFTDR is a 16-stage FIFO register that stores data for serial transmission. When the transmit shift register (SCTSR) empty is detected, transmit data written in the SCFTDR is moved to SCTSR and serial transmission is started. Continuous serial transmission is performed until there is no transmit data left in SCFTDR. The CPU can write to SCFTDR at all times.

When SCFTDR is full of transmit data (16 bytes), no more data can be written. If writing of next data is attempted, the data is ignored.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||||||||||
|Initial value:|-|-|-|-|-|-|-|-|
|R/W:|W|W|W|W|W|W|W|W|

## 14.3.5 Serial Mode Register (SCSMR)

SCSMR specifies the serial communication format and selects the clock source for the baud rate generator.

The CPU can always read from and write to SCSMR.

|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|C/A|CHR|PE|O/E|STOP|-|CKS[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to|8|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|7|||C/A|0|R/W|Communication Mode|
|||||||Selects operating mode from asynchronous and clock synchronous modes.|
|||||||0: Asynchronous mode|
|||||||1: Clock synchronous mode|
|6|||CHR|0|R/W|Character Length|
|||||||Selects 7-bit or 8-bit data length in asynchronous mode. In the clock|
|||||||synchronous mode, the data length is always 8 bits, regardless of the CHR|
|||||||setting.|
|||||||0: 8-bit data|
|||||||1: 7-bit data*|
|||||||Note: * When 7-bit data is selected, the MSB (bit 7) of the transmit FIFO data|
|||||||register is not transmitted.|
|5|||PE|0|R/W|Parity Enable|
|||||||Selects whether to add a parity bit to transmit data and to check the parity of|
|||||||receive data, in asynchronous mode. In clock synchronous mode, a parity bit is|
|||||||neither added nor checked, regardless of the PE setting.|
|||||||0: Parity bit not added or checked|
|||||||1: Parity bit added and checked*|
|||||||Note: * When PE is set to 1, an even or odd parity bit is added to transmit data,|
|||||||depending on the parity mode (O/E) setting. Receive data parity is|
|||||||checked according to the even/odd (O/E) mode setting.|
|4|||O/E|0|R/W|Parity Mode|
|||||||Selects even or odd parity when parity bits are added and checked. The O/E|
|||||||setting is used only in asynchronous mode and only when the parity enable bit|
|||||||(PE) is set to 1 to enable parity addition and checking. The O/E<br>setting is ignored|
|||||||in clock synchronous mode or in asynchronous mode when parity addition and|
|||||||checking is disabled.|
|||||||0: Even parity*1|
|||||||1: Odd parity*2|
|||||||Note: 1. If even parity is selected, the parity bit is added to transmit data to make|
|||||||an even number of 1s in the transmitted character and parity bit|
|||||||combined. Receive data is checked to see if it has an even number of|
|||||||1s in the received character and parity bit combined.|
|||||||2. If odd parity is selected, the parity bit is added to transmit data to|
|||||||make an odd number of 1s in the transmitted character and parity|
|||||||bit combined. Receive data is checked to see if it has an odd|
|||||||number of 1s in the received character and parity bit combined.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|3|STOP|0|R/W|Stop Bit Length|
|||||Selects one or two bits as the stop bit length in asynchronous mode. This setting|
|||||is used only in asynchronous mode. It is ignored in clock synchronous mode|
|||||because no stop bits are added.|
|||||When receiving, only the first stop bit is checked, regardless of the STOP bit|
|||||setting. If the second stop bit is 1, it is treated as a stop bit, but if the second stop|
|||||bit is 0, it is treated as the start bit of the next incoming character.|
|||||0: One stop bit|
|||||When transmitting, a single 1-bit is added at the end of each transmitted|
|||||character.|
|||||1: Two stop bits|
|||||When transmitting, two 1 bits are added at the end of each transmitted|
|||||character.|
|2|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|1, 0|CKS[1:0]|00|R/W|Clock Select|
|||||Select the internal clock source of the on-chip baud rate generator. For further|
|||||information on the clock source, bit rate register settings, and baud rate, see|
|||||section 14.3.8, Bit Rate Register (SCBRR).|
|||||00: P1|
|||||01: P1/4|
|||||10: P1/16|
|||||11: P1/64|
|||||Note: P1: Peripheral clock|

## 14.3.6 Serial Control Register (SCSCR)

SCSCR enables/disables the transmitter/receiver operation and interrupt requests, and selects the transmit/receive clock source. The CPU can always read and write to SCSCR.

||||Bit:|15|14|13|12||11|10<br>9|8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|-|-||-|-<br>-|-<br>TIE<br>RIE<br>TE<br>RE<br>REIE<br>-<br>CKE[1:0]||
||||Initial value:|0|0|0|0||0|0<br>0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:|R|R|R|R||R|R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R/W<br>R/W|||
||||||**Initial**||||||||
|**Bit**|||**Bit Name**||**Value**||**R/W**|||**Description**|||
|15|to|8|—||All|0|R|||Reserved|||
|||||||||||These bits are always read as 0. The write value should always be 0.|||
|7|||TIE||0||R/W|||Transmit|Interrupt Enable||
|||||||||||Enables|or disables the transmit-FIFO-data-empty interrupt (TXI) requested||
|||||||||||when the serial transmit data is transferred from the transmit FIFO data register|||
|||||||||||(SCFTDR) to the transmit shift register (SCTSR), the quantity of data in the|||
|||||||||||transmit FIFO register becomes less than the specified number of transmission|||
|||||||||||triggers,|and then the TDFE flag in the serial status register (SCFSR) is set to 1.||
|||||||||||0: Transmit-FIFO-data-empty interrupt request (TXI) is disabled|||
|||||||||||1: Transmit-FIFO-data-empty interrupt request (TXI) is enabled*|||
|||||||||||Note: *|The TXI interrupt request can be cleared by writing a greater quantity of||
||||||||||||transmit data than the specified transmission trigger number to||
||||||||||||SCFTDR and clearing TDFE to 0 after reading 1 from TDFE, or by||
||||||||||||clearing TIE to 0.||
|6|||RIE||0||R/W|||Receive|Interrupt Enable||
|||||||||||Enables|or disables the receive FIFO data full (RXI) interrupts requested when||
|||||||||||the RDF|flag or DR flag in serial status register (SCFSR) is set to 1, receive-||
|||||||||||error (ERI) interrupts requested when the ER flag in SCFSR is set to 1, and|||
|||||||||||break (BRI) interrupts requested when the BRK flag in SCFSR or the ORER flag|||
|||||||||||in line status register (SCLSR) is set to 1.|||
|||||||||||0: Receive FIFO data full interrupt (RXI), receive-error interrupt (ERI), and break|||
|||||||||||interrupt (BRI) requests are disabled|||
|||||||||||1: Receive FIFO data full interrupt (RXI), receive-error interrupt (ERI), and break|||
|||||||||||interrupt (BRI) requests are enabled*|||
|||||||||||Note: *|RXI interrupt requests can be cleared by reading the DR or RDF flag||
||||||||||||after it has been set to 1, then clearing the flag to 0, or by clearing RIE||
||||||||||||to 0. ERI or BRI interrupt requests can be cleared by reading the ER,||
||||||||||||BRK or ORER flag after it has been set to 1, then clearing the|flag to 0,|
||||||||||||or by clearing RIE and REIE to 0.||
|5|||TE||0||R/W|||Transmit|Enable||
|||||||||||Enables|or disables serial transmission.||
|||||||||||0: Serial|transmission disabled||
|||||||||||1: Serial|transmission enabled*||
|||||||||||Note: *|When this bit is set to 1, serial transmission starts after writing of||
||||||||||||transmit data into SCFTDR. Be sure to select the transmit format in||
||||||||||||SCSMR and SCFCR and reset the transmit FIFO before setting TE to||
||||||||||||1.||
|4|||RE||0||R/W|||Receive|Enable||
|||||||||||Enables|or disables serial reception.||
|||||||||||0: Serial|reception disabled*1||
|||||||||||1: Serial|reception enabled*2||
|||||||||||Notes: 1. Clearing RE to 0 does not affect the receive flags (DR, ER, BRK,|||
||||||||||||RDF, FER, PER, and ORER). These flags retain their previous||
||||||||||||values.||
|||||||||||2. When this bit is set to 1, serial reception starts when a start bit is|||
||||||||||||detected in asynchronous mode, or synchronous clock is||
||||||||||||detected in clock synchronous mode. Be sure to select the||
||||||||||||receive format in SCSMR and SCFCR and reset the receive||
||||||||||||FIFO before setting RE to 1.||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|3|REIE|0|R/W|Receive Error Interrupt Enable|
|||||Enables or disables the receive-error (ERI) interrupts and break (BRI) interrupts.|
|||||The setting of REIE bit is valid only when RIE bit is set to 0.|
|||||0: Receive-error interrupt (ERI) and break interrupt (BRI) requests are disabled|
|||||1: Receive-error interrupt (ERI) and break interrupt (BRI) requests are enabled*|
|||||Note: * ERI or BRI interrupt requests can be cleared by reading the ER, BRK or|
|||||ORER flag after it has been set to 1, then clearing the flag to 0, or by|
|||||clearing RIE and REIE to 0. Even if RIE is set to 0, when REIE is set to|
|||||1, ERI or BRI interrupt requests are enabled.|
|2|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|1, 0|CKE[1:0]|00|R/W|Clock Enable|
|||||Select the clock source and enable or disable clock output from the SCK pin.|
|||||Depending on CKE[1:0], the SCK pin can be used for serial clock output or serial|
|||||clock input. If synchronous clock output is set in clock synchronous mode, set|
|||||the C/A<br>bit in SCSMR to 1, and then set CKE[1:0].|
|||||Asynchronous mode|
|||||00: Internal clock, SCK pin used for input (input signal is ignored)|
|||||01: Internal clock, SCK pin used for clock output|
|||||(The output clock frequency is either 16 or 8 times the bit rate.)|
|||||10: External clock, SCK pin used for clock input|
|||||(The input clock frequency is either 16 or 8 times the bit rate.)|
|||||11: Setting prohibited|
|||||Clock synchronous mode|
|||||00: Internal clock, SCK pin used for synchronous clock output|
|||||01: Internal clock, SCK pin used for synchronous  clock output|
|||||10: External clock, SCK pin used for synchronous  clock input|
|||||11: Setting prohibited|

## 14.3.7 Serial Status Register (SCFSR)

SCFSR is a 16-bit register. The upper 8 bits indicate the number of receive errors in the receive FIFO data register, and the lower 8 bits indicate the status flag indicating operating state.

The CPU can always read from and write to SCFSR, but cannot write 1 to the status flags (ER, TEND, TDFE, BRK, RDF, and DR). These flags can be cleared to 0 only if they have first been read (after being set to 1). The PER flag (bits 15 to 12 and bit 2) and the FER flag (bits 11 to 8 and bit 3) are read-only bits that cannot be written.

|Bit:|15|14|13|12|11|10<br>9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PER[3:0]||||FER[3:0]||ER|TEND|TDFE|BRK|FER|PER|RDF|DR|
|Initial value:|0|0|0|0|0|0<br>0|0|0|1|1|0|0|0|0|0|
|R/W:|R|R|R|R|R|R<br>R|R|R/(W)*|R/(W)*|R/(W)*|R/(W)*|R|R|R/(W)*|R/(W)*|
|Note:<br>*|Only 0 can be||written to clear||the flag|after 1 is read.||||||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 12|PER[3:0]|0000|R|Number of Parity Errors|
|||||Indicate the quantity of data including a parity error in the receive data stored in|
|||||the receive FIFO data register (SCFRDR). The value indicated by bits 15 to 12|
|||||after the ER bit in SCFSR is set, represents the number of parity errors in|
|||||SCFRDR. When parity errors have occurred in all 16-byte receive data in|
|||||SCFRDR, PER[3:0] shows 0000.|
|11 to 8|FER[3:0]|0000|R|Number of Framing Errors|
|||||Indicate the quantity of data including a framing error in the receive data stored|
|||||in SCFRDR. The value indicated by bits 11 to 8 after the ER bit in SCFSR is set,|
|||||represents the number of framing errors in SCFRDR. When framing errors have|
|||||occurred in all 16-byte receive data in SCFRDR, FER[3:0] shows 0000.|
|7|ER|0|R/(W)*|Receive Error|
|||||Indicates the occurrence of a framing error, or of a parity error when receiving|
|||||data that includes parity.*1|
|||||0: Receiving is in progress or has ended normally|
|||||[Clearing conditions]|
|||||ER is cleared to 0 by a power-on reset|
|||||ER is cleared to 0 when 0 is written to after 1 is read from ER|
|||||1: A framing error or parity error has occurred.|
|||||[Setting conditions]|
|||||ER is set to 1 when the stop bit is 0 after checking whether or not the last stop|
|||||bit of the received data is 1 at the end of one data receive operation*2|
|||||ER is set to 1 when the total number of 1s in the receive data plus parity bit|
|||||does not match the even/odd parity specified by the O/Ebit in SCSMR|
|||||Note: 1. Clearing the RE bit to 0 in SCSCR does not affect the ER bit, which|
|||||retains its previous value. Even if a receive error occurs, the receive|
|||||data is transferred to SCFRDR and the receive operation is continued.|
|||||Whether or not the data read from SCFRDR includes a receive error|
|||||can be detected by the FER and PER bits in SCFSR.|
|||||2. In two stop bits mode, only the first stop bit is checked; the second|
|||||stop bit is not checked.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|6|TEND|1|R/(W)*|Transmit End|
|||||Indicates that when the last bit of a serial character was transmitted, SCFTDR|
|||||did not contain valid data, so transmission has ended.|
|||||0: Transmission is in progress|
|||||[Clearing condition]|
|||||TEND is cleared to 0 when 0 is written after 1 is read from TEND after transmit|
|||||data is written in SCFTDR*1|
|||||1: End of transmission|
|||||[Setting conditions]|
|||||TEND is set to 1 by a power-on reset|
|||||TEND is set to 1 when TE is cleared to 0 in the serial control register (SCSCR)|
|||||TEND is set to 1 when SCFTDR does not contain transmit data when the last|
|||||bit of a one-byte serial character is transmitted|
|||||Note: 1. Do not use this bit as a transmit end flag when the direct memory|
|||||access controller writes data to SCFTDR due to a TXI interrupt request.|
|5|TDFE|1|R/(W)*|Transmit FIFO Data Empty|
|||||Indicates that data has been transferred from the transmit FIFO data register|
|||||(SCFTDR) to the transmit shift register (SCTSR), the quantity of data in|
|||||SCFTDR has become less than the transmission trigger number specified by|
|||||the TTRG[1:0] bits in the FIFO control register (SCFCR), and writing of transmit|
|||||data to SCFTDR is enabled.|
|||||0: The quantity of transmit data written to SCFTDR is greater than the specified|
|||||transmission trigger number|
|||||[Clearing conditions]|
|||||TDFE is cleared to 0 when data exceeding the specified transmission trigger|
|||||number is written to SCFTDR after 1 is read from TDFE and then 0 is written|
|||||to TDFE|
|||||TDFE is cleared to 0 when direct memory access controller is activated by|
|||||transmit FIFO data empty interrupt (TXI) and data exceeding the specified|
|||||transmission trigger number is written to SCFTDR|
|||||1: The quantity of transmit data in SCFTDR is less than or equal to the specified|
|||||transmission trigger number*1|
|||||[Setting conditions]|
|||||TDFE is set to 1 by a power-on reset|
|||||TDFE is set to 1 when the quantity of transmit data in SCFTDR becomes less|
|||||than or equal to the specified transmission trigger number as a result of|
|||||transmission|
|||||Note: 1. Since SCFTDR is a 16-byte FIFO register, the maximum quantity of|
|||||data that can be written when TDFE is 1 is "16 minus the specified|
|||||transmission trigger number". If an attempt is made to write additional|
|||||data, the data is ignored. The quantity of data in SCFTDR is indicated|
|||||by the upper 8 bits of SCFDR.|
|4|BRK|0|R/(W)*|Break Detection|
|||||Indicates that a break signal has been detected in receive data.|
|||||0: No break signal received|
|||||[Clearing conditions]|
|||||BRK is cleared to 0 by a power-on reset|
|||||BRK is cleared to 0 when software reads BRK after it has been set to 1, then|
|||||writes 0 to BRK|
|||||1: Break signal received*1|
|||||[Setting condition]|
|||||BRK is set to 1 when data including a framing error is received, followed by at|
|||||least one frame at the space 0 level (low level)|
|||||Note: 1. When a break is detected, transfer of the receive data (H'00) to|
|||||SCFRDR stops after detection. When the break ends and the receive|
|||||signal becomes mark 1, the transfer of receive data resumes.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|3|FER|0|R|Framing Error Indication|
|||||Indicates a framing error in the data read from the receive FIFO data register|
|||||(SCFRDR) in asynchronous mode.|
|||||0: No receive framing error occurred in the next data read from SCFRDR|
|||||[Clearing conditions]|
|||||FER is cleared to 0 by a power-on reset|
|||||FER is cleared to 0 when no framing error is present in the next data read from|
|||||SCFRDR|
|||||1: A receive framing error occurred in the next data read from SCFRDR|
|||||[Setting condition]|
|||||FER is set to 1 when a framing error is present in the next data read from|
|||||SCFRDR|
|2|PER|0|R|Parity Error Indication|
|||||Indicates a parity error in the data read from the receive FIFO data register|
|||||(SCFRDR) in asynchronous mode.|
|||||0: No receive parity error occurred in the next data read from SCFRDR|
|||||[Clearing conditions]|
|||||PER is cleared to 0 by a power-on reset|
|||||PER is cleared to 0 when no parity error is present in the next data read from|
|||||SCFRDR|
|||||1: A receive parity error occurred in the next data read from SCFRDR|
|||||[Setting condition]|
|||||PER is set to 1 when a parity error is present in the next data read from|
|||||SCFRDR|
|1|RDF|0|R/(W)*|Receive FIFO Data Full|
|||||Indicates that receive data has been transferred to the receive FIFO data|
|||||register (SCFRDR), and the quantity of data in SCFRDR has become more than|
|||||the receive trigger number specified by the RTRG[1:0] bits in the FIFO control|
|||||register (SCFCR).|
|||||0: The quantity of transmit data written to SCFRDR is less than the specified|
|||||receive trigger number|
|||||[Clearing conditions]|
|||||RDF is cleared to 0 by a power-on reset|
|||||RDF is cleared to 0 when the SCFRDR is read until the quantity of receive|
|||||data in SCFRDR becomes less than the specified receive trigger number after|
|||||1 is read from RDF, and then 0 is written|
|||||RDF is cleared to 0 when the direct memory access controller is activated by|
|||||receive FIFO data full interrupt (RXI) and SCFRDR is read until the quantity of|
|||||receive data in it becomes less than the specified receive trigger number|
|||||1: The quantity of receive data in SCFRDR is equal to or greater than the|
|||||specified receive trigger number|
|||||[Setting condition]|
|||||RDF is set to 1 when a quantity of receive data equal to or greater than the|
|||||specified receive trigger number is stored in SCFRDR*1|
|||||Note: 1. As SCFRDR is a 16-byte FIFO register, the maximum quantity of data|
|||||that can be read when RDF is 1 is the specified receive trigger number.|
|||||If an attempt is made to read after all the data in SCFRDR has been|
|||||read, the data is undefined. The quantity of receive data in SCFRDR is|
|||||indicated by the lower 8 bits of SCFDR.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|0|DR|0|R/(W)*|Receive Data Ready|
|||||Indicates that the quantity of data in the receive FIFO data register (SCFRDR) is|
|||||less than the specified receive trigger number, and that the next data has not yet|
|||||been received after the elapse of 15 ETU from the last stop bit in asynchronous|
|||||mode. In clock synchronous mode, this bit is not set to 1.|
|||||0: Receiving is in progress, or no receive data remains in SCFRDR after|
|||||receiving ended normally|
|||||[Clearing conditions]|
|||||DR is cleared to 0 by a power-on reset|
|||||DR is cleared to 0 when all receive data are read from SCFRDR after 1 is read|
|||||from DR, and then 0 is written.|
|||||DR is cleared to 0 when all receive data are read from SCFRDR after the|
|||||direct memory access controller is activated by receive FIFO data full interrupt|
|||||(RXI).|
|||||1: Next receive data has not been received|
|||||[Setting condition]|
|||||DR is set to 1 when SCFRDR contains less data than the specified receive|
|||||trigger number, and the next data has not yet been received after the elapse of|
|||||15 ETU from the last stop bit.*1|
|||||Note: 1. This is equivalent to 1.5 frames with the 8-bit, 1-stop-bit format. (ETU:|
|||||elementary time unit)|

Note: * Only 0 can be written to clear the flag after 1 is read.

## 14.3.8 Bit Rate Register (SCBRR)

SCBRR is an 8-bit register that is used with the CKS[1:0] bits in the serial mode register (SCSMR) and the BGDM and ABCS bits in the serial extension mode register (SCEMR) to determine the serial transmit/receive bit rate.

The CPU can always read from and write to SCBRR. SCBRR is initialized to H'FF by a power-on reset. Each channel has independent baud rate generator control, so different values can be set in eight channels.

Bit: 7 6 5 4 3 2 1 0 Initial value: 1 1 1 1 1 1 1 1 R/W: R/W R/W R/W R/W R/W R/W R/W R/W

The SCBRR setting is calculated as follows:

- Asynchronous mode:

When baud rate generator operates in normal mode (when the BGDM bit of SCEMR is 0):

**==> picture [348 x 55] intentionally omitted <==**

When baud rate generator operates in double speed mode (when the BGDM bit of SCEMR is 1):

**==> picture [345 x 58] intentionally omitted <==**

- Clock synchronous mode:

**==> picture [113 x 25] intentionally omitted <==**

- B: Bit rate (bits/s)

- N: SCBRR setting for baud rate generator (0  N  255)

- (The setting must satisfy the electrical characteristics.)

- P1  : Operating frequency for peripheral modules (MHz) n: Baud rate generator clock source (n  0, 1, 2, 3) (for the clock sources and values of n, see Table 14.3 .)

## **Table 14.3 SCSMR Settings**

|**n**<br>**Clock Source**|**SCSMR Settings**|
|---|---|
||**CKS[1]**<br>**CKS[0]**|
|0<br>P1|0<br>0|
|1<br>P1/4|0<br>1|
|2<br>P1/16|1<br>0|
|3<br>P1/64|1<br>1|

The bit rate error in asynchronous mode is given by the following formula:

**==> picture [351 x 88] intentionally omitted <==**

When baud rate generator operates in double speed mode (the BGDM bit of SCEMR is 1):

**==> picture [347 x 68] intentionally omitted <==**

Table 14.4 lists the sample SCBRR settings in asynchronous mode in which a base clock frequency is 16 times the bit rate (the ABCS bit in SCEMR is 0) and the baud rate generator operates in normal mode (the BGDM bit in SCEMR is 0), and Table 14.5 lists the sample SCBRR settings in clock synchronous mode.

**Table 14.4 Bit Rates and SCBRR Settings (Asynchronous Mode, BGDM = 0, ABCS = 0)**

|**Bit Rate (bits/s)**|**P1****(MHz)**|
|---|---|
||**50**<br>**66.67**|
||**n**<br>**N**<br>**Error (%)**<br>**n**<br>**N**<br>**Error (%)**|
|110|3<br>221<br>-0.02|
|150|3<br>162<br>-0.15<br>3<br>216<br>0.01|
|300|3<br>80<br>0.47<br>3<br>108<br>-0.45|
|600|2<br>162<br>-0.15<br>2<br>216<br>0.01|
|1200|2<br>80<br>0.47<br>2<br>108<br>-0.45|
|2400|1<br>162<br>-0.15<br>1<br>216<br>0.01|
|4800|1<br>80<br>0.47<br>1<br>108<br>-0.45|
|9600|0<br>162<br>-0.15<br>0<br>216<br>0.01|
|19200|0<br>80<br>0.47<br>0<br>108<br>-0.45|
|31250|0<br>49<br>0.00<br>0<br>66<br>-0.50|
|38400|0<br>40<br>-0.76<br>0<br>53<br>0.47|

Note: The error rate should be  1 . [Legend] Blank space: Setting impossible

**Table 14.5 Bit Rates and SCBRR Settings (Clock Synchronous Mode)**

|**Bit Rate (bits/s)**|**P1****(MHz)**|
|---|---|
||**50**<br>**66.67**|
||**n**<br>**N**<br>**n**<br>**N**|
|500|—<br>—|
|1000|3<br>194<br>—<br>—|
|2500|3<br>77<br>3<br>103|
|5000|2<br>155<br>2<br>207|
|10000|2<br>77<br>2<br>103|
|25000|1<br>124<br>1<br>166|
|50000|1<br>62<br>1<br>82|
|100000|0<br>124<br>0<br>166|
|250000|0<br>49<br>0<br>66|
|500000|0<br>24<br>—<br>—|
|1000000|—<br>—<br>—<br>—|
|2000000|—<br>—<br>—<br>—|

[Legend] Blank space: Setting impossible : Setting possible, but error occurs

Table 14.6 indicates the maximum bit rates in asynchronous mode when the baud rate generator is used. Table 14.7 lists the maximum bit rates in asynchronous mode when the external clock input is used. Table 14.8 lists the maximum bit rates in clock synchronous mode when the external clock input is used (when tScyc  12tpcyc*).

## Note: * Make sure that the electrical characteristics of this LSI and that of a connected LSI are satisfied.

**Table 14.6 Maximum Bit Rates for Various Frequencies with Baud Rate Generator (Asynchronous Mode)**

|**P1****(MHz)**||**Settings**<br>**Maximum Bit Rate (bits/s)**<br>**ABCS**<br>**n**<br>**N**|
|---|---|---|
||**BGDM**||
|50|0|0<br>0<br>0<br>1562500|
|||1<br>0<br>0<br>3125000|
||1|0<br>0<br>0<br>3125000|
|||1<br>0<br>0<br>6250000|
|66.67|0|0<br>0<br>0<br>2083333|
|||1<br>0<br>0<br>4166667|
||1|0<br>0<br>0<br>4166667|
|||1<br>0<br>0<br>8333333|

## **Table 14.7 Maximum Bit Rates with External Clock Input (Asynchronous Mode)**

|**P1****(MHz)**<br>**External Input Clock**<br>**(MHz)**|**Settings**<br>**Maximum Bit Rate (bits/s)**<br>**ABCS**|
|---|---|
|50<br>12.5000|0<br>781250|
||1<br>1562500|
|66.67<br>16.6667|0<br>1041667|
||1<br>2083333|

**Table 14.8 Maximum Bit Rates with External Clock Input (Clock Synchronous Mode, tScyc**  **12 tpcyc)**

|**P1****(MHz)**|**External Input Clock (MHz)**|**Maximum Bit Rate (bits/s)**|
|---|---|---|
|50|4.1667|4166666.7|
|66.67|5.5556|5555555.5|

## 14.3.9 FIFO Control Register (SCFCR)

SCFCR resets the quantity of data in the transmit and receive FIFO data registers, sets the trigger data quantity, and contains an enable bit for loop-back testing. SCFCR can always be read and written to by the CPU.

|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-||RSTRG[2:0]||RTRG[1:0]||TTRG[1:0]||MCE|TFRST|RFRST|LOOP|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**||||
|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**||
|15 to 11|—|All 0|R|Reserved||
|||||These bits are always read as 0. The write value should always be 0.||
|10 to 8|RSTRG[2:0]|000|R/W|RTS<br>Output Active Trigger||
|||||When the quantity of receive data in receive FIFO data register (SCFRDR)||
|||||becomes equal to or greater than the trigger set number shown below, RTS||
|||||signal is set to high.||
|||||000: 15||
|||||001: 1||
|||||010: 4||
|||||011: 6||
|||||100: 8||
|||||101: 10||
|||||110: 12||
|||||111: 14||
|7, 6|RTRG[1:0]|00|R/W|Receive FIFO Data Trigger||
|||||Set the quantity of receive data which sets the receive data full (RDF) flag in the||
|||||serial status register (SCFSR). The RDF flag is set to 1 when the quantity of||
|||||receive data stored in the receive FIFO data register (SCFRDR) becomes equal||
|||||to or greater than the set trigger number shown below.||
|||||• Asynchronous mode<br>• Clock synchronous mode||
|||||00: 1<br>00: 1||
|||||01: 4<br>01: 2||
|||||10: 8<br>10: 8||
|||||11: 14<br>11: 14||
|||||Note:<br>In clock synchronous mode, to transfer the receive data using the||
|||||direct memory access controller, set the receive trigger number||
|||||to 1. If set to other than 1, CPU must read the receive data left in||
|||||SCFRDR.||
|5, 4|TTRG[1:0]|00|R/W|Transmit FIFO Data Trigger||
|||||Set the quantity of remaining transmit data which sets the transmit FIFO data||
|||||register empty (TDFE) flag in the serial status register (SCFSR). The TDFE flag||
|||||is set to 1 when the quantity of transmit data in the transmit FIFO data register||
|||||(SCFTDR) becomes equal to or less than the set trigger number shown|below.|
|||||00: 8 (8)*||
|||||01: 4 (12)*||
|||||10: 2 (14)*||
|||||11: 0 (16)*||
|||||Note: * Values in parentheses mean the number of empty bytes in SCFTDR||
|||||when the TDFE flag is set to 1.||
|3|MCE|0|R/W|Modem Control Enable||
|||||Enables modem control signals CTS<br>and RTS<br>.||
|||||For channels 3 and 4 in clock synchronous mode, MCE bit should always be 0.||
|||||0: Modem signal disabled*||
|||||1: Modem signal enabled||
|||||Note: * CTS<br>is fixed at active 0 regardless of the input value, and RTS<br>|is also|
|||||fixed at 0.||

|||**Initial**||||
|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**||
|2|TFRST|0|R/W|Transmit FIFO Data Register Reset||
|||||Disables the transmit data in the transmit|FIFO data register and resets the|
|||||register to the empty state.||
|||||0: Reset operation disabled*||
|||||1: Reset operation enabled||
|||||Note: * Reset operation is executed by a power-on reset.||
|1|RFRST|0|R/W|Receive FIFO Data Register Reset||
|||||Disables the receive data in the receive FIFO data register and resets the||
|||||register to the empty state.||
|||||0: Reset operation disabled*||
|||||1: Reset operation enabled||
|||||Note: * Reset operation is executed by a power-on reset.||
|0|LOOP|0|R/W|Loop-Back Test||
|||||Internally connects the transmit outputpin|(TxD) and receive input pin (RxD) and|
|||||internally connects the RTS<br>pin and CTS<br>|pin and enables loop-back testing.|
|||||0: Loop back test disabled||
|||||1: Loop back test enabled||

## 14.3.10 FIFO Data Count Set Register (SCFDR)

SCFDR is a 16-bit register which indicates the quantity of data stored in the transmit FIFO data register (SCFTDR) and the receive FIFO data register (SCFRDR).

It indicates the quantity of transmit data in SCFTDR with the upper 8 bits, and the quantity of receive data in SCFRDR with the lower 8 bits. SCFDR can always be read by the CPU.

||Bit:|15|14|13|12|11|10<br>9|8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|---|
|||-|-|-|||T[4:0]|-<br>-<br>-<br>R[4:0]||
||Initial value:|0|0|0|0|0|0<br>0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||R/W:|R|R|R|R|R|R<br>R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||
||||**Initial**|||||||
|**Bit**|**Bit Name**||**Value**||**R/W**||**Description**|||
|15 to 13|—||All|0|R||Reserved|||
||||||||These bits are always read as 0. The write value should always be 0.|||
|12 to 8|T[4:0]||00000||R||T4 to T0 bits|indicate the quantity of non-transmitted data stored in SCFTDR.||
||||||||H'00 means no transmit data, and H'10 means that all transmit data is||stored in|
||||||||SCFTDR.|||
|7 to 5|—||All|0|R||Reserved|||
||||||||These bits are always read as 0. The write value should always be 0.|||
|4 to 0|R[4:0]||00000||R||R4 to R0 bits indicate the quantity of receive data stored in SCFRDR. H'00|||
||||||||means no receive data, and H'10 means that all receive data is stored||in|
||||||||SCFRDR.|||

## 14.3.11 Serial Port Register (SCSPTR)

SCSPTR controls input/output and data of pins multiplexed to the functions of this module. Bits 7 and 6 can control input/output data of RTS pin. Bits 5 and 4 can control input/output data of CTS pin. Bits 3 and 2 can control input/output data of SCK pin. Bits 1 and 0 can input data from RxD pin and output data to TxD pin, so they control break of serial transmitting/receiving.

The CPU can always read and write to SCSPTR.

||||Bit:|15|14|13|12||11|10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|-|-||-|-<br>-<br>-<br>RTSIO RTSDT CTSIO CTSDT SCKIO SCKDT SPB2IOSPB2DT|||
||||Initial value:|0|0|0|0||0|0<br>0<br>0<br>0<br>1<br>0<br>1<br>0<br>0<br>0<br>0|||
||||R/W:|R|R|R|R||R|R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|||
||||||**Initial**||||||||
|**Bit**|||**Bit Name**||**Value**||**R/W**|||**Description**|||
|15|to|8|—||All|0|R|||Reserved|||
|||||||||||These bits are always read as 0. The write value should always be 0.|||
|7|||RTSIO||0||R/W|||RTS<br>Port Input/Output|||
|||||||||||Specifies input or output for the serial port RTS<br>pin. When the RTS<br>pin is actually|||
|||||||||||used as a port outputting the RTSDT bit value, the MCE bit in SCFCR should be|||
|||||||||||cleared to 0.|||
|||||||||||0: RTSDT bit value not output to RTS<br>pin|||
|||||||||||1: RTSDT bit value output to RTS<br>pin|||
|6|||RTSDT||1||R/W|||RTS<br>Port Data|||
|||||||||||Specifies the input/output data of the serial port|RTS<br>pin. Input/output is||
|||||||||||specified bythe RTSIO bit. For output, the RTSDT bit value is output to the RTS|||
|||||||||||pin. The RTS<br>pin status is read from the RTSDT bit regardless of the RTSIO bit|||
|||||||||||setting. However, RTS<br>input/output must be set|in the general purpose|I/O ports.|
|||||||||||0: Input/output data is low level|||
|||||||||||1: Input/output data is high level|||
|5|||CTSIO||0||R/W|||CTS<br>Port Input/Output|||
|||||||||||Specifies input or output for the serial port CTS<br>|pin. When the CTS<br>pin is||
|||||||||||actually used as a port outputting the CTSDT bit value, the MCE bit in||SCFCR|
|||||||||||should be cleared to 0.|||
|||||||||||0: CTSDT bit value not output to CTS<br>pin|||
|||||||||||1: CTSDT bit value output to CTS<br>pin|||
|4|||CTSDT||1||R/W|||CTS<br>Port Data|||
|||||||||||Specifies the input/output data of the serial port|CTS<br>pin. Input/output is||
|||||||||||specified bythe CTSIO bit. For output, the CTSDT bit value is output to the CTS|||
|||||||||||pin. The CTS<br>pin status is read from the CTSDT bit regardless of the CTSIO bit|||
|||||||||||setting. However, CTS<br>input/output must be set|in the general purpose|I/O ports.|
|||||||||||0: Input/output data is low level|||
|||||||||||1: Input/output data is high level|||
|3|||SCKIO||0||R/W|||SCK Port Input/Output|||
|||||||||||Specifies input or output for the serial port SCK|pin. When the SCK pin is||
|||||||||||actually used as a port outputting the SCKDT bit value, the CKE[1:0] bits in|||
|||||||||||SCSCR should be cleared to 0.|||
|||||||||||0: SCKDT bit value not output to SCK pin|||
|||||||||||1: SCKDT bit value output to SCK pin|||
|2|||SCKDT||0||R/W|||SCK Port Data|||
|||||||||||Specifies the input/output data of the serial port|SCK pin. Input/output is||
|||||||||||specified by the SCKIO bit. For output, the SCKDT bit value is output to the SCK|||
|||||||||||pin. The SCK pin status is read from the SCKDT bit regardless of the SCKIO bit|||
|||||||||||setting. However, SCK input/output must be set|in the general purpose|I/O ports.|
|||||||||||0: Input/output data is low level|||
|||||||||||1: Input/output data is high level|||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|1|SPB2IO|0|R/W|Serial Port Break Input/Output|
|||||Specifies input or output for the serial port TxD pin. When the TxD pin is actually|
|||||used as a port outputting the SPB2DT bit value, the TE bit in SCSCR should be|
|||||cleared to 0.|
|||||0: SPB2DT bit value not output to TxD pin|
|||||1: SPB2DT bit value output to TxD pin|
|0|SPB2DT|0|R/W|Serial Port Break Data|
|||||Specifies the input data of the RxD pin and the output data of the TxD pin used|
|||||as serial ports. Input/output is specified by the SPB2IO bit. When the TxD pin is|
|||||set to output, the SPB2DT bit value is output to the TxD pin. The RxD pin status|
|||||is read from the SPB2DT bit regardless of the SPB2IO bit setting. However, RxD|
|||||input and TxD output must be set in the general purpose I/O ports.|
|||||0: Input/output data is low level|
|||||1: Input/output data is high level|

## 14.3.12 Line Status Register (SCLSR)

The CPU can always read or write to SCLSR, but cannot write 1 to the ORER flag. This flag can be cleared to 0 only if it has first been read (after being set to 1).

|Bit:|15|14|13|12|11|10|9||8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-||-|-|-|-|-|-|-|-|ORER|
|Initial value:|0|0|0|0|0|0|0||0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R||R|R|R|R|R|R|R|R|R/(W)*|
|Note:<br>*|Only 0 can be written to clear||||the flag after 1||is read.|||||||||||

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||ORER|0|R/(W)*|Overrun Error|
|||||||Indicates the occurrence of an overrun error during reception.|
|||||||0: Receiving is in progress or has ended normally*1|
|||||||[Clearing conditions]|
|||||||ORER is cleared to 0 by a power-on reset|
|||||||ORER is cleared to 0 when 0 is written after 1 is read from ORER.|
|||||||1: An overrun error has occurred during reception*2|
|||||||[Setting condition]|
|||||||ORER is set to 1 when the next serial receiving is finished while the receive|
|||||||FIFO is full of 16-byte receive data.|
|||||||Note: 1. Clearing the RE bit to 0 in SCSCR does not affect the ORER bit, which|
|||||||retains its previous value.|
|||||||2. The receive FIFO data register (SCFRDR) retains the data before|
|||||||an overrun error has occurred, and the next received data is|
|||||||discarded. When the ORER bit is set to 1, the next serial|
|||||||reception cannot be continued.|

## 14.3.13 Serial Extension Mode Register (SCEMR)

The CPU can always read from or write to SCEMR. Setting the BGDM bit in this register to 1 allows the baud rate generator in this module to operate in double-speed mode when asynchronous mode is selected (by setting the C/A bit in SCSMR to 0) and an internal clock is selected as a clock source and the SCK pin is set as an input pin (by setting the CKE[1:0] bits in SCSCR to 00).

The base clock frequency within a bit period in asynchronous mode can be switched by the setting of the ABCS bit.

||Bit:|15|14|13|12||11|10<br>9<br>8<br>7<br>6<br>5<br>4<br>3|2|1||0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|-|-||-|-<br>-<br>-<br>BGDM<br>-<br>-<br>-<br>-|-|-|ABCS|||
||Initial value:|0|0|0|0||0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0|0||0||
||R/W:|R|R|R|R||R|R<br>R<br>R<br>R/W<br>R<br>R<br>R<br>R|R|R||R/W||
||||**Initial**|||||||||||
|**Bit**|**Bit Name**||**Value**||**R/W**|||**Description**||||||
|15 to 8|—||All|0|R|||Reserved||||||
|||||||||These bits are always read as 0. The write value should always|||be 0.|||
|7|BGDM||0||R/W|||Baud Rate Generator Double-Speed Mode||||||
|||||||||When the BGDM bit is set to 1, the baud rate generator in this module|||||operates|
|||||||||in double-speed mode. This bit is valid only when asynchronous mode|||||is|
|||||||||selected by setting the C/A<br>bit in SCSMR to 0 and an internal clock is selected||||||
|||||||||as a clock source and the SCK pin is set as an input pin by setting the CKE[1:0]||||||
|||||||||bits in SCSCR to 00. In other settings, use normal mode.||||||
|||||||||0: Normal mode||||||
|||||||||1: Double-speed mode||||||
|6 to 1|—||All|0|R|||Reserved||||||
|||||||||These bits are always read as 0. The write value should always|||be 0.|||
|0|ABCS||0||R/W|||Base Clock Select in Asynchronous Mode||||||
|||||||||This bit selects the base clock frequency within a bit period in asynchronous||||||
|||||||||mode. This bit is valid only in asynchronous mode (when||the C/A<br>||bit in|SCSMR|
|||||||||is 0).||||||
|||||||||0: Base clock frequency is 16 times the bit rate||||||
|||||||||1: Base clock frequency is 8 times the bit rate||||||

## 14.4 Operation

## 14.4.1 Overview

For serial communication, this module has an asynchronous mode in which characters are synchronized individually, and a clock synchronous mode in which communication is synchronized with clock pulses.

This module has a 16-stage FIFO buffer for both transmission and reception, reducing the overhead of the CPU, and enabling continuous high-speed communication. Furthermore, channels 0, 1, and 2 have RTS and CTS signals to be used as modem control signals.

The transmission/reception format is selected in the serial mode register (SCSMR), as shown in Table 14.9 . The clock source is selected by the combination of the C/A bit in SCSMR and the CKE[1:0] bits in the serial control register (SCSCR), as shown in Table 14.10 .

## (1) Asynchronous Mode

- Data length is selectable: 7 or 8 bits

- Parity bit is selectable. So is the stop bit length (1 or 2 bits). The combination of the preceding selections constitutes the communication format and character length.

- In receiving, it is possible to detect framing errors, parity errors, receive FIFO data full, overrun errors, receive data ready, and breaks.

- The number of stored data bytes is indicated for both the transmit and receive FIFO registers.

- An internal or external clock can be selected as the clock source.

   - When an internal clock is selected, this module operates using the clock of on-chip baud rate generator.

   - When an external clock is selected, the external clock input must have a frequency 16 or 8 times the bit rate. (The on-chip baud rate generator is not used.)

## (2) Clock Synchronous Mode

- The transmission/reception format has a fixed 8-bit data length.

- In receiving, it is possible to detect overrun errors (ORER).

- An internal or external clock can be selected as the clock source.

   - When an internal clock is selected, this module operates using the clock of the on-chip baud rate generator, and outputs this clock to external devices as the synchronous clock.

   - When an external clock is selected, this module operates on the input external synchronous clock not using the on-chip baud rate generator.

## **Table 14.9 SCSMR Settings and Communication Formats**

||**SCSMR Settings**<br>**Mode**<br>**Bit 6**<br>**CHR**<br>**Bit 5**<br>**PE**<br>**Bit 3**<br>**STOP**|**SCSMR Settings**<br>**Mode**<br>**Bit 6**<br>**CHR**<br>**Bit 5**<br>**PE**<br>**Bit 3**<br>**STOP**|**SCSMR Settings**<br>**Mode**<br>**Bit 6**<br>**CHR**<br>**Bit 5**<br>**PE**<br>**Bit 3**<br>**STOP**||**Communication Format**|**Communication Format**|
|---|---|---|---|---|---|---|
|**Bit 7**<br>**C/A**|**Bit 6**<br>**CHR**|**Bit 5**<br>**PE**||**Data Length**|**Parity Bit**|**Stop Bit Length**|
|0|0|0|0<br>Asynchronous<br>1<br>0<br>1<br>0<br>1<br>0<br>1|8 bits|Not set|1 bit|
|||||||2 bits|
|||1|||Set|1 bit|
|||||||2 bits|
||1|0||7 bits|Not set|1 bit|
|||||||2 bits|
|||1|||Set|1 bit|
|||||||2 bits|
|1|x|x|x<br>Clock synchronous|8 bits|Not set|None|

[Legend]

x: Don't care

## **Table 14.10 SCSMR and SCSCR Settings and Clock Source Selection**

|**SCSMR**|**SCSCR**<br>**Mode**<br>**Bit 1, 0**<br>**CKE[1:0]**|**Clock Source**|**SCK Pin Function**|
|---|---|---|---|
|**Bit 7**<br>**C/A**||||
|0|00<br>Asynchronous<br>01<br>10<br>11|Internal|This module does not use the SCK pin.|
||||Outputs a clock with a frequency 16/8 times the bit rate|
|||External|Inputs a clock with frequency 16/8 times the bit rate|
|||Setting prohibited||
|1|0x<br>Clock<br>synchronous<br>10<br>11|Internal<br>Outputs the synchronous clock||
|||External<br>Inputs the synchronous clock||
|||Setting prohibited||

[Legend]

x: Don't care

Note: When using the baud rate generator in double-speed mode (BGMD = 1), select asynchronous mode by setting the C/A bit to 0, and select an internal clock as a clock source and the SCK pin is not used (the CKE[1:0] bits set to 00).

## 14.4.2 Operation in Asynchronous Mode

In asynchronous mode, each transmitted or received character begins with a start bit and ends with a stop bit. Serial communication is synchronized one character at a time.

The transmitting and receiving sections in this module are independent, so full duplex communication is possible. The transmitter and receiver are 16-stage FIFO buffered, so data can be written and read while transmitting and receiving are in progress, enabling continuous transmitting and receiving.

Figure 14.2 shows the general format of asynchronous serial communication.

In asynchronous serial communication, the communication line is normally held in the mark (high) state. This module monitors the line and starts serial communication when the line goes to the space (low) state, indicating a start bit.

One serial character consists of a start bit (low), data (LSB first), parity bit (high or low), and stop bit (high), in that order. When receiving in asynchronous mode, this module synchronizes at the falling edge of the start bit. This module samples each data bit on the eighth or fourth pulse of a clock with a frequency 16 or 8 times the bit rate; receive data is latched at the center of each bit.

**==> picture [367 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
Idle state (mark state)<br>1 (LSB) (MSB) 1<br>Serial  0 D0 D1 D2 D3 D4 D5 D6 D7 0/1 1 1<br>data<br>Start  Parity  Stop bit<br>bit Transmit/receive data bit<br>1 bit 7 or 8 bits 1 bit  1 or 2 bits<br>or<br>none<br>One unit of transfer data (character or frame)<br>**----- End of picture text -----**<br>

**Figure 14.2 Example of Data Format in Asynchronous Communication (8-Bit Data with Parity and Two Stop Bits)**

## (1) Transmit/Receive Formats

Table 14.11 lists the eight communication formats that can be selected in asynchronous mode. The format is selected by settings in the serial mode register (SCSMR).

## **Table 14.11 Serial Communication Formats (Asynchronous Mode)**

|**SCSMR**|**SCSMR**|**Bits**|||**Serial**|**Transmit/Receive**|**Transmit/Receive**|**Transmit/Receive**|**Format**|**and Frame Length**|**and Frame Length**|**and Frame Length**|||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**CHR**|**PE**|**STOP**|**1**|**2**|**3**|**4**|**5**|**6**|**7**|**8**|**9**|**10**|**11**|**12**|
|0|0|0|START||||8-bit data|||||STOP|||
|0|0|1|START||||8-bit data|||||STOP|STOP||
||||||||||||||||
|0|1|0|START||||8-bit data|||||P|STOP||
||||||||||||||||
||||||||||||||||
|0|1|1|START||||8-bit data|||||P|STOP|STOP|
||||||||||||||||
|1|0|0|START||||7-bit data||||STOP||||
|1|0|1|START||||7-bit data||||STOP|STOP|||
||||||||||||||||
|1|1|0|START||||7-bit data||||P|STOP|||
||||||||||||||||
||||||||||||||||
|1|1|1|START||||7-bit data||||P|STOP|STOP||

[Legend]

START: Start bit

STOP: Stop bit P: Parity bit

## (2) Clock

An internal clock generated by the on-chip baud rate generator or an external clock input from the SCK pin can be selected as the transmit/receive clock. The clock source is selected by the C/A bit in the serial mode register (SCSMR) and the CKE[1:0] bits in the serial control register (SCSCR). For clock source selection, refer to Table 14.10 , SCSMR and SCSCR Settings and Clock Source Selection.

When an external clock is input at the SCK pin, it must have a frequency equal to 16 or 8 times the desired bit rate. When this module operates on an internal clock, it can output a clock signal on the SCK pin. The frequency of this output clock is 16 or 8 times the desired bit rate.

## (3) Transmitting and Receiving Data

- Initialization (Asynchronous Mode)

   - Before transmitting or receiving, clear the TE and RE bits to 0 in the serial control register (SCSCR), then initialize this module as follows.

When changing the operation mode or the communication format, always clear the TE and RE bits to 0 before following the procedure given below. Clearing TE to 0 initializes the transmit shift register (SCTSR). Clearing TE and RE to 0, however, does not initialize the serial status register (SCFSR), transmit FIFO data register (SCFTDR), or receive FIFO data register (SCFRDR), which retain their previous contents. Clear TE to 0 after all transmit data has been transmitted and the TEND flag in the SCFSR is set. The TE bit can be cleared to 0 during transmission, but the transmit data goes to the Mark state after the bit is cleared to 0. Set the TFRST bit in SCFCR to 1 and reset SCFTDR before TE is set again to start transmission.

When an external clock is used, the clock should not be stopped during initialization or subsequent operation. The operation becomes unreliable if the clock is stopped.

## Figure 14.3 shows a sample flowchart for initialization.

**==> picture [327 x 310] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start of initialization<br>Clear the TE and RE bits in SCSCR to 0 [1] Set the clock selection in SCSCR.<br>Be sure to clear bits TIE, RIE, TE,<br>Set the TFRST and RFRST bits in SCFCR to 1 and RE to 0.<br>[2] Set the data transfer format in<br>After reading flags ER, DR, and BRK in SCFSR, SCSMR.<br>and each flag in SCLSR, write 0 to clear them<br>[3] Write a value corresponding to the<br>Set the CKE[1:0] bits in SCSCR [1] bit rate into SCBRR. (Not<br>(leaving bits TIE, RIE, TE, and RE cleared to 0) necessary if an external clock is<br>used.)<br>Set data transfer format in SCSMR [2]<br>[4]  Sets the general I/O port external pins<br>used. Set as RxD input at receiving<br>Set the BGDM and ABCS bits in SCEMR and TxD output at transmission.<br>However, no setting for SCK pin is<br>Set value in SCBRR [3] required when CKE[1:0] is 00.<br>[5] Set the TE bit or RE bit in SCSCR<br>Set the RTRG[1:0], TTRG[1:0], and   to 1. Also set the RIE, REIE, and<br>MCE bits in SCFCR, and  TIE bits. Setting the TE and RE bits<br>clear TFRST and RFRST bits to 0 enables the TxD and RxD pins to be<br>used.<br>Set the general I/O port external pins used [4] When transmitting, the serial<br>SCK, TxD, RxD communication interface with FIFO will<br>go to the mark state; when receiving,<br>Set the TE and RE bits in SCSCR to 1, and set the TIE, RIE, and REIE bits [5] it will go to the idle state, waiting for a start bit.<br>In the case when internal clock output<br>is set, the SCK pin starts outputting the<br>End of initialization clock at this stage.<br>**----- End of picture text -----**<br>

**Figure 14.3 Sample Flowchart for Initialization**

- Transmitting Serial Data (Asynchronous Mode)

Figure 14.4 shows a sample flowchart for serial transmission.

Use the following procedure for serial data transmission after enabling transmission.

**==> picture [301 x 342] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start of transmission<br>[1] Status check and transmit data write:<br>Read SCFSR and check that the<br>Read TDFE flag in SCFSR TDFE flag is set to 1, then write<br>transmit data to SCFTDR, and read 1<br>No from the TDFE and TEND flags, then<br>TDFE = 1? clear to 0.<br> The quantity of transmit data that can<br>Yes be written is 16 - (transmit trigger set<br>number).<br>Write transmit data in SCFTDR,<br>[1]<br>and read 1 from TDFE flag  [2] Serial transmission continuation<br>and TEND flag in SCFSR,  procedure:<br>then clear to 0 To continue serial transmission, read<br>1 from the TDFE flag to confirm that<br>writing is possible, then write data to<br>No<br>All data transmitted? [2] SCFTDR, and then clear the TDFE<br>flag to 0.<br>Yes [3] Break output during serial<br>transmission:<br>Read TEND flag in SCFSR To output a break in serial<br>transmission, clear the SPB2DT bit to<br>0 and set the SPB2IO bit to 1 in<br>No<br>TEND = 1? SCSPTR, then clear the TE bit in<br>SCSCR to 0.<br>Yes<br>No In [1] and [2], it is possible to ascertain<br>Break output?<br>the number of data bytes that can be<br>written from the number of transmit data<br>Yes bytes in SCFTDR indicated by the upper<br>Clear SPB2DT to 0 and [3] 8 bits of SCFDR.<br>set SPB2IO to 1<br>Clear TE bit in SCSCR to 0<br>End of transmission<br>**----- End of picture text -----**<br>

**Figure 14.4 Sample Flowchart for Transmitting Serial Data**

In serial transmission, this module operates as described below.

1. When data is written into the transmit FIFO data register (SCFTDR), the data is transferred from SCFTDR to the transmit shift register (SCTSR). Confirm that the TDFE flag in the serial status register (SCFSR) is set to 1 before writing transmit data to SCFTDR. The number of data bytes that can be written is (16 – transmit trigger setting).

2. When data is transferred from SCFTDR to SCTSR and transmission is started, consecutive transmit operations are performed until there is no transmit data left in SCFTDR. When the number of transmit data bytes in SCFTDR becomes equal to or less than the transmit trigger number set in the FIFO control register (SCFCR), the TDFE flag is set. If the TIE bit in the serial control register (SCSR) is set to 1 at this time, a transmit-FIFO-data-empty interrupt (TXI) request is generated.

The serial transmit data is sent from the TxD pin in the following order.

   - A. Start bit: One-bit 0 is output.

   - B. Transmit data: 8-bit or 7-bit data is output in LSB-first order.

   - C. Parity bit: One parity bit (even or odd parity) is output. (A format in which a parity bit is not output can also be selected.)

   - D. Stop bit(s): One or two 1 bits (stop bits) are output.

   - E. Mark state: 1 is output continuously until the start bit that starts the next transmission is sent.

3. The SCFTDR transmit data is checked at the timing for sending the stop bit. If data is present, the data is transferred from SCFTDR to SCTSR, the stop bit is sent, and then serial transmission of the next frame is started.

Figure 14.5 shows an example of the operation for transmission.

**==> picture [402 x 142] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start  Parity  Stop  Start  Parity  Stop<br>1 bit Data bit bit bit Data bit bit 1<br>Serial<br>Idle state<br>data 0 D0 D1 D7 0/1 1 0 D0 D1 D7 0/1 1<br>(mark state)<br>TDFE<br>TEND<br>TXI interrupt  Data written to SCFTDR and TDFE  TXI interrupt<br>request flag read as 1 then cleared to 0 by  request<br>TXI interrupt handler<br>One frame<br>**----- End of picture text -----**<br>

**Figure 14.5 Example of Transmit Operation (8-Bit Data, Parity, 1 Stop Bit)**

4. When modem control is enabled in channels 0, 1, and 2, transmission can be stopped and restarted in accordance with the CTS input value. When CTS is set to 1, if transmission is in progress, the line goes to the mark state after transmission of one frame. When CTS is set to 0, the next transmit data is output starting from the start bit.

Figure 14.6 shows an example of the operation when modem control is used.

**==> picture [367 x 108] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Parity Stop Start<br>bit bit bit bit<br>Serial data 0 D0 D1 D7 0/1 0 D0 D1 D7 0/1<br>TxD<br>CTS<br>Drive high before stop bit<br>**----- End of picture text -----**<br>

**Figure 14.6 Example of Operation Using Modem Control (CTS)**

- Receiving Serial Data (Asynchronous Mode)

Figure 14.7 and Figure 14.8 show sample flowcharts for serial reception.

Use the following procedure for serial data reception after enabling reception.

**==> picture [294 x 332] intentionally omitted <==**

**----- Start of picture text -----**<br>
[1] Receive error handling and<br>Start of reception<br>break detection:<br>      Read the DR, ER, and BRK<br>Read ER, DR, BRK flags in flags in SCFSR, and the<br>SCFSR and ORER [1] ORER flag in SCLSR, to<br>flag in SCLSR identify any error, perform the<br>appropriate error handling,<br>then clear the DR, ER, BRK,<br>and ORER flags to 0. In the<br>ER, DR, BRK or ORER = 1? Yes case of a framing error, a<br>break can also be detected by<br>reading the value of the RxD<br>No Error handling pin.<br>[2] Status check and receive data<br>Read RDF flag in SCFSR [2] read:<br>      Read SCFSR and check that<br>No RDF flag = 1, then read the<br>RDF = 1? receive data in SCFRDR, read<br>1 from the RDF flag, and then<br>Yes clear the RDF flag to 0. The<br>Read receive data in transition of the RDF flag from<br>0 to 1 can also be identified by<br>SCFRDR, and clear RDF<br>a receive FIFO data full<br>flag in SCFSR to 0<br>interrupt (RXI).<br>No [3] Serial reception continuation<br>All data received? [3] procedure:<br>      To continue serial reception,<br>Yes read at least the receive<br>Clear RE bit in SCSCR to 0 trigger set number of receive<br>data bytes from SCFRDR,<br>read 1 from the RDF flag, then<br>End of reception clear the RDF flag to 0. The<br>number of receive data bytes<br>in SCFRDR can be<br>ascertained by reading lower 8<br>bits of SCFDR.<br>**----- End of picture text -----**<br>

**Figure 14.7 Sample Flowchart for Receiving Serial Data (1)**

**==> picture [279 x 364] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error handling<br>   • Whether a framing error or parity error<br>No has occurred in the receive data that<br>ORER = 1?<br>is to be read from the receive FIFO<br>Yes data register (SCFRDR) can be<br>ascertained from the FER and PER<br>Overrun error handling bits in the serial status register<br>(SCFSR).<br>   • When a break signal is received,<br>No receive data is not transferred to<br>ER = 1? SCFRDR while the BRK flag is set.<br>However, note that the last data in<br>Yes SCFRDR is H'00, and the break data<br>in which a framing error occurred is<br>Receive error handling stored.<br>No<br>BRK = 1?<br>Yes<br>Break handling<br>No<br>DR = 1?<br>Yes<br>Read receive data in SCFRDR<br>Clear DR, ER, BRK flags<br>in SCFSR,<br>and ORER flag in SCLSR to 0<br>End<br>**----- End of picture text -----**<br>

**Figure 14.8 Sample Flowchart for Receiving Serial Data (2)**

In serial reception, this module operates as described below.

1. The transmission line is monitored, and if a 0 start bit is detected, internal synchronization is performed and reception is started.

2. The received data is stored in SCRSR in LSB-to-MSB order.

3. The parity bit and stop bit are received.

After receiving these bits, this module carries out the following checks.

- A. Stop bit check: Checks whether the stop bit is 1. If there are two stop bits, only the first is checked.

- B. Checks whether receive data can be transferred from the receive shift register (SCRSR) to SCFRDR.

- C. Overrun check: Checks that the ORER flag is 0, indicating that the overrun error has not occurred. D. Break check: Checks that the BRK flag is 0, indicating that the break state is not set. If all the above checks are passed, the receive data is stored in SCFRDR.

Note: When a parity error or a framing error occurs, reception is not suspended.

4. If the RIE bit in SCSCR is set to 1 when the RDF or DR flag changes to 1, a receive-FIFO-data-full interrupt (RXI) request is generated. If the RIE bit or the REIE bit in SCSCR is set to 1 when the ER flag changes to 1, a receiveerror interrupt (ERI) request is generated. If the RIE bit or the REIE bit in SCSCR is set to 1 when the BRK or ORER flag changes to 1, a break reception interrupt (BRI) request is generated.

Figure 14.9 shows an example of the operation for reception in asynchronous mode.

**==> picture [394 x 147] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start  Data Parity  Stop  Start  Data Parity  Stop<br>1 bit bit bit bit bit bit 1<br>Serial<br>data 0 D0 D1 D7 0/1 1 0 D0 D1 D7 0/1 1 Idle state (mark state)<br>RDF<br>RXI interrupt<br>FER request<br>Data read and RDF flag<br>One frame read as 1 then cleared to 0  ERI interrupt request<br>by RXI interrupt handler generated by receive<br>error<br>**----- End of picture text -----**<br>

## **Figure 14.9 Example of Receive Operation(8-Bit Data, Parity, 1 Stop Bit)**

5. When modem control is enabled in channels 0, 1, and 2, the RTS signal is output when SCFRDR is empty. When RTS is 0, reception is possible. When RTS is 1, this indicates that the quantity of data stored in SCFRDR has become equal to or greater than the number set for the RTS output active trigger.

Figure 14.10 shows an example of the operation when modem control is used.

**==> picture [380 x 79] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start  Parity Start  Parity<br>bit bit bit bit<br>Serial data<br>RxD 0 D0 D1 D2 D7 0/1 1 0 D0 D1 D7 0/1<br>RTS<br>**----- End of picture text -----**<br>

**Figure 14.10 Example of Operation Using Modem Control (RTS)**

## 14.4.3 Operation in Clock Synchronous Mode

In clock synchronous mode, data is transmitted and received in synchronization with clock pulses. This mode is suitable for high-speed serial communication.

The transmitter and receiver in this module are independent, so full-duplex communication is possible while sharing the same clock. The transmitter and receiver are also 16-stage FIFO buffered, so continuous transmitting or receiving is possible by reading or writing data while transmitting or receiving is in progress.

Figure 14.11 shows the general format in clock synchronous serial communication.

**==> picture [401 x 137] intentionally omitted <==**

**----- Start of picture text -----**<br>
One unit of transfer data (character or frame)<br>* *<br>Serial clock<br>LSB MSB<br>Serial data Don't care Bit 0 Bit 1 Bit 2 Bit 3 Bit 4 Bit 5 Bit 6 Bit 7 Don't care<br>Note: * High except in continuous transfer<br>**----- End of picture text -----**<br>

**Figure 14.11 Data Format in Clock Synchronous Communication**

In clock synchronous serial communication, each data bit is output on the communication line from one falling edge of the serial clock to the next. Data is guaranteed valid at the rising edge of the serial clock.

In each character, the serial data bits are transmitted in order from the LSB (first) to the MSB (last). After output of the MSB, the communication line remains in the state of the MSB.

In clock synchronous mode, data is received in synchronization with the rising edge of the synchronous clock.

## (1) Transmit/Receive Formats

The data length is fixed at eight bits. No parity bit can be added.

## (2) Clock

An internal clock generated by the on-chip baud rate generator or an external synchronous clock input from the SCK pin can be selected by setting the C/A bit in SCSMR and the CKE[1:0] bits in SCSCR,.

When this module operates on an internal clock, it outputs the synchronous clock signal at the SCK pin. Eight clock pulses are output per one character transmission or reception. When transmission or reception is not performed, the clock signal remains in the high state. When only receiving is performed with the internal clock selected, the clock signal pulses are output while the RE bit of SCSCR is 1 and the number of data in receive FIFO is more than the receive FIFO data trigger number.

## (3) Transmitting and Receiving Data

- Initialization (Clock Synchronous Mode)

   - Before transmitting, receiving, or changing the mode or communication format, the software must clear the TE and RE bits to 0 in the serial control register (SCSCR), and then initialize this module following the procedure described below.

Clearing TE to 0 initializes the transmit shift register (SCTSR). Clearing RE to 0, however, does not initialize the RDF, PER, FER, and ORER flags and receive data register (SCRDR), which retain their previous contents.

Figure 14.12 shows a sample flowchart for initialization.

|Start of initialization|Start of initialization||[1]|Leave the TE and RE bits cleared|
|---|---|---|---|---|
|||||to 0 until the initialization almost|
|Clear TE and RE bits<br>in SCSCR to 0||[1]|[2]|ends.<br>Set the data transfer format in|
|Set TFRST and RFRST bits||||SCSMR.|
|in SCFCR to 1 to clear<br>the FIFO buffer|||[3]|Set CKE[1:0].|
|After reading ER, DR, and BRK flags<br>in SCFSR and ORER flag in SCLSR,<br>write 0 to clear them|||[4]|Write a value corresponding to<br>the bit rate into SCBRR. This<br>is not necessary if an external<br>clock is used.|
|Set data transfer format<br>in SCSMR||[2]|[5]|Sets the general I/O port external|
|||||pins used. Set as RxD input at|
|Set CKE[1:0] in SCSCR<br>(leaving TIE, RIE, TE,||[3]||receiving and as TxD output at<br>transmission.|
|and RE bits cleared to 0)|||[6]|Set the TE or RE bit in SCSCR|
|||||to 1. Also set the TIE, RIE, and|
|Set value in SCBRR||[4]||REIE bits to enable the TxD,<br>RxD, and SCK pins to be used.|
|||||When transmitting, the TxD pin|
|Set RTRG[1:0] and TTRG[1:0] bits<br>in SCFCR, and clear TFRST<br>and RFRST bits to 0||||will go to the mark state.<br>When receiving in clock<br>synchronous mode with the|
|||||synchronous clock output (clock|
|||||master) selected, a clock starts to|
|Set the general I/O port external pins used<br>SCK, TxD, RxD||[5]||be output from the SCK pin at this<br>point.|
||||||
|Set TE and RE|bits in SCSCR||||
|to 1, and set TIE, RIE,||[6]|||
|and REIE bits|||||
|End of initialization|||||

**Figure 14.12 Sample Flowchart for Initialization**

- Transmitting Serial Data (Clock Synchronous Mode)

Figure 14.13 shows a sample flowchart for transmitting serial data.

Use the following procedure for serial data transmission after enabling transmit operation.

**==> picture [300 x 281] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start of transmission<br>[1] Status check and transmit data write:<br>Read TDFE flag in SCFSR       Read SCFSR and check that the<br>TDFE flag is set to 1, then write<br>transmit data to SCFTDR. Clear the<br>TDFE = 1? No TDFE and TEND flags to 0 after<br>reading them as 1.<br>Yes [2] Serial transmission continuation<br>procedure:<br>Write transmit data to SCFTDR,<br>read TDFE and TEND flags        To continue serial transmission, read<br>[1]<br>in SCFSR as 1,  1 from the TDFE flag to confirm that<br>and then clear the flags to 0 writing is possible, then write data to<br>SCFTDR, and then clear the TDFE<br>flag to 0.<br>No<br>All data transmitted? [2]<br>Yes<br>Read TEND flag in SCFSR<br>No<br>TEND = 1?<br>Yes<br>Clear TE bit in SCSCR to 0<br>End of transmission<br>**----- End of picture text -----**<br>

**Figure 14.13 Sample Flowchart for Transmitting Serial Data**

In serial transmission, this module operates as described below.

1. When data is written into the transmit FIFO data register (SCFTDR), the data is transferred from SCFTDR to the transmit shift register (SCTSR). Confirm that the TDFE flag in the serial status register (SCFSR) is set to 1 before writing transmit data to SCFTDR. The number of transmit data bytes that can be written is (16 – transmit trigger setting).

2. When data is transferred from SCFTDR to SCTSR and transmission is started, consecutive transmit operations are performed until there is no transmit data left in SCFTDR. When the number of transmit data bytes in SCFTDR falls below the transmit trigger number set in the FIFO control register (SCFCR), the TDFE flag is set. If the TIE bit in the serial control register (SCSCR) is set to 1 at this time, a transmit-FIFO-data-empty interrupt (TXI) request is generated.

   - If clock output mode is selected, eight synchronous clock pulses are output. If an external clock source is selected, data is output in synchronization with the input clock. Data is output from the TxD pin in order from the LSB (bit 0) to the MSB (bit 7).

3. The SCFTDR transmit data is checked at the timing for sending the MSB (bit 7). If data is present, the data is transferred from SCFTDR to SCTSR, and then serial transmission of the next frame is started. If there is no data, the TxD pin holds the state after the TEND flag in SCFSR is set to 1 and the MSB (bit 7) is sent.

4. After the end of serial transmission, the SCK pin is held in the high state.

Figure 14.14 shows an example of transmit operation.

**==> picture [307 x 151] intentionally omitted <==**

**----- Start of picture text -----**<br>
Serial clock<br>LSB MSB<br>Serial data Bit 0 Bit 1 Bit 7 Bit 0 Bit 1 Bit 6 Bit 7<br>TDFE<br>TEND<br>TXI Data written to SCFTDR  TXI<br>interrupt and TDFE flag cleared  interrupt<br>request to 0 by TXI interrupt  request<br>handler<br>One frame<br>**----- End of picture text -----**<br>

**Figure 14.14 Example of Transmit Operation**

- Receiving Serial Data (Clock Synchronous Mode)

   - Figure 14.15 and Figure 14.16 show sample flowcharts for receiving serial data. Use the following procedure for serial data reception after enabling receive operation. When switching from asynchronous mode to clock synchronous mode without initialization, make sure that ORER, PER, and FER are cleared to 0.

**==> picture [335 x 257] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start of reception<br>[1] Receive error handling:<br>Read  the ORER flag in SCLSR to identify<br>Read ORER flag in SCLSR any error, perform the appropriate error<br>handling, then clear the ORER flag to 0.<br>Reception cannot be resumed while the<br>Yes ORER flag is set to 1.<br>ORER = 1?<br>[1] [2]  Status check and receive data read:<br>Read SCFSR and check that RDF = 1,<br>No Error handling then read the receive data in SCFRDR,<br>and clear the RDF flag to 0. The transition<br>Read RDF flag in SCFSR [2] of the RDF flag from 0 to 1 can also be<br>identified by a receive FIFO data full<br>No interrupt (RXI).<br>RDF = 1? [3] Serial reception continuation procedure:<br>To continue serial reception, read at least<br>Yes<br>the receive trigger set number of receive<br>Read receive data in data bytes from SCFRDR, read 1 from the<br>[3]<br>SCFRDR, and clear RDF RDF flag, then clear the RDF flag to 0.<br>flag in SCFSR to 0 The number of receive data bytes in<br>SCFRDR can be ascertained by reading<br>No lower bits of SCFRDR. However, the RDF<br>All data received? bit is cleared to 0 automatically when an<br>RXI interrupt activates the direct memory<br>Yes access controller to read the data in<br>Clear RE bit in SCSCR to 0 SCFRDR.<br>End of reception<br>**----- End of picture text -----**<br>

**Figure 14.15 Sample Flowchart for Receiving Serial Data (1)**

**==> picture [137 x 133] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error handling<br>No<br>ORER = 1?<br>Yes<br>Overrun error handling<br>Clear ORER flag in SCLSR to 0<br>End<br>**----- End of picture text -----**<br>

**Figure 14.16 Sample Flowchart for Receiving Serial Data (2)**

In serial reception, this module operates as described below.

1. Reception is started in synchronization with synchronous clock input or output.

2. Receive data is shifted into SCRSR in order from the LSB to the MSB. After the data reception, whether the receive data can be loaded from SCRSR into SCFRDR or not is checked. If this check is passed, the RDF flag is set to 1 and the received data is stored in SCFRDR. If the check is not passed (overrun error is detected), further reception is prevented.

3. After setting RDF to 1, if the receive interrupt enable bit (RIE) is set to 1 in SCSCR, a receive FIFO data full interrupt (RXI) request is generated. If the ORER bit is set to 1 and the receive interrupt enable bit (RIE) or the receive error interrupt enable bit (REIE) in SCSCR is also set to 1, a break interrupt (BRI) request is generated.

Figure 14.17 shows an example of receive operation.

**==> picture [393 x 172] intentionally omitted <==**

**----- Start of picture text -----**<br>
Serial clock<br>LSB MSB<br>Serial data Bit 7 Bit 0 Bit 7 Bit 0 Bit 1 Bit 6 Bit 7<br>RDF<br>ORER<br>RXI  Data read from SCFRDR and  RXI<br>interrupt  RDF flag cleared to 0 by RXI  interrupt  BRI interrupt request<br>request interrupt handler request by overrun error<br>One frame<br>**----- End of picture text -----**<br>

**Figure 14.17 Example of Receive Operation**

- Transmitting and Receiving Serial Data Simultaneously (Clock Synchronous Mode) Figure 14.18 shows a sample flowchart for transmitting and receiving serial data simultaneously. Use the following procedure for the simultaneous transmission/reception of serial data, after enabling transmit/ receive operation.

**==> picture [326 x 416] intentionally omitted <==**

**----- Start of picture text -----**<br>
||||
|---|---|---|
|Initialization|[1] Status check and transmit data write:|
|Read SCFSR and check that the|
|TDFE flag is set to 1, then write|
|Start of transmission and reception|transmit data to SCFTDR. Clear the|
|TDFE and TEND flags to 0 after|
|reading them as 1. The transition of|
|the TDFE flag from 0 to 1 can also be|
|Read TDFE flag in SCFSR|identified by a transmit FIFO data|
|empty interrupt (TXI).|
|No|[2] Receive error handling:|
|TDFE = 1?|
|Read the ORER flag in SCLSR to|
|identify any error, perform the|
|Yes|appropriate error handling, then clear|
|the ORER flag to 0. Reception cannot|
|Write transmit data to SCFTDR,|be resumed while the ORER flag is|
|read TDFE and TEND flags|[1]|set to 1.|
|in SCFSR as 1,|
|and then clear the flags to 0|[3] Status check and receive data read:|
|Read SCFSR and check that RDF|
|flag = 1, then read the receive data in|
|SCFRDR, and clear the RDF flag to|
|Read ORER flag in SCLSR|0. The transition of the RDF flag from|
|0 to 1 can also be identified by a|
|Yes|receive FIFO data full interrupt|
|ORER = 1?|(RXI).|
|[2]|
|No|[4] Serial transmission and reception|
|Error handling|continuation procedure:|
|Read RDF flag in SCFSR|To continue serial transmission and|
|reception, read 1 from the RDF flag|
|and the receive data in SCFRDR, and|
|No|clear the RDF flag to 0 before|
|RDF = 1?|receiving the MSB in the current|
|frame. Similarly, read 1 from the|
|Yes|TDFE flag to confirm that writing is|
|possible before transmitting the MSB|
|Read receive data in|in the current frame. Then write data|
|SCFRDR, and clear RDF|[3]|to SCFTDR and clear the TDFE flag|
|flag in SCFSR to 0|to 0.|
|No|
|All data received?|
|Yes|
|Note:|When switching from a transmit operation|
|Clear TE and RE bits|or receive operation to simultaneous|
|in SCSCR to 0|[4]|transmission and reception operations,|
|clear the TE and RE bits to 0, and then|
|set them simultaneously to 1.|
|End of transmission and reception|

**----- End of picture text -----**<br>

**Figure 14.18 Sample Flowchart for Transmitting/Receiving Serial Data**

## 14.5 Interrupts

This module has four interrupt sources: transmit-FIFO-data-empty (TXI), receive-error (ERI), receive FIFO data full (RXI), and break (BRI).

Table 14.12 shows the interrupt sources and their order of priority. The interrupt sources are enabled or disabled by means of the TIE, RIE, and REIE bits in SCSCR. A separate interrupt request is sent to the interrupt controller for each of these interrupt sources.

When a TXI request is enabled by the TIE bit and the TDFE flag in the serial status register (SCFSR) is set to 1, a TXI interrupt request is generated. The direct memory access controller can be activated and data transfer performed by this TXI interrupt request. At this time, an interrupt request is not sent to the CPU.

When an RXI request is enabled by the RIE bit and the RDF flag or the DR flag in SCFSR is set to 1, an RXI interrupt request is generated. The direct memory access controller can be activated and data transfer performed by this RXI interrupt request. At this time, an interrupt request is not sent to the CPU. The RXI interrupt request caused by the DR flag is generated only in asynchronous mode.

When the RIE bit is set to 0 and the REIE bit is set to 1, this module requests only an ERI or a BRI interrupt without requesting an RXI interrupt.

The TXI indicates that transmit data can be written, and the RXI indicates that there is receive data in SCFRDR.

## **Table 14.12 Interrupt Sources**

|**Interrupt**||**Direct Memory Access**|**Priority on Reset**|**Priority on Reset**|
|---|---|---|---|---|
|**Source**|**Description**|**Controller Activation**|**Release**||
|BRI|Interrupt initiated by break (BRK) or overrun error (ORER)|Not possible|High||
|ERI|Interrupt initiated by receive error (ER)|Not possible|||
|RXI|Interrupt initiated by receive FIFO data full (RDF) or data ready (DR)|Possible|||
|TXI|Interrupt initiated by transmit FIFO data empty (TDFE)|Possible|Low||

## 14.6 Usage Notes

Note the following when using this module.

## 14.6.1 SCFTDR Writing and TDFE Flag

The TDFE flag in the serial status register (SCFSR) is set when the number of transmit data bytes written in the transmit FIFO data register (SCFTDR) has fallen below the transmit trigger number set by bits TTRG[1:0] in the FIFO control register (SCFCR). After the TDFE flag is set, transmit data up to the number of empty bytes in SCFTDR can be written, allowing efficient continuous transmission.

However, if the number of data bytes written in SCFTDR is equal to or less than the transmit trigger number, the TDFE flag will be set to 1 again after being read as 1 and cleared to 0. The TDFE flag should therefore be cleared to 0 after being read as 1 when SCFTDR contains more than the transmit trigger number of transmit data bytes.

The number of transmit data bytes in SCFTDR can be found from the upper 8 bits of the FIFO data count register (SCFDR).

## 14.6.2 SCFRDR Reading and RDF Flag

The RDF flag in the serial status register (SCFSR) is set when the number of receive data bytes in the receive FIFO data register (SCFRDR) has become equal to or greater than the receive trigger number set by bits RTRG[1:0] in the FIFO control register (SCFCR). After RDF flag is set, receive data equivalent to the trigger number can be read from SCFRDR, allowing efficient continuous reception.

However, if the number of data bytes in SCFRDR exceeds the trigger number, the RDF flag will be set to 1 again after being read as 1 and then cleared to 0. The RDF flag should therefore be cleared to 0 after being read as 1 after reading the number of the received data in the receive FIFO data register (SCFRDR) which is less than the trigger number.

The number of receive data bytes in SCFRDR can be found from the lower 8 bits of the FIFO data count register (SCFDR).

## 14.6.3 Restriction on Direct Memory Controller Usage

When the direct memory access controller writes data to SCFTDR due to a TXI interrupt request, the state of the TEND flag becomes undefined. Therefore, the TEND flag should not be used as the transfer end flag in such a case.

## 14.6.4 Break Detection and Processing

Break signals can be detected by reading the RxD pin directly when a framing error (FER) is detected. In the break state the input from the RxD pin consists of all 0s, so the FER flag is set and the parity error flag (PER) may also be set.

Note that, although transfer of receive data to SCFRDR is halted in the break state, the receive operation is continued.

## 14.6.5 Sending a Break Signal

The I/O condition and level of the TxD pin are determined by the SPB2IO and SPB2DT bits in the serial port register (SCSPTR). This feature can be used to send a break signal.

Until TE bit is set to 1 (enabling transmission) after initializing, the TxD pin does not work. During the period, mark status is performed by the SPB2DT bit. Therefore, the SPB2IO and SPB2DT bits should be set to 1 (high level output).

To send a break signal during serial transmission, clear the SPB2DT bit to 0 (designating low level), then clear the TE bit to 0 (halting transmission). When the TE bit is cleared to 0, the transmitter is initialized regardless of the current transmission state, and 0 is output from the TxD pin.

## 14.6.6 Receive Data Sampling Timing and Receive Margin (Asynchronous Mode)

This module operates on a base clock with a frequency 16 or 8 times the bit rate. In reception, the falling edge of the start bit is sampled at the base clock to perform synchronization internally. Receive data is latched at the rising edge of the eighth or fourth base clock pulse. When this module operates on a base clock with a frequency 16 times the bit rate, the receive data is sampled at the timing shown in Figure 14.19 .

**==> picture [409 x 130] intentionally omitted <==**

**----- Start of picture text -----**<br>
16 clocks<br>8 clocks<br>0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0 1 2 3 4 5<br>Base clock<br>–7.5 clocks +7.5 clocks<br>Receive data<br>(RxD) Start bit D0 D1<br>Synchronization<br>sampling timing<br>Data sampling<br>timing<br>**----- End of picture text -----**<br>

**Figure 14.19 Receive Data Sampling Timing in Asynchronous Mode (Operation on a Base Clock with a Frequency 16 Times the Bit Rate)**

The receive margin in asynchronous mode can therefore be expressed as shown in equation 1.

## **Equation 1:**

1 D − 0.5 M =  (0.5 − ) − (L − 0.5) F − (1 + F)   × 100 % 2N N

Where: M: Receive margin (%)

N: Ratio of clock frequency to bit rate (N = 16 or 8)

D: Clock duty (D = 0 to 1.0)

L: Frame length (L = 9 to 12)

- F: Absolute deviation of clock frequency

From equation 1, if F = 0, D = 0.5 and N = 16, the receive margin is 46.875%, as given by equation 2.

## **Equation 2:**

When D = 0.5 and F = 0: M = (0.5 − 1/(2 × 16)) × 100% = 46.875%

This is a theoretical value. A reasonable margin to allow in system designs is 20% to 30%.

## 14.6.7 Selection of Base Clock in Asynchronous Mode

In this LSI, when asynchronous mode is selected, the base clock frequency within a bit period can be set to the frequency 16 or 8 times the bit rate by setting the ABCS bit in SCEMR.

Note that, however, if the base clock frequency 8 times the bit rate is used, receive margin is decreased as calculated using equation 1 in section 14.6.6, Receive Data Sampling Timing and Receive Margin (Asynchronous Mode) .

If the desired bit rate can be set simply by setting SCBRR and the CKS[1:0] bits in SCSMR, it is recommended to use the base clock frequency within a bit period 16 times the bit rate (by setting the ABCS bit in SCEMR to 0). If an internal clock is selected as a clock source and the SCK pin is not used, the bit rate can be increased without decreasing receive margin by selecting double-speed mode for the baud rate generator (setting the BGDM bit in SCEMR to 1).
