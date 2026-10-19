# 8. Bus State Controller

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 178–264. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

The bus state controller outputs control signals for various types of memory and external devices that are connected to the external address space. The functions of this module enable this LSI to connect directly with SRAM, SDRAM, and other memory storage devices, and external devices.

## 8.1 Features

1. External address space

   - A maximum of 64 Mbytes for each of areas CS0 to CS5.

   - Can specify the normal space interface, SRAM interface with byte selection, burst ROM (clocked synchronous or asynchronous), MPX-I/O, and SDRAM memory type  for each address space.

   - Can select the data bus width (8, 16, or 32 bits) for each of address spaces.

   - Controls insertion of wait cycles for each address space.

   - Controls insertion of wait cycles for each read access and write access.

   - Can set independent idle cycles during the continuous access for five cases: read-write (in same space/different spaces), read-read (in same space/different spaces), the first cycle is a write access.

2. Normal space interface

   - Supports the interface that can directly connect to the SRAM.

3. Burst ROM interface (clocked asynchronous)

   - High-speed access to the ROM that has the page mode function.

4. MPX-I/O interface

   - Can directly connect to a peripheral LSI that needs an address/data multiplexing.

5. SDRAM interface

   - Can set the SDRAM in up to two areas.

   - Multiplex output for row address/column address.

   - Efficient access by single read/single write.

   - High-speed access in bank-active mode.

   - Supports an auto-refresh and self-refresh.

   - Supports a power-down mode.

   - —Issues MRS and EMRS commands.

6. SRAM interface with byte selection

   - Can connect directly to a SRAM with byte selection.

7. Burst ROM interface (clocked synchronous)

   - Can connect directly to a burst ROM of the clocked synchronous type.

8. Refresh function

   - Supports the auto-refresh and self-refresh functions.

   - Specifies the refresh interval using the refresh counter and clock selection.

   - Can execute concentrated refresh by specifying the refresh counts (1, 2, 4, 6, or 8).

9. Usage as interval timer for refresh counter

   - Generates an interrupt request at compare match.

10. Detection of long wait state for access by the signal on the external WAIT pin.

   - A timeout detection condition is specifiable per CS space.

   - Once timeout is detected, the external WAIT function is disabled and a timeout detection interrupt request is issued.

Figure 8.1 shows a block diagram of this module.

**==> picture [255 x 457] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bus<br>mastership  CMNCR<br>controller<br>CS0WCR<br>WAIT controllerWait  ... ...<br>CS5WCR<br>TOSCOR0<br>... ...<br>TOSCOR5<br>TOSTR<br>TOENR<br>CS0 to CS5 Area  CS0BCR<br>controller ...<br>...<br>CS5BCR<br>...<br>A25 to A0,<br>D31 to D0,<br>BSRD, RD/, WE3WR to , WE0 Memory<br>RAS, CAS,  controller<br>CKE, DQMxx,<br>AH<br>SDCR<br>RTCSR<br>RTCNT<br>Refresh<br>controller<br>Comparator<br>RTCOR<br>[Legend] BSC<br>CMNCR: Common control register<br>CSnWCR: CSn space wait control register (n = 0 to 5)<br>CSnBCR: CSn space bus control register (n = 0 to 5)<br>SDCR: SDRAM control register<br>RTCSR: Refresh timer control/status register<br>RTCNT: Refresh timer counter<br>RTCOR: Refresh time constant register<br>TOSCORn: Timeout cycle constant register (n = 0 to 5)<br>TOSTR: Timeout status register<br>TOENR: Timeout enable register<br>Module bus<br>Internal bus<br>**----- End of picture text -----**<br>

**Figure 8.1 Block Diagram of Bus State Controller**

## 8.2 Input/Output Pins

Table 8.1 shows the pin configuration.

## **Table 8.1 Pin Configuration**

|**Name**|**Name**|**I/O**|**Function**|
|---|---|---|---|
|A25 to A0||Output|Address bus|
|D31 to D0||I/O|Data bus|
|BS||Output|Bus cycle start|
|CS0<br>|to CS5|Output|Chip select|
|RD/WR||Output|Read/write|
||||Connects to W<br>E<br>pins when SDRAM or SRAM with byte selection is connected.|
|RD||Output|Read pulse signal (read data output enable signal)|
|WE3<br>/DQMUU/AH||Output|Indicates that D31 to D24 are being written to.|
||||Connected to the byte select signal when a SRAM with byte selection is|
||||connected.|
||||Functions as the select signals for D31 to D24 when SDRAM is connected.|
||||Functions as the address hold signal when the MPX-I/O is used.|
|WE2<br>/DQMUL||Output|Indicates that D23 to D16 are being written to.|
||||Connected to the byte select signal when a SRAM with byte selection is|
||||connected.|
||||Functions as the select signals for D23 to D16 when SDRAM is connected.|
|WE1<br>/DQMLU||Output|Indicates that D15 to D8 are being written to.|
||||Connected to the byte select signal when a SRAM with byte selection is|
||||connected.|
||||Functions as the select signals for D15 to D8 when SDRAM is connected.|
|WE0<br>/DQMLL||Output|Indicates that D7 to D0 are being written to.|
||||Connected to the byte select signal when a SRAM with byte selection is|
||||connected.|
||||Functions as the select signals for D7 to D0 when SDRAM is connected.|
|RAS||Output|Connects to RAS<br>pin when SDRAM is connected.|
|CAS||Output|Connects to CAS<br>pin when SDRAM is connected.|
|CKE||Output|Connects to CKE pin when SDRAM is connected.|
|WAIT||Input|External wait input|

## 8.3 Area Overview

## 8.3.1 Address Map

In the architecture, this LSI has a 32-bit address space, which is divided into external memory spaces (SPI multi I/O bus space, large-capacity on-chip RAM, hold on-chip RAM, on-chip peripheral modules, and reserved areas) according to the upper bits of the address.

See section 5, LSI Internal Bus (including Secondary Cache) for how to enable or disable caching for the CS0 to CS5 external address spaces.

The kind of memory to be connected and the data bus width are specified in each partial space. The address map for the external address space is listed below.

## **Table 8.2 Address Map**

|**Table 8.2**<br>**Address Map**|||
|---|---|---|
|**Internal Address**|**Space**|**Memory to be Connected**|
|H'00000000 to H'03FFFFFF|CS0|Normal space, SRAM with byte selection, burst ROM (asynchronous or|
|||synchronous)|
|H'04000000 to H'07FFFFFF|CS1|Normal space, SRAM with byte selection|
|H'08000000 to H'0BFFFFFF|CS2|Normal space, SRAM with byte selection, SDRAM|
|H'0C000000 to H'0FFFFFFF|CS3|Normal space, SRAM with byte selection, SDRAM|
|H'10000000 to H'13FFFFFF|CS4|Normal space, SRAM with byte selection,|
|||burst ROM (asynchronous)|
|H'14000000 to H'17FFFFFF|CS5|Normal space, SRAM with byte selection, MPX-I/O|
|H'18000000 to H'3FFFFFFF|Other|SPI multi I/O bus space, large-capacity on-chip RAM, hold on-chip RAM, on-|
|||chip peripheral modules, reserved area*1|
|H'40000000 to H'407FFFFF|CS0 mirror|Access from the north main bus is not possible, but access from the south|
|||main bus is possible.*2|
|H'40800000 to H'43FFFFFF|CS0 mirror|Normal space, SRAM with byte selection, burst ROM (asynchronous or|
|||synchronous)|
|H'44000000 to H'47FFFFFF|CS1 mirror|Normal space, SRAM with byte selection|
|H'48000000 to H'4BFFFFFF|CS2 mirror|Normal space, SRAM with byte selection, SDRAM|
|H'4C000000 to H'4FFFFFFF|CS3 mirror|Normal space, SRAM with byte selection, SDRAM|
|H'50000000 to H'53FFFFFF|CS4 mirror|Normal space, SRAM with byte selection, burst ROM (asynchronous)|
|H'54000000 to H'57FFFFFF|CS5 mirror|Normal space, SRAM with byte selection, MPX-I/O|
|H'58000000 to H'FFFFFFFF|Other|SPI multi I/O bus space (mirror), large-capacity on-chip RAM (mirror), hold on-|
|||chip RAM (mirror), on-chip peripheral modules, reserved area*1|

Note 1. For the large-capacity on-chip RAM space and hold on-chip RAM space, access the addresses shown in section 40, On-Chip RAM. For the on-chip peripheral module space, access the addresses shown in section 46, List of Registers. Do not access addresses which are not described in these sections. Otherwise, the correct operation cannot be guaranteed.

Note 2. For details, see section 5, LSI Internal Bus.

## 8.3.2 Data Bus Width and Related Pin Setting for Each Area Depending on Boot Mode

The initial state of data bus width and settings of the pins related to this module depends on boot mode. For boot mode, refer to section 3, Boot Mode .

In boot mode 0, the state of area 0 is fixed to the state with bus width of 16 bits, because this LSI is started up by the program stored in the ROM connected to area 0. The initial states of areas 1 to 5 are the same as that of area 0, but the bus width can be changed by the program. Immediately after a power-on reset in these modes, some of the address and databus signals and the CS0, RD, and RD/WR signals are automatically selected by default as the functions of the corresponding pins, since these signals are required to read ROM data from area 0. With the exception of these pins, the general purpose pin function is selected by default, and other required pin functions must be specified by the program. Read access to area 0 is only permitted before the pin settings are completed.

In boot modes 1 to 3, the state of areas 0 to 5 can be changed from the initial state by the program, because the LSI is started by the program stored in the SPI serial memory, the NAND flash memory with the SD controller, or the NAND flash memory with the MMC controller. Since pin functions related to this module are not set automatically, they need to be set by the program. Do not access external address spaces before the pin settings are completed. Table 8.3 shows the initial state by areas 0 to 5 in boot modes 0 and 1 to 3.

The sample access waveforms shown in this section include the pins such as BS and WEn. They are the waveforms when pin functions are assigned to the general I/O ports. For example, when 16-bit bus width is used, setting for pin A1 is needed. When 8-bit bus width is used, setting for pins A1 and A0 is also needed. For details on pin function settings, see section 41, Ports .

**Table 8.3 Initial States by Areas in Boot Modes 0 and 1 to 3**

|**Boot Mode**|**Item**<br>**Area 0**<br>**Areas 1 to 5**|
|---|---|
|0|Data bus width<br>Fixed to 16 bits.<br>Not changeable.<br>16 bits. Can be changed by program.|
||Settings of pins related<br>to this module<br>Pins A20 to A1, D15 to D0, CS0<br>, RD/WR<br>, and RD<br>are set automatically. Other pins need<br>to be set by program.|
|1 to 3|Data bus width<br>32 bits. Can be changed by program.|
||Settings of pins related<br>to this module<br>General I/O function.<br>For external bus access, all the necessary pins need to be set by program.|

Note 1. If operation is to start in boot mode 0 and the connected boot ROM includes address bit A21 or higher-order address bits, the circuit board must include pull-down resistors for the corresponding address lines.

Note 2. The data-bus width may be limited by the type of memory in use. For details, see section 8.4.2, CSn Space Bus Control Register (CSnBCR) (n = 0 to 5).

## 8.4 Register Descriptions

Table 8.4 shows the register configuration of this module.

Do not access the areas until settings of the connected memory interface are completed.

## **Table 8.4 Register Configuration**

|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Common control register|CMNCR|R/W|H'00001018|H'3FFFC000|32|
|CS0 space bus control register|CS0BCR|R/W|H'36DB0C00*1|H'3FFFC004|32|
|CS1 space bus control register|CS1BCR|R/W|H'36DB0C00*1|H'3FFFC008|32|
|CS2 space bus control register|CS2BCR|R/W|H'36DB0C00*1|H'3FFFC00C|32|
|CS3 space bus control register|CS3BCR|R/W|H'36DB0C00*1|H'3FFFC010|32|
|CS4 space bus control register|CS4BCR|R/W|H'36DB0C00*1|H'3FFFC014|32|
|CS5 space bus control register|CS5BCR|R/W|H'36DB0C00*1|H'3FFFC018|32|
|CS0 space wait control register|CS0WCR|R/W|H'00000500|H'3FFFC028|32|
|CS1 space wait control register|CS1WCR|R/W|H'00000500|H'3FFFC02C|32|
|CS2 space wait control register|CS2WCR|R/W|H'00000500|H'3FFFC030|32|
|CS3 space wait control register|CS3WCR|R/W|H'00000500|H'3FFFC034|32|
|CS4 space wait control register|CS4WCR|R/W|H'00000500|H'3FFFC038|32|
|CS5 space wait control register|CS5WCR|R/W|H'00000500|H'3FFFC03C|32|
|SDRAM control register|SDCR|R/W|H'00000000|H'3FFFC04C|32|
|Refresh timer control/status|RTCSR|R/W|H'00000000|H'3FFFC050|32|
|register||||||
|Refresh timer counter|RTCNT|R/W|H'00000000|H'3FFFC054|32|
|Refresh time constant register|RTCOR|R/W|H'00000000|H'3FFFC058|32|
|Timeout cycle constant register 0|TOSCOR0|R/W|H'00000000|H’3FFFC060|32|
|Timeout cycle constant register 1|TOSCOR1|R/W|H'00000000|H’3FFFC064|32|
|Timeout cycle constant register 2|TOSCOR2|R/W|H'00000000|H’3FFFC068|32|
|Timeout cycle constant register 3|TOSCOR3|R/W|H'00000000|H’3FFFC06C|32|
|Timeout cycle constant register 4|TOSCOR4|R/W|H'00000000|H’3FFFC070|32|
|Timeout cycle constant register 5|TOSCOR5|R/W|H'00000000|H’3FFFC074|32|
|Timeout status register|TOSTR|R/W|H’00000000|H’3FFFC080|32|
|Timeout enable register|TOENR|R/W|H’00000000|H’3FFFC084|32|

Note 1. H'36DB0C00 in boot mode 0; H'36DB0E00 in boot modes 1 to 3

## 8.4.1 Common Control Register (CMNCR)

CMNCR is a 32-bit register that controls the common items for each area.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|TL0|-|-|-|AL0|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R/W|R|R|R|R/W|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|DPRTY[1:0]||-|-|-|-|-|-|-|HIZ<br>MEM|HIZ<br>CNT*|
|Initial value:|0|0|0|1|0|0|0|0|0|0|0|1|1|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R|R|R|R|R|R|R|R/W|R/W|

|||**Initial**||||||
|---|---|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**||||
|31 to 29|―|All 0|R|Reserved||||
|||||These bits are always read as 0. The write value should always be 0.||||
|28|TL0|0|R/W|Transfer End Level||||
|||||Specifies the TEND0 signal output is high active or low active.||||
|||||0: Low-active output from TEND0||||
|||||1: High-active output from TEND0||||
|27 to 25|―|All 0|R|Reserved||||
|||||These bits are always read as 0. The write value should always be 0.||||
|24|AL0|0|R/W|Specifies the DACK0 (acknowledge) signal output is high active or low||||
|||||active.||||
|||||0: Low-active output from DACK0||||
|||||1: High-active output from DACK0||||
|23 to 13|―|All 0|R|Reserved||||
|||||These bits are always read as 0. The write value should always be 0.||||
|12|―|1|R|Reserved||||
|||||This bit is always read as 1. The write|value should always|be 1.||
|11|―|0|R|Reserved||||
|||||This bit is always read as 0. The write|value should always|be 0.||
|10, 9|DPRTY[1:0]|00|R/W|DMA Burst Transfer Priority||||
|||||Specify the priority for a refresh request during DMA burst transfer.||||
|||||0*: Accepts a refresh request during DMA burst transfer.||||
|||||10: Does not accept a refresh request|during DMA burst transfer.|||
|||||11: Reserved (setting prohibited)||||
|8 to 5|―|All 0|R|Reserved||||
|||||These bits are always read as 0. The write value should always be 0.||||
|4, 3|―|All 1|R|Reserved||||
|||||These bits are always read as 1. The write value should always be 1.||||
|2|―|0|R|Reserved||||
|||||This bit is always read as 0. The write|value should always|be 0.||
|1|HIZMEM|0|R/W|High-Z Memory Control||||
|||||Specifies thepin state in software standby mode or deepstandby mode||||
|||||for A25 to A0, BS<br>, CS<br>n<br>, RD/WR<br>, WE<br>n<br>/DQMxx/AH<br>, and RD<br>.||||
|||||0: High impedance in software standby mode or deep standby mode.||||
|||||1: Driven in software standby mode or|deep standby mode|||
|0|HIZCNT*|0|R/W|High-Z Control||||
|||||Specifies the state in software standby mode or deep standby mode for||||
|||||CKE, RAS<br>, and CAS<br>.||||
|||||0: High impedance in software standby mode or deep standby mode for||||
|||||CKE, RAS<br>, and CAS<br>.||||
|||||1: Driven in software standby mode or|deep standby mode for CKE, RAS<br>,|||
|||||and CAS<br>.||||

Note: * For High-Z control of CKIO, see section 6, Clock Pulse Generator.

## 8.4.2 CSn Space Bus Control Register (CSnBCR) (n = 0 to 5)

CSnBCR is a 32-bit readable/writable register that specifies the memory connected to each space, the number of idle cycles between bus cycles, and the bus width.

Do not access external memory for the corresponding area until CSnBCR initial setting and pin setting are completed. Idle cycles may be inserted even when they are not specified. For details, see section 8.5.10, Wait between Access Cycles .

