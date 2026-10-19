# 30. Video Display Controller 5 (2): Input Controller

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1587–1634. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

- 30.1 Input Controller Functions

## 30.1.1 Overview of Functions

The input controller performs the on/off control of input supplied via the external input pins, and subjects the signals to synchronization adjustment, horizontal noise reduction, and brightness adjustment, gain adjustment, and YCbCr ↔ GBR conversion using a color matrix.

The functional block diagram of the input controller is shown below.

**==> picture [463 x 261] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI<br>DV_DATA23 to<br>HS,VS,<br>DV_HSYNC,DV_VSYNC,DV_DATA0,DV_CLK, (YCbCr24 bits) YCbCr/RGB888(HS,VS,24 bits) RGB888(24 bits)HS,VS,YCbCr/ YCbCr/RGB888HS,VS,HE,VE,FLD,(24 bits) YCbCr/RGB888HS,VS,HE,VE,FLD,(24 bits) Scaler<br>HS,VS,<br>YCbCr/<br>RGB888<br>(24 bits)<br>INP_SEL<br>Sync signal adjustment  adjustmentImage quality block<br>block<br>Register control<br>INP_FORMAT<br>External input block<br>Register control<br>Input controller<br>BT656/601 interface<br>(TINT)<br>compensation Sync delay adjustment Horizontal NR Color matrix<br>Input control Sync signal phase<br>Vertical sync line delay (1, 2, 3, 4 adjacent pixels)<br>YCbCr444 interface<br>RGB888/666/565, Output selection<br>YCbCr422 interface<br>**----- End of picture text -----**<br>

**Figure 30.1 Functional Block Diagram of Input Controller**

## 30.1.2 Updating Registers of External Signal Input Block and Sync Signal Adjustment Block

The control registers of the external input block and sync signal adjustment block are updated by setting the relevant update control bit to 1.

For the control registers other than the IMGCNT_DRC_REG register of the image quality adjustment block, the update timing is controlled using the Vsync signal.

After 1 is set to the bits in the update control register, the contents of the relevant registers are actually modified at the rising edge of the Vsync signal, when the update control register is automatically cleared to 0.

## **Table 30.1 Register Update Control**

|||**Initial**||
|---|---|---|---|
|**Register Name**|**Bit Name**|**Value**|**Description**|
|INP_UPDATE|INP_EXT_UPDATE|0|External Input Block Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated.|
|INP_UPDATE|INP_IMG_UPDATE|0|Sync Signal Adjustment Block Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated.|
|IMGCNT_UPDATE|IMGCNT_VEN|0|Image Quality Adjustment Block Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync signal.|

## 30.1.3 Controlling Input

The input controller performs the on/off control of input supplied via the external input pins.

## **Table 30.2 Input Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|INP_SEL_CNT|INP_SEL|0|On/Off Control of Input Supplied via External Input Pin|
||||0: Input supplied via the external input pins is off.|
||||1: Input supplied via the external input pins is on.|

## 30.1.4 Controlling Externally Input Video Signals

The externally input video image signals in the YCbCr444, RGB888, RGB666, RGB565, BT656 (extended), BT601 (extended), YCbCr422 (the 16-bit data format of the BT601 standard) formats can be handled.

The BT656 signals can be used for the 525-line and 59.94-Hz (27.0-MHz) or the 625-line and 50.00-Hz (27.0-MHz) interlace signals and for the 525-line and 59.94-Hz (54.0-MHz) or the 625-line and 50.00-Hz (54.0-MHz) BT656extended progressive signals.

The BT601 signals can be used for the 8-bit data line 525-line and 59.94 Hz (27.0-MHz) or the 625-line and 50.00-Hz (27.0-MHz) interlace signals and for the 525-line and 59.94 Hz (54.0-MHz) or the 625-line and 50.00-Hz (54.0-MHz) extended progressive signals.

The YCbCr422 signals can be used for the 16-bit data line 525-line and 59.94-Hz (13.5-MHz) or the 625-line and 50.00Hz (13.5-MHz) BT601 interlace signals.

The above signals can be selected by the INP_FORMAT[2:0] bits. Bit endian change and B/R signal swap are controlled by setting the INP_ENDIAN_ON and INP_SWAP_ON bits.

## **Table 30.3 Externally Input Video Signal Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|INP_SEL_CNT|INP_FORMAT[2:0]|000|External Input Format Select|
||||0: YCbCr444, RGB888|
||||1: RGB666|
||||2: RGB565|
||||3: BT656|
||||4: BT601|
||||5: YCbCr422|
||||6, 7: Setting prohibited|
|INP_EXT_|INP_ENDIAN_ON|0|External Input Bit Endian Change On/Off Control|
|SYNC_CNT|||0: Off|
||||1: On|
|INP_EXT_|INP_SWAP_ON|0|External Input B/R Signal Swap On/Off Control|
|SYNC_CNT|||0: Off|
||||1: On|

## 30.1.5 Selecting Clock Edge for Externally Input Signals

The clock edge for receiving the video image signals, Vsync signals, and Hsync signals is individually selected with the INP_PXD_EDGE, INP_VS_EDGE, INP_HS_EDGE bits.

**Table 30.4 Externally Input Clock Edge Selection**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|INP_SEL_CNT|INP_PXD_EDGE|0|Clock Edge Select for Capturing External Input Video Image|
||||Signals DV_DATA23 to DV_DATA0|
||||0: Rising edge|
||||1: Falling edge|
|INP_SEL_CNT|INP_VS_EDGE|0|Clock Edge Select for Capturing External Input Vsync Signal|
||||DV_VSYNC|
||||0: Rising edge|
||||1: Falling edge|
|INP_SEL_CNT|INP_HS_EDGE|0|Clock Edge Select for Capturing External Input Hsync Signal|
||||DV_HSYNC|
||||0: Rising edge|
||||1: Falling edge|

Figure 30.2 shows the typical input timing of externally input signals.

The input signals can be received at the rising edge of the clock signal DV_CLK when the INP_PXD_EDGE, INP_VS_EDGE, and INP_ES_EDGE bits are 0.

**==> picture [401 x 89] intentionally omitted <==**

**----- Start of picture text -----**<br>
DV_CLK<br>DV_DATA23 to<br>DV_DATA0<br>DV_HSYNC<br>DV_VSYNC<br>**----- End of picture text -----**<br>

**Figure 30.2 Typical Input Timing of Externally Input Signals (Clock Phase)**

## 30.1.6 Externally Input Sync Signal Inversion Control

Inversion of polarity of the Vsync and Hsync signals can be controlled by the INP_VS_INV and INP_HS_INV bits.

## **Table 30.5 Sync Signal Inversion Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|INP_EXT_|INP_VS_INV|0|External Input Vsync Signal DV_VSYNC Inversion|
|SYNC_CNT|||Control|
||||0: Not inverted (positive polarity)|
||||1: Inverted (negative polarity)|
|INP_EXT_|INP_HS_INV|0|External Input Hsync Signal DV_HSYNC Inversion|
|SYNC_CNT|||Control|
||||0: Not inverted (positive polarity)|
||||1: Inverted (negative polarity)|

## 30.1.7 Bit Allocation of Externally Input Video Image Signals

Allocation of the externally input video image signal pins DV_DATA to the signals in each format is described below.

## (1) YCbCr444/RGB888 Input

When the external input is of YCbCr444/RGB888 format, the video image signal pins DV_DATA are allocated to the internal signals Y/GOUT, Cb/BOUT, Cr/ROUT, as shown in Table 30.6 .

**Table 30.6 Bit Allocation of DV_DATA Pin Inputs when the External Input is of YCbCr444/RGB888**

|**INP_FORMAT[2:0]**|**0**|**0**|**0**|**0**|
|---|---|---|---|---|
|**INP_ENDIAN_ON**|**0**|**0**|**1**|**1**|
|**INP_SWAP_ON**|**0**|**1**|**0**|**1**|
|DV_DATA23|Cr/ROUT[7]|Cb/BOUT[7]|Cr/ROUT[0]|Cb/BOUT[0]|
|DV_DATA22|Cr/ROUT[6]|Cb/BOUT[6]|Cr/ROUT[1]|Cb/BOUT[1]|
|DV_DATA21|Cr/ROUT[5]|Cb/BOUT[5]|Cr/ROUT[2]|Cb/BOUT[2]|
|DV_DATA20|Cr/ROUT[4]|Cb/BOUT[4]|Cr/ROUT[3]|Cb/BOUT[3]|
|DV_DATA19|Cr/ROUT[3]|Cb/BOUT[3]|Cr/ROUT[4]|Cb/BOUT[4]|
|DV_DATA18|Cr/ROUT[2]|Cb/BOUT[2]|Cr/ROUT[5]|Cb/BOUT[5]|
|DV_DATA17|Cr/ROUT[1]|Cb/BOUT[1]|Cr/ROUT[6]|Cb/BOUT[6]|
|DV_DATA16|Cr/ROUT[0]|Cb/BOUT[0]|Cr/ROUT[7]|Cb/BOUT[7]|
|DV_DATA15|Y/GOUT[7]|Y/GOUT[7]|Y/GOUT[0]|Y/GOUT[0]|
|DV_DATA14|Y/GOUT[6]|Y/GOUT[6]|Y/GOUT[1]|Y/GOUT[1]|
|DV_DATA13|Y/GOUT[5]|Y/GOUT[5]|Y/GOUT[2]|Y/GOUT[2]|
|DV_DATA12|Y/GOUT[4]|Y/GOUT[4]|Y/GOUT[3]|Y/GOUT[3]|
|DV_DATA11|Y/GOUT[3]|Y/GOUT[3]|Y/GOUT[4]|Y/GOUT[4]|
|DV_DATA10|Y/GOUT[2]|Y/GOUT[2]|Y/GOUT[5]|Y/GOUT[5]|
|DV_DATA9|Y/GOUT[1]|Y/GOUT[1]|Y/GOUT[6]|Y/GOUT[6]|
|DV_DATA8|Y/GOUT[0]|Y/GOUT[0]|Y/GOUT[7]|Y/GOUT[7]|
|DV_DATA7|Cb/BOUT[7]|Cr/ROUT[7]|Cb/BOUT[0]|Cr/ROUT[0]|
|DV_DATA6|Cb/BOUT[6]|Cr/ROUT[6]|Cb/BOUT[1]|Cr/ROUT[1]|
|DV_DATA5|Cb/BOUT[5]|Cr/ROUT[5]|Cb/BOUT[2]|Cr/ROUT[2]|
|DV_DATA4|Cb/BOUT[4]|Cr/ROUT[4]|Cb/BOUT[3]|Cr/ROUT[3]|
|DV_DATA3|Cb/BOUT[3]|Cr/ROUT[3]|Cb/BOUT[4]|Cr/ROUT[4]|
|DV_DATA2|Cb/BOUT[2]|Cr/ROUT[2]|Cb/BOUT[5]|Cr/ROUT[5]|
|DV_DATA1|Cb/BOUT[1]|Cr/ROUT[1]|Cb/BOUT[6]|Cr/ROUT[6]|
|DV_DATA0|Cb/BOUT[0]|Cr/ROUT[0]|Cb/BOUT[7]|Cr/ROUT[7]|

## (2) RGB666 Input

When the external input is of RGB666 format, the video image signal pins DV_DATA are allocated to the internal signals GOUT, BOUT, ROUT as shown in Table 30.7 .

The internal signals GOUT, BOUT, ROUT to which the video image signal pins DV_DATA are allocated are output as a 24-bit video image from the RGB666 interface with the following formulae.

G[7:0] = GOUT[7:2] × 255 ÷ 63

B[7:0] = BOUT[7:2] × 255 ÷ 63

R[7:0] = ROUT[7:2] × 255 ÷ 63

**Table 30.7 Bit Allocation of DV_DATA Pin Inputs When the External Input is of RGB666**

|**INP_FORMAT[2:0]**|**1**|**1**|**1**|**1**|
|---|---|---|---|---|
|**INP_ENDIAN_ON**|**0**|**0**|**1**|**1**|
|**INP_SWAP_ON**|**0**|**1**|**0**|**1**|
|DV_DATA17|ROUT[7]|BOUT[7]|ROUT[2]|BOUT[2]|
|DV_DATA16|ROUT[6]|BOUT[6]|ROUT[3]|BOUT[3]|
|DV_DATA15|ROUT[5]|BOUT[5]|ROUT[4]|BOUT[4]|
|DV_DATA14|ROUT[4]|BOUT[4]|ROUT[5]|BOUT[5]|
|DV_DATA13|ROUT[3]|BOUT[3]|ROUT[6]|BOUT[6]|
|DV_DATA12|ROUT[2]|BOUT[2]|ROUT[7]|BOUT[7]|
|DV_DATA11|GOUT[7]|GOUT[7]|GOUT[2]|GOUT[2]|
|DV_DATA10|GOUT[6]|GOUT[6]|GOUT[3]|GOUT[3]|
|DV_DATA9|GOUT[5]|GOUT[5]|GOUT[4]|GOUT[4]|
|DV_DATA8|GOUT[4]|GOUT[4]|GOUT[5]|GOUT[5]|
|DV_DATA7|GOUT[3]|GOUT[3]|GOUT[6]|GOUT[6]|
|DV_DATA6|GOUT[2]|GOUT[2]|GOUT[7]|GOUT[7]|
|DV_DATA5|BOUT[7]|ROUT[7]|BOUT[2]|ROUT[2]|
|DV_DATA4|BOUT[6]|ROUT[6]|BOUT[3]|ROUT[3]|
|DV_DATA3|BOUT[5]|ROUT[5]|BOUT[4]|ROUT[4]|
|DV_DATA2|BOUT[4]|ROUT[4]|BOUT[5]|ROUT[5]|
|DV_DATA1|BOUT[3]|ROUT[3]|BOUT[6]|ROUT[6]|
|DV_DATA0|BOUT[2]|ROUT[2]|BOUT[7]|ROUT[7]|

