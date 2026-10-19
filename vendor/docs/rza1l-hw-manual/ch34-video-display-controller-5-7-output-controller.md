# 34. Video Display Controller 5 (7): Output Controller

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1816–1902. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 34.1 Output Controller

## 34.1.1 Overview of Functions

The output controller subjects RGB signals output from the image synthesizer to brightness adjustment, contrast adjustment, gamma correction of individual RGB, dither process, and output format conversion.

Figure 34.1 shows the function block diagram of the output controller.

**==> picture [333 x 209] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>LCD_DATA23 to<br>RGB888 LCD_DATA0<br>(24 bits)<br>HS,VS,<br>HE,VE,<br>RGB888 LCD_TCON6 to<br>(24 bits) Panel control LCD_TCON0<br>signal<br>Register control<br>Output controller<br>Output<br>interface<br>adjustment<br>Dither process<br>Brightness/contrast  Gamma correction<br>Image synthesizer LCD TCON<br>**----- End of picture text -----**<br>

**Figure 34.1 Functional Block Diagram of Output Controller**

## 34.1.2 Register Update Control

The Vsync signal is used to control the update timing of all the registers of the output controller.

After 1 is set to the bits in the update control register, the contents of the relevant registers are actually modified at the rising edge of the Vsync signal, when the update control register is automatically cleared to 0.

## **Table 34.1 Register Update Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|OUT_UPDATE|OUTCNT_VEN|0|Brightness/Contrast Control, Dither Process, Output Interface Register|
||||Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|GAM_G_UPDATE|GAM_G_VEN|0|Gamma Correction (G) Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|GAM_B_UPDATE|GAM_B_VEN|0|Gamma Correction (B) Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|GAM_R_UPDATE|GAM_R_VEN|0|Gamma Correction (R) Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|TCON_UPDATE|TCON_VEN|0|LCD TCON Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|

## 34.1.3 Route Selection

The processing sequence of the brightness/contrast control and gamma correction control can be swapped according to the settings of the register.

## **Table 34.2 Route Selection**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|OUT_CLK_PHASE|OUTCNT_|0|Correction Circuit Sequence Control|
||FRONT_GAM||0: Brightness → contrast → gamma correction|
||||1: Gamma correction → brightness → contrast|

## 34.1.4 Panel Brightness Adjustment

Brightness (DC) adjustment is individually performed for RGB signals from the image synthesizer.

(BRT_R/G/BOUT after brightness adjustment has many bits to prevent overflow or underflow. The overflow or underflow process is performed at contrast calculation.)

## (1) Calculation formulas for brightness (DC) adjustment

BRT_GOUT = GIN + PBRT_G − 512

BRT_BOUT = BIN + PBRT_B − 512

BRT_ROUT = RIN + PBRT_R − 512

## **Table 34.3 Brightness (DC) Adjustment**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|OUT_BRIGHT1|PBRT_G[9:0]|512|Brightness (DC) Adjustment of G Signal|
||||Unsigned (0 (-512) to 512 (0) to 1023 (+511) [LSB], 512 [LSB]|
||||with offset)|
|OUT_BRIGHT2|PBRT_B[9:0]|512|Brightness (DC) Adjustment of B Signal|
||||Unsigned (0 (-512) to 512 (0) to 1023 (+511) [LSB], 512 [LSB]|
||||with offset)|
|OUT_BRIGHT2|PBRT_R[9:0]|512|Brightness (DC) Adjustment of R Signal|
||||Unsigned (0 (-512) to 512 (0) to 1023 (+511) [LSB], 512 [LSB]|
||||with offset)|

## 34.1.5 Contrast Adjustment

Contrast is calculated for RGB signals obtained after brightness calculation.

(If an overflow or underflow occurs, contrast is clipped to the maximum or minimum value.)

## (1) Calculation formulas for contrast (gain) adjustment

GOUT = BRT_GOUT × CONT_G/128

BOUT = BRT_BOUT × CONT_B/128

ROUT = BRT_ROUT × CONT_R/128

## **Table 34.4 Contrast (Gain) Adjustment**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|OUT_CONTRAST|CONT_G [7:0]|128|Contrast (Gain) Adjustment of G Signal|
||||0/128 to 255/128 (approx.2 times)|
|OUT_CONTRAST|CONT_B [7:0]|128|Contrast (Gain) Adjustment of B Signal|
||||0/128 to 255/128 (approx.2 times)|
|OUT_CONTRAST|CONT_R [7:0]|128|Contrast (Gain) Adjustment of R Signal|
||||0/128 to 255/128 (approx.2 times)|

## 34.1.6 Gamma Correction

Gamma correction is carried out by dividing an input signal having 256 gradation levels into 32 and controlling the gain of each area. Gain coefficient of each area can be set as 0 to approx. 2.0 [times]

## (1) Gamma correction formula for each area

DOUT = ((DIN − TH(n)) × GAIN(n) + OFFSET(n))/256

DIN: Input signal (8-bit)

DOUT: Output signal (10-bit)

TH(n): Threshold (8-bit)

OFFSET(n): Offset value (19-bit)

GAIN(n): Gain coefficient (11-bit)

## (2) Offset calculation formulas for each area

OFFSET(n) = OFFSET(n−1) + DEF_O(n) (When n = 0, OFFSET(0) = 0.)

DEF_O(n) = (TH(n) − TH(n−1)) × GAIN(n−1) (When n = 0, OFFSET(0) = 0.)

OFFSET(n): Offset value of current area (19-bit)

OFFSET(n-1): Offset value of previous area (19-bit)

DEF_O(n): Difference in offset value of Current and previous area (19-bit)

TH(n): Threshold of current area (8-bit)

TH(n-1): Threshold of previous area (8-bit)

GAIN(n-1): Gain coefficient of previous area (11-bit)

**==> picture [483 x 642] intentionally omitted <==**

**----- Start of picture text -----**<br>
0 TH(1) TH(2) TH(3)<br>Input [LSB]<br>Figure 34.2 Corresponding Chart of Offset Calculation Formulas<br>1023<br>Output signal<br>Input signal<br>0<br>Input [LSB]<br>GAIN(2)<br>GAIN(0)<br>GAIN(1)<br>DEF_O(3)<br>Output [LSB]<br>DEF_O(2) OFFSET(3)<br>OFFSET(2)<br>DEF_O(1) OFFSET(1)<br>Output [LSB]<br>0 255<br>TH_1[7:0]=  8 TH_2[7:0]= 16 TH_3[7:0]= 24 TH_4[7:0]= 32 TH_5[7:0]= 40 TH_6[7:0]= 48 TH_7[7:0]= 56 TH_8[7:0]= 64 TH_9[7:0]= 72 TH_10[7:0]= 80 TH_11[7:0]= 88 TH_12[7:0]= 96 TH_13[7:0]=104 TH_14[7:0]=112 TH_15[7:0]=120 TH_16[7:0]=128 TH_17[7:0]=136 TH_18[7:0]=144 TH_19[7:0]=152 TH_20[7:0]=160 TH_21[7:0]=168 TH_22[7:0]=176 TH_23[7:0]=184 TH_24[7:0]=192 TH_25[7:0]=200 TH_26[7:0]=208 TH_27[7:0]=216 TH_28[7:0]=224 TH_29[7:0]=232 TH_30[7:0]=240 TH_31[7:0]=248<br>**----- End of picture text -----**<br>

**Figure 34.3 Example of Input-Output Characteristics of Gamma Correction**

**Table 34.5 Gamma Correction**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GAM_SW|GAM_ON|0|Gamma Correction On/Off Control|
||||0: Off|
||||1: On|
|GAM_G_AREA1 to|GAM_G_TH_01 to|*|Start Threshold of Area 1 to 31 of G Signal|
|GAM_G_AREA8|GAM_G_TH_31||Unsigned (0 to 255 [LSB])|
||[7:0]||Threshold of previous area*1< Threshold of current area <|
||||Threshold of next area*2|
||||*1: GAM_G_TH_01 is 0|
||||*2: GAM_G_TH_31 is ≤ 255|
||||*Initial Value|
||||GAM_G_TH_01:8, GAM_G_TH_02:16,|
||||GAM_G_TH_03:24, GAM_G_TH_04:32,|
||||GAM_G_TH_05:40, GAM_G_TH_06:48,|
||||GAM_G_TH_07:56, GAM_G_TH_08:64,|
||||GAM_G_TH_09:72, GAM_G_TH_10:80|
||||GAM_G_TH_11:88, GAM_G_TH_12:96,|
||||GAM_G_TH_13:104, GAM_G_TH_14:112,|
||||GAM_G_TH_15:120, GAM_G_TH_16:128,|
||||GAM_G_TH_17:136, GAM_G_TH_18:144,|
||||GAM_G_TH_19:152, GAM_G_TH_20:160,|
||||GAM_G_TH_21:168, GAM_G_TH_22:176,|
||||GAM_G_TH_23:184, GAM_G_TH_24:192,|
||||GAM_G_TH_25:200, GAM_G_TH_26:208,|
||||GAM_G_TH_27:216, GAM_G_TH_28:224,|
||||GAM_G_TH_29:232, GAM_G_TH_30:240,|
||||GAM_G_TH_31:248|
|GAM_G_LUT1 to|GAM_G_GAIN_00 to|1024|Gain Adjustment of Area 0 to 31 of G Signal|
|GAM_G_LUT16|GAM_G_GAIN_31||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|
||[10:0]|||
|GAM_B_AREA1 to|GAM_B_TH_01 to|*|Start Threshold of Area 1 to 31 of B Signal|
|GAM_B_AREA8|GAM_B_TH_31||Unsigned (0 to 255 [LSB])|
||[7:0]||Threshold of previous area*1 < Threshold of current area <|
||||Threshold of next area*2|
||||*1: GAM_B_TH_01 is 0|
||||*2: GAM_B_TH_31 is ≤ 255|
||||*Initial Value|
||||GAM_B_TH_01:8, GAM_B_TH_02:16,|
||||GAM_B_TH_03:24, GAM_B_TH_04:32,|
||||GAM_B_TH_05:40, GAM_B_TH_06:48,|
||||GAM_B_TH_07:56, GAM_B_TH_08:64,|
||||GAM_B_TH_09:72, GAM_B_TH_10:80|
||||GAM_B_TH_11:88, GAM_B_TH_12:96,|
||||GAM_B_TH_13:104, GAM_B_TH_14:112,|
||||GAM_B_TH_15:120, GAM_B_TH_16:128,|
||||GAM_B_TH_17:136, GAM_B_TH_18:144,|
||||GAM_B_TH_19:152, GAM_B_TH_20:160,|
||||GAM_B_TH_21:168, GAM_B_TH_22:176,|
||||GAM_B_TH_23:184, GAM_B_TH_24:192,|
||||GAM_B_TH_25:200, GAM_B_TH_26:208,|
||||GAM_B_TH_27:216, GAM_B_TH_28:224,|
||||GAM_B_TH_29:232, GAM_B_TH_30:240,|
||||GAM_B_TH_31:248|
|GAM_B_LUT1 to|GAM_B_GAIN_00 to|1024|Gain Adjustment of Area 0 to 31 of B Signal|
|GAM_B_LUT16|GAM_B_GAIN_31||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|
||[10:0]|||

**Table 34.5 Gamma Correction**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GAM_R_AREA1 to|GAM_R_TH_01 to|*|Start Threshold of Area 1 to 31 of R Signal|
|GAM_R_AREA8|GAM_R_TH_31||Unsigned (0 to 255 [LSB])|
||[7:0]||Threshold of previous area*1< Threshold of current area <|
||||Threshold of next area*2|
||||*1: GAM_R_TH_01 is 0|
||||*2: GAM_R_TH_31 is ≤ 255|
||||*Initial Value|
||||GAM_R_TH_01:8, GAM_R_TH_02:16,|
||||GAM_R_TH_03:24, GAM_R_TH_04:32,|
||||GAM_R_TH_05:40, GAM_R_TH_06:48,|
||||GAM_R_TH_07:56, GAM_R_TH_08:64,|
||||GAM_R_TH_09:72, GAM_R_TH_10:80|
||||GAM_R_TH_11:88, GAM_R_TH_12:96,|
||||GAM_R_TH_13:104, GAM_R_TH_14:112,|
||||GAM_R_TH_15:120, GAM_R_TH_16:128,|
||||GAM_R_TH_17:136, GAM_R_TH_18:144,|
||||GAM_R_TH_19:152, GAM_R_TH_20:160,|
||||GAM_R_TH_21:168, GAM_R_TH_22:176,|
||||GAM_R_TH_23:184, GAM_R_TH_24:192,|
||||GAM_R_TH_25:200, GAM_R_TH_26:208,|
||||GAM_R_TH_27:216, GAM_R_TH_28:224,|
||||GAM_R_TH_29:232, GAM_R_TH_30:240,|
||||GAM_R_TH_31:248|
|GAM_R_LUT1 to|GAM_R_GAIN_00 to|1024|Gain Adjustment of Area 0 to 31 of R Signal|
|GAM_R_LUT16|GAM_R_GAIN_31[10:0]||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|

## 34.1.7 Dither Process

Dither process is carried out by adjusting brightness/contrast or reducing 10-bit RGB signals output from the gamma correction block to 8-bit, 6-bit, or 5-bit RGB signals. The operation mode of dither process can be selected from truncate mode, round-off mode, 2 × 2 pattern dither mode and random pattern dither mode.

**==> picture [434 x 332] intentionally omitted <==**

**----- Start of picture text -----**<br>
Frame (4n) Frame (4n + 2)<br>Clock Clock<br>Hsync signal Hsync signal<br>A B C D A B C D A B C D C D A B C D A B C D A B<br>C D A B C D A B C D A B A B C D A B C D A B C D<br>A B C D A B C D A B C D C D A B C D A B C D A B<br>C D A B C D A B C D A B A B C D A B C D A B C D<br>A B C D A B C D A B C D C D A B C D A B C D A B<br>C D A B C D A B C D A B A B C D A B C D A B C D<br>Frame (4n + 1) Frame (4n + 3)<br>Clock Clock<br>Hsync signal Hsync signal<br>B C D A B C D A B C D A D A B C D A B C D A B C<br>D A B C D A B C D A B C B C D A B C D A B C D A<br>B C D A B C D A B C D A D A B C D A B C D A B C<br>D A B C D A B C D A B C B C D A B C D A B C D A<br>B C D A B C D A B C D A D A B C D A B C D A B C<br>D A B C D A B C D A B C B C D A B C D A B C D A<br>A : PDTH_PA[1:0] B : PDTH_PB[1:0] C : PDTH_PC[1:0] D : PDTH_PD[1:0]<br>Vsync signal Vsync signal<br>Vsync signal Vsync signal<br>**----- End of picture text -----**<br>

**Figure 34.4 Operation Specification of 2 × 2 Pattern Dither**

The conversion equations are as follows.

## [Truncate mode]

## (a) 10 bits to 8 bits

Output RGB data[7:0] = Input RGB data[9:0] ÷ 4 (truncate the number below the decimal point)

## (b) 10 bits to 6 bits

Output RGB data[7:2] = Input RGB data[9:0] ÷ 16 (truncate the number below the decimal point)

## (c) 10 bits to 5 bits

Output RGB data[7:3] = Input RGB data[9:0] ÷ 32 (truncate the number below the decimal point)

[Round-off mode]

## (a) 10 bits to 8 bits

Output RGB data[7:0] = Input RGB data[9:0] ÷ 4 (round off to an integer)

## (b) 10 bits to 6 bits

Output RGB data[7:2] = Input RGB data[9:0] ÷ 16 (round off to an integer)

## (c) 10 bits to 5 bits

Output RGB data[7:3] = Input RGB data[9:0] ÷ 32 (round off to an integer)

## [2 × 2 pattern dither mode, random pattern dither mode]

## (a) 10 bits to 8 bits

Output RGB data[7:0] = Input RGB data[9:0] ÷ 4 + pattern value at the first decimal place (truncate the number below the decimal point after addition)

- (b) 10 bits to 6 bits

Output RGB data[7:2] = Input RGB data[9:0] ÷ 16 + pattern value at the first decimal place (truncate the number below the decimal point after addition)

- (c) 10 bits to 5 bits

Output RGB data[7:3] = Input RGB data[9:0] ÷ 32 + pattern value at the first decimal place (truncate the number below the decimal point after addition)

## **Table 34.6 Panel Dither Correction**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|OUT_PDTHA|PDTH_SEL[1:0]|0|Panel Dither Operation Mode|
||||0: Truncate|
||||1: Round-off|
||||2: 2 × 2 pattern dither|
||||3: Random pattern dither|
|OUT_PDTHA|PDTH_FORMAT[1:0]|0|Panel Dither Output Format Select|
||||0: RGB888|
||||1: RGB666|
||||2: RGB565|
||||3: Setting prohibited|
|OUT_PDTHA|PDTH_PA[1:0]|3|Pattern Value (A) of 2 × 2 Pattern Dither|
||||Unsigned (0 to 3 [LSB])|
|OUT_PDTHA|PDTH_PB[1:0]|0|Pattern Value (B) of 2 × 2 Pattern Dither|
||||Unsigned (0 to 3 [LSB])|
|OUT_PDTHA|PDTH_PC[1:0]|2|Pattern Value (C) of 2 × 2 Pattern Dither|
||||Unsigned (0 to 3 [LSB])|
|OUT_PDTHA|PDTH_PD[1:0]|1|Pattern Value (D) of 2 × 2 Pattern Dither|
||||Unsigned (0 to 3 [LSB])|

## 34.1.8 Output Format Conversion

In output format conversion, the RGB signal after dither process is converted to LCD output signal having any of the following formats, namely, parallel RGB888, parallel RGB666, parallel RGB565, and serial RGB.

Further, converted data can be allocated to LCD output pins as selected.

## (1) Bit Allocation of LCD Signals for RGB888 Output

Table 34.7 shows the RGB signal input allocated to the LCD signal output for RGB888 output.

R/G/BIN[7:0] are the RGB internal signals after dither process.

**Table 34.7 Bit Allocation of RGB Signal Input for RGB888 Output**

