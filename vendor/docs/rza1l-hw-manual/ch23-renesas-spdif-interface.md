# 23. Renesas SPDIF Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1213–1240. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 23.1 Overview

**==> picture [228 x 147] intentionally omitted <==**

**----- Start of picture text -----**<br>
SPDIF_OUT<br>Transmitter<br>SPDIF_IN<br>Peripheral bus interface Receiver<br>**----- End of picture text -----**<br>

**Figure 23.1 Overview Block Diagram**

## 23.2 Features

- Supports the IEC 60958 standard (stereo and consumer use modes only).

- Supports sampling frequencies of 32 kHz, 44.1 kHz, and 48 kHz.

- Supports audio word sizes of 16 to 24 bits per sample.

- Biphase mark encoding.

- Double buffered data.

- Parity encoded serial data.

- Simultaneous transmit and receive

- Receiver autodetects IEC 61937 compressed mode data

## 23.3 Functional Block Diagram

**==> picture [388 x 349] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transmitter Parity BMC and<br>data generator preamble SPDIF_OUT<br>handling encoding<br>Transmitter Frame<br>control counter<br>AUDIO_X1<br>Oversampling clock<br>AUDIO_X2<br>AUDIO_CLK<br>Receiver Clock<br>control recovery and SPDIF_IN<br>frame counter<br>Receiver Parity BMC decode<br>data check an d  preamble<br>handling detection<br>Peripheral bus<br>**----- End of picture text -----**<br>

**Figure 23.2 Functional Block Diagram**

## 23.4 Input/Output Pins

Table 23.1 shows the pin configuration.

## **Table 23.1 Pin Configuration**

|**Channel**|**Pin Name**<br>**I/O**<br>**Description**|
|---|---|
|0|SPDIF_OUT<br>Output<br>Transmitter biphase-mark encoded SPDIF bitstream|
|1|SPDIF_IN<br>Input<br>Receiver biphase-mark encoded SPDIF bitstream|
|0, 1<br>(Common)|AUDIO_CLK<br>Input<br>External clock for audio|
||AUDIO_X1<br>Input<br>Crystal resonator/external clock for audio<br>AUDIO_X2<br>Output|

## 23.5 Renesas SPDIF (IEC60958) Frame Format

The Renesas SPDIF frame consists of two subframes (for channels 1 and 2), each of which contains a 4-bit preamble, audio data of up to 24 bits, a V flag, a user bit, a channel status bit, and an even parity bit. Figure 23.3 shows the subframe format. According to this format, the Renesas SPDIF performs biphase-mark modulation (channel coding) that will make the transmission line's DC component a minimum value.

**==> picture [341 x 107] intentionally omitted <==**

**----- Start of picture text -----**<br>
0 3 4 7 8 27 28 31<br>L L M<br>Synchronization<br>S Aux S Audio sample word S V U C P<br>preamble<br>B B B<br>B/M/W V = Validity flag<br>U = User data<br>C = Channel status<br>P = Parity bit<br>**----- End of picture text -----**<br>

**Figure 23.3 Subframe Format**

Figure 23.4 shows the block format, which consists of 192 continuous frames. One block begins at the starting frame (preamble B) and ends at the 192nd frame (frame 191), and the preamble is used to identify all subframes. Each block has a total of 384 subframes, which are classified into three categories: subframe 0 indicating the beginning of a new block, subframe 1 (usually the channel 1), and subframe 2 (usually the channel 2). Usually, the music data sent and received by the SPDIF is continuous so that continuous blocks appear.

**==> picture [388 x 63] intentionally omitted <==**

**----- Start of picture text -----**<br>
0 1 191 0 1<br>B Channel 1 W Channel 2 M Channel 1 M Channel 1 W Channel 2 B Channel 1 W Channel 2 M Channel 1<br>B = Start of block preamble<br>W = Channel 2 preamble<br>M = Channel 1 preamble but not start of block<br>**----- End of picture text -----**<br>

**Figure 23.4 Block Format**

Table 23.2 shows the binary values of the Renesas SPDIF preambles. The polarity of these preambles differs depending on the status of the preceding symbol (parity bit).

## **Table 23.2 Binary Preamble Values**

|**Preamble**|**Preceding Symbol's Status =**|**0**|**Preceding Symbol's Status =**|**1**|
|---|---|---|---|---|
|B|11101000||00010111||
|M|11100010||00011101||
|W|11100100||00011011||

Note: As shown in Figure 23.3, the even parity bit at time slot 31 of a subframe determines the type of a preamble for one cycle of transmission. Usually, therefore, any one is selected from the set states that are sent through the Renesas SPDIF. However, IEC60958 requires decoding both types in view of connection with the preamble polarity reversed; the Renesas SPDIF has preambles decoded according to Table 23.2.

Channel status information is encoded at the rate of one bit per subframe, making the channel status information per block have a total of 192 bits for each of subframes 1 and 2. For the format of the channel status, refer to the IEC 60958 standard.

## 23.6 Register

Table 23.3 shows the register configuration.

**Table 23.3 Register Configuration**

|**Channel**|**Register Name**<br>**Abbreviation**<br>**Address**<br>**Access**<br>**Size**|
|---|---|
|0<br>(Transmit)|Transmitter channel 1 audio register<br>TLCA<br>H'FFFF D800<br>32|
||Transmitter channel 2 audio register<br>TRCA<br>H'FFFF D804<br>32|
||Transmitter channel 1 status register<br>TLCS<br>H'FFFF D808<br>32|
||Transmitter channel 2 status register<br>TRCS<br>H'FFFF D80C<br>32|
||Transmitter user data register<br>TUI<br>H'FFFF D810<br>32|
|1<br>(Receive)|Receiver channel 1 audio register<br>RLCA<br>H'FFFF D814<br>32|
||Receiver channel 2 audio register<br>RRCA<br>H'FFFF D818<br>32|
||Receiver channel 1 status register<br>RLCS<br>H'FFFF D81C<br>32|
||Receiver channel 2 status register<br>RRCS<br>H'FFFF D820<br>32|
||Receiver user data register<br>RUI<br>H'FFFF D824<br>32|
|0, 1 (Common)|Control register<br>CTRL<br>H'FFFF D828<br>32|
||Status register<br>STAT<br>H'FFFF D82C<br>32|
|0, 1 (Common)|Transmitter DMA audio data register<br>TDAD<br>H'FFFF D830<br>32|
||Receiver DMA audio data register<br>RDAD<br>H'FFFF D834<br>32|

