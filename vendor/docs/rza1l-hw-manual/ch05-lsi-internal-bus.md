# 5. LSI Internal Bus

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 91–116. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 5.1 LSI Internal Bus

## 5.1.1 Configuration

This LSI has two main buses: the north main bus where peripheral modules are connected and the south main bus where on-chip RAM and external ROM and RAM are connected. Figure 5.1 is a schematic diagram of the internal buses.

**==> picture [353 x 264] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>Cortex-A9 Bus masters<br>North main bus<br>Peripheral modules<br>Bus bridge<br>Bus masters<br>South main bus<br>Bus controller On-chip RAM<br>External ROM/RAM<br>**----- End of picture text -----**<br>

**Figure 5.1 Schematic Diagram of LSI Internal Bus**

## 5.1.2 Operation

Cortex-A9 has separate interfaces for the north main bus and south main bus. The addresses assigned to the north main bus are accessed through the north main bus interface, and those assigned to the south main bus are accessed through the south main bus interface.

When a bus master connected to the north main bus, except for Cortex-A9, accesses the on-chip RAM or external ROM or RAM, access is executed through the bus bridge for access from the north main bus to the south main bus. The bus masters connected to the south main bus cannot access an address assigned to the north main bus. The internal bus of this LSI operates in little endian.

## 5.2 North Main Bus

## 5.2.1 Configuration

Various peripheral modules are connected to the north main bus. Figure 5.2 shows the configuration of the north main bus.

**==> picture [386 x 262] intentionally omitted <==**

**----- Start of picture text -----**<br>
Cortex-A9 memory accesscontrollerDirect controllerEthernet codecunitJPEG* [2] Mediabuslocal* [1] CoreSight Captureengineunit<br>Write Write<br>buffer* [1] buffer<br>North main bus<br>SLV0 SLV1 SLV2 SLV3 SLV4 SLV5 SLV6 SLV7 SLV8<br>Write Write Write Write AXI64IC2 bus OpenVG [TM] - Write<br>buffer buffer buffer buffer compliantRenesas buffer<br>graphics<br>bufferWrite memory accesscontrollerDirect controllerInterrupt On-chipROM processor<br>Bus Bus<br>AHB32IC3 bus bridge 1 bridge 2<br>Peripheral Peripheral Peripheral Peripheral Peripheral<br>module module module module module<br>South main bus<br>Peripheral Peripheral Note 1. RZ/A1L only<br>module module Note 2. RZ/A1LU only<br>Peripheral bus 1 Peripheral bus 2 Peripheral bus 3 Peripheral bus 4 Peripheral bus 7<br>Peripheral bus 5 Peripheral bus 6<br>**----- End of picture text -----**<br>

**Figure 5.2 North Main Bus Configuration**

## 5.2.2 Features

Table 5.1 shows the features of the north main bus.

## **Table 5.1 North Main Bus**

|**Table 5.1**<br>**North Main Bus**||
|---|---|
|**Item**|**Description**|
|Bus protocol|AMBA®AXI protocol|
|Bus system configuration|AXI interconnect with multi-layer configuration for all channels|
|Bus clock frequency|Bφ|
|Bus width|64 bits|
|Arbitration|Round robin|

## 5.2.3 Peripheral Buses

Table 5.2 is a list of the peripheral buses connected to the north main bus.

## **Table 5.2 List of Peripheral Buses**

|**Item**|**Description**|
|---|---|
|Peripheral bus 1||
|Bus clock frequency|P0φ|
|Bus width|32 bits|
|Connected peripheral modules|Multi-function timer pulse unit 2|
||Realtime clock|
||Video display controller 5|
|Peripheral bus 2||
|Bus clock frequency|P0φ|
|Bus width|32 bits|
|Connected peripheral modules|Clock pulse generator|
||Interrupt controller|
||Direct memory access controller|
||OS timer channels 0 and 1|
||I2C bus interface channels 0 to 3|
||IEBus controller (RZ/A1L only)|
||LIN interface (RZ/A1L only)|
||General I/O ports|
|Peripheral bus 3||
|Bus clock frequency|P1φ|
|Bus width|32 bits|
|Connected peripheral modules|CAN interface|
||Media local bus (RZ/A1L only)|
||SD host interface channels 0 and 1|
||MMC host interface|

**Table 5.2 List of Peripheral Buses**

|**Item**|**Description**|
|---|---|
|Peripheral bus 4||
|Bus clock frequency|P1φ|
|Bus width|32 bits|
|Connected peripheral modules|Serial communication interface with FIFO channels 0 to 4|
||Serial communication interface channels 0 and 1|
||Renesas serial peripheral interface channels 0 to 2|
||Renesas SPDIF interface|
||CD-ROM decoder (RZ/A1L only)|
||A/D converter|
||USB2.0 host/function module channel 0|
||JPEG codec unit (RZ/A1LU only)|
|AXI64IC2 bus||
|Bus protocol|AMBA AXI protocol|
|Bus system configuration|AXI interconnect with multi-layer configuration for all channels|
|Bus clock frequency|Bφ|
|Bus width|64 bits|
|Arbitration|Round robin|
|AHB32IC3 bus||
|Bus protocol|AMBA AHB protocol|
|Bus clock frequency|Bφ|
|Bus width|32 bits|
|Peripheral bus 5||
|Bus clock frequency|P1φ|
|Bus width|32 bits|
|Connected peripheral modules|Serial sound interface channels 0 to 3|
||USB2.0 host/function module channel 1|
||SCUX|
|Peripheral bus 6||
|Bus clock frequency|Bφ|
|Bus width|32 bits|
|Connected peripheral modules|Ethernet controller|
||Capture engine unit|
||EthernetAVB (RZ/A1LU only)|
|Peripheral bus 7||
|Bus clock frequency|P1φ|
|Bus width|32 bits|
|Connected peripheral modules|CoreSight|

## 5.3 South Main Bus

## 5.3.1 Configuration

On-chip RAM and external ROM and RAM are connected to the south main bus. Figure 5.3 shows the configuration of the south main bus.

**==> picture [413 x 165] intentionally omitted <==**

