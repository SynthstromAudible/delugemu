# 19. Serial Sound Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 880–918. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

The serial sound interface is a module designed to send or receive audio data interface with various devices offering I[2] S bus compatibility. It also provides additional modes for other common formats, as well as support for multi-channel mode.

## 19.1 Features

- Number of channels: Four channels

- Operating mode: Non-compressed mode

   - The non-compressed mode supports serial audio streams divided by channels.

- Serves as both a transmitter and a receiver Channels 0, 1, and 3 support full-duplex communications.

- Capable of using serial bus format

- Asynchronous transfer takes place between the data buffer and the shift register.

- It is possible to select a dividing ratio for the clock used by the serial bus interface.

- It is possible to control data transmission or reception with DMA transfer and interrupt requests. A path is also provided for direct data transfer between this module and the SCUX module.

- Selects the oversampling clock input from among the following pins: —AUDIO_CLK (1 to 50 MHz)

   - —AUDIO_X1, AUDIO_X2 (when connecting a crystal resonator: 10 to 50 MHz, when used to input external clock: 1 to 50 MHz)

- Includes 8-stage FIFO buffers in transmitter and receiver

- Supports multi-channel mode (TDM mode) in which the SSIWS signal is high only for system word 1 period.

- Supports WS continue mode in which the SSIWS signal is not stopped.

- An interrupt is used to notify the CPU of a change of sampling frequency during transfer.

Figure 19.1 shows a block diagram of this module.

**==> picture [386 x 300] intentionally omitted <==**

**----- Start of picture text -----**<br>
Peripheral bus<br>Interrupt/DMA<br>request<br>SSIFTDR SSIFRDR<br>Control  RegistersSSICR  (8-step FIFO)  (8-step FIFO)<br>circuit SSISR<br>SSIFCR<br>Serial audio bus SSIFSR SSITDR SSIRDR<br>SSITDMR<br>SSIDATA*<br>MSB Shift register LSB<br>MSB Shift register LSB AUDIO_CLK<br>SSISCK Serial clock control<br>Divider AUDIO_X1<br>AUDIO_X2<br>SSIWS<br>Bit counter<br>[Legend]<br>SSICR: Control register SSIFCR: FIFO control register Note:  *  In channels 0, 1, and 3, SSIDATA can be<br>SSISR: Status register SSIFSR: FIFO status register used independently as SSITxD for<br>SSITDR: Transmit data register SSIFTDR: Transmit FIFO data register transmission and SSIRxD for reception.<br>SSIRDR: Receive data register SSIFRDR: Receive FIFO data register<br>SSITDMR: TDM mode register<br>Crystaloscillator<br>**----- End of picture text -----**<br>

**Figure 19.1 Block Diagram of Serial Sound Interface**

## 19.2 Input/Output Pins

Table 19.1 shows the pin assignments relating to this module.

## **Table 19.1 Pin Assignments**

|**Table 19.1**|**Pin Assignments**|
|---|---|
|**Channel**|**Pin Name**<br>**I/O**<br>**Description**|
|0, 1, 3|SSISCK0*1*3, SSISCK1*1*3,<br>SSISCK3*1*3<br>I/O<br>Serial bit clock|
||SSIWS0*1*3, SSIWS1*1*3,<br>SSIWS3*1*3<br>I/O<br>Word selection|
||SSITxD0, SSITxD1,<br>SSITxD3<br>Output<br>Serial data output|
||SSIRxD0*1, SSIRxD1*1,<br>SSIRxD3*1<br>Input<br>Serial data input|
|2|SSISCK2*1*3<br>I/O<br>Serial bit clock|
||SSIWS2*1*3<br>I/O<br>Word selection|
||SSIDATA2*1<br>I/O<br>Serial data input/output|
|Common|AUDIO_CLK*2<br>Input<br>External clock for audio (input oversampling clock)|
||AUDIO_X1<br>Input<br>Crystal resonator/external clock for audio (input oversampling<br>clock)<br>AUDIO_X2<br>Output|

Note 1. In slave mode, whether or not to use the noise canceler in the input route can be selected. For details, refer to section 41.3.15, Serial Sound Interface Noise Canceler Control Register (SNCR), under section 41, Ports.

Note 2. When the SSInCKS bit (n = 0 to 3) is set to 1, the MLB_CLK pin is used as the AUDIO_CLK pin. For details, refer to section

37.3.70, SSI Pin Mode Register (SSIPMD_CIM) and section 37.4.4, Pin Connection Specifications of SSIF.

Note 3. Each of SSIF1 to SSIF3 can use SSISCK0 and SSIWS0 of SSIF0 as its own SSISCK and SSIWS. For details, refer to section 37.3.70, SSI Pin Mode Register (SSIPMD_CIM) and section 37.4.4, Pin Connection Specifications of SSIF. When SSIF1 to SSIF3 uses SSIF0 as the master, the noise canceler function cannot be used.

## 19.3 Register Description

Table 19.2 lists the register configuration. Note that explanation in the text does not refer to the channels.

## **Table 19.2 Register Configuration**

|**Table 19.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|0|Control register 0<br>SSICR_0<br>R/W<br>H'00000000<br>H'E820B000<br>32|
||Status register 0<br>SSISR_0<br>R/W*1<br>H'02000013<br>H'E820B004<br>32|
||FIFO control register 0<br>SSIFCR_0<br>R/W<br>H'00000000<br>H'E820B010<br>32|
||FIFO status register 0<br>SSIFSR_0<br>R/(W)*2<br>H'00010000<br>H'E820B014<br>32|
||Transmit FIFO data register 0<br>SSIFTDR_0<br>W<br>Undefined<br>H'E820B018<br>32|
||Receive FIFO data register 0<br>SSIFRDR_0<br>R<br>Undefined<br>H'E820B01C<br>32|
||TDM mode register 0<br>SSITDMR_0<br>R/W<br>H'00000000<br>H'E820B020<br>32|
||FC control register 0<br>SSIFCCR_0<br>R/W<br>H'00000000<br>H'E820B024<br>32|
||FC mode register 0<br>SSIFCMR_0<br>R/W<br>H'00000000<br>H'E820B028<br>32|
||FC status register 0<br>SSIFCSR_0<br>R/(W)*3<br>H'00000000<br>H'E820B02C<br>32|
|1|Control register 1<br>SSICR_1<br>R/W<br>H'00000000<br>H'E820B800<br>32|
||Status register 1<br>SSISR_1<br>R/W*1<br>H'02000013<br>H'E820B804<br>32|
||FIFO control register 1<br>SSIFCR_1<br>R/W<br>H'00000000<br>H'E820B810<br>32|
||FIFO status register 1<br>SSIFSR_1<br>R/(W)*2<br>H'00010000<br>H'E820B814<br>32|
||Transmit FIFO data register 1<br>SSIFTDR_1<br>W<br>Undefined<br>H'E820B818<br>32|
||Receive FIFO data register 1<br>SSIFRDR_1<br>R<br>Undefined<br>H'E820B81C<br>32|
||TDM mode register 1<br>SSITDMR_1<br>R/W<br>H'00000000<br>H'E820B820<br>32|
||FC control register 1<br>SSIFCCR_1<br>R/W<br>H'00000000<br>H'E820B824<br>32|
||FC mode register 1<br>SSIFCMR_1<br>R/W<br>H'00000000<br>H'E820B828<br>32|
||FC status register 1<br>SSIFCSR_1<br>R/(W)*3<br>H'00000000<br>H'E820B82C<br>32|
|2|Control register 2<br>SSICR_2<br>R/W<br>H'00000000<br>H'E820C000<br>32|
||Status register 2<br>SSISR_2<br>R/W*1<br>H'02000013<br>H'E820C004<br>32|
||FIFO control register 2<br>SSIFCR_2<br>R/W<br>H'00000000<br>H'E820C010<br>32|
||FIFO status register 2<br>SSIFSR_2<br>R/(W)*2<br>H'00010000<br>H'E820C014<br>32|
||Transmit FIFO data register 2<br>SSIFTDR_2<br>W<br>Undefined<br>H'E820C018<br>32|
||Receive FIFO data register 2<br>SSIFRDR_2<br>R<br>Undefined<br>H'E820C01C<br>32|
||TDM mode register 2<br>SSITDMR_2<br>R/W<br>H'00000000<br>H'E820C020<br>32|
||FC control register 2<br>SSIFCCR_2<br>R/W<br>H'00000000<br>H'E820C024<br>32|
||FC mode register 2<br>SSIFCMR_2<br>R/W<br>H'00000000<br>H'E820C028<br>32|
||FC status register 2<br>SSIFCSR_2<br>R/(W)*3<br>H'00000000<br>H'E820C02C<br>32|
|3|Control register 3<br>SSICR_3<br>R/W<br>H'00000000<br>H'E820C800<br>32|
||Status register 3<br>SSISR_3<br>R/W*1<br>H'02000013<br>H'E820C804<br>32|
||FIFO control register 3<br>SSIFCR_3<br>R/W<br>H'00000000<br>H'E820C810<br>32|
||FIFO status register 3<br>SSIFSR_3<br>R/(W)*2<br>H'00010000<br>H'E820C814<br>32|
||Transmit FIFO data register 3<br>SSIFTDR_3<br>W<br>Undefined<br>H'E820C818<br>32|
||Receive FIFO data register 3<br>SSIFRDR_3<br>R<br>Undefined<br>H'E820C81C<br>32|
||TDM mode register 3<br>SSITDMR_3<br>R/W<br>H'00000000<br>H'E820C820<br>32|
||FC control register 3<br>SSIFCCR_3<br>R/W<br>H'00000000<br>H'E820C824<br>32|
||FC mode register 3<br>SSIFCMR_3<br>R/W<br>H'00000000<br>H'E820C828<br>32|
||FC status register 3<br>SSIFCSR_3<br>R/(W)*3<br>H'00000000<br>H'E820C82C<br>32|

