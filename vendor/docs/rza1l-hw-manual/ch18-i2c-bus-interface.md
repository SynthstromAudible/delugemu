# 18. I²C Bus Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 789–879. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This section gives an overall description of the I[2] C bus interface (RIIC).

The first section describes the features specific to this LSI, including the number of channels and the register base addresses. The subsequent sections describe the RIIC’s functions and registers.

## 18.1 Features

## 18.1.1 Channels

This LSI has the following number of channels of the I[2] C bus interface (RIIC).

|**Table 18.1**|**Table 18.1**|**Channels of RIIC**|||
|---|---|---|---|---|
||**Package**|**176 Pins**|**208 Pins**|**233 Pins**|
||Number of channels||4||
||Name||RIICn (n = 0 to 3)||
|**Table 18.2**||**Index**|||
||**Index**|**Description**|||
||n|Throughout this section, each channel of the I2C bus interface is identified by the index “n” (n = 0 to|||
|||3). For example, RIICnCR1 is I2C bus control register 1.|||

## 18.1.2 Register Base Addresses

The base address <RIICn_base> of each RIICn is listed in the following table.

All RIICn register addresses are given as values obtained by adding offsets to the register base address <RIICn_base> for each channel.

## **Table 18.3 Register Base Address**

|**Channel**|**Base Address Name**|**Base Address**|
|---|---|---|
|RIIC0|<RIIC0_base>|FCFE E000H|
|RIIC1|<RIIC1_base>|FCFE E400H|
|RIIC2|<RIIC2_base>|FCFE E800H|
|RIIC3|<RIIC3_base>|FCFE EC00H|

## 18.1.3 External I/O Signals

The following table shows the external I/O signals of the RIICn.

## **Table 18.4 RIICn Pin Configuration**

|**Channel**|**Multiplexed Pin Name**<br>**Function**|
|---|---|
|**RIIC0**|RIIC0SCL<br>RIIC0 serial clock I/O pin|
||RIIC0SDA<br>RIIC0 serial data I/O pin|
|**RIIC1**|RIIC1SCL<br>RIIC1 serial clock I/O pin|
||RIIC1SDA<br>RIIC1 serial data I/O pin|
|**RIIC2**|RIIC2SCL<br>RIIC2 serial clock I/O pin|
||RIIC2SDA<br>RIIC2 serial data I/O pin|
|**RIIC3**|RIIC3SCL<br>RIIC3 serial clock I/O pin|
||RIIC3SDA<br>RIIC3 serial data I/O pin|

## 18.2 Overview

## 18.2.1 Functional Overview

## Communications format

- I[2] C bus format or SMBus format

- Master mode or slave mode selectable

- Automatic securing of the various set-up times, hold times, and bus-free times for the transfer rate

## Transfer rate

Up to 400 kbps

## SCL clock

For master operation, the duty cycle of the SCL clock is selectable in the following range. 0% < Duty cycle < 100%

## Issuing and detecting conditions

- Start, restart, and stop conditions are automatically generated.

- Start conditions (including restart conditions) and stop conditions are detected.

## Slave address

- Up to three slave-address settings can be made.

- Seven- and ten-bit address formats are supported (along with the use of both at once).

- General call addresses, device ID addresses, and SMBus host addresses are detectable.

## Acknowledgement

- For transmission, the acknowledge bit is automatically loaded

   - Transfer of the next data for transmission can be automatically suspended on detection of a not-acknowledge bit.

- For reception, the acknowledge bit is automatically transmitted

   - If a wait between the eighth and ninth clock cycles has been selected, software control of the value in the acknowledge field in response to the received value is possible.

## Wait function

- In reception, the following periods of waiting can be obtained by holding the clock signal (SCL) at the low level:

   - Waiting between the eighth and ninth clock cycles

   - Waiting between the ninth clock cycle and the first clock cycle of the next transfer (WAIT function)

## SDA output delay function

Timing of the output of transmitted data, including the acknowledge bit, can be delayed.

## Arbitration

- For multi-master operation

   - Operation to synchronize the SCL (clock) signal in cases of conflict with the SCL signal from another master is possible.

   - When issuing the start condition would create conflict on the bus, loss of arbitration is detected by testing for non-matching between the internal signal for the SDA line and the level on the SDA line.

   - In master operation, loss of arbitration is detected by testing for non-matching between the signal on the SDA line and the internal signal for the SDA line.

- Loss of arbitration due to detection of the start condition while the bus is busy is detectable (to prevent the issuing of double start conditions).

- Loss of arbitration in transfer of a not-acknowledge bit due to the internal signal for the SDA line and the level on the SDA line not matching is detectable.

- Loss of arbitration due to non-matching of internal and line levels for data is detectable in slave transmission.

## Timeout function

The internal time-out function is capable of detecting long-interval stop of the SCL (clock signal).

## Noise removal

The interface incorporates analog noise filters and digital noise filters for input on the RIICnSCL and RIICnSDA pins, and the width for noise cancellation by the digital noise filters is adjustable by software.

## Interrupt sources

- Eight sources:

   - Transmission complete

   - Receive data full

   - Transmit data empty

   - Detection of a stop condition

   - Detection of a start condition

   - Reception of a NACK

   - Arbitration lost

   - Timeout

## Low power consumption function

Module-stop state can be set.

## 18.2.2 Block Diagram

**==> picture [466 x 373] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0<br>PS CKS[2:0] RIICnMR1<br>FMPE BC[2:0]<br>RIICnSCL Output control Transfer clock  RIICnBRH<br>generator RIICnBRL<br>Noise  CLO SCLE SCLI<br>canceller<br>SCL0, SDA0 RIICnCR1<br>NF[1:0] NFE Transmission/ IICRST SDAI<br>reception control  ST, RS, SP<br>circuit RIICnCR2<br>PS DLCS BBSY, MST, TRS<br>WAIT, RDRFS<br>RIICnFER<br>IIC, IIC/2<br>SDA output delay control SDDL[2:0] RIICnMR2<br>RIICnMR3<br>ACKBT ACKBR<br>ACK output circuit RIICnDRT<br>RIICnSAR0<br>FMPE NACKE RIICnSAR1<br>RIICnSDA Output control RIICnDRS RIICnSAR2<br>NACK decision/<br>ACK reception circuit<br>Noise  Address comparator<br>canceller<br>NF[1:0] NFE Arbitration decision  RIICnDRR<br>circuit<br>RIICnSR1<br>MALE, NALE, SALE<br>RIICnSER<br>Bus state decision  NACKF<br>circuit TMOE TMOS, TMOH, TMOL RIICnSR2<br>Timeout circuit TMOF RIICnIER<br>Interrupt generator<br>Interrupt request<br>(INTRIICTEI, INTRIICRI, INTRIICTI, INTRIICSPI, INTRIICSTI, INTRIICNAKI, INTRIICALI, INTRIICTMOI)<br>Internal data bus<br>**----- End of picture text -----**<br>

**Figure 18.1 Block Diagram of RIIC**

**==> picture [399 x 259] intentionally omitted <==**

**----- Start of picture text -----**<br>
Power supply for pull-up (PVcc)<br>SCL SCL<br>SCLin<br>SCLout#<br>SDA SDA<br>SDAin<br>SDAout#<br>(Master) SCLin SCLin<br>SCLout# SCLout#<br>SDAin SDAin<br>SDAout# SDAout#<br>(Slave 1) (Slave 2)<br>SCL SDA SCL SDA<br>**----- End of picture text -----**<br>

**Figure 18.2 Connections to the External Circuit by the I/O Pins (I[2] C Bus Configuration Example)**

RIICnSCL and RIICnSDA are Schmitt input/open-drain output pins for both master and slave operations. Because the output is open drain, an external pull-up resistor is required.

## 18.3 Registers

## 18.3.1 RIICnCR1 — I²C Bus Control Register 1

||**Access:**|**Access:**|RIICnCR1 is a 32-bit readable/writable register.|RIICnCR1 is a 32-bit readable/writable register.|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnCR1L and RIICnCR1H are 16-bit readable/writable registers.||||||||||||
||||RIICnCR1LL, RIICnCR1LH, RIICnCR1HL, and RIICnCR1HH are 8-bit readable/writable registers.||||||||||||
||**Address:**||RIICnCR1: <RIICn_base> + 0000H||||||||||||
||||RIICnCR1L: <RIICn_base> + 0000H, RIICnCR1H:||<RIICn_base> +||0002H||||||||
||||RIICnCR1LL: <RIICn_base> + 0000H, RIICnCR1LH: <RIICn_base>|||||+ 0001H,|RIICnCR1HL: <RIICn_base> + 0002H,||||||
||||RIICnCR1HH: <RIICn_base> + 0003H||||||||||||
|**Initial Value:**|||0000 001FH. This register is initialized by any reset.||||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26|25|24|23||22|21|20|19|18|17|16|
||—||—<br>—<br>—<br>—<br>—|—|—|—||—|—|—|—|—|—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0||0|0|0|0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R||R|R|R|R|R|R|R|
|Bit|15||14<br>13<br>12<br>11<br>10|9|8|7||6|5|4|3|2|1|0|
||—||—<br>—<br>—<br>—<br>—|—|—|ICE||IICRST|CLO|SOWP|SCLO|SDAO|SCLI|SDAI|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0||0|0|1|1|1|1|1|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R/W||R/W|R/W|R/W|R/W|R/W|R|R|

## **Table 18.5 RIICnCR1 register contents  (1/2)**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 8|—|Reserved|
||||These bits are read as 0. The write value should be 0.|
|7||ICE|I2C Bus Interface Enable|
||||0: Output from the RIICnSCL and RIICnSDA pins is disabled (and input to the|
||||RIICnSCL and RIICnSDA pins is enabled).|
||||1: Enabled (RIICnSCL and RIICnSDA pins driven)|
||||(This bit can select the RIIC reset or internal reset in combination with the|
||||IICRST bit.)|
|6||IICRST|I2C Bus Interface Internal Reset|
||||0: Clears the RIIC reset or internal reset.|
||||1: Initiates the RIIC reset or internal reset.|
||||(Clears the bit counter and the SCL/SDA output latch)|
|5||CLO|Extra SCL Clock Cycle Output|
||||0: Does not output an extra SCL clock cycle (default).|
||||1: Outputs an extra SCL clock cycle.|
||||(The CLO bit is cleared automatically after one clock cycle is output.)|
|4||SOWP*2|SCLO/SDAO Write Protect|
||||0: Allows the SCLO and SDAO bits to be rewritten.|
||||(This bit is read as 1.)|
|3||SCLO*1,*2|SCL Output Control|
||||Read:|
||||0: RIICnSCL pin output is at a low level.|
||||1: RIICnSCL pin is in a high-impedance state.|
||||Write:|
||||0: Changes the RIICnSCL pin output to a low level.|
||||1: Changes the RIICnSCL pin in a high-impedance state.|
||||(High level output is achieved through an external pull-up resistor.)|

**Table 18.5 RIICnCR1 register contents  (2/2)**

|**Bit**|**Position**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|---|
|2|||SDAO*1,*2|SDA Output Control|
|||||Read:|
|||||0: RIICnSDA pin output is at a low level.|
|||||1: RIICnSDA pin is in a high-impedance state.|
|||||Write:|
|||||0: Changes the RIICnSDA pin output to a low level.|
|||||1: Changes the RIICnSDA pin in a high-impedance state.|
|||||(High level output is achieved through an external pull-up resistor.)|
|1|||SCLI|SCL Bus Input Monitor|
|||||0: RIICnSCL pin input is at a low level.|
|||||1: RIICnSCL pin input is at a high level.|
|0|||SDAI|SDA Bus Input Monitor|
|||||0: RIICnSDA pin input is at a low level.|
|||||1: RIICnSDA pin input is at a high level.|
|Note|1.|Do|not write to these bits during communication. Changing a value during communication may cause a||
|||transmission or reception failure or an AL error.|||
|Note|2.|To change the SDAO and SCLO bits, set the SOWP bit to 0 at the same timing to set the SDAO and SCLO|||
|||bits to 0.|||

## CLO Bit (Extra SCL Clock Cycle Output)

This bit is used to output an extra SCL clock cycle for debugging or error processing.

Normally, set the bit to 0. Setting the bit to 1 in a normal communication state causes a communication error.

For details on this function, see Section 18.13.2, Extra SCL Clock Cycle Output Function .

IICRST Bit (I[2] C Bus Interface Internal Reset)

This bit is used to reset the internal states of the RIIC.

Setting this bit to 1 initiates an RIIC reset or internal reset.

Whether an RIIC reset or internal reset is initiated is determined according to the combination with the ICE bit. Table 18.6 lists the resets of the RIIC.

The RIIC reset resets all registers including the RIICnCR2.BBSY flag (except ICE and IICRST) and internal states of the RIIC, and the internal reset resets the bit counter (RIICnMR1.BC[2:0] bits), the I[2] C bus shift register (RIICnDRS), and the I[2] C bus status registers (RIICnSR1 and RIICnSR2) as well as the internal states of the RIIC. For the reset conditions for each register, see Section 18.15, Reset Function of RIIC .

An internal reset initiated with the IICRST bit set to 1 during operation (with the ICE bit set to 1) resets the internal states of the RIIC without initializing the port settings and the control and setting registers of the RIIC when the bus or RIIC hangs up due to a communication error.

If the RIIC hangs up in a low level output state, resetting the internal states cancels the low level output state and releases the bus with the RIICnSCL pin and RIICnSDA pin at a high impedance.

## **CAUTION**

If an internal reset is initiated using the IICRST bit for a bus hang-up occurred during communication with the master device in slave mode, the states may become different between the slave device and the master device (due to the difference in the bit counter information). For this reason, do not initiate an internal reset in slave mode, but initiate restoration processing from the master device. If an internal reset is necessary because the RIIC hangs up with the SCL line in a low level output state in slave mode, initiate an internal reset and then issue a restart condition from the master device or resume communication from the start condition issuance after issuing a stop condition. If communication is restarted by initiating a reset solely in the slave device without issuing a start condition or restart condition from the master device, synchronization will be lost because the master and slave devices operate asynchronously.

## **Table 18.6 RIIC Resets**

|**IICRST**|**ICE**<br>**State**<br>**Specifications**|
|---|---|
|1|0<br>RIIC reset<br>Resets all registers (except ICE and IICRST) and internal<br>states of the RIIC.|
||1<br>Internal reset<br>Reset the RIICnMR1.BC[2:0] bits, and the RIICnSR1,<br>RIICnSR2, RIICnDRS registers and the internal states of the<br>RIIC.|

ICE Bit (I[2] C Bus Interface Enable)

The ICE bit selects driving or non-driving of the RIICnSCL and RIICnSDA pins. Moreover, this bit can perform two types of reset in combination with the IICRST bit. For the types of reset, see Table 18.6, RIIC Resets .

Set the ICE bit to 1 when using RIIC. Setting the ICE bit to 1 selects driving of the RIICnSCL and RIICnSDA pins.

Set the ICE bit to 0 when RIIC is not to be used. Clearing the ICE bit to 0 disables output from the RIICnSCL and RIICnSDA pins.

## 18.3.2 RIICnCR2 — I²C Bus Control Register 2

||**Access:**|**Access:**|RIICnCR2 is a 32-bit readable/writable register.|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnCR2L and RIICnCR2H are 16-bit readable/writable registers.|||||||||||
||||RIICnCR2LL, RIICnCR2LH, RIICnCR2HL, and RIICnCR2HH are 8-bit readable/writable registers.|||||||||||
||**Address:**||RIICnCR2: <RIICn_base> + 0004H|||||||||||
||||RIICnCR2L: <RIICn_base> + 0004H, RIICnCR2H:|<RIICn_base> + 0006H||||||||||
||||RIICnCR2LL: <RIICn_base> + 0004H, RIICnCR2LH: <RIICn_base>|||+ 0005H,|RIICnCR2HL: <RIICn_base> + 0006H,|||||||
||||RIICnCR2HH: <RIICn_base> + 0007H|||||||||||
|**Initial Value:**|||0000 0000HThis register is initialized by any reset.|||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26<br>25|24|23|22|21|20|19|18||17|16|
||—||—<br>—<br>—<br>—<br>—<br>—|—|—|—|—|—|—|—||—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0||0|0|
|R/W|R||R<br>R<br>R<br>R<br>R<br>R|R|R|R|R|R|R|R||R|R|
|Bit|15||14<br>13<br>12<br>11<br>10<br>9|8|7|6|5|4|3|2||1|0|
||—||—<br>—<br>—<br>—<br>—<br>—|—|BBSY|MST|TRS|—|SP|RS||ST|—|
|Initial value|0||0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0||0|0|
|R/W|R||R<br>R<br>R<br>R<br>R<br>R|R|R|R|R|R|R/W|R/W||R/W|R|

**Table 18.7 RIICnCR2 register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 8|—|Reserved|
||||These bits are read as 0. The write value should be 0.|
|7||BBSY|Bus Busy Detection Flag|
||||0: The I2C bus is released (bus free state).|
||||1: The I2C bus is occupied (bus busy state or in the bus free state).|
|6||MST|Master/Slave Mode|
||||0: Slave mode|
||||1: Transmit mode|
|5||TRS|Transmit/Receive Mode|
||||0: Receive mode|
||||1: Transmit mode|
|4||—|Reserved|
||||This bit is read as 0. The write value should be 0.|
|3||SP|Stop Condition Issuance Request|
||||0: Does not request to issue a stop condition.|
||||1: Requests to issue a stop condition.|
|2||RS|Restart Condition Issuance Request|
||||0: Does not request to issue a restart condition.|
||||1: Requests to issue a restart condition.|
|1||ST|Start Condition Issuance Request|
||||0: Does not request to issue a start condition.|
||||1: Requests to issue a start condition.|
|0||—|Reserved|
||||This bit is read as 0. The write value should be 0.|

## ST Bit (Start Condition Issuance Request)

This bit is used to request transition to master mode and issuance of a start condition.

When this bit is set to 1 to request to issue a start condition, a start condition is issued when the BBSY flag is set to 0 (bus free).

For details on the start condition issuance, see Section 18.12, Start Condition/Restart Condition/ Stop Condition Issuing Function .

[Setting condition]

When 1 is written to the ST bit

[Clearing conditions]

- When 0 is written to the ST bit

- When a start condition has been issued

- When the RIICnSR2.AL (arbitration-lost) flag is set to 1

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## **CAUTION**

Set the ST bit to 1 (start condition issuance request) when the BBSY flag is set to 0 (bus free). Note that arbitration may be lost if the ST bit is set to 1 (start condition issuance request) when the BBSY flag is set to 1 (bus busy).

RS Bit (Restart Condition Issuance Request)

This bit is used to request that a restart condition be issued in master mode.

When this bit is set to 1 to request to issue a restart condition, a restart condition is issued when the BBSY flag is set to 1 (bus busy) and the MST bit is set to 1 (master mode).

For details on the restart condition issuance, see Section 18.12, Start Condition/Restart Condition/ Stop Condition Issuing Function .

[Setting condition]

When 1 is written to the RS bit with the RIICnCR2.BBSY flag set to 1

[Clearing conditions]

- When 0 is written to the RS bit

- When a restart condition has been issued or a start condition is detected

- When a stop condition is detected

- When the RIICnCR2.AL (arbitration-lost) flag is set to 1

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## **CAUTIONS**

1. Do not set the RS bit to 1 while issuing a stop condition.

2. It is commended to issue a restart condition in master transmit mode. If the RS bit is set to 1 (restart condition issuance request) in mode other than master mode, the restart condition is not issued in this mode but the restart condition issuance request bit remains set. If the operating mode changes to master mode with the bit not being cleared, the restart condition may be issued.

## SP Bit (Stop Condition Issuance Request)

This bit is used to request that a stop condition be issued in master mode.

When this bit is set to 1 to request to issue a stop condition, a stop condition is issued when the BBSY flag is set to 1 (bus busy) and the MST bit is set to 1 (master mode).

For details on the stop condition issuance, see Section 18.12, Start Condition/Restart Condition/ Stop Condition Issuing Function .

[Setting condition]

When 1 is written to the SP bit with both the RIICnCR2.BBSY flag and the RIICnCR2.MST bit set to 1

[Clearing conditions]

- When 0 is written to the SP bit

- When a stop condition has been issued or a stop condition is detected

- When the RIICnSR2.AL (arbitration-lost) flag is set to 1

- When a start condition and a restart condition are detected

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## **CAUTIONS**

1. Wring to the SP bit is not possible while the setting of the BBSY flag is 0 (bus free). 2. Do not set the SP bit to 1 while a restart condition is being issued.

## TRS Bit (Transmit/Receive Mode)

This bit indicates transmit or receive mode.

The RIIC is in receive mode when the TRS bit is set to 0 and is in transmit mode when the bit is set to 1. Combination of this bit and the MST bit indicates the operating mode of the RIIC.

The value of the TRS bit is automatically changed to the value for transmission mode or reception mode by detection or issuing of a start condition, setting or clearing of the R/W# bit, etc.

[Setting conditions]

- When a start condition is issued normally according to the start condition issuance request (when a start condition is detected with the ST bit set to 1)

- When the R/W# bit added to the slave address is set to 0 in master mode

- When the address received in slave mode matches the address enabled in RIICnSER, with the R/ W# bit set to 1

[Clearing conditions]

- When a stop condition is detected

- The RIICnSR2.AL (arbitration-lost) flag being set to 1

- In master mode, reception of a slave address to which an R/W# bit with the value 1 is appended

- In slave mode, a match between the received address and the address enabled in RIICnSER when the value of the received R/W# bit is 0 (including cases where the received address is the general call address)

- In slave transmit mode, a restart condition is detected (a restart condition is detected with

RIICnCR2.BBSY = 1 and RIICnCR2.MST = 0)

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## MST Bit (Master/Slave Mode)

This bit indicates master or slave mode.

The RIIC is in slave mode when the MST bit is set to 0 and is in master mode when the bit is set to 1. Combination of this bit and the TRS bit indicates the operating mode of the RIIC.

The value of the MST bit is automatically changed to the value for master mode or slave mode by detection or issuing of a start condition, etc.

[Setting conditions]

- When a start condition is issued normally according to the start condition issuance request (when a start condition is detected with the ST bit set to 1)

[Clearing conditions]

- When a stop condition is detected

- When the RIICnSR2.AL (arbitration-lost) flag is set to 1

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## BBSY Flag (Bus Busy Detection)

The BBSY flag indicates whether the I[2] C bus is occupied (bus busy) or released (bus free).

This bit is set to 1 when the SDA line changes from high to low under the condition of SCL = high, assuming that a start condition has been issued.

When the SDA line changes from low to high under the condition of SCL = high, this bit is cleared to 0 after the bus free time (specified in RIICnBRL) start condition is not detected, assuming that a stop condition has been issued.

[Setting condition]

When a start condition is detected

[Clearing conditions]

- When the bus free time (specified in RIICnBRL) start condition is not detected after detecting a stop condition

- When 1 is written to the RIICnCR1.IICRST bit with the RIICnCR1.ICE bit set to 0 (RIIC reset)

## 18.3.3 RIICnMR1 — I²C Bus Mode Register 1