|Bit:|31||30|29|28|27<br>26|25|24|23||22|21||20|19|18||17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|||IWW[2:0]||IWRWD[2:0]||IWRWS[2:0]|||||IWRRD[2:0]||||IWRRS[2:0]|||
|Initial value:|0||0|1|1|0<br>1|1|0|1||1|0||1|1|0||1|1|
|R/W:|R||R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W||R/W|R/W||R/W|R/W|R/W||R/W|R/W|
|Bit:|15||14|13|12|11<br>10|9|8|7||6|5||4|3|2||1|0|
||-|||TYPE[2:0]||-<br>BSZ[1:0]||-|-||-|-||-|-|-||-|-|
|Initial value:|0||0|0|0|1<br>1*|0*|0|0||0|0||0|0|0||0|0|
|R/W:|R||R/W|R/W|R/W|R<br>R/W|R/W|R|R||R|R||R|R|R||R|R|
|Note:*B'10|||in boot|mode 0;|B'11 in|boot modes 1 to|3.|||||||||||||

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|||―|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|30|to|28|IWW[2:0]|011|R/W|Idle Cycles between Write-Read Cycles and Write-Write Cycles|
|||||||These bits specify the number of idle cycles to be inserted after the access|
|||||||to a memory that is connected to the space. The target access cycles are|
|||||||the write-read cycle and write-write cycle.|
|||||||000: No idle cycle inserted|
|||||||001: 1 idle cycle inserted|
|||||||010: 2 idle cycles inserted|
|||||||011: 4 idle cycles inserted|
|||||||100: 6 idle cycles inserted|
|||||||101: 8 idle cycles inserted|
|||||||110: 10 idle cycles inserted|
|||||||111: 12 idle cycles inserted|
|27|to|25|IWRWD[2:0]|011|R/W|Idle Cycles for Another Space Read-Write|
|||||||Specify the number of idle cycles to be inserted after the access to a|
|||||||memory that is connected to the space. The target access cycle is a read-|
|||||||write one in which continuous access cycles switch between different|
|||||||spaces.|
|||||||000: No idle cycle inserted|
|||||||001: 1 idle cycle inserted|
|||||||010: 2 idle cycles inserted|
|||||||011: 4 idle cycles inserted|
|||||||100: 6 idle cycles inserted|
|||||||101: 8 idle cycles inserted|
|||||||110: 10 idle cycles inserted|
|||||||111: 12 idle cycles inserted|
|24|to|22|IWRWS[2:0]|011|R/W|Idle Cycles for Read-Write in the Same Space|
|||||||Specify the number of idle cycles to be inserted after the access to a|
|||||||memory that is connected to the space. The target cycle is a read-write|
|||||||cycle of which continuous access cycles are for the same space.|
|||||||000: No idle cycle inserted|
|||||||001: 1 idle cycle inserted|
|||||||010: 2 idle cycles inserted|
|||||||011: 4 idle cycles inserted|
|||||||100: 6 idle cycles inserted|
|||||||101: 8 idle cycles inserted|
|||||||110: 10 idle cycles inserted|
|||||||111: 12 idle cycles inserted|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|21 to 19|IWRRD[2:0]|011|R/W|Idle Cycles for Read-Read in Another Space|
|||||Specify the number of idle cycles to be inserted after the access to a|
|||||memory that is connected to the space. The target cycle is a read-read|
|||||cycle of which continuous access cycles switch between different space.|
|||||000: No idle cycle inserted|
|||||001: 1 idle cycle inserted|
|||||010: 2 idle cycles inserted|
|||||011: 4 idle cycles inserted|
|||||100: 6 idle cycles inserted|
|||||101: 8 idle cycles inserted|
|||||110: 10 idle cycles inserted|
|||||111: 12 idle cycles inserted|
|18 to 16|IWRRS[2:0]|011|R/W|Idle Cycles for Read-Read in the Same Space|
|||||Specify the number of idle cycles to be inserted after the access to a|
|||||memory that is connected to the space. The target cycle is a read-read|
|||||cycle of which continuous access cycles are for the same space.|
|||||000: No idle cycle inserted|
|||||001: 1 idle cycle inserted|
|||||010: 2 idle cycles inserted|
|||||011: 4 idle cycles inserted|
|||||100: 6 idle cycles inserted|
|||||101: 8 idle cycles inserted|
|||||110: 10 idle cycles inserted|
|||||111: 12 idle cycles inserted|
|15|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|14 to 12|TYPE[2:0]|000|R/W|Specify the type of memory connected to a space.|
|||||000: Normal space|
|||||001: Burst ROM (clock asynchronous)|
|||||010: MPX-I/O|
|||||011: SRAM with byte selection|
|||||100: SDRAM|
|||||101: Reserved (setting prohibited)|
|||||110: Reserved (setting prohibited)|
|||||111: Burst ROM (clock synchronous)|
|||||For details for memory type in each area, see Table 8.2.|
|||||Note: When connecting the burst ROM to the CS0 space in boot mode 0,|
|||||change the CS0WCR register to the settings by the burst ROM|
|||||CS0WCR uses and then set TYPE[2:0] to the burst ROM setting. In|
|||||boot modes 1 to 3, memory access should be performed after|
|||||setting CS0BCR and CS0WCR.|
|11|―|1|R|Reserved|
|||||This bit is always read as 1. The write value should always be 1.|
|10, 9|BSZ[1:0]|10*|R/W|Data Bus Width Specification|
|||||Specify the data bus widths of spaces.|
|||||00: Reserved (setting prohibited)|
|||||01: 8-bit size|
|||||10: 16-bit size|
|||||11: 32-bit size|
|||||For MPX-I/O, selects bus width by address|
|||||Notes:1. If area 5 is specified as MPX-I/O, the bus width can be specified|
|||||as 8 bits or 16 bits by the address according to the SZSEL bit in|
|||||CS5WCR by specifying the BSZ[1:0] bits to 11. The fixed bus|
|||||width can be specified as 8 bits or 16 bits|
|||||2. In boot modes 0, the BSZ[1:0] bits settings in CS0BCR are|
|||||ignored.|
|||||3. If area 2 or area 3 is specified as SDRAM space, the bus width|
|||||can be specified as either 16 bits or 32 bits.|
|||||4. If area 0 is specified as clocked synchronous burst ROM space,|
|||||the bus width can be specified as either 16 bits or 32 bits.|
|8 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

Note: * B'10 in boot mode 0; B'11 in boot modes 1 to 3.

## 8.4.3 CSn Space Wait Control Register (CSnWCR) (n = 0 to 5)

CSnWCR specifies various wait cycles for memory access. The bit configuration of this register varies as shown below according to the memory type (TYPE2 to TYPE0) specified by the CSn space bus control register (CSnBCR). Specify CSnWCR before accessing the target area. Specify CSnBCR first, then specify CSnWCR.

## (1) Normal Space, SRAM with Byte Selection, and MPX-I/O

- CS0WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-*|BAS|-|-|-*|-*|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R|R|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|SW[1:0]|||WR[3:0]|||WM|-|-|-|-|HW[1:0]||
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R/W|R/W|

||||**Initial**|||||||
|---|---|---|---|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|||||
|31|to 22|―|All 0|R|Reserved|||||
||||||These bits are always read as 0. The write|value should always be 0.||||
|21||―*|0|R/W|Reserved|||||
||||||Set this bit to 0 when the interfaces for normal space or for SRAM with|||||
||||||byte selection are used.|||||
|20||BAS|0|R/W|SRAM with Byte Selection Byte Access Select|||||
||||||Specifies the WEn<br>and RD/WR<br>signal timing||when the SRAM interface|||
||||||with byte selection is used.|||||
||||||0: Asserts the WEn<br>signal at the read/write|timing and asserts the RD/WR||||
||||||signal duringthe write access cycle.|||||
||||||1: Asserts the WEn<br>signal during the read/write access cycle||||and asserts|
||||||the RD/WR<br>signal at the write timing.|||||
|19,|18|―|All 0|R|Reserved|||||
||||||These bits are always read as 0. The write|value should always be 0.||||
|17,|16|―*|All 0|R/W|Reserved|||||
||||||Set these bits to 0 when the interfaces for normal space or for SRAM with|||||
||||||byte selection are used.|||||
|15|to 13|―|All 0|R|Reserved|||||
||||||These bits are always read as 0. The write|value should always be 0.||||
|12,|11|SW[1:0]|00|R/W|Number of Delay Cycles from Address, CS<br>0<br>||Assertion to RD<br>, WE<br>n|||
||||||Assertion|||||
||||||Specifythe number of delay cycles from address and CS0<br>|||assertion to RD||
||||||and WEn<br>assertion.|||||
||||||00: 0.5 cycles|||||
||||||01: 1.5 cycles|||||
||||||10: 2.5 cycles|||||
||||||11: 3.5 cycles|||||

|||**Initial**|||||||
|---|---|---|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|||||
|10 to 7|WR[3:0]|1010|R/W|Number of Access Wait Cycles|||||
|||||Specify the number of|cycles that are necessary for read/write access.||||
|||||0000: No cycle|||||
|||||0001: 1 cycle|||||
|||||0010: 2 cycles|||||
|||||0011: 3 cycles|||||
|||||0100: 4 cycles|||||
|||||0101: 5 cycles|||||
|||||0110: 6 cycles|||||
|||||0111: 8 cycles|||||
|||||1000: 10 cycles|||||
|||||1001: 12 cycles|||||
|||||1010: 14 cycles|||||
|||||1011: 18 cycles|||||
|||||1100: 24 cycles|||||
|||||1101: Reserved (setting prohibited)|||||
|||||1110: Reserved (setting prohibited)|||||
|||||1111: Reserved (setting prohibited)|||||
|6|WM|0|R/W|External Wait Mask Specification|||||
|||||Specifies whether or not the external wait input is valid. The specification|||||
|||||by this bit is valid even when||the number of|access wait cycle is 0.||
|||||0: External wait input is valid|||||
|||||1: External wait input is ignored|||||
|5 to 2|―|All 0|R|Reserved|||||
|||||These bits are always|read as 0. The write value should always be 0.||||
|1, 0|HW[1:0]|00|R/W|Delay Cycles from RD<br>, WEn<br>||Negation to Address,CS0<br>Negation|||
|||||Specifythe number of delay cycles from RD<br>|||and WEn<br>|negation to address|
|||||and CS0<br>negation.|||||
|||||00: 0.5 cycles|||||
|||||01: 1.5 cycles|||||
|||||10: 2.5 cycles|||||
|||||11: 3.5 cycles|||||

Note: * In boot mode 0, to connect the burst ROM to the CS0 space and switch to burst ROM interface after activation, set the TYPE[2:0] bits in CS0BCR after setting the burst number by the bits 20 and 21 and the burst wait cycle number by the bits 16 and 17. Do not write 1 to the reserved bits other than above bits.

##  CS1WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|BAS|-||WW[2:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|SW[1:0]|||WR[3:0]|||WM|-|-|-|-|HW[1:0]||
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R/W|R/W|

|||**Initial**||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**||||||||
|31 to 21|―|All 0|R|Reserved||||||||
|||||These bits are|always read as 0. The write|||value should always be 0.||||
|20|BAS|0|R/W|SRAM with Byte Selection Byte|||Access Select|||||
|||||Specifies the WEn<br>and RD/WR<br>|||signal timing||when the SRAM interface|||
|||||with byte selection is used.||||||||
|||||0: Asserts the|WEn<br>|signal at the read/write||timing and asserts the|||RD/WR|
|||||signal duringthe||write access cycle.||||||
|||||1: Asserts the|WEn<br>|signal during the read/write access cycle and|||||asserts|
|||||the RD/WR<br>|signal at the write timing.|||||||
|19|―|0|R|Reserved||||||||
|||||This bit is always read as 0. The write value|||||should always be 0.|||
|18 to 16|WW[2:0]|000|R/W|Number of Write Access Wait Cycles||||||||
|||||Specify the number||of cycles that are necessary for write access.||||||
|||||000: The same cycles as WR[3:0] setting (number of read||||||access wait||
|||||cycles)||||||||
|||||001: No cycle||||||||
|||||010: 1 cycle||||||||
|||||011: 2 cycles||||||||
|||||100: 3 cycles||||||||
|||||101: 4 cycles||||||||
|||||110: 5 cycles||||||||
|||||111: 6 cycles||||||||
|15 to 13|―|All 0|R|Reserved||||||||
|||||These bits are|always read as 0. The write|||value should always be 0.||||
|12, 11|SW[1:0]|00|R/W|Number of Delay Cycles from Address, CS<br>n<br>|||||Assertion to RD<br>,WE<br>n|||
|||||Assertion||||||||
|||||Specifythe number||of delay cycles from address and CSn<br>||||assertion to RD||
|||||and WEn<br>assertion.||||||||
|||||00: 0.5 cycles||||||||
|||||01: 1.5 cycles||||||||
|||||10: 2.5 cycles||||||||
|||||11: 3.5 cycles||||||||

|||**Initial**||||||||
|---|---|---|---|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**||||||
|10 to 7|WR[3:0]|1010|R/W|Number of Read Access Wait Cycles||||||
|||||Specify the number of|cycles that are necessary for read access.|||||
|||||0000: No cycle||||||
|||||0001: 1 cycle||||||
|||||0010: 2 cycles||||||
|||||0011: 3 cycles||||||
|||||0100: 4 cycles||||||
|||||0101: 5 cycles||||||
|||||0110: 6 cycles||||||
|||||0111: 8 cycles||||||
|||||1000: 10 cycles||||||
|||||1001: 12 cycles||||||
|||||1010: 14 cycles||||||
|||||1011: 18 cycles||||||
|||||1100: 24 cycles||||||
|||||1101: Reserved (setting prohibited)||||||
|||||1110: Reserved (setting prohibited)||||||
|||||1111: Reserved (setting prohibited)||||||
|6|WM|0|R/W|External Wait Mask Specification||||||
|||||Specifies whether or not the external wait input is valid.|||||The specification|
|||||by this bit is valid even when||the number of|access wait cycle is 0.|||
|||||0: External wait input is valid||||||
|||||1: External wait input is ignored||||||
|5 to 2|―|All 0|R|Reserved||||||
|||||These bits are always|read as 0. The write value should always be 0.|||||
|1, 0|HW[1:0]|00|R/W|Delay Cycles from RD<br>, WEn<br>||Negation to Address, CSn<br>|||Negation|
|||||Specifythe number of delay cycles from RD<br>|||and WEn<br>|negation to address||
|||||and CSn<br>negation.||||||
|||||00: 0.5 cycles||||||
|||||01: 1.5 cycles||||||
|||||10: 2.5 cycles||||||
|||||11: 3.5 cycles||||||

##  CS2WCR, CS3WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|BAS|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-||WR[3:0]|||WM|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 21|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|20|BAS|0|R/W|SRAM with Byte Selection Byte Access Select|
|||||Specifies the WEn<br>and RD/WR<br>signal timing when the SRAM interface|
|||||with byte selection is used.|
|||||0: Asserts the WEn<br>signal at the read timing and asserts the RD/WR|
|||||signal during the write access cycle.|
|||||1: Asserts the WEn<br>signal during the read access cycle and asserts the|
|||||RD/WR<br>signal at the write timing.|
|19 to 11|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|10 to 7|WR[3:0]|1010|R/W|Number of Access Wait Cycles|
|||||Specify the number of cycles that are necessary for read/write access.|
|||||0000: No cycle|
|||||0001: 1 cycle|
|||||0010: 2 cycles|
|||||0011: 3 cycles|
|||||0100: 4 cycles|
|||||0101: 5 cycles|
|||||0110: 6 cycles|
|||||0111: 8 cycles|
|||||1000: 10 cycles|
|||||1001: 12 cycles|
|||||1010: 14 cycles|
|||||1011: 18 cycles|
|||||1100: 24 cycles|
|||||1101: Reserved (setting prohibited)|
|||||1110: Reserved (setting prohibited)|
|||||1111: Reserved (setting prohibited)|
|6|WM|0|R/W|External Wait Mask Specification|
|||||Specifies whether or not the external wait input is valid. The specification|
|||||by this bit is valid even when the number of access wait cycle is 0.|
|||||0: External wait input is valid|
|||||1: External wait input is ignored|
|5 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

##  CS4WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|BAS|-||WW[2:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|SW[1:0]|||WR[3:0]|||WM|-|-|-|-|HW[1:0]||
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R/W|R/W|

|||**Initial**|||||||
|---|---|---|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|||||
|31 to 21|―|All 0|R|Reserved|||||
|||||These bits are always read as 0. The write|||value should always be 0.||
|20|BAS|0|R/W|SRAM with Byte Selection Byte||Access Select|||
|||||Specifies the WEn<br>and RD/WR<br>||signal timing||when the SRAM interface|
|||||with byte selection is used.|||||
|||||0: Asserts the WEn<br>|signal at the read timing|||and asserts the RD/WR|
|||||signal duringthe|write access cycle.||||
|||||1: Asserts the WEn<br>|signal during the read access cycle and asserts the||||
|||||RD/WR<br>signal at|the write timing.||||
|19|―|0|R|Reserved|||||
|||||This bit is always read as 0. The write value||||should always be 0.|
|18 to 16|WW[2:0]|000|R/W|Number of Write Access Wait Cycles|||||
|||||Specify the number|of cycles that are necessary for write access.||||
|||||000: The same cycles as WR[3:0] setting (number of read access wait|||||
|||||cycles)|||||
|||||001: No cycle|||||
|||||010: 1 cycle|||||
|||||011: 2 cycles|||||
|||||100: 3 cycles|||||
|||||101: 4 cycles|||||
|||||110: 5 cycles|||||
|||||111: 6 cycles|||||
|15 to 13|―|All 0|R|Reserved|||||
|||||These bits are always read as 0. The write|||value should always be 0.||
|12, 11|SW[1:0]|00|R/W|Number of Delay Cycles from Address, CS<br>4<br>||||Assertion to RD<br>, WE|
|||||Assertion|||||
|||||Specifythe number|of delay cycles from address and CS4<br>assertion to RD||||
|||||and WE<br>assertion.|||||
|||||00: 0.5 cycles|||||
|||||01: 1.5 cycles|||||
|||||10: 2.5 cycles|||||
|||||11: 3.5 cycles|||||

