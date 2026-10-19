# 42. Power-Down Modes

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2219–2263. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI supports sleep mode, software standby mode, deep standby mode, and module standby mode. In power-down modes, functions of CPU, clocks, on-chip memory, or part of on-chip peripheral modules are halted or the power-supply is turned off, through which low power consumption is achieved. These modes are canceled by a reset or interrupt.

## 42.1 Features

## 42.1.1 States of Processing and Power-Down Modes

## (1) States of processing

This LSI has three general states of processing: the reset state, the program execution state, and the power-down modes. Figure 42.1 shows transitions between these states.

**==> picture [438 x 303] intentionally omitted <==**

**----- Start of picture text -----**<br>
Power-on reset from any state<br>Realtime clock alarm interrupt,<br>change on the pins for canceling,<br>Power-on reset or generation of a power-on reset<br>Reset state<br>Release from the reset state<br>Occurrence of a source condition for exception handling Exception handling Generation of an NMI<br>interrupt (FIQ exception)<br>or IRQ interrupt<br>(IRQ exception)<br>Occurrence of a source condition  End of exception<br>for exception handling handling<br>User mode<br>Program<br>execution state<br>Execution of WFI or WFE* [1] Execution of WFI instruction  Execution of WFI instruction<br>instruction with STBY bit  with STBY bit set to 1 and  with STBY bit set to 1 and<br>cleared to 0. DEEP bit cleared to 0. DEEP bit set to 1.<br>Sleep mode Software standby mode Deep standby mode<br>Power-down modes<br>Note 1. When using the WFE instruction, execute the following three instructions in the given sequence:<br>SEV, WFE, and WFE. The instruction to be executed at the time of a transition to the sleep mode<br>depends on a condition. For details, see 42.3.1 (1) Transition to Sleep Mode.<br>**----- End of picture text -----**<br>

**Figure 42.1 Transitions between Processing States**

## (2) Power-down modes

This LSI has the following power-down modes and function:

1. Sleep mode

2. Software standby mode

3. Deep standby mode

4. Module standby function

Table 42.1 shows the transition conditions for entering the modes from the program execution state, as well as the CPU and peripheral module states in each mode and the procedures for canceling each mode.

## **Table 42.1 States of Power-Down Modes**

|**Power-**<br>**Down**<br>**Mode**<br>**Transition**<br>**Conditions**|**State**<br>**CPU, CPU**<br>**Register,**<br>**Primary**<br>**Cache, TLB**<br>**Secondary**<br>**Cache**<br>**Large-Capacity On-**<br>**Chip RAM**<br>**(including on-chip**<br>**data-retention RAM)**<br>**On-Chip**<br>**Peripheral**<br>**Modules**<br>**Realtime**<br>**Clock**<br>**Internal**<br>**Power**<br>**Supply**<br>**External**<br>**Memory**<br>**Canceling**<br>**Procedure**|
|---|---|
|Sleep<br>mode<br>Execute WFI or<br>WFE*6instruction<br>with STBY bit in<br>STBCR1 cleared to<br>0|<br>Halted<br>Contents<br>are held.*4<br>Running<br>Running<br>Running<br>Running*1<br>Applied<br>Auto-refresh<br>Interrupt<br>Power-on reset|
|Software<br>standby<br>mode<br>Execute WFI<br>instruction with<br>STBY and DEEP<br>bits in STBCR1 set<br>to 1 and 0,<br>respectively|<br>Halted<br>Contents<br>are held.*4<br>Halted<br>Contents<br>are held.*4<br>Halted<br>Contents<br>are held.*5<br>Halted<br>Running*1<br>Applied<br>Self-refresh<br>NMI or IRQ<br>interrupt<br>Power-on reset|
|Deep<br>standby<br>mode<br>Execute WFI<br>instruction with<br>STBY and DEEP<br>bits in STBCR1 set<br>to 1|<br>Halted<br>Contents<br>are not held.<br>Halted<br>Contents<br>are not<br>held.<br>Halted<br>Contents in on-chip data-<br>retention RAM are<br>held*2, and the other<br>contents in large-<br>capacity on-chip RAM<br>are not held.<br>Halted<br>Running*1<br>Shut off<br>Self-refresh<br>Power-on reset*3<br>Realtime clock<br>alarm interrupt*3<br>Change on the<br>pins for canceling*3|
|Module<br>standby<br>mode<br>Set the MSTP bits<br>in STBCR2 to<br>STBCR12 to 1|Running<br>Running<br>Running<br>Specified<br>module<br>halted<br>Halted<br>Applied<br>Auto-refresh<br>Clear MSTP bit to<br>0|

Note 1. The realtime clock operates when the START bit in the RCR2 register is set to 1. For details, see section 13, Realtime Clock. When deep standby mode is canceled by a power-on reset, the running state cannot be retained. Make the initial setting for the realtime clock again.

- Note 2. Setting the bits RRAMKP3 to RRAMKP0 in the RRAMKP register to 1 enables to retain the data in the corresponding area on the on-chip data-retention RAM during the transition to deep standby mode. When the deep standby mode is canceled by a power-on reset, the retained contents are initialized.

- Note 3. Deep standby mode can be canceled by a power-on reset, a realtime clock alarm interrupt, or change on the pins for canceling (P2_0, P2_2, P2_7, P2_9, P5_8, P5_9, P5_10, P6_7, P7_2, P7_3, P7_6, P7_9, and NMI). Even when deep standby mode is canceled by a source other than a power-on reset, the reset exception handling is executed instead of the interrupt exception handling.

- Note 4. When sleep mode or software standby mode is canceled by a power-on reset, the retained contents are initialized. Note 5. By setting the VRAME bit in the SYSCR1 register or VRAMWE bit in the SYSCR2 register to enable accesses, the retained contents are initialized when software standby mode is canceled by a power-on reset. By setting the VRAME bit in the SYSCR1 register or VRAMWE bit in the SYSCR2 register to disable accesses, contents in the large-capacity on-chip RAM (including onchip data-retention RAM) can be retained when software standby mode is canceled by a power-on reset. Note that the area at addresses from H’2002_0000 to H’2002_3FFF is used as working memory for the boot program in boot modes 1 to 3. In boot modes 2 and 3, a 28-Kbyte program is transferred from the external flash memory to the area at addresses from H’2002_4000 to H’2002_AFFF. For details, see section 3, Boot Mode.

- Note 6. When using the WFE instruction, execute the following three instructions in the given sequence: SEV, WFE, and WFE. The instruction to be executed at the time of a transition to the sleep mode depends on a condition. For details, see section 42.3.1, (1) Transition to Sleep Mode.

## 42.2 Register Descriptions

Table 42.2 shows the register configuration.

## **Table 42.2 Register Configuration**

|**Table 42.2**<br>**Register Configuration**||||||
|---|---|---|---|---|---|
||||**Initial**||**Access**|
|**Register Name**|**Abbreviation**|**R/W**|**Value**|**Address**|**Size**|
|Standby control register 1|STBCR1|R/W|H'00|H'FCFE0020|8|
|Standby control register 2|STBCR2|R/W|H'6A|H'FCFE0024|8|
|Standby control register 3|STBCR3|R/W|H'FD|H'FCFE0420|8|
|Standby control register 4|STBCR4|R/W|H'FF|H'FCFE0424|8|
|Standby control register 5|STBCR5|R/W|H'FF|H'FCFE0428|8|
|Standby control register 6|STBCR6|R/W|H'FE|H'FCFE042C|8|
|Standby control register 7|STBCR7|R/W|H'3F|H'FCFE0430|8|
|Standby control register 8|STBCR8|R/W|H'FF|H'FCFE0434|8|
|Standby control register 9|STBCR9|R/W|H'FF|H'FCFE0438|8|
|Standby control register 10|STBCR10|R/W|H'FF|H'FCFE043C|8|
|Standby control register 11|STBCR11|R/W|H'FF|H'FCFE0440|8|
|Standby control register 12|STBCR12|R/W|H'FF|H'FCFE0444|8|
|Software reset control register 1|SWRSTCR1|R/W|H'00|H'FCFE0460|8|
|Software reset control register 2 (RZ/A1LU only)|SWRSTCR2|R/W|H'00|H'FCFE0464|8|
|System control register 1|SYSCR1|R/W|H'FF|H'FCFE0400|8|
|System control register 2|SYSCR2|R/W|H'FF|H'FCFE0404|8|
|System control register 3|SYSCR3|R/W|H'00|H'FCFE0408|8|
|CPU status register|CPUSTS|R|H'00|H'FCFE0018|8|
|Standby request register 1|STBREQ1|R/W|H'00|H'FCFE0030|8|
|Standby request register 2|STBREQ2|R/W|H'00|H'FCFE0034|8|
|Standby acknowledge register 1|STBACK1|R|H'00|H'FCFE0040|8|
|Standby acknowledge register 2|STBACK2|R|H'00|H'FCFE0044|8|
|On-chip data-retention RAM area setting|RRAMKP|R/W|H'00|H'FCFF1800|8|
|register||||||
|Deep standby control register|DSCTR|R/W|H'00|H'FCFF1802|8|
|Deep standby cancel source select register|DSSSR|R/W|H'0000|H'FCFF1804|16|
|Deep standby cancel edge select register|DSESR|R/W|H'0000|H'FCFF1806|16|
|Deep standby cancel source flag register|DSFR|R/W|H'0000|H'FCFF1808|16|
|XTAL crystal oscillator gain control register|XTALCTR|R/W|H'00|H'FCFF1810|8|

## 42.2.1 Standby Control Register 1 (STBCR1)

STBCR1 is an 8-bit readable/writable register that specifies the state of the power-down mode.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||STBY||DEEP|-<br>-<br>-<br>-<br>-<br>-||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R/W||R/W|R<br>R<br>R<br>R<br>R<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|STBY|0|R/W|||Software Standby, Deep Standby||
|6|DEEP|0|R/W|||Specifies transition to software standby mode or deep standby mode.||
|||||||0x: Executing WFI or WFE*1instruction puts chip into sleep mode.||
|||||||10: Executing WFI instruction puts chip into software standby mode.*2||
|||||||11: Executing WFI instruction puts chip into deep standby mode.*2||
|||||||Note 1. When using the WFE instruction, execute the following three||
|||||||instructions in the given sequence: SEV, WFE, and WFE. The||
|||||||instruction to be executed at the time of a transition to the sleep||
|||||||mode depends on a condition. For details, see section 42.3.1,||
|||||||(1) Transition to Sleep Mode.||
|||||||Note 2. Do not execute the WFE instruction while the STBY bit in||
|||||||STBCR1 is 1.||
|5 to 0|—|All 0|R|||Reserved||
|||||||These bits are always read as 0. The write value should always be 0.||

[Legend]

x: Don't care

## 42.2.2 Standby Control Register 2 (STBCR2)

STBCR2 is an 8-bit readable/writable register that controls the operation of each module.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||HIZ||-|-<br>-<br>-<br>-<br>-<br>MSTP<br>20||
|||Initial value:|0||1|1<br>0<br>1<br>0<br>1<br>0||
|||R/W:|R/W||R|R<br>R<br>R<br>R<br>R<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|HIZ|0|R/W|||Port High Impedance||
|||||||Selects whether the state of specific output pin is retained or high||
|||||||impedance in software standby mode|or deep standby mode. As to which|
|||||||pins are controlled, see section 48.1, Pin States in section 48, States and||
|||||||Handling of Pins.||
|||||||0: The pin state is retained in software standby mode or deep standby||
|||||||mode.||
|||||||1: The pin is set to high-impedance in software standby mode or deep||
|||||||standby mode.||
|6, 5|—|All 1|R|||Reserved||
|||||||These bits are always read as 1. The|write value should always be 1.|
|4|—|0|R|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|3|—|1|R|||Reserved||
|||||||This bit is always read as 1. The write value should always be 1.||
|2|—|0|R|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|1|—|1|R|||Reserved||
|||||||This bit is always read as 1. The write value should always be 1.||
|0|MSTP20|0|R/W|||Module Stop 20*1[not for disclosure]||
|||||||When the MSTP20 bit is set to 1, the|clock supply to CoreSight is halted.|
|||||||0: CoreSight runs.||
|||||||1: Clock supply to CoreSight is halted.||