Note 1. Although bits 29 to 26 in these registers can be read from or written to, bits other than these are read-only. For details, refer to section 19.3.2, Status Register (SSISR).

- Note 2. To bits 16 and 0 in these registers, only 0 can be written to clear the flags. Other bits are read-only. For details, refer to section 19.3.6, FIFO Status Register (SSIFSR).

- Note 3. To bit 24 in these registers, only 0 can be written to clear the flag. Other bits are read-only. For details, refer to section 19.3.12, FC Status Register (SSIFCSR).

## 19.3.1 Control Register (SSICR)

SSICR is a 32-bit readable/writable register that controls the IRQ, selects the polarity status, and sets operating mode.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20||19|18||17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|CKS|TUIEN|TOIEN|RUIEN|ROIEN|IIEN|-|CHNL[1:0]|||DWL[2:0]||||SWL[2:0]|||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0||0|0||0|0|
|R/W:||R|R/W|R/W|R/W|R/W|R/W|R/W|R|R/W|R/W|R/W|R/W||R/W|R/W||R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4||3|2||1|0|
|||SCKD|SWSD|SCKP|SWSP|SPDP|SDTA|PDTA|DEL||CKDV[3:0]||||MUEN|-||TEN|REN|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0||0|0||0|0|
|R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R||R/W|R/W|

||||**Initial**|||
|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|31||―|0|R|Reserved|
||||||The read value is undefined. The write value should always be 0.|
|30||CKS|0|R/W|Oversampling Clock Select|
||||||Selects the clock source for oversampling.|
||||||0: AUDIO_X1 input|
||||||1: AUDIO_CLK input|
|29||TUIEN|0|R/W|Transmit Underflow Interrupt Enable|
||||||0: Disables an underflow interrupt.|
||||||1: Enables an underflow interrupt.|
|28||TOIEN|0|R/W|Transmit Overflow Interrupt Enable|
||||||0: Disables an overflow interrupt.|
||||||1: Enables an overflow interrupt.|
|27||RUIEN|0|R/W|Receive Underflow Interrupt Enable|
||||||0: Disables an underflow interrupt.|
||||||1: Enables an underflow interrupt.|
|26||ROIEN|0|R/W|Receive Overflow Interrupt Enable|
||||||0: Disables an overflow interrupt.|
||||||1: Enables an overflow interrupt.|
|25||IIEN|0|R/W|Idle Mode Interrupt Enable|
||||||0: Disables an idle mode interrupt.|
||||||1: Enables an idle mode interrupt.|
|24||―|0|R|Reserved|
||||||The read value is undefined. The write value should always be 0.|
|23,|22|CHNL[1:0]|00|R/W|Channels|
||||||[When TDM = 0]|
||||||These bits show the number of channels in each system word.|
||||||00: Having one channel per system word|
||||||01: Having two channels per system word|
||||||10: Having three channels per system word|
||||||11: Having four channels per system word|
||||||[When TDM = 1]|
||||||These bits show the number of system words in each TDM frame.|
||||||00: Setting prohibited|
||||||01: Having four system words per TDM frame|
||||||10: Having six system words per TDM frame|
||||||11: Having eight system words per TDM frame|

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**|**Description**|
|---|---|
|21 to 19<br>DWL[2:0]<br>000<br>R/W|Data Word Length<br>These bits indicate the number of bits in a data word.<br>000: 8 bits<br>001: 16 bits<br>010: 18 bits<br>011: 20 bits<br>100: 22 bits<br>101: 24 bits<br>110: 32 bits<br>111: Setting prohibited|
|18 to 16<br>SWL[2:0]<br>000<br>R/W|System Word Length<br>These bits indicate the number of bits in a system word.<br>000: 8 bits<br>001: 16 bits<br>010: 24 bits<br>011: 32 bits<br>100: 48 bits<br>101: 64 bits<br>110: 128 bits<br>111: 256 bits|
|15<br>SCKD<br>0<br>R/W|Serial Bit Clock Direction<br>0: Serial bit clock is input, slave mode.<br>1: Serial bit clock is output, master mode.<br>Note: Only the following settings are allowed:<br>(SCKD, SWSD) = (0, 0) or (1, 1).<br>Other settings are prohibited.|
|14<br>SWSD<br>0<br>R/W|Serial WS Direction<br>0: Serial word select is input, slave mode.<br>1: Serial word select is output, master mode.<br>Note: Only the following settings are allowed:<br>(SCKD, SWSD) = (0,0) or (1,1).<br>Other settings are prohibited.|
|13<br>SCKP<br>0<br>R/W|Serial Bit Clock Polarity<br>0: SSIWS and SSIDATA change at the SSISCK falling edge (sampled at the<br>SCK rising edge).<br>1: SSIWS and SSIDATA change at the SSISCK rising edge (sampled at the<br>SCK falling edge).<br>**SCKP =0**<br>**SCKP = 1**<br>SSIDATA input sampling timing at the<br>time of reception<br>SSISCK rising<br>edge<br>SSISCK falling<br>edge<br>SSIDATA output change timing at the<br>time of transmission<br>SSISCK falling<br>edge<br>SSISCK rising<br>edge<br>SSIWS input sampling timing at the<br>time of slave mode (SWSD = 0)<br>SSISCK rising<br>edge<br>SSISCK falling<br>edge<br>SSIWS output change timing at the<br>time of master mode (SWSD = 1)<br>SSISCK falling<br>edge<br>SSISCK rising<br>edge|
|12<br>SWSP<br>0<br>R/W|Serial WS Polarity<br>[When TDM = 0]<br>0: SSIWS is low for the 1st channel, high for the 2nd channel.<br>1: SSIWS is high for the 1st channel, low for the 2nd channel.<br>[When TDM = 1]<br>0: SSIWS is high only for system word 1 period, low for other periods.<br>1: Setting prohibited|
|11<br>SPDP<br>0<br>R/W|Serial Padding Polarity<br>This bit is used to specify the active sense of padding bits. It is also used to<br>specify the logical value to be output from the SSITxD pin when the MUEN<br>bit is set to 0 with transfer disabled in WS continue mode.<br>0: Padding bits are low.<br>1: Padding bits are high.|

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**|**Description**|
|---|---|
|10<br>SDTA<br>0<br>R/W|Serial Data Alignment<br>0: Transmitting and receiving in the order of serial data and padding bits<br>1: Transmitting and receiving in the order of padding bits and serial data|
|9<br>PDTA<br>0<br>R/W|Parallel Data Alignment<br>When the data word length is 32 bits, this configuration field has no meaning.<br>This bit applies to SSIRDR in receive mode and SSITDR in transmit mode.<br>When data word length is 8 or 16 bits:<br>0: The lower bits of parallel data (SSITDR, SSIRDR) are transferred prior to<br>the upper bits.<br>1: The upper bits of parallel data (SSITDR, SSIRDR) are transferred prior to<br>the lower bits.<br>When data word length is 18, 20, 22, or 24 bits:<br>0: Parallel data (SSITDR, SSIRDR) is left-aligned.<br>1: Parallel data (SSITDR, SSIRDR) is right-aligned.<br>PDTA = 0<br>DWL[2:0]<br>SSITDR/SSIRDR[31:0]<br>000<br>31<br>24 23<br>16 15<br>8 7<br>0<br>4th word<br>3rd word<br>2nd word<br>1st word<br>001<br>31<br>16 15<br>0<br>2nd word<br>1st word<br>010<br>31<br>14 13<br>0<br>Valid<br>Invalid<br>011<br>31<br>12 11<br>0<br>Valid<br>Invalid<br>100<br>31<br>10 9<br>0<br>Valid<br>Invalid<br>101<br>31<br>8 7<br>0<br>Valid<br>Invalid<br>110<br>31<br>0<br>Valid|
||PDTA = 1<br>Note: This bit has no meaning in direct transfer between this module and the<br>SCUX. Use the SWAP function of the SCUX.<br>DWL[2:0]<br>SSITDR/SSIRDR[31:0]<br>000<br>31<br>24 23<br>16 15<br>8 7<br>0<br>1st word<br>2nd word<br>3rd word<br>4th word<br>001<br>31<br>16 15<br>0<br>1st word<br>2nd word<br>010<br>31<br>18 17<br>0<br>Invalid<br>Valid<br>011<br>31<br>20 19<br>0<br>Invalid<br>Valid<br>100<br>31<br>22 21<br>24 23<br>0<br>Invalid<br>Valid<br>101<br>31<br>0<br>Invalid<br>Valid<br>110<br>31<br>0<br>Valid|
|8<br>DEL<br>0<br>R/W|Serial Data Delay<br>0: 1 clock cycle delay between SSIWS and SSIDATA|