## (3) RGB565 Input

When the external input is of RGB565 format, the video image signal pins DV_DATA are allocated to the internal signals GOUT, BOUT, ROUT as shown in Table 30.8 .

The internal signals GOUT, BOUT, ROUT to which the video image signal pins DV_DATA are allocated are output as a 24-bit video image from the RGB565 interface with the following formulae.

## G[7:0] = GOUT[7:2] × 255 ÷ 63

B[7:0] = BOUT[7:3] × 255 ÷ 31

R[7:0] = ROUT[7:3] × 255 ÷ 31

**Table 30.8 Bit Allocation of DV_DATA Pin Inputs When the External Input is of RGB565**

|**INP_FORMAT[2:0]**|**2**|**2**|**2**|**2**|
|---|---|---|---|---|
|**INP_ENDIAN_ON**|**0**|**0**|**1**|**1**|
|**INP_SWAP_ON**|**0**|**1**|**0**|**1**|
|DV_DATA15|ROUT[7]|BOUT[7]|ROUT[3]|BOUT[3]|
|DV_DATA14|ROUT[6]|BOUT[6]|ROUT[4]|BOUT[4]|
|DV_DATA13|ROUT[5]|BOUT[5]|ROUT[5]|BOUT[5]|
|DV_DATA12|ROUT[4]|BOUT[4]|ROUT[6]|BOUT[6]|
|DV_DATA11|ROUT[3]|BOUT[3]|ROUT[7]|BOUT[7]|
|DV_DATA10|GOUT[7]|GOUT[7]|GOUT[2]|GOUT[2]|
|DV_DATA9|GOUT[6]|GOUT[6]|GOUT[3]|GOUT[3]|
|DV_DATA8|GOUT[5]|GOUT[5]|GOUT[4]|GOUT[4]|
|DV_DATA7|GOUT[4]|GOUT[4]|GOUT[5]|GOUT[5]|
|DV_DATA6|GOUT[3]|GOUT[3]|GOUT[6]|GOUT[6]|
|DV_DATA5|GOUT[2]|GOUT[2]|GOUT[7]|GOUT[7]|
|DV_DATA4|BOUT[7]|ROUT[7]|BOUT[3]|ROUT[3]|
|DV_DATA3|BOUT[6]|ROUT[6]|BOUT[4]|ROUT[4]|
|DV_DATA2|BOUT[5]|ROUT[5]|BOUT[5]|ROUT[5]|
|DV_DATA1|BOUT[4]|ROUT[4]|BOUT[6]|ROUT[6]|
|DV_DATA0|BOUT[3]|ROUT[3]|BOUT[7]|ROUT[7]|

## (4) BT656/BT601 Input

When the external input is of BT656 or BT601 format, the video image signal pins DV_DATA are allocated to the internal signal BTOUT, as shown in Table 30.9 .

The internal signal BTOUT to which the video image signal pins DV_DATA are allocated is expanded to the YCbCr signal.

For expansion to the YCbCr signal, see section 30.1.12, BT656/BT601/YCbCr422 Format Setting .

**Table 30.9 Bit Allocation of DV_DATA Pin Inputs When the External Input is of BT656 or BT601**

|**INP_FORMAT[2:0]**|**3 to 4**|**3 to 4**|
|---|---|---|
|**INP_ENDIAN_ON**|**0**|**1**|
|**INP_SWAP_ON**|**0**|**0**|
|DV_DATA7|BTOUT[7]|BTOUT[0]|
|DV_DATA6|BTOUT[6]|BTOUT[1]|
|DV_DATA5|BTOUT[5]|BTOUT[2]|
|DV_DATA4|BTOUT[4]|BTOUT[3]|
|DV_DATA3|BTOUT[3]|BTOUT[4]|
|DV_DATA2|BTOUT[2]|BTOUT[5]|
|DV_DATA1|BTOUT[1]|BTOUT[6]|
|DV_DATA0|BTOUT[0]|BTOUT[7]|

## (5) YCbCr422 Input

When the external input is of YCbCr422 format, the video image signal pins DV_DATA are allocated to the internal signals Y and Cb/Cr, as shown in Table 30.10 .

**Table 30.10 Bit Allocation of DV_DATA Pin Inputs When the External Input is of YCbCr422**

|**INP_FORMAT[2:0]**|**5**|**5**|**5**|**5**|
|---|---|---|---|---|
|**INP_ENDIAN_ON**|**0**|**0**|**1**|**1**|
|**INP_SWAP_ON**|**0**|**1**|**0**|**1**|
|DV_DATA15|Y[7]|Cb/Cr[7]|Y[0]|Cb/Cr[0]|
|DV_DATA14|Y[6]|Cb/Cr[6]|Y[1]|Cb/Cr[1]|
|DV_DATA13|Y[5]|Cb/Cr[5]|Y[2]|Cb/Cr[2]|
|DV_DATA12|Y[4]|Cb/Cr[4]|Y[3]|Cb/Cr[3]|
|DV_DATA11|Y[3]|Cb/Cr[3]|Y[4]|Cb/Cr[4]|
|DV_DATA10|Y[2]|Cb/Cr[2]|Y[5]|Cb/Cr[5]|
|DV_DATA9|Y[1]|Cb/Cr[1]|Y[6]|Cb/Cr[6]|
|DV_DATA8|Y[0]|Cb/Cr[0]|Y[7]|Cb/Cr[7]|
|DV_DATA7|Cb/Cr[7]|Y[7]|Cb/Cr[0]|Y[0]|
|DV_DATA6|Cb/Cr[6]|Y[6]|Cb/Cr[1]|Y[1]|
|DV_DATA5|Cb/Cr[5]|Y[5]|Cb/Cr[2]|Y[2]|
|DV_DATA4|Cb/Cr[4]|Y[4]|Cb/Cr[3]|Y[3]|
|DV_DATA3|Cb/Cr[3]|Y[3]|Cb/Cr[4]|Y[4]|
|DV_DATA2|Cb/Cr[2]|Y[2]|Cb/Cr[5]|Y[5]|
|DV_DATA1|Cb/Cr[1]|Y[1]|Cb/Cr[6]|Y[6]|
|DV_DATA0|Cb/Cr[0]|Y[0]|Cb/Cr[7]|Y[7]|

## 30.1.8 Typical Signal Timing of BT601 Format

Figure 30.3 and Figure 30.4 show the horizontal timings and Figure 30.5 and Figure 30.6 show the vertical timings of the BT601 format.

**==> picture [422 x 220] intentionally omitted <==**

**----- Start of picture text -----**<br>
16:9 or 4:3 at 13.5 MHz<br>625<br>0H<br>Analog line n-1 Analog line n<br>Digital line n-1 Digital line n<br>Digital blanking<br>Luminance samples 12T 132T<br>717 718 719 720 721 730 731 732 733 862 863 0 1 2<br>4:2:2,chroma<br>CR samples<br>359 360 365 366 491 0 1<br>4:2:2,chroma<br>CB samples<br>359 360 365 366 491 0 1<br>T: Luminance sampling period Quoted from ITU-R BT.601-5<br>**----- End of picture text -----**<br>

**Figure 30.3 BT601 Horizontal Timing (625 Lines/50.00 Hz)**

**==> picture [407 x 217] intentionally omitted <==**

**----- Start of picture text -----**<br>
16:9 or 4:3 at 13.5 MHz<br>525<br>0H<br>Analog line n-1 Analog line n<br>Digital line n-1 Digital line n<br>Digital blanking<br>Luminance  16T 122T<br>samples<br>717 718 719 720 721 734 735 736 737 856 857 0 1 2<br>4:2:2,chroma<br>CR samples<br>359 360 367 368 428 0 1<br>4:2:2,chroma<br>CB samples<br>359 360 367 368 428 0 1<br>T: Luminance sampling period Quoted from ITU-R BT.601-5<br>**----- End of picture text -----**<br>

**Figure 30.4 BT601 Horizontal Timing (525 Lines/59.94 Hz)**

**==> picture [393 x 323] intentionally omitted <==**

**----- Start of picture text -----**<br>
TOP (First) field Quoted from ITU-R BT.470-6<br>25H + α<br>2.5H 2.5H 2.5H<br>622 623 624 625 1 2 3 4 5 6 7 23 24<br>BOTTOM field 0V TOP field<br>HS<br>VS<br>FLD<br>BOTTOM (Second) field<br>25H + α<br>2.5H 2.5H 2.5H<br>309 310 311 312 313 314 315 316 317 318 319 320 336 337<br>TOP field 0V BOTTOM field<br>HS<br>VS<br>FLD<br>**----- End of picture text -----**<br>

**Figure 30.5 BT601 Vertical Timing (625 Lines/50.00 Hz)**

**==> picture [406 x 328] intentionally omitted <==**

**----- Start of picture text -----**<br>
TOP (First) field Quoted from ITU-R BT.470-6<br>19 to 21H + α<br>3.0H 3.0H 3.0H<br>525 1 2 3 4 5 6 7 8 9 10 21 22<br>BOTTOM field 0V TOP field<br>HS<br>VS<br>FLD<br>BOTTOM (Second) field<br>19 to 21H + α<br>3.0H 3.0H 3.0H<br>262 263 264 265 266 267 268 269 270 271 272 273 283 284<br>TOP field 0V BOTTOM field<br>HS<br>VS<br>FLD<br>**----- End of picture text -----**<br>

**Figure 30.6 BT601 Vertical Timing (525 Lines/59.94 Hz)**

## 30.1.9 Typical Signal Timing of BT656 Format

Figure 30.7 and Figure 30.8 show the horizontal timings of the BT656 format.

**==> picture [441 x 416] intentionally omitted <==**

**----- Start of picture text -----**<br>
16:9 or 4:3 at 13.5 MHz<br>525<br>0H<br>Analog line n-1 Analog line n<br>Digital line n-1 Digital line n<br>Digital blanking<br>Luminance  12T 132T<br>samples<br>717 718 719 720 721 730 731 732 733 862 863 0 1 2<br>4:2:2,chroma<br>CR samples<br>359 360 365 366 491 0 1<br>4:2:2,chroma<br>CB samples<br>359 360 365 366 491 0 1<br>Replaced by Replaced by Replaced by<br>timing reference digital blanking timing reference<br>signal data signal<br>DV_DATA7<br>to<br>DV_DATA0<br>End of Start of<br>Quoted from<br>active video active video ITU-R BT.656-4,<br>T: Luminance sampling period Timing reference signal ITU-R BT.601-5<br>DV_HSYNC<br>C359B Y718 C359R Y719 C360B Y720 C360R Y721 C366B Y732 C366R Y733 Y861 C419B Y862 C419R Y863 C0B Y0 C0R Y1<br>C359B Y718 C359R Y719 C0B Y0 C0R Y1<br>**----- End of picture text -----**<br>

**Figure 30.7 BT656 Horizontal Timing (625 Lines/50.00 Hz)**

**==> picture [442 x 416] intentionally omitted <==**

**----- Start of picture text -----**<br>
16:9 or 4:3 at 13.5 MHz<br>525<br>0H<br>Analog line n-1 Analog line n<br>Digital line n-1 Digital line n<br>Digital blanking<br>Luminance  16T 122T<br>samples<br>717 718 719 720 721 734 735 736 737 856 857 0 1 2<br>4:2:2,chroma<br>CR samples<br>359 360 367 368 428 0 1<br>4:2:2,chroma<br>CB samples<br>359 360 367 368 428 0 1<br>Replaced by Replaced by Replaced by<br>timing reference digital blanking timing reference<br>signal data signal<br>DV_DATA7<br>to<br>DV_DATA0<br>End of Start of<br>Quoted from<br>active video active video<br>ITU-R BT.656-4,<br>T: Luminance sampling period Timing reference signal ITU-R BT.601-5<br>DV_HSYNC<br>C359B Y718 C359R Y719 C360B Y720 C360R Y721 C368B Y736 C368R Y737 Y855 C428B Y856 C428R Y857 C0B Y0 C0R Y1<br>C359B Y718 C359R Y719 C0B Y0 C0R Y1<br>**----- End of picture text -----**<br>

**Figure 30.8 BT656 Horizontal Timing (525 Lines/59.94 Hz)**

## 30.1.10 SAV/EAV Code in BT656 Format

Table 30.11 shows the timing of inserting the SAV/EAV code in the BT656 format. Bit information is shown in Table 30.12 and Table 30.13 . This module does not refer to the parity bits P3 to P0 shown in Table 30.13 .

**Table 30.11 SAV/EAV Code Insertion Timing (Line)**

|**Table 30.11**<br>**SAV/EAV Code Insertion Timing (Line)**||
|---|---|
||**625**<br>**525**|
|**V-digital field blanking**||
|Field 1|Start<br>(V = 1)<br>Line 624<br>Line 1|
||Finish<br>(V = 0)<br>Line 23<br>Line 20|
|Field 2|Start<br>(V = 1)<br>Line 311<br>Line 264|
||Finish<br>(V = 0)<br>Line 336<br>Line 283|
|**V-digital field blanking**||
|Field 1|F = 0<br>Line 1<br>Line 4|
|Field 2|F = 1<br>Line 313<br>Line 266|

**Table 30.12 SAV/EAV Code Bit Information (1)**

