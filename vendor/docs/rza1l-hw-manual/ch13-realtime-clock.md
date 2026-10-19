# 13. Realtime Clock

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 552–570. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI has a realtime clock and a 32.768-kHz crystal oscillator.

## 13.1 Features

- Clock and calendar functions (BCD format): Seconds, minutes, hours, day of the week, day, month, and year.

- 1-Hz to 64-Hz timer (binary format)

   - 64-Hz counter indicates the state of the divider circuit between 64 Hz and 1 Hz

- Start/stop function

- 30-second adjust function

- Alarm interrupt: Comparison with seconds, minutes, hours, day of the week, day, month, or year can be selected as a condition for the alarm interrupt

- Periodic interrupt: the interrupt cycle may be 1/64 second, 1/16 second, 1/4 second, 1/2 second, 1 second, or 2 seconds

- Carry interrupt: a carry interrupt indicates that a second counter carry is generated or a 64-Hz counter carry is generated reading the 64-Hz counter

- Automatic leap year adjustment

- The external clock signal input for internal operation or the external clock signal input dedicated to the clock operation can be selected as the operating clock signal for the clock function.

- Recovery from deep standby mode can be performed by an alarm interrupt.

Figure 13.1 shows the block diagram.

**==> picture [368 x 399] intentionally omitted <==**

**----- Start of picture text -----**<br>
RTC_X1<br>Crystal 32.768 kHz<br>oscillator<br>RTC_X2<br>128 Hz<br>Prescaler R64CNT RSECCNT RSECAR<br>EXTAL RMINCNT RMINAR<br>Crystal<br>oscillator<br>XTAL RCR5 RHRCNT RHRAR<br>RFRH<br>RDAYCNT RDAYAR<br>RFRL<br>Operation<br>control circuit RWKCNT RWKAR<br>RCR1<br>RMONCNT RMONAR<br>RCR2<br>Interrupt<br>control circuit<br>RCR3 RYRCNT RYRAR<br>ARM<br>Interrupt<br>PRD signals<br>CUP<br>[Legend]<br>RSECCNT: Second counter  RSECAR: Second alarm register<br>RMINCNT: Minute counter RMINAR:  Minute alarm register<br>RHRCNT: Hour counter RHRAR: Hour alarm register<br>RWKCNT: Day of week counter RWKAR: Day of week alarm register<br>RDAYCNT:  Day counter RDAYAR: Day alarm register<br>RMONCNT:  Month counter RMONAR: Month alarm register<br>RYRCNT: Year counter RYRAR: Year alarm register<br>R64CNT: 64-Hz counter RCR1: Control register 1<br>RFRH/L: Frequency register RCR2: Control register 2<br>RCR3: Control register 3<br>RCR5: Control register 5<br> Bus interface Peripheral  bus<br>**----- End of picture text -----**<br>

**Figure 13.1 Block Diagram**

## 13.2 Input/Output Pin

Table 13.1 shows the pin configuration.

## **Table 13.1 Pin Configuration**

|**Pin Name**|**Symbol**<br>**I/O**<br>**Description**|
|---|---|
|Realtime clock crystal<br>resonator pin/external clock|RTC_X1<br>Input<br>Connects a 32.768-kHz crystal resonator for this module.<br>External clock can be input to the RTC_X1 pin.<br>RTC_X2<br>Output|
|Internal clock crystal<br>resonator/external clock|EXTAL<br>Input<br>Connects crystal resonator used for internal operation.<br>For details, see section 6, Clock Pulse Generator.<br>XTAL<br>Output|

## 13.3 Register Descriptions

Table 13.2 shows the register configuration.

## **Table 13.2 Register Configuration**

|**Register Name**|**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|---|---|
|64-Hz counter|R64CNT<br>R<br>H'xx<br>H'FCFF1000<br>8|
|Second counter|RSECCNT<br>R/W<br>H'xx<br>H'FCFF1002<br>8|
|Minute counter|RMINCNT<br>R/W<br>H'xx<br>H'FCFF1004<br>8|
|Hour counter|RHRCNT<br>R/W<br>H'xx<br>H'FCFF1006<br>8|
|Day of week counter|RWKCNT<br>R/W<br>H'0x<br>H'FCFF1008<br>8|
|Day counter|RDAYCNT<br>R/W<br>H'xx<br>H'FCFF100A<br>8|
|Month counter|RMONCNT<br>R/W<br>H'xx<br>H'FCFF100C<br>8|
|Year counter|RYRCNT<br>R/W<br>H'xxxx<br>H'FCFF100E<br>16|
|Second alarm register|RSECAR<br>R/W<br>H'xx<br>H'FCFF1010<br>8|
|Minute alarm register|RMINAR<br>R/W<br>H'xx<br>H'FCFF1012<br>8|
|Hour alarm register|RHRAR<br>R/W<br>H'xx<br>H'FCFF1014<br>8|
|Day of week alarm register|RWKAR<br>R/W<br>H'xx<br>H'FCFF1016<br>8|
|Day alarm register|RDAYAR<br>R/W<br>H'xx<br>H'FCFF1018<br>8|
|Month alarm register|RMONAR<br>R/W<br>H'xx<br>H'FCFF101A<br>8|
|Year alarm register|RYRAR<br>R/W<br>H'xxxx<br>H'FCFF1020<br>16|
|Control register 1|RCR1<br>R/W<br>H'xx<br>H'FCFF101C<br>8|
|Control register 2|RCR2<br>R/W<br>H'01<br>H'FCFF101E<br>8|
|Control register 3|RCR3<br>R/W<br>H'x0<br>H'FCFF1024<br>8|
|Control register 5|RCR5<br>R/W<br>H'0x<br>H'FCFF1026<br>8|
|Frequency register|RFRH<br>R/W<br>H'xxxx<br>H'FCFF102A<br>16|
||RFRL<br>R/W<br>H'xxxx<br>H'FCFF102C<br>16|

