# 44. JPEG Codec Unit

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2285–2330. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This module is only incorporated in the RZ/A1LU.

The JPEG codec unit (JCU) incorporates a JPEG codec conforming to the JPEG baseline compression and decompression standard to provide high-speed compression of image data and high-speed decoding of JPEG data.

## 44.1 Features

The JPEG codec unit has the following features:

- Conforms to the JPEG baseline standard within the range described in this document. This module does not support the following basic features:

   - Scanning with two elements

   - Non-interleave scanning with multiple elements

- Operational precision: Conforming to JPEG Part 2, ISO-IEC10918-2

- Image input/output system: Block interleave method

- Pixel format: Compression: YCbCr422 (H = 2:1:1, V = 1:1:1)

   - Decompression: YCbCr444 (H = 1:1:1, V = 1:1:1), YCbCr422 (H = 2:1:1, V = 1:1:1), YCbCr411 (H = 4:1:1, V = 1:1:1), YCbCr420 (H = 2:1:1, V = 2:1:1)

Output pixel format to the buffer: YCbCr422, ARGB8888, RGB565

- Four quantization tables provided

- Four Huffman tables provided (two tables for AC coefficients and two tables for DC coefficients)

- Markers supported: SOI (start of image), SOF0 (start of frame type 0), SOS (start of scan), DQT (define quantization tables), DHT (define Huffman tables), DRI (define restart interval), RSTm (restart marks), and EOI (end of image)

- Image data rate: Max. 133.34 Mbytes/s (at 66.67-MHz operation)

- The buffer size can be reduced by using the mode in which data transfer is temporarily stopped each time the specified number of lines or the specified amount of data is transferred during image data or coded data input/ output.

- Processing unit: 8-byte address boundary units can be set

- Image sizes that can be processed: Sizes divisible by the minimum coded unit (MCU): 8 lines by 8 pixels in YCbCr444; 8 lines by 16 pixels in YCbCr422; 8 lines by 32 pixels in YCbCr411; 16 lines by 16 pixels in YCbCr420

Note: • Compression and decompression processing of images in unsupported pixel formats or unsupported image sizes should be avoided.

## Figure 44.1 shows a block diagram.

**==> picture [426 x 310] intentionally omitted <==**

**----- Start of picture text -----**<br>
 Internal bus  Internal bus<br>JPEG codec unit<br>JPEG core<br>Huffman coder<br>DCT, quantizer marker processing<br>Quantization table Huffman table<br>Data output bus<br>Data input bus interface<br>interface<br>Control circuit,<br>JPEG core registers<br> Input bus control register  Output bus control register<br>Module data bus<br>Bus interface<br>Peripheral bus<br>**----- End of picture text -----**<br>

**Figure 44.1 Block Diagram**

## 44.2 Register Descriptions

Table 44.1 shows the JCU registers.

## **Table 44.1 Register Configuration**

|**Table 44.1**<br>**Register Configuration**|||||
|---|---|---|---|---|
|||||**Access**|
|**Register Name**|**Abbreviation**|**R/W**|**Address**|**Size**|
|JPEG code mode register|JCMOD|R/W|H'E801 7000|8|
|JPEG code command register|JCCMD|R/W|H'E801 7001|8|
|JPEG code quantization table number register|JCQTN|R/W|H'E801 7003|8|
|JPEG code Huffman table number register|JCHTN|R/W|H'E801 7004|8|
|JPEG code DRI upper register|JCDRIU|R/W|H'E801 7005|8|
|JPEG code DRI lower register|JCDRID|R/W|H'E801 7006|8|
|JPEG code vertical size upper register|JCVSZU|R/W|H'E801 7007|8|
|JPEG code vertical size lower register|JCVSZD|R/W|H'E801 7008|8|
|JPEG code horizontal size upper register|JCHSZU|R/W|H'E801 7009|8|
|JPEG code horizontal size lower register|JCHSZD|R/W|H'E801 700A|8|
|JPEG code data count upper register|JCDTCU|R|H'E801 700B|8|
|JPEG code data count middle register|JCDTCM|R|H'E801 700C|8|
|JPEG code data count lower register|JCDTCD|R|H'E801 700D|8|
|JPEG interrupt enable register 0|JINTE0|R/W|H'E801 700E|8|
|JPEG interrupt status register 0|JINTS0|R/W|H'E801 700F|8|
|JPEG code decode error register|JCDERR|R/W|H'E801 7010|8|
|JPEG code reset register|JCRST|R|H'E801 7011|8|
|JPEG interface compression control register|JIFECNT|R/W|H'E801 7040|32|
|JPEG interface compression source address register|JIFESA|R/W|H'E801 7044|32|
|JPEG interface compression line offset register|JIFESOFST|R/W|H'E801 7048|32|
|JPEG interface compression destination address register|JIFEDA|R/W|H'E801 704C|32|
|JPEG interface compression source line count register|JIFESLC|R/W|H'E801 7050|32|
|JPEG interface compression destination register|JIFEDDC|R/W|H'E801 7054|32|
|JPEG interface decompression control register|JIFDCNT|R/W|H'E801 7058|32|
|JPEG interface decompression source address register|JIFDSA|R/W|H'E801 705C|32|
|JPEG interface decompression destination offset register|JIFDDOFST|R/W|H'E801 7060|32|
|JPEG interface decompression destination address register|JIFDDA|R/W|H'E801 7064|32|
|JPEG interface decompression source count register|JIFDSDC|R/W|H'E801 7068|32|
|JPEG interface decompression destination line count register|JIFDDLC|R/W|H'E801 706C|32|
|JPEG interface decompressionsetting register|JIFDADT|R/W|H'E801 7070|32|
|JPEG interrupt enable register 1|JINTE1|R/W|H'E801 708C|32|
|JPEG interrupt status register 1|JINTS1|R/W|H'E801 7090|32|
|JPEG input image data CbCr range setting register|JIFESVSZ|R/W|H’E801 7094|32|
|JPEG output image data CbCr range setting register|JIFESHSZ|R/W|H’E801 7098|32|
|JPEG code quantization table 0 register|JCQTBL0|R/W|H'E801 7100 to|8|
||||H'E801 713F||
|JPEG code quantization table 1 register|JCQTBL1|R/W|H'E801 7140 to|8|
||||H'E801 717F||
|JPEG code quantization table 2 register|JCQTBL2|R/W|H'E801 7180 to|8|
||||H'E801 71BF||
|JPEG code quantization table 3 register|JCQTBL3|R/W|H'E801 71C0 to|8|
||||H'E801 71FF||

## **Table 44.1 Register Configuration**

|**Table 44.1**<br>**Register Configuration**|||||
|---|---|---|---|---|
|||||**Access**|
|**Register Name**|**Abbreviation**|**R/W**|**Address**|**Size**|
|JPEG code Huffman table DC0 register|JCHTBD0|W|H'E801 7200 to|8|
||||H'E801 721B||
|JPEG code Huffman table AC0 register|JCHTBA0|W|H'E801 7220 to|8|
||||H'E801 72D1||
|JPEG code Huffman table DC1 register|JCHTBD1|W|H'E801 7300 to|8|
||||H'E801 731B||
|JPEG code Huffman table AC1 register|JCHTBA1|W|H'E801 7320 to|8|
||||H'E801 73D1||

Note: • For the settings of the JPEG code quantization table and JPEG code Huffman table, see section 44.3.1 (4), Table Setting.

## 44.2.1 JPEG Code Mode Register (JCMOD)

JCMOD sets the operating mode before the JCU starts operation.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R/W<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>—<br>—<br>—<br>—<br>DSP<br>REDU[2:0]|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R/W<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>—<br>—<br>—<br>—<br>DSP<br>REDU[2:0]|
|---|---|
|7 to 4<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|3<br>DSP<br>0|R/W<br>Compression/Decompression Set<br>0: Compression process<br>1: Decompression process<br>Note: • When changing between processing for compression and for<br>decompression, be sure to reset this module in advance by<br>setting the SRST21 bit in the software reset control register 2<br>(SWRSTCR2) of the power-down modes.|
|2 to 0<br>REDU[2:0]<br>000|R/W<br>R<br>Pixel Format<br>[Compression]<br>001: YCbCr422<br>Other than above: Setting prohibited.<br>[Decompression]<br>000: YCbCr444<br>001: YCbCr422<br>110: YCbCr411<br>010: YCbCr420<br>Other than above: Error (JCU cannot process normally.)|

## 44.2.2 JPEG Code Command Register (JCCMD)

JCCMD sets commands. Bits of this register need not be cleared to 0 after setting a command. Multiple commands must not be set simultaneously.

|Bit:|Bit:|7|6|5|4|3<br>2<br>1||0|
|---|---|---|---|---|---|---|---|---|
|||BRST|—|—|—|JEND JRST <br>—||JSRT|
|Initial value:||0|0|0|0|0<br>0<br>0||0|
|R/W(compress):||R*/W|R|R|R|R<br>R*/W Undefined||R*/W|
|R/W(decompress):||R*/W|R|R|R|R<br>R*/W R*/W||R*/W|
|Note:*||Values read||from these bits are undefined.|||||

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|7<br>BRST<br>0|R*/W<br>Bus Reset<br>Setting this bit to 1 resets the internal circuits.<br>While the JCU is in operation (from setting the JPEG core process start<br>command to writing the last output coded/image data), do not set this<br>bit to 1.<br>For the bus reset processing, see section 44.5, Bus Reset Processing.|
|6 to 3<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|2<br>JEND<br>0|R*/W<br>Interrupt Request Clear Command<br>This bit is valid only for the interrupt sources corresponding to bits<br>INS6, INS5, and INS3 in JINTS0.<br>To clear an interrupt request, set this bit to 1.|
|1<br>JRST<br>0|Invalid<br>R*/W<br>JPEG Core Process Stop Clear Command<br>To clear the process-stopped state caused by requests to read the<br>image size and pixel format (enabled by the INT3 bit in JINTE0), set<br>this bit to 1.|
|0<br>JSRT<br>0|R*/W<br>JPEG Core Process Start Command<br>To start JPEG core processing, set this bit to 1. Do not write this bit to<br>1 again while the JCU is in operation.|

Note: * Values read from these bits are undefined.

## 44.2.3 JPEG Code Quantization Table Number Register (JCQTN)

JCQTN sets the quantization table number before compression process is started.

- To use quantization table No. 0 (JCQTBL0) as the first color component, set QT1 to B'00

- To use quantization table No. 1 (JCQTBL1) as the first color component, set QT1 to B'01

- To use quantization table No. 2 (JCQTBL2) as the first color component, set QT1 to B'10

- To use quantization table No. 3 (JCQTBL3) as the first color component, set QT1 to B'11

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>—<br>QT3[1:0]<br>QT1[1:0]<br>—<br>QT2[1:0]|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>—<br>QT3[1:0]<br>QT1[1:0]<br>—<br>QT2[1:0]|
|---|---|
|7, 6<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|5, 4<br>QT3[1:0]<br>00|R/W<br>R<br>Quantization table number for the third color component|
|3, 2<br>QT2[1:0]<br>00|R/W<br>R<br>Quantization table number for the second color component|
|1, 0<br>QT1[1:0]<br>00|R/W<br>R<br>Quantization table number for the first color component|

## 44.2.4 JPEG Code Huffman Table Number Register (JCHTN)

