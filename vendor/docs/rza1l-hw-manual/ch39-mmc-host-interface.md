# 39. MMC Host Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2145–2186. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

The MMC host interface is a host controller conforming to the JEDEC Standard JESD84-A441 that allows connection with devices with the MMC interface.

## 39.1 Features

- Supports 1/4/8-bit MMC bus

- Supports the Single Data Rate only

- MMC clock frequency = P1  frequency/2[n] (n = 1 to 10)

- Supports High Priority Interrupt (HPI)*

- Supports background operation

- Data buffer: 512 bytes  2

- Three types of interrupt requests: normal operation, error/timeout, card detection

- DMA transfer requests: buffer write and buffer read

- Card detection function

Note: * Supports HPI in the sequences of CMD6, CMD24, CMD25 (pre-defined), and CMD38.

Figure 39.1 shows a block diagram of this module.

**==> picture [376 x 180] intentionally omitted <==**

**----- Start of picture text -----**<br>
MMC host interface<br>Module clock<br>Card socket<br>Host I/F Registers Sequence Card I/F<br>Peripheral bus 1 generation MMC_CLK<br>MMC_CMD<br>DMA<br>(buffer write/read) DMA MMC_D[7:0]<br>Direct memory control<br>access  MMC_CD<br>controller Interrupt Buffer I/F<br>(normal operation,<br>error/timeout, Interrupt  Card detection<br>Interruptcontroller card detection) control ..<br>.<br>Buffer A Buffer B<br>512 bytes 512 bytes<br>**----- End of picture text -----**<br>

**Figure 39.1 Block Diagram of MMC Host Interface**

## 39.2 Input/Output Pins

Table 39.1 shows the pin configuration of this module.

## **Table 39.1 Pin Configuration**

|**Pin Name**|**I/O**|**Function**|
|---|---|---|
|MMC_CLK|Output|MMC clock|
|MMC_CMD|Input/output|Command/response|
|MMC_D[7:0]|Input/output|Transmit/receive data|
|MMC_CD|Input|Card detection*1|

Note 1. Check the specifications of the card socket to be used before connection.

## 39.3 Register Descriptions

Table 39.2 shows the register configuration of this module.

## **Table 39.2 Register Configuration**

|**Table 39.2**<br>**Register Configuration**|||||
|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Address**|**Access Size**|
|Command setting register|CE_CMD_SET|R/W|H'E804C800|16|
||||H'E804C802|16|
|Argument register|CE_ARG|R/W|H'E804C808|32|
|Argument register for automatically-issued|CE_ARG_CMD12|R/W|H'E804C80C|32|
|CMD12|||||
|Command control register|CE_CMD_CTRL|R/W|H'E804C810|32|
|Transfer block setting register|CE_BLOCK_SET|R/W|H'E804C814|32|
|Clock control register|CE_CLK_CTRL|R/W|H'E804C818|32|
|Buffer access configuration register|CE_BUF_ACC|R/W|H'E804C81C|32|
|Response register 3|CE_RESP3|R|H'E804C820|32|
|Response register 2|CE_RESP2|R|H'E804C824|32|
|Response register 1|CE_RESP1|R|H'E804C828|32|
|Response register 0|CE_RESP0|R|H'E804C82C|32|
|Response register for automatically-issued|CE_RESP_CMD12|R|H'E804C830|32|
|CMD12|||||
|Data register|CE_DATA|R/W|H'E804C834|32|
|Interrupt flag register|CE_INT|R/W|H'E804C840|32|
|Interrupt enable register|CE_INT_EN|R/W|H'E804C844|32|
|Status register 1|CE_HOST_STS1|R|H'E804C848|32|
|Status register 2|CE_HOST_STS2|R|H'E804C84C|32|
|DMA mode setting register|CE_DMA_MODE|R/W|H'E804C85C|32|
|Card detection/port control register|CE_DETECT|R/W|H'E804C870|32|
|Special mode setting register|CE_ADD_MODE|R/W|H'E804C874|32|
|Version register|CE_VERSION|R/W|H'E804C87C|32|

Note: • Do not access registers other than those shown above.

## 39.3.1 Command Setting Register (CE_CMD_SET)

## CE_CMD_SET sets a command sequence.

The command sequence starts when the settings have been made in bits 31 to 16. Note that writing to CE_CMD_SET is disabled while a command sequence is proceeding (i.e., the value of CMDSEQ in CE_HOST_STS1 is 1).

CE_CMD_SET should be set according to the description in section 39.7.12, Setting Values of CE_CMD_SET . This register should be accessed in 16 bits. (The address of bits 31 to 16 is H'E804C800 and that of bits 15 to 0 is H'E804C802.)

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|||CMD[5:0]||||RTYP[1:0]||RBSY|—|WDAT|DWEN|CMLTE|CMD12<br>EN|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R/W|R/W|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||RIDXC[1:0]||RCRC7C[1:0]||—|CRC<br>16C|—|CRC<br>STE|TBIT|OPDM|—|—|SBIT|—|DATW[1:0]||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R/W|R/W|R/W|R/W|R|R/W|R|R/W|R/W|R/W|R|R|R/W|R|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31, 30|―|00|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|29 to 24|CMD[5:0]|All 0|R/W|Command Index|
|||||These bits set a command index ([45:40]).|
|||||Note: Setting a command index in these bits initiates the command|
|||||sequence.|
|23, 22|RTYP[1:0]|00|R/W|Response Type|
|||||00: No response|
|||||01: 6-byte response (R1, R1b, R3, R4, R5)|
|||||10: 17-byte response (R2)|
|||||11: Setting prohibited|
|21|RBSY|0|R/W|Response Busy Select|
|||||Selects whether “busy” is involved in response reception.|
|||||0: No response busy|
|||||1: Response busy involved (R1b)|
|20|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|19|WDAT|0|R/W|Presence/Absence of Data|
|||||0: No data|
|||||1: With data|
|18|DWEN|0|R/W|Read/Write (valid when “with data” is selected)|
|||||0: Read from the card|
|||||1: Write to the card|
|17|CMLTE|0|R/W|Single/Multi Block Transfer Select (valid when “with data” is selected)|
|||||0: Single-block transfer|
|||||1: Multi-block transfer|
|16|CMD12EN|0|R/W|Automatic CMD12 Issuance (valid when multi-block transfer is selected)*|
|||||0: Does not issue CMD12 automatically.|
|||||1: Issues CMD12 automatically (= automatic CMD12)|
|||||For details of automatic CMD12 issuance, see section 39.6.4, Automatic|
|||||CMD12 Issuance.|
|||||Note: Set the transfer block size to 512 bytes. Set RBSY to 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15, 14|RIDXC[1:0]|00|R/W|Response Index Check|
|||||Specify the items to be checked for [45:40] of a 6-byte response or|
|||||[133:128] of a 17-byte response.|
|||||00: Checks the response index (ensure that the response index matches|
|||||the command index.)|
|||||01: Checks the check bits (ensure that the bits are all 1.)|
|||||10: No checking|
|||||11: Setting prohibited|
|13, 12|RCRC7C|00|R/W|Response CRC7 Check|
||[1:0]|||Specify the items to be checked for [7:1] of a 6-byte response or a 17-|
|||||byte response.|
|||||00: Checks CRC7 (set the response type to 01)|
|||||01: Checks the check bits (set the response type to 01)|
|||||10: Checks internal CRC7 (R2 only)|
|||||(set the response type to 10)|
|||||11: No checking|
|11|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|10|CRC16C|0|R/W|CRC16 Check in Reception (valid when “with data” and “read” are|
|||||selected)|
|||||0: Checks CRC16|
|||||1: Does not check CRC16 (use when CMD14)|
|9|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|8|CRCSTE|0|R/W|CRC Status Reception (valid when “with data” and “write” are selected)|
|||||0: Receives CRC status|
|||||1: Does not receive CRC status (use when CMD19)|
|7|TBIT|0|R/W|Transmission Bit Setting|
|||||0: Sets the transmission bit ([46]) to 1.|
|||||1: Sets the transmission bit ([46]) to 0.|
|6|OPDM|0|R/W|Open-Drain Output Mode|
|||||0: Normal output|
|||||1: Open-drain output|
|||||Note: This setting is only applied to the MMC_CMD line.|
|5, 4|―|00|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|3|SBIT|0|R/W|Read Data Start Bit Detection (valid when "with data" and "read" are|
|||||selected)|
|||||0: Detects the start bit when the MMC_D signals set by DATW are all 0.|
|||||1: Detects the start bit when MMC_D[0] is 0.|
|2|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|1, 0|DATW[1:0]|00|R/W|Data Bus Width Setting (valid when "with data" is selected)|
|||||00: 1 bit|
|||||01: 4 bits|
|||||10: 8 bits|
|||||11: Setting prohibited|

Note: * When HPI is executed, use multi-block transfer (pre-defined) without setting this bit to 1.

## 39.3.2 Argument Register (CE_ARG)

CE_ARG sets the argument for the command to be transmitted. Set CE_ARG before starting the command sequence.

||||Bit:|31|30|29|28|27|26|25|24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||ARG[31:16]||||||||
||||Initial value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8<br>7|6|5|4|3|2|1|0|
||||||||||||ARG[15:0]||||||||
||||Initial value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**|||||||||
|31|to|0|ARG[31:0]|||H'00000000||R/W||These bits set [39:8] of|||a command.||||||
|||||||||||Note:|Set the argument||of automatically-issued||||CMD12|by|
||||||||||||CE_ARG_CMD12.||||||||

## 39.3.3 Argument Register for Automatically-Issued CMD12 (CE_ARG_CMD12)