## 13.3.1 64-Hz Counter (R64CNT)

R64CNT indicates the state of the divider circuit between 64 Hz and 1 Hz.

Reading this register, when carry from 128-Hz divider stage is generated, sets the CF bit in the control register 1 (RCR1) to 1, which indicates that the carrying and reading the 64-Hz counter are performed at the same time. In this case, the R64CNT should be read again after writing 0 to the CF bit in RCR1 since the read value is not valid.

Setting the RESET or ADJ bit in the control register 2 (RCR2) to 1 initializes the divider circuit and the R64CNT.

|BIt:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||-|1Hz|2Hz|4Hz|8Hz|16Hz|32Hz|64Hz|
|Initial value:|0|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|
|R/W:|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|6|1 Hz|Undefined|R|Indicate the state of the divider circuit between 64 Hz and 1 Hz.|
|5|2 Hz|Undefined|R||
|4|4 Hz|Undefined|R||
|3|8 Hz|Undefined|R||
|2|16 Hz|Undefined|R||
|1|32 Hz|Undefined|R||
|0|64 Hz|Undefined|R||

## 13.3.2 Second Counter (RSECCNT)

RSECCNT is the counter used for setting/counting the BCD-coded second value. The count operation is performed by a carry for each second of the 64-Hz counter.

The assignable range is from 00 through 59 (practically in BCD); otherwise an operation error will occur. Carry out write processing after stopping the count operation through the setting of the START bit in RCR2.

|BIt:|7|5<br>6|4|3|2|1|0|
|---|---|---|---|---|---|---|---|
||-|10 seconds|||1 second|||
|Initial value:|0|Undefined Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|
|R/W:|R|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|6 to 4|10 seconds|Undefined|R/W|Counting Ten's Position of Seconds|
|||||Counts from 0 to 5 for 60-seconds counting.|
|3 to 0|1 second|Undefined|R/W|Counting One's Position of Seconds|
|||||Counts from 0 to 9, one number per second. When a carry is generated, 1 is|
|||||added to the ten's position.|

## 13.3.3 Minute Counter (RMINCNT)

RMINCNT is the counter used for setting/counting the BCD-coded minute value. The count operation is performed by a carry for each minute of the second counter.

The assignable range is from 00 through 59 (practically in BCD); otherwise an operation error will occur. Carry out write processing after stopping the count operation through the setting of the START bit in RCR2.

||||BIt:||7|1<br>2<br>3<br>4<br>5<br>6|0||
|---|---|---|---|---|---|---|---|---|
||||||-|10 minutes<br>1 minute|||
|||Initial|value:||0|Undefined Undefined Undefined Undefined Undefined Undefined|Undefined||
||||R/W:||R|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7|—|0|R|||Reserved|||
|||||||This bit is always read as 0.The write value should always be 0.|||
|6 to 4|10 minutes|Undefined|R/W|||Counting Ten's Position of Minutes|||
|||||||Counts from 0 to 5 for 60-minutes counting.|||
|3 to 0|1 minute|Undefined|R/W|||Counting One's Position of Minutes|||
|||||||Counts from 0 to 9, one number per|minute. When a carry is generated, 1 is||
|||||||added to the ten's position.|||

## 13.3.4 Hour Counter (RHRCNT)

RHRCNT is the counter used for setting/counting the BCD-coded hour value. The count operation is performed by a carry for each 1 hour of the minute counter.

The assignable range is from 00 through 23 (practically in BCD); otherwise an operation error will occur. Carry out write processing after stopping the count operation through the setting of the START bit in RCR2.

