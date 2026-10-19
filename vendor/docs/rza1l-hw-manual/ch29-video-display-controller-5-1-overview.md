# 29. Video Display Controller 5 (1): Overview

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1579–1586. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 29.1 Features

The video display controller 5 consists of the following six blocks. For the image synthesis, one plane of video image + two graphics planes, or three graphics planes can be selected.

1. Input controller: Input video image selection, sync signal adjustment, horizontal noise reduction, and brightness adjustment, gain adjustment, and YCbCr ↔ GBR conversion using a color matrix

2. Scaler: Scale up, scale down, and rotation of input video images using the frame buffer, and repeated recording of the specified number of fields in the frame buffer

3. Image quality improver: Black stretch, LTI/sharpness, and YCbCr ↔ GBR conversion using a color matrix

4. Image synthesizer: Synthesis of one plane of video image + two graphics planes, or three graphics planes

5. Output controller: Brightness/contrast adjustment, gamma correction, dither processing, output format conversion, control signal output for TFT-LCD panel

6. System controller: Interrupt control, panel clock control, CLUT table select signal status flag output

The functions of video display controller 5 are listed in Table 29.1 .

**Table 29.1 Features of Video Display Controller 5**

|**Item**|**Function**|
|---|---|
|Operating frequency|Video input clock: 87 MHz or less (for RGB/YCbCr video image)|
||Panel clock: 87 MHz or less (depends on the panel specifications)|
|Input video image|8-bit input conforming to ITU-R BT.656 standard (27 MHz, interlace signal)|
|specification|8-bit input conforming to ITU-R BT.656 extended standard (54 MHz, progressive signal)*1|
||8-bit input conforming to ITU-R BT.601 extended standard (27 MHz, interlace signal)*1|
||8-bit input conforming to ITU-R BT.601 extended standard (54 MHz, progressive signal)*1|
||16-bit input conforming to ITU-R BT.601 extended standard (13.5 MHz, interlace signal)*1|
||Digital pin input: YCbCr422, YCbCr444, RGB888, RGB666, and RGB565 video image|
||Digital pin input size:|
||Maximum input video image size to be set*2: 1440 pixels × 1024 lines (horizontal × vertical)|
||Notes:1. The ITU-R BT.656 and 601 standards do not include the description regarding the progressive|
||signal. The ITU-R BT.601 standard does not include the description regarding the connection|
||interface.|
||2. Depends on the AC characteristics of the connected device.|
||Examples of input video image size:|
||XGA (1024 × 768), SVGA (800 × 600), WVGA (800 × 480), VGA (640 × 480), WQVGA (480 × 240),|
||QVGA in landscape (320 × 240), QVGA in portrait (240 × 320)|
|Video image recording|Storing the video image in the YCbCr422/YCbCr444/RGB565/RGB888 format at a rate of 1/1, 1/2, 1/4, or|
|function|1/8 field.|
||Maximum video image size to be stored: ×1 size of input video image|
|Video image quality|Contrast adjustment, brightness adjustment, horizontal noise reduction, black stretch, LTI/sharpness|
|adjustment function||
|Video image scaling|Vertical: ×1/8 to ×8, linear/hold interpolation|
|processing|Horizontal: ×1/8 to ×8, linear/hold interpolation|
||IP conversion can be performed by adjusting the initial phase.|
|Video image rotation|0/90/180/270 degree rotation in the YCbCr422/RGB565 format|
|function|Horizontal mirroring in the YCbCr422/YCbCr444/RGB565/RGB888 format|

**Table 29.1 Features of Video Display Controller 5**