**----- Start of picture text -----**<br>
North main bus<br>Video display Video display<br>controller 5 controller 5<br>IV1-, 3-, 5-BUS IV6-BUS<br>Ethernet Bus Bus<br>Cortex-A9 AXI128IC2 bus AXI128IC3 bus AVB* [1] bridge 1 bridge 2<br>South main bus<br>SLV0 SLV1 SLV2 SLV3 SLV4 SLV5 SLV6 SLV7<br>L2 cache memory On-chip On-chip On-chip On-chip On-chip On-chip<br>(L2C-310) retentiondata  large-capacityRAM large-capacityRAM large-capacityRAM large-capacityRAM large-capacityRAM* [2]<br>RAM page 0 page 1 page 2 page 3 page 4<br>Bus state SPI multi I/O<br>controller bus controller Note 1. RZ/A1LU only<br>Note 2. RZ/A1L and RZ/A1LU only<br>**----- End of picture text -----**<br>

**Figure 5.3 South Main Bus Configuration**

## 5.3.2 Features

Table 5.3 shows the features of the south main bus.

## **Table 5.3 South Main Bus**

|**Item**|**Description**|
|---|---|
|Bus protocol|AMBA AXI protocol|
|Bus system configuration|AXI interconnect with multi-layer configuration for all channels|
|Bus clock frequency|Bφ|
|Bus width|128 bits|
|Arbitration|Round robin|

## 5.3.3 Connected Buses

Table 5.4 is a list of the buses connected to the south main bus and their features.

## **Table 5.4 List of Buses Connected to South Main Bus and their Features**

|**Item**|**Description**|
|---|---|
|AXI128IC2 and AXI128IC3 buses||
|Bus protocol|AMBA AXI protocol|
|Bus system configuration|AXI interconnect with multi-layer configuration for all channels|
|Bus clock frequency|Bφ|
|Bus width|128 bits|
|Arbitration|Round robin|

## 5.4 Address Map

## Table 5.5 shows the address map of this LSI.

## **Table 5.5 Address Map**

|**Table 5.5**<br>**Address Map**||
|---|---|
|**Address**<br>**Area**<br>**Slave Area Viewed**<br>**from North Main Bus**<br>**Masters**|**Slave Area Viewed**<br>**from South Main Bus**<br>**Masters**|
|0xFFFF_0000 to<br>0xFFFF_FFFF<br>I/O area<br>ROM in SLV4*1|—|
|0xFD00_0000 to<br>0xFFFE_FFFF<br>Reserved area<br>—||
|0xFCFF_0000 to<br>0xFCFF_FFFF<br>I/O area<br>SLV0 *1||
|0xFCFE_0000 to<br>0xFCFE_FFFF<br>I/O area<br>SLV1*1||
|0xFC08_0000 to<br>0xFCFD_FFFF<br>Reserved area<br>—||
|0xFC00_0000 to<br>0xFC07_FFFF<br>I/O area<br>SLV6*2, *4||
|0xF000_2000 to<br>0xFBFF_FFFF<br>Reserved area<br>—||
|0xF000_0000 to<br>0xF000_1FFF<br>Cortex-A9 private area<br>—||
|0xE823_0000 to<br>0xEFFF_FFFF<br>Reserved area<br>—||
|0xE820_0000 to<br>0xE822_FFFF<br>I/O area<br>SLV4*1, *3||
|0xE805_0000 to<br>0xE81F_FFFF<br>Reserved area<br>—||
|0xE803_0000 to<br>0xE804_FFFF<br>I/O area<br>SLV2*1||
|0xE802_0000 to<br>0xE802_FFFF<br>Reserved area<br>—||
|0xE800_0000 to<br>0xE801_FFFF<br>I/O area<br>SLV3*1|—|
|0xE000_0000 to<br>0xE7FF_FFFF<br>Reserved area<br>—||
|0x6030_0000 to<br>0xDFFF_FFFF<br>Reserved area<br>—||
|0x6020_0000 to<br>0x602F_FFFF<br>On-chip large-capacity RAM page 4<br>mirror area (1 Mbyte) (RZ/A1L and RZ/A1LU only)<br>SLV7<br>0x6018_0000 to<br>0x601F_FFFF<br>On-chip large-capacity RAM page 3<br>mirror area (512 Kbytes)|SLV7|
||SLV6|
|0x6010_0000 to<br>0x6017_FFFF<br>On-chip large-capacity RAM page 2<br>mirror area (512 Kbytes)<br>SLV8<br>0x6008_0000 to<br>0x600F_FFFF<br>On-chip large-capacity RAM page 1<br>mirror area (512 Kbytes)<br>0x6002_0000 to<br>0x6007_FFFF<br>On-chip large-capacity RAM page 0<br>(including on-chip data retention RAM) mirror area<br>(512 Kbytes)<br>0x6000_0000 to<br>0x6001_FFFF|SLV5|
||SLV4|
||SLV3|
||SLV2|
|0x5C00_0000 to<br>0x5FFF_FFFF<br>Reserved area<br>—|—|

**Table 5.5 Address Map**