JCHTN sets the Huffman table number (AC/DC) before compression process is started.

- To use DC/AC Huffman table No. 0 (JCHTBD0 and JCHTBA0) as the first color component, set bits HTA1 and HTD1 to B'0

- To use DC/AC Huffman table No. 1 (JCHTBD1 and JCHTBA1) as the first color component, set bits HTA1 and HTD1 to B'1

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>—<br>HTA3<br>HTD2 HTA1 HTD1<br>—<br>HTD3 HTA2|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>—<br>HTA3<br>HTD2 HTA1 HTD1<br>—<br>HTD3 HTA2|
|---|---|
|7, 6<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|5<br>HTA3<br>0|R/W<br>R<br>Huffman table number (AC) for the third color component|
|4<br>HTD3<br>0|R/W<br>R<br>Huffman table number (DC) for the third color component|
|3<br>HTA2<br>0|R/W<br>R<br>Huffman table number (AC) for the second color component|
|2<br>HTD2<br>0|R/W<br>R<br>Huffman table number (DC) for the second color component|
|1<br>HTA1<br>0|R/W<br>R<br>Huffman table number (AC) for the first color component|
|0<br>HTD1<br>0|R/W<br>R<br>Huffman table number (DC) for the first color component|

## 44.2.5 JPEG Code DRI Upper Register (JCDRIU)

JCDRIU sets the upper bytes of the minimum coded units (MCUs) preceding an RST marker.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|||||DRIU[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W(compress):|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|R/W(decompress):|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|

## **R/W**

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|---|---|
|7 to 0<br>DRIU[7:0]<br>H'00|R/W<br>Invalid<br>Upper Bytes of MCUs Preceding RST Marker<br>When both upper and lower bytes are set to H'00, neither a DRI nor an<br>RST marker is placed.|

## 44.2.6 JPEG Code DRI Lower Register (JCDRID)

JCDRID sets the lower bytes of MCUs preceding an RST marker.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|||||DRID[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W(compress):|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|R/W(decompress):|Undefined|Undefined|Undefined|Undefined|Undefined Undefined||Undefined|Undefined|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|7 to 0<br>DRID[7:0]<br>H'00|R/W<br>Invalid<br>Lower Bytes of MCUs Preceding RST Marker<br>When both upper and lower bytes are set to H'00, neither a DRI nor an<br>RST marker is placed.|

## 44.2.7 JPEG Code Vertical Size Upper Register (JCVSZU)

JCVSZU sets the upper bytes of the vertical image size.

|7<br>Bit:|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|
||||VSZU[7:0]|||||
|Initial value:<br>0|0|0|0|0|0|0|0|
|R/W(compress):<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|R/W(decompress):<br>R|R|R|R|R|R|R|R|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|7 to 0<br>VSZU[7:0]<br>H'00|R/W<br>R<br>Upper Bytes of Vertical Image Size<br>In decompression process, a downloaded value from the JPEG coded<br>data is set.|

## 44.2.8 JPEG Code Vertical Size Lower Register (JCVSZD)

JCVSZD sets the lower bytes of the vertical image size.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>VSZD[7:0]|
|---|---|
|7 to 0<br>VSZD[7:0]<br>H'00|R/W<br>R<br>Lower Bytes of Vertical Image Size<br>In decompression process, a downloaded value from the JPEG coded<br>data is set.|

## 44.2.9 JPEG Code Horizontal Size Upper Register (JCHSZU)

JCHSZU sets the upper bytes of the horizontal image size.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>HSZU[7:0]|
|---|---|
|7 to 0<br>HSZU[7:0]<br>H'00|R/W<br>R<br>Upper Bytes of Horizontal Image Size<br>In decompression process, a downloaded value from the JPEG coded<br>data is set.|

## 44.2.10 JPEG Coded Horizontal Size Lower Register (JCHSZD)

JCHSZD sets the lower bytes of the horizontal image size.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
|||||HSZD[7:0]|||||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W(compress):|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|R/W(decompress):|R|R|R|R|R|R|R|R|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|7 to 0<br>HSZD[7:0]<br>H'00|R/W<br>R<br>Lower Bytes of Horizontal Image Size<br>In decompression process, a downloaded value from the JPEG coded<br>data is set.|

## 44.2.11 JPEG Code Data Count Upper Register (JCDTCU)

The upper bytes for the counted amount of data to be compressed are set to JCDTCU. The values of this register are reset before compression starts.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>DCU[7:0]|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>DCU[7:0]|
|---|---|
|7 to 0<br>DCU[7:0]<br>H'00|R<br>Invalid<br>Upper bytes of the counted amount of data to be compressed|

## 44.2.12 JPEG Code Data Count Middle Register (JCDTCM)

The middle bytes for the counted amount of data to be compressed are set to JCDTCM. The values of this register are reset before compression starts.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>DCM[7:0]|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>DCM[7:0]|
|---|---|
|7 to 0<br>DCM[7:0]<br>H'00|R<br>Invalid<br>Middle bytes of the counted amount of data to be compressed|

## 44.2.13 JPEG Code Data Count Lower Register (JCDTCD)

The lower bytes for the counted amount of data to be compressed are set to JCDTCD. The values of this register are reset before compression starts.

|7<br>Bit:|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|
||||DCD[7:0]|||||
|Initial value:<br>0|0|0|0|0|0|0|0|
|R/W(compress):<br>R|R|R|R|R|R|R|R|
|R/W(decompress):<br>Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|7 to 0<br>DCD[7:0]<br>H'00|R<br>Invalid<br>Lower bytes of the counted amount of data to be compressed|

## 44.2.14 JPEG Interrupt Enable Register 0 (JINTE0)

## JINTE0 enables interrupts.

When any of bits INT7 to INT5 is set to B'1, the INS5 bit in JINTS0 indicates B'1 as the error status upon occurrence of the compression data error, and the ERR bit in JCDERR indicates the particular error code.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress): R/W<br>R/W<br>R/W<br>R<br>R/W<br>R<br>R<br>R<br>0<br>Undefined Undefined Undefined<br>Undefined<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>INT6<br>INT5<br>—<br>—<br>—<br>INT7<br>—<br>INT3|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress): R/W<br>R/W<br>R/W<br>R<br>R/W<br>R<br>R<br>R<br>0<br>Undefined Undefined Undefined<br>Undefined<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>INT6<br>INT5<br>—<br>—<br>—<br>INT7<br>—<br>INT3|
|---|---|
|7<br>INT7<br>0|Invalid<br>R/W<br>This bit enables an interrupt to be generated when the number of data<br>in the restart interval of the Huffman-coding segment is not correct in<br>decompression.<br>When this bit is not set to enable interrupt generation, an error code is<br>not returned.|
|6<br>INT6<br>0|Invalid<br>R/W<br>This bit enables an interrupt to be generated when the total number of<br>data in the Huffman-coding segment is not correct in decompression.<br>When this bit is not set to enable interrupt generation, an error code is<br>not returned.|
|5<br>INT5<br>0|Invalid<br>R/W<br>This bit enables an interrupt to be generated when the final number of<br>MCU data in the Huffman-coding segment is not correct in<br>decompression.<br>When this bit is not set to enable interrupt generation, an error code is<br>not returned.|
|4<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|3<br>INT3<br>0|Invalid<br>R/W<br>This bit enables an interrupt to be generated when it has been<br>determined that the image size and the subsampling setting of the<br>compressed data can be read through analyzing the data.|
|2 to 0<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|

## 44.2.15 JPEG Interrupt Status Register 0 (JINTS0)

## JINTS0 identifies the interrupt sources.

The interrupt sources of this register should be cleared by clearing the corresponding interrupt status bits to 0 and setting the relevant bit in JCCMD appropriately.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R/W* R/W*<br>R<br>R/W*<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R/W*<br>R<br>Undefined<br>Undefined<br>R<br>R<br>R<br>INS6<br>INS5<br>—<br>—<br>—<br>—<br>—<br>INS3<br>Note:*Clear this bit by writing 0 to it.<br>Do not write 1 to this bit.|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R/W* R/W*<br>R<br>R/W*<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R/W*<br>R<br>Undefined<br>Undefined<br>R<br>R<br>R<br>INS6<br>INS5<br>—<br>—<br>—<br>—<br>—<br>INS3<br>Note:*Clear this bit by writing 0 to it.<br>Do not write 1 to this bit.|
|---|---|
|7<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|6<br>INS6<br>0|R/W<br>This bit is set to 1 when the JCU completes compression process<br>normally.|
|5<br>INS5<br>0|Invalid<br>R/W<br>This bit is set to 1 when a compressed data error occurs.|
|4<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|3<br>INS3<br>0|Invalid<br>R/W<br>This bit is set to 1 when the image size and pixel format can be read.<br>When an interrupt occurs, this module stops processing and the state<br>is indicated by the JCRST register. To make the JCU resume<br>processing, set the JPEG core process stop clear command bit (JRST)<br>in JCCMD.|
|2 to 0<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|

Note:  Clear this bit by writing 0 to it. Do not write 1 to this bit.

## 44.2.16 JPEG Code Decode Error Register (JCDERR)

JCDERR indicates the error code to identify the type of the error which has occurred in the compressed data analysis for decompression. The values of this register are reset before the JCU starts decompression.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>Undefined Undefined Undefined Undefined<br>0<br>0<br>0<br>0<br>1<br>0<br>1<br>0<br>R<br>R<br>R<br>R<br>—<br>—<br>ERR[3:0]<br>—<br>—|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>Undefined Undefined Undefined Undefined<br>0<br>0<br>0<br>0<br>1<br>0<br>1<br>0<br>R<br>R<br>R<br>R<br>—<br>—<br>ERR[3:0]<br>—<br>—|
|---|---|
|7 to 4<br><br>All 0|R<br>Reserved<br>These bits are always read as 0.|
|3 to 0<br>ERR[3:0]<br>1010|Invalid<br>R/W<br>Error Code<br>(See tables 44.3 and 44.4.)|

## 44.2.17 JPEG Code Reset Register (JCRST)

JCRST indicates a processing-stopped state caused by requests to read the image size and pixel format (enabled by the INT3 bit in JINTE0). To resume processing, set the JPEG core process stop clear command bit (JRST) in JCCMD.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined<br>—<br>—<br>—<br>—<br>RST<br>—<br>—<br>—|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined<br>—<br>—<br>—<br>—<br>RST<br>—<br>—<br>—|
|---|---|
|7 to 1<br><br>All 0|R<br>Reserved<br>These bits are always read as 0.|
|0<br>RST<br>0|Invalid<br>R/W<br>Operating State<br>0: State other than below<br>1: Suspended state caused by interrupt sources of JINTE0|

## 44.2.18 JPEG Interface Compression Control Register (JIFECNT)

JIFECNT controls the compression process.