|**Data Bit Number**|**1st Word (FF)**|**2nd Word (00)**|**3rd Word (00)**|**4th Word (XY)**|
|---|---|---|---|---|
|7 (MSB)|1|0|0|1|
|6|1|0|0|F|
|5|1|0|0|V|
|4|1|0|0|H|
|3|1|0|0|P3|
|2|1|0|0|P2|
|1|1|0|0|P1|
|0|1|0|0|P0|

## [Legend]

F = 0 during field 1 F = 1 during field 2 V = 0 elsewhere V = 1 during field blanking H = 0 is SAV H = 1 is EAV

**Table 30.13 SAV/EAV Code Bit Information (2)**

|**F**|**V**|**H**|**P3**|**P2**|**P1**|**P0**|
|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|
|0|0|1|1|1|0|1|
|0|1|0|1|0|1|1|
|0|1|1|0|1|1|0|
|1|0|0|0|1|1|1|
|1|0|1|1|0|1|0|
|1|1|0|1|1|0|0|
|1|1|1|0|0|0|1|

Figure 30.9 and Figure 30.10 show the SAV/EAV code tables.

||||**One Horizontal Period**||
|---|---|---|---|---|
|||**EAV**<br>**H blank**|**SAV**<br>**Valid area**||
|||**1**<br>**2**<br>**3**<br>**4**|**285**<br>**286**<br>**287**<br>**288**<br>**289**<br>**290**<br>**291**<br>**292**<br>**...**<br>**1725**<br>**1726**<br>**1727**|**1728**|
|Field1<br>(top)|1|FF<br>00<br>00<br>B6<br>FF<br>00<br>00<br>B6<br>FF<br>00<br>00<br>B6|FF<br>00<br>00<br>AB<br>Digital Blanking Data<br>FF<br>00<br>00<br>AB<br>FF<br>00<br>00<br>AB||
||:||||
||22||||
||23|FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D|FF<br>00<br>00<br>80<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||:||FF<br>00<br>00<br>80<br>:<br>Valid pixel data area<br>FF<br>00<br>00<br>80<br>:<br>FF<br>00<br>00<br>80<br>:<br>FF<br>00<br>00<br>80<br>:<br>FF<br>00<br>00<br>80<br>:|:|
||:|||:|
||:|||:|
||:|||:|
||:|||:|
||310||FF<br>00<br>00<br>80<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||311|FF<br>00<br>00<br>B6<br>FF<br>00<br>00<br>B6|FF<br>00<br>00<br>AB<br>Digital Blanking Data<br>FF<br>00<br>00<br>AB||
||312||||
|Field2<br>(bottom)|313|FF<br>00<br>00<br>F1<br>FF<br>00<br>00<br>F1<br>FF<br>00<br>00<br>F1|FF<br>00<br>00<br>EC<br>Digital Blanking Data<br>FF<br>00<br>00<br>EC<br>FF<br>00<br>00<br>EC||
||:||||
||335||||
||336|FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA|FF<br>00<br>00<br>C7<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||:||FF<br>00<br>00<br>C7<br>:<br>Valid pixel data area<br>FF<br>00<br>00<br>C7<br>:<br>FF<br>00<br>00<br>C7<br>:<br>FF<br>00<br>00<br>C7<br>:<br>FF<br>00<br>00<br>C7<br>:|:|
||:|||:|
||:|||:|
||:|||:|
||:|||:|
||623||FF<br>00<br>00<br>C7<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||624|FF<br>00<br>00<br>F1<br>FF<br>00<br>00<br>F1|FF<br>00<br>00<br>EC<br>Digital Blanking Data<br>FF<br>00<br>00<br>EC||
||625||||

**Figure 30.9 SAV/EAV Code in BT656 Format (625 Lines/50.00 Hz)**

||||**One Horizontal Period**||
|---|---|---|---|---|
|||**EAV**<br>**H blank**|**SAV**<br>**Valid area**||
|||**1**<br>**2**<br>**3**<br>**4**|**273**<br>**274**<br>**275**<br>**276**<br>**277**<br>**278**<br>**279**<br>**280**<br>**...**<br>**1713**<br>**1714**<br>**1715**|**1716**|
|Field2|1|FF<br>00<br>00<br>F1<br>FF<br>00<br>00<br>F1<br>FF<br>00<br>00<br>F1|FF<br>00<br>00<br>EC<br>Digital Blanking Data<br>FF<br>00<br>00<br>EC<br>FF<br>00<br>00<br>EC||
||2||||
||3||||
|Field1<br>(top)|4|FF<br>00<br>00<br>B6<br>FF<br>00<br>00<br>B6<br>FF<br>00<br>00<br>B6|FF<br>00<br>00<br>AB<br>Digital Blanking Data<br>FF<br>00<br>00<br>AB<br>FF<br>00<br>00<br>AB||
||:||||
||19||||
||20|FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D<br>FF<br>00<br>00<br>9D|FF<br>00<br>00<br>80<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||:||FF<br>00<br>00<br>80<br>:<br>Valid pixel data area<br>FF<br>00<br>00<br>80<br>:<br>FF<br>00<br>00<br>80<br>:<br>FF<br>00<br>00<br>80<br>:<br>FF<br>00<br>00<br>80<br>:|:|
||:|||:|
||:|||:|
||:|||:|
||:|||:|
||263||FF<br>00<br>00<br>80<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||264|FF<br>00<br>00<br>B6<br>FF<br>00<br>00<br>B6|FF<br>00<br>00<br>AB<br>Digital Blanking Data<br>FF<br>00<br>00<br>AB||
||265||||
|Field2<br>(bottom)|266|FF<br>00<br>00<br>F1<br>FF<br>00<br>00<br>F1<br>FF<br>00<br>00<br>F1|FF<br>00<br>00<br>EC<br>Digital Blanking Data<br>FF<br>00<br>00<br>EC<br>FF<br>00<br>00<br>EC||
||:||||
||282||||
||283|FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA<br>FF<br>00<br>00<br>DA|FF<br>00<br>00<br>C7<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||:||FF<br>00<br>00<br>C7<br>:<br>Valid pixel data area<br>FF<br>00<br>00<br>C7<br>:<br>FF<br>00<br>00<br>C7<br>:<br>FF<br>00<br>00<br>C7<br>:<br>FF<br>00<br>00<br>C7<br>:|:|
||:|||:|
||:|||:|
||:|||:|
||:|||:|
||525||FF<br>00<br>00<br>C7<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|

**Figure 30.10 SAV/EAV Code in BT656 Format (525 Lines/59.94 Hz)**

## 30.1.11 BT656 Progressive Format

This product can be connected with devices which output data in the BT656 progressive format. Because the standard for the BT656 format does not include description of output in the progressive format, there is no guarantee that this product is connected with devices which output data in the progressive format. The following description shows how to generate a vertical/horizontal synchronization signal by decoding the SAV/EAV code input via the BT656 interface of this module. Confirm the connection with devises which output data in the BT656 progressive format in accordance with this section.

## (1) SAV/EAV Code

The SAV/EAV code consists of four words. When the first word is set to FF and the second and third words are set to 00, timing signals are generated by decoding the value of the fourth word (XY).

For bit information, see Table 30.12 in section 30.1.10, SAV/EAV Code in BT656 Format . This product does not refer to the parity bits (P3 to P0).

## (2) Vertical/Horizontal Synchronization Signal

Based on the SAV/EAV code, the vertical/horizontal synchronization signal is generated.

## (a) Vertical Synchronization Signal

The vertical synchronization signal is output when the value of the V bit is changed from 0 to 1 in the BT656 format. The timing of the output varies with the setting of INP_EXT_SYNC_CNT.INP_F525_625 setting and the value of the F bit in the BT656 format.

Table 30.14 lists the timing.

## **Table 30.14 Timing of Delay for Output of Vertical Synchronization Signal**

|**INP_EXT_SYNC_CNT.**<br>**INP_F525_625**|**F Bit in BT656 Format**<br>**Output Timing**<br>**Remark**|
|---|---|
|0: 525 lines|0 (Field 1)<br>2.5 lines after setting of V bit to<br>1 is detected<br>525 lines, vertical<br>synchronization signal for field<br>2|
||1 (Field 2)<br>3 lines after setting of V bit to 1<br>is detected<br>525 lines, vertical<br>synchronization signal for field<br>1|
|1: 625 lines|0 (Field 1)<br>2.5 lines after setting of V bit<br>625 lines, vertical<br>synchronization signal for field<br>2|
||1 (Field 2)<br>2 lines after setting of V bit to 1<br>is detected<br>625 lines, vertical<br>synchronization signal for field<br>1|

(b) Horizontal Synchronization Signal

Based on the setting of the INP_EXT_SYNC_CNT.INP_H_EDGE_SEL bit, the horizontal synchronization signal is output.

- (c) Timing Example of 525-Line Interface Input in BT656 Format

Figure 30.11 and Figure 30.12 show examples of the timing of vertical/horizontal synchronization signal extracted from 525-line interlaced input in the BT656 format.

