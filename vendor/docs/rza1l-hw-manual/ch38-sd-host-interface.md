# 38. SD Host Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2091–2144. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

Note: • SD Host/Ancillary Product License Agreement (SD HALA) is required to develop SD host-related products.

## 38.1 Overview

## 38.1.1 Features

- SD memory/IO card interface (1-bit/4-bit SD bus)

- SD memory card: SD, SDHC, SDXC

- Transfer mode: Default mode, High-Speed mode

- SD clock (SD_CLK) frequency = 1/2[n] P1φ (Peripheral clock 1) frequency (n = 1 to 9)

- Error check function: CRC7 (for command/response), CRC16 (for data)

- Three interrupt requests

- DMA transfer request: SD_BUF read/write

- Card detect function

- Write protect support

## 38.1.2 Block Diagram

Figure 38.1 shows a block diagram of the SD host interface.

**==> picture [367 x 159] intentionally omitted <==**

**----- Start of picture text -----**<br>
Peripheral bus 1<br>SD host interface<br>Peripheral clock 1<br>(P1) Host I/F SD I/F<br>SD card<br>interface SD<br>Interrupt requests card<br>DMA transfer requests<br>SD_BUF<br>(512 bytes × 2)<br>**----- End of picture text -----**<br>

**Figure 38.1 Block Diagram of SD Host Interface**

## 38.1.3 Input/Output Pins

Table 38.1 lists the input and output pins used by the SD host interface.

## **Table 38.1 Pin Configuration**

|**Pin Name**|**Signal Name**|**I/O**|**Function**|
|---|---|---|---|
|SD_CLK[1:0]*1|SDCLK|Output|SD clock|
|SD_CMD[1:0]*1|SDCMD|I/O|Command/response|
|SD_D0[1:0]*1|SDDAT0|I/O|Data[bit 0]|
|SD_D1[1:0]*1|SDDAT1|I/O|Data[bit 1]/SDIO interrupt|
|SD_D2[1:0]*1|SDDAT2|I/O|Data[bit 2]/Read wait|
|SD_D3[1:0]*1|SDDAT3|I/O|Data[bit 3]|
|SD_CD[1:0]*1|ISDCD|Input|Card detect*2|
|SD_WP[1:0]*1|ISDWP|Input|Write protect*2|

Note 1. [1:0] indicates the SD Host Interface channel number. Note 2. When a pin is not in use, fix the corresponding signal to 1.

## 38.2 Register Descriptions

Table 38.2 summaries the registers of the SD host interface.

## **Table 38.2 Register Configuration**

|**Channel**|**Register Name**|**Abbreviation**<br>**Address**<br>**Access**<br>**Size**|
|---|---|---|
|0|Command type register|SD_CMD<br>H'E804E000<br>16|
||SD command argument registers|SD_ARG0<br>H'E804E004<br>16|
|||SD_ARG1<br>H'E804E006<br>16|
||Data stop register|SD_STOP<br>H'E804E008<br>16|
||Block count register|SD_SECCNT<br>H'E804E00A<br>16|
||SD card response registers|SD_RSP00<br>H'E804E00C<br>16|
|||SD_RSP01<br>H'E804E00E<br>16|
|||SD_RSP02<br>H'E804E010<br>16|
|||SD_RSP03<br>H'E804E012<br>16|
|||SD_RSP04<br>H'E804E014<br>16|
|||SD_RSP05<br>H'E804E016<br>16|
|||SD_RSP06<br>H'E804E018<br>16|
|||SD_RSP07<br>H'E804E01A<br>16|
||SD card interrupt flag register 1|SD_INFO1<br>H'E804E01C<br>16|
||SD card interrupt flag register 2|SD_INFO2<br>H'E804E01E<br>16|
||SD_INFO1 interrupt mask register|SD_INFO1_MASK<br>H'E804E020<br>16|
||SD_INFO2 interrupt mask register|SD_INFO2_MASK<br>H'E804E022<br>16|
||SD clock control register|SD_CLK_CTRL<br>H'E804E024<br>16|
||Transfer data length register|SD_SIZE<br>H'E804E026<br>16|
||SD card access control option register|SD_OPTION<br>H'E804E028<br>16|
||SD error status register 1|SD_ERR_STS1<br>H'E804E02C<br>16|
||SD error status register 2|SD_ERR_STS2<br>H'E804E02E<br>16|
||SD buffer read/write register|SD_BUF0<br>H'E804E030<br>32|
||SDIO mode control register|SDIO_MODE<br>H'E804E034<br>16|
||SDIO interrupt flag register|SDIO_INFO1<br>H'E804E036<br>16|
||SDIO_INFO1 interrupt mask register|SDIO_INFO1_MASK<br>H'E804E038<br>16|
||DMA mode enable register|CC_EXT_MODE<br>H'E804E0D8<br>16|
||Software reset register|SOFT_RST<br>H'E804E0E0<br>16|
||Version register|VERSION<br>H'E804E0E2<br>16|
||Swap control register|EXT_SWAP<br>H'E804E0F0<br>16|

|**Channel**|**Register Name**|**Abbreviation**<br>**Address**<br>**Access**<br>**Size**|
|---|---|---|
|1|Command type register|SD_CMD<br>H'E804E800<br>16|
||SD command argument registers|SD_ARG0<br>H'E804E804<br>16|
|||SD_ARG1<br>H'E804E806<br>16|
||Data stop register|SD_STOP<br>H'E804E808<br>16|
||Block count register|SD_SECCNT<br>H'E804E80A<br>16|
||SD card response registers|SD_RSP00<br>H'E804E80C<br>16|
|||SD_RSP01<br>H'E804E80E<br>16|
|||SD_RSP02<br>H'E804E810<br>16|
|||SD_RSP03<br>H'E804E812<br>16|
|||SD_RSP04<br>H'E804E814<br>16|
|||SD_RSP05<br>H'E804E816<br>16|
|||SD_RSP06<br>H'E804E818<br>16|
|||SD_RSP07<br>H'E804E81A<br>16|
||SD card interrupt flag register 1|SD_INFO1<br>H'E804E81C<br>16|
||SD card interrupt flag register 2|SD_INFO2<br>H'E804E81E<br>16|
||SD_INFO1 interrupt mask register|SD_INFO1_MASK<br>H'E804E820<br>16|
||SD_INFO2 interrupt mask register|SD_INFO2_MASK<br>H'E804E822<br>16|
||SD clock control register|SD_CLK_CTRL<br>H'E804E824<br>16|
||Transfer data length register|SD_SIZE<br>H'E804E826<br>16|
||SD card access control option register|SD_OPTION<br>H'E804E828<br>16|
||SD error status register 1|SD_ERR_STS1<br>H'E804E82C<br>16|
||SD error status register 2|SD_ERR_STS2<br>H'E804E82E<br>16|
||SD buffer read/write register|SD_BUF0<br>H'E804E830<br>32|
||SDIO mode control register|SDIO_MODE<br>H'E804E834<br>16|
||SDIO interrupt flag register|SDIO_INFO1<br>H'E804E836<br>16|
||SDIO_INFO1 interrupt mask register|SDIO_INFO1_MASK<br>H'E804E838<br>16|
||DMA mode enable register|CC_EXT_MODE<br>H'E804E8D8<br>16|
||Software reset register|SOFT_RST<br>H'E804E8E0<br>16|
||Version register|VERSION<br>H'E804E8E2<br>16|
||Swap control register|EXT_SWAP<br>H'E804E8F0<br>16|

## 38.2.1 Command Type Register (SD_CMD)

The command type register (SD_CMD) selects the command type and response type. The command sequence is started by writing to SD_CMD. For details on the SD_CMD setting, refer to section 38.4.10, Example of SD_CMD Register Setting .

Do not write to SD_CMD while the SCLKDIVEN bit in SD_INFO2 is set to 0.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|MD7|0|R/W|Multiple Block Transfer Mode (enabled at multiple block transfer)|
|14|MD6|0|R/W|00: CMD12 is automatically issued at multiple block transfer.<br>01: CMD12 is not automatically issued at multiple block transfer.|
|||||10: Setting prohibited|
|||||11: Setting prohibited|
|13|MD5|0|R/W|Single/Multiple Block Transfer (enabled when the command with data is|
|||||handled)|
|||||0: Single block transfer|
|||||1: Multiple block transfer|
|12|MD4|0|R/W|Write/Read Mode (enabled when the command with data is handled)|
|||||0: Write (SD host interface → SD card)|
|||||1: Read (SD host interface ← SD card)|
|11|MD3|0|R/W|Data Mode (Command Type)|
|||||0: Command without data transfer (bc, bcr, ac)|
|||||1: Command with data transfer (adtc)|
|10|MD2|0|R/W|Mode/Response Type|
|9|MD1|0|R/W|000: Normal mode<br>The response type and the transfer mode are selected by SD_CMD[7:0],|
|8|MD0|0|R/W|and the SD_CMD[15:11] setting is disabled.|
|||||001: Setting prohibited|
|||||010: Setting prohibited|
|||||011: Extended mode/No response|
|||||100: Extended mode/SD card R1, R5, R6, R7 response|
|||||101: Extended mode/SD card R1b response|
|||||110: Extended mode/SD card R2 response|
|||||111: Extended mode/SD card R3, R4 response|
|||||As some commands cannot be used in normal mode, see section|
|||||38.4.10, Example of SD_CMD Register Setting to select mode/response|
|||||type.|
|7|C1|0|R/W|00: CMD|
|6|C0|0|R/W|01: ACMD<br>10: Setting prohibited|
|||||11: Setting prohibited|
|5|CF45|0|R/W|Command Index|
|4|CF44|0|R/W|These bits specify Command Format[45:40] (command index).<br>[Examples]|
|3|CF43|0|R/W|CMD6: SD_CMD[7:0] = 8'b00_000110|
|2|CF42|0|R/W|CMD18: SD_CMD[7:0] = 8'b00_010010|
|||||ACMD13: SD_CMD[7:0] = 8'b01_001101|
|1|CF41|0|R/W||
|0|CF40|0|R/W||

Note: • SD_CMD cannot be written to when the CBSY bit in SD_INFO2 is 1.

## 38.2.2 SD Command Argument Registers (SD_ARG)

The SD command argument registers (SD_ARG) set the command argument of SD card. Set the command argument before writing to SD_CMD.

##  SD_ARG0

||||**Initial**|||
|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to 0|CF23 to CF8|All 0|R/W|Set command format[23:8] (argument)|
||SD_ARG1|||||
||||**Initial**|||
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to 0|CF39 to CF24|All 0|R/W|Set command format[39:24] (argument)|

## 38.2.3 Data STOP Register (SD_STOP)

The data stop register (SD_STOP) is used to enable or disable block counting at multiple block transfer, and to control the issuing of CMD12 within command sequences.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 9|—|All 0|R|Fixed 0|
|8|SEC|0*1|R/W|Block Count Enable*2|
|||||0: Disables SD_SECCNT setting value.|
|||||1: Enables SD_SECCNT setting value.|
|||||Set SEC to 1 at multiple block transfer.|
|||||When SD_CMD is set as follows to start the command sequence while|
|||||SEC is set to 1, CMD12 is automatically issued.|
|||||1. CMD18 or CMD25 in normal mode (SD_CMD[10:8] = 000)|
|||||2. SD_CMD[15:13] = 001 in extended mode (CMD12 is automatically|
|||||issued, multiple block transfer)|
|||||When the command sequence is halted because of a communications|
|||||error or timeout, CMD12 is not automatically issued.|
|7 to 1|—|All 0|R|Fixed 0|
|0|STP|0*1|R/W|Stop*3|
|||||When STP is set to 1 during multiple block transfer, CMD12 is issued to|
|||||halt the transfer through the SD host interface.|
|||||However, if a command sequence is halted because of a|
|||||communications error or timeout, CMD12 is not issued. Although|
|||||continued buffer access is possible even after STP has been set to 1,|
|||||the buffer access error bit (ERR5 or ERR4) in SD_INFO2 will be set|
|||||accordingly.|
|||||When STP has been set to 1 during transfer for single block write, the|
|||||access end flag is set when SD_BUF becomes empty, and CMD12 is|
|||||not issued. If SD_BUF does contain data, the access end flag is set on|
|||||completion of reception of the busy state without CMD12 having been|
|||||issued.|
|||||When STP has been set to 1 during transfer for single block read, the|
|||||access end flag is set immediately after setting of the STP bit and|
|||||CMD12 is not issued.|
|||||When STP is set to 1 during reception of the busy state after an R1b|
|||||response, the access end flag is set on completion of reception of the|
|||||busy state without CMD12 having been issued.|
|||||When STP is set to 1 after a command sequence has been completed,|
|||||CMD12 is not issued and the access end flag is not set.|

