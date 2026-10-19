# 31. Video Display Controller 5 (3): Scaler

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1635–1729. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 31.1 Scaler

## 31.1.1 Overview of Functions

The scaler subjects the YCbCr and RGB signals output from the input controller, to sync signal generation; and reduction, enlargement, and rotation of the images.

The scaler also records video image in the frame buffer.

In scaler 0, either enlargement process or graphics 0 process can be used.

The functional block diagram of scaler 0 is shown below.

**==> picture [462 x 330] intentionally omitted <==**

**----- Start of picture text -----**<br>
IV3-BUS (read) RGB565 = 16 bits[Moving picture] RGB565 = 16 bitsRGB888 = 32 bits[Graphics]<br>RGB888 = 32 bits ARGB1555 = 16 bits<br>YCbCr422 = 16 bits ARGB4444 = 16 bits<br>YCbCr444 = 32 bits ARGB8888 = 32 bits<br>CLUT8 = 8 bits<br>CLUT4 = 4 bits<br>CLUT1 = 1 bit<br>IV1-BUS (write/read) YCbCr422 = 16 bits YCbCr422 = 16 bitsYCbCr444 = 32 bits<br>YCbCr444 = 24 (32) bitsRGB565 = 16 bits<br>RGB888 = 24 (32) bits Internal bus<br>read control<br>Internal bus write Buffer write<br>control control<br>Buffer read control<br>Buffer read<br>control<br>Buffer write control YCbCr422 toYCbCr444<br>conversion<br>Internal bus write control HS,VS,HE,VE Internal bus read<br>control 0<br>YCbCr422/YCbCr444/RGB888/RGB565HS,VS,HE,VE,<br>Bit reduction YCbCr422 conversionYCbCr444 to  Bit extension<br>Frame sub-sampling CLUT control<br>Bit reduction Output image enable Data expansion 0<br>signal generation<br>HS,VS,HE,VE,<br>YCbCr444/RGB888 Enable adjustment Switching<br>Vertical scale down(two-TAP linear) Vertical scale up(two-TAP linear) [Moving picture, scale up]YCbCr/RGB888 (24 bits) ARGB8888[Graphics]<br>Horizontal scale down Horizontal scale up<br>(two-TAP linear) Switching (two-TAP linear)<br>controllerInput HS,VS,FLD,YCbCr/ Specification of video imagearea to be capturedHorizontal prefilter(three-TAP) Line buffer Scaling-up control blockTrimming synthesizing blockmoving picture andMoving pictureSynthesis ofbackground HS,VS,HE,VE,RGB888(24 bits)YCbCr/ Image qualityimprover 0 and scaler 1synthesizer To image<br>RGB888(24 bits) Scaling-down control block<br>Graphics 0<br>Repeated Vsync Free-running Vsync<br>signal masking signal generation<br>Switching Missing-sync Vsync signal<br>compensation generation<br>Repeated Vsync Hsync signal<br>signal masking generation<br>Vsync signal correction Sync signal generation Register control<br>Synchronization control block<br>Scaler 0<br>Rotation control Line buffer Line buffer<br>Rotation control<br>CLUT table<br>Enable signal generation Output selection<br>control<br>Vsync signal delay Field determination signal delay control Full-image enable signal generation<br>**----- End of picture text -----**<br>

**Figure 31.1 Functional Block Diagram of Scaler 0**

The registers and bits in the scaler are named SC0_xxxx and those in the graphics blocks are named GR0_xxxx, but in this section, they are collectively called SC_xxxx or GR_xxxx.

## 31.1.2 Register Control

## (1) Updating Registers

The Vsync signal is used to control the update timing of all the registers of the scaling and graphics blocks except some registers of the sync control block and some of the other blocks.

After 1 is set to the bits in the update control register, the contents of the relevant registers are modified at the rising edge of the Vsync signal. The update control register is automatically cleared to 0 after the modification.

**Table 31.1 Register Update Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_UPDATE|SC_SCL0_UPDATE|0|SYNC Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated.|
|SC_SCL0_UPDATE|SC_SCL0_VEN_D|0|Scaling-Up Control and Frame Buffer Read Control|
||||Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|SC_SCL0_UPDATE|SC_SCL0_VEN_C|0|Scaling-Down Control and Frame Buffer Read Control|
||||Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|SC_SCL0_UPDATE|SC_SCL0_VEN_B|0|Synchronization Control and Scaling-up Control Register|
||||Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|SC_SCL0_UPDATE|SC_SCL0_VEN_A|0|Scaling-Down Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|SC_SCL1_UPDATE|SC_SCL1_UPDATE_B|0|Frame Buffer Write Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated.|
|SC_SCL1_UPDATE|SC_SCL1_UPDATE_A|0|Frame Buffer Write Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated.|
|SC_SCL1_UPDATE|SC_SCL1_VEN_B|0|Frame Buffer Write Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|SC_SCL1_UPDATE|SC_SCL1_VEN_A|0|Frame Buffer Write Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|GR_UPDATE|GR_UPDATE|0|Frame Buffer Read Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated.|
|GR_UPDATE|GR_P_VEN|0|Graphics Display Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|GR_UPDATE|GR_IBUS_VEN|0|Frame Buffer Read Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|

The registers controlled by SC_SCL0_VEN_A, SC_SCL0_VEN_C, SC_SCL1_VEN_A, and SC_SCL1_VEN_B are modified at the rising edge of the input Vsync signal.

The registers controlled by SC_SCL0_VEN_B, SC_SCL0_VEN_D, GR_P_VEN, and GR_IBUS_VEN are modified at the rising edge of the output Vsync signal.

## 31.1.3 Synchronization Control

## (1) Selecting Vsync Signal

The Vsync signal to be output from the scaler can be selected.

When an external input signal is to be displayed, an external input Vsync signal should be selected to be output.

When an external input signal is not provided, a free-running Vsync signal should be selected to be output.

## **Table 31.2 Vsync Signal Selection Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_FRC3|SC_RES_VS_SEL|1|Vsync Signal Output Select|
||||0: External input Vsync signal|
||||1: Internally generated free-running Vsync signal|

## (2) Masking Repeated Vsync Signals

It is possible to prevent receiving the Vsync signal with a period shorter than the standard period. This is achieved by setting the start timing to receive the next Vsync signal after receiving an input Vsync signal.

The Vsync signal reception masking period is set with the SC_RES_VMASK[15:0] bits.

Masking period [usec] = SC_RES_VMASK × 128 ÷ pixel clock frequency [MHz]

This function is enabled or disabled by the SC_RES_VMASK_ON bit.

**==> picture [452 x 117] intentionally omitted <==**

**----- Start of picture text -----**<br>
Repeated Vsync signals<br>VSIN<br>Masking period Vsync signal is<br>masked during Repeated<br>SC_RES_VMASK[15:0]×128 masking period. Vsync signal<br>masking<br>VSOUT<br>**----- End of picture text -----**<br>

**Figure 31.2 Timing for Masking Repeated Vsync Signals**

**Table 31.3 Repeated Vsync Signal Mask Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_FRC1|SC_RES_VMASK_ON|1|Repeated Vsync Signal Masking Control|
||||0: Repeated Vsync signal masking control is disabled.|
||||1: Repeated Vsync signal masking control is enabled.|
|SC_SCL0_FRC1|SC_RES_VMASK[15:0]|2800|Repeated Vsync Signal Masking Period|
||||Sets the repeated Vsync signal masking period beginning at a|
||||Vsync signal in terms of 128 pixel-clock periods.|
||||Masking period [usec] = SC_RES_VMASK × 128 ÷ pixel clock|
||||frequency [MHz]|

## (3) Compensating for Missing Vsync Signals

It is possible to prevent output of the Vsync signal with a period longer than the standard period. This is achieved by setting the wait time after reception of an input Vsync signal until reception of the next Vsync signal.

If no Vsync signals are received during the wait time, an internally generated sync signal is inserted.

The wait time can be set using the SC_RES_VLACK[15:0] bits.

Wait time [usec] = SC_RES_VLACK × 128 ÷ pixel clock frequency [MHz]

This function is enabled or disabled by the SC_RES_VLACK_ON bit.

If no Vsync signals are input during the Vsync signal reception time, the SC_RES_QVLACK bit is set to the high level.

If Vsync signals are continuously detected four or more times during the Vsync signal reception time, the SC_RES_QVLOCK bit is set to the high level.

The SC_RES_QVLOCK bit is valid even when both the SC_RES_VMASK_ON and SC_RES_VLACK_ON bits are set to turn off the corresponding functions.

Note that, however, the SC_RES_VMASK and SC_RES_VLACK bits must be set correctly.

**==> picture [434 x 117] intentionally omitted <==**

**----- Start of picture text -----**<br>
Missing Vsync signal<br>VSIN<br>If no Vsync signal is input  After a missing-sync compensation, the<br>during wait time measurement is started from<br>Wait time SC_RES_VLACK[15:0]×128 the wait time, a missing-sync the missing-sync pulse.<br>compensating pulse is output. SC_RES_VLACK[15:0]×128<br>Missing-sync<br>VSOUT compensating pulse<br>**----- End of picture text -----**<br>

**Figure 31.3 Compensation of Missing Vsync Signals**

**Table 31.4 Missing Vsync Compensation Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_FRC2|SC_RES_VLACK_ON|1|Missing Vsync Signal Compensation|
||||0: Compensation of missing Vsync signals is disabled.|
||||1: Compensation of missing Vsync signals is enabled.|
|SC_SCL0_FRC2|SC_RES_VLACK[15:0]|3600|Missing-Sync Compensating Pulse Output Wait Time|
||||Sets the wait time before outputting a missing-sync|
||||compensating pulse after a Vsync signal.|
||||Wait time [usec] = SC_RES_VLACK × 128 ÷ pixel clock|
||||frequency [MHz]|
|SC_SCL0_FRC9|SC_RES_QVLACK|—|Missing Vsync Signal Detection Flag|
||||1: Missing Vsync signal input has been detected.|
||||0: No missing Vsync signal input has been detected.|
|SC_SCL0_FRC9|SC_RES_QVLOCK|—|Locked Vsync Signal Detection Flag|
||||1: No repeated or missing Vsync signal input has been detected|
||||for four or more vertical periods.|
||||0: Repeated or missing Vsync signal input has been detected.|

For the Vsync signal, repeated-signal masking is first carried out and then missing-signal compensation is carried out, followed by another repeated-signal masking.

Repetition masking is inserted after missing-Vsync compensation to prevent output of the Vsync signal even in cases such as the input of a Vsync signal immediately after the input of a pulse to compensate for a missing Vsync signal.

On/off control of the missing-Vsync compensation also applies to the second repeated-Vsync masking; and masking period setting of the first repeated-Vsync masking also applies to the second repeated-Vsync masking.

**==> picture [352 x 64] intentionally omitted <==**

**----- Start of picture text -----**<br>
VSIN Repeated-Vsync VS Missing-Vsync VS Repeated-Vsync VSOUT<br>masking compensation masking<br>SC_RES_VMASK_ON SC_RES_VLACK_ON SC_RES_VLACK_ON<br>SC_RES_VMASK[15:0] SC_RES_VLACK[15:0] SC_RES_VMASK[15:0]<br>**----- End of picture text -----**<br>

**Figure 31.4 Repeated-Vsync Masking and Missing-Vsync Compensation**

**==> picture [444 x 211] intentionally omitted <==**

**----- Start of picture text -----**<br>
Missing Vsync signal Vsync signal is input after a missing detected.<br>VSIN<br>First masking period<br>Not masked during<br>First masking<br>SC_RES_VMASK[15:0]×128 the first repeated-<br>period Vsync masking period<br>SC_RES_VLACK[15:0]×128<br>Wait time Wait time Wait time<br>VSOUT after missing-<br>Vsync compensation<br>Missing-Vsync compensating pulse<br>Second masking Second masking<br>Second masking period<br>period period<br>Second masking<br>period<br>Masked during the<br>second repeated-Vsync<br>VSOUT masking period<br>The closer to the end of second masking period the Vsync<br>signal input is, the longer the Vsync signal output cycle is.<br>**----- End of picture text -----**<br>

**Figure 31.5 Timing for Masking Repeated Vsync Signals and Missing Vsync Signal Compensation**

## (4) Free-Running Period

Free-running Vsync and Hsync periods can be set.

Hsync period [usec] = (SC_RES_FH + 1) ÷ pixel clock frequency [MHz]

Vsync period [usec] = horizontal period [usec] × (SC_RES_FV + 1)

## **Table 31.5 Free-Running Period Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_FRC4|SC_RES_FV[10:0]|524|Free-Running Vsync Period Setting|
||||Free-running Vsync period = (SC_RES_FV + 1) × horizontal|
||||period [usec]|
|SC_SCL0_FRC4|SC_RES_FH[10:0]|799|Hsync Period Setting|
||||Hsync period [usec] = (SC_RES_FH +1) ÷ pixel clock frequency|
||||[MHz]|

When selecting an external input Vsync signal, set the SC_RES_VS_SEL bit to 0. At this time, the internally generated free-running Vsync signal is not output.

In the meantime, the Hsync signal is always generated according to the free-running signal setting and output from the scaler.

## (5) Vsync Signal Delay Control

Delay of Vsync signal output from the scaler can be controlled.

The delay is used to adjust the frame buffer read timing.

## **Table 31.6 Vsync Output Delay Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_FRC5|SC_RES_VSDLY[7:0]|1|Vsync Signal Delay Control|
||||Adjusts the Vsync signal delay in the output Hsync period units.|
||||Vsync signal delay [usec]: SC_RES_VSDLY × output Hsync|
||||period [usec]|

**==> picture [368 x 311] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync (input) Vsync (internal) Vsync (scaler output)<br>Moving picture<br>Moving picture<br>A<br>A<br>(write)<br>(input)<br>Moving picture<br>Moving picture<br>B Moving picture<br>B<br>(write) A<br>(input)<br>(read)<br>Moving picture<br>Moving picture<br>C Moving picture<br>C<br>(write) B<br>(input)<br>(read)<br>After 100% scale-up/down, scale<br>down, or rotation processing is<br>Moving picture<br>performed, data is written to the<br>frame buffer. C<br>(read)<br>After data is read from the<br>frame buffer, 100% scale-up/<br>down or scale-up processing is<br>performed.<br>SC_RES_VSDLY<br>**----- End of picture text -----**<br>

**Figure 31.6 Vsync Signal Phases (Two Frame-Buffer Planes Used)**

**==> picture [444 x 270] intentionally omitted <==**

**----- Start of picture text -----**<br>
Vsync (input) Vsync (internal) Vsync (scaler output)<br>I mage to be written<br>before frame buffer<br>Moving picture  Moving picture  reading<br>A A<br>(input) (write) Moving picture<br>A<br>Reading does not get<br>ahead of writing. (read)<br>Moving picture  Moving picture<br>B B<br>(input) (write) Moving picture<br>B<br>(read)<br>Moving picture  Moving picture<br>C C<br>(input) (write) Moving picture<br>C<br>(read)<br>After 100% scale-up/down, scale<br>down, or rotation processing is<br>performed, data is written to the After data is read from the<br>frame buffer.<br>frame buffer, 100% scale-up/<br>down or scale-up processing is<br>performed.<br>SC_RES_VSDLY<br>**----- End of picture text -----**<br>

**Figure 31.7 Vsync Signal Phases (One Frame-Buffer Plane Used)**

## 31.1.4 Setting Angle of View

## (1) Setting Image Area to be Captured

The image area to be captured can be set for reduction or enlargement.

The area is defined by specifying its start position and width based on the input Hsync and Vsync signals.

**Table 31.7 Control of Image Area to be Captured**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_DS2|SC_RES_VS[10:0]|18|Vertical Position Setting for Video Signal Capturing|
||||(VSYNC + (V backporch - 1) lines)|
||||Note: The set value should be four or more (lines). SC_RES_VS|
||||+ SC_RES_VW should be equal to or less than 2039|
||||(lines).|
|SC_SCL0_DS2|SC_RES_VW[10:0]|240|Vertical Width of Video Signal to be Captured (lines)|
||||Note: SC_RES_VS + SC_RES_VW should be equal to or less|
||||than 2039 (lines).|
|SC_SCL0_DS3|SC_RES_HS[10:0]|244|Horizontal Position Setting for Video Signal Capturing|
||||(HSYNC + H backporch video-image clock cycles)|
||||Note: The set value should be 16 or more (clock cycles).|
||||SC_RES_HS + SC_RES_HW should be equal to or less|
||||than 2015 (clock cycles).|
|SC_SCL0_DS3|SC_RES_HW[10:0]|1440|Horizontal Width of Video Signal to be Captured (video-image|
||||clock cycles)|
||||Note: SC_RES_HS + SC_RES_HW should be equal to or less|
||||than 2015 (clock cycles).|

## (2) Generating a Full-Screen Enable Signal

The valid period of the full screen to be output from the scaler can be set.

The valid period is defined by specifying its start position and width based on the Hsync and Vsync signals output from the scaler.

The vertical front porch should be set to four or more lines, and the horizontal front porch should be 16 or more clock cycles.

## **Table 31.8 Full-Screen Enable Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_FRC6|SC_RES_F_VS[10:0]|35|Vertical Enable Signal Start Position for Full Screen.|
||||(VSYNC + V backporch lines)|
||||Note: The set value should be four or more (lines).|
||||SC_RES_F_VS + SC_RES_F_VW should be equal to|
||||or less than 2039 (lines).|
|SC_SCL0_FRC6|SC_RES_F_VW[10:0]|480|Vertical Enable Signal Width for Full Screen (lines)|
||||Note: SC_RES_F_VS + SC_RES_F_VW should be equal to|
||||or less than 2039 (lines).|
|SC_SCL0_FRC7|SC_RES_F_HS[10:0]|144|Horizontal Enable Signal Start Position for Full Screen.|
||||(HSYNC + H backporch pixel-clock cycles)|
||||Note: The set value should be 16 or more (clock cycles).|
||||SC_RES_F_HS + SC_RES_F_HW should be equal to|
||||or less than 2015 (clock cycles).|
|SC_SCL0_FRC7|SC_RES_F_HW[10:0]|640|Horizontal Enable Signal Width for Full Screen (pixel-clock|
||||cycles)|
||||Note 1. SC_RES_F_HS + SC_RES_F_HW should be equal|
||||to or less than 2015 (clock cycles).|
||||Note 2. The set value should be equal to (horizontal signal|
||||width for full screen + 2) when serial RGB output is|
||||selected as an LCD output signal.|

## (3) Generating an Image Output Enable Signal

The valid period of the image to be output can be set.

The valid period is defined by specifying its start position and width based on the Hsync and Vsync signals output from the scaler.

## **Table 31.9 Image Output Enable Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_US2|SC_RES_P_VS[10:0]|35|Vertical Enable Signal Start Position for Output Image.|
||||(VSYNC + V backporch lines)|
||||Note: The set value should be four or more (lines).|
||||SC_RES_P_VS + SC_RES_P_VW should be equal to or|
||||less than 2039 (lines).|
|SC_SCL0_US2|SC_RES_P_VW[10:0]|480|Vertical Enable Signal Width for Output Image (lines)|
||||Note: SC_RES_P_VS + SC_RES_P_VW should be equal to or|
||||less than 2039 (lines).|
|SC_SCL0_US3|SC_RES_P_HS[10:0]|144|Horizontal Enable Signal Start Position for Output Image.|
||||(HSYNC + H backporch pixel-clock cycles)|
||||Note: The set value should be 16 or more (clock cycles).|
||||SC_RES_P_HS + SC_RES_P_HW should be equal to or|
||||less than 2015 (clock cycles).|
|SC_SCL0_US3|SC_RES_P_HW[10:0]|640|Horizontal Enable Signal Width for Output Image (pixel-clock|
||||cycles)|
||||Note: SC_RES_P_HS + SC_RES_P_HW should be equal to or|
||||less than 2015 (clock cycles).|

**==> picture [427 x 578] intentionally omitted <==**

**----- Start of picture text -----**<br>
Setting the area of input image to be captured<br>Input Hsync<br>signal<br>SC_RES_<br>HS SC_RES_HW<br>SC_RES_<br>VS + 1<br>Image area to be captured<br>SC_RES_<br>VW<br>Setting output enable<br>Output Hsync<br>signal<br>SC_RES_FH+1<br>SC_RES_<br>F_HS SC_RES_F_HW<br>Output full-image area<br>Output image area<br>In free-running<br>mode<br>SC_RES_FV + 1<br>SC_RES_<br>P_HS SC_RES_P_HW<br>Input Vsync signal<br>Output Vsync signal<br>VSF _ VSP _<br>SC_RES_ SC_RES_<br>SC_RES_F_VW SC_RES_P_VW<br>**----- End of picture text -----**<br>

**Figure 31.8 Enable Settings**

## 31.1.5 Scaling Settings

## (1) Scaling Processing Block

The scaling-down control block scales down the input image from the input controller.

When rotation is required, the scaling-down control block first scales down the image and then rotates it before writing it into the frame buffer.

The scaling-up control block reads the rotated image from the frame buffer and scales it up.

**Table 31.10 Rotation and Scaling Process**

