# 26. Ethernet Controller

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1347–1440. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI has an on-chip Ethernet controller (ETHER) conforming to the Ethernet or the IEEE802.3 MAC (Media Access Control) layer standard. Connecting a physical-layer LSI (PHY-LSI) complying with this standard enables the ETHER to perform transmission and reception of Ethernet/IEEE802.3 frames. The Ethernet controller in this LSI has one MAC layer interface port, which can be made to perform transmission and reception independently.

The ETHER can transfer the transmitted or received Ethernet frame data to and from the transmit/receive buffer in the memory at high speed using a dedicated direct memory access controller (E-DMAC).

## 26.1 Features

- MAC (Media Access Control) function Constructs/deconstructs data frames (frame format conforming to IEEE802.3, 2000 Edition) Supports transfer at 10 and 100 Mbps

   - Supports full-duplex mode

One channel (ETHER0)

Flow control conforming to IEEE802.3x

Supports one PHY interface conforming to IEEE802.3

- —MII (Media Independent Interface)

Upward protocol support (checksum) function

- E-DMAC (Direct Memory Access Controller for Ethernet controller) function Data transfer between ETHER and external/internal memory

   - One channel

32-byte burst transfer

Supports single-frame/single-descriptor operation and single-frame/multi-descriptor (multi-buffer) operation Transfer data width: 32 bits

Transmit/receive FIFO (for transmission: 2 Kbytes, for reception: 4 Kbytes)

Function for calculating the intelligent checksum value

Figure 26.1 shows the configuration of the ETHER.

**==> picture [158 x 384] intentionally omitted <==**

**----- Start of picture text -----**<br>
Internal bus<br>ETHER<br>E-DMAC<br>DMA transfer processing<br>Descriptor access<br>Receive FIFO Transmit FIFO<br>TSU<br>CAM<br>control<br>E-MAC<br>Receive Transmit<br>processing unit processing unit<br>PHY interface<br>MII<br>PHY<br>**----- End of picture text -----**<br>

**Figure 26.1 Configuration of ETHER**

## 26.2 Input/Output Pins

Table 26.1 lists the pin configuration of the ETHER.

## **Table 26.1 Pin Configuration**

|**Name**|**Abbreviation**|**I/O**|**Function**|
|---|---|---|---|
|Transmit clock|ET_TXCLK*1|Input|ET_TXEN, ET_TXD[3:0] timing reference signal|
|Transmit enable|ET_TXEN*1|Output|Indicates that transmit data is ready on ET_TXD[3:0]|
|MII transmit data|ET_TXD[3:0]*1|Output|MII transmit data|
|Collision detection|ET_COL*1|Input|Collision detection signal|
|Transmit error|ET_TXER*1|Output|Not asserted in the ETHER|
|Receive clock|ET_RXCLK*1|Input|ET_RXDV, ET_RXD[3:0], ET_RXER timing reference signal|
|Receive data valid|ET_RXDV*1|Input|Indicates that valid receive data is on ET_RXD[3:0]|
|MII receive data|ET_RXD[3:0]*1|Input|MII receive data|
|Receive error|ET_RXER*1|Input|Identifies error state occurred during data reception|
|Carrier detection|ET_CRS*1|Input|Carrier detection signal|
|Management data clock|ET_MDC*1|Output|Reference clock signal for information transfer via|
||||ET_MDIO|
|Management data I/O|ET_MDIO*1|I/O|Bidirectional signal for exchange of management|
||||information between STA and PHY|

Note 1. MII signal conforming to IEEE802.3u

## 26.3 Register Descriptions

Table 26.2 shows the configuration of registers of the ETHER.

## **Table 26.2 Register Configuration**

|**Table 26.2**<br>**Register Configuration**|||||
|---|---|---|---|---|
|||||**Access**|
|**Name**|**Abbreviation**|**R/W**|**Address**|**Size**|
|Software reset register|ARSTR|R/W|H'E820 4800|32|
|E-MAC mode register|ECMR0|R/W|H'E820 3500|32|
|E-MAC status register|ECSR0|R/W|H'E820 3510|32|
|E-MAC interrupt permission register|ECSIPR0|R/W|H'E820 3518|32|
|PHY interface register|PIR0|R/W|H'E820 3520|32|
|MAC address high register|MAHR0|R/W|H'E820 35C0|32|
|MAC address low register|MALR0|R/W|H'E820 35C8|32|
|Receive frame length register|RFLR0|R/W|H'E820 3508|32|
|CRC error frame receive counter register|CEFCR0|R/W|H'E820 3740|32|
|Frame receive error counter register|FRECR0|R/W|H'E820 3748|32|
|Too-short frame receive counter register|TSFRCR0|R/W|H'E820 3750|32|
|Too-long frame receive counter register|TLFRCR0|R/W|H'E820 3758|32|
|Residual-bit frame receive counter register|RFCR0|R/W|H'E820 3760|32|
|Multicast address frame receive counter register|MAFCR0|R/W|H'E820 3778|32|
|Automatic PAUSE frame register|APR0|R/W|H'E820 3554|32|
|Manual PAUSE frame register|MPR0|R/W|H'E820 3558|32|
|Automatic PAUSE frame retransmit count register|TPAUSER0|R/W|H'E820 3564|32|
|PAUSE frame transmit counter register|PFTCR0|R|H'E820 355C|32|
|PAUSE frame receive counter register|PFRCR0|R|H'E820 3560|32|
|TSU counter reset register|TSU_CTRST|R/W|H'E820 4804|32|
|CAM entry table specification enable register (common)|TSU_FWSLC|R/W|H’E820 4838|32|
|VLANtag set register|TSU_VTAG0|R/W|H'E820 4858|32|
|CAM entry table busy register|TSU_ADSBSY|R|H'E820 4860|32|
|CAM entry table enable register|TSU_TEN|R/W|H'E820 4864|32|
|CAM entry table POST 1 register|TSU_POST1|R/W|H’E820 4870|32|
|CAM entry table POST 2 register|TSU_POST2|R/W|H’E820 4874|32|
|CAM entry table POST 3 register|TSU_POST3|R/W|H’E820 4878|32|
|CAM entry table POST 4 register|TSU_POST4|R/W|H’E820 487C|32|
|CAM entry table 0H register|TSU_ADRH0|R/W|H'E820 4900|32|
|CAM entry table 1H register|TSU_ADRH1|R/W|H'E820 4908|32|
|CAM entry table 2H register|TSU_ADRH2|R/W|H'E820 4910|32|
|CAM entry table 3H register|TSU_ADRH3|R/W|H'E820 4918|32|
|CAM entry table 4H register|TSU_ADRH4|R/W|H'E820 4920|32|
|CAM entry table 5H register|TSU_ADRH5|R/W|H'E820 4928|32|
|CAM entry table 6H register|TSU_ADRH6|R/W|H'E820 4930|32|
|CAM entry table 7H register|TSU_ADRH7|R/W|H'E820 4938|32|
|CAM entry table 8H register|TSU_ADRH8|R/W|H'E820 4940|32|
|CAM entry table 9H register|TSU_ADRH9|R/W|H'E820 4948|32|
|CAM entry table 10H register|TSU_ADRH10|R/W|H'E820 4950|32|
|CAM entry table 11H register|TSU_ADRH11|R/W|H'E820 4958|32|
|CAM entry table 12H register|TSU_ADRH12|R/W|H'E820 4960|32|

**Table 26.2 Register Configuration**

|**Table 26.2**<br>**Register Configuration**|||||
|---|---|---|---|---|
|||||**Access**|
|**Name**|**Abbreviation**|**R/W**|**Address**|**Size**|
|CAM entry table 13H register|TSU_ADRH13|R/W|H'E820 4968|32|
|CAM entry table 14H register|TSU_ADRH14|R/W|H'E820 4970|32|
|CAM entry table 15H register|TSU_ADRH15|R/W|H'E820 4978|32|
|CAM entry table 16H register|TSU_ADRH16|R/W|H'E820 4980|32|
|CAM entry table 17H register|TSU_ADRH17|R/W|H'E820 4988|32|
|CAM entry table 18H register|TSU_ADRH18|R/W|H'E820 4990|32|
|CAM entry table 19H register|TSU_ADRH19|R/W|H'E820 4998|32|
|CAM entry table 20H register|TSU_ADRH20|R/W|H'E820 49A0|32|
|CAM entry table 21H register|TSU_ADRH21|R/W|H'E820 49A8|32|
|CAM entry table 22H register|TSU_ADRH22|R/W|H'E820 49B0|32|
|CAM entry table 23H register|TSU_ADRH23|R/W|H'E820 49B8|32|
|CAM entry table 24H register|TSU_ADRH24|R/W|H'E820 49C0|32|
|CAM entry table 25H register|TSU_ADRH25|R/W|H'E820 49C8|32|
|CAM entry table 26H register|TSU_ADRH26|R/W|H'E820 49D0|32|
|CAM entry table 27H register|TSU_ADRH27|R/W|H'E820 49D8|32|
|CAM entry table 28H register|TSU_ADRH28|R/W|H'E820 49E0|32|
|CAM entry table 29H register|TSU_ADRH29|R/W|H'E820 49E8|32|
|CAM entry table 30H register|TSU_ADRH30|R/W|H'E820 49F0|32|
|CAM entry table 31H register|TSU_ADRH31|R/W|H'E820 49F8|32|
|CAM entry table 0L register|TSU_ADRL0|R/W|H'E820 4904|32|
|CAM entry table 1L register|TSU_ADRL1|R/W|H'E820 490C|32|
|CAM entry table 2L register|TSU_ADRL2|R/W|H'E820 4914|32|
|CAM entry table 3L register|TSU_ADRL3|R/W|H'E820 491C|32|
|CAM entry table 4L register|TSU_ADRL4|R/W|H'E820 4924|32|
|CAM entry table 5L register|TSU_ADRL5|R/W|H'E820 492C|32|
|CAM entry table 6L register|TSU_ADRL6|R/W|H'E820 4934|32|
|CAM entry table 7L register|TSU_ADRL7|R/W|H'E820 493C|32|
|CAM entry table 8L register|TSU_ADRL8|R/W|H'E820 4944|32|
|CAM entry table 9L register|TSU_ADRL9|R/W|H'E820 494C|32|
|CAM entry table 10L register|TSU_ADRL10|R/W|H'E820 4954|32|
|CAM entry table 11L register|TSU_ADRL11|R/W|H'E820 495C|32|
|CAM entry table 12L register|TSU_ADRL12|R/W|H'E820 4964|32|
|CAM entry table 13L register|TSU_ADRL13|R/W|H'E820 496C|32|
|CAM entry table 14L register|TSU_ADRL14|R/W|H'E820 4974|32|
|CAM entry table 15L register|TSU_ADRL15|R/W|H'E820 497C|32|
|CAM entry table 16L register|TSU_ADRL16|R/W|H'E820 4984|32|
|CAM entry table 17L register|TSU_ADRL17|R/W|H'E820 498C|32|
|CAM entry table 18L register|TSU_ADRL18|R/W|H'E820 4994|32|
|CAM entry table 19L register|TSU_ADRL19|R/W|H'E820 499C|32|
|CAM entry table 20L register|TSU_ADRL20|R/W|H'E820 49A4|32|
|CAM entry table 21L register|TSU_ADRL21|R/W|H'E820 49AC|32|
|CAM entry table 22L register|TSU_ADRL22|R/W|H'E820 49B4|32|
|CAM entry table 23L register|TSU_ADRL23|R/W|H'E820 49BC|32|
|CAM entry table 24L register|TSU_ADRL24|R/W|H'E820 49C4|32|
|CAM entry table 25L register|TSU_ADRL25|R/W|H'E820 49CC|32|

**Table 26.2 Register Configuration**

|**Table 26.2**<br>**Register Configuration**|||||
|---|---|---|---|---|
|||||**Access**|
|**Name**|**Abbreviation**|**R/W**|**Address**|**Size**|
|CAM entry table 26L register|TSU_ADRL26|R/W|H'E820 49D4|32|
|CAM entry table 27L register|TSU_ADRL27|R/W|H'E820 49DC|32|
|CAM entry table 28L register|TSU_ADRL28|R/W|H'E820 49E4|32|
|CAM entry table 29L register|TSU_ADRL29|R/W|H'E820 49EC|32|
|CAM entry table 30L register|TSU_ADRL30|R/W|H'E820 49F4|32|
|CAM entry table 31L register|TSU_ADRL31|R/W|H'E820 49FC|32|
|Transmit frame counter register (normal transmission only)|TXNLCR0|R|H'E820 4880|32|
|Transmit frame counter register (normal and erroneous|TXALCR0|R|H'E820 4884|32|
|transmission)|||||
|Receive frame counter register (normal reception only)|RXNLCR0|R|H'E820 4888|32|
|Receive frame counter register (normal and erroneous|RXALCR0|R|H'E820 488C|32|
|reception)|||||
|E-DMAC start register|EDSR0|W|H'E820 3000|32|
|E-DMAC mode register|EDMR0|R/W|H'E820 3400|32|
|E-DMAC transmit request register|EDTRR0|R/W|H'E820 3408|32|
|E-DMAC receive request register|EDRRR0|R/W|H'E820 3410|32|
|E-MAC/E-DMAC status register|EESR0|R/W|H'E820 3428|32|
|E-MAC/E-DMAC status interrupt permission register|EESIPR0|R/W|H'E820 3430|32|
|Transmit descriptor list start address register|TDLAR0|R/W|H'E820 3010|32|
|Transmit descriptor fetch address register|TDFAR0|R/W|H'E820 3014|32|
|Transmit descriptor finished address register|TDFXR0|R/W|H'E820 3018|32|
|Transmit descriptor final flag register|TDFFR0|R/W|H'E820 301C|32|
|Receive descriptor list start address register|RDLAR0|R/W|H'E820 3030|32|
|Receive descriptor fetch address register|RDFAR0|R/W|H'E820 3034|32|
|Receive descriptor finished address register|RDFXR0|R/W|H'E820 3038|32|
|Receive descriptor final flag register|RDFFR0|R/W|H'E820 303C|32|
|Transmit/receive status copy enable register|TRSCER0|R/W|H'E820 3438|32|
|Receive missed-frame counter register|RMFCR0|R/W|H'E820 3440|32|
|Transmit FIFO threshold register|TFTR0|R/W|H'E820 3448|32|
|FIFO depth register|FDR0|R/W|H'E820 3450|32|
|Receiving method control register|RMCR0|R/W|H'E820 3458|32|
|Receive data padding insert register|RPADIR0|R/W|H'E820 3460|32|
|Overflow alert FIFO threshold register|FCFTR0|R/W|H'E820 3468|32|
|Intelligent checksum mode register|CSMR|R/W|H'E820 34E4|32|
|Intelligent checksum skipped bytes monitor register|CSSBM|R|H'E820 34E8|32|
|Intelligent checksum monitor register|CSSMR|R|H'E820 34EC|32|

## 26.3.1 Software Reset Register (ARSTR)

ARSTR resets all blocks (E-MAC, TSU, and E-DMAC) in the ETHER. By writing 1 to the ARST bit in this register, a software reset is issued to all blocks of the ETHER (for 256 cycles of internal bus clock Bφ). The ARST bit is always read as 0. While a software reset is issued, register access to all blocks of the ETHER is prohibited.

||||Bit:|Bit:|31|30|29|28||27|26|25<br>24|23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|⎯|⎯||⎯|⎯|⎯<br>⎯|⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0|0|0||0|0|0<br>0|0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R|R|R||R|R|R<br>R|R<br>R<br>R|R|R|R|R|R||
||||Bit:||15|14|13|12||11|10|9<br>8|7<br>6<br>5|4|3|2|1|0||
||||||⎯|⎯|⎯|⎯||⎯|⎯|⎯<br>⎯|⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|ARST||
||||Initial value:||0|0|0|0||0|0|0<br>0|0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R|R|R||R|R|R<br>R|R<br>R<br>R|R|R|R|R|R/W||
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**|||**Description**||||||||
|31|to|1|―|||All 0|||R|||Reserved||||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.||||||||
|0|||ARST|||0|||R/W|||Software Reset||||||||
|||||||||||||When 1 is written to this bit, a software reset||||is issued to all blocks of the||||
|||||||||||||ETHER (for 256 cycles of internal bus|||clock Bφ). Writing 0 does not affect|||||
|||||||||||||this bit. This bit is always read as 0. While a software reset is issued,||||||||
|||||||||||||register access to all blocks of the ETHER is||||prohibited. The following||||
|||||||||||||registers are not initialized by a software reset.||||||||
|||||||||||||TSU_ADRH0|to TSU_ADRH31,|TSU_ADRL0 to TSU_ADRL31, TXNLCR0,||||||
|||||||||||||TXALCR0, RXNLCR0, RXALCR0||||||||

## 26.3.2 E-MAC Mode Register (ECMR)

ECMR is a 32-bit readable/writable register that specifies the operating mode of the ETHER. The settings in this register are normally made in the initialization process following a reset.

The operating mode setting must not be changed while the transmitting and receiving functions are enabled. To switch the operating mode, return the E-MAC and E-DMAC to their initial states by means of the SWRT and SWRR bits in EDMR before making settings again.

||Bit:|Bit:|31|30||29|28||27||26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||⎯|⎯||⎯|⎯||⎯|RCSC<br>⎯<br>DPAD<br>RZPF<br>ZPF<br>PFR<br>RXF<br>TXF<br>TRCCM<br>⎯<br>⎯|||
||Initial value:||0|0||0|0||0||0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||R/W:||R|R||R|R||R||R/W<br>R<br>R<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
||Bit:||15|14||13|12||11||10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
||||⎯|⎯||MCT|⎯||⎯||⎯<br>⎯<br>⎯<br>⎯<br>RE<br>TE<br>⎯<br>⎯<br>⎯<br>DM<br>PRM||
||Initial value:||0|0||0|0||0||0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||R/W:||R|R||R/W|R||R||R<br>R<br>R<br>R/W<br>R/W<br>R<br>R<br>R<br>R/W<br>R/W<br>R||
|||||**Initial**|||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**|||**Description**||
|31 to 27|―|||All|0|||R|||Reserved||
||||||||||||These bits are always read as 0. The write value should always be 0.||
|26|TRCCM|||0||||R/W|||Counter Clear Mode||
||||||||||||Sets the method for clearing the counter register. Refer to the description of||
||||||||||||each register.||
||||||||||||0: Cleared to 0 when the relevant register is written||
||||||||||||1: Cleared to 0 when the relevant register is read||
|25, 24|―|||All|0|||R|||Reserved||
||||||||||||These bits are always read as 0. The write value should always be 0.||
|23|RCSC|||0||||R/W|||Checksum Calculation||
||||||||||||Specifies whether to perform automatic calculation (hardware calculation) of||
||||||||||||the checksum of the receive frame data unit.||
||||||||||||0: Checksum is not automatically calculated||
||||||||||||1: Checksum is automatically calculated||
||||||||||||Note that the checksum calculation of a frame with a VLAN tag|is not|
||||||||||||supported. For details, see section 26.6.1, Checksum Calculation of||
||||||||||||Ethernet Frames.||
|22|―|||0||||R|||Reserved||
||||||||||||This bit is always read as 0. The write value should always be 0.||
|21|DPAD|||0||||R/W|||Data Padding||
||||||||||||0: Padding is inserted to data less than 60 bytes so it is transmitted as 60-||
||||||||||||byte data||
||||||||||||1: Padding is not inserted to data less than 60 bytes and it is transmitted||
||||||||||||without changes||
|20|RZPF|||0||||R/W|||PAUSE Frame Reception with TIME = 0||
||||||||||||0: Reception of a PAUSE frame whose TIME parameter value is 0 is||
||||||||||||disabled||
||||||||||||1: Reception of a PAUSE frame whose TIME parameter value is 0 is||
||||||||||||enabled||
|19|ZPF|||0||||R/W|||PAUSE Frame Usage with TIME = 0 Enable||
||||||||||||0: Control of a PAUSE frame whose TIME parameter value is 0|is disabled.|
||||||||||||The next frame is not transmitted until the time specified by the Timer||
||||||||||||value has elapsed. If a PAUSE frame whose time specified by the Timer||
||||||||||||value is 0 is received, that PAUSE frame is discarded.||
||||||||||||1: Control of a PAUSE frame whose TIME parameter value is 0|is enabled.|
||||||||||||When the data size in the receive FIFO becomes smaller than the FCFTR||
||||||||||||setting before the time specified by the Timer value elapses, an automatic||
||||||||||||PAUSE frame with a Timer value of 0 is transmitted. On receiving a||
||||||||||||PAUSE frame with a Timer value of 0, the transmission wait state is||
||||||||||||canceled.||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|18|PFR|0|R/W|PAUSE Frame Receive Mode|
|||||0: PAUSE frame is not transferred to E-DMAC|
|||||1: PAUSE frame is transferred to E-DMAC|
|17|RXF|0|R/W|Operating Mode for Receiving Port Flow Control|
|||||0: PAUSE frame detection is disabled|
|||||1: Flow control for the receiving port is enabled|
|16|TXF|0|R/W|Operating Mode for Transmitting Port Flow Control|
|||||0: Flow control for the transmitting port is disabled|
|||||(Automatic PAUSE frame is not transmitted)|
|||||1: Flow control for the transmitting port is enabled|
|||||(Automatic PAUSE frame is transmitted as required)|
|15, 14|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|13|MCT|0|R/W|Multicast Address Frame Receive Mode|
|||||0: Frames other than the multicast address set by the CAM entry table 0 to|
|||||31 (H/L) registers are received. However, if the on-chip CAM entry table|
|||||reference is disabled, all multicast address frames are received.|
|||||1: Only the multicast address set by the CAM entry table 0 to 31 (H/L)|
|||||registers is received.|
|12 to 7|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|6|RE|0|R/W|Reception Enable|
|||||If a switch is made from receiving function enabled (RE = 1) to disabled (RE|
|||||= 0) while a frame is being received, the receiving function will be enabled|
|||||until reception of the corresponding frame is completed.|
|||||0: Receiving function is disabled|
|||||1: Receiving function is enabled|
|5|TE|0|R/W|Transmission Enable|
|||||If a switch is made from transmitting function enabled (TE = 1) to disabled|
|||||(TE = 0) while a frame is being transmitted, the transmitting function will be|
|||||enabled until transmission of the corresponding frame is completed.|
|||||0: Transmitting function is disabled|
|||||1: Transmitting function is enabled|
|4 to 2|―|0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1|DM|0|R/W|Full-duplex Transfer Enable|
|||||0: Full-duplex transfer function is disabled.|
|||||1: Full-duplex transfer function is enabled.|
|0|PRM|0|R/W|Promiscuous Mode|
|||||Setting this bit enables all Ethernet frames to be received. All Ethernet|
|||||frames means all receivable frames, irrespective of differences or enabled/|
|||||disabled status (destination address, broadcast address, multicast bit, etc.).|
|||||0: ETHER performs normal operation|
|||||1: ETHER performs promiscuous mode operation|

Note: • All bits, except for TE and RE, should be changed while the transmitting function is disabled (TE = 0) and the receiving function is disabled (RE = 0).

## 26.3.3 E-MAC Status Register (ECSR)

ECSR is a 32-bit readable/writable register that indicates the status in the E-MAC. This status can be notified to the CPU by interrupts. When 1 is written to the PFROI and ICD bits, the corresponding flags can be cleared. Writing 0 does not affect the flag. For bits that generate interrupts, the interrupt can be enabled or disabled by the corresponding bit in ECSIPR.

The interrupts generated due to this status register are indicated in the ECI bit in EESR of the E-DMAC.