**==> picture [449 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
field 1(TOP) field2(BOTTOM)<br>Settings of V bit to 1 and F bit to 0 are detected<br>263 264 265 266 267<br>SAV Valid area EAVBlank SAV Valid area EAVBlank SAV Valid area EAVBlank<br>After 2.5 lines<br>VSOUT<br>HSOUT<br>**----- End of picture text -----**<br>

**Figure 30.11 Timing of Vertical/Horizontal Synchronization Signal from 525-Line Interlaced Input in BT656 Format (Top to Bottom)**

**==> picture [449 x 167] intentionally omitted <==**

**----- Start of picture text -----**<br>
field 2(BOTTOM) field1(TOP)<br>Settings of V and F bits to 1 are detected<br>525 1 2 3 4<br>SAV Valid area EAVBlank SAV Valid area EAVBlank SAV Valid area EAVBlank<br>After 3 lines<br>VSOUT<br>HSOUT<br>**----- End of picture text -----**<br>

**Figure 30.12 Timing of Vertical/Horizontal Synchronization Signal from 525-Line Interlaced Input in BT656 Format (Bottom to Top)**

## (3) Example of Timing for Progressive Input in BT656 Format

Figure 30.13 shows an example of the SAV/EAV code in 525-line progressive input in the BT656 format. Figure 30.14 shows the vertical/horizontal synchronization signal extracted from 525-line progressive input in the BT656 format. The field is detected as field 1 in this example, because the value of the F bit is set to 0 when that of the V bit is changed from 0 to 1. The filed is regarded as the bottom field. The vertical synchronization signal is output 2.5 lines after the detection of the SAV code.

||||**One Horizontal Period**||
|---|---|---|---|---|
|||**EAV**<br>**H blank**|**SAV**<br>**Valid area**||
|||**1**<br>**2**<br>**3**<br>**4**|**273**<br>**274**<br>**275**<br>**276**<br>**277**<br>**278**<br>**279**<br>**280**<br>**...**<br>**1713**<br>**1714**<br>**1715**|**1716**|
|Field1<br>(top)|1|FF<br>00<br>00<br>BX<br>FF<br>00<br>00<br>BX<br>FF<br>00<br>00<br>BX|FF<br>00<br>00<br>AX<br>Digital Blanking Data<br>FF<br>00<br>00<br>AX<br>FF<br>00<br>00<br>AX||
||:||||
||19||||
||20|FF<br>00<br>00<br>9X<br>FF<br>00<br>00<br>9X<br>FF<br>00<br>00<br>9X<br>FF<br>00<br>00<br>9X<br>FF<br>00<br>00<br>9X<br>FF<br>00<br>00<br>9X<br>FF<br>00<br>00<br>9X|FF<br>00<br>00<br>8X<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||:||FF<br>00<br>00<br>8X<br>:<br>Valid pixel data area<br>FF<br>00<br>00<br>8X<br>:<br>FF<br>00<br>00<br>8X<br>:<br>FF<br>00<br>00<br>8X<br>:<br>FF<br>00<br>00<br>8X<br>:|:|
||:|||:|
||:|||:|
||:|||:|
||:|||:|
||504||FF<br>00<br>00<br>8X<br>Cb0<br>Y0<br>Cr0<br>Y1<br>...<br>Cb718<br>Y718<br>Cr718|Y719|
||505|FF<br>00<br>00<br>BX<br>FF<br>00<br>00<br>BX<br>FF<br>00<br>00<br>BX|FF<br>00<br>00<br>AX<br>Digital Blanking Data<br>FF<br>00<br>00<br>AX<br>FF<br>00<br>00<br>AX||
||:||||
||525||||

**Figure 30.13 SAV/EAV Code in BT656 Progressive Format (525 Lines, 59.94 Hz)**

**==> picture [449 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
field 1(BOTTOM) field1(BOTTOM)<br>Settings of V bit to 1 and F bit to 0 are detected<br>504 505 506 507 508<br>SAV Valid area EAVBlank SAV Valid area EAVBlank SAV Valid area EAVBlank<br>After 2.5 lines<br>VSOUT<br>HSOUT<br>**----- End of picture text -----**<br>

**Figure 30.14 Vertical/Horizontal Synchronization Signal in BT656 Format (525 Lines, Progressive)**

## 30.1.12 BT656/BT601/YCbCr422 Format Setting

The BT656 format can be used for the 525-line and 59.94-Hz or the 625-line and 50.00-Hz interlace signal format and progressive signal format (extended).

The BT601 format can be used for the 525-line and 59.94-Hz or the 625-line and 50.00-Hz interlace signal format and progressive signal format (extended).

The YCbCr422 format can be used for the 525-line and 59.94-Hz or the 625-line and 50.00-Hz interlace signal format in the 16-bit data-bus format of the BT601 standard.

The Vsync signal timing for the 525-line BT656 format and 625-line BT656 format are different.

The operating mode is set by the INP_F525_625 bit.

## **Table 30.15 Operating Mode Setting for BT656 Format**

|||**Initial**||
|---|---|---|---|
|**Register Name**|**Bit Name**|**Value**|**Description**|
|INP_EXT_SYNC_CNT|INP_F525_625|0|Number of Lines for BT656 Input of External Input System|
||||0: 525 lines|
||||1: 625 lines|

When the interlace signals are to be input in BT656/BT601/YCbCr422 format, half of 2fH phase timings of the Vsync signal and the Hsync signal are set with the INP_FH50[9:0] bits.

The INP_FH50[9:0] bits are also used for the vertical synchronous phase adjustment block. Therefore, for bit description, see Table 30.20 .

When the external input is of BT656 format, the reference point of the Hsync signal is set with the INP_H_EDGE_SEL bit.

## **Table 30.16 Hsync Signal Reference Selection for BT656 Format**

|||**Initial**||
|---|---|---|---|
|**Register Name**|**Bit Name**|**Value**|**Description**|
|INP_EXT_SYNC_CNT|INP_H_EDGE_|0|Hsync Signal Reference Select for BT656 Format of External|
||SEL||Input System|
||||0: EAV|
||||1: SAV|

When the external input is of BT656/BT601 format, the internal signal BTOUT[7:0], which is input from the DV_DATA pins and allocated, is expanded to the 24-bit YCbCr signal.

Expansion timing with respect to the Hsync signal reference is set with the INP_H_POS[1:0] bits.

**==> picture [458 x 182] intentionally omitted <==**

**----- Start of picture text -----**<br>
[ INP_H_POS[1:0] = 0 ] [ INP_H_POS[1:0] = 2 ]<br>DV_HSYNC DV_HSYNC<br>BTOUT[7:0] ... Cb0 Y0 Cr0 Y1 Cb2 Y2 Cr2 Y3 Cb4 Y4 Cr4 Y5 ... ... ... ... ... ... ... BTOUT[7:0] ... ... ... Cb0 Y0 Cr0 Y1 Cb2 Y2 Cr2 Y3 Cb4 Y4 Cr4 Y5 ... ... ... ... ...<br>YOUT[7:0] XX XX Y0 Y1 Y2 Y3 Y4 Y5 ... ... YOUT[7:0] XX XX XX Y0 Y1 Y2 Y3 Y4 Y5 ...<br>CBOUT[7:0] XX Cb0 Cb2 Cb4 ... CBOUT[7:0] XX XX Cb0 Cb2 Cb4 ...<br>CROUT[7:0] XX Cr0 Cr2 Cr4 ... CROUT[7:0] XX XX Cr0 Cr2 Cr4 ...<br>[ INP_H_POS[1:0] = 1 ] [ INP_H_POS[1:0] = 3 ]<br>DV_HSYNC DV_HSYNC<br>BTOUT[7:0] Cb0 Y0 Cr0 Y1 Cb2 Y2 Cr2 Y3 Cb4 Y4 Cr4 Y5 ... ... ... ... ... ... BTOUT[7:0] ... ... Cb0 Y0 Cr0 Y1 Cb2 Y2 Cr2 Y3 Cb4 Y4 Cr4 Y5 ... ... ... ... ... ...<br>YOUT[7:0] XX XX Y0 Y1 Y2 Y3 Y4 Y5 ... ... ... YOUT[7:0] XX XX XX Y0 Y1 Y2 Y3 Y4 Y5 ... ...<br>CBOUT[7:0] XX Cb0 Cb2 Cb4 ... ... CBOUT[7:0] XX XX Cb0 Cb2 Cb4 ...<br>CROUT[7:0] XX Cr0 Cr2 Cr4 ... ... CROUT[7:0] XX XX Cr0 Cr2 Cr4 ...<br>**----- End of picture text -----**<br>

**Figure 30.15 YCbCr Data Expansion for BT656/BT601 Input**

**Table 30.17 Data String Start Timing Selection for BT656/BT601 Input**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|INP_EXT_SYNC_CNT|INP_H_POS[1:0]|0|Y/Cb/Y/Cr Data String Start Timing with respect to Hsync|
||||Reference|
||||0: Cb/Y/Cr/Y|
||||1: Y/Cr/Y/Cb|
||||2: Cr/Y/Cb/Y|
||||3: Y/Cb/Y/Cr|

When the external input is in YCbCr422 format, the input from the DV_DATA pins is allocated to the internal Y[7:0] and CbCr[7:0] signals, and the CbCr[7:0] are expanded to a 16-bit signal.

Expansion timing with respect to the Hsync signal reference is set with the INP_H_POS[1:0] bits.

**==> picture [331 x 430] intentionally omitted <==**

**----- Start of picture text -----**<br>
[INP_H_POS = 0]<br>IMGCLK<br>HSIN<br>PXDIN[7:0] ... Y0 Y1 Y2 Y3 Y4 Y5 Y6 Y7<br>PXDIN[15:8 ... Cb0 Cr0 Cb2 Cr2 Cb4 Cr4 Cb6 Cr6<br>]<br>CNT_RST<br>hcnt X X 0 1 0 1 0 1 0 1 0<br>HSOUT<br>YOUT[7:0] XX XX XX Y0 Y1 Y2 Y3 Y4 Y5 Y6 Y7<br>CBOUT[7:0] XX XX XX Cb0 Cb2 Cb4 Cb6<br>CROUT[7:0] XX XX XX Cr0 Cr2 Cr4 Cr6<br>[INP_H_POS = 3]<br>IMGCLK<br>HSIN<br>PXDIN[7:0] ... ... Y0 Y1 Y2 Y3 Y4 Y5 Y6 Y7<br>PXDIN[15:8] ... ... Cb0 Cr0 Cb2 Cr2 Cb4 Cr4 Cb6 Cr6<br>CNT_RST<br>hcnt X X X 0 1 0 1 0 1 0 1<br>HSOUT<br>YOUT[7:0] XX XX XX XX Y0 Y1 Y2 Y3 Y4 Y5 Y6 Y7<br>CBOUT[7:0] XX XX XX XX Cb0 Cb2 Cb4 Cb6<br>CROUT[7:0] XX XX XX XX Cr0 Cr2 Cr4 Cr6<br>**----- End of picture text -----**<br>

**Figure 30.16 YCbCr Data Expansion for YCbCr422 Input**

**Table 30.18 Data String Start Timing Selection for YCbCr422 Input**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|INP_EXT_SYNC_CNT|INP_H_POS[1:0]|0|Cb/Cr Data String Start Timing with respect to Hsync|
||||Reference|
||||0: Cb/Cr|
||||3: Cr/Cb|
||||1, 2: Setting prohibited|

## 30.1.13 YCbCr444/RBG888/666/565 Input Timing

The YCbCr444/RGB888/666/565 format can be used for the progressive YCbCr/RGB signal.

The sync signal width (H_SYNC, V_SYNC), sync signal polarity (H_POL, V_POL), valid period start position (H_BP, V_BP), valid period end position (H_FP, V_FP), and valid period video width (H_ACTIVE, V_ACTIVE) are shown in Table 30.19 .

## **Table 30.19 YCbCr/RGB Signal Reception Timing**

|**Item**|**Description**|
|---|---|
|External input clock|Maximum external input clock frequency: 87.00 MHz|
|Vsync signal width (V_SYNC)|Minimum Vsync signal width: 1 CLK|
|Vsync signal polarity (V_POL)|Positive or negative polarity is selected by the relevant registers.|
|Vertical valid period start position (V_BP)|From Vsync reference to the head of the video image: 5 lines or more|
|Vertical valid period video width (V_ACTIVE)|Maximum vertical valid period: 1024 lines|
|Vertical valid period end position (V_FP)|From the end of the video image to the Vsync reference: 4 lines or moreNote 1.|
|Hsync signal width (H_SYNC)|Minimum Hsync signal width: 1 CLK|
|Hsync signal polarity (H_POL)|Positive or negative polarity is selected by the relevant registers.|
|Horizontal valid period start position (H_BP)|From Hsync reference to the head of the video image: 16 CLK or more|
|Horizontal valid period video width (H_ACTIVE)|Maximum horizontal valid period: 1440 pixels|
|Horizontal valid period end position (H_FP)|From the end of the video image to the Hsync reference: 16 CLK or moreNote 2.|
|Number of vertical lines (V_BP+V_ACTIVE+V_FP)|Between vertical synchronization signals: 2047 lines or less|
|Number of horizontal pixels|Between horizontal synchronization signals: 2047 CLK or less|
|(H_BP+H_ACTIVE+H_FP)||

Note 1. When V_FP is below four lines, the setting of INP_DLY_ADJ.INP_VS_DLY_L[2:0] should be adjusted so that V_FP is at least four lines.

Note 2. When H_FP is below 16 cycles, the settings of INP_DLY_ADJ.INP_VS_DLY[7:0], INP_HS_DLY[7:0], and INP_FLD_DLY[7:0] should be adjusted so that H_FP is at least 16 cycles of the pixel clock.

**==> picture [425 x 311] intentionally omitted <==**

**----- Start of picture text -----**<br>
H_SYNC<br>H_BP H_ACTIVE H_FP<br>DV_HSYNC<br>V_SYNC<br>V_BP<br>V_ACTIVE Valid image area<br>V_FP<br>DV_VSYNC<br>**----- End of picture text -----**<br>

**Figure 30.17 YCbCr/RGB Signal Reception Timing**

## 30.1.14 Field Differentiation and Vsync Signal Phase Adjustment

The phase of the input Vsync signal and Hsync signal is detected and the field of the interlace signal is determined. When the reference point of the Vsync signal is detected within ±0.5 horizontal period with respect to the Hsync signal, it is determined as the interlace top field. When the reference point of the Vsync signal is detected outside ±0.5 horizontal period with respect to the Hsync signal, it is determined as the interlace bottom field.

**==> picture [415 x 283] intentionally omitted <==**

**----- Start of picture text -----**<br>
[Interlace (TOP), progressive]<br>Top<br>HSIN<br>VSIN<br>1/4fH 1/4fH<br>Not affected by the falling timing<br>1/2fH<br>VSOUT 1fH<br>1fH<br>FLDOUT<br>[Interlace (BOTTOM)]<br>Bottom<br>HSIN<br>VSIN<br>1/4fH 1/4fH<br>Not affected by the falling timing<br>1/2fH<br>VSOUT 1fH<br>FLDOUT 1fH<br>**----- End of picture text -----**<br>

**Figure 30.18 Vsync Signal Phase Adjustment**

The timings of 1/2fH Vsync signal phase and 1/4fH Vsync signal phase are set with INP_FH50[9:0] and INP_FH25[9:0], respectively.

**Table 30.20 Vsync Signal Phase Timing Setting**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|INP_VSYNC_PH_ADJ|INP_FH50[9:0]|858|Vsync Signal 1/2fH Phase Timing|
||||Should be 1/2 the horizontal cycle.|
|INP_VSYNC_PH_ADJ|INP_FH25[9:0]|429|Vsync Signal 1/4fH Phase Timing|
||||Should be 1/4 the horizontal cycle.|

## 30.1.15 Vsync Signal Delay Adjustment in Line Units

The Vsync signal line delay adjust block can delay the Vsync signal and the field differentiation signal in line units.

When a video signal with a short vertical front porch is input, the vertical front porch is adjusted.

**==> picture [416 x 143] intentionally omitted <==**

**----- Start of picture text -----**<br>
VSIN<br>FLDIN<br>HSIN<br>INP_VS_DLY_L[2:0] = 4 INP_VS_DLY_L[2:0] = 4<br>VSOUT 4 lines 4 lines<br>FLDOUT<br>HSOUT<br>**----- End of picture text -----**<br>

**Figure 30.19 Timing of Vsync Signal Delay in Line Units**

**Table 30.21 Adjustment of Vsync Signal Delay in Line Units**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|INP_DLY_ADJ|INP_VS_DLY_L[2:0]|0|Number of Lines for Delaying Vsync Signal and Field|
||||Differentiation Signal|
||||Delay amount: 0 to 7 (lines)|

## 30.1.16 Sync Signal Delay Adjustment

Delay can be adjusted independently for the Vsync signal, Hsync signal, and field differentiation signal in the units of clock.

Lacking margin of the horizontal front porch is adjusted according to the input synchronization disturbance.

## **Table 30.22 Sync Signal Delay Adjustment**

|||**Initial**||
|---|---|---|---|
|**Register Name**|**Bit Name**|**Value**|**Description**|
|INP_DLY_ADJ|INP_VS_DLY[7:0]|0|Vsync Signal Delay Amount|
||||Delay amount: 0 to 254 (clock cycles)|
|INP_DLY_ADJ|INP_HS_DLY[7:0]|0|Hsync Signal Delay Amount|
||||Delay amount: 0 to 254 (clock cycles)|
|INP_DLY_ADJ|INP_FLD_DLY[7:0]|0|Field Differentiation Signal Delay Amount|
||||Delay amount: 0 to 254 (clock cycles)|

## 30.1.17 Horizontal Noise Reduction

Noise can be reduced according to horizontal pixel reference.

Noise reduction is controlled through noise component frequency band (TAP), noise level (threshold), and noise reduction intensity (gain).

## (1) Frequency Band (TAP) Setting for Noise Component

The noise frequency band can be selected independently from the following four types by using the NR1D_Y_TAP[1:0], NR1D_CB_TAP[1:0], and NR1D_CR **_** TAP[1:0] bits.

When the number of adjacent pixels is one (noise reduction NR1D_Y/CB/CR_TAP is 0):

**==> picture [130 x 17] intentionally omitted <==**

When the number of adjacent pixels is two (noise reduction NR1D_Y/CB/CR_TAP is 1):

_BPF_ (2)  41  1 _Z_ (2,) 2  _Z_ (0),  1 _Z_ (2) 

When the number of adjacent pixels is three (noise reduction NR1D_Y/CB/CR_TAP is 2):

_BPF_ (3)  41  1 _Z_ (3), 2  _Z_ (0),  1 _Z_ (3) 

When the number of adjacent pixels is four (noise reduction NR1D_Y/CB/CR_TAP is 3):

_BPF_ (4)  41  1 _Z_ (4), 2  _Z_ (0),  1 _Z_ (4) 

Note: Z(0) indicates the target pixel for noise reduction and Z(N) indicates the pixel that is n pixels off from Z(0) In the horizontal direction.

## (2) Setting Noise Level (Threshold)

The absolute value of the detected noise amount (BPF output value) is compared with the values of the NR1D_Y_TH[6:0], NR1D_CB_TH[6:0], and NR1D_CR_TH[6:0] bits. When the detected noise amount is greater than NR1D_Y/CB/CR_TH, the absolute value of the detected noise amount is considered as NR1D_Y/CB/CR_TH (fixed value).

ABS(BPF(n)) ≤ absolute value of detected noise amount when ABS(BPF(n)) ≤ NR1D_Y/CB/CR_TH: NOISE_ABS = ABS(BPF(n))

ABS(BPF(n)) > absolute value of detected noise amount when ABS(BPF(n)) > NR1D_Y/CB/CR_TH: NOISE_ABS = NR1D_Y/CB/CR_TH

## (3) Setting Noise Reduction Intensity (Gain)

The absolute value of the detected noise amount is multiplied by the value of gain specified by the NR1D_Y_GAIN[1:0], NR1D_CB_GAIN[1:0], and NR1D_CR_GAIN[1:0] bits, and the feedback is calculated for the original signal.

Computation when the amount of detected noise (BPF(n)) is negative (−): DOUT = DIN + NOISE_ABS ÷ 2[(NR1D_Y/CB/CR_GAIN+1)]

Computation when the amount of detected noise (BPF(n)) is positive (+): DOUT = DIN – NOISE_ABS ÷ 2[(NR1D_Y/] CB/CR_GAIN+1)

## **Table 30.23 Horizontal Noise Reduction**

|||**Initial**||
|---|---|---|---|
|**Register Name**|**Bit Name**|**Value**|**Description**|
|IMGCNT_NR_CNT0|NR1D_MD|1|Horizontal Noise Reduction Operating Mode|
||||0: R/G/B mode|
||||1: Y/Cb/Cr mode|
|IMGCNT_NR_CNT0|NR1D_ON|0|Noise Reduction On/Off Control|
||||0: Noise Reduction Off|
||||1: Noise Reduction On|
|IMGCNT_NR_CNT0|NR1D_Y_TAP[1:0]|0|Y/G Signal TAP Select|
||||0: Adjacent pixel|
||||1: 2 adjacent pixels|
||||2: 3 adjacent pixels|
||||3: 4 adjacent pixels|
|IMGCNT_NR_CNT0|NR1D_Y_TH[6:0]|8|Maximum Value (Absolute Value) of Y/G Signal Coring|
||||Coring is implemented when detected noise amount|
||||value ≤ NR1D_Y_TH.|
||||Unsigned: 0 to 127 [LSB]|
|IMGCNT_NR_CNT0|NR1D_Y_GAIN[1:0]|3|Noise Reduction Gain Adjustment of Y/G Signal|
||||0: 1/2|
||||1: 1/4|
||||2: 1/8|
||||3: 1/16|
|IMGCNT_NR_CNT1|NR1D_CB_TAP[1:0]|0|Cb/B Signal TAP Select|
||||0: Adjacent pixel|
||||1: 2 adjacent pixels|
||||2: 3 adjacent pixels|
||||3: 4 adjacent pixels|
|IMGCNT_NR_CNT1|NR1D_CB_TH[6:0]|8|Maximum Value (Absolute Value) of Cb/B Signal|
||||Coring|
||||Coring is implemented when detected noise amount|
||||value ≤ NR1D_C_TH.|
||||Unsigned: 0 to 127 [LSB]|
|IMGCNT_NR_CNT1|NR1D_CB_GAIN[1:0]|3|Noise Reduction Gain Adjustment of Cb/B Signal|
||||0: 1/2|
||||1: 1/4|
||||2: 1/8|
||||3: 1/16|
|IMGCNT_NR_CNT1|NR1D_CR_TAP[1:0]|0|Cr/R Signal TAP Select|
||||0: Adjacent pixel|
||||1: 2 adjacent pixels|
||||2: 3 adjacent pixels|
||||3: 4 adjacent pixels|
|IMGCNT_NR_CNT1|NR1D_CR_TH[6:0]|8|Maximum Value (Absolute Value) of Cr/R Signal|
||||Coring|
||||Coring is implemented when detected noise amount|
||||value ≤ NR1D_C_TH.|
||||Unsigned: 0 to 127 [LSB]|
|IMGCNT_NR_CNT1|NR1D_CR_GAIN[1:0]|3|Noise Reduction Gain Adjustment of Cr/R Signal|
||||0: 1/2|
||||1: 1/4|
||||2: 1/8|
||||3: 1/16|

## 30.1.18 Color Matrix

By using a color matrix, input signal offsets and nine-axis gain can be adjusted. This enables brightness adjustment, gain adjustment, and YCbCr and GBR mutual conversion.

## (1) GBR to GBR Conversion

YGIN_A = YGIN + IMGCNT_MTX_YG – 128

CBBIN_A = CBBIN + IMGCNT_MTX_B – 128

CRRIN_A = CRRIN + IMGCNT_MTX_R – 128

YGOUT = (IMGCNT_MTX_GG×YGIN_A + IMGCNT_MTX_GB×CBBIN_A + IMGCNT_MTX_GR×CRRIN_A) ÷ 256

CBBOUT = (IMGCNT_MTX_BG×YGIN_A + IMGCNT_MTX_BB×CBBIN_A + IMGCNT_MTX_BR×CRRIN_A) ÷ 256

CRROUT = (IMGCNT_MTX_RG×YGIN_A + IMGCNT_MTX_RB×CBBIN_A + IMGCNT_MTX_RR×CRRIN_A) ÷ 256

## (2) GBR to YCbCr Conversion

YGIN_A = YGIN + IMGCNT_MTX_YG – 128

CBBIN_A = CBBIN + IMGCNT_MTX_B – 128

CRRIN_A = CRRIN + IMGCNT_MTX_R – 128

YGOUT = (IMGCNT_MTX_GG×YGIN_A + IMGCNT_MTX_GB×CBBIN_A + IMGCNT_MTX_GR×CRRIN_A) ÷ 256

CBBOUT = (IMGCNT_MTX_BG×YGIN_A + IMGCNT_MTX_BB×CBBIN_A + IMGCNT_MTX_BR×CRRIN_A) ÷ 256 + 128

CRROUT = (IMGCNT_MTX_RG×YGIN_A + IMGCNT_MTX_RB×CBBIN_A + IMGCNT_MTX_RR×CRRIN_A) ÷ 256 + 128

**Table 30.24 Matrix Coefficient (Typical Value) for SMPTE 293M**

|**Table 30.24**|**Matrix Coefficient (Typical Value) for SMPTE 293M**|
|---|---|
||**YGIN**<br>**CBBIN**<br>**CRRIN**|
||**Coefficient**<br>**Set Value**<br>**Coefficient**<br>**Set Value**<br>**Coefficient**<br>**Set Value**|
|YGOUT|0.587<br>IMGCNT_<br>MTX_GG = 150<br>0.114<br>IMGCNT_MTX_GB<br>= 29<br>0.299<br>IMGCNT_MTX_GR<br>= 77|
|CBBOUT|–0.331<br>IMGCNT_<br>MTX_BG = 1963<br>0.500<br>IMGCNT_MTX_BB<br>= 128<br>–0.169<br>IMGCNT_MTX_BR<br>= 2005|
|CRROUT|–0.419<br>IMGCNT_<br>MTX_RG = 1941<br>–0.081<br>IMGCNT_MTX_RB<br>= 2027<br>0.500<br>IMGCNT_MTX_RR<br>= 128|

## (3) YCbCr to GBR Conversion

YGIN_A = YGIN + IMGCNT_MTX_YG – 128

CBBIN_A = CBBIN – 128

CRRIN_A = CRRIN – 128

YGOUT = (IMGCNT_MTX_GG×YGIN_A + IMGCNT_MTX_GB×CBBIN_A + IMGCNT_MTX_GR×CRRIN_A) ÷ 256

CBBOUT = (IMGCNT_MTX_BG×YGIN_A + IMGCNT_MTX_BB×CBBIN_A + IMGCNT_MTX_BR×CRRIN_A) ÷ 256

CRROUT = (IMGCNT_MTX_RG×YGIN_A + IMGCNT_MTX_RB×CBBIN_A + IMGCNT_MTX_RR×CRRIN_A) ÷ 256

**Table 30.25 Matrix Coefficient (Typical Value) for SMPTE 293M**

|**Table 30.25**|**Matrix Coefficient (Typical Value) for SMPTE 293M**|
|---|---|
||**YGIN**<br>**CBBIN**<br>**CRRIN**|
||**Coefficient**<br>**Set Value**<br>**Coefficient**<br>**Set Value**<br>**Coefficient**<br>**Set Value**|
|YGOUT|1.000<br>IMGCNT_<br>MTX_GG = 256<br>–0.344<br>IMGCNT_MTX_GB<br>= 1960<br>–0.714<br>IMGCNT_MTX_GR<br>= 1865|
|CBBOUT|1.000<br>IMGCNT_<br>MTX_BG = 256<br>1.772<br>IMGCNT_MTX_BB<br>= 454<br>0.000<br>IMGCNT_MTX_BR<br>= 0|
|CRROUT|1.000<br>IMGCNT_<br>MTX_RG = 256<br>0.000<br>IMGCNT_MTX_RB<br>= 0<br>1.402<br>IMGCNT_MTX_RR<br>= 359|

## (4) YCbCr to YCbCr Conversion

YGIN_A = YGIN + IMGCNT_MTX_YG – 128

CBBIN_A = CBBIN – 128

CRRIN_A = CRRIN – 128

YGOUT = (IMGCNT_MTX_GG×YGIN_A + IMGCNT_MTX_GB×CBBIN_A + IMGCNT_MTX_GR×CRRIN_A) ÷ 256

CBBOUT = (IMGCNT_MTX_BG×YGIN_A + IMGCNT_MTX_BB×CBBIN_A + IMGCNT_MTX_BR×CRRIN_A) ÷ 256 + 128

CRROUT = (IMGCNT_MTX_RG×YGIN_A + IMGCNT_MTX_RB×CBBIN_A + IMGCNT_MTX_RR×CRRIN_A) ÷ 256 + 128

## **Table 30.26 YCbCr to GBR Conversion**

|||**Initial**||
|---|---|---|---|
|**Register Name**|**Bit Name**|**Value**|**Description**|
|IMGCNT_MTX_MODE|IMGCNT_MTX_MD|3|Operating Mode|
||[1:0]||0: GBR → GBR|
||||1: GBR → YCbCr|
||||2: YCbCr → GBR|
||||3: YCbCr → YCbCr|
|IMGCNT_MTX_YG_|IMGCNT_MTX_YG|128|Offset (DC) Adjustment of Y/G Signal|
|ADJ0|[7:0]||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB], 512|
||||[LSB])|
|IMGCNT_MTX_CBB_|IMGCNT_MTX_B|128|Offset (DC) Adjustment of B Signal|
|ADJ0|[7:0]||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])|
|IMGCNT_MTX_CRR_|IMGCNT_MTX_R|128|Offset (DC) Adjustment of R Signal|
|ADJ0|[7:0]||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])|
|IMGCNT_MTX_YG_|IMGCNT_MTX_GG|256|Y/G Signal Gain Adjustment for Y/G Signal Output|
|ADJ0|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|
|IMGCNT_MTX_YG_|IMGCNT_MTX_GB|0|Cb/B Signal Gain Adjustment for Y/G Signal Output|
|ADJ1|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|
|IMGCNT_MTX_YG_|IMGCNT_MTX_GR|0|Cr/R Signal Gain Adjustment for Y/G Signal Output|
|ADJ1|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|
|IMGCNT_MTX_CBB_|IMGCNT_MTX_BG|0|Y/G Signal Gain Adjustment for Cb/B Signal Output|
|ADJ0|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|
|IMGCNT_MTX_CBB_|IMGCNT_MTX_BB|256|Cb/B Signal Gain Adjustment for Cb/B Signal Output|
|ADJ1|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|
|IMGCNT_MTX_CBB_|IMGCNT_MTX_BR|0|Cr/R Signal Gain Adjustment for Cb/B Signal Output|
|ADJ1|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|
|IMGCNT_MTX_CRR_|IMGCNT_MTX_RG|0|Y/G Signal Gain Adjustment for Cr/R Signal Output|
|ADJ0|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|
|IMGCNT_MTX_CRR_|IMGCNT_MTX_RB|0|Cb/B Signal Gain Adjustment for Cr/R Signal Output|
|ADJ1|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|
|IMGCNT_MTX_CRR_|IMGCNT_MTX_RR|256|Cr/R Signal Gain Adjustment for Cr/R Signal Output|
|ADJ1|[10:0]||Signed (two's complement) (-1024 to +1023 [LSB],|
||||256 [LSB] = 1.0 [times])|

