# 47. Electrical Characteristics

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2761–2831. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 47.1 Absolute Maximum Ratings

## **Table 47.1 Absolute Maximum Ratings**

|**Table 47.1**<br>**Absolute Maximum Ratings**|**Table 47.1**<br>**Absolute Maximum Ratings**|
|---|---|
|**Item**<br>**Symbol**<br>**Value**<br>**Unit**||
|Power supply voltage (I/O)<br>PVCC<br>–0.3 to 4.2<br>V||
|Power supply voltage (Internal)<br>VCC<br>–0.3 to 1.6<br>V||
|PLL power supply voltage<br>PLLVCC<br>–0.3 to 1.6<br>V||
|Analog power supply voltage<br>AVCC<br>–0.3 to 4.2<br>V||
|Analog reference voltage<br>AVref<br>–0.3 to AVCC+0.3<br>V||
|USB transceiver analog power supply voltage (I/O)<br>USBAPVCC<br>–0.3 to 4.2<br>V||
|USB transceiver digital power supply voltage (I/O)<br>Note: Products in BGA packages do not have this pin.<br>USBDPVCC<br>–0.3 to 4.2<br>V||
|USB transceiver analog power supply voltage (internal)<br>USBAVCC<br>–0.3 to 1.6<br>V||
|USB transceiver digital power supply voltage (internal)<br>Note: Products in BGA packages do not have this pin.<br>USBDVCC<br>–0.3 to 1.6<br>V||
|Power supply for USB 480 MHz (internal)<br>Note: Products in BGA packages do not have this pin.<br>USBUVCC<br>–0.3 to 1.6<br>V||
|Input voltage|VBUS<br>Vin<br>–0.3 to 5.5<br>V|
||Other input pins<br>Vin<br>–0.3- to 3.3-V power supply<br>(PVCC, AVCC, USBAPVCC,<br>USBDPVCC) +0.3<br>V|
|Operating temperature|Topr<br>–40 to +85<br>°C|
|Storage temperature|Tstg<br>–55 to +125<br>°C|

Caution: Permanent damage to the LSI may result if absolute maximum ratings are exceeded.

## 47.2 Power-On/Power-Off Sequence

The 1.2-V power supply (VCC, PLLVcc, USBAVCC, USBDVCC, and USBUVCC) and 3.3-V power supply (PVCC, AVCC, USBAPVCC, and USBDPVCC) can be turned on and off in any order.

When turning on the power, be sure to drive both the TRST and RES pins low; otherwise, the output pins and input/ output pins output undefined levels, resulting in system malfunction.

When turning off the power, drive the TRST and RES pins low if the undefined output may cause a problem.

## 47.3 DC Characteristics

- Conditions used to obtain DC characteristics (2) in Table 47.2 other than current consumption VCC = USBDVCC= USBUVCC = 1.10 to 1.26 V, PVCC = USBDPVCC = 3.0 to 3.6 V, PLLVCC = 1.10 to 1.26 V, AVCC = 3.0 to 3.6 V, USBAPVCC = 3.0 to 3.6 V, USBAVCC = 1.10 to 1.26 V,

   - VSS = AVSS = USBDVSS = USBAVSS = USBDPVSS = USBAPVSS = USBUVSS = 0 V, Ta = –40 to 85  C

- Conditions used to obtain DC characteristics (2) in Table 47.2 for current consumption VCC = USBDVCC = USBUVCC = 1.18 V, PVCC = USBDPVCC = 3.3 V, PLLVCC = 1.18 V, AVCC = 3.3 V, USBAPVCC = 3.3 V, USBAVCC = 1.18 V,

   - VSS = AVSS = USBDVSS = USBAVSS = USBDPVSS = USBAPVSS = USBUVSS = 0 V, AVref = 3.3 V, VBUS = 5.0 V, Ta = –40 to 85  C

   - I  = 400.00 MHz, B  = 133.33 MHz, P1  = 66.67 MHz, P0  = 33.33 MHz

- Note: Products in BGA packages do not have USBDVCC, USBUVCC, USBDPVCC, USBDVSS, USBAVSS, USBDPVSS USBAPVSS, and USBUVSS pins.

## **Table 47.2 DC Characteristics (1) [Common Items]**

|**Item**|**Item**|**Symbol**|**Min.**<br>**Typ.**<br>**Max.**<br>**Unit**<br>**Test Conditions**|
|---|---|---|---|
|Power supply voltage||PVCC|3.0<br>3.3<br>3.6<br>V|
|||VCC|1.10<br>1.18<br>1.26<br>V|
|PLL power supply voltage||PLLVCC|1.10<br>1.18<br>1.26<br>V|
|Analog power supply voltage||AVCC|3.0<br>3.3<br>3.6<br>V|
|USB power supply voltage<br>Note: Products in BGA packages do not have<br>USBDPVcc, USBDVcc, and USBUVcc pins.||USBAPVCC<br>USBDPVCC|3.0<br>3.3<br>3.6<br>V|
|||USBAVCC<br>USBDVCC<br>USBUVCC|1.10<br>1.18<br>1.26<br>V|
|Input leakage current|All input pins||Iin||―<br>―<br>1.0<br>A<br>Vin= 0.5 to PVCC–<br>0.5 V|
|Three-state leakage<br>current|All input/output pins, all<br>output pins (except<br>P1_0 to P1_7) (off state)||ISTI||―<br>―<br>1.0<br>A<br>Vin= 0.5 to PVCC–<br>0.5 V<br>―<br>―<br>10<br>A|
||P1_0 to P1_7|||
|Input capacitance|all input/output pins, all<br>input pins|Cin|―<br>―<br>10<br>pF|

**Table 47.2 DC Characteristics (2) [Current Consumption]**

|**Item**|**Item**|**Power**<br>**Supply**<br>**Symbol**<br>**Typ.**<br>**Max.**<br>**Unit**<br>**Test Conditions**|
|---|---|---|
|Current consumption in normal<br>operation||VCC<br>ICC<br>―<br>492<br>mA|
|||PLLVCC<br>PLLICC<br>―<br>8<br>mA|
|||PVCC<br>PICC<br>70*1*2<br>―<br>mA|
|||AVCC<br>AICC<br>―<br>4<br>mA<br>During A/D conversion|
|||AVref<br>AIref<br>―<br>1<br>mA<br>During A/D conversion|
|||USBAVCC<br>UAICC<br>―<br>6<br>mA<br>When the USB host/function is in use.|
|||USBDVCC+<br>USBUVCC<br>UDICC*3<br>―<br>20<br>mA<br>In USB high-speed operation (2ch)|
|||USBAPVCC<br>UAPICC<br>―<br>4<br>mA<br>When the USB host/function is in use.|
|||USBDPVCC<br>UDPICC*4<br>70*1*2<br>―<br>mA<br>In USB high-speed operation (2ch)|
|||VBUS<br>VICC<br>―<br>10<br>μA|
|Current consumption in sleep<br>mode||VCC<br>Isleep<br>―<br>300<br>mA|
|||For the other power supply, the current consumption is the same as in normal operation.|
|Current<br>consumption in<br>software standby<br>mode|Ta50C|VCC+<br>PLLVCC+<br>USBAVCC+<br>USBDVCC+<br>USBUVCC<br>Isstby<br>32<br>120<br>mA|
|||PVCC+<br>AVCC+<br>AVref +<br>USBAPVCC+<br>USBDPVCC<br>PIsstby<br>20<br>26<br>μA|
|||VBUS<br>VIsstby<br>8<br>10<br>μA|
||Ta ≤ 50C|VCC+<br>PLLVCC+<br>USBAVCC+<br>USBDVCC+<br>USBUVCC<br>Isstby<br>13<br>55<br>mA|
|||PVCC+<br>AVCC+<br>AVref +<br>USBAPVCC+<br>USBDPVCC<br>PIsstby<br>17<br>20<br>μA|
|||VBUS<br>VIsstby<br>8<br>10<br>μA|

**Table 47.2 DC Characteristics (2) [Current Consumption]**

|**Item**||**Power**<br>**Supply**<br>**Symbol**|**Typ.**<br>**Max.**<br>**Unit**<br>**Test Conditions**|
|---|---|---|---|
|Current<br>consumption in<br>deep standby<br>mode|Ta50C|VCC+<br>PLLVCC+<br>USBAVCC+<br>USBDVCC+<br>USBUVCC<br>Idstby|27<br>119<br>μA<br>RAM 0 Kbytes retained, RTC_X1<br>selected|
||||32<br>137<br>μA<br>RAM 16 Kbytes retained, RTC_X1<br>selected|
||||37<br>155<br>μA<br>RAM 32 Kbytes retained, RTC_X1<br>selected|
||||42<br>191<br>μA<br>RAM 64 Kbytes retained, RTC_X1<br>selected|
||||62<br>263<br>μA<br>RAM 128 Kbytes retained, RTC_X1<br>selected|
||||When the EXTAL 13 MHz is selected, 5 μA and 7 μA are added to the<br>"Typ." and "Max." values above, respectively.|
|||PVCC+<br>AVCC+<br>AVref +<br>USBAPVCC+<br>USBDPVCC<br>PIdstby|13<br>15<br>μA<br>RTC is not operating|
||||20<br>25<br>μA<br>RTC_X1 selected|
||||1<br>―<br>mA<br>EXTAL 13 MHz selected, small gain*1|
|||VBUS<br>VIdstby|8<br>10<br>μA|
||Ta ≤ 50C|VCC+<br>PLLVCC+<br>USBAVCC+<br>USBDVCC+<br>USBUVCC<br>Idstby|17<br>54<br>μA<br>RAM 0 Kbytes retained, RTC_X1<br>selected|
||||21<br>71<br>μA<br>RAM 16 Kbytes retained, RTC_X1<br>selected|
||||25<br>88<br>μA<br>RAM 32 Kbytes retained, RTC_X1<br>selected|
||||33<br>122<br>μA<br>RAM 64 Kbytes retained, RTC_X1<br>selected|
||||49<br>190<br>μA<br>RAM 128 Kbytes retained, RTC_X1<br>selected|
||||When the EXTAL 13 MHz is selected, 5 μA and 7 μA are added to the<br>"Typ." and "Max." values above, respectively.|
|||PVCC+<br>AVCC+<br>AVref +<br>USBAPVCC+<br>USBDPVCC<br>PIdstby|12<br>13<br>μA<br>RTC is not operating|
||||19<br>23<br>μA<br>RTC_X1 selected|
||||1<br>―<br>mA<br>EXTAL 13 MHz selected, small gain*1|
|||VBUS<br>VIdstby|8<br>10<br>μA|

Note 1. Reference value. The actual operating current greatly depends on the system (such as slow rising/falling edges caused by IO load and toggle frequency). Be sure to determine the value using the actual system.

Note 2. The sum of PIcc and UDPIcc must be equal to or lower than 150 mA.

Note 3. In the products in BGA packages, UDIcc is added to Icc.

Note 4. In the products in BGA packages, UDPIcc is added to PIcc.

## **Table 47.2 DC Characteristics (3) [Except I[2] C Bus Interface, and USB 2.0 Host/Function Module-Related Pins]**

|**Item**||**Symbol**<br>**Min.**<br>**Typ.**<br>**Max.**<br>**Unit**<br>**Test Conditions**|
|---|---|---|
|Input high voltage*||VIH<br>2.2<br>―<br>PVCC+ 0.3<br>V|
|Input low voltage*||VIL<br>–0.3<br>―<br>0.8<br>V|
|Schmitt trigger input|characteristics|VT+<br>PVCC 0.665<br>―<br>―<br>V|
|||VT-<br>―<br>―<br>0.8<br>V|
|||VT+– VT-<br>0.2<br>―<br>―<br>V|
|Output high voltage||VOH<br>PVCC– 0.5<br>―<br>―<br>V<br>IOH= –2.0 mA|
|Output low voltage||VOL<br>―<br>―<br>0.4<br>V<br>IOL= 2.0 mA|
|RAM standby<br>voltage|Software standby mode<br>(large-capacity on-chip<br>RAM)|VRAMS<br>0.85<br>―<br>―<br>V<br>Measured with VCCas<br>parameter<br>VRAMD<br>1.10<br>―<br>―<br>V|
||Deep standby mode<br>(only the on-chip RAM<br>for data retention)||

Note: * Values for the input of data for boundary scanning through pins TMS, TCK, JP0_0, JP0_1, P5_0 to P5_15, and P6_0 to P6_15.

## **Table 47.2 DC Characteristics (4) [I[2] C Bus Interface Related Pins** * **]**

|**Item**|**Symbol**|**Min.**|**Typ.**|**Max.**|**Unit**|**Test Conditions**|
|---|---|---|---|---|---|---|
|Input high voltage|VIH|PVCC 0.7|―|PVCC+ 0.3|V||
|Input low voltage|VIL|–0.3|―|PVCC 0.3|V||
|Schmitt trigger input characteristics|VIH– VIL|PVCC 0.05|―|―|V||
|Output low voltage|VOL|―|―|0.4|V|IOL= 3.0 mA|

Note: * The P1_0 to P1_7 pins are open-drain pins.

## **Table 47.2 DC Characteristics (5) [USB 2.0 Host/Function Module-Related Pins** * **]**