|**Rotation**|**Horizontal Scaling**<br>**Vertical Scaling**<br>**Scaling-Down Control**<br>**Block**<br>**Scaling-Up Control**<br>**Block**|
|---|---|
|Normal|Horizontal scale down<br>Vertical scale down<br>Horizontal scale down/<br>vertical scale down<br>Horizontal 100% scale up/<br>vertical 100% scale up|
||Horizontal scale down<br>Vertical scale up<br>Horizontal scale down/<br>vertical 100% scale up<br>Horizontal 100% scale up/<br>vertical scale up|
||Horizontal scale up<br>Vertical scale down<br>Horizontal 100% scale up/<br>vertical scale down<br>Horizontal scale up/<br>vertical 100% scale up|
||Horizontal scale up<br>Vertical scale up<br>Horizontal 100% scale up/<br>vertical 100% scale up<br>Horizontal scale up/<br>vertical scale up|
|Horizontal mirroring|Horizontal scale down<br>Vertical scale down<br>Horizontal scale down/<br>vertical scale down<br>Horizontal 100% scale up/<br>vertical 100% scale up|
||Horizontal scale down<br>Vertical scale up<br>Horizontal scale down/<br>vertical 100% scale up<br>Horizontal 100% scale up/<br>vertical scale-up|
||Horizontal scale up<br>Vertical scale down<br>Horizontal 100% scale up/<br>vertical scale down<br>Horizontal scale up/<br>vertical 100% scale up|
||Horizontal scale up<br>Vertical scale up<br>Horizontal 100% scale up/<br>vertical 100% scale up<br>Horizontal scale up/<br>vertical scale up|
|90° rotation|(Horizontal input →<br>vertical output) scale<br>down<br>(Vertical input →<br>horizontal output) scale<br>down<br>Horizontal scale down/<br>vertical scale down<br>Horizontal 100% scale up/<br>vertical 100% scale up|
||(Horizontal input →<br>vertical output) scale<br>down<br>(Vertical input →<br>horizontal output) scale<br>up<br>Horizontal scale down/<br>vertical 100% scale up<br>Horizontal scale up/<br>vertical 100% scale up|
||(Horizontal input →<br>vertical output) scale up<br>(Vertical input →<br>horizontal output) scale<br>up<br>Horizontal 100% scale up/<br>vertical 100% scale up<br>Horizontal scale up/<br>vertical scale up|
|180° rotation|Horizontal scale down<br>Vertical scale down<br>Horizontal scale down/<br>vertical scale down<br>Horizontal 100% scale up/<br>vertical 100% scale up|
||Horizontal scale down<br>Vertical scale up<br>Horizontal scale down/<br>vertical 100% scale up<br>Horizontal 100% scale up/<br>vertical scale up|
||Horizontal scale up<br>Vertical scale down<br>Horizontal 100% scale up/<br>vertical scale down<br>Horizontal scale up/<br>vertical 100% scale up|
||Horizontal scale up<br>Vertical scale up<br>Horizontal 100% scale up/<br>vertical 100% scale up<br>Horizontal scale up/<br>vertical scale up|
|270° rotation|(Horizontal input→vertical<br>output) scale down<br>(Vertical input→horizontal<br>output) scale down<br>Horizontal scale down/<br>vertical scale down<br>Horizontal 100% scale up/<br>vertical 100% scale up|
||(Horizontal input →<br>vertical output) scale<br>down<br>(Vertical input →<br>horizontal output) scale<br>up<br>Horizontal scale down/<br>vertical 100% scale up<br>Horizontal scale up/<br>vertical 100% scale up|
||(Horizontal input →<br>vertical output) scale up<br>(Vertical input →<br>horizontal output) scale<br>up<br>Horizontal 100% scale up/<br>vertical 100% scale up<br>Horizontal scale up/<br>vertical scale up|

**==> picture [472 x 122] intentionally omitted <==**

**----- Start of picture text -----**<br>
Horizontal scale down Horizontal scale up<br>Rotating the image data and writing  Reading the rotated image data from<br>Scaling down the input image the data to the frame buffer the frame buffer Scaling up the rotated image<br>Vertical scale down Vertical scale up<br>**----- End of picture text -----**<br>

**Figure 31.9 Rotation and Scaling Process**

It is impossible to use vertical reduction by the scaling-down control block and vertical enlargement by the scaling-up control block simultaneously because they are mutually exclusive. Thus, the following scaling processes cannot be performed with 90° rotation or 270° rotation.

**Table 31.11 Impossible Scaling Process**

||||**Scaling-Down Control**|**Scaling-Up Control**|
|---|---|---|---|---|
|**Rotation**|**Horizontal Scaling**|**Vertical Scaling**|**Block**|**Block**|
|90° rotation|(Horizontal input →|(Vertical input →|Horizontal 100% scale up/|Horizontal 100% scale up/|
|270° rotation|vertical output) scale up|horizontal output) scale|vertical scale down|vertical scale up|
|||down|||

**==> picture [219 x 134] intentionally omitted <==**

**----- Start of picture text -----**<br>
Scale down<br>Input image Output image<br>Scale up<br>**----- End of picture text -----**<br>

**Figure 31.10 Impossible Scaling Process**

## 31.1.6 Horizontal Prefilter

The horizontal prefilter can be turned on or off for brightness (Y) and RGB signals to suppress the frequency band of the signals during horizontal size reduction. The input format depends on the SC_RES_MD[1:0] bit setting in the writing mode register (SC_SCL1_WR1).

When the horizontal reduction ratio is high and there is too much folding frequency component to ignore, the horizontal prefilter should be turned on.

## **Table 31.12 Horizontal Prefilter Settings**

|**Input Format**|**SC_RES_PFIL_SEL**<br>**Operation**|
|---|---|
|YCbCr input|1<br>Turns on the horizontal prefilter for Y signal and turns off the horizontal prefilter<br>for Cb/Cr signal.|
||0<br>Turns off the horizontal prefilter.|
|RGB input|1<br>Turns on the horizontal prefilter for RGB signal.|
||0<br>Turns off the horizontal prefilter.|

## **Table 31.13 Horizontal Prefilter Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_DS4|SC_RES_PFIL_SEL|0|Prefilter Mode Select for Brightness Signals|
||||0: The prefilter is turned off.|
||||1: The prefilter is turned on. (1/4 + 1/2 + 1/4)|

## 31.1.7 Horizontal Scale-Down

The number of horizontally arranged pixels can be decreased at a desired ratio in the range of 1/1 to 1/8 using pixel conversion.

For the scaling filter, either hold or linear interpolation mode can be selected.

## (1) One-TAP Hold Interpolation

When the interpolation position is between input pixels X _n_ and X _n+1_ , the X _interpo_ interpolation value is defined as follows. Xinterpo = Xn

## (2) Two-TAP Linear Interpolation

When the interpolation position is between input pixels X _n_ and X _n+1_ , the X _interpo_ interpolation value is defined as follows based on the interpolation position "phase".

X _interpo_ = (X _n_ × (4096 − phase) + X _n+1_ × phase) / 4096

## (3) Calculation of Horizontal Scale Down Ratio

The value to be set to the horizontal scale-down ratio SC_RES_DS_H_RATIO can be obtained using the following equation based on the number of input pixels SC_RES_HW and number of output pixels SC_RES_OUT_HW, where the decimals are rounded off.

SC_RES_DS_H_RATIO = round (SC_RES_HW ÷ SC_RES_OUT_HW × 4096)

Note that, for 100% horizontal scale-up, the SC_RES_HW and SC_RES_OUT_HW values should be identical and the SC_RES_DS_H_RATIO bits should be set to 4096.

## (4) Handling for Lack of Last-Input Pixel

Interpolation is carried out between the second-last-input and last-input pixels to produce the last-output pixel at the right end of a screen. The interpolation position of the last-output pixel may be close to the second-last-input pixel depending on the horizontal scale-down ratio; in this case, it may appear that the last-input pixel is lacking.

The undesirable influence by lack of last-input pixel can be decreased by appropriately adjusting the horizontal scaledown ratio using the following equations.

Pre-adjustment horizontal scale-down ratio RATIO_org should be calculated first to find adjustment value σ, and then scale-down ratio SC_RES_DS_H_RATIO should be determined.

RATIO_org = round (SC_RES_HW ÷ SC_RES_OUT_HW × 4096)

σ = (RATIO_org × (SC_RES_OUT_HW − 1) − (SC_RES_HW − 1) × 4096) ÷ (SC_RES_OUT_HW − 1)

SC_RES_DS_H_RATIO = roundup (RATIO_org − σ)

## **Table 31.14 Horizontal Scale Down Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_DS1|SC_RES_DS_H_|1|Horizontal Scale Down On/Off|
||ON||0: Off|
||||1: On|
|SC_SCL0_DS7|SC_RES_OUT_|640|Number of Valid Horizontal Pixels Output by Scaling-down Control|
||HW[10:0]||Block|
||||(Video-image clock cycles)|
|SC_SCL0_DS4|SC_RES_DS_H_|1|Horizontal Interpolation Mode Select|
||INTERPOTYP||0: Hold interpolation|
||||1: Linear interpolation|
|SC_SCL0_DS4|SC_RES_DS_H_|9224|Horizontal Scale Down Ratio|
||RATIO[15:0]||([15:12]: Integer part, [11:0]: Decimal part)|
||||round(SC_RES_HW ÷ SC_RES_OUT_HW × 4096)|
||||SC_RES_DS_H_RATIO < 4096: Setting prohibited|
||||SC_RES_DS_H_RATIO = 4096: 100% scale up|
||||SC_RES_DS_H_RATIO > 4096: Scale down|

Note: The SC_RES_OUT_HW value should be aligned in 4-pixel units and equal to or smaller than the SC_RES_HW value.

## 31.1.8 Vertical Scale-Down

The number of lines can be decreased in the vertical direction at a desired ratio in the range of 1/1 to 1/8 using pixel conversion.

For the scaling filter, either hold or linear interpolation mode can be selected.

## (1) One-TAP Hold Interpolation

When the interpolation position is between input lines X _n_ and X _n+1_ , the X _interpo_ interpolation value is defined as follows. Xinterpo = Xn

## (2) Two-TAP Linear Interpolation

When the interpolation position is between input lines X _n_ and X _n+1_ , the X _interpo_ interpolation value is defined as follows based on the interpolation position "phase".

X _interpo_ = (X _n_ × (4096 − phase) + X _n+1_ × phase) / 4096

## (3) Calculation of Vertical Scale Down Ratio

The value to be set to the vertical scale-down ratio SC_RES_V_RATIO can be obtained using the following equation based on the number of input lines SC_RES_VW and number of output lines SC_RES_OUT_VW, where the decimals are rounded off.

SC_RES_V_RATIO = round (SC_RES_VW ÷ SC_RES_OUT_VW × 4096)

Note that the SC_RES_VW and SC_RES_OUT_VW values should be identical for vertical enlargement or 100% vertical enlargement.

For 100% vertical enlargement, reduction is carried out assuming SC_RES_V_RATIO as 4096.

## (4) Handling for Lack of Last-Input Line

Interpolation is carried out between the second-last-input and last-input lines to produce the last-output line at the lower end of a screen. The interpolation position of the last-output line may be close to the second-last-input line depending on the vertical scale-down ratio; in this case, it may appear that the last-input line is lacking.

The undesirable influence by the lack of last-input line can be decreased by appropriately adjusting the vertical scaledown ratio using the following equations.

Pre-adjustment vertical scale-down ratio RATIO_org should be calculated first to find adjustment value σ, and then scale-down ratio SC_RES_V_RATIO should be determined.

RATIO_org = round (SC_RES_VW ÷ SC_RES_OUT_VW × 4096)

σ = (RATIO_org × (SC_RES_OUT_VW − 1) − (SC_RES_VW − 1) × 4096) ÷ (SC_RES_OUT_VW − 1)

SC_RES_V_RATIO = round (RATIO_org − σ)

**Table 31.15 Vertical Scale Down Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_DS1|SC_RES_DS_V_ON|1|Vertical Scale Down On/Off|
||||0: Off|
||||1: On|
|SC_SCL0_DS7|SC_RES_OUT_VW|240|Number of Valid Lines in Vertical Direction Output by|
||[10:0]||Scaling-Down Control Block (lines)|
||||This bit setting is used for the number of lines to be written to|
||||the frame buffer.|
||||When SC_SCL1_WR1.SC_RES_LOOP is 0 (frame write|
||||mode), these bits specify the number of lines for one frame.|
||||When SC_SCL1_WR1.SC_RES_LOOP is 1 (line write|
||||mode), these bits specify the number of lines for writing in a|
||||ring configuration.|
|SC_SCL0_DS5|SC_RES_V_|1|Vertical Interpolation Mode Select|
||INTERPOTYP||0: Hold interpolation|
||||1: Linear interpolation|
|SC_SCL0_DS6|SC_RES_V_RATIO|2044|Vertical Scale UP/Down Ratio|
||[15:0]||([15:12]: Integer part, [11:0]: Decimal part)|
||||For scale down: round(SC_RES_VW ÷ SC_RES_OUT_VW|
||||× 4096)|
||||For scale up: round(SC_RES_IN_VW ÷ SC_RES_P_VW ×|
||||4096)|
||||SC_RES_V_RATIO < 4096: Scale up|
||||SC_RES_V_RATIO = 4096: 100% scale up|
||||SC_RES_V_RATIO > 4096: Scale down|

Note: SC_RES_V_RATIO and SC_RES_V_INTERPOTYP are both shared by vertical reduction and vertical enlargement.

It is impossible to use vertical reduction and vertical enlargement simultaneously because they are mutually exclusive.

The SC_RES_OUT_VW value should be aligned in 4-line units and equal to or smaller than the SC_RES_VW value.

## 31.1.9 Horizontal Scale Up

The number of horizontally arranged pixels can be increased at a desired ratio in the range of 1/1 to 8/1 using pixel conversion.

For the scaling filter, either hold or linear interpolation mode can be selected.

## (1) One-TAP Hold Interpolation

When the interpolation position is between input pixels X _n_ and X _n+1_ , the X _interpo_ interpolation value is defined as follows. Xinterpo = Xn

## (2) Two-TAP Linear Interpolation

When the interpolation position is between input pixels X _n_ and X _n+1_ , the X _interpo_ interpolation value is defined as follows based on the interpolation position "phase".

X _interpo_ = (X _n_ × (4096 − phase) + X _n+1_ × phase) / 4096

## (3) Calculation of Horizontal Scale Up Ratio

The value to be set to the horizontal scale-up ratio SC_RES_US_H_RATIO can be obtained using the following equation based on the number of input pixels SC_RES_IN_HW and number of output pixels SC_RES_P_HW, where the decimals are rounded off.

SC_RES_US_H_RATIO = round (SC_RES_IN_HW ÷ SC_RES_P_HW × 4096)

Note that, for 100% horizontal scale-up, the SC_RES_IN_HW and SC_RES_P_HW values should be identical and the SC_RES_US_H_RATIO bits should be set to 4096.

## (4) Folding Handling

Since interpolation is carried out between the last-input pixel and second-last-input folding pixel to produce the lastoutput pixel at the right end of a screen, folding may undesirably stand out depending on the horizontal scale up ratio.

The undesirable influence by folding pixels can be decreased by appropriately adjusting the horizontal scale-up ratio using the following equations.

Pre-adjustment horizontal scale-up ratio RATIO_org should be calculated first to find adjustment value σ, and then scaleup ratio SC_RES_US_H_RATIO should be determined.

RATIO_org = round (SC_RES_IN_HW ÷ SC_RES_P_HW × 4096)

σ = (RATIO_org × (SC_RES_P_HW − 1) − (SC_RES_IN_HW − 1) × 4096 ÷ (SC_RES_P_HW − 1)

SC_RES_US_H_RATIO = round (RATIO_org − σ)

**Table 31.16 Horizontal Scale Up Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_US1|SC_RES_US_H_ON|1|Horizontal Scale Up On/Off|
||||0: Off|
||||1: On|
|SC_SCL0_US4|SC_RES_IN_HW[10:0]|640|Number of Valid Horizontal Pixels Input to Scaling-up|
||||Control Block|
||||(Pixel-clock cycles)|
|SC_SCL0_US6|SC_RES_US_H_|1|Horizontal Interpolation Mode Select|
||INTERPOTYP||0: Hold interpolation|
||||1: Linear interpolation|
|SC_SCL0_US5|SC_RES_US_H_RATIO|9224|Horizontal Scale Up Ratio|
||[15:0]||([15:12]: Integer part, [11:0]: Decimal part)|
||||round(SC_RES_IN_HW ÷ SC_RES_P_HW × 4096)|
||||SC_RES_US_H_RATIO < 4096: Scale up|
||||SC_RES_US_H_RATIO = 4096: 100% scale-up|
||||SC_RES_US_H_RATIO > 4096: Setting prohibited|

## 31.1.10 Vertical Scale-Up

The number of lines can be increased in the vertical direction at a desired ratio in the range of 1/1 to 8/1 using pixel conversion.

For the scaling filter, either hold or linear interpolation mode can be selected.

## (1) One-TAP Hold Interpolation

When the interpolation position is between input lines X _n_ and X _n+1_ , the X _interpo_ interpolation value is defined as follows. Xinterpo = Xn

## (2) Two-TAP Linear Interpolation

When the interpolation position is between input lines X _n_ and X _n+1_ , the X _interpo_ interpolation value is defined as follows based on the interpolation position "phase".

X _interpo_ = (X _n_ × (4096 − phase) + X _n+1_ × phase) / 4096

## (3) Calculation of Vertical Scale Up Ratio

The value to be set to the vertical scale-up ratio SC_RES_V_RATIO can be obtained using the following equation based on the number of input lines SC_RES_IN_VW and number of output lines SC_RES_P_VW, where the decimals are rounded off.

## SC_RES_V_RATIO = round (SC_RES_IN_VW ÷ SC_RES_P_VW × 4096)

Note that, for 100% vertical enlargement or vertical reduction, the SC_RES_IN_VW and SC_RES_P_VW values should be identical.

## (4) Folding Handling

The last line to be output at the bottom of the screen is produced by interpolation between the last line and line for folding (second-last line to be input). According to the vertical scale-up rate, this may cause folding to stand out.

The undesirable influence by folding lines can be decreased by appropriately adjusting the vertical scale-up ratio using the following equations.

Pre-adjustment vertical scale-up ratio RATIO_org should be calculated first to find adjustment value σ, and then scale-up ratio SC_RES_V_RATIO should be determined.

RATIO_org = round (SC_RES_IN_VW ÷ SC_RES_P_VW × 4096)

σ = (RATIO_org × (SC_RES_P_VW − 1) − (SC_RES_IN_VW − 1) × 4096) ÷ (SC_RES_P_VW − 1)

SC_RES_V_RATIO = round (RATIO_org − σ)

## **Table 31.17 Vertical Scale Up Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_US1|SC_RES_US_V_ON|1|Vertical Scale Up On/Off|
||||0: Off|
||||1: On|
|SC_SCL0_US4|SC_RES_IN_VW[10:0]|240|Number of Valid Lines in Vertical Direction Input to|
||||Scaling-up Control Block|
||||(Lines)|
|SC_SCL0_DS5|SC_RES_V_INTERPOTYP|1|Vertical Interpolation Mode Select|
||||0: Hold interpolation|
||||1: Linear interpolation|
|SC_SCL0_DS6|SC_RES_V_RATIO[15:0]|2044|Vertical Scale Up Ratio|
||||([15:12]: Integer part, [11:0]: Decimal part)|
||||For scale down: round(SC_RES_VW ÷|
||||SC_RES_OUT_VW × 4096)|
||||For scale up: round(SC_RES_IN_VW ÷ SC_RES_P_VW|
||||× 4096)|
||||SC_RES_V_RATIO < 4096: Scale up|
||||SC_RES_V_RATIO = 4096: 100% scale up|
||||SC_RES_V_RATIO > 4096: Scale down|

Note: SC_RES_V_RATIO and SC_RES_V_INTERPOTYP are both shared by vertical reduction and vertical enlargement.

It is impossible to use vertical reduction and vertical enlargement simultaneously because they are mutually exclusive.

## 31.1.11 IP Conversion

## (1) Initial Phase Control

When interlaced signals are input, line flickering caused by the line offset between the top and bottom fields can be decreased before being displayed by independently adjusting the initial scaling phases of the fields.

For various operations, appropriate settings should be made referring to the relevant registers as listed in Table 31.18 .

**Table 31.18 Initial Scaling Phase Settings (Standard Values) for IP Conversion**

|**Rotation**|**Horizontal Scaling**<br>**Vertical Scaling**<br>**Reference Bit (Setting)**|
|---|---|
|Normal|Horizontal scale down<br>Vertical scale down<br>SC_RES_TOP_INIPHASE = 2048|
||Horizontal scale down<br>Vertical scale up<br>SC_RES_TOP_INIPHASE = 2048|
||Horizontal scale up<br>Vertical scale down<br>SC_RES_TOP_INIPHASE = 2048|
||Horizontal scale up<br>Vertical scale up<br>SC_RES_TOP_INIPHASE = 2048|
|Horizontal mirroring|Horizontal scale down<br>Vertical scale down<br>SC_RES_TOP_INIPHASE = 2048|
||Horizontal scale down<br>Vertical scale up<br>SC_RES_TOP_INIPHASE = 2048|
||Horizontal scale up<br>Vertical scale down<br>SC_RES_TOP_INIPHASE = 2048|
||Horizontal scale up<br>Vertical scale up<br>SC_RES_TOP_INIPHASE = 2048|
|90° rotation|(Horizontal input → vertical<br>output) scale down<br>(Vertical input → horizontal<br>output) scale down<br>SC_RES_TOP_INIPHASE = 2048|
||(Horizontal input → vertical<br>output) scale down<br>(Vertical input → horizontal<br>output) scale up<br>SC_RES_TOP_INIPHASE = 2048|
||(Horizontal input → vertical<br>output) scale up<br>(Vertical input → horizontal<br>output) scale up<br>SC_RES_US_HB_INIPHASE = 2048|
|180° rotation|Horizontal scale down<br>Vertical scale down<br>SC_RES_TOP_INIPHASE = 2048|
||Horizontal scale down<br>Vertical scale up<br>SC_RES_BTM_INIPHASE = 2048|
||Horizontal scale up<br>Vertical scale down<br>SC_RES_TOP_INIPHASE = 2048|
||Horizontal scale up<br>Vertical scale up<br>SC_RES_BTM_INIPHASE = 2048|
|270° rotation|(Horizontal input → vertical<br>output) scale down<br>(Vertical input → horizontal<br>output) scale down<br>SC_RES_TOP_INIPHASE = 2048|
||(Horizontal input → vertical<br>output) scale down<br>(Vertical input → horizontal<br>output) scale up<br>SC_RES_TOP_INIPHASE = 2048|
||(Horizontal input → vertical<br>output) scale up<br>(Vertical input → horizontal<br>output) scale up<br>SC_RES_US_HT_INIPHASE = 2048|

Note: Set 0 to the initial phase control registers where the specific value is not shown in the table. Set 0 to all the initial phase control registers when progressive signals are input.

**Table 31.19 Initial Scaling Phase Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_DS5|SC_RES_BTM_INIPHASE|0|Vertical Interpolation Start Phase for Bottom Field|
||[11:0]||0 to 4095 (0 to approx. 1.0)|
|SC_SCL0_DS5|SC_RES_TOP_INIPHASE|2048|Vertical Interpolation Start Phase for Top Field|
||[11:0]||0 to 4095 (0 to approx. 1.0)|
|SC_SCL0_US6|SC_RES_US_HB_INIPHASE|0|Horizontal Interpolation Start Phase for Bottom Field|
||[11:0]||0 to 4095 (0 to approx. 1.0)|
|SC_SCL0_US6|SC_RES_US_HT_INIPHASE|0|Horizontal Interpolation Start Phase for Top Field|
||[11:0]||0 to 4095 (0 to approx. 1.0)|

**==> picture [448 x 346] intentionally omitted <==**

**----- Start of picture text -----**<br>
Progressive image<br>(1)<br>(2)<br>(3)<br>(4)<br>(5)<br>(6)<br>P-I conversion<br>Interlaced image  Interlaced image<br>(TOP) (BOTTOM)<br>(1)<br>Initial phase = 2048<br>0.5 × (1) + 0.5 × (3) (2) (2)<br>(3) (3) 0.5 × (2) + 0.5 × (4)<br>0.5 × (3) + 0.5 × (5) (4) (4)<br>(5) (5) 0.5 × (4) + 0.5 × (6)<br>... (6) (6)<br>... ... ...<br>...<br>I-P conversion Progressive image  I-P conversion<br>after IP conversion<br>**----- End of picture text -----**<br>

**Figure 31.11 IP Conversion Processing Schematic Diagram**

## (2) Field Determination Signal Control

When interlaced signals are input, the field determination signal can be controlled, which is output to the scaling-up control block during vertical scaling.

When progressive signals are input or vertical scaling is carried out by the scaling-down control block, the field determination signal output to the scaling-up control block is fixed to the specific level, and thus either 0 or 1 can be set to the SC_RES_FLD_DLY_SEL bit.

**Table 31.20 Settings for Field Determination Signal Control**

|**Input Signal**|**Rotation**|**Vertical Processing**|**Frame Buffer**<br>**SC_RES_FLD_DLY_SEL**|
|---|---|---|---|
|Progressive|—|—|—<br>—|
|Interlace|Normal<br>Horizontal mirroring<br>180° rotation|Vertical scale down|—<br>—|
|||Vertical scale up|One plane or less<br>0|
||||Two planes or more<br>1|
||90° rotation<br>270° rotation|(Horizontal input → vertical<br>output) scale down|—<br>—|
|||(Horizontal input → vertical<br>output) scale up|Two planes or more<br>1|

## **Table 31.21 Field Determination Signal Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_FRC5|SC_RES_FLD_DLY_SEL|1|Field Determination Signal Delay Control|
||||0: No delay|
||||1: Delay of one vertical cycle|

## 31.1.12 Control of Interrupt on Specified Image Line before Scaling-down, and Reading of Current Image Line before Scaling-down

When the location of the image line input to the scaling-down control block matches the SC_SCL1_LINE setting, an interrupt processing is done. In addition, the current location of the line input to the scaling-down control block can be read from a register.

## **Table 31.22 Control of Interrupt on Specified Image Line before Scaling-down, and Reading of Current Image line before Scaling-down**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_INT|SC_RES_LINE[10:0]|All 0|Setting of Interrupt on Image Line Input to Scaling-down|
||||Control Block|
||||When the location of the image line input to the scaling-|
||||down control block matches the SC_SCL0_LINE setting,|
||||an interrupt signal is output. (Setting prohibited in this|
||||product)|
|SC_SCL0_MON0|SC_RES_LIN_STAT[10:0]|All 0|Current Location of Image Line Input to Scaling-down|
||||Control Block|

## 31.1.13 Trimming

The upper, lower, right, and left parts of a post-scaling image can be trimmed off as specified by the SC_RES_VCUT and SC_RES_HCUT bits before being output.

The frame lines of the post-scaling image can also be displayed by setting the SC_RES_DISP_ON bit to 1.

**==> picture [391 x 305] intentionally omitted <==**

**----- Start of picture text -----**<br>
Hsync<br>Horizontal trimming width [clk] =<br>SC_RES_HCUT Vertical enable signal<br>start position [line]<br>= SC_RES_P_VS<br>Output image area<br>1[line]<br>Vertical width [line]<br>Output area after = SC_RES_P_VW<br>trimming<br>1[line]<br>White data output<br>Horizontal width [clk] = SC_RES_P_HW<br>Horizontal enable signal start position [clk] = SC_RES_P_HS<br>Vsync<br>1[clk] 1[clk]<br>= SC_RES_VCUT<br>Vertical trimming width [line]<br>**----- End of picture text -----**<br>

**Figure 31.12 Area Relationship for Trimming (Frame Lines Displayed)**

## **Table 31.23 Trimming Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_US7|SC_RES_HCUT[7:0]|0|Horizontal Amount of Cut-off Post-Scaling Image (Right and Left|
||||Parts)|
||||Sets the number of pixel-clock cycles.|
|SC_SCL0_US7|SC_RES_VCUT[7:0]|0|Vertical Amount of Cut-off Post-Scaling Image (Upper and Lower|
||||Parts)|
||||Sets the number of lines.|
|SC_SCL0_US8|SC_RES_DISP_ON|0|Post-Scaling Image Frame Display On/Off|
||||0: Frame display on|
||||1: Frame display off|

