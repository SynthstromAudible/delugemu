# 7. Interrupt Controller

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 137–177. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

The interrupt controller ascertains the priority of interrupt sources and controls interrupt requests to the CPU. The interrupt controller registers set the order of priority of each interrupt, allowing the user to process interrupt requests according to the user-set priority.

## 7.1 Features

- 32 levels of interrupt priority can be set.

   - By setting the interrupt priority registers, the priorities of IRQ interrupts, on-chip peripheral module interrupts, and pin interrupts can be selected from 32 levels for request sources.

- NMI noise canceler function

   - An NMI input-level bit indicates the NMI pin state. By reading this bit in the interrupt exception service routine, the pin state can be checked, enabling it to be used as the noise canceler function.

- Arm PrimeCell[®] generic interrupt controller (PL390)*

Note: * The PL390 supports version 1 of the specification for the architecture of the Arm generic interrupt controller (GIC).

Figure 7.1 shows a block diagram.

**==> picture [333 x 328] intentionally omitted <==**

**----- Start of picture text -----**<br>
Peripheral bus AXI bus<br>Interrupt request<br>NMI<br>Input GIC CPU<br>control<br>IRQ7 to IRQ0<br>Direct memory access controller (Interrupt request)<br>USB 2.0 host/function module (Interrupt request)<br>Video display controller 5 (Interrupt request)<br>JPEG code unit (RZ/A1LU only) (Interrupt request)<br>OS timer (Interrupt request)<br>Bus state controller (Interrupt request)<br>Watchdog timer (Interrupt request)<br>Multi-function timer pulse unit 2 (Interrupt request)<br>12-bit A/D converter (Interrupt request) Priority<br>Serial sound interface (Interrupt request) identifier<br>Renesas SPDIF interface (Interrupt request)<br>I [2] C bus interface (Interrupt request)<br>Serial communication interface with FIFO (Interrupt request)<br>CAN interface (Interrupt request)<br>Renesas serial peripheral interface (Interrupt request)<br>IEBus [TM]  controller (RZ/A1L only) (Interrupt request)<br>CD-ROM decoder (RZ/A1L only) (Interrupt request)<br>MMC host interface (Interrupt request)<br>SD host interface (Interrupt request)<br>Realtime clock (Interrupt request)<br>SCUX (Interrupt request)<br>Media local bus (RZ/A1L only) (Interrupt request)<br>LIN interface (RZ/A1L only) (Interrupt request)<br>Serial communication interface (Interrupt request)<br>EthernetAVB (RZ/A1LU only) (Interrupt request)<br>Ethernet controller (Interrupt request)<br>Capture engine unit (Interrupt request)<br>On-chip RAM (Interrupt request)<br>Internal bus (Interrupt request)<br>Pin interrupts<br>TINT121 to TINT0<br>INTC<br>**----- End of picture text -----**<br>

**Figure 7.1 Block Diagram**

## 7.2 Input/Output Pins

Table 7.1 shows the pin configuration.

## **Table 7.1 Pin Configuration**

|**Table 7.1**<br>**Pin Configuration**||
|---|---|
|**Pin Name**|**Symbol**<br>**I/O**<br>**Function**|
|Nonmaskable interrupt input pin|NMI<br>Input<br>Input of nonmaskable interrupt request signal|
|Interrupt request input pins|IRQ7 to IRQ0<br>Input<br>Input of maskable interrupt request signals|
||TINT121 to TINT0<br>Input<br>Input of maskable interrupt request signals|

## 7.3 Register Descriptions

Table 7.2 shows the register configuration. These registers are used to set the interrupt priorities and control detection of the external interrupt input signal.

For a description of the registers other than interrupt control register 0, interrupt control register 1, and IRQ interrupt request register, see the Arm Generic Interrupt Controller Architecture Specification and the PrimeCell[®] Generic Interrupt Controller (PL390) Technical Reference Manual from Arm.

**Table 7.2 Register Configuration**

|**Table 7.2**<br>**Register Configuration**||||||
|---|---|---|---|---|---|
||||||**Access**|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt control register 0|ICR0|R/W|*1|H'FCFEF800|16|
|Interrupt control register 1|ICR1|R/W|H'0000|H'FCFEF802|16|
|IRQ interrupt request register|IRQRR|R/(W)*2|H'0000|H'FCFEF804|16|
|Distributor control register|ICDDCR|RW|H'00000000|H'E8201000|32|
|Interrupt controller type register|ICDICTR|R|H'0000FC31*3|H'E8201004|32|
|Distributor implementer identification register|ICDIIDR|R|H'0000043B|H'E8201008|32|
|Interrupt security register 0|ICDISR0|R/W|H'00000000|H'E8201080|32|
|Interrupt security register 1|ICDISR1|R/W|H'00000000|H'E8201084|32|
|Interrupt security register 2|ICDISR2|R/W|H'00000000|H'E8201088|32|
|Interrupt security register 3|ICDISR3|R/W|H'00000000|H'E820108C|32|
|Interrupt security register 4|ICDISR4|R/W|H'00000000|H'E8201090|32|
|Interrupt security register 5|ICDISR5|R/W|H'00000000|H'E8201094|32|
|Interrupt security register 6|ICDISR6|R/W|H'00000000|H'E8201098|32|
|Interrupt security register 7|ICDISR7|R/W|H'00000000|H'E820109C|32|
|Interrupt security register 8|ICDISR8|R/W|H'00000000|H'E82010A0|32|
|Interrupt security register 9|ICDISR9|R/W|H'00000000|H'E82010A4|32|
|Interrupt security register 10|ICDISR10|R/W|H'00000000|H'E82010A8|32|
|Interrupt security register 11|ICDISR11|R/W|H'00000000|H'E82010AC|32|
|Interrupt security register 12|ICDISR12|R/W|H'00000000|H'E82010B0|32|
|Interrupt security register 13|ICDISR13|R/W|H'00000000|H'E82010B4|32|
|Interrupt security register 14|ICDISR14|R/W|H'00000000|H'E82010B8|32|
|Interrupt security register 15|ICDISR15|R/W|H'00000000|H'E82010BC|32|
|Interrupt security register 16|ICDISR16|R/W|H'00000000|H'E82010C0|32|
|Interrupt set-enable register 0|ICDISER0|R/W|H'00000000|H'E8201100|32|
|Interrupt set-enable register 1|ICDISER1|R/W|H'00000000|H'E8201104|32|
|Interrupt set-enable register 2|ICDISER2|R/W|H'00000000|H'E8201108|32|
|Interrupt set-enable register 3|ICDISER3|R/W|H'00000000|H'E820110C|32|
|Interrupt set-enable register 4|ICDISER4|R/W|H'00000000|H'E8201110|32|
|Interrupt set-enable register 5|ICDISER5|R/W|H'00000000|H'E8201114|32|
|Interrupt set-enable register 6|ICDISER6|R/W|H'00000000|H'E8201118|32|
|Interrupt set-enable register 7|ICDISER7|R/W|H'00000000|H'E820111C|32|
|Interrupt set-enable register 8|ICDISER8|R/W|H'00000000|H'E8201120|32|
|Interrupt set-enable register 9|ICDISER9|R/W|H'00000000|H'E8201124|32|
|Interrupt set-enable register 10|ICDISER10|R/W|H'00000000|H'E8201128|32|
|Interrupt set-enable register 11|ICDISER11|R/W|H'00000000|H'E820112C|32|
|Interrupt set-enable register 12|ICDISER12|R/W|H'00000000|H'E8201130|32|
|Interrupt set-enable register 13|ICDISER13|R/W|H'00000000|H'E8201134|32|
|Interrupt set-enable register 14|ICDISER14|R/W|H'00000000|H'E8201138|32|

**Table 7.2 Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt set-enable register 15|ICDISER15|R/W|H'00000000|H'E820113C|32|
|Interrupt set-enable register 16|ICDISER16|R/W|H'00000000|H'E8201140|32|
|Interrupt clear-enable register 0|ICDICER0|R/W|H'00000000|H'E8201180|32|
|Interrupt clear-enable register 1|ICDICER1|R/W|H'00000000|H'E8201184|32|
|Interrupt clear-enable register 2|ICDICER2|R/W|H'00000000|H'E8201188|32|
|Interrupt clear-enable register 3|ICDICER3|R/W|H'00000000|H'E820118C|32|
|Interrupt clear-enable register 4|ICDICER4|R/W|H'00000000|H'E8201190|32|
|Interrupt clear-enable register 5|ICDICER5|R/W|H'00000000|H'E8201194|32|
|Interrupt clear-enable register 6|ICDICER6|R/W|H'00000000|H'E8201198|32|
|Interrupt clear-enable register 7|ICDICER7|R/W|H'00000000|H'E820119C|32|
|Interrupt clear-enable register 8|ICDICER8|R/W|H'00000000|H'E82011A0|32|
|Interrupt clear-enable register 9|ICDICER9|R/W|H'00000000|H'E82011A4|32|
|Interrupt clear-enable register 10|ICDICER10|R/W|H'00000000|H'E82011A8|32|
|Interrupt clear-enable register 11|ICDICER11|R/W|H'00000000|H'E82011AC|32|
|Interrupt clear-enable register 12|ICDICER12|R/W|H'00000000|H'E82011B0|32|
|Interrupt clear-enable register 13|ICDICER13|R/W|H'00000000|H'E82011B4|32|
|Interrupt clear-enable register 14|ICDICER14|R/W|H'00000000|H'E82011B8|32|
|Interrupt clear-enable register 15|ICDICER15|R/W|H'00000000|H'E82011BC|32|
|Interrupt clear-enable register 16|ICDICER16|R/W|H'00000000|H'E82011C0|32|
|Interrupt set-pending register 0|ICDISPR0|R/W|H'00000000|H'E8201200|32|
|Interrupt set-pending register 1|ICDISPR1|R/W|H'00000000|H'E8201204|32|
|Interrupt set-pending register 2|ICDISPR2|R/W|H'00000000|H'E8201208|32|
|Interrupt set-pending register 3|ICDISPR3|R/W|H'00000000|H'E820120C|32|
|Interrupt set-pending register 4|ICDISPR4|R/W|H'00000000|H'E8201210|32|
|Interrupt set-pending register 5|ICDISPR5|R/W|H'00000000|H'E8201214|32|
|Interrupt set-pending register 6|ICDISPR6|R/W|H'00000000|H'E8201218|32|
|Interrupt set-pending register 7|ICDISPR7|R/W|H'00000000|H'E820121C|32|
|Interrupt set-pending register 8|ICDISPR8|R/W|H'00000000|H'E8201220|32|
|Interrupt set-pending register 9|ICDISPR9|R/W|H'00000000|H'E8201224|32|
|Interrupt set-pending register 10|ICDISPR10|R/W|H'00000000|H'E8201228|32|
|Interrupt set-pending register 11|ICDISPR11|R/W|H'00000000|H'E820122C|32|
|Interrupt set-pending register 12|ICDISPR12|R/W|H'00000000|H'E8201230|32|
|Interrupt set-pending register 13|ICDISPR13|R/W|H'00000000|H'E8201234|32|
|Interrupt set-pending register 14|ICDISPR14|R/W|H'00000000|H'E8201238|32|
|Interrupt set-pending register 15|ICDISPR15|R/W|H'00000000|H'E820123C|32|
|Interrupt set-pending register 16|ICDISPR16|R/W|H'00000000|H'E8201240|32|
|Interrupt clear-pending register 0|ICDICPR0|R/W|H'00000000|H'E8201280|32|
|Interrupt clear-pending register 1|ICDICPR1|R/W|H'00000000|H'E8201284|32|
|Interrupt clear-pending register 2|ICDICPR2|R/W|H'00000000|H'E8201288|32|
|Interrupt clear-pending register 3|ICDICPR3|R/W|H'00000000|H'E820128C|32|
|Interrupt clear-pending register 4|ICDICPR4|R/W|H'00000000|H'E8201290|32|
|Interrupt clear-pending register 5|ICDICPR5|R/W|H'00000000|H'E8201294|32|
|Interrupt clear-pending register 6|ICDICPR6|R/W|H'00000000|H'E8201298|32|
|Interrupt clear-pending register 7|ICDICPR7|R/W|H'00000000|H'E820129C|32|
|Interrupt clear-pending register 8|ICDICPR8|R/W|H'00000000|H'E82012A0|32|