|**Item**|**Symbol**|**Min.**|**Typ.**|**Max.**|**Unit**|**Test Conditions**|
|---|---|---|---|---|---|---|
|Reference resistance|RREF|5.6 k1%|5.6 k1%|5.6 k1%|||
|Input high voltage (VBUS1, VBUS0)|VIH|4.02|―|5.25|V||
|Input low voltage (VBUS1, VBUS0)|VIL|–0.3|―|0.5|V||
|Input high voltage (USB_X1)|VIH|PVCC 0.5|―|PVCC+ 0.3|V||
|Input low voltage (USB_X1)|VIL|–0.3|―|0.5|V||

Note: * REFRIN, VBUS1, VBUS0, USB_X1, and USB_X2 pins

**Table 47.2 DC Characteristics (6) [USB 2.0 Host/Function Module-Related Pins** * **(Low-Speed, Full-Speed, and High-Speed Common Items)]**

|<br>**High-Speed Common Items)]**||
|---|---|
|**Item**<br>**Symbol**|**Min.**<br>**Typ.**<br>**Max.**<br>**Unit**<br>**Test Conditions**|
|DP pull-up resistance (when function is<br>selected)<br>Rpu|0.900<br>―<br>1.575<br>k<br>In idle mode|
||1.425<br>―<br>3.090<br>k<br>In transmit/receive mode|
|DP and DM pull-down resistance (when host is<br>selected)<br>Rpd|14.25<br>―<br>24.80<br>k|

Note: * DP1, DP0, DM1, and DM pins

## **Table 47.2 DC Characteristics (7) [USB 2.0 Host/Function Module-Related Pins** * **(Low-Speed and Full-Speed)]**

|**Item**|**Symbol**|**Min.**|**Typ.**|**Max.**|**Unit**|**Test Conditions**|
|---|---|---|---|---|---|---|
|Input high voltage|VIH|2.0|―|―|V||
|Input low voltage|VIL|―|―|0.8|V||
|Differential input sensitivity|VDI|0.2|―|―|V|| (DP) – (DM) ||
|Differential common mode range|VCM|0.8|―|2.5|V||
|Output high voltage|VOH|2.8|―|3.6|V|IOH= –200A|
|Output low voltage|VOL|0.0|―|0.3|V|IOL= 2 mA|
|Output signal crossover voltage|VCRS|1.3|―|2.0|V|CL= 50 pF (full-speed)|
|||||||CL= 200 to 600 pF (low-|
|||||||speed)|

Note: * DP1, DP0, DM1, and DM pins

## **Table 47.2 DC Characteristics (8) [USB 2.0 Host/Function Module-Related Pins** * **(High-Speed)]**

|**Item**|**Symbol**|**Min.**|**Typ.**|**Max.**|**Unit**|**Test Conditions**|
|---|---|---|---|---|---|---|
|Squelch detection threshold voltage|VHSSQ|100|―|150|mV||
|(differential voltage)|||||||
|Common mode voltage range|VHSCM|–50|―|500|mV||
|Idle state|VHSOI|–10.0|―|10.0|mV||
|Output high voltage|VHSOH|360|―|440|mV||
|Output low voltage|VHSOL|–10.0|―|10.0|mV||
|Chirp J output voltage (difference)|VCHIRPJ|700|―|1100|mV||
|Chirp K output voltage (difference)|VCHIRPK|–900|―|–500|mV||

Note: * DP1, DP0, DM1, and DM pins

## **Table 47.3 Permissible Output Currents**

|**Item**|**Symbol**|**Min.**<br>**Typ.**|**Max.**<br>**Unit**|
|---|---|---|---|
|Permissible output<br>low current (per pin)|P1_0 to P1_7<br>IOL<br>Output pins other than<br>above|―<br>―<br>―|10<br>mA|
||||2<br>mA|
|Permissible output high current (per pin)<br>–IOH||―<br>―|2<br>mA|
|Permissible output current (total)<br>IO||―<br>―|150<br>mA|

Caution: To protect the LSI's reliability, do not exceed the output current values in Table 47.3.

## 47.4 AC Characteristics

Signals input to this LSI are basically handled as signals in synchronization with a clock. The setup and hold times for input pins must be followed.

Conditions for AC characteristics: VCC = USBDVCC = USBUVCC = 1.10 to 1.26 V, PVCC = USBDPVCC = 3.0 to 3.6 V, PLLVCC = 1.10 to 1.26 V, AVCC = 3.0 to 3.6 V, USBAPVCC = 3.0 to 3.6 V, USBAVCC = 1.10 to 1.26 V, VSS = AVSS = USBDVSS = USBAVSS = USBDPVSS = USBAPVSS = USBUVSS = 0 V, Ta = –40 to 85  C

Note: Products in BGA packages do not have USBDVCC, USBUVCC, USBDPVCC, USBDVSS, USBAVSS, USBDPVSS, USBAPVSS, and USBUVSS pins.

## **Table 47.4 Operating Frequency**

|**Item**|**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Remarks**|
|---|---|---|
|Operating frequency|CPU clock (I)<br>f<br>Internal bus clock (B)<br>Peripheral clock 1 (P1)<br>Peripheral clock 0 (P0)|100.00<br>400.00<br>MHz|
|||100.00<br>133.33<br>MHz|
|||50.00<br>66.67<br>MHz|
|||25.00<br>33.33<br>MHz|

## 47.4.1 Clock Timing

## **Table 47.5 Clock Timing**