Note: All registers are longword registers and must be accessed as such.

A register diagram containing a 0 indicates that the write value should always be 0 (if the register is writeable) and that the read value should always be 0 (if readable).

## 23.7 Register Descriptions

## **Legend:**

Initial Value: Register value after reset

 : Undefined value

R/W: Readable/writable register. The write value can be read. R: Read only register. The write value should always be 0. R/WC0: Readable/writable register. Writing 0 initializes the bit, but writing 1 is ignored. R/WC1: Readable/writable register. Writing 1 initializes the bit, but writing 0 is ignored. W: Write only register. Reading is prohibited. If this bit is reserved, the write value should always be 0. —/W: Write only, Read value undefined

## 23.7.1 Control Register (CTRL)

|||Bit:|31|30|29<br>28<br>27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|
||||-|-|-<br>CKS<br>-|PB|RASS|||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R/W<br>R|R/W|R/W|R/W||
|||Bit:|23|22|21<br>20<br>19|18|17|16||
||||TASS||RDE<br>TDE<br>NCSI|AOS|RME|TME||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W||
|||Bit:|15|14|13<br>12<br>11|10|9|8||
||||REIE|TEIE|UBOI<br>UBUI<br>CREI|PAEI|PREI|CSEI||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W||
|||Bit:|7|6|5<br>4<br>3|2|1|0||
||||ABOI|ABUI|RUII<br>TUII<br>RCSI|RCBI|TCSI|TCBI||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|31 to 29|―|All 0|R||Reserved|||||
|28|CKS|0|R/W||Oversampling clock select|||||
||||||Selects oversampling clock supply source.|||||
||||||0: AUDIO_X1|||||
||||||1: AUDIO CLK|||||
|27|―|0|R||Reserved|||||
|26|PB|0|R/W||Pass Back|||||
||||||Passes transmitter SPDIF output into||||SPDIF receiver in SPDIF module.|
||||||0: Pass Back disabled|||||
||||||1: Pass Back enabled|||||
|25, 24|RASS|All 0|R/W||Receiver Audio Sample Bit Size|||||
||||||These bits Indicate the receiver audio||||sample bit size (16, 20, or 24 bits),|
||||||for data alignment purposes.|||||
||||||00: 16-bit sample|||||
||||||01: 20-bit sample|||||
||||||10: 24-bit sample|||||
||||||11: Reserved|||||

||||**Initial**|||
|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|23,|22|TASS|All 0|R/W|Transmitter Audio Sample Bit Size|
||||||These bits Indicate the transmitter audio sample bit size (16, 20, or 24|
||||||bits), for data alignment purposes.|
||||||00: 16-bit sample|
||||||01: 20-bit sample|
||||||10: 24-bit sample|
||||||11: Reserved|
|21||RDE|0|R/W|Receiver DMA Enable|
||||||Enables DMA requests for the receiver.|
||||||0: Receiver DMA disabled|
||||||1: Receiver DMA enabled|
|20||TDE|0|R/W|Transmitter DMA Enable|
||||||Enables the DMA requests for the transmitter.|
||||||0: Transmitter DMA disabled|
||||||1: Transmitter DMA enabled|
|19||NCSI|0|R/W|New Channel Status Information|
||||||Set this bit to 1 when new channel status information to be corrected is in|
||||||the transmitter.|
||||||0: New channel status information has not been in transmitter|
||||||1: New channel status information has been in transmitter|
|18||AOS|0|R/W|Audio Only Samples|
||||||Clear this bit to 0 when audio channel 1 and channel 2 registers contain|
||||||user information. When this bit is set to 1, all user bits are cleared to 0.|
||||||0: User information present|
||||||1: User information not present|
|17||RME|0|R/W|Receiver Module Enable|
||||||Enables the receiver module.|
||||||0: Receiver module disabled|
||||||1: Receiver module enabled|
|16||TME|0|R/W|Transmitter Module Enable|
||||||Enables the transmitter module.|
||||||0: Transmitter module disabled|
||||||1: Transmitter module enabled|
|15||REIE|0|R/W|Receiver Error Interrupt Enable|
||||||Enables the receiver error interrupts.|
||||||0: Receiver error interrupt disabled|
||||||1: Receiver error interrupt enabled|
|14||TEIE|0|R/W|Transmitter Error Interrupt Enable|
||||||Enables the transmitter error interrupts.|
||||||0: Transmitter error interrupt disabled|
||||||1: Transmitter error interrupt enabled|
|13||UBOI|0|R/W|User Buffer Overrun Interrupt Enable|
||||||Enables the user buffer overrun interrupts.|
||||||0: User buffer overrun interrupt disabled|
||||||1: User buffer overrun interrupt enabled|
|12||UBUI|0|R/W|User Buffer Underrun Interrupt Enable|
||||||Enables the user buffer underrun interrupts.|
||||||0: User buffer underrun interrupt disabled|
||||||1: User buffer underrun interrupt enabled|
|11||CREI|0|R/W|Clock Recovery Error Interrupt Enable|
||||||Enables the clock recovery error interrupts.|
||||||0: Clock recovery error interrupt disabled|
||||||1: Clock recovery error interrupt enabled|
|10||PAEI|0|R/W|Parity Error Interrupt Enable|
||||||Enables the parity check error interrupts.|
||||||0: Parity check error interrupt disabled|
||||||1: Parity check error interrupt enabled|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|9|PREI|0|R/W|Preamble Error Interrupt Enable|
|||||Enables the preamble check error interrupts.|
|||||0: Preamble error interrupt disabled|
|||||1: Preamble error interrupt enabled|
|8|CSEI|0|R/W|Channel Status Error Interrupt Enable|
|||||Enables the channel status error interrupts.|
|||||0: Channel status error interrupt disabled|
|||||1: Channel status error interrupt enabled|
|7|ABOI|0|R/W|Audio Buffer Overrun Interrupt Enable|
|||||Enables the receiver audio buffer overrun interrupts.|
|||||0: Audio buffer overrun interrupt disabled|
|||||1: Audio buffer overrun interrupt enabled|
|6|ABUI|0|R/W|Audio Buffer Underrun Interrupt Enable|
|||||Enables the transmitter audio buffer underrun interrupts.|
|||||0: Audio buffer underrun interrupt disabled|
|||||1: Audio buffer underrun interrupt enabled|
|5|RUII|0|R/W|Receiver User Information Interrupt Enable|
|||||Enables the receiver user information register full interrupts.|
|||||0: Receiver user information interrupt disabled|
|||||1: Receiver user information interrupt enabled|
|4|TUII|0|R/W|Transmitter User Information Interrupt Enable|
|||||Enables the transmitter user information register empty interrupts.|
|||||0: Transmitter user information interrupt disabled|
|||||1: Transmitter user information interrupt enabled|
|3|RCSI|0|R/W|Receiver Channel Status Interrupt Enable|
|||||Enables the receiver channel status register full interrupts.|
|||||0: Receiver channel status interrupt disabled|
|||||1: Receiver channel status interrupt enabled|
|2|RCBI|0|R/W|Receiver Channel Buffer Interrupt Enable|
|||||Enables the receiver audio channel buffer full interrupts.|
|||||0: Receiver audio channel interrupt disabled|
|||||1: Receiver audio channel interrupt enabled|
|1|TCSI|0|R/W|Transmitter Channel Status Interrupt Enable|
|||||Enables the transmitter channel status register empty interrupts.|
|||||0: Transmitter channel status interrupt disabled|
|||||1: Transmitter channel status interrupt enabled|
|0|TCBI|0|R/W|Transmitter Channel Buffer Interrupt Enable|
|||||Enables the transmitter audio channel buffer empty interrupts.|
|||||0: Transmitter audio channel interrupt disabled|
|||||1: Transmitter audio channel interrupt enabled|

