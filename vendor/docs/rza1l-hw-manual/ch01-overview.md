# 1. Overview

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 52–78. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group

Renesas microprocessor

## 1. Overview

## 1.1 Features of This LSI

This LSI is a single-chip microcontroller that includes an Arm Cortex[®] -A9 processor along with the integrated peripheral functions required to configure a system.

This LSI includes a 32-Kbyte L1 instruction cache, a 32-Kbyte L1 data cache, and a 128-Kbyte L2 cache. This LSI also includes on-chip peripheral functions necessary for system configuration, such as a 3-Mbyte (RZ/A1L and RZ/A1LU) or 2-Mbyte (RZ/A1LC) large-capacity RAM (128 Kbytes are shared by the data-retention RAM), data-retention RAM, multi-function timer pulse unit 2, OS timer, realtime clock, serial communication interface with FIFO, serial communication interface, I[2] C bus interface, serial sound interface, media local bus (RZ/A1L only), SCUX, CAN interface, IEBus™* controller (RZ/A1L only), Renesas SPDIF interface, Renesas serial peripheral interface, SPI multi I/O bus controller, CD-ROM decoder (RZ/A1L only), A/D converter, LIN interface (RZ/A1L only), Ethernet controller, EthernetAVB (RZ/A1LU only), USB 2.0 host/function, video display controller 5, JPEG codec unit (RZ/A1LU only), capture engine unit, SD host interface, MMC host interface, interrupt controller modules, and general I/O ports.

## The features of this LSI are listed in Table 1.1 .

Note: * IEBus (Inter Equipment Bus) is a trademark of Renesas Electronics Corporation.

**Table 1.1 Features of RZ/A1L, RZ/A1LU, and RZ/A1LC**

|**Table 1.1**<br>**Features**|**of RZ/A1L, RZ/A1LU, and RZ/A1LC**||
|---|---|---|
|**Items**|**Specification**||
|CPU|Arm Cortex-A9 processor||
||Maximum operating frequency: 400 MHz||
||Instruction cache size: 32 Kbytes||
||Data cache size: 32 Kbytes (write-back algorithm)||
||TLB entries: 128 entries||
||Jazelle®architecture extension: Full implementation||
||Media processing engine with NEONTMtechnology||
|L2 cache memory|Arm CoreLink™ Level 2 Cache Controller L2C-310||
||Operating frequency: 133 MHz||
||Cache size: 128 Kbytes||
|Interrupt controller|Arm PrimeCell®Generic Interrupt Controller (PL390)||
||External interrupt pins (NMI, IRQ7 to IRQ0, and TINT121 to TINT0)||
||On-chip peripheral interrupts: Priority level set for each module||
||32 priority levels available||
|Bus state controller|Address space divided into six areas (0 to 5), each a maximum of 64 Mbytes||
||The following features settable for each area independently||
||—Bus size (8, 16, or 32 bits): Available sizes depend on the area.||
||—Number of access wait cycles (different wait cycles can be specified for|read and write access|
||cycles in some areas)||
||—Idle wait cycle insertion (between the same area access cycles or different area access cycles)||
||—Specifying the memory to be connected to each area enables direct connection to SRAM, SRAM||
||with byte selection, SDRAM, and burst ROM (clocked synchronous or asynchronous). The||
||address/data multiplexed I/O(MPX)interface is also available.||
||Outputs a chip select signal (CS0<br>to CS5<br>) according to the target area (CS<br>|assert or negate timing|
||can be selected by software)||
||SDRAM refresh||
||Auto refresh or self refresh mode selectable||
||SDRAM burst access||
|Direct memory access|Sixteen channels; external requests are available for one of them.||
|controller|Can be activated by on-chip peripheral modules.||
||A specific DMA transfer interval can be specified to adjust the bus occupancy.||
||Link mode (DMA transfer under descriptor control) supported||
||Transfer information can be automatically reloaded.||
|Clock pulse generator|Clock mode: Input clock can be selected from external input (EXTAL or USB_X1) or crystal||
||resonator.||
||Input clock can be multiplied by 32 (max.) by the internal PLL circuit.||
||Peak values of EMI noise can be reduced by the on-chip SSCG circuit.||
||Five types of clocks generated:||
||—CPU clock (Iφ): Maximum 400.00 MHz||
||—Internal bus clock (Bφ): Maximum 133.33 MHz||
||—Peripheral clock 1 (P1φ): Maximum 66.67 MHz||
||—Peripheral clock 0 (P0φ): Maximum 33.33 MHz||
|Watchdog timer|On-chip one-channel watchdog timer||
||A counter overflow can reset the LSI.||
|Power-down modes|Four power-down modes provided to reduce the power consumption in this|LSI|
||—Sleep mode||
||—Software standby mode||
||—Deep standby mode||
||—Module standby mode||

|**Items**|**Specification**|
|---|---|
|Multi-function timer pulse unit|Maximum 16 lines of pulse inputs/outputs based on five channels of 16-bit timers|
|2|18 output compare and input capture registers|
||Input capture function|
||Pulse output modes|
||Toggle, PWM, complementary PWM, and reset-synchronized PWM modes|
||Synchronization of multiple counters|
||Complementary PWM output mode|
||—Non-overlapping waveforms output for 3-phase inverter control|
||—Automatic dead time setting|
||—0% to 100% PWM duty value specifiable|
||—A/D converter start request delaying function|
||—Interrupt skipping at crest or trough|
||Reset-synchronized PWM mode|
||Three-phase PWM waveforms in positive and negative phases can be output with a required duty|
||value.|
||Phase counting mode|
||Two-phase encoder pulse counting available|
|OS timer|Two-channel 32-bit counters|
||Two operating modes:|
||—Interval timer mode|
||—Free-running comparison mode|
||DMA transfer request or interrupt request can be issued when a compare match occurs.|
|Realtime clock|Internal clock, calendar function, alarm function|
||Interrupts can be generated at intervals of 1/64 s by the 32.768-kHz on-chip crystal oscillator.|
|Serial communication|Five channels|
|interface with FIFO|Clock synchronous mode or asynchronous mode selectable|
||Simultaneous transmission and reception (full-duplex communication) supported|
||Dedicated baud rate generator|
||Separate 16-byte FIFO registers for transmission and reception|
||Modem control function (channels 0 to 2 in asynchronous mode)|
|Serial communication|Two channels|
|interface|Clock synchronous mode, asynchronous mode, or smart card interface mode is selectable.|
||Simultaneous transmission and reception (full-duplex communication) supported|
||Dedicated baud rate generator|
||LSB first/MSB first selectable|
||Modem control function|
||Encoding and decoding of IrDA communications waveforms in accord with version 1.0 of the IrDA|
||standard (on channel 0)|
|Renesas serial peripheral|Three channels|
|interface|SPI operation|
||Master mode and slave mode selectable|
||Programmable bit length, clock polarity, and clock phase can be selected.|
||Consecutive transfers|
||MSB first/LSB first selectable|
||Maximum transfer rate: 33.33 Mbps|
|SPI multi I/O bus controller|One channel|
||Up to two serial flash memories with multiple I/O bus sizes (single/dual/quad) can be connected.|
||External address space read mode (built-in read cache)|
||SPI operating mode|
||Clock polarity and clock phase can be selected.|
||MSB first/LSB first selectable|
||Maximum transfer rate:|
||533.33Mbps (SDR transfer, with two serial flash memories connected)|
||1066.66Mbps (DDR transfer, with two serial flash memories connected) (RZ/A1LU only)|
|I2C bus interface|Four channels|
||Master mode and slave mode supported|
||Support for 7-bit and 10-bit slave address formats|
||Support for multi-master operation|
||Timeout detection|

|**Items**|**Specification**|
|---|---|
|Serial sound interface|Four-channel bidirectional serial transfer|
||Duplex communication (channels 0, 1, and 3)|
||Support of various serial audio formats|
||Support of master and slave functions|
||Generation of programmable word clock and bit clock|
||Multi-channel formats|
||Support of 8, 16, 18, 20, 22, 24, and 32-bit data formats|
||Support of eight-stage FIFO for transmission and reception|
||Support of TDM mode|
||Support of WS continue mode in which the SSIWS signal is not stopped.|
||Support of direct transfer to the SCUX module|
||A change of the sampling frequency can be detected.|
|Media local bus|Conforms with version 2.0 of the MediaLB standard.  Data transfer at up to 50 Mbps is possible.|
|(RZ/A1L only)||
|SCUX|Sampling rate conversion|
||—Asynchronous or synchronous sampling rate conversion is possible.|
||—Sampling rate (synchronous mode)|
||Note: The selectable sampling rates depend on the number of used channels and rate ratio.|
||Input [kHz]: 8, 11.025, 12, 16, 22.05, 24, 32, 44.1, 48, 64, 88.2, or 96 is selectable.|
||Output [kHz]: 8, 16, 24, 44.1, 48, or 96 is selectable.|
||—Sampling rate (asynchronous mode)|
||Note: The selectable sampling rates depend on the number of used channels and rate ratio.|
||Input/output [kHz]: 1 to 96|
||—Data format: 16 or 24 bits|
||Digital volume and mute functions|
||—The digital volume can be set within the range from a multiple of 0 to 8 (−120 to 18 dB)|
||—Volume ramping supports soft mute, fade-in, and fade-out.|
||—The zero crossing mute function can apply muting at zero-crossing points.|
||Mixer|
||—Data of two to four source systems can be mixed (added together) into one system.|
||—The ratio to add the sources can be set.|
||Direct transfer to the serial sound interface module is supported.|
|CAN interface|Two channels|
||ISO11898-1 compliant|
||Message buffer:|
||—Up to 64 2-channel receive message buffers: shared among all channels.|
||—16 transmit message buffers per channel|
|IEBusTMcontroller|Conforms with the IEBus protocol (communication modes 1 and 2).|
|(RZ/A1L only)|Transfer rates: approximately 18 kbps (in communication mode 1),|
||approximately 27 kbps (in communication mode 2)|
||Maximum numbers of bytes for transfer: 32 bytes/frame (in communication mode 1),|
||128 bytes/frame (in communication mode 2)|
||Operating clock: 8 MHz|
||Note: Input of peripheral clock 0 (P0φ) running at 32 MHz is required.|
|Renesas SPDIF interface|Support of IEC60958 standard (stereo and consumer use modes only)|
||Sampling frequencies of 32 kHz, 44.1 kHz, and 48 kHz|
||Audio word sizes of 16 to 24 bits per sample|
||Biphase mark encoding|
||Double buffered data|
||Parity encoded serial data|
||Simultaneous transmit and receive|
||Receiver autodetects IEC 61937 compressed mode data.|

|**Items**|**Specification**|
|---|---|
|CD-ROM decoder|Support of five formats: Mode 0, mode 1, mode 2, mode 2 form 1, and mode 2 form 2|
|(RZ/A1L only)|Sync codes detection and protection|
||(Protection: When a sync code is not detected, it is automatically inserted.)|
||Descrambling|
||ECC correction|
||—P, Q, PQ, and QP correction|
||—PQ or QP correction can be repeated up to three times.|
||EDC check|
||Performed before and after ECC|
||Mode and form are automatically detected.|
||Link sectors are automatically detected.|
||Buffering data control|
||Buffering CD-ROM data including Sync code is transferred in specified format, after the data is|
||descrambled, corrected by ECC, and checked by EDC.|
|LIN interface (RZ/A1L only)|Conforms with revisions 1.3, 2.0, 2.1, and 2.2 of the LIN protocol and SAEJ 2062.|
||Master mode selectable|
|Ethernet controller|Conforms with the Ethernet or the IEEE802.3 MAC (Media Access Control) layer standard|
||MAC function|
||Constructs/deconstructs data frames (frame format conforming to IEEE802.3, 2000 Edition)|
||Supports transfer at 10 and 100 Mbps|
||Supports full-duplex mode|
||Flow control conforming to IEEE802.3x|
||Supports an MII (Media Independent Interface) for connection to a PHY interface in conformance|
||with IEEE 802.3|
||Upward protocol support (checksum) function|
||E-DMAC (Direct Memory Access Controller for Ethernet controller) function|
|EthernetAVB (RZ/A1LU only)|Conforms with the Ethernet or the IEEE802.3 MAC (Media Access Control) layer standard|
||MAC function|
||Constructs/deconstructs data frames (frame format conforming to IEEE802.3, 2000 Edition)|
||Supports transfer at 100 Mbps|
||Supports full-duplex mode|
||Flow control conforming to IEEE802.3x|
||Supports an MII (Media Independent Interface) for connection to a PHY interface in conformance|
||with IEEE 802.3|
||Upward protocol support (checksum) function|
||AVB-DMAC (DMAC dedicated to EthernetAVB) function|
||AVB-DMAC conforms with the following 3 standards; IEEE802.1AS (Clock Synchronization|
||Protocol), IEEE802.1Qav (Realtime Transfer Protocol) and IEEE802.1Qat (Bandwidth Reservation|
||Protocol)|
|USB 2.0 host/function module|Two channels|
||Conforms to the Universal Serial Bus Specification Revision 2.0|
||480-Mbps, 12-Mbps, and 1.5-Mbps transfer rates provided (host mode)|
||480-Mbps and 12-Mbps transfer rates provided (function mode)|
||On-chip 8-Kbyte RAM as communication buffers|
|Video display controller 5|Video input interface|
||BT601, BT656 format (NTSC/PAL) input: Input clock: 27 MHz/54 MHz|
||Digital pin input (channel 0):|
||YCbCr422, YCbCr444, RGB888, RGB666, RGB565|
||Digital pin input size:|
||Maximum input video image size to be set*: 1440 pixels × 1024 lines (horizontal × vertical)|
||Note:*Depends on the AC characteristics of the connected device.|
||Examples of input video image size :|
||XGA (1024 × 768),|
||SVGA (800 × 600),|
||WVGA (800 × 480),|
||VGA (640 × 480),|
||WQVGA (480 × 240),|
||QVGA (320 × 240, 240 × 320)|
||Input video control|
||Horizontal noise reduction (NR) and brightness and gain adjustment using matrix operation|