|**Table 5.5**<br>**Address Map**|||
|---|---|---|
|**Address**<br>**Area**|**Slave Area Viewed**<br>**from North Main Bus**<br>**Masters**|**Slave Area Viewed**<br>**from South Main Bus**<br>**Masters**|
|0x5800_0000 to<br>0x5BFF_FFFF<br>SPI multi I/O bus area<br>mirror area (64 Mbytes)|SLV7|SLV1|
|0x5400_0000 to<br>0x57FF_FFFF<br>CS5 space mirror area (64 Mbytes)||SLV0|
|0x5000_0000 to<br>0x53FF_FFFF<br>CS4 space mirror area (64 Mbytes)|||
|0x4C00_0000 to<br>0x4FFF_FFFF<br>CS3 space mirror area (64 Mbytes)|||
|0x4800_0000 to<br>0x4BFF_FFFF<br>CS2 space mirror area (64 Mbytes)|||
|0x4400_0000 to<br>0x47FF_FFFF<br>CS1 space mirror area (64 Mbytes)|||
|0x4080_0000 to<br>0x43FF_FFFF<br>CS0 space mirror area (64 Mbytes)<br>0x4000_0000 to<br>0x407F_FFFF|||
||—*5||
|0x3FFF_C000 to<br>0x3FFF_FFFF<br>I/O area|SLV8||
|0x3FEF_B000 to<br>0x3FFF_BFFF<br>Reserved area|—|—|
|0x3FEF_A000 to<br>0x3FEF_AFFF<br>I/O area|SLV8|SLV1|
|0x2030_0000 to<br>0x3FEF_9FFF<br>Reserved area|—|—|
|0x2020_0000 to<br>0x202F_FFFF<br>On-chip large-capacity RAM page 4<br>(1 Mbyte) (RZ/A1L and RZ/A1LU only)|SLV7|SLV7|
|0x2018_0000 to<br>0x201F_FFFF<br>On-chip large-capacity RAM page 3<br>(512 Kbytes)||SLV6|
|0x2010_0000 to<br>0x2017_FFFF<br>On-chip large-capacity RAM page 2<br>(512 Kbytes)|SLV8|SLV5|
|0x2008_0000 to<br>0x200F_FFFF<br>On-chip large-capacity RAM page 1<br>(512 Kbytes)||SLV4|
|0x2002_0000 to<br>0x2007_FFFF<br>On-chip large-capacity RAM page 0<br>(including on-chip data retention RAM) (512<br>Kbytes)<br>0x2000_0000 to<br>0x2001_FFFF||SLV3|
|||SLV2|
|0x1C00_0000 to<br>0x1FFF_FFFF<br>Reserved area|—|—|
|0x1800_0000 to<br>0x1BFF_FFFF<br>SPI multi I/O bus area<br>(64 Mbytes)|SLV8|SLV1|
|0x1400_0000 to<br>0x17FF_FFFF<br>CS5 space (64 Mbytes)||SLV0|
|0x1000_0000 to<br>0x13FF_FFFF<br>CS4 space (64 Mbytes)|||
|0x0C00_0000 to<br>0x0FFF_FFFF<br>CS3 space (64 Mbytes)|||
|0x0800_0000 to<br>0x0BFF_FFFF<br>CS2 space (64 Mbytes)|||
|0x0400_0000 to<br>0x07FF_FFFF<br>CS1 space (64 Mbytes)|||
|0x0000_0000 to<br>0x03FF_FFFF<br>CS0 space (64 Mbytes)|||

Note 1. Only Cortex-A9, the direct memory access controller, and CoreSight can access this area. If any other north main bus master accesses this area, a decode error will occur.

Note 2. Only Cortex-A9 and CoreSight can access this area. If any other north main bus master accesses this area, a decode error will occur.

Note 3. If any address from 0xE821_4800 to 0xE822_FFFF is accessed, a decode error or slave error will occur.

Note 4. A slave error may occur depending on the CoreSight state.

Note 5. Modules which are connected to the north main bus and capable of operating as bus masters are as follows.

ꞏ Direct memory access controller

ꞏ Ethernet controller

ꞏ Media local bus

ꞏ CoreSight

ꞏ Capture engine unit

These modules do not have access to addresses 0x4000_0000 to 0x407F_FFFF. If they attempt access, a decode error will occur. (RZ/A1L only)

Modules which are connected to the south main bus and capable of operating as bus masters are as follows. ꞏ Cortex-A9

ꞏ Video display controller 5

These modules can access the address range shown above.

Note 6. If the on-chip large-capacity RAM is accessed while access is disabled, a slave error will occur.

Note 7. If the area indicated as "" is accessed, a decode error or a slave error will occur.

Note 8. I/O areas should be accessed in the size specified for each slave module.

## 5.5 Address Remapping

## 5.5.1 Overview

Execution in Cortex-A9 jumps to an exception vector placed in addresses 0x0000_0000 to 0x0000_001C when an exception such as a reset or an interrupt occurs. The interrupt response time depends on the time to access the memory connected to this area, and when low-speed memory is connected, the overhead is large. To avoid this, the exception vectors can be remapped to the on-chip high-speed RAM by using the MMU or vector base address register, or the address remapping function can be used to allocate the addresses where the exception vectors are placed to the on-chip high-speed RAM.

Figure 5.4 show the address maps before and after address remapping.

**==> picture [346 x 246] intentionally omitted <==**

**----- Start of picture text -----**<br>
0x43FF_FFFF 0x43FF_FFFF<br>CS0 space  CS0 space<br>(64 Mbytes) (64 Mbytes)<br>mirror mirror<br>0x4000_0000 0x4000_0000<br>. .<br>. .<br>. .<br>0x202F_FFFF On-chip large-capacity  Address 0x202F_FFFF On-chip large-capacity<br>RAM remapping RAM * [1]<br>0x2000_0000 pages 0 to 4 (3 Mbytes) 0x2000_0000 pages 0 to 4 (3 Mbytes)<br>. .<br>. .<br>. .<br>0x07FF_FFFF 0x07FF_FFFF<br>CS1 space  CS1 space<br>(64 Mbytes) (64 Mbytes)<br>0x0400_0000 0x0400_0000<br>0x03FF_FFFF 0x03FF_FFFF CS0 space<br>0x00A0_0000 (54 Mbytes)<br>CS0 space  0x009F_FFFF Reserved area<br>(64 Mbytes) 0x002F_FFFF On-chip large-capacity<br>RAM * [2]<br>0x0000_0000 0x0000_0000 pages 0 to 4 (3 Mbytes)<br>**----- End of picture text -----**<br>

Note 1. The address range from 0x2020_0000 to 0x202F_FFFF (page 4) is reserved in the RZ/A1LC. Note 2. The address range from 0x0020_0000 to 0x002F_FFFF (page 4) is reserved in the RZ/A1LC.

**Figure 5.4 Address Remapping**

## 5.5.2 Operation

Addresses are remapped by setting the AXI128 bit in the remap register to 0. After address remapping, pages 0 to 4 (pages 0 to 3 in the RZ/A1LC) of the on-chip large-capacity RAM are allocated to addresses 0x0000_0000 to 0x009F_FFFF. Note that the address range from 0x0030_0000 to 0x009F_FFFF (0x0020_0000 to 0x009F_FFFF in the RZ/A1LC) is reserved. Do not access this area. To access the CS0 space after address remapping, use the mirror area for the CS0 space.

