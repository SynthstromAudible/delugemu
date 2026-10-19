# 9. Direct Memory Access Controller

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 265–341. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

The direct memory access controller can be used in place of the CPU to perform high-speed transfers between external devices that have DACK (transfer request acknowledge signal), external memory, on-chip memory, memory-mapped external devices, and on-chip peripheral modules.

## 9.1 Features

- Number of channels selectable: 16 channels (CH0 to CH15). Only the CH0 channel can receive external requests.

- 4-Gbyte address space (according to the architecture)

- Transfer data size: Byte, two bytes, four bytes, eight bytes, 16 bytes, 32 bytes, 64 bytes, and 128 bytes

- Maximum transfer count: 2[32] - 1 bytes

- Address mode: Dual address mode

- Transfer requests: Can be selected from the three types of external request, on-chip peripheral module request, and auto request (software trigger)

The following modules can issue on-chip peripheral module requests.

   - —Serial communication interface with FIFO: 10 sources

   - —A/D converter: 1 source

   - Multi-function timer pulse unit 2: 5 sources

   - —USB2.0 host/function module: 4 sources

   - —Serial sound interface: 7 sources

   - —Renesas SPDIF interface: 2 sources

   - CD-ROM decoder: 1 source (RZ/A1L only)

   - —SD host interface: 4 sources

   - —MMC host interface: 2 sources

   - Renesas serial peripheral interface: 6 sources

   - IEBus™ controller: 2 sources (RZ/A1L only)

   - —OS timer: 2 sources

   - —SCUX: 8 sources

   - Media local bus: 1 source (RZ/A1L only)

   - —Serial communication interface: 4 sources

   - —I[2] C bus interface: 8 sources

   - LIN interface: 2 sources (RZ/A1L only)

- Transfer mode: Single transfer mode and block transfer mode are selectable.

- Priority: The channel priority levels within channels 0 to 7 and within channels 8 to 15 are selectable between fixed mode and round-robin mode (the channel priority level between the group of channels 0 to 7 and the group of channels 8 to 15 is round-robin mode).

- Interrupt request: An interrupt request can be sent to the CPU on completion of data transfer (DMA transfer end interrupt per channel) or on occurrence of a transfer error (DMA error interrupt).

- External request detection: Low level detection, high level detection, rising edge detection, and falling edge detection are selectable for DREQ input detection.

- The DMA registers have a continuous execution function that allows the next DMA transfer to be executed continuously by making settings for the next DMA transfer during execution of the current DMA transfer. This continuous execution function can be enabled or disabled independently in each channel.

- Link mode: In this mode, the setting data (descriptor data) located in the memory by the CPU is automatically retrieved by the DMAC, and DMA transfer is performed according to those values.

- Buffer sweep: If an ongoing DMA transfer is forced to end, the data already retrieved into the buffer can be output before DMA transfer ends.

- Interval: A specific DMA transfer interval can be specified to adjust the bus occupancy.

## 9.2 Input/Output Pins

Table 9.1 lists the pin configuration. This module has pins for a single channel (CH0) as the external bus use.

## **Table 9.1 Pin Configuration**

|**Table 9.1**|**Pin Configuration**|
|---|---|
|**Channel**|**Name**<br>**Pin**<br>**Name**<br>**I/O**<br>**Function**|
|0|DMA transfer request<br>DREQ0<br>Input<br>DMA transfer request input from an external device to channel 0|
||DMA transfer request acknowledge<br>DACK0<br>Output<br>DMA transfer request acknowledge output from channel 0 of<br>this module|
||DMA transfer end<br>TEND0<br>Output<br>DMA transfer end output for channel 0 of this module|

Note 1. For the active level of DACK0 and TEND0, refer to section 8, Bus State Controller.

## 9.3 Register Configuration

The register configuration is shown in the figure below.

**==> picture [380 x 353] intentionally omitted <==**

**----- Start of picture text -----**<br>
DMA<br>Channel<br>Next Register Set Current Register Set<br>Next0 Register Set Source Address<br>Source Address Destination Address 2. Transfe r<br>1. Load<br>Destination Address Transaction Byte<br>Transaction Byte<br>Channel Registers Set<br>Channel Status<br>Next1 Register Set Channel Control<br>Source Address Channel Configuration<br>Destination Address Channel Interval<br>Transaction Byte Channel Extension<br>Select<br>Link Registers Set<br>Next Link Address<br>Current Link Address<br>DMA Control<br>DMA Status EN<br>DMA Status ER<br>DMA Registers Set<br>DMA Status END<br>DMA Status TC<br>DMA Status SUS<br>**----- End of picture text -----**<br>

## **Figure 9.1 Register Configuration**

## (a) Next Register Set

This register set is used to set the source address, destination address, and transfer byte count of the DMA transaction to be executed next.

It consists of the Next0 Register Set and the Next1 Register Set.

In register mode, set this register set by using software. In link mode, the descriptor read data is automatically set in the Next0 Register Set.

These register set values are loaded to the Current Register Set and used for DMA transfer.

## (b) Current Register Set

This register set indicates the source address, destination address, and transfer byte count of the currently executed DMA transaction.

The values are loaded from the Next0/1 Register Set (register mode) or from the descriptor read data (link mode). The user cannot write directly to this register set.

The register set is automatically updated each time a DMA transaction is executed.

## (c) Channel Register Set

This register set is used to make the DMA transfer settings.

The settings to be made with this register set include channel status indication, channel control, DMA transaction setting, and DMA transaction interval.

## (d) Link Register Set

This register set consists of a register that sets the address of the descriptor to be loaded next in link mode (Next Link Address Register) and a register that indicates the address of the currently executed descriptor (Current Link Address Register).

The Current Link Address Register is automatically updated when a descriptor is read. The user cannot write directly to this register set.

## (e) DMA Register Set

This register set consists of a register that controls DMA as a whole and registers that indicate the status of the corresponding channels. It enables channel priority control as well as the monitoring of the channel status (EN, ER, END, TC, and SUS).

## (f) Extended Resource Selector Register Set

This register set is used to select the on-chip peripheral module to perform DMA transfer and the external request.

## 9.4 Register Descriptions

Table 9.2 lists the register configuration. There are eleven control registers and five status registers for each channel, and twelve common control registers are used by all channels. In addition, there is one extension resource selector per two channels. Each channel number is expressed in the register names, as in N0SA_0 for N0SA in channel 0.

**Table 9.2 Register Configuration**

|**Table 9.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|0|Next0 source address register 0<br>N0SA_0<br>RW<br>H'00000000<br>H'E8200000<br>32|
||Next0 destination address register 0<br>N0DA_0<br>RW<br>H'00000000<br>H'E8200004<br>32|
||Next0 transaction byte register 0<br>N0TB_0<br>RW<br>H'00000000<br>H'E8200008<br>32|
||Next1 source address register 0<br>N1SA_0<br>RW<br>H'00000000<br>H'E820000C<br>32|
||Next1 destination address register 0<br>N1DA_0<br>RW<br>H'00000000<br>H'E8200010<br>32|
||Next1 transaction byte register 0<br>N1TB_0<br>RW<br>H'00000000<br>H'E8200014<br>32|
||Current source address register 0<br>CRSA_0<br>R<br>H'00000000<br>H'E8200018<br>32|
||Current destination address register 0<br>CRDA_0<br>R<br>H'00000000<br>H'E820001C<br>32|
||Current transaction byte register 0<br>CRTB_0<br>R<br>H'00000000<br>H'E8200020<br>32|
||Channel status register 0<br>CHSTAT_0<br>R<br>H'00000000<br>H'E8200024<br>32|
||Channel control register 0<br>CHCTRL_0<br>RW<br>H'00000000<br>H'E8200028<br>32|
||Channel configuration register 0<br>CHCFG_0<br>RW<br>H'00000000<br>H'E820002C<br>32|
||Channel interval register 0<br>CHITVL_0<br>RW<br>H'00000000<br>H'E8200030<br>32|
||Channel extension register 0<br>CHEXT_0<br>RW<br>H'00000000<br>H'E8200034<br>32|
||Next link address register 0<br>NXLA_0<br>RW<br>H'00000000<br>H'E8200038<br>32|
||Current link address register 0<br>CRLA_0<br>R<br>H'00000000<br>H'E820003C<br>32|
|1|Next0 source address register 1<br>N0SA_1<br>RW<br>H'00000000<br>H'E8200040<br>32|
||Next0 destination address register 1<br>N0DA_1<br>RW<br>H'00000000<br>H'E8200044<br>32|
||Next0 transaction byte register 1<br>N0TB_1<br>RW<br>H'00000000<br>H'E8200048<br>32|
||Next1 source address register 1<br>N1SA_1<br>RW<br>H'00000000<br>H'E820004C<br>32|
||Next1 destination address register 1<br>N1DA_1<br>RW<br>H'00000000<br>H'E8200050<br>32|
||Next1 transaction byte register 1<br>N1TB_1<br>RW<br>H'00000000<br>H'E8200054<br>32|
||Current source address register 1<br>CRSA_1<br>R<br>H'00000000<br>H'E8200058<br>32|
||Current destination address register 1<br>CRDA_1<br>R<br>H'00000000<br>H'E820005C<br>32|
||Current transaction byte register 1<br>CRTB_1<br>R<br>H'00000000<br>H'E8200060<br>32|
||Channel status register 1<br>CHSTAT_1<br>R<br>H'00000000<br>H'E8200064<br>32|
||Channel control register 1<br>CHCTRL_1<br>RW<br>H'00000000<br>H'E8200068<br>32|
||Channel configuration register 1<br>CHCFG_1<br>RW<br>H'00000000<br>H'E820006C<br>32|
||Channel interval register 1<br>CHITVL_1<br>RW<br>H'00000000<br>H'E8200070<br>32|
||Channel extension register 1<br>CHEXT_1<br>RW<br>H'00000000<br>H'E8200074<br>32|
||Next link address register 1<br>NXLA_1<br>RW<br>H'00000000<br>H'E8200078<br>32|
||Current link address register 1<br>CRLA_1<br>R<br>H'00000000<br>H'E820007C<br>32|

**Table 9.2 Register Configuration**

|**Table 9.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|2|Next0 source address register 2<br>N0SA_2<br>RW<br>H'00000000<br>H'E8200080<br>32|
||Next0 destination address register 2<br>N0DA_2<br>RW<br>H'00000000<br>H'E8200084<br>32|
||Next0 transaction byte register 2<br>N0TB_2<br>RW<br>H'00000000<br>H'E8200088<br>32|
||Next1 source address register 2<br>N1SA_2<br>RW<br>H'00000000<br>H'E820008C<br>32|
||Next1 destination address register 2<br>N1DA_2<br>RW<br>H'00000000<br>H'E8200090<br>32|
||Next1 transaction byte register 2<br>N1TB_2<br>RW<br>H'00000000<br>H'E8200094<br>32|
||Current source address register 2<br>CRSA_2<br>R<br>H'00000000<br>H'E8200098<br>32|
||Current destination address register 2<br>CRDA_2<br>R<br>H'00000000<br>H'E820009C<br>32|
||Current transaction byte register 2<br>CRTB_2<br>R<br>H'00000000<br>H'E82000A0<br>32|
||Channel status register 2<br>CHSTAT_2<br>R<br>H'00000000<br>H'E82000A4<br>32|
||Channel control register 2<br>CHCTRL_2<br>RW<br>H'00000000<br>H'E82000A8<br>32|
||Channel configuration register 2<br>CHCFG_2<br>RW<br>H'00000000<br>H'E82000AC<br>32|
||Channel interval register 2<br>CHITVL_2<br>RW<br>H'00000000<br>H'E82000B0<br>32|
||Channel extension register 2<br>CHEXT_2<br>RW<br>H'00000000<br>H'E82000B4<br>32|
||Next link address register 2<br>NXLA_2<br>RW<br>H'00000000<br>H'E82000B8<br>32|
||Current link address register 2<br>CRLA_2<br>R<br>H'00000000<br>H'E82000BC<br>32|
|3|Next0 source address register 3<br>N0SA_3<br>RW<br>H'00000000<br>H'E82000C0<br>32|
||Next0 destination address register 3<br>N0DA_3<br>RW<br>H'00000000<br>H'E82000C4<br>32|
||Next0 transaction byte register 3<br>N0TB_3<br>RW<br>H'00000000<br>H'E82000C8<br>32|
||Next1 source address register 3<br>N1SA_3<br>RW<br>H'00000000<br>H'E82000CC<br>32|
||Next1 destination address register 3<br>N1DA_3<br>RW<br>H'00000000<br>H'E82000D0<br>32|
||Next1 transaction byte register 3<br>N1TB_3<br>RW<br>H'00000000<br>H'E82000D4<br>32|
||Current source address register 3<br>CRSA_3<br>R<br>H'00000000<br>H'E82000D8<br>32|
||Current destination address register 3<br>CRDA_3<br>R<br>H'00000000<br>H'E82000DC<br>32|
||Current transaction byte register 3<br>CRTB_3<br>R<br>H'00000000<br>H'E82000E0<br>32|
||Channel status register 3<br>CHSTAT_3<br>R<br>H'00000000<br>H'E82000E4<br>32|
||Channel control register 3<br>CHCTRL_3<br>RW<br>H'00000000<br>H'E82000E8<br>32|
||Channel configuration register 3<br>CHCFG_3<br>RW<br>H'00000000<br>H'E82000EC<br>32|
||Channel interval register 3<br>CHITVL_3<br>RW<br>H'00000000<br>H'E82000F0<br>32|
||Channel extension register 3<br>CHEXT_3<br>RW<br>H'00000000<br>H'E82000F4<br>32|
||Next link address register 3<br>NXLA_3<br>RW<br>H'00000000<br>H'E82000F8<br>32|
||Current link address register 3<br>CRLA_3<br>R<br>H'00000000<br>H'E82000FC<br>32|

**Table 9.2 Register Configuration**

|**Table 9.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|4|Next0 source address register 4<br>N0SA_4<br>RW<br>H'00000000<br>H'E8200100<br>32|
||Next0 destination address register 4<br>N0DA_4<br>RW<br>H'00000000<br>H'E8200104<br>32|
||Next0 transaction byte register 4<br>N0TB_4<br>RW<br>H'00000000<br>H'E8200108<br>32|
||Next1 source address register 4<br>N1SA_4<br>RW<br>H'00000000<br>H'E820010C<br>32|
||Next1 destination address register 4<br>N1DA_4<br>RW<br>H'00000000<br>H'E8200110<br>32|
||Next1 transaction byte register 4<br>N1TB_4<br>RW<br>H'00000000<br>H'E8200114<br>32|
||Current source address register 4<br>CRSA_4<br>R<br>H'00000000<br>H'E8200118<br>32|
||Current destination address register 4<br>CRDA_4<br>R<br>H'00000000<br>H'E820011C<br>32|
||Current transaction byte register 4<br>CRTB_4<br>R<br>H'00000000<br>H'E8200120<br>32|
||Channel status register 4<br>CHSTAT_4<br>R<br>H'00000000<br>H'E8200124<br>32|
||Channel control register 4<br>CHCTRL_4<br>RW<br>H'00000000<br>H'E8200128<br>32|
||Channel configuration register 4<br>CHCFG_4<br>RW<br>H'00000000<br>H'E820012C<br>32|
||Channel interval register 4<br>CHITVL_4<br>RW<br>H'00000000<br>H'E8200130<br>32|
||Channel extension register 4<br>CHEXT_4<br>RW<br>H'00000000<br>H'E8200134<br>32|
||Next link address register 4<br>NXLA_4<br>RW<br>H'00000000<br>H'E8200138<br>32|
||Current link address register 4<br>CRLA_4<br>R<br>H'00000000<br>H'E820013C<br>32|
|5|Next0 source address register 5<br>N0SA_5<br>RW<br>H'00000000<br>H'E8200140<br>32|
||Next0 destination address register 5<br>N0DA_5<br>RW<br>H'00000000<br>H'E8200144<br>32|
||Next0 transaction byte register 5<br>N0TB_5<br>RW<br>H'00000000<br>H'E8200148<br>32|
||Next1 source address register 5<br>N1SA_5<br>RW<br>H'00000000<br>H'E820014C<br>32|
||Next1 destination address register 5<br>N1DA_5<br>RW<br>H'00000000<br>H'E8200150<br>32|
||Next1 transaction byte register 5<br>N1TB_5<br>RW<br>H'00000000<br>H'E8200154<br>32|
||Current source address register 5<br>CRSA_5<br>R<br>H'00000000<br>H'E8200158<br>32|
||Current destination address register 5<br>CRDA_5<br>R<br>H'00000000<br>H'E820015C<br>32|
||Current transaction byte register 5<br>CRTB_5<br>R<br>H'00000000<br>H'E8200160<br>32|
||Channel status register 5<br>CHSTAT_5<br>R<br>H'00000000<br>H'E8200164<br>32|
||Channel control register 5<br>CHCTRL_5<br>RW<br>H'00000000<br>H'E8200168<br>32|
||Channel configuration register 5<br>CHCFG_5<br>RW<br>H'00000000<br>H'E820016C<br>32|
||Channel interval register 5<br>CHITVL_5<br>RW<br>H'00000000<br>H'E8200170<br>32|
||Channel extension register 5<br>CHEXT_5<br>RW<br>H'00000000<br>H'E8200174<br>32|
||Next link address register 5<br>NXLA_5<br>RW<br>H'00000000<br>H'E8200178<br>32|
||Current link address register 5<br>CRLA_5<br>R<br>H'00000000<br>H'E820017C<br>32|

**Table 9.2 Register Configuration**

|**Table 9.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|6|Next0 source address register 6<br>N0SA_6<br>RW<br>H'00000000<br>H'E8200180<br>32|
||Next0 destination address register 6<br>N0DA_6<br>RW<br>H'00000000<br>H'E8200184<br>32|
||Next0 transaction byte register 6<br>N0TB_6<br>RW<br>H'00000000<br>H'E8200188<br>32|
||Next1 source address register 6<br>N1SA_6<br>RW<br>H'00000000<br>H'E820018C<br>32|
||Next1 destination address register 6<br>N1DA_6<br>RW<br>H'00000000<br>H'E8200190<br>32|
||Next1 transaction byte register 6<br>N1TB_6<br>RW<br>H'00000000<br>H'E8200194<br>32|
||Current source address register 6<br>CRSA_6<br>R<br>H'00000000<br>H'E8200198<br>32|
||Current destination address register 6<br>CRDA_6<br>R<br>H'00000000<br>H'E820019C<br>32|
||Current transaction byte register 6<br>CRTB_6<br>R<br>H'00000000<br>H'E82001A0<br>32|
||Channel status register 6<br>CHSTAT_6<br>R<br>H'00000000<br>H'E82001A4<br>32|
||Channel control register 6<br>CHCTRL_6<br>RW<br>H'00000000<br>H'E82001A8<br>32|
||Channel configuration register 6<br>CHCFG_6<br>RW<br>H'00000000<br>H'E82001AC<br>32|
||Channel interval register 6<br>CHITVL_6<br>RW<br>H'00000000<br>H'E82001B0<br>32|
||Channel extension register 6<br>CHEXT_6<br>RW<br>H'00000000<br>H'E82001B4<br>32|
||Next link address register 6<br>NXLA_6<br>RW<br>H'00000000<br>H'E82001B8<br>32|
||Current link address register 6<br>CRLA_6<br>R<br>H'00000000<br>H'E82001BC<br>32|
|7|Next0 source address register 7<br>N0SA_7<br>RW<br>H'00000000<br>H'E82001C0<br>32|
||Next0 destination address register 7<br>N0DA_7<br>RW<br>H'00000000<br>H'E82001C4<br>32|
||Next0 transaction byte register 7<br>N0TB_7<br>RW<br>H'00000000<br>H'E82001C8<br>32|
||Next1 source address register 7<br>N1SA_7<br>RW<br>H'00000000<br>H'E82001CC<br>32|
||Next1 destination address register 7<br>N1DA_7<br>RW<br>H'00000000<br>H'E82001D0<br>32|
||Next1 transaction byte register 7<br>N1TB_7<br>RW<br>H'00000000<br>H'E82001D4<br>32|
||Current source address register 7<br>CRSA_7<br>R<br>H'00000000<br>H'E82001D8<br>32|
||Current destination address register 7<br>CRDA_7<br>R<br>H'00000000<br>H'E82001DC<br>32|
||Current transaction byte register 7<br>CRTB_7<br>R<br>H'00000000<br>H'E82001E0<br>32|
||Channel status register 7<br>CHSTAT_7<br>R<br>H'00000000<br>H'E82001E4<br>32|
||Channel control register 7<br>CHCTRL_7<br>RW<br>H'00000000<br>H'E82001E8<br>32|
||Channel configuration register 7<br>CHCFG_7<br>RW<br>H'00000000<br>H'E82001EC<br>32|
||Channel interval register 7<br>CHITVL_7<br>RW<br>H'00000000<br>H'E82001F0<br>32|
||Channel extension register 7<br>CHEXT_7<br>RW<br>H'00000000<br>H'E82001F4<br>32|
||Next link address register 7<br>NXLA_7<br>RW<br>H'00000000<br>H'E82001F8<br>32|
||Current link address register 7<br>CRLA_7<br>R<br>H'00000000<br>H'E82001FC<br>32|
|Common<br>for 0 to 7|DMA control registers 0 to 7<br>DCTRL_0_7<br>R/W<br>H'00000000<br>H'E8200300<br>32|
||DMA status EN registers 0 to 7<br>DSTAT_EN_0_7<br>R<br>H'00000000<br>H'E8200310<br>32|
||DMA status ER registers 0 to 7<br>DSTAT_ER_0_7<br>R<br>H'00000000<br>H'E8200314<br>32|
||DMA status END registers 0 to 7<br>DSTAT_END_0_7<br>R<br>H'00000000<br>H'E8200318<br>32|
||DMA status TC registers 0 to 7<br>DSTAT_TC_0_7<br>R<br>H'00000000<br>H'E820031C<br>32|
||DMA status SUS registers 0 to 7<br>DSTAT_SUS_0_7<br>R<br>H'00000000<br>H'E8200320<br>32|