|**Items**|**Specification**|
|---|---|
|Video display controller 5|Scaling control|
||Vertical and horizontal scaling up or down of input video possible at a desired ratio (scaling up of|
||graphics also possible)|
||Scaling up ratio: 1 to 8; scaling down ratio: 1/8 to 1|
||Interpolation: Hold or linear selectable|
||2D IP conversion: 2D IP conversion through separately setting the initial phases|
||for the top and bottom fields|
||Video recording|
||Output pixel format: YCbCr444, YCbCr422, RGB888, RGB565|
||Output field rate: 1/1, 1/2, 1/4, 1/8|
||Rotation: Horizontal mirroring and 90/180/270 degree rotation for YCbCr422 and RGB565|
||Maximum video image size to be stored: ×1 size of input video image|
||Output video control|
||Black stretch: Black area stretched according to Y signal state|
||Enhancer capability: LTI (transient improvement) and sharpness (contour emphasis) for Y signal|
||Three graphics layers (one of them also for input video)|
||Available input pixel formats|
||1 bit/pixel: CLUT1|
||4 bits/pixel: CLUT4|
||8 bits/pixel: CLUT8|
||16 bits/pixel: YCbCr422 (graphics layers 0 and 1), RGB565, ARGB1555, RGBA5551, ARGB4444|
||32 bits/pixel: ARGB8888, RGBA8888, RGB888, YCbCr444 (graphics layer 0)|
||Superimposition|
||Alpha blending in a rectangular area:|
||Input video, layer 1, and layer 2 blended according to the transparency percentage α|
||(fade-in and fade-out function available)|
||Chroma key function:|
||Mixing based on transparency percentage α using the specified RGB and CLUT value|
||Pixel-base alpha blending:|
||Alpha blending for each pixel based on transparency percentage α|
||Panel output control|
||Panel output correction:|
||Brightness adjustment and contrast adjustment, gamma correction, panel dithering|
||TCON:|
||Various timing output for LCD panel driving provided by a total of seven vertical and horizontal|
||panel driver signals|
||Panel output pixel format: RGB888, RGB666, RGB565, serial RGB|
||Output video image size:|
||Maximum output video image size to be set*:|
||1999 pixels × 2035 lines (horizontal × vertical)|
||Note:*Depends on the AC characteristics of the display panel.|
||Examples of output video image size:|
||XGA (1024 × 768),|
||SVGA (800 × 600),|
||WVGA (800 × 480),|
||VGA (640 × 480),|
||WQVGA (480 × 240),|
||QVGA (320 × 240, 240 × 320)|
|JPEG codec unit|Compression and decompression method conforming to the JPEG baseline standard within the|
|(RZ/A1LU only)|range described in this document.|
||Operational precision: Conforming to JPEG Part 2, ISO-IEC10918-2|
||Pixel format:|
||Compression: YCbCr422|
||Decompression: YCbCr444, YCbCr422, YCbCr411, YCbCr420|
||Output pixel format to the buffer: YCbCr422, ARGB8888, RGB565|
||Four quantization tables provided|
||Four Huffman tables provided (two tables for AC coefficients and two tables for DC coefficients)|
||Markers supported: SOI, SOF0, SOS, DQT, DHT, DRI, RSTm, and EOI|
||Image data rate: Max. 133.33 Mbytes/s (at 66.67-MHz operation)|

|**Items**|**Specification**|
|---|---|
|Capture engine unit|Examples of input video image size :|
||5 megapixels (2,560 × 1,920),|
||3 megapixels (2,048 × 1,536),|
||2 megapixels (1,632 × 1,224),|
||UXGA (1,600 × 1,200),|
||SXGA (1) (1,280 × 1,024),|
||SXGA (2) (1,280 × 960),|
||WXGA (1,280 × 768),|
||XGA (1,024 × 768),|
||SVGA (800 × 600),|
||WVGA (800 × 480),|
||VGA (640 × 480),|
||WQVGA (480 × 240),|
||QVGA (320 × 240, 240 × 320)|
||Note: Depends on the AC characteristics of the connected device, frame rate of the connected|
||device, and transfer speed to the destination RAM.|
||Input format: 8-bit YCbCr422 binary data|
||Memory output format: YCbCr422, YCbCr420|
||Note: The captured data cannot be displayed via the video display controller 5 because the Y data|
||and CbCr data are split when written to memory.|
|SD host interface|Two channels|
||SD memory I/O card interface (1-/4-bit SD bus)|
||Error check function: CRC7 (command), CRC16 (data)|
||Interrupt requests|
||—Card access interrupt|
||—SDIO access interrupt|
||—Card detect interrupt|
||DMA transfer requests|
||—SD_BUF write|
||—SD_BUF read|
||Card detection function, write protect supported|
|MMC host interface|Interface to multi-media card (MMC)|
||Data bus: 1-/4-/8-bit MMC mode|
||Interrupt requests: card detection, error/time-out, and normal operation|
||DMA transfer requests: CE_DATA write and CE_DATA read|
||Card detection function|
|General I/O ports|176-pin QFP or BGA: 78 I/Os, 8 inputs with open-drain outputs, and 14 inputs (input only)|
||208-pin, 233-pin: 100 I/O pins, 8 input pins with open-drain outputs, and 14 inputs (input only)|
||Input or output can be selected for each bit.|
|A/D converter|12-bit resolution|
||Eight input channels|
||Minimum conversion time: 5.0 μs|
||A/D conversion request by the external trigger or timer trigger|
|Debugging interface|Arm CoreSightTMarchitecture|
||JTAG-standard pin assignment|
|On-chip RAM|3-Mbyte (RZ/A1L and RZ/A1LU) or 2-Mbyte (RZ/A1LC) large capacity memory for video display/|
||recording and work (128 Kbytes are used for data retention)|
||128-Kbyte memory for data retention|
||(16 Kbytes × 2, 32 Kbytes × 1, 64 Kbytes × 1)|
|Boot modes|Four boot modes|
||Boot mode 0: Booting from memory (bus width: 16 bits) connected to CS0 area|
||Boot mode 1: Booting from a serial flash memory|
||Boot mode 2: Booting from a NAND flash memory with SD controller|
||Boot mode 3: Booting from a NAND flash memory with MMC controller|
|Power supply voltage|Vcc: 1.10 to 1.26 V|
||PVcc: 3.0 to 3.6 V|

|**Items**|**Specification**|
|---|---|
|Package|PLBG0176KA-A|
||176-pin BGA, 8-mm square, 0.5-mm pitch|
||JEITA package code: P-LFBGA176-8×8-0.50|
||RENESAS code: PLBG0176KA-A|
||PLQP0176KB-A|
||176-pin QFP, 24-mm square, 0.5-mm pitch|
||JEITA package code: P-LFQFP176-24×24-0.50|
||RENESAS code: PLQP0176KB-A|
||PLQP0208KB-A*1|
||208-pin QFP, 28-mm square, 0.5-mm pitch|
||JEITA package code: P-LFQFP208-28×28-0.50|
||RENESAS Code : PLQP0208KB-A|
||PLQP0208KD-A*2|
||208-pin QFP, 28-mm square, 0.5-mm pitch|
||JEITA package code: P-LFQFP208-28x28-0.50|
||RENESAS Code: PLQP0208KD-A|
||PRBG0233GA-A|
||233-pin BGA, 15-mm square, 0.8-mm pitch|
||JEITA package code: P-FBGA233-15x15-0.80|
||RENESAS Code : PRBG0233GA-A|
||Note 1. PLQP0208KB-A: Ordering part number R7S721021VCFP#AA1|
||Note 2. PLQP0208KD-A: Ordering part number R7S721021VCFP#AA2|

## 1.2 Product Lineup

## **Table 1.2 Product Lineup**

|**Group**|**Part Number**<br>**Temperature Range**|**Quality Level**|**Package**|
|---|---|---|---|
|RZ/A1L|R7S721020VCBG<br>-40 to +85C<br>R7S721020VCFP<br>R7S721020VLFP<br>R7S721021VCFP<br>R7S721021VLFP|Industry usage etc.|PLBG0176KA-A|
|||Industry usage etc.|PLQP0176KB-A|
|||Car Accessories||
|||Industry usage etc.|PLQP0208KB-A*1|
||||PLQP0208KD-A*2|
|||Car Accessories|PLQP0208KB-A|
|RZ/A1LU|R7S721030VCBG<br>-40 to +85C<br>R7S721030VCFP<br>R7S721030VLFP<br>R7S721031VCFP<br>R7S721031VLFP<br>R7S721031VCBG<br>R7S721031VLBG|Industry usage etc.|PLBG0176KA-A|
|||Industry usage etc.|PLQP0176KB-A|
|||Car Accessories||
|||Industry usage etc.|PLQP0208KB-A|
|||Car Accessories||
|||Industry usage etc.|PRBG0233GA-A|
|||Car Accessories||
|RZ/A1LC|R7S721034VCBG<br>-40 to +85C|Industry usage etc.|PLBG0176KA-A|

Note 1. PLQP0208KB-A: Ordering part number R7S721021VCFP#AA1 Note 2. PLQP0208KD-A: Ordering part number R7S721021VCFP#AA2

## 1.3 Block Diagram

See section 5, LSI Internal Bus .

## 1.4 Pin Assignment

||1|2|3|4|5|6|7|8|9|10|11|12|13|14|15||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|A|Vss|Vcc|P5_2|P5_0|P4_5|P4_3|Vss|Vss|DM0|DP1|Vss|USB_X1|P2_8|P3_15|Vss|A|
|B|P5_3|Vss|Vcc|P5_1|P4_6|P4_4|P4_1|REFRIN|DP0|DM1|USB_X2|P2_9|P2_6|Vss|P1_7|B|
|C|P5_6|P5_4|Vss|Vcc|P4_7|P4_2|P4_0|USBAVcc|VBUS0|VBUS1|Vss|P2_7|Vss|P1_6|P1_5|C|
|D|P5_7|P5_5|P5_8|PVcc|Vcc|Vcc|Vcc|Vss|Vss|USBAPVcc|PVcc|Vss|PVcc|P1_4|P1_3|D|
|E|P5_10|P5_11|P5_9|PVcc||||||||PVcc|P1_2|P1_0|P1_1|E|
|F|P5_15|P5_12|P5_14|P5_13||||||||PVcc|P3_14|P3_13|P3_12|F|
|G|P6_2|P6_1|P6_0|Vss||||||||P3_8|P3_9|P3_11|P3_10|G|
|H|P6_5|P6_4|P6_3|Vss||||||||Vss|P3_6|P3_7|P3_5|H|
|J|P6_7|P6_9|P6_8|P6_6||||||||Vss|P3_2|P3_4|P3_3|J|
|K|P6_10|P6_11|P6_12|PVcc||||||||P3_1|P3_0|TCK|Vss|K|
|L|Vss|P6_13|P6_15|PVcc||||||||TMS|TRST|JP0_1|JP0_0|L|
|M|CKIO|P6_14|P7_1|Vss|PVcc|P0_3|P0_0|P0_2|PLLVcc|PVcc|PVcc|Vcc|P2_5|P2_4|Vss|M|
|N|P7_2|P7_0|Vss|P7_5|P7_8|P7_11|P0_1|Vss|NMI|P1_9|P1_11|P1_14|Vcc|BSCANP|AUDIO_X2|N|
|P|PVcc|Vss|P7_3|P7_6|P7_10|P2_0|P2_2|RTC_X1|XTAL|P1_8|P1_13|P1_12|AVcc|Vcc|AUDIO_X1|P|
|R|Vss|P7_4|Vss|P7_7|P7_9|P2_1|P2_3|RTC_X2|EXTAL|RES|P1_10|P1_15|AVss|AVref|Vcc|R|
||1|2|3|4|5|6|7|8|9|10|11|12|13|14|15||

