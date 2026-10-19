# 41. Ports

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2190–2218. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

## 41.1 Features

The 176-pin package of this LSI has nine ports: JP0, P0 to P7. The 208-pin and 233-pin packages of this LSI have eleven ports: JP0, P0 to P9.  Each port pin is multiplexed with other peripheral module pin functions, and by setting the control registers, multiplexed pin functions (alternative functions) can be selectable.

## 41.1.1 Port group

This LSI has the following number of port groups.

## **Table 41.1 Port Group**

|**Table 41.1**<br>**Port Group**|||
|---|---|---|
|**Package**|**Number**|**Name**|
|176-pin|9|P0 to P7, JP0|
|208-pin, 233-pin|11|P0 to P9, JP0|

## 41.1.2 Port group index n

Throughout this section, the individual port groups are identified by the index "n" (n = 0 to 9), for example PMCn for the port mode control register, which is used for the Pn pin. The JTAG port has only the index 0.

## 41.1.3 Base address

The address of a register used to control a JTAG port is given as the base address <JPORTn_base> and the offset address from the base address. The address of a register other than the ones used to control JTAG ports is given as the base address <PORTn_base> and the offset address from the base address.

## **Table 41.2 Base Addresses <PORTn_base> and <JPORTn_base>**

|**<PORTn_base> address**|**<JPORTn_base> address**|
|---|---|
|H’FCFE 3000|H’FCFE 7B00|

## 41.2 Functional Overview

## 41.2.1 Mode of Pin Functions

Pins can operate in three modes.

- Port mode (PMCn.PMCnm bit = 0)

   - A pin in port mode operates as a general purpose input/output port.

   - The I/O mode is selected by setting the PMn.PMnm bit.

- Software I/O control alternative mode (PMCn.PMCnm bit = 1, PIPCn.PIPCnm bit = 0) In this mode, the pins operate as alternative functions.

The I/O mode is selected by setting the PMn.PMnm bit by using software.

- Direct I/O control alternative mode (PMCn.PMCnm bit = 1, PIPCn.PIPCnm bit = 1) In this mode, the pins operate as alternative functions.

   - Unlike the software I/O alternative mode, however, the I/O mode is selected by the alternative function.

An overview of the register settings is given in the tables below.

## **Table 41.3 Pin Function Configuration Overview**

|**Mode**||**Register**|**Register**||**I/O**|
|---|---|---|---|---|---|
||**PMCn.PMCnm**|**PMn.PMnm**|**PIBCn.PIBCnm**|**PIPCn.PIPCnm**||
|Port mode|0|0|X|X|O|
|||1|0||—|
||||1||I|
|Software I/O control<br>alternative mode*|1|0|X|0|O|
|||1|||I|
|Direct I/O control<br>alternative mode*||X||1|Controlled by the alternative function|

Caution: When the pins are in alternative mode (PMCn.PMCnm = 1), one of the eight alternative functions is selected by the

PFCn, PFCEn, and PFCAEn registers. For details, see Table 41.6, Alternative Mode Selection.

## 41.2.2 Pin Data Input/Output

The registers used for data input/output are described below. The location that is read via the PPRn register differs depending on the pin mode.

- Output data

In port mode (PMCn.PMCnm = 0), the value of the Pn.Pnm bit is output from the Pn_m pin.

- Input data

When the PPRn register is read, either the level of the Pn_m pin, the value of the Pn.Pnm bit, or the value output by the alternative function is returned. Which value is returned depends on the pin mode and setting of several control bits. Table 41.4 shows the different PPRn read values.

## **Table 41.4 PPRn.PPRnm Bit Read Values**

|**Mode**||**Register**|**Register**||**PPRn.PPRnm Bit Read Value**|
|---|---|---|---|---|---|
||**PMCn.PMCnm**|**PMn.PMnm**|**PIBCn.PIBCnm**|**PIPCn.PIPCnm**||
|Port mode|0|0|X|X|Pn.Pnm bit*|
||||0||Pn.Pnm bit|
|||1|1||Pn_m pin|
|Software I/O control<br>alternative mode|1|0|X|0|Value output by the alternative<br>function*|
|||1|||Pn_m pin|
|Direct I/O control<br>alternative mode||X||1|Input: Pn_m pin<br>Output: Value output by the<br>alternative function*|

Caution: When PBDCn.PBDCnm = 1, the level of the Pn_m pin is returned as the read value of the PPRn.PPRnm bit.

## 41.3 Register Description

The following registers are used for setting the individual pins of the port groups:

**Table 41.5 Register Configuration**

|**Table 41.5**|**Register Configuration**|||||
|---|---|---|---|---|---|
||||**16 Bit**|**32 Bit**||
|**Symbol**|**Register Name**|**R/W**|**Access**|**Access**|**Address**|
|Pn|Port register|R/W|√|─|<PORTn_base> + 0000H + n × 4|
|PSRn|Port set/reset register|R/W|─|√|<PORTn_base> + 0100H + n × 4|
|PPRn|Port pin read register|R|√|─|<PORTn_base> + 0200H + n × 4|
|PMn|Port mode register|R/W|√|─|<PORTn_base> + 0300H + n × 4|
|PMCn|Port mode control register|R/W|√|─|<PORTn_base> + 0400H + n × 4|
|PFCn|Port function control register|R/W|√|─|<PORTn_base> + 0500H + n × 4|
|PFCEn|Port function control expansion register|R/W|√|─|<PORTn_base> + 0600H + n × 4|
|PNOTn|Port NOT register|W|√|─|<PORTn_base> + 0700H + n × 4|
|PMSRn|Port mode set/reset register|R/W|─|√|<PORTn_base> + 0800H + n × 4|
|PMCSRn|Port mode control set/reset register|R/W|─|√|<PORTn_base> + 0900H + n × 4|
|PFCAEn|Port Function Control Additional|R/W|√|─|<PORTn_base> + 0A00H + n × 4|
||Expansion register|||||
|PIBCn|Port input buffer control register|R/W|√|─|<PORTn_base> + 4000H + n × 4|
|PBDCn|Port bi-direction control register|R/W|√|─|<PORTn_base> + 4100H + n × 4|
|PIPCn|Port IP control register|R/W|√|─|<PORTn_base> + 4200H + n × 4|
|JPPR0|Port pin read register|R|√|─|<JPORTn_base> + 0020H|
|JPMC0|Port mode control register|R/W|√|─|<JPORTn_base> + 0040H|
|JPMCSR0|Port mode control set/reset register|R/W|─|√|<JPORTn_base> + 0090H|
|JPIBC0|Port input buffer control register|R/W|√|─|<JPORTn_base> + 0400H|
|SNCRn|Serial sound interface noise canceler|R/W|─|√|<PORTn_base> + 0C00H|
||control register|||||

## 41.3.1 Port Register (Pn)

In port output mode (PMCn.PMCnm = 0 and PMn.PMnm = 0), this register sets the level of the Pn_m pin.

||Bit:|15|14||13|12|11<br>10<br>9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||Pn15|Pn14||Pn13|Pn12|Pn11<br>Pn10<br>Pn9|Pn8|Pn7|Pn6|Pn5|Pn4|Pn3|Pn2|Pn1|Pn0|
||R/W:|R/W|R/W||R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|**Bit**|**Position**|**Bit Name**|||||**Function**||||||||||
|15|to 0|Pn[15:0]|||||These bits set the output level of the Pn_m pin||||(m = 0 to 15).||||||
||||||||0: Outputs low level||||||||||
||||||||1: Outputs high level||||||||||

## 41.3.2 Port Set and Reset Register (PSRn)

This register provides an alternative method for writing data to the Pn register.

The higher 16 bits of the PSRn register specify whether data can be written to the Pn.Pnm bit specified by the lower 16 bits of the PSRn register.

When reading, the higher 16 bits are read as 0000H. The lower 16 bits are read as the value of the Pn register.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|
||31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|PSRn|
||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|PSRn[31:16]|These are enable bits that specify whether the value of the corresponding lower bit of the|
||||PSRn.PSRnm bit is written to the corresponding Pn.Pnm bit.|
||||0: Pn.Pnm is independent of PSRn.PSRnm.|
||||1: Pn.Pnm becomes the value of the PSRn.PSRnm bit.|
||||Example:|
||||If PSRn.PSRn31 = 1, the value of PSRn.PSRn15 is written to Pn.Pn15.|
|15|to 0|PSRn[15:0]|These are data bits that specify the value of the Pn.Pnm bit if the corresponding higher bit,|
||||PSRn.PSRn (m+16), is 1.|
||||0: Pn.Pnm = 0|
||||1: Pn.Pnm = 1|

## 41.3.3 Port Pin Read Register (PPRn/JPPR0)

The PPRn register reflects the level of the Pn_m pin, the value of the Pn.Pnm bit, or the value output by the alternative function. The read value depends on register settings as described in Table 41.4, PPRn.PPRnm Bit Read Values .

