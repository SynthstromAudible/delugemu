# 22. IEBus Controller

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1085–1212. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This module is only incorporated in the RZ/A1L.

IEBus (Inter Equipment Bus) is a small-scale digital data transfer system that transfers data between units. To use IEBus with this LSI, an external IEBus driver and receiver are necessary because they are not provided.

The internal IEBus controller of this LSI is of negative logic.

## 22.1 IEBB Features

**Channels** This microcontroller has the following number of channels of the IEBB.

## **Table 22-1 Channels of IEBB**

|**IEBB**|**IEBB**|
|---|---|
|Number of channels|1|
|Name|IEBB0|

## **Channel index n**

Throughout this chapter, the individual channels of IEBB are identified by the index “n” (n = 0), for example, IEBBnBCR for the IEBBn bus control register.

## **Register addresses**

- All IEBBn register addresses are given as addresses offset from the base address <IEBBn_base>.

The base address <IEBBn_base> of each IEBBn is listed in the following table:

## **Table 22-2 Register base address <IEBBn_base>**

|**IEBBn**|**<IEBBn_base>**|
|---|---|
|IEBB0|FCFEF000|

**Clock supply** The following clock is supplied to the IEBBn:

## **Table 22-3 IEBBn clock supply**

|**IEBBn**|**Clock**|**Connected to:**|
|---|---|---|
|IEBB0|P0|Clock pulse generator|

**Interrupts and DMA** The IEBB can generate the following interrupt requests and DMA requests:

**Table 22-4 IEBBn interrupts and DMA requests**

|**Interrupt request signal**|**Function**|**Direct memory access**<br>**controller activation**|
|---|---|---|
|IEBBTD|Data interrupt request|√|
|IEBBTV|Vector interrupt request|√|
|IEBBTERR|Error interrupt request|—|
|IEBBTSTA|Status interrupt request|—|

**I/O signals** The I/O signals of the IEBB0 are listed in the following table:

## **Table 22-5 IEBBn I/O signals**

|**Pin name**|**Function**|**Input/output**|
|---|---|---|
|IERxD|IEBB0 reception data|Input|
|IETxD|IEBB0 transmission data|Output|

## 22.2 Configuration

## 22.2.1 Function overview

- **Features summary • The data transfer system complies with the IEBus (communication mode 1/ communication mode 2) protocol.**

   - **The IEBus (Inter Equipment Bus) controller is mainly intended to transfer data between automotive devices by using a two-line serial bus interface.**

   - Effective transmission speed: Approximately 18 kbps (communication mode 1), or approximately 27 kbps (communication mode 2)

   - The single mode or FIFO mode can be selected.

   - Maximum number of transferred bytes:

      - 32 bytes/frame (communication mode 1)

128 bytes/frame (communication mode 2)

- To implement IEBus, an external IEBus driver and receiver are necessary. The driver and receiver are not built in.

- This IEBus controller uses negative logic.

- Operation clock: 8 MHz (input P0  = 32 MHz to this module)

- Interrupt request signals

   - Data interrupt (IEBBTD)

For transmission data write processing (single mode, FIFO mode)

For reception data read processing (single mode)

- Error interrupt (IEBBTERR)

For error processing

- Status interrupt (IEBBTSTA)

Start interrupt processing (single mode)

Status transmission interrupt (single mode)

Communication completion interrupt (single mode, FIFO mode) Frame completion interrupt (single mode, FIFO mode)

- Vector interrupt (IEBBTV)

Occurs at the same time as IEBBTERR or IEBBTSTA (single mode)

For reception data read processing (FIFO mode)

- Pin configuration

   - IERxD: IEBus reception data input signal

   - IETxD: IEBus transmission data output signal

## 22.2.2 Block diagram

**==> picture [455 x 424] intentionally omitted <==**

**----- Start of picture text -----**<br>
IE bus controller (IEBB)<br>Core block<br>Register block<br>Field controller<br>IEBBTD<br>IEBBnBCR Interrupt IEBBTV<br>IEBBnPSR Internal bus control<br>IEBBnUAR block IEBBTERR<br>IEBBnSAR Bit controller IEBBTSTA<br>IEBBnISR<br>IEBBnCDR<br>IEBBnTCD<br>IEBBnDLR<br>IEBBnTDL Transmission<br>IETxD<br>IEBBnCKS shift register<br>IEBBnTMS<br>IEBBnDR<br>IEBBnPCR<br>32-byte<br>IEBBnESR transmission<br>IEBBnRCD FIFO buffer<br>IEBBnRDL<br>IEBBnBSR<br>IEBBnSSR<br>Reception<br>IEBBnUSR shift register Noise filter IERxD<br>IEBBnFSR<br>IEBBnSCR<br>IEBBnCCR<br>IEBBnPAR<br>IEBBnRSA 32-byte<br>reception<br>IEBBnSTC0 FIFO buffer<br>IEBBnSTC1<br>Operation clock<br>Baud rate<br>Prescaler<br>generator<br>P0φ<br>block<br>Transmission<br>Peripheral bus<br>Receptionblock<br>**----- End of picture text -----**<br>

**Figure 22-1 IEBBn block diagram**

## 22.3 Registers

## 22.3.1 IEBBn register overview

The IEBBn is controlled by the following registers:

## **Table 22-6 IEBBn registers**

|**Register name**|**Symbol**|**Address**|
|---|---|---|
|IEBBn bus control register|IEBBnBCR|<IEBBn_base> + 0000H|
|IEBBn power save register|IEBBnPSR|<IEBBn_base> + 0004H|
|IEBBn unit address register|IEBBnUAR|<IEBBn_base> + 0008H|
|IEBBn slave address register|IEBBnSAR|<IEBBn_base> + 000CH|
|IEBBn partner address register|IEBBnPAR|<IEBBn_base> + 0010H|
|IEBBn reception slave address<br>register|IEBBnRSA|<IEBBn_base> + 0014H|
|IEBBn control data register|IEBBnCDR|<IEBBn_base> + 0018H|
|IEBBn transmission control data<br>register|IEBBnTCD|<IEBBn_base> + 001CH|
|IEBBn reception control data<br>register|IEBBnRCD|<IEBBn_base> + 0020H|
|IEBBn message length register|IEBBnDLR|<IEBBn_base> + 0024H|
|IEBBn transmission message<br>length register|IEBBnTDL|<IEBBn_base> + 0028H|
|IEBBn reception message<br>length register|IEBBnRDL|<IEBBn_base> + 002CH|
|IEBBn clock selection register|IEBBnCKS|<IEBBn_base> + 0030H|
|IEBBn transfer mode setting<br>register|IEBBnTMS|<IEBBn_base> + 0034H|
|IEBBn pointer clear register|IEBBnPCR|<IEBBn_base> + 0038H|
|IEBBn buffer status register|IEBBnBSR|<IEBBn_base> + 003CH|
|IEBBn slave status register|IEBBnSSR|<IEBBn_base> + 0040H|
|IEBBn unit status register|IEBBnUSR|<IEBBn_base> + 0044H|
|IEBBn interrupt status register|IEBBnISR|<IEBBn_base> + 0048H|
|IEBBn error status register|IEBBnESR|<IEBBn_base> + 004CH|
|IEBBn field status register|IEBBnFSR|<IEBBn_base> + 0050H|
|IEBBn success count register|IEBBnSCR|<IEBBn_base> + 0054H|
|IEBBn communication count<br>register|IEBBnCCR|<IEBBn_base> + 0058H|
|IEBBn status clear register 0|IEBBnSTC0|<IEBBn_base> + 005CH|
|IEBBn status clear register 1|IEBBnSTC1|<IEBBn_base> + 0060H|
|IEBBn data register|IEBBnDR|<IEBBn_base> + 0064H|

**<IEBBn_base>** The IEBBn base address <IEBBn_base> is defined in Table 22-2 .

## 22.3.2 IEBBn control register details

- (1) IEBBnBCR - IEBBn bus control register

The IEBBnBCR register is used to control the operation of IEBBn.

**Access** This register can be read or written in 8-bit units.

**Address** <IEBBn_base> + 0000H

**Initial value** 00H

The IEBBnMSRQ, IEBBnALRQ, IEBBnSTXE, and IEBBnSRXE bits are reset by writing 0 to the IEBBnPW bit.

- Cautions 1. When operation is enabled (when the IEBBnPW bit = 1), writing 1 to the IEBBnMSRQ bit is prohibited while the IEBBnMSRQ bit = 1. To write 1 to this bit, first clear it to 0.

   2. Note the following when accessing the register:

      - When the IEBBnPW bit = 0, it is not possible to write to the IEBBnMSRQ, IEBBnALRQ, IEBBnSTXE, and IEBBnSRXE bits.

      - Because the IEBBnMSRQ, IEBBnALRQ, IEBBnSTXE, and IEBBnSRXE bits are reset at the same time by writing 0 to the IEBBnPW bit, even if an 8-bit write that results in the IEBBnPW bit being cleared to 0 is performed, the IEBBnMSRQ, IEBBnALRQ, IEBBnSTXE, and IEBBnSRXE bits are not written to. When an 8-bit write that results in the IEBBnPW bit being set to 1 is performed, the IEBBnMSRQ, IEBBnALRQ, IEBBnSTXE, and IEBBnSRXE bits can be written to.

Example: If 78H is written to the IEBBnBCR register and then the register is read, 00H is returned.

If F8H is written to the IEBBnBCR register and then the register is read, F8H is returned.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|IEBBn<br>PW|IEBBn<br>MSRQ|IEBBn<br>ALRQ|IEBBn<br>STXE|IEBBn<br>SRXE|0|0|0|
|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R||||||||

**Table 22-7 IEBBnBCR register contents**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|7|IEBBnPW|Communication enable flag<br>0: Stop IEBBn unit operation.<br>1: Enable IEBBn unit operation.<br>Caution<br>When the IEBBnPW bit is set (to 1), the IEBBnPSR, IEBBnUAR,<br>IEBBnCKS, and IEBBnTMS registers below cannot be overwritten.<br>Therefore, these registers must be set up before setting the IEBBnPW bit.|
|6|IEBBnMSRQ|Master request flag<br>0: Do not request the IEBBn unit as the master.<br>1: Request the IEBBn unit as the master.|
|5|IEBBnALRQ|Broadcast request flag<br>0: Request individual communication.<br>1: Request broadcast communication.|
|4|IEBBnSTXE|Slave transmission enable flag<br>0: Disable slave transmission.<br>1: Enable slave transmission.|
|3|IEBBnSRXE|Slave reception enable flag<br>0: Disable slave reception.<br>1: Enable slave reception.|

- (a) Communication enable flag (IEBBnPW): Bit 7

   - Set/clear condition

Set: By software (Write 1 to the IEBBnPW bit.) Clear: By software (Write 0 to the IEBBnPW bit.)

Depending on when the IEBBnPW bit is set (to 1), the IEBBn communication participation method differs.

**Table 22-8 IEBBnPW bit setting timing and communication participation method**

|**Timing for setting the IEBBnPW bit (to 1)**|**IEBBn communication participation method**|
|---|---|
|When communication is not being<br>performed on IEBus|Communication is participated in starting at the next frame or<br>communication is started.|
|When communication is being performed on<br>IEBus, and start bit communication is being<br>performed by another bus master|Participates in communication from that frame if the start bit is<br>detected. If the start bit is not detected, participates in<br>communication from the next frame.|
|When communication is being performed on<br>IEBus, and post-start bit communication is<br>being performed by another bus master|Participates in communication from the next frame.|

If the IEBBnPW bit is cleared (to 0), communication is immediately stopped even if it is in progress, and the internal flags and registers are reset, with some exceptions. The registers that are not reset by the IEBBnPW bit are shown below.

When the IEBBnPW = 0, even if another unit starts communication, IEBBn does not respond.

**Table 22-9 Registers that are not reset by the IEBBnPW bit**

|**Registers that are not reset by the IEBBnPW bit**|**Remark**|
|---|---|
|IEBBnPSR|Not reset|
|IEBBnUAR|Not reset|
|IEBBnSAR|Not reset|
|IEBBnCDR|Data written from the CPU is not reset but data<br>received during communication is.|
|IEBBnTCD|Not reset|
|IEBBnDLR|Data written from the CPU is not reset but data<br>received during communication is.|
|IEBBnTDL|Not reset|
|IEBBnCKS|Not reset|
|IEBBnTMS|Not reset|
|IEBBnPCR|Not reset|
|IEBBnSTC0|Not reset|
|IEBBnSTC1|Not reset|
|IEBBnDR|Data written from the CPU is not reset but data<br>received during communication is.|

(b) Master request flag (IEBBnMSRQ): Bit 6

- Set/clear condition

Set: By software Clear:

– Single mode:

The flag is cleared (to 0) by hardware when master communication is started and when the start interrupt of the master occurs.

The flag is cleared (to 0) by hardware when a communication error interrupt occurs (when the IEBBnISR.IEBBnIEBE bit = 1).

The flag is cleared (to 0) by hardware when arbitration loss occurs.

The flag is cleared (to 0) when the IEBBnPW bit is cleared.

- FIFO mode:

The flag is cleared (to 0) by hardware after master communication starts, communication is performed without arbitration loss occurring, and the parity bit of the slave address field output by the unit is transmitted.

The flag is cleared (to 0) by hardware when a communication error interrupt occurs (when the IEBBnISR.IEBBnIEBE bit = 1).

The flag is cleared (to 0) by hardware if arbitration losses consecutively occur the number of times specified by the IEBBnTMS.IEBBnALC2 to IEBBnALC0 bits.

The flag is cleared (to 0) when the IEBBnPW bit is cleared.

When the IEBBnMSRQ bit is set (to 1), the IEBus controller starts communication on IEBus as the master.

If communication is in progress on IEBus (if the start bit cannot be detected while the start bit is being communicated or if communication is in progress after the start bit has been detected), however, the controller waits until the current frame ends (holds the master request pending), outputs the start bit after the frame has ended, and starts communication as the master.

- Cautions 1. Only set the IEBBnMSRQ bit after clearing the IEBBnSTXE bit to 0. After setting the IEBBnSTXE bit to 1, if arbitration loss occurs and the slave is selected, the transmission data prepared for the master might be used as slave transmission data.

   2. Reissue master requests in the single mode and FIFO mode as described below.

      - Single mode: When arbitration is lost, use software to reissue master requests.

      - FIFO mode:

When arbitration is lost, use hardware to reissue master requests.

However, if arbitration losses consecutively occur the number of times specified by the IEBBnTMS.IEBBnALC2 to IEBBnALC0 bits, the request must be reissued by using software.

- (c) Broadcast request flag (IEBBnALRQ): Bit 5

   - Set/clear condition

Set: By software Clear: By software

- Cautions 1. The IEBBnMSRQ bit is cleared (to 0) by hardware, but the IEBBnALRQ bit is not. Therefore, if the next master request is for individual communication, clear the IEBBnALRQ bit (to 0).

      2. Be sure to change the value of the IEBBnALRQ bit before setting the IEBBnMSRQ bit (to 1).

   - (d) Slave transmission enable flag (IEBBnSTXE): Bit 4

      - Set/clear condition

Set: By software

Clear: By software

Slave transmission is controlled by the value of the slave transmission enable flag, but whether IEBBn performs slave transmission (whether there is an ACK signal response for the control field) is determined by other conditions.

The ACK signal response conditions for the control field are shown below.

## **Table 22-10 Control field ACK signal response conditions (when the received control data is 0H, 3H, 4H, 5H, 6H, or 7H)**

|**Communication target**<br>(**IEBBnUSR.**<br>**IEBBnSRQF bit)**<br>**Slave specification = 1**<br>**No specification = 0**|**Lock status**<br>**(IEBBnUSR.**<br>**IEBBnLCKF**<br>**bit)**<br>**Lock = 1**<br>**No lock = 0**|**Master unit**<br>**judgment**<br>**(IEBBnPAR**<br>**register**<br>**match)**<br>**Lock request**<br>**unit = 1**<br>**Other = 0**|**Slave**<br>**transmission**<br>**enabled**<br>**(IEBBnBCR.**<br>**IEBBnSTXE**<br>**bit)**|**Slave**<br>**reception**<br>**enabled**<br>**(IEBBnBCR.**<br>**IEBBnSRXE**<br>**bit)**|**Received Control Data**|**Received Control Data**|**Received Control Data**|**Received Control Data**|**Received Control Data**|**Received Control Data**|
|---|---|---|---|---|---|---|---|---|---|---|
||||||**0H**|**3H**|**4H**|**5H**|**6H**|**7H**|
|1|0|don’t care|0|don’t care|A|N|N|N|A|N|
||||1||A|A|N|N|A|A|
||1|0|don’t care||A|N|A|A|N|N|
|||1|0||A|N|A|A|A|N|
||||1||A|A|A|A|A|A|
||Other than the above||||N||||||

Note A: Slave transmission is performed. (The ACK signal is returned.)

- N: Slave transmission is not performed. (The NACK signal is returned.)

Slave transmission is not performed if the received control data is AH, BH, EH, or FH.

## **Table 22-11 Control field ACK signal response conditions (when the received control data is AH, BH, EH, or FH)**

|**Communication target**<br>**(IEBBnUSR.**<br>**IEBBnSRQF bit)**<br>**Slave specification = 1**<br>**No specification = 0**|**Lock status**<br>**(IEBBnUSR.**<br>**IEBBnLCKF**<br>**bit)**<br>**Lock = 1**<br>**No lock = 0**|**Master unit judgment**<br>**(IEBBnPAR register**<br>**match)**<br>**Lock request unit = 1**<br>**Other = 0**|**Slave**<br>**transmission**<br>**enabled**<br>**(IEBBnBCR.**<br>**IEBBnSTXE**<br>**bit)**|**Slave**<br>**reception**<br>**enabled**<br>**(IEBBnBCR.**<br>**IEBBnSRXE**<br>**bit)**|**Received control data**|**Received control data**|**Received control data**|**Received control data**|
|---|---|---|---|---|---|---|---|---|
||||||**AH**|**BH**|**EH**|**FH**|
|1|0|don’t care|don’t care|1|A||||
||1|1|||||||
||Other than the above||||N||||

Note A: The ACK signal is returned.

N: The NACK signal is returned.

- Cautions 1. Set the IEBBnSTXE bit before the control field parity bit is received.

   2. When there is a master request, clear the IEBBnSTXE bit (to 0) before setting the IEBBnMSRQ bit (to 1). This is to avoid transmission of the data of the IEBBnDR register that tries master transmission if the controller loses arbitration after master operation and if slave transmission is requested by the master.

- (e) Slave reception enable flag (IEBBnSRXE): Bit 3

• Set/clear condition Set: By software Clear: By software

When the IEBBnSRXE bit = 1 and the reception control data for the communicated control field addressed to the unit is AH, BH, EH, or FH (or when the lock status is specified and the master unit address of the communication matches the address for which a lock was requested), the ACK signal is returned for the control field, and a slave reception operation is performed.

When the IEBBnSRXE bit = 0 and the reception control data for the communicated control field addressed to the unit is AH, BH, EH, or FH, the NACK signal is returned for the control field, and no slave reception operation is performed.

- Cautions 1. Set the IEBBnSRXE bit before the control field parity bit is received.

   2. The IEBBnSRXE bit is used to enable or disable slave reception for both individual and broadcast communication. For individual communication, a NACK signal can be returned for the control field to end communication by clearing the IEBBnSRXE bit to 0 (thereby prohibiting slave reception), but, for broadcast communication, although communication cannot be ended by clearing this bit because no ACK/NACK signal is transmitted, no data interrupt occurs because IEBBn does not respond to the broadcast communication.

- (2) IEBBnPSR - IEBBn power save register

The IEBBnPSR register is used to operate and stop the IEBBn operation clock and to control the communication mode.

**Access** This register can be read or written in 8-bit units.

**Address** <IEBBn_base> + 0004H

**Initial value** 00H

- Cautions 1. The IEBBnPSR register can only be set up when the IEBBnBCR.IEBBnPW bit = 0. Do not set up the register when this bit = 1. If an attempt is made to set up the register when the IEBBnPW bit = 1, the value is ignored.

   2. To use IEBBn, first set the IEBBnCLKE bit (to 1) and enable the operation clock.

To start the bus operation, specify the settings below.

- When communication has started

1. Set up the IEBBnCKS register.

2. Set the IEBBnCLKE bit (to 1). (The operation clock operates.)

   - Set the IEBBnCMD bit to 0 or 1 to specify the communication mode.

3. Set up registers such as IEBBnUAR, IEBBnSAR, IEBn0TCD, IEBBnTDL, and IEBBnDR depending on the type of communication.

4. Set the IEBBnBCR.IEBBnPW bit (to 1) to start communication.

- When communication is stopped

1. Clear the IEBBnPW bit to 0.

2. Clear the IEBBnCLKE bit (to 0). (The operation clock stops.)

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|IEBBn<br>CLKE|IEBBn<br>CMD|0|0|0|0|0|0|
|R/W<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R||||||||

**Table 22-12 IEBBnPSR register contents**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|7|IEBBnCLKE|Operation clock enable flag<br>0: Stop the operation clock. (This makes it possible to reduce the power<br>consumed by IEBBn.)<br>Initialize the prescaler and baud rate generator.<br>1: Enable the operation clock.<br>The operation clock starts operating one clock cycle after the IEBBnCLKE bit is set<br>(to 1). (For details, see Figure 22-2.)<br>Similarly, the operation clock stops operating one clock cycle after the IEBBnCLKE<br>bit is cleared (to 0). (For details, see Figure 22-2.)|
|6|IEBBnCMD|IEBBn communication mode setting flag<br>0: Specify communication mode 1.<br>1: Specify communication mode 2.|

**==> picture [455 x 117] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>IEBBnCLKE bit<br>Operation clock<br>**----- End of picture text -----**<br>

**Figure 22-2 Starting and stopping the operation clock**

(3) IEBBnUAR - IEBBn unit address register

The IEBBnUAR register is used to specify the unit address of the IEBus unit.

This register must always be set before starting communication. Specify the unit address (12 bits) for bits 11 to 0.

**Access** This register can be read or written in 16-bit units. **Address** <IEBBn_base> + 0008H

**Initial value** 0000H

Cautions 1. The IEBBnUAR register can only be set up when the IEBBnBCR.IEBBnPW bit = 0. Do not set up the register when this bit = 1. If an attempt is made to set up the register when the IEBBnPW bit = 1, the value is ignored.

2. Writing to this register in 8-bit units is prohibited.

|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|
|---|---|---|---|---|---|---|---|
|0|0|0|0|||||
|R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||||||||
|||||||||
|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||||||||

- (4) IEBBnSAR - IEBBn slave address register

The IEBBnSAR register is used to specify the address of the communication-partner slave unit during master communication.

During a master request, the value of this register is transmitted as the slave address field data.

Specify the slave address (12 bits) for bits 11 to 0.

**Access** This register can be read or written in 16-bit units.

**Address** <IEBBn_base> + 000CH

**Initial value** 0000H

- Cautions 1. When the IEBBnSAR register is overwritten during communication (while the IEBBnBCR.IEBBnPW bit = 1), communication might not be correctly performed. Therefore, overwriting is prohibited from when a master request is issued until the communication or frame completion timing. Note that overwriting is enabled at the following times:

      - When the IEBBnPW bit = 0

      - From when the IEBBnPW bit is set to 1 until the first master request (when the IEBBnMSRQ bit = 1)

      - From the communication or frame completion timing (assuming the IEBBnPW bit = 1 and the IEBBnMSRQ bit = 0) until the next master request (when the IEBBnMSRQ bit = 1)

   2. Writing to this register in 8-bit units is prohibited.