||||BIt:||7|1<br>2<br>3<br>4<br>5<br>6|0||
|---|---|---|---|---|---|---|---|---|
||||||-|-<br>10 hours<br>1 hour|||
|||Initial|value:||0|Undefined Undefined Undefined Undefined Undefined<br>0|Undefined||
||||R/W:||R|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R|R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7, 6|—|All 0|R|||Reserved|||
|||||||These bits are always read as 0. The write||value should always be 0.|
|5, 4|10 hours|Undefined|R/W|||Counting Ten's Position of Hours|||
|||||||Counts from 0 to 2 for ten's position of hours.|||
|3 to 0|1 hour|Undefined|R/W|||Counting One's Position of Hours|||
|||||||Counts from 0 to 9, one number per hour. When a carry is generated, 1 is added|||
|||||||to the ten's position.|||

## 13.3.5 Day of Week Counter (RWKCNT)

RWKCNT is the counter used for setting/counting the BCD-coded day-of-week value. The count operation is performed by a carry for each day of the hour counter.

The assignable range is from 0 through 6 (practically in BCD); otherwise an operation error will occur. Carry out write processing after stopping the count operation through the setting of the START bit in RCR2.

||||BIt:||7|5<br>6|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-<br>-|-|-||Day|||
|||Initial|value:||0|0<br>0|0|0|Undefined|Undefined|Undefined||
||||R/W:||R|R<br>R|R|R|R/W|R/W|R/W||
|||**Initial**|||||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||||||
|7 to 3|—|All 0|R|||Reserved|||||||
|||||||These bits are always read as||||0. The write||value should always be 0.|
|2 to 0|Day|Undefined|R/W|||Day-of-Week Counting|||||||
|||||||Day-of-week is indicated with a binary code.|||||||
|||||||000: Sunday|||||||
|||||||001: Monday|||||||
|||||||010: Tuesday|||||||
|||||||011: Wednesday|||||||
|||||||100: Thursday|||||||
|||||||101: Friday|||||||
|||||||110: Saturday|||||||
|||||||111: Reserved (setting prohibited)|||||||

## 13.3.6 Day Counter (RDAYCNT)

RDAYCNT is the counter used for setting/counting the BCD-coded day value. The count operation is performed by a carry for each day of the hour counter.

The assignable range is from 01 through 31 (practically in BCD); otherwise an operation error will occur. Carry out write processing after stopping the count operation through the setting of the START bit in RCR2.

The assignable range changes depending on the month and in leap years. Confirm the correct setting. A leap year is determined by checking if the year counter (RYRCNT) value is divisible by 400, 100, and 4.

||||BIt:||7|3<br>4<br>5<br>6|1<br>2|0||
|---|---|---|---|---|---|---|---|---|---|
||||||-|-<br>10 days|1 day|||
|||Initial|value:||0|Undefined Undefined Undefined <br>0|Undefined Undefined|Undefined||
||||R/W:||R|R<br>R/W<br>R/W<br>R/W|R/W<br>R/W|R/W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||
|7, 6|—|All 0|R|||Reserved||||
|||||||These bits are always read as 0. The write|||value should always be 0.|
|5, 4|10 days|Undefined|R/W|||Counting Ten's Position|of Days|||
|3 to 0|1 day|Undefined|R/W|||Counting One's Position of Days||||
|||||||Counts from 0 to 9, one|number per|day. When a carry is generated, 1 is added||
|||||||to the ten's position.||||

## 13.3.7 Month Counter (RMONCNT)

RMONCNT is the counter used for setting/counting the BCD-coded month value. The count operation is performed by a carry for each month of the date counter.

The assignable range is from 01 through 12 (practically in BCD); otherwise an operation error will occur. Carry out write processing after stopping the count operation through the setting of the START bit in RCR2.

||||BIt:||7|4<br>5<br>6|2<br>3|1|0||
|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-<br>-<br>10<br>months|1 month||||
|||Initial|value:||0|Undefined <br>0<br>0|Undefined Undefined|Undefined|Undefined||
||||R/W:||R|R<br>R<br>R/W|R/W<br>R/W|R/W|R/W||
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||||
|7 to 5|—|All 0|R|||Reserved|||||
|||||||These bits are always read as||0. The write||value should always be 0.|
|4|10 months|Undefined|R/W|||Counting Ten's Position of Months|||||
|3 to 0|1 month|Undefined|R/W|||Counting One's Position of Months|||||
|||||||Counts from 0 to 9, one number per|||month. When a carry is generated, 1 is||
|||||||added to the ten's position.|||||

## 13.3.8 Year Counter (RYRCNT)

RYRCNT is the counter used for setting/counting the BCD-coded year value. The count operation is performed by a carry for each year of the month counter.

The assignable range is from 0000 through 9999 (practically in BCD); otherwise an operation error will occur. Carry out write processing after stopping the count operation through the setting of the START bit in RCR2.

|BIt:|15|14|13|12|11|9<br>10|8|7|5<br>6|4|3|1<br>2|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||1000|years|||100 years|||10 years|||1 year||
|Initial value:|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined Undefined|Undefined|Undefined|Undefined Undefined|Undefined|Undefined|Undefined Undefined|Undefined|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W<br>R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 12|1000 years|Undefined|R/W|Counting Thousand's Position of Years|
|11 to 8|100 years|Undefined|R/W|Counting Hundred's Position of Years|
|7 to 4|10 years|Undefined|R/W|Counting Ten's Position of Years|
|3 to 0|1 year|Undefined|R/W|Counting One's Position of Years|