**Figure 1.1 Pin Assignment of the 176-pin BGA (Upper Perspective View)**

**==> picture [469 x 395] intentionally omitted <==**

**----- Start of picture text -----**<br>
132 131 130 129 128 127 126 125 124 123 122 121 120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105 104 103 102 101 100 99 98 97 96 95 94 93 92 91 90 89<br>P3_15 133 88 AVref<br>P2_6 134 87 AVss<br>P2_7 135 86 AVcc<br>P2_8 136 85 P1_15<br>P2_9 137 84 P1_14<br>Vss 138 83 P1_13<br>                  139USB_X1 82 P1_12<br>USB_X2 140 81 P1_11<br>USBDPVcc 141 80 P1_10<br>USBDPVss 142 79 P1_9<br>DM1 143 78 P1_8<br>DP1 144 77 PVcc<br>VBUS1 145 76 RES<br>USBDVcc 146 75 Vss<br>USBDVss 147 74 NMI<br>USBDPVcc 148 73 Vss<br>USBDPVss 149 72 Vss<br>DM0 150 71 XTAL<br>DP0 151 70 EXTAL<br>VBUS0 152 69 PLLVcc<br>USBDVcc 153 68 RTC_X2<br>USBDVss 154 67 RTC_X1<br>REFRIN 155 66 P0_3<br>USBAPVss 156 65 P0_2<br>USBAPVcc 157 64 P0_1<br>USBAVcc 158 63 P0_0<br>USBAVss 159 62 PVcc<br>USBUVcc 160 61 Vss<br>USBUVss 161 60 P2_3<br>Vss 162 59 P2_2<br>Vss 163 58 Vcc<br>P4_0 164 57 P2_1<br>P4_1 165 56 P2_0<br>P4_2 166 55 P7_11<br>P4_3 167 54 P7_10<br>P4_4 168 53 P7_9<br>P4_5 169 52 P7_8<br>P4_6 170 51 P7_7<br>Vss 171 50 PVcc<br>P4_7 172 49 P7_6<br>P5_0 173 48 P7_5<br>PVcc 174 47 P7_4<br>P5_1 175 46 Vss<br>P5_2 176 45 P7_3<br>1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44<br>P1_7 P1_6 P1_5 P1_4 P1_3 P1_2 P1_1 P1_0 P3_14 PVcc P3_13 Vss P3_12 Vcc P3_11 P3_10 Vss P3_9 P3_8 P3_7 P3_6 P3_5 P3_4 PVcc P3_3 Vss P3_2 Vcc P3_1 P3_0 Vss TCK TMS JP0_0 JP0_1 TRST P2_5 Vcc P2_4 Vss AUDIO_ X2 AUDIO_ X1 PVcc BSCANP<br>P5_3 P5_4 P5_5 P5_6 P5_7 P5_8 Vcc P5_9 Vss P5_10 PVcc P5_11 P5_12 P5_13 P5_14 P5_15 P6_0 Vss P6_1 P6_2 Vcc P6_3 Vss P6_4 PVcc P6_5 P6_6 P6_7 P6_8 P6_9 Vss P6_10 P6_11 Vcc P6_12 Vss CKIO P6_13 PVcc P6_14 P6_15 P7_0 P7_1 P7_2<br>**----- End of picture text -----**<br>

**Figure 1.2 Pin Assignment of the 176-pin QFP (Top View)**

**==> picture [465 x 401] intentionally omitted <==**

**----- Start of picture text -----**<br>
156 155 154 153 152 151 150 149 148 147 146 145 144 143 142 141 140 139 138 137 136 135 134 133 132 131 130 129 128 127 126 125 124 123 122 121 120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105<br>P3_15 157 104 AVref<br>P2_6 158 103 AVss<br>P2_7 159 102 AVcc<br>P2_8 160 101 P1_15<br>P2_9 161 100 P1_14<br>Vss 162 99 P1_13<br>                  163USB_X1 98 P1_12<br>USB_X2 164 97 P1_11<br>USBDPVcc 165 96 P1_10<br>USBDPVss 166 95 P1_9<br>DM1 167 94 P1_8<br>DP1 168 93 PVcc<br>VBUS1 169 92 RES<br>USBDVcc 170 91 Vss<br>USBDVss 171 90 NMI<br>USBDPVcc 172 89 Vss<br>USBDPVss 173 88 Vss<br>DM0 174 87 XTAL<br>DP0 175 86 EXTAL<br>VBUS0 176 85 PLLVcc<br>USBDVcc 177 84 RTC_X2<br>USBDVss 178 83 RTC_X1<br>REFRIN 179 82 P0_3<br>USBAPVss 180 81 P0_2<br>USBAPVcc 181 80 P0_1<br>USBAVcc 182 79 P0_0<br>USBAVss 183 78 PVcc<br>USBUVcc 184 77 Vss<br>USBUVss 185 76 P2_3<br>Vss 186 75 P2_2<br>Vss 187 74 Vcc<br>P4_0 188 73 P9_1<br>P4_1 189 72 P9_0<br>P4_2 190 71 P8_15<br>P4_3 191 70 P8_14<br>P8_0 192 69 P2_1<br>Vss 193 68 P2_0<br>P8_1 194 67 PVcc<br>PVcc 195 66 P8_13<br>P4_4 196 65 Vss<br>P4_5 197 64 P8_12<br>P8_2 198 63 P7_11<br>P8_3 199 62 P7_10<br>P8_4 200 61 P7_9<br>P8_5 201 60 P7_8<br>P4_6 202 59 P7_7<br>Vss 203 58 PVcc<br>P4_7 204 57 P7_6<br>P5_0 205 56 P7_5<br>PVcc 206 55 P7_4<br>P5_1 207 54 Vss<br>P5_2 208 53 P7_3<br>1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52<br>P1_7 P1_6 P1_5 P1_4 P1_3 P1_2 P1_1 P1_0 P3_14 PVcc P3_13 Vss P3_12 Vcc P3_11 P3_10 Vss P3_9 P3_8 P9_5 PVcc P9_4 Vss P3_7 P3_6 P3_5 PVcc P9_3 Vss P9_2 P3_4 PVcc P3_3 Vss P3_2 Vcc P3_1 P3_0 Vss TCK TMS JP0_0 JP0_1 TRST P2_5 Vcc P2_4 Vss AUDIO_ 2X AUDIO_ X1 PVcc BSCANP<br>P5_3 P5_4 P5_5 P5_6 P5_7 P5_8 Vcc P5_9 Vss P5_10 PVcc P5_11 P5_12 P5_13 P5_14 P5_15 P6_0 Vss P6_1 P6_2 Vcc P6_3 Vss P6_4 PVcc P6_5 P8_6 P8_7 P8_8 P8_9 P6_6 P6_7 P6_8 Vss P8_10 PVcc P8_11 P6_9 Vss P6_10 P6_11 Vcc P6_12 Vss CKIO P6_13 PVcc P6_14 P6_15 P7_0 P7_1 P7_2<br>**----- End of picture text -----**<br>

**Figure 1.3 Pin Assignment of the 208-pin QFP (Top View)**

||1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|A|Vss|Vcc|P5_2|P5_0|P4_6|P4_5|Vss|P4_2|P4_0|Vss|DM0|DP1|Vss|USB_X1|P2_6|P3_15|Vss|A|
|B|P5_3|Vss|Vcc|P5_1|P8_5|P8_2|P8_1|P4_3|VSS|REFRIN|DP0|DM1|USB_X2|P2_8|P2_7|Vss|PVcc|B|
|C|P5_7|P5_4|Vss|Vcc|P4_7|P8_4|P4_4|P8_0|P4_1|USBAVcc|VBUS0|VBUS1|PVcc|P2_9|Vss|PVcc|P1_7|C|
|D|P5_10|P5_8|P5_6|Vss|Vcc|Vcc|P8_3|PVcc|PVcc|Vss|Vss|USBAPVcc|Vss|Vss|PVcc|P1_6|P1_5|D|
|E|P5_12|P5_11|P5_9|P5_5|||VSS             VSS            VSS             VSS            VSS<br>VSS             VSS            VSS             VSS            VSS<br>VSS             VSS            VSS             VSS            VSS<br>VSS             VSS            VSS             VSS            VSS<br>VSS             VSS            VSS             VSS            VSS|||||||PVcc|P1_4|P1_3|P1_2|E|
|F|P5_15|P5_14|P5_13|PVcc||||||||||PVcc|P1_1|P1_0|P3_14|F|
|G|P6_1|P6_2|P6_0|PVcc||||||||||P3_10|P3_13|P3_12|P3_11|G|
|H|P6_5|P6_4|P6_3|Vcc||||||||||P3_9|P3_8|P9_5|P9_4|H|
|J|P8_8|P8_7|P8_6|Vcc||||||||||Vcc|P3_6|P3_7|Vss|J|
|K|P8_9|P6_6|P6_7|P6_8||||||||||Vcc|P9_3|P3_5|P9_2|K|
|L|P8_10|P8_11|P6_9|PVcc||||||||||Vcc|P3_2|P3_4|Vss|L|
|M|Vss|P6_11|P6_10|PVcc||||||||||TRST|TMS|P3_1|P3_3|M|
|N|CKIO|P6_12|P6_13|PVcc||||||||||BSCANP|JP0_1|TCK|P3_0|N|
|P|PVcc|P6_14|P7_1|Vss|P7_3|P7_9|P7_11|PVcc|PVcc|PLLVcc|Vss|PVcc|PVcc|Vcc|P2_4|JP0_0|Vss|P|
|R|P6_15|P7_0|Vss|P7_5|P7_7|P8_13|P8_15|P2_2|P0_0|P0_3|NMI|P1_10|P1_14|P1_15|Vcc|P2_5|AUDIO_X2|R|
|T|P7_2|Vss|P7_6|P7_8|P8_12|P2_1|P9_0|P2_3|RTC_X1|P0_2|XTAL|P1_8|P1_11|P1_13|AVcc|Vcc|AUDIO_X1|T|
|U|Vss|P7_4|Vss|P7_10|P2_0|P8_14|P9_1|P0_1|RTC_X2|Vss|EXTAL|RES|P1_9|P1_12|AVss|AVref|Vcc|U|
||1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17||

**Figure 1.4 Pin Assignment of the 233-pin BGA (Upper Perspective View)**

## 1.5 Pin Functions

|1.5<br>Pin Functions|1.5<br>Pin Functions|
|---|---|
|**Table 1.3**<br>**Pin Functions**<br>**Classification**<br>**Symbol**<br>**I/O**<br>**Name**<br>**Function**||
|Power supply|Vcc<br>I<br>Power supply<br>Power supply pins. All the Vcc pins must<br>be connected to the system power<br>supply. This LSI does not operate<br>correctly if there is a pin left open.|
||Vss<br>I<br>Ground<br>Ground pins. All the Vss pins must be<br>connected to the system power supply (0<br>V). This LSI does not operate correctly if<br>there is a pin left open.|
||PVcc<br>I<br>Power supply for I/O<br>circuits<br>Power supply for I/O pins. All the PVcc<br>pins must be connected to the system<br>power supply. This LSI does not operate<br>correctly if there is a pin left open.|
||PLLVcc<br>I<br>Power supply for PLL<br>Power supply for the on-chip PLL<br>oscillator.|
|Clock|EXTAL<br>I<br>External clock<br>Connected to a crystal resonator. An<br>external clock signal may also be input to<br>the EXTAL pin.|
||XTAL<br>O<br>Crystal<br>Connected to a crystal resonator.|
||CKIO<br>O<br>System clock output<br>Supplies the system clock to external<br>devices.|
||AUDIO_CLK<br>I<br>External clock for<br>audio<br>Input pin of external clock for audio. A<br>clock input to the divider is selected from<br>an oscillation clock input on this pin or<br>pins AUDIO_X1 and AUDIO_X2.|
||AUDIO_X1<br>I<br>Crystal resonator/<br>external clock for<br>audio<br>Pins connected to a crystal resonator for<br>audio. An external clock can be input on<br>pin AUDIO_X1. A clock input to the<br>divider is selected from an oscillation<br>clock input on these pins or the<br>AUDIO_CLK pin.<br>AUDIO_X2<br>O|
||AUDIO_XOUT<br>O<br>AUDIO_X1 clock<br>output<br>Output for the on-chip crystal oscillator on<br>AUDIO_X1 or the external clock signal.|
||AUDIO_XOUT2<br>O<br>AUDIO_X1 divided-<br>by-two clock output<br>Output for the on-chip crystal oscillator on<br>AUDIO_X1 or the external clock signal<br>after frequency division of the selected<br>signal by two.|
||AUDIO_XOUT3<br>O<br>AUDIO_X1 divided-<br>by-three clock output<br>Output for the on-chip crystal oscillator on<br>AUDIO_X1 or the external clock signal<br>after frequency division of the selected<br>signal by three.|
|Operating mode<br>control|MD_BOOT1,<br>MD_BOOT0<br>I<br>Mode set<br>Sets the operating mode. Do not change<br>the signal levels on these pins while the<br>RES<br>pin is asserted or until the mode is<br>fixed, after the negation.|
||MD_CLK<br>I<br>Clock mode set<br>Sets the clock operating mode. Do not<br>change the signal levels on this pin while<br>the RES<br>pin is asserted or until the mode<br>is fixed, after the negation.|
||MD_CLKS<br>I<br>SSCG clock mode set<br>Switches the SSCG circuit on or off. Do<br>not change the signal levels on this pin<br>while the RES<br>pin is asserted or until the<br>mode is fixed, after the negation.|
||BSCANP<br>I<br>Boundary scan set<br>Boundary scan setting pin.<br>This pin is set to the high level for a<br>boundary scan and to the low level for<br>normal operation.|