Note 1. The transition to and release from module stop mode proceed in the steps described in section 42.3.5, Module Standby Function.

## 42.2.3 Standby Control Register 3 (STBCR3)

STBCR3 is an 8-bit readable/writable register that controls the operation of each module.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||MSTP||MSTP|MSTP<br>MSTP<br>MSTP<br>—<br>MSTP<br>—||
||||37*1||36|35*1<br>32<br>31<br>33||
|||Initial value:|1||1|1<br>1<br>1<br>1<br>1<br>0||
|||R/W:|R/W||R/W|R/W<br>R<br>R/W<br>R/W<br>R/W<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|MSTP37*1|1|R/W|||Module Stop 37||
|||||||When the MSTP37 bit is set to 1, the|clock supply to the IEBusTM|
|||||||controller is halted.||
|||||||0: The IEBusTMcontroller runs.||
|||||||1: Clock supply to the IEBusTMcontroller is halted.||
|6|MSTP36|1|R/W|||Module Stop 36||
|||||||When the MSTP36 bit is set to 1, the|clock supply to serial|
|||||||communication interface (IrDA) is halted.||
|||||||0: Serial communication interface (IrDA) runs.||
|||||||1: Clock supply to serial communication interface (IrDA) is halted.||
|5|MSTP35*1|1|R/W|||Module Stop 35||
|||||||When the MSTP35 bit is set to 1, the|clock supply to the LIN interface|
|||||||channel 0 is halted.||
|||||||0: The LIN interface channel 0 runs.||
|||||||1: Clock supply to the LIN interface channel 0 is halted.||
|4|―|1|R|||Reserved||
|||||||This bit is always read as 1. The write value should always be 1.||
|3|MSTP33|1|R/W|||Module Stop 33||
|||||||When the MSTP33 bit is set to 1, the|clock supply to the multi-function|
|||||||timer pulse unit 2 is halted.||
|||||||0: The multi-function timer pulse unit 2 runs.||
|||||||1: Clock supply to the multi-function timer pulse unit 2 is halted.||
|2|MSTP32|1|R/W|||Module Stop 32||
|||||||When the MSTP32 bit is set to 1, the clock supply to the CAN interface is||
|||||||halted.||
|||||||0: The CAN interface runs.||
|||||||1: Clock supply to the CAN interface is halted.||
|1|MSTP31|0|R/W|||Module Stop 31||
|||||||When the MSTP31 bit is set to 1, the|clock supply to the A/D converter is|
|||||||halted and the analog power supply to the A/D converter is shut off.||
|||||||0: Clock signal and analog voltage are supplied to the A/D converter.||
|||||||1: Supply of clock signal and analog voltage to the A/D converter is shut||
|||||||off.||
|0|―|1|R|||Reserved||
|||||||This bit is always read as 1. The write value should always be 1.||

Note 1. This bit is only present in the RZ/A1L. For the RZ/A1LU and RZ/A1LC, the write value should always be 1.

## 42.2.4 Standby Control Register 4 (STBCR4)

STBCR4 is an 8-bit readable/writable register that controls the operation of each module.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||MSTP||MSTP|MSTP<br>MSTP<br>MSTP<br>—<br>—<br>—||
||||47||46|45<br>44<br>43||
|||Initial value:|1||1|1<br>1<br>1<br>1<br>1<br>1||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R<br>R<br>R<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|MSTP47|1|R/W|||Module Stop 47||
|||||||When the MSTP47 bit is set to 1, the|clock supply to channel 0 of the|
|||||||serial communication interface with FIFO is halted.||
|||||||0: Channel 0 of the serial communication interface with FIFO runs.||
|||||||1: Clock supply to channel 0 of the serial communication interface with||
|||||||FIFO is halted.||
|6|MSTP46|1|R/W|||Module Stop 46||
|||||||When the MSTP46 bit is set to 1, the|clock supply to channel 1 of the|
|||||||serial communication interface with FIFO is halted.||
|||||||0: Channel 1 of the serial communication interface with FIFO runs.||
|||||||1: Clock supply to channel 1 of the serial communication interface with||
|||||||FIFO is halted.||
|5|MSTP45|1|R/W|||Module Stop 45||
|||||||When the MSTP45 bit is set to 1, the|clock supply to channel 2 of the|
|||||||serial communication interface with FIFO is halted.||
|||||||0: Channel 2 of the serial communication interface with FIFO runs.||
|||||||1: Clock supply to channel 2 of the serial communication interface with||
|||||||FIFO is halted.||
|4|MSTP44|1|R/W|||Module Stop 44||
|||||||When the MSTP44 bit is set to 1, the|clock supply to channel 3 of the|
|||||||serial communication interface with FIFO is halted.||
|||||||0: Channel 3 of the serial communication interface with FIFO runs.||
|||||||1: Clock supply to channel 3 of the serial communication interface with||
|||||||FIFO is halted.||
|3|MSTP43|1|R/W|||Module Stop 43||
|||||||When the MSTP43 bit is set to 1, the|clock supply to channel 4 of the|
|||||||serial communication interface with FIFO is halted.||
|||||||0: Channel 4 of the serial communication interface with FIFO runs.||
|||||||1: Clock supply to channel 4 of the serial communication interface with||
|||||||FIFO is halted.||
|2 to 0|―|All 1|R|||Reserved||
|||||||These bits are always read as 1. The|write value should always be 1.|

## 42.2.5 Standby Control Register 5 (STBCR5)

STBCR5 is an 8-bit readable/writable register that controls the operation of each module.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2|1|0||
|---|---|---|---|---|---|---|---|---|---|
||||MSTP||MSTP|—<br>—<br>—<br>—|MSTP|MSTP||
||||57||56||51|50||
|||Initial value:|1||1|1<br>1<br>1<br>1|1|1||
|||R/W:|R/W||R/W|R<br>R<br>R<br>R|R/W|R/W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||
|7|MSTP57|1|R/W|||Module Stop 57||||
|||||||When the MSTP57 bit is set to||1, the|clock supply to channel 0 of the|
|||||||serial communication interface||(SCI) is halted.||
|||||||0: Channel 0 of the serial communication interface (SCI) runs.||||
|||||||1: Clock supply to channel 0 of the serial communication interface (SCI)||||
|||||||is halted.||||
|6|MSTP56|1|R/W|||Module Stop 56||||
|||||||When the MSTP56 bit is set to||1, the|clock supply to channel 1 of the|
|||||||serial communication interface||(SCI) is halted.||
|||||||0: Channel 1 of the serial communication interface (SCI) runs.||||
|||||||1: Clock supply to channel 1 of the serial communication interface (SCI)||||
|||||||is halted.||||
|5 to 2|―|All 1|R|||Reserved||||
|||||||These bits are always read as||1. The|write value should always be 1.|
|1|MSTP51|1|R/W|||Module Stop 51||||
|||||||When the MSTP51 bit is set to||1, the clock supply to channel 0 of the OS||
|||||||timer is halted.||||
|||||||0: Channel 0 of the OS timer runs.||||
|||||||1: Clock supply to channel 0 of the OS timer is halted.||||
|0|MSTP50|1|R/W|||Module Stop 50||||
|||||||When the MSTP50 bit is set to||1, the clock supply to channel 1 of the OS||
|||||||timer is halted.||||
|||||||0: Channel 1 of the OS timer runs.||||
|||||||1: Clock supply to channel 1 of the OS timer is halted.||||

## 42.2.6 Standby Control Register 6 (STBCR6)

STBCR6 is an 8-bit readable/writable register that controls the operation of each module.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|
||||MSTP||MSTP|—<br>—<br>—<br>MSTP<br>—|MSTP||
||||67||66|61*2|60||
|||Initial value:|1||1|1<br>1<br>1<br>1<br>1|0||
|||R/W:|R/W||R/W|R<br>R<br>R<br>R<br>R/W|R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7|MSTP67|1|R/W|||Module Stop 67|||
|||||||When the MSTP67 bit is set to|1, the|clock supply to the A/D converter is|
|||||||halted.|||
|||||||0: The A/D converter runs.|||
|||||||1: Clock supply to channel 0 of the A/D converter is halted.|||
|6|MSTP66|1|R/W|||Module Stop 66*1|||
|||||||When the MSTP66 bit is set to|1, the|clock supply to the capture engine|
|||||||unit is halted.|||
|||||||0: The capture engine unit runs.|||
|||||||1: Clock supply to the capture engine||unit is halted.|
|5 to 2|―|All 1|R|||Reserved|||
|||||||These bits are always read as|1. The|write value should always be 1.|
|1|MSTP61*2|1|R/W|||Module Stop 61*1|||
|||||||When the MSTP61 bit is set to|1, the clock supply to the JPEG codec unit||
|||||||is halted.|||
|||||||0: The JPEG codec unit runs.|||
|||||||1: Clock supply to the JPEG codec unit is halted.|||
|0|MSTP60|0|R/W|||Module Stop 60|||
|||||||When the MSTP60 bit is set to|1, the|clock supply to the realtime clock is|
|||||||halted.|||
|||||||0: The realtime clock runs.|||
|||||||1: Clock supply to the realtime|clock is halted.||
|||||||Note: When the realtime clock|is halted, set the bits in registers shown||
|||||||below.|||
|||||||Set bit RTCEN in the control|register 2 (RCR2) to 0.||
|||||||Set bits RCKSEL[1:0] in the control||register 5 (RCR5) to 00.|
|||||||After the settings above, set bit MSTP60 to 1.|||

Note 1. The transition to and release from module stop mode proceed in the steps described in section 42.3.5, Module Standby Function.

Note 2. This bit is only present in the RZ/A1LU. For the RZ/A1L and RZ/A1LC, the write value should always be 1.

## 42.2.7 Standby Control Register 7 (STBCR7)

STBCR7 is an 8-bit readable/writable register that controls the operation of each module.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3||2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|
||||—||—|MSTP<br>—<br>—||—|MSTP|MSTP||
|||||||74|||71|70||
|||Initial value:|0||0|1<br>1<br>1||1|1|1||
|||R/W:|R||R|R<br>R/W<br>R||R|R/W|R/W||
|||**Initial**||||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||||
|7, 6|—|All 0|R|||Reserved||||||
|||||||These bits are always read as 0. The write value should always be 0.||||||
|5|—|1|R|||Reserved||||||
|||||||This bit is always read as 1. The write|||||value should always be 1.|
|4|MSTP74|1|R/W|||Module Stop 74*1||||||
|||||||When the MSTP74||bit is|set to 1, the clock supply to the Ethernet|||
|||||||controller is halted.||||||
|||||||0: The Ethernet controller runs.||||||
|||||||1: Clock supply to|the Ethernet|||controller is halted.||
|3, 2|—|All 1|R|||Reserved||||||
|||||||These bits are always read as 1. The write value should always be 1.||||||
|1|MSTP71|1|R/W|||Module Stop 71||||||
|||||||When the MSTP71||bit is|set to 1, the clock supply to channel 0 of the|||
|||||||USB 2.0 host/function module is halted.||||||
|||||||0: Channel 0 of the||USB|2.0 host/function module runs.|||
|||||||1: Clock supply to|channel 0 of|||the USB 2.0 host/function module is||
|||||||halted.||||||
|0|MSTP70|1|R/W|||Module Stop 70||||||
|||||||When the MSTP70||bit is|set to 1, the clock supply to channel 1 of the|||
|||||||USB 2.0 host/function module is halted.||||||
|||||||0: Channel 1 of the||USB|2.0 host/function module runs.|||
|||||||1: Clock supply to|channel 1 of|||the USB 2.0 host/function module is||
|||||||halted.||||||

Note 1. The transition to and release from module stop mode proceed in the steps described in section 42.3.5, Module Standby Function.

## 42.2.8 Standby Control Register 8 (STBCR8)

