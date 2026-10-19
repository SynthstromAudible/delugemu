# 6. Clock Pulse Generator

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 117–136. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI has a clock pulse generator that generates a CPU clock (Iφ), internal bus clock (Bφ), peripheral clock 1 (P1φ), and peripheral clock 0 (P0φ). The clock pulse generator consists of a crystal oscillator, PLL circuits, and divider circuits.

## 6.1 Features

- Clock types

A CPU clock (Iφ); an internal bus clock (Bφ); peripheral clock 1 (P1φ = CKIO) for the external bus interface; peripheral clock 0 (P0φ) for the on-chip peripheral modules

- Frequency change function

The CPU clock frequency can be changed using the PLL (phase locked loop) circuits and divider circuits within this module. The frequency is changed by software using frequency control register (FRQCR) setting.

- Power-down mode control

The clock can be stopped in sleep mode, software standby mode, and deep standby mode, and specific modules can be stopped using the module standby function. For details on clock control in the power-down modes, see section 42, Power-Down Modes .

- SSCG function

The CPU's internal PLL (phase locked loop) circuit includes an SSCG (spread spectrum clock generator). The SSCG can be used to decrease the peak value of EMI (electromagnetic interference) noise by frequency modulation, that is, by slightly modulating the output frequency.

The specification of the SSCG for this LSI is as follows.

- Specification of SSCG

- (1) Modulation waveform (modulation profile): Triangle wave

- (2) Type of spreading: Down-spreading

- (3) Modulation rate: -3.3% (clock mode 0), -3.1% (clock mode 1)

- (4) Modulation frequency: 20.00 to 26.67 kHz (frequency on the EXTAL pin ÷ 500)

   - 24.00 kHz (frequency on the USB_X1 pin x (1/4) ÷ 500)

Figure 6.1 shows a block diagram of the clock pulse generator.

**==> picture [455 x 394] intentionally omitted <==**

**----- Start of picture text -----**<br>
Divider 1 Divider 2<br>× 1 CPU clock<br>× 1 PLL circuit<br>× 1/4 (× 30, 32) × 2/3 (Iφ Max : 400.00 MHz)<br>× 1/3<br>SSCG<br>circuit<br>Internal Bus clock<br>(Bφ Max : 133.33 MHz)<br>10.00 to<br>13.33 MHz × 1/6 Peripheral clock 1<br>XTAL oscillatorCrystal  (P1φ Max : 66.67 MHz)<br>External Bus clock<br>EXTAL (CKIO Max : 66.67 MHz)<br>× 1/12 Peripheral clock 0<br>Crystal  (P0φ Max : 33.33 MHz)<br>USB_X2 oscillator × 1/6 Peripheral clock 1C<br>USB_X1 * (P1φ Max : 66.67 MHz)<br>48 MHz × 1/12 Peripheral clock 0C<br>(P0φ Max : 33.33 MHz)<br>Control unit<br>MD_CLK Clock frequency Standby control<br>MD_CLKS control circuit circuit<br>FRQCR: Frequency control register<br>Peripheral clocks 0C and 1C:<br>FRQCR The frequencies of these clock signals are not modulated<br>even if the SSCG function is enabled.<br>Bus interface<br>Peripheral bus<br>Note: * Selected by the MD_CLK pin. See Table 6.2.<br>**----- End of picture text -----**<br>

**Figure 6.1 Block Diagram**

The blocks of this module function as follows:

## (1) Crystal Oscillator

A crystal oscillator is connected to the XTAL and EXTAL pins or to the USB_X2 and USB_X1 pins. Either the EXTAL or USB_X1 pin is selected by the clock mode settings.

## (2) PLL Circuit

The PLL circuit is capable of multiplying the frequency of the input clock signal from the EXTAL pin by 30. If the input clock signal from the USB_X1 pin is selected, the frequency is multiplied by 32.

## (3) Divider 1 and Divider 2

The ratio for frequency division by divider 1 is fixed to 1/1 for the input from the EXTAL pin and 1/4 for the input from the USB_X1 pin.

Divider 2 generates a clock signal whose operating frequency can be used for the CPU clock, internal bus clock, peripheral clock 1, and peripheral clock 0. The division ratio of the CPU clock is set by the frequency control register (FRQCR). The division ratios for peripheral clocks 1 and 0 are fixed to 1/6 and 1/12, respectively.