|**Classification**||**Symbol**<br>**I/O**<br>**Name**<br>**Function**|
|---|---|---|
|System control||RES<br>I<br>Power-on reset<br>This LSI enters the power-on reset state<br>when this signal goes low.|
|||WDTOVF<br>O<br>Watchdog timer<br>overflow<br>Outputs an overflow signal from the<br>watchdog timer.|
|Interrupts||NMI<br>I<br>Non-maskable<br>interrupt<br>Non-maskable interrupt request pin. It is<br>handled as an FIQ exception. Fix it high<br>when not in use.|
|||IRQ7 to IRQ0<br>I<br>Interrupt requests 7 to<br>0<br>Maskable interrupt request pins.<br>Level-input or edge-input detection can<br>be selected. When the edge-input<br>detection is selected, the rising edge,<br>falling edge, or both edges can also be<br>selected.|
|||TINT121 to TINT0<br>I<br>Interrupt requests 121<br>to 0<br>Maskable interrupt request pins.<br>High-level-input or rising edge-input<br>detection can be selected.|
|Address bus||A25 to A0<br>O<br>Address bus<br>Outputs addresses.|
|Data bus||D31 to D0<br>I/O<br>Data bus<br>Bidirectional data bus.|
|Bus control||CS5<br>to CS0<br>O<br>Chip select 5 to 0<br>Chip-select signals for external memory<br>or devices.|
|||RD<br>O<br>Read<br>Indicates that data is read from an<br>external device.|
|||RD/WR<br>O<br>Read/write<br>Read/write signal.|
|||BS<br>O<br>Bus start<br>Bus-cycle start signal.|
|||AH<br>O<br>Address hold<br>Address hold timing signal for the device<br>that uses the address/data-multiplexed<br>bus.|
|||WAIT<br>I<br>Wait<br>Inserts a wait cycle into the bus cycles<br>during access to the external space.|
|||WE0<br>O<br>Byte select<br>Indicates a write access to bits 7 to 0 of<br>data of external memory or device.|
|||WE1<br>O<br>Byte select<br>Indicates a write access to bits 15 to 8 of<br>data of external memory or device.|
|||WE2<br>O<br>Byte select<br>Indicates a write access to bits 23 to 16 of<br>data of external memory or device.|
|||WE3<br>O<br>Byte select<br>Indicates a write access to bits 31 to 24 of<br>data of external memory or device.|
|||DQMLL<br>O<br>Byte select<br>Selects bits D7 to D0 when SDRAM is<br>connected.|
|||DQMLU<br>O<br>Byte select<br>Selects bits D15 to D8 when SDRAM is<br>connected.|
|||DQMUL<br>O<br>Byte select<br>Selects bits D23 to D16 when SDRAM is<br>connected.|
|||DQMUU<br>O<br>Byte select<br>Selects bits D31 to D24 when SDRAM is<br>connected.|
|||RAS<br>O<br>RAS<br>Connected to the RAS<br>pin when SDRAM<br>is connected.|
|||CAS<br>O<br>CAS<br>Connected to the CAS<br>pin when SDRAM<br>is connected.|
|||CKE<br>O<br>CK enable<br>Connected to the CKE pin when SDRAM<br>is connected.|

|**Classification**|**Symbol**<br>**I/O**<br>**Name**<br>**Function**|**Symbol**<br>**I/O**<br>**Name**<br>**Function**|
|---|---|---|
|Direct memory<br>access controller|DREQ0<br>I<br>DMA-transfer request<br>Input pin to receive external requests for<br>DMA transfer.||
||DACK0<br>O<br>DMA-transfer request<br>accept<br>Output pin for signals indicating<br>acceptance of external requests from<br>external devices.||
||TEND0<br>O<br>DMA-transfer end<br>output<br>Output pin for DMA transfer end.||
|Multi-function timer<br>pulse unit 2|TCLKA,<br>TCLKB,<br>TCLKC,<br>TCLKD<br>I<br>Timer clock input<br>External clock input pins for the timer.||
||TIOC0A,<br>TIOC0B,<br>TIOC0C,<br>TIOC0D<br>Note: TIOC0B pin is not present on<br>products in the 176-pin<br>package.<br>I/O<br>Input capture/<br>output compare<br>(channel 0)<br>The TGRA_0 to TGRD_0 input capture<br>input/output compare output/PWM output<br>pins.||
||TIOC1A,<br>TIOC1B<br>I/O<br>Input capture/<br>output compare<br>(channel 1)<br>The TGRA_1 and TGRB_1 input capture<br>input/output compare output/PWM output<br>pins.||
||TIOC2A,<br>TIOC2B<br>I/O<br>Input capture/<br>output compare<br>(channel 2)<br>The TGRA_2 and TGRB_2 input capture<br>input/output compare output/PWM output<br>pins.||
||TIOC3A,<br>TIOC3B,<br>TIOC3C,<br>TIOC3D<br>I/O<br>Input capture/<br>output compare<br>(channel 3)<br>The TGRA_3 to TGRD_3 input capture<br>input/output compare output/PWM output<br>pins.||
||TIOC4A,<br>TIOC4B,<br>TIOC4C,<br>TIOC4D<br>I/O<br>Input capture/<br>output compare<br>(channel 4)<br>The TGRA_4 to TGRD_4 input capture<br>input/output compare output/PWM output<br>pins.||
|Realtime clock|RTC_X1<br>I<br>Crystal resonator for<br>realtime clock/<br>external clock<br>Connected to 32.768-kHz crystal<br>resonator.<br>The RTC_X1 pin can also be used to<br>input an external clock.<br>RTC_X2<br>O||
|Serial<br>communication<br>interface with FIFO|TxD4 to TxD0<br>O<br>Transmit data<br>Data output pins.||
||RxD4 to RxD0<br>I<br>Receive data<br>Data input pins.||
||SCK4 to SCK0<br>I/O<br>Serial clock<br>Clock input/output pins.||
||RTS2<br>to|RTS0<br>I/O<br>Transmit request<br>Modem control pins.|
||CTS2<br>to|CTS0<br>I/O<br>Transmit enable<br>Modem control pins.|
|Serial<br>communication<br>interface|SCI_SCK1,<br>SCI_SCK0<br>I/O<br>Serial clock<br>Clock input/output pins.||
||SCI_TXD1,<br>SCI_TXD0<br>O<br>Transmit data<br>Data output pins.||
||SCI_RXD1,<br>SCI_RXD0<br>I<br>Receive data<br>Data input pins.||
||SCI_CTS1<br>/RTS1<br>,<br>SCI_CTS0<br>/RTS0<br>I/O<br>Transmit and receive<br>start control<br>I/O pins for controlling the start of<br>transmission and reception.||
|Renesas serial<br>peripheral interface|MOSI2 to MOSI0<br>I/O<br>Data<br>Data I/O pins.||
||MISO2 to MISO0<br>I/O<br>Data<br>Data I/O pins.||
||RSPCK2 to RSPCK0<br>I/O<br>Clock<br>Clock I/O pins.||
||SSL20, SSL10, SSL00<br>I/O<br>Slave select<br>Slave select I/O pins.||

|**Classification**|**Symbol**<br>**I/O**<br>**Name**<br>**Function**|
|---|---|
|SPI multi I/O bus<br>controller|SPBCLK_0<br>O<br>Clock<br>Clock output pins.|
||SPBSSL_0<br>O<br>Slave select<br>Slave select output pins.|
||SPBMO0_0/SPBIO00_0,<br>SPBMI0_0/SPBIO10_0,<br>SPBIO20_0,<br>SPBIO30_0,<br>SPBMO1_0/SPBIO01_0,<br>SPBMI1_0/SPBIO11_0,<br>SPBIO21_0, SPBIO31_0<br>I/O<br>Data<br>Data I/O pins for channel.|
|I2C bus interface|RIIC3SCL to RIIC0SCL<br>I/O<br>Serial clock pin<br>Serial clock I/O pins.|
||RIIC3SDA to RIIC0SDA<br>I/O<br>Serial data pin<br>Serial data I/O pins.|
|Serial sound<br>interface|SSITxD3, SSITxD1, SSITxD0<br>O<br>Data output<br>Serial data output pin.|
||SSIRxD3, SSIRxD1, SSIRxD0<br>I<br>Data input<br>Serial data input pin.|
||SSIDATA2<br>I/O<br>Data I/O<br>Serial data I/O pins.|
||SSISCK3 to SSISCK0<br>I/O<br>SSI clock I/O<br>I/O pins for serial clocks.|
||SSIWS3 to SSIWS0<br>I/O<br>SSI clock LR I/O<br>I/O pins for word selection.|
|Media local bus<br>(RZ/A1L only)|MLB_CLK<br>I<br>Clock input<br>MediaLB clock input pin.|
||MLB_SIG<br>I/O<br>Signal information I/O<br>MediaLB signal information I/O pin.|
||MLB_DAT<br>I/O<br>Data I/O<br>MediaLB data I/O pin.|
|CAN interface|CAN_CLK<br>I<br>Clock source for CAN<br>communication<br>Clock source for CAN communication.|
||CAN1TX, CAN0TX<br>O<br>CAN bus transmit data<br>Output pins for transmit data on the CAN<br>bus.|
||CAN1RX, CAN0RX<br>I<br>CAN bus receive data<br>Input pins for receive data on the CAN<br>bus.|
|IEBusTMcontroller<br>(RZ/A1L only)|IETxD<br>O<br>IEBus™ controller<br>transmit data<br>Output pin for transmit data on IEBus™<br>controller.|
||IERxD<br>I<br>IEBus™ controller<br>receive data<br>Input pin for receive data on IEBus™<br>controller.|
|Renesas SPDIF<br>interface|SPDIF_OUT<br>O<br>Output data<br>Transmit data output pin.|
||SPDIF_IN<br>I<br>Input data<br>Receive data input pin.|
|LIN interface<br>(RZ/A1L only)|RLIN30TX<br>O<br>Output data<br>Transmit data output pins.|
||RLIN30RX<br>I<br>Input data<br>Receive data input pins.|
|Ethernet controller,<br>EthernetAVB (RZ/<br>A1LU only)<br>Note: Regarding the<br>switching of pin<br>functions between<br>Ethernet controller<br>and EthernetAVB,<br>refer to section 41,<br>Ports.|ET_TXCLK<br>I<br>Transmit clock<br>Clock pin for transmission.|
||ET_TXEN<br>O<br>Transmit enable<br>Transmit data enable pin|
||ET_TXD3 to ET_TXD0<br>O<br>Transmit data<br>MII transmit data pins.|
||ET_COL<br>I<br>Collision detection<br>Collision detection pin.|
||ET_TXER<br>O<br>Transmit error<br>Transmit error output pin.|
||ET_RXCLK<br>I<br>Receive clock<br>Receive clock pin|
||ET_RXDV<br>I<br>Receive enable<br>Receive data enable pin|
||ET_RXD3 to ET_RXD0<br>I<br>Receive data<br>MII receive data pins.|
||ET_RXER<br>I<br>Receive error<br>Receive error input pin.|
||ET_CRS<br>I<br>Carrier detection<br>Carrier detection pin.|
||ET_MDC<br>O<br>Management data<br>clock<br>Clock pin for information transfer via<br>MDIO.|
||ET_MDIO<br>I/O<br>Management data I/O<br>Bidirectional pin for exchange of<br>management data|
|EthernetAVB<br>(RZ/A1LU only)|AVB_CAPTURE<br>I<br>Timer capture<br>Capturing input pin for AVTP presentation<br>timer|
||AVB_GPTP_EXTERN<br>I<br>gPTP timer external<br>clock<br>External clock pin for gPTP timer|