|**OUT_FORMAT**|**0**|**0**|**0**|**0**|
|---|---|---|---|---|
|**OUT_ENDIAN_ON**|**0**|**0**|**1**|**1**|
|**OUT_SWAP_ON**|**0**|**1**|**0**|**1**|
|LCD_DATA23|RIN[7]|BIN[7]|RIN[0]|BIN[0]|
|LCD_DATA22|RIN[6]|BIN[6]|RIN[1]|BIN[1]|
|LCD_DATA21|RIN[5]|BIN[5]|RIN[2]|BIN[2]|
|LCD_DATA20|RIN[4]|BIN[4]|RIN[3]|BIN[3]|
|LCD_DATA19|RIN[3]|BIN[3]|RIN[4]|BIN[4]|
|LCD_DATA18|RIN[2]|BIN[2]|RIN[5]|BIN[5]|
|LCD_DATA17|RIN[1]|BIN[1]|RIN[6]|BIN[6]|
|LCD_DATA16|RIN[0]|BIN[0]|RIN[7]|BIN[7]|
|LCD_DATA15|GIN[7]|GIN[7]|GIN[0]|GIN[0]|
|LCD_DATA14|GIN[6]|GIN[6]|GIN[1]|GIN[1]|
|LCD_DATA13|GIN[5]|GIN[5]|GIN[2]|GIN[2]|
|LCD_DATA12|GIN[4]|GIN[4]|GIN[3]|GIN[3]|
|LCD_DATA11|GIN[3]|GIN[3]|GIN[4]|GIN[4]|
|LCD_DATA10|GIN[2]|GIN[2]|GIN[5]|GIN[5]|
|LCD_DATA9|GIN[1]|GIN[1]|GIN[6]|GIN[6]|
|LCD_DATA8|GIN[0]|GIN[0]|GIN[7]|GIN[7]|
|LCD_DATA7|BIN[7]|RIN[7]|BIN[0]|RIN[0]|
|LCD_DATA6|BIN[6]|RIN[6]|BIN[1]|RIN[1]|
|LCD_DATA5|BIN[5]|RIN[5]|BIN[2]|RIN[2]|
|LCD_DATA4|BIN[4]|RIN[4]|BIN[3]|RIN[3]|
|LCD_DATA3|BIN[3]|RIN[3]|BIN[4]|RIN[4]|
|LCD_DATA2|BIN[2]|RIN[2]|BIN[5]|RIN[5]|
|LCD_DATA1|BIN[1]|RIN[1]|BIN[6]|RIN[6]|
|LCD_DATA0|BIN[0]|RIN[0]|BIN[7]|RIN[7]|

## (2) Bit Allocation of LCD Signal for RGB666 Output

Table 34.8 shows the RGB signal input allocated to the LCD signal output for RGB666 output.

R/G/BIN[7:0] are the RGB internal signals after dither process.

**Table 34.8 Bit Allocation of RGB Signal Input for RGB666 Output**

|**OUT_FORMAT**|**1**|**1**|**1**|**1**|
|---|---|---|---|---|
|**OUT_ENDIAN_ON**|**0**|**0**|**1**|**1**|
|**OUT_SWAP_ON**|**0**|**1**|**0**|**1**|
|LCD_DATA23|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA22|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA21|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA20|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA19|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA18|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA17|RIN[7]|BIN[7]|RIN[2]|BIN[2]|
|LCD_DATA16|RIN[6]|BIN[6]|RIN[3]|BIN[3]|
|LCD_DATA15|RIN[5]|BIN[5]|RIN[4]|BIN[4]|
|LCD_DATA14|RIN[4]|BIN[4]|RIN[5]|BIN[5]|
|LCD_DATA13|RIN[3]|BIN[3]|RIN[6]|BIN[6]|
|LCD_DATA12|RIN[2]|BIN[2]|RIN[7]|BIN[7]|
|LCD_DATA11|GIN[7]|GIN[7]|GIN[2]|GIN[2]|
|LCD_DATA10|GIN[6]|GIN[6]|GIN[3]|GIN[3]|
|LCD_DATA9|GIN[5]|GIN[5]|GIN[4]|GIN[4]|
|LCD_DATA8|GIN[4]|GIN[4]|GIN[5]|GIN[5]|
|LCD_DATA7|GIN[3]|GIN[3]|GIN[6]|GIN[6]|
|LCD_DATA6|GIN[2]|GIN[2]|GIN[7]|GIN[7]|
|LCD_DATA5|BIN[7]|RIN[7]|BIN[2]|RIN[2]|
|LCD_DATA4|BIN[6]|RIN[6]|BIN[3]|RIN[3]|
|LCD_DATA3|BIN[5]|RIN[5]|BIN[4]|RIN[4]|
|LCD_DATA2|BIN[4]|RIN[4]|BIN[5]|RIN[5]|
|LCD_DATA1|BIN[3]|RIN[3]|BIN[6]|RIN[6]|
|LCD_DATA0|BIN[2]|RIN[2]|BIN[7]|RIN[7]|

## (3) Bit Allocation of LCD Signal for RGB565 Output

Table 34.9 shows the RGB signal input allocated to the LCD signal output for RGB565 output.

R/G/BIN[7:0] are the RGB internal signals after dither process.

**Table 34.9 Bit Allocation of RGB Signal Input for RGB565 Output**

|**OUT_FORMAT**|**2**|**2**|**2**|**2**|
|---|---|---|---|---|
|**OUT_ENDIAN_ON**|**0**|**0**|**1**|**1**|
|**OUT_SWAP_ON**|**0**|**1**|**0**|**1**|
|LCD_DATA23|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA22|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA21|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA20|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA19|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA18|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA17|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA16|Fixed to 0|Fixed to 0|Fixed to 0|Fixed to 0|
|LCD_DATA15|RIN[7]|BIN[7]|RIN[3]|BIN[3]|
|LCD_DATA14|RIN[6]|BIN[6]|RIN[4]|BIN[4]|
|LCD_DATA13|RIN[5]|BIN[5]|RIN[5]|BIN[5]|
|LCD_DATA12|RIN[4]|BIN[4]|RIN[6]|BIN[6]|
|LCD_DATA11|RIN[3]|BIN[3]|RIN[7]|BIN[7]|
|LCD_DATA10|GIN[7]|GIN[7]|GIN[2]|GIN[2]|
|LCD_DATA9|GIN[6]|GIN[6]|GIN[3]|GIN[3]|
|LCD_DATA8|GIN[5]|GIN[5]|GIN[4]|GIN[4]|
|LCD_DATA7|GIN[4]|GIN[4]|GIN[5]|GIN[5]|
|LCD_DATA6|GIN[3]|GIN[3]|GIN[6]|GIN[6]|
|LCD_DATA5|GIN[2]|GIN[2]|GIN[7]|GIN[7]|
|LCD_DATA4|BIN[7]|RIN[7]|BIN[3]|RIN[3]|
|LCD_DATA3|BIN[6]|RIN[6]|BIN[4]|RIN[4]|
|LCD_DATA2|BIN[5]|RIN[5]|BIN[5]|RIN[5]|
|LCD_DATA1|BIN[4]|RIN[4]|BIN[6]|RIN[6]|
|LCD_DATA0|BIN[3]|RIN[3]|BIN[7]|RIN[7]|

## (4) Bit Allocation of LCD Signal for Serial RGB Output

For serial RGB output, RGB signal input shown Table 34.10 is allocated to rgb internal signals and the signals are converted from parallel to serial format and output as LCD signals. R/G/BIN[7:0] are the RGB internal signals after dither process.

The internal signals r[7:0], g[7:0], and b[7:0] are serially output to LCD_DATA7 to LCD_DATA0.

**Table 34.10 Bit Allocation of RGB Signal Input for Serial RGB Output**

|**OUT_FORMAT**|**3**|**3**|**3**|**3**|
|---|---|---|---|---|
|**OUT_ENDIAN_ON**|**0**|**0**|**1**|**1**|
|**OUT_SWAP_ON**|**0**|**1**|**0**|**1**|
|r[7]|RIN[7]|BIN[7]|RIN[0]|BIN[0]|
|r[6]|RIN[6]|BIN[6]|RIN[1]|BIN[1]|
|r[5]|RIN[5]|BIN[5]|RIN[2]|BIN[2]|
|r[4]|RIN[4]|BIN[4]|RIN[3]|BIN[3]|
|r[3]|RIN[3]|BIN[3]|RIN[4]|BIN[4]|
|r[2]|RIN[2]|BIN[2]|RIN[5]|BIN[5]|
|r[1]|RIN[1]|BIN[1]|RIN[6]|BIN[6]|
|r[0]|RIN[0]|BIN[0]|RIN[7]|BIN[7]|
|g[7]|GIN[7]|GIN[7]|GIN[0]|GIN[0]|
|g[6]|GIN[6]|GIN[6]|GIN[1]|GIN[1]|
|g[5]|GIN[5]|GIN[5]|GIN[2]|GIN[2]|
|g[4]|GIN[4]|GIN[4]|GIN[3]|GIN[3]|
|g[3]|GIN[3]|GIN[3]|GIN[4]|GIN[4]|
|g[2]|GIN[2]|GIN[2]|GIN[5]|GIN[5]|
|g[1]|GIN[1]|GIN[1]|GIN[6]|GIN[6]|
|g[0]|GIN[0]|GIN[0]|GIN[7]|GIN[7]|
|b[7]|BIN[7]|RIN[7]|BIN[0]|RIN[0]|
|b[6]|BIN[6]|RIN[6]|BIN[1]|RIN[1]|
|b[5]|BIN[5]|RIN[5]|BIN[2]|RIN[2]|
|b[4]|BIN[4]|RIN[4]|BIN[3]|RIN[3]|
|b[3]|BIN[3]|RIN[3]|BIN[4]|RIN[4]|
|b[2]|BIN[2]|RIN[2]|BIN[5]|RIN[5]|
|b[1]|BIN[1]|RIN[1]|BIN[6]|RIN[6]|
|b[0]|BIN[0]|RIN[0]|BIN[7]|RIN[7]|

## (5) Parallel to Serial Conversion

As shown in Table 34.11 , four types of parallel to serial conversions are possible by controlling clock speed mode and selecting the scan direction ('n' in the table are natural numbers).

**Table 34.11 Specifications of Serial RGB Output**

**==> picture [483 x 357] intentionally omitted <==**

**----- Start of picture text -----**<br>
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|OUT_FRQ_SEL|1|1|2|2|
|OUT_DIR_SEL|0|1|0|1|
|Line (2n-1)|Repeated|Repeated|Repeated|Repeated|
|(r → g → b)|(b → g → r)|(r → g → b → X)|(X → b → g → r)|
|Line 2n|Repeated|Repeated|Repeated|Repeated|
|(g → b → r)|(r → b → g)|(r → g → b → X)|(X → b → g → r)|
|Figure 34.5|and|Figure 34.6|show the timing of parallel to serial conversion in triple speed and quadruple speed modes,|
|respectively.|
|LCD_CLK|
|Line 1|Line 2|Line (2n-1)|Line 2n|
|OUT_FRQ_SEL[1:0] = 1OUT_DIR_SEL = 0|X|X|X|X|X|X|X|X|r|g|b|r|g|b|r|g|...|...|...|X|X|X|X|X|X|X|X|g|b|r|g|b|r|g|b|...|...|...|X|X|X|X|X|X|X|X|r|g|b|r|g|b|r|g|...|...|...|X|X|X|X|X|X|X|X|g|b|r|g|b|r|g|b|...|...|...|X|X|X|X|
|OUT_FRQ_SEL[1:0] = 1OUT_DIR_SEL=  1|X|X|X|X|X|X|X|X|b|g|r|b|g|r|b|g|...|...|...|X|X|X|X|X|X|X|X|r|b|g|r|b|g|r|b|...|...|...|X|X|X|X|X|X|X|X|b|g|r|b|g|r|b|g|...|...|...|X|X|X|X|X|X|X|X|r|b|g|r|b|g|r|b|...|...|...|X|X|X|X|
|Figure 34.5|Timing of Parallel to Serial Conversion in Triple Speed Mode|
|LCD_CLK|
|Line 1|Line 2|Line (2n-1)|Line 2n|
|OUT_FRQ_SEL[1:0] = 2OUT_DIR_SEL = 0|X|X|X|X|X|X|X|X|r|g|b|X|r|g|b|X|...|...|...|X|X|X|X|X|X|X|X|r|g|b|X|r|g|b|X|...|...|...|X|X|X|X|X|X|X|X|r|g|b|X|r|g|b|X|...|...|...|X|X|X|X|X|X|X|X|r|g|b|X|r|g|b|X|...|...|...|X|X|X|X|
|OUT_FRQ_SEL[1:0] = 2OUT_DIR_SEL = 1|X|X|X|X|X|X|X|X|X|b|g|r|X|b|g|r|...|...|...|X|X|X|X|X|X|X|X|X|b|g|r|X|b|g|r|...|...|...|X|X|X|X|X|X|X|X|X|b|g|r|X|b|g|r|...|...|...|X|X|X|X|X|X|X|X|X|b|g|r|X|b|g|r|...|...|...|X|X|X|X|

**----- End of picture text -----**<br>

**Figure 34.6 Timing of Parallel to Serial Conversion in Quadruple Speed Mode**

During serial output, the phase timing with the HE signal can be adjusted by OUT_PHASE[0:1].

Figure 34.7 shows the timing of the clock phases of the serial RGB output (triple speed mode).

**==> picture [431 x 131] intentionally omitted <==**

**----- Start of picture text -----**<br>
Pixel clock<br>LCD_CLK<br>HE<br>OUT_PHASE[1:0] = 0<br>LCD_DATA7 to LCD_DATA0 ... ... ... ... ... ... r g b r g b r g b r g b<br>OUT_PHASE[1:0] = 1<br>LCD_DATA7 to LCD_DATA0 ... ... ... ... ... ... ... r g b r g b r g b r g<br>OUT_PHASE[1:0] = 2<br>LCD_DATA7 to LCD_DATA0 ... ... ... ... ... ... ... ... r g b r g b r g b r<br>**----- End of picture text -----**<br>

**Figure 34.7 Timing of Clock Phases of Serial RGB Output (Triple Speed Mode)**

Figure 34.8 shows the timing of the clock phases of the serial RGB output (quadruple speed mode).

**==> picture [435 x 155] intentionally omitted <==**

**----- Start of picture text -----**<br>
Pixel clock<br>LCD_CLK<br>HE<br>OUT_PHASE[1:0] = 0<br>LCD_DATA7 to LCD_DATA0 ... ... ... ... ... ... ... ... r g b X r g b X r g b X r g b X<br>OUT_PHASE[1:0] = 1<br>LCD_DATA7 to LCD_DATA0 ... ... ... ... ... ... ... ... ... r g b X r g b X r g b X r g b<br>OUT_PHASE[1:0] = 2<br>LCD_DATA7 to LCD_DATA0 ... ... ... ... ... ... ... ... ... ... r g b X r g b X r g b X r g<br>OUT_PHASE[1:0] = 3<br>LCD_DATA7 to LCD_DATA0 ... ... ... ... ... ... ... ... ... ... ... r g b X r g b X r g b X r<br>**----- End of picture text -----**<br>

## **Figure 34.8 Timing of Clock Phases of Serial RGB Output (Quadruple Speed Mode)**

**Table 34.12 Output Format Conversion**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|OUT_SET|OUT_FORMAT[1:0]|0|Output Format Select|
||||0: RBG888|
||||1: RGB666|
||||2: RGB565|
||||3: Serial RGB|
|OUT_SET|OUT_ENDIAN_ON|0|Bit Endian Change On/Off Control|
||||0: Off|
||||1: On|
|OUT_SET|OUT_SWAP_ON|0|B/R Signal Swap On/Off Control|
||||0: Off|
||||1: On|
|OUT_SET|OUT_FRQ_SEL[1:0]|0|Clock Frequency Control|
||||0: 100% speed — (parallel RGB)|
||||1: Triple speed — (serial RGB)|
||||2: Quadruple speed — (serial RGB)|
||||3: Setting prohibited|
|OUT_SET|OUT_DIR_SEL|0|Scan Direction Select|
||||0: Forward scan|
||||1: Reverse scan|
|OUT_SET|OUT_PHASE[1:0]|0|Clock Phase Adjustment for Serial RGB Output|
||||Triple speed mode|
||||0: 0 (clk)|
||||1: 1 (clk)|
||||2: 2 (clk)|
||||3: Setting prohibited|
||||Quadruple speed mode|
||||0: 0 (clk)|
||||1: 1 (clk)|
||||2: 2 (clk)|
||||3: 3 (clk)|

## 34.1.9 LCD TCON

The LCD TCON generates various timing signals for driving the LCD panel.

Specifically, the timing include two vertical panel driver signals, five horizontal panel driver signals, and one composite signal of the vertical and horizontal panel driver signals. Table 34.13 lists the timing signals that are generated by LCD TCON

**Table 34.13 Signals Generated by LCD TCON**

|**Signal Name**|**Type**|**Description**|
|---|---|---|
|STVA/VS|Vertical|Gate start signal|
|||The pulse width, pulse position, and pulse polarity of the signal can be controlled.|
|||Vsync signal|
|||The width, position, and polarity of the sync signal can be controlled.|
|STVB/VE|Vertical|Gate start signal|
|||The pulse width, pulse position, and pulse polarity of the signal can be controlled.|
|||Vertical enable signal|
|||The width, position, and polarity of the sync signal can be controlled.|
|STH/SP/HS|Horizontal|Source start signal|
|||The pulse width, pulse position, and pulse polarity of the signal can be controlled.|
|||Hsync signal|
|||The width, position, and polarity of the sync signal can be controlled.|
|STB/LP/HE|Horizontal|Source strobe signal|
|||The pulse width, pulse position, and pulse polarity of the signal can be controlled.|
|||Horizontal enable signal|
|||The width, position, and polarity of the enable signal can be controlled.|
|CPV/GCK|Horizontal|Gate clock signal|
|||The pulse width, pulse position, and pulse polarity of the signal can be controlled.|
|POLA|Horizontal|VCOM voltage polarity control signal|
|||The polarity inversion position, and polarity inversion operation (1 × 1, 1 × 2, 2 × 2) can|
|||be controlled.|
|POLB|Horizontal|VCOM voltage polarity control signal|
|||The polarity inversion position, and polarity inversion operation (1 × 1, 1 × 2, 2 × 2) can|
|||be controlled.|
|DE|Horizontal/Vertical|Data enable signal|
|||The width, position, and polarity of the enable signal can be controlled.|