|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|
|---|---|---|---|---|---|---|---|
|0|0|0|0|||||
|R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||||||||
|||||||||
|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||||||||

- (5) IEBBnPAR - IEBBn partner address register

The IEBBnPAR register is used to store the reception master address in the master address field.

When operating the unit is enabled (when the IEBBnBCR.IEBBnPW bit = 1), the received master address is stored using the master address field regardless of whether the unit master is operating or the slave is operating.

- Storage in the single mode

Upon completion of the parity period for the master address field, this is only performed if the parity value is normal and the unit is in the non-lock status.

- Storage in the FIFO mode

If reading the data received during the previous communication has finished (if the IEBBnBSR.IEBBnRFLF bit = 0 and the IEBBnBSR.IEBBnSRFP4 to

IEBBnSRFP0 bits = 00000), upon completion of the parity period for the master address field, storage is only performed if the parity value is normal and the unit is in the non-lock status. If reading the received data has not finished, the IEBBnPAR register is not updated until it finishes.

When there is a unit lock, because the address of the unit that requested the lock (the lock master) is retained, the IEBBnPAR register is not updated.

- Lock address transmission request reception in the single mode

If a lock address transmission request is received from the master as a status transmission request, when the received control data receives the lock address (higher four bit) read request (5H), the value of the IEBBnPAR register is read by using software, and then the data in bits 15 to 8 of the IEBBnPAR register is written to the IEBBnDR register.

In addition, if a lock address (lower 8 bits) read request (4H) is received, the value of the IEBBnPAR register is read by using software, and then the data in bits 7 to 0 of the IEBBnPAR register is written to the IEBBnDR register.

- Lock address transmission request reception in the FIFO mode

If a lock address transmission request is received from the master as a status transmission request, the data in the IEBBnPAR register is automatically transmitted to the data field by using hardware.

Specify the partner address (12 bits) for bits 11 to 0.

**Access** This register is read-only, in 16-bit units.

**Address** <IEBBn_base> + 0010H

**Initial value** 0000H

This register is reset when the IEBBnBCR.IEBBnPW bit is overwritten.

**==> picture [376 x 83] intentionally omitted <==**

**----- Start of picture text -----**<br>
15 14 13 12 11 10 9 8<br>0 0 0 0<br>R R R R R R R R<br>7 6 5 4 3 2 1 0<br>R R R R R R R R<br>**----- End of picture text -----**<br>

- (6) IEBBnRSA - IEBBn reception slave address register

The IEBBnRSA register is used to store the slave address value received using the slave address field.

When operating the unit is enabled (when the IEBBnBCR.IEBBnPW bit = 1), the received slave address is stored using the slave address field regardless of whether the unit master is operating or the slave is operating.

- Storage in the single mode

This is performed upon the completion of the slave address field parity period if the parity value is normal.

- Storage in the FIFO mode

If reading the data received during the previous communication has finished (if the IEBBnBSR.IEBBnRFLF bit = 0 and the IEBBnBSR.IEBBnSRFP4 to IEBBnSRFP0  bits = 00000), upon completion of the parity period for the slave address field, storage is only performed if the parity value is normal. Until reading the received data finishes, the IEBBnRSA register is not updated.

Specify the slave address (12 bits) for bits 11 to 0.

**Access** This register is read-only, in 16-bit units.

**Address** <IEBBn_base> + 0014H

**Initial value** 0000H

This register is reset when the IEBBnBCR.IEBBnPW bit is overwritten.

|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|
|---|---|---|---|---|---|---|---|
|0|0|0|0|||||
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||||||||
|||||||||
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

- (7) IEBBnCDR - IEBBn control data register

The IEBBnCDR register is used to specify the control data transmitted using the control field.

After writing to the IEBBnCDR register, the IEBBnTCD register is written to.

After reading the IEBBnCDR register, the IEBBnRCD register value is read.

**Access** This register can be read or written in 8-bit units.

**Address** <IEBBn_base> + 0018H

**Initial value** 00H

The read value is reset when the IEBBnBCR.IEBBnPW bit is overwritten.

Caution When issuing a master request, be sure to set up the IEBBnCDR register before starting communication (when the IEBBnBCR.IEBBnMSRQ bit = 0).

Note The IEBBnCDR register consists of a write register and a read register. Therefore, data written to this register cannot be read as is. The data received during IEBus communication can be read.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|0|0|0|0|IEBBn<br>SLCD3|IEBBn<br>SLCD2|IEBBn<br>SLCD1|IEBBn<br>SLCD0|
|R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W||||||||

- (8) IEBBnTCD - IEBBn transmission control data register

The IEBBnTCD register is used to specify the control data transmitted using the control field.

The value of the lower 4 bits of the value written to the IEBBnTCD register is transmitted as control data by using the control field during master transmission.

**Access** This register can be read or written in 8-bit units.

**Address** <IEBBn_base> + 001CH

**Initial value** 00H

- Cautions 1. When issuing a master request, be sure to set up the IEBBnTCD register before starting communication (when the IEBBnBCR.IEBBnMSRQ bit = 0).

   2. Do not specify undefined values.

   3. During broadcast transmission, specifying slave transmission control data is prohibited.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|0|0|0|0|IEBBn<br>SLTD3|IEBBn<br>SLTD2|IEBBn<br>SLTD1|IEBBn<br>SLTD0|
|R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W||||||||

**Table 22-13 IEBBnTCD register contents**

|**Bit position**|**Bit name**|**Function**|
|---|---|---|
|3 to 0|IEBBnSLTD<br>[3-0]|Specify the control data transmitted by using the control field.<br>**IEBBn**<br>**SLTD3**<br>**IEBBn**<br>**SLTD2**<br>**IEBBn**<br>**SLTD1**<br>**IEBBn**<br>**SLTD0**<br>**Function**<br>0<br>0<br>0<br>0<br>Read slave status<br>0<br>0<br>0<br>1<br>Undefined<br>0<br>0<br>1<br>0<br>Undefined<br>0<br>0<br>1<br>1<br>Data reading and locking<br>0<br>1<br>0<br>0<br>Lock address reading (lower 8 bits)<br>0<br>1<br>0<br>1<br>Lock address reading (higher 4 bits)<br>0<br>1<br>1<br>0<br>Slave status reading and unlocking<br>0<br>1<br>1<br>1<br>Read data<br>1<br>0<br>0<br>0<br>Undefined<br>1<br>0<br>0<br>1<br>Undefined<br>1<br>0<br>1<br>0<br>Command writing and locking<br>1<br>0<br>1<br>1<br>Data writing and locking<br>1<br>1<br>0<br>0<br>Undefined<br>1<br>1<br>0<br>1<br>Undefined<br>1<br>1<br>1<br>0<br>Write command<br>1<br>1<br>1<br>1<br>Write data|

- (9) IEBBnRCD - IEBBn reception control data register

The IEBBnRCD register is used to store the control data received using the control field.

The data received by using the control field is read to the lower 4 bits of the IEBBnRCD register. Data is stored in the IEBBnRCD register upon completion of the control field parity period if the parity value is normal.

- Storage in the single mode

When a status transmission request is received, the user performs each process (settings for the transmission data of the IEBBnSSR register or the IEBBnPAR register) according to the value of the lower 4 bits of the IEBBnRCD register read value.

- Storage in the FIFO mode

When a status transmission request is received, the hardware automatically performs the status transmission processing (settings for the transmission data of the IEBBnSSR register or the IEBBnPAR register).

Because it is necessary to judge whether the received data is a command or data, be sure to read the value of this register upon the completion of communication.

In the FIFO mode, if reading the data received during the previous communication has finished (if the IEBBnBSR.IEBBnRFLF bit = 0 and the IEBBnBSR.IEBBnSRFP4SRFP0 bit = 00000), upon completion of the parity period for the control data field, storage is performed if the parity value is normal. Until reading the received data finishes, the IEBBnRCD register is not updated.

**Access** This register is read-only, in 8-bit units.

**Address** <IEBBn_base> + 0020H

## **Initial value** 00H

This register is reset when the IEBBnBCR.IEBBnPW bit is overwritten.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|0|0|0|0|IEBBn<br>SLRD3|IEBBn<br>SLRD2|IEBBn<br>SLRD1|IEBBn<br>SLRD0|
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

**Table 22-14 IEBBnRCD register contents**

|**Bit position**|**Bit name**|**Function**|
|---|---|---|
|3 to 0|IEBBnSLRD<br>[3-0]|Specify the control data received by using the control field.<br>**IEBBn**<br>**SLRD3**<br>**IEBBn**<br>**SLRD2**<br>**IEBBn**<br>**SLRD1**<br>**IEBBn**<br>**SLRD0**<br>**Function**<br>0<br>0<br>0<br>0<br>Read slave status<br>0<br>0<br>0<br>1<br>Undefined<br>0<br>0<br>1<br>0<br>Undefined<br>0<br>0<br>1<br>1<br>Data reading and locking<br>0<br>1<br>0<br>0<br>Lock address reading (lower 8 bits)<br>0<br>1<br>0<br>1<br>Lock address reading (higher 4 bits)<br>0<br>1<br>1<br>0<br>Slave status reading and unlocking<br>0<br>1<br>1<br>1<br>Read data<br>1<br>0<br>0<br>0<br>Undefined<br>1<br>0<br>0<br>1<br>Undefined<br>1<br>0<br>1<br>0<br>Command writing and locking<br>1<br>0<br>1<br>1<br>Data writing and locking<br>1<br>1<br>0<br>0<br>Undefined<br>1<br>1<br>0<br>1<br>Undefined<br>1<br>1<br>1<br>0<br>Write command<br>1<br>1<br>1<br>1<br>Write data|

- (10) IEBBnDLR - IEBBn message length register

The IEBBnDLR register is used to specify the message length data transmitted using the message length field.

After writing to the IEBBnDLR register, the IEBBnTDL register is written to.

After reading the IEBBnDLR register, the IEBBnRDL register value is read.

**Access** This register can be read or written in 8-bit units.

**Address** <IEBBn_base> + 0024H

**Initial value** 01H

The read value is reset when the IEBBnBCR.IEBBnPW bit is overwritten.

Caution When issuing a master request, be sure to set up the IEBBnDLR register before starting communication (when the IEBBnBCR.IEBBnMSRQ bit = 0).

Note The IEBBnDLR register consists of a write register and a read register. Therefore, data written to this register cannot be read as is. The data received during IEBus communication can be read.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|||||||||
|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||||||||

- (11) IEBBnTDL - IEBBn transmission message length register

The IEBBnTDL register is used to specify the message length data transmitted using the message length field.

The value written to the IEBBnTDL register is transmitted as message length data by using the message length field if the unit is the transmission unit (master transmission, slave transmission).

However, when a status transmission request is received, 0H is transmitted as the message length data regardless of the IEBBnTDL register setting.

**Access** This register can be read or written in 8-bit units.

**Address** <IEBBn_base> + 0028H

**Initial value** 01H

- Cautions 1. Be sure to set up the IEBBnTDL register before starting communication (when the IEBBnBCR.IEBBnMSRQ bit = 0).

   2. The maximum number of bytes that can be transferred per frame is determined according to the communication mode. For example, when transferring 48 bytes in communication mode 1, perform communication by dividing the data among multiple frames. In this case, when performing the second communication, use the IEBBnSCR register to check the number of data bytes transmitted during the first communication, subtract the number of bytes that were successfully transmitted from the number of bytes you want to transmit, and then specify the result for the IEBBnTDL register. Write the next data to the IEBBnDR register at the same time, and then issue a master request.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|||||||||
|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||||||||

**Table 22-15 IEBBnTDL register contents**

|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Setting**|**Number of remaining communication**<br>**data bytes**|
|---|---|---|---|---|---|---|---|---|---|
|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|||
|0|0|0|0|0|0|0|1|01H|1 byte|
|0|0|0|0|0|0|1|0|02H|2 bytes|
|...|...|...|...|...|...|...|...|...|...|
|0|0|0|1|0|1|0|0|20H|32 bytes|
|...|...|...|...|...|...|...|...|...|...|
|1|1|1|1|1|1|1|1|FFH|255 bytes|
|0|0|0|0|0|0|0|0|00H|256 bytes|

- (12) IEBBnRDL - IEBBn reception message length register

The IEBBnRDL register is used to specify the message length data received using the message length field.

The IEBBnRDL register read value is the data received using the message length field.

- Storage in the single mode

Storage proceeds if the parity value is normal at the end of the parity period for the message length field.

- Storage in the FIFO mode

If reading the data received during the previous communication has finished (IEBBnBSR.IEBBnRFLF bit = 0 and the IEBBnBSR.IEBBnSRFP4-SRFP0 bit = 00000), upon completion of the parity period for the message length field, storage is performed if the parity value is normal. Until reading the received data finishes, the IEBBnRDL register is not updated.

**Access** This register is read-only, in 8-bit units.

**Address** <IEBBn_base> + 002CH

**Initial value** 01H

This register is reset when the IEBBnBCR.IEBBnPW bit is overwritten.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|||||||||
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

**Table 22-16 IEBBnRDL register contents**

|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Setting**|**Number of remaining communication data**<br>**bytes**|
|---|---|---|---|---|---|---|---|---|---|
|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|||
|0|0|0|0|0|0|0|1|01H|1 byte|
|0|0|0|0|0|0|1|0|02H|2 bytes|
|...|...|...|...|...|...|...|...|...|...|
|0|0|0|1|0|1|0|0|20H|32 bytes|
|...|...|...|...|...|...|...|...|...|...|
|1|1|1|1|1|1|1|1|FFH|255 bytes|
|0|0|0|0|0|0|0|0|00H|256 bytes|

(13) IEBBnCKS - IEBBn clock selection register

The IEBBnCKS register is used to control the clock selection of the IEBus controller.

**Access** This register can be read or written in 8-bit units. **Address** <IEBBn_base> + 0030H

**Initial value** 17H

Caution The IEBBnCKS register can only be set up when the IEBBnBCR.IEBBnPW bit = 0 and the IEBBnPSR.IEBBnCLKE bit = 0. Do not set up the register when this bit = 1. If an attempt is made to set up the register when the IEBBnPW bit = 1, the value is ignored.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|0|0|0|IEBBn<br>PRS|0|IEBBn<br>BRS2|IEBBn<br>BRS1|IEBBn<br>BRS0|
|R<br>R<br>R<br>R/W<br>R<br>R/W<br>R/W<br>R/W||||||||

## **Table 22-17 IEBBnCKS register contents**

|**Bit position**|**Bit name**|**Function**|
|---|---|---|
|4|IEBBnPRS|Specify the prescaler output (PRSOUT).<br>0: P0<br>1: P02<br>Caution<br>The conditions under which the prescaler is initialized are as follows:<br>**•**<br>When the IEBBnPRS bit is overwritten<br>**•**<br>When theIEBBnBCR.IEBBnPW bit = 0 and the<br>IEBBnPSR.IEBBnCLKE bit = 1|
|2 to 0|IEBBnBRS<br>[2-0]|Specify the operation clock output (MCK).<br>**IEBBnBRS2**<br>**IEBBnBRS1**<br>**IEBBnBRS0**<br>**Operation clock output**<br>**(MCK)**<br>0<br>0<br>0<br>PRSOUT/1<br>0<br>0<br>1<br>PRSOUT/1<br>0<br>1<br>0<br>PRSOUT/2<br>0<br>1<br>1<br>PRSOUT/3<br>1<br>0<br>0<br>PRSOUT/4<br>1<br>0<br>1<br>PRSOUT/5<br>1<br>1<br>0<br>PRSOUT/6<br>1<br>1<br>1<br>PRSOUT/7<br>Caution<br>The conditions under which the baud rate generator is initialized are as<br>follows:<br>**•**<br>When the IEBBnBRS2 to IEBBnBRS0 bits are overwritten<br>**•**<br>When the IEBBnBCR.IEBBnPW bit = 0 and the<br>IEBBnPSR.IEBBnCLKE bit = 1|

## **Table 22-18 Input clock specification example**

|**P0**|**IEBBnPRS**|**IEBBnBRS2**|**IEBBnBRS1**|**IEBBnBRS0**|**Specified value**|
|---|---|---|---|---|---|
|32 MHz|0|1|0|0|04H|

Caution The IEBus controller is designed to operate at 8 MHz.

(14) IEBBnTMS - IEBBn transfer mode setting register The IEBBnTMS register is used to control the IEBus controller communication operations.

**Access** This register can be read or written in 8-bit units.

**Address** <IEBBn_base> + 0034H

**Initial value** 01H

Caution The IEBBnTMS register can only be set up when the IEBBnBCR.IEBBnPW bit = 0. Do not set up the register when this bit = 1. If an attempt is made to set up the register when the IEBBnPW bit = 1, the value is ignored.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|IEBBn<br>FMDE|IEBBn<br>SLRI1|IEBBn<br>SLRI0|IEBBn<br>SLTI1|IEBBn<br>SLTI0|IEBBn<br>ALC2|IEBBn<br>ALC1|IEBBn<br>ALC0|
|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||||||||

**Table 22-19 IEBBnTMS register contents (1/2)**

|**Bit position**|**Bit name**|**Function**|
|---|---|---|
|7|IEBBnFMDE|Specify whether to enable or disable FIFO mode operation.<br>0: Disable FIFO mode operation (single mode).<br>1: Enable FIFO mode operation.|
|6, 5|IEBBnSLRI<br>[1, 0]|Specify the IEBBTV occurrence timing during FIFO mode reception.<br>**IEBBnSLRI1**<br>**IEBBnSLRI0**<br>**IEBBTV occurrence timing**<br>0<br>0<br>When the reception data that has not been<br>read from the reception FIFO buffer reaches<br>32 bytes<br>0<br>1<br>When the reception data that has not been<br>read from the reception FIFO buffer reaches<br>24 bytes<br>1<br>0<br>When the reception data that has not been<br>read from the reception FIFO buffer reaches<br>16 bytes<br>1<br>1<br>When the reception data that has not been<br>read from the reception FIFO buffer reaches<br>8 bytes|
|4, 3|IEBBnSLTI<br>[1, 0]|Specify the IEBBTD occurrence timing during FIFO mode transmission.<br>**IEBBnSLTI1**<br>**IEBBnSLTI0**<br>IEBBTD occurrence timing<br>0<br>0<br>When the transmission FIFO buffer becomes<br>empty<br>0<br>1<br>When the untransmitted data remaining in<br>the transmission FIFO buffer reaches 2 bytes<br>1<br>0<br>When the untransmitted data remaining in<br>the transmission FIFO buffer reaches 4 bytes<br>1<br>1<br>When the untransmitted data remaining in<br>the transmission FIFO buffer reaches 8 bytes|

**Table 22-19 IEBBnTMS register contents (2/2)**

|**Bit position**|**Bit name**|**Function**|
|---|---|---|
|2 to 0|IEBBnALC<br>[2-0]|Specify the arbitration loss number.<br>This is only valid in the FIFO mode. The settings of these bits are invalid in the<br>single mode.<br>When arbitration is lost and the counter is set to 0H, the<br>IEBBnBCR.IEBBnMSRQ bit is not retained.<br>The settings of the IEBBnALC2 to IEBBnALC0 bits are always retained. The<br>settings are not changed each time arbitration is lost.<br>The arbitration loss counter is decremented separately from the IEBBnALC2 to<br>IEBBnALC0 bits.<br>Overwriting the IEBBnALC2 to IEBBnALC0 bits while the arbitration loss counter<br>is counting does not affect the counter. (The values of the bits are specified for<br>the arbitration loss counter when the IEBBnMSRQ bit = 1.)<br>**IEBBnALC2**<br>**IEBBnALC1**<br>**IEBBnALC0**<br>**Maximum arbitration loss**<br>**count**<br>0<br>0<br>1<br>1<br>0<br>1<br>1<br>3<br>Other than the above<br>Setting prohibited|

- (a) FIFO operation enable bit (IEBBnFMDE): Bit 7

Differences between operation in the single mode and FIFO mode are shown below.

**Table 22-20 Differences between operation in the single mode and FIFO mode**

|**Transfer**<br>**mode**|**Arbitration loss master**<br>**request flag**<br>**(IEBBnBCR.IEBBnMSRQ)**|**Arbitration loss error**<br>**interrupt signal (IEBBTERR)**|**Support for slave status**<br>**requests and lock address**<br>**requests**|
|---|---|---|---|
|Single<br>mode|Clear|**•**<br>The signal is not output.<br>**•**<br>The IEBBnESR.IEBBnABTE<br>bit is fixed to 0.|During the slave status<br>interrupt servicing, the value of<br>the IEBBnSSR or IEBBnPAR<br>register is written to the<br>IEBBnDR register.|
|FIFO mode|The flag value is retained until<br>arbitration is lost the number of<br>times specified for the<br>IEBBnALC2 to IEBBnALC0<br>bits. (The flag is cleared unless<br>an error occurs during<br>communication between third<br>parties.)|**•**<br>The signal is output if<br>arbitration is lost the<br>specified number of times.<br>**•**<br>The IEBBnESR.IEBBnABTE<br>bit is simultaneously set (to<br>1).|The value of the IEBBnSSR or<br>IEBBnPAR register is<br>automatically sent by hardware<br>by using the data field.|

(b) FIFO mode reception IEBBTV occurrence timing specification bits (IEBBnSLRI1, IEBBnSLRI0): Bits 6, 5

In communication mode 1, the IEBBnSLRI1 and IEBBnSLRI0 bits are cleared to 00.

In communication mode 2, because data that exceeds 32 bytes is received, data must be read during reception. The occurrence timing of the data interrupt (IEBBTV) that requests that received data be read is specified by the IEBBnSLRI1 and IEBBnSLRI0 bits.

The IEBBTV interrupt occurs when received data is stored in the FIFO buffer and the number of unread bytes of data reaches the value specified for the IEBBnSLRI1 and IEBBnSLRI0 bits.

For the data no less than the number of bytes specified for the IEBBnSLRI1 and IEBBnSLRI0 bits, the data is read, and no interrupt occurs even if the number of unread bytes of received data exceeds the value specified for the IEBBnSLRI1 and IEBBnSLRI0 bits.

**==> picture [455 x 134] intentionally omitted <==**

**----- Start of picture text -----**<br>
Communication Data n Data n+1 Data n+2<br>IEBBnBSR.<br>7 8 9 8 7 8<br>IEBBnSRFP4 to IEBBnSRFP0 bits<br>Data Data<br>  read read<br>IEBBTV<br>**----- End of picture text -----**<br>

**Figure 22-3 Example of operation in communication mode 2: When the IEBBnSLRI1 and IEBBnSLRI0 bits = 11**

- (c) FIFO mode transmission IEBBTB occurrence timing specification bits (IEBBnSLTI1, IEBBnSLTI0): Bits 4, 3

In communication mode 1, clear the IEBBnSLTI1 and IEBBnSLTI0 bits to 00.

In communication mode 2, because data that exceeds 32 bytes is transmitted, transmission data must be written during transmission. The occurrence timing of the data interrupt (IEBBTD) that requests that transmission data be written is specified by the IEBBnSLTI1 and IEBBnSLTI0 bits.