## 23.7.2 Status Register (STAT)

|||||Bit:|31|30|29<br>28<br>27<br>26<br>25|24||
|---|---|---|---|---|---|---|---|---|---|
||||||-|-|-<br>-<br>-<br>-<br>-|-||
|||||Initial value:|0|0|0<br>0<br>0<br>0<br>0|0||
|||||R/W:|R|R|R<br>R<br>R<br>R<br>R|R||
|||||Bit:|23|22|21<br>20<br>19<br>18<br>17|16||
||||||-|-|-<br>-<br>-<br>-<br>-|CMD||
|||||Initial value:|0|0|0<br>0<br>0<br>0<br>0|0||
|||||R/W:|R|R|R<br>R<br>R<br>R<br>R|R||
|||||Bit:|15|14|13<br>12<br>11<br>10<br>9|8||
||||||RIS|TIS|UBO<br>UBU<br>CE<br>PARE PREE|CSE||
|||||Initial value:|1|1|0<br>0<br>0<br>0<br>0|0||
|||||R/W:|R|R|R/WC0 R/WC0 R/WC0 R/WC0 R/WC0|R/WC0||
|||||Bit:|7|6|5<br>4<br>3<br>2<br>1|0||
||||||ABO|ABU|RUIR<br>TUIR CSRX<br>CBRX CSTX|CBTX||
|||||Initial value:|0|0|0<br>0<br>0<br>0<br>0|0||
|||||R/W:|R/WC0|R/WC0|R<br>R<br>R<br>R<br>R|R||
|||||**Initial**||||||
|**Bit**|||**Bit Name**|**Value**|**R/W**||**Description**|||
|31|to|17|―|All 0|R||Reserved|||
|16|||CMD|0|R||Compressed Mode Data|||
||||||||Sets if the data being received is compressed mode data (When bit 1 = 1|||
||||||||in the V flag and channel status).|||
||||||||0: Data is not in compressed mode|||
||||||||1: Data is in compressed mode|||
|15|||RIS|1|R||Receiver Idle State|||
||||||||Sets if the receiver is in the idle|state.||
||||||||0: Receiver is not in idle state|||
||||||||1: Receiver in idle state|||
|14|||TIS|1|R||Transmitter Idle State|||
||||||||Sets if the transmitter is in the idle state.|||
||||||||0: Transmitter is not in idle state|||
||||||||1: Transmitter is in idle state|||
|13|||UBO|0|R/WC0||User Buffer Overrun*|||
||||||||Sets if the receiver user buffer overruns. This bit is cleared by writing 0 to|||
||||||||the register. If bit REIE and bit UBOI in the control register are set this|||
||||||||causes an interrupt.|||
||||||||0: User buffer has not overrun|||
||||||||1: User buffer has overrun|||
|12|||UBU|0|R/WC0||User Buffer Underrun*|||
||||||||Sets if the transmitter user buffer underrun. This bit is cleared by writing|||
||||||||0. If bits TEIE and UBUI in the control register are set this causes an|||
||||||||interrupt.|||
||||||||0: User buffer has not underrun|||
||||||||1: User buffer has underrun|||
|11|||CE|0|R/WC0||Clock Error*|||
||||||||Sets when the clock recovery falls out||of synchronization. This bit is|
||||||||cleared by writing 0. If bits REIE and CREI in the control register are set|||
||||||||this causes an interrupt.|||
||||||||0: Clock recovery stable|||
||||||||1: Clock recovery error|||
|10|||PARE|0|R/WC0||Parity Error*|||
||||||||Sets when the parity checker produces a fail result. This bit is cleared by|||
||||||||writing 0. If bits REIE and PAEI|in the control register are set this causes||
||||||||an interrupt.|||
||||||||0: Parity check correct|||
||||||||1: Parity error|||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|9|PREE|0|R/WC0|Preamble Error*|
|||||Sets when the start of word preamble fails to appear in the correct place.|
|||||This bit is cleared by writing 0. If bits REIE and PREI in the control|
|||||register are set this causes an interrupt.|
|||||Note: Only set after a start of block preamble has occurred.|
|||||0: Preamble is in the correct place|
|||||1: Preamble error|
|8|CSE|0|R/WC0|Channel Status Error*1|
|||||Sets when the channel status information is written before the 32nd frame|
|||||of the current block. This bit is cleared by writing 0. If bits TEIE and CSEI|
|||||in the control register are set this causes an interrupt.|
|||||0: Channel status correct|
|||||1: Channel status error|
|7|ABO|0|R/WC0|Audio Buffer Overrun*1|
|||||Indicates that the receiver audio buffer is full in both the first and second|
|||||stages and that data has been overwritten. This bit is cleared by writing 0.|
|||||If bits REIE and ABOI in the control register are set then this causes an|
|||||interrupt.|
|||||0: Receiver audio buffer has not overrun|
|||||1: Receiver audio buffer has overrun|
|6|ABU|0|R/WC0|Audio Buffer Underrun*1|
|||||Indicates that the transmitter audio buffer is empty in both the first and|
|||||second stages and that the last data transmission has been repeated.|
|||||This bit is cleared by writing 0. If bits TEIE and ABUI in the control register|
|||||are set then this causes an interrupt.|
|||||0: Transmitter audio buffer has not underrun|
|||||1: Transmitter audio buffer has underrun|
|5|RUIR|0|R|Receiver User Information Register Status|
|||||Indicates the status of the receiver user information register. This bit is|
|||||cleared by reading from the receiver user register. If bit RUII in the control|
|||||register is set then this causes an interrupt.|
|||||0: Receiver user information register is empty|
|||||1: Receiver user information register is full|
|4|TUIR|0|R|Transmitter User Information Register Status|
|||||Indicates the status of the transmitter user information register. This bit is|
|||||cleared by writing to the transmitter user register. If bit TUII in the control|
|||||register is set then this causes an interrupt.|
|||||0: Transmitter user information register is full|
|||||1: Transmitter user information register is empty|
|3|CSRX|0|R|Channel 1 and Channel 2 Status for Receiver|
|||||Indicates the status of the receiver channel status registers. This bit is|
|||||cleared by reading from the receiver channel status registers. If bit RCSI|
|||||in the control register is set this causes an interrupt.|
|||||0: Receiver channel status registers are empty|
|||||1: Receiver channel status registers are full|
|2|CBRX|0|R|Channel 1 and Channel 2 Buffers for Receiver|
|||||Indicates the status of the receiver audio channel registers. This bit is|
|||||cleared by reading from the receiver audio channel registers. If bit RCBI|
|||||in the control register is set this causes an interrupt.|
|||||0: Receiver audio channel registers are empty|
|||||1: Receiver audio channel registers are full|
|1|CSTX|0|R|Channel 1 and Channel 2 Status for Transmitter|
|||||Indicates the status of the transmitter channel status registers. This bit is|
|||||cleared by writing to the transmitter channel status registers. If bit TCSI in|
|||||the control register is set this causes an interrupt.|
|||||0: Transmitter channel status register is full|
|||||1: Transmitter channel status register is empty|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|0|CBTX|0|R|Channel 1 and Channel 2 Buffers for Transmitter|
|||||Indicates the status of the transmitter audio channel registers. This bit is|
|||||cleared by writing to the transmitter audio channel registers. If bit TCBI in|
|||||the control register is set this causes an interrupt.|