## (1) Horizontal Reference Offset Control

The horizontal reference offset control enables generation of a reference signal with a clock delay equivalent to the value of TCON_OFFSET[10:0] from the rising edge of the Hsync signal. If a signal that spans across the Hsync signal needs to be generated, such a signal is generated with reference to the offset reference signal.

**==> picture [461 x 107] intentionally omitted <==**

**----- Start of picture text -----**<br>
Pixel clock<br>Hsync signal<br>H_INT<br>(internal signal)<br>CNT_HOFF<br>(internal signal)<br>TCON_OFFSET + 1<br>**----- End of picture text -----**<br>

**Figure 34.9 Generation of Offset Horizontal Reference (H_OFF) Signal**

**Table 34.14 Horizontal Reference Signal Selection**

|**Signal Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM|TCON_OFFSET[10:0]|0|Offset Hsync Signal Timing|
||||Sets the clock cycle count from the rising edge of the|
||||Hsync signal.|
|TCON_TIM_STH2|TCON_STH_HS_SEL|0|STH Signal Operating Reference Select|
||||0: Hsync signal reference|
||||1: Offset Hsync signal reference|
|TCON_TIM_STB2|TCON_STB_HS_SEL|0|STB Signal Operating Reference Select|
||||0: Hsync signal reference|
||||1: Offset Hsync signal reference|
|TCON_TIM_CPV2|TCON_CPV_HS_SEL|0|CPV Signal Operating Reference Select|
||||0: Hsync signal reference|
||||1: Offset Hsync signal reference|
|TCON_TIM_POLA2|TCON_POLA_HS_SEL|0|POLA Signal Operating Reference Select|
||||0: Hsync signal reference|
||||1: Offset Hsync signal reference|
|TCON_TIM_POLB2|TCON_POLB_HS_SEL|0|POLB Signal Operating Reference Select|
||||0: Hsync signal reference|
||||1: Offset Hsync signal reference|

Note: When generating the POLA and POLB signals in reverse mode, the bits TCON_POLA_HS_SEL and TCON_POLB_HS_SEL should be set to 0.

## (2) Horizontal Panel Driver Signal Generation (A)

Horizontal synchronous panel driver signal generation (A) involves generation of a timing signal that changes twice in a horizontal period according to the values of TCON_xxxx_HS[10:0] and TCON_xxxx_HW[10:0] bits, which set the first changing timing and the second changing timing, respectively.

The internal counter performs the following operations.

1. Resets the counter value at the rising edge of the Hsync signal as the reference.

2. Increments the counter value at the rising edge of the panel clock.

A fixed output value of 0 can be obtained by setting 0 in TCON_xxxx_HW[10:0], which set the second changing timing.

**==> picture [453 x 94] intentionally omitted <==**

**----- Start of picture text -----**<br>
Pixel clock<br>Hsync signal<br>Normal mode<br>TCON_xxxx_HS TCON_xxxx_HW<br>**----- End of picture text -----**<br>

**Figure 34.10 Horizontal Panel Driver Signal (in Normal Mode)**

**==> picture [453 x 94] intentionally omitted <==**

**----- Start of picture text -----**<br>
Pixel clock<br>Hsync signal<br>Timing signal not generated<br>Normal mode<br>TCON_xxxx_HS TCON_xxxx_HW = 0<br>**----- End of picture text -----**<br>

**Figure 34.11 Horizontal Panel Driver Signal (in Normal Mode and When TCON_xxxx_HW_ = 0)**

**==> picture [453 x 119] intentionally omitted <==**

**----- Start of picture text -----**<br>
Pixel clock<br>Hsync signal<br>CNT_HOFF Timing signal generated beyond Hsync signal<br>Normal mode TCON_OFFSET + 1<br>TCON_xxxx_HS TCON_xxxx_HW<br>**----- End of picture text -----**<br>

**Figure 34.12 Horizontal Panel Driver Signal (in Normal Mode and When Offset Horizontal Reference is Used)**

**Table 34.15 Settings for Horizontal Panel Driver Signal Generation (A)**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM_STH1|TCON_STH_HS[10:0]|0|STH Signal Pulse Start Position (First Changing Timing)|
||||Starts pulse output after the time specified by the value of|
||||TCON_STH_HS from the rising edge of the Hsync signal|
||||(clock cycles)|
|TCON_TIM_STH1|TCON_STH_HW[10:0]|96|STH Pulse Width (Second Changing Timing)|
||||Outputs a pulse of the duration of the value of|
||||TCON_STH_HW (clock cycles)|
|TCON_TIM_STB1|TCON_STB_HS[10:0]|144|STB Signal Pulse Start Position (First Changing Timing)|
||||Starts pulse output after the time specified by the value of|
||||TCON_STB_HS from the rising edge of the Hsync signal (clock|
||||cycles)|
|TCON_TIM_STB1|TCON_STB_HW[10:0]|640|STB Pulse Width (Second Changing Timing)|
||||Outputs a pulse of the duration of the value of|
||||TCON_STB_HW (clock cycles)|
|TCON_TIM_CPV1|TCON_CPV_HS[10:0]|0|CPV Signal Pulse Start Position (First Changing Timing)|
||||Starts pulse output after the time specified by the value of|
||||TCON_CPV_HS from the rising edge of the Hsync signal|
||||(clock cycles)|
|TCON_TIM_CPV1|TCON_CPV_HW[10:0]|0|CPV Pulse Width (Second Changing Timing)|
||||Outputs a pulse of the duration of the value of|
||||TCON_CPV_HW (clock cycles)|

## (3) Horizontal Panel Driver Signal Generation (B)

In addition to the normal mode operation described in (2), reverse mode operation, that is, horizontal panel driver signal generation (B) is provided. In reverse mode, operation starts at the rising edge of the Vsync signal as the reference and a signal is generated such that its polarity is inverted every horizontal period in the timing set by the TCON_xxxx_HS[10:0] bits, which set the first changing timing.

In reverse mode, regardless of whether the number of lines in the vertical direction is odd or even, the polarity of the signals generated is inverted every horizontal period. The following three reverse modes are selectable for polarity inversion operation.

**Table 34.16 Horizontal Panel Driver Signal Generation Modes**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM_POLA2|TCON_POLA_MD|1|POLA Signal Generation Mode Select|
||[1:0]||0: Normal mode|
||||Generates the signal that changes twice a horizontal period.|
||||1: 1 × 1 reverse mode|
||||Generates the signal whose polarity is inverted every|
||||horizontal period.|
||||2: 1 × 2 reverse mode|
||||Generates the signal whose polarity is inverted in the first|
||||horizontal period and is subsequently inverted every two|
||||horizontal periods.|
||||3: 2 × 2 reverse mode|
||||Generates the signal whose polarity is inverted every two|
||||horizontal periods.|
|TCON_TIM_POLB2|TCON_POLB_MD|1|POLB Signal Generation Mode Select|
||[1:0]||0: Normal mode|
||||Generates the signal that changes twice a horizontal period.|
||||1: 1 × 1 reverse mode|
||||Generates the signal whose polarity is inverted every|
||||horizontal period.|
||||2: 1 × 2 reverse mode|
||||Generates the signal whose polarity is inverted in the first|
||||horizontal period and is subsequently inverted every two|
||||horizontal periods.|
||||3: 2 × 2 reverse mode|
||||Generates the signal whose polarity is inverted every two|
||||horizontal periods.|

**==> picture [433 x 92] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync signal<br>Hsync signal<br>Reverse mode<br>(1) (2) (3) (1) (2) (3)<br>(1 × 1)<br>xxxx_HS xxxx_HS xxxx_HS xxxx_HS<br>Polarity inverted every vertical period<br>**----- End of picture text -----**<br>

**Figure 34.13 Horizontal Panel Driver Signal (in 1 × 1 Reverse Mode)**

**==> picture [433 x 92] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync signal<br>Hsync signal<br>Reverse mode<br>(1) (2) (3) (1) (2) (3)<br>(1 × 2)<br>xxxx_HS xxxx_HS xxxx_HS xxxx_HS<br>Polarity inverted every vertical period<br>**----- End of picture text -----**<br>

**Figure 34.14 Horizontal Panel Driver Signal (in 1 × 2 Reverse Mode)**

**==> picture [435 x 91] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync signal<br>Hsync signal<br>Reverse mode<br>(1) (2) (3) (1) (2)<br>(2 × 2)<br>xxxx_HS xxxx_HS xxxx_HS xxxx_HS<br>Polarity inverted every vertical period<br>**----- End of picture text -----**<br>

**Figure 34.15 Horizontal Panel Driver Signal (in 2 × 2 Reverse Mode)**

**Table 34.17 Settings of Horizontal Panel Driver Signal Generation (B)**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM_POLA1|TCON_POLA_HS|0|POLA Signal Pulse Start Position (First Changing Timing)|
||[10:0]||Starts pulse output after the time specified by the value of|
||||TCON_POLA_HS + 1 from the rising edge of the Hsync|
||||signal (clock cycles)|
||||Note: When 1 × 1, 1 × 2, or 2 × 2 reverse mode is selected,|
||||these bits should be set to 1 or greater.|
|TCON_TIM_POLA1|TCON_POLA_HW|0|POLA Pulse Width (Second Changing Timing)|
||[10:0]||Outputs a pulse of the duration of the value of|
||||TCON_POLA_HW (clock cycles)|
|TCON_TIM_POLB1|TCON_POLB_HS|0|POLBA Signal Pulse Start Position (First Changing Timing)|
||[10:0]||Starts pulse output after the time specified by the value of|
||||TCON_POLB_HS + 1 from the rising edge of the Hsync|
||||signal (clock cycles)|
||||Note: When 1 × 1, 1 × 2, or 2 × 2 reverse mode is selected,|
||||these bits should be set to1 or greater.|
|TCON_TIM_POLB1|TCON_POLB_HW|0|POLB Pulse Width (Second Changing Timing)|
||[10:0]||Outputs a pulse of the duration of the value of|
||||TCON_POLB_HW (clock cycles)|

## (4) Vertical Panel Driver Signal Generation

The vertical synchronous panel driver signal generation involves the following operations.

1. Initialization at the rising edge of the Vsync signal

2. Generation of a timing signal that changes twice in a vertical period according to the values of the internal counter, and TCON_xxxx_VS[10:0] and TCON_xxxx_VW[10:0] bits, which set the first changing timing and the second changing timing, respectively.

The internal counter increments the counter value in the following two cases.

1. At the rising edge of the Hsync signal

2. At the point reached after a clock delay specified by the value of TCON_HALF[10:0] from the rising edge of the Hsync signal (normally, 1/2fH is set).

**==> picture [431 x 116] intentionally omitted <==**

**----- Start of picture text -----**<br>
fH = 858<br>Pixel clock<br>Hsync signal<br>H_INT<br>(internal signal)<br>H_HALF<br>(internal signal) TCON_HALF = 429<br>When 1/2 horizontal period is set<br>**----- End of picture text -----**<br>

**Figure 34.16 1/2 Pulse (H_HALF) Signal Generation**

**Table 34.18 Settings of 1/2 Pulse (H_HALF) Signal Generation**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM|TCON_HALF[10:0]|400|1/2fH Timing|
||||Specifies the clock count from the rising edge of the Hsync|
||||signal as the counting timing of horizontal counter|

**==> picture [453 x 111] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync signal<br>H_INT<br>H_HALF<br>STVA, STVB<br>VS VW<br>**----- End of picture text -----**<br>

**Figure 34.17 Vertical Panel Driver Signal (H_INT Reference Operation)**

**==> picture [453 x 110] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync signal<br>H_INT<br>H_HALF<br>STVA, STVB<br>VS VW<br>**----- End of picture text -----**<br>

**Figure 34.18 Vertical Panel Driver Signal (H_HALF Reference Operation)**

**==> picture [453 x 110] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync signal<br>H_INT<br>H_HALF<br>STVA, STVB<br>VS VW = 1<br>**----- End of picture text -----**<br>

**Figure 34.19 Vertical Panel Driver Signal (H_INT and H_HALF Reference Operation)**

**Table 34.19 Vertical Panel Driver Signal Generation**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM_STVA1|TCON_STVA_VS[10:0]|0|STVA Signal Pulse Start Position (First Changing Timing)|
||||Starts pulse output after the time specified by the value of|
||||TCON_STVA_HS from the rising edge of the Vsync|
||||signal (1/2fH cycles)|
|TCON_TIM_STVA1|TCON_STVA_VW[10:0]|4|STVA Pulse Width (Second Changing Timing)|
||||Outputs a pulse of the duration of the value of|
||||TCON_STVA_HW (1/2fH cycles)|
|TCON_TIM_STVB1|TCON_STVB_VS[10:0]|70|STVB Signal Pulse Start Position (First Changing Timing)|
||||Starts pulse output after the time specified by the value of|
||||TCON_STVB_HS from the rising edge of the Vsync|
||||signal (1/2fH cycles)|
|TCON_TIM_STVB1|TCON_STVB_VW[10:0]|960|STVB Pulse Width (Second Changing Timing)|
||||Outputs a pulse of the duration of the value of|
||||TCON_STVB_HW (1/2fH cycles)|

## (5) DE Timing Signal Generation

DE timing signal generation involves generation of data enable signal (DE) that indicates the valid period of the video signal by synthesizing the horizontal panel driver (HE) signal and the vertical panel driver (VE) signal (AND).

**==> picture [427 x 92] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync signal<br>Hsync signal<br>VE<br>HE<br>DE<br>**----- End of picture text -----**<br>

**Figure 34.20 Data Enable Signal Generation**

## (6) Polarity Inversion

Polarity inversion enables inversion of polarity of each signal generated by the signal generating circuit.

**Table 34.20 Panel Driver Signal Polarity Inversion Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM_STVA2|TCON_STVA_INV|1|Polarity Inversion Control of STVA Signal|
||||0: Not inverted|
||||1: Inverted|
|TCON_TIM_STVB2|TCON_STVB_INV|0|Polarity Inversion Control of STVB Signal|
||||0: Not inverted|
||||1: Inverted|
|TCON_TIM_STH2|TCON_STH_INV|1|Polarity Inversion Control of STH Signal|
||||0: Not inverted|
||||1: Inverted|
|TCON_TIM_STB2|TCON_STB_INV|0|Polarity Inversion Control of STB Signal|
||||0: Not inverted|
||||1: Inverted|
|TCON_TIM_CPV2|TCON_CPV_INV|0|Polarity Inversion Control of CPV Signal|
||||0: Not inverted|
||||1: Inverted|
|TCON_TIM_POLA2|TCON_POLA_INV|0|Polarity Inversion Control of POLA Signal|
||||0: Not inverted|
||||1: Inverted|
|TCON_TIM_POLB2|TCON_POLB_INV|0|Polarity Inversion Control of POLB Signal|
||||0: Not inverted|
||||1: Inverted|
|TCON_TIM_DE|TCON_DE_INV|0|Polarity Inversion Control of DE Signal|
||||0: Not inverted|
||||1: Inverted|

## (7) Output Selection

An output pin is selected for every signal subjected to polarity inversion control.

**Table 34.21 Panel Driver Signal Output Selection**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM_STVA2|TCON_STVA_SEL|0|Output Signal Select for LCD_TCON0 Pin|
||[2:0]||0: STVA/VS|
||||1: STVB/VE|
||||2: STH/SP/HS|
||||3: STB/LP/HE|
||||4: CPV/GCK|
||||5: POLA|
||||6: POLB|
||||7: DE|
|TCON_TIM_STVB2|TCON_STVB_SEL|1|Output Signal Select for LCD_TCON1 Pin|
||[2:0]||0: STVA/VS|
||||1: STVB/VE|
||||2: STH/SP/HS|
||||3: STB/LP/HE|
||||4: CPV/GCK|
||||5: POLA|
||||6: POLB|
||||7: DE|
|TCON_TIM_STH2|TCON_STH_SEL|2|Output Signal Select for LCD_TCON2 Pin|
||[2:0]||0: STVA/VS|
||||1: STVB/VE|
||||2: STH/SP/HS|
||||3: STB/LP/HE|
||||4: CPV/GCK|
||||5: POLA|
||||6: POLB|
||||7: DE|
|TCON_TIM_STB2|TCON_STB_SEL|7|Output Signal Select for LCD_TCON3 Pin|
||[2:0]||0: STVA/VS|
||||1: STVB/VE|
||||2: STH/SP/HS|
||||3: STB/LP/HE|
||||4: CPV/GCK|
||||5: POLA|
||||6: POLB|
||||7: DE|
|TCON_TIM_CPV2|TCON_CPV_SEL|4|Output Signal Select for LCD_TCON4 Pin|
||[2:0]||0: STVA/VS|
||||1: STVB/VE|
||||2: STH/SP/HS|
||||3: STB/LP/HE|
||||4: CPV/GCK|
||||5: POLA|
||||6: POLB|
||||7: DE|
|TCON_TIM_POLA2|TCON_POLA_SEL|5|Output Signal Select for LCD_TCON5 Pin|
||[2:0]||0: STVA/VS|
||||1: STVB/VE|
||||2: STH/SP/HS|
||||3: STB/LP/HE|
||||4: CPV/GCK|
||||5: POLA|
||||6: POLB|
||||7: DE|

**Table 34.21 Panel Driver Signal Output Selection**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|TCON_TIM_POLB2|TCON_POLB_SEL|6|Output Signal Select for LCD_TCON6 Pin|
||[2:0]||0: STVA/VS|
||||1: STVB/VE|
||||2: STH/SP/HS|
||||3: STB/LP/HE|
||||4: CPV/GCK|
||||5: POLA|
||||6: POLB|
||||7: DE|

## (8) Output Phase Selection

The output phase can be individually selected for the video output signal and the various timing output signals based on the LCD_CLK (panel clock).

