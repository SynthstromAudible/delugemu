# 46. List of Registers

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2530–2760. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 46.1 Register Addresses

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Secondary cache|Cache ID Register|reg0_cache_id|32|H'3FFFF000|32|
||Cache Type Register|reg0_cache_type|32|H'3FFFF004|32|
||Control Register|reg1_control|32|H'3FFFF100|32|
||Auxiliary Control Register|reg1_aux_control|32|H'3FFFF104|32|
||Tag RAM Latency Control Register|reg1_tag_ram_control|32|H'3FFFF108|32|
||Data RAM Latency Control Register|reg1_data_ram_control|32|H'3FFFF10C|32|
||Event Counter Control Register|reg2_ev_counter_ctrl|32|H'3FFFF200|32|
||Event Counter Configuration Register 1|reg2_ev_counter1_cfg|32|H'3FFFF204|32|
||Event Counter Configuration Register 0|reg2_ev_counter0_cfg|32|H'3FFFF208|32|
||Event counter value register 1|reg2_ev_counter1|32|H'3FFFF20C|32|
||Event counter value register 0|reg2_ev_counter0|32|H'3FFFF210|32|
||Interrupt Mask Register|reg2_int_mask|32|H'3FFFF214|32|
||Masked Interrupt Status Register|reg2_int_mask_status|32|H'3FFFF218|32|
||Raw Interrupt Status Register|reg2_int_raw_status|32|H'3FFFF21C|32|
||Interrupt Clear Register|reg2_int_clear|32|H'3FFFF220|32|
||Cache Sync Register|reg7_cache_sync|32|H'3FFFF730|32|
||Invalidate Line by PA Register|reg7_inv_pa|32|H'3FFFF770|32|
||Invalidate by Way Register|reg7_inv_way|32|H'3FFFF77C|32|
||Clean Line by PA Register|reg7_clean_pa|32|H'3FFFF7B0|32|
||Clean Line by Set/Way Register|reg7_clean_index|32|H'3FFFF7B8|32|
||Clean by Way Register|reg7_clean_way|32|H'3FFFF7BC|32|
||Clean and Invalidate Line by PA Register|reg7_clean_inv_pa|32|H'3FFFF7F0|32|
||Clean and Invalidate Line by Set/Way Register|reg7_clean_inv_index|32|H'3FFFF7F8|32|
||Clean and Invalidate by Way Register|reg7_clean_inv_way|32|H'3FFFF7FC|32|
||Data Lockdown 0 Register|reg9_d_lockdown0|32|H'3FFFF900|32|
||Instruction Lockdown 0 Register|reg9_i_lockdown0|32|H'3FFFF904|32|
||Data Lockdown 1 Register|reg9_d_lockdown1|32|H'3FFFF908|32|
||Instruction Lockdown 1 Register|reg9_i_lockdown1|32|H'3FFFF90C|32|
||Data Lockdown 2 Register|reg9_d_lockdown2|32|H'3FFFF910|32|
||Instruction Lockdown 2 Register|reg9_i_lockdown2|32|H'3FFFF914|32|
||Data Lockdown 3 Register|reg9_d_lockdown3|32|H'3FFFF918|32|
||Instruction Lockdown 3 Register|reg9_i_lockdown3|32|H'3FFFF91C|32|
||Data Lockdown 4 Register|reg9_d_lockdown4|32|H'3FFFF920|32|
||Instruction Lockdown 4 Register|reg9_i_lockdown4|32|H'3FFFF924|32|
||Data Lockdown 5 Register|reg9_d_lockdown5|32|H'3FFFF928|32|
||Instruction Lockdown 5 Register|reg9_i_lockdown5|32|H'3FFFF92C|32|
||Data Lockdown 6 Register|reg9_d_lockdown6|32|H'3FFFF930|32|
||Instruction Lockdown 6 Register|reg9_i_lockdown6|32|H'3FFFF934|32|
||Data Lockdown 7 Register|reg9_d_lockdown7|32|H'3FFFF938|32|
||Instruction Lockdown 7 Register|reg9_i_lockdown7|32|H'3FFFF93C|32|
||Lockdown by Line Enable Register|reg9_lock_line_en|32|H'3FFFF950|32|
||Unlock All Lines Register|reg9_unlock_way|32|H'3FFFF954|32|
||Address Filtering Start Register|reg12_addr_filtering_start|32|H'3FFFFC00|32|
||Address Filtering End Register|reg12_addr_filtering_end|32|H'3FFFFC04|32|
||Debug Control Register|reg15_debug_ctrl|32|H'3FFFFF40|32|
||Prefetch Control Register|reg15_prefetch_ctrl|32|H'3FFFFF60|32|
||Power Control Register|reg15_power_ctrl|32|H'3FFFFF80|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|LSI internal bus|Remap register|RMPR|32|H'FCFE1A00|32|
||AXI bus control register 0|AXIBUSCTL0|32|H'FCFE1A04|32|
||AXI bus control register 2|AXIBUSCTL2|32|H'FCFE1A0C|32|
||AXI bus control register 5*1|AXIBUSCTL5|32|H'FCFE1A18|32|
||AXI bus control register 6|AXIBUSCTL6|32|H'FCFE1A1C|32|
||AXI bus control register 7|AXIBUSCTL7|32|H'FCFE1A20|32|
||AXI bus response error interrupt control register 0|AXIRERRCTL0|32|H'FCFE1A30|32|
||AXI bus response error interrupt control register 2|AXIRERRCTL2|32|H'FCFE1A38|32|
||AXI bus response error status register 0|AXIRERRST0|32|H'FCFE1A40|32|
||AXI bus response error status register 2|AXIRERRST2|32|H'FCFE1A48|32|
||AXI bus response error clear register 0|AXIRERRCLR0|32|H'FCFE1A50|32|
||AXI bus response error clear register 2|AXIRERRCLR2|32|H'FCFE1A58|32|
|Clock pulse generator|Frequency control register|FRQCR|16|H'FCFE0010|16|
|Interrupt controller|Interrupt control register 0|ICR0|16|H'FCFEF800|16|
||Interrupt control register 1|ICR1|16|H'FCFEF802|16|
||IRQ interrupt request register|IRQRR|16|H'FCFEF804|16|
||Distributor control register|ICDDCR|32|H’E8201000|32|
||Interrupt controller type register|ICDICTR|32|H’E8201004|32|
||Distributor implementer identification register|ICDIIDR|32|H’E8201008|32|
||Interrupt security register 0|ICDISR0|32|H'E8201080|32|
||Interrupt security register 1|ICDISR1|32|H'E8201084|32|
||Interrupt security register 2|ICDISR2|32|H'E8201088|32|
||Interrupt security register 3|ICDISR3|32|H'E820108C|32|
||Interrupt security register 4|ICDISR4|32|H'E8201090|32|
||Interrupt security register 5|ICDISR5|32|H'E8201094|32|
||Interrupt security register 6|ICDISR6|32|H'E8201098|32|
||Interrupt security register 7|ICDISR7|32|H'E820109C|32|
||Interrupt security register 8|ICDISR8|32|H'E82010A0|32|
||Interrupt security register 9|ICDISR9|32|H'E82010A4|32|
||Interrupt security register 10|ICDISR10|32|H'E82010A8|32|
||Interrupt security register 11|ICDISR11|32|H'E82010AC|32|
||Interrupt security register 12|ICDISR12|32|H'E82010B0|32|
||Interrupt security register 13|ICDISR13|32|H'E82010B4|32|
||Interrupt security register 14|ICDISR14|32|H'E82010B8|32|
||Interrupt security register 15|ICDISR15|32|H'E82010BC|32|
||Interrupt security register 16|ICDISR16|32|H'E82010C0|32|
||Interrupt set-enable register 0|ICDISER0|32|H'E8201100|32|
||Interrupt set-enable register 1|ICDISER1|32|H'E8201104|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt set-enable register 2|ICDISER2|32|H'E8201108|32|
||Interrupt set-enable register 3|ICDISER3|32|H'E820110C|32|
||Interrupt set-enable register 4|ICDISER4|32|H'E8201110|32|
||Interrupt set-enable register 5|ICDISER5|32|H'E8201114|32|
||Interrupt set-enable register 6|ICDISER6|32|H'E8201118|32|
||Interrupt set-enable register 7|ICDISER7|32|H'E820111C|32|
||Interrupt set-enable register 8|ICDISER8|32|H'E8201120|32|
||Interrupt set-enable register 9|ICDISER9|32|H'E8201124|32|
||Interrupt set-enable register 10|ICDISER10|32|H'E8201128|32|
||Interrupt set-enable register 11|ICDISER11|32|H'E820112C|32|
||Interrupt set-enable register 12|ICDISER12|32|H'E8201130|32|
||Interrupt set-enable register 13|ICDISER13|32|H'E8201134|32|
||Interrupt set-enable register 14|ICDISER14|32|H'E8201138|32|
||Interrupt set-enable register 15|ICDISER15|32|H'E820113C|32|
||Interrupt set-enable register 16|ICDISER16|32|H'E8201140|32|
||Interrupt clear-enable register 0|ICDICER0|32|H'E8201180|32|
||Interrupt clear-enable register 1|ICDICER1|32|H'E8201184|32|
||Interrupt clear-enable register 2|ICDICER2|32|H'E8201188|32|
||Interrupt clear-enable register 3|ICDICER3|32|H'E820118C|32|
||Interrupt clear-enable register 4|ICDICER4|32|H'E8201190|32|
||Interrupt clear-enable register 5|ICDICER5|32|H'E8201194|32|
||Interrupt clear-enable register 6|ICDICER6|32|H'E8201198|32|
||Interrupt clear-enable register 7|ICDICER7|32|H'E820119C|32|
||Interrupt clear-enable register 8|ICDICER8|32|H'E82011A0|32|
||Interrupt clear-enable register 9|ICDICER9|32|H'E82011A4|32|
||Interrupt clear-enable register 10|ICDICER10|32|H'E82011A8|32|
||Interrupt clear-enable register 11|ICDICER11|32|H'E82011AC|32|
||Interrupt clear-enable register 12|ICDICER12|32|H'E82011B0|32|
||Interrupt clear-enable register 13|ICDICER13|32|H'E82011B4|32|
||Interrupt clear-enable register 14|ICDICER14|32|H'E82011B8|32|
||Interrupt clear-enable register 15|ICDICER15|32|H'E82011BC|32|
||Interrupt clear-enable register 16|ICDICER16|32|H'E82011C0|32|
||Interrupt set-pending register 0|ICDISPR0|32|H'E8201200|32|
||Interrupt set-pending register 1|ICDISPR1|32|H'E8201204|32|
||Interrupt set-pending register 2|ICDISPR2|32|H'E8201208|32|
||Interrupt set-pending register 3|ICDISPR3|32|H'E820120C|32|
||Interrupt set-pending register 4|ICDISPR4|32|H'E8201210|32|
||Interrupt set-pending register 5|ICDISPR5|32|H'E8201214|32|
||Interrupt set-pending register 6|ICDISPR6|32|H'E8201218|32|
||Interrupt set-pending register 7|ICDISPR7|32|H'E820121C|32|
||Interrupt set-pending register 8|ICDISPR8|32|H'E8201220|32|
||Interrupt set-pending register 9|ICDISPR9|32|H'E8201224|32|
||Interrupt set-pending register 10|ICDISPR10|32|H'E8201228|32|
||Interrupt set-pending register 11|ICDISPR11|32|H'E820122C|32|
||Interrupt set-pending register 12|ICDISPR12|32|H'E8201230|32|
||Interrupt set-pending register 13|ICDISPR13|32|H'E8201234|32|
||Interrupt set-pending register 14|ICDISPR14|32|H'E8201238|32|
||Interrupt set-pending register 15|ICDISPR15|32|H'E820123C|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt set-pending register 16|ICDISPR16|32|H'E8201240|32|
||Interrupt clear-pending register 0|ICDICPR0|32|H'E8201280|32|
||Interrupt clear-pending register 1|ICDICPR1|32|H'E8201284|32|
||Interrupt clear-pending register 2|ICDICPR2|32|H'E8201288|32|
||Interrupt clear-pending register 3|ICDICPR3|32|H'E820128C|32|
||Interrupt clear-pending register 4|ICDICPR4|32|H'E8201290|32|
||Interrupt clear-pending register 5|ICDICPR5|32|H'E8201294|32|
||Interrupt clear-pending register 6|ICDICPR6|32|H'E8201298|32|
||Interrupt clear-pending register 7|ICDICPR7|32|H'E820129C|32|
||Interrupt clear-pending register 8|ICDICPR8|32|H'E82012A0|32|
||Interrupt clear-pending register 9|ICDICPR9|32|H'E82012A4|32|
||Interrupt clear-pending register 10|ICDICPR10|32|H'E82012A8|32|
||Interrupt clear-pending register 11|ICDICPR11|32|H'E82012AC|32|
||Interrupt clear-pending register 12|ICDICPR12|32|H'E82012B0|32|
||Interrupt clear-pending register 13|ICDICPR13|32|H'E82012B4|32|
||Interrupt clear-pending register 14|ICDICPR14|32|H'E82012B8|32|
||Interrupt clear-pending register 15|ICDICPR15|32|H'E82012BC|32|
||Interrupt clear-pending register 16|ICDICPR16|32|H'E82012C0|32|
||Active bit register 0|ICDABR0|32|H'E8201300|32|
||Active bit register 1|ICDABR1|32|H'E8201304|32|
||Active bit register 2|ICDABR2|32|H'E8201308|32|
||Active bit register 3|ICDABR3|32|H'E820130C|32|
||Active bit register 4|ICDABR4|32|H'E8201310|32|
||Active bit register 5|ICDABR5|32|H'E8201314|32|
||Active bit register 6|ICDABR6|32|H'E8201318|32|
||Active bit register 7|ICDABR7|32|H'E820131C|32|
||Active bit register 8|ICDABR8|32|H'E8201320|32|
||Active bit register 9|ICDABR9|32|H'E8201324|32|
||Active bit register 10|ICDABR10|32|H'E8201328|32|
||Active bit register 11|ICDABR11|32|H'E820132C|32|
||Active bit register 12|ICDABR12|32|H'E8201330|32|
||Active bit register 13|ICDABR13|32|H'E8201334|32|
||Active bit register 14|ICDABR14|32|H'E8201338|32|
||Active bit register 15|ICDABR15|32|H'E820133C|32|
||Active bit register 16|ICDABR16|32|H'E8201340|32|
||Interrupt priority register 0|ICDIPR0|32|H'E8201400|32|
||Interrupt priority register 1|ICDIPR1|32|H'E8201404|32|
||Interrupt priority register 2|ICDIPR2|32|H'E8201408|32|
||Interrupt priority register 3|ICDIPR3|32|H'E820140C|32|
||Interrupt priority register 4|ICDIPR4|32|H'E8201410|32|
||Interrupt priority register 5|ICDIPR5|32|H'E8201414|32|
||Interrupt priority register 6|ICDIPR6|32|H'E8201418|32|
||Interrupt priority register 7|ICDIPR7|32|H'E820141C|32|
||Interrupt priority register 8|ICDIPR8|32|H'E8201420|32|
||Interrupt priority register 9|ICDIPR9|32|H'E8201424|32|
||Interrupt priority register 10|ICDIPR10|32|H'E8201428|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt priority register 11|ICDIPR11|32|H'E820142C|32|
||Interrupt priority register 12|ICDIPR12|32|H'E8201430|32|
||Interrupt priority register 13|ICDIPR13|32|H'E8201434|32|
||Interrupt priority register 14|ICDIPR14|32|H'E8201438|32|
||Interrupt priority register 15|ICDIPR15|32|H'E820143C|32|
||Interrupt priority register 16|ICDIPR16|32|H'E8201440|32|
||Interrupt priority register 17|ICDIPR17|32|H'E8201444|32|
||Interrupt priority register 18|ICDIPR18|32|H'E8201448|32|
||Interrupt priority register 19|ICDIPR19|32|H'E820144C|32|
||Interrupt priority register 20|ICDIPR20|32|H'E8201450|32|
||Interrupt priority register 21|ICDIPR21|32|H'E8201454|32|
||Interrupt priority register 22|ICDIPR22|32|H'E8201458|32|
||Interrupt priority register 23|ICDIPR23|32|H'E820145C|32|
||Interrupt priority register 24|ICDIPR24|32|H'E8201460|32|
||Interrupt priority register 25|ICDIPR25|32|H'E8201464|32|
||Interrupt priority register 26|ICDIPR26|32|H'E8201468|32|
||Interrupt priority register 27|ICDIPR27|32|H'E820146C|32|
||Interrupt priority register 28|ICDIPR28|32|H'E8201470|32|
||Interrupt priority register 29|ICDIPR29|32|H'E8201474|32|
||Interrupt priority register 30|ICDIPR30|32|H'E8201478|32|
||Interrupt priority register 31|ICDIPR31|32|H'E820147C|32|
||Interrupt priority register 32|ICDIPR32|32|H'E8201480|32|
||Interrupt priority register 33|ICDIPR33|32|H'E8201484|32|
||Interrupt priority register 34|ICDIPR34|32|H'E8201488|32|
||Interrupt priority register 35|ICDIPR35|32|H'E820148C|32|
||Interrupt priority register 36|ICDIPR36|32|H'E8201490|32|
||Interrupt priority register 37|ICDIPR37|32|H'E8201494|32|
||Interrupt priority register 38|ICDIPR38|32|H'E8201498|32|
||Interrupt priority register 39|ICDIPR39|32|H'E820149C|32|
||Interrupt priority register 40|ICDIPR40|32|H'E82014A0|32|
||Interrupt priority register 41|ICDIPR41|32|H'E82014A4|32|
||Interrupt priority register 42|ICDIPR42|32|H'E82014A8|32|
||Interrupt priority register 43|ICDIPR43|32|H'E82014AC|32|
||Interrupt priority register 44|ICDIPR44|32|H'E82014B0|32|
||Interrupt priority register 45|ICDIPR45|32|H'E82014B4|32|
||Interrupt priority register 46|ICDIPR46|32|H'E82014B8|32|
||Interrupt priority register 47|ICDIPR47|32|H'E82014BC|32|
||Interrupt priority register 48|ICDIPR48|32|H'E82014C0|32|
||Interrupt priority register 49|ICDIPR49|32|H'E82014C4|32|
||Interrupt priority register 50|ICDIPR50|32|H'E82014C8|32|
||Interrupt priority register 51|ICDIPR51|32|H'E82014CC|32|
||Interrupt priority register 52|ICDIPR52|32|H'E82014D0|32|
||Interrupt priority register 53|ICDIPR53|32|H'E82014D4|32|
||Interrupt priority register 54|ICDIPR54|32|H'E82014D8|32|
||Interrupt priority register 55|ICDIPR55|32|H'E82014DC|32|
||Interrupt priority register 56|ICDIPR56|32|H'E82014E0|32|
||Interrupt priority register 57|ICDIPR57|32|H'E82014E4|32|
||Interrupt priority register 58|ICDIPR58|32|H'E82014E8|32|
||Interrupt priority register 59|ICDIPR59|32|H'E82014EC|32|
||Interrupt priority register 60|ICDIPR60|32|H'E82014F0|32|
||Interrupt priority register 61|ICDIPR61|32|H'E82014F4|32|
||Interrupt priority register 62|ICDIPR62|32|H'E82014F8|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt priority register 63|ICDIPR63|32|H'E82014FC|32|
||Interrupt priority register 64|ICDIPR64|32|H'E8201500|32|
||Interrupt priority register 65|ICDIPR65|32|H'E8201504|32|
||Interrupt priority register 66|ICDIPR66|32|H'E8201508|32|
||Interrupt priority register 67|ICDIPR67|32|H'E820150C|32|
||Interrupt priority register 68|ICDIPR68|32|H'E8201510|32|
||Interrupt priority register 69|ICDIPR69|32|H'E8201514|32|
||Interrupt priority register 70|ICDIPR70|32|H'E8201518|32|
||Interrupt priority register 71|ICDIPR71|32|H'E820151C|32|
||Interrupt priority register 72|ICDIPR72|32|H'E8201520|32|
||Interrupt priority register 73|ICDIPR73|32|H'E8201524|32|
||Interrupt priority register 74|ICDIPR74|32|H'E8201528|32|
||Interrupt priority register 75|ICDIPR75|32|H'E820152C|32|
||Interrupt priority register 76|ICDIPR76|32|H'E8201530|32|
||Interrupt priority register 77|ICDIPR77|32|H'E8201534|32|
||Interrupt priority register 78|ICDIPR78|32|H'E8201538|32|
||Interrupt priority register 79|ICDIPR79|32|H'E820153C|32|
||Interrupt priority register 80|ICDIPR80|32|H'E8201540|32|
||Interrupt priority register 81|ICDIPR81|32|H'E8201544|32|
||Interrupt priority register 82|ICDIPR82|32|H'E8201548|32|
||Interrupt priority register 83|ICDIPR83|32|H'E820154C|32|
||Interrupt priority register 84|ICDIPR84|32|H'E8201550|32|
||Interrupt priority register 85|ICDIPR85|32|H'E8201554|32|
||Interrupt priority register 86|ICDIPR86|32|H'E8201558|32|
||Interrupt priority register 87|ICDIPR87|32|H'E820155C|32|
||Interrupt priority register 88|ICDIPR88|32|H'E8201560|32|
||Interrupt priority register 89|ICDIPR89|32|H'E8201564|32|
||Interrupt priority register 90|ICDIPR90|32|H'E8201568|32|
||Interrupt priority register 91|ICDIPR91|32|H'E820156C|32|
||Interrupt priority register 92|ICDIPR92|32|H'E8201570|32|
||Interrupt priority register 93|ICDIPR93|32|H'E8201574|32|
||Interrupt priority register 94|ICDIPR94|32|H'E8201578|32|
||Interrupt priority register 95|ICDIPR95|32|H'E820157C|32|
||Interrupt priority register 96|ICDIPR96|32|H'E8201580|32|
||Interrupt priority register 97|ICDIPR97|32|H'E8201584|32|
||Interrupt priority register 98|ICDIPR98|32|H'E8201588|32|
||Interrupt priority register 99|ICDIPR99|32|H'E820158C|32|
||Interrupt priority register 100|ICDIPR100|32|H'E8201590|32|
||Interrupt priority register 101|ICDIPR101|32|H'E8201594|32|
||Interrupt priority register 102|ICDIPR102|32|H'E8201598|32|
||Interrupt priority register 103|ICDIPR103|32|H'E820159C|32|
||Interrupt priority register 104|ICDIPR104|32|H'E82015A0|32|
||Interrupt priority register 105|ICDIPR105|32|H'E82015A4|32|
||Interrupt priority register 106|ICDIPR106|32|H'E82015A8|32|
||Interrupt priority register 107|ICDIPR107|32|H'E82015AC|32|
||Interrupt priority register 108|ICDIPR108|32|H'E82015B0|32|
||Interrupt priority register 109|ICDIPR109|32|H'E82015B4|32|
||Interrupt priority register 110|ICDIPR110|32|H'E82015B8|32|
||Interrupt priority register 111|ICDIPR111|32|H'E82015BC|32|
||Interrupt priority register 112|ICDIPR112|32|H'E82015C0|32|
||Interrupt priority register 113|ICDIPR113|32|H'E82015C4|32|
||Interrupt priority register 114|ICDIPR114|32|H'E82015C8|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt priority register 115|ICDIPR115|32|H'E82015CC|32|
||Interrupt priority register 116|ICDIPR116|32|H'E82015D0|32|
||Interrupt priority register 117|ICDIPR117|32|H'E82015D4|32|
||Interrupt priority register 118|ICDIPR118|32|H'E82015D8|32|
||Interrupt priority register 119|ICDIPR119|32|H'E82015DC|32|
||Interrupt priority register 120|ICDIPR120|32|H'E82015E0|32|
||Interrupt priority register 121|ICDIPR121|32|H'E82015E4|32|
||Interrupt priority register 122|ICDIPR122|32|H'E82015E8|32|
||Interrupt priority register 123|ICDIPR123|32|H'E82015EC|32|
||Interrupt priority register 124|ICDIPR124|32|H'E82015F0|32|
||Interrupt priority register 125|ICDIPR125|32|H'E82015F4|32|
||Interrupt priority register 126|ICDIPR126|32|H'E82015F8|32|
||Interrupt priority register 127|ICDIPR127|32|H'E82015FC|32|
||Interrupt priority register 128|ICDIPR128|32|H'E8201600|32|
||Interrupt priority register 129|ICDIPR129|32|H'E8201604|32|
||Interrupt priority register 130|ICDIPR130|32|H'E8201608|32|
||Interrupt priority register 131|ICDIPR131|32|H'E820160C|32|
||Interrupt priority register 132|ICDIPR132|32|H'E8201610|32|
||Interrupt priority register 133|ICDIPR133|32|H'E8201614|32|
||Interrupt priority register 134|ICDIPR134|32|H'E8201618|32|
||Interrupt processor target register 0|ICDIPTR0|32|H'E8201800|32|
||Interrupt processor target register 1|ICDIPTR1|32|H'E8201804|32|
||Interrupt processor target register 2|ICDIPTR2|32|H'E8201808|32|
||Interrupt processor target register 3|ICDIPTR3|32|H'E820180C|32|
||Interrupt processor target register 4|ICDIPTR4|32|H'E8201810|32|
||Interrupt processor target register 5|ICDIPTR5|32|H'E8201814|32|
||Interrupt processor target register 6|ICDIPTR6|32|H'E8201818|32|
||Interrupt processor target register 7|ICDIPTR7|32|H'E820181C|32|
||Interrupt processor target register 8|ICDIPTR8|32|H'E8201820|32|
||Interrupt processor target register 9|ICDIPTR9|32|H'E8201824|32|
||Interrupt processor target register 10|ICDIPTR10|32|H'E8201828|32|
||Interrupt processor target register 11|ICDIPTR11|32|H'E820182C|32|
||Interrupt processor target register 12|ICDIPTR12|32|H'E8201830|32|
||Interrupt processor target register 13|ICDIPTR13|32|H'E8201834|32|
||Interrupt processor target register 14|ICDIPTR14|32|H'E8201838|32|
||Interrupt processor target register 15|ICDIPTR15|32|H'E820183C|32|
||Interrupt processor target register 16|ICDIPTR16|32|H'E8201840|32|
||Interrupt processor target register 17|ICDIPTR17|32|H'E8201844|32|
||Interrupt processor target register 18|ICDIPTR18|32|H'E8201848|32|
||Interrupt processor target register 19|ICDIPTR19|32|H'E820184C|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt processor target register 20|ICDIPTR20|32|H'E8201850|32|
||Interrupt processor target register 21|ICDIPTR21|32|H'E8201854|32|
||Interrupt processor target register 22|ICDIPTR22|32|H'E8201858|32|
||Interrupt processor target register 23|ICDIPTR23|32|H'E820185C|32|
||Interrupt processor target register 24|ICDIPTR24|32|H'E8201860|32|
||Interrupt processor target register 25|ICDIPTR25|32|H'E8201864|32|
||Interrupt processor target register 26|ICDIPTR26|32|H'E8201868|32|
||Interrupt processor target register 27|ICDIPTR27|32|H'E820186C|32|
||Interrupt processor target register 28|ICDIPTR28|32|H'E8201870|32|
||Interrupt processor target register 29|ICDIPTR29|32|H'E8201874|32|
||Interrupt processor target register 30|ICDIPTR30|32|H'E8201878|32|
||Interrupt processor target register 31|ICDIPTR31|32|H'E820187C|32|
||Interrupt processor target register 32|ICDIPTR32|32|H'E8201880|32|
||Interrupt processor target register 33|ICDIPTR33|32|H'E8201884|32|
||Interrupt processor target register 34|ICDIPTR34|32|H'E8201888|32|
||Interrupt processor target register 35|ICDIPTR35|32|H'E820188C|32|
||Interrupt processor target register 36|ICDIPTR36|32|H'E8201890|32|
||Interrupt processor target register 37|ICDIPTR37|32|H'E8201894|32|
||Interrupt processor target register 38|ICDIPTR38|32|H'E8201898|32|
||Interrupt processor target register 39|ICDIPTR39|32|H'E820189C|32|
||Interrupt processor target register 40|ICDIPTR40|32|H'E82018A0|32|
||Interrupt processor target register 41|ICDIPTR41|32|H'E82018A4|32|
||Interrupt processor target register 42|ICDIPTR42|32|H'E82018A8|32|
||Interrupt processor target register 43|ICDIPTR43|32|H'E82018AC|32|
||Interrupt processor target register 44|ICDIPTR44|32|H'E82018B0|32|
||Interrupt processor target register 45|ICDIPTR45|32|H'E82018B4|32|
||Interrupt processor target register 46|ICDIPTR46|32|H'E82018B8|32|
||Interrupt processor target register 47|ICDIPTR47|32|H'E82018BC|32|
||Interrupt processor target register 48|ICDIPTR48|32|H'E82018C0|32|
||Interrupt processor target register 49|ICDIPTR49|32|H'E82018C4|32|
||Interrupt processor target register 50|ICDIPTR50|32|H'E82018C8|32|
||Interrupt processor target register 51|ICDIPTR51|32|H'E82018CC|32|
||Interrupt processor target register 52|ICDIPTR52|32|H'E82018D0|32|
||Interrupt processor target register 53|ICDIPTR53|32|H'E82018D4|32|
||Interrupt processor target register 54|ICDIPTR54|32|H'E82018D8|32|
||Interrupt processor target register 55|ICDIPTR55|32|H'E82018DC|32|
||Interrupt processor target register 56|ICDIPTR56|32|H'E82018E0|32|
||Interrupt processor target register 57|ICDIPTR57|32|H'E82018E4|32|
||Interrupt processor target register 58|ICDIPTR58|32|H'E82018E8|32|
||Interrupt processor target register 59|ICDIPTR59|32|H'E82018EC|32|
||Interrupt processor target register 60|ICDIPTR60|32|H'E82018F0|32|
||Interrupt processor target register 61|ICDIPTR61|32|H'E82018F4|32|
||Interrupt processor target register 62|ICDIPTR62|32|H'E82018F8|32|
||Interrupt processor target register 63|ICDIPTR63|32|H'E82018FC|32|
||Interrupt processor target register 64|ICDIPTR64|32|H'E8201900|32|
||Interrupt processor target register 65|ICDIPTR65|32|H'E8201904|32|
||Interrupt processor target register 66|ICDIPTR66|32|H'E8201908|32|
||Interrupt processor target register 67|ICDIPTR67|32|H'E820190C|32|
||Interrupt processor target register 68|ICDIPTR68|32|H'E8201910|32|
||Interrupt processor target register 69|ICDIPTR69|32|H'E8201914|32|
||Interrupt processor target register 70|ICDIPTR70|32|H'E8201918|32|
||Interrupt processor target register 71|ICDIPTR71|32|H'E820191C|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt processor target register 72|ICDIPTR72|32|H'E8201920|32|
||Interrupt processor target register 73|ICDIPTR73|32|H'E8201924|32|
||Interrupt processor target register 74|ICDIPTR74|32|H'E8201928|32|
||Interrupt processor target register 75|ICDIPTR75|32|H'E820192C|32|
||Interrupt processor target register 76|ICDIPTR76|32|H'E8201930|32|
||Interrupt processor target register 77|ICDIPTR77|32|H'E8201934|32|
||Interrupt processor target register 78|ICDIPTR78|32|H'E8201938|32|
||Interrupt processor target register 79|ICDIPTR79|32|H'E820193C|32|
||Interrupt processor target register 80|ICDIPTR80|32|H'E8201940|32|
||Interrupt processor target register 81|ICDIPTR81|32|H'E8201944|32|
||Interrupt processor target register 82|ICDIPTR82|32|H'E8201948|32|
||Interrupt processor target register 83|ICDIPTR83|32|H'E820194C|32|
||Interrupt processor target register 84|ICDIPTR84|32|H'E8201950|32|
||Interrupt processor target register 85|ICDIPTR85|32|H'E8201954|32|
||Interrupt processor target register 86|ICDIPTR86|32|H'E8201958|32|
||Interrupt processor target register 87|ICDIPTR87|32|H'E820195C|32|
||Interrupt processor target register 88|ICDIPTR88|32|H'E8201960|32|
||Interrupt processor target register 89|ICDIPTR89|32|H'E8201964|32|
||Interrupt processor target register 90|ICDIPTR90|32|H'E8201968|32|
||Interrupt processor target register 91|ICDIPTR91|32|H'E820196C|32|
||Interrupt processor target register 92|ICDIPTR92|32|H'E8201970|32|
||Interrupt processor target register 93|ICDIPTR93|32|H'E8201974|32|
||Interrupt processor target register 94|ICDIPTR94|32|H'E8201978|32|
||Interrupt processor target register 95|ICDIPTR95|32|H'E820197C|32|
||Interrupt processor target register 96|ICDIPTR96|32|H'E8201980|32|
||Interrupt processor target register 97|ICDIPTR97|32|H'E8201984|32|
||Interrupt processor target register 98|ICDIPTR98|32|H'E8201988|32|
||Interrupt processor target register 99|ICDIPTR99|32|H'E820198C|32|
||Interrupt processor target register 100|ICDIPTR100|32|H'E8201990|32|
||Interrupt processor target register 101|ICDIPTR101|32|H'E8201994|32|
||Interrupt processor target register 102|ICDIPTR102|32|H'E8201998|32|
||Interrupt processor target register 103|ICDIPTR103|32|H'E820199C|32|
||Interrupt processor target register 104|ICDIPTR104|32|H'E82019A0|32|
||Interrupt processor target register 105|ICDIPTR105|32|H'E82019A4|32|
||Interrupt processor target register 106|ICDIPTR106|32|H'E82019A8|32|
||Interrupt processor target register 107|ICDIPTR107|32|H'E82019AC|32|
||Interrupt processor target register 108|ICDIPTR108|32|H'E82019B0|32|
||Interrupt processor target register 109|ICDIPTR109|32|H'E82019B4|32|
||Interrupt processor target register 110|ICDIPTR110|32|H'E82019B8|32|
||Interrupt processor target register 111|ICDIPTR111|32|H'E82019BC|32|
||Interrupt processor target register 112|ICDIPTR112|32|H'E82019C0|32|
||Interrupt processor target register 113|ICDIPTR113|32|H'E82019C4|32|
||Interrupt processor target register 114|ICDIPTR114|32|H'E82019C8|32|
||Interrupt processor target register 115|ICDIPTR115|32|H'E82019CC|32|
||Interrupt processor target register 116|ICDIPTR116|32|H'E82019D0|32|
||Interrupt processor target register 117|ICDIPTR117|32|H'E82019D4|32|
||Interrupt processor target register 118|ICDIPTR118|32|H'E82019D8|32|
||Interrupt processor target register 119|ICDIPTR119|32|H'E82019DC|32|
||Interrupt processor target register 120|ICDIPTR120|32|H'E82019E0|32|
||Interrupt processor target register 121|ICDIPTR121|32|H'E82019E4|32|
||Interrupt processor target register 122|ICDIPTR122|32|H'E82019E8|32|
||Interrupt processor target register 123|ICDIPTR123|32|H'E82019EC|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt processor target register 124|ICDIPTR124|32|H'E82019F0|32|
||Interrupt processor target register 125|ICDIPTR125|32|H'E82019F4|32|
||Interrupt processor target register 126|ICDIPTR126|32|H'E82019F8|32|
||Interrupt processor target register 127|ICDIPTR127|32|H'E82019FC|32|
||Interrupt processor target register 128|ICDIPTR128|32|H'E8201A00|32|
||Interrupt processor target register 129|ICDIPTR129|32|H'E8201A04|32|
||Interrupt processor target register 130|ICDIPTR130|32|H'E8201A08|32|
||Interrupt processor target register 131|ICDIPTR131|32|H'E8201A0C|32|
||Interrupt processor target register 132|ICDIPTR132|32|H'E8201A10|32|
||Interrupt processor target register 133|ICDIPTR133|32|H'E8201A14|32|
||Interrupt processor target register 134|ICDIPTR134|32|H'E8201A18|32|
||Interrupt configuration register 0|ICDICFR0|32|H'E8201C00|32|
||Interrupt configuration register 1|ICDICFR1|32|H'E8201C04|32|
||Interrupt configuration register 2|ICDICFR2|32|H'E8201C08|32|
||Interrupt configuration register 3|ICDICFR3|32|H'E8201C0C|32|
||Interrupt configuration register 4|ICDICFR4|32|H'E8201C10|32|
||Interrupt configuration register 5|ICDICFR5|32|H'E8201C14|32|
||Interrupt configuration register 6|ICDICFR6|32|H'E8201C18|32|
||Interrupt configuration register 7|ICDICFR7|32|H'E8201C1C|32|
||Interrupt configuration register 8|ICDICFR8|32|H'E8201C20|32|
||Interrupt configuration register 9|ICDICFR9|32|H'E8201C24|32|
||Interrupt configuration register 10|ICDICFR10|32|H'E8201C28|32|
||Interrupt configuration register 11|ICDICFR11|32|H'E8201C2C|32|
||Interrupt configuration register 12|ICDICFR12|32|H'E8201C30|32|
||Interrupt configuration register 13|ICDICFR13|32|H'E8201C34|32|
||Interrupt configuration register 14|ICDICFR14|32|H'E8201C38|32|
||Interrupt configuration register 15|ICDICFR15|32|H'E8201C3C|32|
||Interrupt configuration register 16|ICDICFR16|32|H'E8201C40|32|
||Interrupt configuration register 17|ICDICFR17|32|H'E8201C44|32|
||Interrupt configuration register 18|ICDICFR18|32|H'E8201C48|32|
||Interrupt configuration register 19|ICDICFR19|32|H'E8201C4C|32|
||Interrupt configuration register 20|ICDICFR20|32|H'E8201C50|32|
||Interrupt configuration register 21|ICDICFR21|32|H'E8201C54|32|
||Interrupt configuration register 22|ICDICFR22|32|H'E8201C58|32|
||Interrupt configuration register 23|ICDICFR23|32|H'E8201C5C|32|
||Interrupt configuration register 24|ICDICFR24|32|H'E8201C60|32|
||Interrupt configuration register 25|ICDICFR25|32|H'E8201C64|32|
||Interrupt configuration register 26|ICDICFR26|32|H'E8201C68|32|
||Interrupt configuration register 27|ICDICFR27|32|H'E8201C6C|32|
||Interrupt configuration register 28|ICDICFR28|32|H'E8201C70|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Interrupt controller|Interrupt configuration register 29|ICDICFR29|32|H'E8201C74|32|
||Interrupt configuration register 30|ICDICFR30|32|H'E8201C78|32|
||Interrupt configuration register 31|ICDICFR31|32|H'E8201C7C|32|
||Interrupt configuration register 32|ICDICFR32|32|H'E8201C80|32|
||Interrupt configuration register 33|ICDICFR33|32|H'E8201C84|32|
||PPI status register|ppi_status|32|H'E8201D00|32|
||SPI status register 0|spi_status0|32|H'E8201D04|32|
||SPI status register 1|spi_status1|32|H'E8201D08|32|
||SPI status register 2|spi_status2|32|H'E8201D0C|32|
||SPI status register 3|spi_status3|32|H'E8201D10|32|
||SPI status register 4|spi_status4|32|H'E8201D14|32|
||SPI status register 5|spi_status5|32|H'E8201D18|32|
||SPI status register 6|spi_status6|32|H'E8201D1C|32|
||SPI status register 7|spi_status7|32|H'E8201D20|32|
||SPI status register 8|spi_status8|32|H'E8201D24|32|
||SPI status register 9|spi_status9|32|H'E8201D28|32|
||SPI status register 10|spi_status10|32|H'E8201D2C|32|
||SPI status register 11|spi_status11|32|H'E8201D30|32|
||SPI status register 12|spi_status12|32|H'E8201D34|32|
||SPI status register 13|spi_status13|32|H'E8201D38|32|
||SPI status register 14|spi_status14|32|H'E8201D3C|32|
||Software generation interrupt register|ICDSGIR|32|H'E8201F00|32|
||CPU interface control register|ICCICR|32|H'E8202000|32|
||Interrupt priority mask register|ICCPMR|32|H'E8202004|32|
||Binary point register|ICCBPR|32|H'E8202008|32|
||Interrupt acknowledge register|ICCIAR|32|H'E820200C|32|
||End-of-interrupt register|ICCEOIR|32|H'E8202010|32|
||Running priority register|ICCRPR|32|H'E8202014|32|
||Highest pending interrupt register|ICCHPIR|32|H'E8202018|32|
||Aliased binary point register|ICCABPR|32|H'E820201C|32|
||CPU interface implementer identification register|ICCIIDR|32|H'E82020FC|32|
|Bus state controller|Common control register|CMNCR|32|H'3FFFC000|32|
||CS0 space bus control register|CS0BCR|32|H'3FFFC004|32|
||CS1 space bus control register|CS1BCR|32|H'3FFFC008|32|
||CS2 space bus control register|CS2BCR|32|H'3FFFC00C|32|
||CS3 space bus control register|CS3BCR|32|H'3FFFC010|32|
||CS4 space bus control register|CS4BCR|32|H'3FFFC014|32|
||CS5 space bus control register|CS5BCR|32|H'3FFFC018|32|
||CS0 space wait control register|CS0WCR|32|H'3FFFC028|32|
||CS1 space wait control register|CS1WCR|32|H'3FFFC02C|32|
||CS2 space wait control register|CS2WCR|32|H'3FFFC030|32|
||CS3 space wait control register|CS3WCR|32|H'3FFFC034|32|
||CS4 space wait control register|CS4WCR|32|H'3FFFC038|32|
||CS5 space wait control register|CS5WCR|32|H'3FFFC03C|32|
||SDRAM control register|SDCR|32|H'3FFFC04C|32|
||Refresh timer control/status register|RTCSR|16|H'3FFFC050|32|
||Refresh timer counter|RTCNT|16|H'3FFFC054|32|
||Refresh time constant register|RTCOR|16|H'3FFFC058|32|
||Timeout cycle constant register 0|TOSCOR0|32|H'3FFFC060|32|
||Timeout cycle constant register 1|TOSCOR1|32|H'3FFFC064|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Bus state controller|Timeout cycle constant register 2|TOSCOR2|32|H'3FFFC068|32|
||Timeout cycle constant register 3|TOSCOR3|32|H'3FFFC06C|32|
||Timeout cycle constant register 4|TOSCOR4|32|H'3FFFC070|32|
||Timeout cycle constant register 5|TOSCOR5|32|H'3FFFC074|32|
||Timeout status register|TOSTR|32|H'3FFFC080|32|
||Timeout enable register|TOENR|32|H'3FFFC084|32|
|Direct memory access<br>controller|Next0 Source Address Register 0|N0SA_0|32|H'E8200000|32|
||Next0 Destination Address Register 0|N0DA_0|32|H'E8200004|32|
||Next0 Transaction Byte Register 0|N0TB_0|32|H'E8200008|32|
||Next1 Source Address Register 0|N1SA_0|32|H'E820000C|32|
||Next1 Destination Address Register 0|N1DA_0|32|H'E8200010|32|
||Next1 Transaction Byte Register 0|N1TB_0|32|H'E8200014|32|
||Current Source Address Register 0|CRSA_0|32|H'E8200018|32|
||Current Destination Address Register 0|CRDA_0|32|H'E820001C|32|
||Current Transaction Byte Register 0|CRTB_0|32|H'E8200020|32|
||Channel Status Register 0|CHSTAT_0|32|H'E8200024|32|
||Channel Control Register 0|CHCTRL_0|32|H'E8200028|32|
||Channel Configuration Register 0|CHCFG_0|32|H'E820002C|32|
||Channel Interval Register 0|CHITVL_0|32|H'E8200030|32|
||Channel Extension Register 0|CHEXT_0|32|H'E8200034|32|
||Next Link Address Register 0|NXLA_0|32|H'E8200038|32|
||Current Link Address Register 0|CRLA_0|32|H'E820003C|32|
||Next0 Source Address Register 1|N0SA_1|32|H'E8200040|32|
||Next0 Destination Address Register 1|N0DA_1|32|H'E8200044|32|
||Next0 Transaction Byte Register 1|N0TB_1|32|H'E8200048|32|
||Next1 Source Address Register 1|N1SA_1|32|H'E820004C|32|
||Next1 Destination Address Register 1|N1DA_1|32|H'E8200050|32|
||Next1 Transaction Byte Register 1|N1TB_1|32|H'E8200054|32|
||Current Source Address Register 1|CRSA_1|32|H'E8200058|32|
||Current Destination Address Register 1|CRDA_1|32|H'E820005C|32|
||Current Transaction Byte Register 1|CRTB_1|32|H'E8200060|32|
||Channel Status Register 1|CHSTAT_1|32|H'E8200064|32|
||Channel Control Register 1|CHCTRL_1|32|H'E8200068|32|
||Channel Configuration Register 1|CHCFG_1|32|H'E820006C|32|
||Channel Interval Register 1|CHITVL_1|32|H'E8200070|32|
||Channel Extension Register 1|CHEXT_1|32|H'E8200074|32|
||Next Link Address Register 1|NXLA_1|32|H'E8200078|32|
||Current Link Address Register 1|CRLA_1|32|H'E820007C|32|
||Next0 Source Address Register 2|N0SA_2|32|H'E8200080|32|
||Next0 Destination Address Register 2|N0DA_2|32|H'E8200084|32|
||Next0 Transaction Byte Register 2|N0TB_2|32|H'E8200088|32|
||Next1 Source Address Register 2|N1SA_2|32|H'E820008C|32|
||Next1 Destination Address Register 2|N1DA_2|32|H'E8200090|32|
||Next1 Transaction Byte Register 2|N1TB_2|32|H'E8200094|32|
||Current Source Address Register 2|CRSA_2|32|H'E8200098|32|
||Current Destination Address Register 2|CRDA_2|32|H'E820009C|32|
||Current Transaction Byte Register 2|CRTB_2|32|H'E82000A0|32|
||Channel Status Register 2|CHSTAT_2|32|H'E82000A4|32|
||Channel Control Register 2|CHCTRL_2|32|H'E82000A8|32|
||Channel Configuration Register 2|CHCFG_2|32|H'E82000AC|32|
||Channel Interval Register 2|CHITVL_2|32|H'E82000B0|32|
||Channel Extension Register 2|CHEXT_2|32|H'E82000B4|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Direct memory access<br>controller|Next Link Address Register 2|NXLA_2|32|H'E82000B8|32|
||Current Link Address Register 2|CRLA_2|32|H'E82000BC|32|
||Next0 Source Address Register 3|N0SA_3|32|H'E82000C0|32|
||Next0 Destination Address Register 3|N0DA_3|32|H'E82000C4|32|
||Next0 Transaction Byte Register 3|N0TB_3|32|H'E82000C8|32|
||Next1 Source Address Register 3|N1SA_3|32|H'E82000CC|32|
||Next1 Destination Address Register 3|N1DA_3|32|H'E82000D0|32|
||Next1 Transaction Byte Register 3|N1TB_3|32|H'E82000D4|32|
||Current Source Address Register 3|CRSA_3|32|H'E82000D8|32|
||Current Destination Address Register 3|CRDA_3|32|H'E82000DC|32|
||Current Transaction Byte Register 3|CRTB_3|32|H'E82000E0|32|
||Channel Status Register 3|CHSTAT_3|32|H'E82000E4|32|
||Channel Control Register 3|CHCTRL_3|32|H'E82000E8|32|
||Channel Configuration Register 3|CHCFG_3|32|H'E82000EC|32|
||Channel Interval Register 3|CHITVL_3|32|H'E82000F0|32|
||Channel Extension Register 3|CHEXT_3|32|H'E82000F4|32|
||Next Link Address Register 3|NXLA_3|32|H'E82000F8|32|
||Current Link Address Register 3|CRLA_3|32|H'E82000FC|32|
||Next0 Source Address Register 4|N0SA_4|32|H'E8200100|32|
||Next0 Destination Address Register 4|N0DA_4|32|H'E8200104|32|
||Next0 Transaction Byte Register 4|N0TB_4|32|H'E8200108|32|
||Next1 Source Address Register 4|N1SA_4|32|H'E820010C|32|
||Next1 Destination Address Register 4|N1DA_4|32|H'E8200110|32|
||Next1 Transaction Byte Register 4|N1TB_4|32|H'E8200114|32|
||Current Source Address Register 4|CRSA_4|32|H'E8200118|32|
||Current Destination Address Register 4|CRDA_4|32|H'E820011C|32|
||Current Transaction Byte Register 4|CRTB_4|32|H'E8200120|32|
||Channel Status Register 4|CHSTAT_4|32|H'E8200124|32|
||Channel Control Register 4|CHCTRL_4|32|H'E8200128|32|
||Channel Configuration Register 4|CHCFG_4|32|H'E820012C|32|
||Channel Interval Register 4|CHITVL_4|32|H'E8200130|32|
||Channel Extension Register 4|CHEXT_4|32|H'E8200134|32|
||Next Link Address Register 4|NXLA_4|32|H'E8200138|32|
||Current Link Address Register 4|CRLA_4|32|H'E820013C|32|
||Next0 Source Address Register 5|N0SA_5|32|H'E8200140|32|
||Next0 Destination Address Register 5|N0DA_5|32|H'E8200144|32|
||Next0 Transaction Byte Register 5|N0TB_5|32|H'E8200148|32|
||Next1 Source Address Register 5|N1SA_5|32|H'E820014C|32|
||Next1 Destination Address Register 5|N1DA_5|32|H'E8200150|32|
||Next1 Transaction Byte Register 5|N1TB_5|32|H'E8200154|32|
||Current Source Address Register 5|CRSA_5|32|H'E8200158|32|
||Current Destination Address Register 5|CRDA_5|32|H'E820015C|32|
||Current Transaction Byte Register 5|CRTB_5|32|H'E8200160|32|
||Channel Status Register 5|CHSTAT_5|32|H'E8200164|32|
||Channel Control Register 5|CHCTRL_5|32|H'E8200168|32|
||Channel Configuration Register 5|CHCFG_5|32|H'E820016C|32|
||Channel Interval Register 5|CHITVL_5|32|H'E8200170|32|
||Channel Extension Register 5|CHEXT_5|32|H'E8200174|32|
||Next Link Address Register 5|NXLA_5|32|H'E8200178|32|
||Current Link Address Register 5|CRLA_5|32|H'E820017C|32|
||Next0 Source Address Register 6|N0SA_6|32|H'E8200180|32|
||Next0 Destination Address Register 6|N0DA_6|32|H'E8200184|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Direct memory access<br>controller|Next0 Transaction Byte Register 6|N0TB_6|32|H'E8200188|32|
||Next1 Source Address Register 6|N1SA_6|32|H'E820018C|32|
||Next1 Destination Address Register 6|N1DA_6|32|H'E8200190|32|
||Next1 Transaction Byte Register 6|N1TB_6|32|H'E8200194|32|
||Current Source Address Register 6|CRSA_6|32|H'E8200198|32|
||Current Destination Address Register 6|CRDA_6|32|H'E820019C|32|
||Current Transaction Byte Register 6|CRTB_6|32|H'E82001A0|32|
||Channel Status Register 6|CHSTAT_6|32|H'E82001A4|32|
||Channel Control Register 6|CHCTRL_6|32|H'E82001A8|32|
||Channel Configuration Register 6|CHCFG_6|32|H'E82001AC|32|
||Channel Interval Register 6|CHITVL_6|32|H'E82001B0|32|
||Channel Extension Register 6|CHEXT_6|32|H'E82001B4|32|
||Next Link Address Register 6|NXLA_6|32|H'E82001B8|32|
||Current Link Address Register 6|CRLA_6|32|H'E82001BC|32|
||Next0 Source Address Register 7|N0SA_7|32|H'E82001C0|32|
||Next0 Destination Address Register 7|N0DA_7|32|H'E82001C4|32|
||Next0 Transaction Byte Register 7|N0TB_7|32|H'E82001C8|32|
||Next1 Source Address Register 7|N1SA_7|32|H'E82001CC|32|
||Next1 Destination Address Register 7|N1DA_7|32|H'E82001D0|32|
||Next1 Transaction Byte Register 7|N1TB_7|32|H'E82001D4|32|
||Current Source Address Register 7|CRSA_7|32|H'E82001D8|32|
||Current Destination Address Register 7|CRDA_7|32|H'E82001DC|32|
||Current Transaction Byte Register 7|CRTB_7|32|H'E82001E0|32|
||Channel Status Register 7|CHSTAT_7|32|H'E82001E4|32|
||Channel Control Register 7|CHCTRL_7|32|H'E82001E8|32|
||Channel Configuration Register 7|CHCFG_7|32|H'E82001EC|32|
||Channel Interval Register 7|CHITVL_7|32|H'E82001F0|32|
||Channel Extension Register 7|CHEXT_7|32|H'E82001F4|32|
||Next Link Address Register 7|NXLA_7|32|H'E82001F8|32|
||Current Link Address Register 7|CRLA_7|32|H'E82001FC|32|
||DMA Control Registers 0-7|DCTRL_0_7|32|H'E8200300|32|
||DMA Status EN Registers 0-7|DSTAT_EN_0_7|32|H'E8200310|32|
||DMA Status ER Registers 0-7|DSTAT_ER_0_7|32|H'E8200314|32|
||DMA Status END Registers 0-7|DSTAT_END_0_7|32|H'E8200318|32|
||DMA Status TC Registers 0-7|DSTAT_TC_0_7|32|H'E820031C|32|
||DMA Status SUS Registers 0-7|DSTAT_SUS_0_7|32|H'E8200320|32|
||Next0 Source Address Register 8|N0SA_8|32|H'E8200400|32|
||Next0 Destination Address Register 8|N0DA_8|32|H'E8200404|32|
||Next0 Transaction Byte Register 8|N0TB_8|32|H'E8200408|32|
||Next1 Source Address Register 8|N1SA_8|32|H'E820040C|32|
||Next1 Destination Address Register 8|N1DA_8|32|H'E8200410|32|
||Next1 Transaction Byte Register 8|N1TB_8|32|H'E8200414|32|
||Current Source Address Register 8|CRSA_8|32|H'E8200418|32|
||Current Destination Address Register 8|CRDA_8|32|H'E820041C|32|
||Current Transaction Byte Register 8|CRTB_8|32|H'E8200420|32|
||Channel Status Register 8|CHSTAT_8|32|H'E8200424|32|
||Channel Control Register 8|CHCTRL_8|32|H'E8200428|32|
||Channel Configuration Register 8|CHCFG_8|32|H'E820042C|32|
||Channel Interval Register 8|CHITVL_8|32|H'E8200430|32|
||Channel Extension Register 8|CHEXT_8|32|H'E8200434|32|
||Next Link Address Register 8|NXLA_8|32|H'E8200438|32|
||Current Link Address Register 8|CRLA_8|32|H'E820043C|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Direct memory access<br>controller|Next0 Source Address Register 9|N0SA_9|32|H'E8200440|32|
||Next0 Destination Address Register 9|N0DA_9|32|H'E8200444|32|
||Next0 Transaction Byte Register 9|N0TB_9|32|H'E8200448|32|
||Next1 Source Address Register 9|N1SA_9|32|H'E820044C|32|
||Next1 Destination Address Register 9|N1DA_9|32|H'E8200450|32|
||Next1 Transaction Byte Register 9|N1TB_9|32|H'E8200454|32|
||Current Source Address Register 9|CRSA_9|32|H'E8200458|32|
||Current Destination Address Register 9|CRDA_9|32|H'E820045C|32|
||Current Transaction Byte Register 9|CRTB_9|32|H'E8200460|32|
||Channel Status Register 9|CHSTAT_9|32|H'E8200464|32|
||Channel Control Register 9|CHCTRL_9|32|H'E8200468|32|
||Channel Configuration Register 9|CHCFG_9|32|H'E820046C|32|
||Channel Interval Register 9|CHITVL_9|32|H'E8200470|32|
||Channel Extension Register 9|CHEXT_9|32|H'E8200474|32|
||Next Link Address Register 9|NXLA_9|32|H'E8200478|32|
||Current Link Address Register 9|CRLA_9|32|H'E820047C|32|
||Next0 Source Address Register 10|N0SA_10|32|H'E8200480|32|
||Next0 Destination Address Register 10|N0DA_10|32|H'E8200484|32|
||Next0 Transaction Byte Register 10|N0TB_10|32|H'E8200488|32|
||Next1 Source Address Register 10|N1SA_10|32|H'E820048C|32|
||Next1 Destination Address Register 10|N1DA_10|32|H'E8200490|32|
||Next1 Transaction Byte Register 10|N1TB_10|32|H'E8200494|32|
||Current Source Address Register 10|CRSA_10|32|H'E8200498|32|
||Current Destination Address Register 10|CRDA_10|32|H'E820049C|32|
||Current Transaction Byte Register 10|CRTB_10|32|H'E82004A0|32|
||Channel Status Register 10|CHSTAT_10|32|H'E82004A4|32|
||Channel Control Register 10|CHCTRL_10|32|H'E82004A8|32|
||Channel Configuration Register 10|CHCFG_10|32|H'E82004AC|32|
||Channel Interval Register 10|CHITVL_10|32|H'E82004B0|32|
||Channel Extension Register 10|CHEXT_10|32|H'E82004B4|32|
||Next Link Address Register 10|NXLA_10|32|H'E82004B8|32|
||Current Link Address Register 10|CRLA_10|32|H'E82004BC|32|
||Next0 Source Address Register 11|N0SA_11|32|H'E82004C0|32|
||Next0 Destination Address Register 11|N0DA_11|32|H'E82004C4|32|
||Next0 Transaction Byte Register 11|N0TB_11|32|H'E82004C8|32|
||Next1 Source Address Register 11|N1SA_11|32|H'E82004CC|32|
||Next1 Destination Address Register 11|N1DA_11|32|H'E82004D0|32|
||Next1 Transaction Byte Register 11|N1TB_11|32|H'E82004D4|32|
||Current Source Address Register 11|CRSA_11|32|H'E82004D8|32|
||Current Destination Address Register 11|CRDA_11|32|H'E82004DC|32|
||Current Transaction Byte Register 11|CRTB_11|32|H'E82004E0|32|
||Channel Status Register 11|CHSTAT_11|32|H'E82004E4|32|
||Channel Control Register 11|CHCTRL_11|32|H'E82004E8|32|
||Channel Configuration Register 11|CHCFG_11|32|H'E82004EC|32|
||Channel Interval Register 11|CHITVL_11|32|H'E82004F0|32|
||Channel Extension Register 11|CHEXT_11|32|H'E82004F4|32|
||Next Link Address Register 11|NXLA_11|32|H'E82004F8|32|
||Current Link Address Register 11|CRLA_11|32|H'E82004FC|32|
||Next0 Source Address Register 12|N0SA_12|32|H'E8200500|32|
||Next0 Destination Address Register 12|N0DA_12|32|H'E8200504|32|
||Next0 Transaction Byte Register 12|N0TB_12|32|H'E8200508|32|
||Next1 Source Address Register 12|N1SA_12|32|H'E820050C|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Direct memory access<br>controller|Next1 Destination Address Register 12|N1DA_12|32|H'E8200510|32|
||Next1 Transaction Byte Register 12|N1TB_12|32|H'E8200514|32|
||Current Source Address Register 12|CRSA_12|32|H'E8200518|32|
||Current Destination Address Register 12|CRDA_12|32|H'E820051C|32|
||Current Transaction Byte Register 12|CRTB_12|32|H'E8200520|32|
||Channel Status Register 12|CHSTAT_12|32|H'E8200524|32|
||Channel Control Register 12|CHCTRL_12|32|H'E8200528|32|
||Channel Configuration Register 12|CHCFG_12|32|H'E820052C|32|
||Channel Interval Register 12|CHITVL_12|32|H'E8200530|32|
||Channel Extension Register 12|CHEXT_12|32|H'E8200534|32|
||Next Link Address Register 12|NXLA_12|32|H'E8200538|32|
||Current Link Address Register 12|CRLA_12|32|H'E820053C|32|
||Next0 Source Address Register 13|N0SA_13|32|H'E8200540|32|
||Next0 Destination Address Register 13|N0DA_13|32|H'E8200544|32|
||Next0 Transaction Byte Register 13|N0TB_13|32|H'E8200548|32|
||Next1 Source Address Register 13|N1SA_13|32|H'E820054C|32|
||Next1 Destination Address Register 13|N1DA_13|32|H'E8200550|32|
||Next1 Transaction Byte Register 13|N1TB_13|32|H'E8200554|32|
||Current Source Address Register 13|CRSA_13|32|H'E8200558|32|
||Current Destination Address Register 13|CRDA_13|32|H'E820055C|32|
||Current Transaction Byte Register 13|CRTB_13|32|H'E8200560|32|
||Channel Status Register 13|CHSTAT_13|32|H'E8200564|32|
||Channel Control Register 13|CHCTRL_13|32|H'E8200568|32|
||Channel Configuration Register 13|CHCFG_13|32|H'E820056C|32|
||Channel Interval Register 13|CHITVL_13|32|H'E8200570|32|
||Channel Extension Register 13|CHEXT_13|32|H'E8200574|32|
||Next Link Address Register 13|NXLA_13|32|H'E8200578|32|
||Current Link Address Register 13|CRLA_13|32|H'E820057C|32|
||Next0 Source Address Register 14|N0SA_14|32|H'E8200580|32|
||Next0 Destination Address Register 14|N0DA_14|32|H'E8200584|32|
||Next0 Transaction Byte Register 14|N0TB_14|32|H'E8200588|32|
||Next1 Source Address Register 14|N1SA_14|32|H'E820058C|32|
||Next1 Destination Address Register 14|N1DA_14|32|H'E8200590|32|
||Next1 Transaction Byte Register 14|N1TB_14|32|H'E8200594|32|
||Current Source Address Register 14|CRSA_14|32|H'E8200598|32|
||Current Destination Address Register 14|CRDA_14|32|H'E820059C|32|
||Current Transaction Byte Register 14|CRTB_14|32|H'E82005A0|32|
||Channel Status Register 14|CHSTAT_14|32|H'E82005A4|32|
||Channel Control Register 14|CHCTRL_14|32|H'E82005A8|32|
||Channel Configuration Register 14|CHCFG_14|32|H'E82005AC|32|
||Channel Interval Register 14|CHITVL_14|32|H'E82005B0|32|
||Channel Extension Register 14|CHEXT_14|32|H'E82005B4|32|
||Next Link Address Register 14|NXLA_14|32|H'E82005B8|32|
||Current Link Address Register 14|CRLA_14|32|H'E82005BC|32|
||Next0 Source Address Register 15|N0SA_15|32|H'E82005C0|32|
||Next0 Destination Address Register 15|N0DA_15|32|H'E82005C4|32|
||Next0 Transaction Byte Register 15|N0TB_15|32|H'E82005C8|32|
||Next1 Source Address Register 15|N1SA_15|32|H'E82005CC|32|
||Next1 Destination Address Register 15|N1DA_15|32|H'E82005D0|32|
||Next1 Transaction Byte Register 15|N1TB_15|32|H'E82005D4|32|
||Current Source Address Register 15|CRSA_15|32|H'E82005D8|32|
||Current Destination Address Register 15|CRDA_15|32|H'E82005DC|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Direct memory access<br>controller|Current Transaction Byte Register 15|CRTB_15|32|H'E82005E0|32|
||Channel Status Register 15|CHSTAT_15|32|H'E82005E4|32|
||Channel Control Register 15|CHCTRL_15|32|H'E82005E8|32|
||Channel Configuration Register 15|CHCFG_15|32|H'E82005EC|32|
||Channel Interval Register 15|CHITVL_15|32|H'E82005F0|32|
||Channel Extension Register 15|CHEXT_15|32|H'E82005F4|32|
||Next Link Address Register 15|NXLA_15|32|H'E82005F8|32|
||Current Link Address Register 15|CRLA_15|32|H'E82005FC|32|
||DMA Control Registers 8-15|DCTRL_8_15|32|H'E8200700|32|
||DMA Status EN Registers 8-15|DSTAT_EN_8_15|32|H'E8200710|32|
||DMA Status ER Registers 8-15|DSTAT_ER_8_15|32|H'E8200714|32|
||DMA Status END Registers 8-15|DSTAT_END_8_15|32|H'E8200718|32|
||DMA Status TC Registers 8-15|DSTAT_TC_8_15|32|H'E820071C|32|
||DMA Status SUS Registers 8-15|DSTAT_SUS_8_15|32|H'E8200720|32|
||DMA extended resource selector 0|DMARS0|32|H'FCFE1000|32|
||DMA extended resource selector 1|DMARS1|32|H'FCFE1004|32|
||DMA extended resource selector 2|DMARS2|32|H'FCFE1008|32|
||DMA extended resource selector 3|DMARS3|32|H'FCFE100C|32|
||DMA extended resource selector 4|DMARS4|32|H'FCFE1010|32|
||DMA extended resource selector 5|DMARS5|32|H'FCFE1014|32|
||DMA extended resource selector 6|DMARS6|32|H'FCFE1018|32|
||DMA extended resource selector 7|DMARS7|32|H'FCFE101C|32|
|Multi-function timer pulse<br>unit 2|Timer control register_0|TCR_0|8|H'FCFF0300|8|
||Timer mode register_0|TMDR_0|8|H'FCFF0301|8|
||Timer I/O control register H_0|TIORH_0|8|H'FCFF0302|8|
||Timer I/O control register L_0|TIORL_0|8|H'FCFF0303|8|
||Timer interrupt enable register_0|TIER_0|8|H'FCFF0304|8|
||Timer status register_0|TSR_0|8|H'FCFF0305|8|
||Timer counter_0|TCNT_0|16|H'FCFF0306|16|
||Timer general register A_0|TGRA_0|16|H'FCFF0308|16|
||Timer general register B_0|TGRB_0|16|H'FCFF030A|16|
||Timer general register C_0|TGRC_0|16|H'FCFF030C|16|
||Timer general register D_0|TGRD_0|16|H'FCFF030E|16|
||Timer general register E_0|TGRE_0|16|H'FCFF0320|16|
||Timer general register F_0|TGRF_0|16|H'FCFF0322|16|
||Timer interrupt enable register 2_0|TIER2_0|8|H'FCFF0324|8|
||Timer status register 2_0|TSR2_0|8|H'FCFF0325|8|
||Timer buffer operation transfer mode register_0|TBTM_0|8|H'FCFF0326|8|
||Timer control register_1|TCR_1|8|H'FCFF0380|8|
||Timer mode register_1|TMDR_1|8|H'FCFF0381|8|
||Timer I/O control register _1|TIOR_1|8|H'FCFF0382|8|
||Timer interrupt enable register_1|TIER_1|8|H'FCFF0384|8|
||Timer status register_1|TSR_1|8|H'FCFF0385|8|
||Timer counter_1|TCNT_1|16|H'FCFF0386|16|
||Timer general register A_1|TGRA_1|16|H'FCFF0388|16|
||Timer general register B_1|TGRB_1|16|H'FCFF038A|16|
||Timer input capture control register|TICCR|8|H'FCFF0390|8|
||Timer control register_2|TCR_2|8|H'FCFF0000|8|
||Timer mode register_2|TMDR_2|8|H'FCFF0001|8|
||Timer I/O control register _2|TIOR_2|8|H'FCFF0002|8|
||Timer interrupt enable register_2|TIER_2|8|H'FCFF0004|8|
||Timer status register_2|TSR_2|8|H'FCFF0005|8|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Multi-function timer pulse<br>unit 2|Timer counter_2|TCNT_2|16|H'FCFF0006|16|
||Timer general register A_2|TGRA_2|16|H'FCFF0008|16|
||Timer general register B_2|TGRB_2|16|H'FCFF000A|16|
||Timer control register_3|TCR_3|8|H'FCFF0200|8|
||Timer mode register_3|TMDR_3|8|H'FCFF0202|8|
||Timer I/O control register H_3|TIORH_3|8|H'FCFF0204|8|
||Timer I/O control register L_3|TIORL_3|8|H'FCFF0205|8|
||Timer interrupt enable register_3|TIER_3|8|H'FCFF0208|8|
||Timer status register_3|TSR_3|8|H'FCFF022C|8|
||Timer counter_3|TCNT_3|16|H'FCFF0210|16|
||Timer general register A_3|TGRA_3|16|H'FCFF0218|16|
||Timer general register B_3|TGRB_3|16|H'FCFF021A|16|
||Timer general register C_3|TGRC_3|16|H'FCFF0224|16|
||Timer general register D_3|TGRD_3|16|H'FCFF0226|16|
||Timer buffer operation transfer mode register_3|TBTM_3|8|H'FCFF0238|8|
||Timer control register_4|TCR_4|8|H'FCFF0201|8|
||Timer mode register_4|TMDR_4|8|H'FCFF0203|8|
||Timer I/O control register H_4|TIORH_4|8|H'FCFF0206|8|
||Timer I/O control register L_4|TIORL_4|8|H'FCFF0207|8|
||Timer interrupt enable register_4|TIER_4|8|H'FCFF0209|8|
||Timer status register_4|TSR_4|8|H'FCFF022D|8|
||Timer counter_4|TCNT_4|16|H'FCFF0212|16|
||Timer general register A_4|TGRA_4|16|H'FCFF021C|16|
||Timer general register B_4|TGRB_4|16|H'FCFF021E|16|
||Timer general register C_4|TGRC_4|16|H'FCFF0228|16|
||Timer general register D_4|TGRD_4|16|H'FCFF022A|16|
||Timer buffer operation transfer mode register_4|TBTM_4|8|H'FCFF0239|8|
||Timer A/D converter start request control register|TADCR|16|H'FCFF0240|16|
||Timer A/D converter start request cycle set register A_4|TADCORA_4|16|H'FCFF0244|16|
||Timer A/D converter start request cycle set register B_4|TADCORB_4|16|H'FCFF0246|16|
||Timer A/D converter start request cycle set buffer register A_4|TADCOBRA_4|16|H'FCFF0248|16|
||Timer A/D converter start request cycle set buffer register B_4|TADCOBRB_4|16|H'FCFF024A|16|
||Timer start register|TSTR|8|H'FCFF0280|8|
||Timer synchronous register|TSYR|8|H'FCFF0281|8|
||Timer read/write enable register|TRWER|8|H'FCFF0284|8|
||Timer output master enable register|TOER|8|H'FCFF020A|8|
||Timer output control register 1|TOCR1|8|H'FCFF020E|8|
||Timer output control register 2|TOCR2|8|H'FCFF020F|8|
||Timer gate control register|TGCR|8|H'FCFF020D|8|
||Timer cycle data register|TCDR|16|H'FCFF0214|16|
||Timer dead time data register|TDDR|16|H'FCFF0216|16|
||Timer subcounter|TCNTS|16|H'FCFF0220|16|
||Timer cycle buffer register|TCBR|16|H'FCFF0222|16|
||Timer interrupt skipping set register|TITCR|8|H'FCFF0230|8|
||Timer interrupt skipping counter|TITCNT|8|H'FCFF0231|8|
||Timer buffer transfer set register|TBTER|8|H'FCFF0232|8|
||Timer dead time enable register|TDER|8|H'FCFF0234|8|
||Timer waveform control register|TWCR|8|H'FCFF0260|8|
||Timer output level buffer register|TOLBR|8|H'FCFF0236|8|
|OS timer|OSTM0 compare register|OSTM0CMP|32|H'FCFEC000|32|
||OSTM0 counter register|OSTM0CNT|32|H'FCFEC004|32|
||OSTM0 count enable status register|OSTM0TE|8|H'FCFEC010|8|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|OS timer|OSTM0 count start trigger register|OSTM0TS|8|H'FCFEC014|8|
||OSTM0 count stop trigger register|OSTM0TT|8|H'FCFEC018|8|
||OSTM0 control register|OSTM0CTL|8|H'FCFEC020|8|
||OSTM1 compare register|OSTM1CMP|32|H'FCFEC400|32|
||OSTM1 counter register|OSTM1CNT|32|H'FCFEC404|32|
||OSTM1 count enable status register|OSTM1TE|8|H'FCFEC410|8|
||OSTM1 count start trigger register|OSTM1TS|8|H'FCFEC414|8|
||OSTM1 count stop trigger register|OSTM1TT|8|H'FCFEC418|8|
||OSTM1 control register|OSTM1CTL|8|H'FCFEC420|8|
|Watchdog timer|Watchdog timer counter|WTCNT|8|H'FCFE0002|16|
||Watchdog timer control/status register|WTCSR|8|H'FCFE0000|16|
||Watchdog reset control/status register|WRCSR|8|H'FCFE0004|16|
|Realtime clock|64-Hz counter|R64CNT|8|H'FCFF1000|8|
||Second counter|RSECCNT|8|H'FCFF1002|8|
||Minute counter|RMINCNT|8|H'FCFF1004|8|
||Hour counter|RHRCNT|8|H'FCFF1006|8|
||Day of week counter|RWKCNT|8|H'FCFF1008|8|
||Day counter|RDAYCNT|8|H'FCFF100A|8|
||Month counter|RMONCNT|8|H'FCFF100C|8|
||Year counter|RYRCNT|16|H'FCFF100E|16|
||Second alarm register|RSECAR|8|H'FCFF1010|8|
||Minute alarm register|RMINAR|8|H'FCFF1012|8|
||Hour alarm register|RHRAR|8|H'FCFF1014|8|
||Day of week alarm register|RWKAR|8|H'FCFF1016|8|
||Day alarm register|RDAYAR|8|H'FCFF1018|8|
||Month alarm register|RMONAR|8|H'FCFF101A|8|
||Year alarm register|RYRAR|16|H'FCFF1020|16|
||Control register 1|RCR1|8|H'FCFF101C|8|
||Control register 2|RCR2|8|H'FCFF101E|8|
||Control register 3|RCR3|8|H'FCFF1024|8|
||Control register 5|RCR5|8|H'FCFF1026|8|
||Frequency register H|RFRH|16|H'FCFF102A|16|
||Frequency register L|RFRL|16|H'FCFF102C|16|
|Serial communication<br>interface with FIFO|Serial mode register_0|SCSMR_0|16|H'E8007000|16|
||Bit rate register_0|SCBRR_0|8|H'E8007004|8|
||Serial control register_0|SCSCR_0|16|H'E8007008|16|
||Transmit FIFO data register_0|SCFTDR_0|8|H'E800700C|8|
||Serial status register_0|SCFSR_0|16|H'E8007010|16|
||Receive FIFO data register_0|SCFRDR_0|8|H'E8007014|8|
||FIFO control register_0|SCFCR_0|16|H'E8007018|16|
||FIFO data count set register_0|SCFDR_0|16|H'E800701C|16|
||Serial port register_0|SCSPTR_0|16|H'E8007020|16|
||Line status register_0|SCLSR_0|16|H'E8007024|16|
||Serial extension mode register_0|SCEMR_0|16|H'E8007028|16|
||Serial mode register_1|SCSMR_1|16|H'E8007800|16|
||Bit rate register_1|SCBRR_1|8|H'E8007804|8|
||Serial control register_1|SCSCR_1|16|H'E8007808|16|
||Transmit FIFO data register_1|SCFTDR_1|8|H'E800780C|8|
||Serial status register_1|SCFSR_1|16|H'E8007810|16|
||Receive FIFO data register_1|SCFRDR_1|8|H'E8007814|8|
||FIFO control register_1|SCFCR_1|16|H'E8007818|16|
||FIFO data count set register_1|SCFDR_1|16|H'E800781C|16|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Serial communication<br>interface with FIFO|Serial port register_1|SCSPTR_1|16|H'E8007820|16|
||Line status register_1|SCLSR_1|16|H'E8007824|16|
||Serial extension mode register_1|SCEMR_1|16|H'E8007828|16|
||Serial mode register_2|SCSMR_2|16|H'E8008000|16|
||Bit rate register_2|SCBRR_2|8|H'E8008004|8|
||Serial control register_2|SCSCR_2|16|H'E8008008|16|
||Transmit FIFO data register_2|SCFTDR_2|8|H'E800800C|8|
||Serial status register_2|SCFSR_2|16|H'E8008010|16|
||Receive FIFO data register_2|SCFRDR_2|8|H'E8008014|8|
||FIFO control register_2|SCFCR_2|16|H'E8008018|16|
||FIFO data count set register_2|SCFDR_2|16|H'E800801C|16|
||Serial port register_2|SCSPTR_2|16|H'E8008020|16|
||Line status register_2|SCLSR_2|16|H'E8008024|16|
||Serial extension mode register_2|SCEMR_2|16|H'E8008028|16|
||Serial mode register_3|SCSMR_3|16|H'E8008800|16|
||Bit rate register_3|SCBRR_3|8|H'E8008804|8|
||Serial control register_3|SCSCR_3|16|H'E8008808|16|
||Transmit FIFO data register_3|SCFTDR_3|8|H'E800880C|8|
||Serial status register_3|SCFSR_3|16|H'E8008810|16|
||Receive FIFO data register_3|SCFRDR_3|8|H'E8008814|8|
||FIFO control register_3|SCFCR_3|16|H'E8008818|16|
||FIFO data count set register_3|SCFDR_3|16|H'E800881C|16|
||Serial port register_3|SCSPTR_3|16|H'E8008820|16|
||Line status register_3|SCLSR_3|16|H'E8008824|16|
||Serial extension mode register_3|SCEMR_3|16|H'E8008828|16|
||Serial mode register_4|SCSMR_4|16|H'E8009000|16|
||Bit rate register_4|SCBRR_4|8|H'E8009004|8|
||Serial control register_4|SCSCR_4|16|H'E8009008|16|
||Transmit FIFO data register_4|SCFTDR_4|8|H'E800900C|8|
||Serial status register_4|SCFSR_4|16|H'E8009010|16|
||Receive FIFO data register_4|SCFRDR_4|8|H'E8009014|8|
||FIFO control register_4|SCFCR_4|16|H'E8009018|16|
||FIFO data count set register_4|SCFDR_4|16|H'E800901C|16|
||Serial port register_4|SCSPTR_4|16|H'E8009020|16|
||Line status register_4|SCLSR_4|16|H'E8009024|16|
||Serial extension mode register_4|SCEMR_4|16|H'E8009028|16|
|Serial communications<br>interface|Serial mode register 0|SMR0|8|H'E800B000|8|
||Bit rate register 0|BRR0|8|H'E800B001|8|
||Serial control register 0|SCR0|8|H'E800B002|8|
||Transmit data register 0|TDR0|8|H'E800B003|8|
||Serial status register 0|SSR0|8|H'E800B004|8|
||Receive data register 0|RDR0|8|H'E800B005|8|
||Smart card mode register 0|SCMR0|8|H'E800B006|8|
||Serial extended mode register 0|SEMR0|8|H'E800B007|8|
||Noise filter setting register 0|SNFR0|8|H'E800B008|8|
||Extended function control register 0|SECR0|8|H'E800B00D|8|
||Serial mode register 1|SMR1|8|H'E800B800|8|
||Bit rate register 1|BRR1|8|H'E800B801|8|
||Serial control register 1|SCR1|8|H'E800B802|8|
||Transmit data register 1|TDR1|8|H'E800B803|8|
||Serial status register 1|SSR1|8|H'E800B804|8|
||Receive data register 1|RDR1|8|H'E800B805|8|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Serial communications<br>interface|Smart card mode register 1|SCMR1|8|H'E800B806|8|
||Serial extended mode register 1|SEMR1|8|H'E800B807|8|
||Noise filter setting register 1|SNFR1|8|H'E800B808|8|
||Extended function control register 1|SECR1|8|H'E800B80D|8|
||IrDA control register|IRCR|8|H'E8014000|8|
|Renesas serial peripheral<br>interface|Control register_0|SPCR_0|8|H'E800C800|8|
||Slave select polarity register_0|SSLP_0|8|H'E800C801|8|
||Pin control register_0|SPPCR_0|8|H'E800C802|8|
||Status register_0|SPSR_0|8|H'E800C803|8|
||Data register_0|SPDR_0|32|H'E800C804|8, 16, 32|
||Sequence control register_0|SPSCR_0|8|H'E800C808|8|
||Sequence status register_0|SPSSR_0|8|H'E800C809|8|
||Bit rate register_0|SPBR_0|8|H'E800C80A|8|
||Data control register_0|SPDCR_0|8|H'E800C80B|8|
||Clock delay register_0|SPCKD_0|8|H'E800C80C|8|
||Slave select negation delay register_0|SSLND_0|8|H'E800C80D|8|
||Next-access delay register_0|SPND_0|8|H'E800C80E|8|
||Command register 0_0|SPCMD0_0|16|H'E800C810|16|
||Command register 1_0|SPCMD1_0|16|H'E800C812|16|
||Command register 2_0|SPCMD2_0|16|H'E800C814|16|
||Command register 3_0|SPCMD3_0|16|H'E800C816|16|
||Buffer control register_0|SPBFCR_0|8|H'E800C820|8|
||Buffer data count setting register_0|SPBFDR_0|16|H'E800C822|16|
||Control register_1|SPCR_1|8|H'E800D000|8|
||Slave select polarity register_1|SSLP_1|8|H'E800D001|8|
||Pin control register_1|SPPCR_1|8|H'E800D002|8|
||Status register_1|SPSR_1|8|H'E800D003|8|
||Data register_1|SPDR_1|32|H'E800D004|8, 16, 32|
||Sequence control register_1|SPSCR_1|8|H'E800D008|8|
||Sequence status register_1|SPSSR_1|8|H'E800D009|8|
||Bit rate register_1|SPBR_1|8|H'E800D00A|8|
||Data control register_1|SPDCR_1|8|H'E800D00B|8|
||Clock delay register_1|SPCKD_1|8|H'E800D00C|8|
||Slave select negation delay register_1|SSLND_1|8|H'E800D00D|8|
||Next-access delay register_1|SPND_1|8|H'E800D00E|8|
||Command register 0_1|SPCMD0_1|16|H'E800D010|16|
||Command register 1_1|SPCMD1_1|16|H'E800D012|16|
||Command register 2_1|SPCMD2_1|16|H'E800D014|16|
||Command register 3_1|SPCMD3_1|16|H'E800D016|16|
||Buffer control register_1|SPBFCR_1|8|H'E800D020|8|
||Buffer data count setting register_1|SPBFDR_1|16|H'E800D022|16|
||Control register_2|SPCR_2|8|H'E800D800|8|
||Slave select polarity register_2|SSLP_2|8|H'E800D801|8|
||Pin control register_2|SPPCR_2|8|H'E800D802|8|
||Status register_2|SPSR_2|8|H'E800D803|8|
||Data register_2|SPDR_2|32|H'E800D804|8, 16, 32|
||Sequence control register_2|SPSCR_2|8|H'E800D808|8|
||Sequence status register_2|SPSSR_2|8|H'E800D809|8|
||Bit rate register_2|SPBR_2|8|H'E800D80A|8|
||Data control register_2|SPDCR_2|8|H'E800D80B|8|
||Clock delay register_2|SPCKD_2|8|H'E800D80C|8|
||Slave select negation delay register_2|SSLND_2|8|H'E800D80D|8|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Renesas serial peripheral<br>interface|Next-access delay register_2|SPND_2|8|H'E800D80E|8|
||Command register 0_2|SPCMD0_2|16|H'E800D810|16|
||Command register 1_2|SPCMD1_2|16|H'E800D812|16|
||Command register 2_2|SPCMD2_2|16|H'E800D814|16|
||Command register 3_2|SPCMD3_2|16|H'E800D816|16|
||Buffer control register_2|SPBFCR_2|8|H'E800D820|8|
||Buffer data count setting register_2|SPBFDR_2|16|H'E800D822|16|
|SPI multi I/O bus controller|Common control register_0|CMNCR_0|32|H'3FEFA000|32|
||SSL delay register_0|SSLDR_0|32|H'3FEFA004|32|
||Bit rate register_0|SPBCR_0|32|H'3FEFA008|32|
||Data read control register_0|DRCR_0|32|H'3FEFA00C|32|
||Data read command setting register_0|DRCMR_0|32|H'3FEFA010|32|
||Data read extended address setting register_0|DREAR_0|32|H'3FEFA014|32|
||Data read option setting register_0|DROPR_0|32|H'3FEFA018|32|
||Data read enable setting register_0|DRENR_0|32|H'3FEFA01C|32|
||SPI mode control register_0|SMCR_0|32|H'3FEFA020|32|
||SPI mode command setting register_0|SMCMR_0|32|H'3FEFA024|32|
||SPI mode address setting register_0|SMADR_0|32|H'3FEFA028|32|
||SPI mode option setting register_0|SMOPR_0|32|H'3FEFA02C|32|
||SPI mode enable setting register_0|SMENR_0|32|H'3FEFA030|32|
||SPI mode read data register 0_0|SMRDR0_0|32|H'3FEFA038|8, 16, 32|
||SPI mode read data register 1_0|SMRDR1_0|32|H'3FEFA03C|8, 16, 32|
||SPI mode write data register 0_0|SMWDR0_0|32|H'3FEFA040|8, 16, 32|
||SPI mode write data register 1_0|SMWDR1_0|32|H'3FEFA044|8, 16, 32|
||Common status register_0|CMNSR_0|32|H'3FEFA048|32|
||SPI AC input characteristics adjustment register_0*2|CKDLY_0|32|H'3FEFA050|32|
||Data read dummy cycle setting register_0|DRDMCR_0|32|H'3FEFA058|32|
||Data read DDR enable register_0*2|DRDRENR_0|32|H'3FEFA05C|32|
||SPI mode dummy cycle setting register_0|SMDMCR_0|32|H'3FEFA060|32|
||SPI mode DDR enable register_0*2|SMDRENR_0|32|H'3FEFA064|32|
||SPI AC output characteristics adjustment register_0*2|SPODLY_0|32|H'3FEFA068|32|
|I2C bus interface|I2C bus control register 1_0|RIIC0CR1|32|H'FCFEE000|8, 16, 32|
||I2C bus control register 2_0|RIIC0CR2|32|H'FCFEE004|8, 16, 32|
||I2C bus mode register 1_0|RIIC0MR1|32|H'FCFEE008|8, 16, 32|
||I2C bus mode register 2_0|RIIC0MR2|32|H'FCFEE00C|8, 16, 32|
||I2C bus mode register 3_0|RIIC0MR3|32|H'FCFEE010|8, 16, 32|
||I2C bus function enable register_0|RIIC0FER|32|H'FCFEE014|8, 16, 32|
||I2C bus status enable register_0|RIIC0SER|32|H'FCFEE018|8, 16, 32|
||I2C bus interrupt enable register_0|RIIC0IER|32|H'FCFEE01C|8, 16, 32|
||I2C bus status register 1_0|RIIC0SR1|32|H'FCFEE020|8, 16, 32|
||I2C bus status register 2_0|RIIC0SR2|32|H'FCFEE024|8, 16, 32|
||I2C slave address register 0_0|RIIC0SAR0|32|H'FCFEE028|8, 16, 32|
||I2C slave address register 1_0|RIIC0SAR1|32|H'FCFEE02C|8, 16, 32|
||I2C slave address register 2_0|RIIC0SAR2|32|H'FCFEE030|8, 16, 32|
||I2C bus bit rate low-level register_0|RIIC0BRL|32|H'FCFEE034|8, 16, 32|
||I2C bus bit rate high-level register_0|RIIC0BRH|32|H'FCFEE038|8, 16, 32|
||I2C bus transmit data register_0|RIIC0DRT|32|H'FCFEE03C|8, 16, 32|
||I2C bus transmit data register_0|RIIC0DRR|32|H'FCFEE040|8, 16, 32|
||I2C bus control register 1_1|RIIC1CR1|32|H'FCFEE400|8, 16, 32|
||I2C bus control register 2_1|RIIC1CR2|32|H'FCFEE404|8, 16, 32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|I2C bus interface|I2C bus mode register 1_1|RIIC1MR1|32|H'FCFEE408|8, 16, 32|
||I2C bus mode register 2_1|RIIC1MR2|32|H'FCFEE40C|8, 16, 32|
||I2C bus mode register 3_1|RIIC1MR3|32|H'FCFEE410|8, 16, 32|
||I2C bus function enable register_1|RIIC1FER|32|H'FCFEE414|8, 16, 32|
||I2C bus status enable register_1|RIIC1SER|32|H'FCFEE418|8, 16, 32|
||I2C bus interrupt enable register_1|RIIC1IER|32|H'FCFEE41C|8, 16, 32|
||I2C bus status register 1_1|RIIC1SR1|32|H'FCFEE420|8, 16, 32|
||I2C bus status register 2_1|RIIC1SR2|32|H'FCFEE424|8, 16, 32|
||I2C slave address register 0_1|RIIC1SAR0|32|H'FCFEE428|8, 16, 32|
||I2C slave address register 1_1|RIIC1SAR1|32|H'FCFEE42C|8, 16, 32|
||I2C slave address register 2_1|RIIC1SAR2|32|H'FCFEE430|8, 16, 32|
||I2C bus bit rate low-level register_1|RIIC1BRL|32|H'FCFEE434|8, 16, 32|
||I2C bus bit rate high-level register_1|RIIC1BRH|32|H'FCFEE438|8, 16, 32|
||I2C bus transmit data register_1|RIIC1DRT|32|H'FCFEE43C|8, 16, 32|
||I2C bus receive data register_1|RIIC1DRR|32|H'FCFEE440|8, 16, 32|
||I2C bus control register 1_2|RIIC2CR1|32|H'FCFEE800|8, 16, 32|
||I2C bus control register 2_2|RIIC2CR2|32|H'FCFEE804|8, 16, 32|
||I2C bus mode register 1_2|RIIC2MR1|32|H'FCFEE808|8, 16, 32|
||I2C bus mode register 2_2|RIIC2MR2|32|H'FCFEE80C|8, 16, 32|
||I2C bus mode register 3_2|RIIC2MR3|32|H'FCFEE810|8, 16, 32|
||I2C bus function enable register_2|RIIC2FER|32|H'FCFEE814|8, 16, 32|
||I2C bus status enable register_2|RIIC2SER|32|H'FCFEE818|8, 16, 32|
||I2C bus interrupt enable register_2|RIIC2IER|32|H'FCFEE81C|8, 16, 32|
||I2C bus status register 1_2|RIIC2SR1|32|H'FCFEE820|8, 16, 32|
||I2C bus status register 2_2|RIIC2SR2|32|H'FCFEE824|8, 16, 32|
||I2C slave address register 0_2|RIIC2SAR0|32|H'FCFEE828|8, 16, 32|
||I2C slave address register 1_2|RIIC2SAR1|32|H'FCFEE82C|8, 16, 32|
||I2C slave address register 2_2|RIIC2SAR2|32|H'FCFEE830|8, 16, 32|
||I2C bus bit rate low-level register_2|RIIC2BRL|32|H'FCFEE834|8, 16, 32|
||I2C bus bit rate high-level register_2|RIIC2BRH|32|H'FCFEE838|8, 16, 32|
||I2C bus transmit data register_2|RIIC2DRT|32|H'FCFEE83C|8, 16, 32|
||I2C bus receive data register_2|RIIC2DRR|32|H'FCFEE840|8, 16, 32|
||I2C bus control register 1_3|RIIC3CR1|32|H'FCFEEC00|8, 16, 32|
||I2C bus control register 2_3|RIIC3CR2|32|H'FCFEEC04|8, 16, 32|
||I2C bus mode register 1_3|RIIC3MR1|32|H'FCFEEC08|8, 16, 32|
||I2C bus mode register 2_3|RIIC3MR2|32|H'FCFEEC0C|8, 16, 32|
||I2C bus mode register 3_3|RIIC3MR3|32|H'FCFEEC10|8, 16, 32|
||I2C bus function enable register_3|RIIC3FER|32|H'FCFEEC14|8, 16, 32|
||I2C bus status enable register_3|RIIC3SER|32|H'FCFEEC18|8, 16, 32|
||I2C bus interrupt enable register_3|RIIC3IER|32|H'FCFEEC1C|8, 16, 32|
||I2C bus status register 1_3|RIIC3SR1|32|H'FCFEEC20|8, 16, 32|
||I2C bus status register 2_3|RIIC3SR2|32|H'FCFEEC24|8, 16, 32|
||I2C slave address register 0_3|RIIC3SAR0|32|H'FCFEEC28|8, 16, 32|
||I2C slave address register 1_3|RIIC3SAR1|32|H'FCFEEC2C|8, 16, 32|
||I2C slave address register 2_3|RIIC3SAR2|32|H'FCFEEC30|8, 16, 32|
||I2C bus bit rate low-level register_3|RIIC3BRL|32|H'FCFEEC34|8, 16, 32|
||I2C bus bit rate high-level register_3|RIIC3BRH|32|H'FCFEEC38|8, 16, 32|
||I2C bus transmit data register_3|RIIC3DRT|32|H'FCFEEC3C|8, 16, 32|
||I2C bus receive data register_3|RIIC3DRR|32|H'FCFEEC40|8, 16, 32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Serial sound interface|Control register_0|SSICR_0|32|H'E820B000|32|
||Status register_0|SSISR_0|32|H'E820B004|32|
||FIFO control register_0|SSIFCR_0|32|H'E820B010|32|
||FIFO status register_0|SSIFSR_0|32|H'E820B014|32|
||Transmit FIFO data register_0|SSIFTDR_0|32|H'E820B018|32|
||Receive FIFO data register_0|SSIFRDR_0|32|H'E820B01C|32|
||TDM mode register_0|SSITDMR_0|32|H'E820B020|32|
||FC control register_0|SSIFCCR_0|32|H'E820B024|32|
||FC mode register_0|SSIFCMR_0|32|H'E820B028|32|
||FC status register_0|SSIFCSR_0|32|H'E820B02C|32|
||Control register_1|SSICR_1|32|H'E820B800|32|
||Status register_1|SSISR_1|32|H'E820B804|32|
||FIFO control register_1|SSIFCR_1|32|H'E820B810|32|
||FIFO status register_1|SSIFSR_1|32|H'E820B814|32|
||Transmit FIFO data register_1|SSIFTDR_1|32|H'E820B818|32|
||Receive FIFO data register_1|SSIFRDR_1|32|H'E820B81C|32|
||TDM mode register_1|SSITDMR_1|32|H'E820B820|32|
||FC control register_1|SSIFCCR_1|32|H'E820B824|32|
||FC mode register_1|SSIFCMR_1|32|H'E820B828|32|
||FC status register_1|SSIFCSR_1|32|H'E820B82C|32|
||Control register_2|SSICR_2|32|H'E820C000|32|
||Status register_2|SSISR_2|32|H'E820C004|32|
||FIFO control register_2|SSIFCR_2|32|H'E820C010|32|
||FIFO status register_2|SSIFSR_2|32|H'E820C014|32|
||Transmit FIFO data register_2|SSIFTDR_2|32|H'E820C018|32|
||Receive FIFO data register_2|SSIFRDR_2|32|H'E820C01C|32|
||TDM mode register_2|SSITDMR_2|32|H'E820C020|32|
||FC control register_2|SSIFCCR_2|32|H'E820C024|32|
||FC mode register_2|SSIFCMR_2|32|H'E820C028|32|
||FC status register_2|SSIFCSR_2|32|H'E820C02C|32|
||Control register_3|SSICR_3|32|H'E820C800|32|
||Status register_3|SSISR_3|32|H'E820C804|32|
||FIFO control register_3|SSIFCR_3|32|H'E820C810|32|
||FIFO status register_3|SSIFSR_3|32|H'E820C814|32|
||Transmit FIFO data register_3|SSIFTDR_3|32|H'E820C818|32|
||Receive FIFO data register_3|SSIFRDR_3|32|H'E820C81C|32|
||TDM mode register_3|SSITDMR_3|32|H'E820C820|32|
||FC control register_3|SSIFCCR_3|32|H'E820C824|32|
||FC mode register_3|SSIFCMR_3|32|H'E820C828|32|
||FC status register_3|SSIFCSR_3|32|H'E820C82C|32|
|Media local bus*1|Device Control Cfg Register|DCCR|32|H'E8034000|32|
||System Status Cfg Register|SSCR|32|H'E8034004|32|
||System Data Cfg Register|SDCR|32|H'E8034008|32|
||System Mask Cfg Register|SMCR|32|H'E803400C|32|
||Version Control Cfg Register|VCCR|32|H'E803401C|32|
||Synchronous Base Address Cfg Register|SBCR|32|H'E8034020|32|
||Asynchronous Base Address Cfg Register|ABCR|32|H'E8034024|32|
||Control Base Address Cfg Register|CBCR|32|H'E8034028|32|
||Isochronous Base Address Cfg Register|IBCR|32|H'E803402C|32|
||Channel Interrupt Cfg Register|CICR|32|H'E8034030|32|
||Channel 0 Entry Cfg Register|CECR0|32|H'E8034040|32|
||Channel 0 Status Cfg Register|CSCR0|32|H'E8034044|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Media local bus*1|Channel 0 Current Buffer Cfg Register|CCBCR0|32|H'E8034048|32|
||Channel 0 Next Buffer Cfg Register|CNBCR0|32|H'E803404C|32|
||Channel 1 Entry Cfg Register|CECR1|32|H'E8034050|32|
||Channel 1 Status Cfg Register|CSCR1|32|H'E8034054|32|
||Channel 1 Current Buffer Cfg Register|CCBCR1|32|H'E8034058|32|
||Channel 1 Next Buffer Cfg Register|CNBCR1|32|H'E803405C|32|
||Channel 2 Entry Cfg Register|CECR2|32|H'E8034060|32|
||Channel 2 Status Cfg Register|CSCR2|32|H'E8034064|32|
||Channel 2 Current Buffer Cfg Register|CCBCR2|32|H'E8034068|32|
||Channel 2 Next Buffer Cfg Register|CNBCR2|32|H'E803406C|32|
||Channel 3 Entry Cfg Register|CECR3|32|H'E8034070|32|
||Channel 3 Status Cfg Register|CSCR3|32|H'E8034074|32|
||Channel 3 Current Buffer Cfg Register|CCBCR3|32|H'E8034078|32|
||Channel 3 Next Buffer Cfg Register|CNBCR3|32|H'E803407C|32|
||Channel 4 Entry Cfg Register|CECR4|32|H'E8034080|32|
||Channel 4 Status Cfg Register|CSCR4|32|H'E8034084|32|
||Channel 4 Current Buffer Cfg Register|CCBCR4|32|H'E8034088|32|
||Channel 4 Next Buffer Cfg Register|CNBCR4|32|H'E803408C|32|
||Channel 5 Entry Cfg Register|CECR5|32|H'E8034090|32|
||Channel 5 Status Cfg Register|CSCR5|32|H'E8034094|32|
||Channel 5 Current Buffer Cfg Register|CCBCR5|32|H'E8034098|32|
||Channel 5 Next Buffer Cfg Register|CNBCR5|32|H'E803409C|32|
||Channel 6 Entry Cfg Register|CECR6|32|H'E80340A0|32|
||Channel 6 Status Cfg Register|CSCR6|32|H'E80340A4|32|
||Channel 6 Current Buffer Cfg Register|CCBCR6|32|H'E80340A8|32|
||Channel 6 Next Buffer Cfg Register|CNBCR6|32|H'E80340AC|32|
||Channel 7 Entry Cfg Register|CECR7|32|H'E80340B0|32|
||Channel 7 Status Cfg Register|CSCR7|32|H'E80340B4|32|
||Channel 7 Current Buffer Cfg Register|CCBCR7|32|H'E80340B8|32|
||Channel 7 Next Buffer Cfg Register|CNBCR7|32|H'E80340BC|32|
||Channel 8 Entry Cfg Register|CECR8|32|H'E80340C0|32|
||Channel 8 Status Cfg Register|CSCR8|32|H'E80340C4|32|
||Channel 8 Current Buffer Cfg Register|CCBCR8|32|H'E80340C8|32|
||Channel 8 Next Buffer Cfg Register|CNBCR8|32|H'E80340CC|32|
||Channel 9 Entry Cfg Register|CECR9|32|H'E80340D0|32|
||Channel 9 Status Cfg Register|CSCR9|32|H'E80340D4|32|
||Channel 9 Current Buffer Cfg Register|CCBCR9|32|H'E80340D8|32|
||Channel 9 Next Buffer Cfg Register|CNBCR9|32|H'E80340DC|32|
||Channel 10 Entry Cfg Register|CECR10|32|H'E80340E0|32|
||Channel 10 Status Cfg Register|CSCR10|32|H'E80340E4|32|
||Channel 10 Current Buffer Cfg Register|CCBCR10|32|H'E80340E8|32|
||Channel 10 Next Buffer Cfg Register|CNBCR10|32|H'E80340EC|32|
||Channel 11 Entry Cfg Register|CECR11|32|H'E80340F0|32|
||Channel 11 Status Cfg Register|CSCR11|32|H'E80340F4|32|
||Channel 11 Current Buffer Cfg Register|CCBCR11|32|H'E80340F8|32|
||Channel 11 Next Buffer Cfg Register|CNBCR11|32|H'E80340FC|32|
||Channel 12 Entry Cfg Register|CECR12|32|H'E8034100|32|
||Channel 12 Status Cfg Register|CSCR12|32|H'E8034104|32|
||Channel 12 Current Buffer Cfg Register|CCBCR12|32|H'E8034108|32|
||Channel 12 Next Buffer Cfg Register|CNBCR12|32|H'E803410C|32|
||Channel 13 Entry Cfg Register|CECR13|32|H'E8034110|32|
||Channel 13 Status Cfg Register|CSCR13|32|H'E8034114|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Media local bus*1|Channel 13 Current Buffer Cfg Register|CCBCR13|32|H'E8034118|32|
||Channel 13 Next Buffer Cfg Register|CNBCR13|32|H'E803411C|32|
||Channel 14 Entry Cfg Register|CECR14|32|H'E8034120|32|
||Channel 14 Status Cfg Register|CSCR14|32|H'E8034124|32|
||Channel 14 Current Buffer Cfg Register|CCBCR14|32|H'E8034128|32|
||Channel 14 Next Buffer Cfg Register|CNBCR14|32|H'E803412C|32|
||Channel 15 Entry Cfg Register|CECR15|32|H'E8034130|32|
||Channel 15 Status Cfg Register|CSCR15|32|H'E8034134|32|
||Channel 15 Current Buffer Cfg Register|CCBCR15|32|H'E8034138|32|
||Channel 15 Next Buffer Cfg Register|CNBCR15|32|H'E803413C|32|
||Channel 16 Entry Cfg Register|CECR16|32|H'E8034140|32|
||Channel 16 Status Cfg Register|CSCR16|32|H'E8034144|32|
||Channel 16 Current Buffer Cfg Register|CCBCR16|32|H'E8034148|32|
||Channel 16 Next Buffer Cfg Register|CNBCR16|32|H'E803414C|32|
||Channel 17 Entry Cfg Register|CECR17|32|H'E8034150|32|
||Channel 17 Status Cfg Register|CSCR17|32|H'E8034154|32|
||Channel 17 Current Buffer Cfg Register|CCBCR17|32|H'E8034158|32|
||Channel 17 Next Buffer Cfg Register|CNBCR17|32|H'E803415C|32|
||Channel 18 Entry Cfg Register|CECR18|32|H'E8034160|32|
||Channel 18 Status Cfg Register|CSCR18|32|H'E8034164|32|
||Channel 18 Current Buffer Cfg Register|CCBCR18|32|H'E8034168|32|
||Channel 18 Next Buffer Cfg Register|CNBCR18|32|H'E803416C|32|
||Channel 19 Entry Cfg Register|CECR19|32|H'E8034170|32|
||Channel 19 Status Cfg Register|CSCR19|32|H'E8034174|32|
||Channel 19 Current Buffer Cfg Register|CCBCR19|32|H'E8034178|32|
||Channel 19 Next Buffer Cfg Register|CNBCR19|32|H'E803417C|32|
||Channel 20 Entry Cfg Register|CECR20|32|H'E8034180|32|
||Channel 20 Status Cfg Register|CSCR20|32|H'E8034184|32|
||Channel 20 Current Buffer Cfg Register|CCBCR20|32|H'E8034188|32|
||Channel 20 Next Buffer Cfg Register|CNBCR20|32|H'E803418C|32|
||Channel 21 Entry Cfg Register|CECR21|32|H'E8034190|32|
||Channel 21 Status Cfg Register|CSCR21|32|H'E8034194|32|
||Channel 21 Current Buffer Cfg Register|CCBCR21|32|H'E8034198|32|
||Channel 21 Next Buffer Cfg Register|CNBCR21|32|H'E803419C|32|
||Channel 22 Entry Cfg Register|CECR22|32|H'E80341A0|32|
||Channel 22 Status Cfg Register|CSCR22|32|H'E80341A4|32|
||Channel 22 Current Buffer Cfg Register|CCBCR22|32|H'E80341A8|32|
||Channel 22 Next Buffer Cfg Register|CNBCR22|32|H'E80341AC|32|
||Channel 23 Entry Cfg Register|CECR23|32|H'E80341B0|32|
||Channel 23 Status Cfg Register|CSCR23|32|H'E80341B4|32|
||Channel 23 Current Buffer Cfg Register|CCBCR23|32|H'E80341B8|32|
||Channel 23 Next Buffer Cfg Register|CNBCR23|32|H'E80341BC|32|
||Channel 24 Entry Cfg Register|CECR24|32|H'E80341C0|32|
||Channel 24 Status Cfg Register|CSCR24|32|H'E80341C4|32|
||Channel 24 Current Buffer Cfg Register|CCBCR24|32|H'E80341C8|32|
||Channel 24 Next Buffer Cfg Register|CNBCR24|32|H'E80341CC|32|
||Channel 25 Entry Cfg Register|CECR25|32|H'E80341D0|32|
||Channel 25 Status Cfg Register|CSCR25|32|H'E80341D4|32|
||Channel 25 Current Buffer Cfg Register|CCBCR25|32|H'E80341D8|32|
||Channel 25 Next Buffer Cfg Register|CNBCR25|32|H'E80341DC|32|
||Channel 26 Entry Cfg Register|CECR26|32|H'E80341E0|32|
||Channel 26 Status Cfg Register|CSCR26|32|H'E80341E4|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Media local bus*1|Channel 26 Current Buffer Cfg Register|CCBCR26|32|H'E80341E8|32|
||Channel 26 Next Buffer Cfg Register|CNBCR26|32|H'E80341EC|32|
||Channel 27 Entry Cfg Register|CECR27|32|H'E80341F0|32|
||Channel 27 Status Cfg Register|CSCR27|32|H'E80341F4|32|
||Channel 27 Current Buffer Cfg Register|CCBCR27|32|H'E80341F8|32|
||Channel 27 Next Buffer Cfg Register|CNBCR27|32|H'E80341FC|32|
||Channel 28 Entry Cfg Register|CECR28|32|H'E8034200|32|
||Channel 28 Status Cfg Register|CSCR28|32|H'E8034204|32|
||Channel 28 Current Buffer Cfg Register|CCBCR28|32|H'E8034208|32|
||Channel 28 Next Buffer Cfg Register|CNBCR28|32|H'E803420C|32|
||Channel 29 Entry Cfg Register|CECR29|32|H'E8034210|32|
||Channel 29 Status Cfg Register|CSCR29|32|H'E8034214|32|
||Channel 29 Current Buffer Cfg Register|CCBCR29|32|H'E8034218|32|
||Channel 29 Next Buffer Cfg Register|CNBCR29|32|H'E803421C|32|
||Channel 30 Entry Cfg Register|CECR30|32|H'E8034220|32|
||Channel 30 Status Cfg Register|CSCR30|32|H'E8034224|32|
||Channel 30 Current Buffer Cfg Register|CCBCR30|32|H'E8034228|32|
||Channel 30 Next Buffer Cfg Register|CNBCR30|32|H'E803422C|32|
||Local Channel 0 Buffer Cfg Register|LCBCR0|32|H'E8034280|32|
||Local Channel 1 Buffer Cfg Register|LCBCR1|32|H'E8034284|32|
||Local Channel 2 Buffer Cfg Register|LCBCR2|32|H'E8034288|32|
||Local Channel 3 Buffer Cfg Register|LCBCR3|32|H'E803428C|32|
||Local Channel 4 Buffer Cfg Register|LCBCR4|32|H'E8034290|32|
||Local Channel 5 Buffer Cfg Register|LCBCR5|32|H'E8034294|32|
||Local Channel 6 Buffer Cfg Register|LCBCR6|32|H'E8034298|32|
||Local Channel 7 Buffer Cfg Register|LCBCR7|32|H'E803429C|32|
||Local Channel 8 Buffer Cfg Register|LCBCR8|32|H'E80342A0|32|
||Local Channel 9 Buffer Cfg Register|LCBCR9|32|H'E80342A4|32|
||Local Channel 10 Buffer Cfg Register|LCBCR10|32|H'E80342A8|32|
||Local Channel 11 Buffer Cfg Register|LCBCR11|32|H'E80342AC|32|
||Local Channel 12 Buffer Cfg Register|LCBCR12|32|H'E80342B0|32|
||Local Channel 13 Buffer Cfg Register|LCBCR13|32|H'E80342B4|32|
||Local Channel 14 Buffer Cfg Register|LCBCR14|32|H'E80342B8|32|
||Local Channel 15 Buffer Cfg Register|LCBCR15|32|H'E80342BC|32|
||Local Channel 16 Buffer Cfg Register|LCBCR16|32|H'E80342C0|32|
||Local Channel 17 Buffer Cfg Register|LCBCR17|32|H'E80342C4|32|
||Local Channel 18 Buffer Cfg Register|LCBCR18|32|H'E80342C8|32|
||Local Channel 19 Buffer Cfg Register|LCBCR19|32|H'E80342CC|32|
||Local Channel 20 Buffer Cfg Register|LCBCR20|32|H'E80342D0|32|
||Local Channel 21 Buffer Cfg Register|LCBCR21|32|H'E80342D4|32|
||Local Channel 22 Buffer Cfg Register|LCBCR22|32|H'E80342D8|32|
||Local Channel 23 Buffer Cfg Register|LCBCR23|32|H'E80342DC|32|
||Local Channel 24 Buffer Cfg Register|LCBCR24|32|H'E80342E0|32|
||Local Channel 25 Buffer Cfg Register|LCBCR25|32|H'E80342E4|32|
||Local Channel 26 Buffer Cfg Register|LCBCR26|32|H'E80342E8|32|
||Local Channel 27 Buffer Cfg Register|LCBCR27|32|H'E80342EC|32|
||Local Channel 28 Buffer Cfg Register|LCBCR28|32|H'E80342F0|32|
||Local Channel 29 Buffer Cfg Register|LCBCR29|32|H'E80342F4|32|
||Local Channel 30 Buffer Cfg Register|LCBCR30|32|H'E80342F8|32|
|CAN interface|Channel m configuration register (m = 0, 1)|RSCAN0CmCFG (m = 0, 1)|32|H'E803A000 + m<br>* H'0010|8, 16, 32|
||Channel m control register (m = 0, 1)|RSCAN0CmCTR (m = 0, 1)|32|H'E803A004 + m<br>* H'0010|8, 16, 32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|CAN interface|Channel m status register (m = 0, 1)|RSCAN0CmSTS (m = 0, 1)|32|H'E803A008 + m<br>* H'0010|8, 16, 32|
||Channel m error flag register (m = 0, 1)|RSCAN0CmERFL (m = 0, 1)|32|H'E803A00C + m<br>* H'0010|8, 16, 32|
||Global configuration register|RSCAN0GCFG|32|H'E803A084|8, 16, 32|
||Global control register|RSCAN0GCTR|32|H'E803A088|8, 16, 32|
||Global status register|RSCAN0GSTS|32|H'E803A08C|8, 16, 32|
||Global error flag register|RSCAN0GERFL|32|H'E803A090|8, 16, 32|
||Global timestamp counter register|RSCAN0GTSC|32|H'E803A094|16, 32|
||Receive rule entry control register|RSCAN0GAFLECTR|32|H'E803A098|8, 16, 32|
||Receive rule configuration register 0|RSCAN0GAFLCFG0|32|H'E803A09C|8, 16, 32|
||Receive buffer number register|RSCAN0RMNB|32|H'E803A0A4|8, 16, 32|
||Receive buffer new data register y (y = 0)|RSCAN0RMNDy (y = 0)|32|H'E803A0A8 + y<br>*H'0004|8, 16, 32|
||Receive FIFO buffer configuration and control register x (x = 0<br>to 7)|RSCAN0RFCCx (x = 0 to 7)|32|H'E803A0B8 + x<br>* H'0004|8, 16, 32|
||Receive FIFO buffer status register x (x = 0 to 7)|RSCAN0RFSTSx (x = 0 to 7)|32|H'E803A0D8 + x<br>* H'0004|8, 16, 32|
||Receive FIFO buffer pointer control register x (x = 0 to 7)|RSCAN0RFPCTRx (x = 0 to 7)|32|H'E803A0F8 + x *<br>H'0004|8, 16, 32|
||Transmit/receive FIFO buffer configuration and control register<br>k (k = 0 to 5)|RSCAN0CFCCk (k = 0 to 5)|32|H'E803A118 + k *<br>H'0004|8, 16, 32|
||Transmit/receive FIFO buffer status register k (k = 0 to 5)|RSCAN0CFSTSk (k = 0 to 5)|32|H'E803A178 + k *<br>H'0004|8, 16, 32|
||Transmit/receive FIFO buffer pointer control register k (k = 0 to<br>5)|RSCAN0CFPCTRk (k = 0 to 5)|32|H'E803A1D8 + k<br>* H'0004|8, 16, 32|
||FIFO empty status register|RSCAN0FESTS|32|H'E803A238|8, 16, 32|
||FIFO full status register|RSCAN0FFSTS|32|H'E803A23C|8, 16, 32|
||FIFO Msg lost status register|RSCAN0FMSTS|32|H'E803A240|8, 16, 32|
||Receive FIFO buffer interrupt flag status register|RSCAN0RFISTS|32|H'E803A244|8, 16, 32|
||Transmit/receive FIFO buffer receive interrupt flag status<br>register|RSCAN0CFRISTS|32|H'E803A248|8, 16, 32|
||Transmit/receive FIFO buffer transmit interrupt flag status<br>register|RSCAN0CFTISTS|32|H'E803A24C|8, 16, 32|
||Transmit buffer control register p (p = 0 to 31)|RSCAN0TMCp (p = 0 to 31)|8|H'E803A250 + p *<br>H'0001|8|
||Transmit buffer status register p (p = 0 to 31)|RSCAN0TMSTSp (p = 0 to 31)|8|H'E803A2D0 + p<br>* H'0001|8|
||Transmit buffer transmit request status register y (y = 0)|RSCAN0TMTRSTSy (y = 0)|32|H'E803A350 + y *<br>H'0004|8, 16, 32|
||Transmit buffer transmit abort request status register y (y = 0)|RSCAN0TMTARSTSy<br>(y = 0)|32|H'E803A360 + y *<br>H'0004|8, 16, 32|
||Transmit buffer transmit complete status register y (y = 0)|RSCAN0TMTCSTSy (y = 0)|32|H'E803A370 + y *<br>H'0004|8, 16, 32|
||Transmit buffer transmit abort status register y (y = 0)|RSCAN0TMTASTSy (y = 0)|32|H'E803A380 + y *<br>H'0004|8, 16, 32|
||Transmit buffer interrupt enable configuration register y (y = 0)|RSCAN0TMIECy (y = 0)|32|H'E803A390 + y *<br>H'0004|8, 16, 32|
||Transmit queue configuration and control register m (m = 0, 1)|RSCAN0TXQCCm (m = 0, 1)|32|H'E803A3A0 + m<br>* H'0010|8, 16, 32|
||Transmit queue status register m (m = 0, 1)|RSCAN0TXQSTSm (m = 0, 1)|32|H'E803A3C0 + m<br>* H'0004|8, 16, 32|
||Transmit queue pointer control register m (m = 0, 1)|RSCAN0TXQPCTRm<br>(m = 0, 1)|32|H'E803A3E0 + m<br>* H'0004|8, 16, 32|
||Transmit history configuration and control register m (m = 0, 1)|RSCAN0THLCCm (m = 0, 1)|32|H'E803A400 + m<br>* H'0004|8, 16, 32|
||Transmit history status register m (m = 0, 1)|RSCAN0THLSTSm (m = 0, 1)|32|H'E803A420 + m<br>* H'0004|8, 16, 32|
||Transmit history pointer control register m (m = 0, 1)|RSCAN0THLPCTRm<br>(m = 0, 1)|32|H'E803A440 + m<br>* H'0004|8, 16, 32|
||Global TX interrupt status register 0|RSCAN0GTINTSTS0|32|H'E803A460|8, 16, 32|
||Global test configuration register|RSCAN0GTSTCFG|32|H'E803A468|8, 16, 32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|CAN interface|Global test control register|RSCAN0GTSTCTR|32|H'E803A46C|8, 16, 32|
||Global lock key register|RSCAN0GLOCKK|32|H'E803A47C|16, 32|
||Receive rule ID register j (j = 0 to 15)|RSCAN0GAFLIDj (j = 0 to 15)|32|H'E803A500 + j *<br>H'0010|8, 16, 32|
||Receive rule mask register j (j = 0 to 15)|RSCAN0GAFLMj (j = 0 to 15)|32|H'E803A504 + j *<br>H'0010|8, 16, 32|
||Receive rule pointer 0 register j (j = 0 to 15)|RSCAN0GAFLP0j (j = 0 to 15)|32|H'E803A508 + j *<br>H'0010|8, 16, 32|
||Receive rule pointer 1 register j (j = 0 to 15)|RSCAN0GAFLP1j (j = 0 to 15)|32|H'E803A50C + j *<br>H'0010|8, 16, 32|
||Receive buffer ID register q (q = 0 to 31)|RSCAN0RMIDq (q = 0 to 31)|32|H'E803A600 + q *<br>H'0010|8, 16, 32|
||Receive buffer pointer register q (q = 0 to 31)|RSCAN0RMPTRq (q = 0 to 31)|32|H'E803A604 + q *<br>H'0010|8, 16, 32|
||Receive buffer data field 0 register q (q = 0 to 31)|RSCAN0RMDF0q (q = 0 to 31)|32|H'E803A608 + q *<br>H'0010|8, 16, 32|
||Receive buffer data field 1 register q (q = 0 to 31)|RSCAN0RMDF1q (q = 0 to 31)|32|H'E803A60C + q<br>* H'0010|8, 16, 32|
||Receive FIFO buffer access ID register x (x = 0 to 7)|RSCAN0RFIDx (x = 0 to 7)|32|H'E803AE00 + x<br>* H'0010|8, 16, 32|
||Receive FIFO buffer access pointer register x (x = 0 to 7)|RSCAN0RFPTRx (x = 0 to 7)|32|H'E803AE04 + x<br>* H'0010|8, 16, 32|
||Receive FIFO buffer access data field 0 register x (x = 0 to 7)|RSCAN0RFDF0x (x = 0 to 7)|32|H'E803AE08 + x<br>* H'0010|8, 16, 32|
||Receive FIFO buffer access data field 1 register x (x = 0 to 7)|RSCAN0RFDF1x (x = 0 to 7)|32|H'E803AE0C + x<br>* H'0010|8, 16, 32|
||Transmit/receive FIFO buffer access ID register k (k = 0 to 5)|RSCAN0CFIDk (k = 0 to 5)|32|H'E803AE80 + k<br>* H'0010|8, 16, 32|
||Transmit/receive FIFO buffer access pointer register k (k = 0<br>to 5)|RSCAN0CFPTRk (k = 0 to 5)|32|H'E803AE84 + k<br>* H'0010|8, 16, 32|
||Transmit/receive FIFO buffer access data field 0 register k (k =<br>0 to 5)|RSCAN0CFDF0k (k = 0 to 5)|32|H'E803AE88 + k<br>* H'0010|8, 16, 32|
||Transmit/receive FIFO buffer access data field 1 register k (k =<br>0 to 5)|RSCAN0CFDF1k (k = 0 to 5)|32|H'E803AE8C + k<br>* H'0010|8, 16, 32|
||Transmit buffer ID register p (p = 0 to 31)|RSCAN0TMIDp (p = 0 to 31)|32|H'E803B000 + p *<br>H'0010|8, 16, 32|
||Transmit buffer pointer register p (p = 0 to 31)|RSCAN0TMPTRp (p = 0 to 31)|32|H'E803B004 + p *<br>H'0010|8, 16, 32|
||Transmit buffer data field 0 register p (p = 0 to 31)|RSCAN0TMDF0p (p = 0 to 31)|32|H'E803B008 + p *<br>H'0010|8, 16, 32|
||Transmit buffer data field 1 register p (p = 0 to 31)|RSCAN0TMDF1p (p = 0 to 31)|32|H'E803B00C + p<br>* H'0010|8, 16, 32|
||Transmit history access register m (m = 0, 1)|RSCAN0THLACCm (m = 0, 1)|32|H'E803B800 + m<br>* H'0004|8, 16, 32|
|IEBus controller*1|IEBB0 bus control register|IEBB0BCR|8|H'FCFEF000|8|
||IEBB0 power save register|IEBB0PSR|8|H'FCFEF004|8|
||IEBB0 unit address register|IEBB0UAR|16|H'FCFEF008|16|
||IEBB0 slave address register|IEBB0SAR|16|H'FCFEF00C|16|
||IEBB0 partner address register|IEBB0PAR|16|H'FCFEF010|16|
||IEBB0 reception slave address register|IEBB0RSA|16|H'FCFEF014|16|
||IEBB0 control data register|IEBB0CDR|8|H'FCFEF018|8|
||IEBB0 transmission control data register|IEBB0TCD|8|H'FCFEF01C|8|
||IEBB0 reception control data register|IEBB0RCD|8|H'FCFEF020|8|
||IEBB0 message length register|IEBB0DLR|8|H'FCFEF024|8|
||IEBB0 transmission message length register|IEBB0TDL|8|H'FCFEF028|8|
||IEBB0 reception message length register|IEBB0RDL|8|H'FCFEF02C|8|
||IEBB0 clock selection register|IEBB0CKS|8|H'FCFEF030|8|
||IEBB0 transfer mode setting register|IEBB0TMS|8|H'FCFEF034|8|
||IEBB0 pointer clear register|IEBB0PCR|8|H'FCFEF038|8|
||IEBB0 buffer status register|IEBB0BSR|16|H'FCFEF03C|16|
||IEBB0 slave status register|IEBB0SSR|8|H'FCFEF040|8|
||IEBB0 unit status register|IEBB0USR|8|H'FCFEF044|8|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|IEBus controller*1|IEBB0 interrupt status register|IEBB0ISR|8|H'FCFEF048|8|
||IEBB0 error status register|IEBB0ESR|8|H'FCFEF04C|8|
||IEBB0 field status register|IEBB0FSR|8|H'FCFEF050|8|
||IEBB0 success count register|IEBB0SCR|8|H'FCFEF054|8|
||IEBB0 communication count register|IEBB0CCR|8|H'FCFEF058|8|
||IEBB0 status clear register 0|IEBB0STC0|8|H'FCFEF05C|8|
||IEBB0 status clear register 1|IEBB0STC1|8|H'FCFEF060|8|
||IEBB0 data register|IEBB0DR|8|H'FCFEF064|8|
|Renesas SPDIF interface|Transmitter channel 1 audio register|TLCA|32|H'E8012000|32|
||Transmitter channel 2 audio register|TRCA|32|H'E8012004|32|
||Transmitter channel 1 status register|TLCS|32|H'E8012008|32|
||Transmitter channel 2 status register|TRCS|32|H'E801200C|32|
||Transmitter user data register|TUI|32|H'E8012010|32|
||Receiver channel 1 audio register|RLCA|32|H'E8012014|32|
||Receiver channel 2 audio register|RRCA|32|H'E8012018|32|
||Receiver channel 1 status register|RLCS|32|H'E801201C|32|
||Receiver channel 2 status register|RRCS|32|H'E8012020|32|
||Receiver user data register|RUI|32|H'E8012024|32|
||Control register|CTRL|32|H'E8012028|32|
||Status register|STAT|32|H'E801202C|32|
||Transmitter DMA audio data register|TDAD|32|H'E8012030|32|
||Receiver DMA audio data register|RDAD|32|H'E8012034|32|
|CD-ROM decoder*1|Enable control register|CROMEN|8|H'E8005000|8|
||Sync code-based synchronization control register|CROMSY0|8|H'E8005001|8|
||Decoding mode control register|CROMCTL0|8|H'E8005002|8|
||EDC/ECC check control register|CROMCTL1|8|H'E8005003|8|
||Automatic decoding stop control register|CROMCTL3|8|H'E8005005|8|
||Decoding option setting control register|CROMCTL4|8|H'E8005006|8|
||HEAD20 to HEAD22 representation control register|CROMCTL5|8|H'E8005007|8|
||Sync code status register|CROMST0|8|H'E8005008|8|
||Post-ECC header error status register|CROMST1|8|H'E8005009|8|
||Post-ECC subheader error status register|CROMST3|8|H'E800500B|8|
||Header/subheader validity check status register|CROMST4|8|H'E800500C|8|
||Mode determination and link sector detection status register|CROMST5|8|H'E800500D|8|
||ECC/EDC error status register|CROMST6|8|H'E800500E|8|
||Buffer status register|CBUFST0|8|H'E8005014|8|
||Decoding stoppage source status register|CBUFST1|8|H'E8005015|8|
||Buffer overflow status register|CBUFST2|8|H'E8005016|8|
||Pre-ECC correction header: minutes data register|HEAD00|8|H'E8005018|8|
||Pre-ECC correction header: seconds data register|HEAD01|8|H'E8005019|8|
||Pre-ECC correction header: frames (1/75 second) data<br>register|HEAD02|8|H'E800501A|8|
||Pre-ECC correction header: mode data register|HEAD03|8|H'E800501B|8|
||Pre-ECC correction subheader: file number (byte 16) data<br>register|SHEAD00|8|H'E800501C|8|
||Pre-ECC correction subheader: channel number (byte 17)<br>data register|SHEAD01|8|H'E800501D|8|
||Pre-ECC correction subheader: sub-mode (byte 18) data<br>register|SHEAD02|8|H'E800501E|8|
||Pre-ECC correction subheader: data type (byte 19) data<br>register|SHEAD03|8|H'E800501F|8|
||Pre-ECC correction subheader: file number (byte 20) data<br>register|SHEAD04|8|H'E8005020|8|
||Pre-ECC correction subheader: channel number (byte 21)<br>data register|SHEAD05|8|H'E8005021|8|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|CD-ROM decoder*1|Pre-ECC correction subheader: sub-mode (byte 22) data<br>register|SHEAD06|8|H'E8005022|8|
||Pre-ECC correction subheader: data type (byte 23) data<br>register|SHEAD07|8|H'E8005023|8|
||Post-ECC correction header: minutes data register|HEAD20|8|H'E8005024|8|
||Post-ECC correction header: seconds data register|HEAD21|8|H'E8005025|8|
||Post-ECC correction header: frames (1/75 second) data<br>register|HEAD22|8|H'E8005026|8|
||Post-ECC correction header: mode data register|HEAD23|8|H'E8005027|8|
||Post-ECC correction subheader: file number (byte 16) data<br>register|SHEAD20|8|H'E8005028|8|
||Post-ECC correction subheader: channel number (byte 17)<br>data register|SHEAD21|8|H'E8005029|8|
||Post-ECC correction subheader: sub-mode (byte 18) data<br>register|SHEAD22|8|H'E800502A|8|
||Post-ECC correction subheader: data type (byte 19) data<br>register|SHEAD23|8|H'E800502B|8|
||Post-ECC correction subheader: file number (byte 20) data<br>register|SHEAD24|8|H'E800502C|8|
||Post-ECC correction subheader: channel number (byte 21)<br>data register|SHEAD25|8|H'E800502D|8|
||Post-ECC correction subheader: sub-mode (byte 22) data<br>register|SHEAD26|8|H'E800502E|8|
||Post-ECC correction subheader: data type (byte 23) data<br>register|SHEAD27|8|H'E800502F|8|
||Automatic buffering setting control register|CBUFCTL0|8|H'E8005040|8|
||Automatic buffering start sector setting: minutes control<br>register|CBUFCTL1|8|H'E8005041|8|
||Automatic buffering start sector setting: seconds control<br>register|CBUFCTL2|8|H'E8005042|8|
||Automatic buffering start sector setting: frames control register|CBUFCTL3|8|H'E8005043|8|
||ISY interrupt source mask control register|CROMST0M|8|H'E8005045|8|
||CD-ROM decoder reset control register|ROMDECRST|8|H'E8005100|8|
||CD-ROM decoder reset status register|RSTSTAT|8|H'E8005101|8|
||Serial sound interface data control register|SSI|8|H'E8005102|8|
||Interrupt flag register|INTHOLD|8|H'E8005108|8|
||Interrupt source mask control register|INHINT|8|H'E8005109|8|
||CD-ROM decoder stream data input register|STRMDIN0|16|H'E8005200|16 (R/W),<br>32 (W)|
||CD-ROM decoder stream data input register|STRMDIN2|16|H'E8005202|16|
||CD-ROM decoder stream data output register|STRMDOUT0|16|H'E8005204|16|
|LIN interface*1|LIN wake-up baud rate selector register|RLN30LWBR|8|H'FCFE9001|8|
||LIN baud rate prescaler 0 register|RLN30LBRP0|8|H'FCFE9002|8|
||LIN baud rate prescaler 1 register|RLN30LBRP1|8|H'FCFE9003|8|
||LIN self-test control register|RLN30LSTC|8|H'FCFE9004|8|
||LIN mode register|RLN30LMD|8|H'FCFE9008|8|
||LIN break field configuration register|RLN30LBFC|8|H'FCFE9009|8|
||LIN space configuration register|RLN30LSC|8|H'FCFE900A|8|
||LIN wake-up configuration register|RLN30LWUP|8|H'FCFE900B|8|
||LIN interrupt enable register|RLN30LIE|8|H'FCFE900C|8|
||LIN error detection enable register|RLN30LEDE|8|H'FCFE900D|8|
||LIN control register|RLN30LCUC|8|H'FCFE900E|8|
||LIN transmission control register|RLN30LTRC|8|H'FCFE9010|8|
||LIN mode status register|RLN30LMST|8|H'FCFE9011|8|
||LIN status register|RLN30LST|8|H'FCFE9012|8|
||LIN error status register|RLN30LEST|8|H'FCFE9013|8|
||LIN data field configuration register|RLN30LDFC|8|H'FCFE9014|8|
||LIN ID buffer register|RLN30LIDB|8|H'FCFE9015|8|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|LIN interface*1|LIN checksum buffer register|RLN30LCBR|8|H'FCFE9016|8|
||LIN data buffer 1 register|RLN30LDB1|8|H'FCFE9018|8|
||LIN data buffer 2 register|RLN30LDB2|8|H'FCFE9019|8|
||LIN data buffer 3 register|RLN30LDB3|8|H'FCFE901A|8|
||LIN data buffer 4 register|RLN30LDB4|8|H'FCFE901B|8|
||LIN data buffer 5 register|RLN30LDB5|8|H'FCFE901C|8|
||LIN data buffer 6 register|RLN30LDB6|8|H'FCFE901D|8|
||LIN data buffer 7 register|RLN30LDB7|8|H'FCFE901E|8|
||LIN data buffer 8 register|RLN30LDB8|8|H'FCFE901F|8|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Ethernet controller|Software reset register|ARSTR|32|H'E8204800|32|
||E-MAC mode register|ECMR0|32|H'E8203500|32|
||E-MAC status register|ECSR0|32|H'E8203510|32|
||E-MAC interrupt permission register|ECSIPR0|32|H'E8203518|32|
||PHY interface register|PIR0|32|H'E8203520|32|
||MAC address high register|MAHR0|32|H'E82035C0|32|
||MAC address low register|MALR0|32|H'E82035C8|32|
||Receive frame length register|RFLR0|32|H'E8203508|32|
||CRC error frame receive counter register|CEFCR0|32|H'E8203740|32|
||Frame receive error counter register|FRECR0|32|H'E8203748|32|
||Too-short frame receive counter register|TSFRCR0|32|H'E8203750|32|
||Too-long frame receive counter register|TLFRCR0|32|H'E8203758|32|
||Residual-bit frame receive counter register|RFCR0|32|H'E8203760|32|
||Multicast address frame receive counter register|MAFCR0|32|H'E8203778|32|
||Automatic PAUSE frame register|APR0|32|H'E8203554|32|
||Manual PAUSE frame register|MPR0|32|H'E8203558|32|
||Automatic PAUSE frame retransmit count register|TPAUSER0|32|H'E8203564|32|
||PAUSE frame transmit counter register|PFTCR0|32|H'E820355C|32|
||PAUSE frame receive counter register|PFRCR0|32|H'E8203560|32|
||TSU counter reset register|TSU_CTRST|32|H'E8204804|32|
||CAM entry table specification enable register (common)|TSU_FWSLC|32|H’E8204838|32|
||VLANtag set register|TSU_VTAG0|32|H'E8204858|32|
||CAM entry table busy register|TSU_ADSBSY|32|H'E8204860|32|
||CAM entry table enable register|TSU_TEN|32|H'E8204864|32|
||CAM entry table POST 1 register|TSU_POST1|32|H’E8204870|32|
||CAM entry table POST 2 register|TSU_POST2|32|H’E8204874|32|
||CAM entry table POST 3 register|TSU_POST3|32|H’E8204878|32|
||CAM entry table POST 4 register|TSU_POST4|32|H’E820487C|32|
||CAM entry table 0H register|TSU_ADRH0|32|H'E8204900|32|
||CAM entry table 1H register|TSU_ADRH1|32|H'E8204908|32|
||CAM entry table 2H register|TSU_ADRH2|32|H'E8204910|32|
||CAM entry table 3H register|TSU_ADRH3|32|H'E8204918|32|
||CAM entry table 4H register|TSU_ADRH4|32|H'E8204920|32|
||CAM entry table 5H register|TSU_ADRH5|32|H'E8204928|32|
||CAM entry table 6H register|TSU_ADRH6|32|H'E8204930|32|
||CAM entry table 7H register|TSU_ADRH7|32|H'E8204938|32|
||CAM entry table 8H register|TSU_ADRH8|32|H'E8204940|32|
||CAM entry table 9H register|TSU_ADRH9|32|H'E8204948|32|
||CAM entry table 10H register|TSU_ADRH10|32|H'E8204950|32|
||CAM entry table 11H register|TSU_ADRH11|32|H'E8204958|32|
||CAM entry table 12H register|TSU_ADRH12|32|H'E8204960|32|
||CAM entry table 13H register|TSU_ADRH13|32|H'E8204968|32|
||CAM entry table 14H register|TSU_ADRH14|32|H'E8204970|32|
||CAM entry table 15H register|TSU_ADRH15|32|H'E8204978|32|
||CAM entry table 16H register|TSU_ADRH16|32|H'E8204980|32|
||CAM entry table 17H register|TSU_ADRH17|32|H'E8204988|32|
||CAM entry table 18H register|TSU_ADRH18|32|H'E8204990|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Ethernet controller|CAM entry table 19H register|TSU_ADRH19|32|H'E8204998|32|
||CAM entry table 20H register|TSU_ADRH20|32|H'E82049A0|32|
||CAM entry table 21H register|TSU_ADRH21|32|H'E82049A8|32|
||CAM entry table 22H register|TSU_ADRH22|32|H'E82049B0|32|
||CAM entry table 23H register|TSU_ADRH23|32|H'E82049B8|32|
||CAM entry table 24H register|TSU_ADRH24|32|H'E82049C0|32|
||CAM entry table 25H register|TSU_ADRH25|32|H'E82049C8|32|
||CAM entry table 26H register|TSU_ADRH26|32|H'E82049D0|32|
||CAM entry table 27H register|TSU_ADRH27|32|H'E82049D8|32|
||CAM entry table 28H register|TSU_ADRH28|32|H'E82049E0|32|
||CAM entry table 29H register|TSU_ADRH29|32|H'E82049E8|32|
||CAM entry table 30H register|TSU_ADRH30|32|H'E82049F0|32|
||CAM entry table 31H register|TSU_ADRH31|32|H'E82049F8|32|
||CAM entry table 0L register|TSU_ADRL0|32|H'E8204904|32|
||CAM entry table 1L register|TSU_ADRL1|32|H'E820490C|32|
||CAM entry table 2L register|TSU_ADRL2|32|H'E8204914|32|
||CAM entry table 3L register|TSU_ADRL3|32|H'E820491C|32|
||CAM entry table 4L register|TSU_ADRL4|32|H'E8204924|32|
||CAM entry table 5L register|TSU_ADRL5|32|H'E820492C|32|
||CAM entry table 6L register|TSU_ADRL6|32|H'E8204934|32|
||CAM entry table 7L register|TSU_ADRL7|32|H'E820493C|32|
||CAM entry table 8L register|TSU_ADRL8|32|H'E8204944|32|
||CAM entry table 9L register|TSU_ADRL9|32|H'E820494C|32|
||CAM entry table 10L register|TSU_ADRL10|32|H'E8204954|32|
||CAM entry table 11L register|TSU_ADRL11|32|H'E820495C|32|
||CAM entry table 12L register|TSU_ADRL12|32|H'E8204964|32|
||CAM entry table 13L register|TSU_ADRL13|32|H'E820496C|32|
||CAM entry table 14L register|TSU_ADRL14|32|H'E8204974|32|
||CAM entry table 15L register|TSU_ADRL15|32|H'E820497C|32|
||CAM entry table 16L register|TSU_ADRL16|32|H'E8204984|32|
||CAM entry table 17L register|TSU_ADRL17|32|H'E820498C|32|
||CAM entry table 18L register|TSU_ADRL18|32|H'E8204994|32|
||CAM entry table 19L register|TSU_ADRL19|32|H'E820499C|32|
||CAM entry table 20L register|TSU_ADRL20|32|H'E82049A4|32|
||CAM entry table 21L register|TSU_ADRL21|32|H'E82049AC|32|
||CAM entry table 22L register|TSU_ADRL22|32|H'E82049B4|32|
||CAM entry table 23L register|TSU_ADRL23|32|H'E82049BC|32|
||CAM entry table 24L register|TSU_ADRL24|32|H'E82049C4|32|
||CAM entry table 25L register|TSU_ADRL25|32|H'E82049CC|32|
||CAM entry table 26L register|TSU_ADRL26|32|H'E82049D4|32|
||CAM entry table 27L register|TSU_ADRL27|32|H'E82049DC|32|
||CAM entry table 28L register|TSU_ADRL28|32|H'E82049E4|32|
||CAM entry table 29L register|TSU_ADRL29|32|H'E82049EC|32|
||CAM entry table 30L register|TSU_ADRL30|32|H'E82049F4|32|
||CAM entry table 31L register|TSU_ADRL31|32|H'E82049FC|32|
||Transmit frame counter register|TXNLCR0|32|H'E8204880|32|
||Transmit frame counter register|TXALCR0|32|H'E8204884|32|
||Receive frame counter register|RXNLCR0|32|H'E8204888|32|
||Receive frame counter register|RXALCR0|32|H'E820488C|32|
||E-DMAC start register|EDSR0|32|H'E8203000|32|
||E-DMAC mode register|EDMR0|32|H'E8203400|32|
||E-DMAC transmit request register|EDTRR0|32|H'E8203408|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Ethernet controller|E-DMAC receive request register|EDRRR0|32|H'E8203410|32|
||E-MAC/E-DMAC status register|EESR0|32|H'E8203428|32|
||E-MAC/E-DMAC status interrupt permission register|EESIPR0|32|H'E8203430|32|
||Transmit descriptor list start address register|TDLAR0|32|H'E8203010|32|
||Transmit descriptor fetch address register|TDFAR0|32|H'E8203014|32|
||Transmit descriptor finished address register|TDFXR0|32|H'E8203018|32|
||Transmit descriptor final flag register|TDFFR0|32|H'E820301C|32|
||Receive descriptor list start address register|RDLAR0|32|H'E8203030|32|
||Receive descriptor fetch address register|RDFAR0|32|H'E8203034|32|
||Receive descriptor finished address register|RDFXR0|32|H'E8203038|32|
||Receive descriptor final flag register|RDFFR0|32|H'E820303C|32|
||Transmit/receive status copy enable register|TRSCER0|32|H'E8203438|32|
||Receive missed-frame counter register|RMFCR0|32|H'E8203440|32|
||Transmit FIFO threshold register|TFTR0|32|H'E8203448|32|
||FIFO depth register|FDR0|32|H'E8203450|32|
||Receiving method control register|RMCR0|32|H'E8203458|32|
||Receive data padding insert register|RPADIR0|32|H'E8203460|32|
||Overflow alert FIFO threshold register|FCFTR0|32|H'E8203468|32|
||Intelligent checksum mode register|CSMR|32|H'E82034E4|32|
||Intelligent checksum skipped bytes monitor register|CSSBM|32|H'E82034E8|32|
||Intelligent checksum monitor register|CSSMR|32|H'E82034EC|32|
|A/D converter|A/D data register A|ADDRA|16|H'E8005800|16|
||A/D data register B|ADDRB|16|H'E8005802|16|
||A/D data register C|ADDRC|16|H'E8005804|16|
||A/D data register D|ADDRD|16|H'E8005806|16|
||A/D data register E|ADDRE|16|H'E8005808|16|
||A/D data register F|ADDRF|16|H'E800580A|16|
||A/D data register G|ADDRG|16|H'E800580C|16|
||A/D data register H|ADDRH|16|H'E800580E|16|
||A/D comparison upper limit value register A|ADCMPHA|16|H'E8005820|16|
||A/D comparison lower limit value register A|ADCMPLA|16|H'E8005822|16|
||A/D comparison upper limit value register B|ADCMPHB|16|H'E8005824|16|
||A/D comparison lower limit value register B|ADCMPLB|16|H'E8005826|16|
||A/D comparison upper limit value register C|ADCMPHC|16|H'E8005828|16|
||A/D comparison lower limit value register C|ADCMPLC|16|H'E800582A|16|
||A/D comparison upper limit value register D|ADCMPHD|16|H'E800582C|16|
||A/D comparison lower limit value register D|ADCMPLD|16|H'E800582E|16|
||A/D comparison upper limit value register E|ADCMPHE|16|H'E8005830|16|
||A/D comparison lower limit value register E|ADCMPLE|16|H'E8005832|16|
||A/D comparison upper limit value register F|ADCMPHF|16|H'E8005834|16|
||A/D comparison lower limit value register F|ADCMPLF|16|H'E8005836|16|
||A/D comparison upper limit value register G|ADCMPHG|16|H'E8005838|16|
||A/D comparison lower limit value register G|ADCMPLG|16|H'E800583A|16|
||A/D comparison upper limit value register H|ADCMPHH|16|H'E800583C|16|
||A/D comparison lower limit value register H|ADCMPLH|16|H'E800583E|16|
||A/D control/status register|ADCSR|16|H'E8005860|16|
||A/D comparison interrupt enable register|ADCMPER|16|H'E8005862|16|
||A/D comparison status register|ADCMPSR|16|H'E8005864|16|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|USB2.0 host/function<br>module|System configuration control register_0|SYSCFG0_0|16|H'E8010000|16|
||CPU bus wait setting register_0|BUSWAIT_0|16|H'E8010002|16|
||System configuration status register_0|SYSSTS0_0|16|H'E8010004|16|
||Device state control register 0_0|DVSTCTR0_0|16|H'E8010008|16|
||Test mode register_0|TESTMODE_0|16|H'E801000C|16|
||DMA0-FIFO bus configuration register_0|D0FBCFG_0|16|H'E8010010|16|
||DMA1-FIFO bus configuration register_0|D1FBCFG_0|16|H'E8010012|16|
||CFIFO port register_0|CFIFO_0|32|H'E8010014|8, 16, 32|
||D0FIFO port register_0|D0FIFO_0|32|H'E8010018|8, 16, 32|
||D1FIFO port register_0|D1FIFO_0|32|H'E801001C|8, 16, 32|
||CFIFO port select register_0|CFIFOSEL_0|16|H'E8010020|16|
||CFIFO port control register_0|CFIFOCTR_0|16|H'E8010022|16|
||D0FIFO port select register_0|D0FIFOSEL_0|16|H'E8010028|16|
||D0FIFO port control register_0|D0FIFOCTR_0|16|H'E801002A|16|
||D1FIFO port select register_0|D1FIFOSEL_0|16|H'E801002C|16|
||D1FIFO port control register_0|D1FIFOCTR_0|16|H'E801002E|16|
||Interrupt enable register 0_0|INTENB0_0|16|H'E8010030|16|
||Interrupt enable register 1_0|INTENB1_0|16|H'E8010032|16|
||BRDY interrupt enable register_0|BRDYENB_0|16|H'E8010036|16|
||NRDY interrupt enable register_0|NRDYENB_0|16|H'E8010038|16|
||BEMP interrupt enable register_0|BEMPENB_0|16|H'E801003A|16|
||SOF output configuration register_0|SOFCFG_0|16|H'E801003C|16|
||Interrupt status register 0_0|INTSTS0_0|16|H'E8010040|16|
||Interrupt status register 1_0|INTSTS1_0|16|H'E8010042|16|
||BRDY interrupt status register_0|BRDYSTS_0|16|H'E8010046|16|
||NRDY interrupt status register_0|NRDYSTS_0|16|H'E8010048|16|
||BEMP interrupt status register_0|BEMPSTS_0|16|H'E801004A|16|
||Frame number register_0|FRMNUM_0|16|H'E801004C|16|
||Frame number register_0|UFRMNUM_0|16|H'E801004E|16|
||USB address register_0|USBADDR_0|16|H'E8010050|16|
||USB request type register_0|USBREQ_0|16|H'E8010054|16|
||USB request value register_0|USBVAL_0|16|H'E8010056|16|
||USB request index register_0|USBINDX_0|16|H'E8010058|16|
||USB request length register_0|USBLENG_0|16|H'E801005A|16|
||DCP configuration register_0|DCPCFG_0|16|H'E801005C|16|
||DCP maximum packet size register_0|DCPMAXP_0|16|H'E801005E|16|
||DCP control register_0|DCPCTR_0|16|H'E8010060|16|
||Pipe window select register_0|PIPESEL_0|16|H'E8010064|16|
||Pipe configuration register_0|PIPECFG_0|16|H'E8010068|16|
||Pipe buffer setting register_0|PIPEBUF_0|16|H'E801006A|16|
||Pipe maximum packet size register_0|PIPEMAXP_0|16|H'E801006C|16|
||Pipe timing control register_0|PIPEPERI_0|16|H'E801006E|16|
||Pipe 1 control register_0|PIPE1CTR_0|16|H'E8010070|16|
||Pipe 2 control register_0|PIPE2CTR_0|16|H'E8010072|16|
||Pipe 3 control register_0|PIPE3CTR_0|16|H'E8010074|16|
||Pipe 4 control register_0|PIPE4CTR_0|16|H'E8010076|16|
||Pipe 5 control register_0|PIPE5CTR_0|16|H'E8010078|16|
||Pipe 6 control register_0|PIPE6CTR_0|16|H'E801007A|16|
||Pipe 7 control register_0|PIPE7CTR_0|16|H'E801007C|16|
||Pipe 8 control register_0|PIPE8CTR_0|16|H'E801007E|16|
||Pipe 9 control register_0|PIPE9CTR_0|16|H'E8010080|16|
||Pipe A control register_0|PIPEACTR_0|16|H'E8010082|16|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|USB2.0 host/function<br>module|Pipe B control register_0|PIPEBCTR_0|16|H'E8010084|16|
||Pipe C control register_0|PIPECCTR_0|16|H'E8010086|16|
||Pipe D control register_0|PIPEDCTR_0|16|H'E8010088|16|
||Pipe E control register_0|PIPEECTR_0|16|H'E801008A|16|
||Pipe F control register_0|PIPEFCTR_0|16|H'E801008C|16|
||Pipe 1 transaction counter enable register_0|PIPE1TRE_0|16|H'E8010090|16|
||Pipe 1 transaction counter register_0|PIPE1TRN_0|16|H'E8010092|16|
||Pipe 2 transaction counter enable register_0|PIPE2TRE_0|16|H'E8010094|16|
||Pipe 2 transaction counter register_0|PIPE2TRN_0|16|H'E8010096|16|
||Pipe 3 transaction counter enable register_0|PIPE3TRE_0|16|H'E8010098|16|
||Pipe 3 transaction counter register_0|PIPE3TRN_0|16|H'E801009A|16|
||Pipe 4 transaction counter enable register_0|PIPE4TRE_0|16|H'E801009C|16|
||Pipe 4 transaction counter register_0|PIPE4TRN_0|16|H'E801009E|16|
||Pipe 5 transaction counter enable register_0|PIPE5TRE_0|16|H'E80100A0|16|
||Pipe 5 transaction counter register_0|PIPE5TRN_0|16|H'E80100A2|16|
||Pipe B transaction counter enable register_0|PIPEBTRE_0|16|H'E80100A4|16|
||Pipe B transaction counter register_0|PIPEBTRN_0|16|H'E80100A6|16|
||Pipe C transaction counter enable register_0|PIPECTRE_0|16|H'E80100A8|16|
||Pipe C transaction counter register_0|PIPECTRN_0|16|H'E80100AA|16|
||Pipe D transaction counter enable register_0|PIPEDTRE_0|16|H'E80100AC|16|
||Pipe D transaction counter register_0|PIPEDTRN_0|16|H'E80100AE|16|
||Pipe E transaction counter enable register_0|PIPEETRE_0|16|H'E80100B0|16|
||Pipe E transaction counter register_0|PIPEETRN_0|16|H'E80100B2|16|
||Pipe F transaction counter enable register_0|PIPEFTRE_0|16|H'E80100B4|16|
||Pipe F transaction counter register_0|PIPEFTRN_0|16|H'E80100B6|16|
||Pipe 9 transaction counter enable register_0|PIPE9TRE_0|16|H'E80100B8|16|
||Pipe 9 transaction counter register_0|PIPE9TRN_0|16|H'E80100BA|16|
||Pipe A transaction counter enable register_0|PIPEATRE_0|16|H'E80100BC|16|
||Pipe A transaction counter register_0|PIPEATRN_0|16|H'E80100BE|16|
||Device address 0 configuration register_0|DEVADD0_0|16|H'E80100D0|16|
||Device address 1 configuration register_0|DEVADD1_0|16|H'E80100D2|16|
||Device address 2 configuration register_0|DEVADD2_0|16|H'E80100D4|16|
||Device address 3 configuration register_0|DEVADD3_0|16|H'E80100D6|16|
||Device address 4 configuration register_0|DEVADD4_0|16|H'E80100D8|16|
||Device address 5 configuration register_0|DEVADD5_0|16|H'E80100DA|16|
||Device address 6 configuration register_0|DEVADD6_0|16|H'E80100DC|16|
||Device address 7 configuration register_0|DEVADD7_0|16|H'E80100DE|16|
||Device address 8 configuration register_0|DEVADD8_0|16|H'E80100E0|16|
||Device address 9 configuration register_0|DEVADD9_0|16|H'E80100E2|16|
||Device address A configuration register_0|DEVADDA_0|16|H'E80100E4|16|
||Suspend mode register_0|SUSPMODE_0|16|H'E8010102|16|
||D0FIFO continuous transfer port register 0_0|D0FIFOB0_0|32|H'E8010160|32|
||D0FIFO continuous transfer port register 1_0|D0FIFOB1_0|32|H'E8010164|32|
||D0FIFO continuous transfer port register 2_0|D0FIFOB2_0|32|H'E8010168|32|
||D0FIFO continuous transfer port register 3_0|D0FIFOB3_0|32|H'E801016C|32|
||D0FIFO continuous transfer port register 4_0|D0FIFOB4_0|32|H'E8010170|32|
||D0FIFO continuous transfer port register 5_0|D0FIFOB5_0|32|H'E8010174|32|
||D0FIFO continuous transfer port register 6_0|D0FIFOB6_0|32|H'E8010178|32|
||D0FIFO continuous transfer port register 7_0|D0FIFOB7_0|32|H'E801017C|32|
||D1FIFO continuous transfer port register 0_0|D1FIFOB0_0|32|H'E8010180|32|
||D1FIFO continuous transfer port register 1_0|D1FIFOB1_0|32|H'E8010184|32|
||D1FIFO continuous transfer port register 2_0|D1FIFOB2_0|32|H'E8010188|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|USB2.0 host/function<br>module|D1FIFO continuous transfer port register 3_0|D1FIFOB3_0|32|H'E801018C|32|
||D1FIFO continuous transfer port register 4_0|D1FIFOB4_0|32|H'E8010190|32|
||D1FIFO continuous transfer port register 5_0|D1FIFOB5_0|32|H'E8010194|32|
||D1FIFO continuous transfer port register 6_0|D1FIFOB6_0|32|H'E8010198|32|
||D1FIFO continuous transfer port register 7_0|D1FIFOB7_0|32|H'E801019C|32|
||System configuration control register_1|SYSCFG0_1|16|H'E8207000|16|
||CPU bus wait setting register_1|BUSWAIT_1|16|H'E8207002|16|
||System configuration status register_1|SYSSTS0_1|16|H'E8207004|16|
||Device state control register 0_1|DVSTCTR0_1|16|H'E8207008|16|
||Test mode register_1|TESTMODE_1|16|H'E820700C|16|
||DMA0-FIFO bus configuration register_1|D0FBCFG_1|16|H'E8207010|16|
||DMA1-FIFO bus configuration register_1|D1FBCFG_1|16|H'E8207012|16|
||CFIFO port register_1|CFIFO_1|32|H'E8207014|8, 16, 32|
||D0FIFO port register_1|D0FIFO_1|32|H'E8207018|8, 16, 32|
||D1FIFO port register_1|D1FIFO_1|32|H'E820701C|8, 16, 32|
||CFIFO port select register_1|CFIFOSEL_1|16|H'E8207020|16|
||CFIFO port control register_1|CFIFOCTR_1|16|H'E8207022|16|
||D0FIFO port select register_1|D0FIFOSEL_1|16|H'E8207028|16|
||D0FIFO port control register_1|D0FIFOCTR_1|16|H'E820702A|16|
||D1FIFO port select register_1|D1FIFOSEL_1|16|H'E820702C|16|
||D1FIFO port control register_1|D1FIFOCTR_1|16|H'E820702E|16|
||Interrupt enable register 0_1|INTENB0_1|16|H'E8207030|16|
||Interrupt enable register 1_1|INTENB1_1|16|H'E8207032|16|
||BRDY interrupt enable register_1|BRDYENB_1|16|H'E8207036|16|
||NRDY interrupt enable register_1|NRDYENB_1|16|H'E8207038|16|
||BEMP interrupt enable register_1|BEMPENB_1|16|H'E820703A|16|
||SOF output configuration register_1|SOFCFG_1|16|H'E820703C|16|
||Interrupt status register 0_1|INTSTS0_1|16|H'E8207040|16|
||Interrupt status register 1_1|INTSTS1_1|16|H'E8207042|16|
||BRDY interrupt status register_1|BRDYSTS_1|16|H'E8207046|16|
||NRDY interrupt status register_1|NRDYSTS_1|16|H'E8207048|16|
||BEMP interrupt status register_1|BEMPSTS_1|16|H'E820704A|16|
||Frame number register_1|FRMNUM_1|16|H'E820704C|16|
||Frame number register_1|UFRMNUM_1|16|H'E820704E|16|
||USB address register_1|USBADDR_1|16|H'E8207050|16|
||USB request type register_1|USBREQ_1|16|H'E8207054|16|
||USB request value register_1|USBVAL_1|16|H'E8207056|16|
||USB request index register_1|USBINDX_1|16|H'E8207058|16|
||USB request length register_1|USBLENG_1|16|H'E820705A|16|
||DCP configuration register_1|DCPCFG_1|16|H'E820705C|16|
||DCP maximum packet size register_1|DCPMAXP_1|16|H'E820705E|16|
||DCP control register_1|DCPCTR_1|16|H'E8207060|16|
||Pipe window select register_1|PIPESEL_1|16|H'E8207064|16|
||Pipe configuration register_1|PIPECFG_1|16|H'E8207068|16|
||Pipe buffer setting register_1|PIPEBUF_1|16|H'E820706A|16|
||Pipe maximum packet size register_1|PIPEMAXP_1|16|H'E820706C|16|
||Pipe timing control register_1|PIPEPERI_1|16|H'E820706E|16|
||Pipe 1 control register_1|PIPE1CTR_1|16|H'E8207070|16|
||Pipe 2 control register_1|PIPE2CTR_1|16|H'E8207072|16|
||Pipe 3 control register_1|PIPE3CTR_1|16|H'E8207074|16|
||Pipe 4 control register_1|PIPE4CTR_1|16|H'E8207076|16|
||Pipe 5 control register_1|PIPE5CTR_1|16|H'E8207078|16|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|USB2.0 host/function<br>module|Pipe 6 control register_1|PIPE6CTR_1|16|H'E820707A|16|
||Pipe 7 control register_1|PIPE7CTR_1|16|H'E820707C|16|
||Pipe 8 control register_1|PIPE8CTR_1|16|H'E820707E|16|
||Pipe 9 control register_1|PIPE9CTR_1|16|H'E8207080|16|
||Pipe  A  control register_1|PIPEACTR_1|16|H'E8207082|16|
||Pipe  B  control register_1|PIPEBCTR_1|16|H'E8207084|16|
||Pipe  C  control register_1|PIPECCTR_1|16|H'E8207086|16|
||Pipe  D  control register_1|PIPEDCTR_1|16|H'E8207088|16|
||Pipe  E  control register_1|PIPEECTR_1|16|H'E820708A|16|
||Pipe  F  control register_1|PIPEFCTR_1|16|H'E820708C|16|
||Pipe 1 transaction counter enable register_1|PIPE1TRE_1|16|H'E8207090|16|
||Pipe 1 transaction counter register_1|PIPE1TRN_1|16|H'E8207092|16|
||Pipe 2 transaction counter enable register_1|PIPE2TRE_1|16|H'E8207094|16|
||Pipe 2 transaction counter register_1|PIPE2TRN_1|16|H'E8207096|16|
||Pipe 3 transaction counter enable register_1|PIPE3TRE_1|16|H'E8207098|16|
||Pipe 3 transaction counter register_1|PIPE3TRN_1|16|H'E820709A|16|
||Pipe 4 transaction counter enable register_1|PIPE4TRE_1|16|H'E820709C|16|
||Pipe 4 transaction counter register_1|PIPE4TRN_1|16|H'E820709E|16|
||Pipe 5 transaction counter enable register_1|PIPE5TRE_1|16|H'E82070A0|16|
||Pipe 5 transaction counter register_1|PIPE5TRN_1|16|H'E82070A2|16|
||Pipe B transaction counter enable register_1|PIPEBTRE_1|16|H'E82070A4|16|
||Pipe B transaction counter register_1|PIPEBTRN_1|16|H'E82070A6|16|
||Pipe C transaction counter enable register_1|PIPECTRE_1|16|H'E82070A8|16|
||Pipe C transaction counter register_1|PIPECTRN_1|16|H'E82070AA|16|
||Pipe D transaction counter enable register_1|PIPEDTRE_1|16|H'E82070AC|16|
||Pipe D transaction counter register_1|PIPEDTRN_1|16|H'E82070AE|16|
||Pipe E transaction counter enable register_1|PIPEETRE_1|16|H'E82070B0|16|
||Pipe E transaction counter register_1|PIPEETRN_1|16|H'E82070B2|16|
||Pipe F transaction counter enable register_1|PIPEFTRE_1|16|H'E82070B4|16|
||Pipe F transaction counter register_1|PIPEFTRN_1|16|H'E82070B6|16|
||Pipe 9 transaction counter enable register_1|PIPE9TRE_1|16|H'E82070B8|16|
||Pipe 9 transaction counter register_1|PIPE9TRN_1|16|H'E82070BA|16|
||Pipe A transaction counter enable register_1|PIPEATRE_1|16|H'E82070BC|16|
||Pipe A transaction counter register_1|PIPEATRN_1|16|H'E82070BE|16|
||Device address 0 configuration register_1|DEVADD0_1|16|H'E82070D0|16|
||Device address 1 configuration register_1|DEVADD1_1|16|H'E82070D2|16|
||Device address 2 configuration register_1|DEVADD2_1|16|H'E82070D4|16|
||Device address 3 configuration register_1|DEVADD3_1|16|H'E82070D6|16|
||Device address 4 configuration register_1|DEVADD4_1|16|H'E82070D8|16|
||Device address 5 configuration register_1|DEVADD5_1|16|H'E82070DA|16|
||Device address 6 configuration register_1|DEVADD6_1|16|H'E82070DC|16|
||Device address 7 configuration register_1|DEVADD7_1|16|H'E82070DE|16|
||Device address 8 configuration register_1|DEVADD8_1|16|H'E82070E0|16|
||Device address 9 configuration register_1|DEVADD9_1|16|H'E82070E2|16|
||Device address A configuration register_1|DEVADDA_1|16|H'E82070E4|16|
||Suspend mode register_1|SUSPMODE_1|16|H'E8207102|16|
||D0FIFO continuous transfer port register 0_1|D0FIFOB0_1|32|H'E8207160|32|
||D0FIFO continuous transfer port register 1_1|D0FIFOB1_1|32|H'E8207164|32|
||D0FIFO continuous transfer port register 2_1|D0FIFOB2_1|32|H'E8207168|32|
||D0FIFO continuous transfer port register 3_1|D0FIFOB3_1|32|H'E820716C|32|
||D0FIFO continuous transfer port register 4_1|D0FIFOB4_1|32|H'E8207170|32|
||D0FIFO continuous transfer port register 5_1|D0FIFOB5_1|32|H'E8207174|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|USB2.0 host/function<br>module|D0FIFO continuous transfer port register 6_1|D0FIFOB6_1|32|H'E8207178|32|
||D0FIFO continuous transfer port register 7_1|D0FIFOB7_1|32|H'E820717C|32|
||D1FIFO continuous transfer port register 0_1|D1FIFOB0_1|32|H'E8207180|32|
||D1FIFO continuous transfer port register 1_1|D1FIFOB1_1|32|H'E8207184|32|
||D1FIFO continuous transfer port register 2_1|D1FIFOB2_1|32|H'E8207188|32|
||D1FIFO continuous transfer port register 3_1|D1FIFOB3_1|32|H'E820718C|32|
||D1FIFO continuous transfer port register 4_1|D1FIFOB4_1|32|H'E8207190|32|
||D1FIFO continuous transfer port register 5_1|D1FIFOB5_1|32|H'E8207194|32|
||D1FIFO continuous transfer port register 6_1|D1FIFOB6_1|32|H'E8207198|32|
||D1FIFO continuous transfer port register 7_1|D1FIFOB7_1|32|H'E820719C|32|
|Video display controller 5|External input block register update control register|INP_UPDATE|32|H'FCFF7400|32|
||Input select control register|INP_SEL_CNT|32|H'FCFF7404|32|
||External input sync signal control register|INP_EXT_SYNC_CNT|32|H'FCFF7408|32|
||Vsync signal phase adjustment register|INP_VSYNC_PH_ADJ|32|H'FCFF740C|32|
||Sync signal phase adjustment register|INP_DLY_ADJ|32|H'FCFF7410|32|
||Image quality adjustment block register update control register|IMGCNT_UPDATE|32|H'FCFF7480|32|
||NR control register 0|IMGCNT_NR_CNT0|32|H'FCFF7484|32|
||NR control register 1|IMGCNT_NR_CNT1|32|H'FCFF7488|32|
||Image quality adjustment block matrix mode register|IMGCNT_MTX_MODE|32|H'FCFF74A0|32|
||Image quality adjustment block matrix YG adjustment register 0|IMGCNT_MTX_YG_ADJ0|32|H'FCFF74A4|32|
||Image quality adjustment block matrix YG adjustment register 1|IMGCNT_MTX_YG_ADJ1|32|H'FCFF74A8|32|
||Image quality adjustment block matrix CBB adjustment register 0|IMGCNT_MTX_CBB_ADJ0|32|H'FCFF74AC|32|
||Image quality adjustment block matrix CBB adjustment register 1|IMGCNT_MTX_CBB_ADJ1|32|H'FCFF74B0|32|
||Image quality adjustment block matrix CRR adjustment register 0|IMGCNT_MTX_CRR_ADJ0|32|H'FCFF74B4|32|
||Image quality adjustment block matrix CRR adjustment register 1|IMGCNT_MTX_CRR_ADJ1|32|H'FCFF74B8|32|
||SCL0 register update control register (SC0)|SC0_SCL0_UPDATE|32|H'FCFF7500|32|
||Mask control register (SC0)|SC0_SCL0_FRC1|32|H'FCFF7504|32|
||Missing Vsync compensation control register (SC0)|SC0_SCL0_FRC2|32|H'FCFF7508|32|
||Output sync select register (SC0)|SC0_SCL0_FRC3|32|H'FCFF750C|32|
||Free-running period control register (SC0)|SC0_SCL0_FRC4|32|H'FCFF7510|32|
||Output delay control register (SC0)|SC0_SCL0_FRC5|32|H'FCFF7514|32|
||Full-screen vertical size register (SC0)|SC0_SCL0_FRC6|32|H'FCFF7518|32|
||Full-screen horizontal size register (SC0)|SC0_SCL0_FRC7|32|H'FCFF751C|32|
||Vsync detection register (SC0)|SC0_SCL0_FRC9|32|H'FCFF7524|32|
||Status monitor 0 register (SC0)|SC0_SCL0_MON0|16|H'FCFF7528|16|
||Interrupt control register (SC0)|SC0_SCL0_INT|16|H'FCFF752A|16|
||Scaling-down control register (SC0)|SC0_SCL0_DS1|32|H'FCFF752C|32|
||Vertical capture size register (SC0)|SC0_SCL0_DS2|32|H'FCFF7530|32|
||Horizontal capture size register (SC0)|SC0_SCL0_DS3|32|H'FCFF7534|32|
||Horizontal scale down register (SC0)|SC0_SCL0_DS4|32|H'FCFF7538|32|
||Initial vertical phase register (SC0)|SC0_SCL0_DS5|32|H'FCFF753C|32|
||Vertical scaling register (SC0)|SC0_SCL0_DS6|32|H'FCFF7540|32|
||Scaling-down control block output size register (SC0)|SC0_SCL0_DS7|32|H'FCFF7544|32|
||Scaling-up control register (SC0)|SC0_SCL0_US1|32|H'FCFF7548|32|
||Output image vertical size register (SC0)|SC0_SCL0_US2|32|H'FCFF754C|32|
||Output image horizontal size register (SC0)|SC0_SCL0_US3|32|H'FCFF7550|32|
||Scaling-up control block input size register (SC0)|SC0_SCL0_US4|32|H'FCFF7554|32|
||Horizontal scale up register (SC0)|SC0_SCL0_US5|32|H'FCFF7558|32|
||Horizontal scale up initial phase register (SC0)|SC0_SCL0_US6|32|H'FCFF755C|32|
||Trimming register (SC0)|SC0_SCL0_US7|32|H'FCFF7560|32|
||Frame buffer read select register (SC0)|SC0_SCL0_US8|32|H'FCFF7564|32|
||Background color register (SC0)|SC0_SCL0_OVR1|32|H'FCFF756C|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Video display controller 5|SCL1 register update control register (SC0)|SC0_SCL1_UPDATE|32|H'FCFF7580|32|
||Writing mode register (SC0)|SC0_SCL1_WR1|32|H'FCFF7588|32|
||Write address register 1T (SC0)|SC0_SCL1_WR2|32|H'FCFF758C|32|
||Write address register 2T (SC0)|SC0_SCL1_WR3|32|H'FCFF7590|32|
||Write address register 3T (SC0)|SC0_SCL1_WR4|32|H'FCFF7594|32|
||Frame sub-sampling register (SC0)|SC0_SCL1_WR5|32|H'FCFF759C|32|
||Bit reduction register (SC0)|SC0_SCL1_WR6|32|H'FCFF75A0|32|
||Write detection register (SC0)|SC0_SCL1_WR7|32|H'FCFF75A4|32|
||Write address register 1B (SC0)|SC0_SCL1_WR8|32|H'FCFF75A8|32|
||Write address register 2B (SC0)|SC0_SCL1_WR9|32|H'FCFF75AC|32|
||Write address register 3B (SC0)|SC0_SCL1_WR10|32|H'FCFF75B0|32|
||Write detection register B (SC0)|SC0_SCL1_WR11|32|H'FCFF75B4|32|
||Status monitor 1 register (SC0)|SC0_SCL1_MON1|32|H'FCFF75B8|32|
||Pointer buffer 0 register (SC0)|SC0_SCL1_PBUF0|32|H'FCFF75BC|32|
||Pointer buffer 1 register (SC0)|SC0_SCL1_PBUF1|32|H'FCFF75C0|32|
||Pointer buffer 2 register (SC0)|SC0_SCL1_PBUF2|32|H'FCFF75C4|32|
||Pointer buffer 3 register (SC0)|SC0_SCL1_PBUF3|32|H'FCFF75C8|32|
||Pointer buffer and field information register (SC0)|SC0_SCL1_PBUF_FLD|32|H'FCFF75CC|32|
||Pointer buffer control register (SC0)|SC0_SCL1_PBUF_CNT|32|H'FCFF75D0|32|
||Graphics 0 register update control register|GR0_UPDATE|32|H'FCFF7600|32|
||Frame buffer read control register (graphics 0)|GR0_FLM_RD|32|H'FCFF7604|32|
||Frame buffer control register 1 (graphics 0)|GR0_FLM1|32|H'FCFF7608|32|
||Frame buffer control register 2 (graphics 0)|GR0_FLM2|32|H'FCFF760C|32|
||Frame buffer control register 3 (graphics 0)|GR0_FLM3|32|H'FCFF7610|32|
||Frame buffer control register 4 (graphics 0)|GR0_FLM4|32|H'FCFF7614|32|
||Frame buffer control register 5 (graphics 0)|GR0_FLM5|32|H'FCFF7618|32|
||Frame buffer control register 6 (graphics 0)|GR0_FLM6|32|H'FCFF761C|32|
||Alpha blending control register 1 (graphics 0)|GR0_AB1|32|H'FCFF7620|32|
||Alpha blending control register 2 (graphics 0)|GR0_AB2|32|H'FCFF7624|32|
||Alpha blending control register 3 (graphics 0)|GR0_AB3|32|H'FCFF7628|32|
||Alpha blending control register 7 (graphics 0)|GR0_AB7|32|H'FCFF7638|32|
||Alpha blending control register 8 (graphics 0)|GR0_AB8|32|H'FCFF763C|32|
||Alpha blending control register 9 (graphics 0)|GR0_AB9|32|H'FCFF7640|32|
||Alpha blending control register 10 (graphics 0)|GR0_AB10|32|H'FCFF7644|32|
||Alpha blending control register 11 (graphics 0)|GR0_AB11|32|H'FCFF7648|32|
||Background color control register (graphics 0)|GR0_BASE|32|H'FCFF764C|32|
||CLUT table control register (graphics 0)|GR0_CLUT|32|H'FCFF7650|32|
||Register update control register in image quality improver<br>(image quality improver 0)|ADJ0_UPDATE|32|H'FCFF7680|32|
||Black stretch register (image quality improver 0)|ADJ0_BKSTR_SET|32|H'FCFF7684|32|
||Enhancer timing adjustment register 1 (image quality improver 0)|ADJ0_ENH_TIM1|32|H'FCFF7688|32|
||Enhancer timing adjustment register 2 (image quality improver 0)|ADJ0_ENH_TIM2|32|H'FCFF768C|32|
||Enhancer timing adjustment register 3 (image quality improver 0)|ADJ0_ENH_TIM3|32|H'FCFF7690|32|
||Enhancer sharpness register 1 (image quality improver 0)|ADJ0_ENH_SHP1|32|H'FCFF7694|32|
||Enhancer sharpness register 2 (image quality improver 0)|ADJ0_ENH_SHP2|32|H'FCFF7698|32|
||Enhancer sharpness register 3 (image quality improver 0)|ADJ0_ENH_SHP3|32|H'FCFF769C|32|
||Enhancer sharpness register 4 (image quality improver 0)|ADJ0_ENH_SHP4|32|H'FCFF76A0|32|
||Enhancer sharpness register 5 (image quality improver 0)|ADJ0_ENH_SHP5|32|H'FCFF76A4|32|
||Enhancer sharpness register 6 (image quality improver 0)|ADJ0_ENH_SHP6|32|H'FCFF76A8|32|
||Enhancer LTI register 1 (image quality improver 0)|ADJ0_ENH_LTI1|32|H'FCFF76AC|32|
||Enhancer LTI register 2 (image quality improver 0)|ADJ0_ENH_LTI2|32|H'FCFF76B0|32|
||Matrix mode register in image quality improver (image quality improver 0)|ADJ0_MTX_MODE|32|H'FCFF76B4|32|
||Matrix YG control register 0 in image quality improver (image quality improver 0)|ADJ0_MTX_YG_ADJ0|32|H'FCFF76B8|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Video display controller 5|Matrix YG control register 1 in image quality improver (image quality improver 0)|ADJ0_MTX_YG_ADJ1|32|H'FCFF76BC|32|
||Matrix CBB control register 0 in image quality improver (image quality improver 0)|ADJ0_MTX_CBB_ADJ0|32|H'FCFF76C0|32|
||Matrix CBB control register 1 in image quality improver (image quality improver 0)|ADJ0_MTX_CBB_ADJ1|32|H'FCFF76C4|32|
||Matrix CRR control register 0 in image quality improver (image quality improver 0)|ADJ0_MTX_CRR_ADJ0|32|H'FCFF76C8|32|
||Matrix CRR control register 1 in image quality improver (image quality improver 0)|ADJ0_MTX_CRR_ADJ1|32|H'FCFF76CC|32|
||Graphics 2 register update control register|GR2_UPDATE|32|H'FCFF7700|32|
||Frame buffer read control register (Graphics 2)|GR2_FLM_RD|32|H'FCFF7704|32|
||Frame buffer control register 1 (Graphics 2)|GR2_FLM1|32|H'FCFF7708|32|
||Frame buffer control register 2 (Graphics 2)|GR2_FLM2|32|H'FCFF770C|32|
||Frame buffer control register 3 (Graphics 2)|GR2_FLM3|32|H'FCFF7710|32|
||Frame buffer control register 4 (Graphics 2)|GR2_FLM4|32|H'FCFF7714|32|
||Frame buffer control register 5 (Graphics 2)|GR2_FLM5|32|H'FCFF7718|32|
||Frame buffer control register 6 (Graphics 2)|GR2_FLM6|32|H'FCFF771C|32|
||Alpha blending control register 1 (Graphics 2)|GR2_AB1|32|H'FCFF7720|32|
||Alpha blending control register 2 (Graphics 2)|GR2_AB2|32|H'FCFF7724|32|
||Alpha blending control register 3 (Graphics 2)|GR2_AB3|32|H'FCFF7728|32|
||Alpha blending control register 4 (Graphics 2)|GR2_AB4|32|H'FCFF772C|32|
||Alpha blending control register 5 (Graphics 2)|GR2_AB5|32|H'FCFF7730|32|
||Alpha blending control register 6 (Graphics 2)|GR2_AB6|32|H'FCFF7734|32|
||Alpha blending control register 7 (Graphics 2)|GR2_AB7|32|H'FCFF7738|32|
||Alpha blending control register 8 (Graphics 2)|GR2_AB8|32|H'FCFF773C|32|
||Alpha blending control register 9 (Graphics 2)|GR2_AB9|32|H'FCFF7740|32|
||Alpha blending control register 10 (Graphics 2)|GR2_AB10|32|H'FCFF7744|32|
||Alpha blending control register 11 (Graphics 2)|GR2_AB11|32|H'FCFF7748|32|
||Background color control register (Graphics 2)|GR2_BASE|32|H'FCFF774C|32|
||CLUT table control register (Graphics 2)|GR2_CLUT|32|H'FCFF7750|32|
||Status monitor register (Graphics 2)|GR2_MON|32|H'FCFF7754|32|
||Graphics 3 register update control register|GR3_UPDATE|32|H'FCFF7780|32|
||Frame buffer read control register (Graphics 3)|GR3_FLM_RD|32|H'FCFF7784|32|
||Frame buffer control register 1 (Graphics 3)|GR3_FLM1|32|H'FCFF7788|32|
||Frame buffer control register 2 (Graphics 3)|GR3_FLM2|32|H'FCFF778C|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Video display controller 5|Frame buffer control register 3 (Graphics 3)|GR3_FLM3|32|H'FCFF7790|32|
||Frame buffer control register 4 (Graphics 3)|GR3_FLM4|32|H'FCFF7794|32|
||Frame buffer control register 5 (Graphics 3)|GR3_FLM5|32|H'FCFF7798|32|
||Frame buffer control register 6 (Graphics 3)|GR3_FLM6|32|H'FCFF779C|32|
||Alpha blending control register 1 (Graphics 3)|GR3_AB1|32|H'FCFF77A0|32|
||Alpha blending control register 2 (Graphics 3)|GR3_AB2|32|H'FCFF77A4|32|
||Alpha blending control register 3 (Graphics 3)|GR3_AB3|32|H'FCFF77A8|32|
||Alpha blending control register 4 (Graphics 3)|GR3_AB4|32|H'FCFF77AC|32|
||Alpha blending control register 5 (Graphics 3)|GR3_AB5|32|H'FCFF77B0|32|
||Alpha blending control register 6 (Graphics 3)|GR3_AB6|32|H'FCFF77B4|32|
||Alpha blending control register 7 (Graphics 3)|GR3_AB7|32|H'FCFF77B8|32|
||Alpha blending control register 8 (Graphics 3)|GR3_AB8|32|H'FCFF77BC|32|
||Alpha blending control register 9 (Graphics 3)|GR3_AB9|32|H'FCFF77C0|32|
||Alpha blending control register 10 (Graphics 3)|GR3_AB10|32|H'FCFF77C4|32|
||Alpha blending control register 11 (Graphics 3)|GR3_AB11|32|H'FCFF77C8|32|
||Background color control register (Graphics 3)|GR3_BASE|32|H'FCFF77CC|32|
||CLUT table and interrupt control register (Graphics 3)|GR3_CLUT_INT|32|H'FCFF77D0|32|
||Status monitor register (Graphics 3)|GR3_MON|32|H'FCFF77D4|32|
||VIN synthesizer register update control register|GR_VIN_UPDATE|32|H'FCFF7E00|32|
||Alpha blending control register 1 (VIN synthesizer)|GR_VIN_AB1|32|H'FCFF7E20|32|
||Register update control register G in gamma correction block|GAM_G_UPDATE|32|H'FCFF7800|32|
||Function switch register in gamma correction block|GAM_SW|32|H'FCFF7804|32|
||Table setting register G1 in gamma correction block|GAM_G_LUT1|32|H'FCFF7808|32|
||Table setting register G2 in gamma correction block|GAM_G_LUT2|32|H'FCFF780C|32|
||Table setting register G3 in gamma correction block|GAM_G_LUT3|32|H'FCFF7810|32|
||Table setting register G4 in gamma correction block|GAM_G_LUT4|32|H'FCFF7814|32|
||Table setting register G5 in gamma correction block|GAM_G_LUT5|32|H'FCFF7818|32|
||Table setting register G6 in gamma correction block|GAM_G_LUT6|32|H'FCFF781C|32|
||Table setting register G7 in gamma correction block|GAM_G_LUT7|32|H'FCFF7820|32|
||Table setting register G8 in gamma correction block|GAM_G_LUT8|32|H'FCFF7824|32|
||Table setting register G9 in gamma correction block|GAM_G_LUT9|32|H'FCFF7828|32|
||Table setting register G10 in gamma correction block|GAM_G_LUT10|32|H'FCFF782C|32|
||Table setting register G11 in gamma correction block|GAM_G_LUT11|32|H'FCFF7830|32|
||Table setting register G12 in gamma correction block|GAM_G_LUT12|32|H'FCFF7834|32|
||Table setting register G13 in gamma correction block|GAM_G_LUT13|32|H'FCFF7838|32|
||Table setting register G14 in gamma correction block|GAM_G_LUT14|32|H'FCFF783C|32|
||Table setting register G15 in gamma correction block|GAM_G_LUT15|32|H'FCFF7840|32|
||Table setting register G16 in gamma correction block|GAM_G_LUT16|32|H'FCFF7844|32|
||Area setting register G1 in gamma correction block|GAM_G_AREA1|32|H'FCFF7848|32|
||Area setting register G2 in gamma correction block|GAM_G_AREA2|32|H'FCFF784C|32|
||Area setting register G3 in gamma correction block|GAM_G_AREA3|32|H'FCFF7850|32|
||Area setting register G4 in gamma correction block|GAM_G_AREA4|32|H'FCFF7854|32|
||Area setting register G5 in gamma correction block|GAM_G_AREA5|32|H'FCFF7858|32|
||Area setting register G6 in gamma correction block|GAM_G_AREA6|32|H'FCFF785C|32|
||Area setting register G7 in gamma correction block|GAM_G_AREA7|32|H'FCFF7860|32|
||Area setting register G8 in gamma correction block|GAM_G_AREA8|32|H'FCFF7864|32|
||Register update control register B in gamma correction block|GAM_B_UPDATE|32|H'FCFF7880|32|
||Table setting register B1 in gamma correction block|GAM_B_LUT1|32|H'FCFF7888|32|
||Table setting register B2 in gamma correction block|GAM_B_LUT2|32|H'FCFF788C|32|
||Table setting register B3 in gamma correction block|GAM_B_LUT3|32|H'FCFF7890|32|
||Table setting register B4 in gamma correction block|GAM_B_LUT4|32|H'FCFF7894|32|
||Table setting register B5 in gamma correction block|GAM_B_LUT5|32|H'FCFF7898|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Video display controller 5|Table setting register B6 in gamma correction block|GAM_B_LUT6|32|H'FCFF789C|32|
||Table setting register B7 in gamma correction block|GAM_B_LUT7|32|H'FCFF78A0|32|
||Table setting register B8 in gamma correction block|GAM_B_LUT8|32|H'FCFF78A4|32|
||Table setting register B9 in gamma correction block|GAM_B_LUT9|32|H'FCFF78A8|32|
||Table setting register B10 in gamma correction block|GAM_B_LUT10|32|H'FCFF78AC|32|
||Table setting register B11 in gamma correction block|GAM_B_LUT11|32|H'FCFF78B0|32|
||Table setting register B12 in gamma correction block|GAM_B_LUT12|32|H'FCFF78B4|32|
||Table setting register B13 in gamma correction block|GAM_B_LUT13|32|H'FCFF78B8|32|
||Table setting register B14 in gamma correction block|GAM_B_LUT14|32|H'FCFF78BC|32|
||Table setting register B15 in gamma correction block|GAM_B_LUT15|32|H'FCFF78C0|32|
||Table setting register B16 in gamma correction block|GAM_B_LUT16|32|H'FCFF78C4|32|
||Area setting register B1 in gamma correction block|GAM_B_AREA1|32|H'FCFF78C8|32|
||Area setting register B2 in gamma correction block|GAM_B_AREA2|32|H'FCFF78CC|32|
||Area setting register B3 in gamma correction block|GAM_B_AREA3|32|H'FCFF78D0|32|
||Area setting register B4 in gamma correction block|GAM_B_AREA4|32|H'FCFF78D4|32|
||Area setting register B5 in gamma correction block|GAM_B_AREA5|32|H'FCFF78D8|32|
||Area setting register B6 in gamma correction block|GAM_B_AREA6|32|H'FCFF78DC|32|
||Area setting register B7 in gamma correction block|GAM_B_AREA7|32|H'FCFF78E0|32|
||Area setting register B8 in gamma correction block|GAM_B_AREA8|32|H'FCFF78E4|32|
||Register update control register R in gamma correction block|GAM_R_UPDATE|32|H'FCFF7900|32|
||Table setting register R1 in gamma correction block|GAM_R_LUT1|32|H'FCFF7908|32|
||Table setting register R2 in gamma correction block|GAM_R_LUT2|32|H'FCFF790C|32|
||Table setting register R3 in gamma correction block|GAM_R_LUT3|32|H'FCFF7910|32|
||Table setting register R4 in gamma correction block|GAM_R_LUT4|32|H'FCFF7914|32|
||Table setting register R5 in gamma correction block|GAM_R_LUT5|32|H'FCFF7918|32|
||Table setting register R6 in gamma correction block|GAM_R_LUT6|32|H'FCFF791C|32|
||Table setting register R7 in gamma correction block|GAM_R_LUT7|32|H'FCFF7920|32|
||Table setting register R8 in gamma correction block|GAM_R_LUT8|32|H'FCFF7924|32|
||Table setting register R9 in gamma correction block|GAM_R_LUT9|32|H'FCFF7928|32|
||Table setting register R10 in gamma correction block|GAM_R_LUT10|32|H'FCFF792C|32|
||Table setting register R11 in gamma correction block|GAM_R_LUT11|32|H'FCFF7930|32|
||Table setting register R12 in gamma correction block|GAM_R_LUT12|32|H'FCFF7934|32|
||Table setting register R13 in gamma correction block|GAM_R_LUT13|32|H'FCFF7938|32|
||Table setting register R14 in gamma correction block|GAM_R_LUT14|32|H'FCFF793C|32|
||Table setting register R15 in gamma correction block|GAM_R_LUT15|32|H'FCFF7940|32|
||Table setting register R16 in gamma correction block|GAM_R_LUT16|32|H'FCFF7944|32|
||Area setting register R1 in gamma correction block|GAM_R_AREA1|32|H'FCFF7948|32|
||Area setting register R2 in gamma correction block|GAM_R_AREA2|32|H'FCFF794C|32|
||Area setting register R3 in gamma correction block|GAM_R_AREA3|32|H'FCFF7950|32|
||Area setting register R4 in gamma correction block|GAM_R_AREA4|32|H'FCFF7954|32|
||Area setting register R5 in gamma correction block|GAM_R_AREA5|32|H'FCFF7958|32|
||Area setting register R6 in gamma correction block|GAM_R_AREA6|32|H'FCFF795C|32|
||Area setting register R7 in gamma correction block|GAM_R_AREA7|32|H'FCFF7960|32|
||Area setting register R8 in gamma correction block|GAM_R_AREA8|32|H'FCFF7964|32|
||TCON register update control register|TCON_UPDATE|32|H'FCFF7980|32|
||TCON reference timing setting register|TCON_TIM|32|H'FCFF7984|32|
||TCON vertical timing setting register A1|TCON_TIM_STVA1|32|H'FCFF7988|32|
||TCON vertical timing setting register A2|TCON_TIM_STVA2|32|H'FCFF798C|32|
||TCON vertical timing setting register B1|TCON_TIM_STVB1|32|H'FCFF7990|32|
||TCON vertical timing setting register B2|TCON_TIM_STVB2|32|H'FCFF7994|32|
||TCON horizontal timing setting register STH1|TCON_TIM_STH1|32|H'FCFF7998|32|
||TCON horizontal timing setting register STH2|TCON_TIM_STH2|32|H'FCFF799C|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Video display controller 5|TCON horizontal timing setting register STB1|TCON_TIM_STB1|32|H'FCFF79A0|32|
||TCON horizontal timing setting register STB2|TCON_TIM_STB2|32|H'FCFF79A4|32|
||TCON horizontal timing setting register CPV1|TCON_TIM_CPV1|32|H'FCFF79A8|32|
||TCON horizontal timing setting register CPV2|TCON_TIM_CPV2|32|H'FCFF79AC|32|
||TCON horizontal timing setting register POLA1|TCON_TIM_POLA1|32|H'FCFF79B0|32|
||TCON horizontal timing setting register POLA2|TCON_TIM_POLA2|32|H'FCFF79B4|32|
||TCON horizontal timing setting register POLB1|TCON_TIM_POLB1|32|H'FCFF79B8|32|
||TCON horizontal timing setting register POLB2|TCON_TIM_POLB2|32|H'FCFF79BC|32|
||TCON data enable polarity setting register|TCON_TIM_DE|32|H'FCFF79C0|32|
||Register update control register in output controller|OUT_UPDATE|32|H'FCFF7A00|32|
||Output interface register|OUT_SET|32|H'FCFF7A04|32|
||Brightness (DC) correction register 1|OUT_BRIGHT1|32|H'FCFF7A08|32|
||Brightness (DC) correction register 2|OUT_BRIGHT2|32|H'FCFF7A0C|32|
||Contrast (gain) correction register|OUT_CONTRAST|32|H'FCFF7A10|32|
||Panel dither register|OUT_PDTHA|32|H'FCFF7A14|32|
||Output phase control register|OUT_CLK_PHASE|32|H'FCFF7A24|32|
||Interrupt control register 1|SYSCNT_INT1|32|H’FCFF7A80|32|
||Interrupt control register 2|SYSCNT_INT2|32|H’FCFF7A84|32|
||Interrupt control register 4|SYSCNT_INT4|32|H’FCFF7A8C|32|
||Interrupt control register 5|SYSCNT_INT5|32|H’FCFF7A90|32|
||Panel clock control register|SYSCNT_PANEL_CLK|16|H’FCFF7A98|16|
||CLUT table read select signal status register|SYSCNT_CLUT|16|H’FCFF7A9A|16|
|Capture engine unit|CEU Capture start register|CAPSR|32|H'E8210000|32|
||CEU Capture control register|CAPCR|32|H'E8210004|32|
||CEU Capture interface control register|CAMCR|32|H'E8210008|32|
||CEU Capture interface cycle register|CMCYR|32|H'E821000C|32|
||CEU Capture interface offset register|CAMOR|32|Plane A:<br>H'E8210010<br>Plane B:<br>H'E8211010<br>Mirror:<br>H'E8212010|32|
||CEU Capture interface width register|CAPWR|32|Plane A:<br>H'E8210014<br>Plane B:<br>H'E8211014<br>Mirror:<br>H'E8212014|32|
||CEU Capture interface input format register|CAIFR|32|H'E8210018|32|
||CEU register control register|CRCNTR|32|H'E8210028|32|
||CEU register forcible control register|CRCMPR|32|H'E821002C|32|
||CEU Capture filter control register|CFLCR|32|Plane A:<br>H'E8210030<br>Plane B:<br>H'E8211030<br>Mirror:<br>H'E8212030|32|
||CEU Capture filter size clip register|CFSZR|32|Plane A:<br>H'E8210034<br>Plane B:<br>H'E8211034<br>Mirror:<br>H'E8212034|32|
||CEU Capture destination width register|CDWDR|32|Plane A:<br>H'E8210038<br>Plane B:<br>H'E8211038<br>Mirror:<br>H'E8212038|32|
||CEU Capture data address Y register|CDAYR|32|Plane A:<br>H'E821003C<br>Plane B:<br>H'E821103C<br>Mirror:<br>H'E821203C|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Capture engine unit|CEU Capture data address C register|CDACR|32|Plane A:<br>H'E8210040<br>Plane B:<br>H'E8211040<br>Mirror:<br>H'E8212040|32|
||CEU Capture data bottom-field address Y register|CDBYR|32|Plane A:<br>H'E8210044<br>Plane B:<br>H'E8211044<br>Mirror:<br>H'E8212044|32|
||CEU Capture data bottom-field address C register|CDBCR|32|Plane A:<br>H'E8210048<br>Plane B:<br>H'E8211048<br>Mirror:<br>H'E8212048|32|
||CEU Capture bundle destination size register|CBDSR|32|Plane A:<br>H'E821004C<br>Plane B:<br>H'E821104C<br>Mirror:<br>H'E821204C|32|
||CEU Firewall operation control register|CFWCR|32|H'E821005C|32|
||CEU Capture low-pass filter control register|CLFCR|32|Plane A:<br>H'E8210060<br>Plane B:<br>H'E8211060<br>Mirror:<br>H'E8212060|32|
||CEU Capture data output control register|CDOCR|32|Plane A:<br>H'E8210064<br>Plane B:<br>H'E8211064<br>Mirror:<br>H'E8212064|32|
||CEU Capture event interrupt enable register|CEIER|32|H'E8210070|32|
||CEU Capture event flag clear register|CETCR|32|H'E8210074|32|
||CEU Capture status register|CSTSR|32|H'E821007C|32|
||CEU Capture data size register|CDSSR|32|H'E8210084|32|
||CEU Capture data address Y register 2|CDAYR2|32|Plane A:<br>H'E8210090<br>Plane B:<br>H'E8211090<br>Mirror:<br>H'E8212090|32|
||CEU Capture data address C register 2|CDACR2|32|Plane A:<br>H'E8210094<br>Plane B:<br>H'E8211094<br>Mirror:<br>H'E8212094|32|
||CEU Capture data bottom-field address Y register 2|CDBYR2|32|Plane A:<br>H'E8210098<br>Plane B:<br>H'E8211098<br>Mirror:<br>H'E8212098|32|
||CEU Capture data bottom-field address C register 2|CDBCR2|32|Plane A:<br>H'E821009C<br>Plane B:<br>H'E821109C<br>Mirror:<br>H'E821209C|32|
|SCUX|IPC0_0 Initialization Register|IPCIR_IPC0_0|32|H'E8208000|32|
||IPC0_0 Pass Select Register|IPSLR_IPC0_0|32|H'E8208004|32|
||IPC0_1 Initialization Register|IPCIR_IPC0_1|32|H'E8208100|32|
||IPC0_1 Pass Select Register|IPSLR_IPC0_1|32|H'E8208104|32|
||IPC0_2 Initialization Register|IPCIR_IPC0_2|32|H'E8208200|32|
||IPC0_2 Pass Select Register|IPSLR_IPC0_2|32|H'E8208204|32|
||IPC0_3 Initialization Register|IPCIR_IPC0_3|32|H'E8208300|32|
||IPC0_3 Pass Select Register|IPSLR_IPC0_3|32|H'E8208304|32|
||OPC0_0 Initialization Register|OPCIR_OPC0_0|32|H'E8208400|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|SCUX|OPC0_0 Pass Select Register|OPSLR_OPC0_0|32|H'E8208404|32|
||OPC0_1 Initialization Register|OPCIR_OPC0_1|32|H'E8208500|32|
||OPC0_1 Pass Select Register|OPSLR_OPC0_1|32|H'E8208504|32|
||OPC0_2 Initialization Register|OPCIR_OPC0_2|32|H'E8208600|32|
||OPC0_2 Pass Select Register|OPSLR_OPC0_2|32|H'E8208604|32|
||OPC0_3 Initialization Register|OPCIR_OPC0_3|32|H'E8208700|32|
||OPC0_3 Pass Select Register|OPSLR_OPC0_3|32|H'E8208704|32|
||FFD0_0 FIFO Download Initialization Register|FFDIR_FFD0_0|32|H'E8208800|32|
||FFD0_0 FIFO Download Audio Information Register|FDAIR_FFD0_0|32|H'E8208804|32|
||FFD0_0 FIFO Download Request Size Register|DRQSR_FFD0_0|32|H'E8208808|32|
||FFD0_0 FIFO Download Pass Register|FFDPR_FFD0_0|32|H'E820880C|32|
||FFD0_0 FIFO Download Boot Register|FFDBR_FFD0_0|32|H'E8208810|32|
||FFD0_0 FIFO Download Event Mask Register|DEVMR_FFD0_0|32|H'E8208814|32|
||FFD0_0 FIFO Download Event Clear Register|DEVCR_FFD0_0|32|H'E820881C|32|
||FFD0_1 FIFO Download Initialization Register|FFDIR_FFD0_1|32|H'E8208900|32|
||FFD0_1 FIFO Download Audio Information Register|FDAIR_FFD0_1|32|H'E8208904|32|
||FFD0_1 FIFO Download Request Size Register|DRQSR_FFD0_1|32|H'E8208908|32|
||FFD0_1 FIFO Download Pass Register|FFDPR_FFD0_1|32|H'E820890C|32|
||FFD0_1 FIFO Download Boot Register|FFDBR_FFD0_1|32|H'E8208910|32|
||FFD0_1 FIFO Download Event Mask Register|DEVMR_FFD0_1|32|H'E8208914|32|
||FFD0_1 FIFO Download Event Clear Register|DEVCR_FFD0_1|32|H'E820891C|32|
||FFD0_2 FIFO Download Initialization Register|FFDIR_FFD0_2|32|H'E8208A00|32|
||FFD0_2 FIFO Download Audio Information Register|FDAIR_FFD0_2|32|H'E8208A04|32|
||FFD0_2 FIFO Download Request Size Register|DRQSR_FFD0_2|32|H'E8208A08|32|
||FFD0_2 FIFO Download Pass Register|FFDPR_FFD0_2|32|H'E8208A0C|32|
||FFD0_2 FIFO Download Boot Register|FFDBR_FFD0_2|32|H'E8208A10|32|
||FFD0_2 FIFO Download Event Mask Register|DEVMR_FFD0_2|32|H'E8208A14|32|
||FFD0_2 FIFO Download Event Clear Register|DEVCR_FFD0_2|32|H'E8208A1C|32|
||FFD0_3 FIFO Download Initialization Register|FFDIR_FFD0_3|32|H'E8208B00|32|
||FFD0_3 FIFO Download Audio Information Register|FDAIR_FFD0_3|32|H'E8208B04|32|
||FFD0_3 FIFO Download Request Size Register|DRQSR_FFD0_3|32|H'E8208B08|32|
||FFD0_3 FIFO Download Pass Register|FFDPR_FFD0_3|32|H'E8208B0C|32|
||FFD0_3 FIFO Download Boot Register|FFDBR_FFD0_3|32|H'E8208B10|32|
||FFD0_3 FIFO Download Event Mask Register|DEVMR_FFD0_3|32|H'E8208B14|32|
||FFD0_3 FIFO Download Event Clear Register|DEVCR_FFD0_3|32|H'E8208B1C|32|
||FFU0_0 FIFO Upload Initialization Register|FFUIR_FFU0_0|32|H'E8208C00|32|
||FFU0_0 FIFO Upload Audio Information Register|FUAIR_FFU0_0|32|H'E8208C04|32|
||FFU0_0 FIFO Upload Request Size Register|URQSR_FFU0_0|32|H'E8208C08|32|
||FFU0_0 FIFO Upload Pass Register|FFUPR_FFU0_0|32|H'E8208C0C|32|
||FFU0_0 FIFO Upload  Event Mask Register|UEVMR_FFU0_0|32|H'E8208C10|32|
||FFU0_0 FIFO Upload  Event Clear Register|UEVCR_FFU0_0|32|H'E8208C18|32|
||FFU0_1 FIFO Upload Initialization Register|FFUIR_FFU0_1|32|H'E8208D00|32|
||FFU0_1 FIFO Upload Audio Information Register|FUAIR_FFU0_1|32|H'E8208D04|32|
||FFU0_1 FIFO Upload Request Size Register|URQSR_FFU0_1|32|H'E8208D08|32|
||FFU0_1 FIFO Upload Pass Register|FFUPR_FFU0_1|32|H'E8208D0C|32|
||FFU0_1 FIFO Upload  Event Mask Register|UEVMR_FFU0_1|32|H'E8208D10|32|
||FFU0_1 FIFO Upload  Event Clear Register|UEVCR_FFU0_1|32|H'E8208D18|32|
||FFU0_2 FIFO Upload Initialization Register|FFUIR_FFU0_2|32|H'E8208E00|32|
||FFU0_2 FIFO Upload Audio Information Register|FUAIR_FFU0_2|32|H'E8208E04|32|
||FFU0_2 FIFO Upload Request Size Register|URQSR_FFU0_2|32|H'E8208E08|32|
||FFU0_2 FIFO Upload Pass Register|FFUPR_FFU0_2|32|H'E8208E0C|32|
||FFU0_2 FIFO Upload  Event Mask Register|UEVMR_FFU0_2|32|H'E8208E10|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|SCUX|FFU0_2 FIFO Upload  Event Clear Register|UEVCR_FFU0_2|32|H'E8208E18|32|
||FFU0_3 FIFO Upload Initialization Register|FFUIR_FFU0_3|32|H'E8208F00|32|
||FFU0_3 FIFO Upload Audio Information Register|FUAIR_FFU0_3|32|H'E8208F04|32|
||FFU0_3 FIFO Upload Request Size Register|URQSR_FFU0_3|32|H'E8208F08|32|
||FFU0_3 FIFO Upload Pass Register|FFUPR_FFU0_3|32|H'E8208F0C|32|
||FFU0_3 FIFO Upload  Event Mask Register|UEVMR_FFU0_3|32|H'E8208F10|32|
||FFU0_3 FIFO Upload  Event Clear Register|UEVCR_FFU0_3|32|H'E8208F18|32|
||2SRC0_0 Initialization Register 0|SRCIR0_2SRC0_0|32|H'E8209000|32|
||2SRC0_0 Audio Information Register 0|SADIR0_2SRC0_0|32|H'E8209004|32|
||2SRC0_0 Bypass Register 0|SRCBR0_2SRC0_0|32|H'E8209008|32|
||2SRC0_0 IFS Control Register 0|IFSCR0_2SRC0_0|32|H'E820900C|32|
||2SRC0_0 IFS Value Setting Register 0|IFSVR0_2SRC0_0|32|H'E8209010|32|
||2SRC0_0 Control Register 0|SRCCR0_2SRC0_0|32|H'E8209014|32|
||2SRC0_0 Minimum FS Setting Register 0|MNFSR0_2SRC0_0|32|H'E8209018|32|
||2SRC0_0 Buffer Size Setting Register 0|BFSSR0_2SRC0_0|32|H'E820901C|32|
||2SRC0_0 SCU2 Status Register 0|SC2SR0_2SRC0_0|32|H'E8209020|32|
||2SRC0_0 Wait Time Setting Register 0|WATSR0_2SRC0_0|32|H'E8209024|32|
||2SRC0_0 Event Mask Register 0|SEVMR0_2SRC0_0|32|H'E8209028|32|
||2SRC0_0 Event Clear Register 0|SEVCR0_2SRC0_0|32|H'E8209030|32|
||2SRC0_0 Initialization Register 1|SRCIR1_2SRC0_0|32|H'E8209034|32|
||2SRC0_0 Audio Information Register 1|SADIR1_2SRC0_0|32|H'E8209038|32|
||2SRC0_0 Bypass Register 1|SRCBR1_2SRC0_0|32|H'E820903C|32|
||2SRC0_0 IFS Control Register 1|IFSCR1_2SRC0_0|32|H'E8209040|32|
||2SRC0_0 IFS Value Setting Register 1|IFSVR1_2SRC0_0|32|H'E8209044|32|
||2SRC0_0 Control Register 1|SRCCR1_2SRC0_0|32|H'E8209048|32|
||2SRC0_0 Minimum FS Setting Register 1|MNFSR1_2SRC0_0|32|H'E820904C|32|
||2SRC0_0 Buffer Size Setting Register 1|BFSSR1_2SRC0_0|32|H'E8209050|32|
||2SRC0_0 SCU2 Status Register 1|SC2SR1_2SRC0_0|32|H'E8209054|32|
||2SRC0_0 Wait Time Setting Register 1|WATSR1_2SRC0_0|32|H'E8209058|32|
||2SRC0_0 Event Mask Register 1|SEVMR1_2SRC0_0|32|H'E820905C|32|
||2SRC0_0 Event Clear Register 1|SEVCR1_2SRC0_0|32|H'E8209064|32|
||2SRC0_0 Initialization Register RIF|SRCIRR_2SRC0_0|32|H'E8209068|32|
||2SRC0_1 Initialization Register 0|SRCIR0_2SRC0_1|32|H'E8209100|32|
||2SRC0_1 Audio Information Register 0|SADIR0_2SRC0_1|32|H'E8209104|32|
||2SRC0_1 Bypass Register 0|SRCBR0_2SRC0_1|32|H'E8209108|32|
||2SRC0_1 IFS Control Register 0|IFSCR0_2SRC0_1|32|H'E820910C|32|
||2SRC0_1 IFS Value Setting Register 0|IFSVR0_2SRC0_1|32|H'E8209110|32|
||2SRC0_1 Control Register 0|SRCCR0_2SRC0_1|32|H'E8209114|32|
||2SRC0_1 Minimum FS Setting Register 0|MNFSR0_2SRC0_1|32|H'E8209118|32|
||2SRC0_1 Buffer Size Setting Register 0|BFSSR0_2SRC0_1|32|H'E820911C|32|
||2SRC0_1 SCU2 Status Register 0|SC2SR0_2SRC0_1|32|H'E8209120|32|
||2SRC0_1 Wait Time Setting Register 0|WATSR0_2SRC0_1|32|H'E8209124|32|
||2SRC0_1 Event Mask Register 0|SEVMR0_2SRC0_1|32|H'E8209128|32|
||2SRC0_1 Event Clear Register 0|SEVCR0_2SRC0_1|32|H'E8209130|32|
||2SRC0_1 Initialization Register 1|SRCIR1_2SRC0_1|32|H'E8209134|32|
||2SRC0_1 Audio Information Register 1|SADIR1_2SRC0_1|32|H'E8209138|32|
||2SRC0_1 Bypass Register 1|SRCBR1_2SRC0_1|32|H'E820913C|32|
||2SRC0_1 IFS Control Register 1|IFSCR1_2SRC0_1|32|H'E8209140|32|
||2SRC0_1 IFS Value Setting Register 1|IFSVR1_2SRC0_1|32|H'E8209144|32|
||2SRC0_1 Control Register 1|SRCCR1_2SRC0_1|32|H'E8209148|32|
||2SRC0_1 Minimum FS Setting Register 1|MNFSR1_2SRC0_1|32|H'E820914C|32|
||2SRC0_1 Buffer Size Setting Register 1|BFSSR1_2SRC0_1|32|H'E8209150|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|SCUX|2SRC0_1 SCU2 Status Register 1|SC2SR1_2SRC0_1|32|H'E8209154|32|
||2SRC0_1 Wait Time Setting Register 1|WATSR1_2SRC0_1|32|H'E8209158|32|
||2SRC0_1 Event Mask Register 1|SEVMR1_2SRC0_1|32|H'E820915C|32|
||2SRC0_1 Event Clear Register 1|SEVCR1_2SRC0_1|32|H'E8209164|32|
||2SRC0_1 Initialization Register RIF|SRCIRR_2SRC0_1|32|H'E8209168|32|
||DVU0_0 Initialization Register|DVUIR_DVU0_0|32|H'E8209200|32|
||DVU0_0 Audio Information Register|VADIR_DVU0_0|32|H'E8209204|32|
||DVU0_0 Bypass Register|DVUBR_DVU0_0|32|H'E8209208|32|
||DVU0_0 Control Register|DVUCR_DVU0_0|32|H'E820920C|32|
||DVU0_0 Zero Cross Mute Control Register|ZCMCR_DVU0_0|32|H'E8209210|32|
||DVU0_0 Volume Ramp Control Register|VRCTR_DVU0_0|32|H'E8209214|32|
||DVU0_0 Volume Ramp Period Register|VRPDR_DVU0_0|32|H'E8209218|32|
||DVU0_0 Volume Ramp Decibel Register|VRDBR_DVU0_0|32|H'E820921C|32|
||DVU0_0 Volume Ramp Wait Time Register|VRWTR_DVU0_0|32|H'E8209220|32|
||DVU0_0 Volume Value Setting 0 Register|VOL0R_DVU0_0|32|H'E8209224|32|
||DVU0_0 Volume Value Setting 1 Register|VOL1R_DVU0_0|32|H'E8209228|32|
||DVU0_0 Volume Value Setting 2 Register|VOL2R_DVU0_0|32|H'E820922C|32|
||DVU0_0 Volume Value Setting 3 Register|VOL3R_DVU0_0|32|H'E8209230|32|
||DVU0_0 Volume Value Setting 4 Register|VOL4R_DVU0_0|32|H'E8209234|32|
||DVU0_0 Volume Value Setting 5 Register|VOL5R_DVU0_0|32|H'E8209238|32|
||DVU0_0 Volume Value Setting 6 Register|VOL6R_DVU0_0|32|H'E820923C|32|
||DVU0_0 Volume Value Setting 7 Register|VOL7R_DVU0_0|32|H'E8209240|32|
||DVU0_0 Enable Register|DVUER_DVU0_0|32|H'E8209244|32|
||DVU0_0 Status Register|DVUSR_DVU0_0|32|H'E8209248|32|
||DVU0_0 Event Mask Register|VEVMR_DVU0_0|32|H'E820924C|32|
||DVU0_0 Event Clear Register|VEVCR_DVU0_0|32|H'E8209254|32|
||DVU0_1 Initialization Register|DVUIR_DVU0_1|32|H'E8209300|32|
||DVU0_1 Audio Information Register|VADIR_DVU0_1|32|H'E8209304|32|
||DVU0_1 Bypass Register|DVUBR_DVU0_1|32|H'E8209308|32|
||DVU0_1 Control Register|DVUCR_DVU0_1|32|H'E820930C|32|
||DVU0_1 Zero Cross Mute Control Register|ZCMCR_DVU0_1|32|H'E8209310|32|
||DVU0_1 Volume Ramp Control Register|VRCTR_DVU0_1|32|H'E8209314|32|
||DVU0_1 Volume Ramp Period Register|VRPDR_DVU0_1|32|H'E8209318|32|
||DVU0_1 Volume Ramp Decibel Register|VRDBR_DVU0_1|32|H'E820931C|32|
||DVU0_1 Volume Ramp Wait Time Register|VRWTR_DVU0_1|32|H'E8209320|32|
||DVU0_1 Volume Value Setting 0 Register|VOL0R_DVU0_1|32|H'E8209324|32|
||DVU0_1 Volume Value Setting 1 Register|VOL1R_DVU0_1|32|H'E8209328|32|
||DVU0_1 Volume Value Setting 2 Register|VOL2R_DVU0_1|32|H'E820932C|32|
||DVU0_1 Volume Value Setting 3 Register|VOL3R_DVU0_1|32|H'E8209330|32|
||DVU0_1 Volume Value Setting 4 Register|VOL4R_DVU0_1|32|H'E8209334|32|
||DVU0_1 Volume Value Setting 5 Register|VOL5R_DVU0_1|32|H'E8209338|32|
||DVU0_1 Volume Value Setting 6 Register|VOL6R_DVU0_1|32|H'E820933C|32|
||DVU0_1 Volume Value Setting 7 Register|VOL7R_DVU0_1|32|H'E8209340|32|
||DVU0_1 Enable Register|DVUER_DVU0_1|32|H'E8209344|32|
||DVU0_1 Status Register|DVUSR_DVU0_1|32|H'E8209348|32|
||DVU0_1 Event Mask Register|VEVMR_DVU0_1|32|H'E820934C|32|
||DVU0_1 Event Clear Register|VEVCR_DVU0_1|32|H'E8209354|32|
||DVU0_2 Initialization Register|DVUIR_DVU0_2|32|H'E8209400|32|
||DVU0_2 Audio Information Register|VADIR_DVU0_2|32|H'E8209404|32|
||DVU0_2 Bypass Register|DVUBR_DVU0_2|32|H'E8209408|32|
||DVU0_2 Control Register|DVUCR_DVU0_2|32|H'E820940C|32|
||DVU0_2 Zero Cross Mute Control Register|ZCMCR_DVU0_2|32|H'E8209410|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|SCUX|DVU0_2 Volume Ramp Control Register|VRCTR_DVU0_2|32|H'E8209414|32|
||DVU0_2 Volume Ramp Period Register|VRPDR_DVU0_2|32|H'E8209418|32|
||DVU0_2 Volume Ramp Decibel Register|VRDBR_DVU0_2|32|H'E820941C|32|
||DVU0_2 Volume Ramp Wait Time Register|VRWTR_DVU0_2|32|H'E8209420|32|
||DVU0_2 Volume Value Setting 0 Register|VOL0R_DVU0_2|32|H'E8209424|32|
||DVU0_2 Volume Value Setting 1 Register|VOL1R_DVU0_2|32|H'E8209428|32|
||DVU0_2 Volume Value Setting 2 Register|VOL2R_DVU0_2|32|H'E820942C|32|
||DVU0_2 Volume Value Setting 3 Register|VOL3R_DVU0_2|32|H'E8209430|32|
||DVU0_2 Volume Value Setting 4 Register|VOL4R_DVU0_2|32|H'E8209434|32|
||DVU0_2 Volume Value Setting 5 Register|VOL5R_DVU0_2|32|H'E8209438|32|
||DVU0_2 Volume Value Setting 6 Register|VOL6R_DVU0_2|32|H'E820943C|32|
||DVU0_2 Volume Value Setting 7 Register|VOL7R_DVU0_2|32|H'E8209440|32|
||DVU0_2 Enable Register|DVUER_DVU0_2|32|H'E8209444|32|
||DVU0_2 Status Register|DVUSR_DVU0_2|32|H'E8209448|32|
||DVU0_2 Event Mask Register|VEVMR_DVU0_2|32|H'E820944C|32|
||DVU0_2 Event Clear Register|VEVCR_DVU0_2|32|H'E8209454|32|
||DVU0_3 Initialization Register|DVUIR_DVU0_3|32|H'E8209500|32|
||DVU0_3 Audio Information Register|VADIR_DVU0_3|32|H'E8209504|32|
||DVU0_3 Bypass Register|DVUBR_DVU0_3|32|H'E8209508|32|
||DVU0_3 Control Register|DVUCR_DVU0_3|32|H'E820950C|32|
||DVU0_3 Zero Cross Mute Control Register|ZCMCR_DVU0_3|32|H'E8209510|32|
||DVU0_3 Volume Ramp Control Register|VRCTR_DVU0_3|32|H'E8209514|32|
||DVU0_3 Volume Ramp Period Register|VRPDR_DVU0_3|32|H'E8209518|32|
||DVU0_3 Volume Ramp Decibel Register|VRDBR_DVU0_3|32|H'E820951C|32|
||DVU0_3 Volume Ramp Wait Time Register|VRWTR_DVU0_3|32|H'E8209520|32|
||DVU0_3 Volume Value Setting 0 Register|VOL0R_DVU0_3|32|H'E8209524|32|
||DVU0_3 Volume Value Setting 1 Register|VOL1R_DVU0_3|32|H'E8209528|32|
||DVU0_3 Volume Value Setting 2 Register|VOL2R_DVU0_3|32|H'E820952C|32|
||DVU0_3 Volume Value Setting 3 Register|VOL3R_DVU0_3|32|H'E8209530|32|
||DVU0_3 Volume Value Setting 4 Register|VOL4R_DVU0_3|32|H'E8209534|32|
||DVU0_3 Volume Value Setting 5 Register|VOL5R_DVU0_3|32|H'E8209538|32|
||DVU0_3 Volume Value Setting 6 Register|VOL6R_DVU0_3|32|H'E820953C|32|
||DVU0_3 Volume Value Setting 7 Register|VOL7R_DVU0_3|32|H'E8209540|32|
||DVU0_3 Enable Register|DVUER_DVU0_3|32|H'E8209544|32|
||DVU0_3 Status Register|DVUSR_DVU0_3|32|H'E8209548|32|
||DVU0_3 Event Mask Register|VEVMR_DVU0_3|32|H'E820954C|32|
||DVU0_3 Event Clear Register|VEVCR_DVU0_3|32|H'E8209554|32|
||MIX0_0 Initialization Register|MIXIR_MIX0_0|32|H'E8209600|32|
||MIX0_0 Audio Information Register|MADIR_MIX0_0|32|H'E8209604|32|
||MIX0_0 Bypass Register|MIXBR_MIX0_0|32|H'E8209608|32|
||MIX0_0 Mode Register|MIXMR_MIX0_0|32|H'E820960C|32|
||MIX0_0 Volume Period Register|MVPDR_MIX0_0|32|H'E8209610|32|
||MIX0_0 Decibel A Register|MDBAR_MIX0_0|32|H'E8209614|32|
||MIX0_0 Decibel B Register|MDBBR_MIX0_0|32|H'E8209618|32|
||MIX0_0 Decibel C Register|MDBCR_MIX0_0|32|H'E820961C|32|
||MIX0_0 Decibel D Register|MDBDR_MIX0_0|32|H'E8209620|32|
||MIX0_0 Decibel Enable Register|MDBER_MIX0_0|32|H'E8209624|32|
||MIX0_0 Status Register|MIXSR_MIX0_0|32|H'E8209628|32|
||Software Reset Register|SWRSR_CIM|32|H'E8209700|32|
||DMA Control Register|DMACR_CIM|32|H'E8209704|32|
||DMA Transfer Register for FFD0_0 RAM|DMATD0_CIM|32|H'E8209708|16, 32|
||DMA Transfer Register for FFD0_1 RAM|DMATD1_CIM|32|H'E820970C|16, 32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|SCUX|DMA Transfer Register for FFD0_2 RAM|DMATD2_CIM|32|H'E8209710|16, 32|
||DMA Transfer Register for FFD0_3 RAM|DMATD3_CIM|32|H'E8209714|16, 32|
||DMA Transfer Register for FFU0_0 RAM|DMATU0_CIM|32|H'E8209718|16, 32|
||DMA Transfer Register for FFU0_1 RAM|DMATU1_CIM|32|H'E820971C|16, 32|
||DMA Transfer Register for FFU0_2 RAM|DMATU2_CIM|32|H'E8209720|16, 32|
||DMA Transfer Register for FFU0_3 RAM|DMATU3_CIM|32|H'E8209724|16, 32|
||SSI route select register|SSIRSEL_CIM|32|H'E8209738|32|
||FFD0_0 timing select register|FDTSEL0_CIM|32|H'E820973C|32|
||FFD0_1 timing select register|FDTSEL1_CIM|32|H'E8209740|32|
||FFD0_2 timing select register|FDTSEL2_CIM|32|H'E8209744|32|
||FFD0_3 timing select register|FDTSEL3_CIM|32|H'E8209748|32|
||FFU0_0 timing select register|FUTSEL0_CIM|32|H'E820974C|32|
||FFU0_1 timing select register|FUTSEL1_CIM|32|H'E8209750|32|
||FFU0_2 timing select register|FUTSEL2_CIM|32|H'E8209754|32|
||FFU0_3 timing select register|FUTSEL3_CIM|32|H'E8209758|32|
||SSI pin mode register|SSIPMD_CIM|32|H'E820975C|32|
||SSI control register|SSICTRL_CIM|32|H'E8209760|32|
||SRC0 route select register|SRCRSEL0_CIM|32|H'E8209764|32|
||SRC1 route select register|SRCRSEL1_CIM|32|H'E8209768|32|
||SRC2 route select register|SRCRSEL2_CIM|32|H'E820976C|32|
||SRC3 route select register|SRCRSEL3_CIM|32|H'E8209770|32|
||MIX route select register|MIXRSEL_CIM|32|H'E8209774|32|
|SD host interface|Command type register_0|SD_CMD_0|16|H'E804E000|16|
||SD command argument register 0_0|SD_ARG0_0|16|H'E804E004|16|
||SD command argument register 1_0|SD_ARG1_0|16|H'E804E006|16|
||Data stop register_0|SD_STOP_0|16|H'E804E008|16|
||Block count register_0|SD_SECCNT_0|16|H'E804E00A|16|
||SD card response register 00_0|SD_RSP00_0|16|H'E804E00C|16|
||SD card response register 01_0|SD_RSP01_0|16|H'E804E00E|16|
||SD card response register 02_0|SD_RSP02_0|16|H'E804E010|16|
||SD card response register 03_0|SD_RSP03_0|16|H'E804E012|16|
||SD card response register 04_0|SD_RSP04_0|16|H'E804E014|16|
||SD card response register 05_0|SD_RSP05_0|16|H'E804E016|16|
||SD card response register 06_0|SD_RSP06_0|16|H'E804E018|16|
||SD card response register 07_0|SD_RSP07_0|16|H'E804E01A|16|
||SD card interrupt flag register 1_0|SD_INFO1_0|16|H'E804E01C|16|
||SD card interrupt flag register 2_0|SD_INFO2_0|16|H'E804E01E|16|
||SD_INFO1 interrupt mask register_0|SD_INFO1_MASK_0|16|H'E804E020|16|
||SD_INFO2 interrupt mask register_0|SD_INFO2_MASK_0|16|H'E804E022|16|
||SD clock control register_0|SD_CLK_CTRL_0|16|H'E804E024|16|
||Transfer data length register_0|SD_SIZE_0|16|H'E804E026|16|
||SD card access control option register_0|SD_OPTION_0|16|H'E804E028|16|
||SD error status register 1_0|SD_ERR_STS1_0|16|H'E804E02C|16|
||SD error status register 2_0|SD_ERR_STS2_0|16|H'E804E02E|16|
||SD buffer read/write register_0|SD_BUF0_0|32|H'E804E030|32|
||SDIO mode control register_0|SDIO_MODE_0|16|H'E804E034|16|
||SDIO interrupt flag register_0|SDIO_INFO1_0|16|H'E804E036|16|
||SDIO_INFO1 interrupt mask register_0|SDIO_INFO1_MASK_0|16|H'E804E038|16|
||DMA mode enable register_0|CC_EXT_MODE_0|16|H'E804E0D8|16|
||Software reset register_0|SOFT_RST_0|16|H'E804E0E0|16|
||Version register_0|VERSION_0|16|H'E804E0E2|16|
||Swap control register_0|EXT_SWAP_0|16|H'E804E0F0|16|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|SD host interface|Command type register_1|SD_CMD_1|16|H'E804E800|16|
||SD command argument register 0_1|SD_ARG0_1|16|H'E804E804|16|
||SD command argument register 1_1|SD_ARG1_1|16|H'E804E806|16|
||Data stop register_1|SD_STOP_1|16|H'E804E808|16|
||Block count register_1|SD_SECCNT_1|16|H'E804E80A|16|
||SD card response register 00_1|SD_RSP00_1|16|H'E804E80C|16|
||SD card response register 01_1|SD_RSP01_1|16|H'E804E80E|16|
||SD card response register 02_1|SD_RSP02_1|16|H'E804E810|16|
||SD card response register 03_1|SD_RSP03_1|16|H'E804E812|16|
||SD card response register 04_1|SD_RSP04_1|16|H'E804E814|16|
||SD card response register 05_1|SD_RSP05_1|16|H'E804E816|16|
||SD card response register 06_1|SD_RSP06_1|16|H'E804E818|16|
||SD card response register 07_1|SD_RSP07_1|16|H'E804E81A|16|
||SD card interrupt flag register 1_1|SD_INFO1_1|16|H'E804E81C|16|
||SD card interrupt flag register 2_1|SD_INFO2_1|16|H'E804E81E|16|
||SD_INFO1 interrupt mask register_1|SD_INFO1_MASK_1|16|H'E804E820|16|
||SD_INFO2 interrupt mask register_1|SD_INFO2_MASK_1|16|H'E804E822|16|
||SD clock control register_1|SD_CLK_CTRL_1|16|H'E804E824|16|
||Transfer data length register_1|SD_SIZE_1|16|H'E804E826|16|
||SD card access control option register_1|SD_OPTION_1|16|H'E804E828|16|
||SD error status register 1_1|SD_ERR_STS1_1|16|H'E804E82C|16|
||SD error status register 2_1|SD_ERR_STS2_1|16|H'E804E82E|16|
||SD buffer read/write register_1|SD_BUF0_1|32|H'E804E830|32|
||SDIO mode control register_1|SDIO_MODE_1|16|H'E804E834|16|
||SDIO interrupt flag register_1|SDIO_INFO1_1|16|H'E804E836|16|
||SDIO_INFO1 interrupt mask register_1|SDIO_INFO1_MASK_1|16|H'E804E838|16|
||DMA mode enable register_1|CC_EXT_MODE_1|16|H'E804E8D8|16|
||Software reset register_1|SOFT_RST_1|16|H'E804E8E0|16|
||Version register_1|VERSION_1|16|H'E804E8E2|16|
||Swap control register_1|EXT_SWAP_1|16|H'E804E8F0|16|
|MMC host interface|Command setting register|CE_CMD_SET|32|H'E804C800|16|
|||||H'E804C802|16|
||Argument register|CE_ARG|32|H'E804C808|32|
||Argument register for automatically-issued CMD12|CE_ARG_CMD12|32|H'E804C80C|32|
||Command control register|CE_CMD_CTRL|32|H'E804C810|32|
||Transfer block setting register|CE_BLOCK_SET|32|H'E804C814|32|
||Clock control register|CE_CLK_CTRL|32|H'E804C818|32|
||Buffer access configuration register|CE_BUF_ACC|32|H'E804C81C|32|
||Response register 3|CE_RESP3|32|H'E804C820|32|
||Response register 2|CE_RESP2|32|H'E804C824|32|
||Response register 1|CE_RESP1|32|H'E804C828|32|
||Response register 0|CE_RESP0|32|H'E804C82C|32|
||Response register for automatically-issued CMD12|CE_RESP_CMD12|32|H'E804C830|32|
||Data register|CE_DATA|32|H'E804C834|32|
||Interrupt flag register|CE_INT|32|H'E804C840|32|
||Interrupt enable register|CE_INT_EN|32|H'E804C844|32|
||Status register 1|CE_HOST_STS1|32|H'E804C848|32|
||Status register 2|CE_HOST_STS2|32|H'E804C84C|32|
||DMA mode setting register|CE_DMA_MODE|32|H'E804C85C|32|
||Card detection/port control register|CE_DETECT|32|H'E804C870|32|
||Special mode setting register|CE_ADD_MODE|32|H'E804C874|32|
||Version register|CE_VERSION|32|H'E804C87C|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Ports|Port register_1|P1|16|H'FCFE3004|16|
||Port register_2|P2|16|H'FCFE3008|16|
||Port register_3|P3|16|H'FCFE300C|16|
||Port register_4|P4|16|H'FCFE3010|16|
||Port register_5|P5|16|H'FCFE3014|16|
||Port register_6|P6|16|H'FCFE3018|16|
||Port register_7|P7|16|H'FCFE301C|16|
||Port register_8|P8|16|H'FCFE3020|16|
||Port register_9|P9|16|H'FCFE3024|16|
||Port set/reset register_1|PSR1|32|H'FCFE3104|32|
||Port set/reset register_2|PSR2|32|H'FCFE3108|32|
||Port set/reset register_3|PSR3|32|H'FCFE310C|32|
||Port set/reset register_4|PSR4|32|H'FCFE3110|32|
||Port set/reset register_5|PSR5|32|H'FCFE3114|32|
||Port set/reset register_6|PSR6|32|H'FCFE3118|32|
||Port set/reset register_7|PSR7|32|H'FCFE311C|32|
||Port set/reset register_8|PSR8|32|H'FCFE3120|32|
||Port set/reset register_9|PSR9|32|H'FCFE3124|32|
||Port pin read register_0|PPR0|16|H'FCFE3200|16|
||Port pin read register_1|PPR1|16|H'FCFE3204|16|
||Port pin read register_2|PPR2|16|H'FCFE3208|16|
||Port pin read register_3|PPR3|16|H'FCFE320C|16|
||Port pin read register_4|PPR4|16|H'FCFE3210|16|
||Port pin read register_5|PPR5|16|H'FCFE3214|16|
||Port pin read register_6|PPR6|16|H'FCFE3218|16|
||Port pin read register_7|PPR7|16|H'FCFE321C|16|
||Port pin read register_8|PPR8|16|H'FCFE3220|16|
||Port pin read register_9|PPR9|16|H'FCFE3224|16|
||Port mode register_1|PM1|16|H'FCFE3304|16|
||Port mode register_2|PM2|16|H'FCFE3308|16|
||Port mode register_3|PM3|16|H'FCFE330C|16|
||Port mode register_4|PM4|16|H'FCFE3310|16|
||Port mode register_5|PM5|16|H'FCFE3314|16|
||Port mode register_6|PM6|16|H'FCFE3318|16|
||Port mode register_7|PM7|16|H'FCFE331C|16|
||Port mode register_8|PM8|16|H'FCFE3320|16|
||Port mode register_9|PM9|16|H'FCFE3324|16|
||Port mode control register_0|PMC0|16|H'FCFE3400|16|
||Port mode control register_1|PMC1|16|H'FCFE3404|16|
||Port mode control register_2|PMC2|16|H'FCFE3408|16|
||Port mode control register_3|PMC3|16|H'FCFE340C|16|
||Port mode control register_4|PMC4|16|H'FCFE3410|16|
||Port mode control register_5|PMC5|16|H'FCFE3414|16|
||Port mode control register_6|PMC6|16|H'FCFE3418|16|
||Port mode control register_7|PMC7|16|H'FCFE341C|16|
||Port mode control register_8|PMC8|16|H'FCFE3420|16|
||Port mode control register_9|PMC9|16|H'FCFE3424|16|
||Port function control register_0|PFC0|16|H'FCFE3500|16|
||Port function control register_1|PFC1|16|H'FCFE3504|16|
||Port function control register_2|PFC2|16|H'FCFE3508|16|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Ports|Port function control register_3|PFC3|16|H'FCFE350C|16|
||Port function control register_4|PFC4|16|H'FCFE3510|16|
||Port function control register_5|PFC5|16|H'FCFE3514|16|
||Port function control register_6|PFC6|16|H'FCFE3518|16|
||Port function control register_7|PFC7|16|H'FCFE351C|16|
||Port function control register_8|PFC8|16|H'FCFE3520|16|
||Port function control register_9|PFC9|16|H'FCFE3524|16|
||Port function control expansion register_0|PFCE0|16|H'FCFE3600|16|
||Port function control expansion register_1|PFCE1|16|H'FCFE3604|16|
||Port function control expansion register_2|PFCE2|16|H'FCFE3608|16|
||Port function control expansion register_3|PFCE3|16|H'FCFE360C|16|
||Port function control expansion register_4|PFCE4|16|H'FCFE3610|16|
||Port function control expansion register_5|PFCE5|16|H'FCFE3614|16|
||Port function control expansion register_6|PFCE6|16|H'FCFE3618|16|
||Port function control expansion register_7|PFCE7|16|H'FCFE361C|16|
||Port function control expansion register_8|PFCE8|16|H'FCFE3620|16|
||Port function control expansion register_9|PFCE9|16|H'FCFE3624|16|
||Port NOT register_1|PNOT1|16|H'FCFE3704|16|
||Port NOT register_2|PNOT2|16|H'FCFE3708|16|
||Port NOT register_3|PNOT3|16|H'FCFE370C|16|
||Port NOT register_4|PNOT4|16|H'FCFE3710|16|
||Port NOT register_5|PNOT5|16|H'FCFE3714|16|
||Port NOT register_6|PNOT6|16|H'FCFE3718|16|
||Port NOT register_7|PNOT7|16|H'FCFE371C|16|
||Port NOT register_8|PNOT8|16|H'FCFE3720|16|
||Port NOT register_9|PNOT9|16|H'FCFE3724|16|
||Port mode set/reset register_1|PMSR1|32|H'FCFE3804|32|
||Port mode set/reset register_2|PMSR2|32|H'FCFE3808|32|
||Port mode set/reset register_3|PMSR3|32|H'FCFE380C|32|
||Port mode set/reset register_4|PMSR4|32|H'FCFE3810|32|
||Port mode set/reset register_5|PMSR5|32|H'FCFE3814|32|
||Port mode set/reset register_6|PMSR6|32|H'FCFE3818|32|
||Port mode set/reset register_7|PMSR7|32|H'FCFE381C|32|
||Port mode set/reset register_8|PMSR8|32|H'FCFE3820|32|
||Port mode set/reset register_9|PMSR9|32|H'FCFE3824|32|
||Port mode control set/reset register_0|PMCSR0|32|H'FCFE3900|32|
||Port mode control set/reset register_1|PMCSR1|32|H'FCFE3904|32|
||Port mode control set/reset register_2|PMCSR2|32|H'FCFE3908|32|
||Port mode control set/reset register_3|PMCSR3|32|H'FCFE390C|32|
||Port mode control set/reset register_4|PMCSR4|32|H'FCFE3910|32|
||Port mode control set/reset register_5|PMCSR5|32|H'FCFE3914|32|
||Port mode control set/reset register_6|PMCSR6|32|H'FCFE3918|32|
||Port mode control set/reset register_7|PMCSR7|32|H'FCFE391C|32|
||Port mode control set/reset register_8|PMCSR8|32|H'FCFE3920|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Ports|Port mode control set/reset register_9|PMCSR9|32|H'FCFE3924|32|
||Port function control additional expansion register_0|PFCAE0|16|H'FCFE3A00|16|
||Port function control additional expansion register_1|PFCAE1|16|H'FCFE3A04|16|
||Port function control additional expansion register_2|PFCAE2|16|H'FCFE3A08|16|
||Port function control additional expansion register_3|PFCAE3|16|H'FCFE3A0C|16|
||Port function control additional expansion register_4|PFCAE4|16|H'FCFE3A10|16|
||Port function control additional expansion register_5|PFCAE5|16|H'FCFE3A14|16|
||Port function control additional expansion register_6|PFCAE6|16|H'FCFE3A18|16|
||Port function control additional expansion register_7|PFCAE7|16|H'FCFE3A1C|16|
||Port function control additional expansion register_8|PFCAE8|16|H'FCFE3A20|16|
||Port function control additional expansion register_9|PFCAE9|16|H'FCFE3A24|16|
||Port input buffer control register_0|PIBC0|16|H'FCFE7000|16|
||Port input buffer control register_1|PIBC1|16|H'FCFE7004|16|
||Port input buffer control register_2|PIBC2|16|H'FCFE7008|16|
||Port input buffer control register_3|PIBC3|16|H'FCFE700C|16|
||Port input buffer control register_4|PIBC4|16|H'FCFE7010|16|
||Port input buffer control register_5|PIBC5|16|H'FCFE7014|16|
||Port input buffer control register_6|PIBC6|16|H'FCFE7018|16|
||Port input buffer control register_7|PIBC7|16|H'FCFE701C|16|
||Port input buffer control register_8|PIBC8|16|H'FCFE7020|16|
||Port input buffer control register_9|PIBC9|16|H'FCFE7024|16|
||Port bi-direction control register_1|PBDC1|16|H'FCFE7104|16|
||Port bi-direction control register_2|PBDC2|16|H'FCFE7108|16|
||Port bi-direction control register_3|PBDC3|16|H'FCFE710C|16|
||Port bi-direction control register_4|PBDC4|16|H'FCFE7110|16|
||Port bi-direction control register_5|PBDC5|16|H'FCFE7114|16|
||Port bi-direction control register_6|PBDC6|16|H'FCFE7118|16|
||Port bi-direction control register_7|PBDC7|16|H'FCFE711C|16|
||Port bi-direction control register_8|PBDC8|16|H'FCFE7120|16|
||Port bi-direction control register_9|PBDC9|16|H'FCFE7124|16|
||Port IP control register_1|PIPC1|16|H'FCFE7204|16|
||Port IP control register_2|PIPC2|16|H'FCFE7208|16|
||Port IP control register_3|PIPC3|16|H'FCFE720C|16|
||Port IP control register_4|PIPC4|16|H'FCFE7210|16|
||Port IP control register_5|PIPC5|16|H'FCFE7214|16|
||Port IP control register_6|PIPC6|16|H'FCFE7218|16|
||Port IP control register_7|PIPC7|16|H'FCFE721C|16|
||Port IP control register_8|PIPC8|16|H'FCFE7220|16|
||Port IP control register_9|PIPC9|16|H'FCFE7224|16|
||Port pin read register_J0|JPPR0|16|H'FCFE7B20|16|
||Port mode control register_J0|JPMC0|16|H'FCFE7B40|16|
||Port mode control set/reset register_J0|JPMCSR0|32|H'FCFE7B90|32|
||Port input buffer control register_J0|JPIBC0|16|H'FCFE7F00|16|
||Serial sound interface noise canceler control register|SNCR|32|H'FCFE3C00|32|
|Power-down modes|Standby control register 1|STBCR1|8|H'FCFE0020|8|
||Standby control register 2|STBCR2|8|H'FCFE0024|8|
||Standby control register 3|STBCR3|8|H'FCFE0420|8|
||Standby control register 4|STBCR4|8|H'FCFE0424|8|
||Standby control register 5|STBCR5|8|H'FCFE0428|8|
||Standby control register 6|STBCR6|8|H'FCFE042C|8|
||Standby control register 7|STBCR7|8|H'FCFE0430|8|
||Standby control register 8|STBCR8|8|H'FCFE0434|8|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Power-down modes|Standby control register 9|STBCR9|8|H'FCFE0438|8|
||Standby control register 10|STBCR10|8|H'FCFE043C|8|
||Standby control register 11|STBCR11|8|H'FCFE0440|8|
||Standby control register 12|STBCR12|8|H'FCFE0444|8|
||Software reset control register 1|SWRSTCR1|8|H'FCFE0460|8|
||Software reset control register 2*2|SWRSTCR2|8|H'FCFE0464|8|
||System control register 1|SYSCR1|8|H'FCFE0400|8|
||System control register 2|SYSCR2|8|H'FCFE0404|8|
||System control register 3|SYSCR3|8|H'FCFE0408|8|
||CPU status register|CPUSTS|8|H'FCFE0018|8|
||Standby request register 1|STBREQ1|8|H'FCFE0030|8|
||Standby request register 2|STBREQ2|8|H'FCFE0034|8|
||Standby acknowledge register 1|STBACK1|8|H'FCFE0040|8|
||Standby acknowledge register 2|STBACK2|8|H'FCFE0044|8|
||On-chip data-retention RAM area setting register|RRAMKP|8|H'FCFF1800|8|
||Deep standby control register|DSCTR|8|H'FCFF1802|8|
||Deep standby cancel source select register|DSSSR|16|H'FCFF1804|16|
||Deep standby cancel edge select register|DSESR|16|H'FCFF1806|16|
||Deep standby cancel source flag register|DSFR|16|H'FCFF1808|16|
||XTAL crystal oscillator gain control register|XTALCTR|8|H'FCFF1810|8|
|Debugger interface|DAPROM Peripheral ID4 Register|DAPROM_PERIPHID4|32|H'FC000FD0|32|
||DAPROM Peripheral ID0 Register|DAPROM_PERIPHID0|32|H'FC000FE0|32|
||DAPROM Peripheral ID1Register|DAPROM_PERIPHID1|32|H'FC000FE4|32|
||DAPROM Peripheral ID2 Register|DAPROM_PERIPHID2|32|H'FC000FE8|32|
||DAPROM Peripheral ID3 Register|DAPROM_PERIPHID3|32|H'FC000FEC|32|
||DAPROM Component ID0 Register|DAPROM_COMPID0|32|H'FC000FF0|32|
||DAPROM Component ID1 Register|DAPROM_COMPID1|32|H'FC000FF4|32|
||DAPROM Component ID2 Register|DAPROM_COMPID2|32|H'FC000FF8|32|
||DAPROM Component ID3 Register|DAPROM_COMPID3|32|H'FC000FFC|32|
||Mode reset control register|ICEREGMDRSTCTL|32|H'FC00F000|32|
||JTAG trace select register|ICEREGJTTRCSEL|32|H'FC00F004|32|
||Clock power control register|ICEREGCLKPWRCTRL|32|H'FC00F014|32|
||Lock access register|ICEREGLOCKACCES|32|H'FC00FFB0|32|
||2ndDAPROM Peripheral ID4 Register|2ndDAPROM_PERIPHID4|32|H'FC020FD0|32|
||2ndDAPROM Peripheral ID0 Register|2ndDAPROM_PERIPHID0|32|H'FC020FE0|32|
||2ndDAPROM Peripheral ID1Register|2ndDAPROM_PERIPHID1|32|H'FC020FE4|32|
||2ndDAPROM Peripheral ID2 Register|2ndDAPROM_PERIPHID2|32|H'FC020FE8|32|
||2ndDAPROM Peripheral ID3 Register|2ndDAPROM_PERIPHID3|32|H'FC020FEC|32|
||2ndDAPROM Component ID0 Register|2ndDAPROM_COMPID0|32|H'FC020FF0|32|
||2ndDAPROM Component ID1 Register|2ndDAPROM_COMPID1|32|H'FC020FF4|32|
||2ndDAPROM Component ID2 Register|2ndDAPROM_COMPID2|32|H'FC020FF8|32|
||2ndDAPROM Component ID3 Register|2ndDAPROM_COMPID3|32|H'FC020FFC|32|
||CPU-ETF RAM Size Register|CPU_ETF_RSZ|32|H'FC021004|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Debugger interface|CPU-ETF Status Register|CPU_ETF_STS|32|H'FC02100C|32|
||CPU-ETF RAM Read Data Register|CPU_ETF_RRD|32|H'FC021010|32|
||CPU-ETF RAM Read Pointer Register|CPU_ETF_RRP|32|H'FC021014|32|
||CPU-ETF RAM Write Pointer Register|CPU_ETF_RWP|32|H'FC021018|32|
||CPU-ETF Trigger Counter Register|CPU_ETF_TRG|32|H'FC02101C|32|
||CPU-ETF Control Register|CPU_ETF_CTL|32|H'FC021020|32|
||CPU-ETF RAM Write Data Register|CPU_ETF_RWD|32|H'FC021024|32|
||CPU-ETF Mode Register|CPU_ETF_MODE|32|H'FC021028|32|
||CPU-ETF Latched Buffer Fill Level Register|CPU_ETF_LBUFLEVEL|32|H'FC02102C|32|
||CPU-ETF Current Buffer Fill Level Register|CPU_ETF_CBUFLEVEL|32|H'FC021030|32|
||CPU-ETF Buffer Level Water Mark Register|CPU_ETF_BUFWM|32|H'FC021034|32|
||CPU-ETF RAM Read Pointer High Register|CPU_ETF_RRPHI|32|H'FC021038|32|
||CPU-ETF RAM Write Pointer High Register|CPU_ETF_RWPHI|32|H'FC02103C|32|
||CPU-ETF Formatter and Flush Status Register|CPU_ETF_FFSR|32|H'FC021300|32|
||CPU-ETF Formatter and Flush Control Register|CPU_ETF_FFCR|32|H'FC021304|32|
||CPU-ETF Periodic Synchronization Counter Register|CPU_ETF_PSCR|32|H'FC021308|32|
||CPU-ETF Claim Tag Set Register|CPU_ETF_CLAIMSET|32|H'FC021FA0|32|
||CPU-ETF Claim Tag Clear Register|CPU_ETF_CLAIMCLR|32|H'FC021FA4|32|
||CPU-ETF Lock Access Register|CPU_ETF_LAR|32|H'FC021FB0|32|
||CPU-ETF Lock Status Register|CPU_ETF_LSR|32|H'FC021FB4|32|
||CPU-ETF Authentication Status Register|CPU_ETF_AUTHSTATUS|32|H'FC021FB8|32|
||CPU-ETF Device Configuration Register|CPU_ETF_DEVID|32|H'FC021FC8|32|
||CPU-ETF Device Type Identifier Register|CPU_ETF_DEVTYPE|32|H'FC021FCC|32|
||CPU-ETF Peripheral ID4 Register|CPU_ETF_PERIPHID4|32|H'FC021FD0|32|
||CPU-ETF Peripheral ID0 Register|CPU_ETF_PERIPHID0|32|H'FC021FE0|32|
||CPU-ETF Peripheral ID1 Register|CPU_ETF_PERIPHID1|32|H'FC021FE4|32|
||CPU-ETF Peripheral ID2 Register|CPU_ETF_PERIPHID2|32|H'FC021FE8|32|
||CPU-ETF Peripheral ID3 Register|CPU_ETF_PERIPHID3|32|H'FC021FEC|32|
||CPU-ETF Component ID0 Register|CPU_ETF_COMPID0|32|H'FC021FF0|32|
||CPU-ETF Component ID1 Register|CPU_ETF_COMPID1|32|H'FC021FF4|32|
||CPU-ETF Component ID2 Register|CPU_ETF_COMPID2|32|H'FC021FF8|32|
||CPU-ETF Component ID3 Register|CPU_ETF_COMPID3|32|H'FC021FFC|32|
||CPU-CTICS CTI Control Register|CPU_CTICS_CTICONTROL|32|H'FC022000|32|
||CPU-CTICS CTI Interrupt Acknowledge Register|CPU_CTICS_CTIINTACK|32|H'FC022010|32|
||CPU-CTICS CTI Application Trigger Set Register|CPU_CTICS_CTIAPPSET|32|H'FC022014|32|
||CPU-CTICS CTI Application Trigger Clear Register|CPU_CTICS_CTIAPPCLEAR|32|H'FC022018|32|
||CPU-CTICS CTI Application Pulse Register|CPU_CTICS_CTIAPPPULSE|32|H'FC02201C|32|
||CPU-CTICS CTI Trigger to Channel Enable Register0|CPU_CTICS_CTIINEN0|32|H'FC022020|32|
||CPU-CTICS CTI Trigger to Channel Enable Register1|CPU_CTICS_CTIINEN1|32|H'FC022024|32|
||CPU-CTICS CTI Trigger to Channel Enable Register2|CPU_CTICS_CTIINEN2|32|H'FC022028|32|
||CPU-CTICS CTI Trigger to Channel Enable Register3|CPU_CTICS_CTIINEN3|32|H'FC02202C|32|
||CPU-CTICS CTI Trigger to Channel Enable Register4|CPU_CTICS_CTIINEN4|32|H'FC022030|32|
||CPU-CTICS CTI Trigger to Channel Enable Register5|CPU_CTICS_CTIINEN5|32|H'FC022034|32|
||CPU-CTICS CTI Trigger to Channel Enable Register6|CPU_CTICS_CTIINEN6|32|H'FC022038|32|
||CPU-CTICS CTI Trigger to Channel Enable Register7|CPU_CTICS_CTIINEN7|32|H'FC02203C|32|
||CPU-CTICS CTI Channel to Trigger Enable Register0|CPU_CTICS_CTIOUTEN0|32|H'FC0220A0|32|
||CPU-CTICS CTI Channel to Trigger Enable Register1|CPU_CTICS_CTIOUTEN1|32|H'FC0220A4|32|
||CPU-CTICS CTI Channel to Trigger Enable Register2|CPU_CTICS_CTIOUTEN2|32|H'FC0220A8|32|
||CPU-CTICS CTI Channel to Trigger Enable Register3|CPU_CTICS_CTIOUTEN3|32|H'FC0220AC|32|
||CPU-CTICS CTI Channel to Trigger Enable Register4|CPU_CTICS_CTIOUTEN4|32|H'FC0220B0|32|
||CPU-CTICS CTI Channel to Trigger Enable Register5|CPU_CTICS_CTIOUTEN5|32|H'FC0220B4|32|
||CPU-CTICS CTI Channel to Trigger Enable Register6|CPU_CTICS_CTIOUTEN6|32|H'FC0220B8|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Debugger interface|CPU-CTICS CTI Channel to Trigger Enable Register7|CPU_CTICS_CTIOUTEN7|32|H'FC0220BC|32|
||CPU-CTICS CTI Trigger In Status Register|CPU_CTICS_<br>CTITRIGINSTATUS|32|H'FC022130|32|
||CPU-CTICS CTI Trigger Out Status Register|CPU_CTICS_<br>CTITRIGOUTSTATUS|32|H'FC022134|32|
||CPU-CTICS CTI Channel In Status Register|CPU_CTICS_<br>CTICHINSTATUS|32|H'FC022138|32|
||CPU-CTICS CTI Channel Out Status Register|CPU_CTICS_<br>CTICHOUTSTATUS|32|H'FC02213C|32|
||CPU-CTICS Enable CTI Channel Gate Register|CPU_CTICS_CTIGATE|32|H'FC022140|32|
||CPU-CTICS External Multiplexor Control Register|CPU_CTICS_ASICCTL|32|H'FC022144|32|
||CPU-CTICS Claim Tag Set Register|CPU_CTICS_CLAIMSET|32|H'FC022FA0|32|
||CPU-CTICS Claim Tag Clear Register|CPU_CTICS_CLAIMCLR|32|H'FC022FA4|32|
||CPU-CTICS Lock Access Register|CPU_CTICS_LAR|32|H'FC022FB0|32|
||CPU-CTICS Lock Status Register|CPU_CTICS_LSR|32|H'FC022FB4|32|
||CPU-CTICS Authentication Status Register|CPU_CTICS_AUTHSTATUS|32|H'FC022FB8|32|
||CPU-CTICS Device Configuration Register|CPU_CTICS_DEVID|32|H'FC022FC8|32|
||CPU-CTICS Device Type Identifier Register|CPU_CTICS_DEVTYPE|32|H'FC022FCC|32|
||CPU-CTICS Peripheral ID4 Register|CPU_CTICS_PERIPHID4|32|H'FC022FD0|32|
||CPU-CTICS Peripheral ID0 Register|CPU_CTICS_PERIPHID0|32|H'FC022FE0|32|
||CPU-CTICS Peripheral ID1 Register|CPU_CTICS_PERIPHID1|32|H'FC022FE4|32|
||CPU-CTICS Peripheral ID2 Register|CPU_CTICS_PERIPHID2|32|H'FC022FE8|32|
||CPU-CTICS Peripheral ID3 Register|CPU_CTICS_PERIPHID3|32|H'FC022FEC|32|
||CPU-CTICS Component ID0 Register|CPU_CTICS_COMPID0|32|H'FC022FF0|32|
||CPU-CTICS Component ID1 Register|CPU_CTICS_COMPID1|32|H'FC022FF4|32|
||CPU-CTICS Component ID2 Register|CPU_CTICS_COMPID2|32|H'FC022FF8|32|
||CPU-CTICS Component ID3 Register|CPU_CTICS_COMPID3|32|H'FC022FFC|32|
||CPU-TPIU Supported Port Size Register|CPU_TPIU_Supported port<br>sizes|32|H'FC023000|32|
||CPU-TPIU Current Port Size Register|CPU_TPIU_Current port size|32|H'FC023004|32|
||CPU-TPIU Trigger Modes Register|CPU_TPIU_Supported trigger<br>modes|32|H'FC023100|32|
||CPU-TPIU Trigger Counter Register|CPU_TPIU_Trigger counter<br>value|32|H'FC023104|32|
||CPU-TPIU Trigger Multiplier Register|CPU_TPIU_Trigger multiplier|32|H'FC023108|32|
||CPU-TPIU Supported Test Patterns/Modes Register|CPU_TPIU_Supported test<br>pattern/modes|32|H'FC023200|32|
||CPU-TPIU Current Test Patterns/Modes Register|CPU_TPIU_Current test<br>pattern/mode|32|H'FC023204|32|
||CPU-TPIU TPIU Test Pattern Repeat  Register|CPU_TPIU_Test pattern repeat<br>counter|32|H'FC023208|32|
||CPU-TPIU Formatter and Flush Status Register|CPU_TPIU_Formatter and<br>flush status|32|H'FC023300|32|
||CPU-TPIU Formatter and Flush Control Register|CPU_TPIU_Formatter and<br>flush control|32|H'FC023304|32|
||CPU-TPIU Formatter Synchronization counter Register|CPU_TPIU_Formatter<br>synchronization counter|32|H'FC023308|32|
||CPU-TPIU Claim Tag Set Register|CPU_TPIU_CLAIMSET|32|H'FC023FA0|32|
||CPU-TPIU Claim Tag Clear Register|CPU_TPIU_CLAIMCLR|32|H'FC023FA4|32|
||CPU-TPIU Lock Access Register|CPU_TPIU_LAR|32|H'FC023FB0|32|
||CPU-TPIU Lock Status Register|CPU_TPIU_LSR|32|H'FC023FB4|32|
||CPU-TPIU Authentication Status Register|CPU_TPIU_AUTHSTATUS|32|H'FC023FB8|32|
||CPU-TPIU Device Configuration Register|CPU_TPIU_DEVID|32|H'FC023FC8|32|
||CPU-TPIU Device Type Identifier Register|CPU_TPIU_DEVTYPE|32|H'FC023FCC|32|
||CPU-TPIU Peripheral ID4 Register|CPU_TPIU_PERIPHID4|32|H'FC023FD0|32|
||CPU-TPIU Peripheral ID0 Register|CPU_TPIU_PERIPHID0|32|H'FC023FE0|32|
||CPU-TPIU Peripheral ID1 Register|CPU_TPIU_PERIPHID1|32|H'FC023FE4|32|
||CPU-TPIU Peripheral ID2 Register|CPU_TPIU_PERIPHID2|32|H'FC023FE8|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Debugger interface|CPU-TPIU Peripheral ID3 Register|CPU_TPIU_PERIPHID3|32|H'FC023FEC|32|
||CPU-TPIU Component ID0 Register|CPU_TPIU_COMPID0|32|H'FC023FF0|32|
||CPU-TPIU Component ID1 Register|CPU_TPIU_COMPID1|32|H'FC023FF4|32|
||CPU-TPIU Component ID2 Register|CPU_TPIU_COMPID2|32|H'FC023FF8|32|
||CPU-TPIU Component ID3 Register|CPU_TPIU_COMPID3|32|H'FC023FFC|32|
||CPU-TraceFunnel CSTF Control Register|CPU_TraceFunnel_FUNCTL|32|H'FC024000|32|
||CPU-TraceFunnel CSTF Priority Control Register|CPU_TraceFunnel_PRICTL|32|H'FC024004|32|
||CPU-TraceFunnel Claim Tag Set Register|CPU_TraceFunnel_CLAIMSET|32|H'FC024FA0|32|
||CPU-TraceFunnel Claim Tag Clear Register|CPU_TraceFunnel_CLAIMCLR|32|H'FC024FA4|32|
||CPU-TraceFunnel Lock Access Register|CPU_TraceFunnel_LAR|32|H'FC024FB0|32|
||CPU-TraceFunnel Lock Status Register|CPU_TraceFunnel_LSR|32|H'FC024FB4|32|
||CPU-TraceFunnel Authentication Status Register|CPU_TraceFunnel_<br>AUTHSTATUS|32|H'FC024FB8|32|
||CPU-TraceFunnel Device Configuration Register|CPU_TraceFunnel_DEVID|32|H'FC024FC8|32|
||CPU-TraceFunnel Device Type Identifier Register|CPU_TraceFunnel_DEVTYPE|32|H'FC024FCC|32|
||CPU-TraceFunnel Peripheral ID4 Register|CPU_TraceFunnel_PERIPHID<br>4|32|H'FC024FD0|32|
||CPU-TraceFunnel Peripheral ID0 Register|CPU_TraceFunnel_PERIPHID<br>0|32|H'FC024FE0|32|
||CPU-TraceFunnel Peripheral ID1 Register|CPU_TraceFunnel_PERIPHID<br>1|32|H'FC024FE4|32|
||CPU-TraceFunnel Peripheral ID2 Register|CPU_TraceFunnel_PERIPHID<br>2|32|H'FC024FE8|32|
||CPU-TraceFunnel Peripheral ID3 Register|CPU_TraceFunnel_PERIPHID<br>3|32|H'FC024FEC|32|
||CPU-TraceFunnel Component ID0 Register|CPU_TraceFunnel_COMPID0|32|H'FC024FF0|32|
||CPU-TraceFunnel Component ID1 Register|CPU_TraceFunnel_COMPID1|32|H'FC024FF4|32|
||CPU-TraceFunnel Component ID2 Register|CPU_TraceFunnel_COMPID2|32|H'FC024FF8|32|
||CPU-TraceFunnel Component ID3 Register|CPU_TraceFunnel_COMPID3|32|H'FC024FFC|32|
||CA9-DBG Debug ID Register|CA9_DBG_DBGDIDR|32|H'FC030000|32|
||CA9-DBG Watchpoint Fault Address Register|CA9_DBG_DBGWFAR|32|H'FC030018|32|
||CA9-DBG Vector Catch Register|CA9_DBG_DBGVCR|32|H'FC03001C|32|
||CA9-DBG Host to Target Data Transfer Register|CA9_DBG_DBGDTRRXext|32|H'FC030080|32|
||CA9-DBG Instruction Transfer/Program Counter Sampling<br>Register|CA9_DBG_DBGITR/<br>DBGPCSR|32|H'FC030084|32|
||CA9-DBG Debug Status and Control Register|CA9_DBG_DBGDSCRext|32|H'FC030088|32|
||CA9-DBG Target to Host Data Transfer Register|CA9_DBG_DBGDTRTXext|32|H'FC03008C|32|
||CA9-DBG Debug Run Control Register|CA9_DBG_DBGDRCR|32|H'FC030090|32|
||CA9-DBG Breakpoint Value Register 0|CA9_DBG_DBGBVR0|32|H'FC030100|32|
||CA9-DBG Breakpoint Value Register 1|CA9_DBG_DBGBVR1|32|H'FC030104|32|
||CA9-DBG Breakpoint Value Register 2|CA9_DBG_DBGBVR2|32|H'FC030108|32|
||CA9-DBG Breakpoint Value Register 3|CA9_DBG_DBGBVR3|32|H'FC03010C|32|
||CA9-DBG Breakpoint Value Register 4|CA9_DBG_DBGBVR4|32|H'FC030110|32|
||CA9-DBG Breakpoint Value Register 5|CA9_DBG_DBGBVR5|32|H'FC030114|32|
||CA9-DBG Breakpoint Control Register 0|CA9_DBG_DBGBCR0|32|H'FC030140|32|
||CA9-DBG Breakpoint Control Register 1|CA9_DBG_DBGBCR1|32|H'FC030144|32|
||CA9-DBG Breakpoint Control Register 2|CA9_DBG_DBGBCR2|32|H'FC030148|32|
||CA9-DBG Breakpoint Control Register 3|CA9_DBG_DBGBCR3|32|H'FC03014C|32|
||CA9-DBG Breakpoint Control Register 4|CA9_DBG_DBGBCR4|32|H'FC030150|32|
||CA9-DBG Breakpoint Control Register 5|CA9_DBG_DBGBCR5|32|H'FC030154|32|
||CA9-DBG Watchpoint Value Register 0|CA9_DBG_DBGWVR0|32|H'FC030180|32|
||CA9-DBG Watchpoint Value Register 1|CA9_DBG_DBGWVR1|32|H'FC030184|32|
||CA9-DBG Watchpoint Value Register 2|CA9_DBG_DBGWVR2|32|H'FC030188|32|
||CA9-DBG Watchpoint Value Register 3|CA9_DBG_DBGWVR3|32|H'FC03018C|32|
||CA9-DBG Watchpoint Control Register 0|CA9_DBG_DBGWCR0|32|H'FC0301C0|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Debugger interface|CA9-DBG Watchpoint Control Register 1|CA9_DBG_DBGWCR1|32|H'FC0301C4|32|
||CA9-DBG Watchpoint Control Register 2|CA9_DBG_DBGWCR2|32|H'FC0301C8|32|
||CA9-DBG Watchpoint Control Register 3|CA9_DBG_DBGWCR3|32|H'FC0301CC|32|
||CA9-DBG Main ID Register|CA9_DBG_MIDR|32|H'FC030D00|32|
||CA9-DBG Cache Type Register|CA9_DBG_CTR|32|H'FC030D04|32|
||CA9-DBG TLB Type Register|CA9_DBG_TLBTR|32|H'FC030D0C|32|
||CA9-DBG Multiprocessor Affinity Register|CA9_DBG_MPIDR|32|H'FC030D10|32|
||CA9-DBG Revision ID register|CA9_DBG_REVIDR|32|H'FC030D14|32|
||CA9-DBG Processor Feature Register 0|CA9_DBG_ID_PFR0|32|H'FC030D20|32|
||CA9-DBG Processor Feature Register 1|CA9_DBG_ID_PFR1|32|H'FC030D24|32|
||CA9-DBG Debug Feature Register 0|CA9_DBG_ID_DFR0|32|H'FC030D28|32|
||CA9-DBG Memory Model Feature Register 0|CA9_DBG_ID_MMFR0|32|H'FC030D30|32|
||CA9-DBG Memory Model Feature Register 1|CA9_DBG_ID_MMFR1|32|H'FC030D34|32|
||CA9-DBG Memory Model Feature Register 2|CA9_DBG_ID_MMFR2|32|H'FC030D38|32|
||CA9-DBG Memory Model Feature Register 3|CA9_DBG_ID_MMFR3|32|H'FC030D3C|32|
||CA9-DBG Instruction Set Attribute Register 0|CA9_DBG_ID_ISAR0|32|H'FC030D40|32|
||CA9-DBG Instruction Set Attribute Register 1|CA9_DBG_ID_ISAR1|32|H'FC030D44|32|
||CA9-DBG Instruction Set Attribute Register 2|CA9_DBG_ID_ISAR2|32|H'FC030D48|32|
||CA9-DBG Instruction Set Attribute Register 3|CA9_DBG_ID_ISAR3|32|H'FC030D4C|32|
||CA9-DBG Instruction Set Attribute Register 4|CA9_DBG_ID_ISAR4|32|H'FC030D50|32|
||CA9-DBG Claim Tag Set Register|CA9_DBG_CLAIMSET|32|H'FC030FA0|32|
||CA9-DBG Claim Tag Clear Register|CA9_DBG_CLAIMCLR|32|H'FC030FA4|32|
||CA9-DBG Lock Access Register|CA9_DBG_LAR|32|H'FC030FB0|32|
||CA9-DBG Lock Status Register|CA9_DBG_LSR|32|H'FC030FB4|32|
||CA9-DBG Authentication Status Register|CA9_DBG_AUTHSTATUS|32|H'FC030FB8|32|
||CA9-DBG Device Configuration Register|CA9_DBG_DEVID|32|H'FC030FC8|32|
||CA9-DBG Device Type Identifier Register|CA9_DBG_DEVTYPE|32|H'FC030FCC|32|
||CA9-DBG Peripheral ID4 Register|CA9_DBG_PERIPHID4|32|H'FC030FD0|32|
||CA9-DBG Peripheral ID0 Register|CA9_DBG_PERIPHID0|32|H'FC030FE0|32|
||CA9-DBG Peripheral ID1 Register|CA9_DBG_PERIPHID1|32|H'FC030FE4|32|
||CA9-DBG Peripheral ID2 Register|CA9_DBG_PERIPHID2|32|H'FC030FE8|32|
||CA9-DBG Peripheral ID3 Register|CA9_DBG_PERIPHID3|32|H'FC030FEC|32|
||CA9-DBG Component ID0 Register|CA9_DBG_COMPID0|32|H'FC030FF0|32|
||CA9-DBG Component ID1 Register|CA9_DBG_COMPID1|32|H'FC030FF4|32|
||CA9-DBG Component ID2 Register|CA9_DBG_COMPID2|32|H'FC030FF8|32|
||CA9-DBG Component ID3 Register|CA9_DBG_COMPID3|32|H'FC030FFC|32|
||CA9-PMU Event Count Register 0|CA9_PMU_PMXEVCNTR0|32|H'FC031000|32|
||CA9-PMU Event Count Register 1|CA9_PMU_PMXEVCNTR1|32|H'FC031004|32|
||CA9-PMU Event Count Register 2|CA9_PMU_PMXEVCNTR2|32|H'FC031008|32|
||CA9-PMU Event Count Register 3|CA9_PMU_PMXEVCNTR3|32|H'FC03100C|32|
||CA9-PMU Event Count Register 4|CA9_PMU_PMXEVCNTR4|32|H'FC031010|32|
||CA9-PMU Event Count Register 5|CA9_PMU_PMXEVCNTR5|32|H'FC031014|32|
||CA9-PMU Cycle Count Register|CA9_PMU_PMCCNTR|32|H'FC03107C|32|
||CA9-PMU Event Counter Selection Register 0|CA9_PMU_PMXEVTYPER0|32|H'FC031400|32|
||CA9-PMU Event Counter Selection Register 1|CA9_PMU_PMXEVTYPER1|32|H'FC031404|32|
||CA9-PMU Event Counter Selection Register 2|CA9_PMU_PMXEVTYPER2|32|H'FC031408|32|
||CA9-PMU Event Counter Selection Register 3|CA9_PMU_PMXEVTYPER3|32|H'FC03140C|32|
||CA9-PMU Event Counter Selection Register 4|CA9_PMU_PMXEVTYPER4|32|H'FC031410|32|
||CA9-PMU Event Counter Selection Register 5|CA9_PMU_PMXEVTYPER5|32|H'FC031414|32|
||CA9-PMU Count Enable Set Register|CA9_PMU_PMCNTENSET|32|H'FC031C00|32|
||CA9-PMU Count Enable Clear Register|CA9_PMU_PMCNTENCLR|32|H'FC031C20|32|
||CA9-PMU Interrupt Enable Set Register|CA9_PMU_PMINTENSET|32|H'FC031C40|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Debugger interface|CA9-PMU Interrupt Enable Clear Register|CA9_PMU_PMINTENCLR|32|H'FC031C60|32|
||CA9-PMU Overflow Flag Status Register|CA9_PMU_PMOVSR|32|H'FC031C80|32|
||CA9-PMU Software Increment Register|CA9_PMU_PMSWINC|32|H'FC031CA0|32|
||CA9-PMU Performance Monitor Control Register|CA9_PMU_PMCR|32|H'FC031E04|32|
||CA9-PMU User Enable Register|CA9_PMU_PMUSERENR|32|H'FC031E08|32|
||CA9-PMU Claim Tag Set Register|CA9_PMU_CLAIMSET|32|H'FC031FA0|32|
||CA9-PMU Claim Tag Clear Register|CA9_PMU_CLAIMCLR|32|H'FC031FA4|32|
||CA9-PMU Lock Access Register|CA9_PMU_LAR|32|H'FC031FB0|32|
||CA9-PMU Lock Status Register|CA9_PMU_LSR|32|H'FC031FB4|32|
||CA9-PMU Authentication Status Register|CA9_PMU_AUTHSTATUS|32|H'FC031FB8|32|
||CA9-PMU Device Configuration Register|CA9_PMU_DEVID|32|H'FC031FC8|32|
||CA9-PMU Device Type Identifier Register|CA9_PMU_DEVTYPE|32|H'FC031FCC|32|
||CA9-PMU Peripheral ID4 Register|CA9_PMU_PERIPHID4|32|H'FC031FD0|32|
||CA9-PMU Peripheral ID0 Register|CA9_PMU_PERIPHID0|32|H'FC031FE0|32|
||CA9-PMU Peripheral ID1 Register|CA9_PMU_PERIPHID1|32|H'FC031FE4|32|
||CA9-PMU Peripheral ID2 Register|CA9_PMU_PERIPHID2|32|H'FC031FE8|32|
||CA9-PMU Peripheral ID3 Register|CA9_PMU_PERIPHID3|32|H'FC031FEC|32|
||CA9-PMU Component ID0 Register|CA9_PMU_COMPID0|32|H'FC031FF0|32|
||CA9-PMU Component ID1 Register|CA9_PMU_COMPID1|32|H'FC031FF4|32|
||CA9-PMU Component ID2 Register|CA9_PMU_COMPID2|32|H'FC031FF8|32|
||CA9-PMU Component ID3 Register|CA9_PMU_COMPID3|32|H'FC031FFC|32|
||CA9-CTI CTI Control Register|CA9_CTI_CTICONTROL|32|H'FC038000|32|
||CA9-CTI CTI Interrupt Acknowledge Register|CA9_CTI_CTIINTACK|32|H'FC038010|32|
||CA9-CTI CTI Application Trigger Set Register|CA9_CTI_CTIAPPSET|32|H'FC038014|32|
||CA9-CTI CTI Application Trigger Clear Register|CA9_CTI_CTIAPPCLEAR|32|H'FC038018|32|
||CA9-CTI CTI Application Pulse Register|CA9_CTI_CTIAPPPULSE|32|H'FC03801C|32|
||CA9-CTI CTI Trigger to Channel Enable Register0|CA9_CTI_CTIINEN0|32|H'FC038020|32|
||CA9-CTI CTI Trigger to Channel Enable Register1|CA9_CTI_CTIINEN1|32|H'FC038024|32|
||CA9-CTI CTI Trigger to Channel Enable Register2|CA9_CTI_CTIINEN2|32|H'FC038028|32|
||CA9-CTI CTI Trigger to Channel Enable Register3|CA9_CTI_CTIINEN3|32|H'FC03802C|32|
||CA9-CTI CTI Trigger to Channel Enable Register4|CA9_CTI_CTIINEN4|32|H'FC038030|32|
||CA9-CTI CTI Trigger to Channel Enable Register5|CA9_CTI_CTIINEN5|32|H'FC038034|32|
||CA9-CTI CTI Trigger to Channel Enable Register6|CA9_CTI_CTIINEN6|32|H'FC038038|32|
||CA9-CTI CTI Trigger to Channel Enable Register7|CA9_CTI_CTIINEN7|32|H'FC03803C|32|
||CA9-CTI CTI Channel to Trigger Enable Register0|CA9_CTI_CTIOUTEN0|32|H'FC0380A0|32|
||CA9-CTI CTI Channel to Trigger Enable Register1|CA9_CTI_CTIOUTEN1|32|H'FC0380A4|32|
||CA9-CTI CTI Channel to Trigger Enable Register2|CA9_CTI_CTIOUTEN2|32|H'FC0380A8|32|
||CA9-CTI CTI Channel to Trigger Enable Register3|CA9_CTI_CTIOUTEN3|32|H'FC0380AC|32|
||CA9-CTI CTI Channel to Trigger Enable Register4|CA9_CTI_CTIOUTEN4|32|H'FC0380B0|32|
||CA9-CTI CTI Channel to Trigger Enable Register5|CA9_CTI_CTIOUTEN5|32|H'FC0380B4|32|
||CA9-CTI CTI Channel to Trigger Enable Register6|CA9_CTI_CTIOUTEN6|32|H'FC0380B8|32|
||CA9-CTI CTI Channel to Trigger Enable Register7|CA9_CTI_CTIOUTEN7|32|H'FC0380BC|32|
||CA9-CTI CTI Trigger In Status Register|CA9_CTI_CTITRIGINSTATUS|32|H'FC038130|32|
||CA9-CTI CTI Trigger Out Status Register|CA9_CTI_<br>CTITRIGOUTSTATUS|32|H'FC038134|32|
||CA9-CTI CTI Channel In Status Register|CA9_CTI_CTICHINSTATUS|32|H'FC038138|32|
||CA9-CTI CTI Channel Out Status Register|CA9_CTI_CTICHOUTSTATUS|32|H'FC03813C|32|
||CA9-CTI Enable CTI Channel Gate Register|CA9_CTI_CTIGATE|32|H'FC038140|32|
||CA9-CTI External Multiplexor Control Register|CA9_CTI_ASICCTL|32|H'FC038144|32|
||CA9-CTI Claim Tag Set Register|CA9_CTI_CLAIMSET|32|H'FC038FA0|32|
||CA9-CTI Claim Tag Clear Register|CA9_CTI_CLAIMCLR|32|H'FC038FA4|32|
||CA9-CTI Lock Access Register|CA9_CTI_LAR|32|H'FC038FB0|32|
||CA9-CTI Lock Status Register|CA9_CTI_LSR|32|H'FC038FB4|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Debugger interface|CA9-CTI Authentication Status Register|CA9_CTI_AUTHSTATUS|32|H'FC038FB8|32|
||CA9-CTI Device Configuration Register|CA9_CTI_DEVID|32|H'FC038FC8|32|
||CA9-CTI Device Type Identifier Register|CA9_CTI_DEVTYPE|32|H'FC038FCC|32|
||CA9-CTI Peripheral ID4 Register|CA9_CTI_PERIPHID4|32|H'FC038FD0|32|
||CA9-CTI Peripheral ID0 Register|CA9_CTI_PERIPHID0|32|H'FC038FE0|32|
||CA9-CTI Peripheral ID1Register|CA9_CTI_PERIPHID1|32|H'FC038FE4|32|
||CA9-CTI Peripheral ID2 Register|CA9_CTI_PERIPHID2|32|H'FC038FE8|32|
||CA9-CTI Peripheral ID3 Register|CA9_CTI_PERIPHID3|32|H'FC038FEC|32|
||CA9-CTI Component ID0 Register|CA9_CTI_COMPID0|32|H'FC038FF0|32|
||CA9-CTI Component ID1 Register|CA9_CTI_COMPID1|32|H'FC038FF4|32|
||CA9-CTI Component ID2 Register|CA9_CTI_COMPID2|32|H'FC038FF8|32|
||CA9-CTI Component ID3 Register|CA9_CTI_COMPID3|32|H'FC038FFC|32|
||PTM-A9 Main Control Register|PTM_A9_ETMCR|32|H'FC03C000|32|
||PTM-A9 Configuration Code Register|PTM_A9_ETMCCR|32|H'FC03C004|32|
||PTM-A9 Trigger Event Register|PTM_A9_ETMTRIGGER|32|H'FC03C008|32|
||PTM-A9 Status Register|PTM_A9_ETMSR|32|H'FC03C010|32|
||PTM-A9 System Configuration Register|PTM_A9_ETMSCR|32|H'FC03C014|32|
||PTM-A9 TraceEnable Start/Stop Control Register|PTM_A9_ETMTSSCR|32|H'FC03C018|32|
||PTM-A9 TraceEnable Event Register|PTM_A9_ETMTEEVR|32|H'FC03C020|32|
||PTM-A9 TraceEnable Control Register 1|PTM_A9_ETMTECR1|32|H'FC03C024|32|
||PTM-A9 Address Comparator Value Register 1|PTM_A9_ETMACVR1|32|H'FC03C040|32|
||PTM-A9 Address Comparator Value Register 2|PTM_A9_ETMACVR2|32|H'FC03C044|32|
||PTM-A9 Address Comparator Value Register 3|PTM_A9_ETMACVR3|32|H'FC03C048|32|
||PTM-A9 Address Comparator Value Register 4|PTM_A9_ETMACVR4|32|H'FC03C04C|32|
||PTM-A9 Address Comparator Value Register 5|PTM_A9_ETMACVR5|32|H'FC03C050|32|
||PTM-A9 Address Comparator Value Register 6|PTM_A9_ETMACVR6|32|H'FC03C054|32|
||PTM-A9 Address Comparator Value Register 7|PTM_A9_ETMACVR7|32|H'FC03C058|32|
||PTM-A9 Address Comparator Value Register 8|PTM_A9_ETMACVR8|32|H'FC03C05C|32|
||PTM-A9 Address Comparator Access Type Register 1|PTM_A9_ETMACTR1|32|H'FC03C080|32|
||PTM-A9 Address Comparator Access Type Register 2|PTM_A9_ETMACTR2|32|H'FC03C084|32|
||PTM-A9 Address Comparator Access Type Register 3|PTM_A9_ETMACTR3|32|H'FC03C088|32|
||PTM-A9 Address Comparator Access Type Register 4|PTM_A9_ETMACTR4|32|H'FC03C08C|32|
||PTM-A9 Address Comparator Access Type Register 5|PTM_A9_ETMACTR5|32|H'FC03C090|32|
||PTM-A9 Address Comparator Access Type Register 6|PTM_A9_ETMACTR6|32|H'FC03C094|32|
||PTM-A9 Address Comparator Access Type Register 7|PTM_A9_ETMACTR7|32|H'FC03C098|32|
||PTM-A9 Address Comparator Access Type Register 8|PTM_A9_ETMACTR8|32|H'FC03C09C|32|
||PTM-A9 Counter Reload Value Register 1|PTM_A9_ETMCNTRLDVR1|32|H'FC03C140|32|
||PTM-A9 Counter Reload Value Register 2|PTM_A9_ETMCNTRLDVR2|32|H'FC03C144|32|
||PTM-A9 Counter Enable Event Register 1|PTM_A9_ETMCNTENR1|32|H'FC03C150|32|
||PTM-A9 Counter Enable Event Register 2|PTM_A9_ETMCNTENR2|32|H'FC03C154|32|
||PTM-A9 Counter Reload Event Register 1|PTM_A9_ETMCNTRLDEVR1|32|H'FC03C160|32|
||PTM-A9 Counter Reload Event Register 2|PTM_A9_ETMCNTRLDEVR2|32|H'FC03C164|32|
||PTM-A9 Counter Value Register 1|PTM_A9_ETMCNTVR1|32|H'FC03C170|32|
||PTM-A9 Counter Value Register 2|PTM_A9_ETMCNTVR2|32|H'FC03C174|32|
||PTM-A9 State 1 to State 2 Transition Event Register|PTM_A9_ETMSQ12EVR|32|H'FC03C180|32|
||PTM-A9 State 2 to State 1 Transition Event Register|PTM_A9_ETMSQ21EVR|32|H'FC03C184|32|
||PTM-A9 State 2 to State 3 Transition Event Register|PTM_A9_ETMSQ23EVR|32|H'FC03C188|32|
||PTM-A9 State 3 to State 1 Transition Event Register|PTM_A9_ETMSQ31EVR|32|H'FC03C18C|32|
||PTM-A9 State 3 to State 2 Transition Event Register|PTM_A9_ETMSQ32EVR|32|H'FC03C190|32|
||PTM-A9 State 1 to State 3 Transition Event Register|PTM_A9_ETMSQ13EVR|32|H'FC03C194|32|
||PTM-A9 Current Sequencer State Register|PTM_A9_ETMSQR|32|H'FC03C19C|32|
||PTM-A9 External Output Event Register 1|PTM_A9_ETMEXTOUTEVR1|32|H'FC03C1A0|32|

**Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Debugger interface|PTM-A9 External Output Event Register 2|PTM_A9_ETMEXTOUTEVR2|32|H'FC03C1A4|32|
||PTM-A9 Context ID Comparator Value 1 Register|PTM_A9_ETMCIDCVR1|32|H'FC03C1B0|32|
||PTM-A9 Context ID Comparator Mask Register|PTM_A9_ETMCIDCMR|32|H'FC03C1BC|32|
||PTM-A9 Synchronization Frequency Register|PTM_A9_ETMSYNCFR|32|H'FC03C1E0|32|
||PTM-A9 ID Register|PTM_A9_ETMIDR|32|H'FC03C1E4|32|
||PTM-A9 Configuration Code Extension Register|PTM_A9_ETMCCER|32|H'FC03C1E8|32|
||PTM-A9 Extended External Input Selection Register|PTM_A9_ETMEXTINSELR|32|H'FC03C1EC|32|
||PTM-A9 Timestamp Event Register|PTM_A9_ETMTSEVR|32|H'FC03C1F8|32|
||PTM-A9 Auxiliary Control Register|PTM_A9_ETMAUXCR|32|H'FC03C1FC|32|
||PTM-A9 CoreSight Trace ID Register|PTM_A9_ETMTRACEIDR|32|H'FC03C200|32|
||PTM-A9 OS Lock Status Register|PTM_A9_OSLSR|32|H'FC03C304|32|
||PTM-A9 Claim Tag Set Register|PTM_A9_CLAIMSET|32|H'FC031FA0|32|
||PTM-A9 Claim Tag Clear Register|PTM_A9_CLAIMCLR|32|H'FC031FA4|32|
||PTM-A9 Lock Access Register|PTM_A9_LAR|32|H'FC031FB0|32|
||PTM-A9 Lock Status Register|PTM_A9_LSR|32|H'FC031FB4|32|
||PTM-A9 Authentication Status Register|PTM_A9_AUTHSTATUS|32|H'FC031FB8|32|
||PTM-A9 Device Type Identifier Register|PTM_A9_DEVTYPE|32|H'FC031FCC|32|
||PTM-A9 Peripheral ID4 Register|PTM_A9_PERIPHID4|32|H'FC031FD0|32|
||PTM-A9 Peripheral ID0 Register|PTM_A9_PERIPHID0|32|H'FC031FE0|32|
||PTM-A9 Peripheral ID1 Register|PTM_A9_PERIPHID1|32|H'FC031FE4|32|
||PTM-A9 Peripheral ID2 Register|PTM_A9_PERIPHID2|32|H'FC031FE8|32|
||PTM-A9 Peripheral ID3 Register|PTM_A9_PERIPHID3|32|H'FC031FEC|32|
||PTM-A9 Component ID0 Register|PTM_A9_COMPID0|32|H'FC031FF0|32|
||PTM-A9 Component ID1 Register|PTM_A9_COMPID1|32|H'FC031FF4|32|
||PTM-A9 Component ID2 Register|PTM_A9_COMPID2|32|H'FC031FF8|32|
||PTM-A9 Component ID3 Register|PTM_A9_COMPID3|32|H'FC031FFC|32|
|JPEG codec unit*2|JPEG code mode register|JCMOD|8|H'E8017000|8|
||JPEG code command register|JCCMD|8|H'E8017001|8|
||JPEG code quantization table number register|JCQTN|8|H'E8017003|8|
||JPEG code Huffman table number register|JCHTN|8|H'E8017004|8|
||JPEG code DRI upper register|JCDRIU|8|H'E8017005|8|
||JPEG code DRI lower register|JCDRID|8|H'E8017006|8|
||JPEG code vertical size upper register|JCVSZU|8|H'E8017007|8|
||JPEG code vertical size lower register|JCVSZD|8|H'E8017008|8|
||JPEG code horizontal size upper register|JCHSZU|8|H'E8017009|8|
||JPEG code horizontal size lower register|JCHSZD|8|H'E801700A|8|
||JPEG code data count upper register|JCDTCU|8|H'E801700B|8|
||JPEG code data count middle register|JCDTCM|8|H'E801700C|8|
||JPEG code data count lower register|JCDTCD|8|H'E801700D|8|
||JPEG interrupt enable register 0|JINTE0|8|H'E801700E|8|
||JPEG interrupt status register 0|JINTS0|8|H'E801700F|8|
||JPEG code decode error register|JCDERR|8|H'E8017010|8|
||JPEG code reset register|JCRST|8|H'E8017011|8|
||JPEG interface compression control register|JIFECNT|32|H'E8017040|32|
||JPEG interface compression source address register|JIFESA|32|H'E8017044|32|
||JPEG interface compression line offset register|JIFESOFST|32|H'E8017048|32|
||JPEG interface compression destination address register|JIFEDA|32|H'E801704C|32|
||JPEG interface compression source line count register|JIFESLC|32|H'E8017050|32|
||JPEG interface compression destination register|JIFEDDC|32|H'E8017054|32|
||JPEG interface decompression control register|JIFDCNT|32|H'E8017058|32|
||JPEG interface decompression source address register|JIFDSA|32|H'E801705C|32|
||JPEG interface decompression destination offset register|JIFDDOFST|32|H'E8017060|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|JPEG codec unit*2|JPEG interface decompression destination address register|JIFDDA|32|H'E8017064|32|
||JPEG interface decompression source count register|JIFDSDC|32|H'E8017068|32|
||JPEG interface decompression destination line count register|JIFDDLC|32|H'E801706C|32|
||JPEG interface decompression α setting register|JIFDADT|32|H'E8017070|32|
||JPEG interrupt enable register 1|JINTE1|32|H'E801708C|32|
||JPEG interrupt status register 1|JINTS1|32|H'E8017090|32|
||JPEG input image data CbCr range setting register|JIFESVSZ|32|H'E8017094|32|
||JPEG output image data CbCr range setting register|JIFESHSZ|32|H'E8017098|32|
||JPEG code quantization table 0 register|JCQTBL0|512|H'E8017100<br>to<br>H'E801713F|8|
||JPEG code quantization table 1 register|JCQTBL1|512|H'E8017140<br>to<br>H'E801717F|8|
||JPEG code quantization table 2 register|JCQTBL2|512|H'E8017180<br>to<br>H'E80171BF|8|
||JPEG code quantization table 3 register|JCQTBL3|512|H'E80171C0<br>to<br>H'E80171FF|8|
||JPEG code Huffman table DC0 register|JCHTBD0|224|H'E8017200<br>to<br>H'E801721B|8|
||JPEG code Huffman table AC0 register|JCHTBA0|1416|H'E8017220<br>to<br>H'E80172D1|8|
||JPEG code Huffman table DC1 register|JCHTBD1|224|H'E8017300<br>to<br>H'E801731B|8|
||JPEG code Huffman table AC1 register|JCHTBA1|1416|H'E8017320<br>to<br>H'E80173D1|8|
|EthernetAVB*2|AVB-DMAC mode register|CCC|32|H'E8215000|32|
||Descriptor base address table register|DBAT|32|H'E8215004|32|
||Descriptor base address load request register|DLR|32|H'E8215008|32|
||AVB-DMAC status register|CSR|32|H'E821500C|32|
||Current descriptor address register 0|CDAR0|32|H'E8215010|32|
||Current descriptor address register 1|CDAR1|32|H'E8215014|32|
||Current descriptor address register 2|CDAR2|32|H'E8215018|32|
||Current descriptor address register 3|CDAR3|32|H'E821501C|32|
||Current descriptor address register 4|CDAR4|32|H'E8215020|32|
||Current descriptor address register 5|CDAR5|32|H'E8215024|32|
||Current descriptor address register 6|CDAR6|32|H'E8215028|32|
||Current descriptor address register 7|CDAR7|32|H'E821502C|32|
||Current descriptor address register 8|CDAR8|32|H'E8215030|32|
||Current descriptor address register 9|CDAR9|32|H'E8215034|32|
||Current descriptor address register 10|CDAR10|32|H'E8215038|32|
||Current descriptor address register 11|CDAR11|32|H'E821503C|32|
||Current descriptor address register 12|CDAR12|32|H'E8215040|32|
||Current descriptor address register 13|CDAR13|32|H'E8215044|32|
||Current descriptor address register 14|CDAR14|32|H'E8215048|32|
||Current descriptor address register 15|CDAR15|32|H'E821504C|32|
||Current descriptor address register 16|CDAR16|32|H'E8215050|32|
||Current descriptor address register 17|CDAR17|32|H'E8215054|32|
||Current descriptor address register 18|CDAR18|32|H'E8215058|32|
||Current descriptor address register 19|CDAR19|32|H'E821505C|32|
||Current descriptor address register 20|CDAR20|32|H'E8215060|32|
||Current descriptor address register 21|CDAR21|32|H'E8215064|32|
||Error status register|ESR|32|H'E8215088|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|EthernetAVB*2|Receive configuration register|RCR|32|H'E8215090|32|
||Receive queue configuration register 0|RQC0|32|H'E8215094|32|
||Receive queue configuration register 1|RQC1|32|H'E8215098|32|
||Receive queue configuration register 2|RQC2|32|H'E821509C|32|
||Receive queue configuration register 3|RQC3|32|H'E82150A0|32|
||Receive queue configuration register 4|RQC4|32|H'E82150A4|32|
||Receive padding configuration register|RPC|32|H'E82150B0|32|
||Unread frame counter stop level register|UFCS|32|H'E82150C0|32|
||Unread frame counter register 0|UFCV0|32|H'E82150C4|32|
||Unread frame counter register 1|UFCV1|32|H'E82150C8|32|
||Unread frame counter register 2|UFCV2|32|H'E82150CC|32|
||Unread frame counter register 3|UFCV3|32|H'E82150D0|32|
||Unread frame counter register 4|UFCV4|32|H'E82150D4|32|
||Unread frame counter decrement register 0|UFCD0|32|H'E82150E0|32|
||Unread frame counter decrement register 1|UFCD1|32|H'E82150E4|32|
||Unread frame counter decrement register 2|UFCD2|32|H'E82150E8|32|
||Unread frame counter decrement register 3|UFCD3|32|H'E82150EC|32|
||Unread frame counter decrement register 4|UFCD4|32|H'E82150F0|32|
||Separation filter offset register|SFO|32|H'E82150FC|32|
||Separation filter pattern register 0|SFP0|32|H'E8215100|32|
||Separation filter pattern register 1|SFP1|32|H'E8215104|32|
||Separation filter pattern register 2|SFP2|32|H'E8215108|32|
||Separation filter pattern register 3|SFP3|32|H'E821510C|32|
||Separation filter pattern register 4|SFP4|32|H'E8215110|32|
||Separation filter pattern register 5|SFP5|32|H'E8215114|32|
||Separation filter pattern register 6|SFP6|32|H'E8215118|32|
||Separation filter pattern register 7|SFP7|32|H'E821511C|32|
||Separation filter pattern register 8|SFP8|32|H'E8215120|32|
||Separation filter pattern register 9|SFP9|32|H'E8215124|32|
||Separation filter pattern register 10|SFP10|32|H'E8215128|32|
||Separation filter pattern register 11|SFP11|32|H'E821512C|32|
||Separation filter pattern register 12|SFP12|32|H'E8215130|32|
||Separation filter pattern register 13|SFP13|32|H'E8215134|32|
||Separation filter pattern register 14|SFP14|32|H'E8215138|32|
||Separation filter pattern register 15|SFP15|32|H'E821513C|32|
||Separation filter pattern register 16|SFP16|32|H'E8215140|32|
||Separation filter pattern register 17|SFP17|32|H'E8215144|32|
||Separation filter pattern register 18|SFP18|32|H'E8215148|32|
||Separation filter pattern register 19|SFP19|32|H'E821514C|32|
||Separation filter pattern register 20|SFP20|32|H'E8215150|32|
||Separation filter pattern register 21|SFP21|32|H'E8215154|32|
||Separation filter pattern register 22|SFP22|32|H'E8215158|32|
||Separation filter pattern register 23|SFP23|32|H'E821515C|32|
||Separation filter pattern register 24|SFP24|32|H'E8215160|32|
||Separation filter pattern register 25|SFP25|32|H'E8215164|32|
||Separation filter pattern register 26|SFP26|32|H'E8215168|32|
||Separation filter pattern register 27|SFP27|32|H'E821516C|32|
||Separation filter pattern register 28|SFP28|32|H'E8215170|32|
||Separation filter pattern register 29|SFP29|32|H'E8215174|32|
||Separation filter pattern register 30|SFP30|32|H'E8215178|32|
||Separation filter pattern register 31|SFP31|32|H'E821517C|32|
||Separation filter mask register 0|SFM0|32|H'E82151C0|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|EthernetAVB*2|Separation filter mask register 1|SFM1|32|H'E82151C4|32|
||Transmit configuration register|TGC|32|H'E8215300|32|
||Transmit configuration control register|TCCR|32|H'E8215304|32|
||Transmit status register|TSR|32|H'E8215308|32|
||Time stamp FIFO access register 0|TFA0|32|H'E8215310|32|
||Time stamp FIFO access register 1|TFA1|32|H'E8215314|32|
||Time stamp FIFO access register 2|TFA2|32|H'E8215318|32|
||CBS increment value register 0|CIVR0|32|H'E8215320|32|
||CBS increment value register 1|CIVR1|32|H'E8215324|32|
||CBS decrement value register 0|CDVR0|32|H'E8215328|32|
||CBS decrement value register 1|CDVR1|32|H'E821532C|32|
||CBS upper limit register 0|CUL0|32|H'E8215330|32|
||CBS upper limit register 1|CUL1|32|H'E8215334|32|
||CBS lower limit register 0|CLL0|32|H'E8215338|32|
||CBS lower limit register 1|CLL1|32|H'E821533C|32|
||Descriptor interrupt control register|DIC|32|H'E8215350|32|
||Descriptor interrupt status register|DIS|32|H'E8215354|32|
||Error interrupt control register|EIC|32|H'E8215358|32|
||Error interrupt status register|EIS|32|H'E821535C|32|
||Receive interrupt control register 0|RIC0|32|H'E8215360|32|
||Receive interrupt status register 0|RIS0|32|H'E8215364|32|
||Receive interrupt control register 1|RIC1|32|H'E8215368|32|
||Receive interrupt status register 1|RIS1|32|H'E821536C|32|
||Receive interrupt control register 2|RIC2|32|H'E8215370|32|
||Receive interrupt status register 2|RIS2|32|H'E8215374|32|
||Transmit interrupt control register|TIC|32|H'E8215378|32|
||Transmit interrupt status register|TIS|32|H'E821537C|32|
||Interrupt summary status register|ISS|32|H'E8215380|32|
||gPTP configuration control register|GCCR|32|H'E8215390|32|
||gPTP maximum transit time register|GMTT|32|H'E8215394|32|
||gPTP presentation time comparison register|GPTC|32|H'E8215398|32|
||gPTP timer increment register|GTI|32|H'E821539C|32|
||gPTP timer offset configuration register 0|GTO0|32|H'E82153A0|32|
||gPTP timer offset configuration register 1|GTO1|32|H'E82153A4|32|
||gPTP timer offset configuration register 2|GTO2|32|H'E82153A8|32|
||gPTP interrupt control register|GIC|32|H'E82153AC|32|
||gPTP interrupt status register|GIS|32|H'E82153B0|32|
||gPTP presentation time capture register|GCPT|32|H'E82153B4|32|
||gPTP timer capture register 0|GCT0|32|H'E82153B8|32|
||gPTP timer capture register 1|GCT1|32|H'E82153BC|32|
||gPTP timer capture register 2|GCT2|32|H'E82153C0|32|
||gPTP capture event control register|GCEC|32|H'E82153D8|32|
||E-MAC mode register|ECMR|32|H'E8215500|32|
||Receive frame length register|RFLR|32|H'E8215508|32|
||E-MAC status register|ECSR|32|H'E8215510|32|
||E-MAC interrupt permission register|ECSIPR|32|H'E8215518|32|
||PHY interface register|PIR|32|H'E8215520|32|
||Automatic PAUSE frame register|APR|32|H'E8215554|32|
||Manual PAUSE frame register|MPR|32|H'E8215558|32|
||PAUSE frame transmit counter|PFTCR|32|H'E821555C|32|
||PAUSE frame receive counter|PFRCR|32|H'E8215560|32|
||Automatic PAUSE frame retransmission count register|TPAUSER|32|H'E8215564|32|

## **Table 46.1 Register Addresses**

|**Module**|**Register Name**|**Abbreviation**|**Number**<br>**of Bits**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|EthernetAVB*2|MAC address high register|MAHR|32|H'E82155C0|32|
||MAC address low register|MALR|32|H'E82155C8|32|
||CRC error frame receive counter register|CEFCR|32|H'E8215740|32|
||Frame receive error counter register|FRECR|32|H'E8215748|32|
||Too-short frame receive counter register|TSFRCR|32|H'E8215750|32|
||Too-long frame receive counter register|TLFRCR|32|H'E8215758|32|
||Residual-bit frame receive counter register|RFCR|32|H'E8215760|32|
||Multicast address frame receive counter register|MAFCR|32|H'E8215778|32|

Note 1. RZ/A1L only Note 2. RZ/A1LU only

## 46.2 Register Bits

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Secondary cache|reg0_cache_id|Implementer[7]|Implementer[6]|Implementer[5]|Implementer[4]|Implementer[3]|Implementer[2]|Implementer[1]|Implementer[0]|
|||-|-|-|-|-|-|-|-|
|||CACHE ID[5]|CACHE ID[4]|CACHE ID[3]|CACHE ID[2]|CACHE ID[1]|CACHE ID[0]|Part Number[3]|Part Number[2]|
|||Part Number[1]|Part Number[0]|RTL release[5]|RTL release[4]|RTL release[3]|RTL release[2]|RTL release[1]|RTL release[0]|
||reg0_cache_type|Data banking|-|-|ctype[3]|ctype[2]|ctype[1]|ctype[0]|-|
|||Dsize[4]|Dsize[3]|Dsize[2]|Dsize[1]|Dsize[0]|L2 associativity|-|-|
|||-|-|L2 cache line length[1]|L2 cache line length[0]|Isize[4]|Isize[3]|Isize[2]|Isize[1]|
|||Isize[0]|L2 associativity|-|-|-|-|L2 cache line length[1]|L2 cache line length[0]|
||reg1_control|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|L2 Cache enable|
||reg1_aux_control|-|Early BRESP<br>enable|Instruction prefetch<br>enable|Data prefetch<br>enable|Non-secure interrupt<br>access control|Non-secure lockdown<br>enable|Cache<br>replacement policy|Force write allocate[1]|
|||Force write allocate[0]|Shared attribute<br>override enable|Parity enable|Event monitor bus<br>enable|Way-size[2]|Way-size[1]|Way-size[0]|Associativity|
|||-|-|Shared Attribute<br>Invalidate Enable|Exclusive cache<br>configuration|Store buffer device<br>limitation Enable|High Priority for SO<br>and Dev Reads<br>Enable|-|-|
|||-|-|-|-|-|-|-|Full Line of Zero<br>Enable|
||reg1_tag_ram_<br>control|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|RAM write access<br>latency[2]|RAM write access<br>latency[1]|RAM write access<br>latency[0]|
|||0|RAM read access<br>latency[2]|RAM read access<br>latency[1]|RAM read access<br>latency[0]|0|RAM setup latency[2]|RAM setup latency[1]|RAM setup latency[0]|
||reg1_data_ram_<br>control|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|RAM write access<br>latency[2]|RAM write access<br>latency[1]|RAM write access<br>latency[0]|
|||0|RAM read access<br>latency[2]|RAM read access<br>latency[1]|RAM read access<br>latency[0]|0|RAM setup latency<br>[2]|RAM setup latency<br>[1]|RAM setup latency<br>[0]|
||reg2_ev_counter_<br>ctrl|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|Counter reset[1]|Counter reset[0]|Event counter<br>enable|
||reg2_ev_counter1_<br>cfg|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|Counter event<br>source[3]|Counter event<br>source[2]|Counter event<br>source[1]|Counter event<br>source[0]|Event counter<br>interrupt<br>generation[1]|Event counter<br>interrupt<br>generation[0]|
||reg2_ev_counter0_<br>cfg|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|Counter event<br>source[3]|Counter event<br>source[2]|Counter event<br>source[1]|Counter event<br>source[0]|Event counter<br>interrupt<br>generation[1]|Event counter<br>interrupt<br>generation[0]|
||reg2_ev_counter1|Counter value[31]|Counter value[30]|Counter value[29]|Counter value[28]|Counter value[27]|Counter value[26]|Counter value[25]|Counter value[24]|
|||Counter value[23]|Counter value[22]|Counter value[21]|Counter value[20]|Counter value[19]|Counter value[18]|Counter value[17]|Counter value[16]|
|||Counter value[15]|Counter value[14]|Counter value[13]|Counter value[12]|Counter value[11]|Counter value[10]|Counter value[9]|Counter value[8]|
|||Counter value[7]|Counter value[6]|Counter value[5]|Counter value[4]|Counter value[3]|Counter value[2]|Counter value[1]|Counter value[0]|
||reg2_ev_counter0|Counter value[31]|Counter value[30]|Counter value[29]|Counter value[28]|Counter value[27]|Counter value[26]|Counter value[25]|Counter value[24]|
|||Counter value[23]|Counter value[22]|Counter value[21]|Counter value[20]|Counter value[19]|Counter value[18]|Counter value[17]|Counter value[16]|
|||Counter value[15]|Counter value[14]|Counter value[13]|Counter value[12]|Counter value[11]|Counter value[10]|Counter value[9]|Counter value[8]|
|||Counter value[7]|Counter value[6]|Counter value[5]|Counter value[4]|Counter value[3]|Counter value[2]|Counter value[1]|Counter value[0]|
||reg2_int_mask|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DECERR|
|||SLVERR|ERRRD|ERRRT|ERRWD|ERRWT|PARRD|PARRT|ECNTR|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Secondary cache|reg2_int_mask_<br>status|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DECERR|
|||SLVERR|ERRRD|ERRRT|ERRWD|ERRWT|PARRD|PARRT|ECNTR|
||reg2_int_raw_status|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DECERR|
|||SLVERR|ERRRD|ERRRT|ERRWD|ERRWT|PARRD|PARRT|ECNTR|
||reg2_int_clear|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DECERR|
|||SLVERR|ERRRD|ERRRT|ERRWD|ERRWT|PARRD|PARRT|ECNTR|
||reg7_cache_sync|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|C|
||reg7_inv_pa|TAG[17]|TAG[16]|TAG[15]|TAG[14]|TAG[13]|TAG[12]|TAG[11]|TAG[10]|
|||TAG[9]|TAG[8]|TAG[7]|TAG[6]|TAG[5]|TAG[4]|TAG[3]|TAG[2]|
|||TAG[1]|TAG[0]|INDEX[8]|INDEX[7]|INDEX[6]|INDEX[5]|INDEX[4]|INDEX[3]|
|||INDEX[2]|INDEX[1]|INDEX[0]|-|-|-|-|C|
||reg7_inv_way|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Way bits[7]|Way bits[6]|Way bits[5]|Way bits[4]|Way bits[3]|Way bits[2]|Way bits[1]|Way bits[0]|
||reg7_clean_pa|TAG[17]|TAG[16]|TAG[15]|TAG[14]|TAG[13]|TAG[12]|TAG[11]|TAG[10]|
|||TAG[9]|TAG[8]|TAG[7]|TAG[6]|TAG[5]|TAG[4]|TAG[3]|TAG[2]|
|||TAG[1]|TAG[0]|INDEX[8]|INDEX[7]|INDEX[6]|INDEX[5]|INDEX[4]|INDEX[3]|
|||INDEX[2]|INDEX[1]|INDEX[0]|-|-|-|-|C|
||reg7_clean_index|-|Way[2]|Way[1]|Way[0]|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|INDEX[8]|INDEX[7]|INDEX[6]|INDEX[5]|INDEX[4]|INDEX[3]|
|||INDEX[2]|INDEX[1]|INDEX[0]|-|-|-|-|C|
||reg7_clean_way|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Way bits[7]|Way bits[6]|Way bits[5]|Way bits[4]|Way bits[3]|Way bits[2]|Way bits[1]|Way bits[0]|
||reg7_clean_inv_pa|TAG[17]|TAG[16]|TAG[15]|TAG[14]|TAG[13]|TAG[12]|TAG[11]|TAG[10]|
|||TAG[9]|TAG[8]|TAG[7]|TAG[6]|TAG[5]|TAG[4]|TAG[3]|TAG[2]|
|||TAG[1]|TAG[0]|INDEX[8]|INDEX[7]|INDEX[6]|INDEX[5]|INDEX[4]|INDEX[3]|
|||INDEX[2]|INDEX[1]|INDEX[0]|-|-|-|-|C|
||reg7_clean_inv_<br>index|-|Way[2]|Way[1]|Way[0]|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|INDEX[8]|INDEX[7]|INDEX[6]|INDEX[5]|INDEX[4]|INDEX[3]|
|||INDEX[2]|INDEX[1]|INDEX[0]|-|-|-|-|C|
||reg7_clean_inv_way|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Way_bits[7]|Way_bits[6]|Way_bits[5]|Way_bits[4]|Way_bits[3]|Way_bits[2]|Way_bits[1]|Way_bits[0]|
||reg9_d_lockdown0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DATALOCK000[7]|DATALOCK000[6]|DATALOCK000[5]|DATALOCK000[4]|DATALOCK000[3]|DATALOCK000[2]|DATALOCK000[1]|DATALOCK000[0]|
||reg9_i_lockdown0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INSTRLOCK000<br>[7]|INSTRLOCK000<br>[6]|INSTRLOCK000<br>[5]|INSTRLOCK000<br>[4]|INSTRLOCK000<br>[3]|INSTRLOCK000<br>[2]|INSTRLOCK000<br>[1]|INSTRLOCK000<br>[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Secondary cache|reg9_d_lockdown1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DATALOCK001[7]|DATALOCK001[6]|DATALOCK001[5]|DATALOCK001[4]|DATALOCK001[3]|DATALOCK001[2]|DATALOCK001[1]|DATALOCK001[0]|
||reg9_i_lockdown1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INSTRLOCK001<br>[7]|INSTRLOCK001<br>[6]|INSTRLOCK001<br>[5]|INSTRLOCK001<br>[4]|INSTRLOCK001<br>[3]|INSTRLOCK001<br>[2]|INSTRLOCK001<br>[1]|INSTRLOCK001<br>[0]|
||reg9_d_lockdown2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DATALOCK002[7]|DATALOCK002[6]|DATALOCK002[5]|DATALOCK002[4]|DATALOCK002[3]|DATALOCK002[2]|DATALOCK002[1]|DATALOCK002[0]|
||reg9_i_lockdown2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INSTRLOCK002<br>[7]|INSTRLOCK002<br>[6]|INSTRLOCK002<br>[5]|INSTRLOCK002<br>[4]|INSTRLOCK002<br>[3]|INSTRLOCK002<br>[2]|INSTRLOCK002<br>[1]|INSTRLOCK002<br>[0]|
||reg9_d_lockdown3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DATALOCK003[7]|DATALOCK003[6]|DATALOCK003[5]|DATALOCK003[4]|DATALOCK003[3]|DATALOCK003[2]|DATALOCK003[1]|DATALOCK003[0]|
||reg9_i_lockdown3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INSTRLOCK003<br>[7]|INSTRLOCK003<br>[6]|INSTRLOCK003<br>[5]|INSTRLOCK003<br>[4]|INSTRLOCK003<br>[3]|INSTRLOCK003<br>[2]|INSTRLOCK003<br>[1]|INSTRLOCK003<br>[0]|
||reg9_d_lockdown4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DATALOCK004[7]|DATALOCK004[6]|DATALOCK004[5]|DATALOCK004[4]|DATALOCK004[3]|DATALOCK004[2]|DATALOCK004[1]|DATALOCK004[0]|
||reg9_i_lockdown4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INSTRLOCK004<br>[7]|INSTRLOCK004[<br>6]|INSTRLOCK004<br>[5]|INSTRLOCK004<br>[4]|INSTRLOCK004<br>[3]|INSTRLOCK004<br>[2]|INSTRLOCK004<br>[1]|INSTRLOCK004<br>[0]|
||reg9_d_lockdown5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DATALOCK005[7]|DATALOCK005[6]|DATALOCK005[5]|DATALOCK005[4]|DATALOCK005[3]|DATALOCK005[2]|DATALOCK005[1]|DATALOCK005[0]|
||reg9_i_lockdown5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INSTRLOCK005<br>[7]|INSTRLOCK005<br>[6]|INSTRLOCK005<br>[5]|INSTRLOCK005<br>[4]|INSTRLOCK005<br>[3]|INSTRLOCK005<br>[2]|INSTRLOCK005<br>[1]|INSTRLOCK005<br>[0]|
||reg9_d_lockdown6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DATALOCK006[7]|DATALOCK006[6]|DATALOCK006[5]|DATALOCK006[4]|DATALOCK006[3]|DATALOCK006[2]|DATALOCK006[1]|DATALOCK006[0]|
||reg9_i_lockdown6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INSTRLOCK006<br>[7]|INSTRLOCK006<br>[6]|INSTRLOCK006<br>[5]|INSTRLOCK006<br>[4]|INSTRLOCK006<br>[3]|INSTRLOCK006<br>[2]|INSTRLOCK006<br>[1]|INSTRLOCK006<br>[0]|
||reg9_d_lockdown7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DATALOCK007[7]|DATALOCK007[6]|DATALOCK007[5]|DATALOCK007[4]|DATALOCK007[3]|DATALOCK007[2]|DATALOCK007[1]|DATALOCK007[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Secondary cache|reg9_i_lockdown7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INSTRLOCK007<br>[7]|INSTRLOCK007<br>[6]|INSTRLOCK007<br>[5]|INSTRLOCK007<br>[4]|INSTRLOCK007<br>[3]|INSTRLOCK007<br>[2]|INSTRLOCK007<br>[1]|INSTRLOCK007<br>[0]|
||reg9_lock_line_en|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|lockdown_by_line_<br>enable|
||reg9_unlock_way|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||unlock_all_lines_<br>by_way_operation[7]|unlock_all_lines_<br>by_way_operation[6]|unlock_all_lines_<br>by_way_operation[5]|unlock_all_lines_<br>by_way_operation[4]|unlock_all_lines_<br>by_way_operation[3]|unlock_all_lines_<br>by_way_operation[2]|unlock_all_lines_<br>by_way_operation[1]|unlock_all_lines_<br>by_way_operation[0]|
||reg12_addr_filtering_<br>start|address_filtering_start<br>[11]|address_filtering_start<br>[10]|address_filtering_start<br>[9]|address_filtering_start<br>[8]|address_filtering_start<br>[7]|address_filtering_start<br>[6]|address_filtering_start<br>[5]|address_filtering_start<br>[4]|
|||address_filtering_start<br>[3]|address_filtering_start<br>[2]|address_filtering_start<br>[1]|address_filtering_start<br>[0]|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|address_filtering_<br>enable|
||reg12_addr_filtering_<br>end|address_filtering_end<br>[11]|address_filtering_end<br>[10]|address_filtering_end<br>[9]|address_filtering_end<br>[8]|address_filtering_end<br>[7]|address_filtering_end<br>[6]|address_filtering_end<br>[5]|address_filtering_end<br>[4]|
|||address_filtering_end<br>[3]|address_filtering_end<br>[2]|address_filtering_end<br>[1]|address_filtering_end<br>[0]|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||reg15_debug_ctrl|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|SPNIDEN|DWB|DCL|
||reg15_prefetch_ctrl|-|Double linefill<br>enable|Instruction prefetch<br>enable|Data prefetch<br>enable|Double linefill on<br>WRAP read disable|-|-|Prefetch drop<br>enable|
|||Incr double Linefill<br>enable|-|Not same ID on<br>exclusive sequence<br>enable|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|Prefetch offset[4]|Prefetch offset[3]|Prefetch offset[2]|Prefetch offset[1]|Prefetch offset[0]|
||reg15_power_ctrl|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|dynamic_clk_<br>gating_en|standby_mode_en|
|LSI internal bus|RMPR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|AXI128|-|
||AXIBUSCTL0|-|-|-|-|JCUARCACHE[3]*4|JCUARCACHE[2]*4|JCUARCACHE[1]*4|JCUARCACHE[0]*4|
|||-|-|-|-|JCUAWCACHE[3]*4|JCUAWCACHE[2]*4|JCUAWCACHE[1]*4|JCUAWCACHE[0]*4|
|||-|-|-|-|ETHARCACHE[3]|ETHARCACHE[2]|ETHARCACHE[1]|ETHARCACHE[0]|
|||-|-|-|-|ETHAWCACHE[3]|ETHAWCACHE[2]|ETHAWCACHE[1]|ETHAWCACHE[0]|
||AXIBUSCTL2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CEUAWCACHE<br>[3]|CEUAWCACHE<br>[2]|CEUAWCACHE<br>[1]|CEUAWCACHE<br>[0]|
||AXIBUSCTL5*1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|MLBAxCACHE[1]|MLBAxCACHE[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|LSI internal bus|AXIBUSCTL6|-|-|-|-|VDC501AR<br>CACHE[3]|VDC501AR<br>CACHE[2]|VDC501AR<br>CACHE[1]|VDC501AR<br>CACHE[0]|
|||-|-|-|-|VDC501AW<br>CACHE[3]|VDC501AW<br>CACHE[2]|VDC501AW<br>CACHE[1]|VDC501AW<br>CACHE[0]|
|||-|-|-|-|VDC502AR<br>CACHE[3]|VDC502AR<br>CACHE[2]|VDC502AR<br>CACHE[1]|VDC502AR<br>CACHE[0]|
|||-|-|-|-|-|-|-|-|
||AXIBUSCTL7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|VDC504AR<br>CACHE[3]|VDC504AR<br>CACHE[2]|VDC504AR<br>CACHE[1]|VDC504AR<br>CACHE[0]|
|||-|-|-|-|-|-|-|-|
||AXIRERRCTL0|-|-|-|JCURERREN*4|-|-|-|ETHRERREN|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|CEURERREN|
|||-|-|-|-|-|-|-|-|
||AXIRERRCTL2|-|-|-|VDC501RERREN|-|-|-|VDC502RERREN|
|||-|-|-|-|-|-|-|VDC504RERREN|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||AXIRERRST0|JCURRESP[1]*4|JCURRESP[0]*4|JCUBRESP[1]*4|JCUBRESP[0]*4|ETHRRESP[1]|ETHRRESP[0]|ETHBRESP[1]|ETHBRESP[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CEUBRESP[1]|CEUBRESP[0]|
|||-|-|-|-|-|-|-|-|
||AXIRERRST2|VDC501RRESP<br>[1]|VDC501RRESP<br>[0]|VDC501BRESP<br>[1]|VDC501BRESP<br>[0]|VDC502RRESP<br>[1]|VDC502RRESP<br>[0]|-|-|
|||-|-|-|-|VDC504RRESP<br>[1]|VDC504RRESP<br>[0]|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||AXIRERRCLR0|-|JCURRESPCLR*4|-|JCUBRESPCLR*4|-|ETHRRESPCLR|-|ETHBRESPCLR|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|CEUBRESPCLR|
|||-|-|-|-|-|-|-|-|
||AXIRERRCLR2|-|VDC501RRESP<br>CLR|-|VDC501BRESP<br>CLR|-|VDC502RRESP<br>CLR|-|-|
|||-|-|-|-|-|VDC504RRESP<br>CLR|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|Clock pulse<br>generator|FRQCR|-|CKOEN2|CKOEN[1]|CKOEN[0]|-|-|IFC[1]|IFC[0]|
|||-|-|-|-|-|-|-|-|
|Interrupt<br>controller|ICR0|NMIL|-|-|-|-|-|-|NMIE|
|||-|-|-|-|-|-|NMIF|-|
||ICR1|IRQ71S|IRQ70S|IRQ61S|IRQ60S|IRQ51S|IRQ50S|IRQ41S|IRQ40S|
|||IRQ31S|IRQ30S|IRQ21S|IRQ20S|IRQ11S|IRQ10S|IRQ01S|IRQ00S|
||IRQRR|-|-|-|-|-|-|-|-|
|||IRQ7F|IRQ6F|IRQ5F|IRQ4F|IRQ3F|IRQ2F|IRQ1F|IRQ0F|
||ICDDCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|Enable|
||ICDICTR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LSPI[4]|LSPI[3]|LSPI[2]|LSPI[1]|LSPI[0]|SecurityExtn|-|-|
|||CPUNumber[2]|CPUNumber[1]|CPUNumber[0]|ITLinesNumber[4]|ITLinesNumber[3]|ITLinesNumber[2]|ITLinesNumber[1]|ITLinesNumber[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Interrupt<br>controller|ICDIIDR|ProductID[7]|ProductID[6]|ProductID[5]|ProductID[4]|ProductID[3]|ProductID[2]|ProductID[1]|ProductID[0]|
|||-|-|-|-|Variant[3]|Variant[2]|Variant[1]|Variant[0]|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|Implementer[11]|Implementer[10]|Implementer[9]|Implementer[8]|
|||Implementer[7]|Implementer[6]|Implementer[5]|Implementer[4]|Implementer[3]|Implementer[2]|Implementer[1]|Implementer[0]|
||ICDISRn<br>n = 0 to 16|Security status bits[31]|Security status bits[30]|Security status bits[29]|Security status bits[28]|Security status bits[27]|Security status bits[26]|Security status bits[25]|Security status bits[24]|
|||Security status bits[23]|Security status bits[22]|Security status bits[21]|Security status bits[20]|Security status bits[19]|Security status bits[18]|Security status bits[17]|Security status bits[16]|
|||Security status bits[15]|Security status bits[14]|Security status bits[13]|Security status bits[12]|Security status bits[11]|Security status bits[10]|Security status bits[9]|Security status bits[8]|
|||Security status bits[7]|Security status bits[6]|Security status bits[5]|Security status bits[4]|Security status bits[3]|Security status bits[2]|Security status bits[1]|Security status bits[0]|
||ICDISERn<br>n = 0 to 16|Set-enable bits[31]|Set-enable bits[30]|Set-enable bits[29]|Set-enable bits[28]|Set-enable bits[27]|Set-enable bits[26]|Set-enable bits[25]|Set-enable bits[24]|
|||Set-enable bits[23]|Set-enable bits[22]|Set-enable bits[21]|Set-enable bits[20]|Set-enable bits[19]|Set-enable bits[18]|Set-enable bits[17]|Set-enable bits[16]|
|||Set-enable bits[15]|Set-enable bits[14]|Set-enable bits[13]|Set-enable bits[12]|Set-enable bits[11]|Set-enable bits[10]|Set-enable bits[9]|Set-enable bits[8]|
|||Set-enable bits[7]|Set-enable bits[6]|Set-enable bits[5]|Set-enable bits[4]|Set-enable bits[3]|Set-enable bits[2]|Set-enable bits[1]|Set-enable bits[0]|
||ICDICERn<br>n = 0 to 16|Clear-enable bits[31]|Clear-enable bits[30]|Clear-enable bits[29]|Clear-enable bits[28]|Clear-enable bits[27]|Clear-enable bits[26]|Clear-enable bits[25]|Clear-enable bits[24]|
|||Clear-enable bits[23]|Clear-enable bits[22]|Clear-enable bits[21]|Clear-enable bits[20]|Clear-enable bits[19]|Clear-enable bits[18]|Clear-enable bits[17]|Clear-enable bits[16]|
|||Clear-enable bits[15]|Clear-enable bits[14]|Clear-enable bits[13]|Clear-enable bits[12]|Clear-enable bits[11]|Clear-enable bits[10]|Clear-enable bits[9]|Clear-enable bits[8]|
|||Clear-enable bits[7]|Clear-enable bits[6]|Clear-enable bits[5]|Clear-enable bits[4]|Clear-enable bits[3]|Clear-enable bits[2]|Clear-enable bits[1]|Clear-enable bits[0]|
||ICDISPRn<br>n = 0 to 16|Set-pending bits[31]|Set-pending bits[30]|Set-pending bits[29]|Set-pending bits[28]|Set-pending bits[27]|Set-pending bits[26]|Set-pending bits[25]|Set-pending bits[24]|
|||Set-pending bits[23]|Set-pending bits[22]|Set-pending bits[21]|Set-pending bits[20]|Set-pending bits[19]|Set-pending bits[18]|Set-pending bits[17]|Set-pending bits[16]|
|||Set-pending bits[15]|Set-pending bits[14]|Set-pending bits[13]|Set-pending bits[12]|Set-pending bits[11]|Set-pending bits[10]|Set-pending bits[9]|Set-pending bits[8]|
|||Set-pending bits[7]|Set-pending bits[6]|Set-pending bits[5]|Set-pending bits[4]|Set-pending bits[3]|Set-pending bits[2]|Set-pending bits[1]|Set-pending bits[0]|
||ICDICPRn<br>n = 0 to 16|Clear-pending bits[31]|Clear-pending bits[30]|Clear-pending bits[29]|Clear-pending bits[28]|Clear-pending bits[27]|Clear-pending bits[26]|Clear-pending bits[25]|Clear-pending bits[24]|
|||Clear-pending bits[23]|Clear-pending bits[22]|Clear-pending bits[21]|Clear-pending bits[20]|Clear-pending bits[19]|Clear-pending bits[18]|Clear-pending bits[17]|Clear-pending bits[16]|
|||Clear-pending bits[15]|Clear-pending bits[14]|Clear-pending bits[13]|Clear-pending bits[12]|Clear-pending bits[11]|Clear-pending bits[10]|Clear-pending bits[9]|Clear-pending bits[8]|
|||Clear-pending bits[7]|Clear-pending bits[6]|Clear-pending bits[5]|Clear-pending bits[4]|Clear-pending bits[3]|Clear-pending bits[2]|Clear-pending bits[1]|Clear-pending bits[0]|
||ICDABRn<br>n = 0 to 16|Active bits[31]|Active bits[30]|Active bits[29]|Active bits[28]|Active bits[27]|Active bits[26]|Active bits[25]|Active bits[24]|
|||Active bits[23]|Active bits[22]|Active bits[21]|Active bits[20]|Active bits[19]|Active bits[18]|Active bits[17]|Active bits[16]|
|||Active bits[15]|Active bits[14]|Active bits[13]|Active bits[12]|Active bits[11]|Active bits[10]|Active bits[9]|Active bits[8]|
|||Active bits[7]|Active bits[6]|Active bits[5]|Active bits[4]|Active bits[3]|Active bits[2]|Active bits[1]|Active bits[0]|
||ICDIPRn<br>n = 0 to 134|Priority,<br>byte offset 3[7]|Priority,<br>byte offset 3[6]|Priority,<br>byte offset 3[5]|Priority,<br>byte offset 3[4]|Priority,<br>byte offset 3[3]|Priority,<br>byte offset 3[2]|Priority,<br>byte offset 3[1]|Priority,<br>byte offset 3[0]|
|||Priority,<br>byte offset 2[7]|Priority,<br>byte offset 2[6]|Priority,<br>byte offset 2[5]|Priority,<br>byte offset 2[4]|Priority,<br>byte offset 2[3]|Priority,<br>byte offset 2[2]|Priority,<br>byte offset 2[1]|Priority,<br>byte offset 2[0]|
|||Priority,<br>byte offset 1[7]|Priority,<br>byte offset 1[6]|Priority,<br>byte offset 1[5]|Priority,<br>byte offset 1[4]|Priority,<br>byte offset 1[3]|Priority,<br>byte offset 1[2]|Priority,<br>byte offset 1[1]|Priority,<br>byte offset 1[0]|
|||Priority,<br>byte offset 0[7]|Priority,<br>byte offset 0[6]|Priority,<br>byte offset 0[5]|Priority,<br>byte offset 0[4]|Priority,<br>byte offset 0[3]|Priority,<br>byte offset 0[2]|Priority,<br>byte offset 0[1]|Priority,<br>byte offset 0[0]|
||ICDIPTRn<br>n = 0 to 134|CPU targets,<br>byte offset 3[7]|CPU targets,<br>byte offset 3[6]|CPU targets,<br>byte offset 3[5]|CPU targets,<br>byte offset 3[4]|CPU targets,<br>byte offset 3[3]|CPU targets,<br>byte offset 3[2]|CPU targets,<br>byte offset 3[1]|CPU targets,<br>byte offset 3[0]|
|||CPU targets,<br>byte offset 2[7]|CPU targets,<br>byte offset 2[6]|CPU targets,<br>byte offset 2[5]|CPU targets,<br>byte offset 2[4]|CPU targets,<br>byte offset 2[3]|CPU targets,<br>byte offset 2[2]|CPU targets,<br>byte offset 2[1]|CPU targets,<br>byte offset 2[0]|
|||CPU targets,<br>byte offset 1[7]|CPU targets,<br>byte offset 1[6]|CPU targets,<br>byte offset 1[5]|CPU targets,<br>byte offset 1[4]|CPU targets,<br>byte offset 1[3]|CPU targets,<br>byte offset 1[2]|CPU targets,<br>byte offset 1[1]|CPU targets,<br>byte offset 1[0]|
|||CPU targets,<br>byte offset 0[7]|CPU targets,<br>byte offset 0[6]|CPU targets,<br>byte offset 0[5]|CPU targets,<br>byte offset 0[4]|CPU targets,<br>byte offset 0[3]|CPU targets,<br>byte offset 0[2]|CPU targets,<br>byte offset 0[1]|CPU targets,<br>byte offset 0[0]|
||ICDICFRn<br>n = 0 to 33|Int_config[1],<br>field 15|Int_config[0],<br>field 15|Int_config[1],<br>field 14|Int_config[0],<br>field 14|Int_config[1],<br>field 13|Int_config[0],<br>field 13|Int_config[1],<br>field 12|Int_config[0],<br>field 12|
|||Int_config[1],<br>field 11|Int_config[0],<br>field 11|Int_config[1],<br>field 10|Int_config[0],<br>field 10|Int_config[1],<br>field 9|Int_config[0],<br>field 9|Int_config[1],<br>field 8|Int_config[0],<br>field 8|
|||Int_config[1],field7|Int_config[0],field7|Int_config[1],field6|Int_config[0],field6|Int_config[1],field5|Int_config[0],field5|Int_config[1],field4|Int_config[0],field4|
|||Int_config[1],field3|Int_config[0],field3|Int_config[1],field2|Int_config[0],field2|Int_config[1],field1|Int_config[0],field1|Int_config[1],field0|Int_config[0],field0|
||PPI Status Register|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ppi_status[15]|ppi_status[14]|ppi_status[13]|ppi_status[12]|ppi_status[11]|ppi_status[10]|ppi_status[9]|ppi_status[8]|
|||ppi_status[7]|ppi_status[6]|ppi_status[5]|ppi_status[4]|ppi_status[3]|ppi_status[2]|ppi_status[1]|ppi_status[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Interrupt<br>controller|SPI Status<br>Registersn<br>n = 0 to 14|spi_status[31]|spi_status[30]|spi_status[29]|spi_status[28]|spi_status[27]|spi_status[26]|spi_status[25]|spi_status[24]|
|||spi_status[23]|spi_status[22]|spi_status[21]|spi_status[20]|spi_status[19]|spi_status[18]|spi_status[17]|spi_status[16]|
|||spi_status[15]|spi_status[14]|spi_status[13]|spi_status[12]|spi_status[11]|spi_status[10]|spi_status[9]|spi_status[8]|
|||spi_status[7]|spi_status[6]|spi_status[5]|spi_status[4]|spi_status[3]|spi_status[2]|spi_status[1]|spi_status[0]|
||ICDSGIR|-|-|-|-|-|-|TargetListFilter[1]|TargetListFilter[0]|
|||CPUTargetList[7]|CPUTargetList[6]|CPUTargetList[5]|CPUTargetList[4]|CPUTargetList[3]|CPUTargetList[2]|CPUTargetList[1]|CPUTargetList[0]|
|||SATT|-|-|-|-|-|-|-|
|||-|-|-|-|SGIINTID[3]|SGIINTID[2]|SGIINTID[1]|SGIINTID[0]|
||ICCICR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SBPR|FIQEn|AckCtl|EnableNS|EnableS|
||ICCPMR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Priority[7]|Priority[6]|Priority[5]|Priority[4]|Priority[3]|Priority[2]|Priority[1]|Priority[0]|
||ICCBPR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|Binary point[2]|Binary point[1]|Binary point[0]|
||ICCIAR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|CPUID[2]|CPUID[1]|CPUID[0]|ACKINTID[9]|ACKINTID[8]|
|||ACKINTID[7]|ACKINTID[6]|ACKINTID[5]|ACKINTID[4]|ACKINTID[3]|ACKINTID[2]|ACKINTID[1]|ACKINTID[0]|
||ICCEOIR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|CPUID[2]|CPUID[1]|CPUID[0]|EOIINTID[9]|EOIINTID[8]|
|||EOIINTID[7]|EOIINTID[6]|EOIINTID[5]|EOIINTID[4]|EOIINTID[3]|EOIINTID[2]|EOIINTID[1]|EOIINTID[0]|
||ICCRPR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Priority[7]|Priority[6]|Priority[5]|Priority[4]|Priority[3]|Priority[2]|Priority[1]|Priority[0]|
||ICCHPIR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|CPUID[2]|CPUID[1]|CPUID[0]|PENDINTID[9]|PENDINTID[8]|
|||PENDINTID[7]|PENDINTID[6]|PENDINTID[5]|PENDINTID[4]|PENDINTID[3]|PENDINTID[2]|PENDINTID[1]|PENDINTID[0]|
||ICCABPR|||||||||
|||||||||||
|||||||||||
|||||||||||
||ICCIIDR|ProductID[11]|ProductID[10]|ProductID[9]|ProductID[8]|ProductID[7]|ProductID[6]|ProductID[5]|ProductID[4]|
|||ProductID[3]|ProductID[2]|ProductID[1]|ProductID[0]|Architectureversion[3]|Architectureversion[2]|Architectureversion[1]|Architectureversion[0]|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|Implementer[11]|Implementer[10]|Implementer[9]|Implementer[8]|
|||Implementer[7]|Implementer[6]|Implementer[5]|Implementer[4]|Implementer[3]|Implementer[2]|Implementer[1]|Implementer[0]|
|Bus state<br>controller|CMNCR|-|-|-|TL0|-|-|-|AL0|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|DPRTY[1]|DPRTY[0]|-|
|||-|-|-|-|-|-|HIZMEM|HIZCNT|
||CS0BCR|-|IWW[2]|IWW[1]|IWW[0]|IWRWD[2]|IWRWD[1]|IWRWD[0]|IWRWS[2]|
|||IWRWS[1]|IWRWS[0]|IWRRD[2]|IWRRD[1]|IWRRD[0]|IWRRS[2]|IWRRS[1]|IWRRS[0]|
|||-|TYPE[2]|TYPE[1]|TYPE[0]|-|BSZ[1]|BSZ[0]|-|
|||-|-|-|-|-|-|-|-|
||CS1BCR|-|IWW[2]|IWW[1]|IWW[0]|IWRWD[2]|IWRWD[1]|IWRWD[0]|IWRWS[2]|
|||IWRWS[1]|IWRWS[0]|IWRRD[2]|IWRRD[1]|IWRRD[0]|IWRRS[2]|IWRRS[1]|IWRRS[0]|
|||-|TYPE[2]|TYPE[1]|TYPE[0]|-|BSZ[1]|BSZ[0]|-|
|||-|-|-|-|-|-|-|-|
||CS2BCR|-|IWW[2]|IWW[1]|IWW[0]|IWRWD[2]|IWRWD[1]|IWRWD[0]|IWRWS[2]|
|||IWRWS[1]|IWRWS[0]|IWRRD[2]|IWRRD[1]|IWRRD[0]|IWRRS[2]|IWRRS[1]|IWRRS[0]|
|||-|TYPE[2]|TYPE[1]|TYPE[0]|-|BSZ[1]|BSZ[0]|-|
|||-|-|-|-|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Bus state<br>controller|CS3BCR|-|IWW[2]|IWW[1]|IWW[0]|IWRWD[2]|IWRWD[1]|IWRWD[0]|IWRWS[2]|
|||IWRWS[1]|IWRWS[0]|IWRRD[2]|IWRRD[1]|IWRRD[0]|IWRRS[2]|IWRRS[1]|IWRRS[0]|
|||-|TYPE[2]|TYPE[1]|TYPE[0]|-|BSZ[1]|BSZ[0]|-|
|||-|-|-|-|-|-|-|-|
||CS4BCR|-|IWW[2]|IWW[1]|IWW[0]|IWRWD[2]|IWRWD[1]|IWRWD[0]|IWRWS[2]|
|||IWRWS[1]|IWRWS[0]|IWRRD[2]|IWRRD[1]|IWRRD[0]|IWRRS[2]|IWRRS[1]|IWRRS[0]|
|||-|TYPE[2]|TYPE[1]|TYPE[0]|-|BSZ[1]|BSZ[0]|-|
|||-|-|-|-|-|-|-|-|
||CS5BCR|-|IWW[2]|IWW[1]|IWW[0]|IWRWD[2]|IWRWD[1]|IWRWD[0]|IWRWS[2]|
|||IWRWS[1]|IWRWS[0]|IWRRD[2]|IWRRD[1]|IWRRD[0]|IWRRS[2]|IWRRS[1]|IWRRS[0]|
|||-|TYPE[2]|TYPE[1]|TYPE[0]|-|BSZ[1]|BSZ[0]|-|
|||-|-|-|-|-|-|-|-|
||CS0WCR<br>Normal space, SRAM<br>with byte selection,<br>MPX-I/O|<br>-|-|-|-|-|-|-|-|
|||<br>-|-|-|BAS|-|-|-|-|
|||-|-|-|SW[1]|SW[0]|WR[3]|WR[2]|WR[1]|
|||WR[0]|WM|-|-|-|-|HW[1]|HW[0]|
||CS0WCR<br>Burst ROM (clock<br>asynchronous)|-|-|-|-|-|-|-|-|
|||-|-|BST[1]|BST[0]|-|-|BW[1]|BW[0]|
|||-|-|-|-|-|W[3]|W[2]|W[1]|
|||W[0]|WM|-|-|-|-|-|-|
||CS0WCR<br>Burst ROM (clock<br>synchronous)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|BW[1]|BW[0]|
|||-|-|-|-|-|W[3]|W[2]|W[1]|
|||W[0]|WM|-|-|-|-|-|-|
||CS1WCR|-|-|-|-|-|-|-|-|
|||-|-|-|BAS|-|WW[2]|WW[1]|WW[0]|
|||-|-|-|SW[1]|SW[0]|WR[3]|WR[2]|WR[1]|
|||WR[0]|WM|-|-|-|-|HW[1]|HW[0]|
||CS2WCR<br>Normal space, SRAM<br>with byte selection,<br>MPX-I/O|<br>-|-|-|-|-|-|-|-|
|||<br>-|-|-|BAS|-|-|-|-|
|||-|-|-|-|-|WR[3]|WR[2]|WR[1]|
|||WR[0]|WM|-|-|-|-|-|-|
||CS2WCR<br>Burst ROM (clock<br>synchronous)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|A2CL[1]|
|||A2CL[0]|-|-|-|-|-|-|-|
||CS3WCR<br>Normal space, SRAM<br>with byte selection,<br>MPX-I/O|<br>-|-|-|-|-|-|-|-|
|||<br>-|-|-|BAS|-|-|-|-|
|||-|-|-|-|-|WR[3]|WR[2]|WR[1]|
|||WR[0]|WM|-|-|-|-|-|-|
||CS3WCR<br>Burst ROM (clock<br>synchronous)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|WTRP[1]|WTRP[0]|-|WTRCD[1]|WTRCD[0]|-|A3CL[1]|
|||A3CL[0]|-|-|TRWL[1]|TRWL[0]|-|WTRC[1]|WTRC[0]|
||CS4WCR<br>Normal space, SRAM<br>with byte selection,<br>MPX-I/O|<br>-|-|-|-|-|-|-|-|
|||<br>-|-|-|BAS|-|WW[2]|WW[1]|WW[0]|
|||-|-|-|SW[1]|SW[0]|WR[3]|WR[2]|WR[1]|
|||WR[0]|WM|-|-|-|-|HW[1]|HW[0]|
||CS4WCR<br>Burst ROM (clock<br>synchronous)|-|-|-|-|-|-|-|-|
|||-|-|BST[1]|BST[0]|-|-|BW[1]|BW[0]|
|||-|-|-|SW[1]|SW[0]|W[3]|W[2]|W[1]|
|||W[0]|WM|-|-|-|-|HW[1]|HW[0]|
||CS5WCR<br>Normal space, SRAM<br>with byte selection,<br>MPX-I/O|<br>-|-|-|-|-|-|-|-|
|||<br>-|-|SZSEL|MPXW/BAS|-|WW[2]|WW[1]|WW[0]|
|||-|-|-|SW[1]|SW[0]|WR[3]|WR[2]|WR[1]|
|||WR[0]|WM|-|-|-|-|HW[1]|HW[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Bus state<br>controller|SDCR|-|-|-|-|-|-|-|-|
|||-|-|-|A2ROW[1]|A2ROW[0]|-|A2COL[1]|A2COL[0]|
|||-|-|DEEP|-|RFSH|RMODE|PDOWN|BACTV|
|||-|-|-|A3ROW[1]|A3ROW[0]|-|A3COL[1]|A3COL[0]|
||RTCSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CMF|CMIE|CKS[2]|CKS[1]|CKS[0]|RRC[2]|RRC[1]|RRC[0]|
||RTCNT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||||||
||RTCOR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||||||
||TOSCOR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
||TOSCOR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
||TOSCOR2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
||TOSCOR3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
||TOSCOR4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
||TOSCOR5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
||TOSTR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|CS5TOSTF|CS4TOSTF|CS3TOSTF|CS2TOSTF|CS1TOSTF|CS0TOSTF|
||TOENR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|CS5TOEN|CS4TOEN|CS3TOEN|CS2TOEN|CS1TOEN|CS0TOEN|
|Direct memory<br>access controller|N0SA_0|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_0|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_0|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N1SA_0|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_0|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_0|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_0|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_0|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_0|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_0|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_0|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_0|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_1|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_1|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N0TB_1|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_1|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_1|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_1|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_1|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_1|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_1|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_1|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_1|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_1|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_2|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N0DA_2|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_2|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_2|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_2|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_2|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_2|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_2|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_2|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_2|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_2|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_2|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N0SA_3|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_3|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_3|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_3|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_3|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_3|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_3|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_3|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_3|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_3|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_3|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|CRLA_3|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_4|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_4|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_4|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_4|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_4|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_4|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_4|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_4|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_4|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_4|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|NXLA_4|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_4|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_5|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_5|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_5|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_5|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_5|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_5|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_5|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_5|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_5|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_5|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|CHEXT_5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_5|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_5|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_6|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_6|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_6|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_6|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_6|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_6|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_6|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_6|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_6|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_6|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|CHITVL_6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_6|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_6|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_7|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_7|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_7|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_7|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_7|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_7|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_7|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_7|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_7|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|CHCFG_7|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_7|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_7|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||DCTRL_0_7|LWCA[3]|LWCA[2]|LWCA[1]|LWCA[0]|-|LWPR[2]|LWPR[1]|LWPR[0]|
|||LDCA[3]|LDCA[2]|LDCA[1]|LDCA[0]|-|LDPR[2]|LDPR[1]|LDPR[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|LVINT|PR|
||DSTAT_EN_0_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||EN7|EN6|EN5|EN4|EN3|EN2|EN1|EN0|
||DSTAT_ER_0_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ER7|ER6|ER5|ER4|ER3|ER2|ER1|ER0|
||DSTAT_END_0_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||END7|END6|END5|END4|END3|END2|END1|END0|
||DSTAT_TC_0_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TC7|TC6|TC5|TC4|TC3|TC2|TC1|TC0|
||DSTAT_SUS_0_7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SUS7|SUS6|SUS5|SUS4|SUS3|SUS2|SUS1|SUS0|
||N0SA_8|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_8|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_8|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_8|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N1DA_8|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_8|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_8|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_8|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_8|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_8|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_8|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_8|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_8|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_8|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_8|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_8|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_9|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_9|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_9|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N1SA_9|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_9|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_9|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_9|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_9|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_9|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_9|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_9|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_9|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_9|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_9|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_9|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_9|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_10|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_10|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N0TB_10|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_10|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_10|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_10|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_10|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_10|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_10|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_10|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_10|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_10|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_10|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_10|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_10|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_10|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_11|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N0DA_11|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_11|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_11|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_11|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_11|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_11|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_11|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_11|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_11|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_11|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_11|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_11|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_11|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_11|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_11|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|N0SA_12|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_12|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_12|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_12|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_12|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_12|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_12|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_12|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_12|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_12|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_12|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_12|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_12|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_12|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_12|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|CRLA_12|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_13|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_13|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_13|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_13|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_13|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_13|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_13|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_13|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_13|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_13|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_13|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_13|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_13|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_13|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|NXLA_13|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_13|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_14|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_14|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_14|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_14|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_14|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_14|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_14|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_14|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_14|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_14|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_14|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_14|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|
||CHITVL_14|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|CHEXT_14|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_14|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_14|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||N0SA_15|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N0DA_15|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N0TB_15|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||N1SA_15|SA[31]|SA[30]|SA[29]|SA[28]|SA[27]|SA[26]|SA[25]|SA[24]|
|||SA[23]|SA[22]|SA[21]|SA[20]|SA[19]|SA[18]|SA[17]|SA[16]|
|||SA[15]|SA[14]|SA[13]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||N1DA_15|DA[31]|DA[30]|DA[29]|DA[28]|DA[27]|DA[26]|DA[25]|DA[24]|
|||DA[23]|DA[22]|DA[21]|DA[20]|DA[19]|DA[18]|DA[17]|DA[16]|
|||DA[15]|DA[14]|DA[13]|DA[12]|DA[11]|DA[10]|DA[9]|DA[8]|
|||DA[7]|DA[6]|DA[5]|DA[4]|DA[3]|DA[2]|DA[1]|DA[0]|
||N1TB_15|TB[31]|TB[30]|TB[29]|TB[28]|TB[27]|TB[26]|TB[25]|TB[24]|
|||TB[23]|TB[22]|TB[21]|TB[20]|TB[19]|TB[18]|TB[17]|TB[16]|
|||TB[15]|TB[14]|TB[13]|TB[12]|TB[11]|TB[10]|TB[9]|TB[8]|
|||TB[7]|TB[6]|TB[5]|TB[4]|TB[3]|TB[2]|TB[1]|TB[0]|
||CRSA_15|CRSA[31]|CRSA[30]|CRSA[29]|CRSA[28]|CRSA[27]|CRSA[26]|CRSA[25]|CRSA[24]|
|||CRSA[23]|CRSA[22]|CRSA[21]|CRSA[20]|CRSA[19]|CRSA[18]|CRSA[17]|CRSA[16]|
|||CRSA[15]|CRSA[14]|CRSA[13]|CRSA[12]|CRSA[11]|CRSA[10]|CRSA[9]|CRSA[8]|
|||CRSA[7]|CRSA[6]|CRSA[5]|CRSA[4]|CRSA[3]|CRSA[2]|CRSA[1]|CRSA[0]|
||CRDA_15|CRDA[31]|CRDA[30]|CRDA[29]|CRDA[28]|CRDA[27]|CRDA[26]|CRDA[25]|CRDA[24]|
|||CRDA[23]|CRDA[22]|CRDA[21]|CRDA[20]|CRDA[19]|CRDA[18]|CRDA[17]|CRDA[16]|
|||CRDA[15]|CRDA[14]|CRDA[13]|CRDA[12]|CRDA[11]|CRDA[10]|CRDA[9]|CRDA[8]|
|||CRDA[7]|CRDA[6]|CRDA[5]|CRDA[4]|CRDA[3]|CRDA[2]|CRDA[1]|CRDA[0]|
||CRTB_15|CRTB[31]|CRTB[30]|CRTB[29]|CRTB[28]|CRTB[27]|CRTB[26]|CRTB[25]|CRTB[24]|
|||CRTB[23]|CRTB[22]|CRTB[21]|CRTB[20]|CRTB[19]|CRTB[18]|CRTB[17]|CRTB[16]|
|||CRTB[15]|CRTB[14]|CRTB[13]|CRTB[12]|CRTB[11]|CRTB[10]|CRTB[9]|CRTB[8]|
|||CRTB[7]|CRTB[6]|CRTB[5]|CRTB[4]|CRTB[3]|CRTB[2]|CRTB[1]|CRTB[0]|
||CHSTAT_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTMSK|
|||-|-|-|-|MODE|DER|DW|DL|
|||SR|TC|END|ER|SUS|TACT|RQST|EN|
||CHCTRL_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|CLRINTMSK|SETINTMSK|
|||-|-|-|-|-|-|CLRSUS|SETSUS|
|||-|CLRTC|CLREND|CLRRQ|SWRST|STG|CLREN|SETEN|
||CHCFG_15|DMS|REN|RSW|RSEL|SBE|-|-|DEM|
|||-|TM|DAD|SAD|DDS[3]|DDS[2]|DDS[1]|DDS[0]|
|||SDS[3]|SDS[2]|SDS[1]|SDS[0]|-|AM[2]|AM[1]|AM[0]|
|||-|LVL|HIEN|LOEN|REQD|SEL[2]|SEL[1]|SEL[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|CHITVL_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ITVL[15]|ITVL[14]|ITVL[13]|ITVL[12]|ITVL[11]|ITVL[10]|ITVL[9]|ITVL[8]|
|||ITVL[7]|ITVL[6]|ITVL[5]|ITVL[4]|ITVL[3]|ITVL[2]|ITVL[1]|ITVL[0]|
||CHEXT_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DCA[3]|DCA[2]|DCA[1]|DCA[0]|-|-|-|-|
|||SCA[3]|SCA[2]|SCA[1]|SCA[0]|-|-|-|-|
||NXLA_15|NXLA[31]|NXLA[30]|NXLA[29]|NXLA[28]|NXLA[27]|NXLA[26]|NXLA[25]|NXLA[24]|
|||NXLA[23]|NXLA[22]|NXLA[21]|NXLA[20]|NXLA[19]|NXLA[18]|NXLA[17]|NXLA[16]|
|||NXLA[15]|NXLA[14]|NXLA[13]|NXLA[12]|NXLA[11]|NXLA[10]|NXLA[9]|NXLA[8]|
|||NXLA[7]|NXLA[6]|NXLA[5]|NXLA[4]|NXLA[3]|NXLA[2]|NXLA[1]|NXLA[0]|
||CRLA_15|CRLA[31]|CRLA[30]|CRLA[29]|CRLA[28]|CRLA[27]|CRLA[26]|CRLA[25]|CRLA[24]|
|||CRLA[23]|CRLA[22]|CRLA[21]|CRLA[20]|CRLA[19]|CRLA[18]|CRLA[17]|CRLA[16]|
|||CRLA[15]|CRLA[14]|CRLA[13]|CRLA[12]|CRLA[11]|CRLA[10]|CRLA[9]|CRLA[8]|
|||CRLA[7]|CRLA[6]|CRLA[5]|CRLA[4]|CRLA[3]|CRLA[2]|CRLA[1]|CRLA[0]|
||DCTRL_8_15|LWCA[3]|LWCA[2]|LWCA[1]|LWCA[0]|-|LWPR[2]|LWPR[1]|LWPR[0]|
|||LDCA[3]|LDCA[2]|LDCA[1]|LDCA[0]|-|LDPR[2]|LDPR[1]|LDPR[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|LVINT|PR|
||DSTAT_EN_8_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||EN15|EN14|EN13|EN12|EN11|EN10|EN9|EN8|
||DSTAT_ER_8_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ER15|ER14|ER13|ER12|ER11|ER10|ER9|ER8|
||DSTAT_END_8_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||END15|END14|END13|END12|END11|END10|END9|END8|
||DSTAT_TC_8_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TC15|TC14|TC13|TC12|TC11|TC10|TC9|TC8|
||DSTAT_SUS_8_15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SUS15|SUS14|SUS13|SUS12|SUS11|SUS10|SUS9|SUS8|
||DMARS0|-|-|-|-|-|-|-|CH1_MID[6]|
|||CH1_MID[5]|CH1_MID[4]|CH1_MID[3]|CH1_MID[2]|CH1_MID[1]|CH1_MID[0]|CH1_RID[1]|CH1_RID[0]|
|||-|-|-|-|-|-|-|CH0_MID[6]|
|||CH0_MID[5]|CH0_MID[4]|CH0_MID[3]|CH0_MID[2]|CH0_MID[1]|CH0_MID[0]|CH0_RID[1]|CH0_RID[0]|
||DMARS1|-|-|-|-|-|-|-|CH3_MID[6]|
|||CH3_MID[5]|CH3_MID[4]|CH3_MID[3]|CH3_MID[2]|CH3_MID[1]|CH3_MID[0]|CH3_RID[1]|CH3_RID[0]|
|||-|-|-|-|-|-|-|CH2_MID[6]|
|||CH2_MID[5]|CH2_MID[4]|CH2_MID[3]|CH2_MID[2]|CH2_MID[1]|CH2_MID[0]|CH2_RID[1]|CH2_RID[0]|
||DMARS2|-|-|-|-|-|-|-|CH5_MID[6]|
|||CH5_MID[5]|CH5_MID[4]|CH5_MID[3]|CH5_MID[2]|CH5_MID[1]|CH5_MID[0]|CH5_RID[1]|CH5_RID[0]|
|||-|-|-|-|-|-|-|CH4_MID[6]|
|||CH4_MID[5]|CH4_MID[4]|CH4_MID[3]|CH4_MID[2]|CH4_MID[1]|CH4_MID[0]|CH4_RID[1]|CH4_RID[0]|
||DMARS3|-|-|-|-|-|-|-|CH7_MID[6]|
|||CH7_MID[5]|CH7_MID[4]|CH7_MID[3]|CH7_MID[2]|CH7_MID[1]|CH7_MID[0]|CH7_RID[1]|CH7_RID[0]|
|||-|-|-|-|-|-|-|CH6_MID[6]|
|||CH6_MID[5]|CH6_MID[4]|CH6_MID[3]|CH6_MID[2]|CH6_MID[1]|CH6_MID[0]|CH6_RID[1]|CH6_RID[0]|
||DMARS4|-|-|-|-|-|-|-|CH9_MID[6]|
|||CH9_MID[5]|CH9_MID[4]|CH9_MID[3]|CH9_MID[2]|CH9_MID[1]|CH9_MID[0]|CH9_RID[1]|CH9_RID[0]|
|||-|-|-|-|-|-|-|CH8_MID[6]|
|||CH8_MID[5]|CH8_MID[4]|CH8_MID[3]|CH8_MID[2]|CH8_MID[1]|CH8_MID[0]|CH8_RID[1]|CH8_RID[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Direct memory<br>access controller|DMARS5|-|-|-|-|-|-|-|CH11_MID[6]|
|||CH11_MID[5]|CH11_MID[4]|CH11_MID[3]|CH11_MID[2]|CH11_MID[1]|CH11_MID[0]|CH11_RID[1]|CH11_RID[0]|
|||-|-|-|-|-|-|-|CH10_MID[6]|
|||CH10_MID[5]|CH10_MID[4]|CH10_MID[3]|CH10_MID[2]|CH10_MID[1]|CH10_MID[0]|CH10_RID[1]|CH10_RID[0]|
||DMARS6|-|-|-|-|-|-|-|CH13_MID[6]|
|||CH13_MID[5]|CH13_MID[4]|CH13_MID[3]|CH13_MID[2]|CH13_MID[1]|CH13_MID[0]|CH13_RID[1]|CH13_RID[0]|
|||-|-|-|-|-|-|-|CH12_MID[6]|
|||CH12_MID[5]|CH12_MID[4]|CH12_MID[3]|CH12_MID[2]|CH12_MID[1]|CH12_MID[0]|CH12_RID[1]|CH12_RID[0]|
||DMARS7|-|-|-|-|-|-|-|CH15_MID[6]|
|||CH15_MID[5]|CH15_MID[4]|CH15_MID[3]|CH15_MID[2]|CH15_MID[1]|CH15_MID[0]|CH15_RID[1]|CH15_RID[0]|
|||-|-|-|-|-|-|-|CH14_MID[6]|
|||CH14_MID[5]|CH14_MID[4]|CH14_MID[3]|CH14_MID[2]|CH14_MID[1]|CH14_MID[0]|CH14_RID[1]|CH14_RID[0]|
|Multi-function<br>timer pulse unit 2|TCR_0|CCLR[2]|CCLR[1]|CCLR[0]|CKEG[1]|CKEG[0]|TPSC[2]|TPSC[1]|TPSC[0]|
||TMDR_0|-|BFE|BFB|BFA|MD[3]|MD[2]|MD[1]|MD[0]|
||TIORH_0|IOB[3]|IOB[2]|IOB[1]|IOB[0]|IOA[3]|IOA[2]|IOA[1]|IOA[0]|
||TIORL_0|IOD[3]|IOD[2]|IOD[1]|IOD[0]|IOC[3]|IOC[2]|IOC[1]|IOC[0]|
||TIER_0|TTGE|-|-|TCIEV|TGIED|TGIEC|TGIEB|TGIEA|
||TSR_0|-|-|-|TCFV|TGFD|TGFC|TGFB|TGFA|
||TCNT_0|||||||||
|||||||||||
||TGRA_0|||||||||
|||||||||||
||TGRB_0|||||||||
|||||||||||
||TGRC_0|||||||||
|||||||||||
||TGRD_0|||||||||
|||||||||||
||TGRE_0|||||||||
|||||||||||
||TGRF_0|||||||||
|||||||||||
||TIER2_0|TTGE2|-|-|-|-|-|TGIEF|TGIEE|
||TSR2_0|-|-|-|-|-|-|TGFF|TGFE|
||TBTM_0|-|-|-|-|-|TTSE|TTSB|TTSA|
||TCR_1|-|CCLR[1]|CCLR[0]|CKEG[1]|CKEG[0]|TPSC[2]|TPSC[1]|TPSC[0]|
||TMDR_1|-|-|-|-|MD[3]|MD[2]|MD[1]|MD[0]|
||TIOR_1|IOB[3]|IOB[2]|IOB[1]|IOB[0]|IOA[3]|IOA[2]|IOA[1]|IOA[0]|
||TIER_1|TTGE|-|TCIEU|TCIEV|-|-|TGIEB|TGIEA|
||TSR_1|TCFD|-|TCFU|TCFV|-|-|TGFB|TGFA|
||TCNT_1|||||||||
|||||||||||
||TGRA_1|||||||||
|||||||||||
||TGRB_1|||||||||
|||||||||||
||TICCR|-|-|-|-|I2BE|I2AE|I1BE|I1AE|
||TCR_2|-|CCLR[1]|CCLR[0]|CKEG[1]|CKEG[0]|TPSC[2]|TPSC[1]|TPSC[0]|
||TMDR_2|-|-|-|-|MD[3]|MD[2]|MD[1]|MD[0]|
||TIOR_2|IOB[3]|IOB[2]|IOB[1]|IOB[0]|IOA[3]|IOA[2]|IOA[1]|IOA[0]|
||TIER_2|TTGE|-|TCIEU|TCIEV|-|-|TGIEB|TGIEA|
||TSR_2|TCFD|-|TCFU|TCFV|-|-|TGFB|TGFA|
||TCNT_2|||||||||
|||||||||||
||TGRA_2|||||||||
|||||||||||
||TGRB_2|||||||||
|||||||||||
||TCR_3|CCLR[2]|CCLR[1]|CCLR[0]|CKEG[1]|CKEG[0]|TPSC[2]|TPSC[1]|TPSC[0]|
||TMDR_3|-|-|BFB|BFA|MD[3]|MD[2]|MD[1]|MD[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Multi-function<br>timer pulse unit 2|TIORH_3|IOB[3]|IOB[2]|IOB[1]|IOB[0]|IOA[3]|IOA[2]|IOA[1]|IOA[0]|
||TIORL_3|IOD[3]|IOD[2]|IOD[1]|IOD[0]|IOC[3]|IOC[2]|IOC[1]|IOC[0]|
||TIER_3|TTGE|-|-|TCIEV|TGIED|TGIEC|TGIEB|TGIEA|
||TSR_3|TCFD|-|-|TCFV|TGFD|TGFC|TGFB|TGFA|
||TCNT_3|||||||||
|||||||||||
||TGRA_3|||||||||
|||||||||||
||TGRB_3|||||||||
|||||||||||
||TGRC_3|||||||||
|||||||||||
||TGRD_3|||||||||
|||||||||||
||TBTM_3|-|-|-|-|-|-|TTSB|TTSA|
||TCR_4|CCLR[2]|CCLR[1]|CCLR[0]|CKEG[1]|CKEG[0]|TPSC[2]|TPSC[1]|TPSC[0]|
||TMDR_4|-|-|BFB|BFA|MD[3]|MD[2]|MD[1]|MD[0]|
||TIORH_4|IOB[3]|IOB[2]|IOB[1]|IOB[0]|IOA[3]|IOA[2]|IOA[1]|IOA[0]|
||TIORL_4|IOD[3]|IOD[2]|IOD[1]|IOD[0]|IOC[3]|IOC[2]|IOC[1]|IOC[0]|
||TIER_4|TTGE|TTGE2|-|TCIEV|TGIED|TGIEC|TGIEB|TGIEA|
||TSR_4|TCFD|-|-|TCFV|TGFD|TGFC|TGFB|TGFA|
||TCNT_4|||||||||
|||||||||||
||TGRA_4|||||||||
|||||||||||
||TGRB_4|||||||||
|||||||||||
||TGRC_4|||||||||
|||||||||||
||TGRD_4|||||||||
|||||||||||
||TBTM_4|-|-|-|-|-|-|TTSB|TTSA|
||TADCR|BF[1]|BF[0]|-|-|-|-|-|-|
|||UT4AE|DT4AE|UT4BE|DT4BE|ITA3AE|ITA4VE|ITB3AE|ITB4VE|
||TADCORA_4|||||||||
|||||||||||
||TADCORB_4|||||||||
|||||||||||
||TADCOBRA_4|||||||||
|||||||||||
||TADCOBRB_4|||||||||
|||||||||||
||TSTR|CST4|CST3|-|-|-|CST2|CST1|CST0|
||TSYR|SYNC4|SYNC3|-|-|-|SYNC2|SYNC1|SYNC0|
||TRWER|-|-|-|-|-|-|-|RWE|
||TOER|-|-|OE4D|OE4C|OE3D|OE4B|OE4A|OE3B|
||TOCR1|-|PSYE|-|-|TOCL|TOCS|OLSN|OLSP|
||TOCR2|BF[1]|BF[0]|OLS3N|OLS3P|OLS2N|OLS2P|OLS1N|OLS1P|
||TGCR|-|BDC|N|P|FB|WF|VF|UF|
||TCDR|||||||||
|||||||||||
||TDDR|||||||||
|||||||||||
||TCNTS|||||||||
|||||||||||
||TCBR|||||||||
|||||||||||

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Multi-function<br>timer pulse unit 2|TITCR|T3AEN|3ACOR[2]|3ACOR[1]|3ACOR[0]|T4VEN|4VCOR[2]|4VCOR[1]|4VCOR[0]|
||TITCNT|-|3ACNT[2]|3ACNT[1]|3ACNT[0]|-|4VCNT[2]|4VCNT[1]|4VCNT[0]|
||TBTER|-|-|-|-|-|-|BTE[1]|BTE[0]|
||TDER|-|-|-|-|-|-|-|TDER|
||TWCR|CCE|-|-|-|-|-|-|WRE|
||TOLBR|-|-|OLS3N|OLS3P|OLS2N|OLS2P|OLS1N|OLS1P|
|OS timer|OSTM0CMP|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||OSTM0CNT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||OSTM0TE|-|-|-|-|-|-|-|OSTM0TE|
||OSTM0TS|-|-|-|-|-|-|-|OSTM0TS|
||OSTM0TT|-|-|-|-|-|-|-|OSTM0TT|
||OSTM0CTL|-|-|-|-|-|-|OSTM0MD1|OSTM0MD0|
||OSTM1CMP|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||OSTM1CNT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||OSTM1TE|-|-|-|-|-|-|-|OSTM1TE|
||OSTM1TS|-|-|-|-|-|-|-|OSTM1TS|
||OSTM1TT|-|-|-|-|-|-|-|OSTM1TT|
||OSTM1CTL|-|-|-|-|-|-|OSTM1MD1|OSTM1MD0|
|Watchdog timer|WTCNT|||||||||
||WTCSR|IOVF|WT/IT|TME|-|-|CKS[2]|CKS[1]|CKS[0]|
||WRCSR|WOVF|RSTE|-|-|-|-|-|-|
|Realtime clock|R64CNT|-|1Hz|2Hz|4Hz|8Hz|16Hz|32Hz|64Hz|
||RSECCNT|-|10 seconds[2]|10 seconds[1]|10 seconds[0]|1 second[3]|1 second[2]|1 second[1]|1 second[0]|
||RMINCNT|-|10 minutes[2]|10 minutes[1]|10 minutes[0]|1 minute[3]|1 minute[2]|1 minute[1]|1 minute[0]|
||RHRCNT|-|-|10 hours[1]|10 hours[0]|1 hour[3]|1 hour[2]|1 hour[1]|1 hour[0]|
||RWKCNT|-|-|-|-|-|Day[2]|Day[1]|Day[0]|
||RDAYCNT|-|-|10 days[1]|10 days[0]|1 day[3]|1 day[2]|1 day[1]|1 day[0]|
||RMONCNT|-|-|-|10  months|1 month[3]|1 month[2]|1 month[1]|1 month[0]|
||RYRCNT|1000 years[3]|1000 years[2]|1000 years[1]|1000 years[0]|100 years[3]|100 years[2]|100 years[1]|100 years[0]|
|||10 years[3]|10 years[2]|10 years[1]|10 years[0]|1 year[3]|1 year[2]|1 year[1]|1 year[0]|
||RSECAR|ENB|10 seconds[2]|10 seconds[1]|10 seconds[0]|1 second[3]|1 second[2]|1 second[1]|1 second[0]|
||RMINAR|ENB|10 minutes[2]|10 minutes[1]|10 minutes[0]|1 minute[3]|1 minute[2]|1 minute[1]|1 minute[0]|
||RHRAR|ENB|-|10 hours[1]|10 hours[0]|1 hour[3]|1 hour[2]|1 hour[1]|1 hour[0]|
||RWKAR|ENB|-|-|-|-|Day[2]|Day[1]|Day[0]|
||RDAYAR|ENB|-|10 days[1]|10 days[0]|1 day[3]|1 day[2]|1 day[1]|1 day[0]|
||RMONAR|ENB|-|-|10  months|1 month[3]|1 month[2]|1 month[1]|1 month[0]|
||RYRAR|1000 years[3]|1000 years[2]|1000 years[1]|1000 years[0]|100 years[3]|100 years[2]|100 years[1]|100 years[0]|
|||10 years[3]|10 years[2]|10 years[1]|10 years[0]|1 year[3]|1 year[2]|1 year[1]|1 year[0]|
||RCR1|CF|-|-|CIE|AIE|-|-|AF|
||RCR2|PEF|PES[2]|PES[1]|PES[0]|RTCEN|ADJ|RESET|START|
||RCR3|ENB|-|-|-|-|-|-|-|
||RCR5|-|-|-|-|-|-|RCKSEL[1]|RCKSEL[0]|
||RFRH|SEL64|-|-|-|-|-|-|-|
|||-|-|-|-|-|RFC[18]|RFC[17]|RFC[16]|
||RFRL|RFC[15]|RFC[14]|RFC[13]|RFC[12]|RFC[11]|RFC[10]|RFC[9]|RFC[8]|
|||RFC[7]|RFC[6]|RFC[5]|RFC[4]|RFC[3]|RFC[2]|RFC[1]|RFC[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Serial<br>communication<br>interface with FIFO|SCSMR_0|-|-|-|-|-|-|-|-|
|||C/A|CHR|PE|O/E|STOP|-|CKS[1]|CKS[0]|
||SCBRR_0|||||||||
||SCSCR_0|-|-|-|-|-|-|-|-|
|||TIE|RIE|TE|RE|REIE|-|CKE[1]|CKE[0]|
||SCFTDR_0|||||||||
||SCFSR_0|PER[3]|PER[2]|PER[1]|PER[0]|FER[3]|FER[2]|FER[1]|FER[0]|
|||ER|TEND|TDFE|BRK|FER|PER|RDF|DR|
||SCFRDR_0|||||||||
||SCFCR_0|-|-|-|-|-|RSTRG[2]|RSTRG[1]|RSTRG[0]|
|||RTRG[1]|RTRG[0]|TTRG[1]|TTRG[0]|MCE|TFRST|RFRST|LOOP|
||SCFDR_0|-|-|-|T[4]|T[3]|T[2]|T[1]|T[0]|
|||-|-|-|R[4]|R[3]|R[2]|R[1]|R[0]|
||SCSPTR_0|-|-|-|-|-|-|-|-|
|||RTSIO|RTSDT|CTSIO|CTSDT|SCKIO|SCKDT|SPB2IO|SPB2DT|
||SCLSR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ORER|
||SCEMR_0|-|-|-|-|-|-|-|-|
|||BGDM|-|-|-|-|-|-|ABCS|
||SCSMR_1|-|-|-|-|-|-|-|-|
|||C/A|CHR|PE|O/E|STOP|-|CKS[1]|CKS[0]|
||SCBRR_1|||||||||
||SCSCR_1|-|-|-|-|-|-|-|-|
|||TIE|RIE|TE|RE|REIE|-|CKE[1]|CKE[0]|
||SCFTDR_1|||||||||
||SCFSR_1|PER[3]|PER[2]|PER[1]|PER[0]|FER[3]|FER[2]|FER[1]|FER[0]|
|||ER|TEND|TDFE|BRK|FER|PER|RDF|DR|
||SCFRDR_1|||||||||
||SCFCR_1|-|-|-|-|-|RSTRG[2]|RSTRG[1]|RSTRG[0]|
|||RTRG[1]|RTRG[0]|TTRG[1]|TTRG[0]|MCE|TFRST|RFRST|LOOP|
||SCFDR_1|-|-|-|T[4]|T[3]|T[2]|T[1]|T[0]|
|||-|-|-|R[4]|R[3]|R[2]|R[1]|R[0]|
||SCSPTR_1|-|-|-|-|-|-|-|-|
|||RTSIO|RTSDT|CTSIO|CTSDT|SCKIO|SCKDT|SPB2IO|SPB2DT|
||SCLSR_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ORER|
||SCEMR_1|-|-|-|-|-|-|-|-|
|||BGDM|-|-|-|-|-|-|ABCS|
||SCSMR_2|-|-|-|-|-|-|-|-|
|||C/A|CHR|PE|O/E|STOP|-|CKS[1]|CKS[0]|
||SCBRR_2|||||||||
||SCSCR_2|-|-|-|-|-|-|-|-|
|||TIE|RIE|TE|RE|REIE|-|CKE[1]|CKE[0]|
||SCFTDR_2|||||||||
||SCFSR_2|PER[3]|PER[2]|PER[1]|PER[0]|FER[3]|FER[2]|FER[1]|FER[0]|
|||ER|TEND|TDFE|BRK|FER|PER|RDF|DR|
||SCFRDR_2|||||||||
||SCFCR_2|-|-|-|-|-|RSTRG[2]|RSTRG[1]|RSTRG[0]|
|||RTRG[1]|RTRG[0]|TTRG[1]|TTRG[0]|MCE|TFRST|RFRST|LOOP|
||SCFDR_2|-|-|-|T[4]|T[3]|T[2]|T[1]|T[0]|
|||-|-|-|R[4]|R[3]|R[2]|R[1]|R[0]|
||SCSPTR_2|-|-|-|-|-|-|-|-|
|||RTSIO|RTSDT|CTSIO|CTSDT|SCKIO|SCKDT|SPB2IO|SPB2DT|
||SCLSR_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ORER|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Serial<br>communication<br>interface with FIFO|SCEMR_2|-|-|-|-|-|-|-|-|
|||BGDM|-|-|-|-|-|-|ABCS|
||SCSMR_3|-|-|-|-|-|-|-|-|
|||C/A|CHR|PE|O/E|STOP|-|CKS[1]|CKS[0]|
||SCBRR_3|||||||||
||SCSCR_3|-|-|-|-|-|-|-|-|
|||TIE|RIE|TE|RE|REIE|-|CKE[1]|CKE[0]|
||SCFTDR_3|||||||||
||SCFSR_3|PER[3]|PER[2]|PER[1]|PER[0]|FER[3]|FER[2]|FER[1]|FER[0]|
|||ER|TEND|TDFE|BRK|FER|PER|RDF|DR|
||SCFRDR_3|||||||||
||SCFCR_3|-|-|-|-|-|RSTRG[2]|RSTRG[1]|RSTRG[0]|
|||RTRG[1]|RTRG[0]|TTRG[1]|TTRG[0]|MCE|TFRST|RFRST|LOOP|
||SCFDR_3|-|-|-|T[4]|T[3]|T[2]|T[1]|T[0]|
|||-|-|-|R[4]|R[3]|R[2]|R[1]|R[0]|
||SCSPTR_3|-|-|-|-|-|-|-|-|
|||RTSIO|RTSDT|CTSIO|CTSDT|SCKIO|SCKDT|SPB2IO|SPB2DT|
||SCLSR_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ORER|
||SCEMR_3|-|-|-|-|-|-|-|-|
|||BGDM|-|-|-|-|-|-|ABCS|
||SCSMR_4|-|-|-|-|-|-|-|-|
|||C/A|CHR|PE|O/E|STOP|-|CKS[1]|CKS[0]|
||SCBRR_4|||||||||
||SCSCR_4|-|-|-|-|-|-|-|-|
|||TIE|RIE|TE|RE|REIE|-|CKE[1]|CKE[0]|
||SCFTDR_4|||||||||
||SCFSR_4|PER[3]|PER[2]|PER[1]|PER[0]|FER[3]|FER[2]|FER[1]|FER[0]|
|||ER|TEND|TDFE|BRK|FER|PER|RDF|DR|
||SCFRDR_4|||||||||
||SCFCR_4|-|-|-|-|-|RSTRG[2]|RSTRG[1]|RSTRG[0]|
|||RTRG[1]|RTRG[0]|TTRG[1]|TTRG[0]|MCE|TFRST|RFRST|LOOP|
||SCFDR_4|-|-|-|T[4]|T[3]|T[2]|T[1]|T[0]|
|||-|-|-|R[4]|R[3]|R[2]|R[1]|R[0]|
||SCSPTR_4|-|-|-|-|-|-|-|-|
|||RTSIO|RTSDT|CTSIO|CTSDT|SCKIO|SCKDT|SPB2IO|SPB2DT|
||SCLSR_4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ORER|
||SCEMR_4|-|-|-|-|-|-|-|-|
|||BGDM|-|-|-|-|-|-|ABCS|
|Serial<br>communications<br>interface|SMR0|CM|CHR|PE|PM|STOP|MP|CKS[1]|CKS[0]|
||SMR0|GM|BLK|PE|PM|BCP[1]|BCP[0]|CKS[1]|CKS[0]|
||BRR0|BRR[7]|BRR[6]|BRR[5]|BRR[4]|BRR[3]|BRR[2]|BRR[1]|BRR[0]|
||SCR0|TIE|RIE|TE|RE|MPIE|TEIE|CKE[1]|CKE[0]|
||TDR0|TDR[7]|TDR[6]|TDR[5]|TDR[4]|TDR[3]|TDR[2]|TDR[1]|TDR[0]|
||SSR0|-|-|ORER|FER|PER|TEND|MPB|MPBT|
||SSR0|-|-|ORER|ERS|PER|TEND|MPB|MPBT|
||RDR0|RDR[7]|RDR[6]|RDR[5]|RDR[4]|RDR[3]|RDR[2]|RDR[1]|RDR[0]|
||SCMR0|BCP2|-|-|-|SDIR|SINV|-|SMIF|
||SEMR0|-|-|NFEN|ABCS|-|-|-|-|
||SNFR0|-|-|-|-|-|NFCS[2]|NFCS[1]|NFCS[0]|
||SECR0|-|-|-|-|-|-|CTSE|-|
||SMR1|CM|CHR|PE|PM|STOP|MP|CKS[1]|CKS[0]|
||SMR1|GM|BLK|PE|PM|BCP[1]|BCP[0]|CKS[1]|CKS[0]|
||BRR1|BRR[7]|BRR[6]|BRR[5]|BRR[4]|BRR[3]|BRR[2]|BRR[1]|BRR[0]|
||SCR1|TIE|RIE|TE|RE|MPIE|TEIE|CKE[1]|CKE[0]|
||TDR1|TDR[7]|TDR[6]|TDR[5]|TDR[4]|TDR[3]|TDR[2]|TDR[1]|TDR[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Serial<br>communications<br>interface|SSR1|-|-|ORER|FER|PER|TEND|MPB|MPBT|
||SSR1|-|-|ORER|ERS|PER|TEND|MPB|MPBT|
||RDR1|RDR[7]|RDR[6]|RDR[5]|RDR[4]|RDR[3]|RDR[2]|RDR[1]|RDR[0]|
||SCMR1|BCP2|-|-|-|SDIR|SINV|-|SMIF|
||SEMR1|-|-|NFEN|ABCS|-|-|-|-|
||SNFR1|-|-|-|-|-|NFCS[2]|NFCS[1]|NFCS[0]|
||SECR1|-|-|-|-|-|-|CTSE|-|
||IRCR|IRE|IRCKS[2]|IRCKS[1]|IRCKS[0]|IRTXINV|IRRXINV|-|-|
|Renesas serial<br>peripheral<br>interface|SPCR_0|SPRIE|SPE|SPTIE|SPEIE|MSTR|MODFEN|-|-|
||SSLP_0|-|-|-|-|-|-|-|SSL0P|
||SPPCR_0|-|-|MOIFE|MOIFV|-|-|-|SPLP|
||SPSR_0|SPRF|TEND|SPTEF|-|-|MODF|-|OVRF|
||SPDR_0|SPD31|SPD30|SPD29|SPD28|SPD27|SPD26|SPD25|SPD24|
|||SPD23|SPD22|SPD21|SPD20|SPD19|SPD18|SPD17|SPD16|
|||SPD15|SPD14|SPD13|SPD12|SPD11|SPD10|SPD9|SPD8|
|||SPD7|SPD6|SPD5|SPD4|SPD3|SPD2|SPD1|SPD0|
||SPSCR_0|-|-|-|-|-|-|SPSLN1|SPSLN0|
||SPSSR_0|-|-|-|-|-|-|SPCP1|SPCP0|
||SPBR_0|SPR7|SPR6|SPR5|SPR4|SPR3|SPR2|SPR1|SPR0|
||SPDCR_0|TXDMY|SPLW1|SPLW0|-|-|-|-|-|
||SPCKD_0|-|-|-|-|-|SCKDL2|SCKDL1|SCKDL0|
||SSLND_0|-|-|-|-|-|SLNDL2|SLNDL1|SLNDL0|
||SPND_0|-|-|-|-|-|SPNDL2|SPNDL1|SPNDL0|
||SPCMD0_0|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD1_0|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD2_0|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD3_0|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPBFCR_0|TXRST|RXRST|TXTRG[1]|TXTRG[0]|-|RXTRG[2]|RXTRG[1]|RXTRG[0]|
||SPBFDR_0|-|-|-|-|T[3]|T[2]|T[1]|T[0]|
|||-|-|R[5]|R[4]|R[3]|R[2]|R[1]|R[0]|
||SPCR_1|SPRIE|SPE|SPTIE|SPEIE|MSTR|MODFEN|-|-|
||SSLP_1|-|-|-|-|-|-|-|SSL0P|
||SPPCR_1|-|-|MOIFE|MOIFV|-|-|-|SPLP|
||SPSR_1|SPRF|TEND|SPTEF|-|-|MODF|-|OVRF|
||SPDR_1|SPD31|SPD30|SPD29|SPD28|SPD27|SPD26|SPD25|SPD24|
|||SPD23|SPD22|SPD21|SPD20|SPD19|SPD18|SPD17|SPD16|
|||SPD15|SPD14|SPD13|SPD12|SPD11|SPD10|SPD9|SPD8|
|||SPD7|SPD6|SPD5|SPD4|SPD3|SPD2|SPD1|SPD0|
||SPSCR_1|-|-|-|-|-|-|SPSLN1|SPSLN0|
||SPSSR_1|-|-|-|-|-|-|SPCP1|SPCP0|
||SPBR_1|SPR7|SPR6|SPR5|SPR4|SPR3|SPR2|SPR1|SPR0|
||SPDCR_1|TXDMY|SPLW1|SPLW0|-|-|-|-|-|
||SPCKD_1|-|-|-|-|-|SCKDL2|SCKDL1|SCKDL0|
||SSLND_1|-|-|-|-|-|SLNDL2|SLNDL1|SLNDL0|
||SPND_1|-|-|-|-|-|SPNDL2|SPNDL1|SPNDL0|
||SPCMD0_1|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD1_1|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD2_1|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD3_1|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPBFCR_1|TXRST|RXRST|TXTRG[1]|TXTRG[0]|-|RXTRG[2]|RXTRG[1]|RXTRG[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Renesas serial<br>peripheral<br>interface|SPBFDR_1|-|-|-|-|T[3]|T[2]|T[1]|T[0]|
|||-|-|R[5]|R[4]|R[3]|R[2]|R[1]|R[0]|
||SPCR_2|SPRIE|SPE|SPTIE|SPEIE|MSTR|MODFEN|-|-|
||SSLP_2|-|-|-|-|-|-|-|SSL0P|
||SPPCR_2|-|-|MOIFE|MOIFV|-|-|-|SPLP|
||SPSR_2|SPRF|TEND|SPTEF|-|-|MODF|-|OVRF|
||SPDR_2|SPD31|SPD30|SPD29|SPD28|SPD27|SPD26|SPD25|SPD24|
|||SPD23|SPD22|SPD21|SPD20|SPD19|SPD18|SPD17|SPD16|
|||SPD15|SPD14|SPD13|SPD12|SPD11|SPD10|SPD9|SPD8|
|||SPD7|SPD6|SPD5|SPD4|SPD3|SPD2|SPD1|SPD0|
||SPSCR_2|-|-|-|-|-|-|SPSLN1|SPSLN0|
||SPSSR_2|-|-|-|-|-|-|SPCP1|SPCP0|
||SPBR_2|SPR7|SPR6|SPR5|SPR4|SPR3|SPR2|SPR1|SPR0|
||SPDCR_2|TXDMY|SPLW1|SPLW0|-|-|-|-|-|
||SPCKD_2|-|-|-|-|-|SCKDL2|SCKDL1|SCKDL0|
||SSLND_2|-|-|-|-|-|SLNDL2|SLNDL1|SLNDL0|
||SPND_2|-|-|-|-|-|SPNDL2|SPNDL1|SPNDL0|
||SPCMD0_2|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD1_2|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD2_2|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPCMD3_2|SCKDEN|SLNDEN|SPNDEN|LSBF|SPB3|SPB2|SPB1|SPB0|
|||SSLKP|-|-|-|BRDV1|BRDV0|CPOL|CPHA|
||SPBFCR_2|TXRST|RXRST|TXTRG[1]|TXTRG[0]|-|RXTRG[2]|RXTRG[1]|RXTRG[0]|
||SPBFDR_2|-|-|-|-|T[3]|T[2]|T[1]|T[0]|
|||-|-|R[5]|R[4]|R[3]|R[2]|R[1]|R[0]|
|SPI multi I/O bus<br>controller|CMNCR_0|MD|-|-|-|-|-|-|SFDE|
|||MOIIO3[1]|MOIIO3[0]|MOIIO2[1]|MOIIO2[0]|MOIIO1[1]|MOIIO1[0]|MOIIO0[1]|MOIIO0[0]|
|||IO3FV[1]|IO3FV[0]|IO2FV[1]|IO2FV[0]|-|-|IO0FV[1]|IO0FV[0]|
|||-|CPHAT|CPHAR|SSLP|CPOL|-|BSZ[1]|BSZ[0]|
||SSLDR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|SPNDL[2]|SPNDL[1]|SPNDL[0]|
|||-|-|-|-|-|SLNDL[2]|SLNDL[1]|SLNDL[0]|
|||-|-|-|-|-|SCKDL[2]|SCKDL[1]|SCKDL[0]|
||SPBCR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SPBR[7]|SPBR[6]|SPBR[5]|SPBR[4]|SPBR[3]|SPBR[2]|SPBR[1]|SPBR[0]|
|||-|-|-|-|-|-|BRDV[1]|BRDV[0]|
||DRCR_0|-|-|-|-|-|-|-|SSLN|
|||-|-|-|-|RBURST[3]|RBURST[2]|RBURST[1]|RBURST[0]|
|||-|-|-|-|-|-|RCF|RBE|
|||-|-|-|-|-|-|-|SSLE|
||DRCMR_0|-|-|-|-|-|-|-|-|
|||CMD[7]|CMD[6]|CMD[5]|CMD[4]|CMD[3]|CMD[2]|CMD[1]|CMD[0]|
|||-|-|-|-|-|-|-|-|
|||OCMD[7]|OCMD[6]|OCMD[5]|OCMD[4]|OCMD[3]|OCMD[2]|OCMD[1]|OCMD[0]|
||DREAR_0|-|-|-|-|-|-|-|-|
|||EAV[7]|EAV[6]|EAV[5]|EAV[4]|EAV[3]|EAV[2]|EAV[1]|EAV[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|EAC[2]|EAC[1]|EAC[0]|
||DROPR_0|OPD3[7]|OPD3[6]|OPD3[5]|OPD3[4]|OPD3[3]|OPD3[2]|OPD3[1]|OPD3[0]|
|||OPD2[7]|OPD2[6]|OPD2[5]|OPD2[4]|OPD2[3]|OPD2[2]|OPD2[1]|OPD2[0]|
|||OPD1[7]|OPD1[6]|OPD1[5]|OPD1[4]|OPD1[3]|OPD1[2]|OPD1[1]|OPD1[0]|
|||OPD0[7]|OPD0[6]|OPD0[5]|OPD0[4]|OPD0[3]|OPD0[2]|OPD0[1]|OPD0[0]|
||DRENR_0|CDB[1]|CDB[0]|OCDB[1]|OCDB[0]|-|-|ADB[1]|ADB[0]|
|||-|-|OPDB[1]|OPDB[0]|-|-|DRDB[1]|DRDB[0]|
|||DME|CDE|-|OCDE|ADE[3]|ADE[2]|ADE[1]|ADE[0]|
|||OPDE[3]|OPDE[2]|OPDE[1]|OPDE[0]|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SPI multi I/O bus<br>controller|SMCR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SSLKP|
|||-|-|-|-|-|SPIRE|SPIWE|SPIE|
||SMCMR_0|-|-|-|-|-|-|-|-|
|||CMD[7]|CMD[6]|CMD[5]|CMD[4]|CMD[3]|CMD[2]|CMD[1]|CMD[0]|
|||-|-|-|-|-|-|-|-|
|||OCMD[7]|OCMD[6]|OCMD[5]|OCMD[4]|OCMD[3]|OCMD[2]|OCMD[1]|OCMD[0]|
||SMADR_0|ADR[31]|ADR[30]|ADR[29]|ADR[28]|ADR[27]|ADR[26]|ADR[25]|ADR[24]|
|||ADR[23]|ADR[22]|ADR[21]|ADR[20]|ADR[19]|ADR[18]|ADR[17]|ADR[16]|
|||ADR[15]|ADR[14]|ADR[13]|ADR[12]|ADR[11]|ADR[10]|ADR[9]|ADR[8]|
|||ADR[7]|ADR[6]|ADR[5]|ADR[4]|ADR[3]|ADR[2]|ADR[1]|ADR[0]|
||SMOPR_0|OPD3[7]|OPD3[6]|OPD3[5]|OPD3[4]|OPD3[3]|OPD3[2]|OPD3[1]|OPD3[0]|
|||OPD2[7]|OPD2[6]|OPD2[5]|OPD2[4]|OPD2[3]|OPD2[2]|OPD2[1]|OPD2[0]|
|||OPD1[7]|OPD1[6]|OPD1[5]|OPD1[4]|OPD1[3]|OPD1[2]|OPD1[1]|OPD1[0]|
|||OPD0[7]|OPD0[6]|OPD0[5]|OPD0[4]|OPD0[3]|OPD0[2]|OPD0[1]|OPD0[0]|
||SMENR_0|CDB[1]|CDB[0]|OCDB[1]|OCDB[0]|-|-|ADB[1]|ADB[0]|
|||-|-|OPDB[1]|OPDB[0]|-|-|SPIDB[1]|SPIDB[0]|
|||DME|CDE|-|OCDE|ADE[3]|ADE[2]|ADE[1]|ADE[0]|
|||OPDE[3]|OPDE[2]|OPDE[1]|OPDE[0]|SPIDE[3]|SPIDE[2]|SPIDE[1]|SPIDE[0]|
||SMRDR0_0|RDATA0[31]|RDATA0[30]|RDATA0[29]|RDATA0[28]|RDATA0[27]|RDATA0[26]|RDATA0[25]|RDATA0[24]|
|||RDATA0[23]|RDATA0[22]|RDATA0[21]|RDATA0[20]|RDATA0[19]|RDATA0[18]|RDATA0[17]|RDATA0[16]|
|||RDATA0[15]|RDATA0[14]|RDATA0[13]|RDATA0[12]|RDATA0[11]|RDATA0[10]|RDATA0[9]|RDATA0[8]|
|||RDATA0[7]|RDATA0[6]|RDATA0[5]|RDATA0[4]|RDATA0[3]|RDATA0[2]|RDATA0[1]|RDATA0[0]|
||SMRDR1_0|RDATA1[31]|RDATA1[30]|RDATA1[29]|RDATA1[28]|RDATA1[27]|RDATA1[26]|RDATA1[25]|RDATA1[24]|
|||RDATA1[23]|RDATA1[22]|RDATA1[21]|RDATA1[20]|RDATA1[19]|RDATA1[18]|RDATA1[17]|RDATA1[16]|
|||RDATA1[15]|RDATA1[14]|RDATA1[13]|RDATA1[12]|RDATA1[11]|RDATA1[10]|RDATA1[9]|RDATA1[8]|
|||RDATA1[7]|RDATA1[6]|RDATA1[5]|RDATA1[4]|RDATA1[3]|RDATA1[2]|RDATA1[1]|RDATA1[0]|
||SMWDR0_0|WDATA0[31]|WDATA0[30]|WDATA0[29]|WDATA0[28]|WDATA0[27]|WDATA0[26]|WDATA0[25]|WDATA0[24]|
|||WDATA0[23]|WDATA0[22]|WDATA0[21]|WDATA0[20]|WDATA0[19]|WDATA0[18]|WDATA0[17]|WDATA0[16]|
|||WDATA0[15]|WDATA0[14]|WDATA0[13]|WDATA0[12]|WDATA0[11]|WDATA0[10]|WDATA0[9]|WDATA0[8]|
|||WDATA0[7]|WDATA0[6]|WDATA0[5]|WDATA0[4]|WDATA0[3]|WDATA0[2]|WDATA0[1]|WDATA0[0]|
||SMWDR1_0|WDATA1[31]|WDATA1[30]|WDATA1[29]|WDATA1[28]|WDATA1[27]|WDATA1[26]|WDATA1[25]|WDATA1[24]|
|||WDATA1[23]|WDATA1[22]|WDATA1[21]|WDATA1[20]|WDATA1[19]|WDATA1[18]|WDATA1[17]|WDATA1[16]|
|||WDATA1[15]|WDATA1[14]|WDATA1[13]|WDATA1[12]|WDATA1[11]|WDATA1[10]|WDATA1[9]|WDATA1[8]|
|||WDATA1[7]|WDATA1[6]|WDATA1[5]|WDATA1[4]|WDATA1[3]|WDATA1[2]|WDATA1[1]|WDATA1[0]|
||CMNSR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|SSLF|TEND|
||CKDLY_0*2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||GB[7]|GB[6]|GB[5]|GB[4]|GB[3]|GB[2]|GB[1]|GB[0]|
|||||||CKDLY[3]|CKDLY[2]|CKDLY[1]|CKDLY[0]|
||DRDMCR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|DMDB[1]|DMDB[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|DMCYC[2]|DMCYC[1]|DMCYC[0]|
||DRDRENR_0*2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ADDRE|
|||-|-|-|OPDRE|-|-|-|DRDRE|
||SMDMCR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|DMDB[1]|DMDB[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|DMCYC[2]|DMCYC[1]|DMCYC[0]|
||SMDRENR_0*2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ADDRE|
|||-|-|-|OPDRE|-|-|-|SPIDRE|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SPI multi I/O bus<br>controller|SPODLY_0*2|GB[7]|GB[6]|GB[5]|GB[4]|GB[3]|GB[2]|GB[1]|GB[0]|
|||-|-|-|-|-|-|-|-|
|||SPODLY[15]|SPODLY[14]|SPODLY[13]|SPODLY[12]|SPODLY[11]|SPODLY[10]|SPODLY[9]|SPODLY[8]|
|||SPODLY[7]|SPODLY[6]|SPODLY[5]|SPODLY[4]|SPODLY[3]|SPODLY[2]|SPODLY[1]|SPODLY[0]|
|I2C bus interface|RIIC0CR1|ICE|IICRST|CLO|SOWP|SCLO|SDAO|SCLI|SDAI|
||RIIC0CR2|BBSY|MST|TRS|-|SP|RS|ST|-|
||RIIC0MR1|-|CKS[2]|CKS[1]|CKS[0]|BCWP|BC[2]|BC[1]|BC[0]|
||RIIC0MR2|DLCS|SDDL[2]|SDDL[1]|SDDL[0]|-|TMOH|TMOL|TMOS|
||RIIC0MR3|SMBE|WAIT|RDRFS|ACKWP|ACKBT|ACKBR|NF[1]|NF[0]|
||RIIC0FER|-|SCLE|NFE|NACKE|SALE|NALE|MALE|TMOE|
||RIIC0SER|HOAE|-|DIDE|-|GCE|SAR2|SAR1|SAR0|
||RIIC0IER|TIE|TEIE|RIE|NAKIE|SPIE|STIE|ALIE|TMOIE|
||RIIC0SR1|HOA|-|DID|-|GCA|AAS2|AAS1|AAS0|
||RIIC0SR2|TDRE|TEND|RDRF|NACKF|STOP|START|AL|TMOF|
||RIIC0SAR0|FS0|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|

**Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|I2C bus interface|RIIC0SAR1|FS1|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC0SAR2|FS2|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC0BRL|-|-|-|BRL[4]|BRL[3]|BRL[2]|BRL[1]|BRL[0]|
||RIIC0BRH|-|-|-|BRH[4]|BRH[3]|BRH[2]|BRH[1]|BRH[0]|
||RIIC0DRT|DRT[7]|DRT[6]|DRT[5]|DRT[4]|DRT[3]|DRT[2]|DRT[1]|DRT[0]|
||RIIC0DRR|DRR[7]|DRR[6]|DRR[5]|DRR[4]|DRR[3]|DRR[2]|DRR[1]|DRR[0]|
||RIIC1CR1|ICE|IICRST|CLO|SOWP|SCLO|SDAO|SCLI|SDAI|
||RIIC1CR2|BBSY|MST|TRS|-|SP|RS|ST|-|
||RIIC1MR1|-|CKS[2]|CKS[1]|CKS[0]|BCWP|BC[2]|BC[1]|BC[0]|
||RIIC1MR2|DLCS|SDDL[2]|SDDL[1]|SDDL[0]|-|TMOH|TMOL|TMOS|
||RIIC1MR3|SMBE|WAIT|RDRFS|ACKWP|ACKBT|ACKBR|NF[1]|NF[0]|
||RIIC1FER|-|SCLE|NFE|NACKE|SALE|NALE|MALE|TMOE|
||RIIC1SER|HOAE|-|DIDE|-|GCE|SAR2|SAR1|SAR0|
||RIIC1IER|TIE|TEIE|RIE|NAKIE|SPIE|STIE|ALIE|TMOIE|
||RIIC1SR1|HOA|-|DID|-|GCA|AAS2|AAS1|AAS0|
||RIIC1SR2|TDRE|TEND|RDRF|NACKF|STOP|START|AL|TMOF|
||RIIC1SAR0|FS0|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC1SAR1|FS1|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC1SAR2|FS2|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC1BRL|-|-|-|BRL[4]|BRL[3]|BRL[2]|BRL[1]|BRL[0]|
||RIIC1BRH|-|-|-|BRH[4]|BRH[3]|BRH[2]|BRH[1]|BRH[0]|
||RIIC1DRT|DRT[7]|DRT[6]|DRT[5]|DRT[4]|DRT[3]|DRT[2]|DRT[1]|DRT[0]|
||RIIC1DRR|DRR[7]|DRR[6]|DRR[5]|DRR[4]|DRR[3]|DRR[2]|DRR[1]|DRR[0]|
||RIIC2CR1|ICE|IICRST|CLO|SOWP|SCLO|SDAO|SCLI|SDAI|
||RIIC2CR2|BBSY|MST|TRS|-|SP|RS|ST|-|
||RIIC2MR1|-|CKS[2]|CKS[1]|CKS[0]|BCWP|BC[2]|BC[1]|BC[0]|
||RIIC2MR2|DLCS|SDDL[2]|SDDL[1]|SDDL[0]|-|TMOH|TMOL|TMOS|
||RIIC2MR3|SMBE|WAIT|RDRFS|ACKWP|ACKBT|ACKBR|NF[1]|NF[0]|
||RIIC2FER|-|SCLE|NFE|NACKE|SALE|NALE|MALE|TMOE|
||RIIC2SER|HOAE|-|DIDE|-|GCE|SAR2|SAR1|SAR0|
||RIIC2IER|TIE|TEIE|RIE|NAKIE|SPIE|STIE|ALIE|TMOIE|
||RIIC2SR1|HOA|-|DID|-|GCA|AAS2|AAS1|AAS0|
||RIIC2SR2|TDRE|TEND|RDRF|NACKF|STOP|START|AL|TMOF|
||RIIC2SAR0|FS0|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC2SAR1|FS1|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC2SAR2|FS2|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC2BRL|-|-|-|BRL[4]|BRL[3]|BRL[2]|BRL[1]|BRL[0]|
||RIIC2BRH|-|-|-|BRH[4]|BRH[3]|BRH[2]|BRH[1]|BRH[0]|
||RIIC2DRT|DRT[7]|DRT[6]|DRT[5]|DRT[4]|DRT[3]|DRT[2]|DRT[1]|DRT[0]|
||RIIC2DRR|DRR[7]|DRR[6]|DRR[5]|DRR[4]|DRR[3]|DRR[2]|DRR[1]|DRR[0]|
||RIIC3CR1|ICE|IICRST|CLO|SOWP|SCLO|SDAO|SCLI|SDAI|
||RIIC3CR2|BBSY|MST|TRS|-|SP|RS|ST|-|
||RIIC3MR1|-|CKS[2]|CKS[1]|CKS[0]|BCWP|BC[2]|BC[1]|BC[0]|
||RIIC3MR2|DLCS|SDDL[2]|SDDL[1]|SDDL[0]|-|TMOH|TMOL|TMOS|
||RIIC3MR3|SMBE|WAIT|RDRFS|ACKWP|ACKBT|ACKBR|NF[1]|NF[0]|
||RIIC3FER|-|SCLE|NFE|NACKE|SALE|NALE|MALE|TMOE|
||RIIC3SER|HOAE|-|DIDE|-|GCE|SAR2|SAR1|SAR0|
||RIIC3IER|TIE|TEIE|RIE|NAKIE|SPIE|STIE|ALIE|TMOIE|
||RIIC3SR1|HOA|-|DID|-|GCA|AAS2|AAS1|AAS0|
||RIIC3SR2|TDRE|TEND|RDRF|NACKF|STOP|START|3AL|TMOF|
||RIIC3SAR0|FS0|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|I2C bus interface|RIIC3SAR1|FS1|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC3SAR2|FS2|-|-|-|-|-|SVA[9]|SVA[8]|
|||SVA[7]|SVA[6]|SVA[5]|SVA[4]|SVA[3]|SVA[2]|SVA[1]|SVA0|
||RIIC3BRL|-|-|-|BRL[4]|BRL[3]|BRL[2]|BRL[1]|BRL[0]|
||RIIC3BRH|-|-|-|BRH[4]|BRH[3]|BRH[2]|BRH[1]|BRH[0]|
||RIIC3DRT|DRT[7]|DRT[6]|DRT[5]|DRT[4]|DRT[3]|DRT[2]|DRT[1]|DRT[0]|
||RIIC3DRR|DRR[7]|DRR[6]|DRR[5]|DRR[4]|DRR[3]|DRR[2]|DRR[1]|DRR[0]|
|Serial sound<br>interface|SSICR_0|-|CKS|TUIEN|TOIEN|RUIEN|ROIEN|IIEN|-|
|||CHNL[1]|CHNL[0]|DWL[2]|DWL[1]|DWL[0]|SWL[2]|SWL[1]|SWL[0]|
|||SCKD|SWSD|SCKP|SWSP|SPDP|SDTA|PDTA|DEL|
|||CKDV[3]|CKDV[2]|CKDV[1]|CKDV[0]|MUEN|-|TEN|REN|
||SSISR_0|-|-|TUIRQ|TOIRQ|RUIRQ|ROIRQ|IIRQ|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|TCHNO[1]|TCHNO[0]|TSWNO|RCHNO[1]|RCHNO[0]|RSWNO|IDST|
||SSIFCR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TTRG[1]|TTRG[0]|RTRG[1]|RTRG[0]|TIE|RIE|TFRST|RFRST|
||SSIFSR_0|-|-|-|-|TDC[3]|TDC[2]|TDC[1]|TDC[0]|
|||-|-|-|-|-|-|-|TDE|
|||-|-|-|-|RDC[3]|RDC[2]|RDC[1]|RDC[0]|
|||-|-|-|-|-|-|-|RDF|
||SSIFTDR_0|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSIFRDR_0|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSITDMR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|RXDMUTE|-|
|||-|-|-|-|-|-|-|CONT|
|||-|-|-|-|-|-|-|TDM|
||SSIFCCR_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|FIEN|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|FCEN|
||SSIFCMR_0|-|-|MAXV[13]|MAXV[12]|MAXV[11]|MAXV[10]|MAXV[9]|MAXV[8]|
|||MAXV[7]|MAXV[6]|MAXV[5]|MAXV[4]|MAXV[3]|MAXV[2]|MAXV[1]|MAXV[0]|
|||-|-|MINV[13]|MINV[12]|MINV[11]|MINV[10]|MINV[9]|MINV[8]|
|||MINV[7]|MINV[6]|MINV[5]|MINV[4]|MINV[3]|MINV[2]|MINV[1]|MINV[0]|
||SSIFCSR_0|-|-|-|-|-|-|-|FCIRQ|
|||-|-|-|-|-|-|-|-|
|||-|-|VALUE[13]|VALUE[12]|VALUE[11]|VALUE[10]|VALUE[9]|VALUE[8]|
|||VALUE[7]|VALUE[6]|VALUE[5]|VALUE[4]|VALUE[3]|VALUE[2]|VALUE[1]|VALUE[0]|
||SSICR_1|-|CKS|TUIEN|TOIEN|RUIEN|ROIEN|IIEN|-|
|||CHNL[1]|CHNL[0]|DWL[2]|DWL[1]|DWL[0]|SWL[2]|SWL[1]|SWL[0]|
|||SCKD|SWSD|SCKP|SWSP|SPDP|SDTA|PDTA|DEL|
|||CKDV[3]|CKDV[2]|CKDV[1]|CKDV[0]|MUEN|-|TEN|REN|
||SSISR_1|-|-|TUIRQ|TOIRQ|RUIRQ|ROIRQ|IIRQ|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|TCHNO[1]|TCHNO[0]|TSWNO|RCHNO[1]|RCHNO[0]|RSWNO|IDST|
||SSIFCR_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TTRG[1]|TTRG[0]|RTRG[1]|RTRG[0]|TIE|RIE|TFRST|RFRST|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Serial sound<br>interface|SSIFSR_1|-|-|-|-|TDC[3]|TDC[2]|TDC[1]|TDC[0]|
|||-|-|-|-|-|-|-|TDE|
|||-|-|-|-|RDC[3]|RDC[2]|RDC[1]|RDC[0]|
|||-|-|-|-|-|-|-|RDF|
||SSIFTDR_1|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSIFRDR_1|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSITDMR_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|RXDMUTE|-|
|||-|-|-|-|-|-|-|CONT|
|||-|-|-|-|-|-|-|TDM|
||SSIFCCR_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|FIEN|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|FCEN|
||SSIFCMR_1|-|-|MAXV[13]|MAXV[12]|MAXV[11]|MAXV[10]|MAXV[9]|MAXV[8]|
|||MAXV[7]|MAXV[6]|MAXV[5]|MAXV[4]|MAXV[3]|MAXV[2]|MAXV[1]|MAXV[0]|
|||-|-|MINV[13]|MINV[12]|MINV[11]|MINV[10]|MINV[9]|MINV[8]|
|||MINV[7]|MINV[6]|MINV[5]|MINV[4]|MINV[3]|MINV[2]|MINV[1]|MINV[0]|
||SSIFCSR_1|-|-|-|-|-|-|-|FCIRQ|
|||-|-|-|-|-|-|-|-|
|||-|-|VALUE[13]|VALUE[12]|VALUE[11]|VALUE[10]|VALUE[9]|VALUE[8]|
|||VALUE[7]|VALUE[6]|VALUE[5]|VALUE[4]|VALUE[3]|VALUE[2]|VALUE[1]|VALUE[0]|
||SSICR_2|-|CKS|TUIEN|TOIEN|RUIEN|ROIEN|IIEN|-|
|||CHNL[1]|CHNL[0]|DWL[2]|DWL[1]|DWL[0]|SWL[2]|SWL[1]|SWL[0]|
|||SCKD|SWSD|SCKP|SWSP|SPDP|SDTA|PDTA|DEL|
|||CKDV[3]|CKDV[2]|CKDV[1]|CKDV[0]|MUEN|-|TEN|REN|
||SSISR_2|-|-|TUIRQ|TOIRQ|RUIRQ|ROIRQ|IIRQ|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|TCHNO[1]|TCHNO[0]|TSWNO|RCHNO[1]|RCHNO[0]|RSWNO|IDST|
||SSIFCR_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TTRG[1]|TTRG[0]|RTRG[1]|RTRG[0]|TIE|RIE|TFRST|RFRST|
||SSIFSR_2|-|-|-|-|TDC[3]|TDC[2]|TDC[1]|TDC[0]|
|||-|-|-|-|-|-|-|TDE|
|||-|-|-|-|RDC[3]|RDC[2]|RDC[1]|RDC[0]|
|||-|-|-|-|-|-|-|RDF|
||SSIFTDR_2|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSIFRDR_2|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSITDMR_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|RXDMUTE|-|
|||-|-|-|-|-|-|-|CONT|
|||-|-|-|-|-|-|-|TDM|
||SSIFCCR_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|FIEN|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|FCEN|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Serial sound<br>interface|SSIFCMR_2|-|-|MAXV[13]|MAXV[12]|MAXV[11]|MAXV[10]|MAXV[9]|MAXV[8]|
|||MAXV[7]|MAXV[6]|MAXV[5]|MAXV[4]|MAXV[3]|MAXV[2]|MAXV[1]|MAXV[0]|
|||-|-|MINV[13]|MINV[12]|MINV[11]|MINV[10]|MINV[9]|MINV[8]|
|||MINV[7]|MINV[6]|MINV[5]|MINV[4]|MINV[3]|MINV[2]|MINV[1]|MINV[0]|
||SSIFCSR_2|-|-|-|-|-|-|-|FCIRQ|
|||-|-|-|-|-|-|-|-|
|||-|-|VALUE[13]|VALUE[12]|VALUE[11]|VALUE[10]|VALUE[9]|VALUE[8]|
|||VALUE[7]|VALUE[6]|VALUE[5]|VALUE[4]|VALUE[3]|VALUE[2]|VALUE[1]|VALUE[0]|
||SSICR_3|-|CKS|TUIEN|TOIEN|RUIEN|ROIEN|IIEN|-|
|||CHNL[1]|CHNL[0]|DWL[2]|DWL[1]|DWL[0]|SWL[2]|SWL[1]|SWL[0]|
|||SCKD|SWSD|SCKP|SWSP|SPDP|SDTA|PDTA|DEL|
|||CKDV[3]|CKDV[2]|CKDV[1]|CKDV[0]|MUEN|-|TEN|REN|
||SSISR_3|-|-|TUIRQ|TOIRQ|RUIRQ|ROIRQ|IIRQ|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|TCHNO[1]|TCHNO[0]|TSWNO|RCHNO[1]|RCHNO[0]|RSWNO|IDST|
||SSIFCR_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TTRG[1]|TTRG[0]|RTRG[1]|RTRG[0]|TIE|RIE|TFRST|RFRST|
||SSIFSR_3|-|-|-|-|TDC[3]|TDC[2]|TDC[1]|TDC[0]|
|||-|-|-|-|-|-|-|TDE|
|||-|-|-|-|RDC[3]|RDC[2]|RDC[1]|RDC[0]|
|||-|-|-|-|-|-|-|RDF|
||SSIFTDR_3|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSIFRDR_3|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSITDMR_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|RXDMUTE|-|
|||-|-|-|-|-|-|-|CONT|
|||-|-|-|-|-|-|-|TDM|
||SSIFCCR_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|FIEN|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|FCEN|
||SSIFCMR_3|-|-|MAXV[13]|MAXV[12]|MAXV[11]|MAXV[10]|MAXV[9]|MAXV[8]|
|||MAXV[7]|MAXV[6]|MAXV[5]|MAXV[4]|MAXV[3]|MAXV[2]|MAXV[1]|MAXV[0]|
|||-|-|MINV[13]|MINV[12]|MINV[11]|MINV[10]|MINV[9]|MINV[8]|
|||MINV[7]|MINV[6]|MINV[5]|MINV[4]|MINV[3]|MINV[2]|MINV[1]|MINV[0]|
||SSIFCSR_3|-|-|-|-|-|-|-|FCIRQ|
|||-|-|-|-|-|-|-|-|
|||-|-|VALUE[13]|VALUE[12]|VALUE[11]|VALUE[10]|VALUE[9]|VALUE[8]|
|||VALUE[7]|VALUE[6]|VALUE[5]|VALUE[4]|VALUE[3]|VALUE[2]|VALUE[1]|VALUE[0]|
|Media local bus*1|DCCR|MDE|LBM|MCS[1]|MCS[0]|M5PS|MLK|MLE|MHRE|
|||MRS|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||MDA[8]|MDA[7]|MDA[6]|MDA[5]|MDA[4]|MDA[3]|MDA[2]|MDA[1]|
||SSCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SSRE|SDMU|SDML|SDSC|SDCS|SDNU|SDNL|SDR|
||SDCR|MSD[31]|MSD[30]|MSD[29]|MSD[28]|MSD[27]|MSD[26]|MSD[25]|MSD[24]|
|||MSD[23]|MSD[22]|MSD[21]|MSD[20]|MSD[19]|MSD[18]|MSD[17]|MSD[16]|
|||MSD[15]|MSD[14]|MSD[13]|MSD[12]|MSD[11]|MSD[10]|MSD[9]|MSD[8]|
|||MSD[7]|MSD[6]|MSD[5]|MSD[4]|MSD[3]|MSD[2]|MSD[1]|MSD[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|SMCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|SMMU|SMML|SMSC|SMCS|SMNU|SMNL|SMR|
||VCCR|UMA[7]|UMA[6]|UMA[5]|UMA[4]|UMA[3]|UMA[2]|UMA[1]|UMA[0]|
|||UMI[7]|UMI[6]|UMI[5]|UMI[4]|UMI[3]|UMI[2]|UMI[1]|UMI[0]|
|||MMA[7]|MMA[6]|MMA[5]|MMA[4]|MMA[3]|MMA[2]|MMA[1]|MMA[0]|
|||MMI[7]|MMI[6]|MMI[5]|MMI[4]|MMI[3]|MMI[2]|MMI[1]|MMI[0]|
||SBCR|SRBA[31]|SRBA[30]|SRBA[29]|SRBA[28]|SRBA[27]|SRBA[26]|SRBA[25]|SRBA[24]|
|||SRBA[23]|SRBA[22]|SRBA[21]|SRBA[20]|SRBA[19]|SRBA[18]|SRBA[17]|SRBA[16]|
|||STBA[31]|STBA[30]|STBA[29]|STBA[28]|STBA[27]|STBA[26]|STBA[25]|STBA[24]|
|||STBA[23]|STBA[22]|STBA[21]|STBA[20]|STBA[19]|STBA[18]|STBA[17]|STBA[16]|
||ABCR|ARBA[31]|ARBA[30]|ARBA[29]|ARBA[28]|ARBA[27]|ARBA[26]|ARBA[25]|ARBA[24]|
|||ARBA[23]|ARBA[22]|ARBA[21]|ARBA[20]|ARBA[19]|ARBA[18]|ARBA[17]|ARBA[16]|
|||ATBA[31]|ATBA[30]|ATBA[29]|ATBA[28]|ATBA[27]|ATBA[26]|ATBA[25]|ATBA[24]|
|||ATBA[23]|ATBA[22]|ATBA[21]|ATBA[20]|ATBA[19]|ATBA[18]|ATBA[17]|ATBA[16]|
||CBCR|CRBA[31]|CRBA[30]|CRBA[29]|CRBA[28]|CRBA[27]|CRBA[26]|CRBA[25]|CRBA[24]|
|||CRBA[23]|CRBA[22]|CRBA[21]|CRBA[20]|CRBA[19]|CRBA[18]|CRBA[17]|CRBA[16]|
|||CTBA[31]|CTBA[30]|CTBA[29]|CTBA[28]|CTBA[27]|CTBA[26]|CTBA[25]|CTBA[24]|
|||CTBA[23]|CTBA[22]|CTBA[21]|CTBA[20]|CTBA[19]|CTBA[18]|CTBA[17]|CTBA[16]|
||IBCR|IRBA[31]|IRBA[30]|IRBA[29]|IRBA[28]|IRBA[27]|IRBA[26]|IRBA[25]|IRBA[24]|
|||IRBA[23]|IRBA[22]|IRBA[21]|IRBA[20]|IRBA[19]|IRBA[18]|IRBA[17]|IRBA[16]|
|||ITBA[31]|ITBA[30]|ITBA[29]|ITBA[28]|ITBA[27]|ITBA[26]|ITBA[25]|ITBA[24]|
|||ITBA[23]|ITBA[22]|ITBA[21]|ITBA[20]|ITBA[19]|ITBA[18]|ITBA[17]|ITBA[16]|
||CICR|-|CnSU[30]|CnSU[29]|CnSU[28]|CnSU[27]|CnSU[26]|CnSU[25]|CnSU[24]|
|||CnSU[23]|CnSU[22]|CnSU[21]|CnSU[20]|CnSU[19]|CnSU[18]|CnSU[17]|CnSU[16]|
|||CnSU[15]|CnSU[14]|CnSU[13]|CnSU[12]|CnSU[11]|CnSU[10]|CnSU[9]|CnSU[8]|
|||CnSU[7]|CnSU[6]|CnSU[5]|CnSU[4]|CnSU[3]|CnSU[2]|CnSU[1]|CnSU[0]|
||CECR0|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR0|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR0|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR0|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR1|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR1|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR1|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR1|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|CECR2|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR2|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR2|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR2|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR3|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR3|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR3|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR3|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR4|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR4|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR4|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR4|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR5|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR5|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR5|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|

**Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|CNBCR5|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR6|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR6|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR6|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR6|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR7|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR7|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR7|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR7|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR8|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR8|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR8|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR8|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR9|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR9|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|CCBCR9|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR9|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR10|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR10|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR10|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR10|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR11|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR11|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR11|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR11|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR12|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR12|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR12|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR12|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR13|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|CSCR13|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR13|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR13|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR14|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR14|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR14|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR14|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR15|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR15|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR15|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR15|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR16|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR16|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR16|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR16|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|CECR17|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR17|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR17|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR17|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR18|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR18|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR18|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR18|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR19|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR19|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR19|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR19|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR20|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR20|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR20|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|

**Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|CNBCR20|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR21|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR21|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR21|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR21|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR22|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR22|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR22|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR22|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR23|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR23|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR23|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR23|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR24|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR24|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|CCBCR24|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR24|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR25|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR25|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR25|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR25|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR26|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR26|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR26|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR26|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR27|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR27|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR27|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR27|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|CECR28|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR28|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR28|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR28|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR29|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR29|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR29|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR29|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||CECR30|CE|TR|CT[1]|CT[0]|PCE_FSE|MDS[1]|MDS[0]|-|
|||MASK[7]|MASK[6]|MASK[5]|MASK[4]|MASK[3]|MASK[2]|MASK[1]|MASK[0]|
|||FSCD|-|-|PCTH_FSPC[4]|PCTH_FSPC[3]|PCTH_FSPC[2]|PCTH_FSPC[1]|PCTH_FSPC[0]|
|||CA[8]|CA[7]|CA[6]|CA[5]|CA[4]|CA[3]|CA[2]|CA[1]|
||CSCR30|BM|BF|-|-|-|-|-|-|
|||-|-|-|-|-|-|GB|RDY|
|||STS[15]|STS[14]|STS[13]|STS[12]|STS[11]|STS[10]|STS[9]|STS[8]|
|||STS[7]|STS[6]|STS[5]|STS[4]|STS[3]|STS[2]|STS[1]|STS[0]|
||CCBCR30|BCA[15]|BCA[14]|BCA[13]|BCA[12]|BCA[11]|BCA[10]|BCA[9]|BCA[8]|
|||BCA[7]|BCA[6]|BCA[5]|BCA[4]|BCA[3]|BCA[2]|BCA[1]|BCA[0]|
|||BFA[15]|BFA[14]|BFA[13]|BFA[12]|BFA[11]|BFA[10]|BFA[9]|BFA[8]|
|||BFA[7]|BFA[6]|BFA[5]|BFA[4]|BFA[3]|BFA[2]|BFA[1]|BFA[0]|
||CNBCR30|BSA[15]|BSA[14]|BSA[13]|BSA[12]|BSA[11]|BSA[10]|BSA[9]|BSA[8]|
|||BSA[7]|BSA[6]|BSA[5]|BSA[4]|BSA[3]|BSA[2]|-|-|
|||BEA[15]|BEA[14]|BEA[13]|BEA[12]|BEA[11]|BEA[10]|BEA[9]|BEA[8]|
|||BEA[7]|BEA[6]|BEA[5]|BEA[4]|BEA[3]|BEA[2]|BEA[1]|BEA[0]|
||LCBCR0|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR1|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|LCBCR2|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR3|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR4|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR5|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR6|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR7|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR8|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR9|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR10|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR11|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR12|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR13|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR14|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR15|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Media local bus*1|LCBCR16|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR17|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR18|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR19|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR20|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR21|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR22|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR23|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR24|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR25|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR26|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR27|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR28|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR29|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|
||LCBCR30|TH[9]|TH[8]|TH[7]|TH[6]|TH[5]|TH[4]|TH[3]|TH[2]|
|||TH[1]|TH[0]|BD[8]|BD[7]|BD[6]|BD[5]|BD[4]|BD[3]|
|||BD[2]|BD[1]|BD[0]|SA[12]|SA[11]|SA[10]|SA[9]|SA[8]|
|||SA[7]|SA[6]|SA[5]|SA[4]|SA[3]|SA[2]|SA[1]|SA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|CAN interface|RSCAN0CmCFG<br>(m = 0, 1)|-|-|-|-|-|-|SJW[1]|SJW[0]|
|||-|TSEG2[2]|TSEG2[1]|TSEG2[0]|TSEG1[3]|TSEG1[2]|TSEG1[1]|TSEG1[0]|
|||-|-|-|-|-|-|BRP[9]|BRP[8]|
|||BRP[7]|BRP[6]|BRP[5]|BRP[4]|BRP[3]|BRP[2]|BRP[1]|BRP[0]|
||RSCAN0CmCTR<br>(m = 0, 1)|-|-|-|-|-|CTMS[1]|CTMS[0]|CTME|
|||ERRD|BOM[1]|BOM[0]|-|-|-|-|TAIE|
|||ALIE|BLIE|OLIE|BORIE|BOEIE|EPIE|EWIE|BEIE|
|||-|-|-|-|RTBO|CSLPR|CHMDC[1]|CHMDC[0]|
||RSCAN0CmSTS<br>(m = 0, 1)|TEC[7]|TEC[6]|TEC[5]|TEC[4]|TEC[3]|TEC[2]|TEC[1]|TEC[0]|
|||REC[7]|REC[6]|REC[5]|REC[4]|REC[3]|REC[2]|REC[1]|REC[0]|
|||-|-|-|-|-|-|-|-|
|||COMSTS|RECSTS|TRMSTS|BOSTS|EPSTS|CSLPSTS|CHLTSTS|CRSTSTS|
||RSCAN0CmERFL<br>(m = 0, 1)|-|CRCREG[14]|CRCREG[13]|CRCREG[12]|CRCREG[11]|CRCREG[10]|CRCREG[9]|CRCREG[8]|
|||CRCREG[7]|CRCREG[6]|CRCREG[5]|CRCREG[4]|CRCREG[3]|CRCREG[2]|CRCREG[1]|CRCREG[0]|
|||-|ADERR|B0ERR|B1ERR|CERR|AERR|FERR|SERR|
|||ALF|BLF|OVLF|BORF|BOEF|EPF|EWF|BEF|
||RSCAN0GCFG|ITRCP[15]|ITRCP[14]|ITRCP[13]|ITRCP[12]|ITRCP[11]|ITRCP[10]|ITRCP[9]|ITRCP[8]|
|||ITRCP[7]|ITRCP[6]|ITRCP[5]|ITRCP[4]|ITRCP[3]|ITRCP[2]|ITRCP[1]|ITRCP[0]|
|||TSBTCS[2]|TSBTCS[1]|TSBTCS[0]|TSSS|TSP[3]|TSP[2]|TSP[1]|TSP[0]|
|||-|-|-|DCS|MME|DRE|DCE|TPRI|
||RSCAN0GCTR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TSRST|
|||-|-|-|-|-|THLEIE|MEIE|DEIE|
|||-|-|-|-|-|GSLPR|GMDC[1]|GMDC[0]|
||RSCAN0GSTS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|GRAMINIT|GSLPSTS|GHLTSTS|GRSTSTS|
||RSCAN0GERFL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|THLES|MES|DEF|
||RSCAN0GTSC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TS[15]|TS[14]|TS[13]|TS[12]|TS[11]|TS[10]|TS[9]|TS[8]|
|||TS[7]|TS[6]|TS[5]|TS[4]|TS[3]|TS[2]|TS[1]|TS[0]|
||RSCAN0GAFLECTR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|AFLDAE|
|||-|-|-|AFLPN[4]|AFLPN[3]|AFLPN[2]|AFLPN[1]|AFLPN[0]|
||RSCAN0GAFLCFG0|RNC0[7]|RNC0[6]|RNC0[5]|RNC0[4]|RNC0[3]|RNC0[2]|RNC0[1]|RNC0[0]|
|||RNC1[7]|RNC1[6]|RNC1[5]|RNC1[4]|RNC1[3]|RNC1[2]|RNC1[1]|RNC1[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||RSCAN0RMNB|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||NRXMB[7]|NRXMB[6]|NRXMB[5]|NRXMB[4]|NRXMB[3]|NRXMB[2]|NRXMB[1]|NRXMB[0]|
||RSCAN0RMND0|RMNS[31]|RMNS[30]|RMNS[29]|RMNS[28]|RMNS[27]|RMNS[26]|RMNS[25]|RMNS[24]|
|||RMNS[23]|RMNS[22]|RMNS[21]|RMNS[20]|RMNS[19]|RMNS[18]|RMNS[17]|RMNS[16]|
|||RMNS[15]|RMNS[14]|RMNS[13]|RMNS[12]|RMNS[11]|RMNS[10]|RMNS[9]|RMNS[8]|
|||RMNS[7]|RMNS[6]|RMNS[5]|RMNS[4]|RMNS[3]|RMNS[2]|RMNS[1]|RMNS[0]|
||RSCAN0RFCCx<br>(x = 0 to 7)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RFIGCV[2]|RFIGCV[1]|RFIGCV[0]|RFIM|-|RFDC[2]|RFDC[1]|RFDC[0]|
|||-|-|-|-|-|-|RFIE|RFE|
||RSCAN0RFSTSx<br>(x = 0 to 7)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RFMC[7]|RFMC[6]|RFMC[5]|RFMC[4]|RFMC[3]|RFMC[2]|RFMC[1]|RFMC[0]|
|||-|-|-|-|RFIF|RFMLT|RFFLL|RFEMP|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|CAN interface|RSCAN0RFPCTRx<br>(x = 0 to 7)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RFPC[7]|RFPC[6]|RFPC[5]|RFPC[4]|RFPC[3]|RFPC[2]|RFPC[1]|RFPC[0]|
||RSCAN0CFCCk<br>(k = 0 to 5)|CFITT[7]|CFITT[6]|CFITT[5]|CFITT[4]|CFITT[3]|CFITT[2]|CFITT[1]|CFITT[0]|
|||CFTML[3]|CFTML[2]|CFTML[1]|CFTML[0]|CFITR|CFITSS|CFM[1]|CFM[0]|
|||CFIGCV[2]|CFIGCV[1]|CFIGCV[0]|CFIM|-|CFDC[2]|CFDC[1]|CFDC[0]|
|||-|-|-|-|-|CFTXIE|CFRXIE|CFE|
||RSCAN0CFSTSk<br>(k = 0 to 5)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CFMC[7]|CFMC[6]|CFMC[5]|CFMC[4]|CFMC[3]|CFMC[2]|CFMC[1]|CFMC[0]|
|||-|-|-|CFTXIF|CFRXIF|CFMLT|CFFLL|CFEMP|
||RSCAN0CFPCTRk<br>(k = 0 to 5)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CFPC[7]|CFPC[6]|CFPC[5]|CFPC[4]|CFPC[3]|CFPC[2]|CFPC[1]|CFPC[0]|
||RSCAN0FESTS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|CF5EMP|CF4EMP|CF3EMP|CF2EMP|CF1EMP|CF0EMP|
|||RF7EMP|RF6EMP|RF5EMP|RF4EMP|RF3EMP|RF2EMP|RF1EMP|RF0EMP|
||RSCAN0FFSTS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|CF5FLL|CF4FLL|CF3FLL|CF2FLL|CF1FLL|CF0FLL|
|||RF7FLL|RF6FLL|RF5FLL|RF4FLL|RF3FLL|RF2FLL|RF1FLL|RF0FLL|
||RSCAN0FMSTS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|CF5MLT|CF4MLT|CF3MLT|CF2MLT|CF1MLT|CF0MLT|
|||RF7MLT|RF6MLT|RF5MLT|RF4MLT|RF3MLT|RF2MLT|RF1MLT|RF0MLT|
||RSCAN0RFISTS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RF7IF|RF6IF|RF5IF|RF4IF|RF3IF|RF2IF|RF1IF|RF0IF|
||RSCAN0CFRISTS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|CF5RXIF|CF4RXIF|CF3RXIF|CF2RXIF|CF1RXIF|CF0RXIF|
||RSCAN0CFTISIS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|CF5TXIF|CF4TXIF|CF3TXIF|CF2TXIF|CF1TXIF|CF0TXIF|
||RSCAN0TMCp<br>(p = 0 to 31)|||||||||
|||-|-|-|-|-|TMOM|TMTAR|TMTR|
||RSCAN0TMSTSp<br>(p = 0 to 31)|||||||||
|||-|-|-|TMTARM|TMTRM|TMTRF[1]|TMTRF[0]|TMTSTS|
||RSCAN0TMTRSTS0|TMTRSTS[31]|TMTRSTS[30]|TMTRSTS[29]|TMTRSTS[28]|TMTRSTS[27]|TMTRSTS[26]|TMTRSTS[25]|TMTRSTS[24]|
|||TMTRSTS[23]|TMTRSTS[22]|TMTRSTS[21]|TMTRSTS[20]|TMTRSTS[19]|TMTRSTS[18]|TMTRSTS[17]|TMTRSTS[16]|
|||TMTRSTS[15]|TMTRSTS[14]|TMTRSTS[13]|TMTRSTS[12]|TMTRSTS[11]|TMTRSTS[10]|TMTRSTS[9]|TMTRSTS[8]|
|||TMTRSTS[7]|TMTRSTS[6]|TMTRSTS[5]|TMTRSTS[4]|TMTRSTS[3]|TMTRSTS[2]|TMTRSTS[1]|TMTRSTS[0]|
||RSCAN0TMTARSTS<br>0|TMTARSTS[31]|TMTARSTS[30]|TMTARSTS[29]|TMTARSTS[28]|TMTARSTS[27]|TMTARSTS[26]|TMTARSTS[25]|TMTARSTS[24]|
|||TMTARSTS[23]|TMTARSTS[22]|TMTARSTS[21]|TMTARSTS[20]|TMTARSTS[19]|TMTARSTS[18]|TMTARSTS[17]|TMTARSTS[16]|
|||TMTARSTS[15]|TMTARSTS[14]|TMTARSTS[13]|TMTARSTS[12]|TMTARSTS[11]|TMTARSTS[10]|TMTARSTS[9]|TMTARSTS[8]|
|||TMTARSTS[7]|TMTARSTS[6]|TMTARSTS[5]|TMTARSTS[4]|TMTARSTS[3]|TMTARSTS[2]|TMTARSTS[1]|TMTARSTS[0]|
||RSCAN0TMTCSTS0|TMTCSTS[31]|TMTCSTS[30]|TMTCSTS[29]|TMTCSTS[28]|TMTCSTS[27]|TMTCSTS[26]|TMTCSTS[25]|TMTCSTS[24]|
|||TMTCSTS[23]|TMTCSTS[22]|TMTCSTS[21]|TMTCSTS[20]|TMTCSTS[19]|TMTCSTS[18]|TMTCSTS[17]|TMTCSTS[16]|
|||TMTCSTS[15]|TMTCSTS[14]|TMTCSTS[13]|TMTCSTS[12]|TMTCSTS[11]|TMTCSTS[10]|TMTCSTS[9]|TMTCSTS[8]|
|||TMTCSTS[7]|TMTCSTS[6]|TMTCSTS[5]|TMTCSTS[4]|TMTCSTS[3]|TMTCSTS[2]|TMTCSTS[1]|TMTCSTS[0]|
||RSCAN0TMTASTS0|TMTASTS[31]|TMTASTS[30]|TMTASTS[29]|TMTASTS[28]|TMTASTS[27]|TMTASTS[26]|TMTASTS[25]|TMTASTS[24]|
|||TMTASTS[23]|TMTASTS[22]|TMTASTS[21]|TMTASTS[20]|TMTASTS[19]|TMTASTS[18]|TMTASTS[17]|TMTASTS[16]|
|||TMTASTS[15]|TMTASTS[14]|TMTASTS[13]|TMTASTS[12]|TMTASTS[11]|TMTASTS[10]|TMTASTS[9]|TMTASTS[8]|
|||TMTASTS[7]|TMTASTS[6]|TMTASTS[5]|TMTASTS[4]|TMTASTS[3]|TMTASTS[2]|TMTASTS[1]|TMTASTS[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|CAN interface|RSCAN0TMIEC0|TMIE[31]|TMIE[30]|TMIE[29]|TMIE[28]|TMIE[27]|TMIE[26]|TMIE[25]|TMIE[24]|
|||TMIE[23]|TMIE[22]|TMIE[21]|TMIE[20]|TMIE[19]|TMIE[18]|TMIE[17]|TMIE[16]|
|||TMIE[15]|TMIE[14]|TMIE[13]|TMIE[12]|TMIE[11]|TMIE[10]|TMIE[9]|TMIE[8]|
|||TMIE[7]|TMIE[6]|TMIE[5]|TMIE[4]|TMIE[3]|TMIE[2]|TMIE[1]|TMIE[0]|
||RSCAN0TXQCCm<br>(m = 0, 1)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|TXQIM|TXQIE|TXQDC[3]|TXQDC[2]|TXQDC[1]|TXQDC[0]|
|||-|-|-|-|-|-|-|TXQE|
||RSCAN0TXQSTSm<br>(m = 0, 1)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|TXQIF|TXQFLL|TXQEMP|
||RSCAN0TXQPCTR<br>m<br>(m = 0, 1)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TXQPC[7]|TXQPC[6]|TXQPC[5]|TXQPC[4]|TXQPC[3]|TXQPC[2]|TXQPC[1]|TXQPC[0]|
||RSCAN0THLCCm<br>(m = 0, 1)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|THLDTE|THLIM|THLIE|
|||-|-|-|-|-|-|-|THLE|
||RSCAN0THLSTSm<br>(m = 0, 1)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|THLMC[4]|THLMC[3]|THLMC[2]|THLMC[1]|THLMC[0]|
|||-|-|-|-|THLIF|THLELT|THLFLL|THLEMP|
||RSCAN0THLPCTRm<br>(m = 0, 1)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||THLPC[7]|THLPC[6]|THLPC[5]|THLPC[4]|THLPC[3]|THLPC[2]|THLPC[1]|THLPC[0]|
||RSCAN0GTINTSTS0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|THIF1|CFTIF1|TQIF1|TAIF1|TSIF1|
|||-|-|-|THIF0|CFTIF0|TQIF0|TAIF0|TSIF0|
||RSCAN0GTSTCFG|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|C1ICBCE|C0ICBCE|
||RSCAN0GTSTCTR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ICBCTME|
||RSCAN0GLOCKK|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LOCK[15]|LOCK[14]|LOCK[13]|LOCK[12]|LOCK[11]|LOCK[10]|LOCK[9]|LOCK[8]|
|||LOCK[7]|LOCK[6]|LOCK[5]|LOCK[4]|LOCK[3]|LOCK[2]|LOCK[1]|LOCK[0]|
||RSCAN0GAFLIDj<br>(j = 0 to 15)|GAFLIDE|GAFLRTR|GAFLLB|GAFLID[28]|GAFLID[27]|GAFLID[26]|GAFLID[25]|GAFLID[24]|
|||GAFLID[23]|GAFLID[22]|GAFLID[21]|GAFLID[20]|GAFLID[19]|GAFLID[18]|GAFLID[17]|GAFLID[16]|
|||GAFLID[15]|GAFLID[14]|GAFLID[13]|GAFLID[12]|GAFLID[11]|GAFLID[10]|GAFLID[9]|GAFLID[8]|
|||GAFLID[7]|GAFLID[6]|GAFLID[5]|GAFLID[4]|GAFLID[3]|GAFLID[2]|GAFLID[1]|GAFLID[0]|
||RSCAN0GAFLMj<br>(j = 0 to 15)|GAFLIDEM|GAFLRTRM|-|GAFLIDM[28]|GAFLIDM[27]|GAFLIDM[26]|GAFLIDM[25]|GAFLIDM[24]|
|||GAFLIDM[23]|GAFLIDM[22]|GAFLIDM[21]|GAFLIDM[20]|GAFLIDM[19]|GAFLIDM[18]|GAFLIDM[17]|GAFLIDM[16]|
|||GAFLIDM[15]|GAFLIDM[14]|GAFLIDM[13]|GAFLIDM[12]|GAFLIDM[11]|GAFLIDM[10]|GAFLIDM[9]|GAFLIDM[8]|
|||GAFLIDM[7]|GAFLIDM[6]|GAFLIDM[5]|GAFLIDM[4]|GAFLIDM[3]|GAFLIDM[2]|GAFLIDM[1]|GAFLIDM[0]|
||RSCAN0GAFLP0j<br>(j = 0 to 15)|GAFLDLC[3]|GAFLDLC[2]|GAFLDLC[1]|GAFLDLC[0]|GAFLPTR[11]|GAFLPTR[10]|GAFLPTR[9]|GAFLPTR[8]|
|||GAFLPTR[7]|GAFLPTR[6]|GAFLPTR[5]|GAFLPTR[4]|GAFLPTR[3]|GAFLPTR[2]|GAFLPTR[1]|GAFLPTR[0]|
|||GAFLRMV|GAFLRMDP[6]|GAFLRMDP[5]|GAFLRMDP[4]|GAFLRMDP[3]|GAFLRMDP[2]|GAFLRMDP[1]|GAFLRMDP[0]|
|||-|-|-|-|-|-|-|-|
||RSCAN0GAFLP1j<br>(j = 0 to 15)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|GAFLFDP[13]|GAFLFDP[12]|GAFLFDP[11]|GAFLFDP[10]|GAFLFDP[9]|GAFLFDP[8]|
|||GAFLFDP[7]|GAFLFDP[6]|GAFLFDP[5]|GAFLFDP[4]|GAFLFDP[3]|GAFLFDP[2]|GAFLFDP[1]|GAFLFDP[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|CAN interface|RSCAN0RMIDq<br>(q = 0 to 31)|PMIDE|PMRTR|-|RMID[28]|RMID[27]|RMID[26]|RMID[25]|RMID[24]|
|||RMID[23]|RMID[22]|RMID[21]|RMID[20]|RMID[19]|RMID[18]|RMID[17]|RMID[16]|
|||RMID[15]|RMID[14]|RMID[13]|RMID[12]|RMID[11]|RMID[10]|RMID[9]|RMID[8]|
|||RMID[7]|RMID[6]|RMID[5]|RMID[4]|RMID[3]|RMID[2]|RMID[1]|RMID[0]|
||RSCAN0RMPTRq<br>(q = 0 to 31)|RMDLC[3]|RMDLC[2]|RMDLC[1]|RMDLC[0]|RMPTR[11]|RMPTR[10]|RMPTR[9]|RMPTR[8]|
|||RMPTR[7]|RMPTR[6]|RMPTR[5]|RMPTR[4]|RMPTR[3]|RMPTR[2]|RMPTR[1]|RMPTR[0]|
|||RMTS[15]|RMTS[14]|RMTS[13]|RMTS[12]|RMTS[11]|RMTS[10]|RMTS[9]|RMTS[8]|
|||RMTS[7]|RMTS[6]|RMTS[5]|RMTS[4]|RMTS[3]|RMTS[2]|RMTS[1]|RMTS[0]|
||RSCAN0RMDF0q<br>(q = 0 to 31)|RMDB3[7]|RMDB3[6]|RMDB3[5]|RMDB3[4]|RMDB3[3]|RMDB3[2]|RMDB3[1]|RMDB3[0]|
|||RMDB2[7]|RMDB2[6]|RMDB2[5]|RMDB2[4]|RMDB2[3]|RMDB2[2]|RMDB2[1]|RMDB2[0]|
|||RMDB1[7]|RMDB1[6]|RMDB1[5]|RMDB1[4]|RMDB1[3]|RMDB1[2]|RMDB1[1]|RMDB1[0]|
|||RMDB0[7]|RMDB0[6]|RMDB0[5]|RMDB0[4]|RMDB0[3]|RMDB0[2]|RMDB0[1]|RMDB0[0]|
||RSCAN0RMDF1q<br>(q = 0 to 31)|RMDB7[7]|RMDB7[6]|RMDB7[5]|RMDB7[4]|RMDB7[3]|RMDB7[2]|RMDB7[1]|RMDB7[0]|
|||RMDB6[7]|RMDB6[6]|RMDB6[5]|RMDB6[4]|RMDB6[3]|RMDB6[2]|RMDB6[1]|RMDB6[0]|
|||RMDB5[7]|RMDB5[6]|RMDB5[5]|RMDB5[4]|RMDB5[3]|RMDB5[2]|RMDB5[1]|RMDB5[0]|
|||RMDB4[7]|RMDB4[6]|RMDB4[5]|RMDB4[4]|RMDB4[3]|RMDB4[2]|RMDB4[1]|RMDB4[0]|
||RSCAN0RFIDx<br>(x = 0 to 7)|RFIDE|RFRTR|-|RFID[28]|RFID[27]|RFID[26]|RFID[25]|RFID[24]|
|||RFID[23]|RFID[22]|RFID[21]|RFID[20]|RFID[19]|RFID[18]|RFID[17]|RFID[16]|
|||RFID[15]|RFID[14]|RFID[13]|RFID[12]|RFID[11]|RFID[10]|RFID[9]|RFID[8]|
|||RFID[7]|RFID[6]|RFID[5]|RFID[4]|RFID[3]|RFID[2]|RFID[1]|RFID[0]|
||RSCAN0RFPTRx<br>(x = 0 to 7)|RFDLC[3]|RFDLC[2]|RFDLC[1]|RFDLC[0]|RFPTR[11]|RFPTR[10]|RFPTR[9]|RFPTR[8]|
|||RFPTR[7]|RFPTR[6]|RFPTR[5]|RFPTR[4]|RFPTR[3]|RFPTR[2]|RFPTR[1]|RFPTR[0]|
|||RFTS[15]|RFTS[14]|RFTS[13]|RFTS[12]|RFTS[11]|RFTS[10]|RFTS[9]|RFTS[8]|
|||RFTS[7]|RFTS[6]|RFTS[5]|RFTS[4]|RFTS[3]|RFTS[2]|RFTS[1]|RFTS[0]|
||RSCAN0RFDF0x<br>(x = 0 to 7)|RFDB3[7]|RFDB3[6]|RFDB3[5]|RFDB3[4]|RFDB3[3]|RFDB3[2]|RFDB3[1]|RFDB3[0]|
|||RFDB2[7]|RFDB2[6]|RFDB2[5]|RFDB2[4]|RFDB2[3]|RFDB2[2]|RFDB2[1]|RFDB2[0]|
|||RFDB1[7]|RFDB1[6]|RFDB1[5]|RFDB1[4]|RFDB1[3]|RFDB1[2]|RFDB1[1]|RFDB1[0]|
|||RFDB0[7]|RFDB0[6]|RFDB0[5]|RFDB0[4]|RFDB0[3]|RFDB0[2]|RFDB0[1]|RFDB0[0]|
||RSCAN0RFDF1x<br>(x = 0 to 7)|RFDB7[7]|RFDB7[6]|RFDB7[5]|RFDB7[4]|RFDB7[3]|RFDB7[2]|RFDB7[1]|RFDB7[0]|
|||RFDB6[7]|RFDB6[6]|RFDB6[5]|RFDB6[4]|RFDB6[3]|RFDB6[2]|RFDB6[1]|RFDB6[0]|
|||RFDB5[7]|RFDB5[6]|RFDB5[5]|RFDB5[4]|RFDB5[3]|RFDB5[2]|RFDB5[1]|RFDB5[0]|
|||RFDB4[7]|RFDB4[6]|RFDB4[5]|RFDB4[4]|RFDB4[3]|RFDB4[2]|RFDB4[1]|RFDB4[0]|
||RSCAN0CFIDk<br>(k = 0 to 5)|CFIDE|CFRTR|THLEN|CFID[28]|CFID[27]|CFID[26]|CFID[25]|CFID[24]|
|||CFID[23]|CFID[22]|CFID[21]|CFID[20]|CFID[19]|CFID[18]|CFID[17]|CFID[16]|
|||CFID[15]|CFID[14]|CFID[13]|CFID[12]|CFID[11]|CFID[10]|CFID[9]|CFID[8]|
|||CFID[7]|CFID[6]|CFID[5]|CFID[4]|CFID[3]|CFID[2]|CFID[1]|CFID[0]|
||RSCAN0CFPTRk<br>(k = 0 to 5)|CFDLC[3]|CFDLC[2]|CFDLC[1]|CFDLC[0]|CFPTR[11]|CFPTR[10]|CFPTR[9]|CFPTR[8]|
|||CFPTR[7]|CFPTR[6]|CFPTR[5]|CFPTR[4]|CFPTR[3]|CFPTR[2]|CFPTR[1]|CFPTR[0]|
|||CFTS[15]|CFTS[14]|CFTS[13]|CFTS[12]|CFTS[11]|CFTS[10]|CFTS[9]|CFTS[8]|
|||CFTS[7]|CFTS[6]|CFTS[5]|CFTS[4]|CFTS[3]|CFTS[2]|CFTS[1]|CFTS[0]|
||RSCAN0CFDF0k<br>(k = 0 to 5)|CFDB3[7]|CFDB3[6]|CFDB3[5]|CFDB3[4]|CFDB3[3]|CFDB3[2]|CFDB3[1]|CFDB3[0]|
|||CFDB2[7]|CFDB2[6]|CFDB2[5]|CFDB2[4]|CFDB2[3]|CFDB2[2]|CFDB2[1]|CFDB2[0]|
|||CFDB1[7]|CFDB1[6]|CFDB1[5]|CFDB1[4]|CFDB1[3]|CFDB1[2]|CFDB1[1]|CFDB1[0]|
|||CFDB0[7]|CFDB0[6]|CFDB0[5]|CFDB0[4]|CFDB0[3]|CFDB0[2]|CFDB0[1]|CFDB0[0]|
||RSCAN0CFDF1k<br>(k = 0 to 5)|CFDB7[7]|CFDB7[6]|CFDB7[5]|CFDB7[4]|CFDB7[3]|CFDB7[2]|CFDB7[1]|CFDB7[0]|
|||CFDB6[7]|CFDB6[6]|CFDB6[5]|CFDB6[4]|CFDB6[3]|CFDB6[2]|CFDB6[1]|CFDB6[0]|
|||CFDB5[7]|CFDB5[6]|CFDB5[5]|CFDB5[4]|CFDB5[3]|CFDB5[2]|CFDB5[1]|CFDB5[0]|
|||CFDB4[7]|CFDB4[6]|CFDB4[5]|CFDB4[4]|CFDB4[3]|CFDB4[2]|CFDB4[1]|CFDB4[0]|
||RSCAN0TMIDp<br>(p = 0 to 31)|TMIDE|TMRTR|THLEN|TMID[28]|TMID[27]|TMID[26]|TMID[25]|TMID[24]|
|||TMID[23]|TMID[22]|TMID[21]|TMID[20]|TMID[19]|TMID[18]|TMID[17]|TMID[16]|
|||TMID[15]|TMID[14]|TMID[13]|TMID[12]|TMID[11]|TMID[10]|TMID[9]|TMID[8]|
|||TMID[7]|TMID[6]|TMID[5]|TMID[4]|TMID[3]|TMID[2]|TMID[1]|TMID[0]|
||RSCAN0TMPTRp<br>(p = 0 to 31)|TMDLC[3]|TMDLC[2]|TMDLC[1]|TMDLC[0]|-|-|-|-|
|||TMPTR[7]|TMPTR[6]|TMPTR[5]|TMPTR[4]|TMPTR[3]|TMPTR[2]|TMPTR[1]|TMPTR[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||RSCAN0TMDF0p<br>(p = 0 to 31)|TMDB3[7]|TMDB3[6]|TMDB3[5]|TMDB3[4]|TMDB3[3]|TMDB3[2]|TMDB3[1]|TMDB3[0]|
|||TMDB2[7]|TMDB2[6]|TMDB2[5]|TMDB2[4]|TMDB2[3]|TMDB2[2]|TMDB2[1]|TMDB2[0]|
|||TMDB1[7]|TMDB1[6]|TMDB1[5]|TMDB1[4]|TMDB1[3]|TMDB1[2]|TMDB1[1]|TMDB1[0]|
|||TMDB0[7]|TMDB0[6]|TMDB0[5]|TMDB0[4]|TMDB0[3]|TMDB0[2]|TMDB0[1]|TMDB0[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|CAN interface|RSCAN0TMDF1p<br>(p = 0 to 31)|TMDB7[7]|TMDB7[6]|TMDB7[5]|TMDB7[4]|TMDB7[3]|TMDB7[2]|TMDB7[1]|TMDB7[0]|
|||TMDB6[7]|TMDB6[6]|TMDB6[5]|TMDB6[4]|TMDB6[3]|TMDB6[2]|TMDB6[1]|TMDB6[0]|
|||TMDB5[7]|TMDB5[6]|TMDB5[5]|TMDB5[4]|TMDB5[3]|TMDB5[2]|TMDB5[1]|TMDB5[0]|
|||TMDB4[7]|TMDB4[6]|TMDB4[5]|TMDB4[4]|TMDB4[3]|TMDB4[2]|TMDB4[1]|TMDB4[0]|
||RSCAN0THLACCm<br>(m = 0, 1)|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TID[7]|TID[6]|TID[5]|TID[4]|TID[3]|TID[2]|TID[1]|TID[0]|
|||-|BN[3]|BN[2]|BN[1]|BN[0]|BT[2]|BT[1]|BT[0]|
|IEBus controller*1|IEBB0BCR|IEBB0PW|IEBB0MSRQ|IEBB0ALRQ|IEBB0STXE|IEBB0SRXE|-|-|-|
||IEBB0PSR|IEBB0CLKE|IEBB0CMD|-|-|-|-|-|-|
||IEBB0UAR|-|-|-|-|||||
|||||||||||
||IEBB0SAR|-|-|-|-|||||
|||||||||||
||IEBB0PAR|-|-|-|-|||||
|||||||||||
||IEBB0RSA|-|-|-|-|||||
|||||||||||
||IEBB0CDR|-|-|-|-|IEBB0SLCD3|IEBB0SLCD2|IEBB0SLCD1|IEBB0SLCD0|
||IEBB0TCD|-|-|-|-|IEBB0SLTD3|IEBB0SLTD2|IEBB0SLTD1|IEBB0SLTD0|
||IEBB0RCD|-|-|-|-|IEBB0SLRD3|IEBB0SLRD2|IEBB0SLRD1|IEBB0SLRD0|
||IEBB0DLR|||||||||
||IEBB0TDL|||||||||
||IEBB0RDL|||||||||
||IEBB0CKS|-|-|-|IEBB0PRS|-|IEBB0BRS2|IEBB0BRS1|IEBB0BRS0|
||IEBB0TMS|IEBB0FMDE|IEBB0SLRI1|IEBB0SLRI0|IEBB0SLTI1|IEBB0SLTI0|IEBB0ALC2|IEBB0ALC1|IEBB0ALC0|
||IEBB0PCR|IEBB0CRPT|IEBB0CTPT|-|-|-|-|-|-|
||IEBB0BSR|IEBB0RFLF|IEBB0FOVR|-|IEBB0SRFP4|IEBB0SRFP3|IEBB0SRFP2|IEBB0SRFP1|IEBB0SRFP0|
|||IEBB0TFLF|IEBB0FOVW|-|IEBB0STFP4|IEBB0STFP3|IEBB0STFP2|IEBB0STFP1|IEBB0STFP0|
||IEBB0SSR|-|-|-|IEBB0SSLF|-|IEBB0STLF|IEBB0SRXF|IEBB0STXF|
||IEBB0USR|-|IEBB0SRQF|IEBB0ARBF|IEBB0ALTF|IEBB0ACKF|IEBB0LCKF|-|-|
||IEBB0ISR|-|IEBB0IEBE|IEBB0STRF|IEBB0STSF|IEBB0ETRF|IEBB0EFMF|-|IEBB0FOVE|
||IEBB0ESR|IEBB0TIME|IEBB0PARE|IEBB0NACE|IEBB0UNRE|IEBB0OVRE|-|IEBB0ABTE|IEBB0TRDE|
||IEBB0FSR|IEBB0RTRF|IEBB0TTRF|-|-|-|-|IEBB0SSFS1|IEBB0SSFS0|
||IEBB0SCR|||||||||
||IEBB0CCR|||||||||
||IEBB0STC0|IEBB0CLTM|IEBB0CLPA|IEBB0CLNC|IEBB0CLUR|IEBB0CLOV|-|IEBB0CLAB|IEBB0CLTR|
||IEBB0STC1|-|-|-|-|-|-|-|IEBB0CLFF|
||IEBB0DR|||||||||
|Renesas SPDIF<br>interface|TLCA|-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
|||||||||||
||TRCA|-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
|||||||||||
||TLCS|-|-|CLAC[1]|CLAC[0]|FS[3]|FS[2]|FS[1]|FS[0]|
|||CHNO[3]|CHNO[2]|CHNO[1]|CHNO[0]|SRCNO[3]|SRCNO[2]|SRCNO[1]|SRCNO[0]|
|||CATCD[7]|CATCD[6]|CATCD[5]|CATCD[4]|CATCD[3]|CATCD[2]|CATCD[1]|CATCD[0]|
|||–|–|CTL[4]|CTL[3]|CTL[2]|CTL[1]|CTL[0]|–|
||TRCS|-|-|CLAC[1]|CLAC[0]|FS[3]|FS[2]|FS[1]|FS[0]|
|||CHNO[3]|CHNO[2]|CHNO[1]|CHNO[0]|SRCNO[3]|SRCNO[2]|SRCNO[1]|SRCNO[0]|
|||CATCD[7]|CATCD[6]|CATCD[5]|CATCD[4]|CATCD[3]|CATCD[2]|CATCD[1]|CATCD[0]|
|||–|–|CTL[4]|CTL[3]|CTL[2]|CTL[1]|CTL[0]|–|
||TUI|||||||||
|||||||||||
|||||||||||
|||||||||||

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Renesas SPDIF<br>interface|RLCA|-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
|||||||||||
||RRCA|-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
|||||||||||
||RLCS|-|-|CLAC[1]|CLAC[0]|FS[3]|FS[2]|FS[1]|FS[0]|
|||CHNO[3]|CHNO[2]|CHNO[1]|CHNO[0]|SRCNO[3]|SRCNO[2]|SRCNO[1]|SRCNO[0]|
|||CATCD[7]|CATCD[6]|CATCD[5]|CATCD[4]|CATCD[3]|CATCD[2]|CATCD[1]|CATCD[0]|
|||–|–|CTL[4]|CTL[3]|CTL[2]|CTL[1]|CTL[0]|–|
||RRCS|-|-|CLAC[1]|CLAC[0]|FS[3]|FS[2]|FS[1]|FS[0]|
|||CHNO[3]|CHNO[2]|CHNO[1]|CHNO[0]|SRCNO[3]|SRCNO[2]|SRCNO[1]|SRCNO[0]|
|||CATCD[7]|CATCD[6]|CATCD[5]|CATCD[4]|CATCD[3]|CATCD[2]|CATCD[1]|CATCD[0]|
|||–|–|CTL[4]|CTL[3]|CTL[2]|CTL[1]|CTL[0]|–|
||RUI|||||||||
|||||||||||
|||||||||||
|||||||||||
||CTRL|-|-|-|CKS|-|PB|RASS[1]|RASS[0]|
|||TASS[1]|TASS[0]|RDE|TDE|NCSI|AOS|RME|TME|
|||REIE|TEIE|UBOI|UBUI|CREI|PAEI|PREI|CSEI|
|||ABOI|ABUI|RUII|TUII|RCSI|RCBI|TCSI|TCBI|
||STAT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|CMD|
|||RIS|TIS|UBO|UBU|CE|PARE|PREE|CSE|
|||ABO|ABU|RUIR|TUIR|CSRX|CBRX|CSTX|CBTX|
||TDAD|-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
|||||||||||
||RDAD|-|-|-|-|-|-|-|-|
|||||||||||
|||||||||||
|||||||||||
|CD-ROM decoder<br>*1|<br>CROMEN|SUBC_EN|CROM_EN|CROM_STP|-|-|-|-|-|
||CROMSY0|SY_AUT|SY_IEN|SY_DEN|-|-|-|-|-|
||CROMCTL0|MD_DESC|-|MD_AUTO|MD_AUTOS1|MD_AUTOS2|MD_SEC[2]|MD_SEC[1]|MD_SEC[0]|
||CROMCTL1|M2F2EDC|MD_DEC[2]|MD_DEC[1]|MD_DEC[0]|-|-|MD_PQREP[1]|MD_PQREP[0]|
||CROMCTL3|STP_ECC|STP_EDC|-|STP_MD|STP_MIN|-|-|-|
||CROMCTL4|-|LINK2|-|EROSEL|NO_ECC|-|-|-|
||CROMCTL5|-|-|-|-|-|-|-|MSF_LBA_SEL|
||CROMST0|-|-|ST_SYIL|ST_SYNO|ST_BLKS|ST_BLKL|ST_SECS|ST_SECL|
||CROMST1|-|-|-|-|ER2_HEAD0|ER2_HEAD1|ER2_HEAD2|ER2_HEAD3|
||CROMST3|ER2_SHEAD0|ER2_SHEAD1|ER2_SHEAD2|ER2_SHEAD3|ER2_SHEAD4|ER2_SHEAD5|ER2_SHEAD6|ER2_SHEAD7|
||CROMST4|NG_MD|NG_MDCMP1|NG_MDCMP2|NG_MDCMP3|NG_MDCMP4|NG_MDDEF|NG_MDTIM1|NG_MDTIM2|
||CROMST5|ST_AMD[2]|ST_AMD[1]|ST_AMD[0]|ST_MDX|LINK_ON|LINK_DET|LINK_SDET|LINK_OUT1|
||CROMST6|ST_ERR|-|ST_ECCABT|ST_ECCNG|ST_ECCP|ST_ECCQ|ST_EDC1|ST_EDC2|
||CBUFST0|BUF_REF|BUF_ACT|-|-|-|-|-|-|
||CBUFST1|BUF_ECC|BUF_EDC|-|BUF_MD|BUF_MIN|-|-|-|
||CBUFST2|BUF_NG|-|-|-|-|-|-|-|
||HEAD00|HEAD00[7]|HEAD00[6]|HEAD00[5]|HEAD00[4]|HEAD00[3]|HEAD00[2]|HEAD00[1]|HEAD00[0]|
||HEAD01|HEAD01[7]|HEAD01[6]|HEAD01[5]|HEAD01[4]|HEAD01[3]|HEAD01[2]|HEAD01[1]|HEAD01[0]|
||HEAD02|HEAD02[7]|HEAD02[6]|HEAD02[5]|HEAD02[4]|HEAD02[3]|HEAD02[2]|HEAD02[1]|HEAD02[0]|
||HEAD03|HEAD03[7]|HEAD03[6]|HEAD03[5]|HEAD03[4]|HEAD03[3]|HEAD03[2]|HEAD03[1]|HEAD03[0]|
||SHEAD00|SHEAD00[7]|SHEAD00[6]|SHEAD00[5]|SHEAD00[4]|SHEAD00[3]|SHEAD00[2]|SHEAD00[1]|SHEAD00[0]|
||SHEAD01|SHEAD01[7]|SHEAD01[6]|SHEAD01[5]|SHEAD01[4]|SHEAD01[3]|SHEAD01[2]|SHEAD01[1]|SHEAD01[0]|
||SHEAD02|SHEAD02[7]|SHEAD02[6]|SHEAD02[5]|SHEAD02[4]|SHEAD02[3]|SHEAD02[2]|SHEAD02[1]|SHEAD02[0]|
||SHEAD03|SHEAD03[7]|SHEAD03[6]|SHEAD03[5]|SHEAD03[4]|SHEAD03[3]|SHEAD03[2]|SHEAD03[1]|SHEAD03[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|CD-ROM decoder<br>*1|<br>SHEAD04|SHEAD04[7]|SHEAD04[6]|SHEAD04[5]|SHEAD04[4]|SHEAD04[3]|SHEAD04[2]|SHEAD04[1]|SHEAD04[0]|
||SHEAD05|SHEAD05[7]|SHEAD05[6]|SHEAD05[5]|SHEAD05[4]|SHEAD05[3]|SHEAD05[2]|SHEAD05[1]|SHEAD05[0]|
||SHEAD06|SHEAD06[7]|SHEAD06[6]|SHEAD06[5]|SHEAD06[4]|SHEAD06[3]|SHEAD06[2]|SHEAD06[1]|SHEAD06[0]|
||SHEAD07|SHEAD07[7]|SHEAD07[6]|SHEAD07[5]|SHEAD07[4]|SHEAD07[3]|SHEAD07[2]|SHEAD07[1]|SHEAD07[0]|
||HEAD20|HEAD20[7]|HEAD20[6]|HEAD20[5]|HEAD20[4]|HEAD20[3]|HEAD20[2]|HEAD20[1]|HEAD20[0]|
||HEAD21|HEAD21[7]|HEAD21[6]|HEAD21[5]|HEAD21[4]|HEAD21[3]|HEAD21[2]|HEAD21[1]|HEAD21[0]|
||HEAD22|HEAD22[7]|HEAD22[6]|HEAD22[5]|HEAD22[4]|HEAD22[3]|HEAD22[2]|HEAD22[1]|HEAD22[0]|
||HEAD23|HEAD23[7]|HEAD23[6]|HEAD23[5]|HEAD23[4]|HEAD23[3]|HEAD23[2]|HEAD23[1]|HEAD23[0]|
||SHEAD20|SHEAD20[7]|SHEAD20[6]|SHEAD20[5]|SHEAD20[4]|SHEAD20[3]|SHEAD20[2]|SHEAD20[1]|SHEAD20[0]|
||SHEAD21|SHEAD21[7]|SHEAD21[6]|SHEAD21[5]|SHEAD21[4]|SHEAD21[3]|SHEAD21[2]|SHEAD21[1]|SHEAD21[0]|
||SHEAD22|SHEAD22[7]|SHEAD22[6]|SHEAD22[5]|SHEAD22[4]|SHEAD22[3]|SHEAD22[2]|SHEAD22[1]|SHEAD22[0]|
||SHEAD23|SHEAD23[7]|SHEAD23[6]|SHEAD23[5]|SHEAD23[4]|SHEAD23[3]|SHEAD23[2]|SHEAD23[1]|SHEAD23[0]|
||SHEAD24|SHEAD24[7]|SHEAD24[6]|SHEAD24[5]|SHEAD24[4]|SHEAD24[3]|SHEAD24[2]|SHEAD24[1]|SHEAD24[0]|
||SHEAD25|SHEAD25[7]|SHEAD25[6]|SHEAD25[5]|SHEAD25[4]|SHEAD25[3]|SHEAD25[2]|SHEAD25[1]|SHEAD25[0]|
||SHEAD26|SHEAD26[7]|SHEAD26[6]|SHEAD26[5]|SHEAD26[4]|SHEAD26[3]|SHEAD26[2]|SHEAD26[1]|SHEAD26[0]|
||SHEAD27|SHEAD27[7]|SHEAD27[6]|SHEAD27[5]|SHEAD27[4]|SHEAD27[3]|SHEAD27[2]|SHEAD27[1]|SHEAD27[0]|
||CBUFCTL0|CBUF_AUT|CBUF_EN|-|CBUF_MD[1]|CBUF_MD[0]|CBUF_TS|CBUF_Q|-|
||CBUFCTL1|BS_MIN[7]|BS_MIN[6]|BS_MIN[5]|BS_MIN[4]|BS_MIN[3]|BS_MIN[2]|BS_MIN[1]|BS_MIN[0]|
||CBUFCTL2|BS_SEC[7]|BS_SEC[6]|BS_SEC[5]|BS_SEC[4]|BS_SEC[3]|BS_SEC[2]|BS_SEC[1]|BS_SEC[0]|
||CBUFCTL3|BS_FRM[7]|BS_FRM[6]|BS_FRM[5]|BS_FRM[4]|BS_FRM[3]|BS_FRM[2]|BS_FRM[1]|BS_FRM[0]|
||CROMST0M|-|-|ST_SYILM|ST_SYNOM|ST_BLKSM|ST_BLKLM|ST_SECSM|ST_SECLM|
||ROMDECRST|LOGICRST|RAMRST|-|-|-|-|-|-|
||RSTSTAT|RAMCLRST|-|-|-|-|-|-|-|
||SSI|BYTEND|BITEND|BUFEND0[1]|BUFEND0[0]|BUFEND1[1]|BUFEND1[0]|-|-|
||INTHOLD|ISEC|ITARG|ISY|IERR|IBUF|IREADY|-|-|
||INHINT|INHISEC|INHITARG|INHISY|INHIERR|INHIBUF|INHIREADY|PREINHREQDM|PREINHIREADY|
||STRMDIN0|STRMDIN[31]|STRMDIN[30]|STRMDIN[29]|STRMDIN[28]|STRMDIN[27]|STRMDIN[26]|STRMDIN[25]|STRMDIN[24]|
|||STRMDIN[23]|STRMDIN[22]|STRMDIN[21]|STRMDIN[20]|STRMDIN[19]|STRMDIN[18]|STRMDIN[17]|STRMDIN[16]|
||STRMDIN2|STRMDIN[15]|STRMDIN[14]|STRMDIN[13]|STRMDIN[12]|STRMDIN[11]|STRMDIN[10]|STRMDIN[9]|STRMDIN[8]|
|||STRMDIN[7]|STRMDIN[6]|STRMDIN[5]|STRMDIN[4]|STRMDIN[3]|STRMDIN[2]|STRMDIN[1]|STRMDIN[0]|
||STRMDOUT0|STRMDOUT[15]|STRMDOUT[14]|STRMDOUT[13]|STRMDOUT[12]|STRMDOUT[11]|STRMDOUT[10]|STRMDOUT[9]|STRMDOUT[8]|
|||STRMDOUT[7]|STRMDOUT[6]|STRMDOUT[5]|STRMDOUT[4]|STRMDOUT[3]|STRMDOUT[2]|STRMDOUT[1]|STRMDOUT[0]|
|LIN interface<br>LIN master*1|RLN30LWBR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||NSPB[3]|NSPB[2]|NSPB[1]|NSPB[0]|LPRS[2]|LPRS[1]|LPRS[0]|LWBR0|
||RLN30LBRP0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LBRP0[7]|LBRP0[6]|LBRP0[5]|LBRP0[4]|LBRP0[3]|LBRP0[2]|LBRP0[1]|LBRP0[0]|
||RLN30LBRP1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LBRP1[7]|LBRP1[6]|LBRP1[5]|LBRP1[4]|LBRP1[3]|LBRP1[2]|LBRP1[1]|LBRP1[0]|
||RLN30LSTC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|LSTM|
||RLN30LMD|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|LRDNFS|LIOS|LCKS[1]|LCKS[0]|LMD[1]|LMD[0]|
||RLN30LBFC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|BDT[1]|BDT[0]|BLT[3]|BLT[2]|BLT[1]|BLT[0]|
||RLN30LSC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|IBS[1]|IBS[0]|-|IBHS[2]|IBHS[1]|IBHS[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|LIN interface<br>LIN master*1|RLN30LWUP|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||WUTL[3]|WUTL[2]|WUTL[1]|WUTL[0]|-|-|-|-|
||RLN30LIE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SHIE|ERRIE|FRCIE|FTCIE|
||RLN30LEDE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LTES|-|-|-|FERE|FTERE|PBERE|BERE|
||RLN30LCUC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|OM1|OM0|
||RLN30LTRC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|RTS|FTS|
||RLN30LMST|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|OMM1|OMM0|
||RLN30LST|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||HTRC|D1RC|-|-|ERR|-|FRC|FTC|
||RLN30LEST|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RPER|-|CSER|-|FER|FTER|PBER|BER|
||RLN30LDFC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LSS|FSM|CSM|RFT|RFDL[3]|RFDL[2]|RFDL[1]|RFDL[0]|
||RLN30LIDB|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||IDP1|IDP0|ID[5]|ID[4]|ID[3]|ID[2]|ID[1]|ID[0]|
||RLN30LCBR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CKSM[7]|CKSM[6]|CKSM[5]|CKSM[4]|CKSM[3]|CKSM[2]|CKSM[1]|CKSM[0]|
||RLN30LDBR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LDB[7]|LDB[6]|LDB[5]|LDB[4]|LDB[3]|LDB[2]|LDB[1]|LDB[0]|
||RLN30LDBR2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LDB[7]|LDB[6]|LDB[5]|LDB[4]|LDB[3]|LDB[2]|LDB[1]|LDB[0]|
||RLN30LDBR3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LDB[7]|LDB[6]|LDB[5]|LDB[4]|LDB[3]|LDB[2]|LDB[1]|LDB[0]|
||RLN30LDBR4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LDB[7]|LDB[6]|LDB[5]|LDB[4]|LDB[3]|LDB[2]|LDB[1]|LDB[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|LIN interface<br>LIN master*1|RLN30LDBR5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LDB[7]|LDB[6]|LDB[5]|LDB[4]|LDB[3]|LDB[2]|LDB[1]|LDB[0]|
||RLN30LDBR6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LDB[7]|LDB[6]|LDB[5]|LDB[4]|LDB[3]|LDB[2]|LDB[1]|LDB[0]|
||RLN30LDBR7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LDB[7]|LDB[6]|LDB[5]|LDB[4]|LDB[3]|LDB[2]|LDB[1]|LDB[0]|
||RLN30LDBR8|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LDB[7]|LDB[6]|LDB[5]|LDB[4]|LDB[3]|LDB[2]|LDB[1]|LDB[0]|
|Ethernet<br>controller|ARSTR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ARST|
||ECMR0|-|-|-|-|-|TRCCM|-|-|
|||RCSC|-|DPAD|RZPF|ZPF|PFR|RXF|TXXF|
|||-|-|MCT|-|-|-|-|-|
|||-|RE|TE|-|-|-|DM|PRM|
||ECSR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|PFROI|-|-|-|ICD|
||ECSIPR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|PFROIP|-|-|-|ICDIP|
||PIR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|MDI|MDO|MMD|MDC|
||MAHR0|MA[47]|MA[46]|MA[45]|MA[44]|MA[43]|MA[42]|MA[41]|MA[40]|
|||MA[39]|MA[38]|MA[37]|MA[36]|MA[35]|MA[34]|MA[33]|MA[32]|
|||MA[31]|MA[30]|MA[29]|MA[28]|MA[27]|MA[26]|MA[25]|MA[24]|
|||MA[23]|MA[22]|MA[21]|MA[20]|MA[19]|MA[18]|MA[17]|MA[16]|
||MALR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||MA[15]|MA[14]|MA[13]|MA[12]|MA[11]|MA[10]|MA[9]|MA[8]|
|||MA[7]|MA[6]|MA[5]|MA[4]|MA[3]|MA[2]|MA[1]|MA[0]|
||RFLR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|RFL[17]|RFL[16]|
|||RFL[15]|RFL[14]|RFL[13]|RFL[12]|RFL[11]|RFL[10]|RFL[9]|RFL[8]|
|||RFL[7]|RFL[6]|RFL[5]|RFL[4]|RFL[3]|RFL[2]|RFL[1]|RFL[0]|
||CEFCR0|CEFC[31]|CEFC[30]|CEFC[29]|CEFC[28]|CEFC[27]|CEFC[26]|CEFC[25]|CEFC[24]|
|||CEFC[23]|CEFC[22]|CEFC[21]|CEFC[20]|CEFC[19]|CEFC[18]|CEFC[17]|CEFC[16]|
|||CEFC[15]|CEFC[14]|CEFC[13]|CEFC[12]|CEFC[11]|CEFC[10]|CEFC[9]|CEFC[8]|
|||CEFC[7]|CEFC[6]|CEFC[5]|CEFC[4]|CEFC[3]|CEFC[2]|CEFC[1]|CEFC[0]|
||FRECR0|FREC[31]|FREC[30]|FREC[29]|FREC[28]|FREC[27]|FREC[26]|FREC[25]|FREC[24]|
|||FREC[23]|FREC[22]|FREC[21]|FREC[20]|FREC[19]|FREC[18]|FREC[17]|FREC[16]|
|||FREC[15]|FREC[14]|FREC[13]|FREC[12]|FREC[11]|FREC[10]|FREC[9]|FREC[8]|
|||FREC[7]|FREC[6]|FREC[5]|FREC[4]|FREC[3]|FREC[2]|FREC[1]|FREC[0]|
||TSFRCR0|TSFC[31]|TSFC[30]|TSFC[29]|TSFC[28]|TSFC[27]|TSFC[26]|TSFC[25]|TSFC[24]|
|||TSFC[23]|TSFC[22]|TSFC[21]|TSFC[20]|TSFC[19]|TSFC[18]|TSFC[17]|TSFC[16]|
|||TSFC[15]|TSFC[14]|TSFC[13]|TSFC[12]|TSFC[11]|TSFC[10]|TSFC[9]|TSFC[8]|
|||TSFC[7]|TSFC[6]|TSFC[5]|TSFC[4]|TSFC[3]|TSFC[2]|TSFC[1]|TSFC[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ethernet<br>controller|TLFRCR0|TLFC[31]|TLFC[30]|TLFC[29]|TLFC[28]|TLFC[27]|TLFC[26]|TLFC[25]|TLFC[24]|
|||TLFC[23]|TLFC[22]|TLFC[21]|TLFC[20]|TLFC[19]|TLFC[18]|TLFC[17]|TLFC[16]|
|||TLFC[15]|TLFC[14]|TLFC[13]|TLFC[12]|TLFC[11]|TLFC[10]|TLFC[9]|TLFC[8]|
|||TLFC[7]|TLFC[6]|TLFC[5]|TLFC[4]|TLFC[3]|TLFC[2]|TLFC[1]|TLFC[0]|
||RFCR0|RFC[31]|RFC[30]|RFC[29]|RFC[28]|RFC[27]|RFC[26]|RFC[25]|RFC[24]|
|||RFC[23]|RFC[22]|RFC[21]|RFC[20]|RFC[19]|RFC[18]|RFC[17]|RFC[16]|
|||RFC[15]|RFC[14]|RFC[13]|RFC[12]|RFC[11]|RFC[10]|RFC[9]|RFC[8]|
|||RFC[7]|RFC[6]|RFC[5]|RFC[4]|RFC[3]|RFC[2]|RFC[1]|RFC[0]|
||MAFCR0|MAFC[31]|MAFC[30]|MAFC[29]|MAFC[28]|MAFC[27]|MAFC[26]|MAFC[25]|MAFC[24]|
|||MAFC[23]|MAFC[22]|MAFC[21]|MAFC[20]|MAFC[19]|MAFC[18]|MAFC[17]|MAFC[16]|
|||MAFC[15]|MAFC[14]|MAFC[13]|MAFC[12]|MAFC[11]|MAFC[10]|MAFC[9]|MAFC[8]|
|||MAFC[7]|MAFC[6]|MAFC[5]|MAFC[4]|MAFC[3]|MAFC[2]|MAFC[1]|MAFC[0]|
||APR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||AP[15]|AP[14]|AP[13]|AP[12]|AP[11]|AP[10]|AP[9]|AP[8]|
|||AP[7]|AP[6]|AP[5]|AP[4]|AP[3]|AP[2]|AP[1]|AP[0]|
||MPR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||MP[15]|MP[14]|MP[13]|MP[12]|MP[11]|MP[10]|MP[9]|MP[8]|
|||MP[7]|MP[6]|MP[5]|MP[4]|MP[3]|MP[2]|MP[1]|MP[0]|
||TPAUSER0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TPAUSE[15]|TPAUSE[14]|TPAUSE[13]|TPAUSE[12]|TPAUSE[11]|TPAUSE[10]|TPAUSE[9]|TPAUSE[8]|
|||TPAUSE[7]|TPAUSE[6]|TPAUSE[5]|TPAUSE[4]|TPAUSE[3]|TPAUSE[2]|TPAUSE[1]|TPAUSE[0]|
||PFTCR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||PFTXC[15]|PFTXC[14]|PFTXC[13]|PFTXC[12]|PFTXC[11]|PFTXC[10]|PFTXC[9]|PFTXC[8]|
|||PFTXC[7]|PFTXC[6]|PFTXC[5]|PFTXC[4]|PFTXC[3]|PFTXC[2]|PFTXC[1]|PFTXC[0]|
||PFRCR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||PFRXC[15]|PFRXC[14]|PFRXC[13]|PFRXC[12]|PFRXC[11]|PFRXC[10]|PFRXC[9]|PFRXC[8]|
|||PFRXC[7]|PFRXC[6]|PFRXC[5]|PFRXC[4]|PFRXC[3]|PFRXC[2]|PFRXC[1]|PFRXC[0]|
||TSU_CTRST|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|CTRST|
|||-|-|-|-|-|-|-|-|
||TSU_FWSLC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|POSTENU|POSTENL|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||TSU_VTAG0|VTAG0|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|VID0[11]|VID0[10]|VID0[9]|VID0[8]|
|||VID0[7]|VID0[6]|VID0[5]|VID0[4]|VID0[3]|VID0[2]|VID0[1]|VID0[0]|
||TSU_ADSBSY|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ADSBSY|
||TSU_TEN|TEN0|TEN1|TEN2|TEN3|TEN4|TEN5|TEN6|TEN7|
|||TEN8|TEN9|TEN10|TEN11|TEN12|TEN13|TEN14|TEN15|
|||TEN16|TEN17|TEN18|TEN19|TEN20|TEN21|TEN22|TEN23|
|||TEN24|TEN25|TEN26|TEN27|TEN28|TEN29|TEN30|TEN31|
||TSU_POST1|POST0|-|-|-|POST1|-|-|-|
|||POST2|-|-|-|POST3|-|-|-|
|||POST4|-|-|-|POST5|-|-|-|
|||POST6|-|-|-|POST7|-|-|-|
||TSU_POST2|POST8|-|-|-|POST9|-|-|-|
|||POST10|-|-|-|POST11|-|-|-|
|||POST12|-|-|-|POST13|-|-|-|
|||POST14|-|-|-|POST15|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ethernet<br>controller|TSU_POST3|POST16|-|-|-|POST17|-|-|-|
|||POST18|-|-|-|POST19|-|-|-|
|||POST20|-|-|-|POST21|-|-|-|
|||POST22|-|-|-|POST23|-|-|-|
||TSU_POST4|POST24|-|-|-|POST25|-|-|-|
|||POST26|-|-|-|POST27|-|-|-|
|||POST28|-|-|-|POST29|-|-|-|
|||POST30|-|-|-|POST31|-|-|-|
||TSU_ADRH0|ADRH0[31]|ADRH0[30]|ADRH0[29]|ADRH0[28]|ADRH0[27]|ADRH0[26]|ADRH0[25]|ADRH0[24]|
|||ADRH0[23]|ADRH0[22]|ADRH0[21]|ADRH0[20]|ADRH0[19]|ADRH0[18]|ADRH0[17]|ADRH0[16]|
|||ADRH0[15]|ADRH0[14]|ADRH0[13]|ADRH0[12]|ADRH0[11]|ADRH0[10]|ADRH0[9]|ADRH0[8]|
|||ADRH0[7]|ADRH0[6]|ADRH0[5]|ADRH0[4]|ADRH0[3]|ADRH0[2]|ADRH0[1]|ADRH0[0]|
||TSU_ADRH1|ADRH1[31]|ADRH1[30]|ADRH1[29]|ADRH1[28]|ADRH1[27]|ADRH1[26]|ADRH1[25]|ADRH1[24]|
|||ADRH1[23]|ADRH1[22]|ADRH1[21]|ADRH1[20]|ADRH1[19]|ADRH1[18]|ADRH1[17]|ADRH1[16]|
|||ADRH1[15]|ADRH1[14]|ADRH1[13]|ADRH1[12]|ADRH1[11]|ADRH1[10]|ADRH1[9]|ADRH1[8]|
|||ADRH1[7]|ADRH1[6]|ADRH1[5]|ADRH1[4]|ADRH1[3]|ADRH1[2]|ADRH1[1]|ADRH1[0]|
||TSU_ADRH2|ADRH2[31]|ADRH2[30]|ADRH2[29]|ADRH2[28]|ADRH2[27]|ADRH2[26]|ADRH2[25]|ADRH2[24]|
|||ADRH2[23]|ADRH2[22]|ADRH2[21]|ADRH2[20]|ADRH2[19]|ADRH2[18]|ADRH2[17]|ADRH2[16]|
|||ADRH2[15]|ADRH2[14]|ADRH2[13]|ADRH2[12]|ADRH2[11]|ADRH2[10]|ADRH2[9]|ADRH2[8]|
|||ADRH2[7]|ADRH2[6]|ADRH2[5]|ADRH2[4]|ADRH2[3]|ADRH2[2]|ADRH2[1]|ADRH2[0]|
||TSU_ADRH3|ADRH3[31]|ADRH3[30]|ADRH3[29]|ADRH3[28]|ADRH3[27]|ADRH3[26]|ADRH3[25]|ADRH3[24]|
|||ADRH3[23]|ADRH3[22]|ADRH3[21]|ADRH3[20]|ADRH3[19]|ADRH3[18]|ADRH3[17]|ADRH3[16]|
|||ADRH3[15]|ADRH3[14]|ADRH3[13]|ADRH3[12]|ADRH3[11]|ADRH3[10]|ADRH3[9]|ADRH3[8]|
|||ADRH3[7]|ADRH3[6]|ADRH3[5]|ADRH3[4]|ADRH3[3]|ADRH3[2]|ADRH3[1]|ADRH3[0]|
||TSU_ADRH4|ADRH4[31]|ADRH4[30]|ADRH4[29]|ADRH4[28]|ADRH4[27]|ADRH4[26]|ADRH4[25]|ADRH4[24]|
|||ADRH4[23]|ADRH4[22]|ADRH4[21]|ADRH4[20]|ADRH4[19]|ADRH4[18]|ADRH4[17]|ADRH4[16]|
|||ADRH4[15]|ADRH4[14]|ADRH4[13]|ADRH4[12]|ADRH4[11]|ADRH4[10]|ADRH4[9]|ADRH4[8]|
|||ADRH4[7]|ADRH4[6]|ADRH4[5]|ADRH4[4]|ADRH4[3]|ADRH4[2]|ADRH4[1]|ADRH4[0]|
||TSU_ADRH5|ADRH5[31]|ADRH5[30]|ADRH5[29]|ADRH5[28]|ADRH5[27]|ADRH5[26]|ADRH5[25]|ADRH5[24]|
|||ADRH5[23]|ADRH5[22]|ADRH5[21]|ADRH5[20]|ADRH5[19]|ADRH5[18]|ADRH5[17]|ADRH5[16]|
|||ADRH5[15]|ADRH5[14]|ADRH5[13]|ADRH5[12]|ADRH5[11]|ADRH5[10]|ADRH5[9]|ADRH5[8]|
|||ADRH5[7]|ADRH5[6]|ADRH5[5]|ADRH5[4]|ADRH5[3]|ADRH5[2]|ADRH5[1]|ADRH5[0]|
||TSU_ADRH6|ADRH6[31]|ADRH6[30]|ADRH6[29]|ADRH6[28]|ADRH6[27]|ADRH6[26]|ADRH6[25]|ADRH6[24]|
|||ADRH6[23]|ADRH6[22]|ADRH6[21]|ADRH6[20]|ADRH6[19]|ADRH6[18]|ADRH6[17]|ADRH6[16]|
|||ADRH6[15]|ADRH6[14]|ADRH6[13]|ADRH6[12]|ADRH6[11]|ADRH6[10]|ADRH6[9]|ADRH6[8]|
|||ADRH6[7]|ADRH6[6]|ADRH6[5]|ADRH6[4]|ADRH6[3]|ADRH6[2]|ADRH6[1]|ADRH6[0]|
||TSU_ADRH7|ADRH7[31]|ADRH7[30]|ADRH7[29]|ADRH7[28]|ADRH7[27]|ADRH7[26]|ADRH7[25]|ADRH7[24]|
|||ADRH7[23]|ADRH7[22]|ADRH7[21]|ADRH7[20]|ADRH7[19]|ADRH7[18]|ADRH7[17]|ADRH7[16]|
|||ADRH7[15]|ADRH7[14]|ADRH7[13]|ADRH7[12]|ADRH7[11]|ADRH7[10]|ADRH7[9]|ADRH7[8]|
|||ADRH7[7]|ADRH7[6]|ADRH7[5]|ADRH7[4]|ADRH7[3]|ADRH7[2]|ADRH7[1]|ADRH7[0]|
||TSU_ADRH8|ADRH8[31]|ADRH8[30]|ADRH8[29]|ADRH8[28]|ADRH8[27]|ADRH8[26]|ADRH8[25]|ADRH8[24]|
|||ADRH8[23]|ADRH8[22]|ADRH8[21]|ADRH8[20]|ADRH8[19]|ADRH8[18]|ADRH8[17]|ADRH8[16]|
|||ADRH8[15]|ADRH8[14]|ADRH8[13]|ADRH8[12]|ADRH8[11]|ADRH8[10]|ADRH8[9]|ADRH8[8]|
|||ADRH8[7]|ADRH8[6]|ADRH8[5]|ADRH8[4]|ADRH8[3]|ADRH8[2]|ADRH8[1]|ADRH8[0]|
||TSU_ADRH9|ADRH9[31]|ADRH9[30]|ADRH9[29]|ADRH9[28]|ADRH9[27]|ADRH9[26]|ADRH9[25]|ADRH9[24]|
|||ADRH9[23]|ADRH9[22]|ADRH9[21]|ADRH9[20]|ADRH9[19]|ADRH9[18]|ADRH9[17]|ADRH9[16]|
|||ADRH9[15]|ADRH9[14]|ADRH9[13]|ADRH9[12]|ADRH9[11]|ADRH9[10]|ADRH9[9]|ADRH9[8]|
|||ADRH9[7]|ADRH9[6]|ADRH9[5]|ADRH9[4]|ADRH9[3]|ADRH9[2]|ADRH9[1]|ADRH9[0]|
||TSU_ADRH10|ADRH10[31]|ADRH10[30]|ADRH10[29]|ADRH10[28]|ADRH10[27]|ADRH10[26]|ADRH10[25]|ADRH10[24]|
|||ADRH10[23]|ADRH10[22]|ADRH10[21]|ADRH10[20]|ADRH10[19]|ADRH10[18]|ADRH10[17]|ADRH10[16]|
|||ADRH10[15]|ADRH10[14]|ADRH10[13]|ADRH10[12]|ADRH10[11]|ADRH10[10]|ADRH10[9]|ADRH10[8]|
|||ADRH10[7]|ADRH10[6]|ADRH10[5]|ADRH10[4]|ADRH10[3]|ADRH10[2]|ADRH10[1]|ADRH10[0]|
||TSU_ADRH11|ADRH11[31]|ADRH11[30]|ADRH11[29]|ADRH11[28]|ADRH11[27]|ADRH11[26]|ADRH11[25]|ADRH11[24]|
|||ADRH11[23]|ADRH11[22]|ADRH11[21]|ADRH11[20]|ADRH11[19]|ADRH11[18]|ADRH11[17]|ADRH11[16]|
|||ADRH11[15]|ADRH11[14]|ADRH11[13]|ADRH11[12]|ADRH11[11]|ADRH11[10]|ADRH11[9]|ADRH11[8]|
|||ADRH11[7]|ADRH11[6]|ADRH11[5]|ADRH11[4]|ADRH11[3]|ADRH11[2]|ADRH11[1]|ADRH11[0]|
||TSU_ADRH12|ADRH12[31]|ADRH12[30]|ADRH12[29]|ADRH12[28]|ADRH12[27]|ADRH12[26]|ADRH12[25]|ADRH12[24]|
|||ADRH12[23]|ADRH12[22]|ADRH12[21]|ADRH12[20]|ADRH12[19]|ADRH12[18]|ADRH12[17]|ADRH12[16]|
|||ADRH12[15]|ADRH12[14]|ADRH12[13]|ADRH12[12]|ADRH12[11]|ADRH12[10]|ADRH12[9]|ADRH12[8]|
|||ADRH12[7]|ADRH12[6]|ADRH12[5]|ADRH12[4]|ADRH12[3]|ADRH12[2]|ADRH12[1]|ADRH12[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ethernet<br>controller|TSU_ADRH13|ADRH13[31]|ADRH13[30]|ADRH13[29]|ADRH13[28]|ADRH13[27]|ADRH13[26]|ADRH13[25]|ADRH13[24]|
|||ADRH13[23]|ADRH13[22]|ADRH13[21]|ADRH13[20]|ADRH13[19]|ADRH13[18]|ADRH13[17]|ADRH13[16]|
|||ADRH13[15]|ADRH13[14]|ADRH13[13]|ADRH13[12]|ADRH13[11]|ADRH13[10]|ADRH13[9]|ADRH13[8]|
|||ADRH13[7]|ADRH13[6]|ADRH13[5]|ADRH13[4]|ADRH13[3]|ADRH13[2]|ADRH13[1]|ADRH13[0]|
||TSU_ADRH14|ADRH14[31]|ADRH14[30]|ADRH14[29]|ADRH14[28]|ADRH14[27]|ADRH14[26]|ADRH14[25]|ADRH14[24]|
|||ADRH14[23]|ADRH14[22]|ADRH14[21]|ADRH14[20]|ADRH14[19]|ADRH14[18]|ADRH14[17]|ADRH14[16]|
|||ADRH14[15]|ADRH14[14]|ADRH14[13]|ADRH14[12]|ADRH14[11]|ADRH14[10]|ADRH14[9]|ADRH14[8]|
|||ADRH14[7]|ADRH14[6]|ADRH14[5]|ADRH14[4]|ADRH14[3]|ADRH14[2]|ADRH14[1]|ADRH14[0]|
||TSU_ADRH15|ADRH15[31]|ADRH15[30]|ADRH15[29]|ADRH15[28]|ADRH15[27]|ADRH15[26]|ADRH15[25]|ADRH15[24]|
|||ADRH15[23]|ADRH15[22]|ADRH15[21]|ADRH15[20]|ADRH15[19]|ADRH15[18]|ADRH15[17]|ADRH15[16]|
|||ADRH15[15]|ADRH15[14]|ADRH15[13]|ADRH15[12]|ADRH15[11]|ADRH15[10]|ADRH15[9]|ADRH15[8]|
|||ADRH15[7]|ADRH15[6]|ADRH15[5]|ADRH15[4]|ADRH15[3]|ADRH15[2]|ADRH15[1]|ADRH15[0]|
||TSU_ADRH16|ADRH16[31]|ADRH16[30]|ADRH16[29]|ADRH16[28]|ADRH16[27]|ADRH16[26]|ADRH16[25]|ADRH16[24]|
|||ADRH16[23]|ADRH16[22]|ADRH16[21]|ADRH16[20]|ADRH16[19]|ADRH16[18]|ADRH16[17]|ADRH16[16]|
|||ADRH16[15]|ADRH16[14]|ADRH16[13]|ADRH16[12]|ADRH16[11]|ADRH16[10]|ADRH16[9]|ADRH16[8]|
|||ADRH16[7]|ADRH16[6]|ADRH16[5]|ADRH16[4]|ADRH16[3]|ADRH16[2]|ADRH16[1]|ADRH16[0]|
||TSU_ADRH17|ADRH17[31]|ADRH17[30]|ADRH17[29]|ADRH17[28]|ADRH17[27]|ADRH17[26]|ADRH17[25]|ADRH17[24]|
|||ADRH17[23]|ADRH17[22]|ADRH17[21]|ADRH17[20]|ADRH17[19]|ADRH17[18]|ADRH17[17]|ADRH17[16]|
|||ADRH17[15]|ADRH17[14]|ADRH17[13]|ADRH17[12]|ADRH17[11]|ADRH17[10]|ADRH17[9]|ADRH17[8]|
|||ADRH17[7]|ADRH17[6]|ADRH17[5]|ADRH17[4]|ADRH17[3]|ADRH17[2]|ADRH17[1]|ADRH17[0]|
||TSU_ADRH18|ADRH18[31]|ADRH18[30]|ADRH18[29]|ADRH18[28]|ADRH18[27]|ADRH18[26]|ADRH18[25]|ADRH18[24]|
|||ADRH18[23]|ADRH18[22]|ADRH18[21]|ADRH18[20]|ADRH18[19]|ADRH18[18]|ADRH18[17]|ADRH18[16]|
|||ADRH18[15]|ADRH18[14]|ADRH18[13]|ADRH18[12]|ADRH18[11]|ADRH18[10]|ADRH18[9]|ADRH18[8]|
|||ADRH18[7]|ADRH18[6]|ADRH18[5]|ADRH18[4]|ADRH18[3]|ADRH18[2]|ADRH18[1]|ADRH18[0]|
||TSU_ADRH19|ADRH19[31]|ADRH19[30]|ADRH19[29]|ADRH19[28]|ADRH19[27]|ADRH19[26]|ADRH19[25]|ADRH19[24]|
|||ADRH19[23]|ADRH19[22]|ADRH19[21]|ADRH19[20]|ADRH19[19]|ADRH19[18]|ADRH19[17]|ADRH19[16]|
|||ADRH19[15]|ADRH19[14]|ADRH19[13]|ADRH19[12]|ADRH19[11]|ADRH19[10]|ADRH19[9]|ADRH19[8]|
|||ADRH19[7]|ADRH19[6]|ADRH19[5]|ADRH19[4]|ADRH19[3]|ADRH19[2]|ADRH19[1]|ADRH19[0]|
||TSU_ADRH20|ADRH20[31]|ADRH20[30]|ADRH20[29]|ADRH20[28]|ADRH20[27]|ADRH20[26]|ADRH20[25]|ADRH20[24]|
|||ADRH20[23]|ADRH20[22]|ADRH20[21]|ADRH20[20]|ADRH20[19]|ADRH20[18]|ADRH20[17]|ADRH20[16]|
|||ADRH20[15]|ADRH20[14]|ADRH20[13]|ADRH20[12]|ADRH20[11]|ADRH20[10]|ADRH20[9]|ADRH20[8]|
|||ADRH20[7]|ADRH20[6]|ADRH20[5]|ADRH20[4]|ADRH20[3]|ADRH20[2]|ADRH20[1]|ADRH20[0]|
||TSU_ADRH21|ADRH21[31]|ADRH21[30]|ADRH21[29]|ADRH21[28]|ADRH21[27]|ADRH21[26]|ADRH21[25]|ADRH21[24]|
|||ADRH21[23]|ADRH21[22]|ADRH21[21]|ADRH21[20]|ADRH21[19]|ADRH21[18]|ADRH21[17]|ADRH21[16]|
|||ADRH21[15]|ADRH21[14]|ADRH21[13]|ADRH21[12]|ADRH21[11]|ADRH21[10]|ADRH21[9]|ADRH21[8]|
|||ADRH21[7]|ADRH21[6]|ADRH21[5]|ADRH21[4]|ADRH21[3]|ADRH21[2]|ADRH21[1]|ADRH21[0]|
||TSU_ADRH22|ADRH22[31]|ADRH22[30]|ADRH22[29]|ADRH22[28]|ADRH22[27]|ADRH22[26]|ADRH22[25]|ADRH22[24]|
|||ADRH22[23]|ADRH22[22]|ADRH22[21]|ADRH22[20]|ADRH22[19]|ADRH22[18]|ADRH22[17]|ADRH22[16]|
|||ADRH22[15]|ADRH22[14]|ADRH22[13]|ADRH22[12]|ADRH22[11]|ADRH22[10]|ADRH22[9]|ADRH22[8]|
|||ADRH22[7]|ADRH22[6]|ADRH22[5]|ADRH22[4]|ADRH22[3]|ADRH22[2]|ADRH22[1]|ADRH22[0]|
||TSU_ADRH23|ADRH23[31]|ADRH23[30]|ADRH23[29]|ADRH23[28]|ADRH23[27]|ADRH23[26]|ADRH23[25]|ADRH23[24]|
|||ADRH23[23]|ADRH23[22]|ADRH23[21]|ADRH23[20]|ADRH23[19]|ADRH23[18]|ADRH23[17]|ADRH23[16]|
|||ADRH23[15]|ADRH23[14]|ADRH23[13]|ADRH23[12]|ADRH23[11]|ADRH23[10]|ADRH23[9]|ADRH23[8]|
|||ADRH23[7]|ADRH23[6]|ADRH23[5]|ADRH23[4]|ADRH23[3]|ADRH23[2]|ADRH23[1]|ADRH23[0]|
||TSU_ADRH24|ADRH24[31]|ADRH24[30]|ADRH24[29]|ADRH24[28]|ADRH24[27]|ADRH24[26]|ADRH24[25]|ADRH24[24]|
|||ADRH24[23]|ADRH24[22]|ADRH24[21]|ADRH24[20]|ADRH24[19]|ADRH24[18]|ADRH24[17]|ADRH24[16]|
|||ADRH24[15]|ADRH24[14]|ADRH24[13]|ADRH24[12]|ADRH24[11]|ADRH24[10]|ADRH24[9]|ADRH24[8]|
|||ADRH24[7]|ADRH24[6]|ADRH24[5]|ADRH24[4]|ADRH24[3]|ADRH24[2]|ADRH24[1]|ADRH24[0]|
||TSU_ADRH25|ADRH25[31]|ADRH25[30]|ADRH25[29]|ADRH25[28]|ADRH25[27]|ADRH25[26]|ADRH25[25]|ADRH25[24]|
|||ADRH25[23]|ADRH25[22]|ADRH25[21]|ADRH25[20]|ADRH25[19]|ADRH25[18]|ADRH25[17]|ADRH25[16]|
|||ADRH25[15]|ADRH25[14]|ADRH25[13]|ADRH25[12]|ADRH25[11]|ADRH25[10]|ADRH25[9]|ADRH25[8]|
|||ADRH25[7]|ADRH25[6]|ADRH25[5]|ADRH25[4]|ADRH25[3]|ADRH25[2]|ADRH25[1]|ADRH25[0]|
||TSU_ADRH26|ADRH26[31]|ADRH26[30]|ADRH26[29]|ADRH26[28]|ADRH26[27]|ADRH26[26]|ADRH26[25]|ADRH26[24]|
|||ADRH26[23]|ADRH26[22]|ADRH26[21]|ADRH26[20]|ADRH26[19]|ADRH26[18]|ADRH26[17]|ADRH26[16]|
|||ADRH26[15]|ADRH26[14]|ADRH26[13]|ADRH26[12]|ADRH26[11]|ADRH26[10]|ADRH26[9]|ADRH26[8]|
|||ADRH26[7]|ADRH26[6]|ADRH26[5]|ADRH26[4]|ADRH26[3]|ADRH26[2]|ADRH26[1]|ADRH26[0]|
||TSU_ADRH27|ADRH27[31]|ADRH27[30]|ADRH27[29]|ADRH27[28]|ADRH27[27]|ADRH27[26]|ADRH27[25]|ADRH27[24]|
|||ADRH27[23]|ADRH27[22]|ADRH27[21]|ADRH27[20]|ADRH27[19]|ADRH27[18]|ADRH27[17]|ADRH27[16]|
|||ADRH27[15]|ADRH27[14]|ADRH27[13]|ADRH27[12]|ADRH27[11]|ADRH27[10]|ADRH27[9]|ADRH27[8]|
|||ADRH27[7]|ADRH27[6]|ADRH27[5]|ADRH27[4]|ADRH27[3]|ADRH27[2]|ADRH27[1]|ADRH27[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ethernet<br>controller|TSU_ADRH28|ADRH28[31]|ADRH28[30]|ADRH28[29]|ADRH28[28]|ADRH28[27]|ADRH28[26]|ADRH28[25]|ADRH28[24]|
|||ADRH28[23]|ADRH28[22]|ADRH28[21]|ADRH28[20]|ADRH28[19]|ADRH28[18]|ADRH28[17]|ADRH28[16]|
|||ADRH28[15]|ADRH28[14]|ADRH28[13]|ADRH28[12]|ADRH28[11]|ADRH28[10]|ADRH28[9]|ADRH28[8]|
|||ADRH28[7]|ADRH28[6]|ADRH28[5]|ADRH28[4]|ADRH28[3]|ADRH28[2]|ADRH28[1]|ADRH28[0]|
||TSU_ADRH29|ADRH29[31]|ADRH29[30]|ADRH29[29]|ADRH29[28]|ADRH29[27]|ADRH29[26]|ADRH29[25]|ADRH29[24]|
|||ADRH29[23]|ADRH29[22]|ADRH29[21]|ADRH29[20]|ADRH29[19]|ADRH29[18]|ADRH29[17]|ADRH29[16]|
|||ADRH29[15]|ADRH29[14]|ADRH29[13]|ADRH29[12]|ADRH29[11]|ADRH29[10]|ADRH29[9]|ADRH29[8]|
|||ADRH29[7]|ADRH29[6]|ADRH29[5]|ADRH29[4]|ADRH29[3]|ADRH29[2]|ADRH29[1]|ADRH29[0]|
||TSU_ADRH30|ADRH30[31]|ADRH30[30]|ADRH30[29]|ADRH30[28]|ADRH30[27]|ADRH30[26]|ADRH30[25]|ADRH30[24]|
|||ADRH30[23]|ADRH30[22]|ADRH30[21]|ADRH30[20]|ADRH30[19]|ADRH30[18]|ADRH30[17]|ADRH30[16]|
|||ADRH30[15]|ADRH30[14]|ADRH30[13]|ADRH30[12]|ADRH30[11]|ADRH30[10]|ADRH30[9]|ADRH30[8]|
|||ADRH30[7]|ADRH30[6]|ADRH30[5]|ADRH30[4]|ADRH30[3]|ADRH30[2]|ADRH30[1]|ADRH30[0]|
||TSU_ADRH31|ADRH31[31]|ADRH31[30]|ADRH31[29]|ADRH31[28]|ADRH31[27]|ADRH31[26]|ADRH31[25]|ADRH31[24]|
|||ADRH31[23]|ADRH31[22]|ADRH31[21]|ADRH31[20]|ADRH31[19]|ADRH31[18]|ADRH31[17]|ADRH31[16]|
|||ADRH31[15]|ADRH31[14]|ADRH31[13]|ADRH31[12]|ADRH31[11]|ADRH31[10]|ADRH31[9]|ADRH31[8]|
|||ADRH31[7]|ADRH31[6]|ADRH31[5]|ADRH31[4]|ADRH31[3]|ADRH31[2]|ADRH31[1]|ADRH31[0]|
||TSU_ADRL0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL0[15]|ADRL0[14]|ADRL0[13]|ADRL0[12]|ADRL0[11]|ADRL0[10]|ADRL0[9]|ADRL0[8]|
|||ADRL0[7]|ADRL0[6]|ADRL0[5]|ADRL0[4]|ADRL0[3]|ADRL0[2]|ADRL0[1]|ADRL0[0]|
||TSU_ADRL1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL1[15]|ADRL1[14]|ADRL1[13]|ADRL1[12]|ADRL1[11]|ADRL1[10]|ADRL1[9]|ADRL1[8]|
|||ADRL1[7]|ADRL1[6]|ADRL1[5]|ADRL1[4]|ADRL1[3]|ADRL1[2]|ADRL1[1]|ADRL1[0]|
||TSU_ADRL2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL2[15]|ADRL2[14]|ADRL2[13]|ADRL2[12]|ADRL2[11]|ADRL2[10]|ADRL2[9]|ADRL2[8]|
|||ADRL2[7]|ADRL2[6]|ADRL2[5]|ADRL2[4]|ADRL2[3]|ADRL2[2]|ADRL2[1]|ADRL2[0]|
||TSU_ADRL3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL3[15]|ADRL3[14]|ADRL3[13]|ADRL3[12]|ADRL3[11]|ADRL3[10]|ADRL3[9]|ADRL3[8]|
|||ADRL3[7]|ADRL3[6]|ADRL3[5]|ADRL3[4]|ADRL3[3]|ADRL3[2]|ADRL3[1]|ADRL3[0]|
||TSU_ADRL4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL4[15]|ADRL4[14]|ADRL4[13]|ADRL4[12]|ADRL4[11]|ADRL4[10]|ADRL4[9]|ADRL4[8]|
|||ADRL4[7]|ADRL4[6]|ADRL4[5]|ADRL4[4]|ADRL4[3]|ADRL4[2]|ADRL4[1]|ADRL4[0]|
||TSU_ADRL5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL5[15]|ADRL5[14]|ADRL5[13]|ADRL5[12]|ADRL5[11]|ADRL5[10]|ADRL5[9]|ADRL5[8]|
|||ADRL5[7]|ADRL5[6]|ADRL5[5]|ADRL5[4]|ADRL5[3]|ADRL5[2]|ADRL5[1]|ADRL5[0]|
||TSU_ADRL6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL6[15]|ADRL6[14]|ADRL6[13]|ADRL6[12]|ADRL6[11]|ADRL6[10]|ADRL6[9]|ADRL6[8]|
|||ADRL6[7]|ADRL6[6]|ADRL6[5]|ADRL6[4]|ADRL6[3]|ADRL6[2]|ADRL6[1]|ADRL6[0]|
||TSU_ADRL7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL7[15]|ADRL7[14]|ADRL7[13]|ADRL7[12]|ADRL7[11]|ADRL7[10]|ADRL7[9]|ADRL7[8]|
|||ADRL7[7]|ADRL7[6]|ADRL7[5]|ADRL7[4]|ADRL7[3]|ADRL7[2]|ADRL7[1]|ADRL7[0]|
||TSU_ADRL8|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL8[15]|ADRL8[14]|ADRL8[13]|ADRL8[12]|ADRL8[11]|ADRL8[10]|ADRL8[9]|ADRL8[8]|
|||ADRL8[7]|ADRL8[6]|ADRL8[5]|ADRL8[4]|ADRL8[3]|ADRL8[2]|ADRL8[1]|ADRL8[0]|
||TSU_ADRL9|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL9[15]|ADRL9[14]|ADRL9[13]|ADRL9[12]|ADRL9[11]|ADRL9[10]|ADRL9[9]|ADRL9[8]|
|||ADRL9[7]|ADRL9[6]|ADRL9[5]|ADRL9[4]|ADRL9[3]|ADRL9[2]|ADRL9[1]|ADRL9[0]|
||TSU_ADRL10|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL10[15]|ADRL10[14]|ADRL10[13]|ADRL10[12]|ADRL10[11]|ADRL10[10]|ADRL10[9]|ADRL10[8]|
|||ADRL10[7]|ADRL10[6]|ADRL10[5]|ADRL10[4]|ADRL10[3]|ADRL10[2]|ADRL10[1]|ADRL10[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ethernet<br>controller|TSU_ADRL11|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL11[15]|ADRL11[14]|ADRL11[13]|ADRL11[12]|ADRL11[11]|ADRL11[10]|ADRL11[9]|ADRL11[8]|
|||ADRL11[7]|ADRL11[6]|ADRL11[5]|ADRL11[4]|ADRL11[3]|ADRL11[2]|ADRL11[1]|ADRL11[0]|
||TSU_ADRL12|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL12[15]|ADRL12[14]|ADRL12[13]|ADRL12[12]|ADRL12[11]|ADRL12[10]|ADRL12[9]|ADRL12[8]|
|||ADRL12[7]|ADRL12[6]|ADRL12[5]|ADRL12[4]|ADRL12[3]|ADRL12[2]|ADRL12[1]|ADRL12[0]|
||TSU_ADRL13|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL13[15]|ADRL13[14]|ADRL13[13]|ADRL13[12]|ADRL13[11]|ADRL13[10]|ADRL13[9]|ADRL13[8]|
|||ADRL13[7]|ADRL13[6]|ADRL13[5]|ADRL13[4]|ADRL13[3]|ADRL13[2]|ADRL13[1]|ADRL13[0]|
||TSU_ADRL14|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL14[15]|ADRL14[14]|ADRL14[13]|ADRL14[12]|ADRL14[11]|ADRL14[10]|ADRL14[9]|ADRL14[8]|
|||ADRL14[7]|ADRL14[6]|ADRL14[5]|ADRL14[4]|ADRL14[3]|ADRL14[2]|ADRL14[1]|ADRL14[0]|
||TSU_ADRL15|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL15[15]|ADRL15[14]|ADRL15[13]|ADRL15[12]|ADRL15[11]|ADRL15[10]|ADRL15[9]|ADRL15[8]|
|||ADRL15[7]|ADRL15[6]|ADRL15[5]|ADRL15[4]|ADRL15[3]|ADRL15[2]|ADRL15[1]|ADRL15[0]|
||TSU_ADRL16|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL16[15]|ADRL16[14]|ADRL16[13]|ADRL16[12]|ADRL16[11]|ADRL16[10]|ADRL16[9]|ADRL16[8]|
|||ADRL16[7]|ADRL16[6]|ADRL16[5]|ADRL16[4]|ADRL16[3]|ADRL16[2]|ADRL16[1]|ADRL16[0]|
||TSU_ADRL17|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL17[15]|ADRL17[14]|ADRL17[13]|ADRL17[12]|ADRL17[11]|ADRL17[10]|ADRL17[9]|ADRL17[8]|
|||ADRL17[7]|ADRL17[6]|ADRL17[5]|ADRL17[4]|ADRL17[3]|ADRL17[2]|ADRL17[1]|ADRL17[0]|
||TSU_ADRL18|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL18[15]|ADRL18[14]|ADRL18[13]|ADRL18[12]|ADRL18[11]|ADRL18[10]|ADRL18[9]|ADRL18[8]|
|||ADRL18[7]|ADRL18[6]|ADRL18[5]|ADRL18[4]|ADRL18[3]|ADRL18[2]|ADRL18[1]|ADRL18[0]|
||TSU_ADRL19|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL19[15]|ADRL19[14]|ADRL19[13]|ADRL19[12]|ADRL19[11]|ADRL19[10]|ADRL19[9]|ADRL19[8]|
|||ADRL19[7]|ADRL19[6]|ADRL19[5]|ADRL19[4]|ADRL19[3]|ADRL19[2]|ADRL19[1]|ADRL19[0]|
||TSU_ADRL20|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL20[15]|ADRL20[14]|ADRL20[13]|ADRL20[12]|ADRL20[11]|ADRL20[10]|ADRL20[9]|ADRL20[8]|
|||ADRL20[7]|ADRL20[6]|ADRL20[5]|ADRL20[4]|ADRL20[3]|ADRL20[2]|ADRL20[1]|ADRL20[0]|
||TSU_ADRL21|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL21[15]|ADRL21[14]|ADRL21[13]|ADRL21[12]|ADRL21[11]|ADRL21[10]|ADRL21[9]|ADRL21[8]|
|||ADRL21[7]|ADRL21[6]|ADRL21[5]|ADRL21[4]|ADRL21[3]|ADRL21[2]|ADRL21[1]|ADRL21[0]|
||TSU_ADRL22|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL22[15]|ADRL22[14]|ADRL22[13]|ADRL22[12]|ADRL22[11]|ADRL22[10]|ADRL22[9]|ADRL22[8]|
|||ADRL22[7]|ADRL22[6]|ADRL22[5]|ADRL22[4]|ADRL22[3]|ADRL22[2]|ADRL22[1]|ADRL22[0]|
||TSU_ADRL23|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL23[15]|ADRL23[14]|ADRL23[13]|ADRL23[12]|ADRL23[11]|ADRL23[10]|ADRL23[9]|ADRL23[8]|
|||ADRL23[7]|ADRL23[6]|ADRL23[5]|ADRL23[4]|ADRL23[3]|ADRL23[2]|ADRL23[1]|ADRL23[0]|
||TSU_ADRL24|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL24[15]|ADRL24[14]|ADRL24[13]|ADRL24[12]|ADRL24[11]|ADRL24[10]|ADRL24[9]|ADRL24[8]|
|||ADRL24[7]|ADRL24[6]|ADRL24[5]|ADRL24[4]|ADRL24[3]|ADRL24[2]|ADRL24[1]|ADRL24[0]|
||TSU_ADRL25|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL25[15]|ADRL25[14]|ADRL25[13]|ADRL25[12]|ADRL25[11]|ADRL25[10]|ADRL25[9]|ADRL25[8]|
|||ADRL25[7]|ADRL25[6]|ADRL25[5]|ADRL25[4]|ADRL25[3]|ADRL25[2]|ADRL25[1]|ADRL25[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ethernet<br>controller|TSU_ADRL26|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL26[15]|ADRL26[14]|ADRL26[13]|ADRL26[12]|ADRL26[11]|ADRL26[10]|ADRL26[9]|ADRL26[8]|
|||ADRL26[7]|ADRL26[6]|ADRL26[5]|ADRL26[4]|ADRL26[3]|ADRL26[2]|ADRL26[1]|ADRL26[0]|
||TSU_ADRL27|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL27[15]|ADRL27[14]|ADRL27[13]|ADRL27[12]|ADRL27[11]|ADRL27[10]|ADRL27[9]|ADRL27[8]|
|||ADRL27[7]|ADRL27[6]|ADRL27[5]|ADRL27[4]|ADRL27[3]|ADRL27[2]|ADRL27[1]|ADRL27[0]|
||TSU_ADRL28|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL28[15]|ADRL28[14]|ADRL28[13]|ADRL28[12]|ADRL28[11]|ADRL28[10]|ADRL28[9]|ADRL28[8]|
|||ADRL28[7]|ADRL28[6]|ADRL28[5]|ADRL28[4]|ADRL28[3]|ADRL28[2]|ADRL28[1]|ADRL28[0]|
||TSU_ADRL29|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL29[15]|ADRL29[14]|ADRL29[13]|ADRL29[12]|ADRL29[11]|ADRL29[10]|ADRL29[9]|ADRL29[8]|
|||ADRL29[7]|ADRL29[6]|ADRL29[5]|ADRL29[4]|ADRL29[3]|ADRL29[2]|ADRL29[1]|ADRL29[0]|
||TSU_ADRL30|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL30[15]|ADRL30[14]|ADRL30[13]|ADRL30[12]|ADRL30[11]|ADRL30[10]|ADRL30[9]|ADRL30[8]|
|||ADRL30[7]|ADRL30[6]|ADRL30[5]|ADRL30[4]|ADRL30[3]|ADRL30[2]|ADRL30[1]|ADRL30[0]|
||TSU_ADRL31|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ADRL31[15]|ADRL31[14]|ADRL31[13]|ADRL31[12]|ADRL31[11]|ADRL31[10]|ADRL31[9]|ADRL31[8]|
|||ADRL31[7]|ADRL31[6]|ADRL31[5]|ADRL31[4]|ADRL31[3]|ADRL31[2]|ADRL31[1]|ADRL31[0]|
||TXNLCR0|NTC0[31]|NTC0[30]|NTC0[29]|NTC0[28]|NTC0[27]|NTC0[26]|NTC0[25]|NTC0[24]|
|||NTC0[23]|NTC0[22]|NTC0[21]|NTC0[20]|NTC0[19]|NTC0[18]|NTC0[17]|NTC0[16]|
|||NTC0[15]|NTC0[14]|NTC0[13]|NTC0[12]|NTC0[11]|NTC0[10]|NTC0[9]|NTC0[8]|
|||NTC0[7]|NTC0[6]|NTC0[5]|NTC0[4]|NTC0[3]|NTC0[2]|NTC0[1]|NTC0[0]|
||TXALCR0|TC0[31]|TC0[30]|TC0[29]|TC0[28]|TC0[27]|TC0[26]|TC0[25]|TC0[24]|
|||TC0[23]|TC0[22]|TC0[21]|TC0[20]|TC0[19]|TC0[18]|TC0[17]|TC0[16]|
|||TC0[15]|TC0[14]|TC0[13]|TC0[12]|TC0[11]|TC0[10]|TC0[9]|TC0[8]|
|||TC0[7]|TC0[6]|TC0[5]|TC0[4]|TC0[3]|TC0[2]|TC0[1]|TC0[0]|
||RXNLCR0|NRC0[31]|NRC0[30]|NRC0[29]|NRC0[28]|NRC0[27]|NRC0[26]|NRC0[25]|NRC0[24]|
|||NRC0[23]|NRC0[22]|NRC0[21]|NRC0[20]|NRC0[19]|NRC0[18]|NRC0[17]|NRC0[16]|
|||NRC0[15]|NRC0[14]|NRC0[13]|NRC0[12]|NRC0[11]|NRC0[10]|NRC0[9]|NRC0[8]|
|||NRC0[7]|NRC0[6]|NRC0[5]|NRC0[4]|NRC0[3]|NRC0[2]|NRC0[1]|NRC0[0]|
||RXALCR0|RC0[31]|RC0[30]|RC0[29]|RC0[28]|RC0[27]|RC0[26]|RC0[25]|RC0[24]|
|||RC0[23]|RC0[22]|RC0[21]|RC0[20]|RC0[19]|RC0[18]|RC0[17]|RC0[16]|
|||RC0[15]|RC0[14]|RC0[13]|RC0[12]|RC0[11]|RC0[10]|RC0[9]|RC0[8]|
|||RC0[7]|RC0[6]|RC0[5]|RC0[4]|RC0[3]|RC0[2]|RC0[1]|RC0[0]|
||EDSR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|ENT|ENR|
||EDMR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|DE|DL[1]|DL[0]|-|-|SWRT|SWRR|
||EDTRR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|TR[1]|TR[0]|
||EDRRR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|RR|
||EESR0|TWB[1]|TWB[0]|TC[1]|TUC|ROC|TABT|RABT|RFCOF|
|||-|ECI|TC[0]|TDE|TFUF|FR|RDE|RFOF|
|||-|-|-|-|-|-|-|-|
|||RMAF|-|-|RRF|RTLF|RTSF|PRE|CERF|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ethernet<br>controller|EESIPR0|TWB1IP|TWB0IP|TC1IP|TUCIP|ROCIP|TABTIP|RABTIP|RFCOFIP|
|||-|ECIIP|TC0IP|TDEIP|TFUFIP|FRIP|RDEIP|RFOFIP|
|||-|-|-|-|-|-|-|-|
|||RMAFIP|-|-|RRFIP|RTLFIP|RTSFIP|PREIP|CERFIP|
||TDLAR0|TDLA[31]|TDLA[30]|TDLA[29]|TDLA[28]|TDLA[27]|TDLA[26]|TDLA[25]|TDLA[24]|
|||TDLA[23]|TDLA[22]|TDLA[21]|TDLA[20]|TDLA[19]|TDLA[18]|TDLA[17]|TDLA[16]|
|||TDLA[15]|TDLA[14]|TDLA[13]|TDLA[12]|TDLA[11]|TDLA[10]|TDLA[9]|TDLA[8]|
|||TDLA[7]|TDLA[6]|TDLA[5]|TDLA[4]|TDLA[3]|TDLA[2]|TDLA[1]|TDLA[0]|
||TDFAR0|TDFA[31]|TDFA[30]|TDFA[29]|TDFA[28]|TDFA[27]|TDFA[26]|TDFA[25]|TDFA[24]|
|||TDFA[23]|TDFA[22]|TDFA[21]|TDFA[20]|TDFA[19]|TDFA[18]|TDFA[17]|TDFA[16]|
|||TDFA[15]|TDFA[14]|TDFA[13]|TDFA[12]|TDFA[11]|TDFA[10]|TDFA[9]|TDFA[8]|
|||TDFA[7]|TDFA[6]|TDFA[5]|TDFA[4]|TDFA[3]|TDFA[2]|TDFA[1]|TDFA[0]|
||TDFXR0|TDFX[31]|TDFX[30]|TDFX[29]|TDFX[28]|TDFX[27]|TDFX[26]|TDFX[25]|TDFX[24]|
|||TDFX[23]|TDFX[22]|TDFX[21]|TDFX[20]|TDFX[19]|TDFX[18]|TDFX[17]|TDFX[16]|
|||TDFX[15]|TDFX[14]|TDFX[13]|TDFX[12]|TDFX[11]|TDFX[10]|TDFX[9]|TDFX[8]|
|||TDFX[7]|TDFX[6]|TDFX[5]|TDFX[4]|TDFX[3]|TDFX[2]|TDFX[1]|TDFX[0]|
||TDFFR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TDLF|
||RDLAR0|RDLA[31]|RDLA[30]|RDLA[29]|RDLA[28]|RDLA[27]|RDLA[26]|RDLA[25]|RDLA[24]|
|||RDLA[23]|RDLA[22]|RDLA[21]|RDLA[20]|RDLA[19]|RDLA[18]|RDLA[17]|RDLA[16]|
|||RDLA[15]|RDLA[14]|RDLA[13]|RDLA[12]|RDLA[11]|RDLA[10]|RDLA[9]|RDLA[8]|
|||RDLA[7]|RDLA[6]|RDLA[5]|RDLA[4]|RDLA[3]|RDLA[2]|RDLA[1]|RDLA[0]|
||RDFAR0|RDFA[31]|RDFA[30]|RDFA[29]|RDFA[28]|RDFA[27]|RDFA[26]|RDFA[25]|RDFA[24]|
|||RDFA[23]|RDFA[22]|RDFA[21]|RDFA[20]|RDFA[19]|RDFA[18]|RDFA[17]|RDFA[16]|
|||RDFA[15]|RDFA[14]|RDFA[13]|RDFA[12]|RDFA[11]|RDFA[10]|RDFA[9]|RDFA[8]|
|||RDFA[7]|RDFA[6]|RDFA[5]|RDFA[4]|RDFA[3]|RDFA[2]|RDFA[1]|RDFA[0]|
||RDFXR0|RDFX[31]|RDFX[30]|RDFX[29]|RDFX[28]|RDFX[27]|RDFX[26]|RDFX[25]|RDFX[24]|
|||RDFX[23]|RDFX[22]|RDFX[21]|RDFX[20]|RDFX[19]|RDFX[18]|RDFX[17]|RDFX[16]|
|||RDFX[15]|RDFX[14]|RDFX[13]|RDFX[12]|RDFX[11]|RDFX[10]|RDFX[9]|RDFX[8]|
|||RDFX[7]|RDFX[6]|RDFX[5]|RDFX[4]|RDFX[3]|RDFX[2]|RDFX[1]|RDFX[0]|
||RDFFR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|RDLF|
||TRSCER0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|TABTCE|RABTCE|
|||-|-|-|-|-|-|-|-|
|||RMAFCE|-|-|RRFCE|RTLFCE|RTSFCE|PRECE|CERFCE|
||RMFCR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||MFC[15]|MFC[14]|MFC[13]|MFC[12]|MFC[11]|MFC[10]|MFC[9]|MFC[8]|
|||MFC[7]|MFC[6]|MFC[5]|MFC[4]|MFC[3]|MFC[2]|MFC[1]|MFC[0]|
||TFTR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|TFT[10]|TFT[9]|TFT[8]|
|||TFT[7]|TFT[6]|TFT[5]|TFT[4]|TFT[3]|TFT[2]|TFT[1]|TFT[0]|
||FDR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|TFD[2]|TFD[1]|TFD[0]|
|||-|-|-|RFD[4]|RFD[3]|RFD[2]|RFD[1]|RFD[0]|
||RMCR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|RNC|
||RPADIR0|-|-|-|-|-|-|-|-|
|||-|-|-|PADS[4]|PADS[3]|PADS[2]|PADS[1]|PADS[0]|
|||PADR[15]|PADR[14]|PADR[13]|PADR[12]|PADR[11]|PADR[10]|PADR[9]|PADR[8]|
|||PADR[7]|PADR[6]|PADR[5]|PADR[4]|PADR[3]|PADR[2]|PADR[1]|PADR[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ethernet<br>controller|FCFTR0|-|-|-|-|-|-|-|-|
|||-|-|-|RFF[4]|RFF[3]|RFF[2]|RFF[1]|RFF[0]|
|||-|-|-|-|-|-|-|-|
|||RFD[7]|RFD[6]|RFD[5]|RFD[4]|RFD[3]|RFD[2]|RFD[1]|RFD[0]|
||CSMR|CSEBL|CSMD|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|SB[5]|SB[4]|SB[3]|SB[2]|SB[1]|SB[0]|
||CSSBM|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|SBM[5]|SBM[4]|SBM[3]|SBM[2]|SBM[1]|SBM[0]|
||CSSMR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CS[15]|CS[14]|CS[13]|CS[12]|CS[11]|CS[10]|CS[9]|CS[8]|
|||CS[7]|CS[6]|CS[5]|CS[4]|CS[3]|CS[2]|CS[1]|CS[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|A/D converter|ADDRA|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADDRB|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADDRC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADDRD|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADDRE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADDRF|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADDRG|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADDRH|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPHA|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPLA|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPHB|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPLB|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPHC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPLC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPHD|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPLD|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPHE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPLE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPHF|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPLF|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPHG|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPLG|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPHH|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCMPLH|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADCSR|ADF|ADIE|ADST|TRGS[3]|TRGS[2]|TRGS[1]|TRGS[0]|CKS[2]|
|||CKS[1]|CKS[0]|MDS[2]|MDS[1]|MDS[0]|CH[2]|CH[1]|CH[0]|
||ADCMPER|HLMENH|HLMENG|HLMENF|HLMENE|HLMEND|HLMENC|HLMENB|HLMENA|
|||LLMENH|LLMENG|LLMENF|LLMENE|LLMEND|LLMENC|LLMENB|LLMENA|
||ADCMPSR|HOVRH|HOVRG|HOVRF|HOVRE|HOVRD|HOVRC|HOVRB|HOVRA|
|||LUDRH|LUDRG|LUDRF|LUDRE|LUDRD|LUDRC|LUDRB|LUDRA|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|SYSCFG0_0|-|-|-|-|-|SCKE|-|-|
|||HSE|DCFM|DRPD|DPRPU|-|UCKSEL|UPLLE|USBE|
||BUSWAIT_0|-|-|-|-|-|-|-|-|
|||-|-|BWAIT[5]|BWAIT[4]|BWAIT[3]|BWAIT[2]|BWAIT[1]|BWAIT[0]|
||SYSSTS0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|LNST[1]|LNST[0]|
||DVSTCTR0_0|-|-|-|-|-|-|-|WKUP|
|||RWUPE|USBRST|RESUME|UACT|-|RHST[2]|RHST[1]|RHST[0]|
||TESTMODE_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|UTST[3]|UTST[2]|UTST[1]|UTST[0]|
||D0FBCFG_0|-|-|DFACC[1]|DFACC[0]|-|-|-|-|
|||-|-|-|TENDE|-|-|-|-|
||D1FBCFG_0|-|-|DFACC[1]|DFACC[0]|-|-|-|-|
|||-|-|-|TENDE|-|-|-|-|
||CFIFO_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFO_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFO_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||CFIFOSEL_0|RCNT|REW|-|-|MBW[1]|MBW[0]|-|BIGEND|
|||-|-|ISEL|-|CURPIPE[3]|CURPIPE[2]|CURPIPE[1]|CURPIPE[0]|
||CFIFOCTR_0|BVAL|BCLR|FRDY|-|DTLN[11]|DTLN[10]|DTLN[9]|DTLN[8]|
|||DTLN[7]|DTLN[6]|DTLN[5]|DTLN[4]|DTLN[3]|DTLN[2]|DTLN[1]|DTLN[0]|
||D0FIFOSEL_0|RCNT|REW|DCLRM|DREQE|MBW[1]|MBW[0]|-|BIGEND|
|||-|-|-|-|CURPIPE[3]|CURPIPE[2]|CURPIPE[1]|CURPIPE[0]|
||D0FIFOCTR_0|BVAL|BCLR|FRDY|-|DTLN[11]|DTLN[10]|DTLN[9]|DTLN[8]|
|||DTLN[7]|DTLN[6]|DTLN[5]|DTLN[4]|DTLN[3]|DTLN[2]|DTLN[1]|DTLN[0]|
||D1FIFOSEL_0|RCNT|REW|DCLRM|DREQE|MBW[1]|MBW[0]|-|BIGEND|
|||-|-|-|-|CURPIPE[3]|CURPIPE[2]|CURPIPE[1]|CURPIPE[0]|
||D1FIFOCTR_0|BVAL|BCLR|FRDY|-|DTLN[11]|DTLN[10]|DTLN[9]|DTLN[8]|
|||DTLN[7]|DTLN[6]|DTLN[5]|DTLN[4]|DTLN[3]|DTLN[2]|DTLN[1]|DTLN[0]|
||INTENB0_0|VBSE|RSME|SOFE|DVSE|CTRE|BEMPE|NRDYE|BRDYE|
|||-|-|-|-|-|-|-|-|
||INTENB1_0|-|BCHGE|-|DTCHE|ATTCHE|-|-|-|
|||-|EOFERRE|SIGNE|SACKE|-|-|-|-|
||BRDYENB_0|PIPEBRDYE[15]|PIPEBRDYE[14]|PIPEBRDYE[13]|PIPEBRDYE[12]|PIPEBRDYE[11]|PIPEBRDYE[10]|PIPEBRDYE[9]|PIPEBRDYE[8]|
|||PIPEBRDYE[7]|PIPEBRDYE[6]|PIPEBRDYE[5]|PIPEBRDYE[4]|PIPEBRDYE[3]|PIPEBRDYE[2]|PIPEBRDYE[1]|PIPEBRDYE[0]|
||NRDYENB_0|PIPENRDYE[15]|PIPENRDYE[14]|PIPENRDYE[13]|PIPENRDYE[12]|PIPENRDYE[11]|PIPENRDYE[10]|PIPENRDYE[9]|PIPENRDYE[8]|
|||PIPENRDYE[7]|PIPENRDYE[6]|PIPENRDYE[5]|PIPENRDYE[4]|PIPENRDYE[3]|PIPENRDYE[2]|PIPENRDYE[1]|PIPENRDYE[0]|
||BEMPENB_0|PIPEBEMPE[15]|PIPEBEMPE[14]|PIPEBEMPE[13]|PIPEBEMPE[12]|PIPEBEMPE[11]|PIPEBEMPE[10]|PIPEBEMPE[9]|PIPEBEMPE[8]|
|||PIPEBEMPE[7]|PIPEBEMPE[6]|PIPEBEMPE[5]|PIPEBEMPE[4]|PIPEBEMPE[3]|PIPEBEMPE[2]|PIPEBEMPE[1]|PIPEBEMPE[0]|
||SOFCFG_0|-|-|-|-|-|-|-|TRNENSEL|
|||-|BRDYM|-|-|-|-|-|-|
||INTSTS0_0|VBINT|RESM|SOFR|DVST|CTRT|BEMP|NRDY|BRDY|
|||VBSTS|DVSQ[2]|DVSQ[1]|DVSQ[0]|VALID|CTSQ[2]|CTSQ[1]|CTSQ[0]|
||INTSTS1_0|-|BCHG|-|DTCH|ATTCH|-|-|-|
|||-|EOFERR|SIGN|SACK|-|-|-|-|
||BRDYSTS_0|PIPEBRDY[15]|PIPEBRDY[14]|PIPEBRDY[13]|PIPEBRDY[12]|PIPEBRDY[11]|PIPEBRDY[10]|PIPEBRDY[9]|PIPEBRDY[8]|
|||PIPEBRDY[7]|PIPEBRDY[6]|PIPEBRDY[5]|PIPEBRDY[4]|PIPEBRDY[3]|PIPEBRDY[2]|PIPEBRDY[1]|PIPEBRDY[0]|
||NRDYSTS_0|PIPENRDY[15]|PIPENRDY[14]|PIPENRDY[13]|PIPENRDY[12]|PIPENRDY[11]|PIPENRDY[10]|PIPENRDY[9]|PIPENRDY[8]|
|||PIPENRDY[7]|PIPENRDY[6]|PIPENRDY[5]|PIPENRDY[4]|PIPENRDY[3]|PIPENRDY[2]|PIPENRDY[1]|PIPENRDY[0]|
||BEMPSTS_0|PIPEBEMP[15]|PIPEBEMP[14]|PIPEBEMP[13]|PIPEBEMP[12]|PIPEBEMP[11]|PIPEBEMP[10]|PIPEBEMP[9]|PIPEBEMP[8]|
|||PIPEBEMP[7]|PIPEBEMP[6]|PIPEBEMP[5]|PIPEBEMP[4]|PIPEBEMP[3]|PIPEBEMP[2]|PIPEBEMP[1]|PIPEBEMP[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|FRMNUM_0|OVRN|CRCE|-|-|-|FRNM[10]|FRNM[9]|FRNM[8]|
|||FRNM[7]|FRNM[6]|FRNM[5]|FRNM[4]|FRNM[3]|FRNM[2]|FRNM[1]|FRNM[0]|
||UFRMNUM_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|UFRNM[2]|UFRNM[1]|UFRNM[0]|
||USBADDR_0|-|-|-|-|-|-|-|-|
|||-|USBADDR[6]|USBADDR[5]|USBADDR[4]|USBADDR[3]|USBADDR[2]|USBADDR[1]|USBADDR[0]|
||USBREQ_0|bRequest[7]|bRequest[6]|bRequest[5]|bRequest[4]|bRequest[3]|bRequest[2]|bRequest[1]|bRequest[0]|
|||bmRequestType[7]|bmRequestType[6]|bmRequestType[5]|bmRequestType[4]|bmRequestType[3]|bmRequestType[2]|bmRequestType[1]|bmRequestType[0]|
||USBVAL_0|wValue[15]|wValue[14]|wValue[13]|wValue[12]|wValue[11]|wValue[10]|wValue[9]|wValue[8]|
|||wValue[7]|wValue[6]|wValue[5]|wValue[4]|wValue[3]|wValue[2]|wValue[1]|wValue[0]|
||USBINDX_0|wIndex[15]|wIndex[14]|wIndex[13]|wIndex[12]|wIndex[11]|wIndex[10]|wIndex[9]|wIndex[8]|
|||wIndex[7]|wIndex[6]|wIndex[5]|wIndex[4]|wIndex[3]|wIndex[2]|wIndex[1]|wIndex[0]|
||USBLENG_0|wLength[15]|wLength[14]|wLength[13]|wLength[12]|wLength[11]|wLength[10]|wLength[9]|wLength[8]|
|||wLength[7]|wLength[6]|wLength[5]|wLength[4]|wLength[3]|wLength[2]|wLength[1]|wLength[0]|
||DCPCFG_0|-|-|-|-|-|-|-|CNTMD|
|||SHTNAK|-|-|DIR|-|-|-|-|
||DCPMAXP_0|DEVSEL[3]|DEVSEL[2]|DEVSEL[1]|DEVSEL[0]|-|-|-|-|
|||-|MXPS[6]|MXPS[5]|MXPS[4]|MXPS[3]|MXPS[2]|MXPS[1]|MXPS[0]|
||DCPCTR_0|BSTS|SUREQ|CSCLR|CSSTS|SUREQCLR|-|-|SQCLR|
|||SQSET|SQMON|PBUSY|PINGE|-|CCPL|PID[1]|PID[0]|
||PIPESEL_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|PIPESEL[3]|PIPESEL[2]|PIPESEL[1]|PIPESEL[0]|
||PIPECFG_0|TYPE[1]|TYPE[0]|-|-|-|BFRE|DBLB|CNTMD|
|||SHTNAK|-|-|DIR|EPNUM[3]|EPNUM[2]|EPNUM[1]|EPNUM[0]|
||PIPEBUF_0|-|BUFSIZE[4]|BUFSIZE[3]|BUFSIZE[2]|BUFSIZE[1]|BUFSIZE[0]|-|-|
|||BUFNMB[7]|BUFNMB[6]|BUFNMB[5]|BUFNMB[4]|BUFNMB[3]|BUFNMB[2]|BUFNMB[1]|BUFNMB[0]|
||PIPEMAXP_0|DEVSEL[3]|DEVSEL[2]|DEVSEL[1]|DEVSEL[0]|-|MXPS[10]|MXPS[9]|MXPS[8]|
|||MXPS[7]|MXPS[6]|MXPS[5]|MXPS[4]|MXPS[3]|MXPS[2]|MXPS[1]|MXPS[0]|
||PIPEPERI_0|-|-|-|IFIS|-|-|-|-|
|||-|-|-|-|-|IITV[2]|IITV[1]|IITV[0]|
||PIPE1CTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE2CTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE3CTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE4CTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE5CTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE6CTR_0|BSTS|-|CSCLR|CSSTS|-|-|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE7CTR_0|BSTS|-|CSCLR|CSSTS|-|-|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE8CTR_0|BSTS|-|CSCLR|CSSTS|-|-|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE9CTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEACTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEBCTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPECCTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEDCTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEECTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEFCTR_0|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|PIPE1TRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE1TRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE2TRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE2TRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE3TRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE3TRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE4TRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE4TRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE5TRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE5TRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEBTRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEBTRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPECTRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPECTRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEDTRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEDTRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEETRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEETRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEFTRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEFTRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE9TRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE9TRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEATRE_0|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEATRN_0|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||DEVADD0_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD1_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD2_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD3_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD4_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD5_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|DEVADD6_0|-|HPPHUB[3]|HPPHUB[2]|HPPHUB[1]|HPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|-|-|-|
||DEVADD7_0|-|HPPHUB[3]|HPPHUB[2]|HPPHUB[1]|HPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD8_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD9_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADDA_0|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||SUSPMODE_0|-|SUSPM|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||D0FIFOB0_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB1_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB2_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB3_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB4_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB5_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB6_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB7_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB0_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB1_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB2_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB3_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|D1FIFOB4_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB5_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB6_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB7_0|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||SYSCFG0_1|-|-|-|-|-|SCKE|-|-|
|||HSE|DCFM|DRPD|DPRPU|-|-|-|USBE|
||BUSWAIT_1|-|-|-|-|-|-|-|-|
|||-|-|BWAIT[5]|BWAIT[4]|BWAIT[3]|BWAIT[2]|BWAIT[1]|BWAIT[0]|
||SYSSTS0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|LNST[1]|LNST[0]|
||DVSTCTR0_1|-|-|-|-|-|-|-|WKUP|
|||RWUPE|USBRST|RESUME|UACT|-|RHST[2]|RHST[1]|RHST[0]|
||TESTMODE_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|UTST[3]|UTST[2]|UTST[1]|UTST[0]|
||D0FBCFG_1|-|-|DFACC[1]|DFACC[0]|-|-|-|-|
|||-|-|-|TENDE|-|-|-|-|
||D1FBCFG_1|-|-|DFACC[1]|DFACC[0]|-|-|-|-|
|||-|-|-|TENDE|-|-|-|-|
||CFIFO_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFO_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFO_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||CFIFOSEL_1|RCNT|REW|-|-|MBW[1]|MBW[0]|-|BIGEND|
|||-|-|ISEL|-|CURPIPE[3]|CURPIPE[2]|CURPIPE[1]|CURPIPE[0]|
||CFIFOCTR_1|BVAL|BCLR|FRDY|-|DTLN[11]|DTLN[10]|DTLN[9]|DTLN[8]|
|||DTLN[7]|DTLN[6]|DTLN[5]|DTLN[4]|DTLN[3]|DTLN[2]|DTLN[1]|DTLN[0]|
||D0FIFOSEL_1|RCNT|REW|DCLRM|DREQE|MBW[1]|MBW[0]|-|BIGEND|
|||-|-|-|-|CURPIPE[3]|CURPIPE[2]|CURPIPE[1]|CURPIPE[0]|
||D0FIFOCTR_1|BVAL|BCLR|FRDY|-|DTLN[11]|DTLN[10]|DTLN[9]|DTLN[8]|
|||DTLN[7]|DTLN[6]|DTLN[5]|DTLN[4]|DTLN[3]|DTLN[2]|DTLN[1]|DTLN[0]|
||D1FIFOSEL_1|RCNT|REW|DCLRM|DREQE|MBW[1]|MBW[0]|-|BIGEND|
|||-|-|-|-|CURPIPE[3]|CURPIPE[2]|CURPIPE[1]|CURPIPE[0]|
||D1FIFOCTR_1|BVAL|BCLR|FRDY|-|DTLN[11]|DTLN[10]|DTLN[9]|DTLN[8]|
|||DTLN[7]|DTLN[6]|DTLN[5]|DTLN[4]|DTLN[3]|DTLN[2]|DTLN[1]|DTLN[0]|
||INTENB0_1|VBSE|RSME|SOFE|DVSE|CTRE|BEMPE|NRDYE|BRDYE|
|||-|-|-|-|-|-|-|-|
||INTENB1_1|-|BCHGE|-|DTCHE|ATTCHE|-|-|-|
|||-|EOFERRE|SIGNE|SACKE|-|-|-|-|
||BRDYENB_1|PIPEBRDYE[15]|PIPEBRDYE[14]|PIPEBRDYE[13]|PIPEBRDYE[12]|PIPEBRDYE[11]|PIPEBRDYE[10]|PIPEBRDYE[9]|PIPEBRDYE[8]|
|||PIPEBRDYE[7]|PIPEBRDYE[6]|PIPEBRDYE[5]|PIPEBRDYE[4]|PIPEBRDYE[3]|PIPEBRDYE[2]|PIPEBRDYE[1]|PIPEBRDYE[0]|

**Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|NRDYENB_1|PIPENRDYE[15]|PIPENRDYE[14]|PIPENRDYE[13]|PIPENRDYE[12]|PIPENRDYE[11]|PIPENRDYE[10]|PIPENRDYE[9]|PIPENRDYE[8]|
|||PIPENRDYE[7]|PIPENRDYE[6]|PIPENRDYE[5]|PIPENRDYE[4]|PIPENRDYE[3]|PIPENRDYE[2]|PIPENRDYE[1]|PIPENRDYE[0]|
||BEMPENB_1|PIPEBEMPE[15]|PIPEBEMPE[14]|PIPEBEMPE[13]|PIPEBEMPE[12]|PIPEBEMPE[11]|PIPEBEMPE[10]|PIPEBEMPE[9]|PIPEBEMPE[8]|
|||PIPEBEMPE[7]|PIPEBEMPE[6]|PIPEBEMPE[5]|PIPEBEMPE[4]|PIPEBEMPE[3]|PIPEBEMPE[2]|PIPEBEMPE[1]|PIPEBEMPE[0]|
||SOFCFG_1|-|-|-|-|-|-|-|TRNENSEL|
|||-|BRDYM|-|-|-|-|-|-|
||INTSTS0_1|VBINT|RESM|SOFR|DVST|CTRT|BEMP|NRDY|BRDY|
|||VBSTS|DVSQ[2]|DVSQ[1]|DVSQ[0]|VALID|CTSQ[2]|CTSQ[1]|CTSQ[0]|
||INTSTS1_1|-|BCHG|-|DTCH|ATTCH|-|-|-|
|||-|EOFERR|SIGN|SACK|-|-|-|-|
||BRDYSTS_1|PIPEBRDY[15]|PIPEBRDY[14]|PIPEBRDY[13]|PIPEBRDY[12]|PIPEBRDY[11]|PIPEBRDY[10]|PIPEBRDY[9]|PIPEBRDY[8]|
|||PIPEBRDY[7]|PIPEBRDY[6]|PIPEBRDY[5]|PIPEBRDY[4]|PIPEBRDY[3]|PIPEBRDY[2]|PIPEBRDY[1]|PIPEBRDY[0]|
||NRDYSTS_1|PIPENRDY[15]|PIPENRDY[14]|PIPENRDY[13]|PIPENRDY[12]|PIPENRDY[11]|PIPENRDY[10]|PIPENRDY[9]|PIPENRDY[8]|
|||PIPENRDY[7]|PIPENRDY[6]|PIPENRDY[5]|PIPENRDY[4]|PIPENRDY[3]|PIPENRDY[2]|PIPENRDY[1]|PIPENRDY[0]|
||BEMPSTS_1|PIPEBEMP[15]|PIPEBEMP[14]|PIPEBEMP[13]|PIPEBEMP[12]|PIPEBEMP[11]|PIPEBEMP[10]|PIPEBEMP[9]|PIPEBEMP[8]|
|||PIPEBEMP[7]|PIPEBEMP[6]|PIPEBEMP[5]|PIPEBEMP[4]|PIPEBEMP[3]|PIPEBEMP[2]|PIPEBEMP[1]|PIPEBEMP[0]|
||FRMNUM_1|OVRN|CRCE|-|-|-|FRNM[10]|FRNM[9]|FRNM[8]|
|||FRNM[7]|FRNM[6]|FRNM[5]|FRNM[4]|FRNM[3]|FRNM[2]|FRNM[1]|FRNM[0]|
||UFRMNUM_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|UFRNM[2]|UFRNM[1]|UFRNM[0]|
||USBADDR_1|-|-|-|-|-|-|-|-|
|||-|USBADDR[6]|USBADDR[5]|USBADDR[4]|USBADDR[3]|USBADDR[2]|USBADDR[1]|USBADDR[0]|
||USBREQ_1|bRequest[7]|bRequest[6]|bRequest[5]|bRequest[4]|bRequest[3]|bRequest[2]|bRequest[1]|bRequest[0]|
|||bmRequestType[7]|bmRequestType[6]|bmRequestType[5]|bmRequestType[4]|bmRequestType[3]|bmRequestType[2]|bmRequestType[1]|bmRequestType[0]|
||USBVAL_1|wValue[15]|wValue[14]|wValue[13]|wValue[12]|wValue[11]|wValue[10]|wValue[9]|wValue[8]|
|||wValue[7]|wValue[6]|wValue[5]|wValue[4]|wValue[3]|wValue[2]|wValue[1]|wValue[0]|
||USBINDX_1|wIndex[15]|wIndex[14]|wIndex[13]|wIndex[12]|wIndex[11]|wIndex[10]|wIndex[9]|wIndex[8]|
|||wIndex[7]|wIndex[6]|wIndex[5]|wIndex[4]|wIndex[3]|wIndex[2]|wIndex[1]|wIndex[0]|
||USBLENG_1|wLength[15]|wLength[14]|wLength[13]|wLength[12]|wLength[11]|wLength[10]|wLength[9]|wLength[8]|
|||wLength[7]|wLength[6]|wLength[5]|wLength[4]|wLength[3]|wLength[2]|wLength[1]|wLength[0]|
||DCPCFG_1|-|-|-|-|-|-|-|CNTMD|
|||SHTNAK|-|-|DIR|-|-|-|-|
||DCPMAXP_1|DEVSEL[3]|DEVSEL[2]|DEVSEL[1]|DEVSEL[0]|-|-|-|-|
|||-|MXPS[6]|MXPS[5]|MXPS[4]|MXPS[3]|MXPS[2]|MXPS[1]|MXPS[0]|
||DCPCTR_1|BSTS|SUREQ|CSCLR|CSSTS|SUREQCLR|-|-|SQCLR|
|||SQSET|SQMON|PBUSY|PINGE|-|CCPL|PID[1]|PID[0]|
||PIPESEL_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|PIPESEL[3]|PIPESEL[2]|PIPESEL[1]|PIPESEL[0]|
||PIPECFG_1|TYPE[1]|TYPE[0]|-|-|-|BFRE|DBLB|CNTMD|
|||SHTNAK|-|-|DIR|EPNUM[3]|EPNUM[2]|EPNUM[1]|EPNUM[0]|
||PIPEBUF_1|-|BUFSIZE[4]|BUFSIZE[3]|BUFSIZE[2]|BUFSIZE[1]|BUFSIZE[0]|-|-|
|||BUFNMB[7]|BUFNMB[6]|BUFNMB[5]|BUFNMB[4]|BUFNMB[3]|BUFNMB[2]|BUFNMB[1]|BUFNMB[0]|
||PIPEMAXP_1|DEVSEL[3]|DEVSEL[2]|DEVSEL[1]|DEVSEL[0]|-|MXPS[10]|MXPS[9]|MXPS[8]|
|||MXPS[7]|MXPS[6]|MXPS[5]|MXPS[4]|MXPS[3]|MXPS[2]|MXPS[1]|MXPS[0]|
||PIPEPERI_1|-|-|-|IFIS|-|-|-|-|
|||-|-|-|-|-|IITV[2]|IITV[1]|IITV[0]|
||PIPE1CTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE2CTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE3CTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE4CTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE5CTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE6CTR_1|BSTS|-|CSCLR|CSSTS|-|-|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE7CTR_1|BSTS|-|CSCLR|CSSTS|-|-|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|

**Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|PIPE8CTR_1|BSTS|-|CSCLR|CSSTS|-|-|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE9CTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEACTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEBCTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPECCTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEDCTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEECTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPEFCTR_1|BSTS|INBUFM|CSCLR|CSSTS|-|ATREPM|ACLRM|SQCLR|
|||SQSET|SQMON|PBUSY|-|-|-|PID[1]|PID[0]|
||PIPE1TRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE1TRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE2TRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE2TRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE3TRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE3TRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE4TRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE4TRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE5TRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE5TRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEBTRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEBTRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPECTRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPECTRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEDTRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEDTRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEETRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEETRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPEFTRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEFTRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||PIPE9TRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPE9TRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|PIPEATRE_1|-|-|-|-|-|-|TRENB|TRCLR|
|||-|-|-|-|-|-|-|-|
||PIPEATRN_1|TRNCNT[15]|TRNCNT[14]|TRNCNT[13]|TRNCNT[12]|TRNCNT[11]|TRNCNT[10]|TRNCNT[9]|TRNCNT[8]|
|||TRNCNT[7]|TRNCNT[6]|TRNCNT[5]|TRNCNT[4]|TRNCNT[3]|TRNCNT[2]|TRNCNT[1]|TRNCNT[0]|
||DEVADD0_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD1_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD2_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD3_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD4_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD5_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD6_1|-|HPPHUB[3]|HPPHUB[2]|HPPHUB[1]|HPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|-|-|-|
||DEVADD7_1|-|HPPHUB[3]|HPPHUB[2]|HPPHUB[1]|HPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD8_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADD9_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||DEVADDA_1|-|UPPHUB[3]|UPPHUB[2]|UPPHUB[1]|UPPHUB[0]|HUBPORT[2]|HUBPORT[1]|HUBPORT[0]|
|||USBSPD[1]|USBSPD[0]|-|-|-|-|-|-|
||SUSPMODE_1|-|SUSPM|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||D0FIFOB0_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB1_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB2_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB3_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB4_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB5_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB6_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D0FIFOB7_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|USB2.0 host/<br>function module|D1FIFOB0_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB1_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB2_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB3_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB4_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB5_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB6_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
||D1FIFOB7_1|FIFOPORT[31]|FIFOPORT[30]|FIFOPORT[29]|FIFOPORT[28]|FIFOPORT[27]|FIFOPORT[26]|FIFOPORT[25]|FIFOPORT[24]|
|||FIFOPORT[23]|FIFOPORT[22]|FIFOPORT[21]|FIFOPORT[20]|FIFOPORT[19]|FIFOPORT[18]|FIFOPORT[17]|FIFOPORT[16]|
|||FIFOPORT[15]|FIFOPORT[14]|FIFOPORT[13]|FIFOPORT[12]|FIFOPORT[11]|FIFOPORT[10]|FIFOPORT[9]|FIFOPORT[8]|
|||FIFOPORT[7]|FIFOPORT[6]|FIFOPORT[5]|FIFOPORT[4]|FIFOPORT[3]|FIFOPORT[2]|FIFOPORT[1]|FIFOPORT[0]|
|Video display<br>controller 5|INP_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|INP_EXT_UPDATE|-|-|-|INP_IMG_UPDATE|
||INP_SEL_CNT|-|-|-|-|-|-|-|-|
|||-|-|-|INP_SEL|-|-|-|-|
|||-|INP_FORMAT[2]|INP_FORMAT[1]|INP_FORMAT[0]|-|-|-|INP_PXD_EDGE|
|||-|-|-|INP_VS_EDGE|-|-|-|INP_HS_EDGE|
||INP_EXT_SYNC_<br>CNT|-|-|-|INP_ENDIAN_<br>ON|-|-|-|INP_SWAP_ON|
|||-|-|-|INP_VS_INV|-|-|-|INP_HS_INV|
|||-|-|-|-|-|-|-|INP_H_EDGE_<br>SEL|
|||-|-|-|INP_F525_625|-|-|INP_H_POS[1]|INP_H_POS[0]|
||INP_VSYNC_PH_<br>ADJ|-|-|-|-|-|-|INP_FH50[9]|INP_FH50[8]|
|||INP_FH50[7]|INP_FH50[6]|INP_FH50[5]|INP_FH50[4]|INP_FH50[3]|INP_FH50[2]|INP_FH50[1]|INP_FH50[0]|
|||-|-|-|-|-|-|INP_FH25[9]|INP_FH25[8]|
|||INP_FH25[7]|INP_FH25[6]|INP_FH25[5]|INP_FH25[4]|INP_FH25[3]|INP_FH25[2]|INP_FH25[1]|INP_FH25[0]|
||INP_DLY_ADJ|-|-|-|-|-|INP_VS_DLY_L<br>[2]|INP_VS_DLY_L<br>[1]|INP_VS_DLY_L<br>[0]|
|||INP_FLD_DLY[7]|INP_FLD_DLY[6]|INP_FLD_DLY[5]|INP_FLD_DLY[4]|INP_FLD_DLY[3]|INP_FLD_DLY[2]|INP_FLD_DLY[1]|INP_FLD_DLY[0]|
|||INP_VS_DLY[7]|INP_VS_DLY[6]|INP_VS_DLY[5]|INP_VS_DLY[4]|INP_VS_DLY[3]|INP_VS_DLY[2]|INP_VS_DLY[1]|INP_VS_DLY[0]|
|||INP_HS_DLY[7]|INP_HS_DLY[6]|INP_HS_DLY[5]|INP_HS_DLY[4]|INP_HS_DLY[3]|INP_HS_DLY[2]|INP_HS_DLY[1]|INP_HS_DLY[0]|
||IMGCNT_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|IMGCNT_VEN|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|IMGCNT_NR_CNT0|-|-|-|-|-|-|-|-|
|||-|-|-|NR1D_MD|-|-|-|NR1D_ON|
|||-|NR1D_Y_TH[6]|NR1D_Y_TH[5]|NR1D_Y_TH[4]|NR1D_Y_TH[3]|NR1D_Y_TH[2]|NR1D_Y_TH[1]|NR1D_Y_TH[0]|
|||-|-|NR1D_Y_TAP[1]|NR1D_Y_TAP[0]|-|-|NR1D_Y_GAIN[1]|NR1D_Y_GAIN[0]|
||IMGCNT_NR_CNT1|-|NR1D_CB_TH[6]|NR1D_CB_TH[5]|NR1D_CB_TH[4]|NR1D_CB_TH[3]|NR1D_CB_TH[2]|NR1D_CB_TH[1]|NR1D_CB_TH[0]|
|||-|-|NR1D_CB_TAP[1]|NR1D_CB_TAP[0]|-|-|NR1D_CB_GAIN<br>[1]|NR1D_CB_GAIN<br>[0]|
|||-|NR1D_CR_TH[6]|NR1D_CR_TH[5]|NR1D_CR_TH[4]|NR1D_CR_TH[3]|NR1D_CR_TH[2]|NR1D_CR_TH[1]|NR1D_CR_TH[0]|
|||-|-|NR1D_CR_TAP[1]|NR1D_CR_TAP[0]|-|-|NR1D_CR_GAIN<br>[1]|NR1D_CR_GAIN<br>[0]|
||IMGCNT_MTX_<br>MODE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|IMGCNT_MTX_<br>MD[1]|IMGCNT_MTX_<br>MD[0]|
||IMGCNT_MTX_YG_<br>ADJ0|-|-|-|-|-|-|-|-|
|||IMGCNT_MTX_<br>YG[7]|IMGCNT_MTX_<br>YG[6]|IMGCNT_MTX_<br>YG[5]|IMGCNT_MTX_<br>YG[4]|IMGCNT_MTX_<br>YG[3]|IMGCNT_MTX_<br>YG[2]|IMGCNT_MTX_<br>YG[1]|IMGCNT_MTX_<br>YG[0]|
|||-|-|-|-|-|IMGCNT_MTX_<br>GG[10]|IMGCNT_MTX_<br>GG[9]|IMGCNT_MTX_<br>GG[8]|
|||IMGCNT_MTX_<br>GG[7]|IMGCNT_MTX_<br>GG[6]|IMGCNT_MTX_<br>GG[5]|IMGCNT_MTX_<br>GG[4]|IMGCNT_MTX_<br>GG[3]|IMGCNT_MTX_<br>GG[2]|IMGCNT_MTX_<br>GG[1]|IMGCNT_MTX_<br>GG[0]|
||IMGCNT_MTX_YG_<br>ADJ1|-|-|-|-|-|IMGCNT_MTX_<br>GB[10]|IMGCNT_MTX_<br>GB[9]|IMGCNT_MTX_<br>GB[8]|
|||IMGCNT_MTX_<br>GB[7]|IMGCNT_MTX_<br>GB[6]|IMGCNT_MTX_<br>GB[5]|IMGCNT_MTX_<br>GB[4]|IMGCNT_MTX_<br>GB[3]|IMGCNT_MTX_<br>GB[2]|IMGCNT_MTX_<br>GB[1]|IMGCNT_MTX_<br>GB[0]|
|||-|-|-|-|-|IMGCNT_MTX_<br>GR[10]|IMGCNT_MTX_<br>GR[9]|IMGCNT_MTX_<br>GR[8]|
|||IMGCNT_MTX_<br>GR[7]|IMGCNT_MTX_<br>GR[6]|IMGCNT_MTX_<br>GR[5]|IMGCNT_MTX_<br>GR[4]|IMGCNT_MTX_<br>GR[3]|IMGCNT_MTX_<br>GR[2]|IMGCNT_MTX_<br>GR[1]|IMGCNT_MTX_<br>GR[0]|
||IMGCNT_MTX_<br>CBB_ADJ0|-|-|-|-|-|-|-|-|
|||IMGCNT_MTX_<br>B[7]|IMGCNT_MTX_<br>B[6]|IMGCNT_MTX_<br>B[5]|IMGCNT_MTX_<br>B[4]|IMGCNT_MTX_<br>B[3]|IMGCNT_MTX_<br>B[2]|IMGCNT_MTX_<br>B[1]|IMGCNT_MTX_<br>B[0]|
|||-|-|-|-|-|IMGCNT_MTX_<br>BG[10]|IMGCNT_MTX_<br>BG[9]|IMGCNT_MTX_<br>BG[8]|
|||IMGCNT_MTX_<br>BG[7]|IMGCNT_MTX_<br>BG[6]|IMGCNT_MTX_<br>BG[5]|IMGCNT_MTX_<br>BG[4]|IMGCNT_MTX_<br>BG[3]|IMGCNT_MTX_<br>BG[2]|IMGCNT_MTX_<br>BG[1]|IMGCNT_MTX_<br>BG[0]|
||IMGCNT_MTX_<br>CBB_ADJ1|-|-|-|-|-|IMGCNT_MTX_<br>BB[10]|IMGCNT_MTX_<br>BB[9]|IMGCNT_MTX_<br>BB[8]|
|||IMGCNT_MTX_<br>BB[7]|IMGCNT_MTX_<br>BB[6]|IMGCNT_MTX_<br>BB[5]|IMGCNT_MTX_<br>BB[4]|IMGCNT_MTX_<br>BB[3]|IMGCNT_MTX_<br>BB[2]|IMGCNT_MTX_<br>BB[1]|IMGCNT_MTX_<br>BB[0]|
|||-|-|-|-|-|IMGCNT_MTX_<br>BR[10]|IMGCNT_MTX_<br>BR[9]|IMGCNT_MTX_<br>BR[8]|
|||IMGCNT_MTX_<br>BR[7]|IMGCNT_MTX_<br>BR[6]|IMGCNT_MTX_<br>BR[5]|IMGCNT_MTX_<br>BR[4]|IMGCNT_MTX_<br>BR[3]|IMGCNT_MTX_<br>BR[2]|IMGCNT_MTX_<br>BR[1]|IMGCNT_MTX_<br>BR[0]|
||IMGCNT_MTX_<br>CRR_ADJ0|-|-|-|-|-|-|-|-|
|||IMGCNT_MTX_<br>R[7]|IMGCNT_MTX_<br>R[6]|IMGCNT_MTX_<br>R[5]|IMGCNT_MTX_<br>R[4]|IMGCNT_MTX_<br>R[3]|IMGCNT_MTX_<br>R[2]|IMGCNT_MTX_<br>R[1]|IMGCNT_MTX_<br>R[0]|
|||-|-|-|-|-|IMGCNT_MTX_<br>RG[10]|IMGCNT_MTX_<br>RG[9]|IMGCNT_MTX_<br>RG[8]|
|||IMGCNT_MTX_<br>RG[7]|IMGCNT_MTX_<br>RG[6]|IMGCNT_MTX_<br>RG[5]|IMGCNT_MTX_<br>RG[4]|IMGCNT_MTX_<br>RG[3]|IMGCNT_MTX_<br>RG[2]|IMGCNT_MTX_<br>RG[1]|IMGCNT_MTX_<br>RG[0]|
||IMGCNT_MTX_<br>CRR_ADJ1|-|-|-|-|-|IMGCNT_MTX_<br>RB[10]|IMGCNT_MTX_<br>RB[9]|IMGCNT_MTX_<br>RB[8]|
|||IMGCNT_MTX_<br>RB[7]|IMGCNT_MTX_<br>RB[6]|IMGCNT_MTX_<br>RB[5]|IMGCNT_MTX_<br>RB[4]|IMGCNT_MTX_<br>RB[3]|IMGCNT_MTX_<br>RB[2]|IMGCNT_MTX_<br>RB[1]|IMGCNT_MTX_<br>RB[0]|
|||-|-|-|-|-|IMGCNT_MTX_<br>RR[10]|IMGCNT_MTX_<br>RR[9]|IMGCNT_MTX_<br>RR[8]|
|||IMGCNT_MTX_<br>RR[7]|IMGCNT_MTX_<br>RR[6]|IMGCNT_MTX_<br>RR[5]|IMGCNT_MTX_<br>RR[4]|IMGCNT_MTX_<br>RR[3]|IMGCNT_MTX_<br>RR[2]|IMGCNT_MTX_<br>RR[1]|IMGCNT_MTX_<br>RR[0]|
||SC0_SCL0_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|SC0_SCL0_<br>VEN_D|SC0_SCL0_<br>VEN_C|-|-|-|SC0_SCL0_<br>UPDATE|
|||-|-|-|SC0_SCL0_<br>VEN_B|-|-|-|SC0_SCL0_<br>VEN_A|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|SC0_SCL0_FRC1|SC0_RES_<br>VMASK[15]|SC0_RES_<br>VMASK[14]|SC0_RES_<br>VMASK[13]|SC0_RES_<br>VMASK[12]|SC0_RES_<br>VMASK[11]|SC0_RES_<br>VMASK[10]|SC0_RES_<br>VMASK[9]|SC0_RES_<br>VMASK[8]|
|||SC0_RES_<br>VMASK[7]|SC0_RES_<br>VMASK[6]|SC0_RES_<br>VMASK[5]|SC0_RES_<br>VMASK[4]|SC0_RES_<br>VMASK[3]|SC0_RES_<br>VMASK[2]|SC0_RES_<br>VMASK[1]|SC0_RES_<br>VMASK[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SC0_RES_<br>VMASK_ON|
||SC0_SCL0_FRC2|SC0_RES_<br>VLACK[15]|SC0_RES_<br>VLACK[14]|SC0_RES_<br>VLACK[13]|SC0_RES_<br>VLACK[12]|SC0_RES_<br>VLACK[11]|SC0_RES_<br>VLACK[10]|SC0_RES_<br>VLACK[9]|SC0_RES_<br>VLACK[8]|
|||SC0_RES_<br>VLACK[7]|SC0_RES_<br>VLACK[6]|SC0_RES_<br>VLACK[5]|SC0_RES_<br>VLACK[4]|SC0_RES_<br>VLACK[3]|SC0_RES_<br>VLACK[2]|SC0_RES_<br>VLACK[1]|SC0_RES_<br>VLACK[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SC0_RES_<br>VLACK_ON|
||SC0_SCL0_FRC3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SC0_RES_<br>VS_SEL|
||SC0_SCL0_FRC4|-|-|-|-|-|SC0_RES_FV[10]|SC0_RES_FV[9]|SC0_RES_FV[8]|
|||SC0_RES_FV[7]|SC0_RES_FV[6]|SC0_RES_FV[5]|SC0_RES_FV[4]|SC0_RES_FV[3]|SC0_RES_FV[2]|SC0_RES_FV[1]|SC0_RES_FV[0]|
|||-|-|-|-|-|SC0_RES_FH[10]|SC0_RES_FH[9]|SC0_RES_FH[8]|
|||SC0_RES_FH[7]|SC0_RES_FH[6]|SC0_RES_FH[5]|SC0_RES_FH[4]|SC0_RES_FH[3]|SC0_RES_FH[2]|SC0_RES_FH[1]|SC0_RES_FH[0]|
||SC0_SCL0_FRC5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SC0_RES_<br>FLD_DLY_SEL|
|||SC0_RES_<br>VSDLY[7]|SC0_RES_<br>VSDLY[6]|SC0_RES_<br>VSDLY[5]|SC0_RES_<br>VSDLY[4]|SC0_RES_<br>VSDLY[3]|SC0_RES_<br>VSDLY[2]|SC0_RES_<br>VSDLY[1]|SC0_RES_<br>VSDLY[0]|
||SC0_SCL0_FRC6|-|-|-|-|-|SC0_RES_F_<br>VS[10]|SC0_RES_F_<br>VS[9]|SC0_RES_F_<br>VS[8]|
|||SC0_RES_F_<br>VS[7]|SC0_RES_F_<br>VS[6]|SC0_RES_F_<br>VS[5]|SC0_RES_F_<br>VS[4]|SC0_RES_F_<br>VS[3]|SC0_RES_F_<br>VS[2]|SC0_RES_F_<br>VS[1]|SC0_RES_F_<br>VS[0]|
|||-|-|-|-|-|SC0_RES_F_<br>VW[10]|SC0_RES_F_<br>VW[9]|SC0_RES_F_<br>VW[8]|
|||SC0_RES_F_<br>VW[7]|SC0_RES_F_<br>VW[6]|SC0_RES_F_<br>VW[5]|SC0_RES_F_<br>VW[4]|SC0_RES_F_<br>VW[3]|SC0_RES_F_<br>VW[2]|SC0_RES_F_<br>VW[1]|SC0_RES_F_<br>VW[0]|
||SC0_SCL0_FRC7|-|-|-|-|-|SC0_RES_F_<br>HS[10]|SC0_RES_F_<br>HS[9]|SC0_RES_F_<br>HS[8]|
|||SC0_RES_F_<br>HS[7]|SC0_RES_F_<br>HS[6]|SC0_RES_F_<br>HS[5]|SC0_RES_F_<br>HS[4]|SC0_RES_F_<br>HS[3]|SC0_RES_F_<br>HS[2]|SC0_RES_F_<br>HS[1]|SC0_RES_F_<br>HS[0]|
|||-|-|-|-|-|SC0_RES_F_<br>HW[10]|SC0_RES_F_<br>HW[9]|SC0_RES_F_<br>HW[8]|
|||SC0_RES_F_<br>HW[7]|SC0_RES_F_<br>HW[6]|SC0_RES_F_<br>HW[5]|SC0_RES_F_<br>HW[4]|SC0_RES_F_<br>HW[3]|SC0_RES_F_<br>HW[2]|SC0_RES_F_<br>HW[1]|SC0_RES_F_<br>HW[0]|
||SC0_SCL0_FRC9|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SC0_RES_<br>QVLOCK|-|-|-|SC0_RES_<br>QVLACK|
||SC0_SCL0_MON0|-|-|-|-|-|SC0_RES_LIN_<br>STAT[10]|SC0_RES_LIN_<br>STAT[9]|SC0_RES_LIN_<br>STAT[8]|
|||SC0_RES_LIN_<br>STAT[7]|SC0_RES_LIN_<br>STAT[6]|SC0_RES_LIN_<br>STAT[5]|SC0_RES_LIN_<br>STAT[4]|SC0_RES_LIN_<br>STAT[3]|SC0_RES_LIN_<br>STAT[2]|SC0_RES_LIN_<br>STAT[1]|SC0_RES_LIN_<br>STAT[0]|
||SC0_SCL0_INT|-|-|-|-|-|SC0_RES_LINE<br>[10]|SC0_RES_LINE<br>[9]|SC0_RES_LINE<br>[8]|
|||SC0_RES_LINE[7]|SC0_RES_LINE[6]|SC0_RES_LINE[5]|SC0_RES_LINE[4]|SC0_RES_LINE[3]|SC0_RES_LINE[2]|SC0_RES_LINE[1]|SC0_RES_LINE[0]|
||SC0_SCL0_DS1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SC0_RES_DS_<br>V_ON|-|-|-|SC0_RES_DS_<br>H_ON|
||SC0_SCL0_DS2|-|-|-|-|-|SC0_RES_VS[10]|SC0_RES_VS[9]|SC0_RES_VS[8]|
|||SC0_RES_VS[7]|SC0_RES_VS[6]|SC0_RES_VS[5]|SC0_RES_VS[4]|SC0_RES_VS[3]|SC0_RES_VS[2]|SC0_RES_VS[1]|SC0_RES_VS[0]|
|||-|-|-|-|-|SC0_RES_VW[10]|SC0_RES_VW[9]|SC0_RES_VW[8]|
|||SC0_RES_VW[7]|SC0_RES_VW[6]|SC0_RES_VW[5]|SC0_RES_VW[4]|SC0_RES_VW[3]|SC0_RES_VW[2]|SC0_RES_VW[1]|SC0_RES_VW[0]|
||SC0_SCL0_DS3|-|-|-|-|-|SC0_RES_HS[10]|SC0_RES_HS[9]|SC0_RES_HS[8]|
|||SC0_RES_HS[7]|SC0_RES_HS[6]|SC0_RES_HS[5]|SC0_RES_HS[4]|SC0_RES_HS[3]|SC0_RES_HS[2]|SC0_RES_HS[1]|SC0_RES_HS[0]|
|||-|-|-|-|-|SC0_RES_HW[10]|SC0_RES_HW[9]|SC0_RES_HW[8]|
|||SC0_RES_HW[7]|SC0_RES_HW[6]|SC0_RES_HW[5]|SC0_RES_HW[4]|SC0_RES_HW[3]|SC0_RES_HW[2]|SC0_RES_HW[1]|SC0_RES_HW[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|SC0_SCL0_DS4|-|-|SC0_RES_PFIL_SEL|SC0_RES_DS_<br>H_INTERPOTYP|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SC0_RES_DS_H_<br>RATIO[15]|SC0_RES_DS_H_<br>RATIO[14]|SC0_RES_DS_H_<br>RATIO[13]|SC0_RES_DS_H_<br>RATIO[12]|SC0_RES_DS_H_<br>RATIO[11]|SC0_RES_DS_H_<br>RATIO[10]|SC0_RES_DS_H_<br>RATIO[9]|SC0_RES_DS_H_<br>RATIO[8]|
|||SC0_RES_DS_H_<br>RATIO[7]|SC0_RES_DS_H_<br>RATIO[6]|SC0_RES_DS_H_<br>RATIO[5]|SC0_RES_DS_H_<br>RATIO[4]|SC0_RES_DS_H_<br>RATIO[3]|SC0_RES_DS_H_<br>RATIO[2]|SC0_RES_DS_H_<br>RATIO[1]|SC0_RES_DS_H_<br>RATIO[0]|
||SC0_SCL0_DS5|-|-|-|SC0_RES_V_<br>INTERPOTYP|SC0_RES_TOP_<br>INIPHASE[11]|SC0_RES_TOP_<br>INIPHASE[10]|SC0_RES_TOP_<br>INIPHASE[9]|SC0_RES_TOP_<br>INIPHASE[8]|
|||SC0_RES_TOP_<br>INIPHASE[7]|SC0_RES_TOP_<br>INIPHASE[6]|SC0_RES_TOP_<br>INIPHASE[5]|SC0_RES_TOP_<br>INIPHASE[4]|SC0_RES_TOP_<br>INIPHASE[3]|SC0_RES_TOP_<br>INIPHASE[2]|SC0_RES_TOP_<br>INIPHASE[1]|SC0_RES_TOP_<br>INIPHASE[0]|
|||-|-|-|-|SC0_RES_BTM_<br>INIPHASE[11]|SC0_RES_BTM_<br>INIPHASE[10]|SC0_RES_BTM_<br>INIPHASE[9]|SC0_RES_BTM_<br>INIPHASE[8]|
|||SC0_RES_BTM_<br>INIPHASE[7]|SC0_RES_BTM_<br>INIPHASE[6]|SC0_RES_BTM_<br>INIPHASE[5]|SC0_RES_BTM_<br>INIPHASE[4]|SC0_RES_BTM_<br>INIPHASE[3]|SC0_RES_BTM_<br>INIPHASE[2]|SC0_RES_BTM_<br>INIPHASE[1]|SC0_RES_BTM_<br>INIPHASE[0]|
||SC0_SCL0_DS6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SC0_RES_V_<br>RATIO[15]|SC0_RES_V_<br>RATIO[14]|SC0_RES_V_<br>RATIO[13]|SC0_RES_V_<br>RATIO[12]|SC0_RES_V_<br>RATIO[11]|SC0_RES_V_<br>RATIO[10]|SC0_RES_V_<br>RATIO[9]|SC0_RES_V_<br>RATIO[8]|
|||SC0_RES_V_<br>RATIO[7]|SC0_RES_V_<br>RATIO[6]|SC0_RES_V_<br>RATIO[5]|SC0_RES_V_<br>RATIO[4]|SC0_RES_V_<br>RATIO[3]|SC0_RES_V_<br>RATIO[2]|SC0_RES_V_<br>RATIO[1]|SC0_RES_V_<br>RATIO[0]|
||SC0_SCL0_DS7|-|-|-|-|-|SC0_RES_OUT_VW<br>[10]|SC0_RES_OUT_VW<br>[9]|SC0_RES_OUT_VW<br>[8]|
|||SC0_RES_OUT_VW<br>[7]|SC0_RES_OUT_VW<br>[6]|SC0_RES_OUT_VW<br>[5]|SC0_RES_OUT_VW<br>[4]|SC0_RES_OUT_VW<br>[3]|SC0_RES_OUT_VW<br>[2]|SC0_RES_OUT_VW<br>[1]|SC0_RES_OUT_VW<br>[0]|
|||-|-|-|-|-|SC0_RES_OUT_HW<br>[10]|SC0_RES_OUT_HW<br>[9]|SC0_RES_OUT_HW<br>[8]|
|||SC0_RES_OUT_HW<br>[7]|SC0_RES_OUT_HW<br>[6]|SC0_RES_OUT_HW<br>[5]|SC0_RES_OUT_HW<br>[4]|SC0_RES_OUT_HW<br>[3]|SC0_RES_OUT_HW<br>[2]|SC0_RES_OUT_HW<br>[1]|SC0_RES_OUT_HW<br>[0]|
||SC0_SCL0_US1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SC0_RES_US_V_ON|-|-|-|SC0_RES_US_<br>H_ON|
||SC0_SCL0_US2|-|-|-|-|-|SC0_RES_P_<br>VS[10]|SC0_RES_P_<br>VS[9]|SC0_RES_P_<br>VS[8]|
|||SC0_RES_P_<br>VS[7]|SC0_RES_P_<br>VS[6]|SC0_RES_P_<br>VS[5]|SC0_RES_P_<br>VS[4]|SC0_RES_P_<br>VS[3]|SC0_RES_P_<br>VS[2]|SC0_RES_P_<br>VS[1]|SC0_RES_P_<br>VS[0]|
|||-|-|-|-|-|SC0_RES_P_<br>VW[10]|SC0_RES_P_<br>VW[9]|SC0_RES_P_<br>VW[8]|
|||SC0_RES_P_<br>VW[7]|SC0_RES_P_<br>VW[6]|SC0_RES_P_<br>VW[5]|SC0_RES_P_<br>VW[4]|SC0_RES_P_<br>VW[3]|SC0_RES_P_<br>VW[2]|SC0_RES_P_<br>VW[1]|SC0_RES_P_<br>VW[0]|
||SC0_SCL0_US3|-|-|-|-|-|SC0_RES_P_<br>HS[10]|SC0_RES_P_<br>HS[9]|SC0_RES_P_<br>HS[8]|
|||SC0_RES_P_<br>HS[7]|SC0_RES_P_<br>HS[6]|SC0_RES_P_<br>HS[5]|SC0_RES_P_<br>HS[4]|SC0_RES_P_<br>HS[3]|SC0_RES_P_<br>HS[2]|SC0_RES_P_<br>HS[1]|SC0_RES_P_<br>HS[0]|
|||-|-|-|-|-|SC0_RES_P_<br>HW[10]|SC0_RES_P_<br>HW[9]|SC0_RES_P_<br>HW[8]|
|||SC0_RES_P_<br>HW[7]|SC0_RES_P_<br>HW[6]|SC0_RES_P_<br>HW[5]|SC0_RES_P_<br>HW[4]|SC0_RES_P_<br>HW[3]|SC0_RES_P_<br>HW[2]|SC0_RES_P_<br>HW[1]|SC0_RES_P_<br>HW[0]|
||SC0_SCL0_US4|-|-|-|-|-|SC0_RES_IN_<br>VW[10]|SC0_RES_IN_<br>VW[9]|SC0_RES_IN_<br>VW[8]|
|||SC0_RES_IN_<br>VW[7]|SC0_RES_IN_<br>VW[6]|SC0_RES_IN_<br>VW[5]|SC0_RES_IN_<br>VW[4]|SC0_RES_IN_<br>VW[3]|SC0_RES_IN_<br>VW[2]|SC0_RES_IN_<br>VW[1]|SC0_RES_IN_<br>VW[0]|
|||-|-|-|-|-|SC0_RES_IN_<br>HW[10]|SC0_RES_IN_<br>HW[9]|SC0_RES_IN_<br>HW[8]|
|||SC0_RES_IN_<br>HW[7]|SC0_RES_IN_<br>HW[6]|SC0_RES_IN_<br>HW[5]|SC0_RES_IN_<br>HW[4]|SC0_RES_IN_<br>HW[3]|SC0_RES_IN_<br>HW[2]|SC0_RES_IN_<br>HW[1]|SC0_RES_IN_<br>HW[0]|
||SC0_SCL0_US5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SC0_RES_US_H_<br>RATIO[15]|SC0_RES_US_H_<br>RATIO[14]|SC0_RES_US_H_<br>RATIO[13]|SC0_RES_US_H_<br>RATIO[12]|SC0_RES_US_H_<br>RATIO[11]|SC0_RES_US_H_<br>RATIO[10]|SC0_RES_US_H_<br>RATIO[9]|SC0_RES_US_H_<br>RATIO[8]|
|||SC0_RES_US_H_<br>RATIO[7]|SC0_RES_US_H_<br>RATIO[6]|SC0_RES_US_H_<br>RATIO[5]|SC0_RES_US_H_<br>RATIO[4]|SC0_RES_US_H_<br>RATIO[3]|SC0_RES_US_H_<br>RATIO[2]|SC0_RES_US_H_<br>RATIO[1]|SC0_RES_US_H_<br>RATIO[0]|
||SC0_SCL0_US6|-|-|-|SC0_RES_US_H_<br>INTERPOTYP|SC0_RES_US_HT_<br>INIPHASE[11]|SC0_RES_US_HT_<br>INIPHASE[10]|SC0_RES_US_HT_<br>INIPHASE[9]|SC0_RES_US_HT_<br>INIPHASE[8]|
|||SC0_RES_US_HT_<br>INIPHASE[7]|SC0_RES_US_HT_<br>INIPHASE[6]|SC0_RES_US_HT_<br>INIPHASE[5]|SC0_RES_US_HT_<br>INIPHASE[4]|SC0_RES_US_HT_<br>INIPHASE[3]|SC0_RES_US_HT_<br>INIPHASE[2]|SC0_RES_US_HT_<br>INIPHASE[1]|SC0_RES_US_HT_<br>INIPHASE[0]|
|||-|-|-|-|SC0_RES_US_HB_INI<br>PHASE[11]|SC0_RES_US_HB_INI<br>PHASE[10]|SC0_RES_US_HB_INI<br>PHASE[9]|SC0_RES_US_HB_INI<br>PHASE[8]|
|||SC0_RES_US_HB_<br>INIPHASE[7]|SC0_RES_US_HB_<br>INIPHASE[6]|SC0_RES_US_HB_<br>INIPHASE[5]|SC0_RES_US_HB_<br>INIPHASE[4]|SC0_RES_US_HB_<br>INIPHASE[3]|SC0_RES_US_HB_<br>INIPHASE[2]|SC0_RES_US_HB_<br>INIPHASE[1]|SC0_RES_US_HB_<br>INIPHASE[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|SC0_SCL0_US7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SC0_RES_HCUT<br>[7]|SC0_RES_HCUT<br>[6]|SC0_RES_HCUT<br>[5]|SC0_RES_HCUT<br>[4]|SC0_RES_HCUT<br>[3]|SC0_RES_HCUT<br>[2]|SC0_RES_HCUT<br>[1]|SC0_RES_HCUT<br>[0]|
|||SC0_RES_VCUT<br>[7]|SC0_RES_VCUT<br>[6]|SC0_RES_VCUT<br>[5]|SC0_RES_VCUT<br>[4]|SC0_RES_VCUT<br>[3]|SC0_RES_VCUT<br>[2]|SC0_RES_VCUT<br>[1]|SC0_RES_VCUT<br>[0]|
||SC0_SCL0_US8|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SC0_RES_IBUS_SYN<br>C_SEL|-|-|-|SC0_RES_DISP_ON|
||SC0_SCL0_OVR1|-|-|-|-|-|-|-|-|
|||SC0_RES_BK_<br>COL_R[7]|SC0_RES_BK_<br>COL_R[6]|SC0_RES_BK_<br>COL_R[5]|SC0_RES_BK_<br>COL_R[4]|SC0_RES_BK_<br>COL_R[3]|SC0_RES_BK_<br>COL_R[2]|SC0_RES_BK_<br>COL_R[1]|SC0_RES_BK_<br>COL_R[0]|
|||SC0_RES_BK_<br>COL_G[7]|SC0_RES_BK_<br>COL_G[6]|SC0_RES_BK_<br>COL_G[5]|SC0_RES_BK_<br>COL_G[4]|SC0_RES_BK_<br>COL_G[3]|SC0_RES_BK_<br>COL_G[2]|SC0_RES_BK_<br>COL_G[1]|SC0_RES_BK_<br>COL_G[0]|
|||SC0_RES_BK_<br>COL_B[7]|SC0_RES_BK_<br>COL_B[6]|SC0_RES_BK_<br>COL_B[5]|SC0_RES_BK_<br>COL_B[4]|SC0_RES_BK_<br>COL_B[3]|SC0_RES_BK_<br>COL_B[2]|SC0_RES_BK_<br>COL_B[1]|SC0_RES_BK_<br>COL_B[0]|
||SC0_SCL1_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|SC0_SCL1_<br>UPDATE_B|-|-|-|SC0_SCL1_<br>UPDATE_A|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SC0_SCL1_<br>VEN_B|-|-|-|SC0_SCL1_<br>VEN_A|
||SC0_SCL1_WR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|SC0_RES_<br>WRSWA[2]|SC0_RES_<br>WRSWA[1]|SC0_RES_<br>WRSWA[0]|
|||-|-|-|-|-|-|-|-|
|||SC0_RES_TB_<br>ADD_MOD|SC0_RES_DS_<br>WR_MD[2]|SC0_RES_DS_<br>WR_MD[1]|SC0_RES_DS_<br>WR_MD[0]|SC0_RES_MD[1]|SC0_RES_MD[0]|SC0_RES_LOOP|SC0_RES_BST_MD|
||SC0_SCL1_WR2|SC0_RES_BASE<br>[31]|SC0_RES_BASE<br>[30]|SC0_RES_BASE<br>[29]|SC0_RES_BASE<br>[28]|SC0_RES_BASE<br>[27]|SC0_RES_BASE<br>[26]|SC0_RES_BASE<br>[25]|SC0_RES_BASE<br>[24]|
|||SC0_RES_BASE[23]|SC0_RES_BASE<br>[22]|SC0_RES_BASE<br>[21]|SC0_RES_BASE<br>[20]|SC0_RES_BASE<br>[19]|SC0_RES_BASE<br>[18]|SC0_RES_BASE<br>[17]|SC0_RES_BASE<br>[16]|
|||SC0_RES_BASE<br>[15]|SC0_RES_BASE<br>[14]|SC0_RES_BASE<br>[13]|SC0_RES_BASE<br>[12]|SC0_RES_BASE<br>[11]|SC0_RES_BASE<br>[10]|SC0_RES_BASE<br>[9]|SC0_RES_BASE<br>[8]|
|||SC0_RES_BASE<br>[7]|SC0_RES_BASE<br>[6]|SC0_RES_BASE<br>[5]|SC0_RES_BASE<br>[4]|SC0_RES_BASE<br>[3]|SC0_RES_BASE<br>[2]|SC0_RES_BASE<br>[1]|SC0_RES_BASE<br>[0]|
||SC0_SCL1_WR3|-|SC0_RES_LN_<br>OFF[14]|SC0_RES_LN_<br>OFF[13]|SC0_RES_LN_<br>OFF[12]|SC0_RES_LN_<br>OFF[11]|SC0_RES_LN_<br>OFF[10]|SC0_RES_LN_<br>OFF[9]|SC0_RES_LN_<br>OFF[8]|
|||SC0_RES_LN_<br>OFF[7]|SC0_RES_LN_<br>OFF[6]|SC0_RES_LN_<br>OFF[5]|SC0_RES_LN_<br>OFF[4]|SC0_RES_LN_<br>OFF[3]|SC0_RES_LN_<br>OFF[2]|SC0_RES_LN_<br>OFF[1]|SC0_RES_LN_<br>OFF[0]|
|||-|-|-|-|-|-|SC0_RES_FLM_NUM<br>[9]|SC0_RES_FLM_NUM<br>[8]|
|||SC0_RES_FLM_NUM<br>[7]|SC0_RES_FLM_NUM<br>[6]|SC0_RES_FLM_NUM<br>[5]|SC0_RES_FLM_NUM<br>[4]|SC0_RES_FLM_NUM<br>[3]|SC0_RES_FLM_NUM<br>[2]|SC0_RES_FLM_NUM<br>[1]|SC0_RES_FLM_NUM<br>[0]|
||SC0_SCL1_WR4|-|-|-|-|-|-|-|-|
|||-|SC0_RES_FLM_OFF<br>[22]|SC0_RES_FLM_OFF<br>[21]|SC0_RES_FLM_OFF<br>[20]|SC0_RES_FLM_OFF<br>[19]|SC0_RES_FLM_OFF<br>[18]|SC0_RES_FLM_OFF<br>[17]|SC0_RES_FLM_OFF<br>[16]|
|||SC0_RES_FLM_OFF<br>[15]|SC0_RES_FLM_OFF<br>[14]|SC0_RES_FLM_OFF<br>[13]|SC0_RES_FLM_OFF<br>[12]|SC0_RES_FLM_OFF<br>[11]|SC0_RES_FLM_OFF<br>[10]|SC0_RES_FLM_OFF<br>[9]|SC0_RES_FLM_OFF<br>[8]|
|||SC0_RES_FLM_OFF<br>[7]|SC0_RES_FLM_OFF<br>[6]|SC0_RES_FLM_OFF<br>[5]|SC0_RES_FLM_OFF<br>[4]|SC0_RES_FLM_OFF<br>[3]|SC0_RES_FLM_OFF<br>[2]|SC0_RES_FLM_OFF<br>[1]|SC0_RES_FLM_OFF<br>[0]|
||SC0_SCL1_WR5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SC0_RES_INTER|-|-|SC0_RES_FS_<br>RATE[1]|SC0_RES_FS_<br>RATE[0]|
|||-|-|-|SC0_RES_FLD_<br>SEL|-|-|-|SC0_RES_WENB|
||SC0_SCL1_WR6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SC0_RES_DTH_ON|-|-|-|SC0_RES_<br>BITDEC_ON|
||SC0_SCL1_WR7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SC0_RES_<br>OVERFLOW|
|||-|-|-|-|-|-|SC0_RES_FLM_CNT<br>[9]|SC0_RES_FLM_CNT<br>[8]|
|||SC0_RES_FLM_CNT<br>[7]|SC0_RES_FLM_CNT<br>[6]|SC0_RES_FLM_CNT<br>[5]|SC0_RES_FLM_CNT<br>[4]|SC0_RES_FLM_CNT<br>[3]|SC0_RES_FLM_CNT<br>[2]|SC0_RES_FLM_CNT<br>[1]|SC0_RES_FLM_CNT<br>[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|SC0_SCL1_WR8|SC0_RES_BASE_B<br>[31]|SC0_RES_BASE_B<br>[30]|SC0_RES_BASE_B<br>[29]|SC0_RES_BASE_B<br>[28]|SC0_RES_BASE_B<br>[27]|SC0_RES_BASE_B<br>[26]|SC0_RES_BASE_B<br>[25]|SC0_RES_BASE_B<br>[24]|
|||SC0_RES_BASE_B<br>[23]|SC0_RES_BASE_B<br>[22]|SC0_RES_BASE_B<br>[21]|SC0_RES_BASE_B<br>[20]|SC0_RES_BASE_B<br>[19]|SC0_RES_BASE_B<br>[18]|SC0_RES_BASE_B<br>[17]|SC0_RES_BASE_B<br>[16]|
|||SC0_RES_BASE_B<br>[15]|SC0_RES_BASE_B<br>[14]|SC0_RES_BASE_B<br>[13]|SC0_RES_BASE_B<br>[12]|SC0_RES_BASE_B<br>[11]|SC0_RES_BASE_B<br>[10]|SC0_RES_BASE_B<br>[9]|SC0_RES_BASE_B<br>[8]|
|||SC0_RES_BASE_B[7]|SC0_RES_BASE_B[6]|SC0_RES_BASE_B[5]|SC0_RES_BASE_B[4]|SC0_RES_BASE_B[3]|SC0_RES_BASE_B[2]|SC0_RES_BASE_B[1]|SC0_RES_BASE_B[0]|
||SC0_SCL1_WR9|-|SC0_RES_LN_<br>OFF_B[14]|SC0_RES_LN_<br>OFF_B[13]|SC0_RES_LN_<br>OFF_B[12]|SC0_RES_LN_<br>OFF_B[11]|SC0_RES_LN_<br>OFF_B[10]|SC0_RES_LN_<br>OFF_B[9]|SC0_RES_LN_<br>OFF_B[8]|
|||SC0_RES_LN_<br>OFF_B[7]|SC0_RES_LN_<br>OFF_B[6]|SC0_RES_LN_<br>OFF_B[5]|SC0_RES_LN_<br>OFF_B[4]|SC0_RES_LN_<br>OFF_B[3]|SC0_RES_LN_<br>OFF_B[2]|SC0_RES_LN_<br>OFF_B[1]|SC0_RES_LN_<br>OFF_B[0]|
|||-|-|-|-|-|-|SC0_RES_FLM_NUM<br>_B[9]|SC0_RES_FLM_NUM<br>_B[8]|
|||SC0_RES_FLM_NUM<br>_B[7]|SC0_RES_FLM_NUM<br>_B[6]|SC0_RES_FLM_NUM<br>_B[5]|SC0_RES_FLM_NUM<br>_B[4]|SC0_RES_FLM_NUM<br>_B[3]|SC0_RES_FLM_NUM<br>_B[2]|SC0_RES_FLM_NUM<br>_B[1]|SC0_RES_FLM_NUM<br>_B[0]|
||SC0_SCL1_WR10|-|-|-|-|-|-|-|-|
|||-|SC0_RES_FLM_OFF<br>_B[22]|SC0_RES_FLM_OFF<br>_B[21]|SC0_RES_FLM_OFF<br>_B[20]|SC0_RES_FLM_OFF<br>_B[19]|SC0_RES_FLM_OFF<br>_B[18]|SC0_RES_FLM_OFF<br>_B[17]|SC0_RES_FLM_OFF<br>_B[16]|
|||SC0_RES_FLM_OFF<br>_B[15]|SC0_RES_FLM_OFF<br>_B[14]|SC0_RES_FLM_OFF<br>_B[13]|SC0_RES_FLM_OFF<br>_B[12]|SC0_RES_FLM_OFF<br>_B[11]|SC0_RES_FLM_OFF<br>_B[10]|SC0_RES_FLM_OFF<br>_B[9]|SC0_RES_FLM_OFF<br>_B[8]|
|||SC0_RES_FLM_OFF<br>_B[7]|SC0_RES_FLM_OFF<br>_B[6]|SC0_RES_FLM_OFF<br>_B[5]|SC0_RES_FLM_OFF<br>_B[4]|SC0_RES_FLM_OFF<br>_B[3]|SC0_RES_FLM_OFF<br>_B[2]|SC0_RES_FLM_OFF<br>_B[1]|SC0_RES_FLM_OFF<br>_B[0]|
||SC0_SCL1_WR11|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|SC0_RES_FLM_CNT<br>_B[9]|SC0_RES_FLM_CNT<br>_B[8]|
|||SC0_RES_FLM_CNT<br>_B[7]|SC0_RES_FLM_CNT<br>_B[6]|SC0_RES_FLM_CNT<br>_B[5]|SC0_RES_FLM_CNT<br>_B[4]|SC0_RES_FLM_CNT<br>_B[3]|SC0_RES_FLM_CNT<br>_B[2]|SC0_RES_FLM_CNT<br>_B[1]|SC0_RES_FLM_CNT<br>_B[0]|
||SC0_SCL1_MON1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|SC0_PBUF_NUM[1]|SC0_PBUF_NUM[0]|
|||-|-|-|-|-|-|-|-|
||SC0_SCL1_PBUF0|SC0_PBUF0_<br>ADD[31]|SC0_PBUF0_<br>ADD[30]|SC0_PBUF0_<br>ADD[29]|SC0_PBUF0_<br>ADD[28]|SC0_PBUF0_<br>ADD[27]|SC0_PBUF0_<br>ADD[26]|SC0_PBUF0_<br>ADD[25]|SC0_PBUF0_<br>ADD[24]|
|||SC0_PBUF0_<br>ADD[23]|SC0_PBUF0_<br>ADD[22]|SC0_PBUF0_<br>ADD[21]|SC0_PBUF0_<br>ADD[20]|SC0_PBUF0_<br>ADD[19]|SC0_PBUF0_<br>ADD[18]|SC0_PBUF0_<br>ADD[17]|SC0_PBUF0_<br>ADD[16]|
|||SC0_PBUF0_<br>ADD[15]|SC0_PBUF0_<br>ADD[14]|SC0_PBUF0_<br>ADD[13]|SC0_PBUF0_<br>ADD[12]|SC0_PBUF0_<br>ADD[11]|SC0_PBUF0_<br>ADD[10]|SC0_PBUF0_<br>ADD[9]|SC0_PBUF0_<br>ADD[8]|
|||SC0_PBUF0_<br>ADD[7]|SC0_PBUF0_<br>ADD[6]|SC0_PBUF0_<br>ADD[5]|SC0_PBUF0_<br>ADD[4]|SC0_PBUF0_<br>ADD[3]|SC0_PBUF0_<br>ADD[2]|SC0_PBUF0_<br>ADD[1]|SC0_PBUF0_<br>ADD[0]|
||SC0_SCL1_PBUF1|SC0_PBUF1_<br>ADD[31]|SC0_PBUF1_<br>ADD[30]|SC0_PBUF1_<br>ADD[29]|SC0_PBUF1_<br>ADD[28]|SC0_PBUF1_<br>ADD[27]|SC0_PBUF1_<br>ADD[26]|SC0_PBUF1_<br>ADD[25]|SC0_PBUF1_<br>ADD[24]|
|||SC0_PBUF1_<br>ADD[23]|SC0_PBUF1_<br>ADD[22]|SC0_PBUF1_<br>ADD[21]|SC0_PBUF1_<br>ADD[20]|SC0_PBUF1_<br>ADD[19]|SC0_PBUF1_<br>ADD[18]|SC0_PBUF1_<br>ADD[17]|SC0_PBUF1_<br>ADD[16]|
|||SC0_PBUF1_<br>ADD[15]|SC0_PBUF1_<br>ADD[14]|SC0_PBUF1_<br>ADD[13]|SC0_PBUF1_<br>ADD[12]|SC0_PBUF1_<br>ADD[11]|SC0_PBUF1_<br>ADD[10]|SC0_PBUF1_<br>ADD[9]|SC0_PBUF1_<br>ADD[8]|
|||SC0_PBUF1_<br>ADD[7]|SC0_PBUF1_<br>ADD[6]|SC0_PBUF1_<br>ADD[5]|SC0_PBUF1_<br>ADD[4]|SC0_PBUF1_<br>ADD[3]|SC0_PBUF1_<br>ADD[2]|SC0_PBUF1_<br>ADD[1]|SC0_PBUF1_<br>ADD[0]|
||SC0_SCL1_PBUF2|SC0_PBUF2_<br>ADD[31]|SC0_PBUF2_<br>ADD[30]|SC0_PBUF2_<br>ADD[29]|SC0_PBUF2_<br>ADD[28]|SC0_PBUF2_<br>ADD[27]|SC0_PBUF2_<br>ADD[26]|SC0_PBUF2_<br>ADD[25]|SC0_PBUF2_<br>ADD[24]|
|||SC0_PBUF2_<br>ADD[23]|SC0_PBUF2_<br>ADD[22]|SC0_PBUF2_<br>ADD[21]|SC0_PBUF2_<br>ADD[20]|SC0_PBUF2_<br>ADD[19]|SC0_PBUF2_<br>ADD[18]|SC0_PBUF2_<br>ADD[17]|SC0_PBUF2_<br>ADD[16]|
|||SC0_PBUF2_<br>ADD[15]|SC0_PBUF2_<br>ADD[14]|SC0_PBUF2_<br>ADD[13]|SC0_PBUF2_<br>ADD[12]|SC0_PBUF2_<br>ADD[11]|SC0_PBUF2_<br>ADD[10]|SC0_PBUF2_<br>ADD[9]|SC0_PBUF2_<br>ADD[8]|
|||SC0_PBUF2_<br>ADD[7]|SC0_PBUF2_<br>ADD[6]|SC0_PBUF2_<br>ADD[5]|SC0_PBUF2_<br>ADD[4]|SC0_PBUF2_<br>ADD[3]|SC0_PBUF2_<br>ADD[2]|SC0_PBUF2_<br>ADD[1]|SC0_PBUF2_<br>ADD[0]|
||SC0_SCL1_PBUF3|SC0_PBUF3_<br>ADD[31]|SC0_PBUF3_<br>ADD[30]|SC0_PBUF3_<br>ADD[29]|SC0_PBUF3_<br>ADD[28]|SC0_PBUF3_<br>ADD[27]|SC0_PBUF3_<br>ADD[26]|SC0_PBUF3_<br>ADD[25]|SC0_PBUF3_<br>ADD[24]|
|||SC0_PBUF3_<br>ADD[23]|SC0_PBUF3_<br>ADD[22]|SC0_PBUF3_<br>ADD[21]|SC0_PBUF3_<br>ADD[20]|SC0_PBUF3_<br>ADD[19]|SC0_PBUF3_<br>ADD[18]|SC0_PBUF3_<br>ADD[17]|SC0_PBUF3_<br>ADD[16]|
|||SC0_PBUF3_<br>ADD[15]|SC0_PBUF3_<br>ADD[14]|SC0_PBUF3_<br>ADD[13]|SC0_PBUF3_<br>ADD[12]|SC0_PBUF3_<br>ADD[11]|SC0_PBUF3_<br>ADD[10]|SC0_PBUF3_<br>ADD[9]|SC0_PBUF3_<br>ADD[8]|
|||SC0_PBUF3_<br>ADD[7]|SC0_PBUF3_<br>ADD[6]|SC0_PBUF3_<br>ADD[5]|SC0_PBUF3_<br>ADD[4]|SC0_PBUF3_<br>ADD[3]|SC0_PBUF3_<br>ADD[2]|SC0_PBUF3_<br>ADD[1]|SC0_PBUF3_<br>ADD[0]|
||SC0_SCL1_PBUF_<br>FLD|-|-|-|-|-|-|-|SC0_FLD_INF3|
|||-|-|-|-|-|-|-|SC0_FLD_INF2|
|||-|-|-|-|-|-|-|SC0_FLD_INF1|
|||-|-|-|-|-|-|-|SC0_FLD_INF0|
||SC0_SCL1_PBUF_<br>CNT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SC0_PBUF_RST|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GR0_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR0_UPDATE|
|||-|-|-|GR0_P_VEN|-|-|-|GR0_IBUS_VEN|
||GR0_FLM_RD|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR0_R_ENB|
||GR0_FLM1|GR0_FLD_SEL|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR0_LN_OFF_<br>DIR|
|||-|-|-|-|-|-|GR0_FLM_SEL[1]|GR0_FLM_SEL[0]|
|||-|-|-|-|-|-|-|GR0_BST_MD|
||GR0_FLM2|GR0_BASE[31]|GR0_BASE[30]|GR0_BASE[29]|GR0_BASE[28]|GR0_BASE[27]|GR0_BASE[26]|GR0_BASE[25]|GR0_BASE[24]|
|||GR0_BASE[23]|GR0_BASE[22]|GR0_BASE[21]|GR0_BASE[20]|GR0_BASE[19]|GR0_BASE[18]|GR0_BASE[17]|GR0_BASE[16]|
|||GR0_BASE[15]|GR0_BASE[14]|GR0_BASE[13]|GR0_BASE[12]|GR0_BASE[11]|GR0_BASE[10]|GR0_BASE[9]|GR0_BASE[8]|
|||GR0_BASE[7]|GR0_BASE[6]|GR0_BASE[5]|GR0_BASE[4]|GR0_BASE[3]|GR0_BASE[2]|GR0_BASE[1]|GR0_BASE[0]|
||GR0_FLM3|GR0_FLD_NXT|GR0_LN_OFF[14]|GR0_LN_OFF[13]|GR0_LN_OFF[12]|GR0_LN_OFF[11]|GR0_LN_OFF[10]|GR0_LN_OFF[9]|GR0_LN_OFF[8]|
|||GR0_LN_OFF[7]|GR0_LN_OFF[6]|GR0_LN_OFF[5]|GR0_LN_OFF[4]|GR0_LN_OFF[3]|GR0_LN_OFF[2]|GR0_LN_OFF[1]|GR0_LN_OFF[0]|
|||-|-|-|-|-|-|GR0_FLM_NUM<br>[9]|GR0_FLM_NUM<br>[8]|
|||GR0_FLM_NUM<br>[7]|GR0_FLM_NUM<br>[6]|GR0_FLM_NUM<br>[5]|GR0_FLM_NUM<br>[4]|GR0_FLM_NUM<br>[3]|GR0_FLM_NUM<br>[2]|GR0_FLM_NUM<br>[1]|GR0_FLM_NUM<br>[0]|
||GR0_FLM4|-|-|-|-|-|-|-|-|
|||-|GR0_FLM_OFF<br>[22]|GR0_FLM_OFF<br>[21]|GR0_FLM_OFF<br>[20]|GR0_FLM_OFF<br>[19]|GR0_FLM_OFF<br>[18]|GR0_FLM_OFF<br>[17]|GR0_FLM_OFF<br>[16]|
|||GR0_FLM_OFF<br>[15]|GR0_FLM_OFF<br>[14]|GR0_FLM_OFF<br>[13]|GR0_FLM_OFF<br>[12]|GR0_FLM_OFF<br>[11]|GR0_FLM_OFF<br>[10]|GR0_FLM_OFF[9]|GR0_FLM_OFF[8]|
|||GR0_FLM_OFF[7]|GR0_FLM_OFF[6]|GR0_FLM_OFF[5]|GR0_FLM_OFF[4]|GR0_FLM_OFF[3]|GR0_FLM_OFF[2]|GR0_FLM_OFF[1]|GR0_FLM_OFF[0]|
||GR0_FLM5|-|-|-|-|-|GR0_FLM_LNUM[10]|GR0_FLM_LNUM[9]|GR0_FLM_LNUM[8]|
|||GR0_FLM_LNUM[7]|GR0_FLM_LNUM[6]|GR0_FLM_LNUM[5]|GR0_FLM_LNUM[4]|GR0_FLM_LNUM[3]|GR0_FLM_LNUM[2]|GR0_FLM_LNUM[1]|GR0_FLM_LNUM[0]|
|||-|-|-|-|-|GR0_FLM_LOOP<br>[10]|GR0_FLM_LOOP<br>[9]|GR0_FLM_LOOP<br>[8]|
|||GR0_FLM_LOOP<br>[7]|GR0_FLM_LOOP<br>[6]|GR0_FLM_LOOP<br>[5]|GR0_FLM_LOOP<br>[4]|GR0_FLM_LOOP<br>[3]|GR0_FLM_LOOP<br>[2]|GR0_FLM_LOOP<br>[1]|GR0_FLM_LOOP<br>[0]|
||GR0_FLM6|GR0_FORMAT[3]|GR0_FORMAT[2]|GR0_FORMAT[1]|GR0_FORMAT[0]|-|GR0_HW[10]|GR0_HW[9]|GR0_HW[8]|
|||GR0_HW[7]|GR0_HW[6]|GR0_HW[5]|GR0_HW[4]|GR0_HW[3]|GR0_HW[2]|GR0_HW[1]|GR0_HW[0]|
|||GR0_YCC_SWAP[2]|GR0_YCC_SWAP[1]|GR0_YCC_SWAP[0]|GR0_RDSWA[2]|GR0_RDSWA[1]|GR0_RDSWA[0]|-|GR0_CNV444_<br>MD|
|||-|-|GR0_STA_POS[5]|GR0_STA_POS[4]|GR0_STA_POS[3]|GR0_STA_POS[2]|GR0_STA_POS[1]|GR0_STA_POS[0]|
||GR0_AB1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|GR0_GRC_DISP_ON|-|-|GR0_DISP_SEL<br>[1]|GR0_DISP_SEL<br>[0]|
||GR0_AB2|-|-|-|-|-|GR0_GRC_VS<br>[10]|GR0_GRC_VS[9]|GR0_GRC_VS[8]|
|||GR0_GRC_VS[7]|GR0_GRC_VS[6]|GR0_GRC_VS[5]|GR0_GRC_VS[4]|GR0_GRC_VS[3]|GR0_GRC_VS[2]|GR0_GRC_VS[1]|GR0_GRC_VS[0]|
|||-|-|-|-|-|GR0_GRC_VW<br>[10]|GR0_GRC_VW[9]|GR0_GRC_VW[8]|
|||GR0_GRC_VW[7]|GR0_GRC_VW[6]|GR0_GRC_VW[5]|GR0_GRC_VW[4]|GR0_GRC_VW[3]|GR0_GRC_VW[2]|GR0_GRC_VW[1]|GR0_GRC_VW[0]|
||GR0_AB3|-|-|-|-|-|GR0_GRC_HS<br>[10]|GR0_GRC_HS[9]|GR0_GRC_HS[8]|
|||GR0_GRC_HS[7]|GR0_GRC_HS[6]|GR0_GRC_HS[5]|GR0_GRC_HS[4]|GR0_GRC_HS[3]|GR0_GRC_HS[2]|GR0_GRC_HS[1]|GR0_GRC_HS[0]|
|||-|-|-|-|-|GR0_GRC_HW<br>[10]|GR0_GRC_HW[9]|GR0_GRC_HW[8]|
|||GR0_GRC_HW[7]|GR0_GRC_HW[6]|GR0_GRC_HW[5]|GR0_GRC_HW[4]|GR0_GRC_HW[3]|GR0_GRC_HW[2]|GR0_GRC_HW[1]|GR0_GRC_HW[0]|
||GR0_AB7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR0_CK_ON|
||GR0_AB8|GR0_CK_KCLUT<br>[7]|GR0_CK_KCLUT<br>[6]|GR0_CK_KCLUT<br>[5]|GR0_CK_KCLUT<br>[4]|GR0_CK_KCLUT<br>[3]|GR0_CK_KCLUT<br>[2]|GR0_CK_KCLUT<br>[1]|GR0_CK_KCLUT<br>[0]|
|||GR0_CK_KG[7]|GR0_CK_KG[6]|GR0_CK_KG[5]|GR0_CK_KG[4]|GR0_CK_KG[3]|GR0_CK_KG[2]|GR0_CK_KG[1]|GR0_CK_KG[0]|
|||GR0_CK_KB[7]|GR0_CK_KB[6]|GR0_CK_KB[5]|GR0_CK_KB[4]|GR0_CK_KB[3]|GR0_CK_KB[2]|GR0_CK_KB[1]|GR0_CK_KB[0]|
|||GR0_CK_KR[7]|GR0_CK_KR[6]|GR0_CK_KR[5]|GR0_CK_KR[4]|GR0_CK_KR[3]|GR0_CK_KR[2]|GR0_CK_KR[1]|GR0_CK_KR[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GR0_AB9|GR0_CK_A[7]|GR0_CK_A[6]|GR0_CK_A[5]|GR0_CK_A[4]|GR0_CK_A[3]|GR0_CK_A[2]|GR0_CK_A[1]|GR0_CK_A[0]|
|||GR0_CK_G[7]|GR0_CK_G[6]|GR0_CK_G[5]|GR0_CK_G[4]|GR0_CK_G[3]|GR0_CK_G[2]|GR0_CK_G[1]|GR0_CK_G[0]|
|||GR0_CK_B[7]|GR0_CK_B[6]|GR0_CK_B[5]|GR0_CK_B[4]|GR0_CK_B[3]|GR0_CK_B[2]|GR0_CK_B[1]|GR0_CK_B[0]|
|||GR0_CK_R[7]|GR0_CK_R[6]|GR0_CK_R[5]|GR0_CK_R[4]|GR0_CK_R[3]|GR0_CK_R[2]|GR0_CK_R[1]|GR0_CK_R[0]|
||GR0_AB10|GR0_A0[7]|GR0_A0[6]|GR0_A0[5]|GR0_A0[4]|GR0_A0[3]|GR0_A0[2]|GR0_A0[1]|GR0_A0[0]|
|||GR0_G0[7]|GR0_G0[6]|GR0_G0[5]|GR0_G0[4]|GR0_G0[3]|GR0_G0[2]|GR0_G0[1]|GR0_G0[0]|
|||GR0_B0[7]|GR0_B0[6]|GR0_B0[5]|GR0_B0[4]|GR0_B0[3]|GR0_B0[2]|GR0_B0[1]|GR0_B0[0]|
|||GR0_R0[7]|GR0_R0[6]|GR0_R0[5]|GR0_R0[4]|GR0_R0[3]|GR0_R0[2]|GR0_R0[1]|GR0_R0[0]|
||GR0_AB11|GR0_A1[7]|GR0_A1[6]|GR0_A1[5]|GR0_A1[4]|GR0_A1[3]|GR0_A1[2]|GR0_A1[1]|GR0_A1[0]|
|||GR0_G1[7]|GR0_G1[6]|GR0_G1[5]|GR0_G1[4]|GR0_G1[3]|GR0_G1[2]|GR0_G1[1]|GR0_G1[0]|
|||GR0_B1[7]|GR0_B1[6]|GR0_B1[5]|GR0_B1[4]|GR0_B1[3]|GR0_B1[2]|GR0_B1[1]|GR0_B1[0]|
|||GR0_R1[7]|GR0_R1[6]|GR0_R1[5]|GR0_R1[4]|GR0_R1[3]|GR0_R1[2]|GR0_R1[1]|GR0_R1[0]|
||GR0_BASE|-|-|-|-|-|-|-|-|
|||GR0_BASE_G[7]|GR0_BASE_G[6]|GR0_BASE_G[5]|GR0_BASE_G[4]|GR0_BASE_G[3]|GR0_BASE_G[2]|GR0_BASE_G[1]|GR0_BASE_G[0]|
|||GR0_BASE_B[7]|GR0_BASE_B[6]|GR0_BASE_B[5]|GR0_BASE_B[4]|GR0_BASE_B[3]|GR0_BASE_B[2]|GR0_BASE_B[1]|GR0_BASE_B[0]|
|||GR0_BASE_R[7]|GR0_BASE_R[6]|GR0_BASE_R[5]|GR0_BASE_R[4]|GR0_BASE_R[3]|GR0_BASE_R[2]|GR0_BASE_R[1]|GR0_BASE_R[0]|
||GR0_CLUT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR0_CLT_SEL|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ADJ0_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|ADJ0_VEN|
||ADJ0_BKSTR_SET|-|-|-|-|-|-|-|BKSTR_ON|
|||BKSTR_ST[3]|BKSTR_ST[2]|BKSTR_ST[1]|BKSTR_ST[0]|BKSTR_D[3]|BKSTR_D[2]|BKSTR_D[1]|BKSTR_D[0]|
|||-|-|-|BKSTR_T1[4]|BKSTR_T1[3]|BKSTR_T1[2]|BKSTR_T1[1]|BKSTR_T1[0]|
|||-|-|-|BKSTR_T2[4]|BKSTR_T2[3]|BKSTR_T2[2]|BKSTR_T2[1]|BKSTR_T2[0]|
||ADJ0_ENH_TIM1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|ENH_MD|-|-|-|ENH_DISP_ON|
||ADJ0_ENH_TIM2|-|-|-|-|-|ENH_VS[10]|ENH_VS[9]|ENH_VS[8]|
|||ENH_VS[7]|ENH_VS[6]|ENH_VS[5]|ENH_VS[4]|ENH_VS[3]|ENH_VS[2]|ENH_VS[1]|ENH_VS[0]|
|||-|-|-|-|-|ENH_VW[10]|ENH_VW[9]|ENH_VW[8]|
|||ENH_VW[7]|ENH_VW[6]|ENH_VW[5]|ENH_VW[4]|ENH_VW[3]|ENH_VW[2]|ENH_VW[1]|ENH_VW[0]|
||ADJ0_ENH_TIM3|-|-|-|-|-|ENH_HS[10]|ENH_HS[9]|ENH_HS[8]|
|||ENH_HS[7]|ENH_HS[6]|ENH_HS[5]|ENH_HS[4]|ENH_HS[3]|ENH_HS[2]|ENH_HS[1]|ENH_HS[0]|
|||-|-|-|-|-|ENH_HW[10]|ENH_HW[9]|ENH_HW[8]|
|||ENH_HW[7]|ENH_HW[6]|ENH_HW[5]|ENH_HW[4]|ENH_HW[3]|ENH_HW[2]|ENH_HW[1]|ENH_HW[0]|
||ADJ0_ENH_SHP1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SHP_H_ON|
|||-|-|-|-|-|-|-|-|
|||-|SHP_H1_CORE[6]|SHP_H1_CORE[5]|SHP_H1_CORE[4]|SHP_H1_CORE[3]|SHP_H1_CORE[2]|SHP_H1_CORE[1]|SHP_H1_CORE[0]|
||ADJ0_ENH_SHP2|SHP_H1_CLIP_<br>O[7]|SHP_H1_CLIP_<br>O[6]|SHP_H1_CLIP_<br>O[5]|SHP_H1_CLIP_<br>O[4]|SHP_H1_CLIP_<br>O[3]|SHP_H1_CLIP_<br>O[2]|SHP_H1_CLIP_<br>O[1]|SHP_H1_CLIP_<br>O[0]|
|||SHP_H1_CLIP_<br>U[7]|SHP_H1_CLIP_<br>U[6]|SHP_H1_CLIP_<br>U[5]|SHP_H1_CLIP_<br>U[4]|SHP_H1_CLIP_<br>U[3]|SHP_H1_CLIP_<br>U[2]|SHP_H1_CLIP_<br>U[1]|SHP_H1_CLIP_<br>U[0]|
|||SHP_H1_GAIN_<br>O[7]|SHP_H1_GAIN_<br>O[6]|SHP_H1_GAIN_<br>O[5]|SHP_H1_GAIN_<br>O[4]|SHP_H1_GAIN_<br>O[3]|SHP_H1_GAIN_<br>O[2]|SHP_H1_GAIN_<br>O[1]|SHP_H1_GAIN_<br>O[0]|
|||SHP_H1_GAIN_<br>U[7]|SHP_H1_GAIN_<br>U[6]|SHP_H1_GAIN_<br>U[5]|SHP_H1_GAIN_<br>U[4]|SHP_H1_GAIN_<br>U[3]|SHP_H1_GAIN_<br>U[2]|SHP_H1_GAIN_<br>U[1]|SHP_H1_GAIN_<br>U[0]|
||ADJ0_ENH_SHP3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SHP_H2_LPF_SEL|
|||-|-|-|-|-|-|-|-|
|||-|SHP_H2_CORE[6]|SHP_H2_CORE[5]|SHP_H2_CORE[4]|SHP_H2_CORE[3]|SHP_H2_CORE[2]|SHP_H2_CORE[1]|SHP_H2_CORE[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|ADJ0_ENH_SHP4|SHP_H2_CLIP_<br>O[7]|SHP_H2_CLIP_<br>O[6]|SHP_H2_CLIP_<br>O[5]|SHP_H2_CLIP_<br>O[4]|SHP_H2_CLIP_<br>O[3]|SHP_H2_CLIP_<br>O[2]|SHP_H2_CLIP_<br>O[1]|SHP_H2_CLIP_<br>O[0]|
|||SHP_H2_CLIP_<br>U[7]|SHP_H2_CLIP_<br>U[6]|SHP_H2_CLIP_<br>U[5]|SHP_H2_CLIP_<br>U[4]|SHP_H2_CLIP_<br>U[3]|SHP_H2_CLIP_<br>U[2]|SHP_H2_CLIP_<br>U[1]|SHP_H2_CLIP_<br>U[0]|
|||SHP_H2_GAIN_<br>O[7]|SHP_H2_GAIN_<br>O[6]|SHP_H2_GAIN_<br>O[5]|SHP_H2_GAIN_<br>O[4]|SHP_H2_GAIN_<br>O[3]|SHP_H2_GAIN_<br>O[2]|SHP_H2_GAIN_<br>O[1]|SHP_H2_GAIN_<br>O[0]|
|||SHP_H2_GAIN_<br>U[7]|SHP_H2_GAIN_<br>U[6]|SHP_H2_GAIN_<br>U[5]|SHP_H2_GAIN_<br>U[4]|SHP_H2_GAIN_<br>U[3]|SHP_H2_GAIN_<br>U[2]|SHP_H2_GAIN_<br>U[1]|SHP_H2_GAIN_<br>U[0]|
||ADJ0_ENH_SHP5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|SHP_H3_CORE[6]|SHP_H3_CORE[5]|SHP_H3_CORE[4]|SHP_H3_CORE[3]|SHP_H3_CORE[2]|SHP_H3_CORE[1]|SHP_H3_CORE[0]|
||ADJ0_ENH_SHP6|SHP_H3_CLIP_<br>O[7]|SHP_H3_CLIP_<br>O[6]|SHP_H3_CLIP_<br>O[5]|SHP_H3_CLIP_<br>O[4]|SHP_H3_CLIP_<br>O[3]|SHP_H3_CLIP_<br>O[2]|SHP_H3_CLIP_<br>O[1]|SHP_H3_CLIP_<br>O[0]|
|||SHP_H3_CLIP_<br>U[7]|SHP_H3_CLIP_<br>U[6]|SHP_H3_CLIP_<br>U[5]|SHP_H3_CLIP_<br>U[4]|SHP_H3_CLIP_<br>U[3]|SHP_H3_CLIP_<br>U[2]|SHP_H3_CLIP_<br>U[1]|SHP_H3_CLIP_<br>U[0]|
|||SHP_H3_GAIN_<br>O[7]|SHP_H3_GAIN_<br>O[6]|SHP_H3_GAIN_<br>O[5]|SHP_H3_GAIN_<br>O[4]|SHP_H3_GAIN_<br>O[3]|SHP_H3_GAIN_<br>O[2]|SHP_H3_GAIN_<br>O[1]|SHP_H3_GAIN_<br>O[0]|
|||SHP_H3_GAIN_<br>U[7]|SHP_H3_GAIN_<br>U[6]|SHP_H3_GAIN_<br>U[5]|SHP_H3_GAIN_<br>U[4]|SHP_H3_GAIN_<br>U[3]|SHP_H3_GAIN_<br>U[2]|SHP_H3_GAIN_<br>U[1]|SHP_H3_GAIN_<br>U[0]|
||ADJ0_ENH_LTI1|LTI_H_ON|-|-|-|-|-|-|LTI_H2_LPF_SEL|
|||LTI_H2_INC_<br>ZERO[7]|LTI_H2_INC_<br>ZERO[6]|LTI_H2_INC_<br>ZERO[5]|LTI_H2_INC_<br>ZERO[4]|LTI_H2_INC_<br>ZERO[3]|LTI_H2_INC_<br>ZERO[2]|LTI_H2_INC_<br>ZERO[1]|LTI_H2_INC_<br>ZERO[0]|
|||LTI_H2_GAIN[7]|LTI_H2_GAIN[6]|LTI_H2_GAIN[5]|LTI_H2_GAIN[4]|LTI_H2_GAIN[3]|LTI_H2_GAIN[2]|LTI_H2_GAIN[1]|LTI_H2_GAIN[0]|
|||LTI_H2_CORE[7]|LTI_H2_CORE[6]|LTI_H2_CORE[5]|LTI_H2_CORE[4]|LTI_H2_CORE[3]|LTI_H2_CORE[2]|LTI_H2_CORE[1]|LTI_H2_CORE[0]|
||ADJ0_ENH_LTI2|-|-|-|-|-|-|-|LTI_H4_MEDIAN_TA<br>P_SEL|
|||LTI_H4_INC_<br>ZERO[7]|LTI_H4_INC_<br>ZERO[6]|LTI_H4_INC_<br>ZERO[5]|LTI_H4_INC_<br>ZERO[4]|LTI_H4_INC_<br>ZERO[3]|LTI_H4_INC_<br>ZERO[2]|LTI_H4_INC_<br>ZERO[1]|LTI_H4_INC_<br>ZERO[0]|
|||LTI_H4_GAIN[7]|LTI_H4_GAIN[6]|LTI_H4_GAIN[5]|LTI_H4_GAIN[4]|LTI_H4_GAIN[3]|LTI_H4_GAIN[2]|LTI_H4_GAIN[1]|LTI_H4_GAIN[0]|
|||LTI_H4_CORE[7]|LTI_H4_CORE[6]|LTI_H4_CORE[5]|LTI_H4_CORE[4]|LTI_H4_CORE[3]|LTI_H4_CORE[2]|LTI_H4_CORE[1]|LTI_H4_CORE[0]|
||ADJ0_MTX_MODE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|ADJ0_MTX_MD[1]|ADJ0_MTX_MD[0]|
||ADJ0_MTX_YG_<br>ADJ0|-|-|-|-|-|-|-|-|
|||ADJ0_MTX_YG[7]|ADJ0_MTX_YG[6]|ADJ0_MTX_YG[5]|ADJ0_MTX_YG[4]|ADJ0_MTX_YG[3]|ADJ0_MTX_YG[2]|ADJ0_MTX_YG[1]|ADJ0_MTX_YG[0]|
|||-|-|-|-|-|ADJ0_MTX_GG<br>[10]|ADJ0_MTX_GG<br>[9]|ADJ0_MTX_GG<br>[8]|
|||ADJ0_MTX_GG[7]|ADJ0_MTX_GG[6]|ADJ0_MTX_GG[5]|ADJ0_MTX_GG[4]|ADJ0_MTX_GG[3]|ADJ0_MTX_GG[2]|ADJ0_MTX_GG[1]|ADJ0_MTX_GG[0]|
||ADJ0_MTX_YG_<br>ADJ1|-|-|-|-|-|ADJ0_MTX_GB<br>[10]|ADJ0_MTX_GB[9]|ADJ0_MTX_GB[8]|
|||ADJ0_MTX_GB[7]|ADJ0_MTX_GB[6]|ADJ0_MTX_GB[5]|ADJ0_MTX_GB[4]|ADJ0_MTX_GB[3]|ADJ0_MTX_GB[2]|ADJ0_MTX_GB[1]|ADJ0_MTX_GB[0]|
|||-|-|-|-|-|ADJ0_MTX_GR<br>[10]|ADJ0_MTX_GR<br>[9]|ADJ0_MTX_GR<br>[8]|
|||ADJ0_MTX_GR[7]|ADJ0_MTX_GR[6]|ADJ0_MTX_GR[5]|ADJ0_MTX_GR[4]|ADJ0_MTX_GR[3]|ADJ0_MTX_GR[2]|ADJ0_MTX_GR[1]|ADJ0_MTX_GR[0]|
||ADJ0_MTX_CBB_<br>ADJ0|-|-|-|-|-|-|-|-|
|||ADJ0_MTX_B[7]|ADJ0_MTX_B[6]|ADJ0_MTX_B[5]|ADJ0_MTX_B[4]|ADJ0_MTX_B[3]|ADJ0_MTX_B[2]|ADJ0_MTX_B[1]|ADJ0_MTX_B[0]|
|||-|-|-|-|-|ADJ0_MTX_BG<br>[10]|ADJ0_MTX_BG[9]|ADJ0_MTX_BG[8]|
|||ADJ0_MTX_BG[7]|ADJ0_MTX_BG[6]|ADJ0_MTX_BG[5]|ADJ0_MTX_BG[4]|ADJ0_MTX_BG[3]|ADJ0_MTX_BG[2]|ADJ0_MTX_BG[1]|ADJ0_MTX_BG[0]|
||ADJ0_MTX_CBB_<br>ADJ1|-|-|-|-|-|ADJ0_MTX_BB<br>[10]|ADJ0_MTX_BB[9]|ADJ0_MTX_BB[8]|
|||ADJ0_MTX_BB[7]|ADJ0_MTX_BB[6]|ADJ0_MTX_BB[5]|ADJ0_MTX_BB[4]|ADJ0_MTX_BB[3]|ADJ0_MTX_BB[2]|ADJ0_MTX_BB[1]|ADJ0_MTX_BB[0]|
|||-|-|-|-|-|ADJ0_MTX_BR<br>[10]|ADJ0_MTX_BR[9]|ADJ0_MTX_BR[8]|
|||ADJ0_MTX_BR[7]|ADJ0_MTX_BR[6]|ADJ0_MTX_BR[5]|ADJ0_MTX_BR[4]|ADJ0_MTX_BR[3]|ADJ0_MTX_BR[2]|ADJ0_MTX_BR[1]|ADJ0_MTX_BR[0]|
||ADJ0_MTX_CRR_<br>ADJ0|-|-|-|-|-|-|-|-|
|||ADJ0_MTX_R[7]|ADJ0_MTX_R[6]|ADJ0_MTX_R[5]|ADJ0_MTX_R[4]|ADJ0_MTX_R[3]|ADJ0_MTX_R[2]|ADJ0_MTX_R[1]|ADJ0_MTX_R[0]|
|||-|-|-|-|-|ADJ0_MTX_RG<br>[10]|ADJ0_MTX_RG[9]|ADJ0_MTX_RG[8]|
|||ADJ0_MTX_RG[7]|ADJ0_MTX_RG[6]|ADJ0_MTX_RG[5]|ADJ0_MTX_RG[4]|ADJ0_MTX_RG[3]|ADJ0_MTX_RG[2]|ADJ0_MTX_RG[1]|ADJ0_MTX_RG[0]|
||ADJ0_MTX_CRR_<br>ADJ1|-|-|-|-|-|ADJ0_MTX_RB<br>[10]|ADJ0_MTX_RB[9]|ADJ0_MTX_RB[8]|
|||ADJ0_MTX_RB[7]|ADJ0_MTX_RB[6]|ADJ0_MTX_RB[5]|ADJ0_MTX_RB[4]|ADJ0_MTX_RB[3]|ADJ0_MTX_RB[2]|ADJ0_MTX_RB[1]|ADJ0_MTX_RB[0]|
|||-|-|-|-|-|ADJ0_MTX_RR<br>[10]|ADJ0_MTX_RR[9]|ADJ0_MTX_RR[8]|
|||ADJ0_MTX_RR[7]|ADJ0_MTX_RR[6]|ADJ0_MTX_RR[5]|ADJ0_MTX_RR[4]|ADJ0_MTX_RR[3]|ADJ0_MTX_RR[2]|ADJ0_MTX_RR[1]|ADJ0_MTX_RR[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GR2_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR2_UPDATE|
|||-|-|-|GR2_P_VEN|-|-|-|GR2_IBUS_VEN|
||GR2_FLM_RD|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR2_R_ENB|
||GR2_FLM1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR2_LN_OFF_<br>DIR|
|||-|-|-|-|-|-|GR2_FLM_SEL[1]|GR2_FLM_SEL[0]|
|||-|-|-|-|-|-|-|GR2_BST_MD|
||GR2_FLM2|GR2_BASE[31]|GR2_BASE[30]|GR2_BASE[29]|GR2_BASE[28]|GR2_BASE[27]|GR2_BASE[26]|GR2_BASE[25]|GR2_BASE[24]|
|||GR2_BASE[23]|GR2_BASE[22]|GR2_BASE[21]|GR2_BASE[20]|GR2_BASE[19]|GR2_BASE[18]|GR2_BASE[17]|GR2_BASE[16]|
|||GR2_BASE[15]|GR2_BASE[14]|GR2_BASE[13]|GR2_BASE[12]|GR2_BASE[11]|GR2_BASE[10]|GR2_BASE[9]|GR2_BASE[8]|
|||GR2_BASE[7]|GR2_BASE[6]|GR2_BASE[5]|GR2_BASE[4]|GR2_BASE[3]|GR2_BASE[2]|GR2_BASE[1]|GR2_BASE[0]|
||GR2_FLM3|-|GR2_LN_OFF[14]|GR2_LN_OFF[13]|GR2_LN_OFF[12]|GR2_LN_OFF[11]|GR2_LN_OFF[10]|GR2_LN_OFF[9]|GR2_LN_OFF[8]|
|||GR2_LN_OFF[7]|GR2_LN_OFF[6]|GR2_LN_OFF[5]|GR2_LN_OFF[4]|GR2_LN_OFF[3]|GR2_LN_OFF[2]|GR2_LN_OFF[1]|GR2_LN_OFF[0]|
|||-|-|-|-|-|-|GR2_FLM_NUM<br>[9]|GR2_FLM_NUM<br>[8]|
|||GR2_FLM_NUM<br>[7]|GR2_FLM_NUM<br>[6]|GR2_FLM_NUM<br>[5]|GR2_FLM_NUM<br>[4]|GR2_FLM_NUM<br>[3]|GR2_FLM_NUM[2]|GR2_FLM_NUM<br>[1]|GR2_FLM_NUM<br>[0]|
||GR2_FLM4|-|-|-|-|-|-|-|-|
|||-|GR2_FLM_OFF<br>[22]|GR2_FLM_OFF<br>[21]|GR2_FLM_OFF<br>[20]|GR2_FLM_OFF<br>[19]|GR2_FLM_OFF<br>[18]|GR2_FLM_OFF<br>[17]|GR2_FLM_OFF<br>[16]|
|||GR2_FLM_OFF<br>[15]|GR2_FLM_OFF<br>[14]|GR2_FLM_OFF<br>[13]|GR2_FLM_OFF<br>[12]|GR2_FLM_OFF<br>[11]|GR2_FLM_OFF<br>[10]|GR2_FLM_OFF[9]|GR2_FLM_OFF[8]|
|||GR2_FLM_OFF[7]|GR2_FLM_OFF[6]|GR2_FLM_OFF[5]|GR2_FLM_OFF[4]|GR2_FLM_OFF[3]|GR2_FLM_OFF[2]|GR2_FLM_OFF[1]|GR2_FLM_OFF[0]|
||GR2_FLM5|-|-|-|-|-|GR2_FLM_LNUM[10]|GR2_FLM_LNUM[9]|GR2_FLM_LNUM[8]|
|||GR2_FLM_LNUM[7]|GR2_FLM_LNUM[6]|GR2_FLM_LNUM[5]|GR2_FLM_LNUM[4]|GR2_FLM_LNUM[3]|GR2_FLM_LNUM[2]|GR2_FLM_LNUM[1]|GR2_FLM_LNUM[0]|
|||-|-|-|-|-|GR2_FLM_LOOP<br>[10]|GR2_FLM_LOOP<br>[9]|GR2_FLM_LOOP<br>[8]|
|||GR2_FLM_LOOP<br>[7]|GR2_FLM_LOOP<br>[6]|GR2_FLM_LOOP<br>[5]|GR2_FLM_LOOP<br>[4]|GR2_FLM_LOOP<br>[3]|GR2_FLM_LOOP<br>[2]|GR2_FLM_LOOP<br>[1]|GR2_FLM_LOOP<br>[0]|
||GR2_FLM6|GR2_FORMAT[3]|GR2_FORMAT[2]|GR2_FORMAT[1]|GR2_FORMAT[0]|-|GR2_HW[10]|GR2_HW[9]|GR2_HW[8]|
|||GR2_HW[7]|GR2_HW[6]|GR2_HW[5]|GR2_HW[4]|GR2_HW[3]|GR2_HW[2]|GR2_HW[1]|GR2_HW[0]|
|||-|-|-|GR2_RDSWA[2]|GR2_RDSWA[1]|GR2_RDSWA[0]|-|-|
|||-|-|GR2_STA_POS[5]|GR2_STA_POS[4]|GR2_STA_POS[3]|GR2_STA_POS[2]|GR2_STA_POS[1]|GR2_STA_POS[0]|
||GR2_AB1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||GR2_ARC_MUL|GR2_ACALC_MD|-|GR2_ARC_ON|-|-|-|GR2_ARC_DISP_ON|
|||-|-|-|GR2_GRC_DISP_ON|-|-|GR2_DISP_SEL[1]|GR2_DISP_SEL[0]|
||GR2_AB2|-|-|-|-|-|GR2_GRC_VS<br>[10]|GR2_GRC_VS[9]|GR2_GRC_VS[8]|
|||GR2_GRC_VS[7]|GR2_GRC_VS[6]|GR2_GRC_VS[5]|GR2_GRC_VS[4]|GR2_GRC_VS[3]|GR2_GRC_VS[2]|GR2_GRC_VS[1]|GR2_GRC_VS[0]|
|||-|-|-|-|-|GR2_GRC_VW<br>[10]|GR2_GRC_VW[9]|GR2_GRC_VW[8]|
|||GR2_GRC_VW[7]|GR2_GRC_VW[6]|GR2_GRC_VW[5]|GR2_GRC_VW[4]|GR2_GRC_VW[3]|GR2_GRC_VW[2]|GR2_GRC_VW[1]|GR2_GRC_VW[0]|
||GR2_AB3|-|-|-|-|-|GR2_GRC_HS[10]|GR2_GRC_HS[9]|GR2_GRC_HS[8]|
|||GR2_GRC_HS[7]|GR2_GRC_HS[6]|GR2_GRC_HS[5]|GR2_GRC_HS[4]|GR2_GRC_HS[3]|GR2_GRC_HS[2]|GR2_GRC_HS[1]|GR2_GRC_HS[0]|
|||-|-|-|-|-|GR2_GRC_HW<br>[10]|GR2_GRC_HW[9]|GR2_GRC_HW[8]|
|||GR2_GRC_HW[7]|GR2_GRC_HW[6]|GR2_GRC_HW[5]|GR2_GRC_HW[4]|GR2_GRC_HW[3]|GR2_GRC_HW[2]|GR2_GRC_HW[1]|GR2_GRC_HW[0]|
||GR2_AB4|-|-|-|-|-|GR2_ARC_VS[10]|GR2_ARC_VS[9]|GR2_ARC_VS[8]|
|||GR2_ARC_VS[7]|GR2_ARC_VS[6]|GR2_ARC_VS[5]|GR2_ARC_VS[4]|GR2_ARC_VS[3]|GR2_ARC_VS[2]|GR2_ARC_VS[1]|GR2_ARC_VS[0]|
|||-|-|-|-|-|GR2_ARC_VW<br>[10]|GR2_ARC_VW[9]|GR2_ARC_VW[8]|
|||GR2_ARC_VW[7]|GR2_ARC_VW[6]|GR2_ARC_VW[5]|GR2_ARC_VW[4]|GR2_ARC_VW[3]|GR2_ARC_VW[2]|GR2_ARC_VW[1]|GR2_ARC_VW[0]|
||GR2_AB5|-|-|-|-|-|GR2_ARC_HS<br>[10]|GR2_ARC_HS[9]|GR2_ARC_HS[8]|
|||GR2_ARC_HS[7]|GR2_ARC_HS[6]|GR2_ARC_HS[5]|GR2_ARC_HS[4]|GR2_ARC_HS[3]|GR2_ARC_HS[2]|GR2_ARC_HS[1]|GR2_ARC_HS[0]|
|||-|-|-|-|-|GR2_ARC_HW<br>[10]|GR2_ARC_HW[9]|GR2_ARC_HW[8]|
|||GR2_ARC_HW[7]|GR2_ARC_HW[6]|GR2_ARC_HW[5]|GR2_ARC_HW[4]|GR2_ARC_HW[3]|GR2_ARC_HW[2]|GR2_ARC_HW[1]|GR2_ARC_HW[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GR2_AB6|-|-|-|-|-|-|-|GR2_ARC_<br>MODE|
|||GR2_ARC_COEF[7]|GR2_ARC_COEF[6]|GR2_ARC_COEF[5]|GR2_ARC_COEF[4]|GR2_ARC_COEF[3]|GR2_ARC_COEF[2]|GR2_ARC_COEF[1]|GR2_ARC_COEF[0]|
|||-|-|-|-|-|-|-|-|
|||GR2_ARC_RATE<br>[7]|GR2_ARC_RATE<br>[6]|GR2_ARC_RATE<br>[5]|GR2_ARC_RATE<br>[4]|GR2_ARC_RATE<br>[3]|GR2_ARC_RATE<br>[2]|GR2_ARC_RATE<br>[1]|GR2_ARC_RATE<br>[0]|
||GR2_AB7|-|-|-|-|-|-|-|-|
|||GR2_ARC_DEF[7]|GR2_ARC_DEF[6]|GR2_ARC_DEF[5]|GR2_ARC_DEF[4]|GR2_ARC_DEF[3]|GR2_ARC_DEF[2]|GR2_ARC_DEF[1]|GR2_ARC_DEF[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR2_CK_ON|
||GR2_AB8|GR2_CK_KCLUT<br>[7]|GR2_CK_KCLUT<br>[6]|GR2_CK_KCLUT<br>[5]|GR2_CK_KCLUT<br>[4]|GR2_CK_KCLUT<br>[3]|GR2_CK_KCLUT<br>[2]|GR2_CK_KCLUT<br>[1]|GR2_CK_KCLUT<br>[0]|
|||GR2_CK_KG[7]|GR2_CK_KG[6]|GR2_CK_KG[5]|GR2_CK_KG[4]|GR2_CK_KG[3]|GR2_CK_KG[2]|GR2_CK_KG[1]|GR2_CK_KG[0]|
|||GR2_CK_KB[7]|GR2_CK_KB[6]|GR2_CK_KB[5]|GR2_CK_KB[4]|GR2_CK_KB[3]|GR2_CK_KB[2]|GR2_CK_KB[1]|GR2_CK_KB[0]|
|||GR2_CK_KR[7]|GR2_CK_KR[6]|GR2_CK_KR[5]|GR2_CK_KR[4]|GR2_CK_KR[3]|GR2_CK_KR[2]|GR2_CK_KR[1]|GR2_CK_KR[0]|
||GR2_AB9|GR2_CK_A[7]|GR2_CK_A[6]|GR2_CK_A[5]|GR2_CK_A[4]|GR2_CK_A[3]|GR2_CK_A[2]|GR2_CK_A[1]|GR2_CK_A[0]|
|||GR2_CK_G[7]|GR2_CK_G[6]|GR2_CK_G[5]|GR2_CK_G[4]|GR2_CK_G[3]|GR2_CK_G[2]|GR2_CK_G[1]|GR2_CK_G[0]|
|||GR2_CK_B[7]|GR2_CK_B[6]|GR2_CK_B[5]|GR2_CK_B[4]|GR2_CK_B[3]|GR2_CK_B[2]|GR2_CK_B[1]|GR2_CK_B[0]|
|||GR2_CK_R[7]|GR2_CK_R[6]|GR2_CK_R[5]|GR2_CK_R[4]|GR2_CK_R[3]|GR2_CK_R[2]|GR2_CK_R[1]|GR2_CK_R[0]|
||GR2_AB10|GR2_A0[7]|GR2_A0[6]|GR2_A0[5]|GR2_A0[4]|GR2_A0[3]|GR2_A0[2]|GR2_A0[1]|GR2_A0[0]|
|||GR2_G0[7]|GR2_G0[6]|GR2_G0[5]|GR2_G0[4]|GR2_G0[3]|GR2_G0[2]|GR2_G0[1]|GR2_G0[0]|
|||GR2_B0[7]|GR2_B0[6]|GR2_B0[5]|GR2_B0[4]|GR2_B0[3]|GR2_B0[2]|GR2_B0[1]|GR2_B0[0]|
|||GR2_R0[7]|GR2_R0[6]|GR2_R0[5]|GR2_R0[4]|GR2_R0[3]|GR2_R0[2]|GR2_R0[1]|GR2_R0[0]|
||GR2_AB11|GR2_A1[7]|GR2_A1[6]|GR2_A1[5]|GR2_A1[4]|GR2_A1[3]|GR2_A1[2]|GR2_A1[1]|GR2_A1[0]|
|||GR2_G1[7]|GR2_G1[6]|GR2_G1[5]|GR2_G1[4]|GR2_G1[3]|GR2_G1[2]|GR2_G1[1]|GR2_G1[0]|
|||GR2_B1[7]|GR2_B1[6]|GR2_B1[5]|GR2_B1[4]|GR2_B1[3]|GR2_B1[2]|GR2_B1[1]|GR2_B1[0]|
|||GR2_R1[7]|GR2_R1[6]|GR2_R1[5]|GR2_R1[4]|GR2_R1[3]|GR2_R1[2]|GR2_R1[1]|GR2_R1[0]|
||GR2_BASE|-|-|-|-|-|-|-|-|
|||GR2_BASE_G[7]|GR2_BASE_G[6]|GR2_BASE_G[5]|GR2_BASE_G[4]|GR2_BASE_G[3]|GR2_BASE_G[2]|GR2_BASE_G[1]|GR2_BASE_G[0]|
|||GR2_BASE_B[7]|GR2_BASE_B[6]|GR2_BASE_B[5]|GR2_BASE_B[4]|GR2_BASE_B[3]|GR2_BASE_B[2]|GR2_BASE_B[1]|GR2_BASE_B[0]|
|||GR2_BASE_R[7]|GR2_BASE_R[6]|GR2_BASE_R[5]|GR2_BASE_R[4]|GR2_BASE_R[3]|GR2_BASE_R[2]|GR2_BASE_R[1]|GR2_BASE_R[0]|
||GR2_CLUT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR2_CLT_SEL|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||GR2_MON|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR2_ARC_ST|
||GR3_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR3_UPDATE|
|||-|-|-|GR3_P_VEN|-|-|-|GR3_IBUS_VEN|
||GR3_FLM_RD|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR3_R_ENB|
||GR3_FLM1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR3_LN_OFF_<br>DIR|
|||-|-|-|-|-|-|GR3_FLM_SEL[1]|GR3_FLM_SEL[0]|
|||-|-|-|-|-|-|-|GR3_BST_MD|
||GR3_FLM2|GR3_BASE[31]|GR3_BASE[30]|GR3_BASE[29]|GR3_BASE[28]|GR3_BASE[27]|GR3_BASE[26]|GR3_BASE[25]|GR3_BASE[24]|
|||GR3_BASE[23]|GR3_BASE[22]|GR3_BASE[21]|GR3_BASE[20]|GR3_BASE[19]|GR3_BASE[18]|GR3_BASE[17]|GR3_BASE[16]|
|||GR3_BASE[15]|GR3_BASE[14]|GR3_BASE[13]|GR3_BASE[12]|GR3_BASE[11]|GR3_BASE[10]|GR3_BASE[9]|GR3_BASE[8]|
|||GR3_BASE[7]|GR3_BASE[6]|GR3_BASE[5]|GR3_BASE[4]|GR3_BASE[3]|GR3_BASE[2]|GR3_BASE[1]|GR3_BASE[0]|
||GR3_FLM3|-|GR3_LN_OFF[14]|GR3_LN_OFF[13]|GR3_LN_OFF[12]|GR3_LN_OFF[11]|GR3_LN_OFF[10]|GR3_LN_OFF[9]|GR3_LN_OFF[8]|
|||GR3_LN_OFF[7]|GR3_LN_OFF[6]|GR3_LN_OFF[5]|GR3_LN_OFF[4]|GR3_LN_OFF[3]|GR3_LN_OFF[2]|GR3_LN_OFF[1]|GR3_LN_OFF[0]|
|||-|-|-|-|-|-|GR3_FLM_NUM<br>[9]|GR3_FLM_NUM<br>[8]|
|||GR3_FLM_NUM<br>[7]|GR3_FLM_NUM<br>[6]|GR3_FLM_NUM<br>[5]|GR3_FLM_NUM<br>[4]|GR3_FLM_NUM<br>[3]|GR3_FLM_NUM<br>[2]|GR3_FLM_NUM<br>[1]|GR3_FLM_NUM<br>[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GR3_FLM4|-|-|-|-|-|-|-|-|
|||-|GR3_FLM_OFF<br>[22]|GR3_FLM_OFF<br>[21]|GR3_FLM_OFF<br>[20]|GR3_FLM_OFF<br>[19]|GR3_FLM_OFF<br>[18]|GR3_FLM_OFF<br>[17]|GR3_FLM_OFF<br>[16]|
|||GR3_FLM_OFF<br>[15]|GR3_FLM_OFF<br>[14]|GR3_FLM_OFF<br>[13]|GR3_FLM_OFF<br>[12]|GR3_FLM_OFF<br>[11]|GR3_FLM_OFF<br>[10]|GR3_FLM_OFF[9]|GR3_FLM_OFF[8]|
|||GR3_FLM_OFF[7]|GR3_FLM_OFF[6]|GR3_FLM_OFF[5]|GR3_FLM_OFF[4]|GR3_FLM_OFF[3]|GR3_FLM_OFF[2]|GR3_FLM_OFF[1]|GR3_FLM_OFF[0]|
||GR3_FLM5|-|-|-|-|-|GR3_FLM_LNUM[10]|GR3_FLM_LNUM[9]|GR3_FLM_LNUM[8]|
|||GR3_FLM_LNUM[7]|GR3_FLM_LNUM[6]|GR3_FLM_LNUM[5]|GR3_FLM_LNUM[4]|GR3_FLM_LNUM[3]|GR3_FLM_LNUM[2]|GR3_FLM_LNUM[1]|GR3_FLM_LNUM[0]|
|||-|-|-|-|-|GR3_FLM_LOOP<br>[10]|GR3_FLM_LOOP<br>[9]|GR3_FLM_LOOP<br>[8]|
|||GR3_FLM_LOOP<br>[7]|GR3_FLM_LOOP<br>[6]|GR3_FLM_LOOP<br>[5]|GR3_FLM_LOOP<br>[4]|GR3_FLM_LOOP<br>[3]|GR3_FLM_LOOP<br>[2]|GR3_FLM_LOOP<br>[1]|GR3_FLM_LOOP<br>[0]|
||GR3_FLM6|GR3_FORMAT[3]|GR3_FORMAT[2]|GR3_FORMAT[1]|GR3_FORMAT[0]|-|GR3_HW[10]|GR3_HW[9]|GR3_HW[8]|
|||GR3_HW[7]|GR3_HW[6]|GR3_HW[5]|GR3_HW[4]|GR3_HW[3]|GR3_HW[2]|GR3_HW[1]|GR3_HW[0]|
|||-|-|-|GR3_RDSWA[2]|GR3_RDSWA[1]|GR3_RDSWA[0]|-|-|
|||-|-|GR3_STA_POS[5]|GR3_STA_POS[4]|GR3_STA_POS[3]|GR3_STA_POS[2]|GR3_STA_POS[1]|GR3_STA_POS[0]|
||GR3_AB1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||GR3_ARC_MUL|GR3_ACALC_MD|-|GR3_ARC_ON|-|-|-|GR3_ARC_DISP_ON|
|||-|-|-|GR3_GRC_DISP_ON|-|-|GR3_DISP_SEL[1]|GR3_DISP_SEL[0]|
||GR3_AB2|-|-|-|-|-|GR3_GRC_VS[10]|GR3_GRC_VS[9]|GR3_GRC_VS[8]|
|||GR3_GRC_VS[7]|GR3_GRC_VS[6]|GR3_GRC_VS[5]|GR3_GRC_VS[4]|GR3_GRC_VS[3]|GR3_GRC_VS[2]|GR3_GRC_VS[1]|GR3_GRC_VS[0]|
|||-|-|-|-|-|GR3_GRC_VW<br>[10]|GR3_GRC_VW[9]|GR3_GRC_VW[8]|
|||GR3_GRC_VW[7]|GR3_GRC_VW[6]|GR3_GRC_VW[5]|GR3_GRC_VW[4]|GR3_GRC_VW[3]|GR3_GRC_VW[2]|GR3_GRC_VW[1]|GR3_GRC_VW[0]|
||GR3_AB3|-|-|-|-|-|GR3_GRC_HS[10]|GR3_GRC_HS[9]|GR3_GRC_HS[8]|
|||GR3_GRC_HS[7]|GR3_GRC_HS[6]|GR3_GRC_HS[5]|GR3_GRC_HS[4]|GR3_GRC_HS[3]|GR3_GRC_HS[2]|GR3_GRC_HS[1]|GR3_GRC_HS[0]|
|||-|-|-|-|-|GR3_GRC_HW<br>[10]|GR3_GRC_HW[9]|GR3_GRC_HW[8]|
|||GR3_GRC_HW[7]|GR3_GRC_HW[6]|GR3_GRC_HW[5]|GR3_GRC_HW[4]|GR3_GRC_HW[3]|GR3_GRC_HW[2]|GR3_GRC_HW[1]|GR3_GRC_HW[0]|
||GR3_AB4|-|-|-|-|-|GR3_ARC_VS[10]|GR3_ARC_VS[9]|GR3_ARC_VS[8]|
|||GR3_ARC_VS[7]|GR3_ARC_VS[6]|GR3_ARC_VS[5]|GR3_ARC_VS[4]|GR3_ARC_VS[3]|GR3_ARC_VS[2]|GR3_ARC_VS[1]|GR3_ARC_VS[0]|
|||-|-|-|-|-|GR3_ARC_VW<br>[10]|GR3_ARC_VW[9]|GR3_ARC_VW[8]|
|||GR3_ARC_VW[7]|GR3_ARC_VW[6]|GR3_ARC_VW[5]|GR3_ARC_VW[4]|GR3_ARC_VW[3]|GR3_ARC_VW[2]|GR3_ARC_VW[1]|GR3_ARC_VW[0]|
||GR3_AB5|-|-|-|-|-|GR3_ARC_HS[10]|GR3_ARC_HS[9]|GR3_ARC_HS[8]|
|||GR3_ARC_HS[7]|GR3_ARC_HS[6]|GR3_ARC_HS[5]|GR3_ARC_HS[4]|GR3_ARC_HS[3]|GR3_ARC_HS[2]|GR3_ARC_HS[1]|GR3_ARC_HS[0]|
|||-|-|-|-|-|GR3_ARC_HW<br>[10]|GR3_ARC_HW[9]|GR3_ARC_HW[8]|
|||GR3_ARC_HW[7]|GR3_ARC_HW[6]|GR3_ARC_HW[5]|GR3_ARC_HW[4]|GR3_ARC_HW[3]|GR3_ARC_HW[2]|GR3_ARC_HW[1]|GR3_ARC_HW[0]|
||GR3_AB6|-|-|-|-|-|-|-|GR3_ARC_<br>MODE|
|||GR3_ARC_COEF[7]|GR3_ARC_COEF[6]|GR3_ARC_COEF[5]|GR3_ARC_COEF[4]|GR3_ARC_COEF[3]|GR3_ARC_COEF[2]|GR3_ARC_COEF[1]|GR3_ARC_COEF[0]|
|||-|-|-|-|-|-|-|-|
|||GR3_ARC_RATE<br>[7]|GR3_ARC_RATE<br>[6]|GR3_ARC_RATE<br>[5]|GR3_ARC_RATE<br>[4]|GR3_ARC_RATE<br>[3]|GR3_ARC_RATE<br>[2]|GR3_ARC_RATE<br>[1]|GR3_ARC_RATE<br>[0]|
||GR3_AB7|-|-|-|-|-|-|-|-|
|||GR3_ARC_DEF[7]|GR3_ARC_DEF[6]|GR3_ARC_DEF[5]|GR3_ARC_DEF[4]|GR3_ARC_DEF[3]|GR3_ARC_DEF[2]|GR3_ARC_DEF[1]|GR3_ARC_DEF[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR3_CK_ON|
||GR3_AB8|GR3_CK_KCLUT<br>[7]|GR3_CK_KCLUT<br>[6]|GR3_CK_KCLUT<br>[5]|GR3_CK_KCLUT<br>[4]|GR3_CK_KCLUT<br>[3]|GR3_CK_KCLUT<br>[2]|GR3_CK_KCLUT<br>[1]|GR3_CK_KCLUT<br>[0]|
|||GR3_CK_KG[7]|GR3_CK_KG[6]|GR3_CK_KG[5]|GR3_CK_KG[4]|GR3_CK_KG[3]|GR3_CK_KG[2]|GR3_CK_KG[1]|GR3_CK_KG[0]|
|||GR3_CK_KB[7]|GR3_CK_KB[6]|GR3_CK_KB[5]|GR3_CK_KB[4]|GR3_CK_KB[3]|GR3_CK_KB[2]|GR3_CK_KB[1]|GR3_CK_KB[0]|
|||GR3_CK_KR[7]|GR3_CK_KR[6]|GR3_CK_KR[5]|GR3_CK_KR[4]|GR3_CK_KR[3]|GR3_CK_KR[2]|GR3_CK_KR[1]|GR3_CK_KR[0]|
||GR3_AB9|GR3_CK_A[7]|GR3_CK_A[6]|GR3_CK_A[5]|GR3_CK_A[4]|GR3_CK_A[3]|GR3_CK_A[2]|GR3_CK_A[1]|GR3_CK_A[0]|
|||GR3_CK_G[7]|GR3_CK_G[6]|GR3_CK_G[5]|GR3_CK_G[4]|GR3_CK_G[3]|GR3_CK_G[2]|GR3_CK_G[1]|GR3_CK_G[0]|
|||GR3_CK_B[7]|GR3_CK_B[6]|GR3_CK_B[5]|GR3_CK_B[4]|GR3_CK_B[3]|GR3_CK_B[2]|GR3_CK_B[1]|GR3_CK_B[0]|
|||GR3_CK_R[7]|GR3_CK_R[6]|GR3_CK_R[5]|GR3_CK_R[4]|GR3_CK_R[3]|GR3_CK_R[2]|GR3_CK_R[1]|GR3_CK_R[0]|
||GR3_AB10|GR3_A0[7]|GR3_A0[6]|GR3_A0[5]|GR3_A0[4]|GR3_A0[3]|GR3_A0[2]|GR3_A0[1]|GR3_A0[0]|
|||GR3_G0[7]|GR3_G0[6]|GR3_G0[5]|GR3_G0[4]|GR3_G0[3]|GR3_G0[2]|GR3_G0[1]|GR3_G0[0]|
|||GR3_B0[7]|GR3_B0[6]|GR3_B0[5]|GR3_B0[4]|GR3_B0[3]|GR3_B0[2]|GR3_B0[1]|GR3_B0[0]|
|||GR3_R0[7]|GR3_R0[6]|GR3_R0[5]|GR3_R0[4]|GR3_R0[3]|GR3_R0[2]|GR3_R0[1]|GR3_R0[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GR3_AB11|GR3_A1[7]|GR3_A1[6]|GR3_A1[5]|GR3_A1[4]|GR3_A1[3]|GR3_A1[2]|GR3_A1[1]|GR3_A1[0]|
|||GR3_G1[7]|GR3_G1[6]|GR3_G1[5]|GR3_G1[4]|GR3_G1[3]|GR3_G1[2]|GR3_G1[1]|GR3_G1[0]|
|||GR3_B1[7]|GR3_B1[6]|GR3_B1[5]|GR3_B1[4]|GR3_B1[3]|GR3_B1[2]|GR3_B1[1]|GR3_B1[0]|
|||GR3_R1[7]|GR3_R1[6]|GR3_R1[5]|GR3_R1[4]|GR3_R1[3]|GR3_R1[2]|GR3_R1[1]|GR3_R1[0]|
||GR3_BASE|-|-|-|-|-|-|-|-|
|||GR3_BASE_G[7]|GR3_BASE_G[6]|GR3_BASE_G[5]|GR3_BASE_G[4]|GR3_BASE_G[3]|GR3_BASE_G[2]|GR3_BASE_G[1]|GR3_BASE_G[0]|
|||GR3_BASE_B[7]|GR3_BASE_B[6]|GR3_BASE_B[5]|GR3_BASE_B[4]|GR3_BASE_B[3]|GR3_BASE_B[2]|GR3_BASE_B[1]|GR3_BASE_B[0]|
|||GR3_BASE_R[7]|GR3_BASE_R[6]|GR3_BASE_R[5]|GR3_BASE_R[4]|GR3_BASE_R[3]|GR3_BASE_R[2]|GR3_BASE_R[1]|GR3_BASE_R[0]|
||GR3_CLUT_INT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR3_CLT_SEL|
|||-|-|-|-|-|GR3_LINE[10]|GR3_LINE[9]|GR3_LINE[8]|
|||GR3_LINE[7]|GR3_LINE[6]|GR3_LINE[5]|GR3_LINE[4]|GR3_LINE[3]|GR3_LINE[2]|GR3_LINE[1]|GR3_LINE[0]|
||GR3_MON|-|-|-|-|-|GR3_LIN_STAT<br>[10]|GR3_LIN_STAT[9]|GR3_LIN_STAT[8]|
|||GR3_LIN_STAT[7]|GR3_LIN_STAT[6]|GR3_LIN_STAT[5]|GR3_LIN_STAT[4]|GR3_LIN_STAT[3]|GR3_LIN_STAT[2]|GR3_LIN_STAT[1]|GR3_LIN_STAT[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR3_ARC_ST|
||GR_VIN_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GR_VIN_<br>UPDATE|
|||-|-|-|GR_VIN_P_VEN|-|-|-|-|
||GR_VIN_AB1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|GR_VIN_SCL_<br>UND_SEL|GR_VIN_DISP_<br>SEL[1]|GR_VIN_DISP_<br>SEL[0]|
||GAM_G_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GAM_G_VEN|
||GAM_SW|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GAM_ON|
||GAM_G_LUT1|-|-|-|-|-|GAM_G_GAIN_00<br>[10]|GAM_G_GAIN_00<br>[9]|GAM_G_GAIN_00<br>[8]|
|||GAM_G_GAIN_00<br>[7]|GAM_G_GAIN_00<br>[6]|GAM_G_GAIN_00<br>[5]|GAM_G_GAIN_00<br>[4]|GAM_G_GAIN_00<br>[3]|GAM_G_GAIN_00<br>[2]|GAM_G_GAIN_00<br>[1]|GAM_G_GAIN_00<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_01<br>[10]|GAM_G_GAIN_01<br>[9]|GAM_G_GAIN_01<br>[8]|
|||GAM_G_GAIN_01<br>[7]|GAM_G_GAIN_01<br>[6]|GAM_G_GAIN_01<br>[5]|GAM_G_GAIN_01<br>[4]|GAM_G_GAIN_01<br>[3]|GAM_G_GAIN_01<br>[2]|GAM_G_GAIN_01<br>[1]|GAM_G_GAIN_01<br>[0]|
||GAM_G_LUT2|-|-|-|-|-|GAM_G_GAIN_02<br>[10]|GAM_G_GAIN_02<br>[9]|GAM_G_GAIN_02<br>[8]|
|||GAM_G_GAIN_02<br>[7]|GAM_G_GAIN_02<br>[6]|GAM_G_GAIN_02<br>[5]|GAM_G_GAIN_02<br>[4]|GAM_G_GAIN_02<br>[3]|GAM_G_GAIN_02<br>[2]|GAM_G_GAIN_02<br>[1]|GAM_G_GAIN_02<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_03<br>[10]|GAM_G_GAIN_03<br>[9]|GAM_G_GAIN_03<br>[8]|
|||GAM_G_GAIN_03<br>[7]|GAM_G_GAIN_03<br>[6]|GAM_G_GAIN_03<br>[5]|GAM_G_GAIN_03<br>[4]|GAM_G_GAIN_03<br>[3]|GAM_G_GAIN_03<br>[2]|GAM_G_GAIN_03<br>[1]|GAM_G_GAIN_03<br>[0]|
||GAM_G_LUT3|-|-|-|-|-|GAM_G_GAIN_04<br>[10]|GAM_G_GAIN_04<br>[9]|GAM_G_GAIN_04<br>[8]|
|||GAM_G_GAIN_04<br>[7]|GAM_G_GAIN_04<br>[6]|GAM_G_GAIN_04<br>[5]|GAM_G_GAIN_04<br>[4]|GAM_G_GAIN_04<br>[3]|GAM_G_GAIN_04<br>[2]|GAM_G_GAIN_04<br>[1]|GAM_G_GAIN_04<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_05<br>[10]|GAM_G_GAIN_05<br>[9]|GAM_G_GAIN_05<br>[8]|
|||GAM_G_GAIN_05<br>[7]|GAM_G_GAIN_05<br>[6]|GAM_G_GAIN_05<br>[5]|GAM_G_GAIN_05<br>[4]|GAM_G_GAIN_05<br>[3]|GAM_G_GAIN_05<br>[2]|GAM_G_GAIN_05<br>[1]|GAM_G_GAIN_05<br>[0]|
||GAM_G_LUT4|-|-|-|-|-|GAM_G_GAIN_06<br>[10]|GAM_G_GAIN_06<br>[9]|GAM_G_GAIN_06<br>[8]|
|||GAM_G_GAIN_06<br>[7]|GAM_G_GAIN_06<br>[6]|GAM_G_GAIN_06<br>[5]|GAM_G_GAIN_06<br>[4]|GAM_G_GAIN_06<br>[3]|GAM_G_GAIN_06<br>[2]|GAM_G_GAIN_06<br>[1]|GAM_G_GAIN_06<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_07<br>[10]|GAM_G_GAIN_07<br>[9]|GAM_G_GAIN_07<br>[8]|
|||GAM_G_GAIN_07<br>[7]|GAM_G_GAIN_07<br>[6]|GAM_G_GAIN_07<br>[5]|GAM_G_GAIN_07<br>[4]|GAM_G_GAIN_07<br>[3]|GAM_G_GAIN_07<br>[2]|GAM_G_GAIN_07<br>[1]|GAM_G_GAIN_07<br>[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GAM_G_LUT5|-|-|-|-|-|GAM_G_GAIN_08<br>[10]|GAM_G_GAIN_08<br>[9]|GAM_G_GAIN_08<br>[8]|
|||GAM_G_GAIN_08<br>[7]|GAM_G_GAIN_08<br>[6]|GAM_G_GAIN_08<br>[5]|GAM_G_GAIN_08<br>[4]|GAM_G_GAIN_08<br>[3]|GAM_G_GAIN_08<br>[2]|GAM_G_GAIN_08<br>[1]|GAM_G_GAIN_08<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_09<br>[10]|GAM_G_GAIN_09<br>[9]|GAM_G_GAIN_09<br>[8]|
|||GAM_G_GAIN_09<br>[7]|GAM_G_GAIN_09<br>[6]|GAM_G_GAIN_09<br>[5]|GAM_G_GAIN_09<br>[4]|GAM_G_GAIN_09<br>[3]|GAM_G_GAIN_09<br>[2]|GAM_G_GAIN_09<br>[1]|GAM_G_GAIN_09<br>[0]|
||GAM_G_LUT6|-|-|-|-|-|GAM_G_GAIN_10<br>[10]|GAM_G_GAIN_10<br>[9]|GAM_G_GAIN_10<br>[8]|
|||GAM_G_GAIN_10<br>[7]|GAM_G_GAIN_10<br>[6]|GAM_G_GAIN_10<br>[5]|GAM_G_GAIN_10<br>[4]|GAM_G_GAIN_10<br>[3]|GAM_G_GAIN_10<br>[2]|GAM_G_GAIN_10<br>[1]|GAM_G_GAIN_10<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_11<br>[10]|GAM_G_GAIN_11<br>[9]|GAM_G_GAIN_11<br>[8]|
|||GAM_G_GAIN_11<br>[7]|GAM_G_GAIN_11<br>[6]|GAM_G_GAIN_11<br>[5]|GAM_G_GAIN_11<br>[4]|GAM_G_GAIN_11<br>[3]|GAM_G_GAIN_11<br>[2]|GAM_G_GAIN_11<br>[1]|GAM_G_GAIN_11<br>[0]|
||GAM_G_LUT7|-|-|-|-|-|GAM_G_GAIN_12<br>[10]|GAM_G_GAIN_12<br>[9]|GAM_G_GAIN_12<br>[8]|
|||GAM_G_GAIN_12<br>[7]|GAM_G_GAIN_12<br>[6]|GAM_G_GAIN_12<br>[5]|GAM_G_GAIN_12<br>[4]|GAM_G_GAIN_12<br>[3]|GAM_G_GAIN_12<br>[2]|GAM_G_GAIN_12<br>[1]|GAM_G_GAIN_12<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_13<br>[10]|GAM_G_GAIN_13<br>[9]|GAM_G_GAIN_13<br>[8]|
|||GAM_G_GAIN_13<br>[7]|GAM_G_GAIN_13<br>[6]|GAM_G_GAIN_13<br>[5]|GAM_G_GAIN_13<br>[4]|GAM_G_GAIN_13<br>[3]|GAM_G_GAIN_13<br>[2]|GAM_G_GAIN_13<br>[1]|GAM_G_GAIN_13<br>[0]|
||GAM_G_LUT8|-|-|-|-|-|GAM_G_GAIN_14<br>[10]|GAM_G_GAIN_14<br>[9]|GAM_G_GAIN_14<br>[8]|
|||GAM_G_GAIN_14<br>[7]|GAM_G_GAIN_14<br>[6]|GAM_G_GAIN_14<br>[5]|GAM_G_GAIN_14<br>[4]|GAM_G_GAIN_14<br>[3]|GAM_G_GAIN_14<br>[2]|GAM_G_GAIN_14<br>[1]|GAM_G_GAIN_14<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_15<br>[10]|GAM_G_GAIN_15<br>[9]|GAM_G_GAIN_15<br>[8]|
|||GAM_G_GAIN_15<br>[7]|GAM_G_GAIN_15<br>[6]|GAM_G_GAIN_15<br>[5]|GAM_G_GAIN_15<br>[4]|GAM_G_GAIN_15<br>[3]|GAM_G_GAIN_15<br>[2]|GAM_G_GAIN_15<br>[1]|GAM_G_GAIN_15<br>[0]|
||GAM_G_LUT9|-|-|-|-|-|GAM_G_GAIN_16<br>[10]|GAM_G_GAIN_16<br>[9]|GAM_G_GAIN_16<br>[8]|
|||GAM_G_GAIN_16<br>[7]|GAM_G_GAIN_16<br>[6]|GAM_G_GAIN_16<br>[5]|GAM_G_GAIN_16<br>[4]|GAM_G_GAIN_16<br>[3]|GAM_G_GAIN_16<br>[2]|GAM_G_GAIN_16<br>[1]|GAM_G_GAIN_16<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_17<br>[10]|GAM_G_GAIN_17<br>[9]|GAM_G_GAIN_17<br>[8]|
|||GAM_G_GAIN_17<br>[7]|GAM_G_GAIN_17<br>[6]|GAM_G_GAIN_17<br>[5]|GAM_G_GAIN_17<br>[4]|GAM_G_GAIN_17<br>[3]|GAM_G_GAIN_17<br>[2]|GAM_G_GAIN_17<br>[1]|GAM_G_GAIN_17<br>[0]|
||GAM_G_LUT10|-|-|-|-|-|GAM_G_GAIN_18<br>[10]|GAM_G_GAIN_18<br>[9]|GAM_G_GAIN_18<br>[8]|
|||GAM_G_GAIN_18<br>[7]|GAM_G_GAIN_18<br>[6]|GAM_G_GAIN_18<br>[5]|GAM_G_GAIN_18<br>[4]|GAM_G_GAIN_18<br>[3]|GAM_G_GAIN_18<br>[2]|GAM_G_GAIN_18<br>[1]|GAM_G_GAIN_18<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_19<br>[10]|GAM_G_GAIN_19<br>[9]|GAM_G_GAIN_19<br>[8]|
|||GAM_G_GAIN_19<br>[7]|GAM_G_GAIN_19<br>[6]|GAM_G_GAIN_19<br>[5]|GAM_G_GAIN_19<br>[4]|GAM_G_GAIN_19<br>[3]|GAM_G_GAIN_19<br>[2]|GAM_G_GAIN_19<br>[1]|GAM_G_GAIN_19<br>[0]|
||GAM_G_LUT11|-|-|-|-|-|GAM_G_GAIN_20<br>[10]|GAM_G_GAIN_20<br>[9]|GAM_G_GAIN_20<br>[8]|
|||GAM_G_GAIN_20<br>[7]|GAM_G_GAIN_20<br>[6]|GAM_G_GAIN_20<br>[5]|GAM_G_GAIN_20<br>[4]|GAM_G_GAIN_20<br>[3]|GAM_G_GAIN_20<br>[2]|GAM_G_GAIN_20<br>[1]|GAM_G_GAIN_20<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_21<br>[10]|GAM_G_GAIN_21<br>[9]|GAM_G_GAIN_21<br>[8]|
|||GAM_G_GAIN_21<br>[7]|GAM_G_GAIN_21<br>[6]|GAM_G_GAIN_21<br>[5]|GAM_G_GAIN_21<br>[4]|GAM_G_GAIN_21<br>[3]|GAM_G_GAIN_21<br>[2]|GAM_G_GAIN_21<br>[1]|GAM_G_GAIN_21<br>[0]|
||GAM_G_LUT12|-|-|-|-|-|GAM_G_GAIN_22<br>[10]|GAM_G_GAIN_22<br>[9]|GAM_G_GAIN_22<br>[8]|
|||GAM_G_GAIN_22<br>[7]|GAM_G_GAIN_22<br>[6]|GAM_G_GAIN_22<br>[5]|GAM_G_GAIN_22<br>[4]|GAM_G_GAIN_22<br>[3]|GAM_G_GAIN_22<br>[2]|GAM_G_GAIN_22<br>[1]|GAM_G_GAIN_22<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_23<br>[10]|GAM_G_GAIN_23<br>[9]|GAM_G_GAIN_23<br>[8]|
|||GAM_G_GAIN_23<br>[7]|GAM_G_GAIN_23<br>[6]|GAM_G_GAIN_23<br>[5]|GAM_G_GAIN_23<br>[4]|GAM_G_GAIN_23<br>[3]|GAM_G_GAIN_23<br>[2]|GAM_G_GAIN_23<br>[1]|GAM_G_GAIN_23<br>[0]|
||GAM_G_LUT13|-|-|-|-|-|GAM_G_GAIN_24<br>[10]|GAM_G_GAIN_24<br>[9]|GAM_G_GAIN_24<br>[8]|
|||GAM_G_GAIN_24<br>[7]|GAM_G_GAIN_24<br>[6]|GAM_G_GAIN_24<br>[5]|GAM_G_GAIN_24<br>[4]|GAM_G_GAIN_24<br>[3]|GAM_G_GAIN_24<br>[2]|GAM_G_GAIN_24<br>[1]|GAM_G_GAIN_24<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_25<br>[10]|GAM_G_GAIN_25<br>[9]|GAM_G_GAIN_25<br>[8]|
|||GAM_G_GAIN_25<br>[7]|GAM_G_GAIN_25<br>[6]|GAM_G_GAIN_25<br>[5]|GAM_G_GAIN_25<br>[4]|GAM_G_GAIN_25<br>[3]|GAM_G_GAIN_25<br>[2]|GAM_G_GAIN_25<br>[1]|GAM_G_GAIN_25<br>[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GAM_G_LUT14|-|-|-|-|-|GAM_G_GAIN_26<br>[10]|GAM_G_GAIN_26<br>[9]|GAM_G_GAIN_26<br>[8]|
|||GAM_G_GAIN_26<br>[7]|GAM_G_GAIN_26<br>[6]|GAM_G_GAIN_26<br>[5]|GAM_G_GAIN_26<br>[4]|GAM_G_GAIN_26<br>[3]|GAM_G_GAIN_26<br>[2]|GAM_G_GAIN_26<br>[1]|GAM_G_GAIN_26<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_27<br>[10]|GAM_G_GAIN_27<br>[9]|GAM_G_GAIN_27<br>[8]|
|||GAM_G_GAIN_27<br>[7]|GAM_G_GAIN_27<br>[6]|GAM_G_GAIN_27<br>[5]|GAM_G_GAIN_27<br>[4]|GAM_G_GAIN_27<br>[3]|GAM_G_GAIN_27<br>[2]|GAM_G_GAIN_27<br>[1]|GAM_G_GAIN_27<br>[0]|
||GAM_G_LUT15|-|-|-|-|-|GAM_G_GAIN_28<br>[10]|GAM_G_GAIN_28<br>[9]|GAM_G_GAIN_28<br>[8]|
|||GAM_G_GAIN_28<br>[7]|GAM_G_GAIN_28<br>[6]|GAM_G_GAIN_28<br>[5]|GAM_G_GAIN_28<br>[4]|GAM_G_GAIN_28<br>[3]|GAM_G_GAIN_28<br>[2]|GAM_G_GAIN_28<br>[1]|GAM_G_GAIN_28<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_29<br>[10]|GAM_G_GAIN_29<br>[9]|GAM_G_GAIN_29<br>[8]|
|||GAM_G_GAIN_29<br>[7]|GAM_G_GAIN_29<br>[6]|GAM_G_GAIN_29<br>[5]|GAM_G_GAIN_29<br>[4]|GAM_G_GAIN_29<br>[3]|GAM_G_GAIN_29<br>[2]|GAM_G_GAIN_29<br>[1]|GAM_G_GAIN_29<br>[0]|
||GAM_G_LUT16|-|-|-|-|-|GAM_G_GAIN_30<br>[10]|GAM_G_GAIN_30<br>[9]|GAM_G_GAIN_30<br>[8]|
|||GAM_G_GAIN_30<br>[7]|GAM_G_GAIN_30<br>[6]|GAM_G_GAIN_30<br>[5]|GAM_G_GAIN_30<br>[4]|GAM_G_GAIN_30<br>[3]|GAM_G_GAIN_30<br>[2]|GAM_G_GAIN_30<br>[1]|GAM_G_GAIN_30<br>[0]|
|||-|-|-|-|-|GAM_G_GAIN_31<br>[10]|GAM_G_GAIN_31<br>[9]|GAM_G_GAIN_31<br>[8]|
|||GAM_G_GAIN_31<br>[7]|GAM_G_GAIN_31<br>[6]|GAM_G_GAIN_31<br>[5]|GAM_G_GAIN_31<br>[4]|GAM_G_GAIN_31<br>[3]|GAM_G_GAIN_31<br>[2]|GAM_G_GAIN_31<br>[1]|GAM_G_GAIN_31<br>[0]|
||GAM_G_AREA1|-|-|-|-|-|-|-|-|
|||GAM_G_TH_01[7]|GAM_G_TH_01[6]|GAM_G_TH_01[5]|GAM_G_TH_01[4]|GAM_G_TH_01[3]|GAM_G_TH_01[2]|GAM_G_TH_01[1]|GAM_G_TH_01[0]|
|||GAM_G_TH_02[7]|GAM_G_TH_02[6]|GAM_G_TH_02[5]|GAM_G_TH_02[4]|GAM_G_TH_02[3]|GAM_G_TH_02[2]|GAM_G_TH_02[1]|GAM_G_TH_02[0]|
|||GAM_G_TH_03[7]|GAM_G_TH_03[6]|GAM_G_TH_03[5]|GAM_G_TH_03[4]|GAM_G_TH_03[3]|GAM_G_TH_03[2]|GAM_G_TH_03[1]|GAM_G_TH_03[0]|
||GAM_G_AREA2|GAM_G_TH_04[7]|GAM_G_TH_04[6]|GAM_G_TH_04[5]|GAM_G_TH_04[4]|GAM_G_TH_04[3]|GAM_G_TH_04[2]|GAM_G_TH_04[1]|GAM_G_TH_04[0]|
|||GAM_G_TH_05[7]|GAM_G_TH_05[6]|GAM_G_TH_05[5]|GAM_G_TH_05[4]|GAM_G_TH_05[3]|GAM_G_TH_05[2]|GAM_G_TH_05[1]|GAM_G_TH_05[0]|
|||GAM_G_TH_06[7]|GAM_G_TH_06[6]|GAM_G_TH_06[5]|GAM_G_TH_06[4]|GAM_G_TH_06[3]|GAM_G_TH_06[2]|GAM_G_TH_06[1]|GAM_G_TH_06[0]|
|||GAM_G_TH_07[7]|GAM_G_TH_07[6]|GAM_G_TH_07[5]|GAM_G_TH_07[4]|GAM_G_TH_07[3]|GAM_G_TH_07[2]|GAM_G_TH_07[1]|GAM_G_TH_07[0]|
||GAM_G_AREA3|GAM_G_TH_08[7]|GAM_G_TH_08[6]|GAM_G_TH_08[5]|GAM_G_TH_08[4]|GAM_G_TH_08[3]|GAM_G_TH_08[2]|GAM_G_TH_08[1]|GAM_G_TH_08[0]|
|||GAM_G_TH_09[7]|GAM_G_TH_09[6]|GAM_G_TH_09[5]|GAM_G_TH_09[4]|GAM_G_TH_09[3]|GAM_G_TH_09[2]|GAM_G_TH_09[1]|GAM_G_TH_09[0]|
|||GAM_G_TH_10[7]|GAM_G_TH_10[6]|GAM_G_TH_10[5]|GAM_G_TH_10[4]|GAM_G_TH_10[3]|GAM_G_TH_10[2]|GAM_G_TH_10[1]|GAM_G_TH_10[0]|
|||GAM_G_TH_11[7]|GAM_G_TH_11[6]|GAM_G_TH_11[5]|GAM_G_TH_11[4]|GAM_G_TH_11[3]|GAM_G_TH_11[2]|GAM_G_TH_11[1]|GAM_G_TH_11[0]|
||GAM_G_AREA4|GAM_G_TH_12[7]|GAM_G_TH_12[6]|GAM_G_TH_12[5]|GAM_G_TH_12[4]|GAM_G_TH_12[3]|GAM_G_TH_12[2]|GAM_G_TH_12[1]|GAM_G_TH_12[0]|
|||GAM_G_TH_13[7]|GAM_G_TH_13[6]|GAM_G_TH_13[5]|GAM_G_TH_13[4]|GAM_G_TH_13[3]|GAM_G_TH_13[2]|GAM_G_TH_13[1]|GAM_G_TH_13[0]|
|||GAM_G_TH_14[7]|GAM_G_TH_14[6]|GAM_G_TH_14[5]|GAM_G_TH_14[4]|GAM_G_TH_14[3]|GAM_G_TH_14[2]|GAM_G_TH_14[1]|GAM_G_TH_14[0]|
|||GAM_G_TH_15[7]|GAM_G_TH_15[6]|GAM_G_TH_15[5]|GAM_G_TH_15[4]|GAM_G_TH_15[3]|GAM_G_TH_15[2]|GAM_G_TH_15[1]|GAM_G_TH_15[0]|
||GAM_G_AREA5|GAM_G_TH_16[7]|GAM_G_TH_16[6]|GAM_G_TH_16[5]|GAM_G_TH_16[4]|GAM_G_TH_16[3]|GAM_G_TH_16[2]|GAM_G_TH_16[1]|GAM_G_TH_16[0]|
|||GAM_G_TH_17[7]|GAM_G_TH_17[6]|GAM_G_TH_17[5]|GAM_G_TH_17[4]|GAM_G_TH_17[3]|GAM_G_TH_17[2]|GAM_G_TH_17[1]|GAM_G_TH_17[0]|
|||GAM_G_TH_18[7]|GAM_G_TH_18[6]|GAM_G_TH_18[5]|GAM_G_TH_18[4]|GAM_G_TH_18[3]|GAM_G_TH_18[2]|GAM_G_TH_18[1]|GAM_G_TH_18[0]|
|||GAM_G_TH_19[7]|GAM_G_TH_19[6]|GAM_G_TH_19[5]|GAM_G_TH_19[4]|GAM_G_TH_19[3]|GAM_G_TH_19[2]|GAM_G_TH_19[1]|GAM_G_TH_19[0]|
||GAM_G_AREA6|GAM_G_TH_20[7]|GAM_G_TH_20[6]|GAM_G_TH_20[5]|GAM_G_TH_20[4]|GAM_G_TH_20[3]|GAM_G_TH_20[2]|GAM_G_TH_20[1]|GAM_G_TH_20[0]|
|||GAM_G_TH_21[7]|GAM_G_TH_21[6]|GAM_G_TH_21[5]|GAM_G_TH_21[4]|GAM_G_TH_21[3]|GAM_G_TH_21[2]|GAM_G_TH_21[1]|GAM_G_TH_21[0]|
|||GAM_G_TH_22[7]|GAM_G_TH_22[6]|GAM_G_TH_22[5]|GAM_G_TH_22[4]|GAM_G_TH_22[3]|GAM_G_TH_22[2]|GAM_G_TH_22[1]|GAM_G_TH_22[0]|
|||GAM_G_TH_23[7]|GAM_G_TH_23[6]|GAM_G_TH_23[5]|GAM_G_TH_23[4]|GAM_G_TH_23[3]|GAM_G_TH_23[2]|GAM_G_TH_23[1]|GAM_G_TH_23[0]|
||GAM_G_AREA7|GAM_G_TH_24[7]|GAM_G_TH_24[6]|GAM_G_TH_24[5]|GAM_G_TH_24[4]|GAM_G_TH_24[3]|GAM_G_TH_24[2]|GAM_G_TH_24[1]|GAM_G_TH_24[0]|
|||GAM_G_TH_25[7]|GAM_G_TH_25[6]|GAM_G_TH_25[5]|GAM_G_TH_25[4]|GAM_G_TH_25[3]|GAM_G_TH_25[2]|GAM_G_TH_25[1]|GAM_G_TH_25[0]|
|||GAM_G_TH_26[7]|GAM_G_TH_26[6]|GAM_G_TH_26[5]|GAM_G_TH_26[4]|GAM_G_TH_26[3]|GAM_G_TH_26[2]|GAM_G_TH_26[1]|GAM_G_TH_26[0]|
|||GAM_G_TH_27[7]|GAM_G_TH_27[6]|GAM_G_TH_27[5]|GAM_G_TH_27[4]|GAM_G_TH_27[3]|GAM_G_TH_27[2]|GAM_G_TH_27[1]|GAM_G_TH_27[0]|
||GAM_G_AREA8|GAM_G_TH_28[7]|GAM_G_TH_28[6]|GAM_G_TH_28[5]|GAM_G_TH_28[4]|GAM_G_TH_28[3]|GAM_G_TH_28[2]|GAM_G_TH_28[1]|GAM_G_TH_28[0]|
|||GAM_G_TH_29[7]|GAM_G_TH_29[6]|GAM_G_TH_29[5]|GAM_G_TH_29[4]|GAM_G_TH_29[3]|GAM_G_TH_29[2]|GAM_G_TH_29[1]|GAM_G_TH_29[0]|
|||GAM_G_TH_30[7]|GAM_G_TH_30[6]|GAM_G_TH_30[5]|GAM_G_TH_30[4]|GAM_G_TH_30[3]|GAM_G_TH_30[2]|GAM_G_TH_30[1]|GAM_G_TH_30[0]|
|||GAM_G_TH_31[7]|GAM_G_TH_31[6]|GAM_G_TH_31[5]|GAM_G_TH_31[4]|GAM_G_TH_31[3]|GAM_G_TH_31[2]|GAM_G_TH_31[1]|GAM_G_TH_31[0]|
||GAM_B_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GAM_B_VEN|
||GAM_B_LUT1|-|-|-|-|-|GAM_B_GAIN_00[10]|GAM_B_GAIN_00[9]|GAM_B_GAIN_00[8]|
|||GAM_B_GAIN_00[7]|GAM_B_GAIN_00[6]|GAM_B_GAIN_00[5]|GAM_B_GAIN_00[4]|GAM_B_GAIN_00[3]|GAM_B_GAIN_00[2]|GAM_B_GAIN_00[1]|GAM_B_GAIN_00[0]|
|||-|-|-|-|-|GAM_B_GAIN_01[10]|GAM_B_GAIN_01[9]|GAM_B_GAIN_01[8]|
|||GAM_B_GAIN_01[7]|GAM_B_GAIN_01[6]|GAM_B_GAIN_01[5]|GAM_B_GAIN_01[4]|GAM_B_GAIN_01[3]|GAM_B_GAIN_01[2]|GAM_B_GAIN_01[1]|GAM_B_GAIN_01[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GAM_B_LUT2|-|-|-|-|-|GAM_B_GAIN_02[10]|GAM_B_GAIN_02[9]|GAM_B_GAIN_02[8]|
|||GAM_B_GAIN_02[7]|GAM_B_GAIN_02[6]|GAM_B_GAIN_02[5]|GAM_B_GAIN_02[4]|GAM_B_GAIN_02[3]|GAM_B_GAIN_02[2]|GAM_B_GAIN_02[1]|GAM_B_GAIN_02[0]|
|||-|-|-|-|-|GAM_B_GAIN_03[10]|GAM_B_GAIN_03[9]|GAM_B_GAIN_03[8]|
|||GAM_B_GAIN_03[7]|GAM_B_GAIN_03[6]|GAM_B_GAIN_03[5]|GAM_B_GAIN_03[4]|GAM_B_GAIN_03[3]|GAM_B_GAIN_03[2]|GAM_B_GAIN_03[1]|GAM_B_GAIN_03[0]|
||GAM_B_LUT3|-|-|-|-|-|GAM_B_GAIN_04[10]|GAM_B_GAIN_04[9]|GAM_B_GAIN_04[8]|
|||GAM_B_GAIN_04[7]|GAM_B_GAIN_04[6]|GAM_B_GAIN_04[5]|GAM_B_GAIN_04[4]|GAM_B_GAIN_04[3]|GAM_B_GAIN_04[2]|GAM_B_GAIN_04[1]|GAM_B_GAIN_04[0]|
|||-|-|-|-|-|GAM_B_GAIN_05[10]|GAM_B_GAIN_05[9]|GAM_B_GAIN_05[8]|
|||GAM_B_GAIN_05[7]|GAM_B_GAIN_05[6]|GAM_B_GAIN_05[5]|GAM_B_GAIN_05[4]|GAM_B_GAIN_05[3]|GAM_B_GAIN_05[2]|GAM_B_GAIN_05[1]|GAM_B_GAIN_05[0]|
||GAM_B_LUT4|-|-|-|-|-|GAM_B_GAIN_06[10]|GAM_B_GAIN_06[9]|GAM_B_GAIN_06[8]|
|||GAM_B_GAIN_06[7]|GAM_B_GAIN_06[6]|GAM_B_GAIN_06[5]|GAM_B_GAIN_06[4]|GAM_B_GAIN_06[3]|GAM_B_GAIN_06[2]|GAM_B_GAIN_06[1]|GAM_B_GAIN_06[0]|
|||-|-|-|-|-|GAM_B_GAIN_07[10]|GAM_B_GAIN_07[9]|GAM_B_GAIN_07[8]|
|||GAM_B_GAIN_07[7]|GAM_B_GAIN_07[6]|GAM_B_GAIN_07[5]|GAM_B_GAIN_07[4]|GAM_B_GAIN_07[3]|GAM_B_GAIN_07[2]|GAM_B_GAIN_07[1]|GAM_B_GAIN_07[0]|
||GAM_B_LUT5|-|-|-|-|-|GAM_B_GAIN_08[10]|GAM_B_GAIN_08[9]|GAM_B_GAIN_08[8]|
|||GAM_B_GAIN_08[7]|GAM_B_GAIN_08[6]|GAM_B_GAIN_08[5]|GAM_B_GAIN_08[4]|GAM_B_GAIN_08[3]|GAM_B_GAIN_08[2]|GAM_B_GAIN_08[1]|GAM_B_GAIN_08[0]|
|||-|-|-|-|-|GAM_B_GAIN_09[10]|GAM_B_GAIN_09[9]|GAM_B_GAIN_09[8]|
|||GAM_B_GAIN_09[7]|GAM_B_GAIN_09[6]|GAM_B_GAIN_09[5]|GAM_B_GAIN_09[4]|GAM_B_GAIN_09[3]|GAM_B_GAIN_09[2]|GAM_B_GAIN_09[1]|GAM_B_GAIN_09[0]|
||GAM_B_LUT6|-|-|-|-|-|GAM_B_GAIN_10[10]|GAM_B_GAIN_10[9]|GAM_B_GAIN_10[8]|
|||GAM_B_GAIN_10[7]|GAM_B_GAIN_10[6]|GAM_B_GAIN_10[5]|GAM_B_GAIN_10[4]|GAM_B_GAIN_10[3]|GAM_B_GAIN_10[2]|GAM_B_GAIN_10[1]|GAM_B_GAIN_10[0]|
|||-|-|-|-|-|GAM_B_GAIN_11[10]|GAM_B_GAIN_11[9]|GAM_B_GAIN_11[8]|
|||GAM_B_GAIN_11[7]|GAM_B_GAIN_11[6]|GAM_B_GAIN_11[5]|GAM_B_GAIN_11[4]|GAM_B_GAIN_11[3]|GAM_B_GAIN_11[2]|GAM_B_GAIN_11[1]|GAM_B_GAIN_11[0]|
||GAM_B_LUT7|-|-|-|-|-|GAM_B_GAIN_12[10]|GAM_B_GAIN_12[9]|GAM_B_GAIN_12[8]|
|||GAM_B_GAIN_12[7]|GAM_B_GAIN_12[6]|GAM_B_GAIN_12[5]|GAM_B_GAIN_12[4]|GAM_B_GAIN_12[3]|GAM_B_GAIN_12[2]|GAM_B_GAIN_12[1]|GAM_B_GAIN_12[0]|
|||-|-|-|-|-|GAM_B_GAIN_13[10]|GAM_B_GAIN_13[9]|GAM_B_GAIN_13[8]|
|||GAM_B_GAIN_13[7]|GAM_B_GAIN_13[6]|GAM_B_GAIN_13[5]|GAM_B_GAIN_13[4]|GAM_B_GAIN_13[3]|GAM_B_GAIN_13[2]|GAM_B_GAIN_13[1]|GAM_B_GAIN_13[0]|
||GAM_B_LUT8|-|-|-|-|-|GAM_B_GAIN_14[10]|GAM_B_GAIN_14[9]|GAM_B_GAIN_14[8]|
|||GAM_B_GAIN_14[7]|GAM_B_GAIN_14[6]|GAM_B_GAIN_14[5]|GAM_B_GAIN_14[4]|GAM_B_GAIN_14[3]|GAM_B_GAIN_14[2]|GAM_B_GAIN_14[1]|GAM_B_GAIN_14[0]|
|||-|-|-|-|-|GAM_B_GAIN_15[10]|GAM_B_GAIN_15[9]|GAM_B_GAIN_15[8]|
|||GAM_B_GAIN_15[7]|GAM_B_GAIN_15[6]|GAM_B_GAIN_15[5]|GAM_B_GAIN_15[4]|GAM_B_GAIN_15[3]|GAM_B_GAIN_15[2]|GAM_B_GAIN_15[1]|GAM_B_GAIN_15[0]|
||GAM_B_LUT9|-|-|-|-|-|GAM_B_GAIN_16[10]|GAM_B_GAIN_16[9]|GAM_B_GAIN_16[8]|
|||GAM_B_GAIN_16[7]|GAM_B_GAIN_16[6]|GAM_B_GAIN_16[5]|GAM_B_GAIN_16[4]|GAM_B_GAIN_16[3]|GAM_B_GAIN_16[2]|GAM_B_GAIN_16[1]|GAM_B_GAIN_16[0]|
|||-|-|-|-|-|GAM_B_GAIN_17[10]|GAM_B_GAIN_17[9]|GAM_B_GAIN_17[8]|
|||GAM_B_GAIN_17[7]|GAM_B_GAIN_17[6]|GAM_B_GAIN_17[5]|GAM_B_GAIN_17[4]|GAM_B_GAIN_17[3]|GAM_B_GAIN_17[2]|GAM_B_GAIN_17[1]|GAM_B_GAIN_17[0]|
||GAM_B_LUT10|-|-|-|-|-|GAM_B_GAIN_18[10]|GAM_B_GAIN_18[9]|GAM_B_GAIN_18[8]|
|||GAM_B_GAIN_18[7]|GAM_B_GAIN_18[6]|GAM_B_GAIN_18[5]|GAM_B_GAIN_18[4]|GAM_B_GAIN_18[3]|GAM_B_GAIN_18[2]|GAM_B_GAIN_18[1]|GAM_B_GAIN_18[0]|
|||-|-|-|-|-|GAM_B_GAIN_19[10]|GAM_B_GAIN_19[9]|GAM_B_GAIN_19[8]|
|||GAM_B_GAIN_19[7]|GAM_B_GAIN_19[6]|GAM_B_GAIN_19[5]|GAM_B_GAIN_19[4]|GAM_B_GAIN_19[3]|GAM_B_GAIN_19[2]|GAM_B_GAIN_19[1]|GAM_B_GAIN_19[0]|
||GAM_B_LUT11|-|-|-|-|-|GAM_B_GAIN_20[10]|GAM_B_GAIN_20[9]|GAM_B_GAIN_20[8]|
|||GAM_B_GAIN_20[7]|GAM_B_GAIN_20[6]|GAM_B_GAIN_20[5]|GAM_B_GAIN_20[4]|GAM_B_GAIN_20[3]|GAM_B_GAIN_20[2]|GAM_B_GAIN_20[1]|GAM_B_GAIN_20[0]|
|||-|-|-|-|-|GAM_B_GAIN_21[10]|GAM_B_GAIN_21[9]|GAM_B_GAIN_21[8]|
|||GAM_B_GAIN_21[7]|GAM_B_GAIN_21[6]|GAM_B_GAIN_21[5]|GAM_B_GAIN_21[4]|GAM_B_GAIN_21[3]|GAM_B_GAIN_21[2]|GAM_B_GAIN_21[1]|GAM_B_GAIN_21[0]|
||GAM_B_LUT12|-|-|-|-|-|GAM_B_GAIN_22[10]|GAM_B_GAIN_22[9]|GAM_B_GAIN_22[8]|
|||GAM_B_GAIN_22[7]|GAM_B_GAIN_22[6]|GAM_B_GAIN_22[5]|GAM_B_GAIN_22[4]|GAM_B_GAIN_22[3]|GAM_B_GAIN_22[2]|GAM_B_GAIN_22[1]|GAM_B_GAIN_22[0]|
|||-|-|-|-|-|GAM_B_GAIN_23[10]|GAM_B_GAIN_23[9]|GAM_B_GAIN_23[8]|
|||GAM_B_GAIN_23[7]|GAM_B_GAIN_23[6]|GAM_B_GAIN_23[5]|GAM_B_GAIN_23[4]|GAM_B_GAIN_23[3]|GAM_B_GAIN_23[2]|GAM_B_GAIN_23[1]|GAM_B_GAIN_23[0]|
||GAM_B_LUT13|-|-|-|-|-|GAM_B_GAIN_24[10]|GAM_B_GAIN_24[9]|GAM_B_GAIN_24[8]|
|||GAM_B_GAIN_24[7]|GAM_B_GAIN_24[6]|GAM_B_GAIN_24[5]|GAM_B_GAIN_24[4]|GAM_B_GAIN_24[3]|GAM_B_GAIN_24[2]|GAM_B_GAIN_24[1]|GAM_B_GAIN_24[0]|
|||-|-|-|-|-|GAM_B_GAIN_25[10]|GAM_B_GAIN_25[9]|GAM_B_GAIN_25[8]|
|||GAM_B_GAIN_25[7]|GAM_B_GAIN_25[6]|GAM_B_GAIN_25[5]|GAM_B_GAIN_25[4]|GAM_B_GAIN_25[3]|GAM_B_GAIN_25[2]|GAM_B_GAIN_25[1]|GAM_B_GAIN_25[0]|
||GAM_B_LUT14|-|-|-|-|-|GAM_B_GAIN_26[10]|GAM_B_GAIN_26[9]|GAM_B_GAIN_26[8]|
|||GAM_B_GAIN_26[7]|GAM_B_GAIN_26[6]|GAM_B_GAIN_26[5]|GAM_B_GAIN_26[4]|GAM_B_GAIN_26[3]|GAM_B_GAIN_26[2]|GAM_B_GAIN_26[1]|GAM_B_GAIN_26[0]|
|||-|-|-|-|-|GAM_B_GAIN_27[10]|GAM_B_GAIN_27[9]|GAM_B_GAIN_27[8]|
|||GAM_B_GAIN_27[7]|GAM_B_GAIN_27[6]|GAM_B_GAIN_27[5]|GAM_B_GAIN_27[4]|GAM_B_GAIN_27[3]|GAM_B_GAIN_27[2]|GAM_B_GAIN_27[1]|GAM_B_GAIN_27[0]|
||GAM_B_LUT15|-|-|-|-|-|GAM_B_GAIN_28[10]|GAM_B_GAIN_28[9]|GAM_B_GAIN_28[8]|
|||GAM_B_GAIN_28[7]|GAM_B_GAIN_28[6]|GAM_B_GAIN_28[5]|GAM_B_GAIN_28[4]|GAM_B_GAIN_28[3]|GAM_B_GAIN_28[2]|GAM_B_GAIN_28[1]|GAM_B_GAIN_28[0]|
|||-|-|-|-|-|GAM_B_GAIN_29[10]|GAM_B_GAIN_29[9]|GAM_B_GAIN_29[8]|
|||GAM_B_GAIN_29[7]|GAM_B_GAIN_29[6]|GAM_B_GAIN_29[5]|GAM_B_GAIN_29[4]|GAM_B_GAIN_29[3]|GAM_B_GAIN_29[2]|GAM_B_GAIN_29[1]|GAM_B_GAIN_29[0]|
||GAM_B_LUT16|-|-|-|-|-|GAM_B_GAIN_30[10]|GAM_B_GAIN_30[9]|GAM_B_GAIN_30[8]|
|||GAM_B_GAIN_30[7]|GAM_B_GAIN_30[6]|GAM_B_GAIN_30[5]|GAM_B_GAIN_30[4]|GAM_B_GAIN_30[3]|GAM_B_GAIN_30[2]|GAM_B_GAIN_30[1]|GAM_B_GAIN_30[0]|
|||-|-|-|-|-|GAM_B_GAIN_31[10]|GAM_B_GAIN_31[9]|GAM_B_GAIN_31[8]|
|||GAM_B_GAIN_31[7]|GAM_B_GAIN_31[6]|GAM_B_GAIN_31[5]|GAM_B_GAIN_31[4]|GAM_B_GAIN_31[3]|GAM_B_GAIN_31[2]|GAM_B_GAIN_31[1]|GAM_B_GAIN_31[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GAM_B_AREA1|-|-|-|-|-|-|-|-|
|||GAM_B_TH_01[7]|GAM_B_TH_01[6]|GAM_B_TH_01[5]|GAM_B_TH_01[4]|GAM_B_TH_01[3]|GAM_B_TH_01[2]|GAM_B_TH_01[1]|GAM_B_TH_01[0]|
|||GAM_B_TH_02[7]|GAM_B_TH_02[6]|GAM_B_TH_02[5]|GAM_B_TH_02[4]|GAM_B_TH_02[3]|GAM_B_TH_02[2]|GAM_B_TH_02[1]|GAM_B_TH_02[0]|
|||GAM_B_TH_03[7]|GAM_B_TH_03[6]|GAM_B_TH_03[5]|GAM_B_TH_03[4]|GAM_B_TH_03[3]|GAM_B_TH_03[2]|GAM_B_TH_03[1]|GAM_B_TH_03[0]|
||GAM_B_AREA2|GAM_B_TH_04[7]|GAM_B_TH_04[6]|GAM_B_TH_04[5]|GAM_B_TH_04[4]|GAM_B_TH_04[3]|GAM_B_TH_04[2]|GAM_B_TH_04[1]|GAM_B_TH_04[0]|
|||GAM_B_TH_05[7]|GAM_B_TH_05[6]|GAM_B_TH_05[5]|GAM_B_TH_05[4]|GAM_B_TH_05[3]|GAM_B_TH_05[2]|GAM_B_TH_05[1]|GAM_B_TH_05[0]|
|||GAM_B_TH_06[7]|GAM_B_TH_06[6]|GAM_B_TH_06[5]|GAM_B_TH_06[4]|GAM_B_TH_06[3]|GAM_B_TH_06[2]|GAM_B_TH_06[1]|GAM_B_TH_06[0]|
|||GAM_B_TH_07[7]|GAM_B_TH_07[6]|GAM_B_TH_07[5]|GAM_B_TH_07[4]|GAM_B_TH_07[3]|GAM_B_TH_07[2]|GAM_B_TH_07[1]|GAM_B_TH_07[0]|
||GAM_B_AREA3|GAM_B_TH_08[7]|GAM_B_TH_08[6]|GAM_B_TH_08[5]|GAM_B_TH_08[4]|GAM_B_TH_08[3]|GAM_B_TH_08[2]|GAM_B_TH_08[1]|GAM_B_TH_08[0]|
|||GAM_B_TH_09[7]|GAM_B_TH_09[6]|GAM_B_TH_09[5]|GAM_B_TH_09[4]|GAM_B_TH_09[3]|GAM_B_TH_09[2]|GAM_B_TH_09[1]|GAM_B_TH_09[0]|
|||GAM_B_TH_10[7]|GAM_B_TH_10[6]|GAM_B_TH_10[5]|GAM_B_TH_10[4]|GAM_B_TH_10[3]|GAM_B_TH_10[2]|GAM_B_TH_10[1]|GAM_B_TH_10[0]|
|||GAM_B_TH_11[7]|GAM_B_TH_11[6]|GAM_B_TH_11[5]|GAM_B_TH_11[4]|GAM_B_TH_11[3]|GAM_B_TH_11[2]|GAM_B_TH_11[1]|GAM_B_TH_11[0]|
||GAM_B_AREA4|GAM_B_TH_12[7]|GAM_B_TH_12[6]|GAM_B_TH_12[5]|GAM_B_TH_12[4]|GAM_B_TH_12[3]|GAM_B_TH_12[2]|GAM_B_TH_12[1]|GAM_B_TH_12[0]|
|||GAM_B_TH_13[7]|GAM_B_TH_13[6]|GAM_B_TH_13[5]|GAM_B_TH_13[4]|GAM_B_TH_13[3]|GAM_B_TH_13[2]|GAM_B_TH_13[1]|GAM_B_TH_13[0]|
|||GAM_B_TH_14[7]|GAM_B_TH_14[6]|GAM_B_TH_14[5]|GAM_B_TH_14[4]|GAM_B_TH_14[3]|GAM_B_TH_14[2]|GAM_B_TH_14[1]|GAM_B_TH_14[0]|
|||GAM_B_TH_15[7]|GAM_B_TH_15[6]|GAM_B_TH_15[5]|GAM_B_TH_15[4]|GAM_B_TH_15[3]|GAM_B_TH_15[2]|GAM_B_TH_15[1]|GAM_B_TH_15[0]|
||GAM_B_AREA5|GAM_B_TH_16[7]|GAM_B_TH_16[6]|GAM_B_TH_16[5]|GAM_B_TH_16[4]|GAM_B_TH_16[3]|GAM_B_TH_16[2]|GAM_B_TH_16[1]|GAM_B_TH_16[0]|
|||GAM_B_TH_17[7]|GAM_B_TH_17[6]|GAM_B_TH_17[5]|GAM_B_TH_17[4]|GAM_B_TH_17[3]|GAM_B_TH_17[2]|GAM_B_TH_17[1]|GAM_B_TH_17[0]|
|||GAM_B_TH_18[7]|GAM_B_TH_18[6]|GAM_B_TH_18[5]|GAM_B_TH_18[4]|GAM_B_TH_18[3]|GAM_B_TH_18[2]|GAM_B_TH_18[1]|GAM_B_TH_18[0]|
|||GAM_B_TH_19[7]|GAM_B_TH_19[6]|GAM_B_TH_19[5]|GAM_B_TH_19[4]|GAM_B_TH_19[3]|GAM_B_TH_19[2]|GAM_B_TH_19[1]|GAM_B_TH_19[0]|
||GAM_B_AREA6|GAM_B_TH_20[7]|GAM_B_TH_20[6]|GAM_B_TH_20[5]|GAM_B_TH_20[4]|GAM_B_TH_20[3]|GAM_B_TH_20[2]|GAM_B_TH_20[1]|GAM_B_TH_20[0]|
|||GAM_B_TH_21[7]|GAM_B_TH_21[6]|GAM_B_TH_21[5]|GAM_B_TH_21[4]|GAM_B_TH_21[3]|GAM_B_TH_21[2]|GAM_B_TH_21[1]|GAM_B_TH_21[0]|
|||GAM_B_TH_22[7]|GAM_B_TH_22[6]|GAM_B_TH_22[5]|GAM_B_TH_22[4]|GAM_B_TH_22[3]|GAM_B_TH_22[2]|GAM_B_TH_22[1]|GAM_B_TH_22[0]|
|||GAM_B_TH_23[7]|GAM_B_TH_23[6]|GAM_B_TH_23[5]|GAM_B_TH_23[4]|GAM_B_TH_23[3]|GAM_B_TH_23[2]|GAM_B_TH_23[1]|GAM_B_TH_23[0]|
||GAM_B_AREA7|GAM_B_TH_24[7]|GAM_B_TH_24[6]|GAM_B_TH_24[5]|GAM_B_TH_24[4]|GAM_B_TH_24[3]|GAM_B_TH_24[2]|GAM_B_TH_24[1]|GAM_B_TH_24[0]|
|||GAM_B_TH_25[7]|GAM_B_TH_25[6]|GAM_B_TH_25[5]|GAM_B_TH_25[4]|GAM_B_TH_25[3]|GAM_B_TH_25[2]|GAM_B_TH_25[1]|GAM_B_TH_25[0]|
|||GAM_B_TH_26[7]|GAM_B_TH_26[6]|GAM_B_TH_26[5]|GAM_B_TH_26[4]|GAM_B_TH_26[3]|GAM_B_TH_26[2]|GAM_B_TH_26[1]|GAM_B_TH_26[0]|
|||GAM_B_TH_27[7]|GAM_B_TH_27[6]|GAM_B_TH_27[5]|GAM_B_TH_27[4]|GAM_B_TH_27[3]|GAM_B_TH_27[2]|GAM_B_TH_27[1]|GAM_B_TH_27[0]|
||GAM_B_AREA8|GAM_B_TH_28[7]|GAM_B_TH_28[6]|GAM_B_TH_28[5]|GAM_B_TH_28[4]|GAM_B_TH_28[3]|GAM_B_TH_28[2]|GAM_B_TH_28[1]|GAM_B_TH_28[0]|
|||GAM_B_TH_29[7]|GAM_B_TH_29[6]|GAM_B_TH_29[5]|GAM_B_TH_29[4]|GAM_B_TH_29[3]|GAM_B_TH_29[2]|GAM_B_TH_29[1]|GAM_B_TH_29[0]|
|||GAM_B_TH_30[7]|GAM_B_TH_30[6]|GAM_B_TH_30[5]|GAM_B_TH_30[4]|GAM_B_TH_30[3]|GAM_B_TH_30[2]|GAM_B_TH_30[1]|GAM_B_TH_30[0]|
|||GAM_B_TH_31[7]|GAM_B_TH_31[6]|GAM_B_TH_31[5]|GAM_B_TH_31[4]|GAM_B_TH_31[3]|GAM_B_TH_31[2]|GAM_B_TH_31[1]|GAM_B_TH_31[0]|
||GAM_R_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GAM_R_VEN|
||GAM_R_LUT1|-|-|-|-|-|GAM_R_GAIN_00[10]|GAM_R_GAIN_00[9]|GAM_R_GAIN_00[8]|
|||GAM_R_GAIN_00[7]|GAM_R_GAIN_00[6]|GAM_R_GAIN_00[5]|GAM_R_GAIN_00[4]|GAM_R_GAIN_00[3]|GAM_R_GAIN_00[2]|GAM_R_GAIN_00[1]|GAM_R_GAIN_00[0]|
|||-|-|-|-|-|GAM_R_GAIN_01[10]|GAM_R_GAIN_01[9]|GAM_R_GAIN_01[8]|
|||GAM_R_GAIN_01[7]|GAM_R_GAIN_01[6]|GAM_R_GAIN_01[5]|GAM_R_GAIN_01[4]|GAM_R_GAIN_01[3]|GAM_R_GAIN_01[2]|GAM_R_GAIN_01[1]|GAM_R_GAIN_01[0]|
||GAM_R_LUT2|-|-|-|-|-|GAM_R_GAIN_02[10]|GAM_R_GAIN_02[9]|GAM_R_GAIN_02[8]|
|||GAM_R_GAIN_02[7]|GAM_R_GAIN_02[6]|GAM_R_GAIN_02[5]|GAM_R_GAIN_02[4]|GAM_R_GAIN_02[3]|GAM_R_GAIN_02[2]|GAM_R_GAIN_02[1]|GAM_R_GAIN_02[0]|
|||-|-|-|-|-|GAM_R_GAIN_03[10]|GAM_R_GAIN_03[9]|GAM_R_GAIN_03[8]|
|||GAM_R_GAIN_03[7]|GAM_R_GAIN_03[6]|GAM_R_GAIN_03[5]|GAM_R_GAIN_03[4]|GAM_R_GAIN_03[3]|GAM_R_GAIN_03[2]|GAM_R_GAIN_03[1]|GAM_R_GAIN_03[0]|
||GAM_R_LUT3|-|-|-|-|-|GAM_R_GAIN_04[10]|GAM_R_GAIN_04[9]|GAM_R_GAIN_04[8]|
|||GAM_R_GAIN_04[7]|GAM_R_GAIN_04[6]|GAM_R_GAIN_04[5]|GAM_R_GAIN_04[4]|GAM_R_GAIN_04[3]|GAM_R_GAIN_04[2]|GAM_R_GAIN_04[1]|GAM_R_GAIN_04[0]|
|||-|-|-|-|-|GAM_R_GAIN_05[10]|GAM_R_GAIN_05[9]|GAM_R_GAIN_05[8]|
|||GAM_R_GAIN_05[7]|GAM_R_GAIN_05[6]|GAM_R_GAIN_05[5]|GAM_R_GAIN_05[4]|GAM_R_GAIN_05[3]|GAM_R_GAIN_05[2]|GAM_R_GAIN_05[1]|GAM_R_GAIN_05[0]|
||GAM_R_LUT4|-|-|-|-|-|GAM_R_GAIN_06[10]|GAM_R_GAIN_06[9]|GAM_R_GAIN_06[8]|
|||GAM_R_GAIN_06[7]|GAM_R_GAIN_06[6]|GAM_R_GAIN_06[5]|GAM_R_GAIN_06[4]|GAM_R_GAIN_06[3]|GAM_R_GAIN_06[2]|GAM_R_GAIN_06[1]|GAM_R_GAIN_06[0]|
|||-|-|-|-|-|GAM_R_GAIN_07[10]|GAM_R_GAIN_07[9]|GAM_R_GAIN_07[8]|
|||GAM_R_GAIN_07[7]|GAM_R_GAIN_07[6]|GAM_R_GAIN_07[5]|GAM_R_GAIN_07[4]|GAM_R_GAIN_07[3]|GAM_R_GAIN_07[2]|GAM_R_GAIN_07[1]|GAM_R_GAIN_07[0]|
||GAM_R_LUT5|-|-|-|-|-|GAM_R_GAIN_08[10]|GAM_R_GAIN_08[9]|GAM_R_GAIN_08[8]|
|||GAM_R_GAIN_08[7]|GAM_R_GAIN_08[6]|GAM_R_GAIN_08[5]|GAM_R_GAIN_08[4]|GAM_R_GAIN_08[3]|GAM_R_GAIN_08[2]|GAM_R_GAIN_08[1]|GAM_R_GAIN_08[0]|
|||-|-|-|-|-|GAM_R_GAIN_09[10]|GAM_R_GAIN_09[9]|GAM_R_GAIN_09[8]|
|||GAM_R_GAIN_09[7]|GAM_R_GAIN_09[6]|GAM_R_GAIN_09[5]|GAM_R_GAIN_09[4]|GAM_R_GAIN_09[3]|GAM_R_GAIN_09[2]|GAM_R_GAIN_09[1]|GAM_R_GAIN_09[0]|
||GAM_R_LUT6|-|-|-|-|-|GAM_R_GAIN_10[10]|GAM_R_GAIN_10[9]|GAM_R_GAIN_10[8]|
|||GAM_R_GAIN_10[7]|GAM_R_GAIN_10[6]|GAM_R_GAIN_10[5]|GAM_R_GAIN_10[4]|GAM_R_GAIN_10[3]|GAM_R_GAIN_10[2]|GAM_R_GAIN_10[1]|GAM_R_GAIN_10[0]|
|||-|-|-|-|-|GAM_R_GAIN_11[10]|GAM_R_GAIN_11[9]|GAM_R_GAIN_11[8]|
|||GAM_R_GAIN_11[7]|GAM_R_GAIN_11[6]|GAM_R_GAIN_11[5]|GAM_R_GAIN_11[4]|GAM_R_GAIN_11[3]|GAM_R_GAIN_11[2]|GAM_R_GAIN_11[1]|GAM_R_GAIN_11[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GAM_R_LUT7|-|-|-|-|-|GAM_R_GAIN_12[10]|GAM_R_GAIN_12[9]|GAM_R_GAIN_12[8]|
|||GAM_R_GAIN_12[7]|GAM_R_GAIN_12[6]|GAM_R_GAIN_12[5]|GAM_R_GAIN_12[4]|GAM_R_GAIN_12[3]|GAM_R_GAIN_12[2]|GAM_R_GAIN_12[1]|GAM_R_GAIN_12[0]|
|||-|-|-|-|-|GAM_R_GAIN_13[10]|GAM_R_GAIN_13[9]|GAM_R_GAIN_13[8]|
|||GAM_R_GAIN_13[7]|GAM_R_GAIN_13[6]|GAM_R_GAIN_13[5]|GAM_R_GAIN_13[4]|GAM_R_GAIN_13[3]|GAM_R_GAIN_13[2]|GAM_R_GAIN_13[1]|GAM_R_GAIN_13[0]|
||GAM_R_LUT8|-|-|-|-|-|GAM_R_GAIN_14[10]|GAM_R_GAIN_14[9]|GAM_R_GAIN_14[8]|
|||GAM_R_GAIN_14[7]|GAM_R_GAIN_14[6]|GAM_R_GAIN_14[5]|GAM_R_GAIN_14[4]|GAM_R_GAIN_14[3]|GAM_R_GAIN_14[2]|GAM_R_GAIN_14[1]|GAM_R_GAIN_14[0]|
|||-|-|-|-|-|GAM_R_GAIN_15[10]|GAM_R_GAIN_15[9]|GAM_R_GAIN_15[8]|
|||GAM_R_GAIN_15[7]|GAM_R_GAIN_15[6]|GAM_R_GAIN_15[5]|GAM_R_GAIN_15[4]|GAM_R_GAIN_15[3]|GAM_R_GAIN_15[2]|GAM_R_GAIN_15[1]|GAM_R_GAIN_15[0]|
||GAM_R_LUT9|-|-|-|-|-|GAM_R_GAIN_16[10]|GAM_R_GAIN_16[9]|GAM_R_GAIN_16[8]|
|||GAM_R_GAIN_16[7]|GAM_R_GAIN_16[6]|GAM_R_GAIN_16[5]|GAM_R_GAIN_16[4]|GAM_R_GAIN_16[3]|GAM_R_GAIN_16[2]|GAM_R_GAIN_16[1]|GAM_R_GAIN_16[0]|
|||-|-|-|-|-|GAM_R_GAIN_17[10]|GAM_R_GAIN_17[9]|GAM_R_GAIN_17[8]|
|||GAM_R_GAIN_17[7]|GAM_R_GAIN_17[6]|GAM_R_GAIN_17[5]|GAM_R_GAIN_17[4]|GAM_R_GAIN_17[3]|GAM_R_GAIN_17[2]|GAM_R_GAIN_17[1]|GAM_R_GAIN_17[0]|
||GAM_R_LUT10|-|-|-|-|-|GAM_R_GAIN_18[10]|GAM_R_GAIN_18[9]|GAM_R_GAIN_18[8]|
|||GAM_R_GAIN_18[7]|GAM_R_GAIN_18[6]|GAM_R_GAIN_18[5]|GAM_R_GAIN_18[4]|GAM_R_GAIN_18[3]|GAM_R_GAIN_18[2]|GAM_R_GAIN_18[1]|GAM_R_GAIN_18[0]|
|||-|-|-|-|-|GAM_R_GAIN_19[10]|GAM_R_GAIN_19[9]|GAM_R_GAIN_19[8]|
|||GAM_R_GAIN_19[7]|GAM_R_GAIN_19[6]|GAM_R_GAIN_19[5]|GAM_R_GAIN_19[4]|GAM_R_GAIN_19[3]|GAM_R_GAIN_19[2]|GAM_R_GAIN_19[1]|GAM_R_GAIN_19[0]|
||GAM_R_LUT11|-|-|-|-|-|GAM_R_GAIN_20[10]|GAM_R_GAIN_20[9]|GAM_R_GAIN_20[8]|
|||GAM_R_GAIN_20[7]|GAM_R_GAIN_20[6]|GAM_R_GAIN_20[5]|GAM_R_GAIN_20[4]|GAM_R_GAIN_20[3]|GAM_R_GAIN_20[2]|GAM_R_GAIN_20[1]|GAM_R_GAIN_20[0]|
|||-|-|-|-|-|GAM_R_GAIN_21[10]|GAM_R_GAIN_21[9]|GAM_R_GAIN_21[8]|
|||GAM_R_GAIN_21[7]|GAM_R_GAIN_21[6]|GAM_R_GAIN_21[5]|GAM_R_GAIN_21[4]|GAM_R_GAIN_21[3]|GAM_R_GAIN_21[2]|GAM_R_GAIN_21[1]|GAM_R_GAIN_21[0]|
||GAM_R_LUT12|-|-|-|-|-|GAM_R_GAIN_22[10]|GAM_R_GAIN_22[9]|GAM_R_GAIN_22[8]|
|||GAM_R_GAIN_22[7]|GAM_R_GAIN_22[6]|GAM_R_GAIN_22[5]|GAM_R_GAIN_22[4]|GAM_R_GAIN_22[3]|GAM_R_GAIN_22[2]|GAM_R_GAIN_22[1]|GAM_R_GAIN_22[0]|
|||-|-|-|-|-|GAM_R_GAIN_23[10]|GAM_R_GAIN_23[9]|GAM_R_GAIN_23[8]|
|||GAM_R_GAIN_23[7]|GAM_R_GAIN_23[6]|GAM_R_GAIN_23[5]|GAM_R_GAIN_23[4]|GAM_R_GAIN_23[3]|GAM_R_GAIN_23[2]|GAM_R_GAIN_23[1]|GAM_R_GAIN_23[0]|
||GAM_R_LUT13|-|-|-|-|-|GAM_R_GAIN_24[10]|GAM_R_GAIN_24[9]|GAM_R_GAIN_24[8]|
|||GAM_R_GAIN_24[7]|GAM_R_GAIN_24[6]|GAM_R_GAIN_24[5]|GAM_R_GAIN_24[4]|GAM_R_GAIN_24[3]|GAM_R_GAIN_24[2]|GAM_R_GAIN_24[1]|GAM_R_GAIN_24[0]|
|||-|-|-|-|-|GAM_R_GAIN_25[10]|GAM_R_GAIN_25[9]|GAM_R_GAIN_25[8]|
|||GAM_R_GAIN_25[7]|GAM_R_GAIN_25[6]|GAM_R_GAIN_25[5]|GAM_R_GAIN_25[4]|GAM_R_GAIN_25[3]|GAM_R_GAIN_25[2]|GAM_R_GAIN_25[1]|GAM_R_GAIN_25[0]|
||GAM_R_LUT14|-|-|-|-|-|GAM_R_GAIN_26[10]|GAM_R_GAIN_26[9]|GAM_R_GAIN_26[8]|
|||GAM_R_GAIN_26[7]|GAM_R_GAIN_26[6]|GAM_R_GAIN_26[5]|GAM_R_GAIN_26[4]|GAM_R_GAIN_26[3]|GAM_R_GAIN_26[2]|GAM_R_GAIN_26[1]|GAM_R_GAIN_26[0]|
|||-|-|-|-|-|GAM_R_GAIN_27[10]|GAM_R_GAIN_27[9]|GAM_R_GAIN_27[8]|
|||GAM_R_GAIN_27[7]|GAM_R_GAIN_27[6]|GAM_R_GAIN_27[5]|GAM_R_GAIN_27[4]|GAM_R_GAIN_27[3]|GAM_R_GAIN_27[2]|GAM_R_GAIN_27[1]|GAM_R_GAIN_27[0]|
||GAM_R_LUT15|-|-|-|-|-|GAM_R_GAIN_28[10]|GAM_R_GAIN_28[9]|GAM_R_GAIN_28[8]|
|||GAM_R_GAIN_28[7]|GAM_R_GAIN_28[6]|GAM_R_GAIN_28[5]|GAM_R_GAIN_28[4]|GAM_R_GAIN_28[3]|GAM_R_GAIN_28[2]|GAM_R_GAIN_28[1]|GAM_R_GAIN_28[0]|
|||-|-|-|-|-|GAM_R_GAIN_29[10]|GAM_R_GAIN_29[9]|GAM_R_GAIN_29[8]|
|||GAM_R_GAIN_29[7]|GAM_R_GAIN_29[6]|GAM_R_GAIN_29[5]|GAM_R_GAIN_29[4]|GAM_R_GAIN_29[3]|GAM_R_GAIN_29[2]|GAM_R_GAIN_29[1]|GAM_R_GAIN_29[0]|
||GAM_R_LUT16|-|-|-|-|-|GAM_R_GAIN_30[10]|GAM_R_GAIN_30[9]|GAM_R_GAIN_30[8]|
|||GAM_R_GAIN_30[7]|GAM_R_GAIN_30[6]|GAM_R_GAIN_30[5]|GAM_R_GAIN_30[4]|GAM_R_GAIN_30[3]|GAM_R_GAIN_30[2]|GAM_R_GAIN_30[1]|GAM_R_GAIN_30[0]|
|||-|-|-|-|-|GAM_R_GAIN_31[10]|GAM_R_GAIN_31[9]|GAM_R_GAIN_31[8]|
|||GAM_R_GAIN_31[7]|GAM_R_GAIN_31[6]|GAM_R_GAIN_31[5]|GAM_R_GAIN_31[4]|GAM_R_GAIN_31[3]|GAM_R_GAIN_31[2]|GAM_R_GAIN_31[1]|GAM_R_GAIN_31[0]|
||GAM_R_AREA1|-|-|-|-|-|-|-|-|
|||GAM_R_TH_01[7]|GAM_R_TH_01[6]|GAM_R_TH_01[5]|GAM_R_TH_01[4]|GAM_R_TH_01[3]|GAM_R_TH_01[2]|GAM_R_TH_01[1]|GAM_R_TH_01[0]|
|||GAM_R_TH_02[7]|GAM_R_TH_02[6]|GAM_R_TH_02[5]|GAM_R_TH_02[4]|GAM_R_TH_02[3]|GAM_R_TH_02[2]|GAM_R_TH_02[1]|GAM_R_TH_02[0]|
|||GAM_R_TH_03[7]|GAM_R_TH_03[6]|GAM_R_TH_03[5]|GAM_R_TH_03[4]|GAM_R_TH_03[3]|GAM_R_TH_03[2]|GAM_R_TH_03[1]|GAM_R_TH_03[0]|
||GAM_R_AREA2|GAM_R_TH_04[7]|GAM_R_TH_04[6]|GAM_R_TH_04[5]|GAM_R_TH_04[4]|GAM_R_TH_04[3]|GAM_R_TH_04[2]|GAM_R_TH_04[1]|GAM_R_TH_04[0]|
|||GAM_R_TH_05[7]|GAM_R_TH_05[6]|GAM_R_TH_05[5]|GAM_R_TH_05[4]|GAM_R_TH_05[3]|GAM_R_TH_05[2]|GAM_R_TH_05[1]|GAM_R_TH_05[0]|
|||GAM_R_TH_06[7]|GAM_R_TH_06[6]|GAM_R_TH_06[5]|GAM_R_TH_06[4]|GAM_R_TH_06[3]|GAM_R_TH_06[2]|GAM_R_TH_06[1]|GAM_R_TH_06[0]|
|||GAM_R_TH_07[7]|GAM_R_TH_07[6]|GAM_R_TH_07[5]|GAM_R_TH_07[4]|GAM_R_TH_07[3]|GAM_R_TH_07[2]|GAM_R_TH_07[1]|GAM_R_TH_07[0]|
||GAM_R_AREA3|GAM_R_TH_08[7]|GAM_R_TH_08[6]|GAM_R_TH_08[5]|GAM_R_TH_08[4]|GAM_R_TH_08[3]|GAM_R_TH_08[2]|GAM_R_TH_08[1]|GAM_R_TH_08[0]|
|||GAM_R_TH_09[7]|GAM_R_TH_09[6]|GAM_R_TH_09[5]|GAM_R_TH_09[4]|GAM_R_TH_09[3]|GAM_R_TH_09[2]|GAM_R_TH_09[1]|GAM_R_TH_09[0]|
|||GAM_R_TH_10[7]|GAM_R_TH_10[6]|GAM_R_TH_10[5]|GAM_R_TH_10[4]|GAM_R_TH_10[3]|GAM_R_TH_10[2]|GAM_R_TH_10[1]|GAM_R_TH_10[0]|
|||GAM_R_TH_11[7]|GAM_R_TH_11[6]|GAM_R_TH_11[5]|GAM_R_TH_11[4]|GAM_R_TH_11[3]|GAM_R_TH_11[2]|GAM_R_TH_11[1]|GAM_R_TH_11[0]|
||GAM_R_AREA4|GAM_R_TH_12[7]|GAM_R_TH_12[6]|GAM_R_TH_12[5]|GAM_R_TH_12[4]|GAM_R_TH_12[3]|GAM_R_TH_12[2]|GAM_R_TH_12[1]|GAM_R_TH_12[0]|
|||GAM_R_TH_13[7]|GAM_R_TH_13[6]|GAM_R_TH_13[5]|GAM_R_TH_13[4]|GAM_R_TH_13[3]|GAM_R_TH_13[2]|GAM_R_TH_13[1]|GAM_R_TH_13[0]|
|||GAM_R_TH_14[7]|GAM_R_TH_14[6]|GAM_R_TH_14[5]|GAM_R_TH_14[4]|GAM_R_TH_14[3]|GAM_R_TH_14[2]|GAM_R_TH_14[1]|GAM_R_TH_14[0]|
|||GAM_R_TH_15[7]|GAM_R_TH_15[6]|GAM_R_TH_15[5]|GAM_R_TH_15[4]|GAM_R_TH_15[3]|GAM_R_TH_15[2]|GAM_R_TH_15[1]|GAM_R_TH_15[0]|
||GAM_R_AREA5|GAM_R_TH_16[7]|GAM_R_TH_16[6]|GAM_R_TH_16[5]|GAM_R_TH_16[4]|GAM_R_TH_16[3]|GAM_R_TH_16[2]|GAM_R_TH_16[1]|GAM_R_TH_16[0]|
|||GAM_R_TH_17[7]|GAM_R_TH_17[6]|GAM_R_TH_17[5]|GAM_R_TH_17[4]|GAM_R_TH_17[3]|GAM_R_TH_17[2]|GAM_R_TH_17[1]|GAM_R_TH_17[0]|
|||GAM_R_TH_18[7]|GAM_R_TH_18[6]|GAM_R_TH_18[5]|GAM_R_TH_18[4]|GAM_R_TH_18[3]|GAM_R_TH_18[2]|GAM_R_TH_18[1]|GAM_R_TH_18[0]|
|||GAM_R_TH_19[7]|GAM_R_TH_19[6]|GAM_R_TH_19[5]|GAM_R_TH_19[4]|GAM_R_TH_19[3]|GAM_R_TH_19[2]|GAM_R_TH_19[1]|GAM_R_TH_19[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|GAM_R_AREA6|GAM_R_TH_20[7]|GAM_R_TH_20[6]|GAM_R_TH_20[5]|GAM_R_TH_20[4]|GAM_R_TH_20[3]|GAM_R_TH_20[2]|GAM_R_TH_20[1]|GAM_R_TH_20[0]|
|||GAM_R_TH_21[7]|GAM_R_TH_21[6]|GAM_R_TH_21[5]|GAM_R_TH_21[4]|GAM_R_TH_21[3]|GAM_R_TH_21[2]|GAM_R_TH_21[1]|GAM_R_TH_21[0]|
|||GAM_R_TH_22[7]|GAM_R_TH_22[6]|GAM_R_TH_22[5]|GAM_R_TH_22[4]|GAM_R_TH_22[3]|GAM_R_TH_22[2]|GAM_R_TH_22[1]|GAM_R_TH_22[0]|
|||GAM_R_TH_23[7]|GAM_R_TH_23[6]|GAM_R_TH_23[5]|GAM_R_TH_23[4]|GAM_R_TH_23[3]|GAM_R_TH_23[2]|GAM_R_TH_23[1]|GAM_R_TH_23[0]|
||GAM_R_AREA7|GAM_R_TH_24[7]|GAM_R_TH_24[6]|GAM_R_TH_24[5]|GAM_R_TH_24[4]|GAM_R_TH_24[3]|GAM_R_TH_24[2]|GAM_R_TH_24[1]|GAM_R_TH_24[0]|
|||GAM_R_TH_25[7]|GAM_R_TH_25[6]|GAM_R_TH_25[5]|GAM_R_TH_25[4]|GAM_R_TH_25[3]|GAM_R_TH_25[2]|GAM_R_TH_25[1]|GAM_R_TH_25[0]|
|||GAM_R_TH_26[7]|GAM_R_TH_26[6]|GAM_R_TH_26[5]|GAM_R_TH_26[4]|GAM_R_TH_26[3]|GAM_R_TH_26[2]|GAM_R_TH_26[1]|GAM_R_TH_26[0]|
|||GAM_R_TH_27[7]|GAM_R_TH_27[6]|GAM_R_TH_27[5]|GAM_R_TH_27[4]|GAM_R_TH_27[3]|GAM_R_TH_27[2]|GAM_R_TH_27[1]|GAM_R_TH_27[0]|
||GAM_R_AREA8|GAM_R_TH_28[7]|GAM_R_TH_28[6]|GAM_R_TH_28[5]|GAM_R_TH_28[4]|GAM_R_TH_28[3]|GAM_R_TH_28[2]|GAM_R_TH_28[1]|GAM_R_TH_28[0]|
|||GAM_R_TH_29[7]|GAM_R_TH_29[6]|GAM_R_TH_29[5]|GAM_R_TH_29[4]|GAM_R_TH_29[3]|GAM_R_TH_29[2]|GAM_R_TH_29[1]|GAM_R_TH_29[0]|
|||GAM_R_TH_30[7]|GAM_R_TH_30[6]|GAM_R_TH_30[5]|GAM_R_TH_30[4]|GAM_R_TH_30[3]|GAM_R_TH_30[2]|GAM_R_TH_30[1]|GAM_R_TH_30[0]|
|||GAM_R_TH_31[7]|GAM_R_TH_31[6]|GAM_R_TH_31[5]|GAM_R_TH_31[4]|GAM_R_TH_31[3]|GAM_R_TH_31[2]|GAM_R_TH_31[1]|GAM_R_TH_31[0]|
||TCON_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TCON_VEN|
||TCON_TIM|-|-|-|-|-|TCON_HALF[10]|TCON_HALF[9]|TCON_HALF[8]|
|||TCON_HALF[7]|TCON_HALF[6]|TCON_HALF[5]|TCON_HALF[4]|TCON_HALF[3]|TCON_HALF[2]|TCON_HALF[1]|TCON_HALF[0]|
|||-|-|-|-|-|TCON_OFFSET<br>[10]|TCON_OFFSET[9]|TCON_OFFSET[8]|
|||TCON_OFFSET[7]|TCON_OFFSET[6]|TCON_OFFSET[5]|TCON_OFFSET[4]|TCON_OFFSET[3]|TCON_OFFSET[2]|TCON_OFFSET[1]|TCON_OFFSET[0]|
||TCON_TIM_STVA1|-|-|-|-|-|TCON_STVA_VS<br>[10]|TCON_STVA_VS<br>[9]|TCON_STVA_VS<br>[8]|
|||TCON_STVA_VS<br>[7]|TCON_STVA_VS<br>[6]|TCON_STVA_VS<br>[5]|TCON_STVA_VS<br>[4]|TCON_STVA_VS<br>[3]|TCON_STVA_VS<br>[2]|TCON_STVA_VS<br>[1]|TCON_STVA_VS<br>[0]|
|||-|-|-|-|-|TCON_STVA_VW[10]|TCON_STVA_VW[9]|TCON_STVA_VW[8]|
|||TCON_STVA_VW[7]|TCON_STVA_VW[6]|TCON_STVA_VW[5]|TCON_STVA_VW[4]|TCON_STVA_VW[3]|TCON_STVA_VW[2]|TCON_STVA_VW[1]|TCON_STVA_VW[0]|
||TCON_TIM_STVA2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|TCON_STVA_INV|-|TCON_STVA_<br>SEL[2]|TCON_STVA_<br>SEL[1]|TCON_STVA_<br>SEL[0]|
||TCON_TIM_STVB1|-|-|-|-|-|TCON_STVB_VS<br>[10]|TCON_STVB_VS<br>[9]|TCON_STVB_VS<br>[8]|
|||TCON_STVB_VS<br>[7]|TCON_STVB_VS<br>[6]|TCON_STVB_VS<br>[5]|TCON_STVB_VS<br>[4]|TCON_STVB_VS<br>[3]|TCON_STVB_VS<br>[2]|TCON_STVB_VS<br>[1]|TCON_STVB_VS<br>[0]|
|||-|-|-|-|-|TCON_STVB_VW[10]|TCON_STVB_VW[9]|TCON_STVB_VW[8]|
|||TCON_STVB_VW[7]|TCON_STVB_VW[6]|TCON_STVB_VW[5]|TCON_STVB_VW[4]|TCON_STVB_VW[3]|TCON_STVB_VW[2]|TCON_STVB_VW[1]|TCON_STVB_VW[0]|
||TCON_TIM_STVB2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|TCON_STVB_INV|-|TCON_STVB_<br>SEL[2]|TCON_STVB_<br>SEL[1]|TCON_STVB_<br>SEL[0]|
||TCON_TIM_STH1|-|-|-|-|-|TCON_STH_HS<br>[10]|TCON_STH_HS[9]|TCON_STH_HS[8]|
|||TCON_STH_HS[7]|TCON_STH_HS[6]|TCON_STH_HS[5]|TCON_STH_HS[4]|TCON_STH_HS[3]|TCON_STH_HS[2]|TCON_STH_HS[1]|TCON_STH_HS[0]|
|||-|-|-|-|-|TCON_STH_HW<br>[10]|TCON_STH_HW<br>[9]|TCON_STH_HW<br>[8]|
|||TCON_STH_HW<br>[7]|TCON_STH_HW<br>[6]|TCON_STH_HW<br>[5]|TCON_STH_HW<br>[4]|TCON_STH_HW<br>[3]|TCON_STH_HW<br>[2]|TCON_STH_HW<br>[1]|TCON_STH_HW<br>[0]|
||TCON_TIM_STH2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TCON_STH_HS_SEL|
|||-|-|-|TCON_STH_INV|-|TCON_STH_SEL<br>[2]|TCON_STH_SEL<br>[1]|TCON_STH_SEL<br>[0]|
||TCON_TIM_STB1|-|-|-|-|-|TCON_STB_HS<br>[10]|TCON_STB_HS[9]|TCON_STB_HS[8]|
|||TCON_STB_HS[7]|TCON_STB_HS[6]|TCON_STB_HS[5]|TCON_STB_HS[4]|TCON_STB_HS[3]|TCON_STB_HS[2]|TCON_STB_HS[1]|TCON_STB_HS[0]|
|||-|-|-|-|-|TCON_STB_HW<br>[10]|TCON_STB_HW<br>[9]|TCON_STB_HW<br>[8]|
|||TCON_STB_HW<br>[7]|TCON_STB_HW<br>[6]|TCON_STB_HW<br>[5]|TCON_STB_HW<br>[4]|TCON_STB_HW<br>[3]|TCON_STB_HW<br>[2]|TCON_STB_HW<br>[1]|TCON_STB_HW<br>[0]|
||TCON_TIM_STB2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TCON_STB_HS_SEL|
|||-|-|-|TCON_STB_INV|-|TCON_STB_SEL<br>[2]|TCON_STB_SEL<br>[1]|TCON_STB_SEL<br>[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|TCON_TIM_CPV1|-|-|-|-|-|TCON_CPV_HS<br>[10]|TCON_CPV_HS[9]|TCON_CPV_HS[8]|
|||TCON_CPV_HS[7]|TCON_CPV_HS[6]|TCON_CPV_HS[5]|TCON_CPV_HS[4]|TCON_CPV_HS[3]|TCON_CPV_HS[2]|TCON_CPV_HS[1]|TCON_CPV_HS[0]|
|||-|-|-|-|-|TCON_CPV_HW<br>[10]|TCON_CPV_HW<br>[9]|TCON_CPV_HW<br>[8]|
|||TCON_CPV_HW<br>[7]|TCON_CPV_HW<br>[6]|TCON_CPV_HW<br>[5]|TCON_CPV_HW<br>[4]|TCON_CPV_HW<br>[3]|TCON_CPV_HW<br>[2]|TCON_CPV_HW<br>[1]|TCON_CPV_HW<br>[0]|
||TCON_TIM_CPV2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TCON_CPV_HS_SEL|
|||-|-|-|TCON_CPV_INV|-|TCON_CPV_SEL<br>[2]|TCON_CPV_SEL<br>[1]|TCON_CPV_SEL<br>[0]|
||TCON_TIM_POLA1|-|-|-|-|-|TCON_POLA_HS[10]|TCON_POLA_HS[9]|TCON_POLA_HS[8]|
|||TCON_POLA_HS[7]|TCON_POLA_HS[6]|TCON_POLA_HS[5]|TCON_POLA_HS[4]|TCON_POLA_HS[3]|TCON_POLA_HS[2]|TCON_POLA_HS[1]|TCON_POLA_HS[0]|
|||-|-|-|-|-|TCON_POLA_<br>HW[10]|TCON_POLA_<br>HW[9]|TCON_POLA_<br>HW[8]|
|||TCON_POLA_<br>HW[7]|TCON_POLA_<br>HW[6]|TCON_POLA_<br>HW[5]|TCON_POLA_<br>HW[4]|TCON_POLA_<br>HW[3]|TCON_POLA_<br>HW[2]|TCON_POLA_<br>HW[1]|TCON_POLA_<br>HW[0]|
||TCON_TIM_POLA2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|TCON_POLA_MD[1]|TCON_POLA_MD[0]|-|-|-|TCON_POLA_HS_<br>SEL|
|||-|-|-|TCON_POLA_<br>INV|-|TCON_POLA_<br>SEL[2]|TCON_POLA_<br>SEL[1]|TCON_POLA_<br>SEL[0]|
||TCON_TIM_POLB1|-|-|-|-|-|TCON_POLB_HS[10]|TCON_POLB_HS[9]|TCON_POLB_HS[8]|
|||TCON_POLB_HS[7]|TCON_POLB_HS[6]|TCON_POLB_HS[5]|TCON_POLB_HS[4]|TCON_POLB_HS[3]|TCON_POLB_HS[2]|TCON_POLB_HS[1]|TCON_POLB_HS[0]|
|||-|-|-|-|-|TCON_POLB_<br>HW[10]|TCON_POLB_<br>HW[9]|TCON_POLB_<br>HW[8]|
|||TCON_POLB_<br>HW[7]|TCON_POLB_<br>HW[6]|TCON_POLB_<br>HW[5]|TCON_POLB_<br>HW[4]|TCON_POLB_<br>HW[3]|TCON_POLB_<br>HW[2]|TCON_POLB_<br>HW[1]|TCON_POLB_<br>HW[0]|
||TCON_TIM_POLB2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|TCON_POLB_MD[1]|TCON_POLB_MD[0]|-|-|-|TCON_POLB_HS_<br>SEL|
|||-|-|-|TCON_POLB_<br>INV|-|TCON_POLB_<br>SEL[2]|TCON_POLB_<br>SEL[1]|TCON_POLB_<br>SEL[0]|
||TCON_TIM_DE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TCON_DE_INV|
||OUT_UPDATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|OUTCNT_VEN|
||OUT_SET|-|-|-|OUT_ENDIAN_ON|-|-|-|OUT_SWAP_ON|
|||-|-|-|-|-|-|-|-|
|||-|-|OUT_FORMAT[1]|OUT_FORMAT[0]|-|-|OUT_FRQ_SEL[1]|OUT_FRQ_SEL[0]|
|||-|-|-|OUT_DIR_SEL|-|-|OUT_PHASE[1]|OUT_PHASE[0]|
||OUT_BRIGHT1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PBRT_G[9]|PBRT_G[8]|
|||PBRT_G[7]|PBRT_G[6]|PBRT_G[5]|PBRT_G[4]|PBRT_G[3]|PBRT_G[2]|PBRT_G[1]|PBRT_G[0]|
||OUT_BRIGHT2|-|-|-|-|-|-|PBRT_B[9]|PBRT_B[8]|
|||PBRT_B[7]|PBRT_B[6]|PBRT_B[5]|PBRT_B[4]|PBRT_B[3]|PBRT_B[2]|PBRT_B[1]|PBRT_B[0]|
|||-|-|-|-|-|-|PBRT_R[9]|PBRT_R[8]|
|||PBRT_R[7]|PBRT_R[6]|PBRT_R[5]|PBRT_R[4]|PBRT_R[3]|PBRT_R[2]|PBRT_R[1]|PBRT_R[0]|
||OUT_CONTRAST|-|-|-|-|-|-|-|-|
|||CONT_G[7]|CONT_G[6]|CONT_G[5]|CONT_G[4]|CONT_G[3]|CONT_G[2]|CONT_G[1]|CONT_G[0]|
|||CONT_B[7]|CONT_B[6]|CONT_B[5]|CONT_B[4]|CONT_B[3]|CONT_B[2]|CONT_B[1]|CONT_B[0]|
|||CONT_R[7]|CONT_R[6]|CONT_R[5]|CONT_R[4]|CONT_R[3]|CONT_R[2]|CONT_R[1]|CONT_R[0]|
||OUT_PDTHA|-|-|-|-|-|-|-|-|
|||-|-|PDTH_SEL[1]|PDTH_SEL[0]|-|-|PDTH_FORMAT<br>[1]|PDTH_FORMAT<br>[0]|
|||-|-|PDTH_PA[1]|PDTH_PA[0]|-|-|PDTH_PB[1]|PDTH_PB[0]|
|||-|-|PDTH_PC[1]|PDTH_PC[0]|-|-|PDTH_PD[1]|PDTH_PD[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Video display<br>controller 5|OUT_CLK_PHASE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|OUTCNT_FRONT_<br>GAM|-|-|-|OUTCNT_LCD_<br>EDGE|
|||-|OUTCNT_STVA_<br>EDGE|OUTCNT_STVB_<br>EDGE|OUTCNT_STH_<br>EDGE|OUTCNT_STB_<br>EDGE|OUTCNT_CPV_<br>EDGE|OUTCNT_POLA_<br>EDGE|OUTCNT_POLB_<br>EDGE|
||SYSCNT_INT1|-|-|-|INT_STA7|-|-|-|INT_STA6|
|||-|-|-|INT_STA5|-|-|-|INT_STA4|
|||-|-|-|INT_STA3|-|-|-|INT_STA2|
|||-|-|-|INT_STA1|-|-|-|INT_STA0|
||SYSCNT_INT2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|INT_STA9|-|-|-|INT_STA8|
||SYSCNT_INT4|-|-|-|INT_OUT7_ON|-|-|-|INT_OUT6_ON|
|||-|-|-|INT_OUT5_ON|-|-|-|INT_OUT4_ON|
|||-|-|-|INT_OUT3_ON|-|-|-|INT_OUT2_ON|
|||-|-|-|INT_OUT1_ON|-|-|-|INT_OUT0_ON|
||SYSCNT_INT5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|INT_OUT9_ON|-|-|-|INT_OUT8_ON|
||SYSCNT_PANEL_<br>CLK|-|-|PANEL_ICKSEL<br>[1]|PANEL_ICKSEL<br>[0]|-|-|-|PANEL_ICKEN|
|||-|-|PANEL_DCDR[5]|PANEL_DCDR[4]|PANEL_DCDR[3]|PANEL_DCDR[2]|PANEL_DCDR[1]|PANEL_DCDR[0]|
||SYSCNT_CLUT|-|-|-|GR3_CLT_SEL_<br>ST|-|-|-|GR2_CLT_SEL_<br>ST|
|||-|-|-|-|-|-|-|GR0_CLT_SEL_<br>ST|
|Capture engine<br>unit|CAPSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|CPKIL|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|CE|
||CAPCR|FDRP[7]|FDRP[6]|FDRP[5]|FDRP[4]|FDRP[3]|FDRP[2]|FDRP[1]|FDRP[0]|
|||-|-|MTCM[1]|MTCM[0]|-|-|-|CTNCP|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||CAMCR|-|-|-|-|VDSEL*6|HDSEL*6|FLDSEL*6|DSEL*6|
|||-|-|-|-|-|-|-|FLDPOL|
|||-|-|-|DTIF|-|-|DTARY[1]|DTARY[0]|
|||-|-|JPG[1]|JPG[0]|-|-|VDPOL|HDPOL|
||CMCYR|-|-|VCYL[13]|VCYL[12]|VCYL[11]|VCYL[10]|VCYL[9]|VCYL[8]|
|||VCYL[7]|VCYL[6]|VCYL[5]|VCYL[4]|VCYL[3]|VCYL[2]|VCYL[1]|VCYL[0]|
|||-|-|HCYL[13]|HCYL[12]|HCYL[11]|HCYL[10]|HCYL[9]|HCYL[8]|
|||HCYL[7]|HCYL[6]|HCYL[5]|HCYL[4]|HCYL[3]|HCYL[2]|HCYL[1]|HCYL[0]|
||CAMOR|-|-|-|-|VOFST[11]|VOFST[10]|VOFST[9]|VOFST[8]|
|||VOFST[7]|VOFST[6]|VOFST[5]|VOFST[4]|VOFST[3]|VOFST[2]|VOFST[1]|VOFST[0]|
|||-|-|-|HOFST[12]|HOFST[11]|HOFST[10]|HOFST[9]|HOFST[8]|
|||HOFST[7]|HOFST[6]|HOFST[5]|HOFST[4]|HOFST[3]|HOFST[2]|HOFST[1]|HOFST[0]|
||CAPWR|-|-|-|-|VWDTH[11]|VWDTH[10]|VWDTH[9]|VWDTH[8]|
|||VWDTH[7]|VWDTH[6]|VWDTH[5]|VWDTH[4]|VWDTH[3]|VWDTH[2]|VWDTH[1]|VWDTH[0]|
|||-|-|-|HWDTH[12]|HWDTH[11]|HWDTH[10]|HWDTH[9]|HWDTH[8]|
|||HWDTH[7]|HWDTH[6]|HWDTH[5]|HWDTH[4]|HWDTH[3]|HWDTH[2]|HWDTH[1]|HWDTH[0]|
||CAIFR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|IFS|
|||-|-|-|CIM|-|-|FCI[1]|FCI[0]|
||CRCNTR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|RVS|-|-|RS|RC|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Capture engine<br>unit|CRCMPR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|RA|
||CFLCR|VMANT[3]|VMANT[2]|VMANT[1]|VMANT[0]|VFRAC[11]|VFRAC[10]|VFRAC[9]|VFRAC[8]|
|||VFRAC[7]|VFRAC[6]|VFRAC[5]|VFRAC[4]|VFRAC[3]|VFRAC[2]|VFRAC[1]|VFRAC[0]|
|||HMANT[3]|HMANT[2]|HMANT[1]|HMANT[0]|HFRAC[11]|HFRAC[10]|HFRAC[9]|HFRAC[8]|
|||HFRAC[7]|HFRAC[6]|HFRAC[5]|HFRAC[4]|HFRAC[3]|HFRAC[2]|HFRAC[1]|HFRAC[0]|
||CFSZR|-|-|-|-|VFCLP[11]|VFCLP[10]|VFCLP[9]|VFCLP[8]|
|||VFCLP[7]|VFCLP[6]|VFCLP[5]|VFCLP[4]|VFCLP[3]|VFCLP[2]|VFCLP[1]|VFCLP[0]|
|||-|-|-|-|HFCLP[11]|HFCLP[10]|HFCLP[9]|HFCLP[8]|
|||HFCLP[7]|HFCLP[6]|HFCLP[5]|HFCLP[4]|HFCLP[3]|HFCLP[2]|HFCLP[1]|HFCLP[0]|
||CDWDR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|CHDW[12]|CHDW[11]|CHDW[10]|CHDW[9]|CHDW[8]|
|||CHDW[7]|CHDW[6]|CHDW[5]|CHDW[4]|CHDW[3]|CHDW[2]|CHDW[1]|CHDW[0]|
||CDAYR|CAYR[31]|CAYR[30]|CAYR[29]|CAYR[28]|CAYR[27]|CAYR[26]|CAYR[25]|CAYR[24]|
|||CAYR[23]|CAYR[22]|CAYR[21]|CAYR[20]|CAYR[19]|CAYR[18]|CAYR[17]|CAYR[16]|
|||CAYR[15]|CAYR[14]|CAYR[13]|CAYR[12]|CAYR[11]|CAYR[10]|CAYR[9]|CAYR[8]|
|||CAYR[7]|CAYR[6]|CAYR[5]|CAYR[4]|CAYR[3]|CAYR[2]|CAYR[1]|CAYR[0]|
||CDACR|CACR[31]|CACR[30]|CACR[29]|CACR[28]|CACR[27]|CACR[26]|CACR[25]|CACR[24]|
|||CACR[23]|CACR[22]|CACR[21]|CACR[20]|CACR[19]|CACR[18]|CACR[17]|CACR[16]|
|||CACR[15]|CACR[14]|CACR[13]|CACR[12]|CACR[11]|CACR[10]|CACR[9]|CACR[8]|
|||CACR[7]|CACR[6]|CACR[5]|CACR[4]|CACR[3]|CACR[2]|CACR[1]|CACR[0]|
||CDBYR|CBYR[31]|CBYR[30]|CBYR[29]|CBYR[28]|CBYR[27]|CBYR[26]|CBYR[25]|CBYR[24]|
|||CBYR[23]|CBYR[22]|CBYR[21]|CBYR[20]|CBYR[19]|CBYR[18]|CBYR[17]|CBYR[16]|
|||CBYR[15]|CBYR[14]|CBYR[13]|CBYR[12]|CBYR[11]|CBYR[10]|CBYR[9]|CBYR[8]|
|||CBYR[7]|CBYR[6]|CBYR[5]|CBYR[4]|CBYR[3]|CBYR[2]|CBYR[1]|CBYR[0]|
||CDBCR|CBCR[31]|CBCR[30]|CBCR[29]|CBCR[28]|CBCR[27]|CBCR[26]|CBCR[25]|CBCR[24]|
|||CBCR[23]|CBCR[22]|CBCR[21]|CBCR[20]|CBCR[19]|CBCR[18]|CBCR[17]|CBCR[16]|
|||CBCR[15]|CBCR[14]|CBCR[13]|CBCR[12]|CBCR[11]|CBCR[10]|CBCR[9]|CBCR[8]|
|||CBCR[7]|CBCR[6]|CBCR[5]|CBCR[4]|CBCR[3]|CBCR[2]|CBCR[1]|CBCR[0]|
||CBDSR|-|-|-|-|-|-|-|-|
|||-|CBVS[22]|CBVS[21]|CBVS[20]|CBVS[19]|CBVS[18]|CBVS[17]|CBVS[16]|
|||CBVS[15]|CBVS[14]|CBVS[13]|CBVS[12]|CBVS[11]|CBVS[10]|CBVS[9]|CBVS[8]|
|||CBVS[7]|CBVS[6]|CBVS[5]|CBVS[4]|CBVS[3]|CBVS[2]|CBVS[1]|CBVS[0]|
||CFWCR|FWV[26]|FWV[25]|FWV[24]|FWV[23]|FWV[22]|FWV[21]|FWV[20]|FWV[19]|
|||FWV[18]|FWV[17]|FWV[16]|FWV[15]|FWV[14]|FWV[13]|FWV[12]|FWV[11]|
|||FWV[10]|FWV[9]|FWV[8]|FWV[7]|FWV[6]|FWV[5]|FWV[4]|FWV[3]|
|||FWV[2]|FWV[1]|FWV[0]|-|-|-|-|FWE|
||CLFCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|LPF|
||CDOCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|CBE|
|||-|-|-|-|-|-|-|-|
|||-|-|-|CDS|-|COLS|COWS|COBS|
||CEIER|-|-|-|-|-|-|NVDIE|NHDIE|
|||FWFIE|-|-|VBPIE|-|IGVSIE|IGHSIE|CDTOFIE|
|||CPBE4IE|CPBE3IE|CPBE2IE|CPBE1IE|-|-|VDIE|HDIE|
|||-|-|-|IGRWIE|-|-|CFEIE|CPEIE|
||CETCR|-|-|-|-|-|-|NVD|NHD|
|||FWF|-|-|VBP|-|IGVS|IGHS|CDTOF|
|||CPBE4|CPBE3|CPBE2|CPBE1|-|-|VD|HD|
|||-|-|-|IGRW|-|-|CFE|CPE|
||CSTSR|-|-|-|-|-|-|-|CRST|
|||-|-|-|-|-|-|-|CPFLD|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|CPTON|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Capture engine<br>unit|CDSSR|CDSS[31]|CDSS[30]|CDSS[29]|CDSS[28]|CDSS[27]|CDSS[26]|CDSS[25]|CDSS[24]|
|||CDSS[23]|CDSS[22]|CDSS[21]|CDSS[20]|CDSS[19]|CDSS[18]|CDSS[17]|CDSS[16]|
|||CDSS[15]|CDSS[14]|CDSS[13]|CDSS[12]|CDSS[11]|CDSS[10]|CDSS[9]|CDSS[8]|
|||CDSS[7]|CDSS[6]|CDSS[5]|CDSS[4]|CDSS[3]|CDSS[2]|CDSS[1]|CDSS[0]|
||CDAYR2|CAYR2[31]|CAYR2[30]|CAYR2[29]|CAYR2[28]|CAYR2[27]|CAYR2[26]|CAYR2[25]|CAYR2[24]|
|||CAYR2[23]|CAYR2[22]|CAYR2[21]|CAYR2[20]|CAYR2[19]|CAYR2[18]|CAYR2[17]|CAYR2[16]|
|||CAYR2[15]|CAYR2[14]|CAYR2[13]|CAYR2[12]|CAYR2[11]|CAYR2[10]|CAYR2[9]|CAYR2[8]|
|||CAYR2[7]|CAYR2[6]|CAYR2[5]|CAYR2[4]|CAYR2[3]|CAYR2[2]|CAYR2[1]|CAYR2[0]|
||CDACR2|CACR2[31]|CACR2[30]|CACR2[29]|CACR2[28]|CACR2[27]|CACR2[26]|CACR2[25]|CACR2[24]|
|||CACR2[23]|CACR2[22]|CACR2[21]|CACR2[20]|CACR2[19]|CACR2[18]|CACR2[17]|CACR2[16]|
|||CACR2[15]|CACR2[14]|CACR2[13]|CACR2[12]|CACR2[11]|CACR2[10]|CACR2[9]|CACR2[8]|
|||CACR2[7]|CACR2[6]|CACR2[5]|CACR2[4]|CACR2[3]|CACR2[2]|CACR2[1]|CACR2[0]|
||CDBYR2|CBYR2[31]|CBYR2[30]|CBYR2[29]|CBYR2[28]|CBYR2[27]|CBYR2[26]|CBYR2[25]|CBYR2[24]|
|||CBYR2[23]|CBYR2[22]|CBYR2[21]|CBYR2[20]|CBYR2[19]|CBYR2[18]|CBYR2[17]|CBYR2[16]|
|||CBYR2[15]|CBYR2[14]|CBYR2[13]|CBYR2[12]|CBYR2[11]|CBYR2[10]|CBYR2[9]|CBYR2[8]|
|||CBYR2[7]|CBYR2[6]|CBYR2[5]|CBYR2[4]|CBYR2[3]|CBYR2[2]|CBYR2[1]|CBYR2[0]|
||CDBCR2|CBCR2[31]|CBCR2[30]|CBCR2[29]|CBCR2[28]|CBCR2[27]|CBCR2[26]|CBCR2[25]|CBCR2[24]|
|||CBCR2[23]|CBCR2[22]|CBCR2[21]|CBCR2[20]|CBCR2[19]|CBCR2[18]|CBCR2[17]|CBCR2[16]|
|||CBCR2[15]|CBCR2[14]|CBCR2[13]|CBCR2[12]|CBCR2[11]|CBCR2[10]|CBCR2[9]|CBCR2[8]|
|||CBCR2[7]|CBCR2[6]|CBCR2[5]|CBCR2[4]|CBCR2[3]|CBCR2[2]|CBCR2[1]|CBCR2[0]|
|SCUX|IPCIR_IPC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||IPSLR_IPC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|IPC_PASS_SEL[2]|IPC_PASS_SEL[1]|IPC_PASS_SEL[0]|
||IPCIR_IPC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||IPSLR_IPC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|IPC_PASS_SEL[2]|IPC_PASS_SEL[1]|IPC_PASS_SEL[0]|
||IPCIR_IPC0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||IPSLR_IPC0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|IPC_PASS_SEL[2]|IPC_PASS_SEL[1]|IPC_PASS_SEL[0]|
||IPCIR_IPC0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||IPSLR_IPC0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|IPC_PASS_SEL[2]|IPC_PASS_SEL[1]|IPC_PASS_SEL[0]|
||OPCIR_OPC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||OPSLR_OPC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|OPC_PASS_SEL[2]|OPC_PASS_SEL[1]|OPC_PASS_SEL[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|OPCIR_OPC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||OPSLR_OPC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|OPC_PASS_SEL<br>[2]|OPC_PASS_SEL<br>[1]|OPC_PASS_SEL<br>[0]|
||OPCIR_OPC0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||OPSLR_OPC0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|OPC_PASS_SEL<br>[2]|OPC_PASS_SEL<br>[1]|OPC_PASS_SEL<br>[0]|
||OPCIR_OPC0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||OPSLR_OPC0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|OPC_PASS_SEL<br>[2]|OPC_PASS_SEL<br>[1]|OPC_PASS_SEL<br>[0]|
||FFDIR_FFD0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||FDAIR_FFD0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||DRQSR_FFD0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||FFDPR_FFD0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PASS[1]|PASS[0]|
||FFDBR_FFD0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BOOT|
||DEVMR_FFD0_0|DEVMUF|DEVMOF|DEVMOL|DEVMIUF|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DEVMRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||DEVCR_FFD0_0|DEVCUF|DEVCOF|DEVCOL|DEVCIUF|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DEVCRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||FFDIR_FFD0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|FDAIR_FFD0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||DRQSR_FFD0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||FFDPR_FFD0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PASS[1]|PASS[0]|
||FFDBR_FFD0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BOOT|
||DEVMR_FFD0_1|DEVMUF|DEVMOF|DEVMOL|DEVMIUF|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DEVMRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||DEVCR_FFD0_1|DEVCUF|DEVCOF|DEVCOL|DEVCIUF|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DEVCRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||FFDIR_FFD0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||FDAIR_FFD0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||DRQSR_FFD0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||FFDPR_FFD0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PASS[1]|PASS[0]|
||FFDBR_FFD0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BOOT|
||DEVMR_FFD0_2|DEVMUF|DEVMOF|DEVMOL|DEVMIUF|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DEVMRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||DEVCR_FFD0_2|DEVCUF|DEVCOF|DEVCOL|DEVCIUF|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DEVCRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||FFDIR_FFD0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||FDAIR_FFD0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|DRQSR_FFD0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||FFDPR_FFD0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PASS[1]|PASS[0]|
||FFDBR_FFD0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BOOT|
||DEVMR_FFD0_3|DEVMUF|DEVMOF|DEVMOL|DEVMIUF|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DEVMRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||DEVCR_FFD0_3|DEVCUF|DEVCOF|DEVCOL|DEVCIUF|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DEVCRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||FFUIR_FFU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||FUAIR_FFU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||URQSR_FFU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||FFUPR_FFU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PASS[1]|PASS[0]|
||UEVMR_FFU0_0|UEVMUF|UEVMOF|UEVMOL|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||UEVMRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||UEVCR_FFU0_0|UEVCUF|UEVCOF|UEVCOL|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||UEVCRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||FFUIR_FFU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||FUAIR_FFU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||URQSR_FFU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||FFUPR_FFU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PASS[1]|PASS[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|UEVMR_FFU0_1|UEVMUF|UEVMOF|UEVMOL|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||UEVMRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||UEVCR_FFU0_1|UEVCUF|UEVCOF|UEVCOL|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||UEVCRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||FFUIR_FFU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||FUAIR_FFU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||URQSR_FFU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||FFUPR_FFU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PASS[1]|PASS[0]|
||UEVMR_FFU0_2|UEVMUF|UEVMOF|UEVMOL|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||UEVMRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||UEVCR_FFU0_2|UEVCUF|UEVCOF|UEVCOL|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||UEVCRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||FFUIR_FFU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||FUAIR_FFU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||URQSR_FFU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||FFUPR_FFU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|PASS[1]|PASS[0]|
||UEVMR_FFU0_3|UEVMUF|UEVMOF|UEVMOL|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||UEVMRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||UEVCR_FFU0_3|UEVCUF|UEVCOF|UEVCOL|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||UEVCRQ|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SRCIR0_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|SADIR0_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|OTBL[4]|OTBL[3]|OTBL[2]|OTBL[1]|OTBL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||SRCBR0_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||IFSCR0_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTIFSEN|
||IFSVR0_2SRC0_0|-|-|-|-|INTIFS[27]|INTIFS[26]|INTIFS[25]|INTIFS[24]|
|||INTIFS[23]|INTIFS[22]|INTIFS[21]|INTIFS[20]|INTIFS[19]|INTIFS[18]|INTIFS[17]|INTIFS[16]|
|||INTIFS[15]|INTIFS[14]|INTIFS[13]|INTIFS[11]|INTIFS[11]|INTIFS[10]|INTIFS[9]|INTIFS[8]|
|||INTIFS[7]|INTIFS[6]|INTIFS[5]|INTIFS[4]|INTIFS[3]|INTIFS[2]|INTIFS[1]|INTIFS[0]|
||SRCCR0_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|WATMD|-|-|-|-|
|||-|-|-|BUFMD|-|-|-|-|
|||-|-|-|-|-|-|-|SRCMD|
||MNFSR0_2SRC0_0|-|-|-|-|MINFS[27]|MINFS[26]|MINFS[25]|MINFS[24]|
|||MINFS[23]|MINFS[22]|MINFS[21]|MINFS[20]|MINFS[19]|MINFS[18]|MINFS[17]|MINFS[16]|
|||MINFS[15]|MINFS[14]|MINFS[13]|MINFS[11]|MINFS[11]|MINFS[10]|MINFS[9]|MINFS[8]|
|||MINFS[7]|MINFS[6]|MINFS[5]|MINFS[4]|MINFS[3]|MINFS[2]|MINFS[1]|MINFS[0]|
||BFSSR0_2SRC0_0|-|-|-|-|-|-|BUFDATA[9]|BUFDATA[8]|
|||BUFDATA[7]|BUFDATA[6]|BUFDATA[5]|BUFDATA[4]|BUFDATA[3]|BUFDATA[1]|BUFDATA[1]|BUFDATA[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|BUFIN[3]|BUFIN[2]|BUFIN[1]|BUFIN[0]|
||SC2SR0_2SRC0_0|SRCWSTS|SC2MUTE|SC2STS[1]|SC2STS[0]|SC2FSI[27]|SC2FSI[26]|SC2FSI[25]|SC2FSI[24]|
|||SC2FSI[23]|SC2FSI[22]|SC2FSI[21]|SC2FSI[20]|SC2FSI[19]|SC2FSI[18]|SC2FSI[17]|SC2FSI[16]|
|||SC2FSI[15]|SC2FSI[14]|SC2FSI[13]|SC2FSI[11]|SC2FSI[11]|SC2FSI[10]|SC2FSI[9]|SC2FSI[8]|
|||SC2FSI[7]|SC2FSI[6]|SC2FSI[5]|SC2FSI[4]|SC2FSI[3]|SC2FSI[2]|SC2FSI[1]|SC2FSI[0]|
||WATSR0_2SRC0_0|-|-|-|-|-|-|-|-|
|||WTIME[23]|WTIME[22]|WTIME[21]|WTIME[20]|WTIME[19]|WTIME[18]|WTIME[17]|WTIME[16]|
|||WTIME[15]|WTIME[14]|WTIME[13]|WTIME[11]|WTIME[11]|WTIME[10]|WTIME[9]|WTIME[8]|
|||WTIME[7]|WTIME[6]|WTIME[5]|WTIME[4]|WTIME[3]|WTIME[2]|WTIME[1]|WTIME[0]|
||SEVMR0_2SRC0_0|EVMUF|EVMOF|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|EVMWAIT|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SEVCR0_2SRC0_0|EVCUF|EVCOF|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|EVCWAIT|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SRCIR1_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||SADIR1_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|OTBL[4]|OTBL[3]|OTBL[2]|OTBL[1]|OTBL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||SRCBR1_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||IFSCR1_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTIFSEN|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|IFSVR1_2SRC0_0|-|-|-|-|INTIFS[27]|INTIFS[26]|INTIFS[25]|INTIFS[24]|
|||INTIFS[23]|INTIFS[22]|INTIFS[21]|INTIFS[20]|INTIFS[19]|INTIFS[18]|INTIFS[17]|INTIFS[16]|
|||INTIFS[15]|INTIFS[14]|INTIFS[13]|INTIFS[11]|INTIFS[11]|INTIFS[10]|INTIFS[9]|INTIFS[8]|
|||INTIFS[7]|INTIFS[6]|INTIFS[5]|INTIFS[4]|INTIFS[3]|INTIFS[2]|INTIFS[1]|INTIFS[0]|
||SRCCR1_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|WATMD|-|-|-|-|
|||-|-|-|BUFMD|-|-|-|-|
|||-|-|-|-|-|-|-|SRCMD|
||MNFSR1_2SRC0_0|-|-|-|-|MINFS[27]|MINFS[26]|MINFS[25]|MINFS[24]|
|||MINFS[23]|MINFS[22]|MINFS[21]|MINFS[20]|MINFS[19]|MINFS[18]|MINFS[17]|MINFS[16]|
|||MINFS[15]|MINFS[14]|MINFS[13]|MINFS[11]|MINFS[11]|MINFS[10]|MINFS[9]|MINFS[8]|
|||MINFS[7]|MINFS[6]|MINFS[5]|MINFS[4]|MINFS[3]|MINFS[2]|MINFS[1]|MINFS[0]|
||BFSSR1_2SRC0_0|-|-|-|-|-|-|BUFDATA[9]|BUFDATA[8]|
|||BUFDATA[7]|BUFDATA[6]|BUFDATA[5]|BUFDATA[4]|BUFDATA[3]|BUFDATA[1]|BUFDATA[1]|BUFDATA[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|BUFIN[3]|BUFIN[2]|BUFIN[1]|BUFIN[0]|
||SC2SR1_2SRC0_0|SRCWSTS|SC2MUTE|SC2STS[1]|SC2STS[0]|SC2FSI[27]|SC2FSI[26]|SC2FSI[25]|SC2FSI[24]|
|||SC2FSI[23]|SC2FSI[22]|SC2FSI[21]|SC2FSI[20]|SC2FSI[19]|SC2FSI[18]|SC2FSI[17]|SC2FSI[16]|
|||SC2FSI[15]|SC2FSI[14]|SC2FSI[13]|SC2FSI[11]|SC2FSI[11]|SC2FSI[10]|SC2FSI[9]|SC2FSI[8]|
|||SC2FSI[7]|SC2FSI[6]|SC2FSI[5]|SC2FSI[4]|SC2FSI[3]|SC2FSI[2]|SC2FSI[1]|SC2FSI[0]|
||WATSR1_2SRC0_0|-|-|-|-|-|-|-|-|
|||WTIME[23]|WTIME[22]|WTIME[21]|WTIME[20]|WTIME[19]|WTIME[18]|WTIME[17]|WTIME[16]|
|||WTIME[15]|WTIME[14]|WTIME[13]|WTIME[11]|WTIME[11]|WTIME[10]|WTIME[9]|WTIME[8]|
|||WTIME[7]|WTIME[6]|WTIME[5]|WTIME[4]|WTIME[3]|WTIME[2]|WTIME[1]|WTIME[0]|
||SEVMR1_2SRC0_0|EVMUF|EVMOF|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|EVMWAIT|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SEVCR1_2SRC0_0|EVCUF|EVCOF|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|EVCWAIT|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SRCIRR_2SRC0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||SRCIR0_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||SADIR0_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|OTBL[4]|OTBL[3]|OTBL[2]|OTBL[1]|OTBL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||SRCBR0_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||IFSCR0_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTIFSEN|
||IFSVR0_2SRC0_1|-|-|-|-|INTIFS[27]|INTIFS[26]|INTIFS[25]|INTIFS[24]|
|||INTIFS[23]|INTIFS[22]|INTIFS[21]|INTIFS[20]|INTIFS[19]|INTIFS[18]|INTIFS[17]|INTIFS[16]|
|||INTIFS[15]|INTIFS[14]|INTIFS[13]|INTIFS[11]|INTIFS[11]|INTIFS[10]|INTIFS[9]|INTIFS[8]|
|||INTIFS[7]|INTIFS[6]|INTIFS[5]|INTIFS[4]|INTIFS[3]|INTIFS[2]|INTIFS[1]|INTIFS[0]|
||SRCCR0_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|WATMD|-|-|-|-|
|||-|-|-|BUFMD|-|-|-|-|
|||-|-|-|-|-|-|-|SRCMD|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|MNFSR0_2SRC0_1|-|-|-|-|MINFS[27]|MINFS[26]|MINFS[25]|MINFS[24]|
|||MINFS[23]|MINFS[22]|MINFS[21]|MINFS[20]|MINFS[19]|MINFS[18]|MINFS[17]|MINFS[16]|
|||MINFS[15]|MINFS[14]|MINFS[13]|MINFS[11]|MINFS[11]|MINFS[10]|MINFS[9]|MINFS[8]|
|||MINFS[7]|MINFS[6]|MINFS[5]|MINFS[4]|MINFS[3]|MINFS[2]|MINFS[1]|MINFS[0]|
||BFSSR0_2SRC0_1|-|-|-|-|-|-|BUFDATA[9]|BUFDATA[8]|
|||BUFDATA[7]|BUFDATA[6]|BUFDATA[5]|BUFDATA[4]|BUFDATA[3]|BUFDATA[1]|BUFDATA[1]|BUFDATA[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|BUFIN[3]|BUFIN[2]|BUFIN[1]|BUFIN[0]|
||SC2SR0_2SRC0_1|SRCWSTS|SC2MUTE|SC2STS[1]|SC2STS[0]|SC2FSI[27]|SC2FSI[26]|SC2FSI[25]|SC2FSI[24]|
|||SC2FSI[23]|SC2FSI[22]|SC2FSI[21]|SC2FSI[20]|SC2FSI[19]|SC2FSI[18]|SC2FSI[17]|SC2FSI[16]|
|||SC2FSI[15]|SC2FSI[14]|SC2FSI[13]|SC2FSI[11]|SC2FSI[11]|SC2FSI[10]|SC2FSI[9]|SC2FSI[8]|
|||SC2FSI[7]|SC2FSI[6]|SC2FSI[5]|SC2FSI[4]|SC2FSI[3]|SC2FSI[2]|SC2FSI[1]|SC2FSI[0]|
||WATSR0_2SRC0_1|-|-|-|-|-|-|-|-|
|||WTIME[23]|WTIME[22]|WTIME[21]|WTIME[20]|WTIME[19]|WTIME[18]|WTIME[17]|WTIME[16]|
|||WTIME[15]|WTIME[14]|WTIME[13]|WTIME[11]|WTIME[11]|WTIME[10]|WTIME[9]|WTIME[8]|
|||WTIME[7]|WTIME[6]|WTIME[5]|WTIME[4]|WTIME[3]|WTIME[2]|WTIME[1]|WTIME[0]|
||SEVMR0_2SRC0_1|EVMUF|EVMOF|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|EVMWAIT|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SEVCR0_2SRC0_1|EVCUF|EVCOF|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|EVCWAIT|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SRCIR1_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||SADIR1_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|OTBL[4]|OTBL[3]|OTBL[2]|OTBL[1]|OTBL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||SRCBR1_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||IFSCR1_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INTIFSEN|
||IFSVR1_2SRC0_1|-|-|-|-|INTIFS[27]|INTIFS[26]|INTIFS[25]|INTIFS[24]|
|||INTIFS[23]|INTIFS[22]|INTIFS[21]|INTIFS[20]|INTIFS[19]|INTIFS[18]|INTIFS[17]|INTIFS[16]|
|||INTIFS[15]|INTIFS[14]|INTIFS[13]|INTIFS[11]|INTIFS[11]|INTIFS[10]|INTIFS[9]|INTIFS[8]|
|||INTIFS[7]|INTIFS[6]|INTIFS[5]|INTIFS[4]|INTIFS[3]|INTIFS[2]|INTIFS[1]|INTIFS[0]|
||SRCCR1_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|WATMD|-|-|-|-|
|||-|-|-|BUFMD|-|-|-|-|
|||-|-|-|-|-|-|-|SRCMD|
||MNFSR1_2SRC0_1|-|-|-|-|MINFS[27]|MINFS[26]|MINFS[25]|MINFS[24]|
|||MINFS[23]|MINFS[22]|MINFS[21]|MINFS[20]|MINFS[19]|MINFS[18]|MINFS[17]|MINFS[16]|
|||MINFS[15]|MINFS[14]|MINFS[13]|MINFS[11]|MINFS[11]|MINFS[10]|MINFS[9]|MINFS[8]|
|||MINFS[7]|MINFS[6]|MINFS[5]|MINFS[4]|MINFS[3]|MINFS[2]|MINFS[1]|MINFS[0]|
||BFSSR1_2SRC0_1|-|-|-|-|-|-|BUFDATA[9]|BUFDATA[8]|
|||BUFDATA[7]|BUFDATA[6]|BUFDATA[5]|BUFDATA[4]|BUFDATA[3]|BUFDATA[1]|BUFDATA[1]|BUFDATA[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|BUFIN[3]|BUFIN[2]|BUFIN[1]|BUFIN[0]|
||SC2SR1_2SRC0_1|SRCWSTS|SC2MUTE|SC2STS[1]|SC2STS[0]|SC2FSI[27]|SC2FSI[26]|SC2FSI[25]|SC2FSI[24]|
|||SC2FSI[23]|SC2FSI[22]|SC2FSI[21]|SC2FSI[20]|SC2FSI[19]|SC2FSI[18]|SC2FSI[17]|SC2FSI[16]|
|||SC2FSI[15]|SC2FSI[14]|SC2FSI[13]|SC2FSI[11]|SC2FSI[11]|SC2FSI[10]|SC2FSI[9]|SC2FSI[8]|
|||SC2FSI[7]|SC2FSI[6]|SC2FSI[5]|SC2FSI[4]|SC2FSI[3]|SC2FSI[2]|SC2FSI[1]|SC2FSI[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|WATSR1_2SRC0_1|-|-|-|-|-|-|-|-|
|||WTIME[23]|WTIME[22]|WTIME[21]|WTIME[20]|WTIME[19]|WTIME[18]|WTIME[17]|WTIME[16]|
|||WTIME[15]|WTIME[14]|WTIME[13]|WTIME[11]|WTIME[11]|WTIME[10]|WTIME[9]|WTIME[8]|
|||WTIME[7]|WTIME[6]|WTIME[5]|WTIME[4]|WTIME[3]|WTIME[2]|WTIME[1]|WTIME[0]|
||SEVMR1_2SRC0_1|EVMUF|EVMOF|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|EVMWAIT|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SEVCR1_2SRC0_1|EVCUF|EVCOF|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|EVCWAIT|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||SRCIRR_2SRC0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||DVUIR_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||VADIR_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|OTBL[4]|OTBL[3]|OTBL[2]|OTBL[1]|OTBL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||DVUBR_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||DVUCR_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|VVMD|
|||-|-|-|VRMD|-|-|-|ZCMD|
||ZCMCR_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ZCEN7|ZCEN6|ZCEN5|ZCEN4|ZCEN3|ZCEN2|ZCEN1|ZCEN0|
||VRCTR_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||VREN7|VREN6|VREN5|VREN4|VREN3|VREN2|VREN1|VREN0|
||VRPDR_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|VRPDUP[4]|VRPDUP[3]|VRPDUP[1]|VRPDUP[1]|VRPDUP[0]|
|||-|-|-|VRPDDW[4]|VRPDDW[3]|VRPDDW[2]|VRPDDW[1]|VRPDDW[0]|
||VRDBR_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|VRDB[9]|VRDB[8]|
|||VRDB[7]|VRDB[6]|VRDB[5]|VRDB[4]|VRDB[3]|VRDB[2]|VRDB[1]|VRDB[0]|
||VRWTR_DVU0_0|-|-|-|-|-|-|-|-|
|||VRWT[23]|VRWT[22]|VRWT[21]|VRWT[20]|VRWT[19]|VRWT[18]|VRWT[17]|VRWT[16]|
|||VRWT[15]|VRWT[14]|VRWT[13]|VRWT[11]|VRWT[11]|VRWT[10]|VRWT[9]|VRWT[8]|
|||VRWT[7]|VRWT[6]|VRWT[5]|VRWT[4]|VRWT[3]|VRWT[2]|VRWT[1]|VRWT[0]|
||VOL0R_DVU0_0|-|-|-|-|-|-|-|-|
|||VOLVAL0[23]|VOLVAL0[22]|VOLVAL0[21]|VOLVAL0[20]|VOLVAL0[19]|VOLVAL0[18]|VOLVAL0[17]|VOLVAL0[16]|
|||VOLVAL0[15]|VOLVAL0[14]|VOLVAL0[13]|VOLVAL0[11]|VOLVAL0[11]|VOLVAL0[10]|VOLVAL0[9]|VOLVAL0[8]|
|||VOLVAL0[7]|VOLVAL0[6]|VOLVAL0[5]|VOLVAL0[4]|VOLVAL0[3]|VOLVAL0[2]|VOLVAL0[1]|VOLVAL0[0]|
||VOL1R_DVU0_0|-|-|-|-|-|-|-|-|
|||VOLVAL1[23]|VOLVAL1[22]|VOLVAL1[21]|VOLVAL1[20]|VOLVAL1[19]|VOLVAL1[18]|VOLVAL1[17]|VOLVAL1[16]|
|||VOLVAL1[15]|VOLVAL1[14]|VOLVAL1[13]|VOLVAL1[11]|VOLVAL1[11]|VOLVAL1[10]|VOLVAL1[9]|VOLVAL1[8]|
|||VOLVAL1[7]|VOLVAL1[6]|VOLVAL1[5]|VOLVAL1[4]|VOLVAL1[3]|VOLVAL1[2]|VOLVAL1[1]|VOLVAL1[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|VOL2R_DVU0_0|-|-|-|-|-|-|-|-|
|||VOLVAL2[23]|VOLVAL2[22]|VOLVAL2[21]|VOLVAL2[20]|VOLVAL2[19]|VOLVAL2[18]|VOLVAL2[17]|VOLVAL2[16]|
|||VOLVAL2[15]|VOLVAL2[14]|VOLVAL2[13]|VOLVAL2[11]|VOLVAL2[11]|VOLVAL2[10]|VOLVAL2[9]|VOLVAL2[8]|
|||VOLVAL2[7]|VOLVAL2[6]|VOLVAL2[5]|VOLVAL2[4]|VOLVAL2[3]|VOLVAL2[2]|VOLVAL2[1]|VOLVAL2[0]|
||VOL3R_DVU0_0|-|-|-|-|-|-|-|-|
|||VOLVAL3[23]|VOLVAL3[22]|VOLVAL3[21]|VOLVAL3[20]|VOLVAL3[19]|VOLVAL3[18]|VOLVAL3[17]|VOLVAL3[16]|
|||VOLVAL3[15]|VOLVAL3[14]|VOLVAL3[13]|VOLVAL3[11]|VOLVAL3[11]|VOLVAL3[10]|VOLVAL3[9]|VOLVAL3[8]|
|||VOLVAL3[7]|VOLVAL3[6]|VOLVAL3[5]|VOLVAL3[4]|VOLVAL3[3]|VOLVAL3[2]|VOLVAL3[1]|VOLVAL3[0]|
||VOL4R_DVU0_0|-|-|-|-|-|-|-|-|
|||VOLVAL4[23]|VOLVAL4[22]|VOLVAL4[21]|VOLVAL4[20]|VOLVAL4[19]|VOLVAL4[18]|VOLVAL4[17]|VOLVAL4[16]|
|||VOLVAL4[15]|VOLVAL4[14]|VOLVAL4[13]|VOLVAL4[11]|VOLVAL4[11]|VOLVAL4[10]|VOLVAL4[9]|VOLVAL4[8]|
|||VOLVAL4[7]|VOLVAL4[6]|VOLVAL4[5]|VOLVAL4[4]|VOLVAL4[3]|VOLVAL4[2]|VOLVAL4[1]|VOLVAL4[0]|
||VOL5R_DVU0_0|-|-|-|-|-|-|-|-|
|||VOLVAL5[23]|VOLVAL5[22]|VOLVAL5[21]|VOLVAL5[20]|VOLVAL5[19]|VOLVAL5[18]|VOLVAL5[17]|VOLVAL5[16]|
|||VOLVAL5[15]|VOLVAL5[14]|VOLVAL5[13]|VOLVAL5[11]|VOLVAL5[11]|VOLVAL5[10]|VOLVAL5[9]|VOLVAL5[8]|
|||VOLVAL5[7]|VOLVAL5[6]|VOLVAL5[5]|VOLVAL5[4]|VOLVAL5[3]|VOLVAL5[2]|VOLVAL5[1]|VOLVAL5[0]|
||VOL6R_DVU0_0|-|-|-|-|-|-|-|-|
|||VOLVAL6[23]|VOLVAL6[22]|VOLVAL6[21]|VOLVAL6[20]|VOLVAL6[19]|VOLVAL6[18]|VOLVAL6[17]|VOLVAL6[16]|
|||VOLVAL6[15]|VOLVAL6[14]|VOLVAL6[13]|VOLVAL6[11]|VOLVAL6[11]|VOLVAL6[10]|VOLVAL6[9]|VOLVAL6[8]|
|||VOLVAL6[7]|VOLVAL6[6]|VOLVAL6[5]|VOLVAL6[4]|VOLVAL6[3]|VOLVAL6[2]|VOLVAL6[1]|VOLVAL6[0]|
||VOL7R_DVU0_0|-|-|-|-|-|-|-|-|
|||VOLVAL7[23]|VOLVAL7[22]|VOLVAL7[21]|VOLVAL7[20]|VOLVAL7[19]|VOLVAL7[18]|VOLVAL7[17]|VOLVAL7[16]|
|||VOLVAL7[15]|VOLVAL7[14]|VOLVAL7[13]|VOLVAL7[11]|VOLVAL7[11]|VOLVAL7[10]|VOLVAL7[9]|VOLVAL7[8]|
|||VOLVAL7[7]|VOLVAL7[6]|VOLVAL7[5]|VOLVAL7[4]|VOLVAL7[3]|VOLVAL7[2]|VOLVAL7[1]|VOLVAL7[0]|
||DVUER_DVU0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DVUEN|
||DVUSR_DVU0_0|-|-|-|-|-|-|-|-|
|||ZSTS7|ZSTS6|ZSTS5|ZSTS4|ZSTS3|ZSTS2|ZSTS1|ZSTS0|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|VRSTS[2]|VRSTS[1]|VRSTS[0]|
||VEVMR_DVU0_0|VEVMZCM7|VEVMZCM6|VEVMZCM5|VEVMZCM4|VEVMZCM3|VEVMZCM2|VEVMZCM1|VEVMZCM0|
|||-|-|-|-|-|-|-|-|
|||VEVMVR|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||VEVCR_DVU0_0|VEVCZCM7|VEVCZCM6|VEVCZCM5|VEVCZCM4|VEVCZCM3|VEVCZCM2|VEVCZCM1|VEVCZCM0|
|||-|-|-|-|-|-|-|-|
|||VEVCVR|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||DVUIR_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||VADIR_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|OTBL[4]|OTBL[3]|OTBL[2]|OTBL[1]|OTBL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||DVUBR_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||DVUCR_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|VVMD|
|||-|-|-|VRMD|-|-|-|ZCMD|
||ZCMCR_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ZCEN7|ZCEN6|ZCEN5|ZCEN4|ZCEN3|ZCEN2|ZCEN1|ZCEN0|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|VRCTR_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||VREN7|VREN6|VREN5|VREN4|VREN3|VREN2|VREN1|VREN0|
||VRPDR_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|VRPDUP[4]|VRPDUP[3]|VRPDUP[1]|VRPDUP[1]|VRPDUP[0]|
|||-|-|-|VRPDDW[4]|VRPDDW[3]|VRPDDW[2]|VRPDDW[1]|VRPDDW[0]|
||VRDBR_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|VRDB[9]|VRDB[8]|
|||VRDB[7]|VRDB[6]|VRDB[5]|VRDB[4]|VRDB[3]|VRDB[2]|VRDB[1]|VRDB[0]|
||VRWTR_DVU0_1|-|-|-|-|-|-|-|-|
|||VRWT[23]|VRWT[22]|VRWT[21]|VRWT[20]|VRWT[19]|VRWT[18]|VRWT[17]|VRWT[16]|
|||VRWT[15]|VRWT[14]|VRWT[13]|VRWT[11]|VRWT[11]|VRWT[10]|VRWT[9]|VRWT[8]|
|||VRWT[7]|VRWT[6]|VRWT[5]|VRWT[4]|VRWT[3]|VRWT[2]|VRWT[1]|VRWT[0]|
||VOL0R_DVU0_1|-|-|-|-|-|-|-|-|
|||VOLVAL0[23]|VOLVAL0[22]|VOLVAL0[21]|VOLVAL0[20]|VOLVAL0[19]|VOLVAL0[18]|VOLVAL0[17]|VOLVAL0[16]|
|||VOLVAL0[15]|VOLVAL0[14]|VOLVAL0[13]|VOLVAL0[11]|VOLVAL0[11]|VOLVAL0[10]|VOLVAL0[9]|VOLVAL0[8]|
|||VOLVAL0[7]|VOLVAL0[6]|VOLVAL0[5]|VOLVAL0[4]|VOLVAL0[3]|VOLVAL0[2]|VOLVAL0[1]|VOLVAL0[0]|
||VOL1R_DVU0_1|-|-|-|-|-|-|-|-|
|||VOLVAL1[23]|VOLVAL1[22]|VOLVAL1[21]|VOLVAL1[20]|VOLVAL1[19]|VOLVAL1[18]|VOLVAL1[17]|VOLVAL1[16]|
|||VOLVAL1[15]|VOLVAL1[14]|VOLVAL1[13]|VOLVAL1[11]|VOLVAL1[11]|VOLVAL1[10]|VOLVAL1[9]|VOLVAL1[8]|
|||VOLVAL1[7]|VOLVAL1[6]|VOLVAL1[5]|VOLVAL1[4]|VOLVAL1[3]|VOLVAL1[2]|VOLVAL1[1]|VOLVAL1[0]|
||VOL2R_DVU0_1|-|-|-|-|-|-|-|-|
|||VOLVAL2[23]|VOLVAL2[22]|VOLVAL2[21]|VOLVAL2[20]|VOLVAL2[19]|VOLVAL2[18]|VOLVAL2[17]|VOLVAL2[16]|
|||VOLVAL2[15]|VOLVAL2[14]|VOLVAL2[13]|VOLVAL2[11]|VOLVAL2[11]|VOLVAL2[10]|VOLVAL2[9]|VOLVAL2[8]|
|||VOLVAL2[7]|VOLVAL2[6]|VOLVAL2[5]|VOLVAL2[4]|VOLVAL2[3]|VOLVAL2[2]|VOLVAL2[1]|VOLVAL2[0]|
||VOL3R_DVU0_1|-|-|-|-|-|-|-|-|
|||VOLVAL3[23]|VOLVAL3[22]|VOLVAL3[21]|VOLVAL3[20]|VOLVAL3[19]|VOLVAL3[18]|VOLVAL3[17]|VOLVAL3[16]|
|||VOLVAL3[15]|VOLVAL3[14]|VOLVAL3[13]|VOLVAL3[11]|VOLVAL3[11]|VOLVAL3[10]|VOLVAL3[9]|VOLVAL3[8]|
|||VOLVAL3[7]|VOLVAL3[6]|VOLVAL3[5]|VOLVAL3[4]|VOLVAL3[3]|VOLVAL3[2]|VOLVAL3[1]|VOLVAL3[0]|
||VOL4R_DVU0_1|-|-|-|-|-|-|-|-|
|||VOLVAL4[23]|VOLVAL4[22]|VOLVAL4[21]|VOLVAL4[20]|VOLVAL4[19]|VOLVAL4[18]|VOLVAL4[17]|VOLVAL4[16]|
|||VOLVAL4[15]|VOLVAL4[14]|VOLVAL4[13]|VOLVAL4[11]|VOLVAL4[11]|VOLVAL4[10]|VOLVAL4[9]|VOLVAL4[8]|
|||VOLVAL4[7]|VOLVAL4[6]|VOLVAL4[5]|VOLVAL4[4]|VOLVAL4[3]|VOLVAL4[2]|VOLVAL4[1]|VOLVAL4[0]|
||VOL5R_DVU0_1|-|-|-|-|-|-|-|-|
|||VOLVAL5[23]|VOLVAL5[22]|VOLVAL5[21]|VOLVAL5[20]|VOLVAL5[19]|VOLVAL5[18]|VOLVAL5[17]|VOLVAL5[16]|
|||VOLVAL5[15]|VOLVAL5[14]|VOLVAL5[13]|VOLVAL5[11]|VOLVAL5[11]|VOLVAL5[10]|VOLVAL5[9]|VOLVAL5[8]|
|||VOLVAL5[7]|VOLVAL5[6]|VOLVAL5[5]|VOLVAL5[4]|VOLVAL5[3]|VOLVAL5[2]|VOLVAL5[1]|VOLVAL5[0]|
||VOL6R_DVU0_1|-|-|-|-|-|-|-|-|
|||VOLVAL6[23]|VOLVAL6[22]|VOLVAL6[21]|VOLVAL6[20]|VOLVAL6[19]|VOLVAL6[18]|VOLVAL6[17]|VOLVAL6[16]|
|||VOLVAL6[15]|VOLVAL6[14]|VOLVAL6[13]|VOLVAL6[11]|VOLVAL6[11]|VOLVAL6[10]|VOLVAL6[9]|VOLVAL6[8]|
|||VOLVAL6[7]|VOLVAL6[6]|VOLVAL6[5]|VOLVAL6[4]|VOLVAL6[3]|VOLVAL6[2]|VOLVAL6[1]|VOLVAL6[0]|
||VOL7R_DVU0_1|-|-|-|-|-|-|-|-|
|||VOLVAL7[23]|VOLVAL7[22]|VOLVAL7[21]|VOLVAL7[20]|VOLVAL7[19]|VOLVAL7[18]|VOLVAL7[17]|VOLVAL7[16]|
|||VOLVAL7[15]|VOLVAL7[14]|VOLVAL7[13]|VOLVAL7[11]|VOLVAL7[11]|VOLVAL7[10]|VOLVAL7[9]|VOLVAL7[8]|
|||VOLVAL7[7]|VOLVAL7[6]|VOLVAL7[5]|VOLVAL7[4]|VOLVAL7[3]|VOLVAL7[2]|VOLVAL7[1]|VOLVAL7[0]|
||DVUER_DVU0_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DVUEN|
||DVUSR_DVU0_1|-|-|-|-|-|-|-|-|
|||ZSTS7|ZSTS6|ZSTS5|ZSTS4|ZSTS3|ZSTS2|ZSTS1|ZSTS0|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|VRSTS[2]|VRSTS[1]|VRSTS[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|VEVMR_DVU0_1|VEVMZCM7|VEVMZCM6|VEVMZCM5|VEVMZCM4|VEVMZCM3|VEVMZCM2|VEVMZCM1|VEVMZCM0|
|||-|-|-|-|-|-|-|-|
|||VEVMVR|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||VEVCR_DVU0_1|VEVCZCM7|VEVCZCM6|VEVCZCM5|VEVCZCM4|VEVCZCM3|VEVCZCM2|VEVCZCM1|VEVCZCM0|
|||-|-|-|-|-|-|-|-|
|||VEVCVR|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||DVUIR_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||VADIR_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|OTBL[4]|OTBL[3]|OTBL[2]|OTBL[1]|OTBL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||DVUBR_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||DVUCR_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|VVMD|
|||-|-|-|VRMD|-|-|-|ZCMD|
||ZCMCR_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ZCEN7|ZCEN6|ZCEN5|ZCEN4|ZCEN3|ZCEN2|ZCEN1|ZCEN0|
||VRCTR_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||VREN7|VREN6|VREN5|VREN4|VREN3|VREN2|VREN1|VREN0|
||VRPDR_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|VRPDUP[4]|VRPDUP[3]|VRPDUP[1]|VRPDUP[1]|VRPDUP[0]|
|||-|-|-|VRPDDW[4]|VRPDDW[3]|VRPDDW[2]|VRPDDW[1]|VRPDDW[0]|
||VRDBR_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|VRDB[9]|VRDB[8]|
|||VRDB[7]|VRDB[6]|VRDB[5]|VRDB[4]|VRDB[3]|VRDB[2]|VRDB[1]|VRDB[0]|
||VRWTR_DVU0_2|-|-|-|-|-|-|-|-|
|||VRWT[23]|VRWT[22]|VRWT[21]|VRWT[20]|VRWT[19]|VRWT[18]|VRWT[17]|VRWT[16]|
|||VRWT[15]|VRWT[14]|VRWT[13]|VRWT[11]|VRWT[11]|VRWT[10]|VRWT[9]|VRWT[8]|
|||VRWT[7]|VRWT[6]|VRWT[5]|VRWT[4]|VRWT[3]|VRWT[2]|VRWT[1]|VRWT[0]|
||VOL0R_DVU0_2|-|-|-|-|-|-|-|-|
|||VOLVAL0[23]|VOLVAL0[22]|VOLVAL0[21]|VOLVAL0[20]|VOLVAL0[19]|VOLVAL0[18]|VOLVAL0[17]|VOLVAL0[16]|
|||VOLVAL0[15]|VOLVAL0[14]|VOLVAL0[13]|VOLVAL0[11]|VOLVAL0[11]|VOLVAL0[10]|VOLVAL0[9]|VOLVAL0[8]|
|||VOLVAL0[7]|VOLVAL0[6]|VOLVAL0[5]|VOLVAL0[4]|VOLVAL0[3]|VOLVAL0[2]|VOLVAL0[1]|VOLVAL0[0]|
||VOL1R_DVU0_2|-|-|-|-|-|-|-|-|
|||VOLVAL1[23]|VOLVAL1[22]|VOLVAL1[21]|VOLVAL1[20]|VOLVAL1[19]|VOLVAL1[18]|VOLVAL1[17]|VOLVAL1[16]|
|||VOLVAL1[15]|VOLVAL1[14]|VOLVAL1[13]|VOLVAL1[11]|VOLVAL1[11]|VOLVAL1[10]|VOLVAL1[9]|VOLVAL1[8]|
|||VOLVAL1[7]|VOLVAL1[6]|VOLVAL1[5]|VOLVAL1[4]|VOLVAL1[3]|VOLVAL1[2]|VOLVAL1[1]|VOLVAL1[0]|
||VOL2R_DVU0_2|-|-|-|-|-|-|-|-|
|||VOLVAL2[23]|VOLVAL2[22]|VOLVAL2[21]|VOLVAL2[20]|VOLVAL2[19]|VOLVAL2[18]|VOLVAL2[17]|VOLVAL2[16]|
|||VOLVAL2[15]|VOLVAL2[14]|VOLVAL2[13]|VOLVAL2[11]|VOLVAL2[11]|VOLVAL2[10]|VOLVAL2[9]|VOLVAL2[8]|
|||VOLVAL2[7]|VOLVAL2[6]|VOLVAL2[5]|VOLVAL2[4]|VOLVAL2[3]|VOLVAL2[2]|VOLVAL2[1]|VOLVAL2[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|VOL3R_DVU0_2|-|-|-|-|-|-|-|-|
|||VOLVAL3[23]|VOLVAL3[22]|VOLVAL3[21]|VOLVAL3[20]|VOLVAL3[19]|VOLVAL3[18]|VOLVAL3[17]|VOLVAL3[16]|
|||VOLVAL3[15]|VOLVAL3[14]|VOLVAL3[13]|VOLVAL3[11]|VOLVAL3[11]|VOLVAL3[10]|VOLVAL3[9]|VOLVAL3[8]|
|||VOLVAL3[7]|VOLVAL3[6]|VOLVAL3[5]|VOLVAL3[4]|VOLVAL3[3]|VOLVAL3[2]|VOLVAL3[1]|VOLVAL3[0]|
||VOL4R_DVU0_2|-|-|-|-|-|-|-|-|
|||VOLVAL4[23]|VOLVAL4[22]|VOLVAL4[21]|VOLVAL4[20]|VOLVAL4[19]|VOLVAL4[18]|VOLVAL4[17]|VOLVAL4[16]|
|||VOLVAL4[15]|VOLVAL4[14]|VOLVAL4[13]|VOLVAL4[11]|VOLVAL4[11]|VOLVAL4[10]|VOLVAL4[9]|VOLVAL4[8]|
|||VOLVAL4[7]|VOLVAL4[6]|VOLVAL4[5]|VOLVAL4[4]|VOLVAL4[3]|VOLVAL4[2]|VOLVAL4[1]|VOLVAL4[0]|
||VOL5R_DVU0_2|-|-|-|-|-|-|-|-|
|||VOLVAL5[23]|VOLVAL5[22]|VOLVAL5[21]|VOLVAL5[20]|VOLVAL5[19]|VOLVAL5[18]|VOLVAL5[17]|VOLVAL5[16]|
|||VOLVAL5[15]|VOLVAL5[14]|VOLVAL5[13]|VOLVAL5[11]|VOLVAL5[11]|VOLVAL5[10]|VOLVAL5[9]|VOLVAL5[8]|
|||VOLVAL5[7]|VOLVAL5[6]|VOLVAL5[5]|VOLVAL5[4]|VOLVAL5[3]|VOLVAL5[2]|VOLVAL5[1]|VOLVAL5[0]|
||VOL6R_DVU0_2|-|-|-|-|-|-|-|-|
|||VOLVAL6[23]|VOLVAL6[22]|VOLVAL6[21]|VOLVAL6[20]|VOLVAL6[19]|VOLVAL6[18]|VOLVAL6[17]|VOLVAL6[16]|
|||VOLVAL6[15]|VOLVAL6[14]|VOLVAL6[13]|VOLVAL6[11]|VOLVAL6[11]|VOLVAL6[10]|VOLVAL6[9]|VOLVAL6[8]|
|||VOLVAL6[7]|VOLVAL6[6]|VOLVAL6[5]|VOLVAL6[4]|VOLVAL6[3]|VOLVAL6[2]|VOLVAL6[1]|VOLVAL6[0]|
||VOL7R_DVU0_2|-|-|-|-|-|-|-|-|
|||VOLVAL7[23]|VOLVAL7[22]|VOLVAL7[21]|VOLVAL7[20]|VOLVAL7[19]|VOLVAL7[18]|VOLVAL7[17]|VOLVAL7[16]|
|||VOLVAL7[15]|VOLVAL7[14]|VOLVAL7[13]|VOLVAL7[11]|VOLVAL7[11]|VOLVAL7[10]|VOLVAL7[9]|VOLVAL7[8]|
|||VOLVAL7[7]|VOLVAL7[6]|VOLVAL7[5]|VOLVAL7[4]|VOLVAL7[3]|VOLVAL7[2]|VOLVAL7[1]|VOLVAL7[0]|
||DVUER_DVU0_2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DVUEN|
||DVUSR_DVU0_2|-|-|-|-|-|-|-|-|
|||ZSTS7|ZSTS6|ZSTS5|ZSTS4|ZSTS3|ZSTS2|ZSTS1|ZSTS0|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|VRSTS[2]|VRSTS[1]|VRSTS[0]|
||VEVMR_DVU0_2|VEVMZCM7|VEVMZCM6|VEVMZCM5|VEVMZCM4|VEVMZCM3|VEVMZCM2|VEVMZCM1|VEVMZCM0|
|||-|-|-|-|-|-|-|-|
|||VEVMVR|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||VEVCR_DVU0_2|VEVCZCM7|VEVCZCM6|VEVCZCM5|VEVCZCM4|VEVCZCM3|VEVCZCM2|VEVCZCM1|VEVCZCM0|
|||-|-|-|-|-|-|-|-|
|||VEVCVR|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||DVUIR_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||VADIR_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|OTBL[4]|OTBL[3]|OTBL[2]|OTBL[1]|OTBL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||DVUBR_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||DVUCR_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|VVMD|
|||-|-|-|VRMD|-|-|-|ZCMD|
||ZCMCR_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ZCEN7|ZCEN6|ZCEN5|ZCEN4|ZCEN3|ZCEN2|ZCEN1|ZCEN0|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|VRCTR_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||VREN7|VREN6|VREN5|VREN4|VREN3|VREN2|VREN1|VREN0|
||VRPDR_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|VRPDUP[4]|VRPDUP[3]|VRPDUP[1]|VRPDUP[1]|VRPDUP[0]|
|||-|-|-|VRPDDW[4]|VRPDDW[3]|VRPDDW[2]|VRPDDW[1]|VRPDDW[0]|
||VRDBR_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|VRDB[9]|VRDB[8]|
|||VRDB[7]|VRDB[6]|VRDB[5]|VRDB[4]|VRDB[3]|VRDB[2]|VRDB[1]|VRDB[0]|
||VRWTR_DVU0_3|-|-|-|-|-|-|-|-|
|||VRWT[23]|VRWT[22]|VRWT[21]|VRWT[20]|VRWT[19]|VRWT[18]|VRWT[17]|VRWT[16]|
|||VRWT[15]|VRWT[14]|VRWT[13]|VRWT[11]|VRWT[11]|VRWT[10]|VRWT[9]|VRWT[8]|
|||VRWT[7]|VRWT[6]|VRWT[5]|VRWT[4]|VRWT[3]|VRWT[2]|VRWT[1]|VRWT[0]|
||VOL0R_DVU0_3|-|-|-|-|-|-|-|-|
|||VOLVAL0[23]|VOLVAL0[22]|VOLVAL0[21]|VOLVAL0[20]|VOLVAL0[19]|VOLVAL0[18]|VOLVAL0[17]|VOLVAL0[16]|
|||VOLVAL0[15]|VOLVAL0[14]|VOLVAL0[13]|VOLVAL0[11]|VOLVAL0[11]|VOLVAL0[10]|VOLVAL0[9]|VOLVAL0[8]|
|||VOLVAL0[7]|VOLVAL0[6]|VOLVAL0[5]|VOLVAL0[4]|VOLVAL0[3]|VOLVAL0[2]|VOLVAL0[1]|VOLVAL0[0]|
||VOL1R_DVU0_3|-|-|-|-|-|-|-|-|
|||VOLVAL1[23]|VOLVAL1[22]|VOLVAL1[21]|VOLVAL1[20]|VOLVAL1[19]|VOLVAL1[18]|VOLVAL1[17]|VOLVAL1[16]|
|||VOLVAL1[15]|VOLVAL1[14]|VOLVAL1[13]|VOLVAL1[11]|VOLVAL1[11]|VOLVAL1[10]|VOLVAL1[9]|VOLVAL1[8]|
|||VOLVAL1[7]|VOLVAL1[6]|VOLVAL1[5]|VOLVAL1[4]|VOLVAL1[3]|VOLVAL1[2]|VOLVAL1[1]|VOLVAL1[0]|
||VOL2R_DVU0_3|-|-|-|-|-|-|-|-|
|||VOLVAL2[23]|VOLVAL2[22]|VOLVAL2[21]|VOLVAL2[20]|VOLVAL2[19]|VOLVAL2[18]|VOLVAL2[17]|VOLVAL2[16]|
|||VOLVAL2[15]|VOLVAL2[14]|VOLVAL2[13]|VOLVAL2[11]|VOLVAL2[11]|VOLVAL2[10]|VOLVAL2[9]|VOLVAL2[8]|
|||VOLVAL2[7]|VOLVAL2[6]|VOLVAL2[5]|VOLVAL2[4]|VOLVAL2[3]|VOLVAL2[2]|VOLVAL2[1]|VOLVAL2[0]|
||VOL3R_DVU0_3|-|-|-|-|-|-|-|-|
|||VOLVAL3[23]|VOLVAL3[22]|VOLVAL3[21]|VOLVAL3[20]|VOLVAL3[19]|VOLVAL3[18]|VOLVAL3[17]|VOLVAL3[16]|
|||VOLVAL3[15]|VOLVAL3[14]|VOLVAL3[13]|VOLVAL3[11]|VOLVAL3[11]|VOLVAL3[10]|VOLVAL3[9]|VOLVAL3[8]|
|||VOLVAL3[7]|VOLVAL3[6]|VOLVAL3[5]|VOLVAL3[4]|VOLVAL3[3]|VOLVAL3[2]|VOLVAL3[1]|VOLVAL3[0]|
||VOL4R_DVU0_3|-|-|-|-|-|-|-|-|
|||VOLVAL4[23]|VOLVAL4[22]|VOLVAL4[21]|VOLVAL4[20]|VOLVAL4[19]|VOLVAL4[18]|VOLVAL4[17]|VOLVAL4[16]|
|||VOLVAL4[15]|VOLVAL4[14]|VOLVAL4[13]|VOLVAL4[11]|VOLVAL4[11]|VOLVAL4[10]|VOLVAL4[9]|VOLVAL4[8]|
|||VOLVAL4[7]|VOLVAL4[6]|VOLVAL4[5]|VOLVAL4[4]|VOLVAL4[3]|VOLVAL4[2]|VOLVAL4[1]|VOLVAL4[0]|
||VOL5R_DVU0_3|-|-|-|-|-|-|-|-|
|||VOLVAL5[23]|VOLVAL5[22]|VOLVAL5[21]|VOLVAL5[20]|VOLVAL5[19]|VOLVAL5[18]|VOLVAL5[17]|VOLVAL5[16]|
|||VOLVAL5[15]|VOLVAL5[14]|VOLVAL5[13]|VOLVAL5[11]|VOLVAL5[11]|VOLVAL5[10]|VOLVAL5[9]|VOLVAL5[8]|
|||VOLVAL5[7]|VOLVAL5[6]|VOLVAL5[5]|VOLVAL5[4]|VOLVAL5[3]|VOLVAL5[2]|VOLVAL5[1]|VOLVAL5[0]|
||VOL6R_DVU0_3|-|-|-|-|-|-|-|-|
|||VOLVAL6[23]|VOLVAL6[22]|VOLVAL6[21]|VOLVAL6[20]|VOLVAL6[19]|VOLVAL6[18]|VOLVAL6[17]|VOLVAL6[16]|
|||VOLVAL6[15]|VOLVAL6[14]|VOLVAL6[13]|VOLVAL6[11]|VOLVAL6[11]|VOLVAL6[10]|VOLVAL6[9]|VOLVAL6[8]|
|||VOLVAL6[7]|VOLVAL6[6]|VOLVAL6[5]|VOLVAL6[4]|VOLVAL6[3]|VOLVAL6[2]|VOLVAL6[1]|VOLVAL6[0]|
||VOL7R_DVU0_3|-|-|-|-|-|-|-|-|
|||VOLVAL7[23]|VOLVAL7[22]|VOLVAL7[21]|VOLVAL7[20]|VOLVAL7[19]|VOLVAL7[18]|VOLVAL7[17]|VOLVAL7[16]|
|||VOLVAL7[15]|VOLVAL7[14]|VOLVAL7[13]|VOLVAL7[11]|VOLVAL7[11]|VOLVAL7[10]|VOLVAL7[9]|VOLVAL7[8]|
|||VOLVAL7[7]|VOLVAL7[6]|VOLVAL7[5]|VOLVAL7[4]|VOLVAL7[3]|VOLVAL7[2]|VOLVAL7[1]|VOLVAL7[0]|
||DVUER_DVU0_3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DVUEN|
||DVUSR_DVU0_3|-|-|-|-|-|-|-|-|
|||ZSTS7|ZSTS6|ZSTS5|ZSTS4|ZSTS3|ZSTS2|ZSTS1|ZSTS0|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|VRSTS[2]|VRSTS[1]|VRSTS[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|VEVMR_DVU0_3|VEVMZCM7|VEVMZCM6|VEVMZCM5|VEVMZCM4|VEVMZCM3|VEVMZCM2|VEVMZCM1|VEVMZCM0|
|||-|-|-|-|-|-|-|-|
|||VEVMVR|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||VEVCR_DVU0_3|VEVCZCM7|VEVCZCM6|VEVCZCM5|VEVCZCM4|VEVCZCM3|VEVCZCM2|VEVCZCM1|VEVCZCM0|
|||-|-|-|-|-|-|-|-|
|||VEVCVR|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-||
||MIXIR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|INIT|
||MADIR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CHNUM[3]|CHNUM[2]|CHNUM[1]|CHNUM[0]|
||MIXBR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|BPSYS[1]|BPSYS[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BYPASS|
||MIXMR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|MIXMODE|
||MVPDR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|MXPDUP[3]|MXPDUP[2]|MXPDUP[1]|MXPDUP[0]|
|||-|-|-|-|MXPDDW[3]|MXPDDW[2]|MXPDDW[1]|MXPDDW[0]|
||MDBAR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|MIXDBA[9]|MIXDBA[8]|
|||MIXDBA[7]|MIXDBA[6]|MIXDBA[5]|MIXDBA[4]|MIXDBA[3]|MIXDBA[2]|MIXDBA[1]|MIXDBA[0]|
||MDBBR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|MIXDBB[9]|MIXDBB[8]|
|||MIXDBB[7]|MIXDBB[6]|MIXDBB[5]|MIXDBB[4]|MIXDBB[3]|MIXDBB[2]|MIXDBB[1]|MIXDBB[0]|
||MDBCR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|MIXDBC[9]|MIXDBC[8]|
|||MIXDBC[7]|MIXDBC[6]|MIXDBC[5]|MIXDBC[4]|MIXDBC[3]|MIXDBC[2]|MIXDBC[1]|MIXDBC[0]|
||MDBDR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|MIXDBD[9]|MIXDBD[8]|
|||MIXDBD[7]|MIXDBD[6]|MIXDBD[5]|MIXDBD[4]|MIXDBD[3]|MIXDBD[2]|MIXDBD[1]|MIXDBD[0]|
||MDBER_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|MIXDBEN|
||MIXSR_MIX0_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|MIXSTS[1]|MIXSTS[0]|
||SWRSR_CIM|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SWRST|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|DMACR_CIM|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DMAMDFFU3|DMAMDFFU2|DMAMDFFU1|DMAMDFFU0|DMAMDFFD3|DMAMDFFD2|DMAMDFFD1|DMAMDFFD0|
||DMATD0_CIM|||||||||
|||||||||||
|||||||||||
|||||||||||
||DMATD1_CIM|||||||||
|||||||||||
|||||||||||
|||||||||||
||DMATD2_CIM|||||||||
|||||||||||
|||||||||||
|||||||||||
||DMATD3_CIM|||||||||
|||||||||||
|||||||||||
|||||||||||
||DMATU0_CIM|||||||||
|||||||||||
|||||||||||
|||||||||||
||DMATU1_CIM|||||||||
|||||||||||
|||||||||||
|||||||||||
||DMATU2_CIM|||||||||
|||||||||||
|||||||||||
|||||||||||
||DMATU3_CIM|||||||||
|||||||||||
|||||||||||
|||||||||||
||SSIRSEL_CIM|SISEL3[1]|SISEL3[0]|SISEL2[1]|SISEL2[0]|SISEL1[1]|SISEL1[0]|SISEL0[1]|SISEL0[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|SOSEL3[1]|SOSEL3[0]|-|-|SOSEL2[1]|SOSEL2[0]|
|||-|-|SOSEL1[1]|SOSEL1[0]|-|-|SOSEL0[1]|SOSEL0[0]|
||FDTSEL0_CIM|-|-|-|-|-|SCKDIV[11]|SCKDIV[10]|SCKDIV[9]|
|||SCKDIV[8]|SCKDIV[7]|SCKDIV[6]|SCKDIV[5]|SCKDIV[4]|SCKDIV[3]|SCKDIV[2]|SCKDIV[1]|
|||SCKDIV[0]|-|-|-|-|-|-|DIVEN|
|||-|-|-|-|SCKSEL[3]|SCKSEL[2]|SCKSEL[1]|SCKSEL[0]|
||FDTSEL1_CIM|-|-|-|-|-|SCKDIV[10]|SCKDIV[9]|SCKDIV[8]|
|||SCKDIV[7]|SCKDIV[6]|SCKDIV[5]|SCKDIV[4]|SCKDIV[3]|SCKDIV[2]|SCKDIV[1]|SCKDIV[0]|
|||-|-|-|-|-|-|-|DIVEN|
|||-|-|-|-|SCKSEL[3]|SCKSEL[2]|SCKSEL[1]|SCKSEL[0]|
||FDTSEL2_CIM|-|-|-|-|-|SCKDIV[10]|SCKDIV[9]|SCKDIV[8]|
|||SCKDIV[7]|SCKDIV[6]|SCKDIV[5]|SCKDIV[4]|SCKDIV[3]|SCKDIV[2]|SCKDIV[1]|SCKDIV[0]|
|||-|-|-|-|-|-|-|DIVEN|
|||-|-|-|-|SCKSEL[3]|SCKSEL[2]|SCKSEL[1]|SCKSEL[0]|
||FDTSEL3_CIM|-|-|-|-|-|SCKDIV[10]|SCKDIV[9]|SCKDIV[8]|
|||SCKDIV[7]|SCKDIV[6]|SCKDIV[5]|SCKDIV[4]|SCKDIV[3]|SCKDIV[2]|SCKDIV[1]|SCKDIV[0]|
|||-|-|-|-|-|-|-|DIVEN|
|||-|-|-|-|SCKSEL[3]|SCKSEL[2]|SCKSEL[1]|SCKSEL[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SCUX|FUTSEL0_CIM|-|-|-|-|-|SCKDIV[10]|SCKDIV[9]|SCKDIV[8]|
|||SCKDIV[7]|SCKDIV[6]|SCKDIV[5]|SCKDIV[4]|SCKDIV[3]|SCKDIV[2]|SCKDIV[1]|SCKDIV[0]|
|||-|-|-|-|-|-|-|DIVEN|
|||-|-|-|-|SCKSEL[3]|SCKSEL[2]|SCKSEL[1]|SCKSEL[0]|
||FUTSEL1_CIM|-|-|-|-|-|SCKDIV[10]|SCKDIV[9]|SCKDIV[8]|
|||SCKDIV[7]|SCKDIV[6]|SCKDIV[5]|SCKDIV[4]|SCKDIV[3]|SCKDIV[2]|SCKDIV[1]|SCKDIV[0]|
|||-|-|-|-|-|-|-|DIVEN|
|||-|-|-|-|SCKSEL[3]|SCKSEL[2]|SCKSEL[1]|SCKSEL[0]|
||FUTSEL2_CIM|-|-|-|-|-|SCKDIV[10]|SCKDIV[9]|SCKDIV[8]|
|||SCKDIV[7]|SCKDIV[6]|SCKDIV[5]|SCKDIV[4]|SCKDIV[3]|SCKDIV[2]|SCKDIV[1]|SCKDIV[0]|
|||-|-|-|-|-|-|-|DIVEN|
|||-|-|-|-|SCKSEL[3]|SCKSEL[2]|SCKSEL[1]|SCKSEL[0]|
||FUTSEL3_CIM|-|-|-|-|-|SCKDIV[10]|SCKDIV[9]|SCKDIV[8]|
|||SCKDIV[7]|SCKDIV[6]|SCKDIV[5]|SCKDIV[4]|SCKDIV[3]|SCKDIV[2]|SCKDIV[1]|SCKDIV[0]|
|||-|-|-|-|-|-|-|DIVEN|
|||-|-|-|-|SCKSEL[3]|SCKSEL[2]|SCKSEL[1]|SCKSEL[0]|
||SSIPMD_CIM|-|-|-|-|-|-|-|-|
|||-|-|-|-|SSI3CKS|SSI2CKS|SSI1CKS|SSI0CKS|
|||SSI3PMD[1]|SSI3PMD[0]|-|-|-|-|-|-|
|||-|-|-|SSI012EN|SSI2PMD[1]|SSI2PMD[0]|SSI1PMD[1]|SSI1PMD[0]|
||SSICTRL_CIM|-|SSI3TX|-|-|-|SSI3RX|-|-|
|||-|-|-|-|-|-|-|-|
|||-|SSI0TX|SSI1TX|SSI2TX|-|SSI0RX|SSI1RX|SSI2RX|
|||-|-|-|-|-|-|SSI012TEN|SSI012REN|
||SRCRSEL0_CIM|-|PLACE7[2]|PLACE7[1]|PLACE7[0]|-|PLACE6[2]|PLACE6[1]|PLACE6[0]|
|||-|PLACE5[2]|PLACE5[1]|PLACE5[0]|-|PLACE4[2]|PLACE4[1]|PLACE4[0]|
|||-|PLACE3[2]|PLACE3[1]|PLACE3[0]|-|PLACE2[2]|PLACE2[1]|PLACE2[0]|
|||-|PLACE1[2]|PLACE1[1]|PLACE1[0]|-|PLACE0[2]|PLACE0[1]|PLACE0[0]|
||SRCRSEL1_CIM|-|PLACE7[2]|PLACE7[1]|PLACE7[0]|-|PLACE6[2]|PLACE6[1]|PLACE6[0]|
|||-|PLACE5[2]|PLACE5[1]|PLACE5[0]|-|PLACE4[2]|PLACE4[1]|PLACE4[0]|
|||-|PLACE3[2]|PLACE3[1]|PLACE3[0]|-|PLACE2[2]|PLACE2[1]|PLACE2[0]|
|||-|PLACE1[2]|PLACE1[1]|PLACE1[0]|-|PLACE0[2]|PLACE0[1]|PLACE0[0]|
||SRCRSEL2_CIM|-|PLACE7[2]|PLACE7[1]|PLACE7[0]|-|PLACE6[2]|PLACE6[1]|PLACE6[0]|
|||-|PLACE5[2]|PLACE5[1]|PLACE5[0]|-|PLACE4[2]|PLACE4[1]|PLACE4[0]|
|||-|PLACE3[2]|PLACE3[1]|PLACE3[0]|-|PLACE2[2]|PLACE2[1]|PLACE2[0]|
|||-|PLACE1[2]|PLACE1[1]|PLACE1[0]|-|PLACE0[2]|PLACE0[1]|PLACE0[0]|
||SRCRSEL3_CIM|-|PLACE7[2]|PLACE7[1]|PLACE7[0]|-|PLACE6[2]|PLACE6[1]|PLACE6[0]|
|||-|PLACE5[2]|PLACE5[1]|PLACE5[0]|-|PLACE4[2]|PLACE4[1]|PLACE4[0]|
|||-|PLACE3[2]|PLACE3[1]|PLACE3[0]|-|PLACE2[2]|PLACE2[1]|PLACE2[0]|
|||-|PLACE1[2]|PLACE1[1]|PLACE1[0]|-|PLACE0[2]|PLACE0[1]|PLACE0[0]|
||MIXRSEL_CIM|-|PLACE7[2]|PLACE7[1]|PLACE7[0]|-|PLACE6[2]|PLACE6[1]|PLACE6[0]|
|||-|PLACE5[2]|PLACE5[1]|PLACE5[0]|-|PLACE4[2]|PLACE4[1]|PLACE4[0]|
|||-|PLACE3[2]|PLACE3[1]|PLACE3[0]|-|PLACE2[2]|PLACE2[1]|PLACE2[0]|
|||-|PLACE1[2]|PLACE1[1]|PLACE1[0]|-|PLACE0[2]|PLACE0[1]|PLACE0[0]|
|SD host interface|SD_CMD_0|MD[7]|MD[6]|MD[5]|MD[4]|MD[3]|MD[2]|MD[1]|MD[0]|
|||C[1]|C[0]|CF[45]|CF[44]|CF[43]|CF[42]|CF[41]|CF[40]|
||SD_ARG0_0|CF[23]|CF[22]|CF[21]|CF[20]|CF[19]|CF[18]|CF[17]|CF[16]|
|||CF[15]|CF[14]|CF[13]|CF[12]|CF[11]|CF[10]|CF[9]|CF[8]|
||SD_ARG1_0|CF[39]|CF[38]|CF[37]|CF[36]|CF[35]|CF[34]|CF[33]|CF[32]|
|||CF[31]|CF[30]|CF[29]|CF[28]|CF[27]|CF[26]|CF[25]|CF[24]|
||SD_STOP_0|-|-|-|-|-|-|-|SEC|
|||-|-|-|-|-|-|-|STP|
||SD_SECCNT_0|CNT[15]|CNT[14]|CNT[13]|CNT[12]|CNT[11]|CNT[10]|CNT[9]|CNT[8]|
|||CNT[7]|CNT[6]|CNT[5]|CNT[4]|CNT[3]|CNT[2]|CNT[1]|CNT[0]|
||SD_RSP00_0|R[23]|R[22]|R[21]|R[20]|R[19]|R[18]|R[17]|R[16]|
|||R[15]|R[14]|R[13]|R[12]|R[11]|R[10]|R[9]|R[8]|
||SD_RSP01_0|R[39]|R[38]|R[37]|R[36]|R[35]|R[34]|R[33]|R[32]|
|||R[31]|R[30]|R[29]|R[28]|R[27]|R[26]|R[25]|R[24]|
||SD_RSP02_0|R[55]|R[54]|R[53]|R[52]|R[51]|R[50]|R[49]|R[48]|
|||R[47]|R[46]|R[45]|R[44]|R[43]|R[42]|R[41]|R[40]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SD host interface|SD_RSP03_0|R[71]|R[70]|R[69]|R[68]|R[67]|R[66]|R[65]|R[64]|
|||R[63]|R[62]|R[61]|R[60]|R[59]|R[58]|R[57]|R[56]|
||SD_RSP04_0|R[87]|R[86]|R[85]|R[84]|R[83]|R[82]|R[81]|R[80]|
|||R[79]|R[78]|R[77]|R[76]|R[75]|R[74]|R[73]|R[72]|
||SD_RSP05_0|R[103]|R[102]|R[101]|R[100]|R[99]|R[98]|R[97]|R[96]|
|||R[95]|R[94]|R[93]|R[92]|R[91]|R[90]|R[89]|R[88]|
||SD_RSP06_0|R[119]|R[118]|R[117]|R[116]|R[115]|R[114]|R[113]|R[112]|
|||R[111]|R[110]|R[109]|R[108]|R[107]|R[106]|R[105]|R[104]|
||SD_RSP07_0|-|-|-|-|-|-|-|-|
|||R[127]|R[126]|R[125]|R[124]|R[123]|R[122]|R[121]|R[120]|
||SD_INFO1_0|-|-|-|-|-|INFO[10]|INFO[9]|INFO[8]|
|||INFO[7]|-|INFO[5]|INFO[4]|INFO[3]|INFO[2]|-|INFO[0]|
||SD_INFO2_0|ILA|CBSY|SCLKDIVEN|-|-|-|BWE|BRE|
|||DAT0|ERR[6]|ERR[5]|ERR[4]|ERR[3]|ERR[2]|ERR[1]|ERR[0]|
||SD_INFO1_MASK_0|-|-|-|-|-|-|IMASK[9]|IMASK[8]|
|||-|-|-|IMASK[4]|IMASK[3]|IMASK[2]|-|IMASK[0]|
||SD_INFO2_MASK_0|IMASK|-|-|-|-|-|BMASK[1]|BMASK[0]|
|||-|EMASK[6]|EMASK[5]|EMASK[4]|EMASK[3]|EMASK[2]|EMASK[1]|EMASK[0]|
||SD_CLK_CTRL_0|-|-|-|-|-|-|SDCLKOFFEN|SCLKEN|
|||DIV[7]|DIV[6]|DIV[5]|DIV[4]|DIV[3]|DIV[2]|DIV[1]|DIV[0]|
||SD_SIZE_0|-|-|-|-|-|-|LEN[9]|LEN[8]|
|||LEN[7]|LEN[6]|LEN[5]|LEN[4]|LEN[3]|LEN[2]|LEN[1]|LEN[0]|
||SD_OPTION_0|WIDTH|-|-|-|-|-|-|-|
|||TOP[27]|TOP[26]|TOP[25]|TOP[24]|CTOP[24]|CTOP[23]|CTOP[22]|CTOP[21]|
||SD_ERR_STS1_0|-|E[14]|E[13]|E[12]|E[11]|E[10]|E[9]|E[8]|
|||-|-|E[5]|E[4]|E[3]|E[2]|E[1]|E[0]|
||SD_ERR_STS2_0|-|-|-|-|-|-|-|-|
|||-|E[6]|E[5]|E[4]|E[3]|E[2]|E[1]|E[0]|
||SD_BUF0_0|BUF[31]|BUF[30]|BUF[29]|BUF[28]|BUF[27]|BUF[26]|BUF[25]|BUF[24]|
|||BUF[23]|BUF[22]|BUF[21]|BUF[20]|BUF[19]|BUF[18]|BUF[17]|BUF[16]|
|||BUF[15]|BUF[14]|BUF[13]|BUF[12]|BUF[11]|BUF[10]|BUF[9]|BUF[8]|
|||BUF[7]|BUF[6]|BUF[5]|BUF[4]|BUF[3]|BUF[2]|BUF[1]|BUF[0]|
||SDIO_MODE_0|-|-|-|-|-|-|C52PUB|IOABT|
|||-|-|-|-|-|RWREQ|-|IOMOD|
||SDIO_INFO1_0|EXWT|EXPUB52|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|IOIRQ|
||SDIO_INFO1_MASK<br>_0|MEXWT|MEXPUB52|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|IOMSK|
||CC_EXT_MODE_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|DMASDRW|-|
||SOFT_RST_0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SDRST|
||VERSION_0|-|-|-|-|UR[3]|UR[2]|UR[1]|UR[0]|
|||IP[7]|IP[6]|IP[5]|IP[4]|IP[3]|IP[2]|IP[1]|IP[0]|
||EXT_SWAP_0|-|-|-|-|-|-|-|DMASEL|
|||SDBRSWAP|SDBWSWAP|-|-|-|-|-|-|
||SD_CMD_1|MD[7]|MD[6]|MD[5]|MD[4]|MD[3]|MD[2]|MD[1]|MD[0]|
|||C[1]|C[0]|CF[45]|CF[44]|CF[43]|CF[42]|CF[41]|CF[40]|
||SD_ARG0_1|CF[23]|CF[22]|CF[21]|CF[20]|CF[19]|CF[18]|CF[17]|CF[16]|
|||CF[15]|CF[14]|CF[13]|CF[12]|CF[11]|CF[10]|CF[9]|CF[8]|
||SD_ARG1_1|CF[39]|CF[38]|CF[37]|CF[36]|CF[35]|CF[34]|CF[33]|CF[32]|
|||CF[31]|CF[30]|CF[29]|CF[28]|CF[27]|CF[26]|CF[25]|CF[24]|
||SD_STOP_1|-|-|-|-|-|-|-|SEC|
|||-|-|-|-|-|-|-|STP|
||SD_SECCNT_1|CNT[15]|CNT[14]|CNT[13]|CNT[12]|CNT[11]|CNT[10]|CNT[9]|CNT[8]|
|||CNT[7]|CNT[6]|CNT[5]|CNT[4]|CNT[3]|CNT[2]|CNT[1]|CNT[0]|
||SD_RSP00_1|R[23]|R[22]|R[21]|R[20]|R[19]|R[18]|R[17]|R[16]|
|||R[15]|R[14]|R[13]|R[12]|R[11]|R[10]|R[9]|R[8]|
||SD_RSP01_1|R[39]|R[38]|R[37]|R[36]|R[35]|R[34]|R[33]|R[32]|
|||R[31]|R[30]|R[29]|R[28]|R[27]|R[26]|R[25]|R[24]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|SD host interface|SD_RSP02_1|R[55]|R[54]|R[53]|R[52]|R[51]|R[50]|R[49]|R[48]|
|||R[47]|R[46]|R[45]|R[44]|R[43]|R[42]|R[41]|R[40]|
||SD_RSP03_1|R[71]|R[70]|R[69]|R[68]|R[67]|R[66]|R[65]|R[64]|
|||R[63]|R[62]|R[61]|R[60]|R[59]|R[58]|R[57]|R[56]|
||SD_RSP04_1|R[87]|R[86]|R[85]|R[84]|R[83]|R[82]|R[81]|R[80]|
|||R[79]|R[78]|R[77]|R[76]|R[75]|R[74]|R[73]|R[72]|
||SD_RSP05_1|R[103]|R[102]|R[101]|R[100]|R[99]|R[98]|R[97]|R[96]|
|||R[95]|R[94]|R[93]|R[92]|R[91]|R[90]|R[89]|R[88]|
||SD_RSP06_1|R[119]|R[118]|R[117]|R[116]|R[115]|R[114]|R[113]|R[112]|
|||R[111]|R[110]|R[109]|R[108]|R[107]|R[106]|R[105]|R[104]|
||SD_RSP07_1|-|-|-|-|-|-|-|-|
|||R[127]|R[126]|R[125]|R[124]|R[123]|R[122]|R[121]|R[120]|
||SD_INFO1_1|-|-|-|-|-|INFO[10]|INFO[9]|INFO[8]|
|||INFO[7]|-|INFO[5]|INFO[4]|INFO[3]|INFO[2]|-|INFO[0]|
||SD_INFO2_1|ILA|CBSY|SCLKDIVEN|-|-|-|BWE|BRE|
|||DAT0|ERR[6]|ERR[5]|ERR[4]|ERR[3]|ERR[2]|ERR[1]|ERR[0]|
||SD_INFO1_MASK_1|-|-|-|-|-|-|IMASK[9]|IMASK[8]|
|||-|-|-|IMASK[4]|IMASK[3]|IMASK[2]|-|IMASK[0]|
||SD_INFO2_MASK_1|IMASK|-|-|-|-|-|BMASK[1]|BMASK[0]|
|||-|EMASK[6]|EMASK[5]|EMASK[4]|EMASK[3]|EMASK[2]|EMASK[1]|EMASK[0]|
||SD_CLK_CTRL_1|-|-|-|-|-|-|SDCLKOFFEN|SCLKEN|
|||DIV[7]|DIV[6]|DIV[5]|DIV[4]|DIV[3]|DIV[2]|DIV[1]|DIV[0]|
||SD_SIZE_1|-|-|-|-|-|-|LEN[9]|LEN[8]|
|||LEN[7]|LEN[6]|LEN[5]|LEN[4]|LEN[3]|LEN[2]|LEN[1]|LEN[0]|
||SD_OPTION_1|WIDTH|-|-|-|-|-|-|-|
|||TOP[27]|TOP[26]|TOP[25]|TOP[24]|CTOP[24]|CTOP[23]|CTOP[22]|CTOP[21]|
||SD_ERR_STS1_1|-|E[14]|E[13]|E[12]|E[11]|E[10]|E[9]|E[8]|
|||-|-|E[5]|E[4]|E[3]|E[2]|E[1]|E[0]|
||SD_ERR_STS2_1|-|-|-|-|-|-|-|-|
|||-|E[6]|E[5]|E[4]|E[3]|E[2]|E[1]|E[0]|
||SD_BUF0_1|BUF[31]|BUF[30]|BUF[29]|BUF[28]|BUF[27]|BUF[26]|BUF[25]|BUF[24]|
|||BUF[23]|BUF[22]|BUF[21]|BUF[20]|BUF[19]|BUF[18]|BUF[17]|BUF[16]|
|||BUF[15]|BUF[14]|BUF[13]|BUF[12]|BUF[11]|BUF[10]|BUF[9]|BUF[8]|
|||BUF[7]|BUF[6]|BUF[5]|BUF[4]|BUF[3]|BUF[2]|BUF[1]|BUF[0]|
||SDIO_MODE_1|-|-|-|-|-|-|C52PUB|IOABT|
|||-|-|-|-|-|RWREQ|-|IOMOD|
||SDIO_INFO1_1|EXWT|EXPUB52|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|IOIRQ|
||SDIO_INFO1_MASK<br>_1|MEXWT|MEXPUB52|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|IOMSK|
||CC_EXT_MODE_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|DMASDRW|-|
||SOFT_RST_1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|SDRST|
||VERSION_1|-|-|-|-|UR[3]|UR[2]|UR[1]|UR[0]|
|||IP[7]|IP[6]|IP[5]|IP[4]|IP[3]|IP[2]|IP[1]|IP[0]|
||EXT_SWAP_1|-|-|-|-|-|-|-|DMASEL|
|||SDBRSWAP|SDBWSWAP|-|-|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|MMC host<br>interface|CE_CMD_SET|-|-|CMD[5]|CMD[4]|CMD[3]|CMD[2]|CMD[1]|CMD[0]|
|||RTYP[1]|RTYP[0]|RBSY|-|WDAT|DWEN|CMLTE|CMD12EN|
|||RIDXC[1]|RIDXC[0]|RCRC7C[1]|RCRC7C[0]|-|CRC16C|-|CRCSTE|
|||TBIT|OPDM|-|-|SBIT|-|DATW[1]|DATW[0]|
||CE_ARG|ARG[31]|ARG[30]|ARG[29]|ARG[28]|ARG[27]|ARG[26]|ARG[25]|ARG[24]|
|||ARG[23]|ARG[22]|ARG[21]|ARG[20]|ARG[19]|ARG[18]|ARG[17]|ARG[16]|
|||ARG[15]|ARG[14]|ARG[13]|ARG[12]|ARG[11]|ARG[10]|ARG[9]|ARG[8]|
|||ARG[7]|ARG[6]|ARG[5]|ARG[4]|ARG[3]|ARG[2]|ARG[1]|ARG[0]|
||CE_ARG_CMD12|C12ARG[31]|C12ARG[30]|C12ARG[29]|C12ARG[28]|C12ARG[27]|C12ARG[26]|C12ARG[25]|C12ARG[24]|
|||C12ARG[23]|C12ARG[22]|C12ARG[21]|C12ARG[20]|C12ARG[19]|C12ARG[18]|C12ARG[17]|C12ARG[16]|
|||C12ARG[15]|C12ARG[14]|C12ARG[13]|C12ARG[12]|C12ARG[11]|C12ARG[10]|C12ARG[9]|C12ARG[8]|
|||C12ARG[7]|C12ARG[6]|C12ARG[5]|C12ARG[4]|C12ARG[3]|C12ARG[2]|C12ARG[1]|C12ARG[0]|
||CE_CMD_CTRL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|BREAK|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|MMC host<br>interface|CE_BLOCK_SET|BLKCNT[15]|BLKCNT[14]|BLKCNT[13]|BLKCNT[12]|BLKCNT[11]|BLKCNT[10]|BLKCNT[9]|BLKCNT[8]|
|||BLKCNT[7]|BLKCNT[6]|BLKCNT[5]|BLKCNT[4]|BLKCNT[3]|BLKCNT[2]|BLKCNT[1]|BLKCNT[0]|
|||BLKSIZ[15]|BLKSIZ[14]|BLKSIZ[13]|BLKSIZ[12]|BLKSIZ[11]|BLKSIZ[10]|BLKSIZ[9]|BLKSIZ[8]|
|||BLKSIZ[7]|BLKSIZ[6]|BLKSIZ[5]|BLKSIZ[4]|BLKSIZ[3]|BLKSIZ[2]|BLKSIZ[1]|BLKSIZ[0]|
||CE_CLK_CTRL|-|-|-|-|-|-|-|CLKEN|
|||-|-|-|-|CLKDIV[3]|CLKDIV[2]|CLKDIV[1]|CLKDIV[0]|
|||-|-|SRSPTO[1]|SRSPTO[0]|SRBSYTO[3]|SRBSYTO[2]|SRBSYTO[1]|SRBSYTO[0]|
|||SRWDTO[3]|SRWDTO[2]|SRWDTO[1]|SRWDTO[0]|-|-|-|-|
||CE_BUF_ACC|-|-|-|-|-|-|DMAWEN|DMAREN|
|||-|-|-|-|-|-|BUSW|ATYP|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||CE_RESP3|RSP[127]|RSP[126]|RSP[125]|RSP[124]|RSP[123]|RSP[122]|RSP[121]|RSP[120]|
|||RSP[119]|RSP[118]|RSP[117]|RSP[116]|RSP[115]|RSP[114]|RSP[113]|RSP[112]|
|||RSP[111]|RSP[110]|RSP[109]|RSP[108]|RSP[107]|RSP[106]|RSP[105]|RSP[104]|
|||RSP[103]|RSP[102]|RSP[101]|RSP[100]|RSP[99]|RSP[98]|RSP[97]|RSP[96]|
||CE_RESP2|RSP[95]|RSP[94]|RSP[93]|RSP[92]|RSP[91]|RSP[90]|RSP[89]|RSP[88]|
|||RSP[87]|RSP[86]|RSP[85]|RSP[84]|RSP[83]|RSP[82]|RSP[81]|RSP[80]|
|||RSP[79]|RSP[78]|RSP[77]|RSP[76]|RSP[75]|RSP[74]|RSP[73]|RSP[72]|
|||RSP[71]|RSP[70]|RSP[69]|RSP[68]|RSP[67]|RSP[66]|RSP[65]|RSP[64]|
||CE_RESP1|RSP[63]|RSP[62]|RSP[61]|RSP[60]|RSP[59]|RSP[58]|RSP[57]|RSP[56]|
|||RSP[55]|RSP[54]|RSP[53]|RSP[52]|RSP[51]|RSP[50]|RSP[49]|RSP[48]|
|||RSP[47]|RSP[46]|RSP[45]|RSP[44]|RSP[43]|RSP[42]|RSP[41]|RSP[40]|
|||RSP[39]|RSP[38]|RSP[37]|RSP[36]|RSP[35]|RSP[34]|RSP[33]|RSP[32]|
||CE_RESP0|RSP[31]|RSP[30]|RSP[29]|RSP[28]|RSP[27]|RSP[26]|RSP[25]|RSP[24]|
|||RSP[23]|RSP[22]|RSP[21]|RSP[20]|RSP[19]|RSP[18]|RSP[17]|RSP[16]|
|||RSP[15]|RSP[14]|RSP[13]|RSP[12]|RSP[11]|RSP[10]|RSP[9]|RSP[8]|
|||RSP[7]|RSP[6]|RSP[5]|RSP[4]|RSP[3]|RSP[2]|RSP[1]|RSP[0]|
||CE_RESP_CMD12|RSP12[31]|RSP12[30]|RSP12[29]|RSP12[28]|RSP12[27]|RSP12[26]|RSP12[25]|RSP12[24]|
|||RSP12[23]|RSP12[22]|RSP12[21]|RSP12[20]|RSP12[19]|RSP12[18]|RSP12[17]|RSP12[16]|
|||RSP12[15]|RSP12[14]|RSP12[13]|RSP12[12]|RSP12[11]|RSP12[10]|RSP12[9]|RSP12[8]|
|||RSP12[7]|RSP12[6]|RSP12[5]|RSP12[4]|RSP12[3]|RSP12[2]|RSP12[1]|RSP12[0]|
||CE_DATA|DATA[31]|DATA[30]|DATA[29]|DATA[28]|DATA[27]|DATA[26]|DATA[25]|DATA[24]|
|||DATA[23]|DATA[22]|DATA[21]|DATA[20]|DATA[19]|DATA[18]|DATA[17]|DATA[16]|
|||DATA[15]|DATA[14]|DATA[13]|DATA[12]|DATA[11]|DATA[10]|DATA[9]|DATA[8]|
|||DATA[7]|DATA[6]|DATA[5]|DATA[4]|DATA[3]|DATA[2]|DATA[1]|DATA[0]|
||CE_INT|-|-|-|-|-|CMD12DRE|CMD12RBE|CMD12CRE|
|||DTRANE|BUFRE|BUFWEN|BUFREN|-|-|RBSYE|CRSPE|
|||CMDVIO|BUFVIO|-|-|WDATERR|RDATERR|RIDXERR|RSPERR|
|||-|-|-|CRCSTO|WDATTO|RDATTO|RBSYTO|RSPTO|
||CE_INT_EN|-|-|-|-|-|MCMD12DRE|MCMD12RBE|MCMD12CRE|
|||MDTRANE|MBUFRE|MBUFWEN|MBUFREN|-|-|MRBSYE|MCRSPE|
|||MCMDVIO|MBUFVIO|-|-|MWDATERR|MRDATERR|MRIDXERR|MRSPERR|
|||-|-|-|MCRCSTO|MWDATTO|MRDATTO|MRBSYTO|MRSPTO|
||CE_HOST_STS1|CMDSEQ|CMDSIG|RSPIDX[5]|RSPIDX[4]|RSPIDX[3]|RSPIDX[2]|RSPIDX[1]|RSPIDX[0]|
|||DATSIG[7]|DATSIG[6]|DATSIG[5]|DATSIG[4]|DATSIG[3]|DATSIG[2]|DATSIG[1]|DATSIG[0]|
|||RCVBLK[15]|RCVBLK[14]|RCVBLK[13]|RCVBLK[12]|RCVBLK[11]|RCVBLK[10]|RCVBLK[9]|RCVBLK[8]|
|||RCVBLK[7]|RCVBLK[6]|RCVBLK[5]|RCVBLK[4]|RCVBLK[3]|RCVBLK[2]|RCVBLK[1]|RCVBLK[0]|
||CE_HOST_STS2|CRCSTE|CRC16E|AC12CRCE|RSPCRC7E|CRCSTEBE|RDATEBE|AC12REBE|RSPEBE|
|||AC12IDXE|RSPIDXE|-|-|-|CRCST[2]|CRCST[1]|CRCST[0]|
|||-|STRDATTO|DATBSYTO|CRCSTTO|AC12BSYTO|RSPBSYTO|AC12RSPTO|STRSPTO|
|||-|-|-|-|-|-|-|-|
||CE_DMA_MODE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|DMASEL|
||CE_DETECT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|CDSIG|CDRISE|CDFALL|-|-|-|-|
|||-|-|MCDRISE|MCDFALL|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|MMC host<br>interface|CE_ADD_MODE|-|-|-|-|-|-|-|-|
|||-|-|-|-|CLKMAIN|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||CE_VERSION|SWRST|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||VERSION[15]|VERSION[14]|VERSION[13]|VERSION[12]|VERSION[11]|VERSION[10]|VERSION[9]|VERSION[8]|
|||VERSION[7]|VERSION[6]|VERSION[5]|VERSION[4]|VERSION[3]|VERSION[2]|VERSION[1]|VERSION[0]|
|Ports|P1|-|-|-|-|-|-|-|-|
|||P1[7]|P1[6]|P1[5]|P1[4]|P1[3]|P1[2]|P1[1]|P1[0]|
||P2|-|-|-|-|-|-|P2[9]|P2[8]|
|||P2[7]|P2[6]|P2[5]|P2[4]|P2[3]|P2[2]|P2[1]|P2[0]|
||P3|P3[15]|P3[14]|P3[13]|P3[12]|P3[11]|P3[10]|P3[9]|P3[8]|
|||P3[7]|P3[6]|P3[5]|P3[4]|P3[3]|P3[2]|P3[1]|P3[0]|
||P4|-|-|-|-|-|-|-|-|
|||P4[7]|P4[6]|P4[5]|P4[4]|P4[3]|P4[2]|P4[1]|P4[0]|
||P5|P5[15]|P5[14]|P5[13]|P5[12]|P5[11]|P5[10]|P5[9]|P5[8]|
|||P5[7]|P5[6]|P5[5]|P5[4]|P5[3]|P5[2]|P5[1]|P5[0]|
||P6|P6[15]|P6[14]|P6[13]|P6[12]|P6[11]|P6[10]|P6[9]|P6[8]|
|||P6[7]|P6[6]|P6[5]|P6[4]|P6[3]|P6[2]|P6[1]|P6[0]|
||P7|-|-|-|-|P7[11]|P7[10]|P7[9]|P7[8]|
|||P7[7]|P7[6]|P7[5]|P7[4]|P7[3]|P7[2]|P7[1]|P7[0]|
||P8|P8[15]|P8[14]|P8[13]|P8[12]|P8[11]|P8[10]|P8[9]|P8[8]|
|||P8[7]|P8[6]|P8[5]|P8[4]|P8[3]|P8[2]|P8[1]|P8[0]|
||P9|-|-|-|-|-|-|-|-|
|||-|-|P9[5]|P9[4]|P9[3]|P9[2]|P9[1]|P9[0]|
||PSR1|-|-|-|-|-|-|-|-|
|||PSR1[23]|PSR1[22]|PSR1[21]|PSR1[20]|PSR1[19]|PSR1[18]|PSR1[17]|PSR1[16]|
|||-|-|-|-|-|-|-|-|
|||PSR1[7]|PSR1[6]|PSR1[5]|PSR1[4]|PSR1[3]|PSR1[2]|PSR1[1]|PSR1[0]|
||PSR2|-|-|-|-|-|-|PSR2[25]|PSR2[24]|
|||PSR2[23]|PSR2[22]|PSR2[21]|PSR2[20]|PSR2[19]|PSR2[18]|PSR2[17]|PSR2[16]|
|||-|-|-|-|-|-|PSR2[9]|PSR2[8]|
|||PSR2[7]|PSR2[6]|PSR2[5]|PSR2[4]|PSR2[3]|PSR2[2]|PSR2[1]|PSR2[0]|
||PSR3|PSR3[31]|PSR3[30]|PSR3[29]|PSR3[28]|PSR3[27]|PSR3[26]|PSR3[25]|PSR3[24]|
|||PSR3[23]|PSR3[22]|PSR3[21]|PSR3[20]|PSR3[19]|PSR3[18]|PSR3[17]|PSR3[16]|
|||PSR3[15]|PSR3[14]|PSR3[13]|PSR3[12]|PSR3[11]|PSR3[10]|PSR3[9]|PSR3[8]|
|||PSR3[7]|PSR3[6]|PSR3[5]|PSR3[4]|PSR3[3]|PSR3[2]|PSR3[1]|PSR3[0]|
||PSR4|-|-|-|-|-|-|-|-|
|||PSR4[23]|PSR4[22]|PSR4[21]|PSR4[20]|PSR4[19]|PSR4[18]|PSR4[17]|PSR4[16]|
|||-|-|-|-|-|-|-|-|
|||PSR4[7]|PSR4[6]|PSR4[5]|PSR4[4]|PSR4[3]|PSR4[2]|PSR4[1]|PSR4[0]|
||PSR5|PSR5[31]|PSR5[30]|PSR5[29]|PSR5[28]|PSR5[27]|PSR5[26]|PSR5[25]|PSR5[24]|
|||PSR5[23]|PSR5[22]|PSR5[21]|PSR5[20]|PSR5[19]|PSR5[18]|PSR5[17]|PSR5[16]|
|||PSR5[15]|PSR5[14]|PSR5[13]|PSR5[12]|PSR5[11]|PSR5[10]|PSR5[9]|PSR5[8]|
|||PSR5[7]|PSR5[6]|PSR5[5]|PSR5[4]|PSR5[3]|PSR5[2]|PSR5[1]|PSR5[0]|
||PSR6|PSR6[31]|PSR6[30]|PSR6[29]|PSR6[28]|PSR6[27]|PSR6[26]|PSR6[25]|PSR6[24]|
|||PSR6[23]|PSR6[22]|PSR6[21]|PSR6[20]|PSR6[19]|PSR6[18]|PSR6[17]|PSR6[16]|
|||PSR6[15]|PSR6[14]|PSR6[13]|PSR6[12]|PSR6[11]|PSR6[10]|PSR6[9]|PSR6[8]|
|||PSR6[7]|PSR6[6]|PSR6[5]|PSR6[4]|PSR6[3]|PSR6[2]|PSR6[1]|PSR6[0]|
||PSR7|-|-|-|-|PSR7[27]|PSR7[26]|PSR7[25]|PSR7[24]|
|||PSR7[23]|PSR7[22]|PSR7[21]|PSR7[20]|PSR7[19]|PSR7[18]|PSR7[17]|PSR7[16]|
|||-|-|-|-|PSR7[11]|PSR7[10]|PSR7[9]|PSR7[8]|
|||PSR7[7]|PSR7[6]|PSR7[5]|PSR7[4]|PSR7[3]|PSR7[2]|PSR7[1]|PSR7[0]|
||PSR8|PSR8[31]|PSR8[30]|PSR8[29]|PSR8[28]|PSR8[27]|PSR8[26]|PSR8[25]|PSR8[24]|
|||PSR8[23]|PSR8[22]|PSR8[21]|PSR8[20]|PSR8[19]|PSR8[18]|PSR8[17]|PSR8[16]|
|||PSR8[15]|PSR8[14]|PSR8[13]|PSR8[12]|PSR8[11]|PSR8[10]|PSR8[9]|PSR8[8]|
|||PSR8[7]|PSR8[6]|PSR8[5]|PSR8[4]|PSR8[3]|PSR8[2]|PSR8[1]|PSR8[0]|

**Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ports|PSR9|-|-|-|-|-|-|-|-|
|||-|-|PSR9[21]|PSR9[20]|PSR9[19]|PSR9[18]|PSR9[17]|PSR9[16]|
|||-|-|-|-|-|-|-|-|
|||-|-|PSR9[5]|PSR9[4]|PSR9[3]|PSR9[2]|PSR9[1]|PSR9[0]|
||PPR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|PPR0[3]|PPR0[2]|PPR0[1]|PPR0[0]|
||PPR1|PPR1[15]|PPR1[14]|PPR1[13]|PPR1[12]|PPR1[11]|PPR1[10]|PPR1[9]|PPR1[8]|
|||PPR1[7]|PPR1[6]|PPR1[5]|PPR1[4]|PPR1[3]|PPR1[2]|PPR1[1]|PPR1[0]|
||PPR2|-|-|-|-|-|-|PPR2[9]|PPR2[8]|
|||PPR2[7]|PPR2[6]|PPR2[5]|PPR2[4]|PPR2[3]|PPR2[2]|PPR2[1]|PPR2[0]|
||PPR3|PPR3[15]|PPR3[14]|PPR3[13]|PPR3[12]|PPR3[11]|PPR3[10]|PPR3[9]|PPR3[8]|
|||PPR3[7]|PPR3[6]|PPR3[5]|PPR3[4]|PPR3[3]|PPR3[2]|PPR3[1]|PPR3[0]|
||PPR4|-|-|-|-|-|-|-|-|
|||PPR4[7]|PPR4[6]|PPR4[5]|PPR4[4]|PPR4[3]|PPR4[2]|PPR4[1]|PPR4[0]|
||PPR5|PPR5[15]|PPR5[14]|PPR5[13]|PPR5[12]|PPR5[11]|PPR5[10]|PPR5[9]|PPR5[8]|
|||PPR5[7]|PPR5[6]|PPR5[5]|PPR5[4]|PPR5[3]|PPR5[2]|PPR5[1]|PPR5[0]|
||PPR6|PPR6[15]|PPR6[14]|PPR6[13]|PPR6[12]|PPR6[11]|PPR6[10]|PPR6[9]|PPR6[8]|
|||PPR6[7]|PPR6[6]|PPR6[5]|PPR6[4]|PPR6[3]|PPR6[2]|PPR6[1]|PPR6[0]|
||PPR7|-|-|-|-|PPR7[11]|PPR7[10]|PPR7[9]|PPR7[8]|
|||PPR7[7]|PPR7[6]|PPR7[5]|PPR7[4]|PPR7[3]|PPR7[2]|PPR7[1]|PPR7[0]|
||PPR8|PPR8[15]|PPR8[14]|PPR8[13]|PPR8[12]|PPR8[11]|PPR8[10]|PPR8[9]|PPR8[8]|
|||PPR8[7]|PPR8[6]|PPR8[5]|PPR8[4]|PPR8[3]|PPR8[2]|PPR8[1]|PPR8[0]|
||PPR9|-|-|-|-|-|-|-|-|
|||-|-|PPR9[5]|PPR9[4]|PPR9[3]|PPR9[2]|PPR9[1]|PPR9[0]|
||PM1|-|-|-|-|-|-|-|-|
|||PM1[7]|PM1[6]|PM1[5]|PM1[4]|PM1[3]|PM1[2]|PM1[1]|PM1[0]|
||PM2|-|-|-|-|-|-|PM2[9]|PM2[8]|
|||PM2[7]|PM2[6]|PM2[5]|PM2[4]|PM2[3]|PM2[2]|PM2[1]|PM2[0]|
||PM3|PM3[15]|PM3[14]|PM3[13]|PM3[12]|PM3[11]|PM3[10]|PM3[9]|PM3[8]|
|||PM3[7]|PM3[6]|PM3[5]|PM3[4]|PM3[3]|PM3[2]|PM3[1]|PM3[0]|
||PM4|-|-|-|-|-|-|-|-|
|||PM4[7]|PM4[6]|PM4[5]|PM4[4]|PM4[3]|PM4[2]|PM4[1]|PM4[0]|
||PM5|PM5[15]|PM5[14]|PM5[13]|PM5[12]|PM5[11]|PM5[10]|PM5[9]|PM5[8]|
|||PM5[7]|PM5[6]|PM5[5]|PM5[4]|PM5[3]|PM5[2]|PM5[1]|PM5[0]|
||PM6|PM6[15]|PM6[14]|PM6[13]|PM6[12]|PM6[11]|PM6[10]|PM6[9]|PM6[8]|
|||PM6[7]|PM6[6]|PM6[5]|PM6[4]|PM6[3]|PM6[2]|PM6[1]|PM6[0]|
||PM7|-|-|-|-|PM7[11]|PM7[10]|PM7[9]|PM7[8]|
|||PM7[7]|PM7[6]|PM7[5]|PM7[4]|PM7[3]|PM7[2]|PM7[1]|PM7[0]|
||PM8|PM8[15]|PM8[14]|PM8[13]|PM8[12]|PM8[11]|PM8[10]|PM8[9]|PM8[8]|
|||PM8[7]|PM8[6]|PM8[5]|PM8[4]|PM8[3]|PM8[2]|PM8[1]|PM8[0]|
||PM9|-|-|-|-|-|-|-|-|
|||-|-|PM9[5]|PM9[4]|PM9[3]|PM9[2]|PM9[1]|PM9[0]|
||PMC0|-|-|-|-|-|-|-|-|
|||-|-|-|-|PMC0[3]|PMC0[2]|PMC0[1]|PMC0[0]|
||PMC1|PMC1[15]|PMC1[14]|PMC1[13]|PMC1[12]|PMC1[11]|PMC1[10]|PMC1[9]|PMC1[8]|
|||PMC1[7]|PMC1[6]|PMC1[5]|PMC1[4]|PMC1[3]|PMC1[2]|PMC1[1]|PMC1[0]|
||PMC2|-|-|-|-|-|-|PMC2[9]|PMC2[8]|
|||PMC2[7]|PMC2[6]|PMC2[5]|PMC2[4]|PMC2[3]|PMC2[2]|PMC2[1]|PMC2[0]|
||PMC3|PMC3[15]|PMC3[14]|PMC3[13]|PMC3[12]|PMC3[11]|PMC3[10]|PMC3[9]|PMC3[8]|
|||PMC3[7]|PMC3[6]|PMC3[5]|PMC3[4]|PMC3[3]|PMC3[2]|PMC3[1]|PMC3[0]|
||PMC4|-|-|-|-|-|-|-|-|
|||PMC4[7]|PMC4[6]|PMC4[5]|PMC4[4]|PMC4[3]|PMC4[2]|PMC4[1]|PMC4[0]|
||PMC5|PMC5[15]|PMC5[14]|PMC5[13]|PMC5[12]|PMC5[11]|PMC5[10]|PMC5[9]|PMC5[8]|
|||PMC5[7]|PMC5[6]|PMC5[5]|PMC5[4]|PMC5[3]|PMC5[2]|PMC5[1]|PMC5[0]|
||PMC6|PMC6[15]|PMC6[14]|PMC6[13]|PMC6[12]|PMC6[11]|PMC6[10]|PMC6[9]|PMC6[8]|
|||PMC6[7]|PMC6[6]|PMC6[5]|PMC6[4]|PMC6[3]|PMC6[2]|PMC6[1]|PMC6[0]|
||PMC7|-|-|-|-|PMC7[11]|PMC7[10]|PMC7[9]|PMC7[8]|
|||PMC7[7]|PMC7[6]|PMC7[5]|PMC7[4]|PMC7[3]|PMC7[2]|PMC7[1]|PMC7[0]|
||PMC8|PMC8[15]|PMC8[14]|PMC8[13]|PMC8[12]|PMC8[11]|PMC8[10]|PMC8[9]|PMC8[8]|
|||PMC8[7]|PMC8[6]|PMC8[5]|PMC8[4]|PMC8[3]|PMC8[2]|PMC8[1]|PMC8[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ports|PMC9|-|-|-|-|-|-|-|-|
|||-|-|PMC9[5]|PMC9[4]|PMC9[3]|PMC9[2]|PMC9[1]|PMC9[0]|
||PFC0|-|-|-|-|-|-|-|-|
|||-|-|-|-|PFC0[3]|PFC0[2]|PFC0[1]|PFC0[0]|
||PFC1|PFC1[15]|PFC1[14]|PFC1[13]|PFC1[12]|PFC1[11]|PFC1[10]|PFC1[9]|PFC1[8]|
|||PFC1[7]|PFC1[6]|PFC1[5]|PFC1[4]|PFC1[3]|PFC1[2]|PFC1[1]|PFC1[0]|
||PFC2|-|-|-|-|-|-|PFC2[9]|PFC2[8]|
|||PFC2[7]|PFC2[6]|PFC2[5]|PFC2[4]|PFC2[3]|PFC2[2]|PFC2[1]|PFC2[0]|
||PFC3|PFC3[15]|PFC3[14]|PFC3[13]|PFC3[12]|PFC3[11]|PFC3[10]|PFC3[9]|PFC3[8]|
|||PFC3[7]|PFC3[6]|PFC3[5]|PFC3[4]|PFC3[3]|PFC3[2]|PFC3[1]|PFC3[0]|
||PFC4|-|-|-|-|-|-|-|-|
|||PFC4[7]|PFC4[6]|PFC4[5]|PFC4[4]|PFC4[3]|PFC4[2]|PFC4[1]|PFC4[0]|
||PFC5|PFC5[15]|PFC5[14]|PFC5[13]|PFC5[12]|PFC5[11]|PFC5[10]|PFC5[9]|PFC5[8]|
|||PFC5[7]|PFC5[6]|PFC5[5]|PFC5[4]|PFC5[3]|PFC5[2]|PFC5[1]|PFC5[0]|
||PFC6|PFC6[15]|PFC6[14]|PFC6[13]|PFC6[12]|PFC6[11]|PFC6[10]|PFC6[9]|PFC6[8]|
|||PFC6[7]|PFC6[6]|PFC6[5]|PFC6[4]|PFC6[3]|PFC6[2]|PFC6[1]|PFC6[0]|
||PFC7|-|-|-|-|PFC7[11]|PFC7[10]|PFC7[9]|PFC7[8]|
|||PFC7[7]|PFC7[6]|PFC7[5]|PFC7[4]|PFC7[3]|PFC7[2]|PFC7[1]|PFC7[0]|
||PFC8|PFC8[15]|PFC8[14]|PFC8[13]|PFC8[12]|PFC8[11]|PFC8[10]|PFC8[9]|PFC8[8]|
|||PFC8[7]|PFC8[6]|PFC8[5]|PFC8[4]|PFC8[3]|PFC8[2]|PFC8[1]|PFC8[0]|
||PFC9|-|-|-|-|-|-|-|-|
|||-|-|PFC9[5]|PFC9[4]|PFC9[3]|PFC9[2]|PFC9[1]|PFC9[0]|
||PFCE0|-|-|-|-|-|-|-|-|
|||-|-|-|-|PFCE0[3]|PFCE0[2]|PFCE0[1]|PFCE0[0]|
||PFCE1|PFCE1[15]|PFCE1[14]|PFCE1[13]|PFCE1[12]|PFCE1[11]|PFCE1[10]|PFCE1[9]|PFCE1[8]|
|||PFCE1[7]|PFCE1[6]|PFCE1[5]|PFCE1[4]|PFCE1[3]|PFCE1[2]|PFCE1[1]|PFCE1[0]|
||PFCE2|-|-|-|-|-|-|PFCE2[9]|PFCE2[8]|
|||PFCE2[7]|PFCE2[6]|PFCE2[5]|PFCE2[4]|PFCE2[3]|PFCE2[2]|PFCE2[1]|PFCE2[0]|
||PFCE3|PFCE3[15]|PFCE3[14]|PFCE3[13]|PFCE3[12]|PFCE3[11]|PFCE3[10]|PFCE3[9]|PFCE3[8]|
|||PFCE3[7]|PFCE3[6]|PFCE3[5]|PFCE3[4]|PFCE3[3]|PFCE3[2]|PFCE3[1]|PFCE3[0]|
||PFCE4|-|-|-|-|-|-|-|-|
|||PFCE4[7]|PFCE4[6]|PFCE4[5]|PFCE4[4]|PFCE4[3]|PFCE4[2]|PFCE4[1]|PFCE4[0]|
||PFCE5|PFCE5[15]|PFCE5[14]|PFCE5[13]|PFCE5[12]|PFCE5[11]|PFCE5[10]|PFCE5[9]|PFCE5[8]|
|||PFCE5[7]|PFCE5[6]|PFCE5[5]|PFCE5[4]|PFCE5[3]|PFCE5[2]|PFCE5[1]|PFCE5[0]|
||PFCE6|PFCE6[15]|PFCE6[14]|PFCE6[13]|PFCE6[12]|PFCE6[11]|PFCE6[10]|PFCE6[9]|PFCE6[8]|
|||PFCE6[7]|PFCE6[6]|PFCE6[5]|PFCE6[4]|PFCE6[3]|PFCE6[2]|PFCE6[1]|PFCE6[0]|
||PFCE7|-|-|-|-|PFCE7[11]|PFCE7[10]|PFCE7[9]|PFCE7[8]|
|||PFCE7[7]|PFCE7[6]|PFCE7[5]|PFCE7[4]|PFCE7[3]|PFCE7[2]|PFCE7[1]|PFCE7[0]|
||PFCE8|PFCE8[15]|PFCE8[14]|PFCE8[13]|PFCE8[12]|PFCE8[11]|PFCE8[10]|PFCE8[9]|PFCE8[8]|
|||PFCE8[7]|PFCE8[6]|PFCE8[5]|PFCE8[4]|PFCE8[3]|PFCE8[2]|PFCE8[1]|PFCE8[0]|
||PFCE9|-|-|-|-|-|-|-|-|
|||-|-|PFCE9[5]|PFCE9[4]|PFCE9[3]|PFCE9[2]|PFCE9[1]|PFCE9[0]|
||PNOT1|-|-|-|-|-|-|-|-|
|||PNOT1[7]|PNOT1[6]|PNOT1[5]|PNOT1[4]|PNOT1[3]|PNOT1[2]|PNOT1[1]|PNOT1[0]|
||PNOT2|-|-|-|-|-|-|PNOT2[9]|PNOT2[8]|
|||PNOT2[7]|PNOT2[6]|PNOT2[5]|PNOT2[4]|PNOT2[3]|PNOT2[2]|PNOT2[1]|PNOT2[0]|
||PNOT3|PNOT3[15]|PNOT3[14]|PNOT3[13]|PNOT3[12]|PNOT3[11]|PNOT3[10]|PNOT3[9]|PNOT3[8]|
|||PNOT3[7]|PNOT3[6]|PNOT3[5]|PNOT3[4]|PNOT3[3]|PNOT3[2]|PNOT3[1]|PNOT3[0]|
||PNOT4|-|-|-|-|-|-|-|-|
|||PNOT4[7]|PNOT4[6]|PNOT4[5]|PNOT4[4]|PNOT4[3]|PNOT4[2]|PNOT4[1]|PNOT4[0]|
||PNOT5|PNOT5[15]|PNOT5[14]|PNOT5[13]|PNOT5[12]|PNOT5[11]|PNOT5[10]|PNOT5[9]|PNOT5[8]|
|||PNOT5[7]|PNOT5[6]|PNOT5[5]|PNOT5[4]|PNOT5[3]|PNOT5[2]|PNOT5[1]|PNOT5[0]|
||PNOT6|PNOT6[15]|PNOT6[14]|PNOT6[13]|PNOT6[12]|PNOT6[11]|PNOT6[10]|PNOT6[9]|PNOT6[8]|
|||PNOT6[7]|PNOT6[6]|PNOT6[5]|PNOT6[4]|PNOT6[3]|PNOT6[2]|PNOT6[1]|PNOT6[0]|
||PNOT7|-|-|-|-|PNOT7[11]|PNOT7[10]|PNOT7[9]|PNOT7[8]|
|||PNOT7[7]|PNOT7[6]|PNOT7[5]|PNOT7[4]|PNOT7[3]|PNOT7[2]|PNOT7[1]|PNOT7[0]|
||PNOT8|PNOT8[15]|PNOT8[14]|PNOT8[13]|PNOT8[12]|PNOT8[11]|PNOT8[10]|PNOT8[9]|PNOT8[8]|
|||PNOT8[7]|PNOT8[6]|PNOT8[5]|PNOT8[4]|PNOT8[3]|PNOT8[2]|PNOT8[1]|PNOT8[0]|
||PNOT9|-|-|-|-|-|-|-|-|
|||-|-|PNOT9[5]|PNOT9[4]|PNOT9[3]|PNOT9[2]|PNOT9[1]|PNOT9[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ports|PMSR1|-|-|-|-|-|-|-|-|
|||PMSR1[23]|PMSR1[22]|PMSR1[21]|PMSR1[20]|PMSR1[19]|PMSR1[18]|PMSR1[17]|PMSR1[16]|
|||-|-|-|-|-|-|-|-|
|||PMSR1[7]|PMSR1[6]|PMSR1[5]|PMSR1[4]|PMSR1[3]|PMSR1[2]|PMSR1[1]|PMSR1[0]|
||PMSR2|-|-|-|-|-|-|PMSR2[25]|PMSR2[24]|
|||PMSR2[23]|PMSR2[22]|PMSR2[21]|PMSR2[20]|PMSR2[19]|PMSR2[18]|PMSR2[17]|PMSR2[16]|
|||-|-|-|-|-|-|PMSR2[9]|PMSR2[8]|
|||PMSR2[7]|PMSR2[6]|PMSR2[5]|PMSR2[4]|PMSR2[3]|PMSR2[2]|PMSR2[1]|PMSR2[0]|
||PMSR3|PMSR3[31]|PMSR3[30]|PMSR3[29]|PMSR3[28]|PMSR3[27]|PMSR3[26]|PMSR3[25]|PMSR3[24]|
|||PMSR3[23]|PMSR3[22]|PMSR3[21]|PMSR3[20]|PMSR3[19]|PMSR3[18]|PMSR3[17]|PMSR3[16]|
|||PMSR3[15]|PMSR3[14]|PMSR3[13]|PMSR3[12]|PMSR3[11]|PMSR3[10]|PMSR3[9]|PMSR3[8]|
|||PMSR3[7]|PMSR3[6]|PMSR3[5]|PMSR3[4]|PMSR3[3]|PMSR3[2]|PMSR3[1]|PMSR3[0]|
||PMSR4|-|-|-|-|-|-|-|-|
|||PMSR4[23]|PMSR4[22]|PMSR4[21]|PMSR4[20]|PMSR4[19]|PMSR4[18]|PMSR4[17]|PMSR4[16]|
|||-|-|-|-|-|-|-|-|
|||PMSR4[7]|PMSR4[6]|PMSR4[5]|PMSR4[4]|PMSR4[3]|PMSR4[2]|PMSR4[1]|PMSR4[0]|
||PMSR5|PMSR5[31]|PMSR5[30]|PMSR5[29]|PMSR5[28]|PMSR5[27]|PMSR5[26]|PMSR5[25]|PMSR5[24]|
|||PMSR5[23]|PMSR5[22]|PMSR5[21]|PMSR5[20]|PMSR5[19]|PMSR5[18]|PMSR5[17]|PMSR5[16]|
|||PMSR5[15]|PMSR5[14]|PMSR5[13]|PMSR5[12]|PMSR5[11]|PMSR5[10]|PMSR5[9]|PMSR5[8]|
|||PMSR5[7]|PMSR5[6]|PMSR5[5]|PMSR5[4]|PMSR5[3]|PMSR5[2]|PMSR5[1]|PMSR5[0]|
||PMSR6|PMSR6[31]|PMSR6[30]|PMSR6[29]|PMSR6[28]|PMSR6[27]|PMSR6[26]|PMSR6[25]|PMSR6[24]|
|||PMSR6[23]|PMSR6[22]|PMSR6[21]|PMSR6[20]|PMSR6[19]|PMSR6[18]|PMSR6[17]|PMSR6[16]|
|||PMSR6[15]|PMSR6[14]|PMSR6[13]|PMSR6[12]|PMSR6[11]|PMSR6[10]|PMSR6[9]|PMSR6[8]|
|||PMSR6[7]|PMSR6[6]|PMSR6[5]|PMSR6[4]|PMSR6[3]|PMSR6[2]|PMSR6[1]|PMSR6[0]|
||PMSR7|-|-|-|-|PMSR7[27]|PMSR7[26]|PMSR7[25]|PMSR7[24]|
|||PMSR7[23]|PMSR7[22]|PMSR7[21]|PMSR7[20]|PMSR7[19]|PMSR7[18]|PMSR7[17]|PMSR7[16]|
|||-|-|-|-|PMSR7[11]|PMSR7[10]|PMSR7[9]|PMSR7[8]|
|||PMSR7[7]|PMSR7[6]|PMSR7[5]|PMSR7[4]|PMSR7[3]|PMSR7[2]|PMSR7[1]|PMSR7[0]|
||PMSR8|PMSR8[31]|PMSR8[30]|PMSR8[29]|PMSR8[28]|PMSR8[27]|PMSR8[26]|PMSR8[25]|PMSR8[24]|
|||PMSR8[23]|PMSR8[22]|PMSR8[21]|PMSR8[20]|PMSR8[19]|PMSR8[18]|PMSR8[17]|PMSR8[16]|
|||PMSR8[15]|PMSR8[14]|PMSR8[13]|PMSR8[12]|PMSR8[11]|PMSR8[10]|PMSR8[9]|PMSR8[8]|
|||PMSR8[7]|PMSR8[6]|PMSR8[5]|PMSR8[4]|PMSR8[3]|PMSR8[2]|PMSR8[1]|PMSR8[0]|
||PMSR9|-|-|-|-|-|-|-|-|
|||-|-|PMSR9[21]|PMSR9[20]|PMSR9[19]|PMSR9[18]|PMSR9[17]|PMSR9[16]|
|||-|-|-|-|-|-|-|-|
|||-|-|PMSR9[5]|PMSR9[4]|PMSR9[3]|PMSR9[2]|PMSR9[1]|PMSR9[0]|
||PMCSR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|PMCSR0[19]|PMCSR0[18]|PMCSR0[17]|PMCSR0[16]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|PMCSR0[3]|PMCSR0[2]|PMCSR0[1]|PMCSR0[0]|
||PMCSR1|-|-|-|-|-|-|-|-|
|||PMCSR1[23]|PMCSR1[22]|PMCSR1[21]|PMCSR1[20]|PMCSR1[19]|PMCSR1[18]|PMCSR1[17]|PMCSR1[16]|
|||-|-|-|-|-|-|-|-|
|||PMCSR1[7]|PMCSR1[6]|PMCSR1[5]|PMCSR1[4]|PMCSR1[3]|PMCSR1[2]|PMCSR1[1]|PMCSR1[0]|
||PMCSR2|-|-|-|-|-|-|PMCSR2[25]|PMCSR2[24]|
|||PMCSR2[23]|PMCSR2[22]|PMCSR2[21]|PMCSR2[20]|PMCSR2[19]|PMCSR2[18]|PMCSR2[17]|PMCSR2[16]|
|||-|-|-|-|-|-|PMCSR2[9]|PMCSR2[8]|
|||PMCSR2[7]|PMCSR2[6]|PMCSR2[5]|PMCSR2[4]|PMCSR2[3]|PMCSR2[2]|PMCSR2[1]|PMCSR2[0]|
||PMCSR3|PMCSR3[31]|PMCSR3[30]|PMCSR3[29]|PMCSR3[28]|PMCSR3[27]|PMCSR3[26]|PMCSR3[25]|PMCSR3[24]|
|||PMCSR3[23]|PMCSR3[22]|PMCSR3[21]|PMCSR3[20]|PMCSR3[19]|PMCSR3[18]|PMCSR3[17]|PMCSR3[16]|
|||PMCSR3[15]|PMCSR3[14]|PMCSR3[13]|PMCSR3[12]|PMCSR3[11]|PMCSR3[10]|PMCSR3[9]|PMCSR3[8]|
|||PMCSR3[7]|PMCSR3[6]|PMCSR3[5]|PMCSR3[4]|PMCSR3[3]|PMCSR3[2]|PMCSR3[1]|PMCSR3[0]|
||PMCSR4|-|-|-|-|-|-|-|-|
|||PMCSR4[23]|PMCSR4[22]|PMCSR4[21]|PMCSR4[20]|PMCSR4[19]|PMCSR4[18]|PMCSR4[17]|PMCSR4[16]|
|||-|-|-|-|-|-|-|-|
|||PMCSR4[7]|PMCSR4[6]|PMCSR4[5]|PMCSR4[4]|PMCSR4[3]|PMCSR4[2]|PMCSR4[1]|PMCSR4[0]|
||PMCSR5|PMCSR5[31]|PMCSR5[30]|PMCSR5[29]|PMCSR5[28]|PMCSR5[27]|PMCSR5[26]|PMCSR5[25]|PMCSR5[24]|
|||PMCSR5[23]|PMCSR5[22]|PMCSR5[21]|PMCSR5[20]|PMCSR5[19]|PMCSR5[18]|PMCSR5[17]|PMCSR5[16]|
|||PMCSR5[15]|PMCSR5[14]|PMCSR5[13]|PMCSR5[12]|PMCSR5[11]|PMCSR5[10]|PMCSR5[9]|PMCSR5[8]|
|||PMCSR5[7]|PMCSR5[6]|PMCSR5[5]|PMCSR5[4]|PMCSR5[3]|PMCSR5[2]|PMCSR5[1]|PMCSR5[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ports|PMCSR6|PMCSR6[31]|PMCSR6[30]|PMCSR6[29]|PMCSR6[28]|PMCSR6[27]|PMCSR6[26]|PMCSR6[25]|PMCSR6[24]|
|||PMCSR6[23]|PMCSR6[22]|PMCSR6[21]|PMCSR6[20]|PMCSR6[19]|PMCSR6[18]|PMCSR6[17]|PMCSR6[16]|
|||PMCSR6[15]|PMCSR6[14]|PMCSR6[13]|PMCSR6[12]|PMCSR6[11]|PMCSR6[10]|PMCSR6[9]|PMCSR6[8]|
|||PMCSR6[7]|PMCSR6[6]|PMCSR6[5]|PMCSR6[4]|PMCSR6[3]|PMCSR6[2]|PMCSR6[1]|PMCSR6[0]|
||PMCSR7|-|-|-|-|PMCSR7[27]|PMCSR7[26]|PMCSR7[25]|PMCSR7[24]|
|||PMCSR7[23]|PMCSR7[22]|PMCSR7[21]|PMCSR7[20]|PMCSR7[19]|PMCSR7[18]|PMCSR7[17]|PMCSR7[16]|
|||-|-|-|-|PMCSR7[11]|PMCSR7[10]|PMCSR7[9]|PMCSR7[8]|
|||PMCSR7[7]|PMCSR7[6]|PMCSR7[5]|PMCSR7[4]|PMCSR7[3]|PMCSR7[2]|PMCSR7[1]|PMCSR7[0]|
||PMCSR8|PMCSR8[31]|PMCSR8[30]|PMCSR8[29]|PMCSR8[28]|PMCSR8[27]|PMCSR8[26]|PMCSR8[25]|PMCSR8[24]|
|||PMCSR8[23]|PMCSR8[22]|PMCSR8[21]|PMCSR8[20]|PMCSR8[19]|PMCSR8[18]|PMCSR8[17]|PMCSR8[16]|
|||PMCSR8[15]|PMCSR8[14]|PMCSR8[13]|PMCSR8[12]|PMCSR8[11]|PMCSR8[10]|PMCSR8[9]|PMCSR8[8]|
|||PMCSR8[7]|PMCSR8[6]|PMCSR8[5]|PMCSR8[4]|PMCSR8[3]|PMCSR8[2]|PMCSR8[1]|PMCSR8[0]|
||PMCSR9|-|-|-|-|-|-|-|-|
|||-|-|PMCSR9[21]|PMCSR9[20]|PMCSR9[19]|PMCSR9[18]|PMCSR9[17]|PMCSR9[16]|
|||-|-|-|-|-|-|-|-|
|||-|-|PMCSR9[5]|PMCSR9[4]|PMCSR9[3]|PMCSR9[2]|PMCSR9[1]|PMCSR9[0]|
||PFCAE0|-|-|-|-|-|-|-|-|
|||-|-|-|-|PFCAE0[3]|PFCAE0[2]|PFCAE0[1]|PFCAE0[0]|
||PFCAE1|PFCAE1[15]|PFCAE1[14]|PFCAE1[13]|PFCAE1[12]|PFCAE1[11]|PFCAE1[10]|PFCAE1[9]|PFCAE1[8]|
|||PFCAE1[7]|PFCAE1[6]|PFCAE1[5]|PFCAE1[4]|PFCAE1[3]|PFCAE1[2]|PFCAE1[1]|PFCAE1[0]|
||PFCAE2|-|-|-|-|-|-|PFCAE2[9]|PFCAE2[8]|
|||PFCAE2[7]|PFCAE2[6]|PFCAE2[5]|PFCAE2[4]|PFCAE2[3]|PFCAE2[2]|PFCAE2[1]|PFCAE2[0]|
||PFCAE3|PFCAE3[15]|PFCAE3[14]|PFCAE3[13]|PFCAE3[12]|PFCAE3[11]|PFCAE3[10]|PFCAE3[9]|PFCAE3[8]|
|||PFCAE3[7]|PFCAE3[6]|PFCAE3[5]|PFCAE3[4]|PFCAE3[3]|PFCAE3[2]|PFCAE3[1]|PFCAE3[0]|
||PFCAE4|-|-|-|-|-|-|-|-|
|||PFCAE4[7]|PFCAE4[6]|PFCAE4[5]|PFCAE4[4]|PFCAE4[3]|PFCAE4[2]|PFCAE4[1]|PFCAE4[0]|
||PFCAE5|PFCAE5[15]|PFCAE5[14]|PFCAE5[13]|PFCAE5[12]|PFCAE5[11]|PFCAE5[10]|PFCAE5[9]|PFCAE5[8]|
|||PFCAE5[7]|PFCAE5[6]|PFCAE5[5]|PFCAE5[4]|PFCAE5[3]|PFCAE5[2]|PFCAE5[1]|PFCAE5[0]|
||PFCAE6|PFCAE6[15]|PFCAE6[14]|PFCAE6[13]|PFCAE6[12]|PFCAE6[11]|PFCAE6[10]|PFCAE6[9]|PFCAE6[8]|
|||PFCAE6[7]|PFCAE6[6]|PFCAE6[5]|PFCAE6[4]|PFCAE6[3]|PFCAE6[2]|PFCAE6[1]|PFCAE6[0]|
||PFCAE7|-|-|-|-|PFCAE7[11]|PFCAE7[10]|PFCAE7[9]|PFCAE7[8]|
|||PFCAE7[7]|PFCAE7[6]|PFCAE7[5]|PFCAE7[4]|PFCAE7[3]|PFCAE7[2]|PFCAE7[1]|PFCAE7[0]|
||PFCAE8|PFCAE8[15]|PFCAE8[14]|PFCAE8[13]|PFCAE8[12]|PFCAE8[11]|PFCAE8[10]|PFCAE8[9]|PFCAE8[8]|
|||PFCAE8[7]|PFCAE8[6]|PFCAE8[5]|PFCAE8[4]|PFCAE8[3]|PFCAE8[2]|PFCAE8[1]|PFCAE8[0]|
||PFCAE9|-|-|-|-|-|-|-|-|
|||-|-|PFCAE9[5]|PFCAE9[4]|PFCAE9[3]|PFCAE9[2]|PFCAE9[1]|PFCAE9[0]|
||PIBC0|-|-|-|-|-|-|-|-|
|||-|-|-|-|PIBC0[3]|PIBC0[2]|PIBC0[1]|PIBC0[0]|
||PIBC1|PIBC1[15]|PIBC1[14]|PIBC1[13]|PIBC1[12]|PIBC1[11]|PIBC1[10]|PIBC1[9]|PIBC1[8]|
|||PIBC1[7]|PIBC1[6]|PIBC1[5]|PIBC1[4]|PIBC1[3]|PIBC1[2]|PIBC1[1]|PIBC1[0]|
||PIBC2|-|-|-|-|-|-|PIBC2[9]|PIBC2[8]|
|||PIBC2[7]|PIBC2[6]|PIBC2[5]|PIBC2[4]|PIBC2[3]|PIBC2[2]|PIBC2[1]|PIBC2[0]|
||PIBC3|PIBC3[15]|PIBC3[14]|PIBC3[13]|PIBC3[12]|PIBC3[11]|PIBC3[10]|PIBC3[9]|PIBC3[8]|
|||PIBC3[7]|PIBC3[6]|PIBC3[5]|PIBC3[4]|PIBC3[3]|PIBC3[2]|PIBC3[1]|PIBC3[0]|
||PIBC4|-|-|-|-|-|-|-|-|
|||PIBC4[7]|PIBC4[6]|PIBC4[5]|PIBC4[4]|PIBC4[3]|PIBC4[2]|PIBC4[1]|PIBC4[0]|
||PIBC5|PIBC5[15]|PIBC5[14]|PIBC5[13]|PIBC5[12]|PIBC5[11]|PIBC5[10]|PIBC5[9]|PIBC5[8]|
|||PIBC5[7]|PIBC5[6]|PIBC5[5]|PIBC5[4]|PIBC5[3]|PIBC5[2]|PIBC5[1]|PIBC5[0]|
||PIBC6|PIBC6[15]|PIBC6[14]|PIBC6[13]|PIBC6[12]|PIBC6[11]|PIBC6[10]|PIBC6[9]|PIBC6[8]|
|||PIBC6[7]|PIBC6[6]|PIBC6[5]|PIBC6[4]|PIBC6[3]|PIBC6[2]|PIBC6[1]|PIBC6[0]|
||PIBC7|-|-|-|-|PIBC7[11]|PIBC7[10]|PIBC7[9]|PIBC7[8]|
|||PIBC7[7]|PIBC7[6]|PIBC7[5]|PIBC7[4]|PIBC7[3]|PIBC7[2]|PIBC7[1]|PIBC7[0]|
||PIBC8|PIBC8[15]|PIBC8[14]|PIBC8[13]|PIBC8[12]|PIBC8[11]|PIBC8[10]|PIBC8[9]|PIBC8[8]|
|||PIBC8[7]|PIBC8[6]|PIBC8[5]|PIBC8[4]|PIBC8[3]|PIBC8[2]|PIBC8[1]|PIBC8[0]|
||PIBC9|-|-|-|-|-|-|-|-|
|||-|-|PIBC9[5]|PIBC9[4]|PIBC9[3]|PIBC9[2]|PIBC9[1]|PIBC9[0]|
||PBDC1|PBDC1[15]|PBDC1[14]|PBDC1[13]|PBDC1[12]|PBDC1[11]|PBDC1[10]|PBDC1[9]|PBDC1[8]|
|||PBDC1[7]|PBDC1[6]|PBDC1[5]|PBDC1[4]|PBDC1[3]|PBDC1[2]|PBDC1[1]|PBDC1[0]|
||PBDC2|-|-|-|-|-|-|PBDC2[9]|PBDC2[8]|
|||PBDC2[7]|PBDC2[6]|PBDC2[5]|PBDC2[4]|PBDC2[3]|PBDC2[2]|PBDC2[1]|PBDC2[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Ports|PBDC3|PBDC3[15]|PBDC3[14]|PBDC3[13]|PBDC3[12]|PBDC3[11]|PBDC3[10]|PBDC3[9]|PBDC3[8]|
|||PBDC3[7]|PBDC3[6]|PBDC3[5]|PBDC3[4]|PBDC3[3]|PBDC3[2]|PBDC3[1]|PBDC3[0]|
||PBDC4|-|-|-|-|-|-|-|-|
|||PBDC4[7]|PBDC4[6]|PBDC4[5]|PBDC4[4]|PBDC4[3]|PBDC4[2]|PBDC4[1]|PBDC4[0]|
||PBDC5|PBDC5[15]|PBDC5[14]|PBDC5[13]|PBDC5[12]|PBDC5[11]|PBDC5[10]|PBDC5[9]|PBDC5[8]|
|||PBDC5[7]|PBDC5[6]|PBDC5[5]|PBDC5[4]|PBDC5[3]|PBDC5[2]|PBDC5[1]|PBDC5[0]|
||PBDC6|PBDC6[15]|PBDC6[14]|PBDC6[13]|PBDC6[12]|PBDC6[11]|PBDC6[10]|PBDC6[9]|PBDC6[8]|
|||PBDC6[7]|PBDC6[6]|PBDC6[5]|PBDC6[4]|PBDC6[3]|PBDC6[2]|PBDC6[1]|PBDC6[0]|
||PBDC7|-|-|-|-|PBDC7[11]|PBDC7[10]|PBDC7[9]|PBDC7[8]|
|||PBDC7[7]|PBDC7[6]|PBDC7[5]|PBDC7[4]|PBDC7[3]|PBDC7[2]|PBDC7[1]|PBDC7[0]|
||PBDC8|PBDC8[15]|PBDC8[14]|PBDC8[13]|PBDC8[12]|PBDC8[11]|PBDC8[10]|PBDC8[9]|PBDC8[8]|
|||PBDC8[7]|PBDC8[6]|PBDC8[5]|PBDC8[4]|PBDC8[3]|PBDC8[2]|PBDC8[1]|PBDC8[0]|
||PBDC9|-|-|-|-|-|-|-|-|
|||-|-|PBDC9[5]|PBDC9[4]|PBDC9[3]|PBDC9[2]|PBDC9[1]|PBDC9[0]|
||PIPC1|-|-|-|-|-|-|-|-|
|||PIPC1[7]|PIPC1[6]|PIPC1[5]|PIPC1[4]|PIPC1[3]|PIPC1[2]|PIPC1[1]|PIPC1[0]|
||PIPC2|-|-|-|-|-|-|PIPC2[9]|PIPC2[8]|
|||PIPC2[7]|PIPC2[6]|PIPC2[5]|PIPC2[4]|PIPC2[3]|PIPC2[2]|PIPC2[1]|PIPC2[0]|
||PIPC3|PIPC3[15]|PIPC3[14]|PIPC3[13]|PIPC3[12]|PIPC3[11]|PIPC3[10]|PIPC3[9]|PIPC3[8]|
|||PIPC3[7]|PIPC3[6]|PIPC3[5]|PIPC3[4]|PIPC3[3]|PIPC3[2]|PIPC3[1]|PIPC3[0]|
||PIPC4|-|-|-|-|-|-|-|-|
|||PIPC4[7]|PIPC4[6]|PIPC4[5]|PIPC4[4]|PIPC4[3]|PIPC4[2]|PIPC4[1]|PIPC4[0]|
||PIPC5|PIPC5[15]|PIPC5[14]|PIPC5[13]|PIPC5[12]|PIPC5[11]|PIPC5[10]|PIPC5[9]|PIPC5[8]|
|||PIPC5[7]|PIPC5[6]|PIPC5[5]|PIPC5[4]|PIPC5[3]|PIPC5[2]|PIPC5[1]|PIPC5[0]|
||PIPC6|PIPC6[15]|PIPC6[14]|PIPC6[13]|PIPC6[12]|PIPC6[11]|PIPC6[10]|PIPC6[9]|PIPC6[8]|
|||PIPC6[7]|PIPC6[6]|PIPC6[5]|PIPC6[4]|PIPC6[3]|PIPC6[2]|PIPC6[1]|PIPC6[0]|
||PIPC7|-|-|-|-|PIPC7[11]|PIPC7[10]|PIPC7[9]|PIPC7[8]|
|||PIPC7[7]|PIPC7[6]|PIPC7[5]|PIPC7[4]|PIPC7[3]|PIPC7[2]|PIPC7[1]|PIPC7[0]|
||PIPC8|PIPC8[15]|PIPC8[14]|PIPC8[13]|PIPC8[12]|PIPC8[11]|PIPC8[10]|PIPC8[9]|PIPC8[8]|
|||PIPC8[7]|PIPC8[6]|PIPC8[5]|PIPC8[4]|PIPC8[3]|PIPC8[2]|PIPC8[1]|PIPC8[0]|
||PIPC9|-|-|-|-|-|-|-|-|
|||-|-|PIPC9[5]|PIPC9[4]|PIPC9[3]|PIPC9[2]|PIPC9[1]|PIPC9[0]|
||JPPR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|JPPR0[1]|JPPR0[0]|
||JPMC0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|JPMC0[1]|JPMC0[0]|
||JPMCSR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|JPMCSR0[17]|JPMCSR0[16]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|JPMCSR0[1]|JPMCSR0[0]|
||JPIBC0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|JPIBC0[1]|JPIBC0[0]|
||SNCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|ETSEL*4|-|-|SSI3NCE|SSI2NCE|SSI1NCE|SSI0NCE|
|Power-down<br>modes|STBCR1|STBY|DEEP|-|-|-|-|-|-|
||STBCR2|HIZ|-|-|-|-|-|-|MSTP20|
||STBCR3|MSTP37*3|MSTP36|MSTP35*3|-|MSTP33|MSTP32|MSTP31|-|
||STBCR4|MSTP47|MSTP46|MSTP45|MSTP44|MSTP43|-|-|-|
||STBCR5|MSTP57|MSTP56|-|-|-|-|MSTP51|MSTP50|
||STBCR6|MSTP67|MSTP66|-|-|-|-|MSTP61*4|MSTP60|
||STBCR7|-|-|-|MSTP74|-|-|MSTP71|MSTP70|
||STBCR8|-|-|-|MSTP84|MSTP83*3|MSTP82*4|MSTP81|-|
||STBCR9|MSTP97|MSTP96|MSTP95|MSTP94|MSTP93|-|MSTP91|-|
||STBCR10|MSTP107|MSTP106|MSTP105|-|-|MSTP102*3|MSTP101|-|
||STBCR11|-|-|MSTP115|MSTP114|MSTP113|MSTP112|-|-|
||STBCR12|-|-|-|-|MSTP123|MSTP122|MSTP121|MSTP120|
||SWRSTCR1|AXTALE|SRST16|SRST15|SRST14|SRST13|-|-|-|
||SWRSTCR2*2|-|-|-|-|-|-|SRST21|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Power-down<br>modes|SYSCR1|-|-|-|VRAME4*5|VRAME3|VRAME2|VRAME1|VRAME0|
||SYSCR2|-|-|-|VRAMWE4*5|VRAMWE3|VRAMWE2|VRAMWE1|VRAMWE0|
||SYSCR3|-|-|-|-|RRAMWE3|RRAMWE2|RRAMWE1|RRAMWE0|
||CPUSTS|-|-|-|ISBUSY|-|-|-|-|
||STBREQ1|-|-|STBRQ15|-|STBRQ13*4|STBRQ12*4|-|STBRQ10|
||STBREQ2|STBRQ27*3|STBRQ26|STBRQ25|-|-|-|-|-|
||STBACK1|-|-|STBAK15|-|STBAK13*4|STBAK12*4|-|STBAK10|
||STBACK2|STBAK27*3|STBAK26|STBAK25|-|-|-|-|-|
||RRAMKP|-|-|-|-|RRAMKP3|RRAMKP2|RRAMKP1|RRAMKP0|
||DSCTR|EBUSKEEPE|RAMBOOT|-|-|-|-|-|-|
||DSSSR|-|P2_0|P7_6|P7_9|P5_10|P2_2|P7_2|NMI|
|||-|RTCAR|P5_9|P7_3|P5_8|P2_7|P2_9|P6_7|
||DSESR|-|P2_0E|P7_6E|P7_9E|P5_10E|P2_2E|P7_2E|NMIE|
|||-|-|P5_9E|P7_3E|P5_8E|P2_7E|P2_9E|P6_7E|
||DSFR|IOKEEP|P2_0F|P7_6F|P7_9F|P5_10F|P2_2F|P7_2F|NMIF|
|||-|RTCARF|P5_9F|P7_3F|P5_8F|P2_7F|P2_9F|P6_7F|
||XTALCTR|-|-|-|-|-|-|-|GAIN0|
|Debugger<br>interface|DAPROM_<br>PERIPHID4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]|
||DAPROM_<br>PERIPHID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]|
||DAPROM_<br>PERIPHID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number[11]|Part_Number[10]|Part_Number[9]|Part_Number[8]|
||DAPROM_<br>PERIPHID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]|
||DAPROM_<br>PERIPHID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|CUSTOM[3]|CUSTOM[2]|CUSTOM[1]|CUSTOM[0]|
||DAPROM_COMPID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||DAPROM_COMPID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||DAPROM_COMPID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||DAPROM_COMPID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||ICEREGMDRSTCTL|-|-|-|-|-|-|-|-|
|||-|-|-|NIDEN_CPU0|-|-|-|DBGEN_CPU0|
|||-|-|-|RSTRB_CPU0_<br>DERSTZ|-|-|-|RSTRB_CPU0_<br>CPURSTZ|
|||-|-|-|RSTRB_SYS_<br>SYSRSTZ|-|RSTRB_CPU_<br>PRSTDBGZ|RSTRB_CPU_<br>SYSRSTZ|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|ICEREGJTTRCSEL|-|-|-|-|-|-|-|-|
|||PINSETEN|-|-|TRCMUX_SEL|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||ICEREGCLKPWR<br>CTRL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||FAKEDBGCTRL|-|-|-|-|-|-|FAKEDBG|
||ICEREGLOCK<br>ACCES|ICEREGLOCKACCESS<br>[31]|ICEREGLOCKACCESS<br>[30]|ICEREGLOCKACCESS<br>[29]|ICEREGLOCKACCESS<br>[28]|ICEREGLOCKACCESS<br>[27]|ICEREGLOCKACCESS<br>[26]|ICEREGLOCKACCESS<br>[25]|ICEREGLOCKACCESS<br>[24]|
|||ICEREGLOCKACCESS<br>[23]|ICEREGLOCKACCESS<br>[22]|ICEREGLOCKACCESS<br>[21]|ICEREGLOCKACCESS<br>[20]|ICEREGLOCKACCESS<br>[19]|ICEREGLOCKACCESS<br>[18]|ICEREGLOCKACCESS<br>[17]|ICEREGLOCKACCESS<br>[16]|
|||ICEREGLOCKACCESS<br>[15]|ICEREGLOCKACCESS<br>[14]|ICEREGLOCKACCESS<br>[13]|ICEREGLOCKACCESS<br>[12]|ICEREGLOCKACCESS<br>[11]|ICEREGLOCKACCESS<br>[10]|ICEREGLOCKACCESS<br>[9]|ICEREGLOCKACCESS<br>[8]|
|||ICEREGLOCKACCESS<br>[7]|ICEREGLOCKACCESS<br>[6]|ICEREGLOCKACCESS<br>[5]|ICEREGLOCKACCESS<br>[4]|ICEREGLOCKACCESS<br>[3]|ICEREGLOCKACCESS<br>[2]|ICEREGLOCKACCESS<br>[1]|ICEREGLOCKACCESS<br>[0]|
||2ndDAPROM_<br>PERIPHID4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]|
||2ndDAPROM_<br>PERIPHID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]|
||2ndDAPROM_<br>PERIPHID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number<br>[11]|Part_Number<br>[10]|Part_Number[9]|Part_Number[8]|
||2ndDAPROM_<br>PERIPHID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]|
||2ndDAPROM_<br>PERIPHID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|CUSTOM[3]|CUSTOM[2]|CUSTOM[1]|CUSTOM[0]|
||2ndDAPROM_<br>COMPID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||2ndDAPROM_<br>COMPID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||2ndDAPROM_<br>COMPID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||2ndDAPROM_<br>COMPID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_ETF_RSZ|-|RSZ[30]|RSZ[29]|RSZ[28]|RSZ[27]|RSZ[26]|RSZ[25]|RSZ[24]|
|||RSZ[23]|RSZ[22]|RSZ[21]|RSZ[20]|RSZ[19]|RSZ[18]|RSZ[17]|RSZ[16]|
|||RSZ[15]|RSZ[14]|RSZ[13]|RSZ[12]|RSZ[11]|RSZ[10]|RSZ[9]|RSZ[8]|
|||RSZ[7]|RSZ[6]|RSZ[5]|RSZ[4]|RSZ[3]|RSZ[2]|RSZ[1]|RSZ[0]|
||CPU_ETF_STS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|MemErr|Empty|FtEmpty|TMCReady|Triggered|Full|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_ETF_RRD|RRD[31]|RRD[30]|RRD[29]|RRD[28]|RRD[27]|RRD[26]|RRD[25]|RRD[24]|
|||RRD[23]|RRD[22]|RRD[21]|RRD[20]|RRD[19]|RRD[18]|RRD[17]|RRD[16]|
|||RRD[15]|RRD[14]|RRD[13]|RRD[12]|RRD[11]|RRD[10]|RRD[9]|RRD[8]|
|||RRD[7]|RRD[6]|RRD[5]|RRD[4]|RRD[3]|RRD[2]|RRD[1]|RRD[0]|
||CPU_ETF_RRP|RRP[31]|RRP[30]|RRP[29]|RRP[28]|RRP[27]|RRP[26]|RRP[25]|RRP[24]|
|||RRP[23]|RRP[22]|RRP[21]|RRP[20]|RRP[19]|RRP[18]|RRP[17]|RRP[16]|
|||RRP[15]|RRP[14]|RRP[13]|RRP[12]|RRP[11]|RRP[10]|RRP[9]|RRP[8]|
|||RRP[7]|RRP[6]|RRP[5]|RRP[4]|RRP[3]|RRP[2]|RRP[1]|RRP[0]|
||CPU_ETF_RWP|RWP[31]|RWP[30]|RWP[29]|RWP[28]|RWP[27]|RWP[26]|RWP[25]|RWP[24]|
|||RWP[23]|RWP[22]|RWP[21]|RWP[20]|RWP[19]|RWP[18]|RWP[17]|RWP[16]|
|||RWP[15]|RWP[14]|RWP[13]|RWP[12]|RWP[11]|RWP[10]|RWP[9]|RWP[8]|
|||RWP[7]|RWP[6]|RWP[5]|RWP[4]|RWP[3]|RWP[2]|RWP[1]|RWP[0]|
||CPU_ETF_TRG|TRG[31]|TRG[30]|TRG[29]|TRG[28]|TRG[27]|TRG[26]|TRG[25]|TRG[24]|
|||TRG[23]|TRG[22]|TRG[21]|TRG[20]|TRG[19]|TRG[18]|TRG[17]|TRG[16]|
|||TRG[15]|TRG[14]|TRG[13]|TRG[12]|TRG[11]|TRG[10]|TRG[9]|TRG[8]|
|||TRG[7]|TRG[6]|TRG[5]|TRG[4]|TRG[3]|TRG[2]|TRG[1]|TRG[0]|
||CPU_ETF_CTL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TraceCaptEn|
||CPU_ETF_RWD|RWD[31]|RWD[30]|RWD[29]|RWD[28]|RWD[27]|RWD[26]|RWD[25]|RWD[24]|
|||RWD[23]|RWD[22]|RWD[21]|RWD[20]|RWD[19]|RWD[18]|RWD[17]|RWD[16]|
|||RWD[15]|RWD[14]|RWD[13]|RWD[12]|RWD[11]|RWD[10]|RWD[9]|RWD[8]|
|||RWD[7]|RWD[6]|RWD[5]|RWD[4]|RWD[3]|RWD[2]|RWD[1]|RWD[0]|
||CPU_ETF_MODE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|MODE[1]|MODE[0]|
||CPU_ETF_<br>LBUFLEVEL|LBUFLEVEL[31]|LBUFLEVEL[30]|LBUFLEVEL[29]|LBUFLEVEL[28]|LBUFLEVEL[27]|LBUFLEVEL[26]|LBUFLEVEL[25]|LBUFLEVEL[24]|
|||LBUFLEVEL[23]|LBUFLEVEL[22]|LBUFLEVEL[21]|LBUFLEVEL[20]|LBUFLEVEL[19]|LBUFLEVEL[18]|LBUFLEVEL[17]|LBUFLEVEL[16]|
|||LBUFLEVEL[15]|LBUFLEVEL[14]|LBUFLEVEL[13]|LBUFLEVEL[12]|LBUFLEVEL[11]|LBUFLEVEL[10]|LBUFLEVEL[9]|LBUFLEVEL[8]|
|||LBUFLEVEL[7]|LBUFLEVEL[6]|LBUFLEVEL[5]|LBUFLEVEL[4]|LBUFLEVEL[3]|LBUFLEVEL[2]|LBUFLEVEL[1]|LBUFLEVEL[0]|
||CPU_ETF_<br>CBUFLEVEL|CBUFLEVEL[31]|CBUFLEVEL[30]|CBUFLEVEL[29]|CBUFLEVEL[28]|CBUFLEVEL[27]|CBUFLEVEL[26]|CBUFLEVEL[25]|CBUFLEVEL[24]|
|||CBUFLEVEL[23]|CBUFLEVEL[22]|CBUFLEVEL[21]|CBUFLEVEL[20]|CBUFLEVEL[19]|CBUFLEVEL[18]|CBUFLEVEL[17]|CBUFLEVEL[16]|
|||CBUFLEVEL[15]|CBUFLEVEL[14]|CBUFLEVEL[13]|CBUFLEVEL[12]|CBUFLEVEL[11]|CBUFLEVEL[10]|CBUFLEVEL[9]|CBUFLEVEL[8]|
|||CBUFLEVEL[7]|CBUFLEVEL[6]|CBUFLEVEL[5]|CBUFLEVEL[4]|CBUFLEVEL[3]|CBUFLEVEL[2]|CBUFLEVEL[1]|CBUFLEVEL[0]|
||CPU_ETF_BUFWM|BUFWM[31]|BUFWM[30]|BUFWM[29]|BUFWM[28]|BUFWM[27]|BUFWM[26]|BUFWM[25]|BUFWM[24]|
|||BUFWM[23]|BUFWM[22]|BUFWM[21]|BUFWM[20]|BUFWM[19]|BUFWM[18]|BUFWM[17]|BUFWM[16]|
|||BUFWM[15]|BUFWM[14]|BUFWM[13]|BUFWM[12]|BUFWM[11]|BUFWM[10]|BUFWM[9]|BUFWM[8]|
|||BUFWM[7]|BUFWM[6]|BUFWM[5]|BUFWM[4]|BUFWM[3]|BUFWM[2]|BUFWM[1]|BUFWM[0]|
||CPU_ETF_RRPHI|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RRPHI[7]|RRPHI[6]|RRPHI[5]|RRPHI[4]|RRPHI[3]|RRPHI[2]|RRPHI[1]|RRPHI[0]|
||CPU_ETF_RWPHI|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RWPHI[7]|RWPHI[6]|RWPHI[5]|RWPHI[4]|RWPHI[3]|RWPHI[2]|RWPHI[1]|RWPHI[0]|
||CPU_ETF_FFSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|FtStopped|FlInProg|
||CPU_ETF_FFCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|DrainBuffer|StopOnTrigEvt|StopOnFI|-|TrigOnFI|TrigOnTrigEvt|TrigOnTrigIn|
|||-|FlushMan|FOnTrigEvt|FOnFIIn|-|-|EnTI|EnFt|
||CPU_ETF_PSCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|PSCount[4]|PSCount[3]|PSCount[2]|PSCount[1]|PSCount[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_ETF_<br>CLAIMSET|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CLAIMSET[3]|CLAIMSET[2]|CLAIMSET[1]|CLAIMSET[0]|
||CPU_ETF_<br>CLAIMCLR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CLAIMCLR[3]|CLAIMCLR[2]|CLAIMCLR[1]|CLAIMCLR[0]|
||CPU_ETF_LAR|ACCESS_W[31]|ACCESS_W[30]|ACCESS_W[29]|ACCESS_W[28]|ACCESS_W[27]|ACCESS_W[26]|ACCESS_W[25]|ACCESS_W[24]|
|||ACCESS_W[23]|ACCESS_W[22]|ACCESS_W[21]|ACCESS_W[20]|ACCESS_W[19]|ACCESS_W[18]|ACCESS_W[17]|ACCESS_W[16]|
|||ACCESS_W[15]|ACCESS_W[14]|ACCESS_W[13]|ACCESS_W[12]|ACCESS_W[11]|ACCESS_W[10]|ACCESS_W[9]|ACCESS_W[8]|
|||ACCESS_W[7]|ACCESS_W[6]|ACCESS_W[5]|ACCESS_W[4]|ACCESS_W[3]|ACCESS_W[2]|ACCESS_W[1]|ACCESS_W[0]|
||CPU_ETF_LSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|LOCKTYPE|LOCKGRANT|LOCKEXIST|
||CPU_ETF_<br>AUTHSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SNID[1]|SNID[0]|SID[1]|SID[0]|NSNID[1]|NSNID[0]|NSID[1]|NSID[0]|
||CPU_ETF_DEVID|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|WBUF_DEPTH[2]|WBUF_DEPTH[1]|WBUF_DEPTH[0]|MEMWIDTH[2]|MEMWIDTH[1]|MEMWIDTH[0]|
|||CONFIGTYPE[1]|CONFIGTYPE[0]|CLKSCHEME|ATBINPORT<br>COUNT[4]|ATBINPORT<br>COUNT[3]|ATBINPORT<br>COUNT[2]|ATBINPORT<br>COUNT[1]|ATBINPORT<br>COUNT[0]|
||CPU_ETF_<br>DEVTYPE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Sub_type[3]|Sub_type[2]|Sub_type[1]|Sub_type[0]|Major_type[3]|Major_type[2]|Major_type[1]|Major_type[0]|
||CPU_ETF_<br>PERIPHID4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]|
||CPU_ETF_<br>PERIPHID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]|
||CPU_ETF_<br>PERIPHID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number[11]|Part_Number[10]|Part_Number[9]|Part_Number[8]|
||CPU_ETF_<br>PERIPHID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]|
||CPU_ETF_<br>PERIPHID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|Customer<br>Modified[3]|Customer<br>Modified[2]|Customer<br>Modified[1]|Customer<br>Modified[0]|
||CPU_ETF_<br>COMPID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_ETF_<br>COMPID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_ETF_<br>COMPID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_ETF_<br>COMPID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_CTICS_<br>CTICONTROL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GLBEN|
||CPU_CTICS_<br>CTIINTACK|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INTACK[7]|INTACK[6]|INTACK[5]|INTACK[4]|INTACK[3]|INTACK[2]|INTACK[1]|INTACK[0]|
||CPU_CTICS_<br>CTIAPPSET|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|APPSET[3]|APPSET[2]|APPSET[1]|APPSET[0]|
||CPU_CTICS_<br>CTIAPPCLEAR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|APPCLEAR[3]|APPCLEAR[2]|APPCLEAR[1]|APPCLEAR[0]|
||CPU_CTICS_<br>CTIAPPPULSE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|APPULSE[3]|APPULSE[2]|APPULSE[1]|APPULSE[0]|
||CPU_CTICS_<br>CTIINEN0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CPU_CTICS_<br>CTIINEN1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CPU_CTICS_<br>CTIINEN2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CPU_CTICS_<br>CTIINEN3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CPU_CTICS_<br>CTIINEN4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CPU_CTICS_<br>CTIINEN5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CPU_CTICS_<br>CTIINEN6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CPU_CTICS_<br>CTIINEN7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_CTICS_<br>CTIOUTEN0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CPU_CTICS_<br>CTIOUTEN1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CPU_CTICS_<br>CTIOUTEN2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CPU_CTICS_<br>CTIOUTEN3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CPU_CTICS_<br>CTIOUTEN4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CPU_CTICS_<br>CTIOUTEN5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CPU_CTICS_<br>CTIOUTEN6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CPU_CTICS_<br>CTIOUTEN7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CPU_CTICS_<br>CTITRIGINSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TRIGINSTATUS[7]|TRIGINSTATUS[6]|TRIGINSTATUS[5]|TRIGINSTATUS[4]|TRIGINSTATUS[3]|TRIGINSTATUS[2]|TRIGINSTATUS[1]|TRIGINSTATUS[0]|
||CPU_CTICS_<br>CTITRIGOUT<br>STATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TRIGOUT<br>STATUS[7]|TRIGOUT<br>STATUS[6]|TRIGOUT<br>STATUS[5]|TRIGOUT<br>STATUS[4]|TRIGOUT<br>STATUS[3]|TRIGOUT<br>STATUS[2]|TRIGOUT<br>STATUS[1]|TRIGOUT<br>STATUS[0]|
||CPU_CTICS_<br>CTICHINSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CTCHINSTATUS[3]|CTCHINSTATUS[2]|CTCHINSTATUS[1]|CTCHINSTATUS[0]|
||CPU_CTICS_<br>CTICHOUTSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CTCHOUT<br>STATUS[3]|CTCHOUT<br>STATUS[2]|CTCHOUT<br>STATUS[1]|CTCHOUT<br>STATUS[0]|
||CPU_CTICS_<br>CTIGATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CTIGATEEN3|CTIGATEEN2|CTIGATEEN1|CTIGATEEN0|
||CPU_CTICS_<br>ASICCTL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|ASICCTL[3]|ASICCTL[2]|ASICCTL[1]|ASICCTL[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**||
|---|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_CTICS_<br>CLAIMSET|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|CLAIMSET[3]|CLAIMSET[2]|CLAIMSET[1]|CLAIMSET[0]||
||CPU_CTICS_<br>CLAIMCLR|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|CLAIMCLR[3]|CLAIMCLR[2]|CLAIMCLR[1]|CLAIMCLR[0]||
||CPU_CTICS_LAR|ACCESS_W[31]|ACCESS_W[30]|ACCESS_W[29]|ACCESS_W[28]|ACCESS_W[27]|ACCESS_W[26]|ACCESS_W[25]|ACCESS_W[24]||
|||ACCESS_W[23]|ACCESS_W[22]|ACCESS_W[21]|ACCESS_W[20]|ACCESS_W[19]|ACCESS_W[18]|ACCESS_W[17]|ACCESS_W[16]||
|||ACCESS_W[15]|ACCESS_W[14]|ACCESS_W[13]|ACCESS_W[12]|ACCESS_W[11]|ACCESS_W[10]|ACCESS_W[9]|ACCESS_W[8]||
|||ACCESS_W[7]|ACCESS_W[6]|ACCESS_W[5]|ACCESS_W[4]|ACCESS_W[3]|ACCESS_W[2]|ACCESS_W[1]|ACCESS_W[0]||
||CPU_CTICS_LSR|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|LOCKTYPE|LOCKGRANT|LOCKEXIST||
||CPU_CTICS_<br>AUTHSTATUS|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||SNID[1]|SNID[0]|SID[1]|SID[0]|NSNID[1]|NSNID[0]|NSID[1]|NSID[0]||
||CPU_CTICS_DEVID|-|-|-|-|-|-|-|-||
|||-|-|-|-|CHANWIDTH[3]|CHANWIDTH[2]|CHANWIDTH[1]|CHANWIDTH[0]||
|||TRIGWIDTH[7]|TRIGWIDTH[6]|TRIGWIDTH[5]|TRIGWIDTH[4]|TRIGWIDTH[3]|TRIGWIDTH[2]|TRIGWIDTH[1]|TRIGWIDTH[0]||
|||-|-|-|-|EXTMUXNUM[3]|EXTMUXNUM[2]|EXTMUXNUM[1]|EXTMUXNUM[0]||
||CPU_CTICS_<br>DEVTYPE|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Sub_type[3]|Sub_type[2]|Sub_type[1]|Sub_type[0]|Major_type[3]|Major_type[2]|Major_type[1]|Major_type[0]||
||CPU_CTICS_<br>PERIPHID4|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]||
||CPU_CTICS_<br>PERIPHID0|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]||
||CPU_CTICS_<br>PERIPHID1|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number<br>[11]|Part_Number<br>[10]|Part_Number[9]|Part_Number[8]||
||CPU_CTICS_<br>PERIPHID2|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]||
||CPU_CTICS_<br>PERIPHID3|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|CUSTOM[3]|CUSTOM[2]|CUSTOM[1]|CUSTOM[0]||
||CPU_CTICS_<br>COMPID0|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||
||CPU_CTICS_<br>COMPID1|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||
||CPU_CTICS_<br>COMPID2|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_CTICS_<br>COMPID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_TPIU_<br>Supportedportsizes|SIZE[31]|SIZE[30]|SIZE[29]|SIZE[28]|SIZE[27]|SIZE[26]|SIZE[25]|SIZE[24]|
|||SIZE[23]|SIZE[22]|SIZE[21]|SIZE[20]|SIZE[19]|SIZE[18]|SIZE[17]|SIZE[16]|
|||SIZE[15]|SIZE[14]|SIZE[13]|SIZE[12]|SIZE[11]|SIZE[10]|SIZE[9]|SIZE[8]|
|||SIZE[7]|SIZE[6]|SIZE[5]|SIZE[4]|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||CPU_TPIU_<br>Currentportsize|SIZE[31]|SIZE[30]|SIZE[29]|SIZE[28]|SIZE[27]|SIZE[26]|SIZE[25]|SIZE[24]|
|||SIZE[23]|SIZE[22]|SIZE[21]|SIZE[20]|SIZE[19]|SIZE[18]|SIZE[17]|SIZE[16]|
|||SIZE[15]|SIZE[14]|SIZE[13]|SIZE[12]|SIZE[11]|SIZE[10]|SIZE[9]|SIZE[8]|
|||SIZE[7]|SIZE[6]|SIZE[5]|SIZE[4]|SIZE[3]|SIZE[2]|SIZE[1]|SIZE[0]|
||CPU_TPIU_<br>Supportedtrigge<br>rmodes|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|TrgRun|Triggered|
|||-|-|-|-|-|-|-|TCount8|
|||-|-|-|Multipliers[4]|Multipliers[3]|Multipliers[2]|Multipliers[1]|Multipliers[0]|
||CPU_TPIU_<br>TriggerCounter value|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TrigCount[7]|TrigCount[6]|TrigCount[5]|TrigCount[4]|TrigCount[3]|TrigCount[2]|TrigCount[1]|TrigCount[0]|
||CPU_TPIU_<br>Triggermultiplier|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|TrgRun|Triggered|
|||-|-|-|-|-|-|-|TCount8|
|||-|-|-|Multipliers[4]|Multipliers[3]|Multipliers[2]|Multipliers[1]|Multipliers[0]|
||CPU_TPIU_<br>Supportedtestpattern/<br>modes|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|Mode[1]|Mode[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Pattem[3]|Pattem[2]|Pattem[1]|Pattem[0]|
||CPU_TPIU_<br>Currenttestpattern/<br>mode|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|Mode[1]|Mode[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Pattem[3]|Pattem[2]|Pattem[1]|Pattem[0]|
||CPU_TPIU_<br>Testpatternrepeat<br>counter|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||PattCount[7]|PattCount[6]|PattCount[5]|PattCount[4]|PattCount[3]|PattCount[2]|PattCount[1]|PattCount[0]|
||CPU_TPIU_<br>Formatterandflush<br>status|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|Mode[1]|Mode[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|StopTrig|StopFl|-|TCP|FTS|FIP|
||CPU_TPIU_<br>Formatterandflush<br>control|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|TrigFl|TrigEvt|TrigIn|
|||-|FOnMan|FOnTrig|FOnFlIn|-|-|EnFCont|EnFTC|
||CPU_TPIU_<br>Formatter<br>synchronization<br>counter|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CycCount[11]|CycCount[10]|CycCount[9]|CycCount[8]|
|||CycCount[7]|CycCount[6]|CycCount[5]|CycCount[4]|CycCount[3]|CycCount[2]|CycCount[1]|CycCount[0]|
||CPU_TPIU_<br>CLAIMSET|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CLAIMSET[3]|CLAIMSET[2]|CLAIMSET[1]|CLAIMSET[0]|
||CPU_TPIU_<br>CLAIMCLR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CLAIMCLR[3]|CLAIMCLR[2]|CLAIMCLR[1]|CLAIMCLR[0]|
||CPU_TPIU_LAR|ACCESS_W[31]|ACCESS_W[30]|ACCESS_W[29]|ACCESS_W[28]|ACCESS_W[27]|ACCESS_W[26]|ACCESS_W[25]|ACCESS_W[24]|
|||ACCESS_W[23]|ACCESS_W[22]|ACCESS_W[21]|ACCESS_W[20]|ACCESS_W[19]|ACCESS_W[18]|ACCESS_W[17]|ACCESS_W[16]|
|||ACCESS_W[15]|ACCESS_W[14]|ACCESS_W[13]|ACCESS_W[12]|ACCESS_W[11]|ACCESS_W[10]|ACCESS_W[9]|ACCESS_W[8]|
|||ACCESS_W[7]|ACCESS_W[6]|ACCESS_W[5]|ACCESS_W[4]|ACCESS_W[3]|ACCESS_W[2]|ACCESS_W[1]|ACCESS_W[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_TPIU_LSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|LOCKTYPE|LOCKGRANT|LOCKEXIST|
||CPU_TPIU_<br>AUTHSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SNID[1]|SNID[0]|SID[1]|SID[0]|NSNID[1]|NSNID[0]|NSID[1]|NSID[0]|
||CPU_TPIU_DEVID|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|ID[12]|ID[11]|ID[10]|ID[9]|ID[8]|
|||ID[7]|ID[6]|ID[5]|ID[4]|ID[3]|ID[2]|ID[1]|ID[0]|
||CPU_TPIU_<br>DEVTYPE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Sub_type[3]|Sub_type[2]|Sub_type[1]|Sub_type[0]|Main_type[3]|Main_type[2]|Main_type[1]|Main_type[0]|
||CPU_TPIU_<br>PERIPHID4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]|
||CPU_TPIU_<br>PERIPHID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]|
||CPU_TPIU_<br>PERIPHID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number<br>[11]|Part_Number<br>[10]|Part_Number[9]|Part_Number[8]|
||CPU_TPIU_<br>PERIPHID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]|
||CPU_TPIU_<br>PERIPHID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|Customer<br>Modified[3]|Customer<br>Modified[2]|Customer<br>Modified[1]|Customer<br>Modified[0]|
||CPU_TPIU_COMPID<br>0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_TPIU_COMPID<br>1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_TPIU_COMPID<br>2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_TPIU_COMPID<br>3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_TraceFunnel_<br>FUNCTL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|HT[3]|HT[2]|HT[1]|HT[0]|
|||EnS7|EnS6|EnS5|EnS4|EnS3|EnS2|EnS1|EnS0|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_TraceFunnel_<br>PRICTL|-|-|-|-|-|-|-|-|
|||PriPort7[2]|PriPort7[1]|PriPort7[0]|PriPort6[2]|PriPort6[1]|PriPort6[0]|PriPort5[2]|PriPort5[1]|
|||PriPort5[0]|PriPort4[2]|PriPort4[1]|PriPort4[0]|PriPort3[2]|PriPort3[1]|PriPort3[0]|PriPort2[2]|
|||PriPort2[1]|PriPort2[0]|PriPort1[2]|PriPort1[1]|PriPort1[0]|PriPort0[2]|PriPort0[1]|PriPort0[0]|
||CPU_TraceFunnel_<br>CLAIMSET|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CLAIMSET[3]|CLAIMSET[2]|CLAIMSET[1]|CLAIMSET[0]|
||CPU_TraceFunnel_<br>CLAIMCLR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CLAIMCLR[3]|CLAIMCLR[2]|CLAIMCLR[1]|CLAIMCLR[0]|
||CPU_TraceFunnel_<br>LAR|ACCESS_W[31]|ACCESS_W[30]|ACCESS_W[29]|ACCESS_W[28]|ACCESS_W[27]|ACCESS_W[26]|ACCESS_W[25]|ACCESS_W[24]|
|||ACCESS_W[23]|ACCESS_W[22]|ACCESS_W[21]|ACCESS_W[20]|ACCESS_W[19]|ACCESS_W[18]|ACCESS_W[17]|ACCESS_W[16]|
|||ACCESS_W[15]|ACCESS_W[14]|ACCESS_W[13]|ACCESS_W[12]|ACCESS_W[11]|ACCESS_W[10]|ACCESS_W[9]|ACCESS_W[8]|
|||ACCESS_W[7]|ACCESS_W[6]|ACCESS_W[5]|ACCESS_W[4]|ACCESS_W[3]|ACCESS_W[2]|ACCESS_W[1]|ACCESS_W[0]|
||CPU_TraceFunnel_<br>LSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|LOCKTYPE|LOCKGRANT|LOCKEXIST|
||CPU_TraceFunnel_<br>AUTHSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SNID[1]|SNID[0]|SID[1]|SID[0]|NSNID[1]|NSNID[0]|NSID[1]|NSID[0]|
||CPU_TraceFunnel_<br>DEVID|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ID[7]|ID[6]|ID[5]|ID[4]|ID[3]|ID[2]|ID[1]|ID[0]|
||CPU_TraceFunnel_<br>DEVTYPE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TYPE[7]|TYPE[6]|TYPE[5]|TYPE[4]|TYPE[3]|TYPE[2]|TYPE[1]|TYPE[0]|
||CPU_TraceFunnel_<br>PERIPHID4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]|
||CPU_TraceFunnel_<br>PERIPHID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]|
||CPU_TraceFunnel_<br>PERIPHID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number[11]|Part_Number[10]|Part_Number[9]|Part_Number[8]|
||CPU_TraceFunnel_<br>PERIPHID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]|
||CPU_TraceFunnel_<br>PERIPHID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|CUSTOM[3]|CUSTOM[2]|CUSTOM[1]|CUSTOM[0]|
||CPU_TraceFunnel_<br>COMPID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_TraceFunnel_<br>COMPID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CPU_TraceFunnel_<br>COMPID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CPU_TraceFunnel_<br>COMPID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CA9_DBG_<br>DBGDIDR|WRPs[3]|WRPs[2]|WRPs[1]|WRPs[0]|BRPs[3]|BRPs[2]|BRPs[1]|BRPs[0]|
|||CTX_CMPs[3]|CTX_CMPs[2]|CTX_CMPs[1]|CTX_CMPs[0]|Version[3]|Version[2]|Version[1]|Version[0]|
|||DEVID_imp|nSUHD_imp|PCSR_imp|SE_imp|-|-|-|-|
|||Variant[3]|Variant[2]|Variant[1]|Variant[0]|Revision[3]|Revision[2]|Revision[1]|Revision[0]|
||CA9_DBG_<br>DBGWFAR|ADDRESS[31]|ADDRESS[30]|ADDRESS[29]|ADDRESS[28]|ADDRESS[27]|ADDRESS[26]|ADDRESS[25]|ADDRESS[24]|
|||ADDRESS[23]|ADDRESS[22]|ADDRESS[21]|ADDRESS[20]|ADDRESS[19]|ADDRESS[18]|ADDRESS[17]|ADDRESS[16]|
|||ADDRESS[15]|ADDRESS[14]|ADDRESS[13]|ADDRESS[12]|ADDRESS[11]|ADDRESS[10]|ADDRESS[9]|ADDRESS[8]|
|||ADDRESS[7]|ADDRESS[6]|ADDRESS[5]|ADDRESS[4]|ADDRESS[3]|ADDRESS[2]|ADDRESS[1]|ADDRESS[0]|
||CA9_DBG_<br>DBGVCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||FIQ|IRQ|-|DataAbort|PrefetchAbort|SVC|Undef|Reset|
||CA9_DBG_<br>DBGDTRRXext|Host_to_target_data<br>[31]|Host_to_target_data<br>[30]|Host_to_target_data<br>[29]|Host_to_target_data<br>[28]|Host_to_target_data<br>[27]|Host_to_target_data<br>[26]|Host_to_target_data<br>[25]|Host_to_target_data<br>[24]|
|||Host_to_target_data<br>[23]|Host_to_target_data<br>[22]|Host_to_target_data<br>[21]|Host_to_target_data<br>[20]|Host_to_target_data<br>[19]|Host_to_target_data<br>[18]|Host_to_target_data<br>[17]|Host_to_target_data<br>[16]|
|||Host_to_target_data<br>[15]|Host_to_target_data<br>[14]|Host_to_target_data<br>[13]|Host_to_target_data<br>[12]|Host_to_target_data<br>[11]|Host_to_target_data<br>[10]|Host_to_target_data<br>[9]|Host_to_target_data<br>[8]|
|||Host_to_target_data<br>[7]|Host_to_target_data<br>[6]|Host_to_target_data<br>[5]|Host_to_target_data<br>[4]|Host_to_target_data<br>[3]|Host_to_target_data<br>[2]|Host_to_target_data<br>[1]|Host_to_target_data<br>[0]|
||CA9_DBG_DBGITR|Instruction[31]|Instruction[30]|Instruction[29]|Instruction[28]|Instruction[27]|Instruction[26]|Instruction[25]|Instruction[24]|
|||Instruction[23]|Instruction[22]|Instruction[21]|Instruction[20]|Instruction[19]|Instruction[18]|Instruction[17]|Instruction[16]|
|||Instruction[15]|Instruction[14]|Instruction[13]|Instruction[12]|Instruction[11]|Instruction[10]|Instruction[9]|Instruction[8]|
|||Instruction[7]|Instruction[6]|Instruction[5]|Instruction[4]|Instruction[3]|Instruction[2]|Instruction[1]|Instruction[0]|
||CA9_DBG_<br>DBGPCSR|PC[29]|PC[28]|PC[27]|PC[26]|PC[25]|PC[24]|PC[23]|PC[22]|
|||PC[21]|PC[20]|PC[19]|PC[18]|PC[17]|PC[16]|PC[15]|PC[14]|
|||PC[13]|PC[12]|PC[11]|PC[10]|PC[9]|PC[8]|PC[7]|PC[6]|
|||PC[5]|PC[4]|PC[3]|PC[2]|PC[1]|PC[0]|Meaning_of_PC[1]|Meaning_of_PC[0]|
||CA9_DBG_<br>DBGDSCRext|-|Rxfull|Txfull|-|RXfull_l|TXfull_l|PipeAdv|InstrCompl_l|
|||-|-|ExtDCCmode[1]|ExtDCCmode[0]|ADAdiscard,|NS|SPNIDdis|SPIDdis|
|||MDBGen|HDBGen|ITRen|UDCCdis|INTdis|DBGack|-|UND_l|
|||ADABORT_l|SDABORT_l|MOE[3]|MOE[2]|MOE[1]|MOE[0]|RESTARTED|HALTED|
||CA9_DBG_<br>DBGDTRTXext|Target_to_host_data<br>[31]|Target_to_host_data<br>[30]|Target_to_host_data<br>[29]|Target_to_host_data<br>[28]|Target_to_host_data<br>[27]|Target_to_host_data<br>[26]|Target_to_host_data<br>[25]|Target_to_host_data<br>[24]|
|||Target_to_host_data<br>[23]|Target_to_host_data<br>[22]|Target_to_host_data<br>[21]|Target_to_host_data<br>[20]|Target_to_host_data<br>[19]|Target_to_host_data<br>[18]|Target_to_host_data<br>[17]|Target_to_host_data<br>[16]|
|||Target_to_host_data<br>[15]|Target_to_host_data<br>[14]|Target_to_host_data<br>[13]|Target_to_host_data<br>[12]|Target_to_host_data<br>[11]|Target_to_host_data<br>[10]|Target_to_host_data<br>[9]|Target_to_host_data<br>[8]|
|||Target_to_host_data<br>[7]|Target_to_host_data<br>[6]|Target_to_host_data<br>[5]|Target_to_host_data<br>[4]|Target_to_host_data<br>[3]|Target_to_host_data<br>[2]|Target_to_host_data<br>[1]|Target_to_host_data<br>[0]|
||CA9_DBG_<br>DBGDRCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|Cancel BIU<br>Requests|Clear Sticky<br>Pipeline<br>Advanceflag|Clear Sticky<br>Exceptions<br>flags|Restart<br>request|Halt<br>request|
||CA9_DBG_DBGBVR<br>0|Breakpoint[31]|Breakpoint[30]|Breakpoint[29]|Breakpoint[28]|Breakpoint[27]|Breakpoint[26]|Breakpoint[25]|Breakpoint[24]|
|||Breakpoint[23]|Breakpoint[22]|Breakpoint[21]|Breakpoint[20]|Breakpoint[19]|Breakpoint[18]|Breakpoint[17]|Breakpoint[16]|
|||Breakpoint[15]|Breakpoint[14]|Breakpoint[13]|Breakpoint[12]|Breakpoint[11]|Breakpoint[10]|Breakpoint[9]|Breakpoint[8]|
|||Breakpoint[7]|Breakpoint[6]|Breakpoint[5]|Breakpoint[4]|Breakpoint[3]|Breakpoint[2]|Breakpoint[1]|Breakpoint[0]|
||CA9_DBG_DBGBVR<br>1|Breakpoint[31]|Breakpoint[30]|Breakpoint[29]|Breakpoint[28]|Breakpoint[27]|Breakpoint[26]|Breakpoint[25]|Breakpoint[24]|
|||Breakpoint[23]|Breakpoint[22]|Breakpoint[21]|Breakpoint[20]|Breakpoint[19]|Breakpoint[18]|Breakpoint[17]|Breakpoint[16]|
|||Breakpoint[15]|Breakpoint[14]|Breakpoint[13]|Breakpoint[12]|Breakpoint[11]|Breakpoint[10]|Breakpoint[9]|Breakpoint[8]|
|||Breakpoint[7]|Breakpoint[6]|Breakpoint[5]|Breakpoint[4]|Breakpoint[3]|Breakpoint[2]|Breakpoint[1]|Breakpoint[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_DBG_DBGBVR<br>2|Breakpoint[31]|Breakpoint[30]|Breakpoint[29]|Breakpoint[28]|Breakpoint[27]|Breakpoint[26]|Breakpoint[25]|Breakpoint[24]|
|||Breakpoint[23]|Breakpoint[22]|Breakpoint[21]|Breakpoint[20]|Breakpoint[19]|Breakpoint[18]|Breakpoint[17]|Breakpoint[16]|
|||Breakpoint[15]|Breakpoint[14]|Breakpoint[13]|Breakpoint[12]|Breakpoint[11]|Breakpoint[10]|Breakpoint[9]|Breakpoint[8]|
|||Breakpoint[7]|Breakpoint[6]|Breakpoint[5]|Breakpoint[4]|Breakpoint[3]|Breakpoint[2]|Breakpoint[1]|Breakpoint[0]|
||CA9_DBG_DBGBVR<br>3|Breakpoint[31]|Breakpoint[30]|Breakpoint[29]|Breakpoint[28]|Breakpoint[27]|Breakpoint[26]|Breakpoint[25]|Breakpoint[24]|
|||Breakpoint[23]|Breakpoint[22]|Breakpoint[21]|Breakpoint[20]|Breakpoint[19]|Breakpoint[18]|Breakpoint[17]|Breakpoint[16]|
|||Breakpoint[15]|Breakpoint[14]|Breakpoint[13]|Breakpoint[12]|Breakpoint[11]|Breakpoint[10]|Breakpoint[9]|Breakpoint[8]|
|||Breakpoint[7]|Breakpoint[6]|Breakpoint[5]|Breakpoint[4]|Breakpoint[3]|Breakpoint[2]|Breakpoint[1]|Breakpoint[0]|
||CA9_DBG_DBGBVR<br>4|Breakpoint[31]|Breakpoint[30]|Breakpoint[29]|Breakpoint[28]|Breakpoint[27]|Breakpoint[26]|Breakpoint[25]|Breakpoint[24]|
|||Breakpoint[23]|Breakpoint[22]|Breakpoint[21]|Breakpoint[20]|Breakpoint[19]|Breakpoint[18]|Breakpoint[17]|Breakpoint[16]|
|||Breakpoint[15]|Breakpoint[14]|Breakpoint[13]|Breakpoint[12]|Breakpoint[11]|Breakpoint[10]|Breakpoint[9]|Breakpoint[8]|
|||Breakpoint[7]|Breakpoint[6]|Breakpoint[5]|Breakpoint[4]|Breakpoint[3]|Breakpoint[2]|Breakpoint[1]|Breakpoint[0]|
||CA9_DBG_DBGBVR<br>5|Breakpoint[31]|Breakpoint[30]|Breakpoint[29]|Breakpoint[28]|Breakpoint[27]|Breakpoint[26]|Breakpoint[25]|Breakpoint[24]|
|||Breakpoint[23]|Breakpoint[22]|Breakpoint[21]|Breakpoint[20]|Breakpoint[19]|Breakpoint[18]|Breakpoint[17]|Breakpoint[16]|
|||Breakpoint[15]|Breakpoint[14]|Breakpoint[13]|Breakpoint[12]|Breakpoint[11]|Breakpoint[10]|Breakpoint[9]|Breakpoint[8]|
|||Breakpoint[7]|Breakpoint[6]|Breakpoint[5]|Breakpoint[4]|Breakpoint[3]|Breakpoint[2]|Breakpoint[1]|Breakpoint[0]|
||CA9_DBG_DBGBCR<br>0|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|M[2]|M[1]|M[0]|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|-|-|SP[1]|SP[0]|B|
||CA9_DBG_DBGBCR<br>1|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|M[2]|M[1]|M[0]|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|-|-|SP[1]|SP[0]|B|
||CA9_DBG_DBGBCR<br>2|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|M[2]|M[1]|M[0]|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|-|-|SP[1]|SP[0]|B|
||CA9_DBG_DBGBCR<br>3|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|M[2]|M[1]|M[0]|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|-|-|SP[1]|SP[0]|B|
||CA9_DBG_DBGBCR<br>4|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|M[2]|M[1]|M[0]|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|-|-|SP[1]|SP[0]|B|
||CA9_DBG_DBGBCR<br>5|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|M[2]|M[1]|M[0]|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|-|-|SP[1]|SP[0]|B|
||CA9_DBG_<br>DBGWVR0|Watchpoint[31]|Watchpoint[30]|Watchpoint[29]|Watchpoint[28]|Watchpoint[27]|Watchpoint[26]|Watchpoint[25]|Watchpoint[24]|
|||Watchpoint[23]|Watchpoint[22]|Watchpoint[21]|Watchpoint[20]|Watchpoint[19]|Watchpoint[18]|Watchpoint[17]|Watchpoint[16]|
|||Watchpoint[15]|Watchpoint[14]|Watchpoint[13]|Watchpoint[12]|Watchpoint[11]|Watchpoint[10]|Watchpoint[9]|Watchpoint[8]|
|||Watchpoint[7]|Watchpoint[6]|Watchpoint[5]|Watchpoint[4]|Watchpoint[3]|Watchpoint[2]|Watchpoint[1]|Watchpoint[0]|
||CA9_DBG_<br>DBGWVR1|Watchpoint[31]|Watchpoint[30]|Watchpoint[29]|Watchpoint[28]|Watchpoint[27]|Watchpoint[26]|Watchpoint[25]|Watchpoint[24]|
|||Watchpoint[23]|Watchpoint[22]|Watchpoint[21]|Watchpoint[20]|Watchpoint[19]|Watchpoint[18]|Watchpoint[17]|Watchpoint[16]|
|||Watchpoint[15]|Watchpoint[14]|Watchpoint[13]|Watchpoint[12]|Watchpoint[11]|Watchpoint[10]|Watchpoint[9]|Watchpoint[8]|
|||Watchpoint[7]|Watchpoint[6]|Watchpoint[5]|Watchpoint[4]|Watchpoint[3]|Watchpoint[2]|Watchpoint[1]|Watchpoint[0]|
||CA9_DBG_<br>DBGWVR2|Watchpoint[31]|Watchpoint[30]|Watchpoint[29]|Watchpoint[28]|Watchpoint[27]|Watchpoint[26]|Watchpoint[25]|Watchpoint[24]|
|||Watchpoint[23]|Watchpoint[22]|Watchpoint[21]|Watchpoint[20]|Watchpoint[19]|Watchpoint[18]|Watchpoint[17]|Watchpoint[16]|
|||Watchpoint[15]|Watchpoint[14]|Watchpoint[13]|Watchpoint[12]|Watchpoint[11]|Watchpoint[10]|Watchpoint[9]|Watchpoint[8]|
|||Watchpoint[7]|Watchpoint[6]|Watchpoint[5]|Watchpoint[4]|Watchpoint[3]|Watchpoint[2]|Watchpoint[1]|Watchpoint[0]|
||CA9_DBG_<br>DBGWVR3|Watchpoint[31]|Watchpoint[30]|Watchpoint[29]|Watchpoint[28]|Watchpoint[27]|Watchpoint[26]|Watchpoint[25]|Watchpoint[24]|
|||Watchpoint[23]|Watchpoint[22]|Watchpoint[21]|Watchpoint[20]|Watchpoint[19]|Watchpoint[18]|Watchpoint[17]|Watchpoint[16]|
|||Watchpoint[15]|Watchpoint[14]|Watchpoint[13]|Watchpoint[12]|Watchpoint[11]|Watchpoint[10]|Watchpoint[9]|Watchpoint[8]|
|||Watchpoint[7]|Watchpoint[6]|Watchpoint[5]|Watchpoint[4]|Watchpoint[3]|Watchpoint[2]|Watchpoint[1]|Watchpoint[0]|
||CA9_DBG_<br>DBGWCR0|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|-|-|E|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|L/S[1]|L/S[0]|SP[1]|SP[0]|W|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_DBG_<br>DBGWCR1|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|-|-|E|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|L/S[1]|L/S[0]|SP[1]|SP[0]|W|
||CA9_DBG_<br>DBGWCR2|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|-|-|E|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|L/S[1]|L/S[0]|SP[1]|SP[0]|W|
||CA9_DBG_<br>DBGWCR3|-|-|-|address_mask[4]|address_mask[3]|address_mask[2]|address_mask[1]|address_mask[0]|
|||-|-|-|E|Linked BRP[3]|Linked BRP[2]|Linked BRP[1]|Linked BRP[0]|
|||Sec_state_cont[1]|Sec_state_cont[0]|-|-|-|-|-|Byte Add_sel[3]|
|||Byte Add_sel[2]|Byte Add_sel[1]|Byte Add_sel[0]|L/S[1]|L/S[0]|SP[1]|SP[0]|W|
||CA9_DBG_MIDR|Implementer[7]|Implementer[6]|Implementer[5]|Implementer[4]|Implementer[3]|Implementer[2]|Implementer[1]|Implementer[0]|
|||Variant[3]|Variant[2]|Variant[1]|Variant[0]|Architecture[3]|Architecture[2]|Architecture[1]|Architecture[0]|
|||part number[11]|part number[10]|part number[9]|part number[8]|part number[7]|part number[6]|part number[5]|part number[4]|
|||part number[3]|part number[2]|part number[1]|part number[0]|Revision[3]|Revision[2]|Revision[1]|Revision[0]|
||CA9_DBG_CTR|-|-|-|-|CWG[3]|CWG[2]|CWG[1]|CWG[0]|
|||ERG[3]|ERG[2]|ERG[1]|ERG[0]|DminLine[3]|DminLine[2]|DminLine[1]|DminLine[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|IminLine[3]|IminLine[2]|IminLine[1]|IminLine[0]|
||CA9_DBG_TLBTR|-|-|-|-|-|-|-|-|
|||ILSize[7]|ILSize[6]|ILSize[5]|ILSize[4]|ILSize[3]|ILSize[2]|ILSize[1]|ILSize[0]|
|||DLSize[7]|DLSize[6]|DLSize[5]|DLSize[4]|DLSize[3]|DLSize[2]|DLSize[1]|DLSize[0]|
|||-|-|-|-|-|-|TLB_size|uU|
||CA9_DBG_MPIDR|-|U|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|ClusterID[3]|ClusterID[2]|ClusterID[1]|ClusterID[0]|
|||-|-|-|-|-|-|CPUID[1]|CPUID[0]|
||CA9_DBG_REVIDR|ID[31]|ID[30]|ID[29]|ID[28]|ID[27]|ID[26]|ID[25]|ID[24]|
|||ID[23]|ID[22]|ID[21]|ID[20]|ID[19]|ID[18]|ID[17]|ID[16]|
|||ID[15]|ID[14]|ID[13]|ID[12]|ID[11]|ID[10]|ID[9]|ID[8]|
|||ID[7]|ID[6]|ID[5]|ID[4]|ID[3]|ID[2]|ID[1]|ID[0]|
||CA9_DBG_ID_PFR0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||State3[3]|State3[2]|State3[1]|State3[0]|State2[3]|State2[2]|State2[1]|State2[0]|
|||State1[3]|State1[2]|State1[1]|State1[0]|State0[3]|State0[2]|State0[1]|State0[0]|
||CA9_DBG_ID_PFR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Mprofile[3]|Mprofile[2]|Mprofile[1]|Mprofile[0]|
|||Security[3]|Security[2]|Security[1]|Security[0]|model[3]|model[2]|model[1]|model[0]|
||CA9_DBG_ID_DFR0|-|-|-|-|-|-|-|-|
|||Debug Model,<br>M profile[3]|Debug Model,<br>M profile[2]|Debug Model,<br>M profile[1]|Debug Model,<br>M profile[0]|Memory-mapped<br>trace<br>model[3]|Memory-mapped<br>trace<br>model[2]|Memory-mapped<br>trace<br>model[1]|Memory-mapped<br>trace<br>model[0]|
|||Coprocessor<br>trace model[3]|Coprocessor<br>trace model[2]|Coprocessor<br>trace model[1]|Coprocessor<br>trace model[0]|Memory-mapped<br>debug<br>model[3]|Memory-mapped<br>debug<br>model[2]|Memory-mapped<br>debug<br>model[1]|Memory-mapped<br>debug<br>model[0]|
|||Coprocessor<br>Secure debug<br>model[3]|Coprocessor<br>Secure debug<br>model[2]|Coprocessor<br>Secure debug<br>model[1]|Coprocessor<br>Secure debug<br>model[0]|Coprocessor<br>debug model[3]|Coprocessor<br>debug model[2]|Coprocessor<br>debug model[1]|Coprocessor<br>debug model[0]|
||CA9_DBG_ID_<br>MMFR0|Innermost<br>shareability[3]|Innermost<br>shareability2]|Innermost<br>shareability[1]|Innermost<br>shareability[0]|FCSE support[3]|FCSE support[2]|FCSE support[1]|FCSE support[0]|
|||Auxiliary registers[3]|Auxiliary registers[2]|Auxiliary registers[1]|Auxiliary registers[0]|TCM support[3]|TCM support[2]|TCM support[1]|TCM support[0]|
|||Share ability levels[3]|Share ability levels[2]|Share ability levels[1]|Share ability levels[0]|Outermost<br>shareability[3]|Outermost<br>shareability[2]|Outermost<br>shareability[1]|Outermost<br>shareability[0]|
|||PMSA support[3]|PMSA support[2]|PMSA support[1]|PMSA support[0]|VMSA support[3]|VMSA support[2]|VMSA support[1]|VMSA support[0]|
||CA9_DBG_ID_<br>MMFR1|Branch Predictor[3]|Branch Predictor[2]|Branch Predictor[1]|Branch Predictor[0]|L1 cache Testand<br>Clean[3]|L1 cache Testand<br>Clean[2]|L1 cache Testand<br>Clean[1]|L1 cache Testand<br>Clean[0]|
|||L1 unified cache[3]|L1 unified cache[2]|L1 unified cache1]|L1 unified cache[0]|L1 Harvard cache[3]|L1 Harvard cache[2]|L1 Harvard cache[1]|L1 Harvard cache[0]|
|||L1 unified cache<br>s/w[3]|L1 unified cache<br>s/w[2]|L1 unified cache<br>s/w[1]|L1 unified cache<br>s/w[0]|L1 Harvard cache<br>s/w[3]|L1 Harvard cache<br>s/w[2]|L1 Harvard cache<br>s/w[1]|L1 Harvard cache<br>s/w[0]|
|||L1 unified cache VA[3]|L1 unified cache VA[2]|L1 unified cache VA[1]|L1 unified cache VA[0]|L1 Harvard cache<br>VA[3]|L1 Harvard cache<br>VA[2]|L1 Harvard cache<br>VA[1]|L1 Harvard cache<br>VA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_DBG_ID_<br>MMFR2|HW access flag[3]|HW access flag[2]|HW access flag[1]|HW access flag[0]|WFI stall[3]|WFI stall[2]|WFI stall[1]|WFI stall[0]|
|||Mem barrier[3]|Mem barrier[2]|Mem barrier[1]|Mem barrier[0]|Unified TLB[3]|Unified TLB[2]|Unified TLB[1]|Unified TLB[0]|
|||Harvard TLB[3]|Harvard TLB[2]|Harvard TLB[1]|Harvard TLB[0]|L1 Harvard range[3]|L1 Harvard range[2]|L1 Harvard range[1]|L1 Harvard range[0]|
|||L1 Harvard bg<br>prefetch[3]|L1 Harvard bg<br>prefetch[2]|L1 Harvard bg<br>prefetch[1]|L1 Harvard bg<br>prefetch[0]|L1 Harvard fg<br>prefetch[3]|L1 Harvard fg<br>prefetch[2]|L1 Harvard fg<br>prefetch[1]|L1 Harvard fg<br>prefetch[0]|
||CA9_DBG_ID_<br>MMFR3|Supersection<br>support[3]|Supersection<br>support[2]|Supersection<br>support[1]|Supersection<br>support[0]|-|-|-|-|
|||Coherent walk[3]|Coherent walk[2]|Coherent walk[1]|Coherent walk[0]|-|-|-|-|
|||Maintenance<br>broadcast[3]|Maintenance<br>broadcast[2]|Maintenance<br>broadcast[1]|Maintenance<br>broadcast[0]|BP maintain[3]|BP maintain[2]|BP maintain[1]|BP maintain[0]|
|||Cache maintenance<br>s/w[3]|Cache maintenance<br>s/w[2]|Cache maintenance<br>s/w[1]|Cache maintenance<br>s/w[0]|Cache<br>maintenance MVA[3]|Cache<br>maintenance MVA[2]|Cache<br>maintenance MVA[1]|Cache<br>maintenance MVA[0]|
||CA9_DBG_ID_<br>ISAR0|-|-|-|-|Divide_instrs[3]|Divide_instrs[2]|Divide_instrs[1]|Divide_instrs[0]|
|||Debug_instrs[3]|Debug_instrs[2]|Debug_instrs[1]|Debug_instrs[0]|Coproc_instrs[3]|Coproc_instrs[2]|Coproc_instrs[1]|Coproc_instrs[0]|
|||CmpBranch_instrs[3]|CmpBranch_instrs[2]|CmpBranch_instrs[1]|CmpBranch_instrs[0]|Bitfield_instrs[3]|Bitfield_instrs[2]|Bitfield_instrs[1]|Bitfield_instrs[0]|
|||BitCount_instrs[3]|BitCount_instrs[2]|BitCount_instrs[1]|BitCount_instrs[0]|Swap_instrs[3]|Swap_instrs[2]|Swap_instrs[1]|Swap_instrs[0]|
||CA9_DBG_ID_<br>ISAR1|Jazelle_instrs[3]|Jazelle_instrs[2]|Jazelle_instrs[1]|Jazelle_instrs[0]|Interwork_instrs[3]|Interwork_instrs[2]|Interwork_instrs[1]|Interwork_instrs[0]|
|||Immediate_instrs[3]|Immediate_instrs[2]|Immediate_instrs[1]|Immediate_instrs[0]|IfThen_instrs[3]|IfThen_instrs[2]|IfThen_instrs[1]|IfThen_instrs[0]|
|||Extend_instrs[3]|Extend_instrs[2]|Extend_instrs[1]|Extend_instrs[0]|Except_AR_instrs[3]|Except_AR_instrs[2]|Except_AR_instrs[1]|Except_AR_instrs[0]|
|||Except_instrs[3]|Except_instrs[2]|Except_instrs[1]|Except_instrs[0]|Endian_instrs[3]|Endian_instrs[2]|Endian_instrs[1]|Endian_instrs[0]|
||CA9_DBG_ID_<br>ISAR2|Reversal_instrs[3]|Reversal_instrs[2]|Reversal_instrs[1]|Reversal_instrs[0]|PSR_AR_instrs[3]|PSR_AR_instrs[2]|PSR_AR_instrs[1]|PSR_AR_instrs[0]|
|||MultU_instrs[3]|MultU_instrs[2]|MultU_instrs[1]|MultU_instrs[0]|Mult_instrs[3]|Mult_instrs[2]|Mult_instrs[1]|Mult_instrs[0]|
|||Mult_instrs[3]|Mult_instrs[2]|Mult_instrs[1]|Mult_instrs[0]|MultiAccessInt_<br>instrs[3]|MultiAccessInt_<br>instrs[2]|MultiAccessInt_<br>instrs[1]|MultiAccessInt_<br>instrs[0]|
|||MemHint_instrs[3]|MemHint_instrs[2]|MemHint_instrs[1]|MemHint_instrs[0]|LoadStore_instrs[3]|LoadStore_instrs[2]|LoadStore_instrs[1]|LoadStore_instrs[0]|
||CA9_DBG_ID_<br>ISAR3|ThumbEE_extn_<br>instrs[3]|ThumbEE_extn_<br>instrs[2]|ThumbEE_extn_<br>instrs[1]|ThumbEE_extn_<br>instrs[0]|TrueNOP_instrs[3]|TrueNOP_instrs[2]|TrueNOP_instrs[1]|TrueNOP_instrs[0]|
|||ThumbCopy_<br>instrs[3]|ThumbCopy_<br>instrs[2]|ThumbCopy_<br>instrs[1]|ThumbCopy_<br>instrs[0]|TabBranch_instrs[3]|TabBranch_instrs[2]|TabBranch_instrs[1]|TabBranch_instrs[0]|
|||SynchPrim_<br>instrs[3]|SynchPrim_<br>instrs[2]|SynchPrim_<br>instrs[1]|SynchPrim_<br>instrs[0]|SVC_instrs[3]|SVC_instrs[2]|SVC_instrs[1]|SVC_instrs[0]|
|||SIMD_instrs[3]|SIMD_instrs[2]|SIMD_instrs[1]|SIMD_instrs[0]|Saturate_instrs[3]|Saturate_instrs[2]|Saturate_instrs[1]|Saturate_instrs[0]|
||CA9_DBG_ID_<br>ISAR4|SWP_frac[3]|SWP_frac[2]|SWP_frac[1]|SWP_frac[0]|PSR_M_instrs[3]|PSR_M_instrs[2]|PSR_M_instrs[1]|PSR_M_instrs[0]|
|||SynchPrim_instrs_frac<br>[3]|SynchPrim_instrs_frac<br>[2]|SynchPrim_instrs_frac<br>[1]|SynchPrim_instrs_frac<br>[0]|Barrier_instrs[3]|Barrier_instrs[2]|Barrier_instrs[1]|Barrier_instrs[0]|
|||SMC_instrs[3]|SMC_instrs[2]|SMC_instrs[1]|SMC_instrs[0]|Writeback_instrs[3]|Writeback_instrs[2]|Writeback_instrs[1]|Writeback_instrs[0]|
|||WithShifts_instrs[3]|WithShifts_instrs[2]|WithShifts_instrs[1]|WithShifts_instrs[0]|Unpriv_instrs[3]|Unpriv_instrs[2]|Unpriv_instrs[1]|Unpriv_instrs[0]|
||CA9_DBG_<br>CLAIMSET|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CLAIMSET[7]|CLAIMSET[6]|CLAIMSET[5]|CLAIMSET[4]|CLAIMSET[3]|CLAIMSET[2]|CLAIMSET[1]|CLAIMSET[0]|
||CA9_DBG_<br>CLAIMCLR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CLAIMCLR[7]|CLAIMCLR[6]|CLAIMCLR[5]|CLAIMCLR[4]|CLAIMCLR[3]|CLAIMCLR[2]|CLAIMCLR[1]|CLAIMCLR[0]|
||CA9_DBG_LAR|ACCESS_W[31]|ACCESS_W[30]|ACCESS_W[29]|ACCESS_W[28]|ACCESS_W[27]|ACCESS_W[26]|ACCESS_W[25]|ACCESS_W[24]|
|||ACCESS_W[23]|ACCESS_W[22]|ACCESS_W[21]|ACCESS_W[20]|ACCESS_W[19]|ACCESS_W[18]|ACCESS_W[17]|ACCESS_W[16]|
|||ACCESS_W[15]|ACCESS_W[14]|ACCESS_W[13]|ACCESS_W[12]|ACCESS_W[11]|ACCESS_W[10]|ACCESS_W[9]|ACCESS_W[8]|
|||ACCESS_W[7]|ACCESS_W[6]|ACCESS_W[5]|ACCESS_W[4]|ACCESS_W[3]|ACCESS_W[2]|ACCESS_W[1]|ACCESS_W[0]|
||CA9_DBG_LSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|LOCKTYPE|LOCKGRANT|LOCKEXIST|
||CA9_DBG_<br>AUTHSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SNID[1]|SNID[0]|SID[1]|SID[0]|NSNID[1]|NSNID[0]|NSID[1]|NSID[0]|
||CA9_DBG_DEVID|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|PCsample[3]|PCsample[2]|PCsample[1]|PCsample[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**||
|---|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_DBG_<br>DEVTYPE|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Sub_type[3]|Sub_type[2]|Sub_type[1]|Sub_type[0]|Main_class[3]|Main_class[2]|Main_class[1]|Main_class[0]||
||CA9_DBG_<br>PERIPHID4|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]||
||CA9_DBG_<br>PERIPHID0|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]||
||CA9_DBG_<br>PERIPHID1|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number<br>[11]|Part_Number<br>[10]|Part_Number[9]|Part_Number[8]||
||CA9_DBG_<br>PERIPHID2|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]||
||CA9_DBG_<br>PERIPHID3|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|CUSTOM[3]|CUSTOM[2]|CUSTOM[1]|CUSTOM[0]||
||CA9_DBG_<br>COMPID0|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||
||CA9_DBG_<br>COMPID1|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||
||CA9_DBG_<br>COMPID2|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||
||CA9_DBG_<br>COMPID3|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||
||CA9_PMU_<br>PMXEVCNTR0|PMNX[31]|PMNX[30]|PMNX[29]|PMNX[28]|PMNX[27]|PMNX[26]|PMNX[25]|PMNX[24]||
|||PMNX[23]|PMNX[22]|PMNX[21]|PMNX[20]|PMNX[19]|PMNX[18]|PMNX[17]|PMNX[16]||
|||PMNX[15]|PMNX[14]|PMNX[13]|PMNX[12]|PMNX[11]|PMNX[10]|PMNX[9]|PMNX[8]||
|||PMNX[7]|PMNX[6]|PMNX[5]|PMNX[4]|PMNX[3]|PMNX[2]|PMNX[1]|PMNX[0]||
||CA9_PMU_<br>PMXEVCNTR1|PMNX[31]|PMNX[30]|PMNX[29]|PMNX[28]|PMNX[27]|PMNX[26]|PMNX[25]|PMNX[24]||
|||PMNX[23]|PMNX[22]|PMNX[21]|PMNX[20]|PMNX[19]|PMNX[18]|PMNX[17]|PMNX[16]||
|||PMNX[15]|PMNX[14]|PMNX[13]|PMNX[12]|PMNX[11]|PMNX[10]|PMNX[9]|PMNX[8]||
|||PMNX[7]|PMNX[6]|PMNX[5]|PMNX[4]|PMNX[3]|PMNX[2]|PMNX[1]|PMNX[0]||
||CA9_PMU_<br>PMXEVCNTR2|PMNX[31]|PMNX[30]|PMNX[29]|PMNX[28]|PMNX[27]|PMNX[26]|PMNX[25]|PMNX[24]||
|||PMNX[23]|PMNX[22]|PMNX[21]|PMNX[20]|PMNX[19]|PMNX[18]|PMNX[17]|PMNX[16]||
|||PMNX[15]|PMNX[14]|PMNX[13]|PMNX[12]|PMNX[11]|PMNX[10]|PMNX[9]|PMNX[8]||
|||PMNX[7]|PMNX[6]|PMNX[5]|PMNX[4]|PMNX[3]|PMNX[2]|PMNX[1]|PMNX[0]||
||CA9_PMU_<br>PMXEVCNTR3|PMNX[31]|PMNX[30]|PMNX[29]|PMNX[28]|PMNX[27]|PMNX[26]|PMNX[25]|PMNX[24]||
|||PMNX[23]|PMNX[22]|PMNX[21]|PMNX[20]|PMNX[19]|PMNX[18]|PMNX[17]|PMNX[16]||
|||PMNX[15]|PMNX[14]|PMNX[13]|PMNX[12]|PMNX[11]|PMNX[10]|PMNX[9]|PMNX[8]||
|||PMNX[7]|PMNX[6]|PMNX[5]|PMNX[4]|PMNX[3]|PMNX[2]|PMNX[1]|PMNX[0]||
||CA9_PMU_<br>PMXEVCNTR4|PMNX[31]|PMNX[30]|PMNX[29]|PMNX[28]|PMNX[27]|PMNX[26]|PMNX[25]|PMNX[24]||
|||PMNX[23]|PMNX[22]|PMNX[21]|PMNX[20]|PMNX[19]|PMNX[18]|PMNX[17]|PMNX[16]||
|||PMNX[15]|PMNX[14]|PMNX[13]|PMNX[12]|PMNX[11]|PMNX[10]|PMNX[9]|PMNX[8]||
|||PMNX[7]|PMNX[6]|PMNX[5]|PMNX[4]|PMNX[3]|PMNX[2]|PMNX[1]|PMNX[0]||

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_PMU_<br>PMXEVCNTR5|PMNX[31]|PMNX[30]|PMNX[29]|PMNX[28]|PMNX[27]|PMNX[26]|PMNX[25]|PMNX[24]|
|||PMNX[23]|PMNX[22]|PMNX[21]|PMNX[20]|PMNX[19]|PMNX[18]|PMNX[17]|PMNX[16]|
|||PMNX[15]|PMNX[14]|PMNX[13]|PMNX[12]|PMNX[11]|PMNX[10]|PMNX[9]|PMNX[8]|
|||PMNX[7]|PMNX[6]|PMNX[5]|PMNX[4]|PMNX[3]|PMNX[2]|PMNX[1]|PMNX[0]|
||CA9_PMU_<br>PMCCNTR|CCNT[31]|CCNT[30]|CCNT[29]|CCNT[28]|CCNT[27]|CCNT[26]|CCNT[25]|CCNT[24]|
|||CCNT[23]|CCNT[22]|CCNT[21]|CCNT[20]|CCNT[19]|CCNT[18]|CCNT[17]|CCNT[16]|
|||CCNT[15]|CCNT[14]|CCNT[13]|CCNT[12]|CCNT[11]|CCNT[10]|CCNT[9]|CCNT[8]|
|||CCNT[7]|CCNT[6]|CCNT[5]|CCNT[4]|CCNT[3]|CCNT[2]|CCNT[1]|CCNT[0]|
||CA9_PMU_<br>PMXEVTYPER0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SEL[4]|SEL[3]|SEL[2]|SEL[1]|SEL[0]|
||CA9_PMU_<br>PMXEVTYPER1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SEL[4]|SEL[3]|SEL[2]|SEL[1]|SEL[0]|
||CA9_PMU_<br>PMXEVTYPER2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SEL[4]|SEL[3]|SEL[2]|SEL[1]|SEL[0]|
||CA9_PMU_<br>PMXEVTYPER3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SEL[4]|SEL[3]|SEL[2]|SEL[1]|SEL[0]|
||CA9_PMU_<br>PMXEVTYPER4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SEL[4]|SEL[3]|SEL[2]|SEL[1]|SEL[0]|
||CA9_PMU_<br>PMXEVTYPER5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|SEL[4]|SEL[3]|SEL[2]|SEL[1]|SEL[0]|
||CA9_PMU_<br>PMCNTENSET|C|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|P5|P4|P3|P2|P1|P0|
||CA9_PMU_<br>PMCNTENCLR|C|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|P5|P4|P3|P2|P1|P0|
||CA9_PMU_<br>PMINTENSET|C|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|P5|P4|P3|P2|P1|P0|
||CA9_PMU_<br>PMINTENCLR|C|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|P5|P4|P3|P2|P1|P0|
||CA9_PMU_<br>PMINTENCLR|C|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|P5|P4|P3|P2|P1|P0|
||CA9_PMU_PMOVSR|C|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|P5|P4|P3|P2|P1|P0|
||CA9_PMU_<br>PMSWINC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|P5|P4|P3|P2|P1|P0|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_PMU_PMCR|IMP[7]|IMP[6]|IMP[5]|IMP[4]|IMP[3]|IMP[2]|IMP[1]|IMP[0]|
|||IDCODE[7]|IDCODE[6]|IDCODE[5]|IDCODE[4]|IDCODE[3]|IDCODE[2]|IDCODE[1]|IDCODE[0]|
|||N[4]|N[3]|N[2]|N[1]|N[0]|-|-|-|
|||-|-|DP|X|D|C|P|E|
||CA9_PMU_<br>CLAIMSET|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CLAIMSET[7]|CLAIMSET[6]|CLAIMSET[5]|CLAIMSET[4]|CLAIMSET[3]|CLAIMSET[2]|CLAIMSET[1]|CLAIMSET[0]|
||CA9_PMU_<br>CLAIMCLR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CLAIMCLR[7]|CLAIMCLR[6]|CLAIMCLR[5]|CLAIMCLR[4]|CLAIMCLR[3]|CLAIMCLR[2]|CLAIMCLR[1]|CLAIMCLR[0]|
||CA9_PMU_LAR|ACCESS_W[31]|ACCESS_W[30]|ACCESS_W[29]|ACCESS_W[28]|ACCESS_W[27]|ACCESS_W[26]|ACCESS_W[25]|ACCESS_W[24]|
|||ACCESS_W[23]|ACCESS_W[22]|ACCESS_W[21]|ACCESS_W[20]|ACCESS_W[19]|ACCESS_W[18]|ACCESS_W[17]|ACCESS_W[16]|
|||ACCESS_W[15]|ACCESS_W[14]|ACCESS_W[13]|ACCESS_W[12]|ACCESS_W[11]|ACCESS_W[10]|ACCESS_W[9]|ACCESS_W[8]|
|||ACCESS_W[7]|ACCESS_W[6]|ACCESS_W[5]|ACCESS_W[4]|ACCESS_W[3]|ACCESS_W[2]|ACCESS_W[1]|ACCESS_W[0]|
||CA9_PMU_LSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|LOCKTYPE|LOCKGRANT|LOCKEXIST|
||CA9_PMU_<br>AUTHSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SNID[1]|SNID[0]|SID[1]|SID[0]|NSNID[1]|NSNID[0]|NSID[1]|NSID[0]|
||CA9_PMU_DEVID|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ID[7]|ID[6]|ID[5]|ID[4]|ID[3]|ID[2]|ID[1]|ID[0]|
||CA9_PMU_<br>DEVTYPE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Sub_type[3]|Sub_type[2]|Sub_type[1]|Sub_type[0]|Main_class[3]|Main_class[2]|Main_class[1]|Main_class[0]|
||CA9_PMU_<br>PERIPHID4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]|
||CA9_PMU_<br>PERIPHID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]|
||CA9_PMU_<br>PERIPHID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number[11]|Part_Number[10]|Part_Number[9]|Part_Number[8]|
||CA9_PMU_<br>PERIPHID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]|
||CA9_PMU_<br>PERIPHID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|CUSTOM[3]|CUSTOM[2]|CUSTOM[1]|CUSTOM[0]|
||CA9_PMU_<br>COMPID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CA9_PMU_<br>COMPID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_PMU_<br>COMPID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CA9_PMU_<br>COMPID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||CA9_CTI_<br>CTICONTROL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|GLBEN|
||CA9_CTI_<br>CTIINTACK|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||INTACK[7]|INTACK[6]|INTACK[5]|INTACK[4]|INTACK[3]|INTACK[2]|INTACK[1]|INTACK[0]|
||CA9_CTI_<br>CTIAPPSET|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|APPSET[3]|APPSET[2]|APPSET[1]|APPSET[0]|
||CA9_CTI_<br>CTIAPPCLEAR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|APPCLEAR[3]|APPCLEAR[2]|APPCLEAR[1]|APPCLEAR[0]|
||CA9_CTI_<br>CTIAPPPULSE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|APPULSE[3]|APPULSE[2]|APPULSE[1]|APPULSE[0]|
||CA9_CTI_CTIINEN0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CA9_CTI_CTIINEN1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CA9_CTI_CTIINEN2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CA9_CTI_CTIINEN3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CA9_CTI_CTIINEN4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CA9_CTI_CTIINEN5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CA9_CTI_CTIINEN6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|
||CA9_CTI_CTIINEN7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGINEN[3]|TRIGINEN[2]|TRIGINEN[1]|TRIGINEN[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_CTI_<br>CTIOUTEN0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CA9_CTI_<br>CTIOUTEN1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CA9_CTI_<br>CTIOUTEN2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CA9_CTI_<br>CTIOUTEN3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CA9_CTI_<br>CTIOUTEN4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CA9_CTI_<br>CTIOUTEN5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CA9_CTI_<br>CTIOUTEN6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CA9_CTI_<br>CTIOUTEN7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|TRIGOUTEN[3]|TRIGOUTEN[2]|TRIGOUTEN[1]|TRIGOUTEN[0]|
||CA9_CTI_<br>CTITRIGINSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TRIGINSTATUS[7]|TRIGINSTATUS[6]|TRIGINSTATUS[5]|TRIGINSTATUS[4]|TRIGINSTATUS[3]|TRIGINSTATUS[2]|TRIGINSTATUS[1]|TRIGINSTATUS[0]|
||CA9_CTI_<br>CTITRIGOUT<br>STATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TRIGOUT<br>STATUS[7]|TRIGOUT<br>STATUS[6]|TRIGOUT<br>STATUS[5]|TRIGOUT<br>STATUS[4]|TRIGOUT<br>STATUS[3]|TRIGOUT<br>STATUS[2]|TRIGOUT<br>STATUS[1]|TRIGOUT<br>STATUS[0]|
||CA9_CTI_<br>CTICHINSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CTCHIN<br>STATUS[3]|CTCHIN<br>STATUS[2]|CTCHIN<br>STATUS[1]|CTCHIN<br>STATUS[0]|
||CA9_CTI_<br>CTICHOUTSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CTCHOUT<br>STATUS[3]|CTCHOUT<br>STATUS[2]|CTCHOUT<br>STATUS[1]|CTCHOUT<br>STATUS[0]|
||CA9_CTI_CTIGATE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|CTIGATEEN3|CTIGATEEN2|CTIGATEEN1|CTIGATEEN0|
||CA9_CTI_ASICCTL|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|ASICCTL[3]|ASICCTL[2]|ASICCTL[1]|ASICCTL[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**||
|---|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_CTI_<br>CLAIMSET|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|CLAIMSET[3]|CLAIMSET[2]|CLAIMSET[1]|CLAIMSET[0]||
||CA9_CTI_<br>CLAIMCLR|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|CLAIMCLR[3]|CLAIMCLR[2]|CLAIMCLR[1]|CLAIMCLR[0]||
||CA9_CTI_LAR|ACCESS_W[31]|ACCESS_W[30]|ACCESS_W[29]|ACCESS_W[28]|ACCESS_W[27]|ACCESS_W[26]|ACCESS_W[25]|ACCESS_W[24]||
|||ACCESS_W[23]|ACCESS_W[22]|ACCESS_W[21]|ACCESS_W[20]|ACCESS_W[19]|ACCESS_W[18]|ACCESS_W[17]|ACCESS_W[16]||
|||ACCESS_W[15]|ACCESS_W[14]|ACCESS_W[13]|ACCESS_W[12]|ACCESS_W[11]|ACCESS_W[10]|ACCESS_W[9]|ACCESS_W[8]||
|||ACCESS_W[7]|ACCESS_W[6]|ACCESS_W[5]|ACCESS_W[4]|ACCESS_W[3]|ACCESS_W[2]|ACCESS_W[1]|ACCESS_W[0]||
||CA9_CTI_LSR|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|LOCKTYPE|LOCKGRANT|LOCKEXIST||
||CA9_CTI_<br>AUTHSTATUS|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||SNID[1]|SNID[0]|SID[1]|SID[0]|NSNID[1]|NSNID[0]|NSID[1]|NSID[0]||
||CA9_CTI_DEVID|-|-|-|-|-|-|-|-||
|||-|-|-|-|CHANWIDTH[3]|CHANWIDTH[2]|CHANWIDTH[1]|CHANWIDTH[0]||
|||TRIGWIDTH[7]|TRIGWIDTH[6]|TRIGWIDTH[5]|TRIGWIDTH[4]|TRIGWIDTH[3]|TRIGWIDTH[2]|TRIGWIDTH[1]|TRIGWIDTH[0]||
|||-|-|-|-|EXTMUXNUM[3]|EXTMUXNUM[2]|EXTMUXNUM[1]|EXTMUXNUM[0]||
||CA9_CTI_DEVTYPE|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Sub_type[3]|Sub_type[2]|Sub_type[1]|Sub_type[0]|Major_type[3]|Major_type[2]|Major_type[1]|Major_type[0]||
||CA9_CTI_<br>PERIPHID4|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]||
||CA9_CTI_<br>PERIPHID0|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]||
||CA9_CTI_<br>PERIPHID1|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number<br>[11]|Part_Number<br>[10]|Part_Number[9]|Part_Number[8]||
||CA9_CTI_<br>PERIPHID2|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]||
||CA9_CTI_<br>PERIPHID3|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|CUSTOM[3]|CUSTOM[2]|CUSTOM[1]|CUSTOM[0]||
||CA9_CTI_COMPID0|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||
||CA9_CTI_COMPID1|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||
||CA9_CTI_COMPID2|-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||-|-|-|-|-|-|-|-||
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]||

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|CA9_CTI_COMPID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||PTM_A9_ETMCR|-|-|Return stack<br>enable|Timestamp<br>enable|Processor select[2]|Processor select<br>[1]|Processor select<br>[0]|-|
|||-|-|-|-|-|-|-|-|
|||Context IDsize[1]|Context IDsize[0]|-|CycleAccurate|-|ProgBit|Debug request<br>control|Branch<br>Broadcast|
|||Stall processor|-|-|-|-|-|-|PowerDown|
||PTM_A9_ETMCCR|ID Register<br>present|-|-|-|Software access<br>support|Trace stop/start block<br>present|Number of Context ID<br>comparators[1]|Number of Context ID<br>comparators[0]|
|||FIFOFULL logic|Number of external<br>outputs[2]|Number of external<br>outputs[1]|Number of external<br>outputs[0]|Number of external<br>inputs[2]|Number of external<br>inputs[1]|Number of external<br>inputs[0]|Sequencer|
|||Numberofcounters[2]|Numberofcounters[1]|Numberofcounters[0]|-|-|-|-|-|
|||-|-|-|-|Number of pairs of<br>address<br>comparators[3]|Number of pairs of<br>address<br>comparators[2]|Number of pairs of<br>address<br>comparators[1]|Number of pairs of<br>address<br>comparators[0]|
||PTM_A9_<br>ETMTRIGGER|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Trigger event[15]|Trigger Event[14]|Trigger Event[13]|Trigger Event[12]|Trigger Event[11]|Trigger Event[10]|Trigger Event[9]|Trigger Event[8]|
|||Trigger Event[7]|Trigger Event[6]|Trigger Event[5]|Trigger Event[4]|Trigger Event[3]|Trigger Event[2]|Trigger Event[1]|Trigger Event[0]|
||PTM_A9_ETMSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Trigger flag|Trace start/stop<br>resource status|ProgBit value|Untraced overflow<br>flag|
||PTM_A9_ETMSCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|MAXCORES[2]|MAXCORES[1]|MAXCORES[0]|-|-|-|FIFOFULL<br>supported|
|||-|-|-|-|-|-|-|-|
||PTM_A9_<br>ETMTSSCR|-|-|-|-|-|-|-|-|
|||Stop addresses[7]|Stop addresses[6]|Stop addresses[5]|Stop addresses[4]|Stop addresses[3]|Stop addresses[2]|Stop addresses[1]|Stop addresses[0]|
|||-|-|-|-|-|-|-|-|
|||Start addresses[7]|Start addresses[6]|Start addresses[5]|Start addresses[4]|Start addresses[3]|Start addresses[2]|Start addresses[1]|Start addresses[0]|
||PTM_A9_<br>ETMTEEVR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Trace Enable<br>event[15]|Trace Enable<br>event[14]|Trace Enable<br>event[13]|Trace Enable<br>event[12]|Trace Enable<br>event[11]|Trace Enable<br>event[10]|Trace Enable event[9]|Trace Enable event[8]|
|||Trace Enable event[7]|Trace Enable event[6]|Trace Enable event[5]|Trace Enable event[4]|Trace Enable event[3]|Trace Enable event[2]|Trace Enable event[1]|Trace Enable event[0]|
||PTM_A9_<br>ETMTECR1|-|-|-|-|-|-|Trace control<br>enable|Exclude/include flag|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||||||Addresscom<br>parators[3]|Addresscom<br>parators[2]|Addresscom<br>parators[1]|Addresscom<br>parators[0]|
||PTM_A9_<br>ETMACVR1|Address[31]|Address[30]|Address[29]|Address[28]|Address[27]|Address[26]|Address[25]|Address[24]|
|||Address[23]|Address[22]|Address[21]|Address[20]|Address[19]|Address[18]|Address[17]|Address[16]|
|||Address[15]|Address[14]|Address[13]|Address[12]|Address[11]|Address[10]|Address[9]|Address[8]|
|||Address[7]|Address[6]|Address[5]|Address[4]|Address[3]|Address[2]|Address[1]|Address[0]|
||PTM_A9_<br>ETMACVR2|Address[31]|Address[30]|Address[29]|Address[28]|Address[27]|Address[26]|Address[25]|Address[24]|
|||Address[23]|Address[22]|Address[21]|Address[20]|Address[19]|Address[18]|Address[17]|Address[16]|
|||Address[15]|Address[14]|Address[13]|Address[12]|Address[11]|Address[10]|Address[9]|Address[8]|
|||Address[7]|Address[6]|Address[5]|Address[4]|Address[3]|Address[2]|Address[1]|Address[0]|
||PTM_A9_<br>ETMACVR3|Address[31]|Address[30]|Address[29]|Address[28]|Address[27]|Address[26]|Address[25]|Address[24]|
|||Address[23]|Address[22]|Address[21]|Address[20]|Address[19]|Address[18]|Address[17]|Address[16]|
|||Address[15]|Address[14]|Address[13]|Address[12]|Address[11]|Address[10]|Address[9]|Address[8]|
|||Address[7]|Address[6]|Address[5]|Address[4]|Address[3]|Address[2]|Address[1]|Address[0]|
||PTM_A9_<br>ETMACVR4|Address[31]|Address[30]|Address[29]|Address[28]|Address[27]|Address[26]|Address[25]|Address[24]|
|||Address[23]|Address[22]|Address[21]|Address[20]|Address[19]|Address[18]|Address[17]|Address[16]|
|||Address[15]|Address[14]|Address[13]|Address[12]|Address[11]|Address[10]|Address[9]|Address[8]|
|||Address[7]|Address[6]|Address[5]|Address[4]|Address[3]|Address[2]|Address[1]|Address[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|PTM_A9_<br>ETMACVR5|Address[31]|Address[30]|Address[29]|Address[28]|Address[27]|Address[26]|Address[25]|Address[24]|
|||Address[23]|Address[22]|Address[21]|Address[20]|Address[19]|Address[18]|Address[17]|Address[16]|
|||Address[15]|Address[14]|Address[13]|Address[12]|Address[11]|Address[10]|Address[9]|Address[8]|
|||Address[7]|Address[6]|Address[5]|Address[4]|Address[3]|Address[2]|Address[1]|Address[0]|
||PTM_A9_<br>ETMACVR6|Address[31]|Address[30]|Address[29]|Address[28]|Address[27]|Address[26]|Address[25]|Address[24]|
|||Address[23]|Address[22]|Address[21]|Address[20]|Address[19]|Address[18]|Address[17]|Address[16]|
|||Address[15]|Address[14]|Address[13]|Address[12]|Address[11]|Address[10]|Address[9]|Address[8]|
|||Address[7]|Address[6]|Address[5]|Address[4]|Address[3]|Address[2]|Address[1]|Address[0]|
||PTM_A9_<br>ETMACVR7|Address[31]|Address[30]|Address[29]|Address[28]|Address[27]|Address[26]|Address[25]|Address[24]|
|||Address[23]|Address[22]|Address[21]|Address[20]|Address[19]|Address[18]|Address[17]|Address[16]|
|||Address[15]|Address[14]|Address[13]|Address[12]|Address[11]|Address[10]|Address[9]|Address[8]|
|||Address[7]|Address[6]|Address[5]|Address[4]|Address[3]|Address[2]|Address[1]|Address[0]|
||PTM_A9_<br>ETMACVR8|Address[31]|Address[30]|Address[29]|Address[28]|Address[27]|Address[26]|Address[25]|Address[24]|
|||Address[23]|Address[22]|Address[21]|Address[20]|Address[19]|Address[18]|Address[17]|Address[16]|
|||Address[15]|Address[14]|Address[13]|Address[12]|Address[11]|Address[10]|Address[9]|Address[8]|
|||Address[7]|Address[6]|Address[5]|Address[4]|Address[3]|Address[2]|Address[1]|Address[0]|
||PTM_A9_<br>ETMACTR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Secure Level[1]|Secure Level[0]|Context ID[1]|Context ID[0]|
|||-|-|-|-|-|Access Type[2]|Access Type[1]|Access Type[0]|
||PTM_A9_<br>ETMACTR2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Secure Level[1]|Secure Level[0]|Context ID[1]|Context ID[0]|
|||-|-|-|-|-|Access Type[2]|Access Type[1]|Access Type[0]|
||PTM_A9_<br>ETMACTR3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Secure Level[1]|Secure Level[0]|Context ID[1]|Context ID[0]|
|||-|-|-|-|-|Access Type[2]|Access Type[1]|Access Type[0]|
||PTM_A9_<br>ETMACTR4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Secure Level[1]|Secure Level[0]|Context ID[1]|Context ID[0]|
|||-|-|-|-|-|Access Type[2]|Access Type[1]|Access Type[0]|
||PTM_A9_<br>ETMACTR5|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Secure Level[1]|Secure Level[0]|Context ID[1]|Context ID[0]|
|||-|-|-|-|-|Access Type[2]|Access Type[1]|Access Type[0]|
||PTM_A9_<br>ETMACTR6|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Secure Level[1]|Secure Level[0]|Context ID[1]|Context ID[0]|
|||-|-|-|-|-|Access Type[2]|Access Type[1]|Access Type[0]|
||PTM_A9_<br>ETMACTR7|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Secure Level[1]|Secure Level[0]|Context ID[1]|Context ID[0]|
|||-|-|-|-|-|Access Type[2]|Access Type[1]|Access Type[0]|
||PTM_A9_<br>ETMACTR8|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Secure Level[1]|Secure Level[0]|Context ID[1]|Context ID[0]|
|||-|-|-|-|-|Access Type[2]|Access Type[1]|Access Type[0]|
||PTM_A9_ETMCNTR<br>LDVR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||value[15]|value[14]|value[13]|value[12]|value[11]|value[10]|value[9]|value[8]|
|||value[7]|value[6]|value[5]|value[4]|value[3]|value[2]|value[1]|value[0]|
||PTM_A9_<br>ETMCNTRLDVR2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||value[15]|value[14]|value[13]|value[12]|value[11]|value[10]|value[9]|value[8]|
|||value[7]|value[6]|value[5]|value[4]|value[3]|value[2]|value[1]|value[0]|
||PTM_A9_<br>ETMCNTENR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|PTM_A9_<br>ETMCNTENR2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMCNTRLDEVR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMCNTRLDEVR2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMCNTVR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||value[15]|value[14]|value[13]|value[12]|value[11]|value[10]|value[9]|value[8]|
|||value[7]|value[6]|value[5]|value[4]|value[3]|value[2]|value[1]|value[0]|
||PTM_A9_<br>ETMCNTVR2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||value[15]|value[14]|value[13]|value[12]|value[11]|value[10]|value[9]|value[8]|
|||value[7]|value[6]|value[5]|value[4]|value[3]|value[2]|value[1]|value[0]|
||PTM_A9_<br>ETMSQ12EVR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMSQ21EVR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMSQ23EVR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMSQ31EVR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMSQ32EVR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMSQ13EVR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_ETMSQR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|state[1]|state[0]|
||PTM_A9_<br>ETMEXTOUTEVR1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMEXTOUTEVR2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMCIDCVR1|value[31]|value[30]|value[29]|value[28]|value[27]|value[26]|value[25]|value[24]|
|||value[23]|value[22]|value[21]|value[20]|value[19]|value[18]|value[17]|value[16]|
|||value[15]|value[14]|value[13]|value[12]|value[11]|value[10]|value[9]|value[8]|
|||value[7]|value[6]|value[5]|value[4]|value[3]|value[2]|value[1]|value[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|PTM_A9_<br>ETMCIDCMR|mask[31]|mask[30]|mask[29]|mask[28]|mask[27]|mask[26]|mask[25]|mask[24]|
|||mask[23]|mask[22]|mask[21]|mask[20]|mask[19]|mask[18]|mask[17]|mask[16]|
|||mask[15]|mask[14]|mask[13]|mask[12]|mask[11]|mask[10]|mask[9]|mask[8]|
|||mask[7]|mask[6]|mask[5]|mask[4]|mask[3]|mask[2]|mask[1]|mask[0]|
||PTM_A9_<br>ETMSYNCFR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|frequency[11]|frequency[10]|frequency[9]|frequency[8]|
|||frequency[7]|frequency[6]|frequency[5]|frequency[4]|frequency[3]|frequency[2]|frequency[1]|frequency[0]|
||PTM_A9_ETMIDR|code[7]|code[6]|code[5]|code[4]|code[3]|code[2]|code[1]|code[0]|
|||-|-|-|-|Security|32-bitThumb|-|-|
|||-|-|-|-|Major[7]|Major[6]|Major[5]|Major[4]|
|||Minor[3]|Minor[2]|Minor[1]|Minor[0]|revision[3]|revision[2]|revision[1]|revision[0]|
||PTM_A9_ETMCCER|-|-|-|-|-|-|Timestamps for<br>DMB/DSB|DMB/DSB treated<br>as waypoint|
|||Return stack<br>implemented|Timestamping<br>implemented|-|-|-|-|-|-|
|||Number of<br>instrumentation<br>resources[2]|Number of<br>instrumentation<br>resources[1]|Number of<br>instrumentation<br>resources[0]|-|-|Extended external<br>input bus size[7]|Extended external<br>input bus size[6]|Extended external<br>input bus size[5]|
|||Extended external<br>input bus size[4]|Extended external<br>input bus size[3]|Extended external<br>input bus size[2]|Extended external<br>input bus size[1]|Extended external<br>input bus size[0]|Number of extended<br>external input<br>selectors[2]|Number of extended<br>external input<br>selectors[1]|Number of extended<br>external input<br>selectors[0]|
||PTM_A9_<br>ETMEXTINSELR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|Second extended<br>external input<br>selector[5]|Second extended<br>external input<br>selector[4]|Second extended<br>external input<br>selector[3]|Second extended<br>external input<br>selector[2]|Second extended<br>external input<br>selector[1]|Second extended<br>external input<br>selector[0]|
|||-|-|First extended<br>external input<br>selector[5]|First extended<br>external input<br>selector[4]|First extended<br>external input<br>selector[3]|First extended<br>external input<br>selector[2]|First extended<br>external input<br>selector[1]|First extended<br>external input<br>selector[0]|
||PTM_A9_<br>ETMTSEVR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|event[16]|
|||event[15]|event[14]|event[13]|event[12]|event[11]|event[10]|event[9]|event[8]|
|||event[7]|event[6]|event[5]|event[4]|event[3]|event[2]|event[1]|event[0]|
||PTM_A9_<br>ETMAUXCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Force<br>synchronization<br>packet insertion|Disable<br>waypoint update<br>packet|Disable timestamps<br>on barriers|Disable<br>forced<br>overflow|
||PTM_A9_<br>ETMTRACEIDR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ID[7]|ID[6]|ID[5]|ID[4]|ID[3]|ID[2]|ID[1]|ID[0]|
||PTM_A9_OSLSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|Lock access<br>mechanism<br>indicator|32-bit<br>access required|PTM trace<br>registers locked/<br>unlocked|Lock access<br>mechanism<br>indicator|
||PTM_A9_CLAIMSET|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CLAIMSET[7]|CLAIMSET[6]|CLAIMSET[5]|CLAIMSET[4]|CLAIMSET[3]|CLAIMSET[2]|CLAIMSET[1]|CLAIMSET[0]|
||PTM_A9_CLAIMCLR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CLAIMCLR[7]|CLAIMCLR[6]|CLAIMCLR[5]|CLAIMCLR[4]|CLAIMCLR[3]|CLAIMCLR[2]|CLAIMCLR[1]|CLAIMCLR[0]|
||PTM_A9_LAR|ACCESS_W[31]|ACCESS_W[30]|ACCESS_W[29]|ACCESS_W[28]|ACCESS_W[27]|ACCESS_W[26]|ACCESS_W[25]|ACCESS_W[24]|
|||ACCESS_W[23]|ACCESS_W[22]|ACCESS_W[21]|ACCESS_W[20]|ACCESS_W[19]|ACCESS_W[18]|ACCESS_W[17]|ACCESS_W[16]|
|||ACCESS_W[15]|ACCESS_W[14]|ACCESS_W[13]|ACCESS_W[12]|ACCESS_W[11]|ACCESS_W[10]|ACCESS_W[9]|ACCESS_W[8]|
|||ACCESS_W[7]|ACCESS_W[6]|ACCESS_W[5]|ACCESS_W[4]|ACCESS_W[3]|ACCESS_W[2]|ACCESS_W[1]|ACCESS_W[0]|
||PTM_A9_LSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|LOCKTYPE|LOCKGRANT|LOCKEXIST|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|Debugger<br>interface|PTM_A9_<br>AUTHSTATUS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||SNID[1]|SNID[0]|SID[1]|SID[0]|NSNID[1]|NSNID[0]|NSID[1]|NSID[0]|
||PTM_A9_DEVTYPE|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Sub_type[3]|Sub_type[2]|Sub_type[1]|Sub_type[0]|Main_type[3]|Main_type[2]|Main_type[1]|Main_type[0]|
||PTM_A9_<br>PERIPHID4|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||4KB_count[3]|4KB_count[2]|4KB_count[1]|4KB_count[0]|JEP106_code[3]|JEP106_code[2]|JEP106_code[1]|JEP106_code[0]|
||PTM_A9_<br>PERIPHID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Part_Number[7]|Part_Number[6]|Part_Number[5]|Part_Number[4]|Part_Number[3]|Part_Number[2]|Part_Number[1]|Part_Number[0]|
||PTM_A9_<br>PERIPHID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JEP106_id[3]|JEP106_id[2]|JEP106_id[1]|JEP106_id[0]|Part_Number[11]|Part_Number[10]|Part_Number[9]|Part_Number[8]|
||PTM_A9_<br>PERIPHID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Revision[3]|Revision[2]|Revision[1]|Revision[0]|JEDEC|JEP106_id[6]|JEP106_id[5]|JEP106_id[4]|
||PTM_A9_<br>PERIPHID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||RevAnd[3]|RevAnd[2]|RevAnd[1]|RevAnd[0]|CUSTOM[3]|CUSTOM[2]|CUSTOM[1]|CUSTOM[0]|
||PTM_A9_COMPID0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||PTM_A9_COMPID1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Class[3]|Class[2]|Class[1]|Class[0]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||PTM_A9_COMPID2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
||PTM_A9_COMPID3|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||Preamble[7]|Preamble[6]|Preamble[5]|Preamble[4]|Preamble[3]|Preamble[2]|Preamble[1]|Preamble[0]|
|JPEG codec<br>unit*2|JCMOD|-|-|-|-|DSP|REDU[2]|REDU[1]|REDU[0]|
||JCCMD|BRST|-|-|-|-|JEND|JRST|JSRT|
||JCQTN|-|-|QT3[1]|QT3[0]|QT2[1]|QT2[0]|QT1[1]|QT1[0]|
||JCHTN|-|-|HTA3|HTD3|HTA2|HTD2|HTA1|HTD1|
||JCDRIU|DRIU[7]|DRIU[6]|DRIU[5]|DRIU[4]|DRIU[3]|DRIU[2]|DRIU[1]|DRIU[0]|
||JCDRID|DRID[7]|DRID[6]|DRID[5]|DRID[4]|DRID[3]|DRID[2]|DRID[1]|DRID[0]|
||JCVSZU|VSZU[7]|VSZU[6]|VSZU[5]|VSZU[4]|VSZU[3]|VSZU[2]|VSZU[1]|VSZU[0]|
||JCVSZD|VSZD[7]|VSZD[6]|VSZD[5]|VSZD[4]|VSZD[3]|VSZD[2]|VSZD[1]|VSZD[0]|
||JCHSZU|HSZU[7]|HSZU[6]|HSZU[5]|HSZU[4]|HSZU[3]|HSZU[2]|HSZU[1]|HSZU[0]|
||JCHSZD|HSZD[7]|HSZD[6]|HSZD[5]|HSZD[4]|HSZD[3]|HSZD[2]|HSZD[1]|HSZD[0]|
||JCDTCU|DCU[7]|DCU[6]|DCU[5]|DCU[4]|DCU[3]|DCU[2]|DCU[1]|DCU[0]|
||JCDTCM|DCM[7]|DCM[6]|DCM[5]|DCM[4]|DCM[3]|DCM[2]|DCM[1]|DCM[0]|
||JCDTCD|DCD[7]|DCD[6]|DCD[5]|DCD[4]|DCD[3]|DCD[2]|DCD[1]|DCD[0]|
||JINTE0|INT7|INT6|INT5|-|INT3|-|-|-|
||JINTS0|-|INS6|INS5|-|INS3|-|-|-|
||JCDERR|-|-|-|-|ERR[3]|ERR[2]|ERR[1]|ERR[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|JPEG codec<br>unit*2|JCRST|-|-|-|-|-|-|-|RST|
||JIFECNT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|JOUTRINI|JOUTRCMD|JOUTC|-|JOUTSWAP[2]|JOUTSWAP[1]|JOUTSWAP[0]|
|||-|DINRINI|DINRCMD|DINLC|-|DINSWAP[2]|DINSWAP[1]|DINSWAP[0]|
||JIFESA|ESA[31]|ESA[30]|ESA[29]|ESA[28]|ESA[27]|ESA[26]|ESA[25]|ESA[24]|
|||ESA[23]|ESA[22]|ESA[21]|ESA[20]|ESA[19]|ESA[18]|ESA[17]|ESA[16]|
|||ESA[15]|ESA[14]|ESA[13]|ESA[12]|ESA[11]|ESA[10]|ESA[9]|ESA[8]|
|||ESA[7]|ESA[6]|ESA[5]|ESA[4]|ESA[3]|ESA[2]|ESA[1]|ESA[0]|
||JIFESOFST|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|ESMW[14]|ESMW[13]|ESMW[12]|ESMW[11]|ESMW[10]|ESMW[9]|ESMW[8]|
|||ESMW[7]|ESMW[6]|ESMW[5]|ESMW[4]|ESMW[3]|ESMW[2]|ESMW[1]|ESMW[0]|
||JIFEDA|EDA[31]|EDA[30]|EDA[29]|EDA[28]|EDA[27]|EDA[26]|EDA[25]|EDA[24]|
|||EDA[23]|EDA[22]|EDA[21]|EDA[20]|EDA[19]|EDA[18]|EDA[17]|EDA[16]|
|||EDA[15]|EDA[14]|EDA[13]|EDA[12]|EDA[11]|EDA[10]|EDA[9]|EDA[8]|
|||EDA[7]|EDA[6]|EDA[5]|EDA[4]|EDA[3]|EDA[2]|EDA[1]|EDA[0]|
||JIFESLC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LINES[15]|LINES[14]|LINES[13]|LINES[12]|LINES[11]|LINES[10]|LINES[9]|LINES[8]|
|||LINES[7]|LINES[6]|LINES[5]|LINES[4]|LINES[3]|LINES[2]|LINES[1]|LINES[0]|
||JIFEDDC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JDATAS[15]|JDATAS[14]|JDATAS[13]|JDATAS[12]|JDATAS[11]|JDATAS[10]|JDATAS[9]|JDATAS[8]|
|||JDATAS[7]|JDATAS[6]|JDATAS[5]|JDATAS[4]|JDATAS[3]|JDATAS[2]|JDATAS[1]|JDATAS[0]|
||JIFDCNT|-|-|VINTER[1]|VINTER[0]|HINTER[1]|HINTER[0]|OPF[1]|OPF[0]|
|||-|-|-|-|-|-|-|-|
|||-|JINRINI|JINRCMD|JINC|-|JINSWAP[2]|JINSWAP[1]|JINSWAP[0]|
|||-|DOUTRINI|DOUTRCMD|DOUTLC|-|DOUTSWAP[2]|DOUTSWAP[1]|DOUTSWAP[0]|
||JIFDSA|DSA[31]|DSA[30]|DSA[29]|DSA[28]|DSA[27]|DSA[26]|DSA[25]|DSA[24]|
|||DSA[23]|DSA[22]|DSA[21]|DSA[20]|DSA[19]|DSA[18]|DSA[17]|DSA[16]|
|||DSA[15]|DSA[14]|DSA[13]|DSA[12]|DSA[11]|DSA[10]|DSA[9]|DSA[8]|
|||DSA[7]|DSA[6]|DSA[5]|DSA[4]|DSA[3]|DSA[2]|DSA[1]|DSA[0]|
||JIFDDOFST|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|DDMW[14]|DDMW[13]|DDMW[12]|DDMW[11]|DDMW[10]|DDMW[9]|DDMW[8]|
|||DDMW[7]|DDMW[6]|DDMW[5]|DDMW[4]|DDMW[3]|DDMW[2]|DDMW[1]|DDMW[0]|
||JIFDDA|DDA[31]|DDA[30]|DDA[29]|DDA[28]|DDA[27]|DDA[26]|DDA[25]|DDA[24]|
|||DDA[23]|DDA[22]|DDA[21]|DDA[20]|DDA[19]|DDA[18]|DDA[17]|DDA[16]|
|||DDA[15]|DDA[14]|DDA[13]|DDA[12]|DDA[11]|DDA[10]|DDA[9]|DDA[8]|
|||DDA[7]|DDA[6]|DDA[5]|DDA[4]|DDA[3]|DDA[2]|DDA[1]|DDA[0]|
||JIFDSDC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||JDATAS[15]|JDATAS[14]|JDATAS[13]|JDATAS[12]|JDATAS[11]|JDATAS[10]|JDATAS[9]|JDATAS[8]|
|||JDATAS[7]|JDATAS[6]|JDATAS[5]|JDATAS[4]|JDATAS[3]|JDATAS[2]|JDATAS[1]|JDATAS[0]|
||JIFDDLC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||LINES[15]|LINES[14]|LINES[13]|LINES[12]|LINES[11]|LINES[10]|LINES[9]|LINES[8]|
|||LINES[7]|LINES[6]|LINES[5]|LINES[4]|LINES[3]|LINES[2]|LINES[1]|LINES[0]|
||JIFDADT|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||ALPHA[7]|ALPHA[6]|ALPHA[5]|ALPHA[4]|ALPHA[3]|ALPHA[2]|ALPHA[1]|ALPHA[0]|
||JINTE1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|CBTEN|DINLEN|JOUTEN|-|DBTEN|JINEN|DOUTLEN|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|JPEG codec<br>unit*2|JINTS1|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|CBTF|DINLF|JOUTF|-|DBTF|JINF|DOUTLF|
||JIFESVSZ|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DINYCHG|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||JIFESHSZ|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DOUTYCHG|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|EthernetAVB*2|CCC|-|-|-|-|-|-|FCE|LBME|
|||-|-|-|BOC|-|-|CSEL[1]|CSEL[0]|
|||-|-|-|-|-|-|-|DTSR|
|||-|-|-|-|-|-|OPC[1]|OPC[0]|
||DBAT|TA[31]|TA[30]|TA[29]|TA[28]|TA[27]|TA[26]|TA[25]|TA[24]|
|||TA[23]|TA[22]|TA[21]|TA[20]|TA[19]|TA[18]|TA[17]|TA[16]|
|||TA[15]|TA[14]|TA[13]|TA[12]|TA[11]|TA[10]|TA[9]|TA[8]|
|||TA[7]|TA[6]|TA[5]|TA[4]|TA[3]|TA[2]|TA[1]|TA[0]|
||DLR|-|-|-|-|-|-|-|-|
|||-|-|LBA21|LBA20|LBA19|LBA18|LBA17|LBA16|
|||LBA15|LBA14|LBA13|LBA12|LBA11|LBA10|LBA9|LBA8|
|||LBA7|LBA6|LBA5|LBA4|LBA3|LBA2|LBA1|LBA0|
||CSR|-|-|-|-|-|-|-|-|
|||-|-|-|RPO|TPO3|TPO2|TPO1|TPO0|
|||-|-|-|-|-|-|-|DTS|
|||-|-|-|-|OPS[3]|OPS[2]|OPS[1]|OPS[0]|
||CDAR0|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR1|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR2|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR3|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR4|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR5|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR6|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR7|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|CDAR8|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR9|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR10|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR11|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR12|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR13|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR14|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR15|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR16|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR17|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR18|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR19|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR20|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||CDAR21|CDA[31]|CDA[30]|CDA[29]|CDA[28]|CDA[27]|CDA[26]|CDA[25]|CDA[24]|
|||CDA[23]|CDA[22]|CDA[21]|CDA[20]|CDA[19]|CDA[18]|CDA[17]|CDA[16]|
|||CDA[15]|CDA[14]|CDA[13]|CDA[12]|CDA[11]|CDA[10]|CDA[9]|CDA[8]|
|||CDA[7]|CDA[6]|CDA[5]|CDA[4]|CDA[3]|CDA[2]|CDA[1]|CDA[0]|
||ESR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|EIL|ET[3]|ET[2]|ET[1]|ET[0]|
|||-|-|-|EQN[4]|EQN[3]|EQN[2]|EQN[1]|EQN[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|RCR|-|-|-|RFCL[12]|RFCL[11]|RFCL[10]|RFCL[9]|RFCL[8]|
|||RFCL[7]|RFCL[6]|RFCL[5]|RFCL[4]|RFCL[3]|RFCL[2]|RFCL[1]|RFCL[0]|
|||-|-|-|-|-|-|-|-|
|||-|-|ETS2|ETS0|ESF[1]|ESF[0]|ENCF|EFFS|
||RQC0|-|-|UFCC3[1]|UFCC3[0]|-|-|RSM3[1]|RSM3[0]|
|||-|-|UFCC2[1]|UFCC2[0]|-|-|RSM2[1]|RSM2[0]|
|||-|-|UFCC1[1]|UFCC1[0]|-|-|RSM1[1]|RSM1[0]|
|||-|-|UFCC0[1]|UFCC0[0]|-|-|RSM0[1]|RSM0[0]|
||RQC1|-|-|UFCC3[1]|UFCC3[0]|-|-|RSM3[1]|RSM3[0]|
|||-|-|UFCC2[1]|UFCC2[0]|-|-|RSM2[1]|RSM2[0]|
|||-|-|UFCC1[1]|UFCC1[0]|-|-|RSM1[1]|RSM1[0]|
|||-|-|UFCC0[1]|UFCC0[0]|-|-|RSM0[1]|RSM0[0]|
||RQC2|-|-|UFCC3[1]|UFCC3[0]|-|-|RSM3[1]|RSM3[0]|
|||-|-|UFCC2[1]|UFCC2[0]|-|-|RSM2[1]|RSM2[0]|
|||-|-|UFCC1[1]|UFCC1[0]|-|-|RSM1[1]|RSM1[0]|
|||-|-|UFCC0[1]|UFCC0[0]|-|-|RSM0[1]|RSM0[0]|
||RQC3|-|-|UFCC3[1]|UFCC3[0]|-|-|RSM3[1]|RSM3[0]|
|||-|-|UFCC2[1]|UFCC2[0]|-|-|RSM2[1]|RSM2[0]|
|||-|-|UFCC1[1]|UFCC1[0]|-|-|RSM1[1]|RSM1[0]|
|||-|-|UFCC0[1]|UFCC0[0]|-|-|RSM0[1]|RSM0[0]|
||RQC4|-|-|UFCC3[1]|UFCC3[0]|-|-|RSM3[1]|RSM3[0]|
|||-|-|UFCC2[1]|UFCC2[0]|-|-|RSM2[1]|RSM2[0]|
|||-|-|UFCC1[1]|UFCC1[0]|-|-|RSM1[1]|RSM1[0]|
|||-|-|UFCC0[1]|UFCC0[0]|-|-|RSM0[1]|RSM0[0]|
||RPC|-|-|-|-|-|-|-|-|
|||DCNT[7]|DCNT[6]|DCNT[5]|DCNT[4]|DCNT[3]|DCNT[2]|DCNT[1]|DCNT[0]|
|||-|-|-|-|-|PCNT[2]|PCNT[1]|PCNT[0]|
|||-|-|-|-|-|-|-|-|
||UFCS|-|-|SL3[5]|SL3[4]|SL3[3]|SL3[2]|SL3[1]|SL3[0]|
|||-|-|SL2[5]|SL2[4]|SL2[3]|SL2[2]|SL2[1]|SL2[0]|
|||-|-|SL1[5]|SL1[4]|SL1[3]|SL1[2]|SL1[1]|SL1[0]|
|||-|-|SL0[5]|SL0[4]|SL0[3]|SL0[2]|SL0[1]|SL0[0]|
||UFCV0|-|-|CV3[5]|CV3[4]|CV3[3]|CV3[2]|CV3[1]|CV3[0]|
|||-|-|CV2[5]|CV2[4]|CV2[3]|CV2[2]|CV2[1]|CV2[0]|
|||-|-|CV1[5]|CV1[4]|CV1[3]|CV1[2]|CV1[1]|CV1[0]|
|||-|-|CV0[5]|CV0[4]|CV0[3]|CV0[2]|CV0[1]|CV0[0]|
||UFCV1|-|-|CV3[5]|CV3[4]|CV3[3]|CV3[2]|CV3[1]|CV3[0]|
|||-|-|CV2[5]|CV2[4]|CV2[3]|CV2[2]|CV2[1]|CV2[0]|
|||-|-|CV1[5]|CV1[4]|CV1[3]|CV1[2]|CV1[1]|CV1[0]|
|||-|-|CV0[5]|CV0[4]|CV0[3]|CV0[2]|CV0[1]|CV0[0]|
||UFCV2|-|-|CV3[5]|CV3[4]|CV3[3]|CV3[2]|CV3[1]|CV3[0]|
|||-|-|CV2[5]|CV2[4]|CV2[3]|CV2[2]|CV2[1]|CV2[0]|
|||-|-|CV1[5]|CV1[4]|CV1[3]|CV1[2]|CV1[1]|CV1[0]|
|||-|-|CV0[5]|CV0[4]|CV0[3]|CV0[2]|CV0[1]|CV0[0]|
||UFCV3|-|-|CV3[5]|CV3[4]|CV3[3]|CV3[2]|CV3[1]|CV3[0]|
|||-|-|CV2[5]|CV2[4]|CV2[3]|CV2[2]|CV2[1]|CV2[0]|
|||-|-|CV1[5]|CV1[4]|CV1[3]|CV1[2]|CV1[1]|CV1[0]|
|||-|-|CV0[5]|CV0[4]|CV0[3]|CV0[2]|CV0[1]|CV0[0]|
||UFCV4|-|-|CV3[5]|CV3[4]|CV3[3]|CV3[2]|CV3[1]|CV3[0]|
|||-|-|CV2[5]|CV2[4]|CV2[3]|CV2[2]|CV2[1]|CV2[0]|
|||-|-|CV1[5]|CV1[4]|CV1[3]|CV1[2]|CV1[1]|CV1[0]|
|||-|-|CV0[5]|CV0[4]|CV0[3]|CV0[2]|CV0[1]|CV0[0]|
||UFCD0|-|-|DV3[5]|DV3[4]|DV3[3]|DV3[2]|DV3[1]|DV3[0]|
|||-|-|DV2[5]|DV2[4]|DV2[3]|DV2[2]|DV2[1]|DV2[0]|
|||-|-|DV1[5]|DV1[4]|DV1[3]|DV1[2]|DV1[1]|DV1[0]|
|||-|-|DV0[5]|DV0[4]|DV0[3]|DV0[2]|DV0[1]|DV0[0]|
||UFCD1|-|-|DV3[5]|DV3[4]|DV3[3]|DV3[2]|DV3[1]|DV3[0]|
|||-|-|DV2[5]|DV2[4]|DV2[3]|DV2[2]|DV2[1]|DV2[0]|
|||-|-|DV1[5]|DV1[4]|DV1[3]|DV1[2]|DV1[1]|DV1[0]|
|||-|-|DV0[5]|DV0[4]|DV0[3]|DV0[2]|DV0[1]|DV0[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|UFCD2|-|-|DV3[5]|DV3[4]|DV3[3]|DV3[2]|DV3[1]|DV3[0]|
|||-|-|DV2[5]|DV2[4]|DV2[3]|DV2[2]|DV2[1]|DV2[0]|
|||-|-|DV1[5]|DV1[4]|DV1[3]|DV1[2]|DV1[1]|DV1[0]|
|||-|-|DV0[5]|DV0[4]|DV0[3]|DV0[2]|DV0[1]|DV0[0]|
||UFCD3|-|-|DV3[5]|DV3[4]|DV3[3]|DV3[2]|DV3[1]|DV3[0]|
|||-|-|DV2[5]|DV2[4]|DV2[3]|DV2[2]|DV2[1]|DV2[0]|
|||-|-|DV1[5]|DV1[4]|DV1[3]|DV1[2]|DV1[1]|DV1[0]|
|||-|-|DV0[5]|DV0[4]|DV0[3]|DV0[2]|DV0[1]|DV0[0]|
||UFCD4|-|-|DV3[5]|DV3[4]|DV3[3]|DV3[2]|DV3[1]|DV3[0]|
|||-|-|DV2[5]|DV2[4]|DV2[3]|DV2[2]|DV2[1]|DV2[0]|
|||-|-|DV1[5]|DV1[4]|DV1[3]|DV1[2]|DV1[1]|DV1[0]|
|||-|-|DV0[5]|DV0[4]|DV0[3]|DV0[2]|DV0[1]|DV0[0]|
||SFO|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|FBP[5]|FBP[4]|FBP[3]|FBP[2]|FBP[1]|FBP[0]|
||SFP0|FP0[31]|FP0[30]|FP0[29]|FP0[28]|FP0[27]|FP0[26]|FP0[25]|FP0[24]|
|||FP0[23]|FP0[22]|FP0[21]|FP0[20]|FP0[19]|FP0[18]|FP0[17]|FP0[16]|
|||FP0[15]|FP0[14]|FP0[13]|FP0[12]|FP0[11]|FP0[10]|FP0[9]|FP0[8]|
|||FP0[7]|FP0[6]|FP0[5]|FP0[4]|FP0[3]|FP0[2]|FP0[1]|FP0[0]|
||SFP1|FP0[63]|FP0[62]|FP0[61]|FP0[60]|FP0[59]|FP0[58]|FP0[57]|FP0[56]|
|||FP0[55]|FP0[54]|FP0[53]|FP0[52]|FP0[51]|FP0[50]|FP0[49]|FP0[48]|
|||FP0[47]|FP0[46]|FP0[45]|FP0[44]|FP0[43]|FP0[42]|FP0[41]|FP0[40]|
|||FP0[39]|FP0[38]|FP0[37]|FP0[36]|FP0[35]|FP0[34]|FP0[33]|FP0[32]|
||SFP2|FP1[31]|FP1[30]|FP1[29]|FP1[28]|FP1[27]|FP1[26]|FP1[25]|FP1[24]|
|||FP1[23]|FP1[22]|FP1[21]|FP1[20]|FP1[19]|FP1[18]|FP1[17]|FP1[16]|
|||FP1[15]|FP1[14]|FP1[13]|FP1[12]|FP1[11]|FP1[10]|FP1[9]|FP1[8]|
|||FP1[7]|FP1[6]|FP1[5]|FP1[4]|FP1[3]|FP1[2]|FP1[1]|FP1[0]|
||SFP3|FP1[63]|FP1[62]|FP1[61]|FP1[60]|FP1[59]|FP1[58]|FP1[57]|FP1[56]|
|||FP1[55]|FP1[54]|FP1[53]|FP1[52]|FP1[51]|FP1[50]|FP1[49]|FP1[48]|
|||FP1[47]|FP1[46]|FP1[45]|FP1[44]|FP1[43]|FP1[42]|FP1[41]|FP1[40]|
|||FP1[39]|FP1[38]|FP1[37]|FP1[36]|FP1[35]|FP1[34]|FP1[33]|FP1[32]|
||SFP4|FP2[31]|FP2[30]|FP2[29]|FP2[28]|FP2[27]|FP2[26]|FP2[25]|FP2[24]|
|||FP2[23]|FP2[22]|FP2[21]|FP2[20]|FP2[19]|FP2[18]|FP2[17]|FP2[16]|
|||FP2[15]|FP2[14]|FP2[13]|FP2[12]|FP2[11]|FP2[10]|FP2[9]|FP2[8]|
|||FP2[7]|FP2[6]|FP2[5]|FP2[4]|FP2[3]|FP2[2]|FP2[1]|FP2[0]|
||SFP5|FP2[63]|FP2[62]|FP2[61]|FP2[60]|FP2[59]|FP2[58]|FP2[57]|FP2[56]|
|||FP2[55]|FP2[54]|FP2[53]|FP2[52]|FP2[51]|FP2[50]|FP2[49]|FP2[48]|
|||FP2[47]|FP2[46]|FP2[45]|FP2[44]|FP2[43]|FP2[42]|FP2[41]|FP2[40]|
|||FP2[39]|FP2[38]|FP2[37]|FP2[36]|FP2[35]|FP2[34]|FP2[33]|FP2[32]|
||SFP6|FP3[31]|FP3[30]|FP3[29]|FP3[28]|FP3[27]|FP3[26]|FP3[25]|FP3[24]|
|||FP3[23]|FP3[22]|FP3[21]|FP3[20]|FP3[19]|FP3[18]|FP3[17]|FP3[16]|
|||FP3[15]|FP3[14]|FP3[13]|FP3[12]|FP3[11]|FP3[10]|FP3[9]|FP3[8]|
|||FP3[7]|FP3[6]|FP3[5]|FP3[4]|FP3[3]|FP3[2]|FP3[1]|FP3[0]|
||SFP7|FP3[63]|FP3[62]|FP3[61]|FP3[60]|FP3[59]|FP3[58]|FP3[57]|FP3[56]|
|||FP3[55]|FP3[54]|FP3[53]|FP3[52]|FP3[51]|FP3[50]|FP3[49]|FP3[48]|
|||FP3[47]|FP3[46]|FP3[45]|FP3[44]|FP3[43]|FP3[42]|FP3[41]|FP3[40]|
|||FP3[39]|FP3[38]|FP3[37]|FP3[36]|FP3[35]|FP3[34]|FP3[33]|FP3[32]|
||SFP8|FP4[31]|FP4[30]|FP4[29]|FP4[28]|FP4[27]|FP4[26]|FP4[25]|FP4[24]|
|||FP4[23]|FP4[22]|FP4[21]|FP4[20]|FP4[19]|FP4[18]|FP4[17]|FP4[16]|
|||FP4[15]|FP4[14]|FP4[13]|FP4[12]|FP4[11]|FP4[10]|FP4[9]|FP4[8]|
|||FP4[7]|FP4[6]|FP4[5]|FP4[4]|FP4[3]|FP4[2]|FP4[1]|FP4[0]|
||SFP9|FP4[63]|FP4[62]|FP4[61]|FP4[60]|FP4[59]|FP4[58]|FP4[57]|FP4[56]|
|||FP4[55]|FP4[54]|FP4[53]|FP4[52]|FP4[51]|FP4[50]|FP4[49]|FP4[48]|
|||FP4[47]|FP4[46]|FP4[45]|FP4[44]|FP4[43]|FP4[42]|FP4[41]|FP4[40]|
|||FP4[39]|FP4[38]|FP4[37]|FP4[36]|FP4[35]|FP4[34]|FP4[33]|FP4[32]|
||SFP10|FP5[31]|FP5[30]|FP5[29]|FP5[28]|FP5[27]|FP5[26]|FP5[25]|FP5[24]|
|||FP5[23]|FP5[22]|FP5[21]|FP5[20]|FP5[19]|FP5[18]|FP5[17]|FP5[16]|
|||FP5[15]|FP5[14]|FP5[13]|FP5[12]|FP5[11]|FP5[10]|FP5[9]|FP5[8]|
|||FP5[7]|FP5[6]|FP5[5]|FP5[4]|FP5[3]|FP5[2]|FP5[1]|FP5[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|SFP11|FP5[63]|FP5[62]|FP5[61]|FP5[60]|FP5[59]|FP5[58]|FP5[57]|FP5[56]|
|||FP5[55]|FP5[54]|FP5[53]|FP5[52]|FP5[51]|FP5[50]|FP5[49]|FP5[48]|
|||FP5[47]|FP5[46]|FP5[45]|FP5[44]|FP5[43]|FP5[42]|FP5[41]|FP5[40]|
|||FP5[39]|FP5[38]|FP5[37]|FP5[36]|FP5[35]|FP5[34]|FP5[33]|FP5[32]|
||SFP12|FP6[31]|FP6[30]|FP6[29]|FP6[28]|FP6[27]|FP6[26]|FP6[25]|FP6[24]|
|||FP6[23]|FP6[22]|FP6[21]|FP6[20]|FP6[19]|FP6[18]|FP6[17]|FP6[16]|
|||FP6[15]|FP6[14]|FP6[13]|FP6[12]|FP6[11]|FP6[10]|FP6[9]|FP6[8]|
|||FP6[7]|FP6[6]|FP6[5]|FP6[4]|FP6[3]|FP6[2]|FP6[1]|FP6[0]|
||SFP13|FP6[63]|FP6[62]|FP6[61]|FP6[60]|FP6[59]|FP6[58]|FP6[57]|FP6[56]|
|||FP6[55]|FP6[54]|FP6[53]|FP6[52]|FP6[51]|FP6[50]|FP6[49]|FP6[48]|
|||FP6[47]|FP6[46]|FP6[45]|FP6[44]|FP6[43]|FP6[42]|FP6[41]|FP6[40]|
|||FP6[39]|FP6[38]|FP6[37]|FP6[36]|FP6[35]|FP6[34]|FP6[33]|FP6[32]|
||SFP14|FP7[31]|FP7[30]|FP7[29]|FP7[28]|FP7[27]|FP7[26]|FP7[25]|FP7[24]|
|||FP7[23]|FP7[22]|FP7[21]|FP7[20]|FP7[19]|FP7[18]|FP7[17]|FP7[16]|
|||FP7[15]|FP7[14]|FP7[13]|FP7[12]|FP7[11]|FP7[10]|FP7[9]|FP7[8]|
|||FP7[7]|FP7[6]|FP7[5]|FP7[4]|FP7[3]|FP7[2]|FP7[1]|FP7[0]|
||SFP15|FP7[63]|FP7[62]|FP7[61]|FP7[60]|FP7[59]|FP7[58]|FP7[57]|FP7[56]|
|||FP7[55]|FP7[54]|FP7[53]|FP7[52]|FP7[51]|FP7[50]|FP7[49]|FP7[48]|
|||FP7[47]|FP7[46]|FP7[45]|FP7[44]|FP7[43]|FP7[42]|FP7[41]|FP7[40]|
|||FP7[39]|FP7[38]|FP7[37]|FP7[36]|FP7[35]|FP7[34]|FP7[33]|FP7[32]|
||SFP16|FP8[31]|FP8[30]|FP8[29]|FP8[28]|FP8[27]|FP8[26]|FP8[25]|FP8[24]|
|||FP8[23]|FP8[22]|FP8[21]|FP8[20]|FP8[19]|FP8[18]|FP8[17]|FP8[16]|
|||FP8[15]|FP8[14]|FP8[13]|FP8[12]|FP8[11]|FP8[10]|FP8[9]|FP8[8]|
|||FP8[7]|FP8[6]|FP8[5]|FP8[4]|FP8[3]|FP8[2]|FP8[1]|FP8[0]|
||SFP17|FP8[63]|FP8[62]|FP8[61]|FP8[60]|FP8[59]|FP8[58]|FP8[57]|FP8[56]|
|||FP8[55]|FP8[54]|FP8[53]|FP8[52]|FP8[51]|FP8[50]|FP8[49]|FP8[48]|
|||FP8[47]|FP8[46]|FP8[45]|FP8[44]|FP8[43]|FP8[42]|FP8[41]|FP8[40]|
|||FP8[39]|FP8[38]|FP8[37]|FP8[36]|FP8[35]|FP8[34]|FP8[33]|FP8[32]|
||SFP18|FP9[31]|FP9[30]|FP9[29]|FP9[28]|FP9[27]|FP9[26]|FP9[25]|FP9[24]|
|||FP9[23]|FP9[22]|FP9[21]|FP9[20]|FP9[19]|FP9[18]|FP9[17]|FP9[16]|
|||FP9[15]|FP9[14]|FP9[13]|FP9[12]|FP9[11]|FP9[10]|FP9[9]|FP9[8]|
|||FP9[7]|FP9[6]|FP9[5]|FP9[4]|FP9[3]|FP9[2]|FP9[1]|FP9[0]|
||SFP19|FP9[63]|FP9[62]|FP9[61]|FP9[60]|FP9[59]|FP9[58]|FP9[57]|FP9[56]|
|||FP9[55]|FP9[54]|FP9[53]|FP9[52]|FP9[51]|FP9[50]|FP9[49]|FP9[48]|
|||FP9[47]|FP9[46]|FP9[45]|FP9[44]|FP9[43]|FP9[42]|FP9[41]|FP9[40]|
|||FP9[39]|FP9[38]|FP9[37]|FP9[36]|FP9[35]|FP9[34]|FP9[33]|FP9[32]|
||SFP20|FP10[31]|FP10[30]|FP10[29]|FP10[28]|FP10[27]|FP10[26]|FP10[25]|FP10[24]|
|||FP10[23]|FP10[22]|FP10[21]|FP10[20]|FP10[19]|FP10[18]|FP10[17]|FP10[16]|
|||FP10[15]|FP10[14]|FP10[13]|FP10[12]|FP10[11]|FP10[10]|FP10[9]|FP10[8]|
|||FP10[7]|FP10[6]|FP10[5]|FP10[4]|FP10[3]|FP10[2]|FP10[1]|FP10[0]|
||SFP21|FP10[63]|FP10[62]|FP10[61]|FP10[60]|FP10[59]|FP10[58]|FP10[57]|FP10[56]|
|||FP10[55]|FP10[54]|FP10[53]|FP10[52]|FP10[51]|FP10[50]|FP10[49]|FP10[48]|
|||FP10[47]|FP10[46]|FP10[45]|FP10[44]|FP10[43]|FP10[42]|FP10[41]|FP10[40]|
|||FP10[39]|FP10[38]|FP10[37]|FP10[36]|FP10[35]|FP10[34]|FP10[33]|FP10[32]|
||SFP22|FP11[31]|FP11[30]|FP11[29]|FP11[28]|FP11[27]|FP11[26]|FP11[25]|FP11[24]|
|||FP11[23]|FP11[22]|FP11[21]|FP11[20]|FP11[19]|FP11[18]|FP11[17]|FP11[16]|
|||FP11[15]|FP11[14]|FP11[13]|FP11[12]|FP11[11]|FP11[10]|FP11[9]|FP11[8]|
|||FP11[7]|FP11[6]|FP11[5]|FP11[4]|FP11[3]|FP11[2]|FP11[1]|FP11[0]|
||SFP23|FP11[63]|FP11[62]|FP11[61]|FP11[60]|FP11[59]|FP11[58]|FP11[57]|FP11[56]|
|||FP11[55]|FP11[54]|FP11[53]|FP11[52]|FP11[51]|FP11[50]|FP11[49]|FP11[48]|
|||FP11[47]|FP11[46]|FP11[45]|FP11[44]|FP11[43]|FP11[42]|FP11[41]|FP11[40]|
|||FP11[39]|FP11[38]|FP11[37]|FP11[36]|FP11[35]|FP11[34]|FP11[33]|FP11[32]|
||SFP24|FP12[31]|FP12[30]|FP12[29]|FP12[28]|FP12[27]|FP12[26]|FP12[25]|FP12[24]|
|||FP12[23]|FP12[22]|FP12[21]|FP12[20]|FP12[19]|FP12[18]|FP12[17]|FP12[16]|
|||FP12[15]|FP12[14]|FP12[13]|FP12[12]|FP12[11]|FP12[10]|FP12[9]|FP12[8]|
|||FP12[7]|FP12[6]|FP12[5]|FP12[4]|FP12[3]|FP12[2]|FP12[1]|FP12[0]|
||SFP25|FP12[63]|FP12[62]|FP12[61]|FP12[60]|FP12[59]|FP12[58]|FP12[57]|FP12[56]|
|||FP12[55]|FP12[54]|FP12[53]|FP12[52]|FP12[51]|FP12[50]|FP12[49]|FP12[48]|
|||FP12[47]|FP12[46]|FP12[45]|FP12[44]|FP12[43]|FP12[42]|FP12[41]|FP12[40]|
|||FP12[39]|FP12[38]|FP12[37]|FP12[36]|FP12[35]|FP12[34]|FP12[33]|FP12[32]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|SFP26|FP13[31]|FP13[30]|FP13[29]|FP13[28]|FP13[27]|FP13[26]|FP13[25]|FP13[24]|
|||FP13[23]|FP13[22]|FP13[21]|FP13[20]|FP13[19]|FP13[18]|FP13[17]|FP13[16]|
|||FP13[15]|FP13[14]|FP13[13]|FP13[12]|FP13[11]|FP13[10]|FP13[9]|FP13[8]|
|||FP13[7]|FP13[6]|FP13[5]|FP13[4]|FP13[3]|FP13[2]|FP13[1]|FP13[0]|
||SFP27|FP13[63]|FP13[62]|FP13[61]|FP13[60]|FP13[59]|FP13[58]|FP13[57]|FP13[56]|
|||FP13[55]|FP13[54]|FP13[53]|FP13[52]|FP13[51]|FP13[50]|FP13[49]|FP13[48]|
|||FP13[47]|FP13[46]|FP13[45]|FP13[44]|FP13[43]|FP13[42]|FP13[41]|FP13[40]|
|||FP13[39]|FP13[38]|FP13[37]|FP13[36]|FP13[35]|FP13[34]|FP13[33]|FP13[32]|
||SFP28|FP14[31]|FP14[30]|FP14[29]|FP14[28]|FP14[27]|FP14[26]|FP14[25]|FP14[24]|
|||FP14[23]|FP14[22]|FP14[21]|FP14[20]|FP14[19]|FP14[18]|FP14[17]|FP14[16]|
|||FP14[15]|FP14[14]|FP14[13]|FP14[12]|FP14[11]|FP14[10]|FP14[9]|FP14[8]|
|||FP14[7]|FP14[6]|FP14[5]|FP14[4]|FP14[3]|FP14[2]|FP14[1]|FP14[0]|
||SFP29|FP14[63]|FP14[62]|FP14[61]|FP14[60]|FP14[59]|FP14[58]|FP14[57]|FP14[56]|
|||FP14[55]|FP14[54]|FP14[53]|FP14[52]|FP14[51]|FP14[50]|FP14[49]|FP14[48]|
|||FP14[47]|FP14[46]|FP14[45]|FP14[44]|FP14[43]|FP14[42]|FP14[41]|FP14[40]|
|||FP14[39]|FP14[38]|FP14[37]|FP14[36]|FP14[35]|FP14[34]|FP14[33]|FP14[32]|
||SFP30|FP15[31]|FP15[30]|FP15[29]|FP15[28]|FP15[27]|FP15[26]|FP15[25]|FP15[24]|
|||FP15[23]|FP15[22]|FP15[21]|FP15[20]|FP15[19]|FP15[18]|FP15[17]|FP15[16]|
|||FP15[15]|FP15[14]|FP15[13]|FP15[12]|FP15[11]|FP15[10]|FP15[9]|FP15[8]|
|||FP15[7]|FP15[6]|FP15[5]|FP15[4]|FP15[3]|FP15[2]|FP15[1]|FP15[0]|
||SFP31|FP15[63]|FP15[62]|FP15[61]|FP15[60]|FP15[59]|FP15[58]|FP15[57]|FP15[56]|
|||FP15[55]|FP15[54]|FP15[53]|FP15[52]|FP15[51]|FP15[50]|FP15[49]|FP15[48]|
|||FP15[47]|FP15[46]|FP15[45]|FP15[44]|FP15[43]|FP15[42]|FP15[41]|FP15[40]|
|||FP15[39]|FP15[38]|FP15[37]|FP15[36]|FP15[35]|FP15[34]|FP15[33]|FP15[32]|
||SFM0|CFM[31]|CFM[30]|CFM[29]|CFM[28]|CFM[27]|CFM[26]|CFM[25]|CFM[24]|
|||CFM[23]|CFM[22]|CFM[21]|CFM[20]|CFM[19]|CFM[18]|CFM[17]|CFM[16]|
|||CFM[15]|CFM[14]|CFM[13]|CFM[12]|CFM[11]|CFM[10]|CFM[9]|CFM[8]|
|||CFM[7]|CFM[6]|CFM[5]|CFM[4]|CFM[3]|CFM[2]|CFM[1]|CFM[0]|
||SFM1|CFM[31]|CFM[30]|CFM[29]|CFM[28]|CFM[27]|CFM[26]|CFM[25]|CFM[24]|
|||CFM[23]|CFM[22]|CFM[21]|CFM[20]|CFM[19]|CFM[18]|CFM[17]|CFM[16]|
|||CFM[15]|CFM[14]|CFM[13]|CFM[12]|CFM[11]|CFM[10]|CFM[9]|CFM[8]|
|||CFM[7]|CFM[6]|CFM[5]|CFM[4]|CFM[3]|CFM[2]|CFM[1]|CFM[0]|
||TGC|-|-|-|-|-|-|-|-|
|||-|-|TBD3[1]|TBD3[0]|-|-|TBD2[1]|TBD2[0]|
|||-|-|TBD1[1]|TBD1[0]|-|-|TBD0[1]|TBD0[0]|
|||-|-|TQP[1]|TQP[0]|TSM3|TSM2|TSM1|TSM0|
||TCCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|TFR|TFEN|
|||-|-|-|-|TSRQ3|TSRQ2|TSRQ1|TSRQ0|
||TSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|TFFL[2]|TFFL[1]|TFFL[0]|
|||-|-|-|-|CCS1[1]|CCS1[0]|CCS0[1]|CCS0[0]|
||TFA0|TSV[31]|TSV[30]|TSV[29]|TSV[28]|TSV[27]|TSV[26]|TSV[25]|TSV[24]|
|||TSV[23]|TSV[22]|TSV[21]|TSV[20]|TSV[19]|TSV[18]|TSV[17]|TSV[16]|
|||TSV[15]|TSV[14]|TSV[13]|TSV[12]|TSV[11]|TSV[10]|TSV[9]|TSV[8]|
|||TSV[7]|TSV[6]|TSV[5]|TSV[4]|TSV[3]|TSV[2]|TSV[1]|TSV[0]|
||TFA1|TSV[63]|TSV[62]|TSV[61]|TSV[60]|TSV[59]|TSV[58]|TSV[57]|TSV[56]|
|||TSV[55]|TSV[54]|TSV[53]|TSV[52]|TSV[51]|TSV[50]|TSV[49]|TSV[48]|
|||TSV[47]|TSV[46]|TSV[45]|TSV[44]|TSV[43]|TSV[42]|TSV[41]|TSV[40]|
|||TSV[39]|TSV[38]|TSV[37]|TSV[36]|TSV[35]|TSV[34]|TSV[33]|TSV[32]|
||TFA2|-|-|-|-|-|-|TST[9]|TST[8]|
|||TST[7]|TST[6]|TST[5]|TST[4]|TST[3]|TST[2]|TST[1]|TST[0]|
|||TSV[79]|TSV[78]|TSV[77]|TSV[76]|TSV[75]|TSV[74]|TSV[73]|TSV[72]|
|||TSV[71]|TSV[70]|TSV[69]|TSV[68]|TSV[67]|TSV[66]|TSV[65]|TSV[64]|
||CIVR0|CIV[31]|CIV[30]|CIV[29]|CIV[28]|CIV[27]|CIV[26]|CIV[25]|CIV[24]|
|||CIV[23]|CIV[22]|CIV[21]|CIV[20]|CIV[19]|CIV[18]|CIV[17]|CIV[16]|
|||CIV[15]|CIV[14]|CIV[13]|CIV[12]|CIV[11]|CIV[10]|CIV[9]|CIV[8]|
|||CIV[7]|CIV[6]|CIV[5]|CIV[4]|CIV[3]|CIV[2]|CIV[1]|CIV[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|CIVR1|CIV[31]|CIV[30]|CIV[29]|CIV[28]|CIV[27]|CIV[26]|CIV[25]|CIV[24]|
|||CIV[23]|CIV[22]|CIV[21]|CIV[20]|CIV[19]|CIV[18]|CIV[17]|CIV[16]|
|||CIV[15]|CIV[14]|CIV[13]|CIV[12]|CIV[11]|CIV[10]|CIV[9]|CIV[8]|
|||CIV[7]|CIV[6]|CIV[5]|CIV[4]|CIV[3]|CIV[2]|CIV[1]|CIV[0]|
||CDVR0|CDV[31]|CDV[30]|CDV[29]|CDV[28]|CDV[27]|CDV[26]|CDV[25]|CDV[24]|
|||CDV[23]|CDV[22]|CDV[21]|CDV[20]|CDV[19]|CDV[18]|CDV[17]|CDV[16]|
|||CDV[15]|CDV[14]|CDV[13]|CDV[12]|CDV[11]|CDV[10]|CDV[9]|CDV[8]|
|||CDV[7]|CDV[6]|CDV[5]|CDV[4]|CDV[3]|CDV[2]|CDV[1]|CDV[0]|
||CDVR1|CDV[31]|CDV[30]|CDV[29]|CDV[28]|CDV[27]|CDV[26]|CDV[25]|CDV[24]|
|||CDV[23]|CDV[22]|CDV[21]|CDV[20]|CDV[19]|CDV[18]|CDV[17]|CDV[16]|
|||CDV[15]|CDV[14]|CDV[13]|CDV[12]|CDV[11]|CDV[10]|CDV[9]|CDV[8]|
|||CDV[7]|CDV[6]|CDV[5]|CDV[4]|CDV[3]|CDV[2]|CDV[1]|CDV[0]|
||CUL0|ULV[31]|ULV[30]|ULV[29]|ULV[28]|ULV[27]|ULV[26]|ULV[25]|ULV[24]|
|||ULV[23]|ULV[22]|ULV[21]|ULV[20]|ULV[19]|ULV[18]|ULV[17]|ULV[16]|
|||ULV[15]|ULV[14]|ULV[13]|ULV[12]|ULV[11]|ULV[10]|ULV[9]|ULV[8]|
|||ULV[7]|ULV[6]|ULV[5]|ULV[4]|ULV[3]|ULV[2]|ULV[1]|ULV[0]|
||CUL1|ULV[31]|ULV[30]|ULV[29]|ULV[28]|ULV[27]|ULV[26]|ULV[25]|ULV[24]|
|||ULV[23]|ULV[22]|ULV[21]|ULV[20]|ULV[19]|ULV[18]|ULV[17]|ULV[16]|
|||ULV[15]|ULV[14]|ULV[13]|ULV[12]|ULV[11]|ULV[10]|ULV[9]|ULV[8]|
|||ULV[7]|ULV[6]|ULV[5]|ULV[4]|ULV[3]|ULV[2]|ULV[1]|ULV[0]|
||CLL0|LLV[31]|LLV[30]|LLV[29]|LLV[28]|LLV[27]|LLV[26]|LLV[25]|LLV[24]|
|||LLV[23]|LLV[22]|LLV[21]|LLV[20]|LLV[19]|LLV[18]|LLV[17]|LLV[16]|
|||LLV[15]|LLV[14]|LLV[13]|LLV[12]|LLV[11]|LLV[10]|LLV[9]|LLV[8]|
|||LLV[7]|LLV[6]|LLV[5]|LLV[4]|LLV[3]|LLV[2]|LLV[1]|LLV[0]|
||CLL1|LLV[31]|LLV[30]|LLV[29]|LLV[28]|LLV[27]|LLV[26]|LLV[25]|LLV[24]|
|||LLV[23]|LLV[22]|LLV[21]|LLV[20]|LLV[19]|LLV[18]|LLV[17]|LLV[16]|
|||LLV[15]|LLV[14]|LLV[13]|LLV[12]|LLV[11]|LLV[10]|LLV[9]|LLV[8]|
|||LLV[7]|LLV[6]|LLV[5]|LLV[4]|LLV[3]|LLV[2]|LLV[1]|LLV[0]|
||DIC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DPE15|DPE14|DPE13|DPE12|DPE11|DPE10|DPE9|DPE8|
|||DPE7|DPE6|DPE5|DPE4|DPE3|DPE2|DPE1|-|
||DIS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||DPF15|DPF14|DPF13|DPF12|DPF11|DPF10|DPF9|DPF8|
|||DPF7|DPF6|DPF5|DPF4|DPF3|DPF2|DPF1|-|
||EIC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|TFFE|
|||CULE1|CULE0|CLLE1|CLLE0|SEE|QEE|-|-|
||EIS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|QFS|
|||-|-|-|-|-|-|-|TFFF|
|||CULF1|CULF0|CLLF1|CLLF0|SEF|QEF|-|-|
||RIC0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|FRE17|FRE16|
|||FRE15|FRE14|FRE13|FRE12|FRE11|FRE10|FRE9|FRE8|
|||FRE7|FRE6|FRE5|FRE4|FRE3|FRE2|FRE1|FRE0|
||RIS0|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|FRF17|FRF16|
|||FRF15|FRF14|FRF13|FRF12|FRF11|FRF10|FRF9|FRF8|
|||FRF7|FRF6|FRF5|FRF4|FRF3|FRF2|FRF1|FRF0|
||RIC1|RFWE|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
||RIS1|RFWF|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|RIC2|RFFE|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|QFE17|QFE16|
|||QFE15|QFE14|QFE13|QFE12|QFE11|QFE10|QFE9|QFE8|
|||QFE7|QFE6|QFE5|QFE4|QFE3|QFE2|QFE1|QFE0|
||RIS2|RFFF|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|QFF17|QFF16|
|||QFF15|QFF14|QFF13|QFF12|QFF11|QFF10|QFF9|QFF8|
|||QFF7|QFF6|QFF5|QFF4|QFF3|QFF2|QFF1|QFF0|
||TIC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|TFWE|TFUE|
|||-|-|-|-|-|-|-|-|
||TIS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|TFWF|TFUF|
|||-|-|-|-|-|-|-|-|
||ISS|DPS15|DPS14|DPS13|DPS12|DPS11|DPS10|DPS9|DPS8|
|||DPS7|DPS6|DPS5|DPS4|DPS3|DPS2|DPS1|-|
|||-|-|CGIS|RFWS|-|-|TFWS|TFUS|
|||MS|ES|-|-|-|-|-|-|
||GCCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|TCSS[1]|TCSS[0]|
|||-|-|LMTT|LPTC|LTI|LTO|TCR[1]|TCR[0]|
||GMTT|MTTV[31]|MTTV[30]|MTTV[29]|MTTV[28]|MTTV[27]|MTTV[26]|MTTV[25]|MTTV[24]|
|||MTTV[23]|MTTV[22]|MTTV[21]|MTTV[20]|MTTV[19]|MTTV[18]|MTTV[17]|MTTV[16]|
|||MTTV[15]|MTTV[14]|MTTV[13]|MTTV[12]|MTTV[11]|MTTV[10]|MTTV[9]|MTTV[8]|
|||MTTV[7]|MTTV[6]|MTTV[5]|MTTV[4]|MTTV[3]|MTTV[2]|MTTV[1]|MTTV[0]|
||GPTC|PTCV[31]|PTCV[30]|PTCV[29]|PTCV[28]|PTCV[27]|PTCV[26]|PTCV[25]|PTCV[24]|
|||PTCV[23]|PTCV[22]|PTCV[21]|PTCV[20]|PTCV[19]|PTCV[18]|PTCV[17]|PTCV[16]|
|||PTCV[15]|PTCV[14]|PTCV[13]|PTCV[12]|PTCV[11]|PTCV[10]|PTCV[9]|PTCV[8]|
|||PTCV[7]|PTCV[6]|PTCV[5]|PTCV[4]|PTCV[3]|PTCV[2]|PTCV[1]|PTCV[0]|
||GTI|-|-|-|-|TIV[27]|TIV[26]|TIV[25]|TIV[24]|
|||TIV[23]|TIV[22]|TIV[21]|TIV[20]|TIV[19]|TIV[18]|TIV[17]|TIV[16]|
|||TIV[15]|TIV[14]|TIV[13]|TIV[12]|TIV[11]|TIV[10]|TIV[9]|TIV[8]|
|||TIV[7]|TIV[6]|TIV[5]|TIV[4]|TIV[3]|TIV[2]|TIV[1]|TIV[0]|
||GTO0|TOV[31]|TOV[30]|TOV[29]|TOV[28]|TOV[27]|TOV[26]|TOV[25]|TOV[24]|
|||TOV[23]|TOV[22]|TOV[21]|TOV[20]|TOV[19]|TOV[18]|TOV[17]|TOV[16]|
|||TOV[15]|TOV[14]|TOV[13]|TOV[12]|TOV[11]|TOV[10]|TOV[9]|TOV[8]|
|||TOV[7]|TOV[6]|TOV[5]|TOV[4]|TOV[3]|TOV[2]|TOV[1]|TOV[0]|
||GTO1|TOV[63]|TOV[62]|TOV[61]|TOV[60]|TOV[59]|TOV[58]|TOV[57]|TOV[56]|
|||TOV[55]|TOV[54]|TOV[53]|TOV[52]|TOV[51]|TOV[50]|TOV[49]|TOV[48]|
|||TOV[47]|TOV[46]|TOV[45]|TOV[44]|TOV[43]|TOV[42]|TOV[41]|TOV[40]|
|||TOV[39]|TOV[38]|TOV[37]|TOV[36]|TOV[35]|TOV[34]|TOV[33]|TOV[32]|
||GTO2|TOV[95]|TOV[94]|TOV[93]|TOV[92]|TOV[91]|TOV[90]|TOV[89]|TOV[88]|
|||TOV[87]|TOV[86]|TOV[85]|TOV[84]|TOV[83]|TOV[82]|TOV[81]|TOV[80]|
|||TOV[79]|TOV[78]|TOV[77]|TOV[76]|TOV[75]|TOV[74]|TOV[73]|TOV[72]|
|||TOV[71]|TOV[70]|TOV[69]|TOV[68]|TOV[67]|TOV[66]|TOV[65]|TOV[64]|
||GIC|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|PTME|PTOE|PTCE|
||GIS|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|PTMF|PTOF|PTCF|
||GCPT|CPTV[31]|CPTV[30]|CPTV[29]|CPTV[28]|CPTV[27]|CPTV[26]|CPTV[25]|CPTV[24]|
|||CPTV[23]|CPTV[22]|CPTV[21]|CPTV[20]|CPTV[19]|CPTV[18]|CPTV[17]|CPTV[16]|
|||CPTV[15]|CPTV[14]|CPTV[13]|CPTV[12]|CPTV[11]|CPTV[10]|CPTV[9]|CPTV[8]|
|||CPTV[7]|CPTV[6]|CPTV[5]|CPTV[4]|CPTV[3]|CPTV[2]|CPTV[1]|CPTV[0]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|GCT0|CTV[31]|CTV[30]|CTV[29]|CTV[28]|CTV[27]|CTV[26]|CTV[25]|CTV[24]|
|||CTV[23]|CTV[22]|CTV[21]|CTV[20]|CTV[19]|CTV[18]|CTV[17]|CTV[16]|
|||CTV[15]|CTV[14]|CTV[13]|CTV[12]|CTV[11]|CTV[10]|CTV[9]|CTV[8]|
|||CTV[7]|CTV[6]|CTV[5]|CTV[4]|CTV[3]|CTV[2]|CTV[1]|CTV[0]|
||GCT1|CTV[63]|CTV[62]|CTV[61]|CTV[60]|CTV[59]|CTV[58]|CTV[57]|CTV[56]|
|||CTV[55]|CTV[54]|CTV[53]|CTV[52]|CTV[51]|CTV[50]|CTV[49]|CTV[48]|
|||CTV[47]|CTV[46]|CTV[45]|CTV[44]|CTV[43]|CTV[42]|CTV[41]|CTV[40]|
|||CTV[39]|CTV[38]|CTV[37]|CTV[36]|CTV[35]|CTV[34]|CTV[33]|CTV[32]|
||GCT2|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||CTV[79]|CTV[78]|CTV[77]|CTV[76]|CTV[75]|CTV[74]|CTV[73]|CTV[72]|
|||CTV[71]|CTV[70]|CTV[69]|CTV[68]|CTV[67]|CTV[66]|CTV[65]|CTV[64]|
||GCEC|-|-|-|-|-|DRC[10]|DRC[9]|DRC[8]|
|||DRC[7]|DRC[6]|DRC[5]|DRC[4]|DRC[3]|DRC[2]|DRC[1]|DRC[0]|
|||-|-|-|-|-|-|SCS[1]|SCS[0]|
|||-|-|-|DEN|-|-|-|CES|
||ECMR|-|-|-|-|-|TRCCM|-|-|
|||RCSC|-|DPAD|RZPF|ZPF|PFR|RXF|TXF|
|||-|-|-|-|-|-|-|-|
|||-|RE|TE|-|-|-|DM|PRM|
||RFLR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|RFL[17]|RFL[16]|
|||RFL[15]|RFL[14]|RFL[13]|RFL[12]|RFL[11]|RFL[10]|RFL[9]|RFL[8]|
|||RFL[7]|RFL[6]|RFL[5]|RFL[4]|RFL[3]|RFL[2]|RFL[1]|RFL[0]|
||ECSR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|PFROI|-|-|-|ICD|
||ECSIPR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|PFROIP|-|-|-|ICDIP|
||PIR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||-|-|-|-|MDI|MDO|MMID|MDC|
||APR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||AP[15]|AP[14]|AP[13]|AP[12]|AP[11]|AP[10]|AP[9]|AP[8]|
|||AP[7]|AP[6]|AP[5]|AP[4]|AP[3]|AP[2]|AP[1]|AP[0]|
||MPR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||MP[15]|MP[14]|MP[13]|MP[12]|MP[11]|MP[10]|MP[9]|MP[8]|
|||MP[7]|MP[6]|MP[5]|MP[4]|MP[3]|MP[2]|MP[1]|MP[0]|
||PFTCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||PFTXC[15]|PFTXC[14]|PFTXC[13]|PFTXC[12]|PFTXC[11]|PFTXC[10]|PFTXC[9]|PFTXC[8]|
|||PFTXC[7]|PFTXC[6]|PFTXC[5]|PFTXC[4]|PFTXC[3]|PFTXC[2]|PFTXC[1]|PFTXC[0]|
||PFRCR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||PFRXC[15]|PFRXC[14]|PFRXC[13]|PFRXC[12]|PFRXC[11]|PFRXC[10]|PFRXC[9]|PFRXC[8]|
|||PFRXC[7]|PFRXC[6]|PFRXC[5]|PFRXC[4]|PFRXC[3]|PFRXC[2]|PFRXC[1]|PFRXC[0]|
||TPAUSER|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||TPAUSE[15]|TPAUSE[14]|TPAUSE[13]|TPAUSE[12]|TPAUSE[11]|TPAUSE[10]|TPAUSE[9]|TPAUSE[8]|
|||TPAUSE[7]|TPAUSE[6]|TPAUSE[5]|TPAUSE[4]|TPAUSE[3]|TPAUSE[2]|TPAUSE[1]|TPAUSE[0]|
||MAHR|MA[47]|MA[46]|MA[45]|MA[44]|MA[43]|MA[42]|MA[41]|MA[40]|
|||MA[39]|MA[38]|MA[37]|MA[36]|MA[35]|MA[34]|MA[33]|MA[32]|
|||MA[31]|MA[30]|MA[29]|MA[28]|MA[27]|MA[26]|MA[25]|MA[24]|
|||MA[23]|MA[22]|MA[21]|MA[20]|MA[19]|MA[18]|MA[17]|MA[16]|

## **Table 46.2 Register Bits**

|**Module**|**Register**<br>**Abbreviation**|**Bits 31/23/15/7**|**Bits 30/22/14/6**|**Bits 29/21/13/5**|**Bits 28/20/12/4**|**Bits 27/19/11/3**|**Bits 26/18/10/2**|**Bits 25/17/9/1**|**Bits 24/16/8/0**|
|---|---|---|---|---|---|---|---|---|---|
|EthernetAVB*2|MALR|-|-|-|-|-|-|-|-|
|||-|-|-|-|-|-|-|-|
|||MA[15]|MA[14]|MA[13]|MA[12]|MA[11]|MA[10]|MA[9]|MA[8]|
|||MA[7]|MA[6]|MA[5]|MA[4]|MA[3]|MA[2]|MA[1]|MA[0]|
||CEFCR|CEFC[31]|CEFC[30]|CEFC[29]|CEFC[28]|CEFC[27]|CEFC[26]|CEFC[25]|CEFC[24]|
|||CEFC[23]|CEFC[22]|CEFC[21]|CEFC[20]|CEFC[19]|CEFC[18]|CEFC[17]|CEFC[16]|
|||CEFC[15]|CEFC[14]|CEFC[13]|CEFC[12]|CEFC[11]|CEFC[10]|CEFC[9]|CEFC[8]|
|||CEFC[7]|CEFC[6]|CEFC[5]|CEFC[4]|CEFC[3]|CEFC[2]|CEFC[1]|CEFC[0]|
||FRECR|FREC[31]|FREC[30]|FREC[29]|FREC[28]|FREC[27]|FREC[26]|FREC[25]|FREC[24]|
|||FREC[23]|FREC[22]|FREC[21]|FREC[20]|FREC[19]|FREC[18]|FREC[17]|FREC[16]|
|||FREC[15]|FREC[14]|FREC[13]|FREC[12]|FREC[11]|FREC[10]|FREC[9]|FREC[8]|
|||FREC[7]|FREC[6]|FREC[5]|FREC[4]|FREC[3]|FREC[2]|FREC[1]|FREC[0]|
||TSFRCR|TSFRC[31]|TSFRC[30]|TSFRC[29]|TSFRC[28]|TSFRC[27]|TSFRC[26]|TSFRC[25]|TSFRC[24]|
|||TSFRC[23]|TSFRC[22]|TSFRC[21]|TSFRC[20]|TSFRC[19]|TSFRC[18]|TSFRC[17]|TSFRC[16]|
|||TSFRC[15]|TSFRC[14]|TSFRC[13]|TSFRC[12]|TSFRC[11]|TSFRC[10]|TSFRC[9]|TSFRC[8]|
|||TSFRC[7]|TSFRC[6]|TSFRC[5]|TSFRC[4]|TSFRC[3]|TSFRC[2]|TSFRC[1]|TSFRC[0]|
||TLFRCR|TLFC[31]|TLFC[30]|TLFC[29]|TLFC[28]|TLFC[27]|TLFC[26]|TLFC[25]|TLFC[24]|
|||TLFC[23]|TLFC[22]|TLFC[21]|TLFC[20]|TLFC[19]|TLFC[18]|TLFC[17]|TLFC[16]|
|||TLFC[15]|TLFC[14]|TLFC[13]|TLFC[12]|TLFC[11]|TLFC[10]|TLFC[9]|TLFC[8]|
|||TLFC[7]|TLFC[6]|TLFC[5]|TLFC[4]|TLFC[3]|TLFC[2]|TLFC[1]|TLFC[0]|
||RFCR|RFC[31]|RFC[30]|RFC[29]|RFC[28]|RFC[27]|RFC[26]|RFC[25]|RFC[24]|
|||RFC[23]|RFC[22]|RFC[21]|RFC[20]|RFC[19]|RFC[18]|RFC[17]|RFC[16]|
|||RFC[15]|RFC[14]|RFC[13]|RFC[12]|RFC[11]|RFC[10]|RFC[9]|RFC[8]|
|||RFC[7]|RFC[6]|RFC[5]|RFC[4]|RFC[3]|RFC[2]|RFC[1]|RFC[0]|
||MAFCR|MAFC[31]|MAFC[30]|MAFC[29]|MAFC[28]|MAFC[27]|MAFC[26]|MAFC[25]|MAFC[24]|
|||MAFC[23]|MAFC[22]|MAFC[21]|MAFC[20]|MAFC[19]|MAFC[18]|MAFC[17]|MAFC[16]|
|||MAFC[15]|MAFC[14]|MAFC[13]|MAFC[12]|MAFC[11]|MAFC[10]|MAFC[9]|MAFC[8]|
|||MAFC[7]|MAFC[6]|MAFC[5]|MAFC[4]|MAFC[3]|MAFC[2]|MAFC[1]|MAFC[0]|

Note 1. RZ/A1L only Note 2. RZ/A1LU only

Note 3. RZ/A1L only. This bit is reserved in the RZ/A1LU and RZ/A1LC. Note 4. RZ/A1LU only. This bit is reserved in the RZ/A1L and RZ/A1LC. Note 5. RZ/A1L and RZ/A1LU only. This bit is reserved in the RZ/A1LC. Note 6. RZ/A1LU and RZ/A1LC only. This bit is reserved in the RZ/A1L.

## 46.3 Register States

## **Table 46.3 Register States**

|**Table 46.3**<br>**Register States**|||||||
|---|---|---|---|---|---|---|
|**Module**|**Register Name**|**Power-On**<br>**Reset**|**Deep Standby**|**Software**<br>**Standby**|**Module**<br>**Standby**|**Sleep**|
|Secondary cache|All registers|Initialized|Initialized|Retained|-|Retained|
|LSI internal bus|All registers|Initialized|Initialized|Retained|-|Retained|
|Clock pulse generator|FRQCR|Initialized*1|Initialized|Retained|-|Retained|
|Interrupt controller|All registers|Initialized|Initialized|Retained|-|Retained|
|Bus state controller|RTCSR|Initialized|Initialized|Retained|-|Retained*2|
||RTCNT|Initialized|Initialized|Retained|-|Retained*3|
||All registers other<br>than above|Initialized|Initialized|Retained|-|Retained|
|Direct memory access controller|All registers|Initialized|Initialized|Retained|-|Retained*4|
|Multi-function timer pulse unit 2|All registers|Initialized|Initialized|Initialized|Retained|Retained|
|OS timer|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Watchdog timer|WRCSR|Initialized*1|Initialized|Retained|-|Retained|
||All registers other<br>than above|Initialized|Initialized|Retained|-|Retained|
|Realtime clock|R64CNT|Retained*3|Retained*3|Retained*3|Retained|Retained*3|
||RSECCNT||||||
||RMINCNT||||||
||RHRCNT||||||
||RWKCNT||||||
||RDAYCNT||||||
||RMONCNT||||||
||RYRCNT||||||
||RSECAR|Retained|Retained|Retained|Retained|Retained|
||RMINAR||||||
||RHRAR||||||
||RWKAR||||||
||RDAYAR||||||
||RMONAR||||||
||RYRAR||||||
||RCR1|Initialized|Initialized|Retained|Retained|Retained|
||RCR2|Initialized|Initialized*5|Retained|Retained|Retained|
||RCR3|Retained|Retained|Retained|Retained|Retained|
||RCR5|Retained|Retained|Retained|Retained|Retained|
||RFRH|Retained|Retained|Retained|Retained|Retained|
||RFRL|Retained|Retained|Retained|Retained|Retained|
|Serial communication interface with FIFO|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Serial communications interface|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Renesas serial peripheral interface|All registers|Initialized|Initialized|Retained|Retained|Retained|
|SPI multi I/O bus controller|All registers|Initialized|Initialized|Retained|Retained|Retained|
|I2C bus interface|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Serial sound interface|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Media local bus*11|All registers|Initialized|Initialized|Retained|Retained|Retained|
|CAN interface|All registers|Initialized|Initialized|Retained|Retained|Retained|
|IEBus controller*11|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Renesas SPDIF interface|All registers|Initialized|Initialized|Retained|Retained|Retained|
|CD-ROM decoder*11|All registers|Initialized|Initialized|Retained|Retained|Retained|
|LIN interface*11|All registers|Initialized|Initialized|Retained|Retained|Retained|

**Table 46.3 Register States**

|**Table 46.3**<br>**Register States**|||||||
|---|---|---|---|---|---|---|
|**Module**|**Register Name**|**Power-On**<br>**Reset**|**Deep Standby**|**Software**<br>**Standby**|**Module**<br>**Standby**|**Sleep**|
|Ethernet controller|All registers|Initialized|Initialized|Retained|Retained|Retained|
|EthernetAVB*12|All registers|Initialized|Initialized|Retained|Retained|Retained|
|A/D converter|All registers|Initialized|Initialized|Initialized|Initialized|Retained|
|USB2.0 host/function module|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Video display controller 5|All registers|Initialized|Initialized|Retained|Retained|Retained|
|JPEG codec unit*12|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Capture engine unit|All registers|Initialized|Initialized|Retained|Retained|Retained|
|SCUX|All registers|Initialized|Initialized|Retained|Retained|Retained|
|SD host interface|All registers|Initialized|Initialized|Retained|Retained|Retained|
|MMC host interface|All registers|Initialized|Initialized|Retained|Retained|Retained|
|Ports|All registers*10|Initialized|Initialized|Retained|-|Retained|
|Power-down modes|DSFR|Initialized|Retained|Retained|-|Retained|
||XTALCTR|Initialized*1|Retained*6|Retained*6|-|Retained|
||All registers other<br>than above|Initialized|Initialized|Retained|-|Retained|
|Debugger interface|Registers in CA9<br>PMU*7|Initialized|Initialized|Retained|-|Retained|
||All registers other<br>than above*8|Retained|Initialized*9|Retained|Retained|Retained|

Note 1. Retained on internal power-on reset by the watchdog timer. Note 2. Flag processing continues. Note 3. Counting up continues. Note 4. Transfer can proceed. Note 5. The value of RTCEN bit is retained. Note 6. The GAIN0 bit is initialized when the realtime clock is not using the EXTAL pin. Note 7. Access to these registers from the I/O area (SLV6) is not possible while TRST is asserted. Note 8. Initialized on assertion of TRST. Note 9. Retained in FAKE debug mode. Note 10.An internal power-on reset by the watchdog timer does not initialize PM6[0], PMC6[0], PFC6[0], PFCE6[0], and PFCAE6[0]. Note 11.RZ/A1L only

Note 12.RZ/A1LU only