- 0: Transmitter audio channel registers are full

- 1: Transmitter audio channel registers are empty

Note 1. When an error bit is detected during DMA transfer, DMA transfer settings must be made again. In this case, the Renesas SPDIF's module enable bit (either the RME or TME bit) and the DMA enable bit (either the RDE or TDE bit) must be disabled and the error status must be cleared before making DMA transfer settings again. Then the module enable bit should be set and DMA transfer can be started again.

## 23.7.3 Transmitter Channel 1 Audio Register (TLCA)

|||||Bit:|31|30|29|28|27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|-|-|-|-|-|-||
|||||Initial value:|-|-|-|-|-|-|-|-||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|23|22|21|20|19|18|17|16||
||||||||Audio PCM Data|||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|15|14|13|12|11|10|9|8||
||||||||Audio PCM Data|||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|7|6|5|4|3|2|1|0||
||||||||Audio PCM Data|||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||**Initial**||||||||||
|**Bit**|||**Bit Name**|**Value**|**R/W**||**Description**|||||||
|31|to|24|―|―|W||Reserved|||||||
|23|to|0|Audio PCM Data|All 0|W||Audio PCM||Data|||||
||||||||LSB aligned PCM|||encoded audio data.||||

## 23.7.4 Transmitter Channel 2 Audio Register (TRCA)

|||||Bit:|31|30|29|28|27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|-|-|-|-|-|-||
|||||Initial value:|-|-|-|-|-|-|-|-||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|23|22|21|20|19|18|17|16||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|15|14|13|12|11|10|9|8||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|7|6|5|4|3|2|1|0||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||**Initial**||||||||||
|**Bit**|||**Bit Name**|**Value**|**R/W**||**Description**|||||||
|31|to|24|―|―|W||Reserved|||||||
|23|to|0|Audio PCM Data|All 0|W||Audio PCM||Data|||||
||||||||LSB aligned PCM|||encoded audio data.||||

## 23.7.5 Transmitter DMA Audio Data Register (TDAD)

|||||Bit:|31|30|29|28|27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|-|-|-|-|-|-||
|||||Initial value:|-|-|-|-|-|-|-|-||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|23|22|21|20|19|18|17|16||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|15|14|13|12|11|10|9|8||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||Bit:|7|6|5|4|3|2|1|0||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|W|W|W|W|W|W|W|W||
|||||**Initial**||||||||||
|**Bit**|||**Bit Name**|**Value**|**R/W**||**Description**|||||||
|31|to|24|―|―|W||Reserved|||||||
|23|to|0|Audio PCM Data|All 0|W||Audio PCM||Data|||||
||||||||LSB aligned PCM|||encoded audio data.||||

## 23.7.6 Transmitter User Data Register (TUI)

U-bit data in subframes is written in to this register. Because U-bit data is transmitted in a sequence of subframes 1 and 2, you need to update the data on a 16-frame basis. For the contents of the user bytes refer to the appropriate standard for the device in use. The user bits to be transmitted are set in sequence starting at the LSB.

|||Bit:|31|30|29|28|27|26|25|24|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||User Byte 4|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|W|W|W|W|W|W|W|W|
|||Bit:|23|22|21|20|19|18|17|16|
|||||||User Byte 3|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|W|W|W|W|W|W|W|W|
|||Bit:|15|14|13|12|11|10|9|8|
|||||||User Byte 2|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|W|W|W|W|W|W|W|W|
|||Bit:|7|6|5|4|3|2|1|0|
|||||||User Byte 1|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|W|W|W|W|W|W|W|W|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|31 to 24|User Byte 4|All 0|W||U-bit|information is stored|||here.||
|23 to 16|User Byte 3|All 0|W||||||||
|15 to 8|User Byte 2|All 0|W||||||||
|7 to 0|User Byte 1|All 0|W||||||||