|31<br>Bit:|31<br>Bit:|30|29|28|27|26|25|24|23|22|21||20|19|18||17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—||—|—|—||—|—|
|Initial value:<br>0||0|0|0|0|0|0|0|0|0|0||0|0|0||0|0|
|R/W(compress):<br>R||R|R|R|R|R|R|R|R|R|R||R|R|R||R|R|
|R/W(decompress):<br>R||R|R|R|R|R|R|R|R|R|R||R|R|R||R|R|
|15<br>Bit:||14|13|12|11|10|9|8|7|6|5||4|3|2||1|0|
||—|JOUT<br>RINI|JOUT<br>RCMD|JOUTC|—|JOUTSWAP[2:0]|||—|DIN<br>RINI|DIN<br>RCMD||DIN<br>LC|—|DINSWAP[2:0]||||
|Initial value:<br>0||0|0|0|0|0|0|0|0|0|0||0|0|0||0|0|
|R/W(compress):<br>R||R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W||R/W|R|R/W||R/W|R/W|
|R/W(decompress):<br>R||Undefined|Undefined|Undefined|R|Undefined|Undefined|Undefined|R|Undefined|Undefined|Undefined||R|Undefined||Undefined|Undefined|

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**|
|---|---|
|31 to 15<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|14<br>JOUTRINI<br>0|R/W<br>Invalid<br>Address Initialization when Output Coded Data is Resumed<br>This bit is only valid when the count mode for stopping the output of<br>coded data is on.<br>Set this bit before writing 1 to the data resume command bit.<br>0: The transfer address is not initialized when the output of coded data<br>is restarted.<br>1: The transfer address is initialized when the output of coded data is<br>restarted.|
|13<br>JOUTR<br>CMD<br>0|R/W<br>Invalid<br>Output Coded Data Resume Command<br>This bit is only valid when the count mode for stopping the output of<br>coded data is on.<br>Setting this bit to 1 resumes writing output coded data.<br>This bit is always read as 0.|
|12<br>JOUTC<br>0|R/W<br>Invalid<br>Count Mode Setting for Stopping Output Coded Data<br>0: Count mode for stopping the output of coded data is off.<br>1: Count mode for stopping the output of coded data is on.|
|11<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|10 to 8<br>JOUT<br>SWAP[2:0]<br>000|R/W<br>Invalid<br>Byte/Word/Longword Swap<br>Output coded data in compression is swapped.<br>000: (1) (2) (3) (4) (5) (6) (7) (8)<br>001: (2) (1) (4) (3) (6) (5) (8) (7)<br>[Byte swap]<br>010: (3) (4) (1) (2) (7) (8) (5) (6)<br>[Word swap]<br>011: (4) (3) (2) (1) (8) (7) (6) (5)<br>[Word - byte swap]<br>100: (5) (6) (7) (8) (1) (2) (3) (4)<br>[Longword swap]<br>101: (6) (5) (8) (7) (2) (1) (4) (3)<br>[Longword - byte swap]<br>110: (7) (8) (5) (6) (3) (4) (1) (2)<br>[Longword - word swap]<br>111: (8) (7) (6) (5) (4) (3) (2) (1)<br>[Longword - word - byte swap]|
|7<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|6<br>DINRINI<br>0|R/W<br>Invalid<br>Address Initialization when Resuming Input of Image Data Lines<br>This bit is only valid when the count mode for stopping the input of<br>image data lines is on.<br>Set this bit before writing 1 to the data-line resume command bit.<br>0: The transfer address is not initialized when the input of image data<br>lines is restarted.<br>1: The transfer address is initialized when the input of image data lines<br>is restarted.|
|5<br>DINRCMD<br>0|R/W<br>Invalid<br>Input Image Data Lines Resume Command<br>This bit is valid only when the count mode for stopping the input of<br>image data lines is on.<br>Setting this bit to 1 resumes reading input image data.<br>This bit is always read as 0.|
|4<br>DINLC<br>0|R/W<br>Invalid<br>Count Mode Setting for Stopping Input Image Data Lines<br>0: Count mode for stopping the input of image data lines is off.<br>1: Count mode for stopping the input of image data lines is on.|
|3<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|2 to 0<br>DINSWAP<br>[2:0]<br>000|R/W<br>Invalid<br>Byte/Word Swap<br>Input image data in compression is swapped.<br>000: (1) (2) (3) (4) (5) (6) (7) (8)<br>001: (2) (1) (4) (3) (6) (5) (8) (7)<br>[Byte swap]<br>010: (3) (4) (1) (2) (7) (8) (5) (6)<br>[Word swap]<br>011: (4) (3) (2) (1) (8) (7) (6) (5)<br>[Word - byte swap]<br>100: (5) (6) (7) (8) (1) (2) (3) (4)<br>[Longword swap]<br>101: (6) (5) (8) (7) (2) (1) (4) (3)<br>[Longword - byte swap]<br>110: (7) (8) (5) (6) (3) (4) (1) (2)<br>[Longword - word swap]<br>111: (8) (7) (6) (5) (4) (3) (2) (1)<br>[Longword - word - byte swap]|

## 44.2.19 JPEG Interface Compression Source Address Register (JIFESA)

JIFESA sets the source address of the input image data. This register should be set in 8-byte units.