**Table 7.2 Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt clear-pending register 9|ICDICPR9|R/W|H'00000000|H'E82012A4|32|
|Interrupt clear-pending register 10|ICDICPR10|R/W|H'00000000|H'E82012A8|32|
|Interrupt clear-pending register 11|ICDICPR11|R/W|H'00000000|H'E82012AC|32|
|Interrupt clear-pending register 12|ICDICPR12|R/W|H'00000000|H'E82012B0|32|
|Interrupt clear-pending register 13|ICDICPR13|R/W|H'00000000|H'E82012B4|32|
|Interrupt clear-pending register 14|ICDICPR14|R/W|H'00000000|H'E82012B8|32|
|Interrupt clear-pending register 15|ICDICPR15|R/W|H'00000000|H'E82012BC|32|
|Interrupt clear-pending register 16|ICDICPR16|R/W|H'00000000|H'E82012C0|32|
|Active bit register 0|ICDABR0|R/W|H'00000000|H'E8201300|32|
|Active bit register 1|ICDABR1|R/W|H'00000000|H'E8201304|32|
|Active bit register 2|ICDABR2|R/W|H'00000000|H'E8201308|32|
|Active bit register 3|ICDABR3|R/W|H'00000000|H'E820130C|32|
|Active bit register 4|ICDABR4|R/W|H'00000000|H'E8201310|32|
|Active bit register 5|ICDABR5|R/W|H'00000000|H'E8201314|32|
|Active bit register 6|ICDABR6|R/W|H'00000000|H'E8201318|32|
|Active bit register 7|ICDABR7|R/W|H'00000000|H'E820131C|32|
|Active bit register 8|ICDABR8|R/W|H'00000000|H'E8201320|32|
|Active bit register 9|ICDABR9|R/W|H'00000000|H'E8201324|32|
|Active bit register 10|ICDABR10|R/W|H'00000000|H'E8201328|32|
|Active bit register 11|ICDABR11|R/W|H'00000000|H'E820132C|32|
|Active bit register 12|ICDABR12|R/W|H'00000000|H'E8201330|32|
|Active bit register 13|ICDABR13|R/W|H'00000000|H'E8201334|32|
|Active bit register 14|ICDABR14|R/W|H'00000000|H'E8201338|32|
|Active bit register 15|ICDABR15|R/W|H'00000000|H'E820133C|32|
|Active bit register 16|ICDABR16|R/W|H'00000000|H'E8201340|32|
|Interrupt priority register 0|ICDIPR0|R/W|H'00000000|H'E8201400|32|
|Interrupt priority register 1|ICDIPR1|R/W|H'00000000|H'E8201404|32|
|Interrupt priority register 2|ICDIPR2|R/W|H'00000000|H'E8201408|32|
|Interrupt priority register 3|ICDIPR3|R/W|H'00000000|H'E820140C|32|
|Interrupt priority register 4|ICDIPR4|R/W|H'00000000|H'E8201410|32|
|Interrupt priority register 5|ICDIPR5|R/W|H'00000000|H'E8201414|32|
|Interrupt priority register 6|ICDIPR6|R/W|H'00000000|H'E8201418|32|
|Interrupt priority register 7|ICDIPR7|R/W|H'00000000|H'E820141C|32|
|Interrupt priority register 8|ICDIPR8|R/W|H'00000000|H'E8201420|32|
|Interrupt priority register 9|ICDIPR9|R/W|H'00000000|H'E8201424|32|
|Interrupt priority register 10|ICDIPR10|R/W|H'00000000|H'E8201428|32|
|Interrupt priority register 11|ICDIPR11|R/W|H'00000000|H'E820142C|32|
|Interrupt priority register 12|ICDIPR12|R/W|H'00000000|H'E8201430|32|
|Interrupt priority register 13|ICDIPR13|R/W|H'00000000|H'E8201434|32|
|Interrupt priority register 14|ICDIPR14|R/W|H'00000000|H'E8201438|32|
|Interrupt priority register 15|ICDIPR15|R/W|H'00000000|H'E820143C|32|
|Interrupt priority register 16|ICDIPR16|R/W|H'00000000|H'E8201440|32|
|Interrupt priority register 17|ICDIPR17|R/W|H'00000000|H'E8201444|32|
|Interrupt priority register 18|ICDIPR18|R/W|H'00000000|H'E8201448|32|
|Interrupt priority register 19|ICDIPR19|R/W|H'00000000|H'E820144C|32|

**Table 7.2 Register Configuration**

|||||||**Access**|
|---|---|---|---|---|---|---|
|**Register Name**||**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt priority register|20|ICDIPR20|R/W|H'00000000|H'E8201450|32|
|Interrupt priority register|21|ICDIPR21|R/W|H'00000000|H'E8201454|32|
|Interrupt priority register|22|ICDIPR22|R/W|H'00000000|H'E8201458|32|
|Interrupt priority register|23|ICDIPR23|R/W|H'00000000|H'E820145C|32|
|Interrupt priority register|24|ICDIPR24|R/W|H'00000000|H'E8201460|32|
|Interrupt priority register|25|ICDIPR25|R/W|H'00000000|H'E8201464|32|
|Interrupt priority register|26|ICDIPR26|R/W|H'00000000|H'E8201468|32|
|Interrupt priority register|27|ICDIPR27|R/W|H'00000000|H'E820146C|32|
|Interrupt priority register|28|ICDIPR28|R/W|H'00000000|H'E8201470|32|
|Interrupt priority register|29|ICDIPR29|R/W|H'00000000|H'E8201474|32|
|Interrupt priority register|30|ICDIPR30|R/W|H'00000000|H'E8201478|32|
|Interrupt priority register|31|ICDIPR31|R/W|H'00000000|H'E820147C|32|
|Interrupt priority register|32|ICDIPR32|R/W|H'00000000|H'E8201480|32|
|Interrupt priority register|33|ICDIPR33|R/W|H'00000000|H'E8201484|32|
|Interrupt priority register|34|ICDIPR34|R/W|H'00000000|H'E8201488|32|
|Interrupt priority register|35|ICDIPR35|R/W|H'00000000|H'E820148C|32|
|Interrupt priority register|36|ICDIPR36|R/W|H'00000000|H'E8201490|32|
|Interrupt priority register|37|ICDIPR37|R/W|H'00000000|H'E8201494|32|
|Interrupt priority register|38|ICDIPR38|R/W|H'00000000|H'E8201498|32|
|Interrupt priority register|39|ICDIPR39|R/W|H'00000000|H'E820149C|32|
|Interrupt priority register|40|ICDIPR40|R/W|H'00000000|H'E82014A0|32|
|Interrupt priority register|41|ICDIPR41|R/W|H'00000000|H'E82014A4|32|
|Interrupt priority register|42|ICDIPR42|R/W|H'00000000|H'E82014A8|32|
|Interrupt priority register|43|ICDIPR43|R/W|H'00000000|H'E82014AC|32|
|Interrupt priority register|44|ICDIPR44|R/W|H'00000000|H'E82014B0|32|
|Interrupt priority register|45|ICDIPR45|R/W|H'00000000|H'E82014B4|32|
|Interrupt priority register|46|ICDIPR46|R/W|H'00000000|H'E82014B8|32|
|Interrupt priority register|47|ICDIPR47|R/W|H'00000000|H'E82014BC|32|
|Interrupt priority register|48|ICDIPR48|R/W|H'00000000|H'E82014C0|32|
|Interrupt priority register|49|ICDIPR49|R/W|H'00000000|H'E82014C4|32|
|Interrupt priority register|50|ICDIPR50|R/W|H'00000000|H'E82014C8|32|
|Interrupt priority register|51|ICDIPR51|R/W|H'00000000|H'E82014CC|32|
|Interrupt priority register|52|ICDIPR52|R/W|H'00000000|H'E82014D0|32|
|Interrupt priority register|53|ICDIPR53|R/W|H'00000000|H'E82014D4|32|
|Interrupt priority register|54|ICDIPR54|R/W|H'00000000|H'E82014D8|32|
|Interrupt priority register|55|ICDIPR55|R/W|H'00000000|H'E82014DC|32|
|Interrupt priority register|56|ICDIPR56|R/W|H'00000000|H'E82014E0|32|
|Interrupt priority register|57|ICDIPR57|R/W|H'00000000|H'E82014E4|32|
|Interrupt priority register|58|ICDIPR58|R/W|H'00000000|H'E82014E8|32|
|Interrupt priority register|59|ICDIPR59|R/W|H'00000000|H'E82014EC|32|
|Interrupt priority register|60|ICDIPR60|R/W|H'00000000|H'E82014F0|32|
|Interrupt priority register|61|ICDIPR61|R/W|H'00000000|H'E82014F4|32|
|Interrupt priority register|62|ICDIPR62|R/W|H'00000000|H'E82014F8|32|
|Interrupt priority register|63|ICDIPR63|R/W|H'00000000|H'E82014FC|32|
|Interrupt priority register|64|ICDIPR64|R/W|H'00000000|H'E8201500|32|

**Table 7.2 Register Configuration**

|||||||**Access**|
|---|---|---|---|---|---|---|
|**Register Name**||**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt priority register|65|ICDIPR65|R/W|H'00000000|H'E8201504|32|
|Interrupt priority register|66|ICDIPR66|R/W|H'00000000|H'E8201508|32|
|Interrupt priority register|67|ICDIPR67|R/W|H'00000000|H'E820150C|32|
|Interrupt priority register|68|ICDIPR68|R/W|H'00000000|H'E8201510|32|
|Interrupt priority register|69|ICDIPR69|R/W|H'00000000|H'E8201514|32|
|Interrupt priority register|70|ICDIPR70|R/W|H'00000000|H'E8201518|32|
|Interrupt priority register|71|ICDIPR71|R/W|H'00000000|H'E820151C|32|
|Interrupt priority register|72|ICDIPR72|R/W|H'00000000|H'E8201520|32|
|Interrupt priority register|73|ICDIPR73|R/W|H'00000000|H'E8201524|32|
|Interrupt priority register|74|ICDIPR74|R/W|H'00000000|H'E8201528|32|
|Interrupt priority register|75|ICDIPR75|R/W|H'00000000|H'E820152C|32|
|Interrupt priority register|76|ICDIPR76|R/W|H'00000000|H'E8201530|32|
|Interrupt priority register|77|ICDIPR77|R/W|H'00000000|H'E8201534|32|
|Interrupt priority register|78|ICDIPR78|R/W|H'00000000|H'E8201538|32|
|Interrupt priority register|79|ICDIPR79|R/W|H'00000000|H'E820153C|32|
|Interrupt priority register|80|ICDIPR80|R/W|H'00000000|H'E8201540|32|
|Interrupt priority register|81|ICDIPR81|R/W|H'00000000|H'E8201544|32|
|Interrupt priority register|82|ICDIPR82|R/W|H'00000000|H'E8201548|32|
|Interrupt priority register|83|ICDIPR83|R/W|H'00000000|H'E820154C|32|
|Interrupt priority register|84|ICDIPR84|R/W|H'00000000|H'E8201550|32|
|Interrupt priority register|85|ICDIPR85|R/W|H'00000000|H'E8201554|32|
|Interrupt priority register|86|ICDIPR86|R/W|H'00000000|H'E8201558|32|
|Interrupt priority register|87|ICDIPR87|R/W|H'00000000|H'E820155C|32|
|Interrupt priority register|88|ICDIPR88|R/W|H'00000000|H'E8201560|32|
|Interrupt priority register|89|ICDIPR89|R/W|H'00000000|H'E8201564|32|
|Interrupt priority register|90|ICDIPR90|R/W|H'00000000|H'E8201568|32|
|Interrupt priority register|91|ICDIPR91|R/W|H'00000000|H'E820156C|32|
|Interrupt priority register|92|ICDIPR92|R/W|H'00000000|H'E8201570|32|
|Interrupt priority register|93|ICDIPR93|R/W|H'00000000|H'E8201574|32|
|Interrupt priority register|94|ICDIPR94|R/W|H'00000000|H'E8201578|32|
|Interrupt priority register|95|ICDIPR95|R/W|H'00000000|H'E820157C|32|
|Interrupt priority register|96|ICDIPR96|R/W|H'00000000|H'E8201580|32|
|Interrupt priority register|97|ICDIPR97|R/W|H'00000000|H'E8201584|32|
|Interrupt priority register|98|ICDIPR98|R/W|H'00000000|H'E8201588|32|
|Interrupt priority register|99|ICDIPR99|R/W|H'00000000|H'E820158C|32|
|Interrupt priority register|100|ICDIPR100|R/W|H'00000000|H'E8201590|32|
|Interrupt priority register|101|ICDIPR101|R/W|H'00000000|H'E8201594|32|
|Interrupt priority register|102|ICDIPR102|R/W|H'00000000|H'E8201598|32|
|Interrupt priority register|103|ICDIPR103|R/W|H'00000000|H'E820159C|32|
|Interrupt priority register|104|ICDIPR104|R/W|H'00000000|H'E82015A0|32|
|Interrupt priority register|105|ICDIPR105|R/W|H'00000000|H'E82015A4|32|
|Interrupt priority register|106|ICDIPR106|R/W|H'00000000|H'E82015A8|32|
|Interrupt priority register|107|ICDIPR107|R/W|H'00000000|H'E82015AC|32|
|Interrupt priority register|108|ICDIPR108|R/W|H'00000000|H'E82015B0|32|
|Interrupt priority register|109|ICDIPR109|R/W|H'00000000|H'E82015B4|32|

