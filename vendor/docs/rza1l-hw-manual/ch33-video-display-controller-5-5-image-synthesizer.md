# 33. Video Display Controller 5 (5): Image Synthesizer

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1760–1815. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 33.1 Image Synthesizer

## 33.1.1 Overview of Functions

The image synthesizer reads graphics data from the frame buffer and displays the synthesized image on the screen.

One video plane + two graphics planes, or three graphics planes can be selected for synthesis.

RGB565, RGB888, αRGB1555, αRGB4444, αRGB8888, RGBα5551, RGBα8888, CLUT8, CLUT4, CLUT1, YCbCr422 (for the graphics 0 process), and YCbCr444 (for the graphics 0 process) formats can be used for graphics data, and RGB565, RGB888, YCbCr422, and YCbCr444 formats for video data.

On each of the graphics planes, background color, lower-layer graphics, current graphics, or blended image (for the graphics 2 and 3 processes) of lower-layer graphics and current graphics can be displayed.

It is recommend that the frame buffer is placed in the on-chip large-capacity RAM. Both the on-chip large-capacity RAM and an external SDRAM can be used for the frame buffer, but the bus bandwidth might become short and display might not be possible if an external SDRAM is used for the frame buffer.

The functional block diagram of the image synthesizer is shown below.

**==> picture [433 x 281] intentionally omitted <==**

**----- Start of picture text -----**<br>
IV6-BUS(read)<br>IV5-BUS(read)<br>IV3-BUS(read)<br>RGB565 = 16 bitsRGB888 = 32 bits[Moving picture] RGB565 = 16 bitsRGB888 = 32 bits[Graphics] RGB565 = 16 bitsRGB888 = 32 bits[Graphics] RGB565 =RGB888 =[Graphics]16 bits32 bits<br>YCbCr422 = 16 bits<br>CLUT8 = 8 bits CLUT8 = 8 bits CLUT8 = 8 bits<br>CLUT4 = 4 bitsCLUT1 = 1 bit CLUT4CLUT1 = 1= 4 bitsbit CLUT4 = 4 bitsCLUT1 = 1 bit<br>YCbCr422 = 16 bits<br>Internal bus read Internal bus read Internal bus read<br>control control control<br>Buffer write Buffer write Buffer write<br>control control control<br>Buffer read Buffer read Buffer read<br>control control control<br>422 to 444<br>conversion<br>HS,VS,HE,VE Internal bus read Internal bus read Internal bus read<br>control 1 control 2 control 3<br>Bit extension Bit extension Bit extension<br>CLUT control CLUT control CLUT control<br>enable signal generationOutput image  Data expansion 1 Data expansion 2 Data expansion 3<br>Enable adjustment Switching [Graphics]<br>Vertical scale up [Current graphics] [Curren tgrapcih]s [Curren tgrapcih]s<br>Horizontal scale up(two TAP linear) [Moving picture,scale up]<br>(two TAP linear)<br>Scale-up control blockTrimming synthesizing blockMoving pictureand backgroundmoving pictureSynthesis of YCbCr/RGB888(24 bits)HS,VSHE,VE YCbCr/RGB888(24 bits)HS,VSHE,VE Image qualityimprover 0 [Lower-layerGraphics]RGB888(24 bits)HS,VSHE,VE Alpha blending 2 RGB888(24 bits)HS,VSHE,VE [Lower-layerGraphics]RGB888(24 bits)HS,VSHE,VE Alpha blending 3 RGB888(24 bits)HS,VSHE,VE ControllerOutput<br>Register control Register control Register control Register control<br>Scaler 0 (synchronization, scale up) Scaler 0 (graphics 0) Image synthesizer  Image synthesizer<br>(graphics 2) (graphics 3)<br>VIN<br>synthesizer<br>Line buffer Line buffer Line buffer<br>CLUT table CLUT table CLUT table<br>Enable signal generation Output select Enable signal generation Alpha blending Enable signal generation Alpha blending<br>**----- End of picture text -----**<br>

**Figure 33.1 Functional Block Diagram of Image Synthesizer**

## 33.1.2 Graphics Data Read Control

Graphics data read can be controlled for the three processes: the graphics 0 process in the scaler 0, and the graphics 2 and 3 processes in the image synthesizer.

The register bits of each process can be identified by the number in the register name like GR0_xxxx, GR2_xxxx, and GR3_xxxx, respectively. In the sections except for Register Descriptions, however, the number is omitted like GR_xxxx for convenience sake.

In the VIN synthesizer, graphics data read is not controlled. In this manual, the name is omitted like GR_xxxx for convenience sake. The synthesizer does not have the read control register (GR_FLM).

## (1) Updating Registers

The Vsync signal is used to control the update timing of the registers for graphics display and frame buffer read control, except for some of the registers.

After 1 is set to the bits in the update control register, the contents of the relevant registers are actually modified at the rising edge of the Vsync signal, when the update control register is automatically cleared to 0.

## **Table 33.1 Register Update Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_UPDATE|GR_UPDATE|0|Frame Buffer Read Control Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated.|
|GR_UPDATE|GR_P_VEN|0|Graphics Display Register Update|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|
|GR_UPDATE|GR_IBUS_VEN|0|Frame Buffer Read Register Update*|
||||0: Registers are not updated.|
||||1: Registers are updated at the rising edge of the Vsync.|

Note: * This bit is not supported for the VIN synthesizer.

## (2) Frame Buffer Burst Transfer Mode

Either 32-byte or 128-byte transfer mode can be selected for accessing the frame buffer in which video data and graphics data are stored.

**Table 33.2 Frame Buffer Burst Transfer Mode**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM1|GR_BST_MD|0|Frame Buffer Burst Transfer Mode|
||||0: 32-byte transfer|
||||1: 128- byte transfer|

## (3) Frame Buffer Control Mode

More than one frame of data is read from the frame buffer.

For graphics data, set the GR_FLM_SEL[1:0] bits to 1, and set the specific display frame number with the GR_FLM_NUM[9:0] bits. For video data, select a mode with the GR_FLM_SEL[1:0] bits depending on the writing process used; the quantity of the frames used for video data is set in the writing process block.

## **Table 33.3 Frame Buffer Control Mode**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM1|GR_FLM_SEL[1:0]|0|Frame Buffer Address Setting Signal Select|
||||0: Control linked to scaling-down process, or frame 0 selected.*1|
||||1: Register GR_FLM_NUM selected.|
||||2: Frame 0 selected.|
||||3: Control linked to pointer buffer, or setting prohibited.*2|
|GR_FLM3|GR_FLM_NUM[9:0]|0|Frame Number of Frame Buffer|
||||Manually set the frame number when GR_FLM_SEL = 1.|

- Notes: 1. For the graphics 0 process, frame buffer control links to the scaling-down process. For the graphics 2 and 3 processes, frame 0 is selected.

   2. For the graphics 0 process, frame buffer control links to the pointer buffer. For the graphics 2 and 3 processes, setting is prohibited.

## (4) Frame Buffer Read Control

The following bit enables or disables read access to the frame buffer.

## **Table 33.4 Frame Buffer Read Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM_RD|GR_R_ENB|0|Frame Buffer Read Enable|
||||0: Disables read access to the frame buffer.|
||||1: Enables read access to the frame buffer.|

## (5) Frame Buffer Size

The following bits set the size of the frame buffer to be read.

The numbers of horizontal pixels and of lines in the vertical direction are set with the GR_HW[10:0] and GR_FLM_LNUM[10:0] bits, respectively.

## **Table 33.5 Frame Buffer Size**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM6|GR_HW[10:0]|0|Sets the width of the horizontal valid period.|
||||The width is (GR_HW + 1) pixels.|
||||Note: Set to 2 or greater.|
|GR_FLM5|GR_FLM_LNUM[10:0]|0|Sets the number of lines in a frame|
||||The number of lines is (GR_FLM_LNUM + 1).|

## (6) Calculating Addresses in Frame Buffer

The data area in the frame buffer is defined using the addresses specified by GR_BASE[31:0], GR_LN_OFF[14:0], and GR_FLM_OFF[22:0] bits and the display frame number.

The GR_LN_OFF[14:0] and GR_FLM_OFF[22:0] bits should be set in units of 32/128 bytes (the lower 5/7 bits should be fixed to 0).

The GR_BASE[31:0] bits should be set in units of 64 bits to set the display data start position (the lower three bits should be fixed).

**==> picture [278 x 299] intentionally omitted <==**

**----- Start of picture text -----**<br>
GR_BASE<br>Start address<br>GR_HW+1<br>Number of pixels in horizontal direction<br>Frame 0<br>GR_LN_OFF<br>Line offset<br>GR_HW+1<br>Number of pixels in horizontal direction<br>Frame 1<br>LNUM+1<br>_<br>FLM<br>_<br>GR Number of lines in vertical direction<br>GR_FLM_OFF Frame offset<br>LNUM+1<br>_<br>FLM<br>_<br>GR Number of lines in vertical direction<br>**----- End of picture text -----**<br>

**Figure 33.2 Data Arrangement in Frame Buffer**

**Table 33.6 Calculation of Addresses in Frame Buffer**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM2|GR_BASE[31:0]|0|Frame Buffer Base Address|
||||Sets the start address of the frame buffer where frame data is to be|
||||stored.|
||||GR_BASE[4:3] and GR_BASE[6:3] are referred to during 32-byte burst|
||||transfer and 128-byte burst transfer, respectively, to skip the start line|
||||data.|
||||The lower 3 bits should be set to 000.|
|GR_FLM3|GR_LN_OFF[14:0]|0|Frame Buffer Line Offset Address|
||||Sets the line offset address for calculating the start address of each line.|
||||Line 0:GR_BASE|
||||Line 1:GR_BASE + GR_LN_OFF × 1|
||||:|
||||Line n: GR_BASE + GR_LN_OFF × n|
||||For 32-byte transfer, the lower 5 bits should be fixed to 0_0000.|
||||For 128-byte transfer, the lower 7 bits should be fixed to 000_0000.|
|GR_FLM4|GR_FLM_OFF[22:0]|0|Frame Buffer Frame Offset Address (lower)|
||||Specifies the frame offset address used for calculating the start address|
||||of each frame buffer when more than one buffer is used.|
||||Buffer 0: GR_BASE|
||||Buffer 1: GR_BASE + GR_FLM_OFF × 1|
||||:|
||||Buffer n: GR_BASE + GR_FLM_OFF × n|
||||For 32-byte transfer, the lower 5 bits should be fixed to 0_0000.|
||||For 128-byte transfer, the lower 7 bits should be fixed to 000_0000.|

## (7) Setting Frame Buffer Size Smaller than One Frame

Frame buffer size can be set in one-line units.

When the number of lines set with the GR_FLM_LOOP[10:0] bits is smaller than the value of the

GR_FLM_LNUM[10:0] bits, data is again read from the start address of the frame buffer after the number of lines set with the (GR_FLM_LOOP[10:0] + 1) bits have been read.

**Table 33.7 Setting of Frame Buffer Size Smaller than One Frame**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM5|GR_FLM_LOOP[10:0]|1023|Number of lines when reading the addresses repeatedly by|
||||returning to the start address after reaching the end address.|
||||The number of lines is (GR_FLM_LOOP + 1).|

## (8) Line Offset Control for Frame Buffer

The following bit sets the line offset address direction of the frame buffer.

## **Table 33.8 Line Offset Address Direction Control for Frame Buffer**

**==> picture [483 x 415] intentionally omitted <==**

**----- Start of picture text -----**<br>
Register Name Bit Name Initial Value Description<br>GR_FLM1 GR_LN_OFF_DIR 0 Selects the line offset address direction of the frame buffer.<br>0:Increments the address by the line offset address.<br>1:Decrements the address by the line offset address.<br>GR_LN_OFF<br>Line offset<br>GR_HW+1<br>Number of pixels in horizontal direction<br>Frame 0<br>Data is read in a vertically-reversed order<br>starting at the address specified by<br>GR_BASE.<br>GR_BASE<br>Start address<br>GR_HW+1<br>Number of pixels in horizontal direction<br>Frame 1<br>LNUM+1<br>_<br>FLM<br>_<br>GR Number of lines in vertical direction<br>GR_FLM_OFF Frame offset<br>LNUM+1<br>_<br>FLM<br>_<br>GR Number of lines in vertical direction<br>**----- End of picture text -----**<br>

**Figure 33.3 Data Arrangement with Line Offset and Decrement Control**

## (9) Selecting Format of Frame Buffer Read Signal

Signal formats RGB565, RGB888, αRGB1555, αRGB4444, αRGB8888, RGBα5551, RGBα8888, CLUT8, CLUT4 and CLUT1 are supported for the graphics 0, 2, and 3 processes. The YCbCr422 and YCbCr444 formats are also supported for the graphics 0 process.

The GR_FORMAT[3:0] bits select a signal format.

## **Table 33.9 Format Selection for Frame Buffer Read Signal**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM6|GR_FORMAT[3:0]|0|Sets the format of the frame buffer read signal.|
||||0: RGB565|
||||1: RGB888|
||||2:αRGB1555|
||||3:αRGB4444|
||||4:αRGB8888|
||||5: CLUT8|
||||6: CLUT4|
||||7: CLUT1|
||||8: YCbCr422 or setting prohibited *|
||||9: YCbCr444 or setting prohibited *|
||||10: RGBα5551|
||||11: RGBα8888|
||||12 to 15: Setting prohibited|

Note: * Setting this value selects YCbCr422 and YCbCr444 for the graphics 0 process, and is prohibited for the graphics 2 and 3 processes.

## (10) Endian Control

In the frame buffer, data is handled in 64-bit units, and endian of the data to be read can be controlled by setting the GR_RDSWA[2:0] bits. Bit 0 of these bits indicates whether 8-bit data is swapped. Bit 1 indicates whether 16-bit data is swapped. Bit 2 indicates whether 32-bit data is swapped. In the YCbCr422 format, data can be arranged with the GR_YCC_SWAP[2:0] bits.

|||||||||||||||||||||||||||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|YCbCr422<br>RGB565<br>RGB888<br>ARGB1555<br>ARGB4444<br>ARGB8888<br>CLUT8<br>CLUT4<br>CLUT1<br>RGBA5551<br>RGBA8888<br>YCbCr444|[63]<br>[56]|||||[55]<br>[48]|||||[47]<br>[40]|||||[39]<br>[32]|||||[31]<br>[24]|||||[23]<br>[16]|||||[15]<br>[8]|||||[7]<br>[0]||||||
||R0[7:3]|||G0[||7:2]||B0[7:3]|||R1[7:3]|||G1[||7:2]||B1[7:3]|||R2[7:3]|||G2[||7:2]||B2[7:3]|||R3[7:3]|||G3[||7:2]||B3[7:3]||||
||8'h00|||||R0[7:0]|||||G0[7:0]|||||B0[7:0]|||||8'h00|||||R1[7:0]|||||G1[7:0]|||||B1[7:0]||||||
||A0|R0[7:3]|||G|0[7:3]||B0[7:3]|||A1|R1[7:3]|||G|1[7:3]||B1[7:3]|||A2|R2[7:3]|||G|2[7:3]||B2[7:3]|||A3|R3[7:3]|||G|3[7:3]||B3[7:3]||||
||A0[7:4]||R0[7:4]|||G0[7:4]|||B0[7:4]||A1[7:4]||R1[7:4]|||G1[7:4]|||B1[7:4]||A2[7:4]||R2[7:4]|||G2[7:4]|||B2[7:4]||A3[7:4]||R3[7:4]|||G3[7:4]|||B3[7:4]|||
||A0[7:0]|||||R0[7:0]|||||G0[7:0]|||||B0[7:0]|||||A1[7:0]|||||R1[7:0]|||||G1[7:0]|||||B1[7:0]||||||
|||||||||||||||||||||||||||||||||||||||||||
||R0[7:3]|||G0[7:||3]|B0[7:3]|||A0|R1[7:3]|||G1[7:||3]|B1[7:3]|||A1|R2[7:3]|||G2[7:||3]|B2[7:3]|||A2|R3[7:3]|||G3[7:||3]|B3[7:3]|||A3||
||R0[7:0]|||||G0[7:0]|||||B0[7:0]|||||A0[7:0]|||||R1[7:0]|||||G1[7:0]|||||B1[7:0]|||||A1[7:0]||||||
||CLUT0[7:0]|||||CLUT1[7:0]|||||CLUT2[7:0]|||||CLUT3[7:0]|||||CLUT4[7:0]|||||CLUT5[7:0]|||||CLUT6[7:0]|||||CLUT7[7:0]||||||
||CLUT0[7:4]||CLUT1[7:4]|||CLUT2[7:4]|||CLUT3[7:4]||CLUT4[7:4]||CLUT5[7:4]|||CLUT6[7:4]|||CLUT7[7:4]||CLUT8[7:4]||CLUT9[7:4]|||CLUT10[7:4]|||CLUT11[7:4]||CLUT12[7:4]||CLUT13[7:4]|||CLUT14[7:4]|||CLUT15[7:4]|||
||CLUT0, 1, . . . , 6, 7|||||CLUT8, 9, . . . , 14, 15|||||CLUT16, 17, . . . , 22, 23|||||CLUT24, 25, . . . , 30, 31|||||CLUT32, 33, . . . , 38, 39|||||CLUT40, 41, . . . , 46, 47|||||CLUT48, 49, . . . , 54, 55|||||CLUT56, 57, . . . , 62, 63||||||
||CB0[7:0]|||||Y0[7:0]|||||CR0[7:0]|||||Y1[7:0]|||||CB2[7:0]|||||Y2[7:0]|||||CR2[7:0]|||||Y3[7:0]||||||
||8'h00|||||CR0[7:0]|||||Y0[7:0]|||||CB0[7:0]|||||8'h00|||||CR1[7:0]|||||Y1[7:0]|||||CB1[7:0]||||||
|||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||