## 31.1.14 Screen Synthesis

During the valid full-screen period, the image area can be overlaid before being output. If the image area to be output is smaller than a full-screen, the background color specified by the SC_RES_BK_COL_R, SC_RES_BK_COL_G, and SC_RES_BK_COL_B bits are displayed to fill the background.

**Table 31.24 Screen Synthesis Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_OVR1|SC_RES_BK_COL_R|128|Background Color Setting R/Cr Signal|
||[7:0]||R:<br>8 bits; unsigned (0 to 255 [LSB])|
||||Cr:<br>8 bits; 128 offset binary; unsigned (0 to 255 [LSB])|
|SC_SCL0_OVR1|SC_RES_BK_COL_B|128|Background Color Setting B/Cb Signal|
||[7:0]||B:<br>8 bits; unsigned (0 to 255 [LSB])|
||||Cb:<br>8 bits; 128 offset binary; unsigned (0 to 255 [LSB])|
|SC_SCL0_OVR1|SC_RES_BK_COL_G|0|Background Color Setting G/Y Signal|
||[7:0]||G/Y:<br>8 bits; unsigned (0 to 255 [LSB])|

**==> picture [391 x 305] intentionally omitted <==**

**----- Start of picture text -----**<br>
Hsync<br>SC_RES_F_VS<br>Output full-image area<br>Output image area<br>SC_RES_F_VW<br>SC_RES_<br>P_HS SC_RES_P_HW<br>Specifying the color<br>with<br>SC_RES_BK_COL_R,<br>SC_RES_BK_COL_G,<br>and<br>SC_RES_BK_COL_B<br>SC_RES_<br>F_HS SC_RES_F_HW<br>Vsync<br>P_VS<br>SC_RES_<br>SC_RES_P_VW<br>**----- End of picture text -----**<br>

**Figure 31.13 Area Relationship with Output Image Size Smaller than a Full Screen**

## 31.1.15 Selecting Format for Writing Video Image Signals to Frame Buffer

A format can be selected for writing video image signals to the frame buffer.

Although 24-bit YCbCr signals or 24-bit RGB signals are input to the scaling control block, they are converted into 16bit YCbCr422 signals, 16-bit RGB565 signals, 32-bit YCbCr444 signals, or 32-bit RGB888 signals before being written to the frame buffer.

As bit reduction processing of RGB565, rounding off or 2 × 2 pattern dither can be selected with the SC_RES_DTH_ON bit. For details on pattern dither, see section 34.1.7, Dither Process in section 34., Video Display Controller 5 (7): Output Controller .

## **Table 31.25 Frame Buffer Writing Mode Setting**

|**RES_BITDEC_ON**|**SC_RES_MD[1:0]**|**Writing Mode**|
|---|---|---|
|0|3|YCbCr444 (normal, horizontal mirroring)|
|0|2|RGB888 (normal, horizontal mirroring)|
|1|1|RGB565 (normal, horizontal mirroring, rotation)|
|*|0|YCbCr422 (normal, horizontal mirroring, rotation)|

## **Table 31.26 Video Signal Writing Format Selection Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_WR1|SC_RES_MD[1:0]|0|Frame Buffer Video-Signal Writing Format|
||||0: YCbCr422 (16 bits)|
||||1: RGB565 (16 bits)|
||||2: RGB888 (24 (32) bits)|
||||3: YCbCr444 (24 (32) bits)|
|SC_SCL1_WR6|SC_RES_BITDEC_ON|0|Bit Reduction On/Off|
||||0: Off|
||||1: On|
|SC_SCL1_WR6|SC_RES_DTH_ON|0|Dither Correction On/Off|
||||0: Off (rounded off)|
||||1: On (2 × 2 pattern dither)|

## 31.1.16 Horizontal Mirroring and Rotation

Horizontal mirroring and rotation can be carried out for scaled-down images before being written to the frame buffer.

Table 31.27 and Table 31.28 show the relationship between various writing modes for image processing and video signals.

**Table 31.27 Relationship between Writing Modes and Video Signals**

|**RES_DS_WR_MD[2:0]**|**Writing Modes**|**YCbCr444**|**YCbCr422**|**RGB565**|**RGB888**|
|---|---|---|---|---|---|
|0|Normal writing|Enabled|Enabled|Enabled|Enabled|
|1|Horizontal mirroring|Enabled|Enabled|Enabled|Enabled|
|2|90° rotation|Disabled|Enabled|Enabled|Disabled|
|3|180° rotation|Disabled|Enabled|Enabled|Disabled|
|4|270° rotation|Disabled|Enabled|Enabled|Disabled|
|5 to 7|Setting prohibited|—|—|—|—|

## **Table 31.28 Horizontal Mirroring and Rotation Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_WR1|SC_RES_DS_WR_MD|0|Frame Buffer Writing Mode for Image Processing|
||[2:0]||0: Normal|
||||1: Horizontal mirroring|
||||2: 90° rotation|
||||3: 180° rotation|
||||4: 270° rotation|
||||5 to 7: Setting prohibited|

## 31.1.17 Writing to Frame Buffer

## (1) Frame Buffer Transfer Mode

Either 32-byte or 128-byte transfer mode can be selected for accessing the frame buffer in which video image data and graphics data are stored.

## **Table 31.29 Frame Buffer Transfer Mode**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_WR1|SC_RES_BST_MD|0|Transfer Burst Length for Frame Buffer Writing|
||||0: 32-byte|
||||1: 128-byte|

## (2) Frame Buffer Write Control

Frame buffer writing is enabled or disabled.

## **Table 31.30 Frame Buffer Writing Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_WR5|SC_RES_WENB|0|Frame Buffer Write Enable|
||||After making the setting to enable writing, writing starts from the|
||||second frame.|
||||0: Frame buffer writing is disabled.|
||||1: Frame buffer writing is enabled.|

## (3) Frame Buffer Writing Rate Selection

A frame buffer writing rate can be selected from among 1/1, 1/2, 1/4, and 1/8 the vertical frequency of the input signal.

When 1/2, 1/4, or 1/8 is selected, either the top or bottom field can be selected for writing.

## **Table 31.31 Frame Buffer Write Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_WR5|SC_RES_FS_RATE|0|Writing Rate|
||[1:0]||Sets the frame buffer writing rate to the vertical frequency of the|
||||input signal.|
||||0: 1/1 an input signal (The SC_RES_FLD_SEL setting is invalid.)|
||||1: 1/2 an input signal|
||||2: 1/4 an input signal|
||||3: 1/8 an input signal|
|SC_SCL1_WR5|SC_RES_FLD_SEL|0|Write Field Select|
||||0: Top field|
||||1: Bottom field|
|SC_SCL1_WR5|SC_RES_INTER|1|Field Operating Mode Select|
||||0: Progressive|
||||1: Interlace|

## (4) Frame Buffer Write Addresses

Frame buffer addresses are specified using the base address, line offset address, frame offset address, data size of a line, and the number of lines in a frame. When an interlaced video image is input, the top and bottom field data can be separately stored in the frame buffer.

The SC_RES_BASE[31:0], SC_RES_LN_OFF[14:0], and SC_RES_FLM_OFF[22:0] bits should be set in 32-byte units (the lower five bits should be fixed to 0).

For 128-byte transfer, bits [6:5] in the address control registers should be fixed to 0 since addresses should be specified in 128-byte units.

For the data size of a line and the number of lines in a frame, the relevant register values set for the scaling-down control block are used.

**Table 31.32 Frame Buffer Write Address Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_WR1|SC_RES_TB_ADD_|0|Top and Bottom Data Write Address Specification Method|
||MOD||0: A write address is specified in common for top and bottom data.|
||||1: Separate write addresses are specified for top and bottom data.|
|SC_SCL1_WR2|SC_RES_BASE|0|Frame Buffer Base Address|
||[31:0]||Sets the start address of the frame buffer to store the frame data|
||||for the top field when SC_RES_TB_ADD_MOD = 1 or that for the|
||||top and bottom fields when SC_RES_TB_ADD_MOD = 0.|
||||For 32-byte transfer: The lower five bits should be fixed to 0_0000.|
||||For 128-byte transfer: The lower seven bits should be fixed to|
||||000_0000.|
|SC_SCL1_WR8|SC_RES_BASE_B|0|Frame Buffer Base Address for Bottom|
||[31:0]||Sets the start address of the frame buffer to store the frame data|
||||for the bottom field when SC_RES_TB_ADD_MOD = 1.|
||||For 32-byte transfer: The lower five bits should be fixed to 0_0000.|
||||For 128-byte transfer: The lower seven bits should be fixed to|
||||000_0000.|
|SC_SCL1_WR3|SC_RES_LN_OFF|2048|Frame Buffer Line Offset Address|
||[14:0]||Sets the line offset address for calculating the line start address|
||||for the top field when SC_RES_TB_ADD_MOD = 1 or that for the|
||||top and bottom fields when SC_RES_TB_ADD_MOD = 0.|
||||Line 0: SC_RES_BASE|
||||Line 1: SC_RES_BASE + SC_RES_LN_OFF × 1|
||||:|
||||Line n: SC_RES_BASE + SC_RES_LN_OFF × n|
||||For 32-byte transfer: The lower five bits should be fixed to 0_0000.|
||||For 128-byte transfer: The lower seven bits should be fixed to|
||||000_0000.|
|SC_SCL1_WR9|SC_RES_LN_OFF_B|2048|Frame Buffer Line Offset Address for Bottom|
||[14:0]||Sets the line offset address for calculating the line start address|
||||for the bottom field when SC_RES_TB_ADD_MOD = 1.|
||||Line 0: SC_RES_BASE_B|
||||Line 1: SC_RES_BASE_B + SC_RES_LN_OFF_B × 1|
||||:|
||||Line n: SC_RES_BASE_B+ SC_RES_LN_OFF_B × n|
||||For 32-byte transfer: The lower five bits should be fixed to 0_0000.|
||||For 128-byte transfer: The lower seven bits should be fixed to|
||||000_0000.|
|SC_SCL1_WR4|SC_RES_FLM_OFF|524288|Frame Buffer Frame Offset Address|
||[22:0]||Sets the frame offset address for calculating the start address of|
||||each frame for the top field when SC_RES_TB_ADD_MOD = 1 or|
||||that for the top and bottom fields when SC_RES_TB_ADD_MOD|
||||= 0.|
||||Buffer 0: SC_RES_BASE|
||||Buffer 1: SC_RES_BASE + SC_RES_FLM_OFF × 1|
||||:|
||||Buffer n: SC_RES_BASE + SC_RES_FLM_OFF × n|
||||For 32-byte transfer: The lower five bits should be fixed to 0_0000.|
||||For 128-byte transfer: The lower seven bits should be fixed to|
||||000_0000.|

## **Table 31.32 Frame Buffer Write Address Control**

**Register Name Bit Name Initial Value Description** SC_SCL1_WR10 SC_RES_FLM_OFF_B 524288 Frame Buffer Frame Offset Address for Bottom [22:0] Sets the frame offset address for calculating the start address of each frame for the bottom field when SC_RES_TB_ADD_MOD = 1. Buffer 0: SC_RES_BASE_B Buffer 1: SC_RES_BASE_B + SC_RES_FLM_OFF_B × 1 : Buffer n: SC_RES_BASE_B + SC_RES_FLM_OFF_B × n For 32-byte transfer: The lower five bits should be fixed to 0_0000. For 128-byte transfer: The lower seven bits should be fixed to 000_0000.

**==> picture [440 x 212] intentionally omitted <==**

**----- Start of picture text -----**<br>
SC_RES_BASE<br>Start address<br>Input<br>Hsync<br>signal SC_RES_OUT_HW<br>Number of pixels in horizontal<br>direction<br>SC_RES_HS SC_RES_HW<br>SC_RES_<br>VS + 1<br>Image area to be captured<br>SC_RES_OUT_VW<br>After 100% scale-up/down or SC_RES_LN_OFF for 90° or 270°<br>scale-down processing is Line offset rotation<br>SC_RES_ performed, data is written to<br>VW the frame buffer.<br>SC_RES_OUT_HW SC_RES_OUT_HW<br>for 90° or 270°<br>Number of pixels in horizontal direction rotation<br>InputVsyncsignal<br>SC_RES_OUT_VW Number of lines in vertical direction<br>Frame offset<br>SC_RES_FLM_OFF<br>Number of lines  in vertical direction<br>SC_RES_OUT_VW<br>**----- End of picture text -----**<br>

**Figure 31.14 Data Arrangement in Frame Buffer**

**==> picture [316 x 229] intentionally omitted <==**

**----- Start of picture text -----**<br>
Write start address<br>Normal Horizontal mirroring<br>90° rotation 180° rotation 270° rotation<br>**----- End of picture text -----**<br>

**Figure 31.15 Data Arrangement in Frame Buffer in Various Writing Modes**

## (5) Frame Buffer Management

The scaling control block can handle multiple frames as the frame buffer.

Data is written to the buffer in cyclic mode according to the number of frames specified by the SC_RES_FLM_NUM bits.

For rotation, the SC_RES_FLM_NUM bits should be set to two or more frames.

To use the frame buffer as the ring buffer in line mode, the SC_RES_FLM_NUM bits should be set to 0 (1 frame) and the SC_RES_LOOP bit to 1.

**Table 31.33 Frame Buffer Write Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_WR3|SC_RES_FLM_|1|Number of Frames of Buffer to be Written to|
||NUM[9:0]||Sets the number of frames for the top field when|
||||SC_RES_TB_ADD_MOD = 1 or that for the top and bottom|
||||fields when SC_RES_TB_ADD_MOD = 0|
||||Number of frames defined by SC_RES_FLM_NUM+ 1 are|
||||used.|
|SC_SCL1_WR9|SC_RES_FLM_|1|Number of Frames of Buffer to be Written to for Bottom Field|
||NUM_B[9:0]||when SC_RES_TB_ADD_MOD = 1|
||||Number of frames defined by SC_RES_FLM_NUM_B + 1 are|
||||used.|
|SC_SCL1_WR1|SC_RES_LOOP|0|Frame Buffer Write Mode Select|
||||0: Frame mode|
||||1: Line mode (read as ring buffer)|
|SC_SCL1_WR7|SC_RES_FLM_|—|Frame Number of Frame Being Accessed|
||CNT[9:0]||Frame number of the frame being accessed in the top field|
||||when SC_RES_TB_ADD_MOD = 1 or that in the top or bottom|
||||field when SC_RES_TB_ADD_MOD = 0.|
|SC_SCL1_WR11|SC_RES_FLM_|—|Frame Number of Frame Being Accessed in Bottom Field|
||CNT_B[9:0]||Frame number of the frame being accessed in the bottom field|
||||when SC_RES_TB_ADD_MOD = 1.|

## (6) Buffer Overflow Handling

If writing to the frame buffer cannot be completed due to bus-traffic related problems, an overflow interrupt can be output to the interrupt controller.

## **Table 31.34 Buffer Overflow Detection**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_WR7|SC_RES_OVERFLOW|—|Line Buffer Overflow Detect|
||||1: Line buffer has overflowed.|
||||0: Line buffer has not overflowed.|

## (7) Frame Buffer Write End Flag

When writing one frame of data to the frame buffer is completed, a frame buffer write end interrupt can be output to the interrupt controller.

## 31.1.18 Selecting a Scaling-up Process or Graphics 0 Process

Scaling-up process and graphics 0 process are mutually exclusive and thus frame buffer cannot be read out simultaneously for the processes.

When displaying input video image signals or displaying enlarged graphics, data is read from the frame buffer via the scaling-up control block.

However, graphics can be enlarged and displayed by the scaling-up control block only when the RGB565, RGB888, YCbCr422, or YCbCr444 format is used.

When displaying graphics without enlargement, the data is read from the frame buffer via the graphics 0 processing block.

With the SC_RES_IBUS_SYNC_SEL bit, sync signals for reading out the frame buffer and read size setting bits are selected.

## **Table 31.35 Selection of Scaling-Up Process and Graphics 0 Process**

|**Type of Output Scaling**|**SC_RES_**|**Sync Signals for**|**Frame Buffer Read Size**||
|---|---|---|---|---|
|**Display**|**IBUS_SYNC_SEL**|**Frame Buffer Read**|**Setting Bits**|**Display Enabling Bits**|
|Input video signal display|0|Output from scaling-up|SC_RES_IN_VW|SC_RES_P_VS|
|Enlarged graphics display||control block|SC_RES_IN_HW|SC_RES_P_VW|
|||||SC_RES_P_HS|
|||||SC_RES_P_HW|
|Graphics display|1|Output from graphics 0|GR_FLM_LNUM*|GR_GRC_VS|
|||processing block|GR_HW*|GR_GRC_VW|
|||||GR_GRC_HS|
|||||GR_GRC_HW|

Note: * The value set to the register + 1 is the actual read size.

**==> picture [447 x 212] intentionally omitted <==**

**----- Start of picture text -----**<br>
GR_BASE<br>Start address<br>Output<br>Hsync<br>SC_RES_IN_HW signal<br>Number of pixels in horizontal direction<br>SC_RES_F_HS SC_RES_F_HW<br>Output full-image area<br>Output image area<br>GR_LN_OFF Read from the frame<br>Line offset buffer and scaled up<br>SC_RES_IN_HW SC_RES_P_HS SC_RES_P_HW<br>Number of pixels in horizontal direction<br>SC_RES_IN_VW Number of lines in vertical direction OutputVsyncsignal F_VS P_VS<br>SC_RES_ SC_RES_<br>GR_FLM_OFF Frame offset<br>SC_RES_F_VW SC_RES_P_VW<br>SC_RES_IN_VW Number of lines in vertical direction<br>**----- End of picture text -----**<br>

