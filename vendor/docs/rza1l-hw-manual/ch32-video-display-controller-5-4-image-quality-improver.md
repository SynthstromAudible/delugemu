# 32. Video Display Controller 5 (4): Image Quality Improver

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1730–1759. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 32.1 Image Quality Improver

## 32.1.1 Overview of Functions

The image quality improver subjects scaled YCbCr signals to black stretching, LTI/sharpness processing, and GBR conversion by using a color matrix.

The image quality improver does not act on RGB signals.

Figure 32.1 is a functional block diagram of the image quality improver. Image quality improver 0 is connected to scaler 0.

**==> picture [277 x 157] intentionally omitted <==**

**----- Start of picture text -----**<br>
Scaler 0 Image<br>HS,VS synthesizer<br>HS,VS<br>HE,VE<br>HE,VE RGB888<br>YCbCr/<br>RGB888 (24 bits)<br>(24 bits)<br>Register control<br>Image quality<br>improver 0<br>(TINT)<br>LTI(H2,4)<br>Black stretch Color matrix<br>Sharpness (H1,2,3)<br>**----- End of picture text -----**<br>

**Figure 32.1 Functional Block Diagram of Image Quality Improver**

## 32.1.2 Register Update Control

The control register for image quality improver controls the update timing entirely by vertical synchronous signals.

The vertical synchronous signal launched after the update control register is set to 1 is reflected in various registers, following which the update control register is automatically cleared to 0.

Note that registers for the improver can be identified by the number in the register name like ADJ0_xxxx. In the sections except for Register Description, however, the number is omitted like ADJ_xxxx for convenience sake.

## **Table 32.1 Register Update Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|ADJ_UPDATE|ADJ_VEN|0|Image Quality Improver Register Update|
||||0: Register is not updated.|
||||1: Register is updated by launch of vertical synchronous signal.|

## 32.1.3 Black Stretch

Black stretch refers to the black stretch correction of the Y signal of the input video signal of YCbCr format.

Correction of the Y signal is done by adjusting the time constant, depth (gain), and start point.

## Figure 32.2 is a drawing illustrating black stretch correction.

**==> picture [483 x 478] intentionally omitted <==**

**----- Start of picture text -----**<br>
Time constant Depth (gain) Start point<br>adjustment adjustment adjustment<br>Setting 1Setting 2Setting 3 Setting 1Setting 2Setting 3 Setting 1Setting 2Setting 3<br>BKSTR_T1[4:0] 8 9 10 BKSTR_T1[4:0] 8 8 8 BKSTR_T1[4:0] 8 8 8<br>BKSTR_T2[4:0] 8 7 5 BKSTR_T2[4:0] 8 8 8 BKSTR_T2[4:0] 8 8 8<br>BKSTR_D[3:0] 5 5 5 BKSTR_D[3:0] 3 6 9 BKSTR_D[3:0] 5 5 5<br>BKSTR_ST[3:0] 3 3 3 BKSTR_ST[3:0] 3 3 3 BKSTR_ST[3:0] 3 9 15<br>255 255 255<br>64 64 64<br>48 48 48<br>32 32 32<br>Setting 1 Setting 1 Setting 1<br>16 Setting 2 16 Setting 2 16 Setting 2<br>Setting 3 Setting 3 Setting 3<br>0 0 0<br>0 16 32 48 64 255 0 16 32 48 64 255 0 16 32 48 64 255<br>Input signal Input signal Input signal<br>Figure 32.2 Black Stretch Correction (With Sample Settings)<br>Table 32.2 Black Stretch Control<br>Register Name Bit Name Initial Value Description<br>ADJ_BKSTR_SET BKSTR_ON 0 Black Stretch On/Off Control<br>0: Black Stretch Off<br>1: Black Stretch On<br>ADJ_BKSTR_SET BKSTR_ST[3:0] 0 Black Stretch Start Point<br>0 (low) to 15 (high)<br>ADJ_BKSTR_SET BKSTR_T1[4:0] 0 Black Stretch Time Constant (T1)<br>0 (small) to 31 (large)<br>ADJ_BKSTR_SET BKSTR_T2[4:0] 0 Black Stretch Time Constant (T2)<br>0 (small) to 30 (large),<br>31: Setting prohibited<br>ADJ_BKSTR_SET BKSTR_D[3:0] 0 Black Stretch Depth<br>0 (shallow) to 15 (deep)<br>Output signal Output signal Output signal<br>**----- End of picture text -----**<br>

## 32.1.4 Enhancer

The enhancer subjects the scaled Y signal input to transient improvement (LTI) and sharpness processing in the horizontal direction.

## (1) Enhancer Area Specification

The operating area of the enhancer is specified with reference to the rising edges of the Hsync signal and Vsync signal. ENH_HS should be set to four or greater clocks, and ENH_VS should be set to two or greater lines. Figure 32.3 shows enhancer area setting.

**==> picture [436 x 348] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clock<br>Hsync signal<br>output<br>X 1 2 3 4 1 2 3 4 5 6 7 8 9 Internal H counter<br>ENH_HS[10:0] ENH_HW[10:0]<br>Enhancer is enabled in the period defined by<br>ENH_HS [10:0] = 4, ENH_HW [10:0] = 9,<br>ENH_VS [10:0] = 3, and ENH_VW [10:0] = 6<br>Vsync signal output Internal V counter<br>X<br>1<br>2 ENH_VS[10:0]<br>3<br>1<br>2<br>3<br>ENH_VW[10:0]<br>4<br>5<br>6<br>m-1<br>m<br>**----- End of picture text -----**<br>

**Figure 32.3 Period when Enhancer is Enabled**

Setting ENH_DISP_ON to 1 displays the enhancer-enabled area with frame lines.

**Table 32.3 Enhancer Area Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|ADJ_ENH_TIM1|ENH_MD|1|Operating Mode|
||||0: RGB mode|
||||1: YCbCr mode|
|ADJ_ENH_TIM2|ENH_VS[10:0]|0|Start Position of Vertical Valid Image Area in Enhancer-Enabled|
||||Area|
||||Note: Set to 2 or greater lines.|
|ADJ_ENH_TIM2|ENH_VW[10:0]|0|Width of Vertical Valid Image Area in Enhancer-Enabled Area|

## **Table 32.3 Enhancer Area Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|ADJ_ENH_TIM3|ENH_HS[10:0]|0|Start Position of Horizontal Valid Image Area in Enhancer-Enabled|
||||Area|
||||Note: Set to 4 or greater clocks.|
|ADJ_ENH_TIM3|ENH_HW[10:0]|0|Width of Horizontal Valid Image Area in Enhancer-Enabled Area|
|ADJ_ENH_TIM1|ENH_DISP_ON|0|Frame Line Display in Enhancer-Enabled Area|
||||0: Off|
||||1: On|