## 23.7.7 Transmitter Channel 1 Status Register (TLCS)

The 30-bit register stores the channel status information to be transmitted. For each channel, channel status information per frame consists of 192 bits. Because necessary data covers only the 30 bits that are set in the following register, zeros continue to be sent after the transmission of the first 30 bits.

|||Bit:|31|30|29<br>28<br>27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|
||||-|-|CLAC[1:0]|FS[3:0]||||
|||Initial value:|-|-|0<br>0<br>0|0|0|0||
|||R/W:|W|W|W<br>W<br>W|W|W|W||
|||Bit:|23|22|21<br>20<br>19|18|17|16||
|||||CHNO[3:0]||SRCNO[3:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|W|W|W<br>W<br>W|W|W|W||
|||Bit:|15|14|13<br>12<br>11|10|9|8||
||||||CATCD[7:0]|||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|W|W|W<br>W<br>W|W|W|W||
|||Bit:|7|6|5<br>4<br>3|2|1|0||
||||-|-|CTL[4:0]|||-||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|W|W|W<br>W<br>W|W|W|W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|31, 30|―|―|W||Reserved|||||
|29, 28|CLAC[1:0]|All 0|W||Clock Accuracy|||||
||||||00: Level 2|||||
||||||01: Level 1|||||
||||||10: Level 3|||||
||||||11: Reserved|||||
|27 to 24|FS[3:0]|All 0|W||Sample Frequency (FS)|||||
||||||0000: 44.1 kHz|||||
||||||0010: 48 kHz|||||
||||||0011: 32 kHz|||||
|23 to 20|CHNO[3:0]|All 0|W||Channel Number|||||
||||||0000: Don't care|||||
||||||0001: A (left channel)|||||
||||||0010: B (right channel)|||||
||||||0011: C|||||
|19 to 16|SRCNO[3:0]|All 0|W||Source Number|||||
||||||0000: Don't care|||||
||||||0001: 1|||||
||||||0010: 2|||||
||||||0011: 3|||||
|15 to 8|CATCD[7:0]|All 0|W||Category Code (Example)|||||
||||||00000000: 2-channel general format|||||
||||||00000001: 2-channel compact disc (IEC 908)|||||
||||||00000010: 2-channel PCM encoder/decoder|||||
||||||00000011: 2-channel digital audio tape recorder|||||
|7, 6|―|All 0|W||Reserved|||||
||||||The write value should always be 0.|||||
|5 to 1|CTL[4:0]|All 0|W||Control|||||
||||||The control bits are copied||from the source (see IEC60958 standard).|||
|0|―|0|W||Reserved|||||
||||||The write value should always be 0.|||||

## 23.7.8 Transmitter Channel 2 Status Register (TRCS)

The 30-bit register stores the channel status information to be transmitted. For each channel, channel status information per frame consists of 192 bits. Because necessary data covers only the 30 bits that are set in the following register, zeros continue to be sent after the transmission of the first 30 bits.

|||Bit:|31|30|29<br>28<br>27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|
||||-|-|CLAC[1:0]|FS[3:0]||||
|||Initial value:|-|-|0<br>0<br>0|0|0|0||
|||R/W:|W|W|W<br>W<br>W|W|W|W||
|||Bit:|23|22|21<br>20<br>19|18|17|16||
|||||CHNO[3:0]||SRCNO[3:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|W|W|W<br>W<br>W|W|W|W||
|||Bit:|15|14|13<br>12<br>11|10|9|8||
||||||CATCD[7:0]|||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|W|W|W<br>W<br>W|W|W|W||
|||Bit:|7|6|5<br>4<br>3|2|1|0||
||||-|-|CTL[4:0]|||-||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|W|W|W<br>W<br>W|W|W|W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|31, 30|―|―|W||Reserved|||||
|29, 28|CLAC[1:0]|All 0|W||Clock Accuracy|||||
||||||00: Level 2|||||
||||||01: Level 1|||||
||||||10: Level 3|||||
||||||11: Reserved|||||
|27 to 24|FS[3:0]|All 0|W||Sample Frequency|(FS)||||
||||||0000: 44.1 kHz|||||
||||||0010: 48 kHz|||||
||||||0011: 32 kHz|||||
|23 to 20|CHNO[3:0]|All 0|W||Channel Number|||||
||||||0000: Don't care|||||
||||||0001: A (left channel)|||||
||||||0010: B (right channel)|||||
||||||0011: C|||||
|19 to 16|SRCNO[3:0]|All 0|W||Source Number|||||
||||||0000: Don't care|||||
||||||0001: 1|||||
||||||0010: 2|||||
||||||0011: 3|||||
|15 to 8|CATCD[7:0]|All 0|W||Category Code (Example)|||||
||||||00000000: 2-channel general format|||||
||||||00000001: 2-channel compact disc (IEC 908)|||||
||||||00000010: 2-channel PCM encoder/decoder|||||
||||||00000011: 2-channel digital audio tape recorder|||||
|7, 6|―|All 0|W||Reserved|||||
||||||The write value should always be 0.|||||
|5 to 1|CTL[4:0]|All 0|W||Control|||||
||||||The control bits are copied||from the source (see IEC60958 standard).|||
|0|―|0|W||Reserved|||||
||||||The write value should always be 0.|||||

## 23.7.9 Receiver Channel 1 Audio Register (RLCA)

|||||Bit:|31|30|29|28|27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|-|-|-|-|-|-||
|||||Initial value:|-|-|-|-|-|-|-|-||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|23|22|21|20|19|18|17|16||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|15|14|13|12|11|10|9|8||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|7|6|5|4|3|2|1|0||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||**Initial**||||||||||
|**Bit**|||**Bit Name**|**Value**|**R/W**||**Description**|||||||
|31|to|24|―|―|R||Reserved|||||||
|23|to|0|Audio PCM Data|All 0|R||Audio PCM||Data|||||
||||||||LSB aligned PCM|||encoded audio data.||||

## 23.7.10 Receiver Channel 2 Audio Register (RRCA)

|||||Bit:|31|30|29|28|27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|-|-|-|-|-|-||
|||||Initial value:|-|-|-|-|-|-|-|-||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|23|22|21|20|19|18|17|16||
||||||||Audio PCM Data|||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|15|14|13|12|11|10|9|8||
||||||||Audio PCM Data|||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|7|6|5|4|3|2|1|0||
||||||||Audio PCM Data|||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||**Initial**||||||||||
|**Bit**|||**Bit Name**|**Value**|**R/W**||**Description**|||||||
|31|to|24|―|―|R||Reserved|||||||
|23|to|0|Audio PCM Data|All 0|R||Audio PCM||Data|||||
||||||||LSB aligned PCM|||encoded audio data.||||

## 23.7.11 Receiver DMA Audio Data (RDAD)

|||||Bit:|31|30|29|28|27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|-|-|-|-|-|-||
|||||Initial value:|-|-|-|-|-|-|-|-||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|23|22|21|20|19|18|17|16||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|15|14|13|12|11|10|9|8||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||Bit:|7|6|5|4|3|2|1|0||
|||||||||Audio PCM Data||||||
|||||Initial value:|0|0|0|0|0|0|0|0||
|||||R/W:|R|R|R|R|R|R|R|R||
|||||**Initial**||||||||||
|**Bit**|||**Bit Name**|**Value**|**R/W**||**Description**|||||||
|31|to|24|―|―|R||Reserved|||||||
|23|to|0|Audio PCM Data|All 0|R||Audio PCM||Data|||||
||||||||LSB aligned PCM|||encoded audio data.||||

## 23.7.12 Receiver User Data Register (RUI)

The register stores the U-bit data received through the Renesas SPDIF. Because U-bit data is stored in a sequence of subframes 1 and 2 starting at the LSB, you need to read the data on a 16-frame basis. For the contents of the user bytes refer to the appropriate standard for the device in use.

|Bit:|31|30|29|28|27|26|25|24|
|---|---|---|---|---|---|---|---|---|
|||||User|Byte|4|||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|
|Bit:|23|22|21|20|19|18|17|16|
|||||User|Byte|3|||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|
|||||User|Byte|2|||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|
|Bit:|7|6|5|4|3|2|1|0|
|||||User|Byte|1|||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 24|User Byte 4|All 0|R|U-bit information is stored here.|
|23 to 16|User Byte 3|All 0|R||
|15 to 8|User Byte 2|All 0|R||
|7 to 0|User Byte 1|All 0|R||

## 23.7.13 Receiver Channel 1 Status Register (RLCS)

The channel status is stored starting at the register's LSB in a way that subframe 1 received from the beginning of the block is stored. For the contents of the channel status register, refer to the IEC-60958 standard.

|||Bit:|31|30|29<br>28<br>27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|
||||-|-|CLAC[1:0]|FS[3:0]||||
|||Initial value:|-|-|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R<br>R|R|R|R||
|||Bit:|23|22|21<br>20<br>19|18|17|16||
|||||CHNO[3:0]||SRCNO[3:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R<br>R|R|R|R||
|||Bit:|15|14|13<br>12<br>11|10|9|8||
||||||CATCD[7:0]|||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R<br>R|R|R|R||
|||Bit:|7|6|5<br>4<br>3|2|1|0||
||||-|-|CTL[4:0]|||-||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R<br>R|R|R|R||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|31, 30|―|―|R||Reserved|||||
|29, 28|CLAC[1:0]|All 0|R||Clock Accuracy|||||
||||||00: Level 2|||||
||||||01: Level 1|||||
||||||10: Level 3|||||
||||||11: Reserved|||||
|27 to 24|FS[3:0]|All 0|R||Sample Frequency (FS)|||||
||||||0000: 44.1 kHz|||||
||||||0010: 48 kHz|||||
||||||0011: 32 kHz|||||
|23 to 20|CHNO[3:0]|All 0|R||Channel Number|||||
||||||0000: Don't care|||||
||||||0001: A (left channel)|||||
||||||0010: B (right channel)|||||
||||||0011: C|||||
|19 to 16|SRCNO[3:0]|All 0|R||Source Number|||||
||||||0000: Don't care|||||
||||||0001: 1|||||
||||||0010: 2|||||
||||||0011: 3|||||
|15 to 8|CATCD[7:0]|All 0|R||Category Code (Example)|||||
||||||00000000: 2-channel general format|||||
||||||00000001: 2-channel compact|||disc (IEC 908)||
||||||00000010: 2-channel PCM encoder/decoder|||||
||||||00000011: 2-channel digital audio tape recorder|||||
|7, 6|―|All 0|R||Reserved|||||
|5 to 1|CTL[4:0]|All 0|R||Control|||||
||||||The control bits are copied from the source (see IEC60958 standard).|||||
|0|―|0|R||Reserved|||||

## 23.7.14 Receiver Channel 2 Status Register (RRCS)

The channel status is stored starting at the register's LSB in a way that subframe 2 received from the beginning of the block is stored. For the contents of the channel status register, refer to the IEC-60958 standard.

|||Bit:|31|30|29<br>28<br>27|26|25|24||
|---|---|---|---|---|---|---|---|---|---|
||||-|-|CLAC[1:0]|FS[3:0]||||
|||Initial value:|-|-|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R<br>R|R|R|R||
|||Bit:|23|22|21<br>20<br>19|18|17|16||
|||||CHNO[3:0]||SRCNO[3:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R<br>R|R|R|R||
|||Bit:|15|14|13<br>12<br>11|10|9|8||
||||||CATCD[7:0]|||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R<br>R|R|R|R||
|||Bit:|7|6|5<br>4<br>3|2|1|0||
||||-|-|CTL[4:0]|||-||
|||Initial value:|0|0|0<br>0<br>0|0|0|0||
|||R/W:|R|R|R<br>R<br>R|R|R|R||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|31, 30|―|―|R||Reserved|||||
|29, 28|CLAC[1:0]|All 0|R||Clock Accuracy|||||
||||||00: Level 2|||||
||||||01: Level 1|||||
||||||10: Level 3|||||
||||||11: Reserved|||||
|27 to 24|FS[3:0]|All 0|R||Sample Frequency (FS)|||||
||||||0000: 44.1 kHz|||||
||||||0010: 48 kHz|||||
||||||0011: 32 kHz|||||
|23 to 20|CHNO[3:0]|All 0|R||Channel Number|||||
||||||0000: Don't care|||||
||||||0001: A (left channel)|||||
||||||0010: B (left channel)|||||
||||||0011: C|||||
|19 to 16|SRCNO[3:0]|All 0|R||Source Number|||||
||||||0000: Don't care|||||
||||||0001: 1|||||
||||||0010: 2|||||
||||||0011: 3|||||
|15 to 8|CATCD[7:0]|All 0|R||Category Code (Example)|||||
||||||00000000: 2-channel general format|||||
||||||00000001: 2-channel compact|||disc (IEC 908)||
||||||00000010: 2-channel PCM encoder/decoder|||||
||||||00000011: 2-channel digital audio tape recorder|||||
|7, 6|―|All 0|R||Reserved|||||
|5 to 1|CTL[4:0]|All 0|R||Control|||||
||||||The control bits are copied from the source (see IEC60958 standard).|||||
|0|―|0|R||Reserved|||||

## 23.8 Functional Description—Transmitter

## 23.8.1 Transmitter Module

The transmitter module transmits PCM data and auxiliary information after encoding it according to the method of biphase-mark modulation that complies with the IEC60958 standard (SPDIF).

The clock for the transmitter module is an oversampling clock supplied from the outside. This clock usually selects a value that serves as an oversample at a frequency eight times larger than the clock frequency required for biphase-mark encoding. In this case, the clock frequency required to transmit 32 time slots in a subframe is 512 times as large as the sample frequency for audio data.

Audio data and channel status information are first written into the module's channel 1 and then into channel 2.

Generally, the channel status need to be written only when the information changes. The SPDIF module requests that the channel status be written in 30 frames -- when all the current channel status data have been transmitted. You need to write somewhere between frame 31 and the beginning of the next block of 192 frames.

The audio data is stored in a double buffer arrangement. To make sure that the first stage buffer is empty, you can send an interrupt request or poll the status register. DMA transfers send channel 1 audio data on the first request and channel 2 data on the second.

The channel status information is stored in the 30-bit registers of channels 1 and 2. For each channel, the channel status information per frame consists of 192 bits. Because necessary data covers only 30 bits, zeros continue to be sent after the transmission of the first 30 bits until the block is completed.

User data forms a 32-bit double buffer arrangement. You can make sure that the first stage buffer is empty by either sending an interrupt request or polling the status register. Usually, information about the user data will become insufficient with the length of data between blocks. Transmission takes place in a sequence of channels 1 and 2. For the user data within a block, 384 bits are transmitted before the next block is continuously transmitted.

The audio data handled by the Renesas SPDIF module is a linear PCM, making it possible to set up to 24 bits. For this reason, the V flag indicating that audio data is a linear PCM remains to be 0. The V flag involves no register-based setting. An even parity is created for each 32 bits of serial output data (excluding the preamble).

Note: • When transmitter user buffer underrun occurs, the current data in the buffer data of SPDIF is transmitted until the next data is filled.

## 23.8.2 Transmitter Module Initialization

The device defaults to an idle state when it comes out of reset, or can be put into an idle state when 0 is written to the TME bit in the CTRL register. When the transmitter module is idle, it has the following settings:

- The transmitter idle status bit (TIS) is set to 1, all other status bits are cleared to 0.

- Preamble generation is invalid.

- Synchronization between channels 1 and 2 is set to 0 (0 for channel 1, 1 for channel 2).

- Both word_count and frame_count are set to 0.

- The output from the biphase-mark encoder is set to 0.

Channel status, user and audio data registers will retain its value prior to putting the module into idle. To exit the idle state the user must write 1 to the TME bit in the CTRL register.

## 23.8.3 Initial Settings for Transmitter Module

When the TME bit is set to 1, the TUIR and CSTX bits are set to 1. After that, if data is written in the order of 1) TUI and 2) TLCS and TRCS, a channel status error will occur. To avoid this, be sure to write data in the order of 1) TLCS and TRCS and 2) TUI.