||**Access:**|**Access:**|RIICnMR1 is a 32-bit readable/writable register.|RIICnMR1 is a 32-bit readable/writable register.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnMR1L and RIICnMR1H are 16-bit readable/writable registers.|||||||||||
||||RIICnMR1LL, RIICnMR1LH, RIICnMR1HL, and RIICnMR1HH are 8-bit readable/writable registers.|||||||||||
||**Address:**||RIICnMR1: <RIICn_base> + 0008H|||||||||||
||||RIICnMR1L: <RIICn_base> + 0008H, RIICnMR1H: <RIICn_base> + 000AH|||||||||||
||||RIICnMR1LL: <RIICn_base> + 0008H, RIICnMR1LH: <RIICn_base>||||+ 0009H, RIICnMR1HL: <RIICn_base> + 000AH,|||||||
||||RIICnMR1HH: <RIICn_base> + 000BH|||||||||||
|**Initial Value:**|||0000 0008HThis register is initialized by any reset.|||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26|25|24|23|22|21|20|19|18|17|16|
||—||—<br>—<br>—<br>—<br>—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R|R|R|R|R|R|R|R|
|Bit|15||14<br>13<br>12<br>11<br>10|9|8|7|6|5|4|3|2|1|0|
||—||—<br>—<br>—<br>—<br>—|—|—|—||CKS[2:0]||BCWP||BC[2:0]||
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|1|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 18.8 RIICnMR1 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 7|―|Reserved|
|||These bits are read as 0. The write value should be 0.|
|6 to 4|CKS[2:0]|Internal Reference Clock (IIC) Selection|
|||b6   b4|
|||0 0 0: IIC= P0/1|
|||0 0 1: IIC= P0/2|
|||0 1 0: IIC= P0/4|
|||0 1 1: IIC= P0/8|
|||1 0 0: IIC= P0/16|
|||1 0 1: IIC= P0/32|
|||1 1 0: IIC= P0/64|
|||1 1 1: IIC= P0/128|
|3|BCWP*1|BC Write Protect|
|||0: Enables a value to be written in the BC[2:0] bits.|
|||(This bit is read as 1.)|
|2 to 0|BC[2:0]|Bit Counter|
|||b2   b0|
|||0 0 0: 9 bits|
|||0 0 1: 2 bits|
|||0 1 0: 3 bits|
|||0 1 1: 4 bits|
|||1 0 0: 5 bits|
|||1 0 1: 6 bits|
|||1 1 0: 7 bits|
|||1 1 1: 8 bits|

Note 1. When rewriting the BC[2:0] bits, write 0 to the BCWP bit simultaneously.

## BC[2:0] Bits (Bit Counter)

These bits function as a counter that indicates the number of bits remaining to be transferred at the detection of a rising edge on the SCL line. Although these bits are writable and readable, it is not necessary to access these bits under normal conditions.

To write to these bits, specify the number of bits to be transferred plus one (data is transferred with an additional acknowledge bit) between transferred frames when the SCL line is at a low level.

The values of the BC[2:0] bits return to 000B at the end of a data transfer including the acknowledge bit or when a start condition including a restart condition is detected.

## 18.3.4 RIICnMR2 — I²C Bus Mode Register 2

**Access:** RIICnMR2 is a 32-bit readable/writable register. RIICnMR2L and RIICnMR2H are 16-bit readable/writable registers. RIICnMR2LL, RIICnMR2LH, RIICnMR2HL, and RIICnMR2HH are 8-bit readable/writable registers. **Address:** RIICnMR2: <RIICn_base> + 000CH RIICnMR2L: <RIICn_base> + 000CH, RIICnMR2H: <RIICn_base> + 000EH RIICnMR2LL: <RIICn_base> + 000CH, RIICnMR2LH: <RIICn_base> + 000DH, RIICnMR2HL: <RIICn_base> + 000EH, RIICnMR2HH: <RIICn_base> + 000FH

|**Initial Value:**|**Initial Value:**|**Initial Value:**|0000|0000|0006HThis register is initialized by any reset.|0006HThis register is initialized by any reset.|0006HThis register is initialized by any reset.|0006HThis register is initialized by any reset.|0006HThis register is initialized by any reset.|0006HThis register is initialized by any reset.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|Bit|31||30||29|28|27|26|25|24|23|22||21|20|19|18|17|16|
||—||—||—|—|—|—|—|—|—|—||—|—|—|—|—|—|
|Initial value|0||0||0|0|0|0|0|0|0|0||0|0|0|0|0|0|
|R/W|R||R||R|R|R|R|R|R|R|R||R|R|R|R|R|R|
|Bit|15||14||13|12|11|10|9|8|7|6||5|4|3|2|1|0|
||—||—||—|—|—|—|—|—|DLCS||SDDL[2:0]|||—|TMOH|TMOL|TMOS|
|Initial value|0||0||0|0|0|0|0|0|0|0||0|0|0|1|1|0|
|R/W|R||R||R|R|R|R|R|R|R/W|R/W||R/W|R/W|R|R/W|R/W|R/W|

**Table 18.9 RIICnMR2 register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|7|DLCS|SDA Output Delay Clock Source Selection|
|||0: The internal reference clock (IIC) is selected as the clock source of the|
|||SDA output delay counter.|
|||1: The internal reference clock divided by 2 (IIC/2) is selected as the clock|
|||source of the SDA output delay counter.*1|
|6 to 4|SDDL[2:0]|SDA Output Delay Counter|
|||When RIICnMR2.DLCS = 0 (IIC)|
|||b6  b4|
|||0 0 0: No output delay|
|||0 0 1: 1 IICcycle|
|||0 1 0: 2 IICcycles|
|||0 1 1: 3 IICcycles|
|||1 0 0: 4 IICcycles|
|||1 0 1: 5 IICcycles|
|||1 1 0: 6 IICcycles|
|||1 1 1: 7 IICcycles|
|||When RIICnMR2.DLCS = 1 (IIC/2)|
|||b6  b4|
|||0 0 0: No output delay|
|||0 0 1: 1 or 2 IICcycles|
|||0 1 0: 3 or 4 IICcycles|
|||0 1 1: 5 or 6 IICcycles|
|||1 0 0: 7 or 8 IICcycles|
|3|—|Reserved|
|||This bit is read as 0. The write value should be 0.|
|2|TMOH|Timeout H Count Control|
|||0: Count is disabled while the SCL line is at a high level.|
|||1: Count is enabled while the SCL line is at a high level.|
|1|TMOL|Timeout L Count Control|
|||0: Count is disabled while the SCL line is at a low level.|
|||1: Count is enabled while the SCL line is at a low level.|

## **Table 18.9 RIICnMR2 register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|0|TMOS|Timeout Detection Time Selection|
|||0: Long mode is selected.|
|||1: Short mode is selected.|

Note 1. The setting DLCS = 1 (IIC/2) only becomes valid when SCL is at the low level. When SCL is at the high level, the setting DLCS = 1 becomes invalid and the clock source becomes the internal reference clock (IIC).

## TMOS Bit (Timeout Detection Time Selection)

This bit is used to select long mode or short mode for the timeout detection time when the timeout function is enabled (RIICnFER.TMOE bit = 1). When this bit is set to 0, long mode is selected. When this bit is set to 1, short mode is selected. In long mode, the timeout detection internal counter functions as a 16 bit-counter. In short mode, the counter functions as a 14 bit-counter. While the SCL line is in the state that enables this counter as specified by bits TMOH and TMOL, the counter counts up in synchronization with the internal reference clock (IIC  ) as a count source.

For details on the timeout function, see Section 18.13.1, Timeout Function .

## TMOL Bit (Timeout L Count Control)

This bit is used to enable or disable the internal counter of the timeout function to count up while the SCL line is held low when the timeout function is enabled (RIICnFER.TMOE bit = 1).

## TMOH Bit (Timeout H Count Control)

This bit is used to enable or disable the internal counter of the timeout function to count up while the SCL line is held high when the timeout function is enabled (RIICnFER.TMOE bit = 1).

## SDDL[2:0] Bits (SDA Output Delay Setup Counter)

The SDA output can be delayed by the SDDL[2:0] setting. This counter works with the clock source selected by the DLCS bit. The setting of this function can be used for all types of SDA output, including the transmission of the acknowledge bit.

For details on this function, see Section 18.7, Facility for Delaying SDA Output .

## **CAUTION**

Set the SDA output delay time to meet the I[2] C bus standard (within the data enable time/acknowledge enable time*[1] ) or the SMBus standard (within the data hold time: 300 [ns] or more, and SCL-clock lowlevel period - the data setup time: 250 [ns]). Note that, if a value outside the standard is set, communication with communication devices may malfunction or it may seemingly become a start condition or stop condition depending on the bus state.

Note 1. Data enable time/acknowledge enable time 3,450 [ns] (0 to 100 [kbps]: standard mode (Sm)) 900 [ns] (0 to 400 [kbps]: fast mode (Fm))

## 18.3.5 RIICnMR3 — I²C Bus Mode Register 3

||**Access:**|**Access:**|RIICnMR3 is a 32-bit readable/writable register.|RIICnMR3 is a 32-bit readable/writable register.|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnMR3L and RIICnMR3H are 16-bit readable/writable registers.||||||||||||
||||RIICnMR3LL, RIICnMR3LH, RIICnMR3HL, and RIICnMR3HH are 8-bit readable/writable registers.||||||||||||
||**Address:**||RIICnMR3: <RIICn_base> + 0010H||||||||||||
||||RIICnMR3L: <RIICn_base> + 0010H, RIICnMR3H: <RIICn_base> +||||0012H||||||||
||||RIICnMR3LL: <RIICn_base> + 0010H, RIICnMR3LH: <RIICn_base>|||||+ 0011H, RIICnMR3HL: <RIICn_base> + 0012H,|||||||
||||RIICnMR3HH: <RIICn_base> + 0013H||||||||||||
|**Initial Value:**|||0000 0000HThis register is initialized by any reset.||||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26|25|24|23||22|21|20|19|18|17|16|
||—||—<br>—<br>—<br>—<br>—|—|—|—||—|—|—|—|—|—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0||0|0|0|0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R||R|R|R|R|R|R|R|
|Bit|15||14<br>13<br>12<br>11<br>10|9|8|7||6|5|4|3|2|1|0|
||—||—<br>—<br>—<br>—<br>—|—|—|SMBE||WAIT|RDRFS|ACKWP|ACKBT|ACKBR|NF[1:0]||
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0||0|0|0|0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R/W||R/W|R/W|W|R/W|R|R/W|R/W|

## **Table 18.10 RIICnMR3 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|—|Reserved|
|||These bits are read as 0. The write value should be 0.|
|7|SMBE|SMBus/I2C Bus Selection|
|||0: I2C bus selection|
|||1: SMBus selection|
|6|WAIT*2|WAIT|
|||0: No WAIT|
|||(The period between ninth clock cycle and first clock cycle is not held low.)|
|||1: WAIT|
|||(The period between ninth clock cycle and first clock cycle is held low.)|
|||Low-hold is released by reading RIICnDRR.|
|5|RDRFS*2|RDRF Flag Set Timing Selection|
|||0: The RDRF flag is set at the rising edge of the ninth SCL clock cycle.|
|||(The SCL line is not held low at the falling edge of the eighth clock cycle.)|
|||1: The RDRF flag is set at the rising edge of the eighth SCL clock cycle.|
|||(The SCL line is held low at the falling edge of the eighth clock cycle.) Low-|
|||hold is released by writing a value to the ACKBT bit.|
|4|ACKWP*1|ACKBT Write Protect|
|||0: Modification of the ACKBT bit is disabled.|
|||1: Modification of the ACKBT bit is enabled.|
|3|ACKBT*1|Transmit Acknowledge|
|||0: A 0 is sent as the acknowledge bit (ACK transmission).|
|||1: A 1 is sent as the acknowledge bit (NACK transmission).|
|2|ACKBR|Receive Acknowledge|
|||0: A 0 is received as the acknowledge bit (ACK reception).|
|||1: A 1 is received as the acknowledge bit (NACK reception).|
|1, 0|NF[1:0]|Noise Filter Stage Selection|
|||b1 b0|
|||0 0: Noise of up to one IICcycle is filtered out (single-stage filter).|
|||0 1: Noise of up to two IICcycles is filtered out (2-stage filter).|
|||1 0: Noise of up to three IICcycles is filtered out (3-stage filter).|
|||1 1: Noise of up to four IICcycles is filtered out (4-stage filter).|

Note 1. If it is attempted to write 1 to both ACKWP and ACKBT bits, the ACKBT bit cannot be set to 1.

Note 2. The WAIT and RDRFS bits are valid only in receive mode (invalid in transmit mode).

## NF[1:0] Bits (Noise Filter Stage Selection)

These bits are used to select the noise width that can be eliminated for the signal input to RIICnSCL or RIICnSDA pin.

## ACKBR Bit (Receive Acknowledge)

This bit is used to store the acknowledge bit information received from the receive device in transmit mode.

[Setting condition]

When 1 is received as the acknowledge bit with the RIICnCR2.TRS bit set to 1

[Clearing conditions]

- When 0 is received as the acknowledge bit with the RIICnCR2.TRS bit set to 1

- When 1 is written to the RIICnCR1.IICRST bit while the RIICnCR1.ICE bit is 0 (RIIC reset)

## ACKBT Bit (Transmit Acknowledge)

This bit is used to set the bit to be sent at the acknowledge timing in receive mode.

[Setting condition]

When 1 is written to this bit with the ACKWP bit set to 1

[Clearing conditions]

- When 0 is written to this bit with the ACKWP bit set to 1

- When stop condition issuance is detected

- When 1 is written to the RIICnCR1.IICRST bit while the RIICnCR1.ICE bit is 0 (RIIC reset)

## **CAUTION**

The ACKBT bit must be written to while the ACKWP bit is 1. If the ACKBT bit is written to with the ACKWP bit cleared to 0, writing to the ACKBT bit is disabled.

## ACKWP Bit (ACKBT Write Protect)

This bit is used to control the modification of the ACKBT bit.

## RDRFS Bit (RDRF Flag Set Timing Selection)

This bit is used to select the RDRF flag set timing in receive mode and also to select whether to hold the SCL line low at the falling edge of the eighth SCL clock cycle.

When the RDRFS bit is 0, the SCL line is not held low at the falling edge of the eighth SCL clock cycle, and the RDRF flag is set to 1 at the rising edge of the ninth SCL clock cycle.

When the RDRFS bit is 1, the RDRF flag is set to 1 at the rising edge of the eighth SCL clock cycle and the SCL line is held low at the falling edge of the eighth SCL clock cycle. The low-hold of the SCL line is released by writing a value to the ACKBT bit.

After data is received with this setting, the SCL line is automatically held low before the acknowledge bit is sent. This enables processing to send ACK (ACKBT = 0) or NACK (ACKBT = 1) according to receive data.

## WAIT Bit (WAIT)

This bit is used to control whether to hold the period between the ninth SCL clock cycle and the first SCL clock cycle low until the receive data buffer (RIICnDRR) is completely read each time singlebyte data is received in receive mode.

When the WAIT bit is 0, the receive operation is continued without holding the period between the ninth and the first SCL clock cycle low. When both the RDRFS and WAIT bits are 0, continuous receive operation is enabled with the double buffer.

When the WAIT bit is 1, the SCL line is held low from the falling edge of the ninth clock cycle until the RIICnDRR value is read each time single-byte data is received. This enables receive operation in byte units.

## **CAUTION**

When the value of the WAIT bit is to be read, be sure to read the RIICnDRR beforehand.

## SMBE Bit (SMBus Select)

Setting this bit to 1 enables the RIICnSER.HOAE bit.

## 18.3.6 RIICnFER — I²C Bus Function Enable Register

||**Access:**|**Access:**|RIICnFER is a 32-bit readable/writable register.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnFERL and RIICnFERH are 16-bit readable/writable registers.||||||||||
||||RIICnFERLL, RIICnFERLH, RIICnFERHL, and RIICnFERHH are 8-bit readable/writable registers.||||||||||
||**Address:**||RIICnFER: <RIICn_base> + 0014H||||||||||
||||RIICnFERL: <RIICn_base> + 0014H, RIICnFERH:|<RIICn_base> + 0016H|||||||||
||||RIICnFERLL: <RIICn_base> + 0014H, RIICnFERLH: <RIICn_base>|||+ 0015H,|RIICnFERHL: <RIICn_base> + 0016H,||||||
||||RIICnFERHH: <RIICn_base> + 0017H||||||||||
|**Initial Value:**|||0000 0072HThis register is initialized by any reset.||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26<br>25|24|23|22|21|20|19|18|17|16|
||—||—<br>—<br>—<br>—<br>—<br>—|—|—|—|—|—|—|—|—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R<br>R|R|R|R|R|R|R|R|R|R|
|Bit|15||14<br>13<br>12<br>11<br>10<br>9|8|7|6|5|4|3|2|1|0|
||—||—<br>—<br>—<br>—<br>—<br>—|—|—|SCLE|NFE|NACKE|SALE|NALE|MALE|TMOE|
|Initial value|0||0<br>0<br>0<br>0<br>0<br>0|0|0|1|1|1|0|0|1|0|
|R/W|R||R<br>R<br>R<br>R<br>R<br>R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 18.11 RIICnFER register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 7|―|Reserved|
||||These bits are read as 0. The write value should be 0.|
|6||SCLE|SCL Synchronous Circuit Enable|
||||0: No SCL synchronous circuit is used.|
||||1: An SCL synchronous circuit is used.|
|5||NFE|Digital Noise Filter Circuit Enable|
||||0: No digital noise filter circuit is used.|
||||1: A digital noise filter circuit is used.|
|4||NACKE|NACK Reception Transfer Suspension Enable|
||||0: Transfer operation is not suspended during NACK reception (transfer|
||||suspension disabled).|
||||1: Transfer operation is suspended during NACK reception (transfer|
||||suspension enabled).|
|3||SALE|Slave Arbitration-Lost Detection Enable|
||||0: Slave arbitration-lost detection is disabled.|
||||1: Slave arbitration-lost detection is enabled.|
|2||NALE|NACK Transmission Arbitration-Lost Detection Enable|
||||0: NACK transmission arbitration-lost detection is disabled.|
||||1: NACK transmission arbitration-lost detection is enabled.|
|1||MALE|Master Arbitration-Lost Detection Enable|
||||0: Master arbitration-lost detection is disabled.|
||||(Disables the arbitration-lost detection function and does not clear the|
||||RIICnCR2.MST and TRS bits automatically when arbitration is lost.)|
||||1: Master arbitration-lost detection is enabled.|
||||(Enables the arbitration-lost detection function and clears the|
||||RIICnCR2.MST and TRS bits automatically when arbitration is lost.)|
|0||TMOE|Timeout Function Enable|
||||0: The timeout function is disabled.|
||||1: The timeout function is enabled.|

## TMOE Bit (Timeout Function Enable)

This bit is used to enable or disable the timeout function.

For details on the timeout function, see Section 18.13.1, Timeout Function .

## MALE Bit (Master Arbitration-Lost Detection Enable)

This bit is used to specify whether to use the arbitration-lost detection function in master mode. Normally, set this bit to 1.

## NALE Bit (NACK Transmission Arbitration-Lost Detection Enable)

This bit is used to specify whether to cause arbitration to be lost when ACK is detected during transmission of NACK in receive mode (such as when slaves with the same address exist on the bus or when two or more masters select the same slave device simultaneously with different number of receive bytes).

## SALE Bit (Slave Arbitration-Lost Detection Enable)

This bit is used to specify whether to cause arbitration to be lost when a value different from the value being transmitted is detected on the bus in slave transmit mode (such as when slaves with the same address exist on the bus or when a mismatch with the transmit data occurs due to noise).

## NACKE Bit (NACK Reception Transfer Suspension Enable)

This bit is used to specify whether to continue or discontinue the transfer operation when NACK is received in transmit mode. Normally, set this bit to 1.

When NACK is received with the NACKE bit set to 1, the next transfer operation is suspended.

When the NACKE bit is 0, the next transfer operation is continued regardless of the received acknowledge content.

## SCLE Bit (SCL Synchronous Circuit Enable)

This bit is used to specify whether to synchronize the SCL clock with the SCL input clock. Normally, set this bit to 1.

When the SCLE bit is cleared to 0 (SCL synchronous circuit not used), the RIIC does not synchronize the SCL clock with the SCL input clock. In this setting, the RIIC outputs the SCL clock with the transfer rate set in RIICnBRH and RIICnBRL regardless of the SCL line state. For this reason, if the bus load of the I[2] C bus line is much larger than the specification value or if the SCL clock output overlaps in multiple masters, the short-cycle SCL clock that does not meet the specification may be output. When no SCL synchronous circuit is used, it also affects the issuance of a start condition, restart condition, and stop condition, and the continuous output of extra SCL clock cycles.

This bit must not be cleared to 0 except for checking the output of the transfer rate.

## 18.3.7 RIICnSER — I²C Bus Status Enable Register

||**Access:**|**Access:**|RIICnSER is a 32-bit readable/writable register.|RIICnSER is a 32-bit readable/writable register.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnSERL and RIICnSERH are 16-bit readable/writable registers.|||||||||||
||||RIICnSERLL, RIICnSERLH, RRIICnSERHL, and RIICnSERHH are 8-bit readable/writable registers.|||||||||||
||**Address:**||RIICnSER: <RIICn_base> + 0018H|||||||||||
||||RIICnSERL: <RIICn_base> + 0018H, RIICnSERH: <RIICn_base> +||||001AH|||||||
||||RIICnSERLL: <RIICn_base> + 0018H, RIICnSERLH: <RIICn_base>|||||+ 0019H, RIICnSERHL: <RIICn_base> + 001AH,||||||
||||RIICnSERHH: <RIICn_base> + 001BH|||||||||||
|**Initial Value:**|||0000 0009HThis register is initialized by any reset.|||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26|25|24|23||22|21|20<br>19|18|17|16|
||—||—<br>—<br>—<br>—<br>—|—|—|—||—|—|—<br>—|—|—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0||0|0|0<br>0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R||R|R|R<br>R|R|R|R|
|Bit|15||14<br>13<br>12<br>11<br>10|9|8|7||6|5|4<br>3|2|1|0|
||—||—<br>—<br>—<br>—<br>—|—|—|HOAE||—|DIDE|—<br>GCE|SAR2|SAR1|SAR0|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0||0|0|0<br>1|0|0|1|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R/W||R|R/W|R<br>R/W|R/W|R/W|R/W|

**Table 18.12 RIICnSER register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 8|―|Reserved|
||||These bits are read as 0. The write value should be 0.|
|7||HOAE|Host Address Enable|
||||0: Host address detection is disabled.|
||||1: Host address detection is enabled.|
|6||—|Reserved|
||||This bit is read as 0. The write value should be 0.|
|5||DIDE|Device-ID Address Detection Enable|
||||0: Device-ID address detection is disabled.|
||||1: Device-ID address detection is enabled.|
|4||—|Reserved|
||||This bit is read as 0. The write value should be 0.|
|3||GCE|General Call Address Enable|
||||0: General call address detection is disabled.|
||||1: General call address detection is enabled.|
|2||SAR2|Slave Address Register 2 Enable|
||||0: Slave address in RIICnSAR2 is disabled.|
||||1: Slave address in RIICnSAR2 is enabled.|
|1||SAR1|Slave Address Register 1 Enable|
||||0: Slave address in RIICnSAR1 is disabled.|
||||1: Slave address in RIICnSAR1 is enabled.|
|0||SAR0|Slave Address Register 0 Enable|
||||0: Slave address in RIICnSAR0 is disabled.|
||||1: Slave address in RIICnSAR0 is enabled.|

## SARy Bit (Slave Address Register y Enable) (y = 0 to 2)

This bit is used to enable or disable the received slave address and the slave address set in RIICnSARy.

When this bit is set to 1, the slave address set in RIICnSARy is enabled and is compared with the received slave address.

When this bit is cleared to 0, the slave address set in RIICnSARy is disabled and is ignored even if it matches the received slave address.

## GCE Bit (General Call Address Enable)

This bit is used to specify whether to ignore the general call address (0000 000B + 0 [W]: All 0) when it is received.

When this bit is set to 1, if the received slave address matches the general call address, the RIIC recognizes the received slave address as the general call address independently of the slave addresses set in RIICnSARy (y = 0 to 2) and performs data receive operation.

When this bit is cleared to 0, the received slave address is ignored even if it matches the general call address.