CE_ARG_CMD12 is used to set the argument for the automatically-issued CMD12 in multi-block transfer. For the automatically-issued CMD12, see section 39.6.4, Automatic CMD12 Issuance . Set CE_ARG_CMD12 before starting the command sequence.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||C12ARG[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||C12ARG[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|C12ARG[31:0]|||H'00000000||R/W||These bits||set [39:8] of||the automatically-issued||||CMD12.||

## 39.3.4 Command Control Register (CE_CMD_CTRL)

CE_CMD_CTRL is used to terminate a command sequence forcibly.

||||Bit:||31|30|||29|28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||—|—|||—|—|—|—|—<br>—<br>—<br>—<br>—<br>—<br>—|—|—|—||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R|R|R|R||
||||Bit:||15|14|||13|12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3|2|1|0||
||||||—|—|||—|—|—|—|—<br>—<br>—<br>—<br>—<br>—<br>—|—|—|BREAK||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R|R|R|R/W||
||||||||**Initial**|||||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**|||||
|31|to|1|―||||All||0||R||Reserved|||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||
|0|||BREAK||||0||||R/W||Forcible Termination of Command Sequence|||||
||||||||||||||To discontinue the current command sequence, write 1 to this bit while|||||
||||||||||||||the bit is 0 and then write 0.|||||
||||||||||||||After the above procedure, check if the value of the CMDSEQ bit in|||||
||||||||||||||CE_HOST_STS1 has become 0 and then|perform a software reset.||||
||||||||||||||Note: Since a software reset returns the register||value to the initial value,|||
||||||||||||||the register needs be set again.|||||

## 39.3.5 Transfer Block Setting Register (CE_BLOCK_SET)

CE_BLOCK_SET specifies the size of the block and the number of blocks for the data to be transferred. Set CE_BLOCK_SET before starting the command sequence.

||||Bit:|31|30|29|28|27|26|25<br>24<br>23|22|21|20|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||BLKCNT[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0<br>0<br>0|0|0||0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9<br>8<br>7|6|5||4|3|2|1|0|
|||||||||||BLKSIZ[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|1<br>0<br>0|0|0||0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|
|||||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**|||||||||
|31|to|16|BLKCNT|||H'0000||R/W||Number of Blocks|for Transfer||||||||
||||[15:0]|||||||Note: This setting|is valid for multi-block transfer.||||||||
|15|to|0|BLKSIZ|||H'0200||R/W||Transfer Block Size|||||||||
||||[15:0]|||||||Note: Transfer block size should||||be|set as|follows.|||
|||||||||||Single-block transfer: 1 to 512||||bytes|||||
|||||||||||Multi-block transfer: 512 bytes|||||||||

## 39.3.6 Clock Control Register (CE_CLK_CTRL)

CE_CLK_CTRL controls the MMC clock and sets timeout values. Do not change the setting of this register while a command sequence is in progress.

||Bit:|Bit:|31|30|||29|28|27||26|25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|—|||—|—|—||—|—<br>CLKEN<br>—<br>—<br>—|—||CLKDIV[3:0]||||
||Initial value:||0|0|||0|0|0||0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||R/W:||R|R|||R|R|R||R|R<br>R/W<br>R<br>R<br>R|R|R/W|R/W|R/W|R/W||
||Bit:||15|14|||13|12|11||10|9<br>8<br>7<br>6<br>5|4|3|2|1|0||
||||—|—||SRSPTO[1:0]||||SRBSYTO[3:0]<br>SRWDTO[3:0]||||—|—|—|—||
||Initial value:||0|0|||0|0|0||0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||R/W:||R|R||R/W||R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R|R|R|R||
||||||**Initial**||||||||||||||
|**Bit**|**Bit Name**||||**Value**||||**R/W**|||**Description**|||||||
|31 to 25|―||||All||0||R|||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|24|CLKEN||||0||||R/W|||MMC Clock Output Control|||||||
|||||||||||||0: Does not output the MMC clock (tied to|||low level)||||
|||||||||||||1: Outputs the MMC clock|||||||
|23 to 20|―||||All||0||R|||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|19 to 16|CLKDIV[3:0]||||0000||||R/W|||MMC Clock Frequency Setting|||||||
|||||||||||||0000: P1/2|||||||
|||||||||||||0001: P1/22|||||||
|||||||||||||0111: P1/28|||||||
|||||||||||||1000: P1/29|||||||
|||||||||||||1001: P1/210|||||||
|||||||||||||1010 to 1111: Setting prohibited|||||||
|15, 14|―||||00||||R|||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|13, 12|SRSPTO||||00||||R/W|||Response Timeout Setting|||||||
||[1:0]|||||||||||Specifies the timeout period for the RSPTO bit of CE_INT.|||||||
|||||||||||||00: 64 MMC clock cycles|||||||
|||||||||||||01: 128 MMC clock cycles|||||||
|||||||||||||10: 256 MMC clock cycles|||||||
|||||||||||||11: Setting prohibited|||||||
|11 to 8|SRBSYTO||||0000||||R/W|||Response Busy Timeout Setting|||||||
||[3:0]|||||||||||Specifies the timeout period for the RBSYTO bit||||of CE_INT.|||
|||||||||||||0000: 214MMC clock cycles|||||||
|||||||||||||0001: 215MMC clock cycles|||||||
|||||||||||||:|||||||
|||||||||||||1110: 228MMC clock cycles|||||||
|||||||||||||1111: 229MMC clock cycles|||||||
|7 to 4|SRWDTO||||0000||||R/W|||Write Data/Read Data Timeout Setting|||||||
||[3:0]|||||||||||Specifies the timeout period for the WDATTO and RDATTO bits of|||||||
|||||||||||||CE_INT.|||||||
|||||||||||||0000: 214MMC clock cycles|||||||
|||||||||||||0001: 215MMC clock cycles|||||||
|||||||||||||:|||||||
|||||||||||||1110: 228MMC clock cycles|||||||
|||||||||||||1111: 229MMC clock cycles|||||||
|3 to 0|―||||All||0||R|||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||

## 39.3.7 Buffer Access Configuration Register (CE_BUF_ACC)

CE_BUF_ACC configures the method of accessing data registers and mode of DMA transfer. Do not change the setting of this register while a command sequence is in progress. For explanation of the buffers, see section 39.6.3, Buffer Structure and Buffer Accesses .

||||Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22<br>21||20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—|—|||—|—|—|—|—<br>—<br>—<br>DMAR<br>EN<br>DMAW<br>EN||—|—|—|—|ATYP||
||||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0||0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R/W<br>R/W<br>R<br>R<br>R||R|R|R|R|R/W||
||||Bit:|15|14|||13|12|11|10|9<br>8<br>7<br>6<br>5||4|3|2|1|0||
|||||—|—|||—|—|—|—|—<br>—<br>—<br>—<br>—||—|—|—|—|—||
||||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0||0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R||R|R|R|R|R||
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**||||||||
|31|to|26|―|||All||0||R||Reserved||||||||
|||||||||||||These bits are always read as||0. The write value should always be 0.||||||
|25|||DMAWEN|||0||||R/W||Buffer Write DMA Transfer Request|||Enable|||||
|||||||||||||0: Disables DMA transfer request for buffer writing||||||||
|||||||||||||1: Enables DMA transfer request for buffer writing||||||||
|24|||DMAREN|||0||||R/W||Buffer Read DMA Transfer Request|||Enable|||||
|||||||||||||0: Disables DMA transfer request for buffer reading||||||||
|||||||||||||1: Enables DMA transfer request for buffer reading||||||||
|23|to|17|―|||All||0||R||Reserved||||||||
|||||||||||||These bits are always read as||0. The write value should always be 0.||||||
|16|||ATYP|||0||||R/W||Buffer Access Select||||||||
|||||||||||||0: When not swapped byte-wise.||||||||
|||||||||||||1: When swapped byte-wise.||||||||
|||||||||||||Note: For explanation of buffer||access, see section 39.6.3, Buffer||||||
|||||||||||||Structure and Buffer Accesses.||||||||
|15|to|0|―|||All||0||R||Reserved||||||||
|||||||||||||These bits are always read as||0. The write value should always be 0.||||||

## 39.3.8 Response Registers 3 to 0 (CE_RESP3 to CE_RESP0)

CE_RESP3 to CE_RESP0 are the registers for storing the response that has been received. For the formats of response values, see section 39.6.1, Command/Response Formats .

##  CE_RESP3

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||RSP[127:112]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||RSP[111:96]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|RSP[127:96]|||H'00000000||R||[127:96] of a||17-byte response|||are|stored.||||

##  CE_RESP2

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||RSP[95:80]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||RSP[79:64]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|RSP[95:64]|||H'00000000||R||[95:64] of a 17-byte response|||||are|stored.||||

##  CE_RESP1

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||RSP[63:48]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||RSP[47:32]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|RSP[63:32]|||H'00000000||R||[63:32] of a 17-byte response|||||are|stored.||||

##  CE_RESP0

**==> picture [483 x 173] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>RSP[31:16]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>RSP[15:0]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 0 RSP[31:0] H'00000000 R [39:8] of a 6-byte response or [31:0] of a 17-byte response are stored.<br>Note: The response to the automatically-issued CMD12 is stored in<br>CE_RESP_CMD12.<br>**----- End of picture text -----**<br>

## 39.3.9 Response Register for Automatically-Issued CMD12 (CE_RESP_CMD12)

CE_RESP_CMD12 is the register for storing the response to the automatically-issued CMD12.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||RSP12[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||RSP12[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|RSP12[31:0]|||H'00000000||R||[39:8] of a response to||||the automatically-issued||||CMD12|are stored.|

## 39.3.10 Data Register (CE_DATA)

CE_DATA is used to access the buffers of this module.

For the write/read data formats, see section 39.6.2, Data Block Format .

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||DATA[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||DATA[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|DATA[31:0]|||H'00000000||R/W||Buffer write/read|||data [31:0]|||||||

## 39.3.11 Interrupt Flag Register (CE_INT)

CE_INT indicates various status during execution of a command sequence. Each bit is set to 1 when its setting condition has been met. To clear flag(s), write 0 only to the bit(s) to be cleared and write 1 to the other bits. For the operation in the case of an error or timeout, see section 39.6.7, Operation in the Case of Error/Timeout .

||||Bit:|Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||—|—|||—|—|—|CMD12|<br>CMD12<br>CMD12<br>DTRAN<br>BUFR|BUFW|BUFR|—|—|RBSY|CRSP||
|||||||||||||DRE|RBE<br>CRE<br>E<br>E|EN|EN|||E|E||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:||R|R|||R|R|R|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R|R|R/W|R/W||
||||Bit:||15|14|||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
||||||CMD|BUF|||—|—|WDAT|RDAT|RIDX<br>RSP<br>—<br>—|—|CRCS|WDAT|RDAT|RBSY|RSP||
||||||VIO|VIO|||||ERR|ERR|ERR<br>ERR||TO|TO|TO|TO|TO||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:||R/W|R/W|||R|R|R/W|R/W|R/W<br>R/W<br>R<br>R|R|R/W|R/W|R/W|R/W|R/W||
||||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**||||||||
|31|to|27|―||||All||0||R||Reserved||||||||
||||||||||||||These bets are always read as 0. The writing value should always be 0.||||||||
|26|||CMD12DRE||||0||||R/W*1||Automatic CMD12 Issuance & Buffer Read Complete||||||||
||||||||||||||[Setting condition]||||||||
||||||||||||||Response busy for automatically-issued CMD12|||||and buffer reading have|||
||||||||||||||been completed.||||||||
||||||||||||||[Clearing condition]||||||||
||||||||||||||Writing a 0 to this bit||||||||
||||||||||||||Note: When CMD12DRE has||been set, CMD12RBE, CMD12CRE, and||||||
||||||||||||||BUFRE have also been set. So, these bits should be cleared as||||||||
||||||||||||||well.||||||||
|25|||CMD12RBE||||0||||R/W*1||Automatic CMD12 Issuance Response Busy Complete||||||||
||||||||||||||[Setting condition]||||||||
||||||||||||||Reception of the response and response busy for an automatically-issued||||||||
||||||||||||||CMD12 have been completed.||||||||
||||||||||||||[Clearing condition]||||||||
||||||||||||||Writing a 0 to this bit||||||||
||||||||||||||Note: When CMD12RBE is set, CMD12CRE is also set. So, clear the bit||||||||
||||||||||||||as well. When CMD12RBE is set during a|||||multi-block write,|||
||||||||||||||DTRANE is also set. So clear|||the bit as well.|||||
|24|||CMD12CRE||||0||||R/W*1||Automatic CMD12 Response||Complete||||||
||||||||||||||[Setting condition]||||||||
||||||||||||||The response to an automatically-issued CMD12 has been received.||||||||
||||||||||||||[Clearing condition]||||||||
||||||||||||||Writing a 0 to this bit||||||||
|23|||DTRANE||||0||||R/W*1||Data Transmission Complete||||||||
||||||||||||||[Setting conditions]||||||||
||||||||||||||Transmission of all blocks of data has been completed.||||||||
||||||||||||||When configured to receive||CRC status:||||||
||||||||||||||Completion of busy (data busy) after reception of CRC status||||||||
||||||||||||||When configured not to receive CRC status:||||||||
||||||||||||||Completion of data transmission||||||||
||||||||||||||[Clearing condition]||||||||
||||||||||||||Writing a 0 to this bit||||||||
|22|||BUFRE||||0||||R/W*1||Buffer Read Complete||||||||
||||||||||||||[Setting condition]||||||||
||||||||||||||All blocks of data have been received and||||the data have been read from||||
||||||||||||||the buffer||||||||
||||||||||||||[Clearing condition]||||||||
||||||||||||||Writing a 0 to this bit||||||||

||||**Initial**|||
|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|21||BUFWEN|0|R/W*1|Buffer Write Ready|
||||||[Setting condition]|
||||||The buffer has become empty and ready for writing.|
||||||[Clearing condition]|
||||||Writing a 0 to this bit|
||||||Note: When data is written to CE_DATA by the CPU, clear this bit first,|
||||||and then write the amount of data equivalent to the block size set in|
||||||the CE_BLOCK_SET register. Note that this bit is not set when|
||||||DMA transfer request for buffer writing is enabled.|
|20||BUFREN|0|R/W*1|Buffer Read Ready|
||||||[Setting condition]|
||||||Transfer block size of data have been stored in the buffer and it has|
||||||become ready for reading|
||||||[Clearing condition]|
||||||Writing a 0 to this bit|
||||||Note: When data is read from CE_DATA by the CPU, clear this bit first,|
||||||and then read the amount of data equivalent to the block size set in|
||||||the CE_BLOCK_SET register. Note that this bit is not set when|
||||||DMA transfer request for buffer reading is enabled.|
|19,|18|―|00|R|Reserved|
||||||These bits are always read as 0.The write value should always be 0.|
|17||RBSYE|0|R/W*1|Response Busy Complete|
||||||[Setting condition]|
||||||Reception of a response and response busy have been completed|
||||||[Clearing condition]|
||||||Writing a 0 to this bit|
||||||Note: When RBSYE has been set, CRSPE has also been set. So, this bit|
||||||should be cleared as well. Completion of reception of the response|
||||||and response busy for automatically-issued CMD12 is reflected in|
||||||CMD12RBE.|
|16||CRSPE|0|R/W*1|Command/Response Complete|
||||||[Setting conditions]|
||||||A command has been transmitted or a response has been received|
||||||When configured not to receive response:|
||||||A command has been transmitted|
||||||When configured to receive 6- or 17-byte response:|
||||||A response has been received|
||||||[Clearing condition]|
||||||Writing a 0 to this bit|
||||||Note: Completion of reception of the response to automatically-issued|
||||||CMD12 is reflected in CMD12CRE.|
|15||CMDVIO|0|R/W*1|Command Issuance Error|
||||||[Setting conditions]|
||||||Illegal setting has been made in CE_CMD_SET or CE_BLOCK_SET|
||||||During execution of a command sequence:|
||||||Writing to CMD[5:0] in CE_CMD_SET|
||||||(The command sequence is not stopped automatically.)|
||||||At the start of command sequence:|
||||||Writing to CMD[5:0] in CE_CMD_SET when the registers have been|
||||||set for one of the following combinations of selection|
||||||- No response + response busy|
||||||- No response + with data|
||||||- No data + automatic CMD12 issuance|
||||||- With data + single-block transfer + automatic CMD12 issuance|
||||||- With data + response busy + automatic CMD12 issuance|
||||||- With data + transfer block size = 0|
||||||- With data + transfer block size513|
||||||- With data + multi-block transfer + number of blocks for transfer = 0|
||||||[Clearing condition]|
||||||Writing a 0 to this bit|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|14|BUFVIO|0|R/W*1|Buffer Access Error|
|||||[Setting conditions]|
|||||Illegal buffer access has been attempted.|
|||||CE_ DATA has been accessed exceeding the block size set in|
|||||BLKSIZ[15:0] in CE_BLOCK_SET|
|||||While data is being read from the card:|
|||||CE_DATA has been accessed with BUFREN not set (when DMA is|
|||||used, with no DMA transfer request asserted for buffer reading)|
|||||While data is being written to the card:|
|||||CE_DATA has been accessed with BUFWEN not set (when DMA is|
|||||used, with no DMA transfer request asserted for buffer writing)|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: When BUFVIO is set, the command sequence is not stopped|
|||||automatically. When an error occurs, this bit may be set.|
|13, 12|―|00|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11|WDATERR|0|R/W*1|Write Data Error|
|||||[Setting conditions]|
|||||Error is found in the data that has been written.|
|||||Error is in the status of the CRC status|
|||||Error is in the end bit of the CRC status|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: When WDATERR is set, the command sequence is stopped|
|||||automatically.|
|10|RDATERR|0|R/W*1|Read Data Error|
|||||[Setting conditions]|
|||||Error is found in the read data.|
|||||Error is in CRC16 of the read data|
|||||Error is in the end bit of the read data|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: When RDATERR is set, the command sequence is stopped|
|||||automatically.|
|9|RIDXERR|0|R/W*1|Response Index Error|
|||||[Setting condition]|
|||||Error has been found in the index value of the response.|
|||||When an error has been found in [45:40] of a 6-byte response|
|||||(including automatically-issued CMD12) or [133:128] of a 17-byte|
|||||response|
|||||(The items to be checked are set by RIDXC in CE_CMD_SET.)|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: When RIDXERR is set, the command sequence is stopped|
|||||automatically.|
|8|RSPERR|0|R/W*1|Response Error|
|||||[Setting conditions]|
|||||Error has been found in the response values of the response.|
|||||Transmission bit in the response is high|
|||||Error is in the end bit of the response|
|||||When an error has been found in [7:1] of a 6-byte response (including|
|||||automatically-issued CMD12) or a 17-byte response|
|||||(The items to be checked are set by RCRC7C in CE_CMD_SET.)|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: When RSPERR is set, the command sequence is stopped|
|||||automatically.|
|7 to 5|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|4|CRCSTO|0|R/W*1|CRC Status Timeout|
|||||[Setting condition]|
|||||CRC status could not be received|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: The command sequence is not stopped even if CRCSTO is set.|
|3|WDATTO|0|R/W*1|Write Data Timeout|
|||||[Setting condition]|
|||||The busy status remains unchanged after the period set by SRWDTO in|
|||||CE_CLK_CTRL after the CRC status was received.|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: The command sequence is not stopped even if WDATTO is set.|
|2|RDATTO|0|R/W*1|Read Data Timeout|
|||||[Setting conditions]|
|||||Read data could not be received within the period set by SRWDTO in|
|||||CE_CLK_CTRL after the read command was transmitted|
|||||Read data could not be received within the period set by SRWDTO|
|||||in CE_CLK_CTRL after the read data was received.|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: The command sequence is not stopped even if RDATTO is set.|
|1|RBSYTO|0|R/W*1|Response Busy Timeout|
|||||[Setting condition]|
|||||The busy status remains unchanged after the period set by SRBSYTO in|
|||||CE_CLK_CTRL after the command (including automatically-issued|
|||||CMD12) was transmitted.|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: The command sequence is not stopped even if RBSYTO is set.|
|0|RSPTO|0|R/W*1|Response Timeout|
|||||[Setting condition]|
|||||Response could not be received within the period set by SRSPTO in|
|||||CE_CLK_CTRL after the command (including automatically-issued|
|||||CMD12) was transmitted.|
|||||[Clearing condition]|
|||||Writing a 0 to this bit|
|||||Note: The command sequence is not stopped even if RSPTO is set.|

Note 1. A 0 is the only value that can be written to the bit. Writing a 1 is ignored.

## 39.3.12 Interrupt Enable Register (CE_INT_EN)

CE_INT_EN controls output of the CE_INT-related interrupt signals. If a flag in CE_INT is set to 1 while its corresponding bit in CE_INT_EN is set to 1, an interrupt request is output. For details on interrupt requests, see section 39.4, Interrupt Requests .

||Bit:|Bit:|31||30||29|28|27|26|25<br>24<br>23<br>22<br>21||20<br>19<br>18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—||—||—|—|—|MCMD|<br>MCMD<br>MCMD<br>MDT<br>MBUF<br>MBUF||MBUF<br>—<br>—|MRBSY|<br>MCRSP||
|||||||||||12DRE|12RBE<br>12CRE<br>RANE<br>RE<br>WEN||REN|E|E||
||Initial value:||0||0||0|0|0|0|0<br>0<br>0<br>0<br>0||0<br>0<br>0|0|0||
||R/W:||R||R||R|R|R|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W||R/W<br>R<br>R|R/W|R/W||
||Bit:||15||14||13|12|11|10|9<br>8<br>7<br>6<br>5||4<br>3<br>2|1|0||
||||MCMD||MBUF||—|—|MWDAT|<br>MRDAT|<br>MRIDX<br>MRSP<br>—<br>—<br>—||MCRC<br>MWDA<br>MRDA|MRBS|MRSP||
||||VIO||VIO||||ERR|ERR|ERR<br>ERR||STO<br>TTO<br>TTO|YTO|TO||
||Initial value:||0||0||0|0|0|0|0<br>0<br>0<br>0<br>0||0<br>0<br>0|0|0||
||R/W:||R/W||R/W||R|R|R/W|R/W|R/W<br>R/W<br>R<br>R<br>R||R/W<br>R/W<br>R/W|R/W|R/W||
||||||**Initial**||||||||||||
|**Bit**|**Bit Name**||||**Value**||||**R/W**||**Description**||||||
|31 to 27|―||||All||0||R||Reserved||||||
||||||||||||These bits are always read as||0. The write value should always be 0.||||
|26|MCMD12DRE||||0||||R/W||CMD12DRE Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the CMD12DRE flag||||
||||||||||||1: Enables interrupt output by||the CMD12DRE flag||||
|25|MCMD12RBE||||0||||R/W||CMD12RBE Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the CMD12RBE flag||||
||||||||||||1: Enables interrupt output by||the CMD12RBE flag||||
|24|MCMD12CRE||||0||||R/W||CMD12CRE Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the CMD12CRE flag||||
||||||||||||1: Enables interrupt output by||the CMD12CRE flag||||
|23|MDTRANE||||0||||R/W||DTRANE Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the DTRANE flag||||
||||||||||||1: Enables interrupt output by||the DTRANE flag||||
|22|MBUFRE||||0||||R/W||BUFRE Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the BUFRE flag||||
||||||||||||1: Enables interrupt output by||the BUFRE flag||||
|21|MBUFWEN||||0||||R/W||BUFWEN Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the BUFWEN flag||||
||||||||||||1: Enables interrupt output by||the BUFWEN flag||||
|20|MBUFREN||||0||||R/W||BUFREN Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the BUFREN flag||||
||||||||||||1: Enables interrupt output by||the BUFREN flag||||
|19, 18|―||||00||||R||Reserved||||||
||||||||||||These bits are always read as||0. The write value should always be 0.||||
|17|MRBSYE||||0||||R/W||RBSYE Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the RBSYE flag||||
||||||||||||1: Enables interrupt output by||the RBSYE flag||||
|16|MCRSPE||||0||||R/W||CRSPE Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the CRSPE flag||||
||||||||||||1: Enables interrupt output by||the CRSPE flag||||
|15|MCMDVIO||||0||||R/W||CMDVIO Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the CMDVIO flag||||
||||||||||||1: Enables interrupt output by||the CMDVIO flag||||
|14|MBUFVIO||||0||||R/W||BUFVIO Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the BUFVIO flag||||
||||||||||||1: Enables interrupt output by||the BUFVIO flag||||
|13, 12|―||||00||||R||Reserved||||||
||||||||||||These bits are always read as||0. The write value should always be 0.||||
|11|MWDATERR||||0||||R/W||WDATERR Interrupt Enable||||||
||||||||||||0: Disables interrupt output by||the WDATERR flag||||
||||||||||||1: Enables interrupt output by||the WDATERR flag||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|10|MRDATERR|0|R/W|RDATERR Interrupt Enable|
|||||0: Disables interrupt output by the RDATERR flag|
|||||1: Enables interrupt output by the RDATERR flag|
|9|MRIDXERR|0|R/W|RIDXERR Interrupt Enable|
|||||0: Disables interrupt output by the RIDXERR flag|
|||||1: Enables interrupt output by the RIDXERR flag|
|8|MRSPERR|0|R/W|RSPERR Interrupt Enable|
|||||0: Disables interrupt output by the RSPERR flag|
|||||1: Enables interrupt output by the RSPERR flag|
|7 to 5|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|MCRCSTO|0|R/W|CRCSTO Interrupt Enable|
|||||0: Disables interrupt output by the CRCSTO flag|
|||||1: Enables interrupt output by the CRCSTO flag|
|3|MWDATTO|0|R/W|WDATTO Interrupt Enable|
|||||0: Disables interrupt output by the WDATTO flag|
|||||1: Enables interrupt output by the WDATTO flag|
|2|MRDATTO|0|R/W|RDATTO Interrupt Enable|
|||||0: Disables interrupt output by the RDATTO flag|
|||||1: Enables interrupt output by the RDATTO flag|
|1|MRBSYTO|0|R/W|RBSYTO Interrupt Enable|
|||||0: Disables interrupt output by the RBSYTO flag|
|||||1: Enables interrupt output by the RBSYTO flag|
|0|MRSPTO|0|R/W|RSPTO Interrupt Enable|
|||||0: Disables interrupt output by the RSPTO flag|
|||||1: Enables interrupt output by the RSPTO flag|

## 39.3.13 Status Register 1 (CE_HOST _STS1)

CE_HOST_STS1 indicates the number of blocks that have been transferred, states of the MMC_CMD and MMC_D lines, index of the received response, and command sequence status.

|CE_HOST_STS1 indicates the number of blocks that have been transferred, states of the MMC_CMD and MMC_D<br>lines, index of the received response, and command sequence status.|CE_HOST_STS1 indicates the number of blocks that have been transferred, states of the MMC_CMD and MMC_D<br>lines, index of the received response, and command sequence status.|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W:<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W:<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>RCVBLK[15:0]<br>RSPIDX[5:0]<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>DATSIG[7:0]<br>CMD<br>SEQ<br>CMD<br>SIG||
|31<br>CMDSEQ|0<br>R<br>Command Sequence Status<br>0: Command sequence is in the initial state<br>1: Command sequence is being executed|
|30<br>CMDSIG|Undefined<br>R<br>MMC_CMD Line Status<br>Indicates the state on the MMC_CMD line.|
|29 to 24<br>RSPIDX<br>[5:0]|H'00<br>R<br>Response Index<br>Indicate [45:40] of a 6-byte response or [133:128] of a 17-byte response.|
|23 to 16<br>DATSIG<br>[7:0]|Undefined<br>R<br>MMC_D Status<br>Indicate the states on the MMC_D[7:0] lines.<br>Note: When an error or timeout occurs, MMCDAT[0] may remain 0.|
|15 to 0<br>RCVBLK<br>[15:0]|H'0000<br>R<br>Number of Transferred Blocks<br>Indicate the number blocks that have been transferred.<br>When the DWEN bit in CE_CMD_SET is 0<br>Number of blocks read from the card<br>When the DWEN bit in CE_CMD_SET is 1<br>Number of blocks written to the card|

## 39.3.14 Status Register 2 (CE_HOST _STS2)

CE_HOST _STS2 indicates timeout and error status.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18||17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||CRC<br>STE|CRC<br>16E|AC12<br>CRCE|RSP<br>CRC7E|CRC<br>STEBE|RDAT<br>EBE|AC12R<br>EBE|<br>RSP<br>EBE|AC12<br>IDXE|RSP<br>IDXE|—|—|—||CRCST[2:0]|||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0||0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R||R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2||1|0|
|||—|STRD|DATBS|<br>CRCST|<br>AC12|RSPBS|<br>AC12|STRS|—|—|—|—|—|—||—|—|
||||ATTO|YTO|TO|BSYTO|YTO|RSPTO|PTO||||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0||0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R||R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|||CRCSTE|0|R|CRC Status Error|
|||||||This bit is set to 1 when an error is found in the CRC status value.|
|30|||CRC16E|0|R|Read Data CRC16 Error|
|||||||This bit is set to 1 when an error is found in CRC16 in the read data.|
|29|||AC12CRCE|0|R|Automatic CMD12 Response CRC7 Error|
|||||||This bit is set to 1 when an error is found in [7:1] of the response to the|
|||||||automatically-issued CMD12.|
|||||||Note: The items to be checked are set by RCRC7C in CE_CMD_SET.|
|28|||RSPCRC7E|0|R|Command Response CRC7 Error (other than automatically-issued|
|||||||CMD12)|
|||||||This bit is set to 1 when an error is found in [7:1] of a 6-byte response or a|
|||||||17-byte response.|
|||||||Note: The items to be checked are set by RCRC7C in CE_CMD_SET.|
|27|||CRCSTEBE|0|R|CRC Status End Bit Error|
|||||||This bit is set to 1 when an error is found in the end bit in CRC status.|
|26|||RDATEBE|0|R|Read Data End Bit Error|
|||||||This bit is set to 1 when an error is found in the end bit in the read data.|
|25|||AC12REBE|0|R|Automatic CMD12 Response End Bit Error|
|||||||This bit is set to 1 when an error is found in the end bit of the response to|
|||||||the automatically-issued CMD12.|
|24|||RSPEBE|0|R|Command Response End Bit Error (other than automatically-issued|
|||||||CMD12)|
|||||||This bit is set to 1 when an error is found in the end bit of the response.|
|23|||AC12IDXE|0|R|Automatic CMD12 Response Index Error|
|||||||This bit is set to 1 when an error is found in [45:40] of the response to the|
|||||||automatically-issued CMD12.|
|||||||Note: The items to be checked are set by RIDXC in CE_CMD_SET.|
|22|||RSPIDXE|0|R|Command Response Index Error (other than automatically-issued|
|||||||CMD12)|
|||||||This bit is set to 1 when an error is found in [45:40] of a 6-byte response|
|||||||or [133:128] of a 17-byte response.|
|||||||Note: The items to be checked are set by RIDXC in CE_CMD_SET.|
|21|to|19|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|18|to|16|CRCST|000|R|CRC Status|
||||[2:0]|||Indicate the value of the CRC status that has been received.|
|15|||―|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|14|||STRDATTO|0|R|Read Data Timeout|
|||||||This bit is set to 1 if read data is not received within the period set by|
|||||||the SRWDTO bits in CE_CLK_CTRL after a read command was|
|||||||transmitted.|
|||||||This bit is set to 1 if read data is not received within the period set by|
|||||||the SRWDTO bits in CE_CLK_CTRL after a read data was received.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|13|DATBSYTO|0|R|Data Busy Timeout|
|||||This bit is set to 1 if busy status remains unchanged after the period set|
|||||by the SRWDTO bits in CE_CLK_CTRL after the CRC status was|
|||||received.|
|12|CRCSTTO|0|R|CRC Status Timeout|
|||||This bit is set to 1 if CRC status could not be received.|
|11|AC12BSYTO|0|R|Automatic CMD12 Response Busy Timeout|
|||||This bit is set to 1 if busy state remains unchanged after the period set by|
|||||the SRBSYTO bits in CE_CLK_CTRL after the automatically-issued|
|||||CMD12 was transmitted.|
|10|RSPBSYTO|0|R|Response Busy Timeout|
|||||This bit is set to 1 if busy state remains unchanged after the period set by|
|||||the SRBSYTO bits in CE_CLK_CTRL after a command (other than|
|||||automatically-issued CMD12) was transmitted.|
|9|AC12RSPTO|0|R|Automatic CMD12 Response Timeout|
|||||This bit is set to 1 if the response is not received within the period set by|
|||||the SRSPTO bits in CE_CLK_CTRL after the automatically-issued|
|||||CMD12 was transmitted.|
|8|STRSPTO|0|R|Response Timeout|
|||||This bit is set to 1 if the response is not received within the period set by|
|||||the SRSPTO bits in CE_CLK_CTRL after a command (other than|
|||||automatically-issued CMD12) was transmitted.|
|7 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 39.3.15 DMA Mode Setting Register (CE_DMA_MODE)

CE_DMA_MODE sets the transfer unit for DMA transfer.

||||Bit:|Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||—|—|||—|—|—|—|—<br>—<br>—<br>—<br>—<br>—<br>—|—|—|—||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R|R|R|R||
||||Bit:||15|14|||13|12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3|2|1|0||
||||||—|—|||—|—|—|—|—<br>—<br>—<br>—<br>—<br>—<br>—|—|—|DMA||
|||||||||||||||||SEL||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R|R|R|R/W||
||||||||**Initial**|||||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**|||||
|31|to|1|―||||All||0||R||Reserved|||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||
|0|||DMASEL||||0||||R/W||DMA Transfer Size Select|||||
||||||||||||||Selects the transfer unit for CE_DATA read/write||DMA|transfer. Set this||
||||||||||||||bit in combination with the transfer size set in the DMA|||channel||
||||||||||||||configuration register.|||||
||||||||||||||0: 2-byte (word) or 4-byte (longword) unit|||||
||||||||||||||1: 64-byte (longword16) unit|||||
||||||||||||||Note: For DMA transfer in 64-byte units, set address H’E804C800 as the|||||
||||||||||||||destination or source of DMA transfer instead of the data register|||||
||||||||||||||(CE_DATA).|||||
||||||||||||||Moreover, when a transfer error or timeout||occurs during DMA|||
||||||||||||||transfer in 64-byte units, leading to the forced termination of|||||
||||||||||||||transfer, write 0 to this bit and then set it to 1 again. Also do this|||||
||||||||||||||whenever a software reset is used.|||||

## 39.3.16 Card Detection/Port Control Register (CE_DETECT)

CE_DETECT controls card detection. For details on interrupt requests by card detection, see section 39.4, Interrupt Requests .

|Requests.|||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||Bit:||31|30||29|28|27||26|25<br>24<br>23<br>22<br>21||20|19|18|17|16||
||||—|—||—|—|—||—|—<br>—<br>—<br>—<br>—||—|—|—|—|—||
||Initial value:||0|0||0|0|0||0|0<br>0<br>0<br>0<br>0||0|0|0|0|0||
||R/W:||R|R||R|R|R||R|R<br>R<br>R<br>R<br>R||R|R|R|R|R||
||Bit:||15|14||13|12|11||10|9<br>8<br>7<br>6<br>5||4|3|2|1|0||
||||—|CD||CD|CD|—||—|—<br>—<br>—<br>—<br>MCD||MCD|—|—|—|—||
|||||SIG||RISE|FALL||||RISE||FALL||||||
||Initial value:||0|—||0|0|0||—|0<br>0<br>0<br>0<br>0||0|0|0|0|0||
||R/W:||R|R||R/W*|R/W*|R||R|R<br>R<br>R<br>R<br>R/W||R/W|R|R|R|R||
||||||**Initial**||||||||||||||
|**Bit**|**Bit Name**||||**Value**|||**R/W**|||**Description**||||||||
|31 to 15|―||||All 0|||R|||Reserved||||||||
||||||||||||These bits are always read as||0. The write value should always be 0.||||||
|14|CDSIG||||Undefined|||R|||MMC_CD Pin Status Indication||||||||
||||||||||||Indicates the MMC_CD pin status.||||||||
|13|CDRISE||||0|||R/W*1|||MMC_CD Pin Rise Detection|Flag|||||||
||||||||||||[Setting condition]||||||||
||||||||||||The MMC_CD pin level changes from low||||to high.||||
||||||||||||[Clearing condition]||||||||
||||||||||||Writing a 0 to this bit||||||||
|12|CDFALL||||0|||R/W*1|||MMC_CD Pin Fall Detection Flag||||||||
||||||||||||[Setting condition]||||||||
||||||||||||The MMC_CD pin level changes from high to low.||||||||
||||||||||||[Clearing condition]||||||||
||||||||||||Writing a 0 to this bit||||||||
|11|―||||0|||R|||Reserved||||||||
||||||||||||This bit is always read as 0. The write value should always be 0.||||||||
|10|―||||Undefined|||R|||Reserved||||||||
||||||||||||The write value should always be 0.||||||||
|9 to 6|―||||All 0|||R|||Reserved||||||||
||||||||||||These bits are always read as||0. The write value should always be 0.||||||
|5|MCDRISE||||0|||R/W|||CDRISE Interrupt Enable||||||||
||||||||||||0: Disables interrupt output by||the CDRISE flag.||||||
||||||||||||1: Enables interrupt output by||the CDRISE flag.||||||
|4|MCDFALL||||0|||R/W|||CDFALL Interrupt Enable||||||||
||||||||||||0: Disables interrupt output by||the CDFALL flag.||||||
||||||||||||1: Enables interrupt output by||the CDFALL flag.||||||
|3 to 0|―||||All 0|||R|||Reserved||||||||
||||||||||||These bits are always read as||0. The write value should always be 0.||||||

Note 1. A 0 is the only value that can be written to the bit. Writing a 1 is ignored.

## 39.3.17 Special Mode Setting Register (CE_ADD_MODE)

CE_ADD_MODE controls the internal clock.

||||Bit:|Bit:|31|30|||29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||—|—|||—|—|—|—|—|—|—|—|—|—|CLK|—|—|—||
||||||||||||||||||||MAIN|||||
||||Initial value:||0|0|||0|0|0|0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R|R|R|R|R|R|R/W|R|R|R||
||||Bit:||15|14|||13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||||—|—|||—|—|—|—|—|—|—|—|—|—|—|—|—|—||
||||Initial value:||0|0|||0|0|0|0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R|R|R|R|R|R|R|R|R|R||
||||||||**Initial**|||||||||||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**|||||||||||
|31|to|20|―||||All||0||R||Reserved|||||||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||||
|19|||CLKMAIN||||0||||R/W||Internal Clock Control|||||||||||
||||||||||||||0: Normal mode|||||||||||
||||||||||||||1: Low power consumption mode (only card detection is enabled)|||||||||||
|18|to|0|―||||All||0||R||Reserved|||||||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||||

## 39.3.18 Version Register (CE_VERSION)

CE_VERSION indicates the version number and controls software reset of this module.

||||Bit:|Bit:|31|30||29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||SW|—||—|—|—|—|—<br>—<br>—|—|—|—|—|—|—|—||
||||||RST||||||||||||||||
||||Initial value:||0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:||R/W|R||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||||Bit:||15|14||13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||||||||||||VERSION[15:0]|||||||||
||||Initial value:||0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|1|1||
||||R/W:||R|R||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**|||||||||
|31|||SWRST|||0||||R/W||Software Reset|||||||||
|||||||||||||0: Software reset|cleared (normal operation)||||||||
|||||||||||||1: Executes software reset.|||||||||
|||||||||||||When SWRST is|set to|1, all the register values are reset to the initial|||||||
|||||||||||||values. (SWRST|is not reset to the initial value)||||||||
|30|to|16|―|||All||0||R||Reserved|||||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|15|to|0|VERSION|||H'0003||||R||Version Information|||||||||
||||[15:0]|||||||||Indicates the version number of this||||module.|||||

## 39.4 Interrupt Requests

Table 39.3 shows the interrupt request specifications of this module.

This module generates three types of interrupt requests: normal operation, error/timeout, and card detection. When an interrupt flag is set to 1 and also the corresponding interrupt is enabled, an interrupt request is asserted.

## **Table 39.3 Specifications of Interrupt Requests**

|**Flag Register**|**Bit**<br>**Mask Register**|**Bit**<br>**Interrupt Request**|
|---|---|---|
|CE_INT|CMD12DRE<br>CE_INT_EN<br>CMD12RBE<br>CMD12CRE<br>DTRANE<br>BUFRE<br>BUFWEN<br>BUFREN<br>RBSYE<br>CRSPE<br>CMDVIO<br>BUFVIO<br>WDATERR<br>RDATERR<br>RIDXERR<br>RSPERR<br>CRCSTO<br>WDATTO<br>RDATTO<br>RBSYTO<br>RSPTO|MCMD12DRE<br>Normal operation<br>interrupt<br>(MMC2)<br>MCMD12RBE<br>MCMD12CRE<br>MDTRANE<br>MBUFRE<br>MBUFWEN<br>MBUFREN<br>MRBSYE<br>MCRSPE|
|||MCMDVIO<br>Error/timeout interrupt<br>(MMC1)<br>MBUFVIO<br>MWDATERR<br>MRDATERR<br>MRIDXERR<br>MRSPERR<br>MCRCSTO<br>MWDATTO<br>MRDATTO<br>MRBSYTO<br>MRSPTO|
|CE_DETECT|CDRISE<br>CE_DETECT<br>CDFALL|MCDRISE<br>Card detection interrupt<br>(MMC0)<br>MCDFALL|

## 39.5 DMA Specifications

This module provides two channels for DMA transfer requests: one for buffer reading and the other for buffer writing.

## 39.5.1 DMA for Buffer Writing

The DMA transfer request is asserted for buffer writing when the buffer has become empty while the DMAWEN bit in CE_BUF_ACC is 1.

The DMA transfer request stays asserted for the amount of data specified by BLKSIZ (the block size set in CE_BLOCK_SET)  BLKCNT (the number of blocks for transfer set in CE_BLOCK_SET), and negated after the last block has been transferred. Note that the BUFWEN bit in CE_INT will not be asserted in this case.

If an error occurs during DMA transfer or DMA transfer is forcibly terminated, the command sequence is stopped automatically, which causes the DMA transfer request to be negated.

## 39.5.2 DMA for Buffer Reading

The DMA transfer request is asserted for buffer reading when the buffer stores data of the block size specified in CE_BLOCK_SET while the DMAREN bit in CE_BUF_ACC is 1.

The DMA transfer request stays asserted for the amount of data specified by BLKSIZ (the block size set in CE_BLOCK_SET)  BLKCNT (the number of blocks for transfer set in CE_BLOCK_SET), and negated after the last block has been transferred. Note that the BUFREN bit in CE_INT will not be asserted in this case.

If an error occurs during DMA transfer or DMA transfer is forcibly terminated, the command sequence is stopped automatically, which causes the DMA transfer request to be negated.

## 39.6 Operation

## 39.6.1 Command/Response Formats

Figure 39.2 shows the format of the command to be transferred. The command index that is set in CMD[5:0] of CE_CMD_SET and the argument set in ARG[31:0] of CE_ARG are reflected in the command.

**==> picture [384 x 53] intentionally omitted <==**

**----- Start of picture text -----**<br>
S: Start bit, T: Transmission bit, E: End bit<br>Bit:  47  46  45:40  39:8  7:1 0<br>MMC_CMD S T Index Argument CRC7 E<br>Transmit the value of CMD[5:0] in CE_CMD_SET Transmit the value of ARG[31:0] in CE_ARG<br>**----- End of picture text -----**<br>

## **Figure 39.2 Command Format**

Figure 39.3 and Figure 39.4 show the formats when a 6-byte response and 17-byte response (R2) are received, respectively. The response index is stored in RSPIDX[5:0] of CE_HOST_STS1, and the status value of the response is stored to CE_RESP0 or CE_RESP3 to CE_RESP0.

**==> picture [483 x 194] intentionally omitted <==**

**----- Start of picture text -----**<br>
S: Start bit, T: Transmission bit, E: End bit<br>Bit: 47 46 45:40 39:8 7:1 0<br>MMC_CMD S T E<br>Set the items to be checked by RIDXC in CE_CMD_SET. Store receive data to  Set the items to be checked<br>RSP[31:0] in CE_RESP0. by RCRC7C in CE_CMD_SET.<br>Figure 39.3 Format of 6-Byte Response<br>S: Start bit, T: Transmission bit, E: End bit<br>Bit: 135 134 133:128 127:8 7:1 0<br>MMC_CMD S T E<br>Set the items to be checked by RIDXC in CE_CMD_SET. Store receive data to<br>RSP[127:0] in CE_RESP3 to CE_RESP0. Set the items to be checked<br>by RCRC7C in CE_CMD_SET<br>**----- End of picture text -----**<br>

**Figure 39.4 Format of 17-Byte Response (R2)**

## 39.6.2 Data Block Format

Figure 39.5 shows the format of data blocks. For details on D0 to D3 in Figure 39.5 , see section 39.6.3, Buffer Structure and Buffer Accesses . When data is written to a card, data stored in the buffer is transmitted. When data is read from a card, receive data is stored to the buffer.

|MMC_CLK<br>MMC_D[3]<br>MMC_D[2]<br>MMC_D[1]<br>MMC_D[0]<br>MMC_CLK<br>MMC_D[7]<br>MMC_D[6]<br>MMC_D[5]<br>MMC_D[4]<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>MMC_D[3]<br>MMC_D[2]<br>MMC_D[1]<br>MMC_D[0]<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>MMC_D[0]<br>~~S~~<br>MMC_CLK<br>~~S~~|MMC_CLK<br>MMC_D[3]<br>MMC_D[2]<br>MMC_D[1]<br>MMC_D[0]<br>MMC_CLK<br>MMC_D[7]<br>MMC_D[6]<br>MMC_D[5]<br>MMC_D[4]<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>MMC_D[3]<br>MMC_D[2]<br>MMC_D[1]<br>MMC_D[0]<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>MMC_D[0]<br>~~S~~<br>MMC_CLK<br>~~S~~|MMC_CLK<br>MMC_D[3]<br>MMC_D[2]<br>MMC_D[1]<br>MMC_D[0]<br>MMC_CLK<br>MMC_D[7]<br>MMC_D[6]<br>MMC_D[5]<br>MMC_D[4]<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>MMC_D[3]<br>MMC_D[2]<br>MMC_D[1]<br>MMC_D[0]<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>~~S~~<br>MMC_D[0]<br>~~S~~<br>MMC_CLK<br>~~S~~||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||~~S~~|~~b7~~|~~b6~~||~~b0~~||~~b0~~|||||~~E~~|
||||||~~...~~||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
||||D0<br>D1<br>Data<br>(a) 1-bit mode|||||||||||
|||~~S~~|~~b7~~|~~b3~~|~~b7~~|~~b3~~||~~b3~~|||||~~E~~|
||~~S~~<br>||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b6~~|~~b2~~|~~b6~~|~~b2~~||~~b2~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b5~~|~~b1~~|~~b5~~|~~b1~~||~~b1~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b4~~|~~b0~~|~~b4~~|||~~b0~~|||||~~E~~|
|||||||~~b0~~|~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
||||Data<br>D0<br>D1<br>D2<br>D3<br>(b) 4-bit mode|||||||||||
|||~~S~~|~~b7~~|~~b7~~|~~b7~~|~~b7~~||~~b7~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b6~~|~~b6~~|~~b6~~|~~b6~~||~~b6~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b5~~|~~b5~~|~~b5~~|~~b5~~||~~b5~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b4~~|~~b4~~|~~b4~~|~~b4~~||~~b4~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b3~~|~~b3~~|~~b3~~|~~b3~~||~~b3~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b2~~|~~b2~~|~~b2~~|~~b2~~||~~b2~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b1~~|~~b1~~|~~b1~~|~~b1~~||~~b1~~|||||~~E~~|
||~~S~~||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
|||~~S~~|~~b0~~|~~b0~~|~~b0~~|~~b0~~||~~b0~~|||||~~E~~|
||||||||~~...~~||~~crc~~|~~...~~|~~crc~~|~~crc~~||
||||Data<br>(c) 8-bit mode|||||||||||

**Figure 39.5 Data Block Format**

## 39.6.3 Buffer Structure and Buffer Accesses

This module has two units of 512-byte RAM as shown in Figure 39.6 . Therefore, for multi-block writing, if one block of data (512 bytes) stored in one buffer has been transmitted but the other buffer is full, the next block of data can be continuously transmitted. For multi-block reading, if one block of receive data (512 bytes) has been stored in one buffer but the other buffer is empty, the next block of receive data can be continuously stored in the buffer.

If neither of the buffers is empty for multi-block reading, the MMC clock is stopped and reception is suspended. When one of the buffers becomes empty, the MMC clock supply is started to start reception.

The buffer is accessed with CE_DATA. CE_DATA should be accessed for 4  (n + 1) bytes (n = 0, 1, 2, 3, …, 127).

**==> picture [196 x 185] intentionally omitted <==**

**----- Start of picture text -----**<br>
31 24 23 16 15 8 7 0<br>h'34:CE_DATA D0 D1 D2 D3<br>31 24 23 16 15 8 7 0<br>Buffer D0 D4 D1 D5 D2 D6 D3 D7<br>D4 D8 D5 D9 D6 D10 D7 D11<br>D8 D12 D9 D13 D10 D14 D11 D15<br>D12 D16 D13 D17 D14 D18 D15 D19<br>D16 D24 D17 D21 D18 D22 D19 D23<br>D20 D24 D21 D25 D22 D26 D23 D27<br>D24 D104 D25 D105 D26 D106 D27 D107<br>D104D108 D489D109 D106 D110 D491 D111<br>D492D112 D493D113 D494 D114 D495 D115<br>D496D116 D497D117 D498 D118 D499 D119<br>D500D120 D501D121 D502 D122 D503 D123<br>D504D124 D505D125 D506 D126 D507 D127<br>D508 D509 D510 D511<br>Buffer B<br>Buffer A<br>128 words<br>**----- End of picture text -----**<br>

**Figure 39.6 Double Buffer Structure**

The buffer access select function allows byte-wise swapping of data when the buffer is accessed by writing to or reading from CE_DATA. This function is enabled by the setting of CE_BUFF_ACC. Figure 39.7 shows the specification of byte-wise swapping.

**==> picture [427 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
[With the default setting] [Swap in byte units]<br>Read from CE_DATA: Read from CE_DATA:<br>31 24 23 16 15 8 7 0 31 24 23 16 15 8 7 0<br>h'34:CE_DATA D0 D1 D2 D3 h'34:CE_DATA D3 D2 D1 D0<br>31 24 23 16 15 8 7 0 31 24 23 16 15 8 7 0<br>Buffer D0 D1 D2 D3 Buffer D0 D1 D2 D3<br>Write to CE_DATA: Write to CE_DATA:<br>31 24 23 16 15 8 7 0 31 24 23 16 15 8 7 0<br>h'34:CE_DATA D0 D1 D2 D3 h'34:CE_DATA D3 D2 D1 D0<br>31 24 23 16 15 8 7 0 31 24 23 16 15 8<br>Buffer D0 D1 D2 D3 Buffer D0 D1 D2 D3<br>**----- End of picture text -----**<br>

**Figure 39.7 Specification of Byte-Wise Swapping**

## 39.6.4 Automatic CMD12 Issuance

This module automatically issues CMD12 when multi-block transfer is performed with the CMD12EN bit in CE_CMD_SET set to 1.

Figure 39.8 shows the timing of automatic CMD12 issuance in multi-block read. CMD12 is issued such that the end bit of the command is sent two bits before the end bit of the data during reception of the last block.

**==> picture [462 x 77] intentionally omitted <==**

**----- Start of picture text -----**<br>
S T S T<br>INDEX ARG<br>CRC<br>Automatically issued<br>CMD12 Response to CMD12<br>MMC_CLK<br>MMC_CMD 5 4 8 7 6 5 4 3 1 0 E<br>2 bits before<br>MMC_D[0] 35 34 33 32 31 30 29 1 0 15 14 13 12 3 2 1 0 E<br>Last block of the read data<br>CRC<br>**----- End of picture text -----**<br>

**Figure 39.8 Timing of Automatically-Issued CMD12 in Multi-Block Read (1-Bit Mode)**

Figure 39.9 shows the timing of automatic CMD12 issuance in multi-block write. CMD12 is issued after the data busy after transmission of the last block has ended.

**==> picture [458 x 79] intentionally omitted <==**

**----- Start of picture text -----**<br>
MMC_CLK<br>MMC_CMD S T INDEX5 4<br>MMC_D[0] 0 CRC15 14 1 0 E CRCstatusS 0 1 0 E Data busy<br>Last block of the write data<br>Automatically issued<br>CMD12<br>**----- End of picture text -----**<br>

**Figure 39.9 Timing of Automatically-Issued CMD12 in Multi-Block Write (1-Bit Mode)**

The argument of the automatically-issued CMD12 is set by CE_ARG_CMD12. The value of [39:8] of the response to CMD12 is stored to CE_RESP_CMD12. The busy status on response reception is received.

## 39.6.5 High Priority Interrupt (HPI)

HPI should be executed as described below with reference to section 39.3, Register Descriptions and section 39.7, Examples of Setting .

## (1) When HPI is executed during a write to the device

- (a) Terminate the command sequence forcibly.

- (b) Wait for the CMDSEQ bit in CE_HOST_STS1 to be cleared to 0.

- (c) Issue CMD12 (R1) to make the device in the rcv state enter the prg state. Note that the device does not output the response when the device is in the prg state before issuance of CMD12(R1).

- (d) Issue CMD13 (R1).

- (e) Issue the HPI command.

## (2) When HPI is executed during response busy while not writing to the device

- (a) Terminate the command sequence forcibly.

- (b) Wait for the CMDSEQ bit in CE_HOST_STS1 to be cleared to 0.

- (c) Issue CMD13 (R1).

- (d) Issue the HPI command*.

The procedure above is for HPI generated in the CMD6, CMD24, CMD25 (Pre-defined), or CMD38 sequence.

Note: * CMD12 (R1b) or CMD13 (R1b) depending on the device connected

## 39.6.6 Background Operation

Background operation should be executed as described below with reference to section 39.3, Register Descriptions and section 39.7, Examples of Setting .

To execute background operation, issue CMD6 (R1) to write to the BKOPS_START byte in the EXT_CSD register of the device.

Completion of background operation can be determined by checking the device state with CMD13 (R1) issued after CMD6 (R1) or by polling MMCDAT[0]. When the device state is indicated as “tran” or MMCDAT[0] is high, background operation is determined to be completed.

To suspend background operation, use HPI described in section 39.6.5 .

## 39.6.7 Operation in the Case of Error/Timeout

This module may not be stopped in case of error occurrence. If the command sequence is in progress when an error occurs (check the CMDSEQ bit in CE_HOST_STS1), terminate the sequence forcibly and perform a software reset. The data for transmission or received data that had been stored in the buffers at the time of error occurrence are not guaranteed.

This module is not stopped when a timeout has occurred. To execute the next command after a timeout error has occurred, terminate the sequence forcibly, perform a software reset.

For forcible termination, refer to section 39.7.11, Forcible Termination .

## 39.7 Examples of Setting

This section shows the procedures for executing typical command sequences.

## 39.7.1 Legends

Figure 39.10 shows the legends for the symbols used in the figures in the following subsections.

**==> picture [414 x 129] intentionally omitted <==**

**----- Start of picture text -----**<br>
Flowchart and register setting Interrupt and buffer states State of MMC_CMD and MMC_D lines<br>INT CPU BUF HOST CARD HOST CARD<br>: Initial state (MMC_ CMD) (MMC _D)<br>INT : Interrupt BUF:W : Buffer write CMD:S : Transmit command DAT:S : Transmit data<br>: Register access<br>BUF:R : Buffer read RSP:R : Receive response CRCST:R : Receive CRC status<br>: Waiting for certain  BUSY:R : Receive busy<br>  processing to end<br>DAT:R : Receive data<br>: Conditional branch<br>**----- End of picture text -----**<br>

**Figure 39.10 Legends for the Symbols Used in the Figures**

## 39.7.2 Command Transmission

**==> picture [377 x 248] intentionally omitted <==**

**----- Start of picture text -----**<br>
INT CPU BUF HOST CARD HOST CARD<br>(MMC_ (MMC<br>Start CMD) _D)<br>Write(CE_INT , H'0000_0000);<br>Settings prior<br>to command  Write(CE_CLK_CTRL , H'0100_0000);<br>transmission<br>Write(CE_INT_EN , H'0001_CF3F);<br>Settings for Write(CE_ARG , H'****_****);<br>command<br>transmission Write(CE_CMD_SET , H'0000_0000);<br>Waiting for command response  CE_HOST_STS1:CMDSEQ = 1 CMD:S<br>complete flag<br>INT<br>Flag Read(CE_INT);<br>check  Write(CE_INT , H'FFFE_FFFF);<br>Idle<br>**----- End of picture text -----**<br>

**Figure 39.11 Command Transmission (CMD0)**

## 39.7.3 Command Transmission → Response Reception

**==> picture [421 x 290] intentionally omitted <==**

**----- Start of picture text -----**<br>
INT CPU BUF HOST CARD HOST CARD<br>(MMC (MMC<br>Start _CMD) _D)<br>Write(CE_INT , H'0000_0000);<br>Settings prior<br>to command  Write(CE_CLK_CTRL , H'0100_0000);<br>transmission<br>Write(CE_INT_EN , H'0001_CF3F);<br>Settings for Write(CE_ARG , H****_****);<br>command<br>transmission Write(CE_CMD_SET , H'0D40_0000);<br>Waiting for  CE_HOST_STS1: CMD:S<br>command  CMDSEQ = 1<br>response<br>complete flag<br>RSP:R<br>INT<br>Flag Read(CE_INT);<br>check Write(CE_INT , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Error/timeout<br>processing<br>Idle<br>**----- End of picture text -----**<br>

**Figure 39.12 Command Transmission**  **Response Reception (CMD13)**

## 39.7.4 Command Transmission → Response Reception (with Response Busy)

- (1) When the busy time period is less than the period set by SRBSYTO in CE_CLK_CTRL

**==> picture [401 x 404] intentionally omitted <==**

**----- Start of picture text -----**<br>
INT CPU BUF HOST CARD HOST CARD<br>(MMC (MMC<br>Start _CMD) _D)<br>Write(CE_INT , H'0000_0000);<br>Settings priorto command  Write(CE_CLK_CTRL , H'0100_0*00);<br>transmission<br>Write(CE_INT_EN , H'0001_CF3F);<br>Settings for Write(CE_ARG , H'****_****);<br>command<br>transmission Write(CE_CMD_SET , H'0660_0000);<br>Waiting for  CE_HOST_STS1: CMD:S<br>command  CMDSEQ = 1<br>response<br>complete flag RSP:R BUSY:R<br>INT<br>Flag Read(CE_INT);<br>check  Write(CE_INT , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Enable setting Write(CE_INT_EN , H'0002_CF3F);<br>Waiting for<br>response<br>busy complete<br>flag<br>INT<br>Flag Read(CE_INT);<br>check  Write(CE_INT , H'FFFD_FFFF);<br>Error check<br>Error/timeout<br>processing Idle<br>**----- End of picture text -----**<br>

**Figure 39.13 Command Transmission → Response Reception (with Response Busy) (CMD6)**

- (2) When the busy time period may be equal to or beyond the period set by SRBSYTO in CE_CLK_CTRL

**==> picture [386 x 414] intentionally omitted <==**

**----- Start of picture text -----**<br>
INT CPU BUF HOST CARD HOST CARD<br>(MMC_ (MMC<br>Start CMD) _D)<br>Write(CE_INT , H'0000_0000);<br>Settings prior<br>to command  Write(CE_CLK_CTRL , H'0100_0F00);<br>transmission<br>Write(CE_INT_EN , H'0001_CF3F);<br>Settings for Write(CE_ARG , H'****_****);<br>command<br>transmission Write(CE_CMD_SET , H'2660_0000);<br>Set and start a timer in other modules<br>(because the timer in this module cannot be used<br>for check the busy time).<br>Waiting for command  CE_HOST_STS1:CMDSEQ = 1 CMD:S<br>response<br>complete flag RSP:R BUSY:R<br>INT<br>Flag Read(CE_INT);<br>check<br>Write(CE_INT , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Enable setting Write(CE_INT_EN , H'0002_CF3F);<br>Waiting for<br>response<br>busy complete<br>flag<br>INT<br>Flag Read(CE_INT);<br>check  Write(CE_INT , H'FFFD_FFFF);<br>Error Determination Response busy timeout flag only<br>Response busy<br>complete flag Forcible termination<br>only<br>Error/timeout<br>processing Idle Checking the end<br>of busy state by<br>CMD13.<br>Check is performed until the specified timer value is exceeded.<br>**----- End of picture text -----**<br>

**Figure 39.14 Command Transmission → Response Reception (with Response Busy) (CMD38)**

## 39.7.5 Single-Block Read

**==> picture [397 x 456] intentionally omitted <==**

**----- Start of picture text -----**<br>
INT CPU BUF HOST CARD HOST CARD<br>Start<br>(MMC (MMC<br>Write(CE_INT , H'0000_0000); _CMD) _D)<br>Write(CE_CLK_CTRL , H'0100_0000);<br>Settings priorto command  Write(CE_BUF_ACC , H'0000_0000);<br>transmission Write(CE_INT_EN , H'0001_CF3F);<br>Write(CE_BLOCK_SET , H'0000_0***);<br>Settings forcommand  Write(CE_ARG , H'****_****);<br>transmission Write(CE_CMD_SET , H'1148_0002);<br>CMD:S<br>Waiting for<br>command response  CE_HOST_STS1:CMDSEQ = 1 RSP:R<br>complete flag<br>INT<br>Flag Read(CE_INT);<br>check  Write(CE_INT , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Enable setting Write(CE_INT_EN , H'0050_CF3F);<br>Waiting for<br>buffer read  DAT:R<br>enable flag<br>INT<br>Flag Read(CE_INT);<br>check  Write(CE_INT , H'FFEF_FFFF);<br>Error check<br>Buffer read  Read(CE_DATA); BUF:R<br>(for the block size)<br>Waiting for<br>buffer read<br>complete flag<br>INT<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT , H'FFBF_FFFF);<br>Error check<br>Error/timeout Idle<br>processing<br>**----- End of picture text -----**<br>

**Figure 39.15 Single-Block Read (CMD17)**

## 39.7.6 Multi-Block Read

**==> picture [398 x 466] intentionally omitted <==**

**----- Start of picture text -----**<br>
INT CPU BUF HOST CARD HOST CARD<br>Start<br>Write(CE_INT , H'0000_0000); (MMC (MMC<br>Write(CE_CLK_CTRL , H'0100_0000); _CMD) _D)<br>Settings prior Write(CE_BUF_ACC , H'0000_0000);<br>to command transmission Write(CE_INT_EN , H'0001_CF3F);<br>Write(CE_BLOCK_SET , H'****_0200);<br>Settings forcommand  Write(CE_ARG , H'****_****);<br>transmission Write(CE_CMD_SET , H'124A_0002); CMD:S<br>Waiting for  CE_HOST_STS1:<br>command  CMDSEQ = 1 RSP:R<br>response<br>complete flag<br>INT<br>Flag Read(CE_INT);<br>check  Write(CE_INT , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Enable setting Write(CE_INT_EN , H'0050_CF3F);<br>buffer read Waiting for  DAT:R<br>enable flag<br>INT<br>Read(CE_INT);<br>Flag<br>check  Write(CE_INT , H'FFEF_FFFF);<br>Error check<br>Buffer read  Read(CE_DATA); BUF:R<br>(for the block size)<br>Final block read<br>complete<br>Waiting for<br>buffer read<br>complete flag<br>INT<br>Flag check  Read(CE_INT);<br>Write(CE_INT , H'FFBF_FFFF);<br>Error check<br>Error/timeout Idle<br>processing<br>**----- End of picture text -----**<br>

**Figure 39.16 Multi-Block Read (CMD18 Pre-Defined)**

## 39.7.7 Multi-Block Read (with Automatic CMD12 Issuance)

**==> picture [394 x 463] intentionally omitted <==**

**----- Start of picture text -----**<br>
INT CPU BUF HOST CARD HOST CARD<br>Start Write(CE_INT   , H'0000_0000); (MMC (MMC<br>_CMD) _D)<br>Write(CE_CLK_CTRL   , H'0100_0000);<br>Settings prior Write(CE_BUF_ACC   , H'0000_0000);<br>to command transmission Write(CE_INT_EN  , H'0001_CF3F);<br>Write(CE_BLOCK_SET  , H'****_0200);<br>Settings for Write(CE_ARG   , H'****_****);<br>command<br>transmission Write(CE_ARG_CMD12  , H'****_****);<br>Write(CE_CMD_SET   , H'124B_0002);<br>CMD:S<br>Waiting for<br>command  CE_HOST_STS1:<br>complete flagresponse  CMDSEQ = 1 RSP:R<br>INT<br>Read(CE_INT);<br>Flag<br>check  Write(CE_INT   , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Enable setting Write(CE_INT_EN   , H'0410_CF3F);<br>CMD12 is automatically issued<br>when the final block is transferred.<br>Waiting for<br>buffer read<br>enable flag CMD:S DAT:R<br>INT<br>Flag Read(CE_INT); RSP:R<br>check  Write(CE_INT , H'FFEF_FFFF);<br>Error check<br>Buffer read  Read(CE_DATA); BUF:R<br>(for the block size)<br>Final block read<br>complete<br>Waiting for complete flags<br>for automatically-issued<br>CMD12 and buffer read<br>INT<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT , H'F8BF_FFFF);<br>Error check<br>Response check Read(CE_RESP_CMD12);<br>Error/timeout<br>processing Idle<br>**----- End of picture text -----**<br>

**Figure 39.17 Multi-Block Read (with Automatic CMD12 Issuance) (CMD18 Open-Ended)**

## 39.7.8 Single-Block Write

**==> picture [384 x 452] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start INT CPU BUF HOST CARD HOST CARD<br>Write(CE_INT   , H'0000_0000); (MMC (MMC<br>Write(CE_CLK_CTRL   , H'0100_0000);  _CMD) _D)<br>Settings prior<br>to command  Write(CE_BUF_ACC   , H'0000_0000);<br>transmission<br>Write(CE_INT_EN   , H'0001_CF3F);<br>Write(CE_BLOCK_SET  , H'0000_0***);<br>Settings for<br>command  Write(CE_ARG   , H'****_****);<br>transmission<br>Write(CE_CMD_SET   , H'184C_0002); CMD:S<br>Waiting for<br>command  CE_HOST_STS1:<br>response  CMDSEQ = 1 RSP:R<br>complete flag<br>INT<br>Flag Read(CE_INT);<br>check  Write(CE_INT , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Enable setting Write(CE_INT_EN  , H'00A0_CF3F);<br>INT<br>Waiting for<br>buffer write<br>enable flag<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT , H'FFDF_FFFF);<br>(for the block size)Buffer write  Write(CE_DATA , H'****_****); BUF:W<br>DAT:S<br>CRCST:R<br>Waiting for<br>data transmission<br>complete flag<br>BUSY:R<br>INT<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT , H'FF7F_FFFF);<br>Error check<br>Error/timeout Idle<br>processing<br>**----- End of picture text -----**<br>

**Figure 39.18 Single-Block Write (CMD24)**

## 39.7.9 Multi-Block Write

**==> picture [384 x 464] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start INT CPU BUF HOST CARD HOST CARD<br>Write(CE_INT   , H'0000_0000); (MMC (MMC<br>Write(CE_CLK_CTRL   , H'0100_0000); _CMD) _D)<br>Settings priorto command  Write(CE_BUF_ACC   , H'0000_0000);<br>transmission Write(CE_INT_EN   , H''h0001_CF3F);<br>Write(CE_BLOCK_SET  , H'****_0200);<br>Settings forcommand  Write(CE_ARG   , H'****_****);<br>transmission Write(CE_CMD_SET   , H'194E_0002);<br>CMD:S<br>Waiting for  CE_HOST_STS1:<br>command  CMDSEQ = 1<br>response<br>complete flag RSP:R<br>INT<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Enable setting Write(CE_INT_EN  , H'00A0_CF3F);<br>Waiting for<br>buffer write<br>enable flag<br>INT<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT , H'FFDF_FFFF);<br>Error check<br>(for the block size)Buffer write  Write(CE_DATA , H'****_****); BUF:W DAT:S<br>CRCST:R<br>Final block write BUSY:R<br>complete<br>Waiting for<br>data transmission<br>complete flag<br>INT<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT , H'FF7F_FFFF);<br>Error check<br>Error/timeout Idle<br>processing<br>**----- End of picture text -----**<br>

**Figure 39.19 Multi-Block Write (CMD25 Pre-Defined)**

## 39.7.10 Multi-Block Write (with Automatic CMD12 Issuance)

**==> picture [394 x 470] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Write(CE_INT   , H'0000_0000); INT CPU BUF HOST CARD HOST CARD<br>Write(CE_CLK_CTRL   , H'0100_0000);<br>(MMC (MMC<br>Settings priorto command  Write(CE_BUF_ACC  Write(CE_INT_EN  , H'0001_CF3F);, H'0000_0000); _CMD) _D)<br>transmission Write(CE_BLOCK_SET  , H'****_0200);<br>Settings for Write(CE_ARG   , H'****_****);<br>command  Write(CE_ARG_CMD12  , H'****_****);<br>transmission<br>Write(CE_CMD_SET   , H'194F_0002);<br>CMD:S<br>Waiting for<br>command<br>complete flagresponse  CE_HOST_STS1:CMDSEQ = 1 RSP:R<br>INT<br>Flag check  Read(CE_INT);<br>Write(CE_INT   , H'FFFE_FFFF);<br>Error check<br>Response check Read(CE_RESP0);<br>Enable setting Write(CE_INT_EN   , H'0220_CF3F);<br>Waiting for<br>buffer write<br>enable flag<br>INT<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT   , H'FFDF_FFFF);<br>Error check<br>Buffer write  Write(CE_DATA   , H'****_****);<br>(for the block size) BUF:W<br>DAT:S<br>CRCST:R<br>Final block write<br>complete when the final block is transferred.CMD12 is automatically issued  BUSY:R<br>CMD:S<br>Waiting for<br>automatically-issued<br>busy complete flagCMD12 response  RSP:R BUSY:R<br>INT<br>Read(CE_INT);<br>Flag check<br>Write(CE_INT   , H'FC7F_FFFF);<br>Error check<br>Response check Read(CE_RESP_CMD12);<br>Error/timeout<br>processing Idle<br>**----- End of picture text -----**<br>

**Figure 39.20 Multi-Block Write (with Automatic CMD12 Issuance) (CMD25 Open-Ended)**

## 39.7.11 Forcible Termination

**==> picture [340 x 259] intentionally omitted <==**

**----- Start of picture text -----**<br>
INT CPU BUF HOST CARD HOST CARD<br>Command  (MMC (MMC<br>sequence inprogress _CMD) _D)<br>Enable setting Write(CE_INT_EN , H'0000_0000);<br>Settings for forcible  Write(CE_CMD_CTRL , H'0000_0001);<br>termination of<br>command sequence Write(CE_CMD_CTRL , H'0000_0000);<br>Check of command<br>sequence status Read(CE_HOST_STS1);<br>Termination check<br>Software reset Write(CE_VERSION , H'8000_0000);<br>execution Write(CE_VERSION , H'0000_0000);<br>Idle<br>**----- End of picture text -----**<br>

**Figure 39.21 Forcible Termination**

## 39.7.12 Setting Values of CE_CMD_SET

Table 39.4 lists the setting values required to issue commands.

## **Table 39.4 Setting Values of CE_CMD_SET**

|Command|Response|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|Remarks|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|CMD[5:0]|RTYP[1:0]|RBSY|-|WDAT|DWEN|CMLTE|CMD12EN|RIDXC[1:0]|RCRC7C[1:0]|-|CRC16C|-|CRCSTE|TBIT|OPDM|-|-|SBIT|-|DATW[1:0]||
|CMD0|-|0|0|000000|00|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD1|R3|0|0|000001|01|0|0|0|0|0|0|01|01|0|0|0|0|0|0|0|0|0|0|00||
|CMD2|R2|0|0|000010|10|0|0|0|0|0|0|01|10|0|0|0|0|0|0|0|0|0|0|00||
|CMD3|R1|0|0|000011|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD4|-|0|0|000100|00|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD5|R1b|0|0|000101|01|1|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD6|R1|0|0|000110|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00|Background<br>operation|
||R1b|0|0|000110|01|1|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD7|R1|0|0|000111|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
||R1b|0|0|000111|01|1|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD8|R1|0|0|001000|01|0|0|1|0|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**||
|CMD9|R2|0|0|001001|10|0|0|0|0|0|0|01|10|0|0|0|0|0|0|0|0|0|0|00||
|CMD10|R2|0|0|001010|10|0|0|0|0|0|0|01|10|0|0|0|0|0|0|0|0|0|0|00||
|CMD12|R1|0|0|001100|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
||R1b|0|0|001100|01|1|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD13|R1|0|0|001101|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
||R1b|0|0|001101|01|1|1|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD14|R1|0|0|001110|01|0|0|1|0|0|0|00|00|0|1|0|0|0|0|0|0|1|0|**||
|CMD15|-|0|0|001111|00|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD16|R1|0|0|010000|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD17|R1|0|0|010001|01|0|0|1|0|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**||
|CMD18|R1|0|0|010010|01|0|0|1|0|1|0|00|00|0|0|0|0|0|0|0|0|0|*|**|Pre-<br>defined|
||R1|0|0|010010|01|0|0|1|0|1|1|00|00|0|0|0|0|0|0|0|0|0|*|**|Open-<br>ended|
|CMD19|R1|0|0|010011|01|0|0|1|1|0|0|00|00|0|0|0|1|0|0|0|0|0|0|**||
|CMD23|R1|0|0|010111|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD24|R1|0|0|011000|01|0|0|1|1|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**||
|CMD25|R1|0|0|011001|01|0|0|1|1|1|0|00|00|0|0|0|0|0|0|0|0|0|*|**|Pre-<br>defined|
||R1|0|0|011001|01|0|0|1|1|1|1|00|00|0|0|0|0|0|0|0|0|0|*|**|Open-<br>ended|
|CMD26|R1|0|0|011010|01|0|0|1|1|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**||
|CMD27|R1|0|0|011011|01|0|0|1|1|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**||
|CMD28|R1b|0|0|011100|01|1|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD29|R1b|0|0|011101|01|1|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||

|Command|Response|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|CE_CMD_SET|Remarks|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|CMD[5:0]|RTYP[1:0]|RBSY|-|WDAT|DWEN|CMLTE|CMD12EN|RIDXC[1:0]|RCRC7C[1:0]|-|CRC16C|-|CRCSTE|TBIT|OPDM|-|-|SBIT|-|DATW[1:0]||
|CMD30|R1|0|0|011110|01|0|0|1|0|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**||
|CMD31|R1|0|0|011111|01|0|0|1|0|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**||
|CMD35|R1|0|0|100011|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD36|R1|0|0|100100|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD38|R1b|0|0|100110|01|1|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD39|R4|0|0|100111|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD40|R5|0|0|101000|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00|Send<br>CMD|
||R5|0|0|101000|01|0|0|0|0|0|0|00|00|0|0|0|0|1|1|0|0|0|0|00|Send<br>RSP|
|CMD42|R1|0|0|101010|01|0|0|1|1|0|0|00|00|0|0|0|0|0|0|0|0|0|0|**||
|CMD55|R1|0|0|110111|01|0|0|0|0|0|0|00|00|0|0|0|0|0|0|0|0|0|0|00||
|CMD56|R1|0|0|111000|01|0|0|1|0|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**|Read|
||R1|0|0|111000|01|0|0|1|1|0|0|00|00|0|0|0|0|0|0|0|0|0|*|**|Read|

Note: • This module does not support CMD11 and CMD20.

## 39.8 Usage Note

## 39.8.1 Card Detection

The CDRISE and CDFALL bits in CE_DETECT which are used for the card detection function do not have a chattering elimination function. The chattering elimination processing should be implemented by software.

## 39.8.2 Multi-Block Transfer

When HPI is executed, use pre-defined multi-block transfer.

## 39.8.3 Software Reset

For transitions to the software reset state by the SWRST bit in the CE_VERSION register, see section 42.3.6, Software Reset . However, where the procedure refers to the SRST bit, read this as the SWRST bit in the CE_VERSION register.
