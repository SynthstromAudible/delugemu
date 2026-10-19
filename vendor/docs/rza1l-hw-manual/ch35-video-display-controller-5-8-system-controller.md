# 35. Video Display Controller 5 (8):System Controller

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1903–1915. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 35.1 System Controller

## 35.1.1 Overview of Functions

The system controller provides interrupt control, panel clock control, CLUT table read select signal status flag output functions.

## 35.1.2 Interrupt Control

Ten interrupt signals are output from the scaler and image synthesizer. The system controller controls whether to output these interrupt signals.

One is written to the corresponding INT_STA* bit when an interrupt signal is to be accepted. After 1 has been written to the bit, however, its value is still read out as 0 until the interrupt signal is accepted. Once the interrupt signal has been accepted, the INT_STA* bit is read out as 1.

The bit for an accepted interrupt signal is cleared by writing 0 to the INT_STA* bit. If further interrupt signals are to be accepted after the INT_STA* bit has been cleared, 1 is again written to the bit.

**Table 35.1 Interrupt Signals**

|**Request Source Name**|**Bit Name**|**Function**|
|---|---|---|
|S0_VI_VSYNC|INT_STA 0|Vsync signal input to scaler 0|
|S0_LO_VSYNC|INT_STA 1|Vsync signal output from scaler 0|
|S0_VSYNCERR|INT_STA 2|Missing Vsync signal for scaler 0|
|GR3_VLINE|INT_STA 3|Specified line signal for panel output in graphics 3|
|S0_VFIELD|INT_STA 4|Field end signal for recording function in scaler 0|
|IV1_VBUFERR|INT_STA 5|Frame buffer write overflow signal for scaler 0|
|IV3_VBUFERR|INT_STA 6|Frame buffer read underflow signal for graphics 0|
|IV5_VBUFERR|INT_STA 7|Frame buffer read underflow signal for graphics 2|
|IV6_VBUFERR|INT_STA 8|Frame buffer read underflow signal for graphics 3|
|S0_WLINE|INT_STA 9|Write specification line signal input to scaling-down control block in scaler 0|
|||(This signal is not present in this product.)|

**Table 35.2 Interrupt Clear/Hold Settings**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SYSCNT_INT1|INT_STA0|0|S0_VI_VSYNC Interrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT1|INT_STA1|0|S0_LO_VSYNC Interrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT1|INT_STA2|0|S0_VSYNCERR Interrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT1|INT_STA3|0|GR3_VLINE Interrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT1|INT_STA4|0|S0_VFIELDInterrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT1|INT_STA5|0|IV1_VBUFERR Interrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT1|INT_STA6|0|IV3_VBUFERR Interrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT1|INT_STA7|0|IV5_VBUFERR Interrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT2|INT_STA8|0|IV6_VBUFERR Interrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance.|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|
|SYSCNT_INT2|INT_STA9|0|S0_WLINEInterrupt Clear/Hold|
||||0(W): Clears the interrupt status.|
||||1(W): Starts interrupt acceptance. (Setting prohibited in this|
||||product)|
||||0(R): No interrupt has occurred.|
||||1(R): An interrupt has occurred.|

**Table 35.3 Interrupt Output On/Off Settings**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SYSCNT_INT4|INT_OUT0_ON|0|S0_VI_VSYNC Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT4|INT_OUT1_ON|0|S0_LO_VSYNC Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT4|INT_OUT2_ON|0|S0_VSYNCERR Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT4|INT_OUT3_ON|0|GR3_VLINE Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT4|INT_OUT4_ON|0|S0_VFIELD Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT4|INT_OUT5_ON|0|IV1_VBUFERR Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT4|INT_OUT6_ON|0|IV3_VBUFERR Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT4|INT_OUT7_ON|0|IV5_VBUFERR Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT5|INT_OUT8_ON|0|IV6_VBUFERR Interrupt Output On/Off|
||||0: Off|
||||1: On|
|SYSCNT_INT5|INT_OUT9_ON|0|S0_WLINE Interrupt Output On/Off|
||||0: Off|
||||1: On (Setting prohibited in this product)|

## 35.1.3 Panel Clock Control

The video image clock, external clock, or peripheral clock 1 is selectable as the source of the panel clock for supply to this module. The module is also equipped with a divider for scaling the frequency by factors from 1/1 to 1/32. The bits listed in Table 35.4 control the panel clock.