Note 1. The initial value is applied at a reset and when the SDRST bit in SOFT_RST is 0.

Note 2. Do not change the value of this bit when the SCLKDIVEN bit in SD_INFO2 is set to 0.

Note 3. Do not change the value of this bit from 1 to 0 when the SCLKDIVEN bit in SD_INFO2 is set to 0.

## 38.2.4 Block Count Register (SD_SECCNT)

The block count register (SD_SECCNT) specifies the number of transfer blocks at multiple block transfer.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to|0|CNT15 to CNT0|All 0|R/W|Number of Transfer Blocks*1|
|||||||When 0x0001 is set, the number of transfer blocks is 1.|
|||||||:|
|||||||When 0xFFFF is set, the number of transfer blocks is 65535.|
|||||||However, when 0x0000 is set, the number of transfer blocks is 65536.|

Note 1. Do not change the value of this bit when the SCLKDIVEN bit in SD_INFO2 is set to 0.

## 38.2.5 SD Card Response Registers (SD_RSP)

The SD card response registers (SD_RSP) store the response from the SD card.

##  SD_RSP00

||||**Initial**|||
|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to 0|R23 to R8|All 0|R|Store the response from the SD card|
||SD_RSP01|||||
||||**Initial**|||
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to 0|R39 to R24|All 0|R|Store the response from the SD card|
||SD_RSP02|||||
||||**Initial**|||
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to 0|R55 to R40|All 0|R|Store the response from the SD card|
||SD_RSP03|||||
||||**Initial**|||
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to 0|R71 to R56|All 0|R|Store the response from the SD card|
||SD_RSP04|||||
||||**Initial**|||
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to 0|R87 to R72|All 0|R|Store the response from the SD card|
||SD_RSP05|||||
||||**Initial**|||
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to 0|R103 to R88|All 0|R|Store the response from the SD card|

##  SD_RSP06

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to|0|R119 to R104|All 0|R|Store the response from the SD card|

##  SD_RSP07

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 8|—|All 0|R|Fixed 0|
|7 to 0|R127 to R120|All 0|R|Store the response from the SD card|

Table 38.3 lists the response types and corresponding SD_RSP registers.

**Table 38.3 Response Types and Corresponding SD_RSP Registers**

|**Table 38.3**<br>**Response Types**|**and Corresponding SD_RSP Registers**|
|---|---|
|**Response Types**|**SD_RSP Registers**|
|R1, R1b[39:8]|SD_RSP01 and SD_RSP00|
|R2[127:8]|SD_RSP07 to SD_RSP00|
|R3[39:8]|SD_RSP01 and SD_RSP00|
|R4[39:8]|SD_RSP01 and SD_RSP00|
|R5[39:8]|SD_RSP01 and SD_RSP00|
|R6[39:8]|SD_RSP01 and SD_RSP00|
|R7[39:8]|SD_RSP01 and SD_RSP00|

## 38.2.6 SD Card Interrupt Flag Register 1 (SD_INFO1)

The SD card interrupt flag register 1 (SD_INFO1) indicates the response end and access end in the command sequence. This register also indicates the card detect/write protect state.

For CMD12 and CMD52 (SDIO abort) at multiple block transfer, INFO0 is not set but only INFO2 is set.

Even if the command sequence is halted because of a communications error or timeout, INFO0 or INFO2 is set.

INFO10, INFO9, and INFO8 change depending on the SD_D3 state after a reset is released and continue to change in 4- bit transfer mode.

To clear a flag, write 0 to the bit to be cleared and 1 to the other bits.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to|11|—|All 0|R|Fixed 0|
|10|||INFO10|Unknown|R|Indicates the SD_D3 state.|
|||||||1: SD_D3 is set to 1.|
|||||||0: SD_D3 is set to 0.|
|9|||INFO9|0|R/W*1|SD_D3 set|
|||||||[Setting condition]|
|||||||After change in SD_D3 from 0 to 1, two cycles of P1has elapsed with|
|||||||SD_D3 held 1.|
|||||||[Clearing condition]|
|||||||When 0 is written to INFO9|
|8|||INFO8|0|R/W*1|SD_D3 clear|
|||||||[Setting condition]|
|||||||After change in SD_D3 from 1 to 0, two cycles of P1has elapsed with|
|||||||SD_D3 held 0.|
|||||||[Clearing condition]|
|||||||When 0 is written to INFO8|
|7|||INFO7|Unknown|R|Write Protect|
|||||||Indicates the SD_WP state.|
|||||||1: SD_WP is set to 0.|
|||||||0: SD_WP is set to 1.|
|6|||—|0|R|Fixed 0|
|5|||INFO5|Unknown|R|Indicates the SD_CD state.|
|||||||1: Indicates that Ncycle has elapsed with SD_CD held 0.|
|||||||0: Indicates that Ncycle has elapsed with SD_CD held 1.|
|||||||Ncycle is set by bits 3 to 0 in SD_OPTION.|
|4|||INFO4|0|R/W*1|SD_CD Card Insertion|
|||||||[Setting condition]|
|||||||After change in SD_CD from 1 to 0, Ncycle has elapsed with SD_CD held|
|||||||0.|
|||||||[Clearing condition]|
|||||||When 0 is written to INFO4|
|||||||Ncycle is set by bits 3 to 0 in SD_OPTION.|
|3|||INFO3|0|R/W*1|SD_CD Card Removal|
|||||||[Setting condition]|
|||||||After change in SD_CD from 0 to 1, Ncycle has elapsed with SD_CD held|
|||||||1.|
|||||||[Clearing condition]|
|||||||When 0 is written to INFO3|
|||||||Ncycle is set by bits 3 to 0 in SD_OPTION.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|2|INFO2|0*2|R/W*1|Access End|
|||||[Setting conditions]|
|||||When read access to the buffer is completed in the case of transfer for|
|||||single block read|
|||||When read access to the buffer for the last block of data is completed in|
|||||the case of transfer for multiple block read|
|||||When read access to the buffer and reception of the response to|
|||||CMD12 are completed in the case of transfer for multiple block read|
|||||with automatic issuing of CMD12|
|||||When reception of the busy state after reception of the CRC status is|
|||||completed in the case of transfer for single block write|
|||||When reception of the busy state after reception of the CRC status of|
|||||the last block of data is completed in the case of transfer for multiple|
|||||block write|
|||||When reception of the response busy state for CMD12 is completed in|
|||||the case of transfer for multiple block write with automatic issuing of|
|||||CMD12|
|||||When reception of the response to CMD12 that was issued by setting|
|||||the STP bit to1 is completed in the case of transfer for multiple block|
|||||read|
|||||When reception of the response busy state for CMD12 that was issued|
|||||by setting the STP bit to1 is completed in the case of transfer for|
|||||multiple block write|
|||||When reception of the response to CMD52 that was issued by setting|
|||||the IOABT bit to1 is completed in the case of transfer for multiple block|
|||||read|
|||||When reception of the response to CMD52 that was issued by setting|
|||||the IOABT bit to1 is completed in the case of transfer for multiple block|
|||||write|
|||||In addition to the above conditions, this bit is set when a command|
|||||sequence is halted because of a communications error or timeout.|
|||||[Clearing condition]|
|||||When 0 is written to INFO2|
|1|—|0|R|Fixed 0|
|0|INFO0|0*2|R/W*1|Response End|
|||||[Setting conditions]|
|||||When reception of the response is completed|
|||||When transmission of a command without response is completed|
|||||When reception of the busy state after R1b response is completed|
|||||When reception of the response to CMD52 that was issued by setting|
|||||the C52PUB bit to1 is completed in the case of transfer for multiple|
|||||block read|
|||||When reception of the response to CMD52 that was issued by setting|
|||||the C52PUB bit to1 is completed in the case of transfer for multiple|
|||||block write|
|||||In addition to the above conditions, this bit is set when a command|
|||||sequence is halted because of a communications error or timeout.|
|||||[Clearing condition]|
|||||When 0 is written to INFO0|

Note 1. It is effective only if 0 is written.

Note 2. The initial value is applied at a reset and when the SDRST bit in SOFT_RST is 0.

## 38.2.7 SD Card Interrupt Flag Register 2 (SD_INFO2)

The SD card interrupt flag register 2 (SD_INFO2) indicates the access status of the SD buffer (SD_BUF) and SD card. To clear a flag, write 0 to the bit to be cleared and 1 to the other bits.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|ILA|0*2|R/W*1|Illegal Access Error|
|||||[Setting conditions]|
|||||When data is written to SD_CMD within a command sequence|
|||||When SD_CMD[10:8] = 3'b011 (no response) and SD_CMD[11] = 1'b1|
|||||(command with data transfer) are set in SD_CMD|
|||||When SD_CMD[11] = 1'b1 (command with data transfer) and|
|||||SD_CMD[7:0] = 8'b00001100 (CMD12) are set in SD_CMD|
|||||[Clearing condition]|
|||||When 0 is written to ILA|
|14|CBSY|0*2|R|Command Type Register Busy|
|||||1: The command sequence is being executed.|
|||||0: The command sequence is ended.|
|13|SCLKDIVEN|1*2|R|SD Bus Busy|
|||||1: SD buses (CMD and DAT) are not busy.|
|||||0: SD buses (CMD and DAT) are busy.|
|||||When a command sequence is started by writing to SD_CMD, CBSY is|
|||||set to 1. At the same time, SCLKDIVEN is set to 0.|
|||||After CBSY has been set to 0 at the end of the command sequence,|
|||||SCLKDIVEN is set to 1 when 8 cycles of SD_CLK elapses.|
|12|—|0|R|Fixed 0|
|11|—|0*2|R/W*1|Reserved. The write value should always be 1.|
|10|—|0|R|Fixed 0|
|9|BWE|0*2|R/W*1|SD_BUF Write Enable|
|||||1: Data can be written in SD_BUF0.|
|||||0: Data cannot be written in SD_BUF0.|
|||||[Setting conditions]|
|||||When SD_BUF is empty at single block transfer|
|||||When either bank 1 or bank 2 of SD_BUF is empty at multiple block|
|||||transfer|
|||||[Clearing condition]|
|||||When 0 is written to BWE|
|||||When data is written to SD_BUF0 by the CPU, clear BWE and then write|
|||||amount of data specified by SD_SIZE*3. Note that this bit is not set when|
|||||the SD_BUF read/write DMA transfer is enabled by setting the|
|||||DMASDRW bit in CC_EXT_ MODE to 1.|
|8|BRE|0*2|R/W*1|SD_BUF Read Enable|
|||||1: Data can be read from SD_BUF0.|
|||||0: Data cannot be read from SD_BUF0.|
|||||[Setting conditions]|
|||||When data set in SD_SIZE is stored in SD_BUF at single block transfer|
|||||When data set in SD_SIZE is stored in either bank 1 or bank 2 of|
|||||SD_BUF at multiple block transfer|
|||||[Clearing condition]|
|||||When 0 is written to BRE|
|||||When data is read from SD_BUF0 by the CPU, clear BRE and then read|
|||||amount of data specified by SD_SIZE*3. Note that this bit is not set when|
|||||the SD_BUF read/write DMA transfer is enabled by setting the|
|||||DMASDRW bit in CC_EXT_ MODE to 1.|
|||||Even if a CRC error or an END error occurs while block data is read, data|
|||||is stored in SD_BUF and BRE is set.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|DAT0|Unknown|R|SD_D0|
|||||Indicates the SD_D0 state|
|||||1: SD_D0 is set to 1.|
|||||0: SD_D0 is set to 0.|
|||||If the data timeout (ERR3) is set but the response timeout (ERR6) is not|
|||||set after the Erase command has been issued, the end of the Erase|
|||||sequence (DAT0 = 1) is confirmed by polling DAT0.|
|||||If a communications error or timeout occurs during a write sequence, the|
|||||DAT0 bit may retain the value 0.|
|6|ERR6|0*2|R/W*1|Response Timeout|
|||||[Setting condition]|
|||||When a response is not received though a longer time than 640 cycles of|
|||||SD_CLK has elapsed|
|||||[Clearing condition]|
|||||When 0 is written to ERR6|
|||||The command sequence is halted by the response timeout.*4|
|5|ERR5|0*2|R/W*1|SD_BUF Illegal Read Access|
|||||[Setting conditions]|
|||||When SD_BUF is empty while SD_BUF0 is read|
|||||When data with a CRC error or END error is read from SD_BUF0|
|||||[Clearing condition]|
|||||When 0 is written to ERR5|
|4|ERR4|0*2|R/W*1|SD_BUF Illegal Write Access|
|||||[Setting conditions]|
|||||When data is written to SD_BUF0 while it is not in the data read/write|
|||||command state|
|||||When data is written to SD_BUF0 while SD_BUF is full.|
|||||When data is written to SD_BUF0 while an error occurs in the CRC|
|||||status or CRC status length.|
|||||When data is written to SD_BUF0 while a busy state after the CRC|
|||||status continues for longer than Ncycle|
|||||[Clearing condition]|
|||||When 0 is written to ERR4|
|||||Ncycle is set by bits 7 to 4 in SD_OPTION.|
|3|ERR3|0*2|R/W*1|Data Timeout (except response timeout)|
|||||[Setting conditions]|
|||||After R1b response, the busy state (SD_D0 = 0) continues for longer|
|||||than Ncycle.|
|||||After CRC status, the busy state (SD_D0 = 0) continues for longer than|
|||||Ncycle.|
|||||After write data, the CRC status is not received though Ncycle has|
|||||elapsed.|
|||||After read command, read data is not received though a longer time|
|||||than Ncycle has elapsed.|
|||||After CMD12 has been issued within a command sequence, the busy|
|||||state (SD_D0 = 0) for longer than Ncycle continues.|
|||||After the reception of read data, read data for the next block are not|
|||||received though a longer time than Ncycle has elapsed.|
|||||After release of the read wait state, read data for the next block are not|
|||||received though a longer time than Ncycle has elapsed.|
|||||[Clearing condition]|
|||||When 0 is written to ERR3|
|||||Ncycle is set by bits 7 to 4 in SD_OPTION.|
|||||The command sequence is halted by the data timeout.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|2|ERR2|0*2|R/W*1|END Error|
|||||[Setting conditions]|
|||||When an error occurs in the response length (and the end bit has not|
|||||been detected)|
|||||When an error occurs in the read data length (and the end bit has not|
|||||been detected among the valid bits)|
|||||When an error occurs in the CRC status length (and the end bit has not|
|||||been detected)|
|||||[Clearing condition]|
|||||When 0 is written to ERR2|
|||||The command sequence is halted by the End error.*4|
|1|ERR1|0*2|R/W*1|CRC Error|
|||||[Setting conditions]|
|||||When an error occurs in the CRC status|
|||||When a CRC error occurs in the read data|
|||||When a CRC error occurs in the response|
|||||[Clearing condition]|
|||||When 0 is written to ERR1|
|||||The command sequence is halted by the CRC error.*4|
|0|ERR0|0*2|R/W*1|CMD Error|
|||||[Setting condition]|
|||||When the command index of the transmitted command differed from the|
|||||command index of the received response|
|||||[Clearing condition]|
|||||When 0 is written to ERR0|
|||||The command sequence is halted by the CMD error.*4|