|||**Initial**||||||||
|---|---|---|---|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**||||||
|10 to 7|WR[3:0]|1010|R/W|Number of Read Access Wait Cycles||||||
|||||Specify the number of|cycles that are necessary for read access.|||||
|||||0000: No cycle||||||
|||||0001: 1 cycle||||||
|||||0010: 2 cycles||||||
|||||0011: 3 cycles||||||
|||||0100: 4 cycles||||||
|||||0101: 5 cycles||||||
|||||0110: 6 cycles||||||
|||||0111: 8 cycles||||||
|||||1000: 10 cycles||||||
|||||1001: 12 cycles||||||
|||||1010: 14 cycles||||||
|||||1011: 18 cycles||||||
|||||1100: 24 cycles||||||
|||||1101: Reserved (setting prohibited)||||||
|||||1110: Reserved (setting prohibited)||||||
|||||1111: Reserved (setting prohibited)||||||
|6|WM|0|R/W|External Wait Mask Specification||||||
|||||Specifies whether or not the external wait input is valid.|||||The specification|
|||||by this bit is valid even when||the number of|access wait cycle is 0.|||
|||||0: External wait input is valid||||||
|||||1: External wait input is ignored||||||
|5 to 2|―|All 0|R|Reserved||||||
|||||These bits are always|read as 0. The write value should always be 0.|||||
|1, 0|HW[1:0]|00|R/W|Delay Cycles from RD<br>, WEn<br>||Negation to Address,CS4<br>|||Negation|
|||||Specifythe number of delay cycles from RD<br>|||and WEn<br>|negation to address||
|||||and CS4<br>negation.||||||
|||||00: 0.5 cycles||||||
|||||01: 1.5 cycles||||||
|||||10: 2.5 cycles||||||
|||||11: 3.5 cycles||||||

##  CS5WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|SZSEL|MPXW/<br>BAS|-||WW[2:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|SW[1:0]|||WR[3:0]|||WM|-|-|-|-|HW[1:0]||
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R/W|R/W|

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**|**Description**|
|---|---|
|31 to 22<br>―<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|21<br>SZSEL<br>0<br>R/W|MPX-I/O Interface Bus Width Specification<br>Specifies an address to select the bus width when the BSZ[1:0] of<br>CS5BCR are specified as 11. This bit is valid only when area 5 is specified<br>as MPX-I/O.<br>0: Selects the bus width by address A14<br>1: Selects the bus width by address A21<br>The relationship between the SZSEL bit and bus width selected by A14 or<br>A21 are summarized below.<br>**SZSEL**<br>**A14**<br>**A21**<br>**Bus Width**<br>0<br>0<br>Not affected<br>8 bits<br>0<br>1<br>Not affected<br>16 bits<br>1<br>Not affected<br>0<br>8 bits<br>1<br>Not affected<br>1<br>16 bits|
|20<br>MPXW<br>0<br>R/W|MPX-I/O Interface Address Wait<br>This bit setting is valid only when area 5 is specified as MPX-I/O. Specifies<br>the address cycle insertion wait for MPX-I/O interface.<br>0: Inserts no wait cycle<br>1: Inserts 1 wait cycle|
|20<br>BAS<br>0<br>R/W|SRAM with Byte Selection Byte Access Select<br>This bit setting is valid only when area 5 is specified as SRAM with byte<br>selection.<br>Specifies the WEn<br>and RD/WR<br>signal timing when the SRAM interface<br>with byte selection is used.<br>0: Asserts the WEn<br>signal at the read timing and asserts the RD/WR<br>signal duringthe write access cycle.<br>1: Asserts the WEn<br>signal during the read access cycle and asserts the<br>RD/WR<br>signal at the write timing.|
|19<br>―<br>0<br>R|Reserved<br>This bit is always read as 0. The write value should always be 0.|
|18 to 16<br>WW[2:0]<br>000<br>R/W|Number of Write Access Wait Cycles<br>Specify the number of cycles that are necessary for write access.<br>000: The same cycles as WR[3:0] setting (number of read access wait<br>cycles)<br>001: No cycle<br>010: 1 cycle<br>011: 2 cycles<br>100: 3 cycles<br>101: 4 cycles<br>110: 5 cycles<br>111: 6 cycles|
|15 to 13<br>―<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|

|||**Initial**|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|||||||||
|12, 11|SW[1:0]|00|R/W|Number of Delay Cycles from Address, CS<br>5<br>||||Assertion||to RD<br>, WE|||
|||||Assertion|||||||||
|||||Specifythe number of delay cycles from address and CS5<br>|||||||assertion to RD||
|||||and WEn<br>assertion when area 5 is specified||||as normal space or SRAM|||||
|||||with byte selection. Specify the number of delay cycles from the||||||||end of|
|||||address cycle (Ta3) to RD<br>and WEn<br>|assertion when area 5 is specified as||||||||
|||||MPx-I/O.|||||||||
|||||00: 0.5 cycles|||||||||
|||||01: 1.5 cycles|||||||||
|||||10: 2.5 cycles|||||||||
|||||11: 3.5 cycles|||||||||
|10 to 7|WR[3:0]|1010|R/W|Number of Read Access Wait Cycles|||||||||
|||||Specify the number of cycles that are necessary for read access.|||||||||
|||||0000: No cycle|||||||||
|||||0001: 1 cycle|||||||||
|||||0010: 2 cycles|||||||||
|||||0011: 3 cycles|||||||||
|||||0100: 4 cycles|||||||||
|||||0101: 5 cycles|||||||||
|||||0110: 6 cycles|||||||||
|||||0111: 8 cycles|||||||||
|||||1000: 10 cycles|||||||||
|||||1001: 12 cycles|||||||||
|||||1010: 14 cycles|||||||||
|||||1011: 18 cycles|||||||||
|||||1100: 24 cycles|||||||||
|||||1101: Reserved (setting prohibited)|||||||||
|||||1110: Reserved (setting prohibited)|||||||||
|||||1111: Reserved (setting prohibited)|||||||||
|6|WM|0|R/W|External Wait Mask Specification|||||||||
|||||Specifies whether or not the external wait input is valid. The specification|||||||||
|||||by this bit is valid even when the number of|||access wait cycle is|||||0.|
|||||0: External wait input is valid|||||||||
|||||1: External wait input is ignored|||||||||
|5 to 2|―|All 0|R|Reserved|||||||||
|||||These bits are always read as 0. The write||value should always||||||be 0.|
|1, 0|HW[1:0]|00|R/W|Delay Cycles from RD<br>, WEn<br>Negation to Address,CS5<br>Negation|||||||||
|||||Specifythe number of delay cycles from RD<br>|||and WEn<br>||negation to address||||
|||||and CS5<br>negation when area 5 is specified|||as normal||space or SRAM||||
|||||with byte selection. Specify the number of delay cycles from RD<br>||||||||and WEn|
|||||negation to CS5<br>negation when area 5 is specified as|||||MPx-I/O.||||
|||||00: 0.5 cycles|||||||||
|||||01: 1.5 cycles|||||||||
|||||10: 2.5 cycles|||||||||
|||||11: 3.5 cycles|||||||||

## (2) Burst ROM (Clocked Asynchronous)