**Table 34.22 Panel Output Signal Phase Selection**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|OUT_CLK_PHASE|OUTCNT_LCD_EDGE|0|Output Phase Control of LCD_DATA23 to LCD_DATA0 Pin|
||||0: Output at the rising edge of LCD_CLK pin|
||||1: Output at the falling edge of LCD_CLK pin|
|OUT_CLK_PHASE|OUTCNT_STVA_EDGE|0|Output Phase Control of LCD_TCON0 Pin|
||||0: Output at the rising edge of LCD_CLK pin|
||||1: Output at the falling edge of LCD_CLK pin|
|OUT_CLK_PHASE|OUTCNT_STVB_EDGE|0|Output Phase Control of LCD_TCON1 Pin|
||||0: Output at the rising edge of LCD_CLK pin|
||||1: Output at the falling edge of LCD_CLK pin|
|OUT_CLK_PHASE|OUTCNT_STH_EDGE|0|Output Phase Control of LCD_TCON2 Pin|
||||0: Output at the rising edge of LCD_CLK pin|
||||1: Output at the falling edge of LCD_CLK pin|
|OUT_CLK_PHASE|OUTCNT_STB_EDGE|0|Output Phase Control of LCD_TCON3 Pin|
||||0: Output at the rising edge of LCD_CLK pin|
||||1: Output at the falling edge of LCD_CLK pin|
|OUT_CLK_PHASE|OUTCNT_CPV_EDGE|0|Output Phase Control of LCD_TCON4 Pin|
||||0: Output at the rising edge of LCD_CLK pin|
||||1: Output at the falling edge of LCD_CLK pin|
|OUT_CLK_PHASE|OUTCNT_POLA_EDGE|0|Output Phase Control of LCD_TCON5 Pin|
||||0: Output at the rising edge of LCD_CLK pin|
||||1: Output at the falling edge of LCD_CLK pin|
|OUT_CLK_PHASE|OUTCNT_POLB_EDGE|0|Output Phase Control of LCD_TCON6 Pin|
||||0: Output at the rising edge of LCD_CLK pin|
||||1: Output at the falling edge of LCD_CLK pin|

## 34.2 Register Descriptions

Table 34.23 to Table 34.25 show the register configuration.

- Symbols used in Register Description:

Initial value: Register value after a reset —: Undefined value R/W: Readable/writable. The written value can be read. R/WC0: Readable/writable. Writing 0 initializes the bit. Writing 1 is ignored. R/WC1: Readable/writable. Writing 1 initializes the bit. Writing 0 is ignored. R: Read-only. The write value should always be 0. —/W: Write-only. The read value is undefined.

**Table 34.23 Gamma Correction Block Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Register update control register G in|GAM_G_UPDATE|R/WC1|H'0000 0000|H'FCFF 7800|32|
|gamma correction block||||||
|Function switch register in gamma|GAM_SW|R/W|H'0000 0000|H'FCFF 7804|32|
|correction block||||||
|Table setting register G1 in gamma|GAM_G_LUT1|R/W|H'0400 0400|H'FCFF 7808|32|
|correction block||||||
|Table setting register G2 in gamma|GAM_G_LUT2|R/W|H'0400 0400|H'FCFF 780C|32|
|correction block||||||
|Table setting register G3 in gamma|GAM_G_LUT3|R/W|H'0400 0400|H'FCFF 7810|32|
|correction block||||||
|Table setting register G4 in gamma|GAM_G_LUT4|R/W|H'0400 0400|H'FCFF 7814|32|
|correction block||||||
|Table setting register G5 in gamma|GAM_G_LUT5|R/W|H'0400 0400|H'FCFF 7818|32|
|correction block||||||
|Table setting register G6 in gamma|GAM_G_LUT6|R/W|H'0400 0400|H'FCFF 781C|32|
|correction block||||||
|Table setting register G7 in gamma|GAM_G_LUT7|R/W|H'0400 0400|H'FCFF 7820|32|
|correction block||||||
|Table setting register G8 in gamma|GAM_G_LUT8|R/W|H'0400 0400|H'FCFF 7824|32|
|correction block||||||
|Table setting register G9 in gamma|GAM_G_LUT9|R/W|H'0400 0400|H'FCFF 7828|32|
|correction block||||||
|Table setting register G10 in gamma|GAM_G_LUT10|R/W|H'0400 0400|H'FCFF 782C|32|
|correction block||||||
|Table setting register G11 in gamma|GAM_G_LUT11|R/W|H'0400 0400|H'FCFF 7830|32|
|correction block||||||
|Table setting register G12 in gamma|GAM_G_LUT12|R/W|H'0400 0400|H'FCFF 7834|32|
|correction block||||||
|Table setting register G13 in gamma|GAM_G_LUT13|R/W|H'0400 0400|H'FCFF 7838|32|
|correction block||||||
|Table setting register G14 in gamma|GAM_G_LUT14|R/W|H'0400 0400|H'FCFF 783C|32|
|correction block||||||
|Table setting register G15 in gamma|GAM_G_LUT15|R/W|H'0400 0400|H'FCFF 7840|32|
|correction block||||||
|Table setting register G16 in gamma|GAM_G_LUT16|R/W|H'0400 0400|H'FCFF 7844|32|
|correction block||||||
|Area setting register G1 in gamma|GAM_G_AREA1|R/W|H'0008 1018|H'FCFF 7848|32|
|correction block||||||

**Table 34.23 Gamma Correction Block Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Area setting register G2 in gamma|GAM_G_AREA2|R/W|H'2028 3038|H'FCFF 784C|32|
|correction block||||||
|Area setting register G3 in gamma|GAM_G_AREA3|R/W|H'4048 5058|H'FCFF 7850|32|
|correction block||||||
|Area setting register G4 in gamma|GAM_G_AREA4|R/W|H'6068 7078|H'FCFF 7854|32|
|correction block||||||
|Area setting register G5 in gamma|GAM_G_AREA5|R/W|H'8088 9098|H'FCFF 7858|32|
|correction block||||||
|Area setting register G6 in gamma|GAM_G_AREA6|R/W|H'A0A8 B0B8|H'FCFF 785C|32|
|correction block||||||
|Area setting register G7 in gamma|GAM_G_AREA7|R/W|H'C0C8 D0D8|H'FCFF 7860|32|
|correction block||||||
|Area setting register G8 in gamma|GAM_G_AREA8|R/W|H'E0E8 F0F8|H'FCFF 7864|32|
|correction block||||||
|Register update control register B in|GAM_B_UPDATE|R/WC1|H'0000 0000|H'FCFF 7880|32|
|gamma correction block||||||
|Table setting register B1 in gamma|GAM_B_LUT1|R/W|H'0400 0400|H'FCFF 7888|32|
|correction block||||||
|Table setting register B2 in gamma|GAM_B_LUT2|R/W|H'0400 0400|H'FCFF 788C|32|
|correction block||||||
|Table setting register B3 in gamma|GAM_B_LUT3|R/W|H'0400 0400|H'FCFF 7890|32|
|correction block||||||
|Table setting register B4 in gamma|GAM_B_LUT4|R/W|H'0400 0400|H'FCFF 7894|32|
|correction block||||||
|Table setting register B5 in gamma|GAM_B_LUT5|R/W|H'0400 0400|H'FCFF 7898|32|
|correction block||||||
|Table setting register B6 in gamma|GAM_B_LUT6|R/W|H'0400 0400|H'FCFF 789C|32|
|correction block||||||
|Table setting register B7 in gamma|GAM_B_LUT7|R/W|H'0400 0400|H'FCFF 78A0|32|
|correction block||||||
|Table setting register B8 in gamma|GAM_B_LUT8|R/W|H'0400 0400|H'FCFF 78A4|32|
|correction block||||||
|Table setting register B9 in gamma|GAM_B_LUT9|R/W|H'0400 0400|H'FCFF 78A8|32|
|correction block||||||
|Table setting register B10 in gamma|GAM_B_LUT10|R/W|H'0400 0400|H'FCFF 78AC|32|
|correction block||||||
|Table setting register B11 in gamma|GAM_B_LUT11|R/W|H'0400 0400|H'FCFF 78B0|32|
|correction block||||||
|Table setting register B12 in gamma|GAM_B_LUT12|R/W|H'0400 0400|H'FCFF 78B4|32|
|correction block||||||
|Table setting register B13 in gamma|GAM_B_LUT13|R/W|H'0400 0400|H'FCFF 78B8|32|
|correction block||||||
|Table setting register B14 in gamma|GAM_B_LUT14|R/W|H'0400 0400|H'FCFF 78BC|32|
|correction block||||||
|Table setting register B15 in gamma|GAM_B_LUT15|R/W|H'0400 0400|H'FCFF 78C0|32|
|correction block||||||
|Table setting register B16 in gamma|GAM_B_LUT16|R/W|H'0400 0400|H'FCFF 78C4|32|
|correction block||||||
|Area setting register B1 in gamma|GAM_B_AREA1|R/W|H'0008 1018|H'FCFF 78C8|32|
|correction block||||||
|Area setting register B2 in gamma|GAM_B_AREA2|R/W|H'2028 3038|H'FCFF 78CC|32|
|correction block||||||

**Table 34.23 Gamma Correction Block Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Area setting register B3 in gamma|GAM_B_AREA3|R/W|H'4048 5058|H'FCFF 78D0|32|
|correction block||||||
|Area setting register B4 in gamma|GAM_B_AREA4|R/W|H'6068 7078|H'FCFF 78D4|32|
|correction block||||||
|Area setting register B5 in gamma|GAM_B_AREA5|R/W|H'8088 9098|H'FCFF 78D8|32|
|correction block||||||
|Area setting register B6 in gamma|GAM_B_AREA6|R/W|H'A0A8 B0B8|H'FCFF 78DC|32|
|correction block||||||
|Area setting register B7 in gamma|GAM_B_AREA7|R/W|H'C0C8 D0D8|H'FCFF 78E0|32|
|correction block||||||
|Area setting register B8 in gamma|GAM_B_AREA8|R/W|H'E0E8 F0F8|H'FCFF 78E4|32|
|correction block||||||
|Register update control register R in|GAM_R_UPDATE|R/WC1|H'0000 0000|H'FCFF 7900|32|
|gamma correction block||||||
|Table setting register R1 in gamma|GAM_R_LUT1|R/W|H'0400 0400|H'FCFF 7908|32|
|correction block||||||
|Table setting register R2 in gamma|GAM_R_LUT2|R/W|H'0400 0400|H'FCFF 790C|32|
|correction block||||||
|Table setting register R3 in gamma|GAM_R_LUT3|R/W|H'0400 0400|H'FCFF 7910|32|
|correction block||||||
|Table setting register R4 in gamma|GAM_R_LUT4|R/W|H'0400 0400|H'FCFF 7914|32|
|correction block||||||
|Table setting register R5 in gamma|GAM_R_LUT5|R/W|H'0400 0400|H'FCFF 7918|32|
|correction block||||||
|Table setting register R6 in gamma|GAM_R_LUT6|R/W|H'0400 0400|H'FCFF 791C|32|
|correction block||||||
|Table setting register R7 in gamma|GAM_R_LUT7|R/W|H'0400 0400|H'FCFF 7920|32|
|correction block||||||
|Table setting register R8 in gamma|GAM_R_LUT8|R/W|H'0400 0400|H'FCFF 7924|32|
|correction block||||||
|Table setting register R9 in gamma|GAM_R_LUT9|R/W|H'0400 0400|H'FCFF 7928|32|
|correction block||||||
|Table setting register R10 in gamma|GAM_R_LUT10|R/W|H'0400 0400|H'FCFF 792C|32|
|correction block||||||
|Table setting register R11 in gamma|GAM_R_LUT11|R/W|H'0400 0400|H'FCFF 7930|32|
|correction block||||||
|Table setting register R12 in gamma|GAM_R_LUT12|R/W|H'0400 0400|H'FCFF 7934|32|
|correction block||||||
|Table setting register R13 in gamma|GAM_R_LUT13|R/W|H'0400 0400|H'FCFF 7938|32|
|correction block||||||
|Table setting register R14 in gamma|GAM_R_LUT14|R/W|H'0400 0400|H'FCFF 793C|32|
|correction block||||||
|Table setting register R15 in gamma|GAM_R_LUT15|R/W|H'0400 0400|H'FCFF 7940|32|
|correction block||||||
|Table setting register R16 in gamma|GAM_R_LUT16|R/W|H'0400 0400|H'FCFF 7944|32|
|correction block||||||
|Area setting register R1 in gamma|GAM_R_AREA1|R/W|H'0008 1018|H'FCFF 7948|32|
|correction block||||||
|Area setting register R2 in gamma|GAM_R_AREA2|R/W|H'2028 3038|H'FCFF 794C|32|
|correction block||||||
|Area setting register R3 in gamma|GAM_R_AREA3|R/W|H'4048 5058|H'FCFF 7950|32|
|correction block||||||

**Table 34.23 Gamma Correction Block Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Area setting register R4 in gamma|GAM_R_AREA4|R/W|H'6068 7078|H'FCFF 7954|32|
|correction block||||||
|Area setting register R5 in gamma|GAM_R_AREA5|R/W|H'8088 9098|H'FCFF 7958|32|
|correction block||||||
|Area setting register R6 in gamma|GAM_R_AREA6|R/W|H'A0A8 B0B8|H'FCFF 795C|32|
|correction block||||||
|Area setting register R7 in gamma|GAM_R_AREA7|R/W|H'C0C8 D0D8|H'FCFF 7960|32|
|correction block||||||
|Area setting register R8 in gamma|GAM_R_AREA8|R/W|H'E0E8 F0F8|H'FCFF 7964|32|
|correction block||||||

**Table 34.24 TCON Block Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|TCON register update control|TCON_UPDATE|R/WC1|H'0000 0000|H'FCFF 7980|32|
|register||||||
|TCON reference timing|TCON_TIM|R/W|H'0190 0000|H'FCFF 7984|32|
|setting register||||||
|TCON vertical timing setting|TCON_TIM_STVA1|R/W|H'0000 0004|H'FCFF 7988|32|
|register A1||||||
|TCON vertical timing setting|TCON_TIM_STVA2|R/W|H'0000 0010|H'FCFF 798C|32|
|register A2||||||
|TCON vertical timing setting|TCON_TIM_STVB1|R/W|H'0046 03C0|H'FCFF 7990|32|
|register B1||||||
|TCON vertical timing setting|TCON_TIM_STVB2|R/W|H'0000 0001|H'FCFF 7994|32|
|register B2||||||
|TCON horizontal timing|TCON_TIM_STH1|R/W|H'0000 0060|H'FCFF 7998|32|
|setting register STH1||||||
|TCON horizontal timing|TCON_TIM_STH2|R/W|H'0000 0012|H'FCFF 799C|32|
|setting register STH2||||||
|TCON horizontal timing|TCON_TIM_STB1|R/W|H'0090 0280|H'FCFF 79A0|32|
|setting register STB1||||||
|TCON horizontal timing|TCON_TIM_STB2|R/W|H'0000 0007|H'FCFF 79A4|32|
|setting register STB2||||||
|TCON horizontal timing|TCON_TIM_CPV1|R/W|H'0000 0000|H'FCFF 79A8|32|
|setting register CPV1||||||
|TCON horizontal timing|TCON_TIM_CPV2|R/W|H'0000 0004|H'FCFF 79AC|32|
|setting register CPV2||||||
|TCON horizontal timing|TCON_TIM_POLA1|R/W|H'0000 0000|H'FCFF 79B0|32|
|setting register POLA1||||||
|TCON horizontal timing|TCON_TIM_POLA2|R/W|H'0000 1005|H'FCFF 79B4|32|
|setting register POLA2||||||
|TCON horizontal timing|TCON_TIM_POLB1|R/W|H'0000 0000|H'FCFF 79B8|32|
|setting register POLB1||||||
|TCON horizontal timing|TCON_TIM_POLB2|R/W|H'0000 1006|H'FCFF 79BC|32|
|setting register POLB2||||||
|TCON data enable polarity|TCON_TIM_DE|R/W|H'0000 0000|H'FCFF 79C0|32|
|setting register||||||

**Table 34.25 Output Controller Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Register update control|OUT_UPDATE|R/WC1|H'0000 0000|H'FCFF 7A00|32|
|register in output controller||||||
|Output interface register|OUT_SET|R/W|H'001F 0000|H'FCFF 7A04|32|
|Brightness (DC) correction|OUT_BRIGHT1|R/W|H'0000 0200|H'FCFF 7A08|32|
|register 1||||||
|Brightness (DC) correction|OUT_BRIGHT2|R/W|H'0200 0200|H'FCFF 7A0C|32|
|register 2||||||
|Contrast (gain) correction|OUT_CONTRAST|R/W|H'0080 8080|H'FCFF 7A10|32|
|register||||||
|Panel dither register|OUT_PDTHA|R/W|H'0000 3021|H'FCFF 7A14|32|
|Output phase control register|OUT_CLK_PHASE|R/W|H'0000 0000|H'FCFF 7A24|32|

## 34.2.1 Register Update Control Register G in Gamma Correction Block (GAM_G_UPDATE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1||0||
||||||||||||||||||GAM_||
||**—**|**—**|—|—|—|—|—|—|—|—|—|—|—|—|—||G_VEN||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/WC1|||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||GAM_G_VEN|0|R/WC1|Gamma Correction (G) Register Update|
|||||||0: Registers are not updated.|

- 1: Registers are updated at the rising edge of the Vsync.

## 34.2.2 Function Switch Register in Gamma Correction Block (GAM_SW)