## **DIDE Bit (Device-ID Address Detection Enable)**

This bit is used to specify whether to recognize and execute the Device-ID address when a device ID (1111 100B) is received in the first frame after a start condition or restart condition is detected.

When this bit is set to 1, if the received first frame matches the device ID, the RIIC recognizes that the Device-ID address has been received. When the following R/W# bit is 0 [W], the RIIC recognizes the second and the following frames as slave addresses and continues the receive operation.

When this bit is cleared to 0, the RIIC ignores the received first frame even if it matches the device ID address and recognizes the first frame as a normal slave address.

For details on the device-ID address detection, see **Section 18.9.3, Device-ID Address Detection** .

## **HOAE Bit (Host Address Enable)**

This bit is used to specify whether to ignore received host address (0001 000B) when the RIICnMR3.SMBS bit is 1.

When this bit is set to 1 while the RIICnMR3.SMBS bit is 1, if the received slave address matches the host address, the RIIC recognizes the received slave address as the host address independently of the slave addresses set in RIICnSARy (y = 0 to 2) and performs the receive operation.

When the RIICnMR3.SMBS bit or the HOAE bit is cleared to 0, the received slave address is ignored even if it matches the host address.

## 18.3.8 RIICnIER — I²C Bus Interrupt Enable Register

||**Access:**|**Access:**|RIICnIER is a 32-bit readable/writable register.|RIICnIER is a 32-bit readable/writable register.|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnIERL and RIICnIERH are 16-bit readable/writable registers.||||||||||||
||||RIICnIERLL, RIICnIERLH, RIICnIERHL, and RIICnIERHH are 8-bit readable/writable registers.||||||||||||
||**Address:**||RIICnIER: <RIICn_base> + 001CH||||||||||||
||||RIICnIERL: <RIICn_base> + 001CH, RIICnIERH: <RIICn_base> + 001EH||||||||||||
||||RIICnIERLL: <RIICn_base> + 001CH, RIICnIERLH: <RIICn_base> + 001DH, RIICnIERHL: <RIICn_base> + 001EH,||||||||||||
||||RIICnIERHH: <RIICn_base> + 001FH||||||||||||
|**Initial Value:**|||0000 0000HThis register is initialized by any reset.||||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26|25|24|23|22|21|20|19|18||17|16|
||—||—<br>—<br>—<br>—<br>—|—|—|—|—|—|—|—|—||—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|0||0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R|R|R|R|R|R||R|R|
|Bit|15||14<br>13<br>12<br>11<br>10|9|8|7|6|5|4|3|2||1|0|
||—||—<br>—<br>—<br>—<br>—|—|—|TIE|TEIE|RIE|NAKIE|SPIE|STIE||ALIE|TMOIE|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|0||0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R/W|

**Table 18.13 RIICnIER register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 8|―|Reserved|
||||These bits are read as 0. The write value should be 0.|
|7||TIE|Transmit Data Empty Interrupt Enable|
||||0: Transmit data empty interrupt (INTRIICTI) request is disabled.|
||||1: Transmit data empty interrupt (INTRIICTI) request is enabled.|
|6||TEIE|Transmit End Interrupt Enable|
||||0: Transmit end interrupt (INTRIICTEI) request is disabled.|
||||1: Transmit end interrupt (INTRIICTEI) request is enabled.|
|5||RIE|Receive Data Full Interrupt Enable|
||||0: Receive data full interrupt (INTRIICRI) request is disabled.|
||||1: Receive data full interrupt (INTRIICRI) request is enabled.|
|4||NAKIE|NACK Reception Interrupt Enable|
||||0: NACK reception interrupt (INTRIICNAKI) request is disabled.|
||||1: NACK reception interrupt (INTRIICNAKI) request is enabled.|
|3||SPIE|Stop Condition Detection Interrupt Enable|
||||0: Stop condition detection interrupt (INTRIICSPI) request is disabled.|
||||1: Stop condition detection interrupt (INTRIICSPI) request is enabled.|
|2||STIE|Start Condition Detection Interrupt Enable|
||||0: Start condition detection interrupt (INTRIICSTI) request is disabled.|
||||1: Start condition detection interrupt (INTRIICSTI) request is enabled.|
|1||ALIE|Arbitration-Lost Interrupt Enable|
||||0: Arbitration-lost interrupt (INTRIICALI) request is disabled.|
||||1: Arbitration-lost interrupt (INTRIICALI) request is enabled.|
|0||TMOIE|Timeout Interrupt Enable|
||||0: Timeout interrupt (INTRIICTMOI) request is disabled.|
||||1: Timeout interrupt (INTRIICTMOI) request is enabled.|

## TMOIE Bit (Timeout Interrupt Enable)

This bit is used to enable or disable timeout interrupt (INTRIICTMOI) requests when the RIICnSR2.TMOF flag is set to 1. An INTRIICTMOI interrupt request is canceled by clearing the TMOF flag or the TMOIE bit to 0.

## ALIE Bit (Arbitration-Lost Interrupt Enable)

This bit is used to enable or disable arbitration-lost interrupt (INTRIICALI) requests when the RIICnSR2.AL flag is set to 1. An INTRIICALI interrupt request is canceled by clearing the AL flag or the ALIE bit to 0.

## STIE Bit (Start Condition Detection Interrupt Enable)

This bit is used to enable or disable start condition detection interrupt (INTRIICSTI) requests when the RIICnSR2.START flag is set to 1. An INTRIICSTI interrupt request is canceled by clearing the START flag or the STIE bit to 0.

SPIE Bit (Stop Condition Detection Interrupt Enable)

This bit is used to enable or disable stop condition detection interrupt (INTRIICSPI) requests when the RIICnSR2.STOP flag is set to 1. An INTRIICSPI interrupt request is canceled by clearing the STOP flag or the SPIE bit to 0.

NAKIE Bit (NACK Reception Interrupt Enable)

This bit is used to enable or disable NACK reception interrupt (INTRIICNAKI) requests when the RIICnSR2.NACKF flag is set to 1. An INTRIICNAKI interrupt request is canceled by clearing the NACKF flag or the NAKIE bit to 0.

RIE Bit (Receive Data Full Interrupt Enable)

This bit is used to enable or disable receive data full interrupt (INTRIICRI) requests when the RIICnSR2.RDRF flag is set to 1. An INTRIICRI interrupt request is canceled by clearing the RDRF flag or the RIE bit to 0.

TEIE Bit (Transmit End Interrupt Enable)

This bit is used to enable or disable transmit end interrupts (INTRIICTEI) when the RIICnSR2.TEND flag is set to 1. An INTRIICTEI interrupt request is canceled by clearing the TEND flag or the TEIE bit to 0.

## TIE Bit (Transmit Data Empty Interrupt Enable)

This bit is used to enable or disable transmit data empty interrupts (INTRIICTI) when the RIICnSR2.TDRE flag is set to 1.

## 18.3.9 RIICnSR1 — I²C Bus Status Register 1

||**Access:**|**Access:**|RIICnSR1 is a 32-bit readable/writable register.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnSR1L and RIICnSR1H are 16-bit readable/writable registers.||||||||||
||||RIICnSR1LL, RIICnSR1LH, RIICnSR1HL, and RIICnSR1HH are 8/1-bit readable/writable registers.||||||||||
||**Address:**||RIICnSR1: <RIICn_base> + 0020H||||||||||
||||RIICnSR1L: <RIICn_base> + 0020H, RIICnSR1H:|<RIICn_base> + 0022H|||||||||
||||RIICnSR1LL: <RIICn_base> + 0020H, RIICnSR1LH: <RIICn_base> + 0021H,||||RIICnSR1HL: <RIICn_base> + 0022H,||||||
||||RIICnSR1HH: <RIICn_base> + 0023H||||||||||
|**Initial Value:**|||0000 0000HThis register is initialized by any reset.||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26<br>25|24|23|22|21|20|19|18|17|16|
||—||—<br>—<br>—<br>—<br>—<br>—|—|—|—|—|—|—|—|—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R<br>R|R|R|R|R|R|R|R|R|R|
|Bit|15||14<br>13<br>12<br>11<br>10<br>9|8|7|6|5|4|3|2|1|0|
||—||—<br>—<br>—<br>—<br>—<br>—|—|HOA|—|DID|—|GCA|AAS2|AAS1|AAS0|
|Initial value|0||0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R<br>R|R|R(/W)<br>*1|R|R(/W)<br>*1|R|R/W<br>*1|R(W)<br>*1|R(/W)<br>*1|R(/W)<br>*1|

Note 1. Only 0 can be written to this bit.

**Table 18.14 RIICnSR1 register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 8|―|Reserved|
||||These bits are read as 0. The write value should be 0.|
|7||HOA|Host Address Detection Flag|
||||0: Host address is not detected.|
||||1: Host address is detected.|
|6||—|Reserved|
||||This bit is read as 0. The write value should be 0.|
|5||DID|Device-ID Address Detection Flag|
||||0: Device-ID command is not detected.|
||||1: Device-ID command is detected.|
|4||—|Reserved|
||||This bit is read as 0. The write value should be 0.|
|3||GCA|General Call Address Detection Flag|
||||0: General call address is not detected.|
||||1: General call address is detected.|
|2||AAS2|Slave Address 2 Detection Flag|
||||0: Slave address 2 is not detected.|
||||1: Slave address 2 is detected.|
|1||AAS1|Slave Address 1 Detection Flag|
||||0: Slave address 1 is not detected.|
||||1: Slave address 1 is detected.|
|0||AAS0|Slave Address 0 Detection Flag|
||||0: Slave address 0 is not detected.|
||||1: Slave address 0 is detected.|

AASy Flag (Slave Address y Detection) (y = 0 to 2)

[Setting conditions]

<For 7-bit address format: RIICnSARy.FSy = 0>

When the received slave address matches the RIICnSARy.SVA[7:1] value with the RIICnSER.SARy bit set to 1 (slave address y detection enabled)

This flag is set to 1 at the rising edge of the ninth SCL clock cycle in the frame.

<For 10-bit address format: RIICnSARy.FSy = 1>

When the received slave address matches a value of (1111 0B + RIICnSARy.SVA[9:8]) and the following address matches the RIICnSARy.SVA[7:0] value with the RIICnSER.SARy bit set to 1 (slave address y detection enabled)

This flag is set to 1 at the rising edge of the ninth SCL clock cycle in the frame.

[Clearing conditions]

- When 0 is written to the AASy bit after reading AASy = 1

- When a stop condition is detected

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

<For 7-bit address format: RIICnSARy.FSy = 0>

- When the received slave address does not match the RIICnSARy.SVA[7:1] value with the RIICnSER.SARy bit set to 1 (slave address y detection enabled)

This flag is cleared to 0 at the rising edge of the ninth SCL clock cycle in the frame.

<For 10-bit address format: RIICnSARy.FSy = 1>

- When the received slave address does not match a value of (1111 0B + RIICnSARy.SVA[9:8]) with the RIICnSER.SARy bit set to 1 (slave address y detection enabled) This flag is cleared to 0 at the rising edge of the ninth SCL clock cycle in the frame.

- When the received slave address matches a value of (1111 0B + RIICnSARy.SVA[9:8]) and the following address does not match the RIICnSARy.SVA[7:0] value with the RIICnSER.SARy bit set to 1 (slave address y detection enabled)

This flag is cleared to 0 at the rising edge of the ninth SCL clock cycle in the frame.

GCA Flag (General Call Address Detection)

[Setting condition]

When the received slave address matches the general call address (0000 000B + 0 [W]) with the RIICnSER.GCE bit set to 1 (general call address detection enabled)

This flag is set to 1 at the rising edge of the ninth SCL clock cycle in the frame.

[Clearing conditions]

- When 0 is written to the GCA bit after reading GCA = 1

- When a stop condition is detected

- When the received slave address does not match the general call address (0000 000B + 0 [W]) with the RIICnSER.GCE bit set to 1 (general call address detection enabled) This flag is cleared to 0 at the rising edge of the ninth SCL clock cycle in the frame.

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

DID Flag (Device-ID Address Detection)

[Setting condition]

- When the first frame received immediately after a start condition or restart condition is detected matches a value of (device ID (1111 100B) + 0 [W]) with the RIICnSER.DIDE bit set to 1 (Device-ID address detection enabled)

This flag is set to 1 at the rising edge of the ninth SCL clock cycle in the frame.

- When a restart condition is detected after a match with the device ID address and the device ID address (1111 100B) + 1 [R] has matched with the RIICnSER.DIDE bit set to 1 (Device-ID address detection enabled)

This flag is set to 1 at the rising edge of the ninth SCL clock cycle in the frame.

- [Clearing conditions]

- When 0 is written to the DID bit after reading DID = 1

- When a stop condition is detected

- When the first frame received immediately after a start condition or restart condition is detected does not match a value of (device ID (1111 100B)) with the RIICnSER.DIDE bit set to 1 (DeviceID address detection enabled)

This flag is cleared to 0 at the rising edge of the ninth SCL clock cycle in the frame.

- When the first frame received immediately after a start condition or restart condition is detected matches a value of (device ID (1111 100B) + 0 [W]) and the second frame does not match any of slave addresses 0 to 2 with the RIICnSER.DIDE bit set to 1 (Device-ID address detection enabled) This flag is cleared to 0 at the rising edge of the ninth SCL clock cycle in the frame.

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

HOA Flag (Host Address Detection)

[Setting condition]

When the received slave address matches the host address (0001 000B) while the RIICnMR3.SMBE bit and RIICnSER.HOAE bit are set to 1 (host address detection enabled)

This flag is set to 1 at the rising edge of the ninth SCL clock cycle in the frame.

[Clearing conditions]

- When 0 is written to the HOA bit after reading HOA = 1

- When a stop condition is detected

- When 0 is written to the RIICnMR3.SMBE bit or the RIICnSER.HOAE bit

- When the received slave address does not match the host address (0001 000B) with the RIICnSER.HOAE bit set to 1 (host address detection enabled)

This flag is cleared to 0 at the rising edge of the ninth SCL clock cycle in the frame.

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## 18.3.10 RIICnSR2 — I²C Bus Status Register 2

**Access:** RIICnSR2 is a 32-bit readable/writable register. RIICnSR2L and RIICnSR2H are 16-bit readable/writable registers. RIICnSR2LL, RIICnSR2LH, RIICnSR2HL, and RIICnSR2HH are 8/1-bit readable/writable registers. **Address:** RIICnSR2: <RIICn_base> + 0024H RIICnSR2L: <RIICn_base> + 0024H, RIICnSR2H: <RIICn_base> + 0026H RIICnSR2LL: <RIICn_base> + 0024H, RIICnSR2LH: <RIICn_base> + 0025H, RIICnSR2HL: <RIICn_base> + 0026H, RIICnSR2HH: <RIICn_base> + 0027H

|**Initial Value:**|**Initial Value:**|**Initial Value:**|0000|0000|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|Bit|31||30||29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—||—||—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0||0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R||R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15||14||13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—||—||—|—|—|—|—|—|TDRE|TEND|RDRF|NACKF|STOP|START|AL|TMOF|
|Initial value|0||0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R||R|R|R|R|R|R|R|R(/W)<br>*1|R(/W)<br>*1|R(/W)<br>*1|R(/W)<br>*1|R(/W)<br>*1|R(/W)<br>*1|R(/W)<br>*1|

Note 1. Only 0 can be written to this bit.

## **Table 18.15 RIICnSR2 register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 8|―|Reserved|
||||These bits are read as 0. The write value should be 0.|
|7||TDRE|Transmit Data Empty Flag|
||||0: RIICnDRT contains transmit data.|
||||1: RIICnDRT contains no transmit data.|
|6||TEND|Transmit End Flag|
||||0: Data is being transmitted.|
||||1: Data has been transmitted.|
|5||RDRF|Receive Data Full Flag|
||||0: RIICnDRR contains no receive data.|
||||1: RIICnDRR contains receive data.|
|4||NACKF|NACK Receive Flag|
||||0: NACK is not received.|
||||1: NACK is received.|
|3||STOP|Stop Condition Detection Flag|
||||0: Stop condition is not detected.|
||||1: Stop condition is detected.|
|2||START|Start Condition Detection Flag|
||||0: Start condition is not detected.|
||||1: Start condition is detected.|
|1||AL|Arbitration-Lost Flag|
||||0: Arbitration is not lost.|
||||1: Arbitration is lost.|
|0||TMOF|Timeout Flag|
||||0: Timeout has not occurred.|
||||1: Timeout occurred.|

## TMOF Flag (Timeout)

This flag is set to 1 when the RIIC recognizes timeout after the SCL line state remains unchanged for a certain period.

[Setting condition]

The timeout function is enabled when the RIICnFER.TMOE bit is 1. It detects an abnormal bus state that the SCL line is held low or high during the following conditions:

- The bus is busy (RIICnCR2.BBSY = 1) in master mode (RIICnCR2.MST = 1).

- The slave address matches that of this module (RIICnSR1 register is not 00H) and the bus is busy (RIICnCR2.BBSY = 1) in slave mode (RIICnCR2.MST = 0).

- Issuing of a start condition is being requested (RIICnCR2.ST = 1) and the bus is free (RIICnCR2.BBSY = 0).

[Clearing conditions]

- When 0 is written to the TMOF bit after reading TMOF = 1

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## AL Flag (Arbitration-Lost)

This flag shows that bus mastership has been lost (loss in arbitration) due to a bus conflict or some other reason when a start condition is issued or an address and data are transmitted. The RIIC monitors the level on the SDA line during transmission and, if the level on the line does not match the value of the bit being output, sets the value of the AL bit to 1 to indicate that the bus is occupied by another device.

The RIIC can also set the flag to indicate the detection of loss of arbitration during NACK transmission in receive mode or during data transmission in slave mode.

[Setting conditions]

<When master arbitration-lost detection is enabled: RIICnFER.MALE = 1>

- When the internal SDA output state does not match the SDA line level at the rising edge of SCL clock except for the ACK period during data (including slave address) transmission in master transmit mode (when the SDA line is driven low while the internal SDA output is at a high level (the SDA pin is in the high-impedance state))

- When a start condition is detected while the RIICnCR2.ST bit is 1 (start condition issuance request) or the internal SDA output state does not match the SDA line level

- When the RIICnCR2.ST bit is set to 1 (start condition issuance request) with the RIICnCR2.BBSY flag set to 1.

<When NACK arbitration-lost detection is enabled: RIICnFER.NALE = 1>

When the internal SDA output state does not match the SDA line level at the rising edge of SCL clock in the ACK period during NACK transmission in receive mode

<When slave arbitration-lost detection is enabled: RIICnFER.SALE = 1>

When the internal SDA output state does not match the SDA line level at the rising edge of SCL clock except for the ACK period during data transmission in slave transmit mode

[Clearing conditions]

- When 0 is written to the AL bit after reading AL = 1

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

**Table 18.16 Relationship between Arbitration-Lost Generation Sources and ArbitrationLost Enable Functions**

|**RIICnFER**|**RIICn**<br>**SR2**<br>**Error**<br>**AL**|**Arbitration-Lost Generation Source**|
|---|---|---|
|**MALE**<br>**NALE**<br>**SALE**|||
|1<br>x<br>x|1<br>Start condition<br>issuance error|When internal SDA output state does not match<br>SDA line level when a start condition is detected<br>while the RIICnCR2.ST bit is 1|
|||When RIICnCR2.ST is set to 1 with<br>RIICnCR2.BBSY set to 1|
||1<br>Transmit data<br>mismatch|When transmit data (including slave address) does<br>not match the bus state in master transmit mode|
|x<br>1<br>x|1<br>NACK transmission<br>mismatch|When ACK is detected during transmission of NACK<br>in master receive mode or slave receive mode|
|x<br>x<br>1|1<br>Transmit data<br>mismatch|When transmit data does not match the bus state in<br>slave transmit mode|

x: Don’t care

## START Flag (Start Condition Detection)

[Setting condition]

When a start condition (or a restart condition) is detected

[Clearing conditions]

- When 0 is written to the START bit after reading START = 1

- When a stop condition is detected

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## STOP Flag (Stop Condition Detection)

[Setting condition]

When a stop condition is detected

[Clearing conditions]

- When 0 is written to the STOP bit after reading STOP = 1

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## NACKF Flag (NACK Receive)

[Setting condition]

When acknowledge is not received (NACK is received) from the receive device in transmit mode with the RIICnFER.NACKE bit set to 1 (transfer suspension enabled)

[Clearing conditions]

- When 0 is written to the NACKF bit after reading NACKF = 1

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## **CAUTION**

When the NACKF flag is set to 1, the RIIC suspends data transmission/reception. Writing to RIICnDRT in transmit mode or reading from RIICnDRR in receive mode with the NACKF flag set to 1 does not enable data transmit/receive operation. To restart data transmission/reception, clear the NACKF flag to 0.

## RDRF Flag (Receive Data Full)

[Setting conditions]

- Slave receive mode

   - When the received slave address matches and the RIICnCR2.TRS bit is cleared to 0 after a start condition (or a restart condition) is detected

   - At the rising edge of the eighth or ninth SCL clock cycle (selected by the RIICnMR3.RDRFS bit) after receive data is transferred from RIICnDRS to RIICnDRR

- Master receive mode

   - When the slave address and the data direction are transmitted and the receive mode is entered (the RIICnCR2.TRS bit is set to 0) after a start condition (or a restart condition) is issued

   - At the rising edge of the eighth or ninth SCL clock cycle (selected by the RIICnMR3.RDRFS bit) after receive data is transferred from RIICnDRS to RIICnDRR

[Clearing conditions]

- When 0 is written to the RDRF bit after reading RDRF = 1

- When data is read from RIICnDRR

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## TEND Flag (Transmit End)

[Setting condition]

At the rising edge of the ninth SCL clock cycle while the TDRE flag is 1

[Clearing conditions]

- When 0 is written to the TEND bit after reading TEND = 1

- When data is written to RIICnDRT

- When a stop condition is detected

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## TDRE Flag (Transmit Data Empty)

[Setting conditions]

- When data has been transferred from RIICnDRT to RIICnDRS and RIICnDRT becomes empty

- When the RIICnCR2.TRS bit is set to 1

   - When the RIICnCR2.MST bit is set to 1 after a start condition (or a restart condition) is detected

   - When the RIIC enters transmit mode from receive mode

- When the received slave address matches while the TRS bit is 1

- [Clearing conditions]

- When data is written to RIICnDRT

- When the RIICnCR2.TRS bit is cleared to 0

   - When a stop condition is detected

   - When the RIIC enters receive mode from transmit mode

- When 1 is written to the RIICnCR1.IICRST bit to apply an RIIC reset or an internal reset

## **CAUTION**

When the NACKF flag is set to 1 while the RIICnFER.NACKE bit is 1, the RIIC suspends data transmission/reception. Here, if the TDRE flag is 0 (next transmit data has been written), data is transferred to the RIICnDRS register and the RIICnDRT register becomes empty at the rising edge of the ninth clock cycle, but the TDRE flag is not set to 1.

## 18.3.11 RIICnSARy — I²C Slave Address Register y (y = 0 to 2)

**Access:** RIICnSARy is a 32-bit readable/writable register. RIICnSARyL and RIICnSARyH are 16-bit readable/writable registers. RIICnSARyLL, RIICnSARyLH, RIICnSARyHL, and RIICnSARyHH are 8-bit readable/writable registers.