- CS0WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|BST[1:0]||-|-|BW[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R|R|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-||W[3:0]|||WM|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R|R|

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**|**Description**|
|---|---|
|31 to 22<br>―<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|21, 20<br>BST[1:0]<br>00<br>R/W|Burst Count Specification<br>Specify the burst count for 16-byte or more access. These bits must not be<br>set to B'11, because B'11 setting is reserved.<br>**Bus Width**<br>**BST[1:0]**<br>**Burst count (16-byte access)**<br>8 bits<br>00<br>16 burst × one time<br>01<br>4 burst × four times<br>16 bits<br>00<br>8 burst × one time<br>01<br>2 burst × four times<br>10<br>4-4 or 2-4-2 burst<br>32 bits<br>xx<br>4 burst × one time<br>Note:<br>• For details, see Table 8.17, Relationship between Bus Width,<br>Access Size, and Number of Bursts.|
|19, 18<br>―<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|17, 16<br>BW[1:0]<br>00<br>R/W|Number of Burst Wait Cycles<br>Specify the number of wait cycles to be inserted between the second or<br>subsequent access cycles in burst access.<br>00: No cycle<br>01: 1 cycle<br>10: 2 cycles<br>11: 3 cycles|
|15 to 11<br>―<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|10 to 7<br>W[3:0]<br>1010<br>R/W|Number of Access Wait Cycles<br>Specify the number of wait cycles to be inserted in the first access cycle.<br>0000: No cycle<br>0001: 1 cycle<br>0010: 2 cycles<br>0011: 3 cycles<br>0100: 4 cycles<br>0101: 5 cycles<br>0110: 6 cycles<br>0111: 8 cycles<br>1000: 10 cycles<br>1001: 12 cycles<br>1010: 14 cycles<br>1011: 18 cycles<br>1100: 24 cycles<br>1101: Reserved (setting prohibited)<br>1110: Reserved (setting prohibited)<br>1111: Reserved (setting prohibited)|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|6|WM|0|R/W|External Wait Mask Specification|
|||||Specifies whether or not the external wait input is valid. The specification|
|||||by this bit is valid even when the number of access wait cycle is 0.|
|||||0: External wait input is valid|
|||||1: External wait input is ignored|
|5 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

##  CS4WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|BST[1:0]||-|-|BW[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R|R|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|SW[1:0]|||W[3:0]|||WM|-|-|-|-|HW[1:0]||
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R/W|R/W|

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**|**Description**|
|---|---|
|31 to 22<br>―<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|21, 20<br>BST[1:0]<br>00<br>R/W|Burst Count Specification<br>Specify the burst count for 16-byte or more access. These bits must not be<br>set to B'11, because B'11 setting is reserved.<br>**Bus Width**<br>**BST[1:0]**<br>**Burst count (16-byte access)**<br>8 bits<br>00<br>16 burst × one time<br>01<br>4 burst × four times<br>16 bits<br>00<br>8 burst × one time<br>01<br>2 burst × four times<br>10<br>4-4 or 2-4-2 burst<br>32 bits<br>xx<br>4 burst × one time<br>Note:<br>• For details, see Table 8.17, Relationship between Bus Width,<br>Access Size, and Number of Bursts.|
|19, 18<br>―<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|17, 16<br>BW[1:0]<br>00<br>R/W|Number of Burst Wait Cycles<br>Specify the number of wait cycles to be inserted between the second or<br>subsequent access cycles in burst access.<br>00: No cycle<br>01: 1 cycle<br>10: 2 cycles<br>11: 3 cycles|
|15 to 13<br>―<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|12, 11<br>SW[1:0]<br>00<br>R/W|Number of Delay Cycles from Address, CS<br>4<br>Assertion to RD<br>, WEn<br>Assertion<br>Specifythe number of delay cycles from address and CS4<br>assertion to RD<br>and WE<br>n<br>assertion.<br>00: 0.5 cycles<br>01: 1.5 cycles<br>10: 2.5 cycles<br>11: 3.5 cycles|

|||**Initial**||||||||
|---|---|---|---|---|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**||||||
|10 to 7|W[3:0]|1010|R/W|Number of Access Wait Cycles||||||
|||||Specify the number of|wait cycles to be inserted in the first access cycle.|||||
|||||0000: No cycle||||||
|||||0001: 1 cycle||||||
|||||0010: 2 cycles||||||
|||||0011: 3 cycles||||||
|||||0100: 4 cycles||||||
|||||0101: 5 cycles||||||
|||||0110: 6 cycles||||||
|||||0111: 8 cycles||||||
|||||1000: 10 cycles||||||
|||||1001: 12 cycles||||||
|||||1010: 14 cycles||||||
|||||1011: 18 cycles||||||
|||||1100: 24 cycles||||||
|||||1101: Reserved (setting prohibited)||||||
|||||1110: Reserved (setting prohibited)||||||
|||||1111: Reserved (setting prohibited)||||||
|6|WM|0|R/W|External Wait Mask Specification||||||
|||||Specifies whether or not the external wait input is valid.|||||The specification|
|||||by this bit is valid even when||the number of|access wait cycle is 0.|||
|||||0: External wait input is valid||||||
|||||1: External wait input is ignored||||||
|5 to 2|―|All 0|R|Reserved||||||
|||||These bits are always|read as 0. The write value should always be 0.|||||
|1, 0|HW[1:0]|00|R/W|Delay Cycles from RD<br>, WEn<br>||Negation to Address,CS4<br>|||Negation|
|||||Specifythe number of delay cycles from RD<br>|||and WEn<br>|negation to address||
|||||and CS4<br>negation.||||||
|||||00: 0.5 cycles||||||
|||||01: 1.5 cycles||||||
|||||10: 2.5 cycles||||||
|||||11: 3.5 cycles||||||

## (3) SDRAM*

- CS2WCR

||Bit:|31|30|29||28|27||26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|-||-|-||-|-|-|-|-|-|-|-|-|-|-||
||Initial value:|0|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0||
||R/W:|R|R|R||R|R||R|R|R|R|R|R|R|R|R|R|R||
||Bit:|15|14|13||12|11||10|9|8|7|6|5|4|3|2|1|0||
|||-|-|-||-|-||-|-|A2CL[1:0]||-|-|-|-|-|-|-||
||Initial value:|0|0|0||0|0||1|0|1|0|0|0|0|0|0|0|0||
||R/W:|R|R|R||R|R||R|R|R/W|R/W|R|R|R|R|R|R|R||
|||||**Initial**|||||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**|||||||||||
|31 to 11|―|||All 0|||R|||Reserved|||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||||
|10|―|||1|||R|||Reserved|||||||||||
|||||||||||This bit is always read as 1. The write||||||value should||always be 1.|||
|9|―|||0|||R|||Reserved|||||||||||
|||||||||||This bit is always read as 0. The write||||||value should||always be 0.|||
|8, 7|A2CL[1:0]|||10|||R/W|||CAS Latency for Area 2|||||||||||
|||||||||||Specify the CAS latency for area 2.|||||||||||
|||||||||||00: 1|cycle||||||||||
|||||||||||01: 2|cycles||||||||||
|||||||||||10: 3|cycles||||||||||
|||||||||||11: 4|cycles||||||||||
|6 to 0|―|||All 0|||R|||Reserved|||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||||

Note: * If only one area is connected to the SDRAM, specify area 3. In this case, specify area 2 as normal space or SRAM with byte selection.

##  CS3WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|WTRP[1:0]*||-|WTRCD[1:0]*||-|A3CL[1:0]||-|-|TRWL[1:0]*||-|WTRC[1:0]*||
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R/W|R/W|R|R/W|R/W|R|R/W|R/W|R|R|R/W|R/W|R|R/W|R/W|
|Note:<br>*|If both areas 2||and 3 are specified as SDRAM, WTRP[1:0], WTRCD[1:0], TRWL[1:0], and||||||||||WTRC[1:0] bit||settings are||
||used in both areas in common.||||||||||||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 15|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|14, 13|WTRP[1:0]*|00|R/W|Number of Auto-Precharge Completion Wait Cycles|
|||||Specify the number of minimum precharge completion wait cycles as|
|||||shown below.|
|||||From the start of auto-precharge and issuing of ACTV command for the|
|||||same bank|
|||||From issuing of the PRE/PALL command to issuing of the ACTV|
|||||command for the same bank|
|||||Till entering the power-down mode or deep power-down mode|
|||||From the issuing of PALL command to issuing REF command in auto|
|||||refresh mode|
|||||From the issuing of PALL command to issuing SELF command in self|
|||||refresh mode|
|||||The setting for areas 2 and 3 is common.|
|||||00: No cycle|
|||||01: 1 cycle|
|||||10: 2 cycles|
|||||11: 3 cycles|
|12|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|11, 10|WTRCD|01|R/W|Number of Wait Cycles between ACTV Command and READ(A)/WRIT(A)|
||[1:0]*|||Command|
|||||Specify the minimum number of wait cycles from issuing the ACTV|
|||||command to issuing the READ(A)/WRIT(A) command. The setting for|
|||||areas 2 and 3 is common.|
|||||00: No cycle|
|||||01: 1 cycle|
|||||10: 2 cycles|
|||||11: 3 cycles|
|9|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|8, 7|A3CL[1:0]|10|R/W|CAS Latency for Area 3|
|||||Specify the CAS latency for area 3.|
|||||00: 1 cycle|
|||||01: 2 cycles|
|||||10: 3 cycles|
|||||11: 4 cycles|
|6, 5|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|4, 3|TRWL[1:0]*|00|R/W|Number of Auto-Precharge Startup Wait Cycles|
|||||Specify the number of minimum auto-precharge startup wait cycles as|
|||||shown below.|
|||||Cycle number from the issuance of the WRITA command by this LSI|
|||||until the completion of auto-precharge in the SDRAM.|
|||||Equivalent to the cycle number from the issuance of the WRITA|
|||||command until the issuance of the ACTV command. Confirm that how|
|||||many cycles are required between the WRITA command receive in the|
|||||SDRAM and the auto-precharge activation, referring to each SDRAM|
|||||data sheet. And set the cycle number so as not to exceed the cycle|
|||||number specified by this bit.|
|||||Cycle number from the issuance of the WRIT command until the|
|||||issuance of the PRE command. This is the case when accessing|
|||||another low address in the same bank in bank active mode.|
|||||The setting for areas 2 and 3 is common.|
|||||00: No cycle|
|||||01: 1 cycle|
|||||10: 2 cycles|
|||||11: 3 cycles|
|2|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|1, 0|WTRC[1:0]*|00|R/W|Number of Idle Cycles from REF Command/Self-Refresh Release to|
|||||ACTV/REF/MRS Command|
|||||Specify the number of minimum idle cycles in the periods shown below.|
|||||From the issuance of the REF command until the issuance of the ACTV/|
|||||REF/MRS command|
|||||From releasing self-refresh until the issuance of the ACTV/REF/MRS|
|||||command.|
|||||The setting for areas 2 and 3 is common.|
|||||00: 2 cycles|
|||||01: 3 cycles|
|||||10: 5 cycles|
|||||11: 8 cycles|

Note: * If both areas 2 and 3 are specified as SDRAM, WTRP[1:0], WTRCD[1:0], TRWL[1:0], and WTRC[1:0] bit settings are used in both areas in common.

If only one area is connected to the SDRAM, specify area 3. In this case, specify area 2 as normal space or SRAM with byte selection.

## (4) Burst ROM (Clocked Synchronous)

- CS0WCR

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|BW[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-||W[3:0]|||WM|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 18|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|17, 16|BW[1:0]|00|R/W|Number of Burst Wait Cycles|
|||||Specify the number of wait cycles to be inserted between the second or|
|||||subsequent access cycles in burst access.|
|||||00: No cycle|
|||||01: 1 cycle|
|||||10: 2 cycles|
|||||11: 3 cycles|
|15 to 11|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|10 to 7|W[3:0]|1010|R/W|Number of Access Wait Cycles|
|||||Specify the number of wait cycles to be inserted in the first access cycle.|
|||||0000: No cycle|
|||||0001: 1 cycle|
|||||0010: 2 cycles|
|||||0011: 3 cycles|
|||||0100: 4 cycles|
|||||0101: 5 cycles|
|||||0110: 6 cycles|
|||||0111: 8 cycles|
|||||1000: 10 cycles|
|||||1001: 12 cycles|
|||||1010: 14 cycles|
|||||1011: 18 cycles|
|||||1100: 24 cycles|
|||||1101: Reserved (setting prohibited)|
|||||1110: Reserved (setting prohibited)|
|||||1111: Reserved (setting prohibited)|
|6|WM|0|R/W|External Wait Mask Specification|
|||||Specifies whether or not the external wait input is valid. The specification|
|||||by this bit is valid even when the number of access wait cycle is 0.|
|||||0: External wait input is valid|
|||||1: External wait input is ignored|
|5 to 0|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 8.4.4 SDRAM Control Register (SDCR)

SDCR specifies the method to refresh and access SDRAM, and the types of SDRAMs to be connected.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|A2ROW[1:0]||-|A2COL[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|DEEP|-|RFSH|RMODEPDOWN BACTV|||-|-|-|A3ROW[1:0]||-|A3COL[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R/W|R|R/W|R/W|R/W|R/W|R|R|R|R/W|R/W|R|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 21|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|20, 19|A2ROW[1:0]|00|R/W|Number of Bits of Row Address for Area 2|
|||||Specify the number of bits of row address for area 2.|
|||||00: 11 bits|
|||||01: 12 bits|
|||||10: 13 bits|
|||||11: Reserved (setting prohibited)|
|18|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|17, 16|A2COL[1:0]|00|R/W|Number of Bits of Column Address for Area 2|
|||||Specify the number of bits of column address for|
|||||area 2.|
|||||00: 8 bits|
|||||01: 9 bits|
|||||10: 10 bits|
|||||11: Reserved (setting prohibited)|
|15, 14|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|13|DEEP|0|R/W|Deep Power-Down Mode|
|||||This bit is valid for low-power SDRAM. If the RFSH or RMODE bit is set to|
|||||1 while this bit is set to 1, the deep power-down entry command is issued|
|||||and the low-power SDRAM enters the deep power-down mode.|
|||||0: Self-refresh mode|
|||||1: Deep power-down mode|
|12|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|11|RFSH|0|R/W|Refresh Control|
|||||Specifies whether or not the refresh operation of the SDRAM is|
|||||performed.|
|||||0: No refresh|
|||||1: Refresh|
|10|RMODE|0|R/W|Refresh Mode|
|||||Specifies whether to perform auto-refresh or self-refresh when the RFSH|
|||||bit is 1. When the RFSH bit is 1 and this bit is 1, self-refresh starts|
|||||immediately. When the RFSH bit is 1 and this bit is 0, auto-refresh starts|
|||||according to the contents that are set in registers RTCSR, RTCNT, and|
|||||RTCOR.|
|||||0: Auto-refresh is performed|
|||||1: Self-refresh is performed|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|9|PDOWN|0|R/W|Power-Down Mode|
|||||Specifies whether the SDRAM will enter the power-down mode after the|
|||||access to the SDRAM. With this bit being set to 1, after the SDRAM is|
|||||accessed, the CKE signal is driven low and the SDRAM enters the power-|
|||||down mode.|
|||||0: The SDRAM does not enter the power-down mode after being|
|||||accessed.|
|||||1: The SDRAM enters the power-down mode after being accessed.|
|8|BACTV|0|R/W|Bank Active Mode|
|||||Specifies to access whether in auto-precharge mode (using READA and|
|||||WRITA commands) or in bank active mode (using READ and WRIT|
|||||commands).|
|||||0: Auto-precharge mode (using READA and WRITA commands)|
|||||1: Bank active mode (using READ and WRIT commands)|
|||||Note: Bank active mode can be set only for area 3. When both areas 2|
|||||and 3 are set to SDRAM, specify the auto-precharge mode.|
|7 to 5|―|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4, 3|A3ROW[1:0]|00|R/W|Number of Bits of Row Address for Area 3|
|||||Specify the number of bits of the row address for|
|||||area 3.|
|||||00: 11 bits|
|||||01: 12 bits|
|||||10: 13 bits|
|||||11: Reserved (setting prohibited)|
|2|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|1, 0|A3COL[1:0]|00|R/W|Number of Bits of Column Address for Area 3|
|||||Specify the number of bits of the column address for area 3.|
|||||00: 8 bits|
|||||01: 9 bits|
|||||10: 10 bits|
|||||11: Reserved (setting prohibited)|

## 8.4.5 Refresh Timer Control/Status Register (RTCSR)

RTCSR specifies various items about refresh for SDRAM.

When RTCSR is written, the upper 16 bits of the write data must be H'A55A to cancel write protection.

The phase of the clock for incrementing the count in the refresh timer counter (RTCNT) is adjusted only by a power-on reset. Note that there is an error in the time until the compare match flag is set for the first time after the timer is started with the CKS[2:0] bits being set to a value other than B'000.

||Bit:|31|30|29||28|27|26|25<br>24<br>23<br>22|21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|-||-|-|-|-<br>-<br>-<br>-|-<br>-|-|-|-|-||
||Initial value:|0|0|0||0|0|0|0<br>0<br>0<br>0|0<br>0|0|0|0|0||
||R/W:|R|R|R||R|R|R|R<br>R<br>R<br>R|R<br>R|R|R|R|R||
||Bit:|15|14|13||12|11|10|9<br>8<br>7<br>6|5<br>4|3|2|1|0||
|||-|-|-||-|-|-|-<br>-<br>CMF<br>CMIE|CKS[2:0]||RRC[2:0]||||
||Initial value:|0|0|0||0|0|0|0<br>0<br>0<br>0|0<br>0|0|0|0|0||
||R/W:|R|R|R||R|R|R|R<br>R<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||
|31 to 8|―|||All 0|||R||Reserved|||||||
||||||||||These bits are always read as 0.|||||||
|7|CMF|||0|||R/W||Compare Match Flag|||||||
||||||||||Indicates that a compare|match occurs between the refresh timer counter||||||
||||||||||(RTCNT) and refresh time constant register (RTCOR). This bit is||||||set or|
||||||||||cleared in the following conditions.|||||||
||||||||||0: Clearing condition: When 0 is written in CMF after reading out||||||RTCSR|
||||||||||during CMF = 1.|||||||
||||||||||1: Setting condition: When the condition RTCNT = RTCOR is satisfied.|||||||
|6|CMIE|||0|||R/W||Compare Match Interrupt Enable|||||||
||||||||||Enables or disables CMF interrupt requests when the CMF bit in||||||RTCSR|
||||||||||is set to 1.|||||||
||||||||||0: Disables CMF interrupt requests.|||||||
||||||||||1: Enables CMF interrupt requests.|||||||
|5 to 3|CKS[2:0]|||000|||R/W||Clock Select|||||||
||||||||||Select the clock input to count-up the refresh timer counter (RTCNT).|||||||
||||||||||000: Stop the counting-up|||||||
||||||||||001: CKIOφ/4|||||||
||||||||||010: CKIOφ/16|||||||
||||||||||011: CKIOφ/64|||||||
||||||||||100: CKIOφ/256|||||||
||||||||||101: CKIOφ/1024|||||||
||||||||||110: CKIOφ/2048|||||||
||||||||||111: CKIOφ/4096|||||||
|2 to 0|RRC[2:0]|||000|||R/W||Refresh Count|||||||
||||||||||Specify the number of continuous refresh cycles, when the|||||refresh request||
||||||||||occurs after the coincidence of the values of|||the refresh timer counter||||
||||||||||(RTCNT) and the refresh|time constant register (RTCOR). These bits can||||||
||||||||||make the period of occurrence of refresh long.|||||||
||||||||||000: 1 time|||||||
||||||||||001: 2 times|||||||
||||||||||010: 4 times|||||||
||||||||||011: 6 times|||||||
||||||||||100: 8 times|||||||
||||||||||101: Reserved (setting prohibited)|||||||
||||||||||110: Reserved (setting prohibited)|||||||
||||||||||111: Reserved (setting prohibited)|||||||

## 8.4.6 Refresh Timer Counter (RTCNT)

RTCNT is an 8-bit counter that increments using the clock selected by bits CKS[2:0] in RTCSR. When RTCNT matches RTCOR, RTCNT is cleared to 0. The value in RTCNT returns to 0 after counting up to 255. When the RTCNT is written, the upper 16 bits of the write data must be H'A55A to cancel write protection.

**==> picture [483 x 188] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>- - - - - - - - - - - - - - - -<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>- - - - - - - -<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R/W R/W R/W R/W R/W R/W R/W R/W<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 8 ― All 0 R Reserved<br>These bits are always read as 0.<br>7 to 0 All 0 R/W 8-Bit Counter<br>**----- End of picture text -----**<br>

## 8.4.7 Refresh Time Constant Register (RTCOR)

RTCOR is an 8-bit register. When RTCOR matches RTCNT, the CMF bit in RTCSR is set to 1 and RTCNT is cleared to 0.

When the RFSH bit in SDCR is 1, a memory refresh request is issued by this matching signal. This request is maintained until the refresh operation is performed. If the request is not processed when the next matching occurs, the previous request is ignored.

When the CMIE bit in RTCSR is set to 1, an interrupt request is issued by this matching signal. The request continues to be output until the CMF bit in RTCSR is cleared. Clearing the CMF bit only affects the interrupt request and does not clear the refresh request. Therefore, a combination of refresh request and interval timer interrupt can be specified so that the number of refresh requests are counted by using timer interrupts while refresh is performed periodically. When RTCOR is written, the upper 16 bits of the write data must be H'A55A to cancel write protection.

**==> picture [483 x 187] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>- - - - - - - - - - - - - - - -<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>- - - - - - - -<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R/W R/W R/W R/W R/W R/W R/W R/W<br>Initial<br>Bit Bit Name Value R/W Description<br>31 to 8 ― All 0 R Reserved<br>These bits are always read as 0.<br>7 to 0 All 0 R/W 8-Bit Counter<br>**----- End of picture text -----**<br>

## 8.4.8 Timeout Cycle Constant Register (TOSCORn) (n = 0 to 5)

TOSCORn is a 16-bit register the value of which is effective when the WM bit in the CSn space wait control register (CSnWCR) is 0 and the corresponding bit in the timeout enable register (TOENR) is 1. When the number of cycles of waiting due to the signal on the eternal wait input pin matches the setting of TOSCORn, external wait input is disabled to end the cycle of access, the timeout status flag for the corresponding space in the timeout status register (TOSTR) is set, and a timeout detection interrupt request is generated. The timeout detection interrupt request is retained until the corresponding bit in TOENR is set to 0 or 0 is written to the timeout status flag for the corresponding space. Note that timeout detection is enabled even while the timeout status flag for the corresponding space in TOSTR is 1, and external wait input is disabled in response to a further timeout.

**==> picture [412 x 98] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>- - - - - - - - - - - - - - - -<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W<br>**----- End of picture text -----**<br>

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|16|―|All 0|R|Reserved|
|||||||These bits are always read as 0.|
|15|to|0||All 0|R/W|16-Bit Register|
|||||||H’0000: 65536 cycles|
|||||||H’0001: 1 cycle|
|||||||:|
|||||||H’FFFF: 65535 cycles|

## 8.4.9 Timeout Status Register (TOSTR)

TOSTOR is an 8-bit register that holds the timeout status flags for the CS spaces. When the WM bit in the CSn space wait control register (CSnWCR) is 0 and the corresponding bit in the timeout enable register (TOENR) is 1 and the number of cycles of waiting in response to the signal on the eternal wait input matches the setting of TOSCORn, the timeout status flag for the corresponding space is set and a timeout detection interrupt request is generated. The only writable value for the timeout status flags is 0, which clears the flag. Writing 1 to a flag is ignored.

||||Bit:|31|30|29||28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|-||-|-|-|-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-||
||||Initial value:|0|0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:|R|R|R||R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||
||||Bit:|15|14|13||12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
||||||||||||CS5T<br>CS4T<br>CS3T<br>CS2T<br>CS1T<br>CS0T||
|||||-|-|-||-|-|-|-<br>-<br>-<br>-<br>OSTF<br>OSTF<br>OSTF<br>OSTF<br>OSTF<br>OSTF||
||||Initial value:|0|0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:|R|R|R||R|R|R|R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||||||**Initial**|||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**||**Description**||
|31|to|6|―|||All 0|||R||Reserved||
||||||||||||These bits are always read as 0.||
|5|||CS5TOSTF|||0|||R/W||CS5 Space Timeout Status Flag||
||||||||||||Status flag that indicates that the number of cycles of waiting due to the||
||||||||||||input on the external wait pin during access to the CS5 space has||
||||||||||||matched the setting of the CS5 space timeout cycle constant register||
||||||||||||(TOSCOR5).This bit is set or cleared in the following conditions.||
||||||||||||0: Clearing condition||
||||||||||||When 0 is written in CS5TOSTF.||
||||||||||||1: Setting condition||
||||||||||||When the WM bit in the CS5 space wait control register (CS5WCR) is 0||
||||||||||||and the CS5TOEN bit in the timeout enable register (TOENR)|is 1, the|
||||||||||||number of cycles of waiting due to the input on the external wait pin||
||||||||||||during access to the CS5 space has matched the setting of TOSCOR5.||
|4|||CS4TOSTF|||0|||R/W||CS4 Space Timeout Status Flag||
||||||||||||Status flag that indicates that the number of cycles of waiting due to the||
||||||||||||input on the external wait pin during access to the CS4 space has||
||||||||||||matched the setting of the CS4 space timeout cycle constant register||
||||||||||||(TOSCOR4). For the condition to set or clear this bit, refer to the||
||||||||||||description of CS5TOSTF.||
|3|||CS3TOSTF|||0|||R/W||CS3 Space Timeout Status Flag||
||||||||||||Status flag that indicates that the number of cycles of waiting due to the||
||||||||||||input on the external wait pin during access to the CS3 space has||
||||||||||||matched the setting of the CS3 space timeout cycle constant register||
||||||||||||(TOSCOR3). For the condition to set or clear this bit, refer to the||
||||||||||||description of CS5TOSTF.||
|2|||CS2TOSTF|||0|||R/W||CS2 Space Timeout Status Flag||
||||||||||||Status flag that indicates that the number of cycles of waiting due to the||
||||||||||||input on the external wait pin during access to the CS2 space has||
||||||||||||matched the setting of the CS2 space timeout cycle constant register||
||||||||||||(TOSCOR2). For the condition to set or clear this bit, refer to the||
||||||||||||description of CS5TOSTF.||
|1|||CS1TOSTF|||0|||R/W||CS1 Space Timeout Status Flag||
||||||||||||Status flag that indicates that the number of cycles of waiting due to the||
||||||||||||input on the external wait pin during access to the CS1 space has||
||||||||||||matched the setting of the CS1 space timeout cycle constant register||
||||||||||||(TOSCOR1). For the condition to set or clear this bit, refer to the||
||||||||||||description of CS5TOSTF.||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|0|CS0TOSTF|0|R/W|CS0 Space Timeout Status Flag|
|||||Status flag that indicates that the number of cycles of waiting due to the|
|||||input on the external wait pin during access to the CS0 space has|
|||||matched the setting of the CS0 space timeout cycle constant register|
|||||(TOSCOR0). For the condition to set or clear this bit, refer to the|
|||||description of CS5TOSTF.|

## 8.4.10 Timeout Enable Register (TOENR)

TOENR is an 8-bit register that specifies enabling or disabling the detection of timeout for waiting in each of the CS spaces.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||||CS5|CS4|CS3|CS2|CS1|CS0|
||-|-|-|-|-|-|-|-|-|-|TOEN|TOEN|TOEN|TOEN|TOEN|TOEN|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|6|―|All 0|R|Reserved|
|||||||These bits are always read as 0.|
|5|||CS5TOEN|0|R/W|CS5 Space Timeout Detection Enable|
|||||||Specifies enabling or disabling the detection of timeout for waiting in the|
|||||||CS5 space.|
|||||||0: The timeout detection is disabled.|
|||||||1: The timeout detection is enabled.|
|4|||CS4TOEN|0|R/W|CS4 Space Timeout Detection Enable|
|||||||Specifies enabling or disabling the detection of timeout for waiting in the|
|||||||CS4 space.|
|||||||0: The timeout detection is disabled.|
|||||||1: The timeout detection is enabled.|
|3|||CS3TOEN|0|R/W|CS3 Space Timeout Detection Enable|
|||||||Specifies enabling or disabling the detection of timeout for waiting in the|
|||||||CS3 space.|
|||||||0: The timeout detection is disabled.|
|||||||1: The timeout detection is enabled.|
|2|||CS2TOEN|0|R/W|CS2 Space Timeout Detection Enable|
|||||||Specifies enabling or disabling the detection of timeout for waiting in the|
|||||||CS2 space.|
|||||||0: The timeout detection is disabled.|
|||||||1: The timeout detection is enabled.|
|1|||CS1TOEN|0|R/W|CS1 Space Timeout Detection Enable|
|||||||Specifies enabling or disabling the detection of timeout for waiting in the|
|||||||CS1 space.|
|||||||0: The timeout detection is disabled.|
|||||||1: The timeout detection is enabled.|
|0|||CS0TOEN|0|R/W|CS0 Space Timeout Detection Enable|
|||||||Specifies enabling or disabling the detection of timeout for waiting in the|
|||||||CS0 space.|
|||||||0: The timeout detection is disabled.|
|||||||1: The timeout detection is enabled.|

## 8.5 Operation

## 8.5.1 Access Size and Data Alignment

This LSI supports little endian, in which the least significant byte (LSB) is that in the direction of the 0th address. Data bus width can be selected from 8 bits, 16 bits, and 32 bits for the normal memory and SRAM with byte selection. Data bus width can be selected from 16 bits and 32 bits for SDRAM. For MPX-I/O, the data bus width is fixed to either 8 or 16 bits, or made selectable as 8 bits or 16 bits by one of the address lines.

Data bus width varies depending on boot mode. For details, refer to section 8.3.2, Data Bus Width and Related Pin Setting for Each Area Depending on Boot Mode .

Data alignment is performed in accordance with the data bus width selected for the device. This also means that four read operations are required to read 32-bit data from a byte-width device. In this LSI, data alignment and conversion of data length is performed automatically between the respective interfaces.

Table 8.5 to Table 8.7 show the relationship between device data width and access unit.

## **Table 8.5 32-Bit External Device Access and Data Alignment in Little Endian**

|**Operation**|**Data Bus**<br>**Strobe Signals**|
|---|---|
||**D31 to**<br>**D24**<br>**D23 to**<br>**D16**<br>**D15 to**<br>**D8**<br>**D7 to D0**<br>**WE3**<br>**,**<br>**DQMUU**<br>**WE2**<br>**,**<br>**DQMUL**<br>**WE1**<br>**,**<br>**DQMLU**<br>**WE0**<br>**,**<br>**DQMLL**|
|8-bit access at address 0|―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
|8-bit access at address 1|―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert<br>―|
|8-bit access at address 2|―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert<br>―<br>―|
|8-bit access at address 3|Data 7 to<br>0<br>―<br>―<br>―<br>Assert<br>―<br>―<br>―|
|16-bit access at address 0|―<br>―<br>Data 15 to<br>8<br>Data 7 to<br>0<br>―<br>―<br>Assert<br>Assert|
|16-bit access at address 2|Data 15 to<br>8<br>Data 7 to<br>0<br>―<br>―<br>Assert<br>Assert<br>―<br>―|
|32-bit access at address 0|Data 31 to<br>24<br>Data 23 to<br>16<br>Data 15 to<br>8<br>Data 7 to<br>0<br>Assert<br>Assert<br>Assert<br>Assert|

## **Table 8.6 16-Bit External Device Access and Data Alignment in Little Endian**

|**Operation**|**Data Bus**<br>**Strobe Signals**|
|---|---|
||**D31 to**<br>**D24**<br>**D23 to**<br>**D16**<br>**D15 to**<br>**D8**<br>**D7 to D0**<br>**WE3**<br>**,**<br>**DQMUU**<br>**WE2**<br>**,**<br>**DQMUL**<br>**WE1**<br>**,**<br>**DQMLU**<br>**WE0**<br>**,**<br>**DQMLL**|
|8-bit access at address 0|―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
|8-bit access at address 1|―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert<br>―|
|8-bit access at address 2|―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
|8-bit access at address 3|―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert<br>―|
|16-bit access at address 0|―<br>―<br>Data 15 to<br>8<br>Data 7 to<br>0<br>―<br>―<br>Assert<br>Assert|
|16-bit access at address 2|―<br>―<br>Data 15 to<br>8<br>Data 7 to<br>0<br>―<br>―<br>Assert<br>Assert|

## **Table 8.6 16-Bit External Device Access and Data Alignment in Little Endian**

|**Operation**||**Data Bus**<br>**Strobe Signals**|
|---|---|---|
|||**D31 to**<br>**D24**<br>**D23 to**<br>**D16**<br>**D15 to**<br>**D8**<br>**D7 to D0**<br>**WE3**<br>**,**<br>**DQMUU**<br>**WE2**<br>**,**<br>**DQMUL**<br>**WE1**<br>**,**<br>**DQMLU**<br>**WE0**<br>**,**<br>**DQMLL**|
|32-bit access at<br>address 0|<br>1st access at address<br>0|―<br>―<br>Data 15 to<br>8<br>Data 7 to<br>0<br>―<br>―<br>Assert<br>Assert|
||2nd access at address<br>2|<br>―<br>―<br>Data 31 to<br>24<br>Data 23 to<br>16<br>―<br>―<br>Assert<br>Assert|

## **Table 8.7 8-Bit External Device Access and Data Alignment in Little Endian**

|**Operation**|**Operation**|**Data Bus**<br>**Strobe Signals**|
|---|---|---|
|||**D31 to**<br>**D24**<br>**D23 to**<br>**D16**<br>**D15 to**<br>**D8**<br>**D7 to D0**<br>**WE3**<br>**,**<br>**DQMUU**<br>**WE2**<br>**,**<br>**DQMUL**<br>**WE1**<br>**,**<br>**DQMLU**<br>**WE0**<br>**,**<br>**DQMLL**|
|8-bit access at address 0||―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
|8-bit access at address 1||―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
|8-bit access at address 2||―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
|8-bit access at address 3||―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
|16-bit access at<br>address 0|<br>1st access at address<br>0|―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
||2nd access at address<br>1|<br>―<br>―<br>―<br>Data 15 to<br>8<br>―<br>―<br>―<br>Assert|
|16-bit access at<br>address 2|<br>1st access at address<br>0|―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
||2nd access at address<br>1|<br>―<br>―<br>―<br>Data 15 to<br>8<br>―<br>―<br>―<br>Assert|
|32-bit access at<br>address 0|<br>1st access at address<br>0|―<br>―<br>―<br>Data 7 to<br>0<br>―<br>―<br>―<br>Assert|
||2nd access at address<br>1|<br>―<br>―<br>―<br>Data 15 to<br>8<br>―<br>―<br>―<br>Assert|
||3rd access at address<br>2|―<br>―<br>―<br>Data 23 to<br>16<br>―<br>―<br>―<br>Assert|
||4th access at address<br>3|―<br>―<br>―<br>Data 31 to<br>24<br>―<br>―<br>―<br>Assert|

## 8.5.2 Normal Space Interface

## (1) Basic Timing

For access to a normal space, this LSI uses strobe signal output in consideration of the fact that mainly static RAM will be directly connected. When using SRAM with a byte-selection pin, see section 8.5.8, SRAM Interface with Byte Selection . Figure 8.2 shows the basic timings of normal space access. A no-wait normal access is completed in two cycles. The BS signal is asserted for one cycle to indicate the start of a bus cycle.

**==> picture [208 x 335] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1  T2<br>CKIO<br>A25 to A0<br>CSn<br>RD/WR<br>Read RD<br>D31 to D0<br>RD/WR<br>Write WEn<br>D31 to D0<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.2 Normal Space Basic Access Timing (Access Wait 0)**

There is no access size specification when reading. The correct access start address is output in the least significant bit of the address, but since there is no access size specification, 32 bits are always read in case of a 32-bit device. 16 bits are always read in case of a 16-bit device. When writing, only the WEn signal for the byte to be written is asserted.

It is necessary to output the data that has been read using RD when a buffer is established in the data bus. The RD/WR signal is in a read state (high output) when no access has been carried out. Therefore, care must be taken when controlling the external data buffer with this signal, to avoid output collision.

Figure 8.3 and Figure 8.4 show the basic timings in continuous access to normal space. If the WM bit in CSnWCR is cleared to 0, a Tnop cycle is inserted after the CSn space access to evaluate the external wait ( Figure 8.3 ). If the WM bit in CSnWCR is set to 1, external waits are ignored and no Tnop cycle is inserted ( Figure 8.4 ).

**==> picture [230 x 254] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1  T2  Tnop  T1  T2<br>CKIO<br>A25 to A0<br>CSn<br>RD/WR<br>RD<br>Read<br>D15 to D0<br>WEn<br>Write<br>D15 to D0<br>BS<br>DACKn *<br>WAIT<br>Note:  * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.3 Continuous Access to Normal Space (1) Bus Width = 16 Bits, 32-Bit Access, CSnWCR.WM Bit = 0 (Access Wait = 0, Cycle Wait = 0)**

**==> picture [244 x 331] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1  T2    T1  T2<br>CKIO<br>A25 to A0<br>CSn<br>RD/WR<br>RD<br>Read<br>D15 to D0<br>WEn<br>Write<br>D15 to D0<br>BS<br>DACKn *<br>WAIT<br>Note:  * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.4 Continuous Access to Normal Space (2) Bus Width = 16 Bits, 32-Bit Access, CSnWCR.WM Bit = 1 (Access Wait = 0, Cycle Wait = 0)**

**==> picture [348 x 459] intentionally omitted <==**

**----- Start of picture text -----**<br>
128K × 8-bit<br>This LSI  SRAM<br>A18 A16<br>A2 A0<br>CSn CS<br>RD OE<br>D31 I/O7<br>D24 I/O0<br>WE3 WE<br>D23<br>D16 A16<br>WE2<br>D15 A0<br>CS<br>D8 OE<br>WE1 I/O7<br>D7<br>I/O0<br>D0 WE<br>WE0<br>A16<br>A0<br>CS<br>OE<br>I/O7<br>I/O0<br>WE<br>A16<br>A0<br>CS<br>OE<br>I/O7<br>I/O0<br>WE<br>. . . . . .<br>. . . . . .<br>. . .<br>. . .<br>. . .<br>. . .<br>. . .<br>. . .<br>. . .<br>. . .<br>. . .<br>**----- End of picture text -----**<br>

**Figure 8.5 Example of 32-Bit Data-Width SRAM Connection**

**==> picture [283 x 190] intentionally omitted <==**

**----- Start of picture text -----**<br>
128K × 8-bit<br>This LSI SRAM<br>A17 A16<br>A1 A0<br>CSn CS<br>RD OE<br>D15 I/O7<br>D8 I/O0<br>WE1 WE<br>D7<br>D0 A16<br>WE0<br>A0<br>CS<br>OE<br>I/O7<br>I/O0<br>WE<br>• • • • • • • •<br>• • • • • • • •<br>• • • •<br>• • • •<br>• • • •<br>**----- End of picture text -----**<br>

**Figure 8.6 Example of 16-Bit Data-Width SRAM Connection**

**==> picture [307 x 131] intentionally omitted <==**

**----- Start of picture text -----**<br>
128K × 8-bit<br>This LSI  SRAM<br>A16 A16<br>A0 A0<br>CSn CS<br>RD OE<br>D7 I/O7<br>D0 I/O0<br>WE0 WE<br>. . . . . .<br>. . . . . .<br>**----- End of picture text -----**<br>

**Figure 8.7 Example of 8-Bit Data-Width SRAM Connection**

## 8.5.3 Access Wait Control

Wait cycle insertion on a normal space access can be controlled by the settings of bits WR3 to WR0 in CSnWCR. It is possible for areas 1, 4, and 5 to insert wait cycles independently in read access and in write access. Areas 0, 2, and 3 have common access wait for read cycle and write cycle. The specified number of Tw cycles are inserted as wait cycles in a normal space access shown in Figure 8.8 .

**==> picture [218 x 252] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 Tw T2<br>CKIO<br>A25 to A0<br>CSn<br>RD/WR<br>RD<br>Read<br>D31 to D0<br>WEn<br>Write<br>D31 to D0<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.8 Wait Timing for Normal Space Access (Software Wait Only)**

When the WM bit in CSnWCR is cleared to 0, the external wait input WAIT signal is also sampled. WAIT pin sampling is shown in Figure 8.9 . A 2-cycle wait is specified as a software wait. The WAIT signal is sampled on the falling edge of CKIO at the transition from the T1 or Tw cycle to the T2 cycle.

**==> picture [273 x 274] intentionally omitted <==**

**----- Start of picture text -----**<br>
Wait states inserted<br>by WAIT signal<br>T1 Tw Tw Twx T2<br>CKIO<br>A25 to A0<br>CSn<br>RD/WR<br>RD<br>Read<br>D31 to D0<br>WEn<br>Write<br>D31 to D0<br>WAIT<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.9 Wait Cycle Timing for Normal Space Access (Wait Cycle Insertion Using WAIT Signal)**

## 8.5.4 CSn Assert Period Expansion

The number of cycles from CSn assertion to RD, WEn assertion can be specified by setting bits SW1 and SW0 in CSnWCR. The number of cycles from RD, WEn negation to CSn negation can be specified by setting bits HW1 and HW0. Therefore, a flexible interface to an external device can be obtained. Figure 8.10 shows an example. A Th cycle and a Tf cycle are added before and after an ordinary cycle, respectively. In these cycles, RD and WEn are not asserted, while other signals are asserted. The data output is prolonged to the Tf cycle, and this prolongation is useful for devices with slow writing operations.

**==> picture [256 x 262] intentionally omitted <==**

**----- Start of picture text -----**<br>
Th T1 T2 Tf<br>CKIO<br>A25 to A0<br>CSn<br>RD/WR<br>RD<br>Read<br>D31 to D0<br>WEn<br>Write<br>D31 to D0<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.10 CSn Assert Period Expansion**

## 8.5.5 MPX-I/O Interface

Access timing for the MPX space is shown below. In the MPX space, CS5, AH, RD, and WEn signals control the accessing. The basic access for the MPX space consists of 2 cycles of address output followed by an access to a normal space. The bus width for the address output cycle or the data input/output cycle is fixed to 8 bits or 16 bits. Alternatively, it can be 8 bits or 16 bits depending on the address to be accessed.

Output of the addresses D15 to D0 or D7 to D0 is performed from cycle Ta2 to cycle Ta3. Because cycle Ta1 has a highimpedance state, collisions of addresses and data can be avoided without inserting idle cycles, even in continuous access cycles. Address output is increased to 3 cycles by setting the MPXW bit in CS5WCR to 1.

The RD/WR signal is output at the same time as the CS5 signal; it is high in the read cycle and low in the write cycle. The data cycle is the same as that in a normal space access.

The delay cycles the number of which is specified by SW[1:0] are inserted between cycle Ta3 and cycle T1. The delay cycles the number of which is specified by HW[1:0] are added after cycle T2. Timing charts are shown in Figure 8.11 to Figure 8.13 .

**==> picture [370 x 341] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ta1 Ta2 Ta3 T1 T2<br>CKIO<br>A25 to A0<br>CS5<br>RD/WR<br>AH<br>RD<br>Read<br>D15/D7 to D0 Address Data<br>WEn<br>Write<br>D15/D7 to D0 Address Data<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.11 (1) Access Timing for MPX Space (Address Cycle No Wait, Data Cycle No Wait)**

**==> picture [417 x 307] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ta1 Ta2 Ta3 Th T1 T2 Tf<br>CKIO<br>A25 to A0<br>CS5<br>RD/WR<br>AH<br>RD<br>Read<br>D15/D7 to D0 Address Data<br>WEn<br>Write<br>D15/D7 to D0 Address Data<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.11 (2) Access Timing for MPX Space (Address Cycle No Wait, Extended Assertion Cycle 1.5, Data Cycle No Wait, Extended Negation Cycle 1.5)**

**==> picture [483 x 650] intentionally omitted <==**

**----- Start of picture text -----**<br>
Ta1 Tadw Ta2 Ta3 T1 T2<br>CKIO<br>A25 to A0<br>CS5<br>RD/WR<br>AH<br>RD<br>Read<br>D15/D7 to D0 Address Data<br>WEn<br>Write<br>D15/D7 to D0 Address Data<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>Figure 8.12 Access Timing for MPX Space (Address Cycle Wait 1, Data Cycle No Wait)<br>Ta1 Tadw Ta2 Ta3 T1 Tw Twx T2<br>CKIO<br>A25 to A0<br>CS5<br>RD/WR<br>AH<br>RD<br>Read<br>D15/D7 to D0 Address Data<br>WEn<br>Write<br>D15/D7 to D0 Address Data<br>WAIT<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.13 Access Timing for MPX Space (Address Cycle Access Wait 1, Data Cycle Wait 1, External Wait 1)**

## 8.5.6 SDRAM Interface

## (1) SDRAM Direct Connection

The SDRAM that can be connected to this LSI is a product that has 11/12/13 bits of row address, 8/9/10 bits of column address, 4 or less banks, and uses the A10 pin for setting precharge mode in read and write command cycles.

The control signals for direct connection of SDRAM are RAS, CAS, RD/WR, DQMUU, DQMUL, DQMLU, DQMLL, CKE, CS2, and CS3. All the signals other than CS2 and CS3 are common to all areas, and signals other than CKE are valid only when CS2 or CS3 is asserted. SDRAM can be connected to up to 2 spaces. The data bus width of the area that is connected to SDRAM is 16 bits or 32 bits.

Burst read/single write (burst length 1) and burst read/burst write (burst length 1) are supported as the SDRAM operating mode.

Commands for SDRAM can be specified by RAS, CAS, RD/WR, and specific address signals. These commands supports:

- NOP

- Auto-refresh (REF)

- Self-refresh (SELF)

- All banks pre-charge (PALL)

- Specified bank pre-charge (PRE)

- Bank active (ACTV)

- Read (READ)

- Read with pre-charge (READA)

- Write (WRIT)

- Write with pre-charge (WRITA)

- Write mode register (MRS, EMRS)

The byte to be accessed is specified by DQMUU, DQMUL, DQMLU, and DQMLL. Reading or writing is performed for a byte whose corresponding DQMxx is low. For details on the relationship between DQMxx and the byte to be accessed, see section 8.5.1, Access Size and Data Alignment .

## Figure 8.14 and Figure 8.15 show examples of the connection of the SDRAM with the LSI.

**==> picture [338 x 359] intentionally omitted <==**

**----- Start of picture text -----**<br>
64M SDRAM<br>This LSI (1M × 16-bit × 4-bank)<br>A15 A13<br>A2 A0<br>CKE CKE<br>CKIO CLK<br>CSn CS<br>RAS RAS<br>CAS CAS<br>RD/WR WE<br>D31 I/O15<br>D16 I/O0<br>DQMUU DQMU<br>DQMUL DQML<br>D15<br>A13<br>D0<br>DQMLU<br>A0<br>DQMLL<br>CKE<br>CLK<br>CS<br>RAS<br>CAS<br>WE<br>I/O15<br>I/O0<br>DQMU<br>DQML<br>. . . . . .<br>. . . . . .<br>. . .<br>. . .<br>. . .<br>**----- End of picture text -----**<br>

**Figure 8.14 Example of 32-Bit Data Width SDRAM Connection**

**==> picture [338 x 186] intentionally omitted <==**

**----- Start of picture text -----**<br>
64M SDRAM<br>This LSI  (1M × 16-bit × 4-bank)<br>A14 A13<br>A1 A0<br>CKE CKE<br>CKIO CLK<br>CSn CS<br>RAS RAS<br>CAS CAS<br>RD/WR WE<br>D15 I/O15<br>D0 I/O0<br>DQMLU DQMU<br>DQMLL DQML<br>. . . . . .<br>. . . . . .<br>**----- End of picture text -----**<br>

**Figure 8.15 Example of 16-Bit Data Width SDRAM Connection**

## (2) Address Multiplexing

An address multiplexing is specified so that SDRAM can be connected without external multiplexing circuitry according to the setting of bits BSZ[1:0] in CSnBCR and bits A2ROW[1:0], A2COL[1:0], A3ROW[1:0], and A3COL[1:0] in SDCR. Table 8.8 to Table 8.13 show the relationship between the settings of bits BSZ[1:0], A2ROW[1:0], A2COL[1:0], A3ROW[1:0], and A3COL[1:0] and the bits output at the address pins. Do not specify those bits in the manner other than this table, otherwise the operation of this LSI is not guaranteed. A25 to A18 are not multiplexed and the original values of address are always output at these pins.

When the data bus width is 16 bits (BSZ1 and BSZ0 = B'10), A0 of SDRAM specifies a 16-bit address. Therefore, connect this A0 pin of SDRAM to the A1 pin of the LSI; the A1 pin of SDRAM to the A2 pin of the LSI, and so on. When the data bus width is 32 bits (BSZ1 and BSZ0 = B'11), A0 of SDRAM specifies a 32-bit address. Therefore, connect this A0 pin of SDRAM to the A2 pin of the LSI; the A1 pin of SDRAM to the A3 pin of the LSI, and so on.

**Table 8.8 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (1)-1**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**11 (32 bits)**|**00 (11 bits)**||**00 (8 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A25||A17||Unused|
|A16|A24||A16|||
|A15|A23||A15|||
|A14|A22*2||A22*2|A12 (BA1)|Specifies bank|
|A13|A21*2||A21*2|A11 (BA0)||
|A12|A20||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A11|A19||A11|A9|Address|
|A10|A18||A10|A8||
|A9|A17||A9|A7||
|A8|A16||A8|A6||
|A7|A15||A7|A5||
|A6|A14||A6|A4||
|A5|A13||A5|A3||
|A4|A12||A4|A2||
|A3|A11||A3|A1||
|A2|A10||A2|A0||
|A1|A9||A1||Unused|
|A0|A8||A0|||
|Example of connected memory||||||
|64-Mbit product (512 Kwords ×||32 bits × 4 banks, column 8 bits product): 1||||
|16-Mbit product (512 Kwords ×||16 bits × 2 banks, column 8 bits product): 2||||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.8 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (1)-2**

||**Setting**||||
|---|---|---|---|---|
||**A2/3**|**A2/3**|||
|**BSZ**|**ROW**|**COL**|||
|**[1:0]**|**[1:0]**|**[1:0]**|||
|**11 (32 bits)**|**01 (12 bits)**|**00 (8 bits)**|||
|**Output Pin of This**|**Row Address Output**|**Column Address Output**|||
|**LSI**|**Cycle**|**Cycle**|**SDRAM Pin**|**Function**|
|A17|A25|A17||Unused|
|A16|A24|A16|||
|A15|A23*2|A23*2|A13 (BA1)|Specifies bank|
|A14|A22*2|A22*2|A12 (BA0)||
|A13|A21|A13|A11|Address|
|A12|A20|L/H*1|A10/AP|Specifies address/|
|||||precharge|
|A11|A19|A11|A9|Address|
|A10|A18|A10|A8||
|A9|A17|A9|A7||
|A8|A16|A8|A6||
|A7|A15|A7|A5||
|A6|A14|A6|A4||
|A5|A13|A5|A3||
|A4|A12|A4|A2||
|A3|A11|A3|A1||
|A2|A10|A2|A0||
|A1|A9|A1||Unused|
|A0|A8|A0|||
|Example of connected memory|||||
|128-Mbit product (1 Mwords × 32 bits × 4 banks, column 8 bits product): 1|||||
|64-Mbit product (1 Mwords × 16 bits × 4 banks, column 8 bits product): 2|||||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.9 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (2)-1**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**11 (32 bits)**|**01 (12 bits)**||**01 (9 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A26||A17||Unused|
|A16|A25||A16|||
|A15|A24*2||A24*2|A13 (BA1)|Specifies bank|
|A14|A23*2||A23*2|A12 (BA0)||
|A13|A22||A13|A11|Address|
|A12|A21||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A11|A20||A11|A9|Address|
|A10|A19||A10|A8||
|A9|A18||A9|A7||
|A8|A17||A8|A6||
|A7|A16||A7|A5||
|A6|A15||A6|A4||
|A5|A14||A5|A3||
|A4|A13||A4|A2||
|A3|A12||A3|A1||
|A2|A11||A2|A0||
|A1|A10||A1||Unused|
|A0|A9||A0|||
|Example of connected memory||||||
|256-Mbit product (2 Mwords × 32||bits × 4 banks,|column 9 bits product): 1|||
|128-Mbit product (2 Mwords × 16||bits × 4 banks,|column 9 bits product): 2|||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.9 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (2)-2**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**11 (32 bits)**|**01 (12 bits)**||**10 (10 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A27||A17||Unused|
|A16|A26||A16|||
|A15|A25*2||A25*2|A13 (BA1)|Specifies bank|
|A14|A24*2||A24*2|A12 (BA0)||
|A13|A23||A13|A11|Address|
|A12|A22||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A11|A21||A11|A9|Address|
|A10|A20||A10|A8||
|A9|A19||A9|A7||
|A8|A18||A8|A6||
|A7|A17||A7|A5||
|A6|A16||A6|A4||
|A5|A15||A5|A3||
|A4|A14||A4|A2||
|A3|A13||A3|A1||
|A2|A12||A2|A0||
|A1|A11||A1||Unused|
|A0|A10||A0|||
|Example of connected memory||||||
|512-Mbit product (4 Mwords × 32||bits × 4 banks,|column 10 bits product): 1|||
|256-Mbit product (4 Mwords × 16||bits × 4 banks,|column 10 bits product): 2|||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.10 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (3)**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**11 (32 bits)**|**10 (13 bits)**||**01 (9 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A26||A17||Unused|
|A16|A25*2||A25*2|A14 (BA1)|Specifies bank|
|A15|A24*2||A24*2|A13 (BA0)||
|A14|A23||A14|A12|Address|
|A13|A22||A13|A11||
|A12|A21||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A11|A20||A11|A9|Address|
|A10|A19||A10|A8||
|A9|A18||A9|A7||
|A8|A17||A8|A6||
|A7|A16||A7|A5||
|A6|A15||A6|A4||
|A5|A14||A5|A3||
|A4|A13||A4|A2||
|A3|A12||A3|A1||
|A2|A11||A2|A0||
|A1|A10||A1||Unused|
|A0|A9||A0|||
|Example of connected memory||||||
|512-Mbit product (4 Mwords × 32||bits × 4 banks,|column 9 bits product): 1|||
|256-Mbit product (4 Mwords × 16||bits × 4 banks,|column 9 bits product): 2|||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.11 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (4)-1**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**10 (16 bits)**|**00 (11 bits)**||**00 (8 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A25||A17||Unused|
|A16|A24||A16|||
|A15|A23||A15|||
|A14|A22||A14|||
|A13|A21||A21|||
|A12|A20*2||A20*2|A11 (BA0)|Specifies bank|
|A11|A19||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A10|A18||A10|A9|Address|
|A9|A17||A9|A8||
|A8|A16||A8|A7||
|A7|A15||A7|A6||
|A6|A14||A6|A5||
|A5|A13||A5|A4||
|A4|A12||A4|A3||
|A3|A11||A3|A2||
|A2|A10||A2|A1||
|A1|A9||A1|A0||
|A0|A8||A0||Unused|
|Example of connected memory||||||
|16-Mbit product (512 Kwords ×||16 bits × 2 banks, column 8 bits product): 1||||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.11 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (4)-2**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**10 (16 bits)**|**01 (12 bits)**||**00 (8 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A25||A17||Unused|
|A16|A24||A16|||
|A15|A23||A15|||
|A14|A22*2||A22*2|A13 (BA1)|Specifies bank|
|A13|A21*2||A21*2|A12 (BA0)||
|A12|A20||A12|A11|Address|
|A11|A19||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A10|A18||A10|A9|Address|
|A9|A17||A9|A8||
|A8|A16||A8|A7||
|A7|A15||A7|A6||
|A6|A14||A6|A5||
|A5|A13||A5|A4||
|A4|A12||A4|A3||
|A3|A11||A3|A2||
|A2|A10||A2|A1||
|A1|A9||A1|A0||
|A0|A8||A0||Unused|
|Example of connected|memory|||||
|64-Mbit product (1 Mwords × 16||bits × 4 banks,|column 8 bits product): 1|||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.12 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (5)-1**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**10 (16 bits)**|**01 (12 bits)**||**01 (9 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A26||A17||Unused|
|A16|A25||A16|||
|A15|A24||A15|||
|A14|A23*2||A23*2|A13 (BA1)|Specifies bank|
|A13|A22*2||A22*2|A12 (BA0)||
|A12|A21||A12|A11|Address|
|A11|A20||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A10|A19||A10|A9|Address|
|A9|A18||A9|A8||
|A8|A17||A8|A7||
|A7|A16||A7|A6||
|A6|A15||A6|A5||
|A5|A14||A5|A4||
|A4|A13||A4|A3||
|A3|A12||A3|A2||
|A2|A11||A2|A1||
|A1|A10||A1|A0||
|A0|A9||A0||Unused|
|Example of connected memory||||||
|128-Mbit product (2 Mwords × 16||bits × 4 banks,|column 9 bits product): 1|||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.12 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (5)-2**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**10 (16 bits)**|**01 (12 bits)**||**10 (10 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A27||A17||Unused|
|A16|A26||A16|||
|A15|A25||A15|||
|A14|A24*2||A24*2|A13 (BA1)|Specifies bank|
|A13|A23*2||A23*2|A12 (BA0)||
|A12|A22||A12|A11|Address|
|A11|A21||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A10|A20||A10|A9|Address|
|A9|A19||A9|A8||
|A8|A18||A8|A7||
|A7|A17||A7|A6||
|A6|A16||A6|A5||
|A5|A15||A5|A4||
|A4|A14||A4|A3||
|A3|A13||A3|A2||
|A2|A12||A2|A1||
|A1|A11||A1|A0||
|A0|A10||A0||Unused|
|Example of connected memory||||||
|256-Mbit product (4 Mwords × 16||bits × 4 banks,|column 10 bits product): 1|||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.13 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (6)-1**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**10 (16 bits)**|**10 (13 bits)**||**01 (9 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A26||A17||Unused|
|A16|A25||A16|||
|A15|A24*2||A24*2|A14 (BA1)|Specifies bank|
|A14|A23*2||A23*2|A13 (BA0)||
|A13|A22||A13|A12|Address|
|A12|A21||A12|A11||
|A11|A20||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A10|A19||A10|A9|Address|
|A9|A18||A9|A8||
|A8|A17||A8|A7||
|A7|A16||A7|A6||
|A6|A15||A6|A5||
|A5|A14||A5|A4||
|A4|A13||A4|A3||
|A3|A12||A3|A2||
|A2|A11||A2|A1||
|A1|A10||A1|A0||
|A0|A9||A0||Unused|
|Example of connected memory||||||
|256-Mbit product (4 Mwords × 16||bits × 4 banks,|column 9 bits product): 1|||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

**Table 8.13 Relationship between BSZ[1:0], A2/3ROW[1:0], A2/3COL[1:0], and Address Multiplex Output (6)-2**

|||**Setting**||||
|---|---|---|---|---|---|
||**A2/3**||**A2/3**|||
|**BSZ**|**ROW**||**COL**|||
|**[1:0]**|**[1:0]**||**[1:0]**|||
|**10 (16 bits)**|**10 (13 bits)**||**10 (10 bits)**|||
|**Output Pin of This**|**Row Address Output**||**Column Address Output**|||
|**LSI**|**Cycle**||**Cycle**|**SDRAM Pin**|**Function**|
|A17|A27||A17||Unused|
|A16|A26||A16|||
|A15|A25*2||A25*2|A14 (BA1)|Specifies bank|
|A14|A24*2||A24*2|A13 (BA0)||
|A13|A23||A13|A12|Address|
|A12|A22||A12|A11||
|A11|A21||L/H*1|A10/AP|Specifies address/|
||||||precharge|
|A10|A20||A10|A9|Address|
|A9|A19||A9|A8||
|A8|A18||A8|A7||
|A7|A17||A7|A6||
|A6|A16||A6|A5||
|A5|A15||A5|A4||
|A4|A14||A4|A3||
|A3|A13||A3|A2||
|A2|A12||A2|A1||
|A1|A11||A1|A0||
|A0|A10||A0||Unused|
|Example of connected memory||||||
|512-Mbit product (8 Mwords × 16||bits × 4 banks,|column 10 bits product): 1|||

Note 1. L/H is a bit used in the command specification; it is fixed at L or H according to the access mode. Note 2. Bank address specification

## (3) Burst Read

A burst read occurs in the following cases with this LSI.

- Access size in reading is larger than data bus width.

- 16-, 32- or 64-byte transfer

This LSI always accesses the SDRAM with burst length 1. For example, read access of burst length 1 is performed consecutively 8 times to read 16-byte continuous data from the SDRAM that is connected to a 16-bit data bus. This access is called the burst read with the burst number 8. Table 8.14 shows the relationship between the access size and the number of bursts.

**Table 8.14 Relationship between Access Size and Number of Bursts**

|**Bus Width**|**Access Size**<br>**Number of Bursts**|
|---|---|
|16 bits|8 bits<br>1|
||16 bits<br>1|
||32 bits<br>2|
||16 bytes<br>8|
||32 bytes<br>16|
||64 bytes<br>32|
|32 bits|8 bits<br>1|
||16 bits<br>1|
||32 bits<br>1|
||16 bytes<br>4|
||32 bytes<br>8|
||64 bytes<br>16|

Figure 8.16 and Figure 8.17 show timing charts in burst read. In burst read, an ACTV command is output in the Tr cycle, the READ command is issued in the Tc1, Tc2, and Tc3 cycles, the READA command is issued in the Tc4 cycle, and the read data is received at the rising edge of the external clock (CKIO) in the Td1 to Td4 cycles. The Tap cycle is used to wait for the completion of an auto-precharge induced by the READA command in the SDRAM. In the Tap cycle, a new command will not be issued to the same bank. However, access to another CS space or another bank in the same SDRAM space is enabled. The number of Tap cycles is specified by the WTRP1 and WTRP0 bits in CS3WCR. In this LSI, wait cycles can be inserted by specifying each bit in CS3WCR to connect the SDRAM in variable frequencies. Figure 8.17 shows an example in which wait cycles are inserted. The number of cycles from the Tr cycle where the ACTV command is output to the Tc1 cycle where the READ command is output can be specified using the WTRCD1 and WTRCD0 bits in CS3WCR. If the WTRCD1 and WTRCD0 bits specify one cycle or more, a Trw cycle where the NOP command is issued is inserted between the Tr cycle and Tc1 cycle. The number of cycles from the Tc1 cycle where the READ command is output to the Td1 cycle where the read data is latched can be specified for the CS2 and CS3 spaces independently, using the A2CL1 and A2CL0 bits in CS2WCR or the A3CL1 and A3CL0 bits in CS3WCR. The number of cycles from Tc1 to Td1 corresponds to the SDRAM CAS latency. The CAS latency for the SDRAM is normally defined as up to three cycles. However, the CAS latency in this LSI can be specified as 1 to 4 cycles. This CAS latency can be achieved by connecting a latch circuit between this LSI and the SDRAM.

A Tde cycle is an idle cycle required to transfer the read data into this LSI and occurs once for every burst read or every single read.

**==> picture [315 x 282] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tr Tc1 Tc2 Tc3 Tc4 Tde (Tap)<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.16 Burst Read Basic Timing (CAS Latency 1, Auto Pre-Charge)**

**==> picture [381 x 281] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tw Td1 Td2 Td3 Td4<br>Tr Trw Tc1 Tc2 Tc3 Tc4 Tde (Tap)<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.17 Burst Read Wait Specification Timing (CAS Latency 2,  WTRCD[1:0] = 1 Cycle, Auto Pre-Charge)**

## (4) Single Read

A read access ends in one cycle when the data bus width is larger than or equal to the access size. As the SDRAM is set to the burst read with the burst length 1, only the required data is output. A read access that ends in one cycle is called single read.

Figure 8.18 shows the single read basic timing.

**==> picture [251 x 274] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Tc1 Td1 Tde (Tap)<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.18 Basic Timing for Single Read (CAS Latency 1, Auto Pre-Charge)**

## (5) Burst Write

A burst write occurs in the following cases in this LSI.

- Access size in writing is larger than data bus width.

- 16-, 32- or 64-byte transfer

This LSI always accesses SDRAM with burst length 1. For example, write access of burst length 1 is performed continuously 8 times to write 16-byte continuous data to the SDRAM that is connected to a 16-bit data bus. This access is called burst write with the burst number 8. The relationship between the access size and the number of bursts is shown in Table 8.14 . Figure 8.19 shows a timing chart for burst writes. In burst write, an ACTV command is output in the Tr cycle, the WRIT command is issued in the Tc1, Tc2, and Tc3 cycles, and the WRITA command is issued to execute an auto-precharge in the Tc4 cycle. In the write cycle, the write data is output simultaneously with the write command. After the write command with the auto-precharge is output, the Trw1 cycle that waits for the auto-precharge initiation is followed by the Tap cycle that waits for completion of the auto-precharge induced by the WRITA command in the SDRAM. Between the Trwl and the Tap cycle, a new command will not be issued to the same bank. However, access to another CS space or another bank in the same SDRAM space is enabled. The number of Trw1 cycles is specified by the TRWL1 and TRWL0 bits in CS3WCR. The number of Tap cycles is specified by the WTRP1 and WTRP0 bits in CS3WCR.

**==> picture [283 x 276] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Tc1 Tc2 Tc3 Tc4 Trwl   Tap<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.19 Basic Timing for Burst Write (Auto Pre-Charge)**

## (6) Single Write

A write access ends in one cycle when the data bus width is larger than or equal to access size. As a single write or burst write with burst length 1 is set in SDRAM, only the required data is output. The write access that ends in one cycle is called single write. Figure 8.20 shows the single write basic timing.

**==> picture [211 x 273] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Tc1 Trwl   Tap<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>            2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.20 Single Write Basic Timing (Auto-Precharge)**

## (7) Bank Active

The SDRAM bank function can be used to support high-speed access to the same row address. When the BACTV bit in SDCR is 1, access is performed using commands without auto-precharge (READ or WRIT). This function is called bank-active function. This function is valid only for area 3. When area 3 is set to bank-active mode, area 2 should be set to normal space or SRAM with byte selection. When areas 2 and 3 are both set to SDRAM, auto precharge mode must be set.

When the bank-active function is used, precharging is not performed when the access ends. When accessing the same row address in the same bank, it is possible to issue the READ or WRIT command immediately, without issuing an ACTV command. As SDRAM is internally divided into several banks, it is possible to activate one row address in each bank. If the next access is to a different row address, a PRE command is first issued to precharge the relevant bank, then when precharging is completed, the access is performed by issuing an ACTV command followed by a READ or WRIT command. If this is followed by an access to a different row address, the access time will be longer because of the precharging performed after the access request is issued. The number of cycles between issuance of the PRE command and the ACTV command is determined by the WTRP1 and WTPR0 bits in CS3WCR.

In a write, when an auto-precharge is performed, a command cannot be issued to the same bank for a period of Trwl + Tap cycles after issuance of the WRITA command. When bank active mode is used, READ or WRIT commands can be issued successively if the row address is the same. The number of cycles can thus be reduced by Trwl + Tap cycles for each write.

There is a limit on tRAS, the time for placing each bank in the active state. If there is no guarantee that there will not be a cache hit and another row address will be accessed within the period in which this value is maintained by program execution, it is necessary to set auto-refresh and set the refresh cycle to no more than the maximum value of tRAS. A burst read cycle without auto-precharge is shown in Figure 8.21 , a burst read cycle for the same row address in Figure 8.22 , and a burst read cycle for different row addresses in Figure 8.23 . Similarly, a single write cycle without auto-precharge is shown in Figure 8.24 , a single write cycle for the same row address in Figure 8.25 , and a single write cycle for different row addresses in Figure 8.26 .

In Figure 8.22 , a Tnop cycle in which no operation is performed is inserted before the Tc cycle that issues the READ command. The Tnop cycle is inserted to acquire two cycles of CAS latency for the DQMxx signal that specifies the read byte in the data read from the SDRAM. If the CAS latency is specified as two cycles or more, the Tnop cycle is not inserted because the two cycles of latency can be acquired even if the DQMxx signal is asserted after the Tc cycle. When bank active mode is set, if only access cycles to the respective banks in the area 3 space are considered, as long as access cycles to the same row address continue, the operation starts with the cycle in Figure 8.21 or Figure 8.24 , followed by repetition of the cycle in Figure 8.22 or Figure 8.25 . An access to a different area during this time has no effect. If there is an access to a different row address in the bank active state, the bus cycle in Figure 8.23 or Figure 8.26 is executed instead of that in Figure 8.22 or Figure 8.25 . In bank active mode, too, all banks become inactive after a refresh cycle.

**==> picture [294 x 281] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tr Tc1 Tc2 Tc3 Tc4 Tde<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CS3<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.21 Burst Read Timing (Bank Active, Different Bank, CAS Latency 1)**

**==> picture [287 x 284] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tnop Tc1 Tc2 Tc3 Tc4 Tde<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CS3<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.22 Burst Read Timing (Bank Active, Same Row Addresses in the Same Bank, CAS Latency 1)**

**==> picture [350 x 281] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tp Tpw Tr Tc1 Tc2 Tc3 Tc4 Tde<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CS3<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.23 Burst Read Timing (Bank Active, Different Row Addresses in the Same Bank, CAS Latency 1)**

**==> picture [211 x 274] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Tc1<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CS3<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>            2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.24 Single Write Timing (Bank Active, Different Bank)**

**==> picture [131 x 242] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tnop Tc1<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CS3<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>**----- End of picture text -----**<br>

Notes: 1. Address pin to be connected to pin A10 of SDRAM. 2. The waveform for DACKn is when active low is specified.

**Figure 8.25 Single Write Timing (Bank Active, Same Row Addresses in the Same Bank)**

**==> picture [192 x 243] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Tr Tc1<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CS3<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>**----- End of picture text -----**<br>

Notes:  1. Address pin to be connected to pin A10 of SDRAM. 2. The waveform for DACKn is when active low is specified.

**Figure 8.26 Single Write Timing (Bank Active, Different Row Addresses in the Same Bank)**

## (8) Refreshing

This module has a function for controlling SDRAM refreshing. Auto-refreshing can be performed by clearing the RMODE bit to 0 and setting the RFSH bit to 1 in SDCR. A continuous refreshing can be performed by setting the RRC2 to RRC0 bits in RTCSR. If SDRAM is not accessed for a long period, self-refresh mode, in which the power consumption for data retention is low, can be activated by setting both the RMODE bit and the RFSH bit to 1.

## (a) Auto-refreshing

Refreshing is performed at intervals determined by the input clock selected by bits CKS2 to CKS0 in RTCSR, and the value set by in RTCOR. The value of bits CKS2 to CKS0 in RTCOR should be set so as to satisfy the refresh interval stipulation for the SDRAM used. First make the settings for RTCOR, RTCNT, and the RMODE and RFSH bits in SDCR, and then make the CKS2 to CKS0 and RRC2 to RRC0 settings. When the clock is selected by bits CKS2 to CKS0, RTCNT starts counting up from the value at that time. The RTCNT value is constantly compared with the RTCOR value, and if the two values are the same, a refresh request is generated and an auto-refresh is performed for the number of times specified by the RRC2 to RRC0. At the same time, RTCNT is cleared to zero and the count-up is restarted.

Figure 8.27 shows the auto-refresh cycle timing. After starting the auto refreshing, PALL command is issued in the Tp cycle to make all the banks to pre-charged state from active state when some bank is being pre-charged. Then REF command is issued in the Trr cycle after inserting idle cycles of which number is specified by the WTRP1 and WTRP0 bits in CS3WCR. A new command is not issued for the duration of the number of cycles specified by the WTRC1 and WTRC0 bits in CS3WCR after the Trr cycle. The WTRC1 and WTRC0 bits must be set so as to satisfy the SDRAM refreshing cycle time stipulation (tRC). An idle cycle is inserted between the Tp cycle and Trr cycle when the setting value of the WTRP1 and WTRP0 bits in CS3WCR is longer than or equal to 1 cycle.

**==> picture [264 x 264] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Trr Trc Trc Trc<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0 Hi-z<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.27 Auto-Refresh Timing**

## (b) Self-refreshing

Self-refresh mode is a kind of standby mode, in which the refresh timing and refresh addresses are generated within the SDRAM. Self-refreshing is activated by setting both the RMODE bit and the RFSH bit in SDCR to 1. After starting the self-refreshing, PALL command is issued in Tp cycle after the completion of the pre-charging bank. A SELF command is then issued after inserting idle cycles of which number is specified by the WTRP1 and WTRP0 bits in CS3WSR. SDRAM cannot be accessed while in the self-refresh state. Self-refresh mode is cleared by clearing the RMODE bit to 0. After self-refresh mode has been cleared, command issuance is disabled for the number of cycles specified by the WTRC1 and WTRC0 bits in CS3WCR.

Self-refresh timing is shown in Figure 8.28 . Settings must be made so that self-refresh clearing and data retention are performed correctly, and auto-refreshing is performed at the correct intervals. When self-refreshing is activated from the state in which auto-refreshing is set, auto-refreshing is restarted if the RFSH bit is set to 1 and the RMODE bit is cleared to 0 when self-refresh mode is cleared. If the transition from clearing of self-refresh mode to the start of auto-refreshing takes time, this time should be taken into consideration when setting the initial value of RTCNT. Making the RTCNT value 1 less than the RTCOR value will enable refreshing to be started immediately.

After self-refreshing has been set, the self-refresh state continues even if the chip standby state is entered using the LSI standby function, and is maintained even after recovery from standby mode due to an interrupt. Note that the necessary signals such as CKE must be driven even in standby state by setting the HIZCNT bit in CMNCR to 1.

In case of a power-on reset, the bus state controller's registers are initialized, and therefore the self-refresh state is cleared.

**==> picture [317 x 283] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Trr Trc Trc Trc<br>CKIO<br>CKE<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0 Hi-z<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.28 Self-Refresh Timing**

## (9) Relationship between Refresh Requests and Bus Cycles

If a refresh request occurs during bus cycle execution, the refresh cycle must wait for the bus cycle to be completed. If a new refresh request occurs while waiting for the previous refresh request, the previous refresh request is deleted. To refresh correctly, a bus cycle longer than the refresh interval must be prevented from occurring.

## (10) Power-Down Mode

If the PDOWN bit in SDCR is set to 1, the SDRAM is placed in power-down mode by bringing the CKE signal to the low level in the non-access cycle. This power-down mode can effectively lower the power consumption in the nonaccess cycle. However, note that if an access occurs in power-down mode, a cycle of overhead occurs because a cycle is needed to assert the CKE in order to cancel the power-down mode. Figure 8.29 shows the access timing in power-down mode.

**==> picture [315 x 285] intentionally omitted <==**

**----- Start of picture text -----**<br>
Power-down Tnop Tr Tc1 Td1 Tde Tap Power-down<br>CKIO<br>CKE<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.29 Power-Down Mode Access Timing**

## (11) Power-On Sequence

In order to use SDRAM, mode setting must first be made for SDRAM after the pose interval specified for the SDRAM to be used after powering on. The pose interval should be obtained by a power-on reset generating circuit or software. To perform SDRAM initialization correctly, the registers of this module must first be set, followed by a write to the SDRAM mode register. In SDRAM mode register setting, the address signal value at that time is latched by a combination of the CSn, RAS, CAS, and RD/WR signals. If the value to be set is X, the bus state controller provides for value X to be written to the SDRAM mode register by performing a 16-bit write to address H'3FFFD000 + X for area 2 SDRAM, and to address H'3FFFE000 + X for area 3 SDRAM. In this operation the data is ignored, but the mode write is performed as a byte-size access. To set burst read/single write or burst read/burst write (CAS latency 2 to 3, wrap type = sequential, and burst length 1) supported by the LSI, arbitrary data is written in 16 bits to the access addresses shown in Table 8.15 . In this time 0 is output at the external address pins of A12 or later.

## **Table 8.15 Access Address in SDRAM Mode Register Write**

- Setting for Area 2

Burst read/single write (burst length 1):

|**Data Bus Width**|**CAS Latency**<br>**Access Address**<br>**External Address Pin**|
|---|---|
|16 bits|2<br>H'3FFFD440<br>H'0000440|
||3<br>H'3FFFD460<br>H'0000460|
|32 bits|2<br>H'3FFFD880<br>H'0000880|
||3<br>H'3FFFD8C0<br>H'00008C0|

Burst read/burst write (burst length 1):

|**Data Bus Width**|**CAS Latency**<br>**Access Address**<br>**External Address Pin**|
|---|---|
|16 bits|2<br>H'3FFFD040<br>H'0000040|
||3<br>H'3FFFD060<br>H'0000060|
|32 bits|2<br>H'3FFFD080<br>H'0000080|
||3<br>H'3FFFD0C0<br>H'00000C0|

- Setting for Area 3

   - Burst read/single write (burst length 1):

|**Data Bus Width**|**CAS Latency**<br>**Access Address**<br>**External Address Pin**|
|---|---|
|16 bits|2<br>H'3FFFE440<br>H'0000440|
||3<br>H'3FFFE460<br>H'0000460|
|32 bits|2<br>H'3FFFE880<br>H'0000880|
||3<br>H'3FFFE8C0<br>H'00008C0|

Burst read/burst write (burst length 1):

|**Data Bus Width**|**CAS Latency**<br>**Access Address**<br>**External Address Pin**|
|---|---|
|16 bits|2<br>H'3FFFE040<br>H'0000040|
||3<br>H'3FFFE060<br>H'0000060|
|32 bits|2<br>H'3FFFE080<br>H'0000080|
||3<br>H'3FFFE0C0<br>H'00000C0|

Mode register setting timing is shown in Figure 8.30 . A PALL command (all bank pre-charge command) is firstly issued. A REF command (auto refresh command) is then issued 8 times. An MRS command (mode register write command) is finally issued. Idle cycles, of which number is specified by the WTRP1 and WTRP0 bits in CS3WCR, are inserted between the PALL and the first REF. Idle cycles, of which number is specified by the WTRC1 and WTRC0 bits in CS3WCR, are inserted between REF and REF, and between the 8th REF and MRS. One or more idle cycles are inserted between the MRS and a command to be issued next.

It is necessary to keep idle time of certain cycles for SDRAM before issuing PALL command after power-on. Refer to the manual of the SDRAM for the idle time to be needed. When the pulse width of the reset signal is longer than the idle time, mode register setting can be started immediately after the reset, but care should be taken when the pulse width of the reset signal is shorter than the idle time.

**==> picture [395 x 243] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Trr Trc Trc Trr Trc Trc Tmw Tnop<br>PALL REF REF MRS<br>CKIO<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>  DQMxx<br>D31 to D0 Hi-Z<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.30 SDRAM Mode Write Timing (Based on JEDEC)**

## (12) Low-Power SDRAM

The low-power SDRAM can be accessed using the same protocol as the normal SDRAM.

The differences between the low-power SDRAM and normal SDRAM are that partial refresh takes place that puts only a part of the SDRAM in the self-refresh state during the self-refresh function, and that power consumption is low during refresh under user conditions such as the operating temperature. The partial refresh is effective in systems in which the data in a work area other than the specific area can be lost without severe repercussions. For details, refer to the Data Sheet for the low-power SDRAM to be used.

The low-power SDRAM supports the extension mode register in addition to the mode registers as the normal SDRAM. This LSI supports issuing of the extension mode register write command (EMRS).

The EMRS command is issued according to the conditions specified in table below. For example, if data H'0YYYYYYY is written to address H'3FFFEXX0 in 32 bits, the commands are issued to the CS3 space in the following sequence: PALL -> REF  8 -> MRS -> EMRS. In this case, the MRS and EMRS issue addresses are H'0000XX0 and H'YYYYYYY, respectively. If data H'1YYYYYYY is written to address H'3FFFEXX0 in 32 bits, the commands are issued to the CS3 space in the following sequence: PALL -> MRS -> EMRS.

**Table 8.16 Output Addresses when EMRS Command Is Issued**

||||**Write Access**|**MRS Command**|**EMRS Command**|
|---|---|---|---|---|---|
|**Command to be Issued**|**Access Address**|**Access Data**|**Size**|**Issue Address**|**Issue Address**|
|CS2 MRS|H'3FFFDXX0|H'********|16 bits|H'0000XX0|―|
|CS3 MRS|H'3FFFEXX0|H'********|16 bits|H'0000XX0|―|
|CS2 MRS + EMRS|H'3FFFDXX0|H'0YYYYYYY|32 bits|H'0000XX0|H'YYYYYYY|
|(with refresh)||||||
|CS3 MRS + EMRS|H'3FFFEXX0|H'0YYYYYYY|32 bits|H'0000XX0|H'YYYYYYY|
|(with refresh)||||||
|CS2 MRS + EMRS|H'3FFFDXX0|H'1YYYYYYY|32 bits|H'0000XX0|H'YYYYYYY|
|(without refresh)||||||
|CS3 MRS + EMRS|H'3FFFEXX0|H'1YYYYYYY|32 bits|H'0000XX0|H'YYYYYYY|
|(without refresh)||||||

**==> picture [368 x 256] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Trr Trc Trc Trr Trc Trc Tmw Tnop Temw Tnop<br>PALL REF REF MRS EMRS<br>CKIO<br>A25 to A0<br>BA1* [1]<br>BA0* [2]<br>A12/A11* [3]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0 Hi-Z<br>BS<br>DACKn* [4]<br>Notes:  1. Address pin to be connected to pin BA1 of SDRAM.<br>             2. Address pin to be connected to pin BA0 of SDRAM.<br>             3. Address pin to be connected to pin A10 of SDRAM.<br>             4. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.31 EMRS Command Issue Timing**

- Deep power-down mode

The low-power SDRAM supports the deep power-down mode as a low-power consumption mode. In the partial self-refresh function, self-refresh is performed on a specific area. In the deep power-down mode, self-refresh will not be performed on any memory area. This mode is effective in systems where all of the system memory areas are used as work areas.

If the RMODE bit in the SDCR is set to 1 while the DEEP and RFSH bits in the SDCR are set to 1, the low-power SDRAM enters the deep power-down mode. If the RMODE bit is cleared to 0, the CKE signal is pulled high to cancel the deep power-down mode. Before executing an access after returning from the deep power-down mode, the power-up sequence must be re-executed.

**==> picture [316 x 249] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Tdpd Trc Trc Trc Trc Trc<br>CKIO<br>CKE<br>A25 to A0<br>A12/A11* [1]<br>CSn<br>RAS<br>CAS<br>RD/WR<br>DQMxx<br>D31 to D0 Hi-Z<br>BS<br>DACKn* [2]<br>Notes:  1. Address pin to be connected to pin A10 of SDRAM.<br>             2. The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.32 Deep Power-Down Mode Transition Timing**

## 8.5.7 Burst ROM (Clocked Asynchronous) Interface

The burst ROM (clocked asynchronous) interface is used to access a memory with a high-speed read function using a method of address switching called the burst mode or page mode. In a burst ROM (clocked asynchronous) interface, basically the same access as the normal space is performed, but the 2nd and subsequent access cycles are performed only by changing the address, without negating the RD signal at the end of the 1st cycle. In the 2nd and subsequent access cycles, addresses are changed at the falling edge of the CKIO.

For the 1st access cycle, the number of wait cycles specified by the W3 to W0 bits in CSnWCR is inserted. For the 2nd and subsequent access cycles, the number of wait cycles specified by the BW1 and BW0 bits in CSnWCR is inserted. In the access to the burst ROM (clocked asynchronous), the BS signal is asserted only to the first access cycle. An external wait input is valid only to the first access cycle.

In the single access or write access that does not perform the burst operation in the burst ROM (clocked asynchronous) interface, access timing is same as a normal space.

Table 8.17 lists a relationship between bus width, access size, and the number of bursts. Figure 8.33 shows a timing chart.

**Table 8.17 Relationship between Bus Width, Access Size, and Number of Bursts**

|**Bus Width**|**Access Size**|**CSnWCR. BST[1:0] Bits**|**Number of Bursts**<br>**Access Count**|
|---|---|---|---|
|8 bits|8 bits|Not affected|1<br>1|
||16 bits|Not affected|2<br>1|
||32 bits|Not affected|4<br>1|
||16 bytes|00|16<br>1|
|||01|4<br>4|
||32 bytes|00|16<br>2|
|||01|4<br>8|
||64 bytes|00|16<br>4|
|||01|4<br>16|
|16 bits|8 bits|Not affected|1<br>1|
||16 bits|Not affected|1<br>1|
||32 bits|Not affected|2<br>1|
||16 bytes|00|8<br>1|
|||01|2<br>4|
|||10*1|4<br>2|
||||2, 4, 2<br>3|
||32 bytes|00|8<br>2|
|||01|2<br>8|
|||10*1|4<br>4|
||||2, 4, 2<br>6|
||64 bytes|00|8<br>4|
|||01|2<br>16|
|||10*1|4<br>8|
||||2, 4, 2<br>12|
|32 bits|8 bits|Not affected|1<br>1|
||16 bits|Not affected|1<br>1|
||32 bits|Not affected|1<br>1|
||16 bytes|Not affected|4<br>1|
||32 bytes|Not affected|4<br>2|
||64 bytes|Not affected|4<br>4|

Note 1. When the bus width is 16 bits, the access size is 16 bytes or more, and the BST[1:0] bits in CSnWCR are 10, the number of bursts and access count depend on the access start address. At address H'xxx0 or H'xxx8, 4-4 burst access is performed. At address H'xxx4 or H'xxxC, 2-4-2 burst access is performed.

**==> picture [314 x 230] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1  Tw  Tw  T2B  Twb  T2B  Twb  T2B  Twb    T2<br>CKIO<br>A25 to A0<br>CSn<br>RD/WR<br>RD<br>D31 to D0<br>WAIT<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.33 Burst ROM Access Timing (Clocked Asynchronous) (Bus Width = 32 Bits, 16-Byte Transfer (Number of Burst 4), Wait Cycles Inserted in First Access = 2, Wait Cycles Inserted in Second and Subsequent Access Cycles = 1)**

## 8.5.8 SRAM Interface with Byte Selection

The SRAM interface with byte selection is a memory interface that outputs the byte selection signal (WEn) in both read and write bus cycles. This interface has 16-bit data pins and accesses SRAMs having upper and lower byte selection pins, such as UB and LB.

When the BAS bit in CSnWCR is cleared to 0 (initial value), the write access timing of the SRAM interface with byte selection is the same as that for the normal space interface. While in read access of a byte-selection SRAM interface, the byte-selection signal is output from the WEn pin, which is different from that for the normal space interface. The basic access timing is shown in Figure 8.34 . In write access, data is written to the memory according to the timing of the byteselection pin (WEn). For details, refer to the Data Sheet for the corresponding memory.

If the BAS bit in CSnWCR is set to 1, the WEn pin and RD/WR pin timings change. Figure 8.35 shows the basic access timing. In write access, data is written to the memory according to the timing of the write enable pin (RD/WR). The data hold timing from RD/WR negation to data write must be acquired by setting the HW1 and HW0 bits in CSnWCR. Figure 8.36 shows the access timing when a software wait is specified.

**==> picture [273 x 357] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 T2<br>CKIO<br>A25 to A0<br>CSn<br>WEn<br>RD/WR<br>Read RD<br>D31 to D0<br>RD/WR<br>High<br>Write RD<br>D31 to D0<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.34 Basic Access Timing for SRAM with Byte Selection (BAS = 0)**

**==> picture [273 x 343] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 T2<br>CKIO<br>A25 to A0<br>CSn<br>WEn<br>RD/WR<br>Read RD<br>D31 to D0<br>RD/WR<br>High<br>Write RD<br>D31 to D0<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.35 Basic Access Timing for SRAM with Byte Selection (BAS = 1)**

**==> picture [358 x 348] intentionally omitted <==**

**----- Start of picture text -----**<br>
Th T1 Tw T2 Tf<br>CKIO<br>A25 to A0<br>CSn<br>WEn<br>RD/WR<br>Read RD<br>D31 to D0<br>RD/WR<br>High<br>Write RD<br>D31 to D0<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.36 Wait Timing for SRAM with Byte Selection (BAS = 1) (SW[1:0] = 01, WR[3:0] = 0001, HW[1:0] = 01)**

**==> picture [320 x 291] intentionally omitted <==**

**----- Start of picture text -----**<br>
64K × 16-bit<br>This LSI SRAM<br>A17 A15<br>A2 A0<br>CSn CS<br>RD OE<br>RD/WR WE<br>D31 I/O15<br>D16 I/O0<br>WE3 UB<br>WE2 LB<br>D15<br>A15<br>D0<br>WE1 A0<br>WE0 CS<br>OE<br>WE<br>I/O15<br>I/O0<br>UB<br>LB<br>. . . . . .<br>. . . . . .<br>. . .<br>. . .<br>. . .<br>**----- End of picture text -----**<br>

**Figure 8.37 Example of Connection with 32-Bit Data-Width SRAM with Byte Selection**

**==> picture [205 x 148] intentionally omitted <==**

**----- Start of picture text -----**<br>
64K × 16-bit<br>This LSI SRAM<br>A16 A15<br>      .       .<br>      .       .<br>      .       .<br>A1 A0<br>CSn CS<br>RD OE<br>RD/WR WE<br>D15 I/O 15<br>      .       .<br>      .       .<br>      .D0       .I/O 0<br>WE1 UB<br>WE0 LB<br>**----- End of picture text -----**<br>

**Figure 8.38 Example of Connection with 16-Bit Data-Width SRAM with Byte Selection**

## 8.5.9 Burst ROM (Clocked Synchronous) Interface

The burst ROM (clocked synchronous) interface is supported to access a ROM with a synchronous burst function at high speed. The burst ROM interface accesses the burst ROM in the same way as a normal space. This interface is valid only for area 0.

In the first access cycle, wait cycles are inserted. In this case, the number of wait cycles to be inserted is specified by the W3 to W0 bits in CS0WCR. In the second and subsequent cycles, the number of wait cycles to be inserted is specified by the BW1 and BW0 bits in CS0WCR.

While the burst ROM (clocked synchronous) is accessed, the BS signal is asserted only for the first access cycle and an external wait input is also valid for the first access cycle.

When the bus width is 16 bits, the burst length must be specified as 8. When the bus width is 32 bits, the burst length must be specified as 4. The burst ROM interface does not support the 8-bit bus width for the burst ROM.

The burst ROM interface performs burst operations for all read access. For example, in a 32-bit access over a 16-bit bus, valid 16-bit data is read two times and invalid 16-bit data is read six times. These invalid data read cycles increase the memory access time and degrade the program execution speed and DMA transfer speed. To prevent this problem, it is recommended using a read in a 16-byte or more access size. The burst ROM interface performs write access in the same way as normal space access.

**==> picture [403 x 114] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 Tw Tw T2B Twb T2B Twb T2B Twb T2B Twb T2B Twb T2B Twb T2B Twb T2<br>CKIO<br>A25 to A0<br>CS0<br>RD/WR<br>RD<br>D15 to D0<br>WAIT<br>BS<br>DACKn*<br>Note: * The waveform for DACKn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 8.39 Burst ROM Access Timing (Clocked Synchronous) (Burst Length = 8, Wait Cycles Inserted in First Access = 2, Wait Cycles Inserted in Second and Subsequent Access Cycles = 1)**

## 8.5.10 Wait between Access Cycles

As the operating frequency of LSIs becomes higher, the off-operation of the data buffer often collides with the next data access when the read operation from devices with slow access speed is completed. As a result of these collisions, the reliability of the device is low and malfunctions may occur. A function that avoids data collisions by inserting idle (wait) cycles between continuous access cycles has been newly added.

The number of wait cycles between access cycles can be set by the WM bit in CSnWCR, bits IWW2 to IWW0, IWRWD2 to IWRWD0, IWRWS2 to IWRWS0, IWRRD2 to IWRRD0, and IWRRS2 to IWRRS 0 in CSnBCR. The conditions for setting the idle cycles between access cycles are shown below.

1. Continuous access cycles are write-read or write-write

2. Continuous access cycles are read-write for different spaces

3. Continuous access cycles are read-write for the same space

4. Continuous access cycles are read-read for different spaces

5. Continuous access cycles are read-read for the same space

For the specification of the number of idle cycles between access cycles described above, refer to the description of each register.

Besides the idle cycles between access cycles specified by the registers, idle cycles must be inserted to interface with the internal bus or to obtain the minimum pulse width for a multiplexed pin (WEn). The following gives detailed information about the idle cycles and describes how to estimate the number of idle cycles.

The number of idle cycles on the external bus from CSn negation to CSn or CSm assertion is described below.

There are seven conditions that determine the number of idle cycles on the external bus as shown in Table 8.18 . The effects of these conditions are shown in Figure 8.40 .

**Table 8.18 Conditions for Determining Number of Idle Cycles**

|**No.**|**Condition**|**Description**|**Range**|**Note**|
|---|---|---|---|---|
|[1]|IW***[2:0] in|These bits specify the number of idle cycles for|0 to 12|Do not set 0 for the number of idle|
||CSnBCR|access. The number of idle cycles can be specified||cycles between memory types which|
|||independently for each combination of the previous||are not allowed to be accessed|
|||and next cycles. For example, in the case where||successively.|
|||reading CS1 space followed by reading other CS|||
|||space, the bits IWRRD[2:0] in CS1BCR should be|||
|||set to B'100 to specify six or more idle cycles. This|||
|||condition is effective only for access cycles other|||
|||than single address transfer and generates idle|||
|||cycles after the access is completed.|||
|[2]|SDRAM-related bits|These bits specify precharge completion and|0 to 3|Specify these bits in accordance with|
||in CSnWCR|startup wait cycles and idle cycles between||the specification of the target SDRAM.|
|||commands for SDRAM access. This condition is|||
|||effective only for SDRAM access and generates|||
|||idle cycles after the access is completed|||
|[3]|WM in CSnWCR|This bit enables or disables external WAIT<br>pin input|0 or 1||
|||for the memory types other than SDRAM. When|||
|||this bit is cleared to 0 (external WAIT<br>enabled),one|||
|||idle cycle is inserted to check the external WAIT<br>pin|||
|||input after the access is completed. When this bit is|||
|||set to 1 (disabled), no idle cycle is generated.|||
|[4]|Read data transfer|One idle cycle is inserted after a read access is|0 or 1|One idle cycle is always generated|
||cycle|completed. This idle cycle is not generated for the||after a read cycle with SDRAM.|
|||first or middle cycles in divided access cycles. This|||
|||is neither generated when the HW[1:0] bits in|||
|||CSnWCR are not B'00.|||
|[5]|Internal bus idle|External bus access requests from the CPU or the|0 or|The number of internal bus idle cycles|
||cycles, etc.|direct memory access controller and their results|larger|may not become 0 depending on the|
|||are passed through the internal bus. The external||CPU: internal bus: CKIO|
|||bus enters idle state during internal bus idle cycles|||
|||or while a bus other than the external bus is being|||
|||accessed. This condition is not effective for divided|||
|||access cycles, which are generated by the bus|||
|||state controller when the access size is larger than|||
|||the external data bus width.|||
|[6]|Write data wait|During write access, a write cycle is executed on|0 or 1|For write → write or write → read|
||cycles|the external bus only after the write data becomes||access cycles, successive access|
|||ready. This write data wait period generates idle||cycles without idle cycles may be|
|||cycles before the write cycle. Note that when the||available due to the write buffer effect|
|||previous cycle is a write cycle and the internal bus||described in the left column. If|
|||idle cycles are shorter than the previous write cycle,||successive access cycles without idle|
|||write data can be prepared in parallel with the||cycles are not allowed, specify the|
|||previous write cycle and therefore, no idle cycle is||minimum number of idle cycles|
|||generated (write buffer effect).||between access cycles through|
|||||CSnBCR.|
|[7]|Idle cycles between|To ensure the minimum pulse width on the signal-|0 to 2|The number of idle cycles depends on|
||different memory|multiplexed pins, idle cycles may be inserted before||the target memory types. See Table|
||types|access after memory types are switched. For some||8.19.|
|||memory types, idle cycles are inserted even when|||
|||memory types are not switched.|||

In the above conditions, a total of four conditions, that is, condition [1], condition [2] or [3] (either one is effective), a set of conditions [4] to [6] (these are generated successively, and therefore the sum of them should be taken as one set of idle cycles), and condition [7] are generated at the same time. The maximum number of idle cycles among these four conditions become the number of idle cycles on the external bus. To ensure the minimum idle cycles, be sure to make register settings for condition [1].

**==> picture [308 x 283] intentionally omitted <==**

**----- Start of picture text -----**<br>
CKIO<br>Previous access External bus idle cycles Next access<br>CSn<br>Idle cycle after access Idle cycle before access<br>[1] IW***[2:0] setting in CSnBCR Condition [1]<br>[2] WTRP[1:0] setting in CSnWCR<br>TRWL[1:0] setting in CSnWCR<br>WTRC[1:0] setting in CSnWCR Either one of them Condition [2] or [3]<br>is effective<br>[3] WM setting in CSnWCR<br>[4] Read [6] Write Set of conditions<br>data [5] Internal bus idle cycles, etc. data<br>transfer wait [4] to [6]<br>[7] Idle cycles<br>between<br>different Condition [7]<br>memory types<br>Note: A total of four conditions (condition [1], condition [2] or [3], a set of conditions [4] to [6],<br>and condition [7]) generate idle cycle at the same time. Accordingly, the maximum number of<br>cycles among these four conditions become the number of idle cycles.<br>**----- End of picture text -----**<br>

## **Figure 8.40 Idle Cycle Conditions**

**Table 8.19 Number of Idle Cycles Inserted between Access Cycles to Different Memory Types**

|**Previous Cycle**|**Next Cycle**|
|---|---|
||**SRAM**<br>**Burst ROM**<br>**(Asynchronous)**<br>**MPX-I/**<br>**O**<br>**Byte SRAM**<br>**(BAS = 0)**<br>**Byte SRAM**<br>**(BAS = 1)**<br>**SDRAM**<br>**Burst ROM**<br>**(Synchronous)**|
|SRAM|0<br>0<br>1<br>0<br>0/1*<br>0/1*<br>0|
|Burst ROM<br>(asynchronous)|0<br>0<br>1<br>0<br>0/1*<br>0/1*<br>0|
|MPX-I/O|1<br>1<br>0<br>1<br>1<br>1<br>1|
|Byte SRAM<br>(BAS = 0)|0<br>0<br>1<br>0<br>0/1*<br>0/1*<br>0|
|Byte SRAM<br>(BAS = 1)|0/1*<br>0/1*<br>1/2*<br>0/1*<br>0<br>0<br>0/1*|
|SDRAM|1<br>1<br>2<br>1<br>0<br>0<br>1|
|Burst ROM<br>(synchronous)|0<br>0<br>1<br>0<br>1<br>1<br>0|

Note: * The number of idle cycles is determined by the setting of bits HW[1:0] in the CSnWCR register for the previous cycle. The values on the left and right sides of the virgules show the numbers of idle cycles when HW[1:0] ≠ B'00 and HW[1:0] = B'00, respectively. If the memory connected to the CSn space in the previous cycle is of a type for which bits HW[1:0] in the CSnWCR register are ineffective, the number of idle cycles will be the value on the right side.

## 8.5.11 Others

## (1) Reset

This module can be initialized completely only at power-on reset. At power-on reset, all signals are negated and data output buffers are turned off regardless of the bus cycle state after the internal reset is synchronized with the internal clock. All control registers are initialized. In software standby and sleep, control registers of the bus state controller are not initialized.

## (2) Caution on Write Buffer

Since the bus state controller incorporates a one-stage write buffer, it can execute an access via the internal bus before the previous external bus cycle is completed in a write cycle. If the on-chip module is read or written after the external lowspeed memory is written, the on-chip module can be accessed before the completion of the external low-speed memory write cycle.

In read cycles, the CPU is placed in the wait state until read operation has been completed. To continue the process after the data write to the device has been completed, perform a dummy read to the same address to check for completion of the write before the next process to be executed.

The write buffer of the bus state controller functions in the same way for an access by a bus master other than the CPU such as the direct memory access controller. Accordingly, to perform DMA transfers, the next read cycle is initiated before the previous write cycle is completed. Note, however, that if both the DMA source and destination addresses exist in external memory space, the next read cycle will not be initiated until the previous write cycle is completed. Changing the registers in this module while the write buffer is operating may disrupt correct write access. Therefore, do not change the registers in this module immediately after a write access. If this change becomes necessary, do it after executing a dummy read of the write data.

## (3) On-Chip Peripheral Module Access

To access an on-chip module register, two or more peripheral module clock (P0  or P1  ) cycles are required. When the CPU writes data to the internal peripheral registers, the CPU performs the succeeding instructions without waiting for the completion of writing to registers.

For example, a case is described here in which the system is transferring to the software standby mode for power savings. To make this transition, the WFI instruction must be performed after setting the STBY bit in the STBCR1 register to 1. However a dummy read of the STBCR1 register is required before executing the WFI instruction. If a dummy read is omitted, the CPU executes the WFI instruction before the STBY bit is set to 1, thus the system enters sleep mode not software standby mode. A dummy read of the STBCR1 register is indispensable to complete writing to the STBY bit. To reflect the change by internal peripheral registers while performing the succeeding instructions, execute a dummy read of registers to which write instruction is given and then perform the succeeding instructions.