**Table 7.2 Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt priority register 110|ICDIPR110|R/W|H'00000000|H'E82015B8|32|
|Interrupt priority register 111|ICDIPR111|R/W|H'00000000|H'E82015BC|32|
|Interrupt priority register 112|ICDIPR112|R/W|H'00000000|H'E82015C0|32|
|Interrupt priority register 113|ICDIPR113|R/W|H'00000000|H'E82015C4|32|
|Interrupt priority register 114|ICDIPR114|R/W|H'00000000|H'E82015C8|32|
|Interrupt priority register 115|ICDIPR115|R/W|H'00000000|H'E82015CC|32|
|Interrupt priority register 116|ICDIPR116|R/W|H'00000000|H'E82015D0|32|
|Interrupt priority register 117|ICDIPR117|R/W|H'00000000|H'E82015D4|32|
|Interrupt priority register 118|ICDIPR118|R/W|H'00000000|H'E82015D8|32|
|Interrupt priority register 119|ICDIPR119|R/W|H'00000000|H'E82015DC|32|
|Interrupt priority register 120|ICDIPR120|R/W|H'00000000|H'E82015E0|32|
|Interrupt priority register 121|ICDIPR121|R/W|H'00000000|H'E82015E4|32|
|Interrupt priority register 122|ICDIPR122|R/W|H'00000000|H'E82015E8|32|
|Interrupt priority register 123|ICDIPR123|R/W|H'00000000|H'E82015EC|32|
|Interrupt priority register 124|ICDIPR124|R/W|H'00000000|H'E82015F0|32|
|Interrupt priority register 125|ICDIPR125|R/W|H'00000000|H'E82015F4|32|
|Interrupt priority register 126|ICDIPR126|R/W|H'00000000|H'E82015F8|32|
|Interrupt priority register 127|ICDIPR127|R/W|H'00000000|H'E82015FC|32|
|Interrupt priority register 128|ICDIPR128|R/W|H'00000000|H'E8201600|32|
|Interrupt priority register 129|ICDIPR129|R/W|H'00000000|H'E8201604|32|
|Interrupt priority register 130|ICDIPR130|R/W|H'00000000|H'E8201608|32|
|Interrupt priority register 131|ICDIPR131|R/W|H'00000000|H'E820160C|32|
|Interrupt priority register 132|ICDIPR132|R/W|H'00000000|H'E8201610|32|
|Interrupt priority register 133|ICDIPR133|R/W|H'00000000|H'E8201614|32|
|Interrupt priority register 134|ICDIPR134|R/W|H'00000000|H'E8201618|32|
|Interrupt processor target register 0|ICDIPTR0|R|H'00000000|H'E8201800|32|
|Interrupt processor target register 1|ICDIPTR1|R|H'00000000|H'E8201804|32|
|Interrupt processor target register 2|ICDIPTR2|R|H'00000000|H'E8201808|32|
|Interrupt processor target register 3|ICDIPTR3|R|H'00000000|H'E820180C|32|
|Interrupt processor target register 4|ICDIPTR4|R|H'00000000|H'E8201810|32|
|Interrupt processor target register 5|ICDIPTR5|R|H'00000000|H'E8201814|32|
|Interrupt processor target register 6|ICDIPTR6|R|H'00000000|H'E8201818|32|
|Interrupt processor target register 7|ICDIPTR7|R|H'00000000|H'E820181C|32|
|Interrupt processor target register 8|ICDIPTR8|R/W|H'00000000|H'E8201820|32|
|Interrupt processor target register 9|ICDIPTR9|R/W|H'00000000|H'E8201824|32|
|Interrupt processor target register 10|ICDIPTR10|R/W|H'00000000|H'E8201828|32|
|Interrupt processor target register 11|ICDIPTR11|R/W|H'00000000|H'E820182C|32|
|Interrupt processor target register 12|ICDIPTR12|R/W|H'00000000|H'E8201830|32|
|Interrupt processor target register 13|ICDIPTR13|R/W|H'00000000|H'E8201834|32|
|Interrupt processor target register 14|ICDIPTR14|R/W|H'00000000|H'E8201838|32|
|Interrupt processor target register 15|ICDIPTR15|R/W|H'00000000|H'E820183C|32|
|Interrupt processor target register 16|ICDIPTR16|R/W|H'00000000|H'E8201840|32|
|Interrupt processor target register 17|ICDIPTR17|R/W|H'00000000|H'E8201844|32|
|Interrupt processor target register 18|ICDIPTR18|R/W|H'00000000|H'E8201848|32|
|Interrupt processor target register 19|ICDIPTR19|R/W|H'00000000|H'E820184C|32|

**Table 7.2 Register Configuration**

|||||||**Access**|
|---|---|---|---|---|---|---|
|**Register Name**||**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt processor target register|20|ICDIPTR20|R/W|H'00000000|H'E8201850|32|
|Interrupt processor target register|21|ICDIPTR21|R/W|H'00000000|H'E8201854|32|
|Interrupt processor target register|22|ICDIPTR22|R/W|H'00000000|H'E8201858|32|
|Interrupt processor target register|23|ICDIPTR23|R/W|H'00000000|H'E820185C|32|
|Interrupt processor target register|24|ICDIPTR24|R/W|H'00000000|H'E8201860|32|
|Interrupt processor target register|25|ICDIPTR25|R/W|H'00000000|H'E8201864|32|
|Interrupt processor target register|26|ICDIPTR26|R/W|H'00000000|H'E8201868|32|
|Interrupt processor target register|27|ICDIPTR27|R/W|H'00000000|H'E820186C|32|
|Interrupt processor target register|28|ICDIPTR28|R/W|H'00000000|H'E8201870|32|
|Interrupt processor target register|29|ICDIPTR29|R/W|H'00000000|H'E8201874|32|
|Interrupt processor target register|30|ICDIPTR30|R/W|H'00000000|H'E8201878|32|
|Interrupt processor target register|31|ICDIPTR31|R/W|H'00000000|H'E820187C|32|
|Interrupt processor target register|32|ICDIPTR32|R/W|H'00000000|H'E8201880|32|
|Interrupt processor target register|33|ICDIPTR33|R/W|H'00000000|H'E8201884|32|
|Interrupt processor target register|34|ICDIPTR34|R/W|H'00000000|H'E8201888|32|
|Interrupt processor target register|35|ICDIPTR35|R/W|H'00000000|H'E820188C|32|
|Interrupt processor target register|36|ICDIPTR36|R/W|H'00000000|H'E8201890|32|
|Interrupt processor target register|37|ICDIPTR37|R/W|H'00000000|H'E8201894|32|
|Interrupt processor target register|38|ICDIPTR38|R/W|H'00000000|H'E8201898|32|
|Interrupt processor target register|39|ICDIPTR39|R/W|H'00000000|H'E820189C|32|
|Interrupt processor target register|40|ICDIPTR40|R/W|H'00000000|H'E82018A0|32|
|Interrupt processor target register|41|ICDIPTR41|R/W|H'00000000|H'E82018A4|32|
|Interrupt processor target register|42|ICDIPTR42|R/W|H'00000000|H'E82018A8|32|
|Interrupt processor target register|43|ICDIPTR43|R/W|H'00000000|H'E82018AC|32|
|Interrupt processor target register|44|ICDIPTR44|R/W|H'00000000|H'E82018B0|32|
|Interrupt processor target register|45|ICDIPTR45|R/W|H'00000000|H'E82018B4|32|
|Interrupt processor target register|46|ICDIPTR46|R/W|H'00000000|H'E82018B8|32|
|Interrupt processor target register|47|ICDIPTR47|R/W|H'00000000|H'E82018BC|32|
|Interrupt processor target register|48|ICDIPTR48|R/W|H'00000000|H'E82018C0|32|
|Interrupt processor target register|49|ICDIPTR49|R/W|H'00000000|H'E82018C4|32|
|Interrupt processor target register|50|ICDIPTR50|R/W|H'00000000|H'E82018C8|32|
|Interrupt processor target register|51|ICDIPTR51|R/W|H'00000000|H'E82018CC|32|
|Interrupt processor target register|52|ICDIPTR52|R/W|H'00000000|H'E82018D0|32|
|Interrupt processor target register|53|ICDIPTR53|R/W|H'00000000|H'E82018D4|32|
|Interrupt processor target register|54|ICDIPTR54|R/W|H'00000000|H'E82018D8|32|
|Interrupt processor target register|55|ICDIPTR55|R/W|H'00000000|H'E82018DC|32|
|Interrupt processor target register|56|ICDIPTR56|R/W|H'00000000|H'E82018E0|32|
|Interrupt processor target register|57|ICDIPTR57|R/W|H'00000000|H'E82018E4|32|
|Interrupt processor target register|58|ICDIPTR58|R/W|H'00000000|H'E82018E8|32|
|Interrupt processor target register|59|ICDIPTR59|R/W|H'00000000|H'E82018EC|32|
|Interrupt processor target register|60|ICDIPTR60|R/W|H'00000000|H'E82018F0|32|
|Interrupt processor target register|61|ICDIPTR61|R/W|H'00000000|H'E82018F4|32|
|Interrupt processor target register|62|ICDIPTR62|R/W|H'00000000|H'E82018F8|32|
|Interrupt processor target register|63|ICDIPTR63|R/W|H'00000000|H'E82018FC|32|
|Interrupt processor target register|64|ICDIPTR64|R/W|H'00000000|H'E8201900|32|

**Table 7.2 Register Configuration**

|||||||**Access**|
|---|---|---|---|---|---|---|
|**Register Name**||**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt processor target register|65|ICDIPTR65|R/W|H'00000000|H'E8201904|32|
|Interrupt processor target register|66|ICDIPTR66|R/W|H'00000000|H'E8201908|32|
|Interrupt processor target register|67|ICDIPTR67|R/W|H'00000000|H'E820190C|32|
|Interrupt processor target register|68|ICDIPTR68|R/W|H'00000000|H'E8201910|32|
|Interrupt processor target register|69|ICDIPTR69|R/W|H'00000000|H'E8201914|32|
|Interrupt processor target register|70|ICDIPTR70|R/W|H'00000000|H'E8201918|32|
|Interrupt processor target register|71|ICDIPTR71|R/W|H'00000000|H'E820191C|32|
|Interrupt processor target register|72|ICDIPTR72|R/W|H'00000000|H'E8201920|32|
|Interrupt processor target register|73|ICDIPTR73|R/W|H'00000000|H'E8201924|32|
|Interrupt processor target register|74|ICDIPTR74|R/W|H'00000000|H'E8201928|32|
|Interrupt processor target register|75|ICDIPTR75|R/W|H'00000000|H'E820192C|32|
|Interrupt processor target register|76|ICDIPTR76|R/W|H'00000000|H'E8201930|32|
|Interrupt processor target register|77|ICDIPTR77|R/W|H'00000000|H'E8201934|32|
|Interrupt processor target register|78|ICDIPTR78|R/W|H'00000000|H'E8201938|32|
|Interrupt processor target register|79|ICDIPTR79|R/W|H'00000000|H'E820193C|32|
|Interrupt processor target register|80|ICDIPTR80|R/W|H'00000000|H'E8201940|32|
|Interrupt processor target register|81|ICDIPTR81|R/W|H'00000000|H'E8201944|32|
|Interrupt processor target register|82|ICDIPTR82|R/W|H'00000000|H'E8201948|32|
|Interrupt processor target register|83|ICDIPTR83|R/W|H'00000000|H'E820194C|32|
|Interrupt processor target register|84|ICDIPTR84|R/W|H'00000000|H'E8201950|32|
|Interrupt processor target register|85|ICDIPTR85|R/W|H'00000000|H'E8201954|32|
|Interrupt processor target register|86|ICDIPTR86|R/W|H'00000000|H'E8201958|32|
|Interrupt processor target register|87|ICDIPTR87|R/W|H'00000000|H'E820195C|32|
|Interrupt processor target register|88|ICDIPTR88|R/W|H'00000000|H'E8201960|32|
|Interrupt processor target register|89|ICDIPTR89|R/W|H'00000000|H'E8201964|32|
|Interrupt processor target register|90|ICDIPTR90|R/W|H'00000000|H'E8201968|32|
|Interrupt processor target register|91|ICDIPTR91|R/W|H'00000000|H'E820196C|32|
|Interrupt processor target register|92|ICDIPTR92|R/W|H'00000000|H'E8201970|32|
|Interrupt processor target register|93|ICDIPTR93|R/W|H'00000000|H'E8201974|32|
|Interrupt processor target register|94|ICDIPTR94|R/W|H'00000000|H'E8201978|32|
|Interrupt processor target register|95|ICDIPTR95|R/W|H'00000000|H'E820197C|32|
|Interrupt processor target register|96|ICDIPTR96|R/W|H'00000000|H'E8201980|32|
|Interrupt processor target register|97|ICDIPTR97|R/W|H'00000000|H'E8201984|32|
|Interrupt processor target register|98|ICDIPTR98|R/W|H'00000000|H'E8201988|32|
|Interrupt processor target register|99|ICDIPTR99|R/W|H'00000000|H'E820198C|32|
|Interrupt processor target register|100|ICDIPTR100|R/W|H'00000000|H'E8201990|32|
|Interrupt processor target register|101|ICDIPTR101|R/W|H'00000000|H'E8201994|32|
|Interrupt processor target register|102|ICDIPTR102|R/W|H'00000000|H'E8201998|32|
|Interrupt processor target register|103|ICDIPTR103|R/W|H'00000000|H'E820199C|32|
|Interrupt processor target register|104|ICDIPTR104|R/W|H'00000000|H'E82019A0|32|
|Interrupt processor target register|105|ICDIPTR105|R/W|H'00000000|H'E82019A4|32|
|Interrupt processor target register|106|ICDIPTR106|R/W|H'00000000|H'E82019A8|32|
|Interrupt processor target register|107|ICDIPTR107|R/W|H'00000000|H'E82019AC|32|
|Interrupt processor target register|108|ICDIPTR108|R/W|H'00000000|H'E82019B0|32|
|Interrupt processor target register|109|ICDIPTR109|R/W|H'00000000|H'E82019B4|32|