**Address:** RIICnSAR0: <RIICn_base> + 0028H RIICnSAR0L: <RIICn_base> + 0028H, RIICnSAR0H: <RIICn_base> + 002AH RIICnSAR0LL: <RIICn_base> + 0028H, RIICnSAR0LH: <RIICn_base> + 0029H, RIICnSAR0HL: <RIICn_base> + 002AH, RIICnSAR0HH: <RIICn_base> + 002BH RIICnSAR1: <RIICn_base> + 002CH RIICnSAR1L: <RIICn_base> + 002CH, RIICnSAR1H: <RIICn_base> + 002EH RIICnSAR1LL: <RIICn_base> + 002CH, RIICnSAR1LH: <RIICn_base> + 002DH, RIICnSAR1HL: <RIICn_base> + 002EH, RIICnSAR1HH: <RIICn_base> + 002FH RIICnSAR2: <RIICn_base> + 0030H RIICnSAR2L: <RIICn_base> + 0030H, RIICnSAR2H: <RIICn_base> + 0032H RIICnSAR2LL: <RIICn_base> + 0030H, RIICnSAR2LH: <RIICn_base> + 0031H, RIICnSAR2HL: <RIICn_base> + 0032H, RIICnSAR2HH: <RIICn_base> + 0033H

**Initial Value:** 0000 0000H This register is initialized by any reset.

|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||FSy|—|—|—|—|—|||||SVA[9:1]|||||SVA0|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 18.17 RIICnSARy register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 16|―|Reserved|
|||These bits are read as 0. The write value should be 0.|
|15|FSy|7-Bit/10-Bit Address Format Selection|
|||0: The 7-bit address format is selected.|
|||1: The 10-bit address format is selected.|
|14 to 10|―|Reserved|
|||These bits are read as 0. The write value should be 0.|
|9 to 1|SVA[9:1]|7-Bit Address/10-Bit Address Upper Bits|
|||A slave address is set.|
|||When the FSy bit is 0 (7-bit address format), the SVA[7:1] bits are Valid and|
|||form a 7-bit slave address.|
|||When the FSy bit is 1 (10-bit address format), SVA[9:1] bits form a 10-bit|
|||slave address (combined with the SVA0 bit).|
|0|SVA0|10-Bit Address LSB|
|||The least significant bit (LSB) of a 10-bit slave address is set.|
|||When the FSy bit is 0 (7-bit address format), this bit is invalid.|
|||When the FSy bit is 1 (10-bit address format), this bit is a 10-bit slave|
|||address (combined with the SVA[9:1] bits).|

## **SVA0 Bit (10-Bit Address LSB)**

When the 10-bit address format is selected (RIICnSARy.FSy = 1), this bit functions as the LSB of a 10bit address and forms a 10-bit address in combination with the SVA[9:1] bits.

When the RIICnSER.SARy bit is set to 1 (RIICnSARy enabled) and the RIICnSARy.FSy bit is 1, this bit is valid. While the RIICnSARy.FSy bit or SARy bit is 0, the setting of this bit is ignored.

## **SVA[9:1] Bits (7-Bit Address/10-Bit Address Upper Bits)**

When the 7-bit address format is selected (RIICnSARy.FSy = 0), these bits function as a 7-bit address. When the 10-bit address format is selected (RIICnSARy.FSy = 1), these bits function as a 10-bit address in combination with the SVA0 bit.

While the RIICnSER.SARy bit is 0, the setting of these bits is ignored.

## FSy Bit (7-Bit/10-Bit Address Format Selection)

This bit is used to select 7-bit address or 10-bit address for slave address y (in RIICnSARy).

When the RIICnSER.SARy bit is set to 1 (RIICnSARy enabled) and the RIICnSARy.FSy bit is 0, the 7- bit address format is selected for slave address y, the RIICnSARy.SVA[7:1] setting is valid, and the settings of the SVA[9:8] bits and the RIICnSARy.SVA0 bit are ignored.

When the RIICnSER.SARy bit is set to 1 (RIICnSARy enabled) and the RIICnSARy.FSy bit is 1, the 10-bit address format is selected for slave address y and the settings of the SVA[9:1] bits and the SVA0 bit are valid.

While the RIICnSER.SARy bit is 0 (RIICnSARy disabled), the setting of the RIICnSARy.FSy bit is invalid.

## 18.3.12 RIICnBRL — I²C Bus Bit Rate Low-Level Register

**Access:** RIICnBRL is a 32-bit readable/writable register. RIICnBRLL and RIICnBRLH are 16-bit readable/writable registers. RIICnBRLLL, RIICnBRLLH, RIICnBRLHL, and RIICnBRLHH are 8-bit readable/writable registers. **Address:** RIICnBRL: <RIICn_base> + 0034H RIICnBRLL: <RIICn_base> + 0034H, RIICnBRLH: <RIICn_base> + 0036H RIICnBRLLL: <RIICn_base> + 0034H, RIICnBRLLH: <RIICn_base> + 0035H, RIICnBRLHL: <RIICn_base> + 0036H, RIICnBRLHH: <RIICn_base> + 0037H

|**Initial Value:**|**Initial Value:**|**Initial Value:**|0000|0000|00FFHThis register is initialized by|00FFHThis register is initialized by|00FFHThis register is initialized by|00FFHThis register is initialized by|any reset.|any reset.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|Bit|31||30||29|28|27|26|25||24|23|22|21|20|19|18|17|16|
||—||—||—|—|—|—|—||—|—|—|—|—|—|—|—|—|
|Initial value|0||0||0|0|0|0|0||0|0|0|0|0|0|0|0|0|
|R/W|R||R||R|R|R|R|R||R|R|R|R|R|R|R|R|R|
|Bit|15||14||13|12|11|10|9||8|7|6|5|4|3|2|1|0|
||—||—||—|—|—|—|—||—|—|—|—|||BRL[4:0]|||
|Initial value|0||0||0|0|0|0|0||0|1|1|1|1|1|1|1|1|
|R/W|R||R||R|R|R|R|R||R|R|R|R|R/W|R/W|R/W|R/W|R/W|

**Table 18.18 RIICnBRL register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|―|Reserved|
|||These bits are read as 0. The write value should be 0.|
|7 to 5|—|Reserved|
|||These bits are read as 1. The write value should be 1.|
|4 to 0|BRL[4:0]|Bit Rate Low-Level Period|
|||Low-level period of SCL clock|

The RIICnBRL register is a 5-bit register that is used to set the width at low level for the SCL clock.

It also works to generate the data setup time for automatic SCL low-hold operation (see Section 18.10, Automatically Low-Hold Function for SCL ); when the RIIC is used only in slave mode, this *[1] register needs to be set to a value equal to or longer than the data setup time .

RIICnBRL counts the low-level period with the internal reference clock source (IIC  ) specified by the RIICnMR1.CKS[2:0] bits.

Note 1. Data setup time (tSU: DAT) 250 [ns] (0 to 100 [kbps]: standard mode (Sm)) 100 [ns] (0 to 400 [kbps]: fast mode (Fm))

## 18.3.13 RIICnBRH — I²C Bus Bit Rate High-Level Register

||**Access:**|**Access:**|RIICnBRH is a 32-bit readable/writable register.|RIICnBRH is a 32-bit readable/writable register.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||RIICnBRHL and RIICnBRHH are 16-bit readable/writable registers.|||||||||||
||||RIICnBRHLL, RIICnBRHLH, RIICnBRHHL, and RIICnBRHHH are 8-bit readable/writable registers.|||||||||||
||**Address:**||RIICnBRH: <RIICn_base> + 0038H|||||||||||
||||RIICnBRHL: <RIICn_base> + 0038H, RIICnBRHH: <RIICn_base> + 003AH|||||||||||
||||RIICnBRHLL: <RIICn_base> + 0038H, RIICnBRHLH: <RIICn_base>||||+ 0039H, RIICnBRHHL: <RIICn_base> + 003AH,|||||||
||||RIICnBRHHH:<RIICn_base> + 003BH|||||||||||
|**Initial Value:**|||0000 00FFHThis register is initialized by|any reset.||||||||||
|Bit|31||30<br>29<br>28<br>27<br>26|25|24|23|22|21|20|19|18|17|16|
||—||—<br>—<br>—<br>—<br>—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R|R|R|R|R|R|R|R|
|Bit|15||14<br>13<br>12<br>11<br>10|9|8|7|6|5|4|3|2|1|0|
||—||—<br>—<br>—<br>—<br>—|—|—|—|—|—|||BRH[4:0]|||
|Initial value|0||0<br>0<br>0<br>0<br>0|0|0|1|1|1|1|1|1|1|1|
|R/W|R||R<br>R<br>R<br>R<br>R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|

**Table 18.19 RIICnBRH register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|―|Reserved|
|||These bits are read as 0. The write value should be 0.|
|7 to 5|—|Reserved|
|||These bits are read as 1. The write value should be 1.|
|4 to 0|BRH[4:0]|Bit Rate High-Level Period|
|||High-level period of SCL clock|

RIICnBRH is a 5-bit register to set the high-level period of SCL clock. RIICnBRH is valid in master mode. If the RIIC is used only in slave mode, this register need not to set the high-level period.

RIICnBRH counts the high-level period with the internal reference clock source (IIC  ) specified by the RIICnMR1.CKS[2:0] bits.

The frequency and duty cycle are calculated using one of the following expressions (1) to (5) according to the register settings.

## CAUTION

The minimum value that can be specified in RIICnBRL and RIICnBRH is determined according to the values of the SCLE and NFE bits in RIICnFER and the NF bit in RIICnMR3. For details of the minimum specifiable value, see Table 18.20.

- (1) When SCLE = 0

Frequency = 1 / {[ (BRH + 1) + (BRL + 1)] / IIC  + tr + tf}

Duty cycle = {tr + (BRH + 1) / IIC  } / {tr + tf + [(BRH + 1) + (BRL + 1)] / IIC  }

- (2) When SCLE = 1, NFE = 0, CKS = 000 (IIC  = P0  ) Frequency = 1 / {[(BRH + 3) + (BRL + 3)] / IIC  + tr + tf} Duty cycle = {tr + (BRH + 3) / IIC  } / {tr + tf + [(BRH + 3) + (BRL + 3) ] / IIC  }

- (3) When SCLE = 1, NFE = 1, CKS = 000 (IIC  = P0  ) Frequency = 1 / {[(BRH + 3 + nf) + (BRL + 3 + nf)] / IIC  + tr + tf} Duty cycle = {tr + (BRH + 3 + nf) / IIC  } / {tr + tf + [(BRH + 3 + nf) + (BRL + 3 + nf)] / IIC  }

- (4) When SCLE = 1, NFE = 0, CKS  000 (IIC  < P0  ) Frequency = 1 / {[(BRH + 2) + (BRL + 2)] / IIC  + tr + tf} Duty cycle = {tr + (BRH + 2) / IIC  } / {tr + tf + [(BRH + 2) + (BRL + 2) ] / IIC  }

- (5) When SCLE = 1, NFE = 1, CKS  000 (IIC  < P0  ) Frequency = 1 / {[(BRH + 2 + nf) + (BRL + 2 + nf)] / IIC  + tr + tf} Duty cycle = {tr + (BRH + 2 + nf) / IIC  } / {tr + tf + [(BRH + 2 + nf) + (BRL + 2 + nf) ] / IIC  }

Symbols in the expressions SCLE: RIICnFER.SCLE bit BRH: RIICnBRH.BRH[4:0] bits BRL: RIICnBRL.BRL[4:0] bits CKS: RIICnMR1.CKS bits NFE: RIICnFER.NFE bit IIC  : Internal reference clock selected by the CKS bits

- tf: SCL signal falling time [s] *[1]

- tr: SCL signal rising time [s] *[1]

nf: Number of digital noise filter stages specified in the RIICnMR3.NF[0.1] bits

- Note 1. The rising time (tr) and falling time (tf) of the SCL signal depend on the total capacitance of the bus line (Cb) and pull-up resistor (Rp).  For details, see I[2] C Bus Standard from NXP Semiconductors.

**Table 18.20 Minimum Specifiable Value for RIICnBRL and RIICnBRH**

||||**Minimum Pulse**|**Minimum**|**Pulse Width**|
|---|---|---|---|---|---|
||||**Width that**|**Specifiable**|**when Minimum**|
||||**Passes through**|**Value for BRH**|**Value is**|
|**SCLE**|**NFE**|**nf**|**Digital Filter**|**and BRL**|**Specified**|
|0|0|―|1IIC|1|2IIC|
|0|1|1|2IIC|2|3IIC|
|0|1|2|3IIC|3|4IIC|
|0|1|3|4IIC|4|5IIC|
|0|1|4|5IIC|5|6IIC|
|||IIC|cycle > P0cycle (CKS000)|||
|1|0|―|1IIC|0|2IIC|
|1|1|1|2IIC|1|4IIC|
|1|1|2|3IIC|2|6IIC|

**Table 18.20 Minimum Specifiable Value for RIICnBRL and RIICnBRH**

||||**Minimum Pulse**|**Minimum**|**Pulse Width**|
|---|---|---|---|---|---|
||||**Width that**|**Specifiable**|**when Minimum**|
||||**Passes through**|**Value for BRH**|**Value is**|
|**SCLE**|**NFE**|**nf**|**Digital Filter**|**and BRL**|**Specified**|
|1|1|3|4IIC|3|8IIC|
|1|1|4|5IIC|4|10IIC|
|||IIC|cycle = P0cycle (CKS = 000)|||
|1|0|―|2P0|0|3IIC|
|1|1|1|3P0|1|5IIC|
|1|1|2|4P0|2|7IIC|
|1|1|3|5P0|3|9IIC|
|1|1|4|6P0|4|11IIC|

Table 18.21 and Table 18.22 list examples of RIICnBRH/RIICnBRL settings.

## **Table 18.21 Examples of RIICnBRH/RIICnBRL Settings for Transfer Rate (when RIICnFER.SCLE = 1 and RIICnFER.NFE = 0)**

|**Transfer**<br>**Rate**<br>**[kbps]**|**Peripheral Clock Operating Frequency P0****[MHz]**|
|---|---|
||**25**<br>**30**<br>**33**|
||**RIICnMR1.**<br>**CKS[2:0]**<br>**RIICnBRH.**<br>**BRH**<br>**RIICnBRL.**<br>**BRL**<br>**RIICnMR1.**<br>**CKS[2:0]**<br>**RIICnBRH.**<br>**BRH**<br>**RIICnBRL.**<br>**BRL**<br>**RIICnMR1.**<br>**CKS[2:0]**<br>**RIICnBRH.**<br>**BRH**<br>**RIICnBRL.**<br>**BRL**|
|10|110B<br>21 (F5H)<br>14 (EEH)<br>110B<br>25 (F9H)<br>18 (F2H)<br>111B<br>12 (ECH)<br>10 (EAH)|
|50|100B<br>20 (F4H)<br>7 (E7H)<br>100B<br>20 (F4H)<br>13 (EDH)<br>100B<br>22 (F6H)<br>15 (EFH)|
|100|010B<br>30 (FEH)<br>29 (FDH)<br>011B<br>18 (F2H)<br>16 (F0H)<br>011B<br>20 (F4H)<br>18 (F2H)|
|400|000B<br>27 (FBH)<br>30 (FEH)<br>001B<br>16 (F0H)<br>18 (F2H)<br>001B<br>18 (F2H)<br>20 (F4H)|

**Table 18.22 Examples of RIICnBRH/RIICnBRL Settings for Transfer Rate (when RIICnFER.SCLE = 1, RIICnFER.NFE= 1, and Number of NF Stages = 4)**

|**Transfer**<br>**Rate**<br>**[kbps]**|**Peripheral Clock Operating Frequency P0****[MHz]**|
|---|---|
||**25**<br>**30**<br>**33**|
||**RIICnMR1.**<br>**CKS[2:0]**<br>**RIICnBRH.**<br>**BRH**<br>**RIICnBRL.**<br>**BRL**<br>**RIICnMR1.**<br>**CKS[2:0]**<br>**RIICnBRH.**<br>**BRH**<br>**RIICnBRL.**<br>**BRL**<br>**RIICnMR1.**<br>**CKS[2:0]**<br>**RIICnBRH.**<br>**BRH**<br>**RIICnBRL.**<br>**BRL**|
|10|110B<br>19 (F3H)<br>8 (E8H)<br>110B<br>24 (F8H)<br>11 (EBH)<br>110B<br>28 (FCH)<br>12 (ECH)|
|50|011B<br>28 (FCH)<br>22 (F6H)<br>100B<br>19 (F3H)<br>7 (E7H)<br>100B<br>20 (F4H)<br>10 (EAH)|
|100|010B<br>26 (FAH)<br>25 (F9H)<br>011B<br>14 (EEH)<br>12 (ECH)<br>011B<br>16 (F0H)<br>14 (EEH)|
|400|000B<br>23 (F7H)<br>26 (FAH)<br>001B<br>11 (EBH)<br>15 (EFH)<br>001B<br>14 (EEH)<br>16 (F0H)|

## 18.3.14 RIICnDRT — I²C Bus Transmit Data Register

**Access:** RIICnDRT is a 32-bit readable/writable register. RIICnDRTL and RIICnDRTH are 16-bit readable/writable registers. RIICnDRTLL, RIICnDRTLH, RIICnDRTHL, and RIICnDRTHH are 8-bit readable/writable registers. **Address:** RIICnDRT: <RIICn_base> + 003CH RIICnDRTL: <RIICn_base> + 003CH, RIICnDRTH: <RIICn_base> + 003EH RIICnDRTLL: <RIICn_base> + 003CH, RIICnDRTLH: <RIICn_base> + 003DH, RIICnDRTHL: <RIICn_base> + 003EH, RIICnDRTHH: <RIICn_base> + 003FH

|**Initial Value:**|**Initial Value:**|**Initial Value:**|0000|0000|00FFHThis register is initialized by|00FFHThis register is initialized by|00FFHThis register is initialized by|00FFHThis register is initialized by|any reset.|any reset.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|Bit|31||30||29|28|27|26|25||24|23|22|21|20|19|18|17|16|
||—||—||—|—|—|—|—||—|—|—|—|—|—|—|—|—|
|Initial value|0||0||0|0|0|0|0||0|0|0|0|0|0|0|0|0|
|R/W|R||R||R|R|R|R|R||R|R|R|R|R|R|R|R|R|
|Bit|15||14||13|12|11|10|9||8|7|6|5|4|3|2|1|0|
||—||—||—|—|—|—|—||—||||DRT[7:0]|||||
|Initial value|0||0||0|0|0|0|0||0|1|1|1|1|1|1|1|1|
|R/W|R||R||R|R|R|R|R||R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

When RIICnDRT detects a space in the I[2] C bus shift register (RIICnDRS), it transfers the transmit data that has been written to RIICnDRT to RIICnDRS and starts transmitting data in transmit mode.

The double-buffer structure of RIICnDRT and RIICnDRS allows continuous transmit operation if the next transmit data has been written to RIICnDRT while the RIICnDRS data is being transmitted.

RIICnDRT can always be read and written. Write transmit data to RIICnDRT once when a transmit data empty interrupt (INTRIICTI) request is generated. When writing to bits 8 to 15, be sure to write 0 to these bits.

## 18.3.15 RIICnDRR — I²C Bus Receive Data Register

**Access:** RIICnDRR is a 32-bit readable/writable register. RIICnDRRL and RIICnDRRH are 16-bit readable/writable registers. RIICnDRRLL, RIICnDRRLH, RIICnDRRHL, and RIICnDRRHH are 8-bit readable/writable registers. **Address:** RIICnDRR: <RIICn_base> + 0040H RIICnDRRL: <RIICn_base> + 0040H, RIICnDRRH: <RIICn_base> + 0042H RIICnDRRLL: <RIICn_base> + 0040H, RIICnDRRLH: <RIICn_base> + 0041H, RIICnDRRHL: <RIICn_base> + 0042H, RIICnDRRHH: <RIICn_base> + 0043H

|**Initial Value:**|**Initial Value:**|**Initial Value:**|0000|0000|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|0000HThis register is initialized by any reset.|||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|Bit|31||30||29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—||—||—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0||0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R||R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15||14||13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—||—||—|—|—|—|—|—||||DRR[7:0]|||||
|Initial value|0||0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R||R|R|R|R|R|R|R|R|R|R|R|R|R|R|

When 1 byte of data has been received, the received data is transferred from the I[2] C bus shift register (RIICnDRS) to RIICnDRR to enable the next data to be received.

The double-buffer structure of RIICnDRS and RIICnDRR allows continuous receive operation if the received data has been read from RIICnDRR while RIICnDRS is receiving data.

RIICnDRR cannot be written. Read data from RIICnDRR once when a receive data full interrupt (INTRIICRI) request is generated.

If DRR receives the next receive data before the current data is read from RIICnDRR (while the RIICnSR2.RDRF flag is 1), the RIIC automatically holds the SCL clock low one cycle before the RDRF flag is set to 1 next.

## 18.3.16 RIICnDRS — I²C Bus Shift Register

||||**Access:**|**Access:**|This register is not accessible.|This register is not accessible.|This register is not accessible.|This register is not accessible.|This register is not accessible.||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||**Address:**||—||||||||||||||
||||**Initial Value:**||0000|00FFH|||||||||||||
|Bit|31|30|29|28|27||26|25||24|23|22|21|20|19|18|17|16|
||—|—|—|—|—||—|—||—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0||0|0||0|0|0|0|0|0|0|0|0|
|R/W|—|—|—|—|—||—|—||—|—|—|—|—|—|—|—|—|
|Bit|15|14|13|12|11||10|9||8|7|6|5|4|3|2|1|0|
||—|—|—|—|—||—|—||—||||DRS[7:0]|||||
|Initial value|0|0|0|0|0||0|0||0|1|1|1|1|1|1|1|1|
|R/W|—|—|—|—|—||—|—||—|—|—|—|—|—|—|—|—|

RIICnDRS is an 8-bit shift register to transmit and receive data.

During transmission, transmit data is transferred from RIICnDRT to RIICnDRS and is sent from the SDA pin. During reception, data is transferred from RIICnDRS to RIICnDRR after 1 byte of data has been received.

RIICnDRS cannot be accessed directly.

## 18.4 Interrupt Sources

The RIIC issues eight types of interrupt requests: transmission complete, receive data full, transmit data empty, detection of a stop condition, detection of a start condition, reception of a NACK, arbitration lost, and timeout.

Table 18.23 lists details of the interrupt requests. The receive data full and transmit data empty interrupt sources are both capable of launching data transfer by starting the DMAC.

**Table 18.23 Interrupt Sources**

|**Symbol**<br>**Interrupt Source**<br>**Interrupt**<br>**Flag**<br>**DMAC**<br>**Launching**<br>**Priority*1**|**Interrupt Condition**|
|---|---|
|INTRIICTEI<br>Transmission complete<br>TEND<br>Not possible<br>High<br>Low<br>INTRIICRI<br>Receive data full<br>RDRF<br>Possible<br>INTRIICTI<br>Transmit data empty<br>TDRE<br>Possible<br>INTRIICSPI<br>Detection of a stop<br>condition<br>STOP<br>Not possible<br>INTRIICSTI<br>Detection of a start<br>condition<br>START<br>Not possible<br>INTRIICNAKI<br>Reception of a NACK<br>NACKF<br>Not possible<br>INTRIICALI<br>Arbitration lost<br>AL<br>Not possible<br>INTRIICTMOI<br>Timeout<br>TMOF<br>Not possible|TEND = 1 • TEIE = 1|
||RDRF = 1 • RIE = 1|
||TDRE = 1 • TIE = 1|
||STOP = 1 • SPIE = 1|
||START = 1 • STIE = 1|
||NACKF = 1 • NAKIE = 1|
||AL = 1 • ALIE = 1|
||TMOF = 1 • TMOIE = 1|

Note 1. When the setting value of the interrupt priority register (ICDIPRn) is the same

Clear or mask the each flag during interrupt handling.

## CAUTIONS

1. There is a latency (delay) between the execution of a write instruction for a peripheral module by the CPU and actual writing to the module. Thus, when an interrupt flag has been cleared or masked, read the relevant flag again to check whether clearing or masking has been completed, and then return from interrupt processing. Returning from interrupt processing without checking that writing to the module has been completed creates a possibility of repeated processing of the same interrupt.