1: No delay between SSIWS and SSIDATA

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7 to 4|CKDV[3:0]|0000|R/W|Serial Oversampling Clock Division Ratio|
|||||Sets the ratio between the oversampling clock (AUDIOφ) and the serial bit|
|||||clock. When the SCKD bit is 0, the setting of these bits is ignored. The serial|
|||||bit clock is used in the shift register and is supplied from the SSISCK pin.|
|||||0000: AUDIOφ|
|||||0001: AUDIOφ/2|
|||||0010: AUDIOφ/4|
|||||0011: AUDIOφ/8|
|||||0100: AUDIOφ/16|
|||||0101: AUDIOφ/32|
|||||0110: AUDIOφ/64|
|||||0111: AUDIOφ/128|
|||||1000: AUDIOφ/6|
|||||1001: AUDIOφ/12|
|||||1010: AUDIOφ/24|
|||||1011: AUDIOφ/48|
|||||1100: AUDIOφ/96|
|||||1101: Setting prohibited|
|||||1110: Setting prohibited|
|||||1111: Setting prohibited|
|3|MUEN|0|R/W|Mute Enable|
|||||This bit is used to specify muting of the signals from this module during|
|||||transmission. It is also used to specify the logical value to be output from the|
|||||SSITxD pin when the MUEN bit is set to 0 with transfer disabled in WS|
|||||continue mode.|
|||||0: This module is not muted.|
|||||1: This module is muted.|
|||||Note: When this module is muted, serial data to be output is rewritten to 0|
|||||but data transmission in the module is not stopped. Write dummy data|
|||||to the SSIFTDR not to generate a transmit underflow because the|
|||||number of data in the transmit FIFO is decreasing.|
|2|―|0|R|Reserved|
|||||The read value is undefined. The write value should always be 0.|
|1|TEN|0|R/W|Transmit Enable|
|||||0: Disables the transmit operation.|
|||||1: Enables the transmit operation.|
|||||Note: When transmission stop/start is controlled by the SSI control register|
|||||(SSICTRL_CIM) in the SCUX, set this bit to 0.|
|0|REN|0|R/W|Receive Enable|
|||||0: Disables the receive operation.|
|||||1: Enables the receive operation.|
|||||Note: When reception stop/start is controlled by the SSI control register|
|||||(SSICTRL_CIM) in the SCUX, set this bit to 0.|

## 19.3.2 Status Register (SSISR)

SSISR consists of status flags indicating the operational status of this module and bits indicating the current channel numbers and word numbers.

|Bit:|31||30|29<br>28|27<br>26|25||24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-||-|TUIRQ TOIRQ|RUIRQ ROIRQ|IIRQ||-|-|-|-|-|-|-|-|-|
|Initial value:|UndefinedUndefined<br>0<br>0||||0<br>0|1|Undefined||Undefined|UndefinedUndefinedUndefinedUndefinedUndefinedUndefinedUndefined|||||||
|R/W:|R||R|R/(W)*R/(W)*|R/(W)*R/(W)*|R||R|R|R|R|R|R|R|R|R|
|Bit:|15||14|13<br>12|11<br>10|9||8|7|6|5|4|3|2|1|0|
||-||-|-<br>-|-<br>-|-||-|-|TCHNO[1:0]||TSWNO|RCHNO[1:0]||RSWNO IDST||
|Initial value:|UndefinedUndefinedUndefinedUndefined<br>UndefinedUndefinedUndefinedUndefinedUndefined|||||||||0|0|1|0|0|1|1|
|R/W:|R||R|R<br>R|R<br>R|R||R|R|R|R|R|R|R|R|R|
|Note:*||The bit can be read or written to. Writing 0 initializes|||||the bit, but writing|||1 is ignored.|||||||