|**Classification**|**Symbol**<br>**I/O**<br>**Name**<br>**Function**|
|---|---|
|USB 2.0 host/<br>function module|DP1, DP0<br>I/O<br>USB 2.0 host/function<br>module D+ data<br>D+ data pins for USB 2.0 host/function<br>module bus.|
||DM1, DM0<br>I/O<br>USB 2.0 host/function<br>module D– data<br>D– data pins for USB 2.0 host/function<br>module bus.|
||VBUS1, VBUS0<br>I<br>VBUS input<br>Connected to Vbus on USB 2.0 host/<br>function module bus.|
||REFRIN<br>I<br>Reference input<br>Connected to USBAPVss via<br>5.6-k 1% resistance. (QFP package)<br>Connected to Vss via 5.6-kΩ ± 1%<br>resistance. (BGA package)|
||USB_X1<br>I<br>Crystal resonator/<br>external clock for USB<br>2.0 host/function<br>module<br>Connected to a crystal resonator for USB<br>2.0 host/function module. An external<br>clock signal may also be input to the<br>USB_X1 pin.<br>USB_X2<br>O|
||USBAPVcc<br>I<br>Power supply for<br>transceiver analog<br>pins<br>Power supply for pins.|
||USBAPVss<br>Note: This pin is not present on<br>products in the BGA package.<br>I<br>Ground for transceiver<br>analog pins<br>Ground for pins.|
||USBDPVcc<br>Note: This pin is not present on<br>products in the BGA package.<br>I<br>Power supply for<br>transceiver digital pins<br>Power supply for pins.|
||USBDPVss<br>Note: This pin is not present on<br>products in the BGA package.<br>I<br>Ground for transceiver<br>digital pins<br>Ground for pins.|
||USBAVcc<br>I<br>Power supply for<br>transceiver analog<br>core<br>Power supply for core.|
||USBAVss<br>Note: This pin is not present on<br>products in the BGA package.<br>I<br>Ground for transceiver<br>analog core<br>Ground for core.|
||USBDVcc<br>Note: This pin is not present on<br>products in the BGA package.<br>I<br>Power supply for<br>transceiver digital core<br>Power supply for core.|
||USBDVss<br>Note: This pin is not present on<br>products in the BGA package.<br>I<br>Ground for transceiver<br>digital core<br>Ground for core.|
||USBUVcc<br>Note: This pin is not present on<br>products in the BGA package.<br>I<br>480-MHz power<br>supply for USB 2.0<br>host/function module<br>Power supply for 480-MHz sections|
||USBUVss<br>Note: This pin is not present on<br>products in the BGA package.<br>I<br>480-MHz ground for<br>USB 2.0 host/function<br>module<br>Ground for 480-MHz sections|
|Video display<br>controller 5|LCD0_DATA23 to LCD0_DATA0<br>O<br>Output data<br>Data output pins for panel.|
||LCD0_TCON6 to LCD0_TCON0<br>O<br>Panel timing<br>adjustment output<br>Output pins for panel timing adjustment|
||LCD0_CLK<br>O<br>Panel clock<br>Panel clock output pins.|
||LCD0_EXTCLK<br>I<br>Panel clock source<br>Panel clock source input pins.|
||DV0_DATA23 to DV0_DATA0<br>I<br>Input data<br>Data input pins for graphics data.|
||DV0_VSYNC<br>I<br>VSYNC input<br>VSYNC input pins.|
||DV0_HSYNC<br>I<br>HSYNC input<br>HSYNC input pins.|
||DV0_CLK<br>I<br>Input clock<br>Clock input signal pins for graphics data.|

|**Classification**||**Symbol**<br>**I/O**<br>**Name**<br>**Function**|
|---|---|---|
|Capture engine unit||VIO_D7 to VIO_D0<br>I<br>Input data<br>Graphics data input pins.|
|||VIO_CLK<br>I<br>Input clock<br>Graphics data clock input pin.|
|||VIO_VD<br>I<br>VSYNC input<br>VSYNC input pin.|
|||VIO_HD<br>I<br>HSYNC input<br>HSYNC input pin.|
|||VIO_FLD<br>I<br>FIELD input<br>Input pin for field information|
|SD host interface||SD_CLK_0, SD_CLK_1<br>O<br>SD clock<br>Output pins for SD clock.|
|||SD_CMD_0, SD_CMD_1<br>I/O<br>SD command<br>SD command output and response input<br>signals.|
|||SD_D3_0 to SD_D0_0,<br>SD_D3_1 to SD_D0_1<br>I/O<br>SD data<br>SD data bus signals.|
|||SD_CD_0, SD_CD_1<br>I<br>SD card detection<br>SD card detection.|
|||SD_WP_0, SD_WP_1<br>I<br>SD write protection<br>SD write protection signals.|
|MMC host interface||MMC_CLK<br>O<br>MMC clock<br>Output pin for MMC clock.|
|||MMC_CMD<br>I/O<br>MMC command<br>MMC command output and response<br>input signal.|
|||MMC_D7 to MMC_D0<br>I/O<br>MMC data<br>MMC data bus signals.|
|||MMC_CD<br>I<br>MMC card detection<br>MMC card detection.|
|A/D converter||AN7 to AN0<br>I<br>Analog input pins<br>Analog input pins.|
|||ADTRG<br>I<br>A/D conversion trigger<br>input<br>External trigger input pin for starting A/D<br>conversion.|
|||AVcc<br>I<br>Analog power supply<br>Power supply pin for A/D converter.|
|||AVss<br>I<br>Analog ground<br>Ground pin for A/D converter.|
|||AVref<br>I<br>Analog reference<br>voltage<br>Reference voltage pin for A/D converter.|
|General I/O ports||P2_0 to P2_9,<br>P3_0 to P3_15,<br>P4_0 to P4_7,<br>P5_0 to P5_15,<br>P6_0 to P6_15,<br>P7_0 to P7_11,<br>P8_0 to P8_15 (208-pin and 233-<br>pin products only),<br>P9_0 to P9_5 (208-pin and 233-pin<br>products only)<br>I/O<br>General port<br>78 general I/O port pins in 176-pin QFP<br>and 176-pin BGA products.<br>100 general I/O port pins in 208-pin and<br>233-pin products.|
|||P1_0 to P1_7<br>I/O<br>General port<br>8 input port pins with open-drain output.|
|||JP0_0, JP0_1, P0_0 to P0_3, P1_8<br>to P1_15<br>I<br>General port<br>14 general input port pins.|
|Debugging interface||TCK/SWDCLK<br>I<br>Test clock<br>Test-clock input pin.<br>Also used as the input clock pin for serial<br>wire debugging|
|||TMS/SWDIO<br>I, I/<br>O<br>Test mode select<br>Test-mode select signal input pin.<br>Also used as the I/O data pin for serial<br>wire debugging|
|||TDI<br>I<br>Test data input<br>Serial input pin for instructions and data.|
|||TDO<br>O<br>Test data output<br>Serial output pin for instructions and data.|
|||TRST<br>I<br>Test reset<br>Initialization-signal input pin.<br>Note: When the chip is in CoreSight<br>debugging mode, do not negate the<br>TRST<br>signal while the RES<br>signal<br>is at the high-level.|
|||TRACEDATA3 to TRACEDATA0<br>O<br>Data output<br>Trace data output pins.|
|||TRACECLK<br>O<br>Clock output<br>Trace clock output pin.|
|||TRACECTL<br>O<br>Enable output<br>Trace enable output pin.|

## 1.6 List of Pins

## **Table 1.4 List of Pins**

|176<br>QFP|176<br>BGA|208<br>QFP|233<br>BGA|Port function/<br>dedicated function|Port function/<br>dedicated function|Mode function|Mode function|Function 1|Function 1|Function 2|Function 2|Function 3|Function 3|Function 4|Function 4|Function 5|Function 5|Function 6|Function 6|Function 7|Function 7|Function 8|Function 8|Simplified<br>Circuit<br>Diagram|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|No.|No.|No.|No.|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Figure 1.5|
|1|B1|1|B1|P5_3|I(s)/O|―|―|D3|I(s)/O|MMC_D7|I(s)/O|ET_<br>TXD3|O|DV0_<br>DATA19|I(s)|LCD0_<br>TCON3|O|―|―|―|―|―|―|(8)|
|2|C2|2|C2|P5_4|I(s)/O|―|―|D4|I(s)/O|RSPCK2|I(s)/O|SSISCK1|I(s)/O|DV0_<br>DATA20|I(s)|―|―|―|―|―|―|―|―|(8)|
|3|D2|3|E4|P5_5|I(s)/O|―|―|D5|I(s)/O|SSL20|I(s)/O|SSIWS1|I(s)/O|DV0_<br>DATA21|I(s)|―|―|―|―|―|―|―|―|(8)|
|4|C1|4|D3|P5_6|I(s)/O|―|―|D6|I(s)/O|MOSI2|I(s)/O|SSITxD1|O|DV0_<br>DATA22|I(s)|SCK2|I(s)/O|―|―|―|―|―|―|(8)|
|5|D1|5|C1|P5_7|I(s)/O|―|―|D7|I(s)/O|MISO2|I(s)/O|SSIRxD1|I(s)|DV0_<br>DATA23|I(s)|TxD2|O|―|―|―|―|―|―|(8)|
|6|D3|6|D2|P5_8|I(s)/O|―|―|D8|I(s)/O|CAN0RX|I(s)|TIOC4A|I(s)/O|IRQ3|I(s)|―|―|―|―|―|―|―|―|(8)|
|7|―|7|―|Vcc|||||||||||||||||||||
|8|E3|8|E3|P5_9|I(s)/O|―|―|D9|I(s)/O|CAN0TX|O|TIOC4B|I(s)/O|IRQ4|I(s)|―|―|―|―|―|―|―|―|(8)|
|9|―|9|―|Vss|||||||||||||||||||||
|10|E1|10|D1|P5_10|I(s)/O|―|―|D10|I(s)/O|IERxD*3|I(s)|TIOC4C|I(s)/O|IRQ5|I(s)|―|―|―|―|―|―|―|―|(8)|
|11|―|11|―|PVcc|||||||||||||||||||||
|12|E2|12|E2|P5_11|I(s)/O|―|―|D11|I(s)/O|IETxD*3|O|TIOC4D|I(s)/O|IRQ6|I(s)|―|―|―|―|―|―|―|―|(8)|
|13|F2|13|E1|P5_12|I(s)/O|―|―|D12|I(s)/O|SSISCK2|I(s)/O|SCK4|I(s)/O|AUDIO_<br>XOUT2|O|―|―|―|―|―|―|―|―|(8)|
|14|F4|14|F3|P5_13|I(s)/O|―|―|D13|I(s)/O|SSIWS2|I(s)/O|AUDIO_<br>XOUT|O|AUDIO_<br>XOUT3|O|―|―|―|―|―|―|―|―|(8)|
|15|F3|15|F2|P5_14|I(s)/O|―|―|D14|I(s)/O|SSI<br>DATA2|I(s)/O|RxD4|I(s)|TIOC2A|I(s)/O|―|―|―|―|―|―|―|―|(8)|
|16|F1|16|F1|P5_15|I(s)/O|―|―|D15|I(s)/O|SD_<br>WP_1|I(s)|TxD4|O|―|―|―|―|―|―|―|―|―|―|(8)|
|17|G3|17|G3|P6_0|I(s)/O|―|―|D16|I(s)/O|LCD0_<br>DATA8|O|RSPCK0|I(s)/O|TCLKA|I(s)|WDTOVF|O|―|―|―|―|―|―|(8)|
|18|―|18|―|Vss|||||||||||||||||||||
|19|G2|19|G1|P6_1|I(s)/O|―|―|D17|I(s)/O|LCD0_<br>DATA9|O|SSL00|I(s)/O|TCLKB|I(s)|―|―|―|―|―|―|―|―|(8)|
|20|G1|20|G2|P6_2|I(s)/O|―|―|D18|I(s)/O|LCD0_<br>DATA10|O|MOSI0|I(s)/O|TCLKC|I(s)|―|―|―|―|―|―|―|―|(8)|
|21|―|21|―|Vcc|||||||||||||||||||||
|22|H3|22|H3|P6_3|I(s)/O|―|―|D19|I(s)/O|LCD0_<br>DATA11|O|MISO0|I(s)/O|TCLKD|I(s)|―|―|―|―|―|―|―|―|(8)|
|23|―|23|―|Vss|||||||||||||||||||||
|24|H2|24|H2|P6_4|I(s)/O|―|―|D20|I(s)/O|LCD0_<br>DATA12|O|SSISCK3|I(s)/O|MLB_<br>CLK*1|I(s)|―|―|―|―|―|―|―|―|(8)|
|||||||||||||||AVB_<br>CAPTURE*2|I(s)||||||||||
|25|―|25|―|PVcc|||||||||||||||||||||
|26|H1|26|H1|P6_5|I(s)/O|―|―|D21|I(s)/O|LCD0_<br>DATA13|O|SSIWS3|I(s)/O|MLB_<br>SIG*1|I(s)/O|―|―|―|―|―|―|―|―|(8)|
|||||||||||||||AVB_<br>GPTP_<br>EXTERN*2|I(s)||||||||||
|―|―|27|J3|P8_6|I(s)/O|―|―|LCD0_<br>DATA6|O|ET_<br>TXEN|O|IRQ6|I(s)|CTS1|I(s)/O|TIOC0C|I(s)/O|―|―|―|―|―|―|(7)|
|―|―|28|J2|P8_7|I(s)/O|―|―|LCD0_<br>DATA7|O|ET_<br>RXD0|I(s)|IRQ7|I(s)|RTS1|I(s)/O|TIOC0D|I(s)/O|―|―|―|―|―|―|(7)|
|―|―|29|J1|P8_8|I(s)/O|―|―|LCD0_<br>TCON0|O|ET_<br>RXD1|I(s)|AUDIO_<br>XOUT|O|SCK2|I(s)/O|AUDIO_<br>XOUT3|O|―|―|―|―|―|―|(7)|
|―|―|30|K1|P8_9|I(s)/O|―|―|LCD0_<br>TCON1|O|ET_<br>RXD2|I(s)|CAN1TX|O|RxD2|I(s)|AUDIO_<br>XOUT2|O|―|―|―|―|―|―|(7)|
|27|J4|31|K2|P6_6|I(s)/O|―|―|D22|I(s)/O|LCD0_<br>DATA14|O|SSITxD3|O|MLB_<br>DAT*3|I(s)/O|―|―|―|―|―|―|―|―|(8)|
|28|J1|32|K3|P6_7|I(s)/O|―|―|D23|I(s)/O|LCD0_<br>DATA15|O|SSIRxD3|I(s)|IRQ0|I(s)|TIOC3A|I(s)/O|RLIN30<br>RX*3|I(s)|―|―|TRACE<br>DATA0*4|O|(8)|
|29|J3|33|K4|P6_8|I(s)/O|―|―|D24|I(s)/O|LCD0_<br>DATA16|O|SSISCK0|I(s)/O|IRQ1|I(s)|TIOC3B|I(s)/O|RLIN30<br>TX*3|O|―|―|TRACE<br>DATA1*4|O|(8)|
|―|―|34|―|Vss|||||||||||||||||||||
|―|―|35|L1|P8_10|I(s)/O|―|―|LCD0_<br>TCON2|O|ET_<br>RXD3|I(s)|CAN1RX|I(s)|TxD2|O|―|―|―|―|―|―|―|―|(7)|
|―|―|36|―|PVcc|||||||||||||||||||||
|―|―|37|L2|P8_11|I(s)/O|―|―|LCD0_<br>TCON3|O|―|―|SSISCK2|I(s)/O|SCK4|I(s)/O|―|―|―|―|―|―|―|―|(7)|
|30|J2|38|L3|P6_9|I(s)/O|―|―|D25|I(s)/O|LCD0_<br>DATA17|O|SSIWS0|I(s)/O|IRQ2|I(s)|TIOC3C|I(s)/O|―|―|―|―|TRACE<br>DATA2*4|O|(8)|
|31|―|39|―|Vss|||||||||||||||||||||
|32|K1|40|M3|P6_10|I(s)/O|―|―|D26|I(s)/O|LCD0_<br>DATA18|O|SSITxD0|O|IRQ3|I(s)|TIOC3D|I(s)/O|CAN1<br>TX|O|―|―|TRACE<br>DATA3*4|O|(8)|
|33|K2|41|M2|P6_11|I(s)/O|―|―|D27|I(s)/O|LCD0_<br>DATA19|O|SSIRxD0|I(s)|SSI<br>DATA2|I(s)/O|SCK0|I(s)/O|CAN1<br>RX|I(s)|―|―|TRACE<br>CTL*4|O|(8)|

