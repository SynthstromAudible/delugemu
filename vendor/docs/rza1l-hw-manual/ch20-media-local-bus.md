# 20. Media Local Bus

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 919–920. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This module is only incorporated in the RZ/A1L.

This product supports the media local bus as an interface to connect to the MOST controller.

## 20.1 Features

- 3-pin interface

- A maximum of 50 Mbps of data can be transferred.

For details on the functions and registers, contact Renesas Electronics Corporation's sales office.

Figure 20.1 shows the block diagram.

**==> picture [367 x 259] intentionally omitted <==**

**----- Start of picture text -----**<br>
MediaLB module (MLB)<br>MediaLB RAM<br>(1024 bytes)<br>MLB RAM interface<br>MediaLB device interface macro (DIM)<br>OS62400<br>AHB interface MediaLB   MediaLB   MediaLB<br>HBI channel  arbiter buffer logicchannel   link logic<br>APB interface MediaLB   MLB_CLK<br>PBI MediaLB configuration logic core<br>MLB_SIG<br>MLB_DAT<br>MLB_CINT<br>MediaLB clock, power, and reset (CPR) logic<br>MLB_SINT<br>**----- End of picture text -----**<br>

**Figure 20.1 Block Diagram**

## 20.2 Input/Output Pins

Table 20.1 shows the pin configuration.

## **Table 20.1 Pin Configuration**

|**Pin Name**|**I/O**|**Description**|
|---|---|---|
|MLB_CLK|I|MediaLB clock input|
|MLB_SIG|I/O|MediaLB signal information I/O|
|MLB_DAT|I/O|MediaLB data I/O|

## 20.3 Register Description

Table 20.2 shows the register configuration.

For details on the registers, contact Renesas Electronics Corporation's sales office.

## **Table 20.2 Register Configuration**

||**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial**<br>**Value**<br>**Address**<br>**Access**<br>**Size**|
|---|---|
|Configuration<br>control register|Device control configuration register<br>DCCR<br>*1<br>*1<br>H'E8034000<br>32|
||System status configuration register<br>SSCR<br>*1<br>*1<br>H'E8034004<br>32|
||System data configuration register<br>SDCR<br>*1<br>*1<br>H'E8034008<br>32|
||System mask configuration register<br>SMCR<br>*1<br>*1<br>H'E803400C<br>32|
||Version control configuration register<br>VCCR<br>*1<br>*1<br>H'E803401C<br>32|
||Synchronous base address configuration<br>register<br>SBCR<br>*1<br>*1<br>H'E8034020<br>32|
||Asynchronous base address configuration<br>register<br>ABCR<br>*1<br>*1<br>H'E8034024<br>32|
||Control base address configuration register<br>CBCR<br>*1<br>*1<br>H'E8034028<br>32|
||Isochronous base address configuration<br>register<br>IBCR<br>*1<br>*1<br>H'E803402C<br>32|
||Channel interrupt configuration register<br>CICR<br>*1<br>*1<br>H'E8034030<br>32|
|Channel m*2<br>configuration<br>register|Channel m entry configuration register<br>CECRm<br>*1<br>*1<br>H'E8034040 + m x 10<br>32|
||Channel m status configuration register<br>CSCRm<br>*1<br>*1<br>H'E8034044 + m x 10<br>32|
||Channel m current buffer configuration<br>register<br>CCBCRm<br>*1<br>*1<br>H'E8034048 + m x 10<br>32|
||Channel m next buffer configuration register<br>CNBCRm<br>*1<br>*1<br>H'E803404C + m x 10<br>32|
||Local channel m buffer configuration register<br>LCBCRm<br>*1<br>*1<br>H'E8034280 + m x 4<br>32|

Note 1. Contact Renesas Electronics Corporation's sales office. Note 2. Each channel of the media local bus is identified by “m” (m = 0 to 30).