|Bit:||31||30|29|||28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—||**—**|**—**|||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||
|Initial value:||0||0|0|||0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:||R||R|R|||R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:||15||14|13|||12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||||||||||GAM_||
|||**—**||**—**|**—**|||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|ON||
|Initial value:||0||0|0|||0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:||R||R|R|||R|R|R|R|R|R|R|R|R|R|R|R|R/W||
|**Bit**|**Bit Name**|||||**Initial Value**||||**R/W**||**Description**||||||||||
|31 to 1|—|||||All||0||R||Reserved||||||||||
|||||||||||||These bits are always read as 0. The write||||||value should always be 0.||||
|0|GAM_ON|||||0||||R/W||Gamma Correction On/Off Control||||||||||
|||||||||||||0: Off||||||||||
|||||||||||||1: On||||||||||

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.3 Table Setting Register G1 to G16 in Gamma Correction Block (GAM_G_LUT1 to GAM_G_LUT16)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20||19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|-|-|-|-<br>-<br>-<br>GAM_G_GAIN_xx[10:0]|||||-|-|-|-||
|Initial value:|0|0|0|0|0|1|0|0|0|0|0|0||0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4||3|2|1|0||
||**—**|**—**|**—**|**—**|**—**|-|-|-|-<br>-<br>-<br>GAM_G_GAIN_yy[10:0]|||||-|-|-|-||
|Initial value:|0|0|0|0|0|1|0|0|0|0|0|0||0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|*|1024|R/W|GAM_G_LUT1: Gain Adjustment of Area 0 of G Signal|
|||||||GAM_G_LUT2: Gain Adjustment of Area 2 of G Signal|
|||||||GAM_G_LUT3: Gain Adjustment of Area 4 of G Signal|
|||||||GAM_G_LUT4: Gain Adjustment of Area 6 of G Signal|
|||||||GAM_G_LUT5: Gain Adjustment of Area 8 of G Signal|
|||||||GAM_G_LUT6: Gain Adjustment of Area 10 of G Signal|
|||||||GAM_G_LUT7: Gain Adjustment of Area 12 of G Signal|
|||||||GAM_G_LUT8: Gain Adjustment of Area 14 of G Signal|
|||||||GAM_G_LUT9: Gain Adjustment of Area 16 of G Signal|
|||||||GAM_G_LUT10: Gain Adjustment of Area 18 of G Signal|
|||||||GAM_G_LUT11: Gain Adjustment of Area 20 of G Signal|
|||||||GAM_G_LUT12: Gain Adjustment of Area 22 of G Signal|
|||||||GAM_G_LUT13: Gain Adjustment of Area 24 of G Signal|
|||||||GAM_G_LUT14: Gain Adjustment of Area 26 of G Signal|
|||||||GAM_G_LUT15: Gain Adjustment of Area 28 of G Signal|
|||||||GAM_G_LUT16: Gain Adjustment of Area 30 of G Signal|
|||||||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|
|26|to|16|*|1024|R/W|*: Bit Name|
|||||||GAM_G_LUT1: GAM_G_GAIN_00[10:0]|
|||||||GAM_G_LUT2: GAM_G_GAIN_02[10:0]|
|||||||GAM_G_LUT3: GAM_G_GAIN_04[10:0]|
|||||||GAM_G_LUT4: GAM_G_GAIN_06[10:0]|
|||||||GAM_G_LUT5: GAM_G_GAIN_08[10:0]|
|||||||GAM_G_LUT6: GAM_G_GAIN_10[10:0]|
|||||||GAM_G_LUT7: GAM_G_GAIN_12[10:0]|
|||||||GAM_G_LUT8: GAM_G_GAIN_14[10:0]|
|||||||GAM_G_LUT9: GAM_G_GAIN_16[10:0]|
|||||||GAM_G_LUT10: GAM_G_GAIN_18[10:0]|
|||||||GAM_G_LUT11: GAM_G_GAIN_20[10:0]|
|||||||GAM_G_LUT12: GAM_G_GAIN_22[10:0]|
|||||||GAM_G_LUT13: GAM_G_GAIN_24[10:0]|
|||||||GAM_G_LUT14: GAM_G_GAIN_26[10:0]|
|||||||GAM_G_LUT15: GAM_G_GAIN_28[10:0]|
|||||||GAM_G_LUT16: GAM_G_GAIN_30[10:0]|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|10|to|0|*|1024|R/W|GAM_G_LUT1: Gain Adjustment of Area 1 of G Signal|
|||||||GAM_G_LUT2: Gain Adjustment of Area 3 of G Signal|
|||||||GAM_G_LUT3: Gain Adjustment of Area 5 of G Signal|
|||||||GAM_G_LUT4: Gain Adjustment of Area 7 of G Signal|
|||||||GAM_G_LUT5: Gain Adjustment of Area 9 of G Signal|
|||||||GAM_G_LUT6: Gain Adjustment of Area 11 of G Signal|
|||||||GAM_G_LUT7: Gain Adjustment of Area 13 of G Signal|
|||||||GAM_G_LUT8: Gain Adjustment of Area 15 of G Signal|
|||||||GAM_G_LUT9: Gain Adjustment of Area 17 of G Signal|
|||||||GAM_G_LUT10: Gain Adjustment of Area 19 of G Signal|
|10|to|0|*|1024|R/W|GAM_G_LUT11: Gain Adjustment of Area 21 of G Signal|
|||||||GAM_G_LUT12: Gain Adjustment of Area 23 of G Signal|
|||||||GAM_G_LUT13: Gain Adjustment of Area 25 of G Signal|
|||||||GAM_G_LUT14: Gain Adjustment of Area 27 of G Signal|
|||||||GAM_G_LUT15: Gain Adjustment of Area 29 of G Signal|
|||||||GAM_G_LUT16: Gain Adjustment of Area 31 of G Signal|
|||||||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|
|||||||*: Bit Name|
|||||||GAM_G_LUT1: GAM_G_GAIN_01[10:0]|
|||||||GAM_G_LUT2: GAM_G_GAIN_03[10:0]|
|||||||GAM_G_LUT3: GAM_G_GAIN_05[10:0]|
|||||||GAM_G_LUT4: GAM_G_GAIN_07[10:0]|
|||||||GAM_G_LUT5: GAM_G_GAIN_09[10:0]|
|||||||GAM_G_LUT6: GAM_G_GAIN_11[10:0]|
|||||||GAM_G_LUT7: GAM_G_GAIN_13[10:0]|
|||||||GAM_G_LUT8: GAM_G_GAIN_15[10:0]|
|||||||GAM_G_LUT9: GAM_G_GAIN_17[10:0]|
|||||||GAM_G_LUT10: GAM_G_GAIN_19[10:0]|
|||||||GAM_G_LUT11: GAM_G_GAIN_21[10:0]|
|||||||GAM_G_LUT12: GAM_G_GAIN_23[10:0]|
|||||||GAM_G_LUT13: GAM_G_GAIN_25[10:0]|
|||||||GAM_G_LUT14: GAM_G_GAIN_27[10:0]|
|||||||GAM_G_LUT15: GAM_G_GAIN_29[10:0]|
|||||||GAM_G_LUT16: GAM_G_GAIN_31[10:0]|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.4 Area Setting Register G1 in Gamma Correction Block (GAM_G_AREA1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||-|-<br>-<br>-<br>-<br>GAM_G_TH_01[7:0]||||-|-||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||-|-<br>-<br>-<br>-<br>GAM_G_TH_02[7:0]||||-|-||-|-<br>-<br>-<br>-<br>GAM_G_TH_03[7:0]||||-|-||
|Initial value:|0|0|0|1|0|0|0|0|0|0|0|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|23 to 16|GAM_G_TH_01[7:0]|8|R/W|Start Threshold of Area 1 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||0 < Threshold of current area < Threshold of next area|
|15 to 8|GAM_G_TH_02[7:0]|16|R/W|Start Threshold of Area 2 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_G_TH_03[7:0]|24|R/W|Start Threshold of Area 3 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.5 Area Setting Register G2 in Gamma Correction Block (GAM_G_AREA2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_G_TH_04[7:0]||||||||GAM_G_TH_05[7:0]|||||||
|Initial value:|0|0|1|0|0|0|0|0|0|0|1|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_G_TH_06[7:0]||||||||GAM_G_TH_07[7:0]|||||||
|Initial value:|0|0|1|1|0|0|0|0|0|0|1|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_G_TH_04[7:0]|32|R/W|Start Threshold of Area 4 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_G_TH_05[7:0]|40|R/W|Start Threshold of Area 5 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_G_TH_06[7:0]|48|R/W|Start Threshold of Area 6 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_G_TH_07[7:0]|56|R/W|Start Threshold of Area 7 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.6 Area Setting Register G3 in Gamma Correction Block (GAM_G_AREA3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_G_TH_08[7:0]||||||||GAM_G_TH_09[7:0]||||||
|Initial value:|0|1|0|0|0|0|0|0|0|1|0|0|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GAM_G_TH_10[7:0]||||||||GAM_G_TH_11[7:0]||||||
|Initial value:|0|1|0|1|0|0|0|0|0|1|0|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_G_TH_08[7:0]|64|R/W|Start Threshold of Area 8 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_G_TH_09[7:0]|72|R/W|Start Threshold of Area 9 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_G_TH_10[7:0]|80|R/W|Start Threshold of Area 10 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_G_TH_11[7:0]|88|R/W|Start Threshold of Area 11 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.7 Area Setting Register G4 in Gamma Correction Block (GAM_G_AREA4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_G_TH_12[7:0]||||||||GAM_G_TH_13[7:0]||||||
|Initial value:|0|1|1|0|0|0|0|0|0|1|1|0|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GAM_G_TH_14[7:0]||||||||GAM_G_TH_15[7:0]||||||
|Initial value:|0|1|1|1|0|0|0|0|0|1|1|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_G_TH_12[7:0]|96|R/W|Start Threshold of Area 12 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_G_TH_13[7:0]|104|R/W|Start Threshold of Area 13 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_G_TH_14[7:0]|112|R/W|Start Threshold of Area 14 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_G_TH_15[7:0]|120|R/W|Start Threshold of Area 15 of G Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.8 Area Setting Register G5 in Gamma Correction Block (GAM_G_AREA5)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_G_TH_16[7:0]||||||||GAM_G_TH_17[7:0]|||||||
|Initial value:|1|0|0|0|0|0|0|0|1|0|0|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_G_TH_18[7:0]||||||||GAM_G_TH_19[7:0]|||||||
|Initial value:|1|0|0|1|0|0|0|0|1|0|0|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_G_TH_16|128|R/W|Start Threshold of Area 16 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_G_TH_17|136|R/W|Start Threshold of Area 17 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_G_TH_18|144|R/W|Start Threshold of Area 18 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_G_TH_19|152|R/W|Start Threshold of Area 19 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.9 Area Setting Register G6 in Gamma Correction Block (GAM_G_AREA6)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_G_TH_20[7:0]||||||||GAM_G_TH_21[7:0]|||||||
|Initial value:|1|0|1|0|0|0|0|0|1|0|1|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_G_TH_22[7:0]||||||||GAM_G_TH_23[7:0]|||||||
|Initial value:|1|0|1|1|0|0|0|0|1|0|1|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_G_TH_20|160|R/W|Start Threshold of Area 20 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_G_TH_21|168|R/W|Start Threshold of Area 21 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_G_TH_22|176|R/W|Start Threshold of Area 22 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_G_TH_23|184|R/W|Start Threshold of Area 23 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.10 Area Setting Register G7 in Gamma Correction Block (GAM_G_AREA7)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_G_TH_24[7:0]||||||||GAM_G_TH_25[7:0]|||||||
|Initial value:|1|1|0|0|0|0|0|0|1|1|0|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_G_TH_26[7:0]||||||||GAM_G_TH_27[7:0]|||||||
|Initial value:|1|1|0|1|0|0|0|0|1|1|0|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_G_TH_24|192|R/W|Start Threshold of Area 24 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_G_TH_25|200|R/W|Start Threshold of Area 25 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_G_TH_26|208|R/W|Start Threshold of Area 26 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_G_TH_27|216|R/W|Start Threshold of Area 27 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.11 Area Setting Register G8 in Gamma Correction Block (GAM_G_AREA8)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_G_TH_28[7:0]||||||||GAM_G_TH_29[7:0]|||||||
|Initial value:|1|1|1|0|0|0|0|0|1|1|1|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_G_TH_30[7:0]||||||||GAM_G_TH_31[7:0]|||||||
|Initial value:|1|1|1|1|0|0|0|0|1|1|1|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_G_TH_28|224|R/W|Start Threshold of Area 28 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_G_TH_29|232|R/W|Start Threshold of Area 29 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_G_TH_30|240|R/W|Start Threshold of Area 30 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_G_TH_31|248|R/W|Start Threshold of Area 31 of G Signal|
||[7:0]|||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area ≤ 255|

Note: This register is updated when GAM_G_VEN in GAM_G_UPDATE is 1.

## 34.2.12 Register Update Control Register B in Gamma Correction Block (GAM_B_UPDATE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1||0||
||||||||||||||||||GAM_B||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||_VEN||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/WC1|||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||GAM_B_VEN|0|R/WC1|Gamma Correction (B) Register Update|
|||||||0: Registers are not updated.|
|||||||1: Registers are updated at the rising edge of the Vsync.|

## 34.2.13 Table Setting Register B1 to B16 in Gamma Correction Block (GAM_B_LUT1 to GAM_B_LUT16)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—||||GAM_B_GAIN_xx[10:0]||||||||
|Initial value:|0|0|0|0|0|1|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—||||GAM_B_GAIN_yy[10:0]||||||||
|Initial value:|0|0|0|0|0|1|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|*|1024|R/W|GAM_B_LUT1: Gain Adjustment of Area 0 of B Signal|
|||||||GAM_B_LUT2: Gain Adjustment of Area 2 of B Signal|
|||||||GAM_B_LUT3: Gain Adjustment of Area 4 of B Signal|
|||||||GAM_B_LUT4: Gain Adjustment of Area 6 of B Signal|
|||||||GAM_B_LUT5: Gain Adjustment of Area 8 of B Signal|
|||||||GAM_B_LUT6: Gain Adjustment of Area 10 of B Signal|
|||||||GAM_B_LUT7: Gain Adjustment of Area 12 of B Signal|
|||||||GAM_B_LUT8: Gain Adjustment of Area 14 of B Signal|
|||||||GAM_B_LUT9: Gain Adjustment of Area 16 of B Signal|
|||||||GAM_B_LUT10: Gain Adjustment of Area 18 of B Signal|
|||||||GAM_B_LUT11: Gain Adjustment of Area 20 of B Signal|
|||||||GAM_B_LUT12: Gain Adjustment of Area 22 of B Signal|
|||||||GAM_B_LUT13: Gain Adjustment of Area 24 of B Signal|
|||||||GAM_B_LUT14: Gain Adjustment of Area 26 of B Signal|
|||||||GAM_B_LUT15: Gain Adjustment of Area 28 of B Signal|
|||||||GAM_B_LUT16: Gain Adjustment of Area 30 of B Signal|
|||||||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|
|26|to|16|*|1024|R/W|*: Bit Name|
|||||||GAM_B_LUT1: GAM_B_GAIN_00[10:0]|
|||||||GAM_B_LUT2: GAM_B_GAIN_02[10:0]|
|||||||GAM_B_LUT3: GAM_B_GAIN_04[10:0]|
|||||||GAM_B_LUT4: GAM_B_GAIN_06[10:0]|
|||||||GAM_B_LUT5: GAM_B_GAIN_08[10:0]|
|||||||GAM_B_LUT6: GAM_B_GAIN_10[10:0]|
|||||||GAM_B_LUT7: GAM_B_GAIN_12[10:0]|
|||||||GAM_B_LUT8: GAM_B_GAIN_14[10:0]|
|||||||GAM_B_LUT9: GAM_B_GAIN_16[10:0]|
|||||||GAM_B_LUT10: GAM_B_GAIN_18[10:0]|
|||||||GAM_B_LUT11: GAM_B_GAIN_20[10:0]|
|||||||GAM_B_LUT12: GAM_B_GAIN_22[10:0]|
|||||||GAM_B_LUT13: GAM_B_GAIN_24[10:0]|
|||||||GAM_B_LUT14: GAM_B_GAIN_26[10:0]|
|||||||GAM_B_LUT15: GAM_B_GAIN_28[10:0]|
|||||||GAM_B_LUT16: GAM_B_GAIN_30[10:0]|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|10|to|0|*|1024|R/W|GAM_B_LUT1: Gain Adjustment of Area 1 of B Signal|
|||||||GAM_B_LUT2: Gain Adjustment of Area 3 of B Signal|
|||||||GAM_B_LUT3: Gain Adjustment of Area 5 of B Signal|
|||||||GAM_B_LUT4: Gain Adjustment of Area 7 of B Signal|
|||||||GAM_B_LUT5: Gain Adjustment of Area 9 of B Signal|
|||||||GAM_B_LUT6: Gain Adjustment of Area 11 of B Signal|
|||||||GAM_B_LUT7: Gain Adjustment of Area 13 of B Signal|
|||||||GAM_B_LUT8: Gain Adjustment of Area 15 of B Signal|
|||||||GAM_B_LUT9: Gain Adjustment of Area 17 of B Signal|
|||||||GAM_B_LUT10: Gain Adjustment of Area 19 of B Signal|
|||||||GAM_B_LUT11: Gain Adjustment of Area 21 of B Signal|
|||||||GAM_B_LUT12: Gain Adjustment of Area 23 of B Signal|
|||||||GAM_B_LUT13: Gain Adjustment of Area 25 of B Signal|
|||||||GAM_B_LUT14: Gain Adjustment of Area 27 of B Signal|
|||||||GAM_B_LUT15: Gain Adjustment of Area 29 of B Signal|
|||||||GAM_B_LUT16: Gain Adjustment of Area 31 of B Signal|
|||||||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|
|||||||*: Bit Name|
|||||||GAM_B_LUT1: GAM_B_GAIN_01[10:0]|
|||||||GAM_B_LUT2: GAM_B_GAIN_03[10:0]|
|||||||GAM_B_LUT3: GAM_B_GAIN_05[10:0]|
|||||||GAM_B_LUT4: GAM_B_GAIN_07[10:0]|
|||||||GAM_B_LUT5: GAM_B_GAIN_09[10:0]|
|||||||GAM_B_LUT6: GAM_B_GAIN_11[10:0]|
|||||||GAM_B_LUT7: GAM_B_GAIN_13[10:0]|
|||||||GAM_B_LUT8: GAM_B_GAIN_15[10:0]|
|||||||GAM_B_LUT9: GAM_B_GAIN_17[10:0]|
|||||||GAM_B_LUT10: GAM_B_GAIN_19[10:0]|
|||||||GAM_B_LUT11: GAM_B_GAIN_21[10:0]|
|||||||GAM_B_LUT12: GAM_B_GAIN_23[10:0]|
|||||||GAM_B_LUT13: GAM_B_GAIN_25[10:0]|
|||||||GAM_B_LUT14: GAM_B_GAIN_27[10:0]|
|||||||GAM_B_LUT15: GAM_B_GAIN_29[10:0]|
|||||||GAM_B_LUT16: GAM_B_GAIN_31[10:0]|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.14 Area Setting Register B1 in Gamma Correction Block (GAM_B_AREA1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|||GAM_B_TH_01[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GAM_B_TH_02[7:0]||||||||GAM_B_TH_03[7:0]||||||
|Initial value:|0|0|0|1|0|0|0|0|0|0|0|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|23 to 16|GAM_B_TH_01[7:0]|8|R/W|Start Threshold of Area 1 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||0 < Threshold of current area < Threshold of next area|
|15 to 8|GAM_B_TH_02[7:0]|16|R/W|Start Threshold of Area 2 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_B_TH_03[7:0]|24|R/W|Start Threshold of Area 3 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.15 Area Setting Register B2 in Gamma Correction Block (GAM_B_AREA2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_B_TH_04[7:0]||||||||GAM_B_TH_05[7:0]|||||||
|Initial value:|0|0|1|0|0|0|0|0|0|0|1|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_B_TH_06[7:0]||||||||GAM_B_TH_07[7:0]|||||||
|Initial value:|0|0|1|1|0|0|0|0|0|0|1|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_B_TH_04[7:0]|32|R/W|Start Threshold of Area 4 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_B_TH_05[7:0]|40|R/W|Start Threshold of Area 5 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_B_TH_06[7:0]|48|R/W|Start Threshold of Area 6 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_B_TH_07[7:0]|56|R/W|Start Threshold of Area 7 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.16 Area Setting Register B3 in Gamma Correction Block (GAM_B_AREA3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_B_TH_08[7:0]||||||||GAM_B_TH_09[7:0]|||||||
|Initial value:|0|1|0|0|0|0|0|0|0|1|0|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_B_TH_10[7:0]||||||||GAM_B_TH_11[7:0]|||||||
|Initial value:|0|1|0|1|0|0|0|0|0|1|0|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_B_TH_08[7:0]|64|R/W|Start Threshold of Area 8 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_B_TH_09[7:0]|72|R/W|Start Threshold of Area 9 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_B_TH_10[7:0]|80|R/W|Start Threshold of Area 10 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_B_TH_11[7:0]|88|R/W|Start Threshold of Area 11 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.17 Area Setting Register B4 in Gamma Correction Block (GAM_B_AREA4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_B_TH_12[7:0]||||||||GAM_B_TH_13[7:0]|||||||
|Initial value:|0|1|1|0|0|0|0|0|0|1|1|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_B_TH_14[7:0]||||||||GAM_B_TH_15[7:0]|||||||
|Initial value:|0|1|1|1|0|0|0|0|0|1|1|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_B_TH_12[7:0]|96|R/W|Start Threshold of Area 12 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_B_TH_13[7:0]|104|R/W|Start Threshold of Area 13 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_B_TH_14[7:0]|112|R/W|Start Threshold of Area 14 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_B_TH_15[7:0]|120|R/W|Start Threshold of Area 15 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.18 Area Setting Register B5 in Gamma Correction Block (GAM_B_AREA5)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_B_TH_16[7:0]||||||||GAM_B_TH_17[7:0]|||||||
|Initial value:|1|0|0|0|0|0|0|0|1|0|0|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_B_TH_18[7:0]||||||||GAM_B_TH_19[7:0]|||||||
|Initial value:|1|0|0|1|0|0|0|0|1|0|0|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_B_TH_16[7:0]|128|R/W|Start Threshold of Area 16 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_B_TH_17[7:0]|136|R/W|Start Threshold of Area 17 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_B_TH_18[7:0]|144|R/W|Start Threshold of Area 18 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_B_TH_19[7:0]|152|R/W|Start Threshold of Area 19 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.19 Area Setting Register B6 in Gamma Correction Block (GAM_B_AREA6)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_B_TH_20[7:0]||||||||GAM_B_TH_21[7:0]|||||||
|Initial value:|1|0|1|0|0|0|0|0|1|0|1|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_B_TH_22[7:0]||||||||GAM_B_TH_23[7:0]|||||||
|Initial value:|1|0|1|1|0|0|0|0|1|0|1|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_B_TH_20[7:0]|160|R/W|Start Threshold of Area 20 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_B_TH_21[7:0]|168|R/W|Start Threshold of Area 21 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_B_TH_22[7:0]|176|R/W|Start Threshold of Area 22 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_B_TH_23[7:0]|184|R/W|Start Threshold of Area 23 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.20 Area Setting Register B7 in Gamma Correction Block (GAM_B_AREA7)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_B_TH_24[7:0]||||||||GAM_B_TH_25[7:0]|||||||
|Initial value:|1|1|0|0|0|0|0|0|1|1|0|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_B_TH_26[7:0]||||||||GAM_B_TH_27[7:0]|||||||
|Initial value:|1|1|0|1|0|0|0|0|1|1|0|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_B_TH_24[7:0]|192|R/W|Start Threshold of Area 24 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_B_TH_25[7:0]|200|R/W|Start Threshold of Area 25 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_B_TH_26[7:0]|208|R/W|Start Threshold of Area 26 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_B_TH_27[7:0]|216|R/W|Start Threshold of Area 27 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.21 Area Setting Register B8 in Gamma Correction Block (GAM_B_AREA8)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_B_TH_28[7:0]||||||||GAM_B_TH_29[7:0]|||||||
|Initial value:|1|1|1|0|0|0|0|0|1|1|1|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_B_TH_30[7:0]||||||||GAM_B_TH_31[7:0]|||||||
|Initial value:|1|1|1|1|0|0|0|0|1|1|1|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_B_TH_28[7:0]|224|R/W|Start Threshold of Area 28 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_B_TH_29[7:0]|232|R/W|Start Threshold of Area 29 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_B_TH_30[7:0]|240|R/W|Start Threshold of Area 30 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_B_TH_31[7:0]|248|R/W|Start Threshold of Area 31 of B Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area ≤ 255|

Note: This register is updated when GAM_B_VEN in GAM_B_UPDATE is 1.

## 34.2.22 Register Update Control Register R in Gamma Correction Block (GAM_R_UPDATE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17||16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||—|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1||0|
||||||||||||||||||GAM_R|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||_VEN|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/WC1||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||GAM_R_VEN|0|R/WC1|Gamma Correction (R) Register Update|
|||||||0: Registers are not updated.|
|||||||1: Registers are updated at the rising edge of the Vsync.|

## 34.2.23 Table Setting Register R1 to R16 in Gamma Correction Block (GAM_R_LUT1 to GAM_R_LUT16)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20||19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|-|-|-|-<br>-<br>-<br>GAM_G_GAIN_xx[10:0]|||||-|-|-|-||
|Initial value:|0|0|0|0|0|1|0|0|0|0|0|0||0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4||3|2|1|0||
||**—**|**—**|**—**|**—**|**—**|-|-|-|-<br>-<br>-<br>GAM_G_GAIN_yy[10:0]|||||-|-|-|-||
|Initial value:|0|0|0|0|0|1|0|0|0|0|0|0||0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|*|1024|R/W|GAM_R_LUT1: Gain Adjustment of Area 0 of R Signal|
|||||||GAM_R_LUT2: Gain Adjustment of Area 2 of R Signal|
|||||||GAM_R_LUT3: Gain Adjustment of Area 4 of R Signal|
|||||||GAM_R_LUT4: Gain Adjustment of Area 6 of R Signal|
|||||||GAM_R_LUT5: Gain Adjustment of Area 8 of R Signal|
|||||||GAM_R_LUT6: Gain Adjustment of Area 10 of R Signal|
|||||||GAM_R_LUT7: Gain Adjustment of Area 12 of R Signal|
|||||||GAM_R_LUT8: Gain Adjustment of Area 14 of R Signal|
|||||||GAM_R_LUT9: Gain Adjustment of Area 16 of R Signal|
|||||||GAM_R_LUT10: Gain Adjustment of Area 18 of R Signal|
|||||||GAM_R_LUT11: Gain Adjustment of Area 20 of R Signal|
|||||||GAM_R_LUT12: Gain Adjustment of Area 22 of R Signal|
|||||||GAM_R_LUT13: Gain Adjustment of Area 24 of R Signal|
|||||||GAM_R_LUT14: Gain Adjustment of Area 26 of R Signal|
|||||||GAM_R_LUT15: Gain Adjustment of Area 28 of R Signal|
|||||||GAM_R_LUT16: Gain Adjustment of Area 30 of R Signal|
|||||||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|
|||||||*: Bit Name|
|||||||GAM_R_LUT1: GAM_R_GAIN_00[10:0]|
|||||||GAM_R_LUT2: GAM_R_GAIN_02[10:0]|
|||||||GAM_R_LUT3: GAM_R_GAIN_04[10:0]|
|||||||GAM_R_LUT4: GAM_R_GAIN_06[10:0]|
|||||||GAM_R_LUT5: GAM_R_GAIN_08[10:0]|
|||||||GAM_R_LUT6: GAM_R_GAIN_10[10:0]|
|||||||GAM_R_LUT7: GAM_R_GAIN_12[10:0]|
|||||||GAM_R_LUT8: GAM_R_GAIN_14[10:0]|
|||||||GAM_R_LUT9: GAM_R_GAIN_16[10:0]|
|||||||GAM_R_LUT10: GAM_R_GAIN_18[10:0]|
|||||||GAM_R_LUT11: GAM_R_GAIN_20[10:0]|
|||||||GAM_R_LUT12: GAM_R_GAIN_22[10:0]|
|||||||GAM_R_LUT13: GAM_R_GAIN_24[10:0]|
|||||||GAM_R_LUT14: GAM_R_GAIN_26[10:0]|
|||||||GAM_R_LUT15: GAM_R_GAIN_28[10:0]|
|||||||GAM_R_LUT16: GAM_R_GAIN_30[10:0]|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|10|to|0|*|1024|R/W|GAM_R_LUT1: Gain Adjustment of Area 1 of R Signal|
|||||||GAM_R_LUT2: Gain Adjustment of Area 3 of R Signal|
|||||||GAM_R_LUT3: Gain Adjustment of Area 5 of R Signal|
|||||||GAM_R_LUT4: Gain Adjustment of Area 7 of R Signal|
|||||||GAM_R_LUT5: Gain Adjustment of Area 9 of R Signal|
|||||||GAM_R_LUT6: Gain Adjustment of Area 11 of R Signal|
|||||||GAM_R_LUT7: Gain Adjustment of Area 13 of R Signal|
|||||||GAM_R_LUT8: Gain Adjustment of Area 15 of R Signal|
|||||||GAM_R_LUT9: Gain Adjustment of Area 17 of R Signal|
|||||||GAM_R_LUT10: Gain Adjustment of Area 19 of R Signal|
|||||||GAM_R_LUT11: Gain Adjustment of Area 21 of R Signal|
|||||||GAM_R_LUT12: Gain Adjustment of Area 23 of R Signal|
|||||||GAM_R_LUT13: Gain Adjustment of Area 25 of R Signal|
|||||||GAM_R_LUT14: Gain Adjustment of Area 27 of R Signal|
|||||||GAM_R_LUT15: Gain Adjustment of Area 29 of R Signal|
|||||||GAM_R_LUT16: Gain Adjustment of Area 31 of R Signal|
|||||||Unsigned (0 to 2047 [LSB], 1024 [LSB] = 1.0 [times])|
|||||||*: Bit Name|
|||||||GAM_R_LUT1: GAM_R_GAIN_01[10:0]|
|||||||GAM_R_LUT2: GAM_R_GAIN_03[10:0]|
|||||||GAM_R_LUT3: GAM_R_GAIN_05[10:0]|
|||||||GAM_R_LUT4: GAM_R_GAIN_07[10:0]|
|||||||GAM_R_LUT5: GAM_R_GAIN_09[10:0]|
|||||||GAM_R_LUT6: GAM_R_GAIN_11[10:0]|
|||||||GAM_R_LUT7: GAM_R_GAIN_13[10:0]|
|||||||GAM_R_LUT8: GAM_R_GAIN_15[10:0]|
|||||||GAM_R_LUT9: GAM_R_GAIN_17[10:0]|
|||||||GAM_R_LUT10: GAM_R_GAIN_19[10:0]|
|||||||GAM_R_LUT11: GAM_R_GAIN_21[10:0]|
|||||||GAM_R_LUT12: GAM_R_GAIN_23[10:0]|
|||||||GAM_R_LUT13: GAM_R_GAIN_25[10:0]|
|||||||GAM_R_LUT14: GAM_R_GAIN_27[10:0]|
|||||||GAM_R_LUT15: GAM_R_GAIN_29[10:0]|
|||||||GAM_R_LUT16: GAM_R_GAIN_31[10:0]|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.24 Area Setting Register R1 in Gamma Correction Block (GAM_R_AREA1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||-|-<br>-<br>-<br>-<br>GAM_R_TH_01[7:0]||||-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||-|-<br>-<br>-<br>-<br>GAM_R_TH_02[7:0]||||-|-||-|-<br>-<br>-<br>-<br>GAM_R_TH_03[7:0]||||-|-|
|Initial value:|0|0|0|1|0|0|0|0|0|0|0|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|23 to 16|GAM_R_TH_01[7:0]|8|R/W|Start Threshold of Area 1 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||0 < Threshold of current area < Threshold of next area|
|15 to 8|GAM_R_TH_02[7:0]|16|R/W|Start Threshold of Area 2 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_R_TH_03[7:0]|24|R/W|Start Threshold of Area 3 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.25 Area Setting Register R2 in Gamma Correction Block (GAM_R_AREA2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_R_TH_04[7:0]||||||||GAM_R_TH_05[7:0]||||||
|Initial value:|0|0|1|0|0|0|0|0|0|0|1|0|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GAM_R_TH_06[7:0]||||||||GAM_R_TH_07[7:0]||||||
|Initial value:|0|0|1|1|0|0|0|0|0|0|1|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_R_TH_04[7:0]|32|R/W|Start Threshold of Area 4 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_R_TH_05[7:0]|40|R/W|Start Threshold of Area 5 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_R_TH_06[7:0]|48|R/W|Start Threshold of Area 6 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_R_TH_07[7:0]|56|R/W|Start Threshold of Area 7 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.26 Area Setting Register R3 in Gamma Correction Block (GAM_R_AREA3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_R_TH_08[7:0]||||||||GAM_R_TH_09[7:0]||||||
|Initial value:|0|1|0|0|0|0|0|0|0|1|0|0|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GAM_R_TH_10[7:0]||||||||GAM_R_TH_11[7:0]||||||
|Initial value:|0|1|0|1|0|0|0|0|0|1|0|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_R_TH_08[7:0]|64|R/W|Start Threshold of Area 8 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_R_TH_09[7:0]|72|R/W|Start Threshold of Area 9 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_R_TH_10[7:0]|80|R/W|Start Threshold of Area 10 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_R_TH_11[7:0]|88|R/W|Start Threshold of Area 11 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.27 Area Setting Register R4 in Gamma Correction Block (GAM_R_AREA4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_R_TH_12[7:0]||||||||GAM_R_TH_13[7:0]|||||||
|Initial value:|0|1|1|0|0|0|0|0|0|1|1|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_R_TH_14[7:0]||||||||GAM_R_TH_15[7:0]|||||||
|Initial value:|0|1|1|1|0|0|0|0|0|1|1|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_R_TH_12[7:0]|96|R/W|Start Threshold of Area 12 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_R_TH_13[7:0]|104|R/W|Start Threshold of Area 13 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_R_TH_14[7:0]|112|R/W|Start Threshold of Area 14 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_R_TH_15[7:0]|120|R/W|Start Threshold of Area 15 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.28 Area Setting Register R5 in Gamma Correction Block (GAM_R_AREA5)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_R_TH_16[7:0]||||||||GAM_R_TH_17[7:0]|||||||
|Initial value:|1|0|0|0|0|0|0|0|1|0|0|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GAM_R_TH_18[7:0]||||||||GAM_R_TH_19[7:0]|||||||
|Initial value:|1|0|0|1|0|0|0|0|1|0|0|1|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_R_TH_16[7:0]|128|R/W|Start Threshold of Area 16 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_R_TH_17[7:0]|136|R/W|Start Threshold of Area 17 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_R_TH_18[7:0]|144|R/W|Start Threshold of Area 18 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_R_TH_19[7:0]|152|R/W|Start Threshold of Area 19 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.29 Area Setting Register R6 in Gamma Correction Block (GAM_R_AREA6)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_R_TH_20[7:0]||||||||GAM_R_TH_21[7:0]||||||
|Initial value:|1|0|1|0|0|0|0|0|1|0|1|0|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GAM_R_TH_22[7:0]||||||||GAM_R_TH_23[7:0]||||||
|Initial value:|1|0|1|1|0|0|0|0|1|0|1|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_R_TH_20[7:0]|160|R/W|Start Threshold of Area 20 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_R_TH_21[7:0]|168|R/W|Start Threshold of Area 21 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_R_TH_22[7:0]|176|R/W|Start Threshold of Area 22 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_R_TH_23[7:0]|184|R/W|Start Threshold of Area 23 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.30 Area Setting Register R7 in Gamma Correction Block (GAM_R_AREA7)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_R_TH_24[7:0]||||||||GAM_R_TH_25[7:0]||||||
|Initial value:|1|1|0|0|0|0|0|0|1|1|0|0|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GAM_R_TH_26[7:0]||||||||GAM_R_TH_27[7:0]||||||
|Initial value:|1|1|0|1|0|0|0|0|1|1|0|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_R_TH_24[7:0]|192|R/W|Start Threshold of Area 24 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_R_TH_25[7:0]|200|R/W|Start Threshold of Area 25 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_R_TH_26[7:0]|208|R/W|Start Threshold of Area 26 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_R_TH_27[7:0]|216|R/W|Start Threshold of Area 27 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.31 Area Setting Register R8 in Gamma Correction Block (GAM_R_AREA8)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GAM_R_TH_28[7:0]||||||||GAM_R_TH_29[7:0]||||||
|Initial value:|1|1|1|0|0|0|0|0|1|1|1|0|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GAM_R_TH_30[7:0]||||||||GAM_R_TH_31[7:0]||||||
|Initial value:|1|1|1|1|0|0|0|0|1|1|1|1|1|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GAM_R_TH_28[7:0]|224|R/W|Start Threshold of Area 28 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|23 to 16|GAM_R_TH_29[7:0]|232|R/W|Start Threshold of Area 29 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|15 to 8|GAM_R_TH_30[7:0]|240|R/W|Start Threshold of Area 30 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area < Threshold|
|||||of next area|
|7 to 0|GAM_R_TH_31[7:0]|248|R/W|Start Threshold of Area 31 of R Signal|
|||||Unsigned (0 to 255 [LSB])|
|||||Threshold of previous area < Threshold of current area ≤ 255|

Note: This register is updated when GAM_R_VEN in GAM_R_UPDATE is 1.

## 34.2.32 TCON Register Update Control Register (TCON_UPDATE)

||Bit:|31|30|29|||28|27||26|25|24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|**—**|**—**|||**—**|**—**||**—**|**—**|**—**<br>**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||
|Initial|value:|0|0|0|||0|0||0|0|0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R|R|||R|R||R|R|R<br>R|R|R|R|R|R|R|R||
||Bit:|15|14|13|||12|11||10|9|8<br>7|6|5|4|3|2|1|0||
||||||||||||||||||||TCON_||
|||**—**|**—**|**—**|||**—**|**—**||**—**|**—**|**—**<br>**—**|**—**|**—**|**—**|**—**|**—**|**—**|VEN||
|Initial|value:|0|0|0|||0|0||0|0|0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R|R|||R|R||R|R|R<br>R|R|R|R|R|R|R|R/WC1||
|**Bit**|**Bit Name**||||**Initial Value**<br>**R/W**|||||||**Description**|||||||||
|31 to 1|—||||All||0|R||||Reserved|||||||||
|||||||||||||These bits are|always read as 0. The write value should always be 0.||||||||
|0|TCON_VEN||||0|||R/WC1||||LCD TCON Register Update|||||||||
|||||||||||||0: Registers are not updated.|||||||||
|||||||||||||1: Registers are updated at the rising edge|||||of the Vsync.||||

## 34.2.33 TCON Reference Timing Setting Register (TCON_TIM)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|||||TCON_HALF[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|1|1|0|0|1|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**|||||TCON_OFFSET[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|TCON_HALF[10:0]|400|R/W|1/2fH Timing|
|||||||Specifies the clock count from the rising edge of the Hsync signal as|
|||||||the counting timing of horizontal counter.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|TCON_OFFSET[10:0]|0|R/W|Offset Hsync Signal Timing|
|||||||Sets the clock cycle count from the rising edge of the Hsync signal.|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.34 TCON Vertical Timing Setting Register A1 (TCON_TIM_STVA1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**||||TCON_STVA_VS[10:0]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**||||TCON_STVA_VW[10:0]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|1|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|TCON_STVA_VS|0|R/W|STVA Signal Pulse Start Position (First Changing Timing)|
||||[10:0]|||Starts pulse output after the time specified by the value of|
|||||||TCON_STVA_VS from the rising edge of the Vsync signal (1/2fH|
|||||||cycles).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|TCON_STVA_VW|4|R/W|STVA Pulse Width (Second Changing Timing)|
||||[10:0]|||Outputs a pulse of the duration of the value of TCON_STVA_VW (1/|
|||||||2fH cycles).|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.35 TCON Vertical Timing Setting Register A2 (TCON_TIM_STVA2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||||||TCON_|||||
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|STVA_<br>INV|—|TCON_STVA_SEL[2:0]|||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|TCON_STVA_INV|1|R/W|Polarity Inversion Control of STVA Signal|
|||||0: Not inverted|
|||||1: Inverted|
|3|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|2 to 0|TCON_STVA_SEL|0|R/W|Output Signal Select for LCD_TCON0 Pin|
||[2:0]|||0: STVA/VS|
|||||1: STVB/VE|
|||||2: STH/SP/HS|
|||||3: STB/LP/HE|
|||||4: CPV/GCK|
|||||5: POLA|
|||||6: POLB|
|||||7: DE|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.36 TCON Vertical Timing Setting Register B1 (TCON_TIM_STVB1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|||||TCON_STVB_VS[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|1|0|0|0|1|1|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**||||TCON_STVB_VW[10:0]|||||||||
|Initial value:|0|0|0|0|0|0|1|1|1|1|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|TCON_STVB_VS|70|R/W|STVB Signal Pulse Start Position (First Changing Timing)|
||||[10:0]|||Starts pulse output after the time specified by the value of|
|||||||TCON_STVB_VS from the rising edge of the Vsync signal (1/2fH|
|||||||cycles).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|TCON_STVB_VW|960|R/W|STVB Pulse Width (Second Changing Timing)|
||||[10:0]|||Outputs a pulse of the duration of the value of TCON_STVB_VW (1/|
|||||||2fH cycles).|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.37 TCON Vertical Timing Setting Register B2 (TCON_TIM_STVB2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|TCON_<br>STVB_<br>INV|**—**|TCON_STVB_SEL[2:0]||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|TCON_STVB_INV|0|R/W|Polarity Inversion Control of STVB Signal|
|||||0: Not inverted|
|||||1: Inverted|
|3|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|2 to 0|TCON_STVB_SEL|1|R/W|Output Signal Select for LCD_TCON1 Pin|
||[2:0]|||0: STVA/VS|
|||||1: STVB/VE|
|||||2: STH/SP/HS|
|||||3: STB/LP/HE|
|||||4: CPV/GCK|
|||||5: POLA|
|||||6: POLB|
|||||7: DE|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.38 TCON Horizontal Timing Setting Register STH1 (TCON_TIM_STH1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|||||TCON_STH_HS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||**—**|**—**|**—**|**—**|**—**|||||TCON_STH_HW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|1|1|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|TCON_STH_HS|0|R/W|STH Signal Pulse Start Position (First Changing Timing)|
||||[10:0]|||Starts pulse output after the time specified by the value of|
|||||||TCON_STH_HS + 1 from the rising edge of the Hsync signal (clock|
|||||||cycles).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|TCON_STH_HW|96|R/W|STH Pulse Width (Second Changing Timing)|
||||[10:0]|||Outputs a pulse of the duration of the value of TCON_STH_HW|
|||||||(clock cycles).|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.39 TCON Horizontal Timing Setting Register STH2 (TCON_TIM_STH2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|TCON_<br>STH_HS_<br>SEL|**—**|**—**|**—**|TCON_<br>STH_INV|**—**|TCON_STH_SEL[2:0]||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|1|0|0|1|0||
|R/W:|R|R|R|R|R|R|R|R/W|R|R|R|R/W|R|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|TCON_STH_HS_|0|R/W|STH Signal Operating Reference Select|
||SEL|||0: Hsync signal reference|
|||||1: Offset Hsync signal reference|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|TCON_STH_INV|1|R/W|Polarity Inversion Control of STH Signal|
|||||0: Not inverted|
|||||1: Inverted|
|3|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|2 to 0|TCON_STH_SEL|2|R/W|Output Signal Select for LCD_TCON2 Pin|
||[2:0]|||0: STVA/VS|
|||||1: STVB/VE|
|||||2: STH/SP/HS|
|||||3: STB/LP/HE|
|||||4: CPV/GCK|
|||||5: POLA|
|||||6: POLB|
|||||7: DE|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.40 TCON Horizontal Timing Setting Register STB1 (TCON_TIM_STB1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|||||TCON_STB_HS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|1|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||**—**|**—**|**—**|**—**|**—**|||||TCON_STB_HW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|TCON_STB_HS|144|R/W|STB Signal Pulse Start Position (First Changing Timing)|
||||[10:0]|||Starts pulse output after the time specified by the value of|
|||||||TCON_STB_HS + 1 from the rising edge of the Hsync signal (clock|
|||||||cycles).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|TCON_STB_HW|640|R/W|STB Pulse Width (Second Changing Timing)|
||||[10:0]|||Outputs a pulse of the duration of the value of TCON_STB_HW|
|||||||(clock cycles).|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.41 TCON Horizontal Timing Setting Register STB2 (TCON_TIM_STB2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|TCON_<br>STB_HS_<br>SEL|**—**|**—**|**—**|TCON_<br>STB_INV|**—**|TCON_STB_SEL[2:0]||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|1|1|1||
|R/W:|R|R|R|R|R|R|R|R/W|R|R|R|R/W|R|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|TCON_STB_HS_|0|R/W|STB Signal Operating Reference Select|
||SEL|||0: Hsync signal reference|
|||||1: Offset Hsync signal reference|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|TCON_STB_INV|0|R/W|Polarity Inversion Control of STB Signal|
|||||0: Not inverted|
|||||1: Inverted|
|3|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|2 to 0|TCON_STB_SEL|7|R/W|Output Signal Select for LCD_TCON3 Pin|
||[2:0]|||0: STVA/VS|
|||||1: STVB/VE|
|||||2: STH/SP/HS|
|||||3: STB/LP/HE|
|||||4: CPV/GCK|
|||||5: POLA|
|||||6: POLB|
|||||7: DE|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.42 TCON Horizontal Timing Setting Register CPV1 (TCON_TIM_CPV1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|||||TCON_CPV_HS[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**|||||TCON_CPV_HW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|TCON_CPV_HS|0|R/W|CPV Signal Pulse Start Position (First Changing Timing)|
||||[10:0]|||Starts pulse output after the time specified by the value of|
|||||||TCON_CPV_HS + 1 from the rising edge of the Hsync signal (clock|
|||||||cycles).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|TCON_CPV_HW|0|R/W|CPV Pulse Width (Second Changing Timing)|
||||[10:0]|||Outputs a pulse of the duration of the value of TCON_CPV_HW|
|||||||(clock cycles).|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.43 TCON Horizontal Timing Setting Register CPV2 (TCON_TIM_CPV2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|TCON_<br>CPV_HS_<br>SEL|**—**|**—**|**—**|TCON_<br>CPV_INV|—|TCON_CPV_SEL[2:0]||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|1|0|0||
|R/W:|R|R|R|R|R|R|R|R/W|R|R|R|R/W|R|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|TCON_CPV_HS_|0|R/W|CPV Signal Operating Reference Select|
||SEL|||0: Hsync signal reference|
|||||1: Offset Hsync signal reference|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|TCON_CPV_INV|0|R/W|Polarity Inversion Control of CPV Signal|
|||||0: Not inverted|
|||||1: Inverted|
|3|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|2 to 0|TCON_CPV_SEL|4|R/W|Output Signal Select for LCD_TCON4 Pin|
||[2:0]|||0: STVA/VS|
|||||1: STVB/VE|
|||||2: STH/SP/HS|
|||||3: STB/LP/HE|
|||||4: CPV/GCK|
|||||5: POLA|
|||||6: POLB|
|||||7: DE|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.44 TCON Horizontal Timing Setting Register POLA1 (TCON_TIM_POLA1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**||||TCON_POLA_HS[10:0]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|**—**|**—**|**—**||||TCON_POLA_HW[10:0]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|TCON_POLA_HS|0|R/W|POLA Signal Pulse Start Position (First Changing Timing)|
||||[10:0]|||Starts pulse output after the time specified by the value of|
|||||||TCON_POLA_HS from the rising edge of the Hsync signal (clock|
|||||||cycles).|
|||||||Note: When 1 × 1, 1 × 2, or 2 × 2 reverse mode is selected, these|
|||||||bits should be set to1 or greater.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|TCON_POLA_HW|0|R/W|POLA Pulse Width (Second Changing Timing)|
||||[10:0]|||Outputs a pulse of the duration of the value of TCON_POLA_HW|
|||||||(clock cycles).|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.45 TCON Horizontal Timing Setting Register POLA2 (TCON_TIM_POLA2)

||Bit:|31|30|29|||28|28|27||26|25|24<br>23|22|21|20||19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|**—**|**—**|||**—**||**—**||**—**|**—**|**—**<br>**—**|**—**|**—**|**—**||**—**|**—**|**—**|**—**||
|Initial|value:|0|0|0||||0|0||0|0|0<br>0|0|0|0||0|0|0|0||
||R/W:|R|R|R||||R|R||R|R|R<br>R|R|R|R||R|R|R|R||
||Bit:|15|14|13|||12||11||10|9|8<br>7|6|5|4||3|2|1|0||
|||—|—|-<br>-<br>TCON_<br>POLA_MD[1:0]|||||**—**||**—**|**—**|TCON_<br>POLA_HS<br>_SEL<br>**—**|**—**|**—**|TCON_<br>POLA_<br>INV||—|TCON_POLA_SEL[2:0]||||
|Initial|value:|0|0|0||||1|0||0|0|0<br>0|0|0|0||0|1|0|1||
||R/W:|R|R|R/W|||R/W||R||R|R|R/W<br>R|R|R|R/W||R|R/W|R/W|R/W||
|**Bit**|**Bit Name**||||**Initial Value**<br>**R/W**||||||||**Description**||||||||||
|31 to 14|—||||All||0||R||||Reserved||||||||||
||||||||||||||These bits are|always read as 0. The write value should always be 0.|||||||||
|13, 12|TCON_POLA_MD||||1||||R/W||||POLA Signal Generation Mode Select||||||||||
||[1:0]||||||||||||0: Normal mode||||||||||
||||||||||||||Generates the|signal that changes twice a horizontal period.|||||||||
||||||||||||||1: 1 × 1 reverse mode||||||||||
||||||||||||||Generates the|signal whose polarity|||is|inverted every horizontal|||||
||||||||||||||period.||||||||||
||||||||||||||2: 1 × 2 reverse mode||||||||||
||||||||||||||Generates the|signal whose polarity|||is|inverted in the first horizontal|||||
||||||||||||||period and is subsequently inverted||||every two horizontal periods.||||||
||||||||||||||3: 2 × 2 reverse mode||||||||||
||||||||||||||Generates the|signal whose polarity|||is|inverted every two horizontal|||||
||||||||||||||periods.||||||||||
|11 to 9|—||||All||0||R||||Reserved||||||||||
||||||||||||||These bits are|always read as 0. The write value should always be 0.|||||||||
|8|TCON_POLA_HS||||0||||R/W||||POLA Signal Operating Reference Select||||||||||
||_SEL||||||||||||0: Hsync signal reference||||||||||
||||||||||||||1: Offset Hsync signal reference||||||||||
|7 to 5|—||||All||0||R||||Reserved||||||||||
||||||||||||||These bits are|always read as 0. The write value should always be 0.|||||||||
|4|TCON_POLA_INV||||0||||R/W||||Polarity Inversion Control of POLA Signal||||||||||
||||||||||||||0: Not inverted||||||||||
||||||||||||||1: Inverted||||||||||
|3|—||||0||||R||||Reserved||||||||||
||||||||||||||This bit is always read as 0. The write|||||value should always be 0.|||||
|2 to 0|TCON_POLA_SEL||||5||||R/W||||Output Signal Select for LCD_TCON5|||||pin|||||
||[2:0]||||||||||||0: STVA/VS||||||||||
||||||||||||||1: STVB/VE||||||||||
||||||||||||||2: STH/SP/HS||||||||||
||||||||||||||3: STB/LP/HE||||||||||
||||||||||||||4: CPV/GCK||||||||||
||||||||||||||5: POLA||||||||||
||||||||||||||6: POLB||||||||||
||||||||||||||7: DE||||||||||

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.46 TCON Horizontal Timing Setting Register POLB1 (TCON_TIM_POLB1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**||||TCON_POLB_HS[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||**—**|**—**|**—**|**—**|**—**||||TCON_POLB_HW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|TCON_POLB_HS|0|R/W|POLB Signal Pulse Start Position (First Changing Timing)|
||||[10:0]|||Starts pulse output after the time specified by the value of|
|||||||TCON_POLB_HS from the rising edge of the Hsync signal (clock|
|||||||cycles).|
|||||||Note: When 1 × 1, 1 × 2, or 2 × 2 reverse mode is selected, these|
|||||||bits should be set to1 or greater.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|TCON_POLB_HW|0|R/W|POLB Pulse Width (Second Changing Timing)|
||||[10:0]|||Outputs a pulse of the duration of the value of TCON_POLB_HW|
|||||||(clock cycles).|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.47 TCON Horizontal Timing Setting Register POLB2 (TCON_TIM_POLB2)

||Bit:|31|30|29|29||28|27||26|25|24<br>23|22|21|20||19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|**—**|**—**|||**—**|**—**||**—**|**—**|**—**<br>**—**|**—**|**—**|**—**||**—**|**—**|**—**|**—**||
|Initial|value:|0|0|0|||0|0||0|0|0<br>0|0|0|0||0|0|0|0||
||R/W:|R|R|R|||R|R||R|R|R<br>R|R|R|R||R|R|R|R||
||Bit:|15|14|13|||12|11||10|9|8<br>7|6|5|4||3|2|1|0||
|||**—**|**—**|-<br>-<br>TCON_<br>POLB_MD[1:0]||||**—**||**—**|—|TCON_<br>POLB_HS<br>_SEL<br>**—**|**—**|**—**|TCON_<br>POLB_<br>INV||**—**|TCON_POLB_SEL[2:0]||||
|Initial|value:|0|0|0|||1|0||0|0|0<br>0|0|0|0||0|1|1|0||
||R/W:|R|R|R/W|||R/W|R||R|R|R/W<br>R|R|R|R/W||R|R/W|R/W|R/W||
|**Bit**|**Bit Name**||||**Initial Value**<br>**R/W**|||||||**Description**||||||||||
|31 to 14|—||||All||0|R||||Reserved||||||||||
|||||||||||||These bits are|always read as 0. The write value should always be 0.|||||||||
|13, 12|TCON_POLB_MD||||1|||R/W||||POLB Signal Generation Mode Select||||||||||
||[1:0]|||||||||||0: Normal mode||||||||||
|||||||||||||Generates the signal that changes twice a horizontal period.||||||||||
|||||||||||||1: 1 × 1 reverse mode||||||||||
|||||||||||||Generates the signal whose polarity||||is|inverted every horizontal|||||
|||||||||||||period.||||||||||
|||||||||||||2: 1 × 2 reverse mode||||||||||
|||||||||||||Generates the signal whose polarity||||is|inverted in the first horizontal|||||
|||||||||||||period and is subsequently inverted||||every two horizontal periods.||||||
|||||||||||||3: 2 × 2 reverse mode||||||||||
|||||||||||||Generates the|signal whose polarity|||is|inverted every two horizontal|||||
|||||||||||||periods.||||||||||
|11 to 9|—||||All||0|R||||Reserved||||||||||
|||||||||||||These bits are|always read as 0. The write value should always be 0.|||||||||
|8|TCON_POLB_HS||||0|||R/W||||POLB Signal Operating Reference Select||||||||||
||_SEL|||||||||||0: Hsync signal reference||||||||||
|||||||||||||1: Offset Hsync signal reference||||||||||
|7 to 5|—||||All||0|R||||Reserved||||||||||
|||||||||||||These bits are|always read as 0. The write value should always be 0.|||||||||
|4|TCON_POLB_INV||||0|||R/W||||Polarity Inversion Control of POLB Signal||||||||||
|||||||||||||0: Not inverted||||||||||
|||||||||||||1: Inverted||||||||||
|3|—||||0|||R||||Reserved||||||||||
|||||||||||||This bit is always read as 0. The write|||||value should always be 0.|||||
|2 to 0|TCON_POLB_SEL||||6|||R/W||||Output Signal Select for LCD_TCON6|||||pin|||||
||[2:0]|||||||||||0: STVA/VS||||||||||
|||||||||||||1: STVB/VE||||||||||
|||||||||||||2: STH/SP/HS||||||||||
|||||||||||||3: STB/LP/HE||||||||||
|||||||||||||4: CPV/GCK||||||||||
|||||||||||||5: POLA||||||||||
|||||||||||||6: POLB||||||||||
|||||||||||||7: DE||||||||||

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.48 TCON Data Enable Polarity Setting Register (TCON_TIM_DE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||||||TCON_||
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|DE_INV||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||TCON_DE_INV|0|R/W|Polarity Inversion Control of DE Signal|
|||||||0: Not inverted|
|||||||1: Inverted|

Note: This register is updated when TCON_VEN in TCON_UPDATE is 1.

## 34.2.49 Register Update Control Register in Output Controller (OUT_UPDATE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||**—**||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1||0||
||||||||||||||||||OUTCNT||
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||_VEN||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/WC1|||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||OUTCNT_VEN|0|R/WC1|Brightness/Contrast, Dither Process, Output Interface Register|
|||||||Update|
|||||||0: Registers are not updated.|
|||||||1: Registers are updated at the rising edge of the Vsync.|

## 34.2.50 Output Interface Register (OUT_SET)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||OUT_||||OUT_||||||||||
||—|**—**|**—**|ENDIAN_|**—**|**—**|**—**|SWAP_|**—**|—|**—**|**—**|**—**|**—**|—|**—**||
|||||ON||||ON||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|1|1|1|1|1||
|R/W:|R|R|R|R/W|R|R|R|R/W|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||**—**|**—**|OUT_<br>FORMAT[1:0]||—|—|OUT_FRQ_SEL[1:0]||**—**|**—**|**—**|OUT_<br>DIR_<br>SEL|**—**|**—**|OUT_PHASE[1:0]|||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R|R/W|R|R|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 29|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|28|OUT_ENDIAN_ON|0|R/W|Bit Endian Change On/Off Control|
|||||0: Off|
|||||1: On|
|27 to 25|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|24|OUT_SWAP_ON|0|R/W|B/R Signal Swap On/Off Control|
|||||0: Off|
|||||1: On|
|23 to 21|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|20 to 16|—|All 1|R|Reserved|
|||||These bits are always read as 1. The write value should always be 1.|
|15, 14|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|13, 12|OUT_FORMAT[1:0]|0|R/W|Output Format Select|
|||||0: RBG888|
|||||1: RGB666|
|||||2: RGB565|
|||||3: Serial RGB|
|11, 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9, 8|OUT_FRQ_SEL|0|R/W|Clock Frequency Control|
||[1:0]|||0: 100% speed — (parallel RGB)|
|||||1: Triple speed — (serial RGB)|
|||||2: Quadruple speed — (serial RGB)|
|||||3: Setting prohibited|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|OUT_DIR_SEL|0|R/W|Scan Direction Select|
|||||0: Forward scan|
|||||1: Reverse scan|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|1, 0|OUT_PHASE[1:0]|0|R/W|Clock Phase Adjustment During Serial RGB Output|
|||||Triple speed mode|
|||||0: 0 (clk)|
|||||1: 1 (clk)|
|||||2: 2 (clk)|
|||||3: Setting prohibited|
|||||Quadruple speed mode|
|||||0: 0 (clk)|
|||||1: 1 (clk)|
|||||2: 2 (clk)|
|||||3: 3 (clk)|

Note: This register is updated when OUTCNT_VEN in OUT_UPDATE is 1.

## 34.2.51 Brightness (DC) Correction Register 1 (OUT_BRIGHT1)

||Bit:|31|30|29||28|27||26|25||24<br>23||22|21|20|19|18||17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|**—**|**—**||**—**|**—**||**—**|**—**||**—**<br>**—**||**—**|**—**|**—**|**—**|**—**||**—**|**—**||
|Initial|value:|0|0|0||0|0||0|0||0<br>0||0|0|0|0|0||0|0||
||R/W:|R|R|R||R|R||R|R||R<br>R||R|R|R|R|R||R|R||
||Bit:|15|14|13||12|11||10|9||8<br>7||6|5|4|3|2||1|0||
|||**—**|**—**|**—**||**—**|**—**||**—**||||||PBRT_G[9:0]||||||||
|Initial|value:|0|0|0||0|0||0|1||0<br>0||0|0|0|0|0||0|0||
||R/W:|R|R|R||R|R||R|R/W||R/W<br>R/W||R/W|R/W|R/W|R/W|R/W||R/W|R/W||
|**Bit**|**Bit Name**||||**Initial Value**<br>**R/W**||||||**Description**||||||||||||
|31 to 10|—||||All 0||R||||Reserved||||||||||||
||||||||||||These bits are|||always read as 0. The write value should always be 0.|||||||||
|9 to 0|PBRT_G[9:0]||||512||R/W||||Brightness (DC) Adjustment of G Signal||||||||||||
||||||||||||Unsigned (0 (-512) to||||512 (0) to 1023 (+511) [LSB],|||||512 [LSB] with|||
||||||||||||offset)||||||||||||

Note: This register is updated when OUTCNT_VEN in OUT_UPDATE is 1.

## 34.2.52 Brightness (DC) Correction Register 2 (OUT_BRIGHT2)

||Bit:|31|30|29||28|27||26|25|24<br>23|22|21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||**—**|**—**|**—**||**—**|**—**||**—**||||PBRT_B[9:0]||||||
|Initial value:||0|0|0||0|0||0|1|0<br>0|0|0<br>0|0|0|0|0||
||R/W:|R|R|R||R|R||R|R/W|R/W<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14|13||12|11||10|9|8<br>7|6|5<br>4|3|2|1|0||
|||**—**|**—**|**—**||**—**|**—**||**—**||||PBRT_R[9:0]||||||
|Initial value:||0|0|0||0|0||0|1|0<br>0|0|0<br>0|0|0|0|0||
||R/W:|R|R|R||R|R||R|R/W|R/W<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**|**Bit Name**||||**Initial Value**|||**R/W**|||**Description**||||||||
|31 to 26|—||||All 0|||R|||Reserved||||||||
||||||||||||These bits are|always|read as 0. The|write value should always be 0.|||||
|25 to 16|PBRT_B[9:0]||||512|||R/W|||Brightness (DC) Adjustment of B Signal||||||||
||||||||||||Unsigned (0 (-512) to||512 (0) to 1023 (+511) [LSB],|||512 [LSB] with|||
||||||||||||offset)||||||||
|15 to 10|—||||All 0|||R|||Reserved||||||||
||||||||||||These bits are|always|read as 0. The|write value should always be 0.|||||
|9 to 0|PBRT_R[9:0]||||512|||R/W|||Brightness (DC) Adjustment of R Signal||||||||
||||||||||||Unsigned (0 (-512) to||512 (0) to 1023 (+511) [LSB],|||512 [LSB] with|||
||||||||||||offset)||||||||

Note: This register is updated when OUTCNT_VEN in OUT_UPDATE is 1.

## 34.2.53 Contrast (Gain) Correction Register (OUT_CONTRAST)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**||||CONT_G[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||CONT_B[7:0]||||||||CONT_R[7:0]|||||
|Initial value:|1|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|23 to 16|CONT_G[7:0]|128|R/W|Contrast (Gain) Adjustment of G Signal|
|||||0/128 to 255/128 (approx.2 times)|
|15 to 8|CONT_B[7:0]|128|R/W|Contrast (Gain) Adjustment of B Signal|
|||||0/128 to 255/128 (approx.2 times)|
|7 to 0|CONT_R[7:0]|128|R/W|Contrast (Gain) Adjustment of R Signal|
|||||0/128 to 255/128 (approx.2 times)|

Note: This register is updated when OUTCNT_VEN in OUT_UPDATE is 1.

## 34.2.54 Panel Dither Register (OUT_PDTHA)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|**—**|PDTH_SEL[1:0]||**—**|**—**|PDTH_FORMAT[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R|R|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||**—**|**—**|PDTH_PA[1:0]||**—**|**—**|PDTH_PB[1:0]||**—**|**—**|PDTH_PC[1:0]||**—**|**—**|PDTH_PD[1:0]||
|Initial value:|0|0|1|1|0|0|0|0|0|0|1|0|0|0|0|1|
|R/W:|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 22|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|21, 20|PDTH_SEL[1:0]|0|R/W|Panel Dither Operation Mode|
|||||0: Truncate|
|||||1: Round-off|
|||||2: 2 × 2 pattern dither|
|||||3: Random pattern dither|
|19, 18|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|17, 16|PDTH_FORMAT|0|R/W|Panel Dither Output Format Select|
||[1:0]|||0: RGB888|
|||||1: RGB666|
|||||2: RGB565|
|||||3: Setting prohibited|
|15, 14|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|13, 12|PDTH_PA[1:0]|3|R/W|Pattern Value (A) of 2 × 2 Pattern Dither|
|||||Unsigned (0 to 3 [LSB])|
|11, 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9, 8|PDTH_PB[1:0]|0|R/W|Pattern Value (B) of 2 × 2 Pattern Dither|
|||||Unsigned (0 to 3 [LSB])|
|7, 6|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|5, 4|PDTH_PC[1:0]|2|R/W|Pattern Value (C) of 2 × 2 Pattern Dither|
|||||Unsigned (0 to 3 [LSB])|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1, 0|PDTH_PD[1:0]|1|R/W|Pattern Value (D) of 2 × 2 Pattern Dither|
|||||Unsigned (0 to 3 [LSB])|

Note: This register is updated when OUTCNT_VEN in OUT_UPDATE is 1.

## 34.2.55 Output Phase Control Register (OUT_CLK_PHASE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||OUTCNT_||||OUTCNT_||OUTCNT_|OUTCNT_|OUTCNT_|OUTCNT_|OUTCNT_|OUTCNT_|OUTCNT_||
||—|—|—|FRONT_|—|—|—|LCD_|—|STVA_|STVB_|STH_|STB_|CPV_|POLA_|POLB_||
|||||GAM||||EDGE||EDGE|EDGE|EDGE|EDGE|EDGE|EDGE|EDGE||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R/W|R|R|R|R/W|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 13|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|12|OUTCNT_|0|R/W|Correction Circuit Sequence Control|
||FRONT_GAM|||0: Brightness → contrast → gamma correction|
|||||1: Gamma correction → brightness → contrast|
|11 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|OUTCNT_|0|R/W|Output Phase Control of LCD_DATA23 to LCD_DATA0 Pin|
||LCD_EDGE|||0: Output at the rising edge of LCD_CLK pin|
|||||1: Output at the falling edge of LCD_CLK pin|
|7|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|6|OUTCNT_|0|R/W|Output Phase Control of LCD_TCON0 Pin|
||STVA_EDGE|||0: Output at the rising edge of LCD_CLK pin|
|||||1: Output at the falling edge of LCD_CLK pin|
|5|OUTCNT_|0|R/W|Output Phase Control of LCD_TCON1 Pin|
||STVB_EDGE|||0: Output at the rising edge of LCD_CLK pin|
|||||1: Output at the falling edge of LCD_CLK pin|
|4|OUTCNT_|0|R/W|Output Phase Control of LCD_TCON2 Pin|
||STH_EDGE|||0: Output at the rising edge of LCD_CLK pin|
|||||1: Output at the falling edge of LCD_CLK pin|
|3|OUTCNT_|0|R/W|Output Phase Control of LCD_TCON3 Pin|
||STB_EDGE|||0: Output at the rising edge of LCD_CLK pin|
|||||1: Output at the falling edge of LCD_CLK pin|
|2|OUTCNT_|0|R/W|Output Phase Control of LCD_TCON4 Pin|
||CPV_EDGE|||0: Output at the rising edge of LCD_CLK pin|
|||||1: Output at the falling edge of LCD_CLK pin|
|1|OUTCNT_|0|R/W|Output Phase Control of LCD_TCON5 Pin|
||POLA_EDGE|||0: Output at the rising edge of LCD_CLK pin|
|||||1: Output at the falling edge of LCD_CLK pin|
|0|OUTCNT_|0|R/W|Output Phase Control of LCD_TCON6 Pin|
||POLB_EDGE|||0: Output at the rising edge of LCD_CLK pin|
|||||1: Output at the falling edge of LCD_CLK pin|

Note: This register is updated when OUTCNT_VEN in OUT_UPDATE is 1.

## 34.3 Usage Methods

## 34.3.1 Gamma Correction Adjustment Method

The characteristics of G, B, R of each panel to be connected should be measured and gamma correction should be made to suit the panel.

Since the gamma correction adjustment depends on to the characteristics of the panel, there are no recommended setting values.

## 34.3.2 Dither Usage Method

Dither is used when pseudo contour is appeared on the display screen.

**Table 34.26 Dither Settings**

|**Bit Name**|**Setting Value**|
|---|---|
|PDTH_FORMAT[1:0]|Selects the format.|
||For RGB888: 0|
||For RGB666: 1|
||For RGB565: 2|
|PDTH_SEL[1:0]|When 2 × 2 pattern dither is to be used: 2|
|PDTH_PA[1:0]|Normally 3 (initial value)|
|PDTH_PB[1:0]|Normally 0 (initial value)|
|PDTH_PC[1:0]|Normally 2 (initial value)|
|PDTH_PD[1:0]|Normally 1 (initial value)|

## 34.3.3 Output Format Adjustment Method

The setting example of the typical output format is shown in Table 34.27 and Table 34.28 .

It is necessary to carry out the setting of synchronization system signals of each output format similarly as the setting of output after scaling.

**Table 34.27 Setting Example of Synchronizing Signal**

|**Register Name**|**Bit Name**|**VGA**|**SVGA**|**Description**|
|---|---|---|---|---|
|TCON_TIM|TCON_HALF[10:0]|400|528|Sets the half value of 1H time period in clock|
|||||units.|
|**Vsync signal**|||||
|TCON_TIM_STVA1|TCON_STVA_VS[10:0]|0|0|Sets the pulse generation start position from|
|||||the rising edge of the internal Vsync signal.|
|||||A 1/2H time period is set as 1.|
|TCON_TIM_STVA1|TCON_STVA_VW[10:0]|4|8|Sets the changing point from the above pulse|
|||||generation start position.|
|||||A 1/2H time period is set as 1.|
|TCON_TIM_STVA2|TCON_STVA_INV|0|0|Sets the output polarity of the above pulse. For|
|||||inverted output: 1|
|TCON_TIM_STVA2|TCON_STVA_SEL[2:0]|0|0|For STVA output selection: 0|
|**Vertical enable signal**|||||
|TCON_TIM_STVB1|TCON_STVB_VS[10:0]|68|44|Sets the pulse generation start position from|
|||||the rising edge of the internal Vsync signal.|
|||||A 1/2H time period is set as 1.|
|TCON_TIM_STVB1|TCON_STVB_VW[10:0]|960|1200|Sets the changing point from the above pulse|
|||||generation start position.|
|||||A 1/2H time period is set as 1.|
|TCON_TIM_STVB2|TCON_STVB_INV|0|0|Sets the output polarity of the above pulse. For|
|||||inverted output: 1|
|TCON_TIM_STVB2|TCON_STVB_SEL[2:0]|1|1|For STVB output selection: 1|
|**Hsync signal**|||||
|TCON_TIM_STH1|TCON_STH_HS[10:0]|0|0|Sets the pulse generation start position from|
|||||the rising edge of the internal Hsync signal.|
|TCON_TIM_STH1|TCON_STH_HW[10:0]|96|128|Sets the changing point from the above pulse|
|||||generation start position.|
|TCON_TIM_STH2|TCON_STH_INV|0|0|Sets the output polarity of the above pulse. For|
|||||inverted output: 1|
|TCON_TIM_STH2|TCON_STH_SEL[2:0]|2|2|For STH output selection: 2|
|**Horizontal enable signal**|||||
|TCON_TIM_STB1|TCON_STB_HS[10:0]|128|192|Sets the pulse generation start position from|
|||||the rising edge of the internal Hsync signal.|
|TCON_TIM_STB1|TCON_STB_HW[10:0]|640|800|Sets the changing point from the above pulse|
|||||generation start position.|
|TCON_TIM_STB2|TCON_STB_INV|0|0|Sets the output polarity of the above pulse. For|
|||||inverted output: 1|
|TCON_TIM_STB2|TCON_STB_SEL[2:0]|3|3|For STB output selection: 3|

**Table 34.28 Setting Example of Data System**

||||**Serial RGB**||
|---|---|---|---|---|
|**Register Name**|**Bit Name**|**RGB888**|**(Triple Speed)**|**Description**|
|OUT_SET|OUT_ENDIAN_ON|0|0|When bit endian is changed: 1|
|OUT_SET|OUT_SWAP_ON|0|0|When B/R is to be swapped: 1|
|OUT_SET|OUT_FORMAT[1:0]|0|3|Sets the output format.|
|||||For RGB888: 0|
|||||For RGB666: 1|
|||||For RGB565: 2|
|||||For serial RGB: 3|
|OUT_SET|OUT_FRQ_SEL[1:0]|0|1|Sets the output clock.|
|||||For RGB888, RGB666, RGB565: 0|
|||||For triple speed serial RGB output: 1|
|||||For quadruple serial RGB output: 2|
|OUT_SET|OUT_DIR_SEL|0|0|When data arrangement of the serial RGB output is to be|
|||||reversed: 1|
|OUT_SET|OUT_PHASE[1:0]|0|0|Sets when output phase of the serial RGB is shifted.|
|||||Not delayed|
|||||Delayed by one clock cycle: 1|
|||||Delayed by two clock cycles: 2|
|||||Delayed by three clock cycles: 3 (applicable only for|
|||||quadruple speed mode)|