## (4) Clock Frequency Control Circuit

The clock frequency control circuit controls the clock frequency using the frequency control register (FRQCR).

## (5) Standby Control Circuit

The standby control circuit controls the states of the on-chip oscillation circuit and other modules during clock switching, or, software standby or deep standby mode.

In addition, the standby control register is provided to control the power-down mode of other modules. For details on the standby control register, see section 42, Power-Down Modes .

## (6) Frequency Control Register (FRQCR)

The frequency control register (FRQCR) has control bits assigned for the following functions: clock output/non-output from the CKIO pin during software standby mode or deep standby mode and the frequency division ratio of the CPU clock (Iφ).

## (7) SSCG Circuit

Operation of the SSCG circuit is switched on or off (enabled or disabled) by the MD_CLKS pin. When the SSCG function is disabled, all of the internal clock frequencies are fixed, i.e. not modulated. When the SSCG function is enabled, the frequencies of clock signals supplied to peripheral modules other than those listed below are modulated.

Peripheral modules to which non-modulated clock signals are supplied:

IEBus[TM] controller (RZ/A1L only), multi-function timer pulse unit 2, serial communications interface with FIFO, CAN interface, OS timer, LIN interface (RZ/A1L only), and serial communication interface.

## 6.2 Input/Output Pins

Table 6.1 lists the clock pulse generator pins and their functions.

**Table 6.1 Pin Configuration and Functions of the Clock Pulse Generator**

|**Pin Name**|**Symbol**<br>**I/O**<br>**Function**|
|---|---|
|Mode control pin|MD_CLK<br>Input<br>Switches between the EXTAL input and the USB_X1 input.|
||MD_CLKS<br>Input<br>Enables or disables the SSCG circuit.|
|Crystal input/output pins<br>(clock input pins)|XTAL<br>Output<br>Connected to the crystal resonator. (Leave this pin open when the<br>crystal resonator is not in use.)|
||EXTAL<br>Input<br>Connected to the crystal resonator or used to input external clock.|
||USB_X2<br>Output<br>Connected to the crystal resonator. (Leave this pin open when the<br>crystal resonator is not in use.)|
||USB_X1<br>Input<br>Connected to the crystal resonator or used to input external clock.|
|Clock output pin|CKIO<br>Output<br>Clock output pin.|

## 6.3 Clock Mode

Table 6.2 indicates the input/output clock frequency. Table 6.3 shows the usable frequency ranges.

## **Table 6.2 Input/Output Clock Frequency**

|**Mode**|**MD_CLK**|**Clock I/O**|||||
|---|---|---|---|---|---|---|
||**Pin Setting**|**Source**|**Output**|**Divider 1**|**PLL Circuit**|**CKIO Frequency**|
|0|0|EXTAL/crystal|CKIO|1|ON (x30)|(EXTAL/crystal|
|||resonator||||resonator) x5|
|1|1|USB_X1/crystal|CKIO|1/4|ON (x32)|(USB_X1/crystal|
|||resonator||||resonator) x5|

In clock mode 0, the clock signal is the input from the EXTAL pin or the crystal oscillator. The PLL circuit shapes waveforms and multiples the frequency, and then supplies the clock to the LSI. The oscillating frequency for the crystal resonator and EXTAL pin input clock ranges from 10 to 13.33 MHz. The frequency range of CKIO is from 50 to 66.67 MHz.

In clock mode 1, the clock signal is the input from the USB_X1 pin or the crystal oscillator. The PLL circuit shapes waveforms and multiples the frequency, and then supplies the clock to the LSI. The oscillating frequency for the crystal resonator and USB_X1 pin input clock is 48 MHz. The frequency of CKIO is 64 MHz.

When changing the frequency, be sure to set the standby_mode_en bit of the power control register in the PL310. For details on the register, see CoreLink Level 2 Cache Controller L2C-310 Technical Reference Manual issued by Arm Ltd.