## **Table 35.4 Panel Clock Control**

|||**Initial**||
|---|---|---|---|
|**Register Name**|**Bit Name**|**Value**|**Description**|
|SYSCNT_PANEL_CLK|PANEL_ICKSEL|0|Divided Clock Source Select|
||[1:0]||0: Video image clock (this is DV_CLK if INP_SEL = 1)|
||||1: External clock (LCD0_EXTCLK)|
||||2:Setting prohibited|
||||3: Peripheral clock 1 (P1φ)|
|SYSCNT_PANEL_CLK|PANEL_ICKEN|0|Panel Clock Operation Enable|
||||0: Disables operation of the panel clock operation block.|
||||1: Enables operation of the panel clock operation block.|
||||Note: Set this bit to 0 before changing the value of the|
||||PANEL_ICKSEL or PANEL_DCDR bits.|
|SYSCNT_PANEL_CLK|PANEL_DCDR|1|Clock Frequency Division Ratio|
||[5:0]||Refer to Table 35.5 for details on the settings.|
||||Note: Settings other than those in Table 35.5 are prohibited.|

**Table 35.5 I/O Clock Frequency and Divisors**

|**Table 35.5**<br>**I/O Clock Frequency and Divisors**||
|---|---|
|**DCDR[5:0]**<br>**Clock Ratio**|**I/O Clock Frequency (MHz)**|
||**27.00**<br>**54.00**<br>**66.67**|
|000001<br>1/1|27.00<br>54.00<br>66.67|
|000010<br>1/2|13.50<br>27.00<br>33.33|
|000011<br>1/3|9.00<br>18.00<br>22.22|
|000100<br>1/4|6.75<br>13.50<br>16.67|
|000101<br>1/5|5.40<br>10.80<br>13.33|
|000110<br>1/6|4.50<br>9.00<br>11.11|
|000111<br>1/7|3.86<br>7.71<br>9.52|
|001000<br>1/8|3.38<br>6.75<br>8.33|
|001001<br>1/9|3.00<br>6.00<br>7.41|
|001100<br>1/12|2.25<br>4.50<br>5.56|
|010000<br>1/16|1.69<br>3.38<br>4.17|
|011000<br>1/24|1.13<br>2.25<br>2.78|
|100000<br>1/32|0.84<br>1.69<br>2.08|

## 35.1.4 CLUT Table Read Select Signal Status Flag

The CLUT read select signal status can be read using the flags shown in Table 35.6 .

## **Table 35.6 CLUT Table Read Select Signal Status Flags**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SYSCNT_CLUT|GR0_CLT_SEL_ST|—|Graphics 0 CLUT Table Read Select Signal Status Flag|
||||0: CLUT table 0 is read out.|
||||1: CLUT table 1 is read out.|
|SYSCNT_CLUT|GR2_CLT_SEL_ST|—|Graphics 2 CLUT Table Read Select Signal Status Flag|
||||0: CLUT table 0 is read out.|
||||1: CLUT table 1 is read out.|
|SYSCNT_CLUT|GR3_CLT_SEL_ST|—|Graphics 3 CLUT Table Read Select Signal Status Flag|
||||0: CLUT table 0 is read out.|
||||1: CLUT table 1 is read out.|

## 35.2 Register Descriptions

The following register sets are allocated in the SH register map area.

- Symbols used in Register Descriptions

   - Initial value: Register value after a reset

   - —: Undefined value R/W: Readable/writable. The written value can be read. R/WC0: Readable/writable. Writing 0 initializes the bit. Writing 1 is ignored. R/WC1: Readable/writable. Writing 1 initializes the bit. Writing 0 is ignored. R: Read-only. The write value should always be 0. —/W: Write-only. The read value is undefined.

**Table 35.7 Register Configuration of System Controller (CH0)**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Interrupt control register 1|SYSCNT_INT1|R/W|H'0000 0000|H'FCFF 7A80|32|
|Interrupt control register 2|SYSCNT_INT2|R/W|H'0000 0000|H'FCFF 7A84|32|
|Interrupt control register 4|SYSCNT_INT4|R/W|H'0000 0000|H'FCFF 7A8C|32|
|Interrupt control register 5|SYSCNT_INT5|R/W|H'0000 0000|H'FCFF 7A90|32|
|Panel clock control register|SYSCNT_PANEL_CLK|R/W|H'0001|H'FCFF 7A98|16|
|CLUT table read select signal|SYSCNT_CLUT|R|H'0000|H'FCFF 7A9A|16|
|status register||||||