|176<br>QFP|176<br>BGA|208<br>QFP|233<br>BGA|Port function/<br>dedicated function|Port function/<br>dedicated function|Mode function|Mode function|Function 1|Function 1|Function 2|Function 2|Function 3|Function 3|Function 4|Function 4|Function 5|Function 5|Function 6|Function 6|Function 7|Function 7|Function 8|Function 8|Simplified<br>Circuit<br>Diagram|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|No.|No.|No.|No.|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Figure 1.5|
|34|―|42|―|Vcc|||||||||||||||||||||
|35|K3|43|N2|P6_12|I(s)/O|―|―|D28|I(s)/O|LCD0_<br>DATA20|O|RSPCK1|I(s)/O|SSI<br>SCK2|I(s)/O|RTS0|I(s)/O|DV0_<br>DATA0|I(s)|―|―|―|―|(8)|
|36|―|44|―|Vss|||||||||||||||||||||
|37|M1|45|N1|CKIO|O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(5)|
|38|L2|46|N3|P6_13|I(s)/O|―|―|D29|I(s)/O|LCD0_<br>DATA21|O|SSL10|I(s)/O|SSI<br>WS2|I(s)/O|CTS0|I(s)/O|DV0_<br>DATA1|I(s)|―|―|―|―|(8)|
|39|―|47|―|PVcc|||||||||||||||||||||
|40|M2|48|P2|P6_14|I(s)/O|―|―|D30|I(s)/O|LCD0_<br>DATA22|O|MOSI1|I(s)/O|SSI<br>DATA2|I(s)/O|RxD0|I(s)|DV0_<br>DATA2|I(s)|―|―|―|―|(8)|
|41|L3|49|R1|P6_15|I(s)/O|―|―|D31|I(s)/O|LCD0_<br>DATA23|O|MISO1|I(s)/O|―|―|TxD0|O|DV0_<br>DATA3|I(s)|―|―|―|―|(8)|
|42|N2|50|R2|P7_0|I(s)/O|―|―|LCD0_<br>EXTCLK|I(s)|MMC_<br>CD|I(s)|SD_<br>CD_1|I(s)|SPDIF_O<br>UT|O|TIOC2A|I(s)/O|DV0_<br>DATA4|I(s)|SCI_<br>SCK0|I(s)/O|TRACE<br>CLK*4|O|(7)|
|43|M3|51|P3|P7_1|I(s)/O|―|―|CS1|O|AUDIO_<br>XOUT|O|SD_<br>WP_1|I(s)|TxD2|O|―|―|DV0_<br>DATA5|I(s)|SCI_<br>RXD0/<br>IrRXD|I(s)|―|―|(7)|
|44|N1|52|T1|P7_2|I(s)/O|―|―|CS4|O|MMC_D1|I(s)/O|SD_<br>D1_1|I(s)/O|IRQ4|I(s)|CAN0RX|I(s)|DV0_<br>DATA6|I(s)|SCI_<br>TXD0/<br>IrTXD|O|―|―|(7)|
|45|P3|53|P5|P7_3|I(s)/O|―|―|CS5|O|MMC_D0|I(s)/O|SD_<br>D0_1|I(s)/O|IRQ3|I(s)|CAN0TX|O|DV0_<br>DATA7|I(s)|SCI_<br>CTS0<br>/<br>RTS0|I(s)/O|―|―|(7)|
|46|―|54|―|Vss|||||||||||||||||||||
|47|R2|55|U2|P7_4|I(s)/O|―|―|WAIT|I(s)|MMC_<br>CLK|O|SD_<br>CLK_1|O|―|―|IETxD*3|O|LCD0_<br>CLK|O|SCI_<br>SCK1|I(s)/O|―|―|(7)|
|48|N4|56|R4|P7_5|I(s)/O|―|―|BS|O|MMC_<br>CMD|I(s)/O|SD_<br>CMD_1|I(s)/O|TxD0|O|IERxD*3|I(s)|LCD0_<br>TCON4|O|SCI_<br>RXD1|I(s)|―|―|(7)|
|49|P4|57|T3|P7_6|I(s)/O|―|―|WE2<br>/<br>DQMUL|O|MMC_D3|I(s)/O|SD_<br>D3_1|I(s)/O|IRQ6|I(s)|CTS2|I(s)/O|LCD0_<br>TCON5|O|SCI_<br>TXD1|O|―|―|(7)|
|50|―|58|―|PVcc|||||||||||||||||||||
|51|R4|59|R5|P7_7|I(s)/O|―|―|WE3<br>/<br>DQMUU/<br>AH|O|MMC_D2|I(s)/O|SD_<br>D2_1|I(s)/O|IRQ5|I(s)|RTS2|I(s)/O|LCD0_<br>TCON6|O|SCI_<br>CTS1<br>/<br>RTS1|I(s)/O|―|―|(7)|
|52|N5|60|T4|P7_8|I(s)/O|―|―|CS2|O|SSISCK1|I(s)/O|DV0_<br>CLK|I(s)|IRQ3|I(s)|TxD0|O|―|―|―|―|―|―|(7)|
|53|R5|61|P6|P7_9|I(s)/O|―|―|A25|O|SSIWS1|I(s)/O|DV0_<br>VSYNC|I(s)|IRQ5|I(s)|SCK3|I(s)/O|TIOC1A|I(s)/O|―|―|―|―|(7)|
|54|P5|62|U4|P7_10|I(s)/O|―|―|TEND0|O|SSITxD1|O|DV0_<br>HSYNC|I(s)|―|―|RxD3|I(s)|―|―|―|―|―|―|(7)|
|55|N6|63|P7|P7_11|I(s)/O|―|―|DACK0|O|SSIRxD1|I(s)|CAN_<br>CLK|I(s)|SCK2|I(s)/O|TxD3|O|AUDIO_<br>XOUT|O|AUDIO_<br>XOUT3|O|―|―|(7)|
|―|―|64|T5|P8_12|I(s)/O|―|―|LCD0_<br>TCON4|O|SPDIF_<br>IN|I(s)|SSIWS2|I(s)/O|RxD4|I(s)|―|―|―|―|―|―|―|―|(7)|
|―|―|65|―|Vss|||||||||||||||||||||
|―|―|66|R6|P8_13|I(s)/O|―|―|LCD0_<br>TCON5|O|SPDIF_<br>OUT|O|SSI<br>DATA2|I(s)/O|TxD4|O|―|―|―|―|―|―|―|―|(7)|
|―|―|67|―|PVcc|||||||||||||||||||||
|56|P6|68|U5|P2_0|I(s)/O|―|―|CS3|O|RLIN30<br>RX*3|I(s)|SPDIF_<br>IN|I(s)|IRQ7|I(s)|―|―|―|―|―|―|―|―|(7)|
|57|R6|69|T6|P2_1|I(s)/O|―|―|RAS|O|RLIN30<br>TX*3|O|SPDIF_<br>OUT|O|IRQ6|I(s)|―|―|―|―|―|―|―|―|(7)|
|―|―|70|U6|P8_14|I(s)/O|―|―|LCD0_<br>TCON6|O|ET_COL|I(s)|SD_<br>CD_0|I(s)|SCK1|I(s)/O|―|―|―|―|―|―|―|―|(7)|
|―|―|71|R7|P8_15|I(s)/O|―|―|―|―|ET_CRS|I(s)|SD_<br>WP_0|I(s)|RxD1|I(s)|―|―|―|―|―|―|―|―|(7)|
|―|―|72|T7|P9_0|I(s)/O|―|―|―|―|ET_MDC|O|SD_<br>D1_0|I(s)/O|TxD1|O|―|―|―|―|―|―|―|―|(7)|
|―|―|73|U7|P9_1|I(s)/O|―|―|―|―|ET_<br>MDIO|I(s)/O|SD_<br>D0_0|I(s)/O|CTS0|I(s)/O|―|―|―|―|―|―|―|―|(7)|
|58|―|74|―|Vcc|||||||||||||||||||||
|59|P7|75|R8|P2_2|I(s)/O|―|―|CAS|O|CAN1RX|I(s)|TIOC0C|I(s)/O|IRQ5|I(s)|―|―|―|―|―|―|―|―|(7)|
|60|R7|76|T8|P2_3|I(s)/O|―|―|CKE|O|CAN1TX|O|TIOC0D|I(s)/O|―|―|―|―|―|―|―|―|―|―|(7)|
|61|―|77|―|Vss|||||||||||||||||||||
|62|―|78|―|PVcc|||||||||||||||||||||
|63|M7|79|R9|P0_0|I(s)|MD_<br>BOOT0|I(s)|―|―|RxD0|I(s)|IRQ4|I(s)|―|―|―|―|―|―|―|―|―|―|(3)|
|64|N7|80|U8|P0_1|I(s)|MD_<br>BOOT1|I(s)|―|―|RxD2|I(s)|SSIRxD3|I(s)|ADTRG|I(s)|―|―|―|―|―|―|―|―|(3)|
|65|M8|81|T10|P0_2|I(s)|MD_<br>CLK|I(s)|―|―|RxD1|I(s)|IRQ7|I(s)|―|―|―|―|―|―|―|―|―|―|(3)|
|66|M6|82|R10|P0_3|I(s)|MD_<br>CLKS|I(s)|―|―|RxD3|I(s)|SPDIF_<br>IN|I(s)|―|―|―|―|―|―|―|―|―|―|(3)|
|67|P8|83|T9|RTC_X1|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(11)|
|68|R8|84|U9|RTC_X2|O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|69|M9|85|P10|PLLVcc|||||||||||||||||||||

