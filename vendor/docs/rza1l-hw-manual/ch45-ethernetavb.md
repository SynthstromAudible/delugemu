# 45. EthernetAVB

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2331–2529. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This module is only incorporated in the RZ/A1LU.

## 45.1 Overview

The EthernetAVB incorporates an Ethernet controller (E-MAC) that conforms to the definition of the MAC (Media Access Control) layer for Ethernet in the IEEE 802.3 standard.

When connected with a physical-layer LSI chip (PHY-LSI) that complies with the standard, the E- MAC is able to transmit and receive Ethernet (IEEE 802.3) frames. The E-MAC has a single MAC layer interface.

The EthernetAVB has a dedicated direct memory access controller (AVB-DMAC) for transferring transmitted Ethernet frames to and received Ethernet frames from respective storage areas in the onchip RAM at high speed.

The AVB-DMAC is compliant with the following three standards formulated for IEEE 802.1BA: the IEEE 802.1AS timing and synchronization protocol, the IEEE 802.1Qav real-time transfer, and the IEEE 802.1Qat stream reservation protocol.

For the on-chip RAM, see section 40, On-Chip RAM .

## 45.1.1 Specifications (Functions)

Table 45.1 lists the specifications of the EthernetAVB module.

**Table 45.1 Specifications (Functions)**

|**Item**|**Description**|
|---|---|
|Protocol|Flow control conforming with the IEEE 802.3x standard|
|Data transmission and|Transmission and reception of Ethernet (IEEE 802.3) frames|
|reception||
|Transfer speed|Supports transfer at 10 and 100 Mbps|
|Mode|Full-duplex mode|
|Interface|Supports the IEEE 802.3 standard MII (Media Independent Interface)|
|Summary of the|An intelligent frame separation DMAC (AVB-DMAC) conforming with the following|
|EthernetAVB function|standards stipulated for IEEE 802.1BA:|
||IEEE 802.1AS (time synchronization protocol)|
||IEEE 802.1Qav (real-time transfer)|
||IEEE 1722 (AVTP presentation timestamp)|
||IEEE 802.1Qat is supported by software.|
||Descriptor management system|
||Identification and sorting of frame data, and extraction and gathering of valid|
||video data|
||Controllable interrupt frequency (reducing the load on the CPU)|

## 45.1.2 Block Diagram

Figure 45.1 is a block diagram of the EthernetAVB.

**==> picture [381 x 308] intentionally omitted <==**

**----- Start of picture text -----**<br>
North main bus<br>EthernetAVB<br>AVB-DMAC<br>AXI-Bus controller<br>gPTP<br>timer<br>Receive  Reception control  Transmission  Transmit<br>FIFO unit control unit FIFO<br>E-MAC<br>MII interface<br>**----- End of picture text -----**<br>

**Figure 45.1 Block Diagram of EthernetAVB**

## 45.1.3 I/O Pins

Table 45.2 lists the pins for use by EthernetAVB.

**Table 45.2 Pin Configuration**

|Pin Name|I/O|Function|
|---|---|---|
|ET_TXD[3:0]|O|Transmit data signal|
|ET_TXEN|O|Transmit data enable signal|
|ET_RXD[3:0]|I|Receive data signal|
|ET_RXDV|I|Receive data enable signal|
|ET_TXCLK|I|Transmit clock signal|
|ET_RXCLK|I|Receive clock signal|
|ET_TXER|O|Transmit error signal|
|ET_RXER|I|Reception error signal|
|ET_MDC|O|Management information transfer clock signal|
|ET_MDIO|I/O|Management information transmit/receive data|
|ET_CRS|I|Carrier detection signal|
|ET_COL|I|Collision detection signal|
|AVB_CAPTURE|I|Signal for capturing AVTP presentation times|
|AVB_GPTP_|I|External clock signal for gPTP timer|
|EXTERN|||

## 45.2 Register Descriptions

Table 45.3 and Table 45.4 list the EthernetAVB related registers and their configurations.

**Table 45.3 Configuration of AVB-DMAC-related Registers (1/2)**

|**Register Name**|**Symbol**|**Address**|**Access size**|
|---|---|---|---|
|AVB-DMAC mode register|CCC|H’E821 5000|32|
|Descriptor base address table register|DBAT|H’E821 5004|32|
|Descriptor base address load request register|DLR|H’E821 5008|32|
|AVB-DMAC status register|CSR|H’E821 500C|32|
|Current descriptor address register q|CDARq|H’E821 5010+q*4|32|
|(q = 0 to 21)||||
|Error status register|ESR|H’E821 5088|32|
|Receive configuration register|RCR|H’E821 5090|32|
|Receive queue configuration register i (i = 0 to 4)|RQCi|H’E821 5094+i*4|32|
|Receive padding configuration register|RPC|H’E821 50B0|32|
|Unread frame counter stop level register|UFCS|H’E821 50C0|32|
|Unread frame counter register i (i = 0 to 4)|UFCVi|H’E821 50C4+i*4|32|
|Unread frame counter decrement register i|UFCDi|H’E821 50E0+i*4|32|
|(i = 0 to 4)||||
|Separation filter offset register|SFO|H’E821 50FC|32|
|Separation filter pattern register i (i = 0 to 31)|SFPi|H’E821 5100+i*4|32|
|Separation filter mask register i (i = 0, 1)|SFMi|H’E821 51C0+i*4|32|
|Transmit configuration register|TGC|H’E821 5300|32|
|Transmit configuration control register|TCCR|H’E821 5304|32|
|Transmit status register|TSR|H’E821 5308|32|
|Time stamp FIFO access register 0|TFA0|H’E821 5310|32|
|Time stamp FIFO access register 1|TFA1|H’E821 5314|32|
|Time stamp FIFO access register 2|TFA2|H’E821 5318|32|
|CBS increment value register c (c= 0, 1)|CIVRc|H’E821 5320+c*4|32|
|CBS decrement value register c (c = 0, 1)|CDVRc|H’E821 5328+c*4|32|
|CBS upper limit register c (c = 0, 1)|CULc|H’E821 5330+c*4|32|
|CBS lower limit register c (c = 0, 1)|CLLc|H’E821 5338+c*4|32|
|Descriptor interrupt control register|DIC|H’E821 5350|32|
|Descriptor interrupt status register|DIS|H’E821 5354|32|
|Error interrupt control register|EIC|H’E821 5358|32|
|Error interrupt status register|EIS|H’E821 535C|32|
|Receive interrupt control register 0|RIC0|H’E821 5360|32|
|Receive interrupt status register 0|RIS0|H’E821 5364|32|
|Receive interrupt control register 1|RIC1|H’E821 5368|32|
|Receive interrupt status register 1|RIS1|H’E821 536C|32|
|Receive interrupt control register 2|RIC2|H’E821 5370|32|
|Receive interrupt status register 2|RIS2|H’E821 5374|32|
|Transmit interrupt control register|TIC|H’E821 5378|32|
|Transmit interrupt status register|TIS|H’E821 537C|32|
|Interrupt summary status register|ISS|H’E821 5380|32|
|gPTP configuration control register|GCCR|H’E821 5390|32|
|gPTP maximum transit time register|GMTT|H’E821 5394|32|

**Table 45.3 Configuration of AVB-DMAC-related Registers (2/2)**

|**Register Name**|**Symbol**|**Address**|**Access size**|
|---|---|---|---|
|gPTP presentation time comparison register|GPTC|H’E821 5398|32|
|gPTP timer increment register|GTI|H’E821 539C|32|
|gPTP timer offset configuration register i (i = 0 to 2)|GTOi|H’E821 53A0+i*4|32|
|gPTP interrupt control register|GIC|H’E821 53AC|32|
|gPTP interrupt status register|GIS|H’E821 53B0|32|
|gPTP presentation time capture register|GCPT|H’E821 53B4|32|
|gPTP timer capture register i (i = 0 to 2)|GCTi|H’E821 53B8+i*4|32|
|gPTP capture event control register|GCEC|H'E821 53D8|32|

**Table 45.4 Configuration of E-MAC-related Registers**

|**Register Name**|**Symbol**|**Address**|**Access size**|
|---|---|---|---|
|E-MAC mode register|ECMR|H’E821 5500|32|
|Receive frame length register|RFLR|H’E821 5508|32|
|E-MAC status register|ECSR|H’E821 5510|32|
|E-MAC interrupt permission register|ECSIPR|H’E821 5518|32|
|PHY interface register|PIR|H’E821 5520|32|
|Automatic PAUSE frame register|APR|H’E821 5554|32|
|Manual PAUSE frame register|MPR|H’E821 5558|32|
|PAUSE frame transmit counter|PFTCR|H’E821 555C|32|
|PAUSE frame receive counter|PFRCR|H’E821 5560|32|
|Automatic PAUSE frame retransmission count|TPAUSER|H’E821 5564|32|
|register||||
|MAC address high register|MAHR|H’E821 55C0|32|
|MAC address low register|MALR|H’E821 55C8|32|
|CRC error frame receive counter register|CEFCR|H’E821 5740|32|
|Frame receive error counter register|FRECR|H’E821 5748|32|
|Too-short frame receive counter register|TSFRCR|H’E821 5750|32|
|Too-long frame receive counter register|TLFRCR|H’E821 5758|32|
|Residual-bit frame receive counter register|RFCR|H’E821 5760|32|
|Multicast address frame receive counter register|MAFCR|H’E821 5778|32|

## 45.2.1 AVB-DMAC Mode Register (CCC)

The CCC register specifies the operating mode of the AVB-DMAC.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|FCE|LBME|—|—|—|BOC|—|—|CSEL[1:0]||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|R|R|R|R/W|R|R|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|DTSR|—|—|—|—|—|—|OPC[1:0]||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R/W|R|R|R|R|R|R|R/W|R/W|