|**Item**|**Function**|
|---|---|
|Graphics|Number of graphic planes: Three planes (graphics 0, graphics 2, and graphics 3)<br>Supported pixel formats:<br>- RGB565 progressive format (α: none, R: 5 bits, G: 6 bits, B: 5 bits; 16 bits in total)<br>- RGB888 progressive format (α: none, R: 8 bits, G: 8 bits, B: 8 bits; 24 bits in total)<br>-αRGB1555 progressive format (α: 1 bit, R: 5 bits, G: 5 bits, B: 5 bits; 16 bits in total)<br>-αRGB4444 progressive format (α: 4 bits, R: 4 bits, G: 4 bits, B: 4 bits; 16 bits in total)<br>-αRGB8888 progressive format (α: 8 bits, R: 8 bits, G: 8 bits, B: 8 bits; 32 bits in total)<br>- RGBα5551 progressive format (R: 5 bits, G: 5 bits, B: 5 bits,α: 1 bit; 16 bits in total)<br>- RGBα8888 progressive format (R: 8 bits, G: 8 bits, B: 8 bits,α: 8 bits; 32 bits in total)<br>- CLUT8 progressive format (CLUT: 8 bits)<br>- CLUT4 progressive format (CLUT: 4 bits)<br>- CLUT1 progressive format (CLUT: 1 bits)<br>- YCbCr422 progressive format (Y: 8 bits, Cb/Cr: 8 bits; 16 bits in total) (only for graphics 0)<br>- YCbCr444 progressive format (Y: 8 bits, Cb/Cr: 8 bits; 16 bits in total) (only for graphics 0)<br>Maximum image size to be read: 1440 pixels × 1440 lines (horizontal × vertical)|
|Graphics function|Alpha blending in rectangular area: Mixes images according to transparency rateαin the specified area<br>(fade-in and fade-out functions are available.)<br>Chroma-key: Mixes images using the specified RGB color and CLUT value according to transparency rateα.<br>Alpha blending in one pixel units: Mixes images according to transparency rateαwhen the target graphics<br>image is in theαRGB1555,αRGB4444,αRGB8888, RGBα5551,<br>RGBα8888, or CLUT8/4/1 format.|
||For each dot, the priority among theαvalues of the above functions is as follows:<br>Alpha blending in rectangular area > Chroma-key > Alpha blending in one pixel units|
|Output video image<br>size|Maximum output video image size to be set*: 1999 pixels × 2035 lines (horizontal × vertical)<br>Note: * Depends on the AC characteristics of the display panel.<br>Examples of output video image size:<br>XGA (1024 × 768)<br>SVGA (800 × 600), WVGA (800 × 480),<br>VGA (640 × 480), WQVGA (480 × 240),<br>QVGA size in landscape (320 × 240)<br>QVGA size in portrait (240 × 320)|
|Output video image<br>format|RGB888 progressive video output (24-bit parallel output)<br>RGB666 progressive video output (18-bit parallel output)<br>RGB565 progressive video output (16-bit parallel output)<br>RGB888 progressive video output (8-bit serial output)|
|Panel output<br>adjustment|Panel brightness/contrast adjustment, RGB gamma correction, dither processing, output format conversion|
|Sync signal output|Control signal output for the TFT-LCD panel|
|Interrupt output|Vsync signal for video image input/output<br>Line interrupt output (can be output on a desired line.)<br>Erroneous Vsync cycle detection signal for video input<br>Field write completion signal<br>Overflow/underflow signal for the internal buffer|

## 29.2 Block Diagram

Figure 29.1 to Figure 29.3 show the entire block diagram of this module.

**==> picture [456 x 183] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>Internal graphics bus (IV3-BUS)<br>Internal graphics bus (IV1-BUS)<br>Internal bus write<br>control Internal bus<br>Bit reduction read control (0) To the middle<br>Data expansion (0) stage<br>Vertical scale down Vertical scale up<br>DV_DATA 23 to DV_DATA 0 Horizontal scale down Horizontal scale up Output selection synthesizerImage<br>DV_HSYNCDV_VSYNC Image quality  Scaling-down control block Scaling-up control block<br>DV_CLK improver block Graphics block (0)<br>Synchronization control block<br>Input control  block Image quality<br>Scaler block 0 improver block 0<br>* The width of each internal graphics bus is 64 bits.<br>Color matrix<br>External input block Horizontal noise reduction Black stretch LTI/Sharpness Color matrix<br>Sync signal adjustment block<br>**----- End of picture text -----**<br>

**Figure 29.1 Video Display Controller 5 Former Stage Block Diagram**