After the setting of IFC[1:0] in the frequency control register is changed, the hardware automatically stops the bus master and starts changing the frequency following the wait for completion of the issuing-finished request from the bus master. Since processing to change the frequency cannot start if completion of the issuing-finished request is not possible at this time, do not proceed with access to the registers of modules in the module-standby state and so on. Furthermore, as the issuing of unintended requests by the bus master is inhibited, using software to stop all bus masters in preparation for proceeding to change the frequency is also effective.

**Table 6.3 Settable Frequency Ranges**

|**Mode**|**FRQCR**<br>**Setting**<br>***1**|**PLL**<br>**Frequency**<br>**Multiplier**|**Ratio of Internal Clock**<br>**Frequencies**<br>**(I : B : P1 : P0)*2**|**Selectable Frequency Range (MHz)**|**Selectable Frequency Range (MHz)**|
|---|---|---|---|---|---|
|||**PLL Circuit**||**Input**<br>**Clock*3**<br>**Output**<br>**Clock**<br>**(CKIO Pin)**|**CPU Clock**<br>**(I**φ**)**<br>**Internal**<br>**Bus Clock**<br>**(B**φ**)**<br>**Peripheral**<br>**Clock 1**<br>**(P1**φ**)**<br>**Peripheral**<br>**Clock 0**<br>**(P0**φ**)**|
|0|H'x035|ON (× 30)|30 : 10 : 5 : 5/2|10.00 to<br>13.33<br>50.00 to<br>66.67|300.00 to<br>400.00<br>100.00 to<br>133.33<br>50.00 to<br>66.67<br>25.00 to<br>33.33<br>200.00 to<br>266.67<br>100.00 to<br>133.33|
||H'x135||20 : 10 : 5 : 5/2|||
||H'x335||10 : 10 : 5 : 5/2|||
|1|H'x035|ON (× 32)|8 : 8/3 : 4/3 : 2/3|48.00<br>64.00|384.00<br>128.00<br>64.00<br>32.00<br>256.00<br>128.00|
||H'x135||16/3 : 8/3 : 4/3 : 2/3|||
||H'x335||8/ 3 : 8/3 : 4/3 : 2/3|||

Note 1. x in the FRQCR register setting depends on the set value in bits 12, 13, and 14.

Note 2. The ratio of clock frequencies, where the input clock frequency is assumed to be 1.

Note 3. In clock mode 0, the frequency of the EXTAL pin input clock or the crystal resonator. In clock mode 1, the frequency of the USB_X1 pin input clock or the crystal resonator.

Caution: Do not use this LSI for frequency settings other than those in Table 6.3.

The clock source of the chip is switched by the setting of the MD_CLK pin while the RES pin is being held low. The following table shows the correspondence between clock source and pin settings.

## **Table 6.4 Clock Source Selection**

|**MD_CLK Pin Setting**|**Clock Source**|
|---|---|
|0|EXTAL/crystal resonator|
|1|USB_X1/crystal resonator|

The SSCG function of the chip is switched on or off by the setting of the MD_CLKS pin while the RES pin is being held low. The following table shows the correspondence between SSCG operation and pin settings. Note that the pin setting does not affect the PLL frequency multipliers and division ratios for individual clock signals.

## **Table 6.5 SSCG Operation Setting**

|**MD_CLKS Pin Setting**|**SSCG Operation**|
|---|---|
|0|Off|
|1|On|

## 6.4 Register Descriptions

Table 6.6 shows the register configuration of the clock pulse generator.

## **Table 6.6 Register Configuration**

|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Frequency control|FRQCR|R/W|H'0335|H'FCFE0010|16|
|register||||||

## 6.4.1 Frequency Control Register (FRQCR)

FRQCR is a 16-bit readable/writable register used to specify whether a clock is output from the CKIO pin during normal operation mode, change of gain of crystal oscillator for the XTAL pin, software standby mode, deep standby mode, and standby mode cancellation. The register specifies the frequency division ratio for the CPU clock (Iφ). FRQCR can be accessed in 16-bit units.