2. The INTRIICRI and INTRIICTI interrupts do not need to be cleared because they are edge interrupts.

3. When using the INTRIICTEI interrupt, clear the RIICnSR2.TEND flag in the INTRIICTEI interrupt processing.

4. When using the INTRIICSPI interrupt, clear the RIICnSR2.STOP flag in the INTRIICSPI interrupt processing.

5. When using the INTRIICSTI interrupt, clear the RIICnSR2.START flag in the INTRIICSTI interrupt processing.

6. When using the INTRIICNAKI interrupt, clear the RIICnSR2.NACKF flag in the INTRIICNAKI interrupt processing.

7. When using the INTRIICALI interrupt, clear the RIICnSR2.AL flag in the INTRIICALI interrupt processing.

8. When using the INTRIICTMOI interrupt, clear the RIICnSR2.TMOF flag in the INTRIICTMOI interrupt processing.

## 18.5 Operation

## 18.5.1 Communication Data Format

The I[2] C bus format consists of 8-bit data and 1-bit acknowledge (one frame). After a start condition or restart condition is issued, the master device sends the slave address and data direction in the first frame. The specified slave is valid until a stop condition is issued or a new slave is specified by a restart condition.

Figure 18.3 shows the I[2] C bus format, and Figure 18.4 shows the I[2] C bus timing.

**==> picture [387 x 180] intentionally omitted <==**

**----- Start of picture text -----**<br>
[7-bit address format]<br>S SLA (7 bits) R/W# A DATA (8 bits) A A/A# P n: Number of transfer frames<br>1 7 1 1 8 1 1 1<br>n (n = 1 or more)<br>[10-bit address format: Master transmission]<br>S 11110b+SLA(2 bits) W# A SLA (8 bits) A DATA (8 bits) A A/A# P<br>1 7 1 1 8 1 8 1 1 1<br>n (n = 1 or more)<br>[10-bit address format: Master reception]<br>S 11110b+SLA(2 bits) W# A SLA (8 bits) A Sr 11110b+SLA(2 bits) R A DATA (8 bits) A A/A# P<br>1 7 1 1 8 1 1 7 1 1 8 1 1 1<br>n (n = 1 or more)<br>**----- End of picture text -----**<br>

**Figure 18.3 I[2] C Bus Format**

**==> picture [394 x 75] intentionally omitted <==**

**----- Start of picture text -----**<br>
SDA<br>SCL 1 to 7 8 9 1 to 7 8 9 1 to 7 8 9<br>S SLA R/W# A Data A Data A P<br>**----- End of picture text -----**<br>

**Figure 18.4 I[2] C Bus Timing (SLA = 7 Bits)**

- S: Start condition. The master device drives the SDA line low from high level while the SCL line is at a high level.

- SLA: Slave address, by which the master device selects a slave device.

- R/W#: Indicates the direction of data transfer: from the slave device to the master device when R/W is 1, or from the master device to the slave device when R/W is 0.

- A: Acknowledge. The receive device drives the SDA line low. (In master transmit mode, the slave device returns acknowledge. In master receive mode, the master device returns acknowledge.)

- A#: Not-acknowledge. The receiving device has not returned a response or is not present so the SDA line has remained at the high level.

- Sr: Restart condition. The master device drives the SDA line low from the high level after the setup time has elapsed with the SCL line at the high level.

DATA: Transmitted or received data

- P: Stop condition. The master device drives the SDA line high from low level while the SCL line is at a high level.

## 18.5.2 Initial Settings

Before starting data transmission and reception, initialize the RIIC according to the procedure in Figure 18.5 .

**==> picture [330 x 411] intentionally omitted <==**

**----- Start of picture text -----**<br>
Initial settings<br>RIICnSCL, RIICnSDA pins not<br>Clear ICE in RIICnCR1 to 0<br>driven<br>Set IICRST in RIICnCR1 to 1 RIIC reset<br>Set ICE in RIICnCR1 to 1 Internal reset<br>Set RIICnSARy and<br>Set slave address format and slave address<br>Set RIICnSER<br>Set CKS[2:0] in RIICnMR1 and<br>Set transfer bit rate* [1]<br>RIICnBRL/RIICnBRH<br>Set RIICnMR2 and RIICnMR3<br>* [2]<br>Set RIICnFER<br>Set RIICnIER Set interrupt enable<br>Clear IICRST in  Release from the internal reset state<br>RIICnCR1 to 0<br>End<br>y = 0 to 2<br>Note 1. When the RIIC is used only in slave mode, set the RIICnBRL register to a<br>value equal to or longer than the data setup time.<br>Note 2. Set these registers as necessary.<br>**----- End of picture text -----**<br>

## **Figure 18.5 Example of RIIC Initialization Flowchart**

## 18.5.3 Master Transmit Operation

In master transmit operation, the RIIC outputs the SCL (clock) and transmitted data signals as the master device, and the slave device returns acknowledgements. Figure 18.6 shows an example of usage of master transmission and Figure 18.7 to Figure 18.9 show the timing of operations in master transmission.

The following describes the procedure and operations for master transmission.

- (1) Set the RIICnCR1.IICRST bit 1 to 1 (RIIC reset) and then set the RIICnCR1.ICE bit to 1 (internal reset) with the RIICnCR1.ICE bit cleared to 0 (RIICnSCL and RIICnSDA pins not driven). This initializes the internal state and the various flags of RIICnSR1. After that, set registers RIICnSARy, RIICnSER, RIICnMR1, RIICnBRH, and RIICnBRL (y = 0 to 2), and set the other registers as necessary (for initial settings of the RIIC, see Figure 18.5 ). When the necessary register settings have been completed, set the RIICnCR1.IICRST bit to 0 (for release from the reset state). This step is not necessary if initialization of the RIIC has already been completed.

- (2) Read the RIICnCR2.BBSY flag to check that the bus is open, and then set the RIICnCR2.ST bit to 1 (start condition issuance request). Upon receiving the request, the RIIC issues a start condition. At the same time, the BBSY flag and the RIICnSR2.START flag are automatically set to 1 and the ST bit is automatically cleared to 0. At this time, if the start condition is detected and the internal levels for the SDA output state and the levels on the SDA line have matched while the ST bit is 1, the RIIC recognizes that issuing of the start condition as requested by the ST bit has been successfully completed, and the RIICnCR2.MST and TRS bits are automatically set to 1, placing the RIIC in master transmit mode. The RIICnSR2.TDRE flag is also automatically set to 1 in response to setting of the TRS bit to 1.