Before writing the first audio data (write access to TLCA or TRCA by the CPU or write access to TDAD by the DMA transfer) after setting the TME bit to 1, be sure to check that the CSTX and TUIR bits are cleared by writing to TLCS, TRCS, and TUI.

## 23.8.4 Transmitter Module Data Transfer

Once the transmitter module has left the idle state, it is ready for data transfer. Data transfer timing can be achieved in three ways. Either the transfer is done by interrupts, DMA requests or by polling the status register. There is a shared interrupt line (for both transmit and receive) and a single transmitter DMA request line. Figure 23.5 shows a data transfer with an interrupt for the transmitter.

**==> picture [183 x 288] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Idle<br>Set control bit enabled<br>(TCBI)<br>Wait for interrupt<br>Load left or right audio<br>channel data<br>No<br>Enter idle state?<br>Yes<br>Set control bit disabled<br>(TCBI)<br>**----- End of picture text -----**<br>

**Figure 23.5 Transmitter Data Transfer Flow Diagram - Interrupt Driven**

Figure 23.6 shows a data transfer with a DMA transfer for the transmitter.

**==> picture [183 x 198] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Idle<br>Wait for transmitter<br>DMA request<br>Load left or right audio<br>channel data<br>Yes No<br>Enter idle state?<br>**----- End of picture text -----**<br>