||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6|5|4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|CKO<br>EN2||CKOEN[1:0]||-|-|-<br>-<br>IFC[1:0]|-|-<br>-<br>-<br>-<br>-||
||Initial value:|0|0||0|0|0|0|1<br>1<br>0<br>0|1|1<br>0<br>1<br>0<br>1||
||R/W:|R|R/W||R/W|R/W|R|R|R/W<br>R/W<br>R<br>R|R|R<br>R<br>R<br>R<br>R||
|||||**Initial**|||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**||||
|15|―|||0|||R||Reserved||||
||||||||||This bit is always read as 0. The write value should always be|||0.|
|14|CKOEN2|||0|||R/W||Clock Output Enable 2||||
||||||||||Specifies whether the CKIO pin outputs clock signals or is fixed to the low||||
||||||||||level when the gain of the crystal oscillator for the XTAL pin is|||changed.|
||||||||||If this bit is set to 1, the CKIO pin is fixed to the low level when|||the gain of|
||||||||||the crystal oscillator for the XTAL pin is changed. Therefore, the||||
||||||||||malfunction of an external circuit caused by an unstable CKIO clock while||||
||||||||||changing the gain of the crystal oscillator for the XTAL pin can|||be|
||||||||||prevented.||||
||||||||||0: Unstable clock output||||
||||||||||1: Low-level output||||
|13, 12|CKOEN[1:0]|||00|||R/W||Clock Output Enable||||
||||||||||These bits specify whether the||CKIO pin outputs clock signals,|or is set to|
||||||||||a fixed level or high impedance (Hi-Z) during normal operation mode,||||
||||||||||deep standby mode, software standby mode, or cancellation of standby||||
||||||||||mode.||||
||||||||||If these bits are set to 01, the CKIO pin is fixed at low during deep||||
||||||||||standby mode, software|standby mode, or cancellation of software|||
||||||||||standby mode. Therefore, the malfunction of an external circuit|||caused by|
||||||||||an unstable CKIO clock|during cancellation of software standby mode|||
||||||||||can be prevented.||||
||||||||||Table 6.7 lists CKOEN[1:0] settings.||||
|11, 10|―|||00|||R||Reserved||||
||||||||||These bits are always read as||0. The write value should always be 0.||
|9, 8|IFC[1:0]|||11|||R/W||CPU Clock Frequency Division Ratio||||
||||||||||These bits specify the frequency division ratio of the CPU clock with||||
||||||||||respect to the output frequency of PLL circuit. Note: See section 6.5.1.||||
||||||||||00: 1/1 time||||
||||||||||01: 2/3 time||||
||||||||||10: Reserved (setting prohibited)||||
||||||||||11: 1/3 time||||
|7, 6|―|||00|||R||Reserved||||
||||||||||These bits are always read as||0. The write value should always be 0.||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|5, 4|―|11|R|Reserved|
|||||These bits are always read as 1. The write value should always be 1.|
|3|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|2|―|1|R|Reserved|
|||||This bit is always read as 1. The write value should always be 1.|
|1|―|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|0|―|1|R|Reserved|
|||||This bit is always read as 1. The write value should always be 1.|

## **Table 6.7 CKOEN[1:0] Settings**

|**Setting**|**Normal Operation**|**Software Standby Mode**|**Deep Standby Mode***|
|---|---|---|---|
|00|Output|Output off (Hi-Z)|Output off (Hi-Z)|
|01|Output|Low-level output|Low-level output|
|10|Output|Output (unstable clock output)|Low-level or high-level output|
|11|Output off (Hi-Z)|Output off (Hi-Z)|Output off (Hi-Z)|

Note: * Note that the first cycle of the output CKIO clock may be missing after release from deep standby.

## 6.5 Changing the Frequency

The frequency of the CPU clock (I φ ) can be changed by changing the division rate of divider. The division rate can be changed by software through the frequency control register (FRQCR).

## 6.5.1 Changing the Division Ratio

The division rate of divider can be changed by the following operation.

1. In the initial state, IFC[1:0] = B'11.

2. Set the desired value in the IFC[1:0] bits. Note that if the wrong value is set, this LSI will malfunction.

3. After the register bits (IFC[1:0]) have been set, the clock is supplied of the new division ratio.

- Note: When executing the WFI instruction after changing the frequency, be sure to read the frequency control register (FRQCR) to confirm that the new setting is in place and read the ISBUSY0 bit in the CPU status register (CPUSTS) to confirm that it is set to 0 beforehand.

For the CPUSTS register, see section 42, Power-Down Modes .

## 6.6 Usage of the Clock Pins