- (3) Check that the RIICnSR2.TDRE flag is 1, and then write the value for transmission (the slave address and the R/W# bit) to RIICnDRT. Once the data for transmission are written to RIICnDRT, the TDRE flag is automatically cleared to 0, the data are transferred from RIICnDRT to RIICnDRS, and the TDRE flag is again set to 1. After the byte containing the slave address and R/W# bit has been transmitted, the value of the TRS bit is automatically updated to select master transmit or master receive mode in accord with the value of the transmitted R/W# bit. If the value of the R/W# bit was 0, the RIIC continues in master transmit mode.

   - Since the RIICnSR2.NACKF flag being 1 at this time indicates that no slave device recognized the address or there was an error in communications, write 1 to the RIICnCR2.SP bit to issue a stop condition.

For data transmission with an address in the 10-bit format, start by writing 1111 0B, the two higher-order bits of the slave address, and W# to RIICnDRT as the first address transmission. Then, as the second address transmission, write the eight lower-order bits of the slave address to RIICnDRT.

- (4) After confirming that the RIICnSR2.TDRE flag is 1, write the data for transmission to the RIICnDRT register. The RIIC automatically holds the SCL line low until the data for transmission are ready or a stop condition is issued.

- (5) After the last byte of the data to be transmitted is written to RIICnDRT register, wait until the value of the RIICnSR2.TEND flag returns to 1, and then set the RIICnCR2.SP bit to 1 (stop condition issuance request). Upon receiving a stop condition issuance request, the RIIC issues the stop condition.

- (6) Upon detecting the stop condition, the RIIC automatically clears the RIICnCR2.MST and TRS bits to 00B and enters slave receive mode. Furthermore, it automatically clears the RIICnSR2.TDRE and TEND flags to 0, and sets the RIICnSR2.STOP flag in to 1.

- (7) Clear the RIICnSR2.NACKF and STOP flags to 0.

## CAUTION

Operations for transfer start if the RIICnSR2.NACKF flag is cleared to 0 before RIICnSR2.STOP is set to 1. Be sure to confirm that RIICnSR2.STOP is set to 1 before clearing RIICnSR2.NACKF to 0. In particular, when the NACK receive interrupt (INTRIICNAKI) is in use, take care not to clear the NACKF flag to 0 before the STOP flag is set to 1 during interrupt processing.

**==> picture [393 x 488] intentionally omitted <==**

**----- Start of picture text -----**<br>
Master transmission<br>Initial settings [1] Initial settings<br>No<br>RIIC0CR2.BBSY = 0?<br>[2] Check I [2] C bus occupation and issue a start<br>Yes condition.<br>RIIC0CR2.ST = 1<br>No<br>RIIC0SR2.NACKF = 0?<br>Yes<br>No<br>RIIC0SR2.TDRE = 1?<br>[3] Transmit slave address and W (first byte).<br>Yes [4] Check ACK and set transmit data.<br>Write data to ICDRT<br>No<br>All data transmitted?<br>Yes<br>No<br>RIIC0SR2.TEND = 1?<br>Yes<br>[5] Check end of last data transmission<br>RIIC0SR2.STOP = 0<br>and issue a stop condition.<br>RIIC0CR2.SP = 1<br>No<br>RIIC0SR2.STOP = 1? [6] Check stop condition issuance<br>Yes<br>RIIC0SR2.NACKF = 0<br>[7] Processing for the next transfer operation<br>RIIC0SR2.STOP = 0<br>End of master transmission<br>**----- End of picture text -----**<br>

**Figure 18.6 Example of Master Transmission Flowchart**

**==> picture [393 x 228] intentionally omitted <==**

**----- Start of picture text -----**<br>
Automatic low-hold (to prevent wrong transmission)<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4<br>SCLn<br>SDAn b7  b6  b5     b4     b3     b2     b1     b0 ACK b7  b6  b5     b4     b3     b2     b1     b0    ACK b7  b6  b5     b4<br>7-bit slave address W DATA 1 DATA 2<br>BBSY<br>MST<br>TRS Trans mi t data (7-bit address + W) Transmit data (DATA 1) Transmit data (DATA 2)<br>TDRE<br>TEND<br>RDRF<br>RIICnDRT 7-bit address + W DATA 1 DATA 2 DATA 3<br>RIICnDRS 7-bit address + W DATA 1 DATA 2<br>RIICnDRR XXXX (Initial value/last data for reception)<br>ACKBT 0 (ACK)<br>ACKBR X (ACK/NACK) 0 (ACK) 0 (ACK)<br>START<br>ST<br>Write 1  Write data to  Write data to  Write data to  Write data to<br>to ST RIICnDRT RIICnDRT RIICnDRT RIICnDRT<br>(7-bit address + W) (DATA 1) (DATA 2) (DATA 3)<br>[2] [3] [4] [4] [4]<br>**----- End of picture text -----**<br>

**Figure 18.7 Master Transmit Operation Timing (1) (7-Bit Address Format)**

**==> picture [393 x 230] intentionally omitted <==**

**----- Start of picture text -----**<br>
Automatic low-hold (to prevent wrong transmission)<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4<br>SCLn<br>SDAn b7  b6  b5  b4  b3 b2     b1     b0 ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK b7  b6  b5     b4<br>Upper 10-bit addresses (11110b + 2 bits) W Lower 10-bit addresses DATA 1<br>BBSY<br>MST<br>TRS T ransmit  d ata (upper 10 bits + W) Transmit data (lower 10 bits) Transmit data (DATA 1)<br>TDRE<br>TEND<br>RDRF<br>RIICnDRT 1 0-bit address + W Lower 10 bits DATA 1 DATA 2<br>RIICnDRS Upper 10 bits + W Lower 10 bits DATA 1<br>RIICnDRR XXXX (Initial value/last data for reception)<br>ACKBT 0 (ACK)<br>ACKBR X (ACK/NACK) 0 (ACK) 0 (ACK)<br>START<br>ST<br>Write 1  Write data to  Write data to  Write data to  Write data to<br>to ST RIICnDRT RIICnDRT RIICnDRT RIICnDRT<br>(11110b + 2 bits + W) (lower 8 bits) (DATA 1) (DATA 2)<br>[2] [3] [4] [4]<br>**----- End of picture text -----**<br>

**Figure 18.8 Master Transmit Operation Timing (2) (10-Bit Address Format)**

**==> picture [400 x 225] intentionally omitted <==**

**----- Start of picture text -----**<br>
7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 P<br>SCLn<br>SDAn b1     b0     ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK b7  b6  b5     b4     b3     b2     b1     b0     A/NA<br>DATA n-2 DATA n-1 DATA n<br>BBSY<br>MST<br>TRS Transmit data (DATA n-1) Transmit data (DATA n)<br>TDRE<br>TEND<br>RDRF<br>RIICnDRT DATA n-1 DATA n<br>RIICnDRS DATA n-2 DATA  n-1 DATA n<br>RIICnDRR XXXX (Initial value/final receive data)<br>ACKBT 0 (ACK)<br>ACKBR 0 (ACK) 0 (ACK) X (ACK/NACK)<br>STOP<br>SP<br>Write data to RIICnDRT Write 1 to  Clear<br>(Final transmit data [DATA n]) SP STOP to 0<br>[4] [5] [7]<br>**----- End of picture text -----**<br>

**Figure 18.9 Master Transmit Operation Timing (3)**

## 18.5.4 Master Receive Operation

In master receive operation, the RIIC as a master device outputs the SCL (clock) signal, receives data from the slave device, and returns acknowledgements. Since the RIIC must start by sending a slave address to the corresponding slave device, this part of the procedure is performed in master transmit mode, but the subsequent steps are in master receive mode.

Figure 18.10 shows an example of usage for the master reception of 3 or more bytes (7-bit address format), Figure 18.14 shows an example of usage for the master reception of 1 or 2 bytes (7-bit address format), and Figure 18.11 to Figure 18.13 show the timing of operations in master reception.

The following describes the procedure and operations for master reception.

- (1) Set the RIICnCR1.IICRST bit to 1 (RIIC reset) and then set the RIICnCR1.ICE bit to 1 (internal reset) with the RIICnCR1.ICE bit cleared to 0 (RIICnSCL and RIICnSDA pins not driven). This initializes the internal state and the various flags of RIICnSR1. After that, set registers RIICnSARy, RIICnSER, RIICnMR1, RIICnBRH, and RIICnBRL (y = 0 to 2), and set the other registers as necessary (for initial settings of the RIIC, see Figure 18.5 ). When the necessary register settings have been completed, set the RIICnCR1.IICRST bit to 0 (for release from the reset state). This step is not necessary if initialization of the RIIC has already been completed.

- (2) Read the RIICnCR2.BBSY flag to check that the bus is open, and then set the RIICnCR2.ST bit to 1 (start condition issuance request). Upon receiving the request, the RIIC issues a start condition. When the RIIC detects the start condition, the BBSY flag and the RIICnSR2.START flag are automatically set to 1 and the ST bit is automatically cleared to 0. At this time, if the start condition is detected and the levels for the SDA output and the levels on the SDA line have matched while the ST bit is 1, the RIIC recognizes that issuing of the start condition as requested by the ST bit has been successfully completed, and the RIICnCR2.MST and TRS bits are automatically set to 1, placing the RIIC in master transmit mode. The RIICnSR2.TDRE flag is also automatically set to 1 in response to setting of the TRS bit to 1.

- (3) Check that the RIICnSR2.TDRE flag is 1, and then write the value for transmission (the first byte indicates the slave address and value of the R/W# bit) to RIICnDRT. Once the data for transmission are written to RIICnDRT, the TDRE flag is automatically cleared to 0, the data are transferred from RIICnDRT to RIICnDRS, and the TDRE flag is again set to 1. Once the byte containing the slave address and R/W# bit has been transmitted, the value of the RIICnCR2.TRS bit is automatically updated to select transmit or receive mode in accord with the value of the transmitted R/W# bit. If the value of the R/W# bit was 1, the RIICnCR2.TRS bit is cleared to 0 on the rising edge of the ninth cycle of SCL (the clock signal), placing the RIIC in master receive mode. At this time, the TDRE flag is automatically cleared to 0 and the RIICnSR2.RDRF flag is automatically set to 1.

Since the RIICnSR2.NACKF flag being 1 at this time indicates that no slave device recognized the address or there was an error in communications, write 1 to the RIICnCR2.SP bit to issue a stop condition.

For master reception from a device with a 10-bit address, start by using master transmission to issue the 10-bit address, and then issue a restart condition. After that, transmitting 1111 0B, the two higher-order bits of the slave address, and the R bit places the RIIC in master receive mode.

- (4) Dummy read RIICnDRR after confirming that the RIICnSR2.RDRF flag is 1; this makes the RIIC start output of the SCL (clock) signal and start data reception.

- (5) After 1 byte of data has been received, the RIICnSR2.RDRF flag is set to 1 on the rising edge of the eighth or ninth cycle of SCL clock (the clock signal) as selected by the RIICnMR3.RDRFS bit. Reading out RIICnDRR at this time will produce the received data, and the RDRF flag is

automatically cleared to 0 at the same time. Furthermore, the value of the acknowledgement field received during the ninth cycle of SCL clock is returned as the value set in the RIICnMR3.ACKBT bit. Furthermore, if the next byte to be received is the next to last byte, set the RIICnMR3.WAIT bit to 1 (for wait insertion) before reading the RIICnDRR (containing the second byte from last). As well as enabling NACK output even in the case of delays in processing to set the RIICnMR3.ACKBT bit to 1 (NACK) in step (6), due to other interrupts, etc., this fixes the SCL line to the low level on the rising edge of the ninth clock cycle in reception of the last byte, so the state is such that issuing a stop condition is possible.

- (6) When the RIICnMR3.RDRFS bit is 0 and the slave device must be notified that it is to end transfer for data reception after transfer of the next (final) byte, set the RIICnMR3.ACKBT bit to 1 (NACK).

- (7) After reading out the byte before last from the RIICnDRR register, if the value of the RIICnSR2.RDRF flag is confirmed to be 1, write 1 to the RIICnCR2.SP bit (stop condition issuance request) and then read the last byte from RIICnDRR. When RIICnDRR is read, the RIIC is released from the wait state and issues the stop condition after low-level output in the ninth clock cycle is completed or the SCL line is released from the low-hold state.

- (8) Upon detecting the stop condition, the RIIC automatically clears the RIICnCR2.MST and TRS bits to 00B and enters slave receive mode. Furthermore, detection of the stop condition leads to setting of the RIICnSR2.STOP flag to 1.

- (9) After checking that the RIICnSR2.STOP flag is 1, clear the RIICnSR2.NACKF and STOP flags to 0 for the next transfer operation.

**==> picture [360 x 587] intentionally omitted <==**

**----- Start of picture text -----**<br>
Master reception<br>Initial settings [1] Initial settings<br>No<br>RIICnCR2.BBSY = 0?<br>[2] Check I [2] C bus occupation and issue a start<br>Yes condition.<br>RIICnCR2.ST = 1<br>No<br>RIICnSR2.TDRE = 1?<br>Yes<br>Write data to RIICnDRT<br>[3] Transmit slave address and R and check ACK.<br>No<br>RIICnSR2.RDRF = 1?<br>Yes<br>No<br>RIICnSR2.NACKF = 0?<br>Yes<br>Perform dummy read of  [4] Perform dummy read.<br>RIICnDRR<br>No<br>RIICnSR2.RDRF = 1?<br>Yes<br>Yes<br>Next data = Final byte - 1?<br>No [5] Read received data and prepare for receiving<br>Yes final data.<br>Next data = Final byte - 2?<br>No<br>RIICnMR3.WAIT = 1<br>Read RIICnDRR<br>Set RIICnMR3.ACKBT<br>[6] Set the acknowledgement and read<br>data of (final byte – 1 byte).<br>Read RIICnDRR<br>No<br>RIICnSR2.RDRF = 1?<br>Yes<br>RIICnSR2.STOP = 0 RIICnR2.STOP = 0<br>[7] Read final data and issue a stop<br>condition.<br>RIICnCR2.SP = 1 RIICnCR2.SP = 1<br>Read RIICnDRR Perform dummy read of<br>RIICnDRR<br>RIICnMR3.WAIT = 0<br>No<br>RIICnR2.STOP = 1? [8] Check stop condition issuance<br>Yes<br>RIICnSR2.NACKF = 0<br>[9] Processing for the next transfer operation<br>RIICnR2.STOP = 0<br>End of master reception<br>**----- End of picture text -----**<br>

**Figure 18.10 Example Flowchart for the Master Reception of 3 or More Bytes (7-Bit Address Format)**

**==> picture [389 x 227] intentionally omitted <==**

**----- Start of picture text -----**<br>
Automatic low hold (to prevent wrong transmission) Master transmit mode Master receive mode<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4<br>SCLn<br>SDAn b7  b6  b5     b4     b3     b2     b1     b0 ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK b7  b6  b5     b4<br>7-bit slave address R DATA 1 DATA 2<br>BBSY<br>MST<br>TRS Transmit data (7-bit address + R)<br>TDRE<br>TEND Receive data (7-bit address + R) Receive data (DATA 1)<br>RDRF<br>RIICnDRT 7-bit address + R<br>RIICnDRS 7-bit address + R DATA 1 DATA 2<br>RIICnDRR XXXX (Initial value/last data for reception) XXXX (Initial value/last data for reception) DATA 1<br>ACKBT 0 (ACK)<br>ACKBR X (ACK/NACK) 0 (ACK) 0 (ACK)<br>START<br>ST<br>Write 1  Write data to RIICnDRT  Read RIInDRR Read RIInDRR<br>to ST  (7-bit address + R) (Dummy read) (DATA 1)<br>[2] [3] [4] [5]<br>**----- End of picture text -----**<br>

**Figure 18.11 Master Receive Operation Timing (1) (7-Bit Address Format, when RDRFS = 0)**

**==> picture [400 x 232] intentionally omitted <==**

**----- Start of picture text -----**<br>
Automatic low hold (to prevent wrong transmission) Master transmit mode Master receive mode<br>S 1  to 7  8 9 1  to 8  9 Sr 1 2 3 4 5 6 7 8 9 1 2 3 4<br>SCLn<br>SDAn b7 b1 b0 ACK b7     b0 ACK b7  b6  b5  b4  b3 b2     b1     b0 ACK b7  b6  b5     b4<br>Upper 10 bits W Lower 10 bits Upper 10-bit addresses (11110b + 2 bits) R DATA 1<br>BBSY<br>MST<br>TRS Transmit data (upper 10 bits + W)Transmit data (lower 10 bits) Transmit data (upper 10 bits + R)<br>TDRE<br>TEND Transmit data (upper 10 bits + R)<br>RDRF<br>RIInDRT Upper 10 bits + W Lower 10 bits Upper 10 bits + R<br>RIInDRS Upper 10 bits + W Lower 10 bits Upper 10 bits + R DATA 1<br>RIInDRR XXXX (Initial value/last data for reception) XXXX (Initial value/last data for reception)<br>ACKBT 0 (ACK)<br>ACKBR X (ACK/NACK) 0 (ACK) 0 (ACK) 0 (ACK)<br>START<br>ST<br>RS<br>Write 1 to ST (11110b + 2 bits + W)Write data to RIInDRT (lower 8 bits)Write data to RIICnDRT START to 0Clear  Write 1 to RS Write data to RIInDRT (11110b + 2 bits + R) Read RIInDRR(Dummy read)<br>[2] [3] [4]<br>**----- End of picture text -----**<br>

**Figure 18.12 Master Receive Operation Timing (2) (10-Bit Address Format, when RDRFS = 0)**

**==> picture [398 x 221] intentionally omitted <==**

**----- Start of picture text -----**<br>
Automatic low hold (WAIT) Automatic low hold (WAIT)<br>7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 P<br>SCLn<br>SDAn b1     b0     ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK b7  b6  b5     b4     b3     b2     b1     b0     NACK<br>DATA n-2 DATA n-1 DATA n<br>BBSY<br>MST<br>TRS<br>TDRE<br>TEND Receive data (DATA n-2) Receive data (DATA n-1) Receive data (DATA n)<br>RDRF<br>RIICnDRT XXXX (last data for transmission [7-bit addresses + R/Upper 10 bits + R])<br>RIICnDRS DATA n-2 DATA n-1 DATA n<br>RIICnDRR DATA n-3 DATA n-2 DATA n-1 DATA n<br>ACKBT 0 (ACK) 1 (NACK) 0<br>ACKBR 0 (ACK) 0 (ACK) 0 (ACK) 1 (NACK)<br>STOP<br>SP<br>WAIT<br>Write 1  Read RIICnDRR  Write 1  Read RIICnDRR  Write 1  Read RIInDRR Clear WAIT  Clear STOP<br>to WAIT (DATA n-2) to ACKBT (DATA n-1) to SP (last data for reception [DATA n]) to 0 to 0<br>[5] [6] [7] [9]<br>**----- End of picture text -----**<br>

**Figure 18.13 Master Receive Operation Timing (3) (when RDRFS = 0)**

|||Master reception|Master reception|||||[1] Initial settings|
|---|---|---|---|---|---|---|---|---|
|||Initial settings|||||||
|No||RIICnCR2.BBSY = 0?||||||[2] Check I2C bus occupation and issue|
|||||||||a start condition.|
||||Yes||||||
|||RIICnCR2.ST = 1|||||||
||||||||||
|No||RIICnSR2.TDRE = 1?<br>Yes|||||||
|||Write data to RIICnDRT|||||||
|||||||||[3] Transmit slave address and R and check|
|No||RIICnSR2.NACKF = 0?<br>RIICnSR2.RDRF = 1?<br>Yes|||No|||ACK.|
||||Yes||||||
|||RIICnMR3.WAIT = 1||||||[4] Wait settings|
|||Next data =|Final byte?|Yes|||||
|||Perform dummy read of|||||||
|||RIICnDRR||||||[5] NACK settings (perform dummy read for|
|No||Yes<br>RIICnSR2.RDRF = 1?||||||2-byte reception)|
|||Specify RIICnMR3.ACKBT|||||||
|||Read RIICnDRR||||||[6] Read received data (perform dummy<br>read for 1-byte reception)|
|No||RIICnSR2.RDRF = 1?<br>Yes|||||||
|||RIICnSR2.STOP = 0||||RIICnSR2.STOP = 0|||
|||||||||[7] Read final data and issue a|
|||RIICnCR2.SP = 1||||RIICnCR2.SP = 1||stop condition.|
||||||||||
|||Read RIICnDRR||||Perform dummy read of<br>RIICnDRR|||
||||||||||
|||RIICnMR3.WAIT = 0|||||||
|No||RIICnSR2.STOP = 1?<br>Yes||||||[8] Check stop condition issuance|
|||RIICnSR2.NACKF = 0||||||[9] Processing for the next transfer|
|||RIICnSR2.STOP = 0||||||operation|
||||||||||
|||End of master reception|||||||

**Figure 18.14 Example Flowchart for the Master Reception of 1 or 2 Bytes (7-Bit Address Format)**

## 18.5.5 Slave Transmit Operation

In slave transmit operation, the master device outputs the SCL (clock) signal, the RIIC transmits data as a slave device, and the master device returns acknowledgements.

Figure 18.15 shows an example of usage of slave transmission and Figure 18.16 and Figure 18.17 show the timing of operations in slave transmission.

The following describes the procedure and operations for slave transmission.

- (1) Follow the procedure in Figure 18.5 to make initial settings for the RIIC. This step is not necessary if initialization of the RIIC has already been completed. After initial settings, the RIIC will stay in the standby state until it receives a slave address that it matches.

- (2) After receiving a matching slave address, the RIIC sets one of the corresponding bits RIICnSR1.HOA, GCA, and AASy (y = 0 to 2) to 1 on the rising edge of the ninth cycle of SCL clock (the clock signal) and outputs the value set in the RIICnMR3.ACKBT bit to the acknowledge bit on the ninth cycle of SCL clock. If the value of the R/W# bit that was also received at this time is 1, the RIIC automatically places itself in slave transmit mode by setting both the RIICnCR2.TRS bit and the RIICnSR2.TDRE flag to 1.

- (3) After the RIICnSR2.TEND flag is confirmed to be 1, write the data for transmission to the RIICnDRT register. At this time, if the RIIC receives no acknowledge from the master device (receives an NACK signal) while the RIICnFER.NACKE bit is 1, the RIIC suspends transfer of the next data.

- (4) Wait unit the RIICnSR2.TEND flag is set to 1 while the RIICnSR2.TDRE flag is 1, after the RIICnSR2.NACKF flag is set to 1 or the last byte for transmission is written to the RIICnDRT register. When the RIICnSR2.NACKF flag or the TEND flag is 1, the RIIC drives the SCL line low on the ninth falling edge of SCL clock.

- (5) When the RIICnSR2.NACKF flag or the RIICnSR2.TEND flag is 1, dummy read RIICnDRR to complete the processing. This releases the SCL line.

- (6) Upon detecting the stop condition, the RIIC automatically clears bits RIICnSR1.HOA, GCA, and AASy (y = 0 to 2), flags RIICnSR2.TDRE and TEND, and the RIICnCR2.TRS bit to 0, and enters slave receive mode.

- (7) Clear the RIICnSR2.NACKF and STOP flags to 0.

## CAUTION

Operations for transfer start if the RIICnSR2.NACKF flag is cleared to 0 before RIICnSR2.STOP is set to 1. Be sure to confirm that RIICnSR2.STOP is set to 1 before clearing RIICnSR2.NACKF to 0. In particular, when the NACK receive interrupt (INTRIICNAKI) is in use, take care not to clear the NACKF flag to 0 before the STOP flag is set to 1 during interrupt processing.

**==> picture [382 x 456] intentionally omitted <==**

**----- Start of picture text -----**<br>
Slave transmission<br>Initial settings [1] Initial settings<br>No<br>RIICnSR2.NACKF = 0?<br>Yes<br>No<br>RIICnSR2.TDRE = 1?<br>Yes<br>Write data to RIICnDRT [2], [3], [4] Check ACK and set transmit data<br>    (Checking of ACK not necessary immediately after<br>     address is received)<br>No<br>All data transmitted?<br>Yes<br>No<br>RIICnSR2.TEND = 1?<br>Yes<br>Read RIICnDRR [5] Dummy read to release the SCL<br>No<br>RIICnSR2.STOP = 1? [6] Check stop condition issuance<br>Yes<br>RIICnSR2.NACKF = 0<br>[7] Processing for the next transfer operation.<br>RIICnSR2.STOP = 0<br>End of slave transmission<br>**----- End of picture text -----**<br>

**Figure 18.15 Example of Slave Transmission Flowchart**

**==> picture [412 x 550] intentionally omitted <==**

**----- Start of picture text -----**<br>
Slave receive mode Slave transmit mode Automatic low hold (to prevent wrong transmission)<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4<br>SCLn<br>SDAn b7  b6  b5     b4     b3     b2     b1     b0 ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK b7  b6  b5     b4<br>7-bit slave address R DATA 1 DATA 2<br>BBSY<br>Transmit data (DATA 1)<br>MST<br>TRS Transmit data (DATA 2)<br>TDRE<br>TEND<br>RDRF<br>AASn<br>RIICnDRT XXXX (Initial value/last data for transmission) DATA 1 DATA 2 DATA 3<br>RIICnDRS 7-bit address + R DATA 1 DATA 2<br>RIICnDRR XXXX (Initial value/last data for reception)<br>ACKBT 0 (ACK)<br>ACKBR X (ACK/NACK) 0 (ACK) 0 (ACK)<br>START<br>NACKF<br> Write data to  Write data to  Write data to<br>RIICnDRT RIICnDRT RIICnDRT<br>(DATA 1) (DATA 2) (DATA 3)<br>[3] [3] [3]<br>Figure 18.16 Slave Transmit Operation Timing (1) (7-Bit Address Format)<br>7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 P<br>SCLn<br>SDAn b1     b0     ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK b7  b6  b5     b4     b3     b2     b1     b0     NACK<br>DATA n-2 DATA n-1 DATA n<br>BBSY<br>MST<br>TRS Transmit data (DATA n-1) Transmit data (DATA n)<br>TDRE<br>TEND<br>RDRF<br>AASn<br>RIICnDRT DATA n-1 DATA n<br>RIICnDRS DATA n-2 DATA n-1 DATA n<br>RIICnDRR XXXX (Initial value/last data for reception)<br>ACKBT 0 (ACK)<br>ACKBR 0 (ACK) 0 (ACK) 1 (NACK)<br>STOP<br>NACKF<br>Write data to RIICnDRT Dummy read RIICnDRR Clear NACKF  Clear STOP<br>(Last data for transmission [DATA n]) (SCLn line is released) to 0 to 0<br>[4] [5] [7]<br>**----- End of picture text -----**<br>

**Figure 18.17 Slave Transmit Operation Timing (2)**

## 18.5.6 Slave Receive Operation

In slave receive operation, the master device outputs the SCL clock and transmit data, and the RIIC returns acknowledgements as a slave device.

Figure 18.18 shows an example of usage of slave reception and Figure 18.19 and Figure 18.20 show the timing of operations in slave reception.

The following describes the procedure and operations for slave reception.

- (1) Follow the procedure in Figure 18.5 to make initial settings for the RIIC. This step is not necessary if initialization of the RIIC has already been completed. After initial settings, the RIIC will stay in the standby state until it receives a slave address that it matches.

- (2) After receiving a matching slave address, the RIIC sets one of the corresponding bits RIICnSR1.HOA, GCA, and AASy (y = 0 to 2) to 1 on the rising edge of the ninth cycle of SCL clock (the clock signal) and outputs the value set in the RIICnMR3.ACKBT bit to the acknowledge bit on the ninth cycle of SCL clock. If the value of the R/W# bit that was also received at this time is 0, the RIIC continues to place itself in slave receive mode and sets the RIICnSR2.RDRF flag to 1.

- (3) After the RIICnSR2.STOP flag is confirmed to be 0 and the RIICnSR2.RDRF flag to be 1, dummy read RIICnDRR (the dummy value consists of the slave address and R/W# bit when the 7-bit address format is selected, or the lower eight bits when the 10-bit address format is selected).

- (4) When RIICnDRR is read, the RIIC automatically clears the RIICnSR2.RDRF flag to 0. If reading of RIICnDRR is delayed and a next byte is received while the RDRF flag is still set to 1, the RIIC holds the SCL line low from one SCL cycle before the timing with which RDRF should be set. In this case, reading RIICnDRR releases the SCL line from being held at the low level. When the RIICnSR2.STOP flag is 1 and the RIICnSR2.RDRF flag is also 1, read RIICnDRR until all the data is completely received.

- (5) Upon detecting the stop condition, the RIIC automatically clears bits RIICnSR1.HOA, GCA, and AASy (y = 0 to 2) to 0.

- (6) After checking that the RIICnSR2.STOP flag is 1, clear the RIICnSR2.STOP flag to 0 for the next transfer operation.

**==> picture [390 x 280] intentionally omitted <==**

**----- Start of picture text -----**<br>
Slave reception<br>Initial settings [1] Initial settings<br>No<br>RIICnSR2.STOP = 0?<br>Yes<br>No No<br>RIICnSR2.RDRF = 1? RIICnS R2.RDRF = 1?<br>[2], [3], [4] Read receive data<br>Yes Yes (Dummy read first)<br>Read RIICnDRRYes Read RIICnDRR (last data)<br>No<br>All data received?<br>Yes<br>No<br>RIICnSR2.STOP = 1? [5] Check stop condition detection<br>Yes<br>RIICnSR2.STOP = 0 [6] Processing for the next transfer<br>End of slave reception<br>**----- End of picture text -----**<br>

**Figure 18.18 Example of Slave Reception Flowchart**

**==> picture [394 x 236] intentionally omitted <==**

**----- Start of picture text -----**<br>
Automatic low hold<br>(to prevent failure to receive data)<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4<br>SCLn<br>SDAn b7  b6  b5     b4     b3     b2     b1     b0 ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK b7  b6  b5     b4<br>7-bit slave address W DATA 1 DATA 2<br>BBSY<br>MST<br>TRS<br>TDRE<br>TEND Receive data (7-bit address + W) Receive data (DATA 1)<br>RDRF<br>AASn<br>RIICnDRT XXXX (Initial value/last data for transmission)<br>RIICnDRS 7-bit address + W DATA 1 DATA 2<br>RIICnDRR XXXX (Initial value/last data for reception) 7-bit address + W DATA 1<br>ACKBT 0 (ACK)<br>ACKBR X (ACK/NACK) 0 (ACK) 0 (ACK)<br>START<br>NACKF<br>[7-bit address + W])Read RIICnDRR (Dummy read  Read RIICnDRR (DATA 1)<br>[3] [3][4]<br>**----- End of picture text -----**<br>

**Figure 18.19 Slave Receive Operation Timing (1) (7-Bit Address Format, when RDRFS = 0)**

**==> picture [398 x 225] intentionally omitted <==**

**----- Start of picture text -----**<br>
7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 P<br>SCLn<br>SDAn b1     b0     ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK b7  b6  b5     b4     b3     b2     b1     b0     ACK<br>DATA n-2 DATA n-1 DATA n<br>BBSY<br>MST<br>TRS<br>TDRE<br>TEND Receive data (DATA n-2) Receive data (DATA n-1) Receive data (DATA n)<br>RDRF<br>AASn<br>RIICnDRT XXXX (Initial value/last data for transmission)<br>RIICnDRS DATA n-2 DATA n-1 DATA n<br>RIICnDRR DATA n-3 DATA n-2 DATA n-1 DATA n<br>ACKBT 0(ACK)<br>ACKBR 0 (ACK) 0 (ACK) 0 (ACK)<br>STOP<br>NACKF<br>Read RIICnDRR  Read RIICnDRR  Read RIICnDRR  Clear<br>(DATA n-2) (DATA n-1) (DATA n) STOP to 0<br>[3] [4] [3] [4] [3] [4] [6]<br>**----- End of picture text -----**<br>

**Figure 18.20 Slave Receive Operation Timing (2) (when RDRFS = 0)**

## 18.6 SCL Synchronization Circuit

In generation of the SCL (clock) signal, the RIIC starts counting out the value for width at high level specified in RIICnBRH when it detects a rising edge on the SCL line and drives the SCL line low once counting of the width at high level is complete. When the RIIC detects the falling edge of the SCL line, it starts counting out the width at low level period specified in RIICnBRL, and then stops driving the SCL line (releases the line) once counting of the width at low level is complete. The SCL (clock) signal is thus generated.

If multiple master devices are connected to the I[2] C bus, a collision of SCL signals may arise due to contention with another master device. In such cases, the master devices have to synchronize their SCL signals. Since this synchronization of SCL signals must be bit by bit, the RIIC is equipped with a facility (the SCL synchronization circuit) to obtain bit-by-bit synchronization of the SCL clock signals by monitoring the SCL line during communication.

When the RIIC has detected a rising edge on the SCL line and thus started counting out the width at high level specified in RIICnBRH, and the level on the SCL line falls because an SCL signal is being generated by another master device, the RIIC stops counting when it detects the falling edge, drives the level on the SCL line low, and starts counting out the width at low level specified in RIICnBRL. When the RIIC finishes counting out the width at low level, it stops driving the SCL line to the low level (i.e. releases the line). At this time, if the width at low level of the SCL clock signal from the other master device is longer than the width at low level set in the RIIC, the width at low level of the SCL signal will be extended. Once the width at low level for the other master device has ended, the SCL signal rises because the SCL line has been released. When the RIIC finishes outputting the low-level period of the SCL clock, the SCL line is released and the SCL clock rises. That is, in cases of contention of SCL signals from more than one master, the width at high level of the SCL signal is synchronized with that of the clock having the narrower width, and the width at low level of the SCL signal is synchronized with that of the clock having the broader width. However, such synchronization of the SCL signal is only enabled when the RIICnFER.SCLE bit is set to 1.

**==> picture [394 x 228] intentionally omitted <==**

**----- Start of picture text -----**<br>
[SCL clock generation]<br>Compare match Rising of SCL detected<br>(Counter clear, low-drive start) (High-level period count start)<br>RIICnBRH RIICnBRH RIICnBRH<br>SCLn<br>RIICnBRL RIICnBRL<br>Falling of SCL detected Compare match<br>(Low-level period count start) (Counter clear, SCLn line released)<br>[SCL synchronization]<br>Counter clear Counter clear<br>RIICnBRH other master deviceLow-level output of  RIICnBRH Low-level output of other master device RIICnBRH<br>SCLn<br>RIICnBRL RIICnBRL RIICnBRL<br>RIICnBRH: I [2] C bus bit rate high-level register (SCL clock high-level period counter)<br>RIICnBRL:  I [2] C bus bit rate low-level register (SCL clock low-level period counter)<br>**----- End of picture text -----**<br>

**Figure 18.21 Generation and Synchronization of the SCL Signal from the RIIC**

## 18.7 Facility for Delaying SDA Output

The RIIC module incorporates a facility for delaying output on the SDA line. The delay can be applied to all output (issuing of the start, restart, and stop conditions, data, and the ACK and NACK signals) on the SDA line.

With the SDA output delay facility, SDA output is delayed from detection of a falling edge of the SCL signal to ensure that the SDA signal is output within the interval over which the SCL (clock) signal is at the low level. Doing this leads to usage with the aim of preventing erroneous operation of communications devices, with the aim of satisfying the 300-ns (min.) data-hold time requirement of the SMBus specification.

The output delay facility is enabled by setting the RIICnMR2.SDDL[2:0] bits to any value other than 000B, and disabled by setting the same bits to 000B.

While the SDA output delay facility is enabled (i.e. while the SDDL[2:0] bits in IMCR2 are set to any value other than 000B), the RIICnMR2.DLCS bit selects the clock source for counting by the SDA output delay counter as the internal base clock (IIC  ) for the RIIC module or as a clock signal derived by dividing the frequency of the internal base clock by two (IIC  /2). The counter counts the number of cycles set in the SDDL[2:0] bits in IMCR2. After counting of the set number of cycles of delay is completed, the RIIC module places the required output (start, restart, or stop condition, data, or an ACK or NACK signal) on the SDA line.

**==> picture [401 x 274] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0sampling error (1 P0 (max))<br>Digital noise filter delay time (NFE, NF[1:0] settings = 0.5 P0(min), 1 IIC to 4 IIC (max))<br>[Transmit mode]<br>SDA output delay time (DLCS,SDDL[2:0] settings = 0 (min) to 14 IIC (max))<br>SDA output release timing<br>S 8 9<br>SCLn<br>SDAn b7 to b1 b0 ACK/NACK<br>SDA output delay<br>[Receive mode]<br>SDA output release timing<br>1 to 7 8 9 P<br>SCLn<br>SDAn b7 to b1 b0 ACK/NACK<br>SDA output delay<br>[When a condition is issued]<br>RIICn RIICn RIICn RIICn RIICn RIICn RIICn RIICn RIICn<br>BRH BRL BRH BRL BRL BRH BRL BRH BRL<br>SCLn S 1 2 to 8 9 Sr 1 to 9 P<br>SDAn b7 b6 to b0 ACK/NACK<br>* [1] * [1] * [1]<br>BBSY<br>ST<br>SDA output delay<br>Note 1. The output is delayed by the number of cycles set by the SDDL[2:0] bits when a start<br>(S), restart (Sr), or stop (P) condition is issued.<br>**----- End of picture text -----**<br>

**Figure 18.22 SDA Output Delay Facility**

## 18.8 Digital Noise-Filter Circuits

Figure 18.23 is a block diagram of the digital noise-filter circuit. When the NFE bit in the RIICnFER register is set to 1, input to the RIICnSCL and RIICnSDA pins are conveyed to the internal circuitry through digital noise-filter circuits.

The on-chip digital noise-filter circuit of the RIIC consists of four flip-flop circuit stages connected in series and a match-detection circuit.

The number of effective stages in the digital noise filter is selected by the RIICnMR3.NF[1:0] bits. The selected number of effective stages determines the noise-filtering capability as a period from one to four IIC  cycles.

The input signal to the RIICnSCL pin (or RIICnSDA pin) is sampled on falling edges of the IIC  signal. When the input signal level matches the output level of the number of effective flip-flop circuit stages as selected by the RIICnMR3.NF[1:0] bits, the signal level is conveyed to the subsequent stage. If the signal levels do not match, the previous value is retained.

Note that if the ratio of the frequencies for P0  and IIC  is small (when the RIICnMR1.CKS[2:0] bits are set to “000B”), even necessary signals might be eliminated due to the characteristics of the digital noise filter.

**==> picture [397 x 190] intentionally omitted <==**

**----- Start of picture text -----**<br>
Mismatch RIICnSCL/<br>Match D Q RIICnSDA<br>internal signal<br>CLK<br>P0<br>Four-stage digital noise filter<br>RIICnSCL/<br>RIICnSDA D Q D Q D Q D Q D Q<br>input signal<br>CLK CLK CLK CLK CLK<br>IIC NF[1:0] NFE<br>NFE: Digital noise filter circuit enable bit<br>NF[1:0]: Digital noise filter stage selection bits<br>Comparator<br>**----- End of picture text -----**<br>

**Figure 18.23 Block Diagram of Digital Noise Filter Circuit**

## 18.9 Address Match Detection

The RIIC can set three unique slave addresses in addition to the general call address and host address, and also can set 7-bit or 10-bit slave addresses.

## 18.9.1 Slave-Address Match Detection

The RIIC can set three unique slave addresses, and has a slave address detection function for each unique slave address. When the RIICnSER.SARy bit (y = 0 to 2) is set to 1, the slave addresses set in RIICnSARy (y = 0 to 2) can be detected.

When the RIIC detects a match of the set slave address, the corresponding RIICnSR1.AASy flag (y = 0 to 2) is set to 1 at the rising edge of the ninth SCL clock cycle, and the RIICnSR2.RDRF flag or the RIICnSR2.TDRE flag is set to 1 by the following R/W# bit. This causes a receive data full interrupt (INTRIICRI) or transmit data empty interrupt (INTRIICTI) to be generated. The AASy flag is used to identify which slave address has been specified.

Figure 18.24 to Figure 18.26 show the AASy flag set timing in three cases.

**==> picture [392 x 252] intentionally omitted <==**

**----- Start of picture text -----**<br>
[7-bit address format: Slave reception]<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn 7-bit slave address W ACK Data (DATA 1) ACK Data (DATA 2)<br>BBSY<br>Address match<br>AASy<br>TRS Receive data (7-bit address) Receive data (DATA 1)<br>TDRE<br>RDRF<br>Read RIICnDRR Read RIICnDRR<br>(Dummy read [7-bit address]) (DATA 1)<br>[7-bit address format: Slave transmission]<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn 7-bit slave address R ACK Data (DATA 1) ACK Data (DATA 2)<br>BBSY Address match<br>AASy Transmit data (DATA 1) Transmit data (DATA 2)<br>TRS<br>TDRE<br>RDRF<br>Write data to RIICnDRT Write data to RIICnDRT Write data to RIICnDRT<br>(DATA 1) (DATA 2) (DATA 3)<br>**----- End of picture text -----**<br>

**Figure 18.24 AASy Flag Set Timing with 7-Bit Address Format Selected**

**==> picture [391 x 255] intentionally omitted <==**

**----- Start of picture text -----**<br>
[10-bit address format: Slave reception]<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn 1 1 1 1 0 Upper 2 bits W ACK 10-bit slave address (lower 8 bits) ACK Data<br>BBSY<br>Address match<br>AASy<br>TRS Receive data (lower addresses)<br>TDRE<br>RDRF<br>Read RIICnDRR<br>(Dummy read [lower addresses])<br>[10-bit address format: Slave transmission]<br>S 1 2 3 4 5 6 7 8 9 1  to 8  9 Sr 1 2 3 4 5 6 7 8 9<br>SCLn<br>SDAn 1 1 1 1 0 Upper 2 bits W ACK Lower 8 bits ACK 1 1 1 1 0 Upper 2 bits R ACK<br>BBSY<br>Address match<br>AASy<br>TRS Receive data (lower addresses)<br>TDRE<br>RDRF<br>Read RIICnDRR<br>(Dummy read [lower addresses])<br>**----- End of picture text -----**<br>

**Figure 18.25 AASy Flag Set Timing with 10-Bit Address Format Selected**

**==> picture [402 x 301] intentionally omitted <==**

**----- Start of picture text -----**<br>
[In the case of RIICnSAR0: 7-bit address, RIICnSAR1: 7-bit address, RIICnSAR2: 10-bit address (1)]<br>S 1 2 3 4 5 6 7 8 9 1  to 8  9 Sr 1 2 3 4 5 6 7 8 9<br>SCLn<br>SDAn 7-bit slave address (RIICnSAR0) R/W ACK DATA ACK 7-bit slave address (RIICnSAR1) R/W ACK<br>BBSY<br>Address<br>AAS0 Address match mismatch<br>AAS1 Address match<br>AAS2<br>[In the case of RIICnSAR0: 7-bit address, RIICnSAR1: 7-bit address, RIICnSAR2: 10-bit address (2)]<br>S 1 2 3 4 5 6 7 8 9 1  to 8  9 Sr 1 2 3 4 5 6 7 8 9<br>SCLn<br>SDAn 7-bit slave address ((ICSAR1) R/W ACK DATA ACK 1 1 1 1 0 Upper 2 bits  W ACK<br>BBSY<br>AAS0<br>AAS1 Address match Address mismatch<br>AAS2<br>[In the case of RIICnSAR0: 7-bit address, RIICnSAR1: 7-bit address, RIICnSAR2: 10-bit address (3)]<br>S 1 2 3 4 5 6 7 8 9 1  to 8  9 Sr 1 2 3 4 5 6 7 8 9<br>SCLn<br>SDAn 1 1 1 1 0 Upper 2 bits  W ACK Lower 8 bits ACK 7-bit slave address (RIICnSAR0) R/W ACK<br>BBSY<br>Address<br>AAS0 match<br>AAS1<br>AAS2 Address match Address mismatch<br>**----- End of picture text -----**<br>

**Figure 18.26 AASy Flag Set/Clear Timing with 7-Bit/10-Bit Address Formats Mixed**

## 18.9.2 Detection of the General Call Address

The RIIC has a facility for detecting the general call address (0000 000B + 0 [W]). This is enabled by setting the RIICnSER.GCE bit to 1.

If the address received after a start or restart condition is issued is 0000 000B + 1[R] (start byte), the RIIC recognizes this as the address of a slave device with an “all-zero” address but not as the general call address.

When the RIIC detects the general call address, both the RIICnSR1.GCA flag and the RIICnSR2.RDRF flag are set to 1 on the rising edge of the ninth cycle of SCL clock. This leads to the generation of a receive data full interrupt (INTRIICRI). The value of the GCA flag can be confirmed to recognize that the general call address has been transmitted.

Operation after detection of the general call address is the same as normal slave receive operation.

**==> picture [396 x 137] intentionally omitted <==**

**----- Start of picture text -----**<br>
 [General call address reception]<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn 0 0 0 0 0 0 0 W ACK Data (DATA 1) ACK Data (DATA 2)<br>BBSY<br>AAS0<br>AAS1 Receive data (7-bit address) Receive data (DATA 1)<br>AAS2<br>GCA General call address match (0000 000b + W)<br>RDRF<br>Read RIICnDRR Read RIICnDRR<br>(Dummy read [7-bit address]) (DATA 1)<br>**----- End of picture text -----**<br>

**Figure 18.27 Timing of GCA Flag Setting during Reception of General Call Address**

## 18.9.3 Device-ID Address Detection

The RIIC module has a facility for detecting device-ID addresses conformant with the I[2] C bus specification (Rev. 03). When the RIIC receives 1111 100B as the first byte after a start condition or restart condition was issued with the RIICnSER.DIDE bit set to 1, the RIIC recognizes the address as a device ID, sets the RIICnSR1.DID flag to 1 on the rising edge of the ninth SCL clock cycle when the following R/W# bit is 0, and then compares the second and subsequent bytes with its own slave address. If the address matches the value in the slave address register, the RIIC sets the corresponding RIICnSR1.AASy flag (y = 0 to 2) to 1.

After that, when the first byte received after a start or restart condition is issued matches the device ID address (1111 100B) again and the following R/W# bit is 1, the RIIC does not compare the second and subsequent bytes and sets the RIICnSR2.TDRE flag to 1.

In the device-ID address detection function, the RIIC clears the DID flag to 0 if a match with the RIIC’s own slave address is not obtained or a match with the device ID address is not obtained after a match with the RIIC’s own slave address and the detection of a restart condition. If the first byte after detection of a start or restart condition matches the device ID address (1111 100B) and the R/W# bit is 0, the RIIC sets the DID flag to 1 and compares the second and subsequent bytes with the RIIC’s slave address. If the R/W# bit is 1, the DID flag holds the previous value and the RIIC does not compare the second and subsequent bytes. Therefore, the reception of a device-ID address can be checked by reading the DID flag after confirming that TDRE = 1.

Furthermore, prepare the device-ID fields (three bytes: 12 bits indicating the manufacturer + 9 bits identifying the part + 3 bits indicating the revision) that must be sent to the host after reception of a continuous device-ID field as normal data for transmission. For details, see I[2] C Bus Standard from NXP Semiconductors.

**==> picture [400 x 357] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Device-ID reception]<br>S 1 2 3 4 5 6 7 8 9 1  to 7 8 9 Sr 1 2 3 4 5 6 7 8 9<br>SCL<br>SDA 1  1  1  1  1  0 0 W ACK Address R/W ACK 1 1  1  1  1  0 0 R ACK<br>BBSY<br>Slave address match<br>AASy Device-ID match (1111 100b + R)<br>DID Device-ID match (1111 100b + W)<br>TRS Receive data (7-bit address/lower 10 bits)<br>TDRE<br>RDRF<br>Read RIICnDRR<br>(Dummy read [7-bit address/lower 10 bits])<br>[When address received after a restart condition is detected does not match the Device-ID]<br>S 1 2 3 4 5 6 7 8 9 1   to 7 8 9 Sr 1 2 3 4 5 6 7 8 9<br>SCL<br>SDA 1  1  1  1  1  0 0 W ACK Address R/W ACK 7-bit slave address (other station) R/W ACK<br>BBSY Slave address match Slave address mismatch<br>AASy Receive data (7-bit address/lower 10 bits) Device-ID mismatch<br>DID Device-ID match (1111 100b + W)<br>RDRF<br>Read RIICnDRR<br>(Dummy read [7-bit address/lower 10 bits])<br>[When address before the Device-ID + R does not match the slave address]<br>S 1 2 3 4 5 6 7 8 9 1   to 8  9 Sr 1 2 3 4 5 6 7 8 9<br>SCL<br>SDA 1  1  1  1  1  0 0 R NACK NACK 1 1  1  1  1  0 0 R NACK<br>Comparing the second and the following<br>bytes is stopped.<br>BBSY<br>AASy<br>DID Device-ID match (1111 100b + R) Device-ID match (1111 100b + R)<br>TDRE The previous value is retained.<br>RDRF<br>**----- End of picture text -----**<br>

**Figure 18.28 AASy/DID Flag Set/Clear Timing during Reception of Device-ID**

## 18.9.4 Host Address Detection

The RIIC has a function to detect the host address while the SMBus is operating. When the RIICnSER.HOAE bit is set to 1 while the RIICnMR3.SMBS bit is 1, the RIIC can detect the host address (0001 000B) in slave receive mode (RIICnCR2.MST and TRS bits = 00B).

When the RIIC detects the host address, the RIICnSR1.HOA flag is set to 1 at the rising edge of the ninth SCL clock cycle, and at the same time, the RIICnSR2.RDRF flag is set to 1 when the R/W# bit is 0 (Wr bit). This causes a receive data full interrupt (INTRIICRI) to be generated. The HOA flag is used to recognize that the host address was sent from the smart battery or other devices.

If the bit following the host address (0001 000B) is an Rd bit (R/W# bit = 1), the RIIC can also detect the host address. After the host address is detected, the RIIC operates in the same manner as normal slave operation.

**==> picture [396 x 137] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Host address reception]<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn 0 0 0 1 0 0 0 W ACK Data (DATA 1) ACK Data (DATA 2)<br>BBSY<br>AAS0<br>AAS1 Receive data (7-bit address) Receive data (DATA 1)<br>AAS2<br>HOA Host address match (0001 000b)<br>RDRF<br>Read RIICnDRR Read RIICnDRR<br>(Dummy read [7-bit address]) (DATA 1)<br>**----- End of picture text -----**<br>

**Figure 18.29 HOA Flag Set Timing during Reception of Host Address**

## 18.10 Automatically Low-Hold Function for SCL

## 18.10.1 Function to Prevent Wrong Transmission of Transmit Data

If the shift register (RIICnDRS) is empty when data have not been written to the transmit data register (RIICnDRT) with the RIIC in transmission mode (RIICnCR2.TRS bit = 1), the SCL signal is automatically held at the low level over the intervals shown below. This low-hold period is extended until data for transmission have been written, which prevents the unintended transmission of erroneous data.

<Master transmit mode>

- Low-level interval after a start condition or restart condition is issued

- Low-level interval of one clock cycle between the ninth clock cycle of one transfer and the first clock cycle of the next

<Slave transmit mode>

- Low-level interval between the ninth clock cycle of one transfer and the first clock cycle of the next

**==> picture [405 x 254] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Master transmit mode] Automatic low-hold<br>(to prevent wrong<br>Automatic low-hold (to prevent wrong transmission) Automatic low-hold (to prevent wrong transmission) transmission)<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2<br>SCLn<br>SDAn 7-bit slave address W ACK Data (DATA 1) ACK<br>BBSY<br>Transmit data (7-bit address + W) Transmit data (DATA 1) Transmit data (DATA 2)<br>AASy<br>TRS<br>TDRE<br>RDRF<br>Write data to RIICnDRT Write data to RIICnDRT Write data to RIICnDRT<br>(7-bit address + W) (DATA 1) (DATA 2)<br>Automatic low-hold<br>[Slave transmit mode] Automatic low-hold (to prevent wrong transmission) (to prevent wrong<br>transmission)<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3<br>SCLn<br>SDAn 7-bit slave address R ACK Data (DATA 1) ACK<br>BBSY Address match<br>AASy Transmit data (DATA 1) Transmit data (DATA 2)<br>TRS<br>TDRE<br>RDRF<br>Write data to RIICnDRT Write data to RIICnDRT<br>(DATA 1) (DATA 2)<br>**----- End of picture text -----**<br>

**Figure 18.30 Automatic Low-Hold Operation in Transmit Mode**

## 18.10.2 NACK Reception Transfer Suspension Function

The RIIC has a function to suspend transfer operation when NACK is received in transmit mode (RIICnCR2.TRS bit = 1). This function is enabled when the RIICnFER.NACKE bit is set to 1 (transfer suspension enabled). If the next transmit data has already been written (RIICnSR2.TDRE flag = 0) when NACK is received, next data transmission at the falling edge of the ninth SCL clock cycle is automatically suspended. This prevents the SDA line output level from being held low when the MSB of the next transmit data is 0.

If the transfer operation is suspended by this function (RIICnSR2.NACKF flag = 1), transmit operation and receive operation are discontinued. To restore transmit/receive operation, be sure to clear the NACKF flag to 0. In master transmit mode, clear the NACKF flag to 0 after issuing a restart condition or clear the NACKF and STOP flags to 0 after confirming that a stop condition has been issued, and then issue a start condition.

**==> picture [397 x 271] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Master transmit mode]<br>Automatic low-hold (to prevent wrong transmission) Write 1 to SP Bus free time (RIICnBRL)<br>S 1 2 3 4 5 6 7 8 9 P S 1 2 3 4 5 6 7 8 9<br>SCLn<br>SDAn 7-bit slave address W NACK 7-bit slave address W ACK<br>Transfer suspended<br>BBSYAASy Transmit data(7-bit address + W) Transmit data (DATA 1) Transmit data(7-bit address + W) Transmit data (DATA 1)<br>TRS<br>TDRE<br>NACKF<br>Write data to  Write data to RIICnDRT Clear NACKF Write data to  Write data to<br>RIICnDRT (DATA 1) RIICnDRT RIICnDRT<br>(7-bit address + W) (7-bit address + W) (DATA 1)<br>[Slave transmit mode] Automatic low-hold (to prevent wrong transmission) Bus free time<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 P (RIICnBRL)<br>SCLn<br>SDAn 7-bit slave address W ACK Data (DATA 1)<br>Transfer suspended<br>BBSY Address match<br>AASy Transmit data (DATA 1) Transmit data (DATA 2)<br>TRS<br>TDRE<br>NACKF<br>Write data to RIICnDRT Write data to RIICnDRT Clear NACKF<br>(DATA 1) (DATA 2)<br>**----- End of picture text -----**<br>

**Figure 18.31 Suspension of Data Transfer when NACK is Received (NACKE = 1)**

## 18.10.3 Function to Prevent Failure to Receive Data

If response processing is delayed when receive data (RIICnDRR) read is delayed for a period of one transfer frame or more with receive data full (RIICnSR2.RDRF flag = 1) in receive mode (RIICnCR2.TRS = 0), the RIIC holds the SCL line low automatically immediately before the next data is received to prevent failure to receive data.

This function to prevent failure to receive data using the automatic low-hold function is also enabled even if the read processing of the final receive data is delayed and, in the meantime, the RIIC’s own slave address is designated after a stop condition is issued. This function does not disturb other communication because the RIIC does not hold the SCL line low when a mismatch with its own slave address occurs after a stop condition is issued.

Sections in which the SCL line is held low can be selected with a combination of the RIICnMR3.WAIT and RDRFS bits.

- (1) One-Byte Receive Operation and Automatic Low-Hold Function Using the WAIT Bit

When the RIICnMR3.WAIT bit is set to 1, the RIIC performs one-byte receive operation using the WAIT bit function.

Furthermore, when the RIICnMR3.RDRFS bit is 0, the RIIC automatically sends the

RIICnMR3.ACKBT bit value for the acknowledge bit in the period from the falling edge of the eighth SCL clock cycle to the falling edge of the ninth SCL clock cycle, and automatically holds the SCL line low at the falling edge of the ninth SCL clock cycle using the WAIT bit function. This low-hold is released by reading data from RIICnDRR, which enables bytewise receive operation.

The WAIT bit function is enabled for receive frames after a match with the RIIC’s own slave address (including the general call address and host address) is obtained in master receive mode or slave receive mode.

- (2) One-Byte Receive Operation (ACK/NACK Transmission Control) and Automatic Low-Hold Function Using the RDRFS Bit

When the RIICnMR3.RDRFS bit is set to 1, the RIIC performs one-byte receive operation using the RDRFS bit function.

When the RIICnSR2.RDRFS bit is set to 1, the RDRF flag (receive data full) in RIICnSR2 is set to 1 at the rising edge of the eighth SCL clock cycle, and the SCL line is automatically held low at the falling edge of the eighth SCL clock cycle. This lowhold is released by writing a value to the RIICnMR3.ACKBT bit, but cannot be released by reading data from RIICnDRR, which enables receive operation by the ACK/NACK transmission control according to the data received in byte units.

The RDRFS bit function is enabled for receive frames after a match with the RIIC’s own slave address (including the general call address and host address) is obtained in master receive mode or slave receive mode.

**==> picture [396 x 307] intentionally omitted <==**

**----- Start of picture text -----**<br>
[RDRFS = 0, WAIT = 0] Automatic low-hold<br>(to prevent failure to receive data)<br>9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4<br>SCLn<br>SDAn ACK Data ACK Data ACK Data<br>RDRF<br>Read RIICnDRR Read RIICnDRR Read RIICnDRR<br>[RDRFS = 0, WAIT = 1] Automatic low-hold (WAIT) Automatic low-hold (WAIT) Automatic low-<br>hold (WAIT)<br>9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1<br>SCLn<br>SDAn ACK Data ACK Data ACK<br>RDRF<br>Read RIICnDRR Read RIICnDRR Read RIICnDRR<br>Automatic low-hold<br>[RDRFS = 1, WAIT = 0] Automatic low-hold (RDRFS) (to prevent failure to  Automatic low-<br>receive data) hold (RDRFS)<br>2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1<br>SCLn<br>SDAn Data ACK Data ACK<br>RDRF<br>ACKBT<br>Write 0 to ACKBT Read RIICnDRR Read RIICnDRR Write 0 to ACKBT<br>[RDRFS = 1, WAIT = 1] Automatic low-hold  Automatic low-hold (WAIT) Automatic low-hold<br>(RDRFS)  (RDRFS)<br>2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1<br>SCLn<br>SDAn Data ACK Data ACK<br>RDRF<br>ACKBT<br>Write 0 to ACKBT Read RIICnDRR Read RIICnDRR Write 0 to ACKBT<br>**----- End of picture text -----**<br>

**Figure 18.32 Automatic Low-Hold Operation in Receive Mode (Using RDRFS and WAIT Bits)**

## 18.11 Arbitration-Lost Detection Functions

In addition to the normal arbitration-lost detection function defined by the I[2] C bus standard, the RIIC has functions to prevent double-issue of a start condition, to detect arbitration-lost during transmission of NACK, and to detect arbitration-lost in slave transmit mode.

## 18.11.1 Master Arbitration-Lost Detection (MALE Bit)

The RIIC drives the SDA line low to issue a start condition. However, if the SDA line has already been driven low by another master device issuing a start condition, the RIIC regards its own issuing of a start condition as an error and considers this a loss in arbitration, so priority is given to transfer by the other master device. Similarly, if a request to issue a start condition is made by setting the RIICnCR2.ST bit to 1 while the bus is busy (RIICnCR2.BBSY flag = 1), the RIIC regards this as a double-issuing-ofstart-condition error and considers itself to have lost in arbitration, thus preventing a failure of transfer due to issuing of a start condition while transfer is in progress.

When a start condition is issued successfully, if the data for transmission including the address bits (i.e. the internal SDA output level) and the level on the SDA line do not match (the high output as the internal SDA output; i.e. the SDA pin is in the high-impedance state) and the low level is detected on the SDA line, the RIIC loses in arbitration.

After a loss in arbitration of mastership, the RIIC immediately enters slave receive mode. If a slave address (including the general call address) matches its own address at this time, the RIIC continues in slave operation.

A loss in arbitration of mastership is detected when the following conditions are met while the RIICnFER.MALE bit is 1 (master arbitration-lost detection enabled).

[Master arbitration-lost conditions]

- Non-matching of the internal level for output on SDA and the level on the SDA line after a start condition was issued by setting the RIICnCR2.ST bit to 1 while the RIICnCR2.BBSY flag was cleared to 0 (erroneous issuing of a start condition)

- Setting of the RIICnCR2.ST bit to 1 (start condition double-issue error) while the RIICnCR2.BBSY flag is set to 1

- When the transmit data excluding acknowledge (internal SDA output level) does not match the level on the SDA line in master transmit mode (RIICnCR2.MST and TRS bits = 11B)

**==> picture [388 x 324] intentionally omitted <==**

**----- Start of picture text -----**<br>
[When slave addresses conflict] Transmit data mismatch Release SCLn/SDA<br>(Arbitration lost)<br>S 1 2 3 4 5 6<br>SCLn<br>SDAn 1<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn 0 R ACK Data ACK Data<br>BBSY Address match<br>MST Address mismatch<br>TRS<br>AL<br>AASy<br>TDRE<br>Clear AL to 0<br>[When data transmission conflicts after general call address is sent] Transmit data mismatch Release SCLn/SDA<br>(Arbitration-lost)<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn 0 0 0 0 0 0 0 W ACK 1<br>S 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn 0 0 0 0 0 0 0 W ACK 0 ACK Data<br>BBSY<br>MST<br>Receive data<br>TRS<br>AL<br>GCA General call address match (0000 000b + W)<br>RDRF Clear AL to 0<br>Read RIICnDRR<br>**----- End of picture text -----**<br>

**Figure 18.33 Examples of Master Arbitration-Lost Detection (MALE = 1)**

**==> picture [402 x 160] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Bus free (BBSY = 0) start condition issuance (ST = 1) error] [Bus busy (BBSY =1) start condition issuance (ST = 1) error]<br>SDAn mismatch<br>P0 P0 P0<br>SCLn SCLn SCLn<br>SDAn SDAn SDAn<br>S 1 S 1 2 S 1 2 6 7 8 9 1<br>SCLn SCLn SCLn<br>SDAn SDAn SDAn 7-bit/10-bit slave address R ACK<br>ST = 1, BBSY = 1 ST = 1, BBSY = 1 ST = 1,<br>BBSY BBSY BBSY B BSY = 1<br>MST MST MST<br>TRS TRS TRS<br>AASy AASy AASy<br>ST ST ST<br>AL AL AL<br>Write 1 to ST  Write 1 to ST Write 1 to ST<br>**----- End of picture text -----**<br>