|**Table 47.5**<br>**Clock Timing**||
|---|---|
|**Item**<br>**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|EXTAL clock input frequency (when the clock is supplied<br>to USB 2.0 host/function module)<br>fEX<br>EXTAL clock input frequency (when the clock isn't<br>supplied to USB 2.0 host/function module)|12MHz100ppm<br>Figure 47.1<br>10.00<br>13.33<br>MHz<br>75.00<br>100.00<br>ns<br>10.00<br>50.00<br>MHz<br>20.00<br>100.00<br>ns<br>1.00<br>50.00<br>MHz<br>20.00<br>1000.00<br>ns<br>48 MHz100 ppm<br>48 MHz500 ppm<br>48 MHz2500 ppm<br>0.4<br>0.6<br>tEXcyc<br>0.4<br>0.6<br>tEXcyc|
|EXTAL clock input cycle time (when the clock isn't<br>supplied to USB 2.0 host/function module)<br>tEXcyc||
|AUDIO_X1 clock input frequency (crystal resonator<br>connected)<br>fEX||
|AUDIO_X1 clock input cycle time (crystal resonator<br>connected)<br>tEXcyc||
|AUDIO_X1, AUDIO_CLK clock input frequency (external<br>clock input)<br>fEX||
|AUDIO_X1, AUDIO_CLK clock input cycle time (external<br>clock input)<br>tEXcyc||
|USB_X1 clock input frequency (when the 48-MHz clock is<br>supplied to USB 2.0 host/function module  and high-speed<br>transfer function is used)<br>fEX<br>USB_X1 clock input frequency (when the 48-MHz clock is<br>supplied to USB 2.0 host/function module, high-speed<br>transfer function is not used, and host controller function is<br>used)<br>USB_X1 clock input frequency (when the 48-MHz clock is<br>supplied to USB 2.0 host/function module, high-speed<br>transfer function is not used, and host controller function is<br>not used)||
|EXTAL, AUDIO_X1, AUDIO_CLK, USB_X1 clock input<br>low pulse width<br>tEXL||
|EXTAL, AUDIO_X1, AUDIO_CLK, USB_X1 clock input<br>high pulse width<br>tEXH||

## **Table 47.5 Clock Timing**

|**Table 47.5**<br>**Clock Timing**||
|---|---|
|**Item**<br>**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|EXTAL, AUDIO_X1, AUDIO_CLK, USB_ X1 clock input<br>rise time<br>tEXr|―<br>4<br>ns<br>Figure 47.1<br>―<br>4<br>ns<br>50.00<br>66.67<br>MHz|
|EXTAL, AUDIO_X1, AUDIO_CLK, USB_ X1 clock input<br>fall time<br>tEXf||
|CKIO clock output frequency<br>fOP||
|CKIO clock output cycle time<br>tcyc|15.00<br>20.00<br>ns<br>Figure 47.2 (1)<br>and Figure 47.2<br>(2)|
|CKIO clock output low pulse width 1<br>tCKOL1|tcyc/2 –tCKOr1<br>―<br>ns<br>Figure 47.2 (1)<br>tcyc/2 –tCKOr1<br>―<br>ns<br>―<br>3<br>ns<br>―<br>3<br>ns|
|CKIO clock output high pulse width 1<br>tCKOH1||
|CKIO clock output rise time 1<br>tCKOr1||
|CKIO clock output fall time 1<br>tCKOf1||
|CKIO clock output low pulse width 2<br>tCKOL2|tcyc/2 –tCKOr2<br>―<br>ns<br>Figure 47.2 (2)<br>tcyc/2 –tCKOr2<br>―<br>ns<br>―<br>2<br>ns<br>―<br>2<br>ns|
|CKIO clock output high pulse width 2<br>tCKOH2||
|CKIO clock output rise time 2<br>tCKOr2||
|CKIO clock output fall time 2<br>tCKOf2||
|On-chip PLL circuit oscillation settling time<br>tPOSC|1<br>―<br>ms<br>Figure 47.3 and<br>Figure 47.5 (1)|
|On-chip oscillation circuit oscillation settling time<br>(RTC_X1)<br>tROSC<br>On-chip oscillation circuit oscillation settling time (other<br>than above)|―<br>3*<br>s<br>Figure 47.6|
||―<br>4*<br>ms<br>Figure 47.3,<br>Figure 47.5 (1),<br>and Figure 47.6|
|Mode hold time<br>tMDH|200<br>―<br>ns<br>Figure 47.3 and<br>Figure 47.5 (1)|
|SSCG stabilizing time<br>tSSCG|1<br>―<br>us<br>Figure 47.4|

Note: * Settings for values smaller than the above specifications may be possible, as long as the values are confirmed through evaluation by the manufacturer of the oscillator.

**==> picture [266 x 99] intentionally omitted <==**

**----- Start of picture text -----**<br>
t<br>EXcyc<br>AUDIO_X1,EXTAL, tEXH tEXL<br>AUDIO_CLK,<br>USB_X1* 1/2 PVcc VIH VIH 1/2 PVccVIH<br>(input) VIL VIL<br>tEXf tEXr<br>Note:  *  When the clock is input on the EXTAL, AUDIO_X1, AUDIO_CLK, or USB_X1<br>**----- End of picture text -----**<br>

**Figure 47.1 EXTAL, AUDIO_X1, AUDIO_CLK, and USB_X1 Clock Input Timing**

**==> picture [186 x 89] intentionally omitted <==**

**----- Start of picture text -----**<br>
tcyc<br>tCKOH1 tCKOL1<br>1/2 PVcc VOH VOH VOH 1/2 PVcc<br>VOL VOL<br>tCKOf1 tCKOr1<br>**----- End of picture text -----**<br>

**Figure 47.2 (1) CKIO Clock Output Timing 1**

**==> picture [186 x 89] intentionally omitted <==**

**----- Start of picture text -----**<br>
tcyc<br>tCKOH2 tCKOL2<br>2.0V 2.0V 2.0V<br>1/2 PVcc 1/2 PVcc<br>0.8V 0.8V<br>tCKOf2 tCKOr2<br>**----- End of picture text -----**<br>

## **Figure 47.2 (2) CKIO Clock Output Timing 2**

**==> picture [352 x 177] intentionally omitted <==**

**----- Start of picture text -----**<br>
Oscillation settling time<br>CKIO,<br>Internal clock<br>Power supply* Power supply min.<br>tROSC + tPOSC<br>RES tMDH<br>TRST<br>MD_BOOT1, MD_BOOT0<br>MD_CLK, MD_CLKS<br>Note:  Oscillation settling time when the internal oscillator is used.<br>* PVcc, Vcc, PLLVcc, AVcc, USBAPVcc, USBDPVcc, USBAVcc, USBDVcc, USBUVcc<br> Products in BGA packages do not have USBDVcc, USBUVcc, and USBDPVcc pins.<br>**----- End of picture text -----**<br>

**Figure 47.3 Power-On Oscillation Settling Time**

**==> picture [338 x 147] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vccmin<br>Vcc<br>tSSCG<br>MD_CLKS<br>VT-<br>**----- End of picture text -----**<br>

**==> picture [166 x 10] intentionally omitted <==**

**----- Start of picture text -----**<br>
Figure 47.4 SSCG Stabilizing Time<br>**----- End of picture text -----**<br>

**==> picture [373 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
Standby period Oscillation settling time<br>CKIO,<br>Internal clock<br>tROSC + tPOSC<br>RES<br>tMDH<br>MD_BOOT1, MD_BOOT0<br>MD_CLK, MD_CLKS<br>Note: Oscillation settling time when the internal oscillator is used.<br>**----- End of picture text -----**<br>

**Figure 47.5 (1) Oscillation Stabilizing Time on Return from Standby (Return by Reset)**

**==> picture [369 x 106] intentionally omitted <==**

**----- Start of picture text -----**<br>
Standby period Oscillation settling time<br>CKIO,<br>Internal clock<br>tNMIW, tIRQW<br>NMI, IRQ<br>tROSC + tPOSC<br>**----- End of picture text -----**<br>

## **Figure 47.5 (2) Oscillation Stabilizing Time on Return from Standby (Return by NMI or IRQ)**

**==> picture [397 x 249] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1) RTC_X1 Oscillation settling time<br>Clock (internal)<br>RCR2.RTCEN tROSC<br>(2) Other than above Oscillation settling time<br>Clock (internal)<br>PVCC* PVCCmin tROSC<br>Note: *  When power is initially supplied, the oscillation settling time for the on-chip oscillation<br>circuit is counted from the point where PVcc reaches the minimum voltage for guaranteed<br>operation. Once power is supplied, the point where counting starts will only be relevant<br>due to changes in the state of oscillation. In such cases, counting starts when setting of the<br>registers is completed.<br>**----- End of picture text -----**<br>

**Figure 47.6 On-chip Oscillation Circuit Oscillation Stabilizing Time**

## 47.4.2 Control Signal Timing

## **Table 47.6 Control Signal Timing**

|**Item**|**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|---|---|---|
|RES<br>pulse width|Exit from standby mode<br>tRESW<br>Other than above|tROSC+ tPOSC<br>ms<br>Figure 47.7 (1) and<br>Figure 47.5 (1)<br>20<br>―<br>tcyc<br>20<br>―<br>tcyc|
|TRST<br>pulse width|tTRSW||
|NMI pulse width|tNMIW|20<br>―<br>tcyc<br>Figure 47.7 (2) and<br>Figure 47.5 (2)<br>20<br>―<br>tcyc<br>20<br>―<br>tcyc|
|IRQ pulse width|tIRQW||
|TINT pulse width|tTINTW||
|RES<br>input rise time*1|tRSr|―<br>500<br>μs<br>Figure 47.7 (3)|
|RES<br>negating hold time*2|tRSNH|0<br>―<br>ns<br>Figure 47.7 (4)|

Note 1. Make sure that this specification is satisfied when the same signal is controlling the TRST and RES pins. Note 2. Make sure that this specification is satisfied when different signals are controlling the TRST and RES pins.

**==> picture [285 x 53] intentionally omitted <==**

**----- Start of picture text -----**<br>
tRESW/tTRSW<br>RES<br>TRST<br>**----- End of picture text -----**<br>

**Figure 47.7 (1) Reset Input Timing 1**

**==> picture [253 x 140] intentionally omitted <==**

**----- Start of picture text -----**<br>
tNMIW<br>NMI<br>tIRQW<br>IRQ<br>tTINTW<br>TINT<br>**----- End of picture text -----**<br>

**Figure 47.7 (2) Interrupt Signal Input Timing**

**==> picture [483 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
RES<br>TRST<br>tRSr<br>Figure 47.7 (3) Reset Input Timing 2<br>**----- End of picture text -----**<br>

**==> picture [204 x 147] intentionally omitted <==**

**----- Start of picture text -----**<br>
VT+<br>TRST<br>tRSNH<br>RES<br>VT-<br>**----- End of picture text -----**<br>

**Figure 47.7 (4) Reset Input Timing 3**

## 47.4.3 Bus Timing

## **Table 47.7 Bus Timing**

|**Table 47.7**<br>**Bus Timing**||
|---|---|
|**Item**<br>**Symbol**|**CKIO = 66.67 MHz*1**<br>**Unit**<br>**Figure**<br>**Min.**<br>**Max.**|
|Address delay time 1<br>tAD1|0/2*3<br>12<br>ns<br>Figure 47.8 to Figure 47.32|
|Address delay time 2<br>tAD2|1/2tcyc<br>1/2tcyc+ 12<br>ns<br>Figure 47.15|
|Address setup time<br>tAS|0<br>―<br>ns<br>Figure 47.8 to Figure 47.11, Figure<br>47.15|
|Chip enable setup time<br>tCS|0<br>―<br>ns<br>Figure 47.8 to Figure 47.11, Figure<br>47.15|
|Address hold time<br>tAH|0<br>―<br>ns<br>Figure 47.8 to Figure 47.11|
|BS<br>delay time<br>tBSD|―<br>12<br>ns<br>Figure 47.8 to Figure 47.29|
|CS<br>delay time 1<br>tCSD1|0/2*3<br>12<br>ns<br>Figure 47.8 to Figure 47.32|
|Read write delay time 1<br>tRWD1|0/2*3<br>12<br>ns<br>Figure 47.8 to Figure 47.32|
|Read strobe delay time<br>tRSD|1/2tcyc<br>1/2tcyc+ 12<br>ns<br>Figure 47.8 to Figure 47.15|
|Read data setup time 1<br>tRDS1|1/2tcyc+ 5<br>―<br>ns<br>Figure 47.8 to Figure 47.14|
|Read data setup time 2<br>tRDS2|7<br>―<br>ns<br>Figure 47.16 to Figure 47.19,<br>Figure 47.24 to Figure 47.26|
|Read data setup time 3<br>tRDS3|1/2tcyc+ 5<br>―<br>ns<br>Figure 47.15|
|Read data hold time 1<br>tRDH1|0<br>―<br>ns<br>Figure 47.8 to Figure 47.14|
|Read data hold time 2<br>tRDH2|2<br>―<br>ns<br>Figure 47.16 to Figure 47.19,<br>Figure 47.24 to Figure 47.26|
|Read data hold time 3<br>tRDH3|0<br>―<br>ns<br>Figure 47.15|
|Write enable delay time 1<br>tWED1|1/2tcyc<br>1/2tcyc+ 12<br>ns<br>Figure 47.8 to Figure 47.13|
|Write enable delay time 2<br>tWED2|―<br>12<br>ns<br>Figure 47.14|
|Write data delay time 1<br>tWDD1|―<br>12<br>ns<br>Figure 47.8 to Figure 47.14|
|Write data delay time 2<br>tWDD2|―<br>12<br>ns<br>Figure 47.20 to Figure 47.23,<br>Figure 47.27 to Figure 47.29|
|Write data hold time 1<br>tWDH1|1<br>―<br>ns<br>Figure 47.8 to Figure 47.14|
|Write data hold time 2<br>tWDH2|2<br>―<br>ns<br>Figure 47.20 to Figure 47.23,<br>Figure 47.27 to Figure 47.29|
|Write data hold time 4<br>tWDH4|0<br>―<br>ns<br>Figure 47.8 to Figure 47.12|
|WAIT<br>setup time<br>tWTS|1/2tcyc+ 4.5<br>―<br>ns<br>Figure 47.9 to Figure 47.15|
|WAIT<br>hold time<br>tWTH|1/2tcyc+ 3.5<br>―<br>ns<br>Figure 47.9 to Figure 47.15|
|RAS<br>delay time 1<br>tRASD1|2<br>12<br>ns<br>Figure 47.16 to Figure 47.32|
|CAS<br>delay time 1<br>tCASD1|2<br>12<br>ns<br>Figure 47.16 to Figure 47.32|
|DQM delay time 1<br>tDQMD1|2<br>12<br>ns<br>Figure 47.16 to Figure 47.29|
|CKE delay time 1<br>tCKED1|2<br>12<br>ns<br>Figure 47.31|
|AH<br>delay time<br>tAHD|1/2tcyc<br>1/2tcyc+ 12<br>ns<br>Figure 47.12|
|Multiplexed address delay time<br>tMAD|―<br>12<br>ns<br>Figure 47.12|
|Multiplexed address hold time<br>tMAH|1<br>―<br>ns<br>Figure 47.12|
|Address setup time for AH<br>tAVVH|1/2tcyc– 2<br>―<br>ns<br>Figure 47.12|
|DACK, TEND delay time<br>tDACD|Refer to the direct memory<br>access controller timing<br>ns<br>Figure 47.8 to Figure 47.29|

Note 1. The maximum value (fmax) of CKIO (external bus clock) depends on the number of wait cycles and the system configuration of your board.

Note 2. 1/2 tcyc indicated in minimum and maximum values for the item of delay, setup, and hold times represents a half cycle from the rising edge with a clock. That is, 1/2 tcyc describes a reference of the falling edge with a clock. Note 3. Values when SDRAM is used.

**==> picture [271 x 427] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 T2<br>CKIO<br>tAD1 tAD1<br>A25 to A0<br>tAS<br>tCSD1 tCSD1<br>CSn<br>tCS<br>tRWD1 tRWD1<br>RD/WR<br>tRSD tRSD tAH<br>RD<br>tRDH1<br>Read tRDS1<br>D31 to D0<br>tWED1 tWED1 tAH<br>WEn<br>tWDH4<br>Write tWDD1 tWDH1<br>D31 to D0<br>tBSD tBSD<br>BS<br>tDACD tDACD<br>DACKn<br>TENDn*<br>Note: *  The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.8 Basic Bus Timing for Normal Space (No Wait)**

**==> picture [308 x 475] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 Tw T2<br>CKIO<br>tAD1 tAD1<br>A25 to A0<br>tAS<br>tCSD1 tCSD1<br>CSn<br>tCS<br>tRWD1 tRWD1<br>RD/WR<br>tRSD tRSD tAH<br>RD<br>tRDH1<br>Read tRDS1<br>D31 to D0<br>tWED1 tWED1 tAH<br>WEn<br>tWDH4<br>Write tWDD1 tWDH1<br>D31 to D0<br>tBSD tBSD<br>BS<br>tDACD tDACD<br>DACKn<br>TENDn*<br>tWTH<br>tWTS<br>WAIT<br>Note: *  The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.9 Basic Bus Timing for Normal Space (One Software Wait Cycle)**

**==> picture [357 x 470] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 Tw TwX T2<br>CKIO<br>tAD1 tAD1<br>A25 to A0<br>tAS<br>tCSD1 tCSD1<br>CSn<br>tCS<br>tRWD1 tRWD1<br>RD/WR<br>tRSD tRSD tAH<br>RD<br>tRDH1<br>Read tRDS1<br>D31 to D0<br>tWED1 tWED1 tAH<br>WEn tWDH4<br>Write tWDD1 tWDH1<br>D31 to D0<br>tBSD tBSD<br>BS<br>tDACD tDACD<br>DACKn<br>TENDn*<br>tWTH tWTH<br>tWTS tWTS<br>WAIT<br>Note: *  The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.10 Basic Bus Timing for Normal Space (One Software Wait Cycle, One External Wait Cycle)**

**==> picture [319 x 396] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 Tw T2 Taw T1 Tw T2 Taw<br>CKIO<br>tAD1 tAD1 tAD1 tAD1<br>A25 to A0<br>tAS tAS<br>tCSD1 tCSD1 tCSD1 tCSD1<br>CSn<br>tCS tCS<br>tRWD1 tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRSD tRSD tAH tRSD tRSD tAH<br>RD<br>tRDH1 tRDH1<br>tRDS1 tRDS1<br>D15 to D0<br>tWED1 tWED1 tWED1 tWED1 tAH<br>WEn tWDH4 tWDH4<br>tWDD1 tWDH1 tWDD1 tWDH1<br>D15 to D0<br>tBSD tBSD tBSD tBSD<br>BS<br>tDACD tDACD tDACD tDACD<br>DACKn<br>TENDn*<br>tWTH tWTH<br>tWTS tWTS<br>WAIT<br>Note: *  The waveform for DACKn and TENDn is when active low is specified.<br>Read<br>Write<br>**----- End of picture text -----**<br>

**Figure 47.11 Basic Bus Timing for Normal Space (One Software Wait Cycle, External Wait Cycle Valid (WM Bit = 0), No Idle Cycle)**

|Ta1<br>Ta2<br>Ta3<br>T1<br>Tw<br>tAD1<br>tCSD1<br>tRWD1<br>tRSD<br>tWED1<br>tBSD<br>tBSD<br>tAHD<br>tAVVH<br>tAVVH<br>tAHD<br>tWTH<br>tWTS<br>tDACD<br>Address<br>tWDD1<br>tMAD<br>CKIO<br>A25 to A0<br>CS5<br>RD/WR<br>RD<br>AH<br>D15 to D0<br>Read<br>WE1,WE0<br>BS<br>WAIT<br>DACKn*<br>Note:*The waveform for DACKn and TENDn is when active low is specified.<br>D15 to D0<br>Write<br>Address<br>tMAH<br>tMAD<br>tAHD<br>tDACD<br>TENDn*<br>tMAH|||Ta1||Ta2||Ta3|T1|Tw|Tw|TwX|TwX|T2<br>tAD1<br>tRWD1<br>tCSD1|T2<br>tAD1<br>tRWD1<br>tCSD1|T2<br>tAD1<br>tRWD1<br>tCSD1|T2<br>tAD1<br>tRWD1<br>tCSD1|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||tAD1<br>CSD1<br>tRWD1<br>tAHD||||||||||||||
||||||||||||||||||
||||||||||||||||||
||||||||||||||||||
|||t|||||||||||t||||
||||||||||||||||||
||||||||||||||t||||
||||||||||||||||||
|||tAHD|||tAHD||||||||||||
||||||||||||||||||
||||||||||||||||||
|||||||||tRSD<br>tMAH|||||tRSD<br>tRDS1<br>tWED1<br>Data<br><br>tW<br>tRDH||||
||||||||||||||||||
|||||tM|tAVVH<br>AD||||||||||1||
||||||||||||||||||
||||||||Address||||||||||
|||||||||tWED1<br>tWDD1<br>|||||||||
||||||||||||||||||
||||||||||||||||||
|||||tM|SD<br>tAVVH<br>AD||tMA||||||||DH1<br>DH4||
||||||||||||||||||
||||||||||||||||||
|||||||||H|||||tW||||
||||||||||||||||||
||||||||Address||||Data||||||
|||t|BSD|tB|||||||||||||
||||||||||||||||||
||||||||||tWTH<br>tWTS||tWTH<br>tWTS||||||
||||||||||||||||||
||||||||||tWTS||tWTS||||||
||||||||||||||||||
||||||||||||||||||
|||||||||tDACD|||||||||
||||||||||||||||||
||||||||||||||||||
||||||||||||||||||

**Figure 47.12 MPX-I/O Interface Bus Cycle (Three Address Cycles, One Software Wait Cycle, One External Wait Cycle)**

**==> picture [376 x 479] intentionally omitted <==**

**----- Start of picture text -----**<br>
Th T1 Twx T2 Tf<br>CKIO<br>tAD1 tAD1<br>A25 to A0<br>tCSD1 tCSD1<br>CSn<br>tWED1 tWED1<br>WEn<br>tRWD1 tRWD1<br>RD/WR<br>tRSD tRSD<br>Read RD tRDH1<br>tRDS1<br>D31 to D0<br>tRWD1 tRWD1<br>RD/WR<br>tWDD1 tWDH1<br>Write<br>D31 to D0<br>tBSD tBSD<br>BS<br>tDACD tDACD<br>DACKn<br>TENDn*<br>tWTH tWTH<br>WAIT<br>tWTS tWTS<br>Note: *  The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.13 Bus Cycle of SRAM with Byte Selection (SW = 1 Cycle, HW = 1 Cycle, One Asynchronous External Wait Cycle, BAS = 0 (Write Cycle UB/LB Control))**

**==> picture [376 x 478] intentionally omitted <==**

**----- Start of picture text -----**<br>
Th T1 Twx T2 Tf<br>CKIO<br>tAD1 tAD1<br>A25 to A0<br>tCSD1 tCSD1<br>CSn<br>tWED2 tWED2<br>WEn<br>tRWD1<br>RD/WR<br>tRSD tRSD<br>Read RD tRDH1<br>tRDS1<br>D31 to D0<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>Write tWDD1 tWDH1<br>D31 to D0<br>tBSD tBSD<br>BS<br>tDACD tDACD<br>DACKn<br>TENDn*<br>tWTH tWTH<br>WAIT<br>tWTS tWTS<br>Note: *  The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.14 Bus Cycle of SRAM with Byte Selection (SW = 1 Cycle, HW = 1 Cycle, One Asynchronous External Wait Cycle, BAS = 1 (Write Cycle WE Control))**

**==> picture [368 x 449] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 Tw Twx T2B Twb T2B<br>CKIO<br>tAD1 tAD2 tAD2 tAD1<br>A25 to A0<br>tCSD1 tAS tCSD1<br>CSn<br>tCS<br>tRWD1 tRWD1<br>RD/WR<br>tRSD tRSD<br>RD<br>tRDH3 tRDH3<br>tRDS3 tRDS3<br>D31 to D0<br>WEn<br>tBSD tBSD<br>BS<br>tDACD tDACD<br>DACKn<br>TENDn*<br>tWTH tWTH<br>WAIT<br>tWTS tWTS<br>Note: *  The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.15 Burst ROM Read Cycle (One Software Wait Cycle, One Asynchronous External Burst Wait Cycle, Two Burst)**

**==> picture [309 x 453] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Tc1 Tcw Td1 Tde<br>CKIO<br>tAD1 tAD1 tAD1<br>A25 to A0 Row address Column address<br>tAD1 tAD1 tAD1<br>A12/A11 [*][1] R EADA  command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tRDS2 tRDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.16 Synchronous DRAM Single Read Bus Cycle (Auto Precharge, CAS Latency 2, WTRCD = 0 Cycle, WTRP = 0 Cycle)**

**==> picture [349 x 457] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Trw Tc1 Tcw Td1 Tde Tap<br>CKIO<br>tAD1 tAD1 tAD1<br>A25 to A0 Row address Column address<br>tAD1 tAD1 tAD1<br>A12/A11 [*][1] R EADA  command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tRDS2 tRDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.17 Synchronous DRAM Single Read Bus Cycle (Auto Precharge, CAS Latency 2, WTRCD = 1 Cycle, WTRP = 1 Cycle)**

**==> picture [324 x 465] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tr Tc1 Tc2 Tc3 Tc4 Tde<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 addressRow addressColumn ( 1 to 4)<br>tAD1 tAD1 tAD1 tAD1<br>A12/A11 [*][1] READ  command commandREADA<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tRDS2 tRDH2 tRDS2 tRDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.18 Synchronous DRAM Burst Read Bus Cycle (Four Read Cycles) (Auto Precharge, CAS Latency 2, WTRCD = 0 Cycle, WTRP = 1 Cycle)**

**==> picture [353 x 461] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tr Trw Tc1 Tc2 Tc3 Tc4 Tde<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 addressRow addressColumn ( 1 to 4)<br>tAD1 tAD1 tAD1 tAD1<br>A12/A11 [*][1] READ  command READA<br>command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tRDS2 tRDH2 tRDS2 tRDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.19 Synchronous DRAM Burst Read Bus Cycle (Four Read Cycles) (Auto Precharge, CAS Latency 2, WTRCD = 1 Cycle, WTRP = 0 Cycle)**

**==> picture [186 x 427] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Tc1 Trwl<br>CKIO<br>tAD1 tAD1 tAD1<br>A25 to A0 Row Column<br>address address<br>tAD1 tAD1 tAD1<br>A12/A11 [*][1] commandWRITA<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tWDD2 tWDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>**----- End of picture text -----**<br>

Notes: 1.   An address pin to be connected to pin A10 of SDRAM. 2.   The waveform for DACKn and TENDn is when active low is specified.

**Figure 47.20 Synchronous DRAM Single Write Bus Cycle (Auto Precharge, TRWL = 1 Cycle)**

**==> picture [274 x 455] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Trw Trw Tc1 Trwl<br>CKIO<br>tAD1 tAD1 tAD1<br>Column<br>A25 to A0 Row address address<br>tAD1 tAD1 tAD1<br>A12/A11 [*][1] commandWRITA<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tWDD2 tWDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.21 Synchronous DRAM Single Write Bus Cycle (Auto Precharge, WTRCD = 2 Cycles, TRWL = 1 Cycle)**

**==> picture [313 x 455] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Tc1 Tc2 Tc3 Tc4 Trwl<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 Row Column<br>address address<br>tAD1 tAD1 tAD1 tAD1<br>A12/A11 [*][1] WRIT command commandWRITA<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tWDD2 tWDH2 tWDD2 tWDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.22 Synchronous DRAM Burst Write Bus Cycle (Four Write Cycles) (Auto Precharge, WTRCD = 0 Cycle, TRWL = 1 Cycle)**

**==> picture [353 x 455] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Trw Tc1 Tc2 Tc3 Tc4 Trwl<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 addressRow addressColumn<br>tAD1 tAD1 tAD1 tAD1<br>A12/A11 [*][1] WRIT command commandWRITA<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tWDD2 tWDH2 tWDD2 tWDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.23 Synchronous DRAM Burst Write Bus Cycle (Four Write Cycles) (Auto Precharge, WTRCD = 1 Cycle, TRWL = 1 Cycle)**

**==> picture [309 x 461] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tr Tc1 Tc2 Tc3 Tc4 Tde<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 addressRow addressColumn<br>tAD1 tAD1 tAD1<br>A12/A11 [*][1] READ command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tRDS2 tRDH2 tRDS2 tRDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.24 Synchronous DRAM Burst Read Bus Cycle (Four Read Cycles) (Bank Active Mode: ACT + READ Commands, CAS Latency 2, WTRCD = 0 Cycle)**

**==> picture [483 x 495] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tc1 Tc2 Tc3 Tc4 Tde<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 addressColumn<br>tAD1 tAD1<br>A12/A11 [*][ 1] READ command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1<br>RD/WR<br>tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tRDS2 tRDH2 tRDS2 tRDH2<br>D31 to  D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn* [2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.25 Synchronous DRAM Burst Read Bus Cycle (Four Read Cycles) (Bank Active Mode: READ Command, Same Row Address, CAS Latency 2, WTRCD = 0 Cycle)**

**==> picture [360 x 435] intentionally omitted <==**

**----- Start of picture text -----**<br>
Td1 Td2 Td3 Td4<br>Tp Trw Tr Tc1 Tc2 Tc3 Tc4 Tde<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 addressRow addressColumn<br>tAD1 tAD1 tAD1 tAD1<br>A12/A11 [*][1] READ command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1 tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tRDS2 tRDH2 tRDS2 tRDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn [*][2]<br>**----- End of picture text -----**<br>

Notes: 1.   An address pin to be connected to pin A10 of SDRAM. 2.   The waveform for DACKn and TENDn is when active low is specified.

**Figure 47.26 Synchronous DRAM Burst Read Bus Cycle (Four Read Cycles) (Bank Active Mode: PRE + ACT + READ Commands, Different Row Addresses, CAS Latency 2, WTRCD = 0 Cycle)**

**==> picture [293 x 455] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tr Tc1 Tc2 Tc3 Tc4<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 addressRow addressColumn<br>tAD1 tAD1 tAD1<br>A12/A11 [*][1] WRIT command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tWDD2 tWDH2 tWDD2 tWDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn [*][2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.27 Synchronous DRAM Burst Write Bus Cycle (Four Write Cycles) (Bank Active Mode: ACT + WRITE Commands, WTRCD = 0 Cycle, TRWL = 0 Cycle)**

**==> picture [296 x 456] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tnop Tc1 Tc2 Tc3 Tc4<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 addressColumn<br>tAD1 tAD1 tAD1<br>A12/A11 [*][1] WRIT command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tWDD2 tWDH2 tWDD2 tWDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn [*][2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.28 Synchronous DRAM Burst Write Bus Cycle (Four Write Cycles) (Bank Active Mode: WRITE Command, Same Row Address, WTRCD = 0 Cycle, TRWL = 0 Cycle)**

**==> picture [363 x 455] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Tr Tc1 Tc2 Tc3 Tc4<br>CKIO<br>tAD1 tAD1 tAD1 tAD1 tAD1 tAD1<br>A25 to A0 Row address C olumn addres s<br>tAD1 tAD1 tAD1 tAD1<br>A12/A11 [*][1] WRIT command<br>tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1 tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>tDQMD1 tDQMD1<br>DQMxx<br>tWDD2 tWDH2 tWDD2 tWDH2<br>D31 to D0<br>tBSD tBSD<br>BS<br>(High)<br>CKE<br>tDACD tDACD<br>DACKn<br>TENDn [*][2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.29 Synchronous DRAM Burst Write Bus Cycle (Four Write Cycles) (Bank Active Mode: PRE + ACT + WRITE Commands, Different Row Addresses, WTRCD = 0 Cycle, TRWL = 0 Cycle)**

**==> picture [268 x 455] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Trr Trc Trc Trc<br>CKIO<br>tAD1 tAD1<br>A25 to A0<br>tAD1 tAD1<br>A12/A11 [*][1]<br>tCSD1 tCSD1 tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1 tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>DQMxx<br>(Hi-Z)<br>D31 to D0<br>BS<br>(High)<br>CKE<br>DACKn<br>TENDn [*][2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.30 Synchronous DRAM Auto-Refreshing Timing (WTRP = 1 Cycle, WTRC = 3 Cycles)**

**==> picture [336 x 456] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Trr Trc Trc Trc<br>CKIO<br>tAD1 tAD1<br>A25 to A0<br>tAD1 tAD1<br>A12/A11 [*][1]<br>tCSD1 tCSD1 tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1 tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1<br>CAS<br>DQMxx<br>(Hi-Z)<br>D31 to D0<br>BS<br>tCKED1 tCKED1<br>CKE<br>DACKn<br>TENDn [*][2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.31 Synchronous DRAM Self-Refreshing Timing (WTRP = 1 Cycle)**

**==> picture [355 x 467] intentionally omitted <==**

**----- Start of picture text -----**<br>
Tp Tpw Trr Trc Trc Trr Trc Trc Tmw Tde<br>CKIO<br>PALL REF REF MRS<br>tAD1 tAD1 tAD1<br>A25 to A0<br>tAD1 tAD1<br>A12/A11 [*][1]<br>tCSD1 tCSD1 tCSD1 tCSD1 tCSD1 tCSD1 tCSD1 tCSD1<br>CSn<br>tRWD1 tRWD1 tRWD1 tRWD1 tRWD1<br>RD/WR<br>tRASD1 tRASD1 tRASD1 tRASD1 tRASD1 tRASD1 tRASD1 tRASD1<br>RAS<br>tCASD1 tCASD1 tCASD1 tCASD1 tCASD1 tCASD1<br>CAS<br>DQMxx<br>(Hi-Z)<br>D31 to D0<br>BS<br>CKE<br>DACKn<br>TENDn [*][2]<br>Notes: 1.   An address pin to be connected to pin A10 of SDRAM.<br>2.   The waveform for DACKn and TENDn is when active low is specified.<br>**----- End of picture text -----**<br>

**Figure 47.32 Synchronous DRAM Mode Register Write Timing (WTRP = 1 Cycle)**

## 47.4.4 Direct Memory Access Controller Timing

## **Table 47.8 Direct Memory Access Controller Timing**

|**Table 47.8**<br>**Direct Memory Access Controller Timing**||
|---|---|
|**Item**<br>**Symbol**<br>**Min.**<br>**Max.**<br>**Unit**|**Figure**|
|DREQ setup time<br>tDRQS<br>5.5<br>―<br>ns<br>DREQ hold time<br>tDRQH<br>2.5<br>―<br>DACK, TEND delay time<br>tDACD<br>0<br>12|Figure 47.33|
||Figure 47.34|
|||
|tDRQS tDRQH<br>CKIO<br>DREQ0||
|**Figure 47.33**<br>**DREQ Input Timing**||
|CKIO<br>TEND0<br>DACK0<br>tDACD<br>tDACD||

**==> picture [189 x 10] intentionally omitted <==**

**----- Start of picture text -----**<br>
Figure 47.34 DACK, TEND Output Timing<br>**----- End of picture text -----**<br>

## 47.4.5 Multi-Function Timer Pulse Unit 2 Timing

## **Table 47.9 Multi-Function Timer Pulse Unit 2 Timing**

|**Table 47.9**<br>**Multi-Function Timer Pulse Unit 2 Timing**|**Table 47.9**<br>**Multi-Function Timer Pulse Unit 2 Timing**|**Table 47.9**<br>**Multi-Function Timer Pulse Unit 2 Timing**|**Table 47.9**<br>**Multi-Function Timer Pulse Unit 2 Timing**||
|---|---|---|---|---|
|**Item**<br>**Symbol**<br>**Min.**||||**Max.**<br>**Unit**<br>**Figure**|
|Timer clock pulse width (single edge)<br>tTCKWH/L<br>1.5||||―<br>tp0cyc<br>Figure 47.35<br>―<br>tp0cyc<br>―<br>tp0cyc|
|Timer clock pulse width (both edges)<br>tTCKWH/L<br>2.5|||||
|Timer clock pulse width (phase counting<br>mode)<br>tTCKWH/L<br>2.5|||||
|Note:<br>tp0cycindicates peripheral clock (P0) cycle.|||||
|TCLKA<br>to TCLKD||||tTCKWH|
||tTCKWL||||
||||||
||||||
||||||

**Figure 47.35 Clock Input Timing**

## 47.4.6 Watchdog Timer Timing

**==> picture [166 x 9] intentionally omitted <==**

**----- Start of picture text -----**<br>
Table 47.10 Watchdog Timer Timing<br>**----- End of picture text -----**<br>

**==> picture [483 x 128] intentionally omitted <==**

**----- Start of picture text -----**<br>
Item Symbol Min. Max. Unit Figure<br>WDTOVF delay time tWOVD — 100 ns Figure 47.36<br>CKIO<br>tWOVD tWOVD<br>WDTOVF<br>**----- End of picture text -----**<br>

**Figure 47.36 WDTOVF Output Timing**

## 47.4.7 Serial Communication Interface with FIFO Timing

## **Table 47.11 Serial Communication Interface with FIFO Timing**

|**Item**|**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|---|---|---|
|Input clock cycle|(clocked synchronous)<br>tScyc<br>(asynchronous)|12<br>―<br>tp1cyc<br>Figure 47.37<br>4<br>―<br>tp1cyc<br>―<br>1.5<br>tp1cyc<br>―<br>1.5<br>tp1cyc<br>0.4<br>0.6<br>tScyc|
|Input clock rise time|tSCKr||
|Input clock fall time|tSCKf||
|Input clock width|tSCKW||
|Transmit data delay time (clocked synchronous)<br>tTXD||―<br>3 tp1cyc+ 15<br>ns<br>Figure 47.38<br>4 tp1cyc+ 15<br>―<br>ns<br>1 tp1cyc+ 15<br>―<br>ns|
|Receive data setup time (clocked synchronous)<br>tRXS|||
|Receive data hold time (clocked synchronous)<br>tRXH|||

Note: tp1cyc indicates the peripheral clock 1 (P1) cycle.

**==> picture [229 x 50] intentionally omitted <==**

**----- Start of picture text -----**<br>
tSCKW tSCKr tSCKf<br>SCK<br>tScyc<br>**----- End of picture text -----**<br>

## **Figure 47.37 SCK Input Clock Timing**

**==> picture [300 x 88] intentionally omitted <==**

**----- Start of picture text -----**<br>
tScyc<br>SCK<br>(input/output) tTXD<br>TxD<br>(data transmit)<br>tRXS tRXH<br>RxD<br>(data receive)<br>**----- End of picture text -----**<br>

**Figure 47.38 Transmit/Receive Data Input/Output Timing in Clocked Synchronous Mode**

## 47.4.8 Serial Communication Interface Timing

## **Table 47.12 Serial Communication Interface Timing**

|**Item**|**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|---|---|---|
|Input clock cycle|(asynchronous)<br>tScyc<br>(clocked synchronous)|4<br>―<br>tp1cyc<br>Figure 47.39<br>6<br>―<br>0.4<br>0.6<br>tScyc<br>―<br>20<br>ns<br>―<br>20<br>ns<br>16<br>―<br>tp1cyc<br>4<br>―<br>0.4<br>0.6<br>tScyc<br>―<br>20<br>ns<br>―<br>20<br>ns|
|Input clock pulse width|tSCKW||
|Input clock rise time|tSCKr||
|Input clock fall time|tSCKf||
|Output clock cycle|(asynchronous)<br>tScyc<br>(clocked synchronous)||
|Output clock pulse width|tSCKW||
|Output clock rise time|tSCKr||
|Output clock fall time|tSCKf||
|Transmit data delay time|(clocked synchronous)<br>tTXD|―<br>40<br>ns<br>Figure 47.40<br>40<br>―<br>ns<br>40<br>―<br>ns|
|Receive data setup time|(clocked synchronous)<br>tRXS||
|Receive data hold time|(clocked synchronous)<br>tRXH||

Note: tp1cyc indicates the peripheral clock 1 (P1) cycle.

**==> picture [483 x 228] intentionally omitted <==**

**----- Start of picture text -----**<br>
tSCKW tSCKr tSCKf<br>SCKn<br>(n = 0, 1)<br>tScyc<br>Figure 47.39 SCK Input Clock Timing<br>tSCKW<br>SCKn<br>tTXD<br>TXDn<br>tRXS tRXH<br>RXDn<br>(n = 0, 1)<br>**----- End of picture text -----**<br>

**Figure 47.40 Transmit/Receive Data Input/Output Timing in Clocked Synchronous Mode**

## 47.4.9 Renesas Serial Peripheral Interface Timing

**Table 47.13 Renesas Serial Peripheral Interface Timing**

|**Item**|**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|---|---|---|
|RSPCK clock cycle|Master<br>tSPcyc<br>Slave|2<br>4096<br>tcyc<br>Figure 47.41<br>8<br>4096<br>0.4<br>―<br>tSPcyc<br>0.4<br>―<br>0.4<br>―<br>tSPcyc<br>0.4<br>―|
|RSPCK clock high pulse width|Master<br>tSPCKWH<br>Slave||
|RSPCK clock low pulse width|Master<br>tSPCKWL<br>Slave||
|Data input setup time|Master<br>tSU<br>Slave|15<br>―<br>ns<br>Figure 47.42 to<br>Figure 47.45<br>0<br>―<br>tcyc<br>0<br>―<br>ns<br>4<br>―<br>tcyc<br>1tSPcyc–<br>20<br>8tSPcyc<br>ns<br>4<br>―<br>tcyc<br>1tSPcyc<br>8tSPcyc+<br>20<br>ns<br>4<br>―<br>tcyc<br>―<br>21<br>ns<br>―<br>4<br>tcyc<br>5<br>―<br>ns<br>3<br>―<br>tcyc<br>1tSPcyc+<br>2 tcyc<br>8tSPcyc+<br>2tcyc<br>ns<br>4tcyc<br>―|
|Data input hold time|Master<br>tH<br>Slave||
|SSL setup time|Master<br>tLEAD<br>Slave||
|SSL hold time|Master<br>tLAG<br>Slave||
|Data output delay time|Master<br>tOD<br>Slave||
|Data output hold time|Master<br>tOH<br>Slave||
|Continuous transmission delay time|Master<br>tTD<br>Slave||
|Slave access time|tSA|―<br>4<br>tcyc<br>Figure 47.44<br>and Figure<br>47.45<br>―<br>3<br>tcyc|
|Slave out release time|tREL||

**==> picture [352 x 185] intentionally omitted <==**

**----- Start of picture text -----**<br>
tSPCKWH<br>VOH VOH<br>RSPCKn<br>Master select output VOL VOL<br>tSPCKWL<br>tSPcyc<br>tSPCKWH<br>VIH VIH<br>RSPCKn<br>Slave select input VIL VIL<br>tSPCKWL<br>tSPcyc<br>(n = 0 to 2)<br>**----- End of picture text -----**<br>

**Figure 47.41 Clock Timing**

**==> picture [359 x 156] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTD<br>SSLn0<br>Output<br>tLEAD tLAG<br>RSPCKn<br>CP0L = 0<br>Output<br>RSPCKn<br>CP0L = 1<br>Output<br>tSU tH<br>MISOn MSB IN DATA LSB IN MSB IN<br>Input<br>tOH tOD<br>MOSIn<br>Output MSB OUT DATA LSB OUT IDLE MSB OUT<br>**----- End of picture text -----**<br>

**==> picture [27 x 6] intentionally omitted <==**

**----- Start of picture text -----**<br>
(n = 0 to 2)<br>**----- End of picture text -----**<br>

**Figure 47.42 Transmission and Reception Timing (Master, CPHA = 0)**

**==> picture [358 x 178] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTD<br>SSLn0<br>Output<br>tLEAD tLAG<br>RSPCKn<br>CP0L = 0<br>Output<br>RSPCKn<br>CP0L = 1<br>Output<br>tSU tH<br>MISOn<br>Input MSB IN DATA LSB IN MSB IN<br>tOH tOD<br>MOSIn<br>Output MSB OUT DATA LSB OUT IDLE MSB OUT<br>(n = 0 to 2)<br>**----- End of picture text -----**<br>

**Figure 47.43 Transmission and Reception Timing (Master, CPHA = 1)**

**==> picture [359 x 177] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTD<br>SSLn0<br>Input<br>tLEAD tLAG<br>RSPCKn<br>CP0L = 0<br>Input<br>RSPCKn<br>CP0L = 1<br>Input<br>tSA tOH tOD<br>MISOn<br>Output MSB OUT DATA LSB OUT IDLE MSB OUT<br>tSU tH<br>MOSIn MSB IN DATA LSB IN MSB IN<br>Input<br>(n = 0 to 2)<br>**----- End of picture text -----**<br>

**Figure 47.44 Transmission and Reception Timing (Slave, CPHA = 0)**

**==> picture [358 x 176] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTD<br>SSLn0<br>Input<br>tLEAD tLAG<br>RSPCKn<br>CP0L = 0<br>Input<br>RSPCKn<br>CP0L = 1<br>Input<br>tSA tOH tOD tREL<br>MISOn LSB OUT<br>Output (Last data) MSB OUT DATA LSB OUT IDLE MSB OUT<br>tSU tH tDR, tDF<br>MOSIn<br>Input MSB IN DATA LSB IN MSB IN<br>(n = 0 to 2)<br>**----- End of picture text -----**<br>

**Figure 47.45 Transmission and Reception Timing (Slave, CPHA = 1)**

## 47.4.10 SPI Multi I/O Bus Controller Timing

## **Table 47.14 SPI Multi I/O Bus Controller Timing**

|**Item**|**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|---|---|---|
|SPBCLK clock cycle|tSPBcyc|2<br>4080<br>tbcyc<br>Figure 47.46<br>0.475<br>0.525<br>tSPBcyc<br>0.475<br>0.525<br>tSPBcyc<br>―<br>3<br>ns<br>―<br>3<br>ns|
|SPBCLK high pulse width|tSPBWH||
|SPBCLK low pulse width|tSPBWL||
|SPBCLK rise time|tSPBR||
|SPBCLK fall time|tSPBF||
|Data input setup time|CKDLY =<br>B’0100 (initial<br>value)<br>tSU<br>CKDLY =<br>B’1010 (RZ/<br>A1LU only)|5.0<br>―<br>ns<br>Figure 47.47,<br>Figure 47.48,<br>Figure 47.49, and<br>Figure 47.50<br>2.0*2<br>―<br>0.0<br>―<br>ns<br>1.0*2<br>―<br>1tSPBcyc- 3<br>8tSPBcyc+ 3<br>ns<br>1.5tSPBcyc<br>8.5tSPBcyc+ 3<br>ns<br>1<br>8<br>tSPBcyc<br>―<br>4.0<br>ns<br>―<br>5.0*2<br>–2.0<br>―<br>ns<br>1.0*2<br>―|
|Data input hold time|CKDLY =<br>B’0100<br>tH<br>CKDLY =<br>B’1010 (RZ/<br>A1LU only)||
|SSL setup time|tLEAD||
|SSL hold time|tLAG||
|Continuous transfer delay time|tTD||
|Data output delay time|SPODLY =<br>H’0000 (initial<br>value)<br>tOD<br>SPODLY =<br>H’1111 (RZ/<br>A1LU only)||
|Data output hold time|SPODLY =<br>H’0000 (initial<br>value)<br>tOH<br>SPODLY =<br>H’1111 (RZ/<br>A1LU only)||
|Data output buffer on time|SPODLY =<br>H’0000 (initial<br>value)<br>tBON<br>SPODLY =<br>H’1111 (RZ/<br>A1LU only)|―<br>4.0<br>ns<br>Figure 47.47,<br>Figure 47.48,<br>Figure 47.49,<br>Figure 47.50,<br>Figure 47.51, and<br>Figure 47.52<br>―<br>5.0*2<br>–9.0<br>0<br>ns<br>1.5*2<br>7.5*2|
|Data output buffer off time|SPODLY =<br>H’0000 (initial<br>value)<br>tBOFF<br>SPODLY =<br>H’1111 (RZ/<br>A1LU only)||

Note 1. tbcyc indicates the bus clock (B) cycle. Note 2. Value when the output load is 15 pF

**==> picture [320 x 98] intentionally omitted <==**

**----- Start of picture text -----**<br>
tSPBcyc<br>tSPBWL tSPBWH<br>SPBCLK<br>Output<br>tSPBF tSPBR<br>**----- End of picture text -----**<br>

## **Figure 47.46 Clock Timing**

**==> picture [345 x 160] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTD<br>SPBSSL<br>Output<br>tLEAD tLAG<br>SPBCLK<br>CPOL = 0<br>Output<br>SPBCLK<br>CPOL = 1<br>Output<br>tSU tH<br>SPBMI_0/_1,  MSB IN DATA LSB IN<br>SPBIO[0:3]_0/_1<br>Input<br>tBON tOH tOD<br>SPBMO_0/_1, SPBIO[0:3]_0/_1 MSB OUT DATA LSB OUT IDLE<br>Output<br>**----- End of picture text -----**<br>

**Figure 47.47 SDR Transfer Format Transmission and Reception Timing (CPHAT = 0, CPHAR = 0)**

**==> picture [338 x 160] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTD<br>SPBSSL<br>Output<br>tLEAD tLAG<br>SPBCLK<br>CPOL = 0<br>Output<br>SPBCLK<br>CPOL = 1<br>Output<br>tSU tH<br>SPBMI_0/_1,  MSB IN DATA LSB IN<br>SPBIO[0:3]_0/_1<br>Input<br>tBON tOH tOD<br>SPBMO_0/_1, SPBIO[0:3]_0/_1 MSB OUT DATA LSB OUT IDLE<br>Output<br>**----- End of picture text -----**<br>

**Figure 47.48 SDR Transfer Format Transmission and Reception Timing (CPHAT = 1, CPHAR = 1)**

**==> picture [345 x 158] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTD<br>SPBSSL<br>Output<br>tLEAD tLAG<br>SPBCLK<br>CPOL = 0<br>Output<br>SPBCLK<br>CPOL = 1<br>Output<br>tSU tH<br>SPBMI_0/_1,<br>SPBIO[0:3]_0/_1 MSB IN DATA DATA DATA DATA LSB IN<br>Input<br>tBON tOH tOD<br>SPBMO_0/_1,<br>SPBIO[0:3]_0/_1 MSB OUT DATA DATA DATA DATA LSB OUT IDLE<br>Output<br>**----- End of picture text -----**<br>

**Figure 47.49 DDR Transfer Format Transmission and Reception Timing (CPHAT = 0, CPHAR = 0) (RZ/A1LU only)**

**==> picture [345 x 159] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTD<br>SPBSSL<br>Output<br>tLEAD tLAG<br>SPBCLK<br>CPOL = 0<br>Output<br>SPBCLK<br>CPOL = 1<br>Output<br>tSU tH<br>SPBMI_0/_1, SPBIO[0:3]_0/_1 MSB IN DATA DATA DATA DATA LSB IN<br>Input<br>tBON tOH tOD<br>SPBMO_0/_1, SPBIO[0:3]_0/_1 MSB OUT DATA DATA DATA DATA LSB OUT IDLE<br>Output<br>**----- End of picture text -----**<br>

**Figure 47.50 DDR Transfer Format Transmission and Reception Timing (CPHAT = 1, CPHAR = 1) (RZ/A1LU only)**

**==> picture [307 x 92] intentionally omitted <==**

**----- Start of picture text -----**<br>
SPBCLK<br>CPOL = 0<br>Output<br>SPBCLK<br>CPOL = 1<br>Output<br>tBOFF tBON<br>SPBMI_0/_1,<br>SPBIO[0:3]_0/_1<br>Output<br>**----- End of picture text -----**<br>

**Figure 47.51 Timing for Switching the Buffers on and off (CPHAT = 0, CPHAR = 0)**

**==> picture [308 x 85] intentionally omitted <==**

**----- Start of picture text -----**<br>
SPBCLK<br>CPOL = 0<br>Output<br>SPBCLK<br>CPOL = 1<br>Output<br>tBOFF tBON<br>SPBMI_0/_1,<br>SPBIO[0:3]_0/_1<br>Output<br>**----- End of picture text -----**<br>

**Figure 47.52 Timing for Switching the Buffers on and off (CPHAT = 1, CPHAR = 1)**

## 47.4.11 I²C Bus Interface Timing

## **Table 47.15 I[2] C Bus Interface Timing**

|**Table 47.15**<br>**I2C Bus Interface Timing**|||
|---|---|---|
|**Item**<br>**Symbol**|**I/O**|**Standard mode (Sm)**<br>**Fast mode (Fm)**<br>**Unit**<br>**Min.**<br>**Max.**<br>**Min.**<br>**Max.**|
|SCL clock frequency<br>fCLK|I/O|0<br>100<br>0<br>400<br>kHz|
|Bus free time (between stop and<br>start condition)<br>tBUF|I/O|4.7<br>-<br>1.3<br>-<br>μs|
|Hold time*1<br>tHD:STA|I/O|4.0<br>-<br>0.6<br>-<br>μs|
|Low period of SCL clock<br>tLOW|I/O|4.7<br>-<br>1.3<br>-<br>μs|
|High period of SCL clock<br>tHIGH|I/O|4.0<br>-<br>0.6<br>-<br>μs|
|Setup time for start/restart condition<br>tSU:STA|I/O|4.7<br>-<br>0.6<br>-<br>μs|
|Data hold time (I2C bus device)<br>tHD:DAT|I/O|0*2<br>-<br>0*2<br>-<br>μs|
|Data setup time<br>tSU:DAT|I/O|250<br>-<br>100*3<br>-<br>ns|
|SDA and SCL signal rise time<br>tR|Input|-<br>1000<br>20<br>300<br>ns|
|SDA and SCL signal fall time*3<br>tF|Input|-<br>300<br>20 × (PVCC/5.5V)<br>300<br>ns|
||Output|-<br>250<br>20 × (PVCC/5.5V)<br>250<br>ns|
|Setup time for STOP condition<br>tSU:STO|I/O|4.0<br>-<br>0.6<br>-<br>μs|
|Capacitive load for each bus line<br>Cb|-|-<br>400*4<br>-<br>400*4<br>pF|
|Pulse width of spikes that must be<br>suppressed by the input filter<br>tSP|Input|-<br>-<br>0<br>50*5<br>ns|

In the above table and subsequently, SCL and SDA refer to the RIICnSCL and RIICnSDA signals, respectively.

- Note 1. The first clock pulse is generated on the SCL line after the start condition has been issued and the hold time has elapsed. Note 2. This module requires a minimum of 300 ns hold time internally for the SDA signal to handle the period over which the falling edge of SCL has not reached a defined level (time until the SCL signal reaches VIL (max.) from VIH (min.) ).

- Note 3. The fast-mode I[2] C bus device can be used in the standard mode I[2] C bus system. In this case, the minimum value of the data setup time (tSU: DAT 250 [ns]) must be satisfied.

   - If the system does not extend the low period of SCL clock (tLOW), this condition is automatically satisfied. If the system extends the low period of SCL clock (tLOW), transmit the subsequent data bit to the SDA line before the SCL line is released (tRmax. + tSU: DAT = 1000 + 250 = 1250 [ns]: (standard mode I[2] C bus specification)).

- Note 4. Total capacitance of one bus line. The allowable maximum bus capacitance may differ from this specification, depending on the actual operating voltage and frequency of an application. For techniques to cope with a large bus capacitance, see the I[2] C bus specification provided by NXP Semiconductors.

- Note 5. Noise is removed by the analog and digital input filters. The level of noise reduction of the digital input filter is determined by the period of internal reference clock (IICφ) and the NF[1:0] bits in RIICnMR3. For details, refer to section 18, I²C Bus Interface.

**==> picture [335 x 192] intentionally omitted <==**

**----- Start of picture text -----**<br>
tLOW tR tHIGH tF<br>SCL<br>tHD:STA  tHD:DAT  tSU:DAT<br>SDA<br>tBUF<br>P S<br>tSU:STA tHD:STA tSP tSU:STO<br>S:   Start condition<br>P:   Stop condition<br>Sr:  Start condition for retransmission<br>Sr P<br>**----- End of picture text -----**<br>

**Figure 47.53 Input/Output Timing**

## 47.4.12 Serial Sound Interface Timing

## **Table 47.16 Serial Sound Interface Timing**

|**Item**|**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Remarks**<br>**Figure**|
|---|---|---|
|Output clock cycle|tO|80<br>64000<br>ns<br>Output<br>Figure 47.54<br>80<br>64000<br>ns<br>Input<br>32<br>―<br>ns<br>Bidirectional<br>32<br>―<br>ns<br>―<br>25<br>ns<br>Output|
|Input clock cycle|tI||
|Clock high|tHC||
|Clock low|tLC||
|Clock rise time|tRC||
|Delay||–5<br>25<br>ns<br>Figure 47.55,<br>Figure 47.56,<br>Figure 47.57,<br>Figure 47.58,<br>and<br>Figure 47.59<br>10<br>45<br>–5<br>15<br>25<br>―<br>ns<br>5<br>―<br>ns|
|Setup time<br>tSR|||
|Hold time<br>tHTR|||

Note: * For SSIWS delay of the RZ/A1L, refer to the values in the entry on “Delay (Noise canceler not in use)”.

**==> picture [320 x 81] intentionally omitted <==**

**----- Start of picture text -----**<br>
tHC tRC<br>SSISCKn tLC<br>tI ,tO<br>**----- End of picture text -----**<br>

**Figure 47.54 Clock Input/Output Timing**

**==> picture [242 x 167] intentionally omitted <==**

**----- Start of picture text -----**<br>
SSISCKn<br>(Output)<br>SSIDATAn<br>(Input)<br>tSR tHTR<br>SSIWSn, SSIDATAn<br>(Output)<br>tDTR<br>**----- End of picture text -----**<br>

**Figure 47.55 Transmission and Reception Timing (Master, SSICR_n.SCKP = 0)**

**==> picture [242 x 168] intentionally omitted <==**

**----- Start of picture text -----**<br>
SSISCKn<br>(Output)<br>SSIDATAn<br>(Input)<br>tSR tHTR<br>SSIWSn, SSIDATAn<br>(Output)<br>tDTR<br>**----- End of picture text -----**<br>

**Figure 47.56 Transmission and Reception Timing (Master, SSICR_n.SCKP = 1)**

**==> picture [242 x 167] intentionally omitted <==**

**----- Start of picture text -----**<br>
SSISCKn<br>(Input)<br>SSIWSn, SSIDATAn<br>(Input)<br>tSR tHTR<br>SSIDATAn<br>(Output)<br>tDTR<br>**----- End of picture text -----**<br>

**Figure 47.57 Transmission and Reception Timing (Slave, SSICR_n.SCKP = 0)**

**==> picture [242 x 168] intentionally omitted <==**

**----- Start of picture text -----**<br>
SSISCKn<br>(Input)<br>SSIWSn, SSIDATAn<br>(Input)<br>tSR tHTR<br>SSIDATAn<br>(Output)<br>tDTR<br>**----- End of picture text -----**<br>

**Figure 47.58 Transmission and Reception Timing (Slave, SSICR_n.SCKP = 1)**

**==> picture [331 x 150] intentionally omitted <==**

**----- Start of picture text -----**<br>
SSIWSn<br>(Input)<br>SSIDATAn<br>Transmit data (MSB)<br>(Output)<br>tDTR<br>Note:  MSB output timing of when either of the following condition a) or b) is satisfied in slave transmission.<br>a) SSICR_n.DEL = 1, SSICR_n.SDATA = 0<br>b) SSICR_n.DEL = 1, SSICR_n.SDATA = 1, with no padding bit<br>**----- End of picture text -----**<br>

**Figure 47.59 Transmission Timing (Slave, in Synchronization with SSIWSn)**

## 47.4.13 Media Local Bus Timing

This module is only incorporated in the RZ/A1L.

**Table 47.17 Media Local Bus Timing**

|**Item**|**Symbol**|**Min.**|**Typ**|**Max.**|**Unit**|**Remarks**|**Figure**|
|---|---|---|---|---|---|---|---|
|Input clock frequency (256 × FS)|fI|11.2640|12.2880|12.3136|MHz||Figure 47.60|
|Input clock cycle (256 × FS)|tI|―|81|―|ns|||
|Input clock high level (256  × FS)|tHC|30|36.5|―|ns|||
|Input clock low level (256 × FS)|tLC|30|35.5|―|ns|||
|Input clock frequency (512 × FS)|fI|22.5280|24.5760|24.6272|MHz|||
|Input clock cycle (512 × FS)|tI|―|40|―|ns|||
|Input clock high level (512  × FS)|tHC|14|16.5|―|ns|||
|Input clock low level (512 × FS)|tLC|14|16.5|―|ns|||
|Input clock frequency (1024 × FS)|fI|45.0560|49.1520|49.2544|MHz|||
|Input clock cycle (1024 × FS)|tI|―|20.3|―|ns|||
|Input clock high level (1024 × FS)|tHC|9.3|10.2|―|ns|||
|Input clock low level (1024 × FS)|tLC|6.1|7.3|―|ns|||
|Input clock rise time|tRC|―|―|1|ns|VILto VIH||
|Input clock fall time|tFC|―|―|1|ns|VIHto VIL||
|Delay time (clock signal rising)|tDTR|―|―|8.0|ns|Output load:||
|||||||20 pF||
|Delay time (clock signal falling)|tDTF|0|―|tLC|ns|||
|Setup time|tSR|1|―|―|ns|||
|Hold time|tHTR|2|―|―|ns|||

**==> picture [242 x 197] intentionally omitted <==**

**----- Start of picture text -----**<br>
tI<br>tRC tHC tFC<br>tLC<br>MLB_CLK<br>MLB_SIG, MLB_DAT<br>(Input)<br>tSR tHTR<br>MLB_SIG, MLB_DAT<br>(Output)<br>tDTR tDTF<br>**----- End of picture text -----**<br>

**==> picture [139 x 9] intentionally omitted <==**

**----- Start of picture text -----**<br>
Figure 47.60 Interface Timing<br>**----- End of picture text -----**<br>

## 47.4.14 CAN Interface Timing

## **Table 47.18 CAN Interface Timing**

|**Item**|**Symbol**|**Min.**|**Max.**|**Unit**|**Figure**|
|---|---|---|---|---|---|
|Internal delay time|tnode|―|100|ns|Figure 47.61|
|Transmission rate||―|1|Mbps||

Internal delay time (tnode) = Internal transfer delay time (toutput) + Internal receive delay time (tinput)

**==> picture [297 x 127] intentionally omitted <==**

**----- Start of picture text -----**<br>
CAN1TX and CAN0TX pins<br>Internal transfer<br>delay time (toutput)<br>CAN controller<br>Internal receive<br>delay time (tinput)<br>CAN1RX and CAN0RX pins<br>**----- End of picture text -----**<br>

**Figure 47.61 CAN Interface Condition**

## 47.4.15 Ethernet Controller and EthernetAVB Timing

The EthernetAVB is only incorporated in the RZ/A1LU.

## **Table 47.19 Ethernet Controller and EthernetAVB Timing**

|**Item**|**Symbol**|**Min.**|**Max.**|**Unit**|**Figure**|
|---|---|---|---|---|---|
|ET_TXCLK cycle time|tTcyc|40|―|ns|Figure 47.62,|
|ET_TXCLK high level width|tTCKWH|0.35 × tTcyc|―|ns|Figure 47.63,<br>Figure 47.64,|
|ET_TXCLK low level width|tTCKWL|0.35 × tTcyc|―|ns|Figure 47.65, and|
|ET_TXEN output delay time|tTEND|0|25|ns|Figure 47.66|
|ET_TXD[3:0] output delay time|tTDD|0|25|ns||
|ET_RXCLK cycle time|tRcyc|40|―|ns||
|ET_RXCLK high level width|tRCKWH|0.35 × tRcyc|―|ns||
|ET_RXCLK low level width|tRCKWL|0.35 × tRcyc|―|ns||
|ET_RXDV setup time|tRDVS|10|―|ns||
|ET_RXDV hold time|tRDVH|10|―|ns||
|ET_RXD[3:0] setup time|tRDDS|10|―|ns||
|ET_RXD[3:0] hold time|tRDDH|10|―|ns||
|ET_RXER setup time|tRERS|10|―|ns||
|ET_RXER hold time|tRERH|10|―|ns||
|AVB_GPTP_EXTERN cycle time|tGcyc|40|―|ns||
|(RZ/A1LU only)||||||
|AVB_GPTP_EXTERN high level width|tGCKWH|0.35 × tGcyc|―|ns||
|(RZ/A1LU only)||||||
|AVB_GPTP_EXTERN low level width|tGCKWL|0.35 × tGcyc|―|ns||
|(RZ/A1LU only)||||||
|AVB_CAPTURE high level width|tCAPWH|2 × tCcyc*|―|ns||
|(RZ/A1LU only)||||||

Note: * This is the cycle time of the clock selected by the CSEL bit in the AVB-DMAC mode register (CCC).

**==> picture [483 x 188] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTcyc<br>tTCKWH tTCKWL<br>ET_TXCLK<br>tRcyc<br>tRCKWH tRCKWL<br>ET_RXCLK<br>Figure 47.62 MII Clock Timing<br>**----- End of picture text -----**<br>

**==> picture [234 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
ET_TXCLK<br>tTEND<br>ET_TXEN<br>tTDD<br>ET_TXD[3:0]<br>**----- End of picture text -----**<br>

**Figure 47.63 MII Transmit Data Timing**

**==> picture [234 x 236] intentionally omitted <==**

**----- Start of picture text -----**<br>
ET_RXCLK<br>tRDVS tRDVH<br>ET_RXDV<br>tRDDS tRDDH<br>ET_RXD[3:0]<br>tRERS tRERH<br>ET_RXER<br>**----- End of picture text -----**<br>

**Figure 47.64 MII Receive Data Timing**

**==> picture [336 x 112] intentionally omitted <==**

**----- Start of picture text -----**<br>
tGcyc<br>tGCKWH tGCKWL<br>AVB_GPTP_EXTERN<br>**----- End of picture text -----**<br>

**Figure 47.65 gPTP Timer External Clock Timing**

**==> picture [334 x 71] intentionally omitted <==**

**----- Start of picture text -----**<br>
tCAPWH<br>AVB_CAPTURE<br>**----- End of picture text -----**<br>

**Figure 47.66 Timer Capture Signal Timing**

## 47.4.16 A/D Converter Timing

## **Table 47.20 A/D Converter Timing**

|**Table 47.20**<br>**A/D Converter Timing**||
|---|---|
|**Module**<br>**Item**<br>**Symbol**|**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|A/D converter<br>Trigger input setup time<br>tTRGS|17<br>―<br>ns<br>Figure 47.67|
|||
|CKIO<br>ADTRG|tTRGS|

**Figure 47.67 A/D Converter External Trigger Input Timing**

## 47.4.17 USB 2.0 Host/Function Module Timing

## **Table 47.21 USB Transceiver Timing (Low-Speed)**

|**Item**|**Symbol**|**Min.**|**Max.**|**Unit**|**Figure**|
|---|---|---|---|---|---|
|Rise time|tLR|75|300|ns|Figure 47.68|
|Fall time|tLF|75|300|ns||
|Rise/fall time lag|tLR/tLF|80|125|%||

|||||90%|90%||||
|---|---|---|---|---|---|---|---|---|
|DP, DM|10%|||||||10%|
||tLR|||||tLF|||

**Figure 47.68 DP1, DP0, DM1, and DM0 Output Timing (Low-Speed)**

**==> picture [211 x 153] intentionally omitted <==**

**----- Start of picture text -----**<br>
PVCC<br>DP<br>CL = 200 pF to 600 pF PVCC<br>Measurement<br>circuit<br>RL = 1.5 kΩ<br>DM<br>CL = 200 pF<br> to 600 pF<br>VSS<br>The electric capacitance (CL) includes<br>the stray capacitance of connection<br>and the input capacitance of probe.<br>**----- End of picture text -----**<br>

**Figure 47.69 Measurement Circuit (Low-Speed)**

**Table 47.22 USB Transceiver Timing (Full-Speed)**

|**Item**|**Symbol**|**Min.**|**Min.**|||**Max.**||||**Unit**|**Figure**|
|---|---|---|---|---|---|---|---|---|---|---|---|
|Rise time|tFR|4||||20||||ns|Figure 47.70|
|Fall time|tFF|4||||20||||ns||
|Rise/fall time lag|tFR/tFF|90||||111.11||||%||
|||||||||||||
|||||||||||||
||||||90%|90%||||||
||DP, DM|10%|||||||10%|||
|||tFR|||||tFF|||||

**Figure 47.70 DP1, DP0, DM1, and DM0 Output Timing (Full-Speed)**

**==> picture [313 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
USBDPVCC* [1]<br>DP<br>CL = 50 pF<br>Measurement<br>circuit<br>DM<br>CL = 50 pF The electric capacitance (CL) includes<br>the stray capacitance of connection<br>USBDPVSS* [2] and the input capacitance of probe.<br>Note 1.  The PVcc pin is used in the  products in BGA packages.<br>Note 2.  The Vss pin is used in the  products in BGA packages.<br>**----- End of picture text -----**<br>

**Figure 47.71 Measurement Circuit (Full-Speed)**

**Table 47.23 USB Transceiver Timing (High-Speed)**

|**Item**|**Symbol**|**Min.**|**Min.**|||**Max.**||||**Unit**|**Figure**|
|---|---|---|---|---|---|---|---|---|---|---|---|
|Rise time|tHSR|500||||―||||ps|Figure 47.72|
|Fall time|tHSF|500||||―||||ps||
|Output driver resistance|ZHSDRV|40.5||||49.5||||||
|||||||||||||
|||||||||||||
||||||90%|90%||||||
||DP, DM|10%|||||||10%|||
|||tHSR|||||tHSF|||||

**Figure 47.72 DP1, DP0, DM1, and DM0 Output Timing (High-Speed)**

**==> picture [200 x 164] intentionally omitted <==**

**----- Start of picture text -----**<br>
USBDPVCC* [1]<br>DP<br>RL = 45Ω<br>Measurement<br>circuit<br>DM<br>RL = 45Ω<br>USBDPVSS* [2]<br>Note 1.  The PVcc pin is used in the  products in BGA packages.<br>Note 2.  The Vss pin is used in the  products in BGA packages.<br>**----- End of picture text -----**<br>

**Figure 47.73 Measurement Circuit (High-Speed)**

## 47.4.18 Video Display Controller 5 Timing

**Table 47.24 Video Display Controller 5 Timing**

|**Item**|**Symbol**|**Min.**|**Max.**|**Unit**|**Figure**|
|---|---|---|---|---|---|
|DV0_CLK input clock frequency|tDcyc|―|87.00|MHz|Figure 47.74|
|DV0_CLK input clock low pulse width|tWIL|0.4|―|tDcyc||
|DV0_CLK input clock high pulse width|tWIH|0.4|―|||
|CD0_EXTCLK input clock frequency|tEcyc|―|87.00|MHz||
|LCD0_EXTCLK input clock low pulse width|tWIL|0.4|―|tEcyc||
|LCD0_EXTCLK input clock high pulse width|tWIH|0.4|―|||
|LCD0_CLK output clock frequency|tLcyc|―|87.00|MHz|Figure 47.75|
|LCD0_CLK clock output low pulse width*1|tLOL|tWIL- 0.95|tWIL+ 0.95|ns||
|LCD0_CLK clock output high pulse width*1|tLOH|tWIH- 0.95|tWIH+ 0.95|ns||
|LCD0_CLK clock output low pulse width*2|tLOL|tLcyc/2 - 1.06|tLcyc/2 + 1.06|ns||
|LCD0_CLK clock output high pulse width*2|tLOH|tLcyc/2 - 1.06|tLcyc/2 + 1.06|ns||
|LCD0_CLK clock output rise time|tLOR|―|3|ns||
|LCD0_CLK clock output fall time|tLOF|―|3|ns||
|Input data setup time|tVS|2|―|ns|Figure 47.76|
|Input data hold time|tVH|4|―|ns||
|Output data delay time|tDD|–3|3|ns|Figure 47.77|

Note 1. This is the case when the video image clock or an external clock is selected as the clock for frequency division and the division ratio is set to 1/1. Note 2. This is for cases other than when the video image clock or an external clock is selected as the clock for frequency division and the division ratio is set to 1/1.

**==> picture [239 x 69] intentionally omitted <==**

**----- Start of picture text -----**<br>
tDcyc, tEcyc<br>tWH tWL<br>DV_CLK,<br>LCD_EXTCLK VIH VIH<br>1/2 PVcc<br>VIL VIL<br>**----- End of picture text -----**<br>

**Figure 47.74 DV0_CLK and LCD0_EXTCLK Clock Input Timing**

**==> picture [32 x 8] intentionally omitted <==**

**----- Start of picture text -----**<br>
LCD_CLK<br>**----- End of picture text -----**<br>

**==> picture [96 x 84] intentionally omitted <==**

**----- Start of picture text -----**<br>
tLcyc<br>tLOL tLOH<br>tLOF tLOR<br>**----- End of picture text -----**<br>

**Figure 47.75 LCD0_CLK Clock Output Timing**

**==> picture [380 x 144] intentionally omitted <==**

**----- Start of picture text -----**<br>
DV_CLK<br>tVS tVH<br>Latched at<br>rising edge<br>DV_DATA23 to<br>DV_DATA0,  tVS tVH<br>DV_VSYNC,<br>DV_HSYNC<br>Latched at<br>falling edge<br>**----- End of picture text -----**<br>

**Figure 47.76 Video Input Timing**

**==> picture [386 x 143] intentionally omitted <==**

**----- Start of picture text -----**<br>
LCD_CLK<br>tDD<br>Output at<br>falling edge<br>LCD_DATA23 to<br>LCD_DATA0,  tDD<br>LCD_TCON6 to<br>LCD_TCON0<br>Output at<br>rising edge<br>**----- End of picture text -----**<br>

**Figure 47.77 Display Output Timing**

## 47.4.19 Capture Engine Unit Module Signal Timing

## **Table 47.25 Capture Engine Unit Module Signal Timing**

|**Item**|**Symbol**|**Min.**|**Max.**|**Unit**|**Figure**|
|---|---|---|---|---|---|
|Vertical sync (VIO_VD) setup time (when data|tVVDS|2|―|ns|Figure 47.78 (1) and|
|is captured at the rising edges of the camera|||||Figure 47.78 (2)|
|clock)||||||
|Vertical sync (VIO_VD) setup time (when data|tVVDS|2.5|―|ns||
|is captured at the falling edges of the camera||||||
|clock) (RZ/A1LU and RZ/A1LC only)||||||
|Vertical sync (VIO_VD) hold time|tVVDH|3.5|―|ns||
|Horizontal sync (VIO_HD) setup time (when|tVHDS|2|―|ns||
|data is captured at the rising edges of the||||||
|camera clock)||||||
|Horizontal sync (VIO_HD) setup time (when|tVHDS|2.5|―|ns||
|data is captured at the falling edges of the||||||
|camera clock) (RZ/A1LU and RZ/A1LC only)||||||
|Horizontal sync (VIO_HD) hold time|tVHDH|3.5|―|ns||
|Capture image data (VIO_D) setup time (when|tVDTS|2|―|ns||
|data is captured at the rising edges of the||||||
|camera clock)||||||
|Capture image data (VIO_D) setup time (when|tVDTS|2.5|―|ns||
|data is captured at the falling edges of the||||||
|camera clock) (RZ/A1LU and RZ/A1LC only)||||||
|Capture image data (VIO_D) hold time|tVDTH|3.5|―|ns||
|Camera clock cycle|tVCYC|―|87|MHz||
|Camera clock high level|tVHW|0.4tVCYC|―|ns||
|Camera clock low level|tVLW|0.4tVCYC|―|ns||
|Field identification signal (VIO_FLD) setup time|tVFDS|2|―|ns||
|(when data is captured at the rising edges of||||||
|the camera clock)||||||
|Field identification signal (VIO_FLD) setup time|tVFDS|2.5|―|ns||
|(when data is captured at the falling edges of||||||
|the camera clock) (RZ/A1LU and RZ/A1LC||||||
|only)||||||
|Field identification signal (VIO_FLD) hold time|tVFDH|3.5|―|ns||

**==> picture [183 x 265] intentionally omitted <==**

**----- Start of picture text -----**<br>
tVCYC<br>tVLW tVHW<br>VIO_CLK<br>VIO_VD tVVDS tVVDH<br>VIO_HD tVHDS tVHDH<br>tVDTS tVDTH<br>VIO_D7 to<br>VIO_D0<br>tVFDS tVFDH<br>VIO_FLD<br>**----- End of picture text -----**<br>

**Figure 47.78 (1) Capture Engine Unit Module Signal Timing when Data is Captured at the Rising Edges of VIO_CLK**

**==> picture [184 x 266] intentionally omitted <==**

**----- Start of picture text -----**<br>
tVCYC<br>tVHW tVLW<br>VIO_CLK<br>VIO_VD tVVDS tVVDH<br>VIO_HD tVHDS tVHDH<br>tVDTS tVDTH<br>VIO_D7 to<br>VIO_D0<br>tVFDS tVFDH<br>VIO_FLD<br>**----- End of picture text -----**<br>

**Figure 47.78 (2) Capture Engine Unit Module Signal Timing when Data is Captured at the Falling Edge of VIO_CLK (RZ/A1LU and RZ/A1LC Only)**

## 47.4.20 SD Host Interface Timing

## **Table 47.26 SD Host Interface Timing**

|**Table 47.26**<br>**SD Host Interface Timing**||||||
|---|---|---|---|---|---|
|**Item**|**Symbol**|**Min.**|**Max.**|**Unit**|**Figure**|
|SD_CLK  clock cycle|tSDPP|2 × tp1cyc|―|ns|Figure|
|SD_CLK clock high level width|tSDWH|0.4 × tSDPP|―|ns|47.79|
|SD_CLK clock low level width|tSDWL|0.4 × tSDPP|―|ns||
|SD_CLK clock rise time|tSDLH|―|3|ns||
|SD_CLK clock fall time|tSDHL|―|3|ns||
|SD_CMD, SD_D3 to SD_D0 output data delay time (data transfer|tSDODLY|―|4|ns||
|mode)||||||
|SD_CMD, SD_D3 to SD_D0 input data setup time|tSDISU|5|―|ns||
|SD_CMD, SD_D3 to SD_D0 input data hold time|tSDIH|2|―|ns||

Note: • tp1cyc indicates peripheral clock 1 (P1) cycle.

**==> picture [270 x 208] intentionally omitted <==**

**----- Start of picture text -----**<br>
tSDPP<br>tSDWL tSDWH<br>SD_CLK<br>tSDHL tSDLH<br>tSDISU tSDIH<br>SD_CMD,<br>SD_D3 to SD_D0 Input<br>SD_CMD,<br>SD_D3 to SD_D0 Output<br>tSDODLY (max) tSDODLY (min)<br>**----- End of picture text -----**<br>

**Figure 47.79 SD Host Interface**

## 47.4.21 MMC Host Interface Timing

## **Table 47.27 MMC Host Interface Timing**

|**Item**|**Symbol**|**Min.**|**Max.**|**Unit**|**Figure**|
|---|---|---|---|---|---|
|MMC_CLK clock cycle|tMMCPP|2tp1cyc|―|ns|Figure 47.80|
|MMC_CLK clock high level width|tMMCWH|6.5|―|ns||
|MMC_CLK clock low level width|tMMCWL|6.5|―|ns||
|MMC_CLK clock rise time|tMMCLH|―|3|ns||
|MMC_CLK clock fall time|tMMCHL|―|3|ns||
|MMC_CMD, MMC_D7 to MMC_D0|tMMCODLY|– 6.5|6.5|ns||
|output data delay time (data transfer mode)||||||
|MMC_CMD, MMC_D7 to MMC_D0|tMMCISU|4.5|―|ns||
|input data setup time||||||
|MMC_CMD, MMC_D7 to MMC_D0|tMMCIH|2|―|ns||
|input data hold time||||||

Note: • tp1cyc indicates peripheral clock 1 (P1) cycle.

**==> picture [270 x 207] intentionally omitted <==**

**----- Start of picture text -----**<br>
tMMCPP<br>tMMCWL tMMCWH<br>MMC_CLK<br>tMMCHL tMMCLH<br>tMMCISU tMMCIH<br>MMC_CMD,<br>MMC_D7 to MMC_D0 Input<br>MMC_CMD,<br>MMC_D7 to MMC_D0 Output<br>tMMCODLY (max) tMMCODLY (min)<br>**----- End of picture text -----**<br>

**Figure 47.80**

**MMC Interface**

## 47.4.22 General Purpose I/O Ports Timing

## **Table 47.28 General Purpose I/O Ports Timing**

|**Table 47.28**<br>**General Purpose I/O Ports Timing**|**Table 47.28**<br>**General Purpose I/O Ports Timing**|||
|---|---|---|---|
|**Item**<br>**Symbol**|||**Min.**<br>**Max.**<br>**Unit**<br>**Figure**|
|Output data delay time<br>tPORTD|||―<br>100<br>ns<br>Figure 47.81<br>100<br>―<br>100<br>―|
|Input data setup time<br>tPORTS||||
|Input data hold time<br>tPORTH||||
|||||
|CKIO<br>Port<br>(read)<br>Port<br>(write)|||tPORTH<br>tPORTD|
||||tPORTH|
|||||
|||||
|||||
|||||
|||||

**Figure 47.81 General I/O Ports Timing**

## 47.4.23 Debugger Interface Timing

## **Table 47.29 Debugger Interface Timing**

|**Item**|**Symbol**|**Min.**|**Max.**|**Unit**|**Figure**|
|---|---|---|---|---|---|
|TCK cycle time|tTCKcyc|50*1|―|ns|Figure 47.82|
|TCK high pulse width|tTCKH|0.4|0.6|tTCKcyc||
|TCK low pulse width|tTCKL|0.4|0.6|tTCKcyc||
|TDI setup time|tTDIS|10|―|ns|Figure 47.83|
|TDI hold time|tTDIH|10|―|ns||
|TMS/SWDIO setup time|tTMSS|10|―|ns||
|TMS/SWDIO hold time|tTMSH|10|―|ns||
|SWDIO delay time|tSWDO|―|16|ns||
|TDO delay time|tTDOD|―|16|ns||
|Capture register setup time|tCAPTS|10|―|ns|Figure 47.84|
|Capture register hold time|tCAPTH|10|―|ns||
|Update register delay time|tUPDATED|―|20|ns||
|Trace clock cycle|tTCYC|30*2|―|ns|Figure 47.85|
|Trace clock high level|tTHC|12|―|ns|Output load:<br>15 pF|
|Trace clock low level|tTLC|12|―|ns||
|Trace data delay time|tTDT|3|0.3tTCYC+ 3|ns||

Note 1. Should be greater than the peripheral clock 0 (P0) cycle time.

Note 2. Generated by dividing the frequency of the peripheral clock (P1) by 2.

**==> picture [313 x 80] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTCKcyc<br>tTCKH tTCKL<br>VIH<br>VIH VIH<br>1/2 PVcc 1/2 PVcc<br>VIL VIL<br>**----- End of picture text -----**<br>

**Figure 47.82 TCK Input Timing**

**==> picture [286 x 207] intentionally omitted <==**

**----- Start of picture text -----**<br>
tTCKcyc<br>TCK<br>tTDIS tTDIH<br>TDI<br>tTMSS tTMSH<br>TMS/SWDIO<br>(input)<br>tSWDO<br>SWDIO<br>(output)<br>tTDOD<br>TDO<br>**----- End of picture text -----**<br>

**Figure 47.83 Data Transfer Timing**

**==> picture [483 x 409] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCK<br>tCAPTS tCAPTH<br>Capture<br>register<br>tUPDATED<br>Update<br>register<br>Figure 47.84 Boundary Scan Input/Output I/O Timing<br>tTCYC<br>tTHC tTLC<br>Trace_Clk<br>Trace_Ctrl, Trace_Datan<br>(Output)<br>tTDT tTDT<br>**----- End of picture text -----**<br>

**Figure 47.85 Trace Interface Timing**

## 47.4.24 AC Characteristics Measurement Conditions

- I/O signal reference level: PVCC/2, the minimum values of VIH, VT+, and VOH, and the maximum values of VIL, VT-, and VOL (refer to the individual timing chart)

- Input pulse level: PVCC

- Input rise and fall times: 1 ns

**==> picture [231 x 114] intentionally omitted <==**

**----- Start of picture text -----**<br>
LSI output pin Measurement point<br>CL<br>CMOS output<br>Note: CL is the total value that includes the capacitance of measurement<br>tools.<br>CL = 30 pF<br>**----- End of picture text -----**<br>

**Figure 47.86 Output Load Circuit**

## 47.5 A/D Converter Characteristics

Conditions: VCC = USBDVCC = USBUVCC = 1.10 to 1.26 V, PVCC = USBDPVCC = 3.0 to 3.6 V, PLLVCC = 1.10 to 1.26 V, AVCC = 3.0 to 3.6 V, USBAPVCC = 3.0 to 3.6 V, USBAVCC = 1.10 to 1.26 V, VSS = AVSS = USBDVSS = USBAVSS = USBDPVSS = USBAPVSS = USBUVSS = 0 V, Ta = –40 to 85  C

Note: Products in BGA packages do not have USBDVCC, USBUVCC, USBDPVCC, USBDVSS, USBAVSS, USBDPVSS, USBAPVSS, and USBUVSS pins.

## **Table 47.30 A/D Converter Characteristics**

|**Table 47.30**<br>**A/D**|**Converter Characteristics**|
|---|---|
|**Item**|**Min.**<br>**Typ.**<br>**Max.**<br>**Unit**|
|Resolution|12<br>12<br>12<br>bits|
|Conversion time|12-bit<br>5<br>―<br>―<br>s<br>10-bit|
|Analog input capacitance<br>―<br>―<br>20<br>pF||
|Permissible signal-source impedance<br>―<br>―<br>3<br>k||
|DNL|12-bit<br>―<br>―<br>1.0<br>LSB|
||10-bit<br>―<br>―<br>1.0<br>LSB|
|INL|12-bit<br>―<br>―<br>4.0<br>LSB|
||10-bit<br>―<br>―<br>4.0<br>LSB|
|Offset error|12-bit<br>―<br>―<br>8.0<br>LSB|
||10-bit<br>―<br>―<br>2.0<br>LSB|
|Full-scale error|12-bit<br>―<br>―<br>8.0<br>LSB|
||10-bit<br>―<br>―<br>2.0<br>LSB|
|Absolute accuracy|12-bit<br>―<br>―<br>11.0<br>LSB|
||10-bit<br>―<br>―<br>5.0<br>LSB|