For the connection of a crystal resonator or the input of a clock signal, this LSI circuit has the pins listed in Table 6.8 . With regard to these pins, take care on the following points. Furthermore, Xin pin and Xout pin are used in this section to refer to the pins listed in the table.

## **Table 6.8 Clock Pins**

|**Table 6.8**<br>**Clock Pins**||
|---|---|
|**Xin Pins**||
|**(Used for Connection of a Crystal Resonator and Input of**|**Xout Pins**|
|**External Clock Signals)**|**(Used for Connection of a Crystal Resonator)**|
|EXTAL|XTAL|
|USB_X1|USB_X2|
|AUDIO_X1|AUDIO_X2|
|RTC_X1|RTC_X2|

## 6.6.1 In the Case of Inputting an External Clock

An example of the connection of an external clock is shown in Figure 6.2 . In cases where the Xout pin is left open state, take the parasitic capacitance as less than 10 pF.

**==> picture [238 x 83] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>External clock input Xin<br>Open state Xout<br>**----- End of picture text -----**<br>

**Figure 6.2 Example of the Connection of an External Clock**

## 6.6.2 In the Case of Using a Crystal Resonator

An example of the connection of crystal resonator is shown in Figure 6.3 .

Place the crystal resonator and capacitors (CL1 and CL2) as close to pins Xin and Xout as possible. Furthermore, to avoid inductance so that oscillation is correct, use the points where the capacitors are connected to the crystal resonator in common and do not place wiring patterns close to these components.

Since the design of the user board is closely connected with the effective characteristics of the crystal resonator, refer to the example of connection of the crystal resonator that is introduced in this section and perform thorough evaluation on the user side as well. The rated value of the crystal resonator will vary with the floating capacitances and so on of the crystal resonator and mounted circuit, so proceed with decisions on the basis of full discussions with the maker of the crystal resonator. Ensure that voltages applied to the clock pins do not exceed the maximum rated values.

Although the feedback resistor is included in this LSI, an external feedback resistor may be required in some cases. This depends on the characteristics of the crystal resonator.

Set the parameters (of resistors and capacitors) with thorough evaluation on the user side.

**==> picture [314 x 104] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>CL1<br>Xin<br>Crystal<br>resonator ROF RIF<br>CL2<br>Xout To internal<br>sections<br>ROD RID<br>**----- End of picture text -----**<br>

**Figure 6.3 Example of the Connection of a Crystal Resonator**

## 6.6.3 In the Case of Not Using the Clock Pin

In cases where the pins are not in use, fix the level on the Xin pin (pull it up or down, or connect it to the power-supply or ground level), and leave the Xout pin open state.

## 6.7 Oscillation Stabilizing Time

## 6.7.1 Oscillation Stabilizing Time of the On-chip Crystal Oscillator

In the case of using a crystal resonator, wait for the oscillation stabilizing time of the on-chip oscillation circuit at the following cases, to keep the oscillation stabilizing time of the on-chip crystal oscillator (in the case of inputting an external clock input, it is not necessary).

- Power on

- Releasing the software standby mode or deep standby mode by RES pin

- Changing from halting oscillation to running oscillation by power-on reset or register setting (AUDIO_X1)

- Changing from halting oscillation to running oscillation by register setting (RTC_X1)

- Changing the gain of the on-chip crystal oscillator by RES pin (EXTAL)

## 6.7.2 Oscillation Stabilizing Time of the PLL circuit

The clock from EXTAL is supplied to the PLL circuit. So, regardless of whether using a crystal resonator or inputting an external clock from EXTAL, wait for at least the oscillation stabilizing time at the following cases, to keep the oscillation stabilizing time of the PLL circuit.

- Power on (in the case of using the crystal resonator)/start inputting external clock (in the case of inputting the external clock)

- Releasing the software standby mode or deep standby mode by RES pin

## [Remarks]

The oscillation stabilizing time is kept by the counter running in the LSI at the following cases.

- Releasing the software standby mode or deep standby mode by the other than RES pin

- Changing the gain of the on-chip crystal oscillator by the register setting (EXTAL)

## 6.8 Notes on Board Design

## 6.8.1 Note on Using a PLL Oscillation Circuit