**Table 9.2 Register Configuration**

|**Table 9.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|8|Next0 source address register 8<br>N0SA_8<br>RW<br>H'00000000<br>H'E8200400<br>32|
||Next0 destination address register 8<br>N0DA_8<br>RW<br>H'00000000<br>H'E8200404<br>32|
||Next0 transaction byte register 8<br>N0TB_8<br>RW<br>H'00000000<br>H'E8200408<br>32|
||Next1 source address register 8<br>N1SA_8<br>RW<br>H'00000000<br>H'E820040C<br>32|
||Next1 destination address register 8<br>N1DA_8<br>RW<br>H'00000000<br>H'E8200410<br>32|
||Next1 transaction byte register 8<br>N1TB_8<br>RW<br>H'00000000<br>H'E8200414<br>32|
||Current source address register 8<br>CRSA_8<br>R<br>H'00000000<br>H'E8200418<br>32|
||Current destination address register 8<br>CRDA_8<br>R<br>H'00000000<br>H'E820041C<br>32|
||Current transaction byte register 8<br>CRTB_8<br>R<br>H'00000000<br>H'E8200420<br>32|
||Channel status register 8<br>CHSTAT_8<br>R<br>H'00000000<br>H'E8200424<br>32|
||Channel control register 8<br>CHCTRL_8<br>RW<br>H'00000000<br>H'E8200428<br>32|
||Channel configuration register 8<br>CHCFG_8<br>RW<br>H'00000000<br>H'E820042C<br>32|
||Channel interval register 8<br>CHITVL_8<br>RW<br>H'00000000<br>H'E8200430<br>32|
||Channel extension register 8<br>CHEXT_8<br>RW<br>H'00000000<br>H'E8200434<br>32|
||Next link address register 8<br>NXLA_8<br>RW<br>H'00000000<br>H'E8200438<br>32|
||Current link address register 8<br>CRLA_8<br>R<br>H'00000000<br>H'E820043C<br>32|
|9|Next0 source address register 9<br>N0SA_9<br>RW<br>H'00000000<br>H'E8200440<br>32|
||Next0 destination address register 9<br>N0DA_9<br>RW<br>H'00000000<br>H'E8200444<br>32|
||Next0 transaction byte register 9<br>N0TB_9<br>RW<br>H'00000000<br>H'E8200448<br>32|
||Next1 source address register 9<br>N1SA_9<br>RW<br>H'00000000<br>H'E820044C<br>32|
||Next1 destination address register 9<br>N1DA_9<br>RW<br>H'00000000<br>H'E8200450<br>32|
||Next1 transaction byte register 9<br>N1TB_9<br>RW<br>H'00000000<br>H'E8200454<br>32|
||Current source address register 9<br>CRSA_9<br>R<br>H'00000000<br>H'E8200458<br>32|
||Current destination address register 9<br>CRDA_9<br>R<br>H'00000000<br>H'E820045C<br>32|
||Current transaction byte register 9<br>CRTB_9<br>R<br>H'00000000<br>H'E8200460<br>32|
||Channel status register 9<br>CHSTAT_9<br>R<br>H'00000000<br>H'E8200464<br>32|
||Channel control register 9<br>CHCTRL_9<br>RW<br>H'00000000<br>H'E8200468<br>32|
||Channel configuration register 9<br>CHCFG_9<br>RW<br>H'00000000<br>H'E820046C<br>32|
||Channel interval register 9<br>CHITVL_9<br>RW<br>H'00000000<br>H'E8200470<br>32|
||Channel extension register 9<br>CHEXT_9<br>RW<br>H'00000000<br>H'E8200474<br>32|
||Next link address register 9<br>NXLA_9<br>RW<br>H'00000000<br>H'E8200478<br>32|
||Current link address register 9<br>CRLA_9<br>R<br>H'00000000<br>H'E820047C<br>32|

**Table 9.2 Register Configuration**

|**Table 9.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|10|Next0 source address register 10<br>N0SA_10<br>RW<br>H'00000000<br>H'E8200480<br>32|
||Next0 destination address register 10<br>N0DA_10<br>RW<br>H'00000000<br>H'E8200484<br>32|
||Next0 transaction byte register 10<br>N0TB_10<br>RW<br>H'00000000<br>H'E8200488<br>32|
||Next1 source address register 10<br>N1SA_10<br>RW<br>H'00000000<br>H'E820048C<br>32|
||Next1 destination address register 10<br>N1DA_10<br>RW<br>H'00000000<br>H'E8200490<br>32|
||Next1 transaction byte register 10<br>N1TB_10<br>RW<br>H'00000000<br>H'E8200494<br>32|
||Current source address register 10<br>CRSA_10<br>R<br>H'00000000<br>H'E8200498<br>32|
||Current destination address register 10<br>CRDA_10<br>R<br>H'00000000<br>H'E820049C<br>32|
||Current transaction byte register 10<br>CRTB_10<br>R<br>H'00000000<br>H'E82004A0<br>32|
||Channel status register 10<br>CHSTAT_10<br>R<br>H'00000000<br>H'E82004A4<br>32|
||Channel control register 10<br>CHCTRL_10<br>RW<br>H'00000000<br>H'E82004A8<br>32|
||Channel configuration register 10<br>CHCFG_10<br>RW<br>H'00000000<br>H'E82004AC<br>32|
||Channel interval register 10<br>CHITVL_10<br>RW<br>H'00000000<br>H'E82004B0<br>32|
||Channel extension register 10<br>CHEXT_10<br>RW<br>H'00000000<br>H'E82004B4<br>32|
||Next link address register 10<br>NXLA_10<br>RW<br>H'00000000<br>H'E82004B8<br>32|
||Current link address register 10<br>CRLA_10<br>R<br>H'00000000<br>H'E82004BC<br>32|
|11|Next0 source address register 11<br>N0SA_11<br>RW<br>H'00000000<br>H'E82004C0<br>32|
||Next0 destination address register 11<br>N0DA_11<br>RW<br>H'00000000<br>H'E82004C4<br>32|
||Next0 transaction byte register 11<br>N0TB_11<br>RW<br>H'00000000<br>H'E82004C8<br>32|
||Next1 source address register 11<br>N1SA_11<br>RW<br>H'00000000<br>H'E82004CC<br>32|
||Next1 destination address register 11<br>N1DA_11<br>RW<br>H'00000000<br>H'E82004D0<br>32|
||Next1 transaction byte register 11<br>N1TB_11<br>RW<br>H'00000000<br>H'E82004D4<br>32|
||Current source address register 11<br>CRSA_11<br>R<br>H'00000000<br>H'E82004D8<br>32|
||Current destination address register 11<br>CRDA_11<br>R<br>H'00000000<br>H'E82004DC<br>32|
||Current transaction byte register 11<br>CRTB_11<br>R<br>H'00000000<br>H'E82004E0<br>32|
||Channel status register 11<br>CHSTAT_11<br>R<br>H'00000000<br>H'E82004E4<br>32|
||Channel control register 11<br>CHCTRL_11<br>RW<br>H'00000000<br>H'E82004E8<br>32|
||Channel configuration register 11<br>CHCFG_11<br>RW<br>H'00000000<br>H'E82004EC<br>32|
||Channel interval register 11<br>CHITVL_11<br>RW<br>H'00000000<br>H'E82004F0<br>32|
||Channel extension register 11<br>CHEXT_11<br>RW<br>H'00000000<br>H'E82004F4<br>32|
||Next link address register 11<br>NXLA_11<br>RW<br>H'00000000<br>H'E82004F8<br>32|
||Current link address register 11<br>CRLA_11<br>R<br>H'00000000<br>H'E82004FC<br>32|

**Table 9.2 Register Configuration**

|**Table 9.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|12|Next0 source address register 12<br>N0SA_12<br>RW<br>H'00000000<br>H'E8200500<br>32|
||Next0 destination address register 12<br>N0DA_12<br>RW<br>H'00000000<br>H'E8200504<br>32|
||Next0 transaction byte register 12<br>N0TB_12<br>RW<br>H'00000000<br>H'E8200508<br>32|
||Next1 source address register 12<br>N1SA_12<br>RW<br>H'00000000<br>H'E820050C<br>32|
||Next1 destination address register 12<br>N1DA_12<br>RW<br>H'00000000<br>H'E8200510<br>32|
||Next1 transaction byte register 12<br>N1TB_12<br>RW<br>H'00000000<br>H'E8200514<br>32|
||Current source address register 12<br>CRSA_12<br>R<br>H'00000000<br>H'E8200518<br>32|
||Current destination address register 12<br>CRDA_12<br>R<br>H'00000000<br>H'E820051C<br>32|
||Current transaction byte register 12<br>CRTB_12<br>R<br>H'00000000<br>H'E8200520<br>32|
||Channel status register 12<br>CHSTAT_12<br>R<br>H'00000000<br>H'E8200524<br>32|
||Channel control register 12<br>CHCTRL_12<br>RW<br>H'00000000<br>H'E8200528<br>32|
||Channel configuration register 12<br>CHCFG_12<br>RW<br>H'00000000<br>H'E820052C<br>32|
||Channel interval register 12<br>CHITVL_12<br>RW<br>H'00000000<br>H'E8200530<br>32|
||Channel extension register 12<br>CHEXT_12<br>RW<br>H'00000000<br>H'E8200534<br>32|
||Next link address register 12<br>NXLA_12<br>RW<br>H'00000000<br>H'E8200538<br>32|
||Current link address register 12<br>CRLA_12<br>R<br>H'00000000<br>H'E820053C<br>32|
|13|Next0 source address register 13<br>N0SA_13<br>RW<br>H'00000000<br>H'E8200540<br>32|
||Next0 destination address register 13<br>N0DA_13<br>RW<br>H'00000000<br>H'E8200544<br>32|
||Next0 transaction byte register 13<br>N0TB_13<br>RW<br>H'00000000<br>H'E8200548<br>32|
||Next1 source address register 13<br>N1SA_13<br>RW<br>H'00000000<br>H'E820054C<br>32|
||Next1 destination address register 13<br>N1DA_13<br>RW<br>H'00000000<br>H'E8200550<br>32|
||Next1 transaction byte register 13<br>N1TB_13<br>RW<br>H'00000000<br>H'E8200554<br>32|
||Current source address register 13<br>CRSA_13<br>R<br>H'00000000<br>H'E8200558<br>32|
||Current destination address register 13<br>CRDA_13<br>R<br>H'00000000<br>H'E820055C<br>32|
||Current transaction byte register 13<br>CRTB_13<br>R<br>H'00000000<br>H'E8200560<br>32|
||Channel status register 13<br>CHSTAT_13<br>R<br>H'00000000<br>H'E8200564<br>32|
||Channel control register 13<br>CHCTRL_13<br>RW<br>H'00000000<br>H'E8200568<br>32|
||Channel configuration register 13<br>CHCFG_13<br>RW<br>H'00000000<br>H'E820056C<br>32|
||Channel interval register 13<br>CHITVL_13<br>RW<br>H'00000000<br>H'E8200570<br>32|
||Channel extension register 13<br>CHEXT_13<br>RW<br>H'00000000<br>H'E8200574<br>32|
||Next link address register 13<br>NXLA_13<br>RW<br>H'00000000<br>H'E8200578<br>32|
||Current link address register 13<br>CRLA_13<br>R<br>H'00000000<br>H'E820057C<br>32|

**Table 9.2 Register Configuration**

|**Table 9.2**|**Register Configuration**|
|---|---|
|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|14|Next0 source address register 14<br>N0SA_14<br>RW<br>H'00000000<br>H'E8200580<br>32|
||Next0 destination address register 14<br>N0DA_14<br>RW<br>H'00000000<br>H'E8200584<br>32|
||Next0 transaction byte register 14<br>N0TB_14<br>RW<br>H'00000000<br>H'E8200588<br>32|
||Next1 source address register 14<br>N1SA_14<br>RW<br>H'00000000<br>H'E820058C<br>32|
||Next1 destination address register 14<br>N1DA_14<br>RW<br>H'00000000<br>H'E8200590<br>32|
||Next1 transaction byte register 14<br>N1TB_14<br>RW<br>H'00000000<br>H'E8200594<br>32|
||Current source address register 14<br>CRSA_14<br>R<br>H'00000000<br>H'E8200598<br>32|
||Current destination address register 14<br>CRDA_14<br>R<br>H'00000000<br>H'E820059C<br>32|
||Current transaction byte register 14<br>CRTB_14<br>R<br>H'00000000<br>H'E82005A0<br>32|
||Channel status register 14<br>CHSTAT_14<br>R<br>H'00000000<br>H'E82005A4<br>32|
||Channel control register 14<br>CHCTRL_14<br>RW<br>H'00000000<br>H'E82005A8<br>32|
||Channel configuration register 14<br>CHCFG_14<br>RW<br>H'00000000<br>H'E82005AC<br>32|
||Channel interval register 14<br>CHITVL_14<br>RW<br>H'00000000<br>H'E82005B0<br>32|
||Channel extension register 14<br>CHEXT_14<br>RW<br>H'00000000<br>H'E82005B4<br>32|
||Next link address register 14<br>NXLA_14<br>RW<br>H'00000000<br>H'E82005B8<br>32|
||Current link address register 14<br>CRLA_14<br>R<br>H'00000000<br>H'E82005BC<br>32|
|15|Next0 source address register 15<br>N0SA_15<br>RW<br>H'00000000<br>H'E82005C0<br>32|
||Next0 destination address register 15<br>N0DA_15<br>RW<br>H'00000000<br>H'E82005C4<br>32|
||Next0 transaction byte register 15<br>N0TB_15<br>RW<br>H'00000000<br>H'E82005C8<br>32|
||Next1 source address register 15<br>N1SA_15<br>RW<br>H'00000000<br>H'E82005CC<br>32|
||Next1 destination address register 15<br>N1DA_15<br>RW<br>H'00000000<br>H'E82005D0<br>32|
||Next1 transaction byte register 15<br>N1TB_15<br>RW<br>H'00000000<br>H'E82005D4<br>32|
||Current source address register 15<br>CRSA_15<br>R<br>H'00000000<br>H'E82005D8<br>32|
||Current destination address register 15<br>CRDA_15<br>R<br>H'00000000<br>H'E82005DC<br>32|
||Current transaction byte register 15<br>CRTB_15<br>R<br>H'00000000<br>H'E82005E0<br>32|
||Channel status register 15<br>CHSTAT_15<br>R<br>H'00000000<br>H'E82005E4<br>32|
||Channel control register 15<br>CHCTRL_15<br>RW<br>H'00000000<br>H'E82005E8<br>32|
||Channel configuration register 15<br>CHCFG_15<br>RW<br>H'00000000<br>H'E82005EC<br>32|
||Channel interval register 15<br>CHITVL_15<br>RW<br>H'00000000<br>H'E82005F0<br>32|
||Channel extension register 15<br>CHEXT_15<br>RW<br>H'00000000<br>H'E82005F4<br>32|
||Next link address register 15<br>NXLA_15<br>RW<br>H'00000000<br>H'E82005F8<br>32|
||Current link address register 15<br>CRLA_15<br>R<br>H'00000000<br>H'E82005FC<br>32|
|Common<br>for 8 to 15|DMA control registers 8 to 15<br>DCTRL_8_15<br>R/W<br>H'00000000<br>H'E8200700<br>32|
||DMA status EN registers 8 to 15<br>DSTAT_EN_8_15<br>R<br>H'00000000<br>H'E8200710<br>32|
||DMA status ER registers 8 to 15<br>DSTAT_ER_8_15<br>R<br>H'00000000<br>H'E8200714<br>32|
||DMA status END registers 8 to 15<br>DSTAT_END_8_15<br>R<br>H'00000000<br>H'E8200718<br>32|
||DMA status TC registers 8 to 15<br>DSTAT_TC_8_15<br>R<br>H'00000000<br>H'E820071C<br>32|
||DMA status SUS registers 8 to 15<br>DSTAT_SUS_8_15<br>R<br>H'00000000<br>H'E8200720<br>32|
|0/1|DMA extended resource selector 0<br>DMARS0<br>R/W<br>H'00000000<br>H'FCFE1000<br>32|
|2/3|DMA extended resource selector 1<br>DMARS1<br>R/W<br>H'00000000<br>H'FCFE1004<br>32|
|4/5|DMA extended resource selector 2<br>DMARS2<br>R/W<br>H'00000000<br>H'FCFE1008<br>32|
|6/7|DMA extended resource selector 3<br>DMARS3<br>R/W<br>H'00000000<br>H'FCFE100C<br>32|
|8/9|DMA extended resource selector 4<br>DMARS4<br>R/W<br>H'00000000<br>H'FCFE1010<br>32|
|10/11|DMA extended resource selector 5<br>DMARS5<br>R/W<br>H'00000000<br>H'FCFE1014<br>32|
|12/13|DMA extended resource selector 6<br>DMARS6<br>R/W<br>H'00000000<br>H'FCFE1018<br>32|
|14/15|DMA extended resource selector 7<br>DMARS7<br>R/W<br>H'00000000<br>H'FCFE101C<br>32|

## 9.4.1 Next Source Address Register n (N0SA_n, N1SA_n)

This register sets the DMA transfer source address (32 bits) of DMA channel n (n = 0 to 15) which is to be executed next. N0SA_n is for the Next0 Register Set, and N1SA_n is for the Next1 Register Set.

In register mode, set this register set by using software. In link mode, the descriptor read data is automatically set in the Next0 Register Set.

These register set values are loaded to the Current Register Set and used for DMA transfer.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||SA||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||||SA||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|**Value**||**R/W**||**Description**||||||||||||
|31|to|0|SA|All|0|R/W||Source Address||||||||||||
|||||||||Sets the start||address|of the DMA||transfer source.|||||||

## 9.4.2 Next Destination Address Register n (N0DA_n, N1DA_n)

This register sets the DMA transfer destination address (32 bits) of DMA channel n (n = 0 to 15) which is to be executed next.

N0DA_n is for the Next0 Register Set, and N1DA_n is for the Next1 Register Set.

In register mode, set this register set by using software. In link mode, the descriptor read data is automatically set in the Next0 Register Set.

These register set values are loaded to the Current Register Set and used for DMA transfer.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||DA||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||||DA||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|**Value**||**R/W**||**Description**||||||||||||
|31|to|0|DA|All 0||R/W||Destination Address||||||||||||
|||||||||Sets the|start|address|of the DMA||transfer destination.|||||||

## 9.4.3 Next Transaction Byte Register n (N0TB_n, N1TB_n)

This register sets the total transfer byte count (DMA transaction) of DMA channel (n = 0 to 15) which is to be executed next.

N0TB_n is for the Next0 Register Set, and N1TB_n is for the Next1 Register Set.

In register mode, set this register set by using software. In link mode, the descriptor read data is automatically set in the Next0 Register Set.

These register set values are loaded to the Current Register Set and used for DMA transfer.

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||TB||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||||TB||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|**Value**||**R/W**||**Description**||||||||||||
|31|to|0|TB|All 0||R/W||Transaction Byte||||||||||||
|||||||||Sets the|total|transfer byte count.||||||||||
|||||||||Caution:|Do not start a DMA transaction|||||with 0|set in|this register.||||

## 9.4.4 Current Source Address Register (CRSA_n)

This register indicates the DMA transfer source address of DMA channel n (n = 0 to 15).

The values are loaded from the Next0/1 Register Set in register mode or from the descriptor read data in link mode. You cannot write to this register set using software.

||||Bit:|31|30|29|28|27<br>26<br>25<br>24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CRSA||||||||
||||Initial value:|0|0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|R|R|R|R|
||||Bit:|15|14|13|12|11<br>10<br>9<br>8<br>7|6|5|4|3|2|1|0|
|||||||||CRSA||||||||
||||Initial value:|0|0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|R|R|R|R|
|||||**Initial**||||||||||||
|**Bit**|||**Bit Name**|**Value**||**R/W**||**Description**||||||||
|31|to|0|CRSA|All 0||R||Current Source Address Register||||||||
|||||||||Indicates the read address of the next DMA transaction.||||||||
|||||||||The value automatically increments during the|||DMA transaction.|||||
|||||||||(The value is fixed when 1 is set in SAD of the CHCFG_n register.)||||||||
|||||||||The value increments when a read transfer starts.||||||||
|||||||||Read this register after DMA stops (0 is set in EN of the CHSTAT_n||||||register). (Any value||
|||||||||obtained during the DMA operation should be|||handled as a reference value.)|||||

## 9.4.5 Current Destination Address Register (CRDA_n)

This register indicates the DMA transfer destination address of DMA channel n (n = 0 to 15).

The values are loaded from the Next0/1 Register Set in register mode or from the descriptor read data in link mode. You cannot write to this register set using software.

**==> picture [484 x 224] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>CRDA<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>CRDA<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 0 CRDA All 0 R Current Destination Address Register<br>Indicates the write address of the next DMA transaction.<br>The value automatically increments during the DMA transaction. (The value is fixed when<br>1 is set in DAD of the CHCFG_n register.)<br>The value increments when a write transfer starts.<br>Read this register after DMA stops (0 is set in EN of the CHSTAT_n register). (Any value<br>obtained during the DMA operation should be handled as a reference value.)<br>**----- End of picture text -----**<br>

## 9.4.6 Current Transaction Byte Register (CRTB_n)