**==> picture [223 x 168] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>Internal graphics bus (IV6-BUS)<br>Internal graphics bus (IV5-BUS)<br>Previous<br>stage<br>Scaler block 0 Internal bus Internal bus<br>VIN read control (2) read control (3)<br>synthe-sizer Data expansion (2) Data expansion (3) To thelatter stage<br>Output<br>α blending (2) α blending (3) control block<br>Graphics block (2) Graphics block (3)<br>Image synthesizer<br>**----- End of picture text -----**<br>

**==> picture [117 x 6] intentionally omitted <==**

**----- Start of picture text -----**<br>
* The width of each internal graphics bus is 64 bits.<br>**----- End of picture text -----**<br>

**Figure 29.2 Video Display Controller 5 Middle Stage Block Diagram**

**==> picture [194 x 197] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>Interrupt control<br>Clock control LCD_CLK<br>System control block<br>LCD_DATA 23<br>Middle stage to<br>Output image  LCD_DATA 0<br>generator<br>LCD_TCON 6<br>to<br>LCD_TCON0<br>Output control block<br>Output I/F<br>adjustment<br>Brightness/contrast Gamma correction Dither processing<br>LCD TCON<br>**----- End of picture text -----**<br>

**Figure 29.3 Video Display Controller 5 Latter Stage Block Diagram**

## 29.3 Input/Output Pins

Table 29.2 shows the pin configuration.

## **Table 29.2 Input/Output Pins**

|**Symbol**|**I/O**|**Pin Name**|**Function**|
|---|---|---|---|
|DV0_CLK|Input|External input clock 0|External input 0 clock pin|
|DV0_VSYNC|Input|External input Vsync 0|External input 0 Vsync signal pin|
|DV0_HSYNC|Input|External input Hsync 0|External input 0 Hsync signal pin|
|DV0_DATA 23 to DV0_DATA 0|Input|External input video image data 0|External input 0 video image data pin|
|LCD0_CLK|Output|Panel clock 0|Panel output 0 clock pin|
|LCD0_DATA 23 to LCD0_DATA 0|Output|Video image data 0 for panel|Panel output 0 video image data pin|
|LCD0_TCON 6 to LCD0_TCON 0|Output|Control signal 0 for panel|Panel output 0 timing control pin|
|LCD0_EXTCLK|Input|Panel clock source 0|Panel clock source 0 input pin|

## 29.4 Clocks

There are two clocks to be mainly used by the video display controller 5: the video image clock and pixel clock.

The video image clock is used while the video image is processed in the input controller, passed to the scale-down control block in the scaler, and then written to the buffer (internal bus write control). The DV_CLK clock is used as the video image clock.

The pixel clock is used in graphics read-out processing by the scaler (internal bus read controller) through output controller processing. When the parallel RGB output is selected in the output controller, the frequencies of the pixel clock and panel clock (LCD_CLK) are the same. The panel clock can be selected from the video clock, LCD_EXTCLK, and peripheral bus clock 1 (P1φ) with SYSCNT_PANEL_CLK.PANEL_ICKSEL[1:0] of the system controller. When the serial RGB output (3/4 speed mode) is selected in the output controller, the pixel clock frequency is 1/3 or 1/4 the panel clock (LCD_CLK) frequency.

## 29.5 Hsync and Vsync Signals

Hsync and Vsync signals to be used in the logic stage following the scale-up control block of the scaler are generated by the synchronization control block of the scaler. Since the Hsync and Vsync signals are used as the reference signals for the LCD TCON, which generates various panel driving timings, they are also the reference signals for the control signals (LCD_TCON6 to LCD_TCON0 pins) passed to the panel.

The output Hsync signal always operates at a free-running frequency, and the horizontal period is set with SC_SCL0_FRC4.SC_RES_FH[10:0]. On the other hand, the output Vsync signal is selected from the external input and free-running Vsync signals with SC_SCL0_FRC3.SC_RES_VS_SEL of the scaler.

## 29.5.1 External Input Vsync

## (1) Operation Outline

In this mode, the output Vsync signal is generated according to an external input Vsync signal. When displaying video image input from a digital pin on the panel and the pointer buffer is not in use, always use this mode. However, the output Hsync signal is free running even in this mode. Figure 29.4 shows the timing of external input Vsync signal.