**Table 7.2 Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt processor target register 110|ICDIPTR110|R/W|H'00000000|H'E82019B8|32|
|Interrupt processor target register 111|ICDIPTR111|R/W|H'00000000|H'E82019BC|32|
|Interrupt processor target register 112|ICDIPTR112|R/W|H'00000000|H'E82019C0|32|
|Interrupt processor target register 113|ICDIPTR113|R/W|H'00000000|H'E82019C4|32|
|Interrupt processor target register 114|ICDIPTR114|R/W|H'00000000|H'E82019C8|32|
|Interrupt processor target register 115|ICDIPTR115|R/W|H'00000000|H'E82019CC|32|
|Interrupt processor target register 116|ICDIPTR116|R/W|H'00000000|H'E82019D0|32|
|Interrupt processor target register 117|ICDIPTR117|R/W|H'00000000|H'E82019D4|32|
|Interrupt processor target register 118|ICDIPTR118|R/W|H'00000000|H'E82019D8|32|
|Interrupt processor target register 119|ICDIPTR119|R/W|H'00000000|H'E82019DC|32|
|Interrupt processor target register 120|ICDIPTR120|R/W|H'00000000|H'E82019E0|32|
|Interrupt processor target register 121|ICDIPTR121|R/W|H'00000000|H'E82019E4|32|
|Interrupt processor target register 122|ICDIPTR122|R/W|H'00000000|H'E82019E8|32|
|Interrupt processor target register 123|ICDIPTR123|R/W|H'00000000|H'E82019EC|32|
|Interrupt processor target register 124|ICDIPTR124|R/W|H'00000000|H'E82019F0|32|
|Interrupt processor target register 125|ICDIPTR125|R/W|H'00000000|H'E82019F4|32|
|Interrupt processor target register 126|ICDIPTR126|R/W|H'00000000|H'E82019F8|32|
|Interrupt processor target register 127|ICDIPTR127|R/W|H'00000000|H'E82019FC|32|
|Interrupt processor target register 128|ICDIPTR128|R/W|H'00000000|H'E8201A00|32|
|Interrupt processor target register 129|ICDIPTR129|R/W|H'00000000|H'E8201A04|32|
|Interrupt processor target register 130|ICDIPTR130|R/W|H'00000000|H'E8201A08|32|
|Interrupt processor target register 131|ICDIPTR131|R/W|H'00000000|H'E8201A0C|32|
|Interrupt processor target register 132|ICDIPTR132|R/W|H'00000000|H'E8201A10|32|
|Interrupt processor target register 133|ICDIPTR133|R/W|H'00000000|H'E8201A14|32|
|Interrupt processor target register 134|ICDIPTR134|R/W|H'00000000|H'E8201A18|32|
|Interrupt configuration register 0|ICDICFR0|R|H'AAAAAAAA|H'E8201C00|32|
|Interrupt configuration register 1|ICDICFR1|R/W|H'55555555|H'E8201C04|32|
|Interrupt configuration register 2|ICDICFR2|R/W|H'55555555|H'E8201C08|32|
|Interrupt configuration register 3|ICDICFR3|R/W|H'55555555|H'E8201C0C|32|
|Interrupt configuration register 4|ICDICFR4|R/W|H'55555555|H'E8201C10|32|
|Interrupt configuration register 5|ICDICFR5|R/W|H'55555555|H'E8201C14|32|
|Interrupt configuration register 6|ICDICFR6|R/W|H'55555555|H'E8201C18|32|
|Interrupt configuration register 7|ICDICFR7|R/W|H'55555555|H'E8201C1C|32|
|Interrupt configuration register 8|ICDICFR8|R/W|H'55555555|H'E8201C20|32|
|Interrupt configuration register 9|ICDICFR9|R/W|H'55555555|H'E8201C24|32|
|Interrupt configuration register 10|ICDICFR10|R/W|H'55555555|H'E8201C28|32|
|Interrupt configuration register 11|ICDICFR11|R/W|H'55555555|H'E8201C2C|32|
|Interrupt configuration register 12|ICDICFR12|R/W|H'55555555|H'E8201C30|32|
|Interrupt configuration register 13|ICDICFR13|R/W|H'55555555|H'E8201C34|32|
|Interrupt configuration register 14|ICDICFR14|R/W|H'55555555|H'E8201C38|32|
|Interrupt configuration register 15|ICDICFR15|R/W|H'55555555|H'E8201C3C|32|
|Interrupt configuration register 16|ICDICFR16|R/W|H'55555555|H'E8201C40|32|
|Interrupt configuration register 17|ICDICFR17|R/W|H'55555555|H'E8201C44|32|
|Interrupt configuration register 18|ICDICFR18|R/W|H'55555555|H'E8201C48|32|
|Interrupt configuration register 19|ICDICFR19|R/W|H'55555555|H'E8201C4C|32|

**Table 7.2 Register Configuration**

|**Table 7.2**<br>**Register Configuration**||||||
|---|---|---|---|---|---|
||||||**Access**|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt configuration register 20|ICDICFR20|R/W|H'55555555|H'E8201C50|32|
|Interrupt configuration register 21|ICDICFR21|R/W|H'55555555|H'E8201C54|32|
|Interrupt configuration register 22|ICDICFR22|R/W|H'55555555|H'E8201C58|32|
|Interrupt configuration register 23|ICDICFR23|R/W|H'55555555|H'E8201C5C|32|
|Interrupt configuration register 24|ICDICFR24|R/W|H'55555555|H'E8201C60|32|
|Interrupt configuration register 25|ICDICFR25|R/W|H'55555555|H'E8201C64|32|
|Interrupt configuration register 26|ICDICFR26|R/W|H'55555555|H'E8201C68|32|
|Interrupt configuration register 27|ICDICFR27|R/W|H'55555555|H'E8201C6C|32|
|Interrupt configuration register 28|ICDICFR28|R/W|H'55555555|H'E8201C70|32|
|Interrupt configuration register 29|ICDICFR29|R/W|H'55555555|H'E8201C74|32|
|Interrupt configuration register 30|ICDICFR30|R/W|H'55555555|H'E8201C78|32|
|Interrupt configuration register 31|ICDICFR31|R/W|H'55555555|H'E8201C7C|32|
|Interrupt configuration register 32|ICDICFR32|R/W|H'55555555|H'E8201C80|32|
|Interrupt configuration register 33|ICDICFR33|R/W|H'55555555|H'E8201C84|32|
|PPI status register|ppi_status|R|H'00000000|H'E8201D00|32|
|SPI status register 0|spi_status0|R|H'00000000|H'E8201D04|32|
|SPI status register 1|spi_status1|R|H'00000000|H'E8201D08|32|
|SPI status register 2|spi_status2|R|H'00000000|H'E8201D0C|32|
|SPI status register 3|spi_status3|R|H'00000000|H'E8201D10|32|
|SPI status register 4|spi_status4|R|H'00000000|H'E8201D14|32|
|SPI status register 5|spi_status5|R|H'00000000|H'E8201D18|32|
|SPI status register 6|spi_status6|R|H'00000000|H'E8201D1C|32|
|SPI status register 7|spi_status7|R|H'00000000|H'E8201D20|32|
|SPI status register 8|spi_status8|R|H'00000000|H'E8201D24|32|
|SPI status register 9|spi_status9|R|H'00000000|H'E8201D28|32|
|SPI status register 10|spi_status10|R|H'00000000|H'E8201D2C|32|
|SPI status register 11|spi_status11|R|H'00000000|H'E8201D30|32|
|SPI status register 12|spi_status12|R|H'00000000|H'E8201D34|32|
|SPI status register 13|spi_status13|R|H'00000000|H'E8201D38|32|
|SPI status register 14|spi_status14|R|H'00000000|H'E8201D3C|32|
|Software generation interrupt register|ICDSGIR|W|H'00000000|H'E8201F00|32|
|CPU interface control register|ICCICR|R/W|H'00000000|H'E8202000|32|
|Interrupt priority mask register|ICCPMR|R/W|H'00000000|H'E8202004|32|
|Binary point register|ICCBPR|R/W|H'00000002|H'E8202008|32|
|Interrupt acknowledge register|ICCIAR|R|H'000003FF|H'E820200C|32|
|End-of-interrupt register|ICCEOIR|W|-|H'E8202010|32|
|Running priority register|ICCRPR|R|H'000000FF|H'E8202014|32|
|Highest pending interrupt register|ICCHPIR|R|H'000003FF|H'E8202018|32|
|Aliased binary point register|ICCABPR|R/W|H'00000003|H'E820201C|32|
|CPU interface implementer identification|ICCIIDR|R|H'3901043B|H'E82020FC|32|
|register||||||

Note 1. When the NMI pin is high, becomes H'8000; when low, becomes H'0000. Note 2. Only 0 can be written after reading 1, to clear the flag. Note 3. Use the following expression to calculate the maximum number of interrupt IDs from the number of IT lines. (17+1) × 32 + 1 to (17 + 2) × 32: 577 to 608

## 7.3.1 Interrupt Control Register 0 (ICR0)

ICR0 is a 16-bit register that sets the input signal detection mode for the external interrupt input pin NMI, and indicates the input level at the NMI pin.

|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2||1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||NMIL|-|-|-|-|-|-|NMIE|-|-|-|-|-|-||NMIF|-|
|Initial value:|*1|0|0|0|0|0|0|0|0|0|0|0|0|0||0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R|R|R|R|R|R|R/(W)*2<br>R|||
|Notes:<br>1.|1 when the NMI pin is|||high, and 0 when the NMI pin||||is low.||||||||||
|2.|Only 0 can be written after reading 1, to clear the flag.|||||||||||||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|NMIL|*1|R|NMI Input Level|
|||||Sets the level of the signal input at the NMI pin. The NMI pin level can be|
|||||obtained by reading this bit. This bit cannot be modified.|
|||||0: Low level is input to NMI pin|
|||||1: High level is input to NMI pin|
|14 to 9|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|NMIE|0|R/W|NMI Edge Select|
|||||Selects whether the falling or rising edge of the interrupt request signal on|
|||||the NMI pin is detected.|
|||||0: Interrupt request is detected on falling edge of NMI input|
|||||1: Interrupt request is detected on rising edge of NMI input|
|7 to 2|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1|NMIF|0|R/|NMI Interrupt Request|
||||(W)*2|This bit indicates the status of the NMI interrupt request. This bit cannot be|
|||||modified.|
|||||0: NMI interrupt request has not occurred|
|||||[Clearing conditions]|
|||||Cleared by changing NMIE of ICR0|
|||||Cleared by reading NMIF while NMIF = 1, then writing 0 to NMIF|
|||||1: NMI interrupt request is detected|
|||||[Setting condition]|
|||||Edge corresponding to NMIE of ICR0 has occurred at NMI pin|
|0|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|

## 7.3.2 Interrupt Control Register 1 (ICR1)

ICR1 is a 16-bit register that specifies the detection mode for external interrupt input pins IRQ7 to IRQ0 individually: low level, falling edge, rising edge, or both edges.