## (2) LTI (Luminance Transient Improvement)

The enhancer subjects the Y signal input to transient improvement in the horizontal direction.

Transient improvement of the blanking signal is turned off.

**==> picture [390 x 138] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input signal Output signal after correction<br>**----- End of picture text -----**<br>

**Figure 32.4 LTI Correction**

After edge detection of the image, the LTI can be independently controlled in the two horizontal bands.

In LTI, the median filter is inserted after edge detection of the image.

In LTI (H4), the reference pixels of the median filter can be selected.

However, under normal operations, half the tap data (second adjacent pixel) at edge detection is used as reference.

## **Table 32.4 Reference Pixel Table for LTI**

||**Reference Pixel for Edge**||**Median Filter Reference**|
|---|---|---|---|
|**LTI Band**|**Detection**|**LPF Application**|**Pixels**|
|Horizontal LTI (H2)|Second adjacent pixel used as|LPF not applied or LPF (1,2,1)|Adjacent pixel used as|
||reference||reference|
|Horizontal LTI (H4)|Fourth adjacent pixel used as|LPF (1,2,1)|Adjacent pixel or second|
||reference||adjacent pixel used as|
||||reference|

In LTI, the detection result can be subjected to a coring process.

The core value set in the register is subtracted from the edge detection result, and LTI correction is performed on the coring output after subtraction.

**==> picture [483 x 179] intentionally omitted <==**

**----- Start of picture text -----**<br>
Set by coring<br>Set by coring<br>Edge detection result output Coring output<br>Figure 32.5 LTI Coring<br>**----- End of picture text -----**<br>

## **Table 32.5 LTI Control**

|**Table 32.5**<br>**LTI**|**Control**|||
|---|---|---|---|
|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|ADJ_ENH_LTI1|LTI_H_ON|0|LTI On/Off Control|
||||0: LTI off|
||||1: LTI on|
|ADJ_ENH_LTI1|LTI_H2_INC_ZERO|10|Median Filter LTI Correction Threshold|
||[7:0]||LTI correction is disabled when:|
|||||right TAP value – center TAP value| < LTI1_H2_INC_ZERO or|
|||||left TAP value – center TAP value| < LTI1_H2_INC_ZERO.|
|ADJ_ENH_LTI1|LTI_H2_LPF_SEL|0|LPF Selection for Folding Prevention Before H2 Edge Detection|
||||0: LPF not selected|
||||1: LPF selected|
|ADJ_ENH_LTI1|LTI_H2_GAIN[7:0]|0|LTI Edge Amplitude Value Gain|
||||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
|ADJ_ENH_LTI1|LTI_H2_CORE[7:0]|0|LTI Coring (Maximum core value of 255)|
||||Amplitude smaller than or equal to the value of LTI_H2_CORE|
||||is cored from the edge amplitude value.|
||||(A core value setting of 128 remains unchanged.)|
|ADJ_ENH_LTI2|LTI_H4_INC_ZERO[7:0]|10|Median Filter LTI Correction Threshold|
||||LTI correction is disabled when:|
|||||right TAP value – center TAP value| < LTI1_H4_INC_ZERO or|
|||||left TAP value – center TAP value| < LTI1_H4_INC_ZERO.|
|ADJ_ENH_LTI2|LTI_H4_MEDIAN_TAP_|0|Median Filter Reference Pixel Select|
||SEL||0: Second adjacent pixel selected as reference|
||||1: Adjacent pixel selected as reference|
|ADJ_ENH_LTI2|LTI_H4_GAIN[7:0]|0|LTI Edge Amplitude Value Gain|
||||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
|ADJ_ENH_LTI2|LTI_H4_CORE[7:0]|0|LTI Coring (Maximum core value of 255)|
||||Amplitude less than or equal to the value of LTI_H4_CORE is|
||||cored from the edge amplitude value.|
||||(A core value setting of 128 remains unchanged.)|

## (3) Sharpness Process

The enhancer performs edge enhancement on the Y signal input by adding overshoot and undershoot to the original signal. Edge enhancement of the blanking signal is turned off.

**==> picture [390 x 153] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input signal Output signal after correction<br>**----- End of picture text -----**<br>

**Figure 32.6 Sharpness Correction**

After edge detection of the image, the sharpness can be independently controlled in the three horizontal bands.

In horizontal sharpness, a 3-tap low-pass filter (LPF) is inserted before edge detection to prevent folding. The LPF can be turned on or off by register setting.

**Table 32.6 Reference Pixel Table for Sharpness**

|**Table 32.6**<br>**Reference Pixel**|**Table for Sharpness**||
|---|---|---|
|**Sharpness Band**|**Reference Pixel for Edge Detection**|**LPF Application**|
|Horizontal sharpness (H1)|Adjacent pixel used as reference|LPF not applied|
|Horizontal sharpness (H2)|Second adjacent pixel used as reference|LPF not applied or LPF (1,2,1)|
|Horizontal sharpness (H3)|Third adjacent pixel used as reference|LPF (1,2,1)|

The edge amplitude of the edge to be enhanced is adjusted according to the value of SHP_CORE.

Edge enhancement is accomplished when the edge detection result of the image is greater than the value of SHP_CORE.

In edge enhancement, a correction value is output by multiplying (edge amplitude value - SHP_CORE) by sharpness gain.

Sharpness is turned off when the edge detection result of the image is smaller than the value of SHP_CORE.

**==> picture [472 x 85] intentionally omitted <==**

**----- Start of picture text -----**<br>
When edge amplitude value = SHP_CORE<br>Sharpness turned on using (edge amplitude value-SHP_CORE)<br>When edge amplitude value < SHP_CORE<br>Sharpness turned off<br>SHP_CORE Correction value output<br>Edge detection result<br>**----- End of picture text -----**<br>

**Figure 32.7 Sharpness Characteristics**