Note 1. It is effective only if 0 is written.

Note 2. The initial value is applied at a reset and when the SDRST bit in SOFT_RST is 0.

- Note 3. The single byte or three bytes from the fraction of a full 32-bit unit are regarded as excess data due to an odd value for the number of bytes setting in SD_SIZE, or the two bytes from the fraction of a full 32-bit unit are regarded as excess data due if the value for the number of bytes setting in SD_SIZE is even but is not on a four-byte boundary.

- Note 4. After the C52PUB bit in SDIO_MODE has been set to 1, if a communications error or timeout for response occurs in response to the CMD52 that is issued, since the command sequence has not been completed, complete the sequence with error processing as in usage examples in Figure 38.17 under section 38.4.7, IO_RW_EXTENDED Command (CMD53/Multiple Block Read) or in Figure 38.20 under section 38.4.8, IO_RW_EXTENDED Command (CMD53/Multiple Block Write).

## 38.2.8 SD_INFO1 Interrupt Mask Register (SD_INFO1_MASK)

The SD_INFO1 interrupt mask register (SD_INFO1_MASK) enables or disables the SD_INFO1 interrupt. When 0 is set in SD_INFO1_MASK while the corresponding flag in SD_INFO1 is set, an interrupt occurs.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 10|—|All 0|R|Fixed 0|
|9|IMASK9|1|R/W|INFO9 interrupt masked|
|8|IMASK8|1|R/W|INFO8 interrupt masked|
|7 to 5|—|All 0|R|Fixed 0|
|4|IMASK4|1|R/W|INFO4 interrupt masked|
|3|IMASK3|1|R/W|INFO3 interrupt masked|
|2|IMASK2|1|R/W|INFO2 interrupt masked|
|1|—|0|R|Fixed 0|
|0|IMASK0|1|R/W|INFO0 interrupt masked|

## 38.2.9 SD_INFO2 Interrupt Mask Register (SD_INFO2_MASK)

The SD_INFO2 interrupt mask register (SD_INFO2_MASK) enables or disables the SD_INFO2 interrupt. When 0 is set in SD_INFO2_MASK while the corresponding flag in SD_INFO2 is set, an interrupt occurs.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|||IMASK|1|R/W|ILA interrupt masked|
|14|to|12|—|All 0|R|Fixed 0|
|11|||—|1|R/W|Reserved. The write value should always be 1.|
|10|||—|0|R|Fixed 0|
|9|||BMASK1|1|R/W|BWE interrupt masked|
|8|||BMASK0|1|R/W|BRE interrupt masked|
|7|||—|0|R|Fixed 0|
|6|||EMASK6|1|R/W|ERR6 interrupt masked|
|5|||EMASK5|1|R/W|ERR5 interrupt masked|
|4|||EMASK4|1|R/W|ERR4 interrupt masked|
|3|||EMASK3|1|R/W|ERR3 interrupt masked|
|2|||EMASK2|1|R/W|ERR2 interrupt masked|
|1|||EMASK1|1|R/W|ERR1 interrupt masked|
|0|||EMASK0|1|R/W|ERR0 interrupt masked|

## 38.2.10 SD Clock Control Register (SD_CLK_CTRL)

The SD clock control register (SD_CLK_CTRL) controls the SD clock (SD_CLK) output and sets the frequency. Set SCLKEN to 1 before writing to SD_CMD to issue a command.

Do not write to SD_CLK_CTRL while the SCLKDIVEN bit in SD_INFO2 is set to 0.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to|10|—|All 0|R|Fixed 0|
|9|||SDCLKOFFEN|0|R/W|SD Clock (SD_CLK) Output Automatic Control Enable|
|||||||0: Automatic control for SD clock (SD_CLK) output is disabled.|
|||||||1: Automatic control for SD clock (SD_CLK) output is enabled.|
|||||||This function of automatic control for SD clock (SD_CLK) output causes|
|||||||SD_CLK output only within a command sequence.|
|||||||The timing with which SD_CLK output starts and stops is as follows.|
|||||||SD_CLK output starts after writing to SD_CMD.|
|||||||SD_CLK output stops when 8 cycles of SD_CLK have elapsed after the|
|||||||end of the command sequence.|
|||||||In addition, automatic control for SD clock (SD_CLK) output is enabled|
|||||||when SCLKEN in SD_CLK_CTRL is 1.|
|8|||SCLKEN|0*1|R/W*2|SD Clock (SD_CLK) Output Control Enable|
|||||||0: SD clock (SD_CLK) output is disabled. The SD_CLK signal is fixed 0.|
|||||||1: SD clock (SD_CLK) output is enabled.|
|7|||DIV7|0|R/W*2|SD Clock (SD_CLK)|
|6|||DIV6|0|R/W*2|10000000: P1/512<br>01000000: P1/256|
|5|||DIV5|1|R/W*2|00100000: P1/128|
|4|||DIV4|0|R/W*2|00010000: P1/64|
|||||||00001000: P1/32|
|3|||DIV3|0|R/W*2|00000100: P1/16|
|2|||DIV2|0|R/W*2|00000010: P1/8|
|1|||DIV1|0|R/W*2|00000001: P1/4<br>00000000: P1/2|
|0|||DIV0|0|R/W*2|Other settings are prohibited.|

Note 1. This initial value is applied at a reset and when the SDRST bit in SOFT_RST is 0. Note 2. Writing is impossible when the CBSY bit in SD_INFO2 is 1.

## 38.2.11 Transfer Data Length Register (SD_SIZE)

The transfer data length register (SD_SIZE) specifies the transfer data size.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 12|—|All 0|R|Fixed 0|
|11, 10|—|All 0|R|Reserved|
|9 to 0|LEN9 to LEN0|1000000000|R/W|Transfer Data Size*1|
|||||These bits specify a size between 1 and 512 bytes for the transfer of|
|||||single blocks.|
|||||In cases of multiple block transfer with automatic issuing of CMD12|
|||||(CMD18 and CMD25), the only specifiable transfer data size is 512 bytes.|
|||||Furthermore, in cases of multiple block transfer without automatic issuing|
|||||of CMD12, as well as 512 bytes, 32, 64, 128, and 256 bytes are|
|||||specifiable. However, in the reading of 32, 64, 128, and 256 bytes for the|
|||||transfer of multiple blocks, this is restricted to cases of multiple block|
|||||transfer by CMD53. Additionally, if a command accompanies data|
|||||transfer, do not set these bits to 0.|

Note 1. Do not change the values of these bits when the SCLKDIVEN bit in SD_INFO2 is 0.

## 38.2.12 SD Card Access Control Option Register (SD_OPTION)

The SD card access control option register (SD_OPTION) sets the bus width and timeout counter.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|||WIDTH|0*1|R/W|Bus Width*2|
|||||||0: 4-bit width|
|||||||1: 1-bit width|
|14|||—|1|R|Fixed 1|
|13|to|8|—|All 0|R|Fixed 0|
|7|||TOP27|1*1|R/W|Timeout Counter*2|
|6|||TOP26|1*1|R/W|1111: Setting prohibited<br>1110: SD_CLK227|
|5|||TOP25|1*1|R/W|1101: SD_CLK226|
|4|||TOP24|0*1|R/W|:<br>0001: SD_CLK214|
|||||||0000: SD_CLK213|
|3|||CTOP24|1*1|R/W|Card Detect Time Counter|
|2|||CTOP23|1*1|R/W|1111: Setting prohibited<br>1110: P1 224|
|1|||CTOP22|1*1|R/W|1101: P1 223|
|0|||CTOP21|0*1|R/W|:<br>0001: P1 211|
|||||||0000: P1 210|

Note 1. The initial value is applied at a reset and when the SDRST bit in SOFT_RST is 0. Note 2. Do not change the values of these bits when the SCLKDIVEN bit in SD_INFO2 is 0.

## 38.2.13 SD Error Status Register 1 (SD_ERR_STS1)

The SD error status register 1 (SD_ERR_STS1) indicates the CRC status, CRC error, End error, and CMD error.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|—|0|R|Fixed 0|
|14|E14|0*1|R|These bits store the CRC status. (normal: 010)|
|13|E13|1*1|R||
|12|E12|0*1|R||
|11|E11|0*1|R|Set to 1 when an error occurs in the CRC status|
|10|E10|0*1|R|Set to 1 when a CRC error occurs in the read data|
|9|E9|0*1|R|Set to 1 when a CRC error occurs in the response to a command*2|
|||||issued within a command sequence. In cases where CMD12 is issued by|
|||||setting a command index in SD_CMD, this is indicated in E8.|
|8|E8|0*1|R|Set to 1 when a CRC error occurs in a response (other than a response to|
|||||a command*2issued within a command sequence)|
|7, 6|—|All 0|R|Fixed 0|
|5|E5|0*1|R|Set to 1 when an error occurs in the CRC status length (and the end bit|
|||||has not been detected)|
|4|E4|0*1|R|Set to 1 when an error occurs in the read data length (and the end bit has|
|||||not been detected among the valid bits)|
|3|E3|0*1|R|Set to 1 when an error occurs in the response length to a command*2|
|||||issued within a command sequence. In cases where CMD12 is issued by|
|||||setting a command index in SD_CMD, this is indicated in E2.|
|2|E2|0*1|R|Set to 1 when an error occurs in the response length (other than a|
|||||response to a command*2issued within a command sequence)|
|1|E1|0*1|R|Set to 1 when an error occurs in the command index of the response to a|
|||||command*2issued within a command sequence. In cases where CMD12|
|||||is issued by setting a command index in SD_CMD, this is Indicated in E0.|
|0|E0|0*1|R|Set to 1 when an error occurs in the command index of a response (other|
|||||than a response to a command*2issued within a command sequence).|

Note 1. The initial value is applied at a reset and when the SDRST bit in SOFT_RST is 0.

Note 2. "Command issued within a command sequence" refers to CMD12 when automatic issuing is enabled for multiple block transfer by the setting in SD_CMD, CMD12 when the STP bit in SD_STOP is set to 1, or CMD52 when the C52PUB or IOABT bit in SDIO_MODE is set to 1.

## 38.2.14 SD Error Status Register 2 (SD_ERR_STS2)