When less than 32 bytes of data are written to the FIFO buffer, IEBBTD occurs for the remaining number of bytes of data to be transmitted.

The IEBBTD interrupt occurs when transmission data is transferred from the FIFO buffer to the shift register and the number of bytes of data that have not been transmitted reaches the value specified for the IEBBnSLTI1 and IEBBnSLTI0 bits.

For data less than the number of bytes specified for the IEBBnSLTI1 and IEBBnSLTI0 bits, the data is written, and no interrupt occurs even if the number of bytes of data that have not been transmitted reaches the value specified for the IEBBnSLTI1 and IEBBnSLTI0 bits.

**==> picture [455 x 134] intentionally omitted <==**

**----- Start of picture text -----**<br>
Communication Data n Data n+1 Data n+2<br>IEBBnBSR.<br>3 2 1 2 3 2<br>IEBBnSTFP4-IEBBnSTFP0 bit<br>Data Data<br>  write write<br>IEBBTD<br>**----- End of picture text -----**<br>

**Figure 22-4 Example of operation in communication mode 2: When the IEBBnSLTI1 and IEBBnSLTI0 bits = 01**

- (d) Arbitration loss count specification bits (IEBBnALC2 to IEBBnALC0): Bits 2 to 0

This is only valid in the FIFO mode. The settings of these bits are invalid in the single mode.

When arbitration is lost and the counter is set to 0H, the IEBBnBCR.IEBBnMSRQ bit is not retained.

**==> picture [455 x 209] intentionally omitted <==**

**----- Start of picture text -----**<br>
Communication Frame 1 Frame 2 Frame 3<br>Contention loss Contention loss Contention loss<br>Contention loss counter 3 2 1 0<br>IEBBnBSR.<br>IEBBnMSRQ bit<br>IEBBTERR<br>IEBBnESR.<br>IEBBnABTE bit<br>IEBBnUSR.<br>IEBBnARBF bit<br>**----- End of picture text -----**<br>

**Figure 22-5 Example of operation in the FIFO mode: When the IEBBnALC2 to IEBBnALC0 bits = 011**

(15) IEBBnPCR - IEBBn pointer clear register

The IEBBnPCR register is the trigger bit register for clearing the FIFO buffer pointer.

**Access** This register is write-only, in 8-bit units. **Address** <IEBBn_base> + 0038H

**Initial value** 00H

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|IEBBn<br>CRPT|IEBBn<br>CTPT|0|0|0|0|0|0|
|W<br>W<br>R<br>R<br>R<br>R<br>R<br>R||||||||

**Table 22-21 IEBBnPCR register contents**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|7|IEBBnCRPT|Clear trigger bit for the store pointer and read pointer of the reception FIFO buffer<br>0: No operation<br>1: Clear the store pointer and read pointer of the reception FIFO buffer.<br>The bit value can only be changed by setting the bit (to 1). Attempting to clear the bit<br>(to 0) does not change the bit value.<br>When the bit is read, 0 is always returned.<br>Caution<br>During reception or before reading received data, if the IEBBnCRPT bit is<br>set to 1, the received data cannot be read. Except when discarding<br>received data, only write 1 to the IEBBnCRPT bit after receiving and then<br>reading data.|
|6|IEBBnCTPT|Clear the trigger bit for the write pointer and load pointer of the transmission FIFO<br>buffer<br>0: No operation<br>1: Clear the write pointer and load pointer of the transmission FIFO buffer.<br>The bit value can only be changed by setting the bit (to 1). Attempting to clear the bit<br>(to 0) does not change the bit value.<br>When the bit is read, 0 is always returned.<br>Cautions 1. If the IEBBnCTPT bit = 1 while specifying data for the FIFO buffer or<br>during transmission, the specified data cannot be transmitted. Except<br>when discarding transmission data, only write 1 to the IEBBnCTPT bit<br>after transmitting the data written to the FIFO buffer.<br>2. To discard transmission data, set the IEBBnCTPT bit to 1 during<br>transmission. Because the data is lost in this case, transmission is not<br>performed and an underrun error occurs.|

(16) IEBBnBSR - IEBBn buffer status register

The IEBBnBSR register indicates the FIFO buffer status.

**Access** This register is read only, in 16-bit units. **Address** <IEBBn_base> + 003CH

**Initial value** 0000H

This register is reset when 0 is written to the IEBBnBCR.IEBBnPW bit.

|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|15<br>14<br>13<br>12<br>11<br>10<br>9<br>8|
|---|---|---|---|---|---|---|---|
|IEBBn<br>RFLF|IEBBn<br>FOVR|0|IEBBn<br>SRFP4|IEBBn<br>SRFP3|IEBBn<br>SRFP2|IEBBn<br>SRFP1|IEBBn<br>SRFP0|
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0||||||||
|IEBBn<br>TFLF|IEBBn<br>FOVW|0|IEBBn<br>STFP4|IEBBn<br>STFP3|IEBBn<br>STFP2|IEBBn<br>STFP1|IEBBn<br>STFP0|
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

## **Table 22-22 IEBBnBSR register contents (1/2)**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|15|IEBBnRFLF|Reception FIFO buffer full status flag<br>0: There are 31 bytes of data or less that have not been read in the reception FIFO<br>buffer.<br>1: There are 32 bytes of data that have not been read in the reception FIFO buffer.<br>This flag indicates that there are 32 bytes of data that have not been read in the<br>reception FIFO buffer and that the buffer is full.|
|14|IEBBnFOVR|This flag indicates whether reception FIFO buffer over-reading has occurred.<br>0: Reception FIFO buffer over-reading has not occurred.<br>1: Reception FIFO buffer over-reading has occurred.|
|12 to 8|IEBBnSRFP<br>[4-0]|This flag indicates the number of data bytes that have not been read remaining in the<br>reception FIFO buffer.<br>The (store pointer - read pointer) value can be read.<br>However, the following values are used when IEBBnSRFP4 to IEBBnSRFP0 =<br>00000.<br>**•**<br>When the IEBBnRFLF bit = 0 and the IEBBnSRFP4 to IEBBnSRFP0 bits = 00000<br>Number of remaining data bytes that have not been read = 0 bytes<br>**•**<br>When the IEBBnRFLF bit = 1, and the  IEBBnSRFP4 to IEBBnSRFP0 bits =<br>00000<br>Number of remaining data bytes that have not been read = 32 bytes|
|7|IEBBnTFLF|Transmission FIFO buffer full status flag<br>0: There are 31 bytes of data or less that have not been transferred in the<br>transmission FIFO buffer.<br>1: There are 32 bytes of data that have not been transferred in the transmission<br>FIFO buffer.<br>This flag indicates that there are 32 bytes of data that have not been transferred in<br>the transmission FIFO buffer and that the buffer is full.|
|6|IEBBnFOVW|Transmission FIFO buffer overwrite flag<br>0: No transmission FIFO buffer overwrite has occurred.<br>1: A transmission FIFO buffer overwrite has occurred.|

**Table 22-22 IEBBnBSR register contents (2/2)**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|4 to 0|IEBBnSTFP<br>[4-0]|This flag indicates the number of data bytes that have not been transferred remaining<br>in the transmission FIFO buffer.<br>The (write pointer - load pointer) value can be read.<br>However, the following values are used when the IEBBnSTFP4 to STFPSTFP0 bits =<br>00000.<br>**•**<br>When the IEBBnTFLF bit = 0 and the IEBBnSTFP4 to IEBBnSTFP0 bits = 00000<br>Number of remaining data bytes that have not been transferred = 0 bytes<br>**•**<br>When the IEBBnTFLF bit = 1 and the IEBBnSTFP4 to IEBBnSTFP0 bits = 00000<br>Number of remaining data bytes that have not been transferred = 32 bytes|

- (a) Reception FIFO buffer over-read indicating flag (IEBBnFOVR): Bit 14

   - Set/clear condition

Set:

- Single mode:

The IEBBnFOVR bit is not set (to 1).

- FIFO mode:

When an over-read (a read of the IEBBnDR register while the store pointer = the read pointer) occurs for the reception FIFO buffer

Clear:

- Single mode or FIFO mode:

By software (The flag is cleared when 1 is written to the IEBBnPCR.IEBBnCRPT bit.)

After reading the reception FIFO buffer, detect whether an over-read occurred by reading the IEBBnFOVR bit. (The data read during the over-read is the last bytes read during multiple operations.)

Even if an over-read is detected, because the data cannot be read again, perform software processing such as requesting retransmission. The IEBBnFOVR bit is cleared by writing 1 to the IEBBnPCR.IEBBnCRPT bit. (If an over-read occurred, the FIFO buffer pointers have already been cleared.)

- (b) Transmission FIFO buffer overwrite flag (IEBBnFOVW): Bit 6

   - Set/clear condition

Set:

- Single mode:

The IEBBnFOVW bit is not set (to 1).

- FIFO mode:

When there are 32 bytes of that have not been transmitted in the transmission FIFO buffer and a 33rd byte of data is written

Clear:

- Single mode or FIFO mode:

By software (The flag is cleared when 1 is written to the IEBBnPCR.IEBBnCTPT bit.)

After writing the required data to the transmission FIFO buffer, read the IEBBnFOVW bit before setting the master request flag. (IEBBnBCR.IEBBnMSRQ) (to 1) to detect whether an overwrite has occurred. If an overwrite is detected, clear the FIFO buffer pointers by writing 1 to the IEBBnPCR.IEBBnCTPT bit and then specify the data again.

(17) IEBBnSSR - IEBBn slave status register

The IEBBnSSR register indicates the communication status of the slave unit.

When a slave status transmission request interrupt is received form the master and the received control data is 0H or 6H, the IEBBnSSR register value is automatically written to the IEBBnDR register, and the slave status is transmitted.

In addition, when transmitting the slave status, because 01H is automatically transmitted as the message length, the IEBBnTDL register does not have to be set up.

Because bits 7 and 6 indicate the highest mode supported by the unit, they are fixed to 10 (which indicates communication mode 2).

**Access** This register is read-only, in 8-bit units.

**Address** <IEBBn_base> + 0040H

**Initial value** 81H

The IEBBnSSLF and IEBBnSTLF bits are reset by writing 0 to the IEBBnBCR.IEBBnPW bit.

The IEBBnSRXF and IEBBnSTXF bits are reset when the value of the IEBBnPW bit is overwritten with a different value.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|1|0|0|IEBBn<br>SSLF|0|IEBBn<br>STLF|IEBBn<br>SRXF|IEBBn<br>STXF|
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

## **Table 22-23 IEBBnSSR register contents (1/2)**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|4|IEBBnSSLF|Slave transmission status flag<br>0: Slave transmission is stopped.<br>1: Slave transmission is enabled.|
|2|IEBBnSTLF|Lock status flag<br>0: Unlocked<br>1: Locked|
|1|IEBBnSRXF|IEBBnDR register or FIFO buffer reception status flag<br>In the single mode<br>0: Received data has not been stored in the IEBBnDR register.<br>1: Received data has been stored in the IEBBnDR register.<br>In the FIFO mode<br>0: Received data has not been stored in the FIFO buffer.<br>1: Received data has been stored in the FIFO buffer.|

**Table 22-23 IEBBnSSR register contents (2/2)**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|0|IEBBnSTXF|IEBBnDR register or FIFO buffer transmission status flag<br>**•**<br>When communication is not being performed<br>1: The flag is always this value.<br>**•**<br>Master<br>In the single mode (transmission)<br>0: The data specified for the IEBBnDR register has been transferred to the<br>transmission shift register, and the next transmission data has not been written<br>to the IEBBnDR register.<br>1: Transmission data remains in the IEBBnDR register. (This is the status up until<br>the contents of the IEBBnDR register are transferred to the transmission shift<br>register.)<br>In the single mode (reception)<br>1: The flag is always this value.<br>In the FIFO mode (transmission)<br>0: The number of bytes of data written to the FIFO buffer have been transferred<br>from the FIFO buffer to the transmission shift register, and the next transfer<br>data has not been written to the FIFO buffer.<br>1: This is the status from when communication starts until data is transferred to<br>the transmission shift register and the number of bytes of data written to the<br>FIFO buffer disappear.<br>In the FIFO mode (reception)<br>1: The flag is always this value.<br>**•**<br>Slave<br>In the single mode (transmission)<br>0: The data specified for the IEBBnDR register has been transferred to the<br>transmission shift register, and the next transmission data has not been written<br>to the IEBBnDR register.<br>1: This is the status from when communication starts until the first transmission<br>data is transferred from the IEBBnDR register to the transmission shift register.<br>This is also the status after writing data to the IEBBnDR register until the data<br>is transferred to the transmission shift register.<br>In the single mode (reception)<br>1: The flag is always this value.<br>In the FIFO mode (transmission)<br>0: The number of bytes of data written to the FIFO buffer have been transferred<br>from the FIFO buffer to the transmission shift register, and the next transfer<br>data has not been written to the FIFO buffer.<br>1: This is the status from when communication starts until data is transferred to<br>the transmission shift register and the number of bytes of data written to the<br>FIFO buffer disappear.<br>In the FIFO mode (reception)<br>1: The flag is always this value.<br>**•**<br>Third party<br>1: The flag is always this value.|

- (a) Slave transmission status flag (IEBBnSSLF): Bit 4

The value of the slave transmission enable flag (the IEBBnBCR.IEBBnSTXE bit) is applied as is.

- (b) Lock status flag (IEBBnSTLF): Bit 2

The value of the lock status flag (the IEBBnUSR.IEBBnLCKF bit) is applied as is.

- (c) IEBBnDR register or FIFO buffer reception status flag (IEBBnSRXF): Bit 1

   - Set/clear condition

Set:

- Single mode:

When received data is stored in the IEBBnDR register

- FIFO mode:

When received data is stored in the FIFO buffer

Clear:

- Single mode:

When the IEBBnDR register contents are read

- FIFO mode:

When all the received data stored in the FIFO buffer has been read

In the single mode, when the IEBBnSRXF bit is set (to 1), the data interrupt IEBBTD occurs.

In the single mode, when IEBBTD occurs on data reception, the IEBBnDR register must be read before the next data is received. During broadcast communication, an overrun error occurs if the IEBBnDR register is not read regardless of whether IEBBTD has occurred. For details, see the description of the IEBBnOVRE bit in 22.3.2  (20) IEBBnESR - IEBBn error status register .

In the FIFO mode, even if the IEBBnSRXF bit is set (to 1), the interrupt signal IEBBTV is not generated. For details about the IEBBTV generation timing, see the description of the IEBBnSLRI1, IEBBnSLRI0 bits in 22.3.2 (14) IEBBnTMS - IEBBn transfer mode setting register .

- (d) IEBBnDR register or FIFO buffer transmission status flag (IEBBnSTXF): Bit 0

   - Set/clear condition

Set:

- When communication finishes

- Single mode:

When the IEBBnDR register is written to

- FIFO mode:

When transmission data is written to the FIFO buffer

Clear:

- Single mode:

When the contents of the IEBBnDR register are written to the transmission shift register

- FIFO mode:

When the number of bytes of data written to the FIFO buffer are transferred from the FIFO buffer to the transmission shift register

In the single mode, when the IEBBnSTXF bit is cleared, the data interrupt IEBBTD occurs.

In the single mode, when IEBBTD occurs on data transmission, the next transmission data must be written to the IEBBnDR register.

Regardless of whether IEBBTD occurs, an underrun error occurs if IEBBnDR is not written to. For details, see the description of the IEBBnUNRE bit in 22.3.2 (20) IEBBnESR - IEBBn error status register .

In the FIFO mode, even if the IEBBnSRXF bit is set (to 1), the interrupt signal IEBBTD is not generated. For details about the IEBBTD generation timing, see the description of the IEBBnSLTI1, IEBBnSLTI0 bits in 22.3.2 (14) IEBBnTMS - IEBBn transfer mode setting register .

(18) IEBBnUSR - IEBBn unit status register

The IEBBnUSR register indicates the unit status.

**Access** This register is read-only, in 8-bit units. **Address** <IEBBn_base> + 0044H

**Initial value** 00H

This register is reset when the value of the IEBBnPW bit is overwritten with a different value.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|0|IEBBn<br>SRQF|IEBBn<br>ARBF|IEBBn<br>ALTF|IEBBn<br>ACKF|IEBBn<br>LCKF|0|0|
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

**Table 22-24 IEBBnUSR register contents**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|6|IEBBnSRQF|Slave request flag for the unit<br>0: There are no slave requests.<br>1: There is a slave request.|
|5|IEBBnARBF|Arbitration result flag<br>0: Arbitration loss did not occur.<br>1: Arbitration loss occurred.|
|4|IEBBnALTF|Broadcast communication flag<br>0: Individual communication status<br>1: Broadcast communication status|
|3|IEBBnACKF|Acknowledge transmission flag<br>0: A NACK signal is transmitted.<br>1: An ACK<br>signal is transmitted.|
|2|IEBBnLCKF|Lock status flag<br>0: Unlocked<br>1: Locked|

- (a) Slave request flag for the unit (IEBBnSRQF): Bit 6

   - Set/clear condition

Set:

When the unit is requested as a slave (if the condition in Table 22-25 is satisfied), this flag is set (to 1) by hardware when the parity bit communication of the slave address field ends[a] .

Clear:

This flag is cleared (to 0) by hardware when the unit is not requested as a slave (if the condition in Table 22-25 is not satisfied). The timing[a] is the same as that for setting the flag.

- a) The bit is updated when the communication of the slave address field parity bit finishes without an error such as a parity error occurring. For example, if the slave address reception parity is incorrect, the IEBBnSRQF bit is not updated and the previous value is retained.

**Table 22-25 Slave request conditions (conditions for setting the IEBBnSRQF bit)**

|**Status of unit**|**Received master address**|**Communication mode**|**Received slave address**|
|---|---|---|---|
|Not locked|don’t care|Individual|IEBBnUAR match|
|||Broadcast|Group matching|
||||FFFH match|
|Locked|Locked master matching|Individual|IEBBnUAR match|
|||Broadcast|Group matching|
||||FFFH match|

- Note IEBBnUAR match: When the reception slave address and unit IEBBnUAR register match

Group match: When the reception-slave-address group address and unit IEBBnUARregister group address match

FFFH match: When the reception slave address is FFFH

**Table 22-26 ACK signal response condition for the slave address field**

|**Status of unit**|**Received master address**|**Communication mode**|**Received slave address**|
|---|---|---|---|
|don’t care|don’t care|Individual|IEBBnUAR match|

Note IEBBnUAR match: When the reception slave address and unit IEBBnUAR register match

Caution If a unit other than the locked master communicates with the unit while the unit is locked, the IEBBnSRQF bit is not set but the ACK signal is returned to the slave address field. This is because communication must be continued, even for communication of a unit other than the locked master, if the control data received using the control field is a slave status transmission request.

- (b) Arbitration result flag (IEBBnARBF): Bit 5

   - Set/clear condition

Set:

When the data output by the unit does not match the received data during the arbitration period[a]

Clear:  After each communication frame start bit is transmitted or received

a) In the FIFO mode, the arbitration loss flag is set (to 1) based on the same condition even while the master request flag (IEBBnBCR.IEBBnMSRQ) is retained.

Note that, if arbitration is lost in the FIFO mode, a NACK reception error is detected by returning the NACK signal after control data reception, and software processing by outputting IEBBTERR is required.

In the case of a status transmission request, the NACK signal is not returned because there is an automatic response.

The IEBBnARBF bit is set (to 1) if there is inter-unit-data contention during the arbitration period (the broadcast field and master address field period) and the unit loses arbitration.

Arbitration loss is judged to have occurred when the unit output data does not match the received data.

Because the IEBus controller uses AND logic, the unit that outputs 0 wins arbitration.

In other words, among units that output broadcast data (0) for the broadcast field, the unit that has the smallest master address wins arbitration.

Caution

In the single mode, when the start interrupt occurs upon issuing a master request, use the IEBBnARBF bit to check for arbitration loss. To transfer data again in the case of arbitration loss, perform software processing to issue another master request.

In the FIFO mode, another master request is issued even if arbitration is lost the number of times specified by the IEBBnTMS.IEBBnALC0 to IEBBnALC2 bits. If the number of arbitration losses exceeds this setting, an interrupt occurs to indicate an arbitration loss error. To transfer data again, perform software processing to issue another master request.

## (c) Broadcast communication flag (IEBBnALTF): Bit 4

Flag indicating whether the unit is performing broadcast communication. The contents of the flag are updated in the broadcast field of each frame.

- Set/clear condition

Set: When “broadcast” is received by the broadcast field Clear: When individual is received by the broadcast field

Caution The broadcast flag is updated regardless of whether IEBus is the communication target.

In the FIFO mode, storage is performed upon header completion if reading the data received during the previous communication has finished (if the IEBBnBSR.IEBBnRFLF bit = 0 and the nBSR.IEBBnSRFP4 to IEBBnSRFP0 bits = 00000). Until reading the received data finishes, the IEBBnALTF register is not updated.

## (d) Acknowledge transmission flag (IEBBnACKF): Bit 3

This flag indicates whether the ACK signal was transmitted during the acknowledge bit period of the acknowledge bit field when IEBus is the receiving unit.

- Set/clear condition

Set:

When ACK is transmitted upon the completion of the acknowledge bit period for each field

Clear:

When NACK is transmitted upon the completion of the acknowledge bit period for each field

- Cautions 1. If a communication error occurs and the unit returns to the initial status, no update is performed at the end of the acknowledge bit period for the corresponding field. For example, if the reception parity for the control field is incorrect, because IEBBn changes to the initial status (the communication standby status) after parity reception due to the parity error, a NACK signal is returned by using the control field (more accurately, no ACK signal is returned), but this is not applied to the IEBBnACKF bit, and the previous value is retained.

   2. In the single mode, because the occurrence timing (when IEBBTSTA or IEBBTV becomes active) for the start interrupt and status transmission interrupt is when parity bit reception ends, the reading of the IEBBnUSR register by the previously described interrupt in the slave mode during interrupt handler processing might overlap with the changing of the IEBBnACKF bit.

- (e) Lock status flag (IEBBnLCKF): Bit 2

A flag that indicates whether the unit is locked.

- Set/clear condition

Set:

When an individual communication frame ends, lock-related data (3H, 6H, AH, and BH) is received by using the control field, the communication completion flag (the IEBBnISR.IEBBnETRF bit) is cleared (to 0), and the frame completion flag (the IEBBnISR.IEBBnEFMF bit) is set (to 1).

Clear:

When an individual communication frame ends, lock-related data (3H, 6H, AH, and BH) is received by using the control field, and the communication completion flag (the IEBBnISR.IEBBnETRF bit) is set (to 1)

- Cautions 1. Locking and unlocking are performed only during individual communication, not during broadcast communication.

   2. While the master is locked, communication from a unit other than the master is not generally acknowledged. However, as an exception, if the control data (0H, 4H, or 5H) of a slave status transmission request is received, the communication is acknowledged even if it is not from the locked master. Note that, at this time, only a status request interrupt occurs, not a start interrupt or completion interrupt.

(19) IEBBnISR - IEBBn interrupt status register

The IEBBnISR status register indicates the interrupt source when an IEBBTSTA, IEBBTERR, or IEBBTV interrupt occurs.

Each time the IEBBTSTA, IEBBTERR, and IEBBTV interrupts occur, the IEBBnISR register is read, and the specified interrupt servicing is performed.

**Access** Only bit 6 can be read or written in 8-bit units.