## 30.2 Register Descriptions

Table 30.27 and Table 30.28 show register Configuration.

- Symbols used in Register Description:

Initial value: Register value after a power-on reset

—: Undefined value R/W: Readable/writable. The written value can be read. R/WC0: Readable/writable. Writing 0 initializes the bit. Writing 1 is ignored. R/WC1: Readable/writable. Writing 1 initializes the bit. Writing 0 is ignored. R: Read-only. The write value should always be 0. —/W: Write-only. The read value is undefined.

**Table 30.27 Register Configuration of Input Controller**

||||||**Access**|
|---|---|---|---|---|---|
|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|External input block register|INP_UPDATE|R/WC1|H'0000 0000|H'FCFF 7400|32|
|update control register||||||
|Input select control register|INP_SEL_CNT|R/W|H'0000 0000|H'FCFF 7404|32|
|External input sync signal control|INP_EXT_SYNC_CNT|R/W|H'0000 0000|H'FCFF 7408|32|
|register||||||
|Vsync signal phase adjustment|INP_VSYNC_PH_ADJ|R/W|H'035A 01AD|H'FCFF 740C|32|
|register||||||
|Sync signal delay adjustment|INP_DLY_ADJ|R/W|H'0000 0000|H'FCFF 7410|32|
|register||||||