## 13.3.9 Second Alarm Register (RSECAR)

RSECAR is an alarm register corresponding to the BCD-coded second counter RSECCNT. When the ENB bit is set to 1, a comparison with the RSECCNT value is performed. From among RSECAR/RMINAR/RHRAR/RWKAR/RDAYAR/ RMONAR/RCR3, the counter and alarm register comparison is performed only on those with ENB bits set to 1, and if each of those coincides, an alarm flag of RCR1 is set to 1.

The assignable range is from 00 through 59  ENB bits (practically in BCD); otherwise an operation error will occur.

||||7<br>BIt:|3<br>4<br>5<br>6|1<br>2|0||
|---|---|---|---|---|---|---|---|
||||ENB|10 seconds|1 second|||
|||Initial|Undefined <br>value:|Undefined Undefined Undefined Undefined|Undefined Undefined|Undefined||
||||R/W<br>R/W:|R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W|R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**||||
|7|ENB|Undefined|R/W|When this bit is set to 1,|a comparison with the RSECCNT value is performed.|||
|6 to 4|10 seconds|Undefined|R/W|Ten's position of seconds setting value||||
|3 to 0|1 second|Undefined|R/W|One's position of seconds setting value||||

## 13.3.10 Minute Alarm Register (RMINAR)

RMINAR is an alarm register corresponding to the BCD-coded minute counter RMINCNT. When the ENB bit is set to 1, a comparison with the RMINCNT value is performed. From among RSECAR/RMINAR/RHRAR/RWKAR/RDAYAR/ RMONAR/RCR3, the counter and alarm register comparison is performed only on those with ENB bits set to 1, and if each of those coincides, an alarm flag of RCR1 is set to 1.

The assignable range is from 00 through 59  ENB bits (practically in BCD); otherwise an operation error will occur.

|BIt:|7|5<br>6|4|3|2|1|0|
|---|---|---|---|---|---|---|---|
||ENB|10 minutes|||1 minute|||
|Initial value:|Undefined|Undefined Undefined|Undefined|Undefined|Undefined|Undefined|Undefined|
|R/W:|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|ENB|Undefined|R/W|When this bit is set to 1, a comparison with the RMINCNT value is performed.|
|6 to 4|10 minutes|Undefined|R/W|Ten's position of minutes setting value|
|3 to 0|1 minute|Undefined|R/W|One's position of minutes setting value|

## 13.3.11 Hour Alarm Register (RHRAR)

RHRAR is an alarm register corresponding to the BCD-coded hour counter RHRCNT. When the ENB bit is set to 1, a comparison with the RHRCNT value is performed. From among RSECAR/RMINAR/RHRAR/RWKAR/RDAYAR/ RMONAR/RCR3, the counter and alarm register comparison is performed only on those with ENB bits set to 1, and if each of those coincides, an alarm flag of RCR1 is set to 1.

The assignable range is from 00 through 23  ENB bits (practically in BCD); otherwise an operation error will occur.

||||BIt:|7|1<br>2<br>3<br>4<br>5<br>6|0||
|---|---|---|---|---|---|---|---|
|||||ENB|-<br>10 hours<br>1 hour|||
|||Initial|value:|Undefined|Undefined Undefined Undefined Undefined Undefined <br>0|Undefined||
||||R/W:|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R|R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||
|7|ENB|Undefined|R/W||When this bit is set to 1, a comparison with the RHRCNT value is performed.|||
|6|—|0|R||Reserved|||
||||||This bit is always read as 0. The write value should always be 0.|||
|5, 4|10 hours|Undefined|R/W||Ten's position of hours setting value|||
|3 to 0|1 hour|Undefined|R/W||One's position of hours setting value|||

## 13.3.12 Day of Week Alarm Register (RWKAR)

RWKAR is an alarm register corresponding to the BCD-coded day of week counter RWKCNT. When the ENB bit is set to 1, a comparison with the RWKCNT value is performed. From among RSECAR/RMINAR/RHRAR/RWKAR/ RDAYAR/RMONAR/RCR3, the counter and alarm register comparison is performed only on those with ENB bits set to 1, and if each of those coincides, an alarm flag of RCR1 is set to 1.

The assignable range is from 0 through 6 + ENB bits (practically in BCD); otherwise an operation error will occur.

|BIt:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||ENB|-|-|-|-||Day||
|Initial value:|Undefined|0|0|0|0|Undefined|Undefined|Undefined|
|R/W:|R/W|R|R|R|R|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|ENB|Undefined|R/W|When this bit is set to 1, a comparison with the RWKCNT value is performed.|
|6 to 3|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|2 to 0|Day|Undefined|R/W|Day of Week Setting Value|
|||||000: Sunday|
|||||001: Monday|
|||||010: Tuesday|
|||||011: Wednesday|
|||||100: Thursday|
|||||101: Friday|
|||||110: Saturday|
|||||111: Reserved (setting prohibited)|