Bits other than bit 6 are read-only, in 8-bit units.

**Address** <IEBBn_base> + 0048H **Initial value** 00H

The IEBBnIEBE bit is reset when 0 is written to the IEBBnBCR.IEBBnPW bit.

Bits other than IEBBnIEBE are reset when the value of the IEBBnPW bit is overwritten with a different value.

Caution Be sure to set bits 1, and 7 to 0.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|0|IEBBn<br>IEBE|IEBBn<br>STRF|IEBBn<br>STSF|IEBBn<br>ETRF|IEBBn<br>EFMF|0|IEBBn<br>FOVE|
|R<br>R/Wa<br>R<br>R<br>R<br>R<br>R<br>R||||||||

> a) Only the IEBBnIEBE bit can be written. Note that, when writing to the IEBBnIEBE bit, the bit can only be cleared (to 0). Even if 1 is written, the IEBBnIEBE bit is not set (to 1).

## **Table 22-27 IEBBnISR register contents**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|6|IEBBnIEBE|Communication error flag<br>0: No communication error has occurred.<br>1: A communication error has occurred.|
|5|IEBBnSTRF|Start interrupt flag<br>0: No start interrupt has occurred.<br>1: A start interrupt has occurred.|
|4|IEBBnSTSF|Status transmission flag (slave)<br>0: There is no status transmission request.<br>1: There is a status transmission request.|
|3|IEBBnETRF|Communication completion flag<br>0: Communication of the number of transmission bytes specified by the message<br>length field has not finished.<br>1: Communication of the number of transmission bytes specified by the message<br>length field has finished.|
|2|IEBBnEFMF|Frame completion flag<br>0: The frame (communication of the maximum number of transmission bytesa) has<br>not finished.<br>1: The frame (communication of the maximum number of transmission bytesa) has<br>finished.|
|0|IEBBnFOVE|Frame over error flag<br>0: No frame over error has occurred.<br>1: A frame over error has occurred.|

> a) Communication mode 1: 32 bits, communication mode 2: 128 bits

- (a) Communication error flag (IEBBnIEBE): Bit 6

A flag that indicates a communication error has occurred.

- Set/clear condition

Set:

- Single mode:

When a timing error, parity error (except in the data field during individual reception), NACK reception error, underrun error, or overrun error (during broadcast reception) occurs

- FIFO mode:

When a timing error, parity error (except in the data field during individual reception), NACK reception error, underrun error, overrun error (during broadcast reception), or arbitration loss error occurs

Clear:

- Single mode or FIFO mode:

By software (The flag is cleared (to 0) when 0 is written to the IEBBnIEBE bit.)

When a communication error occurs, IEBBTERR IEBBTV occur in the single mode, and IEBBTERR occurs in the FIFO mode.

It is possible to determine what caused the error by reading the IEBBnESR and IEBBnISR registers.

- (b) Start interrupt flag: (IEBBnSTRF): Bit 5

A flag that indicates the start interrupt.

- Set/clear condition

Set:

- Single mode:

The flag is set (to 1) during master unit operation, regardless of whether arbitration is won or lost.

The flag is set (to 1) during slave unit operation if there is a slave request (when the IEBBnUSR.IEBBnSRQF bit = 1) from the master (only the locked master when the unit is locked).

The flag is set upon the completion of the slave address field parity period in all cases.

- FIFO mode: The IEBBnSTRF bit is not set (to 1).

Clear:

- Single mode:

If the unit is the communication target (during communication with the master unit or slave unit), the flag is cleared (to 0) by hardware when a status transmission interrupt, communication completion interrupt, frame completion interrupt, transmission data write request interrupt, reception data read interrupt, or communication error interrupt occurs.

- FIFO mode: The IEBBnSTRF bit is normally cleared.

In the single mode, IEBBTSTA and IEBBTV occur when a start interrupt occurs. In the FIFO mode, the start interrupt, IEBBTSTA, and IEBBTV do not occur.

- Cautions 1. When a start interrupt occurs, read the IEBBnUSR register to check the slave request flag (IEBBnSRQF) and arbitration result flag (IEBBnARBF) for the unit.

   2. If the arbitration result flag (IEBBnARBF) is set (to 1) when a start interrupt occurs after the unit issues a master request, perform software processing to reissue the master request.

- (c) Status transmission flag (slave) (IEBBnSTSF): Bit 4

This flag indicates that the master requested transmission of the slave status and lock address (higher 4 bits and lower 8 bits) when the controller was serving as a slave.

- Set/clear condition

Set:

- Single mode:

When the unit is not locked, there is a slave request from any master, and 0H or 6H is received by using the control field

When the unit is locked, there is a slave request from the locked master, and 0H, 4H, 5H, or 6H is received by using the control field, or when 0H, 4H, or 5H is received from a unit other than the locked master by using the control field

The flag is set upon the completion of the control field parity period in all cases.

For details, see Table 22-28 .

- FIFO mode: The IEBBnSTSF bit is not set (to 1).

Clear:

- Single mode:

If the unit is the communication target (during communication with the master unit or slave unit), the flag is cleared (to 0) by hardware when a start interrupt, communication completion interrupt, frame completion interrupt, transmission data write request interrupt, reception data read interrupt, or communication error interrupt occurs.

- FIFO mode: The IEBBnSTSF bit is normally cleared.

In the single mode, IEBBTSTA and IEBBTV occur when there is a status transmission request. In the FIFO mode, no interrupt signal is generated even if there is a status transmission request.

Caution

Even if the slave transmission enable flag (the IEBBnBCR.IEBBnSTXE bit) is set to the prohibited value (0), the IEBBnSTSF bit is set (to 1).

**Table 22-28 Conditions for setting the status transmission request flag (slave)**

|**Various statuses**|**Various statuses**|**Various statuses**|**Various statuses**|**Various statuses**|**Value received using the control field**|**Value received using the control field**|**Value received using the control field**|**Value received using the control field**|**Value received using the control field**|
|---|---|---|---|---|---|---|---|---|---|
|**equa**|**lockf**|**eqpa**|**IEBBn**<br>**STXE**|**IEBBn**<br>**SRXE**|**0H**|**3H, 7H**|**4H, 5H**|**6H**|**AH, BH,**<br>**EH, FH**|
|1|0|0|Any|Any|Set|Not set|Not set|Set|Not set|
|1|0|1|Any|Any|Set|Not set|Not set|Set|Not set|
|1|1|0|Any|Any|Set|Not set|Set|Not set|Not set|
|1|1|1|Any|Any|Set|Not set|Set|Set|Not set|