## **Table 30.28 Register Configuration of Image Quality Adjustment Block**

||||||**Access**|
|---|---|---|---|---|---|
|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Size**|
|Image quality adjustment block|IMGCNT_UPDATE|R/WC1|H'0000 0000|H'FCFF 7480|32|
|register update control register||||||
|NR control register 0|IMGCNT_NR_CNT0|R/W|H'0010 0803|H'FCFF 7484|32|
|NR control register 1|IMGCNT_NR_CNT1|R/W|H'0803 0803|H'FCFF 7488|32|
|Image quality adjustment block|IMGCNT_MTX_MODE|R/W|H'0000 0003|H'FCFF 74A0|32|
|matrix mode register||||||
|Image quality adjustment block|IMGCNT_MTX_YG_|R/W|H'0080 0100|H'FCFF 74A4|32|
|matrix YG adjustment register 0|ADJ0|||||
|Image quality adjustment block|IMGCNT_MTX_YG_|R/W|H'0000 0000|H'FCFF 74A8|32|
|matrix YG adjustment register 1|ADJ1|||||
|Image quality adjustment block|IMGCNT_MTX_CBB_|R/W|H'0080 0000|H'FCFF 74AC|32|
|matrix CBB adjustment register 0|ADJ0|||||
|Image quality adjustment block|IMGCNT_MTX_CBB_|R/W|H'0100 0000|H'FCFF 74B0|32|
|matrix CBB adjustment register 1|ADJ1|||||
|Image quality adjustment block|IMGCNT_MTX_CRR_|R/W|H'0080 0000|H'FCFF 74B4|32|
|matrix CRR adjustment register 0|ADJ0|||||
|Image quality adjustment block|IMGCNT_MTX_CRR_|R/W|H'0000 0100|H'FCFF 74B8|32|
|matrix CRR adjustment register 1|ADJ1|||||

## 30.2.1 External Input Block Register Update Control Register (INP_UPDATE)

||Bit:|31|30|29||28|27||26|25<br>24|23<br>22|21|20||19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—||—|—||—|—<br>—|—<br>—|—|—||—|—|—||—||
||Initial Value:|0|0|0||0|0||0|0<br>0|0<br>0|0|0||0|0|0||0||
||R/W:|R|R|R||R|R||R|R<br>R|R<br>R|R|R||R|R|R||R||
||Bit:|15|14|13||12|11||10|9<br>8|7<br>6|5|4||3|2|1||0||
||||||||||||||INP_EXT_||||||INP_IMG_||
|||—|—|—||—|—||—|—<br>—|—<br>—|—|UPDATE||—|—|—||UPDATE||
||Initial Value:|0|0|0||0|0||0|0<br>0|0<br>0|0|0||0|0|0||0||
||R/W:|R|R|R||R|R||R|R<br>R|R<br>R|R|R/WC1||R|R|R|R/WC1|||
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**|||||||||||
|31 to 5||—|||All 0|||R||Reserved|||||||||||
|||||||||||These bits|are always read as 0. The write value should always be 0.||||||||||
|4||INP_EXT_|||0|||R/WC1||External Input Block Register Update|||||||||||
|||UPDATE||||||||0: Registers are not updated.|||||||||||
|||||||||||1: Registers are updated.|||||||||||
|3|to 1|—|||All 0|||R||Reserved|||||||||||
|||||||||||These bits|are always read as 0. The write value should always be 0.||||||||||
|0||INP_IMG_|||0|||R/WC1||Sync Signal Adjustment Block Register Update|||||||||||
|||UPDATE||||||||0: Registers are not updated.|||||||||||
|||||||||||1: Registers are updated.|||||||||||

## 30.2.2 Input Select Control Register (INP_SEL_CNT)

||Bit:|31|30|29|||28|27||26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||INP_||||||
|||—|—|—|||—|—||—|—<br>—<br>—|—|—|SEL|—|—|—|—||
|Initial Value:||0|0|0|||0|0||0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R|R|||R|R||R|R<br>R<br>R|R|R|R/W|R|R|R|R||
||Bit:|15|14|13|||12|11||10|9<br>8<br>7|6|5|4|3|2|1|0||
|||—|INP_FORMAT[2:0]|||||—||—|—<br>INP_<br>PXD_<br>EDGE<br>—|—|—|INP_<br>VS_<br>EDGE|—|—|—|INP_<br>HS_<br>EDGE||
||Initial Value:|0|0|0|||0|0||0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R/W|R/W||R/W||R||R|R<br>R/W<br>R|R|R|R/W|R|R|R|R/W||
|**Bit**||**Bit Name**||**Initial Value**|||||**R/W**||**Description**|||||||||
|31|to 21|—||All||0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|20||INP_SEL||0|||||R/W||Input Select|||||||||
||||||||||||0: Input supplied via the external input pins is off.|||||||||
||||||||||||1: Input supplied via the external input pins is on.|||||||||
|19|to 15|—||All||0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|14|to 12|INP_||0|||||R/W||External Input Format Select|||||||||
|||FORMAT|||||||||0: YcbCr444, RGB888|||||||||
|||[2:0]|||||||||1: RGB666|||||||||
||||||||||||2: RGB565|||||||||
||||||||||||3: BT656|||||||||
||||||||||||4: BT601|||||||||
||||||||||||5: YCbCr422|||||||||
||||||||||||6, 7: Setting prohibited|||||||||
|11|to 9|—||All||0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|8||INP_PXD_||0|||||R/W||Clock Edge Select for Capturing|||External Input||Video Image Signals||||
|||EDGE|||||||||DV_DATA23 to DV_DATA0|||||||||
||||||||||||0: Rising edge|||||||||
||||||||||||1: Falling edge|||||||||
|7 to 5||—||All||0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|4||INP_VS_||0|||||R/W||Clock Edge Select for Capturing|||External Input||Vsync Signals||||
|||EDGE|||||||||DV_VSYNC|||||||||
||||||||||||0: Rising edge|||||||||
||||||||||||1: Falling edge|||||||||
|3 to 1||—||All||0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||||
|0||INP_HS_||0|||||R/W||Clock Edge Select for Capturing|||External Input||Hsync|Signals|||
|||EDGE|||||||||DV_HSYNC|||||||||
||||||||||||0: Rising edge|||||||||
||||||||||||1: Falling edge|||||||||

Note: INP_FORMAT, INP_PXD_EDGE, INP_VS_EDGE, and INP_HS_EDGE are updated when the INP_EXT_UPDATE bit in INP_UPDATE is 1. INP_SEL is updated when set.

## 30.2.3 External Input Sync Signal Control Register (INP_EXT_SYNC_CNT)

||Bit:|31|30|29|||28|27||26|25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|||INP_<br>ENDIAN_<br>ON|—||—|—<br>—<br>—<br>INP_<br>SWAP_<br>ON<br>—|INP_<br>VS_INV|—|—|—|INP_<br>HS_INV||
||Initial Value:|0|0|0|||0|0||0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||R/W:|R|R|R|||R/W|R||R|R<br>R/W<br>R<br>R<br>R|R/W|R|R|R|R/W||
||Bit:|15|14|13|||12|11||10|9<br>8<br>7<br>6<br>5|4|3|2|1|0||
|||—|—|—|||—|—||—|—<br>—<br>—<br>—<br>INP_<br>H_EDGE_<br>SEL|INP_<br>F525_625|—|—|INP_H_POS[1:0]|||
||Initial Value:|0|0|0|||0|0||0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||R/W:|R|R|R|||R|R||R|R<br>R/W<br>R<br>R<br>R|R/W|R|R|R/W|R/W||
|**Bit**||**Bit Name**|||**Initial Value**||||**R/W**||**Description**|||||||
|31 to 29||—|||All||0||R||Reserved|||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|28||INP_|||0||||R/W||External Input Bit Endian Change On/Off Control|||||||
|||ENDIAN_|||||||||0: Off|||||||
|||ON|||||||||1: On|||||||
|27 to 25||—|||All||0||R||Reserved|||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|24||INP_|||0||||R/W||External Input B/R Signal Swap On/Off Control|||||||
|||SWAP_ON|||||||||0: Off|||||||
||||||||||||1: On|||||||
|23 to 21||—|||All||0||R||Reserved|||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|20||INP_VS_|||0||||R/W||External Input Vsync Signal DV_VSYNC Inversion Control|||||||
|||INV|||||||||0: Not inverted (positive polarity)|||||||
||||||||||||1: Inverted (negative polarity)|||||||
|19 to 17||—|||All||0||R||Reserved|||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|16||INP_HS_|||0||||R/W||External Input Hsync Signal DV_HSYNC Inversion Control|||||||
|||INV|||||||||0: Not inverted (positive polarity)|||||||
||||||||||||1: Inverted (negative polarity)|||||||
|15 to 9||—|||All||0||R||Reserved|||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|8||INP_H_|||0||||R/W||Reference Select for External Input BT656 Hsync Signal|||||||
|||EDGE_SEL|||||||||0: EAV|||||||
||||||||||||1: SAV|||||||
|7 to 5||—|||All||0||R||Reserved|||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|4||INP_F525_|||0||||R/W||Number of Lines for BT656 External Input|||||||
|||625|||||||||0: 525 lines|||||||
||||||||||||1: 625 lines|||||||
|3,|2|—|||All||0||R||Reserved|||||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|1,|0|INP_H_|||0||||R/W||Y/Cb/Y/Cr Data String Start Timing to Hsync Reference for BT656/601|||||||
|||POS[1:0]|||||||||or YCbCr422 External Input|||||||
||||||||||||0: Cb/Y/Cr/Y(BT656/601), Cb/Cr|(YCbCr422)||||||
||||||||||||1: Y/Cr/Y/Cb(BT656/601),|||||||
||||||||||||setting prohibited (YCbCr422)|||||||
||||||||||||2: Cr/Y/Cb/Y(BT656/601),|||||||
||||||||||||setting prohibited (YCbCr422)|||||||
||||||||||||3: Y/Cb/Y/Cr(BT656/601), Cr/Cb|(YCbCr422)||||||

Note: This register is updated when the INP_EXT_UPDATE bit in INP_UPDATE is 1.

## 30.2.4 Vsync Signal Phase Adjustment Register (INP_VSYNC_PH_ADJ)

|Bit:||31|30|29||28|27||26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—||—|—||—||||INP_FH50[9:0]|||||||
|Initial Value:||0|0|0||0|0||0|1<br>1|0|1|0|1|1|0|1|0||
|R/W:||R|R|R||R|R||R|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:||15|14|13||12|11||10|9<br>8|7|6|5|4|3|2|1|0||
|||—|—|—||—|—||—||||INP_FH25[9:0]|||||||
|Initial Value:||0|0|0||0|0||0|0<br>1|1|0|1|0|1|1|0|1||
|R/W:||R|R|R||R|R||R|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**||||||||||
|31 to 26||—|||All 0|||R||Reserved||||||||||
|||||||||||These bits|are always read as 0. The write value should always be 0.|||||||||
|25 to 16||INP_FH50|||858|||R/W||Vsync Signal 1/2fH Phase Timing||||||||||
|||[9:0]||||||||1/2 clock cycle of the horizontal cycle should be||||||set.||||
|15 to 10||—|||All 0|||R||Reserved||||||||||
|||||||||||These bits|are always read as 0. The write value should always be 0.|||||||||
|9 to 0||INP_FH25|||429|||R/W||Vsync Signal 1/4fH Phase Timing||||||||||
|||[9:0]||||||||1/4 clock cycle of the horizontal cycle should be||||||set.||||

Note: The INP_FH50[9:0] bits are updated when the INP_EXT_UPDATE and INP_IMG_UPDATE bits in INP_UPDATE are 1. The IMP_FH25[9:0] bits are updated when the INP_IMG_UPDATE bit is 1.

## 30.2.5 Sync Signal Delay Adjustment Register (INP_DLY_ADJ)