## 35.2.1 Interrupt Control Register 1 (SYSCNT_INT1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||INT_||||INT_||||INT_||||INT_||
||—|—|—|STA7|—|—|—|STA6|—|—|—|STA5|—|—|—|STA4||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||INT_||||INT_||||INT_||||INT_||
||—|—|—|STA3|—|—|—|STA2|—|—|—|STA1|—|—|—|STA0||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 29|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|28|INT_STA7|0|R/W|IV5_VBUFERR Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|
|27 to 25|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|24|INT_STA6|0|R/W|IV3_VBUFERR Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|
|23 to 21|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|20|INT_STA5|0|R/W|IV1_VBUFERR Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|
|19 to 17|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|16|INT_STA4|0|R/W|S0_VFIELD Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|
|15 to 13|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|12|INT_STA3|0|R/W|GR3_VLINE Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|
|11 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|INT_STA2|0|R/W|S0_VSYNCERR Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|INT_STA1|0|R/W|S0_LO_VSYNC Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|INT_STA0|0|R/W|S0_VI_VSYNC Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|

## 35.2.2 Interrupt Control Register 2 (SYSCNT_INT2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||INT_||||INT_||
||—|—|—|—|—|—|—|—|—|—|—|STA9|—|—|—|STA8||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|INT_STA9|0|R/W|S0_WLINE Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance. (Setting prohibited in this product)|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|INT_STA8|0|R/W|IV6_VBUFERR Interrupt Clear/Hold|
|||||0(W): Clears the interrupt status.|
|||||1(W): Starts interrupt acceptance.|
|||||0(R): No interrupt has occurred.|
|||||1(R): An interrupt has occurred.|

## 35.2.3 Interrupt Control Register 4 (SYSCNT_INT4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||INT_||||INT_||||INT_||||INT_||
||—|—|—|OUT7_|—|—|—|OUT6_|—|—|—|OUT5_|—|—|—|OUT4_||
|||||ON||||ON||||ON||||ON||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||INT_||||INT_||||INT_||||INT_||
||—|—|—|OUT3_|—|—|—|OUT2_|—|—|—|OUT1_|—|—|—|OUT0_||
|||||ON||||ON||||ON||||ON||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 29|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|28|INT_OUT7_ON|0|R/W|IV5_VBUFERR Interrupt Output On/Off|
|||||0: Off|
|||||1: On|
|27 to 25|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|24|INT_OUT6_ON|0|R/W|IV3_VBUFERR Interrupt Output On/Off|
|||||0: Off|
|||||1: On|
|23 to 21|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|20|INT_OUT5_ON|0|R/W|IV1_VBUFERR Interrupt Output On/Off|
|||||0: Off|
|||||1: On|
|19 to 17|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|16|INT_OUT4_ON|0|R/W|S0_VFIELD Interrupt Output On/Off|
|||||0: Off|
|||||1: On|
|15 to 13|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|12|INT_OUT3_ON|0|R/W|GR3_VLINE Interrupt Output On/Off|
|||||0: Off|
|||||1: On|
|11 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|INT_OUT2_ON|0|R/W|S0_VSYNCERR Interrupt Output On/Off|
|||||0: Off|
|||||1: On|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|INT_OUT1_ON|0|R/W|S0_LO_VSYNC Interrupt Output On/Off|
|||||0: Off|
|||||1: On|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|INT_OUT0_ON|0|R/W|S0_VI_VSYNC Interrupt Output On/Off|
|||||0: Off|
|||||1: On|

## 35.2.4 Interrupt Control Register 5 (SYSCNT_INT5)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||INT_||||INT_||
||—|—|—|—|—|—|—|—|—|—|—|OUT9_|—|—|—|OUT8_||
|||||||||||||ON||||ON||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|INT_OUT9_ON|0|R/W|S0_WLINE Interrupt Output On/Off|
|||||0: Off|
|||||1: On (Setting prohibited in this product)|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|INT_OUT8_ON|0|R/W|IV6_VBUFERR Interrupt Output On/Off|
|||||0: Off|
|||||1: On|

