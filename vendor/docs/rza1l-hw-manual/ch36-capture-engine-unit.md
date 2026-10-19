# 36. Capture Engine Unit

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1916–1976. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

The capture engine unit (CEU) is a capture module that fetches image data externally input and transfers it to the memory. The CEU is connected to the system bus via bus bridge modules.

## 36.1 Features of CEU

Lists the features of CEU as follows.

## (1) Image data fetch

- Captures an image output from an external module and writes YCbCr data to the memory with it separated into Y data and CbCr data.

- Fetches image data other than YCbCr data, e.g. JPEG data, RGB565, from an externally connected module, such as a camera, and sequentially writes the image data to the memory.

- Fetches an interlace source image in both-field units or one-field units and writes it to the memory. In both-field capture, an image can be stored in the memory as a frame image.

## (2) Filter processing

- Performs scale-down and removal of high-frequency components (only in the horizontal direction) for an image using internal filters. Note that the scaled-down image must not exceed VGA. The filter processing can be applied to only YCbCr input data.

## (3) Format conversion

- Converts image data input in the YCbCr422 format into the YCbCr420 format and writes it to the memory. Note that the conversion algorithm is simple skipping in which the chrominance component (CbCr) of the evennumbered lines is skipped.

## 36.2 Functional Overview of CEU

The functional overview of the CEU is shown in Table 36.1 , and the main functions and their details are shown in Table 36.1 .

## **Table 36.1 Functional Overview of CEU**

|**Classification**|**Item**|**Function**|**Description**<br>**Note**|
|---|---|---|---|
|Connectable camera|Size|5 megapixels|2,560 pixels × 1,920 lines<br>Horizontal: 4-pixel units*<br>Vertical: 4-line units<br>Note: * 8-pixel units when<br>writing to other than the on-<br>chip RAM<br>The range of the image size<br>that can be input is as follows.<br>Horizontal: 2,560 pixels to 128<br>pixels<br>Vertical: 1,920 lines to 96 lines<br>[Note] This depends on the AC<br>characteristics of the device to<br>be connected, frame rate of<br>the connected device, and<br>transfer speed to the<br>destination RAM.<br>2,048 pixels × 1,536 lines<br>1,632 pixels × 1,224 lines<br>1,600 pixels × 1,200 lines<br>1,280 pixels × 1,024 lines<br>1,280 pixels × 960 lines<br>1,280 pixels × 768 lines<br>1,024 pixels × 768 lines<br>800 pixels × 600 lines<br>800 pixels × 480 lines<br>640 pixels × 480 lines<br>352 pixels × 288 lines<br>480 pixels × 240 lines<br>320 pixels × 240 lines,<br>240 pixels × 320 lines<br>176 pixels × 144 lines<br>160 pixels × 120 lines<br>128 pixels × 96 lines|
|||3 megapixels||
|||2 megapixels||
|||UXGA||
|||SXGA (1)||
|||SXGA (2)||
|||WXGA||
|||XGA||
|||SVGA||
|||WVGA||
|||VGA||
|||CIF||
|||WQVGA||
|||QVGA||
|||QCIF||
|||QQVGA||
|||Sub-QCIF||
||Input format|YCbCr422<br>8 bits|Cb0, Y0, Cr0, Y1…<br>Supports clock ratio of 1:1<br>Cr0, Y0, Cb0, Y1…<br>Y0, Cb0, Y1, Cr0…<br>Y0, Cr0, Y1, Cb0…|
|||Binary data|Specified amount to be fetched<br>on edges of the sync signal<br>Written sequentially<br>Data is fetched with the<br>horizontal sync signal as an<br>enable signal (RZ/A1LU and<br>RZ/A1LC only).|
||Horizontal and<br>vertical sync<br>signal polarities|Arbitrary|High-active and low-active|
||Capture start<br>location|Arbitrary|Can be specified in camera<br>input clock units<br>Horizontal: 1-cycle units<br>Vertical: 1-HD (horizontal sync<br>signal) units|
||Number of<br>captured pixels|Arbitrary|Can be specified in 4-pixel units<br>horizontally and in 4-line units<br>vertically|
||Interlace|Both-field capture|Stored as a field image<br>Capture: 2-VD (vertical sync<br>signal) units<br>Stored as a frame image|
|||One-field capture|Top field or bottom field can be<br>specified<br>Capture: 1-VD units|
|Memory write|Output format|YCbCr422<br>YCbCr420|YCbCr420 is realized by simple<br>skipping|
|Filter function|No scaling or<br>scale-down|Scale-down of<br>captured display|Desired scaling factor from 1/16<br>to 1 (scaled-down display must<br>not exceed VGA)|
||Low-pass filter||Removal of high-frequency<br>components<br>Only in the horizontal direction|

## **Table 36.2 Main Functions of CEU and Their Details**

|**Main Function**|**Detailed Description**|
|---|---|
|Image data fetch|Captures an image output from an external module and writes YCbCr data to the memory with it|
||separated into Y data and CbCr data.|
||Fetches image data other than YCbCr data, e.g. JPEG data, from an externally connected module,|
||such as a camera, and sequentially writes the image data to the memory.|
||Fetches an interlace source image in both-field units or one-field units and writes it to the memory. In|
||both-field capture, an image can be stored in the memory as a frame image.|
|Filter processing|Performs scale-down and removal of high-frequency components (only in the horizontal direction) for|
||an image using internal filters.|
||Note that the scaled-down image must not exceed VGA. The filter processing can be applied to only|
||YCbCr input data.|
|Format conversion|Converts image data input in the YCbCr422 format into the YCbCr420 format and writes it to the|
||memory.|
||Note that the conversion algorithm is simple skipping in which the chrominance component (CbCr) of|
||the even-numbered lines is skipped.|

Figure 36.1 shows a block diagram of the CEU.

**==> picture [389 x 101] intentionally omitted <==**

**----- Start of picture text -----**<br>
Capture  Filter  Data Write  Bus-bridge<br>Camera interface  block  arrangement  buffer  interface<br>block  (FLB) block  block  block<br>(CIB) (DAB) (WBB) (BIB) Bus<br>bridge<br>Register block (RGB)<br>**----- End of picture text -----**<br>

## **Figure 36.1 Block Diagram of CEU**

## 36.3 Pin Configuration of CEU

The pin configuration of the CEU is shown in Table 36.3 .

## **Table 36.3 Pin Configuration of CEU**

|**Pin Name**|**Function**|**I/O**|**Description**|
|---|---|---|---|
|VIO_D7 to VIO_D0*|CEU data bus|Input|Camera image data input to the CEU|
|VIO_CLK|CEU clock|Input|Camera clock input to the CEU|
|VIO_VD|CEU vertical sync|Input|Camera vertical sync signal input to the CEU|
|VIO_HD|CEU horizontal sync|Input|Camera horizontal sync signal input to the CEU|
|VIO_FLD|Field signal|Input|Field identification signal to the CEU|

Note: * When the distinction according to the bus width for the data bus is not needed, VIO_D is used in this manual. Otherwise, VIO_D7 to VIO_D0 are used.

## 36.4 Register Descriptions of CEU

The register configuration of the CEU is shown in Table 36.4 .

Most CEU registers have a 2-plane configuration (plane A and plane B). The CEU switches the planes when using these 2-plane registers. A mirror address, which is an address that can always access the register on the unused plane, is provided for each 2-plane register. Figure 36.2 shows the timing to switch the register planes. The CEU switches the register planes at the same time a VD interrupt is asserted.

In the following register descriptions, "during operation" indicates the period that begins when the CEU is activated by the CE bit in the capture start register (CAPSR) and ends when a capture end interrupt (CPE) of the capture event flag clear register (CETCR) occurs. In the read-only bits in each register, the write value should always be 0. If a value other than 0 is written to any of these bits, correct operation cannot be guaranteed.

**Table 36.4 Register Configuration of CEU**

|**Table 36.4**<br>**Register Configuration of CEU**||
|---|---|
|**Register Name**<br>**Abbr.**<br>**R/W**|**Addresses**<br>**Access**<br>**Size**<br>**Address**<br>**(Plane A)**<br>**Address**<br>**(Plane B)**<br>**Mirror**<br>**Address**|
|CEU Capture start register<br>CAPSR<br>R/W|H'E821 0000<br>—<br>—<br>32|
|CEU Capture control register<br>CAPCR<br>R/W|H'E821 0004<br>—<br>—<br>32|
|CEU Capture interface control register*<br>CAMCR<br>R/W|H'E821 0008<br>—<br>—<br>32|
|CEU Capture interface cycle register*<br>CMCYR<br>R/W|H'E821 000C<br>—<br>—<br>32|
|CEU Capture interface offset register<br>CAMOR<br>R/W|H'E821 0010<br>H'E821 1010<br>H'E821 2010<br>32|
|CEU Capture interface width register<br>CAPWR<br>R/W|H'E821 0014<br>H'E821 1014<br>H'E821 2014<br>32|
|CEU Capture interface input format register<br>CAIFR<br>R/W|H'E821 0018<br>—<br>—<br>32|
|CEU register control register<br>CRCNTR<br>R/W|H'E821 0028<br>—<br>—<br>32|
|CEU register forcible control register<br>CRCMPR<br>R/W|H'E821 002C<br>—<br>—<br>32|
|CEU Capture filter control register<br>CFLCR<br>R/W|H'E821 0030<br>H'E821 1030<br>H'E821 2030<br>32|
|CEU Capture filter size clip register<br>CFSZR<br>R/W|H'E821 0034<br>H'E821 1034<br>H'E821 2034<br>32|
|CEU Capture destination width register<br>CDWDR<br>R/W|H'E821 0038<br>H'E821 1038<br>H'E821 2038<br>32|
|CEU Capture data address Y register<br>CDAYR<br>R/W|H'E821 003C<br>H'E821 103C<br>H'E821 203C<br>32|
|CEU Capture data address C register<br>CDACR<br>R/W|H'E821 0040<br>H'E821 1040<br>H'E821 2040<br>32|
|CEU Capture data bottom-field address Y<br>register<br>CDBYR<br>R/W|H'E821 0044<br>H'E821 1044<br>H'E821 2044<br>32|
|CEU Capture data bottom-field address C<br>register<br>CDBCR<br>R/W|H'E821 0048<br>H'E821 1048<br>H'E821 2048<br>32|
|CEU Capture bundle destination size register<br>CBDSR<br>R/W|H'E821 004C<br>H'E821 104C<br>H'E821 204C<br>32|
|CEU Firewall operation control register<br>CFWCR<br>R/W|H'E821 005C<br>—<br>—<br>32|
|CEU Capture low-pass filter control register<br>CLFCR<br>R/W|H'E821 0060<br>H'E821 1060<br>H'E821 2060<br>32|
|CEU Capture data output control register<br>CDOCR<br>R/W|H'E821 0064<br>H'E821 1064<br>H'E821 2064<br>32|
|CEU Capture event interrupt enable register<br>CEIER<br>R/W|H'E821 0070<br>—<br>—<br>32|
|CEU Capture event flag clear register<br>CETCR<br>R/W|H'E821 0074<br>—<br>—<br>32|
|CEU Capture status register<br>CSTSR<br>R|H'E821 007C<br>—<br>—<br>32|
|CEU Capture data size register<br>CDSSR<br>R/W|H'E821 0084<br>—<br>—<br>32|
|CEU Capture data address Y register 2<br>CDAYR2<br>R/W|H'E821 0090<br>H'E821 1090<br>H'E821 2090<br>32|
|CEU Capture data address C register 2<br>CDACR2<br>R/W|H'E821 0094<br>H'E821 1094<br>H'E821 2094<br>32|
|CEU Capture data bottom-field address Y<br>register 2<br>CDBYR2<br>R/W|H'E821 0098<br>H'E821 1098<br>H'E821 2098<br>32|
|CEU Capture data bottom-field address C<br>register 2<br>CDBCR2<br>R/W|H'E821 009C<br>H'E821 109C<br>H'E821 209C<br>32|

Note: * After changing the setting of a register (CAMCR or CMCYR) that is determined by the external module characteristics, do not start capture until at least 10 external input clock cycles have elapsed.

**==> picture [220 x 108] intentionally omitted <==**

**----- Start of picture text -----**<br>
CAPSR.CE write<br>System clock<br>CAPSR.CE<br>VIO_VD<br>CETCR.VD<br>(VD interrupt)<br>Register plane Plane A Plane B<br>**----- End of picture text -----**<br>

**Figure 36.2 Register Plane Switching Timing (VD Polarity is High-Active in Data Enable Fetch Mode)**

## 36.4.1 Capture Start Register (CAPSR)

CAPSR captures data input to the CEU from an external module.

||||Bit:|31|30|29||28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—|—|—||—|—|—|—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>CPKIL||
|||Initial|value:|0|0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:|R|R|R||R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W||
||||Bit:|15|14|13||12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
|||||—|—|—||—|—|—|—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>CE||
|||Initial|value:|0|0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:|R|R|R||R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W||
|||||||**Initial**|||||||
|**Bit**|||**Bit**|**Name**||**Value**|||**R/W**||**Description**||
|31|to|17|—|||All 0|||R||Reserved||
||||||||||||These bits are always read as 0. The write value should always be 0.||
|16|||CPKIL|||0|||R/W||Write 1 to this bit to perform a software reset of capturing. At a software||
||||||||||||reset, capturing ends immediately without completing capture operation||
||||||||||||until the end of a frame. Clear the CE bit to 0 when writing 1 to this bit.||
||||||||||||Processing of the capture software reset is indicated by this bit being|set to|
||||||||||||1. When this bit is 1, do not start capturing since reset processing is in||
||||||||||||progress. When restarting capture operations, after referring to the CPTON||
||||||||||||bit in CSTSR to ensure that the CEU is halted (in the idle state), wait|until|
||||||||||||this bit is cleared to 0. The timing of restarting capture operations is shown||
||||||||||||in Figure 36.6.||
||||||||||||When a software reset is generated by this bit, a capture end interrupt (CPE||
||||||||||||bit in CETCR) may be output immediately after the software reset. However,||
||||||||||||such kind of interrupt should be ignored. Also, even if the capture end||
||||||||||||interrupt is not output, the interrupt source (CPE bit) must be cleared before||
||||||||||||capturing of the next frame.||
||||||||||||0: Normal state||
||||||||||||1: Software reset of capturing||
|15|to|1|—|||All 0|||R||Reserved||
||||||||||||These bits are always read as 0. The write value should always be 0.||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|0|CE|0|R/W|Single-capture|
|||||This bit reserves capturing of the next frame. When 1 is written to this|
|||||bit, the capture of one frame starts from the next VD input, and stops|
|||||when the one-frame capture end interrupt (CPE bit in CETCR) is|
|||||asserted (Figure 36.7). To perform capture again, write 1 to this bit. After|
|||||the VD or HD polarity is changed, do not write 1 to this bit until the next|
|||||VD interrupt is asserted.|
|||||As this bit indicates the capture reserve state, this bit is read as 1 after it|
|||||is set to 1 and until VD is input. When VD is input, this bit returns to 0|
|||||and so is read as 0.|
|||||The capture end is determined by the one-frame capture end interrupt|
|||||(CPE bit). This is similar in data fetch mode.|
|||||Registers should be set before the VD interrupt of the frame where|
|||||capture starts next. The new register settings take effect at the next VD|
|||||input. When registers are modified during capturing, the register settings|
|||||take effect from the capture operations of the next VD input. If a setting|
|||||register to which writing during capturing is prohibited is modified during|
|||||capturing, an interrupt source (IGRW bit in CETCR) is generated. For|
|||||details on the interrupt source, see the description on CETCR.|
|||||Continuous capture|
|||||When this bit is set to 1 while the CTNCP bit in CAPCR is set to 1,|
|||||continuous capture starts from the next frame (Figure 36.8). Note that|
|||||this bit is not cleared to 0 but remains as 1. To stop capturing, clear this|
|||||bit to 0; capturing stops after the current frame is completed.|
|||||Continuous capture operations are possible in only image capture mode.|
|||||The start address of the memory to which the captured data is written to|
|||||must be set for each frame.|
|||||0: Stops capturing|
|||||1: Starts capturing|