|176<br>QFP|176<br>BGA|208<br>QFP|233<br>BGA|Port function/<br>dedicated function|Port function/<br>dedicated function|Mode function|Mode function|Function 1|Function 1|Function 2|Function 2|Function 3|Function 3|Function 4|Function 4|Function 5|Function 5|Function 6|Function 6|Function 7|Function 7|Function 8|Function 8|Simplified<br>Circuit<br>Diagram|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|No.|No.|No.|No.|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Figure 1.5|
|70|R9|86|U11|EXTAL|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(10)|
|71|P9|87|T11|XTAL|O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|72|―|88|―|Vss|||||||||||||||||||||
|73|―|89|―|Vss|||||||||||||||||||||
|74|N9|90|R11|NMI|I(s)|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(3)|
|75|―|91|―|Vss|||||||||||||||||||||
|76|R10|92|U12|RES|I(s)|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(1)|
|77|―|93|―|PVcc|||||||||||||||||||||
|78|P10|94|T12|P1_8|I(s)|―|―|AN0|I(a)|IRQ0|I(s)|RxD0|I(s)|DV0_<br>DATA4|I(s)|―|―|―|―|―|―|―|―|(4)|
|79|N10|95|U13|P1_9|I(s)|―|―|AN1|I(a)|IRQ1|I(s)|RxD1|I(s)|DV0_<br>DATA5|I(s)|―|―|―|―|―|―|―|―|(4)|
|80|R11|96|R12|P1_10|I(s)|―|―|AN2|I(a)|IRQ2|I(s)|RxD2|I(s)|DV0_<br>DATA6|I(s)|―|―|―|―|―|―|―|―|(4)|
|81|N11|97|T13|P1_11|I(s)|―|―|AN3|I(a)|IRQ3|I(s)|RxD3|I(s)|DV0_<br>DATA7|I(s)|―|―|―|―|―|―|―|―|(4)|
|82|P12|98|U14|P1_12|I(s)|―|―|AN4|I(a)|IRQ4|I(s)|ET_<br>RXD0|I(s)|VIO_D4|I(s)|―|―|―|―|―|―|―|―|(4)|
|83|P11|99|T14|P1_13|I(s)|―|―|AN5|I(a)|IRQ5|I(s)|ET_<br>RXD1|I(s)|VIO_D5|I(s)|―|―|―|―|―|―|―|―|(4)|
|84|N12|100|R13|P1_14|I(s)|―|―|AN6|I(a)|IRQ6|I(s)|ET_<br>RXD2|I(s)|VIO_D6|I(s)|―|―|―|―|―|―|―|―|(4)|
|85|R12|101|R14|P1_15|I(s)|―|―|AN7|I(a)|IRQ7|I(s)|ET_<br>RXD3|I(s)|VIO_D7|I(s)|―|―|―|―|―|―|―|―|(4)|
|86|P13|102|T15|AVcc|||||||||||||||||||||
|87|R13|103|U15|AVss|||||||||||||||||||||
|88|R14|104|U16|AVref|||||||||||||||||||||
|89|N14|105|N14|BSCANP|I(s)|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(1)|
|90|―|106|―|PVcc|||||||||||||||||||||
|91|P15|107|T17|AUDIO_<br>X1|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(10)|
|92|N15|108|R17|AUDIO_<br>X2|O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|93|―|109|―|Vss|||||||||||||||||||||
|94|M14|110|P15|P2_4|I(s)/O|―|―|WE0<br>/<br>DQMLL|O|―|―|TIOC4A|I(s)/O|―|―|―|―|―|―|―|―|―|―|(7)|
|95|―|111|―|Vcc|||||||||||||||||||||
|96|M13|112|R16|P2_5|I(s)/O|―|―|WE1<br>/WE<br>/<br>DQMLU|O|―|―|TIOC3A|I(s)/O|―|―|―|―|―|―|―|―|―|―|(7)|
|97|L13|113|M14|TRST|I(s)|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(3)|
|98|L14|114|N15|JP0_1|I|―|―|TDO|O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(6)|
|99|L15|115|P16|JP0_0|I|―|―|TDI|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(2)|
|100|L12|116|M15|TMS|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(2)|
|101|K14|117|N16|TCK|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(2)|
|102|―|118|―|Vss|||||||||||||||||||||
|103|K13|119|N17|P3_0|I(s)/O|―|―|A1|O|SD_<br>D2_0|I(s)/O|LCD0_<br>DATA0|O|ET_<br>TXCLK|I(s)|―|―|―|―|―|―|―|―|(7)|
|104|K12|120|M16|P3_1|I(s)/O|―|―|A2|O|SD_<br>D3_0|I(s)/O|LCD0_<br>DATA1|O|ET_<br>TXER|O|―|―|―|―|―|―|―|―|(7)|
|105|―|121|―|Vcc|||||||||||||||||||||
|106|J13|122|L15|P3_2|I(s)/O|―|―|A3|O|SD_<br>CMD_0|I(s)/O|LCD0_<br>DATA2|O|ET_<br>TXEN|O|―|―|―|―|―|―|―|―|(7)|
|107|―|123|―|Vss|||||||||||||||||||||
|108|J15|124|M17|P3_3|I(s)/O|―|―|A4|O|SD_<br>CLK_0|O|LCD0_<br>DATA3|O|ET_<br>RXCLK|I(s)|―|―|―|―|―|―|―|―|(7)|
|109|―|125|―|PVcc|||||||||||||||||||||
|110|J14|126|L16|P3_4|I(s)/O|―|―|A5|O|SD_<br>D0_0|I(s)/O|LCD0_<br>DATA4|O|ET_<br>RXER|I(s)|―|―|―|―|―|―|―|―|(7)|
|―|―|127|K17|P9_2|I(s)/O|―|―|RSPCK2|I(s)/O|ET_<br>RXCLK|I(s)|SD_<br>CLK_0|O|RTS0|I(s)/O|TIOC1A|I(s)/O|―|―|―|―|―|―|(7)|
|―|―|128|―|Vss|||||||||||||||||||||
|―|―|129|K15|P9_3|I(s)/O|―|―|SSL20|I(s)/O|ET_<br>RXER|I(s)|SD_<br>CMD_0|I(s)/O|SCK0|I(s)/O|TIOC1B|I(s)/O|―|―|―|―|―|―|(7)|
|―|―|130|―|PVcc|||||||||||||||||||||
|111|H15|131|K16|P3_5|I(s)/O|―|―|A6|O|SD_<br>D1_0|I(s)/O|LCD0_<br>DATA5|O|ET_<br>RXDV|I(s)|―|―|―|―|―|―|―|―|(7)|
|112|H13|132|J15|P3_6|I(s)/O|―|―|A7|O|SD_<br>WP_0|I(s)|LCD0_<br>DATA6|O|ET_<br>COL|I(s)|―|―|―|―|―|―|―|―|(7)|
|113|H14|133|J16|P3_7|I(s)/O|―|―|A8|O|SD_<br>CD_0|I(s)|LCD0_<br>DATA7|O|ET_<br>CRS|I(s)|―|―|―|―|―|―|―|―|(7)|
|―|―|134|―|Vss|||||||||||||||||||||
|―|―|135|H17|P9_4|I(s)/O|―|―|MOSI2|I(s)/O|ET_<br>RXDV|I(s)|SD_<br>D3_0|I(s)/O|RxD0|I(s)|TIOC2A|I(s)/O|―|―|―|―|―|―|(7)|

|176<br>QFP|176<br>BGA|208<br>QFP|233<br>BGA|Port function/<br>dedicated function|Port function/<br>dedicated function|Mode function|Mode function|Function 1|Function 1|Function 2|Function 2|Function 3|Function 3|Function 4|Function 4|Function 5|Function 5|Function 6|Function 6|Function 7|Function 7|Function 8|Function 8|Simplified<br>Circuit<br>Diagram|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|No.|No.|No.|No.|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Figure 1.5|
|―|―|136|―|PVcc|||||||||||||||||||||
|―|―|137|H16|P9_5|I(s)/O|―|―|MISO2|I(s)/O|―|―|SD_<br>D2_0|I(s)/O|TxD0|O|TIOC2B|I(s)/O|―|―|―|―|―|―|(7)|
|114|G12|138|H15|P3_8|I(s)/O|―|―|A9|O|―|―|AUDIO_C<br>LK|I(s)|DV0_<br>DATA8|I(s)|SCK3|I(s)/O|―|―|―|―|―|―|(7)|
|115|G13|139|H14|P3_9|I(s)/O|―|―|A10|O|―|―|SPDIF_<br>OUT|O|DV0_<br>DATA9|I(s)|TxD3|O|―|―|―|―|―|―|(7)|
|116|―|140|―|Vss|||||||||||||||||||||
|117|G15|141|G14|P3_10|I(s)/O|―|―|A11|O|SPBIO<br>01_0|I(s)/O|TIOC3B|I(s)/O|DV0_<br>DATA10|I(s)|RxD3|I(s)|―|―|―|―|―|―|(7)|
|118|G14|142|G17|P3_11|I(s)/O|―|―|A12|O|SPBIO<br>11_0|I(s)/O|TIOC3A|I(s)/O|DV0_<br>DATA11|I(s)|―|―|―|―|―|―|―|―|(7)|
|119|―|143|―|Vcc|||||||||||||||||||||
|120|F15|144|G16|P3_12|I(s)/O|―|―|A13|O|SPBIO<br>21_0|I(s)/O|TIOC3C|I(s)/O|DV0_<br>DATA12|I(s)|―|―|―|―|―|―|―|―|(7)|
|121|―|145|―|Vss|||||||||||||||||||||
|122|F14|146|G15|P3_13|I(s)/O|―|―|A14|O|SPBIO31_<br>0|I(s)/O|TIOC3D|I(s)/O|DV0_<br>DATA13|I(s)|―|―|―|―|―|―|―|―|(7)|
|123|―|147|―|PVcc|||||||||||||||||||||
|124|F13|148|F17|P3_14|I(s)/O|―|―|A15|O|VIO_CLK|I(s)|SPDIF_<br>IN|I(s)|DV0_<br>DATA14|I(s)|SCK1|I(s)/O|AUDIO_<br>XOUT2|O|―|―|―|―|(7)|
|125|E14|149|F16|P1_0|I(s)/O(o)|―|―|RIIC0SCL|I(s)/<br>O(o)|IRQ4|I(s)|ET_<br>RXD0|I(s)|DV0_<br>DATA0|I(s)|―|―|―|―|―|―|―|―|(9)|
|126|E15|150|F15|P1_1|I(s)/O(o)|―|―|RIIC0SDA|I(s)/<br>O(o)|IRQ5|I(s)|ET_<br>RXD1|I(s)|DV0_<br>DATA1|I(s)|―|―|―|―|―|―|―|―|(9)|
|127|E13|151|E17|P1_2|I(s)/O(o)|―|―|RIIC1SCL|I(s)/<br>O(o)|IRQ6|I(s)|ET_<br>RXD2|I(s)|DV0_<br>DATA2|I(s)|―|―|―|―|―|―|―|―|(9)|
|128|D15|152|E16|P1_3|I(s)/O(o)|―|―|RIIC1SDA|I(s)/<br>O(o)|IRQ7|I(s)|ET_<br>RXD3|I(s)|DV0_<br>DATA3|I(s)|―|―|―|―|―|―|―|―|(9)|
|129|D14|153|E15|P1_4|I(s)/O(o)|―|―|RIIC2SCL|I(s)/<br>O(o)|IRQ0|I(s)|DREQ0|I(s)|VIO_D0|I(s)|―|―|―|―|―|―|―|―|(9)|
|130|C15|154|D17|P1_5|I(s)/O(o)|―|―|RIIC2SDA|I(s)/<br>O(o)|IRQ1|I(s)|―|―|VIO_D1|I(s)|―|―|―|―|―|―|―|―|(9)|
|131|C14|155|D16|P1_6|I(s)/O(o)|―|―|RIIC3SCL|I(s)/<br>O(o)|IRQ2|I(s)|SSIRxD0|I(s)|VIO_D2|I(s)|―|―|―|―|―|―|―|―|(9)|
|132|B15|156|C17|P1_7|I(s)/O(o)|―|―|RIIC3SDA|I(s)/<br>O(o)|IRQ3|I(s)|RxD2|I(s)|VIO_D3|I(s)|―|―|―|―|―|―|―|―|(9)|
|133|A14|157|A16|P3_15|I(s)/O|―|―|A16|O|VIO_<br>FLD|I(s)|―|―|DV0_<br>DATA15|I(s)|TxD1|O|―|―|―|―|―|―|(7)|
|134|B13|158|A15|P2_6|I(s)/O|―|―|RD/WR|O|SSIRxD3|I(s)|TIOC2A|I(s)/O|―|―|―|―|―|―|―|―|―|―|(7)|
|135|C12|159|B15|P2_7|I(s)/O|―|―|CS0|O|SSISCK3|I(s)/O|TIOC1A|I(s)/O|IRQ2|I(s)|―|―|―|―|―|―|―|―|(7)|
|136|A13|160|B14|P2_8|I(s)/O|―|―|RD|O|SSITxD3|O|TIOC0A|I(s)/O|―|―|CAN0TX|O|―|―|―|―|―|―|(7)|
|137|B12|161|C14|P2_9|I(s)/O|―|―|A0|O|SSIWS3|I(s)/O|SCK0|I(s)/O|IRQ1|I(s)|CAN0RX|I(s)|―|―|―|―|―|―|(7)|
|138|―|162|―|Vss|||||||||||||||||||||
|139|A12|163|A14|USB_X1|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|(10)|
|140|B11|164|B13|USB_X2|O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|141|―|165|―|USBDP<br>Vcc|||||||||||||||||||||
|142|―|166|―|USBDP<br>Vss|||||||||||||||||||||
|143|B10|167|B12|DM1|I/O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|144|A10|168|A12|DP1|I/O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|145|C10|169|C12|VBUS1|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|146|―|170|―|USBD<br>Vcc|||||||||||||||||||||
|147|―|171|―|USBD<br>Vss|||||||||||||||||||||
|148|―|172|―|USBDP<br>Vcc|||||||||||||||||||||
|149|―|173|―|USBDP<br>Vss|||||||||||||||||||||
|150|A9|174|A11|DM0|I/O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|151|B9|175|B11|DP0|I/O|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|152|C9|176|C11|VBUS0|I|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|153|―|177|―|USBD<br>Vcc|||||||||||||||||||||
|154|―|178|―|USBD<br>Vss|||||||||||||||||||||
|155|B8|179|B10|REFRIN|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―|―||
|156|―|180|―|USBAP<br>Vss|||||||||||||||||||||
|157|D10|181|D12|USBAP<br>Vcc|||||||||||||||||||||
|158|C8|182|C10|USBA<br>Vcc|||||||||||||||||||||