**Figure 33.4 Data Arrangement with Endian Control Disabled (GR_RDSWA = 000)**

|GR_RDSWA = 000<br>GR_RDSWA = 001<br>GR_RDSWA = 010<br>GR_RDSWA = 011<br>GR_RDSWA = 100<br>GR_RDSWA = 101<br>GR_RDSWA = 110<br>GR_RDSWA = 111|||||||||
|---|---|---|---|---|---|---|---|---|
||(1) 8 bits|(2) 8 bits|(3) 8 bits|(4) 8 bits|(5) 8 bits|(6) 8 bits|(7) 8 bits|(8) 8 bits|
||||||||||
||(2) 8 bits|(1) 8 bits|(4) 8 bits|(3) 8 bits|(6) 8 bits|(5) 8 bits|(8) 8 bits|(7) 8 bits|
||(3) 8 bits|(4) 8 bits|(1) 8 bits|(2) 8 bits|(7) 8 bits|(8) 8 bits|(5) 8 bits|(6) 8 bits|
||(4) 8 bits|(3) 8 bits|(2) 8 bits|(1) 8 bits|(8) 8 bits|(7) 8 bits|(6) 8 bits|(5) 8 bits|
||(5) 8 bits|(6) 8 bits|(7) 8 bits|(8) 8 bits|(1) 8 bits|(2) 8 bits|(3) 8 bits|(4) 8 bits|
||||||||||
||(6) 8 bits|(5) 8 bits|(8) 8 bits|(7) 8 bits|(2) 8 bits|(1) 8 bits|(4) 8 bits|(3) 8 bits|
||||||||||
||(7) 8 bits|(8) 8 bits|(5) 8 bits|(6) 8 bits|(3) 8 bits|(4) 8 bits|(1) 8 bits|(2) 8 bits|
||||||||||
||(8) 8 bits|(7) 8 bits|(6) 8 bits|(5) 8 bits|(4) 8 bits|(3) 8 bits|(2) 8 bits|(1) 8 bits|
||||||||||

**Figure 33.5 Data Arrangement with Endian Control Enabled**

||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||[63]|[56]|[55]|[48]|[47]|[40]|[39]<br>[32]|[31]|[24]|[23]|[16]|[15]|[8]|[7]|[0]||
|YCC_SWAP = 0||CB0[7:0]||Y0[7:0]||CR0[7:0]|Y1[7:0]|CB2[7:0]|||Y2[7:0]||CR2[7:0]||Y3[7:0]||
||||||||||||||||||
|YCC_SWAP = 1||Y0[7:0]||CB0[7:0]||Y1[7:0]|CR0[7:0]|Y2[7:0]|||CB2[7:0]||Y3[7:0]||CR2[7:0]||
||||||||||||||||||
|YCC_SWAP = 2||CR0[7:0]||Y0[7:0]||CB0[7:0]|Y1[7:0]|CR2[7:0]|||Y2[7:0]||CB2[7:0]||Y3[7:0]||
||||||||||||||||||
|YCC_SWAP = 3||Y0[7:0]||CR0[7:0]||Y1[7:0]|CB0[7:0]|Y2[7:0]|||CR2[7:0]||Y3[7:0]||CB2[7:0]||
||||||||||||||||||
|YCC_SWAP = 4||Y1[7:0]||CR0[7:0]||Y0[7:0]|CB0[7:0]|Y3[7:0]|||CR2[7:0]||Y2[7:0]||CB2[7:0]||
||||||||||||||||||
|YCC_SWAP = 5||CR0[7:0]||Y1[7:0]||CB0[7:0]|Y0[7:0]|CR2[7:0]|||Y3[7:0]||CB2[7:0]||Y2[7:0]||
||||||||||||||||||
|YCC_SWAP = 6||Y1[7:0]||CB0[7:0]||Y0[7:0]|CR0[7:0]|Y3[7:0]|||CB2[7:0]||Y2[7:0]||CR2[7:0]||
||||||||||||||||||
|YCC_SWAP = 7||CB0[7:0]||Y1[7:0]||CR0[7:0]|Y0[7:0]|CB2[7:0]|||Y3[7:0]||CR2[7:0]||Y2[7:0]||
||||||||||||||||||
||||||||||||||||||
|**Figure 33.6**||**YCbCr422**||**Data Arrangement with Swapping Enabled**|||||||||||||
|**Table 33.10**||**Endian Control**|||||||||||||||
|**Register Name**||**Bit Name**|||**Initial Value**||**Description**||||||||||
|GR_FLM6||GR_RDSWA[2:0]|||0||Sets 8-, 16-,|and 32-bit swap.|||||||||
||||||||These three|bits specify|the|method for swapping the bits||||of frame buffer|||
||||||||read data as|follows.|||||||||
||||||||Bit 0||||||||||
||||||||0: 8 bits are not swapped.||||||||||
||||||||1: 8 bits are swapped.||||||||||
||||||||Bit 1||||||||||
||||||||0: 16 bits are not swapped.||||||||||
||||||||1: 16 bits are swapped.||||||||||
||||||||Bit 2||||||||||
||||||||0: 32 bits are not swapped.||||||||||
||||||||1: 32 bits are swapped.||||||||||
||||||||When eight bits are put together, they are swapped as follows. Each of (1)||||||||||
||||||||to (8) indicates eight-bit data.||||||||||
||||||||000: (1) (2) (3) (4) (5) (6) (7) (8) [No swap]||||||||||
||||||||001: (2) (1) (4) (3) (6) (5) (8) (7) [8-bit swap]||||||||||
||||||||010: (3) (4) (1) (2) (7) (8) (5) (6) [16-bit swap]||||||||||
||||||||011: (4) (3) (2) (1) (8) (7) (6) (5) [16-bit swap +||||||8-bit swap]||||
||||||||100: (5) (6) (7) (8) (1) (2) (3) (4) [32-bit swap]||||||||||
||||||||101: (6) (5) (8) (7) (2) (1) (4) (3) [32-bit swap +||||||8-bit swap]||||
||||||||110: (7) (8) (5) (6) (3) (4) (1) (2) [32-bit swap +||||||16-bit swap]||||
||||||||111: (8) (7) (6) (5) (4) (3) (2) (1) [32-bit swap +||||||16-bit swap + 8-bit swap]||||

## **Table 33.10 Endian Control**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM6|GR_YCC_SWAP|0|Controls swapping of data read from buffer in the YCbCr422 format. *|
||[2:0]||0: Cb/Y0/Cr/Y1|
||||1: Y0/Cb/Y1/Cr|
||||2: Cr/Y0/Cb/Y1|
||||3: Y0/Cr/Y1/Cb|
||||4: Y1/Cr/Y0/Cb|
||||5: Cr/Y1/Cb/Y0|
||||6: Y1/Cb/Y0/Cr|
||||7: Cb/Y1/Cr/Y0|

Note: * These bits are supported for the graphics 0 process only.

## (11) Display Start Pixel Setting for Read Data

When a horizontal offset is applied to display the image data in the frame buffer, the display start pixel is set with the GR_BASE[31:0] and GR_STA_POS[5:0] bits. Calculation of the values for the GR_BASE[31:0] and

GR_STA_POS[5:0] bits depends on the signal format. The display start pixel can be calculated with the formulas in the table below, where H_OFF is a horizontal offset from the display start pixel.

**Table 33.11 Calculation of Display Start Position for Various Signal Formats**

|**Signal Format of Video/Graphics**|**Number of Bits per Pixel**|**Calculation Formula *1**|
|---|---|---|
|RGB888|32|GR_BASE[31:3] = t (H_OFF ÷ 2)|
|αRGB8888,||GR_STA_POS[5:0] = mod (H_OFF ÷ 2)|
|RGBα8888|||
|YCbCr422*2|||
|YCbCr444*3|||
|RGB565|16|GR_BASE[31:3] = int (H_OFF ÷ 4)|
|αRGB1555,||GR_STA_POS[5:0] = mod (H_OFF ÷ 4)|
|RGBα5551|||
|αRGB4444|||
|CLUT8|8|GR_BASE[31:3] = int (H_OFF ÷ 8)|
|||GR_STA_POS[5:0] = mod (H_OFF ÷ 8)|
|CLUT4|4|GR_BASE[31:3] = int (H_OFF ÷ 16)|
|||GR_STA_POS[5:0] = mod (H_OFF ÷ 16)|
|CLUT1|1|GR_BASE[31:3] = int (H_OFF ÷ 64)|
|||GR_STA_POS[5:0] = mod (H_OFF ÷ 64)|

- Notes: 1. The functions int() and mod() output a quotient and a remainder, respectively.

   2. The YCbCr422 format is not supported for the graphics 2 and 3 processes.

      - In the YCbCr422 format, 32 bits are used for two pixels (Cb, Y0, Cr, and Y1 components). Therefore, the start position is controlled in units of 32 bits.

   3. The YCbCr444 format is not supported for the graphics 2 and 3 processes.

**Table 33.12 Setting of Display Start Pixel of Read Data**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM6|GR_STA_POS[5:0]|0|Sets the amount of data to be skipped through.|
||||Specifically data amount equal to the amount indicated by|
||||GR_STA_POS is skipped from the start of the line.|
|GR_FLM2|GR_BASE[31:0]|0|Frame Buffer Base Address|
||||Sets the start address of the frame buffer where frame data is|
||||to be stored.|
||||GR_BASE[4:3] and GR_BASE[6:3] are referred to during 32-|
||||byte burst transfer and 128-byte burst transfer, respectively, to|
||||skip the start line data.|
||||The lower 3 bits should be fixed to 000.|

## (12) YCbCr422 to YCbCr444 Conversion

Data format for the graphics 0 process is converted from YCbCr422 to YCbCr444.

This function is not supported for the graphics 2 and 3 processes.

## **Table 33.13 YCbCr422 to YCbCr444 Conversion**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_FLM6|GR_CNV444_MD|0|Sets the interpolation mode for YCbCr422 to YCbCr444|
||||conversion. *|
||||0: Hold interpolation|
||||1: Average interpolation|

Note: * This bit is not provided for the graphics 2 and 3 processes, for which the YCbCr422 format is not supported.

## (13) Bit Extension

When the value of the GR_FORMAT[3:0] bits is 0 to 3, the RGB565, RGB888, αRGB1555, and αRGB4444 formats are converted to the αRGB8888 format. When the value of the GR_FORMAT[3:0] bits is 10, the RGBα5551 format is converted to the RGBα8888 format. The RGBα5551 to RGBα8888 format conversion is omitted because it differs from the αRGB5551 to αRGB8888 format conversion only in the position of α.

- RGB565 to αRGB8888 Format Conversion

After conversion, α [7:0] is fixed to 255.

After conversion, R[7:0] = R[4:0] × 263 ÷ 32 (round off to an integer), approximation of #R[4:0] × 255 ÷ 31 After conversion G[7:0] = G[5:0] × 259 ÷ 64 (round off to an integer), approximation of #G[5:0] × 255 ÷ 63 After conversion, B[7:0] = B[4:0] × 263 ÷ 32 (round off to an integer), approximation of #B[4:0] × 255 ÷ 31

- RGB888 to αRGB8888 Format Conversion

After conversion, α [7:0] is fixed to 255.

- αRGB1555 to αRGB8888 Format Conversion

After conversion, α [7:0] is GR_A1 when α input is 1, and GR_A0 when 0.

After conversion, R[7:0] = R[4:0] × 263 ÷ 32 (round off to an integer), approximation of #R[4:0] × 255 ÷ 31 After conversion, G[7:0] = G[4:0] × 263 ÷ 32 (round off to an integer), approximation of #G[4:0] × 255 ÷ 31 After conversion, B[7:0] = B[4:0] × 263 ÷ 32 (round off to an integer), approximation of #B[4:0] × 255 ÷ 31

- αRGB4444 to αRGB8888 Format Conversion

After conversion, α [7:0] = α [3:0] × 17

After conversion, R[7:0] = R[3:0] × 17 After conversion, G[7:0] = G[3:0] × 17 After conversion, B[7:0] = B[3:0] × 17

## (14) Buffer Underflow Processing

When data read from the frame buffer cannot be completed due to bus-traffic related problems, an underflow interrupt signal is output.

## 33.1.3 Setting Graphics Display Area

The graphics display area is set with the GR_GRC_HS[10:0], GR_GRC_HW[10:0], GR_GRC_VS[10:0], and GR_GRC_VW[10:0] bits based on the rising edges of the Hsync and Vsync signals.

Figure 33.7 shows the graphics display area.

**==> picture [398 x 332] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clock<br>Hsync signal<br>0 1 2 3 4 5 6 7 8 9 n-1 n HCNT[10:0]<br>Valid graphics area when<br>GR_GRC_HS[10:0] = 2,<br>GR_GRC_HW[10:0] = 6,<br>GR_GRC_VS[10:0] = 1, and<br>GR_GRC_VW[10:0] = 4<br>0<br>1<br>2<br>3<br>4<br>5<br>m-1<br>m<br>Vsync signal VCNT[10:0]<br>**----- End of picture text -----**<br>

**Figure 33.7 Graphics Display Area**

The frame line of the graphics area can be displayed by setting the GR_GRC_DISP_ON bit to 1.

**Table 33.14 Graphics Image Area Setting**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_AB3|GR_GRC_HS[10:0]|0|Sets the horizontal start position of the graphics image area.|
||||Note: Set to 16 or greater clocks and the result of GR_GRC_HS +|
||||GR_GRC_HW should be smaller than or equal to 2015 clocks.|
|GR_AB3|GR_GRC_HW[10:0]|0|Sets the horizontal width of the graphics image area.|
||||Note: For displaying an image with 1- or 2-pixel horizontal width, set|
||||GR_HW to 2 and GR_GRC_HW to 1 (1-pixel) or 2 (2-pixel).|
|GR_AB2|GR_GRC_VS[10:0]|0|Sets the vertical start position of the graphics image area.|
||||Note: Set to 4 or greater lines and the result of GR_GRC_VS +|
||||GR_GRC_VW should be smaller than or equal to 2039 lines.|
|GR_AB2|GR_GRC_VW[10:0]|0|Sets the vertical width of the graphics image area.|
|GR_AB1|GR_GRC_DISP_ON|0|Turns on/off frame-line display of the graphics image area.|
||||0: Frame-line display off|
||||1: Frame-line display on|