|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||IRQ71S|IRQ70S|IRQ61S|IRQ60S|IRQ51S|IRQ50S|IRQ41S|IRQ40S|IRQ31S|IRQ30S|IRQ21S|IRQ20S|IRQ11S|IRQ10S|IRQ01S|IRQ00S|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|IRQ71S|0|R/W|IRQ Sense Select|
|14|IRQ70S|0|R/W|These bits select whether interrupt signals corresponding to pins IRQ7 to<br>IRQ0 are detected by a low level, falling edge, rising edge, or both edges.|
|13|IRQ61S|0|R/W|00: Interrupt request is detected on low level of IRQn input|
|12|IRQ60S|0|R/W|01: Interrupt request is detected on falling edge of IRQn input<br>10: Interrupt request is detected on rising edge of IRQn input|
|11|IRQ51S|0|R/W|11: Interrupt request is detected on both edges of IRQn input|
|10|IRQ50S|0|R/W||
|9|IRQ41S|0|R/W||
|8|IRQ40S|0|R/W||
|7|IRQ31S|0|R/W||
|6|IRQ30S|0|R/W||
|5|IRQ21S|0|R/W||
|4|IRQ20S|0|R/W||
|3|IRQ11S|0|R/W||
|2|IRQ10S|0|R/W||
|1|IRQ01S|0|R/W||
|0|IRQ00S|0|R/W||

[Legend] n = 7 to 0

## 7.3.3 IRQ Interrupt Request Register (IRQRR)

IRQRR is a 16-bit register that indicates interrupt requests from external input pins IRQ7 to IRQ0. If edge detection is set for the IRQ7 to IRQ0 interrupts, writing 0 to the IRQ7F to IRQ0F bits after reading IRQ7F to IRQ0F = 1 cancels the retained interrupts.

||||15<br>Bit:|14|13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||-|-|-|-|-|-|-<br>-<br>IRQ7F<br>IRQ6F|IRQ5F|IRQ4F|IRQ3F|IRQ2F|IRQ1F|IRQ0F||
||||Initial value:<br>0|0|0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:<br>R|R|R|R|R|R|R/(W)*R/(W)*R/(W)*R/(W)*R/(W)*R/(W)*R/(W)*R/(W)*<br>R<br>R||||||||
||||Note:<br>Only 0 can be written to clear<br>*||||the flag after 1||is read.||||||||
||||||**Initial**||||||||||||
|**Bit**|||**Bit Name**||**Value**||**R/W**||**Description**||||||||
|15|to|8|―||All 0||R||Reserved||||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||||
|7|||IRQ7F||0||R/(W)*||IRQ Interrupt Request||||||||
|6|||IRQ6F||0||R/(W)*||These bits indicate the status of the IRQ7 to IRQ0 interrupt requests.<br>Level detection:||||||||
|5|||IRQ5F||0||R/(W)*||0: IRQn interrupt request|has not occurred|||||||
|4|||IRQ4F||0||R/(W)*||[Clearing condition]<br>IRQn input is high||||||||
|3|||IRQ3F||0||R/(W)*||1: IRQn interrupt has occurred||||||||
|2|||IRQ2F||0||R/(W)*||[Setting condition]<br>IRQn input is low||||||||
|1|||IRQ1F||0||R/(W)*||Edge detection:||||||||
|0|||IRQ0F||0||R/(W)*||0: IRQn interrupt request|is not detected|||||||
||||||||||[Clearing condition]||||||||
||||||||||Cleared by reading IRQnF while IRQnF = 1, then|||||writing 0 to IRQnF|||
||||||||||1: IRQn interrupt request|is detected|||||||
||||||||||[Setting condition]||||||||
||||||||||Edge corresponding to|IRQn1S or IRQn0S of ICR1 has|||||occurred at||
||||||||||IRQn pin||||||||

[Legend] n = 7 to 0

## 7.4 Interrupt Sources

There are four types of interrupt sources: NMI, IRQ, on-chip peripheral modules, and pin interrupts. Each interrupt has a priority level (0 to 31), with 0 the highest and 31 the lowest.

## 7.4.1 NMI Interrupt

The NMI interrupt with the highest priority is accepted by the CPU as an FIQ exception all times. NMI interrupt requests are edge-detected, and the NMI edge select bit (NMIE) in ICR0 selects whether the rising edge or falling edge is detected. The status of the interrupt request can be checked by reading the NMI interrupt request bit (NMIF) in the ICR0. When the NMIE bit is changed, the NMI interrupt request that is retained is cleared.

When deep standby mode is entered, deep standby mode is canceled by the NMI interrupt.

## 7.4.2 IRQ Interrupts

IRQ interrupts are input from pins IRQ7 to IRQ0. For the IRQ interrupts, low-level, falling-edge, rising-edge, or bothedge detection can be selected individually for each pin by the IRQ sense select bits (IRQ71S to IRQ01S and IRQ70S to IRQ00S) in interrupt control register 1 (ICR1).

When using low-level sensing for IRQ interrupts, an interrupt request signal is sent to the interrupt controller while the IRQ7 to IRQ0 pins are low. An interrupt request signal is stopped being sent to the interrupt controller when the IRQ7 to IRQ0 pins are driven high. The status of the interrupt requests can be checked by reading the IRQ interrupt request bits (IRQ7F to IRQ0F) in the IRQ interrupt request register (IRQRR).

When using edge-sensing for IRQ interrupts, an interrupt request is detected due to change of the IRQ7 to IRQ0 pin states, and an interrupt request signal is sent to the interrupt controller. The result of IRQ interrupt request detection is retained until that interrupt request is accepted. Whether IRQ interrupt requests have been detected or not can be checked by reading the IRQ7F to IRQ0F bits in the IRQ interrupt request register (IRQRR). Writing 0 to these bits after reading them as 1 clears the result of IRQ interrupt request detection.

When returning from IRQ interrupt exception service routine, execute the return instruction after confirming that the interrupt request has been cleared by the IRQ interrupt request register (IRQRR) so as not to accidentally receive the interrupt request again.

## 7.4.3 On-Chip Peripheral Module Interrupts

On-chip peripheral module interrupts are generated by the following on-chip peripheral modules:

- Direct memory access controller

- USB 2.0 host/function module

- Video display controller 5

- JPEG codec unit (RZ/A1LU only)

- OS timer

- Bus state controller

- Watchdog timer

- Multi-function timer pulse unit 2

- 12-bit A/D converter

- Serial sound interface

- Renesas SPDIF interface

- I[2] C bus interface

- Serial communication interface with FIFO

- CAN interface

- Renesas serial peripheral interface

- IEBus[TM] controller (RZ/A1L only)

- CD-ROM decoder (RZ/A1L only)

- MMC host interface

- SD host interface

- Realtime clock

- SCUX

- Media local bus (RZ/A1L only)

- LIN interface (RZ/A1L only)

- Serial communication interface

- EthernetAVB (RZ/A1LU only)

- Ethernet controller

- Capture engine unit

- On-chip RAM

- Internal bus

When returning from the interrupt exception service routine for an interrupt request at the peripheral-module level, execute the return instruction after clearing the source flag at the source of the request and reading the source flag so that the interrupt request is not accidentally received again.

## 7.4.4 Pin Interrupts

Pin interrupts are input from pins TINT121 to TINT0. Signals input on pins TINT121 to TINT0 are conveyed as interrupt signals regardless of mode settings and pin function settings for the general-purpose I/O port pin. Accordingly, if pin interrupts are to be used in port mode, set the pin as an input port pin. Alternatively, if an alternative mode is selected, the alternative pin with an input function can only be used for pin interrupts. For the settings of generalpurpose I/O port pins, see section 41., Ports .

For the pin interrupts, high-level or rising-edge detection can be selected individually for each pin by the interrupt configuration registers (ICDICFRn). For a description of the interrupt configuration registers (ICDICFRn), see the GIC architecture specification.

## 7.5 Interrupt IDs

Table 7.3 lists the interrupt sources and their interrupt IDs, and the registers for setting the interrupt sources. Do not make settings other than those in table 7.3, otherwise, the operation cannot be guaranteed.

Each interrupt source is allocated a different interrupt ID. To control notification of the interrupt source to the CPU and reference its status, it is necessary to set and reference the following registers which correspond to given interrupt IDs.

- Interrupt security register

- Interrupt set-enable register

- Interrupt clear-enable register

- Interrupt set-pending register

- Interrupt clear-pending register

- Active bit register

- Interrupt configuration register

ICDISRn

ICDISERn

ICDICERn

ICDISPRn

- ICDICPRn

ICDABRn

ICDICFRn

- Interrupt priority register ICDIPRn

- Interrupt processor target register ICDIPTRn

For the procedure for the initial settings of the registers, see section 7.6.1 Initial Settings . For details on individual registers, see the Arm Generic Interrupt Controller Architecture Specification and the PrimeCell[®] Generic Interrupt Controller (PL390) Technical Reference Manual from Arm.

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**||**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**<br>**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**|**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|GIC<br>software<br>interrupt<br>-|-<br>-|0<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15<br>16<br>17<br>18<br>19|0<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>0<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>1<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>2<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>3<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|CPU<br>0|PMUIRQ0<br>Level||16<br>1<br>17<br>18<br>19|1 to 0<br>4<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||COMMRX0<br>Level||||15 to 8|
||COMMTX0<br>Level||||23 to 16|
||CTIIRQ0<br>Level||||31 to 24|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|IRQ|-|IRQ0<br>Level<br>32<br>1<br>IRQ1<br>Level<br>33<br>IRQ2<br>Level<br>34<br>IRQ3<br>Level<br>35<br>IRQ4<br>Level<br>36<br>IRQ5<br>Level<br>37<br>IRQ6<br>Level<br>38<br>IRQ7<br>Level<br>39<br>PL310ERR<br>Level<br>40<br>DMAINT0<br>Edge<br>41<br>DMAINT1<br>Edge<br>42<br>DMAINT2<br>Edge<br>43<br>DMAINT3<br>Edge<br>44<br>DMAINT4<br>Edge<br>45<br>DMAINT5<br>Edge<br>46<br>DMAINT6<br>Edge<br>47<br>DMAINT7<br>Edge<br>48<br>DMAINT8<br>Edge<br>49<br>DMAINT9<br>Edge<br>50<br>DMAINT10<br>Edge<br>51<br>DMAINT11<br>Edge<br>52<br>DMAINT12<br>Edge<br>53<br>DMAINT13<br>Edge<br>54<br>DMAINT14<br>Edge<br>55<br>DMAINT15<br>Edge<br>56<br>DMAERR<br>Edge<br>57|0<br>2<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>8<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>9<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|Secondary<br>cache|-|||17 to 16<br>10<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|Direct<br>memory<br>access<br>controller|0||||15 to 8|
||1||||23 to 16|
||2||||31 to 24|
||3|||25 to 24<br>11<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||4||||15 to 8|
||5||||23 to 16|
||6||||31 to 24|
||7||16<br>3<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25|1 to 0<br>12<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||8||||15 to 8|
||9||||23 to 16|
||10||||31 to 24|
||11|||9 to 8<br>13<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||12||||15 to 8|
||13||||23 to 16|
||14||||31 to 24|
||15|||17 to 16<br>14<br>19 to 18|7 to 0|
||-||||15 to 8|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Reserved||58<br>1<br>59<br>60<br>61<br>62<br>63|26<br>3<br>27<br>28<br>29<br>30<br>31|21 to 20<br>14<br>23 to 22|23 to 16|
||||||31 to 24|
|||||25 to 24<br>15<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||64<br>2<br>65<br>66<br>67<br>68<br>69<br>70<br>71<br>72<br>USBI0<br>Level<br>73<br>USBI1<br>Level<br>74<br>S0_VI_VSYNC0<br>Level<br>75<br>S0_LO_VSYNC0<br>Level<br>76<br>S0_VSYNCERR0<br>Level<br>77<br>GR3_VLINE0<br>Level<br>78<br>S0_VFIELD0<br>Level<br>79<br>IV1_VBUFERR0<br>Level<br>80<br>IV3_VBUFERR0<br>Level<br>81<br>IV5_VBUFERR0<br>Level<br>82<br>IV6_VBUFERR0<br>Level<br>83<br>S0_WLINE0<br>Level<br>84<br>85<br>86<br>87<br>88<br>89<br>90<br>91<br>92<br>93<br>94<br>95|0<br>4<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>16<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>17<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>18<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|USB 2.0<br>host/<br>function<br>module|0||||15 to 8|
||1||||23 to 16|
|Video<br>display<br>controller 5|-||||31 to 24|
|||||25 to 24<br>19<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
||||16<br>5<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>20<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>21<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|Reserved|||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>22<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>23<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|