**Figure 31.16 Area Setting for Input Video Image Signal Display and Enlarged Graphics Display**

**==> picture [447 x 211] intentionally omitted <==**

**----- Start of picture text -----**<br>
GR_BASE<br>Start address<br>Output<br>Hsync<br>GR_HW+1 signal<br>Number of pixels in horizontal direction<br>SC_RES_<br>F_HS SC_RES_F_HW<br>Output full-image area<br>Output image area<br>GR_LN_OFF<br>Line offset Read from the frame buffer<br>GR_HW+1 GR_GRC_HS GR_GRC_HW<br>Number of pixels in horizontal direction<br>OutputVsyncsignal<br>GR_FLM_LNUM+1 Number of lines in vertical direction F_VS VS<br>SC_RES_ GR_GRC_<br>GR_FLM_OFF Frame offset<br>SC_RES_F_VW GR_GRC_VW<br>GR_FLM_LNUM+1 Number of lines in vertical direction<br>**----- End of picture text -----**<br>

**Figure 31.17 Area Setting for Graphics Display**

**Table 31.36 Scaling-Up Process or Graphics 0 Process Selection**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL0_US8|SC_RES_IBUS_SYNC_SEL|0|Sync Signal Select for Frame Buffer Read Block|
||||0: Sync signals from the scaling-up control block|
||||1: Sync signals from the graphics processing|
||||block|

The GR_DISP_SEL bits are used to select a display by the scaling-up control block (video image display or enlarged graphics display) or graphics display.

For details on the graphics processing, refer to the section 33., Video Display Controller 5 (5): Image Synthesizer .

## 31.1.19 Selecting Field for Frame Buffer Reading

For the next frame buffer to be read, the top or bottom field can be selected. This field selection is used in the scaling-up control block.

## **Table 31.37 Field Specification for Frame Buffer Reading**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM1|GR_FLD_SEL|0|Enables or disables top or bottom field selection for the next|
||||frame buffer to be read.|
||||0: Field selection is disabled.|
||||1: Top or bottom field can be selected.|
|GR_FLM3|GR_FLD_NXT|0|Selects the top or bottom field for the next frame buffer.|
||||0: Bottom|
||||1: Top|

## 31.1.20 Pointer Buffer and Frame Buffer Reading Processing

## (1) Pointer Buffers

The pointer buffers can be used to control the frame buffer for the input video image. They are mainly used to prevent flicker in the output video image, which occurs when the input and output vertical sync signals are asynchronous.

Four pointer buffers are provided and each pointer buffer has a start address register that shows the start location of the frame buffer and a field information register that shows the current field is the top or bottom field. The four pointer buffers are arranged in a ring structure and a write pointer is provided to indicate the pointer buffer corresponding to the location currently being written to. The location pointed to by the write pointer is being written to, and the corresponding pointer buffer value is undetermined. The value in the pointer buffer corresponding to the location being written to and the value in the write pointer are automatically updated when frame data writing is completed.

When the frame buffer address setting signal is linked with the pointer buffer (GR_FLM_SEL = 3), frame buffer reading can be controlled by using the read pointer that indicates the pointer buffer corresponding to the location being read; the start address and field information of the next frame buffer to be read should be read from the pointer buffer and they should be set in the frame buffer base address and field information. The read pointer value is automatically updated at the rising edge of the vertical sync signal on the reading side.

## (2) Write Pointer Control

The write pointer is incremented by one every time frame data writing is completed.

## (3) Read Pointer Control

The read pointer is updated at the rising edge of the vertical sync signal on the reading side according to the difference between the read and write pointer values as follows.

- (A) When (write pointer value) – (read pointer value) ≤ 1

The read pointer value is not updated (the same frame is displayed continuously).

- (B) When (write pointer value) – (read pointer value) = 2

The read pointer is incremented by one with the next updating timing.

- (C) When (write pointer value) – (read pointer value) ≥ 3

The read pointer is incremented by two with the next updating timing.

(One frame is skipped.)

## (4) Frame Buffer Read Control

- (A) When SC_RES_WENB = 0

Frame data is not written to the frame buffer, and the frame buffer is not read.

- (B) When frame data writing is terminated with SC_RES_WENB = 1

As the pointer buffer value is determined, the frame buffer is read.

**Table 31.38 Frame Buffer Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|SC_SCL1_PBUF0|SC_BUF0_ADD|0|Start address of the write buffer pointed to by pointer buffer 0|
|SC_SCL1_PBUF1|SC_BUF1_ADD|0|Start address of the write buffer pointed to by pointer buffer 1|
|SC_SCL1_PBUF2|SC_BUF2_ADD|0|Start address of the write buffer pointed to by pointer buffer 2|
|SC_SCL1_PBUF3|SC_BUF3_ADD|0|Start address of the write buffer pointed to by pointer buffer 3|
|SC_SCL1_PBUF_FLD|SC_FLD_INF0|0|Top or bottom field information pointed to by pointer buffer 0|
||||0: Bottom|
||||1: Top|
|SC_SCL1_PBUF_FLD|SC_FLD_INF1|0|Top or bottom field information pointed to by pointer buffer 1|
||||0: Bottom|
||||1: Top|
|SC_SCL1_PBUF_FLD|SC_FLD_INF2|0|Top or bottom field information pointed to by pointer buffer 2|
||||0: Bottom|
||||1: Top|
|SC_SCL1_PBUF_FLD|SC_FLD_INF3|0|Top or bottom field information pointed to by pointer buffer 3|
||||0: Bottom|
||||1: Top|
|SC_SCL1_PBUF_CNT|SC_PBUF_RST|0|Reset Control for the Pointer Buffer|
||||0: Pointer buffer is not reset.|
||||1: Pointer buffer is reset.|
|SC_SCL1_MON1|SC_PBUF_NUM|0|Write pointer indicating the pointer buffer number|
||||corresponding to the location currently being written to.|
|SC_SCL1_WR5|SC_RES_WENB|0|Frame Buffer Write Enable|
||||After making the setting to enable writing, writing starts from|
||||the second frame.|
||||0: Writing is disabled.|
||||1: Writing is enabled.|
|GR_FLM1|GR_FLM_SEL|0|Frame Buffer Address Setting Signal Selection|
||||0: Links to scaling-down process. (This setting is prohibited|
||||when separate write addresses are specified for the top|
||||and bottom fields; that is, SC_RES_TB_ADD_MOD = 1 in|
||||SC_SCL1_WR1.)|
||||1: Selects GR0_FLM_NUM.|
||||2: Setting prohibited|
||||3: Links to pointer buffer.|
|GR_FLM2|GR_BASE|0|Frame Buffer Base Address|
||||Sets the start address of the frame buffer where frame data is|
||||to be stored.|
||||GR_BASE[4:3] and GR_BASE[6:3] are referred to during 32-|
||||byte burst transfer and 128-byte burst transfer, respectively, to|
||||skip the start line data.|
||||The lower three bits should be fixed to 000.|

For other frame buffer read operation and graphics processing, refer to section 33., Video Display Controller 5 (5): Image Synthesizer .

## 31.2 Register Descriptions

Table 31.39 shows the register configuration.

- Symbols used in Register Description:

Initial value: Register value after a reset

—: Undefined value R/W: Readable/writable. The written value can be read. R/WC0: Readable/writable. Writing 0 initializes the bit. Writing 1 is ignored. R/WC1: Readable/writable. Writing 1 initializes the bit. Writing 0 is ignored. R: Read-only. The write value should always be 0. —/W: Write-only. The read value is undefined.

**Table 31.39 Register Configuration of the Scaler**

||||||**Access**|
|---|---|---|---|---|---|
|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|SCL0 register update control register|SC0_SCL0_UPDATE|R/WC1|H'0000 0000|H'FCFF 7500|32|
|(SC0)||||||
|Mask control register (SC0)|SC0_SCL0_FRC1|R/W|H'0AF0 0001|H'FCFF 7504|32|
|Missing Vsync compensation control|SC0_SCL0_FRC2|R/W|H'0E10 0001|H'FCFF 7508|32|
|register (SC0)||||||
|Output sync select register (SC0)|SC0_SCL0_FRC3|R/W|H'0000 0001|H'FCFF 750C|32|
|Free-running period control register|SC0_SCL0_FRC4|R/W|H'020C 031F|H'FCFF 7510|32|
|(SC0)||||||
|Output delay control register (SC0)|SC0_SCL0_FRC5|R/W|H'0000 0101|H'FCFF 7514|32|
|Full-screen vertical size register (SC0)|SC0_SCL0_FRC6|R/W|H'0023 01E0|H'FCFF 7518|32|
|Full-screen horizontal size register|SC0_SCL0_FRC7|R/W|H'0090 0280|H'FCFF 751C|32|
|(SC0)||||||
|Vsync detection register (SC0)|SC0_SCL0_FRC9|R|H'0000 0000|H'FCFF 7524|32|
|Status monitor 0 register (SC0)|SC0_SCL0_MON0|R|H'0000|H'FCFF 7528|16|
|Interrupt control register (SC0)|SC0_SCL0_INT|R/W|H'0000|H'FCFF 752A|16|
|Scaling-down control register (SC0)|SC0_SCL0_DS1|R/W|H'0000 0011|H'FCFF 752C|32|
|Vertical capture size register (SC0)|SC0_SCL0_DS2|R/W|H'0012 00F0|H'FCFF 7530|32|
|Horizontal capture size register (SC0)|SC0_SCL0_DS3|R/W|H'00F4 05A0|H'FCFF 7534|32|
|Horizontal scale down register (SC0)|SC0_SCL0_DS4|R/W|H'1000 2408|H'FCFF 7538|32|
|Initial vertical phase register (SC0)|SC0_SCL0_DS5|R/W|H'1800 0000|H'FCFF 753C|32|
|Vertical scaling register (SC0)|SC0_SCL0_DS6|R/W|H'0000 07FC|H'FCFF 7540|32|
|Scaling-down control block output size|SC0_SCL0_DS7|R/W|H'00F0 0280|H'FCFF 7544|32|
|register (SC0)||||||
|Scaling-up control register (SC0)|SC0_SCL0_US1|R/W|H'0000 0011|H'FCFF 7548|32|
|Output image vertical size register|SC0_SCL0_US2|R/W|H'0023 01E0|H'FCFF 754C|32|
|(SC0)||||||
|Output image horizontal size register|SC0_SCL0_US3|R/W|H'0090 0280|H'FCFF 7550|32|
|(SC0)||||||
|Scaling-up control block input size|SC0_SCL0_US4|R/W|H'00F0 0280|H'FCFF 7554|32|
|register (SC0)||||||
|Horizontal scale up register (SC0)|SC0_SCL0_US5|R/W|H'0000 2408|H'FCFF 7558|32|
|Horizontal scale up initial phase register|SC0_SCL0_US6|R/W|H'1000 0000|H'FCFF 755C|32|
|(SC0)||||||
|Trimming register (SC0)|SC0_SCL0_US7|R/W|H'0000 0000|H'FCFF 7560|32|
|Frame buffer read select register (SC0)|SC0_SCL0_US8|R/W|H'0000 0000|H'FCFF 7564|32|
|Background color register (SC0)|SC0_SCL0_OVR1|R/W|H'0080 0080|H'FCFF 756C|32|

**Table 31.39 Register Configuration of the Scaler**

||||||**Access**|
|---|---|---|---|---|---|
|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|SCL1 register update control register|SC0_SCL1_UPDATE|R/WC1|H'0000 0000|H'FCFF 7580|32|
|(SC0)||||||
|Writing mode register (SC0)|SC0_SCL1_WR1|R/W|H'0000 0000|H'FCFF 7588|32|
|Write address register 1T (SC0)|SC0_SCL1_WR2|R/W|H'0000 0000|H'FCFF 758C|32|
|Write address register 2T (SC0)|SC0_SCL1_WR3|R/W|H'0800 0001|H'FCFF 7590|32|
|Write address register 3T (SC0)|SC0_SCL1_WR4|R/W|H'0008 0000|H'FCFF 7594|32|
|Frame sub-sampling register (SC0)|SC0_SCL1_WR5|R/W|H'0000 1000|H'FCFF 759C|32|
|Bit reduction register (SC0)|SC0_SCL1_WR6|R/W|H'0000 0000|H'FCFF 75A0|32|
|Write detection register (SC0)|SC0_SCL1_WR7|R|H'0000 0000|H'FCFF 75A4|32|
|Write address register 1B (SC0)|SC0_SCL1_WR8|R/W|H'0000 0000|H'FCFF 75A8|32|
|Write address register 2B (SC0)|SC0_SCL1_WR9|R/W|H'0800 0001|H'FCFF 75AC|32|
|Write address register 3B (SC0)|SC0_SCL1_WR10|R/W|H'0008 0000|H'FCFF 75B0|32|
|Write detection register B (SC0)|SC0_SCL1_WR11|R|H'0000 0000|H'FCFF 75B4|32|
|Status monitor 1 register (SC0)|SC0_SCL1_MON1|R|H'0000 0000|H'FCFF 75B8|32|
|Pointer buffer 0 register (SC0)|SC0_SCL1_PBUF0|R|H'0000 0000|H'FCFF 75BC|32|
|Pointer buffer 1 register (SC0)|SC0_SCL1_PBUF1|R|H'0000 0000|H'FCFF 75C0|32|
|Pointer buffer 2 register (SC0)|SC0_SCL1_PBUF2|R|H'0000 0000|H'FCFF 75C4|32|
|Pointer buffer 3 register (SC0)|SC0_SCL1_PBUF3|R|H'0000 0000|H'FCFF 75C8|32|
|Pointer buffer and field information|SC0_SCL1_PBUF_FLD|R|H'0000 0000|H'FCFF 75CC|32|
|register (SC0)||||||
|Pointer buffer control register (SC0)|SC0_SCL1_PBUF_CNT|R/W|H'0000 0000|H'FCFF 75D0|32|
|Graphics 0 register update control|GR0_UPDATE|R/WC1|H'0000 0000|H'FCFF 7600|32|
|register||||||
|Frame buffer read control register|GR0_FLM_RD|R/W|H'0000 0000|H'FCFF 7604|32|
|(graphics 0)||||||
|Frame buffer control register 1|GR0_FLM1|R/W|H'0000 0000|H'FCFF 7608|32|
|(graphics 0)||||||
|Frame buffer control register 2|GR0_FLM2|R/W|H'0000 0000|H'FCFF 760C|32|
|(graphics 0)||||||
|Frame buffer control register 3|GR0_FLM3|R/W|H'0800 0001|H'FCFF 7610|32|
|(graphics 0)||||||
|Frame buffer control register 4|GR0_FLM4|R/W|H'0008 0000|H'FCFF 7614|32|
|(graphics 0)||||||
|Frame buffer control register 5|GR0_FLM5|R/W|H'0000 03FF|H'FCFF 7618|32|
|(graphics 0)||||||
|Frame buffer control register 6|GR0_FLM6|R/W|H'8000 0000|H'FCFF 761C|32|
|(graphics 0)||||||
|Alpha blending control register 1|GR0_AB1|R/W|H'0000 0000|H'FCFF 7620|32|
|(graphics 0)||||||
|Alpha blending control register 2|GR0_AB2|R/W|H'0000 0000|H'FCFF 7624|32|
|(graphics 0)||||||
|Alpha blending control register 3|GR0_AB3|R/W|H'0000 0000|H'FCFF 7628|32|
|(graphics 0)||||||
|Alpha blending control register 7|GR0_AB7|R/W|H'00FF 0000|H'FCFF 7638|32|
|(graphics 0)||||||
|Alpha blending control register 8|GR0_AB8|R/W|H'0000 0000|H'FCFF 763C|32|
|(graphics 0)||||||
|Alpha blending control register 9|GR0_AB9|R/W|H'0000 0000|H'FCFF 7640|32|
|(graphics 0)||||||

**Table 31.39 Register Configuration of the Scaler**

||||||**Access**|
|---|---|---|---|---|---|
|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Alpha blending control register 10|GR0_AB10|R/W|H'0000 0000|H'FCFF 7644|32|
|(graphics 0)||||||
|Alpha blending control register 11|GR0_AB11|R/W|H'0000 0000|H'FCFF 7648|32|
|(graphics 0)||||||
|Background color control register|GR0_BASE|R/W|H'0000 8080|H'FCFF 764C|32|
|(graphics 0)||||||
|CLUT table control register (graphics 0)|GR0_CLUT|R/W|H'0000 0000|H'FCFF 7650|32|

## 31.2.1 SCL0 Register Update Control Register (SC0_SCL0_UPDATE)

|Bit:|31|30||29|28||27|26|25|24||23|22|21|20||19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—||—|—||—|—|—|—||—|—|—|—||—|—|—||—||
|Initial value:|0|0||0|0||0|0|0|0||0|0|0|0||0|0|0||0||
|R/W:|R|R||R|R||R|R|R|R||R|R|R|R||R|R|R||R||
|Bit:|15|14||13|12||11|10|9|8||7|6|5|4||3|2|1||0||
||—|—||SC0_<br>SCL0_<br>VEN_D|SC0_<br>SCL0_<br>VEN_C||—|—|—|SC0_<br>SCL0_<br>UPDATE||—|—|—|SC0_<br>SCL0_<br>VEN_B||—|—|—||SC0_<br>SCL0_<br>VEN_A||
|Initial value:|0|0||0|0||0|0|0|0||0|0|0|0||0|0|0||0||
|R/W:|R|R<br>R/WC1|||R/WC1||R|R|R|R/WC1||R|R|R|R/WC1||R|R|R|R/WC1|||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 14|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|13|SC0_SCL0_|0|R/WC1|Scaling-Up Control and Frame Buffer Read Control Register Update|
||VEN_D|||0: Registers are not updated.|
|||||1: Registers are updated at the rising edge of the Vsync.|
|12|SC0_SCL0_|0|R/WC1|Scaling-Down Control and Frame Buffer Read Control Register Update|
||VEN_C|||0: Registers are not updated.|
|||||1: Registers are updated at the rising edge of the Vsync.|
|11 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|SC0_SCL0_|0|R/WC1|SYNC Control Register Update|
||UPDATE|||0: Registers are not updated.|
|||||1: Registers are updated.|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|SC0_SCL0_|0|R/WC1|Synchronization Control and Scaling-up Control Register Update|
||VEN_B|||0: Registers are not updated.|
|||||1: Registers are updated at the rising edge of the Vsync.|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|SC0_SCL0_|0|R/WC1|Scaling-Down Control Register Update|
||VEN_A|||0: Registers are not updated.|
|||||1: Registers are updated at the rising edge of the Vsync.|

## 31.2.2 Mask Control Register (SC0_SCL0_FRC1)

||Bit:|31|30|29||28|27|26||25<br>24<br>23|22<br>21||20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||SC0_RES_VMASK[15:0]||||||||
|Initial|value:|0|0|0||0|1|0||1<br>0<br>1|1<br>1||1<br>0|0|0|0||
||R/W:|R/W|R/W|R/W||R/W|R/W|R/W||R/W<br>R/W<br>R/W<br>R/W<br>R/W|||R/W<br>R/W|R/W|R/W|R/W||
||Bit:|15|14|13||12|11|10||9<br>8<br>7|6<br>5||4<br>3|2|1|0||
|||||||||||||||||SC0_RES_||
|||—|—|—||—|—|—||—<br>—<br>—|—<br>—||—<br>—|—|—|VMASK_||
|||||||||||||||||ON||
|Initial|value:|0|0|0||0|0|0||0<br>0<br>0|0<br>0||0<br>0|0|0|1||
||R/W:|R|R|R||R|R|R||R<br>R<br>R|R<br>R||R<br>R|R|R|R/W||
|**Bit**|**Bit Name**||||**Initial Value**|||**R/W**||**Description**||||||||
|31 to 16|SC0_RES_VMASK||||2800|||R/W||Repeated Vsync|Signal Masking Period|||||||
||[15:0]|||||||||Sets the repeated Vsync signal masking period beginning at a Vsync||||||||
|||||||||||signal in terms of|128 pixel-clock periods.|||||||
|||||||||||Masking period [usec] = SC0_RES_VMASK × 128 ÷ pixel clock||||||||
|||||||||||frequency [MHz]||||||||
|15 to 1|—||||All 0|||R||Reserved||||||||
|||||||||||These bits are always read as|||0. The write value should always be||||0.|
|0|SC0_RES_||||1|||R/W||Repeated Vsync|Signal Masking Control|||||||
||VMASK_ON|||||||||0: Repeated Vsync signal masking control is disabled.||||||||
|||||||||||1: Repeated Vsync signal masking control is enabled.||||||||

Note: This register is updated when the SC0_SCL0_UPDATE bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.3 Missing Vsync Compensation Control Register (SC0_SCL0_FRC2)

||Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||SC0_RES_VLACK[15:0]|||||||||
||Initial value:|0|0|0|0||1|1|1<br>0<br>0<br>0|0|1|0|0|0||0||
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||R/W||
||Bit:|15|14|13|12||11|10|9<br>8<br>7<br>6|5|4|3|2|1||0||
||||||||||||||||SC0_RES_|||
|||—|—|—|—||—|—|—<br>—<br>—<br>—|—|—|—|—|—||VLACK_||
|||||||||||||||||ON||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0||1||
||R/W:|R|R|R|R||R|R|R<br>R<br>R<br>R|R|R|R|R|R||R/W||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**|||||||||
|31|to 16|SC0_RES_||3600|||R/W||Missing-Sync Compensating Pulse Output Wait Time|||||||||
|||VLACK|||||||Sets the wait time before|outputting a missing-sync compensating pulse||||||||
|||[15:0]|||||||after a Vsync signal.|||||||||
||||||||||Wait time [usec] = SC0_RES_VLACK ×|||128 ÷ pixel clock frequency||||||
||||||||||[MHz]|||||||||
|15|to 1|—||All|0||R||Reserved|||||||||
||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|0||SC0_RES_||1|||R/W||Missing Vsync Signal Compensation|||||||||
|||VLACK_ON|||||||0: Compensation of missing Vsync signals is disabled.|||||||||
||||||||||1: Compensation of missing Vsync signals is enabled.|||||||||