## 33.1.4 Interrupt Generation at Specified Line

An interrupt signal can be generated at the line specified with the GR_LINE[10:0] bits.

## **Table 33.15 Interrupt Generation at Specified Line**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_CLUT_INT|GR_LINE[10:0]|0|Line Interrupt Set *|
||||When the number of lines matches the value of the GR_LINE bits, an|
||||interrupt signal is output. This function is supported for the graphics 3|
||||process only. This function supported for the graphics 3 process is|
||||enabled even when the graphics 3 process is not used.|

Note: * This function is supported for the graphics 3 process only; these bits are not supported for the graphics 0 and 2 processes.

## 33.1.5 Formats of Frame Buffer Read Signals and Corresponding Alpha Blending Types

Setting the GR_FORMAT[3:0] bits selects the format of the signal read from the frame buffer.

Table 33.16 shows the signal formats and the corresponding alpha blending types. The priority of the alpha value is: alpha blending in rectangular area > chroma-key processing > alpha blending in pixel units.

**Table 33.16 Formats of Frame Buffer Read Signal and Corresponding Alpha Blending Types**

||||**RGB-Index**|**CLUT-Index**||
|---|---|---|---|---|---|
|||**Alpha Blending in**|**Chroma-Key**|**Chroma-Key**|**Alpha Blending in**|
|**GR_FORMAT[3:0]**|**Signal Format**|**Rectangular Area**|**Processing**|**Processing**|**Pixel Units**|
|0|RGB565|Supported|Supported *1|Not supported|Not supported *2|
|1|RGB888|Supported|Supported|Not supported|Not supported *2|
|2|αRGB1555|Supported|Supported *1*3|Not supported|Supported *3|
|3|αRGB4444|Supported|Supported *1|Not supported|Supported|
|4|αRGB8888|Supported|Supported|Not supported|Supported|
|5|CLUT8|Supported|Not supported|Supported|Supported|
|6|CLUT4|Supported|Not supported|Supported|Supported|
|7|CLUT1|Supported *4|Not supported|Supported *4|Supported *4|
|8|YCbCr422|Not supported *5|Not supported *5|Not supported *5|Not supported *5|
|9|YCbCr444|Not supported *5|Not supported *5|Not supported *5|Not supported *5|
|10|RGBα5551|Supported|Supported *1*3|Not supported|Supported *3|
|11|RGBα8888|Supported|Supported|Not supported|Supported|

- Notes: 1. When each color component of the RGB signal read from the frame buffer is not 8 bits, it is converted to 8 bits by calculation in RGB-index chroma-key processing. (See section 33.1.2 (13) Bit Extension.)

   2. Since α value is 255, the current graphics is always displayed.

   3. α value for data read from the frame buffer is specified with one bit. This one-bit signal selects one of the two registers, each of which holds an 8-bit α value.

   4. CLUT value for the frame buffer signal is specified with one bit. This one-bit signal selects one of the two registers, each of which holds the α , G, B, and R values (8 bits for each value). The CLUT table is not referenced.

   5. YCbCr422 and YCbCr444 are supported for the graphics 0 process, but any type of blending and chroma-key processing cannot be used.

## 33.1.6 Display Selection

The GR_DISP_SEL[1:0] bits select the graphics to be displayed from the background color, the lower-layer graphics, the current graphics, and the blended image of the lower-layer graphics and the current graphics. For blending, alpha blending in a rectangular area, multiplication with current alpha at alpha blending in a rectangular area, RGB-index chroma-key processing, CLUT-index chroma-key processing, alpha blending in one-pixel units, or premultiplication at alpha blending in one-pixel units can be selected.

This function is not supported for the VIN synthesizer.

Table 33.17 shows the settings for various display types.

**Table 33.17 Settings for Various Display Types**

|**GR_**|||||||
|---|---|---|---|---|---|---|
|**DISP_**|**GR_**|**GR_**|**GR_**|**GR_**|||
|**SEL**|**ARC_**|**CK_**|**ARC_**|**ACALC_**|**Processing for Graphics**|**Processing for the Area**|
|**[1:0]**|**ON**|**ON**|**MUL**|**MD**|**Area**|**outside the Graphics Area**|
|0|—|—|—|—|Background color|Background color|
|1|—|—|—|—|Lower-layer graphics|Lower-layer graphics|
|2|—|—|—|—|Current graphics|Background color|
|3|1|—|0|0|Alpha blending in a rectangular|Lower-layer graphics|
||||||area*1||
|3|1|—|0|1|Setting prohibited||
|3|1|—|1|0|Multiplication with current|Lower-layer graphics|
||||||alpha at alpha blending in a||
||||||rectangular area*2||
|3|1|—|1|1|Multiplication with current|Lower-layer graphics|
||||||alpha at alpha blending in a||
||||||rectangular area with alpha||
||||||premultiplied*2||
|3|0|1|—|—|RGB-index or CLUT-index|Lower-layer graphics|
||||||chroma-key processing||
|3|0|0|—|0|Alpha blending in one-pixel|Lower-layer graphics|
||||||units*2||
|3|0|0|—|1|Premultiplication at alpha|Lower-layer graphics|
||||||blending in one-pixel units*2||

Notes: 1. The alpha blending in a rectangular area is not supported for the graphics 0 process in the scaler. 2. The multiplication with current alpha at alpha blending in a rectangular area and alpha blending function in one-pixel units are supported for the graphics 2 and 3 processes only.

**==> picture [443 x 162] intentionally omitted <==**

**----- Start of picture text -----**<br>
Hsync Rectangular area setting by the scaler<br>signal<br>[GR_DISP_SEL = 0] Displays the background color set by<br>GR_BASE_G, GR_BASE_B, GR_BASE_R<br>GR_ARC_VS GR_GRC_VS [GR_DISP_SEL = 1] Displays the lower-layer graphics.<br>Display area [GR_DISP_SEL = 2] Displays the current graphics.<br>[GR_DISP_SEL = 3] Displays the alpha-blended image of the<br>Graphics area lower-layer graphics and current graphics.<br>Alpha blending image of the rectangular area<br>[GR_DISP_SEL = 0] Displays the background color set by<br>GR_BASE_G, GR_BASE_B, GR_BASE_R<br>GR_ARC_HS [GR_DISP_SEL = 1] Displays the lower-layer graphics<br>GR_ARC_HW [GR_DISP_SEL = 2] Displays the background color set by<br>GR_GRC_HS GR_BASE_G, GR_BASE_B, GR_BASE_R<br>GR_GRC_HW [GR_DISP_SEL = 3] Displays the lower-layer graphics<br>[GR_DISP_SEL = 3,GR_ARC_ON = 1]<br>Rectangular area setting by the scaler Displays the alpha-blended image of the rectangular area<br>signal Vsync<br>GR_ARC_VW GR_GRC_VW<br>**----- End of picture text -----**<br>

**Figure 33.8 Graphic Display Types**

Figure 33.9 shows the graphics planes displayed when the GR_DISP_SEL bits are set to 3.

For correspondence between the lower-layer graphics and the current graphics, see Figure 33.1 .

**==> picture [203 x 116] intentionally omitted <==**

**----- Start of picture text -----**<br>
Current graphics<br>Lower-layer graphics<br>When GR_ACALC_MD is set to 0, current graphics and<br>lower-layer graphics are blended and<br>displayed using the following formula (α = 0 to 255):<br>(Current graphics × α + lower-layer graphics × (255 - α))/255<br>**----- End of picture text -----**<br>

## **Figure 33.9 Graphics Planes with GR_DISP_SEL Set to 3**

**Table 33.18 Alpha Blending Setting**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_AB1|GR_DISP_SEL|0|Selects the graphics display mode.|
||[1:0]||0:Background color display|
||||1:Lower-layer graphics display|
||||2:Current graphics display|
||||3:Blended display of lower-layer graphics and current graphics*1|
|GR_AB1|GR_ARC_ON|0|Turns on/off alpha blending in a rectangular area.*2|
||||0: Off|
||||1: On|
|GR_AB1|GR_ARC_MUL|0|Turns on/off multiplication processing with current alpha at alpha blending in a|
||||rectangular area *3|
||||0: Off|
||||1: On|
|GR_AB1|GR_ACALC_MD|0|Turns on/off premultiplication processing at alpha blending in one-pixel units *3|
||||0: Off|
||||1: On|
|GR_AB7|GR_CK_ON|0|Turns on/off CLUT-index/RGB-index chroma-key processing.|
||||0: Off|
||||1: On|

- Notes: 1. The graphics 0 process supports the chroma-key processing only. When performing chroma-key processing, set the α value for converting the pixels to be subjected to chroma-key processing, and the α value of the pixels not to be subjected to the chroma-key processing to 255 to display the current graphics only.

   2. This function is supported only for the graphics 2 and 3 processes. This bit is not provided for the graphics 0 process.

   3. This function is supported only for the graphics 2 and 3 processes. This bit is not provided for the graphics 0 process.

## 33.1.7 Background Color Display Processing

The color set with the GR_BASE_G[7:0], GR_BASE_B[7:0], and GR_BASE_R[7:0] bits is displayed.

G output = GR_BASE_G

B output = GR_BASE_B

R output = GR_BASE_R

## **Table 33.19 Background Color Setting**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_BASE|GR_BASE_G[7:0]|0|Background color G signal|
||||G: 8 bits; unsigned (0 to 255 [LSB])|
|GR_BASE|GR_BASE_B[7:0]|0|Background color B signal|
||||B: 8 bits; unsigned (0 to 255 [LSB])|
|GR_BASE|GR_BASE_R[7:0]|0|Background color R signal|
||||R: 8 bits; unsigned (0 to 255 [LSB])|

## 33.1.8 Lower-Layer Graphics Display Processing

The lower-layer graphics are displayed as follows:

G output = G input of lower-layer graphics

B output = B input of lower-layer graphics

R output = R input of lower-layer graphics

## 33.1.9 Current Graphics Display Processing

The current graphics are displayed as follows:

G output = G input of current graphics

B output = B input of current graphics

R output = R input of current graphics

## 33.1.10 Display with Alpha Blending in a Rectangular Area

The rectangular area subjected to alpha blending is set with the GR_ARC_HS[10:0], GR_ARC_HW[10:0], GR_ARC_VS[10:0], and GR_ARC_VW[10:0] bits based on the rising edges of the Hsync and Vsync signals. This function is not supported for the graphics 0 process.

Figure 33.10 shows the rectangular area setting for alpha blending.

**==> picture [398 x 333] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clock<br>Hsync signal<br>0 1 2 3 4 5 6 7 8 9 n-1 n HCNT[10:0]<br>Valid image area for alpha<br>blending in a rectangular area<br>when<br>GR_ARC_HS[10:0] = 2,<br>GR_ARC_HW[10:0] = 6,<br>GR_ARC_VS[10:0] = 1, and<br>GR_ARC_VW[10:0] = 4<br>0<br>1<br>2<br>3<br>4<br>5<br>m-1<br>m<br>Vsync signal VCNT[10:0]<br>**----- End of picture text -----**<br>

**Figure 33.10 Rectangular Area Setting for Alpha Blending**

The frame line of graphics area can be displayed by setting the GR_ARC_DISP_ON bit to 1.

**Table 33.20 Setting of Rectangular Area for Alpha Blending**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_AB5|GR_ARC_HS[10:0]|0|Sets the horizontal start position of the valid image area for|
||||alpha blending in a rectangular area.|
|GR_AB5|GR_ARC_HW[10:0]|0|Sets the horizontal width of the valid image area for alpha|
||||blending in a rectangular area.|
|GR_AB4|GR_ARC_VS[10:0]|0|Sets the vertical start position of the valid image area for|
||||alpha blending in a rectangular area.|
|GR_AB4|GR_ARC_VW[10:0]|0|Sets the vertical width of the valid image area for alpha|
||||blending in a rectangular area.|
|GR_AB1|GR_ARC_DISP_ON|0|Turns on/off frame-line display of the valid image area for|
||||alpha blending in a rectangular area.|
||||0: Frame-line display off|
||||1: Frame-line display on|

In alpha blending in a rectangular area, the current graphics are faded in or out by setting the fade-in or fade-out coefficients with the GR_ARC_DEF[7:0], GR_ARC_MODE, GR_ARC_COEF[7:0], and GR_ARC_RATE[7:0] bits.

## First, the value of the GR_ARC_DEF[7:0] bits is assigned to the α value.

Then, each time the Vsync signal rises for the number of times set with the GR_ARC_RATE[7:0] bits + 1, the value of the GR_ARC_COEF[7:0] bit is added to or subtracted from the α value.

**==> picture [464 x 159] intentionally omitted <==**

**----- Start of picture text -----**<br>
Displays lower-layer Displays current Displays lower-layer<br>graphics Fade-in graphics Fade-out graphics<br>255<br>GR_ARC_COEF<br>GR_ARC_RATE + 1<br>0<br>GR_ARC_MODE = 0 GR_ARC_MODE = 1<br>GR_ARC_ST = 0 GR_ARC_ST = 1 GR_ARC_ST = 0 GR_ARC_ST = 1 GR_ARC_ST = 0 [Time]<br>[Alpha value]<br>**----- End of picture text -----**<br>

**Figure 33.11 Fade In and Fade Out**

**Table 33.21 Setting for Alpha Blending in a Rectangular Area**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_AB7|GR_ARC_DEF[7:0]|0|Sets the initial alpha value for alpha blending in a rectangular area.|
|GR_AB6|GR_ARC_MODE|0|Alpha Blending Mode in Rectangular Area|
||||0: Addition|
||||1: Subtraction|
|GR_AB6|GR_ARC_COEF[7:0]|0|Sets the alpha coefficient for alpha blending in a rectangular area. (0 to 255)|
||||[7:0]: Variation (absolute value)|
|GR_AB6|GR_ARC_RATE[7:0]|0|Sets the value obtained by subtracting 1 from the frame rate for alpha|
||||blending in a rectangular area.|
|GR_MON|GR_ARC_ST|—|Status Flag for Alpha Blending in Rectangular Area|
||||0: Addition or subtraction has been completed. (αvalue is 0 or 255)|
||||1: Addition or subtraction is in progress.|

The values specified with the following expressions are used in the alpha blending calculation described in section 33.1.14, Alpha Blending Calculation .

α value = Fade-in/out coefficient

G value = G input of the current graphics

B value = B input of the current graphics

R value = R input of the current graphics

## 33.1.11 RGB-Index Chroma-Key Processing

The pixels that satisfy all the expressions below are subjected to RGB-index chroma-key processing.

G input of the current graphics = GR_CK_KG

B input of the current graphics = GR_CK_KB

R input of the current graphics = GR_CK_KR

In RGB-index chroma-key processing, the values specified with the following expressions are used in the alpha blending calculation described in section 33.1.14, Alpha Blending Calculation . This function is not supported in the VIN synthesizer.

α value = GR_CK_A

G value = GR_CK_G

B value = GR_CK_B

R value = GR_CK_R

For the pixels that are not subjected to RGB-index chroma-key processing, the values specified with the following expressions are used in the alpha blending calculation described in section 33.1.14, Alpha Blending Calculation .

α value = α input of the current graphics

G value = G input of the current graphics

B value = B input of the current graphics

R value = R input of the current graphics