|Bit:||31<br>30|29||28|27||26|25<br>24<br>23<br>22|21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—<br>—|—||—|—||INP_VS_DLY_L[2:0]||INP_FLD_DLY[7:0]||||||
|Initial Value:||0<br>0|0||0|0||0|0<br>0<br>0<br>0|0<br>0|0|0|0|0||
|R/W:||R<br>R|R||R|R||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W|R/W||
|Bit:||15<br>14|13||12|11||10|9<br>8<br>7<br>6|5<br>4|3|2|1|0||
||||INP_VS_DLY[7:0]|||||||INP_HS_DLY[7:0]||||||
|Initial Value:||0<br>0|0||0|0||0|0<br>0<br>0<br>0|0<br>0|0|0|0|0||
|R/W:||R/W<br>R/W|R/W||R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**|**Initial Value**||||**R/W**||**Description**|||||||
|31 to 27||—|All||0||R||Reserved|||||||
||||||||||These bits are always read as 0. The write||value|should|always|be 0.||
|26 to 24||INP_VS_|0||||R/W||Number of lines for Delaying|Vsync signal|and Field Differentiation Signal|||||
|||DLY_L[2:0]|||||||Delay amount: 0 to 7 (lines)|||||||
|23 to 16||INP_FLD_|0||||R/W||Field Differentiation Signal Delay Amount|||||||
|||DLY[7:0]|||||||Delay amount: 0 to 254 (clock cycles)|||||||
|15 to 8||INP_VS_|0||||R/W||Vsync Signal Delay Amount|||||||
|||DLY[7:0]|||||||Delay amount: 0 to 254 (clock cycles)|||||||
|7 to 0||INP_HS_|0||||R/W||Hsync Signal Delay Amount|||||||
|||DLY[7:0]|||||||Delay amount: 0 to 254 (clock cycles)|||||||

Note: This register is updated when the INP_IMG_UPDATE bit in INP_UPDATE is 1.

## 30.2.6 Image Quality Adjustment Block Register Update Control Register (IMGCNT_UPDATE)

|Bit:|31|30|29||28|27||26|25|24|23|22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—||—|—||—|—|—|—|—|—|—|—|—|—||—||
|Initial Value:|0|0|0||0|0||0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R||R|R||R|R|R|R|R|R|R|R|R|R||R||
|Bit:|15|14|13||12|11||10|9|8|7|6|5|4|3|2|1||0||
||||||||||||||||||||IMGCNT||
||—|—|—||—|—||—|—|—|—|—|—|—|—|—|—||_VEN||
|Initial Value:|0|0|0||0|0||0|0|0|0|0|0|0|0|0|0||0||
|R/W:|R|R|R||R|R||R|R|R|R|R|R|R|R|R|R|R/WC1|||
|**Bit**|**Bit Name**|||**Initial Value**|||**R/W**||**Description**||||||||||||
|31 to 1|—|||All 0|||R||Reserved||||||||||||
||||||||||These bits||are always read as 0. The write value should always be 0.||||||||||
|0|IMGCNT_|||0|||R/WC1||Image Quality Adjustment Block|||||Register Update|||||||
||VEN||||||||0: Registers are not updated.||||||||||||
||||||||||1: Registers are updated||||at the rising edge of the Vsync signal.||||||||

## 30.2.7 NR Control Register 0 (IMGCNT_NR_CNT0)

||Bit:|31|30|29||28|27|27|26|25<br>24<br>23||22||21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||NR1D_|||||NR1D_||
|||—|—|—||—|—||—|—<br>—<br>—||—||—|MD|—|—|—||ON||
||Initial Value:|0|0|0||0||0|0|0<br>0<br>0||0||0|1|0|0|0||0||
||R/W:|R|R|R||R|R||R|R<br>R<br>R||R||R|R/W|R|R|R||R/W||
||Bit:|15|14|13||12|11||10|9<br>8<br>7||6||5|4|3|2|1||0||
|||—||||NR1D_Y_TH[6:0]||||—||—||NR1D_Y_TAP[1:0]||—|—|NR1D_Y_GAIN[1:0]||||
||Initial Value:|0|0|0||0||1|0|0<br>0<br>0||0||0|0|0|0|1||1||
||R/W:|R|R/W|R/W||R/W|R/W||R/W|R/W<br>R/W<br>R||R||R/W|R/W|R|R|R/W||R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**||||||||||||
|31 to 21||—||All||0||R||Reserved||||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||||||||
|20||NR1D_MD||1||||R/W||Horizontal Noise Reduction Operating Mode||||||||||||
|||||||||||0: G/B/R mode||||||||||||
|||||||||||1: Y/Cb/Cr mode||||||||||||
|19 to 17||—||All||0||R||Reserved||||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||||||||
|16||NR1D_ON||0||||R/W||Noise Reduction On/Off Control||||||||||||
|||||||||||0: Noise reduction Off||||||||||||
|||||||||||1: Noise reduction On||||||||||||
|15||—||0||||R||Reserved||||||||||||
|||||||||||This bit is always read as||||0. The|write value should always be|||||0.||
|14 to 8||NR1D_Y_||8||||R/W||Maximum Value (Absolute Value) of Y/G Signal Coring||||||||||||
|||TH[6:0]||||||||Coring is implemented when detected noise amount value ≤||||||||||||
|||||||||||NR1D_Y_TH.||||||||||||
|||||||||||Unsigned: 0 to 127||[LSB]||||||||||
|7,|6|—||All||0||R||Reserved||||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||||||||
|5,|4|NR1D_Y_||0||||R/W||Y/G Signal TAP Select||||||||||||
|||TAP[1:0]||||||||0: Adjacent pixel||||||||||||
|||||||||||1: 2 adjacent pixels||||||||||||
|||||||||||2: 3 adjacent pixels||||||||||||
|||||||||||3: 4 adjacent pixels||||||||||||
|3,|2|—||All||0||R||Reserved||||||||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||||||||
|1,|0|NR1D_Y_||3||||R/W||Noise Reduction Gain Adjustment of Y/G Signal||||||||||||
|||GAIN[1:0]||||||||0: 1/2||||||||||||
|||||||||||1: 1/4||||||||||||
|||||||||||2: 1/8||||||||||||
|||||||||||3: 1/16||||||||||||

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.2.8 NR Control Register 1 (IMGCNT_NR_CNT1)

|Bit:||31|30|29|28|27|26|25|24|23|22|21|20|19|18|17<br>16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|||NR1D_CB_TH[6:0]|||||—|—|NR1D_CB_TAP[1:0]||—|—|NR1D_CB_<br>GAIN[1:0]|
|Initial Value:||0|0|0|0|1|0|0|0|0|0|0|0|0|0|1<br>1|
|R/W:||R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R/W|R/W|R|R|R/W<br>R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1<br>0|
|||—|||NR1D_CR_TH[6:0]|||||—|—|NR1D_CR_TAP[1:0]||—|—|NR1D_CR_<br>GAIN[1:0]|
|Initial Value:||0|0|0|0|1|0|0|0|0|0|0|0|0|0|1<br>1|
|R/W:||R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R/W|R/W|R|R|R/W<br>R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|30 to 24|NR1D_CB_|8|R/W|Maximum Value (Absolute Value) of Cb/B Signal Coring|
||TH[6:0]|||Coring is implemented when detected noise amount value ≤|
|||||NR1D_CB_TH.|
|||||Unsigned: 0 to 127 [LSB]|
|23, 22|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|21, 20|NR1D_CB_|0|R/W|Cb/B Signal TAP Select|
||TAP[1:0]|||0: Adjacent pixel|
|||||1: 2 adjacent pixels|
|||||2: 3 adjacent pixels|
|||||3: 4 adjacent pixels|
|19, 18|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|17, 16|NR1D_CB_|3|R/W|Noise Reduction Gain Adjustment of Cb/B Signal|
||GAIN[1:0]|||0: 1/2|
|||||1: 1/4|
|||||2: 1/8|
|||||3: 1/16|
|15|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|14 to 8|NR1D_CR_|8|R/W|Maximum Value (Absolute Value) of Cr/R Signal Coring|
||TH[6:0]|||Coring is implemented when detected noise amount value ≤|
|||||NR1D_CR_TH.|
|||||Unsigned: 0 to 127 [LSB]|
|7, 6|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|5, 4|NR1D_CR_|0|R/W|Cr/R Signal TAP Select|
||TAP[1:0]|||0: Adjacent pixel|
|||||1: 2 adjacent pixels|
|||||2: 3 adjacent pixels|
|||||3: 4 adjacent pixels|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1, 0|NR1D_CR_|3|R/W|Noise Reduction Gain Adjustment of Cr/R Signal|
||GAIN[1:0]|||0: 1/2|
|||||1: 1/4|
|||||2: 1/8|
|||||3: 1/16|

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.2.9 Image Quality Adjustment Block Matrix Mode Register (IMGCNT_MTX_MODE)

||Bit:|31|30|29||28|27||26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—||—|—||—|—|—|—|—|—|—|—|—|—|—||
||Initial Value:|0|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0||
||R/W:|R|R|R||R|R||R|R|R|R|R|R|R|R|R|R|R||
||Bit:|15|14|13||12|11||10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||||||||IMGCNT_|||
|||—|—|—||—|—||—|—|—|—|—|—|—|—|—|MTX_MD[1:0]|||
||Initial Value:|0|0|0||0|0||0|0|0|0|0|0|0|0|0|1|1||
||R/W:|R|R|R||R|R||R|R|R|R|R|R|R|R|R|R/W|R/W||
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**|||||||||||
|31 to 2||—|||All 0|||R||Reserved|||||||||||
|||||||||||These bits||are always read as 0. The write value should always be 0.|||||||||
|1,|0|IMGCNT_|||3|||R/W||Operating Mode|||||||||||
|||MTX_MD||||||||0: GBR →||GBR|||||||||
|||[1:0]||||||||1: GBR →||YCbCr|||||||||
|||||||||||2: YCbCr → GBR|||||||||||
|||||||||||3: YCbCr → YCbCr|||||||||||

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.2.10 Image Quality Adjustment Block Matrix YG Adjustment Register 0 (IMGCNT_MTX_YG_ADJ0)

|Bit:|31|30||29||28|27||26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—||—||—|—||—|—<br>—<br>IMGCNT_MTX_YG[7:0]||||||
|Initial Value:|0|0||0||0|0||0|0<br>0<br>1<br>0<br>0<br>0|0|0|0|0||
|R/W:|R|R||R||R|R||R|R<br>R<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14||13||12|11||10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
||—|—||—||—|—|||IMGCNT_MTX_GG[10:0]||||||
|Initial Value:|0|0||0||0|0||0|0<br>1<br>0<br>0<br>0<br>0|0|0|0|0||
|R/W:|R|R||R||R|R||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**|**Bit Name**||||**Initial Value**|||**R/W**||**Description**||||||
|31 to 24|—||||All 0|||R||Reserved||||||
|||||||||||These bits are always read as 0. The write value||should always be 0.||||
|23 to 16|IMGCNT_||||128|||R/W||Offset (DC) Adjustment of Y/G Signal||||||
||MTX_YG[7:0]|||||||||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])||||||
|15 to 11|—||||All 0|||R||Reserved||||||
|||||||||||These bits are always read as 0. The write value||should always be 0.||||
|10 to 0|IMGCNT_||||256|||R/W||Y/G Signal Gain Adjustment for Y/G Signal Output||||||
||MTX_GG[10:0]|||||||||Signed (two's complement) (-1024 to +1023 [LSB], 256|||[LSB] = 1.0|||
|||||||||||[times])||||||

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.2.11 Image Quality Adjustment Block Matrix YG Adjustment Register 1 (IMGCNT_MTX_YG_ADJ1)

|||31<br>Bit:|30|29|28||27||26|25<br>24<br>23|22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—|||IMGCNT_MTX_GB[10:0]|||||||
||Initial|0<br>Value:|0|0|0||0||0|0<br>0<br>0|0<br>0<br>0|0|0|0|0||
|||R<br>R/W:|R|R|R||R||R/W|R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|||15<br>Bit:|14|13|12||11||10|9<br>8<br>7|6<br>5<br>4|3|2|1|0||
|||—|—|—|—||—|||IMGCNT_MTX_GR[10:0]|||||||
||Initial|0<br>Value:|0|0|0||0||0|0<br>0<br>0|0<br>0<br>0|0|0|0|0||
|||R<br>R/W:|R|R|R||R||R/W|R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**|||||||
|31|to 27|—||All 0||||R||Reserved|||||||
|||||||||||These bits are always read as 0. The write value should always be||||||0.|
|26|to 16|IMGCNT_||0||||R/W||Cb/B Signal Gain|Adjustment for Y/G Signal||Output||||
|||MTX_GB||||||||Signed (two's complement) (-1024 to +1023|||[LSB], 256 [LSB] = 1.0||||
|||[10:0]||||||||[times])|||||||
|15|to 11|—||All 0||||R||Reserved|||||||
|||||||||||These bits are always read as 0. The write value should always be||||||0.|
|10|to 0|IMGCNT_||0||||R/W||Cr/R Signal Gain|Adjustment for Y/G Signal Output||||||
|||MTX_GR||||||||Signed (two's complement) (-1024 to +1023|||[LSB], 256 [LSB] = 1.0||||
|||[10:0]||||||||[times])|||||||

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.2.12 Image Quality Adjustment Block Matrix CBB Adjustment Register 0 (IMGCNT_MTX_CBB_ADJ0)