The SD error status register 2 (SD_ERR_STS2) indicates the timeout state. Ncycle is set by bits 7 to 4 in SD_OPTION.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to|7|—|All 0|R|Fixed 0|
|6|||E6|0*1|R|Set to 1 when the busy state continues for longer than Ncycle after the|
|||||||CRC status|
|5|||E5|0*1|R|Set to 1 when the CRC status is not received though a longer time than|
|||||||Ncycle has elapsed after data writing|
|4|||E4|0*1|R|Set to 1 when read data is not received though a longer time than Ncycle|
|||||||has elapsed after read command.|
|||||||Set to 1 when read data for the next block are not received though a|
|||||||longer time than Ncycle has elapsed after the reception of read data.|
|||||||Set to 1 when read data for the next block are not received though a|
|||||||longer time than Ncycle has elapsed after release of the read wait state.|
|3|||E3|0*1|R|Set to 1 when the busy state for longer than Ncycle continues after|
|||||||CMD12 has been issued within a command sequence. In cases where|
|||||||CMD12 is issued by setting a command index in SD_CMD, this is|
|||||||indicated in E2.|
|2|||E2|0*1|R|Set to 1 when the busy state for longer than Ncycle continues after R1b|
|||||||response|
|1|||E1|0*1|R|Set to 1 when the response to a command*2issued within a command|
|||||||sequence is not received though a longer time than 640 cycles of|
|||||||SD_CLK has elapsed. In cases where CMD12 is issued by setting a|
|||||||command index in SD_CMD, this is indicated in E0.|
|0|||E0|0*1|R|Set to 1 when the response (other than a response to a command*2|
|||||||issued within a command sequence) is not received though a longer time|
|||||||than 640 cycles of SD_CLK has elapsed.|

- Note 1. The initial value is applied at a reset and when the SDRST bit in SOFT_RST is 0.

Note 2. "Command issued within a command sequence" refers to CMD12 when automatic issuing is enabled for multiple block transfer by the setting in SD_CMD, CMD12 when the STP bit in SD_STOP is set to 1, or CMD52 when the C52PUB or IOABT bit in SDIO_MODE is set to 1.

## 38.2.15 SD Buffer Read/Write Register (SD_BUF0)

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|0|BUF31 to BUF0|Unknown|R/W|When writing to the SD card, the write data is written to this register.|
|||||||When reading from the SD card, the read data is read from this register.|
|||||||This register is internally connected to two 512-byte (128-word) buffers.|

## 38.2.16 SDIO Mode Control Register (SDIO_MODE)

The SDIO mode control register (SDIO_MODE) controls the CMD52 issuance and the read wait state at multiple block transfer, and the reception of SDIO interrupt. C52PUB and IOABT should not be set to 1 simultaneously.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 10|—|All 0|R|Fixed 0|
|9|C52PUB|0|R/W|SDIO None Abort*2|
|||||When C52PUB is set to 1 in the CMD53 (multiple block) write|
|||||sequence, CMD52 is automatically issued if SD_BUF becomes empty|
|||||and between the current one-block and next-block. C52PUB is|
|||||automatically cleared to 0 after reception of the response to CMD52 is|
|||||completed. Additionally, if C52PUB is set to 1 while the last block is|
|||||being transferred, CMD52 is not issued. In this case, C52PUB is|
|||||automatically cleared to 0 after the access end flag has been set to 1.|
|||||When C52PUB and RWREQ are set to 1 in the CMD53 (multiple block)|
|||||read sequence, the block transfer enters the read wait state between|
|||||the current one-block and next-block and CMD52 is automatically|
|||||issued. C52PUB is automatically cleared to 0 after reception of the|
|||||response to CMD52 is completed. Additionally, if C52PUB is set to 1|
|||||while the last block is being transferred, CMD52 is not issued. In this|
|||||case, C52PUB is automatically cleared to 0 after the access end flag|
|||||has been set to 1.|
|||||If C52PUB is set to 1 in the CMD53 (multiple block) read sequence, be|
|||||sure to set RWREQ to 1 as well as C52PUB.|
|||||Set SD_ARG before setting C52PUB to 1.|
|8|IOABT|0|R/W|SDIO Abort*2|
|||||When IOABT is set to 1 in the CMD53 (multiple block) sequence, the|
|||||CMD53 sequence is halted and CMD52 is issued.|
|||||However, if a command sequence is halted because of a|
|||||communications error or timeout, CMD52 is not issued.|
|||||Although continued buffer access is possible even after IOABT has|
|||||been set to 1, the buffer access error bit (ERR5 or ERR4) in SD_INFO2|
|||||will be set accordingly. Set SD_ARG before setting IOABT to 1.|
|||||When IOABT has been set to 1 during transfer for single block write,|
|||||the access end flag is set when SD_BUF becomes empty, and CMD52|
|||||is not issued. If SD_BUF does contain data, the access end flag is set|
|||||on completion of reception of the busy state without CMD52 having|
|||||been issued.|
|||||When IOABT has been set to 1 during transfer for single block read, the|
|||||access end flag is set immediately after setting of IOABT and CMD52 is|
|||||not issued.|
|||||When IOABT is set to 1 during reception of the busy state after an R1b|
|||||response, the access end flag is set on completion of reception of the|
|||||busy state without CMD52 having been issued.|
|||||When IOABT is set to 1 after a command sequence has been|
|||||completed, CMD52 is not issued and the access end flag is not set.|
|7 to 3|—|All 0|R|Fixed 0|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|2|RWREQ|0|R/W|Read Wait Request|
|||||When RWREQ is set to 1 in the CMD53 (multiple block) read sequence,|
|||||the block transfer enters the read wait state (SD_D2 changes from 1 to 0)|
|||||between the current one-block and next-block.|
|||||[Read wait state releasing]|
|||||The read wait state is released, when RWREQ is cleared to 0 in the|
|||||read wait state.*3|
|||||When IOABT is set to 1 in the read wait state, RWREQ is automatically|
|||||cleared to 0 after CMD52 has been issued, and then the read wait state|
|||||is released.|
|||||When C52PUB and RWREQ are set to 1 simultaneously in the CMD53|
|||||(multiple block) read sequence, the read wait state is not automatically|
|||||released. Therefore, after the CMD52 response is received, clear|
|||||RWREQ.|
|||||(Be sure to set RWREQ and C52PUB simultaneously.)|
|||||When RWREQ is set to 1 while the last block in the CMD53 (multiple|
|||||block) read sequence is transferred, the read wait state is not entered|
|||||and RWREQ is automatically cleared to 0 by setting access end.|
|1|—|0|R|Fixed 0|
|0|IOMOD|0|R/W|SDIO Mode*1|
|||||1: Enables the SD host interface to receive SDIO interrupt from the SDIO|
|||||card.|
|||||0: Disables the SD host interface to receive SDIO interrupt from the SDIO|
|||||card.|

Note 1. Do not change the value of this bit when the SCLKDIVEN bit in SD_INFO2 is set to 0. Note 2. Do not change the values of these bits from 1 to 0 when the SCLKDIVEN bit in SD_INFO2 is set to 0. Note 3. Clear this bit after reception of the response to CMD52 is completed.

## 38.2.17 SDIO Interrupt Flag Register (SDIO_INFO1)

The SDIO interrupt flag register (SDIO_INFO1) indicates the status regarding to the SDIO card access. To clear a flag, write 0 to the bit to be cleared and 1 to the other bits.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|EXWT|0*2|R/W*1|[Setting condition]|
|||||While the last block in the CMD53 (multiple block) read sequence is|
|||||transferred, RWREQ in SDIO_MODE is set to 1.|
|||||[Clearing condition]|
|||||When 0 is written to EXWT|
|14|EXPUB52|0*2|R/W*1|[Setting conditions]|
|||||While the last block in the CMD53 (multiple block) sequence is|
|||||transferred, C52PUB in SDIO_MODE is set to 1.|
|||||While C52PUB is set to 1 in the CMD53 (multiple block) write|
|||||sequence, the last block is transferred.|
|||||[Clearing condition]|
|||||When 0 is written to EXPUB52|
|13 to 3|—|All 0|R|Fixed 0|
|2, 1|—|0*2|R/W*1|Reserved|
|||||The write value should always be 1.|
|0|IOIRQ|0*2|R/W*1|SD IO Interrupt|
|||||[Setting condition]|
|||||When SDIO interrupt from an SDIO card is received while IOMOD in|
|||||SDIO_MODE is set to 1|
|||||[Clearing condition]|
|||||When 0 is written to IOIRQ*3|

Note 1. It is effective only if 0 is written.

Note 2. The initial value is applied at a reset and when the SDRST bit in SOFT_RST is 0.

Note 3. Before clearing this bit, access the SDIO card to negate the SDIO interrupt signal from the SDIO card (after CMD25 has been issued and the response received). If the interrupt signal is not negated, this bit may be set again.

## 38.2.18 SDIO_INFO1 Interrupt Mask Register (SDIO_INFO1_MASK)

The SDIO_INFO1 interrupt mask register (SDIO_INFO1_MASK) enables or disables the SD_INFO1 interrupt. When 0 is set in SDIO_INFO1_MASK while the corresponding flag in SD_INFO1 is set, an interrupt occurs.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|MEXWT|1|R/W|EXWT interrupt masked|
|14|MEXPUB52|1|R/W|EXPUB52 interrupt masked|
|13 to 3|—|All 0|R|Fixed 0|
|2, 1|—|All 1|R/W|Reserved|
|||||The write value should always be 1.|
|0|IOMSK|1|R/W|IOIRQ interrupt masked|

## 38.2.19 DMA Mode Enable Register (CC_EXT_MODE)

The DMA mode enable register (CC_EXT_MODE) enables the DMA transfer.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 13|—|All 0|R|Fixed 0|
|12|—|1|R|Reserved|
|11, 10|—|All 0|R|Fixed 0|
|9, 8|—|All 0|R|Reserved|
|7 to 5|—|All 0|R|Fixed 0|
|4|—|1|R|Reserved|
|3, 2|—|All 0|R|Reserved|
|1|DMASDRW|0|R/W|SD_BUF Read/Write DMA Transfer*1|
|||||1: The SD_BUF read/write DMA transfer is enabled.|
|||||0: The SD_BUF read/write DMA transfer is disabled.|
|||||At the SD_BUF read/write DMA transfer, set DMASDRW to 1 before|
|||||setting SD_CMD.|
|0|—|0|R|Reserved|

Note 1. Do not change the values of these bits when the SCLKDIVEN bit in SD_INFO2 is set to 0.

## 38.2.20 Software Reset Register (SOFT_RST)

The software reset register (SOFT_RST) sets a software reset. Make sure to release the reset before using the SD host interface.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|to|3|—|All 0|R|Fixed 0|
|2|||—|1|R|Reserved|
|1|||—|1|R|Reserved|
|0|||SDRST|0|R/W|Software Reset of SD I/F Unit|
|||||||0: Reset|
|||||||1: Reset released|

## 38.2.21 Version Register (VERSION)

The version register (VERSION) indicates the version of the SD host interface.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 12|—|1000|R|Reserved|
|11 to 8|UR3 to UR0|4'h2|R|Version of Renesas IP|
|7 to 0|IP7 to IP0|8'h0B|R|Version of adopted IP|

## 38.2.22 Swap Control Register (EXT_SWAP)

The swap control register (EXT_SWAP) can replace data when SD_BUF0 is accessed.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|—|0|R/W|Reserved|
|||||The write value should always be 0.|
|14, 13|—|All 0|R|Reserved|
|12, 11|—|All 0|R/W|Reserved|
|||||The write value should always be 0.|
|10, 9|—|All 0|R|Fixed 0|
|8|DMASEL|0|R/W|DMA Transfer Size Select|
|||||Selects the transfer unit for SD_BUF read/write DMA transfer. Set this bit|
|||||in combination with the transfer size set in the DMA Channel|
|||||Configuration register.|
|||||0: 4-byte (longword) unit|
|||||1: 64-byte (longword16) unit|
|||||Note: • For DMA transfer in 64-byte units, set address H'E804E000|
|||||(channel 0) / H'E804E800 (channel 1) as the destination or|
|||||source of DMA transfer instead of the SD buffer read/write|
|||||register (SD_BUF0). Moreover, if a communications error or|
|||||timeout occurs during the 64-byte unit DMA transfer, this bit|
|||||should be set to 0 and re-setting again before using DMA|
|||||transfer. If a software reset occurs during the 64-byte unit DMA|
|||||transfer, this bit should be set to 0 and re-setting again before|
|||||using DMA transfer.|
|7|SDBRSWAP|0|R/W|SD_BUF0 Swap Read*1|
|||||When reading from SD_BUF0, data stored in SD_BUF0 can be replaced|
|||||and then read.*2|
|||||0: The current data is read without replacement.|
|||||1: Data replacement for reading proceeds in bytes.|
|6|SDBWSWAP|0|R/W|SD_BUF0 Swap Write*1|
|||||When writing to SD_BUF0, data to be written can be replaced and then|
|||||stored in SD_BUF0.*2|
|||||0: The current data is written without replacement.|
|||||1: Data replacement for writing proceeds in bytes.|
|5|—|0|R|Fixed 0|
|4, 3|—|All 0|R/W|Reserved|
|||||The write value should always be 0.|
|2|—|0|R|Fixed 0|
|1|—|0|R/W|Reserved|
|||||The write value should always be 0.|
|0|—|0|R|Fixed 0|