**==> picture [452 x 202] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input Vsync signal<br>(DV_VSYNC pin)<br>SC_SCL0_FRC5.<br>SC_RES_VSDLY[7:0]<br>setting<br>Vsync signal<br>(Scaler output)<br>Hsync signal<br>(Scaler output)<br>Free-running<br>period<br>SC_SCL0_FRC4.<br>SC_RES_FH[10:0] setting<br>**----- End of picture text -----**<br>

**Figure 29.4 External Input Vsync Timing**

## (2) Notes

When Vsync is externally input, generation of the output Vsync signal is based on the external Vsync signal. That is, the output Vsync signal follows the input Vsync signal, so if an unstable Vsync signal is input, the output Vsync signal will also be unstable.

Since the output Hsync signal is generated according to the frequency generated by a free-running clock and the Vsync signal is generated from the video input as a base, the signals will not be in synchronization. This module adjusts the timing between these signals by adjusting the output Vsync signal so that it stays in time with the output Hsync signal. Therefore, even if the input Vsync signal is stable, the timing of the output Vsync signal may be increased or decreased by up to one line to stay in synchronization with the timing of the output Hsync signal.

**==> picture [453 x 132] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input Vsync<br>signal<br>Output after waiting for<br>the horizontal period<br>Output Vsync<br>signal<br>Output Hsync<br>signal<br>**----- End of picture text -----**<br>

**Figure 29.5 Detailed Timing Chart for Generation of the Output Vsync Signal**

## 29.5.2 Free-Running Vsync

## (1) Operation Outline

In this mode, the Vsync signal is generated according to the pixel clock (free running). The vertical period is selected with SC_SCL0_FRC4.SC_RES_FV[10:0]. The output Hsync signal is also free running. Figure 29.6 shows the timing.

**==> picture [445 x 209] intentionally omitted <==**

**----- Start of picture text -----**<br>
SC_SCL0_FRC4.SC_RES_FV[10:0]<br>setting<br>Free-running period<br>Free-running<br>Vsync signal<br>Vsync signal<br>(Scaler output)<br>Hsync signal<br>(Scaler output)<br>Free-running<br>period<br>SC_SCL0_FRC4.SC_RES_FH[10:0]<br>setting<br>**----- End of picture text -----**<br>

**Figure 29.6 Free Running Vsync Timing**

## (2) Pointer Buffers

In free-running vertical synchronization mode, output of the input video image to a panel may lead to flicker in the output video image. This occurs when the input and output vertical sync signals are not in synchronization. To prevent this, use the pointer buffers to adjust the timing between the input and output video images in frame units. If the input Vsync signal is faster than the output Vsync signal, frames from the input video image are skipped in the output image for display. On the other hand, when the input Vsync signal is slower than the output Vsync signal, frames from the input video image are repeated. However, when the difference in timing between the input and output Vsync signals is too large, the pointer buffers cannot deal with the difference, so flicker may occur. As more buffers are used, the pointer buffers can deal with larger differences in frequency.

**==> picture [227 x 261] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input Vsync  Input video  Output Vsync  Output video<br>signal image signal image<br>0<br>1<br>0<br>This frame is skipped.<br>2<br>1<br>3<br>4<br>3<br>5<br>**----- End of picture text -----**<br>

**Figure 29.7 Timing when the Input Vsync Signal is Faster than the Output Vsync Signal**

**==> picture [280 x 259] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input Vsync  Input video  Output Vsync  Output video<br>signal image signal image<br>0<br>0<br>1<br>1<br>2<br>This frame is displayed again.<br>1<br>3<br>2<br>**----- End of picture text -----**<br>

**Figure 29.8 Timing when the Input Vsync Signal is Slower than the Output Vsync Signal**

## 29.5.3 Usage Note on Changing Vsync Signal Selections

When the Vsync signal selection is changed, the output Vsync signal is discontinuous, resulting in disordered panel display. In this case, perform the mute processing according to the panel specification as necessary and change the Vsync signal selection.