This register indicates the total transfer byte count of DMA channel n (n = 0 to 15). The value of this register becomes 0 when the transaction ends.

The values are loaded from the Next0/1 Register Set in register mode or from the descriptor read data in link mode. You cannot write to this register set using software.

||||31<br>Bit:|31<br>Bit:|30|29|28|27<br>26<br>25<br>24<br>23|27<br>26<br>25<br>24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||CRTB||||||||
||||0<br>Initial value:||0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|0|0|
||||R<br>R/W:||R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R|R|R|
||||15<br>Bit:||14|13|12|11<br>10<br>9<br>8|7|6|5|4|3|2|1|0|
||||||||||CRTB||||||||
||||0<br>Initial value:||0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|0|0|
||||R<br>R/W:||R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R|R|R|
|||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**|**Value**||**R/W**||**Description**|||||||||
|31|to|0|CRTB|All 0||R||Current Transaction Byte Register|||||||||
|||||||||Indicates the remaining|transfer byte count of|||the currently executed DMA||||transaction.|
|||||||||The value automatically|decrements during the DMA transaction.||||||||
|||||||||The value decrements when a write transfer is completed.|||||||||
|||||||||Read this register after DMA stops||(0 is set in||EN of the CHSTAT_n|||register). (Any value||
|||||||||obtained during the DMA operation||should be||handled as a reference value.)|||||

## 9.4.7 Channel Status Register n (CHSTAT_n)

This register indicates the status of DMA channel n (n = 0 to 15).

||||Bit:||31|||30|29||28|27<br>26<br>25<br>24<br>23<br>22|21|20|19|18|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|||-|-||-|-<br>-<br>-<br>-<br>-<br>-|-|-|-||-|-|INTMSK||
||||Initial value:||0|||0|0||0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||0|0||
||||R/W:||R|||R|R||R|R<br>R<br>R<br>R<br>R<br>R|R|R|R|R||R|R||
||||Bit:||15|||14|13||12|11<br>10<br>9<br>8<br>7<br>6|5|4|3|2||1|0||
||||||-|||-|-||-|MODE<br>DER<br>DW<br>DL<br>SR<br>TC|END|ER|SUS|TACT||RQST|EN||
||||Initial value:||0|||0|0||0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||0|0||
||||R/W:||R|||R|R||R|R<br>R<br>R<br>R<br>R<br>R|R|R|R|R||R|R||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**|||**Description**|||||||||
|31|to|17|—|||All||0|R|||Reserved area. Set 0. A read operation results||in 0 being read.|||||||
|16|||INTMSK|||0|||R|||Indicates the temporary mask status of the DMA transfer end interrupt.|||||||||
|||||||||||||1: Masked temporarily|||||||||
|||||||||||||0: Unmasked temporarily|||||||||
|||||||||||||Set condition(s):|||||||||
|||||||||||||When SETINTMSK (CHCTRL_n) is set to 1|||||||||
|||||||||||||Reset condition(s):|||||||||
|||||||||||||When CLRINTMSK (CHCTRL_n) is set to 1|||||||||
|||||||||||||When SWRST (CHCTRL_n) is set to 1|||||||||
|15|to|12|—|||All||0|R|||Reserved area. Set 0. A read operation results||in 0 being read.|||||||
|11|||MODE|||0|||R|||DMA Mode|||||||||
|||||||||||||Indicates the DMA mode. It corresponds to the||value set in the|||DMS bit of the CHCFG_n||||
|||||||||||||register.|||||||||
|||||||||||||0: Register mode|||||||||
|||||||||||||1: Link mode|||||||||
|10|||DER|||0|||R|||Descriptor Error|||||||||
|||||||||||||Indicates whether the link valid value of the read descriptor is invalid (LV = 0) (this is not|||||||||
|||||||||||||dependent on the DIM level of the descriptor). If a descriptor error has occurred, the|||||||||
|||||||||||||transfer is stopped but no DMA error interrupt occurs.|||||||||
|||||||||||||0: Descriptor Error not detected|||||||||
|||||||||||||1: Descriptor Error detected|||||||||
|||||||||||||Set condition(s):|||||||||
|||||||||||||When the LV value loaded with the descriptor in link mode is|||||0||||
|||||||||||||Reset condition(s):|||||||||
|||||||||||||When SWRST (CHCTRL_n) is set to 1|||||||||
|9|||DW|||0|||R|||Descriptor WriteBack|||||||||
|||||||||||||Indicates the descriptor writeback status. The bit maintains 1 if|||||a bus error is received||||
|||||||||||||during descriptor writeback.|||||||||
|||||||||||||0: Operation other than writeback is being performed|||for the|header in link mode.|||||
|||||||||||||1: (ER = 0)|||||||||
|||||||||||||Writeback is being performed for the header||in link|mode.||||||
|||||||||||||(ER = 1)|||||||||
|||||||||||||A bus error occurs during writeback for the header|||in link mode.||||||
|||||||||||||Set condition(s):|||||||||
|||||||||||||When header writeback in link mode starts|||||||||
|||||||||||||Reset condition(s):|||||||||
|||||||||||||When header writeback in link mode ends with an OK response|||||||||
|||||||||||||When SWRST (CHCTRL_n) is set to 1|||||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|8|DL|0|R|Descriptor Load|
|||||Indicates whether the descriptor is being loaded. The bit maintains 1 if a bus error is|
|||||received during descriptor load.|
|||||0: Operation other than descriptor load|
|||||1: (ER = 0)|
|||||Descriptor load is in progress in link mode.|
|||||(ER = 1)|
|||||A bus error occurs during descriptor load in link mode.|
|||||Set condition(s):|
|||||When descriptor load in link mode starts|
|||||Reset condition(s):|
|||||When descriptor load in link mode ends with an OK response|
|||||When SWRST (CHCTRL_n) is set to 1|
|7|SR|0|R|Selected Register Set|
|||||Indicates the register set currently selected in register mode.|
|||||0: Next0 Register Set|
|||||1: Next1 Register Set|
|||||Set condition(s):|
|||||When RSEL (CHCFG_n) is set to 1|
|||||Reset condition(s):|
|||||When RSEL (CHCFG_n) is set to 0|
|6|TC|0|R|Terminal Count|
|||||Indicates whether the DMA transaction is completed.|
|||||0: DMA transfer not completed|
|||||1: DMA transfer completed|
|||||Set condition(s):|
|||||When data equivalent to the total transfer byte count set in the CRTB register has been|
|||||transferred in register mode|
|||||When data equivalent to the total transfer byte count set in the CRTB register has been|
|||||transferred in link mode, with 1 set in WBD of the descriptor header|
|||||When descriptor writeback is completed in link mode, with 0 set in WBD of the|
|||||descriptor header|
|||||Clear condition(s):|
|||||When the CLRTC (CHCTRL_n) bit is set to 1|
|||||When the SWRST (CHCTRL_n) bit is set to 1|
|5|END|0|R|DMAEND Interrupted|
|||||Indicates whether the DMA transaction is completed and whether the DMA transfer end|
|||||interrupt has occurred.|
|||||0: DMA transfer not completed|
|||||1: DMA transfer completed|
|||||Set condition(s):|
|||||When one of the set conditions for the TC bit is met and 0 is set in DEM of the|
|||||CHCFG_n register|
|||||When the descriptor is read in link mode and both LV of the header and DIM are set to 0|
|||||Clear condition(s):|
|||||When CLREND (CHCTRL_n) is set to 1|
|||||When SWRST (CHCTRL_n) is set to 1|
|4|ER|0|R|Error bit|
|||||Indicates that a DMA error interrupt has occurred because an error response has been|
|||||received from the transfer source or destination and a bus error has occurred during the|
|||||DMA transfer.|
|||||0: No bus error has occurred|
|||||1: A DMA error interrupt has occurred due to a bus error|
|||||Set condition(s):|
|||||When a bus error has occurred during a bus cycle|
|||||Clear condition(s):|
|||||When SWRST (CHCTRL_n) is set to 1|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|3|SUS|0|R|Suspend|
|||||Indicates whether the channel is suspended.|
|||||0: Channel_n not suspended|
|||||1: Channel_n suspended|
|||||Set condition(s):|
|||||When SETSUS (CHCTRL_n) is set to 1 during a DMA transfer on Channel_n, creating|
|||||a SUSPEND status internally|
|||||Clear condition(s):|
|||||When CLRSUS (CHCTRL_n) is set to 1|
|||||When CLREN (CHCTRL_n) is set to 1|
|2|TACT|0|R|Transaction Active|
|||||Indicates whether the DMAC is active. This bit is intended to check that the channel is|
|||||completely inactive.|
|||||0: DMA on Channel_n inactive|
|||||1: DMA on Channel_n active|
|||||Set condition(s):|
|||||When a DMA transaction starts on Channel_n|
|||||Clear condition(s):|
|||||When a DMA transaction is completed|
|1|RQST|0|R|Request|
|||||Indicates whether a transfer request is being received.|
|||||0: DMA transfer request not being received|
|||||1: DMA transfer request being received|
|||||Set condition(s):|
|||||When the STG bit (CHCTRL_n) is set to 1 (auto request)|
|||||When a transfer request is received from the DMA request source set in the CHCFG_n|
|||||register|
|||||Clear condition(s):|
|||||When SWRST (CHCTRL_n) is set to 1|
|||||When CLRRQ (CHCTRL_n) is set to 1|
|||||When a transfer is executed on the side specified by REQD (CHCFG_n) in single|
|||||transfer mode (TM = 0).|
|||||When all DMA transactions are completed in register mode (the transaction ends with|
|||||REN set to 0)|
|||||When the DMA transfer of the last descriptor (LE = 1) is completed in link mode|
|||||When descriptor read stops (LV = 0) in link mode|
|||||When a DMA transaction is completed in link mode while DEM is set to 0|
|||||When a bus error is received due to an error response|
|0|EN|0|R|Enable|
|||||Indicates whether the operation of DMA channel n is enabled or disabled.|
|||||0: Operation disabled|
|||||1: Operation enabled|
|||||Set condition(s):|
|||||When SETEN (CHCTRL_n) is set to 1|
|||||Clear condition(s):|
|||||When SWRST (CHCTRL_n) is set to 1|
|||||When CLREN (CHCTRL_n) is set to 1|
|||||When a bus error is received due to an error response during the transfer|
|||||When all DMA transactions are completed in register mode (the transaction ends with|
|||||REN set to 0)|
|||||When the DMA transfer of the last descriptor (LE = 1) is completed in link mode|
|||||(writeback when WBD is set to 0)|
|||||When descriptor read stops (LV = 0) in link mode|

<Caution> If the ER bit is set to 1 for any transfer, the whole transfer should be handled as invalid.

To suspend a DMA transaction, mask or clear the transfer request or clear the Enable bit (for the procedure, see section 9.7.11 (2) Transfer Stop).

If you make a transfer request from an on-chip peripheral module or the external DREQ input concurrently with an auto request (by setting 1 in the STG bit) for the same one channel, you cannot identify the trigger source that takes effect. Make sure that only one of these transfer requests is used in the system.

When transfer is requested by an auto request, wait for the last requested DMA transfer to complete (use the Current Register or other data to check the status) before setting the STG bit for the next transfer request.

## 9.4.8 Channel Control Register n (CHCTRL_n)

This register controls the DMA transfer operation on DMA channel n (n = 0 to 15).

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||CLRINT|SETINT|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|MSK|MSK|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|CLR<br>SUS|SET<br>SUS|-|CLRTC|CLR<br>END|CLRRQ|SWRST|STG|CLREN|SETEN|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R/W|R/W|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|18|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|17|||CLRINTMSK|0|R/W|When this bit is set to 1, the mask of the DMA transfer end interrupt is cleared. Also,|
|||||||the INTMSK bit of the CHSTAT_n register is set to 0.|
|||||||If the mask is cleared when 1 is set in both LVINT of the DCTRL register and END of|
|||||||the CHSTAT_n register, the DMA transfer end interrupt becomes active. (It does not|
|||||||become active when 0 is set in LVINT.)|
|||||||A read operation results in 0 being read.|
|||||||1: Clears the mask set by SETINTMSK.|
|||||||0: Does not affect the operation.|
|16|||SETINTMSK|0|R/W|When this bit is set to 1, the DMA transfer end interrupt is temporarily masked. Also,|
|||||||the INTMSK bit of the CHSTAT_n register is set to 1.|
|||||||A read operation results in 0 being read.|
|||||||1: Masks the DMA transfer end interrupt.|
|||||||0: Does not affect the operation.|
|15|to|10|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|9|||CLRSUS|0|R/W|Clear Suspend|
|||||||Clears the suspend status. Setting this bit to 1 when 1 is set in SUS of the CHSTAT_n|
|||||||register can clear the suspend status.|
|||||||An attempt to read this bit results in 0 being read.|
|||||||1: Clears the suspend status of the current DMA transfer.|
|||||||0: Does not affect the operation.|
|8|||SETSUS|0|R/W|Set Suspend|
|||||||Suspends the current DMA transfer. Setting this bit to 1 when 1 is set in EN of the|
|||||||CHSTAT_n register can suspend the current DMA transfer.|
|||||||An attempt to read this bit results in 0 being read.|
|||||||1: Suspends the current DMA transfer.|
|||||||0: Does not affect the operation.|
|7|||—|0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|6|||CLRTC|0|R/W|Clear TC bit|
|||||||Setting this bit to 1 can clear the TC bit of the CHSTAT_n register. An attempt to read|
|||||||this bit results in 0 being read.|
|||||||1: Clears the TC bit.|
|||||||0: Does not affect the operation.|
|5|||CLREND|0|R/W|Clear End bit|
|||||||Setting this bit to 1 can clear the END bit of the CHSTAT_n register.|
|||||||Also, the DMA transfer end interrupt is cleared.|
|||||||An attempt to read this bit results in 0 being read.|
|||||||1: Clears the END bit.|
|||||||0: Does not affect the operation.|
|4|||CLRRQ|0|R/W|Clear Request bit|
|||||||Setting this bit to 1 can clear the RQST bit of the CHSTAT_n register.|
|||||||An attempt to read this bit results in 0 being read.|
|||||||1: Clears the RQST bit.|
|||||||0: Does not affect the operation.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|3|SWRST|0|R/W|Software Reset|
|||||Setting this bit to 1 can clear the channel status register (CHSTAT_n). When setting|
|||||this bit to 1, make sure that both the EN bit and TACT bit are set to 0.|
|||||An attempt to read this bit results in 0 being read.|
|||||1: Resets the channel status register.|
|||||0: Does not affect the operation.|
|2|STG|0|R/W|Software Trigger|
|||||Setting this bit to 1 sets an auto request. If this bit is set at the same time the SWRST|
|||||bit is set, the clear operation by the SWRST bit takes precedence.|
|||||An attempt to read this bit results in 0 being read.|
|||||1: Sets a transfer request triggered by an auto request (sets 1 in the RQST bit).|
|||||0: Does not affect the operation.|
|1|CLREN|0|R/W|Clear Enable|
|||||Setting this bit to 1 can clear the EN bit (for details, see section9.7.11 (2) Transfer|
|||||Stop).|
|||||An attempt to read this bit results in 0 being read.|
|||||1: Stops the DMA transfer (clears the EN bit).|
|||||0: Does not affect the operation.|
|0|SETEN|0|R/W|Set Enable|
|||||Enables a DMA transfer on DMA channel n. If this bit is set at the same time the|
|||||SWRST bit is set, the clear operation by the SWRST bit takes precedence and the|
|||||transfer does not start.|
|||||An attempt to read this bit results in 0 being read.|
|||||1: Enables a DMA transfer (sets 1 in the EN bit).|
|||||0: Does not affect the operation.|

## 9.4.9 Channel Configuration Register n (CHCFG_n)

This register controls the DMA transfer operation on DMA channel n (n = 0 to 15).

|||Bit:||31|30|29|28<br>27<br>26<br>25<br>24<br>23<br>22<br>21|20|19||18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||DMS|REN|RSW|RSEL<br>SBE<br>-<br>-<br>DEM<br>-<br>TM<br>DAD|SAD|||DDS[3:0]||||
|||Initial value:||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0|0||0|0|0||
|||R/W:||R/W|R/W|R/W|R/W<br>R/W<br>R<br>R<br>R/W<br>R<br>R/W<br>R/W|R/W|R/W|R/W||R/W|R/W||
|||Bit:||15|14|13|12<br>11<br>10<br>9<br>8<br>7<br>6<br>5|4|3||2|1|0||
||||||SDS[3:0]||-<br>-<br>LVL<br>HIEN<br>AM[2:0]|LOEN|REQD|||SEL[2:0]|||
|||Initial value:||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0|0||0|0|0||
|||R/W:||R/W|R/W|R/W|R/W<br>R<br>R/W<br>R/W<br>R/W<br>R<br>R/W<br>R/W|R/W|R/W|R/W||R/W|R/W||
|||||**Initial**|||||||||||
|**Bit**||**Bit Name**||**Value**||**R/W**|**Description**||||||||
|31||DMS||0||R/W|DMA Mode Select||||||||
||||||||Sets the DMA mode.||||||||
||||||||0: Register mode (initial value)||||||||
||||||||1: Link mode||||||||
|30||REN||0||R/W|Register Set Enable||||||||
||||||||After a DMA transaction is completed, DMA transfers are continued using the Next Register||||||||
||||||||Set selected by RSEL. This bit is valid only in register mode.||||||||
||||||||0: Does not continue DMA transfers.||||||||
||||||||1: Continues DMA transfers.||||||||
||||||||Set condition(s):||||||||
||||||||When 1 is written to this bit||||||||
||||||||Clear condition(s):||||||||
||||||||When 0 is written to this bit||||||||
||||||||When a DMA transaction is completed, with REN set to 1||||||||
|29||RSW||0||R/W|Register Select Switch||||||||
||||||||Inverts RSEL automatically after a DMA transaction is completed. This bit is valid only in||||||||
||||||||register mode.||||||||
||||||||0: Does not invert RSEL automatically after a DMA transaction (initial value).||||||||
||||||||1: Inverts RSEL automatically after a DMA transaction.||||||||
|28||RSEL||0||R/W|Register Set Select||||||||
||||||||Selects the Next Register Set to be executed next. This||bit is valid only in register mode.||||||
||||||||When RSW is set to 1, this bit is inverted automatically when a DMA transaction is||||||||
||||||||completed.||||||||
||||||||0: Executes the Next0 Register Set (initial value).||||||||
||||||||1: Executes the Next1 Register Set.||||||||
||||||||Transition condition(s):||||||||
||||||||When a DMA transaction is completed, with RSW set||to 1||||||
|27||SBE||0||R/W|Sweep Buffer Enable||||||||
||||||||Selects whether to sweep (write) the data already read into the buffer and stop the DMA||||||||
||||||||transfer if the Enable bit is cleared to 0 during a DMA transaction.||||||||
||||||||The sweep mode is available only when REQD is set to||0.||||||
||||||||0: Stops the DMA transfer without sweeping the buffer (initial value).||||||||
||||||||1: Stops the DMA transfer after sweeping the buffer.||||||||
|26,|25|—||0||R|Reserved area. Set 0. A read operation results in|0 being read.|||||||
|24||DEM||0||R/W|DMA Transfer End Interrupt Mask||||||||
||||||||Masks the DMA transfer end interrupt for register|mode|transfer.||||||
||||||||If 1 is set in this bit when a DMA transfer end interrupt is output,||||the DMA transfer end||||
||||||||interrupt signal is not asserted. In this case, DEM|is cleared to||0|automatically.||||
||||||||0: Does not mask the DMA transfer end interrupt|(initial|value).||||||
||||||||1: Masks the DMA transfer end interrupt.||||||||
||||||||Clear condition(s):||||||||
||||||||When a DMA transaction is completed with DEM set to 1||||||||
|23||—||0||R|Reserved area. Set 0. A read operation results in|0 being read.|||||||

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**|**Description**|
|---|---|
|22<br>TM<br>0<br>R/W|Transfer Mode<br>Sets the DMA transfer mode.<br>0: Single transfer mode (initial value)<br>1: Block transfer mode|
|21<br>DAD<br>0<br>R/W|Sets the destination address counting direction of DMA channel n.<br>0: Increment (initial value)<br>1: Fixed|
|20<br>SAD<br>0<br>R/W|Sets the source address counting direction of DMA channel n.<br>0: Increment (initial value)<br>1: Fixed|
|19 to 16<br>DDS<br>[3:0]<br>0000<br>R/W|Destination Data Size<br>Sets the DMA transfer size of the transfer destination.<br>**Value**<br>**Size**<br>**Remark**<br>0000<br>8 bits<br>Initial value<br>0001<br>16 bits<br>0010<br>32 bits<br>0011<br>64 bits<br>0100<br>128 bits<br>0101<br>256 bits<br>0110<br>512 bits<br>0111<br>1024 bits<br>Other than the above<br><br>Setting prohibited|
|15 to 12<br>SDS<br>[3:0]<br>0000<br>R/W|Source Data Size<br>Sets the DMA transfer size of the transfer source.<br>**Value**<br>**Size**<br>**Remark**<br>0000<br>8 bits<br>Initial value<br>0001<br>16 bits<br>0010<br>32 bits<br>0011<br>64 bits<br>0100<br>128 bits<br>0101<br>256 bits<br>0110<br>512 bits<br>0111<br>1024 bits<br>Other than the above<br><br>Setting prohibited|
|11<br>—<br>0<br>R|Reserved area. Set 0. A read operation results in 0 being read.|
|10 to 8<br>AM<br>[2:0]<br>000<br>R/W|ACK Mode<br>Sets the DMAACK output mode.<br>000: (initial value)<br>001: Level mode (active until the transfer request from an on-chip peripheral module or the<br>external DREQ input becomes inactive)<br>01x: Bus cycle mode (active while the DMA transfer is in a bus cycle)<br>1xx: DMAACK not to be output (this setting should be made when an auto request is made<br>by STG (CHCTRL_n))|
|7<br>—<br>0<br>R|Reserved area. Set 0. A read operation results in 0 being read.|
|6<br>LVL<br>0<br>R/W|Level<br>Selects whether to detect a DMA request based on the level or edge of the signal.<br>0: Detects based on the edge (initial value).<br>1: Detects based on the level.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|5|HIEN|0|R/W|High Enable|
|||||Selects whether to detect a DMA request using the High level or rising edge of the signal.|
|||||When LVL = 0:|
|||||HIEN = 1: Detects a request in response to the rising edge of the signal.|
|||||HIEN = 0: Does not detect a request in response to the rising edge of the signal (initial|
|||||value).|
|||||When LVL = 1:|
|||||HIEN = 1: Detects a request when the signal is at the High level.|
|||||HIEN = 0: Does not detect a request even when the signal is at the High level (initial value).|
|4|LOEN|0|R/W|Low Enable|
|||||Selects whether to detect a DMA request using the Low level or falling edge of the signal.|
|||||When LVL = 0:|
|||||LOEN = 1: Detects a request in response to the falling edge of the signal.|
|||||LOEN = 0: Does not detect a request in response to the falling edge of the signal (initial|
|||||value).|
|||||When LVL = 1:|
|||||LOEN = 1: Detects a request when the signal is at the Low level.|
|||||LOEN = 0: Does not detect a request even when the signal is at the Low level (initial value).|
|3|REQD|0|R/W|Request Direction|
|||||Selects whether DMAREQ selected by the SEL bit is the source or destination. This bit is|
|||||also used to define when DMAACK is to become active.|
|||||0: Source; DMAACK is to become active when read (initial value).|
|||||1: Destination; DMAACK is to become active when written.|
|2 to 0|SEL[2:0]|000|R/W|These bits are used to set a DMAC channel. Set one of the following values so that the|
|||||channel set by the SEL bits matches the CHCFG_n channel.|
|||||000: CH0/CH8|
|||||001: CH1/CH9|
|||||010: CH2/CH10|
|||||011: CH3/CH11|
|||||100: CH4/CH12|
|||||101: CH5/CH13|
|||||110: CH6/CH14|
|||||111: CH7/CH15|

