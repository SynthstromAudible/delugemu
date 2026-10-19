# 40. On-Chip RAM

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2187–2189. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI has an on-chip large-capacity RAM for display area and work area (128 Kbytes of this RAM are shared with the on-chip data retention RAM) and an on-chip data retention RAM, which can retain data in deep standby mode. These memory units can be used to store instructions or data.

The operation and write access to the large-capacity RAM (including on-chip data retention RAM) can be enabled or disabled through the RAM enable bits and RAM write enable bits.

The on-chip data retention RAM is assigned to page 0 in the on-chip large-capacity RAM. Retention or non-retention of data by the on-chip data retention RAM in deep standby mode is selectable on a per-page basis.

## 40.1 Features

- Page

   - The on-chip large-capacity RAM consists of five pages (four pages in the RZ/A1LC).

   - The on-chip data retention RAM consists of four pages. Page 0 has 16-Kbytes, page 1 has 16-Kbytes, page 2 has 32-Kbytes, and page 3 has 64-Kbytes.

- Memory map

The on-chip RAM is located in the address spaces shown in Table 40.1 and Table 40.2. Pages 0 to 3 of the largecapacity RAM each have a capacity of 512 Kbytes, and page 4 of the large-capacity RAM has a capacity of 1 Mbyte.

## **Table 40.1 Address Spaces of On-Chip Large-Capacity RAM**

|**Page**|||**Address**||**Mirror Address**|
|---|---|---|---|---|---|
|Page|0|(512KB)|H'20000000|to H'2007FFFF|H'60000000 to H'6007FFFF|
|Page|1|(512KB)|H'20080000|to H'200FFFFF|H'60080000 to H'600FFFFF|
|Page|2|(512KB)|H'20100000|to H'2017FFFF|H'60100000 to H'6017FFFF|
|Page|3|(512KB)|H'20180000|to H'201FFFFF|H'60180000 to H'601FFFFF|
|Page|4|(1024KB)*|H'20200000|to H'202FFFFF|H'60200000 to H'602FFFFF|

Note: * Reserved in the RZ/A1LC.

## **Table 40.2 Address Spaces of On-Chip Data Retention RAM**

|**Page**|||**Address**||**Mirror Address**|
|---|---|---|---|---|---|
|Page|0|(16KB)|H'20000000|to H'20003FFF|H'60000000 to H'60003FFF|
|Page|1|(16KB)|H'20004000|to H'20007FFF|H'60004000 to H'60007FFF|
|Page|2|(32KB)|H'20008000|to H'2000FFFF|H'60008000 to H'6000FFFF|
|Page|3|(64KB)|H'20010000|to H'2001FFFF|H'60010000 to H'6001FFFF|

- Ports

   - Each page of the on-chip large-capacity RAM has one read and write port and is connected to the AXI bus. The onchip RAM for data retention, which has a port independent of the port in page 0, is shared with the read and write port in four pages.

- Method of arbitration

   - When the same port of the on-chip large-capacity RAM is accessed from different masters simultaneously, the AXI bus performs arbitration in round-robin mode.

- Number of access cycles

The number of cycles for access to read or write is one cycle of B  .

## 40.2 Usage Notes

## 40.2.1 Page Conflict

When the same page of the on-chip large-capacity RAM is accessed from different masters simultaneously, a conflict on the page occurs. Although each access is completed correctly, this kind of conflict degrades the memory access speed. Therefore, it is advisable to provide software measures to prevent such conflicts as far as possible. For example, no conflict will arise if different pages are accessed by each master.

## 40.2.2 Data Retention

Data in the large-capacity RAM (including on-chip data retention RAM) are retained in the states other than power-on reset and deep standby mode. In power-on reset and deep standby mode, these RAMs operate as described below.

## (1) Power-on Reset

## (a) On-Chip Large-Capacity RAM (Excluding On-Chip Data Retention RAM)

Data are retained on a power-on reset by disabling the setting of either the VRAME or VRAMWE bit. Data are not retained when the setting of the VRAME and VRAMWE bits are both enabled.

## (b) On-Chip Data Retention RAM

Data are retained on a power-on reset by disabling the setting of any of the VRAME, VRAMWE, or RRAMWE, excluding the case that deep standby mode is canceled by power-on reset.

Data are not retained when the setting of the VRAME, VRAMWE and RRAMWE bits are all enabled.

## (2) Deep Standby Mode

## (a) On-Chip Large-Capacity RAM (Excluding On-Chip Data Retention RAM)

Data are not retained.

## (b) On-Chip Data Retention RAM

Data are retained in deep standby mode by enabling the setting of the RRAMKP bit, excluding the case that deep standby mode is canceled by power-on reset. In the case that deep standby mode is canceled by interrupt or pins for cancelling, power-on reset exception handling is executed, but the data are retained.