Note 1. Do not change the values of these bits when the SCLKDIVEN bit in SD_INFO2 is set to 0.

Note 2. Details on SD_BUF0 access with data replacement or non-replacement are indicated in (1) SD Data Format in section 38.3.1, SD I/F.

## 38.3 Operation

## 38.3.1 SD I/F

## (1) SD Data Format

When data is read from the SD card, the procedure is as follows.

1. The SD host interface receives data from the SD card via the SD_D signal. (SD_D signal: see Figure 38.2 and Figure 38.3 .)

2. The receive data is stored in SD_BUF of the SD host interface. (SD_BUF store data: see Figure 38.4 )

3. The data stored in SD_BUF is read by SD_BUF0. (Reading from SD_BUF0: see Figure 38.5 )

When data is written to the SD card, the above procedure will be reversed.

When accessing SD_BUF0, caution should be taken for the transfer order in SD_D and the store order in SD_BUF. In addition, data stored in SD_BUF0 can be replaced in bytes with the EXT_SWAP. (See Figure 38.5 )

|||||||||||||||||||||||||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||0<br>T<br>A<br>D<br>D<br>S|S|7|···|0||15|···||8||23|···|||6<br>1||31|||···||24||||CRC16<br>(15)||CRC16<br>(14)||||CRC16<br>(1)||CRC16<br>(0)|E||
||||Start|||Byte 0|||Byte||1||||Byte 2||||||||Byte 3||||···|||||||||||Stop||
|||||||||||||||||||||||||||||||||||||||||
|**Figure**||**38.2**|**SD_D0 in 1-Bit Width Mode**|||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||
||||||SDDAT3||S||7|3|15|11||23|19|31||27|||||CRC16<br>(15)|CRC16<br>(14)||||||CRC16<br>(1)||CRC16<br>(0)||E||||||
|||||||||||||||||||||||||||||||||||||||||
||||||SDDAT2||S||6|2|14|10||22|18|30||26|||||CRC16<br>(15)|CRC16<br>(14)||||||CRC16<br>(1)||CRC16<br>(0)||E||||||
|||||||||||||||||||||||||||||||||||||||||
||||||SDDAT1||S||5|1|13|9||21|17|29||25|||||CRC16<br>(15)|CRC16<br>(14)||||||CRC16<br>(1)||CRC16<br>(0)||E||||||
|||||||||||||||||||||||||||||||||||||||||
||||||SDDAT0||S||4|0|12|8||20|16|28||24|||||CRC16<br>(15)|CRC16<br>(14)||||||CRC16<br>(1)||CRC16<br>(0)||E||||||
|||||||Start|||Byte 0||Byte 1|||Byte 2||Byte 3||||||||||||||||||Stop||||||
|||||||||||||||||||||||||||||||||||||||||

**Figure 38.3 SD_D3 to SD_D0 in 4-Bit Width Mode**

**==> picture [396 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
Word MSB ··· ··· LSB<br>0 31 30 29 28 27 26 25 24 23 ··· 16 15 ··· 8 7 6 5 4 3 2 1 0<br>Byte 3 Byte 2 Byte 1 Byte 0<br>1 31 30 29 28 27 26 25 24 23 ··· 16 15 ··· 8 7 6 5 4 3 2 1 0<br>Byte 7 Byte 6 Byte 5 Byte 4<br>127 31 30 29 28 27 26 25 24 23 ··· 16 15 ··· 8 7 6 5 4 3 2 1 0<br>Byte 511 Byte 510 Byte 509 Byte 508<br>**----- End of picture text -----**<br>

**Figure 38.4 SD_BUF Store Data**

|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|8<br>Byte (4N + 2)<br>Byte (4N + 3)<br>SD_BUF0<br>15<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>SD_BUF0<br>···<br>16<br>···<br>Byte (4N)<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>15<br>23<br>···<br>16<br>···<br>• In case data stored in SD_BUF0 is read without replacement (the SDBRSWAP bit in EXT_SWAP = 0)<br>Byte (4N + 1)<br>Byte (4N + 1)<br>)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>)<br>N<br>4<br>(<br>e<br>ty<br>B<br>Byte (4N + 2)<br>• In case data stored in SD_BUF0 is read with replacement (the SDBRSWAP bit in EXT_SWAP = 1)<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31<br>8<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>N = 0, 1, 2 ...|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||7|6|5|4|3|2|1|0|15|···|8|23|···|16|31|30|29|28|27|26|25|24|
||||||||||||||||)<br>3<br>+<br>N<br>4<br>(<br>e<br>ty<br>B<br>N = 0, 1, 2 ...||||||||

**Figure 38.5 Reading from SD_BUF0**

## 38.3.2 Card Detect/Write Protect

## (1) Card Detect

The SD host interface has two types of card detect functions as described in the following.

- Card detect with SD_CD

Figure 38.6 shows the timing chart of card detect using SD_CD. SD_CD is connected to the card socket and pulled up on the host device. The resistance of the pull-up resistor is decided by the specification of the SD host device.

[Card insertion]

SD_CD is pulled down when a card is inserted. At this time, if SD_CD has been pulled down for the Ncycle period (set in SD_OPTION), INFO4 in SD_INFO1 is set to 1. (It is cleared to by writing 0.)

[Card removal]

SD_CD is pulled up when a card is removed. At this time, if SD_CD has been pulled up for the Ncycle period (set in SD_OPTION), INFO3 in SD_INFO1 is set to 1. (It is cleared to by writing 0.)

**==> picture [329 x 103] intentionally omitted <==**

**----- Start of picture text -----**<br>
ISDCD<br>Card  Card<br>Without card With card Without card<br>detect  detect<br>Ncycle Ncycle<br>Clear<br>ISDCD card insertion (INFO4)<br>Clear<br>ISDCD card removal (INFO3)<br>**----- End of picture text -----**<br>

**Figure 38.6 Example of Card Detect with SD_CD**

- SD card detect with SD_D3

   - Figure 38.7 shows the timing chart when the SD card is detected with SD_D3. In addition, SD_D3 is pulled down by the host device, and the resistance value for pulling down is decided by the specification of SD host device.

[Card insertion]

When an SD card is inserted, SD_D3 is pulled up. Accordingly, INFO9 in SD_INFO1 is set to 1. (It is cleared to by writing 0.)

[Card removal]

When an SD card is removed, SD_D3 is pulled down. Accordingly, INFO8 in SD_INFO1 is set to 1. (It is cleared to by writing 0.)

**==> picture [329 x 107] intentionally omitted <==**

**----- Start of picture text -----**<br>
SDDAT3<br>Card  Card<br>Without card With card Without card<br>detect  detect<br>2 IMCLK 2 IMCLK<br>Clear<br>SDDAT3 card insertion (INFO9)<br>Clear<br>SDDAT3 card removal (INFO8)<br>**----- End of picture text -----**<br>

**Figure 38.7 SD Card Detect with SD_D3**

- Power-Down mode at Card removal

   - SD Host Interface module is halted by the MSTP123 bit to MSTP120 bit in Standby Control Register 12 (STBCR12). If these bits of each channel in STBCR12 are set to 10, low power consumption is achieved at Card removal. See section 42, Power-Down Modes .

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|3|MSTP123|1|R/W|SD Host Interface 0 Module Stop|
|2|MSTP122|1||00: SD Host Interface 0 Module runs.<br>01: Setting prohibited|
|||||10: Only card detect block in SD Host Interface 0 Module runs.|
|||||11: Clock supply to SD Host Interface 0 Module is halted.|
|1|MSTP121|1|R/W|SD Host Interface 1 Module Stop|
|0|MSTP120|1||00: SD Host Interface 1 Module runs.<br>01: Setting prohibited|
|||||10: Only card detect block in SD Host Interface 1 Module runs.|
|||||11: Clock supply to SD Host Interface 1 Module is halted.|

## (2) Write Protect

The SD host interface has two types of write protect functions.

- Write protect with SD_WP

   - SD_WP is connected to the card socket, and pulled up or pulled down by the card insertion. The selection of pulling up or pulling down and the resistance value is decided by the specification of SD host device. As the SD_WP state is reflected to INFO7 in SD_INFO1, the write protect is decided after the SD card is inserted.

- Write protect with command

The card's internal write protection and the card lock/unlock operation are realized by the command.

## 38.3.3 Interrupt Request and DMA Transfer Request

## (1) Interrupt Request

The SD host interface has three interrupt requests. Table 38.4 shows the relationship between the interrupt flag registers and the interrupt mask registers. When a bit in an interrupt mask register is set to 0, an interrupt occurs by setting the corresponding bit in the interrupt flag register to 1.

To clear a flag, write 0 to the bit to be cleared and 1 to the other bits.

## **Table 38.4 Interrupt Request**

|**Interrupt Request**|**Interrupt Flag Register**|**Interrupt Mask Register**||
|---|---|---|---|
||**Register Name**|**Bit Name**<br>**Register Name**|**Bit Name**|
|Card access interrupt<br>(SDHI0)|SD_INFO1|INFO2<br>SD_INFO1_MASK<br>INFO0|IMASK2|
||||IMASK0|
||SD_INFO2|ILA<br>SD_INFO2_MASK<br>BWE<br>BRE<br>ERR6<br>ERR5<br>ERR4<br>ERR3<br>ERR2<br>ERR1<br>ERR0|IMASK|
||||BMASK1|
||||BMASK0|
||||EMASK6|
||||EMASK5|
||||EMASK4|
||||EMASK3|
||||EMASK2|
||||EMASK1|
||||EMASK0|
|SDIO access interrupt<br>(SDHI1)|SDIO_INFO1|EXWT<br>SDIO_INFO1_MASK<br>EXPUB52<br>IOIRQ|MEXWT|
||||MEXPUB52|
||||IOMSK|
|Card detect interrupt<br>(SDHI3)|SD_INFO1|INFO9<br>SD_INFO1_MASK<br>INFO8<br>INFO4<br>INFO3|IMASK9|
||||IMASK8|
||||IMASK4|
||||IMASK3|

## (2) DMA Transfer Request

The SD host interface has two types of DMA transfer requests. The DMA transfer requests are described in the following passages.

- SD_BUF write DMA transfer request

   - When the buffer is empty while the DMASDRW bit in CC_EXT_MODE is set to 1, the SD_BUF write DMA transfer request is asserted.

   - The SD_BUF write DMA transfer request is negated when the last data in one block (= the transfer data size set in SD_SIZE) is transferred. The SD_BUF write DMA transfer request is also negated by clearing the SDRST bit in SOFT_RST to 0 or setting the STP bit in SD_STOP to 1. Note that if a communications error or timeout occurs at the DMA transfer, the SD_BUF write DMA transfer request is not negated.

   - The number of DMA transfers should be n x one block. (n = integer, one block = the transfer data size set in SD_SIZE)

   - When the IOABT bit in SDIO_MODE is set to 1, the SD_BUF write DMA transfer request is negated.

   - The DMA transfer request is also negated by clearing the DMASDRW bit to 0. However, note that the DMA transfer request is asserted again when the DMASDRW bit is set to 1 before writing to SD_CMD.

- SD_BUF read DMA transfer request

   - When the buffer is full while the DMASDRW bit in CC_EXT_MODE is set to 1, the SD_BUF read DMA transfer request is asserted.

   - The SD_BUF read DMA transfer request is negated when the last data in one block (= the transfer data size set in SD_SIZE) is transferred. The SD_BUF read DMA transfer request is also negated by clearing the SDRST bit in SOFT_RST to 0 or setting the STP bit in SD_STOP to 1. Note that if a communications error or timeout occurs at the DMA transfer, the SD_BUF read DMA transfer request is not negated.

   - The number of DMA transfers should be n x one block. (n = integer, one block = the transfer data size set in SD_SIZE)

   - When the IOABT bit in SDIO_MODE is set to 1, the SD_BUF read DMA transfer request is negated.

   - The DMA transfer request is also negated by clearing the DMASDRW bit to 0. However, note that the DMA transfer request is asserted again when the DMASDRW bit is set to 1 before writing to SD_CMD.

   - The number of cycles at one DMA transfer will be more than P1   10. If SD_CLK is high frequency and SD_BUF is not empty, SD_CLK is stopped until SD_BUF is empty.

## 38.3.4 Communications Errors and Timeouts

- Communications Errors and Timeouts

   - Table 38.5 and Table 38.6 show the relationships between the SD card interrupt flag register and SD error status register for communications errors and timeouts, respectively. When a bit in the SD card interrupt flag register is set to 1, the corresponding bit in the SD error status register is set to 1. The values of the SD error status register are cleared by writing to SD_CMD or writing 0 to the SDRST bit in SOFT_RST.

## **Table 38.5 Communications Errors**

|**Communication**<br>**Error**|**SD Card Interrupt Flag**<br>**Register**<br>**SD Error Status**<br>**Register**|**SD Card Interrupt Flag**<br>**Register**<br>**SD Error Status**<br>**Register**|<br>**Description**<br>**Bit**<br>**Name**|
|---|---|---|---|
||**Register Name**|**Bit**<br>**Name**<br>**Register Name**||
|END error|SD_INFO2|ERR2<br>SD_ERR_STS1<br>ERR1<br>ERR0|E5<br>When an error occurs in the CRC status length|
||||E4<br>When an error occurs in read data length|
||||E3<br>When an error occurs in the response length to a<br>command issued within a command sequence|
||||E2<br>When an error occurs in the response length (other than a<br>response to a command issued within a command<br>sequence)|
|CRC error|||E11<br>When an error occurs in the CRC status|
||||E10<br>When a CRC error occurs in the read data|
||||E9<br>When a CRC error occurs in the response to a command<br>issued within a command sequence|
||||E8<br>When a CRC error occurs in the response (other than a<br>response to a command issued within a command<br>sequence)|
|CMD error|||E1<br>The command index of the transmitted command differed<br>from the command index of the received response (for a<br>command issued within a command sequence).|
||||E0<br>The command index of the transmitted command differed<br>from the command index of the received response (for a<br>command issued other than within a command sequence)|

**Table 38.6 Timeouts**

|**Timeout**|**SD Card Interrupt Flag**<br>**Register**<br>**SD Error Status**<br>**Register**|**SD Card Interrupt Flag**<br>**Register**<br>**SD Error Status**<br>**Register**||**Description**|
|---|---|---|---|---|
||**Register Name**|**Bit**<br>**Name**<br>**Register Name**|**Bit**<br>**Name**||
|Response<br>timeout|SD_INFO2|ERR6<br>SD_ERR_STS2<br>ERR3|E1|When the response to a command issued within a<br>command sequence is not received though a longer time<br>than 640 cycles of SD_CLK has elapsed|
||||E0|When the response (other than a response to a command<br>issued within a command sequence) is not received<br>though a longer time than 640 cycles of SD_CLK has<br>elapsed|
|Data timeout<br>(other than<br>response<br>timeout)|||E6|When the busy state (SD_D0 = 0) continues for longer<br>than Ncycle after the CRC status|
||||E5|When the CRC status is not received though a longer time<br>than Ncycle has elapsed after data writing|
||||E4|When read data is not received though a longer time than<br>Ncycle has elapsed after read command|
|||||When read data for the next block are not received though<br>a longer time than Ncycle has elapsed after the reception<br>of read data|
|||||When read data for the next block are not received though<br>a longer time than Ncycle has elapsed after release of the<br>read wait state|
||||E3|When the busy state (SD_D0 = 0) for longer than Ncycle<br>continues after CMD12 has been issued within a<br>command sequence.|
||||E2|When the busy state (SD_D0 = 0) for longer than Ncycle<br>continues after R1b response|

## 38.4 Usage Example

## 38.4.1 Command without Data Transfer

## (1) Flowchart

Figure 38.8 and Figure 38.9 show flowchart examples.

**==> picture [215 x 181] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock) Set control register<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SD_ARG0, Argument0)<br>W (SD_ARG1, Argument1)<br>W (SD_CMD, Command) Issue command without<br>response and data<br>Response end<br>W (SD_INFO1, 0xFFFE) Flag clear<br>[Legend]<br>W (register name, value): Write to register<br>R (register name): Read from register<br>**----- End of picture text -----**<br>