STBCR8 is an 8-bit readable/writable register that controls the operation of each module.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|
||||—||—|—<br>MSTP<br>MSTP<br>MSTP<br>MST|—||
|||||||84<br>83*2<br>82*3<br>P81|||
|||Initial value:|1||1|1<br>1<br>1<br>1<br>1|1||
|||R/W:|R||R|R<br>R/W<br>R/W<br>R/W<br>R/W|R||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7 to 5|—|All 1|R|||Reserved|||
|||||||These bits are always read as|1. The|write value should always be 1.|
|4|MSTP84|1|R/W|||Module Stop 84|||
|||||||When the MSTP84 bit is set to|1, the|clock supply to the MMC host|
|||||||interface is halted.|||
|||||||0: The MMC host interface runs.|||
|||||||1: Clock supply to the MMC host interface is halted.|||
|3|MSTP83*2|1|R/W|||Module Stop 83*1|||
|||||||When the MSTP83 bit is set to|1, the|clock supply to the media local bus|
|||||||is halted.|||
|||||||0: The media local bus runs.|||
|||||||1: Clock supply to the media local bus is halted.|||
|2|MSTP82*3|1|R/W|||Module Stop 82*1|||
|||||||When the MSTP82 bit is set to|1, the|clock supply to the EthernetAVB is|
|||||||halted.|||
|||||||0: The EthernetAVB runs.|||
|||||||1: Clock supply to the EthernetAVB is halted.|||
|1|MSTP81|1|R/W|||Module Stop 81|||
|||||||When the MSTP81 bit is set to|1, the|clock supply to SCUX is halted.|
|||||||0: SCUX runs.|||
|||||||1: Clock supply to SCUX is halted.|||
|0|—|1|R|||Reserved|||
|||||||This bit is always read as 1. The write value should always be 1.|||

Note 1. The transition to and release from module stop mode proceed in the steps described in section 42.3.5, Module Standby Function.

Note 2. This bit is only present in the RZ/A1L. For the RZ/A1LU and RZ/A1LC, the write value should always be 1.

Note 3. This bit is only present in the RZ/A1LU. For the RZ/A1L and RZ/A1LC, the write value should always be 1.

## 42.2.9 Standby Control Register 9 (STBCR9)

STBCR9 is an 8-bit readable/writable register that controls the operation of each module.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||MSTP||MSTP|MSTP<br>MSTP<br>—<br>MSTP<br>MSTP<br>—||
||||97||96|95<br>94<br>91<br>93||
|||Initial value:|1||1|1<br>1<br>1<br>1<br>1<br>1||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R<br>R<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|MSTP97|1|R/W|||Module Stop 97||
|||||||When the MSTP97 bit is set to 1, the clock supply to channel 0 of the I2C||
|||||||bus interface is halted.||
|||||||0: Channel 0 of the I2C bus interface runs.||
|||||||1: Clock supply to channel 0 of the I2C bus interface is halted.||
|6|MSTP96|1|R/W|||Module Stop 96||
|||||||When the MSTP96 bit is set to 1, the|clock supply to channel 1 of the I2C|
|||||||bus interface is halted.||
|||||||0: Channel 1 of the I2C bus interface runs.||
|||||||1: Clock supply to channel 1 of the I2C bus interface is halted.||
|5|MSTP95|1|R/W|||Module Stop 95||
|||||||When the MSTP95 bit is set to 1, the|clock supply to channel 2 of the I2C|
|||||||bus interface is halted.||
|||||||0: Channel 2 of the I2C bus interface runs.||
|||||||1: Clock supply to channel 2 of the I2C bus interface is halted.||
|4|MSTP94|1|R/W|||Module Stop 94||
|||||||When the MSTP94 bit is set to 1, the|clock supply to channel 3 of the I2C|
|||||||bus interface is halted.||
|||||||0: Channel 3 of the I2C bus interface runs.||
|||||||1: Clock supply to channel 3 of the I2C bus interface is halted.||
|3|MSTP93|1|R/W|||Module Stop 93||
|||||||When the MSTP93 bit is set to 1, the clock supply to channel 0 of the SPI||
|||||||multi I/O bus controller is halted.||
|||||||0: Channel 0 of the SPI multi I/O bus|controller runs.|
|||||||1: Clock supply to channel 0 of the SPI multi I/O bus controller is halted.||
|2|—|1|R|||Reserved||
|||||||This bit is always read as 1. The write value should always be 1.||
|1|MSTP91|1|R/W|||Module Stop 91*1||
|||||||When the MSTP91 bit is set to 1, the|clock supply to the video display|
|||||||controller 5 is halted.||
|||||||0: The video display controller 5 runs.||
|||||||1: Clock supply to the video display controller 5 is halted.||
|0|—|1|R|||Reserved||
|||||||This bit is always read as 1. The write value should always be 1.||

Note 1. The transition to and release from module stop mode proceed in the steps described in section 42.3.5, Module Standby Function.

## 42.2.10 Standby Control Register 10 (STBCR10)

STBCR10 is an 8-bit readable/writable register that controls the operation of each module.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2||1<br>0||
|---|---|---|---|---|---|---|---|---|---|
||||MSTP||MSTP|MSTP<br>—<br>MSTP<br>—|MSTP<br>—|||
||||107||106|105<br>102*1||101||
|||Initial value:|1||1|1<br>1<br>1<br>1||1<br>1||
|||R/W:|R/W||R/W|R/W<br>R<br>R<br>R/W||R<br>R/W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||
|7|MSTP107|1|R/W|||Module Stop 107||||
|||||||When the MSTP107 bit|is|set to 1, the clock supply to channel 0 of the||
|||||||Renesas serial peripheral||interface is halted.||
|||||||0: Channel 0 of the Renesas serial peripheral interface runs.||||
|||||||1: Clock supply to channel 0 of the Renesas serial peripheral interface is||||
|||||||halted.||||
|6|MSTP106|1|R/W|||Module Stop 106||||
|||||||When the MSTP106 bit|is|set to 1, the clock supply to channel 1 of the||
|||||||Renesas serial peripheral||interface is halted.||
|||||||0: Channel 1 of the Renesas serial peripheral interface runs.||||
|||||||1: Clock supply to channel 1 of the Renesas serial peripheral interface is||||
|||||||halted.||||
|5|MSTP105|1|R/W|||Module Stop 105||||
|||||||When the MSTP105 bit|is|set to 1, the clock supply to channel 2 of the||
|||||||Renesas serial peripheral||interface is halted.||
|||||||0: Channel 2 of the Renesas serial peripheral interface runs.||||
|||||||1: Clock supply to channel 2 of the Renesas serial peripheral interface is||||
|||||||halted.||||
|4, 3|—|All 1|R|||Reserved||||
|||||||These bits are always read as 1. The|||write value should always be 1.|
|2|MSTP102*1|1|R/W|||Module Stop 102||||
|||||||When the MSTP102 bit|is|set to 1, the clock supply to the CD-ROM||
|||||||decoder is halted.||||
|||||||0: The CD-ROM decoder||runs.||
|||||||1: Clock supply to the CD-ROM decoder is halted.||||
|1|MSTP101|1|R/W|||Module Stop 101||||
|||||||When the MSTP101 bit|is|set to 1, the clock supply to the Renesas||
|||||||SPDIF interface is halted.||||
|||||||0: The Renesas SPDIF interface runs.||||
|||||||1: Clock supply to the Renesas SPDIF interface is halted.||||
|0|—|1|R|||Reserved||||
|||||||This bit is always read as||1. The write value should always be 1.||

Note 1. This bit is only present in the RZ/A1L. For the RZ/A1LU and RZ/A1LC, the write value should always be 1.

## 42.2.11 Standby Control Register 11 (STBCR11)

STBCR11 is an 8-bit readable/writable register that controls the operation of each module.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||—||—|MSTP<br>MSTP<br>MSTP<br>MSTP<br>—<br>—||
|||||||115<br>114<br>112<br>113||
|||Initial value:|1||1|1<br>1<br>1<br>1<br>1<br>1||
|||R/W:|R||R|R/W<br>R/W<br>R/W<br>R/W<br>R<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7, 6|—|All 1|R|||Reserved||
|||||||These bits are always read as 1. The|write value should always be 1.|
|5|MSTP115|1|R/W|||Module Stop 115||
|||||||When the MSTP115 bit is set to 1, the clock supply to channel 0 of the||
|||||||serial sound interface is halted.||
|||||||0: Channel 0 of the serial sound interface runs.||
|||||||1: Clock supply to channel 0 of the serial sound interface is halted.||
|4|MSTP114|1|R/W|||Module Stop 114||
|||||||When the MSTP114 bit is set to 1, the clock supply to channel 1 of the||
|||||||serial sound interface is halted.||
|||||||0: Channel 1 of the serial sound interface runs.||
|||||||1: Clock supply to channel 1 of the serial sound interface is halted.||
|3|MSTP113|1|R/W|||Module Stop 113||
|||||||When the MSTP113 bit is set to 1, the clock supply to channel 2 of the||
|||||||serial sound interface is halted.||
|||||||0: Channel 2 of the serial sound interface runs.||
|||||||1: Clock supply to channel 2 of the serial sound interface is halted.||
|2|MSTP112|1|R/W|||Module Stop 112||
|||||||When the MSTP112 bit is set to 1, the clock supply to channel 3 of the||
|||||||serial sound interface is halted.||
|||||||0: Channel 3 of the serial sound interface runs.||
|||||||1: Clock supply to channel 3 of the serial sound interface is halted.||
|1, 0|—|All 1|R|||Reserved||
|||||||These bits are always read as 1. The|write value should always be 1.|

## 42.2.12 Standby Control Register 12 (STBCR12)

STBCR12 is an 8-bit readable/writable register that controls the operation of each module.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||—||—|—<br>—<br>MSTP<br>MSTP<br>MSTP<br>MSTP||
|||||||122<br>123<br>121<br>120||
|||Initial value:|1||1|1<br>1<br>1<br>1<br>1<br>1||
|||R/W:|R||R|R<br>R<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7 to 4|—|All 1|R|||Reserved||
|||||||These bits are always read as 1. The|write value should always be 1.|
|3|MSTP123|1|R/W|||Module Stop 123||
|||||||When the MSTP123 bit is set to 1, the SD host interface 00 is halted.||
|||||||0: The SD host interface 00 runs.||
|||||||1: Clock supply to the SD host interface 00 is halted.||
|2|MSTP122|1|R/W|||Module Stop 122||
|||||||When the MSTP122 bit is set to 1, the SD host interface 01 is halted.||
|||||||0: The SD host interface 01 runs.||
|||||||1: Clock supply to the SD host interface 01 is halted.||
|1|MSTP121|1|R/W|||Module Stop 121||
|||||||When the MSTP121 bit is set to 1, the SD host interface 10 is halted.||
|||||||0: The SD host interface 10 runs.||
|||||||1: Clock supply to the SD host interface 10 is halted.||
|0|MSTP120|1|R/W|||Module Stop 120||
|||||||When the MSTP120 bit is set to 1, the SD host interface 11 is halted.||
|||||||0: The SD host interface 11 runs.||
|||||||1: Clock supply to the SD host interface 11 is halted.||

Note: For details on this register, see section 38.3.2, Card Detect/Write Protect.

## 42.2.13 Software Reset Control Register 1 (SWRSTCR1)

SWRSTCR1 is an 8-bit readable/writable register that controls a software reset for the serial sound interface and the operation of the crystal resonator for audio.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4|3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|
||||AXT||SRST|SRST<br>SRST|SRST<br>—<br>—<br>—||
||||ALE||16|15<br>14|13||
|||Initial value:|0||0|0<br>0|0<br>0<br>0<br>0||
|||R/W:|R/W||R/W|R/W<br>R/W|R/W<br>R<br>R<br>R||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7|AXTALE|0|R/W|||AUDIO_X1 Clock Control|||
|||||||Controls the function of AUDIO_X1 pin.|||
|||||||0: Runs the on-chip crystal oscillator/enables the external clock input.|||
|||||||1: Halts the on-chip crystal oscillator/disables the external clock input.|||
|6|SRST16|0|R/W|||Serial Sound Interface Channel 0 Software Reset|||
|||||||Controls the serial sound interface channel 0 reset with software.|||
|||||||0: The serial sound interface channel||0 reset is canceled.|
|||||||1: The serial sound interface channel||0 is reset.|
|5|SRST15|0|R/W|||Serial Sound Interface Channel 1 Software Reset|||
|||||||Controls the serial sound interface channel 1 reset with software.|||
|||||||0: The serial sound interface channel||1 reset is canceled.|
|||||||1: The serial sound interface channel||1 is reset.|
|4|SRST14|0|R/W|||Serial Sound Interface Channel 2 Software Reset|||
|||||||Controls the serial sound interface channel 2 reset with software.|||
|||||||0: The serial sound interface channel||2 reset is canceled.|
|||||||1: The serial sound interface channel||2 is reset.|
|3|SRST13|0|R/W|||Serial Sound Interface Channel 3 Software Reset|||
|||||||Controls the serial sound interface channel 3 reset with software.|||
|||||||0: The serial sound interface channel||3 reset is canceled.|
|||||||1: The serial sound interface channel||3 is reset.|
|2 to 0|—|All 0|R|||Reserved|||
|||||||These bits|are always read as 0. The|write value should always be 0.|