**Figure 18.34 Arbitration-Lost when a Start Condition is Issued (MALE = 1)**

## 18.11.2 Function to Detect Loss of Arbitration during NACK Transmission (NALE Bit)

The RIIC has a function to cause arbitration to be lost if the internal SDA output level does not match the level on the SDA line (the high output as the internal SDA output; i.e. the SDA pin is in the highimpedance state) and the low level is detected on the SDA line during transmission of NACK in receive mode. Arbitration is lost due to a conflict of NACK transmission and ACK transmission when two or more master devices receive data from the same slave device simultaneously in a multi-master system. Such conflict occurs when multiple master devices send/receive the same information through a single slave device. Figure 18.35 shows an example of arbitration-lost detection during transmission of NACK.

**==> picture [400 x 174] intentionally omitted <==**

**----- Start of picture text -----**<br>
NACK transmission mismatch<br>[Conflict during transmission of NACK (ACK received)] (Arbitration-lost ) Release SCLn/SDA<br>2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9<br>SCLn<br>SDAn Data ACK Data NACK<br>2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn Data ACK Data ACK Data<br>BBSY<br>MST<br>Receive data Receive data<br>TRS<br>AL<br>RDRFS<br>RDRF<br>ACKBT<br>Write 1 to RDRFS Read RIICnDRR Read RIICnDRR Write 1 to ACKBT  Clear AL to 0<br>**----- End of picture text -----**<br>

**Figure 18.35 Example of Arbitration-Lost Detection during Transmission of NACK (NALE = 1)**

The following explains arbitration-lost detection using an example where two master devices (master A and master B) and a single slave device are connected through the bus. In this example, master A receives two bytes of data from the slave device, and master B receives four bytes of data from the slave device.