When both the VD (vertical sync signal) and HD (horizontal sync signal) polarities are high-active, one frame is defined as a period from a VD rising edge to the next VD rising edge, and one line as a period from an HD rising edge to the next HD rising edge. Figure 36.3 shows the timing of one frame (when both the VD and HD polarities are high-active).

VIO_VD One VD period (one frame) VIO_HD One HD period (one line)

## **Figure 36.3 Frame Timing**

When both the VD and HD polarities are high-active, similar to one frame, one field is defined as follows:

- Period from a VD rising edge to the next VD rising edge

- One line is a period from an HD rising edge to the next HD rising edge

The field identification signal FLD should be fixed for at least 1-HD period from a VD input. Figure 36.4 shows the timing of one field (when both the VD and HD polarities are high-active).

**==> picture [388 x 199] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_VD<br>One VD period (one field)<br>VIO_HD<br>One HD period (one line)<br>VIO_FLD<br>Fixed for at least one HD period<br>VIO_VD<br>VIO_HD One HD period (one line)<br>VIO_FLD<br>Fixed for at least one HD period from the VD input<br>**----- End of picture text -----**<br>

**Figure 36.4 One Field Timing**

In data enable fetch (RZ/A1LU and RZ/A1LC only), one frame is defined as a period from a VD rising edge to the VD falling edge. With the HD as an enable signal (positive polarity), data of a cycle in which the HD is asserted is fetched while the VD is high. Figure 36.5 shows the timing of one frame for data enable fetch.

**==> picture [248 x 76] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_VD<br>1 frame<br>VIO_HD<br>Data enabled period (assertion of HD)<br>**----- End of picture text -----**<br>

**Figure 36.5 Frame Timing (Data Enable Fetch)**

**==> picture [326 x 163] intentionally omitted <==**

**----- Start of picture text -----**<br>
CPKIL write<br>VIO_VD<br>VIO_HD<br>CSTSR.CPTON Reset<br>Operating Halted<br>CPKIL write<br>CSTSR.CPTON<br>CAPSR.CPKIL<br>Period in which restart is prohibited Restart is allowed<br>**----- End of picture text -----**<br>

**Figure 36.6 Timing of Software Reset and Restart of Capturing**

**==> picture [241 x 145] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_VD<br>VIO_HD<br>Write Write<br>CAPSR.CE<br>One-frame capture end interrupt<br>CETCR.CPE = 1<br>CSTSR.CPTON<br>Operating Halted<br>Period in which register settings are  Period in which register settings are<br>modified for the next frame modified for the next frame<br>**----- End of picture text -----**<br>

**Figure 36.7 Timing of Modifying CE Bit and Register Setting in One Frame Capture**

**==> picture [248 x 60] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_VD<br>CSTSR.CPTON<br>Register write Register clear<br>CAPSR.CE<br>**----- End of picture text -----**<br>

**Figure 36.8 Continuous-Frame Capture**

## 36.4.2 Capture Control Register (CAPCR)

CAPCR sets continuous-frame capture and the frame drop intervals.

Do not modify this register during operation. If this register is modified during operation, correct operation cannot be guaranteed. In addition, the IGRW bit (interrupt source) in CETCR is set to B'1.

||Bit:|31|30|29|28|27|26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17|16||
|---|---|---|---|---|---|---|---|---|---|
||||||FDRP[7:0]||MTCM[1:0]<br>—<br>—<br>—<br>—<br>—|CTNCP||
||Initial value:|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0||
||R/W:|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R<br>R<br>R/W<br>R/W<br>R<br>R<br>R|R/W||
||Bit:|15|14|13|12|11|10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1|0||
|||—|—|—|—|—|—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—|—||
||Initial value:|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0||
||R/W:|R|R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|R||
||||**Initial**|||||||
|**Bit**|**Bit Name**||**Value**||**R/W**||**Description**|||
|31 to 24|FDRP[7:0]||H'00||R/W||These bits set the frame drop interval in continuous-frame capture.|||
||||||||When these bits are cleared to 0, frame drop is not performed, and|all||
||||||||frames are captured.|||
||||||||Figure 36.9 shows the value set in these bits and the timing of captured|||
||||||||frames.|||
||||||||The frame drop interval unit differs according to the capture setting.|Table||
||||||||36.5 shows the relationship between the capture setting and frame drop|||
||||||||interval unit. The image of the frame drop timing for each capture setting|||
||||||||when these bits are set to 2 is shown in Figure 36.10.|||
||||||||In both-field capture, capturing is performed continuously for 2-VD periods,|||
||||||||regardless of whether the second field is the top field or bottom field. In|||
||||||||addition, in both-field capture, the frame drop counter is incremented when|||
||||||||the first field has been identified as the top field or bottom field, regardless of|||
||||||||whether the second field is the top field or bottom field.|||
||||||||When 0 is written to the CE bit in CAPSR, capturing terminates after the|||
||||||||current frame has been captured for a capture frame. However, for a drop|||
||||||||frame, capturing is forcibly terminated in the CEU so no capture end|||
||||||||interrupt (CPE bit in CETCR) is output.|||
||||||||While CE bit is 1, do not change the setting of these bits.|||
||||||||Note: Do not change the setting of these bits during continuous capture|||
||||||||operations. To change the setting of these bits, stop continuous|||
||||||||capture (CE bit = 0), clear the CTNCP bit (continuous capture) in|||
||||||||CAPCR to 0, and then restart continuous capture. Continuous|||
||||||||capture is performed during the period of CAPSR.CE = 1 shown in|||
||||||||Figure 36.9.|||
|23, 22|—||All|0|R||Reserved|||
||||||||These bits are always read as 0. The write value should always be 0.|||

||||**Initial**|||
|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**|**Description**|
|21,|20|MTCM[1:0]|00|R/W|These bits specify the unit for transferring data to a bus bridge module.|
||||||The efficiency of writing image data can be improved by continuously|
||||||accessing the addresses. To improve the write efficiency, set these bits to|
||||||11. The setting of these bits appear to be unchanged from the outside.|
||||||00: Transferred to the bus in 32-byte units|
||||||01: Transferred to the bus in 64-byte units|
||||||10: Transferred to the bus in 128-byte units|
||||||11: Transferred to the bus in 256-byte units|
||||||(1) Image capture|
||||||00: Y data and C data are transferred in 32-byte units|
||||||01: Y data and C data are transferred in 64-byte units|
||||||10: Y data and C data are transferred in 128-byte units|
||||||11: Y data and C data are transferred in 256-byte units|
||||||(2) Data fetch|
||||||00: Data is transferred in 32-byte units|
||||||01: Data is transferred in 64-byte units|
||||||10: Data is transferred in 128-byte units|
||||||11: Data is transferred in 256-byte units|
|19|to 17|—|All 0|R|Reserved|
||||||These bits are always read as 0. The write value should always be 0.|
|16||CTNCP|0|R/W|When capturing is started with this bit set to 1, capturing continues until the|
||||||CE bit in CAPSR is cleared to 0 or a software reset is initiated by the CPKIL|
||||||bit in CAPSR (see Figure 36.8). Continuous capture must be set before|
||||||capturing is started.|
||||||This bit is modified only after 0 is written to the CE bit to stop capturing. If|
||||||this bit is modified during capturing, correct operation cannot be|
||||||guaranteed.|
||||||In data fetch mode, clear this bit to 0.|
||||||0: One-frame capture when the CE bit is 1|
||||||1: Continuous capture until the CE bit is cleared to 0|
|15|to 0|—|All 0|R|Reserved|
||||||These bits are always read as 0. The write value should always be 0.|

||Write: CAPSR.CE = 1|Write: CAPSR.CE = 1|||Write: CAPSR.CE = 0|Write: CAPSR.CE = 0|Write: CAPSR.CE = 0|
|---|---|---|---|---|---|---|---|
|VIO_VD||||||||
|CAPTURE_STATE|IDLE||DROP|DROP<br>DROP<br>DROP<br>DROP|||IDLE|
|||CAPTURE|||CAPTURE|||
|Frame No.||0|1|2<br>n|n+1<br>n+2<br>n+3|||
|CAPSR.CE||||||||
|||||FDRP||||

**Figure 36.9 Setting of FDRP Bits and Frame Drop Timing**

**Table 36.5 Relationship between Capture Setting and Frame Drop Interval Unit**

|**Input Mode**|**Captured Image**|**First Captured Image**<br>**Frame Drop Interval Unit**|**Capture**<br>**Setting**|
|---|---|---|---|
|Progressive|Frame|Frame immediately after capture<br>start<br>Frame|A|
|Interlace|Both-field<br>(2-VD capture)|Field immediately after capture start<br>2 fields (first capture field count)|B|
||||C|
|||Top field<br>2 fields (top-field count)|D|
|||Bottom field<br>2 fields (bottom-field count)|E|
||One-field<br>(1-VD capture)|Field immediately after capture start<br>First capture field|F|
||||G|
|||Top field<br>Top field|H|
|||Bottom field<br>Bottom field|I|

|VIO_VD|VIO_VD|VIO_VD||||||||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||A|F||F|||F|F|F|F|F|F|F|F|F|F|F|F|F|F|F|F|F|F|
|Capture setting||B<br>C<br>D<br>E<br>F<br>G|tf<br>bf<br>bf<br>tf<br>tf<br>bf||bf<br>tf<br>tf<br>bf<br>bf<br>tf|<br> <br> <br>||tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|tf<br>bf<br>bf<br>tf<br>tf<br>bf|bf<br>tf<br>tf<br>bf<br>bf<br>tf|
|||H|bf||tf|||bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|
|||I|tf||bf|||tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|tf|bf|
|Note:  FDRP =|||||2|||||||||||||||||||||
|[Legend]||||||||||||||||||||||||||
|||: Capture||||F:||Frame||||||||||||||||||
|||: Drop||||tf:||Top field||||||||||||||||||
|||||||bf:||Bottom field||||||||||||||||||

**Figure 36.10 Image of Frame Drop Timing for Capture Settings (FDRP Bits = 2)**

## 36.4.3 Capture Interface Control Register (CAMCR)

CAMCR sets the capture interface.

The following items are set by CAMCR.

- Selection between the rising edge or falling edge of the camera clock for signal capture or data fetch operation (RZ/ A1LU and RZ/A1LC only)

- Selection between image capture operation or data fetch operation

- Polarities of the vertical and horizontal sync signals

- Input order of image data components (Y, Cb, and Cr) (only for image capture mode)

- Selection of digital image input pins (8 bits only)

- Polarity of the field identification signal

CAMCR must be set according to the module connected. In data fetch mode, set the DTARY bits to B'0. Do not modify this register during operation. If this register is modified during operation, correct operation cannot be guaranteed. In addition, the IGRW bit (interrupt source) in CETCR is set to B'1.

Note: After changing the setting of this register, do not start capture until at least 10 external input clock cycles have elapsed.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|VDSEL*|HDSEL*|FLDSEL*|DSEL*|—|—|—|—|—|—|—|FLDPOL|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R/W|R/W|R/W|R/W|R|R|R|R|R|R|R|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|DTIF|—|—|DTARY[1:0]||—|—|JPG[1:0]||—|—|VDPOL|HDPOL|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R/W|R|R|R/W|R/W|R|R|R/W|R/W|R|R|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|28|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|27|||VDSEL*|0|R/W|Sets the edge for capturing the vertical sync signal (VD) from an external|
|||||||module.|
|||||||0: VD is captured at the rising edge of the camera clock.|
|||||||1: VD is captured at the falling edge of the camera clock.|
|26|||HDSEL*|0|R/W|Sets the edge for capturing the horizontal sync signal (HD) from an external|
|||||||module.|
|||||||0: HD is captured at the rising edge of the camera clock.|
|||||||1: HD is captured at the falling edge of the camera clock.|
|25|||FLDSEL*|0|R/W|Sets the edge for capturing the field identification signal (FLD) from an|
|||||||external module.|
|||||||0: FLD is captured at the rising edge of the camera clock.|
|||||||1: FLD is captured at the falling edge of the camera clock.|
|24|||DSEL*|0|R/W|Sets the edge for fetching the image data (D7 to D0) from an external|
|||||||module.|
|||||||0: D7 to D0 are fetched at the rising edge of the camera clock.|
|||||||1: D7 to D0 are fetched at the falling edge of the camera clock.|
|23|to|17|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|16|FLDPOL|0|R/W|Sets the polarity of the field identification signal (FLD) from an external|
|||||module.|
|||||0: When the FLD signal is high-active, the field is detected as the top field|
|||||and when low-active, the field is detected as the bottom field.|
|||||1: When the FLD signal is low-active, the field is detected as the top field|
|||||and when high-active, the field is detected as the bottom field.|
|15 to 13|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|12|DTIF|0|R/W|Sets the digital image input pins from which data is to be captured.|
|||||The write value should always be 0.|
|11, 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9, 8|DTARY[1:0]|00|R/W|These bits set the input order of the luminance component and|
|||||chrominance component.|
|||||The order in which the luminance component (Y) and chrominance|
|||||component (Cb and Cr) are input from an external module differs among|
|||||modules. The CEU supports the input orders shown in Figure 36.12. Set the|
|||||corresponding value in these bits. In data fetch mode, set these bits to 00.|
|||||00: Image input data is fetched in the order of Cb0, Y0, Cr0, and Y1|
|||||01: Image input data is fetched in the order of Cr0, Y0, Cb0, and Y1|
|||||10: Image input data is fetched in the order of Y0, Cb0, Y1, and Cr0|
|||||11: Image input data is fetched in the order of Y0, Cr0, Y1, and Cb0|
|7, 6|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|5, 4|JPG[1:0]|00|R/W|These bits select the fetched data type.|
|||||00: Image capture mode|
|||||(input data are separated into Y data and CbCr data for output to the|
|||||memory)|
|||||01: Data synchronous fetch mode|
|||||(specified size of input data are output to the specified memory|
|||||addresses in order of input and in synchronization with the sync signal)|
|||||10: Data enable fetch mode (RZ/A1LU and RZ/A1LC only)|
|||||(input data are fetched with HD as an enable signal and output to the|
|||||specified addresses in memory in order of input)|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1|VDPOL|0|R/W|Sets the polarity for detection of the vertical sync signal input from an|
|||||external module.|
|||||Figure 36.14 and Figure 36.15 show the relationship between the VIO_VD|
|||||and VIO_HD signals and VD interrupt when high-active is selected.|
|||||Since a VD interrupt may occur when this bit value is modified, the VD bit in|
|||||CETCR must always be cleared to 0 when this bit value is changed. In data|
|||||enable fetch mode, this bit is not used and the sense for detection is always|
|||||active high.|
|||||0: Vertical sync signal (VD) from an external module is detected as high-|
|||||active|
|||||1: Vertical sync signal (VD) from an external module is detected as low-|
|||||active|
|0|HDPOL|0|R/W|Sets the polarity for detection of the horizontal sync signal input from an|
|||||external module.|
|||||Figure 36.16 shows the relationship between the HD and HD interrupt when|
|||||high-active is selected.|
|||||Since an HD interrupt may occur when this bit value is modified, the HD bit|
|||||in CETCR must always be cleared to 0 when this bit value is changed.|
|||||0: Horizontal sync signal (HD) from an external module is detected as high-|
|||||active|
|||||1: Horizontal sync signal (HD) from an external module is detected as low-|
|||||active|

Note: * This bit is only present in the RZ/A1LU and RZ/A1LC. This is reserved in the RZ/A1L.