## 13.3.13 Day Alarm Register (RDAYAR)

RDAYAR is an alarm register corresponding to the BCD-coded day counter RDAYCNT. When the ENB bit is set to 1, a comparison with the RDAYCNT value is performed. From among RSECAR/RMINAR/RHRAR/RWKAR/RDAYAR/ RMONAR/RCR3, the counter and alarm register comparison is performed only on those with ENB bits set to 1, and if each of those coincides, an alarm flag of RCR1 is set to 1.

The assignable range is from 01 through 31 + ENB bits (practically in BCD); otherwise an operation error will occur.

||||BIt:|7|1<br>2<br>3<br>4<br>5<br>6|0||
|---|---|---|---|---|---|---|---|
|||||ENB|-<br>10 days<br>1 day|||
|||Initial|value:|Undefined|Undefined Undefined Undefined Undefined Undefined <br>0|Undefined||
||||R/W:|R/W|R/W<br>R/W<br>R<br>R/W<br>R/W<br>R/W|R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||
|7|ENB|Undefined|R/W||When this bit is set to 1, a comparison with the RDAYCNT value is performed.|||
|6|—|0|R||Reserved|||
||||||This bit is always read as 0. The write value should always be 0.|||
|5, 4|10 days|Undefined|R/W||Ten's position of days setting value|||
|3 to 0|1 day|Undefined|R/W||One's position of days setting value|||

## 13.3.14 Month Alarm Register (RMONAR)

RMONAR is an alarm register corresponding to the BCD-coded month counter RMONCNT. When the ENB bit is set to 1, a comparison with the RMONCNT value is performed. From among RSECAR/RMINAR/RHRAR/RWKAR/ RDAYAR/RMONAR/RCR3, the counter and alarm register comparison is performed only on those with ENB bits set to 1, and if each of those coincides, an alarm flag of RCR1 is set to 1.

The assignable range is from 01 through 12 + ENB bits (practically in BCD); otherwise an operation error will occur.

|BIt:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||ENB|-|-|10<br>months||1 month|||
|Initial value:|Undefined|0|0|Undefined|Undefined|Undefined|Undefined|Undefined|
|R/W:|R/W|R|R|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|ENB|Undefined|R/W|When this bit is set to 1, a comparison with the RMONCNT value is performed.|
|6, 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|10 months|Undefined|R/W|Ten's position of months setting value|
|3 to 0|1 month|Undefined|R/W|One's position of months setting value|

## 13.3.15 Year Alarm Register (RYRAR)

RYRAR is an alarm register corresponding to the BCD-coded year counter RYRCNT. The assignable range is from 0000 through 9999 (practically in BCD); otherwise an operation error will occur.

|BIt:|15|14|13|12|11|9<br>10|8|7|5<br>6|4|3|1<br>2|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||1000|years|||100 years|||10 years|||1 year||
|Initial value:|Undefined|Undefined|Undefined|Undefined|Undefined|Undefined Undefined|Undefined|Undefined|Undefined Undefined|Undefined|Undefined|Undefined Undefined|Undefined|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W<br>R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|15 to 12|1000 years|Undefined|R/W|Thousand's position of years setting value|
|11 to 8|100 years|Undefined|R/W|Hundred's position of years setting value|
|7 to 4|10 years|Undefined|R/W|Ten's position of years setting value|
|3 to 0|1 year|Undefined|R/W|One's position of years setting value|

## 13.3.16 Control Register 1 (RCR1)

RCR1 is a register that affects carry flags and alarm flags. It also selects whether to generate interrupts for each flag. The CF flag remains undefined until the divider circuit is reset (the RESET and ADJ bits in RCR2 are set to 1). When using the CF flag, make sure to reset the divider circuit beforehand.

The AF flag remains undefined until the value is set to an alarm register and a counter. When using the AF flag, make sure to set the alarm register and counter beforehand.