||Bit:|Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22<br>21<br>20<br>19|18|17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||⎯|⎯|⎯|⎯||⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|⎯<br>⎯||
||Initial value:||0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0<br>0||
||R/W:||R|R|R|R||R|R|R<br>R<br>R<br>R<br>R<br>R<br>R|R|R<br>R||
||Bit:||15|14|13|12||11|10|9<br>8<br>7<br>6<br>5<br>4<br>3|2|1<br>0||
||||⎯|⎯|⎯|⎯||⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>PFROI|⎯|⎯<br>ICD||
||Initial value:||0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0<br>0||
||R/W:||R|R|R|R||R|R|R<br>R<br>R<br>R<br>R<br>R/W<br>R|R|R/W<br>R||
|||||**Initial**||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**||||
|31 to 5|―|||All 0|||R|||Reserved||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||
|4|PFROI|||0|||R/W|||PAUSE Frame Retransmit Retry Over||||
|||||||||||Indicates whether the retransmit count for retransmitting a PAUSE frame||||
|||||||||||when flow control is enabled has exceeded the retransmit upper-limit set in||||
|||||||||||the automatic PAUSE frame retransmit count register (TPAUSER).||||
|||||||||||0: PAUSE frame retransmit count has not exceeded the upper limit||||
|||||||||||1: PAUSE frame retransmit count has exceeded the upper limit||||
|3 to 1|―|||All 0|||R|||Reserved||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||
|0|ICD|||0|||R/W|||Illegal Carrier Detection||||
|||||||||||Indicates that the PHY-LSI has detected an illegal carrier on the line. If a||||
|||||||||||change in the signal input from the PHY-LSI occurs in a period shorter than||||
|||||||||||the software recognition period, the correct information may not be||||
|||||||||||obtained. Refer to the timing specification for the PHY-LSI used.||||
|||||||||||0: PHY-LSI has not detected an illegal carrier on the line||||
|||||||||||1: PHY-LSI has detected an illegal carrier on|the line|||

## 26.3.4 E-MAC Interrupt Permission Register (ECSIPR)

ECSIPR is a 32-bit readable/writable register that enables or disables the interrupt sources indicated by ECSR. Each bit can disable or enable interrupts corresponding to the bits in ECSR.

||Bit:|Bit:|31|30|29|28||27|26|25<br>24<br>23|22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||⎯|⎯|⎯|⎯||⎯|⎯|⎯<br>⎯<br>⎯|⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯||
||Initial value:||0|0|0|0||0|0|0<br>0<br>0|0<br>0<br>0|0|0|0|0||
||R/W:||R|R|R|R||R|R|R<br>R<br>R|R<br>R<br>R|R|R|R|R||
||Bit:||15|14|13|12||11|10|9<br>8<br>7|6<br>5<br>4|3|2|1|0||
||||⎯|⎯|⎯|⎯||⎯|⎯|⎯<br>⎯<br>⎯|⎯<br>⎯<br>PFRO<br>IP|PHYIP|LCHN<br>GIP|MPDIP|ICDIP||
||Initial value:||0|0|0|0||0|0|0<br>0<br>0|0<br>0<br>0|0|0|0|0||
||R/W:||R|R|R|R||R|R|R<br>R<br>R|R<br>R<br>R/W|R/W|R/W|R/W|R/W||
|||||**Initial**|||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**|||||||
|31 to 5|―|||All 0|||R|||Reserved|||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|4|PFROIP|||0|||R/W|||PAUSE Frame Retransmit Interrupt Enable|||||||
|||||||||||0: Interrupt notification by the PFROI bit is disabled|||||||
|||||||||||1: Interrupt notification by the PFROI bit is enabled|||||||
|3 to 1|―|||All 0|||R|||Reserved|||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|0|ICDIP|||0|||R/W|||Illegal Carrier Detect Interrupt Enable|||||||
|||||||||||0: Interrupt notification by the ICD bit is disabled|||||||
|||||||||||1: Interrupt notification by the ICD bit is enabled|||||||

## 26.3.5 PHY Interface Register (PIR)

PIR is a 32-bit readable/writable register that provides a means of accessing the PHY-LSI internal registers via the MII.

||||Bit:|Bit:|31|30|29||28||27|26|25<br>24<br>23<br>22<br>21|20|19||18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|⎯||⎯||⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|⎯||⎯|⎯|⎯||
||||Initial value:||0|0|0||0||0|0|0<br>0<br>0<br>0<br>0|0|0||0|0|0||
||||R/W:||R|R|R||R||R|R|R<br>R<br>R<br>R<br>R|R|R||R|R|R||
||||Bit:||15|14|13||12||11|10|9<br>8<br>7<br>6<br>5|4|3||2|1|0||
||||||⎯|⎯|⎯||⎯||⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|MDI||MDO|MMD|MDC||
||||Initial value:||0|0|0||0||0|0|0<br>0<br>0<br>0<br>0|0|⎯||0|0|0||
||||R/W:||R|R|R||R||R|R|R<br>R<br>R<br>R<br>R|R|R||R/W|R/W|R/W||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**|||**Description**||||||||
|31|to|4|―|||All 0||||R|||Reserved||||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.||||||||
|3|||MDI|||Undefined||||R|||MII Management Data-In||||||||
||||||||||||||Indicates the level of the ET_MDIO pin.||||||||
|2|||MDO|||0||||R/W|||MII Management Data-Out||||||||
||||||||||||||Outputs the value set in this bit from the ET_MDIO|||||pin when the MMD bit is|||
||||||||||||||1.||||||||
|1|||MMD|||0||||R/W|||MII Management Mode||||||||
||||||||||||||Specifies the data read/write direction with respect|||||to the|MII.||
||||||||||||||0: Read direction is specified||||||||
||||||||||||||1: Write direction is specified||||||||
|0|||MDC|||0||||R/W|||MII Management Data Clock||||||||
||||||||||||||Outputs the value set in this bit from the MDC pin and supplies the MII with||||||||
||||||||||||||the management data clock. For the method||||of accessing the MII registers,||||
||||||||||||||see section 26.5.2, Accessing MII Registers.||||||||

## 26.3.6 MAC Address High Register (MAHR)