**Figure 23.6 Transmitter Data Transfer Flow Diagram—DMA Request Driven**

Channel status information is required to be updated when the information has changed. Because the updating needs to be done before the transmission of the next block, the channel status to be updated should be written after 30 frames have been sent; this is indicated either by an interrupt or by polling the status bit. If channel status is written before 30 frames have been sent (while current information is being sent) then an interrupt indicates that the channel status error bit (CSE) in the status register has been set.

Note: • 30 frames contains all the valid information in a single channel status block.

## 23.9 Functional Description—Receiver

## 23.9.1 Receiver Module

The receiver module demodulates data and clock signals from the input encoded according to the IEC60958 standard. The encoded data, shown in linear PCM format, is stored into the audio data register.  The register also stores the channel status and user information being received simultaneously as auxiliary information.

The main clock for the receiver module is an oversampling clock supplied from the outside. The module operates at a frequency four times as large as the oversampling clock.

## Note: • The oversampling clock is the same for the transmitter and receiver.

Clock recovery is performed using a pulse width counter and averaging filters to produce a sampling pulse in the middle of each bit in the datastream. A clock error status bit indicates clock synchronization loss. Synchronization is achieved when a preamble occurs on the data stream for the first time. Continuous adjustment prevents jitter and/or clock drift from affecting clock recovery, provided that they fall within the clock recovery specifications.