**Table 33.22 Setting for RGB-Index Chroma-Key Processing**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_AB8|GR_CK_KG[7:0]|0|G Signal for RGB-Index Chroma-Key Processing|
||||G: 8 bits; unsigned (0 to 255 [LSB])|
|GR_AB8|GR_CK_KB[7:0]|0|B Signal for RGB-Index Chroma-Key Processing|
||||B: 8 bits; unsigned (0 to 255 [LSB])|
|GR_AB8|GR_CK_KR[7:0]|0|R Signal for RGB-Index Chroma-Key Processing|
||||R: 8 bits; unsigned (0 to 255 [LSB])|
|GR_AB9|GR_CK_A[7:0]|0|Replaced Alpha Signal after RGB-Index Chroma-Key|
||||Processing*|
||||α: 8 bits; unsigned (0 to 255 [LSB])|
|GR_AB9|GR_CK_G[7:0]|0|Replaced G Signal after RGB-Index Chroma-Key Processing|
||||G: 8 bits; unsigned (0 to 255 [LSB])|
|GR_AB9|GR_CK_B[7:0]|0|Replaced B Signal after RGB-Index Chroma-Key Processing|
||||B: 8 bits; unsigned (0 to 255 [LSB])|
|GR_AB9|GR_CK_R[7:0]|0|Replaced R Signal after RGB-Index Chroma-Key Processing|
||||R: 8 bits; unsigned (0 to 255 [LSB])|

Note:   * To use this function for the graphics 0 process, the alpha value should be set to 255.

## 33.1.12 CLUT-Index Chroma-Key Processing

The pixels that satisfy the expression below are subjected to CLUT-index chroma-key processing.

CLUT input of the current graphics = GR_CK_KCLUT

In CLUT-index chroma-key processing, the values specified with the following expressions are used in the alpha blending calculation described in section 33.1.14, Alpha Blending Calculation . This function is not supported in the VIN synthesizer.

α value = GR_CK_A G value = GR_CK_G B value = GR_CK_B R value = GR_CK_R

For the pixels that are not subjected to CLUT-index chroma-key processing, the values specified with the following expressions are used in the alpha blending calculation described in section 33.1.14, Alpha Blending Calculation .

α value = α input of the current graphics

G value = G input of the current graphics

B value = B input of the current graphics

R value = R input of the current graphics

**Table 33.23 Setting for CLUT-Index Chroma-Key Processing**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_AB8|GR_CK_|0|CLUT Signal for CLUT-Index Chroma-Key Processing|
||KCLUT[7:0]||CLUT: 8 bits; unsigned (0 to 255 [LSB])|
|GR_AB10|GR_A0[7:0]|0|CLUT1α0 Signal*|
||||Replaced withαsignal when in the CLUT1 format and CLUT1= 0.|
||||Replaced withαsignal when in theαRGB1555 format andα= 0.|
|GR_AB10|GR_G0[7:0]|0|CLUT1 G0 Signal|
||||Replaced with G signal when in the CLUT1 format and CLUT1 = 0.|
|GR_AB10|GR_B0[7:0]|0|CLUT1 B0 Signal|
||||Replaced with B signal when in the CLUT1 format and CLUT1 = 0.|
|GR_AB10|GR_R0[7:0]|0|CLUT1 R0 Signal|
||||Replaced with R signal when in the CLUT1 format and CLUT1 = 0.|
|GR_AB11|GR_A1[7:0]|0|CLUT1α1 Signal*|
||||Replaced withαsignal when in the CLUT1 format and CLUT1 = 1.|
||||Replaced withαsignal when in theαRGB1555 format andα= 1.|
|GR_AB11|GR_G1[7:0]|0|CLUT1 G1 Signal|
||||Replaced with G signal when in the CLUT1 format and CLUT1 = 1.|
|GR_AB11|GR_B1[7:0]|0|CLUT1 B1 Signal|
||||Replaced with B signal when in the CLUT1 format and CLUT1 = 1.|
|GR_AB11|GR_R1[7:0]|0|CLUT1 R1 Signal|
||||Replaced with R signal when in the CLUT1 format and CLUT1 = 1.|

Note: * To use this function for the graphics 0 process, the alpha value should be set to 255.

## 33.1.13 Display with Alpha Blending in One-Pixel Units

In the alpha blending in one-pixel units, the values specified with the following expressions are used in the alpha blending calculation described in section 33.1.14, Alpha Blending Calculation . This function is not supported in the graphics 0 process and the VIN synthesizer.

α value = α input of the current graphics

G value = G input of the current graphics

B value = B input of the current graphics

R value = R input of the current graphics

## 33.1.14 Alpha Blending Calculation

Alpha blending of two input signals is performed using the α value as described below (rounded up if the result includes a decimal fraction).

## [GR_ACALC_MD = 0]

G output = (G value × α value + G input of the lower-layer graphics × (255 − α value)) ÷ 256

B output = (B value × α value + B input of the lower-layer graphics × (255 − α value)) ÷ 256

R output = (R value × α value + R input of the lower-layer graphics × (255 − α value)) ÷ 256

## [GR_ACALC_MD = 1 (premultiplication)]

G output = (G value + G input of the lower-layer graphics × (255 − α value)) ÷ 256

B output = (B value + B input of the lower-layer graphics × (255 − α value)) ÷ 256

R output = (R value + R input of the lower-layer graphics × (255 − α value)) ÷ 256

## 33.1.15 CLUT Table

When the signal format is CLUT8 or CLUT4, the format is converted to αRGB8888 based on the CLUT table. When the format is CLUT1, it is converted to αRGB8888 based on the register value.

Figure 33.12 shows data arrangement in the CLUT table.

**==> picture [287 x 33] intentionally omitted <==**

**----- Start of picture text -----**<br>
31 24 23 16 15 8 7 0<br>α value R value G value B value<br>**----- End of picture text -----**<br>

**Figure 33.12 Data Arrangement in CLUT Table**

The CLUT tables are arranged in the following addresses:

Graphics 0 CLUT table: H'FCFF6000 to H'FCFF63FF (For CLUT4, addresses H'FCFF6000 to H'FCFF603F are valid.)

Graphics 2 CLUT table: H'FCFF6800 to H'FCFF6BFF

(For CLUT4, addresses H'FCFF6800 to H'FCFF683F are valid.)

Graphics 3 CLUT table: H'FCFF6C00 to H'FCFF6FFF

(For CLUT4, addresses H'FCFF6C00 to H'FCFF6C3F are valid.)

Two CLUT tables (CLUT table 0, CLUT table 1) on the different planes are allocated to the same address and one of the tables is selected with the GR_CLT_SEL bit. This allows rewriting one CLUT table when this module refers to the other CLUT table.

When switching the CLUT after overwriting the CLUT, please execute a dummy read of the CLUT table address.And switch the CLUT table by GR_CLT_SEL after dummy-read.switch the CLUT table by GR_CLT_SEL after dummyread.

## **Table 33.24 CLUT Table Selection**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_CLUT|GR_CLT_SEL|0|CLUT Table Select Signal|
||||0: Selects CLUT table 0.|
||||The format is converted toαRGB8888 based on the CLUT table 0. CLUT table|
||||1 can be read from or written to by the CPU.|
||||1: Selects CLUT table 1.|
||||The format is converted toαRGB8888 based on the CLUT table 1. CLUT table|
||||0 can be read from or written to by the CPU.|

## 33.1.16 Multiplication Processing with Current Alpha at Alpha Blending in Rectangular Area

In multiplication processing with current alpha at alpha blending in a rectangular area, the values specified with the following expressions are used in the alpha blending calculation described in section 33.1.14, Alpha Blending Calculation .

## [GR_ARC_MUL = 0]

α value = Fade-in/out coefficient

G value = G input of the current graphics

B value = B input of the current graphics

R value = R input of the current graphics

## [GR_ARC_MUL = 1 (multiplication)]

α value = Fade-in/out coefficient x α input of current graphics

G value = G input of the current graphics

B value = B input of the current graphics

R value = R input of the current graphics

## 33.1.17 Selection of Lower-Layer Graphics in VIN Synthesizer

Graphics 0 is allocated to the lower-layer graphics in the VIN synthesizer.

**Table 33.25 Selection of Lower-Layer Plane in Scaler**

|**Register Name**|**Bit Name**|**Initial Value**|**Description**|
|---|---|---|---|
|GR_VIN_AB1|GR_VIN_SCL_|0|Specifies lower-layer plane in the scaler.|
||UND_SEL||0: Selects graphics 0 as lower-layer graphics.|
||||1: Setting prohibited|

## 33.2 Register Descriptions

Table 33.26 to Table 33.29 show the register configuration.

- Symbols used in Register Description:

Initial value: Register value after a reset

—: Undefined value R/W: Readable/writable. The written value can be read. R/WC0: Readable/writable. Writing 0 initializes the bit. Writing 1 is ignored. R/WC1: Readable/writable. Writing 1 initializes the bit. Writing 0 is ignored. R: Read-only. The write value should always be 0. —/W: Write-only. The read value is undefined.

Table 33.26 shows the register configuration for the graphics 2 process.

Table 33.27 shows the register configuration for the graphics 3 process.

Table 33.28 shows the CLUT table configuration.

Table 33.29 shows the register configuration for the VIN synthesizer.

The register configuration for the graphics 0 process is described in section 31, Video Display Controller 5 (3): Scaler .

**Table 33.26 Register Configuration of the Image Synthesizer (Graphics 2 Process)**

|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Graphics 2 register update|GR2_UPDATE|R/WC1|H'0000 0000|H'FCFF 7700|32|
|control register||||||
|Frame buffer read control register|GR2_FLM_RD|R/W|H'0000 0000|H'FCFF 7704|32|
|(Graphics 2)||||||
|Frame buffer control register 1|GR2_FLM1|R/W|H'0000 0000|H'FCFF 7708|32|
|(Graphics 2)||||||
|Frame buffer control register 2|GR2_FLM2|R/W|H'0000 0000|H'FCFF 770C|32|
|(Graphics 2)||||||
|Frame buffer control register 3|GR2_FLM3|R/W|H'0000 0000|H'FCFF 7710|32|
|(Graphics 2)||||||
|Frame buffer control register 4|GR2_FLM4|R/W|H'0000 0000|H'FCFF 7714|32|
|(Graphics 2)||||||
|Frame buffer control register 5|GR2_FLM5|R/W|H'0000 03FF|H'FCFF 7718|32|
|(Graphics 2)||||||
|Frame buffer control register 6|GR2_FLM6|R/W|H'0000 0000|H'FCFF 771C|32|
|(Graphics 2)||||||
|Alpha blending control register 1|GR2_AB1|R/W|H'0000 0000|H'FCFF 7720|32|
|(Graphics 2)||||||
|Alpha blending control register 2|GR2_AB2|R/W|H'0000 0000|H'FCFF 7724|32|
|(Graphics 2)||||||
|Alpha blending control register 3|GR2_AB3|R/W|H'0000 0000|H'FCFF 7728|32|
|(Graphics 2)||||||
|Alpha blending control register 4|GR2_AB4|R/W|H'0000 0000|H'FCFF 772C|32|
|(Graphics 2)||||||
|Alpha blending control register 5|GR2_AB5|R/W|H'0000 0000|H'FCFF 7730|32|
|(Graphics 2)||||||
|Alpha blending control register 6|GR2_AB6|R/W|H'0000 0000|H'FCFF 7734|32|
|(Graphics 2)||||||
|Alpha blending control register 7|GR2_AB7|R/W|H'00FF 0000|H'FCFF 7738|32|
|(Graphics 2)||||||
|Alpha blending control register 8|GR2_AB8|R/W|H'0000 0000|H'FCFF 773C|32|
|(Graphics 2)||||||
|Alpha blending control register 9|GR2_AB9|R/W|H'0000 0000|H'FCFF 7740|32|
|(Graphics 2)||||||
|Alpha blending control register 10|GR2_AB10|R/W|H'0000 0000|H'FCFF 7744|32|
|(Graphics 2)||||||
|Alpha blending control register 11|GR2_AB11|R/W|H'0000 0000|H'FCFF 7748|32|
|(Graphics 2)||||||
|Background color control register|GR2_BASE|R/W|H'0000 0000|H'FCFF 774C|32|
|(Graphics 2)||||||
|CLUT table control register|GR2_CLUT|R/W|H'0000 0000|H'FCFF 7750|32|
|(Graphics 2)||||||
|Status monitor register|GR2_MON|R|H'0000 0000|H'FCFF 7754|32|
|(Graphics 2)||||||

**Table 33.27 Register Configuration of the Image Synthesizer (Graphics 3 Process)**

|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|Graphics 3 register update|GR3_UPDATE|R/WC1|H'0000 0000|H'FCFF 7780|32|
|control register||||||
|Frame buffer read control register|GR3_FLM_RD|R/W|H'0000 0000|H'FCFF 7784|32|
|(Graphics 3)||||||
|Frame buffer control register 1|GR3_FLM1|R/W|H'0000 0000|H'FCFF 7788|32|
|(Graphics 3)||||||
|Frame buffer control register 2|GR3_FLM2|R/W|H'0000 0000|H'FCFF 778C|32|
|(Graphics 3)||||||
|Frame buffer control register 3|GR3_FLM3|R/W|H'0000 0000|H'FCFF 7790|32|
|(Graphics 3)||||||
|Frame buffer control register 4|GR3_FLM4|R/W|H'0000 0000|H'FCFF 7794|32|
|(Graphics 3)||||||
|Frame buffer control register 5|GR3_FLM5|R/W|H'0000 03FF|H'FCFF 7798|32|
|(Graphics 3)||||||
|Frame buffer control register 6|GR3_FLM6|R/W|H'0000 0000|H'FCFF 779C|32|
|(Graphics 3)||||||
|Alpha blending control register 1|GR3_AB1|R/W|H'0000 0000|H'FCFF 77A0|32|
|(Graphics 3)||||||
|Alpha blending control register 2|GR3_AB2|R/W|H'0000 0000|H'FCFF 77A4|32|
|(Graphics 3)||||||
|Alpha blending control register 3|GR3_AB3|R/W|H'0000 0000|H'FCFF 77A8|32|
|(Graphics 3)||||||
|Alpha blending control register 4|GR3_AB4|R/W|H'0000 0000|H'FCFF 77AC|32|
|(Graphics 3)||||||
|Alpha blending control register 5|GR3_AB5|R/W|H'0000 0000|H'FCFF 77B0|32|
|(Graphics 3)||||||
|Alpha blending control register 6|GR3_AB6|R/W|H'0000 0000|H'FCFF 77B4|32|
|(Graphics 3)||||||
|Alpha blending control register 7|GR3_AB7|R/W|H'00FF 0000|H'FCFF 77B8|32|
|(Graphics 3)||||||
|Alpha blending control register 8|GR3_AB8|R/W|H'0000 0000|H'FCFF 77BC|32|
|(Graphics 3)||||||
|Alpha blending control register 9|GR3_AB9|R/W|H'0000 0000|H'FCFF 77C0|32|
|(Graphics 3)||||||
|Alpha blending control register 10|GR3_AB10|R/W|H'0000 0000|H'FCFF 77C4|32|
|(Graphics 3)||||||
|Alpha blending control register 11|GR3_AB11|R/W|H'0000 0000|H'FCFF 77C8|32|
|(Graphics 3)||||||
|Background color control register|GR3_BASE|R/W|H'0000 0000|H'FCFF 77CC|32|
|(Graphics 3)||||||
|CLUT table and interrupt control|GR3_CLUT_INT|R/W|H'0000 0000|H'FCFF 77D0|32|
|register (Graphics 3)||||||
|Status monitor register|GR3_MON|R|H'0000 0000|H'FCFF 77D4|32|
|(Graphics 3)||||||

## **Table 33.28 CLUT Table Configuration**

|**Name**|||**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Access Size**|
|---|---|---|---|---|---|---|---|
|Graphics|0|CLUT table|GR0_CLUTT|R/W|—|H'FCFF 6000 to H'FCFF 63FF|32|
|Graphics|2|CLUT table|GR2_CLUTT|R/W|—|H'FCFF 6800 to H'FCFF 6BFF|32|
|Graphics|3|CLUT table|GR3_CLUTT|R/W|—|H'FCFF 6C00 to H'FCFF 6FFF|32|

## **Table 33.29 Register Configuration of the VIN Synthesizer**

|**Name**|**Abbreviation**|**R/W**|**Initial Value**|**Address**|**Access Size**|
|---|---|---|---|---|---|
|VIN synthesizer register update control|GR_VIN_UPDATE|R/WC1|H'0000 0000|H'FCFF 7E00|32|
|register||||||
|Alpha blending control register 1|GR_VIN _AB1|R/W|H'0000 0000|H'FCFF 7E20|32|
|(VIN synthesizer)||||||