**Table 32.7 Sharpness Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|ADJ_ENH_SHP1|SHP_H_ON|0|Sharpness On/Off Control|
||||0: Horizontal sharpness off|
||||1: Horizontal sharpness on|
|ADJ_ENH_SHP3|SHP_H2_LPF_SEL|0|LPF Selection for Folding Prevention Before H2 Edge Detection|
||||0: LPF not selected|
||||1: LPF selected|
|ADJ_ENH_SHP2|SHP_H1_CLIP_O[7:0]|0|Sharpness Correction Value Clipping (on the Overshoot Side)|
||||Correction value clipped according to SHP_H1_CLIP_O|
|ADJ_ENH_SHP2|SHP_H1_CLIP_U[7:0]|0|Sharpness Correction Value Clipping (on the Undershoot Side)|
||||Correction value clipped according to SHP_H1_CLIP_U|
|ADJ_ENH_SHP2|SHP_H1_GAIN_O[7:0]|0|Sharpness Edge Amplitude Value Gain (on the Overshoot Side)|
||||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
||||Sharpness correction value = SHP_H1_GAIN_O × (edge amplitude|
||||value – SHP_H1_CORE)|
|ADJ_ENH_SHP2|SHP_H1_GAIN_U[7:0]|0|Sharpness Edge Amplitude Value Gain (on the Undershoot Side)|
||||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
||||Sharpness correction value = SHP_H1_GAIN_U × (edge amplitude|
||||value – SHP_H1_CORE)|
|ADJ_ENH_SHP1|SHP_H1_CORE[6:0]|0|Active Sharpness Range|
||||Edge amplitude value ≥ SHP_H1_CORE: Sharpness processing on|
||||Edge amplitude value < SHP_H1_CORE: Sharpness processing off|
||||Sharpness processing is always on when the edge detection value is|
||||128 or greater.|
|ADJ_ENH_SHP4|SHP_H2_CLIP_O[7:0]|0|Sharpness Correction Value Clipping (on the Overshoot Side)|
||||Correction value clipped according to SHP_H2_CLIP_O|
|ADJ_ENH_SHP4|SHP_H2_CLIP_U[7:0]|0|Sharpness Correction Value Clipping (on the Undershoot Side)|
||||Correction value clipped according to SHP_H2_CLIP_U|
|ADJ_ENH_SHP4|SHP_H2_GAIN_O[7:0]|0|Sharpness Edge Amplitude Value Gain (on the Overshoot Side)|
||||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
||||Sharpness correction value = SHP_H2_GAIN_O × (edge amplitude|
||||value – SHP_H2_CORE)|
|ADJ_ENH_SHP4|SHP_H2_GAIN_U[7:0]|0|Sharpness Edge Amplitude Value Gain (on the Undershoot Side)|
||||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
||||Sharpness correction value = SHP_H2_GAIN_U × (edge amplitude|
||||value – SHP_H2_CORE)|
|ADJ_ENH_SHP3|SHP_H2_CORE[6:0]|0|Active Sharpness Range|
||||Edge amplitude value ≥ SHP_H2_CORE: Sharpness processing on|
||||Edge amplitude value < SHP_H2_CORE: Sharpness processing off|
||||Sharpness processing is always on when the edge detection value is|
||||128 or greater.|
|ADJ_ENH_SHP6|SHP_H3_CLIP_O[7:0]|0|Sharpness Correction Value Clipping (on the Overshoot Side)|
||||Correction value clipped according to SHP_H3_CLIP_O|
|ADJ_ENH_SHP6|SHP_H3_CLIP_U[7:0]|0|Sharpness Correction Value Clipping (on the Undershoot Side)|
||||Correction value clipped according to SHP_H3_CLIP_U|
|ADJ_ENH_SHP6|SHP_H3_GAIN_O[7:0]|0|Sharpness Edge Amplitude Value Gain (on the Overshoot Side)|
||||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
||||Sharpness correction value = SHP_H3_GAIN_O × (edge amplitude|
||||value – SHP_H3_CORE)|
|ADJ_ENH_SHP6|SHP_H3_GAIN_U[7:0]|0|Sharpness Edge Amplitude Value Gain (on the Undershoot Side)|
||||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
||||Sharpness correction value = SHP_H3_GAIN_U × (edge amplitude|
||||value – SHP_H3_CORE)|
|ADJ_ENH_SHP5|SHP_H3_CORE[6:0]|0|Active Sharpness Range|
||||Edge amplitude value ≥ SHP_H3_CORE: Sharpness processing on|
||||Edge amplitude value < SHP_H3_CORE: Sharpness processing off|
||||Sharpness processing is always on when the edge detection value is|
||||128 or greater.|

## 32.1.5 Color Matrix

Color matrix is performed by adjusting the offset of each input signal and nine-axis gain. This allows YCbCr to GBR conversion.

## (1) GBR to GBR Conversion

YGIN_A = YGIN + ADJ_MTX_YG − 128

CBBIN_A = CBBIN + ADJ_MTX_B − 128

CRRIN_A = CRRIN + ADJ_MTX_R − 128

YGOUT = (ADJ_MTX_GG × YGIN_A + ADJ_MTX_GB × CBBIN_A + ADJ_MTX_GR × CRRIN_A) ÷ 256 CBBOUT = (ADJ_MTX_BG × YGIN_A + ADJ_MTX_BB × CBBIN_A + ADJ_MTX_BR × CRRIN_A) ÷ 256 CRROUT = (ADJ_MTX_RG × YGIN_A + ADJ_MTX_RB × CBBIN_A + ADJ_MTX_RR × CRRIN_A) ÷ 256

## (2) YCbCr to GBR Conversion

YGIN_A = YGIN + ADJ_MTX_YG − 128

CBBIN_A = CBBIN − 128

CRRIN_A = CRRIN − 128

YGOUT = (ADJ_MTX_GG × YGIN_A + ADJ_MTX_GB × CBBIN_A + ADJ_MTX_GR × CRRIN_A) ÷ 256 CBBOUT = (ADJ_MTX_BG × YGIN_A + ADJ_MTX_BB × CBBIN_A + ADJ_MTX_BR × CRRIN_A) ÷ 256 CRROUT = (ADJ_MTX_RG × YGIN_A + ADJ_MTX_RB × CBBIN_A + ADJ_MTX_RR × CRRIN_A) ÷ 256

**Table 32.8 Matrix Coefficients (Standard Values) of SMPTE 293M**

|**Table 32.8**|**Matrix Coefficients (Standard Values) of SMPTE 293M**|
|---|---|
||**YGIN**<br>**CBBIN**<br>**CRRIN**|
||**Coefficient**<br>**Bit Setting**<br>**Coefficient**<br>**Bit Setting**<br>**Coefficient**<br>**Bit Setting**|
|YGOUT|1.000<br>ADJ_MTX_GG =<br>256<br>–0.344<br>ADJ_MTX_GB =<br>1960<br>–0.714<br>ADJ_MTX_GR =<br>1865|
|CBBOUT|1.000<br>ADJ_MTX_BG =<br>256<br>1.772<br>ADJ_MTX_BB =<br>454<br>0.000<br>ADJ_MTX_BR = 0|
|CRROUT|1.000<br>ADJ_MTX_RG =<br>256<br>0.000<br>ADJ_MTX_RB = 0<br>1.402<br>ADJ_MTX_RR =<br>359|