## **Table 45.5 CCC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b26|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b25|FCE|Flow Control Enable|
|||0: Normal operation|
|||1: Flow control is enabled.|
|b24|LBME|Loopback Mode Enable|
|||0: Normal operation|
|||1: Loopback mode is enabled.|
|b23 to b21|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b20|BOC|First Byte Specification|
|||0: The first byte is the 8 lower-order bits (on-chip RAM[7:0])|
|||1: The first byte is the 8 higher-order bits (on-chip RAM[31:24])|
|b19, b18|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b17, b16|CSEL[1:0]|gPTP Clock Select|
|||B’00: gPTP is not in use.|
|||B’01: Internal bus clock (B|
|||B’10: Ethernet transmission clock (ET_TXCLK)|
|||B’11: External clock (AVB_GPTP_EXTERN)|
|b15 to b9|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b8|DTSR|Data Transfer Suspend Request|
|||0: Normal operation|
|||1: Requests suspension.|
|b7 to b2|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b1, b0|OPC[1:0]|Operating Mode Configuration|
|||B’00: Reset mode|
|||B’01: Configuration mode|
|||B’10: Operation mode|
|||B’11: Standby mode|

## FCE (Flow Control Enable) Bit

This bit enables flow control by the E-MAC.

Writing to this bit is only possible when the current operating mode is configuration mode.

## LBME (Loopback Mode Enable) Bit

This bit enables loopback mode.

In loopback mode, the transmission lines are internally connected to the reception lines. When loopback mode is to be used, the Ethernet transmission clock must be supplied to the MII interface. A received clock signal is not required. Writing to this bit is only possible when the current operating mode is configuration mode.

## CAUTION

Data for transmission are still output normally. To eliminate effects on external modules, pin control should be applied to block the output of data. For pin control, see section 41., Ports.

## BOC (First Byte Specification) Bit

Specifies the allocation of the first byte from a received Ethernet frame to the on-chip RAM.

This configuration setting does not affect the format and filter parameters of the descriptor in the onchip RAM.

Writing to this bit is only possible when the current operating mode is configuration mode.

Figure 45.2 to Figure 45.4 show how data from frames received via the Ethernet connection are stored in the on-chip RAM.

|||||||||||||||||||||||||||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||Ethernet frame<br>on the bus||||||||||||||||||||||||||||||||||Frame Check<br>Sequence|||||||
|||||Preamble|||Frame<br>Delimiter|||Destination Address||||||||||||Source Address<br>...||||||||||Payload|||Frame Check<br>Sequence|||||||
|||||||||||Byte0||Byte1||Byte2||Byte3||Byte4||Byte5||Byte6||Byte7||Byte8||Byte9||...||ByteN<br>||||||||||
|||||||||||||||||||||||||||||||||||||||||||
|||||||||||Frame data stored in on-chip RAM||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||
|||||**Figure 45.2**||||||**Data for Reception in an Ethernet Frame**||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||Byte0<br>Byte4<br>Byte8<br>0<br>1<br>2<br>3<br>4<br>5<br>6|||||||
||Bit|31||30|29|28||27|26|25|24||23|22|21||20|19|18||17|16|15||14|13|12||11|10|9||8|7|6|5|4|3|2|1|0|
||DPTR+0|||Byte3|||||||||Byte2||||||||||Byte1||||||||||||Byte0|||||||
||DPTR+4|||Byte7|||||||||Byte6||||||||||Byte5||||||||||||Byte4|||||||
||DPTR+8|||Byte11|||||||||Byte10||||||||||Byte9||||||||||||Byte8|||||||
|||||||||||||||||||||||||||||||||||||||||||

## **Figure 45.3 When CCC.BOC = 0**

**==> picture [464 x 40] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>DPTR+0 Byte0 Byte1 Byte2 Byte3<br>DPTR+4 Byte4 Byte5 Byte6 Byte7<br>DPTR+8 Byte8 Byte9 Byte10 Byte11<br>**----- End of picture text -----**<br>

**Figure 45.4 When CCC.BOC = 1**

## CSEL[1:0] (gPTP Clock Select) Bits

These bits select the clock source for the gPTP timer.

Writing to these bits is only possible when the current operating mode is configuration mode.

## DTSR (Data Transfer Suspend Request) Bit

This bit can suspend access to the on-chip RAM.

The access is suspended on completion of the transfer of the frame currently being transferred.

This function disables access to the on-chip RAM without affecting normal operation of the AVBDMAC. Use this bit when exclusive control over the contents of the on-chip RAM is necessary, for example, in checking its integrity.

Note that the transmission and reception queues are not processed while access is suspended.

Change neither the AVB-DMAC settings nor the mode from when this bit is set to 1 to complete suspension until when the data transfer suspend status bit (CSR.DTS) is set to 1.

## OPC[1:0] (Operating Mode Configuration) Bits

These bits specify the operating mode.

For the operating modes, see section 45.3.1.1, Operating Modes .

Writing to this bit is possible in any of the operating modes, but should not be done after the standby request has been issued to the EthernetAVB. For issuance of the standby request to the EthernetAVB, see section 42., Power-Down Modes .

## 45.2.2 Descriptor Base Address Table Register (DBAT)

The DBAT register is used to set the base address of the descriptor table.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||TA[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||TA[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.6 DBAT register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|TA[31:0]|Table Address|
|||Base address of the descriptor table in the on-chip RAM|

## CAUTION

The setting of this bit must be a multiple of four (i.e. b0 and b1 must be set to 0).

## TAL3[1:0] (Table Address) Bits

These bits specify the base address of the descriptor table in the on-chip RAM.

For the structure of this table, see section 45.3.3, Descriptors .

Writing to this bit is only possible when the current operating mode is configuration mode.

## 45.2.3 Descriptor Base Address Load Request Register (DLR)

The DLR register is used to issue a request to load the values from the current descriptor address register q (CDARq) for each queue to the descriptor base address table register (DBAT).

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|LBA21|LBA20|LBA19|LBA18|LBA17|LBA16|
|Initial value|0|0|0|0|0|0|0|0|0|0|1|1|1|1|1|1|
|R/W|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||LBA15|LBA14|LBA13|LBA12|LBA11|LBA10|LBA9|LBA8|LBA7|LBA6|LBA5|LBA4|LBA3|LBA2|LBA1|LBA0|
|Initial value|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.7 DLR register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to 22|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b21|LBA21|Base Address Load Request (Rx17: Stream 15)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b20|LBA20|Base Address Load Request (Rx16: Stream 14)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b19|LBA19|Base Address Load Request (Rx15: Stream 13)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b18|LBA18|Base Address Load Request (Rx14: Stream 12)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b17|LBA17|Base Address Load Request (Rx13: Stream 11)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b16|LBA16|Base Address Load Request (Rx12: Stream 10)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b15|LBA15|Base Address Load Request (Rx11: Stream 9)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b14|LBA14|Base Address Load Request (Rx10: Stream 8)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b13|LBA13|Base Address Load Request (Rx9: Stream 7)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|

**Table 45.7 DLR register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b12|LBA12|Base Address Load Request (Rx8: Stream 6)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b11|LBA11|Base Address Load Request (Rx7: Stream 5)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b10|LBA10|Base Address Load Request (Rx6: Stream 4)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b9|LBA9|Base Address Load Request (Rx5: Stream 3)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b8|LBA8|Base Address Load Request (Rx4: Stream 2)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b7|LBA7|Base Address Load Request (Rx3: Stream 1)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b6|LBA6|Base Address Load Request (Rx2: Stream 0)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b5|LBA5|Base Address Load Request (Rx1: Network Control)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b4|LBA4|Base Address Load Request (Rx0: Best Effort)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b3|LBA3|Base Address Load Request (Tx3: Stream Class A)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b2|LBA2|Base Address Load Request (Tx2: Stream Class B)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b1|LBA1|Base Address Load Request (Tx1: Network Control)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|
|b0|LBA0|Base Address Load Request (Tx0: Best Effort)|
|||0(R): No load request is issued.|
|||1(W): A request for loading the corresponding base address is issued.|
|||1(R): The given base address is being loaded.|

## LBAq (Base Address Load Request) Bits

Each bit is used to issue requests to load base addresses and to indicate that a base address is currently being loaded.

Setting a bit to 1 issues a request for loading the descriptor base address for the queue q (q = 0 to 21), to change the current descriptor address bit (CDARq.CDA) to DBAT.TA + 8*q.

If transfer is currently in progress, loading is executed on completion of transfer for the current frame.

Completion of loading leads to automatic setting of the corresponding bit to 0.

For the transmission queues, base address load requests are executed even while fetching is in progress (the transmit start request bit in the transmit configuration control register (TCCR.TSRQt) is 1). Therefore, be sure to check that fetching is not in progress before issuing a request.

Writing to a bit of this register is only possible when the current operating mode is configuration mode. Only 1 can be written to this bit.

## 45.2.4 AVB-DMAC Status Register (CSR)

The CSR register is used to indicate the operating mode in which the AVB-DMAC is running and the individual communications states.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|RPO|TPO3|TPO2|TPO1|TPO0|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|DTS|—|—|—|—||OPS[3:0]|||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 45.8 CSR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b21|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b20|RPO|Receive Process Status|
|||0: Reception completed.|
|||1: Reception is in progress.|
|b19|TPO3|Transmit Process Status 3 (Stream Class A)|
|||0: Transmission completed.|
|||1: Transmission is in progress.|
|b18|TPO2|Transmit Process Status 2 (Stream Class B)|
|||0: Transmission completed.|
|||1: Transmission is in progress.|
|b17|TPO1|Transmit Process Status 1 (Network Control)|
|||0: Transmission completed.|
|||1: Transmission is in progress.|
|b16|TPO0|Transmit Process Status 0 (Best Effort)|
|||0: Transmission completed.|
|||1: Transmission is in progress.|
|b16 to b9|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b8|DTS|Data Transfer Suspend Status|
|||0: Normal operation|
|||1: Transmission is suspended.|
|b7 to b4|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b3 to b0|OPS[3:0]|Operating Mode Status|
|||B’0001: Reset mode|
|||B’0010: Configuration mode|
|||B’0100: Operation mode|
|||B’1000: Standby mode|
|||Other settings are reserved.|

## RPO (Receive Process Status) Bit

This bit indicates whether a reception queue contains an unread received frame.

This bit being set to 1 indicates that a received frame is yet to be stored in the on-chip RAM.

- [Clearing conditions]

The current operating mode is not operation mode.

Received frames in the reception FIFO all being stored in the on-chip RAM.

- [Setting condition]

A received frame being stored in the reception FIFO (but not yet in the on-chip RAM)

## TPO3 (Transmit Process Status 3) Bit

This bit indicates whether a class A stream is being transmitted.

This bit being set to 1 indicates that the AVB-DMAC is fetching data for transmission from the on-chip RAM, or the E-MAC is transmitting data.

- [Clearing conditions]

The current operating mode is not operation mode.

Completion of transfer of all frames for transmission from the transmission FIFO (the transmit start request bit in the transmit configuration control register (TCCR.TSRQ3) is 0)

- [Setting condition]

Transmission being started (by writing 1 to the transmit start request bit in the transmit configuration control register (TCCR.TSRQ3))

## TPO2 (Transmit Process Status 2) Bit

This bit indicates whether a class B stream is being transmitted.

This bit being set to 1 indicates that the AVB-DMAC is fetching data for transmission from the on-chip RAM, or the E-MAC is transmitting data.

- [Clearing conditions]

The current operating mode is not operation mode.

Completion of transfer of all frames for transmission from the transmission FIFO (the transmit start request bit in the transmit configuration control register (TCCR.TSRQ2) is 0)

- [Setting condition]

   - Transmission being started (by writing 1 to the transmit start request bit in the transmit configuration control register (TCCR.TSRQ2))

## TPO1 (Transmit Process Status 1) Bit

This bit indicates whether a network control is being transmitted.

This bit being set to 1 indicates that the AVB-DMAC is fetching data for transmission from the on-chip RAM, or the E-MAC is transmitting data.

- [Clearing conditions]

The current operating mode is not operation mode.

   - Completion of transfer of all frames for transmission from the transmission FIFO (the transmit start request bit in the transmit configuration control register (TCCR.TSRQ1) is 0)

- [Setting condition]

Transmission being started (by writing 1 to the transmit start request bit in the transmit configuration control register (TCCR.TSRQ1))

## TPO0 (Transmit Process Status 0) Bit

This bit indicates whether a best effort is being transmitted.

This bit being set to 1 indicates that the AVB-DMAC is fetching data for transmission from the on-chip RAM, or the E-MAC is transmitting data.

- [Clearing conditions]

The current operating mode is not operation mode.

   - Completion of transfer of all frames for transmission from the transmission FIFO (the transmit start request bit in the transmit configuration control register (TCCR.TSRQ0) is 0)

- [Setting condition]

   - Transmission being started (by writing 1 to the transmit start request bit in the transmit configuration control register (TCCR.TSRQ0))

## DTS (Data Transfer Suspend Status) Bit

This bit indicates whether access to the on-chip RAM is enabled.

- [Clearing condition]

The current operating mode is not operation mode.

The data transfer suspend request bit in the AVB-DMAC mode register (CCC.DTSR) being 0.

- [Setting condition]

Access to the on-chip RAM not proceeding while the data transfer suspend request bit (CCC.DTSR) in the AVB-DMAC mode register (CCC) is 1 (if the on-chip RAM is being accessed, this bit is set to 1 on completion of access).

## OPS[3:0] (Operating Mode Status) Bits

These bits indicate the current operating mode.

For the operating modes, see section 45.3.1.1, Operating Modes .

## 45.2.5 Current Descriptor Address Register q (CDARq) (q = 0 to 21)

The CDARq register indicates the current descriptor address.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CDA[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||CDA[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 45.9 CDARq (q = 0 to 21) register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|CDA[31:0]|Current Descriptor Address|
|||The address of the current descriptors for the transmission queues|

## CDA[31:0] (Current Descriptor Address) Bits

CDAR0 to CDAR3 indicate the addresses of the current descriptors for the corresponding transmission queues while CDAR4 to CDAR21 indicate the addresses of the current descriptors for the corresponding reception queues.

If the operating mode is changed to operation mode, the contents of the register for the queue to be used are set in the descriptor base address table register (DBAT).

Also, when the descriptor base address load request register (DLR) issues a load request, the contents of the corresponding register are set in the descriptor base address table register (DBAT).

## Conditions for updating:

These bits are set to 0 when the operating mode is not operation mode.

This register is updated in response to processing of the descriptor for a queue.

## 45.2.6 Error Status Register (ESR)

The ESR register indicates the error status in the AVB-DMAC.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19||b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—||—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0||0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R||R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3||b2|b1|b0|
||—|—|—|EIL||ET[3:0]|||—|—|—|||EQN[4:0]||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0||0|0|1|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R||R|R|R|

## **Table 45.10 ESR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b13|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b12|EIL|Error Information Lost|
|||0: No error information lost.|
|||1: Error information lost.|
|b11 to b8|ET[3:0]|Error Type|
|||B’0000: Descriptor reading error from the on-chip RAM|
|||B’0001: Descriptor writing error to the on-chip RAM|
|||B’0010: Illegal descriptor reading error|
|||B’0100: Data/time stamp reading error from the on-chip RAM|
|||B’0101: Data/time stamp writing error to the on-chip RAM|
|||B’1001: Transmission frame size error|
|||B’1010: Transmission FIFO overflow error|
|b7 to b5|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b4 to b0|EQN[4:0]|Error Queue Number|
|||Error queue number.|

## EIL (Error Information Lost) Bit

This bit indicates that error information has been lost because a new error was detected when the previous error remained unprocessed.

## Conditions for updating:

This bit is set to 0 when the operating mode is not operation mode.

This bit is also set to 0 when 0 is written to the queue error interrupt status bit in the error interrupt status register (EIS.QEF).

This bit is set to 1 when the condition for setting the queue error interrupt status bit in the error interrupt status register (EIS.QEF) to 1 is satisfied when the queue error interrupt status bit in the error interrupt status register (EIS.QEF) is 1.

## ET[3:0] (Error Type) Bits

These bits indicate the detail of the error detected.

When the detected error is related to descriptor reading (ESR.ET = B’0000 or B’0010), the current descriptor address bits in the current descriptor address register q (CDARq.CDA) are not updated thus the same descriptor is processed again. To handle this, correct the descriptor **.**

When the detected error is related to descriptor writing (ESR.ET = B’0001), the current descriptor address bits in the current descriptor address register q (CDARq.CDA) and the transmit start request bit in the transmit configuration control register (TCCR.TSRQt) are updated as in the normal case thus the descriptor chain processing is not affected.

The other errors are temporary and might be eliminated by transfer continuation. For details, refer to section 45.3.2.3, Checking Integrity .

This bit should be referred to only when the queue error interrupt status bit in the error interrupt status register (EIS.QEF) is 1.

## Conditions for updating:

These bits are updated when the condition for setting the queue error interrupt status bit in the error interrupt status register (EIS.QEF) to 1 is satisfied when the queue error interrupt status bit in the error interrupt status register (EIS.QEF) is 0.

## EQN (Error Queue Number) Bits

These bits indicate the queue number in which the error has been detected. When ESR.EQN is 0 to 3, it means that the related queue is a transmission queue and the EQN value is the transmission queue number. When ESR.EQN is 4 or larger, it means that the related queue is a reception queue and the “ESR.EQN – 4” is the reception queue number r.

Refer to these bits only when the queue error interrupt status bit in the error interrupt status register (EIS.QEF) is 1.

## Conditions for updating:

These bits are updated when the condition for setting the queue error interrupt status bit in the error interrupt status register (EIS.QEF) to 1 is satisfied when the EIS.QEF bit is 0.

## 45.2.7 Receive Configuration Register (RCR)

The RCR register is used to make settings related to reception for the AVB-DMAC.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23||b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|||||||RFCL[12:0]||||||||
|Initial value|0|0|0|1|1|0|0|0|0||0|0|0|0|0|0|0|
|R/W|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7||b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—||—|ETS2|ETS0|ESF[1:0]||ENCF|EFFS|
|Initial value|0|0|0|0|0|0|0|0|0||0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R||R|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.11 RCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b29|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b28 to b16|RFCL[12:0]|Receive FIFO Caution Level|
|b15 to b6|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b5|ETS2|Time Stamp Enable (Stream)|
|||0: Time stamping is disabled.|
|||1: Time stamping is enabled.|
|b4|ETS0|Time Stamp Enable (Best Effort)|
|||0: Time stamping is disabled.|
|||1: Time stamping is enabled.|
|b3, b2|ESF[1:0]|Stream Filtering Select|
|||Settings for reception queues 2 to 17|
|||B’00: Filtering is disabled. Frames are processed in queue 0 (best effort).|
|||B’01: The filter for separating AVB stream frames from non-AVB stream|
|||frames is enabled; non-matching frames from the stream are processed|
|||in queue 0 (best effort).|
|||B’10: The filter for separating AVB stream frames from non-AVB stream|
|||frames is enabled; non-matching frames are discarded.|
|||B’11: The filter for separating AVB stream frames from non-AVB stream|
|||frames is enabled; non-matching frames from a stream are processed in|
|||queue 0 (best effort).|
|b1|ENCF|Network Control Filtering Enable|
|||Setting for reception queue 1 (network control)|
|||0: Network control is disabled.|
|||1: Network control is enabled.|
|b0|EFFS|Error Frame Enable|
|||0: Error frames are disabled.|
|||1: Error frames are enabled.|

## RFCL[12:0] (Receive FIFO Caution Level) Bits

These bits set the caution level for the reception FIFO and are used to maintain the priority order of the storage of received data and the fetching of data for transmission.

If the reception FIFO contains less data than this level, processing of both transmission and reception queues becomes pending.

If the reception FIFO contains more data than this level, only data in the reception queue are transferred, and processing of the transmission queue becomes pending.

Writing to this bit is only possible when the current operating mode is configuration mode.

## CAUTION

 In the case of this LSI chip, set these bits to H’1800.

## ETS2 (Time Stamp Enable (Stream)) Bit

Enables the inclusion of time-stamp information in reception queues 2 to 17.

The descriptor structure differs depending on whether time-stamp information is included or not. The reception queue in which time-stamp information is enabled uses the extended descriptor.

Writing to this bit is only possible when the current operating mode is configuration mode.

## ETS0 (Time Stamp Enable (Best Effort)) Bit

Enables the inclusion of time-stamp information in reception queue 0.

The descriptor structure differs depending on whether time-stamp information is included or not. The reception queue 0 in which time-stamp information is enabled uses the extended descriptor.

Writing to this bit is only possible when the current operating mode is configuration mode.

## ESF[1:0] (Stream Filtering Select) Bits

These bits select separation filtering for reception queues 2 to 17.

The queue-dependent separation filter can be used in combination with the identification of AVB stream frames.

When the value is B’00, filtering is disabled and frames from streams are processed in reception queue 0 (best effort).

When the value is B’01, the separation filter is enabled for both AVB stream frames and non-AVB stream frames; frames from non-matching streams are processed in reception queue 0 (best effort).

When the value is B’10, the separation filter is enabled for AVB stream frames; frames from nonmatching streams are discarded.

When the value is B’11, the separation filter is enabled for AVB stream frames; frames from nonmatching streams are processed in reception queue 0 (best effort).

For separation filtering, see 45.3.4.1 (1) Separation Filtering .

Writing to this bit is only possible when the current operating mode is configuration mode.

## ENCF (Enable Network Control Filtering) Bit

Enables the AVB network control frame for reception queue 1.

When reception queue 1 is disabled, a received frame is stored in reception queue 0 (best effort). Writing to this bit is only possible when the current operating mode is configuration mode.

## EFFS (Enable Error Frame) Bit

Enables or disables the reception of frames that have been classified as error frames by the E-MAC.

Received error frames are stored in reception queue 0 (best effort).

An indicator of error detection by the E-MAC during reception is stored in the descriptor (DESCR.MS).

Writing to this bit is only possible when the current operating mode is configuration mode.

## 45.2.8 Receive Queue Configuration Register i (RQCi) (i = 0 to 4)

The RQC0 register is used to set up reception queues 0 to 3.

The RQC1 register is used to set up reception queues 4 to 7. The RQC2 register is used to set up reception queues 8 to 11.

The RQC3 register is used to set up reception queues 12 to 15.

The RQC4 register is used to set up reception queues 16 to 17.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|UFCC3[1:0]||—|—|RSM3[1:0]||—|—|UFCC2[1:0]||—|—|RSM2[1:0]||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|UFCC1[1:0]||—|—|RSM1[1:0]||—|—|UFCC0[1:0]||—|—|RSM0[1:0]||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R/W|R/W|

## **Table 45.12 RQCi register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31, b30|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b29, b28|UFCC3[1:0]|Unread Frame Counter Configuration (Receive Queue 3+i*4)|
|||These bits set the unread frame counter used in reception queue 3+4*i.|
|b27, b26|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b25, b24|RSM3[1:0]|Receive Synchronous Mode (Receive Queue 3+i*4)|
|||B’00: Mode with write-back|
|||Other than B’00: Setting prohibited|
|b23, b22|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b21, b20|UFCC2[1:0]|Unread Frame Counter Configuration (Receive Queue 2+i*4)|
|||These bits set the unread frame counter used in  reception queue 2+4*i.|
|b19, b18|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b17, b16|RSM2[1:0]|Receive Synchronous Mode (Receive Queue 2+i*4)|
|||B’00: Mode with write-back|
|||Other than B’00: Setting prohibited|
|b15, b14|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b13, b12|UFCC1[1:0]|Unread Frame Counter Configuration (Receive Queue 1+i*4)|
|||These bits set the unread frame counter used in  reception queue 1+4*i.|
|b11, b10|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b9, b8|RSM1[1:0]|Receive Synchronous Mode (Receive Queue 1+i*4)|
|||B’00: Mode with write-back|
|||Other than B’00: Setting prohibited|
|b7, b6|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b5, b4|UFCC0[1:0]|Unread Frame Counter Configuration (Receive Queue 0+i*4)|
|||These bits set the unread frame counter used in  reception queue 0+4*i.|

**Table 45.12 RQCi register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b3, b2|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b1, b0|RSM0[1:0]|Receive Synchronous Mode (Receive Queue 0+i*4)|
|||B’00: Mode with write-back|
|||Other than B’00: Setting prohibited|

UFCCr[1:0] (r = 0 to 17) Unread Frame Counter Configuration Bits

These bits set the unread frame counter for reception queue r.

With the AVB-DMAC, four patterns of settings are available for the unread frame counter. Use the unread frame counter stop level configuration register (UFCS) to set the stop level of the unread frame counter.

When these bits are set to B’00, the stop function is disabled.

Writing to the bits is only possible when the current operating mode is configuration mode.

## RSMr[1:0] (r = 0 to 17) Receive Synchronous Mode Bits

These bits set receive synchronous mode.

Set B’00 in this bit.

Writing to the bits is only possible when the current operating mode is configuration mode.

## 45.2.9 Receive Padding Configuration Register (RPC)

The RPC register is used to set padding for received frames.

|Bit|b31|b30|b29|b28|b27|b26||b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—||—|—||||DCNT[7:0]|||||
|Initial value|0|0|0|0|0|0||0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10||b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—||PCNT[2:0]|||—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0||0|1|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R/W||R/W|R/W|R|R|R|R|R|R|R|R|

## **Table 45.13 RPC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b24|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b23 to b16|DCNT[7:0]|Stored Data Counter|
|||These bits specify the amount of data to be stored with the descriptor. The|
|||setting is in words.|
|||I.e. 1 in the counter indicates 1 word (4 bytes).|
|b15 to b11|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b10 to b8|PCNT[2:0]|Stored Padding Counter|
|||These bits indicate the amount of padding to be stored in data areas for|
|||descriptors. The setting is in words.|
|||I.e. 1 in the counter indicates 1 word (4 bytes).|
|b7 to b0|—|Reserved|
|||These bits are read as 0. The write value should be 0.|

## CAUTION

Padding can be used to extend frame lengths, but frame lengths should not exceed 4 Kbytes.

## DCNT[7:0] Stored Data Counter Bits

These bits specify the amount of the frame data (1 to 255) to be stored following the padding. Counting by one indicates one word (4 bytes). For example, when these bits are set to 47, the amount of data is 47 words (= 188 bytes).

When these bits are 0, all received data have been stored following the initial padding.

Writing to the bits is only possible when the current operating mode is configuration mode.

For details on padding, see section 45.3.4.3 (c) Padding .

## PCNT[2:0] Stored Padding Counter Bits

These bits specify the amount of padding to be appended to the on-chip RAM. Counting by one indicates one word (4 bytes). For example, when these bits are set to 1, the amount of padding is one word (= 4 bytes).

Writing to the bits is only possible when the current operating mode is configuration mode.

For details on padding, see section 45.3.4.3 (c) Padding .

## 45.2.10 Unread Frame Counter Stop Level Configuration Register (UFCS)

The UFCS register sets the stop levels for unread frames.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|||SL3[5:0]||||—|—|||SL2[5:0]||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|||SL1[5:0]||||—|—|||SL0[5:0]||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R|R|R|R|

## **Table 45.14 UFCS register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31, b30|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b29 to b24|SL3[5:0]|Stop Level 3|
|||Unread frame count stop level 3|
|b23, b22|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b21 to b16|SL2[5:0]|Stop Level 2|
|||Unread frame count stop level 2|
|b15, b14|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b13 to b8|SL1[5:0]|Stop Level 1|
|||Unread frame count stop level 1|
|b7, b6|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b5 to b0|SL0[5:0]|Stop Level 0|
|||Unread frame count stop level 0|
|||These bits are read as 0. The write value should be 0.|

SL0 to SL3[5:0] Stop Level 0 to 3 Bits

These bits set the stop levels for unread frames.

One of the four stop levels from 0 to 3 can be set for each reception queue. When these bits are set to 0, the stop function is disabled. The level to be used is specified by the receive queue configuration register i (RQCi) (i = 0 to 4).

Writing to the bits is only possible when the current operating mode is configuration mode.

## 45.2.11 Unread Frame Counter Register i (UFCVi) (i = 0 to 4)

The UFCV0 register indicates the number of unread frames in reception queues 0 to 3.

The UFCV1 register indicates the number of unread frames in reception queues 4 to 7.

The UFCV2 register indicates the number of unread frames in reception queues 8 to 11.

The UFCV3 register indicates the number of unread frames in reception queues 12 to 15.

The UFCV4 register indicates the number of unread frames in reception queues 16 and 17.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|||CV3[5:0]||||—|—|||CV2[5:0]||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|||CV1[5:0]||||—|—|||CV0[5:0]||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 45.15 UFCS0 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31, b30|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b29 to b24|CV3[5:0]|Unread Frame Count 3+4*i|
|||Number of unread frames in reception queue 3+4*i|
|b23, b22|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b21 to b16|CV2[5:0]|Unread Frame Count 2+4*i|
|||Number of unread frames in reception queue 2+4*i|
|b15, b14|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b13 to b8|CV1[5:0]|Unread Frame Count 1+4*i|
|||Number of unread frames in reception queue 1+4*i|
|b7, b6|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b5 to b0|CV0[5:0]|Unread Frame Count 0+4*i|
|||Number of unread frames in reception queue 0+4*i|

## CVr[5:0] Unread Frame Count r (r = 0 to 17) Bits

These bits indicate the number of unread frames in reception queue r.

The number of unread frames is decremented by the value that is written to the unread frame counter decrement register i (UFCDi).

For a description of how to use unread frames, refer to section 45.3.4.4, Unread Frame Counters .

## Conditions for updating:

The bits are set to 0 when the operating mode is not operation mode and when the descriptor base address load request register (DLR) issues a base address load request.

The value of these bits is incremented when a frame is stored in reception queue r normally and a write transaction to the corresponding descriptor is issued. (The maximum setting is H’3F. If the value exceeds H’3F, incrementation will not proceed.) Note that the value is incremented without waiting for response to the write transaction. Therefore confirm that the descriptor type (DESCR.DT) of the corresponding descriptor has been updated before processing the received data.

The value is decremented by the value written to the unread frame counter decrement register i

(UFCDi). Confirm that the descriptor types (DESCR.DT) of all the target descriptors for decrementing have been updated before decrementing.

## 45.2.12 Unread Frame Counter Decrement Register i (UFCDi) (i = 0 to 4)

The UFCD0 register is used to decrement unread counters in reception queues 0 to 3.

The UFCD1 register is used to decrement unread counters in reception queues 4 to 7.

The UFCD2 register is used to decrement unread counters in reception queues 8 to 11.

The UFCD3 register is used to decrement unread counters in reception queues 12 to 15.

The UFCD4 register is used to decrement unread counters in reception queues 16 and 17.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|||DV3[5:0]||||—|—|||DV2[5:0]||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|||DV1[5:0]||||—|—|||DV0[5:0]||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.16 UFCDi register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31, b30|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b29 to b24|DV3[5:0]|Unread Frame Decrement Value 3+4*i|
|||Unread frame decrement value for reception queue 3+4*i|
|b23, b22|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b21 to b16|DV2[5:0]|Unread Frame Decrement Value 2+4*i|
|||Unread frame decrement value for reception queue 2+4*i|
|b15, b14|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b13 to b8|DV1[5:0]|Unread Frame Decrement Value 1+4*i|
|||Unread frame decrement value for reception queue 1+4*i|
|b7, b6|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b5 to b0|DV0[5:0]|Unread Frame Decrement Value 0+4*i|
|||Unread frame decrement value for reception queue 0+4*i|

## DVr[5:0] Unread Frame Decrement Value r (r = 0 to 17) Bits

These bits set the decrement value for unread frames in reception queue r. The value of an unread frame counter register i (UFCVi) (i = 0 to 4) is decremented by the value set in the corresponding bits of this register.

Write H’3F to these bits to reset the unread counters in reception queue r.

These bits are always read as 0.

## 45.2.13 Separation Filter Offset Register (SFO)

The SFO register sets an offset into frames for use by the separation filter.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|—|||FBP[5:0]||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.17 SFO register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b6|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b5 to b0|FBP[5:0]|First Byte Position|
|||Position in Ethernet frames of the first byte of the bytes to be used by the|
|||separation filter|

## FBP[5:0] First Byte Position Bits

These bits set the position in Ethernet frames of the first byte of the bytes to be used by the separation filter.

When these bits are 0, the separation filter starts from the start of each Ethernet frame (first byte of the destination address). For bytes in Ethernet frames, see Figure 45.2 , in section 45.2.1, AVB-DMAC Mode Register (CCC) .

Writing to the bits is only possible when the current operating mode is configuration mode.

For separation filtering, see section 45.3.4.1 (1) Separation Filtering .

## CAUTION

Received frames having fewer bytes than the setting of these bits + 8 bytes are judged to be non-matching by the separation filter. In this case, the data will either be sorted into a reception queue or discarded in accord with the setting of the separation filtering select bits in the receive configuration register (RCR.ESF).

## 45.2.14 Separation Filter Pattern Register i (SFPi) (i = 0 to 31)

Pairs of SFPi registers set the pattern for the separation filters to be used by the corresponding reception queues 2 to 17.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24<br>b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||FPs[31+32*(i%2):16+32*(i%2)]|||||||||
|Initial value|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8<br>b7|b6|b5|b4|b3|b2|b1|b0|
||||||||FPs[15+32*(i%2):0+32*(i%2)]|||||||||
|Initial value|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||**Table 45.18**||**SFPi register contents**||||||||||||
|||**Bit Position**||**Bit**|**Name**||**Function**|||||||||
|||b31 to b0||FPs[31+32*(i%2|||Separation Filter Pattern|||||||||
|||||):0+32*(i%2)]|||These bits|set the pattern|of the|separation filter.||||||
||||||||The 64-bit|filter pattern is|set for|each queue.||||||

## FPs[63:0](s = i/2) Separation Filter Pattern Bits

These bits set the pattern for a separation filter to be used with reception queues 2 to 17 (for streams 0 to 15).

Each queue has a 64-bit setting; reception queue 2 (for stream 0) uses SFP0 and SFP1, reception queue 17 (for stream 15) uses SFP30 and SFP31, and so on.

SFPi.FPs[7:0] (where i is an even number) are used for the byte of Ethernet frame data specified by the separation filter offset register, while SFPi.FPs[63:56] (where i is the corresponding odd number) are used for the byte at the address specified by the separation filter offset register (SFO) + 7.

Data from received frames passes the separation filter when the following formula is satisfied.

(Data from received frames & SFMi.CFM) == SFPi.FPs

Eight bytes from the position specified by the start byte position bits (SFO.FBP) of data in the received frames are used by the separation filter.

Writing to the bits is only possible when the current operating mode is configuration mode.

For separation filtering, see section 45.3.4.1 (1) Separation Filtering .

## 45.2.15 Separation Filter Mask Register i (SFMi) (i = 0 or 1)

A pair of SFMi registers sets the mask value for the separation filter used by the corresponding reception queue 2 to 17.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CFM[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||CFM[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.19 SFMi register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|CFM[31:0]|Separation Filter Mask|
|||These bits set the mask value for the separation filter.|

## CFM[63:0] Separation Filter Mask Bits

These bits set the mask value for the separation filter for use with the corresponding reception queue 2 to 17 (stream 0 to 15).

SFM0.CFM[7:0] are used for bytes of Ethernet frame data specified by the separation filter offset register, while SFM1.CFM[63:56] are used for the separation filter offset register (SFO) + 7.

Writing to the bits is only possible when the current operating mode is configuration mode.

For separation filtering, see section 45.3.4.1 (1) Separation Filtering .

## 45.2.16 Transmit Configuration Register (TGC)

The TGC register is used to make settings related to transmission for the AVB-DMAC.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|TBD3[1:0]||—|—|TBD2[1:0]||
|Initial value|0|0|0|0|0|0|0|0|0|0|1|0|0|0|1|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R|R|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|TBD1[1:0]||—|—|TBD0[1:0]||—|—|TQP[1:0]||TSM3|TSM2|TSM1|TSM0|
|Initial value|0|0|1|0|0|0|1|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.20 TGC register contents (1/2)**

|**Bit Position**<br>**Bit Name**|**Function**|
|---|---|
|b31 to b22<br>—|Reserved<br>These bits are read as 0. The write value should be 0.|
|b21, b20<br>TBD3[1:0]|Transmit FIFO Size (Stream Class A)<br>Number of frames to be fetched from transmission queue 3 (for stream class A)<br>**CAUTION**<br>Write 2 to these bits.|
|b19, b18<br>—|Reserved<br>These bits are read as 0. The write value should be 0.|
|b17, b16<br>TBD2[1:0]|Transmit FIFO Size (Stream Class B)<br>Number of frames to be fetched from transmission queue 2 (for stream class B)<br>**CAUTION**<br>Write 2 to these bits.|
|b15, b14<br>—|Reserved<br>These bits are read as 0. The write value should be 0.|
|b13, b12<br>TBD1[1:0]|Transmit FIFO Size (Network Control)<br>Number of frames to be fetched from transmission queue 1 (for network control)<br>**CAUTION**<br>Write 2 to these bits.|
|b11, b10<br>—|Reserved<br>These bits are read as 0. The write value should be 0.|
|b9, b8<br>TBD0[1:0]|Transmit FIFO Size (Best Effort)<br>Number of frames to be fetched from transmission queue 0 (for best effort)<br>**CAUTION**<br>Write 2 to these bits.|
|b7, b6<br>—|Reserved<br>These bits are read as 0. The write value should be 0.|
|b5, b4<br>TQP[1:0]|Transmit Queue Priority<br>00: Non-ABV mode<br>01: AVB mode 1<br>10: Setting prohibited<br>11: AVB mode 2|

**Table 45.20 TGC register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b3|TSM3|Transmit Synchronous Mode (Stream Class A)|
|||0: With write-back|
|||1: Setting prohibited|
|b2|TSM2|Transmit Synchronous Mode (Stream Class B)|
|||0: With write-back|
|||1: Setting prohibited|
|b1|TSM1|Transmit Synchronous Mode (Network Control)|
|||0: With write-back|
|||1: Setting prohibited|
|b0|TSM0|Transmit Synchronous Mode (Best Effort)|
|||0: With write-back|
|||1: Setting prohibited|

TBD0 to TBD3[1:0] Transmit FIFO Size (Stream Class A/ Stream Class B/Network Control/ Best Effort) Bits

These bits set the sizes of the transmission FIFO buffers for use with each of the transmission queues.

Writing to these bits is only possible when the current operating mode is configuration mode. Set these bits to 2.

TQP[1:0] Transmit Queue Priority Bits

These bits set the priority of the transmission queues.

B’00: Non-AVB mode: Q3→Q2→Q1→Q0

B’01: AVB mode 1: Q3 (CBS)→Q2 (CBS)→Q1→Q0

B’10: Setting prohibited

B’11: AVB mode 2: Q1→Q3 (CBS)→Q2 (CBS)→Q0

For the credit-based shaping (CBS) algorithm, see section 45.3.6, CBS (Credit-Based Shaping) .

The CBS algorithm is not applied in non-AVB mode (i.e. when the value is B’00).

Writing to the bits is only possible when the current operating mode is configuration mode.

## TSM0 to TSM3 Transmit Synchronous Bits

Set these bits to 0.

## 45.2.17 Transmit Configuration Control Register (TCCR)

The TCCR register controls transmission by the AVB-DMAC and is used to make related settings.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|TFR|TFEN|—|—|—|—|TSRQ3|TSRQ2|TSRQ1|TSRQ0|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|R|R|R|R|R/W|R/W|R/W|R/W|

**Table 45.21 TCCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b10|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b9|TFR|Time Stamp FIFO Release|
|||0(W): No request to the time-stamp FIFO.|
|||1(W): Releases the oldest entry in the time-stamp FIFO.|
|b8|TFEN|Time Stamp FIFO Enable|
|||0: Recording of transmission time stamps in the time-stamp FIFO is disabled.|
|||1: Recording of transmission time stamps in the time-stamp FIFO is enabled.|
|b7 to b4|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b3|TSRQ3|Transmit Start Request (Queue 3 (Stream Class A))|
|||0(R): Transmission queue is empty or stopped.|
|||1(W): A transmission start request is issued.|
|||1(R): Fetching of data for transmission is pending.|
|b2|TSRQ2|Transmit Start Request (Queue 2 (Stream Class B))|
|||0(R): Transmission queue is empty or stopped.|
|||1(W): A transmission start request is issued.|
|||1(R): Fetching of data for transmission is pending.|
|b1|TSRQ1|Transmit Start Request (Queue 1 (Network Control))|
|||0(R): Transmission queue is empty or stopped.|
|||1(W): A transmission start request is issued.|
|||1(R): Fetching of data for transmission is pending.|
|b0|TSRQ0|Transmit Start Request (Queue 0 (Best Effort))|
|||0(R): Transmission queue is empty or stopped.|
|||1(W): A transmission start request is issued.|
|||1(R): Fetching of data for transmission is pending.|

TFR Time Stamp FIFO Release Bit

This bit releases the oldest entry in the time-stamp FIFO.

When 1 is written to this bit, the TFAi register is updated by the oldest entry in the time-stamp FIFO.

For a description of how to use the time-stamp FIFO, see section 45.3.5.4, Time Stamping in Transmission .

This bit is always read as 0.

When the time stamp FIFO count bits (TSR.TFFL) are set to B’000, 1 should not be written to this bit.

## TFEN Time Stamp FIFO Enable Bit

This bit enables storage in the time-stamp FIFO.

When it is set, time-stamp information is stored for descriptors with DESCR.TSR set to 1 (for DESCR.TSR, see section 45.3.5.2 (2) Configuration of Transmission Frame Data Descriptors .

When 0 is set in this bit, no entries are made in the time-stamp FIFO.

For a description of how to use the time-stamp FIFO, see section 45.3.5.4, Time Stamping in Transmission .

## TSRQt Transmit Start Request (Queue t) (t = 0 to 3) Bit

This bit issues a request to start transmission for transmission queue t.

When read, this bit being set to 1 indicates that transmission queue t has a frame that has not yet been fetched to the transmission FIFO.

Frame transmission by the E-MAC is processed independently from fetching to the transmission FIFO. The timing of transmission from a queue depends on the priority order of transmission.

For the scheduling of transmission queues, see section 45.3.5.1, Transmission Modes .

Writing to this bit is only possible when the current operating mode is configuration mode.

Only 1 can be written to the bit. Writing 0 to the bit has no effect.

## Conditions for updating:

The bit is set to 0 when the operating mode is not operation mode, when a descriptor of type EEMPTY, FEMPTY, or LEMPTY (no usable data) is processed, when an EOS descriptor is processed, and when a descriptor with defective data is processed.

## 45.2.18 Transmit Status Register (TSR)

The TSR register indicates the state of transmission by the AVB-DMAC.

|Bit|b31|b30|b29|b28|b27|b26||b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—||—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0||0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R||R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10||b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—||TFFL[2:0]|||—|—|—|—|CCS1[1:0]||CCS0[1:0]||
|Initial value|0|0|0|0|0|0||0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R||R|R|R|R|R|R|R|R|R|R|

**Table 45.22 TSR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b11|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b10 to b8|TFFL[2:0]|Time Stamp FIFO Count|
|||Number of time-stamp FIFOs|
|b7 to b4|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b3, b2|CCS1[1:0]|CBS Counter Status 1 (Class A)|
|||B’00: The current credit value is within the limit.|
|||B’01: The current credit value is less than or equal to the lower limit.|
|||B’10: The current credit value is greater than or equal to the upper limit.|
|||B’11: (Reserved)|
|b1, b0|CCS0[1:0]|CBS Counter Status 0 (Class B)|
|||B’00: The current credit value is within the limit.|
|||B’01: The current credit value is less than or equal to the lower limit.|
|||B’10: The current credit value is greater than or equal to the upper limit.|
|||B’11: (Reserved)|

## TFFL[3:0] Time Stamp FIFO Count Bits

These bits indicate the number of time stamps in the time-stamp FIFO.

The values 0 and 2 indicate that the time-stamp FIFO is empty and full, respectively (values 3 to 7 are reserved).

Conditions for updating:

The bits are set to 0 when the operating mode is not operation mode and when the time stamp FIFO enable bit in the transmit configuration control register (TCCR.TFEN) = 0.

When the time stamp FIFO enable bit (TCCR.TFEN) is 1 and these bits are not 2, the value of these bits is incremented after a frame with DESCR.TSR set has been transmitted by the E-MAC (for DESCR.TSR, see section 45.3.5.2 (2) Configuration of Transmission Frame Data Descriptors .

The value of these bits is decremented if it is not 0 when 1 is written to the time stamp FIFO release bit in the transmit configuration control register (TCCR.TFR).

## CCS0 and CCS1[1:0] CBS Counter Status 0 and 1 Bits

These bits indicate the CBS (credit-based shaping) state of stream data transmission queues 0 and 1. If the calculated credit value is outside the range specified by CBS upper limit register c (CULc) and CBS lower limit register c (CLLc), it falls outside the range for CBS.

Conditions for updating:

The bits are set to B’00 when the operating mode is not operation mode.

The bits are set to B’00 when the credit value calculated by the CBS is within the range specified by the CBS upper limit register c (CULc) (c = 0, 1) and the CBS lower limit register c (CLLc) (c = 0, 1).

The bits are set to B’01 if the credit value calculated by the CBS is lower than the value in CBS lower limit register c (CLLc).

The bits are set to B’10 if the credit value calculated by the CBS is higher than the value in CBS upper limit register c (CULc).

## 45.2.19 Time Stamp FIFO Access Register 0 (TFA0)

TFA0 indicates the time stamp value.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||TSV[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||TSV[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 45.23 TFA0 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|TSV[31:0]|Time Stamp Value|
|||Time stamp value|

## TSV[79:0] Time Stamp Value Bits

These 80 bits consist of TFA0.TSV[31:0], TFA1.TSV[63:32], and TFA2.TSV[79:64], which together indicate the oldest time stamp value stored in the time-stamp FIFO.

Once the time-stamp FIFO is full, no further time-stamp values are stored.

Conditions for updating:

The bits are set to H’0000 0000 when the operating mode is not operation mode.

The register is updated whenever a value is stored in the time-stamp FIFO (when the time-stamp FIFO count bit in the transmit status register (TSR.TFFL) changes from 0 to 1).

The register is updated when the oldest entry is released (when the time stamp FIFO release bit in the transmit configuration control register (TCCR.TFR) is set to 1).

## 45.2.20 Time Stamp FIFO Access Register 1 (TFA1)

The TFA1 register indicates the time-stamp value.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||TSV[63:48]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||TSV[47:32]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 45.24 TFA1 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|TSV[63:32]|Time Stamp Value|
|||Time-stamp value|

## TSV[63:32] Time Stamp Value Bits

For details, see section 45.2.19, Time Stamp FIFO Access Register 0 (TFA0) .

## 45.2.21 Time Stamp FIFO Access Register 2 (TFA2)

The TFA2 register indicates the time-stamp tag and part of the time-stamp value.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|||||TST[9:0]||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||TSV[79:64]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 45.25 TFA2 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b26|—|Reserved|
|||These bits are read as 0.|
|b25 to b16|TST[9:0]|Time Stamp Tag|
|||Time-stamp tag|
|b15 to b0|TSV[79:64]|Time Stamp Value|
|||Time-stamp value|

## TST[9:0] Time Stamp Tag Bits

These bits indicate the contents of the DESCR.TAG bit within the descriptor for frame transmission. These values are used to check the correlation between frames within the transmission queue and the time-stamp values (accessible through time stamp FIFO access register i (TFAi.TSV, i = 0 to 2)) which can be placed in the FIFO.

For the tagging of frames in transmission, see section 45.3.5.4, Time Stamping in Transmission .

When the time stamp FIFO count bits (TSR.TFFL) are 0, do not refer to these bits.

Conditions for updating:

The bits are set to H’000 when the operating mode is not operation mode.

Updated when a value is stored in the time-stamp FIFO (when the value of the time stamp FIFO count bit in the transmit status register (TSR.TFFL) changes from 0 to 1).

Updated when the oldest entry has been released (1 is set in the time stamp FIFO release bit in the transmit configuration control register (TCCR.TFR)).

## TSV[73:64] Time Stamp Value Bits

For details, see section 45.2.19, Time Stamp FIFO Access Register 0 (TFA0) .

## 45.2.22 CBS Increment Value Register c (CIVRc) (c = 0 or 1)

The CIVR0 register sets the increment in the CBS algorithm for transmission queue 2 (for stream class B).

The CIVR1 register sets the increment in the CBS algorithm for transmission queue 3 (for stream class A).

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CIV[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||CIV[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||**Table 45.26**||**CIVRc register contents**|||||||||||||
|||**Bit Position**||**Bit**|**Name**||**Function**||||||||||
|||b31 to b0||CIV[31:0]|||CBS Increment Value||||||||||
||||||||Setting value: 1 to 65535|||(H’00000001 to H’0000FFFF)|||||||

## CIV[31:0] CBS Increment Value Bits

These bits set the increment for the CBS algorithm.

Set a value in the range from 1 to 65535 (H’0000 0001 to H’0000 FFFF).

The value to be written to these bits depends on the Ethernet bit rate and B  (internal bus clock). For details, see section 45.3.6, CBS (Credit-Based Shaping) .

## 45.2.23 CBS Decrement Value Register c (CDVRc) (c = 0 or 1)

The CDVR0 register sets the decrement in the CBS algorithm for transmission queue 2 (for stream class B).

The CDVR1 register sets the decrement in the CBS algorithm for transmission queue 3 (for stream class A).

|Bit|b31|b30|b29|b28|b27|b26|b25|b24<br>b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CDV[31:16]||||||||
|Initial value|1|1|1|1|1|1|1|1<br>1|1|1|1|1|1|1|1|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8<br>b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||CDV[15:0]||||||||
|Initial value|1|1|1|1|1|1|1|1<br>1|1|1|1|1|1|1|1|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||**Table 45.27**||**CDVR0**||**and CDVR1 register contents**||||||||||
|||**Bit Position**||**Bit**|**Name**||**Function**|||||||||
|||b31 to b0||CDV[31:0]|||CBS Decrement Value|||||||||
||||||||Setting value: -1 to -65536 (H’FFFF FFFF to H’FFFF||||||0000)|||

## CDV[31:0] CBS Decrement Value Bits

These bits set the decrement for the CBS algorithm.

Set a negative value from -1 to -65536 (H’FFFF FFFF to H’FFFF 0000).

The value to be written to these bits depends on the Ethernet bit rate and B  (internal bus clock). For details, see section 45.3.6, CBS (Credit-Based Shaping) .

## 45.2.24 CBS Upper Limit Register c (CULc) (c = 0 or 1)

The CUL0 register sets the upper limit for credit values calculated by using the CSB algorithm for transmission queue 2 (for stream class B).

The CUL1 register sets the upper limit for credit values calculated by using the CSB algorithm for transmission queue 3 (for stream class A).

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||ULV[31:16]|||||||||
|Initial value|0|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||ULV[15:0]|||||||||
|Initial value|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.28 CUL0 and CUL1 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31?b0|ULV[31:0]|CBS Upper Limit|
|||Upper limit on CBS values|

## ULV[31:0] CBS Upper Limit Bits

These bits set the upper limit for credit values calculated by using the CBS algorithm.

The setting is a limiting value for error detection and does not normally affect operation of the algorithm.

Write a positive value to these bits.

For details, see section 45.3.6, CBS (Credit-Based Shaping) .

## 45.2.25 CBS Lower Limit Register c (CLLc) (c = 0 or 1)

The CUL0 register sets the lower limit for credit values calculated by using the CSB algorithm for transmission queue 2 (for stream class B).

The CUL1 register sets the lower limit for credit values calculated by using the CSB algorithm for transmission queue 3 (for stream class A).

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||LLV[31:16]|||||||||
|Initial value|1|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||LLV[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.29 CULc register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|LLV[31:0]|CBS Lower Limit|
|||Lower limit on CBS values|

## LLV[31:0] CBS Lower Limit Bits

These bits set the lower limit for credit values calculated by using the CBS algorithm.

The setting is a limiting value for error detection and does not normally affect operation of the algorithm.

Write a negative value to these bits.

For details, see section 45.3.6, CBS (Credit-Based Shaping) .

## 45.2.26 Descriptor Interrupt Control Register (DIC)

The DIC register is used to control descriptor interrupts 1 to 15.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||DPE15|DPE14|DPE13|DPE12|DPE11|DPE10|DPE9|DPE8|DPE7|DPE6|DPE5|DPE4|DPE3|DPE2|DPE1|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|

**Table 45.30 DIC register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b16|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b15|DPE15|Descriptor Interrupt Enable 15|
|||0: Disabled|
|||1: Enabled|
|b14|DPE14|Descriptor Interrupt Enable 14|
|||0: Disabled|
|||1: Enabled|
|b13|DPE13|Descriptor Interrupt Enable 13|
|||0: Disabled|
|||1: Enabled|
|b12|DPE12|Descriptor Interrupt Enable 12|
|||0: Disabled|
|||1: Enabled|
|b11|DPE11|Descriptor Interrupt Enable 11|
|||0: Disabled|
|||1: Enabled|
|b10|DPE10|Descriptor Interrupt Enable 10|
|||0: Disabled|
|||1: Enabled|
|b9|DPE9|Descriptor Interrupt Enable 9|
|||0: Disabled|
|||1: Enabled|
|b8|DPE8|Descriptor Interrupt Enable 8|
|||0: Disabled|
|||1: Enabled|
|b7|DPE7|Descriptor Interrupt Enable 7|
|||0: Disabled|
|||1: Enabled|
|b6|DPE6|Descriptor Interrupt Enable 6|
|||0: Disabled|
|||1: Enabled|
|b5|DPE5|Descriptor Interrupt Enable 5|
|||0: Disabled|
|||1: Enabled|
|b4|DPE4|Descriptor Interrupt Enable 4|
|||0: Disabled|
|||1: Enabled|

**Table 45.30 DIC register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b3|DPE3|Descriptor Interrupt Enable 3|
|||0: Disabled|
|||1: Enabled|
|b2|DPE2|Descriptor Interrupt Enable 2|
|||0: Disabled|
|||1: Enabled|
|b1|DPE1|Descriptor Interrupt Enable 1|
|||0: Disabled|
|||1: Enabled|
|b0|—|Reserved|
|||This bit is read as 0. The write value should be 0.|

## RPE1 to RPE15 Descriptor Interrupt Enable Bits 1 to 15

When an interrupt source flag is set (a bit from among the DPF1 to DPF15 bits in the descriptor interrupt status register (DIS) = 1) while the interrupt is enabled, the interrupt is issued.

## 45.2.27 Descriptor Interrupt Status Register (DIS)

The DIS register indicates the state of descriptor interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||DPF15|DPF14|DPF13|DPF12|DPF11|DPF10|DPF9|DPF8|DPF7|DPF6|DPF5|DPF4|DPF3|DPF2|DPF1|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|

**Table 45.31 DIS register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b16|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b15|DPF15|Descriptor Interrupt Status15|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b14|DPF14|Descriptor Interrupt Status14|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b13|DPF13|Descriptor Interrupt Status13|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b12|DPF12|Descriptor Interrupt Status12|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b11|DPF11|Descriptor Interrupt Status11|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b10|DPF10|Descriptor Interrupt Status10|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b9|DPF9|Descriptor Interrupt Status9|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b8|DPF8|Descriptor Interrupt Status8|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b7|DPF7|Descriptor Interrupt Status7|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b6|DPF6|Descriptor Interrupt Status6|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b5|DPF5|Descriptor Interrupt Status5|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b4|DPF4|Descriptor Interrupt Status4|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|

**Table 45.31 DIS register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b3|DPF3|Descriptor Interrupt Status3|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b2|DPF2|Descriptor Interrupt Status2|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b1|DPF1|Descriptor Interrupt Status1|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b0|—|Reserved|
|||This bit is read as 0. The write value should be 0.|

## DPF1 to DPF15 Descriptor Interrupt Status Bits

The corresponding bit indicates completion of the processing of a descriptor with DESCR.DIE set to the corresponding number from 1 to 15 within the reception or transmission queue.

When DESCR.DIE is 0, the descriptor interrupt is not generated.

Only 0 can be written to these bits.

[Conditions for Changing]

A bit is set to 0 when the operating mode is not operation mode.

A bit is set to 1 when a descriptor with DESCR.DIE set to the corresponding number from 1 to 15 is processed and a write transaction to the corresponding descriptor is issued. Note that the bit is set to 1 without waiting for response to the write transaction. Therefore confirm that the descriptor type (DESCR.DT) of the corresponding descriptor has been updated before post-processing the processed descriptor.

## 45.2.28 Error Interrupt Control Register (EIC)

The EIC register controls the AVB-DMAC-related error interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|TFFE|CULE1|CULE0|CLLE1|CLLE0|SEE|QEE|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|

## **Table 45.32 EIC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b9|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b8|TFFE|Time Stamp FIFO Full-Error Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b7|CULE1|CBS Upper Limit Error Interrupt Enable (Class A)|
|||0: Disabled|
|||1: Enabled|
|b6|CULE0|CBS Upper Limit Error Interrupt Enable (Class B)|
|||0: Disabled|
|||1: Enabled|
|b5|CLLE1|CBS Lower Limit Error Interrupt Enable (Class A)|
|||0: Disabled|
|||1: Enabled|
|b4|CLLE0|CBS Lower Limit Error Interrupt Enable (Class B)|
|||0: Disabled|
|||1: Enabled|
|b3|SEE|Separation Filter Error Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b2|QEE|Queue Error Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b1, b0|—|Reserved|
|||These bits are read as 0. The write value should be 0.|

## TFFE Time Stamp FIFO Full-Error Interrupt Enable Bits

When the time stamp FIFO is full (TFFF in the error interrupt status register (EIS) = 1) and the interrupt is enabled, the interrupt is issued.

CULE1 CBS Upper Limit Error Interrupt Enable Bit (Class A)

When the Class A CBS reaches its upper limit (CULF1 in the error interrupt status register (EIS) = 1) and the interrupt is enabled, the interrupt is issued.

## CULE0 CBS Upper Limit Error Interrupt Enable Bit (Class B)

When the Class B CBS reaches its upper limit (CULF0 in the error interrupt status register (EIS) = 1) and the interrupt is enabled, the interrupt is issued.

## CLLE1 CBS Lower Limit Error Interrupt Enable Bit (Class A)

When the Class A CBS reaches its lower limit (CLLF1 in the error interrupt status register (EIS) = 1) and the interrupt is enabled, the interrupt is issued.

## CLLE0 CBS Lower Limit Error Interrupt Enable Bit (Class B)

When the Class B CBS reaches its lower limit (CLLF0 in the error interrupt status register (EIS) = 1) and the interrupt is enabled, the interrupt is issued.

SEE Separation Filter Error Interrupt Enable Bit

When the separation filter error is detected (SEF in the error interrupt status register (EIS) = 1) and the interrupt is enabled, the interrupt is issued.

## QEE Queue Error Interrupt Enable Bit

When the queue error is detected (QEF in the error interrupt status register (EIS) = 1) and the interrupt is enabled, the interrupt is issued.

## 45.2.29 Error Interrupt Status Register (EIS)

The EIS register indicates the states of AVB-DMAC-related error interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|QFS|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|TFFF|CULF1|CULF0|CLLF1|CLLF0|SEF|QEF|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|

## **Table 45.33 EIS register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b17|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b16|QFS|Queue Full Error Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b15 to b9|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b8|TFFF|Time Stamp FIFO Full Error Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b7|CULF1|CBS Upper Limit Error Interrupt Status (Class A)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b6|CULF0|CBS Upper Limit Error Interrupt Status (Class B)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b5|CLLF1|CBS Lower Limit Error Interrupt Status (Class A)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b4|CLLF0|CBS Lower Limit Error Interrupt Status (Class B)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b3|SEF|Separation Filter Error Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b2|QEF|Queue Error Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b1, b0|—|Reserved|
|||These bits are read as 0. The write value should be 0.|

## QFS Queue Full Error Status Bit

With the interrupts enabled, this bit indicates that a queue is full (the receive queue r full interrupt status bit (QFFr) or the receive FIFO full interrupt status bit (RFFF) in receive interrupt status register 2 (RIS2) = 1).

[Conditions for Changing]

If the receive queue r full interrupt status bit (RIS2.QFFr) and the receive queue r full interrupt enable bit in the receive interrupt control register 2 (RIC2.QFEr) are updated, this bit is also updated.

If the receive FIFO full interrupt status bit (RIS2.RFFF) and the receive FIFO full interrupt enable bit (RIC2.RFFE) are updated, this bit is also updated.

## TFFF Time Stamp FIFO Full-Error Interrupt Status Bit

This bit indicates that a new transmission time stamp has been discarded due to the time-stamp FIFO being full (i.e. has reached the overflow state).

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

The bit is set to 1 when a frame with DESCR.TSR set is transmitted while the time stamp FIFO enable bit in the transmit configuration control register (TCCR.TFEN) is set to 1 and the time stamp FIFO count bit in the transmit status register (TSR.TFFL) is set to 2.

## CULF1 CBS Upper Limit Error Interrupt Status Bit (Class A)

This bit indicates that CBS counter 1 has exceeded the set upper limit (CUL1.ULV in the CBS upper limit register c (CULc)).

Only 0 can be written to the bit.

[Conditions for Changing]

This bit is set to 0 when the operating mode is not operation mode.

This bit is set to 1 when the value of the CBS counter status 1 (Class A) bits in the transmit status register (TSR.CCS1) change from 00 (indicating a value within the range between the limits) to 10 (indicating a value over the upper limit).

CULF0 CBS Upper Limit Error Interrupt Status Bit (Class B)

This bit indicates that CBS counter 0 has exceeded the set upper limit (CUL0.ULV in the CBS upper limit register c (CULc)).

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

The bit is set to 1 when the value of the CBS counter status 0 (Class B) bit in the transmit status register changes from 00 (indicating a value within the range between the limits) to 10 (indicating a value over the upper limit).

## CULF1 CBS Lower Limit Error Interrupt Status Bit (Class A)

This bit indicates that CBS counter 1 has fallen below the set lower limit (CLL1.LLV in CBS lower limit register c (CLLc)).

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

The bit is set to 1 when the value of the CBS counter status 1 (Class A) bit in the transmit status register (TSR.CCS1) changes from 00 (indicating a value within the range between the limits) to 01 (indicating a value less than the lower limit).

## CLLF0 CBS Lower Limit Error Interrupt Status Bit (Class B)

This bit indicates that CBS counter 0 has fallen below the set lower limit (CLL0.LLV in the CBS lower limit register c (CLLc)).

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

The bit is set to 1 when the value of the CBS counter status 0 (Class B) bit in the transmit status register (TSR.CCS0) changes from 00 (indicating a value within the range between the limits) to 01 (indicating a value less than the lower limit).

## SEF Separation Filter Error Interrupt Status Bit

This bit indicates that a received frame has been discarded due to non-matching of the defined separation filter.

Only 0 can be written to this bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

If the stream filtering select bits in the receive configuration register (RCR.ESF) are B’10, this bit is set to 1 when the received frame is discarded because the received AVB stream data frame has not match any of the separation filters.

QEF Queue Error Interrupt Status Bit

This bit indicates that an error is detected when the transmission and reception queues are processed. For details, see section 45.3.2.3, Checking Integrity .

Only 0 can be written to this bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

If an error in the transmission and reception queues is detected, this bit is set to 1.

## 45.2.30 Receive Interrupt Control Register 0 (RIC0)

The RIC0 register controls the AVB-DMAC receive interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|FRE17|FRE16|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||FRE15|FRE14|FRE13|FRE12|FRE11|FRE10|FRE9|FRE8|FRE7|FRE6|FRE5|FRE4|FRE3|FRE2|FRE1|FRE0|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.34 RIC0 register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b18|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b17|FRE17|Receive Frame Interrupt Enable 17 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b16|FRE16|Receive Frame Interrupt Enable 16 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b15|FRE15|Receive Frame Interrupt Enable 15 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b14|FRE14|Receive Frame Interrupt Enable 14 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b13|FRE13|Receive Frame Interrupt Enable 13 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b12|FRE12|Receive Frame Interrupt Enable 12 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b11|FRE11|Receive Frame Interrupt Enable 11 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b10|FRE10|Receive Frame Interrupt Enable 10 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b9|FRE9|Receive Frame Interrupt Enable 9 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b8|FRE8|Receive Frame Interrupt Enable 8 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b7|FRE7|Receive Frame Interrupt Enable 7 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b6|FRE6|Receive Frame Interrupt Enable 6 (Stream)|
|||0: Disabled|
|||1: Enabled|

**Table 45.34 RIC0 register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b5|FRE5|Receive Frame Interrupt Enable 5 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b4|FRE4|Receive Frame Interrupt Enable 4 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b3|FRE3|Receive Frame Interrupt Enable 3 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b2|FRE2|Receive Frame Interrupt Enable 2 (Stream)|
|||0: Disabled|
|||1: Enabled|
|b1|FRE1|Receive Frame Interrupt Enable 1 (Network Control)|
|||0: Disabled|
|||1: Enabled|
|b0|FRE0|Receive Frame Interrupt Enable 0 (Best Effort)|
|||0: Disabled|
|||1: Enabled|

## FRE0 to FRE17 Receive Frame Interrupt Enable Bits 0 to 17

When an interrupt source flag is set (a bit from among the receive interrupt status bits in the receive interrupt status register (RIS0.FRF0 to 17) = 1) while the interrupt is enabled, the interrupt is issued.

## 45.2.31 Receive Interrupt Status Register 0 (RIS0)

The RIS0 register indicates the states of the AVB-DMAC receive interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|FRF17|FRF16|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||FRF15|FRF14|FRF13|FRF12|FRF11|FRF10|FRF9|FRF8|FRF7|FRF6|FRF5|FRF4|FRF3|FRF2|FRF1|FRF0|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.35 RIS0 register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b18|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b17|FRF17|Receive Frame Interrupt Status 17 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b16|FRF16|Receive Frame Interrupt Status 16 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b15|FRF15|Receive Frame Interrupt Status 15 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b14|FRF14|Receive Frame Interrupt Status 14 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b13|FRF13|Receive Frame Interrupt Status 13 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b12|FRF12|Receive Frame Interrupt Status 12 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b11|FRF11|Receive Frame Interrupt Status 11 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b10|FRF10|Receive Frame Interrupt Status 11 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b9|FRF9|Receive Frame Interrupt Status 9 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b8|FRF8|Receive Frame Interrupt Status 8 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b7|FRF7|Receive Frame Interrupt Status 7 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b6|FRF6|Receive Frame Interrupt Status 6 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|

**Table 45.35 RIS0 register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b5|FRF5|Receive Frame Interrupt Status 5 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b4|FRF4|Receive Frame Interrupt Status 4 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b3|FRF3|Receive Frame Interrupt Status 3 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b2|FRF2|Receive Frame Interrupt Status 2 (Stream)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b1|FRF1|Receive Frame Interrupt Status 1 (Network Control)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b0|FRF0|Receive Frame Interrupt Status 0 (Best Effort)|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|

## FRF0 to FRF17 Receive Frame Interrupt Status Bits 0 to 17

Each bit indicates that a corresponding frame has been stored normally in reception queues 0 to 17 and that data are ready for CPU processing.

Only 0 can be written to the bit.

[Conditions for Changing]

A bit is set to 0 when the operating mode is not operation mode.

A bit is set to 0 when a value is written to the unread frame counter decrement register i (UFCDi) (i = 0 to 4), and this decrements the value of unread frame counter register i (UFCVi) (i = 0 to 4) to 0.

When a frame is stored in reception queue normally and a write transaction to the corresponding descriptor is issued, the corresponding bit is set to 1. Note that the bit is set to 1 without waiting for response to the write transaction. Therefore confirm that the descriptor type (DESCR.DT) of the corresponding descriptor has been updated before processing the received data.

## 45.2.32 Receive Interrupt Control Register 1 (RIC1)

The RIC1 register controls the AVB-DMAC receive interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||RFWE|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 45.36 RIC1 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31|RFWE|Receive FIFO Warning Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b30 to b0|—|Reserved|
|||These bits are read as 0. The write value should be 0.|

## RFWE Receive FIFO Warning Interrupt Enable Bit

If the reception FIFO reaches the caution level (the value set in the receive FIFO caution level bits in the receive configuration register (RCR.RFCL) with the corresponding interrupt enabled, the interrupt is issued.

## 45.2.33 Receive Interrupt Status Register 1 (RIS1)

The RIS1 register indicates the states of the AVB-DMAC receive interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||RFWF|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 45.37 RIS1 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31|RFWF|Receive FIFO Warning Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b30 to b0|—|Reserved|
|||These bits are read as 0. The write value should be 0.|

## RFWF Receive FIFO Warning Interrupt Status Bit

This bit indicates that the reception FIFO has reached the set caution level (the value set in the receive FIFO caution level bits in the receive configuration register (RCR.RFCL)).

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

The bit is set to 1 when the reception FIFO exceeds the set caution level (the value set in the receive FIFO caution level bits in the receive configuration register (RCR.RFCL)).

## 45.2.34 Receive Interrupt Control Register 2 (RIC2)

The RIC2 register controls the AVB-DMAC receive interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||RFFE|—|—|—|—|—|—|—|—|—|—|—|—|—|QFE17|QFE16|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||QFE15|QFE14|QFE13|QFE12|QFE11|QFE10|QFE9|QFE8|QFE7|QFE6|QFE5|QFE4|QFE3|QFE2|QFE1|QFE0|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.38 RIC2 register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31|RFFE|Receive FIFO Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b30 to b18|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b17|QFE17|Receive Queue 17 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b16|QFE16|Receive Queue 16 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b15|QFE15|Receive Queue 15 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b14|QFE14|Receive Queue 14 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b13|QFE13|Receive Queue 13 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b12|QFE12|Receive Queue 12 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b11|QFE11|Receive Queue 11 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b10|QFE10|Receive Queue 10 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b9|QFE9|Receive Queue 9 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b8|QFE8|Receive Queue 8 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b7|QFE7|Receive Queue 7 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|

**Table 45.38 RIC2 register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b6|QFE6|Receive Queue 6 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b5|QFE5|Receive Queue 5 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b4|QFE4|Receive Queue 4 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b3|QFE3|Receive Queue 3 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b2|QFE2|Receive Queue 2 (Stream) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b1|QFE1|Receive Queue 1 (Network Control) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b0|QFE0|Receive Queue 0 (Best Effort) Full Interrupt Enable|
|||0: Disabled|
|||1: Enabled|

RFFE Receive FIFO Full Interrupt Enable Bit

When the reception FIFO is full and the interrupt is enabled, the interrupt is issued.

QFE0 to 17 Receive Queue 0 to 17 Full Interrupt Enable Bits

When a reception queue is full and the interrupt is enabled, the interrupt is issued.

## 45.2.35 Receive Interrupt Status Register 2 (RIS2)

The RIS2 register indicates the states of the AVB-DMAC receive interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||RFFF|—|—|—|—|—|—|—|—|—|—|—|—|—|QFF17|QFF16|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||QFF15|QFF14|QFF13|QFF12|QFF11|QFF10|QFF9|QFF8|QFF7|QFF6|QFF5|QFF4|QFF3|QFF2|QFF1|QFF0|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.39 RIS2 register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31|RFFF|Receive FIFO Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending|
|b30 to b18|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b17|QFF17|Receive Queue 17 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b16|QFF16|Receive Queue 16 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b15|QFF15|Receive Queue 15 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b14|QFF14|Receive Queue 14 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b13|QFF13|Receive Queue 13 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b12|QFF12|Receive Queue 12 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b11|QFF11|Receive Queue 11 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b10|QFF10|Receive Queue 10 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b9|QFF9|Receive Queue 9 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b8|QFF8|Receive Queue 8 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b7|QFF7|Receive Queue 7 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|

**Table 45.39 RIS2 register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b6|QFF6|Receive Queue 6 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b5|QFF5|Receive Queue 5 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b4|QFF4|Receive Queue 4 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b3|QFF3|Receive Queue 3 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b2|QFF2|Receive Queue 2 (Stream) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b1|QFF1|Receive Queue 7 (Network Control) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b0|QFF0|Receive Queue 0 (Best Effort) Full Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|

## RFFF Receive FIFO Full Interrupt Status Bit

This bit indicates that a frame was received but storing it was not possible due to the reception FIFO being full.

When receiving a frame is not possible, the frame will be discarded.

Other information regarding discarded frames is not retained. Even if the frame is not discarded, this bit may also be set to 1 if the E-MAC determines that the frame is an error frame

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

The bit is set to 1 when the reception FIFO cannot hold received data.

## QFF0 to 17 Receive 0 to 17 Full Interrupt Status Bits

These bits indicate that reception queue r did not have space for storing a received frame.

A reception queue is treated as full when it has no descriptors (descriptor type (DESCR.DT) = FEMPTY, FEMPTY_IS, FEMPTY_IC, or FEMPTY_ND) available or reaches the set level for stopping.

## CAUTION

If no FEMPTY descriptors or no empty space for descriptors remains in the queue during storing of a divided frame (see section 45.3.4.3 (b) Divided Frames), an error frame is stored in the queue. Such error frames are treated as descriptor sequence errors.

## [Conditions for Changing]

A bit is set to 0 when the operating mode is not operation mode.

A bit is set to 1 when reception queue r has no space available for storage.

A bit is set to 1 when the unread frame counter (unread frame counter register i (UFCVi) (i = 0 to 4)) reaches the set level for stopping.

A bit is set to 1 when the unread frame counter reaches the level for stopping before the subsequent received frame is discarded.

## 45.2.36 Transmit Interrupt Control Register (TIC)

The TIC register controls the AVB-DMAC transmit interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|TFWE|TFUE|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|R|R|R|R|R|R|R|R|

## **Table 45.40 TIC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b10|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b9|TFWE|Time Stamp FIFO Warning Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b8|TFUE|Time Stamp FIFO Update Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b7 to b0|—|Reserved|
|||These bits are read as 0. The write value should be 0.|

## TFWE Time Stamp FIFO Warning Interrupt Enable Bit

When the time-stamp FIFO reaches the warning level while the interrupt is enabled, the interrupt is issued.

TFUE Time Stamp FIFO Update Interrupt Enable Bit

When the time-stamp FIFO is updated while the interrupt is enabled, the interrupt is issued.

## 45.2.37 Transmit Interrupt Status Register (TIS)

The TIS register indicates the states of the AVB-DMAC transmit interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|TFWF|TFUF|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|R|R|R|R|R|R|R|R|

**Table 45.41 TIS register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b10|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b9|TFWF|Time Stamp FIFO Warning Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The time-stamp FIFO has reached the warning level.|
|b8|TFUF|Time Stamp FIFO Update Interrupt Status|
|||0: The interrupt is not pending.|
|||1: The time-stamp FIFO has been updated.|
|b7 to b0|—|Reserved|
|||These bits are read as 0. The write value should be 0.|

## TFWF Time Stamp FIFO Warning Interrupt Status Bit

This bit indicates that the transmission time-stamp FIFO has reached the warning level.

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode and when the time stamp FIFO enable bit in the transmit configuration control register (TCCR.TFEN) is 0.

The bit is set to 1 after a frame including DESCR.TSR set has been transmitted and one entry has already been stored in the time-stamp FIFO.

## TFUF Time Stamp FIFO Update Interrupt Status Bit

This bit indicates that the transmission time-stamp FIFO has been updated.

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode, when the time stamp FIFO enable bit in the transmit configuration control register (TCCR.TFEN) is 0, and when 1 is written to the time stamp FIFO release bit in the transmit configuration control register (TCCR.TFR).

The bit is set to 1 when the time stamp FIFO enable bit (TCCR.TFEN) is 1 after a frame including DESCR.TSR set has been transmitted.

## 45.2.38 Interrupt Summary Status Register (ISS)

The ISS register gives a summary of the states of AVB-DMAC-related interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||DPS15|DPS14|DPS13|DPS12|DPS11|DPS10|DPS9|DPS8|DPS7|DPS6|DPS5|DPS4|DPS3|DPS2|DPS1|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|CGIS|RFWS|—|—|TFWS|TFUS|MS|ES|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 45.42 ISS register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31|DPS15|Descriptor Interrupt 15 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b30|DPS14|Descriptor Interrupt 14 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b29|DPS13|Descriptor Interrupt 13 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b28|DPS12|Descriptor Interrupt 12 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b27|DPS11|Descriptor Interrupt 11 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b26|DPS10|Descriptor Interrupt 10 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b25|DPS9|Descriptor Interrupt 9 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b24|DPS8|Descriptor Interrupt 8 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b23|DPS7|Descriptor Interrupt 7 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b22|DPS6|Descriptor Interrupt 6 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b21|DPS5|Descriptor Interrupt 5 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b20|DPS4|Descriptor Interrupt 4 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b19|DPS3|Descriptor Interrupt 3 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|

**Table 45.42 ISS register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b18|DPS2|Descriptor Interrupt 2 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b17|DPS1|Descriptor Interrupt 1 Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b16 to b14|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b13|CGIS|gPTP Interrupt Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b12|RFWS|Receive FIFO Warning Interrupt Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b11 to b10|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b9|TFWS|Time Stamp FIFO Warning Interrupt Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b8|TFUS|Time Stamp FIFO Update Interrupt|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b7|MS|E-MAC Interrupt Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b6|ES|Error Interrupt Summary|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b5 to b0|—|Reserved|
|||These bits are read as 0. The write value should be 0.|

## DPS1 to DPS15 Descriptor Interrupt 1 to 15 Summary Bits

These bits are set to 1 when the given descriptor interrupt enable bit (DIC.DPE1 to DPE15) and descriptor interrupt status flag (DIS.DPF1 to DPF15) are both 1.

## CGIS gPTP Interrupt Summary Bit

This bit is set to 1 when either interrupt-related bit in the two gPTP-related interrupt registers (GIC and GIS) is 1.

RFWS Receive FIFO Warning Interrupt Summary Bit

This bit is set to 1 when the receive FIFO warning interrupt enable bit (RIC1.RFWE) and receive FIFO warning interrupt status flag (RIS1.RFWF) are both 1.

TFWS Time Stamp FIFO Warning Interrupt Summary Bit

This bit is set to 1 when the time stamp FIFO warning interrupt enable bit (TIC.TFWE) and time stamp FIFO warning interrupt status flag (TIS.TFWF) are both 1.

## TFUS Time Stamp FIFO Update Interrupt Summary Bit

This bit is set to 1 when the time stamp FIFO update interrupt enable bit (TIC.TFUE) and time stamp FIFO update interrupt status flag (TIS.TFUF) are both 1.

## MS E-MAC Interrupt Summary Bit

This bit is set to 1 when an E-MAC interrupt is issued.

## ES Error Interrupt Summary Bit

This bit is set to 1 when any of the valid flags in the error interrupt status register (EIS) is 1 or the queue full error interrupt status bit (EIS.QFS) in the error interrupt status register (EIS) is 1.

## 45.2.39 gPTP Configuration Control Register (GCCR)

The GCCR register is used to set and control the gPTP (generalized precision time protocol).

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|TCSS[1:0]||—|—|LMTT|LPTC|LTI|LTO|TCR[1:0]||
|Initial value|0|0|0|0|0|0|0|0|0|0|1|1|1|1|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.43 GCCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b10|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b9, b8|TCSS[1:0]|Timer Capture Source Select|
|||00: gPTP timer value|
|||01: Adjusted gPTP timer value|
|||10: AVTP presentation time|
|||11: Setting prohibited|
|b7, b6|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b5|LMTT|Maximum Transit Time Configuration Request|
|||0: Setting completed|
|||1(W): Issue a configuration request.|
|||1(R): Completion of settings is pending.|
|b4|LPTC|Presentation Time Compare Value Configuration Request|
|||0: Setting completed|
|||1(W): Issue a configuration request.|
|||1(R): Completion of settings is pending.|
|b3|LTI|Timer Increment Value Configuration Request|
|||0: Setting completed|
|||1(W): Issue a configuration request.|
|||1(R): Completion of settings is pending.|
|b2|LTO|Timer Offset Value Configuration Request|
|||0: Setting completed|
|||1(W): Issue a configuration request.|
|||1(R): Completion of settings is pending.|
|b1, b0|TCR[1:0]|Timer Control Request|
|||00: Timer control is not requested.|
|||01: gPTP/AVPT presentation time reset|
|||10: Setting prohibited|
|||11: Captures the value set in the TCSS bit.|

## TCSS[1:0] Timer Capture Source Select Bits

These bits select the source used for updating the captured timer register (gPTP timer capture register (GCTi.CTV)).

These bits should still be controlled when timer control is not being requested (GCCR.TCR = B’00).

## LMTT Maximum Transit Time Configuration Request Bit

This bit issues requests for configuring the gPTP maximum transit time configuration register (GMTT).

Only 1 can be written to the bit.

[Conditions for Changing]

The bit is set to 1 when the operating mode is not operation mode.

The bit is set to 0 when the value of the gPTP maximum transit time configuration register (GMTT) is reflected in the gPTP timer.

LPTC Presentation Time Compare Value Configuration Request Bit

This bit issues requests for configuring the gPTP presentation time comparison register (GPTC).

Only 1 can be written to the bit.

[Conditions for Changing]

The bit is set to 1 when the operating mode is not operation mode.

The bit is set to 0 when the value of the gPTP presentation time comparison register (GPTC) is reflected in the gPTP timer.

LTI Timer Increment Value Configuration Request Bit

This bit issues requests for configuring the gPTP timer increment configuration register (GTI).

Only 1 can be written to the bit.

[Conditions for Changing]

The bit is set to 1 when the operating mode is not operation mode.

The bit is set to 0 when the value of the gPTP timer increment configuration register (GTI) is reflected in the gPTP timer.

LTO Timer Offset Value Configuration Request Bit

This bit issues requests for configuring gPTP timer offset configuration register i (GTOi).

Only 1 can be written to the bit.

[Conditions for Changing]

The bit is set to 1 when the operating mode is not operation mode.

The bit is set to 0 when the value of gPTP timer offset configuration register i (GTOi) is reflected in the gPTP timer.

## TCR[1:0] Timer Control Request Bits

These bits issue requests for controlling the gPTP timer.

Writing to the bits is only possible when the current operating mode is operation mode and the bits are B’00.

Do not write to the bit when the gPTP timer clock select bit in the AVB-DMAC mode register is B’00.

## [Conditions for Changing]

The bits are set to B’00 when the operating mode is not operation mode and on completion of the requested processing.

## 45.2.40 gPTP Maximum Transit Time Configuration Register (GMTT)

The GMTT register sets the maximum time for transitions of the gPTP timer.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||MTTV[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||MTTV[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.44 GMTT register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|MTTV[31:0]|Maximum Transit Time|
|||The maximum transition time for addition to the presentation time|

## MTTV[31:0] Maximum Transit Time Bits

These bits set the maximum transition time for use in calculating AVTP presentation times.

Write the desired setting to the bits, then issue the configuration request by setting the maximum transit time configuration request bit in the gPTP configuration control register (GCCR.LMTT) to 1.

## CAUTION

Do not write a value to these bits when the operating mode is operation mode and the maximum transit time configuration request bit (GCCR.LMTT) is 1.

## 45.2.41 gPTP Presentation Time Comparison Register (GPTC)

The GPTC register sets a value for comparison with presentation times in the gPTP timer.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||PTCV[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||PTCV[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.45 GPTC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|PTCV[31:0]|Presentation Time Comparison Value|
|||Value for comparison with the gPTP presentation times|

## PTCV[31:0] Presentation Time Comparison Value Bits

These bits set a value for comparison with AVTP timer values to which a maximum transit time is not appended.

Write the desired setting to the bits, then issue the configuration request by setting the presentation time comparison value configuration request bit in the gPTP configuration control register (GCCR.LPTC) to 1.

## CAUTION

Do not write a value to these bits when the operating mode is operation mode and the presentation time comparison value configuration request bit (GCCR.LPTC) is 1.

Do not set these bits to a value in the range from x-1 to x+1 (x is the setting value of the gPTP timer increment value bits (GTI.TIV)).

## 45.2.42 gPTP Timer Increment Configuration Register (GTI)

The GTI register sets the increment for the gPTP timer.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—||||||TIV[27:16]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||TIV[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.46 GTI register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b28|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b27 to b0|TIV[27:0]|gPTP Timer Increment Value|
|||Increment for the gPTP timer|

## TIV[27:0] Bits (gPTP Timer Increment Value)

When the gPTP clock select bits in the AVB-DMAV mode register (CCC.CSEL) are selecting a clock signal, these bits set the value by which the timer is incremented each time a cycle of that clock signal elapses.

Write the desired setting to the bits, then issue the configuration request by setting the timer increment value configuration request bit in the gPTP configuration control register (GCCR.LTI) to 1.

## CAUTION

Do not write a value to these bits when the operating mode is operation mode and the timer increment value configuration request bit (GCCR.LTI) is 1.

Do not write 0 to the bits.

## 45.2.43 gPTP Timer Offset Configuration Register i (GTOi) (i = 0 to 2)

The GTOi register sets an offset value for the gPTP timer.

The offset value is added to the combination of bits 0 to 31 in GTO0, 32 to 63 in GTO1, and 64 to 79 in GTO2, which together make up the gPTP timer.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||TOV[31+32*i:16+32*i]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||TOV[15+32*i:32*i]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.47 GTOi register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|TOV[31+32*i:32*i]|Timer Offset Value|
|||Offset value for the gPTP timer|

## TOV[79:0] Timer Offset Value Bits

This is an 80-bit value consisting of the settings in GTO0.TOV[31:0], GTO1.TOV[63:32], and GTO2.TOV[79:64], and is used to set an offset for adding to the value of the gPTP timer.

Write the desired setting to the bits, then issue the configuration request by setting the timer offset value configuration request bit in the gPTP configuration control register (GCCR.LTO) to 1.

## CAUTION

Do not write a value to these bits when the operating mode is operation mode and the timer offset value configuration request bit (GCCR.LTO) is 1.

Write H’0000 to GTO2.TOV[95:80].

Set a value in the range from 0 to 10[9] -1 (H’0000 0000 to H’3B9A C9FF) in GTO0.TOV[31:0].

## 45.2.44 gPTP Interrupt Control Register (GIC)

The GCI register is used to control gPTP-related interrupts.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|—|—|—|—|PTME|PTOE|PTCE|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|

**Table 45.48 GIC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b3|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b2|PTME|Presentation Time Match Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b1|PTOE|Presentation Time Overrun Interrupt Enable|
|||0: Disabled|
|||1: Enabled|
|b0|PTCE|Presentation Time Capture Interrupt Enable|
|||0: Disabled|
|||1: Enabled|

## PTME Presentation Time Match Interrupt Enable Bit

When this bit is 1, setting of the presentation time match interrupt flag in the gPTP interrupt status register (GIS.PTMF) to 1 leads to generation of that interrupt.

## PTOE Presentation Time Overrun Interrupt Enable Bit

When this bit is 1, setting of the presentation time overrun interrupt flag in the gPTP interrupt status register (GIS.PTOF) to 1 leads to generation of that interrupt.

## PTCE Presentation Time Capture Interrupt Enable Bit

When this bit is 1, setting of the presentation time capture interrupt flag in the gPTP interrupt status register (GIS.PTCF) to 1 leads to generation of that interrupt.

## 45.2.45 gPTP Interrupt Status Register (GIS)

The GIC register indicates the state of the gPTP-related interrupt.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|—|—|—|—|PTMF|PTOF|PTCF|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|

**Table 45.49 GIS register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b3|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b2|PTMF|Presentation Time Match Interrupt Flag|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b1|PTOF|Presentation Time Overrun Interrupt Flag|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|
|b0|PTCF|Presentation Time Capture Interrupt Flag|
|||0: The interrupt is not pending.|
|||1: The interrupt is pending.|

## PTMF Presentation Time Match Interrupt Flag Bit

This bit indicates that the value of the AVTP timer exceeds the value of the gPTP presentation time comparison register (GPTC).

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

The bit is set to 1 when the AVTP timer value is greater than or equal to the value of the gPTP presentation time comparison register (GPTC).

## PTOF Presentation Time Overrun Interrupt Flag Bit

This bit indicates that a capture event is generated before completion of the previous capture process.

Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode.

The bit is set to 0 when the presentation time capture interrupt flag bit (GIS.PTCF) is set to 0. The bit is set to 1 when a capture event is generated while the value of the presentation time capture interrupt flag bit (GIS.PTCF) is 1.

PTCF Presentation Time Capture Interrupt Flag Bit

This bit indicates that a capture event is generated. Only 0 can be written to the bit.

[Conditions for Changing]

The bit is set to 0 when the operating mode is not operation mode. The bit is set to 1 when a capture event is generated.

## 45.2.46 gPTP Presentation Time Capture Register (GCPT)

The GCPT register indicates the captured presentation time.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CPTV[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||CPTV[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 45.50 GCPT register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|CPTV[31:0]|Presentation Time Capture|
|||Presentation time value|

## CPTV[31:0] Presentation Time Capture Bits

These bits indicate the AVTP presentation time captured in response to a capture event. Read the time value from these bits and clear the presentation time capture interrupt flag bit (GIS.PTCF) before triggering a next capture.

Whether capturing a correct value was possible can be confirmed by following the procedure below.

1. Read these bits.

2. Read the presentation time overrun interrupt flag bit (GIS.PTOF).

3. Read these bits again.

4. Check whether the presentation time overrun interrupt flag bit (GIS.PTOF) is set to 1 and whether the value read from these bits has changed. If either of the two conditions is met, a correct value has not been captured.

[Conditions for Changing]

The bits are set to H’00000000 when the operating mode is not operation mode.

When a capture event occurs, the bits are updated with the AVTP presentation time value at the time of the event.

## 45.2.47 gPTP Timer Capture Register i (GCTi) (i = 0 to 2)

The GCTi registers form an 80-bit register that captures the gPTP timer value.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CTV[31+32*i:16+32*i]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||CTV[15+32*i:32*i]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 45.51 GCTi register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|CTV[31+32*i:32*i]|gPTP Timer Capture Value|
|||Captured timer value|

## CTV[79:0] gPTP Timer Capture Value Bits

These 80 bits consist of GCT0.CTV[31:0], GCT1.CTV[63:32] and GCT2.CTV[79:64], which together indicate captured timer values.

When B’00 (value of the gPTP timer) or B'01 (corrected gPTP timer value) is selected by the timer capture source select bits in the gPTP configuration control register (GCCR.TCSS), the corresponding 80-bit values are stored in GCT0.CTV[31:0], GCT1.CTV[63:32], and GCT2.CTV[79:64].

When B’10 (AVTP presentation time) is selected by the timer capture source select bit (GCCR.TCSS), the corresponding 32-bit values are stored in GCT0.CTV[31:0].

Actual writing of the timer value specified by the timer capture source select bits (GCCR.TCSS) proceeds when B’11 (timer capture request) is written to the timer control request bits in the gPTP configuration control register (GCCR.TCR).

Do not read the value while the value of the timer control request bits (GCCR.TCR) is B’11, because this indicates that storage is still in progress.

When operating mode is not operation mode, the bits are set to H’00000000.

## 45.2.48 gPTP Capture Event Control Register (GCEC)

The GCEC register sets the capture event.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22||b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—||||||DRC[10:0]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0||0|0|0|0|0|0|
|R/W|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6||b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|SCS[1:0]||—|—||—|DEN|—|—|—|CES|
|Initial value|0|0|0|0|0|0|0|0|0|0||0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|R|R||R|R/W|R|R|R|R/W|

**Table 45.52 GCEC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b27|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b26 to b16|DRC[10:0]|Division Ratio Setting|
|b15 to b10|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b9, b8|SCS[1:0]|Serial Sound Interface Channel Select|
|||00: Serial sound interface channel 0|
|||01: Serial sound interface channel 1|
|||10: Serial sound interface channel 2|
|||11: Serial sound interface channel 3|
|b7 to b5|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b4|DEN|Divider Operation Enable|
|||0: Divider operation is disabled.|
|||1: Divider operation is enabled.|
|b3 to b1|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b0|CES|Capture Event Select|
|||0: External capture event (AVB_CAPTURE pin)|
|||1: Output from the divider|

## CAUTION

Set the bits following the procedure described below. For pin control, see section 41., Ports.

- <1> Change the capture event from an external capture event (AVB_CAPTURE pin) to output from the divider.

   1. Perform pin control to disable the AVB_CAPTURE pin function.

   2. Make the setting for the serial sound interface.

   3. Set GCEC.CES to 1.

   4. Set a desired value in GCEC.SCS and GCES.DRC.

   5. Set GCEC.DEN to 1.

- <2> Change the capture event from output from the divider to the external capture event (AVB_CAPTURE pin).

   1. Set GCEC.DEN to 0.

   2. Wait for 2 cycles of output from the divider specified by GCEC.SCS and GCES.DRC.

   3. Set GCEC.CES to 0.

   4. Perform pin control to enable the AVB_CAPTURE pin function.

- <3> Switch SCS or DRC while output from the divider is selected as the capture event.

   1. Set GCEC.DEN to 0.

   2. Wait for 2 cycles of output from the divider specified by GCEC.SCS and GCES.DRC.

   3. Set a desired value in GCEC.SCS and GCES.DRC.

   4. Set GCEC.DEN to 1.

## DRC[10:0] Division Ratio Setting Bits

These bits set the division ratio which is used in dividing the SSIWS signal supplied from the serial sound interface by the divider.

The division ratio is “the value set in these bits + 1”.

## SCS[1:0] Serial Sound Interface Channel Select Bits

These bits select the channel of the serial sound interface which supplies the SSIWS signal to the divider.

## CAUTION

The frequency of the SSIWS signal of the selected channel must be equal to or smaller than a quarter of the clock frequency set by the gPTP clock select bits (CCC.CSEL).

## DEN Divider Operation Enable Bit

This bit sets the operating state of the divider.

Change the settings of GCEC.DRC, GCEC.SCS, GCEC.CES, and serial sound interface after setting this bit to 0.

Do not set this bit to 1 while GCEC.CES is set to 0.

CES Capture Event Select Bit

This bit sets the supply source of the capture event.

The capture event is detected on the rising edge of the signal selected by this bit.

## CAUTION

When the external capture event (AVB_CAPTURE pin) is selected, the AVB_CAPTURE pin should be held high for at least two cycles of the clock specified by the gPTP clock select bits (CCC.CSEL) to generate an external capture event.

When output from the divider is selected, perform pin control to disable the AVB_CAPTURE

pin function. For pin control, see section 41., Ports.

## 45.2.49 E-MAC Mode Register (ECMR)

ECMR is used to specify the operating mode of the E-MAC. The settings in this register are normally made in the initialization process following a reset.

The operating mode settings must not be changed while transmission or reception is enabled (i.e. while the RE or TE bit in this register is 1).

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|TRCCM|—|—|RCSC|—|DPAD|RZPF|ZPF|PFR|RXF|TXF|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R/W|R|R|R/W|R|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|RE|TE|—|—|—|DM|PRM|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R/W|R/W|R|R|R|R/W|R/W|

## **Table 45.53 ECMR register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b27|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b26|TRCCM|Counter Clear Mode|
|||0: Writing to a counter register leads to the register being cleared to 0.|
|||1: Reading from a counter register leads to the register being cleared to 0.|
|b25, b24|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b23|RCSC|Checksum Calculation|
|||0: Checksums are not automatically calculated.|
|||1: Checksums are automatically calculated.|
|b22|—|Reserved|
|||This bit is read as 0. The write value should be 0.|
|b21|DPAD|Data Padding|
|||0: Padding to make up 60 bytes is inserted in data for transmission when|
|||fewer than 60 bytes are to be transmitted.|
|||1: Padding is not inserted in data for transmission when fewer than 60 bytes|
|||are to be transmitted and the data are transmitted without being changed.|
|b20|RZPF|PAUSE Frame Reception with Time = 0|
|||0: Reception of PAUSE frames with the TIME parameter value 0 is disabled.|
|||1: Reception of PAUSE frames with the TIME parameter value 0 is enabled.|
|b19|ZPF|PAUSE Frame Usage with TIME = 0 Enable|
|||0: Control in response to and for the sending of PAUSE frames with the TIME|
|||parameter value 0 is disabled.|
|||1: Control in response to and for the sending of PAUSE frames with the TIME|
|||parameter value is 0 is enabled.|
|b18|PFR|PAUSE Frame Receive Mode|
|||0: PAUSE frames are not transferred to the AVB-DMAC.|
|||1: PAUSE frames are transferred to the AVB-DMAC.|
|b17|RXF|Operating Mode for Flow Control in Reception|
|||0: Detection of PAUSE frames is disabled.|
|||1: Flow control for the receiving port is enabled.|

**Table 45.53 ECMR register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b16|TXF|Operating Mode for Flow Control in Transmission|
|||0: Flow control for the transmitting port is disabled|
|||(PAUSE frames are not automatically transmitted).|
|||1: Flow control for the transmitting port is enabled|
|||(PAUSE frames are automatically transmitted as required).|
|b15 to b7|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b6|RE|Reception Enable|
|||0: Reception is disabled.|
|||1: Reception is enabled.|
|b5|TE|Transmission Enable|
|||0: Transmission is disabled.|
|||1: Transmission is enabled.|
|b4 to b2|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b1|DM|Full-duplex Transfer Enable|
|||0: Disables full-duplex transfer.|
|||1: Enables full-duplex transfer.|
|b0|PRM|Promiscuous Mode|
|||0: Normal operation|
|||1: Promiscuous mode operation|

## TRCCM Counter Clear Mode Bit

This bit sets the method for clearing the counter register. Refer to the descriptions of the counter registers.

## RCSC Checksum Calculation Bit

Setting this bit to 1 enables automatic calculation of checksums for data in received frames.

Only the data field of an Ethernet frame is in the scope of checksum calculation. Specifically, the checksum is calculated from the data field, which follows the length/type field and is followed by the CRC field. Calculation only involves 16-bit addition; it does not involve bit inversion.

## DPAD Data Padding Control Bit

This bit specifies padding or non-padding of data when less than 60 bytes are to be transmitted.

When this bit is set to 1, data are transmitted without padding; when it is set to 0, data are padded to make up 60-byte units for transmission.

## RZPF (PAUSE Frame Reception with Time = 0) Bit

When the RZPF bit is set to 0, received PAUSE frames with the Timer value 0 are discarded.

When the RZPF bit is set to 1, release from the transmission wait state follows reception of a PAUSE frame with the Timer value 0.

## ZPF (PAUSE Frame Usage with TIME = 0 Enable) Bit

When the ZPF bit is set to 0, the next frame to be transmitted is not transmitted until the time specified by the Timer value has elapsed.

Received PAUSE frames with the Timer value 0 are discarded.

When the ZPF bit is set to 1, if the amount of data in the reception FIFO becomes less than the setting of the receive FIFO critical level bits (RCR.RFCL) before the time specified by the Timer value elapses, a PAUSE frame with a Timer value of 0 is automatically transmitted. If the interface is in the transmission wait state, it is released from that state on receiving a PAUSE frame with a Timer value of 0.

## PFR PAUSE Frame Receive Mode Bit

This bit specifies whether PAUSE frames are transferred to the AVB-DMAC.

## RXF (Operating Mode for Flow Control in Reception) Bit

When the RXF bit is set to 1 and a PAUSE frame is received, a next frame to be transmitted is not transmitted until the time indicated by the Timer value in the PAUSE frame has elapsed. However, the transmission of a current frame is continued. The number of received PAUSE frames is also counted. For details, see section 45.2.57, PAUSE Frame Receive Counter (PFRCR) .

Setting this bit to 0 disables PAUSE frame detection.

## TXF (Operating Mode for Flow Control in Transmission) Bit

The TXF bit enables or disables flow control in transmission by the port.

Setting this bit to 0 disables PAUSE frame detection.

## RE Reception Enable Bit

If this bit is switched from reception being enabled (RE = 1) to reception being disabled (RE = 0) while a frame is being received, reception will continue until reception of that frame is completed.

## TE Transmission Enable Bit

If this bit is switched from transmission being enabled (TE = 1) to transmission being disabled (TE = 0) while a frame is being transmitted, transmission will continue until transmission of that frame is completed.

## DM Full-Duplex Transfer Enable Bit

This bit enables or disables full-duplex transfer.

## PRM Promiscuous Mode Bit

Setting the PRM bit enables all Ethernet frames to be received. All Ethernet frames means all receivable frames, irrespective of differences or enabled/disabled status (destination address, broadcast address, multicast bit, etc.).

## 45.2.50 Receive Frame Length Register (RFLR)

The RFLR register specifies the maximum length (in bytes) of frames that can be received by this LSI. Settings in this register must not be changed while reception is enabled (while the RE bit in the E-MAC mode register (EMCR) is 1).

|Bit|b31|b30|b29||b28|b27|b26<br>b25||b24<br>b23|b22||b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—||—|—|—<br>—||—<br>—|—||—|—|—|—|RFL[17:16]||
|Initial value|0|0|0||0|0|0<br>0||0<br>0|0||0|0|0|0|0|0|
|R/W|R|R|R||R|R|R<br>R||R<br>R|R||R|R|R|R|R/W|R/W|
|Bit|b15|b14|b13||b12|b11|b10<br>b9||b8<br>b7|b6||b5|b4|b3|b2|b1|b0|
||||||||||RFL[15:0]|||||||||
|Initial value|0|0|0||0|0|0<br>0||0<br>0|0||0|0|0|0|0|0|
|R/W|R/W|R/W|R/W||R/W|R/W|R/W<br>R/W||R/W<br>R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|
|||**Table 45.54**|||**RFLR register contents**|||||||||||||
|||**Bit Position**|||**Bit Name**||**Function**|||||||||||
|||b31 to b18|||—||Reserved|||||||||||
||||||||These bits||are read as 0. The write value should|||||be 0.||||
|||b17 to b0|||RFL[17:0]||Receive|Frame Length||||||||||
||||||||H’00000||to H’005EE: 1,518 bytes|||||||||
||||||||H’005EF: 1,519 bytes|||||||||||
||||||||H’005F0: 1,520 bytes|||||||||||
||||||||:||:|||||||||
||||||||H’007FF: 2,047 bytes|||||||||||
||||||||H’00800: 2,048 bytes|||||||||||
||||||||:||:|||||||||
||||||||H’01000: 4,096 bytes|||||||||||
||||||||:||:|||||||||
||||||||H’10000: 65,535 bytes|||||||||||
||||||||:||:|||||||||
||||||||H’20000||to H’3FFFF: 131,072||bytes|||||||

## RFL[17:0] Receive Frame Length Bits

Frame data described here refers to all fields from the destination address up to the CRC data. Frame contents from the destination address up to the data are actually transferred to memory. CRC data are not included in the transfer. When more data than the specified number of bytes are received, the portion of data that exceeds the specified value is discarded.

## 45.2.51 E-MAC Status Register (ECSR)

The ECSR register indicates the state of the E-MAC. The CPU can be notified of the state. For bits associated with interrupts, the interrupt can be enabled or disabled by the corresponding bit in the E- MAC Interrupt Permission Register (ECSIPR) described in section 45.2.52, E-MAC Interrupt Permission Register (ECSIPR) .

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|—|—|PFROI|—|—|—|ICD|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R/W|

**Table 45.55 ECSR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b5|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b4|PFROI|PAUSE Frame Retransmit Retry Over|
|||0: PAUSE frame retransmit retry count does not exceed the upper limit.|
|||1: PAUSE frame retransmit retry count exceeds the upper limit.|
|b3 to b1|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b0|ICD|Illegal Carrier Detection|
|||0: PHY-LSI has not detected an illegal carrier on the line.|
|||1: PHY-LSI has detected an illegal carrier on the line.|

## PFROI PAUSE Frame Retransmit Retry Over Bit

This bit indicates that retransmission count has exceeded the retransmit upper limit set in the PAUSE frame retransmission count register (TPAUSER) during PAUSE frame retransmission when the flow control is enabled.

Writing 1 to this bit clears it to 0.

## ICD Illegal Carrier Detection Bit

This bit indicates that the PHY-LSI has detected an illegal carrier on the line. If a change in the signal input from the PHY-LSI occurs in a period shorter than the software recognition period, the correct information may not be obtained. Refer to the timing specification for the PHY-LSI used.

Writing 1 to this bit clears it to 0.

## 45.2.52 E-MAC Interrupt Permission Register (ECSIPR)

The ECSIPR register enables or disables the states indicated by the ECSR register as interrupt sources. Each effective bit disables or enables interrupts corresponding to the bits in ECSR.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|—|PFROIP|—|—|—|—|ICDIP|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R|R/W|

**Table 45.56 ECSIPR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b5|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b4|PFROIP|PAUSE Frame Retransmit Interrupt Enable|
|||0: Interrupts on setting of the PFROI bit is disabled.|
|||1: Interrupts on setting of the PFROI bit is enabled.|
|b3 to b1|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b0|ICDIP|Illegal Carrier Detect Interrupt Enable|
|||0: Interrupts on setting of the ICD bit is disabled.|
|||1: Interrupt on setting of the ICD bit is enabled.|

## PFROIP PAUSE Frame Retransmit Interrupt Enable Bit

Setting this bit to 1 selects interrupt generation on setting of the PAUSE frame retransmit retry over bit (ECSR.PFROI) in the E-MAC status register to 1.

## ICDIP Illegal Carrier Detect Interrupt Enable Bit

Setting this bit to 1 selects interrupt generation on setting of the illegal carrier detection bit (ECSR.ICD) in the E-MAC status register to 1.

## 45.2.53 PHY Interface Register (PIR)

The PIR register provides a means of access to the PHY-LSI internal registers via the MII.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
||—|—|—|—|—|—|—|—|—|—|—|—|MDI|MDO|MMD|MDC|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|—|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|

**Table 45.57 PIR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b4|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b3|MDI|MII Management Data-In|
|||Indicates the level of the ET_MDIO pin.|
|b2|MDO|MII Management Data-Out|
|||Holds data for output from the ET_MDIO pin.|
|b1|MMD|MII Management Mode|
|||0: Read direction is specified.|
|||1: Write direction is specified.|
|b0|MDC|MII Management Data Clock|
|||The value set in this bit is output from the ET_MDC pin, which supplies the|
|||management data clock for the MII.|

## MDI MII Management Data-In Bit

This bit indicates the level of the ET_MDIO pin.

## MDO MII Management Data-Out Bit

This bit holds data for output from the ET_MDIO pin.

The ET_MDIO pin outputs a value set in this bit when the MMD bit is set to 1 (to specify writing as the direction). Data are not output while the MMD bit is set to 0 (to specify reading as the direction).

## MMD MII Management Mode Bit

This bit specifies the direction for data through MDIO (reading or writing).

## MDC MII Management Data Clock Bit

Values set in this bit are output on the ET_MDC pin to supply the MII with the management data clock. For the method of access to the MII registers, see section 45.3.12, Connection to PHY-LSI .

## 45.2.54 Automatic PAUSE Frame Register (APR)

The APR register is used to set the value for the TIME parameter of automatically transmitted PAUSE frames. When a PAUSE frame is automatically transmitted, the value set in this register is used as its TIME parameter.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||AP[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.58 APR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b16|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b15 to b0|AP[15:0]|Automatic PAUSE|
|||These bits set the TIME parameter value of an automatic PAUSE frame.*1|
|||H’0000: —|
|||H’0001: 512 × 1 bit-period|
|||H’0002: 512 × 2 bit-period|
|||:<br>:|
|||H’FFFF: 512 × 65535 bit-period|
|||Note 1.<br>A bit-period changes relative to the transfer speed as follows.|
|||100Mbps: 1 bit-period = 10 ns|
|||10Mbps: 1 bit-period = 100 ns|

## AP[15:0] Automatic PAUSE Bit

These bits set the value of the TIME parameter in automatically transmitted PAUSE frames. The unit for the setting is 512-bit periods.

Set these bits to a value other than H’0000 when the flow control in transmission (PAUSE frame transmission) is enabled (ECMR.TXF = 1).

## 45.2.55 Manual PAUSE Frame Register (MPR)

The MPR register is used to set the value for the TIME parameter of manually generated PAUSE frames. When a PAUSE frame is manually transmitted, the value set in this register is used as its TIME parameter.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||MP[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.59 MPR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b16|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b15 to b0|MP[15:0]|Manual PAUSE|
|||These bits set the TIME parameter value of a manual PAUSE frame.*1|
|||H’0000: —|
|||H’0001: 512 × 1 bit-period|
|||H’0002: 512 × 2 bit-period|
|||:<br>:|
|||H’FFFF: 512 × 65535 bit-period|
|||Note 1.<br>A bit-period changes relative to the transfer speed as follows.|
|||100Mbps: 1 bit-period = 10 ns|
|||10Mbps: 1 bit-period = 100 ns|

## MP[15:0] Manual PAUSE Bits

These bits set the value of the TIME parameter in manually generated PAUSE frames. The unit for the setting is 512 bit periods.

## 45.2.56 PAUSE Frame Transmit Counter (PFTCR)

The PFTCR register is a counter that indicates the number of times PAUSE frames have been transmitted.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||PFTXC[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 45.60 PFTCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b16|—|Reserved|
|||These bits are read as 0.|
|b15 to b0|PFTXC[15:0]|PAUSE Frame Transmit Counter|
|||Counter for counting the number of transmitted PAUSE frames|

## PFTXC[15:0] PAUSE Frame Transmit Counter Bits

These bits indicate the total number of PAUSE frames that have been transmitted (both manually and automatically).

The bits are cleared to 0 when they are read.

If counting up and clearing of the counter coincide, clearing the counter takes priority.

## 45.2.57 PAUSE Frame Receive Counter (PFRCR)

The RFRCR register is a counter that indicates the number of times PAUSE frames have been received.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||PFRXC[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 45.61 RFRCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b16|—|Reserved|
|||These bits are read as 0.|
|b15 to b0|PFRXC[15:0]|PAUSE Frame Receive Counter|
|||Counter for counting the number of received PAUSE frames|

## PFRXC[15:0] PAUSE Frame Receive Counter Bits

These bits indicate the number of PAUSE frames that have been received when flow control in reception is enabled (the RXF bit in ECMR = 1).

The bits are cleared to 0 when they are read.

If counting up and clearing the counter coincide, clearing the counter takes priority.

## 45.2.58 Automatic PAUSE Frame Retransmission Count Register (TPAUSER)

The TPAUSER register sets the upper limit of automatic PAUSE frame retransmission count.

|Bit|b31|b30|b29||b28|b27|b26|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—||—|—||—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R||R|R||R|R|R|R|R|R|R|R|R|R|R|
|Bit|b15|b14|b13||b12|b11|b10||b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||||TPAUSE[15:0]|||||||||
|Initial value|0|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W||R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||**Table 45.62**|||**TPAUSER register contents**||||||||||||||
|||**Bit Position**|||**Bit Name**|||**Function**|||||||||||
|||b31 to b16|||—|||Reserved|||||||||||
|||||||||These bits are read as 0.|||||||||||
|||b15 to b0|||TPAUSE[15:0]|||Automatic PAUSE Frame Retransmission Count|||||||Upper Limit||||
||||||||||H’0000: No limitation||||||||||
||||||||||H’0001: Once||||||||||
||||||||||:|:|||||||||
||||||||||H’FFFF: 65535 times||||||||||

TPAUSE[15:0] Automatic PAUSE Frame Retransmission Count Upper Limit Bits

The bits set the upper limit of automatic PAUSE frame retransmission count.

The setting in the bits must not be changed while transmission is enabled (EMCR.TE = 1).

## 45.2.59 MAC Address High Register (MAHR)

The MAHR register specifies the 32 higher-order bits of the 48-bit MAC address. The settings in this

register are normally made in the initialization process after a reset.

The settings in this register must not be changed while transmission or reception is enabled.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||MA[47:32]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||MA[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.63 MAHR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|MA[47:16]|MAC Address Bits 47 to 16|
|||These bits are used to set the 32 higher-order bits of the MAC address.|

## MA[47:16] MAC Address Bits 47 to 16

These bits are used to set the 32 higher-order bits of the MAC address.

For example, if the MAC address is 01-23-45-67-89-AB (hexadecimal), set H’0123 4567 in the MAHR register.

## 45.2.60 MAC Address Low Register (MALR)

The MALR register specifies the 16 lower-order bits of the 48-bit MAC address. The settings in this register are normally made in the initialization process after a reset.

The settings in this register must not be changed while transmission or reception is enabled.

**==> picture [491 x 137] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit b31 b30 b29 b28 b27 b26 b25 b24 b23 b22 b21 b20 b19 b18 b17 b16<br>— — — — — — — — — — — — — — — —<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>Bit b15 b14 b13 b12 b11 b10 b9 b8 b7 b6 b5 b4 b3 b2 b1 b0<br>MA[15:0]<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W<br>**----- End of picture text -----**<br>

## **Table 45.64 MALR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b16|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|b15 to b0|MA[15:0]|MAC Address Bits 15 to 0|
|||These bits are used to set the 16 lower-order bits of the MAC address.|

## MA[15:0] MAC Address Bits 15 to 0

These bits are used to set the 16 lower-order bits of the MAC address.

For example, if the MAC address is 01-23-45-67-89-AB (hexadecimal), set H'89AB in the MALR register.

## 45.2.61 CRC Error Frame Receive Counter Register (CEFCR)

The CEFCR register is a counter that indicates the number of times frames with CRC errors were received. Counting up stops when the value in this register reaches H’FFFF FFFF.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CEFC[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||CEFC[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.65 CEFCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|CEFC[31:0]|CRC Error Frame Counter|
|||These bits indicate the number of CRC error frames received.|

## CEFC[31:0] CRC Error Frame Counter Bits

These bits indicate the number of received frames having CRC errors.

The bits are cleared to 0 when they are read while the counter clear mode bit (TRCCM) in the E-MAC mode register is set to 1.

When TRCCM = 0, they are cleared to 0 by the writing of any value to this register.

## 45.2.62 Frame Receive Error Counter Register (FRECR)

The FRECR register is a counter that indicates the number of frames for which receive errors were generated by input on the ET_RXER pin from the PHY-LSI. Counting up stops when the value in this register reaches H’FFFF FFFF.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||FREC[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||FREC[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.66 FRECR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to 0|FREC[31:0]|Frame Receive Error Counter|
|||These bits indicate the number of errors during frame reception.|

## FREC[31:0] Frame Receive Error Counter Bits

These bits indicate the number of errors during frame reception.

The bits are cleared to 0 when they are read while the counter clear mode bit (TRCCM) in the E-MAC mode register is set to 1.

When TRCCM = 0, they are cleared to 0 by the writing of any value to this register.

## 45.2.63 Too-Short Frame Receive Counter Register (TSFRCR)

The TSFRCR register is a counter that indicates the number of received frames that were fewer than 64 bytes in length. Counting stops when the value in this register reaches H’FFFF FFFF.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||TSFRC[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||TSFRC[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.67 TSFRCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|TSFRC[31:0]|Too-Short Frame Receive Counter|
|||These bits indicate the number of frames received with a length of less than 64|
|||bytes.|

## TSFRC[31:0] Too-Short Frame Receive Counter Bits

These bits indicate the number of received frames that were fewer than 64 bytes in length.

The bits are cleared to 0 when they are read while the counter clear mode bit (TRCCM) in the E-MAC mode register is set to 1.

When TRCCM = 0, they are cleared to 0 by the writing of any value to this register.

## 45.2.64 Too-Long Frame Receive Counter Register (TLFRCR)

The TLFRCR register is a counter that indicates the number of received frames that were longer than the value specified in the receive frame length register (RFLR). Counting up stops when the value in the TLFRCR register reaches H’FFFF FFFF.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||TLFC[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||TLFC[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.68 TLFRCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|TLFC[31:0]|Too-Long Frame Receive Counter|
|||These bits indicate the number of frames received with a length exceeding the|
|||value in RFLR.|

## TLFC[31:0] Too-Long Frame Receive Counter Bits

These bits indicate the number of received frames that were longer than the value in RFLR.

The bits are cleared to 0 when they are read while the counter clear mode bit (TRCCM) in the E-MAC mode register is set to 1.

When TRCCM = 0, they are cleared to 0 by the writing of any value to this register.

## 45.2.65 Residual-Bit Frame Receive Counter Register (RFCR)

The RFCR register is a counter that indicates the number of received frames containing “residual bits” (trailing bits not making up an 8-bit unit). Counting up stops when the value in this register reaches H’FFFF FFFF.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||RFC[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||RFC[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 45.69 RFCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|RFC[31:0]|Residual-Bit Frame Receive Counter|
|||These bits indicate the number of received frames containing residual bits.|

RFC[31:0] Residual-Bit Frame Receive Counter Bits

These bits indicate the number of received frames containing residual bits.

The bits are cleared to 0 when they are read while the counter clear mode bit (TRCCM) in the E-MAC mode register is set to 1.

When TRCCM = 0, they are cleared to 0 by the writing of any value to this register.

## 45.2.66 Multicast Address Frame Receive Counter Register (MAFCR)

The MAFCR register is a counter that indicates the number of received frames for which a multicast address was specified. Counting up stops when the value in this register reaches H’FFFF FFFF.

|Bit|b31|b30|b29|b28|b27|b26|b25|b24|b23|b22|b21|b20|b19|b18|b17|b16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||MAFC[31:16]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|b15|b14|b13|b12|b11|b10|b9|b8|b7|b6|b5|b4|b3|b2|b1|b0|
|||||||||MAFC[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 45.70 MAFCR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b0|MAFC[31:0]|Multicast Address Frame Counter|
|||These bits indicate the number of multicast frames that have been received.|

## MAFC[31:0] Multicast Address Frame Counter Bits

These bits indicate the number of multicast frames that have been received.

The bits are cleared to 0 when they are read while the counter clear mode bit (TRCCM) in the E-MAC mode register is set to 1.

When TRCCM = 0, they are cleared to 0 by the writing of any value to this register.

## 45.3 Operation

The EthernetAVB consists of the following functional units:

- DMA transfer controller (AVB-DMAC): Handles DMA transfer between the data storage areas for reception and transmission in the on-chip RAM and the reception and transmission FIFO buffers

- MAC controller (E-MAC): Handles transfer between the reception and transmission FIFO buffers and the MII

Using its direct memory access (DMA) function, the AVB-DMAC handles DMA transfer of frame data between the destinations for storing Ethernet frame data for transmission and reception in the on-chip RAM and the FIFO buffers for reception and transmission. Data cannot be directly read from or written to the FIFO buffers.

To handle DMA transfer, the AVB-DMAC requires information that includes the addresses for storage of data for transmission and received data. These data are referred to as descriptors. The AVB-DMAC reads data for transmission from the storage area for data to be transmitted according to the information in descriptors and writes received data to the storage area for received data accompanied by information in descriptors. The descriptors are placed in the on-chip RAM. Arranging multiple descriptors in descriptor lists allows the continuous reception or transmission of multiple Ethernet frames.

The E-MAC supports an MII, which provides an interface format for the externally connected PHYLSI. The E-MAC constructs Ethernet frames from data written to the transmission FIFO and transmits these frames to the MII. It also performs CRC checking of Ethernet frames received from the MII and writes the frames to the reception FIFO.

## 45.3.1 AVB-DMAC Operating Modes

Figure 45.5 illustrates the operating modes of the AVB-DMAC.

Transitions of AVB-DMAC operating mode are under the control of the items listed below.

- CPU operating mode (power-on reset)

- Configuration of the operating mode configuration bits (CCC.OPC) in the AVB-DMAC mode register

The current operating mode can be determined by reading the operating mode status bits in the AVBDMAC status register (CSR.OPS).

**==> picture [386 x 223] intentionally omitted <==**

**----- Start of picture text -----**<br>
Configuration mode<br>No transmission/reception in progress<br>Power-on reset Configuration<br>Reset Configuration Operation<br>Operation<br>Transition due to software (CCC.OPC)<br>Standby<br>RESET<br>Standby<br>Configuration<br>**----- End of picture text -----**<br>

**Figure 45.5 Operating Mode of AVB-DMAC**

## 45.3.1.1 Operating Modes

- (1) Reset mode

After a power-on reset, the AVB-DMAC enters reset mode.

In reset mode, only the AVB-DMAC operating mode control function is controllable and other functions are all stopped. This mode is designed for reduced power when the Ethernet function is not necessary.

- (2) Configuration mode

In configuration mode, various settings for the AVB-DMAC can be made.

The operation of most functions is stopped and all status registers are initialized to their reset values.

The E-MAC functions in this mode.

- (3) Operation mode

In operation mode, all functions of the AVB-DMAC can operate.

Ethernet communications can only proceed in this mode.

- (4) Standby mode

In standby mode, only the operating mode control function and E-MAC can be used. Other functions cannot be used.

## 45.3.1.2 How to Set the Operating Mode

Set the operating mode configuration bits in the AVB-DMAC status register (CSR.OPC) to select the operating mode. Furthermore, the current operating mode can be checked by reading the operating mode status bits in the AVB-DMAC status register (CSR.OPS).

Transitions other than from operation mode to configuration mode are made after the value is written to the operating mode configuration bits (CCC.OPC) ( Figure 45.6 ).

For transitions from operation mode to configuration mode, follow the procedure in Figure 45.7 because any transmission and reception in progress will be executed before the transition to configuration mode.

**==> picture [324 x 315] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Yes<br>Is the current operating mode operation mode and the mode<br>to be set reset mode?<br>No Data transfer suspend request<br>(CCC.DTSR = 1)<br>Wait until the data transfer suspend request has<br>been reflected (CSR.DTS = 1).<br>Set the operating mode.<br>No<br>Check the operating mode.<br>Yes<br>Error processing<br>End<br>**----- End of picture text -----**<br>

**Figure 45.6 Flow for Transitions of Operating Mode (Other than from Operation Mode to Configuration Mode)**

**==> picture [277 x 271] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Disable the reception function<br>of the E-MAC (ECMR.RE = 0)<br>and stop the software task that is<br>generating data for transmission. Specify operation mode<br>(CCC.OPC = 2).<br>Wait until transmission and reception<br>in progress have been completed<br>(CSR.RPO = 0 and CSR.TPO0 to  Release data transfer from suspension<br>CSR.TPO3 = 0). (CCC.DTSR = 0).<br>Capture all of the required  Wait until reception in progress<br>status information. has been completed (CSR.RPO = 0).<br>Request suspension of data transfer  Request suspension of data transfer<br>(CCC.DTSR = 1) and wait until the  (CCC.DTSR = 1) and wait until the<br>data transfer suspend request  data transfer suspend request<br>has been reflected (CSR.DTS = 1). has been reflected (CSR.DTS = 1).<br>Specify configuration mode  Specify configuration mode<br>(CCC.OPC = 1). (CCC.OPC = 1).<br>Check for completion  No Check for completion  No<br>of the transition to configuration mode  of the transition to configuration mode<br>(CSR.OPS = 2). (CSR.OPS = 2).<br>Yes Yes Error processing<br>End<br>**----- End of picture text -----**<br>

**Figure 45.7 Flow for Transitions of Operating Mode (from Operation Mode to Configuration Mode)**

In the transition from operation mode to configuration mode, the AVB-DMAC executes the following operations before the transition is completed. Read the operating mode status bits in the AVB-DMAC status register (CSR.OPS) to check that the transition to configuration mode has been completed.

- If the transfer of a frame between the reception FIFO and on-chip RAM is in progress, this is completed

   - (other received frames remaining in the FIFO and any frames that are subsequently received by the E-MAC are discarded).

- If the transfer of a frame is in progress between the transmission FIFO and on-chip RAM, this is completed

   - (frames for transmission remaining in the on-chip RAM will not be transmitted).

- All frames for transmission in the transmission FIFO are transferred to the E-MAC.

## Notes:

When the operating mode shifts to configuration mode, all status registers are cleared.

We recommend following the procedure below in the case of this transition.

1. Disable reception.

2. Since reception actually stopping after being disabled requires time, wait for an interval equivalent to that for reception of a maximum length packet.

3. Stop the software task that is generating data for transmission.

4. Wait until the receive process status bit (CSR.RPO) and the transmit process status bits (CSR.TPO0 to 3) in the AVB-DMAC status register are set to 0.

5. Capture all of the required status information.

6. Set the operating mode configuration bits in the AVB-DMAC mode register (CCC.OPC) to initiate the transition to configuration mode.

## 45.3.1.3 Operating Mode Transitions Due to Hardware

The following hardware factors can also initiate transitions of the AVB-DMAC operating mode.

- (1) Power-on reset

Resetting of the LSI chip leads to resetting of the entire EthernetAVB module. The operating mode shifts to reset mode.

## 45.3.2 Common Control for Transmission and Reception

## 45.3.2.1 Initialization Procedure

Figure 45.8 shows the overall initialization procedure in outline.

**==> picture [171 x 256] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Transition to configuration mode from reset mode<br>Settings for E-MAC<br>(disabling transmission and reception)<br>Settings for AVB-DMAC<br>Transition to operation mode<br>from configuration mode<br>Settings for E-MAC<br>(enabling transmission and reception)<br>End<br>**----- End of picture text -----**<br>

**Figure 45.8 Outline of the Initialization Procedure**

- (1) Initializing the Receiver Section

Before starting reception, follow the procedure below.

Set the operating mode to operation mode or standby mode, and do not enable reception until the settings for the AVB-DMAC are completed.

- Set the operating mode to configuration mode.

- Set AVB filtering for network control frames and AVB stream frames to suit the specifications of the product the chip will be used in.

- Create a descriptor chain for each queue to be used.

- Set the base address for the descriptor table in the descriptor base address table register (DBAT).

- Specify the maximum frame length with the receive frame length upper limit register (RFLR).

- Specify whether padding is to be used with the receive padding configuration register (RPC).

- Set the unread frame counter for each queue with unread frame counter registers 0 to 4.

## (2) Initializing the Transmitter Section

Figure 45.9 illustrates initialization of the transmitter section.

**==> picture [300 x 384] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Set the transmit configuration<br>register (TGC) and transmit configuration<br>control register (TCCR).<br>Set the transmit queue priority<br>(TGC.TQP[1:0]).<br>Yes<br>AVB mode? Set the CBS parameters<br>for SR traffic class.<br>No<br>Set the descriptor base<br>address table register.<br>Initialize the E-MAC<br> (see Figure 45.10).<br>End<br>**----- End of picture text -----**<br>

**Figure 45.9 Procedure for Initializing the Transmitter Section**

## (3) Initializing the E-MAC Section

Figure 45.10 illustrates initialization of the E-MAC section.

**==> picture [104 x 286] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Enable full-duplex<br>transfer function.<br>Disable Pause<br>Frame.<br>Disable filtering<br>of AVB addresses<br>(see the AVB specification).<br>Enable address<br>filter processing<br>and interrupts<br>for each application.<br>End<br>**----- End of picture text -----**<br>

**Figure 45.10 Procedure for Initializing the E-MAC Section**

## (4) Initialization of the AVB-DMAC Unit

Figure 45.11 illustrates initialization of the AVB-DMAC unit.

For a description of how to set up the descriptors and the CBS, see section 45.3.3, Descriptors , and section 45.3.6, CBS (Credit-Based Shaping) .

**==> picture [104 x 409] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Construct the descriptors.<br>Set descriptor pointers<br>for transmission and reception.<br>Set the gPTP timer.<br>Set the time stamp for<br>transmission and reception.<br>Set the stream traffic type<br>(default is best effort) and<br>AVB filter options<br>for special control.<br>Set CBS.<br>Set priority order<br>for traffic classes.<br>End<br>**----- End of picture text -----**<br>

**Figure 45.11 Procedure for Initializing the AVB-DMAC Unit**

## 45.3.2.2 Scheduling Reception and Transmission

The EthernetAVB normally has independent buses for transmission and reception. Furthermore, the four processes of fetching, storing, transmission and reception are basically independent of one another. Fetching and storing, however, share the same bus master so cannot be executed simultaneously. Access to the bus master is controlled by the scheduler.

Figure 45.12 is a schematic view of EthernetAVB operations in transmission and reception.

**==> picture [377 x 254] intentionally omitted <==**

**----- Start of picture text -----**<br>
Priority for<br>transmission FIFO<br>access<br>North main  EthernetAVB Transmission FIFO<br>bus<br>Arbiter<br>Master Slave Master<br>Data for transmission<br>Fetching  Transmission<br>process process<br>Buffer Scheduler E-MAC<br>Slave AVB Message Handler<br>Storage<br>process Reception<br>process<br>Slave Data for reception<br>Master<br>Master<br>Bus Master<br>Arbiter<br>Reception FIFO Both transmission and reception<br>processes are independent of<br>other processes and are NOT<br>Priority for handled by the scheduler.<br>Only one process active at a time, reception FIFO<br>either Fetch or Store. Scheduler access<br>controls these processes.<br>section Transmitter<br>section Receiver<br>**----- End of picture text -----**<br>

**Figure 45.12 Schematic View of EthernetAVB Operations in Transmission and Reception**

Storing and fetching are alternately performed. When the number of frames held by the reception FIFO reaches the warning level, storing takes precedence over fetching.

- (1) Relationship between Transmission Queue Numbers and Traffic Classes

In fetching, the relationships between the transmission queues and traffic classes are fixed, so the priority specified by the transmit queue priority bits in the transmit configuration register (TGC.TQP) has no effect.

**==> picture [389 x 118] intentionally omitted <==**

**----- Start of picture text -----**<br>
On-chip RAM AVBMH SFR<br>Q3<br>SR class A frame TCCR.TSRQ3<br>Q2<br>SR class B frame TCCR.TSRQ2<br>Q1<br>NC frame TCCR.TSRQ1<br>Q0<br>BE frame TCCR.TSRQ0<br>**----- End of picture text -----**<br>

**Figure 45.13 Class Associations of Queues for the Scheduler**

In fetching, the credit values for stream classes A and B are not taken into account. Behavior depends on the setting of the transfer FIFO size configuration bits in the transfer configuration registers (TGC.TBDt).

When the transmit queue priority bits in the transmit configuration register (TGC.TQP) are B’00 or B'01, the priority order is Q3 → Q 2 → Q1 → Q0.

When the transmit queue priority bits in the transmit configuration register (TGC.TQP) are B’11, the priority order is Q1 → Q3 → Q2 → Q0.

## 45.3.2.3 Checking Integrity

The EthernetAVB is capable of detecting and identifying errors produced in the processing of Ethernet frames and in the transfer of frame data for transmission and reception.

- (1) Items for Monitoring in Both Reception and Transmission

   - (a) Errors in access to the on-chip RAM for reading of descriptors

   - The error type bits (ESR.ET) are set to B’0000, and the queue number being processed is set to the error queue number bits (ESR.EQN).

   - The same descriptor may be processed again because the current descriptor address (CDARq.CDA) was not changed.

   - If this problem occurs in a divided frame, the sequence may be broken.

## In reception

- The received frame will be lost.

- The same problem will occur for the next frame of data received for the same queue.

## In transmission

- The transmit start request bit in the transmit configuration control register (TCCR.TSRQt) is set to 0.

- The frame will be lost from the transmission FIFO.

- (b) Illegal configuration of a descriptor

- The error type bits (ESR.ET) are set to B’0010, and the queue number being processed is set to the error queue number bits (ESR.EQN).

- The same descriptor may be processed again because the current descriptor address (CDARq.CDA) was not changed.

- If this problem occurs in a divided frame, the sequence may be broken.

## In reception

- The received frame will be lost.

- The same problem will occur for the next frame of data received for the same queue.

## In transmission

- The transmit start request bit in the transmit configuration control register (TCCR.TSRQt) is set to 0.

- The frame will be lost from the transmission FIFO.

- (c) Errors in access to the on-chip RAM for writing of descriptors

- The error type bits (ESR.ET) are set to B’0001, and the queue number being processed is set to the error queue number bits (ESR.EQN).

- As in the case where no error occurs, the current descriptor address (CDARq.CDA) and the transmit start request bit in the transmit configuration control register (TCCR.TSRQt) are updated.

   - As DESCR.DT was not updated, hardware and software synchronization may have been lost.

- (2) Items for Monitoring in Reception

   - (a) Errors in access to the on-chip RAM for writing of data or time stamps

   - The error type bits (ESR.ET) are set to B’0101, and the queue number being processed is set to the error queue number bits (ESR.EQN).

   - As in the case where no error occurs, the current descriptor address (CDARq.CDA) is updated.

   - DESCR.EI is set to 1 to indicate error detection.

   - This problem occurring in a divided frame may break the descriptor sequence, making the queue unusable.

   - (b) Overflow of the Reception FIFO

   - The reception FIFO full interrupt status bit (RIS2.RFFF) is set to 1.

   - The received frames are all invalidated. The frames stored in the reception FIFO must be discarded according to the following procedure.

   1. Stop reception and enter configuration mode according to the flow shown in **Figure 45.7, Flow for Transitions of Operating Mode (from Operation Mode to Configuration Mode)** .

   2. Discard all the unprocessed received data stored in the on-chip RAM.

- (3) Items for Monitoring in Transmission

   - (a) Errors in Access for Reading Data from the on-chip RAM

   - The error type bits (ESR.ET) are set to B’0100, and the queue number being processed is set to the error queue number bits (ESR.EQN).

   - Data that have already been fetched are discarded from the transmission FIFO.

   - When an error of this type occurs during processing of an FSINGLE or FEND descriptor: As in the case where no error occurs, the current descriptor address (CDARq.CDA) and the transmit start bit in the transmit configuration control register (TCCR.TSRQt) are updated. Fetching resumes after the error frame.

   - When an error of this type occurs during processing of an FSTART or FMID descriptor:

      - The current descriptor address (CDARq.CDA) is not updated.

      - The transmit start bit in the transmit configuration control register (TCCR.TSRQt) is set to 0.

   - (b) Overflow of the Transmission FIFO

   - The error type bits (ESR.ET) are set to B’1010, and the queue number being processed is set to the error queue number bits (ESR.EQN).

   - As in the case where no error occurs, the current descriptor address (CDARq.CDA) and the transmit start bit in the transmit configuration control register (TCCR.TSRQt) are updated. Fetching resumes after the error frame.

   - The frame will be discarded from the FIFO.

   - (c) Frame size error during transmission

   - The error type bits (ESR.ET) are set to B’1001, and the queue number being processed is set to the error queue number bits (ESR.EQN).

   - As in the case where no error occurs, the current descriptor address (CDARq.CDA) and the transmit start bit in the transmit configuration control register (TCCR.TSRQt) are updated. Fetching resumes after the error frame.

A transmit frame size error is detected when the size setting in one or more (in the case of a divided frame) descriptors for frame transmission is more than 1996 bytes. Such frames are cut out and transmitted.

## 45.3.3 Descriptors

## 45.3.3.1 Data Representation in On-chip RAM

The AVB-DMAC transfers data for transmission and received data to and from the application software via the on-chip RAM.

Control structures referred to as descriptors and the frame data referred to as descriptor data area are allocated to the on-chip RAM. Dividing into a control area and data area allows the flexible allocation of frame data to the on-chip RAM.

Figure 45.14 shows an example of the memory maps for descriptors and the descriptor data area in the on-chip RAM.

A descriptor consists of its type (DESCR.DT), which controls the descriptor functions, a descriptor pointer (DESCR.DPTR) indicating the start address for storage of the frame data in the descriptor area, and the data size field (DESCR.DS), indicating the amount of frame data. Post-processing interrupt generation can be set up for each descriptor. Enabling and disabling of the interrupt is controlled by the descriptor interrupt enable bits (DESCR.DIE).

The descriptor may also hold information related to content. This information does not affect general descriptor functions. It provides information other than the frame data proper, such as on the state of reception.

For details, see section 45.3.4.2, Setting Up Reception Descriptors , and section 45.3.5.2, Setting Up Transmission Descriptors .

**==> picture [335 x 187] intentionally omitted <==**

**----- Start of picture text -----**<br>
Descriptor address<br>Descriptor type (DT)<br>Frame data<br>Descriptor pointer (DPTR)<br>Data size (DS)<br>Descriptor interrupt enable (DIE)<br>Content control (...)<br>Descriptor<br>Unused<br>Descriptor data area<br>On-chip RAM<br>**----- End of picture text -----**<br>

**Figure 45.14 Example of On-chip RAM Memory Map**

The descriptor must be aligned with a 32-bit boundary in the on-chip RAM.

Descriptors are generally configured of 64 bits, but are configured of 160 bits when reception and storage of gPTP time stamps is enabled.

The frame data must also be aligned with a 32-bit boundary in the on-chip RAM.

The amount of data in the frame is defined by the data size bits (DESCR.DS). In reception, these bits indicate the upper limit on the size of frames to be received. If the data size is not aligned with a 32-bit boundary, the bytes to the next 32-bit boundary in the data area will be an unused area.

## 45.3.3.2 Using Descriptor Chains in Queues

Transmission and reception descriptors in the on-chip RAM are grouped into queues. Each queue handles frames so that they are transmitted in order of priority and received separately. A queue is capable of controlling one or more frames. Accordingly, multiple descriptors can be assigned to one queue. A combination of multiple descriptors is referred to as a descriptor chain.

For a descriptor chain, the three general descriptor types listed below are defined. For details on these descriptor types, see section 45.3.3.6, Descriptor Type .

- Descriptors that define frame data

- Descriptors that control the descriptor chain itself (e.g. LINK, EOS).

- Descriptors that arbitrate access by hardware or software

Figure 45.15 shows the two basic topologies for descriptor chains. In the simplified examples in the figure, all descriptors allocated to the chain are stored in the array.

- For a linear descriptor chain, the last descriptor in the array is a control descriptor indicating the end of the descriptors (e.g. EEMPTY).

- For a cyclic descriptor chain, the last descriptor in the array is a control descriptor that returns to the first descriptor in the array (e.g. LINK).

**==> picture [248 x 104] intentionally omitted <==**

**----- Start of picture text -----**<br>
Linear descriptor chain Cyclic descriptor chain<br>Base of chain Base of chain<br>.... ....<br>End Link<br>**----- End of picture text -----**<br>

## **Figure 45.15 Outline of the Basic Descriptor Chains**

The relationship between queues and descriptor chains is defined by the base addresses of chains. A queue is connected to one descriptor chain over one round of processing. There is also a method of switching to a different chain while in operation mode.

There are no restrictions on the number of link descriptors and their locations within the chain. The last descriptor of a designed chain determines the topology.

Which chain structure is to be used or which topology is suitable depends on the application. A description of how to design descriptor chains to suit various applications is given in section 45.3.4.2, Setting Up Reception Descriptors . Procedure for Setting Reception Descriptors, and section 45.3.5.2, Setting Up Transmission Descriptors .

## 45.3.3.3 Descriptor Base Address Table

The base address table in the on-chip RAM contains the address of the first descriptor of all chains to be handled by the respective queues.

Entries 0 to 3 are used to access transmission queues 0 to 3. Subsequent entries are used to access reception queues. Entry 4 thus corresponds to reception queue 0.

The configuration of entries in the base address table is the same as the configuration of link descriptors. We recommend using the descriptor type (DESCR.DT) LINKFIX. Processing of this link descriptor does not change it, so it does not require updating. The first descriptor of a chain performs hardware and software synchronization. If the application requires hardware and software synchronization for the base addresses, use the descriptor type (DESCR.DT) LINK.

The CPU is only capable of using LINKFIX and LINK as descriptor types (DESCR.DT) of descriptors in the base address table.

Set the location of the base address table in the on-chip RAM in the descriptor base address table register (DBAT).

Figure 45.16 shows an example of a base address table for controlling four transmission and three reception queues. The boxes to the right of the table represent descriptor chains with the desired topologies.

**==> picture [296 x 138] intentionally omitted <==**

**----- Start of picture text -----**<br>
Base address table (DBAT.TA)<br>+ 00h LINKFIX Base of chain Tx queue 0<br>+ 08h LINKFIX<br>+ 10h LINKFIX Tx queue 0<br>+ 18h LINKFIX<br>+ 20h LINKFIX Tx queue 2<br>+ 28h LINKFIX<br>+ 30h LINKFIX Tx queue 3<br>Rx queue 0<br>Rx queue 1<br>Rx queue 2<br>**----- End of picture text -----**<br>

**Figure 45.16 Example of a Base Address Table for Reception and Transmission Queues**

## CAUTION

The size of the descriptors in the base address table is always eight bytes even if the queue itself includes extended descriptors.

## 45.3.3.4 Descriptor Chain Processing

When a descriptor is currently being processed or the queue for a descriptor is active, the current descriptor is a descriptor to be processed. The current descriptor address for use by a queue q can be checked in the current descriptor address register q (CDARq).

Current descriptors are:

- set in the descriptor base table address bits (DBAT.TA) +8*q for all q queues when the operating mode shifts to operation mode.

- set in the descriptor base table address bits (DBAT.TA) +8*q when a base address load request is issued for a queue q by setting the corresponding bit (DLR.LBAq) in the descriptor base address load request register (DLR).

- set in DESCR.DPTR for a link descriptor (LINK, LINKFIX) to be processed.

- incremented by the size of the descriptors (8 bytes for normal descriptors and 20 bytes for extended descriptors) after a descriptor has been processed. In this case, the AVB-DMAC updates the descriptor type and informs the CPU that the descriptor has been processed.

In other cases (for illegal descriptor processing and so on), the current descriptor address register q (CDARq) is not updated.

## 45.3.3.5 Descriptor Interrupts

A descriptor is able to issue a descriptor interrupt on completion of its processing. The setting of the descriptor interrupt enable bits (DESCR.DIE) in each descriptor can disable the descriptor interrupts or select the specific descriptor interrupt to be generated.

The descriptor interrupt is a common resource that is shared between reception and transmission queues.

Figure 45.17 illustrates the way in which the AVB-DMAC generates descriptor interrupts (or sets bits in the descriptor interrupt status register (DIS.DPFi)). Processing of a descriptor with the value i in the descriptor interrupt enable bits (DESCR.DIE) leads to the corresponding bit in the descriptor interrupt status register (DIS.DPFi) being set.

**==> picture [326 x 156] intentionally omitted <==**

**----- Start of picture text -----**<br>
Read the descriptor from Process data transfer or control Update the descriptor<br>on-chip RAM. in accord with the DT setting in on-chip RAM<br>The descriptor  Notification of descriptor<br>can be used processing completion<br>DescriptorDIE  Select the interrupt flag<br>for use in descriptor<br>processing.<br>Event for which the selected interrupt flag is set<br>6 5 4 3 2 1 0<br>DIS - DPF6 DPF5 DPF4 DPF3 DPF2 DPF1 -<br>**----- End of picture text -----**<br>

**Figure 45.17 Method of Descriptor Interrupt Generation**

## 45.3.3.6 Descriptor Type

The descriptor types (indicated by the DESCR.DT bits) supported by the AVB-DMAC fall into the following three categories.

- Definitions of frame data

- Control of descriptor chains

- Hardware and software arbitration

Table 45.71 is a summary of the descriptor types available for the AVB-DMAC. Entries under “Name” are the names of the descriptor types and the values under “DT” are the corresponding values to be set in the descriptor type field (DESCR.DT). A given descriptor may be handled differently according to whether it is in a transmission or reception queue, so the transmission and reception columns list the scopes of control and processing of the descriptor types.

The abbreviations defined below are used in the transmission and reception columns.

## Definition of SW:

- The descriptor is processed by software.

- Software has access to and may modify the descriptor and descriptor data area.

- This descriptor cannot be changed by hardware (AVB-DMAC).

## Definition of HW:

- The descriptor is processed by hardware (AVB-DMAC).

- Software must modify neither the descriptor nor the descriptor data area.

- Hardware (AVB-DMAC) processes this descriptor and subsequently changes the descriptor type.

## Invalid:

This descriptor type is not used in transfer in the given direction (transmission or reception).

Do not write this value to the descriptor type (DESCR.DT) field for transfer in the given direction.

Hardware does not process these descriptor types in the cases listed as invalid. The current descriptor address (CDARq.CDA) will not be changed when processing of a queue for the given direction arrives at a descriptor with this type setting.

**Table 45.71 Summary of Descriptor Types**

|**Name**|**DT**|**Description**|**Reception**|**Transmission**|
|---|---|---|---|---|
|Frame data|||||
|FSTART|5|Frame Start|SW|HW|
|||The descriptor points to valid data for a frame. The frame starts with the|||
|||given data and continues with that indicated by the next descriptor.|||
|FMID|4|Frame Middle|SW|HW|
|||The descriptor points to valid data for a frame. The frame started with a|||
|||previous descriptor and continues to the data indicated by the next|||
|||descriptor.|||
|FEND|6|Frame End|SW|HW|
|||The descriptor points to valid data for a frame. The frame continues from the|||
|||previous descriptor and ends with the data indicated by in this descriptor.|||
|FSINGLE|7|Frame Single|SW|HW|
|||The descriptor points to valid data for a complete frame.|||
|Chain control|||||
|LINK|8|Link|HW|HW|
|||Defines the descriptor in the next chain.|||
|LINKFIX|9|Fixed Link|SW|SW|
|||Defines the descriptor in the next chain. Unlike the case of Link, it is not|||
|||rewritten by hardware after descriptor processing.|||
|EOS|10|End Of Set|HW|HW|
|||Controls division of the chain.|||
|HW/SW arbitration|||||
|FEMPTY|12|Frame Empty|HW|SW|
|||A descriptor related to frame data but not containing valid data for a frame|||
|FEMPTY_IS|13|Frame Empty Incremental Start|HW|Invalid|
|||A descriptor related to frame data but not containing valid data for a frame|||
|||DESCR.DPTR sets the base address of an "incremental data area" in the|||
|||on-chip RAM.|||
|FEMPTY_IC|14|Frame Empty Incremental Continue|HW|Invalid|
|||A descriptor related to frame data but not containing valid data for a frame|||
|||Data indicated by the pointer are for storage in an incremental data area in|||
|||the on-chip RAM.|||
|FEMPTY_ND|15|Frame Empty No Data Storage|HW|Invalid|
|||A descriptor related to frame data but not containing valid data for a frame|||
|||The descriptor is processed in the same way as FEMPTY but data are not|||
|||stored in the on-chip RAM.|||
|LEMPTY|2|Link Empty|SW|SW|
|||A link descriptor for processing by the AVB-DMAC|||
|EEMPTY|3|EOS Empty|SW|SW|
|||An EOS descriptor for processing by the AVB-DMAC|||
|DT0|0|Reserved|Invalid|Invalid|
|DT1|1|Reserved|Invalid|Invalid|
|DT11|11|Reserved|Invalid|Invalid|

## (1) Layout of General Descriptors in the On-chip RAM

The AVB-DMAC updates processed descriptors in the on-chip RAM. The field to be changed in a descriptor being updated depends upon whether the direction is transmission or reception and the queue mode. Other fields will not be changed. There are no restrictions on the values set in unused descriptor fields (indicated by “—” in the figure).

## (2) Frame Data Descriptors

The allocation of bits in the frame data descriptors (FSTART, FMID, FEND, and FSINGLE) is shown below.

 Normal descriptor (usable in both reception and transmission)

|+0<br>+4<br>+0<br>+4<br>+8<br>+12<br>+16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||DT[3:0]||||DIE[3:0]||||Content control for reception and transmission|||||||||DS[11:0]|
||DPTR[31:0]||||||||||||||||||
||<br>Extended descriptor (usable only in reception)<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||||||||||||||||||
||DT[3:0]||||DIE[3:0]||||Content control for reception and transmission|||||||||DS[11:0]|
|||||||||DPTR[31:0]|||||||||||
|||||||||TS[31:0]|||||||||||
|||||||||TS[63:32]|||||||||||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|TS[79:64]||
||**Table 45.72**|||||||**Contents of Frame Data Descriptors (DESCR)**|||||||||||
|||||||||**Bit Name**<br>**Function**|||||||||||
|||||||||DT[3:0]<br>Descriptor Type<br>5: FSTART<br>4: FMID<br>6: FEND<br>7: FSINGLE<br>For details, see section 45.3.4.2, Setting Up Reception Descriptors, and section<br>45.3.5.2, Setting Up Transmission Descriptors.|||||||||||
|||||||||DIE[3:0]<br>Descriptor Interrupt Enable<br>B’0000: Descriptor interrupt is disabled.<br>B’0001 to B’1111: The corresponding descriptor interrupt is generated<br>(DIS.DPFi).|||||||||||
|||||||||—<br>Content Control<br>For details, see section 45.3.4.2, Setting Up Reception Descriptors, and section<br>45.3.5.2, Setting Up Transmission Descriptors.|||||||||||
|||||||||DS[11:0]<br>Data Size<br>Size of the data area/frame data for the descriptor (in bytes)<br>The specifiable data lengths are as follows (when a frame is divided into parts,<br>the total size of the frame should be within the ranges below).<br>Transmission: 1 ≤ DS ≤ 1996<br>Reception: 1 ≤ DS ≤ 2000|||||||||||
|||||||||DPTR[31:0]<br>Descriptor Pointer<br>Pointer to the data area for the descriptor<br>Register an address on a 32-bit boundary.|||||||||||
|||||||||TS[79:0]<br>Time Stamp<br>Time stamp of the received frame (only available in extended descriptors)|||||||||||

## CAUTION

Register an address aligned with a 32-bit boundary as the descriptor pointer (DESCR.DPTR).

H’0000 is written to the reserved bits in an extended descriptor (bits 31 to 16 in DESCR) when the time stamp is stored.

- (3) Hardware/Software Arbitration Descriptors (Only for Reception)

The allocation of bits in the descriptors for hardware/software arbitration (FEMPTY, FEMPTY_IS, FEMPTY_IC, and FEMPTY_ND) is shown below.

- Normal descriptor

**==> picture [475 x 35] intentionally omitted <==**

**----- Start of picture text -----**<br>
31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>+0 DT[3:0] DIE[3:0] Content control for reception and transmission DS[11:0]<br>+4 DPTR[31:0]<br>**----- End of picture text -----**<br>

**Table 45.73 Contents of Hardware/Software Arbitration Descriptors (DESCR)**

|**Bit Name**|**Function**|
|---|---|
|DT[3:0]|Descriptor Type|
||12: FEMPTY|
||13: FEMPTY_IS|
||14: FEMPTY_IC|
||15: FEMPTY_ND|
||For details, see**Table 45.71, Summary of Descriptor Types**.|
|DIE[3:0]|Descriptor Interrupt Enable|
||B’0000: Descriptor interrupt is disabled.|
||B’0001 to B’1111: The corresponding descriptor interrupt is generated|
||(DIS.DPFi).|
|—|Content Control|
||For details, see section 45.3.4.2, Setting Up Reception Descriptors, and section|
||45.3.5.2, Setting Up Transmission Descriptors.|
|DS[11:0]|Data Size|
||Size of the data area/frame data for the descriptor (in bytes)|
|DPTR[31:0]|Descriptor Pointer|
||Pointer to the data area for the descriptor|
||Register an address on a 32-bit boundary.|

## CAUTIONS

Register an address aligned with a 32-bit boundary as the descriptor pointer (DESCR.DPTR).

When an extended descriptor is used, a 12-byte unused area is added.

In an FEMPTY descriptor, the descriptor type (DT), descriptor interrupt enable (DIE), data size (DS), and descriptor pointer (DPTR) fields are used.

In an FEMPTY_IS descriptor, the descriptor type (DT), descriptor interrupt enable (DIE), and descriptor pointer (DPTR) fields are used.

In an FEMPTY_IC descriptor, the descriptor type (DT) and descriptor interrupt enable (DIE) are used.

In an FEMPTY_ND descriptor, the descriptor type (DT), descriptor interrupt enable (DIE), and data size (DS) are used.

## (4) Link Descriptors

The allocation of bits in the link descriptors (LINK and LINKFIX) is shown below.

- Normal descriptor

**==> picture [475 x 36] intentionally omitted <==**

**----- Start of picture text -----**<br>
31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>+0 DT[3:0] DIE[3:0] — — — — — — — — — — — — — — — — — — — — — — — —<br>+4 DPTR[31:0]<br>**----- End of picture text -----**<br>

**Table 45.74 Contents of Link Descriptors (DESCR)**

|**Bit Name**|**Function**|
|---|---|
|DT[3:0]|Descriptor Type|
||8: LINK|
||9: LINKFIX|
||For details, see**Table 45.71, Summary of Descriptor Types**.|
|DIE[3:0]|Descriptor Interrupt Enable|
||B’0000: Descriptor interrupt is disabled.|
||B’0001 to B’1111: The corresponding descriptor interrupt is generated|
||(DIS.DPFi).|
|—|Content Control|
||For details, see section 45.3.4.2, Setting Up Reception Descriptors, and section|
||45.3.5.2, Setting Up Transmission Descriptors.|
|DPTR[31:0]|Descriptor Pointer|
||Pointer to the data area for the next descriptor|
||Register an address on a 32-bit boundary.|

## CAUTION

Register an address aligned with a 32-bit boundary as the descriptor pointer (DESCR.DPTR). When an extended descriptor is used, a 12-byte unused area is added.

## (5) Other Descriptors

The allocation of bits in the other descriptors (EOS, FEMPTY (only for transmission), LEMPTY, and EEMPTY) is shown below.

|+0<br>+4|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||DT[3:0]||||DIE[3:0]||||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|

## **Table 45.75 Contents of Other Descriptors (DESCR)**

|**Bit Name**|**Function**|
|---|---|
|DT[3:0]|Descriptor Type|
||10: EOS|
||12: FEMPTY (only for transmission)|
||2: LEMPTY|
||3: EEMPTY|
||For details, see**Table 45.71, Summary of Descriptor Types**.|
|DIE[3:0]|Descriptor Interrupt Enable|
||B’0000: Descriptor interrupt is disabled.|
||B’0001 to B’1111: The corresponding descriptor interrupt is generated|
||(DIS.DPFi).|

## CAUTION

When an extended descriptor is used, a 12-byte unused area is added.

## (6) How to Use Frame Data Descriptors

The descriptor data area size field (DESCR.DS) can specify up to 2048 bytes of Ethernet frame data per data area. Settings higher than 2048 (bytes) cannot be made.

In general, Ethernet frames are not of uniform length. The AVB-DMAC is capable of dividing frame data into multiple descriptors in order to minimize the memory capacity for frame data. This function allows processing of frames that are longer than the limit for descriptor data areas. Division can also be applied to frames on the basis of their data structures.

To handle both frames divided up into multiple data areas and descriptors for complete single frames, four types (DESCR.DT) FSTART, FEND, FMID, and FSINGLE are defined.

Figure 45.18 shows the mapping of frame data by frame data descriptors. The descriptor data areas are allocated to the on-chip RAM. For frames that require division into four or more data areas, additional FMID descriptors can be added as required.

**==> picture [246 x 152] intentionally omitted <==**

**----- Start of picture text -----**<br>
... Data area<br>FSINGLE Data area<br>...<br>FSTART<br>FEND Data area<br>... Data area<br>FSTART<br>FMID<br>FEND Data area<br>... Data area<br>FSTART<br>FMID<br>FMID<br>FEND<br>...<br>**----- End of picture text -----**<br>

## **Figure 45.18 Mapping of Frame Data**

For reception, set the descriptor data areas to the maximum size (i.e. give DESCR.DS its maximum value). The AVB-DMAC will store received frame data in the given area. If a received frame has more data than the maximum size, the AVB-DMAC will divide the data up.

For transmission, set the frame data size to the actual data size. The AVB-DMAC modifies the descriptor type (DESCR.DT) to FEMPTY after processing the relevant descriptor. The data size (DESCR.DS) and descriptor pointer (DESCR.PTR) fields retain their settings.

A descriptor data area including unused space produces an empty space between data areas. In reception, an "incremental data area" can be used to prevent empty spaces. For incremental data areas, see section 45.3.4.3 (2) Incremental Data Areas .

As well as reducing the memory capacity taken up by the descriptor area in the on-chip RAM, division into frames can be used to identify different sections of data (e.g. for separating a header and data).

- (7) How to Use Chain Control Descriptors

## (a) Link Descriptors

The link descriptors can be used to set up cyclic descriptor chains (for details, see section 45.3.3.2, Using Descriptor Chains in Queues ).

After a LINK descriptor is processed, its descriptor type (DESCR.DT) is changed to LEMPTY. The descriptor pointer (DESCR.PTR) retains its setting.

After processing of a LINKFIX descriptor, the descriptor type (DESCR.DT) is not updated. Software can change the descriptor type (DESCR.DT), descriptor interrupt enable (DESCR.DIE), and descriptor pointer (DESCR.DPTR). Take care, however, to check the current descriptor address register (CDARq.CDA) before changing the descriptor pointer (DESCR.DPTR).

## (b) EOS Descriptor

Use the EOS descriptor to divide a descriptor chain into various segments. The queue can continue even after an EOS descriptor.

In transmission, the response to an EOS descriptor is clearing of the transmit start request bit in the transmit configuration control register (TCCR.TSRQq) to 0.

In reception, the response is generation of a receive queue full interrupt (RIS2.QFFr), although if the frame currently being received is being divided for storage (received data being stored in FMID- or FEND-type frames), the data are not completely stored.

## (8) How to Use Hardware and Software Arbitration Descriptors

In hardware processing of descriptors, the empty descriptor types (FEMPTY, LEMPTY, and EEMPTY) are defined to distinguish various descriptors. For software, they can be used to initiate checking for empty spaces, etc.

## (a) FEMPTY, FEMPTY_IS, FEMPTY_IC, and FEMPTY_ND

These descriptor types (DESCR.DT) are used for descriptors that do not contain effective data. Of these, only FEMPTY is used in transmission.

These descriptor pointers (DESCR.DPTR) indicate the descriptor data area.

## (b) LEMPTY

This descriptor type (DESCR.DT) is assigned to LINK descriptors after they have been processed.

The descriptor pointer (DESCR.DPTR) of an LEMPTY descriptor still points to the linked descriptor.

## (c) EEMPTY

This descriptor type (DESCR.DT) is assigned to EOS descriptors after they have been processed.

The descriptor pointer (DESCR.DPTR) of an EEMPTY descriptor is not used, and thus points to nothing.

- (9) Relationship between Descriptor Access by Hardware and Software

In the EthernetAVB, the allocation of descriptor types (DESCR.DT) to the on-chip RAM can be used. This makes it possible to minimize access to the EthernetAVB registers via the CPU, leading to higher performance.

- Each descriptor type in the set is exclusively for processing by hardware or software, depending on the direction of transfer (see Table 45.71 ).

- Software must not change a descriptor assigned to hardware processing (the hardware does not change descriptors assigned to software processing).

In the case of software processing, the software must process the information in the descriptor and the corresponding frame data before changing the descriptor type. If a descriptor type for hardware is set in DESCR.DT, the software should not change any part of the descriptor or of the corresponding frame data.

## 45.3.3.7 Optimization of Bus Performance when Using Descriptors

The following items are recommended as ways to ensure the optimal use of data structures in the onchip RAM.

They are not requirements, but using a different approach may increase the load on the system bus within the LSI chip.

- Register descriptors with 64-bit alignment (this does not apply to extended descriptors).

- While in operation mode, use LINKFIX instead of LINK whenever a descriptor need not be changed. Hardware modifies the descriptor type (DESCR.DT) fields of LINK descriptors.

- Restrict frame data to a maximum size of 128 bytes.

- Minimize parallelism of processing to the descriptor chains. This helps in arranging the different segments exclusively for access by software or hardware by dividing the chains so as to be allocated to different on-chip RAM pages.

- Minimize the number of divided frames. This can reduce the overhead of descriptor handling.

## 45.3.4 Control in Reception

The point of the AVB-DMAC is to transfer data between the E-MAC and on-chip RAM without intervention by the CPU.

Create descriptors that define the amounts of frame data to be stored and the locations. After the E- MAC receives a frame, it stores the received frame data and the conditions of reception as the MAC state. If the descriptor is extended, the time stamp is also stored. For a description of how to set up descriptors for use in reception, see section 45.3.4.2, Setting Up Reception Descriptors .

The AVB-DMAC filters received frames to separate them into various classifications (separation filtering). More specifically, this is done to separate received frames into the various reception queues and to set the priorities of different classes of received frames. For more on separation filtering, see section 45.3.4.1 (1) Separation Filtering .

Figure 45.19 shows the reception data bus and the selection of queues for use in reception.

Each frame received from the E-MAC is stored in the reception FIFO; in parallel with this, the frame is analyzed to identify its type and the target queue number. After the E-MAC completes reception, the target queue number is generated and stored in the reception FIFO. A reception flag is applied to each reception queue in the on-chip RAM, and the unread frame counter (UFC) is also applied to each reception queue.

**==> picture [383 x 150] intentionally omitted <==**

**----- Start of picture text -----**<br>
Queue 0 UFC information is to be stored or Number of the queue where  - Network (802.1AS)Identifying the frame type<br>discarded - Sorted AVB stream (1722)<br>- Sorted non-AVB stream<br>Queue 1 - Discard frames<br>Trigger to start storage  - Best effort (others)<br>(from the scheduler)<br>Queue 2<br>On-chip RAM<br>Processing of the<br>... queue-specific<br>descriptor chain and  Reception  E-MAC<br>North main  appending of flags FIFO Received Ethernet frames To PHY<br>Queue 17 bus Received time stamps from gPTP stream<br>reception<br>Each status register Truncation settings<br>**----- End of picture text -----**<br>

**Figure 45.19 Mechanism of General Reception Queue Selection**

## 45.3.4.1 Reception Queues

The AVB-DMAC applies its separation filtering mechanism to select the reception queue for storing a received frame. The AVB-DMAC stores all received frames in the on-chip RAM.

There are two conditions for the AVB-DMAC to discard a received frame.

- Detection of an error during reception by the E-MAC

   - Whether error frames are discarded or stored in reception queue 0 (best effort) can be set by the error frame enable bit in the receive configuration register (RCR.EFFS). If error frames are to be stored (RCR.EFFE = 1), they are always stored in queue 0 (best effort). In this case, parameters of each queue (e.g. truncation) may not match. If the storage of time stamps for reception queue 0 (best effort) is enabled (the time stamp enable bit in the receive configuration register RCR.ETS0 = 1), time stamps are stored even for error frames.

- Non-matching determination conditions of the separation filter

   - Whether non-matching frames are discarded or stored in reception queue 0 (best effort) can be set by the stream filtering select bit in the receive configuration register (RCR.ESF).

The flowchart in Figure 45.20 shows how the AVB-DMAC selects the reception queue in accord with the frame type, including judgment by the separation filter. Selection of the queue starts when the E- MAC completes frame reception. The result is storage of the frame in the proper queue or the frame being discarded.

**==> picture [421 x 334] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Did the E-MAC  Yes<br>detect a reception<br>error? Error frame enable<br>No 0b<br>Network control  RCR.EFFS<br>filtering enable<br>1b 1b<br>RCR.ENCF<br>Condition for<br>No 0b<br>determining network<br>control frames  Stream filtering select<br>satisfied?<br>Yes (AVB) 10b, 11b 00b (disabled) Frame is stored through<br>RCR.ESF reception queue 0<br>(best effort)<br>01b<br>Condition for  Yes (only for separation filter)<br>determining IEEE 1722<br>frames satisfied? Frame is discarded<br>No Condition for<br>separation filter  No<br>determination<br>satisfied?<br>10b (non-matching<br>Yes frames are discarded)<br>RCR.ESF<br>01b, 11b (non-matching frames are<br>Frames are stored  Frames are stored  processed in reception queue 0)<br>through reception queue 1  through reception queue<br>(network control) r ≥ 2 (stream)<br>**----- End of picture text -----**<br>

**Figure 45.20 Flow of Reception Queue Selection**

Notes on the description of entries in the flowchart

- “Condition for determining network control frames” The Ethernet destination address (DA) is 01:80:C2:00:00:0E, and The Ethernet type (ET) is 88:F7.

- “Condition for determining IEEE 1722 frames” The Ethernet destination address (DA) is in the range from 91:E0:F0:00:00:00 to 91:E0:F0:00:FE:FF,

   - The VLAN tagged TPID (tag protocol identifier) field (VL) is 81:00, and The Ethernet type (ET) is 22:F0.

- “Condition for separation filter determination” See section 45.3.4.1 (1) Separation Filtering .

Figure 45.21 shows the allocation of data in Ethernet frames used for determination of Network Control frame and IEEE1722 frame. The preambles of Ethernet frames are not taken into account.

|Data bytes<br>Network type<br>Stream type|0<br>1<br>2<br>3|0<br>1<br>2<br>3|0<br>1<br>2<br>3|0<br>1<br>2<br>3|4<br>5<br>6<br>7|4<br>5<br>6<br>7|4<br>5<br>6<br>7|4<br>5<br>6<br>7|8<br>9<br>10<br>11|8<br>9<br>10<br>11|8<br>9<br>10<br>11|8<br>9<br>10<br>11|12<br>13<br>14<br>15|12<br>13<br>14<br>15|12<br>13<br>14<br>15|12<br>13<br>14<br>15|16<br>17<br>18<br>19|16<br>17<br>18<br>19|16<br>17<br>18<br>19|16<br>17<br>18<br>19|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||DA1|DA2|DA3|DA4|DA5|DA6|SA1|SA2|SA3|SA4|SA5|SA6|ET1|ET2|...|...|...|...|...|...|
||||||||||||||||||||||
||DA1|DA2|DA3|DA4|DA5|DA6|SA1|SA2|SA3|SA4|SA5|SA6|VL1|VL2|-|-|ET1|ET2|...|...|

## **Figure 45.21 Data Allocation of Ethernet Frames Used in Frame Determination**

- (1) Separation Filtering

Separation filtering involves the checking of 64 bits (eight successive bytes) in received Ethernet frames. The setting for the first byte (i.e. the setting of the separation filter offset configuration register (SFO.FBP)), selects the part of frames to be used in separation filtering. There is also a common filter mask (set in the separation filter mask configuration register (SFMi.CFM)) that can filter less than the number of bytes and mask particular bits.

## Examples

To use only the first byte from the top in separation filter, set separation filter mask configuration register 0 (SFM0.CFM) to H’0000 00FF and separation filter mask configuration register 1 (SFM1.CFM) to H’0000 0000.

To use seven bytes from the top in separation filter, set separation filter mask configuration register 0 (SFM0.CFM) to H’FFFF FFFF and separation filter mask configuration register 1 (SFM1.CFM) to H’00FF FFFF.

## CAUTION

If bits are set to 0 in the separation filter mask, in order to match with the pattern, the bits at the corresponding positions of the pattern must also be set to 0. Only when "the received frame data & the separation filter mask register (SFMi.CFM) = the separation filter pattern register (SFPi.FPs)", it is judged that the bits match with the pattern.

Figure 45.22 shows separation filtering. The selected data from a received frame (Rx_Frame[63:0]) are masked by the common filter mask. This value is compared with all filter patterns. The AVBDMAC selects the queue having the smallest queue number from among the matched filter patterns.

**==> picture [414 x 241] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet frame data (byte)<br>0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ...<br>SFO.FBP = 6<br>Rx_Frame[63:0]<br>SFMi.CFM[63:0] &<br>Matching of separation filter<br>SFPi.FP0[63:0] ==<br>SFPi.FP1[63:0] ==<br>Select<br>SFPi.FP2[63:0] == matching pattern<br>with the smallest<br>queue number<br>...<br>**----- End of picture text -----**<br>

**Figure 45.22 Overview of Separation Filtering (when SFO.FBP = 6)**

## (a) Restrictions on Number of Filters Used

The AVB-DMAC always checks all the separation filter patterns. When it is not necessary to use all the reception queues, providing a special pattern can prevent data from being stored in the unused reception queue.

## Example 1:

Setting a value other than H’FFFF_FFFF_FFFF_FFFF to the separation filter mask register (SFMi.CFM) and setting H’FFFF_FFFF_FFFF_FFFF to the separation filter pattern register (SFPi.FPs) can prevent pattern matching in the unused reception queue.

Example 2:

Setting H’FFFF_FFFF_FFFF_FFFF to the separation filter mask register (SFMi.CFM) and setting the value identical to the pattern in reception queue 2 to the separation filter pattern register (SFPi.FPs) selects, upon a pattern matching, reception queue 2, which has a smaller queue number, thus preventing the unused reception queue from being used.

## (2) Separating Streams

The AVB-DMAC applies separation filtering to sort frames received in streams. An AVB network has a concept of “Talker” and “Listener”. A Talker is an end station that generates one or more streams. A Listener is an end station that has the role of being a sink for at least one stream. The various A/V streams are identified by 8-byte stream IDs.

The number of end stations within an ABV network and their roles differ with the application.

The stream ID is a specific pattern of the AVB network for identifying one stream. Figure 45.23 shows the bit allocation of bits in IEEE1722 Ethernet frames and stream ID fields.

**==> picture [433 x 165] intentionally omitted <==**

**----- Start of picture text -----**<br>
8 bytes 6 bytes 6 bytes 4 bytes 2 bytes 0 to 1500 bytes<br>Destination  Source  VLAN  Ether<br>Preamble address address tag type IEEE 1722 data stream CRC<br>4 bytes 8 bytes<br>IEEE 1722 Subtype  Stream<br> Packet data ID Control packer additional headers and audio/video payload<br>These three fields are<br>required to decide it’s a  6 bytes 2 bytes<br>1722 frame<br>Possible<br> stream ID structure Talker source address Unique ID<br>**----- End of picture text -----**<br>

**Figure 45.23 IEEE 1722 Frame Layout and Stream ID**

The IEEE 1722 standard stipulates that the stream ID field starts from the 22nd byte (not counting the preamble). Accordingly, set the separation filter offset (SFO.FBP) to 22 in separations on IEEE 1722 streams. Set the separation filter mask (SFMi) and separation filter pattern (SFPi) in accord with the specification of the application in which the chip is being used.

Example: In the example of a stream ID shown in Figure 45.23 , the representative application divides the field into the talker source address and the unique stream ID. The unique ID is used to differentiate between multiple streams from the same talker. Based on this, there are two settings for separation filter masking:

- To divide various streams into individual queues, set SFM0.CFM to H’FFFF FFFF and SFM1.CFM to H’FFFF FFFF.

- To divide streams for each talker into individual queues, set SFM0.CFM to H’FFFF FFFF and SFM1.CFM to H’0000 FFFF. This excludes the unique ID from the filter condition.

## 45.3.4.2 Setting Up Reception Descriptors

For reception, the descriptor as described in section 45.3.3, Descriptors is used.

This section describes specific operations that are especially required in handling reception queues.

## (1) Reception Descriptor Type

The type of a descriptor is defined by the descriptor type (DESCR.DT) field.

Table 45.76 shows the descriptor types used in reception. In the table, entries in the write-back column indicate how the AVB-DMAC changes the DESCR.DT field upon completion of descriptor processing.

## **Table 45.76 Descriptor Types in Reception**

|**Descriptor Type**|||
|---|---|---|
|**(DESCR.DT)**|**Operation**|**Write-back**|
|**Frame Start**(FSTART)|There is no storage space in a reception queue:|Not changed|
||The RIS2.QFFr bit indicates that queue r is full and the received frame is not stored.||
||Descriptor processing proceeds again in response to further reception.||
|**Frame Middle**(FMID)|Same as FSTART|Not changed|
|**Frame End**(FEND)|Same as FSTART|Not changed|
|**Frame Single**|Same as FSTART|Not changed|
|(FSINGLE)|||
|**Link**(LINK)|Processing proceeds to the descriptor specified by DESCR.DPTR.|LEMPTY|
|**Fixed Link**(LINKFIX)|Same as LINK|Not changed|
|**End Of Set**(EOS)|In the case of a divided frame (received frame being stored in FMID or FEND), storing of|EEMPTY|
||frames is stopped and the frame is lost. RIS2.QFFr indicates that the frame has been||
||lost.||
||If this happens at the start of a frame (received frame being stored in FSTART or||
||FSINGLE), storing of frames starts from the next descriptor.||
||In either case, processing shifts to the next descriptor in the chain.||
|**Frame Empty**|Used to store received data.|FSTART, FMID,|
|(FEMPTY)|Up to DESCR.DS bytes are stored in the descriptor data area.|FEND, or|
||For details, see section 45.3.4.3 (1) Storing Frame Data in the Descriptor Data Area.|FSINGLE|
|Frame Empty|Used to store received data.|FEND or|
|Incremental Start|The remaining frame data are all stored in the descriptor's data area.|FSINGLE|
|(FEMPTY_IS)|DESCR.DPTR indicates the base address of the incremental data area.||
||For details, see section 45.3.4.3 (2) Incremental Data Areas.||
|Frame Empty|Used to store received data.|FEND or|
|Incremental Continue|The remaining bytes of frame data are all stored in the descriptor's data area.|FSINGLE|
|(FEMPTY_IC)|DESCR.DPTR is undefined, but the address after processing of previous incremental||
||data becomes the base address.||
||For details, see section 45.3.4.3 (2) Incremental Data Areas.||
|Frame Empty|Used to store received data.|FSTART, FMID,|
|No Data storage|DESCR.DS bytes of spaces are secured in the reception FIFO but not stored. After|FEND or|
|(FEMPTY_ND)|processing, DESCR.DS is written back as 0.|FSINGLE|
||For details, see section 45.3.4.3 (2) Incremental Data Areas||
|Link Empty (LEMPTY)|Same as FSTART|Not changed|
|EOS Empty (EEMPTY)|Same as FSTART|Not changed|

If a reception FIFO read error occurs when FEMPTY_ND is used, it is not reflected in DESCR.EI and queue error interrupt status bit (EIS.QEF).

Therefore, to detect a reception FIFO error also for unnecessary data, FEMPTY should be used.

## (2) Configuration of Reception Frame Data Descriptors

Figure 45.24 shows the configuration of descriptors for use with reception queues. The receptionspecific fields are the same whether the descriptor is normal or extended. The reception-specific fields (DESCR.MSC, DESCR.PS, DESCR.EI, and DESCR.TR) are described in Table 45.77 .

For the other fields and the descriptor types, see section 45.3.3.6, Descriptor Type .

**==> picture [431 x 25] intentionally omitted <==**

**----- Start of picture text -----**<br>
31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>+0 DT[3:0] DIE[3:0] MSC[7:0] PS[1:0] EI TR DS[11:0]<br>+4 DPTR[31:0]<br>**----- End of picture text -----**<br>

## **Figure 45.24 Configuration of Descriptor for a Received Frame**

**Table 45.77 Configuration of a Received Descriptor**

|**Bit Name**|**Function**|
|---|---|
|MSC|MAC Status Code|
||These bits indicate errors in reception detected by the E-MAC.|
||These bits are set to the same value between the frames divided by the descriptor.|
||Details of the bits are as follows.|
||MSC[7]: Received frame has a multicast address.|
||MSC[6]: Reserved|
||MSC[5]: Reserved|
||MSC[4]: Received frame has residual bits.|
||MSC[3]: Received frame is too long.|
||MSC[2]: Received frame is too short|
||MSC[1]: Error in frame reception|
||MSC[0]: Received frame has a CRC error.|
|PS|Padding Selection|
||These bits specify whether frame data are to be padded when stored in the|
||incremental data area.|
||Insertion of padding data is in accord with the settings in the receive padding|
||configuration register (RPC).|
||B’00: Padding is not to be inserted.|
||B’01: Padding data may be inserted. This depends on the RPC settings.|
||B'10: Setting prohibited.|
||B'11: Setting prohibited.|
|EI|Error Indication|
||This bit indicates the detection of an error in frame data while a frame was being|
||stored.|
||The bit is set to 1 for a descriptor in which an error has been detected. If the|
||descriptor is for a divided frame, the frame data is discarded.|
||0: No error|
||1: Error is detected|
|TR|Truncation Indication|
||This bit indicates whether frame data received from the E-MAC have been|
||truncated before being stored in the on-chip RAM.|
||These bits are set to the same value between the frames divided by the descriptor.|
||0: Data have not been truncated.|
||1: Data have been truncated.|

## CAUTION

The RCR.EFFS bit specifies whether or not frames with errors detected by the E-MAC are to be stored in the on-chip RAM. When the storing of error frames is disabled, error codes are not written to DESCR.MSC.

## 45.3.4.3 Reception Processing

After initialization, the AVB-DMAC is able to select the proper reception queue and store received frames in the data area in the on-chip RAM as indicated by the descriptor. The AVB-DMAC continues to store received data in the on-chip RAM as long as space is available for descriptors and data areas.

Received frames are classified and stored in the reception FIFO in accord with the algorithm described in section 45.3.4.1 (1) Separation Filtering . A frame will already have been sorted by separation filtering, truncated, or discarded based on reception by the MAC before being stored in the reception FIFO. The following data are stored in the reception FIFO.

- MAC status of received frames

- Length of received frames

- Time stamp of received frames

- Target reception queue

- Received frame data

If the reception FIFO contains even one frame, the scheduler allocates storing in the reception queue (see section 45.3.2.2, Scheduling Reception and Transmission ).

If there is even one empty descriptor in a queue for which reception has started, the storage of frame data starts. Received frames for a queue that is already full (there is no empty frame descriptor or the unread frame counter stop level has been reached) are discarded from the reception FIFO. This ensures that one queue being full does not prevent the processing for data in the other queues.

- (1) Storing Frame Data in the Descriptor Data Area

Frame data for storage are assumed to be in either of the two patterns described below.

- The data for an entire frame will fit in the descriptor data area.

   - In this case, the descriptor type (DESCR.DT) is FSINGLE.

- Frame data is bigger than the descriptor, so the frame data is divided and stored in the descriptor data area.

– In this case, FSTART is written to the descriptor type (DESCR.DT) bits of the first of the frame data to arrive and FMID and FEND are written to the type bits of descriptors for subsequent data.

The descriptor type is updated by the AVB-DMAC in the last step of descriptor processing, so software can always access the descriptor written-back to DESCR.DT.

Software can write FEMPTYxxx directly to the descriptor type field after processing the stored frame data. Do not change the descriptor or any part of the descriptor data area after FEMPTYxxx is written to DESCR.DT.

## (a) Single Frame

For a frame with an FSINGLE descriptor, all data for the frame are held at the position defined by DESCR.DPTR. DESCR.DS indicates the length of the received frame.

If DESCR.DS is bigger than the actual size of a received frame, the FEMPTY or FEMPTY_ND descriptor is stored in place of the FSINGLE descriptor.

Also, the FEMPTY_IS and FEMPTY_IC descriptors, which always hold the full frame data, are stored in place of the FSINGLE descriptor.

## (b) Divided Frames

Divided frames can be processed in the same way as a single frame. A frame stored with divided descriptors must be recombined before use. DESCR.EI and DESCR.TS are only valid in the last descriptor of the sequence for a divided frame.

## CAUTION

If the data area size setting in DESCR.DS is not a multiple of four bytes, only the number of bytes set in DESCR.DS is fetched from the reception FIFO and the remaining bytes are used by the next descriptor.

After a received frame is divided into different descriptors, each frame data is processed separately, and the descriptor type is assigned by software after processing. Accordingly, an error frame (FEMPTYxxx instead of FMID or FEND) may exist while a descriptor chain is being processed. In such a case, the CPU must postpone processing of the error frame until the corresponding descriptor has been processed.

## (c) No Data

The application specification may lead to some types of received frames being unimportant (for example, when the application only requires stream data from the Ethernet frames). Storing frames in divided form makes separating out the unnecessary parts of Ethernet frames possible.

If part of a divided frame is not required, use the FEMPTY_ND descriptor so that unnecessary data is not stored in the on-chip RAM.

After processing an FEMPTY_ND descriptor, the AVB-DMAC sets DESCR.DS to 0. DESCR.DS = 0 is for the specific flag indicating that the FEMPTY_ND descriptor has been processed.

## (2) Incremental Data Areas

Secure space for storing received data in the on-chip RAM. Even when all descriptor data areas of a chain are placed in the contiguous area of the on-chip RAM area, a received frame being shorter than the descriptor data area will lead to an empty space. Figure 45.25 shows an example of settings and the memory map.

In some cases, contiguous data arrangement may be effective (e.g. when received data are to be processed other than by hardware as the A/V codec module). When the length of frames differs for each received frame (e.g. when payloads vary between having one or two A/V packages), the use of a pointer in the descriptor produces empty spaces in the data area. This necessitates additional processing such as copying the frame data to remove the empty spaces.

Accordingly, and to prevent copying data, the AVB-DMAC supports an “incremental data area” function.

When incremental data areas are in use, different descriptors use a contiguous data area. The first descriptor (FEMPTY_IS) from the top defines the base address of the incremental data area and is used to, together with the subsequent descriptor (FEMPTY_IC) within the descriptor chain, hold received data. Figure 45.26 shows an example of settings and the memory map.

When an incremental data area is used, it is also possible to divide a frame into various descriptors in a way that reflects its structure (e.g. one descriptor for the Ethernet header and one for the data payload).

**==> picture [374 x 227] intentionally omitted <==**

**----- Start of picture text -----**<br>
Data allocation<br>in on-chip RAM<br>Descriptor chain example<br>300<br>Written by CPU Written by AVB-DMAC 300 bytes are reserved<br>FEMPTY (DS = 25) FSTART (DS = 25) for one descriptor<br>FEMPTY (DS = 300) FEND (DS = 300)<br>FEMPTY (DS = 25) FSTART (DS = 25) 150<br>FEMPTY (DS = 300) FEND (DS = 150)<br>FEMPTY (DS = 25) FSTART (DS = 25) 150<br>FEMPTY (DS = 300) FEND (DS = 150)<br>FEMPTY (DS = 25) FSTART (DS = 25) 150 Part used for received<br>FEMPTY (DS = 300) FEND (DS = 300) frame data<br>FEMPTY (DS = 25) FSTART (DS = 25) 150 Received frame being<br>FEMPTY (DS = 300) FEND (DS = 300) shorter than the reserved<br>EOS 300 area leads to empty<br>... space.<br>300<br>**----- End of picture text -----**<br>

**Figure 45.25 When Individual Descriptor Data Areas are Used**

Figure 45.25 and Figure 45.26 show how control of the data storage areas by a descriptor chain varies according to whether incremental data areas are not in use or in use. The chains are configured for storing received frames consisting of a 25-byte header (in this example, stored in the on-chip RAM area outside the drawing range) and a 150- or 300-byte payload (whether one or two 150-byte data depending on the data source).

In Figure 45.25 , an EOS descriptor is added as an example of a re-synchronization point. If a frame larger than 325 bytes is received, the frame will be divided into three descriptors, meaning that synchronization of the header and data sequences is lost. However, a frame is not divided across an EOS descriptor, so adding EOS descriptors can prevent the header and data sequences losing synchronization. While an incremental data area is in use, EOS descriptors are not required because the incremental descriptors always hold all data being processed.

**==> picture [272 x 224] intentionally omitted <==**

**----- Start of picture text -----**<br>
Data allocation<br>Descriptor chain example in on-chip RAM<br>300<br>Written by CPU Written by AVB-DMAC<br>FEMPTY (DS  = 25) FSTART (DS = 25)<br>FEMPTY_IS FEND (DS  = 300)<br>FEMPTY (DS = 25) FSTART (DS = 25) 150<br>FEMPTY_IC FEND (DS = 150)<br>FEMPTY (DS = 25) FSTART (DS = 25) 150<br>FEMPTY_IC FEND (DS = 150)<br>FEMPTY (DS = 25) FSTART (DS = 25) 300<br>FEMPTY_IC FEND (DS = 300)<br>FEMPTY (DS = 25) FSTART (DS = 25)<br>FEMPTY_IC FEND (DS = 300)<br>... 300<br>DPTR set by CPU Latest incremental address<br>300<br>DPTR set by AVB-DMAC<br>**----- End of picture text -----**<br>

**Figure 45.26 When Incremental Data Area is Used**

As Figure 45.26 shows, when data are stored in an incremental data area, the descriptor pointers in the FEMPTY_IC descriptors (DESCR.DPTR) are updated. Accordingly, the FEND or FSINGLE descriptor written-back by the AVB-DMAC after processing is in the same format as the FEMPTY descriptor after processing.

Software captures contiguous received data, which has no empty spaces, from an incremental data area. The incremental data area must be aligned with a 4-byte boundary. Therefore, when the amount of received data for storage in an incremental data area is not a multiple of four bytes, from one to three bytes of empty space is placed at the end of the incremental data area. DESCR.DS can be read to check for such empty spaces.

For the normal descriptors (FEMPTY and FEMPTY_ND), controlling the amount of received data due to DESCR.DR is possible, but for the incremental descriptors (FEMPTY_IS and FEMPTY_IC), controlling the amount of received data to be stored is not possible. All received data are always stored in an incremental descriptor.

## (a) Setting Up an Incremental Data Area

If a descriptor chain has N descriptors (one FEMPTY_IS and N-1 FEMPTY_IC), an area for storing N times of the maximum received data as the incremental data area must be secured.

As Figure 45.26 shows, DESCR.DPTR of an FEMPTY_IS descriptor indicates the base address of the incremental data area. The subsequent FEMPTY_IC descriptor in the chain indicates that data must be stored in the incremental data area.

## (b) Processing an Incremental Data Area Based on Descriptors

Since data processing by the CPU is the same regardless of how the AVB-DMAC stores the data, data stored in an incremental data area do not require any special handling.

## (c) Padding

Use padding for reception of frame data that are not aligned correctly. Padding can be set individually for each descriptor. Accordingly, in the reception of divided frames, padding can be set to only those frames that require it (e.g. A/V payload data.)

Padding can also be used to effectively use an incremental data area (e.g. to prevent inefficient access by aligning received data with 32-byte boundaries.

Padding can only be used in an incremental data area.

The value H’0000 0000 is always used in padding.

Padding is the addition of the number of words (from one to seven 32-bit words) set in the stored padding counter bit in the receive padding configuration register (RPC.PCNT). This padding is repeatedly inserted for each received data count set to the stored data counter bit (RPC.DCN) (from one to 255 32-bit words). When the stored data counter (RPC.DCNT) reaches 0, however, padding is not repeated.

The first word of padding is always inserted at the position specified by DESCR.DPTR. When divided frames are in use, a padding word can be inserted in accord with each descriptor (e.g. the first descriptor handles a 42-byte header data and the second descriptor holds padded payload data in an incremental data area).

The next figure shows a general example of how padding is inserted and an example of setting up padding. In the figure, A indicates frame data received from the E-MAC, while B indicates frame data stored in the descriptor data area (32-bit word units).

A 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ... B P P P 1 2 3 4 5 6 7 8 9 P P P 10 11 12 13 14 ... RPC.PCNT = 3 RPC.DCNT = 9 RPC.PCNT = 3 RPC.DCNT = 9

## **Figure 45.27 Example of a Padding Setting**

Both padding and received frame data are counted in the descriptor size (DESCR.DS).

## (3) Support for Reception Time Stamps

Capturing reception time stamps is essential for IEEE 802.1AS time synchronization. Other types of received frames may also require that a reception time stamp be appended; this depends on the application. The AVB-DMAC supplies reception time stamps based on the gPTP timer by storing time stamps that have been captured when the start frame delimiter (SFD) for a received frame in the last frame data descriptor (FEND or FSINGLE). For the gPTP timer, see section 45.3.7.1, gPTP Timer .

When time stamps are to be stored, use extended descriptors for the entire reception queue. Furthermore, time stamps are always stored for reception queue 1 (network control). Time stamps for reception queue 0 (best effort) and reception queue r (r ≥ 2; for stream data) can be selected by the time stamp enable bits in the receive configuration register (RCR.ETS0 or RCR.ETS2).

## 45.3.4.4 Unread Frame Counters

Each reception queue has an unread frame counter (UFCVi). Use the unread frame counter configuration bits in the receive queue configuration register (RQCi.UFCCr) to select from among the four stop levels for each unread frame counter. The 0 setting disables the stop functions. For how to set this up, see Figure 45.28 .

Operations of the AVB-DMAC (hardware) and CPU (software) drive an unread frame counter (UFC) in the following ways.

- The hardware indicates that it has added a new frame to the descriptor chain for the queue (this increments the counter).

- Software indicates how many frames from the descriptor chain it has processed by writing to the corresponding bits of the unread frame counter decrement register for the queue (this decrements the register by the number written).

The unread frame counter is based on the number of frames stored in the on-chip RAM and is only incremented by one even when a received frame is divided into different descriptors. Data failure in a descriptor chain requires care because this may fail in synchronization of the unread frame counter as described in section 45.3.4.4 (1) Loss of Unread Frame (UFC) Synchronization .

**==> picture [388 x 206] intentionally omitted <==**

**----- Start of picture text -----**<br>
Common settings UFC for each queue<br>Incremented by hardware<br>(when frames are stored)<br>Stop level<br>Decremented by the CPU<br>(UFCSi)<br>(writing to UFCDi.DVr)<br>SL0 0<br>Selected settings<br>SL1 1 6-bit counter<br>SL2 2 (UFCVi.CVr)<br>SL3 3<br># 0<br># 1<br>RQCi.UFCCr<br>.<br>. Stop level<br>Stop level . was reached<br># 63<br>**----- End of picture text -----**<br>

**Figure 45.28 Overview of an Unread Frame Counter**

Unless synchronization of hardware and software is lost, the current unread frame counter value (UFCVi.CVr) indicates the number of unread frames in the queue.

When the stop level has been reached, received frames are not stored in the descriptor chain. Setting 0 as the stop level disables the stop function. Otherwise, further received frames for the queue are discarded once its unread frame counter reaches the stop level. Activation of the unread frame counter stop function is indicating by setting of the receive queue full interrupt flag in the receive interrupt status register 2 (RIS2.QFFr).

Set the unread frame counter stop level configuration register (UFCS) for each reception queue that will use the unread frame counter function while the current operating mode is configuration mode.

## (1) Loss of Unread Frame (UFC) Synchronization

The unread frame counters do not recognize failure to store a frame in the on-chip RAM. In other words, the AVB-DMAC increments the counter for a queue each time it captures a frame for that queue from the reception FIFO whether or not it succeeds in storing the frame normally in the descriptor chain.

In general, synchronization of hardware and software may be lost under the following conditions.

- An unread frame counter reaching its maximum value When the value of a counter in an unread frame counter register i (UFCVi) (i = 0 to 4) reaches 63, synchronization for the corresponding queue can be lost.

   - It can only be judged that a loss of synchronization has not occurred when the stop level is set to 63.

- A queue not having enough space for a descriptor or the associated data In this case, the corresponding receive queue full interrupt flag (RIS2.QFFr) in receive interrupt status register 2 (RIS2) is set.

   - If an unread frame counter reaches its stop level, the receive queue full interrupt flag (RIS2.QFFr) in the receive interrupt status register 2 (RIS2) is set.

- A problem occurring during access to memory

The result of a failure in synchronization is the unread frame counter indicating that the corresponding descriptor chain contains more available frames than it actually does. To retrieve the correct starting point for operations, use the descriptor base address load request (DLR.LBAq) for the given queue.

## 45.3.5 Transmission Control

Areas in the on-chip RAM for storing transmission descriptors must also be secured (for descriptors, see section 45.3.3, Descriptors ).

The AVB-DMAC fetches data from the on-chip RAM in accord with the procedure the descriptor describes. The descriptor also retains tag information once the frame has been fetched for transmission. The tag information is used to maintain the relationships between state information and time stamps for the software and the AVB-DMAC. The status and time stamp information for transmitted frames remains accessible after their transmission is completed.

## 45.3.5.1 Transmission Modes

The AVB-DMAC has two modes of transmission.

- AVB transmission mode

This mode is selected by the priority level setting for the transmission queue in the transmit configuration register (setting of the TGC.TQP[1:0] bits) being B’01 or B’11.

- Non-AVB transmission mode

This mode is selected by the priority level setting for the transmission queue in the transmit configuration register (setting of the TGC.TQP[1:0] bits) being B’00.

- (1) AVB Transmission Mode

AVB transmission supports the control of traffic through the output port to implement various traffic classes.

## (a) Support for Traffic Classes and Associated Priority

When transmission is in AVB transmission mode, streams of traffic are transmitted in accord with the part of the AVB specification called Forwarding and Queuing for Time Sensitive Streams (FQTSS; for details on this, see the IEEE 802.1Q standard).

In the AVB specification, at least one queue for a reserving stream under the Stream Reservation Protocol (SR stream) and at least one queue for a non-SR stream are present, and the queues for reserved traffic according to the SRP have highest priority.

The AVB-DMAC supports four traffic classes: SR class A, SR class B, network control (NC) traffic (gPTP frames), and best effort (BE) traffic. Allocating a specific queue to network control (NC) frames ensures the control of synchronization.

The AVB-DMAC realizes compliance with the AVB standards by handling queues with the following architecture (in terms of traffic classes).

- Four transmission queues (Q3, Q2, Q1, and Q0) are available.

- Q3 and Q2 are for SR streams (one each for class A and class B).

- Q1 is for low-bandwidth network control (NC) traffic (gPTP frames)

- [1] *[2]

- Q0 is for other types of traffic (MSRPDU , MVRPDU , best effort (BE), etc.)

## CAUTIONS

1. MSRPDU: Multiple Stream Registration Protocol Data Unit

2. MVRPDU: Multiple VLAN Registration Protocol Data Unit

Fetching from queues proceeds in order of priority of the above traffic types. Three systems of priority are available through the setting of the transmit queue priority bits in the transmit configuration register (TGC.TQP[1:0]). In the default priority scheme, which is called AVB mode 1 (selected by TGC.TQP[1:0] = B’01), operation of the AVB-DMAC is fully in accord with the AVB specification. AVB mode 2 (transmit queue priority bits (TGC.TQP[1:0] = B’11) is an alternative priority scheme and varies from the AVB specification. Using this scheme thus requires more care.

**Table 45.78 Default and Alternative Priority Orders in AVB Transmission Mode**

|**Priority Schemes (AVB Mode)**|**Priority Order of Queues**|
|---|---|
|AVB mode 1|Q3 (SR class A) > Q2 (SR class B) > Q1 (NC) > Q0 (BE)|
|AVB mode 2|Q1 (NC) > Q3 (SR class A) > Q2 (SR class B) > Q0 (BE)|

## (b) Transmission Selecting Algorithm and CBS

The algorithm the AVB-DMAC applies to select frames for transmission is in accord with the IEEE 802.1Q standard. For AVB mode, the CBS (credit-based shaping) algorithm is applied to the class A and class B SR queues (Q3 and Q2). Use of the CBS enables correct handling of the priorities of transmission from the SR queues. For the CBS algorithm, see section 45.3.6, CBS (Credit-Based Shaping) .

When the following conditions are both satisfied, transmission from an SR queue (Q3 or Q2) proceeds at the specified time.

- The queue contains at least one frame ready for transmission.

- The queue has credit.

- Unless an SR queue satisfies the above conditions, a higher priority queue is not present (not ready for transmission).

A non-SR queue (Q1 or Q0) is selected if the conditions below both hold.

- The queue contains at least one frame ready for transmission.

- As well as the above condition, a higher priority queue is not present (not ready for transmission).

Figure 45.29 and Figure 45.30 are flowcharts of selection for transmission in AVB mode 1 and AVB mode 2.

**==> picture [230 x 402] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start:<br>Checking to see<br>which frame is next<br>for transmission<br>Does Q3 hold<br>Yes<br>a frame and<br>have available<br>credit?<br>Transmit<br>No from Q3.<br>Does Q2 hold<br>a frame and  Yes<br>have available<br>credit?<br>Transmit<br>No from Q2<br>Yes<br>Does Q1 hold<br>a frame?<br>No<br>Transmit<br>from Q1<br>Yes<br>Does Q0 hold<br>a frame?<br>No<br>Transmit<br>from Q0<br>**----- End of picture text -----**<br>

**Figure 45.29 Flow of Selection for Transmission in AVB Mode 1**

**==> picture [230 x 415] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start:<br>Checking to see<br>which frame is next<br>for transmission<br>Yes<br>Does Q1 hold<br>a frame?<br>Transmit<br>No<br>from Q1<br>Does Q3 hold<br>Yes<br>a frame and<br>have available<br>credit?<br>Transmit<br>No from Q3<br>Does Q2 hold<br>Yes<br>a frame and<br>have available<br>credit?<br>Transmit<br>No from Q2<br>Yes<br>Does Q0 hold<br>a frame?<br>No<br>Transmit<br>from Q0<br>**----- End of picture text -----**<br>

**Figure 45.30 Flow of Selection for Transmission in AVB Mode 2**

## (2) Non-AVB Transmission Mode

In non-AVB transmission mode, an absolute priority scheme is used. The SR class is not supported and the CBS algorithm is not used.

In non-AVB transmission mode (when the transmit queue priority bits in the transmit configuration register (TGC.TQP[1:0]) are B’00), data is fetched for transmission in a strict order of priority (Q3 > Q2 > Q1 > Q0).

Figure 45.31 shows the flow of selection in non-AVB transmission mode.

**==> picture [230 x 415] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start:<br>Checking to see<br>which frame is next<br>for transmission<br>Does Q3 hold  Yes<br>a frame?<br>Transmit<br>No<br>from Q3<br>Does Q2 hold  Yes<br>a frame?<br>Transmit<br>No from Q2<br>Does Q1 hold  Yes<br>a frame?<br>Transmit<br>No from Q1<br>Yes<br>Does Q0 hold<br>a frame?<br>No<br>Transmit<br>from Q0<br>**----- End of picture text -----**<br>

**Figure 45.31 Flow of Selection for Transmission in Non-AVB Mode**

## (3) Setting the Size of the Transmission FIFO

The transmission FIFO is made up of 124 clusters. Each cluster can hold up to 128 bytes.

The size of the part of the transmission FIFO for use by each of the four transmission queues can be set by the corresponding transmit queue configuration q bits in the transmit control register (TGC.TBDq). The maximum number of clusters required can be determined from the maximum length of frames for transmission from the queue q.

Even if queue t already contains data of the frame size specified by TGC.TBDt, the AVB-DMAC fetches the next frame to queue t after the E-MAC starts transfer data from queue t. Therefore, a frame data area of the total of maximum frame sizes set for each transmission queue plus an area for 1 frame must be secured for a cluster.

## General Usage Examples:

Q0: Frames containing up to 1500 bytes → 1500/128 = 11.7 → 12 clusters

Q1: Frames containing up to 1024 bytes → 1024/128 = 8.0 → 8 clusters

Q3: Frames containing up to 1996 bytes → 1996/128 = 15.6 → 16 clusters

Q4: Frames containing up to 1996 bytes → 1996/128 = 15.6 → 16 clusters

When the depth of all transmission queues is 2, only the following number of clusters is required.

2 * (12 + 8 + 16 + 16) + 16 = 2 * 52 + 16 = 120

Adjust the frame length of each queue so that the number of clusters to be used is no greater than 124.

## 45.3.5.2 Setting Up Transmission Descriptors

## (1) Transmission Descriptor Type

The type of a descriptor is defined by the descriptor type (DESCR.DT) field.

Table 45.79 shows the descriptor types used in transmission. In the table, entries in the write-back column indicate how the AVB-DMAC changes the DESCR.DT field upon completion of descriptor processing.

## **Table 45.79 Descriptor Types in Transmission**

|**Descriptor Type**|||
|---|---|---|
|**(DESCR.DT)**|**Operation**|**Write-back**|
|**Frame Start**(FSTART)|The AVB-DMAC fetches the first of the data for the divided frame and proceeds to the next|FEMPTY|
||descriptor.||
|**Frame Middle**(FMID)|The AVB-DMAC fetches the second or subsequent data for the divided frame and|FEMPTY|
||proceeds to the next descriptor.||
|**Frame End**(FEND)|The AVB-DMAC fetches the last of the data for the divided frame.|FEMPTY|
||When the frame of data that has been fetched to the transmission FIFO is ready for||
||transmission by the E-MAC, the AVB-DMAC proceeds to the next descriptor.||
|**Frame Single**|The AVB-DMAC fetches the frame of data.|FEMPTY|
|(FSINGLE)|When the frame of data that has been fetched to the transmission FIFO is ready for||
||transmission by the E-MAC, the AVB-DMAC proceeds to the next descriptor.||
|**Link**(LINK)|Processing proceeds to the descriptor specified by DESCR.DPTR.|LEMPTY|
|**Fixed Link**(LINKFIX)|Same as LINK|Not changed|
|**End Of Set**(EOS)|Clears the transmit start request bit (TCCR.TSRQt), which stops transmission queue.|EEMPTY|
||When the TCCR.TSRQt is again set to 1 (a new transmission start request is issued),||
||processing proceeds to the next descriptor.||
|**Frame Empty**|Clears the transmit start request bit (TCCR.TSRQt), which stops transmission queue.|Not changed|
|(FEMPTY)|When the TCCR.TSRQt is again set to 1 (a new transmission start request is issued),||
||processes this descriptor again.||
|**Link Empty**(LEMPTY)|Same as FEMPTY|Not changed|
|**EOS Empty**(EEMPTY)|Same as FEMPTY|Not changed|

## (2) Configuration of Transmission Frame Data Descriptors

Figure 45.32 shows the configuration of descriptors for use with transmission queues. The transmission-specific fields (DESCR.TSR and DESCR.TAG) are described in Table 45.80 .

For the other fields and the descriptor types, see section 45.3.3.6, Descriptor Type .

**==> picture [432 x 25] intentionally omitted <==**

**----- Start of picture text -----**<br>
31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>+0 DT[3:0] DIE[3:0] - TSR TAG[9:0] DS[11:0]<br>+4 DPTR[31:0]<br>**----- End of picture text -----**<br>

## **Figure 45.32 Configuration of Descriptor for a Transmitted Frame**

**Table 45.80 Configuration of a Transmission Descriptor**

|**Bit Name**|**Function**|
|---|---|
|TSR|Time Stamp Store Request|
||This bit specifies whether the transmission time stamp together with tag|
||information is to be stored within the EthernetAVB module.|
||0: The time stamp status FIFO within the EthernetAVB module does not retain|
||a transmission time stamp.|
||1: The time stamp status FIFO within the EthernetAVB module retains a|
||transmission time stamp.|
||Only control this bit while the current DESCR.DT is FEND or FSINGLE.|
|TAG|Frame Tag|
||This TAG field is used to associate each frame data status with a time stamp.|
||Frame TAG is not required but is recommended.|
||Only control this bit while the current DESCR.DT is FEND or FSINGLE.|

For the time stamp FIFO function, see section 45.3.5.4, Time Stamping in Transmission .

## 45.3.5.3 Transmission

## (1) Transmitting Frames

Setting the transmit start request bit in the transmit configuration control register (TCCR.TSRQt) starts the transfer of frames from the corresponding transmission queue.

The descriptor in the current descriptor address for the queue (CDARq.CDA) is read first.

If this descriptor is a descriptor for frame transmission (FSINGLE, etc.), the AVB-DMAC fetches the frame data from the data area indicated by the descriptor, writes FEMPTY back to the descriptor type (DESCR.DT) bits to indicate completion of this processing, then proceeds to processing of the next descriptor.

If the descriptor is not for transmission, processing is as dictated by the given descriptor (for these descriptors, see the descriptions in section 45.3.3, Descriptors ).

If a base address load request is issued for a descriptor chain while it is being processed (by setting 1 in the LBAq bit for transmission queue q that is currently being processed in the descriptor base address load request register, DLR), processing proceeds to the new descriptor chain (descriptor base table address bits (DBAT.TA) + 8*q). Loading the base address does not interrupt frame fetching, but note that frames that have not been fetched from the old chain remain where they are.

Figure 45.33 shows descriptor processing during transmission. “Fxxx” in the figure indicates the frame data descriptors (FSTART, FMID, FEND, FSINGLE).

**==> picture [398 x 279] intentionally omitted <==**

**----- Start of picture text -----**<br>
<SW><br>Prepare descriptor<br>chain in the descriptor<br>base address table.  <HW><br>Set address to the<br>DBAT register. Set the transmit  DBAT Fetch the base descriptor of the DBAT from transmission queue t and start processing at the first FSTART, FMID,  Descriptor data area<br>start request bit  FEND, or FSINGLE indicated by the link.<br>(TCCR.TSRQt) for<br>transmission queue t.<br>DBAT + 8*t LINKFIX<br><HW><br>Read the FSTART, FMID, FEND,<br>Fxxx or FSINGLE descriptor, read<br>the relevant frame data,<br>Fxxx write back FEMPTY to DT,<br><HW> then fetch the next descriptor.<br>When DIE ! = 0, an interrupt signal<br>is generated after the processing<br>of all descriptors for a frame or an<br>FSINGLE descriptor, and normal frame transmission proceeds. Fxxx <HW><br>EOS Stop fetching at EOS.<br><SW>Set TCCR.TSRQt to resume  Fxxx Fetch the next descriptor after TCCR.TSRQt is set again.<br>descriptor fetching. LINK<br><HW><br><SW>Issue a request to load the base address for the queue. Fxxx Fetch the descriptor indicated by the DPTR field of the LINK descriptor.<br><HW> Fxxx<br>Return to DBAT + 8*t. Fxxx<br><HW><br>FEMPTY Fxxx Stop fetching at FEMTPY.<br>Fxxx When TCCR.TSRQt is set again,<br><SW> AVB-DMAC fetches the new descriptor<br>Change FEMPTY to FSTART, FMID, FEND,  at the same position in the chain.<br>FSINGLE, etc. and set TCCR.TSRQt to the<br>AVB-DMAC resumes descriptor fetching. <SW>: Software processing<br><HW>: Hardware (AVB-DMAC) processing<br>**----- End of picture text -----**<br>

**Figure 45.33 Descriptor Processing During Transmission**

## (2) Examples of Descriptor Usage

- (a) Immediate Frame Transmission

Immediate frame transmission is a method in which fetching by the AVB-DMAC starts whenever software adds data to a queue. FEMPTY descriptors are used as stop points to keep the hardware and software in synchronization.

As preparation in transmission, software creates descriptor chains that have FEMTPY descriptors.

Figure 45.34 shows the flow for subsequent process.

**==> picture [262 x 244] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Does the chain include  Wait for sufficient FEMPTY<br>enough FEMPTY  No descriptors to become available<br>descriptors to handle the  or create new FEMPTY<br>frame data? descriptors within the chain.<br>Yes<br>Add frame data for the<br>current descriptor.<br>Change the descriptor type<br>from FEMPTY to the descriptor type<br>for the frame data.<br>Write 1b to TCCR.TSRQt.<br>End<br>**----- End of picture text -----**<br>

**Figure 45.34 Software Flow for Immediate Frame Transmission**

When processing a divided frame, change the types of descriptors in the backward direction, i.e., from FEND to FSTART. This guarantees all the descriptors including frame data to be ready when the AVBDMAC starts fetching divided frames.

Figure 45.35 shows software and AVB-DMAC operations for divided frame transmission. In the figure, software and hardware independently perform processing. This allows software to prepare the descriptor for frame n + 1 even when the AVB-DMAC is currently fetching frame n.

**==> picture [383 x 147] intentionally omitted <==**

**----- Start of picture text -----**<br>
<HW1><br>Fetch data for frame n,<br>FSTART FEMPTY change the descriptor type<br>FMID FEMPTY after fetching each time,<br>Frame n and stop at the pre-fetching<br>FMID FEMPTY FEMPTY.<br>FEND FEMPTY <HW2><br><SW2><br>Change FEMPTY to FEMPTY Stop at FEMPTY and leave<br>FSTART and write 1b toTCCR.TSRQt. FEMPTYFEMPTY FMIDFMID Frame n+1 TCCR.TSRQt clear untilSW2 step 2.<br><SW1> FEMPTY FMID<br>Write the data for frame n+1 and FEMPTY FEND<br>change the types of descriptors FEMPTY<br>other than the first within the chain.<br><SW>: Software processing<br><HW>: Hardware (AVB-DMAC) processing<br>**----- End of picture text -----**<br>

**Figure 45.35 Software and AVB-DMAC Operation Examples for Immediate Frame Transmission (divided frames)**

## (b) Frame Set Transmission with Switching of the Active Descriptor Chain

This method is used when data are transmitted with a delay for software control to secure bandwidth or for other reasons, rather than immediately transmitted. EOS descriptors are used for the stop points.

As preparation in transmission, software creates descriptor chains that have FEMTPY descriptors.

Figure 45.36 shows the flow for subsequent process.

In the first task, software creates and adds a transmission frame to the descriptor chain, which is followed by EOS descriptor insertion.

In the second task, software processes the transmission trigger for the transmission descriptor prepared. This guarantees transmission of a frame set per trigger.

No particular operation is necessary for synchronization between two tasks. If not enough frame sets are prepared when the transmit start request bit in the transmit configuration control register (TCCR.TSRQt) is set, only the prepared frame sets are transmitted. If nothing is prepared in the queue, only clearance of a transmission request is performed.

**==> picture [385 x 189] intentionally omitted <==**

**----- Start of picture text -----**<br>
Software processing to add a frame set Software processing to schedule the transmission of frame sets<br>Start Start<br>Wait until transmission is triggered<br>(e.g. by a regular software timer<br>descriptors to handle the Does the chain include enough FEMPTY frame data? No descriptors to become available or create new FEMPTY descriptors Wait for sufficient FEMPTY  interrupt).<br>within the chain. Bandwidth error: the bandwidth<br>Yes of the previous set completed Was transmission  No for E-MAC transmission is not sufficient to handle transmission at the<br>Add frame data for the  (TCCR.TSRQt = 0b)? frequency of the transmission trigger. This error must be handled<br>descriptors. by software.<br>Yes<br>Change the descriptor type from<br>FEMPTY to the descriptor types<br>of the frame data. Write 1b to TCCR.TSRQt<br>End<br>Add EOS to the descriptor chain<br>when the frame set is full<br>(maximum size per transfer).<br>End<br>**----- End of picture text -----**<br>

**Figure 45.36 Software Flow for Frame Set Transmission with Switching of the Active Descriptor Chain**

In a given time, the AVB-DMAC does not use the descriptor chain area currently being updated by software; therefore, descriptor types for a divided frame can be changed in any order.

Figure 45.37 shows software and AVB-DMAC operation examples in this method.

**==> picture [378 x 195] intentionally omitted <==**

**----- Start of picture text -----**<br>
FSTART FEMPTY<br>FMID FEMPTY <HW1><br>Frame set n Fetch the descriptors<br>FMID FEMPTY for frame n.<br>FEND FEMPTY<br><HW2><br>EOS<br><SW1> Stop at EOS, clear<br>Write the data for frame set n+1 FEMPTY FSTART TCCR.TSRQt, and<br>and change the descriptor types FEMPTY FEND wait until SW step 3 is<br>within the chain. FEMPTY FSTART Frame set n+1completed.<br>FEMPTY FMID<br>FEMPTY FEND<br><SW2><br>Add EOS at the end of FEMPTY EOS<br>the frame set FEMPTY<br><SW3><br>When the frame is ready for<br><SW>: Software processing<br>transmission, confirm that<br>TCCR.TSRQt = 0b and write 1b to <HW>: Hardware (AVB-DMAC) processing<br>TCCR.TSRQt.<br>**----- End of picture text -----**<br>

**Figure 45.37 SW and AVB-DMAC Operation Examples for Frame Set Transmission with Switching of the Active Descriptor Chain**

## (c) Frame Set Transmission Using a Shadow Descriptor Chain

This method is used when data are transmitted with a delay for software control to secure bandwidth or for other reasons, rather than immediately transmitted. Two or more descriptor chains are used. The chains are classified as active or shadow chains. Software prepares frame data in shadow chain and descriptor while hardware processes active chain. EOS or FEMPTY descriptors are used for the stop points.

As preparation in transmission, software creates a shadow descriptor chain that has a FEMPTY descriptor, and creates a frame data descriptor in an active chain. Software then sets the transmit start request bit (TCCR.TSRQt) to start transmission of the active chain. During active chain transmission, software can prepare frame data for the shadow chain.

Figure 45.38 shows the flow for software implementing this method.

**==> picture [384 x 158] intentionally omitted <==**

**----- Start of picture text -----**<br>
Software processing to add a frame to the shadow chain. Frame set scheduling for transmission by software processing<br>Start Start<br>Wait until transmission is triggered<br>(e.g. by a regular software timer interrupt).<br>Does the shadow chain include  No<br>enough FEMPTY descriptors to handle  Create new FEMPTY  Bandwidth error: the bandwidth<br>the frame data? descriptors in the  for E-MAC transmission is not<br>shadow chain. Was transmission of the active  No sufficient to handle transmission<br>Yes (TCCR.TSRQt = 0b)?chain completed  at the frequency of the transmission trigger. This error must be handled<br>Add frame data for the descriptors. by software.<br>Yes<br>Change the descriptor type from FEMPTY  Write the base address of the shadow chain to the descriptor base address table. End<br>to the descriptor types of the frame data.<br>Write 1b to DLR.LBAq. The shadow chain<br>Confirm that FEMPTY or EOS is at the  becomes the new active chain, and the<br>end of the shadow chain as the hardware  active chain becomes the new shadow chain.<br>stopping point.<br>End Write 1b to TCCR.TSRQt.<br>**----- End of picture text -----**<br>

**Figure 45.38 Software Flow for Frame Set Transmission Using the Shadow Descriptor Chain**

Figure 45.39 shows software and AVB-DMAC operation examples in this method.

**==> picture [388 x 175] intentionally omitted <==**

**----- Start of picture text -----**<br>
Shadow chain Active chain<br>FEMPTY FSTART FEMPTY FEMPTY <HW1><br>FEMPTY FEND FEMPTY FEMPTY Fetch the descriptors forframe n.<br>FEMPTY FSTART FEMPTY FEMPTY<br>FEMPTY FMID FEMPTY FEMPTY Frame set n<br>FEMPTY FEND FEMPTY FEMPTY<br>Frame set n+1<br>FEMPTY FSTART FEMPTY FEMPTY<br>FEMPTY FMID FEMPTY FEMPTY<br><SW1><br>Write the data to for frame set FEMPTY FMID FEMPTY <HW2><br>n+1 and change the descriptor FEMPTY FMID Stop at FEMPTY, clear<br>types within the chain. FEMPTY FEND TCCR.TSRQt, and wait until<br>FEMPTY <SW step 3> is completed.<br><HW3><br><SW2> Load the base address of the shadow<br>On receiving the transmission trigger signal, confirm chain and start to fetch the shadow chain<br>that TCCR.TSRQt = 0b and write the base address descriptors.<br>of the shadow chain to the descriptor base address<br>table.<br><SW3><br><SW>: Software processing<br>Write 1b to DLR.LBAq and TCCR.TSRQt.<br><HW>: Hardware (AVB-DMAC) processing<br>**----- End of picture text -----**<br>

**Figure 45.39 SW and AVB-DMAC Operation Examples for Frame Set Transmission Using the Shadow Descriptor Chain**

## 45.3.5.4 Time Stamping in Transmission

Transmission time stamps are important in performing timing and synchronization processing of the IEEE 802.1AS standard. Reference to the transmission time stamps can also be useful to other applications and so on. The AVB-DMAC supplies the time-stamp values based on the gPTP timer by storing the time stamps captured at the same time as sending of the Start of Frame Delimiter (SFD) for transmitted frames.

When the time stamp storage request field (DESCR.TSR) is set to 1, selecting storage of a time stamp, the tag number defined in the tag field (DESCR.TAG) of the last descriptor in a set (FEND) or of an FSINGLE descriptor for the frame being transmitted is stored with the time stamp. This eases identification and association. The time-stamp FIFO is accessible at any time.

The method of using this function is described below:

1. Create descriptor and frame data in the on-chip RAM for the frame requiring time stamping. Write the tag number of the frame to the frame tag field (DESCR.TAG) and set the time stamp storage request field (DESCR.TSR) to 1.

2. The AVB-DMAC fetches and analyzes the descriptor. When the time stamp storage request field (DESCR.TSR) is 1, the AVB-DMAC recognizes that transmitting this frame also requires storage of the time stamp.

3. The AVB-DMAC fetches the frame data and stores the frame data in the transmission FIFO for scheduling.

4. Under the control of priority settings according to credit-based shaping (CBS) or another scheme, the transmission scheduler decides it is time to transmit frame.

5. The EthernetAVB starts transmission of frame.

6. The gPTP time stamp is captured at the start of sending the frame delimiter (SFD) for transmission and stored with the tag frame field (DESCR, TAG) in the time-stamp FIFO upon completion of the frame transmission. When the time stamp update interrupt is enabled, update of time stamp is notified by an interrupt.

7. The time stamp can now be acquired from the time-stamp FIFO.

Use the time-stamp FIFO for the timing and synchronization of frames with IEEE 802.1AS compliance.

Time stamping can also be used with other frames, but take care not to allow the time-stamp FIFO to overflow. When the time-stamp FIFO is full, further time stamps in subsequent transmissions are not stored.

Figure 45.40 shows software flow in time-stamp FIFO operation. The time stamp FIFO update interrupt status bit (TIS.TFUF) and the time stamp FIFO warning interrupt status bit (TIS.TFWF) are used for the start flag of the START block in the figure.

**==> picture [290 x 245] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Yes<br>TSR.TFFL = 0<br>No<br>END<br>Read time stamp and tag from TFAi.<br>Write 1 to TCCR.TFR.<br>Process read-out time stamp<br>if necessary.<br>**----- End of picture text -----**<br>

**Figure 45.40 Flow of Transmission Time Stamping**

When all the entries in the time-stamp FIFO are released, the time stamp FIFO update interrupt status bit (TIS.TFUF) and time stamp FIFO warning interrupt status bit (TIS.TFWF) are cleared by the AVBDMAC. Therefore, clearing the interrupt flags is not necessary.

When multiple frames are transmitted with time stamps but from different queues, the order of storage in the time-stamp FIFO buffer depends on the order of frames in transmission.

## 45.3.6 CBS (Credit-Based Shaping)

In AVB transmission mode (i.e. when the transmit queue priority field in the transmit configuration register (TGC.TQP) is B’01 or B’11), transmission queues Q3 and Q2 are respectively assigned to class A and class B stream traffic and the CBS (Credit Based Shaping) algorithm is used to select the transmission queues in order to satisfy the Forwarding and Queuing for Time Sensitive Streams (FQTSS) specification (see section 8.6.8 or section 34 in IEEE 802.1Q ).

The CBS algorithm is based on the concept of transmission credit for each queue. Credit can be thought of as the degree to which a queue has the “right” to transmit at a given time. In addition, in AVB transmission mode as specified in IEEE 802.1Q, queues that are subject to the CBS algorithm are able to transmit when the following conditions are met.

- At least one frame is stored in the queue.

- The credit for the queue is 0 or a positive value.

The credit for a transmission queue is incremented while one or more frames from the queue are present in the transmission FIFO but transmission of these frames is not proceeding. This state is indicated by the transmission process status bit for queue t in the AVB-DMAC status register (CSR.TPOt) being clear (0). The credit is decremented while transmission of a frame from the queue is in progress. This mechanism is used to control transmission so that the amount of data for transmission for each queue does not exceed the specified maximum bandwidths.

IEEE 802.1Q defines the following parameters for queues under the control of the CBS algorithm.

**portTransmitRate:** Maximum transmission data rate of an external port. The E-MAC determines this parameter.

**bandwidthFraction:** Maximum fraction of portTransmitRate that can be used for a queue.

**idleSlope** : Rate of change of credit for a queue when transmission of frames from the queue is not proceeding so the credit value (in bits per second) is increasing. idleSlope is also equal to the maximum fraction of the total bandwidth (portTransmitRate) that is available to the given queue under a specified condition (frames from the queue can be placed in a continuous stream. See Annex L of IEEE 802.Q.

idleSlope = bandwidthFraction * portTransmitRate

**sendSlope** : Rate of change of credit (in bits per second) for a queue while transmission of a frame from

the queue is in progress so the credit value is decreasing.

The value of sendSlope is defined as follows: sendSlope = idleSlope - portTransmitRate

Furthermore, the values below are used to define individual traffic classes (or queues for the classes) under control of the algorithm. See Annex L of IEEE 802.Q.

**maxFrameSize:** Maximum size of frames (in bits) of the corresponding traffic class that can be transmitted from a port

**maxInterferenceSize:** Maximum burst size (in bits) by which delays for the corresponding traffic class can be allowed

- **hiCredit:** Maximum credit value (positive number). Can be calculated by using the following equation: hiCredit = maxInterferenceSize * (idleSlope / portTransmitRate)

- **loCredit:** Minimum credit value (negative number). Can be calculated by using the following equation: loCredit = maxFrameSize * (sendSlope / portTransmitRate)

Figure 45.41 shows how the CBS algorithm works and the meaning of the above parameters. When there is no frame to be transmitted in the queue in the transmit-enabled state, the credit value is 0 (after Frame 0 transmission in the figure).

**==> picture [435 x 326] intentionally omitted <==**

**----- Start of picture text -----**<br>
Credit<br>hiCredit<br>idleSlope<br>idleSlope sendSlope sendSlope<br>0<br>Time<br>idleSlope<br>loCredit<br>Queue<br>depth<br>3 Frame 3<br>2 Frame 2 Frame 3<br>1 Frame 0 Frame 1 Frame 2 Frame 3<br>0<br>Time<br>Transmitted<br>data<br>Fr.<br>Interfering traffic 0 Interfering traffic Frame 1 Frame 2 Interfering traffic Frame 3<br>Time<br>**----- End of picture text -----**<br>

**Figure 45.41 CBS (Credit-Based Shaping) Operation**

Figure 45.42 shows the operation of CBS (Credit Based Shaping) in the AVB-DMAC.

**==> picture [390 x 203] intentionally omitted <==**

**----- Start of picture text -----**<br>
EthernetAVB<br>AVB-DMAC<br>ET_TXD[3:0]<br>ET_TXCLK<br>CIVR0 MAC<br>Class B credit counter I/F E-MAC PHY<br>CDVR0<br>CUL0 portTransmitRate<br>CLL0<br>CIVR1<br>Class A credit counter<br>CDVR1<br>CUL1<br>CLL1<br>Internal bus clock<br>**----- End of picture text -----**<br>

## **Figure 45.42 CBS (Credit-Based Shaping) Operation in the AVB-DMAC**

The CBS operation in the AVB-DMAC is based on “credit counters” for the respective traffic classes (SR class A and class B). The following parameters apply for these classes.

CBS increment value (CIV): Signed positive number

The credit is incremented by this amount every internal bus clock cycle while a frame from the queue is pending but transmission has not started (idleSlope).

CBS decrement value (CDV): Signed negative number

The credit is decremented by this amount every internal bus clock cycle while transmission of a frame from the queue is proceeding (sendSlope).

The CBS increment value (CIV) and CBS decrement value (CDV) are defined as follows.

CIV = idleSlope * Mfactor

CDV = sendSlope * Mfactor

Mfactor is a multiplier factor to ensure accuracy for CIV and CDV. CIV and CDV are finally calculated by using the following equations.

> CIV = (portTransmitRate/B  ) * bwFraction * Mfactor

> CDV = (portTransmitRate/B  ) * (bwFraction - 1) * Mfactor

The credit counters are driven by the internal bus clock (B  ), so calculating the slope parameters for CBS requires (1/B  ).

Mfactor must be calculated for the CBS parameters. All queues for the same class must have the same CBS parameters. Mfactor for a certain class can be changed during operation, unless transmission is pending for that class (i.e. the transmit process status bit in the AVB-DMAC status register (CSR.TPOt) = 0). At that time, the credit counter values for class are 0. Note that the credit value will

not match a new incrementation or decrementation parameter if Mfactor is changed while the credit counter value is non-zero. Mfactor configuration register is not present in the AVB-DMAC.

Set the CIV and CDV parameters in the CBS increment value registers (CIVRc) and the CBS decrement value registers (CDVRc). They should be dynamically updated when streams are registered and erased in accord with IEEE 802.1Qat.

Although the credit counters operate with the internal bus clock (Bφ), a transmission clock is used in frame transmission. Therefore, time lags occur when frame transmission starts and ends.

For this reason, an extra credit is stored after a frame is transmitted. The maximum value of the credit to be stored is the credit value incremented for one cycle of the Bφ clock and equals the Tx port transmission rate in Mbps * Bφ.

Bandwidth needs to be secured by software taking this into account.

The AVB-DMAC also has CBS upper limit registers (CULc) (the upper limit registers for classes A and B) and CBS lower limit registers (CLLc) (the lower limit registers for classes A and B). Multiply the upper limit (hiCredit) and the lower limit (loCredit) by Mfactor for each class as defined above so that the resulting values agree with the credit values.

CUL = hiCredit * Mfactor = maxInterferenceSize * bwFraction * Mfactor

CLL = loCredit * Mfactor = maxFrameSize * (bwFraction - 1) * Mfactor

## Example:

> Assume that portTransmitRate = 100 Mbps, B  = 130 MHz and bwFraction = 3%. Then idleSlope and sendSlope represented as one bit vs. cycles of the peripheral bus clock are as follows.

> idleSlope = (portTransmitRate/B  ) * bwFraction = 100/130 (Mbps/MHz) * 3% = 0.023 (bit/B 

sendSlope =  idleSlope - (portTransmitRate / B  ) = -0.746 (bit/B 

Let Mfactor be 100, then CIV and CDV parameters are determined as follows.

CIV = idleSlope * Mfactor = 23

CDV = sendSlope * Mfactor = -74.6

## 45.3.6.1 Restrictions on CIV, CDV and Mfactor

The maximum value (the minimum value for negative numbers) up to which the credit counter will not overflow determines the maximum values of CIV and CDV that can be set in the CBS registers. This maximum credit value is equivalent to the worst case of the hiCredit value, and the maximum values for class A and class B are calculated as follows.

<Conditions>

- Class A maximum value (hiCredit_max_classA) classA bwFraction  100%

   - Maintaining the proper relations in the transmission priority order requires waiting for a period equivalent to the one maximum sized frame.

   - hiCredit_max_classA  maxInterferenceSize for class A = Waiting for a period equivalent to one maximum sized frame = header + maximum size payload + CRC (2000 bytes) + preamble (8 bytes) + IFG (12 bytes) + processing_delay (  80 bytes)  2100 bytes

- Class B maximum value (hiCredit_max_classB) classB bwFraction  100%

   - Maintaining the proper relations in the transmission priority order requires waiting for a period equivalent to the respective one maximum sized frame in the class A transmission queue and other transmission queues.

hiCredit_max_classB  maxInterferenceSize for class B = Waiting for a period equivalent to two maximum sized frames = 2* hiCredit_max_classA  4200 bytes

In bit units, calculated as follows:

hiCredit_max_classA = 16800

hiCredit_max_classB = 33600

The 32-bit signed counter can handle from -2[31] to 2[31] -1, so the specifiable maximum values of Mfactor without overflow are:

Mfactor_max_classA = 2[31] -1 / hiCredit_max_classA  127826 and Mfactor_max_classB = 2[31] -1 / hiCredit_max_classB  63913.

A high degree of accuracy can be achieved even with a low bandwidth. In class B, bandwidthFraction = 0.05% and the bandwidth error < 0.1%.

The maximum value of CIV is calculated from the following equation.

> CIV = idleSlope x Mfactor = (portTransmitRate / B  * bandwidthFraction × Mfactor

When Mfactor is the maximum value and bandwidthFraction is the maximum value (up to 100%):

CIV_max_classA = (portTransmitRate / B  * Mfactor_max_classA and CIV_max_classB = (portTransmitRate / B  * Mfactor_max_classB.

The maximum values when portTransmitRate = 100 Mbps and B  = 130 MHz are as follows:

CIV_max_classA  98328

CIV_max_classB  49164

Table 45.81 shows examples of values for portTransmitRate and internal bus clock frequency. The values in this table are just the results of calculation, so when actually setting values, the CIV values must be limited so that the 32-bit credit counter will not overflow. In the AVB-DMAC, the CIV parameters are implemented as 16 bits + a sign bit, so CIV  65535 should be applied to both class A and class B.

**Table 45.81 Example of Maximum Values for Class A and Class B CIV Parameters**

|**portTransmitRate**|||**B****[MHz]**||**CIV_max_classA**||**CIV_max_classB**||
|---|---|---|---|---|---|---|---|---|
||100|Mbps||100||127826||63913|
||100|Mbps||125||102260||51130|
||100|Mbps||133||96109||48054|

## 45.3.6.2 Credit Incrementation (IFGs)

In the CBS credit counter in the AVB-DMAC, the inter-frame gap (IFG) after a frame is transmitted is not treated as part of frame transmission. During an IFG, the credit is incremented for all SR queues that have pending frames or negative credit. Figure 45.43 illustrates credit operations during IFGs.

**==> picture [374 x 234] intentionally omitted <==**

**----- Start of picture text -----**<br>
Queue x<br>credit<br>idleSlope<br>sendSlope<br>sendSlope<br>0<br>idleSlope Time<br>Transmitted<br>data<br>IFG IFG IFG<br>Qx Frame x Qx Frame x Qy Frame y<br>Time<br>**----- End of picture text -----**<br>

**Figure 45.43 Credit Operations during IFGs**

The IFG need not be included in calculation of the bandwidth for the specified SR class when deciding the idleSlope, sendSlope, and CIV and CDV parameters. However, IFG must also be included in the calculation in order to confirm that the total bandwidth allocated to all SR classes does not exceed 100% of portTransmitRate.

## 45.3.6.3 CBS Setting Example

The case of a class A 48-kHz stereo audio stream among Ethernet frames is described as an example.

After every class A measurement interval (125 us), 80 octets consisting of two sets of six 32-bit samples plus a 32-octet header are stored as audio data within a frame. The IEEE 802.3 also imposes a 42-octet media-specific frame overhead (an 8-octet preamble, 14-octet IEEE 802.3 header, 4-octet IEEE 802.1Q priority/VID Tag, 4-octet CRC, and 12-octet IFG) are also added. Accordingly, the total frame size is 80 + 42 = 122, and one such frame is transmitted after every class measurement interval.

This represents a total bandwidth of about 7.8 Mbits per second (122 octets × 8 bits per octet × 8000 frames per second) for this class. The E-MAC runs at 100 Mbps (portTransmitRate), so the allocation of the total bandwidth to each class A queue corresponds to 7.8%. If other traffic classes are to share the total transmission bandwidth, checking that the total allocation of bandwidth with this 7.8% allocation does not exceed 100% of portTransmitRate is required.

To obtain the CIV and CDV parameters for a given class, the IFG must not be taken into account in calculation of the frame size. For this case, therefore, we obtain the total bandwidth for the class = about 7.04 Mbps (110 octets × 8 bits per octet × 8000 frames per second) = 7.04% of portTransmitRate.

**==> picture [386 x 166] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet AVB<br>AVB-DMAC<br>ET_TXD[3:0]<br>CIVR1 MAC<br>E-MAC PHY<br>CDVR1 Class A credit counter I/F<br>CUL1 portTransmitRate<br>CLL1<br>ET_TXCLK<br>Internal bus clock<br>**----- End of picture text -----**<br>

## **Figure 45.44 Example of CBS Settings**

In this setting example, operating frequency and so on in each section are as follows:

- the E-MAC runs at 100 Mbps, so portTransmitRate = 100 Mbps and

- high-speed internal bus clock (operating clock for the credit counter) frequency = 133 MHz,

securing a bandwidth of 7.04 Mbits/sec for class A requires configuring the CBS parameters as follows.

- bandwidthFraction = 7.04%

- idleSlope = (portTransmitRate / B  ) * bandwidthFraction  0.05293 bits per B 

- sendSlope = idleSlope – (portTransmitRate / B  )  -0.69895 bits per B 

When Mfactor = 10000, the parameters are as follows.

- CIV = idleSlope × Mfactor = 529 bits per B 

- CDV = sendSlope × Mfactor = -6989 bits per B 

These are the final values for setting in the CIVR1 and CDVR1 registers.

## 45.3.7 IEEE802.1: gPTP

## 45.3.7.1 gPTP Timer

An 84-bit timer is provided to support the gPTP function. Figure 45.45 shows the overview of the timer.

**==> picture [385 x 175] intentionally omitted <==**

**----- Start of picture text -----**<br>
After reaching 10 [9] -1, the<br>Increment register(28 bits) nanoseconds value wraps around to zero. + The increment register value is added to the gPTP timerevery clock cycle.<br>gPTP timer<br>(64 + 20 bits) Seconds Nanoseconds Fraction of nanoseconds<br>+ (32 bits) (32 bits) (20 bits)<br>Offset register<br>(80 bits)<br>Seconds Nanoseconds<br>= (48 bits) (only the 30 lower-order bits are valid)<br>Corrected gPTP timer<br>(80 bits)<br>Seconds Nanoseconds<br>(48 bits) (32 bits)<br>**----- End of picture text -----**<br>

**Figure 45.45 gPTP Timer**

The higher-order 32 bits indicate seconds. For the next 32 bits indicate nanoseconds. The lower-order 20 bits indicate fractional nanoseconds. Software can only read the 32 higher-order bits, indicating seconds, and the subsequent 32-bits, indicating nanoseconds. The 20 lower-order 20 bits, representing less than 1 ns, are provided within the AVB-DMAC to maintain accuracy in time measurement, and cannot be referenced.

The timer can be reset by setting the timer control request bits in the gPTP configuration control register (GCCR.TCR[1:0]) to B’01. These bits are set to B’00 on completion of normal resetting of the timer.

After the timer starts, the value in the gPTP timer increment value bit (GTI.TIV) is added to the value of the gPTP timer every clock cycle. When the value of the nanosecond part reaches 10[9] - 1, it returns to 0 when the next 1 nanosecond is counted. The fractional nanosecond value is represented by 20 bits and can be adjusted in precision of 1/2[20] (1/1048576) nanosecond.

Before setting a value in the gPTP timer increment value bit (GTI.TIV), set the timer increment value setting request bit in the gPTP configuration control register (GCCR.LTI) to 1. If this bit is not set to 1, new values that are written will not be reflected in the register. This bit returns to 0 after the setting is completed.

An offset to the gPTP timer is also available. If this is required, set the value in the timer offset value bit (GTO.TOV). Before setting a value in this register, set the timer offset value setting request bit in the gPTP configuration control register (GCCR.LTO) to 1. If this bit is not set to 1, new values that are written will not be reflected in the register. This bit returns to 0 after the setting is completed. Set the value from 0 to 10[9] - 1 to the timer offset value bits (GTO0.TOV[31:0]) in the nanoseconds portion. When adding an offset, take care that the calculation result with the offset added does not exceed 80 bits.

The value of the gPTP timer can be read from the gPTP timer capture value bit (GCTi.CTV) by setting the timer control request bits in the gPTP timer control register (GCCR.TCR[1:0]) to B’11. Set the timer capture source select bits in the gPTP configuration control register (TCCR.TCSS) to select the timer value for capture as the value of the gPTP timer, the corrected value of the gPTP timer (value with the offset added), or the AVTP presentation time. Setting the timer control request bits in the gPTP configuration control register (GCCR.TCR[1:0]) to B’11 initiates the capture. Once normal capture of the timer is complete, the value of the timer control request bits in the gPTP configuration control register (GCCR.TCR[1:0]) returns to B’00.

The timer for gPTP operates as a free-running timer but can be synchronized with the Grandmaster clock.

The timer clock source can be selected from the internal bus clock and Ethernet transmission clock by setting the gPTP clock select bits (CCC.CSEL[1:0]).

## 45.3.7.2 Free-Running Operation

The IEEE 802.1 AS standard does not prescribe the adjustment of local clocks to the Grandmaster clock. To avoid negative effects from the correction procedure, we recommend the use of a freerunning timer.

As a free-running timer, the timer counts the local clock based on the local time. The gPTP timer increment value bit (GTI.TIV) is set to 1 ns (the setting value = H’0010 0000) and the timer offset value bit (GTOi.TOV) is set to 0. The ratio information captured at the time of the gPTP delay measurement and synchronization procedures is used to correct the frequency ratio to that of the Grandmaster clock. The Grandmaster clock can be calculated from the local clock by using the information collected during the gPTP measurement and synchronization procedures.

## 45.3.7.3 Synchronization with the Grandmaster Clock

In situations requiring physical synchronization of the local clock with the Grandmaster clock, the fractional nanoseconds value (the 20 lower-order bits of the gPTP timer) is used to make the adjustment. Specifically, the increment value is finely adjusted to correct for deviations of the clock frequency from that of the Grandmaster clock.

Use the timer offset value bit (GTOi.TOV) to correct for offsets for comparing with the absolute time and so on from start-up. The sum of the timer value and the offset register is the corrected gPTP timer value.

Set the value from 0 to 10[9] - 1 to the timer offset value bits (GTOi.TOV[31:0]) for setting the nanoseconds portion of the offset.

The following equation gives a method of calculating the increment (GTI.TIV) from the frequency of the gPTP clock and its deviation from that of the Grandmaster clock. Variable d is the deviation (d = 10[-6] for 1 ppm).

**==> picture [405 x 65] intentionally omitted <==**

After calculating the new offset value, re-set the timer offset configuration register (GTOi.TOV).

- Sample setting 1

When fGPTP = 100 MHz  0 ppm (device used is guaranteed by the Grandmaster clock)

gPTP is updated every 10 ns.

Set the gPTP timer increment value bits (GTI.TIV) to H’00A0_0000.

- Sample setting 2

When fGPTP = 100 MHz - 10 ppm gPTP is updated every 10 ns.

Set the gPTP timer increment value bits (GTI.TIV) to H’00A0_0069 (10485864.8576 before rounded off). Rounding off the value causes a frequency error less than 1 ppm.

## 45.3.7.4 Support Provided by the gPTP Timer in Transmission and Reception

The timer value described above is used in the time-stamp values captured when start frame delimiters are detected in reception and generated in transmission.

Captured time stamp values for received frames are stored in the corresponding descriptors. Those for transmitted frames are stored with tag information in the time-stamp FIFO. The time stamp values are thus correlated with both transmitted and received frames.

Note that the use of corrected gPTP timer values can introduce an error due to the offset correction in the gPTP synchronization procedure.

Errors due to SFD notification and the interface between the timer modules must also be taken into account. Although SFDs for transmission and reception are detected in synchronization with the transmission and reception clocks, respectively, the gPTP operates with a gPTP clock. Therefore, an error of ± 1 GTI.TIV + 1 Bφ is generated.

## 45.3.8 Support for IEEE 1722

For IEEE 1722, the following two functions are supported.

- Output and capture of values in the IEEE 1722 AVTP (Audio/Video Transport Protocol) presentation time format

- Comparison of IEEE 1722 AVTP presentation time stamps

The 32-bit AVTP time stamp field of IEEE 1722 frames holds the AVTP presentation time when the AVTP time-stamp enable bit in the frame is 1. The AVTP time stamp field is generated from the pPTP timer and is given as seconds (gPTP_seconds) and nanoseconds (gPTP_nanoseconds) according to the following equation.

AVTP time stamp = (gPTP_seconds * 10[9] + gPTP_nanoseconds) modulo 2[32]

The AVTP presentation time can be read from the gPTP timer capture value bit (GCTi.CTV). Set the timer capture source select bits in the gPTP configuration control register (TCCR.TCSS) to select the timer value for capture as the AVTP presentation time. Setting the timer control request bits in the gPTP configuration control register (GCCR.TCR[1:0]) to B’11 initiates the capture. The value stored as the capturing result is obtained by adding the maximum transit time defined in the maximum transit time bits (GMTT.MTTV) to the corrected gPTP timer value. The AVTP presentation time wraps around approximately every four seconds.

## CAUTION

The AVTP presentation time captured in GCTi.CTV is only valid when the corrected gPTP timer value is in synchronization with the Grandmaster clock. That is, the timer increment and timer offset values for the corrected gPTP timer value must be adjusted by the synchronization procedure so that the corrected gPTP clock is adjusted to match the time kept by the Grandmaster clock.

## 45.3.9 Flow Control

The E-MAC supports flow control for full-duplex operation in compliance with the IEEE 802.3 standards. This flow control is applicable to both reception and transmission. In regard to the transmission of PAUSE frames, flow control operates in the following ways.

- (1) Automatic PAUSE Frame Transmission

For the received frames, PAUSE frames are automatically transmitted when the amount of data having been written in the reception FIFO reaches the value specified by the receive FIFO caution level bits in the receive configuration register (RCR.RFCL). The TIME parameter contained in the PAUSE frame can be specified by the automatic PAUSE frame register (APR). If the maximum count of PAUSE frame retransmission times is not specified, PAUSE frames are automatically transmitted repeatedly until the data is read from the reception FIFO and the remaining data amount becomes smaller than the value specified by the RCR.RFCL. As the maximum count of PAUSE frame retransmission times, any value from 1 to 65535 can be specified by the PAUSE frame retransmission count register (TPAUSER). In this case, PAUSE frames are automatically transmitted repeatedly until the remaining data amount becomes smaller than the value specified by the RCR.RFCL or the count of retransmission times reaches the value specified by the TPAUSER. The retransmit counter is cleared to 0 when the next PAUSE frame is transmitted once the data amount in the reception FIFO becomes smaller than the value specified by the RCR.RFCL.

Automatic PAUSE frame transmission is enabled when the operating mode bit for flow control in transmission in the E-MAC mode register (ECMR.TXF) is 1.

- (2) Manual PAUSE Frame Transmission

PAUSE frames can also be transmitted in response to software operations. Writing a timer value to the manual PAUSE frame register (MPR) starts the transmission of a PAUSE frame. This only causes the transmission of one PAUSE frame.

- (3) PAUSE Frame Reception

After reception of a PAUSE frame, transmission of the next frame does not proceed until the time indicated by the Timer value elapses. However, transmission of a frame currently being transmitted continues. PAUSE frames are only received while the operating mode for flow control in reception bit in the E-MAC mode register (ECMR.RXF) is set to 1. The number of received PAUSE frames is counted.

- (4) 0 TIME PAUSE Frame Control

The setting of the PAUSE frame usage with TIME = 0 enable bit in the E-MAC mode register (ECMR.ZPF) enables or disables the transmission of PAUSE frames with the TIME parameter value 0. The setting of the PAUSE frame reception with time = 0 bit in the E-MAC mode register (ECMR.RZPF) enables or disables the reception of PAUSE frames with the TIME parameter value 0.

- Operation for transmission

   - When the 0-time PAUSE frame control is enabled, PAUSE frame with the TIME parameter value 0 is transmitted when the capacity of the reception FIFO is less than the value of the receive FIFO caution level bits in the receive configuration register (RCR.RFCR) while the time indicated by the TIME parameter value has not elapsed.

When the 0-time PAUSE frame control is disabled, PAUSE frames with the TIME parameter value 0 are not transmitted.

- Operation for reception

When the 0-time PAUSE frame reception is enabled, frame transmission wait state is released when PAUSE frame with the TIME parameter value 0 is received.

When the 0-time PAUSE frame reception is disabled, received PAUSE frames with the TIME parameter value 0 are discarded.

## 45.3.10 Interrupts

The EthernetAVB module has four interrupts: three interrupts from the AVB-DMAC and one interrupt from the E-MAC. The three interrupts from the AVB-DMAC are generated when the AVB-DMAC is placed in operation mode, and the one interrupt from the E-MAC is generated when the AVB-DMAC is placed in configuration, operation, or standby mode.

Table 45.82 is a list of the interrupts.

## **Table 45.82 EthernetAVB Interrupts**

|**Interrupt Source Name**|**Remarks**|
|---|---|
|AVB_DATA|Transmit/receive data management interrupt|
|AVB_ERROR|Error management interrupt|
|AVB_MANAGE|Other management (FIFO caution level, etc.) interrupt|
|AVB_MAC|E-MAC interrupt|

The AVB-DMAC related interrupts include descriptor interrupts (15 sources), error interrupts (5 sources), reception interrupts (37 sources), transmission interrupts (2 sources), and gPTP interrupts (3 sources). From the CPU’s perspective, each appears as one of the above four interrupt sources.

The states of an AVB-DMAC-related interrupt sources can be checked in the following registers.

- Descriptor interrupt status register (DIS)

- Error interrupt status register (EIS)

- Receive interrupt status register (RISi)

- Transmit interrupt status register (TIS)

- gPTP interrupt status register (GIS)

The interrupts are controlled by the corresponding interrupt enable bits. However, the status flags operate independently of the settings of the enable bits.

The states of grouped interrupts can be checked by reading the interrupt summary status register (ISS) and the queue full error interrupt status bit in the error interrupt status register (EIS.QFS).

## 45.3.10.1 Transmit/Receive Data Management Interrupt

The management interrupt for transmission and reception is conveyed when the interrupt conditions corresponding to the following sources are satisfied.

- Receive frame interrupt in the receive interrupt status register 0 (RIS0.FRFr)

- Descriptor interrupt in the descriptor interrupt status register (DIS.DPFi)

## 45.3.10.2 Error Management Interrupt

The error management interrupt is conveyed when interrupt conditions corresponding to the following sources are satisfied.

- Time stamp FIFO full error interrupt in the error interrupt status register (EIS.TFFF)

- CBS limitation value error interrupts in the error interrupt status register (EIS.CULF1, EIS.CULF0, EIS.CLLF1, EIS.CLLF0)

- Receive FIFO full interrupt in the receive interrupt status register 2 (RIS2.RFFF)

- Receive queue full interrupt in the receive interrupt status register 2 (RIS2.QFFr)

## 45.3.10.3 Other Management (FIFO Warning, etc.) Interrupts

The other management (FIFO warning, etc.) interrupt is conveyed when interrupt conditions corresponding to the following sources are satisfied.

- (1) Reception related interrupt

Receive FIFO warning interrupt in the receive interrupt status register 1 (RIS1.RFWF)

- (2) Transmission related interrupts

Time stamp FIFO warning interrupt in the transmit interrupt status register (TIS.TSWF)

Time stamp FIFO update interrupt in the transmit interrupt status register (TIS.TSUF)

- (3) gPTP related interrupts

Presentation time match interrupt in the gPTP interrupt status register (GIS.PTMF)

## 45.3.10.4 E-MAC Interrupt

The E-MAC interrupt is conveyed when the following E-MAC interrupt sources are generated.

- PAUSE frame retransmit retry over interrupt in the E-MAC status register (ECSR.PFROI)

- Illegal carrier detection interrupt in the E-MAC status register (ECSR.ICD)

## 45.3.11 Flows of Operations

## 45.3.11.1 Flow of E-MAC Initialization

Figure 45.46 shows the flow of E-MAC initialization.

**==> picture [377 x 328] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit setting definition<br>S: Arbitrary value is set.<br>0: 0 is set.<br>1: 1 is set.<br>Ethernet<br>F/W EthernetAVB PHY-LSI (MII)<br>Set MAC address MAC address high register<br>SSSS SSSS SSSS SSSS SSSS SSSS SSSS SSSS (MAHR)<br>0000 0000 0000 0000 SSSS SSSS SSSS SSSS MAC address low register<br>(MALR)<br>Set MAC address E-MAC mode register<br>0000 0S00 0000 0000 0000 0000 0000 0010 (ECMR)<br>Set Max frame length Receive frame length register<br>0000 0000 0000 0000 0000 SSSS SSSS SSSS (RFLR)<br>Limitation on H’0000 0800: 2 Kbytes<br>Set Interrupt enable E-MAC interrupt enable register<br>0000 0000 0000 0000 0000 0000 0000 0000 (ECSIPR)<br>E-MAC does not start transmission or reception at this point.<br>PHY Registers access PHY interface register<br>(PIR)<br>Check the PHY-LSI specification before<br>setting the PHY register.<br>**----- End of picture text -----**<br>

**Figure 45.46 Flow of E-MAC Initialization**

## 45.3.11.2 Flow of AVB-DMAC Initialization

Figure 45.47 shows the flow of AVB-DMAC initialization.

**==> picture [386 x 322] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>On-chip RAM F/W EthernetAVB PHY-LSI (MII)<br>Check operating mode AVB-DMAC status register<br>Operating mode status bits<br>Reset mode? CSR.OPS[3:0] = 1 (RESET)<br>Set operating mode Operating mode configuration bitsAVB-DMAC mode register<br>Reset mode →Configuration mode CCC.OPC[1:0] = 1<br>Check operating mode AVB-DMAC status register<br>Operating mode status bits<br>Configuration mode? CSR.OPS[3:0] = 2 (CONFIG)<br>See E-MAC initialization flow. E-MAC initialization<br>Select gPTP clock source gPTP clock source select bitsAVB-DMAC mode register<br>gPTP clock select bits (CCC.CSEL[1:0])<br>B’00: gPTP is not in use.<br>B’01: Internal bus clock (Bɸ)<br>B’10: Ethernet transmission clock (ET_TXCLK)<br>B’11: External clock (AVB_GPTP_EXTERN)<br>Set base address of descriptor table Descriptor base address register<br>Set the address of the descriptor table in the on-chip  (DBAT)<br>RAM.<br>Descriptor setting<br>Set transmission/<br>reception descriptors. Check operating mode AVB-DMAC mode register<br>Operating mode configuration bits<br>Configuration mode → Operation mode CCC.OPC[1:0] = 2<br>Check operating mode AVB-DMAC status register<br>Operating mode status bits<br>Operation mode? CSR.OPS[3:0] = 4<br>**----- End of picture text -----**<br>

**Figure 45.47 Flow of AVB-DMAC Initialization**

## 45.3.11.3 Flow for the AVB-DMAC in Reception

Figure 45.48 shows the flow for the AVB-DMAC in reception.

**==> picture [397 x 560] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>On-chip RAM F/W EthernetAVB PHY-LSI (MII)<br>See AVB-DMAC initialization flow.  Set configuration mode<br>to initialize E-MAC.<br>Setting for descriptor interrupt  Descriptor interrupt control register<br>(DIC)<br>Setting for reception Receive configuration register<br>Receive configuration register (RCR)<br> Receive FIFO critical level (RFCL)  H’1800<br> Time stamp enable bit (ETS2)  0<br> Time stamp enable bit (ETS0)  0<br> Filtering enable bit (ESF)  10, 11<br> Network control filtering enable bit (ENCF)  1/0<br> Incomplete frame enable bit (EFFS)  0<br>Setting for reception queues Receive queue configuration<br>Receive queue configuration register  register i (RQCi)<br>(reception queues 0 to 17)<br> Setting of the unread frame counter (UFFC)  00<br> Receive synchronous mode (RSM)               00<br>Setting for reception padding Receive padding<br>Receive padding configuration register configuration register (RPC)<br> Data counter value (DCNT)         188 bytes<br> Padding counter value (PCNT)    4<br>Setting for separation filter offset Separation filter offset register<br>(SFO)<br>Separation filter offset register<br> For VLAN:  SFO.FBP[5:0] = 14<br> For stream ID: SFO.FBP[5:0] = 22<br>Setting for separation filter pattern Separation filter<br>pattern register (SFP)<br>Separation filter pattern register<br> For VLAN: 0000 0000 0000 SSSS<br> For stream ID: SSSS SSSS SSSS SSSS<br> Set an arbitrary value to “S”.<br>Setting for separation filter mask Separation filter<br>mask register (SFM)<br>Set link descriptors Separation filter mask register For VLAN: 0000 0000 0000 FFFF<br>DT[3:0] = 4'd9  For stream ID: FFFF FFFF FFFF FFFF<br>Tx  queue0 (BE frames)Tx  queue1 (NC frames) DPTR[31:0] = Descriptor pointerDIE[3:0] = 4'd0 “1” compare  “0” don’t care<br>Tx  queue2 (Class B frames)<br>Tx  queue3 (Class A frames)<br>Rx  queue0 (BE frames)<br>Rx  queue1 (NC frames)<br>Rx  queue2 (TS0 frames) DT[3:0] = 4'd9<br>DIE[3:0] = 4'd0<br>DPTR[31:0] = Descriptor pointer<br>Rx  queue15 (TS13 frames) DPTR[31:0] = Descriptor pointer<br>Rx  queue16 (TS14 frames)Rx  queue17 (TS15 frames) DPTR[31:0] = Descriptor pointer<br>Total 22 Link descriptors DPTR[31:0] = Descriptor pointer<br>These descriptors must be allocated in<br>the contiguous areas.<br>Set reception descriptors<br>DT[3:0] = FEMPTY<br>DIE[3:0] = arbitrary<br>DS[11:0] = Received data size<br>DPTR[31:0] = Reception data storage pointer<br>DT[3:0] = FEMPTY<br>DIE[3:0] = arbitrary<br>DS[11:0] = Received data size<br>DPTR[31:0] = Reception data storage pointer<br>DT[3:0] = LINK, LINKFIX, EOS<br>DIE[3:0] = arbitrary<br>See AVB-DMAC initialization flow.<br>The descriptor chains specified by LINK or LINKFIX must be allocated in the contiguous areas. Set operation mode.<br>Enable reception E-MAC mode register<br>E-MAC mode register: Receive enable bit (ECMR)<br>ECMR.RE = 1 Ethernet<br>Ethernet MAC Frame Frame<br>Descriptor read<br>For MAC Frame<br>Data transfer Header part<br>Descriptor write back<br>Descriptor read For MAC Frame<br>Data transfer payload part<br>Descriptor write back<br>Descriptor interrupt signal (when interrupt is enabled)<br>Read interrupt status Descriptor interrupt<br>status register (DIS)<br>Descriptor interrupt processing<br>**----- End of picture text -----**<br>

**Figure 45.48 Flow for the AVB-DMAC in Reception**

## 45.3.11.4 Flow for the AVB-DMAC in Transmission

## Figure 45.49 shows the flow for the AVB-DMAC in transmission.

**==> picture [396 x 559] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>On-chip RAM F/W EthernetAVB PHY-LSI (MII)<br>See AVB-DMAC initialization flow.  Set configuration mode<br>to initialize E-MAC.<br>Setting for descriptor interrupt Descriptor interrupt control register<br>(DIC)<br>Setting for transmission Transmit configuration register<br>(TGC)<br>Transmit configuration register<br> Transmit data size (TBD0-3[3:0])     2<br> Transmit queue priority (TQP[1:0])   B’01 (AVB mode 1)<br>Transmit synchronous mode (TSM0-3)   0 (normal mode)<br>Transmission configuration control Transmit configuration<br>control register (TCCR)<br>Setting for CBS increment CBS increment value register 0,1<br>(CIVr)<br>Setting for CBS decrement CBS decrement value register 0,1<br>(CDVr)<br>Setting for CBS upper limit CBS upper limit register 0,1<br>(CULr)<br>Setting for CBS lower limit CBS lower limit register 0,1<br>(CLLr)<br>Set link descriptors<br>DT[3:0] = 4'd9<br>Tx  queue0 (BE frames) DIE[3:0] = 4'd0<br>Tx  queue1 (NC frames) DPTR[31:0] = Descriptor pointer<br>Tx  queue2 (Class B frames)<br>Tx  queue3 (Class A frames)<br>Rx  queue0 (BE frames)<br>Rx  queue1 (NC frames)<br>Rx  queue2 (TS0 frames) DT[3:0] = 4'd9<br>DIE[3:0] = 4'd0<br>DPTR[31:0 ]= Descriptor pointer<br>Rx  queue15 (TS13 frames)Rx  queue16 (TS14 frames) DPTR[31:0] = Descriptor pointer<br>Rx  queue17 (TS15 frames) DPTR[31:0] = Descriptor pointer<br>Total 22 Link descriptors DPTR[31:0] = Descriptor pointer<br>These descriptors must be allocated in the contiguous areas. Set transmission<br>descriptors<br>DT[3:0] = FSTART, FSINGLE<br>DIE[3:0] = arbitrary<br>DS[11:0] = Transmit data size<br>DPTR[31:0] = Transmit data storage pointer<br>DT[3:0] = FMD, FEND<br>DIE[3:0] = arbitrary<br>DS[11:0] = Transmit data size<br>DPTR[31:0] = Transmit data storage pointer<br>DT[3:0] = LINK, LINKFIX, EOS<br>DIE[3:0] = arbitrary<br>The descriptor chains specified by LINK or LINKFIX must be allocated in<br>the contiguous areas.<br>Set data for transmission See AVB-DMAC initialization flow.<br>Set operation mode.<br>Enable transmission E-MAC mode register<br>E-MAC mode register: Transmit enable bit (ECMR)<br>ECMR.TE = 1<br>Request for starting transmission Transmit configuration<br>Transmit configuration control register:  control register (TCCR)<br>transmission start request bits<br>TCCR.TSRQ0,1,2,3 = 1<br>Descriptor read<br>For MAC Frame<br>Data transfer Header part<br>Descriptor write back<br>Ethernet MAC Frame Ethernet<br>Frame<br>Descriptor read<br>Data transfer For MAC Frame payload part<br>Descriptor write back<br>Ethernet<br>Descriptor interrupt signal (when interrupt is enabled) Ethernet MAC Frame Frame<br>Read interrupt status Descriptor interrupt<br>status register (DIS)<br>Descriptor interrupt processing<br>**----- End of picture text -----**<br>

**Figure 45.49 Flow for the AVB-DMAC in Transmission**

## 45.3.11.5 Flow for Stopping AVB-DMAC Operation in Reception

Figure 45.50 shows the flow for stopping AVB-DMAC operation in reception.

**==> picture [376 x 175] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>F/W EthernetAVB PHY-LSI (MII)<br>Disable reception E-MAC mode register<br>E-MAC mode register: Reception enable bit (ECMR)<br> ECMR.RE = 0<br>Wait for completion of reception process AVB-DMAC status register<br>(CSR)<br>Wait until the receive process bit in the AVB-DMAC status<br>register CSR.RPO = 0<br>Reception is stopped<br>**----- End of picture text -----**<br>

## **Figure 45.50 Flow for Stopping AVB-DMAC Operation in Reception**

## 45.3.11.6 Flow for Stopping AVB-DMAC Operation in Transmission

Figure 45.51 shows the flow for stopping AVB-DMAC operation in transmission.

**==> picture [376 x 175] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>F/W EthernetAVB PHY-LSI (MII)<br>Wait for completion of transmission request Transmit configuration control<br>Wait until the transmission start request bits in the transmit  register (TCCR)<br>configuration control register TCCR.TSR0 to TSR3 are all<br>set to 0.<br>Wait for completion of transmission process AVB-DMAC status register<br>(CSR)<br>Wait until the transmit process status 0 to 3 bits in the AVB-<br>DMAC status register CSR.TPO0 to TPO3 are all set to 0.<br>Disable transmission E-MAC mode register<br>E-MAC mode register: Transmit enable bit (ECMR)<br>ECMR.TE = 0<br>Transmission is stopped<br>**----- End of picture text -----**<br>

**Figure 45.51 Flow for Stopping AVB-DMAC Operation in Transmission**

## 45.3.11.7 Flow for Stopping and Resetting the AVB-DMAC

Figure 45.52 shows the flow for stopping and resetting the AVB-DMAC.

**==> picture [379 x 174] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>F/W EthernetAVB PHY-LSI (MII)<br>Processing to stop transmission/reception<br>Request for transmission suspension AVB-DMAC mode register<br>(CCC)<br>AVB-DMAC mode register: Data transmission suspend request bit<br>CCC.DTSR = 1 Accessing on-chip<br>RAM is stopped<br>Wait for completion of transmission suspension AVB-DMAC status register<br>(CSR)<br>Wait until the data transfer suspend status bit in the AVB-DMAC status register<br>CSR.DTS = 1.<br>Operating mode = Reset mode AVB-DMAC mode register<br>AVB-DMAC mode register: Operating mode configuration bit  (CCC)<br>CCC.OPC = B’ 00<br>Wait for completion of transition to reset mode AVB-DMAC status register<br>(CSR)<br>Wait until the data transmit status flag in the AVB-DMAC status register<br>CSR.OPS = B’ 0001.<br>Reset mode<br>**----- End of picture text -----**<br>

**Figure 45.52 Flow for Stopping and Resetting the AVB-DMAC**

## 45.3.11.8 Flow for Emergency Stopping the AVB-DMAC

Figure 45.53 shows the flow for emergency stopping the AVB-DMAC.

**==> picture [379 x 175] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>F/W EthernetAVB PHY-LSI (MII)<br>Request for transmission suspension AVB-DMAC mode register<br>(CCC)<br>AVB-DMAC mode register: Data transmission suspend request bit<br>CCC.DTSR = 1 Accessing on-chip<br>RAM is stopped<br>Wait for completion of transmission suspension AVB-DMAC status register<br>(CSR)<br>Wait until the data transfer suspend status bit in the AVB-DMAC status register<br>CSR.DTS = 1.<br>Operating mode = Reset mode AVB-DMAC mode register<br>AVB-DMAC mode register: Operating mode configuration bit   (CCC)<br>CCC.OPC = B’00<br>Wait for completion of transition to reset mode AVB-DMAC status register<br>(CSR)<br>Wait until the data transmit status bit in the AVB-DMAC status register<br>CSR.OPS = B’0001.<br>Reset mode<br>Note: Data in the transmission/reception FIFO are invalid.<br>To resume communications, initialize the E-MAC and<br>AVB-DMAC.<br>**----- End of picture text -----**<br>

**Figure 45.53 Flow for Emergency Stopping the AVB-DMAC**

## 45.3.11.9 Flow of gPTP Initialization

Figure 45.54 shows the flow of gPTP initialization.

**==> picture [384 x 181] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>F/W EthernetAVB PHY-LSI (MII)<br>AVB-DMAC<br>Operating mode = operation mode<br>Setting for timer increment value gPTP timer increment configuration<br>register (GTI)<br>Setting for timer offset value gPTP timer offset configuration<br>register i (GTOi (i = 0 to 2))<br>Request for timer incrementation and offset setting gPTP configuration control<br>gPTP configuration control register: Timer increment/offset value  register (GCCR)<br>configuration request bits<br>GCCR.LTI  = 1<br>GCCR.LTO = 1<br>Wait for completion of timer increment and offset request gPTP configuration control register (GCCR)<br>gPTP configuration control register: Timer increment/offset value  GCCR.LTI/LTO = 0?<br>configuration request bits<br>Wait until GCCR.LTI = 0 and GCCR.LTO = 0<br>**----- End of picture text -----**<br>

**Figure 45.54 Flow of gPTP Initialization**

## 45.3.11.10 Flow of gPTP Time Stamping in Transmission

Figure 45.55 shows the flow of gPTP time stamping in transmission.

**==> picture [381 x 292] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>On-chip RAM F/W EthernetAVB PHY-LSI (MII)<br>gPTP initialization<br>Tagged network control frame<br>Set transmission queue 1<br>Setting for time stamp FIFO related interrupts Transmit interrupt control<br>register (TIC)<br>Transmission processing<br>Start of Frame Delimiter (SFD)<br>Capture the time stamp.<br>Store the time stamp with the tag number<br>into FIFO.<br>Time stamp FIFO update interrupt<br>Check time stamp FIFO update interrupt status bit. Transmit interrupt status register<br>(TIS)<br>Clear time stamp FIFO update interrupt status bit. Transmit interrupt status register<br>(TIS)<br>TIS.TFUF = 0<br>Read time stamp value Time stamp FIFO access registers 0 to 2<br>(TFA0 to TFA2)<br>Release time stamp FIFO Transmit configuration control register<br>Transmit configuration control register: Time stamp FIFO release  (TCCR)<br>bit TCCR.TFR = 1<br>**----- End of picture text -----**<br>

**Figure 45.55 Flow of gPTP Time Stamping in Transmission**

## 45.3.11.11 Flow of gPTP Time Stamping and Synchronization in Reception

Figure 45.56 shows the flow of gPTP time stamping and synchronization in reception.

**==> picture [367 x 325] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>On-chip RAM F/W EthernetAVB PHY-LSI (MII)<br>gPTP initialization<br>Enable network control filter Receive configuration register<br>(RCR)<br>Receive configuration register:<br>Network control filtering enable bit<br>RCR.ENCF = 1<br>Set reception interrupt (network control) Receive  interrupt control<br>register 0 (RIC0)<br>Receive interrupt control register 0:<br>Receive frame interrupt enable bit 1 (network control)<br>RIC0.FRE1 = 1<br>Set unread frame counter (reception queue 1) Receive queue configuration<br>register 0 (RQC0)<br>Receive queue configuration register 0:<br>Unread frame counter configuration bit<br>RQC0.UFCC = B’ 00<br>Set reception synchronous mode Receive queue configuration<br>Receive queue configuration register 0: register 0 (RQC0)<br>Reception synchronous mode bit 1<br>RQC0.RSM1 = B’ 00<br>Set descriptors<br>Reception processing<br>Request for reception frame interrupt<br>Check reception frame interrupt status Receive interrupt status register 0<br>Receive interrupt status register 0 (RIS0)<br>Receive frame interrupt status bit 1 (RIS0.FRF1)<br>Clear reception frame interrupt flag Receive interrupt status register 0<br>Receive interrupt status register 0 (RIS0)<br>Receive frame interrupt status bit 1 (RIS0.FRF 1 = 0)<br>Capture reception time stamp written-<br>back by the descriptor<br>Calculate timer offset<br>Initialize gPTP by setting the calculated timer offset value.<br>**----- End of picture text -----**<br>

**Figure 45.56 Flow of gPTP Time Stamping and Synchronization in Reception**

## 45.3.11.12 Flow of Capturing AVTP Presentation Times

Figure 45.57 shows the flow of capturing AVTP presentation times.

**==> picture [374 x 175] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>F/W EthernetAVB PHY-LSI (MII)<br>Set maximum transition time gPTP maximum transit time configuration<br>register (GMTT)<br>Request for configuring maximum transition time gPTP configuration control<br>register (GCCR)<br>gPTP configuration control register: Maximum transit time<br>configuration request bit  GCCR.LMTT = 1<br>Select AVTP presentation time gPTP configuration control<br>gPTP configuration control register:  register (GCCR)<br>timer capture source select bit GCCR.TCSS  = B’ 10<br>Request for capturing AVTP presentation times gPTP configuration control<br>gPTP configuration control register: Timer control request bit GCCR.TCR = B’ 11 register (GCCR)<br>Wait for completion of capturing AVTP presentation time gPTP configuration control<br>gPTP configuration control register: Timer control request bitWait until  GCCR.TCR = B’ 00 register (GCCR)<br>Capture AVTP presentation times gPTP capture timer registers 0 to 2)<br>(GCT0 to GCT2)<br>**----- End of picture text -----**<br>

**Figure 45.57 Flow of Capturing AVTP Presentation Times**

## 45.3.11.13 Flow of AVTP Presentation Time Comparison

Figure 45.58 shows the flow of AVTP presentation time comparison.

**==> picture [374 x 172] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>F/W EthernetAVB PHY-LSI (MII)<br>Set maximum transition time gPTP maximum transit time configuration<br>register (GMTT)<br>Request for configuring maximum transition time gPTP configuration control<br>gPTP configuration control register:  register (GCCR)<br>Maximum transit time configuration request bit<br>GCCR.LMTT = 1<br>Set value for comparison with gPTP presentation time  gPTP presentation time comparison register<br>(GPTC)<br>Request for setting value for gPTP presentation time comparison gPTP configuration control<br>gPTP configuration control register:  register (GCCR)<br>Presentation time comparison value setting request bit<br>GCCR.LPTC = 1<br>Presentation match interrupt<br>Check gPTP interrupt status register gPTP interrupt status register<br>gPTP interrupt status register: (GIS)<br>Presentation time match interrupt flag bit (GIS.PTMF = 1?)<br>**----- End of picture text -----**<br>

**Figure 45.58 Flow of AVTP Presentation Time Comparison**

## 45.3.11.14 Flow of Loopback Mode Operation

Figure 45.59 shows the flow of loopback mode operation.

**==> picture [374 x 177] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ethernet<br>On-chip RAM F/W EthernetAVB PHY-LSI (MII)<br>Initialize E-MAC<br>Initialize AVB-DMAC<br>Set loopback mode AVB-DMAC operating mode<br>register (CCC)<br>AVB-DMAC mode register: Loopback mode enable bit<br>CCC.LBME = 1<br>Set descriptors for<br>reception processing<br>Set descriptors for<br>transmission processing<br>**----- End of picture text -----**<br>

**Figure 45.59 Flow of Loopback Mode Operation**

## 45.3.12 Connection to PHY-LSI

## 45.3.12.1 MII Frame Transmission/Reception Timing

Each MII frame transmission/reception timing is shown in Figure 45.60 to Figure 45.63 .

**==> picture [346 x 88] intentionally omitted <==**

**----- Start of picture text -----**<br>
ET_TXCLK<br>ET_TXEN<br>Preamble SFD Data CRC<br>ET_TXD[3:0]<br>ET_TXER<br>**----- End of picture text -----**<br>

**Figure 45.60 MII Frame Transmit Timing (Normal Transmission)**

**==> picture [349 x 72] intentionally omitted <==**

**----- Start of picture text -----**<br>
ET_RXCLK<br>ET_RXDV<br>Preamble SFD Data CRC<br>ET_RXD[3:0]<br>ET_RXER<br>**----- End of picture text -----**<br>

**Figure 45.61 MII Frame Receive Timing (Normal Reception)**

**==> picture [350 x 72] intentionally omitted <==**

**----- Start of picture text -----**<br>
ET_RXCLK<br>ET_RXDV<br>Preamble SFD Data XXXX<br>ET_RXD[3:0]<br>ET_RXER<br>**----- End of picture text -----**<br>

**Figure 45.62 MII Frame Receive Timing (Reception Error (1))**

**==> picture [351 x 72] intentionally omitted <==**

**----- Start of picture text -----**<br>
ET_RXCLK<br>ET_RXDV<br>XXXX 1110 XXXX<br>ET_RXD[3:0]<br>ET_RXER<br>**----- End of picture text -----**<br>

**Figure 45.63 MII Fame Receive Timing (Reception Error (2))**

## 45.3.12.2 Accessing MII Registers

MII registers in the PHY-LSI are accessed via PIR in this LSI. PIR is used as a serial interface conforming to the MII frame format specified in IEEE802.3u.

## (1) MII Management Frame Format

Figure 45.64 shows the format of an MII management frame. To access an MII register, a management frame is implemented by the program in accordance with the procedures shown in MII Register Access Procedure.

|Access Type<br>MII Management Frame<br>Item<br>Number of bits<br>Read<br>Write<br>PRE<br>32<br>1..1<br>1..1<br>ST<br>2<br>01<br>01<br>OP<br>2<br>10<br>01<br>PHYAD<br>5<br>00001<br>00001<br>REGAD<br>5<br>RRRRR<br>RRRRR<br>TA<br>2<br>Z0<br>10<br>DATA<br>16<br>D..D<br>D..D<br>IDLE<br>X<br>PRE:<br>ST:<br>OP:<br>PHYAD:<br>REGAD:<br>TA:<br>DATA:<br>IDLE:<br>32 consecutive 1s<br>Write of 01 indicating start of frame<br>Write of code indicating access type<br>Write of 0001 if the PHY-LSI address is 1 (sequential write starting with the MSB).<br>This bit changes depending on the PHY-LSI address.<br>Write of 000q if the register address is 1 (sequential write starting with the MSB).<br>This bit changes depending on the PHY-LSI register address.<br>Time for switching data transmission source on MII interface<br>(a) Write: 10 written<br>(b) Read: Bus release (notation: Z0) performed<br>16-bit data. Sequential write or read from MSB<br>(a) Write: 16-bit data write<br>(b) Read: 16-bit data read<br>Wait time until next MII management format input<br>(a) Write: Independent bus release (notation: X) performed<br>(d) Read: Bus already released in TA: control unnecessary<br>[Legend]|Access Type|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|
|---|---|---|---|---|---|---|---|---|---|
||Item|PRE|ST|OP|PHYAD|REGAD|TA|DATA|IDLE|
||Number of bits|32|2|2|5|5|2|16||
||Read|1..1|01|10|00001|RRRRR|Z0|D..D||
||Write|1..1|01|01|00001|RRRRR|10|D..D|X|

**Figure 45.64 MII Management Frame Format**

## (2) MII Register Access Procedure

The program accesses MII registers via PIR. Access is implemented by a combination of 1-bit-unit data write, 1-bit-unit data read, bus release, and independent bus release. Figure 45.65 to Figure 45.68 show the MII register access timing. The timing will differ depending on the PHY-LSI type.

**==> picture [289 x 195] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) Write to PHY interface<br>register<br>ET_MDC<br>PIR.MMD = 1<br>PIR.MDO = write data<br>PIR.MDC = 0 ET_MDIO<br>(2) Write to PHY interface<br>register (1) (2) (3)<br>PIR.MMD = 1 1-bit data write timing<br>PIR.MDO = write data relationship<br>PIR.MDC = 1<br>(3) Write to PHY interface<br>register<br>PIR.MMD = 1<br>PIR.MDO = write data<br>PIR.MDC = 0<br>**----- End of picture text -----**<br>

**Figure 45.65 1-Bit Data Write Flowchart**

**==> picture [289 x 171] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) Write to PHY interface<br>register<br>ET_MDC<br>PIR.MMD = 0<br>PIR.MDC = 0<br>ET_MDIO<br>(2) Write to PHY interface<br>register<br>(1) (2) (3)<br>PIR.MMD = 0<br>PIR.MDC = 1<br>Bus release timing<br>relationship<br>(3) Write to PHY interface<br>register<br>PIR.MMD = 0<br>PIR.MDC = 0<br>**----- End of picture text -----**<br>

**Figure 45.66 Bus Release Flowchart (TA in Read in Figure 45.64)**

**==> picture [289 x 177] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) Write to PHY interface<br>register<br>PIR.MMD = 0 ET_MDC<br>PIR.MDC = 1<br>ET_MDIO<br>(2) Read from PHY<br>interface register<br>PIR.MMD = 0 (1) (2) (3)<br>PIR.MDC = 1<br>1-bit data read timing<br>ET_MDIO is read data. relationship<br>(2) Write to PHY interface<br>register<br>PIR.MMD = 0<br>PIR.MDC = 0<br>**----- End of picture text -----**<br>

**Figure 45.67 1-Bit Data Read Flowchart**

**==> picture [267 x 119] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) Write to PHY interface<br>register<br>ET_MDC<br>PIR.MMD = 0<br>PIR.MDC = 0<br>ET_MDIO<br>(1)<br>Independent bus release<br>timing relationship<br>**----- End of picture text -----**<br>

**Figure 45.68 Independent Bus Release Flowchart (IDLE in Write in Figure 45.64)**

## 45.3.13 Usage Notes

## 45.3.13.1 Checksum Calculation of Ethernet Frames

This LSI is capable of calculating the checksum data of the received frames. Only the data fields of the Ethernet frames are subject to checksum calculation. Specifically, a data field follows the length/type field and is followed by the CRC field. Figure 45.69 shows schematics indicating which parts of the Ethernet frames are calculated. Calculation involves 16-bit addition only; it does not involve bit inversion. Note that when the checksum data is valid, the CRC data (4 bytes) is not transferred as a receive frame, and the checksum data (sum data) is added automatically. Figure 45.70 shows schematics of Ethernet frames to which the checksum data has been added.

## CAUTION

Also for the frames with VLANtag inserted, the 15th byte from the top and the following bytes before the CRC field are subject to calculation.

**==> picture [307 x 180] intentionally omitted <==**

**----- Start of picture text -----**<br>
Destination address Destination address<br>(6 bytes) (6 bytes)<br>Source address Source address<br>(6 bytes) (6 bytes)<br>Type (2 bytes) VLANtag<br>(4 bytes)<br>Type (2 bytes)<br>Data subject to Data subject to<br>Data (46 to 1500 bytes) checksum checksum<br>calculation Data (42 to 1500 bytes) calculation<br>CRC (4 bytes) CRC (4 bytes)<br>Schematic of an Ethernet frame Schematic of an Ethernet frame<br>(without VLANtag) (with VLANtag)<br>**----- End of picture text -----**<br>

**Figure 45.69 Data Subject to Checksum Calculation**

**==> picture [249 x 170] intentionally omitted <==**

**----- Start of picture text -----**<br>
Destination address Destination address<br>(6 bytes) (6 bytes)<br>Source address Source address<br>(6 bytes) (6 bytes)<br>Type (2 bytes) VLANtag<br>(4 bytes)<br>Type (2 bytes)<br>Data (46 to 1500 bytes)<br>Data (42 to 1500 bytes)<br>Sum data Sum data<br>(2 bytes) (2 bytes)<br>Schematic of an Ethernet frame Schematic of an Ethernet frame<br>(without VLANtag) (with VLANtag)<br>**----- End of picture text -----**<br>

**Figure 45.70 Data after Checksum Data Addition**