**==> picture [353 x 97] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_CLK<br>VIO_HD<br>Cb Y Cr Y Cb Y Cr Y CAMCR.DTARY = 0<br>Cr Y Cb Y Cr Y Cb Y CAMCR.DTARY = 1<br>VIO_D7 to VIO_D0<br>Y Cb Y Cr Y Cb Y Cr CAMCR.DTARY = 2<br>Y Cr Y Cb Y Cr Y Cb CAMCR.DTARY = 3<br>**----- End of picture text -----**<br>

**Figure 36.11 Input Order of Image Data**

The JPG bit in CAMCR selects whether digital image data is fetched or data such as JPEG is fetched. In addition, when data such as JPEG is fetched, select whether the specified amount of data is continuously fetched in synchronization with the sync signal or data is fetched while the horizontal sync signal is enabled  (RZ/A1LU and RZ/A1LC only).

In data enable fetch mode, one frame is defined as a period from the rising edge to the falling edge of the vertical sync signal (VD) for data fetching. The horizontal sync signal (HD) is enabled only when the VD is high and treated as an enable signal. Data input in the cycle in which the HD is asserted (high) is fetched and output to the memory continuously.

This module starts fetching data at the rising edge of the VD and stops fetching data at the falling edge of the VD in data enable fetch mode. Thus, if the VD remains high and does not go low, end processing does not start. In addition, if the VD remains high and the HD also remains asserted, data continues to be fetched.

Figure 36.12 and Figure 36.13 show the interface timing in data enable fetch mode.

**==> picture [186 x 79] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_CLK<br>VIO_VD<br>VIO_HD<br>VIO_D<br> : Invalid<br>**----- End of picture text -----**<br>

**Figure 36.12 Data Enable Fetch Timing (HD Asserted (High) While VD is High)**

**==> picture [185 x 79] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_CLK<br>VIO_VD<br>VIO_HD<br>VIO_D<br> : Invalid<br>**----- End of picture text -----**<br>

**Figure 36.13 Data Enable Fetch Timing (HD Asserted (High) When VD is Not High)**

In data enable fetch mode, this module generates a VD interrupt in response to detection of the active level of VD. In image capture mode and data synchronous fetch mode, this module generates a VD interrupt in response to the first detection of the active level of HD following detection of the active level of VD. Note that, when VD and HD are asserted and detected at the same time, this module generates a VD interrupt at that time.

Figures 36.14 to 36.16 show the relationships between the VIO_VD signal and the VD interrupt, the VIO_VD and VIO_HD signals and the VD interrupt, and the VIO_HD signal and the HD interrupt.

**==> picture [265 x 71] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_VD<br>VD edge detection<br>VD interrupt<br>Clear Clear<br>**----- End of picture text -----**<br>

**Figure 36.14 Relationship between VIO_VD and VD Interrupt when VD is High-Active (In Data Enable Fetch Mode)**

**==> picture [308 x 91] intentionally omitted <==**

**----- Start of picture text -----**<br>
VD<br>VD edge detection<br>HD<br>HD edge detection<br>VD interrupt<br>Clear<br>**----- End of picture text -----**<br>

**Figure 36.15 Relationship between the VIO_VD and VIO_HD signals and the VD Interrupt when VD and HD are High-Active (in Image Capture Mode or Data Synchronous Fetch Mode)**

**==> picture [265 x 71] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_HD<br>HD edge detection<br>HD interrupt<br>Clear Clear<br>**----- End of picture text -----**<br>

**Figure 36.16 Relationship between VIO_HD and HD Interrupt when HD is High-Active**

## 36.4.4 Capture Interface Cycle Register (CMCYR)

CMCYR is used to detect an illegal VD and an illegal HD. For HD, the number of cycles from a rising edge of HD to the next rising edge is set (falling edges when low-active is selected for HD). For VD, the number of HD inputs from a rising edge of VD to the next rising edge is set (falling edges when low-active is selected for VD).

Do not modify this register during operation. If this register is modified during operation, correct operation cannot be guaranteed. In addition, the IGRW bit (interrupt source) in CETCR is set to B'1.

Set 0 in all bits of this register, during data enable fetch mode.

Note: After changing the setting of this register, do not start capture until at least 10 external input clock cycles have elapsed.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|||||||VCYL[13:0]||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||—|—|||||||HCYL[13:0]||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31, 30|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|29 to 16|VCYL[13:0]|H'0000|R/W|Vertical HD Count of External Module|
|||||These bits set the number of VD cycles of an external module with the|
|||||number of HD inputs. The interrupt source bit IGVS in CETCR is set to 1|
|||||when the actual number of VD cycles input from the external module differs|
|||||from this setting. Set these bits for detecting an illegal VD.|
|||||When these bits are all cleared to 0, the interrupt source bit IGVS in CETCR|
|||||is not set to 1. Though the interrupt source bit IGVS in CETCR may be set to|
|||||1 after the VDPOL bit (VD polarity) in CAMCR is changed, this interrupt|
|||||should be ignored.|
|15, 14|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|13 to 0|HCYL[13:0]|H'0000|R/W|Horizontal Cycle Count of External Module|
|||||These bits set the number of HD cycles of an external module. The interrupt|
|||||source bit IGHS in CETCR is set to 1 when the actual number of HD cycles|
|||||input from the external module differs from this setting. Set these bits for|
|||||detecting an illegal HD.|
|||||When these bits are all cleared to 0, the interrupt source bit IGHS in CETCR|
|||||is not set to 1. Though the interrupt source bit IGHS in CETCR may be set|
|||||to 1 after the HDPOL bit (HD polarity) in CAMCR is changed, this interrupt|
|||||should be ignored.|

## 36.4.5 Capture Interface Offset Register (CAMOR)

CAMOR sets the location to start capturing when capturing images.

Since the number of HD (horizontal sync signal) inputs from a VD (vertical sync signal) input to the start of a valid image period, and the number of clock cycles from an HD input to the start of a valid image period differ among external modules, these must be set in CAMOR. By setting a value greater than the valid image area, part of the image can be clipped for capture. When fetching data, the setting of this register becomes the number of cycles (HD count) up to the start of a valid data period.

This register is not used, during data enable fetch mode.

||||Bit:|31||30||29|28|27|26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—||—||—|—||VOFST[11:0]||
|||Initial|value:|0||0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:|R||R||R|R|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
||||Bit:|15||14||13|12|11|10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
|||||—||—||—|||HOFST[12:0]||
|||Initial|value:|0||0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:|R||R||R|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
||||||||**Initial**||||||
|**Bit**|||**Bit Name**||||**Value**||**R/W**||**Description**||
|31|to|28|—||||All 0||R||Reserved||
||||||||||||These bits are always read as 0. The write value should always be 0.||
|27|to|16|VOFST[11:0]||||H'000||R/W||These bits specify the capture start location in terms of the HD count from a vertical||
||||||||||||sync signal (1-HD units).||
||||||||||||The blanking period from a vertical sync signal differs among external modules.||
||||||||||||Therefore, the vertical capture start location must be specified by these bits in||
||||||||||||terms of the HD count from a vertical sync signal so that an image can be captured||
||||||||||||from the valid image area (see Figure 36.17). Some external modules output a||
||||||||||||vertical sync signal as a data enable signal. In this case, there is no blanking period||
||||||||||||so these bits must be cleared to 0 (see Figure 36.18).||
|15|to|13|—||||All 0||R||Reserved||
||||||||||||These bits are always read as 0. The write value should always be 0.||
|12|to|0|HOFST[12:0]||||H'0000||R/W||These bits specify the capture start location in terms of the number of clock cycles||
||||||||||||from a horizontal sync signal (1-cycle units).||
||||||||||||The blanking period from a horizontal sync signal differs among external modules.||
||||||||||||Therefore, the horizontal capture start location must be specified by these bits in||
||||||||||||terms of external input clock cycles from a horizontal sync signal so that an image||
||||||||||||can be captured from the valid image area. This is similar in data synchronous fetch||
||||||||||||mode (see Figure 36.19). Some external modules output a horizontal sync signal||
||||||||||||as a data enable signal. In this case, there is no blanking period so these bits must||
||||||||||||be cleared to 0 (see Figure 36.20).||
||||||||||||Note: The first HD (horizontal sync signal) being input simultaneously or after the||
||||||||||||first VD (vertical sync signal) is the operating condition of the CEU. These||
||||||||||||inputs are affected by the polarities (set by the VDPOL and HDPOL bits in||
||||||||||||CAMCR).||

|VIO_VD<br>VIO_HD<br>VIO_D7 to VIO_D0||VOFST<br>blank<br>blank<br>H0<br>H1<br>Hn-1<br>Hn<br>blank<br>blank<br>blank|
|---|---|---|
||blank||
|**Figure 36.17**<br>**Vertical Offset**|||
|VIO_VD<br>VIO_HD<br>VIO_D7 to VIO_D0<br>VOFST = 0<br>H0||H2<br>H3<br>H1<br>Hn-1<br>Hn<br>blank<br>blank<br>blank<br>blank<br>blank|
|**Figure 36.18**<br>**Timing when VD**||**is Data Enable Signal**|
|VIO_CLK<br>VIO_HD<br>VIO_D7 to VIO_D0||HOFST<br>blank blank blank<br>blank<br>blank blank blank<br>Cb0<br>Y0<br>Cr0<br>Y1<br>Cb2<br>Y2|

**Figure 36.19 Horizontal Offset**

|HOFST = 0<br>blank blank blank blank blank blank<br>Cb0<br>Y0<br>Cr0<br>Y1<br>Cr2<br>Y3<br>Cb2<br>Y2<br>VIO_CLK<br>VIO_HD<br>VIO_D7 to VIO_D0||||||||||||||||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||||||||||||||||||
|||||Y0||||Y1||Cb2||||||||||blank||blank||||||blank||||

**Figure 36.20 Timing when HD is Data Enable Signal (8-bit Interface)**

## 36.4.6 Capture Interface Width Register (CAPWR)

CAPWR sets the fetch (capture) cycle width when capturing images.

The cycle width unit differs according to the interface and the data type to be captured. For each setting unit, see Table 36.6 .

|||Bit:|31|30|29||28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|
||||—|—|—||—|||VWDTH[11:0]||
||Initial|value:|0|0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R|R|R||R|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R||
|||Bit:|15|14|13||12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||
||||—|—|—|||||HWDTH[12:0]||
||Initial|value:|0|0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R|R|R||R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R||
|||||||**Initial**||||||
|**Bit**||**Bit**|**Name**|||**Value**|||**R/W**|**Description**||
|31 to 28||—||||All 0|||R|Reserved||
|||||||||||These bits are always read as 0. The write value should always be|0.|
|27 to 18||VWDTH[11:2]||||H'000|||R/W|These bits specify the vertical capture period (4-HD units).||
|17,|16|VWDTH[1:0]|||||||R|These bits specify the number of lines (HD count) to be captured from the||
|||||||||||location specified by the VOFST bits in CAMOR. Figure 36.21 shows the||
|||||||||||timing when the vertical blanking period is 0. The CEU captures only the||
|||||||||||number of lines (HD count) specified by these bits in the vertical direction.||
|||||||||||Make a setting in the same way to obtain data synchronization.||
|||||||||||The maximum value to be set is 1,920 HD (5 megapixels).||
|15 to 13||—||||All 0|||R|Reserved||
|||||||||||These bits are always read as 0. The write value should always be|0.|
|12 to 1||HWDTH[12:1]||||H'0000|||R/W|These bits specify the horizontal capture period.||
|0||HWDTH[0]|||||||R|These bits specify the number of cycles to be captured from the location||
|||||||||||specified by the HOFST bits. Figure 36.22 shows the timing when the||
|||||||||||horizontal blanking period is 0. The CEU captures for only the number of||
|||||||||||cycles specified by these bits in the horizontal direction. Make a similar||
|||||||||||setting for data synchronous fetch.||
|||||||||||The maximum value to be set is as follows:||
|||||||||||Image capture (8-cycle units*1)||
|||||||||||: 5,120 cycles (2,560 pixels)||
|||||||||||Data synchronous fetch (4-cycle units*2)||
|||||||||||: 2,560 cycles (2,560 bytes)||
|||||||||||Note: In data synchronous fetch mode, set CFSZR and CDWDR||
|||||||||||according to the values set in this register. For details, see the||
|||||||||||descriptions on CFSZR and CDWDR.||
|||||||||||Note 1. 16-cycle units when writing to other than the on-chip RAM||
|||||||||||Note 2. 8-cycle units when writing to other than the on-chip RAM||

**Table 36.6 Unit for Setting Fetch (Capture) Cycle Width**

|**Interface**|**Vertical Direction**<br>**Horizontal Direction**<br>**Image Capture**<br>**Data Synchronous**<br>**Fetch**<br>**Image Capture**<br>**Data Synchronous**<br>**Fetch**|
|---|---|
|8-bit interface|4 HD<br>4 HD<br>8 cycles*1<br>4 cycles*2|

Note 1. 16 cycles when writing to other than the on-chip RAM Note 2. 8 cycles when writing to other than the on-chip RAM

**==> picture [393 x 82] intentionally omitted <==**

**----- Start of picture text -----**<br>
VWDTH<br>VIO_VD<br>VIO_HD 1H 2H 3H<br>VIO_D7 to VIO_D0 valid valid valid valid valid valid valid blank blank blank blank<br>VOFST = 0<br>**----- End of picture text -----**<br>

**Figure 36.21 Vertical Capture Timing**

**==> picture [296 x 78] intentionally omitted <==**

**----- Start of picture text -----**<br>
HWDTH<br>VIO_CLK<br>VIO_HD<br>VIO_D7 to VIO_D0 Cb0 Y0 Cr0 Y1 Cb2 Yn-1 Crn-1 Yn blank blank blank<br>HOFST = 0<br>**----- End of picture text -----**<br>

**Figure 36.22 Horizontal Capture Timing (Image Capture with 8-bit Interface)**

## 36.4.7 Capture Interface Input Format Register (CAIFR)

CAIFR sets the input mode (progressive or interlace) for capturing images, the images to be captured (frame, both-field, or one-field), and the image from which capturing starts (top field, bottom field, etc.). CAIFR is not used in data fetch mode.

Do not modify this register during operation. If this register is modified during operation, correct operation cannot be guaranteed. In addition, the IGRW bit (interrupt source) in CETCR is set to B'1.

The items set by CAIFR are listed in Table 36.7 .

||Bit:|31|30|29|29|28||27|26<br>25<br>24<br>23<br>22<br>21|20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—||—||—|—<br>—<br>—<br>—<br>—<br>—|—<br>—|—|—|—||
|Initial|value:|0|0||0|0||0|0<br>0<br>0<br>0<br>0<br>0|0<br>0|0|0|0||
||R/W:|R|R|R||R||R|R<br>R<br>R<br>R<br>R<br>R|R<br>R|R|R|R||
||Bit:|15|14|13||12||11|10<br>9<br>8<br>7<br>6<br>5|4<br>3|2|1|0||
|||—|—|—||—||—|—<br>—<br>IFS<br>—<br>—<br>—|CIM<br>—|—|FCI[1:0]|||
|Initial|value:|0|0||0|0||0|0<br>0<br>0<br>0<br>0<br>0|0<br>0|0|0|0||
||R/W:|R|R|R||R||R|R<br>R<br>R/W<br>R<br>R<br>R|R/W<br>R|R|R/W|R/W||
|||||**Initial**|||||||||||
|**Bit**|**Bit**|**Name**||**Value**||**R/W**|||**Description**||||||
|31 to 9|—|||All|0|R|||Reserved||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||
|8|IFS|||0||R/W|||Sets the input mode for capturing images.||||||
||||||||||0: Progressive||||||
||||||||||1: Interlace||||||
|7 to 5|—|||All|0|R|||Reserved||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||
|4|CIM|||0||R/W|||Sets the images to be captured.||||||
||||||||||Clear this bit to 0 when the input mode for image capture is progressive (frame||||||
||||||||||image) or when the input mode for image|capture is interlace for continuous|||||
||||||||||capture of both the top and bottom fields.|Set this bit to|1 when the input mode for||||
||||||||||image capture is interlace for capture of only a one-field image.||||||
||||||||||0: Capture of frame image (1 VD) or both-field image (2 VD)||||||
||||||||||1: Capture of one-field image (1 VD)||||||
|3, 2|—|||All|0|R|||Reserved||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||
|1, 0|FCI[1:0]|||00||R/W|||These bits set the timing to start capturing.||||||
||||||||||The timing to start capturing is set by specifying the image to be captured first.||||||
||||||||||Set these bits to 00 when the input mode|is progressive.|||||
||||||||||00: Capture starts from the VD input immediately after the CEU activation||||||
||||||||||regardless of it being a top or bottom field||||||
||||||||||01: After the CEU activation, input of a top-field image is waited, and||||then capture||
||||||||||starts from the top field||||||
||||||||||10: After the CEU activation, input of a bottom-field image is waited, and then||||||
||||||||||capture starts from the bottom field||||||
||||||||||11: Setting prohibited||||||