Once the clock recovery is successful the biphase-mark decoder initiates its preamble detection. The decoder searches for the start of block preamble (see Table 23.2 ). A preamble error status bit indicates that following preambles have not appeared at the correct time, such failures are most likely caused by transmission loss or interference.

Even parity checking is performed on the decoded data. A discrepancy will result in the parity error status bit being set. The SPDIF module acquires user data and channel status information in addition to audio data. The audio is stored in a double buffer arrangement. Either an interrupt request because of a full buffer or polling of the status bit will indicate when the data is ready to be read. DMA transfers receive channel 1 audio data on the first request and channel 2 data on the second.

Channel status is stored in a 30-bit register. Channel status information is received at 1-bit per subframe. Therefore the registers will not be full until a total of 30 frames for each channel have been received. New channel status is compared with the current data to see if it has changed and is only read by the processor if it has. User data, which is also received at the same time, is stored into the register on a subframe basis, so that the reception is completed when 16 frames are reached.

## Note 1. Channel status data requests do not support DMA.

Note 2. When receiver user buffer overrun occurs, the current data in the buffer data of SPDIF is overwritten by the next incoming data from SPDIF interface.

## 23.9.2 Receiver Module Initialization

The device defaults to an idle state when it comes out of reset, or can be put into an idle state by writing 0 to bit RME in the CTRL register. Whilst idle the module has the following settings:

- The receiver idle status bit is set to 1, all other status bits are cleared to 0.

- Synchronization between channels 1 and 2 is set to 0 (0 for channel 1, 1 for channel 2).

- Both Word_count and frame_count are set to 0.

Channel status registers, user data registers and audio data registers will retain its value prior to putting the module into idle. To exit the idle state the user must write 1 to the bit RME in the CTRL register.

## 23.9.3 Receiver Module Data Transfer

Once the module has left the idle state it is ready for data transfer. Data transfer timing can be achieved in three ways. The transfer can be done by interrupts, or by polling the status register, or by DMA. There is a shared interrupt line (transmit and receive) and a single receiver DMA request line. Data transfer for the receiver can be interrupted by error signals caused by:

1. Clock recovery failure.

2. Transmission loss or interference – indicated by a preamble error.

3. Parity check failure.

Transmission loss or interference can cause the start of subframe or start of block preamble to be misplaced or not present.

Parity check failure occurs when the parity bit is incorrect, this can be caused by any of the above.

- Clock Recovery Deviation

The receive margin for clock recovery is based on the following equation:

1 D − 0.5 M = 0.5 − − (L − 0.5) F − (1 + F)   × 100% 2N N

where _M_ = receive margin

_N_ = oversampling rate

_L_ = frame length = 33

_D_ = duty cycle = 0.6

_F_ = oversampling clock deviation = Level II accuracy = 1000 in 10e[–6]

Figure 23.7 indicates what the receive margin M represents.

**==> picture [483 x 119] intentionally omitted <==**

**----- Start of picture text -----**<br>
Internal Clock<br>Data<br>M<br>Sampling Clock<br>Figure 23.7 Receive Margin<br>**----- End of picture text -----**<br>

Introducing jitter into the equation gives the following inequality.

1 D − 0.5 j ≤ 0.5 − − (L − 0.5) F − (1 + F)   × 100% 2N N

## _J_ = clock jitter

Eight times oversampling produces a receive margin = 39.25% Four times oversampling produces a receive margin = 31.75% Two times oversampling produces a receive margin = 16.75%

The fastest sample frequency is 48 kHz. This requires a clock speed of 128  48 kHz = 6.144 MHz. The worst case jitter in one cycle is specified at 40 ns = 24.5% of the period. This means that an oversampling rate of 4 or more will satisfy the inequality and therefore be sufficient for clock recovery.

Figure 23.8 illustrates the receiver data transfer using interrupts.

**==> picture [238 x 337] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Idle<br>Set control bit enabled<br>(RCBI)<br>Wait for interrupt<br>Load left or right audio<br>channel data<br>Yes<br>Error detected? Error handling<br>No<br>No<br>Enter idle state?<br>Yes<br>Set control bit disabled<br>(RCBI)<br>**----- End of picture text -----**<br>

**Figure 23.8 Receiver Data Transfer Flow Diagram - Interrupt Driven**

Interrupts to indicate that the channel status information register is full occur after frame 30 has been received and only if the information has changed. When the first four bytes have been stored an interrupt occurs.

## 23.10 Disabling the Module

## 23.10.1 Transmitter and Receiver Idle

The transmitter or receiver modules can be disabled by writing 0 to the idle bit in the control register (TME for the transmitter and RME for the receiver). The idle state can be detected by polling the idle bit in the status register (TIS and RIS).

## 23.11 Compressed Mode Data

Compressed mode data is defined in the IEC 61937 specification. This module only detects compressed mode data. This is done by checking the parity flag (V flag) and bit 1 in the channel status data. If both are one then the data is in compressed mode. This is indicated by the setting of the CMD bit in the status register.

Note: • Only the receiver detects compressed mode data since the information is not relevant to the transmitter.

## 23.12 References

IEC60958 Digital Audio Interface

IEC61937 Compressed Mode Digital Audio Interface

## 23.13 Usage Notes

## 23.13.1 Clearing TUIR

After TUI is written to, the TUIR bit is cleared only after transmission of a maximum of one frame is completed. When using a transmitter user information interrupt to write data to TUI, check that the TUIR bit is cleared before terminating the interrupt handling routine so that the interrupt is not unexpectedly accepted again.

## 23.13.2 Frequency of Clock Input for Audio

The frequency of the clock input to the AUDIO_X1 and AUDIO_X2 or AUDIO_CLK must be lower than the B  frequency.