During address remapping, access to addresses 0x0000_0000 to 0x009F_FFFF is prohibited. Accordingly, to modify the remap register, use the following steps.

- (1) Stop the bus masters except for Cortex-A9,

or make settings so that addresses 0x0000_0000 to 0x009F_FFFF are never accessed.

- (2) Execute a program outside addresses 0x0000_0000 to 0x009F_FFFF.

- (3) After modifying the value of the remap register, execute a dummy read of the remap register.

## 5.6 AXI Interconnect

## 5.6.1 Configuration

The AXI interconnect in this LSI has a multi-layer configuration in all channels (five channels). Figure 5.5 shows a conceptual diagram of the AXI interconnect configuration.

**==> picture [315 x 272] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bus master 0 Bus master 1<br>AXI interconnect<br>Arbiter Arbiter<br>Arbiter Arbiter<br>Bus slave 0 Bus slave 1<br>**----- End of picture text -----**<br>

**Figure 5.5 Conceptual Diagram of AXI Interconnect Configuration**

## 5.6.2 Operation

In the AXI interconnect, the necessary wiring is prepared for connection between all bus masters and all bus slaves in all channels. When bus masters and slaves access bus slaves and masters, transfer will proceed after bus arbitration by the arbiter. The bus mastership priority changes in a round-robin manner. When multiple bus masters or slaves access different bus slaves or masters, multiple accesses can be executed in parallel. However, when multiple bus masters or slaves access a single bus slave or master at the same time, the bus arbiter executes bus arbitration. When a bus master or slave cannot obtain the bus mastership, it enters a wait state until the bus master or slave that has the bus mastership completes transfer unless the access destination bus master or slave cannot accept multiple transfers. When the destination bus master or slave can accept multiple transfers, bus arbitration is done again with the next transfer timing.

## 5.7 Bus Bridges

Access from the north main bus to the south main bus is executed through a bus bridge. There are two bus bridges and which bus bridge is used is determined depending on the slave area to be accessed. For assignment of the slave areas to be accessed, see Table 5.5, Address Map .

Each bus bridge can accept up to eight transfers at the same time. Out-of-order transfer is also supported. Therefore, when access to low-speed external ROM and access to on-chip high-speed RAM from different bus masters occur sequentially in this order, the on-chip RAM access can be done without waiting for completion of the previous external ROM access completion.

## 5.8 AXI Protocol Control Signals

The AXI protocol control signals can be set as desired for each bus master. For details of the AXI protocol control signals, refer to the AMBA AXI Protocol Specification prepared by Arm Ltd.

## 5.8.1 Bus Masters other than Cortex-A9, CoreSight, and the Direct Memory Access Controller

## (1) Cache Control Signals (ARCACHE[3:0] and AWCACHE[3:0])

Use the AXI bus control register (AXIBUSCTL) to make settings of the ARCACHE[3:0] and AWCACHE[3:0] signals for each bus master. Be sure to make settings while the target bus master does not use the AXI bus.

## (2) Response Signals (RRESP[1:0] and BRESP[1:0])

Use the AXI bus response error status register (AXIRERRST) to read the RRESP[1:0] and BRESP[1:0] signals received by each bus master. The register value is updated when a response error occurs. The status register value can be cleared to 00 through the AXI bus response error clear register (AXIRERRCLR).

In addition, enabling interrupts through the AXI bus response error interrupt control register (AXIRERRCTL) allows an interrupt to be generated when a response error occurs.

This interrupt should be used only for debugging purposes. Make sure that no response error occurs during system operation.

## (3) Protection unit information (ARPROT[2:0], AWPROT[2:0])

Signals ARPROT[2:0] and AWPROT[2:0] are fixed as follows and cannot be modified. ARPROT[2], AWPROT[2]: 0 (data access)

ARPROT[1], AWPROT[1]: 1 * (non-secure access)

ARPROT[0], AWPROT[0]: 0 (normal access)

Note: * For the EthernetAVB, signals ARPROT[1] and AWPROT[1] are fixed to 0 (secure access).

## (4) Atomic access (ARLOCK[1:0], AWLOCK[1:0])

Signals ARLOCK[1:0] and AWLOCK[1:0] are fixed as follows and cannot be modified. ARLOCK[1:0], AWLOCK[1:0]: 00 (normal access)

## 5.8.2 Cortex-A9

For details on the Cortex-A9, refer to the Arm Architecture Reference Manual.

## 5.8.3 CoreSight

For details on CoreSight, refer to the technical reference manual issued by Arm Ltd.

The bus master side (AHB access port) of CoreSight is connected to the main bus via the AHB-AXI bus conversion circuit.

The signals are converted as follows for connection to the AXI bus.

## (1) Cache control (ARCACHE[3:0], AWCACHE[3:0])

ARCACHE[3], AWCACHE[3]: 0 when HPROT[3] is 0, 1 when HPROT[3] is 1. ARCACHE[2], AWCACHE[2]: 0 when HPROT[3] is 0, 1 when HPROT[3] is 1. ARCACHE[1], AWCACHE[1]: Value of HPROT[3] (cacheable) ARCACHE[0], AWCACHE[0]: Value of HPROT[2] (bufferable)

## (2) Response unit (RRESP[1:0], BRESP[1:0])

OKAY is returned when RRESP[1:0] and BRESP[1:0] are 00 or 01. ERROR is returned when RRESP[1:0] and BRESP[1:0] are 10 or 11.

## (3) Protection unit information (ARPROT[2:0], AWPROT[2:0])

ARPROT[2], AWPROT[2]: Inverse of HPROT[0] (data/opcode) ARPROT[1], AWPROT[1]: Fixed to 1 (non-secure access) ARPROT[0], AWPROT[0]: Value of HPROT[1] (privileged)

## (4) Atomic access (ARLOCK[1:0], AWLOCK[1:0])