MAHR is a 32-bit readable/writable register that specifies the upper 32 bits of the 48-bit MAC address. The settings in this register are normally made in the initialization process after a reset. The MAC address setting must not be changed while the transmitting and receiving functions are enabled. Return the E-MAC and E-DMAC to their initial states by means of the SWRT and SWRR bits in EDMR before making settings again.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||MA[47:32]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||MA[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**||**Value**|||**R/W**||**Description**||||||||||
|31|to|0|MA[47:16]||All|0||R/W||MAC Address||Bits 47 to 16||||||||
|||||||||||These|bits are|used to set||the upper 32||bits|of the|MAC address.||
|||||||||||If the MAC address|||is 01-23-45-67-89-AB (hexadecimal), set H'01234567 in|||||||
|||||||||||this register.||||||||||

## 26.3.7 MAC Address Low Register (MALR)

MALR is a 32-bit readable/writable register that specifies the lower 16 bits of the 48-bit MAC address. The settings in this register are normally made in the initialization process after a reset. The MAC address setting must not be changed while the transmitting and receiving functions are enabled. Return the E-MAC and E-DMAC to their initial states by means of the SWRT and SWRR bits in EDMR before making settings again.

||||Bit:|Bit:|31|30||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯||⎯|⎯|⎯|⎯|⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:||15|14||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||||||||||||MA[15:0]||||||||||
||||Initial value:||0|0||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R/W|R/W||R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||||
|31|to|16|―|||All|0||R||Reserved|||||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||||
|15|to|0|MA[15:0]|||All|0||R/W||MAC Address Bits 15 to 0|||||||||||
||||||||||||These bits are used to set the lower 16 bits of the MAC address.|||||||||||
||||||||||||If the MAC address|||is 01-23-45-67-89-AB (hexadecimal), set H'000089AB||||||||
||||||||||||in this register.|||||||||||

## 26.3.8 Receive Frame Length Register (RFLR)

RFLR is a 32-bit readable/writable register that specifies the maximum frame length (in bytes) that can be received by this LSI. The settings in this register must not be changed while the receiving function is enabled.

||||Bit:|Bit:|31|30||29|28|27<br>26<br>25<br>24|23||22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯||⎯|⎯|⎯<br>⎯<br>⎯<br>⎯|⎯||⎯|⎯|⎯|⎯|⎯|RFL[17:16]|||
||||Initial value:||0|0||0|0|0<br>0<br>0<br>0|0||0|0|0|0|0|0|0||
||||R/W:||R|R||R|R|R<br>R<br>R<br>R|R||R|R|R|R|R|R/W|R/W||
||||Bit:||15|14||13|12|11<br>10<br>9<br>8|7||6|5|4|3|2|1|0||
|||||||||||RFL[15:0]|||||||||||
||||Initial value:||0|0||0|0|0<br>0<br>0<br>0|0||0|0|0|0|0|0|0||
||||R/W:||R/W|R/W||R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**|||||||||||
|31|to|18|―|||All 0||R||Reserved|||||||||||
|||||||||||These bits are always read as|||0. The write value should always be 0.||||||||
|17|to|0|RFL[17:0]|||All 0||R/W||Receive Frame Length|||||||||||
|||||||||||The frame data described here refers to all fields from|||||||the destination address up to||||
|||||||||||the CRC data. Frame contents from the destination address up to the data are|||||||||||
|||||||||||actually transferred to memory. CRC data|||||is not|included in the transfer. When data|||||
|||||||||||that exceeds the specified value is received, the part of data||||||||that exceeds the|||
|||||||||||specified value is discarded.|||||||||||
|||||||||||H'00000 to H'005EE: 1,518 bytes|||||||||||
|||||||||||H'005EF: 1,519 bytes|||||||||||
|||||||||||H'005F0: 1,520 bytes|||||||||||
|||||||||||:            :|||||||||||
|||||||||||H'007FF: 2,047 bytes|||||||||||
|||||||||||H'00800: 2,048 bytes|||||||||||
|||||||||||:            :|||||||||||
|||||||||||H'01000: 4,096 bytes|||||||||||
|||||||||||:            :|||||||||||
|||||||||||H'10000: 65,536 bytes|||||||||||
|||||||||||:            :|||||||||||
|||||||||||H'20000 to H'3FFFF: 131,072|||bytes||||||||

## 26.3.9 CRC Error Frame Receive Counter Register (CEFCR)

CEFCR is a 32-bit counter that indicates the number of times a frame with a CRC error was received. When the value in this register reaches H'FFFFFFFF, count-up is halted. This register is cleared to 0 when it is read with the TRCCM bit in ECMR set to 1. When the TRCCM bit in ECMR is 0, writing to this register will clear it regardless of the value written.

**==> picture [484 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>CEFC[31:16]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>CEFC[15:0]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 0 CEFC[31:0] All 0 R/W CRC Error Frame Count<br>These bits indicate the number of CRC error frames received.<br>R/W<br>**----- End of picture text -----**<br>

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.10 Frame Receive Error Counter Register (FRECR)

FRECR is a 32-bit counter that indicates the number of frames for which a receive error was generated by the RXER pin input from the PHY-LSI. FRECR is incremented each time the RXER pin becomes active. When the value in this register reaches H'FFFFFFFF, count-up is halted. This register is cleared to 0 when it is read with the TRCCM bit in ECMR set to 1. When the TRCCM bit in ECMR is 0, writing to this register will clear it regardless of the value written.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||FREC[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||FREC[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**||**Value**|||**R/W**||**Description**||||||||||
|31|to|0|FREC[31:0]||All|0||R/W||Frame|Receive Error Count|||||||||
|||||||||||These|bits indicate||the number||of errors during frame reception.|||||

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.11 Too-Short Frame Receive Counter Register (TSFRCR)

TSFRCR is a 32-bit counter that indicates the number of frames received with a length fewer than 64 bytes. When the value in this register reaches H'FFFFFFFF, count-up is halted. This register is cleared to 0 when it is read with the TRCCM bit in ECMR set to 1. When the TRCCM bit in ECMR is 0, writing to this register will clear it regardless of the value written.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||TSFC[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||TSFC[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**||**Value**|||**R/W**|**Description**|||||||||||
|31|to|0|TSFC[31:0]||All|0||R/W|Too-Short Frame Receive|||||Count||||||
||||||||||These||bits indicate||the number of||frames received|||with a|length of less than|
||||||||||64 bytes.|||||||||||

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.12 Too-Long Frame Receive Counter Register (TLFRCR)

TLFRCR is a 32-bit counter that indicates the number of frames received with a length exceeding the value specified by the receive frame length register (RFLR). When the value in this register reaches H'FFFFFFFF, count-up is halted. This register is not incremented when a frame containing residual bits is received. In this case, the reception of the frame is indicated in the residual-bit frame receive counter register (RFCR). This register is cleared to 0 when it is read with the TRCCM bit in ECMR set to 1. When the TRCCM bit in ECMR is 0, writing to this register will clear it regardless of the value written.

Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 TLFC[31:16] Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 TLFC[15:0] Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|0|TLFC[31:0]|All 0|R/W|Too-Long Frame Receive Count|
|||||||These bits indicate the number of frames received with a length exceeding|
|||||||the value in RFLR.|

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.13 Residual-Bit Frame Receive Counter Register (RFCR)

RFCR is a 32-bit counter that indicates the number of frames received containing residual bits (less than an 8-bit unit). When the value in this register reaches H'FFFFFFFF, count-up is halted. This register is cleared to 0 when it is read with the TRCCM bit in ECMR set to 1. When the TRCCM bit in ECMR is 0, writing to this register will clear it regardless of the value written.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||RFC[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||RFC[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**||**Value**|||**R/W**||**Description**||||||||||
|31|to|0|RFC[31:0]||All|0||R/W||Residual-Bit||Frame|Receive Count|||||||
|||||||||||These|bits indicate||the number||of frames received|||containing residual bits.||

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.14 Multicast Address Frame Receive Counter Register (MAFCR)

MAFCR is a 32-bit counter that indicates the number of frames received with a specified multicast address. When the value in this register reaches H'FFFFFFFF, count-up is halted. This register is cleared to 0 when it is read with the TRCCM bit in ECMR set to 1. When the TRCCM bit in ECMR is 0, writing to this register will clear it regardless of the value written.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||MAFC[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||MAFC[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**||**Value**|||**R/W**||**Description**||||||||||
|31|to|0|MAFC[31:0]||All|0||R/W||Multicast Address Frame||||Count||||||
|||||||||||These|bits indicate||the number of multicast||||frames|received.||

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.15 Automatic PAUSE Frame Register (APR)

APR is used to set the TIME parameter value of an automatic PAUSE frame. When an automatic PAUSE frame is transmitted, the value set in this register is used as the TIME parameter of the PAUSE frame.

||||Bit:|Bit:|31|30||29|28|27|26<br>25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯||⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R||R|R|R|R<br>R<br>R<br>R<br>R<br>R|R|R|R|R|R||
||||Bit:||15|14||13|12|11|10<br>9<br>8<br>7<br>6<br>5|4|3|2|1|0||
||||||||||||AP[15:0]|||||||
||||Initial value:||0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R/W|R/W||R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
|||||||**Initial**||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**||**Description**|||||||
|31|to|16|―|||All||0|R||Reserved|||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|15|to|0|AP[15:0]|||All||0|R/W||Automatic PAUSE|||||||
||||||||||||These bits set the TIME parameter value of an automatic|||||PAUSE frame.||
||||||||||||One bit is equivalent to 512 bit-time.|||||||
||||||||||||When flow control is enabled in transmission (PAUSE frame transmission)|||||||
||||||||||||(TXF bit in ECMR = 1), set a value other than H'0000 in these bits.|||||||
||||||||||||H'0000:|||||||
||||||||||||H'0001: 5121 bit-time|||||||
||||||||||||H'0002: 5122 bit-time|||||||
||||||||||||:            :|||||||
||||||||||||H'FFFF: 51265,535 bit-time|||||||
||||||||||||Note:The bit-time becomes as follows according to||||the transfer||speed.|
||||||||||||100 Mbps: 1 bit-time = 10 ns|||||||
||||||||||||10 Mbps: 1 bit-time = 100 ns|||||||

## 26.3.16 Manual PAUSE Frame Register (MPR)

MPR is used to set the TIME parameter value of a manual PAUSE frame. When a manual PAUSE frame is transmitted, the value set in this register is used as the TIME parameter of the PAUSE frame.

||||Bit:|Bit:|31|30||29|28|27|26<br>25<br>24<br>23|22|21|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯||⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯|⎯||⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0||0|0|0|0<br>0<br>0<br>0|0||0|0|0|0|0|0||
||||R/W:||R|R||R|R|R|R<br>R<br>R<br>R|R||R|R|R|R|R|R||
||||Bit:||15|14||13|12|11|10<br>9<br>8<br>7|6||5|4|3|2|1|0||
||||||||||||MP[15:0]||||||||||
||||Initial value:||0|0||0|0|0|0<br>0<br>0<br>0|0||0|0|0|0|0|0||
||||R/W:||R/W|R/W||R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**||**Description**||||||||||
|31|to|16|―|||All||0|R||Reserved||||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|15|to|0|MP[15:0]|||All||0|R/W||Manual PAUSE||||||||||
||||||||||||These bits set the TIME parameter value of a||||||manual PAUSE frame. One bit||||
||||||||||||is equivalent to 512|bit-time.|||||||||
||||||||||||H'0000:||||||||||
||||||||||||H'0001: 5121 bit-time||||||||||
||||||||||||H'0002: 5122 bit-time||||||||||
||||||||||||:            :||||||||||
||||||||||||H'FFFF: 51265,535 bit-time||||||||||
||||||||||||Note:The bit-time becomes as follows according to|||||||the transfer||speed.|
||||||||||||100 Mbps: 1 bit-time||=|10 ns|||||||
||||||||||||10 Mbps: 1 bit-time = 100 ns||||||||||

## 26.3.17 Automatic PAUSE Frame Retransmit Count Register (TPAUSER)

TPAUSER is used to set the upper limit for the number of times to retransmit an automatic PAUSE frame. The settings in this register must not be changed while the transmitting function is enabled.

||||Bit:|Bit:|31|30|29|28|27||26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|⎯|⎯|⎯||⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0|0|0|0||0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R||R|R|R|R|R|R|R|R|R|R|R||
||||Bit:||15|14|13|12|11||10|9|8|7|6|5|4|3|2|1|0||
||||||||||||||TPAUSE[15:0]||||||||||
||||Initial value:||0|0|0|0|0||0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
||||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**||||**Value**||**R/W**||**Description**||||||||||||
|31|to|16|―||||All 0||R||Reserved||||||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||||
|15|to|0|TPAUSE[15:0]||||All 0||R/W||Upper Limit for Automatic|||||PAUSE Frame Retransmission|||||||
||||||||||||H'0000: Retransmit||||count|is unlimited|||||||
||||||||||||H'0001: Retransmit||||count|is 1|||||||
|||||||||||||:|:||||||||||
||||||||||||H'FFFF: Retransmit count|||||is 65,535|||||||

## 26.3.18 PAUSE Frame Transmit Counter Register (PFTCR)

PFTCR is a 16-bit counter that indicates the number of times a PAUSE frame is transmitted. This register is cleared to 0 when it is read.

||||Bit:|Bit:|31|30|29|28|27||26<br>25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|⎯|⎯|⎯||⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0|0|0|0||0<br>0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R||R<br>R<br>R|R|R|R|R|R|R|R|R||
||||Bit:||15|14|13|12|11||10<br>9<br>8|7|6|5|4|3|2|1|0||
||||||||||||PFTXC[15:0]||||||||||
||||Initial value:||0|0|0|0|0||0<br>0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R||R<br>R<br>R|R|R|R|R|R|R|R|R||
||||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**||||**Value**||**R/W**||**Description**||||||||||
|31|to|16|―||||All 0||R||Reserved||||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|15|to|0|PFTXC[15:0]||||All 0||R||PAUSE Frame Transmit Count||||||||||
||||||||||||These bits indicate the total number of|||||automatic PAUSE|||frames and||
||||||||||||manual PAUSE frames transmitted.||||||||||

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.19 PAUSE Frame Receive Counter Register (PFRCR)

PFRCR is a 16-bit counter that indicates the number of times a PAUSE frame is received. This register is cleared to 0 when it is read.

||||Bit:|Bit:|31|30|29|28|27||26<br>25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|⎯|⎯|⎯||⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0|0|0|0||0<br>0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R||R<br>R<br>R|R|R|R|R|R|R|R|R||
||||Bit:||15|14|13|12|11||10<br>9<br>8|7|6|5|4|3|2|1|0||
||||||||||||PFRXC[15:0]||||||||||
||||Initial value:||0|0|0|0|0||0<br>0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R||R<br>R<br>R|R|R|R|R|R|R|R|R||
||||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**||||**Value**||**R/W**||**Description**||||||||||
|31|to|16|―||||All 0||R||Reserved||||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|15|to|0|PFRXC[15:0]||||All 0||R||PAUSE Frame Receive Count||||||||||
||||||||||||These bits indicate the number of PAUSE frames received when flow||||||||||
||||||||||||control is enabled in reception (RXF bit in ECMR =|||||||1).|||

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.20 TSU Counter Reset Register (TSU_CTRST)

TSU_CTRST clears the transmit, receive, and relay frame counters to 0.

||Bit:|Bit:|31|30||29|28||27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||⎯|⎯||⎯|⎯||⎯|⎯|⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||Initial value:||0|0||0|0||0|0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:||R|R||R|R||R|R|R<br>R|R|R|R|R|R|R|R|R||
||Bit:||15|14||13|12||11|10|9<br>8|7|6|5|4|3|2|1|0||
||||⎯|⎯||⎯|⎯||⎯|⎯|⎯<br>CTRST|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||Initial value:||0|0||0|0||0|0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:||R|R||R|R||R|R|R<br>R/W|R|R|R|R|R|R|R|R||
|||||**Initial**|||||||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**|||**Description**||||||||||
|31 to 9|―|||All||0||R|||Reserved||||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|8|CTRST|||0||||R/W|||TSU Counter|Reset|||||||||
||||||||||||When 1 is written to this bit, the values of registers|||||||TXNLCR0, TXALCR0,|||
||||||||||||RXNLCR0, and RXALCR0 are cleared|||||to 0. Writing||0 does not affect this bit.|||
||||||||||||This bit is always read as 0.||||||||||
|7 to 0|―|||All||0||R|||Reserved||||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||

## 26.3.21 CAM Entry Table Specification Enable Register (Common) (TSU_FWSLC)

When the CAM function is in use, you can use the TSU_POST1 to TSU_POST4 registers to specify which of among the CAM entry tables are for reference or reference to all tables. The TSU_FWSLC register enables or disables this action of the settings of the TSU_POST1 to TSU_POST4 registers.

||Bit:|Bit:|31|30||29|28||27|26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||―|―||―|―||―|―|―<br>―<br>―<br>―<br>―<br>―|―|―|―|―||
||Initial value:||0|0||0|0||0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:||R|R||R|R||R|R|R<br>R<br>R<br>R<br>R<br>R|R|R|R|R||
||Bit:||15|14||13|12||11|10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|||||||POST|POST||||||||||
||||―|―||ENU|ENL||―|―|―<br>―<br>―<br>―<br>―<br>―|―|―|―|―||
||Initial value:||0|0||0|0||0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:||R|R||R/W|R/W||R|R|R<br>R<br>R<br>R<br>R<br>R|R|R|R|R||
|||||**Initial**|||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**|||**Description**||||||
|31 to 14|―|||All||0||R|||Reserved||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||
|13|POSTENU|||0||||R/W|||This bit enables the settings for CAM entry tables 0|||to 15 in the POST bits of|||
||||||||||||the TSU_POST1 and TSU_POST2 registers.||||||
||||||||||||0: The settings of the POST bits are disabled (CAM entry||||tables 0 to 15 are||
||||||||||||referred to on reception of frames).||||||
||||||||||||1: The settings of the POST bits are enabled||(whether to||refer to each of||
||||||||||||CAM entry tables is determined by the settings of the corresponding||||||
||||||||||||POST bit).||||||
|12|POSTENL|||0||||R/W|||This bit enables the settings for CAM entry tables 16 to 31 in the POST bits||||||
||||||||||||of the TSU_POST3 and TSU_POST4 registers.||||||
||||||||||||0: The settings of the POST bits are disabled||(CAM|entry tables||16 to 31 are|
||||||||||||not referred to on reception of frames).||||||
||||||||||||1: The settings of the POST bits are enabled||(whether to||refer to each of||
||||||||||||CAM entry tables is determined by the settings of the corresponding||||||
||||||||||||POST bit).||||||
|11 to 0|―|||All||0||R|||Reserved||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||

## 26.3.22 VLANtag Set Register (TSU_VTAG0)

TSU_VTAG0 enables or disables the frame receive/discard evaluation function based on the VLAN number, and also sets the VLAN number.

||Bit:|Bit:|31|30|29|28|27||26||25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||VTAG|⎯|⎯|⎯|⎯||⎯||⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||||0|||||||||||||||||||
||Initial value:||0|0|0|0|0||0||0|0|0|0|0|0|0|0|0|0||
||R/W:||R/W|R|R|R|R||R||R|R|R|R|R|R|R|R|R|R||
||Bit:||15|14|13|12|11||10||9|8|7|6|5|4|3|2|1|0||
||||⎯|⎯|⎯|⎯||||||||VID0[11:0]||||||||
||Initial value:||0|0|0|0|0||0||0|0|0|0|0|0|0|0|0|0||
||R/W:||R|R|R|R|R/W||R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
||||||**Initial**|||||||||||||||||
|**Bit**|**Bit Name**||||**Value**||**R/W**|||**Description**||||||||||||
|31|VTAG0||||0||R/W|||Port 0||VLANtag Evaluation Function||||||||||
|||||||||||0: Disables receive/discard evaluation|||||||for frames based on the VLAN|||||
||||||||||||number|||||||||||
|||||||||||1: Enables receive/discard evaluation for frames based on the VLAN||||||||||||
||||||||||||number|||||||||||
|30 to 12|―||||All 0||R|||Reserved||||||||||||
|||||||||||These||bits are always read as 0. The write value should always be 0.||||||||||
|11 to 0|VID0[11:0]||||All 0||R/W|||V-LAN||ID Setting (VID)||||||||||
|||||||||||These||bits set the VLAN number received by receive frames.||||||||||

## 26.3.23 CAM Entry Table Busy Register (TSU_ADSBSY)

When CAM entry table registers (TSU_ADRH0 to TSU_ADRH31 and TSU_ADRL0 to TSU_ADRL31) are set by register writing, the ADSBSY bit in this register is set to 1 (when the process of reflecting the contents of the CAM entry table registers in the CAM controller is completed inside the TSU, the ADSBSY bit is automatically restored to 0). Access to TSU_ADRH0 to TSU_ADRH31 and TSU_ADRL0 to TSU_ADRL31 is prohibited, while the ADSBSY bit in this register is set to 1. This register is a read-only status register, which must not be written to.

**==> picture [484 x 239] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ADSBSY<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 1 ― All 0 R Reserved<br>These bits are always read as 0. The write value should always be 0.<br>0 ADSBSY 0 R CAM Entry Table Setting Busy<br>When TSU_ADRH0 to TSU_ADRH31 and TSU_ADRL0 to TSU_ADRL31<br>are set by register writing, this bit is set to 1. When the process of reflecting<br>the contents of the CAM entry table registers in the CAM controller is<br>completed inside the TSU, this bit is automatically restored to 0. Access to<br>TSU_ADRH0 to TSU_ADRH31 and TSU_ADRL0 to TSU_ADRL31 is<br>prohibited, while this bit is set to 1. Writing to this register is also prohibited.<br>R<br>**----- End of picture text -----**<br>

## 26.3.24 CAM Entry Table Enable Register (TSU_TEN)

TSU_TEN enables or disables the settings of TSU_ADRH0 to TSU_ADRH31 and TSU_ADRL0 to TSU_ADRL31.

Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 TEN0 TEN1 TEN2 TEN3 TEN4 TEN5 TEN6 TEN7 TEN8 TEN9 TEN10 TEN11 TEN12 TEN13 TEN14 TEN15 Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 TEN16 TEN17 TEN18 TEN19 TEN20 TEN21 TEN22 TEN23 TEN24 TEN25 TEN26 TEN27 TEN28 TEN29 TEN30 TEN31 Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31|TEN0|0|R/W|CAM Entry Table 0 (TSU_ADRH0 and TSU_ADRL0) Setting|
|||||0: Disabled|
|||||1: Enabled|
|30|TEN1|0|R/W|CAM Entry Table 1 (TSU_ADRH1 and TSU_ADRL1) Setting|
|||||0: Disabled|
|||||1: Enabled|
|29|TEN2|0|R/W|CAM Entry Table 2 (TSU_ADRH2 and TSU_ADRL2) Setting|
|||||0: Disabled|
|||||1: Enabled|
|28|TEN3|0|R/W|CAM Entry Table 3 (TSU_ADRH3 and TSU_ADRL3) Setting|
|||||0: Disabled|
|||||1: Enabled|
|27|TEN4|0|R/W|CAM Entry Table 4 (TSU_ADRH4 and TSU_ADRL4) Setting|
|||||0: Disabled|
|||||1: Enabled|
|26|TEN5|0|R/W|CAM Entry Table 5 (TSU_ADRH5 and TSU_ADRL5) Setting|
|||||0: Disabled|
|||||1: Enabled|
|25|TEN6|0|R/W|CAM Entry Table 6 (TSU_ADRH6 and TSU_ADRL6) Setting|
|||||0: Disabled|
|||||1: Enabled|
|24|TEN7|0|R/W|CAM Entry Table 7 (TSU_ADRH7 and TSU_ADRL7) Setting|
|||||0: Disabled|
|||||1: Enabled|
|23|TEN8|0|R/W|CAM Entry Table 8 (TSU_ADRH8 and TSU_ADRL8) Setting|
|||||0: Disabled|
|||||1: Enabled|
|22|TEN9|0|R/W|CAM Entry Table 9 (TSU_ADRH9 and TSU_ADRL9) Setting|
|||||0: Disabled|
|||||1: Enabled|
|21|TEN10|0|R/W|CAM Entry Table 10 (TSU_ADRH10 and TSU_ADRL10) Setting|
|||||0: Disabled|
|||||1: Enabled|
|20|TEN11|0|R/W|CAM Entry Table 11 (TSU_ADRH11 and TSU_ADRL11) Setting|
|||||0: Disabled|
|||||1: Enabled|
|19|TEN12|0|R/W|CAM Entry Table 12 (TSU_ADRH12 and TSU_ADRL12) Setting|
|||||0: Disabled|
|||||1: Enabled|
|18|TEN13|0|R/W|CAM Entry Table 13 (TSU_ADRH13 and TSU_ADRL13) Setting|
|||||0: Disabled|
|||||1: Enabled|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|17|TEN14|0|R/W|CAM Entry Table 14 (TSU_ADRH14 and TSU_ADRL14) Setting|
|||||0: Disabled|
|||||1: Enabled|
|16|TEN15|0|R/W|CAM Entry Table 15 (TSU_ADRH15 and TSU_ADRL15) Setting|
|||||0: Disabled|
|||||1: Enabled|
|15|TEN16|0|R/W|CAM Entry Table 16 (TSU_ADRH16 and TSU_ADRL16) Setting|
|||||0: Disabled|
|||||1: Enabled|
|14|TEN17|0|R/W|CAM Entry Table 17 (TSU_ADRH17 and TSU_ADRL17) Setting|
|||||0: Disabled|
|||||1: Enabled|
|13|TEN18|0|R/W|CAM Entry Table 18 (TSU_ADRH18 and TSU_ADRL18) Setting|
|||||0: Disabled|
|||||1: Enabled|
|12|TEN19|0|R/W|CAM Entry Table 19 (TSU_ADRH19 and TSU_ADRL19) Setting|
|||||0: Disabled|
|||||1: Enabled|
|11|TEN20|0|R/W|CAM Entry Table 20 (TSU_ADRH20 and TSU_ADRL20) Setting|
|||||0: Disabled|
|||||1: Enabled|
|10|TEN21|0|R/W|CAM Entry Table 21 (TSU_ADRH21 and TSU_ADRL21) Setting|
|||||0: Disabled|
|||||1: Enabled|
|9|TEN22|0|R/W|CAM Entry Table 22 (TSU_ADRH22 and TSU_ADRL22) Setting|
|||||0: Disabled|
|||||1: Enabled|
|8|TEN23|0|R/W|CAM Entry Table 23 (TSU_ADRH23 and TSU_ADRL23) Setting|
|||||0: Disabled|
|||||1: Enabled|
|7|TEN24|0|R/W|CAM Entry Table 24 (TSU_ADRH24 and TSU_ADRL24) Setting|
|||||0: Disabled|
|||||1: Enabled|
|6|TEN25|0|R/W|CAM Entry Table 25 (TSU_ADRH25 and TSU_ADRL25) Setting|
|||||0: Disabled|
|||||1: Enabled|
|5|TEN26|0|R/W|CAM Entry Table 26 (TSU_ADRH26 and TSU_ADRL26) Setting|
|||||0: Disabled|
|||||1: Enabled|
|4|TEN27|0|R/W|CAM Entry Table 27 (TSU_ADRH27 and TSU_ADRL27) Setting|
|||||0: Disabled|
|||||1: Enabled|
|3|TEN28|0|R/W|CAM Entry Table 28 (TSU_ADRH28 and TSU_ADRL28) Setting|
|||||0: Disabled|
|||||1: Enabled|
|2|TEN29|0|R/W|CAM Entry Table 29 (TSU_ADRH29 and TSU_ADRL29) Setting|
|||||0: Disabled|
|||||1: Enabled|
|1|TEN30|0|R/W|CAM Entry Table 30 (TSU_ADRH30 and TSU_ADRL30) Setting|
|||||0: Disabled|
|||||1: Enabled|
|0|TEN31|0|R/W|CAM Entry Table 31 (TSU_ADRH31 and TSU_ADRL31) Setting|
|||||0: Disabled|
|||||1: Enabled|

## 26.3.25 CAM Entry Table POST 1 Register (TSU_POST1)

When the CAM function is in use, you can use the TSU_POST1 to TSU_POST4 registers to specify which of the CAM entry tables are for reference. The TSU_POST1 register specifies the conditions for reference to TSU_ADRH0 to TSU_ADRH7 and TSU_ADRL0 to TSU_ADRL7. The setting of this register is effective when the POSTENU bit of the TSU_FWSLC register is set to 1.

||Bit:|Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|
||||POST0|―|―|―||POST1|―|POST2<br>―<br>―<br>―<br>POST3<br>―<br>―<br>―<br>―<br>―||
||Initial value:||0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||R/W:||R/W|R|R|R||R/W|R|R<br>R<br>R/W<br>R<br>R<br>R<br>R/W<br>R<br>R<br>R||
||Bit:||15|14|13|12||11|10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
||||POST4|―|―|―||POST5|―|―<br>―<br>POST6<br>―<br>―<br>―<br>POST7<br>―<br>―<br>―||
||Initial value:||0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||R/W:||R/W|R|R|R||R/W|R|R<br>R<br>R/W<br>R<br>R<br>R<br>R/W<br>R<br>R<br>R||
|||||**Initial**||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**||
|31|POST0|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 0.||
|||||||||||Setting this bit to 1 selects the condition below.||
|||||||||||POST0: CAM entry table 0 is referred to on reception of frames.||
|30 to 28|―|||All 0|||R|||Reserved||
|||||||||||These bits are always read as 0. The write value should always|be 0.|
|27|POST1|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 1.||
|||||||||||Setting this bit to 1 selects the condition below.||
|||||||||||POST1: CAM entry table 1 is referred to on reception of frames.||
|26 to 24|―|||All 0|||R|||Reserved||
|||||||||||These bits are always read as 0. The write value should always|be 0.|
|23|POST2|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 2.||
|||||||||||Setting this bit to 1 selects the condition below.||
|||||||||||POST2: CAM entry table 2 is referred to on reception of frames.||
|22 to 20|―|||All 0|||R|||Reserved||
|||||||||||These bits are always read as 0. The write value should always|be 0.|
|19|POST3|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 3.||
|||||||||||Setting this bit to 1 selects the condition below.||
|||||||||||POST3: CAM entry table 3 is referred to on reception of frames.||
|18 to 16|―|||All 0|||R|||Reserved||
|||||||||||These bits are always read as 0. The write value should always|be 0.|
|15|POST4|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 4.||
|||||||||||Setting this bit to 1 selects the condition below.||
|||||||||||POST4: CAM entry table 4 is referred to on reception of frames.||
|14 to 12|―|||All 0|||R|||Reserved||
|||||||||||These bits are always read as 0. The write value should always|be 0.|
|11|POST5|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 5.||
|||||||||||Setting this bit to 1 selects the condition below.||
|||||||||||POST5: CAM entry table 5 is referred to on reception of frames.||
|10 to 8|―|||All 0|||R|||Reserved||
|||||||||||These bits are always read as 0. The write value should always|be 0.|
|7|POST6|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 6.||
|||||||||||Setting this bit to 1 selects the condition below.||
|||||||||||POST6: CAM entry table 6 is referred to on reception of frames.||
|6 to 4|―|||All 0|||R|||Reserved||
|||||||||||These bits are always read as 0. The write value should always|be 0.|
|3|POST7|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 7.||
|||||||||||Setting this bit to 1 selects the condition below.||
|||||||||||POST7: CAM entry table 7 is referred to on reception of frames.||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|2 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 26.3.26 CAM Entry Table POST 2 Register (TSU_POST2)

When the CAM function is in use, you can use the TSU_POST1 to TSU_POST4 registers to specify which of the CAM entry tables are for reference. The TSU_POST2 register specifies the conditions for reference to TSU_ADRH8 to TSU_ADRH15 and TSU_ADRL8 to TSU_ADRL15. The setting of this register is effective when the POSTENU bit of the TSU_FWSLC register is set to 1.

||||Bit:|Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22<br>21<br>20|19|18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||POST8|―|―|―||POST9|―|POST10<br>―<br>―<br>―<br>―<br>―|POST11|―<br>―<br>―||
||||Initial value:||0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0|0|0<br>0<br>0||
||||R/W:||R/W|R|R|R||R/W|R|R<br>R<br>R/W<br>R<br>R<br>R|R/W|R<br>R<br>R||
||||Bit:||15|14|13|12||11|10|9<br>8<br>7<br>6<br>5<br>4|3|2<br>1<br>0||
||||||POST12|―|―|―||POST13|―|―<br>―<br>POST14<br>―<br>―<br>―|POST15|―<br>―<br>―||
||||Initial value:||0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0|0|0<br>0<br>0||
||||R/W:||R/W|R|R|R||R/W|R|R<br>R<br>R/W<br>R<br>R<br>R|R/W|R<br>R<br>R||
|||||||**Initial**||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**|||**Description**||||
|31|||POST8|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 8.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST8: CAM entry table 8 is referred to on reception of frames.||||
|30|to|28|―|||All 0|||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always|||be 0.|
|27|||POST9|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 9.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST9: CAM entry table 9 is referred to on reception of frames.||||
|26|to|24|―|||All 0|||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always|||be 0.|
|23|||POST10|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 10.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST10: CAM entry table 10 is referred to on reception of frames.||||
|22|to|20|―|||All 0|||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always|||be 0.|
|19|||POST11|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 11.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST11: CAM entry table 11 is referred to on reception of frames.||||
|18|to|16|―|||All 0|||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always|||be 0.|
|15|||POST12|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 12.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST12: CAM entry table 12 is referred to on reception of frames.||||
|14|to|12|―|||All 0|||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always|||be 0.|
|11|||POST13|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 13.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST13: CAM entry table 13 is referred to on reception of frames.||||
|10|to|8|―|||All 0|||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always|||be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|POST14|0|R/W|Specifies whether reference is or is not made to CAM entry table 14.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST14: CAM entry table 14 is referred to on reception of frames.|
|6 to 4|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|3|POST15|0|R/W|Specifies whether reference is or is not made to CAM entry table 15.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST15: CAM entry table 15 is referred to on reception of frames.|
|2 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 26.3.27 CAM Entry Table POST 3 Register (TSU_POST3)

When the CAM function is in use, you can use the TSU_POST1 to TSU_POST4 registers to specify which of the CAM entry tables are for reference. The TSU_POST3 register specifies the conditions for reference to TSU_ADRH16 to TSU_ADRH23 and TSU_ADRL16 to TSU_ADRL23. The setting of this register is effective when the POSTENL bit of the TSU_FWSLC register is set to 1.

||||Bit:|Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22<br>21<br>20|19|18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||POST16|―|―|―||POST17|―|POST18<br>―<br>―<br>―<br>―<br>―|POST19|―<br>―<br>―||
||||Initial value:||0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0|0|0<br>0<br>0||
||||R/W:||R/W|R|R|R||R/W|R|R<br>R<br>R/W<br>R<br>R<br>R|R/W|R<br>R<br>R||
||||Bit:||15|14|13|12||11|10|9<br>8<br>7<br>6<br>5<br>4|3|2<br>1<br>0||
||||||POST20|―|―|―||POST21|―|―<br>―<br>POST22<br>―<br>―<br>―|POST23|―<br>―<br>―||
||||Initial value:||0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0|0|0<br>0<br>0||
||||R/W:||R/W|R|R|R||R/W|R|R<br>R<br>R/W<br>R<br>R<br>R|R/W|R<br>R<br>R||
|||||||**Initial**||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**|||**Description**||||
|31|||POST16|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 16.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST16: CAM entry table 16 is referred to on reception of frames.||||
|30|to|28|―|||All|0||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always be 0.||||
|27|||POST17|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 17.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST17: CAM entry table 17 is referred to on reception of frames.||||
|26|to|24|―|||All|0||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always be 0.||||
|23|||POST18|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 18.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST18: CAM entry table 18 is referred to on reception of frames.||||
|22|to|20|―|||All|0||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always be 0.||||
|19|||POST19|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 19.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST19: CAM entry table 19 is referred to on reception of frames.||||
|18|to|16|―|||All|0||R|||Reserved||||
|||||||||||||These bits are always read as 0. The write value should always be 0.||||
|15|||POST20|||0|||R/W|||Specifies whether reference is or is not made to CAM entry table 20.||||
|||||||||||||Setting this bit to 1 selects the condition below.||||
|||||||||||||POST20: CAM entry table 20 is referred to on reception of frames.||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|14 to 12|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11|POST21|0|R/W|Specifies whether reference is or is not made to CAM entry table 21.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST21: CAM entry table 21 is referred to on reception of frames.|
|10 to 8|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|7|POST22|0|R/W|Specifies whether reference is or is not made to CAM entry table 22.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST22: CAM entry table 22 is referred to on reception of frames.|
|6 to 4|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|3|POST23|0|R/W|Specifies whether reference is or is not made to CAM entry table 23.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST23: CAM entry table 23 is referred to on reception of frames.|
|2 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 26.3.28 CAM Entry Table POST 4 Register (TSU_POST4)

When the CAM function is in use, you can use the TSU_POST1 to TSU_POST4 registers to specify which of the CAM entry tables are for reference. The TSU_POST4 register specifies the conditions for reference to TSU_ADRH24 to TSU_ADRH31 and TSU_ADRL24 to TSU_ADRL31. The setting of this register is effective when the POSTENL bit of the TSU_FWSLC register is set to 1.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||POST24|―|―|―|POST25|―|―|―|POST26|―|―|―|POST27|―|―|―|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||POST28|―|―|―|POST29|―|―|―|POST30|―|―|―|POST31|―|―|―|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|||POST24|0|R/W|Specifies whether reference is or is not made to CAM entry table 24.|
|||||||Setting this bit to 1 selects the condition below.|
|||||||POST24: CAM entry table 24 is referred to on reception of frames.|
|30|to|28|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|27|||POST25|0|R/W|Specifies whether reference is or is not made to CAM entry table 25.|
|||||||Setting this bit to 1 selects the condition below.|
|||||||POST25: CAM entry table 25 is referred to on reception of frames.|
|26|to|24|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|23|||POST26|0|R/W|Specifies whether reference is or is not made to CAM entry table 26.|
|||||||Setting this bit to 1 selects the condition below.|
|||||||POST26: CAM entry table 26 is referred to on reception of frames.|
|22|to|20|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|19|POST27|0|R/W|Specifies whether reference is or is not made to CAM entry table 27.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST27: CAM entry table 27 is referred to on reception of frames.|
|18 to 16|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|15|POST28|0|R/W|Specifies whether reference is or is not made to CAM entry table 28.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST28: CAM entry table 28 is referred to on reception of frames.|
|14 to 12|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11|POST29|0|R/W|Specifies whether reference is or is not made to CAM entry table 29.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST29: CAM entry table 29 is referred to on reception of frames.|
|10 to 8|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|7|POST30|0|R/W|Specifies whether reference is or is not made to CAM entry table 30.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST30: CAM entry table 30 is referred to on reception of frames.|
|6 to 4|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|3|POST31|0|R/W|Specifies whether reference is or is not made to CAM entry table 31.|
|||||Setting this bit to 1 selects the condition below.|
|||||POST31: CAM entry table 31 is referred to on reception of frames.|
|2 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 26.3.29 CAM Entry Table 0H to 31H Registers (TSU_ADRH0 to TSU_ADRH31)

TSU_ADRH0 to TSU_ADRH31 are entry tables referred to by the CAM in reception and relay. Each of these registers sets the upper 32 bits of the 48-bit MAC address. Maximum 32 entries of MAC addresses can be registered.

Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 ADRHn[31:16] (n = 0 to 31) Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 ADRHn[15:0] (n = 0 to 31) Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|0|ADRHn[31:0]|All 0|R/W|MAC Address Bits|
||||(n: 0 to 31)|||These bits set the upper 32 bits of the MAC address.|
|||||||When the MAC address is 01-23-45-67-89-AB (displayed in hexadecimal),|
|||||||set H'01234567 in this register.|

Note: • Set the CAM entry tables following the procedure below.

1. Check that the ADSBSY bit in TSU_ADSBSY is cleared to 0.

2. Set the upper 32 bits of the MAC addresses by TSU_ADRH0 to TSU_ADRH31.

3. Set the lower 16 bits of the MAC addresses by TSU_ADRL0 to TSU_ADRL31.

## 26.3.30 CAM Entry Table 0L to 31L Registers (TSU_ADRL0 to TSU_ADRL31)

TSU_ADRL0 to TSU_ADRL31 are entry tables referred to by the CAM in reception and relay. Each of these registers sets the lower 16 bits of the 48-bit MAC address. Maximum 32 entries of MAC addresses can be registered.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||ADRLn[15:0]||(n = 0 to 31)||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|16|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|15|to|0|ADRLn[15:0]|All 0|R/W|MAC Address Bits|
||||(n: 0 to 31)|||These bits set the lower 16 bits of the MAC address.|
|||||||When the MAC address is 01-23-45-67-89-AB (displayed in hexadecimal),|
|||||||set H'000089AB in this register.|

Note: • Set the CAM entry tables following the procedure below.

1. Check that the ADSBSY bit in TSU_ADSBSY is cleared to 0.

2. Set the upper 32 bits of the MAC addresses by TSU_ADRH0 to TSU_ADRH31.

3. Set the lower 16 bits of the MAC addresses by TSU_ADRL0 to TSU_ADRL31.

## 26.3.31 Transmit Frame Counter Register (Normal Transmission Only) (TXNLCR0)

TXNLCR0 is a 32-bit counter indicating the number of frames successfully transmitted in the

E-MAC. When the value in this register reaches H'FFFFFFFF, count-up is halted. The counter is cleared to 0 by reading from this register. This register cannot be written to.

**==> picture [484 x 166] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>NTC0[31:16]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>NTC0[15:0]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 0 NTC0[31:0] All 0 R Transmit Frame Counter Bits<br>These bits indicate the number of frames successfully transmitted.<br>**----- End of picture text -----**<br>

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.32 Transmit Frame Counter Register (Normal and Erroneous Transmission) (TXALCR0)

TXALCR0 is a 32-bit counter indicating the number of frames transmitted in the E-MAC, including the number of frames erroneously transmitted. When the value in this register reaches H'FFFFFFFF, count-up is halted. The counter is cleared to 0 by reading from this register. This register cannot be written to.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||TC0[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||TC0[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|TC0[31:0]|||All 0||R||Transmit Frame||Counter||Bits||||||
|||||||||||These bits indicate the number of frames||||||successfully transmitted and||||
|||||||||||erroneously transmitted.||||||||||

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.33 Receive Frame Counter Register (Normal Reception Only) (RXNLCR0)

RXNLCR0 is a 32-bit counter indicating the number of frames successfully received in the

E-MAC. When the value in this register reaches H'FFFFFFFF, count-up is halted. The counter is cleared to 0 by reading from this register. This register cannot be written to.

**==> picture [484 x 166] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>NRC0[31:16]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>NRC0[15:0]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 0 NRC0[31:0] All 0 R Receive Frame Counter Bits<br>These bits indicate the number of frames successfully received.<br>**----- End of picture text -----**<br>

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.34 Receive Frame Counter Register (Normal and Erroneous Reception) (RXALCR0)

RXALCR0 is a 32-bit counter indicating the number of frames received in the E-MAC, including the number of frames erroneously received. When the value in this register reaches H'FFFFFFFF, count-up is halted. The counter is cleared to 0 by reading from this register. This register cannot be written to.

**==> picture [484 x 176] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>RC0[31:16]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>RC0[15:0]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 0 RC0[31:0] All 0 R Receive Frame Counter Bits<br>These bits indicate the number of frames successfully received and<br>erroneously received.<br>R<br>**----- End of picture text -----**<br>

Note: • When count-up and count-clearing of this register value occur simultaneously, count-clearing is performed.

## 26.3.35 E-DMAC Start Register (EDSR)

EDSR specifies activation of the transmitting unit and receiving unit of the E-DMAC. This register can only be written to, and the read values are invalid.

||||Bit:|Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|R|R||
||||Bit:||15|14|||13|12|11|10|9<br>8<br>7<br>6<br>5|4|3|2|1|0||
||||||⎯|⎯|||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|⎯|⎯|ENT|ENR||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|W|W||
||||||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**|||||||
|31|to|2|―||||All||0||R||Reserved|||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|1|||ENT||||0||||W||E-DMAC Transmitting Unit Start|||||||
||||||||||||||0: Stops the E-DMAC transmitting unit|||||||
||||||||||||||1: Starts the E-DMAC transmitting unit|||||||
|0|||ENR||||0||||W||E-DMAC Receiving Unit Start|||||||
||||||||||||||0: Stops the E-DMAC receiving unit|||||||
||||||||||||||1: Starts the E-DMAC receiving unit|||||||

## 26.3.36 E-DMAC Mode Register (EDMR)

EDMR is a 32-bit readable/writable register that specifies E-DMAC resetting and the transmit/receive descriptor length. This register is to be set before the transmitting or receiving function is enabled (before the TR bit in EDTRR or the RR bit in EDRRR is set to 1). However, the SWRR and SWRT bits can be written to even after the transmitting or receiving function is enabled. If a software reset is executed with this register during data transmission, abnormal data may be transmitted on the line. Execute a software reset with this register before specifying the transmit/receive descriptor length or modifying the settings of TDLAR, RDLAR, and so forth, the setting of ECMR (E-MAC mode register), and the settings of registers related to the E-DMAC and E-MAC operation.

To execute a software reset with this register, 1 must be written to both the SWRT and SWRR bits simultaneously. Writing 1 to the SWRT and SWRR bits initializes the E-MAC registers and E-DMAC registers, except for TDLAR, RDLAR, and RMFCR of the E-DMAC. The TSU registers (registers whose names are prefixed with TSU_) are not initialized. The SWRT and SWRR bits in EDMR0 initializes the registers related to the E-DMAC and E-MAC. Note that during the period a software reset is issued (for 64 cycles of the internal bus clock Bck), accesses to all Ethernet-related registers are prohibited.

||Bit:||31|30|||29|28||27|22<br>23<br>24<br>25<br>26|21|20|19||18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||−|−|||−|−||−|−<br>−<br>−<br>−<br>−|−|−|−||−|−|−||
||Initial value:||0|0|||0|0||0|0<br>0<br>0<br>0<br>0|0|0|0||0|0|0||
||R/W:||R|R|||R|R||R|R<br>R<br>R<br>R<br>R|R|R|R||R|R|R||
||Bit:||15|14|||13|12||11|6<br>7<br>8<br>9<br>10|5|4|3||2|1|0||
||||−|−|||−|−||−|−<br>−<br>−<br>−<br>DE|DL[1:0]||−||−|SWRT|SWRR||
||Initial value:||0|0|||0|0||0|0<br>0<br>0<br>0<br>0|0|0|0||0|0|0||
||R/W:||R|R|||R|R||R|R/W<br>R<br>R<br>R<br>R|R/W|R/W|R||R|R/W|R/W||
||||||**Initial**|||||||||||||||
|**Bit**|**Bit Name**||||**Value**||||**R/W**||**Description**|||||||||
|31 to 7|―||||All||0||R||Reserved|||||||||
||||||||||||These bits are always read|as 0. The write value should always be 0.||||||||
|6|DE||||0||||R/W||Transmit/Receive Frame Endian|||||||||
||||||||||||Sets the endian mode for DMA transfer|||of frame data between the transmit/||||||
||||||||||||receive FIFO and transmit/receive buffer.|||||||||
||||||||||||0: Big endian (longword access)|||||||||
||||||||||||1: Little endian (longword access)|||||||||
|5, 4|DL[1:0]||||00||||R/W||Transmit/Receive Descriptor Length|||||||||
||||||||||||These bits specify the descriptor length. (See|||||section 26.4.1, Descriptors||||
||||||||||||and Descriptor List.)|||||||||
||||||||||||00: 16 bytes|||||||||
||||||||||||01: 32 bytes|||||||||
||||||||||||10: 64 bytes|||||||||
||||||||||||11: Setting prohibited|||||||||
|3, 2|―||||All||0||R||Reserved|||||||||
||||||||||||These bits are always read|as 0. The write value should always be 0.||||||||
|1|SWRT||||0||||R/W||Software Reset of Transmit FIFO||Controller|||||||
||||||||||||[Writing]|||||||||
||||||||||||0: Disabled|||||||||
||||||||||||1: Software reset started|||||||||
||||||||||||[Reading]|||||||||
||||||||||||0: Software reset not executed (or completed)|||||||||
||||||||||||1: Software reset being executed|||||||||
|0|SWRR||||0||||R/W||Software Reset of Receive|FIFO Controller||||||||
||||||||||||[Writing]|||||||||
||||||||||||0: Disabled|||||||||
||||||||||||1: Software reset started|||||||||
||||||||||||[Reading]|||||||||
||||||||||||0: Software reset not executed (or completed)|||||||||
||||||||||||1: Software reset being executed|||||||||

## 26.3.37 E-DMAC Transmit Request Register (EDTRR)

EDTRR is a 32-bit readable/writable register that issues transmit directives to the E-DMAC. After writing 11 to bits TR[1:0] in this register, the E-DMAC reads the transmit descriptor at the address specified by TDLAR. If the TACT bit of this transmit descriptor is set to 1 (valid), transmit DMA transfer by the E-DMAC starts. When DMA transfer based on the first transmit descriptor is completed, the E-DMAC reads the next transmit descriptor. If the TACT bit of that transmit descriptor is set to 1 (valid), the E-DMAC continues transmit DMA operation. If the TACT bit of a transmit descriptor is cleared to 0 (invalid), the E-DMAC clears bits TR[1:0] and stops transmit DMA operation.

||Bit:|Bit:|31|30|29|28||27||26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||⎯|⎯|⎯|⎯||⎯||⎯|⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||Initial value:||0|0|0|0||0||0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:||R|R|R|R||R||R|R<br>R<br>R|R|R|R|R|R|R|R||
||Bit:||15|14|13|12||11||10|9<br>8<br>7|6|5|4|3|2|1|0||
||||⎯|⎯|⎯|⎯||⎯||⎯|⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|TR[1:0]|||
||Initial value:||0|0|0|0||0||0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:||R|R|R|R||R||R|R<br>R<br>R|R|R|R|R|R|R/W|R/W||
|||||**Initial**||||||||||||||||
|**Bit**|**Bit Name**|||**Value**||**R/W**|||**Description**|||||||||||
|31 to 2|―|||All 0||R|||Reserved|||||||||||
||||||||||These||bits are always read as 0. The|||write value should|||always be 0.|||
|1, 0|TR[1:0]|||00||R/W|||Transmit Request|||||||||||
||||||||||00, 01, 10: Transmission-halted state|||||||||||
||||||||||||If 00, 01, or 10 is written to these bits,|||||the E-DMAC stops DMA||||
||||||||||||transfer of the currently processed transmit descriptor, reads the next|||||||||
||||||||||||transmit descriptor,||and then clears these bits. (Write-back is|||||||
||||||||||||completed for the valid transmit||||descriptors that have been detected|||||
||||||||||||up till then.)|||||||||

The E-DMAC clears these bits when transmit descriptor empty occurs, or transmission of a transmit descriptor has completed. (Write-back is completed for the valid transmit descriptors that have been detected up till then.)

11: Transmit DMA operation by E-DMAC

After writing 11 to these bits, the E-DMAC starts reading a transmit descriptor.

## 26.3.38 E-DMAC Receive Request Register (EDRRR)

EDRRR is a 32-bit readable/writable register that issues receive directives to the E-DMAC. After writing 1 to the RR bit in this register, the E-DMAC reads the receive descriptor at the address specified by RDLAR. If the RACT bit of this receive descriptor is set to 1 (valid), and the receive FIFO holds a receive frame, the E-DMAC starts receive DMA transfer. When DMA transfer based on the first receive descriptor is completed, the E-DMAC reads the next receive descriptor. If the RACT bit of that receive descriptor is set to 1 (valid), the E-DMAC continues receive DMA operation. However, if the receive FIFO holds no receive data, the E-DMAC places receive DMA operation in the standby state. If the RACT bit of the receive descriptor is cleared to 0 (invalid), the E-DMAC clears the RR bit and stops receive DMAC operation.

||||Bit:|Bit:|31|30|||29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||||Bit:||15|14|||13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
||||||⎯|⎯|||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|RR||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R/W||
||||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**|||||||||
|31|to|1|―||||All||0||R||Reserved|||||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|0|||RR||||0||||R/W||Receive Request|||||||||
||||||||||||||0: Receiving function is disabled*1|||||||||
||||||||||||||If 0 is written to this bit,||the E-DMAC stops receive operation||||||after DMA|
||||||||||||||transfer of one frame has completed and then clears this bit.|||||||||
||||||||||||||The E-DMAC clears this bit when receive descriptor empty occurs.|||||||||
||||||||||||||1: Receive descriptor is read, and the E-DMAC is ready to receive.|||||||||

Note 1. If the receiving function is disabled during frame reception, write-back is not performed successfully to the receive descriptor. Following pointers to read a receive descriptor become abnormal and the E-DMAC cannot operate successfully. In this case, to make E-DMAC reception enabled again, execute a software reset by the SWRT and SWRR bits in EDMR0. To disable the E- DMAC receiving function without executing a software reset, specify the RE bit in ECMR0. Next, after the E-DMAC has completed the reception and write-back to the receive descriptor has been confirmed, disable the receiving function using this register.

## 26.3.39 Transmit Descriptor List Start Address Register (TDLAR)

TDLAR is a 32-bit readable/writable register that specifies the start address of the transmit descriptor list. Descriptors have a boundary configuration in accordance with the descriptor length indicated by the DL bits in EDMR. This register must not be modified during transmission. Modifications to this register should only be made in the transmission-halted state specified by bits TR[1:0] (= 00) in the E-DMAC transmit request register (EDTRR).

||||Bit:|31|30|29|28|27|26|25|24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||TDLA[31:15]||||||||
||||Initial value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8<br>7|6|5|4|3|2|1|0|
||||||||||||TDLA[15:0]||||||||
||||Initial value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**|||||||||
|31|to|0|TDLA[31:0]|||All 0||R/W||Transmit Descriptor Start|||Address||||||
|||||||||||The lower bits are set according to the specified descriptor length.|||||||||
|||||||||||16-byte|boundary: TDLA[3:0] = 0000||||||||
|||||||||||32-byte|boundary: TDLA[4:0] = 00000||||||||
|||||||||||64-byte|boundary: TDLA[5:0] = 000000||||||||

## 26.3.40 Receive Descriptor List Start Address Register (RDLAR)

RDLAR is a 32-bit readable/writable register that specifies the start address of the receive descriptor list. Descriptors have a boundary configuration in accordance with the descriptor length indicated by the DL bits in EDMR. This register must not be modified during reception. Modifications to this register should only be made while reception is disabled by the RR bit (= 0) in the E-DMAC receive request register (EDRRR).

||||Bit:|31|30|29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||RDLA[31:15]||||||||
||||Initial value:|0|0|0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0|
|||||||||||RDLA[15:0]||||||||
||||Initial value:|0|0|0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||
|31|to|0|RDLA[31:0]|||All 0||R/W||Receive Descriptor|Start|Address||||||
|||||||||||The lower bits are set according to the specified descriptor length.||||||||
|||||||||||16-byte boundary: RDLA[3:0] = 0000||||||||
|||||||||||32-byte boundary: RDLA[4:0] = 00000||||||||
|||||||||||64-byte boundary: RDLA[5:0] = 000000||||||||

## 26.3.41 E-MAC/E-DMAC Status Register (EESR)

EESR is a 32-bit readable/writable register that shows communications status information on the E-DMAC in combination with the E-MAC. The information in this register is reported in the form of interrupt sources. Individual bits are cleared by writing 1 (however, bit 22 (ECI) is a read-only bit that is not cleared by writing 1) and are not affected by writing 0. Each interrupt source can also be masked by means of the corresponding bit in the E-MAC/E-DMAC status interrupt permission register (EESIPR).

The interrupt generated by this status register is ETHERI. For interrupt priorities, see section 7.4, Interrupt Sources .

|||Bit:|Bit:|31|30||29|28|27|26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|
|||||TWB[1:0]|||TC[1]|TUC|ROC|⎯<br>ECI<br>TC[0]<br>TDE<br>TFUF<br>FR<br>RDE<br>RFOF<br>TABT<br>RABT RFCOF||
|||Initial value:||0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
|||R/W:<br>R/W|||R/W||R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||Bit:||15|14||13|12|11|10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
|||||⎯|⎯||⎯|⎯|⎯|RMAF<br>⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>RRF<br>RTLF<br>RTSF<br>PRE<br>CERF||
|||Initial value:||0|0||0|0|0|Undefined Undefined<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
|||R/W:||R|R||R|R|R|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R<br>R<br>R||
|||||||**Initial**||||||
|**Bit**||**Bit Name**||||**Value**|||**R/W**|**Description**||
|31,|30|TWB[1:0]||||00|||R/W|Write-Back Complete||
|||||||||||Indicates that write-back from the E-DMAC to the corresponding descriptor||
|||||||||||after frame transmission has completed. This operation is enabled only||
|||||||||||when the TWBI bit in the transmit descriptor that includes the end of the||
|||||||||||transmit frame is set to 1.||
|||||||||||00: Write-back has not completed, or no transmission directive||
|||||||||||11: Write-back has completed||
|||||||||||Others: Setting disabled||
|29||TC[1]||||0|||R/W|Frame Transmission Complete||
|||||||||||Indicates, in combination with the TC[0] bit, that all the data specified by the||
|||||||||||transmit descriptor has been transmitted from the E-MAC. This bit is set to 1||
|||||||||||on assuming the completion of transmission. This is when transmission of||
|||||||||||one frame is completed and the transmit descriptor valid bit (TACT) of the||
|||||||||||next transmit descriptor not being set in single-frame/single-descriptor||
|||||||||||operation or when the last data of a frame has been transmitted and the||
|||||||||||transmit descriptor valid bit (TACT) of the next descriptor not being set in||
|||||||||||multi-buffer frame processing based on single-frame/multi-descriptor||
|||||||||||operation. After frame transmission has completed, the E-DMAC writes the||
|||||||||||transmission status back to the relevant descriptor.||
|||||||||||TC[1:0]||
|||||||||||00: Transmission has not completed, or no transmission directive||
|||||||||||11: Transmission has completed||
|||||||||||Others: Setting disabled||
|28||TUC||||0|||R/W|Transmit Underflow Frame Write-Back Complete||
|||||||||||0: Write-back has not completed for the frame causing transmit|underflow|
|||||||||||1: Write-back has completed for the frame causing transmit underflow||
|27||ROC||||0|||R/W|Receive Overflow Frame Write-Back Complete||
|||||||||||0: Write-back has not completed for the frame causing receive overflow||
|||||||||||1: Write-back has completed for the frame causing receive overflow||
|26||TABT||||0|||R/W|Transmit Abort Detect||
|||||||||||Indicates that the E-MAC aborts transmitting a frame because of failures||
|||||||||||during frame transmission.||
|||||||||||0: Frame transmission has not been aborted or no transmission directive||
|||||||||||1: Frame transmission has been aborted||
|25||RABT||||0|||R/W|Receive Abort Detect||
|||||||||||Indicates that the E-MAC aborts receiving a frame because of failures||
|||||||||||during frame reception.||
|||||||||||0: Frame reception has not been aborted or no reception directive||
|||||||||||1: Frame reception has been aborted||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|24|RFCOF|0|R/W|Receive Frame Counter Overflow|
|||||Indicates that the frame counter in the receive FIFO has overflowed.|
|||||0: Receive frame counter has not overflowed|
|||||1: Receive frame counter has overflowed|
|23|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|22|ECI|0|R|E-MAC Status Register Source|
|||||This bit is a read-only bit. When the source of an ECSR interrupt is cleared,|
|||||this bit is also cleared.|
|||||0: E-MAC status interrupt source has not been detected|
|||||1: E-MAC status interrupt source has been detected|
|21|TC[0]|0|R/W|Frame Transmission Complete|
|||||Indicates, in combination with the TC[1] bit, that all the data specified by the|
|||||transmit descriptor has been transmitted from the E-MAC. For details, see|
|||||the description of the TC[1] bit.|
|20|TDE|0|R/W|Transmit Descriptor Empty|
|||||Indicates that the transmit descriptor valid bit (TACT) of a transmit descriptor|
|||||read by the E-DMAC is not set if the previous descriptor does not represent|
|||||the end of a frame in multi-buffer frame processing based on single-frame/|
|||||multi-descriptor operation. As a result, an incomplete frame may be sent.|
|||||0: Transmit descriptor active bit TACT = 1 detected|
|||||1: Transmit descriptor active bit TACT = 0 detected|
|||||When transmit descriptor empty (TDE = 1) occurs, execute a software reset|
|||||and initiate transmission. In this case, transmission starts from the address|
|||||that is stored in the transmit descriptor list start address register (TDLAR).|
|19|TFUF|0|R/W|Transmit FIFO Underflow|
|||||Indicates that an underflow has occurred in the transmit FIFO during frame|
|||||transmission. Incomplete data is sent onto the line.|
|||||0: Underflow has not occurred|
|||||1: Underflow has occurred|
|18|FR|0|R/W|Frame Reception|
|||||Indicates that a frame has been received and the receive descriptor has|
|||||been updated. This bit is set to 1 each time a frame is received.|
|||||0: Frame has not been received|
|||||1: Frame has been received|
|17|RDE|0|R/W|Receive Descriptor Empty|
|||||Indicates that the RACT bit of a receive descriptor read by the E-DMAC for|
|||||receive DMA operation is cleared to 0 (invalid).|
|||||When receive descriptor empty (RDE = 1) occurs, reception can be|
|||||resumed by setting the RACT bit (cleared to 0) of the receive descriptor to 1|
|||||and then writing 1 to the RR bit in EDRRR.|
|||||0: Receive descriptor active bit RACT = 1 detected|
|||||1: Receive descriptor active bit RACT = 0 detected|
|16|RFOF|0|R/W|Receive FIFO Overflow|
|||||Indicates that the receive FIFO has overflowed during frame reception.|
|||||0: Overflow has not occurred|
|||||1: Overflow has occurred|
|15 to 11|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|10, 9|―|Undefined|R|Reserved|
|||||The write value should always be 0.|
|8|―|0|R|Reserved|
|||||The write value should always be 0.|
|7|RMAF|0|R/W|Receive Multicast Address Frame|
|||||0: Multicast address frame has not been received|
|||||1: Multicast address frame has been received|
|6, 5|―|All 0|R|Reserved|
|||||The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|4|RRF|0|R/W|Receive Residual-Bit Frame|
|||||0: Residual-bit frame has not been received|
|||||1: Residual-bit frame has been received|
|3|RTLF|0|R/W|Receive Too-Long Frame|
|||||Indicates that a frame whose byte size exceeds the upper limit for the|
|||||receive frame length set by RFLR has been received.|
|||||0: Too-long frame has not been received|
|||||1: Too-long frame has been received|
|2|RTSF|0|R/W|Receive Too-Short Frame|
|||||Indicates that a frame of fewer than 64 bytes has been received.|
|||||0: Too-short frame has not been received|
|||||1: Too-short frame has been received|
|1|PRE|0|R/W|PHY-LSI Receive Error|
|||||0: PHY-LSI receive error has not been detected|
|||||1: PHY-LSI receive error has been detected|
|0|CERF|0|R/W|CRC Error on Received Frame|
|||||0: CRC error has not been detected|
|||||1: CRC error has been detected|

## 26.3.42 E-MAC/E-DMAC Status Interrupt Permission Register (EESIPR)

EESIPR is a 32-bit readable/writable register that enables interrupts corresponding to individual bits in the E-MAC/EDMAC status register (EESR). An interrupt is enabled by writing 1 to the corresponding bit.

||Bit:|Bit:|31|30|29|28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||TWB1|TWB0|TC1|TUC|ROC|TABT|ECI<br>TC0<br>TDE<br>TFUF<br>RABT<br>RFCOF|FR|RDE|RFOF||
||||IP|IP|IP|IP|IP|IP|⎯<br>IP<br>IP<br>IP<br>IP<br>IP<br>IP|IP|IP|IP||
||Initial value:||0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W||
||Bit:||15|14|13|12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3|2|1|0||
||||||||||RMAF<br>RRF<br>RTLF|RTSF|PRE|CERF||
||||⎯|⎯|⎯|⎯|⎯|⎯|IP<br>⎯<br>⎯<br>⎯<br>⎯<br>IP<br>IP|IP|IP|IP||
||Initial value:||0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||R/W:||R|R|R|R|R|R|R/W<br>R/W<br>R/W<br>R<br>R<br>R<br>R|R/W|R/W|R/W||
|||||**Initial**||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|**Description**||||||
|31|TWB1IP|||0|||R/W|Write-Back Complete Interrupt Enable||||||
|||||||||0: Write-back complete interrupt is disabled||||||
|||||||||1: Write-back complete interrupt is enabled||||||
|30|TWB0IP|||0|||R/W|Write-Back Complete Interrupt Enable||||||
|||||||||0: Write-back complete interrupt is disabled||||||
|||||||||1: Write-back complete interrupt is enabled||||||
|29|TC1IP|||0|||R/W|Frame Transmission Complete Interrupt Enable||||||
|||||||||0: Frame transmission complete interrupt is disabled||||||
|||||||||1: Frame transmission complete interrupt is enabled||||||
|28|TUCIP|||0|||R/W|Transmit Underflow Frame Write-Back Complete Interrupt Enable||||||
|||||||||0: Transmit underflow frame write-back complete interrupt is disabled||||||
|||||||||1: Transmit underflow frame write-back complete interrupt is enabled||||||
|27|ROCIP|||0|||R/W|Receive Overflow Frame Write-Back Complete Interrupt Enable||||||
|||||||||0: Receive overflow frame write-back complete interrupt is disabled||||||
|||||||||1: Receive overflow frame write-back complete interrupt is enabled||||||
|26|TABTIP|||0|||R/W|Transmit Abort Detect Interrupt Enable||||||
|||||||||0: Transmit abort detect interrupt is disabled||||||
|||||||||1: Transmit abort detect interrupt is enabled||||||
|25|RABTIP|||0|||R/W|Receive Abort Detect Interrupt Enable||||||
|||||||||0: Receive abort detect interrupt is disabled||||||
|||||||||1: Receive abort detect interrupt is enabled||||||
|24|RFCOFIP|||0|||R/W|Receive Frame Counter Overflow Interrupt Enable||||||
|||||||||0: Receive frame counter overflow interrupt is disabled||||||
|||||||||1: Receive frame counter overflow interrupt is enabled||||||
|23|―|||0|||R|Reserved||||||
|||||||||This bit is always read as 0. The write value should always be 0.||||||
|22|ECIIP|||0|||R/W|E-MAC Status Register Source Interrupt Enable||||||
|||||||||0: E-MAC status interrupt is disabled||||||
|||||||||1: E-MAC status interrupt is enabled||||||
|21|TC0IP|||0|||R/W|Frame Transmission Complete Interrupt Enable||||||
|||||||||0: Frame transmission complete interrupt is disabled||||||
|||||||||1: Frame transmission complete interrupt is enabled||||||
|20|TDEIP|||0|||R/W|Transmit Descriptor Empty Interrupt Enable||||||
|||||||||0: Transmit descriptor empty interrupt is disabled||||||
|||||||||1: Transmit descriptor empty interrupt is enabled||||||
|19|TFUFIP|||0|||R/W|Transmit FIFO Underflow Interrupt Enable||||||
|||||||||0: Underflow interrupt is disabled||||||
|||||||||1: Underflow interrupt is enabled||||||
|18|FRIP|||0|||R/W|Frame Reception Interrupt Enable||||||
|||||||||0: Frame reception interrupt is disabled||||||
|||||||||1: Frame reception interrupt is enabled||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|17|RDEIP|0|R/W|Receive Descriptor Empty Interrupt Enable|
|||||0: Receive descriptor empty interrupt is disabled|
|||||1: Receive descriptor empty interrupt is enabled|
|16|RFOFIP|0|R/W|Receive FIFO Overflow Interrupt Enable|
|||||0: Overflow interrupt is disabled|
|||||1: Overflow interrupt is enabled|
|15 to 8|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|7|RMAFIP|0|R/W|Receive Multicast Address Frame Interrupt Enable|
|||||0: Receive multicast address frame interrupt is disabled|
|||||1: Receive multicast address frame interrupt is enabled|
|6, 5|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|RRFIP|0|R/W|Receive Residual-Bit Frame Interrupt Enable|
|||||0: Receive residual-bit frame interrupt is disabled|
|||||1: Receive residual-bit frame interrupt is enabled|
|3|RTLFIP|0|R/W|Receive Too-Long Frame Interrupt Enable|
|||||0: Receive too-long frame interrupt is disabled|
|||||1: Receive too-long frame interrupt is enabled|
|2|RTSFIP|0|R/W|Receive Too-Short Frame Interrupt Enable|
|||||0: Receive too-short frame interrupt is disabled|
|||||1: Receive too-short frame interrupt is enabled|
|1|PREIP|0|R/W|PHY-LSI Receive Error Interrupt Enable|
|||||0: PHY-LSI receive error interrupt is disabled|
|||||1: PHY-LSI receive error interrupt is enabled|
|0|CERFIP|0|R/W|CRC Error on Received Frame Interrupt Enable|
|||||0: CRC error interrupt is disabled|
|||||1: CRC error interrupt is enabled|

## 26.3.43 Transmit/Receive Status Copy Enable Register (TRSCER)

TRSCER specifies whether the information for the transmit and receive state reported by bits 26, 25, and 10 to 0 in the E- MAC/E-DMAC status register (EESR) is to be reflected in the TFE or RFE bit of the corresponding descriptor. The bits in this register correspond to bits 26, 25, and 10 to 0 in EESR. When a bit is cleared to 0, the transmit status (bits 26 and 10 to 8 in EESR) is reflected in the TFE bit of the transmit descriptor, and the receive status (bits 25 and 7 to 0 in EESR) is reflected in the RFE bit of the receive descriptor. In this case, the state of a status bit set to 1 is reflected as the TFE or RFE bit set to 1. When a bit is set to 1, the occurrence of the corresponding source is not reflected in the descriptor. After this LSI is reset, all bits are cleared to 0.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||TABT|RABT|
|||⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|CE|CE|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||RMAF|||RRF|RTLF|RTSF|PRE|CERF|
|||⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|CE|⎯|⎯|CE|CE|CE|CE|CE|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R/W|R|R|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 18|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|17|TABTCE|0|R/W|TABT Bit Copy Directive|
|||||0: Reflects the TABT bit status in the TFE bit of the transmit descriptor|
|||||1: Occurrence of the corresponding source is not reflected in the TFE bit of|
|||||the transmit descriptor|
|16|RABTCE|0|R/W|RABT Bit Copy Directive|
|||||0: Reflects the RABT bit status in the RFE bit of the receive descriptor|
|||||1: Occurrence of the corresponding source is not reflected in the RFE bit of|
|||||the receive descriptor|
|15 to 8|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|7|RMAFCE|0|R/W|RMAF Bit Copy Directive|
|||||0: Reflects the RMAF bit status in the RFE bit of the receive descriptor|
|||||1: Occurrence of the corresponding source is not reflected in the RFE bit of|
|||||the receive descriptor|
|6, 5|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|RRFCE|0|R/W|RRF Bit Copy Directive|
|||||0: Reflects the RRF bit status in the RFE bit of the receive descriptor|
|||||1: Occurrence of the corresponding source is not reflected in the RFE bit of|
|||||the receive descriptor|
|3|RTLFCE|0|R/W|RTLF Bit Copy Directive|
|||||0: Reflects the RTLF bit status in the RFE bit of the receive descriptor|
|||||1: Occurrence of the corresponding source is not reflected in the RFE bit of|
|||||the receive descriptor|
|2|RTSFCE|0|R/W|RTSF Bit Copy Directive|
|||||0: Reflects the RTSF bit status in the RFE bit of the receive descriptor|
|||||1: Occurrence of the corresponding source is not reflected in the RFE bit of|
|||||the receive descriptor|
|1|PRECE|0|R/W|PRE Bit Copy Directive|
|||||0: Reflects the PRE bit status in the RFE bit of the receive descriptor|
|||||1: Occurrence of the corresponding source is not reflected in the RFE bit of|
|||||the receive descriptor|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|0|CERFCE|0|R/W|CERF Bit Copy Directive|
|||||0: Reflects the CERF bit status in the RFE bit of the receive descriptor|
|||||1: Occurrence of the corresponding source is not reflected in the RFE bit of|
|||||the receive descriptor|

## 26.3.44 Receive Missed-Frame Counter Register (RMFCR)

RMFCR is a 16-bit counter that indicates the number of frames that could not be saved in the receive buffer and so were discarded during reception. When the receive FIFO overflows, the receive frames in the FIFO are discarded. The number of frames discarded at this time is counted. When the value in this register reaches H'0000FFFF, count-up is halted. Clear the counter by writing H'00000000 in this register. Note that a value other than H'00000000 must not be written to this register.

||||Bit:|Bit:|31|30|29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|⎯|⎯|⎯|⎯|⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:||15|14|13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
||||||||||||MFC[15:0]||||||||||
||||Initial value:||0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**|**Description**|||||||||||
|31|to|16|―|||All 0|||R|Reserved|||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||||
|15|to|0|MFC[15:0]|||All 0|||R/W|Missed-Frame Counter|||||||||||
|||||||||||These bits indicate the number of frames that are discarded and not|||||||||||
|||||||||||transferred to||the receive buffer during reception.|||||||||

## 26.3.45 Transmit FIFO Threshold Register (TFTR)

TFTR is a 32-bit readable/writable register that specifies the transmit FIFO threshold at which the first transmission is started. The actual threshold is 4 times the set value. The E-MAC starts transmission when the amount of data in the transmit FIFO exceeds the number of bytes specified by this register, when the transmit FIFO is full, or when one frame of data write is performed. This register must not be written to during transmission (bits TR[1:0] in EDTRR = 11).

||||Bit:|Bit:|31|30|29|28|27<br>26<br>25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R|R|R||
||||Bit:||15|14|13|12|11<br>10<br>9<br>8|7|6|5|4|3|2|1|0||
||||||⎯|⎯|⎯|⎯|⎯||TFT[10:0]||||||||
||||Initial value:||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|||||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**|**Description**||||||||||
|31|to|11|―|||All 0||R|Reserved||||||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|10|to|0|TFT[10:0]|||All 0||R/W|Transmit FIFO Threshold||||||||||
||||||||||A value in 32-byte units and smaller than the FIFO size specified||||||||by FDR must be||
||||||||||set as the transmit FIFO threshold.||||||||||
||||||||||H'000: Store and forward modes||||||||||
||||||||||H'008: 32 bytes||||||||||
||||||||||H'010: 64 bytes||||||||||
||||||||||H'018: 128 bytes||||||||||
||||||||||:            :||||||||||
||||||||||H'07F: 508 bytes||||||||||
||||||||||H'080: 512 bytes||||||||||
||||||||||:            :||||||||||
||||||||||H'0FF: 1,020 bytes||||||||||
||||||||||H'100: 1,024 bytes||||||||||
||||||||||:            :||||||||||
||||||||||H'1FF: 2,044 bytes||||||||||
||||||||||H'200: 2,048 bytes||||||||||

Note: • When starting transmission before one frame of data write has completed, take care no underflow occurs.

## 26.3.46 FIFO Depth Register (FDR)

FDR is a 32-bit readable/writable register that specifies the sizes of the transmit and receive FIFOs.

||Bit:|Bit:|31|30||29|28|27|26|25<br>24<br>23|22|21||20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||⎯|⎯||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯|⎯|⎯||⎯|⎯|⎯|⎯|⎯||
||Initial value:||0|0||0|0|0|0|0<br>0<br>0|0|0||0|0|0|0|0||
||R/W:||R|R||R|R|R|R|R<br>R<br>R|R|R||R|R|R|R|R||
||Bit:||15|14||13|12|11|10|9<br>8<br>7|6|5||4|3|2|1|0||
||||⎯|⎯||⎯|⎯|⎯||TFD[2:0]<br>⎯|⎯|⎯|||RFD[4:0]|||||
||Initial value:||0|0||0|0|0|1|1<br>1<br>0|0|0||1|1|1|1|1||
||R/W:||R|R||R|R|R|R/W|R/W<br>R/W<br>R|R|R||R/W|R/W|R/W|R/W|R/W||
|**Bit**|**Bit Name**|||**Initial Value**||||**R/W**||**Description**||||||||||
|31 to 11|―|||All||0||R||Reserved||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|10 to 8|TFD[2:0]|||All||1||R/W||Transmit FIFO Size||||||||||
|||||||||||Specifies 256 bytes|to 2 Kbytes||in 256-byte units as the size of the transmit|||||||
|||||||||||FIFO whose maximum size is 2||||Kbytes. The||setting must not be changed||||
|||||||||||after transmission/reception has||||started.||||||
|||||||||||H'00: 256 bytes||||||||||
|||||||||||H'01: 512 bytes||||||||||
|||||||||||:            :||||||||||
|||||||||||H'07: 2048 bytes||||||||||
|7 to 5|―|||All||0||R||Reserved||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|4 to 0|RFD[4:0]|||All||1||R/W||Receive FIFO Size||||||||||
|||||||||||Specifies 256 bytes|to 4 Kbytes||in 256-byte units as the size of the receive|||||||
|||||||||||FIFO whose maximum size is 4||||Kbytes. The||setting must not be changed||||
|||||||||||after transmission/reception has||||started.||||||
|||||||||||H'00: 256 bytes||||||||||
|||||||||||H'01: 512 bytes||||||||||
|||||||||||:            :||||||||||
|||||||||||H'0F: 4096 bytes||||||||||

## 26.3.47 Receiving Method Control Register (RMCR)

RMCR is a 32-bit readable/writable register that specifies the control method for the RE bit in ECMR while a frame is received. This register must be set during the receiving-halted state.

**==> picture [484 x 179] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ RNC<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R/W<br>Bit Bit Name Initial Value R/W Description<br>31 to 1 ― All 0 R Reserved<br>These bits are always read as 0. The write value should always be 0.<br>0 RNC 0 R/W Receive Enable Control<br>Sets whether to continue frame reception.<br>R<br>**----- End of picture text -----**<br>

- 0: Upon completion of reception of one frame, the E-DMAC writes the receive status to the descriptor and clears the RR bit in EDRRR to 0.

1: Upon completion of reception of one frame, the E-DMAC writes (writes back) the receive status to the descriptor. In addition, the E-DMAC reads the next descriptor and prepares for reception of the next frame.

## 26.3.48 Receive Descriptor Fetch Address Register (RDFAR)

RDFAR stores the descriptor start address that is required when the E-DMAC fetches descriptor information from the receive descriptor. Which receive descriptor information is used for processing by the E-DMAC can be recognized by monitoring addresses displayed in this register. The address from which the E-DMAC is actually fetching a descriptor may be different from the value read from this register. In the initial setting, set the address of the receive descriptor at which receive processing is to be started.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||RDFA[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||RDFA[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|RDFA[31:0]|||All 0||R/W||Receive Descriptor Fetch Address||||||||||
|||||||||||Writing to these bits during the|||||reception is prohibited.|||||

## 26.3.49 Receive Descriptor Finished Address Register (RDFXR)

RDFXR stores the start address of the receive descriptor for which the E-DMAC has just completed the write-back processing. Up to which receive descriptor has been processed by the E-DMAC can be recognized by monitoring addresses displayed in this register. In the initial setting, set the address of the descriptor immediately before the descriptor that is pointed to by the address in RDFAR.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||RDFX[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||RDFX[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|RDFX[31:0]|||All 0||R/W||Receive Descriptor Finished Address||||||||||
|||||||||||Writing to these bits during||||the|reception is prohibited.|||||

## 26.3.50 Receive Descriptor Final Flag Register (RDFFR)

RDFFR indicates whether the receive descriptor for which the E-DMAC has just completed the write-back processing and whose start address is stored in RDFXR is at the end of the receive descriptor queue (descriptor list).

**==> picture [484 x 220] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ RDLF<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R/W<br>Bit Bit Name Initial Value R/W Description<br>31 to 1 ― All 0 R Reserved<br>These bits are always read as 0. The write value should always be 0.<br>0 RDLF 0 R/W Receive Descriptor Queue Last Flag<br>Indicates whether the receive descriptor for which the E-DMAC has just<br>completed the write-back processing and whose start address is stored in<br>RDFXR is at the end of the receive descriptor queue (descriptor list).<br>0: Not the last descriptor in the receive descriptor queue<br>1: Last descriptor in the receive descriptor queue<br>R<br>**----- End of picture text -----**<br>

## 26.3.51 Transmit Descriptor Fetch Address Register (TDFAR)

TDFAR stores the descriptor start address that is required when the E-DMAC fetches descriptor information from the transmit descriptor. Which transmit descriptor information is used for processing by the E-DMAC can be recognized by monitoring addresses displayed in this register. The address from which the E-DMAC is actually fetching a descriptor may be different from the value read from this register. In the initial setting, set the address of the transmit descriptor at which transmit processing is to be started.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||TDFA[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||TDFA[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|TDFA[31:0]|||All 0||R/W||Transmit Descriptor|||Fetch|Address||||||
|||||||||||Writing|to these bits||during transmission is prohibited.|||||||

## 26.3.52 Transmit Descriptor Finished Address Register (TDFXR)

TDFXR stores the start address of the transmit descriptor for which the E-DMAC has just completed the write-back processing. Up to which transmit descriptor has been processed by the E-DMAC can be recognized by monitoring addresses displayed in this register. In the initial setting, set the address of the transmit descriptor immediately before the descriptor that is pointed to by the address in TDFAR.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||TDFX[31:16]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||TDFX[15:0]|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|0|TDFX[31:0]|||All 0||R/W||Transmit Descriptor|||Finished Address|||||||
|||||||||||Writing|to these bits||during|transmission is prohibited.||||||

## 26.3.53 Transmit Descriptor Final Flag Register (TDFFR)

TDFFR indicates whether the transmit descriptor for which the E-DMAC has just completed the write-back processing and whose start address is stored in TDFXR is at the end of the transmit descriptor queue (descriptor list).

||||Bit:|Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯||
||||Initial value:||0|0||0|0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R||R|R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|R|R||
||||Bit:||15|14||13|12|11|10|9<br>8<br>7<br>6<br>5|4|3|2|1|0||
||||||⎯|⎯||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|TDLF||
||||Initial value:||0|0||0|0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R||R|R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|R|R/W||
|**Bit**|||**Bit Name**|||**Initial Value**||||**R/W**||**Description**|||||||
|31|to|1|―|||All||0||R||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|0|||TDLF|||0||||R/W||Transmit Descriptor Queue Last|Flag||||||
|||||||||||||Indicates whether the transmit descriptor for|||which|the E-DMAC has just|||
|||||||||||||completed the write-back processing and whose start address is stored in|||||||
|||||||||||||TDFXR is at the end of the transmit descriptor queue (descriptor list).|||||||
|||||||||||||0: Not the last descriptor in the transmit descriptor queue|||||||
|||||||||||||1: Last descriptor in the transmit descriptor queue|||||||

## 26.3.54 Overflow Alert FIFO Threshold Register (FCFTR)

FCFTR is a 32-bit readable/writable register that sets the flow control of the E-MAC. The threshold can be set by the size of the receive FIFO data (bits RFD[7:0]) and the number of receive frames (bits RFF[4:0]).

If the same receive FIFO size as set by the FIFO depth register (FDR) is set when flow control is turned on according to  the RFD setting condition, flow control is turned on with (FIFO data size 64) bytes. For instance, when the RFD bits in  FDR is 7 and the RFD bits in this register is 7, flow control is turned on when (2,048 64) bytes of data is stored in the receive FIFO. The value set in the RFD bits in this register should be equal to or less than that set in the RFD bits in FDR. Flow control is turned on when either of the setting conditions of bits RFF[4:0] and bits RFD[7:0] is satisfied. Flow control is turned off when neither of the conditions is satisfied (release).

||Bit:|Bit:|31|30||29|28|27|26|25<br>24|23<br>22<br>21<br>20<br>19<br>18<br>17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||⎯|⎯||⎯|⎯|⎯|⎯|⎯<br>⎯|⎯<br>⎯<br>⎯<br>RFF[4:0]|||
||Initial value:||0|0||0|0|0|0|0<br>0|0<br>0<br>0<br>1<br>0<br>1<br>1|1||
||R/W:||R|R||R|R|R|R|R<br>R|R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W|R/W||
||Bit:||15|14||13|12|11|10|9<br>8|7<br>6<br>5<br>4<br>3<br>2<br>1|0||
||||⎯|⎯||⎯|⎯|⎯|⎯|⎯<br>⎯|RFD[7:0]|||
||Initial value:||0|0||0|0|0|0|0<br>0|1<br>1<br>1<br>1<br>1<br>1<br>1|1||
||R/W:||R|R||R|R|R|R|R<br>R|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W||
|**Bit**|**Bit Name**|||**Initial Value**||||**R/W**||**Description**||||
|31 to 21|―|||All||0||R||Reserved||||
|||||||||||These bits are always read as 0. The write value should||always be 0.||
|20 to 16|RFF[4:0]|||H'17||||R/W||Receive FIFO Overflow Alert Signal Output Threshold||||
|||||||||||H'00: When one receive frame has been stored in the receive FIFO||||
|||||||||||H'01: When two receive frames have been stored in the||receive FIFO||
|||||||||||:            :||||
|||||||||||H'16: When 23 receive frames have been stored in the receive FIFO||||
|||||||||||H'17: When 24 receive frames have been stored in the receive FIFO||||
|15 to 8|―|||All||0||R||Reserved||||
|||||||||||These bits are always read as 0. The write value should||always be 0.||
|7 to 0|RFD[7:0]|||H'FF||||R/W||Receive FIFO Overflow Alert Signal Output Threshold||||
|||||||||||H'00: When (25632) bytes of data is stored in the receive FIFO||||
|||||||||||H'01: When (51232) bytes of data is stored in the receive FIFO||||
|||||||||||:            :||||
|||||||||||H'06: When (1,79232) bytes of data is stored in the receive FIFO||||
|||||||||||H'07: When (2,04864) bytes of data is stored in the receive FIFO||||

## 26.3.55 Receive Data Padding Insert Register (RPADIR)

RPADIR is a 32-bit readable/writable register that inserts padding in receive data. To change the settings of this register, execute a software reset by means of the SWRT and SWRR bits in the E-DMAC mode register (EDMR) before making settings again.

||||Bit:|Bit:|31|30||29|28|27|26<br>25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||⎯|⎯||⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯|⎯|⎯|||PADS[4:0]||||
||||Initial value:||0|0||0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:||R|R||R|R|R|R<br>R<br>R<br>R|R|R|R/W|R/W|R/W|R/W|R/W||
||||Bit:||15|14||13|12|11|10<br>9<br>8<br>7|6|5|4|3|2|1|0||
||||||||||||PADR[15:0]|||||||||
||||Initial value:||0|0||0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:||R/W|R/W||R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**|||**Bit Name**|||**Initial Value**||||**R/W**|**Description**|||||||||
|31|to|21|―|||All||0||R|Reserved|||||||||
||||||||||||These bits are always read as 0. The||||write value should always be 0.|||||
|20|to|16|PADS[4:0]|||H'00||||R/W|Padding Size|||||||||
||||||||||||H'00: No padding insertion|||||||||
||||||||||||H'01: 1-byte insertion|||||||||
||||||||||||:            :|||||||||
||||||||||||H'1F: 31-byte insertion|||||||||
|15|to|0|PADR[15:0]|||H'0000||||R/W|Padding Slot|||||||||
||||||||||||H'0000: Inserts specified size of|||padding at||the first|byte|||
||||||||||||H'0001: Inserts specified size of|||padding at||the second byte||||
||||||||||||:            :|||||||||
||||||||||||H'FFFF: Inserts specified size of padding at|||||the 64K byte||||

## 26.3.56 Intelligent Checksum Mode Register (CSMR)

CSMR is a readable 32-bit register that specifies the intelligent checksum operation mode. This register must be set while reception is halted.

||Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||CSEBL|CSMD|||⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>⎯<br>⎯|⎯|⎯||
||Initial value:|1|1|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0|0||
||R/W:|R/W|R/W|||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|R|R||
||Bit:|15|14|||13|12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2|1|0||
|||⎯|⎯|||⎯|⎯|⎯|⎯|SB[5:0]<br>⎯<br>⎯<br>⎯<br>⎯||||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>1<br>1<br>0|1|0||
||R/W:|R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W||
|**Bit**|**Bit Name**|||**Initial Value**||||**R/W**||**Description**||||
|31|CSELB|||1||||R||Intelligent Checksum Calculation Operation Setting||||
|||||||||||0: The result of checksum calculation is not written back to the receive||||
|||||||||||descriptor.||||
|||||||||||1: The result of checksum calculation is written back to the receive||||
|||||||||||descriptor.||||
|30|CSMD|||1||||R/W||Intelligent Checksum Calculation Mode Setting||||
|||||||||||0: After having skipped the number of bytes specified in SB[5:0], counting||||
|||||||||||from the beginning of the MAC-layer packet, the checksum is calculated||||
|||||||||||for all subsequent data||||
|||||||||||1: MAC- or IP-layer packets are detected and checksums are calculated for||||
|||||||||||upper-layer protocol packets such as TCP or UDP.||||
|29 to 6|―|||All||0||R||Reserved||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||
|5 to 0|SB[5:0]*1|||011010||||R/W||Intelligent Checksum Calculation Skip Bytes||||
|||||||||||These bits specify the number of bytes to be skipped|for checksum|||
|||||||||||calculation, counting from the beginning of the data received in the E-||||
|||||||||||DMAC. When padding bytes are to be added, specify the checksum start||||
|||||||||||position to cover the amount or extent of padding.||||
|||||||||||H'00: 0 bytes (meaning checksum calculation is performed from the||||
|||||||||||beginning of the packet.)||||
|||||||||||H'02: 2 bytes||||
|||||||||||:           :||||
|||||||||||H'1A: 26 bytes||||
|||||||||||H'3E: 62 bytes||||

Note 1. These bits should only be set when CSEL is 1 and CSMD is 0; otherwise, set to H'00.

## 26.3.57 Intelligent Checksum Skipped Bytes Monitor Register (CSSBM)

CSSBM is a 32-bit readable register that holds the number of bytes that have been skipped in received packets being handled by the E-DMAC. The number of skipped bytes can be monitored through this register. The amount of data received in E-DMAC may not match the number of skipped bytes.

**==> picture [484 x 197] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ ⎯ SBM[5:0]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit Bit Name Initial Value R/W Description<br>31 to 6 ― All 0 R Reserved<br>These bits are always read as 0. The write value should always be 0.<br>5 to 0 SBM[5:0] 000000 R Number of Skipped Bytes<br>These bits are read-only. Writing is prohibited.<br>These bits are initialized when the beginning of a packet for reception is<br>detected.<br>**----- End of picture text -----**<br>

Note: • This register is only valid when CSEL is 1 and CSMD is 0.

## 26.3.58 Intelligent Checksum Monitor Register (CSSMR)

CSSMR is a 32-bit register that holds the checksum value of received packets being handled by the E-DMAC. The checksum value can be monitored through this register. The amount of data received in E-DMAC may not match the number of skipped bytes.

||Bit:|31|30|29|28|27|26<br>25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||⎯|⎯|⎯|⎯|⎯|⎯<br>⎯<br>⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯|⎯||
||Initial value:|0|0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R|R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R|R||
||Bit:|15|14|13|12|11|10<br>9<br>8|7|6|5|4|3|2|1|0||
||||||||CS[15:0]||||||||||
||Initial value:|0|0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R|R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R|R||
|**Bit**|**Bit Name**||**Initial Value**|||**R/W**|**Description**||||||||||
|31 to 6|―||All 0|||R|Reserved||||||||||
||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|5 to 0|CS[15:0]||000000|||R|Intelligent Checksum Value||||||||||
||||||||These bits are read-only. Writing is prohibited.||||||||||
||||||||These bits are initialized when the beginning of a packet for||||||||reception is||
||||||||detected.||||||||||

Note: • This register is only valid when CSEL = 1 and CSMD = 0.

## 26.4 Operation

The ETHER consists of the following three function units:

- DMA transfer controller (E-DMAC):DMA transfer between the transmit/receive buffer

in the memory and the transmit/receive FIFO

- MAC controller (E-MAC):                Transmission/reception processing between

   - the transmit/receive FIFO and the MII

- Transfer Switching Unit (TSU):         CAM processing

Using its direct memory access (DMA) function, the E-DMAC performs DMA transfer of frame data between a userspecified Ethernet frame transmission/reception data storage destination (accessible memory space: transmit buffer/ receive buffer) and the transmit/receive FIFO in the E-DMAC. The user cannot read and write data from and to the transmit/receive FIFO directly via the CPU.

To enable the E-DMAC to perform DMA transfer, information (data) including a transmit/receive data storage address and so forth, referred to as a descriptor, is required. The E-DMAC reads transmit data from the transmit buffer or writes receive data to the receive buffer according to the descriptor information. By arranging multiple descriptors as a descriptor row (list) (to be placed in a readable/writable memory space), multiple Ethernet frames can be transmitted or received continuously.

The E-MAC constructs an Ethernet frame using the data written to the transmit FIFO and transmits the frame to the MII. It also performs a CRC check of an Ethernet frame received from the MII and deconstructs the frame to write to the receive FIFO. The E-MAC supports the MII format for interface to the PHI-LSI connected externally to this LSI. The TSU, which is placed between the E-DMAC and E-MAC, references the CAM entry table to select one of the following tasks according to the Ethernet frame destination address (DA) input to the E-MAC.

- Receives data and writes to the receive FIFO.

- Discards data.

Figure 26.2 shows the frame data path and an overview of each setting.

**==> picture [264 x 468] intentionally omitted <==**

**----- Start of picture text -----**<br>
In memory<br>Transmit  Receive<br>data buffer data buffer<br>Internal bus<br>Transmit request Receive request ETHER<br>EDTRR0.TR = 11  EDRRR0.RR = 1<br>E-DMAC<br>Descriptor<br>DMA transfer<br>access<br>Transmitter startup Receiver startup<br>EDSR0.ENT = 1 EDSR0.ENR = 1<br>Transmit FIFO Receive FIFO<br>TSU CAM control<br>CAM entry table<br>referenceCAM  (32 entries × 48 bits)<br>(Reference setting: TSU_TEN)<br>Transmission  Reception<br>enabled enabled<br>ECMR0.TE = 1 ECMR0.RE = 1<br>E-MAC<br>PHY<br>MII<br>Transmit/receive<br>descriptor<br>**----- End of picture text -----**<br>

**Figure 26.2 ETHER Data Path and Various Settings**

## 26.4.1 Descriptors and Descriptor List

The E-DMAC performs DMA transfer according to the information (data), referred to as a descriptor, written in memory space. There are two types of descriptors: transmit descriptors and receive descriptors. Before a DMA transfer, DMA transfer information including a transmit/receive frame data storage address must be set by software.

The E-DMAC automatically starts reading a transmit/receive descriptor when the TR bits in EDTRR are set to 11 or the RR bit in EDRRR is set to 1, and performs DMA transfer of frame data between the transmit/receive buffer and transmit/ receive FIFO according to the information stored in the descriptor. After completion of Ethernet frame transmission/ reception, the E-DMAC disables the descriptor valid/invalid bit and reflects the result of transmission/reception in the status bits.

Descriptors are placed in a readable/writable memory space. The address of the start descriptor (descriptor to be read first by the E-DMAC) is set in TDLAR/RDLAR. When multiple descriptors are prepared as a descriptor row (descriptor list), the descriptors are placed in continuous addresses (memory) according to the descriptor length set in the DL0 and DL1 bits in EDMR.

## (1) Transmit Descriptor

Figure 26.3 shows the configuration of a transmit descriptor and the relationship with a transmit buffer. The data of a transmit descriptor consists of TD0, TD1, TD2, and padding data in groups of 32 bits from top to end. The length of padding data is determined according to the descriptor length specified by the DL0 and DL1 bits in EDMR. TD0 indicates whether the transmit descriptor is valid or invalid, and information about the descriptor configuration and status. TD1 indicates the length of data in a transmit buffer to be transferred (TDL) as specified by the descriptor. TD2 indicates the start address of a transmit buffer that holds data to be transferred (TBA).

Depending on the descriptor specification, one transmit descriptor can specify all transmit data of one frame (singleframe/single-buffer) or multiple descriptors can specify the transmit data of one frame (single-frame/multi-buffer). As an example of single-frame/multi-buffer operation, the data portion that is used in a fixed manner in each Ethernet frame transmission can be referenced by multiple descriptors. For example, multiple descriptors can share the destination address and transmit source address in an Ethernet frame, and the remaining data can be stored in each separate buffer.

**==> picture [392 x 217] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transmit descriptor Transmit buffer<br>31 30 29 28 27 26 25 12 11 0<br>T T T T T<br>A D F F F<br>TD0 CT EL P E EI Reserved TFS[26:0]<br>Valid transmit data<br>31 16<br>TD1 TDL<br>31 0<br>TD2 TBA<br>Padding (4/20/52 bytes)*<br>Note: *According to the descriptor length set by the DL0 and DL1 bits in EDMR, the padding size is determined as follows:<br>For 16 bytes padding = 4 bytes<br>For 32 bytes padding = 20 bytes<br>For 64 bytes padding = 52 bytes<br>**----- End of picture text -----**<br>

**Figure 26.3 Relationship between Transmit Descriptor and Transmit Buffer**

## (a) Transmit Descriptor 0 (TD0)

Before the TR bits in EDTRR are set to 11, the user sets whether the bits of the descriptor are valid or invalid bit and sets other descriptor configuration. After Ethernet frame transmission, the E-DMAC disables the valid/invalid bits of the descriptor and writes status information. This operation is referred to as write-back.

When using TD0, the user should write desired values to bits 31 to 28 and 26 according to the descriptor configuration. Bits 27 and 25 to 0 should be cleared to 0.

|**Bit**||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|
|31||TACT|0|R/W|Transmit Descriptor Valid/Invalid|
||||||Indicates whether the corresponding descriptor is valid or invalid. To make|
||||||this bit valid, store transmit data in a transmit buffer (user-specified transmit|
||||||data storage destination) beforehand, then write 1 to this bit. The E-DMAC|
||||||clears this bit to 0 after data transfer.|
||||||0: Indicates that this transmit descriptor is invalid|
||||||Indicates the initial setting state, the state after 0 is written, or (in case the|
||||||user writes 1 to this bit) that this bit is cleared to 0 because the E-DMAC|
||||||data transfer processing is completed.|
||||||If this state is recognized when the E-DMAC reads a descriptor, the E-|
||||||DMAC clears the TR bit in EDTRR to 0, and halts transfer operation|
||||||related to transmission by the E-DMAC.|
||||||1: Indicates that this transmit descriptor is valid|
||||||After the user writes 1 to this bit, this bit indicates that data is not|
||||||transferred yet or data is being transferred.|
||||||When there is a descriptor row (descriptor list) consisting of multiple|
||||||continuous descriptors, the E-DMAC can continue operation when this bit|
||||||of the next descriptor is valid.|
|30||TDLE|0|R/W|Transmit Descriptor List End|
||||||Indicates whether the corresponding descriptor is the last descriptor of the|
||||||descriptor row (descriptor list).|
||||||0: Not last descriptor|
||||||After transfer of the corresponding descriptor, the E-DMAC reads the next|
||||||one in the list of continuous descriptors.|
||||||1: Last descriptor|
||||||After transfer of the corresponding descriptor, the E-DMAC reads the|
||||||descriptor placed at the address indicated by TDLAR.|
|29,|28|TFP[1:0]|00|R/W|Transmit Frame Position|
||||||These bits indicate whether information of this descriptor represents|
||||||information about the start, middle, or end of the transmit frame.|
||||||00: The information of the descriptor represents information about the|
||||||middle of the frame.|
||||||01: The information of the descriptor represents information about the end|
||||||of the frame.|
||||||10: The information of the descriptor represents information about the start|
||||||of the frame.|
||||||11: The information of the descriptor represents all information about the|
||||||frame (single-frame/single-descriptor (single-buffer)).|
||||||Reference|
||||||When one frame is divided for use, the method of specifying this bit for a|
||||||descriptor row according to the number of divisions is described below.|
||||||For single-frame/single-descriptor operation|
||||||First descriptor: TFP[1:0] = 11|
||||||For single-frame/two-descriptor operation|
||||||First descriptor: TFP[1:0] = 10|
||||||Second descriptor: TFP[1:0] = 01|
||||||For single-frame/three-descriptor operation|
||||||First descriptor: TFP[1:0] = 10|
||||||Second descriptor: TFP[1:0] = 00|
||||||Third descriptor: TFP[1:0] = 01|
||||||When the number of divisions is large, a descriptor row is configured by|
||||||adding intermediate descriptors with TFP[1:0] = 00.|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|27|TFE|0|R/W|Transmit Frame Error Occurrence|
|||||Indicates that an error occurred in the transmit frame.|
|||||0: The TFS11 to TFS0 bits are all 0|
|||||1: One of the TFS11 to TFS0 bits is 1|
|||||The TFS8 to TFS0 bits can be masked for each factor by using TRSCER.|
|||||The TFS11 to TFS9 bits cannot be masked.|
|||||This bit is set by the E-DMAC write-back operation.|
|26|TWBI|0|R/W|Write-Back Completion Interrupt Notification|
|||||0: Does not notify of a write-back completion interrupt|
|||||1: After a write-back operation to this descriptor is complete, this bit sets the|
|||||TWB1 and TWB0 bits in EESR to 11 and notifies the CPU of a write-back|
|||||completion interrupt.|
|||||This bit is valid only for the descriptor including the end of transmit frame|
|||||(TFP = 01 or 11). This bit is cleared to 0 by the E-DMAC write-back|
|||||operation.|
|25 to 12|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11 to 0|TFS|All 0|R/W|Transmit Frame Status|
||[11:0]|||These bits indicate the status of the corresponding frame. A bit below, which|
|||||is set by the E-DMAC write-back operation, indicates the occurrence of the|
|||||corresponding event when set to 1.|
|||||TFS[11:10]: Reserved (The write value should always be 0.)|
|||||TFS[9]: Transmit FIFO underflow (Corresponding to the TUC bit in EESR)|
|||||TFS[8]: Detection of transmission abort (Corresponding to the TABT bit in|
|||||EESR)|
|||||TFS[7:0]: Reserved (The write value should always be 0.)|

## (b) Transmit Descriptor 1 (TD1)

TD1 indicates the data length of the transmit buffer used by the corresponding descriptor. The user should set TD1 before the start of a read by the E-DMAC.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|16|TDL|All 0|R/W|Transmit Buffer Data Length (in bytes)|
||||[15:0]|||These bits indicate the data length of the corresponding transmit buffer in bytes.|
|||||||The specifiable data lengths are from a minimum of 1 (H'0001) byte to a maximum|
|||||||of 64 K - 32 (H'FFE0) bytes.|
|15|to|0|―|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

## (c) Transmit Descriptor 2 (TD2)

TD2 indicates the start address of the corresponding 32-bit width transmit buffer. An address value should be specified in a 16-byte boundary.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|0|TBA|All 0|R/W|Transmit Buffer Start Address|
||||[31:0]|||These bits set the start address of the corresponding transmit buffer in a 16-byte|
|||||||boundary.|

If descriptors are set below, the E-DMAC does not return to normal operation until a system reset is performed.

- TFP (transmit frame position) is not logically correct

   - Example: The TFP bits are set to 11 in a descriptor (descriptor A) and the TFP bits are set to 01 in the next descriptor (descriptor B). This specification means that there is no descriptor indicating the start of the transmit frame specified by descriptor B.

- TBL (transmit buffer length) is set to 0

When one transmit frame is divided into three parts or more with transmit descriptors, the E-DMAC performs the following write-back operation:

- A write-back operation is performed for a transmit descriptor including information for the start of the transmit frame (TFP = 10 or 11) and for a transmit descriptor including information for the end of the frame (TFP = 01 or 11).

- A write-back operation is not performed for a transmit descriptor for the middle of the frame (TFP = 00).

However, TFE (transmit frame error occurrence) or TFS (transmit frame status) is written only to a transmit descriptor including information for the end of the frame (TFP = 01 or 11) by a write-back operation.

Before changing a transmit descriptor with the software, make sure that a write-back operation has been performed (TACT = 0) for the transmit descriptor including information for the end of the frame (TFP = 01 or 11) to avoid overwriting (re-setting) an unprocessed transmit descriptor.

## (2) Receive Descriptor

Figure 26.4 shows the relationship between a receive descriptor and receive buffer.

The data of a receive descriptor consists of RD0, RD1, RD2, and padding data in groups of 32 bits from top to end. The length of padding data is determined according to the descriptor length specified by the DL0 and DL1 bits in EDMR. RD0 indicates whether the receive descriptor is valid or invalid, and information about descriptor configuration and status. RD1 indicates the length of data that can be received in the receive buffer specified by the descriptor (RBL) and the length of the received frame data (RDL). RD2 indicates the start address of the receive buffer for storing receive data (RBA).

Depending on the descriptor specification, one receive descriptor can specify the storing of all receive data of one frame in a receive buffer (single-frame/single-buffer). All receive frames can be stored in a single buffer if RBL of each descriptor is set to more than 1514 bytes (maximum Ethernet frame length).

**==> picture [379 x 211] intentionally omitted <==**

**----- Start of picture text -----**<br>
Receive descriptor Receive buffer<br>31 30 29 28 27 26 25       1615                                        0<br>R R R R R<br>RD0 A D F F C RFS[9:0] RCS[15:0]<br>C L P E S<br>T E E<br>Valid receive data<br>RBL 15                                        0<br>RD1<br>31                                     16 RDL<br>31                                                                                     0<br>RD2 RBA<br>Padding (4/20/52 bytes)*<br>Note: *According to the descriptor length set by the DL0 and DL1 bits in EDMR, the padding size is determined as follows:<br>For 16 bytes padding = 4 bytes<br>For 32 bytes padding = 20 bytes<br>For 64 bytes padding = 52 bytes<br>**----- End of picture text -----**<br>

**Figure 26.4 Relationship between Receive Descriptor and Receive Buffer**

## (a) Receive Descriptor 0 (RD0)

The user sets whether the bits of the descriptor are valid or invalid and whether the descriptor represents the end of the descriptor list in RD0 before the RR bit in EDRRR is set to 1 and the start of a read by the E-DMAC. After receive DMA transfer of an Ethernet frame by the E-DMAC, the E-DMAC disables the valid/invalid bits of the descriptor and writes status information. This operation is referred to as write-back.

When using RD0, the user should write desired values to bits 31 and 30 according to the descriptor configuration. Bits 29 to 0 should be cleared to 0.

||||**Initial**|||
|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|31||RACT|0|R/W|Receive Descriptor Valid/Invalid|
||||||Indicates whether this descriptor is valid or invalid. To make this bit valid, prepare|
||||||a receive buffer (user-specified receive data storage destination) beforehand,|
||||||then write 1 to this bit. The E-DMAC clears this bit to 0 after data transfer.|
||||||0: Indicates that this receive descriptor is invalid|
||||||Indicates the initial setting state, the state after 0 is written to, or (in case the|
||||||user writes 1 to this bit) that this bit is cleared to 0 because the E-DMAC data|
||||||transfer processing is completed|
||||||If this state is recognized when the E-DMAC reads a descriptor, the E-DMAC|
||||||clears the RR bit in EDRRR to 0, and halts transfer operation related to|
||||||reception by the E-DMAC|
||||||1: Indicates that this receive descriptor is valid|
||||||Indicates that data is not transferred yet after the user writes 1 to this bit, or that|
||||||data is being transferred|
||||||When there is a descriptor row (descriptor list) consisting of multiple continuous|
||||||descriptors, the E-DMAC can continue operation when this bit of the next|
||||||descriptor is valid|
|30||RDLE|0|R/W|Receive Descriptor List End|
||||||Indicates whether this descriptor is the last descriptor of the descriptor row|
||||||(descriptor list).|
||||||0: Not last descriptor|
||||||After transfer of this descriptor, the E-DMAC reads the next one in the list of|
||||||continuous descriptors|
||||||1: Last descriptor|
||||||After transfer of this descriptor, the E-DMAC reads the descriptor placed at the|
||||||address indicated by RDLAR|
|29,|28|RFP[1:0]|00|R/W|Receive Frame Position 1, 0|
||||||The E-DMAC indicates by write-back operation whether information of the|
||||||corresponding descriptor represents information about the start, middle, or end of|
||||||the receive frame.|
||||||00: The information of the descriptor represents information about the middle of|
||||||the frame|
||||||01: The information of the descriptor represents information about the end of the|
||||||frame|
||||||10: The information of the descriptor represents information about the start of the|
||||||frame|
||||||11: The information of the descriptor represents all information about the frame|
||||||(single-frame/single-descriptor (single-buffer))|
||||||Note:|
||||||The relationship between a frame after reception of one frame and a descriptor is|
||||||described below.|
||||||When the receive buffer data length is less than the receive frame length, these|
||||||bits are set to a value other than 11 after reception. When they are set so,|
||||||reception processing should be started after a software reset.|
|27||RFE|0|R/W|Receive Frame Error Occurrence|
||||||Indicates that an error occurred in the receive frame.|
||||||0: RFS9 to RFS0 are all 0|
||||||1: One of RFS9 to RFS0 is 1|
||||||Each of RFS8 to RFS0 can be masked by using TRSCER. RFS9 cannot be|
||||||masked.|
||||||This bit is set by the E-DMAC write-back operation.|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|26|||RCSE|0|R/W|Receive Packet Checksum Value Evaluation by Intelligent Checksum|
|||||||When CSEBL = 1 and CSMD = 1, the value of this bit is set as shown in Table|
|||||||26.3, according to the receive packet and receive data.|
|||||||The information of this bit is invalid when operation is performed with a setting|
|||||||other than above.|
|25|to|16|RFS[9:0]|All 0|R/W|Receive Frame Status|
|||||||These bits indicate the error status during frame reception.|
|||||||RFS9: Receive FIFO overflow (corresponding to the RFOF bit in EESR)|
|||||||RFS8: Reserved (write value should be 0)|
|||||||RFS7: Multicast address frame received (corresponding to the RMAF bit in EESR)|
|||||||RFS[6:5]: Reserved (write value should be 0)|
|||||||RFS4: Residual-bit frame receive error (corresponding to the RRF bit in EESR)|
|||||||RFS3: Long frame receive error (corresponding to the RTLF bit in EESR)|
|||||||RFS2: Short frame receive error (corresponding to the RTSF bit in EESR)|
|||||||RFS1: PHY-LSI receive error (corresponding to the PRE bit in EESR)|
|||||||RFS0: CRC error on receive frame (corresponding to the CERF bit in EESR)|
|15|to|0|RCS[15:0]|All 0|R/W|Receive Packet Checksum Value in Intelligent Checksum|

**Table 26.3 RCSE State Determined by Receive Packet Type and Receive Data**

||**Frame Type**<br>**Normal Data**<br>**Abnormal Data**|
|---|---|
|**IP Version**|**Option and Extension**<br>**Header**<br>**RCS[15:0]**<br>**RCSE**<br>**RCS[15:0]**<br>**RCSE**|
|IPv4|None<br>H'FFFF<br>H'0000<br>0<br>Undefined<br>1|
||Fragment<br>Undefined<br>Undefined<br>Undefined<br>Undefined|
||Option<br>H'FFFF<br>H'0000<br>0<br>Undefined<br>1|
|IPv6|None<br>H'FFFF<br>H'0000<br>0<br>Undefined<br>1|
||Hop-by-hop<br>H'FFFF<br>H'0000<br>0<br>Undefined<br>1|
||Routing<br>H'FFFF<br>H'0000<br>0<br>Undefined<br>1|
||Destination options<br>H'FFFF<br>H'0000<br>0<br>Undefined<br>1|
||AH<br>H'FFFF<br>H'0000<br>0<br>Undefined<br>1|
||Fragment<br>Undefined<br>Undefined<br>Undefined<br>Undefined|
||ESP<br>H'0000<br>1<br>H'0000<br>1|
||MobileIPv6<br>H'0000<br>1<br>H'0000<br>1|
||Others<br>H'0000<br>1<br>H'0000<br>1|
|Other than IPv4 or|IPv6<br>H'0000<br>0<br>H'0000<br>0|

## (b) Receive Descriptor 1 (RD1)

In RD1, the user specifies the data length of a receive buffer usable by the corresponding descriptor. After reception of a frame, RD1 indicates the length of a frame received by the E-DMAC.

The user should set RD1 before the start of a read by the E-DMAC.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|16|RBL|All 0|R/W|Receive Buffer Data Length (in bytes, to be specified with a 32-byte boundary)|
||||[15:0]|||These bits set the length of data that can be received by the corresponding|
|||||||receive buffer with an integral multiple of 32 bytes.|
|||||||The specifiable data lengths are from a minimum of 32 (H'0020) bytes to a|
|||||||maximum of 64 K - 32 (H'FFE0) bytes.|
|||||||Set the data length so that a receive frame can be stored in a single buffer.|
|||||||When the checksum function is disabled, any received frame can be stored in a|
|||||||single buffer if the setting is for 1514 bytes (the maximum length of an Ethernet|
|||||||frame) or more. When the checksum function is enabled, any received frame can|
|||||||be stored in a single buffer if the setting is for 1516 bytes (the maximum length of|
|||||||an Ethernet frame + checksum data) or more.|
|15|to|0|RDL|All 0|R|Receive Data Length|
||||[15:0]|||These bits indicate the data length of a receive frame stored in the receive buffer.|
|||||||Receive data transferred to the receive buffer does not include CRC data (4 bytes)|
|||||||placed at the end of a frame.|
|||||||Accordingly, these bits indicate the number of bytes (valid data bytes), excluding|
|||||||the CRC code, as the data length of the received frame. When the checksum|
|||||||function is enabled, they indicate the number of bytes including the checksum|
|||||||value (2 bytes) as the data length.|
|||||||In single-frame/multi-buffer (descriptor) operation, only the receive data length of|
|||||||the last descriptor is valid. The receive data length of an intermediate descriptor|
|||||||has no meaning.|
|||||||The maximum frame length that can be received is:|
|||||||When padding function is invalid: 64 Kbytes between 1 byte (H'FFFF)|
|||||||When padding function is valid: 64 Kbytes between 32 bytes (H'FFE0)|

## (c) Receive Descriptor 2 (RD2)

RD2 indicates the start address of the corresponding receive buffer. Set the start address of a receive buffer with a 32byte boundary.

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|0|RBA|All 0|R/W|Receive Buffer Start Address|
||||[31:0]|||These bits set the start address of the corresponding receive buffer with a 32-byte|
|||||||boundary.|

The E-DMAC performs DMA transfer for a receive frame from the address specified by RBA (receive buffer address) to the receive buffer in 32-byte units. RBL (receive buffer length) must be set to be an integral multiple of 32 bytes. If data to be transferred is less than 32 bytes, invalid data will be written to.

## [Example]

When the receive frame length is 170 bytes and the required receive buffer capacity is 192 bytes (32 bytes  6), the sixth DMA-transfer causes invalid data to be written to the receive buffer (In the 32-byte DMA data, the former 10 bytes are valid and the latter 22 bytes are invalid).

Padding of the value 0 can be inserted into only one position in the receive frame by setting RPADIR. The padding size can be selected from 1 byte to 31 bytes in byte units. When padding is inserted into a receive frame, a receive buffer area equal to the total of "receive frame length and padding size" is required. RPADIR setting is valid for all receive frames. RFE (receive frame error occurrence), PV (padding insertion), RFS (receive frame status) and RFS (receive frame status) are only set in the receive descriptor including information for the end of the frame (TFP = 01 or 11) by a write-back operation.

Before re-setting a receive descriptor with the software, completion of a write-back operation for the receive descriptor (RACT = 0) must be confirmed to avoid rewriting to (and re-setting) an unprocessed receive descriptor.

## (3) Descriptor and Transmit/Receive Buffer

## (a) Transmission

Each transmit descriptor specifies one transmit buffer. The E-DMAC transfers a transmit frame stored in a transmit buffer specified by a transmit descriptor to the transmit FIFO. Multiple transmit frames stored in transmit buffers specified by multiple descriptors can be connected into one transmit frame and transferred to the transmit FIFO. Figure 26.5 shows the relationship between the transmit descriptors and transmit buffers.

**==> picture [399 x 287] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transmit descriptor ring Transmit buffer Transmit frame data<br>(in memory) (in memory)<br>(Transmit data transferred by DMA transfer from<br>memory to transmit FIFO is configured as a frame<br>TACT 4 bytes in the MAC and output to the MII.)<br>TDL<br>TFP[1:0]<br>Transmit frame A<br>1 0 1 1 16-byte boundary<br>Transmit descriptor 1 Transmit buffer 1 Transmit buffer 1<br>(Transmit frame A) 16-byte boundary<br>1 0 1 0 Transmit frame B<br>Transmit descriptor 2 16-byte boundary Transmit buffer 2 Transmit buffer 4 Transmit buffer 3 Transmit buffer 2<br>(Transmit frame B)<br>16-byte boundary Transmit buffers 2 to 4 are connected to be one frame<br>1Transmit descriptor 30 0 0 16-byte boundary Transmit buffer 3 (transmit frame B) and output to the MII.<br>(Transmit frame B) 16-byte boundary<br>1 0 0 1 16-byte boundary Transmit buffer 4<br>Transmit descriptor 4 16-byte boundary<br>(Transmit frame B)<br>16-byte boundary Transmit frame C<br>1 0 1 0 Transmit buffer 5 Transmit buffer 6 Transmit buffer 5<br>Transmit descriptor 5 16-byte boundary<br>(Transmit frame C) Transmit buffers 5 and 6 are connected to be one frame<br>1 0 0 1 16-byte boundary (transmit frame C) and output to the MII.<br>Transmit descriptor 6 Transmit buffer 6<br>(Transmit frame C) 16-byte boundary<br>1 0 1 1 Transmit frame D<br>Transmit descriptor 7 16-byte boundary Transmit buffer 7 Transmit buffer 7<br>(Transmit frame D) 16-byte boundary<br>1Transmit descriptor 81 1 1 16-byte boundary Transmit buffer 8 Transmit frame ETransmit buffer 8<br>(Transmit frame E) 16-byte boundary<br>**----- End of picture text -----**<br>

**Figure 26.5 Relationship between Transmit Descriptor and Transmit Buffer**

## (b) Reception

Each receive descriptor specifies one receive buffer. The E-DMAC receives a receive frame from the receive FIFO and stores it in a receive buffer specified by a receive descriptor.

Figure 26.6 shows the relationship between the receive descriptors and receive buffers.

**==> picture [365 x 294] intentionally omitted <==**

**----- Start of picture text -----**<br>
Receive descriptor ring Receive buffer Receive frame data<br>(in memory) (in memory)<br>(A frame input from the MII is written<br>to the receive FIFO. Then the frame<br>RACT 4 bytes is transferred by DMA transfer from the<br>RDL receive FIFO to the receive buffer in memory.)<br>RFP[1:0]<br>32-byte Receive frame A<br>0 0 1 1 boundary Receive frame A<br>Transmit descriptor 1 (29 bytes) 29 bytes<br>(Transmit frame A) 32-byte (Undefined value) When the receive frame ;length is not a multiple<br>0 0 1 1 boundary 32 bytes of of 32 bytes, an undefined value is written.<br>unused area<br>Transmit descriptor 2 32-byte<br>(Transmit frame B) boundary<br>0 0 1 1<br>32-byte<br>Transmit descriptor 3 boundary<br>(Transmit frame C) Padding data Receive frame B<br>1 0 - - 32-byte Receive frame B 53 bytes<br>(Waiting for a receive frameTransmit descriptor 4 ) boundary (53 bytes) When padding data is inserted at the top of<br>the receive frame. the receive frame can be<br>1 0 - - boundary32-byte written to arbitrary byte boundary in memory.<br>Transmit descriptor 5<br>(Waiting for a receive frame)<br>32-byte<br>1 1 - - boundary<br>Transmit descriptor 6<br>(Waiting for a receive frame) 32-byte Receive frame C<br>boundary Receive frame C 64 bytes<br>(Former 29 bytes)<br>32-byte When padding data is inserted in the middle<br>boundary of the receive frame, PRADIR should be set<br>Padding data so that the latter half of data is written from<br>32-byte Receive frame C the 4-byte boundary in the receive buffer.<br>boundary (Latter 35 bytes)<br>32-byte<br>boundary<br>**----- End of picture text -----**<br>

**Figure 26.6 Relationship between Receive Descriptor and Receive Buffer**

## (4) Descriptor Pointer

The E-DMAC controls the transmit and receive descriptor addresses in memory and the processing priority by using the following registers.

1. Registers related to a transmit descriptor

- TDLAR: Address of the start descriptor in a list of transmit descriptors.

- TDFAR: Address of the transmit descriptor to be processed

- TDFXR: Address of the transmit descriptor that finished processing (set by a write-back operation) last

- TDFFR (DL bit): Indicates whether the TDLE value of the transmit descriptor specified by TDFXR is 1 or not.

2. Registers related to receive descriptor:

- RDLAR: Address of the start descriptor in a list of receive descriptors.

- RDFAR: Address of the receive descriptor to be processed

- RDFXR: Address of the receive descriptor that finished processing (set by a write-back operation) last

- RDFFR (DL bit): Indicates whether the RDLE value of the receive descriptor specified by RDFXR is 1 or not.

Transmit descriptors and receive descriptors have a ring structure. When the TDLE (RDLE) value of the processed transmit (receive) descriptor is 0, the next descriptor will be processed. The next descriptor is the transmit (receive) descriptor at the address obtained by adding the processed transmit (receive) descriptor address to the descriptor length specified by the DL bits in EDMR. When the TDLE (RDLE) value of the processed transmit (receive) descriptor is 1, the transmit descriptor indicated by TDLAR (RDLAR) will be processed next. Figure 26.7 shows the relationship between the transmit/receive descriptor ring and read pointer.

The transmit descriptor list must be large enough to point to five or more transmit frames. If four or less transmit frames are pointed to in a list, E-DMAC operation is not guaranteed. Accordingly, do not set that all the transmit descriptors in a ring are used by four or less descriptors. The receive descriptor list does not have this restriction. For example, one receive frame can use all receive descriptors in a list.

In the initial setting, the start address of a descriptor list must be set to TDLAR (RDLAR) and TDFAR (RDFAR), and the end descriptor address of the descriptor list to TDFXR (RDFXR) by the software.

The E-DMAC updates TDFAR (RDFAR), TDFXR (RDFXR), and the DL bit in TDFFR (DL bit in RDFFR) each time a descriptor is processed.

**==> picture [337 x 426] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transmit descriptor ring (in memory)<br>TACT<br>TDLE<br>Transmit descriptor list start address register(TDLAR) H'0000 1 0<br>Transmit descriptor 1<br>H'0010 1 0<br>Transmit descriptor 2<br>H'0020 0 0<br>Transmit descriptor 3<br>Transmit descriptor processed address register(TDFXR) H'0030 0 0<br>Transmit descriptor 4<br>Transmit descriptor fetch address register(TDFAR) H'0040 1 0 in processing<br>Transmit descriptor 5<br>H'0050 1 0<br>Transmit descriptor 6<br>The transmit descriptor final flag register H'0060 1 0<br>(TDFFR) is set to H'00000000.<br>Transmit descriptor 7<br>H'0070 1 1<br>Transmit descriptor 8<br>Receive descriptor ring (in memory)<br>RACT<br>R DLE<br>Receive descriptor list start address register(RDLAR) H'0000 1 0<br>Receive descriptor fetch address register Receive descriptor 1 in processing<br>(RDFAR) H'0010 1 0<br>Receive descriptor 2<br>H'0020 1 0<br>Receive descriptor 3<br>H'0030 1 0<br>Receive descriptor 4<br>H'0040 1 0<br>Receive descriptor 5<br>H'0050 0 0<br>Receive descriptor 6<br>H'0060 0 0<br>Receive descriptor processed address register Receive descriptor 7<br>(RDFXR) H'0070 0 1<br>The receive descriptor final flag register(RDFFR) is set to H'00000001. Receive descriptor 8<br>**----- End of picture text -----**<br>

Note: Addresses in the descriptor list are shown as an example when the descriptor length is 16 bytes

**Figure 26.7 Relationship between Transmit/Receive Descriptor and Descriptor Pointing Registers**

## 26.4.2 Transmission

## (1) Transmission Procedure and Processing Flow

When 11 is written to the TR bits in EDTRR with the TE bit in ECMR set to 1 and there is empty space of 32 bytes or more in the transmit FIFO, the E-DMAC reads the descriptor following the previously used descriptor from the transmit descriptor list (or the descriptor indicated by TDLAR at the initial startup).

If the TACT bit of the read descriptor is set to 1 (valid), the E-DMAC sequentially reads transmit frame data from the transmit buffer start address specified by TD2 and transfers the data to the transmit FIFO. The E-DMAC configures a transmit frame and starts transmission to the MII. After DMA transfer of data equivalent to the buffer length specified in the descriptor, the following processing is carried out according to the TFP value.

- TFP = 10 (start of a frame) Descriptor write-back (writing 0 to the TACT bit) is performed after completion of DMA transfer.

- TFP = 01 or 11 (end of a frame) Descriptor write-back (writing 0 to the TACT bit and writing status) is performed after completion of frame transmission.

- TFP = 00 (frame continued) Descriptor write-back is not performed. The TACT bit retains the value 1.

As long as the TACT bit of a read descriptor is set to 1 (valid), the reading of E-DMAC descriptors and the transmission of frames continue.

When a descriptor with the TACT bit cleared to 0 (invalid) is read, the E-DMAC performs the following processing and completes transmit processing.

- Clears the TR bits in EDTRR to 00.

- Writes the TC bits in EESR to 11 and generates an interrupt to the CPU.

The E-DMAC can store up to four frames of data in the transmit FIFO.

When the following conditions are satisfied, the E-MAC transmit processing section reads transmit data from the transmit FIFO to configure a frame and transmits the frame to the MII.

- The amount of data in the transmit FIFO exceeds the number of bytes specified by TFTR.

- One or more frame of data is stored in the transmit FIFO.

- The transmit FIFO has no space (full of transmit wait data for the MII).

Figure 26.8 shows an example of transmission flow.

**==> picture [337 x 352] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transmission flowchart<br>Ethernet<br>This LSI + memory E-DMAC Transmit FIFO E-MAC MII<br>ETHER<br>initialization<br>Transmit<br>descriptor and<br>transmit buffer<br>setting<br>Start of transmission<br>Transmit descriptor read<br>Transmit data transfer<br>Transmit descriptor<br>write-back<br>Transmit descriptor<br>read<br>Frame transmission<br>Transmit data transfer<br>Transmit descriptor<br>write-back<br>Transmission<br>completed<br>[Legend]<br>ETHER initialization: Executes a software reset with the SWR bit in EDMR set to 1.<br>Transmit descriptor and transmit setting: Sets transmit descriptors and transmit buffer, and sets E-MAC<br>and E-DMAC registers, then writes 11 to the TE bit in ECMR<br>and the TR bit in EDTRR.<br>Start of transmission: Occurs when 1 is written to the TE bit in ECMR and 11 is written to the TR bit in EDTRR.<br>Transmit descriptor read: The E-DMAC reads a transmit descriptor.<br>Transmit data transfer : Writes transmit data to the transmit FIFO by using DMA transfer by the E-DMAC<br>Transmit descriptor write-back: The E-DMAC writes 0 to the TACT bit and writes the transmit status to the transmit descriptor.<br>**----- End of picture text -----**<br>

**Figure 26.8 Sample Transmission Flowchart (Single-Frame/Two-Description)**

Figure 26.9 shows the status change of the E-MAC transmitter.

1. When the TE bit in ECMR is set, the transmitter enters the transmit idle state.

2. The preamble is sent as soon as a transmit request is issued by the E-DMAC.

3. The transmitter sends the SFD, data, and CRC sequentially. At the end of transmission, the transmit E-DMAC generates a transmission complete interrupt (TC).

4. After waiting for the frame interval time, the transmitter enters the idle state, and if there is more transmit data, continues transmitting.

**==> picture [352 x 305] intentionally omitted <==**

**----- Start of picture text -----**<br>
TE set FDPX Start of transmission<br>Idle (preamble transmission)<br>Transmission<br>halted TE reset<br>FDPX<br>Reset<br>SFD<br>transmission<br>Error<br>Error Data<br>Error detection<br>Error transmission<br>notification<br>Error<br>Normal transmission CRC<br>transmission<br>**----- End of picture text -----**<br>

**Figure 26.9 E-MAC Transmitter State Transitions**

## (2) Transmission Error Processing

## (a) Transmission Abort

If a transmission error is detected during frame transmission from the transmit FIFO to the MII, transmission of the frame data is aborted. At this time, if DMA transfer of the appropriate frame from the transmit buffer to the transmit FIFO has not been completed, the DMA transfer is also aborted.

Following a write-back operation to the transmit descriptor related to the transmit frame aborted by a transmission error, 1 is written to the TABT bit in EESR and an interrupt is issued to the CPU. The subsequent transmit descriptors will be processed normally.

## (b) Transmit FIFO Underflow

If the transmit FIFO is empty (transmit FIFO underflow) during frame transmission from the transmit FIFO to the MII, the E-MAC forcibly aborts transmission of the frame to the MII. At this time, the frame that the E-MAC receives from the E-DMAC is cut off halfway. Then, the E-MAC performs the following operation:

- Writes the TFUF bit in EESR to 1 and generates an interrupt to the CPU.

- Performs a write-back operation to the transmit descriptor corresponding to the transmit frame.

- Following the write-back operation, writes the TUC bit in EESR and generates an interrupt to the CPU.

The subsequent transmit descriptors operate normally.

The E-MAC waits to start frame transmission from the transmit FIFO to the MII until the data that was stored in the transmit FIFO exceeds the number of the bytes specified by TFTR. Through the effective use of TFTR, the transmit FIFO underflow counts can be controlled.

## (c) Transmit Descriptor Empty

When the TFP bits of the descriptor previously processed are set to 00 or 10 and the TACT bit of the read transmit descriptor is set to 0 (invalid), a transmit descriptor empty state is determined and 1 is written to the TDE bit in EESR, and then an interrupt is issued to the CPU.

When a transmit descriptor state is empty, start transmission processing after a software reset.

## 26.4.3 Reception

## (1) Reception Procedure and Processing Flow

The E-MAC receiver separates the frame from the MII into preamble, SFD, data and CRC, and transfers the fields from DA (destination address) to the data to the receive FIFO. Up to 24 frames can be written in the receive FIFO. Figure 26.10 shows the status change of the E-MAC receiver.

1. When the RE bit in ECMR is set to 1, the receiver enters the receive idle state.

2. When an SFD (start frame delimiter) is detected after a receive packet preamble, the receiver starts receive processing. A frame with an invalid pattern is discarded.

3. In normal mode, if the destination of the frame address is this LSI, the receiver starts data reception when broadcast or multicast transmission is specified. In promiscuous mode, data reception starts regardless of the frame type.

4. Following data reception from the MII, the receiver carries out a CRC check. The result is indicated as a status bit in the descriptor after the frame data has been written to the receive FIFO. Reports an error status in the case of an abnormality.

After one frame has been received, if the RE bit in ECMR is set to 1, the receiver prepares to receive the next frame.

**==> picture [299 x 235] intentionally omitted <==**

**----- Start of picture text -----**<br>
Illegal carrier<br>detection RX-DV negation<br>Idle Start of frame Wait for SFD<br>reception reception<br>RE set Preamble<br>detection SFD<br>Reception reception<br>halted RE reset<br>Destination address<br>Promiscuous and other reception<br>Reset station destination address<br>Own destination address<br>or broadcast<br>or broadcast<br>Receive error or promiscuous<br>detection<br>Error Data<br>Error detection reception<br>notification*<br>Receive error End of reception<br>detection<br>CRC<br>Successful reception reception<br>[Legend]<br>SFD: Start frame delimiter<br>Note:  *  The error frame also transmits data to the buffer.<br>**----- End of picture text -----**<br>

**Figure 26.10 E-MAC Receiver State Transitions**

CAM evaluation can be referenced during frame processing in reception (for details on the CAM function, refer to section 26.4.4, CAM Function ).

When 1 is written to the RR bit in EDRRR while the RE bit in ECMR is set to 1, the E-DMAC reads the descriptor following the previously used descriptor from the receive descriptor list (or the descriptor indicated by RDLAR at the initial startup) then enters the receive wait state. If 32 bytes or more of data or the last byte of the receive frame is stored in the receive FIFO, the E-DMAC transfers receive FIFO data to the receive buffer specified by RD2 according to the receive descriptor with the RACT bit set to 1 (valid).

If the data length of a received frame is longer than the buffer length specified by RD1, the E-DMAC performs a writeback operation to the descriptor (set RFP to 10 or 00) when the buffer is full, then reads the next descriptor. The E- DMAC then continues to transfer data to the receive buffer specified by the new RD2.

When the following conditions are satisfied, a write-back operation is performed for the descriptor (RFP = 11 or 01), 11 is written to the FR bits in EESR, and an interrupt is issued to the CPU.

- The receive buffer has been full during DMA transfer.

- DMA transfer to the receive buffer of the last byte of the receive frame has been completed.

After the reception processing of the frame, the next descriptor reading standby state begins. At this time, if 32 bytes or more of data or the last byte of the receive frame is stored in the receive FIFO, the next receive descriptor process is performed continuously.

When the TACT bit of the read receive descriptor is 0 (invalid), the receive descriptor empty state is determined and the RDE bit in EESR is written to 1, and then an interrupt is issued to the CPU.

To receive frames continuously, set the RNC bit in RMCR to 1. The initial value is 0. Figure 26.11 shows an example of reception flow.

**==> picture [413 x 468] intentionally omitted <==**

**----- Start of picture text -----**<br>
Reception flowchart<br>Ethernet<br>This LSI + memory E-DMAC Receive FIFO E-MAC MII<br>ETHER<br>initialization<br>Receive<br>descriptor and<br>receive buffer<br>setting<br>Start of reception<br>Receive descriptor read<br>Frame reception<br>Receive data transfer<br>Receive descriptor<br>write-back<br>Reception<br>Receive descriptor read completed<br>(preparation for receiving<br>the next frame)<br>[Legend]<br>ETHER initialization: Executes a software reset with the SWR bit in EDMR set to 1.<br>Receive descriptor and receive buffer setting:<br>Sets receive descriptors and receive buffers, and sets E-MAC and E-DMAC registers,<br>then writes 1 to the RE bit in ECMR and the RR bit in EDRRR.<br>Start of Reception: Occurs when 1 is written to the RE bit in ECMR and the RR bit in EDRRR.<br>Receive descriptor read: The E-DMAC reads a receive descriptor.<br>Receive data transfer: Writes receive data from the receive FIFO to the receive buffer by using DMA transfer by the E-DMAC.<br>Receive descriptor write-back: The E-DMAC writes 0 to the RACT bit and writes the receive status to the receive descriptor<br>**----- End of picture text -----**<br>

**Figure 26.11 Sample Reception Flowchart (Single-Frame/Single-Descriptor)**

## (2) Reception Error Processing

## (a) Reception Error

When a reception error occurs, the FR and RABT bits in EESR are set to 1 and an interrupt is issued to the CPU after a write-back operation for the receive descriptor related to the reception error frame.

If a reception error occurs when the length of the frame received from the MII is less than 32 bytes, DMA transfer to the receive buffer for the frame is not performed. At this time, the receive frame is discarded in the E-DMAC (flush function). However, if padding is inserted in the receive frame by RPADIR, the flush function is performed when the frame length including the padding bytes is less than 32 bytes.

## (b) Receive FIFO Overflow

In any of the following cases, the E-MAC cannot receive frames from the MII because it has no space to store receive frames, and all the receive frames that have been transferred to the E-MAC will be discarded in the E-MAC (receive FIFO overflow).

- Receive FIFO is full of data waiting for DMA transfer (the receive FIFO has no space).

- The number of receive frames waiting for DMA transfer is 24 in total (the receive frame information managing area has no empty space; up to 24 frames can be managed).

If an overflow occurs due to the former case, the RFOF bit in EESR is set to 1 and an interrupt is generated to the CPU. If an overflow occurs due to the latter case, the RFCOF bit in EESR is set to 1 and an interrupt is generated to the CPU. Each time a receive frame is discarded due to an overflow, RMFCR is incremented. However, RMFCR is not incremented for a receive frame that is cut off due to insufficient receive FIFO space. If a receive frame is cut off due to insufficient receive FIFO space (the frame is partially stored in the receive FIFO), the E-DMAC performs the following operation:

- Performs DMA transfers for the cut-off frame stored in the receive FIFO to the receive buffer.

- After the DMA transfer, performs a write-back operation on the receive descriptor.

- After the write-back operation, sets the ROC bit in EESR to 1 and generates an interrupt to the CPU.

When the receive FIFO is full of data waiting for DMA transfer, frame reception from the MII can be resumed if DMA transfer is performed from the receive FIFO to the receive buffer and 32 bytes or more of empty space is generated in the receive FIFO. When the number of receive frames waiting for DMA transfer is 24 in total, frame reception from the MII can be resumed if one or more frame has been DMA transferred from the receive FIFO to the receive buffer. For restarting frame reception from the MII, when the E-DMAC resumes frame reception from the MII, it only accepts from the start of the frame.

## (c) Flow Control

When the amount of receive data or the number of receive frames in the receive FIFO leads to one of the following conditions, the E-DMAC notifies the E-MAC to control E-MAC writing to the receive FIFO.

- When the space used in the receive FIFO exceeds the data amount specified by FCFTR

- When the number of receive frames in the receive FIFO exceeds the value specified by FCFTR

The threshold of the receive data amount can be set in a range from 256 to 65536 bytes in 256-byte units. The threshold of receive frames can be set in a range from 1 to 24 frames (by the frame) in frame units.

## (d) Receive Descriptor Empty

When the RACT bit of the read descriptor is 0 (invalid), the receive descriptor empty state is determined and DMA transfer is stopped. Then the following operation is performed.

- Writes the RR bit in EDRRR to 0

- Sets the RDE bit in EESR to 1 and generates an interrupt to the CPU.

To resume the DMA transfer to the receive buffer, the interrupt source needs to be cleared by software, the receive descriptor needs to be re-set and the RR bit in EDRRR should be set to 1.

Even if receive descriptor is empty, frame reception from the MII to the receive FIFO is continued if there is empty space left in the receive FIFO and receive frame information management area. Therefore, even if a receive descriptor empty state is determined, the DMA transfer can be performed without discarding the frames received from the MII if DMA transfer to the receive buffer can be resumed before an overflow occurs.

## 26.4.4 CAM Function

Frames input to the E-MAC are grouped into the following four types; unicast for this LSI, broadcast, multicast, and unicast to other destinations. The MAC addresses of unicast for this LSI and broadcast are fixed, and determined only by register settings. Consequently, only multicast and unicast to other destinations determine whether to receive or not by using the CAM (unicast frames whose destination MAC addresses match this LSI are called unicast frames to this LSI, and those that do not are called unicast frames to other destinations).

Furthermore, the evaluation of reception of unicast to other destinations and multicast frames by using CAM are performed by referencing the registered MAC addresses of the CAM entry table in the TSU. By using this function, receive FIFO overflow can be prevented caused by accumulation of frame data not required for reception, and CPU processing for determining reception can be reduced.

The on-chip CAM has entry tables which can register the MAC address of 32 entries, the details of which can be set by TSU_ADRH0 to TSU_ADRH31 and TSU_ADRL0 to TSU_ADRL31. The setting to enable/disable referencing of the on-chip CAM entry table is performed by the CAM entry table enable setting register which sets whether to perform CAM evaluation or not. When on-chip CAM entry table referencing is enabled, the destination address in the frame and MAC address registered in the CAM entry table are compared, and it is determined whether to transfer the frames input to the E-MAC to E-DMAC (have E-DMAC receive the frames) or discard the frames. Table 26.4 shows the processing method of frames (receive or discard) in reception from E-MAC to E-DMAC.

**Table 26.4 Receive Frame Processing**

|**CAM Entry Table**<br>**Referencing Results**|**Types of Frame**|**Normal Mode**<br>**Promiscuous Mode**|
|---|---|---|
|||**MCT**=**0**<br>**MCT**=**1**<br>**MCT**=**0**<br>**MCT**=**1**|
|CAM hit<br>(when addresses match)|Frame to this LSI|Discarded<br>Discarded|
||Broadcast frame|Discarded<br>Discarded|
||Multicast frame|Discarded<br>Received<br>Discarded<br>Received|
||Frames having<br>destinations other than<br>this LSI|Received<br>Discarded|
|CAM mishit<br>(when addresses do not<br>match)|Frames to this LSI|Received<br>Received|
||Broadcast frame|Received<br>Received|
||Multicast frame|Received<br>Discarded<br>Received<br>Discarded|
||Frames having<br>destinations other than<br>this LSI|Discarded<br>Received|

## [Legend]

MCT (Bit 13 in ECMR): Multicast receive mode (0: Receive when CAM mishit/1: Receive when CAM hit)

## 26.4.5 Transmit Processing of Multi-Buffer Frame (Single-Frame/Multi-Descriptor)

## (1) Multi-Buffer Frame Transmit Processing

If an error occurs during multi-buffer frame transmission, the processing shown in Figure 26.12 is carried out by the E- DMAC.

In the figure where the transmit descriptor is shown as inactive (TACT bit = 0), buffer data has already been transmitted successfully, and where the transmit descriptor is shown as active (TACT bit = 1), buffer data has not been transmitted. If a frame transmit error occurs in the first descriptor part where the transmit descriptor is active (TACT bit = 1), transmission is halted, and the TACT bit is cleared to 0, immediately. The next descriptor is then read, and the position within the transmit frame is determined on the basis of bits TFP1 and TFP0 (continuing [B  00] or end [B  01]). In the case of a continuing descriptor, the TACT bit is cleared to 0, and the next descriptor is read immediately. If the descriptor is the final descriptor, not only is the TACT bit cleared to 0, but write-back is also performed to the TFE and TFS bits at the same time. Data in the buffer is not transmitted between the occurrence of an error and write-back to the final descriptor. If error interrupts are enabled in EESIPR, an interrupt is generated immediately after the final descriptor write-back.

**==> picture [370 x 219] intentionally omitted <==**

**----- Start of picture text -----**<br>
Descriptors<br>T T T T<br>A D F F Frame<br>C L P P Type<br>T E 1 0<br>0 0 1 0 Start<br>0 0 0 0 Continue<br>0 0 0 0 Continue<br>Transmit error<br>E-DMAC Inactivates TACT (change 1 to 0) 1 0 0 0 Continue occurrence<br>Descriptor read Inactivates TACT 1 0 0 0 Continue Untransmitted<br>data is not<br>Descriptor readDescriptor read Inactivates TACT 1 0 0 0 Continue transmittedafter error One frame<br>Inactivates TACT 1 0 0 0 Continue occurrence.<br>Descriptor read Descriptor is<br>Inactivates TACT 1 0 0 1 End only processed.<br>1 1 1 0 Start Buffer length set<br>by descriptor<br>Transmitted data<br>Untransmitted data<br>**----- End of picture text -----**<br>

**Figure 26.12 E-DMAC Operation after Transmit Error**

## 26.4.6 Padding Insertion in Receive Data

In the E-DMAC, one to three bytes of padding can be inserted in any byte position of receive data to improve software handling capability. By using this function, for instance, inserting 2-byte padding after the MAC header (14 bytes) of Ethernet frame enables data following the MAC header to set in 4-byte boundary.

**==> picture [268 x 379] intentionally omitted <==**

**----- Start of picture text -----**<br>
[No padding]<br>Receive buffer area<br>16-byte boundary<br>MAC header (14 bytes)<br>Padding for separation<br>16-byte boundary at 16 byte boundary<br>MAC header (14 bytes)<br>16-byte boundary<br>MAC header (14 bytes)<br>4 bytes<br>[No padding]<br>Insert 2-byte padding after 14th byte<br>Receive buffer area<br>16-byte boundary<br>MAC header (14 bytes)<br>2 bytes padding inserted<br>after MAC header<br>16-byte boundary<br>MAC header (14 bytes)<br>Padding for separation<br>16-byte boundary at 16-bytes boundary<br>MAC header (14 bytes)<br>4 bytes<br>**----- End of picture text -----**<br>

**Figure 26.13 Padding Insertion in Receive Data**

## 26.4.7 Interrupt Processing

## (1) Interrupt Sources

The ETHER issues one type of interrupt to the CPU: receive/transmit interrupts (ETHERI). ETHERI interrupts are generated in correspondence with the transmit/receive operation. When an interrupt source is generated, it is set in EESR0 and an interrupt is issued to the CPU. For some interrupt sources, the EESR0 setting and an interrupt to the CPU are performed after a write-back operation to a descriptor is completed, not immediately after the interrupt source is detected. Interrupt sources other than the E-MAC status register source (ECI bit) are cleared by writing a 1 to the corresponding source bit. The E-MAC status register source (ECI bit) is cleared by writing a 1 to the corresponding source bit in ECSR. Interrupt source bits retain the values until they are cleared. ETHERI interrupt source is allowed to issue interrupts by setting the corresponding bit in EESIPR0. Each E-MAC state register source (ECI bit) is allowed to issue an interrupt by setting the corresponding bit in ECSIPR. In the initial value, interrupts are disabled. Table 26.5 shows these three interrupts, interrupt sources, interrupt status registers and bits set at interrupt occurrence and interrupt generation timing.

## **Table 26.5 List of ETHER Interrupts**

|**Interrupt**|**Interrupt Source**<br>**Register and Bit**<br>**Interrupt Generation Timing**|
|---|---|
|Transmit/<br>receive interrupt<br>(ETHERI)|Write-back completed<br>EESR0.TWB<br>After write-back|
||Transmit underflow frame write-back completed<br>EESR0.TUC<br>After write-back|
||Receive underflow frame write-back completed<br>EESR0.ROC<br>After write-back|
||Transmission abort detection<br>EESR0.TABT<br>After write-back|
||Reception abort detection<br>EESR0.RABT<br>After write-back|
||Receive frame counter overflow<br>EESR0.RFCOF<br>When the interrupt source is detected|
||E-MAC status register source<br>EESR0.ECI<br>When the interrupt source is detected|
||Frame transmission completed<br>EESR0.TC<br>After write-back|
||Transmit descriptor empty<br>EESR0.TDE<br>When the interrupt source is detected|
||Transmit FIFO underflow<br>EESR0.TFUF<br>When the interrupt source is detected|
||Frame reception<br>EESR0.FR<br>After write-back|
||Receive descriptor empty<br>EESR0.RDE<br>When the interrupt source is detected|
||Receive FIFO overflow<br>EESR0.RFOF<br>When the interrupt source is detected|
||Receive Multicast Address Frame<br>EESR0.RMAF<br>After write-back|
||Receive Residual-Bit Frame<br>EESR0.RRF<br>After write-back|
||Receive Too-Long Frame<br>EESR0.RTLF<br>After write-back|
||Receive Too-Short Frame<br>EESR0.RTSF<br>After write-back|
||PHY-LSI Receive Error<br>EESR0.PRE<br>After write-back|
||CRC Error on Received Frame<br>EESR0.CERF<br>After write-back|

## 26.4.8 Activation Procedure

The ETHER should be activated by the following procedure:

## (1) Reset

1. Perform a power-on reset.

2. Set the ET_TXCLK and ET_RXCLK pins and supply the clock signal (for details on pin function settings, see section 41, Ports ).

3. Start the E-DMAC transmitter and receiver (activation of descriptor engine). —Set ENT to 1 and ENR to 1 in EDSR.

4. Perform a software reset. —Set SWRR to 1 and SWRT to 1 in EDMR simultaneously.

5. Initialize the descriptor entry table.

6. Confirm cancellation of the software reset.

   - —Check that the SWRR and SWRT bits in EDMR are cleared to 0.

## (2) Pin Settings

See section 41, Ports .

## (3) Registration of Descriptor Ring

The address of a descriptor ring configured in memory is registered in the descriptor entry table.

1. Transmit descriptor setting —Set TDLAR.

   - —Set TDFAR.

   - —Set TDFXR.

—Set TDFFR. When the descriptor indicated by TDFXR is the last descriptor in the descriptor list, set H'00000001.

2. Receive descriptor setting —Set RDLAR.

   - —Set RDFAR.

   - —Set RDFXR.

   - —Set RDFFR. When the descriptor indicated by RDFXR is the last descriptor in the descriptor list, set H'00000001.

## (4) Register Settings

The following registers should be set as necessary.

1. E-DMAC related registers

   - —Set EDMR: Operating mode, etc.

   - —Set EESIPR: Interrupt masks

   - —Set TRSCER: Error masks

   - —Set TFTR: Transmit FIFO threshold

   - —Set FDR: External FIFO size

   - —Set RMCR: Reset method for reception activation

   - —Set RPADIR: Padding insertion into receive data

   - —Set FCFTR: Receive BSY output threshold

2. E-MAC related registers —Set ECMR setting: Transmission/reception specifications

   - —Set ECSIPR setting: Interrupt masks

   - —Set MAHR: MAC address

   - —Set MALR: MAC address

—Set RFLR: Maximum receive frame length

—Set APR: TIME parameter value of an automatic pause frame

—Set MPR: TIME parameter value of a manual PAUSE frame

—Set TPAUSER: Upper limit of automatic PAUSE frame retransmission

## (5) Activation

1. Start the E-DMAC transmission/reception function

   - —Set the TR bits in EDTRR to 11.

   - —Set the RR bit in EDRRR to 1.

2. Start the E-MAC transmission/reception function

   - —Set the TE and RE bits in ECMR to 1.

## 26.4.9 Flow Control

The ETHER supports flow control functions conforming to IEEE802.3x for full-duplex operation. The flow control can be applied to both receive and transmit operations. When transmitting PAUSE frames, flow control can be performed by the following two procedures:

## (1) Automatic PAUSE Frame Transmission

For receive frames, PAUSE frames are automatically transmitted when the number of data written to the receive FIFO reaches the value set in FCFTR. The TIME parameter included in the PAUSE frame is set by APR. The automatic PAUSE frame transmission is repeated until the number of data in the receive FIFO becomes less than the value set in FCFTR as the receive data is read from the FIFO. Using TPAUSER, the upper limit of retransmission counts of the PAUSE frames can also be set in the range from 1 to 65535. In this case, PAUSE frame transmission is repeated until the number of receive FIFO data becomes less than the FCFTR value, or the number of transmits reaches the value set by TPAUSER. The transmission counter is cleared to 0 when the next PAUSE frame is transmitted after the number of data in the receive FIFO becomes less than the FCFTR value.

The automatic PAUSE frame transmission is enabled when the TXF bit in ECMR is 1.

## (2) Manual PAUSE Frame Transmission

PAUSE frames are transmitted by directives from the software. When writing the Timer value to MPR, manual PAUSE frame transmission is started. With this method, PAUSE frame transmission is carried out only once.

## (3) PAUSE Frame Reception

The next frame is not transmitted until the time indicated by the Timer value elapses after receiving a PAUSE frame. However, the transmission of the current frame is continued. A received PAUSE frame is valid only when the RXF bit in ECMR is set to 1. The number of times of PAUSE frame receptions is counted.

## (4) 0-Time PAUSE Frame Control

Flow control is performed using a PAUSE frame with the TIME parameter value set to 0. The PAUSE frame with the TIME parameter set to 0 can be enabled or disabled by the ZPF bit in ECMR.

- When PAUSE frame control with the TIME parameter value set to 0 is enabled

   - A PAUSE frame with the TIME parameter value set to 0 is transmitted when the number of data in the receive FIFO is less than the FCFTR value before the time indicated by the TIME parameter value has not elapsed. When a PAUSE frame with the time indicated by the TIME parameter value set to 0 is received, the transmit standby state is canceled.

- When PAUSE frame control with the TIME parameter value set to 0 is disabled A PAUSE frame with the TIME parameter value set to 0 is not transmitted. When a PAUSE frame with the TIME parameter value set to 0 is received, the PAUSE frame is discarded.

## 26.4.10 Intelligent Checksum Calculation Function

This function accelerates checksum calculation on received packets, and provides the following two modes.

- MAC/IP packet analyzing intelligent checksum calculation mode

- All-data intelligent checksum calculation mode with bytes to be skipped specified

## (1) MAC/IP Packet Analyzing Intelligent Checksum Calculation Mode (CSEBL = 1 and CSMD = 1 in CSMR)

In this mode, the checksum of received packets indicated in the table is calculated. However, if a MAC packet payload includes padding data in fields other than those for the IP packet itself because there is too little data for a full packet, it is not included in the checksum.

|**IPver**|**Items**|
|---|---|
|IPv4|Option present|
||Option not present|
||Fragment*1|
|IPv6|Extension header not present|
||Hop-by-hop options extension header length|
||Routing extension header length|
||Fragment extension header length*1|
||Destination options header length|
||AH extension header length|
||ESP extension header length*2|
||Extension header length for mobile IPv6*2|

Note 1. This packet is to be checksumed, however, the RCS[15:0] bits and RCSE bit in RD0 are to be undefined even if the data is successfully received.

Note 2. The RD0.RCSE bit is set to 1 without calculating the value of the RD0.RCS[15:0] bits.

The shaded regions of the following figure indicate the parts of an IPv4 packet which are used to obtain the checksum.

**==> picture [275 x 160] intentionally omitted <==**

**----- Start of picture text -----**<br>
No. 31 16 15 11 8 7 0<br>0<br>1<br>2<br>3 IPv4/IPv6/others IHL*<br>4 Packet length<br>5<br>6 Transmission IP address<br>7 Transmission IP address Reception IP address<br>8 Reception IP address<br>9 Options will not be included in the checksum calculation.<br>10<br>Data<br>Note:  *  After conversion to octet units, this is subtracted in the checksum calculation.<br>              In the calculation: {8'h00, protocol no.[7:0]}<br>**----- End of picture text -----**<br>

The shaded regions of the following figure indicate the parts of an IPv6 packet which are used to obtain the checksum.

**==> picture [275 x 214] intentionally omitted <==**

**----- Start of picture text -----**<br>
No. 31 16 15 0<br>0<br>1<br>2<br>3 IPv4/IPv6/others<br>4 Payload length<br>5 Subsequent header* [1] Transmission IP address<br>6 Transmission IP address<br>7 Transmission IP address<br>8 Transmission IP address<br>9 Transmission IP address Reception IP address<br>10 Reception IP address<br>11 Reception IP address<br>12 Reception IP address<br>13 Reception IP address Subsequent header* [1] Header length* [2]<br>Contents of the extension header are not included in the checksum.<br>Data<br>Notes:  *1 Only included in the checksum when the header is for the TCP or UDP.<br>Calculation coverage is extended to {8'h00, protocol No.[7:0]} when the<br>checksum is taken.<br>*2 After conversion to octet units, this is subtracted in the checksum calculation.<br>**----- End of picture text -----**<br>

## (2) All-Data Intelligent Checksum Calculation Mode with Bytes to be Skipped Specified (CSELB = 1 and CSMD = 0 in CSMR)

After having skipped the number of bytes specified in the SB[5:0] bits in CSMR, counting from the beginning of the packet, the checksum is calculated for all subsequent data (e.g. 14 bytes may be skipped).

**==> picture [160 x 118] intentionally omitted <==**

**----- Start of picture text -----**<br>
No. 31 16 15 0<br>0<br>1 SB[5:0] = H'0E<br>2<br>3<br>4<br>5<br>6<br>7 Data<br>8<br>9<br>10<br>11<br>**----- End of picture text -----**<br>

## 26.5 Connection to PHY-LSI

## 26.5.1 MII Frame Transmission/Reception Timing

Each MII frame transmission/reception timing is shown in Figure 26.14 to Figure 26.17 .

**==> picture [336 x 76] intentionally omitted <==**

**----- Start of picture text -----**<br>
TXCLK<br>TXEN<br>Preamble SFD Data CRC<br>TXD[3:0]<br>TXER<br>**----- End of picture text -----**<br>

**Figure 26.14 MII Frame Transmit Timing (Normal Transmission)**

**==> picture [336 x 72] intentionally omitted <==**

**----- Start of picture text -----**<br>
RXCLK<br>RXDV<br>Preamble SFD Data CRC<br>RXD[3:0]<br>RXER<br>**----- End of picture text -----**<br>

**Figure 26.15 MII Frame Receive Timing (Normal Reception)**

**==> picture [337 x 73] intentionally omitted <==**

**----- Start of picture text -----**<br>
RXCLK<br>RXDV<br>Preamble SFD Data XXXX<br>RXD[3:0]<br>RXER<br>**----- End of picture text -----**<br>

**Figure 26.16 MII Frame Receive Timing (Reception Error (1))**

**==> picture [338 x 72] intentionally omitted <==**

**----- Start of picture text -----**<br>
RXCLK<br>RXDV<br>RXD[3:0] XXXX 1110 XXXX<br>RXER<br>**----- End of picture text -----**<br>

**Figure 26.17 MII Frame Receive Timing (Reception Error (2))**

## 26.5.2 Accessing MII Registers

MII registers in the PHY-LSI are accessed via PIR in this LSI. PIR is used as a serial interface conforming to the MII frame format specified in IEEE802.3u.

## (1) MII Management Frame Format

Figure 26.18 shows the format of an MII management frame. To access an MII register, a management frame is implemented by the program in accordance with the procedures shown in MII Register Access Procedure.

|Access Type<br>MII Management Frame<br>Item<br>Number of bits<br>Read<br>Write<br>PRE<br>32<br>1..1<br>1..1<br>ST<br>2<br>01<br>01<br>OP<br>2<br>10<br>01<br>PHYAD<br>5<br>00001<br>00001<br>REGAD<br>5<br>RRRRR<br>RRRRR<br>TA<br>2<br>Z0<br>10<br>DATA<br>16<br>D..D<br>D..D<br>IDLE<br>X<br>PRE:<br>ST:<br>OP:<br>PHYAD:<br>REGAD:<br>TA:<br>DATA:<br>IDLE:<br>32 consecutive 1s<br>Write of 01 indicating start of frame<br>Write of code indicating access type<br>Write of 0001 if the PHY-LSI address is 1 (sequential write starting with the MSB).<br>This bit changes depending on the PHY-LSI address.<br>Write of 000q if the register address is 1 (sequential write starting with the MSB).<br>This bit changes depending on the PHY-LSI register address.<br>Time for switching data transmission source on MII interface<br>(a) Write: 10 written<br>(b) Read: Bus release (notation: Z0) performed<br>16-bit data. Sequential write or read from MSB<br>(a) Write: 16-bit data write<br>(b) Read: 16-bit data read<br>Wait time until next MII management format input<br>(a) Write: Independent bus release (notation: X) performed<br>(d) Read: Bus already released in TA: control unnecessary<br>[Legend]|Access Type|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|MII Management Frame|
|---|---|---|---|---|---|---|---|---|---|
||Item|PRE|ST|OP|PHYAD|REGAD|TA|DATA|IDLE|
||Number of bits|32|2|2|5|5|2|16||
||Read|1..1|01|10|00001|RRRRR|Z0|D..D||
||Write|1..1|01|01|00001|RRRRR|10|D..D|X|

**Figure 26.18 MII Management Frame Format**

## (2) MII Register Access Procedure

The program accesses MII registers via PIR. Access is implemented by a combination of 1-bit-unit data write, 1-bit-unit data read, bus release, and independent bus release. Figure 26.19 (1) to Figure 26.22 (4) show the MII register access timing. The timing will differ depending on the PHY-LSI type.

**==> picture [289 x 196] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) Write to PHY interface<br>register<br>ET_MDC<br>PIR.MMD = 1<br>PIR.MDO = write data<br>PIR.MDC = 0 ET_MDIO<br>(2) Write to PHY interface<br>register (1) (2) (3)<br>PIR.MMD = 1 1-bit data write timing<br>PIR.MDO = write data relationship<br>PIR.MDC = 1<br>(3) Write to PHY interface<br>register<br>PIR.MMD = 1<br>PIR.MDO = write data<br>PIR.MDC = 0<br>**----- End of picture text -----**<br>

**Figure 26.19 1-Bit Data Write Flowchart**

**==> picture [289 x 171] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) Write to PHY interface<br>register<br>ET_MDC<br>PIR.MMD = 0<br>PIR.MDC = 0<br>ET_MDIO<br>(2) Write to PHY interface<br>register<br>(1) (2) (3)<br>PIR.MMD = 0<br>PIR.MDC = 1<br>Bus release timing<br>relationship<br>(3) Write to PHY interface<br>register<br>PIR.MMD = 0<br>PIR.MDC = 1<br>**----- End of picture text -----**<br>

**Figure 26.20 Bus Release Flowchart (TA in Read in Figure 26.18)**

**==> picture [289 x 178] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) Write to PHY interface<br>register<br>PIR.MMD = 0 ET_MDC<br>PIR.MDC = 1<br>ET_MDIO<br>(2) Read from PHY<br>interface register<br>PIR.MMD = 0 (1) (2) (3)<br>PIR.MDC = 1<br>1-bit data read timing<br>PIR.MDI is read data relationship<br>(2) Write to PHY interface<br>register<br>PIR.MMD = 0<br>PIR.MDC = 0<br>**----- End of picture text -----**<br>

**Figure 26.21 1-Bit Data Read Flowchart**

**==> picture [267 x 117] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) Write to PHY interface<br>register<br>ET_MDC<br>PIR.MMD = 0<br>PIR.MDC = 0<br>ET_MDIO<br>(1)<br>Independent bus release<br>timing relationship<br>**----- End of picture text -----**<br>

**Figure 26.22 Independent Bus Release Flowchart (IDLE in Write in Figure 26.18)**

## 26.6 Usage Notes

## 26.6.1 Checksum Calculation of Ethernet Frames

This LSI is capable of calculating the checksum data of the received frames. Only the data fields of the Ethernet frames are subject to checksum calculation. Specifically, a data field follows the length/type field and is followed by the CRC field. Figure 26.23 shows schematics indicating which parts of the Ethernet frames are calculated. Calculation involves 16-bit addition only; it does not involve bit inversion. Note that when the checksum data is valid, the CRC data (4 bytes) is not transferred as a receive frame, and the checksum data (sum data) is added automatically. Figure 26.24 shows schematics of Ethernet frames to which the checksum data has been added.

Note: • Also for the frames with VLANtag inserted, the 15th byte from the top and the following bytes before the CRC field are subject to calculation.

**==> picture [308 x 173] intentionally omitted <==**

**----- Start of picture text -----**<br>
Destination address Destination address<br>(6 bytes) (6 bytes)<br>Source address Source address<br>(6 bytes) (6 bytes)<br>Type (2 bytes) VLANtag<br>(4 bytes)<br>Type (2 bytes)<br>Data subject to Data subject to<br>Data (46 to 1500 bytes) checksum checksum<br>calculation Data (42 to 1500 bytes) calculation<br>CRC (4 bytes) CRC (4 bytes)<br>Schematic of an Ethernet frame Schematic of an Ethernet frame<br>(without VLANtag) (with VLANtag)<br>**----- End of picture text -----**<br>

**Figure 26.23 Data Subject to Checksum Calculation**

**==> picture [249 x 170] intentionally omitted <==**

**----- Start of picture text -----**<br>
Destination address Destination address<br>(6 bytes) (6 bytes)<br>Source address Source address<br>(6 bytes) (6 bytes)<br>Type (2 bytes) VLANtag<br>(4 bytes)<br>Type (2 bytes)<br>Data (46 to 1500 bytes)<br>Data (42 to 1500 bytes)<br>Sum data Sum data<br>(2 bytes) (2 bytes)<br>Schematic of an Ethernet frame Schematic of an Ethernet frame<br>(without VLANtag) (with VLANtag)<br>**----- End of picture text -----**<br>

**Figure 26.24 Data after Checksum Data Addition**

## 26.6.2 Notes on Using the Intelligent Checksum Function

Checksum calculation using the intelligent checksum function is not affected by padding insertion specified by the receive data padding insert register (RPADIR). This is because checksum calculation is performed when transferring receive data from E-MAC to E-DMAC, while padding of receive data is performed when transferring receive data from E-DMAC to the receive buffer in memory.

## 26.6.3 Software Reset

For transitions to the software reset state by the ARST bit in the software reset register (ARSTR) or SWRT and SWRR bits in the E-DMAC mode register (EDMR0), see section 42.3.6, Software Reset . However, where the procedure refers to the SRST bit, read this as the ARST bit or SWRT and SWRR bits.