## 9.4.10 Channel Interval Register n (CHITVL_n)

This register sets the transfer interval for DMA channel n (n = 0 to 15).

For details, see section 9.7.9, Interval Count Function .

||||Bit:||31|30|29||28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|-||-|-|-|-|-|-|-|-|-|-|-|-|-||
||||Initial value:||0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R||R|R|R|R|R|R|R|R|R|R|R|R|R||
||||Bit:||15|14|13||12|11|10|9|8|7|6|5|4|3|2|1|0||
||||||||||||||ITVL||||||||||
||||Initial value:||0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
||||||**Initial**||||||||||||||||||
|**Bit**|||**Bit Name**||**Value**||**R/W**||**Description**||||||||||||||
|31|to|16|—||All 0||R||Reserved area. Set 0. A read operation results||||||||in 0 being read.||||||
|15|to|0|ITVL||All 0||R/W||Sets the channel transfer interval.||||||||||||||

## 9.4.11 Channel Extension Register n (CHEXT_n)

This is an extension register for DMA channel n (n = 0 to 15).

|Bit:|31|30|29|28|27|26||25|24|23|22|21|20|19|18||17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-||-|-|-|-|-|-|-|-||-|-|
|Initial value:|0|0|0|0|0|0||0|0|0|0|0|0|0|0||0|0|
|R/W:|R|R|R|R|R|R||R|R|R|R|R|R|R|R||R|R|
|Bit:|15|14|13|12|11|10||9|8|7|6|5|4|3|2||1|0|
|||DCA[3:0]|||-||DPR[2:0]||||SCA[3:0]|||-||SPR[2:0]|||
|Initial value:|0|0|0|0|0|0||0|0|0|0|0|0|0|0||0|0|
|R/W:|R/W|R/W|R/W|R/W|R|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R|R/W||R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 16|—|All 0|R|Set 0. A read operation results in 0 being read.|
|15 to 12|DCA[3:0]|0000|R/W|Destination CACHE|
|||||Sets the value to be output to AWCACHE[3:0] for DMA write transfer.|
|||||See Note 1 below.|
|11|—|0|R|Set 0. A read operation results in 0 being read.|
|10 to 8|DPR[2:0]|000|R/W|Destination PROT|
|||||Sets the value to be output to AWPROT[2:0] for DMA write transfer.|
|||||See Note 2 below.|
|7 to 4|SCA[3:0]|0000|R/W|Source CACHE|
|||||Sets the value to be output to ARCACHE[3:0] for DMA read transfer.|
|||||See Note 1 below.|
|3|—|0|R|Set 0. A read operation results in 0 being read.|
|2 to 0|SPR[2:0]|000|R/W|Source PROT|
|||||Sets the value to be output to ARPROT[2:0] for DMA read transfer.|
|||||See Note 2 below.|

Note 1. Cache support: Bits SCA and DCA are used to change the settings.

When the transfer destination or source is not in the external bus space, set these bits to 0000.

Even when the transfer destination or source is in the external bus space but the secondary cache is not in use, set these bits to 0000. In this case, the DACK0 output and TEND0 output are issued in response to the DREQ0 transfer request. When the secondary cache is in use in the external bus space, set CACHE[3:0].

Note 2. Protection unit support: Bits SPR and DPR are used to change the settings.

For the setting value, see AMBA AXI Protocol Specification from Arm Limited.

## 9.4.12 Next Link Address Register n (NXLA_n)

This is a 32-bit register that sets the link address of DMA channel n (n = 0 to 15). For information about the link mode, see section 9.6.3, Link Mode .

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||NXLA|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||NXLA|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||||**Bit**|**Initial**||||||||||||||||
|**Bit**|||**Name**|**Value**||**R/W**|**Description**|||||||||||||
|31|to|0|NXLA|All 0||R/W|Sets|a link|address. The||low-order 2||bits are|masked with||0s. Only an||address aligned with a||
||||||||4-byte boundary|||can be|set.|||||||||

## 9.4.13 Current Link Address Register n (CRLA_n)

This is a 32-bit register that indicates the link address of DMA channel n (n = 0 to 15). For information about the link mode, see section 9.6.3, Link Mode .

||||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||CRLA|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||CRLA|||||||||
||||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||||**Bit**|**Initial**||||||||||||||||
|**Bit**|||**Name**|**Value**||**R/W**|**Description**|||||||||||||
|31|to|0|CRLA|All 0||R|Indicates||the address of the|||currently|executed||descriptor.|||||

## 9.4.14 DMA Control Register (DCTRL_0_7, DCTRL_8_15)