||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|PPRn|
|||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|**Bit**|**Position**|**Bit Name**||||**Function**||||||||||||
|15|to 0|PPRn[15:0]||||The level of the Pn_m pin, the value of the Pn.Pnm bit,|||||||or the value output by the alternative|||||
|||||||function.||||||||||||

- Note: 1. For the PPRn register read value, see section 41.2.2, Pin Data Input/Output.

   2. The JPPR0[1:0] bits are control bits in the JTAG port pin read register (JPPR0).

## 41.3.4 Port Mode Register (PMn)

This register specifies whether the Pn_m pin is in input mode or in output mode.

||Bit:|15|14||13|12||11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PMn|PMn||PMn|PMn||PMn|PMn|PMn|PMn|PMn|PMn|PMn|PMn|PMn|PMn|PMn|PMn|
|||15|14||13|12||11|10|9|8|7|6|5|4|3|2|1|0|
||R/W:|R/W|R/W||R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|**Bit**|**Position**|**Bit Name**|||||**Function**|||||||||||||
|15|to 0|PMn[15:0]|||||Specifies input/output mode of the corresponding pin:|||||||||||||
||||||||0: Output mode|||(output|enabled)|||||||||
||||||||1: Input mode (output disabled)|||||||||||||

Caution: To use the Pn_m pin in port input mode (PMCn.PMCnm = 0 and PMn.PMnm = 1), the PIBCn.PIBCnm bit must be set to 1 so that the input buffer is enabled.

Note: After the register is reset (PIPCn.PIPCnm bit is 0), the PMn.PMnm bit specifies the I/O direction in port mode (PMCn.PMCnm = 0) and alternative mode (PMCn.PMCnm = 1). For the pins that are automatically configured in boot mode (see Table 8.3, Initial States by Areas in Boot Modes 0 and 1 to 3), the alternative function (not the PMn register) is used to control the I/O direction.

## 41.3.5 Port Mode Control Register (PMCn/JPMC0)

This register specifies whether the Pn_m pin is in port mode or in alternative mode.

||Bit:|15|14|13|12|11|10|9|8|7|6|5||4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PMCn|PMCn|PMCn|PMCn|PMCn|PMCn|PMCn|PMCn|PMCn|PMCn|PMCn||PMCn|PMCn|PMCn|PMCn|PMCn|
|||15|14|13|12|11|10|9|8|7|6|5||4|3|2|1|0|
||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|
|**Bit**|**Position**|**Bit Name**||||**Function**|||||||||||||
|15|to 0|PMCn[15:0]||||Specifies the operation mode of the corresponding pin:|||||||||||||
|||||||0: Port mode|||||||||||||

1: Alternative mode

Caution: The input/output control is not performed just by setting alternative mode (PMCn.PMCnm). Set 1 in the PIPCn.PIPCnm bit too when the I/O control is to be performed by using the alternative function.

Note: The JPMC0[1:0] bits are control bits in the JTAG port mode control register (JPMC0).

## 41.3.6 Port Function Control Register (PFCn)

This register, together with the PFCEn and PFCAEn register, specifies the alternative function of the pins.

The I/O direction of several alternative functions can be controlled directly by using the Pn_m pin. For these alternative functions, the PIPCn.PIPCnm bit must be set to “1”.

For all other alternative functions, the I/O direction is specified by using the PMn.PMnm bit.

||Bit:|15|14|13|12||11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PFCn|PFCn|PFCn|PFCn||PFCn|PFCn|PFCn|PFCn|PFCn|PFCn|PFCn|PFCn|PFCn|PFCn|PFCn|PFCn|
|||15|14|13|12||11|10|9|8|7|6|5|4|3|2|1|0|
||R/W:|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|**Bit**|**Position**|**Bit Name**||||**Function**|||||||||||||
|15|to 0|PFCn[15:0]||||Specifies the alternative function of a pin.|||||||||||||

## **Table 41.6 Alternative Mode Selection**

|**PMCn.**<br>**PMCnm**|**PFCAEn.**<br>**PFCAEnm**|**PFCEn.**<br>**PFCEnm**|**PFCn.**<br>**PFCnm**|**PMn.**<br>**PMnm**<br>**Function*2**|
|---|---|---|---|---|
|0|X|X|X|1<br>Port mode/input|
|||||0<br>Port mode/output|
|1***1**|0|0|0|1<br>Alternative mode/1st alternative function/input|
|||||0<br>Alternative mode/1st alternative function/output|
||||1|1<br>Alternative mode/2nd alternative function/input|
|||||0<br>Alternative mode/2nd alternative function/output|
|||1|0|1<br>Alternative mode/3rd alternative function/input|
|||||0<br>Alternative mode/3rd alternative function/output|
||||1|1<br>Alternative mode/4th alternative function/input|
|||||0<br>Alternative mode/4th alternative function/output|
||1|0|0|1<br>Alternative mode/5th alternative function/input|
|||||0<br>Alternative mode/5th alternative function/output|
||||1|1<br>Alternative mode/6th alternative function/input|
|||||0<br>Alternative mode/6th alternative function/output|
|||1|0|1<br>Alternative mode/7th alternative function/input|
|||||0<br>Alternative mode/7th alternative function/output|
||||1|1<br>Alternative mode/8th alternative function/input|
|||||0<br>Alternative mode/8th alternative function/output|

Cautions:1. When the PIPCn.PIPCnm bit is set to 1, the I/O direction is directly controlled by the alternative function and the setting of the PMn.PMnm bit becomes invalid.

2. Use alternative functions that are open to the public. If a mode to which no alternative function is assigned is selected, correct operation is not guaranteed.

## 41.3.7 Port Function Control Expansion Register (PFCEn)

This register, together with the PFCn and PFCAEn register, specifies the alternative function of the pins.

The I/O direction of several alternative functions can be controlled directly by using the Pn_m pin. For these alternative functions, the PIPCn.PIPCnm bit must be set to “1”.

For all other alternative functions, the I/O direction is specified by using the PMn.PMnm bit.

Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn PFCEn 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W **Bit Position Bit Name Function** 15 to 0 PFCEn[15:0] Specifies the alternative function of a pin.

## 41.3.8 Port NOT Register (PNOTn)

This register allows the Pn.Pnm bit to be inverted without directly writing to the Pn register.

||Bit:|15|14|13|12<br>11<br>10|9<br>8<br>7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PNOTn|PNOTn|PNOTn|PNOTn<br>PNOTn<br>PNOTn|PNOTn<br>PNOTn<br>PNOTn|PNOTn|PNOTn|PNOTn|PNOTn|PNOTn|PNOTn|PNOTn|
|||15|14|13|12<br>11<br>10|9<br>8<br>7|6|5|4|3|2|1|0|
||R/W:|W|W|W|W<br>W<br>W|W<br>W<br>W|W|W|W|W|W|W|W|
|**Bit**|**Position**|**Bit Name**|||**Function**|||||||||
|15|to 0|PNOTn[15:0]|||Specifies whether to invert Pn.Pnm.|||||||||
||||||0: Pn.Pnm is not inverted(Pnm → Pnm)|||||||||
||||||1: Pn.Pnm is inverted (Pnm<br>→ Pnm)|||||||||

## 41.3.9 Port Mode Set and Reset Register (PMSRn)

This register provides an alternative method for writing data to the PMn register.

The higher 16 bits of the PMSRn register specify whether data can be written to the PMn.PMnm bit specified by the lower 16 bits of the PMSRn register.

When reading, the higher 16 bits are read as 0000H. The lower 16 bits are read as the value of the PMn register.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|
||31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|PMSRn|
||15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|PMSRn[31:16]|These are enable bits that specify whether the value of the corresponding lower bit of the|
||||PMSRn.PMSRnm bit is written to the corresponding PMn.PMnm bit.|
||||0: PMn.PMnm does not depend on the PMSRn.PMSRnm bit.|
||||1: PMn.PMnm becomes the value of the PMSRn.PMSRnm bit.|
||||Example:|
||||If PMSRn.PMSRn31 = 1, the value of PMSRn.PMSRn15 is written to PMn.PMn15.|
|15|to 0|PMSRn[15:0]|These are data bits that specify the value of the PMn.PMnm bit if the corresponding higher|
||||bit, PMSRn.PMSRn (m + 16), is 1.|
||||0: PMn.PMnm = 0|

1: PMn.PMnm = 1

## 41.3.10 Port Mode Control Set and Reset Register (PMCSRn/JPMCSR0)

This register provides an alternative method for writing data to the PMCn register.

The higher bits of the PMCSRn register specify whether data can be written to the PMCn.PMCnm bit specified by the lower bits of the PMCSRn register.

When reading, the higher 16 bits are read as 0000H. The lower 16 bits are read as the value of the PMCn register.