Note equa: Unit match (during individual communication, IEBBnUAR register match

lockf: Whether there is a lock eqpa: Lock master match IEBBnSTXE: Slave transmission enable flag (IEBBnBCR register bit 4) IEBBnSRXE: Slave reception enable flag (IEBBnBCR register bit 3)

If a slave status transmission request interrupt occurs in the single mode, read the IEBBnCDR register to check the received control data contents, and then write the required slave status information to the IEBBnDR register.

The received control data and data written to the IEBBnDR register are shown below.

**Table 22-29 Received control data and data written to the IEBBnDR register**

|**Received control data**||**Function**|**Data written to the IEBBnDR register**|
|---|---|---|---|
|0H, 6H||Slave status transmission|Value read from the IEBBnSSR register|
|4H||Transmission of the lower 8 bits of the<br>lock address|Lower 8 bits of the IEBBnPAR register|
|5H||Transmission of the higher 4 bits of the<br>lock address|Higher 8 bits of the IEBBnPAR register|
|||||
|||||
|||||
|Caution|After a slave status transmission request interrupt occurs, be sure to write the<br>appropriate data to the IEBBnDR register before the completion of the<br>message length field.|||

- (d) Communication completion flag (IEBBnETRF): Bit 3

A flag that indicates whether communication ends after the number of bytes set in the message length field have been transferred.

- Set/clear condition

Set:

- Single mode:

When the unit is the communication target (during communication with the master unit or slave unit) and the value of the IEBBnSCR register becomes 0 at the end of the data field acknowledge period

Clear:

- Single mode:

The flag is cleared (to 0) by hardware when a start interrupt, status transmission interrupt, frame completion interrupt (when a communication completion interrupt does not occur), transmission data write request interrupt, reception data read interrupt, or communication error interrupt occurs.

In the single mode, IEBBTSTA and IEBBTV occur when the communication completion flag is set (to 1).

In the FIFO mode, the IEBBTSTA interrupt occurs at the same timing as in the single mode.

In the FIFO mode, reading the IEBBnETRF bit is prohibited. If the bit is read, the returned value is undefined.

In the FIFO mode, after IEBBTSTA occurs, transmission and reception can be controlled by performing the software processing below.

- When reception ends

1. Detecting the completion of communication based on the occurrence of the IEBBTSTA interrupt

2. Checking whether communication or a frame has finished by using the IEBBnFSR.IEBBnRTRF bit

3. Checking the number of received data bytes by using the IEBBnBSR.IEBBnSRFP4 to IEBBnSRFP0 bits (the number of bytes that have not been read)

4. Reading the received data from the IEBBnDR register (the reception FIFO buffer)

- When transmission ends

1. Detecting the completion of communication based on the occurrence of the IEBBTSTA interrupt

2. Checking whether communication or a frame has finished by using the IEBBnFSR.IEBBnTTRF bit

3. Checking the number of transmission data bytes by using the IEBBnBSR.IEBBnSTFP4 to IEBBnSTFP0 bits (the number of bytes that have not been transmitted)

4. Proceeding to retransmission processing if there is data that has not been transmitted

- (e) Frame completion flag (IEBBnEFMF): Bit 2

This flag indicates whether communication ends after the maximum number of bytes (communication mode 1: 32 bytes, communication mode 2: 128 bytes) have been transferred.

- Set/clear condition

Set:

- Single mode:

When the unit is the communication target (during communication with the master unit or slave unit) and the value of the IEBBnCCR register becomes 0 at the end of the data field acknowledge period

Clear:

- Single mode:

The flag is cleared (to 0) by hardware when a start interrupt, status transmission interrupt, communication completion interrupt (when a frame completion interrupt does not occur), transmission data write request interrupt, reception data read interrupt, or communication error interrupt occurs.

In the single mode, IEBBTSTA and IEBBTV occur when the frame completion flag is set (to 1).

- Cautions 1. In the single mode, if the IEBBnSCR and IEBBnCCR registers are both cleared to 00H at the end of the data field acknowledge period, the IEBBnETRF and IEBBnEFMF bits are set (to 1) at the same time.

   2. In the single mode, if the last data field is a NACK signal when the maximum number of bytes that can be transmitted is reached during retransmission, the IEBBnEFMF and IEBBnIEBE bits (NACK reception error) are set (to 1) at the same time.

In the FIFO mode, the IEBBTSTA interrupt occurs at the same timing as in the single mode.

In the FIFO mode, reading the IEBBnEFMF bit is prohibited. If the bit is read, the returned value is undefined.

After IEBBTSTA occurs, transmission and reception can be controlled by performing the software processing below.

- When reception ends

1. Detecting the completion of communication based on the occurrence of the IEBBTSTA interrupt

2. Checking whether communication or a frame has finished by using the IEBBnFSR.IEBBnRTRF bit

3. Checking the number of received data bytes by using the IEBBnBSR.IEBBnSRFP4 to IEBBnSRFP0 bits (the number of bytes that have not been read)

4. Reading the received data from the IEBBnDR register (the reception FIFO buffer)

   - When transmission ends

   1. Detecting the completion of communication based on the occurrence of the IEBBTSTA interrupt

   2. Checking whether communication or a frame has finished by using the IEBBnFSR.IEBBnTTRF bit

   3. Checking the number of transmission data bytes by using the IEBBnBSR.IEBBnSTFP4 to IEBBnSTFP0 bits (the number of bytes that have not been transmitted)

   4. Proceeding to retransmission processing if there is data that has not been transmitted

- (f) Frame over error flag (IEBBnFOVE): Bit 0

This flag indicates that a frame over error has occurred.

- Set/clear condition

Set:

- Single mode: The IEBBnFOVE bit is not set (to 1).

- FIFO mode:

If the next broadcast communication is received as a slave unit before reading the data received during the previous communication finishes, the flag is set (to 1) after the first data field parity period finishes.

Clear:

- Single mode or FIFO mode:

By software

(The flag is cleared (to 0) when 1 is written to the IEBBnSTC1.IEBBnCLFF bit.)

In the single mode, the IEBBnFOVE bit is not set (to 1), and no interrupt requests occur.

In the FIFO mode, IEBBTERR occurs when the IEBBnFOVE bit is set (to 1).

Even if a frame over error occurs for the current frame, the data received during the previous frame is valid.

## (20) IEBBnESR - IEBBn error status register

The IEBBnESR register is used to indicate the cause when an IEBus controller communication error interrupt occurs. Each bit of the IEBBnESR register is set (to 1) as soon as the communication error flag of the IEBBnISR register (IEBBnIEBE) is set (to 1). The cause of a communication error, if any, can be identified by checking the contents of the IEBBnESR register. (If the IEBBnISR.IEBBnIEBE bit is already set to 1, only the bits of the IEBBnESR register are set (to 1).)

Note that the bits can only be set (to 1) by hardware and are cleared by writing 1 to the IEBBnSTC0 register.

When 1 is written to the IEBBnSTC0 register, if there is contention with the hardware trying to specify (1), the hardware is prioritized.

Note that writing to the IEBBnESR register is invalid.

**Access** This register is read-only, in 8-bit units.

**Address** <IEBBn_base> + 004CH

**Initial value** 00H

This register is reset when the value of the IEBBnBCR.IEBBnPW bit is overwritten with a different value.

Caution When a communication error occurs, IEBBn returns to the initial status and prepares for the next communication. Regardless of whether an error occurs, if the next communication is started without handling errors, any error flags that have been set remain set. (If the system returns to the initial status due to a timing error, and a parity error is received during the next communication, both the timing error and parity error bits of the IEBBnESR register are set to 1.) Therefore, handle any errors that occur before the next communication starts.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|IEBBn<br>TIME|IEBBn<br>PARE|IEBBn<br>NACE|IEBBn<br>UNRE|IEBBn<br>OVRE|0|IEBBn<br>ABTE|IEBBn<br>TRDE|
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

**Table 22-30 IEBBnESR register contents (1/2)**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|7|IEBBnTIME|Timing error occurrence flag<br>0: No timing error has occurred.<br>1: A timing error has occurred.|
|6|IEBBnPARE|Parity error occurrence flag<br>0: No parity error has occurred.<br>1: A parity error has occurred.|
|5|IEBBnNACE|NACK reception error flag<br>0:  No NACK reception error has occurred.<br>1: A NACK reception error has occurred.|
|4|IEBBnUNRE|Underrun error occurrence flag<br>0: No underrun error has occurred.<br>1: An underrun error has occurred.|

**Table 22-30 IEBBnESR register contents (2/2)**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|3|IEBBnOVRE|Overrun error occurrence flag<br>0: No overrun error has occurred.<br>1: An overrun error has occurred.|
|1|IEBBnABTE|Arbitration loss error occurrence flag<br>0: The number of arbitration losses specified for the arbitration loss count setting<br>bits (IEBBnTMS.IEBBnALC2 to IEBBnALC0) have not occurred.<br>1: The number of arbitration losses specified for the arbitration loss count setting<br>bits (IEBBnTMS.IEBBnALC2 to IEBBnALC0) have occurred.|
|0|IEBBnTRDE|Inter-third-party communication error occurrence flag<br>0: An error occurred during communication targeting the unit.<br>1: An error occurred during inter-third-party communication.|

- (a) Timing error occurrence flag (IEBBnTIME): Bit 7

   - Set condition

Set: This flag is set (to 1) if a timing error occurs.

A timing error occurs if the high-/low-level width of the communication bit is not the defined value.

The defined value of the high- and low-level width is set to the bit processing block and monitored by the internal timer.

- (b) Parity error occurrence flag (IEBBnPARE): Bit 6

   - Set condition

Set: This flag is set (to 1) if a parity error occurs.

When the unit is the reception unit (including while communication between others is being monitored), a parity error occurs when the parity data generated by the data received using the master address field, slave address field, control data field, or message length field does not match the received parity data.

However, when there is a data field mismatch, a NACK signal is returned and a data retransmission request is issued during individual communication, but a parity error occurs during broadcast communication.

Note During the above parity period, if the parity data received on the transmission side is inverted for some reason, a timing error occurs and communication ends.

## **Table 22-31 Operation when the parity data does not match**

|**Field**|**Communication mode**|**Operation when the parity data**<br>**does not match**|
|---|---|---|
|Master address field|Individual/broadcast|A parity error occurs.|
|Slave address field|Individual/broadcast|A parity error occurs.|
|Control data field|Individual/broadcast|A parity error occurs.|
|Message length field|Individual/broadcast|A parity error occurs.|
|Data field|Individual|A NACK signal is returned to<br>request retransmission.|
||Broadcast|A parity error occurs.|

- (c) NACK reception error flag (IEBBnNACE): Bit 5

   - Set condition

Set: This flag is set (to 1) if a NACK reception error occurs.

A NACK reception error occurs if a NACK signal is received during the acknowledge bit period of the slave address field, control data field, or message length field during individual communication, regardless of whether the controller is operating as the master or slave.

When a NACK signal is received for the data field, no NACK reception error generally occurs because this reception signals a data retransmission request. However, if the last data field is a NACK signal, a NACK reception error does occur.

During reception, a NACK reception error is judged to have occurred if an output NACK signal is received for the last data of the slave address field, control data field, message length field, or data field.

Note that, during broadcast communication, no NACK reception errors occur because ACK/NACK signal judgment is not performed.

No NACK reception errors occur during inter-third-party communication because only timing/parity errors are detected as errors. However, for the slave address field, NACK reception error judgment is performed because communication is participated in as a slave.

**Table 22-32 NACK reception error judgment period**

|**Communication mode**|**Communication mode**|**Slave address field**|**Control data field**<br>**Data field**|**Message length**<br>**field**|**Data field (last)**|
|---|---|---|---|---|---|
|Individual<br>communication|Master<br>transmission|Occurs|Occurs|Occurs|Occurs|
||Master<br>reception|—|—|Occurs|Occurs|
||Slave<br>transmission|—|—|Occurs|Occurs|
||Slave reception|Occurs|Occurs|Occurs|Occurs|
||Inter-third-party<br>communication|Occurs|Does not occur|Does not occur|Does not occur|
|Broadcast<br>communication|All|Does not occur|Does not occur|Does not occur|Does not occur|

- (d) Underrun error occurrence flag (IEBBnUNRE): Bit 4

   - Set condition

Set:

- Single mode:

During data transmission using the data field, an underrun error occurs if writing the next data to be transmitted to the IEBBnDR register does not finish before the end of the data-field acknowledge bit period following the occurrence of IEBBTD, and this flag is set (to 1). However, if the NACK signal is received during the acknowledge bit period, no underrun error occurs because retransmission is performed.

During inter-third-party communication, underrun errors do not occur because only timing/parity errors are detected as errors.

**==> picture [455 x 146] intentionally omitted <==**

**----- Start of picture text -----**<br>
•  •  • P A Data field P A Data field •  •  •<br>Request to write to the<br>IEBBTD IEBBnDR register<br>IEBBnSSR.IEBBnSTXF<br>bit<br>An error occurs if the IEBBnDR register<br>is not written to during this period.<br>**----- End of picture text -----**<br>

## **Figure 22-6 Underrun error occurrence timing**

## – FIFO mode:

Before data of the message length specified by the IEBBnTDL register is transmitted, if there are 0 data items to be transmitted remaining in the transmission FIFO buffer (if the IEBBnSSR.IEBBnSTXF bit = 0), an underrun error occurs if writing the next data to be transmitted to the IEBBnDR register does not finish before the end of the next data-field acknowledge bit period, and this flag is set (to 1). However, if the NACK signal is received during the acknowledge bit period, no underrun error occurs because retransmission is performed.

During inter-third-party communication, underrun errors do not occur because only timing/parity errors are detected as errors.

- (e) Overrun error occurrence flag (IEBBnOVRE): Bit 3

   - Set condition

Set:

## – Single mode:

When the data field is used to receive data during broadcast communication, an overrun error occurs if reading the IEBBnDR register does not finish between when IEBBTD occurs and when the parity period of the data field finishes, and this flag is set (to 1).

During individual communication, data retransmission is requested by returning a NACK signal without an error, and returning the NACK signal continues until the IEBBnDR register is read. (However, the frame ends when the maximum number of bytes that can be transferred is reached.)

During inter-third-party communication, overrun errors do not occur because only timing/parity errors are detected as errors.

**==> picture [455 x 146] intentionally omitted <==**

**----- Start of picture text -----**<br>
•  •  • P A Data field P A Data field •  •  •<br>Request to read to the<br>IEBBTD IEBBnDR register<br>IEBBnSSR.IEBBnSRXF<br>bit<br>An error occurs if the IEBBnDR register<br>is not read to during this period.<br>**----- End of picture text -----**<br>

## **Figure 22-7 Overrun error occurrence timing**

## – FIFO mode:

During broadcast communication in communication mode 2, if there are 32 bytes of unread data in the reception FIFO buffer, an overrun error occurs if a 33rd byte of data is received, and this flag is set (to 1).

During individual communication, data retransmission is requested by returning a NACK signal without an error, and returning the NACK signal continues until the IEBBnDR register is read. (However, the frame ends when the maximum number of bytes that can be transferred is reached.)

If an overrun error occurs, do not read data by servicing interrupts.

If an interrupt occurs while reading data, it might no longer be possible to read the correct data.

- (f) Arbitration loss error occurrence flag (IEBBnABTE): Bit 1

   - Set condition

Set:

If arbitration losses occur the number of times specified for the IEBBnTMS.IEBBnALC2 to IEBBnALC0 bits, this flag is set (to 1) when the last arbitration loss error occurs.

For details about arbitration loss, see the description of the IEBBnARBF bit in 22.3.2 (18) IEBBnUSR - IEBBn unit status register .

- (g) Inter-third-party communication error occurrence flag (IEBBnTRDE): Bit 0

   - Set condition

Set:

If an inter-third-party communication error occurs at the same time as a timing error or parity error that occurs during communication that is not related to the unit (interthird-party communication), this flag is set (to 1) at the same time as the IEBBnTIME or IEBBnPARE bit.

Caution If an error occurs before the inter-third-party communication starts even when the slave address field does not match that of the unit (for example, if the NACK signal is received when the received address does not match that of the unit in the slave address field (if the IEBBnNACE bit is set (to 1))), the IEBBnTRDE bit is not set (to 1).

Note Communication between third parties may take place in the following two cases.

1. If the address received in the slave address field does not match that of the unit (during individual communication: matching with the IEBBnUAR register, during broadcast communication: matching with the group or FFFH) and communication continues after the ACK signal has been received, the unit monitors that communication.

2. If the unit cannot respond to the received control data in the control field during broadcast communication and if communication continues, the unit monitors that communication. For example, this happens when the unit receives the control data FH from the master during broadcast communication but the slave reception enable flag of the unit is disabled (IEBBnBCR.IEBBnSRXE bit = 0). (During individual communication, the NACK signal is returned and communication ends.)

- (21) IEBBnFSR - IEBBn field status register

The IEBBnFSR register is used to store the field status state of the IEBus controller when various interrupts (IEBBTD, IEBBTSTA, IEBBTERR, and  IEBBTV) occur.

**Access** This register is read-only, in 8-bit units.

**Address** <IEBBn_base> + 0050H

- **Initial value** 00H

The IEBBnSSFS1 and IEBBnSSFS0 bits are reset when the IEBBnBCR.IEBBnPW bit is overwritten with a different value.

- Cautions 1. If a different interrupt occurs before the IEBBnFSR register is read, the status information used at the time of the previous interrupt is overwritten with the status information used at the time of the new interrupt.

   2. If an interrupt occurs during communication between third parties (during the reception of communication between other units), the IEBBnSSFS1 and IEBBnSSFS0 bits are cleared to 00. However, because the only interrupts that occur during communication between third parties are interrupts caused by errors, an inter-third-party communication error can be judged to have occurred by reading the inter-third-party communication error occurrence flag (the IEBBnTRDE bit) of the IEBBnESR register.

   3. Even if the field status signal (an internal signal) changes, the IEBBnSSFS1 and IEBBnSSFS0 bits retain their previous values until an interrupt occurs.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|IEBBn<br>RTRF|IEBBn<br>TTRF|0|0|0|0|IEBBn<br>SSFS1|IEBBn<br>SSFS0|
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

**Table 22-33 IEBBnFSR register contents**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|7|IEBBnRTRF|Reception communication completion flag<br>0: Communication did not finish during reception.<br>1: Communication finished during reception.|
|6|IEBBnTTRF|Transmission communication completion flag<br>0: Communication did not finish during transmission.<br>1: Communication finished during transmission.|
|1, 0|IEBBnSSFS<br>[1, 0]|For details about the IEBBnSSFS1 and IEBBnSSFS0 bits, see Table 22-34.|

**Table 22-34 Field status**

|**Field status**||**Description**|**Description**|
|---|---|---|---|
||**Master/slave**|**Field**|**Transmission/**<br>**reception**|
|Slave reception status<br>IEBBnSSFS1 and IEBBnSSFS0 bits =<br>00 (IEBBnFSR register = 00H)|Slave operation|Start bit|Reception|
|||Master address field||
|||Slave address field||
|||Control data field||
|||Message length field||
|||Data field||
|Slave transmission status<br>IEBBnSSFS1 and IEBBnSSFS0 bits =<br>01 (IEBBnFSR register = 01H)|Slave operation|Message length field|Transmission|
|||Data field||
|Master reception status<br>IEBBnSSFS1 and IEBBnSSFS0 bits =<br>10 (IEBBnFSR register = 02H)|Master operation|Message length field|Reception|
|||Data field||
|Master transmission status<br>IEBBnSSFS1 and IEBBnSSFS0 bits =<br>11 (IEBBnFSR register = 03H)|Master operation|Start bit|Transmission|
|||Master address field||
|||Slave address field||
|||Control data field||
|||Message length field||
|||Data field||

## (a) Reception communication completion flag (IEBBnRTRF): Bit 7

This flag indicates that communication equivalent to the number of bytes specified by the message length has finished during reception.

- Set/clear condition

Set:

– Single mode: The IEBBnRTRF bit is not set (to 1).

– FIFO mode:

During reception, the flag is set (to 1) when the IEBBnISR.IEBBnETRF bit is set (to 1).

Clear:

– Single mode: The IEBBnRTRF bit always has the clear status.

- FIFO mode:

During reception, the flag is cleared (to 0) when the IEBBnISR.IEBBnEFMF bit is set (to 1).

- Cautions 1. In the FIFO mode, if the set and clear conditions are both satisfied, setting the flag is prioritized.

   2. The IEBBnRTRF bit is not cleared (to 0) by writing 1 to the IEBBnPCR.IEBBnCRPT bit.

- (b) Transmission communication completion flag (IEBBnTTRF): Bit 6

This flag indicates that communication equivalent to the number of bytes specified by the message length has finished during transmission.

- Set/clear condition

Set:

– Single mode: The IEBBnTTRF bit is not set (to 1).

– FIFO mode:

During transmission, the flag is set (to 1) when the IEBBnISR.IEBBnETRF bit is set (to 1).

Clear:

– Single mode: The IEBBnTTRF bit always has the clear status.

– FIFO mode:

During transmission, the flag is cleared (to 0) when the IEBBnISR.IEBBnEFMF bit is set (to 1).

- Cautions 1. In the FIFO mode, if the set and clear conditions are both satisfied, setting the flag is prioritized.

   2. The IEBBnTTRF bit is not cleared (to 0) by writing 1 to the IEBBnPCR.IEBBnCTPT bit.

- (c) Field status flags (IEBBnSSFS1 and IEBBnSSFS0): Bits 1 and 0

These flags store the state of the IEBus controller field status when various interrupts (IEBBTD, IEBBTSTA, IEBBTERR, and IEBBTV) occur.

**==> picture [455 x 413] intentionally omitted <==**

**----- Start of picture text -----**<br>
Internal field state  Internal field state<br>previous status retention 03H<br>Logic 1<br>Master unit<br>Logic 0<br>1TP1 1TP2 1TP3 1TP4<br>Example:  If a timing error occurred<br>during the  [1] TP3 period<br>Bus line<br>IEBBTERR<br>Internal field status Previous status retention 03H<br>IEBBnFSR<br>Previous status retention 03H<br>register<br>Remark 1TP1: Reference signal output period<br>1TP2: Synchronization signal output period<br>1TP3: Start bit output period<br>1TP4: Stop signal output period<br>**----- End of picture text -----**<br>

**Figure 22-8 Start bit field status for the master (internal signal)**

When the start bit shown in Figure 22-8 is output for the master, the previous field status value is retained until[1] TP1. At point[1] TP2 and after, the field status value is 03H. If a timing error occurs at point[1] TP3 and IEBBTERR is output, 03H is stored in the IEBBnFSR register.

Because IEBBTERR does not occur if communication is performed normally, the field status value is not stored in the IEBBnFSR register, and the IEBBnFSR register retains the previous value at and after point[1] TP2.

(22) IEBBnSCR - IEBBn success count register

The IEBBnSCR register indicates the number of remaining communication bytes.

The value specified by the IEBBnDLR register is stored in the IEBBnSCR register after the message length field processing finishes, and the count value of the counter to be decremented according to the data field ACK signal is read.

In other words, because the number of successfully communicated bytes is subtracted from the number of data bytes to be communicated, the IEBBnSCR register indicates the remaining number of bytes to be communicated.

Note that the communication completion flag (the IEBBnISR.IEBBnETRF bit) is set (to 1) when the count value reaches 00H.

The data in the IEBBnSCR register is updated when the ACK signal is received at the end of the message length field parity period or data field acknowledge bit period.

**Access** This register is read-only, in 8-bit units.

**Address** <IEBBn_base> + 0054H

**Initial value** 01H

This register is reset when the value of the IEBBnBCR.IEBBnPW bit is overwritten with a different value.

Caution When 00H is read from the IEBBnSCR register, it is not possible to judge whether the remaining number of communication data bytes is 0 (indicating communication completion) or 256. Therefore, the communication completion flag (the IEBBnISR.IEBBnETRF bit) must also be used with this register to make this judgment.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|||||||||
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

**Table 22-35 IEBBnSCR register contents**

|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Bit**|**Setting**|**Number of remaining communication data bytes**|
|---|---|---|---|---|---|---|---|---|---|
|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|||
|0|0|0|0|0|0|0|1|01H|1 byte|
|0|0|0|0|0|0|1|0|02H|2 bytes|
|...|...|...|...|...|...|...|...|...|...|
|0|0|0|1|0|1|0|0|20H|32 bytes|
|...|...|...|...|...|...|...|...|...|...|
|1|1|1|1|1|1|1|1|FFH|255 bytes|
|0|0|0|0|0|0|0|0|00H|0 bytes (communication completion) or 256 bytes|

(23) IEBBnCCR - IEBBn communication count register

The IEBBnCCR register indicates the number of bytes remaining from the communication byte number specified by the communication mode.

This register indicates the number of transfer bytes.

The maximum number of transmitted bytes per frame defined in each mode (communication mode 1: 32 bytes, communication mode 2: 128 bytes) is preset to this register. The count value of the counter that is decremented during the acknowledge bit period of the data field regardless of the ACK/NACK signal is read from this register. In contrast with the IEBBnSCR register, which is decremented when there is normal communication (the ACK signal), the IEBBnCCR register is decremented when one byte is communicated, regardless of the ACK/NACK signal. Note that the frame completion flag (the IEBBnISR.IEBBnEFMF bit) is set (to 1) when the counter reaches 00H.

The preset value of the maximum number of transmitted bytes per frame is 20H (32 bytes) in communication mode 1 and 80H (128 bytes) in communication mode 2.

Updating of data proceeds independently of parity at the end of the ACK interval for the data field on completion of transmission (or reception) of the start bit for the preset maximum number of bytes.

**Access** This register is read-only, in 8-bit units.

**Address** <IEBBn_base> + 0058H

**Initial value** 20H

This register is reset when the value of the IEBBnBCR.IEBBnPW bit is overwritten with a different value.

## Caution The value of the IEBBnCCR register is not updated by writing to the IEBBnPSR.IEBBnCMD bit.

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|||||||||
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R||||||||

(24) IEBBnSTC0 - IEBBn status clear register 0 **Access** This register is write-only, in 8-bit units. **Address** <IEBBn_base> + 005CH

The IEBBnSTC0 register is used to clear the IEBBnESR register.

**Initial value** 00H

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|IEBBn<br>CLTM|IEBBn<br>CLPA|IEBBn<br>CLNC|IEBBn<br>CLUR|IEBBn<br>CLOV|0|IEBBn<br>CLAB|IEBBn<br>CLTR|
|W<br>W<br>W<br>W<br>W<br>R<br>W<br>W||||||||

**Table 22-36 IEBBnSTC0 register contents**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|7|IEBBnCLTM|This bit is used to clear the timing error flag (IEBBnESR.IEBBnTIME).<br>0: No operation<br>1: Clear the IEBBnTIME bit.<br>Writing 1 is valid, and writing 0 does not change the internal status.<br>When the bit is read, 0 is always returned.|
|6|IEBBnCLPA|This bit is used to clear the parity error flag (IEBBnESR.IEBBnPARE).<br>0: No operation<br>1: Clear the IEBBnPARE bit.<br>Writing 1 is valid, and writing 0 does not change the internal status.<br>When the bit is read, 0 is always returned.|
|5|IEBBnCLNC|This bit is used to clear the NACK reception error flag (IEBBnESR.IEBBnNACE).<br>0: No operation<br>1: Clear the IEBBnNACE bit.<br>Writing 1 is valid, and writing 0 does not change the internal status.<br>When the bit is read, 0 is always returned.|
|4|IEBBnCLUR|This bit is used to clear the underrun error flag (IEBBnESR.IEBBnUNRE).<br>0: No operation<br>1: Clear the IEBBnUNRE bit.<br>Writing 1 is valid, and writing 0 does not change the internal status.<br>When the bit is read, 0 is always returned.|
|3|IEBBnCLOV|This bit is used to clear the overrun error flag (IEBBnESR.IEBBnOVRE).<br>0: No operation<br>1: Clear the IEBBnOVRE bit.<br>Writing 1 is valid, and writing 0 does not change the internal status.<br>When the bit is read, 0 is always returned.|
|1|IEBBnCLAB|This bit is used to clear the arbitration loss error flag (IEBBnESR.IEBBnABTE).<br>0: No operation<br>1:  Clear the IEBBnABTE bit.<br>Writing 1 is valid, and writing 0 does not change the internal status.<br>When the bit is read, 0 is always returned.|
|0|IEBBnCLTR|This bit is used to clear the inter-third-party communication error flag<br>(IEBBnESR.IEBBnTRDE).<br>0: No operation<br>1: Clear the IEBBnTRDE bit.<br>Writing 1 is valid, and writing 0 does not change the internal status.<br>When the bit is read, 0 is always returned.|

(25) IEBBnSTC1 - IEBBn status clear register 1 The IEBBnSTC1 register is used to clear the IEBBnISR.IEBBnFOVE bit. **Access** This register is write-only, in 8-bit units. **Address** <IEBBn_base> + 0060H **Initial value** 00H

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|0|0|0|0|0|0|0|IEBBn<br>CLFF|
|R<br>R<br>R<br>R<br>R<br>R<br>R<br>W||||||||

**Table 22-37 IEBBnSTC1 register contents**

|**Bit**<br>**position**|**Bit name**|**Function**|
|---|---|---|
|0|IEBBnCLFF|This bit is used to clear the frame over error flag (IEBBnISR.IEBBnFOVE).<br>0: No operation<br>1: Clear the IEBBnFOVE bit.<br>Writing 1 is valid, and writing 0 does not change the internal status.<br>When the bit is read, 0 is always returned.|

- (26) IEBBnDR - IEBBn data register

The IEBBnDR register is used to set up the communication data. Specify the communication data (8 bits) for bits 7 to 0.

- Notes 1. The IEBBnDR register consists of a write register and a read register. Therefore, data written to this register cannot be read as is. The data received during IEBus communication can be read.

      2. In the FIFO mode, the data in the FIFO buffer can be transferred by continuously accessing the IEBBnDR register. (See 22.5.1 (1) Transmission FIFO buffer for details about using the transmission unit or 22.5.1  (2) Reception FIFO buffer for details about using the reception unit.)

   - (a) For the transmission unit

If the unit is the transmission unit (during master or slave transmission), the bits in the data field are transmitted as data bits starting with the highest bits when writing to the IEBBnDR register.

Specify the first byte of transmission data before starting communication (IEBBnBCR.IEBBnMSRQ bit = 0).

Even in the FIFO mode, write at least one byte of transmission data to the FIFO buffer before starting communication (IEBBnMSRQ bit = 0).

In the FIFO mode, the contents of the FIFO buffer are not reset in sync with the IEBBnBCR.IEBBnPW bit. Clearing the pointer value (to 0) eliminates the remaining data visible to the user. The stored data becomes undefined.

During transmission (master or slave transmission), if a data interrupt (IEBBTD) occurs, the next transmission data is written to the IEBBnDR register.

In the single mode, if a status transmission interrupt (IEBBTSTA or IEBBTV) occurs, the status data is written to the IEBBnDR register according to the control data.

- (b) For the reception unit

The 1 byte of data received using the data field is read from the IEBBnDR register if the unit is the reception unit (master or slave reception). Storage is performed at the end of the data field parity period if the parity value is normal. The read value is reset by clearing the IEBBnPW bit to 0.

During reception (master or slave reception), if a data interrupt (IEBBTD) occurs, received data is read from the IEBBnDR register.

**Access** This register can be read or written in 8-bit units.

**Address** <IEBBn_base> + 0064H

**Initial value** 00H

The read value is reset when the IEBBnBCR.IEBBnPW bit is overwritten.

- Cautions 1. If writing to the IEBBnDR register is not in time for transmission, an underrun error occurs and communication ends.

   2. Write to the status data register IEBBnDR after a status transmission interrupt occurs and before the end of the message length field.

   3. In the single mode, if the IEBBnDR register is not read before the next reception, the communication differs in the case of individual versus broadcast communication.

      - For individual communication, a NACK signal is returned for the field, and the master is requested to transmit the same data. Received data is not stored in the IEBBnDR register. If the NACK signal is returned again before the IEBBnDR register is read and the register has still not been read when the maximum number of transferable bytes is reached, frame completion (IEBBTSTA, IEBBTV) and a NACK reception error (IEBBTERR, IEBBTV) occur at the same time.

      - During broadcast communication, an overrun error occurs and communication ends. Received data is not stored in the IEBBnDR register. The overrun error flag (IEBBnOVRE) is set (to 1).

   4. In the FIFO mode, if the next reception occurs before all the data received during the previous communication is read, the communication differs in the case of individual versus broadcast communication.

      - For individual communication, a NACK signal is returned for the data field, and the master is requested to transmit the same data. Received data is not stored in the FIFO buffer. If the NACK signal is returned again before all the data in the FIFO buffer is read and the FIFO buffer has still not been read when the maximum number of transferable bytes is reached, frame completion (IEBBTSTA) and a NACK reception error (IEBBTERR) occur at the same time.

      - During broadcast communication, an overrun error occurs and communication ends. Received data is not stored in the FIFO buffer. The frame over error flag (IEBBnISR.IEBBnFOVE) is set (to 1).

   5. In the FIFO mode and communication mode 2, if there are 32 bytes of unread data and the next reception occurs, the communication differs in the case of individual versus broadcast communication.

      - For individual communication, a NACK signal is returned for the field, and the master is requested to transmit the same data. Received data is not stored in the FIFO buffer. If the NACK signal is returned again before the IEBBnDR register is read and reading the register has still not finished when the maximum number of transferable bytes is reached, frame completion (IEBBTSTA) and a NACK reception error (IEBBTERR) occur at the same time.

      - During broadcast communication, an overrun error occurs and communication ends. Received data is not stored in the FIFO buffer. The overrun error flag (IEBBnESR.IEBBnOVRE) is set (to 1).

|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|7<br>6<br>5<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
|||||||||
|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||||||||

## 22.4 Interrupt Operations

## 22.4.1 Interrupt request signals

Various interrupts occur in response to the eight interrupt requests below. The high level width of each interrupt signal is one P0  clock cycle.

The interrupts that occur differ depending on whether the system is in the single or FIFO mode.

- (1) Single mode

The causes of interrupts in the single mode are shown blow.

## **Table 22-38 Causes of interrupts in the single mode**

|**Symbol**|**IEBBTD**|**IEBBTV**|**IEBBTERR**|**IEBBTSTA**|**Interrupt cause**|
|---|---|---|---|---|---|
|IEBBnIEBE||Occurs|Occurs||Communication error<br>(When the IEBBnISR.IEBBnIEBE bit = 1)<br>Note that IEBBnIEBE occurs when the<br>following bits of the IEBBnESR register =<br>1.<br>**•**<br>Timing error (IEBBnTIME)<br>**•**<br>Parity error (IEBBnPARE)<br>**•**<br>NACK reception error (IEBBnNACE)a<br>**•**<br>Underrun error (IEBBnUNRE)<br>**•**<br>Overrun error (IEBBnOVRE)|
|IEBBnSTRF||Occurs||Occurs|Start request (when the<br>IEBBnISR.IEBBnSTRF bit = 1)|
|IEBBnSTSF||Occurs||Occurs|Status transmission request<br>(when the IEBBnISR.IEBBnSTSF bit = 1)|
|IEBBnETRF||Occurs||Occurs|End of communication<br>(When the IEBBnISR.IEBBnETRF bit = 1)|
|IEBBnEFMF||Occurs||Occurs|End of frame<br>(When the IEBBnISR.IEBBnEFMF bit =<br>1)a|
|IEBBnFOVE|||||Frame over<br>(When the IEBBnISR.IEBBnFOVE bit = 1)|
|WRREQ|Occurs||||Transmission data write request (when<br>the IEBBnSSR.IEBBnSTXF bit = 0)b|
|RDREQ|Occurs||||Reception data read request (when the<br>IEBBnSSR.IEBBnSRXF bit = 1)c|

- a) If the frame data ends with a NACK signal, IEBBTV and IEBBTSTA are triggered by setting the frame completion indicating bit IEBBnISR.IEBBnEFMF (to 1).

   - At this time, the IEBBTERR and IEBBTV interrupts are triggered by a NACK reception error. Three interrupts (IEBBTV, IEBBTSTA, and IEBBTERR) occur at the same time.

- b) During master transmission:

   1. IEBBTD occurs after receiving the ACK signal, which follows message length field transmission. However, if the transfer size is one byte (the IEBBnTDL register = 01H), IEBBTD does not occur.

   2. IEBBTD occurs after receiving the ACK signal, which follows data field transmission. However, IEBBTD does not occur before transmitting the final data, or after transmitting the final data and then receiving the ACK signal. More specifically, if the message length is five bytes, IEBBTD does not occur after transmitting the 4th or 5th byte. In addition, when transmitting the maximum number of transferable bytes for one frame, IEBBTD does not occur after transmitting byte number (maximum number of transferrable bytes  1) or byte number (maximum number of transferable bytes).

## During slave transmission:

   1. IEBBTD occurs after receiving the ACK signal, which follows message length field transmission. However, if the transfer size is one byte or the received control bit is a status request (0H, 4H, 5H, or 6H), IEBBTD does not occur (and a status transmission interrupt occurs instead).

2. After data field transmission, the operation is the same as for _2_ under During master transmission.

c) RDREQ occurs after receiving the parity bit by using the data field. However, if the self-transmitted parity bit differs from the received parity bit, there is a timing error and no interrupt occurs.

## (2) FIFO mode

The causes of interrupts in the FIFO mode are shown below.

**Table 22-39 Causes of interrupts in the FIFO mode**

|**Symbol**|**IEBBTD**|**IEBBTV**|**IEBBTERR**|**IEBBTSTA**|**Interrupt cause**|
|---|---|---|---|---|---|
|IEBBnIEBE|||Occurs||Communication error<br>(When the IEBBnISR.IEBBnIEBE bit = 1)<br>Note that IEBBnIEBE occurs when the<br>following bits of the IEBBnESR register =<br>1.<br>**•**<br>Timing error (IEBBnTIME)<br>**•**<br>Parity error (IEBBnPARE)<br>**•**<br>NACK reception error (IEBBnNACE)a<br>**•**<br>Underrun error (IEBBnUNRE)<br>**•**<br>Overrun error (IEBBnOVRE)b<br>**•**<br>Arbitration loss error (IEBBnABTE)|
|IEBBnSTRF|||||Start request (when the<br>IEBBnISR.IEBBnSTRF bit = 1)|
|IEBBnSTSF|||||Status transmission request<br>(when the IEBBnISR.IEBBnSTSF bit = 1)|
|IEBBnETRF||Occursc||Occurs|End of communication<br>(When the IEBBnISR.IEBBnETRF bit = 1)|
|IEBBnEFMF||Occursc||Occurs|End of frame<br>(When the IEBBnISR.IEBBnEFMF bit =<br>1)a|
|IEBBnFOVE|||Occurs||Frame over<br>(When the IEBBnISR.IEBBnFOVE bit =<br>1)b|
|WRREQ|Occursd||||Transmit data write request|
|RDREQ||Occurse|||Receive data write request<br>Parity|

> a) If the frame data ends with a NACK signal, IEBBTV and IEBBTSTA are triggered by setting the frame completion indicating bit IEBBnISR.IEBBnEFMF (to 1).

Note that the IEBBTERR interrupt is triggered by a NACK reception error.

- Three interrupts (IEBBTV, IEBBTSTA, and IEBBTERR) occur at the same time, regardless of transmission or reception.

> b) If data is received during the broadcast communication for the next frame while the FIFO buffer is full due to the reception of the previous frame and the data has not been read, the IEBBnISR.IEBBnFOVE and IEBBnESR.IEBBnOVRE bits are set (to 1) at the same time.

- c) IEBBTV occurs based on the same conditions and at the same timing as IEBBTSTA. (For details, see Table 22-40 ACK/NACK for IEBBnETRF and IEBBnEFMF.) For individual communication:

   1. Transmission-side device

## IEBBnETRF:

- This is set (to 1) after receiving the ACK signal. If the NACK signal is received, communication does not end.

IEBBnEFMF: This is set (to 1) after reception regardless of the ACK/NACK signal.

2. Reception-side device

## IEBBnETRF:

This is set (to 1) after transmitting the ACK signal. If the NACK signal is transmitted, communication does not end.

## IEBBnEFMF:

This is set (to 1) after transmission regardless of the ACK/NACK signal.

The NACK signal is output when there is no room in the reception FIFO buffer or when there is a data retransmission request due to a parity mismatch. Not returning an ACK signal to the reception side as the bus status after exiting communications due to the detection of an error does not constitute a NACK signal. In this case, IEBBTSTA and IEBBTV do not occur because the system does not enter the frame completion status.

## For broadcast communication:

For broadcast communication, no ACK signal is returned from the slave. Therefore, it is judged that the NACK signal was successfully returned regardless of master transmission or slave reception, and the IEBBnETRF or IEBBnEFMF interrupt occurs.

- d) This occurs when the conditions specified by the IEBBnTMS.IEBBnSLTI1 and IEBBnSLTI0 bits are satisfied. The occurrence timing is after receiving the ACK signal, which follows data field transmission. However, if the transfer size is one byte or the received control bit is a status request (0H, 4H, 5H, or 6H), IEBBTD does not occur.

- e) 1. Transmission-side device

RDREQ is not set under this condition.

2. Reception-side device

- RDREQ is set (to 1) when the conditions specified by the IEBBnTMS.IEBBnSLRI1 and IEBBnSLRI0 bits are satisfied (after confirming that a normal parity bit value has been received).

If there is a parity bit mismatch, RDREQ is not set (to 1) because the conditions are not satisfied.

On normal completion or frame completion, RDREQ interrupt sources are masked.

**Table 22-40 ACK/NACK for IEBBnETRF and IEBBnEFMF**

|**Field status**|**Individual communication**|**Individual communication**|**Individual communication**|**Individual communication**|**Broadcast communication**|**Broadcast communication**|**Broadcast communication**|**Broadcast communication**|
|---|---|---|---|---|---|---|---|---|
||**IEBBnETRF**||**IEBBnEFMF**||**IEBBnETRF**||**IEBBnEFMF**||
||**ACK**|**NACK**|**ACK**|**NACK**|**ACK**|**NACK**|**ACK**|**NACK**|
|Master<br>transmission|Occurs|Does not<br>occur|Occurs|Occurs||Occurs||Occurs|
|Master reception|Occurs|Does not<br>occur|Occurs|Occurs|||||
|Slave<br>transmission|Occurs|Does not<br>occur|Occurs|Occurs|||||
|Slave reception|Occurs|Does not<br>occur|Occurs|Occurs||Occurs||Occurs|

Note The IEBBTV usage method is shown below.

1. Generating IEBBTV before communication finishes (when the IEBBnTMS.IEBBnSLRI1 and IEBBnSLRI0 bit settings are 32 bytes or less) This operation is not generally performed in communication mode 1. (It can be performed but is not.) The operation is performed in communication mode 2.

   - Use IEBBTV to check the number of data bytes received by the FIFO buffer, and then perform a readout operation. (Be sure to check the number because the IEBBTV interrupt servicing is assumed to be late.)

   - For IEBBTSTA (communication completion/frame completion), check the status.

   - Because the status is changed after receiving data, the interrupt priority is IEBBTV followed by IEBBTSTA.

2. If not generating IEBBTV during communication (if the IEBBnSLRI1 and IEBBnSLRI0 bit settings are 32 bytes)

Use communication mode 1. (Communication mode 2 can also be used.)

– Communication mode 1

Mask IEBBTV (so it is not used). Use IEBBTSTA (communication completion/frame completion) to check the number of data bytes in the FIFO buffer, and then check the readout and status changes.

– Communication mode 2

Perform the same operations as in 1.

## 22.4.2 Interrupt judgment examples

Interrupt judgment examples for the single mode are shown below.

## (1) When using IEBBTD

IEBBn transmission/reception must be checked by issuing an IEBBTD interrupt.

**==> picture [455 x 239] intentionally omitted <==**

**----- Start of picture text -----**<br>
IEBBTD occurs.<br>Check the  1<br>IEBBnISR.IEBBnIEBE bit.<br>0<br>Error processing<br>Master or slave transmission<br>No<br>IEBBnFS.IEBBnSSFS0<br>bit = 1?<br>Yes<br>Transmission write<br>Reception read processing<br>processing<br>**----- End of picture text -----**<br>

## **Figure 22-9 IEBBTD interrupt judgment example**

Caution Even if IEBBTD occurs, an error might occur depending on when the interrupt is handled.

Such errors include timing errors after IEBBTD occurs. To increase data processing reliability, only handle data after using the IEBBnISR.IEBBnIEBE bit to make sure that no error has occurred.

## (2) When using IEBBTERR

**==> picture [455 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
IEBBTERR occurs.<br>Read the IEBBnESR register<br>and use flags for judgment.<br>Error processing<br>**----- End of picture text -----**<br>

**Figure 22-10 IEBBTERR interrupt judgment example**

## (3) When using IEBBTSTA or  IEBBTV

**==> picture [455 x 521] intentionally omitted <==**

**----- Start of picture text -----**<br>
IEBBTSTA, IEBBTV occurs.<br>Read the IEBBnISR register.<br>Only when IEBBTV occurs (same processing as when IEBBTERR occurs)<br>Error source judgment<br>IEBBnIEBE flag IEBBnESR register read<br>Communication error judgment<br>IEBBnTIME flag<br>IEBBnPARE flag<br>IEBBnNACE flag<br>IEBBnUNRE flag<br>IEBBnOVRE flag<br>IEBBnABTE flag<br>IEBBnSTRF flag IEBBnUSR register read<br>Contention loss judgment<br>Start interrupt judgment<br>Additional master<br>IEBBnARBF flag<br>processing<br>IEBBnSRQF flag<br>Slave request judgment<br>Status transmission processing<br>IEBBnSTSF flag IEBBnSSR register read<br>Status transmission judgment<br>Write the IEBBnSSR register<br>0H,6H<br>value to the IEBBnDR register.<br>Write the lower 8-bit value of the<br>4H<br>IEBBnPAR register to the IEBBnDR register.<br>5H Write the higher 8-bit value of the<br>IEBBnPAR register to the IEBBnDR register.<br>IEBBnETRF flag<br>Communication end judgment<br>IEBBnEFMF flag<br>Frame end judgment<br>**----- End of picture text -----**<br>

**Figure 22-11 IEBBTSTA and IEBBTV interrupt judgment examples**

## 22.5 Operation

## 22.5.1 FIFO

## (1) Transmission FIFO buffer

When the IEBBnTMS.IEBBnFMDE bit = 1, data can be stored in the FIFO buffer while automatically incrementing the FIFO buffer pointer for writing by continuously writing transmission data to the IEBBnDR register. The FIFO buffer size is 8 bits x 32 stages.

When the transfer is started, the data indicated by the load pointer is transferred. After the transfer finishes, the load pointer is incremented. The initial value for the write pointer and load pointer is 0.

The IEBBnBSR.IEBBnTFLF bit is set (to 1) when there are 32 bytes of data in the FIFO buffer, and the transmission FIFO buffer overwrite flag

(IEBBnBSR.IEBBnFOVW) is set (to 1) when a 33rd byte of data is written while the IEBBnTFLF bit = 1. At this time, the write data is ignored and the write pointer is not changed.

The data below can be written when one byte is transferred while the IEBBnTFLF bit = 1 and then the bit is cleared to 0.

If the write is not in time for data loading, an underrun error occurs.

**==> picture [455 x 275] intentionally omitted <==**

**----- Start of picture text -----**<br>
7 0<br>31<br>Write pointer<br>0 Load pointer<br>Transmission FIFO buffer<br>**----- End of picture text -----**<br>

**Figure 22-12 Transmission FIFO buffer**

## (2) Reception FIFO buffer

When the IEBBnTMS.IEBBnFMDE bit = 1, the received data is stored at the address indicated by the storage pointer. The storage pointer is incremented after storing the data. Data is stored in the FIFO buffer at the end of the data field parity period if the parity value is normal. The FIFO buffer size is 8 bits x 32 stages.

By reading the IEBBnDR register, the data in the FIFO buffer can be read while automatically incrementing the read pointer. The initial value for the read pointer and storage pointer is 0.

If there are 32 bytes of unread data in the FIFO buffer, the operation when the next data is received is as follows.

- During individual communication: No data is stored, a NACK signal is returned, and data retransmission is requested.

- During broadcast communication: No data is stored and an overrun error occurs.

If the IEBBnDR register is read again after reading the received data that has been stored finishes (when the read pointer = the storage pointer), the read pointer is not changed, and the over-read flag (IEBBnBSR.IEBBnFOVR bit) is set (to 1).

**==> picture [455 x 281] intentionally omitted <==**

**----- Start of picture text -----**<br>
7 0<br>31<br>Store pointer<br>0 Read pointer<br>Reception FIFO buffer<br>**----- End of picture text -----**<br>

**Figure 22-13 Reception FIFO buffer**

## 22.5.2 Initial settings

After setting the IEBBnBCR.IEBBnPW bit to 1, set up the registers below, and then start communication processing.

## **Table 22-41 Initial setup**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnPSR|Operation clock and communication mode settings|80H|
|IEBBnUAR|Set a unit address.|101H|
|IEBBnCKS|Clock Selection|15H|
|IEBBnTMS|Communication control|01Ha|

> a) For use in the single mode, the initial values do no have to be changed.

## 22.5.3 Master transmission (single mode)

The unit transmits data and commands to the slave unit as the master.

Data interrupts are used to write transmission data to the IEBBnDR register for each one-byte transfer.

## (1) Register settings

After specifying the initial settings in 22.5.2 Initial settings , set up the registers below before starting communication.

## **Table 22-42 Standard initial processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnSAR|Communication partner unit address|102H|
|IEBBnCDR or IEBBnTCD|Control data (AH, BH, EH, FH)|FH|
|IEBBnDLR|Message length|02H|
|IEBBnDR|Data (1st byte of data)|11H|

## **Table 22-43 Communication startup processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnBCR|Communication startup processing|C8H|

## (2) Interrupt occurrence timing

**==> picture [455 x 160] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A Data 2 P A ... Data n P A<br>Transmission<br>Start interrupt<br>IEBBTSTA end interrupt<br>Transmission<br>IEBBTV Start interrupt end interrupt<br>Data interrupt<br>IEBBTD<br>Note<br>No data interrupt occurs<br>because this is frame end data.<br>**----- End of picture text -----**<br>

**Figure 22-14 Interrupt occurrence timing**

- (3) Interrupt servicing examples

- (a) Start interrupt CPU processing flow example

**==> picture [455 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Additional master<br>Contention judgment Note<br>request processing<br>During master operation, because the slave transmission enable<br>flag (IEBBnBCR.IEBBnSTXE) must be cleared to 0 (to prohibit<br>transmission), the slave operation processing here is slave<br>Slave operation  reception processing.<br>Slave request judgment<br>processing<br>**----- End of picture text -----**<br>

**Figure 22-15 Start interrupt CPU processing flow example**

(b) Transmission completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example

**==> picture [455 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Communication end  Communication end<br>Note<br>judgment processing<br>For frame end judgment, if it was not possible to transmit a message<br>length worth of data within one frame, perform communication to<br>retransmit or continue transmitting data during the next communication<br>Additional communication  frame.<br>Frame end judgment<br>processing<br>**----- End of picture text -----**<br>

**Figure 22-16 Transmission completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example**

- (c) Data interrupt CPU processing example

**==> picture [455 x 77] intentionally omitted <==**

**----- Start of picture text -----**<br>
Note<br>Processing to write the next  Write transmission data to the IEBBnDR register before the next<br>data to the IEBBnDR register data interrupt occurs.<br>If writing to this register is late, an underrun error occurs.<br>**----- End of picture text -----**<br>

**Figure 22-17 Data interrupt CPU processing**

## 22.5.4 Master transmission (FIFO mode)

The unit transmits data and commands to the slave unit as the master.

Transmission data is written into the buffer in advance, and then a master request is issued.

## (1) Register settings

After specifying the initial settings in 22.5.2 Initial settings , set up the registers below before starting communication.

## **Table 22-44 Standard initial processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnSAR|Communication partner unit address|102H|
|IEBBnCDR or IEBBnTCD|Control data (AH, BH, EH, FH)|FH|
|IEBBnTDL|Message length|02H|
|IEBBnDR|Data (all data to be transmitted)|11H, …|

## **Table 22-45 Communication startup processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnBCR|Communication startup processing|C8H|

## (2) Interrupt occurrence timing

**==> picture [455 x 145] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A ... Data m P A ... Data n P A<br>Transmission<br>end interrupt<br>IEBBTSTA<br>Note   No start interrupt occurs. Transmission<br>end interrupt<br>IEBBTV<br>IEBBTD<br>Note Note   A data interrupt occurs at the timing specified by<br>No data interrupt occurs.           the IEBBnTMS.IEBBnSLTI1 and IEBBnSLTI0 bits.<br>**----- End of picture text -----**<br>

**Figure 22-18 Interrupt occurrence timing**

## (3) Interrupt servicing examples

(a) Transmission completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example

**==> picture [455 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Communication end  Communication end<br>judgment processing Note<br>For frame end judgment, if it was not possible to transmit a message<br>length worth of data within one frame, perform communication to<br>retransmit or continue transmitting data during the next communication<br>Additional communication  frame.<br>Frame end judgment<br>processing<br>**----- End of picture text -----**<br>

**Figure 22-19 Transmission completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example**

## 22.5.5 Master reception (single mode)

The unit receives data and commands from the slave unit as the master. Because the slave transfers the message length field in the case of master reception, indicate the message length of data to be transmitted to the slave, such as during other communication. Read the received data one byte at a time by using data interrupts.

## (1) Register settings

After specifying the initial settings in 22.5.2 Initial settings , set up the registers below before starting communication.

## **Table 22-46 Standard initial processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnSAR|Communication partner unit address|102H|
|IEBBnCDR or IEBBnTCD|Control data (0H, 3H, 4H, 5H, 6H, 7H)|7H|

## **Table 22-47 Communication startup processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnBCR|Communication startup processing|C8H|

## (2) Interrupt occurrence timing

**==> picture [455 x 119] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A Data 2 P A ... Data n P A<br>Reception end<br>Start interrupt<br>IEBBTSTA interrupt<br>Reception end<br>IEBBTV Start interrupt interrupt<br>IEBBTD Data interrupt<br>**----- End of picture text -----**<br>

**Figure 22-20 Interrupt occurrence timing**

- (3) Interrupt servicing examples

**==> picture [455 x 137] intentionally omitted <==**

**----- Start of picture text -----**<br>
(a) Start interrupt CPU processing flow example<br>Error occurrence judgment Error processing<br>Contention judgment Additional master  Note<br>request processing During master operation, because the slave transmission enable<br>flag (IEBBnBCR.IEBBnSTXE) must be cleared to 0 (to prohibit<br>transmission), the slave operation processing here is slave<br>Slave operation  reception processing.<br>Slave request judgment<br>processing<br>**----- End of picture text -----**<br>

**Figure 22-21 Start interrupt CPU processing flow example**

- (b) Reception completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example

**==> picture [455 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Communication end  Communication end<br>judgment processing Note<br>For frame end judgment, if it was not possible to transmit a message<br>length worth of data within one frame, perform communication to<br>retransmit or continue transmitting data during the next communication<br>Additional communication  frame.<br>Frame end judgment<br>processing<br>**----- End of picture text -----**<br>

**Figure 22-22 Reception completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example**

- (c) Data interrupt CPU processing example

**==> picture [455 x 75] intentionally omitted <==**

**----- Start of picture text -----**<br>
Note<br>IEBBnDR register  The reception data must be read from the IEBBnDR register before<br>read processing the next data interrupt occurs. If reading this register is late, the<br>hardware transmits a NACK signal during separate communication<br>that prompts retransmission. Master reception is prohibited during<br>broadcast communication.<br>**----- End of picture text -----**<br>

**Figure 22-23 Data interrupt CPU processing**

## 22.5.6 Master reception (FIFO mode)

The unit receives data and commands from the slave unit as the master. Because the slave transfers the message length field in the case of master reception, indicate the message length of data to be transmitted to the slave, such as during other communication.

## (1) Register settings

After specifying the initial settings in 22.5.2 Initial settings , set up the registers below before starting communication.

## **Table 22-48 Standard initial processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnSAR|Communication partner unit address|102H|
|IEBBnCDR or IEBBnTCD|Control data (0H, 3H, 4H, 5H, 6H, 7H)|7H|

## **Table 22-49 Communication startup processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnBCR|Communication startup processing|C8H|

## (2) Interrupt occurrence timing

**==> picture [455 x 133] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A ... Data m P A ... Data n P A<br>Reception end<br>interrupt<br>IEBBTSTA<br>Note   No start interrupt occurs. Note   A data interrupt occurs at the timing specified by  Reception end<br>IEBBTV           the IEBBnTMS.IEBBnSLTI1 and IEBBnSLTI0 bits. interrupt<br>IEBBTD<br>Note<br>No data interrupt occurs.<br>**----- End of picture text -----**<br>

**Figure 22-24 Interrupt occurrence timing**

- (3) Interrupt servicing examples

- (a) Reception completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example

**==> picture [455 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Communication end  Communication end<br>judgment processing Note<br>For frame end judgment, if it was not possible to transmit a message<br>length worth of data within one frame, perform communication to<br>retransmit or continue transmitting data during the next communication<br>Additional communication  frame.<br>Frame end judgment<br>processing<br>**----- End of picture text -----**<br>

**Figure 22-25 Reception completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example**

## 22.5.7 Slave transmission (single mode)

The unit transfers data and commands to the master unit as a slave.

Data interrupts are used to write transmission data to the IEBBnDR register for each one-byte transfer.

## (1) Register settings

After specifying the initial settings in 22.5.2 Initial settings , set up the registers below before starting communication.

## **Table 22-50 Standard initial processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnDLR|Message length (other than during slave status transmission)|02H|
|IEBBnDR|Data (1st byte of data)|11H|

Caution When starting slave transmission, information such as the value to be set to the message length register (IEBBnDLR) and which data is to be returned (the value to be set to the IEBBnDR register) must be assigned in advance by the master, such as during separate communication.

## **Table 22-51 Communication startup processing**

**==> picture [455 x 233] intentionally omitted <==**

**----- Start of picture text -----**<br>
Register name Function  Example<br>IEBBnBCR Communication startup processing  90H<br>(2) Interrupt occurrence timing<br>(a) When the control bit 3H or 7H, which is addressed to the unit, is received<br>Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A Data 2 P A ... Data n P A<br>Transmission<br>IEBBTSTA Start interrupt end interrupt<br>Transmission<br>IEBBTV Start interrupt end interrupt<br>Data interrupt<br>IEBBTD<br>Note<br>No data interrupt occurs<br>because this is frame end data.<br>**----- End of picture text -----**<br>

**Figure 22-26 When the control bit 3H or 7H, which is addressed to the unit, is received**

- (b) When the control bit 0H or 6H, which is addressed to the unit, is received (or when 4H or 5H is received from the locked master while the unit is locked)

|||||||||||||Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||IEBBTSTA<br>IEBBTV<br>IEBBTD|||||||||||Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|||||||
|||Start interrupt<br>Start<br>Broad<br>cast<br>M address P<br>P <br>S address|Start|Broad<br>cast|M address|P|S address|P|A|Control|P|A|Message<br>length|<br>P|A|Data 1|P|A|
|||||||||||||Status transmissi||||on interrupt|||
|||Start interrupt||||||||||Status transmissi||||on interrupt|||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||

## **Figure 22-27 When the control bit 0H or 6H, which is addressed to the unit, is received (or when 4H or 5H is received from the locked master while the unit is locked)**

- (c) When the control bit 0H, 4H, or 5H, which is addressed to the unit, is received from a unit other than the locked master while the unit is locked

|||||||||||||Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||IEBBTSTA<br>IEBBTV<br>IEBBTD|||||||||||Status transmission interrupt<br>Status transmission interrupt<br>Transmission end<br>interrupt<br>Transmission end<br>interrupt<br>Message<br>length<br>Data 1<br>P A<br> A<br>P A<br>Status processing must be performed during this period.|||||||
|||Start interrupt<br>Start<br>Broad<br>cast<br>M address P<br>P <br>S address|Start|Broad<br>cast|M address|P|S address|P <br>|A|Control|P|A|Message<br>length|<br>P|A|Data 1|P|A|
|||||||||||||Status transmissi||||on interrupt|||
|||Start interrupt||||||||||Status transmissi||||on interrupt|||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||

- **Figure 22-28 When the control bit 0H, 4H, or 5H, which is addressed to the unit, is received from a unit other than the locked master while the unit is locked**

- (3) Interrupt servicing examples

- (a) Start interrupt CPU processing flow example

**==> picture [455 x 98] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Slave request judgment Slave operation processing<br>**----- End of picture text -----**<br>

**Figure 22-29 Start interrupt CPU processing flow example**

- (b) Transmission completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example

**==> picture [455 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Communication end  Communication end<br>judgment processing Note<br>Determine if a message length worth of data could be transmitted<br>within one frame by using frame end judgment. If transmission of a<br>message length worth of data has finished correctly, the subsequent<br>Frame end judgment Frame end processing communications depend on the master processing.<br>**----- End of picture text -----**<br>

**Figure 22-30 Transmission completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example**

- (c) Slave status transmission request processing flow example

**==> picture [455 x 153] intentionally omitted <==**

**----- Start of picture text -----**<br>
Status transmission processing:<br>Error occurrence judgment Error processing The following processing must be performed depending on the<br>received control data (the value read from the (IEBBnCDR register).<br>0H, 6H reception: Write the value read from the IEBBnSSR register<br>to the IEBBnDR register.<br>Status transmission  Status transmission<br>4H reception:        Write the lower 8 bits of the value read from the<br>request judgment processing<br>IEBBnPAR register to the IEBBnDR register.<br>5H reception:        Write the higher 8 bits of the value read from the<br>IEBBnPAR register to the IEBBnDR register.<br>Note<br>Status data must be written to the IEBBnDR register before the end<br>of the message length field. If writing to this register is late, the status<br>data is not transmitted, and the previous IEBBnDR register value is<br>transmitted.<br>**----- End of picture text -----**<br>

**Figure 22-31 Slave status transmission request processing flow**

- (d) Data interrupt CPU processing example

**==> picture [455 x 77] intentionally omitted <==**

**----- Start of picture text -----**<br>
Note<br>Processing to write the next  Write transmission data to the IEBBnDR register before the next<br>data to the IEBBnDR register data interrupt occurs.<br>If writing to this register is late, an underrun error occurs.<br>**----- End of picture text -----**<br>

**Figure 22-32 Data interrupt CPU processing**

## 22.5.8 Slave transmission (FIFO mode)

The unit transfers data and commands to the master unit as a slave.

Write the transmission data to the buffer in advance.

## (1) Register settings

After specifying the initial settings in 22.5.2 Initial settings , set up the registers below before starting communication.

## **Table 22-52 Standard initial processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnTDL|Message length (other than during slave status transmission)|02H|
|IEBBnDR|Data (all data to be transmitted)|11H, …|

Caution When starting slave transmission, information such as the value to be set to the message length register (IEBBnTDL) and which data is to be returned (the value to be set to the IEBBnDR register) must be assigned in advance by the master, such as during separate communication.

## **Table 22-53 Communication startup processing**

**==> picture [455 x 220] intentionally omitted <==**

**----- Start of picture text -----**<br>
Register name Function  Example<br>IEBBnBCR Communication startup processing  90H<br>(2) Interrupt occurrence timing<br>(a) When the control bit 3H or 7H, which is addressed to the unit, is received<br>Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A ... Data m P A ... Data n P A<br>Transmission<br>IEBBTSTA end interrupt<br>Note   No start interrupt occurs. Transmission<br>end interrupt<br>IEBBTV<br>IEBBTD<br>Note Note   A data interrupt occurs at the timing specified by<br>No data interrupt occurs.           the IEBBnTMS.IEBBnSLTI1 and IEBBnSLTI0 bits.<br>**----- End of picture text -----**<br>

**Figure 22-33 When the control bit 3H or 7H, which is addressed to the unit, is received**

- (b) When the control bit 0H or 6H, which is addressed to the unit, is received (or when 4H or 5H is received from the locked master while the unit is locked)

**==> picture [455 x 128] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A<br>Transmission<br>end interrupt<br>IEBBTSTA<br>Note   No start interrupt occurs. Transmission<br>end interrupt<br>IEBBTV<br>Note   No status transmission<br>IEBBTD           interrupt occurs.<br>**----- End of picture text -----**<br>

## **Figure 22-34 When the control bit 0H or 6H, which is addressed to the unit, is received (or when 4H or 5H is received from the locked master while the unit is locked)**

- (c) When the control bit 0H, 4H, or 5H, which is addressed to the unit, is received from a unit other than the locked master while the unit is locked

**==> picture [455 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A<br>Transmission<br>IEBBTSTA end interrupt<br>Note   No start interrupt occurs. Transmission<br>end interrupt<br>IEBBTV<br>Note   No status transmission<br>IEBBTD           interrupt occurs.<br>**----- End of picture text -----**<br>

**Figure 22-35 When the control bit 0H, 4H, or 5H, which is addressed to the unit, is received from a unit other than the locked master while the unit is locked**

## (3) Interrupt servicing examples

- (a) Transmission completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example

**==> picture [455 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Communication end  Communication end<br>judgment processing Note<br>Determine if a message length worth of data could be transmitted<br>within one frame by using frame end judgment. If transmission of a<br>message length worth of data has finished correctly, the subsequent<br>communications depend on the master processing.<br>Frame end judgment Frame end processing<br>**----- End of picture text -----**<br>

**Figure 22-36 Transmission completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example**

(b) Slave status transmission request processing flow example

**==> picture [455 x 153] intentionally omitted <==**

**----- Start of picture text -----**<br>
Status transmission processing:<br>Error occurrence judgment Error processing The following processing must be performed depending on the<br>received control data (the value read from the (IEBBnCDR register).<br>0H, 6H reception: Write the value read from the IEBBnSSR register<br>to the IEBBnDR register.<br>Status transmission  Status transmission<br>4H reception:        Write the lower 8 bits of the value read from the<br>request judgment processing<br>IEBBnPAR register to the IEBBnDR register.<br>5H reception:        Write the higher 8 bits of the value read from the<br>IEBBnPAR register to the IEBBnDR register.<br>Note<br>Status data must be written to the IEBBnDR register before the end<br>of the message length field. If writing to this register is late, the status<br>data is not transmitted, and the previous IEBBnDR register value is<br>transmitted.<br>**----- End of picture text -----**<br>

**Figure 22-37 Slave status transmission request processing flow**

In the FIFO mode, if the unit loses a conflict between a unit master transmission request and a slave transmission request addressed to the unit, because the slave transmission enable flag (IEBBnBCR.IEBBnSTXE) is not set (to 1) for the unit, a NACK signal is transmitted using the control data field and communication ends. Next, specify the slave transmission data for the FIFO buffer, set the slave transmission enable flag (to 1), and prepare to receive another slave transmission request from the master.

## 22.5.9 Slave reception (single mode)

The unit receives data and commands from the master unit as a slave.

Read the received data one byte at a time by using data interrupts.

## (1) Register settings

After specifying the initial settings in 22.5.2 Initial settings , set up the registers below before starting communication.

## **Table 22-54 Communication startup processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnBCR|Communication startup processing|88H|

## (2) Interrupt occurrence timing

**==> picture [455 x 119] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A Data 2 P A ... Data n P A<br>Reception end<br>IEBBTSTA Start interrupt interrupt<br>Reception end<br>IEBBTV Start interrupt interrupt<br>IEBBTD Data interrupt<br>**----- End of picture text -----**<br>

**Figure 22-38 Interrupt occurrence timing**

**==> picture [150 x 11] intentionally omitted <==**

**----- Start of picture text -----**<br>
(3) Interrupt servicing examples<br>**----- End of picture text -----**<br>

- (a) Start interrupt CPU processing flow example

**==> picture [455 x 100] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Slave request judgment Slave operation processing<br>**----- End of picture text -----**<br>

**Figure 22-39 Start interrupt CPU processing flow example**

- (b) Reception completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example

**==> picture [455 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
Error occurrence judgment Error processing<br>Communication end  Communication end<br>judgment processing Note<br>Determine if a message length worth of data could be received within<br>one frame by using frame end judgment. For example, if reception of a<br>message length worth of data has not finished, the subsequent<br>communications depend on the master processing.<br>Frame end judgment Frame end processing<br>**----- End of picture text -----**<br>

**Figure 22-40 Reception  completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example**

**==> picture [455 x 86] intentionally omitted <==**

**----- Start of picture text -----**<br>
(c) Data interrupt CPU processing example<br>Note<br>IEBBnDR register  The reception data must be read from the IEBBnDR register before<br>read processing the next data interrupt occurs. If reading this register is late, the<br>hardware transmits a NACK signal during separate communication<br>that prompts retransmission. An overrun error occurs during<br>broadcast communication.<br>**----- End of picture text -----**<br>

**Figure 22-41 Data interrupt CPU processing**

## 22.5.10 Slave reception (FIFO mode)

The unit receives data and commands from the master unit as a slave.

## (1) Register settings

After specifying the initial settings in 22.5.2 Initial settings , set up the registers below before starting communication.

## **Table 22-55 Communication startup processing**

|**Register name**|**Function**|**Example**|
|---|---|---|
|IEBBnBCR|Communication startup processing|88H|

## (2) Interrupt occurrence timing

**==> picture [455 x 340] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Broadcast M address P S address P A Control P A Message length P A Data 1 P A ... Data m P A ... Data n P A<br>Reception end<br>IEBBTSTA interrupt<br>Note   No start interrupt occurs. Note   A data interrupt occurs at the timing specified by  Reception end<br>          the IEBBnTMS.IEBBnSLTI1 and IEBBnSLTI0 bits. interrupt<br>IEBBTV<br>IEBBTD<br>Note<br>No data interrupt occurs.<br>Figure 22-42 Interrupt occurrence timing<br>(3) Interrupt servicing examples<br>(a) Reception completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow<br>example<br>Error occurrence judgment Error processing<br>Communication end  Communication end<br>judgment processing Note<br>Determine if a message length worth of data could be received within<br>one frame by using frame end judgment. For example, if reception of<br>a message length worth of data has not finished, the subsequent<br>Frame end judgment Frame end processing communications depend on the master processing.<br>**----- End of picture text -----**<br>

**Figure 22-43 Reception completion interrupt (IEBBTV, IEBBTSTA) CPU processing flow example**

## 22.6 Setup Procedures

22.6.1 Master transmission (single mode)

**==> picture [455 x 450] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 80H.<br>Set up the IEBBnSAR, IEBBnCDR<br>(or IEBBnTCD), IEBBnDLR, and<br>IEBBnDR (first byte of data) registers.<br>Set the IEBBnBCR register to C8H (separate communication)<br>: Master request<br>or the IEBBnBCR register to E8H (broadcast communication).<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: Start interrupt occurrence check<br>Yes<br>Start interrupt servicing<br>(See  22.5.3 (3)  “Interrupt servicing example” .)<br>Yes<br>Has IEBBTD occurred?<br>: Data interrupt occurrence check : Specify the 2nd<br>No Set up the IEBBnDR register.<br>  and following<br>  bytes of data.<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See  22.5.3 (3)  “Interrupt servicing example” .)<br>END<br>**----- End of picture text -----**<br>

**Figure 22-44 Master transmission (single mode)**

## 22.6.2 Master transmission (FIFO mode)

**==> picture [455 x 365] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 80H.<br>Set up the IEBBnSAR, IEBBnCDR<br>(or IEBBnTCD), IEBBnTDL, IEBBnDR<br>(data of 32 bytes or less) registers.<br>Set the IEBBnBCR register to C8H (separate communication)<br>: Master request<br>or the IEBBnBCR register to E8H (broadcast communication).<br>Yes<br>Has IEBBTD occurred?<br>: Write the<br>: Data interrupt occurrence check Write the transmission data to    transmission data<br>No<br>the IEBBnDR register.   remaining in the<br>  FIFO buffer in order.<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See  22.5.4 (3)  “Interrupt servicing example” .)<br>END<br>**----- End of picture text -----**<br>

**Figure 22-45 Master transmission (FIFO mode)**

## 22.6.3 Master reception (single mode)

**==> picture [455 x 446] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 80H.<br>Set up the IEBBnSAR, IEBBnCDR<br>(or IEBBnTCD) registers.<br>Set the IEBBnBCR register to C8H (separate communication)<br>: Master request<br>or the IEBBnBCR register to E8H (broadcast communication).<br>No<br>Has IEBBTSTA occurred<br>(IEBBTV)?<br>: Start interrupt occurrence check<br>Yes<br>Start interrupt servicing<br>(See  22.5.5 (3)  “Interrupt servicing example”. )<br>Yes<br>Has IEBBTD occurred?<br>: Data interrupt occurrence check<br>No Read the IEBBnDR register.<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See  22.5.5 (3)  “Interrupt servicing example”. )<br>END<br>**----- End of picture text -----**<br>

**Figure 22-46 Master reception (single mode)**

## 22.6.4 Master reception (FIFO mode)

**==> picture [455 x 366] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 80H.<br>Set up the IEBBnSAR, IEBBnCDR<br>(or IEBBnTCD) registers.<br>Set the IEBBnBCR register to C8H (separate communication)<br>: Master request<br>or the IEBBnBCR register to E8H (broadcast communication).<br>Yes<br>Has IEBBTV occurred?<br>: Read the reception<br>: Data interrupt occurrence check Read the reception data from<br>No   data remaining in the<br>the IEBBnDR register.<br>  FIFO buffer in order.<br>No<br>Has IEBBTSTA occurred?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See  22.5.6 (3)  “Interrupt servicing example”. )<br>END<br>**----- End of picture text -----**<br>

**Figure 22-47 Master reception (FIFO mode)**

## 22.6.5 Slave transmission (single mode)

- (1) When the control bit 3H or 7H is received

**==> picture [455 x 446] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 80H.<br>Set up the IEBBnDLR,<br>IEBBnDR (first byte of data) registers.<br>Set the IEBBnBCR register to 90H  : Slave transmission enable<br>(separate communication).<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: Start interrupt occurrence check<br>Yes<br>Start interrupt servicing<br>(See  22.5.7 (3)  “Interrupt servicing example”. )<br>Yes<br>Has IEBBTD occurred?<br>: Data interrupt occurrence check : Specify the 2nd<br>No Set up the IEBBnDR register.   and following<br>  bytes of data.<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See  22.5.7 (3)  “Interrupt servicing example”. )<br>END<br>**----- End of picture text -----**<br>

**Figure 22-48 Slave transmission (single mode): When the control bit 3H or 7H is received**

- (2) When the control bit 0H or 6H is received (or when 4H or 5H is received from the locked master while the unit is locked)

**==> picture [455 x 377] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 90H  : Slave transmission enable<br>(separate communication).<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: Start interrupt occurrence check<br>Yes<br>Start interrupt servicing<br>(See  22.5.7 (3)  “Interrupt servicing example” .)<br>Yes Status transmission<br>Has IEBBTSTA occurred?<br>processing<br>: Status interrupt occurrence check (See  22.5.7 (3)<br>No Set up the IEBBnDR register. “Interrupt servicing<br>example” .) [a]<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See  22.5.7 (3)  “Interrupt servicing example” .)<br>a)  When IEBBnTMS.IEBBnFMDEbit = 1, because<br>status transmission processing is performed by<br>hardware, no software processing is necessary.<br>END<br>**----- End of picture text -----**<br>

**Figure 22-49 Slave transmission (single mode): When the control bit 0H or 6H is received (or when 4H or 5H is received from the locked master while the unit is locked)**

- (3) When the control bit 0H, 4H, or 5H, which is addressed to the unit, is received from a unit other than the locked master while the unit is locked

**==> picture [455 x 305] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 90H  : Slave transmission enable<br>(separate communication).<br>Yes Status transmission<br>Has IEBBTSTA occurred? processing<br>(See  22.5.7 (3)<br>No : Status interrupt occurrence check Set up the IEBBnDR register. “Interrupt servicing<br>example” .) [a]<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See  22.5.7 (3)  “Interrupt servicing example” .) a)  When IEBBnTMS.IEBBnFMDEbit = 1, because<br>status transmission processing is performed by<br>hardware, no software processing is necessary.<br>    A status interrupt does not occur either.<br>END<br>**----- End of picture text -----**<br>

**Figure 22-50 Slave transmission (single mode): When the control bit 0H, 4H, or 5H, which is addressed to the unit, is received from a unit other than the locked master while the unit is locked**

## 22.6.6 Slave transmission (FIFO mode)

- (1) When the control bit 3H or 7H is received

**==> picture [455 x 366] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 80H.<br>Set up the IEBBnSAR, IEBBnTCD,<br>IEBBnTDL, IEBBnDR<br>(data of 32 bytes or less) registers.<br>Set the IEBBnBCR register to 90H  : Slave transmission enable<br>(separate communication).<br>Yes<br>Has IEBBTD occurred?<br>: Write the<br>Write the transmission data to    transmission data<br>No the IEBBnDR register.   remaining in the<br>  FIFO buffer in order.<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See 22.5.8 (3)  “Interrupt servicing example”.)<br>END<br>**----- End of picture text -----**<br>

**Figure 22-51 Slave transmission (FIFO mode): When the control bit 3H or 7H is received**

- (2) When the control bit 0H or 6H is received (or when 4H or 5H is received from the locked master while the unit is locked)

**==> picture [455 x 317] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 90H  : Slave transmission enable<br>(separate communication).<br>Yes Status transmission<br>Has IEBBTSTA occurred?<br>processing<br>(See 22.5.8 (3)<br>: Status interrupt occurrence check<br>No Set up the IEBBnDR register. “Interrupt servicing<br>example”.) [a]<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See 22.5.8 (3)  “Interrupt servicing example”.)<br>a)  When IEBBnTMS.IEBBnFMDEbit = 1, because<br>status transmission processing is performed by<br>hardware, no software processing is necessary.<br>END A status interrupt does not occur either.<br>**----- End of picture text -----**<br>

**Figure 22-52 Slave transmission (FIFO mode): When the control bit 0H or 6H is received (or when 4H or 5H is received from the locked master while the unit is locked)**

- (3) When the control bit 0H, 4H, or 5H, which is addressed to the unit, is received from a unit other than the locked master while the unit is locked

**==> picture [455 x 238] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 90H  : Slave transmission enable<br>(separate communication).<br>Yes Status transmission<br>Has IEBBTSTA occurred? processing<br>(See  22.5.8 (3)<br>: Status interrupt occurrence check<br>No Set up the IEBBnDR register. “Interrupt servicing<br>example” .) [a]<br>a)  When IEBBnTMS.IEBBnFMDEbit = 1, because<br>status transmission processing is performed by<br>END hardware, no software processing is necessary.<br>**----- End of picture text -----**<br>

**Figure 22-53 Slave transmission (FIFO mode): When the control bit 0H, 4H, or 5H, which is addressed to the unit, is received from a unit other than the locked master while the unit is locked**

## 22.6.7 Slave reception (single mode)

**==> picture [455 x 381] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 88H<br>:Slave reception enable<br>(separate communication).<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br> Start interrupt occurrence check<br>Yes<br>Start interrupt servicing<br>(See 22.5.9 (3)  “Interrupt servicing example”.)<br>Yes<br>Has IEBBTD occurred?<br>: Data interrupt occurrence check : Specify the 2nd<br>No Read the IEBBnDR register.   and following<br>  bytes of data.<br>Has IEBBTSTA  No<br>occurred (IEBBTV)?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See 22.5.9 (3)  “Interrupt servicing example”.)<br>END<br>**----- End of picture text -----**<br>

**Figure 22-54 Slave reception (single mode)**

## 22.6.8 Slave reception (FIFO mode)

**==> picture [455 x 300] intentionally omitted <==**

**----- Start of picture text -----**<br>
START<br>Set up the IEBBnPSR, IEBBnUAR,<br>: Initial settings<br>IEBBnCKS, and IEBBnTMS registers.<br>Set the IEBBnBCR register to 88H  : Slave reception enable<br>(separate communication).<br>Yes<br>Has IEBBTV occurred?<br>: Read the reception<br>Read the reception data from the<br>No   data stored in the<br>IEBBnDR register.<br>  FIFO buffer in order.<br>No<br>Has IEBBTSTA occurred?<br>: End interrupt occurrence check<br>Yes<br>End interrupt servicing<br>(See  22.5.10 (3)  “Interrupt servicing example” .)<br>END<br>**----- End of picture text -----**<br>

**Figure 22-55 Slave reception (FIFO mode)**

## 22.7 Functions

## 22.7.1 IEBus communication protocol

The communication protocol of the IEBus is as follows.

## (1) Multi-task mode

All the units connected to the IEBus can transfer data to the other units.

## (2) Broadcast communication

Communication between one unit and multiple units can be performed as follows.

- Group broadcast communication: Broadcast communication to group units

- All-unit broadcast communication: Broadcast communication to all units

## (3) Effective transmission speed

The effective transfer rate is in communication mode 1 or communication mode 2. (This product does not support mode 0 for the effective transfer rate.)

   - Communication mode 1: Approx. 18 kbps

   - Communication mode 2: Approx. 27 kbps

- Caution Different modes (communication mode 1, communication mode 2) must not be mixed on one IEBus.

## (4) Communication mode

Data transfer is executed in half-duplex asynchronous communication mode.

- (5) Access control: CSMA/CD (Carrier Sense Multiple Access with Collision Detection)

The priority of the IEBus is as follows:

   1. Broadcast communication takes precedence over individual communication (communication from one unit to another).

   2. The lower master address takes precedence.

- (6) Communication scale

The communication scale of IEBus is as follows:

- Number of units: 50 maximum

- Cable length: 150 m maximum (when twisted pair cable is used)

Caution The communication scale in an actual system differs depending on the characteristics of the cables, etc., constituting the IEBus driver/receiver and IEBus.

## 22.7.2 Determination of bus mastership (arbitration)

An operation to occupy the bus is performed when a unit connected to the IEBus controls the other units. This operation is called arbitration.

When multiple units simultaneously start transmission, arbitration is used to grant one of the units permission to occupy the bus.

Because only one unit is granted bus mastership as a result of arbitration, the priority conditions of the bus are predetermined as follows.

Caution Bus mastership is canceled if communication is aborted.

## (1) Priority by communication type

Broadcast communication (communication from one unit to multiple units) takes precedence over normal communication (communication from one unit to another).

## (2) Priority by master address

If the communication type is the same, communication with the lower master address takes precedence.

A master address consists of 12 bits, with unit 000H having the highest priority and unit FFFH having the lowest priority.

## 22.7.3 Communication mode

The IEBus has three communication modes, each of which has a different transfer rate. This module supports communication modes 1 and 2. The transfer rate and the maximum number of transfer bytes per communication frame in communication modes 1 and 2 are shown below.

**Table 22-56 Transfer rate and maximum number of transfer bytes in each communication mode**

|**Communication mode**|**Maximum number of**<br>**transfer bytes**<br>**(bytes/frame)**|**Effective transfer ratea**|
|---|---|---|
|1|32 bytes/frame|Approx. 18 kbps|
|2|128 bytes/frame|Approx. 27 kbps|

> a) Effective transfer rate when the maximum number of transfer bytes is transmitted

Select the communication mode for each unit connected to the IEBus before starting communication. If the communication mode of the master unit and that of the partner unit (slave unit) are not the same, communication is not correctly executed.

## 22.7.4 Communication address

For the IEBus, each unit is assigned a specific 12-bit address. This communication address consists of the following identification numbers.

- Higher 4 bits: Group number (number to identify the group to which each unit belongs)

- Lower 8 bits: Unit number (number to identify each unit in a group)

## 22.7.5 Broadcast communication

Normally, transmission or reception is performed between the master unit and its partner slave unit on a one-to-one basis. During broadcast communication, however, multiple slave units exist and the master unit executes transmission to these slave units. Because multiple slave units exist, the NACK signal is returned by the communicating slave unit as an acknowledge bit.

Whether broadcast communication or normal communication is to be executed is selected by the broadcast bit. (For details about this bit, see 22.7.6 (2) Broadcast bit .)

Broadcast communication is classified into two types: group-unit broadcast communication and all-unit broadcast communication. Group-unit broadcast and allunit broadcast are identified by the value of the slave address. (For the slave address, see 22.7.6 (4) Slave address field .)

## (1) Group-unit broadcast communication

Broadcast communication is performed to the units in a group identified by the group number indicated by the higher 4 bits of the communication address.

## (2) All-unit broadcast communication

Broadcast communication is performed to all the units, regardless of the value of the group number.

## 22.7.6 IEBus transfer format

The IEBus transfer signal format is shown in Figure 22-56 .

||||||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||Header<br>Master<br>address<br>field||Slave<br>address<br>field|||Control field|||Telegraph<br>length<br>field|||Data field|||||||
|Frame|format||Start<br>bit|Broad-<br>cast<br>bit<br>P<br>Master<br>address<br>bit|Slave<br>address<br>bit|P|A|Control<br>bit|P|A|Telegraph<br>length<br>bit<br>P|A|Data<br>bit|P|A||Data<br>bit|P|A||
|||Remarks 1.    P: Parity bit|||||||||||||||||||
|||||A: Acknowledge (ACK/NACK) bit|||||||||||||||||
|||||2.    The master unit ignores the||||acknowledge bit during broadcast communication.|||||||||||||

**Figure 22-56 IEBus transfer signal format**

## (1) Start bit

The start bit is a signal that informs the other units of the start of a data transfer.

The unit that is to start a data transfer outputs a low-level signal (start bit) for a specific time, and then starts outputting the broadcast bit.

If another unit has already output its start bit when one unit is to output the start bit, this unit does not output the start bit and instead waits for completion of output of the start bit by the other unit. When the output of the start bit by the other unit is complete, the unit starts outputting the broadcast bit in synchronization with the completion of the start bit output by the other unit.

The units other than the one that started communication detect this start bit, and enter the reception status.

## (2) Broadcast bit

This bit indicates whether the master selects one slave (individual communication) or multiple slaves (broadcast communication) as the other party of communication.

When the broadcast bit is 0, it indicates broadcast communication. When it is 1, individual communication is indicated. Broadcast communication is classified into two types: group-unit communication and all-unit communication. These communication types are identified by the value of the slave address. (For the slave address, see 22.7.6 (4) Slave address field .)

Because multiple slave units exist as a partner slave unit of communication in the case of broadcast communication, the NACK signal is returned as an acknowledge bit in each field subsequent to the master address field.

If multiple units start transmitting a communication frame at the same time, broadcast communication takes precedence over individual communication, and wins in arbitration.

If one unit occupies the bus as the master, the value set to the broadcast request flag (the IEBBnBCR.IEBBnALRQ bit) is output.

## (3) Master address field

The master address field is output by the master to inform a slave of the master’s address.

The configuration of the master address field is shown in Figure 22-57 .

If multiple units start transmitting the broadcast bit at the same time, the master address field makes a judgment of arbitration.

The master address field compares the data it outputs with the data on the bus each time it has output one bit. If the master address output by the master address field is found to differ from the data on the bus as a result of comparison, it is assumed that the master has lost arbitration.

As a result, the master stops transmission and enters the reception status. Because the IEBus is configured of wired AND, the unit having the smallest master address of the units participating in arbitration (arbitration masters) wins arbitration.

After a 12-bit master address has been output, only one unit remains in the transmission status as one master unit.

Next, this master unit outputs a parity bit, determines the master address of other unit, and starts outputting a slave address field.

If one unit occupies the bus as the master, the address specified by the IEBBnUAR register is output.

**==> picture [455 x 86] intentionally omitted <==**

**----- Start of picture text -----**<br>
Master address field<br>Master address (12 bits) Parity<br>MSB LSB<br>**----- End of picture text -----**<br>

**Figure 22-57 Master address field**

- (4) Slave address field

The master outputs the address of the unit with which it is to communicate.

The configuration of the slave address field is shown in Figure 22-58 .

A parity bit is output after a 12-bit slave address has been transmitted to prevent the wrong slave address from being received by mistake. Next, the master unit detects an ACK signal from the slave unit to confirm that the slave unit exists on the bus. The master unit starts outputting the control field after detecting the ACK signal. During broadcast communication, however, the master does not confirm the acknowledge bit and instead starts outputting the control field.

The slave unit outputs the ACK signal if its slave address matches and if the slave detects that the parities of both the master address and slave address are even. The slave unit judges that the master address or slave address has not been correctly received and outputs the NACK signal if the parities are odd. At this time, the master unit is in the standby (monitor) status, and communication ends.

During broadcast communication, the slave address is used to identify group-unit broadcast or all-unit broadcast, as follows:

If the slave address is FFFH: All-unit broadcast communication

If the slave address is not FFFH: Group-unit broadcast communication

Note The group No. during group-unit broadcasting communication is the value of the higher 4 bits of the slave address.

If one unit occupies the bus as the master, the address specified by the IEBBnSAR register is output.

**==> picture [455 x 94] intentionally omitted <==**

**----- Start of picture text -----**<br>
Slave address field<br>Slave address (12 bits) Parity ACK<br>Group No. Unit No.<br>MSB LSB<br>**----- End of picture text -----**<br>

**Figure 22-58 Slave address field**

## (5) Control data field

The master uses this field to output the operation it requires the slave to perform.

The configuration of the control field is shown in Figure 22-59 .

If the parity following the control bit is even and the slave unit can execute the function required by the master unit, the slave unit outputs an ACK signal and starts outputting the message length field. If the slave unit cannot execute the function required by the master unit even if the parity is even, or if the parity is odd, the slave unit outputs the NACK signal, and returns to the standby (monitor) status.

The master unit starts outputting the message length field after detecting the ACK signal.

If the master detects the NACK signal, the master unit enters the standby status, and communication ends. During broadcast communication, however, the master unit does not confirm the acknowledge bit and starts outputting the message length field.

If one unit occupies the bus as the master, the value set to the IEBBnTCD register is output.

**==> picture [455 x 79] intentionally omitted <==**

**----- Start of picture text -----**<br>
Control field<br>Control bit (4 bits) Parity ACK<br>MSB LSB<br>**----- End of picture text -----**<br>

**Figure 22-59 Control field**

The contents of the control bits are shown below.

## **Table 22-57 Control bit contents**

|**Bit 3a**|**Bit 2**|**Bit 1**|**Bit 0**|**Function**|
|---|---|---|---|---|
|0|0|0|0|Read slave status|
|0|0|0|1|Undefined|
|0|0|1|0|Undefined|
|0|0|1|1|Read data and lockb|
|0|1|0|0|Read lock address (lower 8 bits)c|
|0|1|0|1|Lock address reading (higher 4 bits)c|
|0|1|1|0|Slave status reading and unlockingb|
|0|1|1|1|Read data|
|1|0|0|0|Undefined|
|1|0|0|1|Undefined|
|1|0|1|0|Command writing and lockingb|
|1|0|1|1|Data writing and lockingb|
|1|1|0|0|Undefined|
|1|1|0|1|Undefined|
|1|1|1|0|Write command|
|1|1|1|1|Write data|

- a) The message length bit of the message length field and data transfer direction of the data field change as follows depending on the value of bit 3 (MSB).

   - If bit 3 is 1: Transfer from master unit to slave unit

   - If bit 3 is 0: Transfer from slave unit to master unit

- b) This is a control bit that specifies locking or unlocking. (For details, see 22.7.7 (4) Locking and unlocking.) c) The lock address is transferred in 1-byte (8-bit) units and is configured as follows:

|||MSB|||LSB||
|---|---|---|---|---|---|---|
|Control bit:|4H|Lower||8 bits|||
||||||||
|Control bit:|5H|Undefined||Higher 4 bits|||
||||||||

If the control bit received from the master unit is not as shown in Table 22-58 , the unit locked by the master unit rejects acknowledging the control bit, and outputs the NACK signal.

**Table 22-58 Control field for locked slave unit**

|**Bit 3**|**Bit 2**|**Bit 1**|**Bit 0**|**Function**|
|---|---|---|---|---|
|0|0|0|0|Read slave status|
|0|1|0|0|Lock address reading (lower 8 bits)|
|0|1|0|1|Lock address reading (higher 4 bits)|

In addition, units for which locking is not set up by the master unit reject acknowledgment and output a NACK signal when the control data shown in Table 22-59 is acknowledged.

**Table 22-59 Control field for unlocked slave unit**

|**Bit 3**|**Bit 2**|**Bit 1**|**Bit 0**|**Function**|
|---|---|---|---|---|
|0|1|0|0|Lock address reading (lower 8 bits)|
|0|1|0|1|Lock address reading (higher 4 bits)|

**Table 22-60 Control field ACK signal response conditions (when the received control data is 0H, 3H, 4H, 5H, 6H, or 7H)**

|**Communication**<br>**target**<br>**(IEBBnUSR.**<br>**IEBBnSRQF bit)**<br>**Slave**<br>**specification = 1**<br>**No specification**<br>**= 0**|**Lock status**<br>**(IEBBnUSR.**<br>**IEBBnLCKF bit)**<br>**Lock = 1**<br>**No lock = 0**|**Master unit**<br>**judgment**<br>**(IEBBnPAR**<br>**register match)**<br>**Lock request unit = 1**<br>**Other = 0**|**Slave**<br>**transmission**<br>**enabled**<br>**(IEBBnBCR.**<br>**IEBBnSTXE bit)**|**Slave**<br>**reception**<br>**enabled**<br>**(IEBBnBCR.**<br>**IEBBnSRXE**<br>**bit)**|**Received control data**|**Received control data**|**Received control data**|**Received control data**|**Received control data**|**Received control data**|
|---|---|---|---|---|---|---|---|---|---|---|
||||||**0H**|**3H**|**4H**|**5H**|**6H**|**7H**|
|1|0|don’t care|0|don’t care|A|N|N|N|A|N|
||||1||A|A|N|N|A|A|
||1|0|don’t care||A|N|A|A|N|N|
|||1|0||A|N|A|A|A|N|
||||1||A|A|A|A|A|A|
||Other than the above||||N||||||

- Note A: Slave transmission is performed. (The ACK signal is returned.)

   - N: Slave transmission is not performed. (The NACK signal is returned.)

Caution If the received control data is other than the data shown in the above table, N is unconditionally assumed. (Slave transmission is not performed (and the NACK signal is returned).)

**Table 22-61 Control field ACK signal response conditions (when the received control data is AH, BH, EH, or FH)**

|**Communication**<br>**target**<br>**(IEBBnUSR.**<br>**IEBBnSRQF bit)**<br>**Slave**<br>**specification = 1**<br>**No specification**<br>**= 0**|**Lock status**<br>**(IEBBnUSR.**<br>**IEBBnLCKF bit)**<br>**Lock = 1**<br>**No lock = 0**|**Master unit**<br>**judgment**<br>**(IEBBnPAR**<br>**register match)**<br>**Lock request unit = 1**<br>**Other = 0**|**Slave**<br>**transmission**<br>**enabled**<br>**(IEBBnBCR.**<br>**IEBBnSTXE bit)**|**Slave**<br>**reception**<br>**enabled**<br>**(IEBBnBCR.**<br>**IEBBnSRXE**<br>**bit)**|**Received control data**|**Received control data**|**Received control data**|**Received control data**|
|---|---|---|---|---|---|---|---|---|
||||||**AH**|**BH**|**EH**|**FH**|
|1|0|don’t care|don’t care|1|A||||
||1|1|||||||
||Other than the above||||N||||

- Note A: Slave transmission is performed. (The ACK signal is returned.)

N: Slave transmission is not performed. (The NACK signal is returned.)

Caution If the received control data is other than the data shown in the above table, N is unconditionally assumed. (Slave transmission is not performed (and the NACK signal is returned).)

## (6) Message length field

This field is output by the transmission side to inform the reception side of the number of bytes of the transmit data.

The configuration of the message length field is shown in Figure 22-60 .

Table 22-62 shows the relationship between the message length bit and the number of transmission data bytes.

**==> picture [455 x 79] intentionally omitted <==**

**----- Start of picture text -----**<br>
Telegraph length field<br>Telegraph length bit (8 bits) Parity ACK<br>MSB LSB<br>**----- End of picture text -----**<br>

**Figure 22-60 Message length field**

**Table 22-62 Contents of the message length bit**

|**Message length bit (hexadecimal)**|**Number of transmission data bytes**|
|---|---|
|01H|1 byte|
|02H|2 bytes|
|...|...|
|FFH|255 bytes|
|00H|256 bytes|

The operation of the message length field differs depending on whether the master transmits data (when control bit 3 is 1) or receives data (when control bit 3 is 0).

- (a) During master transmission

The message length bit and parity bit are output by the master unit and the synchronization signals of bits are output by the master unit. When the slave unit detects that the parity is even, it outputs the ACK signal, and starts outputting the data field. During broadcast communication, however, the slave unit outputs the NACK signal.

If the parity is odd, the slave unit judges that the message length bit has not been correctly received, outputs the NACK signal, and returns to the standby (monitor) status. At this time, the master unit also returns to the standby status, and communication ends.

## (b) Master reception

The message length bit and parity bit are output by the slave unit and the synchronization signals of bits are output by the master unit. If the master unit detects that the parity bit is even, it outputs the ACK signal.

If the parity bit is odd, the master unit judges that the message length bit has not been correctly received, outputs the NACK signal, and returns to the standby status. At this time, the slave unit also returns to the standby status, and communication ends.

## (7) Data field

This is data output by the transmission side.

The master unit transmits or receives data to or from a slave unit by using the data field.

The configuration of the data field is shown below.

**==> picture [455 x 87] intentionally omitted <==**

**----- Start of picture text -----**<br>
Data field (number specified by telegraph length field)<br>One data<br>Data bit (8 bits) Parity ACK Parity ACK<br>MSB LSB<br>**----- End of picture text -----**<br>

**Figure 22-61 Data field**

Following the data bit, the parity bit and acknowledge bit are output by the master unit and slave unit, respectively.

Use broadcast communication only when the master unit transmits data. At this time, the acknowledge bit is ignored.

The operation differs as follows depending on whether the master transmits or receives data.

## (a) During master transmission

When the master units writes data to a slave unit, the master unit transmits the data bit and parity bit to the slave unit. If the parity is even and the received data is not stored in the IEBBnDR register when the slave unit has received the data bit and parity bit, the slave unit outputs an ACK signal. If the parity is odd or the received data is stored in the IEBBnDR register, the slave unit rejects receiving the data, and outputs the NACK signal.

If the slave unit outputs the NACK signal, the master unit transmits the same data again. This operation continues until the master detects the ACK signal from the slave unit, or the data exceeds the maximum number of transmit bytes.

If there is more data and the maximum number of transmission bytes is not exceeded when the parity is even and when the slave unit outputs the ACK signal, the master unit transmits the next data.

During broadcast communication, the slave unit outputs the NACK signal, and the master unit transfers 1 byte of data at a time. If the parity is odd or the IEBBnDR register is storing received data after the slave unit receives the data bit and parity bit during broadcast communication, the slave unit judges that reception has not been performed correctly, and stops reception.

## (b) Master reception

When the master unit reads data from a slave unit, the master unit outputs a sync signal corresponding to all the read bits.

The slave unit outputs the contents of the data and parity bits to the bus in response to the sync signal from the master unit.

The master unit reads the data and parity bits output by the slave unit, and checks the parity.

If the parity is odd or the IEBBnDR register is storing received data, the master unit rejects accepting the data, and outputs the NACK signal. If the maximum number of transmission bytes is within the value that can be transmitted in one communication frame, the master unit rereads the same data.

If the parity is even and the IEBBnDR register is not storing received data, the master unit accepts the data and outputs the ACK signal. If the maximum number of transmission bytes is within the value that can be transmitted in one frame, the master unit reads the next data.

Caution

During broadcast communication, do not perform master reception. If you do this, the slave unit cannot be defined and data transfers cannot be performed correctly.

Note that, due to the IEBBn specifications, overrun errors can occur. Therefore, even if reading the IEBBnDR register is late during individual communication and the system has reached the timing for receiving the next data (the overrun status), data can be retransmitted from the master unit by returning a NACK signal, which makes it possible to buy time for reading the IEBBnDR register. However, during broadcast communication, because no ACK signal is output from the slave unit and the master unit ignores ACK signals, even if reading the IEBBnDR register is late, no data is retransmitted from the master. Therefore, for IEBBn, if an overrun occurs during broadcast communication, normal reception is not possible, an overrun error occurs, and an interrupt request (for a communication error) is output.

## (8) Parity bit

The parity bit is used to make sure that the transmission data has no error.

The parity bit is appended to each data of the master address, slave address, control, message length, and data bits.

The parity is an even parity. If the number of data bits that are ‘1’ is odd, the parity bit is ‘1’. If the number of data bits that are ‘1’ is even, the parity bit is ‘0’.

## (9) Acknowledge bit

During normal communication (communication from one unit to another), an acknowledge bit is appended to the following locations to check whether the data has been correctly received.

- End of slave address field

- End of control field

- End of message length field

- End of data field

The definition of the acknowledge bit is as follows.

- 0: The transmission data is recognized. (ACK signal)

- 1: The transmission data is not recognized. (NACK signal)

During broadcast communication, however, the contents of the acknowledge bit are ignored.

- (a) Last acknowledge bit of the slave address field

The last acknowledge bit of the slave address field serves as a NACK signal in any of the following cases, and transmission is stopped.

   - If the parity of the master address bit or slave address bit is incorrect

   - If a timing error (an error in the bit format) occurs

   - If a slave unit does not exist

- (b) Last acknowledge bit of the control field

The last acknowledge bit of the control field serves as a NACK signal in any of the following cases, and transmission is stopped.

- If the parity of the control bit is incorrect

- If control bit 3 is 1 (write operation) when the slave reception enable flag (the IEBBnBCR.IEBBnSRXE bit) is not set (to 1)

   - (For details, see 22.3.2 (1) IEBBnBCR - IEBBn bus control register .)

- If control bit data is read (3H, 7H) when the slave transmission enable flag (the IEBBnBCR.IEBBnSTXE bit) is not set (to 1)

(For details, see 22.3.2 (1) IEBBnBCR - IEBBn bus control register .)

- If a unit other than one that has set locking requests 3H, 6H, 7H, AH, BH, EH, or FH of the control bit when locking is set

- If the control bit indicates reading of lock addresses (4H, 5H) even when locking is not set

- If a timing error occurs

- If the control bit is undefined

- Cautions 1. The ACK signal is always returned when the control data of the slave status request is received, if the IEBBnSTXE bit = 0.

   2. The NACK signal is returned by the acknowledge bit in the control field when the control data for data/command writing is received, even if the IEBBnSRXE bit = 0.

Slave reception can be disabled (communication stopped) by the IEBBnSRXE bit only in the case of individual communication. In the case of broadcast communication, communication is maintained and the data interrupt (IEBBTD) or completion interrupt (IEBBTSTA) is generated.

## (c) Last acknowledge bit of message length field

The last acknowledge bit of the message length field serves as a NACK signal in any of the following cases, and transmission is stopped.

   - If the parity of the message length bit is incorrect

   - If a timing error occurs

- (d) Last acknowledge bit of the data field

The last acknowledge bit of the data field serves as a NACK signal in any of the following cases, and transmission is stopped.

- If the parity of the data bit is incorrect[a]

- If a timing error occurs after the preceding acknowledge bit has been transmitted

- If the received data is stored in the IEBBnDR register and no more data can be received[a]

- a) In this case, when the communication executed is individual communication, if the maximum number of transmit bytes is within the value that can be transmitted in one frame, the transmission side executes transmission of that data field again. For broadcast communication, the transmission side does not execute transmission again, a communication error occurs on the reception side and reception stops.

## 22.7.7 Transfer data

(1) Slave status

The master unit can learn why the slave unit did not return the ACK signal by reading the slave status.

The slave status is determined according to the result of the last communication the slave unit has executed.

All the slave units can supply information on the slave status.

The configuration of the slave status is shown below.

|<br> <br>|Bit 7<br>Transmit data is not written in IEBBnDR register<br>Transmit data is written in IEBBnDR register<br>Bit 0a<br>0<br>1<br>Function<br>Function<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0<br>MSB<br>LSB<br>Receive data is not stored in IEBBnDR register<br>Receive data is stored in IEBBnDR register<br>Bit 1<br>0<br>1<br>Unit is not locked<br>Unit is locked<br>Bit2<br>0<br>1<br>Function<br>Function<br>Function<br>Function<br>Function<br>Fixed to 0<br>Bit3<br>0<br>Fixed to 0<br>Bit5<br>0<br>Bit7<br>0<br>0<br>1<br>1<br>Communication mode 0<br>Communication mode 1<br>Communication mode 2<br>Not used<br>Indicates the highest communication<br>mode supported by the unitc.<br>a)After reset: Bit 0 is set to 1.<br>b)When this module serves as a slave unit, this bit corresponds to the<br>status indicated by IEBBnBCR.IEBBnSTXE bit.<br>c)Bits 7 and 6 are fixed to “10” because this module can support communication<br>modes 1 and 2.<br>Bit6<br>0<br>1<br>0<br>1<br>Slave transmission is stopped<br>Slave transmission is ready<br>Bit 4b<br>0<br>1|
|---|---|

**Figure 22-62 Slave status bit configuration**

## (2) Lock address

When the lock address is read (control bit: 4H or 5H), the address (12 bits) of the master unit that has issued the lock instruction is configured in 1-byte units as shown below and read.

**==> picture [455 x 87] intentionally omitted <==**

**----- Start of picture text -----**<br>
MSB LSB<br>Control bit: 4H Lower 8 bits<br>Control bit: 5H Undefined Higher 4 bits<br>**----- End of picture text -----**<br>

**Figure 22-63 Lock address configuration**

## (3) Data

If the control bit indicates reading of data (3H or 7H), the data in the data buffer of the slave unit is read by the master unit.

If the control bit indicates writing of data (BH or FH), the data received by the slave unit is processed according to the operation rule of that slave unit.

## (4) Locking and unlocking

The lock function is used when a message is transferred in two or more communication frames.

The unit that is locked does not receive data from units other than the one that has locked the unit (does not receive broadcast communication).

A unit is locked or unlocked as follows.

## (a) Lock setting

If the communication frame is completed without succeeding to transmit or receive data of the number of bytes specified by the message length bit after the message length field has been transmitted or received (ACK = 0) by the control bit that specifies locking (3H, AH, or BH), the slave unit is locked by the master unit. At this time, the bit (bit 2) in the byte indicating the slave status is set to ‘1’.

## (b) Unlocked

After transmitting or receiving data of the number of data bytes specified by the message length bit in one communication frame by the control bit that has specified locking (3H, AH, or BH), or the control bit that has specified unlocking (6H), the slave unit is unlocked by the master unit. At this time, the bit related to locking (bit 2) in the byte indicating the slave status is reset to ‘0’.

Locking or unlocking is not performed during broadcast communication.

Locking and unlocking conditions are shown below.

## **Table 22-63 Setting conditions:**

|**Control data**|**Broadcast communication**|**Broadcast communication**|**Individual communication**|**Individual communication**|
|---|---|---|---|---|
||**End of**<br>**communication**|**End of frame**|**End of**<br>**communication**|**End of frame**|
|3H, 6Ha|||Cannot be locked|Lock set|
|AH, BH|Cannot be locked|Cannot be locked|Cannot be locked|Lock set|
|0H, 4H, 5H, EH, FH|Cannot be locked|Cannot be locked|Cannot be locked|Cannot be locked|

> a) The frame end of control data 6H (slave status read/unlock) occurs when the parity in the data field is odd, and when the NACK signal from the IEBus unit is repeated with up to the maximum number of transfer bytes being output.

**Table 22-64 Unlocking conditions (while locked)**

|**Control data**|**Broadcast communication from the lock**<br>**request unit**|**Broadcast communication from the lock**<br>**request unit**|**Individual communication from the lock**<br>**request unit**|**Individual communication from the lock**<br>**request unit**|
|---|---|---|---|---|
||**End of**<br>**communication**|**End of frame**|**End of**<br>**communication**|**End of frame**|
|3H, 6Ha|||Unlocked|Remains locked|
|AH, BH|Unlocked|Unlocked|Unlocked|Remains locked|
|0H, 4H, 5H, EH, FH|Remains locked|Remains locked|Remains locked|Remains locked|

> a) The frame end of control data 6H (slave status read/unlock) occurs when the parity in the data field is odd, and when the NACK signal from the IEBus unit is repeated with up to the maximum number of transfer bytes being output.

## 22.7.8 Bit format

The format of the bits constituting the communication frame of the IEBus is shown below.

**==> picture [455 x 138] intentionally omitted <==**

**----- Start of picture text -----**<br>
Logic “1”<br>Logic “0”<br>Preparation Synchronization Data period Stop period<br>period period<br>Preparation period:   First low-level (logic “1”) period<br>Synchronization period:  Next high-level (logic “0”) period<br>Data period:   Period indicating value of bit<br>Stop period:   Last low-level (logic “1”) period<br>**----- End of picture text -----**<br>

**Figure 22-64 IEBus bit format**

The synchronization period and data period are almost equal to each other in length.

The IEBus synchronizes each bit. The specifications on the time of the entire bit and the time related to the period allocated to that bit differ depending on the type of transmit bit, or whether the unit is the master unit or a slave unit. The master and slave units monitor whether each period (preparation period, synchronization period, data period, and stop period) is output for the specified time while they are in communication. If a period is not output for the specified time, the master and slave units report a timing error, immediately terminate communication, and enter the standby status.