|**Bit**||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|
|31,|30|―|Undefined|R|Reserved|
||||||The read value is undefined. The write value should always be 0.|
|29||TUIRQ|0|R/(W)*|Transmit Underflow Error Interrupt Status Flag|
||||||This status flag indicates that transmit data was supplied at a lower rate than|
||||||was required.|
||||||This bit is set to 1 regardless of the value of the TUIEN bit and can be|
||||||cleared by writing 0 to this bit.|
||||||If TUIRQ = 1 and TUIEN = 1, an SSI interrupt occurs.|
||||||If TUIRQ = 1, SSITDR did not have data written to it before it was required|
||||||for transmission. This will lead to the same data being transmitted once|
||||||more and a potential corruption of multi-channel data. As a result, this|
||||||module will output erroneous data.|
||||||Note: When an underflow error occurs, the current data in the data buffer of|
||||||this module is transmitted until the next data is written.|
|28||TOIRQ|0|R/(W)*|Transmit Overflow Error Interrupt Status Flag|
||||||This status flag indicates that transmit data was supplied at a higher rate|
||||||than was required.|
||||||This bit is set to 1 regardless of the value of the TOIEN bit and can be|
||||||cleared by writing 0 to this bit.|
||||||If TOIRQ = 1 and TOIEN = 1, an SSI interrupt occurs.|
||||||If TOIRQ = 1, SSIFTDR had data written to it while the transmit FIFO is full|
||||||(TDC = H'8). This will lead to the loss of data and a potential corruption of|
||||||multi-channel data.|
|27||RUIRQ|0|R/(W)*|Receive Underflow Error Interrupt Status Flag|
||||||This status flag indicates that receive data was supplied at a lower rate than|
||||||was required.|
||||||This bit is set to 1 regardless of the value of the RUIEN bit and can be|
||||||cleared by writing 0 to this bit.|
||||||If RUIRQ = 1 and RUIEN = 1, an SSI interrupt occurs.|
||||||If RUIRQ = 1, SSIFRDR was read while the receive FIFO is empty (RDC =|
||||||H'0).This can cause invalid receive data to be stored, which may lead to|
||||||corruption of multi-channel data.|
|26||ROIRQ|0|R/(W)*|Receive Overflow Error Interrupt Status Flag|
||||||This status flag indicates that receive data was supplied at a higher rate than|
||||||was required.|
||||||This bit is set to 1 regardless of the value of the ROIEN bit and can be|
||||||cleared by writing 0 to this bit.|
||||||If ROIRQ = 1 and ROIEN = 1, an SSI interrupt occurs.|
||||||If ROIRQ = 1, SSIRDR was not read before there was new unread data|
||||||written to it. This will lead to the loss of data and a potential corruption of|
||||||multi-channel data.|
||||||Note: When an overflow error occurs, the current data in the data buffer of|
||||||this module is overwritten by the next incoming data from the SSI|
||||||interface.|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|25|IIRQ|1|R|Idle Mode Interrupt Status Flag|
|||||This status flag indicates whether this module is in the idle state.|
|||||This bit is set to 1 regardless of the value of the IIEN bit to allow polling.|
|||||The interrupt can be masked by clearing IIEN to 0, but cannot be cleared by|
|||||writing 0 to this bit.|
|||||If IIRQ = 1 and IIEN = 1, an SSI interrupt occurs.|
|||||0: This module is not in idle state.|
|||||1: This module is in idle state.|
|24 to 7|―|Undefined|R|Reserved|
|||||The read value is undefined. The write value should always be 0.|
|6, 5|TCHNO|00|R|Transmit Channel Number|
||[1:0]|||These bits show the current channel number.|
|||||These bits indicate the number of a channel whose data is required to be|
|||||written to SSITDR. This value will change as the data is copied to the shift|
|||||register, regardless of whether the data is written to SSITDR.|
|||||When TDM or CONT is 1, these bits cannot be used.|
|4|TSWNO|1|R|Transmit Serial Word Number|
|||||This status bit indicates the current word number.|
|||||This bit indicates which system word is required to be written to SSITDR.|
|||||This value will change as the data is copied to the shift register, regardless of|
|||||whether the data is written to SSITDR.|
|||||When TDM or CONT is 1, this bit cannot be used.|
|3, 2|RCHNO|00|R|Receive Channel Number|
||[1:0]|||These bits show the current channel number.|
|||||These bits indicate which channel the data in SSIRDR currently represents.|
|||||This value will change as the data in SSIRDR is updated from the shift|
|||||register.|
|||||When TDM or CONT is 1, these bits cannot be used.|
|1|RSWNO|1|R|Receive Serial Word Number|
|||||This status bit indicates the current word number.|
|||||This bit indicates which system word the data in SSIRDR currently|
|||||represents. This value will change as the data in SSIRDR is updated from|
|||||the shift register, regardless of whether SSIRDR has been read.|
|||||When TDM or CONT is 1, this bit cannot be used.|
|0|IDST|1|R|Idle Mode Status Flag|
|||||This status flag indicates that the serial bus activity has stopped.|
|||||This bit is cleared to 0 if the serial bus is currently active while TEN = 1 or|
|||||REN = 1.|
|||||This bit is automatically set to 1 if both TEN and REN are cleared to 0 and|
|||||the current system word communication is completed.|
|||||Note: If the external device stops the serial bus clock before the current|
|||||system word is completed, this bit is not set.|

Note: * The bit can be read or written to. Writing 0 initializes the bit, but writing 1 is ignored.

## 19.3.3 Transmit Data Register (SSITDR)

SSITDR is a 32-bit register that stores data to be transmitted. The data for transmission to be stored to SSITDR is automatically transferred from the transmit FIFO data register.

Data written to this register is transferred to the shift register upon transmission request. If the data word length is less than 32 bits, the alignment is determined by the setting of the PDTA control bit in SSICR. The CPU cannot read or write data from/to SSITDR.

**==> picture [406 x 97] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>Initial value: - - - - - - - - - - - - - - - -<br>R/W: - - - - - - - - - - - - - - - -<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>Initial value: - - - - - - - - - - - - - - - -<br>R/W: - - - - - - - - - - - - - - - -<br>**----- End of picture text -----**<br>

## 19.3.4 Receive Data Register (SSIRDR)

SSIRDR is a 32-bit register that stores received data. The received data stored in SSIRDR is automatically transferred to the receive FIFO data register.

Data in this register is transferred from the shift register each time data word is received. If the data word length is less than 32 bits, the alignment is determined by the setting of the PDTA control bit in SSICR.

The CPU cannot read or write data from/to SSIRDR.

**==> picture [406 x 98] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>Initial value: - - - - - - - - - - - - - - - -<br>R/W: - - - - - - - - - - - - - - - -<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>Initial value: - - - - - - - - - - - - - - - -<br>R/W: - - - - - - - - - - - - - - - -<br>**----- End of picture text -----**<br>

## 19.3.5 FIFO Control Register (SSIFCR)

SSIFCR is a 32-bit readable/writable register that specifies the data trigger numbers for the transmit and receive FIFO data registers, and enables or disables FIFO data resets and interrupt requests. SSIFCR can always be read or written by the CPU.

**==> picture [483 x 80] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>- - - - - - - - - - - - - - - -<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>- - - - - - - - TTRG[1:0] RTRG[1:0] TIE RIE TFRST RFRST<br>**----- End of picture text -----**<br>

||||||||||
|---|---|---|---|---|---|---|---|---|
||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|
||R/W:|R|R|R|R|R|R|R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|
|||||**Initial**|||||
|**Bit**|**Bit Name**|||**Value**||**R/W**||**Description**|
|31 to 8|―|||All 0||R||Reserved|
|||||||||These bits are always read as 0. The write value should always be 0.|
|7, 6|TTRG[1:0]|||00||R/W||Transmit Data Trigger Number|
|||||||||When the FIFO is operating for transmission, these bits specify the number|
|||||||||of bytes for transmission in the FIFO (trigger number for transmission) at|
|||||||||which the TDE flag in the FIFO status register (SSIFSR) will be set. The TDE|
|||||||||flag is set to 1 when the number of bytes for transmission in the transmit|
|||||||||FIFO data register (SSIFTDR) has fallen to or below the trigger number|
|||||||||corresponding to the setting as shown below.|
|||||||||00: 7 (1)*|
|||||||||01: 6 (2)*|
|||||||||10: 4 (4)*|
|||||||||11: 2 (6)*|
|||||||||Note: * The values in parentheses are the number of empty stages in|
|||||||||SSIFTDR at which the TDE flag is set.|
|5, 4|RTRG[1:0]|||00||R/W||Receive Data Trigger Number|
|||||||||When the FIFO is operating for reception, these bits specify the number of|
|||||||||received bytes in the FIFO (trigger number for reception) at which the RDF|
|||||||||flag in the FIFO status register (SSIFSR) will be set. The RDF flag is set to 1|
|||||||||when the number of received bytes in the receive FIFO data register|
|||||||||(SSIFRDR) has risen to or above the trigger number corresponding to the|
|||||||||setting as shown below.|
|||||||||00: 1|
|||||||||01: 2|
|||||||||10: 4|
|||||||||11: 6|
|3|TIE|||0||R/W||Transmit Interrupt Enable|
|||||||||This bit enables or disables generation of transmit data empty interrupt (TXI)|
|||||||||requests in the following situation: when the FIFO is operating for|
|||||||||transmission, the data for transmission in the transmit FIFO data register|
|||||||||(SSIFTDR) are transferred to the transmit data register (SSITDR) and the|
|||||||||number of data bytes in the transmit FIFO data register has become less|
|||||||||than the set transmit trigger number, so that the TDE flag in the FIFO status|
|||||||||register (SSIFSR) is set to 1.|
|||||||||0: Transmit data empty interrupt (TXI) request is disabled.|
|||||||||1: Transmit data empty interrupt (TXI) request is enabled.*|
|||||||||Note: * TXI can be cleared by clearing either the TDE flag (see the|
|||||||||description of the TDE bit for details) or TIE bit to 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|2|RIE|0|R/W|Receive Interrupt Enable|
|||||Enables or disables generation of receive data full interrupt (RXI) requests|
|||||when the RDF flag in the FIFO status register (SSIFSR) is set to 1 while the|
|||||FIFO is operating for reception.|
|||||0: Receive data full interrupt (RXI) request is disabled.|
|||||1: Receive data full interrupt (RXI) request is enabled.*|
|||||Note: * RXI can be cleared by clearing either the RDF flag (see the|
|||||description of the RDF bit for details) or RIE bit to 0.|
|1|TFRST|0|R/W|Transmit FIFO Data Register Reset|
|||||Invalidates the data in the transmit FIFO data register (SSIFTDR) to reset|
|||||the FIFO to an empty state.|
|||||0: Reset is disabled.*|
|||||1: Reset is enabled.|
|||||Note: * FIFO is reset at a power-on reset.|
|0|RFRST|0|R/W|Receive FIFO Data Register Reset|
|||||Invalidates the data in the receive FIFO data register (SSIFRDR) to reset the|
|||||FIFO to an empty state.|
|||||0: Reset is disabled.*|
|||||1: Reset is enabled.|
|||||Note: * FIFO is reset at a power-on reset.|

## 19.3.6 FIFO Status Register (SSIFSR)

SSIFSR contains status flags that indicate the state of operation of the transmit and receive FIFO data registers.

**==> picture [483 x 80] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>- - - - TDC[3:0] - - - - - - - TDE<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1<br>R/W: R R R R R R R R R R R R R R R R/(W)*<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>- - - - RDC[3:0] - - - - - - - RDF<br>**----- End of picture text -----**<br>

||||||||||
|---|---|---|---|---|---|---|---|---|
||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|
||R/W:|R|R|R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/(W)*|
|||||**Initial**|||||
|**Bit**|**Bit Name**|||**Value**||**R/W**||**Description**|
|31 to 28|―|||All 0||R||Reserved|
|||||||||These bits are always read as 0. The write value should always be 0.|
|27 to 24|TDC[3:0]|||0000||R||Number of Data Bytes Stored in SSIFTDR|
|||||||||TDC[3:0] = H'0 indicates no data for transmission.|
|||||||||TDC[3:0] = H'8 indicates that 32 bytes of data for transmission is stored in|
|||||||||SSIFTDR.|
|23 to 17|―|||All 0||R||Reserved|
|||||||||These bits are always read as 0. The write value should always be 0.|
|16|TDE|||1||R/(W)*||Transmit Data Empty|
|||||||||Indicates that, when the FIFO is operating for transmission, the data for|
|||||||||transmission in the transmit FIFO data register (SSIFTDR) is transferred to|
|||||||||the transmit data register (SSITDR), the number of data bytes in SSIFTDR|
|||||||||has become less than the transmit trigger number specified by TTRG[1:0] in|
|||||||||the FIFO control register (SSIFCR), and thus writing of transmit data to|
|||||||||SSIFTDR has been enabled.|
|||||||||0: Number of data bytes for transmission in SSIFTDR is greater than the set|
|||||||||transmit trigger number.|
|||||||||[Clearing conditions]|
|||||||||0 is written to TDE after data of the number of bytes larger than the set|
|||||||||transmit trigger number is written to SSIFTDR.|
|||||||||The direct memory access controller is activated by transmit data empty|
|||||||||(TXI) interrupt, and data of the number of bytes larger than the set transmit|
|||||||||trigger number is written to SSIFTDR.|
|||||||||1: Number of data bytes for transmission in SSIFTDR is equal to or less than|
|||||||||the set transmit trigger number.*1|
|||||||||[Setting conditions]|
|||||||||Power-on reset|
|||||||||Number of transmission data bytes stored in SSIFTDR has become equal|
|||||||||to or less than the set transmit trigger number.|
|||||||||Note: *1 Since SSIFTDR is an 8-stage FIFO register, the amount of data|
|||||||||that can be written to it while TDE = 1 is "8 – transmit trigger|
|||||||||number to be specified" bytes at maximum. Writing more data will|
|||||||||be ignored. The number of data bytes in SSIFTDR is indicated in|
|||||||||the TDC bits in SSIFSR.|
|15 to 12|―|||All 0||R||Reserved|
|||||||||These bits are always read as 0. The write value should always be 0.|
|11 to 8|RDC[3:0]|||0000||R||Number of Data Bytes Stored in SSIFRDR|
|||||||||RDC[3:0] = H'0 indicates no received data.|
|||||||||RDC[3:0] = H'8 indicates that 32 bytes of received data is stored in|
|||||||||SSIFRDR.|
|7 to 1|―|||All 0||R||Reserved|
|||||||||These bits are always read as 0. The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|0|RDF|0|R/(W)*|Receive Data Full|
|||||Indicates that, when the FIFO is operating for reception, the received data is|
|||||transferred to the receive FIFO data register (SSIFRDR) and the number of|
|||||data bytes in SSIFRDR has become greater than the receive trigger number|
|||||specified by RTRG[1:0] in the FIFO control register (SSIFCR).|
|||||0: Number of received data bytes in SSIFRDR is less than the set receive|
|||||trigger number.|
|||||[Clearing conditions]|
|||||Power-on reset|
|||||0 is written to RDF after the receive FIFO is emptied with writing 1 to|
|||||RFRST.|
|||||0 is written to RDF after data is read from SSIFRDR until the number of|
|||||data bytes in SSIFRDR becomes less than the set receive trigger number.|
|||||The direct memory access controller is activated by receive data full (RXI)|
|||||interrupt, and data is read from SSIFRDR until the number of data bytes in|
|||||SSIFRDR becomes less than the set receive trigger number.|
|||||1: Number of received data bytes in SSIFRDR is equal to or greater than the|
|||||set receive trigger number.|
|||||[Setting condition]|
|||||Data of the number of bytes that is equal to or greater than the set receive|
|||||trigger number is stored in SSIFRDR.*1|
|||||Note: *1 Since SSIFRDR is an 8-stage FIFO register, the amount of data|
|||||that can be read from it while RDF = 1 is the set receive trigger|
|||||number of bytes at maximum.|
|||||Continuing to read data from SSIFRDR after reading all the data|
|||||will result in undefined data to be read. The number of data bytes|
|||||in SSIFRDR is indicated in the RDC bits in SSIFSR.|

Note: * The bit can be read or written to. Writing 0 initializes the bit, but writing 1 is ignored.

## 19.3.7 Transmit FIFO Data Register (SSIFTDR)

SSIFTDR is a FIFO register consisting of eight stages of 32-bit registers for storing data to be serially transmitted. On detecting that the transmit data register (SSITDR) is empty, this module transfers the data for transmission written to SSIFTDR to SSITDR to start serial transmission, which can continue until SSIFTDR becomes empty. SSIFTDR can be written to by the CPU at any time.

Note that when SSIFTDR is full of transmit data (32 bytes), the next data cannot be written to it. If writing is attempted, it will be ignored and an overflow occurs.

**==> picture [406 x 117] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>Initial value: - - - - - - - - - - - - - - - -<br>R/W: W W W W W W W W W W W W W W W W<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>Initial value: - - - - - - - - - - - - - - - -<br>R/W: W W W W W W W W W W W W W W W W<br>Note: * Not writable while FIFO is receiving data.<br>**----- End of picture text -----**<br>

## 19.3.8 Receive FIFO Data Register (SSIFRDR)

SSIFRDR is a FIFO register consisting of eight stages of 32-bit registers for storing serially received data. When four bytes of data have been received, this module transfers the received data in the receive data register (SSIRDR) to SSIFRDR to complete reception operation. Reception can continue until 32 bytes of data have been stored to SSIFRDR. SSIFRDR can be read but cannot be written to by the CPU. Note that when SSIFRDR is read while it does not hold received data, the value read is undefined and a reception underflow will occur.

After SSIFRDR becomes full of received data, the data received thereafter will be lost and a receive overflow occurs.

**==> picture [406 x 98] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>Initial value: - - - - - - - - - - - - - - - -<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>Initial value: - - - - - - - - - - - - - - - -<br>R/W: R R R R R R R R R R R R R R R R<br>**----- End of picture text -----**<br>

## 19.3.9 TDM Mode Register (SSITDMR)

SSITDMR is a 32-bit readable/writable register that enables or disables muting of receive data in direct transfer, TDM mode, and WS continue mode.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|-|-|-|-|-|-|-|-|-|-|-|-|RXD|-|
|||||||||||||||||MUTE||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||-|-|-|-|-|-|-|CONT|-|-|-|-|-|-|-|TDM|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R/W|R|R|R|R|R|R|R|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 18|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|17|RXDMUTE|0|R/W|Receive Direct Data Mute Setting|
|||||When receive data is output directly to the SCUX, the output data is forcibly|
|||||muted so that there is no signal (output as 0 data).|
|||||0: The receive data is output without change.|
|||||1: 0 data is output.|
|16|―|0|R/W|Reserved|
|||||Always write 0 to this bit.|
|15 to 9|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|CONT|0|R/W|WS Continue Mode|
|||||0: Disables WS continue mode.|
|||||1: Enables WS continue mode.|
|||||Note: This bit can be set only in master mode|
|||||(SCKD = 1 and SWSD = 1)|
|7 to 1|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|TDM|0|R/W|TDM Mode|
|||||0: Disables TDM mode.|
|||||1: Enables TDM mode.|

## 19.3.10 FC Control Register (SSIFCCR)

SSIFCCR is a 32-bit readable/writable register that controls frequency change detection.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|FIEN|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|FCEN|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|17|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|16|||FIEN|0|R/W|Frequency Change Detection Interrupt Enable|
|||||||0: Disables a frequency change detection interrupt.|
|||||||1: Enables a frequency change detection interrupt.|
|15|to|1|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||FCEN|0|R/W|Frequency Change Detection Enable|
|||||||When this bit is set to 1, counting up of cycles of peripheral clock 1 (P1φ)|
|||||||starts at the beginning of the next SSIWS cycle. On the start of each SSIWS|
|||||||cycle, the current counted value is moved to the VALUE bits in the FC Status|
|||||||Register (SSIFCSR). The counter is then cleared to 0 and counting up is|
|||||||resumed. When this bit is set to 0, the counter is cleared to 0 and counting|
|||||||up is stopped.|
|||||||0: Disables frequency change detection.|
|||||||1: Enables frequency change detection.|
|||||||Note: Set this bit to 1 after setting the desired values in SSICR, SSIFCMR,|
|||||||and SSITDMR.|

## 19.3.11 FC Mode Register (SSIFCMR)

SSIFCMR sets the maximum and minimum allowable numbers of cycles of the peripheral clock 1 (P1  ) for each SSIWS cycle, when frequency change detection is enabled.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|||||||MAXV||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||-|-|||||||MINV||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31, 30|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|29 to 16|MAXV|0|R/W|Maximum Value|
|||||Sets the maximum allowable number of cycles of the peripheral clock 1|
|||||(P1φ) for each SSIWS cycle, when SSIFCCR.FCEN = 1.|
|15, 14|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|13 to 0|MINV|0|R/W|Minimum Value|
|||||Sets the minimum allowable number of cycles of the peripheral clock 1|
|||||(P1φ) for each SSIWS cycle, when SSIFCCR.FCEN = 1.|

## 19.3.12 FC Status Register (SSIFCSR)

SSIFCSR consists of the frequency change detection status flag and the bits that indicate the current cycle count of the peripheral clock 1 (P1  ).

|l clock 1 (|l clock 1 (|P1)|.|||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|Bit:||31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||-|-|-|-|-|-|-|FCIRQ|-|-|-|-|-|-|-|-|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R/(W)*|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||-|-|||||||VALUE||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|25|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|24|||FCIRQ|0|R/(W)*|Frequency Change Detection Error Interrupt Status|
|||||||Indicates VALUE > SSIFCMR.MAXV or 0 < VALUE < SSIFCMR.MINV when|
|||||||SSIFCCR.FCEN = 1.|
|||||||This bit is set to 1 regardless of the setting of the FIEN bit in SSIFCCR. Write|
|||||||0 to clear this flag to 0.|
|||||||When FCIRQ = 1 and SSIFCCR.FIEN = 1, an SSI interrupt is generated.|
|23|to|14|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|13|to|0|VALUE|0|R|VALUE|
|||||||Indicates the current cycle count of the peripheral clock 1 (P1φ) in an SSIWS|
|||||||cycle, when SSIFCCR.FCEN = 1. Each time the next SSIWS cycle starts,|
|||||||the value is updated.|
|||||||Note: When the SSISCK signal stops, the start of an SSIWS cycle cannot be|
|||||||detected. Consequently, the value is not updated.|

Note: * The bit can be read or written to. Writing 0 initializes the bit, but writing 1 is ignored.

## 19.4 Operation Description

## 19.4.1 Bus Format

This module can operate as a transmitter or a receiver and can be configured into many serial bus formats in either mode. The bus format can be selected from one of the twelve major modes shown in Table 19.3 .

## **Table 19.3 Bus Format for SSIF Module**

||**TEN**|**REN**|**SCKD**|**SWSD**|**TDM**|**MUEN**|**IIEN**|**TOIEN**|**TUIEN**|**ROIEN**|**RUIEN**|**CONT**|**SWSP**|**DEL**|**PDTA**|**SDTA**|**SPDP**|**SCKP**|**SWL[2:0]**|**DWL[2:0]**|**CHNL[1:0]**|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|Non-Compression Slave<br>Receiver|0|1|0|0|0|Control Bits|||||||Configuration Bits|||||||||
|Non-Compression Slave<br>Transmitter|1|0|0|0|0|||||||||||||||||
|Non-Compression Slave<br>Transceiver*|1|1|0|0|0|||||||||||||||||
|Non-Compression Master<br>Receiver|0|1|1|1|0|||||||||||||||||
|Non-Compression Master<br>Transmitter|1|0|1|1|0|||||||||||||||||
|Non-Compression Master<br>Transceiver*|1|1|1|1|0|||||||||||||||||
|TDM Slave Receiver|0|1|0|0|1||||||||0|Configuration Bits||||||||
|TDM Slave Transmitter|1|0|0|0|1||||||||0|||||||||
|TDM Slave Transceiver*|1|1|0|0|1||||||||0|||||||||
|TDM Master Receiver|0|1|1|1|1||||||||0|||||||||
|TDM Master Transmitter|1|0|1|1|1||||||||0|||||||||
|TDM Master Transceiver*|1|1|1|1|1||||||||0|||||||||

Note: * Set the TEN and REN bits to 1 at the same time when using transceiver mode.

## 19.4.2 Non-Compressed Modes

The non-compressed modes support all serial audio streams split into channels. It supports the I[2] S compatible format as well as many more variants on these modes.

## (1) Slave Receiver

This mode allows the module to receive serial data from another device. The clock and word select signal used for the serial data stream is also supplied from an external device. If these signals do not conform to the format specified in the configuration fields of this module, operation is not guaranteed.

## (2) Slave Transmitter

This mode allows the module to transmit serial data to another device. The clock and word select signal used for the serial data stream is also supplied from an external device. If these signals do not conform to the format specified in the configuration fields of this module, operation is not guaranteed.

## (3) Slave Transceiver

This mode allows serial data transmission and reception between this module and another device. The clock and word select signal used for the serial data stream is also supplied from an external device. If these signals do not conform to the format specified in the configuration fields of this module, operation is not guaranteed.

## (4) Master Receiver

This mode allows the module to receive serial data from another device. The clock and word select signals are internally derived from the oversampling clock. The format of these signals is defined in the configuration fields of this module. If the incoming data from another device does not follow the configured format, operation is not guaranteed.

## (5) Master Transmitter

This mode allows the module to transmit serial data to another device. The clock and word select signals are internally derived from the oversampling clock. The format of these signals is defined in the configuration fields of this module.

## (6) Master Transceiver

This mode allows serial data transmission and reception between this module and another device. The clock and word select signals are internally derived from the oversampling clock. The format of these signals is defined in the configuration fields of this module.

## (7) Operation Setting Related to Word Length

All bits related to the SSICR's word length are valid in non-compressed modes. There are many configurations this module supports, but some of the combinations are shown below for the I[2] S compatible format, MSB-first and leftaligned format, and MSB-first and right-aligned format.

 I[2] S Compatible Format Figure 19.2 and Figure 19.3 show the I[2] S compatible formats without and with padding, respectively. Padding occurs when the data word length is smaller than the system word length.

**==> picture [314 x 122] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCKP = 0, SWSP = 0, DEL = 0, CHNL = 00<br>System word length = data word length<br>SSISCK<br>SSIWS<br>SSIDATA prev. sample MSB LSB+ 1 LSB MSB LSB+ 1 LSB next sample<br>System word 1 = System word 2 =<br>data word 1 data word 2<br>**----- End of picture text -----**<br>

**Figure 19.2 I[2] S Compatible Format (without Padding)**

**==> picture [341 x 135] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCKP = 0, SWSP = 0, DEL = 0, CHNL = 00, SPDP = 0, SDTA = 0<br>System word length > data word length<br>SSISCK<br>SSIWS<br>SSIDATA MSB LSB MSB LSB Next<br>Data word 1 Padding Data word 2 Padding<br>System word 1 System word 2<br>**----- End of picture text -----**<br>

**Figure 19.3 I[2] S Compatible Format (with Padding)**

Figure 19.4 shows the MSB-first and left-aligned format and Figure 19.5 shows the MSB-first and right-aligned format.

- MSB-first and Left-aligned Format

**==> picture [344 x 136] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCKP = 0, SWSP = 0, DEL = 1, CHNL = 00, SPDP = 0, SDTA = 0<br>System word length > data word length<br>SSISCK<br>SSIWS<br>SSIDATA MSB LSB MSB LSB Next<br>Data word 1 Padding Data word 2 Padding<br>System word 1 System word 2<br>**----- End of picture text -----**<br>

**Figure 19.4 MSB-first and Left-aligned Format (Transmitted and Received in the Order of Serial Data and Padding Bits)**

- MSB-first and Right-aligned Format

**==> picture [344 x 135] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCKP = 0, SWSP = 0, DEL = 1, CHNL = 00, SPDP = 0, SDTA = 1<br>System word length > data word length<br>SSISCK<br>SSIWS<br>SSIDATA Prev. MSB LSB MSB LSB<br>Padding Data word 1 Padding Data word 2<br>System word 1 System word 2<br>**----- End of picture text -----**<br>

**Figure 19.5 MSB-first and Right-aligned Format (Transmitted and Received in the Order of Padding Bits and Serial Data)**

## (8) Multi-channel Formats

Some devices extend the definition of the I[2] S bus specification and allow more than 2 channels to be transferred within two system words.

This module supports the transfer of 4, 6, and 8 channels by using the CHNL, SWL and DWL bits only when the system word length (SWL) is greater than or equal to the data word length (DWL) multiplied by channels (CHNL). Table 19.4 shows the number of padding bits for each of the valid setting. If setting is not valid, "  " is indicated instead of a number.

**Table 19.4 The Number of Padding Bits for Each Valid Setting**

|**Table 19.4**<br>**The Number of Padding Bits for Each Valid Setting**|**Table 19.4**<br>**The Number of Padding Bits for Each Valid Setting**|
|---|---|
|**Padding Bits per System Word**<br>**DWL[2:0]**<br>**000**<br>**001**<br>**010**<br>**011**<br>**100**<br>**101**<br>**110**||
|**CHNL**<br>**[1:0]**<br>**Decoded**<br>**Channels per**<br>**System Word**|**SWL**<br>**[2:0]**<br>**Decoded**<br>**Word**<br>**Length**<br>**8**<br>**16**<br>**18**<br>**20**<br>**22**<br>**24**<br>**32**|
|00<br>1|000<br>8<br>0<br>―<br>―<br>―<br>―<br>―<br>―|
||001<br>16<br>8<br>0<br>―<br>―<br>―<br>―<br>―|
||010<br>24<br>16<br>8<br>6<br>4<br>2<br>0<br>―|
||011<br>32<br>24<br>16<br>14<br>12<br>10<br>8<br>0|
||100<br>48<br>40<br>32<br>30<br>28<br>26<br>24<br>16|
||101<br>64<br>56<br>48<br>46<br>44<br>42<br>40<br>32|
||110<br>128<br>120<br>112<br>110<br>108<br>106<br>104<br>96|
||111<br>256<br>248<br>240<br>238<br>236<br>234<br>232<br>224|
|01<br>2|000<br>8<br>―<br>―<br>―<br>―<br>―<br>―<br>―|
||001<br>16<br>0<br>―<br>―<br>―<br>―<br>―<br>―|
||010<br>24<br>8<br>―<br>―<br>―<br>―<br>―<br>―|
||011<br>32<br>16<br>0<br>―<br>―<br>―<br>―<br>―|
||100<br>48<br>32<br>16<br>12<br>8<br>4<br>0<br>―|
||101<br>64<br>48<br>32<br>28<br>24<br>20<br>16<br>0|
||110<br>128<br>112<br>96<br>92<br>88<br>84<br>80<br>64|
||111<br>256<br>240<br>224<br>220<br>216<br>212<br>208<br>192|
|10<br>3|000<br>8<br>―<br>―<br>―<br>―<br>―<br>―<br>―|
||001<br>16<br>―<br>―<br>―<br>―<br>―<br>―<br>―|
||010<br>24<br>0<br>―<br>―<br>―<br>―<br>―<br>―|
||011<br>32<br>8<br>―<br>―<br>―<br>―<br>―<br>―|
||100<br>48<br>24<br>0<br>―<br>―<br>―<br>―<br>―|
||101<br>64<br>40<br>16<br>10<br>4<br>―<br>―<br>―|
||110<br>128<br>104<br>80<br>74<br>68<br>62<br>56<br>32|
||111<br>256<br>232<br>208<br>202<br>196<br>190<br>184<br>160|
|11<br>4|000<br>8<br>―<br>―<br>―<br>―<br>―<br>―<br>―|
||001<br>16<br>―<br>―<br>―<br>―<br>―<br>―<br>―|
||010<br>24<br>―<br>―<br>―<br>―<br>―<br>―<br>―|
||011<br>32<br>0<br>―<br>―<br>―<br>―<br>―<br>―|
||100<br>48<br>16<br>―<br>―<br>―<br>―<br>―<br>―|
||101<br>64<br>32<br>0<br>―<br>―<br>―<br>―<br>―|
||110<br>128<br>96<br>64<br>56<br>48<br>40<br>32<br>0|
||111<br>256<br>224<br>192<br>184<br>176<br>168<br>160<br>128|

When this module acts as a transmitter, each word written to SSITDR is transmitted to the serial audio bus in the order they are written. When this module acts as a receiver, each word received by the serial audio bus is read from the SSIRDR register in the order they are received.

Figure 19.6 to Figure 19.8 show how the data on 4, 6, and 8 channels are transferred to the serial audio bus. Note that there are no padding bits in the first example ( Figure 19.6 ), the second example ( Figure 19.7 ) is left-aligned and the third ( Figure 19.8 ) is right-aligned. The other conditions in these examples have been selected arbitrarily.

SCKP = 0, SWSP = 0, DEL = 0, CHNL = 01, SPDP = don't care, SDTA = don't care System word length = data word length × 2

**==> picture [352 x 110] intentionally omitted <==**

**----- Start of picture text -----**<br>
SSISCK<br>SSIWS<br>SSIDATA LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB<br>Data Data Data Data Data Data Data Data<br>word 1 word 2 word 3 word 4 word 1 word 2 word 3 word 4<br>System word 1 System word 2 System word 1 System word 2<br>**----- End of picture text -----**<br>

**Figure 19.6 Multi-Channel Format (4 Channels Without Padding)**

SCKP = 0, SWSP = 0, DEL = 0, CHNL = 10, SPDP = 1, SDTA = 0 System word length = data word length × 3

**==> picture [357 x 103] intentionally omitted <==**

**----- Start of picture text -----**<br>
SSISCK<br>SSIWS<br>SSIDATA MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB<br>Data Data Data Data Data Data<br>word 1 word 2 word 3 word 4 word 5 word 6<br>System word 1 System word 2<br>Padding Padding<br>**----- End of picture text -----**<br>

**Figure 19.7 Multi-Channel Format (6 Channels with High Padding)**

**==> picture [358 x 132] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCKP = 0, SWSP = 0, DEL = 0, CHNL = 11, SPDP = 0, SDTA = 1<br>System word length > data word length × 4<br>SSISCK<br>SSIWS<br>SSIDATA MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB<br>Data Data Data Data Data Data Data Data<br>word 1 word 2 word 3 word 4 word 5 word 6 word 7 word 8<br>System word 1 System word 2<br>Padding Padding<br>**----- End of picture text -----**<br>

**Figure 19.8 Multi-Channel Format (8 Channels; Transmitting and Receiving in the Order of Padding Bits and Serial Data ; with Padding)**

## (9) Operation Format Configuration Bits

Several more configuration bits in non-compressed mode are shown below. These bits are not mutually exclusive, but some combinations may not be useful.

These configuration bits are described below with reference to the basic sample format in Figure 19.9 .

**==> picture [365 x 203] intentionally omitted <==**

**----- Start of picture text -----**<br>
SWL = 6 bits (not attainable in SSI module, demonstration only)<br>DWL = 4 bits (not attainable in SSI module, demonstration only)<br>CHNL = 00, SCKP = 0, SWSP = 0, SPDP = 0, SDTA = 0, PDTA = 0, DEL = 0, MUEN = 0<br>4-bit data samples continuously written to SSITDR are transmitted onto the serial audio bus.<br>SSISCK<br>SSIWS 1st channel 2nd channel<br>SSIDATA TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31<br>Key for this and following diagrams:<br>Arrow head indicates sampling point of receiver<br>TDn Bit n in SSITDR<br>0 means a low level on the serial bus (padding or mute)<br>1  means a high level on the serial bus (padding)<br>**----- End of picture text -----**<br>

**Figure 19.9 Basic Sample Format (Transmit Mode with Example System/Data Word Length)**

Figure 19.9 uses a system word length of 6 bits and a data word length of 4 bits. These settings are not possible with this module but are used as an example only for clarification of the other configuration bits.

- Inverted Clock

**==> picture [364 x 88] intentionally omitted <==**

**----- Start of picture text -----**<br>
Same as basic sample format configuration except SCKP = 1<br>SSISCK<br>SSIWS 1st Channel 2nd Channel<br>SSIDATA TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31<br>**----- End of picture text -----**<br>

**Figure 19.10 Inverted Clock**

- Inverted Word Select

**==> picture [365 x 89] intentionally omitted <==**

**----- Start of picture text -----**<br>
Same as basic sample format configuration except SWSP = 1<br>SSISCK<br>SSIWS 1st Channel 2nd Channel<br>SSIDATA TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31<br>**----- End of picture text -----**<br>

**Figure 19.11 Inverted Word Select**

- Inverted Padding Polarity

**==> picture [364 x 88] intentionally omitted <==**

**----- Start of picture text -----**<br>
Same as basic sample format configuration except SPDP = 1<br>SSISCK<br>SSIWS 1st Channel 2nd Channel<br>SSIDATA TD28 1 1 TD31 TD30 TD29 TD28 1 1 TD31 TD30 TD29 TD28 1 1 TD31<br>**----- End of picture text -----**<br>

**Figure 19.12 Inverted Padding Polarity**

- Transmitting and Receiving in the Order of Padding Bits and Serial Data; with Delay

**==> picture [364 x 89] intentionally omitted <==**

**----- Start of picture text -----**<br>
Same as basic sample format configuration except SDTA = 1<br>SSISCK<br>SSIWS 1st Channel 2nd Channel<br>SSIDATA TD30 TD29 TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31 TD30 TD29 TD28 0<br>**----- End of picture text -----**<br>

**Figure 19.13 Transmitting and Receiving in the Order of Padding Bits and Serial Data; with Delay**

- Transmitting and Receiving in the Order of Padding Bits and Serial Data; without Delay

**==> picture [366 x 90] intentionally omitted <==**

**----- Start of picture text -----**<br>
Same as basic sample format configuration except SDTA = 1 and DEL = 1<br>SSISCK<br>SSIWS 1st Channel 2nd Channel<br>SSIDATA TD29 TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31 TD30 TD29 TD28 0 0<br>**----- End of picture text -----**<br>

**Figure 19.14 Transmitting and Receiving in the Order of Padding Bits and Serial Data; without Delay**

- Transmitting and Receiving in the Order of Serial Data and Padding Bits; without Delay

**==> picture [365 x 88] intentionally omitted <==**

**----- Start of picture text -----**<br>
Same as basic sample format configuration except DEL = 1<br>SSISCK<br>SSIWS 1st Channel 2nd Channel<br>SSIDATA 0 0 TD31 TD30 TD29 TD28 0 0 TD31 TD30 TD29 TD28 0 0 TD31 TD30<br>**----- End of picture text -----**<br>

**Figure 19.15 Transmitting and Receiving in the Order of Serial Data and Padding Bits; without Delay**

- Parallel Right-Aligned with Delay

**==> picture [364 x 89] intentionally omitted <==**

**----- Start of picture text -----**<br>
Same as basic sample format configuration except PDTA = 1<br>SSISCK<br>SSIWS 1st Channel 2nd Channel<br>SSIDATA TD0 0 0 TD3 TD2 TD1 TD0 0 0 TD3 TD2 TD1 TD0 0 0 TD3<br>**----- End of picture text -----**<br>

**Figure 19.16 Parallel Right-Aligned with Delay**

- Mute Enabled

**==> picture [366 x 88] intentionally omitted <==**

**----- Start of picture text -----**<br>
Same as basic sample format configuration except MUEN = 1 (TD data ignored)<br>SSISCK<br>SSIWS 1st Channel 2nd Channel<br>SSIDATA 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>**----- End of picture text -----**<br>

**Figure 19.17 Mute Enabled**

## 19.4.3 TDM Mode

TDM mode is provided to enable connection to multi-channel devices for TDM. This mode can be set using the TDM bit in the TDM mode register (SSITDMR). In this mode, the SSIWS signal is high only for system word 1 period and low for the other periods. The pulse produced on the SSIWS signal is defined as SYNC pulse. Note that the SYNC pulse always has the positive polarity (high only for system word 1 period).

Figure 19.18 and Figure 19.19 show the TDM formats without and with padding, respectively.

**==> picture [365 x 104] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCKP = 0, SWSP = 0, DEL = 1, CHNL = 10, SPDP = don't care, SDTA = don't care, TDM = 1<br>System word length = data word length<br>SSISCK<br>SSIWS<br>SSIDATA LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB<br>Data word 1 =  Data word 2 =  Data word 3 =  Data word 4 =  Data word 5 =  Data word 6 =<br>system word 1 system word 2 system word 3 system word 4 system word 5 system word 6<br>TDM frame<br>**----- End of picture text -----**<br>

**Figure 19.18 TDM Format (6 system words, no padding)**

**==> picture [368 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
SCKP = 0, SWSP = 0, DEL = 1, CHNL = 10, SPDP = 1, SDTA = 0, TDM = 1<br>System word length > data word length<br>SSISCK<br>SSIWS<br>SSIDATA MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB LSB MSB<br>Data word 1 Data word 2 Data word 3 Data word 4 Data word 5 Data word 6<br>System word 1 System word 2 System word 3 System word 4 System word 5 System word 6<br>TDM frame<br>Padding Padding Padding Padding Padding<br>**----- End of picture text -----**<br>

**Figure 19.19 TDM Format (6 system words, with padding)**

## 19.4.4 WS Continue Mode

In WS continue mode, the SSIWS signal continues to be output irrespective whether data transfer is enabled or disabled. This mode can be set using the CONT bit in the TDM mode register (SSITDMR). With this mode enabled, the SSIWS signal does not stop but continues operating even if TEN and REN bits in the control register (SSICR) are both set to 0 (transfer disabled). While transfer is disabled, the SSITxD pin outputs 0 if the MUEN bit in SSICR is set to 0, and outputs the value specified by the SPDP bit in SSICR if the MUEN bit is set to 0. With this mode disabled, the SSIWS signal stops if TEN and REN bits are both set to 0.

Figure 19.20 and Figure 19.21 show the operations with WS continue mode enabled and disabled, respectively.

**==> picture [342 x 77] intentionally omitted <==**

**----- Start of picture text -----**<br>
Data transfer disabled period (TEN = 0, REN = 0)<br>SSISCK<br>SSIWS<br>SSIDATA LSB MSB LSB MSB LSB MSB<br>**----- End of picture text -----**<br>

**Figure 19.20 WS Continue Mode Enabled**

**==> picture [342 x 77] intentionally omitted <==**

**----- Start of picture text -----**<br>
Data transfer disabled period (TEN = 0, REN = 0)<br>SSISCK<br>SSIWS<br>SSIDATA LSB MSB LSB MSB LSB MSB<br>**----- End of picture text -----**<br>

**Figure 19.21 WS Continue Mode Disabled**

## 19.4.5 Operation Modes

There are three modes of operation: configuration, enabled and disabled. Figure 19.22 shows how the module enters each of these modes.

**==> picture [167 x 172] intentionally omitted <==**

**----- Start of picture text -----**<br>
Reset<br>Module<br>configuration<br>(after reset)<br>TEN = 0  TEN = 1<br>and  or<br>REN = 0  REN = 1<br>(IDST = 1) (IDST = 0)<br>Module disabled<br>(waiting until  TEN = 0  Module enabled<br>bus inactive) and  (normal tx/rx)<br>REN = 0<br>(IDST = 0)<br>**----- End of picture text -----**<br>

**Figure 19.22 Operation Modes**

## (1) Configuration Mode

This mode is entered after the module is released from reset. All required configuration fields in the control register should be defined in this mode, before this module is enabled by setting the TEN and REN bits.

Setting the TEN and REN bits causes the module to enter the module enabled mode.

## (2) Module Enabled Mode

Operation of the module in this mode is dependent on the operation mode selected. For details, refer to section 19.4.6, Transmit Operation , and section 19.4.7, Receive Operation , below.

## 19.4.6 Transmit Operation

Transmission can be controlled either by DMA transfer or interrupt.

DMA control is preferred to reduce the processor load. In DMA control mode, the processor will only receive interrupts if there is an underflow or overflow of data or if the DMA transfer has been completed.

The alternative method is using the interrupts that this module generates to supply data as required.

When disabling this module, the clock* must be kept supplied to this module until the IIRQ bit indicates that the module is in the idle state.

Figure 19.23 shows the transmit operation in DMA control mode, and Figure 19.24 shows the transmit operation in interrupt control mode.

Note: * Input clock from the SSISCK pin when SCKD = 0.

Oversampling clock when SCKD = 1.

## (1) Transmission Using Direct Memory Access Controller

**==> picture [325 x 459] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Define SCKD, SWSD, MUEN,<br>Release from reset,  DEL, PDTA, SDTA, SPDP,<br>set SSICR configuration bits. SWSP, SCKP, SWL, DWL,<br>CHNL<br>Set up the direct memory<br>access controller.<br>Enable the direct memory<br>access controller.<br>Enable error interrupts<br>and transmit interrupts,  TUIEN = 1, TOIEN = 1, TIE = 1,<br>then enable transmission. TEN = 1<br>Wait for an interrupt.<br>Yes<br>Error interrupt?<br>No<br>No<br>End of DMA transfer?<br>Yes<br>Yes<br>More data to be sent?<br>No<br>Disable transmit operation* [2] ,<br>TEN = 0,<br>disable direct memory access<br>TUIEN = 0, TOIEN = 0,<br>controller,<br>IIEN = 1, TIE = 0<br>disable an error interrupt,<br>enable an idle interrupt.<br>Wait for an idle interrupt<br>from this module<br>End* [1]<br>Notes:  1. If an error interrupt (underflow/overflow) occurs, go back to the start in the flowchart again.<br>2. When WS continue mode is disabled, to restart the transmission after it is disabled (TEN = 0),<br>     perform a software reset and then go back to the start in the flowchart again.<br>**----- End of picture text -----**<br>

**Figure 19.23 Transmission Using Direct Memory Access Controller**

## (2) Transmission Using Interrupt-Driven Data Flow Control

**==> picture [319 x 406] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Define SCKD, SWSD, MUEN,<br>Release from reset,  DEL, PDTA, SDTA, SPDP,<br>set SSICR configuration bits. SWSP, SCKP, SWL, DWL,<br>CHNL<br>Set up an interrupt controller.<br>Enable error interrupts  TUIEN = 1, TOIEN = 1, TIE = 1,<br>and transmit interrupts,  TEN = 1<br>then enable transmission.<br>For n = ((CHNL +1) x 2)<br>Loop<br>Wait for an interrupt.<br>Use SSI status register bits<br>No<br>Data interrupt? to realign data after<br>underflow/overflow.<br>Yes<br>Load data of channel n.<br>Next channel<br>Yes<br>More data to be sent?<br>No<br>Disable transmit operation*,  TEN = 0,<br>disable an error interrupt,  TUIEN = 0, TOIEN = 0,<br>enable an idle interrupt. IIEN = 1, TIE = 0<br>Wait for an idle interrupt<br>from this module<br>End<br>Note:  *  When WS continue mode is disabled, to restart the transmission after it is disabled (TEN = 0),<br>             perform a software reset and then go back to the start in the flowchart again.<br>**----- End of picture text -----**<br>

**Figure 19.24 Transmission Using Interrupt-Driven Data Flow Control**

## 19.4.7 Receive Operation

Like transmission, reception can be controlled either by DMA transfer or interrupt.

Figure 19.25 and Figure 19.26 show the flow of operation.

When disabling this module, the clock* must be kept supplied to this module until the IIRQ bit indicates that the module is in the idle state.

- Note: * Input clock from the SSISCK pin when SCKD = 0.

Oversampling clock when SCKD = 1.

## (1) Reception Using Direct Memory Access Controller

**==> picture [251 x 449] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Define SCKD, SWSD, MUEN,<br>Release from reset,  DEL, PDTA, SDTA, SPDP,<br>set SSICR configuration bits. SWSP, SCKP, SWL, DWL,<br>CHNL<br>Set up the direct memory<br>access controller.<br>Enable the direct memory<br>access controller.<br>Enable error interrupts<br>and receive interrupts,  RUIEN = 1, ROIEN = 1, RIE = 1,<br>then enable reception. REN = 1<br>Wait for an interrupt.<br>Yes<br>Error interrupt?<br>No<br>No<br>End of DMA transfer?<br>Yes<br>Yes<br>More data to be received?<br>No<br>Disable receive operation,  REN = 0,<br>disable an error interrupt,  RUIEN = 0, ROIEN = 0,<br>enable an idle interrupt. IIEN = 1, RIE = 0<br>Wait for an idle interrupt<br>from this module<br>End*<br>Note:  *  If an error interrupt (underflow/overflow) occurs,<br>              go back to the start in the flowchart again.<br>**----- End of picture text -----**<br>

**Figure 19.25 Reception Using Direct Memory Access Controller**

(2) Reception Using Interrupt-Driven Data Flow Control

**==> picture [242 x 368] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Define SCKD, SWSD, MUEN,<br>Release from reset,  DEL, PDTA, SDTA, SPDP,<br>set SSICR configuration bits. SWSP, SCKP, SWL, DWL,<br>CHNL<br>Set up the interrupt controller.<br>Enable error interrupts  RUIEN = 1, ROIEN = 1, RIE = 1,<br>and receive interrupts,  REN = 1<br>then enable reception.<br>Wait for an interrupt.<br>Yes Use SSI status register bits<br>Error interrupt? to realign data after<br>underflow/overflow.<br>No<br>Read data from receive<br>data register.<br>Yes<br>Receive more data?<br>No<br>Disable receive operation,  REN = 0,<br>disable a data interrupt,  RUIEN = 0, ROIEN = 0,<br>disable an error interrupt,  IIEN = 1, RIE = 0<br>enable an idle interrupt.<br>Wait for an idle interrupt<br>from this module<br>End<br>**----- End of picture text -----**<br>

**Figure 19.26 Reception Using Interrupt-Driven Data Flow Control**

When an underflow or overflow error condition has matched, this module can be recovered to the status before underflow or overflow condition match by using the TCHNO [1:0] and TSWNO bits in transmission and the RCHNO[1:0] and RSWNO bits in reception. When an underflow or overflow occurs, the host CPU can read the channel number and system word number to determine what point the serial audio stream has reached. In the transmitter case, the host CPU can skip forward through the data it wants to transmit until it finds the sample data that matches what this module is expecting to transmit next, and so resynchronize with the audio data stream. In the receiver case the host CPU can store null data to make the number of receive data items consistent until it is ready to store the sample data that this module is indicating will be received next, and so resynchronize with the audio data stream.

## 19.4.8 Serial Bit Clock Control

This function is used to control and select the clock that is used for the serial bus interface.

If the serial bit clock direction is set to input (SCKD = 0), this module is in clock slave mode and the shift register uses the bit clock that was input to the SSISCK pin.

If the serial bit clock direction is set to output (SCKD = 1), this module is in clock master mode, and the shift register uses the oversampling clock or a divided oversampling clock as the bit clock. The oversampling clock is divided by the ratio specified by the serial oversampling clock division ratio bits (CKDV) in SSICR for use as the bit clock by the shift register.

In either case above, the output of the SSISCK pin is the same as the bit clock.

## 19.5 Usage Notes

## 19.5.1 Limitations from Underflow or Overflow during DMA Operation

If an underflow or overflow occurs while the DMA is in operation, the module should be restarted. The transmit and receive buffers in the SSIF consists of 32-bit registers that share the L and R channels. Therefore, data to be transmitted and received at the L channel may sometimes be transmitted and received at the R channel if an underflow or overflow occurs, for example, under the following condition: the control register (SSICR) has a 32-bit setting for both data word length (DWL2 to DWL0) and system word length (SWL2 to SWL0).

If an error interrupt (transmit underflow, transmit overflow, receive underflow, and receive overflow) or setting of a corresponding error status flag (the bits TUIRQ, TOIRQ, RUIRQ, and ROIRQ in SSISR) indicates an error, write 0 to the TEN or REN bit in SSICR to disable DMA transfer requests from this module, thus stopping the operation. Make the setting to stop the direct memory access controller. After this, if reception had been in progress, write 0 to the error status flag bit to clear it, set the direct memory access controller again, and restart the transfer. For transmission, issue a software reset and execute the procedure to start again.

## 19.5.2 Note on Changing Mode from Master Transceiver to Master Receiver

If a transmit underflow occurs in master transceiver mode while WS continue mode is disabled (SSITDMR.CONT = 0) and the TEN bit in SSICR is set to 0 in order to disable transmit operation, SSIWS output is broken. In order to receive seamlessly after changing mode to master receiver mode, write dummy data to SSIFTDR to suppress transmit underflow.

## 19.5.3 Limits on TDM mode and WS Continue Mode

If TDM mode or WS continue mode setting is changed, the operation of the SSISCK and SSIWS signals immediately after switching are not guaranteed. If it affects the device to be connected, do not change the setting dynamically. To temporarily halt and restart transmission while the WS continue mode is enabled (SSITDMR.CONT = 1), after writing to the transmit FIFO data register (SSIFTDR) a multiple of two times, use the transmit underflow error interrupt or the corresponding error status flag (SSISR.TUIRQ) to confirm that an error has occurred, and then write 0 to the TEN bit of the SSISCR register.

Note that after the transmit underflow error, the last value written to SSIFTDR will be repeatedly sent as long as SSISCR.TEN = 1. Therefore, write a dummy value as the last data for transmission or mute the signal by writing 1 to the MUEN bit of the SSISCR register.

To restart transmission, do not apply a software reset; after writing 0 to the error status flag bit to clear it, use the idle mode status flag (SSISR.IDST) to confirm that this module is in the idle state, and then write 1 to the TEN bit of the SSISCR register.