||Bit:|31|30|29|28<br>27<br>26<br>25|24<br>23|22|21|20||19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PMCS|PMCS|PMCS|PMCS<br>PMCS<br>PMCS<br>PMCS|PMCS<br>PMCS|PMCS|PMCS|PMCS||PMCS|PMCS|PMCS|PMCS|
|||Rn31|Rn30|Rn29|Rn28<br>Rn27<br>Rn26<br>Rn25|Rn24<br>Rn23|Rn22|Rn21|Rn20||Rn19|Rn18|Rn17|Rn16|
||R/W:|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|
||Bit:|15|14|13|12<br>11<br>10<br>9|8<br>7|6|5|4||3|2|1|0|
|||PMCS|PMCS|PMCS|PMCS<br>PMCS<br>PMCS<br>PMCS|PMCS<br>PMCS|PMCS|PMCS|PMCS||PMCS|PMCS|PMCS|PMCS|
|||Rn15|Rn14|Rn13|Rn12<br>Rn11<br>Rn10<br>Rn9|Rn8<br>Rn7|Rn6|Rn5|Rn4||Rn3|Rn2|Rn1|Rn0|
||R/W:|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|
|**Bit**|**Position**|**Bit Name**|||**Function**||||||||||
|31|to 16|PMCSRn[31:16]|||These are enable bits that specify whether the|||value of the corresponding lower bit of the|||||||
||||||PMCSRn.PMCSRnm bit is written to the corresponding PMCn.PMCnm bit.||||||||||
||||||0: PMCn.PMCnm does not depend on the PMCSRn.PMCSRnm bit.||||||||||
||||||1: PMCn.PMCnm becomes the value of the PMCSRn.PMCSRnm bit.||||||||||
||||||Example:||||||||||
||||||If PMCSRn.PMCSRn31 = 1, the value of PMCSRn.PMCSRn15||||||is written to PMCn.PMCn15.||||
|15|to 0|PMCSRn[15:0]|||These are data bits that|specify the value of the PMCn.PMCnm bit if the corresponding|||||||||
||||||higher bit, PMCSRn.PMCSRn (m+16),||is 1.||||||||
||||||0: PMCn.PMCnm = 0||||||||||
||||||1: PMCn.PMCnm = 1||||||||||

Note: The JPMCSR0[1:0] bits are control bits in the JTAG port mode control set and reset register (JPMCSR0).

## 41.3.11 Port Function Control Additional Expansion Register (PFCAEn)

This register, together with the PFCn and PFCEn register, specifies the alternative function of the pins.

The I/O direction of several alternative functions can be controlled directly by using the Pn_m pin. For these alternative functions, the PIPCn.PIPCnm bit must be set to “1”.

For all other alternative functions, the I/O direction is specified by using the PMn.PMnm bit.

Use the PFCn.PFCnm, PFCEn.PFCEnm, and PFCAEn.PFCAEnm bits to select the alternative functions, and then set the PMCn.PMCnm bit to 1.

||Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|PFCAE|
|||n15|n14|n13|n12|n11|n10|n9|n8|n7|n6|n5|n4|n3|n2|n1|n0|
||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|**Bit**|**Position**|**Bit Name**|||**Function**|||||||||||||
|15|to 0|PFCAEn[15:0]|||Specifies the alternative function of a pin.|||||||||||||

Caution: Although some alternative functions are assigned to multiple pins in this LSI, only one of the pins can be used for each

alternative function. Do not set the same alternative function in multiple pins. For example, when the a/b/c pin is used

as the b pin, the b/d/e pin cannot be used as the b pin. Before using the b/d/e pin, set the pin as an alternative function other than b.

Note: For the allocation of the alternative functions, see the table of the pin functions of each port.

## 41.3.12 Port Input Buffer Control Register (PIBCn/JPIBC0)

This register specifies whether to enable or disable the Pn_m pin’s input buffer in port input mode (PMCn.PMCnm = 0 and PMn.PMnm = 1 or JPMC0.JPMC0 = 0).

||Bit:|15|14|13|12|11<br>10<br>9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PIBCn|PIBCn|PIBCn|PIBCn|PIBCn<br>PIBCn<br>PIBCn|PIBCn|PIBCn|PIBCn|PIBCn|PIBCn|PIBCn|PIBCn|PIBCn|PIBCn|
|||15|14|13|12|11<br>10<br>9|8|7|6|5|4|3|2|1|0|
||R/W:|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|**Bit**|**Position**|**Bit Name**|||**Function**|||||||||||
|15|to 0|PIBCn[15:0]|||These bits enable or disable the input buffer.|||||||||||
||||||0: Input buffer disabled|||||||||||
||||||1: Input buffer enabled|||||||||||

Note: When the input buffer is disabled, through current does not flow even when the pin level is Hi-Z. Thus the pin does not

need to be fixed to a high or low level externally (except for P2_0, P2_2, P2_7, P2_9, P5_8, P5_9, P5_10, P6_7, P7_2, P7_3, P7_6, and P7_9).

The JPIBC0[1:0] bits are control bits in the JTAG port input buffer control register (JPIBC0).

Caution: The input buffer is enabled regardless of the settings in this register when the output buffer is enabled and PBDCn.PBDCnm = 1.

## 41.3.13 Port Bidirection Control Register (PBDCn)

This register specifies whether to enable or disable the input buffers when the output buffers are enabled. If the PBDCn.PBDCnm bit is set to “1” when the output buffers are enabled, bidirectional mode is enabled, and the level of the Pn_m pin is always read via the PPRn.PPRnm bit.

||Bit:|15|14|13|12<br>11<br>10<br>9<br>8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||PBDCn|PBDCn|PBDCn|PBDCn<br>PBDCn<br>PBDCn<br>PBDCn<br>PBDCn|PBDCn|PBDCn|PBDCn|PBDCn|PBDCn|PBDCn|PBDCn|PBDCn|
|||15|14|13|12<br>11<br>10<br>9<br>8|7|6|5|4|3|2|1|0|
||R/W:|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|**Bit**|**Position**|**Bit Name**|||**Function**|||||||||
|15|to 0|PBDCn[15:0]|||Enables/disables bidirectional mode of||the corresponding pin:|||||||
||||||0: Bidirectional mode disabled|||||||||
||||||1: Bidirectional mode enabled|||||||||

Caution: When using the Pn_m pin as an alternative function (PMCn.PMCnm = 1 and PMn.PMnm = 0), the level of the Pn_m

pin can be read at the PPRn.PPRnm bit by setting PBDCn.PBDCnm to 1. Note, however, that in this case, the level of the Pn_m pin will be input to the alternative function that the Pn_m pin is being used as.

## 41.3.14 Port IP Control Register (PIPCn)

This register specifies whether the I/O direction of the Pn_m pin is controlled by the PMn.PMnm bit or by the alternative function in alternative mode (PMCn.PMCnm = 1). Set the PIPCn.PIPCnm bit to 0 to use the alternative functions listed in Table 41.7. Set the PIPCn.PIPCnm bit to 1 to use the alternative functions not listed in Table 41.7 . If the PIPCn.PIPCnm bit is set to 1, the I/O direction is controlled by the alternative function, and the setting of the PMn.PMnm bit becomes invalid.

||Bit:|15|14|13|12|11<br>10<br>9<br>8<br>7<br>6<br>5|4<br>3<br>2||1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||PIPCn|PIPCn|PIPCn|PIPCn|PIPCn<br>PIPCn<br>PIPCn<br>PIPCn<br>PIPCn<br>PIPCn<br>PIPCn|PIPCn<br>PIPCn<br>PIPCn||PIPCn|PIPCn|
|||15|14|13|12|11<br>10<br>9<br>8<br>7<br>6<br>5|4<br>3<br>2||1|0|
||R/W:|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W<br>R/W||R/W|R/W|
|**Bit**|**Position**|**Bit Name**|||**Function**||||||
|15|to 0|PIPCn[15:0]|||These bits specify how the I/O direction is controlled in alternative mode.||||||
||||||0: The I/O direction is controlled by the PMn.PMnm bit||(software I/O control).||||
||||||1: The I/O direction is controlled by the alternative function (direct I/O control).||||||

## **Table 41.7 Alternative Functions for Which the PIPCn.PIPCnm Bit Should be Set to 0**

|**Function**||**Pin Name**<br>**Remark**|
|---|---|---|
|Multi-function timer pulse unit 2||TIOC0A<br>Set the PIPCn.PIPCnm bit to 0, and specify input or output by<br>using the PMn.PMnm bit.<br>TIOC0B<br>TIOC0C<br>TIOC0D<br>TIOC1A<br>TIOC1B<br>TIOC2A<br>TIOC2B<br>TIOC3A<br>TIOC3B<br>TIOC3C<br>TIOC3D<br>TIOC4A<br>TIOC4B<br>TIOC4C<br>TIOC4D|
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
|Serial sound interface||SSITxD0<br>Set the PIPCn.PIPCnm bit and the PMn.PMnm bit to 0.<br>SSITxD1<br>SSITxD3|
||||
||||
|Watchdog timer||WDTOVF<br>Set the PIPCn.PIPCnm bit and the PMn.PMnm bit to 0.|