ARLOCK[1:0], AWLOCK[1:0]: Fixed to 00 (normal access)

## 5.8.4 Direct Memory Access Controller

For details on the direct memory access controller, refer to section 9, Direct Memory Access Controller .

## 5.8.5 Slave Area

The control signals are handled as follows by the modules in the slave area.

## (1) Cache control (ARCACHE[3:0], AWCACHE[3:0])

The L2 cache memory and write buffer refer to these signals. Other modules in the slave area do not refer to them.

## (2) Response unit (RRESP[1:0], BRESP[1:0])

See Table 5.5 , Address Map.

## (3) Protection unit information (ARPROT[2:0], AWPROT[2:0])

ARPROT[2], AWPROT[2] (instruction/data): The modules in the slave area do not refer to these signals. ARPROT[1], AWPROT[1] (non-secure/secure): The interrupt controller and L2 cache memory refer to these signals.

Other modules in the slave area do not refer to them.

ARPROT[0], AWPROT[0] (privileged/user): The modules in the slave area do not refer to these signals.

## (4) Atomic access (ARLOCK[1:0], AWLOCK[1:0])

This LSI does not support atomic access. Signals ARLOCK[1:0] and AWLOCK[1:0] should be fixed to 00 for normal access by the bus master. *

Note: * This restriction means that instructions for exclusive access (LDREX, STREX, LDREXB, STREXB, LDREXD, STREXD, LDREXH, STREXH) and semaphore instructions (SWP, SWPB) cannot be used by the Cortex-A9 in the internal non-cacheable areas.

## 5.9 Write Buffers

A write buffer is provided at each connection between the north main bus and a peripheral bus and at each connection between the media local bus and the north main bus, and CoreSight and the north main bus. When the AWCACHE[1:0] cache control signals are set to cache-enabled or buffer-enabled (either of the AWCACHE[1:0] signals is set to 1), the write buffer sends a write completion response to the bus master before accessing the slave area under the write buffer. At this time, even if a slave error response is returned from the slave area to be accessed, it is ignored.

## 5.10 Register Descriptions

Table 5.6 shows the registers related to the internal bus.

## **Table 5.6 Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Remap register|RMPR|R/W|H'0000_0003|H’FCFE_1A00|32|
|AXI bus control register 0|AXIBUSCTL0|R/W|H'0000_0000|H’FCFE_1A04|32|
|AXI bus control register 2|AXIBUSCTL2|R/W|H'0000_0000|H’FCFE_1A0C|32|
|AXI bus control register 5|AXIBUSCTL5|R/W|H’0000_0000|H’FCFE_1A18|32|
|(RZ/A1L only)||||||
|AXI bus control register 6|AXIBUSCTL6|R/W|H’0000_0000|H’FCFE_1A1C|32|
|AXI bus control register 7|AXIBUSCTL7|R/W|H’0000_0000|H’FCFE_1A20|32|
|AXI bus response error interrupt|AXIRERRCTL0|R/W|H’0000_0000|H’FCFE_1A30|32|
|control register 0||||||
|AXI bus response error interrupt|AXIRERRCTL2|R/W|H’0000_0000|H’FCFE_1A38|32|
|control register 2||||||
|AXI bus response error status|AXIRERRST0|R/W|H’0000_0000|H’FCFE_1A40|32|
|register 0||||||
|AXI bus response error status|AXIRERRST2|R/W|H’0000_0000|H’FCFE_1A48|32|
|register 2||||||
|AXI bus response error clear register|AXIRERRCLR0|R/W|H’0000_0000|H’FCFE_1A50|32|
|0||||||
|AXI bus response error clear register|AXIRERRCLR2|R/W|H’0000_0000|H’FCFE_1A58|32|
|2||||||

## 5.10.1 Remap Register (RMPR)

This register controls the address remapping function.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||—|—|—|—|—|—|—|—|—|—|—|—|—|—|AXI128|—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|1|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|2|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|1|||AXI128|1|R/W|AXI128 Address Remapping|
|||||||This bit enables or disables allocation of addresses H’0000_0000 to H’009F_FFFF|
|||||||to on-chip RAM pages 0 to 4 (pages 0 to 3 in the RZ/A1LC).|
|||||||0: Address remapping is enabled.|
|||||||1: Address remapping is disabled.|
|0|||—|1|R|Reserved|
|||||||This bit is always read as 1. The write value should always be 1.|

## 5.10.2 AXI Bus Control Register 0 (AXIBUSCTL0)

This register controls the cache operation for the JPEG codec unit (RZ/A1LU only) and Ethernet controller.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|JCUARCACHE[3:0]*||||—|—|—|—|JCUAWCACHE[3:0]*||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R/W|R/W|R/W|R/W|R|R|R|R|R/W|R/W|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||—|—|—|—||ETHARCACHE[3:0]|||—|—|—|—||ETHAWCACHE[3:0]|||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R/W|R/W|R/W|R/W|R|R|R|R|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 28|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|27 to 24|JCUARCA|0000|R/W|ARCACHE[3:0] Signals for JPEG Codec Unit|
||CHE[3:0]*|||These bits specify the system cache operation when the JPEG codec unit performs|
|||||read access. The values of these bits are used as the ARCACHE[3:0] signals for the|
|||||JPEG codec unit. Modify the values of these bits only while the JPEG codec unit|
|||||does not use the internal bus.|
|23 to 20|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|19 to 16|JCUAWCA|0000|R/W|AWCACHE[3:0] Signals for JPEG Codec Unit|
||CHE[3:0]*|||These bits specify the system cache operation when the JPEG codec unit performs|
|||||write access. The values of these bits are used as the AWCACHE[3:0] signals for|
|||||the JPEG codec unit. Modify the values of these bits only while the JPEG codec unit|
|||||does not use the internal bus.|
|15 to 12|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11 to 8|ETHARCA|0000|R/W|ARCACHE[3:0] Signals for Ethernet Controller|
||CHE|||These bits specify the system cache operation when the Ethernet controller|
||[3:0]|||performs read access. The values of these bits are used as the ARCACHE[3:0]|
|||||signals for the Ethernet controller. Modify the values of these bits only while the|
|||||Ethernet controller does not use the internal bus.|
|7 to 4|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|3 to 0|ETHAWCA|0000|R/W|AWCACHE[3:0] Signals for Ethernet Controller|
||CHE|||These bits specify the system cache operation when the Ethernet controller|
||[3:0]|||performs write access. The values of these bits are used as the AWCACHE[3:0]|
|||||signals for the Ethernet controller. Modify the values of these bits only while the|
|||||Ethernet controller does not use the internal bus.|