Note: This register is updated when the SC0_SCL0_UPDATE bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.4 Output Sync Select Register (SC0_SCL0_FRC3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||||||SC0_||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|RES_||
|||||||||||||||||VS_SEL||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||SC0_RES_|1|R/W|Vsync Signal Output Select|
||||VS_SEL|||0: Externally input Vsync signal|
|||||||1: Internally generated free-running Vsync signal|

Note: This register is updated when the SC0_SCL0_UPDATE bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.5 Free-Running Period Control Register (SC0_SCL0_FRC4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||SC0_RES_FV[10:0]|||||||
|Initial value:|0|0|0|0|0|0|1|0|0|0|0|0|1|1|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||SC0_RES_FH[10:0]|||||||
|Initial value:|0|0|0|0|0|0|1|1|0|0|0|1|1|1|1|1|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|SC0_RES_FV|524|R/W|Free-Running Vsync Period Setting|
||||[10:0]|||Free-running Vsync period = (SC0_RES_FV + 1) × horizontal period [usec]|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|SC0_RES_FH|799|R/W|Hsync Period Setting|
||||[10:0]|||Hsync period [usec] = (SC0_RES_FH +1) ÷ pixel clock frequency [MHz]|

Note: This register is updated when the SC0_SCL0_UPDATE bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.6 Output Delay Control Register (SC0_SCL0_FRC5)

|Bit:|31|30|29|28|27|26|25|24||23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—||—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0||0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R||R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8||7|6|5|4|3|2|1|0||
||—|—|—|—|—|—|—|SC0_RES_<br>FLD_<br>DLY_SEL||||SC0_RES_VSDLY[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|1||0|0|0|0|0|0|0|1||
|R/W:|R|R|R|R|R|R|R|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|SC0_RES_|1|R/W|Field Determination Signal Delay Control|
||FLD_DLY_SEL|||0: No delay|
|||||1: Delay of one vertical cycle|
|7 to 0|SC0_RES_|1|R/W|Vsync Signal Delay Control|
||VSDLY[7:0]|||Adjusts the Vsync signal delay in the output Hsync period units.|
|||||Vsync signal delay [usec]: SC0_RES_VSDLY × output Hsync period [usec]|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.7 Full-Screen Vertical Size Register (SC0_SCL0_FRC6)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||SC0_RES_F_VS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|1|0|0|0|1|1|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||SC0_RES_F_VW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|1|1|1|1|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|SC0_RES_F_|35|R/W|Vertical Enable Signal Start Position for Full Screen.|
||||VS[10:0]|||(VSYNC + V backporch lines)|
|||||||Note: The set value should be four or more (lines). SC0_RES_F_VS +|
|||||||SC0_RES_F_VW should be equal to or less than 2039 (lines).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|SC0_RES_F_|480|R/W|Vertical Enable Signal Width for Full Screen (lines)|
||||VW[10:0]|||Note: SC0_RES_F_VS + SC0_RES_F_VW should be equal to or less|
|||||||than 2039 (lines).|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.8 Full-Screen Horizontal Size Register (SC0_SCL0_FRC7)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||SC0_RES_F_HS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|1|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||SC0_RES_F_HW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 27|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|26 to 16|SC0_RES_F_|144|R/W|Horizontal Enable Signal Start Position for Full Screen.|
||HS[10:0]|||(HSYNC+H backporch pixel-clock cycles)|
|||||Note: The set value should be 16 or more (clock cycles).|
|||||SC0_RES_F_HS + SC0_RES_F_HW should be equal to or less|
|||||than 2015 (clock cycles).|
|15 to 11|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|10 to 0|SC0_RES_F_|640|R/W|Horizontal Enable Signal Width for Full Screen (pixel-clock cycles)|
||HW[10:0]|||Note 1. SC0_RES_F_HS + SC0_RES_F_HW should be equal to or less|
|||||than 2015 (clock cycles).|
|||||Note 2. The set value should be equal to (horizontal signal width for full|
|||||screen + 2) when serial RGB output is selected as an LCD output|
|||||signal.|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.9 Vsync Detection Register (SC0_SCL0_FRC9)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||SC0_||||SC0_||
||—|—|—|—|—|—|—|—|—|—|—|RES_|—|—|—|RES_||
|||||||||||||QVLOCK||||QVLACK||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|SC0_RES_|0|R|Locked Vsync Signal Detection Flag|
||QVLOCK|||1: No repeated or missing Vsync signal input has been detected for four|
|||||or more vertical periods.|
|||||0: Repeated or missing Vsync signal input has been detected.|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|SC0_RES_|0|R|Missing Vsync Signal Detection Flag|
||QVLACK|||1: Missing Vsync signal input has been detected.|
|||||0: No missing Vsync signal input has been detected.|

## 31.2.10 Status Monitor 0 Register (SC0_SCL0_MON0)

|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||SC0_RES_LIN_STAT[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|SC0_RES_|All 0|R|Current location of the image line input to the scaling-down control|
||||LIN_STAT|||block.|
||||[10:0]||||

## 31.2.11 Interrupt Control Register (SC0_SCL0_INT)

|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||SC0_RES_LINE[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|SC0_RES_|All 0|R/W|Setting of Interrupt on Image Line Input to Scaling-down Control Block|
||||LINE[10:0]|||When the location of the image line input to the scaling-down control|
|||||||block matches the SC0_RES_LINE setting, an interrupt signal is output.|
|||||||(Setting prohibited in this product)|

Note: This register is updated when the SC0_SCL0_VEN_A bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.12 Scaling-Down Control Register (SC0_SCL0_DS1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||SC0_RES||||SC0_RES||
||—|—|—|—|—|—|—|—|—|—|—|_DS_V_|—|—|—|_DS_H_||
|||||||||||||ON||||ON||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0|1||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|SC0_RES_DS_|1|R/W|Vertical Scale Down On/Off|
||V_ON|||0: Off|
|||||1: On|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|SC0_RES_DS_|1|R/W|Horizontal Scale Down On/Off|
||H_ON|||0: Off|
|||||1: On|

Note: This register is updated when the SC0_SCL0_VEN_A bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.13 Vertical Capture Size Register (SC0_SCL0_DS2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||SC0_RES_VS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|1|0|0|1|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||SC0_RES_VW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|1|1|1|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|SC0_RES_VS|18|R/W|Vertical Position Setting for Video Signal Capturing|
||||[10:0]|||(VSYNC + (V backporch - 1) lines)|
|||||||Note: The set value should be four or more (lines). SC0_RES_VS +|
|||||||SC0_RES_VW should be equal to or less than 2039 (lines).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|SC0_RES_VW|240|R/W|Vertical Width of Video Signal to be Captured|
||||[10:0]|||(Lines)|
|||||||Note: SC0_RES_VS + SC0_RES_VW should be equal to or less than|
|||||||2039 (lines).|

Note: This register is updated when the SC0_SCL0_VEN_A bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.14 Horizontal Capture Size Register (SC0_SCL0_DS3)

||Bit:|31|30||29|28||27||26|25<br>24<br>23<br>22|21<br>20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—||—|—||—|||SC0_RES_HS[10:0]||||||
||Initial value:|0|0||0|0||0||0|0<br>0<br>1<br>1|1<br>1<br>0|1|0|0||
||R/W:|R|R||R|R||R||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W||
||Bit:|15|14||13|12||11||10|9<br>8<br>7<br>6|5<br>4<br>3|2|1|0||
|||—|—||—|—||—|||SC0_RES_HW[10:0]||||||
||Initial value:|0|0||0|0||0||1|0<br>1<br>1<br>0|1<br>0<br>0|0|0|0||
||R/W:|R|R||R|R||R||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**|||**Initial Value**||||**R/W**||**Description**||||||
|31|to 27|—|||All|0|||R||Reserved||||||
||||||||||||These bits are always read|as 0. The write value|should|always be 0.|||
|26|to 16|SC0_RES_HS|||244||||R/W||Horizontal Position Setting|for Video Signal Capturing|||||
|||[10:0]|||||||||(HSYNC + H backporch video-image clock cycles)||||||
||||||||||||Note: The set value should|be 16 or more (clock cycles). SC0_RES_HS|||||
||||||||||||+ SC0_RES_HW should be equal to or less than 2015||||(clock||
||||||||||||cycles).||||||
|15|to 11|—|||All|0|||R||Reserved||||||
||||||||||||These bits are always read|as 0. The write value|should|always be 0.|||
|10|to 0|SC0_RES_HW|||1440||||R/W||Horizontal Width of Video Signal to be Captured||||||
|||[10:0]|||||||||(Video-image clock cycles)||||||
||||||||||||Note: SC0_RES_HS + SC0_RES_HW should be equal to or||||less than||
||||||||||||2015 (clock cycles).||||||

Note: This register is updated when the SC0_SCL0_VEN_A bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.15 Horizontal Scale Down Register (SC0_SCL0_DS4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||SC0_RES_||||||||||||||
||||SC0_RES_|DS_H_||||||||||||||
||—|—|PFIL_SEL|INTERPO<br>TYP|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|1|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R/W|R/W|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||||||SC0_RES_DS_H_RATIO[15:0]|||||||||||
|Initial value:|0|0|1|0|0|1|0|0|0|0|0|0|1|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31, 30|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|29|SC0_RES_|0|R/W|Prefilter Mode Select for Brightness Signals|
||PFIL_SEL|||0: The prefilter is turned off.|
|||||1: The prefilter is turned on. (1/4 + 1/2 + 1/4)|
|28|SC0_RES_DS_H_|1|R/W|Horizontal Interpolation Mode Select|
||INTERPOTYP|||0: Hold interpolation|
|||||1: Linear interpolation|
|27 to 16|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|15 to 0|SC0_RES_DS_H_|9224|R/W|Horizontal Scale Down Ratio|
||RATIO[15:0]|||([15:12]: Integer part, [11:0]: Decimal part)|
|||||round(SC0_RES_HW ÷ SC0_RES_OUT_HW × 4096)|
|||||SC0_RES_DS_H_RATIO < 4096: Setting prohibited|
|||||SC0_RES_DS_H_RATIO = 4096: 100% scale up|
|||||SC0_RES_DS_H_RATIO > 4096: Scale down|

Note: This register is updated when the SC0_SCL0_VEN_A bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.16 Initial Vertical Phase Register (SC0_SCL0_DS5)

|Bit:|31|30|29||28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|SC0_RES_<br>V_INTER<br>POTYP||||||SC0_RES_TOP_INIPHASE[11:0]||||||||
|Initial value:|0|0|0||1|1|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13||12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—||—|||||SC0_RES_BTM_INIPHASE[11:0]||||||||
|Initial value:|0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R||R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 29|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|28|SC0_RES_V_|1|R/W|Vertical Interpolation Mode Select|
||INTERPOTYP|||0: Hold interpolation|
|||||1: Linear interpolation|
|27 to 16|SC0_RES_TOP_|2048|R/W|Vertical Interpolation Start Phase for Top Field|
||INIPHASE|||0 to 4095 (0 to approx. 1.0)|
||[11:0]||||
|15 to 12|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11 to 0|SC0_RES_BTM_|0|R/W|Vertical Interpolation Start Phase for Bottom Field|
||INIPHASE|||0 to 4095 (0 to approx. 1.0)|
||[11:0]||||

Note: This register is updated when the SC0_SCL0_VEN_A and SC0_SCL0_VEN_B bits in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) are 1.

## 31.2.17 Vertical Scaling Register (SC0_SCL0_DS6)

|Bit:|31|30|29|28|27|26|25|24|23|22||21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—||—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0||0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R||R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6||5|4|3|2|1|0||
||||||||SC0_RES_V_RATIO[15:0]||||||||||||
|Initial value:|0|0|0|0|0|1|1|1|1|1||1|1|1|1|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|16|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|15|to|0|SC0_RES_V_|2044|R/W|Vertical Scale Up/Down Ratio|
||||RATIO|||([15:12]: Integer part, [11:0]: Decimal part)|
||||[15:0]|||For scale down:|
|||||||round (SC0_RES_VW ÷ SC0_RES_OUT_VW × 4096)|
|||||||For scale up:|
|||||||round (SC0_RES_IN_VW ÷ SC0_RES_P_VW × 4096)|
|||||||SC0_RES_V_RATIO < 4096: Scale up|
|||||||SC0_RES_V_RATIO = 4096: 100% scale up|
|||||||SC0_RES_V_RATIO > 4096: Scale down|

Note: These bits updated when the SC0_SCL0_VEN_A and SC0_SCL0_VEN_B bits in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) are 1. Accordingly, even a scaled-up graphics display requires both an input Vsync signal and output Vsync signal.

## 31.2.18 Scaling-Down Control Block Output Size Register (SC0_SCL0_DS7)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—||||SC0_RES_OUT_VW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|1|1|1|1|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—||||SC0_RES_OUT_HW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|SC0_RES_|240|R/W|Number of Valid Lines in Vertical Direction Output by Scaling-down|
||||OUT_VW|||Control Block (lines)|
||||[10:0]|||This bit setting is used for the number of lines to be written to the frame|
|||||||buffer.|
|||||||When SC0_SCL1_WR1.SC0_RES_LOOP is 0 (frame write mode),|
|||||||specify the number of lines for one frame.|
|||||||When SC0_SCL1_WR1.SC0_RES_LOOP is 1 (line write mode),|
|||||||specify the number of lines for repeated write.|
|||||||Note: The SC0_RES_OUT_VW value should be aligned in 4-line units|
|||||||and equal to or smaller than the SC0_RES_VW value.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|SC0_RES_|640|R/W|Number of Valid Horizontal Pixels Output by Scaling-Down Control|
||||OUT_HW|||Block (video-image clock cycles)|
||||[10:0]|||Note: The SC0_RES_OUT_HW value should be aligned in 4-pixel units|
|||||||and equal to or smaller than the SC0_RES_HW value.|

Note: This register is updated when the SC0_SCL0_VEN_A and SC0_SCL0_VEN_C bits in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) are 1.

## 31.2.19 Scaling-Up Control Register (SC0_SCL0_US1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||SC0_||||SC0_||
||—|—|—|—|—|—|—|—|—|—|—|RES_US_|—|—|—|RES_US_||
|||||||||||||V_ON||||H_ON||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0|1||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|SC0_RES_US_|1|R/W|Vertical Scale Up On/Off|
||V_ON|||0: Off|
|||||1: On|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|SC0_RES_US_|1|R/W|Horizontal Scale Up On/Off|
||H_ON|||0: Off|
|||||1: On|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.20 Output Image Vertical Size Register (SC0_SCL0_US2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||SC0_RES_P_VS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|1|0|0|0|1|1|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||SC0_RES_P_VW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|1|1|1|1|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|SC0_RES_P_|35|R/W|Vertical Enable Signal Start Position for Output Image|
||||VS[10:0]|||(VSYNC + V backporch lines)|
|||||||Note: The set value should be four or more (lines). SC0_RES_P_VS +|
|||||||SC0_RES_P_VW should be equal to or less than 2039 (lines).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|SC0_RES_P_|480|R/W|Vertical Enable Signal Width for Output Image (lines)|
||||VW[10:0]|||Note: SC0_RES_P_VS + SC0_RES_P_VW should be equal to or less|
|||||||than 2039 (lines).|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.21 Output Image Horizontal Size Register (SC0_SCL0_US3)

||Bit:|31|30||29|28||27||26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—||—|—||—|||SC0_RES_P_HS[10:0]||||||
||Initial value:|0|0||0|0||0||0|0<br>0<br>1<br>0<br>0<br>1|0|0|0|0||
||R/W:|R|R||R|R||R||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W<br>R/W||R/W||
||Bit:|15|14||13|12||11||10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|||—|—||—|—||—|||SC0_RES_P_HW[10:0]||||||
||Initial value:|0|0||0|0||0||0|1<br>0<br>1<br>0<br>0<br>0|0|0|0|0||
||R/W:|R|R||R|R||R||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W<br>R/W||R/W||
|**Bit**||**Bit Name**|||**Initial Value**||||**R/W**||**Description**||||||
|31|to 27|—|||All|0|||R||Reserved||||||
||||||||||||These bits are always read as 0. The write value||should|always be 0.|||
|26|to 16|SC0_RES_P_|||144||||R/W||Horizontal Enable Signal Start Position for Output Image||||||
|||HS[10:0]|||||||||(HSYNC+H backporch pixel-clock cycles)||||||
||||||||||||Note: The set value should be 16 or more (clock||cycles).||||
||||||||||||SC0_RES_P_HS + SC0_RES_P_HW should be equal||||to or less||
||||||||||||than 2015 (clock cycles).||||||
|15|to 11|—|||All|0|||R||Reserved||||||
||||||||||||These bits are always read as 0. The write value||should always be 0.||||
|10|to 0|SC0_RES_P_|||640||||R/W||Horizontal Enable Signal Width for Output Image (pixel-clock||||cycles)||
|||HW[10:0]|||||||||Note: SC0_RES_P_HS + SC0_RES_P_HW should be equal||||to or less||
||||||||||||than 2015 (clock cycles).||||||

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.22 Scaling-Up Control Block Input Size Register (SC0_SCL0_US4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—||||SC0_RES_IN_VW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|1|1|1|1|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—||||SC0_RES_IN_HW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|1|0|1|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|SC0_RES_IN_|240|R/W|Number of Valid Lines in Vertical Direction Input to Scaling-up Control|
||||VW[10:0]|||Block (lines)|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|SC0_RES_IN_|640|R/W|Number of Valid Horizontal Pixels Input to Scaling-up Control Block|
||||HW[10:0]|||(pixel-clock cycles)|

Note: This register is updated when the SC0_SCL0_VEN_B and SC0_SCL0_VEN_D bits in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) are 1.

## 31.2.23 Horizontal Scale Up Register (SC0_SCL0_US5)

**==> picture [458 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>— — — — — — — — — — — — — — — —<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>SC0_RES_US_H_RATIO[15:0]<br>Initial value: 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0<br>R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W<br>**----- End of picture text -----**<br>

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|16|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|15|to|0|SC0_RES_US_|9224|R/W|Horizontal Scale Up Ratio|
||||H_RATIO|||([15:12]: Integer part, [11:0]: Decimal part)|
||||[15:0]|||round (SC0_RES_IN_HW ÷ SC0_RES_P_HW × 4096)|
|||||||SC0_RES_US_H_RATIO < 4096: Scale up|
|||||||SC0_RES_US_H_RATIO = 4096: 100% scale up|
|||||||SC0_RES_US_H_RATIO > 4096: Setting prohibited|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.24 Horizontal Scale Up Initial Phase Register (SC0_SCL0_US6)

|Bit:|31|30|29||28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|SC0_RES_<br>US_H_INT<br>ERPOTYP|||||SC0_RES_US_HT_INIPHASE[11:0]|||||||||
|Initial value:|0|0|0||1|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13||12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—||—||||SC0_RES_US_HB_INIPHASE[11:0]|||||||||
|Initial value:|0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R||R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 29|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|28|SC0_RES_US_H_|1|R/W|Horizontal Interpolation Mode Select|
||INTERPOTYP|||0: Hold interpolation|
|||||1: Linear interpolation|
|27 to 16|SC0_RES_US_HT_|0|R/W|Horizontal Interpolation Start Phase for Top Field|
||INIPHASE[11:0]|||0 to 4095 (0 to approx. 1.0)|
|15 to 12|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11 to 0|SC0_RES_US_HB_|0|R/W|Horizontal Interpolation Start Phase for Bottom Field|
||INIPHASE[11:0]|||0 to 4095 (0 to approx. 1.0)|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.25 Trimming Register (SC0_SCL0_US7)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||SC0_RES_HCUT[7:0]||||||||SC0_RES_VCUT[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 16|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|15 to 8|SC0_RES_|0|R/W|Horizontal Amount of Cut-off Post-Scaling Image (Right and Left Parts)|
||HCUT[7:0]|||Sets the number of pixel-clock cycles.|
|7 to 0|SC0_RES_|0|R/W|Vertical Amount of Cut-off Post-Scaling Image (Upper and Lower Parts)|
||VCUT[7:0]|||Sets the number of lines.|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.26 Frame Buffer Read Select Register (SC0_SCL0_US8)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1||0||
|||||||||||||SC0_RES_<br>IBUS_||||SC0_RES_|||
||—|—|—|—|—|—|—|—|—|—|—|SYNC_|—|—|—||DISP_ON||
|||||||||||||SEL|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R||R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|SC0_RES_IBUS_|0|R/W|Sync Signal Select for Frame Buffer Read Block|
||SYNC_SEL|||0: Sync signals from the scaling-up control block|
|||||1: Sync signals from the graphics processing block|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|SC0_RES_DISP|0|R/W|Post-Scaling Image Frame Display On/Off|
||_ON|||0: Frame display on|
|||||1: Frame display off|

Note: SC0_RES_IBUS_SYNC_SEL is updated when the SC0_SCL0_VEN_B and SC0_SCL0_VEN_D bits in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) are 1.

SC0_RES_DISP_ON is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.27 Background Color Register (SC0_SCL0_OVR1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|||SC0_RES_BK_COL_R[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||SC0_RES_BK_COL_G[7:0]||||||||SC0_RES_BK_COL_B[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|24|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|23|to|16|SC0_RES_BK_|128|R/W|Background Color Setting R/Cr Signal|
||||CLO_R[7:0]|||R:<br>8 bits; unsigned (0 to 255 [LSB])|
|||||||Cr:<br>8 bits; 128 offset binary; unsigned (0 to 255 [LSB])|
|15|to|8|SC0_RES_BK_|0|R/W|Background Color Setting G/Y Signal|
||||COL_G[7:0]|||G/Y: 8 bits; unsigned (0 to 255 [LSB])|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|7 to 0|SC0_RES_BK_|128|R/W|Background Color Setting B/Cb Signal|
||COL_B[7:0]|||B:<br>8 bits; unsigned (0 to 255 [LSB])|
|||||Cb:<br>8 bits; 128 offset binary; unsigned (0 to 255 [LSB])|

Note: This register is updated when the SC0_SCL0_VEN_B bit in the SC0_SCL0 register update control register (SC0_SCL0_UPDATE) is 1.

## 31.2.28 SCL1 Register Update Control Register (SC0_SCL1_UPDATE)

||Bit:|31|30|29|28|27|||26|25<br>24|23<br>22<br>21|20||19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||SC0_SCL1||||||SC0_SCL1||
|||—|—|—|—|—|||—|—<br>—|—<br>—<br>—|_UPDATE_||—|—|—||_UPDATE_||
|||||||||||||B||||||A||
||Initial value:|0|0|0|0|0|||0|0<br>0|0<br>0<br>0|0||0|0|0||0||
||R/W:|R|R|R|R|R|||R|R<br>R|R<br>R<br>R<br>R/WC1|||R|R|R|R/WC1|||
||Bit:|15|14|13|12|11|||10|9<br>8|7<br>6<br>5|4||3|2|1||0||
|||—|—|—|—|—|||—|—<br>—|—<br>—<br>—|SC0_<br>SCL1_||—|—|—||SC0_<br>SCL1_||
|||||||||||||VEN_B||||||VEN_A||
||Initial value:|0|0|0|0|0|||0|0<br>0|0<br>0<br>0|0||0|0|0||0||
||R/W:|R|R|R|R|R|||R|R<br>R|R<br>R<br>R|R/WC1||R|R|R|R/WC1|||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**|||**Description**||||||||||
|31|to 21|—||All|0||R|||Reserved||||||||||
|||||||||||These bits|are always read as 0. The write value should always be 0.|||||||||
|20||SC0_SCL1_||0|||R/WC1|||Frame Buffer Write Control Register Update||||||||||
|||UPDATE_B||||||||0: Registers are not updated.||||||||||
|||||||||||1: Registers are updated.||||||||||
|19|to 17|—||All|0||R|||Reserved||||||||||
|||||||||||These bits|are always read as 0. The write value should always be 0.|||||||||
|16||SC0_SCL1_||0|||R/WC1|||Frame Buffer Write Control Register Update||||||||||
|||UPDATE_A||||||||0: Registers are not updated.||||||||||
|||||||||||1: Registers are updated.||||||||||
|15|to 5|—||All|0||R|||Reserved||||||||||
|||||||||||These bits|are always read as 0. The write value should always be 0.|||||||||
|4||SC0_SCL1_||0|||R/WC1|||Frame Buffer Write Control Register Update||||||||||
|||VEN_B||||||||0: Registers are not updated.||||||||||
|||||||||||1: Registers are updated at the rising edge of the Vsync.||||||||||
|3 to 1||—||All|0||R|||Reserved||||||||||
|||||||||||These bits|are always read as 0. The write value should always be 0.|||||||||
|0||SC0_SCL1_||0|||R/WC1|||Frame Buffer Write Control Register Update||||||||||
|||VEN_A||||||||0: Registers are not updated.||||||||||
|||||||||||1: Registers are updated at the rising edge of the Vsync.||||||||||

## 31.2.29 Writing Mode Register (SC0_SCL1_WR1)

|Bit:|31|30|29|28|27|26|25|24||23|22|21|20|19|18|17|||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—||—|—|—|—|—|SC0_RES_WRSWA||||||
|||||||||||||||||[2:0]|||||
|Initial value:|0|0|0|0|0|0|0|0||0|0|0|0|0|0|0|||0||
|R/W:|R|R|R|R|R|R|R|R||R|R|R|R|R|R/W|R/W|||R/W||
|Bit:|15|14|13|12|11|10|9|8||7|6|5|4|3|2|1|||0||
||—|—|—|—|—|—|—|—|SC0_RES_<br>TB_ADD_<br>MOD||SC0_RES_DS_WR_MD[2:0]|||SC0_RES_MD[1:0]||SC0_RES_<br>LOOP||SC0_RES_<br>BST_MD|||
|Initial value:|0|0|0|0|0|0|0|0||0|0|0|0|0|0|0|||0||
|R/W:|R|R|R|R|R|R|R|R||R/W|R/W|R/W|R/W|R/W|R/W|R/W|||R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 19|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|18 to 16|SC0_RES_|All 0|R/W|8-Bit, 16-Bit, or 32-Bit Swap Setting|
||WRSWA[2:0]|||These bits control swapping in frame buffer writing as follows.|
|||||Bit 0|
|||||0: Swapped in 8-bit units.|
|||||1: Not swapped in 8-bit units.|
|||||Bit 1|
|||||0: Swapped in 16-bit units.|
|||||1: Not swapped in 16-bit units.|
|||||Bit 2|
|||||0: Swapped in 32-bit units.|
|||||1: Not swapped in 32-bit units.|
|||||According to the setting of these bits, data is swapped as follows. Each|
|||||number in parentheses ((1) to (8)) indicates 8-bit data.|
|||||000: (1) (2) (3) (4) (5) (6) (7) (8)|
|||||[Not swapped]|
|||||001: (2) (1) (4) (3) (6) (5) (8) (7)|
|||||[Swapped in 8-bit units]|
|||||010: (3) (4) (1) (2) (7) (8) (5) (6)|
|||||[Swapped in 16-bit units]|
|||||011: (4) (3) (2) (1) (8) (7) (6) (5)|
|||||[Swapped in 16-bit units + 8-bit units]|
|||||100: (5) (6) (7) (8) (1) (2) (3) (4)|
|||||[Swapped in 32-bit units]|
|||||101: (6) (5) (8) (7) (2) (1) (4) (3)|
|||||[Swapped in 32-bit units + 8-bit units]|
|||||110: (7) (8) (5) (6) (3) (4) (1) (2)|
|||||[Swapped in 32-bit units + 16-bit units]|
|||||111: (8) (7) (6) (5) (4) (3) (2) (1)|
|||||[Swapped in 32-bit units + 16-bit units + 8-bit units]|
|||||Note: When YCbCr422 or RGB565 is selected as a frame buffer video-|
|||||signal writing format, these bits should be set to 000 [Not|
|||||swapped].|
|15 to 8|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|7|SC0_RES_|0|R/W|Top and Bottom Data Write Address Specification Method|
||TB_ADD_MOD|||0: A write address is specified in common for top and bottom data.|
|||||1: Separate write addresses are specified for top and bottom data.|
|6 to 4|SC0_RES_|0|R/W|Frame Buffer Writing Mode for Image Processing|
||DS_WR_MD|||0: Normal|
||[2:0]|||1: Horizontal mirroring|
|||||2: 90° rotation|
|||||3: 180° rotation|
|||||4: 270° rotation|
|||||5 to 7: Setting prohibited|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|3, 2|SC0_RES_MD|0|R/W|Frame Buffer Video-Signal Writing Format|
||[1:0]|||0: YCbCr422 (16 bits)|
|||||1: RGB565 (16 bits)|
|||||2: RGB888 (24 (32) bits)|
|||||3: YCbCr444 (24 (32) bits)|
|1|SC0_RES_|0|R/W|Frame Buffer Write Mode Select|
||LOOP|||0: Frame mode|
|||||1: Line mode (read as ring buffer)|
|0|SC0_RES_|0|R/W|Transfer Burst Length for Frame Buffer Writing|
||BST_MD|||0: 32-byte|
|||||1: 128-byte|

Note: SC0_RES_LOOP and SC0_RES_BST_MD are updated when the SC0_SCL1_VEN_B bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

SC0_RES_TB_ADD_MOD, SC0_RES_DS_WR_MD, and SC0_RES_MD are updated when the SC0_SCL1_VEN_A and SC0_SCL1_VEN_B bits in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) are 1.

SC0_RES_WRSWA is updated when the SC0_SCL1_UPDATE_A bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.30 Write Address Register 1T (SC0_SCL1_WR2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||SC0_RES_BASE[31:16]||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||SC0_RES_BASE[15:0]||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|0|SC0_RES_|0|R/W|Frame Buffer Base Address|
||||BASE|||Sets the start address of the frame buffer to store the frame data for the|
||||[31:0]|||top field when SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1 or that|
|||||||for the top and bottom fields when|
|||||||SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 0.|
|||||||For 32-byte transfer: The lower five bits should be fixed to 0 0000.|
|||||||For 128-byte transfer: The lower seven bits should be fixed to 000 0000.|

Note: This register is updated when the SC0_SCL1_VEN_B bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.31 Write Address Register 2T (SC0_SCL1_WR3)

||Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18|17|16|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|||||||SC0_RES_LN_OFF[14:0]||||||
||Initial value:|0|0|0|0||1|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0||0||
||R/W:|R|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||R/W|R/W|||
||Bit:|15|14|13|12||11|10|9<br>8<br>7<br>6<br>5<br>4<br>3|2|1||0||
|||—|—|—|—||—|—|SC0_RES_FLM_NUM[9:0]||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0||1||
||R/W:|R|R|R|R||R|R|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||R/W|R/W|||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**||||||
|31||—||0|||R||Reserved||||||
||||||||||This bit is always read as 0. The write value should always be|||0.|||
|30|to 16|SC0_RES_||2048|||R/W||Frame Buffer Line Offset Address||||||
|||LN_OFF|||||||Sets the line offset address for calculating the line|start address for the|||||
|||[14:0]|||||||top field when SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1||||or that||
||||||||||for the top and bottom fields when||||||
||||||||||SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 0.||||||
||||||||||Line 0: SC0_RES_BASE||||||
||||||||||Line 1: SC0_RES_BASE + SC0_RES_LN_OFF ×|1|||||
||||||||||:||||||
||||||||||Line n: SC0_RES_BASE + SC0_RES_LN_OFF ×|n|||||
||||||||||For 32-byte transfer: The lower five bits should be|fixed|to 0 0000.||||
||||||||||For 128-byte transfer: The lower seven bits should be fixed to|||000 0000.|||
|15|to 10|—||All|0||R||Reserved||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||
|9 to 0||SC0_RES_||1|||R/W||Number of Frames of Buffer to be Written to||||||
|||FLM_NUM|||||||Sets the number of frames for the top field when||||||
|||[9:0]|||||||SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1 or that for the top and||||||
||||||||||bottom fields when SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 0||||||
||||||||||Number of frames defined by SC0_RES_FLM_NUM  + 1 are used.||||||

Note: This register is updated when the SC0_SCL1_VEN_B bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.32 Write Address Register 3T (SC0_SCL1_WR4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—||SC0_RES_FLM_OFF[22:16]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||||||SC0_RES_FLM_OFF[15:0]|||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 23|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|22 to 0|SC0_RES_|524288|R/W|Frame Buffer Frame Offset Address|
||FLM_OFF<br>[22:0]|||Sets the frame offset address for calculating the start address of each<br>frame for the top field when SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD =|
|||||1 or that for the top and bottom fields when|
|||||SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 0.|
|||||Buffer 0: SC0_RES_BASE|
|||||Buffer 1: SC0_RES_BASE + SC0_RES_FLM_OFF × 1|
|||||:|
|||||Buffer n: SC0_RES_BASE + SC0_RES_FLM_OFF × n|
|||||For 32-byte transfer: The lower five bits should be fixed to 0 0000.|
|||||For 128-byte transfer: The lower seven bits should be fixed to 000 0000.|

Note: This register is updated when the SC0_SCL1_VEN_B bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.33 Frame Sub-Sampling Register (SC0_SCL1_WR5)

|||Bit:|31|30|29|28||27||26|25<br>24<br>23<br>22|21|20|19||18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|—|—|—||—||—|—<br>—<br>—<br>—|—|—|—||—|—|—||
|||Initial value:|0|0|0|0||0||0|0<br>0<br>0<br>0|0|0|0||0|0|0||
|||R/W:|R|R|R|R||R||R|R<br>R<br>R<br>R|R|R|R||R|R|R||
|||Bit:|15|14|13|12||11||10|9<br>8<br>7<br>6|5|4|3||2|1|0||
||||—|—|—|SC0_RES<br>_INTER||—||—|—<br>—<br>SC0_RES_FS_<br>RATE[1:0]|—|SC0_RES<br>_FLD_<br>SEL|—||—|—|SC0_RES<br>_WENB||
|||Initial value:|0|0|0|1||0||0|0<br>0<br>0<br>0|0|0|0||0|0|0||
|||R/W:|R|R|R|R/W||R||R|R/W<br>R/W<br>R<br>R|R|R/W|R||R|R|R/W||
|**Bit**|||**Bit Name**||**Initial Value**||||**R/W**||**Description**|||||||||
|31||to 13|—||All|0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|12|||SC0_RES_||1||||R/W||Field Operating Mode Select|||||||||
||||INTER||||||||0: Progressive|||||||||
||||||||||||1: Interlace|||||||||
|11,||10|—||All|0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|9,|8||SC0_RES_||0||||R/W||Writing Rate|||||||||
||||FS_RATE||||||||Sets the frame buffer writing rate to the vertical|||||frequency of the input||||
||||[1:0]||||||||signal.|||||||||
||||||||||||0: 1/1 an input signal (The SC0_RES_FLD_SEL setting is invalid.)|||||||||
||||||||||||1: 1/2 an input signal|||||||||
||||||||||||2: 1/4 an input signal|||||||||
||||||||||||3: 1/8 an input signal|||||||||
|7 to 5|||—||All|0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|4|||SC0_RES_||0||||R/W||Write Field Select|||||||||
||||FLD_SEL||||||||0: Top field|||||||||
||||||||||||1: Bottom field|||||||||
|3 to 1|||—||All|0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|0|||SC0_RES_||0||||R/W||Frame Buffer Write Enable|||||||||
||||WENB||||||||After making the setting to enable writing, writing starts from the second|||||||||
||||||||||||frame.|||||||||
||||||||||||0: Frame buffer writing is|disabled.||||||||
||||||||||||1: Frame buffer writing is|enabled.||||||||

Note: SC0_RES_INTER, SC0_RES_FS_RATE[1:0], and SC0_RES_FLD_SEL are updated when the SC0_SCL1_VEN_A bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1. SC0_RES_WENB is updated when the SC0_SCL1_VEN_A and SC0_SCL1_VEN_B bits in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) are 1.

## 31.2.34 Bit Reduction Register (SC0_SCL1_WR6)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1||0||
||—|—|—|—|—|—|—|—|—|—|—|SC0_RES_<br>DTH_ON|—|—|—|SC0_RES_<br>BITDEC_<br>ON|||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R||R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|SC0_RES_|0|R/W|Dither Correction On/Off|
||DTH_ON|||0: Off (rounded off)|
|||||1: On (2 × 2 dither pattern)|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|SC0_RES_|0|R/W|Bit Reduction On/Off|
||BITDEC_|||0: Off|
||ON|||1: On|

Note: This register is updated when the SC0_SCL1_VEN_A bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.35 Write Detection Register (SC0_SCL1_WR7)

||Bit:|31|30|29|28||27|26|25<br>24|23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||SC0_RES_||
|||—|—|—|—||—|—|—<br>—|—<br>—<br>—|—|—|—|—|OVER||
||||||||||||||||FLOW||
||Initial value:|0|0|0|0||0|0|0<br>0|0<br>0<br>0|0|0|0|0|0||
||R/W:|R|R|R|R||R|R|R<br>R|R<br>R<br>R|R|R|R|R|R||
||Bit:|15|14|13|12||11|10|9<br>8|7<br>6<br>5|4|3|2|1|0||
|||—|—|—|—||—|—||SC0_RES_FLM_CNT[9:0]|||||||
||Initial value:|0|0|0|0||0|0|0<br>0|0<br>0<br>0|0|0|0|0|0||
||R/W:|R|R|R|R||R|R|R<br>R|R<br>R<br>R|R|R|R|R|R||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**|**Description**||||||||
|31|to 17|—||All 0||||R|Reserved||||||||
||||||||||These bits|are always read as 0. The write value should always be 0.|||||||
|16||SC0_RES_||0||||R|Line Buffer|Overflow Detect|||||||
|||OVERFLOW|||||||1: Line buffer has overflowed.||||||||
||||||||||0: Line buffer has not overflowed.||||||||
|15|to 10|—||All 0||||R|Reserved||||||||
||||||||||These bits|are always read as 0. The write value should always be 0.|||||||
|9 to 0||SC0_RES_||0||||R|Frame Number of Frame Being Accessed||||||||
|||FLM_CNT|||||||Frame number of the frame being accessed in||||the top|field when|||
|||[9:0]|||||||SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1 or that in the top or||||||||
||||||||||bottom field when SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 0.||||||||

## 31.2.36 Write Address Register 1B (SC0_SCL1_WR8)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||SC0_RES_BASE_B[31:16]||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||SC0_RES_BASE_B[15:0]||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|0|SC0_RES_|0|R/W|Frame Buffer Base Address for Bottom|
||||BASE_B|||Sets the start address of the frame buffer to store the frame data for the|
||||[31:0]|||bottom field when SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1.|
|||||||For 32-byte transfer: The lower five bits should be fixed to 0_0000.|
|||||||For 128-byte transfer: The lower seven bits should be fixed to|
|||||||000_0000.|

Note: This register is updated when the SC0_SCL1_VEN_B bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.37 Write Address Register 2B (SC0_SCL1_WR9)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—||||||SC0_RES_LN_OFF_B[14:0]||||||||||
|Initial value:|0|0|0|0|1|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|—||||SC0_RES_FLM_NUM_B[9:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W:|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|30 to 16|SC0_RES_|2048|R/W|Frame Buffer Line Offset Address for Bottom|
||LN_OFF_B|||Sets the line offset address for calculating the line start address for the|
||[14:0]|||bottom field when SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1.|
|||||Line 0: SC0_RES_BASE_B|
|||||Line 1: SC0_RES_BASE_B + SC0_RES_LN_OFF_B × 1|
|||||:|
|||||Line n: SC0_RES_BASE + SC0_RES_LN_OFF_B × n|
|||||For 32-byte transfer: The lower five bits should be fixed to 0_0000.|
|||||For 128-byte transfer: The lower seven bits should be fixed to 000_0000.|
|15 to 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9 to 0|SC0_RES_|1|R/W|Number of Frames of Buffer to be Written to for Bottom Field|
||FLM_NUM_B|||Number of frames defined by SC0_RES_FLM_NUM_B + 1 are used when|
||[9:0]|||SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1.|

Note: This register is updated when the SC0_SCL1_VEN_B bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.38 Write Address Register 3B (SC0_SCL1_WR10)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—||SC0_RES_FLM_OFF_B[22:16]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|1|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||SC0_RES_FLM_OFF_B[15:0]|||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|23|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|22|to|0|SC0_RES_|524288|R/W|Frame Buffer Frame Offset Address for Bottom|
||||FLM_OFF_|||Sets the frame offset address for calculating the start address of each|
||||B[22:0]|||frame for the bottom field when|
|||||||SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1.|
|||||||Buffer 0: SC0_RES_BASE_B|
|||||||Buffer 1: SC0_RES_BASE_B|
|||||||+ SC0_RES_FLM_OFF_B × 1|
|||||||:|
|||||||Buffer n: SC0_RES_BASE_B|
|||||||+ SC0_RES_FLM_OFF_B × n|
|||||||For 32-byte transfer: The lower five bits should be fixed to 0_0000.|
|||||||For 128-byte transfer: The lower seven bits should be fixed to|
|||||||000_0000.|

Note: This register is updated when the SC0_SCL1_VEN_B bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.39 Write Detection Register B (SC0_SCL1_WR11)

|||Bit:||31|30|29|||28|27||26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—|—|—|||—|—||—|—<br>—|—|—|—|—|—|—|—|—||
|||Initial value:||0|0|0|||0|0||0|0<br>0|0|0|0|0|0|0|0|0||
|||R/W:||R|R|R|||R|R||R|R<br>R|R|R|R|R|R|R|R|R||
|||Bit:||15|14|13|||12|11||10|9<br>8|7|6|5|4|3|2|1|0||
|||||—|—|—|||—|—||—|||SC0_RES_FLM_CNT_B[9:0]||||||||
|||Initial value:||0|0|0|||0|0||0|0<br>0|0|0|0|0|0|0|0|0||
|||R/W:||R|R|R|||R|R||R|R<br>R|R|R|R|R|R|R|R|R||
|**Bit**|||**Bit Name**||||**Initial Value**||||**R/W**||**Description**||||||||||
|31||to 10|—||||All||0||R||Reserved||||||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|9|to 0||SC0_RES_||||0||||R||Frame Number of Frame Being Accessed in Bottom Field||||||||||
||||FLM_CNT_B||||||||||Frame number of||the frame being accessed in||||the bottom field when||||
||||[9:0]||||||||||SC0_SCL1_WR1.SC0_RES_TB_ADD_MOD = 1.||||||||||

## 31.2.40 Status Monitor 1 Register (SC0_SCL1_MON1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|—|SC0_PBUF_NUM<br>[1:0]||—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9, 8|SC0_PBUF_|All 0|R|Write pointer indicating the pointer buffer number corresponding to the|
||NUM[1:0]|||location currently being written to.|
|7 to 0|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 31.2.41 Pointer Buffer 0 Register (SC0_SCL1_PBUF0)

||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||SC0_PBUF0_ADD[31:16]||||||||||
||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||SC0_PBUF0_ADD[15:0]||||||||||
||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**|||||||||
|31|to 0|SC0_PBUF0_||All 0|||R||Start address of the write|||buffer|pointed|to by pointer||buffer 0.||
|||ADD[31:0]||||||||||||||||

## 31.2.42 Pointer Buffer 1 Register (SC0_SCL1_PBUF1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||SC0_PBUF1_ADD[31:16]||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||SC0_PBUF1_ADD[15:0]||||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|0|SC0_PBUF1_|All 0|R|Start address of the write buffer pointed to by pointer buffer 1.|
||||ADD[31:0]||||

## 31.2.43 Pointer Buffer 2 Register (SC0_SCL1_PBUF2)

||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||SC0_PBUF2_ADD[31:16]||||||||||
||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||SC0_PBUF2_ADD[15:0]||||||||||
||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|**Bit**||**Bit Name**||**Initial**|**Value**||**R/W**||**Description**|||||||||
|31|to 0|SC0_PBUF2_||All 0|||R||Start address of the write|||buffer|pointed|to by pointer||buffer 2.||
|||ADD[31:0]||||||||||||||||

## 31.2.44 Pointer Buffer 3 Register (SC0_SCL1_PBUF3)

||Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||SC0_PBUF3_ADD[31:16]||||||||||
||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||SC0_PBUF3_ADD[15:0]||||||||||
||Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|**Bit**||**Bit Name**|||**Initial Value**||**R/W**||**Description**|||||||||
|31|to 0|SC0_PBUF3_|||All 0||R||Start address of the write|||buffer|pointed|to by pointer||buffer 3.||
|||ADD[31:0]||||||||||||||||

## 31.2.45 Pointer Buffer and Field Information Register (SC0_SCL1_PBUF_FLD)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|SC0_FLD<br>_INF3|—|—|—|—|—|—|—|SC0_FLD<br>_INF2||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||SC0_FLD||||||||SC0_FLD||
||—|—|—|—|—|—|—|_INF1|—|—|—|—|—|—|—|_INF0||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 25|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|24|SC0_FLD_|0|R|Top or bottom field information of the frame buffer pointed to by|
||INF3|||pointer buffer 3.|
|||||0: Bottom|
|||||1: Top|
|23 to 17|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|16|SC0_FLD_|0|R|Top or bottom field information of the frame buffer pointed to by|
||INF2|||pointer buffer 2.|
|||||0: Bottom|
|||||1: Top|
|15 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|SC0_FLD_|0|R|Top or bottom field information of the frame buffer pointed to by|
||INF1|||pointer buffer 1.|
|||||0: Bottom|
|||||1: Top|
|7 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|0|SC0_FLD_|0|R|Top or bottom field information of the frame buffer pointed to by|
||INF0|||pointer buffer 0.|
|||||0: Bottom|
|||||1: Top|

## 31.2.46 Pointer Buffer Control Register (SC0_SCL1_PBUF_CNT)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||SC0_||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|PBUF_||
|||||||||||||||||RST||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|17|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|16|||SC0_PBUF_|0|R/W|Reset Control for Pointer Buffer|
||||RST|||0: Pointer buffer is not reset.|
|||||||1: Pointer buffer is reset.|
|15|to|0|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

Note: This register is updated when the SC0_SCL1_UPDATE_B bit in the SC0_SCL1 register update control register (SC0_SCL1_UPDATE) is 1.

## 31.2.47 Graphics 0 Register Update Control Register (GR0_UPDATE)

|Bit:|31|30|29|28|27|26|25|24||23|22|21|20||19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—||—|—|—|—||—|—|—||—||
|Initial value:|0|0|0|0|0|0|0|0||0|0|0|0||0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R||R|R|R|R||R|R|R||R||
|Bit:|15|14|13|12|11|10|9|8||7|6|5|4||3|2|1||0||
||—|—|—|—|—|—|—|GR0_<br>UPDATE||—|—|—|GR0_<br>P_VEN||—|—|—||GR0_<br>IBUS_<br>VEN||
|Initial value:|0|0|0|0|0|0|0|0||0|0|0|0||0|0|0||0||
|R/W:|R|R|R|R|R|R|R|R/WC1||R|R|R|R/WC1||R|R|R|R/WC1|||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|GR0_|0|R/WC1|Frame Buffer Read Control Register Update|
||UPDATE|||0: Registers are not updated.|
|||||1: Registers are updated.|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|GR0_P_|0|R/WC1|Graphics Display Register Update|
||VEN|||0: Registers are not updated.|
|||||1: Registers are updated at the rising edge of the Vsync.|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|GR0_IBUS_|0|R/WC1|Frame Buffer Read Control Register Update|
||VEN|||0: Registers are not updated.|
|||||1: Registers are updated at the rising edge of the Vsync.|

## 31.2.48 Frame Buffer Read Control Register (Graphics 0) (GR0_FLM_RD)

**==> picture [483 x 216] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>— — — — — — — — — — — — — — — —<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>— — — — — — — — — — — — — — — R_ENBGR0_<br>Initial value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W: R R R R R R R R R R R R R R R R/W<br>Bit Bit Name Initial Value R/W Description<br>31 to 1 — All 0 R Reserved<br>These bits are always read as 0. The write value should always be 0.<br>0 GR0_R_ 0 R/W Frame Buffer Read Enable<br>ENB 0: Frame buffer reading is disabled.<br>1: Frame buffer reading is enabled.<br>**----- End of picture text -----**<br>

Note: This register is updated when the GR0_IBUS_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.49 Frame Buffer Control Register 1 (Graphics 0) (GR0_FLM1)

||Bit:|31|30|29||28|27||26|25<br>24<br>23<br>22<br>21||20||19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||GR0_<br>FLD_<br>SEL|—|—||—|—||—|—<br>—<br>—<br>—<br>—||—||—|—|—|GR0_LN_<br>OFF_DIR||
||Initial value:|0|0|0||0|0||0|0<br>0<br>0<br>0<br>0||0||0|0|0|0||
||R/W:|R/W|R|R||R|R||R|R<br>R<br>R<br>R<br>R||R||R|R|R|R/W||
||Bit:|15|14|13||12|11||10|9<br>8<br>7<br>6<br>5||4||3|2|1|0||
|||—|—|—||—|—||—|—<br>—<br>—<br>GR0_FLM_SEL[1:0]||—||—|—|—|GR0_<br>BST_MD||
||Initial value:|0|0|0||0|0||0|0<br>0<br>0<br>0<br>0||0||0|0|0|0||
||R/W:|R|R|R||R|R||R|R/W<br>R/W<br>R<br>R<br>R||R||R|R|R|R/W||
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**|||||||||
|31||GR0_FLD_SEL|||0|||R/W||Enables or disables top or bottom field selection for the next frame|||||||||
|||||||||||buffer to be read.|||||||||
|||||||||||0: Field selection is disabled.|||||||||
|||||||||||1: Top or bottom field can be selected.|||||||||
|30 to 17||—|||All 0|||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|16||GR0_LN_|||0|||R/W||Selects the line offset address direction||||of the frame buffer.|||||
|||OFF_DIR||||||||0: Increments the address by the line offset address.|||||||||
|||||||||||1: Decrements the address by the||line offset address.|||||||
|15 to 10||—|||All 0|||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|9,|8|GR0_FLM_SEL|||0|||R/W||Selects a frame buffer address setting signal.|||||||||
|||[1:0]||||||||0: Links to scaling-down process. (This setting is prohibited when|||||||||
|||||||||||separate write addresses are specified for the top and bottom fields; that|||||||||
|||||||||||is, SC0_RES_TB_ADD_MOD = 1||in SC0_SCL1_WR1.)|||||||
|||||||||||1: Selects GR0_FLM_NUM.|||||||||
|||||||||||2: Setting prohibited|||||||||
|||||||||||3: Links to pointer buffer.|||||||||
|7 to 1||—|||All 0|||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|0||GR0_BST_MD|||0|||R/W||Frame Buffer Burst Transfer Mode|||||||||
|||||||||||0: 32-byte transfer|||||||||
|||||||||||1: 128- byte transfer|||||||||

Note: GR0_FLD_SEL is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

GR0_LN_OFF_DIR is updated when the GR0_IBUS_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

GR0_FLM_SEL is updated when the GR0_P_VEN and GR0_IBUS_VEN bits in the graphics 0 register update control register (GR0_UPDATE) are 1.

GR0_BST_MD is updated when the GR0_IBUS_VEN and GR0_P_VEN bits in the graphics 0 register update control register (GR0_UPDATE) are 1.

## 31.2.50 Frame Buffer Control Register 2 (Graphics 0) (GR0_FLM2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||GR0_BASE[31:16]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||GR0_BASE[15:0]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|0|GR0_BASE|0|R/W|Frame Buffer Base Address|
||||[31:0]|||Sets the start address of the frame buffer where frame data is to be|
|||||||stored.|
|||||||GR0_BASE[4:3] and GR0_BASE[6:3] are referred to during 32-byte|
|||||||burst transfer and 128-byte burst transfer, respectively, to skip the start|
|||||||line data.|
|||||||The lower three bits should be fixed to 000.|

Note: This register is updated when the GR0_IBUS_VEN and GR0_P_VEN bits in the graphics 0 register update control register (GR0_UPDATE) are 1.

## 31.2.51 Frame Buffer Control Register 3 (Graphics 0) (GR0_FLM3)

||Bit:|31|30||29|28||27|26|25<br>24<br>23|22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||GR0_<br>FLD_<br>NXT||||||||GR0_LN_OFF[14:0]|||||||
||Initial value:|0|0||0|0||1|0|0<br>0<br>0|0<br>0<br>0|0|0|0|0||
||R/W:|R/W|R/W|R/W||R/W|R/W||R/W|R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14||13|12||11|10|9<br>8<br>7|6<br>5<br>4|3|2|1|0||
|||—|—||—|—||—|—||GR0_FLM_NUM[9:0]||||||
||Initial value:|0|0||0|0||0|0|0<br>0<br>0|0<br>0<br>0|0|0|0|1||
||R/W:|R|R||R|R||R|R|R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**|||||||
|31||GR0_FLD_NXT|||0|||R/W||Top or Bottom Field|Selection for Next Frame Buffer||||||
|||||||||||0: Bottom|||||||
|||||||||||1: Top|||||||
|30|to 16|GR0_LN_|||2048|||R/W||Frame Buffer Line Offset Address|||||||
|||OFF[14:0]||||||||Sets the line offset address for calculating the start address of each line.|||||||
|||||||||||Line 0: GR0_BASE|||||||
|||||||||||Line 1: GR0_BASE|+ GR0_LN_OFF × 1||||||
|||||||||||:|||||||
|||||||||||Line n: GR0_BASE|+ GR0_LN_OFF × n||||||
|||||||||||For 32-byte transfer: The lower five bits should|||be fixed to 0 0000.||||
|||||||||||For 128-byte transfer: The lower seven bits should be fixed to 000 0000.|||||||
|15|to 10|—|||All|0||R||Reserved|||||||
|||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|9 to 0||GR0_FLM_|||1|||R/W||Frame Number of Frame Buffer|||||||
|||NUM[9:0]||||||||Manually set the frame number when GR0_FLM_SEL = 1.|||||||

Note: GR0_FLD_NXT is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

GR0_LN_OFF[14:0] and GR0_FLM_NUM[9:0] are updated when the GR0_IBUS_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.52 Frame Buffer Control Register 4 (Graphics 0) (GR0_FLM4)

|||Bit:|31|30|29|28||27|26|25<br>24|23<br>22<br>21|20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|—|—|—||—|—|—<br>—|—|GR0_FLM_OFF[22:16]|||||
||Initial|value:|0|0|0|0||0|0|0<br>0|0<br>0<br>0|0<br>1|0|0|0||
|||R/W:|R|R|R|R||R|R|R<br>R|R<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W||
|||Bit:|15|14|13|12||11|10|9<br>8|7<br>6<br>5|4<br>3|2|1|0||
|||||||||||GR0_FLM_OFF[15:0]|||||||
||Initial|value:|0|0|0|0||0|0|0<br>0|0<br>0<br>0|0<br>0|0|0|0||
|||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W|R/W<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W||
|**Bit**|||**Bit Name**||**Initial Value**|||**R/W**||**Description**|||||||
|31|to 23|—|||All 0|||R||Reserved|||||||
|||||||||||These bits are always read as 0.||The write value should||always be 0.|||
|22|to 0|GR0_FLM_|||524288|||R/W||Frame Buffer Frame Offset Address|||||||
|||OFF[22:0]||||||||Specifies the frame offset address used for calculating the start address|||||||
|||||||||||of each frame buffer when more||than one buffer|is used.||||
|||||||||||Buffer 0: GR0_BASE|||||||
|||||||||||Buffer 1: GR0_BASE + GR0_FLM_OFF × 1|||||||
|||||||||||:|||||||
|||||||||||Buffer n: GR0_BASE + GR0_FLM_OFF × n|||||||
|||||||||||For 32-byte|transfer: The lower five bits should be fixed to 0 0000.||||||
|||||||||||For 128-byte transfer: The lower||seven bits should be fixed to 000 0000.|||||

Note: This register is updated when the GR0_IBUS_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.53 Frame Buffer Control Register 5 (Graphics 0) (GR0_FLM5)

||Bit:|31|30|29|28||27||26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—|||GR0_FLM_LNUM[10:0]||||||
||Initial value:|0|0|0|0||0||0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:|R|R|R|R||R||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14|13|12||11||10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|||—|—|—|—||—|||GR0_FLM_LOOP[10:0]||||||
||Initial value:|0|0|0|0||0||0|1<br>1<br>1<br>1<br>1<br>1|1|1|1|1||
||R/W:|R|R|R|R||R||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**||||||
|31|to 27|—||All|0|||R||Reserved||||||
|||||||||||These bits are always read as 0. The write value||should|always be 0.|||
|26|to 16|GR0_FLM_||0||||R/W||Sets number of lines in a frame||||||
|||LNUM[10:0]||||||||Number of lines is (GR0_FLM_LNUM +|1).|||||
|15|to 11|—||All|0|||R||Reserved||||||
|||||||||||These bits are always read as 0. The write value||should|always be 0.|||
|10|to 0|GR0_FLM_||1023||||R/W||Number of lines when reading the addresses repeatedly by returning|||||to|
|||LOOP[10:0]||||||||the start address after reaching the end|address.|||||
|||||||||||(GR0_FLM_LOOP + 1) lines are read.||||||

Note: This register is updated when the GR0_IBUS_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.54 Frame Buffer Control Register 6 (Graphics 0) (GR0_FLM6)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-<br>-<br>-<br>GR0_FORMAT[3:0]||||—|||||GR0_HW[10:0]||||||||
|Initial value:|1|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||-<br>-<br>GR0_YCC_SWAP[2:0]|||GR0_RDSWA[2:0]|||—|GR0_<br>CNV444_<br>MD|—|—||GR0_STA_POS[5:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R|R/W|R|R|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|28|GR0_|8|R/W|Sets the format of the frame buffer read signal.|
||||FORMAT|||0: RGB565|
||||[3:0]|||1: RGB888|
|||||||2:αRGB1555|
|||||||3:αRGB4444|
|||||||4:αRGB8888|
|||||||5: CLUT8|
|||||||6: CLUT4|
|||||||7: CLUT1|
|||||||8: YCbCr422|
|||||||9: YCbCr444|
|||||||10: RGBα5551|
|||||||11: RGBα8888|
|||||||12 to 15: Setting prohibited|
|27|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|26|to|16|GR0_HW|0|R/W|Sets the width of the horizontal valid period.|
||||[10:0]|||The width is (GR0_HW + 1) pixels.|
|||||||Note: The set value should be equal to or more than two.|
|15|to|13|GR0_YCC_|0|R/W|Controls swapping of data read from buffer in the YCbCr422 format.|
||||SWAP[2:0]|||0: Cb/Y0/Cr/Y1|
|||||||1: Y0/Cb/Y1/Cr|
|||||||2: Cr/Y0/Cb/Y1|
|||||||3: Y0/Cr/Y1/Cb|
|||||||4: Y1/Cr/Y0/Cb|
|||||||5: Cr/Y1/Cb/Y0|
|||||||6: Y1/Cb/Y0/Cr|
|||||||7: Cb/Y1/Cr/Y0|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|12 to 10|GR0_|0|R/W|8-Bit, 16-Bit, or 32-Bit Swap Setting|
||RDSWA|||These bits control swapping in frame buffer reading as follows.|
||[2:0]|||Bit 0|
|||||0: Swapped in 8-bit units.|
|||||1: Not swapped in 8-bit units.|
|||||Bit 1|
|||||0: Swapped in 16-bit units.|
|||||1: Not swapped in 16-bit units.|
|||||Bit 2|
|||||0: Swapped in 32-bit units.|
|||||1: Not swapped in 32-bit units.|
|||||According to the setting of these bits, data is swapped as follows. Each|
|||||number in parentheses ((1) to (8)) indicates 8-bit data.|
|||||000: (1) (2) (3) (4) (5) (6) (7) (8) [Not swapped]|
|||||001: (2) (1) (4) (3) (6) (5) (8) (7)|
|||||[Swapped in 8-bit units]|
|||||010: (3) (4) (1) (2) (7) (8) (5) (6)|
|||||[Swapped in 16-bit units]|
|||||011: (4) (3) (2) (1) (8) (7) (6) (5)|
|||||[Swapped in 16-bit units + 8-bit units]|
|||||100: (5) (6) (7) (8) (1) (2) (3) (4)|
|||||[Swapped in 32-bit units]|
|||||101: (6) (5) (8) (7) (2) (1) (4) (3)|
|||||[Swapped in 32-bit units + 8-bit units]|
|||||110: (7) (8) (5) (6) (3) (4) (1) (2)|
|||||[Swapped in 32-bit units + 16-bit units]|
|||||111: (8) (7) (6) (5) (4) (3) (2) (1)|
|||||[Swapped in 32-bit units + 16-bit units + 8-bit units]|
|9|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|8|GR0_|0|R/W|Sets the interpolation mode for YCbCr422 to YCbCr444 conversion.|
||CNV444_|||0: Hold interpolation|
||MD|||1: Average interpolation|
|7, 6|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|5 to 0|GR0_STA_|0|R/W|Sets the amount of data to be skipped through.|
||POS[5:0]|||Specifically data amount equal to the amount indicated by|
|||||GR0_STA_POS is skipped from the start of the line.|

Note: GR0_YCC_SWAP, GR0_CNV444, and GR0_STA_POS are updated when GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

GR0_ RDSWA is updated when the GR0_UPDATE bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

GR0_FORMAT and GR0_HW are updated when GR0_IBUS_VEN and GR0_P_VEN bits in the graphics 0 register update control register (GR0_UPDATE) are 1.

## 31.2.55 Alpha Blending Control Register 1 (Graphics 0) (GR0_AB1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||GR0_||||||
||—|—|—|—|—|—|—|—|—|—|—|GRC_DISP|—|—|GR0_DISP_SEL[1:0]|||
|||||||||||||_ON||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|GR0_GRC_|0|R/W|Turns on/off frame-line display of the graphics image area.|
||DISP_ON|||0: Frame-line display off|
|||||1: Frame-line display on|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1, 0|GR0_DISP_|0|R/W|Selects the graphics display mode.|
||SEL[1:0]|||0: Background color display (GR0_BASE)|
|||||1: Lower-layer graphics display|
|||||When displaying video image or enlarged graphics, select this|
|||||setting.|
|||||2: Current graphics display|
|||||When displaying graphics, select this setting.|
|||||3: Blended display of lower-layer graphics and current graphics*|
|||||Note:<br>*   Select this setting whenever chroma-key processing is to|
|||||proceed. Since only current graphics are to be displayed by|
|||||chroma-key processing, set theαvalues for both pixels to be|
|||||subject to chroma-keying and pixels not to be subject to|
|||||chroma-keying to 255.|

Note: This register is updated when GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.56 Alpha Blending Control Register 2 (Graphics 0) (GR0_AB2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR0_GRC_VS[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||GR0_GRC_VW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 27|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|26 to 16|GR0_GRC_|0|R/W|Vertical Start Position of Graphics Image Area.|
||VS[10:0]|||Note: The set value should be four or more (lines). GR0_GRC_VS +|
|||||GR0_GRC_VW should be equal to or less than 2039 (lines).|
|15 to 11|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|10 to 0|GR0_GRC_|0|R/W|Vertical Width of Graphics Image Area.|
||VW[10:0]||||

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.57 Alpha Blending Control Register 3 (Graphics 0) (GR0_AB3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR0_GRC_HS[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||GR0_GRC_HW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 27|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|26 to 16|GR0_GRC_|0|R/W|Horizontal Start Position of Graphics Image Area.|
||HS[10:0]|||Note: The set value should be 16 or more (clock cycles). GR0_GRC_HS|
|||||+ GR0_GRC_HW should be equal to or less than 2015 (clock|
|||||cycles).|
|15 to 11|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|10 to 0|GR0_GRC_|0|R/W|Horizontal Width of Graphics Image Area.|
||HW[10:0]|||Note: For displaying an image with 1- or 2-pixel horizontal width, set|
|||||GR0_HW to 2 and GR0_GRC_HW to 1 (1 pixel) or 2 (2 pixels).|

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.58 Alpha Blending Control Register 7 (Graphics 0) (GR0_AB7)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|1|1|1|1|1|1|1|1||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||||||GR0_||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|CK_ON||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|24|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|23|to|16|—|All 1|R|Reserved|
|||||||These bits are always read as 1. The write value should always be 1.|
|15|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||GR0_CK_|0|R/W|CLUT-Index/RGB-Index Chroma-Key Processing On/Off|
||||ON|||0: Off|
|||||||1: On|

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.59 Alpha Blending Control Register 8 (Graphics 0) (GR0_AB8)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GR0_CK_KCLUT[7:0]||||||||GR0_CK_KG[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GR0_CK_KB[7:0]||||||||GR0_CK_KR[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR0_CK_|0|R/W|CLUT Signal for CLUT-Index Chroma-Key Processing|
||KCLUT[7:0]|||CLUT: Unsigned 8 bits (0 to 255 [LSB])|
|23 to 16|GR0_CK_|0|R/W|G Signal for RGB-Index Chroma-Key Processing|
||KG[7:0]|||G: Unsigned 8 bits (0 to 255 [LSB])|
|15 to 8|GR0_CK_|0|R/W|B Signal for RGB-Index Chroma-Key Processing|
||KB[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|7 to 0|GR0_CK_|0|R/W|R Signal for RGB-Index Chroma-Key Processing|
||KR[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.60 Alpha Blending Control Register 9 (Graphics 0) (GR0_AB9)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||GR0_CK_A[7:0]||||||||GR0_CK_G[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||GR0_CK_B[7:0]||||||||GR0_CK_R[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR0_CK_A|0|R/W|Replaced Alpha Signal after RGB-Index Chroma-Key Processing|
||[7:0]|||α: Unsigned 8 bits (0 to 255 [LSB])|
|||||Note: These bits should always be set to 255 to display the current|
|||||graphics only.|
|23 to 16|GR0_CK_G|0|R/W|Replaced G Signal after RGB-Index Chroma-Key Processing|
||[7:0]|||G: Unsigned 8 bits (0 to 255 [LSB])|
|15 to 8|GR0_CK_B|0|R/W|Replaced B Signal after RGB-Index Chroma-Key Processing|
||[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|7 to 0|GR0_CK_R|0|R/W|Replaced R Signal after RGB-Index Chroma-Key Processing|
||[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.61 Alpha Blending Control Register 10 (Graphics 0) (GR0_AB10)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||GR0_A0[7:0]||||||||GR0_G0[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||GR0_B0[7:0]||||||||GR0_R0[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR0_A0|0|R/W|CLUT1α0 Signal|
||[7:0]|||Replaced withαsignal when in the CLUT1 format and CLUT1 = 0.|
|||||Replaced withαsignal when in theαRGB1555/RGBα5551 format andα=|
|||||0.|
|||||Note: These bits should always be set to 255 to display the current|
|||||graphics only.|
|23 to 16|GR0_G0|0|R/W|CLUT1 G0 Signal|
||[7:0]|||Replaced with G signal when in the CLUT1 format and CLUT1 = 0.|
|15 to 8|GR0_B0|0|R/W|CLUT1 B0 Signal|
||[7:0]|||Replaced with B signal when in the CLUT1 format and CLUT1 = 0.|
|7 to 0|GR0_R0|0|R/W|CLUT1 R0 Signal|
||[7:0]|||Replaced with R signal when in the CLUT1 format and CLUT1 = 0.|

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.62 Alpha Blending Control Register 11 (Graphics 0) (GR0_AB11)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||GR0_A1[7:0]||||||||GR0_G1[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||GR0_B1[7:0]||||||||GR0_R1[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR0_A1|0|R/W|CLUT1 α1 Signal|
||[7:0]|||Replaced withαsignal when in the CLUT1 format and CLUT1 = 1.|
|||||Replaced withαsignal when in theαRGB1555/RGBα5551 format andα|
|||||= 1.|
|||||Note: These bits should always be set to 255 to display the current|
|||||graphics only.|
|23 to 16|GR0_G1|0|R/W|CLUT1 G1 Signal|
||[7:0]|||Replaced with G signal when in the CLUT1 format and CLUT1 = 1.|
|15 to 8|GR0_B1|0|R/W|CLUT1 B1 Signal|
||[7:0]|||Replaced with B signal when in the CLUT1 format and CLUT1 = 1.|
|7 to 0|GR0_R1|0|R/W|CLUT1 R1 Signal|
||[7:0]|||Replaced with R signal when in the CLUT1 format and CLUT1 = 1.|

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.63 Background Color Control Register (Graphics 0) (GR0_BASE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|||GR0_BASE_G[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GR0_BASE_B[7:0]||||||||GR0_BASE_R[7:0]|||||||
|Initial value:|1|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|24|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|23|to|16|GR0_BASE_|0|R/W|Background Color G/Y Signal|
||||G[7:0]|||G/Y: Unsigned 8 bits (0 to 255 [LSB])|
|15|to|8|GR0_BASE_|128|R/W|Background Color B/Cb Signal|
||||B[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|||||||Cb: 8 bits; 128 offset binary; unsigned (0 to 255 [LSB])|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|7 to 0|GR0_BASE_|128|R/W|Background Color R/Cr Signal|
||R[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|
|||||Cr: 8 bits; 128 offset binary; unsigned (0 to 255 [LSB])|

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.2.64 CLUT Table Control Register (Graphics 0) (GR0_CLUT)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||GR0_||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|CLT_SEL||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|17|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|16|||GR0_CLT_SEL|0|R/W|CLUT Table Select Signal|
|||||||0: Selects CLUT table 0.|
|||||||Referring to the CLUT table 0 value to expand toαRGB8888|
|||||||The CPU side can read-access or write-access to the CLUT table 1.|
|||||||1: Selects CLUT table 1.|
|||||||Referring to the CLUT table 1 value to expand toαRGB8888|
|||||||The CPU side can read-access or write-access to the CLUT table 0.|
|15|to|0|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

Note: This register is updated when the GR0_P_VEN bit in the graphics 0 register update control register (GR0_UPDATE) is 1.

## 31.3 Usage Method

## 31.3.1 Scaling Setting Example for 525i Video Input and VGA-Size (640 x 480) Video Output

## (1) Angles of View for Input and Output

This section describes an example of setting the signals of the input and output angles of view shown in Table 31.40 .

Here, the over-scan rate is assumed to be 100%.

**Table 31.40 Input and Output Angles for 525i Video Input and VGA-Size (640 x 480) Video Output**

|**Input**|**Signal**|**Output Signal**|**Signal Format**|**Rotation**|**Buffer Planes**|**Scaling Filter**|
|---|---|---|---|---|---|---|
|1440|× 240|640 × 480|YCbCr|Normal|Two planes|2-tap linear|

**==> picture [454 x 167] intentionally omitted <==**

**----- Start of picture text -----**<br>
Frame<br>buffer<br>Internal bus write Internal bus read<br>control block control block<br>Bit reduction block Data expansion block<br>Scale-down control<br>block<br>Input<br>controller Image<br>Scale-up control Moving picture Enable signal<br>Sync control block block synthesizing block generation quality<br>improver<br>Video image signal<br>Sync signal<br>**----- End of picture text -----**<br>

**Figure 31.18 Signal Paths for Displaying Input Video Image**

## (2) Horizontal Scaling (Horizontal Scale Down, Scaling Filter: 2-Tap Linear)

- The scaling rate for folding can be calculated as shown below.

RATIO_org = round (1440 ÷ 640 × 4096) = 9216

σ = (9216 × (640 − 1) − (1440 − 1) × 4096) ÷ (640 − 1) = −8.01

Horizontal scaling ratio = roundup (9216 − (−8.01)) = 9225

## (3) Vertical Scaling (Vertical Scale Up, Scaling Filter: 2-Tap Linear)

- The scaling rate for folding can be calculated as shown below.

RATIO_org = round (240 ÷ 480 × 4096) = 2048

σ = (2048 × (480 − 1) − (240 − 1) × 4096) ÷ (480 − 1) = 4.27

Vertical scaling ratio = round (2048 − (4.07)) = 2044

## (4) Setting Frame Buffer Access Area

Since video data is written to the frame buffer after scaled down, the write size is 640 × 240 pixels.

The frame buffer area required is 640 pixels or more for line offset and line offset × 240 pixels or more for frame offset.

Here, the frame buffer work area is assumed to be 1024 × 256 pixels.

**==> picture [241 x 162] intentionally omitted <==**

**----- Start of picture text -----**<br>
Image area<br>640<br>Number of pixels in horizontal<br>direction<br>At least 640 pixels are necessary<br>for the buffer area.<br>Line offset address<br>Frame buffer work area<br>240<br>vertical direction<br>Number of lines in for the buffer area.<br>Frame offset address<br>At least 240 lines are necessary<br>**----- End of picture text -----**<br>

**Figure 31.19 Frame Buffer Access Area Setting**

Since the frame buffer is accessed in 64-bit units, YCbCr422 (16 bits) is accessed in 4-pixel units.

The line offset address values to be set are:

SC_RES_LN_OFF[14:0] = 1024 × 2 = 2048

GR_LN_OFF[14:0] = 1024 × 2 = 2048

The frame offset address values to be set are:

SC_RES_FLM_OFF[22:0] = SC_RES_LN_OFF[14:0] × 256 = 524288

GR_FLM_OFF[22:0] = GR_LN_OFF[14:0] × 256 = 524288

## (5) Register Setting Example

**Table 31.41 Register Setting Example for 525i Video Input and VGA-Size Video Output**

|**Register Name**|**Bit Name**|**Settings**|**Remarks**|
|---|---|---|---|
|||**Synchronization Control**||
|SC_SCL0_FRC3|SC_RES_VS_SEL|0|External Vsync selected|
|SC_SCL0_FRC4|SC_RES_FH[10:0]|799|Horizontal period width of output signal|
||||(period width = set value + 1)|
|||**Size of Angle of View**||
|SC_SCL0_DS2|SC_RES_VS[10:0]|15|Vertical capture start position of input signal|
|SC_SCL0_DS2|SC_RES_VW[10:0]|240|Vertical capture width of input signal|
|SC_SCL0_DS3|SC_RES_HS[10:0]|244|Horizontal capture start position of input signal|
|SC_SCL0_DS3|SC_RES_HW[10:0]|1440|Horizontal capture width of input signal|
|SC_SCL0_FRC6|SC_RES_F_VS[10:0]|35|Vertical valid start position of full screen|
|SC_SCL0_FRC6|SC_RES_F_VW[10:0]|480|Vertical valid width of full screen|
|SC_SCL0_FRC7|SC_RES_F_HS[10:0]|144|Horizontal valid start position of full screen|
|SC_SCL0_FRC7|SC_RES_F_HW[10:0]|640|Horizontal valid width of full screen|
|SC_SCL0_US2|SC_RES_P_VS[10:0]|35|Vertical valid start position of output image|
|SC_SCL0_US2|SC_RES_P_VW[10:0]|480|Vertical valid width of output image|
|SC_SCL0_US3|SC_RES_P_HS[10:0]|144|Horizontal valid start position of output image|
|SC_SCL0_US3|SC_RES_P_HW[10:0]|640|Horizontal valid width of output image|
|||**Scaling Setting**||
|SC_SCL0_DS4|SC_RES_DS_H_RATIO|9224|Horizontal scaling-down because SC_RES_DS_H_RATIO is|
||[15:0]||equal to or larger than 4096|
|SC_SCL0_DS1|SC_RES_DS_H_ON|1|Horizontal scaling-down on|
|SC_SCL0_US1|SC_RES_US_H_ON|0|Horizontal scaling-up off|
|SC_SCL0_US5|SC_RES_US_H_RATIO|4096|Horizontal scaling-up off because SC_RES_US_H_RATIO is|
||[15:0]||equal to or larger than 4096|
|SC_SCL0_DS1|SC_RES_DS_V_ON|0|Vertical scaling-down off|
|SC_SCL0_US1|SC_RES_US_V_ON|1|Vertical scaling-up on|
|SC_SCL0_DS6|SC_RES_V_RATIO[15:0]|2044|Vertical scaling-up because SC_RES_V_RATIO is smaller than|
||||4096|
|SC_SCL0_DS7|SC_RES_OUT_VW[10:0]|240|Vertical valid input width because the vertical scaling-down|
||||function is off|
|SC_SCL0_DS7|SC_RES_OUT_HW[10:0]|640|Horizontal image size after horizontal scaling-down|
|SC_SCL0_US4|SC_RES_IN_VW[10:0]|240|Vertical width of frame buffer read|
|SC_SCL0_US4|SC_RES_IN_HW[10:0]|640|Horizontal width of frame buffer read|
|||**IP Conversion Setting**||
|SC_SCL0_DS5|SC_RES_TOP_|2048|Top field adjusted by 0.5-line phase|
||INIPHASE[11:0]|||
|SC_SCL0_DS5|SC_RES_BTM_|0|No phase adjustment for bottom field|
||INIPHASE[11:0]|||
|SC_SCL0_FRC5|SC_RES_FLD_DLY_SEL|1|IP conversion with two planes of frame buffer used for vertical|
||||scaling-up|
|||**Frame Buffer Write Setting**||
|SC_SCL1_WR1|SC_RES_DS_WR_MD|0|Normal write mode for rotation control|
||[2:0]|||
|SC_SCL1_WR1|SC_RES_MD[1:0]|0|Frame buffer write format  YCbCr422 (16 bits)|
|SC_SCL1_WR2|SC_RES_BASE[31:0]|0|Frame buffer write start address (0 in setting example)|
|SC_SCL1_WR3|SC_RES_LN_OFF[14:0]|2048|Frame buffer write line offset|

**Table 31.41 Register Setting Example for 525i Video Input and VGA-Size Video Output**

|**Register Name**|**Bit Name**|**Settings**|**Remarks**|
|---|---|---|---|
|SC_SCL1_WR3|SC_RES_FLM_NUM[9:0]|1|Two planes of frame buffer used|
|SC_SCL1_WR4|SC_RES_FLN_OFF[22:0]|524288|Frame buffer write frame offset|
|SC_SCL1_WR5|SC_RES_WENB|1|Frame buffer write enabled|
||**Frame Buffer Read Setting**|||
|GR_FLM1|GR_FLM_SEL[1:0]|0|Frame number for frame buffer write output|
|GR_FLM2|GR_BASE[31:0]|0|Conforming to frame buffer write setting|
|GR_FLM3|GR_LN_OFF[14:0]|2048|Conforming to frame buffer write setting|
|GR_FLM4|GR_FLM_OFF[22:0]|524288|Conforming to frame buffer write setting|
|GR_FLM6|GR_FORMAT[3:0]|8|Frame buffer read format YCbCr422|
|GR_FLM_RD|GR_R_ENB|1|Frame buffer read enabled|
|GR_FLM6|GR_CNV444_MD|1|Mean value interpolation in YCbCr422→ YCbCr444 conversion|
|||**Scaling-up Selection**||
|SC_SCL0_US8|SC_RES_IBUS_SYNC_SEL|0|Scaled-up video signal displayed|
|GR_AB1|GR_DISP_SEL[1:0]|1|Scaling display selected|

## 31.3.2 Scaling Setting Example for Graphics Display

## (1) Angle of View for Graphics Display

This section describes an example of setting the signals of the input and output angles of view shown in Table 31.42 .

**Table 31.42 Input and Output Angles of View for Graphics Display**

**==> picture [483 x 251] intentionally omitted <==**

**----- Start of picture text -----**<br>
Graphics Size Output Signal Graphics Signal Format<br>640 × 480 640 × 480 RGB888<br>Frame<br>buffer<br>Internal bus read<br>control block<br>Data expansion block<br>Image<br>Scale-up control Moving picture Enable signal<br>Sync control block block synthesizing block generation quality<br>improver<br>Video image signal<br>Sync signal<br>**----- End of picture text -----**<br>

**Figure 31.20 Signal Paths for Graphics Display**

## (2) Setting Frame Buffer Access Area

In the frame buffer in which graphics data is stored, graphics data needs to be expanded in the area of 640 × 480 pixels or larger.

Here, the frame buffer area in which graphics data is expanded is assumed to be 640 × 480 pixels.

Since the frame buffer is accessed in 64-bit units, RGB888 (32 bits) is accessed in 2-pixel units.

The line offset address values to be set are:

GR_LN_OFF[14:0] = 640 × 4 = 2560

The frame offset address values to be set are:

GR_FLM_OFF[22:0] = GR_LN_OFF[14:0] × 480 = 1228800

## (3) Register Setting Example

**Table 31.43 Register Setting Example for Graphics Display**

|**Register Name**|**Bit Name**|**Settings**|**Remarks**|
|---|---|---|---|
|||**Synchronization Control**||
|SC_SCL0_FRC3|SC_RES_VS_SEL|1|Free-running Vsync selected (when the appropriate input|
||||signal is available, an external sync can also be selected)|
|SC_SCL0_FRC4|SC_RES_FV[10:0]|524|Vertical period width of output signal (period width = set|
||||value + 1)|
|SC_SCL0_FRC4|SC_RES_FH[10:0]|799|Horizontal period width of output signal|
||||(period width = set value + 1)|
|||**Size of Angle of View**||
|SC_SCL0_FRC6|SC_RES_F_VS[10:0]|35|Vertical valid start position of full screen|
|SC_SCL0_FRC6|SC_RES_F_VW[10:0]|480|Vertical valid width of full screen|
|SC_SCL0_FRC7|SC_RES_F_HS[10:0]|144|Horizontal valid start position of full screen|
|SC_SCL0_FRC7|SC_RES_F_HW[10:0]|640|Horizontal valid width of full screen|
|GR_AB2|GR_GRC_VS[10:0]|35|Vertical valid start position of graphics output|
|GR_AB2|GR_GRC_VW[10:0]|480|Vertical valid width of graphics output|
|GR_AB3|GR_GRC_HS[10:0]|144|Horizontal valid start position of graphics output|
|GR_AB3|GR_GRC_HW[10:0]|640|Horizontal valid width of graphics output|
|||**Frame Buffer Read Setting**||
|GR_FLM1|GR_FLM_SEL[1:0]|1|Frame number setting with register|
|GR_FLM3|GR_FLM_NUM[9:0]|0|Frame number of frame buffer (0 in setting example)|
|GR_FLM5|GR_FLM_LNUM[9:0]|479|Number of graphics lines (number of lines = set value + 1)|
|GR_FLM6|GR_HW[9:0]|639|Horizontal valid width of graphics (valid width = set value|
||||+ 1)|
|GR_FLM2|GR_BASE[31:0]|0|Conforming to graphics expansion setting (0 in setting|
||||example)|
|GR_FLM3|GR_LN_OFF[14:0]|2560|Conforming to graphics expansion setting|
|||**Frame Buffer Read Setting**||
|GR_FLM4|GR_FLM_OFF[22:0]|1228800|Conforming to graphics expansion setting|
|GR_FLM6|GR_FORMAT[3:0]|1|Frame buffer read format RGB888|
|GR_FLM_RD|GR_R_ENB|1|Frame buffer read enabled|

**Table 31.43 Register Setting Example for Graphics Display**

|**Register Name**|**Bit Name**|**Settings**|**Remarks**|
|---|---|---|---|
|||Scaling-up Selection||
|SC_SCL0_US8|SC_RES_IBUS_SYNC|1|Graphics output displayed|
||_SEL|||
|GR_AB1|GR_DISP_SEL[1:0]|2|Graphics display selected|

## 31.3.3 Scaling Setting Example for Scaled-up Graphics Display

## (1) Angles of View for Input and Output

This section describes an example of setting the signals of the input and output angles of view shown in Table 31.44 .

**Table 31.44 Input and Output Angles of View for Scaled-up Graphics Display**

**==> picture [483 x 240] intentionally omitted <==**

**----- Start of picture text -----**<br>
Graphics Size Output Signal Graphics Signal Format<br>640 × 480 800 × 600 RGB565<br>Frame<br>buffer<br>Internal bus read<br>control block<br>Data expansion block<br>Image<br>Scale-up control Moving picture Enable signal<br>Sync control block block synthesizing block generation quality<br>improver<br>Video image signal<br>Sync signal<br>**----- End of picture text -----**<br>

**Figure 31.21 Signal Paths for Scaled-up Graphics Display**

## (2) Horizontal Scaling (Horizontal Scale Up, Scaling Filter: 2-Tap Linear)

The scaling rate for folding can be calculated as shown below.

RATIO_org = round (640 ÷ 800 × 4096) = 3277 σ = (3277 × (800 − 1) − (640 − 1) × 4096) ÷ (800 − 1) = 1.23

Horizontal scaling ratio = round (3277 − (1.23)) = 3276

## (3) Vertical Scaling (Vertical Scale Up, Scaling Filter: 2-Tap Linear)

- The scaling rate for folding can be calculated as shown below.

RATIO_org = round (480 ÷ 600 × 4096) = 3277

σ = (3277 × (600 − 1) − (480 − 1) × 4096) ÷ (600 − 1) = 1.57

Vertical scaling ratio = round (3277 − (1.57)) = 3275

## (4) Setting Frame Buffer Access Area

In the frame buffer in which graphics data is stored, graphics data needs to be expanded in the area of 640 × 480 pixels or larger.

Here, the frame buffer area in which graphics data is expanded is assumed to be 640 × 480 pixels.

Since the frame buffer is accessed in 64-bit units, RGB565 (16 bits) is accessed in 4-pixel units.

The line offset address values to be set are:

GR_LN_OFF[14:0] = 640 × 2 = 1280

The frame offset address values to be set are:

GR_FLM_OFF[22:0] = GR_LN_OFF[14:0] × 480 = 614400

## (5) Register Setting Example

**Table 31.45 Register Setting Example for Scaled-up Graphics Display**

|**Register Name**|**Bit Name**|**Settings**|**Remarks**|
|---|---|---|---|
||**Synchronization Control**|||
|SC_SCL0_FRC3|SC_RES_VS_SEL|1|Free-running Vsync selected (when the appropriate|
||||input signal is available, an external sync can also be|
||||selected)|
|SC_SCL0_FRC4|SC_RES_FV[10:0]|668|Vertical period width of output signal (period width = set|
||||value + 1)|
|SC_SCL0_FRC4|SC_RES_FH[10:0]|1040|Horizontal period width of output signal|
||||(period width = set value + 1)|
||**Size of Angle of View**|||
|SC_SCL0_FRC6|SC_RES_F_VS[10:0]|27|Vertical valid start position of full screen|
|SC_SCL0_FRC6|SC_RES_F_VW[10:0]|600|Vertical valid width of full screen|
|SC_SCL0_FRC7|SC_RES_F_HS[10:0]|216|Horizontal valid start position of full screen|
|SC_SCL0_FRC7|SC_RES_F_HW[10:0]|800|Horizontal valid width of full screen|
|SC_SCL0_US2|SC_RES_P_VS[10:0]|27|Vertical valid start position of image output|
|SC_SCL0_US2|SC_RES_P_VW[10:0]|600|Vertical valid width of image output|
|SC_SCL0_US3|SC_RES_P_HS[10:0]|216|Horizontal valid start position of image output|
|SC_SCL0_US3|SC_RES_P_HW[10:0]|800|Horizontal valid width of image output|
|||**Scaling Setting**||
|SC_SCL0_US5|SC_RES_US_H_RATIO[15:0]|3276|Horizontal scaling-up because|
||||SC_RES_US_H_RATIO is smaller than 4096|
|SC_SCL0_DS6|SC_RES_V_RATIO[15:0]|3275|Vertical scaling-up because SC_RES_V_RATIO is|
||||smaller than 4096|
|SC_SCL0_US1|SC_RES_US_H_ON|1|Horizontal scaling-up on|
|SC_SCL0_US1|SC_RES_US_V_ON|1|Vertical scaling-up on|
|SC_SCL0_US4|SC_RES_IN_VW[10:0]|480|Vertical width of frame buffer read|
|SC_SCL0_US4|SC_RES_IN_HW[10:0]|640|Horizontal width of frame buffer read|
||**Frame Buffer Read Setting**|||
|GR_FLM1|GR_FLM_SEL[1:0]|1|Frame number setting with register|
|GR_FLM3|GR_FLM_NUM[9:0]|0|Frame number of frame buffer (0 in setting example)|
|GR_FLM2|GR_BASE[31:0]|0|Conforming to graphics expansion setting (0 in setting|
||||example)|
|GR_FLM3|GR_LN_OFF[14:0]|1280|Conforming to graphics expansion setting|
|GR_FLM4|GR_FLM_OFF[22:0]|614400|Conforming to graphics expansion setting|
|GR_FLM6|GR_FORMAT[3:0]|0|Frame buffer read format RGB565|
|GR_FLM_RD|GR_R_ENB|1|Frame buffer read enabled|
|||**Scaling-up Selection**||
|SC_SCL0_US8|SC_RES_IBUS_SYNC_SEL|0|Scaled-up video signal displayed|
|GR_AB1|GR_DISP_SEL[1:0]|1|Scaling display selected|