## 41.3.15 Serial Sound Interface Noise Canceler Control Register (SNCR)

This register controls the noise canceler in the input route from the LSI pin to a serial sound interface and the pins for MII supported in the Ethernet. Four lower-order bits can be set only when slave mode is selected for the corresponding channel of the serial sound interface.

In master mode, the bit corresponding to the channel of the serial sound interface must be set to 0.

|Bit:|31||30||29|28|27<br>26<br>25<br>24<br>23<br>22<br>21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—||—||—|—|—<br>—<br>—<br>—<br>—<br>—<br>—|—|—|—|—|—|
|R/W:|R||R||R|R|R<br>R<br>R<br>R<br>R<br>R<br>R|R|R|R|R|R|
|Bit:|15||14||13|12|11<br>10<br>9<br>8<br>7<br>6<br>5|4|3|2|1|0|
||—||—||—|—|—<br>—<br>—<br>—<br>—<br>ETSEL*<br>—|—|SSI3N|SSI2N|SSI1N|SSI0N|
||||||||||CE|CE|CE|CE|
|R/W:|R||R||R|R|R<br>R<br>R<br>R<br>R<br>R/W<br>R|R|R/W|R/W|R/W|R/W|
|**Bit Position**||**Bit Name**|||||**Function**||||||
|6||ETSEL*|||||Enables or disables the Ethernet controller and EthernetAVB with respect to the pins|||||for MII|
||||||||supported in the Ethernet.||||||
||||||||0: The Ethernet controller is enabled and the EthernetAVB is disabled.||||||
||||||||1: The EthernetAVB is enabled and the Ethernet controller is disabled.||||||
|5, 4||—|||||Reserved||||||
||||||||The write value should always be 0.||||||
|3||SSI3NCE|||||Serial Sound Interface Channel 3 Noise Canceler Enable||||||
||||||||Enables or disables the noise canceler of SSISCK3, SSIWS3,||and SSIRxD3.||||
||||||||0: Noise canceler is disabled.||||||
||||||||1: Noise canceler is enabled.||||||
|2||SSI2NCE|||||Serial Sound Interface Channel 2 Noise Canceler Enable||||||
||||||||Enables or disables the noise canceler of SSISCK2, SSIWS2,||and SSIDATA2.||||
||||||||0: Noise canceler is disabled.||||||
||||||||1: Noise canceler is enabled.||||||
|1||SSI1NCE|||||Serial Sound Interface Channel 1 Noise Canceler Enable||||||
||||||||Enables or disables the noise canceler of SSISCK1, SSIWS1,||and SSIRxD1.||||
||||||||0: Noise canceler is disabled.||||||
||||||||1: Noise canceler is enabled.||||||
|0||SSI0NCE|||||Serial Sound Interface Channel 0 Noise Canceler Enable||||||
||||||||Enables or disables the noise canceler of SSISCK0, SSIWS0,||and SSIRxD0.||||
||||||||0: Noise canceler is disabled.||||||
||||||||1: Noise canceler is enabled.||||||

Note: * This bit is only present in the RZ/A1LU. For the RZ/A1L and RZ/A1LC, the write value should always be 0.

## 41.4 Port Function

**Table 41.8 Number and Function of Ports**

|||**Size**|||
|---|---|---|---|---|
|**Port**|**Pin Name**|**(Number of Ports)**|**Input/Output**|**Note**|
|JTAG Port 0|JP0_0, JP0_1|2 bits|input||
|Port 0|P0_0 to P0_3|4 bits|input||
|Port 1|P1_0 to P1_15|16 bits|input/open-drain output|Output of only the P1_0 to P1_7 pins|
|||||is open-drain output.|
|Port 2|P2_0 to P2_9|10 bits|input/output||
|Port 3|P3_0 to P3_15|16 bits|input/output||
|Port 4|P4_0 to P4_7|8 bits|input/output||
|Port 5|P5_0 to P5_15|16 bits|input/output||
|Port 6|P6_0 to P6_15|16 bits|input/output||
|Port 7|P7_0 to P7_11|12 bits|input/output||
|Port 8|P8_0 to P8_15|16 bits|input/output|208-pin and 233-pin packages only|
|Port 9|P9_0 to P9_5|6 bits|input/output|208-pin and 233-pin packages only|

## 41.5 JTAG Port 0 (JP0)

## **Table 41.9 Pin Function (JP0)**

|**Table 41.9**<br>**Pin Function (JP0)**|**Table 41.9**<br>**Pin Function (JP0)**|||
|---|---|---|---|
|**Port Mode**||**Alternative Mode**||
|**Input**|**Output**|**Input**|**Output**|
|JP0_0||TDI||
|JP0_1|||TDO|

Caution: Only input in port mode.

## **Table 41.10 Control Registers (JP0)**

|**Register**<br>**Register Size**|**Valid Bit**<br>**Offset Address**<br>**<JPORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|
|---|---|
|JPPR0<br>16|1 and 0<br>R<br>H'0020<br>H'0000|
|JPMC0<br>16|1 and 0<br>R/W<br>H'0040<br>H'FFFF|
|JPMCSR0<br>32|17 and 16,<br>1 and 0<br>W, R/W<br>H'0090<br>H'0000_FFFF|
|JPIBC0<br>16|1 and 0<br>R/W<br>H'0400<br>H'0000|

Caution: An initial value is read if the bit is invalid. The write value should always be the initial value.

## 41.6 Port 0 (P0)

**Table 41.11 Pin Function (P0)**

|**Port Mode**|**Port Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|
|---|---|---|---|---|---|---|---|---|---|---|
|||**1st Alternative**||**2nd Alternative**||**3rd Alternative**||**4th Alternative**|||
|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**||**Output**|
|P0_0||||RxD0||IRQ4|||||
|P0_1||||RxD2||SSIRxD3|||ADTRG||
|P0_2||||RxD1||IRQ7|||||
|P0_3||||RxD3||SPDIF_IN|||||

Cautions: 1. Only input in port mode.

2. P0_0, P0_1, P0_2, P0_3 pins are MD_BOOT0, MD_BOOT1, MD_CLK, MD_CLKS functions in the state of RES = L.

## **Table 41.12 Control Registers (P0)**

|**Register**<br>**Register Size**|**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|
|---|---|
|PPR0<br>16|3 to 0<br>R<br>H'0200<br>H'0000|
|PMC0<br>16|3 to 0<br>R/W<br>H'0400<br>H'0000|
|PFC0<br>16|3 to 0<br>R/W<br>H'0500<br>H'0000|
|PFCE0<br>16|3 to 0<br>R/W<br>H'0600<br>H'0000|
|PMCSR0<br>32|19 to 16, 3 to 0<br>W, R/W<br>H'0900<br>H'0000_0000|
|PFCAE0<br>16|3 to 0<br>R/W<br>H’0A00<br>H'0000|
|PIBC0<br>16|3 to 0<br>R/W<br>H'4000<br>H'0000|

Caution: An initial value is read if the bit is invalid. The write value should always be the initial value.

## 41.7 Port 1 (P1)

**Table 41.13 Pin Function (P1)**

|**Port Mode**|**Port Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|
|---|---|---|---|---|---|---|---|---|---|
|||**1st Alternative**||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||
|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P1_0|P1_0|RIIC0SCL||IRQ4||ET_RXD0||DV0_DATA0||
|P1_1|P1_1|RIIC0SDA||IRQ5||ET_RXD1||DV0_DATA1||
|P1_2|P1_2|RIIC1SCL||IRQ6||ET_RXD2||DV0_DATA2||
|P1_3|P1_3|RIIC1SDA||IRQ7||ET_RXD3||DV0_DATA3||
|P1_4|P1_4|RIIC2SCL||IRQ0||DREQ0||VIO_D0||
|P1_5|P1_5|RIIC2SDA||IRQ1||||VIO_D1||
|P1_6|P1_6|RIIC3SCL||IRQ2||SSIRxD0||VIO_D2||
|P1_7|P1_7|RIIC3SDA||IRQ3||RxD2||VIO_D3||
|P1_8||AN0||IRQ0||RxD0||DV0_DATA4||
|P1_9||AN1||IRQ1||RxD1||DV0_DATA5||
|P1_10||AN2||IRQ2||RxD2||DV0_DATA6||
|P1_11||AN3||IRQ3||RxD3||DV0_DATA7||
|P1_12||AN4||IRQ4||ET_RXD0||VIO_D4||
|P1_13||AN5||IRQ5||ET_RXD1||VIO_D5||
|P1_14||AN6||IRQ6||ET_RXD2||VIO_D6||
|P1_15||AN7||IRQ7||ET_RXD3||VIO_D7||

Caution: P1_0 to P1_7 pins are input with open-drain output. P1_8 to P1_15 pins are only input.

**Table 41.14 Control Registers (P1)**