## **Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|
|**Module**<br>**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Reserved|96<br>3<br>97<br>98<br>99<br>100<br>101<br>102<br>103<br>104<br>105<br>106<br>107<br>108<br>109<br>110<br>111<br>112<br>113<br>114<br>115<br>116<br>117<br>118<br>119<br>120<br>121<br>122<br>123<br>124<br>125<br>JEDI<br>Level<br>126<br>JDTI<br>Level<br>127|0<br>6<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>24<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>25<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>26<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>27<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
|||16<br>7<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>28<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>29<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>30<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>31<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|JPEG<br>codec unit<br>(RZ/A1LU<br>only)<br>-||||23 to 16|
|||||31 to 24|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Reserved||128<br>4<br>129<br>130<br>131<br>132<br>133<br>OSTM0TINT<br>Edge<br>134<br>OSTM1TINT<br>Edge<br>135<br>CMI<br>Level<br>136<br>WTOUT<br>Level<br>137<br>ITI<br>Level<br>138|0<br>8<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>32<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>33<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
|OS timer|0||||23 to 16|
||1||||31 to 24|
|Bus state<br>controller|-|||17 to 16<br>34<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
|Watchdog<br>timer|-||||23 to 16|
|Multi-<br>function<br>timer pulse<br>unit 2|0|TGI0A<br>Level<br>139<br>4<br>TGI0B<br>Level<br>140<br>TGI0C<br>Level<br>141<br>TGI0D<br>Level<br>142<br>TGI0V<br>Level<br>143<br>TGI0E<br>Level<br>144<br>TGI0F<br>Level<br>145<br>TGI1A<br>Level<br>146<br>TGI1B<br>Level<br>147<br>TGI1V<br>Level<br>148<br>TGI1U<br>Level<br>149<br>TGI2A<br>Level<br>150<br>TGI2B<br>Level<br>151<br>TGI2V<br>Level<br>152<br>TGI2U<br>Level<br>153<br>TGI3A<br>Level<br>154<br>TGI3B<br>Level<br>155<br>TGI3C<br>Level<br>156<br>TGI3D<br>Level<br>157<br>TGI3V<br>Level<br>158<br>TGI4A<br>Level<br>159|||31 to 24|
|||||25 to 24<br>35<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
||||16<br>9<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>36<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||1||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>37<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||2||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>38<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||3||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>39<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||4||||31 to 24|
|||TGI4B<br>Level<br>160<br>5<br>TGI4C<br>Level<br>161<br>TGI4D<br>Level<br>162<br>TGI4V<br>Level<br>163|0<br>10<br>1<br>2<br>3|1 to 0<br>40<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Reserved||164<br>5<br>165<br>166<br>167<br>168<br>169<br>ADI<br>Level<br>170<br>LMTI<br>Level<br>171<br>SSII0<br>Level<br>172<br>SSIRXI0<br>Level<br>173<br>SSITXI0<br>Level<br>174<br>SSII1<br>Level<br>175<br>SSIRXI1<br>Level<br>176<br>SSITXI1<br>Level<br>177<br>SSII2<br>Level<br>178<br>SSIRTI2<br>Level<br>179<br>SSII3<br>Level<br>180<br>SSIRXI3<br>Level<br>181<br>SSITXI3<br>Level<br>182<br>183<br>184<br>185<br>186<br>187<br>SPDIFI<br>Level<br>188|4<br>10<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|9 to 8<br>41<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>42<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
|12-bit A/D<br>converter|-||||23 to 16|
||||||31 to 24|
|Serial<br>sound<br>interface|0|||25 to 24<br>43<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||1||||31 to 24|
||||16<br>11<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28|1 to 0<br>44<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||2||||23 to 16|
||||||31 to 24|
||3|||9 to 8<br>45<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
|Reserved|||||31 to 24|
|||||17 to 16<br>46<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|Renesas<br>SPDIF<br>interface|-|||25 to 24<br>47|7 to 0|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|I2C bus<br>interface|0|INTIICTEI0<br>Level<br>189<br>5<br>INTIICRI0<br>Edge<br>190<br>INTIICTI0<br>Edge<br>191|29<br>11<br>30<br>31|27 to 26<br>47<br>29 to 28<br>31 to 30|15 to 8|
||||||23 to 16|
||||||31 to 24|
|||INTIICSPI0<br>Level<br>192<br>6<br>INTIICSTI0<br>Level<br>193<br>INTIICNAKI0<br>Level<br>194<br>INTIICALI0<br>Level<br>195<br>INTIICTMOI0<br>Level<br>196<br>INTIICTEI1<br>Level<br>197<br>INTIICRI1<br>Edge<br>198<br>INTIICTI1<br>Edge<br>199<br>INTIICSPI1<br>Level<br>200<br>INTIICSTI1<br>Level<br>201<br>INTIICNAKI1<br>Level<br>202<br>INTIICALI1<br>Level<br>203<br>INTIICTMOI1<br>Level<br>204<br>INTIICTEI2<br>Level<br>205<br>INTIICRI2<br>Edge<br>206<br>INTIICTI2<br>Edge<br>207<br>INTIICSPI2<br>Level<br>208<br>INTIICSTI2<br>Level<br>209<br>INTIICNAKI2<br>Level<br>210<br>INTIICALI2<br>Level<br>211<br>INTIICTMOI2<br>Level<br>212<br>INTIICTEI3<br>Level<br>213<br>INTIICRI3<br>Edge<br>214<br>INTIICTI3<br>Edge<br>215<br>INTIICSPI3<br>Level<br>216<br>INTIICSTI3<br>Level<br>217<br>INTIICNAKI3<br>Level<br>218<br>INTIICALI3<br>Level<br>219<br>INTIICTMOI3<br>Level<br>220|0<br>12<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>48<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>49<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||1||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>50<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>51<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||2||||15 to 8|
||||||23 to 16|
||||||31 to 24|
||||16<br>13<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28|1 to 0<br>52<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>53<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||3||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>54<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>55|7 to 0|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Serial<br>communi-<br>cation<br>interface<br>with FIFO|0|BRI0<br>Level<br>221<br>6<br>ERI0<br>Level<br>222<br>RXI0<br>Level<br>223|29<br>13<br>30<br>31|27 to 26<br>55<br>29 to 28<br>31 to 30|15 to 8|
||||||23 to 16|
||||||31 to 24|
|||TXI0<br>Level<br>224<br>7<br>BRI1<br>Level<br>225<br>ERI1<br>Level<br>226<br>RXI1<br>Level<br>227<br>TXI1<br>Level<br>228<br>BRI2<br>Level<br>229<br>ERI2<br>Level<br>230<br>RXI2<br>Level<br>231<br>TXI2<br>Level<br>232<br>BRI3<br>Level<br>233<br>ERI3<br>Level<br>234<br>RXI3<br>Level<br>235<br>TXI3<br>Level<br>236<br>BRI4<br>Level<br>237<br>ERI4<br>Level<br>238<br>RXI4<br>Level<br>239<br>TXI4<br>Level<br>240<br>241<br>242<br>243<br>244<br>245<br>246<br>247<br>248<br>249<br>250<br>251<br>252|0<br>14<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>56<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||1||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>57<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||2||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>58<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||3||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>59<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||4||||15 to 8|
||||||23 to 16|
||||||31 to 24|
||||16<br>15<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28|1 to 0<br>60<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|Reserved|||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>61<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>62<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>63|7 to 0|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|CAN<br>interface|Com-<br>mon|INTRCANGERR<br>Level<br>253<br>7<br>INTRCANGRECC<br>Level<br>254<br>INTRCAN0REC<br>Level<br>255|29<br>15<br>30<br>31|27 to 26<br>63<br>29 to 28<br>31 to 30|15 to 8|
||||||23 to 16|
||0||||31 to 24|
|||INTRCAN0ERR<br>Level<br>256<br>8<br>INTRCAN0TRX<br>Level<br>257<br>INTRCAN1REC<br>Level<br>258<br>INTRCAN1ERR<br>Level<br>259<br>INTRCAN1TRX<br>Level<br>260<br>261<br>262<br>263<br>264<br>265<br>266<br>267<br>268<br>269<br>SPEI0<br>Level<br>270<br>SPRI0<br>Level<br>271<br>SPTI0<br>Level<br>272<br>SPEI1<br>Level<br>273<br>SPRI1<br>Level<br>274<br>SPTI1<br>Level<br>275<br>SPEI2<br>Level<br>276<br>SPRI2<br>Level<br>277<br>SPTI2<br>Level<br>278<br>279<br>280<br>281<br>282<br>283<br>284|0<br>16<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>64<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||1||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>65<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|Reserved|||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>66<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>67<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
|Renesas<br>serial<br>peripheral<br>interface|0||||23 to 16|
||||||31 to 24|
||||16<br>17<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28|1 to 0<br>68<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||1||||15 to 8|
||||||23 to 16|
||||||31 to 24|
||2|||9 to 8<br>69<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
|Reserved|||||31 to 24|
|||||17 to 16<br>70<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>71|7 to 0|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|IEBus™<br>controller<br>(RZ/A1L<br>only)|-|IEBBTD<br>Edge<br>285<br>8<br>IEBBTERR<br>Edge<br>286<br>IEBBTSTA<br>Edge<br>287|29<br>17<br>30<br>31|27 to 26<br>71<br>29 to 28<br>31 to 30|15 to 8|
||||||23 to 16|
||||||31 to 24|
|||IEBBTV<br>Edge<br>288<br>9<br>ISY<br>Level<br>289<br>IERR<br>Level<br>290<br>ITARG<br>Level<br>291<br>ISEC<br>Level<br>292<br>IBUF<br>Level<br>293<br>IREADY<br>Level<br>294<br>295<br>296<br>297<br>298<br>MMC0<br>Level<br>299<br>MMC1<br>Level<br>300<br>MMC2<br>Level<br>301<br>SDHI0_3<br>Level<br>302<br>SDHI0_0<br>Level<br>303<br>SDHI0_1<br>Level<br>304<br>SDHI1_3<br>Level<br>305<br>SDHI1_0<br>Level<br>306<br>SDHI1_1<br>Level<br>307<br>ARM<br>Level<br>308<br>PRD<br>Level<br>309<br>CUP<br>Level<br>310<br>SCUAI0<br>Level<br>311<br>SCUAI1<br>Level<br>312<br>SCUFDI0<br>Level<br>313<br>SCUFDI1<br>Level<br>314<br>SCUFDI2<br>Level<br>315<br>SCUFDI3<br>Level<br>316<br>SCUFUI0<br>Level<br>317<br>SCUFUI1<br>Level<br>318<br>SCUFUI2<br>Level<br>319|0<br>18<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>72<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|CD-ROM<br>decoder<br>(RZ/A1L<br>only)|-||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>73<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
|Reserved|||||31 to 24|
|||||17 to 16<br>74<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
|MMC host<br>interface|-||||31 to 24|
|||||25 to 24<br>75<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
|SD host<br>interface|0||||23 to 16|
||||||31 to 24|
||||16<br>19<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>76<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||1||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|Realtime<br>clock|-|||9 to 8<br>77<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
|SCUX|-||||31 to 24|
|||||17 to 16<br>78<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>79<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||SCUFUI3<br>Level<br>320<br>10<br>SCUDVI0<br>Level<br>321<br>SCUDVI1<br>Level<br>322<br>SCUDVI2<br>Level<br>323<br>SCUDVI3<br>Level<br>324|0<br>20<br>1<br>2<br>3<br>4|1 to 0<br>80<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>81|7 to 0|

## **Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Media local<br>bus (RZ/<br>A1L only)|<br>-|MLB_CINT<br>Level<br>325<br>10<br>MLB_SINT<br>Level<br>326<br>327<br>328<br>329<br>330<br>LIN0_INT_T<br>Edge<br>331<br>LIN0_INT_R<br>Edge<br>332<br>LIN0_INT_S<br>Edge<br>333<br>LIN0_INT_M<br>Edge<br>334<br>335<br>336<br>337<br>338<br>339<br>340<br>341<br>342<br>343<br>344<br>345<br>346<br>ERI0<br>Level<br>347<br>RXI0<br>Edge<br>348<br>TXI0<br>Edge<br>349<br>TEI0<br>Level<br>350<br>ERI1<br>Level<br>351|5<br>20<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|11 to 10<br>81<br>13 to 12<br>15 to 14|15 to 8|
||||||23 to 16|
|Reserved|||||31 to 24|
|||||17 to 16<br>82<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
|LIN<br>interface<br>(RZ/A1L<br>only)|0||||31 to 24|
|||||25 to 24<br>83<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
|Reserved|||||31 to 24|
||||16<br>21<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>84<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>85<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>86<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
|Serial<br>communi-<br>cation<br>interface|0||||31 to 24|
|||||25 to 24<br>87<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||1||||31 to 24|
|||RXI1<br>Edge<br>352<br>11<br>TXI1<br>Edge<br>353<br>TEI1<br>Level<br>354<br>AVBI_DATA<br>Level<br>355<br>AVBI_ERROR<br>Level<br>356<br>AVBI_MANAGE<br>Level<br>357<br>AVBI_MAC<br>Level<br>358<br>ETHERI<br>Level<br>359<br>AVBI_ERROR<br>360<br>361<br>362<br>363|0<br>22<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11|1 to 0<br>88<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
|Ethernet<br>AVB<br>(RZ/A1LU<br>only)|-||||31 to 24|
|||||9 to 8<br>89<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
|Ethernet<br>controller|-||||31 to 24|
|Reserved||||17 to 16<br>90<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|