If master A and master B access the slave device simultaneously, because the slave address is identical, arbitration is not lost in both master A and master B during access to the slave device. Therefore, both master A and master B recognize that they have obtained the bus mastership and operate as such. Here, master A sends NACK when it has received two final bytes of data from the slave device. Meanwhile, master B sends ACK because it has not received necessary four bytes of data. At this time, the NACK transmission from master A and the ACK transmission from master B conflict. In general, if a conflict like this occurs, master A cannot detect ACK transmitted by master B and issues a stop condition.

Therefore, the issuance of the stop condition conflicts with the SCL clock output of master B, which disturbs communication.

When the RIIC receives ACK during transmission of NACK, it detects a defeat in conflict with other master devices and causes arbitration to be lost.

If arbitration is lost during transmission of NACK, the RIIC enters slave receive mode. This prevents a stop condition from being issued, preventing a communication failure on the bus.

Similarly, in the ARP command processing of SMBus, the function to detect loss of arbitration during transmission of NACK is also available for eliminating the extra clock cycle processing (such as FFH

transmission processing) necessary if the UDID (Unique Device Identifier) of assign address does not match in the Get UDID (general) processing after the Assign address command.

The RIIC detects arbitration-lost during transmission of NACK when the following condition is met with the RIICnFER.NALE bit set to 1 (arbitration-lost detection during NACK transmission enabled).

[Condition for arbitration-lost during NACK transmission]

When the internal SDA output level does not match the SDA line (ACK is received) during transmission of NACK (RIICnMR3.ACKBT bit = 1)

## 18.11.3 Slave Arbitration-Lost Detection (SALE Bit)

The RIIC has a function to cause arbitration to be lost if the data for transmission (i.e. the internal SDA output level) and the level on the SDA line do not match (the high output as the internal SDA output; i.e. the SDA pin is in the highimpedance state) and the low level is detected on the SDA line in slave transmit mode. This arbitration-lost detection function is mainly used when transmitting a UDID (Unique Device Identifier) over an SMBus.

When it loses slave arbitration, the RIIC enters slave receive mode. This function can detect conflicts of data during transmission of UDIDs over an SMBus and eliminates

subsequent redundant processing (processing for the transmission of FFH).

The RIIC detects slave arbitration-lost when the following condition is met with the RIICnFER.SALE bit set to 1 (slave arbitration-lost detection enabled).

[Condition for slave arbitration-lost]

When transmit data excluding acknowledge (internal SDA output level) does not match the SDA line in slave transmit mode (RIICnCR2.MST and TRS bits = 01B)

**==> picture [400 x 154] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Conflict during data transmission] Transmit data mismatch(Arbitration-lost) Release SCLn/SDA<br>2 3 4 5 6 7 8 9 1 2 3 4 5<br>SCLn<br>SDAn Data ACK 1<br>2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6<br>SCLn<br>SDAn Data ACK 0 ACK Data<br>BBSY<br>MST<br>TRS<br>AL<br>TDRE<br>Write data to RIICnDRT Clear AL to 0<br>**----- End of picture text -----**<br>

**Figure 18.36 Example of Slave Arbitration-Lost Detection (SALE = 1)**

## 18.12 Start Condition/Restart Condition/Stop Condition Issuing Function

## 18.12.1 Issuing a Start Condition

The RIIC issues a start condition when the RIICnCR2.ST bit is set to 1.

When the ST bit is set to 1, a start condition issuance request is made and the RIIC issues a start condition when the RIICnCR2.BBSY flag is 0 (bus free). When a start condition is issued normally, the RIIC automatically shifts to the master transmit mode.

A start condition is issued in the following sequence.

[Start condition issuance]

- Drive the SDA line low (high level to low level).

- Ensure the time set in RIICnBRH and the start condition hold time.

- Drive the SCL line low (high level to low level).

- Detect low level of the SCL line and ensure the low-level period of SCL line set in RIICnBRL.

## 18.12.2 Issuing a Restart Condition

The RIIC issues a restart condition when the RIICnCR2.RS bit is set to 1.

When the RS bit is set to 1, a restart condition issuance request is made and the RIIC issues a restart condition when the RIICnCR2.BBSY flag is 1 (bus busy) and the RIICnCR2.MST bit is 1 (master mode).

A restart condition is issued in the following sequence.

[Restart condition issuance]

- Release the SDA line.

- Ensure the low-level period of SCL line set in RIICnBRL.

- Release the SCL line (low level to high level).

- Detect a high level of the SCL line and ensure the time set in RIICnBRL and the restart condition setup time.

- Drive the SDA line low (high level to low level).

- Ensure the time set in RIICnBRH and the restart condition hold time.

- Drive the SCL line low (high level to low level).

- Detect a low level of the SCL line and ensure the low-level period of SCL line set in RIICnBRL.

**==> picture [392 x 147] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Start condition issuing operation] [Restart condition issuing operation]<br>Hold time Setup time Hold time<br>RIICnBRH RIICnBRL RIICnBRH RIICnBRL RIICnCBRL RIICnBRH RIICnBRL<br>SCLn S Issue start  SCLn 9 SrIssue restart<br>SDAn condition SDAn ACK/NACK condition<br>IIC IIC<br>BBSY BBSY<br>MST MST<br>TRS TRS<br>TDRE TDRE<br>START START<br>ST RS<br>Write 1 to ST Accept start condition issuance Write 1 to RS Accept restart condition issuance<br>**----- End of picture text -----**<br>

**Figure 18.37 Start Condition/Restart Condition Issue Timing (ST and RS Bits)**

## 18.12.3 Issuing a Stop Condition

The RIIC issues a stop condition when the RIICnCR2.SP bit is set to 1.

When the SP bit is set to 1, a stop condition issuance request is made and the RIIC issues a stop condition when the RIICnCR2.BBSY flag is 1 (bus busy) and the RIICnCR2.MST bit is 1 (master mode).

A stop condition is issued in the following sequence.

[Stop condition issuance]

- Drive the SDA line low (high level to low level).

- Ensure the low-level period of SCL line set in RIICnBRL.

- Release the SCL line (low level to high level).

- Detect a high level of the SCL line and ensure the time set in RIICnBRH and the stop condition setup time.

- Release the SDA line (low level to high level).

- Ensure the time set in RIICnBRL and the bus free time.

- Clear the BBSY flag to 0 (to release the bus mastership).

**==> picture [384 x 134] intentionally omitted <==**

**----- Start of picture text -----**<br>
Setup time Bus free time<br>RIICnBRL RIICnBRH RIICnBRL RIICnBRH RIICnBRL RIICnBRH RIICnBRL<br>SCLn 8 9 P<br>Issue stop<br>SDAn b0 ACK/NACK condition<br>IIC<br>BBSY<br>MST<br>TRS<br>TDRE<br>STOP<br>SP<br>Write 1 to SP Accept stop condition issuance Clear STOP to 0<br>**----- End of picture text -----**<br>

**Figure 18.38 Stop Condition Issue Timing (SP Bit)**

## 18.13 Bus Hanging

If the clock signals from the master and slave devices go out of synchronization due to noise or other factors, the I[2] C bus might hang with a fixed level on the SCL line and/or SDA line.

As measures against the bus hanging, the RIIC has a timeout function to detect hanging by monitoring the SCL line, a function for the output of an extra SCL clock cycle to release the bus from a hung state due to clock signals being out of synchronization, and the RIIC/internal reset function.

By checking the RIICnCR1.SCLO, SDAO, SCLI, and SDAI bits, it is possible to see whether the RIIC or its partner in communications is placing the low level on the SCL or SDA lines.

## 18.13.1 Timeout Function

The RIIC has the timeout function to detect an abnormality that the SCL line is held for a certain period of time. The RIIC can detect an abnormal bus state by monitoring that the SCL line is held low or high for a predetermined time.

The timeout function monitors the SCL line state and counts the low-level period or high-level period using the internal counter. The timeout function resets the internal counter each time the SCL line changes (rising or falling), but continues to count unless the SCL line changes. If the internal counter overflows due to no SCL line change, the RIIC can detect the timeout and report the bus abnormality.

This timeout function is enabled when the RIICnFER.TMOE bit is 1. It detects an abnormal bus state in which the SCL line is held low or high in the following cases.

- <1> The bus is busy (RIICnCR2.BBSY = 1) in master mode (RIICnCR2.MST = 1).

- <2> The bus is busy (RIICnCR2.BBSY = 1) and the RIIC’s own slave address matches (RIICnSR1 is not 00H) in slave mode (RIICnCR2.MST = 0).

- <3> The bus is free (RIICnCR2.BBSY = 0) and issuing of a start condition is being requested (RIICnCR2.ST = 1).

The internal counter of the timeout function works using the internal reference clock (IIC  ) set by the RIICnMR1.CKS[2:0] bits as a count source. It functions as a 16-bit counter when long mode is selected (RIICnMR2.TMOS bit = 0) or a 14-bit counter when short mode is selected (TMOS bit = 1).

The SCL line level (low/high or both levels) during which this counter is activated can be selected by the setting of the RIICnMR2.TMOH and TMOL bits. If both TMOL and TMOH bits are cleared to 0, the internal counter does not work.

**==> picture [391 x 290] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Timeout function]<br>Start internal  Start internal  Start internal  Start internal  Start internal  Start internal<br>counter counter counter counter counter counter<br>Clear internal  Clear internal  Clear internal  Clear internal  Clear internal  Clear internal  Clear internal<br>counter counter counter counter counter counter counter<br>SCLn<br>SDAn<br>IIC<br>BBSY<br>TMOE<br>TMOH<br>TMOL<br>Write 1 to TMOH Write 0 to TMOL Write 1 to TMOL Write 0 to TMOE<br>[Example of operation when TMOH = 1 and TMOL = 1] When a stat condition is issued In the slave-address matched state 14-bit counter  16-bit counter<br>Clear internal counter Start internal counter overflows overflows<br>TMOS = 0 TMOS =  1<br>7 8 9 P S 1 2 7 8 9 1 2<br>SCLn<br>SDAn A/NA Bus free time 7-bit slave address R/W ACK Data<br>BBSY<br>ST<br>TMOE<br>TMOF<br>**----- End of picture text -----**<br>

**Figure 18.39 Timeout Function (TMOE, TMOS, TMOH, and TMOL Bits)**

## 18.13.2 Extra SCL Clock Cycle Output Function

In master mode, the RIIC module has a facility for the output of extra SCL (clock) cycles to release the SDA line of the slave device from being held at the low level due to the master being out of synchronization with the slave device.

This function is mainly used in master mode to release the SDA line of the slave device from the state of being fixed to the low level by including extra cycles of SCL output from the RIIC with single cycles of the SCL (clock) signal as the unit in the case of a bus error where the RIIC cannot issue a stop condition because the slave device is holding the SDA line at the low level. Do not use this facility in normal situations. Using it when communications are proceeding correctly will lead to malfunctions.

When the RIICnCR1.CLO bit is set to 1 in master mode, a single cycle of the SCL clock at the frequency corresponding to the transfer rate settings (settings of the RIICnMR1.CKS[2:0] bits, and of the RIICnBRH and RIICnBRL registers) is output as an extra clock cycle. After output of this single cycle of the SCL clock, the CLO bit is automatically cleared to 0. In this case, if the BBSY flag is set to 1, the SCL pin continues outputting the low level. If the BBSY flag is set to 0, the SCL pin goes high. In addition, further extra clock cycles can be output consecutively by the software program writing 1 to the CLO bit after having read CLO = 0.

When the RIIC module is in master mode and the slave device is holding the SDA line at the low level because synchronization with the slave device has been lost due to the effects of noise, etc., the output of a stop condition is not possible. The facility for output of an extra cycle of the SCL (clock) signal can be used to output extra cycles of SCL one by one to make the slave device release the SDA line from being held at the low level, thus recovering the bus from an unusable state. Release of the SDA line by the slave device can be monitored by reading the RIICnCR1.SDAI bit. After confirming release of the SDA line by the slave device, complete communications by reissuing the stop condition.

[Output conditions for using the RIICnCR1.CLO bit]

- When the bus is free (RIICnCR2.BBSY flag = 0) or in master mode (RIICnCR2.MST bit = 1 and BBSY flag = 1)

- When the communication device does not hold the SCL line low

Figure 18.40 shows the operation timing of the extra SCL clock cycle output function (CLO bit).

**==> picture [390 x 106] intentionally omitted <==**

**----- Start of picture text -----**<br>
SDAn line is held low due to irregular bits<br>RIICnBRH RIICnBRL RIICnBRH RIICnBRL RIICnBRH RIICnBRL<br>Extra clock cycle  Extra clock cycle<br>SCLn 9 output output<br>SDAn ACK or Data “0” MSB or Next Data Data “1”<br>IIC<br>BBSY<br>MST<br>TRS<br>CLO<br>Accept CLO output Write 1 to CLO Write 1 to CLO<br>**----- End of picture text -----**<br>

**Figure 18.40 Extra SCL Clock Cycle Output Function (CLO Bit)**

## 18.13.3 RIIC Reset and Internal Reset

The RIIC module incorporates a function for resetting itself. There are two types of reset. One is referred to as an RIIC reset; this initializes all registers including the RIICnCR2.BBSY flag. The other is referred to as an internal reset; this releases the RIIC from the slave-address matched state and initializes the internal counter while retaining other settings.

After issuing a reset, be sure to clear the RIICnCR1.IICRST bit to 0.

Both types of reset are effective for release from bus-hung states since both restore the output state of the SCL and SDA pins to the high impedance state.

Issuing a reset during slave operation may lead to a loss of synchronization between the master device clock and the slave device clock, so avoided this where possible. Note that monitoring of the bus state, such as for the presence of a start condition, is not possible during an RIIC reset (RIICnCR1.ICE and IICRST bits = 01B).

For a detailed description of the RIIC and internal resets, see Section 18.15, Reset Function of RIIC .

## 18.14 SMBus Operation

The RIIC is available for data communication conforming to the SMBus (Version 2.0). To perform SMBus communication, set the RIICnMR3.SMBS bit to 1. To use the transfer rate within a range of 10 kbps to 100 kbps of the SMBus standard, set the RIICnMR1.CKS[2:0] bits, RIICnCBRH, and RIICnBRL. In addition, determine the values of the RIICnMR2.DLCS bit and the

RIICnMR2.SDDL[2:0] bits to meet the data hold time specification of 300 ns or more. If the RIIC is used only as a slave device, the transfer rate setting is not necessary. When the RIIC is used only as a slave device, the transfer rate setting is not necessary, whereas the RIICnBRL needs to be set to a value equal to or longer than the data setup time (250 ns).

For the SMBus device default address (1100 001B), use one of the slave address registers L0 to L2 (RIICnSAR0, RIICnSAR1, and RIICnSAR2), and set the corresponding RIICnSARy.FSy bit (7-bit/10bit address format select) (y = 0 to 2) to 0 (7-bit address format).

When transmitting the UDID (Unique Device Identifier), set the RIICnFER.SALE bit to 1 to enable the slave arbitration lost detection function.

## 18.14.1 SMBus Timeout Measurement

- (1) Measuring timeout of slave device

The following period (timeout interval: TLOW: SEXT) must be measured for slave devices in SMBus communication.

- From start condition to stop condition

To measure timeout for slave devices, measure the period from start condition detection to stop condition detection with the internal timer using a start condition detection interrupt (INTRIICSTI) and stop condition detection interrupt (INTRIICSPI) of the RIIC. The measured timeout period must be within the total clock low-level period [slave device] TLOW: SEXT: 25 ms (max.) of the SMBus standard.

If the time measured with the internal timer exceeds the clock low-level detection timeout TTIMEOUT: 25 ms (min.) of the SMBus standard, the slave device must release the bus by writing 1 to the RIICnCR1.IICRST bit to issue an internal reset of the RIIC. When an internal reset is issued, the RIIC stops driving the bus for the SCL pin and SDA pin and make the SCL/SDA pin outputs high impedance, which releases the bus.

- (2) Measuring timeout of master device

The following periods (timeout interval: TLOW: MEXT) must be measured for master devices in SMBus communication.

- From start condition to acknowledge bit

- Between acknowledge bits

- From acknowledge bit to stop condition

To measure timeout for master devices, measure these periods with the internal timer using a start condition detection interrupt (INTRIICSTI), stop condition detection interrupt (INTRIICSPI), and transmit end interrupt (INTRIICTEI) or receive data full interrupt (INTRIICRI) of the RIIC. The measured timeout period must be within the total clock low-level extended period [master device] TLOW: MEXT: 10 ms (max.) of the SMBus standard, and the total of all TLOW: MEXT from start condition to stop condition must be within TLOW: SEXT: 25 ms (max.).

For the ACK receive timing (rising edge of the ninth SMBCLK clock cycle), monitor theRIICnSR2. TEND flag in master transmit mode (master transmitter) and the RIICnSR2.RDRF flag in master receive mode (master receiver). For this reason, perform bytewise transmit operation in master transmit mode, and hold the RIICnMR3.RDRFS bit 0 until the byte just before reception of the final byte in master receive mode. While the RDRFS bit is 0, the RDRF flag is set to 1 at the rising edge of the ninth SMBCLK clock cycle.

If the period measured with the internal timer exceeds the total clock low-level extended period [master device] TLOW:MEXT: 10 ms (max.) of the SMBus standard or the total of measured periods exceeds the clock low-level detection timeout TTIMEOUT: 25 ms (min.) of the SMBus standard, the master device must stop the transaction by issuing a stop condition. In master transmit mode, immediately stop the transmit operation (writing data to RIICnDRT).

**==> picture [391 x 185] intentionally omitted <==**

**----- Start of picture text -----**<br>
SMBus standard TLOW:SEXT: Total clock low-level extended period (slave device)<br>TLOW:MEXT: Total clock low-level extended period (master device)<br>Start TLOW:SEXT Stop<br>TLOW:MEXT Clk ACK TLOW:MEXT Clk ACK TLOW:MEXT Clk ACK TLOW:MEXT<br>S 1 2 7 8 9 1 2 7 8 9 1 2 7 8 9 P<br>SCLn<br>SDAn 7-bit slave address R/W ACK Data ACK Data A/NA<br>BBSY<br>TDRE<br>TEND<br>RDRF<br>RDRFS<br>START<br>STOP<br>Measured with the interval timer<br>**----- End of picture text -----**<br>

## **Figure 18.41 SMBus Timeout Measurement**

## 18.14.2 SMBus Host Notification Protocol/Notify ARP Master

In communications over an SMBus, a slave device can temporarily act as a master device to notify the SMBus host (or ARP master) of (or request the SMBus host for) its own slave address or to request its own slave address from the SMBus host.

For this LSI to operate as an SMBus host (or ARP master), the host address (0001 000B) sent from the slave device must be detected as a slave address, so the RIIC has a function for detecting the host address. To detect the host address as a slave address, set the RIICnMR3.SMBS bit and the RIICnSER.HOAE bit to 1. Operation after the host address has been detected is the same as normal slave operation.

## 18.15 Reset Function of RIIC

The RIIC has chip reset, RIIC reset, and internal reset functions. Table 18.24 lists the scope of each reset and reset conditions.

## **Table 18.24 RIIC Reset Functions  (1/2)**

|**Register**|**RIIC Reset**<br>**(ICE = 0, IICRST = 1)**<br>**Internal Reset**<br>**(ICE = 1, IICRST = 1)**<br>**Start Condition/**<br>**Restart Condition**<br>**Detection**<br>**Stop Condition**<br>**Detection**|
|---|---|
|RIICnCR1|ICE<br>0<br>1<br>Retained<br>Retained|
||IICRST<br>1<br>1<br>Retained<br>Retained|
||CLO<br>Initialized<br>Retained<br>Retained<br>Retained|
||SOWP<br>Initialized<br>Retained<br>Retained<br>Retained|
||SCLO<br>Initialized<br>Initialized<br>Retained<br>Retained|
||SDAO<br>Initialized<br>Initialized<br>Retained<br>Retained|
||SCLI<br>Initialized<br>Retained<br>Retained<br>Retained|
||SDAI<br>Initialized<br>Retained<br>Retained<br>Retained|
|RIICnCR2|BBSY<br>Initialized<br>Initialized *1<br>Operation<br>Retained|
||MST<br>Initialized<br>Initialized<br>Operation (retained)<br>Initialized|
||TRS<br>Initialized<br>Initialized<br>Operation (retained)<br>Initialized|
||SP<br>Initialized<br>Initialized<br>Initialized<br>Initialized|
||RS<br>Initialized<br>Initialized<br>Initialized<br>Initialized|
||ST<br>Initialized<br>Initialized<br>Initialized<br>Retained|
|RIICnMR1|CKS[2:0]<br>Initialized<br>Retained<br>Retained<br>Retained|
||BCWP<br>Initialized<br>Retained<br>Retained<br>Retained|
||BC[2:0]<br>Initialized<br>Initialized<br>Initialized<br>Retained|
|RIICnMR2|Initialized<br>Retained<br>Retained<br>Retained|
|RIICnMR3|WAIT<br>Initialized<br>Retained<br>Retained<br>Retained|
||RDRFS<br>Initialized<br>Retained<br>Retained<br>Retained|
||ACKWP<br>Initialized<br>Retained<br>Retained<br>Retained|
||ACKBT<br>Initialized<br>Retained<br>Retained<br>Initialized|
||ACKBR<br>Initialized<br>Retained<br>Retained<br>Retained|
||NF[1:0]<br>Initialized<br>Retained<br>Retained<br>Retained|
|RIICnFER|Initialized<br>Retained<br>Retained<br>Retained|
|RIICnSER|Initialized<br>Retained<br>Retained<br>Retained|
|RIICnIER|Initialized<br>Retained<br>Retained<br>Retained|
|RIICnSR1|DID<br>Initialized<br>Initialized<br>Retained<br>Initialized|
||GCA<br>Initialized<br>Initialized<br>Retained<br>Initialized|
||AAS2<br>Initialized<br>Initialized<br>Retained<br>Initialized|
||AAS1<br>Initialized<br>Initialized<br>Retained<br>Initialized|
||AAS0<br>Initialized<br>Initialized<br>Retained<br>Initialized|
|RIICnSR2|TDRE<br>Initialized<br>Initialized<br>Retained<br>Initialized|
||TEND<br>Initialized<br>Initialized<br>Retained<br>Initialized|
||RDRF<br>Initialized<br>Initialized<br>Retained<br>Retained|
||NACKF<br>Initialized<br>Initialized<br>Retained<br>Retained|
||STOP<br>Initialized<br>Initialized<br>Retained<br>Operation|
||START<br>Initialized<br>Initialized<br>Operation<br>Initialized|
||AL<br>Initialized<br>Initialized<br>Retained<br>Retained|
||TMOF<br>Initialized<br>Initialized<br>Retained<br>Retained|
|RIICnSAR0, RIICnSAR1, RIICnSAR2<br>Initialized<br>Retained<br>Retained<br>Retained||
|RIICnBRH, RIICnBRL<br>Initialized<br>Retained<br>Retained<br>Retained||

## **Table 18.24 RIIC Reset Functions  (2/2)**

||||**Start Condition/**||
|---|---|---|---|---|
||**RIIC Reset**|**Internal Reset**|**Restart Condition**|**Stop Condition**|
|**Register**|**(ICE = 0, IICRST = 1)**|**(ICE = 1, IICRST = 1)**|**Detection**|**Detection**|
|RIICnDRT|Initialized|Retained|Retained|Retained|
|RIICnDRR|Initialized|Retained|Retained|Retained|
|RIICnDRS|Initialized|Initialized|Retained|Retained|

Note 1. When an internal reset is applied while the bus is free after detection of a stop condition, the setting of the BBSY flag is 0 while the bus is free following de-assertion of the internal reset signal. When an internal reset is applied while the bus is not free, the BBSY flag is not cleared.