## 33.2.1 Graphics 2 Register Update Control Register (GR2_UPDATE)

||Bit:|31|30||29||28|27||26|25|24|23<br>22<br>21|20||19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—||—||—|—||—|—|—|—<br>—<br>—|—||—|—|—||—||
||Initial value:|0|0||0||0|0||0|0|0|0<br>0<br>0|0||0|0|0||0||
||R/W:|R|R||R||R|R||R|R|R|R<br>R<br>R|R||R|R|R||R||
||Bit:|15|14||13||12|11||10|9|8|7<br>6<br>5|4||3|2|1||0||
|||—|—||—||—|—||—|—|GR2_<br>UPDATE|—<br>—<br>—|GR2_<br>P_VEN||—|—|—||GR2_<br>IBUS_<br>VEN||
||Initial value:|0|0||0||0|0||0|0|0|0<br>0<br>0|0||0|0|0||0||
||R/W:|R|R||R||R|R||R|R|R/WC1<br>R<br>R<br>R||R/WC1||R|R|R|R/WC1|||
|**Bit**||**Bit Name**||||**Initial Value**|||**R/W**||**Description**|||||||||||
|31 to 9||—||||All 0|||R||Reserved|||||||||||
||||||||||||These bits||are always read as 0. The write value should always be 0.|||||||||
|8||GR2_||||0|||R/WC1||Frame Buffer Read Control Register Update|||||||||||
|||UPDATE|||||||||0: Registers are not updated.|||||||||||
||||||||||||1: Registers are updated.|||||||||||
|7|to 5|—||||All 0|||R||Reserved|||||||||||
||||||||||||These bits||are always read as 0. The write value should always be 0.|||||||||
|4||GR2_P_||||0|||R/WC1||Graphics Display Register Update|||||||||||
|||VEN|||||||||0: Registers are not updated.|||||||||||
||||||||||||1: Registers are updated at the rising edge of the Vsync.|||||||||||
|3|to 1|—||||All 0|||R||Reserved|||||||||||
||||||||||||These bits||are always read as 0. The write value should always be 0.|||||||||
|0||GR2_IBUS_VE||||0|||R/WC1||Frame Buffer Read Register Update|||||||||||
|||N|||||||||0: Registers are not updated.|||||||||||
||||||||||||1: Registers are updated at the rising edge of the Vsync.|||||||||||

## 33.2.2 Frame Buffer Read Control Register (Graphics 2) (GR2_FLM_RD)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||||||GR2_||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|R_ENB||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||GR2_R_ENB|0|R/W|Frame Buffer Read Enable|
|||||||0: Frame buffer reading is disabled.|
|||||||1: Frame buffer reading is enabled.|

Note: This register is updated when GR2_IBUS_VEN in GR2_UPDATE is 1.

## 33.2.3 Frame Buffer Control Register 1 (Graphics 2) (GR2_FLM1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||GR2_||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|LN_OFF_||
|||||||||||||||||DIR||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|—|GR2_FLM_SEL[1:0]||—|—|—|—|—|—|—|GR2_<br>BST_MD||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R/W|R/W|R|R|R|R|R|R|R|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 17|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|16|GR2_LN_|0|R/W|Selects the line offset address direction of the frame buffer.|
||OFF_DIR|||0: Increments the address by the line offset address.|
|||||1: Decrements the address by the line offset address.|
|15 to 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9, 8|GR2_FLM_SEL|0|R/W|Selects a frame buffer address setting signal.|
||[1:0]|||0: Selects frame 0.|
|||||1: Selects register GR2_FLM_NUM.|
|||||2: Selects frame 0.|
|||||3: Setting prohibited|
|7 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|GR2_BST_MD|0|R/W|Frame Buffer Burst Transfer Mode|
|||||0: 32-byte transfer|
|||||1: 128- byte transfer|

Note: GR2_LN_OFF_DIR and GR2_FLM_SEL are updated when GR2_IBUS_VEN in GR2_UPDATE is 1. GR2_BST_MD is updated when GR2_IBUS_VEN and GR2_P_VEN in GR2_UPDATE are 1.

## 33.2.4 Frame Buffer Control Register 2 (Graphics 2) (GR2_FLM2)

||Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||GR2_BASE[31:16]|||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||Bit:|15|14|13|12||11|10|9<br>8<br>7<br>6|5|4|3|2|1|0|
||||||||||GR2_BASE[15:0]|||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**|||||||
|31|to 0|GR2_BASE||0|||R/W||Frame Buffer Base Address (upper)|||||||
|||[31:0]|||||||Sets the start address of the frame buffer|||where frame data is to|||be|
||||||||||stored.|||||||
||||||||||GR_BASE[4:3] and GR_BASE[6:3]||are referred to during 32-byte burst|||||
||||||||||transfer and 128-byte burst|transfer, respectively,|||to skip|the start line||
||||||||||data.|||||||
||||||||||The lower 3 bits should be fixed to 000.|||||||

Note: This register is updated when GR2_IBUS_VEN and GR2_P_VEN in GR2_UPDATE are 1.

## 33.2.5 Frame Buffer Control Register 3 (Graphics 2) (GR2_FLM3)

||Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|||||||GR2_LN_OFF[14:0]||||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14|13|12||11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||—|—|—|—||—|—|GR2_FLM_NUM[9:0]||||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R|R|R||R|R|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**||||||||
|31||—||0|||R||Reserved||||||||
||||||||||This bit is always read as|0. The write value should always be|||||0.||
|30|to 16|GR2_LN_||0|||R/W||Frame Buffer Line Offset|Address|||||||
|||OFF[14:0]|||||||Sets the line offset address for calculating the start address of||||||each line.||
||||||||||Line 0: GR2_BASE||||||||
||||||||||Line 1: GR2_BASE + GR2_LN_OFF × 1||||||||
||||||||||:||||||||
||||||||||Line n: GR2_BASE + GR2_LN_OFF × n||||||||
||||||||||For 32 byte transfer, the lower 5 bits should be fixed to|||||0_0000.|||
||||||||||For 128 byte transfer, the|lower 7|bits should be fixed to 000_0000.||||||
|15|to 10|—||All|0||R||Reserved||||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||||
|9 to 0||GR2_FLM_||0|||R/W||Frame Number of Frame|Buffer|||||||
|||NUM[9:0]|||||||Manually set the frame number when GR2_FLM_SEL = 1.||||||||

Note: This register is updated when GR2_IBUS_VEN in GR2_UPDATE is 1.

## 33.2.6 Frame Buffer Control Register 4 (Graphics 2) (GR2_FLM4)

||Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22<br>21<br>20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—|—|—<br>—<br>—<br>GR2_FLM_OFF[22:16]|||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||R/W:|R|R|R|R||R|R|R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W||R/W||
||Bit:|15|14|13|12||11|10|9<br>8<br>7<br>6<br>5<br>4<br>3|2|1|0||
||||||||||GR2_FLM_OFF[15:0]|||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W||R/W||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**|||||
|31|to 23|—||All|0||R||Reserved|||||
||||||||||These bits are always read as 0. The write value should||always be 0.|||
|22|to 0|GR2_FLM_||0|||R/W||Frame Buffer Frame Offset Address (upper)|||||
|||OFF[22:0]|||||||Specifies the frame offset address used for calculating the start|||address||
||||||||||of each frame buffer when more than one buffer is used.|||||
||||||||||Buffer 0: GR2_BASE|||||
||||||||||Buffer 1: GR2_BASE + GR2_FLM_OFF × 1|||||
||||||||||:|||||
||||||||||Buffer n: GR2_BASE + GR2_FLM_OFF × n|||||
||||||||||For 32 byte transfer, the lower 5 bits should be fixed to 0_0000.|||||
||||||||||For 128 byte transfer, the lower 7 bits should be fixed to||000_0000.|||

Note: This register is updated when GR2_IBUS_VEN in GR2_UPDATE is 1.

## 33.2.7 Frame Buffer Control Register 5 (Graphics 2) (GR2_FLM5)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR2_FLM_LNUM[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||GR2_FLM_LOOP[10:0]||||||||
|Initial value:|0|0|0|0|0|0|1|1|1|1|1|1|1|1|1|1||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|GR2_FLM_|0|R/W|Sets number of lines in a frame|
||||LNUM[10:0]|||The number of lines is (GR2_FLM_LNUM + 1).|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|GR2_FLM_|1023|R/W|Number of lines when reading the addresses repeatedly by returning to|
||||LOOP[10:0]|||the start address after reaching the end address.|
|||||||The number of lines is (GR2_FLM_LOOP + 1).|

Note: This register is updated when GR2_IBUS_VEN in GR2_UPDATE is 1.

## 33.2.8 Frame Buffer Control Register 6 (Graphics 2) (GR2_FLM6)

|||Bit:|31|30|29|28|27|26<br>25<br>24<br>23|22||21|20|19|18||17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GR2_FORMAT[3:0]||||—||GR2_HW[10:0]||||||||||
||Initial|value:|0|0|0|0|0|0<br>0<br>0<br>0|0||0|0|0|0||0|0||
|||R/W:|R/W|R/W|R/W|R/W|R|R/W<br>R/W<br>R/W<br>R/W|R/W||R/W|R/W|R/W|R/W|R/W||R/W||
|||Bit:|15|14|13|12|11|10<br>9<br>8<br>7|6||5|4|3|2||1|0||
||||—|—|—|GR2_RDSWA[2:0]<br>—<br>—<br>—|||—|||GR2_STA_POS[5:0]|||||||
||Initial|value:|0|0|0|0|0|0<br>0<br>0<br>0|0||0|0|0|0||0|0||
|||R/W:|R|R|R|R/W|R/W|R/W<br>R<br>R<br>R|R||R/W|R/W|R/W|R/W|R/W||R/W||
|**Bit**||**Bit**|**Name**|**Initial Value**|||**R/W**|**Description**|||||||||||
|31|to 28|GR2_||0|||R/W|Sets the format of the frame buffer read signal.|||||||||||
|||FORMAT||||||0: RGB565|||||||||||
|||[3:0]||||||1: RGB888|||||||||||
|||||||||2:αRGB1555|||||||||||
|||||||||3:αRGB4444|||||||||||
|||||||||4:αRGB8888|||||||||||
|||||||||5: CLUT8|||||||||||
|||||||||6: CLUT4|||||||||||
|||||||||7: CLUT1|||||||||||
|||||||||8: Setting prohibited|||||||||||
|||||||||9: Setting prohibited|||||||||||
|||||||||10: RGBα5551|||||||||||
|||||||||11: RGBα8888|||||||||||
|||||||||12 to 15: Setting prohibited|||||||||||
|27||—||0|||R|Reserved|||||||||||
|||||||||This bit is always read as 0. The write value should always be||||||||0.|||
|26|to 16|GR2_HW||0|||R/W|Sets the width of the horizontal||valid period.|||||||||
|||[10:0]||||||The width is (GR2_HW + 1) pixels.|||||||||||
|||||||||Note: Set to 2 or greater.|||||||||||
|15|to 13|—||All 0|||R|Reserved|||||||||||
|||||||||These bits are always read as 0. The write value should always be|||||||||0.||
|12|to 10|GR2_||0|||R/W|Sets 8-, 16-, and 32-bit swap.|||||||||||
|||RDSWA||||||These three bits specify|the method for swapping the bits of frame buffer read||||||||||
|||[2:0]||||||data as follows.|||||||||||
|||||||||Bit 0|||||||||||
|||||||||0: 8 bits are not swapped.|||||||||||
|||||||||1: 8 bits are swapped.|||||||||||
|||||||||Bit 1|||||||||||
|||||||||0: 16 bits are not swapped.|||||||||||
|||||||||1: 16 bits are swapped.|||||||||||
|||||||||Bit 2|||||||||||
|||||||||0: 32 bits are not swapped.|||||||||||
|||||||||1: 32 bits are swapped.|||||||||||
|||||||||When eight bits are put|together, they are swapped as follows. Each of (1)|||||||||to|
|||||||||(8) indicates eight-bit data.|||||||||||
|||||||||000: (1) (2) (3) (4) (5) (6) (7) (8)|||[No swap]||||||||
|||||||||001: (2) (1) (4) (3) (6) (5) (8) (7)|||[8-bit swap]||||||||
|||||||||010: (3) (4) (1) (2) (7) (8) (5) (6)|||[16-bit|swap]|||||||
|||||||||011: (4) (3) (2) (1) (8) (7) (6) (5)|||[16-bit|swap +|8-bit swap]||||||
|||||||||100: (5) (6) (7) (8) (1) (2) (3) (4)|||[32-bit|swap]|||||||
|||||||||101: (6) (5) (8) (7) (2) (1) (4) (3)|||[32-bit|swap +|8-bit swap]||||||
|||||||||110: (7) (8) (5) (6) (3) (4) (1) (2)|||[32-bit|swap +|16-bit swap]||||||
|||||||||111: (8) (7) (6) (5) (4) (3) (2) (1)|||[32-bit|swap + 16-bit swap + 8-bit swap]|||||||
|9 to 6||—||All 0|||R|Reserved|||||||||||
|||||||||These bits are always read as 0. The write value should always be|||||||||0.||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|5 to 0|GR2_|0|R/W|Sets the amount of data to be skipped through.|
||STA_POS|||Specifically data amount equal to the amount indicated by GR2_STA_POS is|
||[5:0]|||skipped from the start of the line.|

Note: GR2_STA_POS is updated when GR2_P_VEN in GR2_UPDATE is 1. GR2_RDSWA is updated when GR2_UPDATE in GR2_UPDATE is 1.

GR2_FORMAT and GR2_HW are updated when GR2_IBUS_VEN and GR2_P_VEN in GR2_UPDATE are 1.