**Table 32.9 Color Matrix Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|ADJ_MTX_MODE|ADJ_MTX_MD[1:0]|2|Operating Mode|
||||0: GBR → GBR|
||||1: Setting prohibited|
||||2: YCbCr → GBR|
||||3: Setting prohibited|
|ADJ_MTX_YG_ADJ0|ADJ_MTX_YG[7:0]|128|Y/G Signal Offset (DC) Adjustment|
||||Unsigned (0 (-128) to 128(0) to 255 (+127) [LSB])|
|ADJ_MTX_CBB_ADJ0|ADJ_MTX_B[7:0]|128|B Signal Offset (DC) Adjustment|
||||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])|
|ADJ_MTX_CRR_ADJ0|ADJ_MTX_R[7:0]|128|R Signal Offset (DC) Adjustment|
||||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])|
|ADJ_MTX_YG_ADJ0|ADJ_MTX_GG[10:0]|256|Gain Adjustment of Y/G Signal of G Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|
|ADJ_MTX_YG_ADJ1|ADJ_MTX_GB[10:0]|1960|Gain Adjustment of Cb/B Signal of G Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|
|ADJ_MTX_YG_ADJ1|ADJ_MTX_GR[10:0]|1865|Gain Adjustment of Cr/R Signal of G Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|
|ADJ_MTX_CBB_ADJ0|ADJ_MTX_BG[10:0]|256|Gain Adjustment of Y/G Signal of B Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|
|ADJ_MTX_CBB_ADJ1|ADJ_MTX_BB[10:0]|454|Gain adjustment of Cb/B signal of B Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|
|ADJ_MTX_CBB_ADJ1|ADJ_MTX_BR[10:0]|0|Gain Adjustment of Cr/R Signal of B Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|
|ADJ_MTX_CRR_ADJ0|ADJ_MTX_RG[10:0]|256|Gain Adjustment of Y/G Signal of R Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|
|ADJ_MTX_CRR_ADJ1|ADJ_MTX_RB[10:0]|0|Gain Adjustment of Cb/B Signal of R Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|
|ADJ_MTX_CRR_ADJ1|ADJ_MTX_RR[10:0]|359|Gain Adjustment of Cr/R Signal of R Signal Output|
||||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] =|
||||1.0 [times])|

## 32.2 Register Description

Table 32.10 shows the register configuration.

[Symbols used in Register Description]

Initial value : Register value after a reset — : Undefined value R/W : Readable/writable. The written value can be read. R/WC0 : Read and write. Bit is initialized if 0 is written, and ignored if 1 is written. R/WC1 : Read and write. Bit is initialized if 1 is written, and ignored if 0 is written. R : Read-only. The write value should always be 0. —/W : Write-only. Read value is undefined.

**Table 32.10 Image Quality Improver Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Register update control register in image|ADJ0_UPDATE|R/WC1|H'0000 0000|H'FCFF 7680|32|
|quality improver (image quality improver 0)||||||
|Black stretch register (image quality|ADJ0_BKSTR_SET|R/W|H'0000 0000|H'FCFF 7684|32|
|improver 0)||||||
|Enhancer timing adjustment register 1|ADJ0_ENH_TIM1|R/W|H'0000 0010|H'FCFF 7688|32|
|(image quality improver 0)||||||
|Enhancer timing adjustment register 2|ADJ0_ENH_TIM2|R/W|H'0023 01E0|H'FCFF 768C|32|
|(image quality improver 0)||||||
|Enhancer timing adjustment register 3|ADJ0_ENH_TIM3|R/W|H'0091 0280|H'FCFF 7690|32|
|(image quality improver 0)||||||
|Enhancer sharpness register 1 (image|ADJ0_ENH_SHP1|R/W|H'0000 0000|H'FCFF 7694|32|
|quality improver 0)||||||
|Enhancer sharpness register 2 (image|ADJ0_ENH_SHP2|R/W|H'0000 0000|H'FCFF 7698|32|
|quality improver 0)||||||
|Enhancer sharpness register 3 (image|ADJ0_ENH_SHP3|R/W|H'0000 0000|H'FCFF 769C|32|
|quality improver 0)||||||
|Enhancer sharpness register 4 (image|ADJ0_ENH_SHP4|R/W|H'0000 0000|H'FCFF 76A0|32|
|quality improver 0)||||||
|Enhancer sharpness register 5 (image|ADJ0_ENH_SHP5|R/W|H'0000 0000|H'FCFF 76A4|32|
|quality improver 0)||||||
|Enhancer sharpness register 6 (image|ADJ0_ENH_SHP6|R/W|H'0000 0000|H'FCFF 76A8|32|
|quality improver 0)||||||
|Enhancer LTI register 1 (image quality|ADJ0_ENH_LTI1|R/W|H'000A 0000|H'FCFF 76AC|32|
|improver 0)||||||
|Enhancer LTI register 2 (image quality|ADJ0_ENH_LTI2|R/W|H'000A 0000|H'FCFF 76B0|32|
|improver 0)||||||
|Matrix mode register in image quality|ADJ0_MTX_MODE|R/W|H'0000 0002|H'FCFF 76B4|32|
|improver (image quality improver 0)||||||
|Matrix YG control register 0 in image|ADJ0_MTX_YG_ADJ0|R/W|H'0080 0100|H'FCFF 76B8|32|
|quality improver (image quality improver 0)||||||
|Matrix YG control register 1 in image|ADJ0_MTX_YG_ADJ1|R/W|H'07A8 0749|H'FCFF 76BC|32|
|quality improver (image quality improver 0)||||||
|Matrix CBB control register 0 in image|ADJ0_MTX_CBB_ADJ0|R/W|H'0080 0100|H'FCFF 76C0|32|
|quality improver (image quality improver 0)||||||
|Matrix CBB control register 1 in image|ADJ0_MTX_CBB_ADJ1|R/W|H'01C6 0000|H'FCFF 76C4|32|
|quality improver (image quality improver 0)||||||

## **Table 32.10 Image Quality Improver Register Configuration**