Note: * These bits are only present in the RZ/A1LU. For the RZ/A1L and RZ/A1LC, the write value should always be 0.

## 5.10.3 AXI Bus Control Register 2 (AXIBUSCTL2)

This register controls the cache operation for the capture engine unit.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19||18|17||16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—|—|—|—|—|—|—|—|—||—|—||—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0||0|0||0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R||R|R||R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3||2|1||0|
|||—|—|—|—|—|—|—|—|—|—|—|—||CEUAWCACHE[3:0]|||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0||0|0||0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R/W||R/W|R/W|R/W||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 4|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|3 to 0|CEUAWCA|0000|R/W|AWCACHE[3:0] Signals for Capture Engine Unit|
||CHE|||These bits specify the system cache operation when capture engine unit performs|
||[3:0]|||write access. The values of these bits are used as the AWCACHE[3:0] signals for|
|||||capture engine unit. Modify the values of these bits only while capture engine unit|
|||||does not use the internal bus.|

## 5.10.4 AXI Bus Control Register 5 (AXIBUSCTL5)

This register is only provided in the RZ/A1L.

This register controls the cache operation for the media local bus.

||Bit:|Bit:|31|||30|29||28|27<br>26|25<br>24<br>23<br>22<br>21<br>20|19|18|17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|||—|—||—|—<br>—|—<br>—<br>—<br>—<br>—<br>—|—|—|—<br>—||
||Initial value:||0|||0|0||0|0<br>0|0<br>0<br>0<br>0<br>0<br>0|0|0|0<br>0||
||R/W:||R|||R|R||R|R<br>R|R<br>R<br>R<br>R<br>R<br>R|R|R|R<br>R||
||Bit:||15|||14|13||12|11<br>10|9<br>8<br>7<br>6<br>5<br>4|3|2|1<br>0||
||||||||||||—<br>—|—|—|MLBAXCACHE||
||||—|||—|—||—|—<br>—|—<br>—<br>—<br>—|||[1:0]||
||Initial value:||0|||0|0||0|0<br>0|0<br>0<br>0<br>0<br>0<br>0|0|0|0<br>0||
||R/W:||R|||R|R||R|R<br>R|R<br>R<br>R<br>R<br>R<br>R|R|R|R/W<br>R/W||
|||||**Initial**||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**||**Description**||||||
|31 to 2|—|||All||0||R||Reserved||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||
|1, 0|MLBAXCA|||00||||R/W||AWCACHE[3:0] and ARCACHE[3:0] Signals for Media Local Bus||||||
||CHE|||||||||These bits specify the system cache operation when the media local bus performs||||||
||[1:0]|||||||||read or write access. The values of these bits||are used as||the AWCACHE[3:0] and||
|||||||||||ARCACHE[3:0] signals for the media local bus.||||||
|||||||||||The MLBAXCACHE[0] value is used as ARCACHE[0] and||||AWCACHE[0] without||
|||||||||||change.||||||
|||||||||||When MLBAXCACHE[1] = 0, the ARCACHE[3:1] and AWCACHE[3:1] signals are all||||||
|||||||||||set to 0.||||||
|||||||||||When MLBAXCACHE[1] = 1, the ARCACHE[3:1] and AWCACHE[3:1] signals are all||||||
|||||||||||set to 1.||||||
|||||||||||Modify the values of these bits only while the media|||local bus does not||use the|
|||||||||||internal bus.||||||

## 5.10.5 AXI Bus Control Register 6 (AXIBUSCTL6)

This register controls the cache operation for video display controller 5.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|VDC501ARCACHE[3:0]||||—|—|—|—|VDC501AWCACHE[3:0]||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R/W|R/W|R/W|R/W|R|R|R|R|R/W|R/W|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||—|—|—|—|VDC502ARCACHE[3:0]||||—|—|—|—|—|—|—|—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R/W|R/W|R/W|R/W|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 28|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|27 to 24|VDC501AR|0000|R/W|ARCACHE[3:0] Signals for Video Display Controller 5 IV3-BUS|
||CACHE|||These bits specify the system cache operation when the IV3-BUS of video display|
||[3:0]|||controller 5 performs read access. The values of these bits are used as the|
|||||ARCACHE[3:0] signals for the IV3-BUS of video display controller 5. Modify the|
|||||values of these bits only while video display controller 5 does not use the internal|
|||||bus.|
|23 to 20|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|19 to 16|VDC501AW|0000|R/W|AWCACHE[3:0] Signals for Video Display Controller 5 IV1-BUS|
||CACHE|||These bits specify the system cache operation when the IV1-BUS of video display|
||[3:0]|||controller 5 performs write access. The values of these bits are used as the|
|||||AWCACHE[3:0] signals for the IV1-BUS of video display controller 5. Modify the|
|||||values of these bits only while video display controller 5 does not use the internal|
|||||bus.|
|15 to 12|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11 to 8|VDC502AR|0000|R/W|ARCACHE[3:0] Signals for Video Display Controller 5 IV5-BUS|
||CACHE|||These bits specify the system cache operation when the IV5-BUS of video display|
||[3:0]|||controller 5 performs read access. The values of these bits are used as the|
|||||ARCACHE[3:0] signals for the IV5-BUS of video display controller 5. Modify the|
|||||values of these bits only while video display controller 5 does not use the internal|
|||||bus.|
|7 to 0|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 5.10.6 AXI Bus Control Register 7 (AXIBUSCTL7)