||||BIt:|7|0<br>1<br>2<br>3<br>4<br>5<br>6||
|---|---|---|---|---|---|---|
|||||CF|-<br>-<br>CIE<br>AIE<br>-<br>-<br>AF||
|||Initial|value:|Undefined|0<br>0<br>0<br>0<br>0<br>0<br>Undefined||
||||R/W:|R/W|R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W||
|||**Initial**|||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||
|7|CF|Undefined|R/W||Carry Flag||
||||||Status flag that indicates that a carry has occurred. CF is set to 1 when a second||
||||||counter carry is generated or a 64-Hz counter carry is generated while reading||
||||||the 64-Hz counter A value read from the count register at this time cannot be||
||||||guaranteed; another read is required.||
||||||0: No carry of second counter or no carry of 64-Hz counter while reading 64-Hz||
||||||counter||
||||||[Clearing condition]||
||||||When 0 is written to CF||
||||||1: Carry of second counter or carry of 64-Hz counter while reading 64-Hz||
||||||counter||
||||||[Setting condition]||
||||||When a second counter carry is generated or a 64-Hz counter carry is||
||||||generated while reading the 64-Hz counter, or 1 is written to CF||
|6, 5|—|All 0|R||Reserved||
||||||These bits are always read as 0. The write value should always be 0.||
|4|CIE|0|R/W||Carry Interrupt Enable Flag||
||||||When the carry flag (CF) is set to 1, the CIE bit enables an interrupt.||
||||||0: A carry interrupt is not generated when the CF flag is set to 1||
||||||1: A carry interrupt is generated when the CF flag is set to 1||
|3|AIE|0|R/W||Alarm Interrupt Enable Flag||
||||||When the alarm flag (AF) is set to 1, the AIE bit enables an interrupt.||
||||||0: An alarm interrupt is not generated when the AF flag is set to 1||
||||||1: An alarm interrupt is generated when the AF flag is set to 1||
|2, 1|—|All 0|R||Reserved||
||||||These bits are always read as 0. The write value should always be 0.||
|0|AF|Undefined|R/W||Alarm Flag||
||||||The AF flag is set when the alarm time, which is set by the alarm registers||
||||||(RSECAR, RMINAR, RHRAR, RWKAR, RDAYAR, RMONAR, or RYRAR whose||
||||||ENB bit is set to 1), and counters match.||
||||||0: Alarm registers and counters not match||
||||||[Clearing condition]||
||||||When 0 is written to AF||
||||||1: Alarm registers and counters match*||
||||||[Setting condition]||
||||||When alarm registers (only the registers with ENB bit set to 1) and counters||
||||||match||
||||||Note: * Writing 1 holds previous value.||

## 13.3.17 Control Register 2 (RCR2)

RCR2 is a register for periodic interrupt control, 30-second adjustment, divider circuit RESET, and count control.

RCR2 is initialized by a power-on reset or in deep standby mode. The RTCEN bit is only initialized by a power-on reset using the RES pin.

||||BIt:||7|0<br>1<br>2<br>3<br>4<br>5<br>6||
|---|---|---|---|---|---|---|---|
||||||PEF|PES[2:0]<br>RTCEN<br>ADJ<br>RESET START||
|||Initial|value:||0|1<br>0<br>0<br>1<br>0<br>0<br>0||
||||R/W:||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|PEF|0|R/W|||Periodic Interrupt Flag||
|||||||Indicates that an interrupt is generated with the period designated by the PES2||
|||||||to PES0 bits. When set to 1, PEF generates periodic interrupts.||
|||||||0: Interrupts not generated with the period designated by the bits PES2 to PES0.||
|||||||[Clearing condition]||
|||||||When 0 is written to PEF||
|||||||1: Interrupts generated with the period designated by the PES2 to PES0 bits.||
|||||||[Setting condition]||
|||||||When an interrupt is generated with the period designated by the bits PES0 to||
|||||||PES2 or when 1 is written to the PEF flag||
|6 to 4|PES[2:0]|000|R/W|||Interrupt Enable Flags||
|||||||These bits specify the period of the periodic interrupt.||
|||||||000: No periodic interrupts generated||
|||||||001: Setting prohibited||
|||||||010: Periodic interrupt generated every 1/64 second||
|||||||011: Periodic interrupt generated every 1/16 second||
|||||||100: Periodic interrupt generated every 1/4 second||
|||||||101: Periodic interrupt generated every 1/2 second||
|||||||110: Periodic interrupt generated every 1 second||
|||||||111: Periodic interrupt generated every 2 seconds||
|3|RTCEN|1|R/W|||RTC_X1 Clock Control||
|||||||Controls the function of the RTC_X1 pin.||
|||||||0: Halts the on-chip crystal oscillator/disables the external clock input.||
|||||||1: Runs the on-chip crystal oscillator/enables the external clock input.||
|||||||Note: The on-chip crystal oscillator selected with the RCKSEL[1:0] bits in the||
|||||||RCR5 register runs. This bit must not be set to 1 when the RCKSEL[1:0] bits are||
|||||||set to 01.||
|2|ADJ|0|R/W|||30-Second Adjustment||
|||||||When 1 is written to the ADJ bit, times of 29 seconds or less will be rounded||
|||||||down to 00 seconds and 30 seconds or more up to 1 minute. The divider circuit||
|||||||(prescaler and R64CNT) will be simultaneously reset. The ADJ bit is||
|||||||automatically reset to 0; there is no need to write 0 to this bit. This bit is always||
|||||||read as 0.||
|||||||0: Normal clock operation||
|||||||1: 30-second adjustment||
|1|RESET|0|R/W|||Reset||
|||||||Writing 1 to this bit initializes the divider circuit, the R64CNT register, the alarm||
|||||||register, the RCR3 register, bits CF and AF in RCR1, and bit PEF in RCR2. In||
|||||||this case, the RESET bit is automatically reset to 0 after 1 is written to and the||
|||||||above registers are reset. Thus, there is no need to write 0 to this bit. This bit is||
|||||||always read as 0.||
|||||||0: Normal clock operation||
|||||||1: Divider circuit is reset.||
|0|START|1|R/W|||Start||
|||||||Halts and restarts the counter (clock).||
|||||||0: Second, minute, hour, day, week, month, and year counters halt.||
|||||||1: Second, minute, hour, day, week, month, and year counters run normally.||