This register sets the transfer type for descriptor access and the arbitration between channels. (DCTRL_0_7 is common for channels 0 to 7 and DCTRL_8_15 is common for channels 8 to 15.)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||LWCA|||-||LWPR|||LDCA|||-||LDPR||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|LVINT|PR|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|28|LWCA|0000|R/W|Link WriteBack CACHE|
|||||||Sets the value to be output to AWCACHE[3:0] during descriptor writeback in link mode.|
|||||||For the setting value, see Note in section 9.4.11, Channel Extension Register n|
|||||||(CHEXT_n).|
|27|||—|0|R|Reserved area. Set 0. The initial value is 0.|
|26|to|24|LWPR|000|R/W|Link WriteBack PROT|
|||||||Sets the value to be output to AWPROT[2:0] during descriptor writeback in link mode.|
|||||||For the setting value, see AMBA AXI Protocol Specification from Arm Limited.|
|23|to|20|LDCA|0000|R/W|Link Descriptor CACHE|
|||||||Sets the value to be output to ARCACHE[3:0] during descriptor load in link mode. For the|
|||||||setting value, see Note in section 9.4.11, Channel Extension Register n (CHEXT_n).|
|19|||—|0|R|Reserved area. Set 0. The initial value is 0.|
|18|to|16|LDPR|000|R/W|Link Descriptor PROT|
|||||||Sets the value to be output to ARPROT[2:0] during descriptor load in link mode.|
|||||||For the setting value, see AMBA AXI Protocol Specification from Arm Limited.|
|15|to|2|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|1|||LVINT|0|R/W|Sets whether to use pulse output or level output for the DMA transfer end interrupt and|
|||||||DMA error interrupt. Set pulse output for this product.|
|||||||0: Pulse output (initial value)|
|||||||1: Level output|
|0|||PR|0|R/W|Sets the transfer priority control mode between channels (see section 9.7.2, Priority|
|||||||Control for DMA Channels.|
|||||||0: Fixed priority mode (initial value)|
|||||||1: Round robin mode|

## 9.4.15 DMA Status EN Register (DSTAT_EN_0_7)

This register indicates the EN bit status of the CHSTAT_n register (n = 0 to 7). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|EN7|EN6|EN5|EN4|EN3|EN2|EN1|EN0|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||EN7|0|R|Indicates the EN bit status of DMA channel 7.|
|6|||EN6|0|R|Indicates the EN bit status of DMA channel 6.|
|5|||EN5|0|R|Indicates the EN bit status of DMA channel 5.|
|4|||EN4|0|R|Indicates the EN bit status of DMA channel 4.|
|3|||EN3|0|R|Indicates the EN bit status of DMA channel 3.|
|2|||EN2|0|R|Indicates the EN bit status of DMA channel 2.|
|1|||EN1|0|R|Indicates the EN bit status of DMA channel 1.|
|0|||EN0|0|R|Indicates the EN bit status of DMA channel 0.|

## 9.4.16 DMA Status EN Register (DSTAT_EN_8_15)

This register indicates the EN bit status of the CHSTAT_n register (n = 8 to 15). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|EN15|EN14|EN13|EN12|EN11|EN10|EN9|EN8|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||EN15|0|R|Indicates the EN bit status of DMA channel 15.|
|6|||EN14|0|R|Indicates the EN bit status of DMA channel 14.|
|5|||EN13|0|R|Indicates the EN bit status of DMA channel 13.|
|4|||EN12|0|R|Indicates the EN bit status of DMA channel 12.|
|3|||EN11|0|R|Indicates the EN bit status of DMA channel 11.|
|2|||EN10|0|R|Indicates the EN bit status of DMA channel 10.|
|1|||EN9|0|R|Indicates the EN bit status of DMA channel 9.|
|0|||EN8|0|R|Indicates the EN bit status of DMA channel 8.|

## 9.4.17 DMA Status ER Register (DSTAT_ER_0_7)

This register indicates the ER bit status of the CHSTAT_n register (n = 0 to 7). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|ER7|ER6|ER5|ER4|ER3|ER2|ER1|ER0|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||ER7|0|R|Indicates the ER bit status of DMA channel 7.|
|6|||ER6|0|R|Indicates the ER bit status of DMA channel 6.|
|5|||ER5|0|R|Indicates the ER bit status of DMA channel 5.|
|4|||ER4|0|R|Indicates the ER bit status of DMA channel 4.|
|3|||ER3|0|R|Indicates the ER bit status of DMA channel 3.|
|2|||ER2|0|R|Indicates the ER bit status of DMA channel 2.|
|1|||ER1|0|R|Indicates the ER bit status of DMA channel 1.|
|0|||ER0|0|R|Indicates the ER bit status of DMA channel 0.|

## 9.4.18 DMA Status ER Register (DSTAT_ER_8_15)

This register indicates the ER bit status of the CHSTAT_n register (n = 8 to 15). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|ER15|ER14|ER13|ER12|ER11|ER10|ER9|ER8|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||ER15|0|R|Indicates the ER bit status of DMA channel 15.|
|6|||ER14|0|R|Indicates the ER bit status of DMA channel 14.|
|5|||ER13|0|R|Indicates the ER bit status of DMA channel 13.|
|4|||ER12|0|R|Indicates the ER bit status of DMA channel 12.|
|3|||ER11|0|R|Indicates the ER bit status of DMA channel 11.|
|2|||ER10|0|R|Indicates the ER bit status of DMA channel 10.|
|1|||ER9|0|R|Indicates the ER bit status of DMA channel 9.|
|0|||ER8|0|R|Indicates the ER bit status of DMA channel 8.|

## 9.4.19 DMA Status END Register (DSTAT_END_0_7)

This register indicates the END bit status of the CHSTAT_n register (n = 0 to 7). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|END7|END6|END5|END4|END3|END2|END1|END0|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||END7|0|R|Indicates the END bit status of DMA channel 7.|
|6|||END6|0|R|Indicates the END bit status of DMA channel 6.|
|5|||END5|0|R|Indicates the END bit status of DMA channel 5.|
|4|||END4|0|R|Indicates the END bit status of DMA channel 4.|
|3|||END3|0|R|Indicates the END bit status of DMA channel 3.|
|2|||END2|0|R|Indicates the END bit status of DMA channel 2.|
|1|||END1|0|R|Indicates the END bit status of DMA channel 1.|
|0|||END0|0|R|Indicates the END bit status of DMA channel 0.|

## 9.4.20 DMA Status END Register (DSTAT_END_8_15)

This register indicates the END bit status of the CHSTAT_n register (n = 8 to 15). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|END15|END14|END13|END12|END11|END10|END9|END8|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||END15|0|R|Indicates the END bit status of DMA channel 15.|
|6|||END14|0|R|Indicates the END bit status of DMA channel 14.|
|5|||END13|0|R|Indicates the END bit status of DMA channel 13.|
|4|||END12|0|R|Indicates the END bit status of DMA channel 12.|
|3|||END11|0|R|Indicates the END bit status of DMA channel 11.|
|2|||END10|0|R|Indicates the END bit status of DMA channel 10.|
|1|||END9|0|R|Indicates the END bit status of DMA channel 9.|
|0|||END8|0|R|Indicates the END bit status of DMA channel 8.|

## 9.4.21 DMA Status TC Register (DSTAT_TC_0_7)

This register indicates the TC bit status of the CHSTAT_n register (n = 0 to 7). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|TC7|TC6|TC5|TC4|TC3|TC2|TC1|TC0|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||TC7|0|R|Indicates the TC bit status of DMA channel 7.|
|6|||TC6|0|R|Indicates the TC bit status of DMA channel 6.|
|5|||TC5|0|R|Indicates the TC bit status of DMA channel 5.|
|4|||TC4|0|R|Indicates the TC bit status of DMA channel 4.|
|3|||TC3|0|R|Indicates the TC bit status of DMA channel 3.|
|2|||TC2|0|R|Indicates the TC bit status of DMA channel 2.|
|1|||TC1|0|R|Indicates the TC bit status of DMA channel 1.|
|0|||TC0|0|R|Indicates the TC bit status of DMA channel 0.|

## 9.4.22 DMA Status TC Register (DSTAT_TC_8_15)

This register indicates the TC bit status of the CHSTAT_n register (n = 8 to 15).

Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|TC15|TC14|TC13|TC12|TC11|TC10|TC9|TC8|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||TC15|0|R|Indicates the TC bit status of DMA channel 15.|
|6|||TC14|0|R|Indicates the TC bit status of DMA channel 14.|
|5|||TC13|0|R|Indicates the TC bit status of DMA channel 13.|
|4|||TC12|0|R|Indicates the TC bit status of DMA channel 12.|
|3|||TC11|0|R|Indicates the TC bit status of DMA channel 11.|
|2|||TC10|0|R|Indicates the TC bit status of DMA channel 10.|
|1|||TC9|0|R|Indicates the TC bit status of DMA channel 9.|
|0|||TC8|0|R|Indicates the TC bit status of DMA channel 8.|

## 9.4.23 DMA Status SUS Register (DSTAT_SUS_0_7)

This register indicates the SUS bit status of the CHSTAT_n register (n = 0 to 7). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|SUS7|SUS6|SUS5|SUS4|SUS3|SUS2|SUS1|SUS0|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||SUS7|0|R|Indicates the SUS bit status of DMA channel 7.|
|6|||SUS6|0|R|Indicates the SUS bit status of DMA channel 6.|
|5|||SUS5|0|R|Indicates the SUS bit status of DMA channel 5.|
|4|||SUS4|0|R|Indicates the SUS bit status of DMA channel 4.|
|3|||SUS3|0|R|Indicates the SUS bit status of DMA channel 3.|
|2|||SUS2|0|R|Indicates the SUS bit status of DMA channel 2.|
|1|||SUS1|0|R|Indicates the SUS bit status of DMA channel 1.|
|0|||SUS0|0|R|Indicates the SUS bit status of DMA channel 0.|

## 9.4.24 DMA Status SUS Register (DSTAT_SUS_8_15)

This register indicates the SUS bit status of the CHSTAT_n register (n = 8 to 15). Even if you write to this register, the values of the individual bits do not change.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|SUS15|SUS14|SUS13|SUS12|SUS11|SUS10|SUS9|SUS8|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|8|—|All 0|R|Reserved area. Set 0. A read operation results in 0 being read.|
|7|||SUS15|0|R|Indicates the SUS bit status of DMA channel 15.|
|6|||SUS14|0|R|Indicates the SUS bit status of DMA channel 14.|
|5|||SUS13|0|R|Indicates the SUS bit status of DMA channel 13.|
|4|||SUS12|0|R|Indicates the SUS bit status of DMA channel 12.|
|3|||SUS11|0|R|Indicates the SUS bit status of DMA channel 11.|
|2|||SUS10|0|R|Indicates the SUS bit status of DMA channel 10.|
|1|||SUS9|0|R|Indicates the SUS bit status of DMA channel 9.|
|0|||SUS8|0|R|Indicates the SUS bit status of DMA channel 8.|

## 9.4.25 DMA Extension Resource Selectors 0 to 7 (DMARS0 to DMARS7)

DMARS are 32-bit readable/writable registers that specify the DMA transfer sources from peripheral modules in each

channel. DMARS0 is for channels 0 and 1, DMARS1 is for channels 2 and 3, and so on.

Table 9.4 shows the specifiable combinations.

DMARS can specify transfer requests to be accepted for the following triggers. The following modules can issue on-chip peripheral module requests. Serial communication interface with FIFO: 10 sources A/D converter: 1 source Multi-function timer pulse unit 2: 5 sources USB2.0 host/function module: 4 sources Serial sound interface: 7 sources Renesas SPDIF interface: 2 sources CD-ROM decoder: 1 source (RZ/A1L only) SD host interface: 4 sources MMC host interface: 2 sources Renesas serial peripheral interface: 6 sources IEBus™ controller: 2 sources (RZ/A1L only) OS timer: 2 sources SCUX: 8 sources Media local bus: 1 source (RZ/A1L only) Serial communication interface: 4 sources I[2] C bus interface: 8 sources LIN interface: 2 sources (RZ/A1L only)

Some on-chip peripheral modules in this product use the same signal both for an interrupt request and for a DMA transfer request. If such a module is selected by a DMARS register, the signal works as a DMA transfer request signal and interrupt requests to the interrupt controller are masked. To enable the interrupt, clear the setting of DMARS (set all MID[6:0] and RID[1:0] to 0).

##  DMARS0

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|||CH1 MID[6:0]|||||CH1|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|||CH0 MID[6:0]|||||CH0|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

- DMARS1

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|||CH3 MID[6:0]|||||CH3|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|||CH2 MID[6:0]|||||CH2|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|ARS2|||||||||||||||||
|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||-|-|-|-|-|-|-|||CH5 MID[6:0]|||||CH5|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|||CH4 MID[6:0]|||||CH4|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

##  DMARS2

- DMARS3

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|||CH7 MID[6:0]|||||CH7|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|||CH6 MID[6:0]|||||CH6|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

##  DMARS4

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|||CH9 MID[6:0]|||||CH9|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|||CH8 MID[6:0]|||||CH8|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

- DMARS5

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|||CH11 MID[6:0]|||||CH11|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|||CH10 MID[6:0]|||||CH10|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|ARS6|||||||||||||||||
|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||-|-|-|-|-|-|-|||CH13 MID[6:0]|||||CH13|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|||CH12 MID[6:0]|||||CH12|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

##  DMARS6

- DMARS7

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|||CH15 MID[6:0]|||||CH15|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|||CH14 MID[6:0]|||||CH14|RID[1:0]|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## 9.5 Operation

When there is a DMA transfer request, the DMAC starts the transfer according to the predetermined channel priority order; when the transfer end conditions are satisfied, it ends the transfer. Transfers can be requested in three modes: auto request, external request, and on-chip peripheral module request.

## 9.5.1 Transfer Flow

After the next source address register (N0SA_n/N1SA_n), next destination address register (N0DA_n/N1DA_n), next transaction byte register (N0TB_n/N1TB_n), channel control register (CHCTRL_n), channel configuration register (CHCFG_n), channel extension register (CHEXT_n), DMA control register (DCTRL_0_7/DCTRL_8_15), and DMA extension resource selector (DMARS) are set for the target transfer conditions, the DMAC transfers data according to the following procedure:

1. Checks to see if transfer is enabled (EN = 0 and TACT = 0 in channel status register).

2. Clears the channel status register (set 1 in the SWRST bit of the channel control register).

3. Enables DMA transfer (set 1 in the SETEN bit of the channel control register).

4. When a transfer request comes and transfer is enabled, the DMAC transfers one transfer unit of data (depending on the DDS[3:0] and SDS[3:0] bit settings). For an auto request, the transfer begins automatically when 1 is set in the STG bit of the channel control register. The CRTB_n value will be decremented by 1 for each transfer.

5. If 0 is set in the REN bit of the channel configuration register when transfer has been completed for the specified count (when CRTB_n reaches 0), transfer ends normally. If the DEM bit of the channel configuration register is set to 0 at this time, a DMA transfer end interrupt is sent to the CPU. If the REN bit is 1 when CRTB_n reaches 0, transfer operations are continued with the values of N0SA_n/N1SA_n, N0DA_n/N1DA_n, and N0TB_n/N1TB_n set by the RSEL bit of the channel configuration register until there are no more transfer requests.

6. When an address error in the DMAC is generated, the transfer is stopped. Transfers are also stopped when 1 is set in the CLREN bit of CHCTRL_n.

## 9.5.2 DMA Transfer Requests

DMA transfer requests are basically generated in either the data transfer source or destination, but they can also be generated in external devices and on-chip peripheral modules that are neither the transfer source nor destination. Transfers can be requested in three modes: auto request, external request, and on-chip peripheral module request. External request or on-chip peripheral module request is selected by the DMARS0 to DMARS7 registers.

## (1) Auto-Request Mode

When there is no transfer request signal from an external source, as in a memory-to-memory transfer or a transfer between memory and an on-chip peripheral module unable to request a transfer, auto-request mode allows the DMAC to automatically generate a transfer request signal internally. When the STG bit in channel control register is set to 1, the transfer begins so long as the TACT bit in channel status register is 0.

## (2) External Request Mode

In this mode a transfer is performed at the transfer request signal (DREQ0) of an external device of the LSI. When the DMA transfer is enabled, DMA transfer is performed upon a DREQ input.

Choose to detect DREQ0 by either the edge or level of the signal input with the LVL, HIEN, and LOEN bits in channel configuration register 0 as shown below. The source of the transfer request does not have to be the data transfer source or destination.

For the output level settings of the DACK0 and TEND0 pins, refer to section 8, Bus State Controller .

**Table 9.3 Settings for External Request Detection**

**CHCFG_0**

||**CHCFG_0**|
|---|---|
|**LVL**|**Detection of External Request**<br>**HIEN**<br>**LOEN**|
|0|0<br>1<br>Falling edge detection|
||1<br>0<br>Rising edge detection|
|1|0<br>1<br>Low level detection|
||1<br>0<br>High level detection|

When DREQ0 is accepted, the DREQ0 pin enters the request accept disabled state (non-sensitive period). After issuing an acknowledge DACK0 signal for the accepted DREQ0, the DREQ0 pin again enters the request accept enabled state.

## (3) On-Chip Peripheral Module Request Mode

In this mode, the transfer is performed in response to the DMA transfer request signal from an on-chip peripheral module.

When a transfer request signal is sent in on-chip peripheral module request mode while DMA transfer is enabled, the DMA transfer is performed.

The DMA transfer request signals to be sent from on-chip peripheral modules or external pin input are listed in Table 9.4 .

The transfer source or destination is fixed for some on-chip peripheral module requests. For details, see Table 9.4 .

**Table 9.4 On-Chip Peripheral Module Requests**

|**DMA Transfer**<br>**Request Source**|**DMA Transfer**<br>**Request Signal**|**Transfer**<br>**Source**|**Transfer**<br>**Destination**|**DMARS**||**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||**MID**|**RID**|**TM**|**AM**<br>**[2:0]**|**LVL**|**HIEN**|**LO**<br>**EN**|**RE**<br>**QD**|**SEL[2:0]**|
|OS timer<br>channel 0|OSTM0TINT<br>(compare match)|Arbitrary|Arbitrary|000_1000|11|0/1|010|0|1|0|0/1|Ch0: 000<br>Ch1: 001<br>Ch2: 010<br>Ch3: 011<br>Ch4: 100<br>Ch5: 101<br>Ch6: 110<br>Ch7: 111<br>Ch8: 000<br>Ch9: 001<br>Ch10: 010<br>Ch11: 011<br>Ch12: 100<br>Ch13: 101<br>Ch14: 110<br>Ch15: 111|
|OS timer<br>channel 1|OSTM1TINT<br>(compare match)|Arbitrary|Arbitrary|000_1001|11||||||||
|Multi-function timer<br>pulse unit 2<br>channel 0|TGIA_0<br>(input capture/<br>compare match)|Arbitrary|Arbitrary|001_0000|11|0/1|001|1|||0/1||
|Multi-function timer<br>pulse unit 2<br>channel 1|TGIA_1<br>(input capture/<br>compare match)|Arbitrary|Arbitrary|001_0001|11||||||||
|Multi-function timer<br>pulse unit 2<br>channel 2|TGIA_2<br>(input capture/<br>compare match)|Arbitrary|Arbitrary|001_0010|11||||||||
|Multi-function timer<br>pulse unit 2<br>channel 3|TGIA_3<br>(input capture/<br>compare match)|Arbitrary|Arbitrary|001_0011|11||||||||
|Multi-function timer<br>pulse unit 2<br>channel 4|TGIA_4<br>(input capture/<br>compare match)|Arbitrary|Arbitrary|001_0100|11||||||||
|Serial<br>communication<br>interface with FIFO<br>channel 0|TXI0<br>(transmit empty)|Arbitrary|SCFTDR_0|001_1000|01|0|010|1|||1||
||RXI0<br>(receive data full)|SCFRDR_0|Arbitrary||10||||||0||
|Serial<br>communication<br>interface with FIFO<br>channel 1|TXI1<br>(transmit empty)|Arbitrary|SCFTDR_1|001_1001|01||||||1||
||RXI1<br>(receive data full)|SCFRDR_1|Arbitrary||10||||||0||
|Serial<br>communication<br>interface with FIFO<br>channel 2|TXI2<br>(transmit empty)|Arbitrary|SCFTDR_2|001_1010|01||||||1||
||RXI2<br>(receive data full)|SCFRDR_2|Arbitrary||10||||||0||

**Table 9.4 On-Chip Peripheral Module Requests**

|**DMA Transfer**<br>**Request Source**|**DMA Transfer**<br>**Request Signal**|**Transfer**<br>**Source**|**Transfer**<br>**Destination**|**DMARS**||**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||**MID**|**RID**|**TM**|**AM**<br>**[2:0]**|**LVL**|**HIEN**|**LO**<br>**EN**|**RE**<br>**QD**|**SEL[2:0]**|
|Serial<br>communication<br>interface with FIFO<br>channel 3|TXI3<br>(transmit empty)|Arbitrary|SCFTDR_3|001_1011|01|0|010|1|1|0|1|Ch0: 000<br>Ch1: 001<br>Ch2: 010<br>Ch3: 011<br>Ch4: 100<br>Ch5: 101<br>Ch6: 110<br>Ch7: 111<br>Ch8: 000<br>Ch9: 001<br>Ch10: 010<br>Ch11: 011<br>Ch12: 100<br>Ch13: 101<br>Ch14: 110<br>Ch15: 111|
||RXI3<br>(receive data full)|SCFRDR_3|Arbitrary||10||||||0||
|Serial<br>communication<br>interface with FIFO<br>channel 4|TXI4<br>(transmit empty)|Arbitrary|SCFTDR_4|001_1100|01||||||1||
||RXI4<br>(receive data full)|SCFRDR_4|Arbitrary||10||||||0||
|USB2.0 host/<br>function module<br>channel 0|USB0_DMA0<br>(channel 0<br>transmit FIFO<br>empty)|Arbitrary|D0FIFO_0<br>D0FIFOBn_0<br>(n = 0 to 7)|010_0000|11||010|1|||1||
||USB0_DMA0<br>(channel 0<br>receive FIFO full)|D0FIFO_0<br>D0FIFOBn_0<br>(n = 0 to 7)|Arbitrary||||||||0||
||USB0_DMA1<br>(channel 1<br>transmit FIFO<br>empty)|Arbitrary|D1FIFO_0<br>D1FIFOBn_0<br>(n = 0 to 7)|010_0001|11||||||1||
||USB0_DMA1<br>(channel 1<br>receive FIFO full)|D1FIFO_0<br>D1FIFOBn_0<br>(n = 0 to 7)|Arbitrary||||||||0||
|USB2.0 host/<br>function module<br>channel 1|USB1_DMA0<br>(channel 0<br>transmit FIFO<br>empty)|Arbitrary|D0FIFO_1<br>D0FIFOBn_1<br>(n = 0 to 7)|010_0010|11||||||1||
||USB1_DMA0<br>(channel 0<br>receive FIFO full)|D0FIFO_1<br>D0FIFOBn_1<br>(n = 0 to 7)|Arbitrary||||||||0||
||USB1_DMA1<br>(channel 1<br>transmit FIFO<br>empty)|Arbitrary|D1FIFO_1<br>D1FIFOBn_1<br>(n = 0 to 7)|010_0011|11||||||1||
||USB1_DMA1<br>(channel 1<br>receive FIFO full)|D1FIFO_1<br>D1FIFOBn_1<br>(n = 0 to 7)|Arbitrary||||||||0||
|A/D converter|ADI<br>(A/D conversion<br>end)|ADDR|Arbitrary|010_0100|11|0/1|001|1|||0||
|IEBus™ controller<br>(RZ/A1L only)|IEBBTD<br>(data interrupt)<br>(transmission in<br>single mode)|Arbitrary|IEBB0DR|010_1000|11|0|010|0|||||
||IEBBTD<br>(data interrupt)<br>(reception in<br>single mode)|IEBB0DR|Arbitrary||||||||||
||IEBBTD<br>(data interrupt)<br>(transmission in<br>FIFO mode)|Arbitrary|IEBB0DR||||||||||
||IEBBTV<br>(vector interrupt)<br>(reception in FIFO<br>mode)|IEBB0DR|Arbitrary|010_1001|11||||||||
|CD-ROM decoder<br>(RZ/A1L only)|IREADY<br>(decoding end)|STRMDOUT<br>0|Arbitrary|010_1010|11||010|1|||0||
|SD host interface 0|SDHI_0<br>transmission|Arbitrary|Data register|011_0000|01||010|1|||1||
||SDHI_0 reception|Data register|Arbitrary||10||||||0||
|SD host interface 1|SDHI_1<br>transmission|Arbitrary|Data register|011_0001|01||||||1||
||SDHI_1 reception|Data register|Arbitrary||10||||||0||

**Table 9.4 On-Chip Peripheral Module Requests**

|**DMA Transfer**<br>**Request Source**|**DMA Transfer**<br>**Request Signal**|**Transfer**<br>**Source**|**Transfer**<br>**Destination**|**DMARS**||**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||**MID**|**RID**|**TM**|**AM**<br>**[2:0]**|**LVL**|**HIEN**|**LO**<br>**EN**|**RE**<br>**QD**|**SEL[2:0]**|
|MMC host<br>interface|Transmit data<br>empty|Arbitrary|Data register|011_0010|01|0|010|1|1|0|1|Ch0: 000<br>Ch1: 001<br>Ch2: 010<br>Ch3: 011<br>Ch4: 100<br>Ch5: 101<br>Ch6: 110<br>Ch7: 111<br>Ch8: 000<br>Ch9: 001<br>Ch10: 010<br>Ch11: 011<br>Ch12: 100<br>Ch13: 101<br>Ch14: 110<br>Ch15: 111|
||Receive data full|Data register|Arbitrary||10||||||0||
|Serial sound<br>interface<br>channel 0|SSITXI0 (transmit<br>data empty)|Arbitrary|SSIFTDR_0|011_1000|01||010|1|||1||
||SSIRXI0 (receive<br>data full)|SSIFRDR_0|Arbitrary||10||||||0||
|Serial sound<br>interface<br>channel 1|SSITXI1 (transmit<br>data empty)|Arbitrary|SSIFTDR_1|011_1001|01||||||1||
||SSIRXI1 (receive<br>data full)|SSIFRDR_1|Arbitrary||10||||||0||
|Serial sound<br>interface<br>channel 2|SSIRTI2<br>(transmit data<br>empty)|Arbitrary|SSIFTDR_2|011_1010|11||||||1||
||SSIRTI2<br>(receive data full)|SSIFRDR_2|Arbitrary||||||||0||
|Serial sound<br>interface<br>channel 3|SSITXI3 (transmit<br>data empty)|Arbitrary|SSIFTDR_3|011_1011|01||||||1||
||SSIRXI3 (receive<br>data full)|SSIFRDR_3|Arbitrary||10||||||0||
|SCUX|SCUTXI0<br>(FFD0_0<br>request)|Arbitrary|DMATD0_CI<br>M|100_0000|01||001|1|||1||
||SCURXI0<br>(FFU0_0 request)|DMATU0_CI<br>M|Arbitrary||10||||||0||
||SCUTXI1<br>(FFD0_1 request)|Arbitrary|DMATD1_CI<br>M|100_0001|01||||||1||
||SCURXI1<br>(FFU0_1 request)|DMATU1_CI<br>M|Arbitrary||10||||||0||
||SCUTXI2<br>(FFD0_2 request)|Arbitrary|DMATD2_CI<br>M|100_0010|01||||||1||
||SCURXI2<br>(FFU0_2 request)|DMATU2_CI<br>M|Arbitrary||10||||||0||
||SCUTXI3<br>(FFD0_3 request)|Arbitrary|DMATD3_CI<br>M|100_0011|01||||||1||
||SCURXI3<br>(FFU0_3 request)|DMATU3_CI<br>M|Arbitrary||10||||||0||
|Renesas serial<br>peripheral interface<br>channel 0|<br>SPTI0<br>(transmit data<br>empty)|Arbitrary|SPDR_0|100_1000|01||010|1|||1||
||SPRI0<br>(receive data full)|SPDR_0|Arbitrary||10||||||0||
|Renesas serial<br>peripheral interface<br>channel 1|SPTI1<br>(transmit data<br>empty)|Arbitrary|SPDR_1|100_1001|01||||||1||
||SPRI1<br>(receive data full)|SPDR_1|Arbitrary||10||||||0||
|Renesas serial<br>peripheral interface<br>channel 2|SPTI2<br>(transmit data<br>empty)|Arbitrary|SPDR_2|100_1010|01||||||1||
||SPRI2<br>(receive data full)|SPDR_2|Arbitrary||10||||||0||
|Renesas SPDIF<br>interface|SPDIFTXI|Arbitrary|TDAD|101_0000|01||010|1|||1||
||SPDIFRXI|RDAD|Arbitrary||10||||||0||
|Media local bus<br>(RZ/A1L only)|MLB_CINT<br>(MLB channel<br>write)|Arbitrary|Local<br>Channel<br>buffer|101_0011|11||010|1|||1||
||MLB_CINT<br>(MLB channel<br>read)|Local<br>Channel<br>buffer|Arbitrary||||||||0||

**Table 9.4 On-Chip Peripheral Module Requests**

|**DMA Transfer**<br>**Request Source**|**DMA Transfer**<br>**Request Signal**|**Transfer**<br>**Source**|**Transfer**<br>**Destination**|**DMARS**||**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|**CHCFG_n**|||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||**MID**|**RID**|**TM**|**AM**<br>**[2:0]**|**LVL**|**HIEN**|**LO**<br>**EN**|**RE**<br>**QD**|**SEL[2:0]**|
|Serial<br>communication<br>interface<br>channel 0|TXI0|Arbitrary|TDR0|101_1010|01|0|010|0|1|0|1|Ch0: 000<br>Ch1: 001<br>Ch2: 010<br>Ch3: 011<br>Ch4: 100<br>Ch5: 101<br>Ch6: 110<br>Ch7: 111<br>Ch8: 000<br>Ch9: 001<br>Ch10: 010<br>Ch11: 011<br>Ch12: 100<br>Ch13: 101<br>Ch14: 110<br>Ch15: 111|
||RXI0|RDR0|Arbitrary||10||||||0||
|Serial<br>communication<br>interface<br>channel 1|TXI1|Arbitrary|TDR1|101_1011|01||010|0|||1||
||RXI1|RDR1|Arbitrary||10||||||0||
|I2C bus interface<br>channel 0|INTRIICTI0<br>(transmit data<br>empty)|Arbitrary|RIIC0DRT|110_0000|01||010|0|||1||
||INTRIICRI0<br>(receive data full)|RIIC0DRR|Arbitrary||10||||||0||
|I2C bus interface<br>channel 1|INTRIICTI1<br>(transmit data<br>empty)|Arbitrary|RIIC1DRT|110_0001|01||||||1||
||INTRIICRI1<br>(receive data full)|RIIC1DRR|Arbitrary||10||||||0||
|I2C bus interface<br>channel 2|INTRIICTI2<br>(transmit data<br>empty)|Arbitrary|RIIC2DRT|110_0010|01||||||1||
||INTRIICRI2<br>(receive data full)|RIIC2DRR|Arbitrary||10||||||0||
|I2C bus interface<br>channel 3|INTRIICTI3<br>(transmit data<br>empty)|Arbitrary|RIIC3DRT|110_0011|01||||||1||
||INTRIICRI3<br>(receive data full)|RIIC3DRR|Arbitrary||10||||||0||
|LIN interface<br>channel 0<br>(RZ/A1L only)|LIN0_INT_T<br>(LIN mode)|Arbitrary|RLN30LDBR<br>m<br>(m = 1 to 8)|110_1000|01|0|010|0|1|0|1||
||LIN0_INT_R<br>(LIN mode)|RLN30LDBR<br>m<br>(m = 1 to 8)|Arbitrary||10||||||0||
|External request|DREQ0|Arbitrary|Arbitrary|000_0000|11|0/1|001/<br>010/<br>100|001: Falling edge<br>detection<br>010: Rising edge<br>detection<br>101: Low level<br>detection<br>110: High level<br>detection|||0/1|000|

Note: • CHCFG_n setting value

TM        0: Single transfer

AM        001: ACK level output

LVL      0: REQ edge detection

REQD  0: ACK output at read

## 9.6 DMA Mode

## 9.6.1 Mode Setting

You can toggle between register mode and link mode, by using the DMS field of the CHCFG_n register.

## **Table 9.5 DMA Mode Setting**

|**DMS**|||
|---|---|---|
|**(CHCFG_n)**|**Mode**|**Description**|
|0|Register mode|A DMA transfer is executed using the values set in the Next Register Set.|
|1|Link mode|A DMA transfer is executed using the descriptor set in the Current register. The DMAC|
|||repeatedly loads the descriptor and executes the DMA transfer unless otherwise set by|
|||the descriptor or stopped by the control register.|

## 9.6.2 Register Mode

In register mode, a DMA transfer is executed using the values set in the internal registers.

Two sets of the source address, destination address, and transfer byte count (Next0 Register Set and Next1 Register Set) can be set. It is possible to select the Next Register Set to be used for the DMA transfer, as well as to execute two Next Register Sets continuously for the DMA transfer.

**==> picture [345 x 386] intentionally omitted <==**

**----- Start of picture text -----**<br>
DMA Channel n<br>3. DMAEND<br>Next0 Register Set    (Maskable)<br>Source Address Current Register Set<br>Destination Address<br>1. Load<br>Transaction Byte Source Address 2. Transfer<br>Destination Address<br>Next1 Register Set Transaction Byte<br>Source Address<br>Channel Control<br>Destination Address<br>Channel Status<br>Transaction Byte<br>Channel Config<br>Select (RSEL = 0)<br>DMA Channel n<br>3. DMAEND<br>Next0 Register Set<br>   (Maskable)<br>Source Address Current Register Set<br>Destination Address<br>Transaction Byte Source Address<br>2. Transfer<br>Destination Address<br>Next1 Register Set Transaction Byte<br>1. Load<br>Source Address<br>Channel Control<br>Destination Address<br>Channel Status<br>Transaction Byte<br>Channel Config<br>Select (RSEL = 1)<br>**----- End of picture text -----**<br>

**Figure 9.2 Outline of Normal Register Mode**

The above figure shows how the transfer is executed when the Next0 Register Set is used (upper part of the figure) and when the Next1 Register Set is used (lower part of the figure).

## (1) Operation Flow

**==> picture [389 x 383] intentionally omitted <==**

**----- Start of picture text -----**<br>
Setup by software<br>configurationsSet channel Set channel enableSETEN = 1 Processing by hardware<br>Bus transaction<br>Register set selection<br>RSEL 1<br>0<br>Load Next0 Register Set to Current Load Next1 Register Set to Current<br>                    Register Set                  N0SA -> CRSA                     Register Set                  N1SA -> CRSA<br>                  N0DA -> CRDA                   N1DA -> CRDA<br>                  N0TB -> CRTB                   N1TB -> CRTB<br>Processing<br>transaction<br>Wait for request and  DMA transaction<br>          interval is not completed<br>RQST = 1<br>DMA transfer<br>DMA transaction is  Bus error<br>     completed Register set<br>automatic<br>DMAEND change<br>mask<br>DEM  0 Assert DMAEND RSW 1 RSEL = ~RSELRSEL reversal<br>1<br>DEM = 0 0<br>ER = 1<br>Continuation  DMA error = 1<br>execution<br>REN 0<br>1<br>REN = 0 End<br>EN = 0<br>**----- End of picture text -----**<br>

**Figure 9.3 Register Mode Flow**

<Explanation of the register mode flow>

1. Channel setting (set channel configuration)

   - The Next0 or Next1 Register Set (destination address, source address, and total transfer byte count) is set. In the Channel Register Set, the DMA Register Set (REQ, DMAACK, transfer size, etc.) is set. (See section 9.7, DMA Transfer .)

2. Register set selection (register set selection) When 1 is set in EN, the values set in the Next Register Set selected by RSEL are loaded to the Current Register Set.

3. DMA transaction (processing transaction)

A DMA transfer is executed according to the set values. For details of the transfer, see section 9.7, DMA Transfer .

4. DMA transfer end interrupt mask (DMAINT mask) The DMA transfer end interrupt is masked according to the value set in the DEM bit of CHCFG_n. When 1 is set in DEM, the DMA transfer end interrupt is not output. Also, immediately after that, DEM is automatically cleared to 0.

5. Automatic register set change (register set automatic change) Whether to use the other Next Register Set is determined by the value set in the RSW bit of CHCFG_n.

6. Continuation of execution (continuation execution) Whether to continue the execution of the DMA transfer is determined by the value set in the REN bit of CHCFG_n. When 1 is set in REN, the execution of the DMA transfer is continued. Also, immediately after that, REN is automatically cleared to 0.

(2) Register Setting

(a) Register mode setting

Select the register set to be executed.

## **Table 9.6 Register Mode Setting**

|**DMS**<br>**(CHCFG_n)**|**RSEL**<br>**(CHCFG_n)**<br>**Description**|
|---|---|
|0|0<br>Executes the Next0 Register Set.|
||1<br>Executes the Next1 Register Set.|

## (b) DMA transfer end interrupt mask setting

The DMA transfer end interrupt can be masked individually for each register set.

## **Table 9.7 DMAINT Mask Setting**

|**DEM**|||
|---|---|---|
|**(CHCFG_n)**|**Operation**|**Remark**|
|0|When the DMA transaction is completed, a DMA transfer end interrupt is||
||issued.||
|1|Even when the DMA transaction is completed, a DMA transfer end interrupt||
||is not issued.||
||After the DMA transaction is completed, DEM is cleared to 0 by hardware.||

## (c) Automatic register set execution setting

After DMA transfers, the DMA transaction of the selected register set is automatically executed.

## **Table 9.8 Automatic Register Set Execution Setting**

|**Table 9.8**|**Automatic Register Set Execution Setting**||
|---|---|---|
|**REN**|||
|**(CHCFG_n)**|**Operation**|**Remark**|
|0|When the DMA transaction of the register set selected by RSEL is|Set this value when you want to execute a|
||completed, the EN bit is cleared and the DMA operation ends.|DMA transaction once.|
|1|When a DMA transaction is completed, the DMAC continues to|Set this value when you want to continuously|
||execute a DMA transfer by using the data set in the selected|execute DMA transfers by using the data set|
||register set. When continuous transfers are successful, REN is|in separate register sets.|
||cleared to 0.||

## (d) Automatic register set change setting

When 1 is set in REN, the DMAC can automatically change to the register set to be executed next, after a DMA transaction is completed.

## **Table 9.9 Automatic Register Set Change Setting**

|**Table 9.9**|**Automatic Register Set Change Setting**||
|---|---|---|
|**RSW**|||
|**(CHCFG_n)**|**Operation**|**Remark**|
|0|If 1 is set in REN when a DMA transaction is completed, the register set is not|Set this value when you want to|
||changed.|use only one register set.|
|1|If 1 is set in REN when a DMA transaction is completed, the value of RSEL is|Set this value when you want to|
||automatically inverted and the other register set is selected.|change the register set.|

- (3) Setting Examples

- (a) When only the Next0 Register Set is used

**Table 9.10 Register Mode Setting Example 1**

|**DMS**|**RSEL**|**DEM**|**RSW**|**REN**|
|---|---|---|---|---|
|**(CHCFG_n)**|**(CHCFG_n)**|**(CHCFG_n)**|**(CHCFG_n)**|**(CHCFG_n)**|
|0|0|0|0|0|
|(Register mode)|(Next0)|(not masked)|(not switched)|(not continuously executed)|

**==> picture [346 x 201] intentionally omitted <==**

**----- Start of picture text -----**<br>
DMA Channel n<br>3.DMAEND<br>Next0 Register Set    (Maskable)<br>Source Address Current Register Set<br>Destination Address 1. Load<br>Transaction Byte  Source Address<br>Destination Address 2. Transfer<br>Next1 Register Set  Transaction Byte<br>Source Address<br>Channel Status<br>Destination Address Channel Control<br>Transaction Byte  Channel Config<br>Select (RSEL = 0)<br>**----- End of picture text -----**<br>

**Figure 9.4 Register Mode Setting Example 1**

1. 1 is set in EN (SETEN = 1), and the Next0 Register Set is loaded to the Current Register Set.

2. A DMA transaction is executed according to the values set in the Current Register Set and Channel Register Set.

3. Because 0 is set in DEM, the DMA transfer end interrupt is issued after the DMA transaction is completed.

4. Because 0 is set in REN, EN is cleared to 0 and the DMA transaction ends.

(b) When two register sets are used continuously

## **Table 9.11 Automatic Register Set Execution Setting**

|**DMS**|**RSEL**|**DEM**|**RSW**|**REN**|
|---|---|---|---|---|
|**(CHCFG_n)**|**(CHCFG_n)**|**(CHCFG_n)**|**(CHCFG_n)**|**(CHCFG_n)**|
|0|0|1|1|1|
|(Register mode)|(Next0)|(masked)|(switched)|(continuously executed)|

**==> picture [346 x 201] intentionally omitted <==**

**----- Start of picture text -----**<br>
DMA<br>6.DMAEND<br>Next0 Register Set<br>Source Address Current Register Set<br>Destination Address 1. Load 2. Transfer<br>Transaction Byte  Source Address<br>Destination Address 5. Transfer<br>Next1 Register Set Transaction Byte<br>4. Load<br>Source Address<br>Channel Status<br>Destination Address Channel Control<br>Transaction Byte  Channel Config<br>3. Switch (Next0 → Next1)<br>**----- End of picture text -----**<br>

## **Figure 9.5 Register Mode Setting Example 2**

1. 1 is set in EN (SETEN = 1), and the Next0 Register Set is loaded to the Current Register Set.

2. A DMA transaction is executed according to the values set in the Current Register Set and Channel Register Set.

3. Because 1 is set in DEM, DMA transfer end interrupt is not output after the DMA transaction is completed. Also, DEM is automatically cleared to 0.

4. Because 1 is set in REN, the execution is continued. Also, REN is automatically cleared to 0.

5. Because 1 is set in RSW, the register set to be executed next is switched (RSEL = 0 → 1).

6. The Next1 Register Set is loaded to the Current Register Set.

7. A DMA transaction is executed according to the values set in the Current Register Set and Channel Register Set.

8. Because 0 is set in DEM, the DMA transfer end interrupt is issued after the DMA transaction is completed.

9. Because 0 is set in REN, EN is cleared to 0 and the DMA transaction ends.

## 9.6.3 Link Mode

In link mode, a descriptor stored in external memory is loaded as set values and a DMA transaction is executed using the loaded values. The DMAC contains a Next Link address and a Current Link address for each channel, and these addresses are used to set the descriptor address to be executed next and to indicate the descriptor address of the currently executed DMA transaction, respectively.

**==> picture [382 x 355] intentionally omitted <==**

**----- Start of picture text -----**<br>
External memory or on-chip memory space<br>0x00  header<br>0x04  Source Address<br>DMAC  0x08  Destination Address<br>Current Register Set  Bus  0x0C Transaction Byte<br>0x10  Channel Config<br>Source Address<br>0x14  Channel Interval<br>Destination Address  Link<br>0x18  Channel Extension<br>Transaction Byte<br>0x1C Link Address(0x20)<br>Link<br>Link Address Registers<br>0x20  header<br>Next Link Address<br>0x24  Source Address<br>Current Link Address<br>0x28  Destination Address<br>0x2C  Transaction Byte<br>Channel Status  0x30  Channel Config<br>Channel Control  0x34  Channel Interval<br>Channel Config  0x38  Channel Extension<br>0x3C  Link Address(0x40)<br>Link<br>0x40  header<br>0x44  Source Address<br>0x48  Destination Address<br>0x4C  Transaction Byte<br>0x50  Channel Config<br>0x54  Channel Interval<br>0x58  Channel Extension<br>0x5C  Link Address(0x60)<br>( )<br>**----- End of picture text -----**<br>

**Figure 9.6**

**Link Mode Outline**

## (1) Operation Flow

**==> picture [374 x 449] intentionally omitted <==**

**----- Start of picture text -----**<br>
Set up by software<br>Processing by hardware<br>Set link address Set channel enable Bus transaction<br>SETEN = 1<br>Reflect descriptor<br>data to registers<br>Update link address Update current link address Update registers<br>         NXLA -> CRLA Descriptor data<br>-><br>N0SA, CRSA, N0DA, CRDA,<br>N0TB, CRTB, CHCFG, CHITVL,<br>CHEXT, NXLA<br>Analyze header<br>Descriptor read Bus error<br>Valid LV = 1 Transaction<br>Wait for request  execution<br>and interval<br>RQST = 1 DMA transaction<br>is not completed.<br>DMA transfer Bus error<br>LV = 0<br>DMA transaction<br>is completed.<br>Write back<br>processing<br>(DW = 1)<br>Write back<br>processing<br>(DW = 1)<br>Write back<br>Set DER = 1<br>WBD = 0<br>WBD = 1<br>Descriptor write back  Bus error<br>           (LV = 0)<br>DMAEND<br>mask<br>DEM  0 Assert DMAEND<br>1 DIM  1<br>Clear RQST ER = 1<br>Assert DMA error<br>0<br>Assert DMAEND<br>Analyze end of<br>LE = 0 End of chain LE = 1 chain<br>End<br>EN = 0<br>**----- End of picture text -----**<br>

**Figure 9.7 Link Mode Flow**

<Explanation of the link mode flow>

1. Channel setting

The start address of the link destination is set in NXLA_n.

2. Link address update

When 1 is set in EN (1 is set in SETEN), the Link address set in NXLA_n is loaded to CRLA_n.

3. Descriptor load and header analysis

The DMAC begins to load the descriptor and then analyzes the content of the header. When LV is 0, the DMAC discards the loaded descriptor and sets 1 in DER to end the operation (EN = 0). In this case, if 0 is set in DIM of the header, DMAEND is issued.

4. Descriptor setting The loaded descriptor is set in the Current Register Set and Channel Register Set. Also, the next link address is set in NXLA_n.

5. DMA transaction

A DMA transaction is executed according to the set values.

## 6. Header writeback

When 0 is set in WBD of the header, the DMAC writes back the header with 0 set in its LV bit.

## 7. DMAINT mask

When 0 is set in the DEM bit of CHCFG_n, the DMA transfer end interrupt is issued.

## 8. Link end analysis

When 1 is set in LE of the header, the operation is ended by clearing EN to 0, after the transfer using the settings of the descriptor is completed. When 0 is set in LE, the Current register is updated and the load of the next descriptor begins. TEND is issued each time a descriptor is transferred.

## (2) Register Setting

## (a) Link mode setting

To use the link mode, set 1 in the DMS bit of the CHCFG_n register.

## **Table 9.12 Link Mode Setting**

|**DMS**||
|---|---|
|**(CHCFG_n)**|**Description**|
|1|Operates in link mode.|
||This bit cannot be changed using a descriptor.|

## (b) Link address setting

There are two registers that indicate a link address: Next Link address register and Current Link address register. To start the link mode, set a link address in the Next Link address register.

The Next Link address indicates the next link address after a descriptor is loaded. The Current Link address indicates the currently executed link address.

## **Table 9.13 Link Address Register Set**

|**Register**|**Description**|
|---|---|
|Next Link Address Register|Sets and indicates the next link address. Before starting the link mode, set a link|
|(NXLA_n)|address in this register.|
|Current Link Address Register|Indicates the currently executed link address. This register is read-only.|
|(CRLA_n)||

<Caution> In link mode, the settings can be changed by reading a descriptor. It is not possible, however, to synchronize the change of the settings with a peripheral module request or external request. Therefore, when using a peripheral module request or external request, set AM, LVL, HIEN, LOEN, and SEL of the CHCFG_n register before setting Enable and do not change any of these bits in the descriptor.

## (3) Descriptor Setting

In a link address, prepare a descriptor with data arranged in the order shown below. The DMAC reads the descriptor in burst mode.

## (a) Descriptor data arrangement

## **Table 9.14 Descriptor Data Arrangement**

|**Address**|**Data**|**Remark**|
|---|---|---|
|Link address + 00H|header||
|Link address + 04H|Source Address||
|Link address + 08H|Destination Address||
|Link address + 0CH|Transaction Byte||
|Link address + 10H|Config|The register mode cannot be set.|
|Link address + 14H|Interval||
|Link address + 18H|Extension||
|Link address + 1CH|Next Link Address||

Remark: As a link address, set an address aligned along the 32-bit boundary.

## (b) header

The header indicates the status of the descriptor, as shown below.

The DMAC reads this area when a DMA transfer is started in link mode. Also, after a DMA transaction is completed, the DMAC writes back the transfer status to the area.

|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||||||||||||||||
|-|-|-|-|-|-|-|-|-|-|-|-|DIM|WBD|LE|LV|
|If 0 is set in WBD when the header is read, the DMAC writes back to this 4-byte area<br>after a DMA transaction using a descriptor is completed.<br>0 is written back to LV, and the values obtained when reading the header are written back to the other fields.||||||||||||||||

## **Figure 9.8 header Area**

## **Table 9.15 Header Area**

|**Bit**|**Position**|**Bit Name**|**Meaning**|
|---|---|---|---|
|31|to 4|—|—|
|3||DIM|Descriptor Interrupt Mask|
||||Sets whether to mask the DMA transfer end interrupt if 0 is set in LV when the header|
||||is loaded.|
||||0: Issues a DMA transfer end interrupt.|
||||1: Does not issue a DMA transfer end interrupt.|
|2||WBD|Write Back Disable|
||||Sets whether to mask LV bit writeback. When 1 is set in this bit, the DMAC does not|
||||perform writeback.|
||||0: Writes the LV bit back to 0.|
||||1: Does not write back the LV bit.|
|1||LE|Link End|
||||Indicates whether the link ends with the DMA transaction of this descriptor.|
||||Set 1 in this bit to indicate the end of the link.|
||||0: The link continues.|
||||1: The link ends.|
|0||LV|Link Valid|
||||Indicates whether this descriptor is valid.|
||||If 0 is set in WBD, the DMAC writes 0 in this bit after the DMA transaction written in|
||||the descriptor is executed. When setting the header, set 1 in this bit.|
||||0: Descriptor invalid|
||||1: Descriptor valid|

## (c) Descriptor data other than the header

The data items of the descriptor other than the header are the same as defined in the internal register specifications (note that the DMS bit of the CHCFG_n register cannot be changed using the descriptor). For information about the internal register specifications, see section 9.4, Register Descriptions .

For descriptor setting examples, see section 9.8, DMA Setting Examples .

## (d) CACHE settings for descriptor access

The CACHE settings for descriptor access can be set in LWCA and LDCA of the DMA control register (DCTRL_0_7, DCTRL_8_15). Make these settings as appropriate for the access destination in which the descriptor is prepared.

## (e) Descriptor area and DMA transfer area

The following figure outlines the descriptor area and DMA transfer area that are accessed by the DMAC.

**==> picture [350 x 324] intentionally omitted <==**

**----- Start of picture text -----**<br>
External memory or<br>on-chip memory space<br>[31:0]<br>DMAC (1) Descriptor read header descriptor 1<br>:<br>:<br>Next Link Address<br>(2) DMA transaction<br>header descriptor 2<br>:<br>(3) Descriptor writeback :<br>Next Link Address<br>:<br>(4) Descriptor read<br>DMA transfer area 1<br>(5) DMA transaction<br>DMA transfer area 2<br>(6) Descriptor writeback<br>**----- End of picture text -----**<br>

**Figure 9.9 Outline of the Descriptor Area and DMA Transfer Area**

1. Descriptor read

   - The values set in the internal Next Link Address register are loaded to the Current Link Address register, and a descriptor is read from the external memory space (descriptor1) pointed to by the Current Link Address register.

2. DMA transfer When 1 is set in the LV bit of the header in the descriptor, a DMA transfer is executed according to the descriptor data.

3. Descriptor writeback

   - When 0 is set in the WBD bit of the header after the DMA transfer of the set number of bytes is completed, the DMAC writes back data in word size to the header of descriptor1, with 0 set in LV and the other bits containing the values read in <1>.

4. Descriptor read

   - When 0 is set in the LE bit of the header in the last read descriptor (<1>), the next descriptor is read from the address (descriptor2) indicated by Next Link Address in the descriptor.

5. DMA transfer

   - When 1 is set in the LV bit of the header in the descriptor, a DMA transfer is executed according to the descriptor data.

6. Descriptor writeback

   - When 0 is set in the WBD bit of the header after the DMA transfer of the set number of bytes is completed, the DMAC writes back data in word size to the header of descriptor2, with 0 set in LV and the other bits containing the values read in <4>.

## 4 through 6 are repeated.

When the header contains 1 in LE and 0 in WBD, the DMAC executes a DMA transfer using the settings of that descriptor, writes back data with 0 set in the LV bit of the header and ends the operation.

When the header contains 1 in both LE and WBD, the DMAC executes a DMA transfer using the settings of that descriptor and ends the operation (without writing back).

When the header contains 0 in LV, the DMAC ends the operation (without executing a DMA transfer).

## (4) Descriptor Configuration Examples

In link mode, a descriptor can be configured as shown below.

**==> picture [348 x 377] intentionally omitted <==**

**----- Start of picture text -----**<br>
List configuration Loop configuration<br>External memory or on-chip memory space External memory or on-chip memory space<br>0x00  Header (LE = 0) 0x00  Header (LE = 0)<br>0x04  Source Address  0x04  Source Address<br>0x08  Destination Address  0x08  Destination Address<br>0x0C Transaction Size  0x0C  Transaction Size<br>0x10  Channel Config  0x10  Channel Config<br>0x14  Channel Interval  0x14  Channel Interval<br>0x18  Channel Extension 0x18  Channel Extension<br>0x1C  Link Address(0x20)  0x1C  Link Address(0x20)<br>Link Link<br>0x20  header(LE = 0)  Link 0x20  header (LE = 0)<br>0x24  Source Address  0x24  Source Address<br>0x28  Destination Address  0x28  Destination Address<br>0x2C  transaction Size  0x2C  Transaction Size<br>0x30  Channel Config  0x30  Channel Config<br>0x34  Channel Interval  0x34  Channel Interval<br>0x38  Channel Extension  0x38  Channel Extension<br>0x3C Link Address(0x40)  0x3C  Link Address(0x40)<br>Link Link<br>0x40  header (LE = 1) 0x40  header (LE = 0)<br>0x44  Source Address  0x44  Source Address<br>0x48  Destination Address  0x48  Destination Address<br>0x4C  Transaction Size  0x4C  Transaction Size<br>0x50  Channel Config  0x50  Channel Config<br>0x54  Channel Interval  0x54  Channel Interval<br>0x58  Channel Extension  0x58  Channel Extension<br>0x5C Link Address(0x00)  0x5C  Link Address(0x00)<br>**----- End of picture text -----**<br>

**Figure 9.10 Descriptor Configuration Examples**

##  List configuration

The link is ended by setting 1 in the LE bit of the header in the last descriptor.

##  Loop configuration

A descriptor can be created with a loop configuration, by setting the address of the top descriptor in the link address of the last descriptor. To end the loop, change the value of the LE bit of the header to 1 before the DMAC reads the descriptor, or follow the transfer suspension procedure.

## 9.7 DMA Transfer

The basic operation of DMA transfer is described here.

## 9.7.1 Transfer Mode

Two transfer modes are supported: single transfer mode and block transfer mode.

To select a transfer mode, set the TM bit of CHCFG_n for each channel.

## **Table 9.16 Basic Transfer Setting**

||**TM**||
|---|---|---|
|**Transfer Mode**|**(CHCFG_n)**|**Function**|
|Single transfer|0|A single DMA transfer is executed in response to a DMAREQ.|
|Block transfer|1|In response to a DMAREQ, the DMAC continues to execute the transfer until the DMA|
|||transaction is completed.|

## (1) Single Transfer Mode

When a DMA transfer request is received, a DMA transfer is executed once in the direction indicated by REQD (source or destination). A DMA transfer is executed once each time a transfer request is received, and this operation continues until the number of bytes loaded to CRTB_n is reached (arbitration between channels is accomplished for each DMA transfer).

**==> picture [395 x 72] intentionally omitted <==**

**----- Start of picture text -----**<br>
DREQ0<br>DACK0<br>DMA Transfer Read Write Write Write Write<br>**----- End of picture text -----**<br>

**Figure 9.11 Single Transfer Mode (REQD = 1, SDS > DDS)**

## (2) Block Transfer Mode

Once a DMA transfer request is received, the DMAC continues to execute the transfer until data equivalent to the number of bytes loaded to the DMA transfer byte register (CRTB_n register) is transferred (the DMA transaction is completed) (arbitration between channels is accomplished for each DMA transfer).

**==> picture [384 x 66] intentionally omitted <==**

**----- Start of picture text -----**<br>
DREQ0<br>DACK0<br>DMA Transfer Read Write Read Write<br>**----- End of picture text -----**<br>

**Figure 9.12 Block Transfer Mode (REQD = 0, SDS < DDS)**

## 9.7.2 Priority Control for DMA Channels

Within channels 0 to 7 and 8 to 15, two priority control modes are supported: fixed priority mode and round robin mode. Only round robin mode is supported for priority control between the group of channels 0 to 7 and the group of channels 8 to 15. To select a priority control mode, use the PR bit of the DMA control register (DCTRL register). The fixed priority mode is selected when 0 is set in the PR bit, and the round robin mode is selected when 1 is set. Read priority and write priority are controlled independently.

The DMAC issues transfer requests to different channels concurrently without waiting for the completion of any particular transfer and processes responses in the order it receives them. Therefore, the order in which the channels start transactions is not necessarily consistent with the order in which the transactions end.

## **Table 9.17 Priority Control Setting**

||**PR**|||
|---|---|---|---|
|**Mode**|**(DCTRL)**|**Function**|**Purpose**|
|Fixed priority|0|Requests are controlled based on the fixed order of priority for|Use this mode when the|
|||channels 0 to 7 and 8 to 15 (High: CH0 (CH8) > CH1 (CH9) >|channels have a specific order|
|||CH2 (CH10) > CH3 (CH11) > CH4 (CH12) > CH5 (CH13) >|of priority.|
|||CH6 (CH14) > CH7 (CH15): Low).||
|Round robin|1|Requests are controlled in a round robin fashion.|Use this mode when you want|
||||requests evenly executed.|

## (1) Fixed Priority Mode

In fixed priority mode, the channels have a fixed order of priority in channels 0 to 7 and 8 to 15. Round robin mode is used to determine the priority between the group of channels 0 to 7 and the group of channels 8 to 15. Immediately after a reset, the order of priority is as follows.

High   CH0 > CH8 > CH1 > CH9 > CH2 > CH10 > CH3 > CH11 > CH4 > CH12 > CH5 > CH13 > CH6 > CH14 > CH7 > CH15   Low

If there is a transfer request from DMA channel 0 in this state, a transfer is executed on DMA channel 0. After the transfer is completed, the order of priority is as follows.

High   CH8 > CH0 > CH9 > CH1 > CH10 > CH2 > CH11 > CH3 > CH12 > CH4 > CH13 > CH5 > CH14 > CH6 > CH15 > CH7   Low

If a DMA transfer request occurs on multiple channels simultaneously, the DMA transfer request of the channel having the smallest channel number is given priority. The following figure shows an example where a DMA transfer request occurs on a channel having a higher priority while a DMA transfer is being executed in fixed priority mode.

**==> picture [401 x 167] intentionally omitted <==**

**----- Start of picture text -----**<br>
DMAREQ[0] Channels 4 to 7: Not used<br>Channel 0<br>DMAACK[0]<br>DMAREQ[1]<br>Channel 1<br>DMAACK[1]<br>DMAREQ[2]<br>Channel 2<br>DMAACK[2]<br>DMAREQ[3]<br>Channel 3<br>DMAACK[3]<br>Request execution order<br>Read execution channel  CH0 CH1 CH2 CH0 CH3<br>Write execution channel  CH0 CH1 CH2 CH0 CH3<br>**----- End of picture text -----**<br>

**Figure 9.13 Fixed Priority Mode (Number of Channels = 4, REQD = 1)**

## (2) Round Robin Mode

In round robin mode, each time a transfer request is received from a channel in the group of channels 0 to 7 and the group of channels 8 to 15, the order of priority is changed in such a way that the channel that executed a transfer last has the lowest priority.

Round robin mode is used to determine the priority between the group of channels 0 to 7 and the group of channels 8 to 15.

Immediately after a reset, the order of priority is the same as that of the fixed priority mode, which is as follows.

High   CH0 > CH8 > CH1 > CH9 > CH2 > CH10 > CH3 > CH11 > CH4 > CH12 > CH5 > CH13 > CH6 > CH14 > CH7 > CH15   Low

If a transfer request is received from DMA channel 2 in this state, a transfer is executed on DMA channel 2. After the transfer is completed, the order of priority is as follows.

High   CH8 > CH3 > CH9 > CH4 > CH10 > CH5 > CH11 > CH6 > CH12 > CH7 > CH13 > CH0 > CH14 > CH1 > CH15 > CH2   Low

The following figure shows an example where DMA transfers are executed in round robin mode.

**==> picture [387 x 158] intentionally omitted <==**

**----- Start of picture text -----**<br>
Channels 4 to 7: Not used<br>DMAREQ0<br>Channel 0<br>DMAACK[0]<br>DMAREQ1<br>Channel 1<br>DMAACK[1]<br>DMAREQ2<br>Channel 2<br>DMAACK[2]<br>DMAREQ3<br>Channel 3<br>DMAACK[3]<br>Request execution order<br>Read execution channel  CH2 CH3 CH0 CH1 CH3 CH2<br>Write execution channel CH2 CH3 CH0 CH1 CH3 CH2<br>Read priority channel  CH3 CH4 CH1 CH2 CH4 CH3<br>Write priority channel  CH3 CH4 CH1 CH2 CH4 CH3<br>**----- End of picture text -----**<br>

**Figure 9.14 Round Robin Mode (Number of Channels = 4, REQD = 0)**

The channel whose channel number is the number of the currently transferring channel + 1 gets to execute a DMA transfer next. If there is no transfer request from this channel, the channel whose channel number is the number of this channel + 1 gets to execute a DMA transfer.

## 9.7.3 Number of States of an External Bus Cycle

When this module is the bus master, the number of states of an external bus cycle is controlled by the bus state controller as when the CPU is the bus master. For details, refer to section 8, Bus State Controller .

## 9.7.4 DMA Transfer Request

Edge detection or level detection can be selected using the LVL bit of the CHCFG_n register.

The HIEN and LOEN bits of the CHCFG_n register are used to select either the rising edge or falling edge in the case of edge detection or either the high level or low level in the case of level detection.

When the transfer request is by an on-chip peripheral module, set the CHCFG_n register according to Table 9.4, OnChip Peripheral Module Requests .

When the transfer request is by the external pin (DREQ0), set the detection conditions (rising/falling edge and high/low level) according to Table 9.18, Setting for Detection of External Pin Request .

## **Table 9.18 Setting for Detection of External Pin Request**

|**Mode**<br>**LVL**<br>**(CHCFG_0)**|**HIEN**<br>**(CHCFG_0)**|**LOEN**<br>**(CHCFG_0)**<br>**Function**|
|---|---|---|
|Edge<br>detection<br>0|0|0<br>Specify this value when you use auto request triggers.<br>1<br>Detects external pin request (DREQ0) at its falling edge.|
||1|0<br>Detects external pin request (DREQ0) at its rising edge.<br>1<br>Setting prohibited|
|Level<br>detection<br>1|0|0<br>Setting prohibited<br>1<br>Detects external pin request (DREQ0) in Low level mode.|
||1|0<br>Detects external pin request (DREQ0) in High level mode.<br>1<br>Setting prohibited|

## (1) Edge Detection

Setting 0 in the LVL bit of the CHCFG_n register enables edge detection.

When 1 is set in the HIEN bit of the CHCFG_n register, rising edge detection is enabled. When 1 is set in the LOEN bit, falling edge detection is enabled.

Wait for DACK0 to be detected, before issuing the next DREQ0 request.

**==> picture [396 x 93] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>DREQ0<br>Internal request<br>DACK0<br>DMA Transfer                                                                     Read                                      Write                                         Read<br>**----- End of picture text -----**<br>

**Figure 9.15 Edge Detection Timing (HIEN = 1, REQD = 0)**

**==> picture [391 x 95] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>DREQ0<br>Internal request<br>DACK0<br>DMA Transfer                                                                 Read                                Write                                          Read                                  Wr<br>**----- End of picture text -----**<br>

**Figure 9.16 Edge Detection Timing (HIEN = 1, REQD = 1)**

## (2) Level Detection

Setting 1 in the LVL bit of the CHCFG_n register enables level detection.

DREQ0 is regarded as valid when it remains active for two consecutive clock cycles or more (depending on the HIEN and LOEN settings).

When the level mode is selected for DACK0, it remains at the High level until DREQ0 is deasserted.

When the next DMA transfer request is to be issued, DACK0 needs to be deasserted before that DREQ0 can be asserted.

**==> picture [391 x 99] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>DREQ0<br>Internal request<br>DACK0<br>DMA Transfer                                                                          Read                                     Write                                       Read<br>**----- End of picture text -----**<br>

**Figure 9.17 Level Detection Timing (HIEN = 1, REQD = 0, AM[2:0] = 001)**

**==> picture [392 x 110] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>DREQ0<br>Internal request<br>DACK0<br>DMA Transfer                                                                     Read                                 Write                                                    Read<br>**----- End of picture text -----**<br>

**Figure 9.18 Level Detection Timing (HIEN = 1, REQD = 1, AM[2:0] = 001)**

## 9.7.5 DMA Acknowledge Output Function

DACK0 is an acknowledge signal that is sent to DREQ0. Level output and bus cycle output settings are supported as the DACK0 output mode. DACK0 is asserted at the same time as CS assertion except for the MPX-IO interface. For details, refer to section 8, Bus State Controller .

## (1) DMA Acknowledge Signal Output Timing Setting

Upon receiving a DMA transfer request, the DACK0 pin becomes active (High level output). By using the REQD and AM[2:0] bits of the CHCFG_n register, the DACK0 output timing can be set as shown below.

## **Table 9.19 DACK0 Output Timing Setting**

|**Table 9.19**<br>**DACK0 Output Timing Setting**||
|---|---|
|**Mode**<br>**AM[2]**<br>**(CHCFG_0)**<br>**AM[1:0]**<br>**(CHCFG_0)**|**REQD**<br>**(CHCFG_0)**<br>**Purpose**|
|Pulse<br>0<br>00|0<br>Setting prohibited<br>1|
|Level<br>0<br>01|0 (Active during read)<br>DACK0 is output as a level. DACK0<br>remains asserted until DREQ0 is<br>deasserted.<br>1 (Active during write)|
|Bus cycle<br>0<br>10<br>11|0 (Active during read)<br>DACK0 is output for the duration of a bus<br>cycle. Use this mode when you want to<br>keep DACK0 asserted until the end of the<br>bus cycle.<br>1 (Active during write)|
|Mask<br>1<br>—|—<br>Make this setting when using auto request<br>trigger.|

## (2) Level Output

Setting 001 in the AM bits of the CHCFG_n register enables level output. DACK0 remains asserted until DREQ0 is deasserted.

**==> picture [393 x 133] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>CHCFG_n.AM[2:0]                                                                                                                                     001<br>CHCFG_n.REQD<br>DREQ0<br>Internal request<br>DACK0<br>DMA Transfer                                                                                                           Read                                               Write<br>**----- End of picture text -----**<br>

**Figure 9.19 DACK0 Output Timing (AM[2:0] = 001, REQD = 0)**

**==> picture [390 x 125] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>CHCFG_n.AM[2:0]                                                                                                         001<br>CHCFG_n.REQD<br>DREQ0<br>Internal request<br>DACK0<br>DMA Transfer                                                                                          Read                                    Write<br>**----- End of picture text -----**<br>

**Figure 9.20 DACK0 Output Timing (AM[2:0] = 001, REQD = 1)**

## (3) Bus Cycle Output

Setting 010 in the AM bits of the CHCTRL_n register enables bus cycle output. DACK0 remains active for the duration of a bus cycle.

**==> picture [389 x 115] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>DREQ0<br>Internal request<br>CHCFG_n.REQD<br>DACK0<br>DMA Transfer                                                                                                      Read                                                                                   Write<br>**----- End of picture text -----**<br>

## **Figure 9.21 Bus Cycle Output Timing (REQD = 0)**

- In the read active mode (REQD = 0), DACK0 remains active from the time when a read request is output on the bus until one cycle after the final read data.

- When level detection is selected for DREQ0, DREQ0 remains disabled until the cycle following the end of the bus cycle.

The following signals trigger the rise and fall of DACK0:

Rise: Transfer start (MARVALID = 1)

Fall: Transfer end (MRLAST & MRREADY = 1)

**==> picture [390 x 114] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>DREQ0<br>Internal request<br>CHCFG_n.REQD<br>DACK0<br>DMA Transfer                                                       Read                                                                                       Write<br>**----- End of picture text -----**<br>

**Figure 9.22 Bus Cycle Output Timing (REQD = 1)**

- In the write active mode (REQD = 1), DACK0 remains active from the time when a write request is output until one cycle after the response to the final data is returned.

- When level detection is selected for DREQ0, DREQ0 remains disabled until the cycle following the end of the bus cycle.

The following signals trigger the rise and fall of DACK0:

Rise: Transfer start (MAWVALID = 1)

Fall: Transfer end (MBVALID & MBREADY = 1)

## 9.7.6 DMA Transfer End Output Function

TEND0 is a transaction completion signal that is sent to the source of a DMA transfer request. TEND0 is asserted as the same time as DACK0 for the last transfer transaction. Figure 9.23 shows the TEND0 output timing.

**==> picture [287 x 112] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>Last DMA transfer<br>Bus cycle DMA CPU DMA CPU CPU<br>DREQ0<br>DACK0<br>TEND0<br>**----- End of picture text -----**<br>

**Figure 9.23 TEND0 Output Timing**

## 9.7.7 DMA Transfer End Interrupt

The DMA transfer end interrupt is an interrupt request signal that indicates that a DMA transaction is completed. There is an independent DMA transfer end interrupt for each channel.

When the transfer of data equivalent to the total transfer byte count loaded to the CRTB (Current Transaction Byte) is completed, 1 is set in END of the CHSTAT_n register. In this case, when 0 is set in DEM of the CHCFG_n register, the DMA transfer end interrupt is output (n = 0 to 15). (When writeback is performed in link mode, the signal is output after the writeback operation.)

When 0 is set in LV of the header in the read descriptor in link mode, 1 is set in DER of the CHSTAT_n register. In this case, when 0 is set in DIM of the header, the DMA transfer end interrupt is output.

## **Table 9.20 Assertion Conditions of DMA Transfer End Interrupt**

|||**DMA Transfer End Interrupt  Mask**|
|---|---|---|
|**Source**|**Condition**|**Signal**|
|DMA transaction end|When the transfer of data equivalent to the total transfer byte|DEM bit of the CHCFG_n register|
||count loaded to the CRTB (Current Transaction Byte) is||
||completed with an OKAY response (or after the writeback||
||operation when writeback is performed in link mode)||
|Descriptor invalid|When 0 is set in LV of the header in the read descriptor in link|DIM bit of the header|
||mode while 0 is set in DIM of the header||

## 9.7.8 DMA Error Interrupt

If an error response is received for a DMA transfer or descriptor access, the DMAC regards it as an error and stops the transfer. Upon receiving an error response, the EN bit of the CHSTAT_n register of transferring channel n is cleared to 0 and 1 is set in the ER bit (n = 0 to 15). Also, the DMA error interrupt is output. The DMA error interrupt cannot be masked.

Once an error occurs, the data of the whole transfer cannot be guaranteed. Be sure to start the transaction again from the beginning by following the procedure below.

1. Set 1 in the SWRST bit of the CHCTRL_n register.

2. Set each register again.

## 9.7.9 Interval Count Function

The interval at which a DMA transfer is executed can be adjusted by setting the ITVL bit of the channel interval register (CHITVL_n). This function is intended to prevent the DMA controller from occupying the bus all the time.

When a read or write operation is completed, a countdown starts from the value set in CHITVL_n. The next internal request is not executed until the count value reaches 0.

The following figure shows an example of how this works.

**==> picture [396 x 192] intentionally omitted <==**

**----- Start of picture text -----**<br>
B φ<br>DMAREQ[0]<br>DMAREQ[1]<br>DMAACK[0]<br>DMAACK[1]<br>REQ0 internal request<br>REQ1 internal request<br>REQ0 internal request mask<br>REQ1 internal request mask<br>CHITVL0 0                                                     100   99     98     97         4       3       2       1       0<br>CHITVL1 0                          100   99     98     97     96     95     94         1       0<br>CH0 DMA Transfer Write Write<br>CH1 DMA Transfer Read Read<br>**----- End of picture text -----**<br>

**Figure 9.24 Interval Count**

## 9.7.10 Difference in Operation Due to the Transfer Size

## (1) When the Source Transfer Size Is Smaller

When the read of data equivalent to the destination data size is completed, the data is written to the destination. The following figure shows a timing chart where the source transfer size is 8 bits and the destination transfer size is 32 bits (in the case of rising edge detection).

**==> picture [394 x 117] intentionally omitted <==**

**----- Start of picture text -----**<br>
DMAREQ[0]<br>DMAACK[0]<br>REQD<br>SDS 0<br>DDS 2<br>CRTB_n 4 0<br>DMA Transfer Read Read Read Read Write<br>**----- End of picture text -----**<br>

**Figure 9.25 When the Source Transfer Size Is Smaller (LVL = 0, HIEN = 1, REQD = 0, SDS < DDS in CHCFG_n)**

## (2) When the Destination Transfer Size Is Smaller

Since the source transfer size is larger, multiple destination writes occur after a single source read. The following figure shows a timing chart where the source transfer size is 64 bits and the destination transfer size is 16 bits (in the case of rising edge detection) (1 is set in REQD of the CHCFG_n register).

**==> picture [394 x 116] intentionally omitted <==**

**----- Start of picture text -----**<br>
DMAREQ[0]<br>DMAACK[0]<br>REQD<br>SDS 3                                                3                                              3                                  3<br>DDS 1                                                1                                              1                                  1<br>CRTB_n 4                                                4                                              4                                        0<br>DMA Transfer Read Write Write Write Write<br>**----- End of picture text -----**<br>

**Figure 9.26 When the Destination Transfer Size Is Smaller (LVL = 0, HIEN = 1, REQD = 1, SDS > DDS in CHCFG_n)**

## (3) When the Source Transfer Size Is the Same as the Destination Transfer Size

Every time a DMA transfer request is detected, a source read and a destination write occur.

The following figure shows a timing chart where the source transfer size and the destination transfer size are both 8 bits (in the case of rising edge detection, with 1 set in REQD of the CHCFG_n register).

**==> picture [394 x 111] intentionally omitted <==**

**----- Start of picture text -----**<br>
DMAREQ[0]<br>DMAACK[0]<br>REQD<br>SDS 0<br>DDS 0<br>CRTB_n 2                                                    1                                                                                    0<br>DMA Transfer Read Write Read Write<br>**----- End of picture text -----**<br>

**Figure 9.27 When the Source Transfer Size Is the Same as the Destination Transfer Size (LVL = 0, HIEN = 1, REQD = 0, SDS = DDS in CHCFG_n)**

## 9.7.11 Transfer Status

The channel status register indicates the status of DMA transfer execution on a channel.

## (1) Suspend

A DMA transfer can be suspended by using the SETSUS bit of CHCTRL_n. In this case, if an ongoing bus cycle exists, the DMAC waits for that cycle to end before suspending the transfer. Writing 1 in the CLRSUS bit restores the DMA transfer from the suspend status.

**==> picture [391 x 171] intentionally omitted <==**

**----- Start of picture text -----**<br>
CHCTRL_n<br>register   SETEN<br>setting<br>STG<br>SETSUS<br>CLRSUS<br>CHSTAT_n<br>register EN<br>indication<br>level SUS Suspend status<br>Bus transfer status<br>Read      Write      Read     Write      Read                                               Write      Read<br>**----- End of picture text -----**<br>

**Figure 9.28 DMAC Suspend Status (Auto Request/Block Transfer)**

In the above case, the DMA transfer is suspended after the read transfer is completed.

If there is any ongoing DMA transfer, the suspend status starts when that transfer is completed. To make sure that the transfer is suspended, read the CHSTAT or DSTAT_SUS register, after setting SETSUS, and check that 1 is set in the SUS bit for the relevant channel.

## (2) Transfer Stop

If you write 1 to CLREN while a DMA transaction is in progress, you can stop the DMA transaction for the corresponding channel. For the post-stop processing, two modes are supported: one sweeps out the data remaining in the buffer when the transaction is stopped (SBE = 1) and the other does not (SBE = 0). One of these modes can be selected using the SBE bit of the CHCFG_n register. By default, SBE is set to 0.

When this sweep mode is enabled and CLREN is set to 1, and if a DMA transaction is stopped with data remaining in the DMAC buffer, the transaction is completed after the DMAC sweeps the data.

## (a) Transfer Stop (Buffer Sweep Disabled - SBE = 0)

If you set 1 in CLREN during a DMA transfer, the DMA transfer is stopped. The stop timing depends on the value set in REQD. After stopping a DMA transfer, be sure to set 1 in SWRST to clear the DMA internal status before setting the next transfer.

**==> picture [392 x 248] intentionally omitted <==**

**----- Start of picture text -----**<br>
CHCTRL_n<br>register SETEN<br>setting<br>CLREN<br>STG<br>SETSUS<br>CHCFG_n<br>register SBE<br>setting<br>CHSTAT_n<br>register SUS<br>indication<br>level<br>EN<br>TACT<br>Bus transfer status<br>Read Read  Read Read  Read suspend Read  Read Read<br>Write<br>Not executed<br>**----- End of picture text -----**<br>

**Figure 9.29 DMAC Transfer Stop**

- When the TACT bit is set to 0, you can check that the channel has been brought to a complete stop.

- If you stop an ongoing DMA transfer before it is completed, the DMA transfer end interrupt is not asserted.

- If 0 is set in REQD, the DMA transfer is stopped when the next read is completed. (If the buffer contains any data that can be written, the DMA transfer is stopped after the data is written.)

- If 1 is set in REQD, the DMA transfer is stopped when the next write is completed.

## (b) Transfer Stop (Buffer Sweep Enabled - SBE = 1)

If 1 is set in CLREN during a DMA transfer, the DMA transfer is stopped. When 0 is set in REQD, the DMA transfer is stopped after the DMAC sweeps (writes) the already read data. If 1 is set in REQD to use hardware requests, do not use the sweep mode. After stopping a DMA transfer, be sure to set 1 in SWRST to clear the DMAC internal status before setting the next transfer.

**==> picture [394 x 194] intentionally omitted <==**

**----- Start of picture text -----**<br>
CHCTRL_n<br>register SETEN<br>setting<br>CLREN<br>STG<br>SETSUS<br>CHCFG_n<br>register SBE<br>setting<br>CHSTAT_n<br>register SUS<br>indication<br>level EN<br>TACT<br>Bus transfer status<br>Read  Read Read Read Read Suspend        Read Read Read<br>Write Buffer sweep<br>**----- End of picture text -----**<br>

**Figure 9.30 DMA Transfer Stop (Buffer Sweep Mode)**

- When the TACT bit is set to 0, you can check that the channel has been brought to a complete stop.

- If you stop a transfer in sweep mode (SBE = 1) during the fifth read transfer by setting SETSUS and then CLREN, the read data is written before the DMA transfer is stopped.

## (c) Channel Stop Check Method

Even when you clear the EN bit to 0, you cannot stop the DMA transfer immediately, if the bus is already executing the transfer. Therefore, in order to make sure that the DMAC has been brought to a complete stop, you need to check that the EN bit and TACT bit are both set to 0.

## (d) Transfer Stop Procedure

The transfer stop procedure is described below.

1. Set 1 in SETSUS of CHCTRL_n.

2. Repeat polling until the SUS bit of CHSTAT_n is set to 1. (If EN is already set to 0, the DMAC has already been stopped. Go to step 6.)

3. Set 1 in CLREN of CHCTRL_n.

4. When 0 is set in SBE, the transfer is stopped according to the value of REQD. When 1 is set in SBE, the sweep mode is enabled. When 1 is set in SBE, set 0 in REQD.

5. Read CHSTAT_n to check that 0 is set in the TACT bit. When TACT is set to 0, it means that the DMAC has been brought to a complete stop. When TACT is set to 1, repeat polling until this bit is set to 0.

6. To execute the next DMA transfer after stopping a transfer, be sure to set 1 in the SWRST (software reset) bit of CHCTRL_n before the next DMA transfer starts.

**==> picture [227 x 438] intentionally omitted <==**

**----- Start of picture text -----**<br>
Suspend<br>Start<br>(transfer stop)<br>Set 1 in SETSUS of<br>CHCTRL_n<br>Read CHSTAT_n<br>Repeat polling until<br>SUS is set to 1<br>No EN = 1<br>Yes<br>SUS = 1<br>Yes<br>Set 1 in CLREN of<br>CHCTRL_n<br>SBE = 1 No<br>Yes<br>Sweep<br>No<br>Stop DMA<br>Repeat polling until<br>TACT is set to 0<br>(check that DMA has<br> stopped)<br>Set 1 in SWRST of<br>CHCTRL_n<br>Set DMA again<br>**----- End of picture text -----**<br>

**Figure 9.31 Transfer Stop Flow**

## 9.8 DMA Setting Examples

Setting examples applicable when DMA transfer is executed using the direct memory access controller are shown in the following.

The transfer conditions for these setting examples are as follows.

## **Table 9.21 Transfer Condition List for DMA Transfer Setting Examples**

|||**DMA Mode**|**Transfer Mode**|**Transfer Request**|
|---|---|---|---|---|
|Setting example|1|Register|Single|Hardware|
|Setting example|2|Register|Block|Software|
|Setting example|3|Register|Block|Software|
|||(continuous execution)|||
|Setting example|4|Link|Block|Software|

For details of the settings, see the individual setting examples.

## 9.8.1 Setting Example 1 (Register Mode/Hardware Request)

The following table shows a setting example applicable when DMA transfer is executed using the settings shown below.

**Table 9.22 DMA Transfer Setting Example 1**

|**Table 9.22**<br>**DMA Transfer Setting Example 1**|**Table 9.22**<br>**DMA Transfer Setting Example 1**|
|---|---|
|**Item**<br>**Description**||
|Channel used<br>3||
|DMA mode<br>Register||
|Transfer mode<br>Single transfer||
|Register set used<br>Next0||
|Source/destination<br>Source<br>Destination||
||Start address<br>1111_0000H<br>2222_0000H|
||Address direction<br>Increment<br>Increment|
||Data size<br>32 bits<br>32 bits|
|DMA transfer byte count<br>64 bytes||
|DMA transfer request<br>Rising edge detection by hardware||
|DMAACK signal<br>Level output during read||
|DMA transfer end interrupt mask<br>Not masked||
|CACHE setting<br>Default value||

## **Setting example 1**

N0SA = 1111_0000H (source address) N0DA = 2222_0000H (destination address) N0TB = 0000_0040H (transfer byte count)

CHCFG = 0002_2123H (configuration) CHITVL = 0000_0000H (interval) CHEXT = 0000_0000H (CACHE setting)

**==> picture [279 x 384] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>(setting example 1)<br>DCTRL ← 00000000H ⋅ Fixed priority<br>⋅ Source:        1111000H N0SA_3 ← 11110000H<br>⋅ Destination:  22220000H N0DA_3 ← 22220000H<br>⋅ Transfer size:  64 bytes  N0TB_3 ← 00000040H<br>⋅ Interval:  None CHCFG_3 ← 00022023H<br>⋅ AXI setting:  None CHITVL_3 ← 00000000H<br>CHEXT_3 ← 00000000H<br> CHCTRL_3  ← 00000008H ⋅ Clear the status<br>Set 1 in the EN<br>(DMA transfer enable) bit  CHCTRL_3  ← 00000001H<br>DMA transfer<br>DMAEND3 == 1<br>Check EN is set to "0"<br>Check CHSTAT_3<br>End<br>(setting example 1)<br>**----- End of picture text -----**<br>

**Figure 9.32 Setting Example 1**

## 9.8.2 Setting Example 2 (Register Mode/Software Request)

The following table shows a setting example applicable when DMA transfer is executed using the settings shown below.

**Table 9.23 DMA Transfer Setting Example 2**

|**Table 9.23**<br>**DMA Transfer Setting Example 2**|**Table 9.23**<br>**DMA Transfer Setting Example 2**|
|---|---|
|**Item**<br>**Description**||
|Channel used<br>2||
|Priority control<br>Round robin||
|DMA mode<br>Register||
|Transfer mode<br>Block transfer||
|Register set used<br>Next1||
|Source/destination<br>Source<br>Destination||
||Start address<br>0FFF_E000H<br>3333_0000H|
||Address direction<br>Increment<br>Increment|
||Data size<br>8 bits<br>256 bits|
|DMA transfer byte count<br>128 bytes||
|DMA transfer request<br>Auto request||
|DMAACK signal<br>Masked||
|DMA transfer end interrupt mask<br>Not masked||
|CACHE setting<br>Default value||

## **Setting example 2**

DCTRL = 0000_0001H (DMA setting)

N1SA = 0FFF_E000H (source address) N1DA = 3333_0000H (destination address) N1TB = 0000_0080H (transfer byte count)

CHCFG = 1045_0402H (configuration) CHITVL = 0000_0000H (interval) CHEXT = 0000_0000H (CACHE setting)

**==> picture [282 x 384] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>(setting example 2)<br>DCTRL ← 00000001H ⋅ Round robin<br>N1SA_2 ← 0FFFE000H<br>⋅ Source:        0FFFE000H<br>N1DA_2 ← 33330000H<br>⋅ Destination:  33330000H<br>N1TB_2 ← 00000080H<br>⋅ Transfer size:  128 bytes CHCFG_2 ← 10450402H<br>⋅ Interval:  None<br>CHITVL_2 ← 00000000H<br>⋅ AXI setting:  None CHEXT_2 ← 00000000H<br> CHCTRL_2  ← 00000008H ⋅ Clear the status<br>Set 1 in the EN<br>(DMA transfer enable)    CHCTRL_2  ← 00000005H<br>and STG bits<br>DMA transfer<br>DMAEND2 == 1<br>Check EN is set to "0"<br>Check CHSTAT_2<br>End<br>(setting example 2)<br>**----- End of picture text -----**<br>

**Figure 9.33 Setting Example 2**

## 9.8.3 Setting Example 3 (Register Mode/Continuous Execution)

The following table shows a setting example applicable when DMA transfer is executed using the settings shown below.

## **Table 9.24 DMA Transfer Setting Example 3**

|**Table 9.24**<br>**DMA Transfer Setting Example 3**|**Table 9.24**<br>**DMA Transfer Setting Example 3**|
|---|---|
|**Item**<br>**Description**||
|Channel used<br>1||
|Priority control<br>Round robin||
|DMA mode<br>Register||
|Transfer mode<br>Block transfer||
|Register set used<br>Use Next0 and then Next1 continuously||
|Next0|Source<br>Destination|
||Start address<br>1111_0000H<br>3333_0000H|
||Address direction<br>Fixed<br>Fixed|
||Data size<br>32 bits<br>512 bits|
||DMA transfer byte count<br>512 bytes|
|Next1|Source<br>Destination|
||Start address<br>2222_0000H<br>4444_0000H|
||Address direction<br>Fixed<br>Fixed|
||Data size<br>32 bits<br>512 bits|
||DMA transfer byte count<br>2048 bytes|
|DMA transfer request<br>Auto request||
|DMAACK signal<br>Not output||
|DMA transfer end interrupt mask<br>Mask the DMA transfer end interrupt upon completion of Next0||
|CACHE setting<br>Default value||

## **Setting example 3**

DCTRL = 0000_0001H (DMA setting)

N0SA = 1111_0000H (source address) N0DA = 3333_0000H (destination address) N0TB = 0000_0200H (transfer byte count)

N1SA = 2222_0000H (source address) N1DA = 4444_0000H (destination address) N1TB = 0000_0800H (transfer byte count)

CHCFG = 6176_2001H (configuration) CHITVL = 0000_0000H (interval) CHEXT = 0000_0000H (CACHE setting)

**==> picture [292 x 443] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>(setting example 3)<br>DCTRL ← 00000001H ⋅ Round robin<br>⋅ Source:        11110000H N0SA_1 ←  11110000H<br>⋅ Destination:  33330000H  N0DA_1 ← 33330000H<br>⋅ Transfer size:  512 bytes N0TB_1 ← 00000200H<br>N1SA_1 ← 22220000H ⋅ Source:        22220000H<br>N1DA_1 ← 44440000H ⋅ Destination:  44440000H<br>N1TB_1 ← 00000800H ⋅ Transfer size:  2048 bytes<br>CHCFG_1 ← 61762001H<br>⋅ Interval:  None CHITVL_1 ← 00000000H<br>⋅ AXI setting:  None CHEXT_1 ← 00000000H<br>CHCTRL_1 ← 00000008H ⋅ Clear the status<br>Set 1 in the EN<br>CHCTRL_1 ← 00000005H<br>(DMA transfer enable)<br>and STG bits<br>DMA transfer Execute NEXT0<br>DMA transfer Execute NEXT1<br>DMAEND1 == 1<br>Check EN is set to "0"<br>Check CHSTAT_1<br>End<br>(setting example 3)<br>**----- End of picture text -----**<br>

**Figure 9.34**

**Setting Example 3**

## 9.8.4 Setting Example 4 (Link Mode)

The following table shows a setting example applicable when DMA transfer is executed using the settings shown below.

## **Table 9.25 DMA Transfer Setting Example 4**

|**Item**|**Description**|
|---|---|
|Channel used|0|
|Priority control|Round robin|
|DMA mode|Link|
|Transfer mode|Block transfer|
|Register set used|—|
|Descriptor start address|0000_1000H|

**Table 9.26 DMA Transfer Setting Example 4 (Descriptor 1)**

|**Table 9.26**<br>**DMA Transfer Setting Example 4 (Descriptor 1)**|**Table 9.26**<br>**DMA Transfer Setting Example 4 (Descriptor 1)**|**Table 9.26**<br>**DMA Transfer Setting Example 4 (Descriptor 1)**|
|---|---|---|
|**Item**<br>**Description**|||
|Descriptor start address<br>0000_1000H|||
|Next descriptor start address<br>0000_2000H|||
|Transfer mode<br>Block transfer|||
|Next0||Source<br>Destination|
|||Start address<br>1111_0000H<br>3333_0000H|
|||Address direction<br>Increment<br>Increment|
|||Data size<br>32 bits<br>32 bits|
|||DMA transfer byte count<br>2048 bytes|
|DMA transfer request<br>Auto request trigger (STG)|||
|DMAACK signal<br>Not output|||
|DMA transfer end interrupt mask<br>Masked|||
|CACHE setting<br>Default value|||
|header|||
||DMA interrupt when LV = 1<br>Issued (DIM = 0)||
||LV writeback<br>Done (WBD = 0)||
||Next link address<br>Available (LE = 0)||
||Descriptor valid<br>Valid (LV = 1)||

## **Table 9.27 DMA Transfer Setting Example 4 (Descriptor 2)**

|**Table 9.27**<br>**DMA Transfer Setting Example 4 (Descriptor 2)**|**Table 9.27**<br>**DMA Transfer Setting Example 4 (Descriptor 2)**|**Table 9.27**<br>**DMA Transfer Setting Example 4 (Descriptor 2)**|
|---|---|---|
|**Item**<br>**Description**|||
|Descriptor start address<br>0000_2000H|||
|Next descriptor start address<br>0000_5000H|||
|Transfer mode<br>Block transfer|||
|Next0||Source<br>Destination|
|||Start address<br>4444_0000H<br>5555_0000H|
|||Address direction<br>Increment<br>Increment|
|||Data size<br>64 bits<br>256 bits|
|||DMA transfer byte count<br>1024 bytes|
|DMA transfer request<br>Auto request trigger (STG)|||
|DMAACK signal<br>Not output|||
|DMA transfer end interrupt mask<br>Masked|||
|CACHE setting<br>Default value|||
|header|||
||DMA interrupt when LV = 1<br>Issued (DIM = 0)||
||LV writeback<br>Done (WBD = 0)||
||Next link address<br>Available (LE = 0)||
||Descriptor valid<br>Valid (LV = 1)||

**Table 9.28 DMA Transfer Setting Example 4 (Descriptor 3)**

|**Table 9.28**<br>**DMA Transfer Setting Example 4 (Descriptor 3)**|**Table 9.28**<br>**DMA Transfer Setting Example 4 (Descriptor 3)**|**Table 9.28**<br>**DMA Transfer Setting Example 4 (Descriptor 3)**|
|---|---|---|
|**Item**<br>**Description**|||
|Descriptor start address<br>0000_5000H|||
|Next descriptor start address<br>—|||
|Transfer mode<br>Block transfer|||
|Next0||Source<br>Destination|
|||Start address<br>7777_0000H<br>AAAA_0000H|
|||Address direction<br>Increment<br>Increment|
|||Data size<br>512 bits<br>512 bits|
|||DMA transfer byte count<br>4096 bytes|
|DMA transfer request<br>Auto request trigger (STG)|||
|DMAACK signal<br>Not output|||
|DMA transfer end interrupt mask<br>Not masked|||
|CACHE setting<br>Default value|||
|header|||
||DMA interrupt when LV = 1<br>Issued (DIM = 0)||
||LV writeback<br>Done (WBD = 0)||
||Next link address<br>Not available (LE = 1)||
||Descriptor valid<br>Valid (LV = 1)||

## **Setting example 4**

DCTRL= 0000_0001H (DMA setting) NXLA = 0000_1000H (descriptor start address) CHCFG = 8000_0000H (configuration)

## **Table 9.29 Descriptor Setting**

||**Descriptor 1**|**Descriptor 2**|**Descriptor 3**|
|---|---|---|---|
|header|0000_0001H|0000_0001H|0000_0003H|
|SA (Source Address)|1111_0000H|4444_0000H|7777_0000H|
|DA (Destination Address)|3333_0000H|5555_0000H|AAAA_0000H|
|TB (Transaction Byte)|0000_0800H|0000_0400H|0000_1000H|
|CFG (Configuration)|8142_2008H|8145_3008H|8046_6008H|
|ITVL (Interval)|0000_0000H|0000_0000H|0000_0000H|
|EXT (Extension)|0000_0000H|0000_0000H|0000_0000H|
|NXLA (Next Link Address)|0000_2000H|0000_5000H|0000_0000H|

**==> picture [293 x 353] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>(setting example 4)<br>DCTRL ← 00000001H ⋅ Round robin<br>Start link address:  00001000H NXLA_0  ←  00001000<br>Set the link mode CHCFG_0  ← 80000000H<br> CHCTRL_0  ← 00000008H ⋅ Clear the status<br>Set 1 in the EN<br>(DMA transfer enable)    CHCTRL_0  ← 00000005H<br>and STG bits<br>Link mode operation<br>End of link mode<br>Check EN is set to "0"<br>Check CHSTAT_0<br>End<br>(setting example 4)<br>**----- End of picture text -----**<br>

**Figure 9.35 Setting Example 4**

## 9.8.5 Next Register Set Continuous Execution Setting

The following figure shows the flowchart for executing DMA transfers continuously by using two Next Register Sets in register mode. While a DMA transaction is being executed using one Next Register Set, the other Next Register Set is set in order to continue to execute DMA transfers.

**==> picture [383 x 113] intentionally omitted <==**

**----- Start of picture text -----**<br>
Slave  Set N0 Set N1 Set N0 Set N1 Set N0<br>interface<br>Load N0 Load N1 Load N0 Load N1<br>Master  Transfer N0 Transfer N1 Transfer N0 Transfer N1<br>interface<br>Continue Continue Continue Continue<br>The Next Register Set is set by the DMAEND interrupt  N0: Next0 Register Set<br>or status register polling N1: Next1 Register Set<br>**----- End of picture text -----**<br>

**Figure 9.36 Image of Next Register Set Continuous Execution**

**==> picture [306 x 481] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Set DCTRL<br>Set CHITVL<br>Set CHEXT<br> $CR=0<br>   Set CHCFG_n<br>  (other settings are optional)<br>    REN = 1, RSW = 1,<br>    RSEL = $CR, DEM = 0<br>Set register 0 (N0SA, N0DA, N0TB)<br>Set register 1 (N1SA, N1DA, N1TB) $CR (current register):<br>This variable is for RSEL control.<br>Use a general-purpose register of the CPU.<br>Set CHCTRL_n<br>  SWRST=1<br>Set CHCTRL_n<br>(other settings are optional)<br>    SETEN = 1<br>    STG = 1<br>DMA transfer in progress<br>Wait for DMAEND<br>Process data in register<br>($CR) area<br>All transfers  completed? Yes<br>No<br>End<br>Set CHCFG_n<br>(only when continuing)<br>    RSEL = ~$CR<br>    REN = 1<br>RSEL is automatically inverted when<br>DMA for one register area is completed.<br>Read CHSTAT_n It is necessary, however, to set RSEL<br>appropriately when setting REN.<br>$CR=~$CR No EN=0<br>Yes<br>If DMA ends unexpectedly<br>before REN is set again<br>Yes SR=0<br>No<br>Read CHCFG_n Read CHCFG_n<br>REN = 0 Yes REN = 0 Yes<br>Process data in   Process data in<br>register 0 area and   register 1 area and<br>register 1 area register 0 area<br>No No<br>All transfers  completed? Yes All transfers  completed? Yes<br>No No<br>$CR = 1 $CR = 0 $CR = 0 $CR = 1 End<br>**----- End of picture text -----**<br>

**Figure 9.37 Example of Continuous DMA Execution by Using a Next Register Set**

- Supplementary information

First, save the data of the register sets to be used for DMA transfers (0 (N0SA, N0DA, and N0TB) and 1 (N1SA, N1DA, and N1TB)) to a general-purpose register of the CPU (the values of this register is referred to as $CR for the sake of convenience).

Each time the DMA transfers for one register set are completed (the DMA transfer end interrupt is output), REN is automatically cleared to 0. In order to continue to execute DMA transfers, it is necessary to set REN of the CHCFG_n register every time the DMA transfer end interrupt is asserted. This register also contains the RSEL bit, and the value of this bit needs to be set appropriately as well. Therefore, use $CR.

In this mode, two Next Register Sets are executed continuously. However, if CLREN is not set before the DMA transaction is completed (the next DMA transfer end interrupt is output), continuous execution stops. In this case, you can check how much of data has been transferred, by reading the SR and EN bits of the CHSTAT_n register and the REN bit of the CHCFG_n register. To restart the DMA transaction, follow the flowchart shown above.

## 9.9 Note

## 9.9.1 Divided Output of DACK0 and TEND0

When transferring 4 bytes or more to an 8-bit or 16-bit external device or transferring 2 bytes or more to an 8-bit external device, each DMA transfer unit is divided into multiple bus cycles. Note that, if the setting is such that DMA transfer is divided into multiple bus cycles and CS is negated between bus cycles, the DACK0 output and the TEND0 output is divided to align data as with CS. Figure 9.38 shows an example.

**==> picture [396 x 284] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 T2 Taw T1 T2<br>CKIO<br>Address<br>CS<br>RD<br>Data<br>WE<br>DACK0<br>(Active low)<br>TEND0<br>(Active low)<br>WAIT<br>**----- End of picture text -----**<br>

**Figure 9.38 Example of TEND0 Divided Output Timing**

## 9.9.2 TEND0 Not Output

Note that TEND0 may not be output depending on the combination of the bits DDS[3:0], SDS[3:0] and REQD in the CHCFG_0 register.

Table 9.30 shows when TEND0 is not output and Figure 9.39 shows an operation example.

## **Table 9.30 Bit Combination when TEND0 Is Not Output**

**==> picture [483 x 312] intentionally omitted <==**

**----- Start of picture text -----**<br>
CHCFG_0 Register<br>REQD DDS SDS TEND0 Output<br>1 — — Output<br>0 DDS > SDS Output<br>DDS = SDS Output<br>DDS < SDS Not output<br>CKIO<br>CHCFG_0<br>REQD<br>DDS[3:0] 0<br>SDS[3:0] 2<br>DACK0<br>TEND0<br>TEND0 is not output<br>DMA Transfer Read Read Read Read Write Write<br>Figure 9.39 TEND0 Not Output<br>**----- End of picture text -----**<br>

## 9.9.3 Atomic Access (ARLOCK[1:0] and AWLOCK[1:0])

This module does not support atomic (locked or exclusive) access, that is, it only supports normal access. Signals ARLOCK[1:0] and AWLOCK[1:0] are fixed as follows and cannot be modified. ARLOCK[1:0], AWLOCK[1:0]: 00 (normal access)