**Figure 38.8 Flow Example of Command Without Response and Data**

**==> picture [377 x 207] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock) Set control register<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SD_ARG0, Argument0)<br>W (SD_ARG1, Argument1)<br>W (SD_CMD, Command) Issue command without data<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>  Error processing (clear the interrupt flag register)<br>R (SD_RSP00)  Response check<br>R (SD_RSP01)<br>[Legend]<br>W (register name, value): Write to register<br>R (register name): Read from register<br>**----- End of picture text -----**<br>

**Figure 38.9 Flow Example of Command Without Data**

- (2) Operation for Command without Data Transfer: The operation of the command without data transfer is described in the following.

- Command without response and data

   - Flag register clear

First, clear the bits in the flag register. (SD_INFO1 and SD_INFO2)

- Control register set

Set the SD clock (SD_CLK), interrupt mask, and so on. (SD_CLK_CTRL, SD_INFO1_MASK, and SD_INFO2_MASK)

- Command issue

Set CMD Argument in SD_ARG0 and SD_ARG1 and write to SD_CMD.

Accordingly, CMD is issued, and the operation is started.

- Flag clear

When transmission of a command is completed, INFO0 (response end) in SD_INFO1 is set to 1 to generate an interrupt. Clear INFO0 to 0.

- Command without data

   - Flag register clear

First, clear the bits in the flag register. (SD_INFO1 and SD_INFO2)

- Control register set

Set the SD clock (SD_CLK), interrupt mask, and so on. (SD_CLK_CTRL, SD_INFO1_MASK, and SD_INFO2_MASK)

- Command issue

Set CMD Argument in SD_ARG0 and SD_ARG1 and write to the SD_CMD.

Accordingly, CMD is issued, and the operation is started.

- Flag clear

When a response is received, INFO0 (response end) in SD_INFO1 is set to 1 to generate an interrupt. Clear INFO0 to 0.

- Read a response from SD_RSP00 and SD_RSP01.

Furthermore, perform error processing (clear the interrupt flag register) if an error occurs (a communications error or timeout).

## 38.4.2 Single Block Read

## (1) Flowchart

**==> picture [397 x 441] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock) Set control register<br>W (SD_SIZE, Transfer data size)<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SD_ARG0, Argument0) Issue CMD17<br>W (SD_ARG1, Argument1)<br>(single-block read)<br>W (SD_CMD, 0x0011)<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>R (SD_RSP00) Response check<br>R (SD_RSP01)<br>W (SD_INFO1_MASK, 0xFFFB) Enable the access end interrupt<br>W (SD_INFO2_MASK, 0x7E80) Enable the BRE interrupt<br>Error (communications error or timeout)<br>BRE or error<br>W (SD_INFO2, 0xFEFF) Flag clear<br>R (SD_BUF0)<br>(amount of data specified by SD_SIZE)  Read data<br>Access end<br>Error processing (clear the interrupt flag register) W (SD_INFO1, 0xFFFB) Flag clear<br>[Legend]<br>W (register name, value): Write to register<br>R (register name):   Read from register<br>**----- End of picture text -----**<br>

**Figure 38.10 Single Block Read Flowchart Example**

- (2) Operation for Single Block Read: The operation of the single block read is described in the following.

   - Flag register clear

First, clear the bits in the flag register. (SD_INFO1 and SD_INFO2)

- Control register set

Set the SD clock (SD_CLK), transfer data size, interrupt mask, and so on. (SD_CLK_CTRL, SD_SIZE, SD_INFO1_MASK, and SD_INFO2_MASK)

- Command issue (CMD17)

Set CMD17 Argument in SD_ARG0 and SD_ARG1 and write 0x0011 to SD_CMD.

Accordingly, CMD17 is issued, and the single block read operation is started.

- Response check

On receiving the response, INFO0 (response end) in SD_INFO1 is set to 1 to generate an interrupt. Clear INFO0 to 0 and read the response from SD_RSP00 and SD_RSP01.

If the result of response decoding is an error, the command sequence can be halted by setting the STP bit in SD_STP or the IOABT bit in SDIO_MODE to 1. Furthermore, this causes CMD12 and CMD52 to not be issued. If the INFO2 bit (access end) in SD_INFO has been set, halting the command sequence will also lead to the generation of an interrupt.

- Data receive from SD card and data read

Write 0xFFFB to SD_INFO1_MASK to enable the access end interrupt. In addition, write 0x7E80 to

SD_INFO2_MASK to enable the BRE interrupt. When the data receive from the SD card is completed, the BRE bit in SD_INFO2 is set to 1 to generate an interrupt. Clear the BRE bit to 0 and read the amount of data specified by SD_SIZE from SD_BUF0.

However, a communications error or timeout may be generated if data are being received while reading of SD_BUF0 is in progress.

##  Operation complete

When the data read from SD_BUF0 is completed, INFO2 (access end) in SD_INFO1 is set to 1 to generate an interrupt. Clear INFO2 to 0 to end the single block read operation.

Furthermore, perform error processing (clear the interrupt flag register) if an error occurs (a communications error or timeout).

## 38.4.3 Single Block Write

## (1) Flowchart

**==> picture [397 x 448] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock) Set control register<br>W (SD_SIZE, Transfer data size)<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SD_ARG0, Argument0) Issue CMD24<br>W (SD_ARG1, Argument1)<br>(single-block write)<br>W (SD_CMD, 0x0018)<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>R (SD_RSP00) Response check<br>R (SD_RSP01)<br>W (SD_INFO1_MASK, 0xFFFB) Enable the access end interrupt<br>W (SD_INFO2_MASK, 0x7D80) Enable the BWE interrupt<br>      BWE<br>W (SD_INFO2, 0xFDFF) Flag clear<br>W (SD_BUF0, data)<br>(amount of data specified by SD_SIZE)  Write data<br>Error (communications error or timeout)<br>Access end or error<br>Error processing (clear the interrupt flag register) W (SD_INFO1, 0xFFFB) Flag clear<br>[Legend]<br>W (register name, value): Write to register<br>R (register name):   Read from register<br>**----- End of picture text -----**<br>

**Figure 38.11 Single Block Write Flowchart Example**

- (2) Operation for Single Block Write: The operation of the single block write is described in the following.

   - Flag register clear

First, clear the bits in the flag register. (SD_INFO1 and SD_INFO2)

- Control register set

Set the SD clock (SD_CLK), transfer data size, interrupt mask, and so on. (SD_CLK_CTRL, SD_SIZE, SD_INFO1_MASK, and SD_INFO2_MASK)

- Command issue (CMD24)

Set CMD24 Argument in SD_ARG0 and SD_ARG1 and write 0x0018 to SD_CMD.

Accordingly, CMD24 is issued, and the single block write operation is started.

- Response check

On receiving the response, INFO0 (response end) in SD_INFO1 is set to 1 to generate an interrupt. Clear INFO0 to 0 and read the response from SD_RSP00 and SD_RSP01.

If the result of response decoding is an error, the command sequence can be halted by setting the STP bit in SD_STP or the IOABT bit in SDIO_MODE to 1. Furthermore, this causes CMD12 and CMD52 to not be issued. If the INFO2 bit (access end) in SD_INFO has been set, halting the command sequence will also lead to the generation of an interrupt.

- Data write and data transmit to SD card

Write 0xFFFB to SD_INFO1_MASK to enable the access end interrupt. In addition, write 0x7D80 to

SD_INFO2_MASK to enable the BWE interrupt. When SD_BUF0 is ready for the data to be written, the BWE bit in SD_INFO2 is set to 1 to generate an interrupt. Clear the BWE bit to 0 and write the amount of data specified by SD_SIZE to SD_BUF0. When the data write to SD_BUF0 is completed, data is transmitted to the SD card. Then, the CRC status and busy state are received from the SD card.

However, a communications error or timeout may be generated if data are being transmitted after writing to SD_BUF0.

##  Operation complete

When the CRC status and busy state are received from the SD card, INFO2 (access end) in SD_INFO1 is set to 1

to generate an interrupt. Clear the INFO2 bit to 0 to end the single block write operation.

Furthermore, perform error processing (clear the interrupt flag register) if an error occurs (a communications error or timeout).

## 38.4.4 Multiple Block Read

## (1) Flowchart