|**Register**<br>**Register Size**|**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|
|---|---|
|P1<br>16|7 to 0<br>R/W<br>H'0004<br>H'0000|
|PSR1<br>32|23 to 16,<br>7 to 0<br>W, R/W<br>H'0104<br>H'0000_0000|
|PPR1<br>16|15 to 0<br>R<br>H'0204<br>H'0000|
|PM1<br>16|7 to 0<br>R/W<br>H'0304<br>H'FFFF*2|
|PMC1<br>16|15 to 0<br>R/W<br>H'0404<br>H'0000|
|PFC1<br>16|15 to 0<br>R/W<br>H'0504<br>H'0000|
|PFCE1<br>16|15 to 0<br>R/W<br>H'0604<br>H'0000|
|PNOT1<br>16|7 to 0<br>W<br>H'0704<br>H'0000|
|PMSR1<br>32|23 to 16,<br>7 to 0<br>W, R/W<br>H'0804<br>H'0000_FFFF|
|PMCSR1<br>32|23 to 16,<br>7 to 0<br>W, R/W<br>H'0904<br>H'0000_0000|
|PFCAE1<br>16|15 to 0<br>R/W<br>H'0A04<br>H'0000|
|PIBC1<br>16|15 to 0<br>R/W<br>H'4004<br>H'0000|
|PBDC1<br>16|15 to 0<br>R/W<br>H'4104<br>H'0000|
|PIPC1<br>16|7 to 0<br>R/W<br>H'4204<br>H'FF00*2|

Cautions: 1. An initial value is read if the bit is invalid. The write value should always be the initial value.

2. The values of bits 8 to 15 of the PM1 and PIPC1 registers are fixed. When read, all of these bits are always read as

1.

## 41.8 Port 2 (P2)

**Table 41.15 Pin Function (P2)**