|JIFESA sets the source address of the input image data. This register should be set in 8-byte units.|JIFESA sets the source address of the input image data. This register should be set in 8-byte units.|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(compress):<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>R/W(decompress):<br>R/W(decompress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R<br>ESA[31:16]<br>ESA[15:0]||
|31 to 3<br>2 to 0<br>ESA[31:3]<br>ESA[2:0]<br>H'0000<br>0000|R/W<br>R<br>Invalid<br>Input Image Data Source Address (in 8-byte units)<br>The lower three bits should be set to 0.|

## 44.2.20 JPEG Interface Compression Line Offset Register (JIFESOFST)

JIFESOFST sets the line offset of the input image data (refer to section 44.3.4, Storing Image Data ). This register should be set in 8-byte units.

|31<br>Bit:|31<br>Bit:|30||29||28||27||26||25||24||23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—||—||—||—||—||—||—||—|—|—|—|—|—|—|—|
|Initial value:<br>0||0||0||0||0||0||0||0||0|0|0|0|0|0|0|0|
|R/W(compress):<br>R||R||R||R||R||R||R||R||R|R|R|R|R|R|R|R|
|R/W(decompress):<br>R||R||R||R||R||R||R||R||R|R|R|R|R|R|R|R|
|15<br>Bit:||14||13||12||11||10||9||8||7|6|5|4|3|2|1|0|
||—|||||||||||||ESMW[14:0]||||||||||
|Initial value:<br>0||0||0||0||0||0||0||0||0|0|0|0|0|0|0|0|
|R/W(compress):<br>R||R/W||R/W||R/W||R/W||R/W||R/W||R/W||R/W|R/W|R/W|R/W|R/W|R|R|R|
|R/W(decompress):<br>R||Undefined||Undefined||Undefined||Undefined||Undefined||Undefined||Undefined||Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|31 to 15<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|14 to 3<br>2 to 0<br>ESMW<br>[14:3]<br>ESMW[2:0]<br>H'0000|R/W<br>R<br>Invalid<br>Input Image Data Lines Offset (in 8-byte units)<br>The lower three bits should be set to 0.|

## 44.2.21 JPEG Interface Compression Destination Address Register (JIFEDA)

JIFEDA sets the destination address of the output coded data. This register should be set in 8-byte units.

|31<br>Bit:|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||EDA[31:16]|||||||||
|Initial value:<br>0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W(compress):<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|R/W(decompress):<br>Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|
|15<br>Bit:|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||EDA[15:0]|||||||||
|Initial value:<br>0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W(compress):<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|
|R/W(decompress):<br>Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|31 to 3<br>2 to 0<br>EDA[31:3]<br>EDA[2:0]<br>H'0000<br>0000|R/W<br>R<br>Invalid<br>Output Coded Data Destination Address (in 8-byte units)<br>The lower three bits should be set to 0.|

## 44.2.22 JPEG Interface Compression Source Line Count Register (JIFESLC)

JIFESLC sets the number of input image data lines when the count mode for stopping the input of image data lines is on (the DINLC bit in JIFECNT is set to 1). This register should be set in 8-line units.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|
|R/W(compress):||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|R/W(decompress):||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||LINES[15:0]|||||||||
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|
|R/W(compress):||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|
|R/W(decompress):||Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|31 to 16<br><br>H'FFF8|R<br>Reserved<br>Values read from these bits are undefined. The write value should<br>always be 0.|
|15 to 3<br>2 to 0<br>LINES[15:3]<br>LINES[2:0]<br>H'FFF8|R/W<br>R<br>Invalid<br>Number of Input Image Data Lines to be Read (in 8-line units)<br>The lower three bits should be set to 0.|

## 44.2.23 JPEG Interface Compression Destination Count Register (JIFEDDC)

JIFEDDC sets the amount of output coded data when the count mode for stopping the output of coded data is on (the JOUTC bit in JIFECNT is set to 1). This register should be set in 8-byte units.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value:|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|
|R/W(compress):|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|R/W(decompress):|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||JDATAS[15:0]|||||||||
|Initial value:|1|1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|
|R/W(compress):|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|
|R/W(decompress):<br>Undefined||Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|31 to 16<br><br>H'FFF8|R<br>Invalid<br>Reserved<br>Values read from these bits are undefined. The write value should<br>always be 0.|
|15 to 3<br>2 to 0<br>JDATAS[15:3]<br>JDATAS[2:0]<br>H'FFF8|R/W<br>R<br>Invalid<br>Amount of Output Coded Data to be Written (in 8-byte units)<br>The lower three bits should be set to 0.|

## 44.2.24 JPEG Interface Decompression Control Register (JIFDCNT)

JIFDCNT controls the decompression process.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(compress):<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R/W<br>R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>Undefined Undefined Undefined<br>R<br>Undefined Undefined Undefined<br>R<br>—<br>—<br>—<br>—<br>—<br>VINTER[1:0] HINTER[1:0]<br>OPF[1:0]<br>—<br>—<br>—<br>DOUT<br>RINI<br>DOUT<br>RCMD<br>DOUT<br>LD<br>JINR<br>INI<br>JINR<br>CMD<br>JINC<br>JINSWAP[2:0]<br>DOUTSWAP[2:0]<br>—<br>—<br>—<br>—<br>—<br>—<br>Undefined Undefined Undefined Undefined Undefined Undefined<br>R<br>Undefined Undefined Undefined<br>Undefined Undefined Undefined|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(compress):<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R/W<br>R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>Undefined Undefined Undefined<br>R<br>Undefined Undefined Undefined<br>R<br>—<br>—<br>—<br>—<br>—<br>VINTER[1:0] HINTER[1:0]<br>OPF[1:0]<br>—<br>—<br>—<br>DOUT<br>RINI<br>DOUT<br>RCMD<br>DOUT<br>LD<br>JINR<br>INI<br>JINR<br>CMD<br>JINC<br>JINSWAP[2:0]<br>DOUTSWAP[2:0]<br>—<br>—<br>—<br>—<br>—<br>—<br>Undefined Undefined Undefined Undefined Undefined Undefined<br>R<br>Undefined Undefined Undefined<br>Undefined Undefined Undefined|
|---|---|
|31, 30<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|29, 28<br>VINTER[1:0]<br>00|Invalid<br>R/W<br>Vertical Subsampling<br>Subsamples vertical output image data.<br>00: No subsampling<br>01: Subsamples output data into 1/2.<br>10: Subsamples output data into 1/4.<br>11: Subsamples output data into 1/8.|
|27, 26<br>HINTER[1:0]<br>00|Invalid<br>R/W<br>Horizontal Subsampling<br>Subsamples horizontal output image data.<br>00: No subsampling<br>01: Subsamples output data into 1/2.<br>10: Subsamples output data into 1/4.<br>11: Subsamples output data into 1/8.|
|25, 24<br>OPF[1:0]<br>00|Invalid<br>R/W<br>Specifies output image data pixel format.<br>00: YCbCr422<br>01: ARGB8888<br>10: RGB565<br>11: Setting prohibited|
|23 to 15<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|14<br>JINRINI<br>0|Invalid<br>R/W<br>Address Initialization when Input Coded Data is Resumed<br>This bit is only valid when the count mode for stopping the input of<br>coded data is on.<br>Set this bit before writing 1 to the data resume command bit.<br>0: The transfer address is not initialized when the input of coded data<br>is restarted.<br>1: The transfer address is initialized when the input of coded data is<br>restarted.|
|13<br>JINRCMD<br>0|Invalid<br>R/W<br>Input Coded Data Resume Command<br>This bit is valid only when the count mode for stopping the input of<br>coded data is on.<br>Setting this bit to 1 resumes reading input coded data.<br>This bit is always read as 0.|
|12<br>JINC<br>0|Invalid<br>R/W<br>Count Mode Setting for Stopping Input Coded Data<br>0: Count mode for stopping the input of coded data is off.<br>1: Count mode for stopping the input of coded data is on.|
|11<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**|
|---|---|
|10 to 8<br>JINSWAP<br>[2:0]<br>000|Invalid<br>R/W<br>Byte/Word/Longword Swap<br>Input coded data in decompression is swapped.<br>000: (1) (2) (3) (4) (5) (6) (7) (8)<br>001: (2) (1) (4) (3) (6) (5) (8) (7)<br>[Byte swap]<br>010: (3) (4) (1) (2) (7) (8) (5) (6)<br>[Word swap]<br>011: (4) (3) (2) (1) (8) (7) (6) (5)<br>[Word - byte swap]<br>100: (5) (6) (7) (8) (1) (2) (3) (4)<br>[Longword swap]<br>101: (6) (5) (8) (7) (2) (1) (4) (3)<br>[Longword - byte swap]<br>110: (7) (8) (5) (6) (3) (4) (1) (2)<br>[Longword - word swap]<br>111: (8) (7) (6) (5) (4) (3) (2) (1)<br>[Longword - word - byte swap]|
|7<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|6<br>DOUTRINI<br>0|Invalid<br>R/W<br>Address Initialization when Resuming Output of Image Data Lines<br>This bit is only valid when the count mode for stopping the output of<br>image data lines is on.<br>Set this bit before writing 1 to the data-line resume command bit.<br>0: The transfer address is not initialized when the output of lines of<br>image data is restarted.<br>1: The transfer address is initialized when the output of lines of<br>image data is restarted.|
|5<br>DOUTRCMD<br>0|Invalid<br>R/W<br>Output Image Data Lines Resume Command<br>This bit is valid only when the count mode for stopping the output of<br>image data lines is on.<br>Setting this bit to 1 resumes writing image data.<br>This bit is always read as 0.|
|4<br>DOUTLC<br>0|Invalid<br>R/W<br>Count Mode for Stopping Output Image Data Lines<br>0: Count mode for stopping the output of image data lines is off.<br>1: Count mode for stopping the output of image data lines is on.|
|3<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|2 to 0<br>DOUTSWAP<br>[2:0]<br>000|Invalid<br>R/W<br>Byte/Word Swap<br>Output image data in decompression is swapped.<br>000: (1) (2) (3) (4) (5) (6) (7) (8)<br>001: (2) (1) (4) (3) (6) (5) (8) (7)<br>[Byte swap]<br>010: (3) (4) (1) (2) (7) (8) (5) (6)<br>[Word swap]<br>011: (4) (3) (2) (1) (8) (7) (6) (5)<br>[Word - byte swap]<br>100: (5) (6) (7) (8) (1) (2) (3) (4)<br>[Longword swap]<br>101: (6) (5) (8) (7) (2) (1) (4) (3)<br>[Longword - byte swap]<br>110: (7) (8) (5) (6) (3) (4) (1) (2)<br>[Longword - word swap]<br>111: (8) (7) (6) (5) (4) (3) (2) (1)<br>[Longword - word - byte swap]|

## 44.2.25 JPEG Interface Decompression Source Address Register (JIFDSA)

JIFDSA sets the source address of the input coded data. This register should be set in 8-byte units.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||DSA[31:16]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W(compress):|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|
|R/W(decompress):|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||DSA[15:0]|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W(compress):|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|
|R/W(decompress):|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|31 to 3<br>2 to 0<br>DSA[31:3]<br>DSA[2:0]<br>H'0000<br>0000|Invalid<br>R/W<br>R<br>Input Coded Data Source Address (in 8-byte units)<br>The lower three bits should be set to 0.|

## 44.2.26 JPEG Interface Decompression Line Offset Register (JIFDDOFST)

JIFDDOFST sets the line offset of the output image data to be transferred to the external buffer (refer to section 44.3.4, Storing Image Data ). This register should be set in 8-byte units.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(compress):<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>DDMW[14:0]<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(compress):<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>DDMW[14:0]<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined|
|---|---|
|31 to 16<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|15 to 3<br>2 to 0<br>DDMW[14:3]<br>DDMW[2:0]<br>H'0000|Invalid<br>R/W<br>R<br>Output Image Data Lines Offset (in 8-byte units)<br>The lower three bits should be set to 0.|

## 44.2.27 JPEG Interface Decompression Destination Address Register (JIFDDA)

JIFDDA sets the destination address of the output image data. This register should be set in 8-byte units.

|JIFDDA sets the destination address of the output image data. This register should be set in 8-byte units.|JIFDDA sets the destination address of the output image data. This register should be set in 8-byte units.|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(decompress):<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(decompress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R<br>DDA[31:16]<br>DDA[15:0]<br>R/W(compress):<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>Undefined Undefined<br>Undefined<br>R/W(compress):<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>Undefined Undefined<br>Undefined||
|31 to 3<br>2 to 0<br>DDA[31:3]<br>DDA[2:0]<br>H'0000<br>0000|Invalid<br>R/W<br>R<br>Output Image Data Destination Address (in 8-byte units)<br>The lower three bits should be set to 0.|

## 44.2.28 JPEG Interface Decompression Source Data Count Register (JIFDSDC)

JIFDSDC sets the amount of input coded data when the count mode for stopping the input of coded data is on (the JINC bit in JIFDCNT is set to 1). This register should be set in 8-byte units.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|
|R/W(compress):||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|R/W(decompress):||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||JDATAS[15:0]|||||||||
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|
|R/W(compress):<br>Undefined|||Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|
|R/W(decompress):||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|31 to 16<br><br>H'FFF8|R<br>Reserved<br>Values read from these bits are undefined. The write value should<br>always be 0.|
|15 to 3<br>2 to 0<br>JDATAS[15:3]<br>JDATAS[2:0]<br>H'FFF8|Invalid<br>R/W<br>R<br>Amount of Input Coded Data to be Read (in 8-byte units)The lower<br>three bits should be set to 0.|

## 44.2.29 JPEG Interface Decompression Destination Line Count Register (JIFDDLC)

JIFDDLC sets the number of lines of output image data when the count mode for stopping the output of image data lines is on (the DOUTLC bit in JIFECNT is set to 1). This register is used to set the number of lines of output image data in MCU units.

|Bit:|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|
|R/W(compress):||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|R/W(decompress):||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||||LINES[15:0]|||||||||
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|
|R/W(compress):||Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|
|R/W(decompress):||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|

## **R/W**

||**R/W**|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**Description**<br>**Compression**<br>**De-**<br>**compression**|
|31 to 16<br><br>H'FFF8|R<br>Reserved<br>Values read from these bits are undefined. The write value should<br>always be 0.|
|15 to 3<br>2 to 0<br>LINES[15:3]<br>LINES[2:0]<br>H'FFF8|Invalid<br>R/W<br>R<br>Specify the number of lines of output image data to be written.<br>The setting is in MCU units.<br>When data are to be output in YCbCr444, YCbCr422 or YCbCr411<br>format, the number of lines of output image data is <this setting> x 1.<br>When data are to be output in YCbCr420 format, the number of lines<br>of output image data is <this setting> x 2.<br>The lower three bits should be set to 0.|

## 44.2.30 JPEG Interface Decompression α Set Register (JIFDADT)

JIFDADT is used to set the  value when output is in ARGB8888 format.

|JIFDADT is used to set thevalue when output is in ARGB8888 format.|JIFDADT is used to set thevalue when output is in ARGB8888 format.|
|---|---|
|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>ALPHA[7:0]<br>Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(compress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—||
|31 to 8<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|7 to 0<br>ALPHA[7:0]<br>H'00|Invalid<br>R/W<br>Setting of thevalue for output in ARGB8888 format.|

## 44.2.31 JPEG Interrupt Enable Register 1 (JINTE1)

JINTE1 enables interrupts.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(compress):<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>CBTEN<br>DIN<br>LEN<br>—<br>—<br>—<br>—<br>—<br>DBTEN JINEN<br>DOU<br>TLEN<br>—<br>—<br>—<br>JOU<br>TEN<br>—<br>Undefined Undefined Undefined<br>Undefined Undefined Undefined|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>Bit:<br>Initial value:<br>R/W(compress):<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>Bit:<br>Initial value:<br>R/W(compress):<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W(decompress):<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>CBTEN<br>DIN<br>LEN<br>—<br>—<br>—<br>—<br>—<br>DBTEN JINEN<br>DOU<br>TLEN<br>—<br>—<br>—<br>JOU<br>TEN<br>—<br>Undefined Undefined Undefined<br>Undefined Undefined Undefined|
|---|---|
|31 to 7<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|6<br>CBTEN<br>0|R/W<br>Invalid<br>Enables or disables a data transfer processing interrupt request<br>(JDTI) when the CBTF bit in JINTS1 is set to 1.<br>0: Disables an interrupt request.<br>1: Enables an interrupt request.|
|5<br>DINLEN<br>0|R/W<br>Invalid<br>Enables or disables a data transfer processing interrupt request<br>(JDTI) when the DINLF bit in JINTS1 is set to 1.<br>0: Disables an interrupt request.<br>1: Enables an interrupt request.|
|4<br>JOUTEN<br>0|R/W<br>Invalid<br>Enables or disables a data transfer processing interrupt request<br>(JDTI) when the JOUTF bit in JINTS1 is set to 1.<br>0: Disables an interrupt request.<br>1: Enables an interrupt request.|
|3<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|2<br>DBTEN<br>0|Invalid<br>R/W<br>Enables or disables a data transfer processing interrupt request<br>(JDTI) when the DBTF bit in JINTS1 is set to 1.<br>0: Disables an interrupt request.<br>1: Enables an interrupt request.|
|1<br>JINEN<br>0|Invalid<br>R/W<br>Enables or disables a data transfer processing interrupt request<br>(JDTI) when the JINF bit in JINTS1 is set to 1.<br>0: Disables an interrupt request.<br>1: Enables an interrupt request.|
|0<br>DOUTLEN<br>0|Invalid<br>R/W<br>Enables or disables a data transfer processing interrupt request<br>(JDTI) when the DOUTLF bit in JINTS1 is set to 1.<br>0: Disables an interrupt request.<br>1: Enables an interrupt request.|

## 44.2.32 JPEG Interrupt Status Register 1 (JINTS1)

## JINTS1 indicates the interrupt sources.

The interrupt sources of this register should be cleared by writing 0 to this register.

|Bit:|31||30|29|28|27||26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—||—|—|—|—||—|—|—|—|—|—|—|—|—|—|—|
|Initial value:|0||0|0|0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W(compress):|R||R|R|R|R||R|R|R|R|R|R|R|R|R|R|R|
|R/W(decompress):|R||R|R|R|R||R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15||14|13|12|11||10|9|8|7|6|5|4|3|2|1|0|
||—||—|—|—|—||—|—|—|—|CBTF|DINLF|JOUTF|—|DBTF|JINF|DOU<br>TLF|
|Initial value:|0||0|0|0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W(compress):|R||R|R|R|R||R|R|R|R|R/W*|R/W*|R/W*|R|Undefined|Undefined|Undefined|
|R/W(decompress):|R||R|R|R|R||R|R|R|R|Undefined|Undefined|Undefined|R|R/W*|R/W*|R/W*|
|Note:*||When the bit is read as 1, write||||||0 to clear it.|||||||||||
|||When the bit is read as 0, write||||||1 to it.|||||||||||

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**|**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**|
|---|---|
|31 to 7<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|6<br>CBTF<br>0|R/W*<br>Invalid<br>This bit is set to 1 when the last output coded data is written in<br>compression.|
|5<br>DINLF<br>0|R/W*<br>Invalid<br>This bit is set to 1 when the number of input image data lines<br>indicated by JIFESLC is read in compression.<br>This bit is valid only when the DINLC bit in JIFECNT is set to 1.|
|4<br>JOUTF<br>0|R/W*<br>Invalid<br>This bit is set to 1 when the amount of output coded data indicated by<br>JIFEDDC is written in compression.<br>This bit is valid only when the JOUTC bit in JIFECNT is set to 1.|
|3<br><br>0|R<br>Reserved<br>This bit is always read as 0. The write value should always be 0.|
|2<br>DBTF<br>0|Invalid<br>R/W*<br>This bit is set to 1 when the last output image data is written in<br>decompression.|
|1<br>JINF<br>0|Invalid<br>R/W*<br>This bit is set to 1 when the amount of input coded data indicated by<br>JIFDSDC is read in decompression.<br>This bit is valid only when the JINC bit in JIFDCNT is set to 1.|
|0<br>DOUTLF<br>0|Invalid<br>R/W*<br>In decompression, this bit is set to 1 when the number of lines of<br>output image data indicated by JIFDDLC have been written.<br>This bit is only valid when the DOUTLC bit in JIFDCNT is set to 1.|

Note:  When the bit is read as 1, write 0 to clear it. When the bit is read as 0, write 1 to it.

## 44.2.33 JPEG Input Image Data CbCr Range Setting Register (JIFESVSZ)

JIFESVSZ sets the CbCr range of input image data.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>—<br>DINY<br>CHG<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>—<br>DINY<br>CHG<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):|
|---|---|
|31 to 16<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|15<br>DINYCHG<br>0|R/W<br>Invalid<br>Input Image Data CbCr Range Setting<br>0: Range from -128 to 127<br>1: Range from 0 to 255|
|14 to 0<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|

## 44.2.34 JPEG Output Image Data CbCr Range Setting Register (JIFESHSZ)

JIFESHSZ sets the CbCr range of output image data.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>—<br>DOUTY<br>CHG<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>**Description**<br>**Compression**<br>**De-**<br>**compression**<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Undefined<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>—<br>DOUTY<br>CHG<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):<br>Bit:<br>Initial value:<br>R/W(compress):<br>R/W(decompress):|
|---|---|
|31 to 16<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|
|15<br>DOUTYCHG<br>0|Invalid<br>R/W<br>Output Image Data CbCr Range Setting<br>0: Range from -128 to 127<br>1: Range from 0 to 255|
|14 to 0<br><br>All 0|R<br>Reserved<br>These bits are always read as 0. The write value should always be 0.|

## 44.3 Operation

## 44.3.1 Compression

## (1) Overview of Processing

The compression process flows are described below.

1. The JPEG core is activated.

A marker is output. (After a marker is output, image data can be input.)

   - Approximately 30,000 cycles (necessary for making SOI to SOS markers)

2. Image data is transferred in MCUs from the external buffer to the JCU. If the count mode for stopping the input of image data lines is on, reading is stopped each time the number of lines set in JIFESLC is read. Reading is resumed by setting the DINRCMD bit in JIFECNT to 1.

   - When the DINRINI bit in JIFECNT is zero, the addresses for reading on resumption are continued from the addresses in the previous round of transfer.

When the DINRINI bit is one, the address set in JIFESA is used on resumption.

Reading is also stopped when one frame of image data is completely transferred.

   - If the count mode for stopping the input of image data lines is off, reading is continued until one frame of image data is completely transferred.

3. Image data is input to the JPEG core.

The input data is processed in MCUs at any time in the JPEG core.

4. Coded data is transferred from the JCU to the external buffer.

   - When the count mode for stopping the output of coded data is on, writing is stopped each time the amount of coded data set in JIFEDDC is written. Writing is resumed by setting the JOUTRCMD bit in JIFECNT to 1.

   - When the JOUTRINI bit in JIFECNT is zero, the addresses for writing on resumption are continued from the addresses in the previous round of transfer.

When the JOUTRINI bit is one, the address set in JIFEDA is used on resumption.

Writing is also stopped when one frame of coded data is completely transferred.

   - If the count mode for stopping the output of coded data is off, writing is continued until one frame of coded data is completely transferred.

5. Compression is completed after one frame of data is processed completely.

## (2) Flowchart (Compression)

## (a) Initial Settings

After completing the JPEG core settings and input/output buffer settings and transferring image data to the external buffer, activate this module by setting the JSRT bit in JCCMD to 1. After the JCU has been activated, the JPEG markers (SOI to SOS) are generated and output. It takes approximately 30,000 cycles to generate the markers.

**==> picture [467 x 246] intentionally omitted <==**

**----- Start of picture text -----**<br>
Software reset<br>Reset this module in advance by setting the SRST21 bit in SWRSTCR2<br>of the power-down modes.<br>Start initial setting<br>JPEG core settings<br>Software reset<br>Pixel format setting: REDU bits in JCMOD<br>Compression setting: DSP bit in JCMOD<br>Quantization table number setting: JCQTN<br>Set the JPEG core. Huffman table number setting: JCHTN<br>DRI setting: JCDRIU, JCDRID<br>Vertical image size setting: JCVSZU, JCVSZD<br>Set the I/O buffer. Horizontal image size setting: JCHSZU, JCHSZD<br>Quantization table setting: JCQTBL0 to JCQTBL3<br>Huffman table setting: JCHTBD0, JCHTBD1, JCHTBA0, JCHTBA1<br>Set the JSRT bit in JCCMD to 1.<br>I/O buffer settings<br>Byte/word/longword swap setting: JOUTSWAP, DINSWAP bits in JIFECNT<br>Initial setting completed Input data line stop count mode setting: DINLC bit in JIFECNT<br>Address initialization setting for resumption of input image data: DINRINI bit in JIFECNT<br>Output coded data stop count mode setting: JOUTC bit in JIFECNT<br>Address initialization setting for resumption of output coded data: JOUTRINI bit in JIFECNT<br>Source address setting: JIFESA<br>Line offset setting: JIFESOFST<br>Destination address setting: JIFEDA<br>Source line count setting: JIFESLC<br>Destination count setting: JIFEDDC<br>Interrupt settings: CBTEN, DINLEN, JOUTEN bits in JINTE1<br>**----- End of picture text -----**<br>

## **Figure 44.2 Compression Initial Setting Flow**

## (b) Compression Process

The compression process flows are described below.

- When JPEG compression process has been completed, the INS6 bit in JINTS0 is set to 1. However, the JCU continues processing since the coded data remains to be transferred. The CBTF bit in JINTS1 is set to 1 when the last coded data is transferred. The interrupt source is cleared by writing 0 to the INS6 bit. However, the interrupt request asserted by this interrupt source cannot be cleared by writing 0 to the INS6 bit. Set an interrupt request clear command (by setting the JEND bit in JCCMD to 1) to clear the interrupt request.

- When the JCU has completed compression and all coded data has been transferred, the CBTF flag in JINTS1 is set to 1. When the CBTEN bit in JINTE1 is 1 here, an interrupt is generated. The interrupt source is cleared by writing 0 to the CBTF flag.

- If the count mode for stopping image data lines is on, when the specified number of image data lines set in JIFESLC has been read, the DINLF flag in JINTS1 is set to 1, and reading is stopped. When the DINLEN bit in JINTE1 is 1 here, an interrupt is generated. An interrupt source is cleared by writing 0 to the DINLEN bit. Setting the DINRCMD bit in JIFECNT to 1 resumes reading.

   - When the DINRINI bit in JIFECNT is zero, the addresses for reading on resumption are continued from the addresses in the previous round of transfer.

When the DINRINI bit is one, the address set in JIFESA is used on resumption.

- If the count mode for stopping the output of coded data is on, when the specified amount of coded data set in JIFEDDC has been written, the JOUTF flag in JINTS1 is set to 1, and writing is stopped. When the JOUTEN bit in JINTE1 is 1 here, an interrupt is generated. An interrupt source is cleared by writing 0 to the JOUTF bit. Setting the JOUTRCMD bit in JIFECNT to 1 resumes writing.

When the JOUTRINI bit in JIFECNT is zero, the addresses for writing on resumption are continued from the addresses in the previous round of transfer.

When the JOUTRINI bit is one, the address set in JIFEDA is used on resumption.

**==> picture [376 x 291] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start compression<br>Set interrupt request   Set input image data<br>Is interrupt source   No Set the JEND bit  clear command. Set the DINRCMD bit  resume command.<br>generated? in JCCMD to 1. in JIFECNT to 1.<br>Yes<br>Clear the INS6 flag in JINTS0. Clear the DINLF flag in JINTS1.<br>Is the INS6 flag in<br>JINTS0 to 1? Yes<br>(JEDI)<br>No<br>Yes Is the CBTF flag in<br>JINTS1 to 1?<br>(JDTI)<br>No<br>Is the DINLF flag in   Yes<br>Clear all the flags in JINTS1. JINTS1 to 1?<br>(JDTI)<br>No  JOUTF = 1 (JDTI)<br>Clear the JOUTF flag in JINTS1.<br>Set output coded data<br>resume command.<br>Set the JOUTRCMD bit<br>Compression completed in JIFECNT to 1.<br>**----- End of picture text -----**<br>

## **Figure 44.3 Compression Process Flow**

## (3) JPEG Coded Data Format

Figure 44.4 shows the data output stream in compression. The amount of coded data from SOI to EOI is indicated by JCDTCU, JCDTCM, and JCDTCD. When both JCDRIU and JCDRID are set to H'0000 0000, the following markers are not output.

- DRI marker

- RST marker (in compressed image data)

|SOI|DQT|DRI|SOF0|DHT|SOS|Encoded<br>image|EOI|
|---|---|---|---|---|---|---|---|

## **Figure 44.4 JPEG Coded Data Format**

DQT: Not output for unused table.

DHT: Output in order DC0, AC0, DC1, and AC1. Not output for unused table.

- SOF0: Component identifiers are C1 = first color component, C2 = second color component, and C3 = third color component.

- SOS: Scan component selectors are CS1 = first color component, CS2 = second color component, and CS3 = third color component.

## **Header Volume (Reference):**

- SOI: 2 bytes (FFD8)

- DQT: 134 bytes when two quantization tables are used, 199 bytes when three quantization tables are used (  65 bytes/table increase or decrease)

- DRI: 6 bytes

- SOF0: 19 bytes (4:2:2)

- DHT: 420 bytes (two tables are used)

- SOS: 14 bytes (4:2:2)

- EOI: 2 bytes (FFD9)

## (4) Table Setting

## (a) Quantization Table Specification

The order of addresses shown in 8  8 blocks corresponds to that of the register addresses. Do not access this table while the JCU is in processing.

## **Table 44.2 Quantization Table**

|00|01|02|03|04|05|06|07|
|---|---|---|---|---|---|---|---|
|08|09|0A|0B|0C|0D|0E|0F|
|10|11|12|13|14|15|16|17|
|18|19|1A|1B|1C|1D|1E|1F|
|20|21|22|23|24|25|26|27|
|28|29|2A|2B|2C|2D|2E|2F|
|30|31|32|33|34|35|36|37|
|38|39|3A|3B|3C|3D|3E|3F|

JCQTBL0 (H'E801 7100) = H'00 JCQTBL0 (H'E801 7101) = H'01 JCQTBL0 (H'E801 7102) = H'02 JCQTBL0 (H'E801 7103) = H'03

:

JCQTBL0 (H'E801 713F) = H'3F

## (b) Huffman Table Specification

Examples of the Huffman table specification given in the ITU-T T81 Annex K.3.3 recommended by JPEG are shown below. In compression, the following settings must be specified for all the codes so that Huffman codes can be generated for all the group numbers.

- DC Huffman table: The number of codes for each code length is 12.

The group numbers in order of frequency of occurrence are 12.

- AC Huffman table: The number of codes for each code length is 162.

   - The zero run length/the group numbers in order of frequency of occurrence are 162.

Do not access the following tables while the JCU is in processing. In particular, read access is prohibited.

- able K.3/T81 JCHTBD0 (H'E801 7200) = H'00 JCHTBD0 (H'E801 7201) = H'01 JCHTBD0 (H'E801 7202) = H'05 JCHTBD0 (H'E801 7203) = H'01 : JCHTBD0 (H'E801 721B) = H'0B

- Table K.4/T81 JCHTBD1 (H'E801 7300) = H'00 JCHTBD1 (H'E801 7301) = H'03 JCHTBD1 (H'E801 7302) = H'01 JCHTBD1 (H'E801 7303) = H'01 : JCHTBD1 (H'E801 731B) = H'0B

- Table K.5/T81 JCHTBA0 (H'E801 7220) = H'00 JCHTBA0 (H'E801 7221) = H'02 JCHTBA0 (H'E801 7222) = H'01 JCHTBA0 (H'E801 7223) = H'03 : JCHTBA0 (H'E801 72D1) = H'FA

- Table K.6/T81 JCHTBA1 (H'E801 7320) = H'00 JCHTBA1 (H'E801 7321) = H'02 JCHTBA1 (H'E801 7322) = H'01 JCHTBA1 (H'E801 7323) = H'02 : JCHTBA1 (H'E801 73D1) = H'FA

## (5) Input Pixel Format

Image data in the YCbCr422 format can be input to this module. Allocation of data in the YCbCr422 format can be changed by the DINSWAP bits in JIFECNT as shown below.

 When the DINSWAP bits = 000

|<br>When the DINSWAP bits = 000|<br>When the DINSWAP bits = 000|<br>When the DINSWAP bits = 000|<br>When the DINSWAP bits = 000|<br>When the DINSWAP bits = 000|<br>When the DINSWAP bits = 000|<br>When the DINSWAP bits = 000|<br>When the DINSWAP bits = 000|
|---|---|---|---|---|---|---|---|
|b63           b56<br>b55           b48<br>b47           b40<br>b39           b32<br>b31           b24<br>b23           b16<br>b15              b8<br>b7                b0||||||||
|Y0 8 bits|Cb0 8 bits|Y1 8 bits|Cr0 8 bits|Y2 8 bits|Cb1 8 bits|Y3 8 bits|Cr1 8 bits|
|<br>When the DINSWAP bits = 001<br>b63           b56<br>b55           b48<br>b47           b40<br>b39           b32<br>b31           b24<br>b23           b16<br>b15              b8<br>b7                b0||||||||
|Cb0 8 bits|Y0 8 bits|Cr0 8 bits|Y1 8 bits|Cb1 8 bits|Y2 8 bits|Cr1 8 bits|Y3 8 bits|
|<br>When the DINSWAP bits = 010<br>b63           b56<br>b55           b48<br>b47           b40<br>b39           b32<br>b31           b24<br>b23           b16<br>b15              b8<br>b7                b0||||||||
|Y1 8 bits|Cr0 8 bits|Y0 8 bits|Cb0 8 bits|Y3 8 bits|Cr1 8 bits|Y2 8 bits|Cb1 8 bits|
|<br>When the DINSWAP bits = 100<br>b63           b56<br>b55           b48<br>b47           b40<br>b39           b32<br>b31           b24<br>b23           b16<br>b15              b8<br>b7                b0||||||||
|Y2 8 bits|Cb1 8 bits|Y3 8 bits|Cr1 8 bits|Y0 8 bits|Cb0 8 bits|Y1 8 bits|Cr0 8 bits|
|<br>When the DINSWAP bits = 101<br>b63           b56<br>b55           b48<br>b47           b40<br>b39           b32<br>b31           b24<br>b23           b16<br>b15              b8<br>b7                b0||||||||
|Cb1 8 bits|Y2 8 bits|Cr1 8 bits|Y3 8 bits|Cb0 8 bits|Y0 8 bits|Cr0 8 bits|Y1 8 bits|
|<br>When the DINSWAP bits = 110<br>b63           b56<br>b55           b48<br>b47           b40<br>b39           b32<br>b31           b24<br>b23           b16<br>b15              b8<br>b7                b0||||||||
|Y3 8 bits|Cr1 8 bits|Y2 8 bits|Cb1 8 bits|Y1 8 bits|Cr0 8 bits|Y0 8 bits|Cb0 8 bits|

##  When the DINSWAP bits = 111

|<br>When the DINSWAP bits = 111|<br>When the DINSWAP bits = 111|<br>When the DINSWAP bits = 111|<br>When the DINSWAP bits = 111|<br>When the DINSWAP bits = 111|<br>When the DINSWAP bits = 111|<br>When the DINSWAP bits = 111|<br>When the DINSWAP bits = 111|
|---|---|---|---|---|---|---|---|
|b63           b56<br>b55           b48<br>b47           b40<br>b39           b32<br>b31           b24<br>b23           b16<br>b15              b8<br>b7                b0||||||||
|Cr1 8 bits|Y3 8 bits|Cb1 8 bits|Y2 8 bits|Cr0 8 bits|Y1 8 bits|Cb0 8 bits|Y0 8 bits|

## (6) Output Coded Data

In the case of compression, coded data are output. This module handles the output of coded data in 16-bit units. For this reason, if the coded data have an odd code length (are fractional), the final code for output will be H'D9FF. The JOUTSWAP bits in JIFECNT can be used to alter the arrangement of coded data in the output.

## 44.3.2 Decompression

## (1) Overview of Processing

The decompression process flows are described below.

1. The JPEG core is activated.

2. Coded data is transferred from the external buffer to the JCU.

   - If the count mode for stopping the input of coded data is on, reading is stopped each time the amount of coded data set in JIFDSLC is read. Reading is resumed by setting the JINRCMD bit in JIFDCNT to 1. When the JINRINI bit in JIFDCNT is zero, the addresses for reading on resumption are continued from the addresses in the previous round of transfer.

When the JINRINI bit is one, the address set in JIFDSA is used on resumption. Reading is stopped when the end of the coded data is detected.

If the count mode for stopping the input of coded data is off, reading is continued until the end of code is detected. With this module, more coded data may be read than the coded data size since coded data reading is continued until the end of code is detected.

3. Coded data is input to the JPEG core.

The input data is processed in MCUs at any time in the JPEG core.

4. Image data is transferred in MCUs from the JCU to the external buffer.

   - When the count mode for stopping the output of image data lines is on, writing is stopped each time the number of image data lines set in JIFDDLC is written. Writing is resumed by setting the DOUTRCMD bit in JIFECNT to 1. When the DOUTRINI bit in JIFDCNT is zero, the addresses for writing on resumption are continued from the addresses in the previous round of transfer.

When the DOUTRINI bit is one, the address set in JIFDDA is used on resumption. Writing is stopped when one frame of image data is completely transferred.

   - If the count mode for stopping the output of image data lines is off, writing is continued until one frame of image data is completely transferred.

5. Decompression is completed after one frame of data is processed completely.

## (a) Initial Settings

- When the INT3 bit in JINTE0 is set to 0:

   - After completing the JPEG core settings and input/output buffer settings and transferring coded data to the external buffer, activate this module by setting the JSRT bit in JCCMD to 1.

- When the INT3 bit in JINTE0 is set to 1:

   - After completing the JPEG core settings and input buffer settings and transferring coded data to the external buffer, activate this module by setting the JSRT bit in JCCMD to 1.

When the image size and pixel format become readable after the coded data has been decompressed, the INS3 bit in JINTS0 is set. At this time, decompression is temporarily stopped.

After the image size and pixel format have been read, set the output buffer.

Setting the JRST bit in JCCMD to 1 after interrupt handling resumes decompression.

**==> picture [414 x 181] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start initial setting<br>Software reset<br>Reset this module in advance by setting the SRST21 bit in SWRSTCR2 of the power-down modes.<br>Software reset JPEG core settings<br>Decompression setting: DSP bit in JCMOD<br>Interrupt setting: INT7 to INT5 and INT3 flags in JINTE0<br>Set the JPEG core.<br>Input buffer settings<br>Byte/word/longword swap setting:  JINSWAP bit in JIFDCNT<br>Input coded data stop count setting: JINC bit in JIFDCNT<br>Set the input buffer. Address initialization setting for resumption of input coded data: JINRINI bit in JIFDCNT<br>Source address setting: JIFDSA<br>Source count setting:  JIFDSDC<br>Interrupt setting: JINEN bit in JINTE1<br>No Is the INT3 flag<br>in JINTE0 1? Output buffer settings<br>Yes Byte/word/longword swap setting DOUTSWAP bit in JIFDCNT<br>Set output buffer. Vertical/horizontal subsampling setting: VINTER and HINTER bits in JIFDCNT<br>Image information acquisition Output image pixel format setting: Output data line stop count setting: OPF bits in JIFDCNTDOUTLC bit in JIFDCNT<br>Set the JSRT bit in JCCMD to 1. Address initialization setting for resumption of output image data:  DOUTRINI bit in JIFDCNT<br>Line offset setting:  JIFDDOFST<br>Destination address setting:  JIFDDA<br>Destination line count setting: JIFDDLC<br>Interrupt setting:  DBTEN, DOUTLEN bits in JINTE1<br>Initial setting completed<br>**----- End of picture text -----**<br>

**Figure 44.5 Decompression Initial Setting Flow**

**==> picture [406 x 260] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start of image<br>information acquisition<br>Set the JSRT bit in JCCMD to 1.<br>Is an interrupt source   No<br>generated? Set input coded data resume command.<br>Set the JINRCMD bit in JIFDCNT to 1.<br>Yes<br>Yes Is the INS5 flag in<br>JINTS0 1?<br>(JEDI) Clear the JINF flag in JINTS1.<br>No<br>Is the JINF flag in   Yes   JINF = 1<br>Error handling JINTS1 1?<br>(JDTI)<br>No  INS3 = 1 (JEDI)<br>Clear the INS3 flag in JINTS0. Output buffer settings<br>Byte/word/longword swap setting: DOUTSWAP bit in JIFDCNT<br>Vertical/horizontal subsampling setting: VINTER and HINTER bits in JIFDCNT<br>Output image pixel format setting:  OPF bits in JIFDCNT<br>Set interrupt request clear command. Output data line stop count setting: DOUTLC bit in JIFDCNT<br>Set the JEND bit in JCCMD to 1. Address initialization setting for resumption of output image data:   DOUTRINI bit in JIFDCNT<br>Line offset setting:  JIFDDOST<br>Destination address setting:  JIFDDA<br>Set output buffer. Destination line count setting:Interrupt settings: JIFDDLCDBTEN, DOUTLEN bits in JINTE1<br>Set the JRST bit in JCCMD to 1.<br>End of image<br>information acquisition<br>**----- End of picture text -----**<br>

**Figure 44.6 Image Information Acquisition Flow**

## (b) Decompression Process

The decompression process flows are described below.

- When JPEG decompression process has been completed, the INS6 bit in JINTS0 is set to 1. However, the JCU continues processing since the image data remains to be transferred. The DBTF bit in JINTS1 is set to 1 when the last image data is transferred. The interrupt source is cleared by writing 0 to the INS6 bit. However, the interrupt request asserted by this interrupt source cannot be cleared by writing 0 to the INS6 bit. Set an interrupt request clear command (by setting the JEND bit in JCCMD to 1) to clear the interrupt request.

- When the JCU has completed decompression process and all image data has been transferred, the DBTF flag in JINTS1 is set to 1. When the DBTEN bit in JINTE1 is 1 here, an interrupt is generated. The interrupt source is cleared by writing 0 to the DBTF flag.

- If the count mode for stopping input coded data is on, when the specified amount of coded data set in JIFDSDC have been read, the JINF flag in JINTS1 is set to 1, and reading is stopped. When the JINEN bit in JINTE1 is 1 here, an interrupt is generated. An interrupt source is cleared by writing 0 to the JINF bit. Setting the JINRCMD bit in JIFDCNT to 1 resumes reading.

   - When the JINRINI bit in JIFDCNT is zero, the addresses for reading on resumption are continued from the addresses in the previous round of transfer.

When the JINRINI bit is one, the address set in JIFDSA is used on resumption.

- If the count mode for stopping the output image data is on, when the specified number of image data lines set in JIFDDLC have been written, the DOUTLF flag in JINT1 is set to 1, and writing is stopped. When the DOUTLEN bit in JINTE1 is 1 here, an interrupt is generated. An interrupt source is cleared by writing 0 to the DOUTLF bit. Setting the DOUTRCMD bit in JIFDCNT to 1 resumes writing.

   - When the DOUTRINI bit in JIFDCNT is zero, the addresses for writing on resumption are continued from the addresses in the previous round of transfer.

When the DOUTRINI bit is one, the address set in JIFDDA is used on resumption.

**==> picture [376 x 340] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start decompression<br>Is interrupt source   No command. Set the JEND bit  Set interrupt request clear    command. Set the JINRCMD  Set input coded data resume<br>generated? in JCCMD to 1. bit in JIFDCNT to 1.<br>Yes<br>Clear the INS6 flag in JINTS0. Clear the JINF flag in JINTS1.<br>Yes Is the INS5 flag<br>in JINTS0 to 1?<br>(JEDI)<br>No<br>Is the INS6 flag   Yes<br>in JINTS0 to 1?<br>Error handling (JEDI)<br>No<br>Yes Is the DBTF flag<br>in JINTS1 to 1?<br>(JDTI)<br>No<br>Is the JINF flag   Yes<br>in JINTS1 to 1?<br>Clear all the flags in JINTS1. (JDTI)<br>No  DOUTLF = 1 (JDTI)<br>Clear the DOUTLF flag in JINTS1.<br>Set output image data resume<br>command. Set the DOUTRCMD<br>bit in JIFDCNT to 1.<br>Decompression completed<br>**----- End of picture text -----**<br>

**Figure 44.7 Decompression Process Flow**

## (c) Error Handling

If the INS5 bit in JINTS0 is 1, it indicates that there is an error in the input JPEG coded data and that the decompression process by this module has been ended. Read the ERR bits in JCDERR to determine the cause of the error. The interrupt signal asserted due to the interrupt source indicated by the INS5 bit cannot be negated by clearing the interrupt status through 0-writing. To clear the interrupt request, set the interrupt request clear command (by setting the JEND bit in JCCMD to 1).

If decompression or compression is to proceed after error handling is completed, start by making the initial settings.

**==> picture [251 x 180] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start error handling<br>Clear all the flags in JINTS0.<br>Set interrupt request clear command.<br>Set the JEND bit in JCCMD to 1.<br>Read error code value.<br>Error handling<br>Error handling<br>Handle the error appropriately<br>according to the error coded value.<br>Error handling completed<br>**----- End of picture text -----**<br>

## **Figure 44.8 Error Handling Flow**

## (2) Input JPEG Coded Data

Markers to be processed in decompression are SOI, SOF0, SOS, DQT, DHT, DRI, RSTm, and EOI. Other markers except for the error markers shown below are ignored even if they are read.

The JINSWAP bits in JIFDCNT can be used to alter the arrangement for the input of coded data.

## (3) JPEG Decompression Errors

## (a) Error Marker

If a marker error is found while analyzing compressed data for decompression, the code to identify the error type (shown in Table 44.3 ) is set to ERR bits in JCDERR. When an error is detected, the JCU generates an interrupt signal and terminates decoding. The stored code value will be set to B'1010 (default value) at the start of processing of the next frame or after a bus reset.

## **Table 44.3 Decompression Error Codes**

|**Table 44.3**|**Decompression Error Codes**|
|---|---|
|**Code**|**Description**|
|B'0000|Normal|
|B'0001|SOI not detected: SOI not detected until EOI detected|
|B'0010|SOF1 to SOFF detected|
|B'0011|Unprovided pixel format detected|
|B'0100|SOF accuracy error: Other than 8 detected|
|B'0101|DQT accuracy error: Other than 0 detected|
|B'0110|Component error 1: The number of SOF0 header components detected is other than 1, 3, or 4|
|B'0111|Component error 2: The number of components differs between SOF0 header and SOS|
|B'1000|SOF0, DQT, and DHT not detected when SOS detected|
|B'1001|SOS not detected: SOS not detected until EOI detected|
|B'1010|EOI not detected (default)|
|B'1011|Restart interval data number error detected|
|B'1100|Image size error detected|
|B'1101|Last MCU data number error detected|
|B'1110|Block data number error detected|

## (b) Huffman Coded Segment Error

During the compressed data analysis in decompression operation, if there is an increase or decrease in the decoded data count due to an error resulting from bit reversal or missing data in the Huffman-coded segment, determine the error type, and set the error code in the ERR bit in JCDERR. Table 44.4 lists the segment error codes. The error code is set, interrupt signal is issued, and the process is ended only if the bits INT7 to INT5 in JINTE0 corresponding to the detected error is set to 1. The set code value will turn to the default value (B'1010) at the start of processing of the next frame or after a bus reset.

However, in this error detection, if an error in the Huffman-coded segment does not result in an alteration in the decoded data count, the error will go undetected.

[Example]

The number of data in a Huffman coded segment with pixel format setting YCbCr422, DRI = 2, X = 80 pixels, and Y = 8 pixels

|Restart interval 1|Restart interval 2<br>Restart interval 3|||
|---|---|---|---|
|SOS<br>Coded segment|RST<br>Coded segment<br>RST<br>Coded segment|EOI||
|Number of data in the last MCU:<br>Pixel format setting is YCbCr422, the number of data to be||decoded in||
||each MCU is 256.|||
|Number of data in the restart interval:<br>In restart intervals 1 and 2, there are data of two MCUs; the number of||||
||data to be decoded is 512.|||
|Image size:|The total number of data to be decoded is 1280.|||

**Figure 44.9 Huffman Coded Segment**

## **Table 44.4 Segment Error Codes**

|**Code**|**Description**|
|---|---|
|B'0000|Normal|
|B'1011|Restart interval data number error:|
||The number of data in each interval is compared with the number of data specified by the DRI marker. If an interval has|
||more or less data that is specified by the DRI marker, the decompression error code (1011) is set. The last interval which|
||is shorter than the restart interval is not compared.|
||If the DRI marker segment is not placed or the specified number is 00, an error is not detected even if the RSTm marker|
||is placed. Also an m which indicates the order of RSTm marker modulo 8 (m = 0 to 7) is exempt from the error detection|
||analysis.|
||When the INT7 bit in JINTE0 is set to 0, this error is not detected.|
|B'1100|Image size error:|
||The data number of an image which is calculated from the number of lines specified by the frame parameter and the|
||number of samples per line is compared with the total number of data from SOS to EOI (in pixel units). If the numbers of|
||data do not match, the decompression error code (1100) is set. When the INT6 bit in JINTE0 is set to 0, this error is not|
||detected. The data number of an image is shown in MCU units. Thus the number of lines and the number of samples per|
||line for calculation need to be shown in MCU units.|
|B'1101|Last MCU data number error:|
||Whether the number of data in the MCUs at the EOI detection is shown in MCU units is checked and fractions are|
||detected. If error (1100) occurs simultaneously, error (1100) has priority. When the INT5 bit in JINTE0 is set to 0, this|
||error is not detected.|
|B'1110|Block data number error:|
||Whether a block is an 88 array is checked; the check is performed for fractions. When bits INT7 to INT5 in JINTE0 are|
||all set to 0, this error is not detected.|

## 44.3.3 Output Pixel Format in Decompression

This module is capable of decompressing JPEG encoded data created in the YCbCr444, YCbCr422, YCbCr411 and YCbCr420 formats. The pixel format of the output image will be YCbCr422, ARGB8888, or RGB565. The flow of conversion of decompressed data to the given output pixel format is shown below.

**==> picture [428 x 131] intentionally omitted <==**

**----- Start of picture text -----**<br>
This module Internal bus<br>YCbCr422<br>On-chip RAM<br>Y0 to Y3 Color matrix Vertical/horizontal   Swap<br>subsampling<br>JPEG core Cb YCbCr  conversion YCbCrconversion→RGB   RGB Bit reduction RGB<br>888 565<br>Cr OPF bits<br>YCbCr444<br>**----- End of picture text -----**<br>

## **Figure 44.10 Block Diagram of Output Pixel Format Conversion in Decompression**

## (1) On-chip RAM

Data decoded by the JPEG core are stored in MCUs on RAM in this module.

## (2) YCbCr Conversion

When data are to be output in the ARGB8888 or RGB565 format, data in the YCbCr422, YCbCr411 or YCbCr420 format are first converted to the YCbCr444 format.

When data are to be output in the YCbCr422 format, data in the YCbCr444, YCbCr411 or YCbCr420 format are converted to the YCbCr422 format.

Conversion is performed using simple interpolation.

## (3) YCbCr  RGB Conversion

Data in the YCbCr444 format are converted to the RGB888 format. The following formulae are used.

R = 1.000Y + 1.402Cr

G = 1.000Y - 0.344Cb - 0.714Cr

B = 1.000Y + 1.772Cb

## (4) Bit Reduction

RGB888 data is reduced to RGB565 data. The lower three bits of red and blue, and lower two bits of green are removed.

## (5) Output Pixel Format Selection

The pixel format to be output is selected by the OPF bit in JIFDCNT.

Allocation of data (while the DOUTSWAP bits in JIFDCNT = 000) in the pixel format is shown below.

 YCbCr422 (32 bits/pixel)

|The pixel format to be output is selected by the OPF bit in JIFDCNT.<br>Allocation of data (while the DOUTSWAP bits in JIFDCNT = 000) in the pixel format is shown below.<br><br>YCbCr422 (32 bits/pixel)|The pixel format to be output is selected by the OPF bit in JIFDCNT.<br>Allocation of data (while the DOUTSWAP bits in JIFDCNT = 000) in the pixel format is shown below.<br><br>YCbCr422 (32 bits/pixel)|The pixel format to be output is selected by the OPF bit in JIFDCNT.<br>Allocation of data (while the DOUTSWAP bits in JIFDCNT = 000) in the pixel format is shown below.<br><br>YCbCr422 (32 bits/pixel)|The pixel format to be output is selected by the OPF bit in JIFDCNT.<br>Allocation of data (while the DOUTSWAP bits in JIFDCNT = 000) in the pixel format is shown below.<br><br>YCbCr422 (32 bits/pixel)|The pixel format to be output is selected by the OPF bit in JIFDCNT.<br>Allocation of data (while the DOUTSWAP bits in JIFDCNT = 000) in the pixel format is shown below.<br><br>YCbCr422 (32 bits/pixel)|The pixel format to be output is selected by the OPF bit in JIFDCNT.<br>Allocation of data (while the DOUTSWAP bits in JIFDCNT = 000) in the pixel format is shown below.<br><br>YCbCr422 (32 bits/pixel)|
|---|---|---|---|---|---|
|b31<br>b24<br>b23<br>b16<br>b15<br>b8<br>b7<br>b0||||||
|Y0 8 bits|Cb 8 bits||Y1 8 bits||Cr 8 bits|
|<br>ARGB8888 (32 bits/pixel)<br>b31<br>b24<br>b23<br>b16<br>b15<br>b8<br>b7<br>b0||||||
|*|Red 8 bits||Green 8 bits||Blue 8 bits|
|Note: * This value is determined by the ALPHA[7:0] bits in JIFDADT.<br><br>RGB565 (16 bits/pixel)<br>b15<br>b11<br>b10<br>b5<br>b4<br>b0||||||
|Red 5 bits||Green 6 bits||Blue 5 bits||

## (6) Vertical/Horizontal Subsampling

The output data can be horizontally and vertically subsampled according to the VINTER and HINTER bit setting in JIFDCNT.

Figure 44.11 to Figure 44.13 show line subsampling modes.

For the output formats ARGB8888 and RGB565, one cell represents one pixel in the figures.

For the output format YCbCr422, one cell represents one set of Y0Cb0Y1Cr0 in the figures.

As subsampling is carried out by minimum coded units (MCU), the numbers of the horizontal and vertical block units will vary according to the decompressed pixel format.

Table 44.5 and Table 44.6 show the values of n and m in the figures.

Horizontal:

## **Table 44.5 Number of Horizontal Blocks**

|**Compression Format**|**Output Format**|**n**|
|---|---|---|
|YCbCr444|YCbCr422|1/2|
|YCbCr444|ARGB8888, RGB565|1|
|YCbCr422|YCbCr422|1|
|YCbCr422|ARGB8888, RGB565|2|
|YCbCr411|YCbCr422|2|
|YCbCr411|ARGB8888, RGB565|4|
|YCbCr420|YCbCr422|1|
|YCbCr420|ARGB8888, RGB565|2|

## Vertical:

## **Table 44.6 Number of Vertical Blocks**

|**Compression Format**|**Output Format**|**m**|
|---|---|---|
|YCbCr444|YCbCr422|1|
|YCbCr444|ARGB8888, RGB565|1|
|YCbCr422|YCbCr422|1|
|YCbCr422|ARGB8888, RGB565|1|
|YCbCr411|YCbCr422|1|
|YCbCr411|ARGB8888, RGB565|1|
|YCbCr420|YCbCr422|2|
|YCbCr420|ARGB8888, RGB565|2|

- Subsampling into 1/2

Even lines are skipped by subsampling.

**==> picture [304 x 178] intentionally omitted <==**

**----- Start of picture text -----**<br>
8 × n blocks<br>1 2 3 4 5 6 7 8 6 7 8<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>:<br>:<br>6<br>7<br>8 :Lines to be skipped by subsampling<br>: :<br> m blocks<br>×<br>8<br>**----- End of picture text -----**<br>

**Figure 44.11 MCU when subsampling into 1/2 is selected**

- Subsampling into 1/4

   - The second, third, and fourth lines are skipped by subsampling.

**==> picture [305 x 178] intentionally omitted <==**

**----- Start of picture text -----**<br>
8 × n blocks<br>1 2 3 4 5 6 7 8 6 7 8<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>6<br>7<br>8 : Lines to be skipped by subsampling<br>: :<br> m blocks<br>×<br>8<br>:<br>:<br>**----- End of picture text -----**<br>

**Figure 44.12 MCU when subsampling into 1/4 is selected**

- Subsampling into 1/8

   - The second, third, fourth, fifth, sixth, seventh, and eighth lines are skipped by subsampling.

**==> picture [305 x 179] intentionally omitted <==**

**----- Start of picture text -----**<br>
8 × n blocks<br>1 2 3 4 5 6 7 8 6 7 8<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>6<br>7<br>8 : Lines to be skipped by subsampling<br>: :<br>m blocks<br>×<br>8  :<br>:<br>**----- End of picture text -----**<br>

**Figure 44.13 MCU when subsampling into 1/8 is selected**

## (7) Swap

Allocation of data can be changed by the DOUTSWAP bits in JIFECNT.

## 44.3.4 Storing Image Data

Figure 44.14 shows the buffer area for storing the image data.

- Start address

   - Compression: JIFESA Decompression: JIFDDA

- Horizontal size Compression, decompression: JCHSZU, JCHSZD

- Vertical size

   - Compression, decompression: JCVSAU, JCVSZD

- Offset

   - Compression: JIFESOFST

   - Decompression: JIFDDOFST

**==> picture [269 x 200] intentionally omitted <==**

**----- Start of picture text -----**<br>
JIFESOFST/JIFDDOFST<br>JIFESA/JIFDDA JCHSZU, JCHSZD<br>Area for storing image data JCVSZU<br>JCVSZD<br>**----- End of picture text -----**<br>

**Figure 44.14 Image of Storing Image Data**

## 44.4 Interrupts

Two types of interrupt requests, namely compression/decompression process interrupt request (JEDI) and data transfer interrupt request (JDTI), are available in this module. The two types of interrupt requests are each related to multiple sources. The interrupt request cancellation methods differ depending on the source of the interrupt request.

## 44.4.1 Compression/Decompression Process Interrupt Request (JEDI)

The flags in JINTS0 indicate compression/decompression-related sources. The interrupt requests asserted by these interrupt sources cannot be negated by clearing the corresponding interrupt status bits to 0. Issue an interrupt request clear command (by setting the JEND bit in JCCMD to 1) to clear the interrupt request. When a flag in JINTS0 is set to 1, a compression/decompression process interrupt request is sent to the interrupt controller.

## (1) Compression

- JPEG compression process end

   - When the INS6 bit in JINTS0 is 1, the JPEG compression process has been successfully completed. After all of the coded data is transferred, the JCU completes compression.

## (2) Decompression

- JPEG decompression process end

   - When the INS6 bit in JINTS0 is 1, the JPEG decompression process has been successfully completed. After all of the image data is transferred, JCU completes decompression.

- JPEG decompression error occurrence When the INS5 bit in JINTS0 is 1, the input JPEG coded data has an error and the JCU has stopped the decompression process. Read the error code (ERR bits in JCDERR) and identify the error source. This interrupt occurs when any of the INT7 to INT5 bits in JINTE0 is 1.

- Request for reading the image size and pixel format When the INS3 bit in JINTS0 is 1, JPEG coded data has been input and information regarding the image size and pixel format can be read. Since the JPEG decompression process is suspended, resume the JPEG decompression process by setting the process stop clear command after accessing the necessary registers. This interrupt occurs when the INT3 bit in JINTE0 is 1.

## 44.4.2 Data Transfer Interrupt Request (JDTI)

The flags in JINTS1 are the interrupt sources for transferring the image data and coded data. The interrupt requests asserted by these interrupt sources can be negated by clearing the corresponding interrupt status bits to 0.

## (1) Compression

- Interrupt request generated after the specified number of input image data lines has been read When the DINLF bit in JINTS1 is 1, the number of image data lines specified by JIFESLC has been transferred; transfer the rest of the image data to the external buffer and resume transferring the data from the external buffer. A data transfer interrupt request is sent when the DINLEN bit in JINTE1 is 1.

- Interrupt request generated after the specified amount of output coded data have been written to When the JOUTF bit in JINTS1 is 1, the amount of coded data specified by JIFEDDC has been transferred. Secure a space for the next coded data in the external buffer, and resume transfer process. The data transfer interrupt request is sent when the JOUTEN bit in JINTE1 is 1.

- Interrupt request generated after all processes are completed When the CBTF bit in JINTS1 is 1, the JCU has completed compression and transferred all of the coded data. The data transfer interrupt request is sent when the CBTEN bit in JINTE1 is set to 1.

## (2) Decompression

- Interrupt request generated after the specified number of output image data lines has been written to When the DOUTLF bit in the JINTS1 is 1, the number of image data lines specified by JIFDDLC has been transferred. Secure a space for the next coded data in the external buffer, and resume transfer process.  A data transfer interrupt request is sent when the DOUTLEN bit in JINTE1 is 1.

- Interrupt request generated after the specified amount of input coded data has been read The JINF bit in JINTS1 becomes 1 when the amount of coded data specified by JIFDSDC has been transferred. Secure the next coded data in the external buffer, and resume transfer process. A data transfer interrupt is also sent at this time if the JINEN bit in JINTE1 is 1.

- Interrupt request generated after all processes are completed The DBTF bit in JINTS1 becomes 1 when the JCU has completed decompression and transferred all of the coded data. A data transfer interrupt request is also sent at this time if the DBTEN bit in JINTE1 is set to 1.

## 44.5 Bus Reset Processing

Issuing the bus reset command (setting the BRST bit in JCCMD to 1) causes a bus reset.

When the JCU is in operation, the bus reset command should not be issued. Registers below are initialized by a bus reset.

- JPEG code data count upper register (JCDTCU)

- JPEG code data count middle register (JCDTCM)

- JPEG code data count lower register (JCDTCD)

- JPEG interrupt status register 0 (JINTS0)

- JPEG code decode error register (JCDERR)

- JPEG code reset register (JCRST)