This register controls the cache operation for video display controller 5.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||—|—|—|—|VDC504ARCACHE[3:0]||||—|—|—|—|—|—|—|—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R/W|R/W|R/W|R/W|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 12|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11 to 8|VDC504AR|0000|R/W|ARCACHE[3:0] Signals for Video Display Controller 5 IV6-BUS|
||CACHE|||These bits specify the system cache operation when the IV6-BUS of video display|
||[3:0]|||controller 5 performs read access. The values of these bits are used as the|
|||||ARCACHE[3:0] signals for the IV6-BUS of video display controller 5. Modify the|
|||||values of these bits only while video display controller 5 does not use the internal|
|||||bus.|
|7 to 0|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 5.10.7 AXI Bus Response Error Interrupt Control Register 0 (AXIRERRCTL0)

This register controls AXI bus response error interrupts.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|JCUR|—|—|—|ETHR|—|—|—|—|—|—|—|—|
||||||ERREN*||||ERREN|||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R/W|R|R|R|R/W|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||—|—|—|—|—|—|—|CEUR|—|—|—|—|—|—|—|—|
||||||||||ERREN|||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R/W|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 29|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|28|JCURERR|0|R/W|Response Error Interrupt Enable for JPEG Codec Unit|
||EN*|||Enables or disables interrupt requests when access from the JPEG codec unit|
|||||generates a response error.|
|||||0: Interrupt requests are disabled.|
|||||1: Interrupt requests are enabled.|
|27 to 25|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|24|ETHRERR|0|R/W|Response Error Interrupt Enable for Ethernet Controller|
||EN|||Enables or disables interrupt requests when access from the Ethernet controller|
|||||generates a response error.|
|||||0: Interrupt requests are disabled.|
|||||1: Interrupt requests are enabled.|
|23 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|CEURERR|0|R/W|Response Error Interrupt Enable for Capture Engine Unit|
||EN|||Enables or disables interrupt requests when access from capture engine unit|
|||||generates a response error.|
|||||0: Interrupt requests are disabled.|
|||||1: Interrupt requests are enabled.|
|7 to 0|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

Note: * This bit is only present in the RZ/A1LU. For the RZ/A1L and RZ/A1LC, the write value should always be 0.

## 5.10.8 AXI Bus Response Error Interrupt Control Register 2 (AXIRERRCTL2)

This register controls AXI bus response error interrupts.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|VDC501|—|—|—|VDC502|—|—|—|—|—|—|—|VDC504|
||||||RERREN||||RERREN||||||||RERREN|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R/W|R|R|R|R/W|R|R|R|R|R|R|R|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||||—|—|||||
|||—|—|—|—|—|—|—|—|—|—|||—|—|—|—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|29|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|28|||VDC501|0|R/W|Response Error Interrupt Enable for Video Display Controller 5 IV1/3-BUS|
||||RERREN|||Enables or disables interrupt requests when access from the IV1-BUS or IV3-BUS|
|||||||of video display controller 5 generates a response error.|
|||||||0: Interrupt requests are disabled.|
|||||||1: Interrupt requests are enabled.|
|27|to|25|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|24|||VDC502|0|R/W|Response Error Interrupt Enable for Video Display Controller 5 IV5-BUS|
||||RERREN|||Enables or disables interrupt requests when access from the IV5-BUS of video|
|||||||display controller 5 generates a response error.|
|||||||0: Interrupt requests are disabled.|
|||||||1: Interrupt requests are enabled.|
|23|to|17|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|16|||VDC504|0|R/W|Response Error Interrupt Enable for Video Display Controller 5 IV6-BUS|
||||RERREN|||Enables or disables interrupt requests when access from the IV6-BUS of video|
|||||||display controller 5 generates a response error.|
|||||||0: Interrupt requests are disabled.|
|||||||1: Interrupt requests are enabled.|
|15|to|0|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

## 5.10.9 AXI Bus Response Error Status Register 0 (AXIRERRST0)

This register indicates occurrence of AXI bus response errors.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||JCURRESP||JCUBRESP||ETHRRESP||ETHBRESP||—|—|—|—|—|—|—|—|
|||[1:0]*||[1:0]*||[1:0]|||[1:0]|||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||—|—|—|—|—|—|CEUBRESP||—|—|—|—|—|—|—|—|
||||||||||[1:0]|||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31, 30|JCURRESP|00|R|RRESP[1:0] Signals for JPEG Codec Unit|
||[1:0]*|||These bits indicate the RRESP[1:0] signals received by the JPEG codec unit. The|
|||||values of these bits are updated when a response error occurs.|
|||||00: OKAY|
|||||10: SLVERR|
|||||11: DECERR|
|29, 28|JCUBRESP|00|R|BRESP[1:0] Signals for JPEG Codec Unit|
||[1:0]*|||These bits indicate the BRESP[1:0] signals received by the JPEG codec unit. The|
|||||values of these bits are updated when a response error occurs.|
|||||00: OKAY|
|||||10: SLVERR|
|||||11: DECERR|
|27, 26|ETHRRES|00|R|RRESP[1:0] Signals for Ethernet Controller|
||P[1:0]|||These bits indicate the RRESP[1:0] signals received by the Ethernet controller. The|
|||||values of these bits are updated when a response error occurs.|
|||||00: OKAY|
|||||10: SLVERR|
|||||11: DECERR|
|25, 24|ETHBRESP|00|R|BRESP[1:0] Signals for Ethernet Controller|
||[1:0]|||These bits indicate the BRESP[1:0] signals received by the Ethernet controller. The|
|||||values of these bits are updated when a response error occurs.|
|||||00: OKAY|
|||||10: SLVERR|
|||||11: DECERR|
|23 to 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9, 8|CEUBRES|00|R|BRESP[1:0] Signals for Capture Engine Unit|
||P[1:0]|||These bits indicate the BRESP[1:0] signals received by capture engine unit. The|
|||||values of these bits are updated when a response error occurs.|
|||||00: OKAY|
|||||10: SLVERR|
|||||11: DECERR|
|7 to 0|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

Note: * These bits are only present in the RZ/A1LU. For the RZ/A1L and RZ/A1LC, these bits are always read as 0. The write value should always be 0.

## 5.10.10 AXI Bus Response Error Status Register 2 (AXIRERRST2)