## **Table 36.7 CAIFR Setting Items**

|**Input Mode**<br>**IFS Bit**|**Captured Image**<br>**CIM Bit**|**Image to Start Capture**<br>**FCI Bits**|
|---|---|---|
|Progressive<br>0|Frame<br>0|Frame immediately after activation<br>00|
|Interlace<br>1|Both-field (2-VD capture)<br>0|Field immediately after activation<br>00|
|||Top field<br>01|
|||Bottom field<br>10|
|||Setting prohibited<br>11|
||One-field (1-VD capture)<br>1|Field immediately after activation<br>00|
|||Top field<br>01|
|||Bottom field<br>10|
|||Setting prohibited<br>11|

In frame image capture and one-field image capture, a one-frame capture end interrupt occurs when capture for 1 VD finishes. In both-field image capture, a one-field capture end interrupt occurs when capture for 1 VD finishes and a oneframe capture end interrupt occurs when capture for 2 VD finishes. At this time, a one-field capture end interrupt occurs simultaneously with a one-frame capture end interrupt. Figure 36.24 shows the timing of a one-frame capture end interrupt and one-field capture end interrupt in both-field image capture.

**==> picture [262 x 224] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_VD<br>VIO_HD<br>VIO_FLD<br>Write<br>CAPSR.CE<br>End of top  End of bottom<br>field capture field capture<br>CSTSR.CPTON<br>One-field<br>capture end<br>interrupt<br>CETCR.CFE<br>Clear<br>One-frame<br>capture end<br>interrupt<br>CETCR.CPE Capture period Capture period<br>of one field of one field<br>Capture period of both fields<br>**----- End of picture text -----**<br>

**Figure 36.23 One-Frame Capture End Interrupt and One-Field Capture End Interrupt in Both-Field Image Capture**

A captured frame image or captured one-field image is stored in the memory from the addresses set in CDAYR and CDACR ( Figure 36.24 ). Captured both-field images are stored in different memory areas depending on whether it is a top-field or bottom-field image. A top-field image is stored in the memory from the addresses set in CDAYR and CDACR whereas a bottom-field image is stored in the memory from the addresses set in CDBYR and CDBCR ( Figure 36.25 ).

**==> picture [281 x 116] intentionally omitted <==**

**----- Start of picture text -----**<br>
CDAYR, CDACR CDWDR<br>CEU source image<br>Memory image<br>**----- End of picture text -----**<br>

**Figure 36.24 Image of Storing Captured Frame Image or Captured One-Field Image in Memory**

**==> picture [296 x 162] intentionally omitted <==**

**----- Start of picture text -----**<br>
CEU top-field source image CDAYR, CDACR<br>CDBYR, CDBCR CDWDR<br>Memory image<br>CEU bottom-field source image<br>**----- End of picture text -----**<br>

**Figure 36.25 Image of Storing Captured Both-Field Images in Memory**

If the FCI bits are set to B'00 for continuous capture in interlace input mode, images are continuously captured for 2 VD with the first captured field as the reference in both-field image capture ( Figure 36.26 ). In one-field image capture, only the first captured field is continuously captured for 1 VD ( Figure 36.27 ).

VIO_VD VIO_D7 tf bf tf bf tf bf tf bf tf bf tf bf tf bf tf bf tf bf tf bf to VIO_D0 [Legend] : Capture tf: Top field bf: Bottom field