## 33.2.9 Alpha Blending Control Register 1 (Graphics 2) (GR2_AB1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||GR2_ARC<br>_MUL|GR2_ACA<br>LC_MD|—|GR2_<br>ARC_ON|—|—|—|GR2_<br>ARC_<br>DISP_ON|—|—|—|GR2_<br>GRC_<br>DISP_ON|—|—|GR2_DISP_SEL[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R|R/W|R|R|R|R/W|R|R|R|R/W|R|R|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 16|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|15|GR2_ARC_MUL|0|R/W|Turns on/off multiplication processing with current alpha at alpha|
|||||blending in a rectangular area.|
|||||0: Off|
|||||1: On|
|14|GR2_ACALC_MD|0|R/W|Turns on/off premultiplication processing at alpha blending in one-pixel|
|||||units.|
|||||0: Off|
|||||1: On|
|13|—|0|R|Reserved|
|||||This bit is always read as 0. The write value|
|||||should always be 0.|
|12|GR2_ARC_ON|0|R/W|Turns on/off alpha blending in a rectangular area.|
|||||0: Off|
|||||1: On|
|11 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|GR2_ARC_|0|R/W|Turns on/off frame-line display of the image area for alpha blending in a|
||DISP_ON|||rectangular area.|
|||||0: Frame-line display off|
|||||1: Frame-line display on|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|GR2_GRC_|0|R/W|Turns on/off frame-line display of the graphics image area.|
||DISP_ON|||0: Frame-line display off|
|||||1: Frame-line display on|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|1, 0|GR2_DISP_|0|R/W|Selects the graphics display mode.|
||SEL[1:0]|||0: Background color display|
|||||1: Lower-layer graphics display|
|||||2: Current graphics display|
|||||3: Blended display of lower-layer graphics and current graphics|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.10 Alpha Blending Control Register 2 (Graphics 2) (GR2_AB2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR2_GRC_VS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||GR2_GRC_VW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|GR2_GRC_|0|R/W|Sets the vertical start position of the graphics image area.|
||||VS[10:0]|||Note: Set to 4 or greater lines and the result of GR2_GRC_VS +|
|||||||GR2_GRC_VW should be smaller than or equal to 2039 lines.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|GR2_GRC_|0|R/W|Sets the vertical width of the graphics image area.|
||||VW[10:0]||||

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.11 Alpha Blending Control Register 3 (Graphics 2) (GR2_AB3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR2_GRC_HS[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||GR2_GRC_HW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|GR2_GRC_|0|R/W|Sets the horizontal start position of the graphics image area.|
||||HS[10:0]|||Note: Set to 16 or greater clocks and the result of GR2_GRC_HS +|
|||||||GR2_GRC_HW should be smaller than or equal to 2015 clocks.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|GR2_GRC_|0|R/W|Sets the horizontal width of the graphics image area.|
||||HW[10:0]|||Note: For displaying an image with 1- or 2-pixel horizontal width, set|
|||||||GR2_HW to 2 and GR2_GRC_HW to 1 (1-pixel) or 2 (2-pixel).|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.12 Alpha Blending Control Register 4 (Graphics 2) (GR2_AB4)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR2_ARC_VS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||GR2_ARC_VW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|GR2_ARC_|0|R/W|Sets the vertical start position of the valid image area for alpha blending|
||||VS[10:0]|||in a rectangular area.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|GR2_ARC_|0|R/W|Sets the vertical width of the valid image area for alpha blending in a|
||||VW[10:0]|||rectangular area.|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.13 Alpha Blending Control Register 5 (Graphics 2) (GR2_AB5)

||Bit:|31|30|29|28||27||26|25<br>24|23|22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—|||||GR2_ARC_HS[10:0]|||||||
||Initial value:|0|0|0|0||0||0|0<br>0|0|0<br>0|0|0|0|0|0||
||R/W:|R|R|R|R||R||R/W|R/W<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14|13|12||11||10|9<br>8|7|6<br>5|4|3|2|1|0||
|||—|—|—|—||—|||||GR2_ARC_HW[10:0]|||||||
||Initial value:|0|0|0|0||0||0|0<br>0|0|0<br>0|0|0|0|0|0||
||R/W:|R|R|R|R||R||R/W|R/W<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**|||||||||
|31|to 27|—||All|0|||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value|||||should|always be 0.|||
|26|to 16|GR2_ARC_||0||||R/W||Sets the horizontal start position of the valid image area||||||for alpha|||
|||HS[10:0]||||||||blending in a rectangular area.|||||||||
|15|to 11|—||All|0|||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value|||||should|always be 0.|||
|10|to 0|GR2_ARC_||0||||R/W||Sets the horizontal width of the valid image area|||||for alpha blending in a||||
|||HW[10:0]||||||||rectangular area.|||||||||

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.14 Alpha Blending Control Register 6 (Graphics 2) (GR2_AB6)

|||Bit:|31||30|||29|28|27|26<br>25<br>24||23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—||—|||—|—|—|—<br>—<br>GR2_ARC<br>_MODE||||GR2_ARC_COEF[7:0]|||||||
||Initial|value:|0||0|||0|0|0|0<br>0<br>0||0|0|0|0|0|0|0|0||
|||R/W:|R||R|||R|R|R|R<br>R<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|||Bit:|15||14|||13|12|11|10<br>9<br>8||7|6|5|4|3|2|1|0||
||||—||—|||—|—|—|—<br>—<br>—||||GR2_ARC_RATE[7:0]|||||||
||Initial|value:|0||0|||0|0|0|0<br>0<br>0||0|0|0|0|0|0|0|0||
|||R/W:|R||R|||R|R|R|R<br>R<br>R||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||||**Initial Value**||||**R/W**|**Description**|||||||||||
|31|to 25|—||||All||0||R|Reserved|||||||||||
||||||||||||These bits are always read as 0.||||The write value should always be 0.|||||||
|24||GR2_ARC_||||0||||R/W|Alpha Blending Mode in Rectangular Area|||||||||||
|||MODE|||||||||0: Addition|||||||||||
||||||||||||1: Subtraction|||||||||||
|23|to 16|GR2_ARC_||||0||||R/W|Sets the alpha coefficient for alpha blending in a rectangular||||||||area. (0 to 255)|||
|||COEF[7:0]|||||||||[7:0]: Variation (absolute|||value)||||||||
|15|to 8|—||||All||0||R|Reserved|||||||||||
||||||||||||These bits are always read as 0.||||The write value should always be 0.|||||||
|7 to 0||GR2_ARC_||||0||||R/W|Sets the value obtained by subtracting 1 from||||||the frame rate||for alpha|||
|||RATE[7:0]|||||||||blending in a rectangular area.|||||||||||

Note: This bit is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.15 Alpha Blending Control Register 7 (Graphics 2) (GR2_AB7)

||Bit:|31|30|29|28||27||26|25|24|23|22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—||—|—|—|||GR2_ARC_DEF[7:0]||||||||
||Initial value:|0|0|0|0||0||0|0|0|1|1|1|1|1|1|1||1||
||R/W:|R|R|R|R||R||R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W||
||Bit:|15|14|13|12||11||10|9|8|7|6|5|4|3|2|1||0||
|||||||||||||||||||||GR2_||
|||—|—|—|—||—||—|—|—|—|—|—|—|—|—|—||CK_ON||
||Initial value:|0|0|0|0||0||0|0|0|0|0|0|0|0|0|0||0||
||R/W:|R|R|R|R||R||R|R|R|R|R|R|R|R|R|R||R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**||||||||||||
|31|to 24|—||All|0|||R||Reserved||||||||||||
|||||||||||These bits are always read as 0.|||||The write value should always be 0.|||||||
|23|to 16|GR2_ARC_||255||||R/W||Sets the initial alpha value for alpha blending in a rectangular|||||||||area.|||
|||DEF[7:0]||||||||||||||||||||
|15|to 1|—||All|0|||R||Reserved||||||||||||
|||||||||||These bits are always read as 0.|||||The write value should always be 0.|||||||
|0||GR2_CK_||0||||R/W||Turns on/off CLUT-index/RGB-index chroma-key processing.||||||||||||
|||ON||||||||0: Off||||||||||||
|||||||||||1: On||||||||||||

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.16 Alpha Blending Control Register 8 (Graphics 2) (GR2_AB8)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GR2_CK_KCLUT[7:0]||||||||GR2_CK_KG[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GR2_CK_KB[7:0]||||||||GR2_CK_KR[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR2_CK_|0|R/W|CLUT Signal for CLUT-Index Chroma-Key Processing|
||KCLUT[7:0]|||CLUT: Unsigned 8 bits (0 to 255 [LSB])|
|23 to 16|GR2_CK_|0|R/W|G Signal for RGB-Index Chroma-Key Processing|
||KG[7:0]|||G: Unsigned 8 bits (0 to 255 [LSB])|
|15 to 8|GR2_CK_|0|R/W|B Signal for RGB-Index Chroma-Key Processing|
||KB[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|7 to 0|GR2_CK_|0|R/W|R Signal for RGB-Index Chroma-Key Processing|
||KR[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.17 Alpha Blending Control Register 9 (Graphics 2) (GR2_AB9)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GR2_CK_A[7:0]|||||||||GR2_CK_G[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||GR2_CK_B[7:0]||||||||GR2_CK_R[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR2_CK_A|0|R/W|Replaced Alpha Signal after RGB/CLUT-Index Chroma-Key Processing|
||[7:0]|||α: Unsigned 8 bits (0 to 255 [LSB])|
|23 to 16|GR2_CK_G|0|R/W|Replaced G Signal after RGB/CLUT-Index Chroma-Key Processing|
||[7:0]|||G: Unsigned 8 bits (0 to 255 [LSB])|
|15 to 8|GR2_CK_B|0|R/W|Replaced B Signal after RGB/CLUT-Index Chroma-Key Processing|
||[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|7 to 0|GR2_CK_R|0|R/W|Replaced R Signal after RGB/CLUT-Index Chroma-Key Processing|
||[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.18 Alpha Blending Control Register 10 (Graphics 2) (GR2_AB10)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||GR2_A0[7:0]||||||||GR2_G0[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||GR2_B0[7:0]||||||||GR2_R0[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR2_A0|0|R/W|CLUT1α0 Signal|
||[7:0]|||Replaced withαsignal when in the CLUT1 format and CLUT1= 0.|
|||||Replaced withαsignal when in theαRGB1555 or RGBα5551 format and|
|||||α= 0.|
|23 to 16|GR2_G0|0|R/W|CLUT1 G0 Signal|
||[7:0]|||Replaced with G signal when in the CLUT1 format and CLUT1 = 0.|
|15 to 8|GR2_B0|0|R/W|CLUT1 B0 Signal|
||[7:0]|||Replaced with B signal when in the CLUT1 format and CLUT1 = 0.|
|7 to 0|GR2_R0|0|R/W|CLUT1 R0 Signal|
||[7:0]|||Replaced with R signal when in the CLUT1 format and CLUT1 = 0.|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.19 Alpha Blending Control Register 11 (Graphics 2) (GR2_AB11)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||GR2_A1[7:0]||||||||GR2_G1[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||GR2_B1[7:0]||||||||GR2_R1[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR2_A1|0|R/W|CLUT1α1 Signal|
||[7:0]|||Replaced withαsignal when in the CLUT1 format and CLUT1 = 1.|
|||||Replaced withαsignal when in theαRGB1555 or RGBα5551 format and|
|||||α= 1.|
|23 to 16|GR2_G1|0|R/W|CLUT1 G1 Signal|
||[7:0]|||Replaced with G signal when in the CLUT1 format and CLUT1 = 1.|
|15 to 8|GR2_B1|0|R/W|CLUT1 B1 Signal|
||[7:0]|||Replaced with B signal when in the CLUT1 format and CLUT1 = 1.|
|7 to 0|GR2_R1|0|R/W|CLUT1 R1 Signal|
||[7:0]|||Replaced with R signal when in the CLUT1 format and CLUT1 = 1.|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.20 Background Color Control Register (Graphics 2) (GR2_BASE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|||GR2_BASE_G[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GR2_BASE_B[7:0]||||||||GR2_BASE_R[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|23 to 16|GR2_BASE_G|0|R/W|Background Color G Signal|
||[7:0]|||G: Unsigned 8 bits (0 to 255 [LSB])|
|15 to 8|GR2_BASE_B|0|R/W|Background Color B Signal|
||[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|7 to 0|GR2_BASE_R|0|R/W|Background Color R Signal|
||[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.21 CLUT Table Control Register (Graphics 2) (GR2_CLUT)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|GR2_||
|||||||||||||||||CLT_SEL||
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
|16|||GR2_CLT_|0|R/W|CLUT Table Select Signal|
||||SEL|||0: Selects CLUT table 0.|
|||||||The format is converted toαRGB8888 based on the CLUT table 0.|
|||||||CLUT table 1 can be read from or written to by the CPU.|
|||||||1: Selects CLUT table 1.|
|||||||The format is converted toαRGB8888 based on the CLUT table 1.|
|||||||CLUT table 0 can be read from or written to by the CPU.|
|15|to|0|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

Note: This register is updated when GR2_P_VEN in GR2_UPDATE is 1.

## 33.2.22 Status Monitor Register (Graphics 2) (GR2_MON)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
|||||||||||||||||GR2_||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|ARC_ST||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||GR2_ARC_ST|0|R|Status Flag for Alpha Blending in Rectangular Area|
|||||||0: Addition or subtraction has been completed. (αvalue is 0 or 255)|
|||||||1: Addition or subtraction is in progress.|

## 33.2.23 Graphics 3 Register Update Control Register (GR3_UPDATE)

||Bit:|31|30|29|28|27||26|25|24|23<br>22<br>21<br>20||19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—||—|—|—|—<br>—<br>—<br>—||—|—|—||—||
||Initial value:|0|0|0|0|0||0|0|0|0<br>0<br>0<br>0||0|0|0||0||
||R/W:|R|R|R|R|R||R|R|R|R<br>R<br>R<br>R||R|R|R||R||
||Bit:|15|14|13|12|11||10|9|8|7<br>6<br>5<br>4||3|2|1||0||
|||—|—|—|—|—||—|—|GR3_<br>UPDATE|—<br>—<br>—<br>GR3_<br>P_VEN||—|—|—||GR3_<br>IBUS_<br>VEN||
||Initial value:|0|0|0|0|0||0|0|0|0<br>0<br>0<br>0||0|0|0||0||
||R/W:|R|R|R|R|R||R|R|R/WC1<br>R<br>R<br>R<br>R/WC1|||R|R|R|R/WC1|||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**||||||||||
|31|to 9|—||All|0||R||Reserved||||||||||
||||||||||These bits||are always read as 0. The write value should always be 0.||||||||
|8||GR3_||0|||R/WC1||Frame Buffer Read Control Register Update||||||||||
|||UPDATE|||||||0: Registers are not updated.||||||||||
||||||||||1: Registers are updated.||||||||||
|7 to 5||—||All|0||R||Reserved||||||||||
||||||||||These bits||are always read as 0. The write value should always be 0.||||||||
|4||GR3_P_||0|||R/WC1||Graphics Display Register Update||||||||||
|||VEN|||||||0: Registers are not updated.||||||||||
||||||||||1: Registers are updated at the rising edge of the Vsync.||||||||||
|3 to 1||—||All|0||R||Reserved||||||||||
||||||||||These bits||are always read as 0. The write value should always be 0.||||||||
|0||GR3_IBUS_||0|||R/WC1||Frame Buffer Read Register Update||||||||||
|||VEN|||||||0: Registers are not updated.||||||||||
||||||||||1: Registers are updated at the rising edge of the Vsync.||||||||||

## 33.2.24 Frame Buffer Read Control Register (Graphics 3) (GR3_FLM_RD)

||Bit:|31|30|29|28||27||26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—||—|—|—|—|—|—|—|—|—|—|—||
||Initial value:|0|0|0|0||0||0|0|0|0|0|0|0|0|0|0|0||
||R/W:|R|R|R|R||R||R|R|R|R|R|R|R|R|R|R|R||
||Bit:|15|14|13|12||11||10|9|8|7|6|5|4|3|2|1|0||
||||||||||||||||||||GR3_||
|||—|—|—|—||—||—|—|—|—|—|—|—|—|—|—|R_ENB||
||Initial value:|0|0|0|0||0||0|0|0|0|0|0|0|0|0|0|0||
||R/W:|R|R|R|R||R||R|R|R|R|R|R|R|R|R|R|R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**|||||||||||
|31|to 1|—||All|0|||R||Reserved|||||||||||
|||||||||||These bits are always read as 0.|||||The write value should always be 0.||||||
|0||GR3_R_||0||||R/W||Frame Buffer Read Enable|||||||||||
|||ENB||||||||0: Frame buffer reading is disabled.|||||||||||
|||||||||||1: Frame buffer reading is enabled.|||||||||||

Note: This register is updated when GR3_IBUS_VEN in GR3_UPDATE is 1.

## 33.2.25 Frame Buffer Control Register 1 (Graphics 3) (GR3_FLM1)

|||Bit:|31|30|29|28||27||26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||||GR3_||
||||—|—|—|—||—||—|—<br>—<br>—|—|—|—|—|—|—|LN_OFF_||
|||||||||||||||||||DIR||
|||Initial value:|0|0|0|0||0||0|0<br>0<br>0|0|0|0|0|0|0|0||
|||R/W:|R|R|R|R||R||R|R<br>R<br>R|R|R|R|R|R|R|R/W||
|||Bit:|15|14|13|12||11||10|9<br>8<br>7|6|5|4|3|2|1|0||
|||||||||||||||||||GR3_||
||||—|—|—|—||—||—|—<br>GR3_FLM_SEL[1:0]|—|—|—|—|—|—|BST_||
|||||||||||||||||||MD||
|||Initial value:|0|0|0|0||0||0|0<br>0<br>0|0|0|0|0|0|0|0||
|||R/W:|R|R|R|R||R||R|R/W<br>R/W<br>R|R|R|R|R|R|R|R/W||
|**Bit**|||**Bit Name**||**Initial Value**||||**R/W**||**Description**|||||||||
|31||to 17|—||All|0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0.|||The write value should always be 0.||||||
|16|||GR3_LN_||0||||R/W||Selects the line offset address direction of the frame buffer.|||||||||
||||OFF_DIR||||||||0: Increments the address by the line offset address.|||||||||
||||||||||||1: Decrements the address by the line offset address.|||||||||
|15||to 10|—||All|0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0.|||The write value should always be 0.||||||
|9,|8||GR3_FLM_||0||||R/W||Selects a frame buffer address setting signal.|||||||||
||||SEL[1:0]||||||||0: Selects frame 0.|||||||||
||||||||||||1: Selects register|GR3_FLM_NUM.||||||||
||||||||||||2: Selects frame 0.|||||||||
||||||||||||3: Setting prohibited|||||||||
|7 to 1|||—||All|0|||R||Reserved|||||||||
||||||||||||These bits are always read as 0.|||The write value should always be 0.||||||
|0|||GR3_BST_||0||||R/W||Frame Buffer Burst Transfer Mode|||||||||
||||MD||||||||0: 32-byte transfer|||||||||
||||||||||||1: 128- byte transfer|||||||||

Note: GR3_LN_OFF_DIR and GR3_FLM_SEL are updated when GR3_IBUS_VEN in GR3_UPDATE is 1. GR3_BST_MD is updated when GR3_IBUS_VEN and GR3_P_VEN in GR3_UPDATE are 1.

## 33.2.26 Frame Buffer Control Register 2 (Graphics 3) (GR3_FLM2)

||Bit:|31|30|29|28||27|26|25<br>24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||GR3_BASE[31:16]|||||||||
||Initial value:|0|0|0|0||0|0|0<br>0|0|0|0|0|0|0|0|0|
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||Bit:|15|14|13|12||11|10|9<br>8|7|6|5|4|3|2|1|0|
||||||||||GR3_BASE[15:0]|||||||||
||Initial value:|0|0|0|0||0|0|0<br>0|0|0|0|0|0|0|0|0|
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**|||||||||
|31|to 0|GR3_BASE||0|||R/W||Frame Buffer Base||Address (upper)|||||||
|||[31:0]|||||||Sets the start address of the frame buffer where||||||frame|data is to be||
||||||||||stored.|||||||||
||||||||||GR_BASE[4:3] and||GR_BASE[6:3] are referred||||to during 32-byte burst|||
||||||||||transfer and|128-byte burst transfer, respectively, to skip the start line||||||||
||||||||||data.|||||||||
||||||||||The lower 3|bits should be fixed|||to 000.|||||

Note: This register is updated when GR3_IBUS_VEN and GR3_P_VEN in GR3_UPDATE are 1.

## 33.2.27 Frame Buffer Control Register 3 (Graphics 3) (GR3_FLM3)

||Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|||||||GR3_LN_OFF[14:0]||||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14|13|12||11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||—|—|—|—||—|—|GR3_FLM_NUM[9:0]||||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R|R|R||R|R|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**||||||||
|31||—||0|||R||Reserved||||||||
||||||||||This bit is always read as|0. The write value should always be|||||0.||
|30|to 16|GR3_LN_||0|||R/W||Frame Buffer Line Offset|Address|||||||
|||OFF[14:0]|||||||Sets the line offset address for calculating the start address of||||||each line.||
||||||||||Line 0: GR3_BASE||||||||
||||||||||Line 1: GR3_BASE + GR3_LN_OFF × 1||||||||
||||||||||:||||||||
||||||||||Line n: GR3_BASE + GR3_LN_OFF × n||||||||
||||||||||For 32 byte transfer, the lower 5 bits should be fixed to|||||0_0000.|||
||||||||||For 128 byte transfer, the|lower 7|bits should be fixed to 000_0000.||||||
|15|to 10|—||All|0||R||Reserved||||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||||
|9 to 0||GR3_FLM_||0|||R/W||Frame Number of Frame|Buffer|||||||
|||NUM[9:0]|||||||Manually set the frame number when GR3_FLM_SEL = 1.||||||||

Note: This register is updated when GR3_IBUS_VEN in GR3_UPDATE is 1.

## 33.2.28 Frame Buffer Control Register 4 (Graphics 3) (GR3_FLM4)

||Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22<br>21<br>20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—|—|—<br>—<br>—<br>GR3_FLM_OFF[22:16]|||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||R/W:|R|R|R|R||R|R|R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W||R/W||
||Bit:|15|14|13|12||11|10|9<br>8<br>7<br>6<br>5<br>4<br>3|2|1|0||
||||||||||GR3_FLM_OFF[15:0]|||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W||R/W||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**|||||
|31|to 23|—||All|0||R||Reserved|||||
||||||||||These bits are always read as 0. The write value should||always be 0.|||
|22|to 0|GR3_FLM_||0|||R/W||Frame Buffer Frame Offset Address (upper)|||||
|||OFF[22:0]|||||||Specifies the frame offset address used for calculating the start|||address||
||||||||||of each frame buffer when more than one buffer is used.|||||
||||||||||Buffer 0: GR3_BASE|||||
||||||||||Buffer 1: GR3_BASE + GR3_FLM_OFF × 1|||||
||||||||||:|||||
||||||||||Buffer n: GR3_BASE + GR3_FLM_OFF × n|||||
||||||||||For 32 byte transfer, the lower 5 bits should be fixed to 0_0000.|||||
||||||||||For 128 byte transfer, the lower 7 bits should be fixed to||000_0000.|||

Note: This register is updated when GR3_IBUS_VEN in GR3_UPDATE is 1.

## 33.2.29 Frame Buffer Control Register 5 (Graphics 3) (GR3_FLM5)

||Bit:|31|30|29|28||27||26|25<br>24|23|22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—|||||GR3_FLM_LNUM[10:0]||||||
||Initial value:|0|0|0|0||0||0|0<br>0|0|0<br>0<br>0|0|0|0|0||
||R/W:|R|R|R|R||R||R/W|R/W<br>R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14|13|12||11||10|9<br>8|7|6<br>5<br>4|3|2|1|0||
|||—|—|—|—||—|||||GR3_FLM_LOOP[10:0]||||||
||Initial value:|0|0|0|0||0||0|1<br>1|1|1<br>1<br>1|1|1|1|1||
||R/W:|R|R|R|R||R||R/W|R/W<br>R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**||||||||
|31|to 27|—||All|0|||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write value||||should|always be 0.|||
|26|to 16|GR3_FLM_||0||||R/W||Sets number of lines in a frame||||||||
|||LNUM[10:0]||||||||The number|of lines is (GR3_FLM_LNUM + 1).|||||||
|15|to 11|—||All|0|||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write value||||should|always be 0.|||
|10|to 0|GR3_FLM_||1023||||R/W||Number of lines when reading the addresses repeatedly by returning|||||||to|
|||LOOP[10:0]||||||||the start address||after reaching the end address.||||||
|||||||||||The number|of lines is (GR3_FLM_LOOP||+ 1).|||||

Note: This register is updated when GR3_IBUS_VEN in GR3_UPDATE is 1.

## 33.2.30 Frame Buffer Control Register 6 (Graphics 3) (GR3_FLM6)

||Bit:|31|30|29|28||27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||GR3_FORMAT[3:0]|||||—||GR3_HW[10:0]||||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R/W|R/W|R/W|R/W||R|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W<br>R/W||R/W||
||Bit:|15|14|13|12||11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||—|—|—|GR3_RDSWA[2:0]||||—<br>—<br>—<br>—||GR3_STA_POS[5:0]||||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R|R|R/W|R/W||R/W|R<br>R<br>R<br>R|R/W|R/W<br>R/W||R/W<br>R/W||R/W||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**||||||||
|31|to 28|GR3_||0|||R/W||Sets the format of the frame buffer read signal.||||||||
|||FORMAT|||||||0: RGB565||||||||
|||[3:0]|||||||1: RGB888||||||||
||||||||||2:αRGB1555||||||||
||||||||||3:αRGB4444||||||||
||||||||||4:αRGB8888||||||||
||||||||||5: CLUT8||||||||
||||||||||6: CLUT4||||||||
||||||||||7: CLUT1||||||||
||||||||||8: Setting prohibited||||||||
||||||||||9: Setting prohibited||||||||
||||||||||10: RGBα5551||||||||
||||||||||11: RGBα8888||||||||
||||||||||12 to 15: Setting prohibited||||||||
|27||—||0|||R||Reserved||||||||
||||||||||This bit is always read as|0. The|write value should always be 0.||||||
|26|to 16|GR3_HW||0|||R/W||Sets the width of the horizontal valid period.||||||||
|||[10:0]|||||||The width is (GR3_HW +|1) pixels.|||||||
||||||||||Note: Set to 2 or greater.||||||||
|15|to 13|—||All|0||R||Reserved||||||||
||||||||||These bits are always read as 0.||The write value should always be 0.||||||
|12|to 10|GR3_||0|||R/W||Sets 8-, 16-, and 32-bit swap.||||||||
|||RDSWA|||||||These three bits specify the method for|||swapping the bits||of frame buffer|||
|||[2:0]|||||||read data as follows.||||||||
||||||||||Bit 0||||||||
||||||||||0: 8 bits are not swapped.||||||||
||||||||||1: 8 bits are swapped.||||||||
||||||||||Bit 1||||||||
||||||||||0: 16 bits are not swapped.||||||||
||||||||||1: 16 bits are swapped.||||||||
||||||||||Bit 2||||||||
||||||||||0: 32 bits are not swapped.||||||||
||||||||||1: 32 bits are swapped.||||||||
||||||||||When eight bits are put together,||they are swapped as follows. Each of||||||
||||||||||(1) to (8) indicates eight-bit data.||||||||
||||||||||000: (1) (2) (3) (4) (5) (6) (7) (8) [No swap]||||||||
||||||||||001: (2) (1) (4) (3) (6) (5) (8) (7) [8-bit swap]||||||||
||||||||||010: (3) (4) (1) (2) (7) (8) (5) (6) [16-bit|||swap]|||||
||||||||||011: (4) (3) (2) (1) (8) (7) (6) (5) [16-bit|||swap +|8-bit swap]||||
||||||||||100: (5) (6) (7) (8) (1) (2) (3) (4) [32-bit|||swap]|||||
||||||||||101: (6) (5) (8) (7) (2) (1) (4) (3) [32-bit|||swap +|8-bit swap]||||
||||||||||110: (7) (8) (5) (6) (3) (4) (1) (2) [32-bit|||swap +|16-bit swap]||||
||||||||||111: (8) (7) (6) (5) (4) (3) (2) (1) [32-bit|||swap +|16-bit swap + 8-bit swap]||||
|9 to 6||—||All|0||R||Reserved||||||||
||||||||||These bits are always read as 0.||The write value should always be 0.||||||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|5 to 0|GR3_STA_|0|R/W|Sets the amount of data to be skipped through.|
||POS[5:0]|||Specifically data amount equal to the amount indicated by|
|||||GR3_STA_POS is skipped from the start of the line.|

Note: GR3_STA_POS is updated when GR3_P_VEN in GR3_UPDATE is 1. GR3_RDSWA is updated when GR3_UPDATE in GR3_UPDATE is 1.

GR3_FORMAT and GR3_HW are updated when GR3_IBUS_VEN and GR3_P_VEN in GR3_UPDATE are 1.

## 33.2.31 Alpha Blending Control Register 1 (Graphics 3) (GR3_AB1)

|||Bit:|31|30||29||28||27||26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|—||—||—||—||—|—<br>—<br>—<br>—|—|—|—|—|—|—||
|||Initial value:|0|0||0||0||0||0|0<br>0<br>0<br>0|0|0|0|0|0|0||
|||R/W:|R|R||R||R||R||R|R<br>R<br>R<br>R|R|R|R|R|R|R||
|||Bit:|15|14||13||12||11||10|9<br>8<br>7<br>6|5|4|3|2|1|0||
||||GR3_ARC<br>_MUL|GR3_ACA<br>LC_MD||—||GR3_<br>ARC_ON||—||—|—<br>—<br>—<br>GR3_<br>ARC_<br>DISP_ON|—|GR3_<br>GRC_<br>DISP_ON|—|—|GR3_DISP_SEL[1:0]|||
|||Initial value:|0|0||0||0||0||0|0<br>0<br>0<br>0|0|0|0|0|0|0||
|||R/W:|R/W|R/W||R||R/W||R||R|R<br>R/W<br>R<br>R|R|R/W|R|R|R/W|R/W||
|**Bit**|||**Bit Name**|||**Initial Value**|||||**R/W**||**Description**||||||||
|31||to 16|—|||All|0||||R||Reserved||||||||
||||||||||||||These bits are always read as 0.||The write value should always be 0.||||||
|15|||GR3_ARC_|||0|||||R/W||Turns on/off multiplication processing with current alpha at alpha||||||||
||||MUL||||||||||blending in a rectangular area.||||||||
||||||||||||||0: Off||||||||
||||||||||||||1: On||||||||
|14|||GR3_ACALC_|||0|||||R/W||Turns on/off premultiplication processing at alpha blending in one-pixel||||||||
||||MD||||||||||units.||||||||
||||||||||||||0: Off||||||||
||||||||||||||1: On||||||||
|13|||—|||0|||||R||Reserved||||||||
||||||||||||||This bit is always read as|0. The|write value should always be 0.||||||
|12|||GR3_ARC_|||0|||||R/W||Turns on/off alpha blending in a rectangular area.||||||||
||||ON||||||||||0: Off||||||||
||||||||||||||1: On||||||||
|11 to 9|||—|||All|0||||R||Reserved||||||||
||||||||||||||These bits are always read as 0.||The write value should always be 0.||||||
|8|||GR3_ARC_|||0|||||R/W||Turns on/off frame-line display of||the image area for alpha blending in a||||||
||||DISP_ON||||||||||rectangular area.||||||||
||||||||||||||0: Frame-line display off||||||||
||||||||||||||1: Frame-line display on||||||||
|7 to 5|||—|||All|0||||R||Reserved||||||||
||||||||||||||These bits are always read as 0.||The write value should always be 0.||||||
|4|||GR3_GRC_|||0|||||R/W||Turns on/off frame-line display of the graphics image area.||||||||
||||DISP_ON||||||||||0: Frame-line display off||||||||
||||||||||||||1: Frame-line display on||||||||
|3,|2||—|||All|0||||R||Reserved||||||||
||||||||||||||These bits are always read as 0.||The write value should always be 0.||||||
|1,|0||GR3_DISP_|||0|||||R/W||Selects the graphics display mode.||||||||
||||SEL[1:0]||||||||||0: Background color display||||||||
||||||||||||||1: Lower-layer graphics display||||||||
||||||||||||||2: Current graphics display||||||||
||||||||||||||3: Blended display of lower-layer||graphics and current|||graphics|||

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.32 Alpha Blending Control Register 2 (Graphics 3) (GR3_AB2)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR3_GRC_VS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||GR3_GRC_VW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|GR3_GRC_|0|R/W|Sets the vertical start position of the graphics image area.|
||||VS[10:0]|||Note: Set to 4 or greater lines and the result of GR3_GRC_VS +|
|||||||GR3_GRC_VW should be smaller than or equal to 2039 lines.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|GR3_GRC_|0|R/W|Sets the vertical width of the graphics image area.|
||||VW[10:0]||||

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.33 Alpha Blending Control Register 3 (Graphics 3) (GR3_AB3)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR3_GRC_HS[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|||||GR3_GRC_HW[10:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|GR3_GRC_|0|R/W|Sets the horizontal start position of the graphics image area.|
||||HS[10:0]|||Note: Set to 16 or greater clocks and the result of GR3_GRC_HS +|
|||||||GR3_GRC_HW should be smaller than or equal to 2015 clocks.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|GR3_GRC_|0|R/W|Sets the horizontal width of the graphics image area.|
||||HW[10:0]|||Note: For displaying an image with 1- or 2-pixel horizontal width, set|
|||||||GR3_HW to 2 and GR3_GRC_HW to 1 (1-pixel) or 2 (2-pixel).|

Note: All the bits assigned to this address are updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.34 Alpha Blending Control Register 4 (Graphics 3) (GR3_AB4)

||Bit:|31|30|29|28||27||26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—|||||GR3_ARC_VS[10:0]||||||||
||Initial value:|0|0|0|0||0||0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R|R|R|R||R||R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14|13|12||11||10|9<br>8|7|6|5|4|3|2|1|0||
|||—|—|—|—||—|||||GR3_ARC_VW[10:0]||||||||
||Initial value:|0|0|0|0||0||0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R|R|R|R||R||R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**||||||||||
|31|to 27|—||All|0|||R||Reserved||||||||||
|||||||||||These bits are always read as 0.||||The write value should always be 0.||||||
|26|to 16|GR3_ARC_||0||||R/W||Sets the vertical start position of the valid|||||image area for alpha|||blending||
|||VS[10:0]||||||||in a rectangular area.||||||||||
|15|to 11|—||All|0|||R||Reserved||||||||||
|||||||||||These bits are always read as 0.||||The write value should always be 0.||||||
|10|to 0|GR3_ARC_||0||||R/W||Sets the vertical width of the valid image|||||area for alpha blending in a|||||
|||VW[10:0]||||||||rectangular area.||||||||||

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.35 Alpha Blending Control Register 5 (Graphics 3) (GR3_AB5)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR3_ARC_HS[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||GR3_ARC_HW[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|GR3_ARC_|0|R/W|Sets the horizontal start position of the valid image area for alpha|
||||HS[10:0]|||blending in a rectangular area.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|10|to|0|GR3_ARC_|0|R/W|Sets the horizontal width of the valid image area for alpha blending in a|
||||HW[10:0]|||rectangular area.|

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.36 Alpha Blending Control Register 6 (Graphics 3) (GR3_AB6)

|||Bit:|31||30|||29|28|27|26|25<br>24||23|22|21|20|19|18|17|16|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—||—|||—|—|—|—|—<br>GR3_ARC<br>_MODE||||GR3_ARC_COEF[7:0]||||||||
||Initial|value:|0||0|||0|0|0|0|0<br>0||0|0|0|0|0|0|0||0||
|||R/W:|R||R|||R|R|R|R|R<br>R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|||
|||Bit:|15||14|||13|12|11|10|9<br>8||7|6|5|4|3|2|1||0||
||||—||—|||—|—|—|—|—<br>—||||GR3_ARC_RATE[7:0]||||||||
||Initial|value:|0||0|||0|0|0|0|0<br>0||0|0|0|0|0|0|0||0||
|||R/W:|R||R|||R|R|R|R|R<br>R||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|||
|**Bit**||**Bit**|**Name**||**Initial Value**|||||**R/W**||**Description**||||||||||||
|31|to 25|—|||All|||0||R||Reserved||||||||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||||
|24||GR3_ARC_|||0|||||R/W||Alpha Blending Mode in|||Rectangular Area|||||||||
|||MODE||||||||||0: Addition||||||||||||
|||||||||||||1: Subtraction||||||||||||
|23|to 16|GR3_ARC_|||0|||||R/W||Sets the alpha coefficient for alpha blending in a rectangular||||||||area. (0||to 255)||
|||COEF[7:0]||||||||||[7:0]: Variation (absolute value)||||||||||||
|15|to 8|—|||All|||0||R||Reserved||||||||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||||
|7 to 0||GR3_ARC_|||0|||||R/W||Sets the value obtained|||by subtracting 1 from the frame rate|||||for alpha||||
|||RATE[7:0]||||||||||blending in a rectangular area.||||||||||||

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.37 Alpha Blending Control Register 7 (Graphics 3) (GR3_AB7)

||Bit:|31|30|29|28||27||26|25|24|23|22|21|20|19|18|17||16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—||—||—|—|—|||GR3_ARC_DEF[7:0]||||||||
||Initial value:|0|0|0|0||0||0|0|0|1|1|1|1|1|1|1||1||
||R/W:|R|R|R|R||R||R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W||
||Bit:|15|14|13|12||11||10|9|8|7|6|5|4|3|2|1||0||
|||||||||||||||||||||GR3_||
|||—|—|—|—||—||—|—|—|—|—|—|—|—|—|—||CK_ON||
||Initial value:|0|0|0|0||0||0|0|0|0|0|0|0|0|0|0||0||
||R/W:|R|R|R|R||R||R|R|R|R|R|R|R|R|R|R||R/W||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**||||||||||||
|31|to 24|—||All|0|||R||Reserved||||||||||||
|||||||||||These bits are always read as 0.|||||The write value should always be 0.|||||||
|23|to 16|GR3_ARC_||255||||R/W||Sets the initial alpha value for alpha blending in a rectangular|||||||||area.|||
|||DEF[7:0]||||||||||||||||||||
|15|to 1|—||All|0|||R||Reserved||||||||||||
|||||||||||These bits are always read as 0.|||||The write value should always be 0.|||||||
|0||GR3_CK_||0||||R/W||Turns on/off CLUT-index/RGB-index chroma-key processing.||||||||||||
|||ON||||||||0: Off||||||||||||
|||||||||||1: On||||||||||||

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.38 Alpha Blending Control Register 8 (Graphics 3) (GR3_AB8)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GR3_CK_KCLUT[7:0]||||||||GR3_CK_KG[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||GR3_CK_KB[7:0]||||||||GR3_CK_KR[7:0]||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR3_CK_|0|R/W|CLUT Signal for CLUT-Index Chroma-Key Processing|
||KCLUT[7:0]|||CLUT: Unsigned 8 bits (0 to 255 [LSB])|
|23 to 16|GR3_CK_|0|R/W|G Signal for RGB-Index Chroma-Key Processing|
||KG[7:0]|||G: Unsigned 8 bits (0 to 255 [LSB])|
|15 to 8|GR3_CK_|0|R/W|B Signal for RGB-Index Chroma-Key Processing|
||KB[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|7 to 0|GR3_CK_|0|R/W|R Signal for RGB-Index Chroma-Key Processing|
||KR[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.39 Alpha Blending Control Register 9 (Graphics 3) (GR3_AB9)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||GR3_CK_A[7:0]|||||||||GR3_CK_G[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||GR3_CK_B[7:0]||||||||GR3_CK_R[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR3_CK_A|0|R/W|Replaced Alpha Signal after RGB/CLUT-Index Chroma-Key Processing|
||[7:0]|||α: Unsigned 8 bits (0 to 255 [LSB])|
|23 to 16|GR3_CK_G|0|R/W|Replaced G Signal after RGB/CLUT-Index Chroma-Key Processing|
||[7:0]|||G: Unsigned 8 bits (0 to 255 [LSB])|
|15 to 8|GR3_CK_B|0|R/W|Replaced B Signal after RGB/CLUT-Index Chroma-Key Processing|
||[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|7 to 0|GR3_CK_R|0|R/W|Replaced R Signal after RGB/CLUT-Index Chroma-Key Processing|
||[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.40 Alpha Blending Control Register 10 (Graphics 3) (GR3_AB10)

||Bit:|31|30|29|28||27|26|25<br>24<br>23|22|21|20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||GR3_A0[7:0]|||||||GR3_G0[7:0]|||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0|0|0|0<br>0|0|0|0||
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W||
||Bit:|15|14|13|12||11|10|9<br>8<br>7|6|5|4<br>3|2|1|0||
||||||GR3_B0[7:0]|||||||GR3_R0[7:0]|||||
||Initial value:|0|0|0|0||0|0|0<br>0<br>0|0|0|0<br>0|0|0|0||
||R/W:|R/W|R/W|R/W|R/W|R/W||R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W||
|**Bit**||**Bit Name**||**Initial Value**|||**R/W**||**Description**||||||||
|31|to 24|GR3_A0||0|||R/W||CLUT1α0 Signal||||||||
|||[7:0]|||||||Replaced withαsignal when in|||the CLUT1 format and||CLUT1 = 0.|||
||||||||||Replaced withαsignal when in theαRGB1555 or||||RGBα5551 format and||||
||||||||||α= 0.||||||||
|23|to 16|GR3_G0||0|||R/W||CLUT1 G0 Signal||||||||
|||[7:0]|||||||Replaced with G signal when in|||the CLUT1 format and||CLUT1 = 0.|||
|15|to 8|GR3_B0||0|||R/W||CLUT1 B0 Signal||||||||
|||[7:0]|||||||Replaced with B signal when in|||the CLUT1 format and||CLUT1 = 0.|||
|7 to 0||GR3_R0||0|||R/W||CLUT1 R0 Signal||||||||
|||[7:0]|||||||Replaced with R signal when in|||the CLUT1 format and||CLUT1 = 0.|||

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.41 Alpha Blending Control Register 11 (Graphics 3) (GR3_AB11)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||GR3_A1[7:0]||||||||GR3_G1[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||GR3_B1[7:0]||||||||GR3_R1[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|GR3_A1|0|R/W|CLUT1α1 Signal|
||[7:0]|||Replaced withαsignal when in the CLUT1 format and CLUT1 = 1.|
|||||Replaced withαsignal when in theαRGB1555 or RGBα5551 format and|
|||||α= 1.|
|23 to 16|GR3_G1|0|R/W|CLUT1 G1 Signal|
||[7:0]|||Replaced with G signal when in the CLUT1 format and CLUT1 = 1.|
|15 to 8|GR3_B1|0|R/W|CLUT1 B1 Signal|
||[7:0]|||Replaced with B signal when in the CLUT1 format and CLUT1 = 1.|
|7 to 0|GR3_R1|0|R/W|CLUT1 R1 Signal|
||[7:0]|||Replaced with R signal when in the CLUT1 format and CLUT1 = 1.|

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.42 Background Color Control Register (Graphics 3) (GR3_BASE)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|||GR3_BASE_G[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||GR3_BASE_B[7:0]||||||||GR3_BASE_R[7:0]|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 24|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|23 to 16|GR3_BASE_G|0|R/W|Background Color G Signal|
||[7:0]|||G: Unsigned 8 bits (0 to 255 [LSB])|
|15 to 8|GR3_BASE_B|0|R/W|Background Color B Signal|
||[7:0]|||B: Unsigned 8 bits (0 to 255 [LSB])|
|7 to 0|GR3_BASE_R|0|R/W|Background Color R Signal|
||[7:0]|||R: Unsigned 8 bits (0 to 255 [LSB])|

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.43 CLUT Table and Interrupt Control Register (Graphics 3) (GR3_CLUT_INT)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|GR3_||
|||||||||||||||||CLT_SEL||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|||||GR3_LINE[10:0]||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|17|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|16|||GR3_CLT_|0|R/W|CLUT Table Select Signal|
||||SEL|||0: Selects CLUT table 0.|
|||||||The format is converted toαRGB8888 based on the CLUT table 0.|
|||||||CLUT table 1 can be read from or written to by the CPU.|
|||||||1: Selects CLUT table 1.|
|||||||The format is converted toαRGB8888 based on the CLUT table 1.|
|||||||CLUT table 0 can be read from or written to by the CPU.|
|15|to|11|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|10|to|0|GR3_LINE|0|R/W|Line Interrupt Set|
||||[10:0]|||When number of lines matches the value of the GR3_LINE bits, an|
|||||||interrupt signal is output.|
|||||||This function is enabled even when the graphics 3 process is not used.|

Note: This register is updated when GR3_P_VEN in GR3_UPDATE is 1.

## 33.2.44 Status Monitor Register (Graphics 3) (GR3_MON)

|Bit:|31|30|29|28|27|26|25|24|23||22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|||||GR3_LIN_STAT[10:0]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0||0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R||R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7||6|5|4|3|2|1|0||
||||||||||||||||||GR3_||
||—|—|—|—|—|—|—|—|—||—|—|—|—|—|—|ARC_ST||
|Initial value:|0|0|0|0|0|0|0|0|0||0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R||R|R|R|R|R|R|R||

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|27|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|26|to|16|GR3_LIN_|0|R|Line Position of Image being Currently Read|
||||STAT[10:0]||||
|15|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||GR3_ARC_|0|R|Status Flag for Alpha Blending in Rectangular Area|
||||ST|||0: Addition or subtraction has been completed. (αvalue is 0 or 255)|
|||||||1: Addition or subtraction is in progress.|

## 33.2.45 VIN Synthesizer Register Update Control Register (GR_VIN_UPDATE)

|||Bit:|31|30|29||28||27|26<br>25|24||23<br>22|21|20||19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|—|—||—||—|—<br>—|—||—<br>—|—|—||—|—|—|—||
||Initial|value:|0|0|0||0||0|0<br>0|0||0<br>0|0|0||0|0|0|0||
|||R/W:|R|R|R||R||R|R<br>R|R||R<br>R|R|R||R|R|R|R||
|||Bit:|15|14|13||12||11|10<br>9|8||7<br>6|5|4||3|2|1|0||
||||—|—|—||—||—|—<br>—|GR_VIN_<br>UPDATE||—<br>—|—|GR_VIN_<br>P_VEN||—|—|—|—||
||Initial|value:|0|0|0||0||0|0<br>0|0||0<br>0|0|0||0|0|0|0||
|||R/W:|R|R|R||R||R|R<br>R|R/WC1||R<br>R|R|R/WC1||R|R|R|R||
|**Bit**||**Bit Name**||**Initial Value**||||**R/W**||**Description**||||||||||||
|31|to 9|—||All 0||||R||Reserved||||||||||||
|||||||||||These bits are always read as 0. The write value|||||||should always be 0.|||||
|8||GR_VIN_||0||||R/WC1||Graphics Display Register Update||||||||||||
|||UPDATE||||||||0: Registers are not|||updated.|||||||||
|||||||||||1: Registers are updated.||||||||||||
|7 to 5||—||All 0||||R||Reserved||||||||||||
|||||||||||These bits are always read as 0. The write value|||||||should always be 0.|||||
|4||GR_VIN_||0||||R/WC1||Graphics Display Register Update||||||||||||
|||P_VEN||||||||0: Registers are not|||updated.|||||||||
|||||||||||1: Registers are updated at the rising edge of the|||||||Vsync.|||||
|3 to 0||—||All 0||||R||Reserved||||||||||||
|||||||||||These bits are always read as 0. The write value|||||||should always be 0.|||||

## 33.2.46 Alpha Blending Control Register 1 (VIN Synthesizer) (GR_VIN_AB1)

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R||
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||—|—|—|—|—|—|—|—|—|—|—|—|—|GR_VIN_<br>SCL_UND<br>_SEL|GR_VIN_DISP_<br>SEL[1:0]|||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0||
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W||

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 3|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|2|GR_VIN_|0|R/W|Selection of Lower-Layer Plane in Scaler|
||SCL_UND_|||0: Selects graphics 0 as lower-layer graphics.|
||SEL|||1: Setting prohibited|
|1, 0|GR_VIN_|0|R/W|Selects the graphics display mode.|
||DISP_SEL|||0: Background color display (fixed to black)|
||[1:0]|||1: Lower-layer graphics display|
|||||2: Setting prohibited|
|||||3: Setting prohibited|

Notes: GR_VIN_SCL_UND_SEL is updated when GR_VIN_UPDATE in GR_VIN_UPDATE is 1. The other bits of this register are updated when GR_VIN_P_VEN in GR_VIN_UPDATE is 1.

## 33.3 Usage Method

## 33.3.1 Mute Image

The initial values of the GR0_DISP_SEL[1:0], GR2_DISP_SEL[1:0], GR3_DISP_SEL[1:0], and GR_VIN_DISP_SEL[1:0] bits are all 0. Accordingly, in the initial setting, a background color is displayed both inside and outside the graphics area for the graphics 0, 2, and 3 processes and the VIN synthesizer. Since the default background color is black, the black mute image is displayed in the initial state. Note that the background color for the VIN synthesizer is fixed to black.

## 33.3.2 Alpha Blending in Rectangular Area

The alpha coefficient and the frame rate can be changed during fade in and fade out by modifying the GR_ARC_MODE, GR_ARC_COEF[7:0] and GR_ARC_RATE[7:0] bits, respectively.