|||Bit:||31|30||29|28|27|||26|25<br>24<br>23|22|21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—|—||—|—|—|||—|—<br>—||IMGCNT_MTX_B[7:0]||||||
||Initial|Value:||0|0||0|0|0|||0|0<br>0<br>1|0|0<br>0|0|0|0|0||
|||R/W:||R|R||R|R|R|||R|R<br>R<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W||
|||Bit:||15|14||13|12|11|||10|9<br>8<br>7|6|5<br>4|3|2|1|0||
|||||—|—||—|—|—||||IMGCNT_MTX_BG[10:0]||||||||
||Initial|Value:||0|0||0|0|0|||0|0<br>0<br>0|0|0<br>0|0|0|0|0||
|||R/W:||R|R||R|R|R|||R/W|R/W<br>R/W<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**|||||**Initial Value**|||**R/W**|||**Description**||||||||
|31|to 24|—|||||All|0||R|||Reserved||||||||
||||||||||||||These bits are always read as 0. The write value should always be|||||||0.|
|23|to 16|IMGCNT_|||||128|||R/W|||Offset (DC) Adjustment||of Cb/B Signal||||||
|||MTX_B[7:0]|||||||||||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])||||||||
|15|to 11|—|||||All|0||R|||Reserved||||||||
||||||||||||||These bits are always read as 0. The write value should always be|||||||0.|
|10|to 0|IMGCNT_|||||0|||R/W|||Y/G Signal Gain|Adjustment for Cb/B Signal|||Output||||
|||MTX_BG[10:0]|||||||||||Signed (two's complement) (-1024 to +1023||||[LSB], 256 [LSB] = 1.0||||
||||||||||||||[times])||||||||

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.2.13 Image Quality Adjustment Block Matrix CBB Adjustment Register 1 (IMGCNT_MTX_CBB_ADJ1)

|Bit:|31|30|29||28|27||26|25<br>24<br>23|22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—||—|—|||IMGCNT_MTX_BB[10:0]||||||||
|Initial Value:|0|0|0||0|0||0|0<br>1<br>0|0<br>0|0|0|0|0|0||
|R/W:|R|R|R||R|R||R/W|R/W<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13||12|11||10|9<br>8<br>7|6<br>5|4|3|2|1|0||
||—|—|—||—|—|||IMGCNT_MTX_BR[10:0]||||||||
|Initial Value:|0|0|0||0|0||0|0<br>0<br>0|0<br>0|0|0|0|0|0||
|R/W:|R|R|R||R|R||R/W|R/W<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**|**Bit Name**|||**Initial Value**|||**R/W**||**Description**||||||||
|31 to 27|—|||All 0|||R||Reserved||||||||
||||||||||These bits are always read as 0.||The write value||should always be 0.||||
|26 to 16|IMGCNT_|||256|||R/W||Cb/B Signal Gain|Adjustment for|Cb/B Signal Output||||||
||MTX_BB||||||||Signed (two's complement) (-1024 to +1023 [LSB], 256|||||[LSB] = 1.0|||
||[10:0]||||||||[times])||||||||
|15 to 11|—|||All 0|||R||Reserved||||||||
||||||||||These bits are always read as 0.||The write value||should always be 0.||||
|10 to 0|IMGCNT_|||0|||R/W||Cr/R Signal Gain|Adjustment for|Cb/B Signal Output||||||
||MTX_BR||||||||Signed (two's complement) (-1024 to +1023 [LSB], 256|||||[LSB] = 1.0|||
||[10:0]||||||||[times])||||||||

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.2.14 Image Quality Adjustment Block Matrix CRR Adjustment Register 0 (IMGCNT_MTX_CRR_ADJ0)

|Bit:|31|30||29||28|27||26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—||—||—|—||—|—<br>—<br>IMGCNT_MTX_R[7:0]||||||
|Initial Value:|0|0||0||0|0||0|0<br>0<br>1<br>0<br>0<br>0|0|0|0|0||
|R/W:|R|R||R||R|R||R|R<br>R<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14||13||12|11||10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
||—|—||—||—|—|||IMGCNT_MTX_RG[10:0]||||||
|Initial Value:|0|0||0||0|0||0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
|R/W:|R|R||R||R|R||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**|**Bit Name**||||**Initial Value**|||**R/W**||**Description**||||||
|31 to 24|—||||All 0|||R||Reserved||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||
|23 to 16|IMGCNT_||||128|||R/W||Offset (DC) Adjustment of Cr/R Signal||||||
||MTX_R[7:0]|||||||||Unsigned (0 (-128) to 128 (0) to 255 (+127) [LSB])||||||
|15 to 11|—||||All 0|||R||Reserved||||||
|||||||||||These bits are always read as 0. The write value should always be 0.||||||
|10 to 0|IMGCNT_||||0|||R/W||Y/G Signal Gain Adjustment for Cr/R Signal Output||||||
||MTX_RG[10:0]|||||||||Signed (two's complement) (-1024 to +1023 [LSB], 256|||[LSB]|= 1.0||
|||||||||||[times])||||||

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.2.15 Image Quality Adjustment Block Matrix CRR Adjustment Register 1 (IMGCNT_MTX_CRR_ADJ1)

|Bit:|31|30||29|28|27||26|25<br>24|23|22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—||—|—|—||||IMGCNT_MTX_RB[10:0]||||||||
|Initial Value:|0|0||0|0|0||0|0<br>0|0|0<br>0|0|0|0|0|0||
|R/W:|R|R||R|R|R||R/W|R/W<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14||13|12|11||10|9<br>8|7|6<br>5|4|3|2|1|0||
||—|—||—|—|—||||IMGCNT_MTX_RR[10:0]||||||||
|Initial Value:|0|0||0|0|0||0|0<br>1|0|0<br>0|0|0|0|0|0||
|R/W:|R|R||R|R|R||R/W|R/W<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**|**Bit Name**|||**Initial Value**|||**R/W**||**Description**|||||||||
|31 to 27|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0.|||The write value||should always be 0.||||
|26 to 16|IMGCNT_|||0|||R/W||Cb/B Signal|Gain|Adjustment for|Cr/R Signal Output||||||
||MTX_RB[10:0]||||||||Signed (two's complement) (-1024 to +1023 [LSB], 256||||||[LSB] = 1.0|||
||||||||||[times])|||||||||
|15 to 11|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0.|||The write value||should always be 0.||||
|10 to 0|IMGCNT_|||256|||R/W||Cr/R Signal Gain||Adjustment for|Cr/R Signal Output||||||
||MTX_RR[10:0]||||||||Signed (two's complement) (-1024 to +1023 [LSB], 256||||||[LSB] = 1.0|||
||||||||||[times])|||||||||

Note: This register is updated when the IMGCNT_VEN bit in IMGCNT_UPDATE is 1.

## 30.3 Usage Methods

## 30.3.1 Input Format Adjustment Method

Setting examples of each input format are shown below.

## **Table 30.29 External Input (BT656, 525i) Setting Example**

|**Register Name**|**Bit Name**|**Description**|**Setting Value**|
|---|---|---|---|
|INP_SEL_CNT|INP_SEL|Performs the on/off control of input supplied via|1|
|||the external input pins.||
|INP_SEL_CNT|INP_FORMAT[2:0]|Selects the externally input format.|3|
|INP_SEL_CNT|INP_PXD_EDGE|Selects the clock edge for capturing the externally|0|
|||input video signals.||
|INP_SEL_CNT|INP_VS_EDGE|Selects the clock edge for capturing the externally|0|
|||input Vsync signals.||
|INP_SEL_CNT|INP_HS_EDGE|Selects the clock edge for capturing the externally|0|
|||input Hsync signals.||
|INP_EXT_SYNC_CNT|INP_ENDIAN_ON|Changes the bit endian of the external input.|0|
|INP_EXT_SYNC_CNT|INP_SWAP_ON|Enables or disables the B/R signal swap of the|0|
|||external input.||
|INP_EXT_SYNC_CNT|INP_HS_INV|Enables or disables the Hsync signal inversion of|1|
|||the external input.||
|INP_EXT_SYNC_CNT|INP_VS_INV|Enables or disables the Hsync signal inversion of|1|
|||the external input.||
|INP_EXT_SYNC_CNT|INP_H_EDGE_SEL|Selects the Hsync reference for BT656 input.|0|
|INP_EXT_SYNC_CNT|INP_F525_625|Sets the number of lines for BT656 input.|0|
|INP_EXT_SYNC_CNT|INP_H_POS[1:0]|Sets the data start timing with respect to the|0|
|||Hsync in the BT656/601 format.||
|INP_VSYNC_PH_ADJ|INP_FH50[9:0]|Sets the 1/2fH phase in clock cycle units.|858|
|INP_VSYNC_PH_ADJ|INP_FH25[9:0]|Sets the 1/4fH phase in clock cycle units.|429|
|INP_DLY_ADJ|INP_VS_DLY_L[2:0]|Sets the number of lines for delaying the Vsync|0|
|||signal and field differentiation signal.||
|INP_DLY_ADJ|INP_VS_DLY[7:0]|Sets the amount of delay of the Vsync signal in|0|
|||clock cycle units.||
|INP_DLY_ADJ|INP_HS_DLY[7:0]|Sets the amount of delay of the Hsync signal in|0|
|||clock cycle units.||
|INP_DLY_ADJ|INP_FLD_DLY[7:0]|Sets the amount of delay of the field|0|
|||differentiation signal in clock units.||

Note: Some registers require, after they are set, that the INP_EXT_UPDATE and INP_IMG_UPDATE bits in INP_UPDATE should be set to 1.

**Table 30.30 External Input (BT601, 525i) Setting Example**

||||**Setting**|
|---|---|---|---|
|**Register Name**|**Bit Name**|**Description**|**Value**|
|INP_SEL_CNT|INP_SEL|Performs the on/off control of input supplied via the|1|
|||external input pins.||
|INP_SEL_CNT|INP_FORMAT[2:0]|Selects the externally input format.|4|
|INP_SEL_CNT|INP_PXD_EDGE|Selects the clock edge for capturing the externally input|0|
|||video signals.||
|INP_SEL_CNT|INP_VS_EDGE|Selects the clock edge for capturing the externally input|0|
|||Vsync signals.||
|INP_SEL_CNT|INP_HS_EDGE|Selects the clock edge for capturing the externally input|0|
|||Hsync signals.||
|INP_EXT_SYNC_CNT|INP_ENDIAN_ON|Changes the bit endian of the external input.|0|
|INP_EXT_SYNC_CNT|INP_SWAP_ON|Enables or disables the B/R signal swap of the external|0|
|||input.||
|INP_EXT_SYNC_CNT|INP_HS_INV|Enables or disables the Hsync signal inversion of the|1|
|||external input.||
|INP_EXT_SYNC_CNT|INP_VS_INV|Enables or disables the Hsync signal inversion of the|1|
|||external input.||
|INP_EXT_SYNC_CNT|INP_H_EDGE_SEL|Selects the Hsync reference for BT656 input.|0|
|INP_EXT_SYNC_CNT|INP_F525_625|Sets the number of lines for BT656 input.|0|
|INP_EXT_SYNC_CNT|INP_H_POS[1:0]|Sets the data start timing with respect to the Hsync in the|0|
|||BT656/601 format.||
|INP_VSYNC_PH_ADJ|INP_FH50[9:0]|Sets the 1/2fH phase in clock cycle units.|858|
|INP_VSYNC_PH_ADJ|INP_FH25[9:0]|Sets the 1/4fH phase in clock cycle units.|429|
|INP_DLY_ADJ|INP_VS_DLY_L[2:0]|Sets the number of lines for delaying the Vsync signal|0|
|||and field differentiation signal.||
|INP_DLY_ADJ|INP_VS_DLY[7:0]|Sets the amount of delay of the Vsync signal in clock|0|
|||cycle units.||
|INP_DLY_ADJ|INP_HS_DLY[7:0]|Sets the amount of delay of the Hsync signal in clock|0|
|||cycle units.||
|INP_DLY_ADJ|INP_FLD_DLY[7:0]|Sets the amount of delay of the field differentiation signal|0|
|||in clock units.||

Note: Some registers require, after they are set, that the INP_EXT_UPDATE and INP_IMG_UPDATE bits in INP_UPDATE should be set to 1.

## 30.3.2 Usage Method of Conversion Color Matrix

Typical data conversion setting examples are shown below.

## **Table 30.31 Conversion Color Matrix**

|||**GBR to**|**GBR to**|**YCbCr to**|**YCbCr to**|
|---|---|---|---|---|---|
|**Register Name**|**Bit Name**|**GBR**|**YCbCr**|**GBR**|**YCbCr**|
|IMGCNT_MTX_MODE|IMGCNT_MTX_MD[1:0]|0|1|2|3|
|IMGCNT_MTX_YG_ADJ0|IMGCNT_MTX_YG[7:0]|128|128|128|128|
|IMGCNT_MTX_YG_ADJ0|IMGCNT_MTX_GG[10:0]|256|150|256|256|
|IMGCNT_MTX_YG_ADJ1|IMGCNT_MTX_GB[10:0]|0|29|1960|0|
|IMGCNT_MTX_YG_ADJ1|IMGCNT_MTX_GR[10:0]|0|77|1865|0|
|IMGCNT_MTX_CBB_ADJ0|IMGCNT_MTX_B[7:0]|128|128|128|128|
|IMGCNT_MTX_CBB_ADJ0|IMGCNT_MTX_BG[10:0]|0|1963|256|0|
|IMGCNT_MTX_CBB_ADJ1|IMGCNT_MTX_BB[10:0]|256|128|454|256|
|IMGCNT_MTX_CBB_ADJ1|IMGCNT_MTX_BR[10:0]|0|2005|0|0|
|IMGCNT_MTX_CRR_ADJ0|IMGCNT_MTX_R[7:0]|128|128|128|128|
|IMGCNT_MTX_CRR_ADJ0|IMGCNT_MTX_RG[10:0]|0|1941|256|0|
|IMGCNT_MTX_CRR_ADJ1|IMGCNT_MTX_RB[10:0]|0|2027|0|0|
|IMGCNT_MTX_CRR_ADJ1|IMGCNT_MTX_RR[10:0]|256|128|359|256|

Note: The registers require, after they are set, that the IMGCNT_VEN bit in IMGCNT_UPDATE should be set to 1.
