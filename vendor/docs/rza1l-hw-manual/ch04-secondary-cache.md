# 4. Secondary Cache

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 90–90. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This product incorporates Arm's PL310 as a secondary cache. The IP version is r3p2.

## 4.1 Features

- Total cache size:

   - 128 Kbytes

- Number of cache ways: 8 ways

- Number of master ports : 2

- Number of slave ports: 2

- Lockdown by master: No

- Lockdown by line Defined

- Speculative read: No

- Sideband signal from CA9: No

For details, see CoreLink™ Level 2 Cache Controller L2C-310 Technical Reference Manual issued by Arm Ltd.

## 4.2 Configuration Signals

The setting values of the configuration signals are shown in Table 4.1 .

## **Table 4.1 Setting Values of Configuration Signals**

|**Configuration Signals**|**Setting Values**|
|---|---|
|ASSOCIATIVITY*1|1'b0 (8 ways)|
|CACHEID[5:0]|6'b000000|
|CFGADDRFILTEN*1|1'b1|
|CFGADDRFILTEND[11:0]*1|12'h3FF|
|CFGADDRFILTSTART[11:0]*1|12'h180|
|CFGBIGEND|1'b0|
|DATAREADLAT[2:0]*1|3'b000|
|DATASETUPLAT[2:0]*1|3'b000|
|DATAWRITELAT[2:0]*1|3'b000|
|REGFILEBASE[19:0]*2|20'h3FFFF|
|TAGREADLAT[2:0]*1|3'b000|
|TAGSETUPLAT[2:0]*1|3'b000|
|TAGWRITELAT[2:0]*1|3'b000|
|WAYSIZE[2:0]*1|3'b001 (16 Kbytes)|

- Note 1. Do not change the initial settings of these signals by software.

Note 2. The base address for the PL310 registers is H'3FFFF000. For the details and overview of the registers, see CoreLink™ Level 2 Cache Controller L2C-310 Technical Reference Manual issued by Arm Ltd. The external ROM/RAM mirror area (0x4000_0000 to 0x5FFF_FFFF) is mirrored before the secondary cache. Accordingly, when a cache maintenance operation is to be executed for the external ROM/RAM mirror area, treat this as the normal external ROM/RAM area in the physical addresses range from 0x0000_0000 to 0x1FFF_FFFF.