## 42.2.14 Software Reset Control Register 2 (SWRSTCR2)

This register is only provided in the RZ/A1LU.

SWRSTCR2 is an 8-bit readable/writable register that controls a software reset for each module.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|
||||-||-|SRST<br>-<br>-<br>-<br>-|-||
|||||||21|||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0|0||
|||R/W:|R||R|R<br>R<br>R<br>R<br>R/W|R||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7 to 2|—|All 0|R|||Reserved|||
|||||||These bits are always read as 0. The write value should always be 0.|||
|1|SRST21|0|R/W|||JPEG Codec Unit Software Reset|||
|||||||Controls the JPEG codec unit reset with software.|||
|||||||0: The JPEG codec unit reset is canceled.|||
|||||||1: The JPEG codec unit is reset.|||
|0|—|0|R|||Reserved|||
|||||||This bit is always read as 0. The write||value should always be 0.|

## 42.2.15 System Control Register 1 (SYSCR1)

SYSCR1 is an 8-bit readable/writable register that enables or disables access (read and write) to a specified page in the large-capacity on-chip RAM.

When a VRAMEn (n = 0 to 4) bit in SYSCR1 is set to 1, access to page n is enabled. When a VRAMEn bit is cleared to 0, page n cannot be accessed. In this case, an undefined value is returned when reading data or fetching an instruction from page n, and writing to page n is ignored. The initial value of a VRAMEn bit is 1.

SYSCR1 should be set with a program located in an area other than the large-capacity on-chip RAM. Furthermore, an instruction to read SYSCR1 should be located immediately after the instruction to write to SYSCR1. If not, normal access is not guaranteed.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4|3||2<br>1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|
||||—||—|—<br>VRAME|VRAME||VRAME<br>VRAME|VRAME||
|||||||4|3||2<br>1|0||
|||Initial value:|1||1|1<br>1|1||1<br>1|1||
|||R/W:|R||R|R<br>R/W|R/W||R/W<br>R/W|R/W||
|||**Initial**||||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||||
|7 to 5|—|All 1|R|||Reserved||||||
|||||||These bits|are always read as|||1. The|write value should always be 1.|
|4|VRAME4|1|R/W|||RAM Enable 4 (corresponding||||area: page 4*1in large-capacity on-chip||
|||||||RAM)||||||
|||||||0: Access to page|||4 is disabled.|||
|||||||1: Access to page|||4 is enabled.|||
|3|VRAME3|1|R/W|||RAM Enable 3 (corresponding||||area: page 3*1in large-capacity on-chip||
|||||||RAM)||||||
|||||||0: Access to page|||3 is disabled.|||
|||||||1: Access to page|||3 is enabled.|||
|2|VRAME2|1|R/W|||RAM Enable 2 (corresponding||||area: page 2*1in large-capacity on-chip||
|||||||RAM)||||||
|||||||0: Access to page|||2 is disabled.|||
|||||||1: Access to page|||2 is enabled.|||
|1|VRAME1|1|R/W|||RAM Enable 1 (corresponding||||area: page 1*1in large-capacity on-chip||
|||||||RAM)||||||
|||||||0: Access to page|||1 is disabled.|||
|||||||1: Access to page|||1 is enabled.|||
|0|VRAME0|1|R/W|||RAM Enable 0 (corresponding||||area: page 0*1in large-capacity on-chip||
|||||||RAM)||||||
|||||||0: Access to page|||0 is disabled.|||
|||||||1: Access to page|||0 is enabled.|||

Note 1. For addresses in each page, see section 40, On-Chip RAM.

## 42.2.16 System Control Register 2 (SYSCR2)

SYSCR2 is an 8-bit readable/writable register that enables or disables writing to a specified page in the large-capacity on-chip RAM.

When a VRAMWEn (n = 0 to 4) bit in SYSCR2 is set to 1, writing to page n is enabled. When a VRAMWEn bit is cleared to 0, writing to page n is ignored. The initial value of a VRAMWEn bit is 1.

SYSCR2 should be set with a program located in an area other than the large-capacity on-chip RAM. Furthermore, an instruction to read SYSCR2 should be located immediately after the instruction to write to SYSCR2. If not, normal access is not guaranteed.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4|3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|---|
||||—||—|—<br>VRAM|VRAM<br>VRAM<br>VRAM|VRAM||
|||||||WE4|WE3<br>WE2<br>WE1|WE0||
|||Initial value:|1||1|1<br>1|1<br>1<br>1|1||
|||R/W:|R||R|R<br>R/W|R/W<br>R/W<br>R/W|R/W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||
|7 to 5|—|All 1|R|||Reserved||||
|||||||These bits are always read as 1. The|||write value should always be 1.|
|4|VRAMWE4|1|R/W|||RAM Write|Enable 4 (corresponding area: page 4*1in large-capacity on-|||
|||||||chip RAM)||||
|||||||0: Writing to page 4 is disabled.||||
|||||||1: Writing to page 4 is enabled.||||
|3|VRAMWE3|1|R/W|||RAM Write|Enable 3 (corresponding area: page 3*1in large-capacity on-|||
|||||||chip RAM)||||
|||||||0: Writing to page 3 is disabled.||||
|||||||1: Writing to page 3 is enabled.||||
|2|VRAMWE2|1|R/W|||RAM Write|Enable 2 (corresponding area: page 2*1in large-capacity on-|||
|||||||chip RAM)||||
|||||||0: Writing to page 2 is disabled.||||
|||||||1: Writing to page 2 is enabled.||||
|1|VRAMWE1|1|R/W|||RAM Write|Enable 1 (corresponding area: page 1*1in large-capacity on-|||
|||||||chip RAM)||||
|||||||0: Writing to page 1 is disabled.||||
|||||||1: Writing to page 1 is enabled.||||
|0|VRAMWE0|1|R/W|||RAM Write|Enable 0 (corresponding area: page 0*1in large-capacity on-|||
|||||||chip RAM)||||
|||||||0: Writing to page 0 is disabled.||||
|||||||1: Writing to page 0 is enabled.||||

Note 1. For addresses in each page, see section 40, On-Chip RAM.

## 42.2.17 System Control Register 3 (SYSCR3)

SYSCR3 is an 8-bit readable/writable register that enables or disables writing to a specified page in the on-chip dataretention RAM.

When a RRAMWEn (n = 0 to 3) bit in SYSCR3 is set to 1, writing to page n is enabled. When a RRAMWEn bit is cleared to 0, writing to page n is ignored. The initial value of a RRAMWEn bit is 0.

SYSCR3 should be set with a program located in an area other than the on-chip data-retention RAM.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|
||||—||—|—<br>—<br>RRAM<br>RRAM<br>RRAM|RRAM||
|||||||WE3<br>WE2<br>WE1|WE0||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0|0||
|||R/W:|R||R|R<br>R<br>R/W<br>R/W<br>R/W|R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7 to 4|—|All 0|R|||Reserved|||
|||||||These bits are always read as|0. The|write value should always be 0.|
|3|RRAMWE3|0|R/W|||RAM Write Enable 3 (corresponding area: page 3*2in on-chip data-|||
|||||||retention RAM)|||
|||||||0: Writing to page 3 is disabled.|||
|||||||1: Writing to page 3 is enabled.|||
|2|RRAMWE2|0|R/W|||RAM Write Enable 2 (corresponding area: page 2*2in on-chip data-|||
|||||||retention RAM)|||
|||||||0: Writing to page 2 is disabled.|||
|||||||1: Writing to page 2 is enabled.|||
|1|RRAMWE1|0|R/W|||RAM Write Enable 1 (corresponding area: page 1*2in on-chip data-|||
|||||||retention RAM)|||
|||||||0: Writing to page 1 is disabled.|||
|||||||1: Writing to page 1 is enabled.|||
|0|RRAMWE0|0|R/W|||RAM Write Enable 0 (corresponding area: page 0*2in on-chip data-|||
|||||||retention RAM)|||
|||||||0: Writing to page 0 is disabled.|||
|||||||1: Writing to page 0 is enabled.|||

Note 1. For addresses in each page, see section 40, On-Chip RAM.

Note 2. When the VRAME0 bit in SYSCR1 is cleared to 0 (access to page 0 in large-capacity on-chip RAM is invalid), the on-chip dataretention RAM cannot be accessed (read and written), regardless of the setting of this bit.

When the VRAMWE0 bit in SYSCR2 is cleared to 0 (writing to page 0 in large-capacity on-chip RAM is invalid), the on-chip dataretention RAM cannot be written, regardless of the setting of this bit.

## 42.2.18 CPU Status Register (CPUSTS)

CPUSTS is an 8-bit readable register that indicates the status of the CPU.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|
||||—||—|—<br>ISBUSY<br>—<br>—<br>—|—||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0|0||
|||R/W:|R||R|R<br>R<br>R<br>R<br>R|R||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7 to 5|—|All 0|R|||Reserved|||
|||||||These bits are always read as|0.||
|4|ISBUSY|0|R|||State during Changing of the Frequency of CPU and Return from|||
|||||||Software Standby|||
|||||||Indicates that the frequency of|CPU is being changed or that return from||
|||||||software standby is in progress. Do not execute a WFI instruction while|||
|||||||this bit is 1.|||
|||||||0: The frequency of CPU is not being||changed and returning from|
|||||||software standby is not in progress|||
|||||||1: The frequency of CPU is being changed or return from software|||
|||||||standby is in progress|||
|3 to 0|—|All 0|R|||Reserved|||
|||||||These bits are always read as|0.||

## 42.2.19 Standby Request Register 1 (STBREQ1)

This register is used to request notification of whether a CPU or peripheral module is ready for standby. The CPU or peripheral module returns a standby acknowledgement on receipt of a request for notification if it is ready for standby.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||—||—|STBRQ<br>—<br>STBRQ<br>STBRQ<br>—<br>STBRQ||
|||||||15<br>13*2<br>12*2<br>10||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R||R|R/W<br>R<br>R/W<br>R/W<br>R/W<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7, 6|—|All 0|R|||Reserved||
|||||||These bits are always read as 0. The|write value should always be 0.|
|5|STBRQ15|0|R/W|||Standby Request to CoreSight||
|||||||0: The standby request to CoreSight is invalid.||
|||||||1: The standby request to CoreSight is valid.*1||
|4|—|0|R|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|3|STBRQ13*2|0|R/W|||Standby Request to JPEG Codec Unit||
|||||||0: The standby request to the JPEG codec unit is invalid.||
|||||||1: The standby request to the JPEG codec unit is valid.*1||
|2|STBRQ12*2|0|R/W|||Standby Request to EthernetAVB||
|||||||0: The standby request to the EthernetAVB is invalid.||
|||||||1: The standby request to the EthernetAVB is valid.*1||
|1|—|0|R|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|0|STBRQ10|0|R/W|||Standby Request to Capture Engine Unit||
|||||||0: The standby request to the capture engine unit is invalid.||
|||||||1: The standby request to the capture engine unit is valid.*1||

Note 1. When the MSTP bit for the corresponding module is 1, writing 1 to the STBRQ bit has no effect. Note 2. This bit is only present in the RZ/A1LU. For the RZ/A1L and RZ/A1LC, the write value should always be 0.

## 42.2.20 Standby Request Register 2 (STBREQ2)