||||||**Access**|
|---|---|---|---|---|---|
|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Matrix CRR control register 0 in image|ADJ0_MTX_CRR_ADJ0|R/W|H'0080 0100|H'FCFF 76C8|32|
|quality improver (image quality improver 0)||||||
|Matrix CRR control register 1 in image|ADJ0_MTX_CRR_ADJ1|R/W|H'0000 0167|H'FCFF 76CC|32|
|quality improver (image quality improver 0)||||||

## 32.2.1 Register Update Control Register in Image Quality Improver (ADJ0_UPDATE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17||16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||—|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1||0|
||||||||||||||||||ADJ0_|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||VEN|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/WC1||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||ADJ0_VEN|0|R/WC1|Image Quality Improver Register Update|
|||||||0: Registers are not updated.|
|||||||1: Registers are updated at the rising edge of the Vsync.|

## 32.2.2 Black Stretch Register (ADJ0_BKSTR_SET)

|Bit:|31|30|29|||28|27|27|26|25<br>24<br>23<br>22||21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|||—|—||—|—<br>-<br>BKSTR_ST[3:0]<br>BKSTR_<br>ON||||-|-<br>-<br>BKSTR_D[3:0]||-||
|Initial value:|0|0|0|||0||0|0|0<br>0<br>0<br>0||0|0|0|0|0|0||
|R/W:|R|R|R|||R|R||R|R<br>R/W<br>R/W<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|||12|11||10|9<br>8<br>7<br>6||5|4|3|2|1|0||
||—|—|—|||-||-<br>-<br>—<br>—<br>BKSTR_T1[4:0]||||—||-<br>-<br>-<br>BKSTR_T2[4:0]|||||
|Initial value:|0|0|0|||0||0|0|0<br>0<br>0<br>0||0|0|0|0|0|0||
|R/W:|R|R|R|||R/W|R/W||R/W|R/W<br>R/W<br>R<br>R||R|R/W|R/W|R/W|R/W|R/W||
|**Bit**|**Bit Name**|||**Initial Value**||||**R/W**||**Description**|||||||||
|31 to 25|—|||All||0||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|24|BKSTR_ON|||0||||R/W||Black Stretch On/Off Control|||||||||
|||||||||||0: Black stretch off|||||||||
|||||||||||1: Black stretch on|||||||||
|23 to 20|BKSTR_ST|||0||||R/W||Black Stretch Start Point|||||||||
||[3:0]|||||||||Setting values: 0 (low) to||15 (high)|||||||
|19 to 16|BKSTR_D|||0||||R/W||Depth of Black Stretch|||||||||
||[3:0]|||||||||Setting Values: 0 (shallow) to 15|||(deep)||||||
|15 to 13|—|||All||0||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|12 to 8|BKSTR_T1|||0||||R/W||Black Stretch Time Constant (T1)|||||||||
||[4:0]|||||||||Setting Values: 0 (small) to 31 (large)|||||||||
|7 to 5|—|||All||0||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|4 to 0|BKSTR_T2|||0||||R/W||Black Stretch Time Constant (T2)|||||||||
||[4:0]|||||||||Setting Values: 0 (small) to 31 (large)|||||||||

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.3 Enhancer Timing Adjustment Register 1 (ADJ0_ENH_TIM1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|—|—|—|—|—|—|ENH_MD|—|—|—|ENH_<br>DISP_ON|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|ENH_MD|1|R/W|Operating Mode|
|||||0: RGB mode|
|||||1: YCbCr mode|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|ENH_DISP_ON|0|R/W|Frame Line Display On/Off of Enhancer-Enabled Area|
|||||0: Display off|
|||||1: Display on|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.4 Enhancer Timing Adjustment Register 2 (ADJ0_ENH_TIM2)

|Bit:|31|30||29||28|27||26|25<br>24|23|22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—||—||—|—|||||ENH_VS[10:0]||||||
|Initial value:|0|0||0||0|0||0|0<br>0|0|0<br>1<br>0|0|0|1|1||
|R/W:|R|R||R||R|R||R/W|R/W<br>R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14||13||12|11||10|9<br>8|7|6<br>5<br>4|3|2|1|0||
||—|—||—||—|—|||||ENH_VW[10:0]||||||
|Initial value:|0|0||0||0|0||0|0<br>1|1|1<br>1<br>0|0|0|0|0||
|R/W:|R|R||R||R|R||R/W|R/W<br>R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**|**Bit Name**||||**Initial Value**|||**R/W**||**Description**||||||||
|31 to 27|—||||All 0|||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write value||||should|always|be 0.||
|26 to 16|ENH_VS[10:0]||||35|||R/W||Start Position of Vertical Valid Image Area|||in Enhancer-Enabled|||Area||
|||||||||||Note: Set to|2 or greater lines.|||||||
|15 to 11|—||||All 0|||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write value||||should|always|be 0.||
|10 to 0|ENH_VW[10:0]||||480|||R/W||Width of Vertical Valid Image Area in Enhancer-Enabled|||||Area|||

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.5 Enhancer Timing Adjustment Register 3 (ADJ0_ENH_TIM3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||ENH_HS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|1|0|0|0|1|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||ENH_HW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|ENH_HS[10:0]|145|R/W|Start Position of Horizontal Valid Image Area in Enhancer-Enabled Area|
|||||||Note: Set to 4 or greater clocks.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|ENH_HW[10:0]|640|R/W|Width of Horizontal Valid Image Area in Enhancer-Enabled Area|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.6 Enhancer Sharpness Register 1 (ADJ0_ENH_SHP1)

||Bit:|31|30|29||28|27||26|25<br>24<br>23<br>22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||||SHP_H||
|||—|—|—||—|—||—|—<br>—<br>—<br>—|—|—|—|—|—||_ON||
||Initial value:|0|0|0||0|0||0|0<br>0<br>0<br>0|0|0|0|0|0||0||
||R/W:|R|R|R||R|R||R|R<br>R<br>R<br>R|R|R|R|R|R||R/W||
||Bit:|15|14|13||12|11||10|9<br>8<br>7<br>6|5|4|3|2|1||0||
|||—|—|—||—|—||—|—<br>—<br>—||SHP_H1_CORE[6:0]|||||||
||Initial value:|0|0|0||0|0||0|0<br>0<br>0<br>0|0|0|0|0|0||0||
||R/W:|R|R|R||R|R||R|R<br>R<br>R<br>R/W|R/W|R/W|R/W|R/W|R/W||R/W||
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**|||||||||
|31|to 17|—|||All 0|||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|16||SHP_H_ON|||0|||R/W||Sharpness On/Off Control|||||||||
|||||||||||0: Horizontal sharpness off|||||||||
|||||||||||1: Horizontal sharpness on|||||||||
|15|to 7|—|||All 0|||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|6 to 0||SHP_H1_|||0|||R/W||Active Sharpness Range|||||||||
|||CORE[6:0]||||||||Edge amplitude value ≥ SHP_H1_CORE: Sharpness processing on|||||||||
|||||||||||Edge amplitude value < SHP_H1_CORE: Sharpness processing off|||||||||
|||||||||||Sharpness processing is|always|on when the edge detection||||value is|||
|||||||||||128 or greater.|||||||||

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.7 Enhancer Sharpness Register 2 (ADJ0_ENH_SHP2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||SHP_H1_CLIP_O[7:0]||||||||SHP_H1_CLIP_U[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||SHP_H1_GAIN_O[7:0]||||||||SHP_H1_GAIN_U[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|SHP_H1_CLIP_O|0|R/W|Sharpness Correction Value Clipping (on the Overshoot Side)|
||[7:0]|||Correction value clipped according to SHP_H1_CLIP_O|
|23 to 16|SHP_H1_CLIP_U|0|R/W|Sharpness Correction Value Clipping (on the Undershoot Side)|
||[7:0]|||Correction value clipped according to SHP_H1_CLIP_U|
|15 to 8|SHP_H1_GAIN_O|0|R/W|Sharpness Edge Amplitude Value Gain (on the Overshoot Side)|
||[7:0]|||0 (0 times) to 64 (+1 times) to 255 (+approx. 4 times)|
|||||Sharpness correction value = SHP_H1_GAIN_O × (edge amplitude|
|||||value – SHP_H1_CORE)|
|7 to 0|SHP_H1_GAIN_U|0|R/W|Sharpness Edge Amplitude Value Gain (on the Undershoot Side)|
||[7:0]|||0 (0 times) to 64 (+1 times) to 255 (+approx. 4 times)|
|||||Sharpness correction value = SHP_H1_GAIN_U × (Edge amplitude|
|||||value – SHP_H1_CORE)|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.8 Enhancer Sharpness Register 3 (ADJ0_ENH_SHP3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||SHP_H2_||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|LPF_SEL||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|—|—|—|—|||SHP_H2_CORE[6:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 17|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|16|SHP_H2_|0|R/W|LPF Selection for Folding Prevention before H2 Edge Detection|
||LPF_SEL|||0: LPF not selected|
|||||1: LPF selected|
|15 to 7|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|6 to 0|SHP_H2_|0|R/W|Active Sharpness Range|
||CORE[6:0]|||Edge amplitude value ≥ SHP_H2_CORE: Sharpness processing on|
|||||Edge amplitude value < SHP_H2_CORE: Sharpness processing off|
|||||Sharpness processing is always on when the edge detection value is|
|||||128 or greater.|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.9 Enhancer Sharpness Register 4 (ADJ0_ENH_SHP4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||SHP_H2_CLIP_O[7:0]||||||||SHP_H2_CLIP_U[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||SHP_H2_GAIN_O[7:0]||||||||SHP_H2_GAIN_U[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|SHP_H2_|0|R/W|Sharpness Correction Value Clipping (on the Overshoot Side)|
||CLIP_O[7:0]|||Correction value clipped according to SHP_H2_CLIP_O|
|23 to 16|SHP_H2_|0|R/W|Sharpness Correction Value Clipping (on the Undershoot Side)|
||CLIP_U[7:0]|||Correction value clipped according to SHP_H2_CLIP_U|
|15 to 8|SHP_H2_|0|R/W|Sharpness Edge Amplitude Value Gain (on the Overshoot Side)|
||GAIN_O[7:0]|||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
|||||Sharpness correction value = SHP_H2_GAIN_O × (edge amplitude|
|||||value – SHP_H2_CORE)|
|7 to 0|SHP_H2_|0|R/W|Sharpness Edge Amplitude Value Gain (on the Undershoot Side)|
||GAIN_U[7:0]|||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
|||||Sharpness correction value = SHP_H2_GAIN_U × (edge amplitude|
|||||value – SHP_H2_CORE)|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.10 Enhancer Sharpness Register 5 (ADJ0_ENH_SHP5)

**==> picture [483 x 239] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>— — — — — — — — — — — — — — — —<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>— — — — — — — — —<br>SHP_H3_CORE[6:0]<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R/W R/W R/W R/W R/W R/W R/W<br>Bit Bit Name Initial Value R/W Description<br>31 to 7 — All 0 R Reserved<br>These bits are always read as 0. The write value should always be 0.<br>6 to 0 SHP_H3_ 0 R/W Active Sharpness Range<br>CORE[6:0] Edge amplitude value ≥ SHP_H3_CORE: Sharpness processing on<br>Edge amplitude value < SHP_H3_CORE: Sharpness processing off<br>Sharpness processing is always on when the edge detection value is<br>128 or greater.<br>**----- End of picture text -----**<br>

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.11 Enhancer Sharpness Register 6 (ADJ0_ENH_SHP6)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||SHP_H3_CLIP_O[7:0]||||||||SHP_H3_CLIP_U[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||SHP_H3_GAIN_O[7:0]||||||||SHP_H3_GAIN_U[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|SHP_H3_|0|R/W|Sharpness Correction Value Clipping (on the Overshoot Side)|
||CLIP_O[7:0]|||Correction value clipped according to SHP_H3_CLIP_O|
|23 to 16|SHP_H3_|0|R/W|Sharpness Correction Value Clipping (on the Undershoot Side)|
||CLIP_U[7:0]|||Correction value clipped according to SHP_H3_CLIP_U|
|15 to 8|SHP_H3_|0|R/W|Sharpness Edge Amplitude Value Gain (on the Overshoot Side)|
||GAIN_O[7:0]|||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
|||||Sharpness correction value = SHP_H3_GAIN_O × (Edge amplitude|
|||||value – SHP_H3_CORE)|
|7 to 0|SHP_H3_|0|R/W|Sharpness Edge Amplitude Value Gain (on the Undershoot Side)|
||GAIN_U[7:0]|||0 (0 times) to 64 (+1 times) to 255 (+ approx. 4 times)|
|||||Sharpness correction value = SHP_H3_GAIN_U × (Edge amplitude|
|||||value – SHP_H3_CORE)|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.12 Enhancer LTI Register 1 (ADJ0_ENH_LTI1)

|Bit:|31|30|29||28|27||26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||LTI_H_<br>ON|—|—||—|—||—|—|LTI_H2_<br>LPF_SEL|||LTI_H2_INC_ZERO[7:0]|||||||
|Initial value:|0|0|0||0|0||0|0|0|0|0|0|0|1|0|1|0||
|R/W:|R/W|R|R||R|R||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13||12|11||10|9|8|7|6|5|4|3|2|1|0||
|||||LTI_H2_GAIN[7:0]|||||||||LTI_H2_CORE[7:0]|||||||
|Initial value:|0|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W||R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31|LTI_H_ON|0|R/W|LTI On/Off Control|
|||||0: LTI off|
|||||1: LTI on|
|30 to 25|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|24|LTI_H2_|0|R/W|LPF Selection for Folding Prevention before H2 Edge Detection|
||LPF_SEL|||0: LPF not selected|
|||||1: LPF selected|
|23 to 16|LTI_H2_INC_|10|R/W|Median Filter LTI Correction Threshold|
||ZERO[7:0]|||LTI correction is disabled when|
|||||| right TAP value – center TAP value | < LTI_H2_INC_ZERO or|
|||||| left TAP value – center TAP value | < LTI_H2_INC_ZERO|
|15 to 8|LTI_H2_|0|R/W|LTI Edge Amplitude Value Gain|
||GAIN[7:0]|||0 (0 times) to 64 (+ 1 times) to 255 (+ approx. 4 times)|
|7 to 0|LTI_H2_|0|R/W|LTI Coring (Maximum Core value of 255)|
||CORE[7:0]|||Amplitude less than or equal to the value of LTI_H2_CORE is cored|
|||||from the edge amplitude value.|
|||||(A core value setting of 128 remains unchanged)|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.13 Enhancer LTI Register 2 (ADJ0_ENH_LTI2)

|Bit:|31|30|29||28|27||26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—||—|—||—|—|LTI_H4_<br>MEDIAN_<br>TAP_SEL|||LTI_H4_INC_ZERO[7:0]||||||
|Initial value:|0|0|0||0|0||0|0|0|0|0|0|0|1|0|1|0|
|R/W:|R|R|R||R|R||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13||12|11||10|9|8|7|6|5|4|3|2|1|0|
|||||LTI_H4_GAIN[7:0]||||||-|||LTI_H4_CORE[7:0]||||||
|Initial value:|0|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W||R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 25|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|24|LTI_H4_|0|R/W|Median Filter Reference Pixel Select|
||MEDIAN_|||0: Second adjacent pixel selected as reference|
||TAP_SEL|||1: Adjacent pixel selected as reference|
|23 to 16|LTI_H4_INC_|10|R/W|Median Filter LTI Correction Threshold|
||ZERO[7:0]|||LTI correction is disabled when|
|||||| right TAP value – center TAP value | < LTI_H4_INC_ZERO or|
|||||| left TAP value – center TAP value | < LTI_H4_INC_ZERO|
|15 to 8|LTI_H4_|0|R/W|LTI Edge Amplitude Value Gain|
||GAIN[7:0]|||0 (0 times) to 64 (+ 1 times) to 255 (+ approx. 4 times)|
|7 to 0|LTI_H4_|0|R/W|LTI Coring (Maximum Core value of 255)|
||CORE[7:0]|||Amplitude less than or equal to the value of LTI_H4_CORE is cored|
|||||from the edge amplitude value (A core value setting of 128 remains|
|||||unchanged)|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.14 Matrix Mode Register in Image Quality Improver (ADJ0_MTX_MODE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||||||||||||||ADJ0_MTX_|||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|MD[1:0]|||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1, 0|ADJ0_MTX_|2|R/W|Operating Mode|
||MD[1:0]|||0: GBR → GBR|
|||||1: Setting prohibited|
|||||2: YCbCr → GBR|
|||||3: Setting prohibited|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.15 Matrix YG Control Register 0 in Image Quality Improver (ADJ0_MTX_YG_ADJ0)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|||ADJ0_MTX_YG[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||ADJ0_MTX_GG[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|24|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|23|to|16|ADJ0_MTX_|128|R/W|Y/G Signal Offset (DC) Adjustment|
||||YG[7:0]|||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|ADJ0_MTX_|256|R/W|Gain Adjustment of Y/G Signal of G Signal Output|
||||GG[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.16 Matrix YG Control Register 1 in Image Quality Improver (ADJ0_MTX_YG_ADJ1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||ADJ0_MTX_GB[10:0]||||||||
|Initial value:|0|0|0|0|0|1|1|1|1|0|1|0|1|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||ADJ0_MTX_GR[10:0]||||||||
|Initial value:|0|0|0|0|0|1|1|1|0|1|0|0|1|0|0|1||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|ADJ0_MTX_GB|1960|R/W|Gain Adjustment of Cb/B Signal of G Signal Output|
||||[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|ADJ0_MTX_GR|1865|R/W|Gain Adjustment of Cr/R Signal of G Signal Output|
||||[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.17 Matrix CBB Control Register 0 in Image Quality Improver (ADJ0_MTX_CBB_ADJ0)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|||ADJ0_MTX_B[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||ADJ0_MTX_BG[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|24|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|23|to|16|ADJ0_MTX_B|128|R/W|B Signal Offset (DC) Adjustment|
||||[7:0]|||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|ADJ0_MTX_BG|256|R/W|Gain Adjustment of Y/G Signal of B Signal Output|
||||[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.18 Matrix CBB Control Register 1 in Image Quality Improver (ADJ0_MTX_CBB_ADJ1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||ADJ0_MTX_BB[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|1|1|1|0|0|0|1|1|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||ADJ0_MTX_BR[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|ADJ0_MTX_BB|454|R/W|Gain Adjustment of Cb/B Signal of B Signal Output|
||||[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|ADJ0_MTX_BR|0|R/W|Gain Adjustment of Cr/R Signal of B Signal Output|
||||[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.19 Matrix CRR Control Register 0 in Image Quality Improver (ADJ0_MTX_CRR_ADJ0)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|||ADJ0_MTX_R[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||ADJ0_MTX_RG[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|24|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|23|to|16|ADJ0_MTX_R|128|R/W|R Signal Offset (DC) Adjustment|
||||[7:0]|||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|ADJ0_MTX_RG|256|R/W|Gain Adjustment of Y/G Signal of R Signal Output|
||||[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.2.20 Matrix CRR Control Register 1 in Image Quality Improver (ADJ0_MTX_CRR_ADJ1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||ADJ0_MTX_RB[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||ADJ0_MTX_RR[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|1|0|1|1|0|0|1|1|1|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|ADJ0_MTX_RB|0|R/W|Gain Adjustment of Cb/B Signal of R Signal Output|
||||[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|ADJ0_MTX_RR|359|R/W|Gain Adjustment of Cr/R Signal of R Signal Output|
||||[10:0]|||Signed (complement of 2) (-1024 to +1023 [LSB], 256 [LSB] = 1.0|
|||||||[times])|

Note: This register is updated when ADJ0_VEN in ADJ0_UPDATE is 1.

## 32.3 Usage Method

## 32.3.1 Black Stretch Usage Method

The degree of black stretch can be adjusted by setting the depth (BKSTR_D[3:0]) and the start point (BKSTR_ST[3:0]) of the black stretch. The variation in the black stretch time axis can be adjusted by setting the time constant (BKSTR_T1[4:0] and BKSTR_T2[4:0]). By setting the time constant, changes that occur abruptly due to swapping of the scene can be controlled.

## **Table 32.11 Black Stretch Setting Register**

|**Register Name**|**Bit Name**|**Set Value**|
|---|---|---|
|ADJ_BKSTR_SET|BKSTR_ON|When black stretch is on: 1|
|ADJ_BKSTR_SET|BKSTR_D[3:0]|Set the depth of black stretch. The depth increases as the value|
|||becomes larger.|
|ADJ_BKSTR_SET|BKSTR_ST[3:0]|Set the start point of black stretch. The stretching area becomes larger|
|||as the value becomes larger.|
|ADJ_BKSTR_SET|BKSTR_T1[4:0]|Set the time constant of black stretch in the positive direction. The|
|||changes are more delayed as the value becomes larger.|
|ADJ_BKSTR_SET|BKSTR_T2[4:0]|Set the time constant of black stretch in the negative direction. The|
|||changes are more delayed as the value becomes larger.|

Note: ADJ_VEN in ADJ_UPDATE should be set to 1 after setting the registers.

## 32.3.2 LTI Processing of Enhancer

## Figure 32.8 shows an example of LTI adjustment.

**==> picture [434 x 110] intentionally omitted <==**

**----- Start of picture text -----**<br>
LTI_H2_GAIN adjustment<br>LTI_H4_GAIN adjustment<br>Enhancer output Y signal Enhancer output Y signal<br>LTI gain is adjusted with the LTI_H2_GAIN and The center frequency of LTI differs in the LTI_H2_GAIN and<br>LTI_H4_GAIN bits. LTI_H4_GAIN bits.<br>**----- End of picture text -----**<br>

**Figure 32.8 Example of LTI Adjustment**

## 32.3.3 Sharpness Processing of Enhancer

Figure 32.9 shows an example of sharpness adjustment.

**==> picture [462 x 419] intentionally omitted <==**

**----- Start of picture text -----**<br>
Enhancer output Y<br>signal<br>Enhancer output Y<br>signal<br>Sharpness gain is adjusted on the undershoot side with the Sharpness gain is adjusted on the overshoot side with the<br>SHP_H1_GAIN_U, SHP_H2_GAIN_U, and  SHP_H1_GAIN_O, SHP_H2_GAIN_O, and<br>SHP_H3_GAIN_U bits. SHP_H3_GAIN_O bits.<br>Enhancer output Y<br>signal<br>Enhancer output Y<br>signal<br>Sharpness clipping is adjusted on the undershoot side with the Sharpness clipping is adjusted on the overshoot side with the<br>SHP_H1_CLIP_U, SHP_H2_CLIP_U, and SHP_H3_CLIP_U bits. SHP_H1_CLIP_O, SHP_H2_CLIP_O, and SHP_H3_CLIP_O bits.<br>SHP_H1_GAIN_O<br>adjustment<br>SHP_H2_GAIN_O<br>adjustment<br>SHP_H3_GAIN_O<br>adjustment<br>Enhancer output Y<br>signal<br>SHP_H1_GAIN_U adjustment<br>SHP_H2_GAIN_U adjustment Enhancer output Y<br>SHP_H3_GAIN_U adjustment signal<br>Sharpness center frequency differs in the SHP_H1_GAIN_U, Sharpness center frequency differs in the SHP_H1_GAIN_O,<br>SHP_H2_GAIN_U, and SHP_H3_GAIN_U bits. SHP_H2_GAIN_O, and SHP_H3_GAIN_O bits.<br>**----- End of picture text -----**<br>

**Figure 32.9 Example of Sharpness Adjustment**

## 32.3.4 Setting Method for Color Matrix Data Conversion

GBR signals are assumed to be input to the circuit subsequent to the image quality improver; therefore, the output from the color matrix circuit should be in the GBR format.

Table 32.12 shows an example of GBR conversion setting.

**Table 32.12 Recommended Setting Values for Matrix Conversion**

|**Register Name**<br>**Bit Name**|**GBR to GBR Conversion**<br>**YCBCR to GBR Conversion**|
|---|---|
||**Recommended Values**<br>**Recommended Values**|
|ADJ_MTX_MODE<br>ADJ_MTX_MD[1:0]|0<br>2|
|ADJ_MTX_YG_ADJ0<br>ADJ_MTX_YG[7:0]|128<br>128|
|ADJ_MTX_CBB_ADJ0<br>ADJ_MTX_B[7:0]|128<br>128|
|ADJ_MTX_CRR_ADJ0<br>ADJ_MTX_R[7:0]|128<br>128|
|ADJ_MTX_YG_ADJ0<br>ADJ_MTX_GG[10:0]|256<br>256|
|ADJ_MTX_YG_ADJ1<br>ADJ_MTX_GB[10:0]|0<br>1960|
|ADJ_MTX_YG_ADJ1<br>ADJ_MTX_GR[10:0]|0<br>1865|
|ADJ_MTX_CBB_ADJ0<br>ADJ_MTX_BG[10:0]|0<br>256|
|ADJ_MTX_CBB_ADJ1<br>ADJ_MTX_BB[10:0]|256<br>454|
|ADJ_MTX_CBB_ADJ1<br>ADJ_MTX_BR[10:0]|0<br>0|
|ADJ_MTX_CRR_ADJ0<br>ADJ_MTX_RG[10:0]|0<br>256|
|ADJ_MTX_CRR_ADJ1<br>ADJ_MTX_RB[10:0]|0<br>0|
|ADJ_MTX_CRR_ADJ1<br>ADJ_MTX_RR[10:0]|256<br>359|

Note: ADJ_VEN in ADJ_UPDATE should be set to 1 after setting the registers.