## 35.2.5 Panel Clock Control Register (SYSCNT_PANEL_CLK)

|||Bit:|15|14||13||12|11||10|9|8<br>7<br>6<br>5<br>4|3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|—||-<br>PANEL_ICKSEL<br>[1:0]|||—||—|—|PANEL_<br>ICKEN<br>—<br>-<br>—<br>-|-<br>-<br>-<br>PANEL_DCDR[5:0]|||
||Initial|value:|0|0||0||0|0||0|0|0<br>0<br>0<br>0<br>0|0<br>0<br>0|1||
|||R/W:|R|R||R/W||R/W|R||R|R|R/W<br>R<br>R<br>R/W<br>R/W|R/W<br>R/W<br>R/W|R/W||
|**Bit**||**Bit Name**|||||**Initial Value**|||**R/W**|||**Description**||||
|15, 14||—|||||All 0|||R|||Reserved||||
||||||||||||||These bits are always read as 0. The write value should always be 0.||||
|13, 12||PANEL_ICKSEL|||||All 0|||R/W|||Divided Clock Source Select||||
|||[1:0]|||||||||||0: Video image clock (this is DV_CLK if INP_SEL = 1)||||
||||||||||||||1: External clock (LCD0_EXTCLK)||||
||||||||||||||2: Setting prohibited||||
||||||||||||||3: Peripheral clock 1 (P1φ)||||
|11 to 9||—|||||0|||R|||Reserved||||
||||||||||||||These bits are always read as 0. The write value should always be 0.||||
|8||PANEL_|||||0|||R/W|||Panel Clock Operation Enable||||
|||ICKEN|||||||||||0: Disables operation of the panel clock operation block.||||
||||||||||||||1: Enables operation of the panel clock operation block.||||
||||||||||||||Note: Set this bit to 0 before changing the value of the||||
||||||||||||||PANEL_ICKSEL or PANEL_DCDR bits.||||
|7,|6|—|||||All 0|||R|||Reserved||||
||||||||||||||These bits are always read as 0. The write value should always be 0.||||
|5 to 0||PANEL_|||||1|||R/W|||Clock Frequency Division Ratio||||
|||DCDR[5:0]|||||||||||Refer to Table 35.5 for details on the settings.||||
||||||||||||||Note: Settings other than those in Table 35.5 are prohibited.||||

## 35.2.6 CLUT Table Read Select Signal Status Register (SYSCNT_CLUT)

||Bit:|15|14|13|||12|11||10|9|8<br>7<br>6<br>5|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||GR3_CLT||||||GR2_CLT|||||GR0_CLT||
|||—|—|—||_SEL_ST||—||—|—|_SEL_ST<br>—<br>—<br>—|—|—|—|—|_SEL_ST||
|Initial|value:|0|0|0|||0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0||
||R/W:|R|R|R|||R|R||R|R|R<br>R<br>R<br>R|R|R|R|R|R||
|**Bit**|**Bit Name**||||**Initial Value**<br>**R/W**|||||||**Description**|||||||
|15, 14|—||||0|||R||||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|13|—||||0|||R||||Reserved|||||||
|||||||||||||This bit is always read as 0. The write value should always be 0.|||||||
|12|GR3_CLT_||||—|||R||||Graphics 3 CLUT Table Read Select Signal Status||||Flag|||
||SEL_ST|||||||||||0: CLUT table 0 is read out.|||||||
|||||||||||||1: CLUT table 1 is read out.|||||||
|11 to 9|—||||All||0|R||||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|8|GR2_CLT_||||—|||R||||Graphics 2 CLUT Table Read Select Signal Status||||Flag|||
||SEL_ST|||||||||||0: CLUT table 0 is read out.|||||||
|||||||||||||1: CLUT table 1 is read out.|||||||
|7 to 1|—||||All||0|R||||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|0|GR0_CLT_||||—|||R||||Graphics 0 CLUT Table Read Select Signal Status||||Flag|||
||SEL_ST|||||||||||0: CLUT table 0 is read out.|||||||
|||||||||||||1: CLUT table 1 is read out.|||||||