In the PLLVcc connection pattern for the PLL, signal lines from the board power supply pins must be as short as possible and pattern width must be as wide as possible to reduce inductive interferences.

Since the analog power supply pins of the PLL are sensitive to the noise, the system may malfunction due to inductive interference at the other power supply pins. To prevent such malfunction, the analog power supply pins and the digital power supply pins Vcc and PVcc should not supply the same resources on the board if at all possible.

## 6.9 Definition of Modulation Rate and Frequency in the SSCG Specification

The SSCG circuit can be used to decrease the peak value of electromagnetic interference noise by frequency modulation, i.e. by slightly modulating the output frequency. In this case, the rate of change in the frequency and the size of the change to the input clock frequency are defined as the modulation rate and modulation frequency, respectively. Figure 6.4 shows the modulation rate and modulation frequency.

**==> picture [394 x 90] intentionally omitted <==**

**----- Start of picture text -----**<br>
Frequency<br>Output signal<br>1/modulation frequency<br>Center frequency (f0) Time<br>f0 - 3.3% (clock mode 0),<br>f0 - 3.1% (clock mode 1) Modulation rate<br>**----- End of picture text -----**<br>

**Figure 6.4 Definition of SSCG Modulation Rate and Frequency**

## 6.10 Clock Signals

## 6.10.1 Clock Signals for the System and Realtime Clock

**==> picture [446 x 352] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clock pulse generator<br>Divider 1 Divider 2<br>��1<br>��1 PLL circuit CPU clock<br>��1/4 (��30, 32) ��2/3 (I� max. 400.00 MHz)<br>��1/3<br>SSCG<br>circuit<br>Internal bus clock<br>(B� max. 133.33 MHz)<br>10.00 to<br>13.33 MHz ��1/6 Peripheral clock 1<br>XTAL Crystal (P1� max. 66.67 MHz)<br>oscillator<br>External bus clock<br>EXTAL (CKIO max. 66.67 MHz)<br>��1/12 Peripheral clock 0<br>Crystal (P0� max. 33.33 MHz)<br>USB_X2 oscillator ��1/6 Peripheral clock 1C<br>USB_X1 * (P1� max. 66.67 MHz)<br>48 MHz ��1/12 Peripheral clock 0C<br>(P0� max. 33.33 MHz)<br>Realtime clock Peripheral clocks 0C and 1C:<br>These clock signals are not frequency-modulated even<br>if the SSCG function is enabled.<br>Divider 128 Hz<br>32.768 KHz<br>Crystal<br>RTC_X2 oscillator<br>RTC_X1<br>Note: * Selected by the MD_CLK pin. See Table 6.2.<br>**----- End of picture text -----**<br>

**Figure 6.5 Clock Signals for the System and Realtime Clock**

## 6.10.2 Audio and USB Clock Signals

**==> picture [385 x 367] intentionally omitted <==**

**----- Start of picture text -----**<br>
Max. 50.00 MHz<br>Crystal<br>AUDIO_X2 oscillator<br>AUDIO_XOUT<br>AUDIO_X1<br>Serial sound interface channels 0 to 3<br>AUDIO_XOUT2<br>AUDIO_XOUT3<br>Oversampling<br>Divider clock SCUX<br>Renesas SPDIF<br>1/2<br>Max. 50.00 MHz<br>AUDIO_CLK<br>Oversampling  1/3<br>clock<br>Channels 0 to 3<br>Div ider<br>Input<br>Media local bus (RZ/A1L only) timing<br>Max. 49.2544 MHz SSIWS0<br>MLB_CLK Oversampling clock to<br>SSIWS3<br>12 MHz<br>Crystal USB2.0 host/function interface Peripheral<br>XTAL oscillator clock 1<br>Div ider Output<br>1/2<br>EXTAL timing<br>PLL 48.00 MHz<br>USB_X2 oscillatorCrystal * (��10, 40) Divider USB communication clock<br>USB_X1<br>48 MHz<br>**----- End of picture text -----**<br>

**==> picture [352 x 8] intentionally omitted <==**

**----- Start of picture text -----**<br>
Note: * Selected by SYSCFG0.UCKSEL. See section 28.3.1, System Configuration Control Register (SYSCFG0).<br>**----- End of picture text -----**<br>