## 13.3.18 Control Register 3 (RCR3)

When the ENB bit is set to 1, RCR3 performs a comparison with the RYRCNT. From among RSECAR/RMINAR/ RHRAR/RWKAR/RDAYAR/RMONAR/RCR3, the counter and alarm register comparison is performed only on those with ENB bits set to 1, and if each of those coincides, an alarm flag of RCR1 is set to 1.

|BIt:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||ENB|-|-|-|-|-|-|-|
|Initial value:|Undefined|0|0|0|0|0|0|0|
|R/W:|R/W|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|ENB|Undefined|R/W|When this bit is set to 1, comparison of the year alarm register (RYRAR) and the|
|||||year counter (RYRCNT) is performed.|
|6 to 0|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|

## 13.3.19 Control Register 5 (RCR5)

When the RCKSEL[1:0] bits in RCR5 are set to 00 and 01, the RTC_X1 clock pulses (32.768 kHz) and the EXTAL clock pulses are used for clock counting, respectively.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|RCKSEL[1:0]||
|Initial value:|0|0|0|0|0|0|Undefined|Undefined|
|R/W:|R|R|R|R|R|R|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7 to 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1, 0|RCKSEL[1:0]|Undefined|R/W|Operation clock select|
|||||Operation clock can be selected from RTC_X1 and EXTAL.|
|||||The setting of these bits should not be switched during operation.|
|||||00: Selects RTC_X1 (32.768 kHz).|
|||||01: Selects EXTAL.|
|||||10: Reserved.|
|||||11: Setting prohibited.|

## 13.3.20 Frequency Register H/L (RFRH/L)

RFRH/L is a 16-bit readable/writable register.

The "frequency comparison value" is set in RFC[18:0] so that a 128-Hz clock is generated when the realtime clock operates at the EXTAL clock frequency.

Change the "frequency comparison value" according to the EXTAL clock frequency. The calculation method is shown below. When the RCKSEL bits in RCR5 are set to 00, setting this register is not necessary.

**==> picture [409 x 98] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit: 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>SEL64 - - - - - - - - - - - - RFC[18:16]<br>Initial value: Undefined 0 0 0 0 0 0 0 0 0 0 0 0 Undefined Undefined Undefined<br>R/W: R/W R R R R R R R R R R R R R/W R/W R/W<br>Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>RFC[15:0]<br>Initial value: Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined Undefined<br>R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W<br>**----- End of picture text -----**<br>

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|||SEL64|Undefined|R/W|64-Hz Divider Select|
|||||||Indicates the EXTAL clock frequency is not dividable by 128 Hz but is dividable|
|||||||by 64 Hz.|
|||||||0: EXTAL clock frequency is dividable by 128 Hz.|
|||||||1: EXTAL clock frequency is not dividable by 128 Hz but is dividable by 64 Hz.|
|30|to|19|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|18|to|0|RFC[18:0]|Undefined|R/W|Frequency comparison value|
|||||||Sets the comparison value to generate operation clock from the EXTAL clock|
|||||||frequency.|

## (1) Method for calculating "frequency comparison value".

- When EXTAL clock frequency is dividable by 128 Hz: 

- RFC[18:0] (EXTAL clock frequency)/128 Clear the SEL64 bit to 0.

- When EXTAL clock frequency is not dividable by 128 Hz but is dividable by 64 Hz: 

- RFC[18:0] (EXTAL clock frequency)/64 Set the SEL64 bit to 1.

## (2) Setting Example

## **Table 13.3 Setting Example**

|**Clock Frequency**|**SEL64 Setting Value**<br>**RFC Setting Value**|
|---|---|
|EXTAL|10 MHz<br>0<br>H’1312D|
||11 MHz<br>1<br>H’29F63|
||12 MHz<br>0<br>H’16E36|
||13 MHz<br>1<br>H’31975|

## 13.4 Operation

A usage example of this module is shown below.

## 13.4.1 Initial Settings of Registers after Power-On and Oscillation Stabilization Time

All the registers should be initialized after the power is turned on. When the RTC_X1 crystal oscillator is used, oscillation stabilization time is necessary after changing the RTCEN bit in RCR2 from 0 to 1. During oscillation stabilization time, various configurations for or operation of the real time clock must not be performed. For details on oscillation stabilization time, refer to section 47, Electrical Characteristics .

## 13.4.2 Setting Time

Figure 13.2 shows how to set the time when the clock is stopped.