This register is used to request notification of whether a peripheral module is ready for standby. The peripheral module returns a standby acknowledgement on receipt of a request for notification if it is ready for standby.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5|4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|
||||STBRQ||STBRQ|STBRQ|—<br>—<br>—<br>—<br>—||
||||27*2||26|25|||
|||Initial value:|0||0|0|0<br>0<br>0<br>0<br>0||
|||R/W:|R/W||R/W|R/W|R<br>R<br>R<br>R<br>R||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7|STBRQ27*2|0|R/W|||Standby Request to the media local bus|||
|||||||0: The standby request to the media local bus is invalid.|||
|||||||1: The standby request to the media local bus is valid.*1|||
|6|STBRQ26|0|R/W|||Standby Request to Ethernet Controller|||
|||||||0: The standby request to the Ethernet controller is invalid.|||
|||||||1: The standby request to the Ethernet controller is valid.*1|||
|5|STBRQ25|0|R|||Standby Request to Video Display Controller 5|||
|||||||0: The standby request to the video display controller 5 is invalid.|||
|||||||1: The standby request to of the video display controller 5 is valid.*1|||
|4 to 0|—|All 0|R|||Reserved|||
|||||||These bits are always read as 0. The||write value should always be 0.|

Note 1. When the MSTP bit for the corresponding module is 1, writing 1 to the STBRQ bit has no effect.

Note 2. This bit is only present in the RZ/A1L. For the RZ/A1LU and RZ/A1LC, the write value should always be 0.

## 42.2.21 Standby Acknowledge Register 1 (STBACK1)

This register is used to provide notification that a CPU or peripheral module is in the standby ready state. The CPU or peripheral module returns a standby acknowledgement on reception of a standby notification request if it is ready for standby. This register is a read-only register.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||—||—|STBAK<br>—<br>STBAK<br>STBAK<br>—<br>STBAK||
|||||||15<br>13*2<br>12*2<br>10||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R||R|R<br>R<br>R<br>R<br>R<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7, 6|—|All 0|R|||Reserved||
|||||||These bits are always read as 0.||
|5|STBAK15|0|R|||Standby Acknowledgement from CoreSight||
|||||||0: The standby acknowledgement from CoreSight is invalid.||
|||||||1: The standby acknowledgement from CoreSight is valid.*1||
|4|—|0|R|||Reserved||
|||||||This bit is always read as 0.||
|3|STBAK13*2|0|R|||Standby Acknowledgement from JPEG Codec Unit||
|||||||0: The standby acknowledgement from the JPEG codec unit is invalid.||
|||||||1: The standby acknowledgement from the JPEG codec unit is valid.*1||
|2|STBAK12*2|0|R|||Standby Acknowledgement from EthernetAVB||
|||||||0: The standby acknowledgement from the EthernetAVB is invalid.||
|||||||1: The standby acknowledgement from the EthernetAVB is valid.*1||
|1|—|0|R|||Reserved||
|||||||This bit is always read as 0.||
|0|STBAK10|0|R|||Standby Acknowledgement from Capture Engine Unit||
|||||||0: The standby acknowledgement from the capture engine unit is invalid.||
|||||||1: The standby acknowledgement from the capture engine unit is valid.*1||

Note 1. The bits in STBACK1 are set to 1 when a standby acknowledgement is transmitted from the module while the MSTP bit for the corresponding module is set to 0.

Note 2. This bit is only present in the RZ/A1LU.

## 42.2.22 Standby Acknowledge Register 2 (STBACK2)

This register is used to provide notification that a peripheral module is in the standby ready state. The peripheral module returns a standby acknowledgement on reception of a standby notification request if it is ready for standby. This register is a read-only register.

|||Bit:|7||6|5|4<br>3<br>2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|
||||STBAK||STBAK|STBAK|—||||
||||27*2||26|25|—<br>—|—|—||
|||Initial value:|0||0|0|0<br>0<br>0|0|0||
|||R/W:|R||R|R|R<br>R<br>R|R|R||
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||||
|7|STBAK27*2|0|R|||Standby Acknowledgement from the media local bus|||||
|||||||0: The standby acknowledgement from the media local bus is invalid.|||||
|||||||1: The standby acknowledgement from the media local bus is valid.*1|||||
|6|STBAK26|0|R|||Standby Acknowledgement from Ethernet Controller|||||
|||||||0: The standby acknowledgement from the Ethernet controller is invalid.|||||
|||||||1: The standby acknowledgement from the Ethernet controller is valid.*1|||||
|5|STBAK25|0|R|||Standby Acknowledgement from Video Display Controller 5|||||
|||||||0: The standby acknowledgement from the video display controller 5 is|||||
|||||||invalid.|||||
|||||||1: The standby acknowledgement from the video display controller 5 is|||||
|||||||valid.*1|||||
|4 to 0|—|All 0|R|||Reserved|||||
|||||||These bits are always read as|||0.||

Note 1. The bits in STBACK2 are set to 1 when a standby acknowledgement is transmitted from the module while the MSTP bit for the corresponding module is set to 0.

Note 2. This bit is only present in the RZ/A1L.

## 42.2.23 On-Chip Data-Retention RAM Area Setting Register (RRAMKP)

RRAMKP is an 8-bit readable/writable register that selects whether the contents of the corresponding area of the on-chip data-retention RAM are retained or not in deep standby mode.

When the RRAMKP3 to RRAMKP0 bits are set to 1, the contents of the corresponding area of the on-chip data-retention RAM are retained in deep standby mode. When these bits are cleared to 0, the contents of the corresponding area of the on-chip data-retention RAM are not retained in deep standby mode.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|
||||—||—|—<br>—<br>RRAM<br>RRAM<br>RRAM|RRAM||
|||||||KP3<br>KP2<br>KP1|KP0||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0|0||
|||R/W:|R||R|R<br>R<br>R/W<br>R/W<br>R/W|R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7 to 4|—|All 0|R|||Reserved|||
|||||||These bits are always read as 0. The||write value should always be 0.|
|3|RRAMKP3|0|R/W|||On-Chip Data-Retention RAM Storage Area 3 (corresponding area: page|||
|||||||3*1in on-chip data-retention RAM)|||
|||||||0: The contents of the on-chip data-retention RAM are not retained in|||
|||||||deep standby mode.|||
|||||||1: The contents of the on-chip data-retention RAM are retained in deep|||
|||||||standby mode.|||
|2|RRAMKP2|0|R/W|||On-Chip Data-Retention RAM Storage Area 2 (corresponding area: page|||
|||||||2*1in on-chip data-retention RAM)|||
|||||||0: The contents of the on-chip data-retention RAM are not retained in|||
|||||||deep standby mode.|||
|||||||1: The contents of the on-chip data-retention RAM are retained in deep|||
|||||||standby mode.|||
|1|RRAMKP1|0|R/W|||On-Chip Data-Retention RAM Storage Area 1 (corresponding area: page|||
|||||||1*1in on-chip data-retention RAM)|||
|||||||0: The contents of the on-chip data-retention RAM are not retained in|||
|||||||deep standby mode.|||
|||||||1: The contents of the on-chip data-retention RAM are retained in deep|||
|||||||standby mode.|||
|0|RRAMKP0|0|R/W|||On-Chip Data-Retention RAM Storage Area 0 (corresponding area: page|||
|||||||0*1in on-chip data-retention RAM)|||
|||||||0: The contents of the on-chip data-retention RAM are not retained in|||
|||||||deep standby mode.|||
|||||||1: The contents of the on-chip data-retention RAM are retained in deep|||
|||||||standby mode.|||

Note 1. For addresses in each page, see section 40, On-Chip RAM.

## 42.2.24 Deep Standby Control Register (DSCTR)

DSCTR is an 8-bit readable/writable register that selects whether the states of the external memory control pins are retained or not when returning from deep standby mode and specifies the method to start the LSI.

Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||EBUS||RAM|—<br>—<br>—<br>—<br>—<br>—||
||||KEEPE||BOOT|||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R/W||R/W|R<br>R<br>R<br>R<br>R<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|EBUSKEEPE|0|R/W|||Retention of External Memory Control Pin State||
|||||||0: The state of the external memory control pins is not retained when||
|||||||returning from deep standby mode.||
|||||||1: The state of the external memory control pins is retained when||
|||||||returning from deep standby mode.||
|||||||Note: The following setting is prohibited:||
|||||||(EBUSKEEPE, RAMBOOT) =|(1, 0).|
|6|RAMBOOT|0|R/W|||Selection of Method after Returning from Deep Standby Mode||
|||||||Selects an activation method after returning from deep standby mode.||
|||||||0: Activated according to the boot mode specified for a reset.||
|||||||1: The program is read from the on-chip data-retention RAM.||
|||||||Instruction fetch from H'20000000||
|||||||Note: The following setting is prohibited:||
|||||||(EBUSKEEPE, RAMBOOT) =|(1, 0).|
|5 to 0|—|All 0|R|||Reserved||
|||||||These bits are always read as 0. The|write value should always be 0.|

## 42.2.25 Deep Standby Cancel Source Select Register (DSSSR)

DSSSR is a 16-bit readable/writable register that consists of the bits for selecting a source to cancel deep standby mode. The realtime clock alarm interrupt or change on the pins for canceling (P2_0, P2_2, P2_7, P2_9, P5_8, P5_9, P5_10, P6_7, P7_2, P7_3, P7_6, P7_9, NMI) can be selected as a cancel source. The pins for canceling can be used for canceling deep standby, regardless of pin function settings in the general I/O port.

Note: • When writing to this register, see section 42.4, Usage Notes.

||Bit:|15|14|13||12|11||10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|P2_0|P7_6||P7_9|P5_10||P2_2|P7_2<br>NMI<br>—<br>RTCAR<br>P5_9<br>P7_3<br>P5_8<br>P2_7<br>P6_7<br>P2_9||
||Initial value:|0|0|0||0|0||0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||R/W:|R|R/W|R/W||R/W|R/W||R/W|R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||||**Initial**||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**||
|15|—|||0|||R|||Reserved||
|||||||||||This bit is always read as 0. The write value should always be 0.||
|14|P2_0|||0|||R/W|||Cancel by Change on P2_0||
|||||||||||0: Deep standby mode is not canceled by change on the P2_0 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P2_0 pin.||
|13|P7_6|||0|||R/W|||Cancel by Change on P7_6||
|||||||||||0: Deep standby mode is not canceled by change on the P7_6 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P7_6 pin.||
|12|P7_9|||0|||R/W|||Cancel by Change on P7_9||
|||||||||||0: Deep standby mode is not canceled by change on the P7_9 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P7_9 pin.||
|11|P5_10|||0|||R/W|||Cancel by Change on P5_10||
|||||||||||0: Deep standby mode is not canceled by change on the P5_10 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P5_10 pin.||
|10|P2_2|||0|||R/W|||Cancel by Change on P2_2||
|||||||||||0: Deep standby mode is not canceled by change on the P2_2 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P2_2 pin.||
|9|P7_2|||0|||R/W|||Cancel by Change on P7_2||
|||||||||||0: Deep standby mode is not canceled by change on the P7_2 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P7_2 pin.||
|8|NMI|||0|||R/W|||Cancel by Change on NMI||
|||||||||||0: Deep standby mode is not canceled by change on the NMI pin.||
|||||||||||1: Deep standby mode is canceled by change on the NMI pin.||
|7|—|||0|||R|||Reserved||
|||||||||||This bit is always read as 0. The write value should always be 0.||
|6|RTCAR|||0|||R/W|||Cancel by Realtime Clock Alarm Interrupt||
|||||||||||0: Deep standby mode is not canceled by a realtime clock alarm interrupt.||
|||||||||||1: Deep standby mode is canceled by a realtime clock alarm interrupt.||
|5|P5_9|||0|||R/W|||Cancel by Change on P5_9||
|||||||||||0: Deep standby mode is not canceled by change on the P5_9 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P5_9 pin.||
|4|P7_3|||0|||R/W|||Cancel by Change on P7_3||
|||||||||||0: Deep standby mode is not canceled by change on the P7_3 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P7_3 pin.||
|3|P5_8|||0|||R/W|||Cancel by Change on P5_8||
|||||||||||0: Deep standby mode is not canceled by change on the P5_8 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P5_8 pin.||
|2|P2_7|||0|||R/W|||Cancel by Change on P2_7||
|||||||||||0: Deep standby mode is not canceled by change on the P2_7 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P2_7 pin.||
|1|P2_9|||0|||R/W|||Cancel by Change on P2_9||
|||||||||||0: Deep standby mode is not canceled by change on the P2_9 pin.||
|||||||||||1: Deep standby mode is canceled by change on the P2_9 pin.||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|0|P6_7|0|R/W|Cancel by Change on P6_7|
|||||0: Deep standby mode is not canceled by change on the P6_7 pin.|
|||||1: Deep standby mode is canceled by change on the P6_7 pin.|