## **Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|
|**Module**<br>**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Capture<br>engine unit<br>-|CEUI<br>Level<br>364<br>11<br>365<br>366<br>367<br>368<br>369<br>370<br>371<br>372<br>373<br>374<br>375<br>376<br>377<br>378<br>379<br>380<br>H2XMLB_ERRINT<br>Level<br>381<br>H2XIC1_ERRINT<br>Level<br>382<br>X2HPERI1_ERRINT<br>Level<br>383|12<br>22<br>13<br>14<br>15|25 to 24<br>91<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|Reserved||||15 to 8|
|||||23 to 16|
|||||31 to 24|
|||16<br>23<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>92<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>93<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>94<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>95<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|Internal<br>bus||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||X2HPERI2_ERRINT<br>Level<br>384<br>12<br>X2HPERI34_ERRINT<br>Level<br>385<br>X2HPERI5_ERRINT<br>Level<br>386<br>X2HPERI67_ERRINT<br>Level<br>387<br>X2HDBGR_ERRINT<br>Level<br>388<br>X2HBSC_ERRINT<br>Level<br>389<br>X2HSPI1_ERRINT<br>Level<br>390<br>X2HSPI2_ERRINT<br>Level<br>391<br>PRRI<br>Level<br>392<br>393<br>394<br>395<br>396<br>397<br>398<br>399|0<br>24<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>96<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>97<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>98<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|Reserved||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>99<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|

**Table 7.3 List of Interrupt IDs**

|**Interrupt Source**|**Interrupt Source**|**Register Allocation**|**Register Allocation**|||
|---|---|---|---|---|---|
|**Module**|**Channel**|**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Reserved||400<br>12<br>401<br>402<br>403<br>404<br>405<br>406<br>407<br>408<br>409<br>410<br>411<br>412<br>413<br>414<br>415|16<br>25<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>100<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||9 to 8<br>101<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||17 to 16<br>102<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|||||25 to 24<br>103<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
||||||15 to 8|
||||||23 to 16|
||||||31 to 24|
|Pin<br>interrupts<br>Note: The<br>port name is<br>given in the<br>Channel<br>column for<br>the pin<br>interrupts.|JP0_0|TINT0<br>Edge/Level<br>416<br>13<br>TINT1<br>Edge/Level<br>417<br>TINT2<br>Edge/Level<br>418<br>TINT3<br>Edge/Level<br>419<br>TINT4<br>Edge/Level<br>420<br>TINT5<br>Edge/Level<br>421<br>TINT6<br>Edge/Level<br>422<br>TINT7<br>Edge/Level<br>423<br>TINT8<br>Edge/Level<br>424<br>TINT9<br>Edge/Level<br>425<br>TINT10<br>Edge/Level<br>426<br>TINT11<br>Edge/Level<br>427|0<br>26<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11|1 to 0<br>104<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
||JP0_1||||15 to 8|
||P0_0||||23 to 16|
||P0_1||||31 to 24|
||P0_2|||9 to 8<br>105<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
||P0_3||||15 to 8|
||P1_0||||23 to 16|
||P1_1||||31 to 24|
||P1_2|||17 to 16<br>106<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
||P1_3||||15 to 8|
||P1_4||||23 to 16|
||P1_5||||31 to 24|

## **Table 7.3 List of Interrupt IDs**

|**Table 7.3**<br>**List of Interrupt IDs**|**Table 7.3**<br>**List of Interrupt IDs**|**Table 7.3**<br>**List of Interrupt IDs**|||
|---|---|---|---|---|
|**Interrupt Source**<br>**Register Allocation**|||||
|**Module**|**Channel**<br>**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Pin<br>interrupts<br>Note: The<br>port name is<br>given in the<br>Channel<br>column for<br>the pin<br>interrupts.|P1_6<br>TINT12<br>Edge/Level<br>428<br>13<br>P1_7<br>TINT13<br>Edge/Level<br>429<br>P1_8<br>TINT14<br>Edge/Level<br>430<br>P1_9<br>TINT15<br>Edge/Level<br>431<br>P1_10<br>TINT16<br>Edge/Level<br>432<br>P1_11<br>TINT17<br>Edge/Level<br>433<br>P1_12<br>TINT18<br>Edge/Level<br>434<br>P1_13<br>TINT19<br>Edge/Level<br>435<br>P1_14<br>TINT20<br>Edge/Level<br>436<br>P1_15<br>TINT21<br>Edge/Level<br>437<br>P2_0<br>TINT22<br>Edge/Level<br>438<br>P2_1<br>TINT23<br>Edge/Level<br>439<br>P2_2<br>TINT24<br>Edge/Level<br>440<br>P2_3<br>TINT25<br>Edge/Level<br>441<br>P2_4<br>TINT26<br>Edge/Level<br>442<br>P2_5<br>TINT27<br>Edge/Level<br>443<br>P2_6<br>TINT28<br>Edge/Level<br>444<br>P2_7<br>TINT29<br>Edge/Level<br>445<br>P2_8<br>TINT30<br>Edge/Level<br>446<br>P2_9<br>TINT31<br>Edge/Level<br>447|12<br>26<br>13<br>14<br>15|25 to 24<br>107<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
|||16<br>27<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>108<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>109<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>110<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>111<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||P3_0<br>TINT32<br>Edge/Level<br>448<br>14<br>P3_1<br>TINT33<br>Edge/Level<br>449<br>P3_2<br>TINT34<br>Edge/Level<br>450<br>P3_3<br>TINT35<br>Edge/Level<br>451<br>P3_4<br>TINT36<br>Edge/Level<br>452<br>P3_5<br>TINT37<br>Edge/Level<br>453<br>P3_6<br>TINT38<br>Edge/Level<br>454<br>P3_7<br>TINT39<br>Edge/Level<br>455<br>P3_8<br>TINT40<br>Edge/Level<br>456<br>P3_9<br>TINT41<br>Edge/Level<br>457<br>P3_10<br>TINT42<br>Edge/Level<br>458<br>P3_11<br>TINT43<br>Edge/Level<br>459<br>P3_12<br>TINT44<br>Edge/Level<br>460<br>P3_13<br>TINT45<br>Edge/Level<br>461<br>P3_14<br>TINT46<br>Edge/Level<br>462<br>P3_15<br>TINT47<br>Edge/Level<br>463|0<br>28<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>112<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>113<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>114<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>115<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|

**Table 7.3 List of Interrupt IDs**

|**Table 7.3**<br>**List of Interrupt IDs**|**Table 7.3**<br>**List of Interrupt IDs**|**Table 7.3**<br>**List of Interrupt IDs**|||
|---|---|---|---|---|
|**Interrupt Source**<br>**Register Allocation**|||||
|**Module**|**Channel**<br>**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Pin<br>interrupts<br>Note: The<br>port name is<br>given in the<br>Channel<br>column for<br>the pin<br>interrupts.|P4_0<br>TINT48<br>Edge/Level<br>464<br>14<br>P4_1<br>TINT49<br>Edge/Level<br>465<br>P4_2<br>TINT50<br>Edge/Level<br>466<br>P4_3<br>TINT51<br>Edge/Level<br>467<br>P4_4<br>TINT52<br>Edge/Level<br>468<br>P4_5<br>TINT53<br>Edge/Level<br>469<br>P4_6<br>TINT54<br>Edge/Level<br>470<br>P4_7<br>TINT55<br>Edge/Level<br>471<br>P5_0<br>TINT56<br>Edge/Level<br>472<br>P5_1<br>TINT57<br>Edge/Level<br>473<br>P5_2<br>TINT58<br>Edge/Level<br>474<br>P5_3<br>TINT59<br>Edge/Level<br>475<br>P5_4<br>TINT60<br>Edge/Level<br>476<br>P5_5<br>TINT61<br>Edge/Level<br>477<br>P5_6<br>TINT62<br>Edge/Level<br>478<br>P5_7<br>TINT63<br>Edge/Level<br>479|16<br>29<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>116<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>117<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>118<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>119<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||P5_8<br>TINT64<br>Edge/Level<br>480<br>15<br>P5_9<br>TINT65<br>Edge/Level<br>481<br>P5_10<br>TINT66<br>Edge/Level<br>482<br>P5_11<br>TINT67<br>Edge/Level<br>483<br>P5_12<br>TINT68<br>Edge/Level<br>484<br>P5_13<br>TINT69<br>Edge/Level<br>485<br>P5_14<br>TINT70<br>Edge/Level<br>486<br>P5_15<br>TINT71<br>Edge/Level<br>487<br>P6_0<br>TINT72<br>Edge/Level<br>488<br>P6_1<br>TINT73<br>Edge/Level<br>489<br>P6_2<br>TINT74<br>Edge/Level<br>490<br>P6_3<br>TINT75<br>Edge/Level<br>491<br>P6_4<br>TINT76<br>Edge/Level<br>492<br>P6_5<br>TINT77<br>Edge/Level<br>493<br>P6_6<br>TINT78<br>Edge/Level<br>494<br>P6_7<br>TINT79<br>Edge/Level<br>495|0<br>30<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br>11<br>12<br>13<br>14<br>15|1 to 0<br>120<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>121<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>122<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>123<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|

## **Table 7.3 List of Interrupt IDs**

|**Table 7.3**<br>**List of Interrupt IDs**|**Table 7.3**<br>**List of Interrupt IDs**|**Table 7.3**<br>**List of Interrupt IDs**|||
|---|---|---|---|---|
|**Interrupt Source**<br>**Register Allocation**|||||
|**Module**|**Channel**<br>**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Pin<br>interrupts<br>Note: The<br>port name is<br>given in the<br>Channel<br>column for<br>the pin<br>interrupts.|P6_8<br>TINT80<br>Edge/Level<br>496<br>15<br>P6_9<br>TINT81<br>Edge/Level<br>497<br>P6_10<br>TINT82<br>Edge/Level<br>498<br>P6_11<br>TINT83<br>Edge/Level<br>499<br>P6_12<br>TINT84<br>Edge/Level<br>500<br>P6_13<br>TINT85<br>Edge/Level<br>501<br>P6_14<br>TINT86<br>Edge/Level<br>502<br>P6_15<br>TINT87<br>Edge/Level<br>503<br>P7_0<br>TINT88<br>Edge/Level<br>504<br>P7_1<br>TINT89<br>Edge/Level<br>505<br>P7_2<br>TINT90<br>Edge/Level<br>506<br>P7_3<br>TINT91<br>Edge/Level<br>507<br>P7_4<br>TINT92<br>Edge/Level<br>508<br>P7_5<br>TINT93<br>Edge/Level<br>509<br>P7_6<br>TINT94<br>Edge/Level<br>510<br>P7_7<br>TINT95<br>Edge/Level<br>511|16<br>31<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25<br>26<br>27<br>28<br>29<br>30<br>31|1 to 0<br>124<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>125<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>126<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>127<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||P7_8<br>TINT96<br>Edge/Level<br>512<br>16<br>P7_9<br>TINT97<br>Edge/Level<br>513<br>P7_10<br>TINT98<br>Edge/Level<br>514<br>P7_11<br>TINT99<br>Edge/Level<br>515<br>P8_0<br>TINT100<br>Edge/Level<br>516<br>P8_1<br>TINT101<br>Edge/Level<br>517<br>P8_2<br>TINT102<br>Edge/Level<br>518<br>P8_3<br>TINT103<br>Edge/Level<br>519|0<br>32<br>1<br>2<br>3<br>4<br>5<br>6<br>7|1 to 0<br>128<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>129<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|

## **Table 7.3 List of Interrupt IDs**