|**Table 41.15**|**Table 41.15**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|**Pin Function (P2)**|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Port Mode**||**Alternative Mode**|||||||||||
|||**1st Alternative**|||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||**5th Alternative**||
|**Input**|**Output**|**Input**|**Output**||**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P2_0|P2_0||CS3||RLIN30R*||SPDIF_IN||IRQ7||||
|P2_1|P2_1||RAS|||RLIN30TX*||SPDIF_OUT|IRQ6||||
|P2_2|P2_2||CAS||CAN1RX||TIOC0C||IRQ5||||
|P2_3|P2_3||CKE|||CAN1TX|TIOC0D||||||
|P2_4|P2_4||WE0<br>/<br>DQMLL||||TIOC4A||||||
|P2_5|P2_5||WE1<br>/WE<br>/<br>DQMLU||||TIOC3A||||||
|P2_6|P2_6||RD/WR||SSIRxD3||TIOC2A||||||
|P2_7|P2_7||CS0||SSISCK3||TIOC1A||IRQ2||||
|P2_8|P2_8||RD|||SSITxD3|TIOC0A|||||CAN0TX|
|P2_9|P2_9||A0||SSIWS3||SCK0||IRQ1||CAN0RX||
|Note: * RZ/A1L only<br>**Table 41.16**<br>**Control Registers (P2)**<br>**Register**<br>**Register Size**<br>**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|||||||||||||
|P2<br>16||||9 to 0<br>R/W<br>H'0008<br>H'0000|||||||||
|PSR2<br>32||||25 to 16, 9 to 0<br>W, R/W<br>H'0108<br>H'0000_0000|||||||||
|PPR2<br>16||||9 to 0<br>R<br>H'0208<br>H'0000|||||||||
|PM2<br>16||||9 to 0<br>R/W<br>H'0308<br>H'FFFF|||||||||
|PMC2<br>16||||9 to 0<br>R/W<br>H'0408<br>H'01C0 (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|||||||||
|PFC2<br>16||||9 to 0<br>R/W<br>H'0508<br>H'0000|||||||||
|PFCE2<br>16||||9 to 0<br>R/W<br>H'0608<br>H'0000|||||||||
|PNOT2<br>16||||9 to 0<br>W<br>H'0708<br>H'0000|||||||||
|PMSR2<br>32||||25 to 16, 9 to 0<br>W, R/W<br>H'0808<br>H'0000_FFFF|||||||||
|PMCSR2<br>32||||25 to 16, 9 to 0<br>W, R/W<br>H'0908<br>H'0000_01C0 (In boot mode 0),<br>H'0000_0000 (Other than in boot mode 0)|||||||||
|PFCAE2<br>16||||9 to 0<br>R/W<br>H'0A08<br>H'0000|||||||||
|PIBC2<br>16||||9 to 0<br>R/W<br>H'4008<br>H'0000|||||||||
|PBDC2<br>16||||9 to 0<br>R/W<br>H'4108<br>H'01C0 (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|||||||||
|PIPC2<br>16||||9 to 0<br>R/W<br>H'4208<br>H'01C0 (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|||||||||

Cautions: 1. An initial value is read if the bit is invalid. The write value should always be the initial value.

2. For the pins that are automatically configured in boot mode, see Table 8.3, Initial States by Areas in Boot Modes 0 and 1 to 3.

## 41.9 Port 3 (P3)

**Table 41.17 Pin Function (P3)**

|**Table 41.17**|**Table 41.17**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|**Pin Function (P3)**|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Port Mode**||**Alternative Mode**||||||||||||
|||**1st Alternative**||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||**5th Alternative**||**6th Alternative**||
|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P3_0|P3_0||A1|SD_D2_0|||LCD0_DATA0|ET_TXCLK||||||
|P3_1|P3_1||A2|SD_D3_0|||LCD0_DATA1||ET_TXER|||||
|P3_2|P3_2||A3|SD_CMD_0|||LCD0_DATA2||ET_TXEN|||||
|P3_3|P3_3||A4||SD_CLK_0||LCD0_DATA3|ET_RXCLK||||||
|P3_4|P3_4||A5|SD_D0_0|||LCD0_DATA4|ET_RXER||||||
|P3_5|P3_5||A6|SD_D1_0|||LCD0_DATA5|ET_RXDV||||||
|P3_6|P3_6||A7|SD_WP_0|||LCD0_DATA6|ET_COL||||||
|P3_7|P3_7||A8|SD_CD_0|||LCD0_DATA7|ET_CRS||||||
|P3_8|P3_8||A9|||AUDIO_CLK||DV0_DATA8||SCK3||||
|P3_9|P3_9||A10||||SPDIF_OUT|DV0_DATA9|||TxD3|||
|P3_10|P3_10||A11|SPBIO01_0||TIOC3B||DV0_DATA10||RxD3||||
|P3_11|P3_11||A12|SPBIO11_0||TIOC3A||DV0_DATA11||||||
|P3_12|P3_12||A13|SPBIO21_0||TIOC3C||DV0_DATA12||||||
|P3_13|P3_13||A14|SPBIO31_0||TIOC3D||DV0_DATA13||||||
|P3_14|P3_14||A15|VIO_CLK||SPDIF_IN||DV0_DATA14||SCK1|||AUDIO_<br>XOUT2|
|P3_15|P3_15||A16|VIO_FLD||||DV0_DATA15|||TxD1|||

## **Table 41.18 Control Registers (P3)**

|**Register**<br>**Register Size**|**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|
|---|---|
|P3<br>16|15 to 0<br>R/W<br>H'000C<br>H'0000|
|PSR3<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'010C<br>H'0000_0000|
|PPR3<br>16|15 to 0<br>R<br>H'020C<br>H'0000|
|PM3<br>16|15 to 0<br>R/W<br>H'030C<br>H'FFFF|
|PMC3<br>16|15 to 0<br>R/W<br>H'040C<br>H'FFFF (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|
|PFC3<br>16|15 to 0<br>R/W<br>H'050C<br>H'0000|
|PFCE3<br>16|15 to 0<br>R/W<br>H'060C<br>H'0000|
|PNOT3<br>16|15 to 0<br>W<br>H'070C<br>H'0000|
|PMSR3<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'080C<br>H'0000_FFFF|
|PMCSR3<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'090C<br>H'0000_FFFF (In boot mode 0),<br>H'0000_0000 (Other than in boot mode 0)|
|PFCAE3<br>16|15 to 0<br>R/W<br>H'0A0C<br>H'0000|
|PIBC3<br>16|15 to 0<br>R/W<br>H'400C<br>H'0000|
|PBDC3<br>16|15 to 0<br>R/W<br>H'410C<br>H'FFFF (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|
|PIPC3<br>16|15 to 0<br>R/W<br>H'420C<br>H'FFFF (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|

Caution: For the pins that are automatically configured in boot mode, see Table 8.3, Initial States by Areas in Boot Modes 0 and 1 to 3.

## 41.10 Port 4 (P4)

**Table 41.19 Pin Function (P4)**

|**Port Mode**|**Port Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|
|---|---|---|---|---|---|---|---|---|---|---|---|
|||**1st Alternative**||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||**5th Alternative**||
|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P4_0|P4_0||A17|VIO_VD||TIOC1B|||ET_MDC|CTS1||
|P4_1|P4_1||A18|VIO_HD||TIOC2B||ET_MDIO||RTS1||
|P4_2|P4_2||A19|SPBIO20_0|||TRACEDATA2*|||||
|P4_3|P4_3||A20|SPBIO30_0|||TRACEDATA3*|||||
|P4_4|P4_4||A21||SPBCLK_0||TRACECLK*|||||
|P4_5|P4_5||A22||SPBSSL_0||TRACECTL*|||||
|P4_6|P4_6||A23|SPBIO00_0|||TRACEDATA0*|||||
|P4_7|P4_7||A24|SPBIO10_0|||TRACEDATA1*|||||

Note: * RZ/A1L only

**Table 41.20 Control Registers (P4)**

|**Register**<br>**Register Size**|**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|
|---|---|
|P4<br>16|7 to 0<br>R/W<br>H'0010<br>H'0000|
|PSR4<br>32|23 to 16,<br>7 to 0<br>W, R/W<br>H'0110<br>H'0000_0000|
|PPR4<br>16|7 to 0<br>R<br>H'0210<br>H'0000|
|PM4<br>16|7 to 0<br>R/W<br>H'0310<br>H'FFFF|
|PMC4<br>16|7 to 0<br>R/W<br>H'0410<br>H'000F (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|
|PFC4<br>16|7 to 0<br>R/W<br>H'0510<br>H'0000|
|PFCE4<br>16|7 to 0<br>R/W<br>H'0610<br>H'0000|
|PNOT4<br>16|7 to 0<br>W<br>H'0710<br>H'0000|
|PMSR4<br>32|23 to 16,<br>7 to 0<br>W, R/W<br>H'0810<br>H'0000_FFFF|
|PMCSR4<br>32|23 to 16,<br>7 to 0<br>W, R/W<br>H'0910<br>H'0000_000F (In boot mode 0),<br>H'0000_0000 (Other than in boot mode 0)|
|PFCAE4<br>16|7 to 0<br>R/W<br>H'0A10<br>H'0000|
|PIBC4<br>16|7 to 0<br>R/W<br>H'4010<br>H'0000|
|PBDC4<br>16|7 to 0<br>R/W<br>H'4110<br>H'000F (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|
|PIPC4<br>16|7 to 0<br>R/W<br>H'4210<br>H'000F (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|

Cautions: 1. An initial value is read if the bit is invalid. The write value should always be the initial value.

2. For the pins that are automatically configured in boot mode, see Table 8.3, Initial States by Areas in Boot Modes 0 and 1 to 3.

## 41.11 Port 5 (P5)

**Table 41.21 Pin Function (P5)**

|**Port Mode**|**Port Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|**Alternative Mode**|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||**1st Alternative**|||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||**5th Alternative**||
|**Input**|**Output**|**Input**|**Output**||**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P5_0|P5_0|D0|||MMC_D4|||ET_TXD0|DV0_DATA16|||LCD0_TCON0|
|P5_1|P5_1|D1|||MMC_D5|||ET_TXD1|DV0_DATA17|||LCD0_TCON1|
|P5_2|P5_2|D2|||MMC_D6|||ET_TXD2|DV0_DATA18|||LCD0_TCON2|
|P5_3|P5_3|D3|||MMC_D7|||ET_TXD3|DV0_DATA19|||LCD0_TCON3|
|P5_4|P5_4|D4|||RSPCK2||SSISCK1||DV0_DATA20||||
|P5_5|P5_5|D5|||SSL20||SSIWS1||DV0_DATA21||||
|P5_6|P5_6|D6|||MOSI2|||SSITxD1|DV0_DATA22||SCK2||
|P5_7|P5_7|D7|||MISO2||SSIRxD1||DV0_DATA23|||TxD2|
|P5_8|P5_8|D8|||CAN0RX||TIOC4A||IRQ3||||
|P5_9|P5_9|D9||||CAN0TX|TIOC4B||IRQ4||||
|P5_10|P5_10|D10|||IERxD*||TIOC4C||IRQ5||||
|P5_11|P5_11|D11||||IETxD*|TIOC4D||IRQ6||||
|P5_12|P5_12|D12|||SSISCK2||SCK4|||AUDIO_XOUT2|||
|P5_13|P5_13|D13|||SSIWS2|||AUDIO_XOUT||AUDIO_XOUT3|||
|P5_14|P5_14|D14|||SSIDATA2||RxD4||TIOC2A||||
|P5_15|P5_15|D15|||SD_WP_1|||TxD4|||||
|Note: * RZ/A1L only<br>**Table 41.22**<br>**Control Registers (P5)**<br>**Register**<br>**Register Size**<br>**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|||||||||||||
|P5<br>16||||15 to 0<br>R/W<br>H'0014<br>H'0000|||||||||
|PSR5<br>32||||31 to 16,<br>15 to 0<br>W, R/W<br>H'0114<br>H'0000_0000|||||||||
|PPR5<br>16||||15 to 0<br>R<br>H'0214<br>H'0000|||||||||
|PM5<br>16||||15 to 0<br>R/W<br>H'0314<br>H'FFFF|||||||||
|PMC5<br>16||||15 to 0<br>R/W<br>H'0414<br>H'FFFF (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|||||||||
|PFC5<br>16||||15 to 0<br>R/W<br>H'0514<br>H'0000|||||||||
|PFCE5<br>16||||15 to 0<br>R/W<br>H'0614<br>H'0000|||||||||
|PNOT5<br>16||||15 to 0<br>W<br>H'0714<br>H'0000|||||||||
|PMSR5<br>32||||31 to 16,<br>15 to 0<br>W, R/W<br>H'0814<br>H'0000_FFFF|||||||||
|PMCSR5<br>32||||31 to 16,<br>15 to 0<br>W, R/W<br>H'0914<br>H'0000_FFFF (In boot mode 0),<br>H'0000_0000 (Other than in boot mode 0)|||||||||
|PFCAE5<br>16||||15 to 0<br>R/W<br>H'0A14<br>H'0000|||||||||
|PIBC5<br>16||||15 to 0<br>R/W<br>H'4014<br>H'0000|||||||||
|PBDC5<br>16||||15 to 0<br>R/W<br>H'4114<br>H'FFFF (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|||||||||
|PIPC5<br>16||||15 to 0<br>R/W<br>H'4214<br>H'FFFF (In boot mode 0),<br>H'0000 (Other than in boot mode 0)|||||||||

Caution: For the pins that are automatically configured in boot mode, see Table 8.3, Initial States by Areas in Boot Modes 0 and 1 to 3.

## 41.12 Port 6 (P6)

## **Table 41.23 Pin Function (P6)**

|**Port Mode**|**Port Mode**|||||||**Alternative M**|**Alternative M**|**Alternative M**|**ode**|**ode**|**ode**|**ode**|**ode**|**ode**|**ode**|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||**1st Alternative**||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||**5th Alt**|**ernative**|**6th Alternative**||**7th Alternative**||**8th Alternative**||
|**Input**|**Output **|**Input**|**Output **|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P6_0|P6_0|D16|||LCD0_<br>DATA8|RSPCK0||TCLKA|||WDTOVF|||||||
|P6_1|P6_1|D17|||LCD0_<br>DATA9|SSL00||TCLKB||||||||||
|P6_2|P6_2|D18|||LCD0_<br>DATA10|MOSI0||TCLKC||||||||||
|P6_3|P6_3|D19|||LCD0_<br>DATA11|MISO0||TCLKD||||||||||
|P6_4|P6_4|D20|||LCD0_<br>DATA12|SSISCK3||MLB_CLK<br>*1||||||||||
|||||||||AVB_CA<br>PTURE*2||||||||||
|P6_5|P6_5|D21|||LCD0_<br>DATA13|SSIWS3||MLB_SIG*1||||||||||
|||||||||AVB_GPTP<br>_EXTERN*2||||||||||
|P6_6|P6_6|D22|||LCD0_<br>DATA14||SSITxD3|MLB_DAT*1||||||||||
|P6_7|P6_7|D23|||LCD0_<br>DATA15|SSIRxD3||IRQ0||TIO|C3A|RLIN30RX<br>*1|||||TRACED<br>ATA0*3|
|P6_8|P6_8|D24|||LCD0_<br>DATA16|SSISCK0||IRQ1||TIO|C3B||RLIN30TX<br>*1||||TRACED<br>ATA1*3|
|P6_9|P6_9|D25|||LCD0_<br>DATA17|SSIWS0||IRQ2||TIO|C3C||||||TRACED<br>ATA2*3|
|P6_10|P6_10|D26|||LCD0_<br>DATA18||SSITxD0|IRQ3||TIO|C3D||CAN1TX||||TRACED<br>ATA3*3|
|P6_11|P6_11|D27|||LCD0_<br>DATA19|SSIRxD0||SSIDATA2||S|CK0|CAN1RX|||||TRACE<br>CTL*3|
|P6_12|P6_12|D28|||LCD0_<br>DATA20|RSPCK1||SSISCK2||R|TS0|DV0_<br>DATA0||||||
|P6_13|P6_13|D29|||LCD0_<br>DATA21|SSL10||SSIWS2||C|TS0|DV0_<br>DATA1||||||
|P6_14|P6_14|D30|||LCD0_<br>DATA22|MOSI1||SSIDATA2||RxD0||DV0_<br>DATA2||||||
|P6_15|P6_15|D31|||LCD0_<br>DATA23|MISO1|||||TxD0|DV0_<br>DATA3||||||

Note: 1. RZ/A1L only

2. RZ/A1LU only

3. RZ/A1LU and RZ/A1LC only

**Table 41.24 Control Registers (P6)**

|**Register**<br>**Register Size**|**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|
|---|---|
|P6<br>16|15 to 0<br>R/W<br>H'0018<br>H'0000|
|PSR6<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'0118<br>H'0000_0000|
|PPR6<br>16|15 to 0<br>R<br>H'0218<br>H'0000|
|PM6<br>16|15 to 0<br>R/W<br>H'0318<br>H'FFFF*|
|PMC6<br>16|15 to 0<br>R/W<br>H'0418<br>H'0000*|
|PFC6<br>16|15 to 0<br>R/W<br>H'0518<br>H'0000*|
|PFCE6<br>16|15 to 0<br>R/W<br>H'0618<br>H'0000*|
|PNOT6<br>16|15 to 0<br>W<br>H'0718<br>H'0000|
|PMSR6<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'0818<br>H'0000_FFFF|
|PMCSR6<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'0918<br>H'0000_0000|
|PFCAE6<br>16|15 to 0<br>R/W<br>H'0A18<br>H'0000*|
|PIBC6<br>16|15 to 0<br>R/W<br>H'4018<br>H'0000|
|PBDC6<br>16|15 to 0<br>R/W<br>H'4118<br>H'0000|
|PIPC6<br>16|15 to 0<br>R/W<br>H'4218<br>H'0000|

Caution: An internal power-on reset by the watchdog timer does not initialize PM6[0], PMC6[0], PFC6[0], PFCE6[0], and PFCAE6[0].

## 41.13 Port 7 (P7)

**Table 41.25 Pin Function (P7)**

|**Table 41.25**|**Table 41.25**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|**Pin Function (P7)**|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Port Mode**||**Alternative Mode**||||||||||||||||
|||**1st Alternative**||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||**5th Alternative**||**6th Alternative**||**7th Alternative**||**8th Alternative**||
|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P7_0|P7_0|LCD0_<br>EXTCLK||MMC_<br>CD||SD_<br>CD_1|||SPDIF_<br>OUT|TIOC2A||DV0_<br>DATA4||SCI_SCK0|||TRACE<br>CLK*2|
|P7_1|P7_1||CS1||AUDIO_<br>XOUT|SD_<br>WP_1|||TxD2|||DV0_<br>DATA5||SCI_<br>RXD0/<br>IrRXD||||
|P7_2|P7_2||CS4|MMC_D1||SD_D1_1||IRQ4||CAN0R<br>X||DV0_<br>DATA6|||SCI_<br>TXD0/<br>IrTXD|||
|P7_3|P7_3||CS5|MMC_D0||SD_D0_1||IRQ3|||CAN0T<br>X|DV0_<br>DATA7||SCI_CTS0<br>/RTS0||||
|P7_4|P7_4|WAIT|||MMC_<br>CLK||SD_<br>CLK_1||||IETxD*1||LCD0_<br>CLK|SCI_SCK1||||
|P7_5|P7_5||BS|MMC_CMD||SD_CMD_1|||TxD0|IERxD*1|||LCD0_<br>TCON4|SCI_<br>RXD1||||
|P7_6|P7_6||WE2<br>/<br>DQMUL|MMC_D3||SD_D3_1||IRQ6||CTS2|||LCD0_<br>TCON5||SCI_<br>TXD1|||
|P7_7|P7_7||WE3<br>/<br>DQMUU<br>/AH|MMC_D2||SD_D2_1||IRQ5||RTS2|||LCD0_<br>TCON6|SCI_CTS1<br>/RTS1||||
|P7_8|P7_8||CS2|SSISCK1||DV0_<br>CLK||IRQ3|||TxD0|||||||
|P7_9|P7_9||A25|SSIWS1||DV0_<br>VSYNC||IRQ5||SCK3||TIOC1A||||||
|P7_10|P7_10||TEND0||SSITxD1|DV0_<br>HSYNC||||RxD3||||||||
|P7_11|P7_11||DACK0|SSIRxD1||CAN_<br>CLK||SCK2|||TxD3||AUDIO_<br>XOUT||AUDIO_<br>XOUT3|||

Note: 1. RZ/A1L only 2. RZ/A1LU and RZ/A1LC only

**Table 41.26 Control Registers (P7)**

|**Register**<br>**Register Size**|**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|
|---|---|
|P7<br>16|11 to 0<br>R/W<br>H'001C<br>H'0000|
|PSR7<br>32|27 to 16,<br>11 to 0<br>W, R/W<br>H'011C<br>H'0000_0000|
|PPR7<br>16|11 to 0<br>R<br>H'021C<br>H'0000|
|PM7<br>16|11 to 0<br>R/W<br>H'031C<br>H'FFFF|
|PMC7<br>16|11 to 0<br>R/W<br>H'041C<br>H'0000|
|PFC7<br>16|11 to 0<br>R/W<br>H'051C<br>H'0000|
|PFCE7<br>16|11 to 0<br>R/W<br>H'061C<br>H'0000|
|PNOT7<br>16|11 to 0<br>W<br>H'071C<br>H'0000|
|PMSR7<br>32|27 to 16,<br>11 to 0<br>W, R/W<br>H'081C<br>H'0000_FFFF|
|PMCSR7<br>32|27 to 16,<br>11 to 0<br>W, R/W<br>H'091C<br>H'0000_0000|
|PFCAE7<br>16|11 to 0<br>R/W<br>H'0A1C<br>H'0000|
|PIBC7<br>16|11 to 0<br>R/W<br>H'401C<br>H'0000|
|PBDC7<br>16|11 to 0<br>R/W<br>H'411C<br>H'0000|
|PIPC7<br>16|11 to 0<br>R/W<br>H'421C<br>H'0000|

Caution: An initial value is read if the bit is invalid. The write value should always be the initial value.

## 41.14 Port 8 (P8)

**Table 41.27 Pin Function (P8)**

|**Table 41.27**|**Table 41.27**|**Pin Function (P8)**|**Pin Function (P8)**|**Pin Function (P8)**|**Pin Function (P8)**|**Pin Function (P8)**|**Pin Function (P8)**|**Pin Function (P8)**|**Pin Function (P8)**|**Pin Function (P8)**|**Pin Function (P8)**|
|---|---|---|---|---|---|---|---|---|---|---|---|
|**Port Mode**||**Alternative Mode**||||||||||
|||**1st Alternative**||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||**5th Alternative**||
|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P8_0|P8_0||LCD0_DATA0||ET_TXD0|SSISCK1||SCK3||||
|P8_1|P8_1||LCD0_DATA1||ET_TXD1|SSIWS1||RxD3||||
|P8_2|P8_2||LCD0_DATA2||ET_TXD2||SSITxD1||TxD3|||
|P8_3|P8_3||LCD0_DATA3||ET_TXD3|SSIRxD1||||||
|P8_4|P8_4||LCD0_DATA4|ET_TXCLK||||CTS2||TIOC0A||
|P8_5|P8_5||LCD0_DATA5||ET_TXER|||RTS2||TIOC0B||
|P8_6|P8_6||LCD0_DATA6||ET_TXEN|IRQ6||CTS1||TIOC0C||
|P8_7|P8_7||LCD0_DATA7|ET_RXD0||IRQ7||RTS1||TIOC0D||
|P8_8|P8_8||LCD0_TCON0|ET_RXD1|||AUDIO_XOUT|SCK2|||AUDIO_XOUT3|
|P8_9|P8_9||LCD0_TCON1|ET_RXD2|||CAN1TX|RxD2|||AUDIO_XOUT2|
|P8_10|P8_10||LCD0_TCON2|ET_RXD3||CAN1RX|||TxD2|||
|P8_11|P8_11||LCD0_TCON3|||SSISCK2||SCK4||||
|P8_12|P8_12||LCD0_TCON4|SPDIF_IN||SSIWS2||RxD4||||
|P8_13|P8_13||LCD0_TCON5||SPDIF_OUT|SSIDATA2|||TxD4|||
|P8_14|P8_14||LCD0_TCON6|ET_COL||SD_CD_0||SCK1||||
|P8_15|P8_15|||ET_CRS||SD_WP_0||RxD1||||

## **Table 41.28 Control Registers (P8)**

|**Register**<br>**Register Size**|**Valid Bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial Value**<br>**Location**<br>**R/W**|
|---|---|
|P8<br>16|15 to 0<br>R/W<br>H'0020<br>H'0000|
|PSR8<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'0120<br>H'0000_0000|
|PPR8<br>16|15 to 0<br>R<br>H'0220<br>H'0000|
|PM8<br>16|15 to 0<br>R/W<br>H'0320<br>H'FFFF|
|PMC8<br>16|15 to 0<br>R/W<br>H'0420<br>H'0000|
|PFC8<br>16|15 to 0<br>R/W<br>H'0520<br>H'0000|
|PFCE8<br>16|15 to 0<br>R/W<br>H'0620<br>H'0000|
|PNOT8<br>16|15 to 0<br>W<br>H'0720<br>H'0000|
|PMSR8<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'0820<br>H'0000_FFFF|
|PMCSR8<br>32|31 to 16,<br>15 to 0<br>W, R/W<br>H'0920<br>H'0000_0000|
|PFCAE8<br>16|15 to 0<br>R/W<br>H'0A20<br>H'0000|
|PIBC8<br>16|15 to 0<br>R/W<br>H'4020<br>H'0000|
|PBDC8<br>16|15 to 0<br>R/W<br>H'4120<br>H'0000|
|PIPC8<br>16|15 to 0<br>R/W<br>H'4220<br>H'0000|

## 41.15 Port 9 (P9)

**Table 41.29 Pin Function (P9)**

|**Table 41.29**|**Table 41.29**|**Pin Function (P9)**|**Pin Function (P9)**|**Pin Function (P9)**|**Pin Function (P9)**|**Pin Function (P9)**|**Pin Function (P9)**|**Pin Function (P9)**|**Pin Function (P9)**|**Pin Function (P9)**|**Pin Function (P9)**|
|---|---|---|---|---|---|---|---|---|---|---|---|
|**Port Mode**||**Alternative Mode**||||||||||
|||**1st Alternative**||**2nd Alternative**||**3rd Alternative**||**4th Alternative**||**5th Alternative**||
|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|**Input**|**Output**|
|P9_0|P9_0||||ET_MDC|SD_D1_0|||TxD1|||
|P9_1|P9_1|||ET_MDIO||SD_D0_0||CTS0||||
|P9_2|P9_2|RSPCK2||ET_RXCLK|||SD_CLK_0|RTS0||TIOC1A||
|P9_3|P9_3|SSL20||ET_RXER||SD_CMD_0||SCK0||TIOC1B||
|P9_4|P9_4|MOSI2||ET_RXDV||SD_D3_0||RxD0||TIOC2A||
|P9_5|P9_5|MISO2||||SD_D2_0|||TxD0|TIOC2B||

## **Table 41.30 Control Registers (P9)**

|**Register**<br>**Register Size**|**Valid bit**<br>**Offset Address**<br>**<PORTn_base>**<br>**Initial value**<br>**Location**<br>**R/W**|
|---|---|
|P9<br>16|5 to 0<br>R/W<br>H'0024<br>H'0000|
|PSR9<br>32|21 to 16,<br>5 to 0<br>W, R/W<br>H'0124<br>H'0000_0000|
|PPR9<br>16|5 to 0<br>R<br>H'0224<br>H'0000|
|PM9<br>16|5 to 0<br>R/W<br>H'0324<br>H'FFFF|
|PMC9<br>16|5 to 0<br>R/W<br>H'0424<br>H'0000|
|PFC9<br>16|5 to 0<br>R/W<br>H'0524<br>H'0000|
|PFCE9<br>16|5 to 0<br>R/W<br>H'0624<br>H'0000|
|PNOT9<br>16|5 to 0<br>W<br>H'0724<br>H'0000|
|PMSR9<br>32|21 to 16,<br>5 to 0<br>W, R/W<br>H'0824<br>H'0000_FFFF|
|PMCSR9<br>32|21 to 16,<br>5 to 0<br>W, R/W<br>H'0924<br>H'0000_0000|
|PFCAE9<br>16|5 to 0<br>R/W<br>H'0A24<br>H'0000|
|PIBC9<br>16|5 to 0<br>R/W<br>H'4024<br>H'0000|
|PBDC9<br>16|5 to 0<br>R/W<br>H'4124<br>H'0000|
|PIPC9<br>16|5 to 0<br>R/W<br>H'4224<br>H'0000|

Caution: An initial value is read if the bit is invalid. The write value should always be the initial value.

## 41.16 Port Control Logical Diagram

The figure below is a logical diagram of the port control function. Note: This figure shows the logic for reference, not the circuit.

**==> picture [471 x 302] intentionally omitted <==**

**----- Start of picture text -----**<br>
PBDC<br>PM BUFOE<br>PIBC BUFIE<br>PMC<br>PIPC<br>PPR 1 BUFI<br>0<br>P 0<br>BUFO<br>1<br>PSR<br>PNOT<br>PFC<br>01001011 ALT_IDL8-1<br>PFCE 00101101<br>00010111 IP_ENT8-1<br>PFCAE<br>PMSR<br>PMCSR<br>12345678 12345678 12345678 12345678<br>ALT_OUT IP_ENO IP_ENI ALT_IN<br>Internal IPs<br>Peripheral bus(APB)<br>Clamp<br>ALT_SEL8-1<br>**----- End of picture text -----**<br>

**Figure 41.1 Port Control Logical Diagram**

## 41.17 Flowchart Examples of Port Setting

(a) shows an example flow of setting the Pn_m pin to port mode. (b) shows an example flow of setting the Pn_m pin to software I/O control alternative mode. (c) shows an example flow of setting the Pn_m pin to direct I/O control alternative mode.

## (a) In Port Mode

**==> picture [360 x 303] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Specify PIBCn.PIBCnm bit = 0<br>Specify PBDCn.PBDCnm bit = 0<br>Port initialization:<br>Set the initial port values.<br>Specify PMn.PMnm bit = 1<br>(The port is set to input mode<br>and the input buffer is disabled.)<br>Specify PMCn.PMCnm bit = 0<br>Specify PIPCn.PIPCnm bit = 0<br>Output mode<br>Input or output?<br>Input mode<br>Port settings:<br>Specify PBDCn.PBDCnm bit Set appropriate values.<br>Specify Pn.Pnm bit<br>Specify PIBCn.PIBCnm bit = 1 Specify PMn.PMnm bit = 0<br>**----- End of picture text -----**<br>

**Figure 41.2 Example Flow of Port Settings (in Port Mode) (a)**

## (b) In Software I/O Control Alternative Mode

**==> picture [367 x 391] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Specify PIBCn.PIBCnm bit = 0<br>Specify PBDCn.PBDCnm bit = 0<br>Port initialization:<br>Set the initial port values.<br>Specify PMn.PMnm bit = 1<br>(The port is set to input mode<br>and the input buffer is disabled.)<br>Specify PMCn.PMCnm bit = 0<br>Specify PIPCn.PIPCnm bit = 0<br>Output mode<br>Input or output?<br>Input mode<br>Specify PBDCn.PBDCnm bit<br>Specify PFCn.PFCnm,<br>PFCEn.PFCEnm,<br>PFCAEn.PFCAEnm bits<br>Specify PFCn.PFCnm,  Port settings:<br>PFCEn.PFCEnm,  Set appropriate values.<br>PFCAEn.PFCAEnm bits Specify PMCn.PMCnm bit = 1<br>Specify PMCn.PMCnm bit = 1<br>Specify PMn.PMnm bit = 0<br>Temporarily enters<br>alternative input mode. [*]<br>**----- End of picture text -----**<br>

**Figure 41.3 Example Flow of Port Settings (in Software I/O Control Alternative Mode) (b)**

Caution: When the Pn_m pin is set to the output mode of the software I/O control alternative mode, alternative input mode is temporarily enabled during the period from when the PMCn.PMCnm bit is set to 1 to when the PMn.PMnm bit is set to 0. Therefore, if a signal regarding interrupt has been set for the port alternative function, configure the setting so that interrupt does not occur or becomes invalid.

## (c) In Direct I/O Control Alternative Mode

**==> picture [294 x 306] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Specify PIBCn.PIBCnm bit = 0<br>Specify PBDCn.PBDCnm bit = 0<br>Port initialization:<br>Set the initial port values.<br>Specify PMn.PMnm bit = 1<br>(The port is set to input mode<br>and the input buffer is disabled.)<br>Specify PMCn.PMCnm bit = 0<br>Specify PIPCn.PIPCnm bit = 0<br>Input function port settings:<br>Specify PBDCn.PBDCnm bit Set the PBDCn.PBDCnm bit to 1<br>when using an alternative function that<br>requires a pin to operate as both an input<br>and an output.<br>Specify PFCn.PFCnm,<br>PFCEn.PFCEnm,<br>PFCAEn.PFCAEnm bits<br>Port settings:<br>Set appropriate values.<br>Specify PIPCn.PIPCnm bit = 1<br>Specify PMCn.PMCnm bit = 1<br>**----- End of picture text -----**<br>

**Figure 41.4 Example Flow of Port Settings (in Direct I/O Control Alternative Mode) (c)**