## 42.2.26 Deep Standby Cancel Edge Select Register (DSESR)

DSESR is a 16-bit readable/writable register that consists of the bits for selecting an edge to be detected for the pin specified as a deep standby cancel source with DSSSR. This register setting is always valid for canceling deep standby, regardless of the interrupt controller setting.

Note: • When writing to this register, see section 42.4, Usage Notes.

||Bit:|15|14|13||12|11||10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|P2_0E|P7_6E||P7_9E|P5_10E||P2_2E|P7_2E<br>NMIE<br>—<br>—<br>P5_9E<br>P7_3E|P5_8E|P2_7E|P2_9E|P6_7E||
||Initial value:|0|0|0||0|0||0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:|R|R/W|R/W||R/W|R/W||R/W|R/W<br>R/W<br>R<br>R<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**||||||
|15|—|||0|||R|||Reserved||||||
|||||||||||This bit is always read as 0. The write value should always be 0.||||||
|14|P2_0E|||0|||R/W|||P2_0 Edge Detection||||||
|||||||||||0: Falling edge of P2_0 is detected.||||||
|||||||||||1: Rising edge of P2_0 is detected.||||||
|13|P7_6E|||0|||R/W|||P7_6 Edge Detection||||||
|||||||||||0: Falling edge of P7_6 is detected.||||||
|||||||||||1: Rising edge of P7_6 is detected.||||||
|12|P7_9E|||0|||R/W|||P7_9 Edge Detection||||||
|||||||||||0: Falling edge of P7_9 is detected.||||||
|||||||||||1: Rising edge of P7_9 is detected.||||||
|11|P5_10E|||0|||R/W|||P5_10 Edge Detection||||||
|||||||||||0: Falling edge of P5_10 is detected.||||||
|||||||||||1: Rising edge of P5_10 is detected.||||||
|10|P2_2E|||0|||R/W|||P2_2 Edge Detection||||||
|||||||||||0: Falling edge of P2_2 is detected.||||||
|||||||||||1: Rising edge of P2_2 is detected.||||||
|9|P7_2E|||0|||R/W|||P7_2 Edge Detection||||||
|||||||||||0: Falling edge of P7_2 is detected.||||||
|||||||||||1: Rising edge of P7_2 is detected.||||||
|8|NMIE|||0|||R/W|||NMI Edge Detection||||||
|||||||||||0: Falling edge of NMI is detected.||||||
|||||||||||1: Rising edge of NMI is detected.||||||
|7, 6|—|||All 0|||R|||Reserved||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||
|5|P5_9E|||0|||R/W|||P5_9 Edge Detection||||||
|||||||||||0: Falling edge of P5_9 is detected.||||||
|||||||||||1: Rising edge of P5_9 is detected.||||||
|4|P7_3E|||0|||R/W|||P7_3 Edge Detection||||||
|||||||||||0: Falling edge of P7_3 is detected.||||||
|||||||||||1: Rising edge of P7_3 is detected.||||||
|3|P5_8E|||0|||R/W|||P5_8 Edge Detection||||||
|||||||||||0: Falling edge of P5_8 is detected.||||||
|||||||||||1: Rising edge of P5_8 is detected.||||||
|2|P2_7E|||0|||R/W|||P2_7 Edge Detection||||||
|||||||||||0: Falling edge of P2_7 is detected.||||||
|||||||||||1: Rising edge of P2_7 is detected.||||||
|1|P2_9E|||0|||R/W|||P2_9 Edge Detection||||||
|||||||||||0: Falling edge of P2_9 is detected.||||||
|||||||||||1: Rising edge of P2_9 is detected.||||||
|0|P6_7E|||0|||R/W|||P6_7 Edge Detection||||||
|||||||||||0: Falling edge of P6_7 is detected.||||||
|||||||||||1: Rising edge of P6_7 is detected.||||||

## 42.2.27 Deep Standby Cancel Source Flag Register (DSFR)

DSFR is a 16-bit readable/writable register composed of two types of bits. One is the flag that confirms which source canceled deep standby mode. The other is the bit that releases the state of pins after canceling deep standby mode. When deep standby mode is canceled by an interrupt (NMI or realtime clock alarm interrupt) and changes on the pins for canceling, this register retains the previous data although power-on reset exception handling is executed. When deep standby mode is canceled by a power-on reset, this register is initialized to H'0000.

All flags must be cleared immediately before transition to deep standby mode.

Note: • When writing to this register, see section 42.4, Usage Notes.

|Bit:|15|14|13|12|11<br>10|9<br>8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||IO<br>KEEP|P2_0F|P7_6F|P7_9F|P5_10F<br>P2_2F|P7_2F<br>NMIF|-|RTC<br>ARF|P5_9F|P7_3F|P5_8F|P2_7F|P2_9F|P6_7F|
|Initial value:|0|0|0|0|0<br>0|0<br>0|0|0|0|0|0|0|0|0|
|R/W:|R/(W)*|R/(W)*|R/(W)*|R/(W)*|R/(W)* R/(W)*|R/(W)* R/(W)*|R|R/(W)*|R/(W)*|R/(W)*|R/(W)*|R/(W)*|R/(W)*|R/(W)*|
|Note:*Only 0 can be written after reading 1 to clear the fag.|||||||||||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15|IOKEEP|0|R/(W)*1|Release of Pin State Retention|
|||||Releases the retention of the pin state after canceling deep standby|
|||||mode|
|||||0: Pin state not retained|
|||||[Clearing condition]|
|||||Writing 0 after reading 1|
|||||1: Pin state retained|
|||||[Setting condition]|
|||||When deep standby mode is entered|
|14|P2_0F|0|R/(W)*1|P2_0 Flag|
|||||0: No change on the P2_0 pin|
|||||1: Change on the P2_0 pin|
|13|P7_6F|0|R/(W)*1|P7_6 Flag|
|||||0: No change on the P7_6 pin|
|||||1: Change on the P7_6 pin|
|12|P7_9F|0|R/(W)*1|P7_9 Flag|
|||||0: No change on the P7_9 pin|
|||||1: Change on the P7_9 pin|
|11|P5_10F|0|R/(W)*1|P5_10 Flag|
|||||0: No change on the P5_10 pin|
|||||1: Change on the P5_10 pin|
|10|P2_2F|0|R/(W)*1|P2_2 Flag|
|||||0: No change on the P2_2 pin|
|||||1: Change on the P2_2 pin|
|9|P7_2F|0|R/(W)*1|P7_2 Flag|
|||||0: No change on the P7_2 pin|
|||||1: Change on the P7_2 pin|
|8|NMIF|0|R/(W)*1|NMI Flag|
|||||0: No interrupt on NMI pin|
|||||1: Interrupt on NMI pin|
|7|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|6|RTCARF|0|R/(W)*1|RTCAR Flag|
|||||0: No realtime clock alarm interrupt generated|
|||||1: Realtime clock alarm Interrupt generated|
|5|P5_9F|0|R/(W)*1|P5_9 Flag|
|||||0: No change on the P5_9 pin|
|||||1: Change on the P5_9 pin|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|4|P7_3F|0|R/(W)*1|P7_3 Flag|
|||||0: No change on the P7_3 pin|
|||||1: Change on the P7_3 pin|
|3|P5_8F|0|R/(W)*1|P5_8 Flag|
|||||0: No change on the P5_8 pin|
|||||1: Change on the P5_8 pin|
|2|P2_7F|0|R/(W)*1|P2_7 Flag|
|||||0: No change on the P2_7 pin|
|||||1: Change on the P2_7 pin|
|1|P2_9F|0|R/(W)*1|P2_9 Flag|
|||||0: No change on the P2_9 pin|
|||||1: Change on the P2_9 pin|
|0|P6_7F|0|R/(W)*1|P6_7 Flag|
|||||0: No change on the P6_7 pin|
|||||1: Change on the P6_7 pin|

Note 1. Only 0 can be written after reading 1 to clear the flag.

## 42.2.28 XTAL Crystal Oscillator Gain Control Register (XTALCTR)

XTALCTR is an 8-bit readable/writable register that controls the gain of the crystal oscillator for XTAL. If the realtime clock uses the EXTAL input, the GAIN0 bit retains the previous value when software standby mode or deep standby mode is canceled by a source other than a power-on reset. If the realtime clock does not use the EXTAL input, this bit is initialized to 0 when software standby or deep standby mode is entered.

This register is initialized to H'00 when software standby or deep standby mode is canceled by a power-on reset.

## Note: • When writing to this register, see section 42.4, Usage Notes.

|||Bit:|7||6|5<br>4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|
||||—||—|—<br>—|—|—|—|GAIN0||
|||Initial value:|0||0|0<br>0|0|0|0|0||
|||R/W:|R||R|R<br>R|R|R|R|R/W||
|||**Initial**||||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||||
|7 to 1|—|All 0|R|||Reserved||||||
|||||||These bits|are always read as 0. The||||write value should always be 0.|
|0|GAIN0|0|R/W|||XTAL Crystal Oscillator (EXTAL or XTAL Pin) Gain Select||||||
|||||||0: Large gain||||||
|||||||1: Small gain||||||

## 42.3 Operation

## 42.3.1 Sleep Mode

## (1) Transition to Sleep Mode

When causing the device to make a transition from the program execution state to sleep mode, follow procedure (a) or

(b) depending on the condition described following the description of the procedures.

- (a) Execute the WFI instruction while the STBY bit in STBCR1 is 0.

- (b) While the STBY bit in STBCR1 is 0 and bits I and F in the current program status register (CPSR) corresponding to the interrupt source to trigger release from the sleep mode are 0 (mask disabled), execute the following three instructions in the given sequence: SEV, WFE, and WFE.

When the following condition is met, follow procedure (b) and do not use the WFI instruction other than to initiate a transition to software standby or deep standby.

- Software standby is also being used.

- When software standby is not being used, deep standby is being used, and the procedure (a) in 42.3.4 (1) Transition to Deep Standby Mode is followed to initiate the transition to deep standby.

Although the CPU halts immediately after a transition to the sleep mode, the contents of its internal registers remain unchanged. The on-chip peripheral modules continue to run. The clock output from the CKIO pin is continued.

## Note: • When writing to STBCR1 register, see section 42.4, Usage Notes.

## (2) Canceling Sleep Mode

Sleep mode is canceled by an interrupt (NMI, IRQ, and on-chip peripheral module) or a power-on reset.

- Canceling by an interrupt When an NMI, IRQ, or on-chip peripheral module interrupt occurs, sleep mode is canceled and interrupt exception handling is executed. When the priority level of the generated interrupt is lower than the setting of the interrupt controller execution priority register, or the interrupt by the on-chip peripheral module is disabled on the module side, the interrupt request is not accepted and sleep mode is not canceled. When procedure (a) in 42.3.1 (1) Transition to Sleep Mode is followed and an interrupt request occurs with an interrupt masked by bits 6 (the FIQ mask bit) and 7 (the IRQ mask bit) in the CPSR register in the CPU, sleep mode is canceled but interrupt exception handling is not executed.

- Canceling by a reset

Sleep mode is canceled by a power-on reset.

## 42.3.2 Software Standby Mode

## (1) Transition to Software Standby Mode

The LSI switches from a program execution state to software standby mode by executing the WFI instruction when the STBY bit and DEEP bit in STBCR1 are 1 and 0 respectively. In software standby mode, not only the CPU but also the clock and on-chip peripheral modules halt. The clock output from the CKIO pin also stops.

The contents of the CPU and cache registers remain unchanged. Some registers of on-chip peripheral modules are, however, initialized. As for the states of on-chip peripheral module registers in software standby mode, see section 46.3, Register States .

The CPU takes one cycle to finish writing to STBCR1, and then executes processing for the next instruction. However, it takes one or more cycles to actually write. Therefore, execute a WFI instruction after reading STBCR1 to have the values written to STBCR1 by the CPU to be definitely reflected in the WFI instruction.