**Figure 6.6 Audio and USB Clock Signals**

## 6.10.3 Video Image Clock Signals

**==> picture [273 x 135] intentionally omitted <==**

**----- Start of picture text -----**<br>
Video display controller 5<br>Max. 87 MHz<br>DV0_CLK Video input clock<br>Max. 87 MHz Pixel clock<br>LCD0_EXTCLK Div ider<br>Peripheral clock 1<br>Capture engine unit<br>VIO_CLK<br>**----- End of picture text -----**<br>

**Figure 6.7 Video Image Clock Signals**

## 6.10.4 Other Clock Signals

**==> picture [279 x 254] intentionally omitted <==**

**----- Start of picture text -----**<br>
CAN interface<br>4.00 to 33.33 MHz Peripheral 1/2 Oversampling<br>CAN_CLK clock 1C clock<br>IEBus [TM]  Controller (RZ/A1L only)<br>Peripheral clock 0C<br>Fixed to 32 MHz<br>Debugger interface (CoreSight)<br>TCK<br>Ethernet controller<br>ET_TXCLK<br>ET_RXCLK<br>EthernetAVB (RZ/A1LU only)<br>ET_TXCLK<br>ET_RXCLK<br>AVB_GPTP_EXTERN<br>**----- End of picture text -----**<br>

**Figure 6.8 Clock Signals for Other Modules**

## 6.10.5 Internal Clock Signals (1)

|CPU clock<br>(Iφmax. 400.00 MHz)<br>Internal bus clock<br>(Bφmax. 133.33 MHz)<br>Peripheral clock 1<br>(P1φmax. 66.67 MHz)||CPU<br>Internal buses (north main bus, AXI64IC2 bus,<br>AHB32IC3 bus, peripheral bus 6, south main bus,<br>AXI128IC2 bus, AXI128IC3 bus)<br>Interrupt controller<br>Direct memory access controller<br>Large-capacity on-chip RAM<br>Secondary cache<br>SPI multi I/O bus controller<br>Ethernet controller<br>EthernetAVB (RZ/A1LU only)<br>Media local bus (RZ/A1L only)<br>Video display controller 5<br>JPEG codec unit (RZ/A1LU only)<br>Capture engine unit<br>Module standby signals<br>Module standby signals<br>Internal buses (peripheral buses 3, 4, 5, and 7)<br>General input/output port<br>Bus state controller<br>Debugger interface (CoreSight)<br>USB 2.0 host/function interface, 2 channels<br>A/D converter<br>CD-ROM decoder (RZ/A1L only)<br>SD host interface<br>MMC host interface<br>Serial sound interface, 4 channels<br>SCUX<br>Renesas serial peripheral interface, 3 channels<br>Renesas SPDIF<br>Media local bus (RZ/A1L only)<br>Video display controller 5<br>JPEG codec unit (RZ/A1LU only)|
|---|---|---|
||||
||||
||||

**Figure 6.9 Distribution of Internal Clock Signals (1)**

## 6.10.6 Internal Clock Signals (2)

Module standby signals Serial communication interface with FIFO, 5 channels Peripheral clock 1C Serial communication interface, 2 channels (P1φ max. 66.67 MHz) CAN interface, 2 channels Internal bus (peripheral buses 3 and 4) Interrupt controller Direct memory access controller Module standby signals Realtime clock Peripheral clock 0 I[2] C bus interface, 4 channels (P0φ max. 33.33 MHz) Video display controller 5 Internal bus (peripheral buses 1 and 2) Interrupt controller Direct memory access controller Watchdog timer General input/output port Module standby signals OS timer, 2 channels Peripheral clock 0C Multi-function timer pulse unit 2 (P0φ max. 33.33 MHz) IEBus[TM] controller (RZ/A1L only) LIN interface (RZ/A1L only) Internal buses (peripheral buses 1 and 2) Interrupt controller Direct memory access controller

## **Figure 6.10 Distribution of Internal Clock Signals (2)**

## 6.11 Usage Note

## 6.11.1 Notes on the SSCG

When the SSCG is to be used, secure the SSCG stabilizing time (tSSCG) shown in Table 47.5, Clock Timing in section 47, Electrical Characteristics . Furthermore, avoid deep standby while the SSCG is in use.