|176<br>QFP|176<br>BGA|208<br>QFP|233<br>BGA|Port function/<br>dedicated function|Port function/<br>dedicated function|Mode function|Mode function|Function 1|Function 1|Function 2|Function 2|Function 3|Function 3|Function 4|Function 4|Function 5|Function 5|Function 6|Function 6|Function 7|Function 7|Function 8|Function 8|Simplified<br>Circuit<br>Diagram|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|No.|No.|No.|No.|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Symbol|I/O|Figure 1.5|
|159|―|183|―|USBA<br>Vss|||||||||||||||||||||
|160|―|184|―|USBU<br>Vcc|||||||||||||||||||||
|161|―|185|―|USBU<br>Vss|||||||||||||||||||||
|162|―|186|―|Vss|||||||||||||||||||||
|163|―|187|―|Vss|||||||||||||||||||||
|164|C7|188|A9|P4_0|I(s)/O|―|―|A17|O|VIO_VD|I(s)|TIOC1B|I(s)/O|ET_<br>MDC|O|CTS1|I(s)/O|―|―|―|―|―|―|(7)|
|165|B7|189|C9|P4_1|I(s)/O|―|―|A18|O|VIO_HD|I(s)|TIOC2B|I(s)/O|ET_<br>MDIO|I(s)/O|RTS1|I(s)/O|―|―|―|―|―|―|(7)|
|166|C6|190|A8|P4_2|I(s)/O|―|―|A19|O|SPBIO<br>20_0|I(s)/O|TRACE<br>DATA2*3|O|―|―|―|―|―|―|―|―|―|―|(7)|
|167|A6|191|B8|P4_3|I(s)/O|―|―|A20|O|SPBIO<br>30_0|I(s)/O|TRACE<br>DATA3*3|O|―|―|―|―|―|―|―|―|―|―|(7)|
|―|―|192|C8|P8_0|I(s)/O|―|―|LCD0_<br>DATA0|O|ET_<br>TXD0|O|SSISCK1|I(s)/O|SCK3|I(s)/O|―|―|―|―|―|―|―|―|(7)|
|―|―|193|―|Vss|||||||||||||||||||||
|―|―|194|B7|P8_1|I(s)/O|―|―|LCD0_<br>DATA1|O|ET_<br>TXD1|O|SSIWS1|I(s)/O|RxD3|I(s)|―|―|―|―|―|―|―|―|(7)|
|―|―|195|―|PVcc|||||||||||||||||||||
|168|B6|196|C7|P4_4|I(s)/O|―|―|A21|O|SPBCLK_<br>0|O|TRACE<br>CLK*3|O|―|―|―|―|―|―|―|―|―|―|(7)|
|169|A5|197|A6|P4_5|I(s)/O|―|―|A22|O|SPBSSL_<br>0|O|TRACE<br>CTL*3|O|―|―|―|―|―|―|―|―|―|―|(7)|
|―|―|198|B6|P8_2|I(s)/O|―|―|LCD0_<br>DATA2|O|ET_<br>TXD2|O|SSITxD1|O|TxD3|O|―|―|―|―|―|―|―|―|(7)|
|―|―|199|D7|P8_3|I(s)/O|―|―|LCD0_<br>DATA3|O|ET_<br>TXD3|O|SSIRxD1|I(s)|―|―|―|―|―|―|―|―|―|―|(7)|
|―|―|200|C6|P8_4|I(s)/O|―|―|LCD0_<br>DATA4|O|ET_<br>TXCLK|I(s)|―|―|CTS2|I(s)/O|TIOC0A|I(s)/O|―|―|―|―|―|―|(7)|
|―|―|201|B5|P8_5|I(s)/O|―|―|LCD0_<br>DATA5|O|ET_<br>TXER|O|―|―|RTS2|I(s)/O|TIOC0B|I(s)/O|―|―|―|―|―|―|(7)|
|170|B5|202|A5|P4_6|I(s)/O|―|―|A23|O|SPBIO<br>00_0|I(s)/O|TRACE<br>DATA0*3|O|―|―|―|―|―|―|―|―|―|―|(7)|
|171|―|203|―|Vss|||||||||||||||||||||
|172|C5|204|C5|P4_7|I(s)/O|―|―|A24|O|SPBIO<br>10_0|I(s)/O|TRACE<br>DATA1*3|O|―|―|―|―|―|―|―|―|―|―|(7)|
|173|A4|205|A4|P5_0|I(s)/O|―|―|D0|I(s)/O|MMC_D4|I(s)/O|ET_<br>TXD0|O|DV0_<br>DATA16|I(s)|LCD0_<br>TCON0|O|―|―|―|―|―|―|(8)|
|174|―|206|―|PVcc|||||||||||||||||||||
|175|B4|207|B4|P5_1|I(s)/O|―|―|D1|I(s)/O|MMC_D5|I(s)/O|ET_<br>TXD1|O|DV0_<br>DATA17|I(s)|LCD0_<br>TCON1|O|―|―|―|―|―|―|(8)|
|176|A3|208|A3|P5_2|I(s)/O|―|―|D2|I(s)/O|MMC_D6|I(s)/O|ET_<br>TXD2|O|DV0_<br>DATA18|I(s)|LCD0_<br>TCON2|O|―|―|―|―|―|―|(8)|

[Legend]

(s): Schmitt

(a): Analog

## (o): Open drain

Note: • Pins to which the PVcc, Vcc, and Vss functions can be allocated on 176-pin BGA products are listed below. PVcc: D4, D11, D13, E4, E12, F12, K4, L4, M5, M10, M11, P1 Vcc: A2, B3, C4, D5, D6, D7, M12, N13, P14, R15

Vss: A1, A7, A8, A11, A15, B2, B14, C3, C11, C13, D8, D9, D12, G4, H4, H12, J12, K15, L1, M4, M15, N3, N8, P2, R1, R3

Note: • Pins to which the PVcc, Vcc, and Vss functions can be allocated on 233-pin BGA products are listed below. PVcc: B17, C13, C16, D8, D9, D15, E14, F4, F14, G4, L4, M4, N4, P1, P8, P9, P12, P13 Vcc: A2, B3, C4, D5, D6, H4, J4, J14, K14, L14, P14, R15, T16, U17

Vss: A1, A7, A10, A13, A17, B2, B9, B16, C3, C15, D4, D10, D11, D13, D14, G7, G8, G9, G10, G11, H7, H8, H9, H10, H11, J7, J8, J9, J10, J11, J17, K7, K8, K9, K10, K11, L7, L8, L9, L10, L11, L17, M1, P4, P11, P17, R3, T2, U1, U3, U10

- Note 1. RZ/A1L only. "-" for the RZ/A1LC.

Note 2. RZ/A1LU only. "-" for the RZ/A1LC.

Note 3. RZ/A1L only. "-" for the RZ/A1LU and RZ/A1LC.

Note 4. RZ/A1LU and RZ/A1LC only. "-" for the RZ/A1L.

**==> picture [483 x 291] intentionally omitted <==**

**----- Start of picture text -----**<br>
PAD<br>Schmitt input data<br>Figure 1.5 (1) Simplified Circuit Diagram (Schmitt Input Buffer)<br>PAD<br>TTL input data<br>TTL input enable<br>Figure 1.5 (2) Simplified Circuit Diagram (TTL AND Input Buffer)<br>PAD<br>Schmitt input data<br>Schmitt input enable<br>Figure 1.5 (3) Simplified Circuit Diagram (Schmitt AND Input Buffer)<br>**----- End of picture text -----**<br>

**==> picture [245 x 121] intentionally omitted <==**

**----- Start of picture text -----**<br>
A/D analog input enable<br>PAD<br>A/D analog input data<br>Schmitt input data<br>Schmitt input enable<br>**----- End of picture text -----**<br>

**==> picture [367 x 10] intentionally omitted <==**

**----- Start of picture text -----**<br>
Figure 1.5 (4) Simplified Circuit Diagram (Schmitt OR Input and A/D Input Buffer)<br>**----- End of picture text -----**<br>

**==> picture [483 x 115] intentionally omitted <==**

**----- Start of picture text -----**<br>
Latch enable<br>Output enable<br>PAD<br>Output data<br>Figure 1.5 (5) Simplified Circuit Diagram (Output Buffer with Enable, with Latch)<br>**----- End of picture text -----**<br>

**==> picture [240 x 140] intentionally omitted <==**

**----- Start of picture text -----**<br>
Latch enable<br>Output enable<br>PAD<br>Output data<br>TTL input data<br>TTL input enable<br>**----- End of picture text -----**<br>

**Figure 1.5 (6) Simplified Circuit Diagram (Bidirectional Buffer, TTL AND Input, with Latch)**

**==> picture [252 x 140] intentionally omitted <==**

**----- Start of picture text -----**<br>
Latch enable<br>Output enable<br>PAD<br>Output data<br>Schmitt input data<br>Schmitt input enable<br>**----- End of picture text -----**<br>

**Figure 1.5 (7) Simplified Circuit Diagram (Bidirectional Buffer, Schmitt AND Input, with Latch)**

**==> picture [252 x 206] intentionally omitted <==**

**----- Start of picture text -----**<br>
Latch enable<br>Output enable<br>PAD<br>Output data<br>TTL input data<br>TTL input enable<br>Schmitt input data<br>Schmitt input enable<br>**----- End of picture text -----**<br>

**==> picture [441 x 21] intentionally omitted <==**

**----- Start of picture text -----**<br>
Figure 1.5 (8) Simplified Circuit Diagram (Bidirectional Buffer, TTL AND Input, Schmitt AND Input,<br>with Latch)<br>**----- End of picture text -----**<br>

**==> picture [253 x 110] intentionally omitted <==**

**----- Start of picture text -----**<br>
PAD<br>Output data<br>Schmitt input data<br>Schmitt input enable<br>**----- End of picture text -----**<br>

**Figure 1.5 (9) Simplified Circuit Diagram (Open Drain Output and Schmitt OR Input Buffer)**

**==> picture [339 x 169] intentionally omitted <==**

**----- Start of picture text -----**<br>
XOUT Input clock<br>(XTAL, AUDIO_X2, USB_X2)<br>XIN<br>(EXTAL, AUDIO_X1, USB_X1)<br>Input enable<br>**----- End of picture text -----**<br>

**Figure 1.5 (10) Simplified Circuit Diagram (Oscillation Buffer 1)**

**==> picture [278 x 157] intentionally omitted <==**

**----- Start of picture text -----**<br>
XOUT<br>(RTC_X2) Input clock<br>XIN<br>(RTC_X1)<br>Input enable<br>**----- End of picture text -----**<br>

**Figure 1.5 (11) Simplified Circuit Diagram (Oscillation Buffer 2)**