This register indicates occurrence of AXI bus response errors.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||VDC501RRESP||VDC501BRESP||VDC502RRESP||—|—|—|—|—|—|VDC504RRESP||—|—|
|||[1:0]||[1:0]||[1:0]||||||||[1:0]||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||||—|—|||||
|||—|—|—|—|—|—|—|—|—|—|||—|—|—|—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

||||**Initial**|||
|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|31,|30|VDC501RR|00|R|RRESP[1:0] Signals for Video Display Controller 5 IV3-BUS|
|||ESP|||These bits indicate the RRESP[1:0] signals received by the IV3-BUS of video|
|||[1:0]|||display controller 5. The values of these bits are updated when a response error|
||||||occurs.|
||||||00: OKAY|
||||||10: SLVERR|
||||||11: DECERR|
|29,|28|VDC501BR|00|R|BRESP[1:0] Signals for Video Display Controller 5 IV1-BUS|
|||ESP|||These bits indicate the BRESP[1:0] signals received by the IV1-BUS of video|
|||[1:0]|||display controller 5. The values of these bits are updated when a response error|
||||||occurs.|
||||||00: OKAY|
||||||10: SLVERR|
||||||11: DECERR|
|27,|26|VDC502RR|00|R|RRESP[1:0] Signals for Video Display Controller 5 IV5-BUS|
|||ESP|||These bits indicate the RRESP[1:0] signals received by the IV5-BUS of video|
|||[1:0]|||display controller 5. The values of these bits are updated when a response error|
||||||occurs.|
||||||00: OKAY|
||||||10: SLVERR|
||||||11: DECERR|
|25|to 20|—|All 0|R|Reserved|
||||||These bits are always read as 0. The write value should always be 0.|
|19,|18|VDC504RR|00|R|RRESP[1:0] Signals for Video Display Controller 5 IV6-BUS|
|||ESP|||These bits indicate the RRESP[1:0] signals received by the IV6-BUS of video|
|||[1:0]|||display controller 5. The values of these bits are updated when a response error|
||||||occurs.|
||||||00: OKAY|
||||||10: SLVERR|
||||||11: DECERR|
|17|to 0|—|All 0|R|Reserved|
||||||These bits are always read as 0. The write value should always be 0.|

## 5.10.11 AXI Bus Response Error Clear Register 0 (AXIRERRCLR0)

This register clears the AXI bus response error status.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||JCU||JCU||ETH||ETH|||||||||
|||—|RRESP|—|BRESP|—|RRESP|—|BRESP|—|—|—|—|—|—|—|—|
||||CLR*||CLR*||CLR||CLR|||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R/W|R|R/W|R|R/W|R|R/W|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||CEU|||||||||
|||—|—|—|—|—|—|—|BRESP|—|—|—|—|—|—|—|—|
||||||||||CLR|||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R/W|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|30|JCURRESP|0|R/W|JCURRESP[1:0] Clear|
||CLR*|||Writing 1 to this bit clears the JCURRESP[1:0] bits to 00.|
|||||This bit is always read as 0.|
|29|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|28|JCUBRESP|0|R/W|JCUBRESP[1:0] Clear|
||CLR*|||Writing 1 to this bit clears the JCUBRESP[1:0] bits to 00.|
|||||This bit is always read as 0.|
|27|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|26|ETHRRESP|0|R/W|ETHRRESP[1:0] Clear|
||CLR|||Writing 1 to this bit clears the ETHRRESP[1:0] bits to 00.|
|||||This bit is always read as 0.|
|25|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|24|ETHBRESP|0|R/W|ETHBRESP[1:0] Clear|
||CLR|||Writing 1 to this bit clears the ETHBRESP[1:0] bits to 00.|
|||||This bit is always read as 0.|
|23 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|CEUBRESP|0|R/W|CEUBRESP[1:0] Clear|
||CLR|||Writing 1 to this bit clears the CEUBRESP[1:0] bits to 00.|
|||||This bit is always read as 0.|
|7 to 0|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

Note: * This bit is only present in the RZ/A1LU. For the RZ/A1L and RZ/A1LC, the write value should always be 0.

## 5.10.12 AXI Bus Response Error Clear Register 2 (AXIRERRCLR2)

This register clears the AXI bus response error status.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||VDC501||VDC501||VDC502||||||||VDC504|||
|||—|RRESP|—|BRESP|—|RRESP|—|—|—|—|—|—|—|RRESP|—|—|
||||CLR||CLR||CLR||||||||CLR|||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R/W|R|R/W|R|R/W|R|R|R|R|R|R|R|R/W|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||||—|—|||||
|||—|—|—|—|—|—|—|—|—|—|||—|—|—|—|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|30|||VDC501|0|R/W|VDC501RRESP[1:0] Clear|
||||RRESP|||Writing 1 to this bit clears the VDC501RRESP[1:0] bits to 00.|
||||CLR|||This bit is always read as 0.|
|29|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|28|||VDC501|0|R/W|VDC501BRESP[1:0] Clear|
||||BRESP|||Writing 1 to this bit clears the VDC501BRESP[1:0] bits to 00.|
||||CLR|||This bit is always read as 0.|
|27|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|26|||VDC502|0|R/W|VDC502RRESP[1:0] Clear|
||||RRESP|||Writing 1 to this bit clears the VDC502RRESP[1:0] bits to 00.|
||||CLR|||This bit is always read as 0.|
|25|to|19|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|18|||VDC504|0|R/W|VDC504RRESP[1:0] Clear|
||||RRESP|||Writing 1 to this bit clears the VDC504RRESP[1:0] bits to 00.|
||||CLR|||This bit is always read as 0.|
|17|to|0|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

## 5.11 Interrupt Request

When a decode error or a slave error occurs, an AXI bus response error interrupt request (PRRI) is issued. An interrupt request is issued when a response is returned from the bus for which interrupt requests are enabled through the AXI bus response error interrupt control register (AXIRERRCTL). To check the response error type, read the AXI bus response error status register (AXIRERRST). To clear the interrupt request, clear the AXI bus response error status register through the AXI bus response error clear register (AXIRERRCLR).

This interrupt should be used only for debugging purposes. Make sure that no response error occurs during system operation.