**==> picture [341 x 418] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock) Set control register<br>W (SD_SIZE, 0x0200)<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SD_STOP, 0x0100)<br>W (SD_SECCNT ,<br>       number of transfer blocks)<br>W (SD_ARG0, Argument0) Issue CMD18<br>W (SD_ARG1, Argument1) (multiple-block read)<br>W (SD_CMD, 0x0012)<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>R (SD_RSP00) Response check<br>R (SD_RSP01)<br>W (SD_INFO1_MASK, 0xFFFB) Enable the access end interrupt<br>W (SD_INFO2_MASK, 0x7E80) Enable the BRE interrupt<br>Error (communications error or timeout)<br>BRE or error<br>W (SD_INFO2, 0xFEFF) Flag clear<br>R (SD_BUF0)<br>(amount of data specified by SD_SIZE) Read data<br>No All block read<br>Number of blocks set in SD_SECCNT<br>completed?<br>Yes<br>Access end<br>W (SD_INFO1, 0xFFFB) Flag clear<br>Error processing (clear the interrupt flag register) R (SD_RSP00) Response check<br>R (SD_RSP01)<br>[Legend]<br>W (register name, value): Write to register<br>R (register name):  Read from register<br>**----- End of picture text -----**<br>

**Figure 38.12 Multiple Block Read Flowchart Example**

- (2) Operation for Multiple Block Read: The operation of the multiple block read is described in the following.

   - Flag register clear

First, clear the bits in the flag register. (SD_INFO1 and SD_INFO2)

- Control register set

Set the SD clock (SD_CLK), transfer data size, interrupt mask, and so on. (SD_CLK_CTRL, SD_SIZE, SD_INFO1_MASK, and SD_INFO2_MASK)

Set SEC in SD_STOP to 1, and set the number of transfer blocks in SD_SECCNT.

- Command issue (CMD18)

Set CMD18 Argument in SD_ARG0 and SD_ARG1 and write 0x0012 to SD_CMD.

Accordingly, CMD18 is issued, and the multiple block read operation is started.

- Response check

On receiving the response, INFO0 (response end) in SD_INFO1 is set to 1 to generate an interrupt. Clear INFO0 to 0 and read the response from SD_RSP00 and SD_RSP01.

If the result of response decoding is an error, the command sequence can be halted by setting the STP bit in SD_STP to 1. Setting the STP bit to 1 also causes CMD12 to be issued and the response received. When this happens, the arguments for the CMD12 command are set in SD_ARG0 and SD_ARG1. If the command sequence is halted because the access end interrupt has been enabled, an interrupt will be generated by setting of the INFO2 bit (access end) bit in SD_INFO1 to 1 when reception of the response has been completed. Clear the INFO2 bit to 0 and read the response.

- Data receive from SD card and data read

Write 0xFFFB to SD_INFO1_MASK to enable the access end interrupt. In addition, write 0x7E80 to SD_INFO2_MASK to enable the BRE interrupt. When one-block data receive from the SD card is completed, the BRE bit in SD_INFO2 is set to 1 to generate an interrupt. Clear the BRE bit to 0 and read the amount of data specified by SD_SIZE from SD_BUF0. Doing this repeats transfer of the number of blocks set in SD_SECCNT. However, a communications error or timeout may be generated if data are being received while reading of SD_BUF0 is in progress. When reception of the last block of data is completed, CMD12 is automatically issued and the response is received.

At this point, the arguments of CMD12 are reflected as the arguments of CMD18.

- Operation complete

When all-block data read and the CMD12 response receive are completed, INFO2 (access end) in SD_INFO1 is set to 1 to generate an interrupt. Clear INFO2 to 0 to read the response. This is the end of multiple block read operation.

Furthermore, perform error processing (clear the interrupt flag register) if an error occurs (a communications error or timeout).

## 38.4.5 Multiple Block Write

## (1) Flowchart

**==> picture [343 x 416] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock) Set control register<br>W (SD_SIZE, 0x0200)<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SD_STOP, 0x0100)<br>W (SD_SECCNT ,<br>       number of transfer blocks)<br>W (SD_ARG0, Argument0) Issue CMD25<br>W (SD_ARG1, Argument1) (multiple-block write)<br>W (SD_CMD, 0x0019)<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>R (SD_RSP00) Response check<br>R (SD_RSP01)<br>W (SD_INFO1_MASK, 0xFFFB) Enable the access end interrupt<br>W (SD_INFO2_MASK, 0x7D80) Enable the BWE interrupt<br>Error (communications error or timeout)<br>BWE or error<br>W (SD_INFO2, 0xFDFF) Flag clear<br>W (SD_BUF0, data)<br>(amount of data specified by SD_SIZE) Write data<br>No All block read Number of blocks set in SD_SECCNT<br>completed?<br>Yes<br>Error (communications error or timeout)<br>Access end or error<br>W (SD_INFO1, 0xFFFB) Flag clear<br>Error processing (clear the interrupt flag register) R (SD_RSP00)R (SD_RSP01) Response check<br>[Legend]<br>W (register name, value): Write to register<br>R (register name):  Read from register<br>**----- End of picture text -----**<br>

**Figure 38.13 Multiple Block Write Flowchart Example**

- (2) Operation for Multiple Block Write: The operation of the multiple block write is described in the following.

   - Flag register clear

First, clear the bits in the flag register. (SD_INFO1 and SD_INFO2)

- Control register set

Set the SD clock (SD_CLK), transfer data size, interrupt mask, and so on. (SD_CLK_CTRL, SD_SIZE, SD_INFO1_MASK, and SD_INFO2_MASK)

Set the SEC bit in SD_STOP to 1, and set the number of transfer blocks in SD_SECCNT.

- Command issue (CMD25)

Set CMD25 Argument in SD_ARG0 and SD_ARG1 and write 0x0019 to SD_CMD.

Accordingly, CMD25 is issued, and the multiple block write operation is started.

- Response check

On receiving the response, the INFO0 bit (response end) in SD_INFO1 is set to 1 to generate an interrupt. Clear the INFO0 bit to 0 and read the response from SD_RSP00 and SD_RSP01.

If the result of response decoding is an error, the command sequence can be halted by setting the STP bit in SD_STP to 1. Setting the STP bit to 1 also causes CMD12 to be issued and the response received. When this happens, the arguments for the CMD12 command are set in SD_ARG0 and SD_ARG1. If the command sequence is halted because the access end interrupt has been enabled, an interrupt will be generated by setting of the INFO2 bit (access end) bit in SD_INFO1 to 1 when reception of the response has been completed. Clear the INFO2 bit to 0 and read the response.

- Data write and data transmit to SD card

Write 0xFFFB to SD_INFO1_MASK to enable the access end interrupt. In addition, write 0x7D80 to SD_INFO2_MASK to enable the BWE interrupt. When SD_BUF0 is ready for the data to be written, the BWE bit in the SD_INFO2 resister is set to 1 to generate an interrupt. Clear the BWE bit to 0 and write the amount of data specified by SD_SIZE to SD_BUF0. When the data write to SD_BUF0 is completed, data is transmitted to the SD card. Then, the CRC status and busy state are received from the SD card. Doing this repeats transfer of the number of blocks set in SD_SECCNT. However, a communications error or timeout may be generated if data are being received while writing to SD_BUF0 is in progress. When reception of the last block of data is completed, CMD12 is automatically issued and the response is received.

At this point, the arguments of CMD12 are reflected as the arguments of CMD25.

- Operation complete

When all-block data transmit and the CRC status receive are completed, the INFO2 bit (access end) in SD_INFO1 is set to 1 to generate an interrupt. Clear the INFO2 bit to 0 to read the response. This is the end of multiple block write operation.

Furthermore, perform error processing (clear the interrupt flag register) if an error occurs (a communications error or timeout).

## 38.4.6 IO_RW_DIRECT Command (CMD52)

## (1) Flowchart

**==> picture [363 x 190] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock)<br>Set control register<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SDIO_MODE, 0x0001)<br>W (SDIO_INFO1_MASK, 0xFFFE)<br>Issue CMD52<br>W (SD_ARG0, Argument0)<br>(IO_RW_DIRECT command)<br>W (SD_ARG1, Argument1)<br>W (SD_CMD, 0x0434)<br>Error (communications error or timeout)<br>Response end or error<br>Flag clear<br>W (SD_INFO1, 0xFFFE)<br>R (SD_RSP00) Response check<br>Error processing (clear the interrupt flag register) R (SD_RSP01)<br>[Legend]<br>W (register name, value): Write to register<br>R (register name): Read from register<br>**----- End of picture text -----**<br>

**Figure 38.14 IO_RW_DIRECT Command (CMD52) Flowchart Example**

## 38.4.7 IO_RW_EXTENDED Command (CMD53/Multiple Block Read)

## (1) Flowchart

Figure 38.15 shows a flowchart example for CMD53 (multiple block read).

**==> picture [348 x 438] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock)<br>W (SD_SIZE, 0x0200)<br>W (SD_INFO1_MASK, 0xFFFE) Set control register<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SD_STOP, 0x0100)<br>W (SD_SECCNT ,<br>      number of transfer blocks)<br>W (SDIO_MODE, 0x0001)<br>W (SDIO_INFO1_MASK, 0x3FFE)<br>W (SD_ARG0, Argument0) Issue CMD53<br>W (SD_ARG1, Argument1) (multiple-block read)<br>W (SD_CMD, 0x7C35)<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>R (SD_RSP00) Response check<br>R (SD_RSP01)<br>W (SD_INFO1_MASK, 0xFFFB) Enable the access end interrupt<br>W (SD_INFO2_MASK, 0x7E80) Enable the BRE interrupt<br>A From C52PUB<br>Error (communications error or timeout)<br>BRE or error<br>W (SD_INFO2, 0xFEFF) Flag clear<br>R (SD_BUF0, data)<br>(amount of data specified by SD_SIZE) Read data<br>No All block read Number of blocks set in SD_SECCNT<br>completed?<br>Yes<br>B From IOABT<br>Error (communications error or timeout)<br>Access end or error<br>Error processing (clear the interrupt flag register) W (SD_INFO1, 0xFFFB) CMD53 completedFlag clear<br>[Legend]<br>W (register name, value): Write to register<br>R (register name):  Read from register<br>**----- End of picture text -----**<br>

**Figure 38.15 CMD53 (Multiple Block Read) Flowchart Example**

Figure 38.16 shows a flowchart example when CMD52 (SDIO abort) is issued at CMD53 (multiple block read).

**==> picture [219 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
IOABT start<br>W (SD_INFO2_MASK, 0xFFFB)<br>W (SD_ARG0, Argument0)<br>W (SD_ARG1, Argument1)<br>W (SDIO_MODE, 0x0101)<br>[Legend]<br>B W (register name, value): Write to register<br>**----- End of picture text -----**<br>

**Figure 38.16 Flowchart Example when CMD52 (SDIO Abort) is Issued at CMD53 (Multiple Block Read)**

Figure 38.17 shows a flowchart example when CMD52 (SDIO none abort) is issued at CMD53 (multiple block read) while the SD host interface is in the read wait state.

**==> picture [360 x 288] intentionally omitted <==**

**----- Start of picture text -----**<br>
RWREQ and C52PUB start<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 07F80)<br>W (SD_ARG0, Argument0)<br>W (SD_ARG1, Argument1)<br>W (SDIO_MODE, 0x0205)<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>R (SD_RSP00) Response check<br>Error processing (clear the interrupt  Response end R (SD_RSP01)<br>flag register) Error flags<br>Release of the read wait state RWREQ clear<br>Issue CMD52?<br>Yes<br>Access end and error No<br>W (SDIO_MODE, 0x0001)<br>Access end  W (SD_INFO1_MASK, 0xFFFB)<br>(Clear the interrupt flag register) Error flags W (SD_INFO2_MASK, 0x7E80)<br>[Legend]<br>A<br>W (register name, value): Write to register<br>R (register name) : Read from register<br>**----- End of picture text -----**<br>

**Figure 38.17 Flowchart Example when CMD52 (SDIO None Abort) is Issued at CMD53 (Multiple Block Read) while the SD Host Interface is in the Read Wait State**

## 38.4.8 IO_RW_EXTENDED Command (CMD53/Multiple Block Write)

## (1) Flowchart

Figure 38.18 shows a flowchart example for CMD53 (multiple block write).