After a WFI instruction is issued, the hardware automatically stops the bus master following the wait for completion of the issuing-finished request from the bus master and the transition to software standby proceeds. Since the transition to software standby is not possible if completion of the issuing-finished request is not possible at this time, do not proceed with access to the registers of modules in the module-standby state and so on. Furthermore, as the issuing of unintended requests by the bus master is inhibited, using software to stop all bus masters in preparation for the procedure for the transition to software standby is also effective.

The procedure for switching to software standby mode is as follows:

1. Set the standby_mode_en bit of the power control register in the PL310 to 1. For the details of this register, see CoreLink Level 2 Cache Controller L2C-310 Technical Reference Manual issued by Arm Ltd.

2. Clear the TME bit in the watchdog timer control/status register (WTCSR) of the watchdog timer to 0 to stop the watchdog timer.

3. Set the CKS[2:0] bits of the WTCSR register and the watchdog timer counter (WTCNT) to appropriate values so that the watchdog timer overflow period will be at least the oscillation settling time on return from standby.

4. After setting the STBY and DEEP bits in STBCR1 to 1 and 0 respectively, read STBCR1. Then, execute a WFI instruction.

## (2) Canceling Software Standby Mode

Software standby mode is canceled by interrupts (NMI or IRQ) or a reset (power-on reset). Clock signal starts to be output from the CKIO pin.

- Canceling by an interrupt When the falling edge or rising edge of the NMI pin (selected by the NMI edge select bit (NMIE) in the interrupt control register 0 (ICR0) of the interrupt controller) or the falling edge or rising edge of an IRQ pin (IRQ7 to IRQ0) (selected by the IRQn sense select bits (IRQn1S and IRQn0S) in interrupt control register 1 (ICR1) of the interrupt controller) is detected, clock oscillation is started. This clock pulse is supplied only to the oscillation settling counter (watchdog timer) used to count the oscillation settling time.

   - After the elapse of the time set in the clock select bits (CKS[2:0]) in the watchdog timer control/status register (WTCSR) of the watchdog timer before the transition to software standby mode, the watchdog timer overflow occurs. Since this overflow indicates that the clock has been stabilized, the clock pulse will be supplied to the entire chip after this overflow. Software standby mode is thus cleared and NMI interrupt exception handling (IRQ interrupt exception handling in case of IRQ) is started. If the priority level of the generated interrupt is lower than the setting of the interrupt controller execution priority register, the interrupt request is not accepted and sleep mode is entered. So, cancel software standby mode by an interrupt whose priority level is higher than the setting of the interrupt controller execution priority register.

When canceling software standby mode by the NMI interrupt or IRQ interrupt, set the CKS[2:0] bits so that the watchdog timer overflow period will be equal to or longer than the oscillation settling time.

The clock output phase of the CKIO pin may be unstable immediately after detecting an interrupt and until software standby mode is canceled.

- Canceling by a reset

When the RES pin is driven low, software standby mode is canceled and the LSI enters the power-on reset state. After that, if the RES pin is driven high, the power-on reset exception handling is started.

- Keep the RES pin low until the clock oscillation settles. The internal clock will continue to be output to the CKIO pin.

## (3) Note on Transition to Software Standby Mode

Release from software standby mode is triggered by interrupts (NMI or IRQ) or a power-on reset. If, however, a WFI instruction and an interrupt other than NMI and IRQ are generated at the same time, software standby mode may be canceled due to acceptance of the interrupt.

When initiating a transition to software standby mode, make settings so that interrupts other than NMI and IRQ are not generated before execution of the WFI instruction.

## (4) Note on Canceling Software Standby Mode

After software standby mode is canceled, unstable clock pulses are output from the CKIO pin during oscillation settling time. To prevent malfunction due to the unstable pulses, the CKOEN[1:0] bits in FRQCR should be modified.

## 42.3.3 Software Standby Mode Application Example

This example describes a transition to software standby mode on the falling edge of the NMI signal, and cancellation on the rising edge of the NMI signal. The timing is shown in Figure 42.2 .

When the NMI pin is changed from high to low level while the NMI edge select bit (NMIE) in the interrupt control register 0 (ICR0) is set to 0 (falling edge detection), the NMI interrupt is accepted. When the NMIE bit is set to 1 (rising edge detection) by the NMI exception service routine, the STBY and DEEP bits in STBCR1 are set to 1 and 0 respectively, and a WFI instruction is executed, software standby mode is entered. Thereafter, software standby mode is canceled when the NMI pin is changed from low to high level.

Note: • When writing to STBCR1 register, see section 42.4, Usage Notes.

**==> picture [353 x 204] intentionally omitted <==**

**----- Start of picture text -----**<br>
Oscillator<br>CK<br>NMI pin<br>NMIE bit<br>STBY bit<br>LSI state executionProgram exceptionhandlingNMI service routineException standby modeSoftware settling timeOscillation NMI exceptionhandling<br>**----- End of picture text -----**<br>

**Figure 42.2 NMI Timing in Software Standby Mode (Application Example)**

## 42.3.4 Deep Standby Mode

## (1) Transition to Deep Standby Mode

The LSI switches from a program execution state to deep standby mode by executing the WFI instruction when the STBY bit and DEEP bit in STBCR1 are set to 1. In deep standby mode, not only the CPU, clocks, and on-chip peripheral modules but also power supply is turned off excluding the on-chip data-retention RAM area specified by the RRAMKP3 to RRAMKP0 bits in RRAMKP and realtime clock. This can significantly reduce power consumption. Therefore, data in the registers of the CPU, cache, and on-chip peripheral modules are not retained. Pin state values immediately before the transition to deep standby mode are retained.

The CPU takes one cycle to finish writing to STBCR1, and then executes processing for the next instruction. However, it actually takes one or more cycles to write. Therefore, execute a WFI instruction after reading STBCR1 to reflect the values written to STBCR1 by the CPU in the WFI instruction without fail.

After a WFI instruction is issued, the hardware automatically stops the bus master following the wait for completion of the issuing-finished request from the bus master and the transition to deep standby proceeds. Since the transition to deep standby is not possible if completion of the issuing-finished request is not possible at this time, do not proceed with access to the registers of modules in the module-standby state and so on. Furthermore, as the issuing of unintended requests by the bus master is inhibited, using software to stop all bus masters in preparation for the procedure for the transition to deep standby is also effective.

- The procedure for switching to deep standby mode is as follows. Figure 42.3 also shows its flowchart.

1. Set the standby_mode_en bit of the power control register in the PL310 to 1. For the details of this register, see CoreLink Level 2 Cache Controller L2C-310 Technical Reference Manual issued by Arm Ltd.

2. Set the RRAMKP3 to RRAMKP0 bits in RRAMKP for the corresponding on-chip data-retention RAM area that must be retained. Transfer the programs to be retained to the specified areas of the on-chip data-retention RAM.

3. Set the RAMBOOT and EBUSKEEPE bits in DSCTR to specify the activation method for returning from deep standby mode and to select whether the external memory control pin status is retained or not.

4. When canceling deep standby mode by an interrupt, set the corresponding bit in DSSSR to select the pin or source to cancel deep standby mode. In this case, specify the input signal detection mode for the selected pin with the corresponding bit in DSESR.

5. Execute read and write of an arbitrary but the same address for each page in the on-chip data-retention RAM area. When this is not executed, data last written may not be written to the on-chip data-retention RAM. If there is a write to the on-chip data-retention RAM after this time, execute this processing after the last write to the on-chip dataretention RAM.

The procedures for steps 6 to 8 are as listed under (a) or (b), and which procedure is correct depends on the condition described after the procedures.

## (a)

6. Set the STBY and DEEP bits in the STBCR1 register to 1, and then read this register.

7. Clear the flag in the DSFR register.

8. Set the CPU interface control register (ICCICR) of the interrupt controller to 0 so that the CPU is not notified of interrupts other than NMIs. Then, read the ICCICR register.

## (b)

6. Clear the flag in the DSFR register.

7. Set the CPU interface control register (ICCICR) of the interrupt controller to 0 so that the CPU is not notified of interrupts other than NMIs. Then, read the ICCICR register.

8. Set the STBY and DEEP bits in the STBCR1 register to 1, and then read this register.

When the condition below is met, follow procedure (b).

- Software standby is not being used, the sleep mode is being used, and procedure (a) in section 42.3.1 , (1) Transition to Sleep Mode is followed to initiate the transition to sleep mode.

9. Execute the WFI instruction.

10. The conflict between the instruction and the NMI interrupt may prevent transition to deep standby mode. After executing the WFI instruction, locate the branch instruction to return to step 9.

**==> picture [256 x 441] intentionally omitted <==**

**----- Start of picture text -----**<br>
Set the RRAMKP bit in RRAMKP<br>as needed<br>Transfer data that needs to be<br>retained to the corresponding<br>area<br>Set the corresponding bit in<br>DSCTR as needed<br>Set the corresponding bit in<br>DSSSR as needed<br>Set the corresponding bit in<br>DSESR as needed<br>Set the realtime clock registers<br>as needed<br>Perform read/write to the same<br>arbitrary address in each<br>retention page of the on-chip<br>data-retention RAM<br>Yes<br>Select procedure (b) in<br>42.3.4 (1) Transition to Deep<br>Standby Mode<br>No<br>Set the STBY and DEEP bits  Clear the flags of DSFR<br> in STBCR1 to 1<br>Read STBCR1 Clear ICCICR and read ICCICR<br>Clear the flags of DSFR<br>Set the STBY and DEEP bits<br> in STBCR1 to 1<br>Clear ICCICR and read ICCICR<br>Read STBCR1<br>Execute the WFI instruction<br>If conflict with NMI does not occur,<br>transition to deep standby mode<br>is performed.<br>**----- End of picture text -----**<br>

**Figure 42.3 Flowchart of Transition to Deep Standby Mode**

## (2) Canceling Deep Standby Mode

Deep standby mode is canceled by interrupts (NMI or realtime clock alarm interrupt), change on the pins for canceling, or a reset (power-on reset). The realtime clock alarm interrupt can always cancel deep standby mode regardless of the settings of the execution priority register for the interrupt controller and of the alarm interrupt enable flag (RCR1.AIE) . This interrupt can also always cancel this mode do regardless of the states of bit 6 (the FIQ mask bit) and bit 7 (the IRQ mask bit) in the CPSR register of the CPU. When canceling the mode by a source other than a reset, a power-on reset exception handling is executed instead of an interrupt exception handling. Figure 42.4 shows the flowchart of canceling deep standby mode.

**==> picture [386 x 352] intentionally omitted <==**

**----- Start of picture text -----**<br>
Deep standby mode<br>Detect an interrupt (NMI or realtime clock alarm). Detect RES<br>Detect change on the pins for canceling.<br>Count oscillation settling  The RES pin is held low<br>time during oscillation settling<br>time<br>Power-on reset<br>No exception handling*<br>RAMBOOT=1? according to the boot mode<br>specified for the reset<br>Yes<br>Power-on reset Power-on reset<br>exception handling* exception handling*  To the initialization routine<br>Instruction fetch  according to the boot mode<br>from H'20000000 specified for the reset<br>Check the flags in DSFR<br>Processing according to<br>deep standby mode cancel source<br>Reconfiguration of<br>peripheral functions*<br>Clear the IOKEEP bit in DSFR<br>(Release the pin state retention)<br>To the state before the transition<br>to deep standby mode<br>Note:   *  Since the peripheral functions return to their initial states by reset processing, they require re-setting.<br>               The peripheral functions include all functions such as the clock pulse generator, interrupt controller,<br>               bus state controller, general I/O ports, and peripheral modules.<br>**----- End of picture text -----**<br>

**Figure 42.4 Flowchart of Canceling Deep Standby Mode**

- Canceling by a source other than a reset

   - When the falling or rising edge of the NMI pin (selected by a corresponding bit in DSESR) or falling or rising edge of the pins for canceling (selected by a corresponding bit in DSESR) is detected or the realtime clock alarm interrupt (see section 13.4.4, Alarm Function ) is generated, clock oscillation is started after the wait time for the oscillation settling time. After the oscillation settling time has elapsed, deep standby mode is cancelled and the power-on reset exception handling is executed.

The clock output phase of the CKIO pin may be unstable immediately after detecting a cancel source and until deep standby mode is canceled.