**Figure 36.26 Continuous Both-Field Capture in Interlace Mode (Image Immediately after Activation is Top Field (FCI Bits = B'00))**

VIO_VD VIO_D7 tf bf tf bf tf bf tf bf tf bf tf bf tf bf tf bf tf bf tf bf to VIO_D0 [Legend] : Capture tf: Top field bf: Bottom field

**Figure 36.27 Continuous One-Field Capture in Interlace Mode (Image Immediately after Activation is Top Field (FCI Bits = B'00))**

## (1) Storage of Interlace Input as Frame Image

The CEU can store an interlace source image in the memory as a frame image. To store an interlace source image as a frame image, make the following register settings:

Input mode: Interlace (IFS bit = B'1)

Capture image: Both-field (CIM bit = B'0)

Image to start capture: Any setting other than the prohibited setting (FCI bits = as desired)

Figure 36.28 shows a memory image of capturing both fields of an interlace input and storing it as a frame image in the memory. Set the start addresses of the memory destination for the captured top-field image in CDAYR and CDACR, and the start addresses of the memory destination for the captured bottom-field image in CDBYR and CDBCR. When storing an interlace image as a frame image in the memory, set the horizontal image size of the memory area in CDWDR with the top-field image and bottom-field image placed next to each other as shown in Figure 36.28 . In addition, set the number of captured lines of the field image in the VWDTH bits in CAPWR.

A memory image of folding the horizontal image size of the memory area in Figure 36.28 at CDWDR/2 is shown in Figure 36.29 . Setting the registers to form the image in Figure 36.28 enables an interlace image to be stored as a frame image in the memory as shown in Figure 36.29 .

**==> picture [377 x 162] intentionally omitted <==**

**----- Start of picture text -----**<br>
CEU top-field source image CDAYR, CDACR CDBYR, CDBCR<br>CDWDR<br>Memory image<br>CAPWR.VWDTH<br>CDWDR/2<br>CEU bottom-field source image<br>**----- End of picture text -----**<br>

**Figure 36.28 Image of Storing Captured Both-Fields of Interlace Input in Memory**

**==> picture [223 x 115] intentionally omitted <==**

**----- Start of picture text -----**<br>
CDAYR, CDACR CDWDR/2<br>Memory image<br>CDBYR, CDBCR<br>CAPWR.VWDTH × 2<br>**----- End of picture text -----**<br>

**Figure 36.29 Image of Storing Interlace Input as Frame Image in Memory**

## 36.4.8 CEU Register Control Register (CRCNTR)

CRCNTR controls switching of the planes of registers with a 2-plane configuration.

|||Bit:|Bit:|31|30|29||28|27|26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—|—|—||—|—|—|—<br>—<br>—<br>—<br>—<br>—|—|—|—|—||
||Initial|value:||0|0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
|||R/W:||R|R|R||R|R|R|R<br>R<br>R<br>R<br>R<br>R|R|R|R|R||
|||Bit:||15|14|13||12|11|10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|||||—|—|—||—|—|—|—<br>—<br>—<br>—<br>—<br>RVS|—|—|RS|RC||
||Initial|value:||0|0|0||0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
|||R/W:||R|R|R||R|R|R|R<br>R<br>R<br>R<br>R<br>R/W|R|R|R/W|R/W||
|||||||**Initial**|||||||||||
|**Bit**||**Bit**|**Name**|||**Value**|||**R/W**||**Description**||||||
|31 to|5|—||||All 0|||R||Reserved||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||
|4||RVS||||0|||R/W||Sets the timing to switch the register plane in both-field|||capture.|||
||||||||||||The setting of this bit is valid only when the RC bit is 1 in both-field capture.||||||
||||||||||||0: Switches the register plane every 2 VD||||||
||||||||||||1: Switches the register plane every 1 VD||||||
|3, 2||—||||All 0|||R||Reserved||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||
|1||RS||||0|||R/W||Specifies which register plane is used by the CEU in synchronization|||||with|
||||||||||||VD.||||||
||||||||||||The setting of this bit is valid only when the RC bit is 0.||||||
||||||||||||0: Uses plane A of the register||||||
||||||||||||1: Uses plane B of the register||||||
|0||RC||||0|||R/W||Specifies switching of the register plane used by||the CEU in||||
||||||||||||synchronization with VD.||||||
||||||||||||If the register plane is not switched, the register plane specified by the RS||||||
||||||||||||bit is used.||||||
||||||||||||0: Uses the specified register plane in synchronization with VD||||||
||||||||||||1: Switches the register plane in synchronization with VD||||||

**==> picture [268 x 82] intentionally omitted <==**

**----- Start of picture text -----**<br>
2 VD<br>CSTSR.CE<br>VIO_VD<br>VIO_FLD<br>Register plane Plane B Plane A Plane B Plane A<br>**----- End of picture text -----**<br>

**Figure 36.30 Timing for Register Plane Switching when RVS Bit is B'0**

**==> picture [287 x 81] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 VD<br>CSTSR.CE<br>VIO_VD<br>VIO_FLD<br>Register plane Plane B Plane A Plane B Plane A Plane B Plane A Plane B<br>**----- End of picture text -----**<br>

**Figure 36.31 Timing for Register Plane Switching when RVS Bit is B'1**

## 36.4.9 CEU Register Forcible Control Register (CRCMPR)

CRCMPR forcibly controls switching of the planes of registers with a 2-plane configuration. Setting this register enables direct control of register plane switching.

Do not modify this register during operation. If this register is modified during operation, correct operation cannot be guaranteed. In addition, the IGRW bit (interrupt source) in CETCR is set to B'1.

||||Bit:|Bit:|31|30|29||28|27|26|25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||—|—|—||—|—|—|—<br>—<br>—<br>—<br>—|—|—|—|—|—||
|||Initial|value:||0|0|0||0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R|R||R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|R|R||
||||Bit:||15|14|13||12|11|10|9<br>8<br>7<br>6<br>5|4|3|2|1|0||
||||||—|—|—||—|—|—|—<br>—<br>—<br>—<br>—|—|—|—|—|RA||
|||Initial|value:||0|0|0||0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R|R||R|R|R|R<br>R<br>R<br>R<br>R|R|R|R|R|R/W||
||||||||**Initial**||||||||||||
|**Bit**|||**Bit**||**Name**||**Value**|||**R/W**||**Description**|||||||
|31|to|1|—||||All 0|||R||Reserved|||||||
|||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|0|||RA||||0|||R/W||Indicates the register plane currently specified. This register value|||||||
|||||||||||||automatically changes in synchronization||with VD for starting capture.|||||
|||||||||||||To start capture with plane A of the register when a setting to switch the|||||||
|||||||||||||register plane in synchronization with VD||has been made (RC|||bit in||
|||||||||||||CRCNTR is 1), specify plane B of the register using this bit.|||||||
|||||||||||||0: Specifies plane A of the register|||||||
|||||||||||||1: Specifies plane B of the register|||||||

## 36.4.10 Capture Filter Control Register (CFLCR)

CFLCR sets the scale-down factor for the filter to scale images down.

The CEU has an image scale-down filter which can be used to scale down the captured images before storing them in the memory. Set CFLCR to 0 when not performing scale-down (same size output). If a value other than 0 is set in CFLCR, scale-down is performed. In data fetch mode, set CFLCR to 0.

When handling an interlace source image as a frame image, set CFLCR to 0 not to use the filter.

||Bit:|Bit:|31|30|29|28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19|18|17<br>16|17<br>16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||VMANT[3:0]|||||VFRAC[11:0]|||||
|Initial|value:||0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R|R<br>R|||
||Bit:||15|14|13|12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3|2|1|0||
|||||HMANT[3:0]|||||HFRAC[11:0]|||||
|Initial|value:||0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|0||
||R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R|R<br>R|||
||||||**Initial**|||||||||
|**Bit**|**Bit**||**Name**||**Value**||**R/W**||**Description**|||||
|31 to 28|VMANT[3:0]|||||H'0|R/W||Mantissa Part of Vertical Scale-Down Factor|||||
||||||||||The specifiable range is H'0 to H'F. When H'0 is set for the VMANT bits and|||||
||||||||||H'000 is set for the VFRAC bits, the scale-down filter is not|||used.||
|27 to 19|VFRAC[11:3]||||H'000||R/W||Fraction Part of Vertical Scale-Down Factor|||||
|18 to 16|VFRAC[2:0]||||||R||The specifiable range is H'000 to H'FF8. The fraction of||the|scale-down||
||||||||||factor that cannot be set with only the VMANT bits must be|||set with these||
||||||||||bits.|||||
|15 to 12|HMANT[3:0]|||||H'0|R/W||Mantissa Part of Horizontal Scale-Down Factor|||||
||||||||||The specifiable range is H'0 to H'F. When H'0 is set for the HMANT bits and|||||
||||||||||H'000 is set for the HFRAC bits, the scale-down filter is not|||used.||
|11 to 3|HFRAC[11:3]||||H'000||R/W||Fraction Part of Horizontal Scale-Down Factor|||||
|2 to 0|HFRAC[2:0]||||||R||The specifiable range is H'000 to H'FF8. The fraction of||the|scale-down||
||||||||||factor that cannot be set with only the HMANT bits must be|||specified|with|
||||||||||these bits.|||||

An image scale-down filter is installed in the CEU, and the captured images can be scaled down and stored in the memory.

**==> picture [483 x 101] intentionally omitted <==**

**----- Start of picture text -----**<br>
Camera image CEU destination image<br>Sample filter<br>for scale-down<br>Figure 36.32 Scale-Down of Captured Image<br>**----- End of picture text -----**<br>

The formulas for obtaining the MANT (VMANT or HMANT) and FRAC (VFRAC or HFRAC) values from the input pixel count and output pixel count of the filter are shown below. Set the MANT and FRAC bits in order to obtain the desired output pixel count from the number of pixels input to the CEU.

First, calculate preliminary MANT and FRAC values. The parameters needed for calculation are defined as follows:

**==> picture [265 x 35] intentionally omitted <==**

Assuming an operator  _x_  which discards fractions of an integer _x_ , the MANT and FRAC values can be temporarily set as follows, according to formula 1 and formula 2.

**==> picture [207 x 18] intentionally omitted <==**

Here, the scaled-down filter output size ( _SIZED_ ) can be calculated using the input image size _Sin_ (half of the CAPWR setting) in the following formula.

**==> picture [280 x 30] intentionally omitted <==**

_MANTpre_ = 1 (0 ≤ _MANT_ < 2) _MANTpre_ = 2 (2 ≤ _MANT_ < 4) _MANTpre_ = 4 (4 ≤ _MANT_ < 8) _MANTpre_ = 8 (8 ≤ _MANT )_

The number of output pixels can be obtained by substituting the temporarily calculated MANT, FRAC, and input image size into these formulas. If the calculated number of output pixels is smaller than the number of output pixels used to obtain the preliminary MANT and FRAC values, recalculate with a smaller FRAC (α) value, and set the MANT and FRAC values in this register so that a pixel value greater than the desired number of output pixels can be obtained.

Example: Scale down 640 pixels to 480 pixels

SCL = 480/640 = 3/4, and the preliminary settings of MANT = 1, MANT _pre_ = 1, and FRAC = H'550 are made. Substituting these in the following formula results in an output pixel count of 479.

**==> picture [280 x 30] intentionally omitted <==**

Since this output pixel count is smaller than the desired output pixel count of 480, the formula is recalculated with a FRAC value of H'548, a value eight less than the previous time. The obtained result of output pixel count = 480 is equal to the desired output pixel count of 480, so this register is set as MANT = 1 and FRAC = H'548.

**Table 36.8 Setting Examples for Each Scale-Down Filter Factor**

|**Scale-Down**<br>**Factor**|**FRAC**<br>**MANT**<br>**Input Pixel**<br>**Count**<br>**Output Pixel**<br>**Count**<br>**Clipping Size**<br>**(CFSZR)**<br>**Decimal**<br>**Hexadecimal**|
|---|---|
|7/8|576<br>H'240<br>1<br>640<br>560<br>560|
|3/4|1352<br>H'548<br>1<br>640<br>480<br>480|
|5/8|2448<br>H'990<br>1<br>640<br>400<br>400|
|1/2|0<br>H'0<br>2<br>640<br>320<br>320|
|3/8|2728<br>H'AA8<br>2<br>640<br>240<br>240|
|1/3|0.0<br>H'0<br>3<br>640<br>213<br>212|
|1/4|0.0<br>H'0<br>4<br>640<br>160<br>160|
|1/5|0.0<br>H'0<br>5<br>640<br>128<br>128|
|1/6|0.0<br>H'0<br>6<br>640<br>107<br>104|
|1/7|0.0<br>H'0<br>7<br>640<br>91<br>88|
|1/8|0.0<br>H'0<br>8<br>640<br>80<br>80|
|1/16|4088<br>H'FF8<br>15<br>640<br>40<br>40|

Note: This scale-down filter uses a VGA-size line memory for scale-down. Therefore, when an image larger than the VGA size is input for scale-down, settings must be made so that the output image size is equal to or larger than the SubQCIF size and equal to or smaller than the VGA size. When an image is not scaled down (same size output), this restriction does not apply.

## 36.4.11 Capture Filter Size Clip Register (CFSZR)

CFSZR sets the clipping size for fine adjustment of the image size output from the filter, and must be set in combination with CFLCR. When clipping the output size of the filter, set the clipping size as a number of pixels, and the setting unit should be four pixels. CFSZR must be set even when scale-down is not performed (same size output).

In data synchronous fetch mode, set CFSZR according to the setting of CAPWR.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|||||VFCLP[11:0]||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||—|—|—|—|||||HFCLP[11:0]||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 28|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|27 to 18|VFCLP[11:2]|H'000|R/W|These bits set the vertical clipping value of the filter output size (4-pixel|
|17, 16|VFCLP[1:0]||R|units).|
|15 to 12|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|11 to 2|HFCLP[11:2]|H'000|R/W|These bits specify the horizontal clipping value of the filter output size (4-|
|1, 0|HFCLP[1:0]||R|pixel units*).|
|||||Note: * 8-pixel units when writing to other than the on-chip RAM|

The scale-down filter in the CEU may output an odd number of pixels or lines depending on the settings. To adjust the output size of the filter, the CEU clips the destination image by using the number of pixels specified in CFSZR, as shown in Figure 36.33 . The clipping size must be specified vertically and horizontally in 4-pixel units.

**==> picture [281 x 169] intentionally omitted <==**

**----- Start of picture text -----**<br>
(h+a) pixels<br>Filter (v+b) lines<br>Source image Destination image<br>CFSZR.HFCLP = h<br>Clipping<br>CFSZR.VFCLP = v<br>h pixels<br>v lines<br>**----- End of picture text -----**<br>

**Figure 36.33 Clipping of Image Output from Filter**

The pixels to be clipped are counted from the top-left corner of a display. The pixels located to the right of the specified number of pixels or below the specified number of lines are discarded by the clipping function. If the number of pixels specified in CFSZR is larger than that output from the filter, correct operation cannot be guaranteed. To avoid this, the clipping size specified in CFSZR must be equal to or smaller than the number of pixels output from the filter.

Note: In data synchronous fetch mode, the following settings are required. Data cannot be fetched correctly unless the following settings are made. VFCLP = CAPWR.VWDTH HFCLP = CAPWR.HWDTH/2

## 36.4.12 Capture Destination Width Register (CDWDR)

CDWDR sets the horizontal image size in the memory area where the captured image is to be output in 4-byte units (4pixel units).

In data synchronous fetch mode, set CDWDR according to the setting of CAPWR.

This register is not used, during data enable fetch mode.

|||Bit:|Bit:|31|30|29|28|27||26|25<br>24<br>23<br>22<br>21<br>20|19|18<br>17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—|—|—|—|—||—|—<br>—<br>—<br>—<br>—<br>—|—|—<br>—|—||
||Initial|value:||0|0|0|0|0||0|0<br>0<br>0<br>0<br>0<br>0|0|0<br>0|0||
|||R/W:||R|R|R|R|R||R|R<br>R<br>R<br>R<br>R<br>R|R|R<br>R|R||
|||Bit:||15|14|13|12|11||10|9<br>8<br>7<br>6<br>5<br>4|3|2<br>1|0||
|||||—|—|—|||||CHDW[12:0]|||||
||Initial|value:||0|0|0|0|0||0|0<br>0<br>0<br>0<br>0<br>0|0|0<br>0|0||
|||R/W:||R|R|R|R/W|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W<br>R|R||
|||||||**Initial**||||||||||
|**Bit**||**Bit**||**Name**||**Value**||**R/W**|||**Description**|||||
|31 to|13|—||||All|0|R|||Reserved|||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||
|12 to|2|CHDW[12:2]||||H'0000||R/W|||These bits specify the horizontal image size in the memory area where the|||||
|1, 0||CHDW[1:0]||||||R|||captured image is to be stored (4-byte units*).|||||
||||||||||||The image data captured by the CEU is stored in the memory. If the right|||||
||||||||||||end of the captured image does not match the horizontal image size in the|||||
||||||||||||memory area as shown in Figure 36.34, some addresses must be skipped|||||
||||||||||||at the right end of the image when storing the captured image. Therefore,|||||
||||||||||||the horizontal image size in the memory area where the captured image is|||||
||||||||||||to be stored must be set in these bits.|||||
||||||||||||The maximum value to be set is 8188 bytes (8188 pixels).|||||
||||||||||||In data synchronous fetch mode, set as follows:|||||
||||||||||||CHDW = CAPWR.HWDTH|||||
||||||||||||Note: * 8-byte units when writing to other|than the on-chip RAM||||

**==> picture [283 x 114] intentionally omitted <==**

**----- Start of picture text -----**<br>
CHDW<br>CEU destination image<br>Memory image<br>**----- End of picture text -----**<br>

**Figure 36.34 Captured Image and Memory Area Image**

## 36.4.13 Capture Data Address Y Register (CDAYR)

CDAYR specifies the address where the luminance (Y) component of the captured data is to be stored in frame image capture or one-field image capture, the address where the luminance (Y) component of the captured top field is to be stored in both-field image capture, and the address where the fetched data is to be stored in data fetch. The CEU separates the captured image data into the luminance component data (Y) and the chrominance component data (C), and stores them in the memory via the bus. In frame image capture or one-field image capture, set the start address of the memory area where the Y (luminance) component of the captured data is to be stored by CDAYR. In both-field image capture, set the start address of the memory area where the Y (luminance) component of the captured top-field image is to be stored by CDAYR. In data fetch, set the start address of the memory area where data is to be stored by CDAYR.

Because the address must be specified in 32 bits, the address set by CDAYR must be in longword units. As the setting is in 4-pixel units for image capture and 4-byte units for data fetch, the lower two bits are always fixed to 0.

|||Bit:|31|30|29|28|27|26|25|24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||CAYR[31:16]|
||Initial|value:|0|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|
|||Bit:|15|14|13|12|11|10|9|8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|||||||||||CAYR[15:0]|
||Initial|value:|0|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R|
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**|
|31 to|2|CAYR[31:2]|||H'0000 0000|||R/W||Frame image capture: These bits set the address for storing the|
|1, 0||CAYR[1:0]||||||R||Y (luminance) component data of the captured data (4-pixel|
|||||||||||units*1).|
|||||||||||One-field image capture: These bits set the address for storing|
|||||||||||the Y (luminance) component data of the captured data (4-pixel|
|||||||||||units*1).|
|||||||||||Both-field image capture: These bits set the address for storing|
|||||||||||the Y (luminance) component data of the captured top-field data|
|||||||||||(4-pixel units*1).|
|||||||||||Data fetch: These bits set the address for storing data (4-byte|
|||||||||||units*2).|
|||||||||||Data enable fetch bundle write: These bits set the address for|
|||||||||||storing data (32-byte units).|
|||||||||||Note 1. 8-pixel units when writing to other than the on-chip RAM|
|||||||||||Note 2. 8-byte units when writing to other than the on-chip RAM|

Set the address of the starting point of the memory area where the fetched data is to be stored in this register, as shown in Figure 36.35 .

- Frame image capture: Set the address of the starting point of the memory area where the Y component of the captured image is to be stored.

- One-field image capture: Set the address of the starting point of the memory area where the Y component of the captured image is to be stored.

- Both-field image capture: Set the address of the starting point of the memory area where the Y component of the captured top-field image is to be stored.

- Data fetch: Set the address of the starting point of the memory area where the fetched data is to be stored. In data fetch mode, the data is simply stuffed in order from the start address so the end address becomes as follows:

## **End address = CDAYR + number of fetched bytes**

- Data enable fetch bundle write: Set the address in 32-byte units.

**==> picture [360 x 152] intentionally omitted <==**

**----- Start of picture text -----**<br>
CDAYR<br>CDAYR<br>(start address for storage)<br>CEU destination image<br>Memory image Memory<br>Y memory area<br>C memory area<br>**----- End of picture text -----**<br>

**Figure 36.35 Relationship between Captured Image and Y Component Memory Area**

## 36.4.14 Capture Data Address C Register (CDACR)

CDACR specifies the address where the chrominance (C) component of the captured data is to be stored in frame image capture or one-field image capture, and the address where the chrominance (C) component of the captured top field is to be stored in both-field image capture. The CEU separates the captured image data into the luminance component data (Y) and the chrominance component data (C), and stores them in the memory via the bus. In frame image capture or onefield image capture, set the start address of the memory area where the C (chrominance) component of the captured data is to be stored by CDACR. In both-field image capture, set the start address of the memory area where the C (chrominance) component of the captured top-field image is to be stored by CDACR. CDACR is not used in data fetch.

Because the address must be specified in 32 bits, the address set by CDACR must be in longword units. As the setting is in 4-pixel units, the lower two bits are always fixed to 0.

|||Bit:|31|30|29|28|27|26|25|24<br>23<br>22<br>21<br>20<br>19<br>18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||CACR[31:16]|||
||Initial|value:|0|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|
|||Bit:|15|14|13|12|11|10|9|8<br>7<br>6<br>5<br>4<br>3<br>2|1|0|
|||||||||||CACR[15:0]|||
||Initial|value:|0|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R|R|
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**|||
|31 to|2|CACR[31:2]|||H'0000 0000|||R/W||Frame image capture: These bits set the address||for storing the|
|1, 0||CACR[1:0]||||||R||C (chrominance) component data of the captured||data (4-pixel|
|||||||||||units*).|||
|||||||||||One-field image capture: These bits set the address for storing|||
|||||||||||the C (chrominance) component data of the|captured data (4-||
|||||||||||pixel units*).|||
|||||||||||Both-field image capture: These bits set the|address for storing||
|||||||||||the C (chrominance) component data of the|captured top-field||
|||||||||||data (4-pixel units*).|||
|||||||||||Note: * 8-pixel units when writing to other than the on-chip RAM|||

Set the address of the starting point of the memory area where the C component of the captured image is to be stored in this register, as shown in Figure 36.36 . The C component has an output data format like that in Figure 36.37 , and is saved in the memory in this format.

- Frame image capture: Set the address of the starting point of the memory area where the C component of the captured image is to be stored.

- One-field image capture: Set the address of the starting point of the memory area where the C component of the captured image is to be stored.

- Both-field image capture: Set the address of the starting point of the memory area where the C component of the captured top-field image is to be stored.

**==> picture [359 x 143] intentionally omitted <==**

**----- Start of picture text -----**<br>
CDACR CDACR<br>CEU destination image<br>Memory image Memory<br>Y memory area<br>C memory area<br>**----- End of picture text -----**<br>

**Figure 36.36 Relationship between Captured Image and C Component Memory Area**

**==> picture [142 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
Cb0 Cr0 Cb2 Cr2<br>**----- End of picture text -----**<br>

**Figure 36.37 Image of Storing C Components in Memory**

## 36.4.15 Capture Data Bottom-Field Address Y Register (CDBYR)

CDBYR specifies the address where the luminance (Y) component of the captured bottom-field data is to be stored in both-field image capture. The CEU separates the captured image data into the luminance component data (Y) and the chrominance component data (C), and stores them in the memory via the bus. Set the start address of the memory area where the Y (luminance) component of the captured bottom-field image is to be stored by CDBYR. CDBYR is not used in frame image capture, one-field image capture, or data fetch.

Because the address must be specified in 32 bits, the address set by CDBYR must be in longword units. As the setting is in 4-pixel units, the lower two bits are always fixed to 0.

|||Bit:|31|30|29|28|27|26|25|24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||CBYR[31:16]||||||||
||Initial|value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||Bit:|15|14|13|12|11|10|9|8<br>7|6|5|4|3|2|1|0|
|||||||||||CBYR[15:0]||||||||
||Initial|value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R|R|
|**Bit**||**Bit Name**|||**Initial**|**Value**||**R/W**||**Description**||||||||
|31 to|2|CBYR[31:2]|||H'0000 0000|||R/W||These bits set the||address for storing|||the Y (luminance)|||
|1, 0||CBYR[1:0]||||||R||component data of the captured bottom-field data (4-pixel units*).||||||||
|||||||||||Note: * 8-pixel units when|||writing to other than the on-chip RAM|||||

Set the address of the starting point of the memory area where the Y component of the captured bottom-field image is to be stored in this register, as shown in Figure 36.38 .

**==> picture [368 x 144] intentionally omitted <==**

**----- Start of picture text -----**<br>
CEU captured bottom-field  CDBYR CDBYR<br>destination image<br>Memory image Memory<br>Y memory area<br>C memory area<br>**----- End of picture text -----**<br>

**Figure 36.38 Relationship between Captured Bottom-Field Image and Y Component Memory Area**

## 36.4.16 Capture Data Bottom-Field Address C Register (CDBCR)

CDBCR specifies the address where the chrominance (C) component of the captured bottom-field data is to be stored in both-field image capture. The CEU separates the captured image data into the luminance component data (Y) and the chrominance component data (C), and stores them in the memory via the bus. Set the start address of the memory area where the C (chrominance) component of the captured bottom-field image is to be stored by CDBCR. CDBCR is not used in frame image capture, one-field image capture, or data fetch.

Because the address must be specified in 32 bits, the address set by CDBCR must be in longword units. As the setting is in 4-pixel units, the lower two bits are always fixed to 0.

|||Bit:|31|30|29|28|27|26|25|24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||CBCR[31:16]||||||||
||Initial|value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||Bit:|15|14|13|12|11|10|9|8<br>7|6|5|4|3|2|1|0|
|||||||||||CBCR[15:0]||||||||
||Initial|value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R|R|
|**Bit**||**Bit Name**|||**Initial**|**Value**||**R/W**||**Description**||||||||
|31 to|2|CBCR[31:2]|||H'0000 0000|||R/W||These bits set the||address for storing|||the C (chrominance)|||
|1, 0||CBCR[1:0]||||||R||component data of the captured bottom-field data (4-pixel units*).||||||||
|||||||||||Note: * 8-pixel units when|||writing to other than the on-chip RAM|||||

Set the address of the starting point of the memory area where the C component of the captured bottom-field image is to be stored in this register, as shown in Figure 36.39 . The C component has an output data format like that in Figure 36.40 , and is saved in the memory in this format.

**==> picture [372 x 142] intentionally omitted <==**

**----- Start of picture text -----**<br>
CEU captured bottom-field  CDBCR CDBCR<br>destination image<br>Memory image Memory<br>Y memory area<br>C memory area<br>**----- End of picture text -----**<br>

**Figure 36.39 Relationship between Captured Bottom-Field Image and C Component Memory Area**

**==> picture [141 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
Cb0 Cr0 Cb2 Cr2<br>**----- End of picture text -----**<br>

**Figure 36.40 Image of Storing C Components in Memory**

## 36.4.17 Capture Bundle Destination Size Register (CBDSR)

CBDSR sets the size of output to memory in a bundle write. The number of output lines should be specified for image capture or data synchronous fetch. The number of bytes should be specified for data enable fetch.

||||Bit:|31|30|29|28|27||26<br>25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||—|—|—|—|—||—<br>—<br>—<br>—|CBVS[22:16]||||||
|||Initial|value:|0|0|0|0|0||0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:|R|R|R|R|R||R<br>R<br>R<br>R<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
||||Bit:|15|14|13|12|11||10<br>9<br>8<br>7<br>6<br>5|4|3|2|1|0||
|||||||||||CBVS[15:0]|||||||
|||Initial|value:|0|0|0|0|0||0<br>0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:|R/W|R/W|R/W|R/W|R/W||R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R|R|R||
|||||||**Initial**|||||||||||
|**Bit**|||**Bit**|**Name**||**Value**||**R/W**||**Description**|||||||
|31|to|23|—|||All|0|R||Reserved|||||||
|||||||||||These bits are always read as 0. The write value|||should always be 0.||||
|22|to|0|CBVS[22:3]|||H'000||R/W||These bits select the number of lines or number of bytes for output to the|||||||
||||CBVS[2:0]|||||R||memory in a bundle write.|||||||
|||||||||||Image capture and data synchronous fetch: Number of lines for output to|||||||
|||||||||||the memory in a bundle write.|||||||
|||||||||||Unit: 8 lines, min.: 8 lines, max.: 1,920 lines (H'780)|||||||
|||||||||||Data enable fetch: Number of bytes|for output to||the memory in a bundle||||
|||||||||||write.|||||||
|||||||||||Unit: 32 bytes, min.: 512 bytes,|||||||
|||||||||||max.: 6291456 lines (H'600000)|||||||

## (a) Image capture and data synchronous fetch

Set the number of lines of captured data to be written to the memory by a bundle write as a multiple of eight. This register is valid only when the CBE bit in CDOCR is 1. When the CBE bit in CDOCR is 1 and this register cleared to H'0, this module operates with the number of lines of captured data to be written to the memory as eight. The maximum number of lines that can be set is 1,920 (H'780). Only bits CBVS[11:3] are valid.

**==> picture [309 x 155] intentionally omitted <==**

**----- Start of picture text -----**<br>
CEU source image<br>Memory image<br>CBVS<br>CBVS<br>**----- End of picture text -----**<br>

**Figure 36.41 Image of Storing Captured Image in Memory by Bundle Write**

## (b) Data enable fetch

Set the number of bytes of captured data to be written to the memory by a bundle write as a multiple of 32. This register is valid only when the CBE bit in CDOCR is 1. The minimum settable size is 512 bytes. When a number smaller than 512 bytes is specified, operation is not guaranteed.

## 36.4.18 Capture Low-Pass Filter Control Register (CLFCR)

CLFCR specifies whether or not to operate the low-pass filter. In data fetch mode, clear the LPF bit to B'0.

The characteristic of the low-pass filter installed in the CEU causes the phase location of the image processed by the lowpass filter to be shifted right by one pixel compared to the raw image.

||||Bit:|Bit:|31|30|29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||—|—|—|—|—|—|—<br>—|—|—|—|—|—|—|—|—||
|||Initial|value:||0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:||15|14|13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
||||||—|—|—|—|—|—|—<br>—|—|—|—|—|—|—|—|LPF||
|||Initial|value:||0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|R|R|R|R|R<br>R|R|R|R|R|R|R|R|R/W||
||||||||**Initial**||||||||||||||
|**Bit**|||**Bit**|**Name**|||**Value**||**R/W**||**Description**||||||||||
|31|to|1|—||||All 0||R||Reserved||||||||||
||||||||||||These bits are always read as 0. The write value should always be 0.||||||||||
|0|||LPF||||0||R/W||Enables or disables operation of the low-pass filter.||||||||||
||||||||||||The low-pass|filter removes||high-frequency components from|||||the||
||||||||||||destination image in the horizontal||||direction. Clear this bit to 0||||in data fetch||
||||||||||||mode.||||||||||
||||||||||||0: Low-pass filter not||used||||||||
||||||||||||1: Low-pass filter used (only in the||||horizontal direction)||||||

## 36.4.19 Firewall Operation Control Register (CFWCR)

CFWCR specifies the upper limit of the write addresses in data enable fetch. When the VD input from an external module dose not go low and end notification is not given, this register can prevent writing to memory from being out of control.

This register is enabled only in data enable fetch.

||Bit:|Bit:|31|30|29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||FWV[26:11]||||||||
|Initial|value:||0|0|0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W||
||Bit:||15|14|13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
||||||||FWV[10:0]||||—|—|—|—|FWE||
|Initial|value:||0|0|0|0|0|0|0<br>1<br>0<br>0|0|0|0|0|0|0||
||R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R|R|R|R|R/W||
|**Bit**|**Bit**||**Name**||**Initial**|**Value**|**R/W**||**Description**||||||||
|31 to 5|FWV[26:0]||||H'0000008||R/W||These bits specify the upper limit of a write address.||||||||
||||||||||Specify the upper 27 bits of the 32-bit address.||||||||
||||||||||The upper limit of an address is FWV[26:0]<<5 + H'1F.||||||||
|4 to 1|—||||All 0||R||Reserved||||||||
||||||||||These bits are always read as 0. The write value should always be 0.||||||||
|0|FWE||||0||R/W||With the setting of FWE1, when an address exceeds the value set with||||||||
||||||||||FWV, the address is retained and an interrupt source FWF is set. After this,||||||||
||||||||||the address is not incremented and data|||is overwritten||on the|upper|limit|
||||||||||address.||||||||
||||||||||0: Firewall is not activated.||||||||
||||||||||1: Firewall is activated.||||||||

## 36.4.20 Capture Data Output Control Register (CDOCR)

CDOCR sets the format for outputting captured data to the memory. In data fetch mode, set the CDS bit to B'1.

||||Bit:|Bit:|31|30||29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||—|—||—|—|—|—|—|—|—|—|—|—|—|—|—|CBE||
|||Initial|value:||0|0||0|0|0|0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R|R||R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||
||||Bit:||15|14||13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||||—|—||—|—|—|—|—|—|—|—|—|CDS|—|COLS|COWS|COBS||
|||Initial|value:||0|0||0|0|0|0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R|R||R|R|R|R|R|R|R|R|R|R/W|R|R/W|R/W|R/W||
|||||||**Initial**|||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**|**Description**|||||||||||||
|31|to|17|—|||All 0|||R|Reserved|||||||||||||
|||||||||||These bits are always read as 0. The||||||write value should always be 0.|||||||

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**|**Description**|
|---|---|
|16<br>CBE<br>0<br>R/W|Controls the number of lines of captured data to be written to the memory.<br>Image capture<br>This bit controls the number of lines of captured data to be written to the memory.<br>When bundle write is set by this register, captured data is written in line units<br>specified by CBDSR to the addresses specified by CDAYR and CDACR, and<br>CDAYR2 and CDACR2 (CDBYR and CDBCR, and CDBYR2 and CDBCR2 for the<br>bottom field in both-field capture) alternately (Figure 36.42). When captured data<br>has been written for the number of lines set by CBDSR, a write end interrupt<br>corresponding to each address setting register occurs. However, after write for<br>one-frame (one-field) capture ends, a bundle write end interrupt does not occur<br>even when bundle write has finished.|
||Data synchronous fetch<br>This bit controls the number of lines of captured data to be written to the memory.<br>When bundle write is set by this register, captured data is written in line units<br>specified by CBDSR to the addresses specified by CDAYR and CDAYR2<br>alternately. When captured data has been written for the number of lines set by<br>CBDSR, a write end interrupt corresponding to each address setting register<br>occurs. However, after write for one-frame capture ends, a bundle write end<br>interrupt does not occur even when bundle write has finished.<br>Data enable fetch<br>This bit controls the number of bytes of captured data to be written to the memory.<br>When bundle write is set by this register, captured data is written in byte units<br>specified by CBDSR to the addresses specified by CDAYR and CDAYR2<br>alternately. When captured data has been written for the number of bytes set by<br>CBDSR, a write end interrupt corresponding to each address setting register<br>occurs. Also, only in data enable fetch, a bundle write end interrupt occurs when<br>bundle write has finished after write for one-frame capture ends.<br>Table 36.9 shows the correspondence between address setting registers and write<br>end interrupt sources. Figure 36.43 shows the timing of write end interrupts in<br>image capture and data synchronous fetch. Figure 36.44 shows the timing of write<br>end interrupts in data enable fetch.<br>0: Normal write<br>1: Bundle write|
|15 to 5<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|4<br>CDS<br>0<br>R/W|Sets the image format when outputting the image data captured in the YCbCr422<br>format to the memory.<br>When 0 is written to this bit, only the luminance component (Y) is output and no<br>chrominance components (Cb and Cr) are output for the odd-numbered lines. With an<br>interlace source image, similarly only the luminance component (Y) is output and no<br>chrominance components (Cb and Cr) are output for the odd-numbered lines of the<br>field. In data fetch mode, set this bit to 1.<br>0: Converts the YCbCr422 format to the YCbCr420 format before outputting data to<br>the memory<br>1: Outputs data in the YCbCr422 format to the memory without conversion|
|3<br>—<br>0<br>R|Reserved<br>This bit is always read as 0. The write value should always be 0.|
|2<br>COLS<br>0<br>R/W|Controls swapping in 32-bit units for data output from the CEU.<br>0: Data is not swapped in 32-bit units<br>1: Data is swapped in 32-bit units|
|1<br>COWS<br>0<br>R/W|Controls swapping in 16-bit units for data output from the CEU.<br>0: Data is not swapped in 16-bit units<br>1: Data is swapped in 16-bit units|
|0<br>COBS<br>0<br>R/W|Controls swapping in 8-bit units for data output from the CEU.<br>0: Data is not swapped in 8-bit units<br>1: Data is swapped in 8-bit units|

**==> picture [314 x 162] intentionally omitted <==**

**----- Start of picture text -----**<br>
CDAYR, CDACR CDWDR<br>CEU source image<br>Memory image<br>CBDSR<br>CDAYR2, CDACR2<br>CBDSR<br>**----- End of picture text -----**<br>

**Figure 36.42 Image of Bundle Write to Memory**

**Table 36.9 Correspondence between Address Setting Registers and Write End Interrupt Sources**

|**Address Setting Registers**|**Bundle Write End Interrupt Source**|
|---|---|
|CDAYR, CDACR|CPBE1 bit in CETCR|
|CDAYR2, CDACR2|CPBE2 bit in CETCR|
|CDBYR, CDBCR|CPBE3 bit in CETCR|
|CDBYR2, CDBCR2|CPBE4 bit in CETCR|

**==> picture [236 x 234] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_VD<br>VIO_HD<br>Write<br>CAPSR.CE<br>End of write to<br>Bundle 1<br>CDAYR, CDACR<br>write end<br>interrupt<br>CETCR.CPBE1<br>Clear End of write to<br>Bundle 2 CDAYR2, CDACR2<br>write end<br>interrupt<br>CETCR.CPBE2<br>One-frame   Clear<br>capture end<br>interrupt<br>CETCR.CPE<br>CBDSR line  CBDSR line<br>bundle 1 bundle 2<br>capture period capture period<br>1 frame capture period<br>**----- End of picture text -----**<br>

**Figure 36.43 Timing of Write End Interrupts (Image Capture, Data Synchronous Fetch)**

**==> picture [261 x 234] intentionally omitted <==**

**----- Start of picture text -----**<br>
VIO_VD<br>VIO_HD<br>Write<br>CAPSR.CE<br>End ot write to<br>Bundle 1 CDAYR<br>write end<br>interrupt source<br>CETCR.CPBE1 = 1<br>Clear End of write to<br>CDAYR2<br>Bundle 2<br>write end<br>interrupt source<br>CETCR.CPBE2 = 1<br>One-frame Clear<br>capture end<br>interrupt source<br>CETCR.CPE = 1<br>CBDSR byte CBDSR byte<br>bundle 1 bundle 2<br>capture period capture period<br>One-frame capture period<br>**----- End of picture text -----**<br>

**Figure 36.44 Timing of Write End Interrupts (Data Enable Fetch)**

For data output from the CEU, the COLS, COWS, and COBS bits control swapping in 32-bit, 16-bit, and 8-bit units, respectively. Set these bits when data is misaligned because of a difference in endian. The data swapping bits are shown below. These bits can be set similarly in data fetch mode.

Data can be swapped in 8-bit, 16-bit, 32-bit units, or in 32 bits, 16 bits and 8 bits, as shown in Figure 36.45 . To enable data swapping, set the corresponding control bit to B'1.

**==> picture [219 x 434] intentionally omitted <==**

**----- Start of picture text -----**<br>
8-bit swapping<br>64 bits<br>MSB LSB<br>1 2 3 4 5 6 7 8<br>2 1 4 3 6 5 8 7<br>16-bit swapping<br>64 bits<br>MSB LSB<br>1 2 3 4 5 6 7 8<br>3 4 1 2 7 8 5 6<br>32-bit swapping<br>64 bits<br>MSB LSB<br>1 2 3 4 5 6 7 8<br>5 6 7 8 1 2 3 4<br>32 bits, 16 bits, and 8 bits<br>64 bits<br>MSB LSB<br>1 2 3 4 5 6 7 8<br>5 6 7 8 1 2 3 4<br>7 8 5 6 3 4 1 2<br>8 7 6 5 4 3 2 1<br>**----- End of picture text -----**<br>

**Figure 36.45 Data Swapping by Data Aligner**

## 36.4.21 Capture Event Interrupt Enable Register (CEIER)

CEIER enables or disables interrupts of the event flag register that generates CEU interrupts.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—|—|NV<br>DIE|NH<br>DIE|FWFIE|—|—|VB<br>PIE|—|IGV<br>SIE|IGH<br>SIE|CDT<br>OFIE|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R/W|R/W|R/W|R|R|R/W|R|R/W|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||CPBE<br>4IE|CPBE<br>3IE|CPBE<br>2IE|CPBE<br>1IE|—|—|VDIE|HDIE|—|—|—|IGR<br>WIE|—|—|CF<br>EIE|CP<br>EIE|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R/W|R/W|R/W|R/W|R|R|R/W|R/W|R|R|R|R/W|R|R|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 26|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|25|NVDIE|0|R/W|Non-VD Interrupt Enable|
|||||Disable this interrupt (NVDIE = 0) for data enable fetch.|
|||||0: Disables a non-VD interrupt|
|||||1: Enables a non-VD interrupt|
|24|NHDIE|0|R/W|Non-HD Interrupt Enable|
|||||Disable this interrupt (NHDIE = 0) for data enable fetch.|
|||||0: Disables a non-HD interrupt|
|||||1: Enables a non-HD interrupt|
|23|FWFIE|0|R/W|FWF Interrupt Enable|
|||||0: Disables a FWF interrupt|
|||||1: Enables a FWF interrupt|
|22, 21|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|20|VBPIE|0|R/W|VBP Interrupt Enable|
|||||0: Disables a VBP interrupt|
|||||1: Enables a VBP interrupt|
|19|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|18|IGVSIE|0|R/W|IGVS Interrupt Enable|
|||||0: Disables an IGVS interrupt|
|||||1: Enables an IGVS interrupt|
|17|IGHSIE|0|R/W|IGHS Interrupt Enable|
|||||0: Disables an IGHS interrupt|
|||||1: Enables an IGHS interrupt|
|16|CDTOFIE|0|R/W|CDTOF Interrupt Enable|
|||||0: Disables a CDTOF interrupt|
|||||1: Enables a CDTOF interrupt|
|15|CPBE4IE|0|R/W|CPBE4 Interrupt Enable|
|||||0: Disables a CPBE4 interrupt|
|||||1: Enables a CPBE4 interrupt|
|14|CPBE3IE|0|R/W|CPBE3 Interrupt Enable|
|||||0: Disables a CPBE3 interrupt|
|||||1: Enables a CPBE3 interrupt|
|13|CPBE2IE|0|R/W|CPBE2 Interrupt Enable|
|||||0: Disables a CPBE2 interrupt|
|||||1: Enables a CPBE2 interrupt|
|12|CPBE1IE|0|R/W|CPBE1 Interrupt Enable|
|||||0: Disables a CPBE1 interrupt|
|||||1: Enables a CPBE1 interrupt|
|11, 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9|VDIE|0|R/W|VD Interrupt Enable|
|||||0: Disables a VD interrupt|
|||||1: Enables a VD interrupt|
|8|HDIE|0|R/W|HD Interrupt Enable|
|||||0: Disables an HD interrupt|
|||||1: Enables an HD interrupt|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|IGRWIE|0|R/W|Register-Access-During-Capture Interrupt Enable|
|||||0: Disables a register-access-during-capture interrupt|
|||||1: Enables a register-access-during-capture interrupt|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|1|CFEIE|0|R/W|CFE Interrupt Enable|
|||||0: Disables a CFE interrupt|
|||||1: Enables a CFE interrupt|
|0|CPEIE|0|R/W|One-Frame Capture End Interrupt Enable|
|||||0: Disables a one-frame capture end interrupt|
|||||1: Enables a one-frame capture end interrupt|

## 36.4.22 Capture Event Flag Clear Register (CETCR)

CETCR notifies the CPU of the source of an interrupt that is generated in the CEU. The flags of CETCR can be used as interrupt signals. When the corresponding interrupt is enabled, an interrupt is generated. To clear the interrupt, clear the bit corresponding to the interrupt source to 0. After several cycles have passed after modifying the bit, the interrupt is cleared.

To clear the bit corresponding to the interrupt source to be cleared to 0 and retain that state, write 1 to that bit. For example, to clear only the CPE bit to 0, write H'FFFF FFFE to CETCR.

In CETCR, only bits to which 0 is written are cleared. Bits to which 1 is written retain their current values. To clear an interrupt source, write 0 only to the bit corresponding to the interrupt source to be cleared, and 1 to the other bits.

Note: Since the CETCR value becomes undefined in the following cases, clear all bits in CETCR to 0.

- VD and HD bits immediately after power-on reset or the deep-standby mode is entered

- All bits after the software standby or module standby mode is entered

- VD and HD bits after the polarities of the capture interface sync signals are changed

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—|—|NVD|NHD|FWF|—|—|VBP|—|IGVS|IGHS|CDTOF|
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R/W|R/W|R/W|R|R|R/W|R|R/W|R/W|R/W|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||CPBE4|CPBE3|CPBE2|CPBE1|—|—|VD|HD|—|—|—|IGRW|—|—|CFE|CPE|
|Initial value:||0|0|0|0|0|0|—|—|0|0|0|0|0|0|0|0|
|R/W:||R/W|R/W|R/W|R/W|R|R|R/W|R/W|R|R|R|R/W|R|R|R/W|R/W|

|**Bit**|||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|---|
|31|to|26|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|25|||NVD|0|R/W|This bit is used for an interrupt indicating that no VD was input.|
|||||||A non-VD interrupt occurs when the 14-bit internal counter becomes full.|
|||||||Accordingly, this bit is set to 1 when no VD has been input for at least 16,383|
|||||||lines since the last VD was input.|
|24|||NHD|0|R/W|This bit is used for an interrupt indicating that no HD was input.|
|||||||A non-HD interrupt occurs when the 11-bit internal counter that is incremented|
|||||||every eight cycles becomes full. Accordingly, this bit is set to 1 when no HD|
|||||||has been input for at least 16,376 cycles since the last HD was input.|
|||||||When connecting a camera whose HD is fixed low when VD is low, this bit|
|||||||may be set to 1.|
|||||||Ignore this interrupt during data enable fetch.|

|**Bit**||**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|---|
|23||FWF|0|R/W|The interrupt is generated when data is written to the address that exceeds the|
||||||value specified with CFWCR.FMV.|
||||||This bit is set to 1 when data is written to the address that exceeds the value|
||||||specified with CFWCR.FMV while CFWCR.FWE1.|
|22,|21|—|0|R|Reserved|
||||||These bits are always read as 0. The write value should always be 0.|
|20||VBP|0|R/W|This bit is used for an interrupt indicating that VD has been input while the|
||||||CEU holds data (insufficient vertical-sync front porch).|
||||||The conditions for a VBP interrupt to occur are as follows:|
||||||Condition 1|
||||||VD is input when there is captured data within the CEU|
||||||Condition 2|
||||||The last transfer data cannot be internally detected due to a write buffer|
||||||overflow or an illegal HD so that the end timing is unclear until the next VD|
||||||(By generating a VBP interrupt at the VD input timing, capture fail can be|
||||||announced.)|
||||||When a VBP interrupt occurs, a capture end interrupt (CPE bit in CETCR)|
||||||does not occur and the image of that frame is not captured correctly. Though a|
||||||capture end interrupt (CPE bit) will occur on rare occasions, it should be|
||||||ignored in this case. Capturing cannot be performed until the next VD (even if|
||||||the CE bit (capture reservation signal) in CAPSR is 1, capturing does not|
||||||start).|
||||||In the case of condition 2, instead of waiting for a VBP interrupt to occur,|
||||||execute a software reset (CPKIL bit in CAPSR) to stop capturing and then|
||||||restart capturing. In this case, since capture operation is terminated without|
||||||waiting for the next VD, a VBP interrupt does not occur and capturing can be|
||||||performed from the next VD.|
|19||—|0|R|Reserved|
||||||This bit is always read as 0. The write value should always be 0.|
|18||IGVS|0|R/W|This bit is used for an interrupt generated when the number of VD cycles set in|
||||||CMCYR differ from the number of VD cycles input from an external module.|
||||||This bit is set to 1 when there is an illegal VD input from an external module.|
||||||This bit is set to 1 when the number of HD cycles for the VD input to the CEU|
||||||differs from the value set in the VCYL bits in CMCYR. Note however that when|
||||||the VCYL bits are cleared to 0, this interrupt does not occur.|
|17||IGHS|0|R/W|This bit is used for an interrupt generated when the number of HD cycles set in|
||||||CMCYR differ from the number of HD cycles input from an external module.|
||||||This bit is set to 1 when there is an illegal HD input from an external module.|
||||||This bit is set to 1 when the number of clock cycles for the HD input to the|
||||||CEU differs from the value set in the HCYL bits in CMCYR. Note however that|
||||||when the HCYL bits are cleared to 0, this interrupt does not occur.|
|16||CDTOF|0|R/W|This bit is used for an interrupt indicating that data overflowed in the CRAM of|
||||||the write buffer.|
||||||Since data is input at realtime from an external module in capture operations,|
||||||the frame image is overwritten unless the captured data is transferred from the|
||||||CEU internal buffer to the memory at a certain or higher transfer rate. This bit|
||||||is set to 1 when writing the data in the CRAM of the CEU internal write buffer|
||||||to the bus is not performed within time and data has overflowed.|
|15||CPBE4|0|R/W|This bit is used for an interrupt indicating that writing to CDBYR2 and|
||||||CDBCR2 in a bundle write has finished.|
||||||This interrupt is output when the last captured data has been transferred and|
||||||the end notification received, regardless of the next HD input.|
||||||This bit is set to 1 when data for the number of lines set in CBDSR has been|
||||||captured and the last data transfer to the bus has completed.|
||||||However, this interrupt does not occur when the last captured data in a bundle|
||||||write is the last captured data of a frame (field).|
|14||CPBE3|0|R/W|This bit is used for an interrupt indicating that writing to CDBYR and CDBCR in|
||||||a bundle write has finished.|
||||||This interrupt is output when the last captured data has been transferred and|
||||||the end notification received, regardless of the next HD input.|
||||||This bit is set to 1 when data for the number of lines set in CBDSR has been|
||||||captured and the last data transfer to the bus has completed.|
||||||However, this interrupt does not occur when the last captured data in a bundle|
||||||write is the last captured data of a frame (field).|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|13|CPBE2|0|R/W|This bit is used for an interrupt indicating that writing to CDAYR2 and CDACR2|
|||||in a bundle write has finished.|
|||||This interrupt is output when the last captured data has been transferred and|
|||||the end notification received, regardless of the next HD input.|
|||||This bit is set to 1 when data for the number of lines (number of bytes in data|
|||||enable fetch) set in CBDSR has been captured and the last data transfer to|
|||||the bus has completed.|
|||||However, in image capture or data synchronous fetch, this interrupt does not|
|||||occur when the last captured data in a bundle write is the last captured data of|
|||||a frame (field).|
|12|CPBE1|0|R/W|This bit is used for an interrupt indicating that writing to CDAYR and CDACR in|
|||||a bundle write has finished.|
|||||This interrupt is output when the last captured data has been transferred and|
|||||the end notification received, regardless of the next HD input.|
|||||This bit is set to 1 when data for the number of lines (number of bytes in data|
|||||enable fetch) set in CBDSR has been captured and the last data transfer to|
|||||the bus has completed.|
|||||However, in image capture or data synchronous fetch, this interrupt does not|
|||||occur when the last captured data in a bundle write is the last captured data of|
|||||a frame (field).|
|11, 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9|VD|Undefined|R/W|This bit is used for an interrupt indicating that VD (vertical sync signal) was|
|||||input from an external module.|
|||||In data enable fetch mode, this bit is set to 1 when a VD input from an external|
|||||module is detected.|
|||||In image capture mode and data synchronous fetch mode, this module|
|||||generates a VD interrupt in response to the first detection of the active level of|
|||||HD following detection of the active level of VD from an external module. Note|
|||||that, when VD and HD are asserted and detected at the same time, this|
|||||module generates a VD interrupt at that time. Immediately after the VDPOL bit|
|||||in CAMCR is modified, a pseudo VD is input and this bit is set to 1. The VD|
|||||interrupt after the VDPOL bit is modified should be ignored.|
|8|HD|Undefined|R/W|This bit is used for an interrupt indicating that HD (horizontal sync signal) was|
|||||input from an external module.|
|||||This bit is set to 1 when an HD input from an external module is detected.|
|||||Immediately after the HDPOL bit in CAMCR is modified, a pseudo HD is input|
|||||and this bit is set to 1. The HD interrupt after the HDPOL bit is modified should|
|||||be ignored.|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|IGRW|0|R/W|This bit is used for an interrupt indicating that during capturing, access was|
|||||attempted to a register to which writing during operation is prohibited.|
|||||Among the CEU registers, writing during capturing is prohibited for some|
|||||registers. Table 36.10 shows which registers can/cannot be written to during|
|||||capturing. This bit is set to 1 when a register to which writing during capturing|
|||||is prohibited has been written to.|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1|CFE|0|R/W|This bit is used for an interrupt indicating that capturing of one field from an|
|||||external module has finished.|
|||||This interrupt is output when the last captured data has been transferred and|
|||||the end notification received, regardless of the next VD input (see Figure|
|||||36.46).|
|||||This interrupt occurs only in both-field capture mode.|
|0|CPE|0|R/W|This bit is used for an interrupt indicating that capturing of one frame from an|
|||||external module has finished.|
|||||This interrupt is output when the last captured data has been transferred and|
|||||the end notification received, regardless of the next VD input.|
|||||This interrupt indicates that capturing of one frame has finished. This bit is set|
|||||to 1 when the image of the size set in CAPWR is captured and the last data|
|||||transfer to the bus finished (see Figure 36.47).|

**Table 36.10 Registers that Can/Cannot Be Modified during Capturing**

||**Modification during**|
|---|---|
|**Register Name**|**Capturing**|
|CAPSR|Possible|
|CAPCR|Prohibited|
|CAMCR|Prohibited|
|CMCYR|Prohibited|
|CAMOR|Possible|
|CAPWR|Possible|
|CAIFR|Prohibited|
|CRCNTR|Possible|
|CRCMPR|Prohibited|
|CFLCR|Possible|
|CFSZR|Possible|
|CDWDR|Possible|
|CDAYR|Possible|
|CDACR|Possible|
|CDBYR|Possible|
|CDBCR|Possible|
|CBDSR|Possible|
|CFWCR|Possible|
|CLFCR|Possible|
|CDOCR|Possible|
|CEIER|Possible|
|CETCR|Possible|
|CSTSR|Prohibited|
|CDSSR|Prohibited|
|CDAYR2|Possible|
|CDACR2|Possible|
|CDBYR2|Possible|
|CDBCR2|Possible|

**==> picture [354 x 130] intentionally omitted <==**

**----- Start of picture text -----**<br>
One-field<br>capture end<br>interrupt<br>Capture start CETCR.CFE = 1 Capture start<br>VIO_VD<br>VIO_HD<br>VIO_FLD<br>VIO_D7<br>to VIO_D0<br>Capture<br>**----- End of picture text -----**<br>

**Figure 36.46 CFE Generation Timing**

**==> picture [352 x 114] intentionally omitted <==**

**----- Start of picture text -----**<br>
One-frame<br>capture end<br>interrupt<br>Capture start CETCR.CPE = 1 Capture start<br>VIO_VD<br>VIO_HD<br>VIO_D7<br>to VIO_D0<br>Capture<br>**----- End of picture text -----**<br>

**Figure 36.47 CPE Generation Timing**

## 36.4.23 Capture Status Register (CSTSR)

CSTSR indicates the internal status of the CEU. CSTSR differs from CETCR in that no interrupt is generated for the events indicated in CSTSR.

The CEU operating/halt state can be confirmed using CSTSR. To confirm the halt state of the CEU, make sure that the status bit (bit 0) indicating that the CEU is operating is cleared to 0 for sure.

||||Bit:|Bit:|31|30|29||28|27||26|25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||—|—|—||—|—||—|—<br>CRST<br>—<br>—<br>—|—|—|—|—|CP<br>FLD||
|||Initial|value:||0|0|0||0|0||0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R|R||R|R||R|R<br>R<br>R<br>R<br>R|R|R|R|R|R||
||||Bit:||15|14|13||12|11||10|9<br>8<br>7<br>6<br>5|4|3|2|1|0||
|||||||||||||||||||CP||
||||||—|—|—||—|—||—|—<br>—<br>—<br>—<br>—|—|—|—|—|TON||
|||Initial|value:||0|0|0||0|0||0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:||R|R|R||R|R||R|R<br>R<br>R<br>R<br>R|R|R|R|R|R||
||||||||**Initial**|||||||||||||
|**Bit**|||**Bit**||**Name**||**Value**|||**R/W**|||**Description**|||||||
|31|to|25|—||||All 0|||R|||Reserved|||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|24|||CRST||||0|||R|||Indicates which register plane is currently||used.|||||
||||||||||||||0: Plane A of the register is being used|||||||
||||||||||||||1: Plane B of the register is being used|||||||
|23|to|17|—||||All 0|||R|||Reserved|||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|16|||CPFLD||||0|||R|||Indicates which field is being captured.|||||||
||||||||||||||0: Bottom field is being captured|||||||
||||||||||||||1: Top field is being captured|||||||
|15|to|1|—||||All 0|||R|||Reserved|||||||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||||||
|0|||CPTON||||0|||R|||Indicates that the CEU is operating.|||||||
||||||||||||||This bit retains 1 during the period that starts from the internal VD at capture|||||||
||||||||||||||start and ends when a one-frame capture end interrupt occurs.|||||Figure|36.48|
||||||||||||||shows the CEU operating period.|||||||

**==> picture [325 x 148] intentionally omitted <==**

**----- Start of picture text -----**<br>
Interrupt clear Interrupt clear<br>System clock<br>CETCR.VD<br>(VD interrupt)<br>CETCR.CPE<br>(one-frame capture<br>end interrupt)<br>CSTSR.CPTON<br>Operating Halted<br>CAPSR.CE<br>CAPSR.CE write CAPSR.CE write<br>**----- End of picture text -----**<br>

**Figure 36.48 Operating Status during Capturing**

## 36.4.24 Capture Data Size Register (CDSSR)

CDSSR indicates the size of data written to the memory in data enable fetch. As this register indicates a correct value at the end of capture, confirm this register when capture is completed.

||||Bit:|31|30|29|28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||CDSS[31:16]|||
|||Initial|value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|
||||R/W:|R|R|R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|R|R|
||||Bit:|15|14|13|12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2|1|0|
|||||||||||CDSS[15:0]|||
|||Initial|value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0|0|
||||R/W:|R|R|R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|R|R|
|||||||**Initial**|||||||
|**Bit**|||**Bit**|**Name**||**Value**||**R/W**||**Description**|||
|31|to|0|CDSS[31:0]|||H'0000||R||Indicate the size of data written to the memory in data enable fetch.|||
|||||||0000||||In a bundle write, size of data written to the selected address||at the end of|
|||||||||||one-frame capture is indicated. In a bundle write, as soon as||the number of|
|||||||||||bytes specified by CBDSR is transferred to the bus, address to which data|||
|||||||||||is written is switched.|||
|||||||||||Therefore, if one-frame capture is completed at the same time as a bundle|||
|||||||||||write is completed, this register indicates H'0000 0000.|||
|||||||||||Figure 36.49 and Figure 36.50 show the overall timing of the CDSSR|||
|||||||||||operation in a bundle write.|||

**==> picture [297 x 137] intentionally omitted <==**

**----- Start of picture text -----**<br>
CBDSR<br>Captured data<br>Address CDAYR CDAYR2 CDAYR CDAYR2 CDAYR<br>CETCR.CPBE1<br>CETCR.CPBE2<br>CETCR.CPE<br>CDSSR H'00000000<br>Indicates data size written to CDAYR<br>**----- End of picture text -----**<br>

**Figure 36.49 Overall Timing of CDSSR Operation in Bundle Write (When Bundle Write End and Capture End Coincide)**

|Captured data<br>Address<br>CETCR.CPBE1<br>CETCR.CPBE2<br>CETCR.CPE<br>CDSSR|CDAYR<br>CBDSR<br>CDAYR2<br>CDAYR<br>CDAYR2<br>CDAYR<br>Indicates data size written to CDAYR<br>H'00000200<br>H'00000200|
|---|---|

**Figure 36.50 Overall Timing of CDSSR Operation in Bundle Write (When Bundle Write End and Capture End Do Not Coincide)**

## 36.4.25 Capture Data Address Y Register 2 (CDAYR2)

CDAYR2 specifies the address for the luminance (Y) component used in a bundle write and the address for data storage in a bundle write in data fetch. CDAYR2 is used only in a bundle write.

CDAYR2 specifies the address where the Y component of the captured data is to be stored in frame image capture or one-field image capture, the address where the Y component of the captured top field is to be stored in both-field image capture, and the address where data is to be stored in data fetch. The CEU separates the captured image data into the luminance component data (Y) and the chrominance component data (C), and stores them in the memory via the bus. In frame image capture or one-field image capture, set the start address of the memory area where the Y component of the captured data is to be stored by CDAYR2. In both-field image capture, set the start address of the memory area where the Y component of the captured top-field image is to be stored by CDAYR2. In data fetch, set the start address of the memory area to be used for data storage.

The address specified by this register must be in 32-bit units. As the setting is in 4-pixel units, the lower two bits are always fixed to 0.

|||Bit:|31|30|29|28|27|26|25<br>24<br>23|22<br>21<br>20<br>19<br>18<br>17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||CAYR2[31:16]|||
||Initial value:||0|0|0|0|0|0|0<br>0<br>0|0<br>0<br>0<br>0<br>0<br>0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|
|||Bit:|15|14|13|12|11|10|9<br>8<br>7|6<br>5<br>4<br>3<br>2<br>1|0|
||||||||||CAYR2[15:0]|||
||Initial value:||0|0|0|0|0|0|0<br>0<br>0|0<br>0<br>0<br>0<br>0<br>0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R|R|
|**Bit**||**Bit Name**|||**Initial Value**||**R/W**||**Description**|||
|31 to|2|CAYR2[31:2]|||H'0000 0000||R/W||Frame image capture: These bits set the address for storing||the Y|
|1, 0||CAYR2[1:0]|||||R||component data of|the captured data (4-pixel units*1).||
||||||||||One-field image capture: These bits set the address for storing the Y|||
||||||||||component data of|the captured data (4-pixel units*1).||
||||||||||Both-field image capture: These bits set the address for storing the Y|||
||||||||||component data of|the captured top-field data (4-pixel units*1).||
||||||||||Data synchronous fetch: These bits set the address for storing data (4-|||
||||||||||byte units*2).|||
||||||||||Dana enable fetch: These bits set the address for storing data (32-byte|||
||||||||||units).|||
||||||||||Note 1. 8-pixel units|when writing to other than the on-chip RAM||
||||||||||Note 2. 8-byte units|when writing to other than the on-chip RAM||

Set the address of the starting point of the memory area where the Y component of the captured image is to be stored in this register, as shown in Figure 36.51 .

- Frame image capture: Set the address of the starting point of the memory area where the Y component of the captured image is to be stored.

- One-field image capture: Set the address of the starting point of the memory area where the Y component of the captured image is to be stored.

- Both-field image capture: Set the address of the starting point of the memory area where the Y component of the captured top-field image is to be stored.

**==> picture [360 x 152] intentionally omitted <==**

**----- Start of picture text -----**<br>
CDAYR2<br>CDAYR2<br>(start address for storage)<br>CEU destination image<br>Memory image Memory<br>Y memory area<br>C memory area<br>**----- End of picture text -----**<br>

**Figure 36.51 Relationship between Captured Image and Y Component Memory Area**

## 36.4.26 Capture Data Address C Register 2 (CDACR2)

CDACR2 specifies the address for the chrominance (C) component used in a bundle write. CDACR2 is used only in a bundle write.

CDACR2 specifies the address where the C component of the captured data is to be stored in frame image capture or one-field image capture, and the address where the C component of the captured top field is to be stored in both-field image capture. The CEU separates the captured image data into the luminance component data (Y) and the chrominance component data (C), and stores them in the memory via the bus. In frame image capture or one-field image capture, set the start address of the memory area where the C component of the captured data is to be stored by CDACR2. In bothfield image capture, set the start address of the memory area where the C component of the captured top-field image is to be stored by CDACR2. CDACR2 is not used in data fetch.

The address specified by this register must be in 32-bit units. As the setting is in 4-pixel units, the lower two bits are always fixed to 0.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||CACR2[31:16]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||CACR2[15:0]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|

|**Bit**|**Bit Name**|**Initial Value**|**R/W**|**Description**|
|---|---|---|---|---|
|31 to 2|CACR2[31:2]|H'0000 0000|R/W|Frame image capture: These bits set the address for storing the|
|1, 0|CACR2[1:0]||R|C component data of the captured data (4-pixel units*).|
|||||One-field image capture: These bits set the address for storing|
|||||the C component data of the captured data (4-pixel units*).|
|||||Both-field image capture: These bits set the address for storing|
|||||the C component data of the captured top-field data (4-pixel|
|||||units*).|
|||||Note: * 8-pixel units when writing to other than the on-chip RAM|

In this register, set the address of the starting point of the memory area where the captured data is to be stored in a bundle write, as shown in Figure 36.52 . The C component has an output data format as shown in Figure 36.53 , and is saved in the memory in this format.

- Frame image capture: Set the address of the starting point of the memory area where the C component of the captured image is to be stored.

- One-field image capture: Set the address of the starting point of the memory area where the C component of the captured image is to be stored.

- Both-field image capture: Set the address of the starting point of the memory area where the C component of the captured top-field image is to be stored.

The C component has an output data format as shown in Figure 36.52 , and is saved in the memory in this format.

**==> picture [360 x 142] intentionally omitted <==**

**----- Start of picture text -----**<br>
CDACR2 CDACR2<br>CEU destination image<br>Memory image Memory<br>Y memory area<br>C memory area<br>**----- End of picture text -----**<br>

**Figure 36.52 Relationship between Captured Image and C Component Memory Area**

**==> picture [141 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
Cb0 Cr0 Cb2 Cr2<br>**----- End of picture text -----**<br>

**Figure 36.53 Image of Storing C Components in Memory**

## 36.4.27 Capture Data Bottom-Field Address Y Register 2 (CDBYR2)

CDBYR2 specifies the address for the luminance (Y) component of the bottom field used in a bundle write. CDBYR2 is used only in a bundle write.

CDBYR2 specifies the address where the Y component of the captured bottom-field data is to be stored in both-field image capture. The CEU separates the captured image data into the luminance component data (Y) and the chrominance component data (C), and stores them in the memory via the bus. Set the start address of the memory area where the Y component of the bottom-field image captured in both-field image capture is to be stored by CDBYR2. CDBYR2 is not used in frame image capture, one-field image capture, or data fetch.

The address specified by this register must be in 32-bit units. As the setting is in 4-pixel units, the lower two bits are always fixed to 0.

|||Bit:|31|30|29|28|27|26|25|24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||CBYR2[31:16]||||||||
||Initial|value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||Bit:|15|14|13|12|11|10|9|8<br>7|6|5|4|3|2|1|0|
|||||||||||CBYR2[15:0]||||||||
||Initial|value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R|R|
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**||||||||
|31 to|2|CBYR2[31:2]|||H'0000 0000|||R/W||These bits set the||address for storing|||the Y component data of the|||
|1, 0||CBYR2[1:0]||||||R||captured bottom-field data (4-pixel units*).||||||||
|||||||||||Note: * 8-pixel units when|||writing|to other than||the on-chip RAM||

In this register, set the address of the starting point of the memory area where the Y component of the captured bottomfield image is to be stored in a bundle write, as shown in Figure 36.54 .

**==> picture [368 x 144] intentionally omitted <==**

**----- Start of picture text -----**<br>
CEU captured bottom-field  CDBYR2 CDBYR2<br>destination image<br>Memory image Memory<br>Y memory area<br>C memory area<br>**----- End of picture text -----**<br>

**Figure 36.54 Relationship between Captured Bottom-Field Image and Y Component Memory Area**

## 36.4.28 Capture Data Bottom-Field Address C Register 2 (CDBCR2)

CDBCR2 specifies the address for the chrominance (C) component of the bottom field used in a bundle write. CDBCR2 is used only in a bundle write.

CDBCR2 specifies the address where the C component of the captured bottom-field data is to be stored in both-field image capture. The CEU separates the captured image data into the luminance component data (Y) and the chrominance component data (C), and stores them in the memory via the bus. Set the start address of the memory area where the C component of the bottom-field image captured in both-field image capture is to be stored by CDBCR2. CDBCR2 is not used in frame image capture, one-field image capture, or data fetch.

The address specified by this register must be in 32-bit units. As the setting is in 4-pixel units, the lower two bits are always fixed to 0.

|||Bit:|31|30|29|28|27|26|25|24<br>23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||CBCR2[31:16]||||||||
||Initial|value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||Bit:|15|14|13|12|11|10|9|8<br>7|6|5|4|3|2|1|0|
|||||||||||CBCR2[15:0]||||||||
||Initial|value:|0|0|0|0|0|0|0|0<br>0|0|0|0|0|0|0|0|
|||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R|R|
|**Bit**||**Bit Name**|||**Initial Value**|||**R/W**||**Description**||||||||
|31 to|2|CBCR2[31:2]|||H'0000 0000|||R/W||These bits set the||address for storing|||the C component data of the|||
|1, 0||CBCR2[1:0]||||||R||captured bottom-field data (4-pixel units*).||||||||
|||||||||||Note: * 8-pixel units when|||writing|to other than||the on-chip RAM||

In this register, set the address of the starting point of the memory area where the C component of the captured bottomfield image is to be stored in a bundle write, as shown in Figure 36.55 . The C component has an output data format as shown in Figure 36.56 , and is saved in the memory in this format.

**==> picture [370 x 143] intentionally omitted <==**

**----- Start of picture text -----**<br>
CEU captured bottom-field  CDBCR2 CDBCR2<br>destination image<br>Memory image Memory<br>Y memory area<br>C memory area<br>**----- End of picture text -----**<br>

**Figure 36.55 Relationship between Captured Bottom-Field Image and C Component Memory Area**

**==> picture [142 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
Cb0 Cr0 Cb2 Cr2<br>**----- End of picture text -----**<br>

**Figure 36.56 Image of Storing C Components in Memory**

## 36.5 Usage Notes for CEU

## 36.5.1 Conditions for Connection to an External Module

## (1) Clock Frequency

The external input clock should have a frequency at most the same as the CEU operating clock frequency (Bφ), with jitter on both sides included.

CEU operating clock frequency (Bφ) ≥ External input clock frequency

## (2) Blanking Period

The period from the last valid pixel in each line to the next horizontal sync signal HD must be at least 20 cycles.

## (3) Fixed Period of Field Identification Signal

The field identification signal FLD should be fixed for at least 1-HD period since a VD input.

## 36.5.2 Restrictions on Input/Output Functions

Table 36.11 lists the restrictions regarding the CEU input/output functions.

## **Table 36.11 Restrictions on CEU Input/Output Functions**

|**Item**|**Restrictions**|
|---|---|
|External module interface|The operating clock of the external module (VIO_CLK) should always have a frequency at most the same<br>as that of the CEU operating clock (Bφ), with jitter on both sides included.|
||Selecting the interface, or modifying the frequency of the external module operating clock or HD/VD<br>polarity must be done when capture operations are halted for sure.|
||Specify the capture horizontal size in image capture in 8-cycle units*.<br>Note: * 16-cycle units when writing to other than the on-chip RAM|
||Specify the capture horizontal size in data fetch in 4-cycle units*.<br>Note: * 8-cycle units when writing to other than the on-chip RAM|
||The capture vertical size must be specified in 4-line units.|
||The maximum number of cycles in the horizontal sync signal period should be 16,375 cycles of external<br>input clock.|
||The maximum number of lines (HD count) in the vertical sync signal should be 16,382 lines.|
||The minimum number of captured pixels should be sub-QCIF (128 × 96).|
||The maximum number of captured pixels should be 5 megapixels (2,560 × 1,920).|
||Captured size in data enable fetch<br>Maximum: 6 Mbytes (2,048 × 1,536 × 2)<br>Minimum: 16 bytes|
|Memory output|The output address must be specified in 32-bit units*.<br>Note: * 64-bit units when writing to other than the on-chip RAM|
||The horizontal size of the destination image (memory) must be specified in 4-pixel units*.<br>Note: * 8-pixel units when writing to other than the on-chip RAM|
||The number of horizontal output pixels (= horizontal clipping size) must be specified in 4-pixel units*.<br>Note: * 8-pixel units when writing to other than the on-chip RAM|
||The number of vertical output lines (HD) (= vertical clipping size) must be specified in 4-line (HD) units.|
||In data enable fetch bundle write, the output address must be specified in 32-byte units.|
|Internal processing|The filter clipping size must be specified as a value equal to or lower than the actual output size of the<br>filter.|

## 36.5.3 Cooperation with Video Display Controller 5

Since the input data are written to the memory separately as Y data and CbCr data in image capture mode, the captured data cannot be displayed in the video display controller 5.

## 36.5.4 Software Reset

For transitions to the software reset state by the CPKIL bit in the CAPSR register, see section 42.3.6, Software Reset . However, where the procedure refers to the SRST bit, read this as the CPKIL bit in the CAPSR register.