**==> picture [348 x 438] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>W (SD_CLK_CTRL, SD clock)<br>W (SD_SIZE, 0x0200)<br>W (SD_INFO1_MASK, 0xFFFE) Set control register<br>W (SD_INFO2_MASK, 0x7F80)<br>W (SD_STOP, 0x0100)<br>W (SD_SECCNT ,<br>      number of transfer blocks)<br>W (SDIO_MODE, 0x0001)<br>W (SDIO_INFO1_MASK, 0xBFFE)<br>W (SD_ARG0, Argument0) Issue CMD53<br>W (SD_ARG1, Argument1) (multiple-block write)<br>W (SD_CMD, 0x6C35)<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>R (SD_RSP00) Response check<br>R (SD_RSP01)<br>W (SD_INFO1_MASK, 0xFFFB) Enable the access end interrupt<br>W (SD_INFO2_MASK, 0x7D80) Enable the BWE interrupt<br>A From C52PUB<br>Error (communications error or timeout)<br>BWE or error<br>W (SD_INFO2, 0xFDFF) Flag clear<br>W (SD_BUF0, data)<br>(amount of data specified by SD_SIZE) Write data<br>No All block read Number of blocks set in SD_SECCNT<br>completed?<br>Yes<br>B From IOABT<br>Error (communications error or timeout)<br>Access end or error<br>Error processing (clear the interrupt flag register) W (SD_INFO1, 0xFFFB) CMD53 completedFlag clear<br>[Legend]<br>W (register name, value): Write to register<br>R (register name):  Read from register<br>**----- End of picture text -----**<br>

**Figure 38.18 CMD53 (Multiple Block Write) Flowchart Example**

Figure 38.19 shows a flowchart example when CMD52 (SDIO abort) is issued at CMD53 (multiple block write).

**==> picture [220 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
IOABT start<br>W (SD_INFO2_MASK, 0xFFFB)<br>W (SD_ARG0, Argument0)<br>W (SD_ARG1, Argument1)<br>W (SDIO_MODE, 0x0101)<br>[Legend]<br>B W (register name, value): Write to register<br>**----- End of picture text -----**<br>

**Figure 38.19 Flowchart Example when CMD52 (SDIO Abort) is Issued at CMD53 (Multiple Block Write)**

Figure 38.20 shows a flowchart example when CMD52 (SDIO none abort) is issued at CMD53 (multiple block write).

**==> picture [360 x 288] intentionally omitted <==**

**----- Start of picture text -----**<br>
C52PUB start<br>W (SD_INFO1_MASK, 0xFFFE)<br>W (SD_INFO2_MASK, 07F80)<br>W (SD_ARG0, Argument0)<br>W (SD_ARG1, Argument1)<br>W (SDIO_MODE, 0x0201)<br>Error (communications error or timeout)<br>Response end or error<br>W (SD_INFO1, 0xFFFE) Flag clear<br>R (SD_RSP00) Response check<br>Error processing (clear the interrupt  Response end R (SD_RSP01)<br>flag register) Error flags<br>IOABT set SDIO abort<br>Issue CMD52?<br>Yes<br>Access end and error No<br>W (SDIO_MODE, 0x0001)<br>Access end  W (SD_INFO1_MASK, 0xFFFB)<br>(Clear the interrupt flag register) Error flags W (SD_INFO2_MASK, 0x7D80)<br>[Legend]<br>A<br>W (register name, value): Write to register<br>R (register name) : Read from register<br>**----- End of picture text -----**<br>

**Figure 38.20 Flowchart Example when CMD52 (SDIO None Abort) is Issued at CMD53 (Multiple Block Write)**

## 38.4.9 DMA Transfer

## (1) SD_BUF DMA Transfer

Figure 38.21 shows a flowchart example for SD_BUF DMA read when CMD18 (multiple block read) is issued.

**==> picture [396 x 351] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>Set control register<br>W (CC_EXT_MODE, 0x0002) SD_BUF DMA transfer enabled<br>             Issue CMD18<br>(multiple-block read command)<br>Error (communications error or timeout)<br>Response end or error<br>     Flag clear<br>Response check<br>Set DMA controller<br>Error (communications error or timeout)<br>     Access end or error<br>     Flag clear<br>Response check<br>W (CC_EXT_MODE, 0x0000) SD_BUF DMA transfer disabled<br>Error processing (clear the interrupt flag register)<br>(SD_BUF DMA transfer disabled) Set DMA controller<br>[Legend]<br>W (register name, value): Write to register<br>**----- End of picture text -----**<br>

**Figure 38.21 SD_BUF DMA Read Flowchart Example**

Figure 38.22 shows a flowchart example for SD_BUF DMA write when CMD25 (multiple block write) is issued.

**==> picture [396 x 351] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clear flag register<br>Set control register<br>W (CC_EXT_MODE, 0x0002) SD_BUF DMA transfer enabled<br>             Issue CMD25<br>(multiple-block write command)<br>Error (communications error or timeout)<br>Response end or error<br>     Flag clear<br>Response check<br>Set DMA controller<br>Error (communications error or timeout)<br>     Access end or error<br>     Flag clear<br>Response check<br>W (CC_EXT_MODE, 0x0000) SD_BUF DMA transfer disabled<br>Error processing (clear the interrupt flag register)<br>(SD_BUF DMA transfer disabled) Set DMA controller<br>[Legend]<br>W (register name, value): Write to register<br>**----- End of picture text -----**<br>

## **Figure 38.22 SD_BUF DMA Write Flowchart Example**

## 38.4.10 Example of SD_CMD Register Setting

Table 38.7 lists the example of SD_CMD register setting.

## **Table 38.7 Example of SD_CMD Register Setting**

|**Type**|**Command**|**Example of SD_CMD**<br>**Register Setting**<br>**Remark**|
|---|---|---|
|CMD|CMD0|0x0000|
||CMD2|0x0002|
||CMD3|0x0003|
||CMD4|0x0004|
||CMD5|0x0705|
||CMD6|0x1C06|
||CMD7|0x0007<br>When the card is placed in the deselected state, the response<br>timeout flag will be set since there is no response.|
||CMD8|0x0408|
||CMD9|0x0009|
||CMD10|0x000A|
||CMD12|0x000C|
||CMD13|0x000D|
||CMD15|0x000F|
||CMD16|0x0010|
||CMD17|0x0011|
||CMD18|0x0012|
||CMD24|0x0018|
||CMD25|0x0019|
||CMD27|0x001B|
||CMD28|0x001C|
||CMD29|0x001D|
||CMD30|0x001E|
||CMD32|0x0020|
||CMD33|0x0021|
||CMD38|0x0026|
||CMD42|0x002A|
||CMD52|0x0434|
||CMD53|0x1C35<br>Single read|
|||0x0C35<br>Single write|
|||0x7C35<br>Multiple read|
|||0x6C35<br>Multiple write|
||CMD55|0x0037|
||CMD56|0x0038|
|ACMD|ACMD6|0x0046|
||ACMD13|0x004D|
||ACMD22|0x0056|
||ACMD23|0x0057|
||ACMD41|0x0069|
||ACMD42|0x006A|
||ACMD51|0x0073|

## 38.5 Usage Note

## (1) SD_BUF Illegal Write Access

When writing data to SD_BUF0 after the single block write or multi block write command is issued, the data of the size specified by SD_SIZE must be written to.

If the data of the size which exceeds the size specified by SD_SIZE is written to, the ERR4 bit in SD_INFO2 is set to 1. In addition, the data written to SD_BUF0 may not be transmitted and it causes the SCLKDIVEN bit in SD_INFO2 to hold the value of 0. In such cases, clearing the SDRST bit in SOFT_RST to 0 and then restoring its value to 1 clears the SCLKDIVEN bit to 1.

However, for the single byte or three bytes when the number of bytes setting in SD_SIZE is odd, or the fraction of bytes when the number of bytes setting in SD_SIZE is even, since the portion of dummy data writing is regarded as excess data and ignored, it is not within the scope of the above description (the fraction of bytes: the two bytes that are not in a fourbyte unit).

## (2) Block Number Limitation for Multiple Block Read

When performing a multiple block read of one or two blocks, depending on the timing with which the response register is read, the response value may not be read properly. When receiving one or two blocks of data, use single block read operation.

Figure 38.23 shows the processing flows of SD host interface (hardware) operation and software operation when a multiple block read is performed on two blocks. As shown in the incorrect operation of Figure 38.23 , when an interrupt is generated on reception of the CMD18 response and the timing with which the response register is read by the interrupt is delayed, the data during the CMD12 response reception or the CMD12 response may be read. In the case of a multiple block read of three or more blocks, CMD12 is not issued until the block of data has been read, so this problem does not arise. Furthermore, in the case of a multiple block write, since the CMD25 response is read before the block of data is sent, the problem does not arise.

**==> picture [397 x 169] intentionally omitted <==**

**----- Start of picture text -----**<br>
< SD host interface < SD host interface<br> (hardware) operation > < Software operation >  (hardware) operation > < Software operation ><br>Transmit CMD18 CMD18 transmission process Transmit CMD18 CMD18 transmission process<br>Receive CMD18 response Interrupt Read response register  Receive CMD18 response Interrupt<br>(CMD18)<br>Interrupt<br>Receive block data Read block data (1) Receive block data<br>Receive block data  Interrupt Receive block data<br>+  Read block data (2) +<br>Transmit CMD12  Transmit CMD12<br>Interrupt<br>Receive CMD12 response Read response register  Receive CMD12 response Read response register (?)<br>(CMD12)<br>Normal Operation Incorrect Operation<br>**----- End of picture text -----**<br>

**Figure 38.23 Flowcharts for Multiple Block Read Operation (Two Blocks)**

## (3) Automatic Control of SD_CLK Output

In the SD Card standard, 74 cycles of SD_CLK must be output before initialization of the card. For this reason, use automatic control of SD_CLK output after 74 cycles of SD_CLK have been output. Furthermore, if automatic control of SD_CLK output was in use, SD_CLK output is stopped on completion of the sequence for a communications error or timeout. Thus, in cases where state transitions within the SD card are necessary and so on after completion of the sequence, release automatic control of SD_CLK output and restart supply of SD_CLK to the SD card.

## (4) Control of the C52PUB Setting for Multiple Block Write

If the C52PUB bit in SDIO_MODE is set to 1 during a sequence of multiple block write due to CMD53, CMD52 is not issued until SD_BUF becomes empty. For this reason, set the C52PUB bit after suspending writing to SD_BUF by following the appropriate procedure below.

- When DMA transfer is not in use

1. Before setting the C52PUB bit, suspend writing to SD_BUF by making the setting in SD_INFO2 to disable BWE interrupts.

2. Set the C52PUB bit in SDIO_MODE to 1 (so that CMD52 is issued when SD_BUF becomes empty).

3. After the INFO0 interrupt processing in SD_INFO1 due to the issuing of CMD52 has been completed, restart writing to SD_BUF by making the setting in SD_INFO2 to enable BWE interrupts.

- When DMA transfer is in use

1. Every time DMA transfer of the value set in SD_SIZE  n blocks (where n = 1, 2, ...) proceeds, suspend writing to SD_BUF by DMA transfer before the C52PUB bit is set.

2. Set the C52PUB bit in SDIO_MODE to 1 (so that CMD52 is issued when SD_BUF becomes empty).

3. After the INFO0 interrupt processing in SD_INFO1 due to the issuing of CMD52 has been completed, restart writing to SD_BUF by DMA transfer.

## (5) Erroneous Detection of SDIO interrupts

- The SD host interface erroneously detects an SDIO interrupt when all of the following conditions are satisfied.

1. SDIO access

2. The SDIO device supports the SDIO interrupt (an optional part of the standard).

3. The SDIO device supports 4-bit width multi-block read of CMD53 (an optional part of the standard).

4. The SDIO device does not support the SDIO interrupt between 4-bit width data blocks (an optional part of the standard).

Avoid this problem by following the procedure below when the values of the SMB and S4MI bits in the card capability register of the SDIO device are 1 and 0, respectively.

1. Immediately before executing the multiple block read command, clear (to 0) the IOMOD bit of the SDIO_MODE register.

2. Execute the command.

3. Set (to 1) the IOMOD bit of the SDIO_MODE register immediately after multiple block read operation is completed.

## (6) Setting STP bit during multiple read

During multiple block read with auto CMD12 setting 1 to SEC bit of SD_STOP, if performing a force-quit by setting 1 to STP bit of SD_STOP, the command sequence is not terminated depending on the timing of setting 1 to STP bit of SD_STOP.

To avoid this, if setting STP bit of SD_STOP during multiple block transfer, setting 0 to SEC bit of SD_STOP at the same time.

Switching the value of SEC bit of SD_STOP from 1 to 0, even if CBSY bit of SD_INFO2 is 1.

In case the command sequence is not terminated because of not setting 0 to SEC bit of SD_STOP at the same time, setting SDRST bit of SOFT_RST is also available to terminate the command sequence.

If performing a force-quit by setting 1 to IOABT bit of SDIO_MODE during CMD53 multiple block transfer, leave the value (=1) of SEC bit of SD_STOP as it is.

## (7) Software Reset

For transitions to the software reset state by the SDRST bit in the SOFT_RST register, see section 42.3.6, Software Reset . However, where the procedure refers to the SRST bit, read this as the SDRST bit in the SOFT_RST register.