The detecting of the NMI pin, the pins for canceling, and the realtime clock alarm interrupt becomes enable when the corresponding bits in DSSSR are set. The detected cancel sources are kept, but they are reflected to DSFR after canceling the deep standby mode. When the CPU accepts any interrupts and reads the interrupt response register (ICCIAR), all of the cancel sources that are kept are cleared. When the CPU enters the deep standby mode as the detected cancel sources are kept, the deep standby mode is canceled immediately after the CPU enters the deep standby mode.

- Canceling with a reset

Driving the RES pin low cancels deep standby mode and causes a transition to the power-on reset state. After this, driving the RES pin high initiates power-on reset exception handling. Output of the internal clock from the CKIO pin also starts by driving the RES pin low.

Keep the RES pin low until the clock oscillation has settled.

## (3) Operation after Canceling Deep Standby Mode

After canceling deep standby mode, the LSI can be activated through the external memory or from the on-chip dataretention RAM, which can be selected by setting the RAMBOOT bit in DSCTR. By setting the EBUSKEEPE bit, the states of the external memory control pins can be retained even after cancellation of deep standby mode. Table 42.3 shows the pin states after cancellation of deep standby mode according to the setting of each bit. Table 42.4 lists the external memory control pins.

**Table 42.3 Pin States after Cancellation of Deep Standby Mode and System Activation Method by the DSCTR Settings**

|||**Activation**||
|---|---|---|---|
|**EBUSKEEPE Bit**|**RAMBOOT Bit**|**Method**|**Pin States After Cancellation of Deep Standby Mode**|
|0|0|External memory|The states of the external memory control pins are not retained.|
||||For other pins, the retention of their states is cancelled when the IOKEEP|
||||bit is cleared.|
|0|1|On-chip data-|The states of the external memory control pins are not retained.|
|||retention RAM|After cancellation of deep standby mode, the retention of the external|
||||memory control pin states is cancelled.|
||||For other pins, the retention of their states is cancelled when the IOKEEP|
||||bit is cleared.|
|1|0|—|Setting prohibited.|
|1|1|On-chip data-|The states of the external memory control pin are retained.|
|||retention RAM|The retention of the states of the external memory control pins and other|
||||pins is cancelled when the IOKEEP bit is cleared.|

## **Table 42.4 External Memory Control Pins in Different Modes**

|**Boot Mode 0**|**Boot Mode 0**||||
|---|---|---|---|---|
|**(CS0 Area: Bus Width: 16**||**Boot Mode 1**|**Boot Mode 2**|**Boot Mode 3**|
|**Bits)**||**(Serial Flash Boot)**|**(eSD Boot)**|**(eMMC Boot)**|
|A[20:1]||SPBCLK_0, SPBSSL_0,|SD_CLK_0, SD_CMD_0,|MMC_CLK, MMC_CMD,|
|D[15:0]||SPBMO0_0, SPBMI0_0|SD_D[3:0]_0|MMC_D[3:0]|
|CS0<br>, RD<br>, CKIO|||||

When deep standby mode is canceled by interrupts (NMI or realtime clock alarm) or changes on the pins for canceling, the deep standby cancel source flag register (DSFR) can be used to confirm which source has canceled the mode. Pins retain the state immediately before the transition to deep standby mode. However, in system activation through the external memory, the retention of the states of the external memory control pins is cancelled so that programs can be fetched after cancellation of deep standby mode. Other pins, after cancellation of deep standby mode, continue to retain the pin states until writing 0 to the IOKEEP bit in DSFR after reading 1 from the same bit. In system activation from the on-chip data-retention RAM, after cancellation of deep standby mode, both the external memory control pins and other pins continues to retain the pin states until writing 0 to the IOKEEP bit in DSFR after reading 1 from the same bit. Reconfiguration of peripheral functions is required to return to the previous state of deep standby mode. Peripheral functions include all functions such as the clock pulse generator, interrupt controller, general I/O ports, and peripheral modules. After the reconfiguration, the retention of the pin state can be canceled and the LSI returns to the state prior to the transition to deep standby mode by reading 1 from the IOKEEP bit in DSFR and then writing 0 to it.

## (4) Notes on Transition to Deep Standby Mode

If multiple canceling sources have been specified and multiple canceling sources are input, multiple cancel source flags will be set.

## 42.3.5 Module Standby Function

## (1) Transition to Module Standby Function

Setting an MSTP bit in a standby control register to 1 halts supply of the clock signal to the corresponding on-chip peripheral module. This function can be used to reduce power consumption both while a program is running and in sleep mode. Disable a module before placing it in the module standby state. If interrupt requests are enabled, set the respective register in the target module or in the interrupt controller to disable interrupt requests. If DMA transfer requests are enabled, set the respective register in the target module to disable DMA transfer requests from the module and then set the respective register in the direct memory access controller to stop DMA transfers. In addition, do not attempt to access a module's registers while it is in the module standby state. The procedure for transitions to the module standby state depends on whether the STBREQ register has a bit for the corresponding module.

- (a) Procedure for transition to module standby of modules for which the STBREQ register does not have a corresponding  bit

1. Set the MSTP bit of the corresponding module to 1.

- (b) Procedure for transition to module standby of modules for which the STBREQ register has a corresponding bit

1. Set the corresponding bit in the STBREQ register to 1 to generate a request to stop the module.

2. Confirm that the module is ready to be stopped by the corresponding bit in the STBACK register being set to 1.

3. Set the MSTP bit of the corresponding module to 1.

For states of registers in the module standby function, see section 46.3, Register States .

## (2) Canceling Module Standby Function

Release from the module standby state can be achieved in two ways: starting the module by a power-on reset while the MSTP bit is set to 1, then clearing the MSTP bit to 0, or setting the MSTP bit to 0 to activate the module, setting the MSTP bit to 1 to place the module in the standby state, and then setting the MSTP bit to 0 again. If you use the latter approach, the procedure for release from module standby depends on whether the STBREQ register has a bit for the corresponding module.

- Release from the module standby state after the activation of the module by a power-on reset while the MSTP bit is set  to 1

1. Clear the MSTP bit to 0.

2. After that, dummy-read the same register.

- Release from the module standby state after a transition to standby following activation of the module

- (a) Procedure for release from module standby of modules for which the STBREQ register does not have a corresponding  bit

1. Clear the MSTP bit to 0, then dummy-read the same register.

- (b) Procedure for release from module standby of modules for which the STBREQ register has a corresponding bit

1. Clear the MSTP bit to 0, then dummy-read the same register.

2. Clear the corresponding bit in the STBREQ register to 0 to cancel the request to stop the module.

3. Confirm that the corresponding bit in the STBACK register has been cleared to 0, indicating the completion of release from standby.

## 42.3.6 Software Reset

Initialization equivalent to a power-on reset is only applied to the selected modules. The procedure for transitions to the software reset state varies according to whether the STBREQ register has a bit for the corresponding module. Follow the procedures below according to whether this is or is not the case. If DMA transfer requests are enabled, make the settings to stop the DMA transaction for the corresponding channel before transitions to the software reset state. For stopping the DMA transaction, see section 9.7.11, Transfer Status .

## (1) Transition to Software Reset State

- (a) Procedure for transition to the software reset state of modules for which the STBREQ register does not have a corresponding bit

1. Set the SRST bit of the corresponding module to 1, then dummy-read the same register.

- (b) Procedure for transition to the software reset state of modules for which the STBREQ register has a corresponding bit

1. Set the corresponding bit in the STBREQ register to 1 to generate a request to stop the module.

2. Confirm that the corresponding bit in the STBACK register has been set to 1.

3. Set the SRST bit of the corresponding module to 1, then dummy-read the same register.

## (2) Canceling Software Reset

- (a) Procedure for release from the software reset state of modules for which the STBREQ register does not have a corresponding bit

1. Clear the SRST bit of the corresponding module to 0, then dummy-read the same register.

- (b) Procedure for release from the software reset state of modules for which the STBREQ register has a corresponding bit

1. Clear the SRST bit of the corresponding module to 0, then dummy-read the same register.

2. Clear the corresponding bit in the STBREQ register to 0 to cancel the request to stop the module.

3. Confirm that the corresponding bit in the STBACK register has been cleared to 0.

## 42.3.7 Adjustment of XTAL Crystal Oscillator Gain

The gain of the crystal oscillator for XTAL can be adjusted using the GAIN0 bit in XTALCTR. To modify the gain of the signal on the EXTAL or XTAL pin, PLL settling time is needed. The settling time is counted using the on-chip watchdog timer.

After a change to the value of the GAIN0 bit, the hardware automatically stops the bus master following the wait for completion of the issuing-finished request from the bus master and the change to the gain for the crystal oscillator in use with XTAL proceeds. Since the change to the gain for the crystal oscillator in use with XTAL cannot start if completion of the issuing-finished request is not possible at this time, do not proceed with access to the registers of modules in the module-standby state and so on. Furthermore, as the issuing of unintended requests by the bus master is inhibited, using software to stop all bus masters in preparation for the procedure to change the gain for the crystal oscillator in use with XTAL is also effective.

1. The large gain is selected in the initial state.

2. Set the standby_mode_en bit of the power control register in the PL310 to 1. For the details of this register, see CoreLink Level 2 Cache Controller L2C-310 Technical Reference Manual issued by Arm Ltd.

3. Set the watchdog timer so that the specified settling time should be obtained and stop the watchdog timer. Specifically, the following settings are necessary:

   - TME in WTCSR = 0: Stop the watchdog timer.

   - CKS[2:0] in WTCSR: Division ratio for watchdog timer count clock

   - WTCNT: Initial counter value

(The watchdog timer starts counting on the set clock.)

4. Set the GAIN0 bit to the desired value.

5. The LSI is internally stopped and the watchdog timer starts counting. The clock is supplied only to the watchdog timer and other internal clocks are stopped. In this state, the CKIO pin continues to output an unstable clock. To avoid malfunction due to the unstable clock, modify the CKOEN2 bit in FRQCR appropriately. Since this state is equivalent to the software standby mode state, some registers of on-chip peripheral modules are initialized. For details, see section 46.3, Register States .

6. When an overflow occurs on the watchdog timer, the specified clock supply is started and the LSI starts operation. The watchdog timer stops after an overflow.

## 42.4 Usage Notes

## 42.4.1 Usage Notes on Setting Registers

When writing to the registers related to power-down modes, note the following.

When writing to the register related to power-down modes, the CPU, after executing a write instruction, executes the next instruction without waiting for the write operation to complete.

Therefore, to reflect the change specified by writing to the register while the next instruction is executed, insert a dummy read of the same register between the register write instruction and the next instruction.

## 42.4.2 Usage Notes when the Realtime Clock is not Used

When the realtime clock is not used, set the MSTP60 bit in STBCR6 to 1 after setting the bits in registers of the realtime clock. For details, see section 42.2.6, Standby Control Register 6 (STBCR6) .

- Set the RTCEN bit in the control register 2 (RCR2) to 0

- Set the RCKSEL[1:0] bits in the control register 5 (RCR5) to 00.

## 42.4.3 Usage Notes Applying when the USB_X1 Pin is not to be Used

When a 48 MHz clock is not being supplied to the USB_X1 pin, set registers according to the below procedure in the initial settings after release from the power-on reset state or deep standby mode.

## (1) When the USB2.0 host/function module is not to be used

1. Set the MSTP71 bit in the STBCR7 register to 0 and dummy-read STBCR7.

2. Set the UCKSEL bit in the SYSCFG0_0 register to 1.

3. Wait for at least 20 cycles of the EXTAL clock.

4. Set the MSTP71 bit in the STBCR7 register to 1 and dummy-read STBCR7.

## (2) When the USB2.0 host/function module is to be used

1. Set the MSTP71 bit* in the STBCR7 register to 0 and dummy-read STBCR7.

2. Set the UCKSEL bit in the SYSCFG0_0 register to 1.

3. Follow the procedure of example 1 in section 28.4.1 (5) Setting the Clock Supply for the USB Module .

4. Make the initial settings of the USB2.0 host/function module.

Note: * When channel 1 of the USB2.0 host/function module is to be used, also set the MSTP70 bit to 0.

## 42.4.4 Notes on Using IRQ Pins as Triggers for Release from Standby when Software Standby is in Use

To use an IRQ pin as the trigger for release from standby when software standby is in use, see section 7.8.4, Notes on Using IRQ Pins as Triggers for Release from Standby when Software Standby is in Use .