|**Table 7.3**<br>**List of Interrupt IDs**|**Table 7.3**<br>**List of Interrupt IDs**|**Table 7.3**<br>**List of Interrupt IDs**|||
|---|---|---|---|---|
|**Interrupt Source**<br>**Register Allocation**|||||
|**Module**|**Channel**<br>**Request Source**<br>**Name**<br>**Interrupt**<br>**Request**<br>**Edge/**<br>**Level**<br>**Inter**<br>**-rupt**<br>**ID**<br>**ICDISRn**<br>**ICDISERn**<br>**ICDICERn**<br>**ICDISPRn**<br>**ICDICPRn**<br>**ICDABRn**|**Bit**<br>**ICDICFRn**|**Bit**<br>**ICDIPRn**<br>**ICDIPTRn**|**Bit**|
|Pin<br>interrupts<br>Note: The<br>port name is<br>given in the<br>Channel<br>column for<br>the pin<br>interrupts.|P8_4<br>TINT104<br>Edge/Level<br>520<br>16<br>P8_5<br>TINT105<br>Edge/Level<br>521<br>P8_6<br>TINT106<br>Edge/Level<br>522<br>P8_7<br>TINT107<br>Edge/Level<br>523<br>P8_8<br>TINT108<br>Edge/Level<br>524<br>P8_9<br>TINT109<br>Edge/Level<br>525<br>P8_10<br>TINT110<br>Edge/Level<br>526<br>P8_11<br>TINT111<br>Edge/Level<br>527<br>P8_12<br>TINT112<br>Edge/Level<br>528<br>P8_13<br>TINT113<br>Edge/Level<br>529<br>P8_14<br>TINT114<br>Edge/Level<br>530<br>P8_15<br>TINT115<br>Edge/Level<br>531<br>P9_0<br>TINT116<br>Edge/Level<br>532<br>P9_1<br>TINT117<br>Edge/Level<br>533<br>P9_2<br>TINT118<br>Edge/Level<br>534<br>P9_3<br>TINT119<br>Edge/Level<br>535<br>P9_4<br>TINT120<br>Edge/Level<br>536<br>P9_5<br>TINT121<br>Edge/Level<br>537|8<br>32<br>9<br>10<br>11<br>12<br>13<br>14<br>15|17 to 16<br>130<br>19 to 18<br>21 to 20<br>23 to 22|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||25 to 24<br>131<br>27 to 26<br>29 to 28<br>31 to 30|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
|||16<br>33<br>17<br>18<br>19<br>20<br>21<br>22<br>23<br>24<br>25|1 to 0<br>132<br>3 to 2<br>5 to 4<br>7 to 6|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||9 to 8<br>133<br>11 to 10<br>13 to 12<br>15 to 14|7 to 0|
|||||15 to 8|
|||||23 to 16|
|||||31 to 24|
||||17 to 16<br>134<br>19 to 18|7 to 0|
|||||15 to 8|

## 7.6 Operation

## 7.6.1 Initial Settings

For details on the registers for making initial settings and the procedures for settings in general, see the Arm Generic Interrupt Controller Architecture Specification and the PrimeCell[®] Generic Interrupt Controller (PL390) Technical Reference Manual from Arm. Figure 7.2 illustrates the flow of initial settings.

**==> picture [273 x 359] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start initial settings<br>GIC interrupt request acknowledgement initial setting 1<br>(1)  ICDISRn  Interrupt security register<br>For ICDISR0 to ICDISR16, set H'00000000.<br>(2)  ICDICFRn  Interrupt configuration register<br>Set ICDICFR0 to ICDICFR33 to the values in table 7.4.<br>Set ICDICFR26 to ICDICFR33 to the mode for detecting pin interrupts.<br>(3)  ICDIPRn  Interrupt priority register<br>Set the priority levels for interrupts with the corresponding IDs in the fields<br>of ICDIPR0 to ICDIPR134.<br>(4)  ICDIPTRn  Target CPU setting<br>Set the value H'01 for interrupts with the corresponding IDs in the fields of<br>ICDIPTR8 to ICDIPTR134. (ICDIPTR0 to ICDIPTR7 are read-only.)<br>(5) ICDISERn  Interrupt set-enable register<br>For interrupts which are to be enabled, set the corresponding bits of<br>ICDISER0 to ICDISER16 to 1.<br>CPU interface initial setting<br>(1)  ICCPMR  Interrupt priority mask register<br>Specify the priority level at and above which the CPU will be notified.<br>(2)  ICCBPR  Binary point register<br>Set the separation point for the fractional part of the priority value field.<br>(3)  ICCICR  CPU interface control register<br>Set this register to H'00000003.<br>GIC interrupt request acknowledgement initial setting 2<br>(1)  ICDDCR  Distributor control register<br>Set the enable bit to 1.<br>CPU initial setting<br>(1)  CSPR<br>Clear the I and F bits to 0.<br>Initial settings<br>completed<br>**----- End of picture text -----**<br>

**Figure 7.2**

**Flow of Initial Settings**

**Table 7.4 ICDICFRn Interrupt Configuration Register Settings**

|**Register Name**|**Setting**|**Interrupt ID**|
|---|---|---|
|ICDICFR0|H'AAAAAAAA|15 to 0|
|ICDICFR1|H'00000055|31 to 16|
|ICDICFR2|H'FFFD5555|47 to 32|
|ICDICFR3|H'555FFFFF|63 to 48|
|ICDICFR4|H'55555555|79 to 64|
|ICDICFR5|H'55555555|95 to 80|
|ICDICFR6|H'55555555|111 to 96|
|ICDICFR7|H'55555555|127 to 112|
|ICDICFR8|H'5555F555|143 to 128|
|ICDICFR9|H'55555555|159 to 144|
|ICDICFR10|H'55555555|175 to 160|
|ICDICFR11|H'F5555555|191 to 176|
|ICDICFR12|H'F555F555|207 to 192|
|ICDICFR13|H'5555F555|223 to 208|
|ICDICFR14|H'55555555|239 to 224|
|ICDICFR15|H'55555555|255 to 240|
|ICDICFR16|H'55555555|271 to 256|
|ICDICFR17|H'FD555555|287 to 272|
|ICDICFR18|H'55555557|303 to 288|
|ICDICFR19|H'55555555|319 to 304|
|ICDICFR20|H'7FD55555|335 to 320|
|ICDICFR21|H'5F555555|351 to 336|
|ICDICFR22|H'FD55555F|367 to 352|
|ICDICFR23|H'55555557|383 to 368|
|ICDICFR24|H'55555555|399 to 384|
|ICDICFR25|H'55555555|415 to 400|
|ICDICFR26*1|H'55555555|431 to 416|
|ICDICFR27*1|H'55555555|447 to 432|
|ICDICFR28*1|H'55555555|463 to 448|
|ICDICFR29*1|H'55555555|479 to 464|
|ICDICFR30*1|H'55555555|495 to 480|
|ICDICFR31*1|H'55555555|511 to 496|
|ICDICFR32*1|H'55555555|527 to 512|
|ICDICFR33*1|H'55555555|537 to 528|

Note 1. Edge or level detection can be selected for IDs corresponding to pin interrupts. The settings in the above table select level detection.

## 7.6.2 Flow of Interrupt Operations

For details on operation involved in interrupt generation, see the ArmGeneric Interrupt Controller Architecture Specification and the PrimeCell[®] Generic Interrupt Controller (PL390) Technical Reference Manual from Arm. Figure 7.3 shows the flow of interrupt operations.

**==> picture [392 x 537] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transmit the interrupt  Transmit the interrupt<br>request to INTC request to the CPU interface<br>Is the priority of<br>No the interrupt at the CPU interface<br>greater than or equal to<br>the ICCPMR  INTC operation<br>value?<br>Yes<br>Interrupt request not  Transmit the interrupt<br>START transmitted to CPU request to CPU<br>Place the work space on<br>Interrupt initial setting the stack and branch to  CPU operation<br>Interrupt enabled the interrupt handler.<br>Normal processing  Read ICCHPIR  [Note 1]<br>routine<br>Interrupt source<br>generated<br>Acquire the interrupt ID<br>from ICCIAR  [Note 1]<br>Branch to the interrupt processing<br>routine for the given interrupt ID.<br>No<br>Level sensitive?<br>END<br>Yes CPU operation<br>(User software)<br>Clear the source flag at the<br>source of the request [Note 2]<br>Read the source flag at the<br>source of the request<br>Interrupt processing  Interrupt processing<br>completed<br>Write the interrupt ID to ICCEOIR and<br>execute the return instruction.<br>Restore the work space. CPU operation<br>Return from the interrupt handler.<br>Note 1. Read ICCHPIR. Then, read ICCIAR. If reading is not in this order, ICCIAR may be read before it completely reflects processing through<br>the CPU interface. Consequently, wrong interrupt IDs may be read.<br>Note 2. When the interrupt is one for which clearing of the flag for the interrupt request before interrupt processing is not possible, the flag<br>should be cleared after interrupt processing.<br>**----- End of picture text -----**<br>

**Figure 7.3 Flow of Interrupt Operations**

## 7.7 Data Transfer with Interrupt Request Signals

Interrupt request signals can be used to activate the direct memory access controller and transfer data. Interrupt sources for which the direct memory access controller is designated as the destination by DMA extension resource selectors 0 to 7 are masked and requests from them are not input to the interrupt controller. Figure 7.4 shows a block diagram of interrupt control. For details, see section 9, Direct Memory Access Controller .

**==> picture [367 x 205] intentionally omitted <==**

**----- Start of picture text -----**<br>
Direct memory access controller<br>Interrupt source flag clearing<br>(by the direct memory Data<br>access controller) transfer<br>Activating   control<br>Activating   source selected logic<br>source<br>Interrupt source selection<br>logic<br>Activating source not selected<br>Interrupt source<br>(not specified as a direct memory access controller activating source)<br>Interrupt CPU interrupt source<br>CPU<br>controller<br>**----- End of picture text -----**<br>

**Figure 7.4 Interrupt Control Block Diagram**

## 7.7.1 Handling Interrupt Request Signals as Sources for CPU Interrupt but Not Direct Memory Access Controller Activating

1. Do not select direct memory access controller activating sources.

2. When interrupts occur, interrupt requests are sent to the CPU.

3. The CPU clears the interrupt source and performs the necessary processing in the interrupt exception service routine.

## 7.7.2 Handling Interrupt Request Signals as Sources for Activating Direct Memory Access Controller but Not CPU Interrupt

1. Select direct memory access controller activating sources.

2. Activating sources are applied to the direct memory access controller when interrupts occur.

3. The direct memory access controller clears the interrupt sources when starting transfer.

## 7.8 Usage Note

## 7.8.1 Timing to Clear Interrupt Source

Clear the interrupt source flag to 0 in the interrupt exception handler. It takes some time to clear an interrupt in the CPU after clearing the interrupt source flag to 0. Read the interrupt source flag after clearing it to ensure that the interrupt request that should have been cleared is not received again erroneously. After that, execute the return instruction.

## 7.8.2 Notes on Selecting IRQ Interrupt Pin Functions

While the corresponding setting in interrupt control register 1 (ICR1) is for interrupt requests to be detected on falling edges or both edges of an IRQn input and the current input on the pin is at the low level, this will be detected as a falling edge and thus an interrupt when the pin function is switched to the IRQ interrupt function.

## 7.8.3 Notes on Reading Interrupt ID Values from Interrupt Acknowledge Register (ICCIAR)

If an interrupt ID value read from the interrupt acknowledge register (ICCIAR) is 0, the interrupt notice may be wrong. At that time, confirm the interrupt state before proceeding with interrupt processing.

When the interrupt ID is read as 0, the interrupt state can be confirmed by using bit 0 in the active bit register 0 (ICDABR0).

If the interrupt state is inactive, the interrupt notice is wrong and no interrupt processing is required.

Return from interrupt processing after writing the same value as the setting value to the interrupt priority register 0 (ICDIPR0).

If the interrupt state is active, the interrupt notice is correct. Proceed with interrupt processing.

If an interrupt ID value read from the interrupt acknowledge register (ICCIAR) is 1022 or 1023, return from interrupt processing after writing the same value as the setting value to the interrupt priority register 0 (ICDIPR0).

## 7.8.4 Notes on Using IRQ Pins as Triggers for Release from Standby when Software Standby is in Use

To use an IRQ pin as the trigger for release from standby when software standby is in use, execute the following processing.

## (1) When the mode setting for an IRQ pin has been switched from the alternative mode to the port mode

Set the IRQ sense select bits corresponding to the given IRQ pin in interrupt control register 1 (ICR1) to the initial value, 00 (interrupt requests being detected as the low level of the IRQn input).

## (2) When the mode setting for an IRQ pin has been switched from the port mode to the alternative mode

After switching the pin mode setting, make the setting of the IRQ sense select bits corresponding to the given IRQ pin in the following sequence. To start with, set the IRQ sense select bits in interrupt control register 1 (ICR1) to the initial value, 00 (interrupt requests being detected as the low level of the IRQn input), and then set them to the desired value, as described below.

- When the IRQ pin is to be used with the IRQ sense select bits set to 01 (interrupt requests being detected on falling edges of the IRQn input)

   - Set these bits to 00 (detection as the low level) *[1] and then to 01 (detection on falling edges).

- When the IRQ pin is to be used with the IRQ sense select bits set to 10 (interrupt requests being detected on rising edges of the IRQn input)

   - Set these bits to 00 (detection as the low level) *[1] and then to 10 (detection on rising edges).

- When the IRQ pin is to be used with the IRQ sense select bits set to 11 (interrupt requests being detected on the both edges of the IRQn input)

Set these bits to 00 (detection as the low level) *[1] and then to 11 (detection on the both edges).

- Note 1. This setting is for the detection of interrupt requests when the IRQ pin is at the low level. Make the appropriate settings so that the interrupt function does not operate, i.e. the interrupt is ignored, during the period from setting of the IRQ pin mode to setting of the IRQ sense select bits.