**==> picture [302 x 110] intentionally omitted <==**

**----- Start of picture text -----**<br>
Stop clock, Write 0 to START and 1 to RESET in the RCR2 register.<br>select input clock, When EXTAL and RTC_X1 are selected for input clock, set<br>reset divider circuit also RCR5 and RFRH/L.<br>Set seconds, minutes,<br>hour, day, day of the Order is irrelevant<br>week, month, and year<br>Start clock Write 1 to START in the RCR2 register<br>**----- End of picture text -----**<br>

**Figure 13.2 Setting Time**

## 13.4.3 Reading Time

Figure 13.3 shows how to read the time.

**==> picture [248 x 364] intentionally omitted <==**

**----- Start of picture text -----**<br>
Disable the carry interrupt Write 0 to CIE in RCR1<br>Write 0 to CF in RCR1<br>Clear the carry flag (Set AF in RCR1 to 1 so that alarm<br> flag is not cleared.)<br>Read all the counter registers<br> to be read<br>Read RCR1 and check CF bit<br>Yes<br>Carry flag = 1?<br>No<br>(a) To read the time without using interrupts<br>Clear the carry flag<br>Enable the carry interrupt Write 1 to CIE in RCR1<br>Write 0 to CF in RCR1<br>Clear the carry flag (Set AF in RCR1 to 1 so that alarm<br> flag is not cleared.)<br>Read all the counter registers<br> to be read<br>Yes<br>interrupt<br>No<br>Disable the carry interrupt Write 0 to CIE in RCR1<br> (b) To read the time using interrupts<br>**----- End of picture text -----**<br>

**Figure 13.3 Reading Time**

If a carry occurs while reading the time, the correct time will not be obtained, so it must be read again. Part (a) in Figure 13.3 shows the method of reading the time without using interrupts; part (b) in Figure 13.3 shows the method using carry interrupts. To keep programming simple, method (a) should normally be used.

## 13.4.4 Alarm Function

Figure 13.4 shows how to use the alarm function.

**==> picture [249 x 218] intentionally omitted <==**

**----- Start of picture text -----**<br>
Clock running<br>Write 0 to AIE in RCR1<br>Disable alarm interrupt to prevent erroneous interrupt<br>Set alarm time<br>Always reset, since the flag may have been<br>Clear alarm flag<br>set while the alarm time was being set.<br>Enable alarm interrupt Write 1 to AIE in RCR1<br>Monitor alarm time<br>(wait for interrupt or<br>check alarm flag)<br>**----- End of picture text -----**<br>

**Figure 13.4 Using Alarm Function**

Alarms can be generated using seconds, minutes, hours, day of the week, day, month, year, or any combination of these. Set the ENB bit in the register on which the alarm is placed to 1, and then set the alarm time in the lower bits. Clear the ENB bit in the register on which the alarm is not placed to 0.

When the clock and alarm times match, 1 is set in the AF bit in RCR1. Alarm detection can be checked by reading this bit, but normally it is done by interrupt. If 1 is set in the AIE bit in RCR1, an interrupt is generated when an alarm occurs.

The alarm flag is set when the clock and alarm times match. However, the alarm flag can be cleared by writing 0.

## 13.5 Usage Notes

## 13.5.1 Register Writing during Count Operation

The following registers cannot be written to during count operation (while the START bit = 1 in RCR2).

RSECCNT, RMINCNT, RHRCNT, RDAYCNT, RWKCNT, RMONCNT, RYRCONT

Count operation must be stopped before writing to any of the above registers.

## 13.5.2 Use of Realtime Clock Periodic Interrupts

The method of using the periodic interrupt function is shown in Figure 13.5 .

A periodic interrupt can be generated periodically at the interval set by bits PES2 to PES0 in RCR2. When the time set by bits PES2 to PES0 has elapsed, the PEF is set to 1.

The PEF is cleared to 0 upon periodic interrupt generation or when bits PES2 to PES0 are set. Periodic interrupt generation can be confirmed by reading this bit, but normally the interrupt function is used.

**==> picture [196 x 92] intentionally omitted <==**

**----- Start of picture text -----**<br>
Set PES2 to PES0<br>Set PES, clear PEF<br>and clear PEF to 0<br>in RCR2<br>Elapse of time set by PES<br>Clear PEF Clear PEF to 0<br>**----- End of picture text -----**<br>

**Figure 13.5 Using Periodic Interrupt Function**

## 13.5.3 Transition to Standby Mode after Setting Register

When a transition to standby mode is made after registers in this module are set, sometimes counting is not performed correctly. After the registers are set, be sure to perform one dummy read of the registers before making a transition to standby mode.

## 13.5.4 Usage Notes when Writing to and Reading the Register

- After writing to the RCR2 register or any of the counters such as the second counter, dummy-read the register twice before reading the actual value. The register contents before the write are returned by the two dummy reads, and the third read returns the register contents reflecting the write.

- Registers other than the above can be read immediately after a write and the written value is reflected.
