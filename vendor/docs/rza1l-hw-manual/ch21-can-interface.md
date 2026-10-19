# 21. CAN Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 921–1084. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This section gives an overall description of the CAN interface (RS-CAN).

The first section describes the features specific to this LSI, including the number of units and the register base addresses. The subsequent sections describe the RS-CAN’s functions and registers.

## 21.1 Overview

## 21.1.1 Units

This microcontroller incorporates the following number of units of the CAN interface (RS-CAN).

## **Table 21.1 Units of RS-CAN**

||**RS-CAN**|
|---|---|
|Number of units|1|
|Name|RSCAN0|

## The RS-CAN has two channels.

## **Table 21.2 Channels of RS-CAN**

||**RS-CAN**|
|---|---|
|Number of channels|2|
|Name|CAN0, CAN1|

## **Table 21.3 Index**

|**Index**<br>**Meaning**|**Available Number of CAN**<br>**Channels and Index**|
|---|---|
||**2 channels**|
|n<br>Throughout this section, the unit of the RS-CAN is identified by the index<br>“n”: for example, RSCANnGCFG is the global configuration register in<br>the RS-CANn unit.|n = 0|
|m<br>Throughout this section, the individual channels in the RS-CAN units are<br>identified by the index “m”: for example, RSCAN0CmSTS is the channel<br>m status register in the RS-CAN0 unit.|m = 0 or 1|
|j<br>The individual receive rule table registers in the RS-CAN units are<br>identified by the index “j”: for example, RSCAN0GAFLIDj is the receive<br>rule ID register j in the RS-CAN0 unit.|j = 0 to 15|
|k<br>The individual transmit/receive FIFO in the RS-CAN units are identified<br>by the index “k” (k = 0 to channel m3 + 2): for example,<br>RSCAN0CFCCk is the transmit/receive FIFO buffer configuration and<br>control register k in the RS-CAN0 unit.|k = 0 to 5|
|q<br>The individual receive buffer in the RS-CAN units are identified by the<br>index “q” (q = 0 to channel m16 + 15): for example, RSCAN0RMIDq is<br>the receive buffer ID register q in the RS-CAN0 unit.|q = 0 to 31|
|p<br>The individual transmit buffers in the RS-CAN units are identified by the<br>index “p” (p = 0 to channel m16 + 15): for example, RSCAN0TMCp is<br>the transmit buffer control register p in the RS-CAN0 unit.|p = 0 to 31|
|y<br>When the registers other than above are collectively explained, they are<br>identified by the index “y” (y = 0): for example, RSCAN0RMNDy is the<br>receive buffer new data register in the RS-CAN0 unit.|y = 0|

## 21.1.2 Register addresses

RS-CAN base addresses are listed in the following table.

RS-CAN register addresses are given as offsets from the base addresses.

## **Table 21.4 Register base address**

|**Base Address Name**||**Base Address**|
|---|---|---|
|<RSCAN0_base>|E803 A000H||

## 21.1.3 Clock supply

The RS-CAN provides two clock inputs:

## **Table 21.5 RS-CAN clock supply**

|**Module**|**RS-CAN clock**<br>**Clock**<br>**Connected to**|
|---|---|
|RSCAN0|clk_xincan<br>CAN_CLK|
||clkc<br>P1/2|
||pclk<br>P1|

The operating frequency of the RS-CAN depends on the transfer rate and the number of channels in use. Table 21.6 shows the range of the frequency.

## **Table 21.6 Range of Operating Frequency Depending on the Transfer Rate and the Number of Channels in Use in this LSI**

|**Condition**<br>**Range of Operating Frequency**|**Condition**<br>**Range of Operating Frequency**|
|---|---|
|**Transfer**<br>**Rate**|**No. of**<br>**Channels in**<br>**Use**<br>**pclk**<br>**clk_xincan*1**<br>**clkc*1,*2**|
|1 Mbps|2ch<br>pclk ≥ 26 MHz<br>8 MHz ≤ clk_xincan ≤ pclk/2<br>12.5 MHz ≤ clkc ≤ pclk/2<br>1ch<br>pclk ≥ 18 MHz|
|500 kbps|2ch<br>pclk ≥ 13 MHz<br>4 MHz ≤ clk_xincan ≤ pclk/2<br>12.5 MHz ≤ clkc ≤ pclk/2<br>1ch<br>pclk ≥ 8 MHz|
|125 kbps|2ch<br>pclk ≥ 8 MHz<br>4 MHz ≤ clk_xincan ≤ pclk/2<br>12.5 MHz ≤ clkc ≤ pclk/2<br>1ch|

Note 1. Setting the DCS bit in RSCAN0GCFG enables to select either clk_xincan or clkc. Set clocks less than or equal to pclk/2.

Note 2. Select clk_xincan when pclk < 25 MHz.

## 21.1.4 Interrupts

The Controller Area Network (RS-CAN) can generate the interrupt requests shown in the following table.

## **Table 21.7 RS-CAN interrupt requests**

|**Unit Interrupt Name**|**Outline**|**Interrupt ID**|**DMA Trigger Number**|
|---|---|---|---|
||**RSCAN0**|||
|INTRCANGERR|CAN global error interrupt|253|—|
|INTRCANGRECC|CAN receive FIFO interrupt|254|—|
||**CAN0**|||
|INTRCANmERR (m = 0)|CAN0 error interrupt|256|—|
|INTRCANmREC (m = 0)|CAN0 transmit/receive FIFO receive|255|—|
||completion interrupt|||
|INTRCANmTRX (m = 0)|CAN0 transmit interrupt|257|—|
||**CAN1**|||
|INTRCANmERR (m = 1)|CAN1 error interrupt|259|—|
|INTRCANmREC (m = 1)|CAN1 transmit/receive FIFO receive|258|—|
||completion interrupt|||
|INTRCANmTRX (m = 1)|CAN1 transmit interrupt|260|—|

## 21.1.5 I/O signals

Table 21.8 lists the I/O pins of the RS-CAN module.

## **Table 21.8 I/O Pins of the RS-CAN Module**

|**Unit Signal Name**|**Outline**|**Alternative port pin signal**|
|---|---|---|
||**CAN0**||
|CANmRX (m = 0)|CAN0 receive data input|CAN0RX|
|CANmTX (m = 0)|CAN0 transmit data output|CAN0TX|
||**CAN1**||
|CANmRX (m = 1)|CAN1 receive data input|CAN1RX|
|CANmTX (m = 1)|CAN1 transmit data output|CAN1TX|

## 21.2 Function

This LSI incorporates one unit of the CAN interface (RS-CAN) which consists of two channels (CAN0 and CAN1) of the CAN controller conforming to the ISO11898-1 specifications. Table 21.9 shows the RSCAN module specifications.

Figure 21.1 shows the RS-CAN module block diagram.

## **Table 21.9 RS-CAN Module Specifications  (1/2)**

|**Item**|**Specification**|
|---|---|
|Number of channels|2|
|Protocol|ISO11898-1 compliant|
|Communication speed|Maximum 1 Mbps|
||Communication speed (CANm bit time clock)<br>1<br>CANm bit time<br>--------------------------------------<br>=|
||CANm bit time = CANmTqTq count per bit|
||CANmTq<br>(BRP[9:0] bits in the RSCAN0CmCFG register + 1)<br>fCAN<br>-------------------------------------------------------------------------------------------------------------------------------------**-**<br>=|
||m = 0 or 1|
||Tq: Time quantum|
||fCAN: Frequency of CAN clock (selected by the DCS bit in the RSCAN0GCFG register)|
|Buffer|160 buffers in total|
||Individual buffers: 32 buffers (16 buffers2 channels)|
||Transmit buffer: 16 buffers per channel|
||Transmit queue: Single queue per channel|
||Shared buffers: 128 buffers for all channels|
||Receive buffer: 0 to 31 buffers|
||Receive FIFO buffer: 8 FIFO buffers (up to 96 buffers allocatable to each)|
||Transmit/receive FIFO buffer: 3 FIFO buffers per channel (up to 96 buffers allocatable to each)|
|Reception function|Receives data frames and remote frames.|
||Selects ID format (standard ID, extended ID, or both IDs) to be received.|
||Sets interrupt enable/disable for each FIFO.|
||Mirror function (CAN mode receives its own transmitted messages.)|
||Timestamp function (to record message reception time as a 16-bit timer value)|
|Reception filter function|Selects receive messages according to 128 receive rules.|
||Sets the number of receive rules (0 to 128) for each channel.|
||Acceptance filter processing: Sets ID and mask for each receive rule.|
||DLC filter processing: Sets DLC check value for each acceptance rule.|
|Receive message transfer|Routing function to transfer receive messages to arbitrary destinations (can be transferred to up to 8|
|function|buffers)|
||Transfer destination: Receive buffer, receive FIFO buffer, and/or transmit/receive FIFO buffer|
||Label addition function|
||Stores label information together with a message in a receive buffer and FIFO buffer.|
|Transmission function|Transmits data frames and remote frames.|
||Selects ID format (standard ID, extended ID, or both IDs) to be transmitted.|
||Sets interrupt enable/disable for each transmit buffer and transmit/receive FIFO buffer.|
||Selects ID priority transmission or transmit buffer number priority transmission.|
||Transmit request can be aborted (possible to confirm with a flag)|
||One-shot transmission function|
|Interval transmission|Transmit messages at intervals|
|function|(transmit mode or gateway mode of transmit/receive FIFO buffers)|
|Transmit queue function|Transmits all stored messages according to the ID priority.|

## **Table 21.9 RS-CAN Module Specifications  (2/2)**

|**Item**|**Specification**|
|---|---|
|Transmit history function|Stores the history information of transmitted messages.|
|Gateway function|A received message is automatically routed to a different channel.|
|Bus off recovery mode|Selects the method for returning from bus off state.|
|selection|ISO11898-1 compliant|
||Automatic entry to channel halt mode at bus-off entry|
||Automatic entry to channel halt mode at bus-off end|
||Transition to channel standby mode by program request|
||Transition to the error-active state by program request|
|Error status monitoring|Monitors CAN protocol errors (stuff error, form error, ACK error, CRC error, bit error, ACK delimiter|
||error, and bus dominant lock).|
||Detects error status transitions (error warning, error passive, bus off entry, and bus off recovery)|
||Reads the error counter.|
||Monitors DLC errors.|
|Interrupt source|8 sources|
||Global Interrupts [2 sources: common among channels]|
||Receive FIFO interrupt [1 source: common among channels]|
||Global error interrupt [1 source: common among channels]|
||Channel interrupts [6 sources: 3 sourcesnumber of channels]|
||CANm transmit interrupt [1 source for each channel]|
||– CANm transmit complete interrupt|
||– CANm transmit abort interrupt|
||– CANm transmit/receive FIFO transmit complete interrupt (in transmit mode, gateway mode)|
||– CANm transmit history interrupt|
||– CANm transmit queue interrupt|
||CANm transmit/receive FIFO receive complete interrupt (in receive mode, gateway mode) [1 source|
||for each channel]|
||CANm error interrupt [1 source for each channel]|
||(m = 0 or 1)|
|CAN stop mode|Reduces power consumption by stopping clock supply to the RS-CAN module.|
|CAN clock source|Selects the clkc or the clk_xincan.|
||As for the range of operating frequency, refer to Table 21.6.|
|Test function|Test function for user evaluation|
||Listen-only mode|
||Self-test mode 0 (external loopback)|
||Self-test mode 1 (internal loopback)|
||Inter-channel communication test|

## 21.2.1 Block Diagram

**==> picture [387 x 277] intentionally omitted <==**

**----- Start of picture text -----**<br>
Peripheral bus<br>CAN-related registers<br>Receive rule<br>table RAM<br>CAN0RX Acceptance filter<br>Protocol<br>controller Baud rate<br>CAN0TX (BRP[9:0])prescaler transmission ID priority  FIFO RAM<br>controller<br>CANmRX Timer<br>Protocol<br>controller Baud rate<br>CANmTX prescaler Buffer RAM<br>(BRP[9:0]) 1/2<br>fCANTQm<br>pclk<br>DCS<br>clkc fCAN CAN global error interrupt<br>(INTRCANGERR)<br>clk_xincan CAN receive FIFO interrupt<br>Interrupt  (INTRCANGRECC)<br>CANm transmit interrupt<br>generator circuit (INTRCANmTRX)<br>CANm error interrupt<br>(INTRCANmERR)<br>CANm transmit/receive<br>FIFO receive complete interrupt<br>(INTRCANmREC)<br>**----- End of picture text -----**<br>

Note: m = 0 or 1 BRP[9:0]: Bits in the RSCAN0CmCFG register DCS: Bits in the RSCAN0GCFG register fCANTQm: CANmTq clock fCAN: CAN clock

**Figure 21.1 RS-CAN Module Block Diagram**

## 21.3 Registers

Table 21.10 lists the registers of the RS-CAN module.n = 0, 1.

**Table 21.10 List of RS-CAN Module Registers (1/12)**

|||||**Access**|
|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Channel 0 configuration register|RSCAN0C0CFG|0000 0000H|<RSCAN0_base> + 0000H|8, 16, 32|
|Channel 0 control register|RSCAN0C0CTR|0000 0005H|<RSCAN0_base> + 0004H|8, 16, 32|
|Channel 0 status register|RSCAN0C0STS|0000 0005H|<RSCAN0_base> + 0008H|8, 16, 32|
|Channel 0 error flag register|RSCAN0C0ERFL|0000 0000H|<RSCAN0_base> + 000CH|8, 16, 32|
|Channel 1 configuration register|RSCAN0C1CFG|0000 0000H|<RSCAN0_base> + 0010H|8, 16, 32|
|Channel 1 control register|RSCAN0C1CTR|0000 0005H|<RSCAN0_base> + 0014H|8, 16, 32|
|Channel 1 status register|RSCAN0C1STS|0000 0005H|<RSCAN0_base> + 0018H|8, 16, 32|
|Channel 1 error flag register|RSCAN0C1ERFL|0000 0000H|<RSCAN0_base> + 001CH|8, 16, 32|
|Global configuration register|RSCAN0GCFG|0000 0000H|<RSCAN0_base> + 0084H|8, 16, 32|
|Global control register|RSCAN0GCTR|0000 0005H|<RSCAN0_base> + 0088H|8, 16, 32|
|Global status register|RSCAN0GSTS|0000 000DH|<RSCAN0_base> + 008CH|8, 16, 32|
|Global error flag register|RSCAN0GERFL|0000 0000H|<RSCAN0_base> + 0090H|8, 16, 32|
|Global timestamp counter register|RSCAN0GTSC|0000 0000H|<RSCAN0_base> + 0094H|16, 32|
|Receive rule entry control register|RSCAN0GAFLECTR|0000 0000H|<RSCAN0_base> + 0098H|8, 16, 32|
|Receive rule configuration register 0|RSCAN0GAFLCFG0|0000 0000H|<RSCAN0_base> + 009CH|8, 16, 32|
|Receive buffer number register|RSCAN0RMNB|0000 0000H|<RSCAN0_base> + 00A4H|8, 16, 32|
|Receive buffer new data register 0|RSCAN0RMND0|0000 0000H|<RSCAN0_base> + 00A8H|8, 16, 32|
|Receive FIFO buffer configuration and control register 0|RSCAN0RFCC0|0000 0000H|<RSCAN0_base> + 00B8H|8, 16, 32|
|Receive FIFO buffer configuration and control register 1|RSCAN0RFCC1|0000 0000H|<RSCAN0_base> + 00BCH|8, 16, 32|
|Receive FIFO buffer configuration and control register 2|RSCAN0RFCC2|0000 0000H|<RSCAN0_base> + 00C0H|8, 16, 32|
|Receive FIFO buffer configuration and control register 3|RSCAN0RFCC3|0000 0000H|<RSCAN0_base> + 00C4H|8, 16, 32|
|Receive FIFO buffer configuration and control register 4|RSCAN0RFCC4|0000 0000H|<RSCAN0_base> + 00C8H|8, 16, 32|
|Receive FIFO buffer configuration and control register 5|RSCAN0RFCC5|0000 0000H|<RSCAN0_base> + 00CCH|8, 16, 32|
|Receive FIFO buffer configuration and control register 6|RSCAN0RFCC6|0000 0000H|<RSCAN0_base> + 00D0H|8, 16, 32|
|Receive FIFO buffer configuration and control register 7|RSCAN0RFCC7|0000 0000H|<RSCAN0_base> + 00D4H|8, 16, 32|
|Receive FIFO buffer status register 0|RSCAN0RFSTS0|0000 0001H|<RSCAN0_base> + 00D8H|8, 16, 32|
|Receive FIFO buffer status register 1|RSCAN0RFSTS1|0000 0001H|<RSCAN0_base> + 00DCH|8, 16, 32|
|Receive FIFO buffer status register 2|RSCAN0RFSTS2|0000 0001H|<RSCAN0_base> + 00E0H|8, 16, 32|
|Receive FIFO buffer status register 3|RSCAN0RFSTS3|0000 0001H|<RSCAN0_base> + 00E4H|8, 16, 32|
|Receive FIFO buffer status register 4|RSCAN0RFSTS4|0000 0001H|<RSCAN0_base> + 00E8H|8, 16, 32|
|Receive FIFO buffer status register 5|RSCAN0RFSTS5|0000 0001H|<RSCAN0_base> + 00ECH|8, 16, 32|
|Receive FIFO buffer status register 6|RSCAN0RFSTS6|0000 0001H|<RSCAN0_base> + 00F0H|8, 16, 32|
|Receive FIFO buffer status register 7|RSCAN0RFSTS7|0000 0001H|<RSCAN0_base> + 00F4H|8, 16, 32|
|Receive FIFO buffer pointer control register 0|RSCAN0RFPCTR0|—|<RSCAN0_base> + 00F8H|8, 16, 32|
|Receive FIFO buffer pointer control register 1|RSCAN0RFPCTR1|—|<RSCAN0_base> + 00FCH|8, 16, 32|
|Receive FIFO buffer pointer control register 2|RSCAN0RFPCTR2|—|<RSCAN0_base> + 0100H|8, 16, 32|
|Receive FIFO buffer pointer control register 3|RSCAN0RFPCTR3|—|<RSCAN0_base> + 0104H|8, 16, 32|
|Receive FIFO buffer pointer control register 4|RSCAN0RFPCTR4|—|<RSCAN0_base> + 0108H|8, 16, 32|
|Receive FIFO buffer pointer control register 5|RSCAN0RFPCTR5|—|<RSCAN0_base> + 010CH|8, 16, 32|
|Receive FIFO buffer pointer control register 6|RSCAN0RFPCTR6|—|<RSCAN0_base> + 0110H|8, 16, 32|
|Receive FIFO buffer pointer control register 7|RSCAN0RFPCTR7|—|<RSCAN0_base> + 0114H|8, 16, 32|
|Transmit/receive FIFO buffer configuration and control|RSCAN0CFCC0|0000 0000H|<RSCAN0_base> + 0118H|8, 16, 32|
|register 0|||||

**Table 21.10 List of RS-CAN Module Registers (2/12)**

|||||**Access**|
|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Transmit/receive FIFO buffer configuration and control|RSCAN0CFCC1|0000 0000H|<RSCAN0_base> + 011CH|8, 16, 32|
|register 1|||||
|Transmit/receive FIFO buffer configuration and control|RSCAN0CFCC2|0000 0000H|<RSCAN0_base> + 0120H|8, 16, 32|
|register 2|||||
|Transmit/receive FIFO buffer configuration and control|RSCAN0CFCC3|0000 0000H|<RSCAN0_base> + 0124H|8, 16, 32|
|register 3|||||
|Transmit/receive FIFO buffer configuration and control|RSCAN0CFCC4|0000 0000H|<RSCAN0_base> + 0128H|8, 16, 32|
|register 4|||||
|Transmit/receive FIFO buffer configuration and control|RSCAN0CFCC5|0000 0000H|<RSCAN0_base> + 012CH|8, 16, 32|
|register 5|||||
|Transmit/receive FIFO buffer status register 0|RSCAN0CFSTS0|0000 0001H|<RSCAN0_base> + 0178H|8, 16, 32|
|Transmit/receive FIFO buffer status register 1|RSCAN0CFSTS1|0000 0001H|<RSCAN0_base> + 017CH|8, 16, 32|
|Transmit/receive FIFO buffer status register 2|RSCAN0CFSTS2|0000 0001H|<RSCAN0_base> + 0180H|8, 16, 32|
|Transmit/receive FIFO buffer status register 3|RSCAN0CFSTS3|0000 0001H|<RSCAN0_base> + 0184H|8, 16, 32|
|Transmit/receive FIFO buffer status register 4|RSCAN0CFSTS4|0000 0001H|<RSCAN0_base> + 0188H|8, 16, 32|
|Transmit/receive FIFO buffer status register 5|RSCAN0CFSTS5|0000 0001H|<RSCAN0_base> + 018CH|8, 16, 32|
|Transmit/receive FIFO buffer pointer control register 0|RSCAN0CFPCTR0|—|<RSCAN0_base> + 01D8H|8, 16, 32|
|Transmit/receive FIFO buffer pointer control register 1|RSCAN0CFPCTR1|—|<RSCAN0_base> + 01DCH|8, 16, 32|
|Transmit/receive FIFO buffer pointer control register 2|RSCAN0CFPCTR2|—|<RSCAN0_base> + 01E0H|8, 16, 32|
|Transmit/receive FIFO buffer pointer control register 3|RSCAN0CFPCTR3|—|<RSCAN0_base> + 01E4H|8, 16, 32|
|Transmit/receive FIFO buffer pointer control register 4|RSCAN0CFPCTR4|—|<RSCAN0_base> + 01E8H|8, 16, 32|
|Transmit/receive FIFO buffer pointer control register 5|RSCAN0CFPCTR5|—|<RSCAN0_base> + 01ECH|8, 16, 32|
|FIFO empty status register|RSCAN0FESTS|007F FFFFH|<RSCAN0_base> + 0238H|8, 16, 32|
|FIFO full status register|RSCAN0FFSTS|0000 0000H|<RSCAN0_base> + 023CH|8, 16, 32|
|FIFO Msg lost status register|RSCAN0FMSTS|0000 0000H|<RSCAN0_base> + 0240H|8, 16, 32|
|Receive FIFO buffer interrupt flag status register|RSCAN0RFISTS|0000 0000H|<RSCAN0_base> + 0244H|8, 16, 32|
|Transmit/receive FIFO buffer receive interrupt flag status|RSCAN0CFRISTS|0000 0000H|<RSCAN0_base> + 0248H|8, 16, 32|
|register|||||
|Transmit/receive FIFO buffer transmit interrupt flag status|RSCAN0CFTISTS|0000 0000H|<RSCAN0_base> + 024CH|8, 16, 32|
|register|||||
|Transmit buffer control register 0|RSCAN0TMC0|00H|<RSCAN0_base> + 0250H|8|
|Transmit buffer control register 1|RSCAN0TMC1|00H|<RSCAN0_base> + 0251H|8|
|Transmit buffer control register 2|RSCAN0TMC2|00H|<RSCAN0_base> + 0252H|8|
|Transmit buffer control register 3|RSCAN0TMC3|00H|<RSCAN0_base> + 0253H|8|
|Transmit buffer control register 4|RSCAN0TMC4|00H|<RSCAN0_base> + 0254H|8|
|Transmit buffer control register 5|RSCAN0TMC5|00H|<RSCAN0_base> + 0255H|8|
|Transmit buffer control register 6|RSCAN0TMC6|00H|<RSCAN0_base> + 0256H|8|
|Transmit buffer control register 7|RSCAN0TMC7|00H|<RSCAN0_base> + 0257H|8|
|Transmit buffer control register 8|RSCAN0TMC8|00H|<RSCAN0_base> + 0258H|8|
|Transmit buffer control register 9|RSCAN0TMC9|00H|<RSCAN0_base> + 0259H|8|
|Transmit buffer control register 10|RSCAN0TMC10|00H|<RSCAN0_base> + 025AH|8|
|Transmit buffer control register 11|RSCAN0TMC11|00H|<RSCAN0_base> + 025BH|8|
|Transmit buffer control register 12|RSCAN0TMC12|00H|<RSCAN0_base> + 025CH|8|
|Transmit buffer control register 13|RSCAN0TMC13|00H|<RSCAN0_base> + 025DH|8|
|Transmit buffer control register 14|RSCAN0TMC14|00H|<RSCAN0_base> + 025EH|8|
|Transmit buffer control register 15|RSCAN0TMC15|00H|<RSCAN0_base> + 025FH|8|
|Transmit buffer control register 16|RSCAN0TMC16|00H|<RSCAN0_base> + 0260H|8|
|Transmit buffer control register 17|RSCAN0TMC17|00H|<RSCAN0_base> + 0261H|8|
|Transmit buffer control register 18|RSCAN0TMC18|00H|<RSCAN0_base> + 0262H|8|
|Transmit buffer control register 19|RSCAN0TMC19|00H|<RSCAN0_base> + 0263H|8|

**Table 21.10 List of RS-CAN Module Registers (3/12)**

|||||**Access**|**Access**|
|---|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**||**Size**|
|Transmit buffer control register 20|RSCAN0TMC20|00H|<RSCAN0_base> + 0264H|8||
|Transmit buffer control register 21|RSCAN0TMC21|00H|<RSCAN0_base> + 0265H|8||
|Transmit buffer control register 22|RSCAN0TMC22|00H|<RSCAN0_base> + 0266H|8||
|Transmit buffer control register 23|RSCAN0TMC23|00H|<RSCAN0_base> + 0267H|8||
|Transmit buffer control register 24|RSCAN0TMC24|00H|<RSCAN0_base> + 0268H|8||
|Transmit buffer control register 25|RSCAN0TMC25|00H|<RSCAN0_base> + 0269H|8||
|Transmit buffer control register 26|RSCAN0TMC26|00H|<RSCAN0_base> + 026AH|8||
|Transmit buffer control register 27|RSCAN0TMC27|00H|<RSCAN0_base> + 026BH|8||
|Transmit buffer control register 28|RSCAN0TMC28|00H|<RSCAN0_base> + 026CH|8||
|Transmit buffer control register 29|RSCAN0TMC29|00H|<RSCAN0_base> + 026DH|8||
|Transmit buffer control register 30|RSCAN0TMC30|00H|<RSCAN0_base> + 026EH|8||
|Transmit buffer control register 31|RSCAN0TMC31|00H|<RSCAN0_base> + 026FH|8||
|Transmit buffer status register 0|RSCAN0TMSTS0|00H|<RSCAN0_base> + 02D0H|8||
|Transmit buffer status register 1|RSCAN0TMSTS1|00H|<RSCAN0_base> + 02D1H|8||
|Transmit buffer status register 2|RSCAN0TMSTS2|00H|<RSCAN0_base> + 02D2H|8||
|Transmit buffer status register 3|RSCAN0TMSTS3|00H|<RSCAN0_base> + 02D3H|8||
|Transmit buffer status register 4|RSCAN0TMSTS4|00H|<RSCAN0_base> + 02D4H|8||
|Transmit buffer status register 5|RSCAN0TMSTS5|00H|<RSCAN0_base> + 02D5H|8||
|Transmit buffer status register 6|RSCAN0TMSTS6|00H|<RSCAN0_base> + 02D6H|8||
|Transmit buffer status register 7|RSCAN0TMSTS7|00H|<RSCAN0_base> + 02D7H|8||
|Transmit buffer status register 8|RSCAN0TMSTS8|00H|<RSCAN0_base> + 02D8H|8||
|Transmit buffer status register 9|RSCAN0TMSTS9|00H|<RSCAN0_base> + 02D9H|8||
|Transmit buffer status register 10|RSCAN0TMSTS10|00H|<RSCAN0_base> + 02DAH|8||
|Transmit buffer status register 11|RSCAN0TMSTS11|00H|<RSCAN0_base> + 02DBH|8||
|Transmit buffer status register 12|RSCAN0TMSTS12|00H|<RSCAN0_base> + 02DCH|8||
|Transmit buffer status register 13|RSCAN0TMSTS13|00H|<RSCAN0_base> + 02DDH|8||
|Transmit buffer status register 14|RSCAN0TMSTS14|00H|<RSCAN0_base> + 02DEH|8||
|Transmit buffer status register 15|RSCAN0TMSTS15|00H|<RSCAN0_base> + 02DFH|8||
|Transmit buffer status register 16|RSCAN0TMSTS16|00H|<RSCAN0_base> + 02E0H|8||
|Transmit buffer status register 17|RSCAN0TMSTS17|00H|<RSCAN0_base> + 02E1H|8||
|Transmit buffer status register 18|RSCAN0TMSTS18|00H|<RSCAN0_base> + 02E2H|8||
|Transmit buffer status register 19|RSCAN0TMSTS19|00H|<RSCAN0_base> + 02E3H|8||
|Transmit buffer status register 20|RSCAN0TMSTS20|00H|<RSCAN0_base> + 02E4H|8||
|Transmit buffer status register 21|RSCAN0TMSTS21|00H|<RSCAN0_base> + 02E5H|8||
|Transmit buffer status register 22|RSCAN0TMSTS22|00H|<RSCAN0_base> + 02E6H|8||
|Transmit buffer status register 23|RSCAN0TMSTS23|00H|<RSCAN0_base> + 02E7H|8||
|Transmit buffer status register 24|RSCAN0TMSTS24|00H|<RSCAN0_base> + 02E8H|8||
|Transmit buffer status register 25|RSCAN0TMSTS25|00H|<RSCAN0_base> + 02E9H|8||
|Transmit buffer status register 26|RSCAN0TMSTS26|00H|<RSCAN0_base> + 02EAH|8||
|Transmit buffer status register 27|RSCAN0TMSTS27|00H|<RSCAN0_base> + 02EBH|8||
|Transmit buffer status register 28|RSCAN0TMSTS28|00H|<RSCAN0_base> + 02ECH|8||
|Transmit buffer status register 29|RSCAN0TMSTS29|00H|<RSCAN0_base> + 02EDH|8||
|Transmit buffer status register 30|RSCAN0TMSTS30|00H|<RSCAN0_base> + 02EEH|8||
|Transmit buffer status register 31|RSCAN0TMSTS31|00H|<RSCAN0_base> + 02EFH|8||
|Transmit buffer transmit request status register 0|RSCAN0TMTRSTS0|0000 0000H|<RSCAN0_base> + 0350H|8,|16, 32|
|Transmit buffer transmit abort request status register 0|RSCAN0TMTARSTS0|0000 0000H|<RSCAN0_base> + 0360H|8,|16, 32|
|Transmit buffer transmit complete status register 0|RSCAN0TMTCSTS0|0000 0000H|<RSCAN0_base> + 0370H|8,|16, 32|

**Table 21.10 List of RS-CAN Module Registers (4/12)**

|||||**Access**|
|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Transmit buffer transmit abort status register 0|RSCAN0TMTASTS0|0000 0000H|<RSCAN0_base> + 0380H|8, 16, 32|
|Transmit buffer interrupt enable configuration register 0|RSCAN0TMIEC0|0000 0000H|<RSCAN0_base> + 0390H|8, 16, 32|
|Transmit queue configuration and control register 0|RSCAN0TXQCC0|0000 0000H|<RSCAN0_base> + 03A0H|8, 16, 32|
|Transmit queue configuration and control register 1|RSCAN0TXQCC1|0000 0000H|<RSCAN0_base> + 03A4H|8, 16, 32|
|Transmit queue status register 0|RSCAN0TXQSTS0|0000 0001H|<RSCAN0_base> + 03C0H|8, 16, 32|
|Transmit queue status register 1|RSCAN0TXQSTS1|0000 0001H|<RSCAN0_base> + 03C4H|8, 16, 32|
|Transmit queue pointer control register 0|RSCAN0TXQPCTR0|—|<RSCAN0_base> + 03E0H|8, 16, 32|
|Transmit queue pointer control register 1|RSCAN0TXQPCTR1|—|<RSCAN0_base> + 03E4H|8, 16, 32|
|Transmit history configuration and control register 0|RSCAN0THLCC0|0000 0000H|<RSCAN0_base> + 0400H|8, 16, 32|
|Transmit history configuration and control register 1|RSCAN0THLCC1|0000 0000H|<RSCAN0_base> + 0404H|8, 16, 32|
|Transmit history status register 0|RSCAN0THLSTS0|0000 0001H|<RSCAN0_base> + 0420H|8, 16, 32|
|Transmit history status register 1|RSCAN0THLSTS1|0000 0001H|<RSCAN0_base> + 0424H|8, 16, 32|
|Transmit history pointer control register 0|RSCAN0THLPCTR0|0000 0000H|<RSCAN0_base> + 0440H|8, 16, 32|
|Transmit history pointer control register 1|RSCAN0THLPCTR1|0000 0000H|<RSCAN0_base> + 0444H|8, 16, 32|
|Global TX interrupt status register 0|RSCAN0GTINTSTS0|0000 0000H|<RSCAN0_base> + 0460H|8, 16, 32|
|Global test configuration register|RSCAN0GTSTCFG|0000 0000H|<RSCAN0_base> + 0468H|8, 16, 32|
|Global test control register|RSCAN0GTSTCTR|0000 0000H|<RSCAN0_base> + 046CH|8, 16, 32|
|Global lock key register|RSCAN0GLOCKK|—|<RSCAN0_base> + 047CH|16, 32|
|Receive rule ID register 0|RSCAN0GAFLID0|0000 0000H|<RSCAN0_base> + 0500H|8, 16, 32|
|Receive rule mask register 0|RSCAN0GAFLM0|0000 0000H|<RSCAN0_base> + 0504H|8, 16, 32|
|Receive rule pointer 0 register 0|RSCAN0GAFLP00|0000 0000H|<RSCAN0_base> + 0508H|8, 16, 32|
|Receive rule pointer 1 register 0|RSCAN0GAFLP10|0000 0000H|<RSCAN0_base> + 050CH|8, 16, 32|
|Receive rule ID register 1|RSCAN0GAFLID1|0000 0000H|<RSCAN0_base> + 0510H|8, 16, 32|
|Receive rule mask register 1|RSCAN0GAFLM1|0000 0000H|<RSCAN0_base> + 0514H|8, 16, 32|
|Receive rule pointer 0 register 1|RSCAN0GAFLP01|0000 0000H|<RSCAN0_base> + 0518H|8, 16, 32|
|Receive rule pointer 1 register 1|RSCAN0GAFLP11|0000 0000H|<RSCAN0_base> + 051CH|8, 16, 32|
|Receive rule ID register 2|RSCAN0GAFLID2|0000 0000H|<RSCAN0_base> + 0520H|8, 16, 32|
|Receive rule mask register 2|RSCAN0GAFLM2|0000 0000H|<RSCAN0_base> + 0524H|8, 16, 32|
|Receive rule pointer 0 register 2|RSCAN0GAFLP02|0000 0000H|<RSCAN0_base> + 0528H|8, 16, 32|
|Receive rule pointer 1 register 2|RSCAN0GAFLP12|0000 0000H|<RSCAN0_base> + 052CH|8, 16, 32|
|Receive rule ID register 3|RSCAN0GAFLID3|0000 0000H|<RSCAN0_base> + 0530H|8, 16, 32|
|Receive rule mask register 3|RSCAN0GAFLM3|0000 0000H|<RSCAN0_base> + 0534H|8, 16, 32|
|Receive rule pointer 0 register 3|RSCAN0GAFLP03|0000 0000H|<RSCAN0_base> + 0538H|8, 16, 32|
|Receive rule pointer 1 register 3|RSCAN0GAFLP13|0000 0000H|<RSCAN0_base> + 053CH|8, 16, 32|
|Receive rule ID register 4|RSCAN0GAFLID4|0000 0000H|<RSCAN0_base> + 0540H|8, 16, 32|
|Receive rule mask register 4|RSCAN0GAFLM4|0000 0000H|<RSCAN0_base> + 0544H|8, 16, 32|
|Receive rule pointer 0 register 4|RSCAN0GAFLP04|0000 0000H|<RSCAN0_base> + 0548H|8, 16, 32|
|Receive rule pointer 1 register 4|RSCAN0GAFLP14|0000 0000H|<RSCAN0_base> + 054CH|8, 16, 32|
|Receive rule ID register 5|RSCAN0GAFLID5|0000 0000H|<RSCAN0_base> + 0550H|8, 16, 32|
|Receive rule mask register 5|RSCAN0GAFLM5|0000 0000H|<RSCAN0_base> + 0554H|8, 16, 32|
|Receive rule pointer 0 register 5|RSCAN0GAFLP05|0000 0000H|<RSCAN0_base> + 0558H|8, 16, 32|
|Receive rule pointer 1 register 5|RSCAN0GAFLP15|0000 0000H|<RSCAN0_base> + 055CH|8, 16, 32|
|Receive rule ID register 6|RSCAN0GAFLID6|0000 0000H|<RSCAN0_base> + 0560H|8, 16, 32|
|Receive rule mask register 6|RSCAN0GAFLM6|0000 0000H|<RSCAN0_base> + 0564H|8, 16, 32|
|Receive rule pointer 0 register 6|RSCAN0GAFLP06|0000 0000H|<RSCAN0_base> + 0568H|8, 16, 32|
|Receive rule pointer 1 register 6|RSCAN0GAFLP16|0000 0000H|<RSCAN0_base> + 056CH|8, 16, 32|
|Receive rule ID register 7|RSCAN0GAFLID7|0000 0000H|<RSCAN0_base> + 0570H|8, 16, 32|

**Table 21.10 List of RS-CAN Module Registers (5/12)**

|||||**Access**|
|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Receive rule mask register 7|RSCAN0GAFLM7|0000 0000H|<RSCAN0_base> + 0574H|8, 16, 32|
|Receive rule pointer 0 register 7|RSCAN0GAFLP07|0000 0000H|<RSCAN0_base> + 0578H|8, 16, 32|
|Receive rule pointer 1 register 7|RSCAN0GAFLP17|0000 0000H|<RSCAN0_base> + 057CH|8, 16, 32|
|Receive rule ID register 8|RSCAN0GAFLID8|0000 0000H|<RSCAN0_base> + 0580H|8, 16, 32|
|Receive rule mask register 8|RSCAN0GAFLM8|0000 0000H|<RSCAN0_base> + 0584H|8, 16, 32|
|Receive rule pointer 0 register 8|RSCAN0GAFLP08|0000 0000H|<RSCAN0_base> + 0588H|8, 16, 32|
|Receive rule pointer 1 register 8|RSCAN0GAFLP18|0000 0000H|<RSCAN0_base> + 058CH|8, 16, 32|
|Receive rule ID register 9|RSCAN0GAFLID9|0000 0000H|<RSCAN0_base> + 0590H|8, 16, 32|
|Receive rule mask register 9|RSCAN0GAFLM9|0000 0000H|<RSCAN0_base> + 0594H|8, 16, 32|
|Receive rule pointer 0 register 9|RSCAN0GAFLP09|0000 0000H|<RSCAN0_base> + 0598H|8, 16, 32|
|Receive rule pointer 1 register 9|RSCAN0GAFLP19|0000 0000H|<RSCAN0_base> + 059CH|8, 16, 32|
|Receive rule ID register 10|RSCAN0GAFLID10|0000 0000H|<RSCAN0_base> + 05A0H|8, 16, 32|
|Receive rule mask register 10|RSCAN0GAFLM10|0000 0000H|<RSCAN0_base> + 05A4H|8, 16, 32|
|Receive rule pointer 0 register 10|RSCAN0GAFLP010|0000 0000H|<RSCAN0_base> + 05A8H|8, 16, 32|
|Receive rule pointer 1 register 10|RSCAN0GAFLP110|0000 0000H|<RSCAN0_base> + 05ACH|8, 16, 32|
|Receive rule ID register 11|RSCAN0GAFLID11|0000 0000H|<RSCAN0_base> + 05B0H|8, 16, 32|
|Receive rule mask register 11|RSCAN0GAFLM11|0000 0000H|<RSCAN0_base> + 05B4H|8, 16, 32|
|Receive rule pointer 0 register 11|RSCAN0GAFLP011|0000 0000H|<RSCAN0_base> + 05B8H|8, 16, 32|
|Receive rule pointer 1 register 11|RSCAN0GAFLP111|0000 0000H|<RSCAN0_base> + 05BCH|8, 16, 32|
|Receive rule ID register 12|RSCAN0GAFLID12|0000 0000H|<RSCAN0_base> + 05C0H|8, 16, 32|
|Receive rule mask register 12|RSCAN0GAFLM12|0000 0000H|<RSCAN0_base> + 05C4H|8, 16, 32|
|Receive rule pointer 0 register 12|RSCAN0GAFLP012|0000 0000H|<RSCAN0_base> + 05C8H|8, 16, 32|
|Receive rule pointer 1 register 12|RSCAN0GAFLP112|0000 0000H|<RSCAN0_base> + 05CCH|8, 16, 32|
|Receive rule ID register 13|RSCAN0GAFLID13|0000 0000H|<RSCAN0_base> + 05D0H|8, 16, 32|
|Receive rule mask register 13|RSCAN0GAFLM13|0000 0000H|<RSCAN0_base> + 05D4H|8, 16, 32|
|Receive rule pointer 0 register 13|RSCAN0GAFLP013|0000 0000H|<RSCAN0_base> + 05D8H|8, 16, 32|
|Receive rule pointer 1 register 13|RSCAN0GAFLP113|0000 0000H|<RSCAN0_base> + 05DCH|8, 16, 32|
|Receive rule ID register 14|RSCAN0GAFLID14|0000 0000H|<RSCAN0_base> + 05E0H|8, 16, 32|
|Receive rule mask register 14|RSCAN0GAFLM14|0000 0000H|<RSCAN0_base> + 05E4H|8, 16, 32|
|Receive rule pointer 0 register 14|RSCAN0GAFLP014|0000 0000H|<RSCAN0_base> + 05E8H|8, 16, 32|
|Receive rule pointer 1 register 14|RSCAN0GAFLP114|0000 0000H|<RSCAN0_base> + 05ECH|8, 16, 32|
|Receive rule ID register 15|RSCAN0GAFLID15|0000 0000H|<RSCAN0_base> + 05F0H|8, 16, 32|
|Receive rule mask register 15|RSCAN0GAFLM15|0000 0000H|<RSCAN0_base> + 05F4H|8, 16, 32|
|Receive rule pointer 0 register 15|RSCAN0GAFLP015|0000 0000H|<RSCAN0_base> + 05F8H|8, 16, 32|
|Receive rule pointer 1 register 15|RSCAN0GAFLP115|0000 0000H|<RSCAN0_base> + 05FCH|8, 16, 32|
|Receive buffer ID register 0|RSCAN0RMID0|0000 0000H|<RSCAN0_base> + 0600H|8, 16, 32|
|Receive buffer pointer register 0|RSCAN0RMPTR0|0000 0000H|<RSCAN0_base> + 0604H|8, 16, 32|
|Receive buffer data field 0 register 0|RSCAN0RMDF00|0000 0000H|<RSCAN0_base> + 0608H|8, 16, 32|
|Receive buffer data field 1 register 0|RSCAN0RMDF10|0000 0000H|<RSCAN0_base> + 060CH|8, 16, 32|
|Receive buffer ID register 1|RSCAN0RMID1|0000 0000H|<RSCAN0_base> + 0610H|8, 16, 32|
|Receive buffer pointer register 1|RSCAN0RMPTR1|0000 0000H|<RSCAN0_base> + 0614H|8, 16, 32|
|Receive buffer data field 0 register 1|RSCAN0RMDF01|0000 0000H|<RSCAN0_base> + 0618H|8, 16, 32|
|Receive buffer data field 1 register 1|RSCAN0RMDF11|0000 0000H|<RSCAN0_base> + 061CH|8, 16, 32|
|Receive buffer ID register 2|RSCAN0RMID2|0000 0000H|<RSCAN0_base> + 0620H|8, 16, 32|
|Receive buffer pointer register 2|RSCAN0RMPTR2|0000 0000H|<RSCAN0_base> + 0624H|8, 16, 32|
|Receive buffer data field 0 register 2|RSCAN0RMDF02|0000 0000H|<RSCAN0_base> + 0628H|8, 16, 32|
|Receive buffer data field 1 register 2|RSCAN0RMDF12|0000 0000H|<RSCAN0_base> + 062CH|8, 16, 32|

**Table 21.10 List of RS-CAN Module Registers (6/12)**

|||||**Access**|
|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Receive buffer ID register 3|RSCAN0RMID3|0000 0000H|<RSCAN0_base> + 0630H|8, 16, 32|
|Receive buffer pointer register 3|RSCAN0RMPTR3|0000 0000H|<RSCAN0_base> + 0634H|8, 16, 32|
|Receive buffer data field 0 register 3|RSCAN0RMDF03|0000 0000H|<RSCAN0_base> + 0638H|8, 16, 32|
|Receive buffer data field 1 register 3|RSCAN0RMDF13|0000 0000H|<RSCAN0_base> + 063CH|8, 16, 32|
|Receive buffer ID register 4|RSCAN0RMID4|0000 0000H|<RSCAN0_base> + 0640H|8, 16, 32|
|Receive buffer pointer register 4|RSCAN0RMPTR4|0000 0000H|<RSCAN0_base> + 0644H|8, 16, 32|
|Receive buffer data field 0 register 4|RSCAN0RMDF04|0000 0000H|<RSCAN0_base> + 0648H|8, 16, 32|
|Receive buffer data field 1 register 4|RSCAN0RMDF14|0000 0000H|<RSCAN0_base> + 064CH|8, 16, 32|
|Receive buffer ID register 5|RSCAN0RMID5|0000 0000H|<RSCAN0_base> + 0650H|8, 16, 32|
|Receive buffer pointer register 5|RSCAN0RMPTR5|0000 0000H|<RSCAN0_base> + 0654H|8, 16, 32|
|Receive buffer data field 0 register 5|RSCAN0RMDF05|0000 0000H|<RSCAN0_base> + 0658H|8, 16, 32|
|Receive buffer data field 1 register 5|RSCAN0RMDF15|0000 0000H|<RSCAN0_base> + 065CH|8, 16, 32|
|Receive buffer ID register 6|RSCAN0RMID6|0000 0000H|<RSCAN0_base> + 0660H|8, 16, 32|
|Receive buffer pointer register 6|RSCAN0RMPTR6|0000 0000H|<RSCAN0_base> + 0664H|8, 16, 32|
|Receive buffer data field 0 register 6|RSCAN0RMDF06|0000 0000H|<RSCAN0_base> + 0668H|8, 16, 32|
|Receive buffer data field 1 register 6|RSCAN0RMDF16|0000 0000H|<RSCAN0_base> + 066CH|8, 16, 32|
|Receive buffer ID register 7|RSCAN0RMID7|0000 0000H|<RSCAN0_base> + 0670H|8, 16, 32|
|Receive buffer pointer register 7|RSCAN0RMPTR7|0000 0000H|<RSCAN0_base> + 0674H|8, 16, 32|
|Receive buffer data field 0 register 7|RSCAN0RMDF07|0000 0000H|<RSCAN0_base> + 0678H|8, 16, 32|
|Receive buffer data field 1 register 7|RSCAN0RMDF17|0000 0000H|<RSCAN0_base> + 067CH|8, 16, 32|
|Receive buffer ID register 8|RSCAN0RMID8|0000 0000H|<RSCAN0_base> + 0680H|8, 16, 32|
|Receive buffer pointer register 8|RSCAN0RMPTR8|0000 0000H|<RSCAN0_base> + 0684H|8, 16, 32|
|Receive buffer data field 0 register 8|RSCAN0RMDF08|0000 0000H|<RSCAN0_base> + 0688H|8, 16, 32|
|Receive buffer data field 1 register 8|RSCAN0RMDF18|0000 0000H|<RSCAN0_base> + 068CH|8, 16, 32|
|Receive buffer ID register 9|RSCAN0RMID9|0000 0000H|<RSCAN0_base> + 0690H|8, 16, 32|
|Receive buffer pointer register 9|RSCAN0RMPTR9|0000 0000H|<RSCAN0_base> + 0694H|8, 16, 32|
|Receive buffer data field 0 register 9|RSCAN0RMDF09|0000 0000H|<RSCAN0_base> + 0698H|8, 16, 32|
|Receive buffer data field 1 register 9|RSCAN0RMDF19|0000 0000H|<RSCAN0_base> + 069CH|8, 16, 32|
|Receive buffer ID register 10|RSCAN0RMID10|0000 0000H|<RSCAN0_base> + 06A0H|8, 16, 32|
|Receive buffer pointer register 10|RSCAN0RMPTR10|0000 0000H|<RSCAN0_base> + 06A4H|8, 16, 32|
|Receive buffer data field 0 register 10|RSCAN0RMDF010|0000 0000H|<RSCAN0_base> + 06A8H|8, 16, 32|
|Receive buffer data field 1 register 10|RSCAN0RMDF110|0000 0000H|<RSCAN0_base> + 06ACH|8, 16, 32|
|Receive buffer ID register 11|RSCAN0RMID11|0000 0000H|<RSCAN0_base> + 06B0H|8, 16, 32|
|Receive buffer pointer register 11|RSCAN0RMPTR11|0000 0000H|<RSCAN0_base> + 06B4H|8, 16, 32|
|Receive buffer data field 0 register 11|RSCAN0RMDF011|0000 0000H|<RSCAN0_base> + 06B8H|8, 16, 32|
|Receive buffer data field 1 register 11|RSCAN0RMDF111|0000 0000H|<RSCAN0_base> + 06BCH|8, 16, 32|
|Receive buffer ID register 12|RSCAN0RMID12|0000 0000H|<RSCAN0_base> + 06C0H|8, 16, 32|
|Receive buffer pointer register 12|RSCAN0RMPTR12|0000 0000H|<RSCAN0_base> + 06C4H|8, 16, 32|
|Receive buffer data field 0 register 12|RSCAN0RMDF012|0000 0000H|<RSCAN0_base> + 06C8H|8, 16, 32|
|Receive buffer data field 1 register 12|RSCAN0RMDF112|0000 0000H|<RSCAN0_base> + 06CCH|8, 16, 32|
|Receive buffer ID register 13|RSCAN0RMID13|0000 0000H|<RSCAN0_base> + 06D0H|8, 16, 32|
|Receive buffer pointer register 13|RSCAN0RMPTR13|0000 0000H|<RSCAN0_base> + 06D4H|8, 16, 32|
|Receive buffer data field 0 register 13|RSCAN0RMDF013|0000 0000H|<RSCAN0_base> + 06D8H|8, 16, 32|
|Receive buffer data field 1 register 13|RSCAN0RMDF113|0000 0000H|<RSCAN0_base> + 06DCH|8, 16, 32|
|Receive buffer ID register 14|RSCAN0RMID14|0000 0000H|<RSCAN0_base> + 06E0H|8, 16, 32|
|Receive buffer pointer register 14|RSCAN0RMPTR14|0000 0000H|<RSCAN0_base> + 06E4H|8, 16, 32|
|Receive buffer data field 0 register 14|RSCAN0RMDF014|0000 0000H|<RSCAN0_base> + 06E8H|8, 16, 32|

**Table 21.10 List of RS-CAN Module Registers (7/12)**

|||||**Access**|
|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Receive buffer data field 1 register 14|RSCAN0RMDF114|0000 0000H|<RSCAN0_base> + 06ECH|8, 16, 32|
|Receive buffer ID register 15|RSCAN0RMID15|0000 0000H|<RSCAN0_base> + 06F0H|8, 16, 32|
|Receive buffer pointer register 15|RSCAN0RMPTR15|0000 0000H|<RSCAN0_base> + 06F4H|8, 16, 32|
|Receive buffer data field 0 register 15|RSCAN0RMDF015|0000 0000H|<RSCAN0_base> + 06F8H|8, 16, 32|
|Receive buffer data field 1 register 15|RSCAN0RMDF115|0000 0000H|<RSCAN0_base> + 06FCH|8, 16, 32|
|Receive buffer ID register 16|RSCAN0RMID16|0000 0000H|<RSCAN0_base> + 0700H|8, 16, 32|
|Receive buffer pointer register 16|RSCAN0RMPTR16|0000 0000H|<RSCAN0_base> + 0704H|8, 16, 32|
|Receive buffer data field 0 register 16|RSCAN0RMDF016|0000 0000H|<RSCAN0_base> + 0708H|8, 16, 32|
|Receive buffer data field 1 register16|RSCAN0RMDF116|0000 0000H|<RSCAN0_base> + 070CH|8, 16, 32|
|Receive buffer ID register 17|RSCAN0RMID17|0000 0000H|<RSCAN0_base> + 0710H|8, 16, 32|
|Receive buffer pointer register 17|RSCAN0RMPTR17|0000 0000H|<RSCAN0_base> + 0714H|8, 16, 32|
|Receive buffer data field 0 register 17|RSCAN0RMDF017|0000 0000H|<RSCAN0_base> + 0718H|8, 16, 32|
|Receive buffer data field 1 register 17|RSCAN0RMDF117|0000 0000H|<RSCAN0_base> + 071CH|8, 16, 32|
|Receive buffer ID register 18|RSCAN0RMID18|0000 0000H|<RSCAN0_base> + 0720H|8, 16, 32|
|Receive buffer pointer register 18|RSCAN0RMPTR18|0000 0000H|<RSCAN0_base> + 0724H|8, 16, 32|
|Receive buffer data field 0 register 18|RSCAN0RMDF018|0000 0000H|<RSCAN0_base> + 0728H|8, 16, 32|
|Receive buffer data field 1 register 18|RSCAN0RMDF118|0000 0000H|<RSCAN0_base> + 072CH|8, 16, 32|
|Receive buffer ID register 19|RSCAN0RMID19|0000 0000H|<RSCAN0_base> + 0730H|8, 16, 32|
|Receive buffer pointer register 19|RSCAN0RMPTR19|0000 0000H|<RSCAN0_base> + 0734H|8, 16, 32|
|Receive buffer data field 0 register 19|RSCAN0RMDF019|0000 0000H|<RSCAN0_base> + 0738H|8, 16, 32|
|Receive buffer data field 1 register 19|RSCAN0RMDF119|0000 0000H|<RSCAN0_base> + 073CH|8, 16, 32|
|Receive buffer ID register 20|RSCAN0RMID20|0000 0000H|<RSCAN0_base> + 0740H|8, 16, 32|
|Receive buffer pointer register 20|RSCAN0RMPTR20|0000 0000H|<RSCAN0_base> + 0744H|8, 16, 32|
|Receive buffer data field 0 register 20|RSCAN0RMDF020|0000 0000H|<RSCAN0_base> + 0748H|8, 16, 32|
|Receive buffer data field 1 register 20|RSCAN0RMDF120|0000 0000H|<RSCAN0_base> + 074CH|8, 16, 32|
|Receive buffer ID register 21|RSCAN0RMID21|0000 0000H|<RSCAN0_base> + 0750H|8, 16, 32|
|Receive buffer pointer register 21|RSCAN0RMPTR21|0000 0000H|<RSCAN0_base> + 0754H|8, 16, 32|
|Receive buffer data field 0 register 21|RSCAN0RMDF021|0000 0000H|<RSCAN0_base> + 0758H|8, 16, 32|
|Receive buffer data field 1 register 21|RSCAN0RMDF121|0000 0000H|<RSCAN0_base> + 075CH|8, 16, 32|
|Receive buffer ID register 22|RSCAN0RMID22|0000 0000H|<RSCAN0_base> + 0760H|8, 16, 32|
|Receive buffer pointer register 22|RSCAN0RMPTR22|0000 0000H|<RSCAN0_base> + 0764H|8, 16, 32|
|Receive buffer data field 0 register 22|RSCAN0RMDF022|0000 0000H|<RSCAN0_base> + 0768H|8, 16, 32|
|Receive buffer data field 1 register 22|RSCAN0RMDF122|0000 0000H|<RSCAN0_base> + 076CH|8, 16, 32|
|Receive buffer ID register 23|RSCAN0RMID23|0000 0000H|<RSCAN0_base> + 0770H|8, 16, 32|
|Receive buffer pointer register 23|RSCAN0RMPTR23|0000 0000H|<RSCAN0_base> + 0774H|8, 16, 32|
|Receive buffer data field 0 register 23|RSCAN0RMDF023|0000 0000H|<RSCAN0_base> + 0778H|8, 16, 32|
|Receive buffer data field 1 register 23|RSCAN0RMDF123|0000 0000H|<RSCAN0_base> + 077CH|8, 16, 32|
|Receive buffer ID register 24|RSCAN0RMID24|0000 0000H|<RSCAN0_base> + 0780H|8, 16, 32|
|Receive buffer pointer register 24|RSCAN0RMPTR24|0000 0000H|<RSCAN0_base> + 0784H|8, 16, 32|
|Receive buffer data field 0 register 24|RSCAN0RMDF024|0000 0000H|<RSCAN0_base> + 0788H|8, 16, 32|
|Receive buffer data field 1 register 24|RSCAN0RMDF124|0000 0000H|<RSCAN0_base> + 078CH|8, 16, 32|
|Receive buffer ID register 25|RSCAN0RMID25|0000 0000H|<RSCAN0_base> + 0790H|8, 16, 32|
|Receive buffer pointer register 25|RSCAN0RMPTR25|0000 0000H|<RSCAN0_base> + 0794H|8, 16, 32|
|Receive buffer data field 0 register 25|RSCAN0RMDF025|0000 0000H|<RSCAN0_base> + 0798H|8, 16, 32|
|Receive buffer data field 1 register 25|RSCAN0RMDF125|0000 0000H|<RSCAN0_base> + 079CH|8, 16, 32|
|Receive buffer ID register 26|RSCAN0RMID26|0000 0000H|<RSCAN0_base> + 07A0H|8, 16, 32|
|Receive buffer pointer register 26|RSCAN0RMPTR26|0000 0000H|<RSCAN0_base> + 07A4H|8, 16, 32|

**Table 21.10 List of RS-CAN Module Registers (8/12)**

|||||**Access**|
|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Receive buffer data field 0 register 26|RSCAN0RMDF026|0000 0000H|<RSCAN0_base> + 07A8H|8, 16, 32|
|Receive buffer data field 1 register 26|RSCAN0RMDF126|0000 0000H|<RSCAN0_base> + 07ACH|8, 16, 32|
|Receive buffer ID register 27|RSCAN0RMID27|0000 0000H|<RSCAN0_base> + 07B0H|8, 16, 32|
|Receive buffer pointer register 27|RSCAN0RMPTR27|0000 0000H|<RSCAN0_base> + 07B4H|8, 16, 32|
|Receive buffer data field 0 register 27|RSCAN0RMDF027|0000 0000H|<RSCAN0_base> + 07B8H|8, 16, 32|
|Receive buffer data field 1 register 27|RSCAN0RMDF127|0000 0000H|<RSCAN0_base> + 07BCH|8, 16, 32|
|Receive buffer ID register 28|RSCAN0RMID28|0000 0000H|<RSCAN0_base> + 07C0H|8, 16, 32|
|Receive buffer pointer register 28|RSCAN0RMPTR28|0000 0000H|<RSCAN0_base> + 07C4H|8, 16, 32|
|Receive buffer data field 0 register 28|RSCAN0RMDF028|0000 0000H|<RSCAN0_base> + 07C8H|8, 16, 32|
|Receive buffer data field 1 register 28|RSCAN0RMDF128|0000 0000H|<RSCAN0_base> + 07CCH|8, 16, 32|
|Receive buffer ID register 29|RSCAN0RMID29|0000 0000H|<RSCAN0_base> + 07D0H|8, 16, 32|
|Receive buffer pointer register 29|RSCAN0RMPTR29|0000 0000H|<RSCAN0_base> + 07D4H|8, 16, 32|
|Receive buffer data field 0 register 29|RSCAN0RMDF029|0000 0000H|<RSCAN0_base> + 07D8H|8, 16, 32|
|Receive buffer data field 1 register 29|RSCAN0RMDF129|0000 0000H|<RSCAN0_base> + 07DCH|8, 16, 32|
|Receive buffer ID register 30|RSCAN0RMID30|0000 0000H|<RSCAN0_base> + 07E0H|8, 16, 32|
|Receive buffer pointer register 30|RSCAN0RMPTR30|0000 0000H|<RSCAN0_base> + 07E4H|8, 16, 32|
|Receive buffer data field 0 register 30|RSCAN0RMDF030|0000 0000H|<RSCAN0_base> + 07E8H|8, 16, 32|
|Receive buffer data field 1 register 30|RSCAN0RMDF130|0000 0000H|<RSCAN0_base> + 07ECH|8, 16, 32|
|Receive buffer ID register 31|RSCAN0RMID31|0000 0000H|<RSCAN0_base> + 07F0H|8, 16, 32|
|Receive buffer pointer register 31|RSCAN0RMPTR31|0000 0000H|<RSCAN0_base> + 07F4H|8, 16, 32|
|Receive buffer data field 0 register 31|RSCAN0RMDF031|0000 0000H|<RSCAN0_base> + 07F8H|8, 16, 32|
|Receive buffer data field 1 register 31|RSCAN0RMDF131|0000 0000H|<RSCAN0_base> + 07FCH|8, 16, 32|
|Receive FIFO buffer access ID register 0|RSCAN0RFID0|0000 0000H|<RSCAN0_base> + 0E00H|8, 16, 32|
|Receive FIFO buffer access pointer register 0|RSCAN0RFPTR0|0000 0000H|<RSCAN0_base> + 0E04H|8, 16, 32|
|Receive FIFO buffer access data field 0 register 0|RSCAN0RFDF00|0000 0000H|<RSCAN0_base> + 0E08H|8, 16, 32|
|Receive FIFO buffer access data field 1 register 0|RSCAN0RFDF10|0000 0000H|<RSCAN0_base> + 0E0CH|8, 16, 32|
|Receive FIFO buffer access ID register 1|RSCAN0RFID1|0000 0000H|<RSCAN0_base> + 0E10H|8, 16, 32|
|Receive FIFO buffer access pointer register 1|RSCAN0RFPTR1|0000 0000H|<RSCAN0_base> + 0E14H|8, 16, 32|
|Receive FIFO buffer access data field 0 register 1|RSCAN0RFDF01|0000 0000H|<RSCAN0_base> + 0E18H|8, 16, 32|
|Receive FIFO buffer access data field 1 register 1|RSCAN0RFDF11|0000 0000H|<RSCAN0_base> + 0E1CH|8, 16, 32|
|Receive FIFO buffer access ID register 2|RSCAN0RFID2|0000 0000H|<RSCAN0_base> + 0E20H|8, 16, 32|
|Receive FIFO buffer access pointer register 2|RSCAN0RFPTR2|0000 0000H|<RSCAN0_base> + 0E24H|8, 16, 32|
|Receive FIFO buffer access data field 0 register 2|RSCAN0RFDF02|0000 0000H|<RSCAN0_base> + 0E28H|8, 16, 32|
|Receive FIFO buffer access data field 1 register 2|RSCAN0RFDF12|0000 0000H|<RSCAN0_base> + 0E2CH|8, 16, 32|
|Receive FIFO buffer access ID register 3|RSCAN0RFID3|0000 0000H|<RSCAN0_base> + 0E30H|8, 16, 32|
|Receive FIFO buffer access pointer register 3|RSCAN0RFPTR3|0000 0000H|<RSCAN0_base> + 0E34H|8, 16, 32|
|Receive FIFO buffer access data field 0 register 3|RSCAN0RFDF03|0000 0000H|<RSCAN0_base> + 0E38H|8, 16, 32|
|Receive FIFO buffer access data field 1 register 3|RSCAN0RFDF13|0000 0000H|<RSCAN0_base> + 0E3CH|8, 16, 32|
|Receive FIFO buffer access ID register 4|RSCAN0RFID4|0000 0000H|<RSCAN0_base> + 0E40H|8, 16, 32|
|Receive FIFO buffer access pointer register 4|RSCAN0RFPTR4|0000 0000H|<RSCAN0_base> + 0E44H|8, 16, 32|
|Receive FIFO buffer access data field 0 register 4|RSCAN0RFDF04|0000 0000H|<RSCAN0_base> + 0E48H|8, 16, 32|
|Receive FIFO buffer access data field 1 register 4|RSCAN0RFDF14|0000 0000H|<RSCAN0_base> + 0E4CH|8, 16, 32|
|Receive FIFO buffer access ID register 5|RSCAN0RFID5|0000 0000H|<RSCAN0_base> + 0E50H|8, 16, 32|
|Receive FIFO buffer access pointer register 5|RSCAN0RFPTR5|0000 0000H|<RSCAN0_base> + 0E54H|8, 16, 32|
|Receive FIFO buffer access data field 0 register 5|RSCAN0RFDF05|0000 0000H|<RSCAN0_base> + 0E58H|8, 16, 32|
|Receive FIFO buffer access data field 1 register 5|RSCAN0RFDF15|0000 0000H|<RSCAN0_base> + 0E5CH|8, 16, 32|
|Receive FIFO buffer access ID register 6|RSCAN0RFID6|0000 0000H|<RSCAN0_base> + 0E60H|8, 16, 32|

**Table 21.10 List of RS-CAN Module Registers (9/12)**

|||||**Access**|
|---|---|---|---|---|
|**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Receive FIFO buffer access pointer register 6|RSCAN0RFPTR6|0000 0000H|<RSCAN0_base> + 0E64H|8, 16, 32|
|Receive FIFO buffer access data field 0 register 6|RSCAN0RFDF06|0000 0000H|<RSCAN0_base> + 0E68H|8, 16, 32|
|Receive FIFO buffer access data field 1 register 6|RSCAN0RFDF16|0000 0000H|<RSCAN0_base> + 0E6CH|8, 16, 32|
|Receive FIFO buffer access ID register 7|RSCAN0RFID7|0000 0000H|<RSCAN0_base> + 0E70H|8, 16, 32|
|Receive FIFO buffer access pointer register 7|RSCAN0RFPTR7|0000 0000H|<RSCAN0_base> + 0E74H|8, 16, 32|
|Receive FIFO buffer access data field 0 register 7|RSCAN0RFDF07|0000 0000H|<RSCAN0_base> + 0E78H|8, 16, 32|
|Receive FIFO buffer access data field 1 register 7|RSCAN0RFDF17|0000 0000H|<RSCAN0_base> + 0E7CH|8, 16, 32|
|Transmit/receive FIFO buffer access ID register 0|RSCAN0CFID0|0000 0000H|<RSCAN0_base> + 0E80H|8, 16, 32|
|Transmit/receive FIFO buffer access pointer register 0|RSCAN0CFPTR0|0000 0000H|<RSCAN0_base> + 0E84H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 0 register 0|RSCAN0CFDF00|0000 0000H|<RSCAN0_base> + 0E88H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 1 register 0|RSCAN0CFDF10|0000 0000H|<RSCAN0_base> + 0E8CH|8, 16, 32|
|Transmit/receive FIFO buffer access ID register 1|RSCAN0CFID1|0000 0000H|<RSCAN0_base> + 0E90H|8, 16, 32|
|Transmit/receive FIFO buffer access pointer register 1|RSCAN0CFPTR1|0000 0000H|<RSCAN0_base> + 0E94H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 0 register 1|RSCAN0CFDF01|0000 0000H|<RSCAN0_base> + 0E98H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 1 register 1|RSCAN0CFDF11|0000 0000H|<RSCAN0_base> + 0E9CH|8, 16, 32|
|Transmit/receive FIFO buffer access ID register 2|RSCAN0CFID2|0000 0000H|<RSCAN0_base> + 0EA0H|8, 16, 32|
|Transmit/receive FIFO buffer access pointer register 2|RSCAN0CFPTR2|0000 0000H|<RSCAN0_base> + 0EA4H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 0 register 2|RSCAN0CFDF02|0000 0000H|<RSCAN0_base> + 0EA8H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 1 register 2|RSCAN0CFDF12|0000 0000H|<RSCAN0_base> + 0EACH|8, 16, 32|
|Transmit/receive FIFO buffer access ID register 3|RSCAN0CFID3|0000 0000H|<RSCAN0_base> + 0EB0H|8, 16, 32|
|Transmit/receive FIFO buffer access pointer register 3|RSCAN0CFPTR3|0000 0000H|<RSCAN0_base> + 0EB4H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 0 register 3|RSCAN0CFDF03|0000 0000H|<RSCAN0_base> + 0EB8H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 1 register 3|RSCAN0CFDF13|0000 0000H|<RSCAN0_base> + 0EBCH|8, 16, 32|
|Transmit/receive FIFO buffer access ID register 4|RSCAN0CFID4|0000 0000H|<RSCAN0_base> + 0EC0H|8, 16, 32|
|Transmit/receive FIFO buffer access pointer register 4|RSCAN0CFPTR4|0000 0000H|<RSCAN0_base> + 0EC4H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 0 register 4|RSCAN0CFDF04|0000 0000H|<RSCAN0_base> + 0EC8H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 1 register 4|RSCAN0CFDF14|0000 0000H|<RSCAN0_base> + 0ECCH|8, 16, 32|
|Transmit/receive FIFO buffer access ID register 5|RSCAN0CFID5|0000 0000H|<RSCAN0_base> + 0ED0H|8, 16, 32|
|Transmit/receive FIFO buffer access pointer register 5|RSCAN0CFPTR5|0000 0000H|<RSCAN0_base> + 0ED4H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 0 register 5|RSCAN0CFDF05|0000 0000H|<RSCAN0_base> + 0ED8H|8, 16, 32|
|Transmit/receive FIFO buffer access data field 1 register 5|RSCAN0CFDF15|0000 0000H|<RSCAN0_base> + 0EDCH|8, 16, 32|
|Transmit  buffer ID register 0|RSCAN0TMID0|0000 0000H|<RSCAN0_base> + 1000H|8, 16, 32|
|Transmit  buffer pointer register 0|RSCAN0TMPTR0|0000 0000H|<RSCAN0_base> + 1004H|8, 16, 32|
|Transmit  buffer data field 0 register 0|RSCAN0TMDF00|0000 0000H|<RSCAN0_base> + 1008H|8, 16, 32|
|Transmit  buffer data field 1 register 0|RSCAN0TMDF10|0000 0000H|<RSCAN0_base> + 100CH|8, 16, 32|
|Transmit  buffer ID register 1|RSCAN0TMID1|0000 0000H|<RSCAN0_base> + 1010H|8, 16, 32|
|Transmit  buffer pointer register 1|RSCAN0TMPTR1|0000 0000H|<RSCAN0_base> + 1014H|8, 16, 32|
|Transmit  buffer data field 0 register 1|RSCAN0TMDF01|0000 0000H|<RSCAN0_base> + 1018H|8, 16, 32|
|Transmit  buffer data field 1 register 1|RSCAN0TMDF11|0000 0000H|<RSCAN0_base> + 101CH|8, 16, 32|
|Transmit  buffer ID register 2|RSCAN0TMID2|0000 0000H|<RSCAN0_base> + 1020H|8, 16, 32|
|Transmit  buffer pointer register 2|RSCAN0TMPTR2|0000 0000H|<RSCAN0_base> + 1024H|8, 16, 32|
|Transmit  buffer data field 0 register 2|RSCAN0TMDF02|0000 0000H|<RSCAN0_base> + 1028H|8, 16, 32|
|Transmit  buffer data field 1 register 2|RSCAN0TMDF12|0000 0000H|<RSCAN0_base> + 102CH|8, 16, 32|
|Transmit  buffer ID register 3|RSCAN0TMID3|0000 0000H|<RSCAN0_base> + 1030H|8, 16, 32|
|Transmit  buffer pointer register 3|RSCAN0TMPTR3|0000 0000H|<RSCAN0_base> + 1034H|8, 16, 32|
|Transmit  buffer data field 0 register 3|RSCAN0TMDF03|0000 0000H|<RSCAN0_base> + 1038H|8, 16, 32|
|Transmit  buffer data field 1 register 3|RSCAN0TMDF13|0000 0000H|<RSCAN0_base> + 103CH|8, 16, 32|

**Table 21.10 List of RS-CAN Module Registers (10/12)**

||||||**Access**|
|---|---|---|---|---|---|
||**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Transmit|buffer ID register 4|RSCAN0TMID4|0000 0000H|<RSCAN0_base> + 1040H|8, 16, 32|
|Transmit|buffer pointer register 4|RSCAN0TMPTR4|0000 0000H|<RSCAN0_base> + 1044H|8, 16, 32|
|Transmit|buffer data field 0 register 4|RSCAN0TMDF04|0000 0000H|<RSCAN0_base> + 1048H|8, 16, 32|
|Transmit|buffer data field 1 register 4|RSCAN0TMDF14|0000 0000H|<RSCAN0_base> + 104CH|8, 16, 32|
|Transmit|buffer ID register 5|RSCAN0TMID5|0000 0000H|<RSCAN0_base> + 1050H|8, 16, 32|
|Transmit|buffer pointer register 5|RSCAN0TMPTR5|0000 0000H|<RSCAN0_base> + 1054H|8, 16, 32|
|Transmit|buffer data field 0 register 5|RSCAN0TMDF05|0000 0000H|<RSCAN0_base> + 1058H|8, 16, 32|
|Transmit|buffer data field 1 register 5|RSCAN0TMDF15|0000 0000H|<RSCAN0_base> + 105CH|8, 16, 32|
|Transmit|buffer ID register 6|RSCAN0TMID6|0000 0000H|<RSCAN0_base> + 1060H|8, 16, 32|
|Transmit|buffer pointer register 6|RSCAN0TMPTR6|0000 0000H|<RSCAN0_base> + 1064H|8, 16, 32|
|Transmit|buffer data field 0 register 6|RSCAN0TMDF06|0000 0000H|<RSCAN0_base> + 1068H|8, 16, 32|
|Transmit|buffer data field 1 register 6|RSCAN0TMDF16|0000 0000H|<RSCAN0_base> + 106CH|8, 16, 32|
|Transmit|buffer ID register 7|RSCAN0TMID7|0000 0000H|<RSCAN0_base> + 1070H|8, 16, 32|
|Transmit|buffer pointer register 7|RSCAN0TMPTR7|0000 0000H|<RSCAN0_base> + 1074H|8, 16, 32|
|Transmit|buffer data field 0 register 7|RSCAN0TMDF07|0000 0000H|<RSCAN0_base> + 1078H|8, 16, 32|
|Transmit|buffer data field 1 register 7|RSCAN0TMDF17|0000 0000H|<RSCAN0_base> + 107CH|8, 16, 32|
|Transmit|buffer ID register 8|RSCAN0TMID8|0000 0000H|<RSCAN0_base> + 1080H|8, 16, 32|
|Transmit|buffer pointer register 8|RSCAN0TMPTR8|0000 0000H|<RSCAN0_base> + 1084H|8, 16, 32|
|Transmit|buffer data field 0 register 8|RSCAN0TMDF08|0000 0000H|<RSCAN0_base> + 1088H|8, 16, 32|
|Transmit|buffer data field 1 register 8|RSCAN0TMDF18|0000 0000H|<RSCAN0_base> + 108CH|8, 16, 32|
|Transmit|buffer ID register 9|RSCAN0TMID9|0000 0000H|<RSCAN0_base> + 1090H|8, 16, 32|
|Transmit|buffer pointer register 9|RSCAN0TMPTR9|0000 0000H|<RSCAN0_base> + 1094H|8, 16, 32|
|Transmit|buffer data field 0 register 9|RSCAN0TMDF09|0000 0000H|<RSCAN0_base> + 1098H|8, 16, 32|
|Transmit|buffer data field 1 register 9|RSCAN0TMDF19|0000 0000H|<RSCAN0_base> + 109CH|8, 16, 32|
|Transmit|buffer ID register 10|RSCAN0TMID10|0000 0000H|<RSCAN0_base> + 10A0H|8, 16, 32|
|Transmit|buffer pointer register 10|RSCAN0TMPTR10|0000 0000H|<RSCAN0_base> + 10A4H|8, 16, 32|
|Transmit|buffer data field 0 register 10|RSCAN0TMDF010|0000 0000H|<RSCAN0_base> + 10A8H|8, 16, 32|
|Transmit|buffer data field 1 register 10|RSCAN0TMDF110|0000 0000H|<RSCAN0_base> + 10ACH|8, 16, 32|
|Transmit|buffer ID register 11|RSCAN0TMID11|0000 0000H|<RSCAN0_base> + 10B0H|8, 16, 32|
|Transmit|buffer pointer register 11|RSCAN0TMPTR11|0000 0000H|<RSCAN0_base> + 10B4H|8, 16, 32|
|Transmit|buffer data field 0 register 11|RSCAN0TMDF011|0000 0000H|<RSCAN0_base> + 10B8H|8, 16, 32|
|Transmit|buffer data field 1 register 11|RSCAN0TMDF111|0000 0000H|<RSCAN0_base> + 10BCH|8, 16, 32|
|Transmit|buffer ID register 12|RSCAN0TMID12|0000 0000H|<RSCAN0_base> + 10C0H|8, 16, 32|
|Transmit|buffer pointer register 12|RSCAN0TMPTR12|0000 0000H|<RSCAN0_base> + 10C4H|8, 16, 32|
|Transmit|buffer data field 0 register 12|RSCAN0TMDF012|0000 0000H|<RSCAN0_base> + 10C8H|8, 16, 32|
|Transmit|buffer data field 1 register 12|RSCAN0TMDF112|0000 0000H|<RSCAN0_base> + 10CCH|8, 16, 32|
|Transmit|buffer ID register 13|RSCAN0TMID13|0000 0000H|<RSCAN0_base> + 10D0H|8, 16, 32|
|Transmit|buffer pointer register 13|RSCAN0TMPTR13|0000 0000H|<RSCAN0_base> + 10D4H|8, 16, 32|
|Transmit|buffer data field 0 register 13|RSCAN0TMDF013|0000 0000H|<RSCAN0_base> + 10D8H|8, 16, 32|
|Transmit|buffer data field 1 register 13|RSCAN0TMDF113|0000 0000H|<RSCAN0_base> + 10DCH|8, 16, 32|
|Transmit|buffer ID register 14|RSCAN0TMID14|0000 0000H|<RSCAN0_base> + 10E0H|8, 16, 32|
|Transmit|buffer pointer register 14|RSCAN0TMPTR14|0000 0000H|<RSCAN0_base> + 10E4H|8, 16, 32|
|Transmit|buffer data field 0 register 14|RSCAN0TMDF014|0000 0000H|<RSCAN0_base> + 10E8H|8, 16, 32|
|Transmit|buffer data field 1 register 14|RSCAN0TMDF114|0000 0000H|<RSCAN0_base> + 10ECH|8, 16, 32|
|Transmit|buffer ID register 15|RSCAN0TMID15|0000 0000H|<RSCAN0_base> + 10F0H|8, 16, 32|
|Transmit|buffer pointer register 15|RSCAN0TMPTR15|0000 0000H|<RSCAN0_base> + 10F4H|8, 16, 32|
|Transmit|buffer data field 0 register 15|RSCAN0TMDF015|0000 0000H|<RSCAN0_base> + 10F8H|8, 16, 32|

**Table 21.10 List of RS-CAN Module Registers (11/12)**

||||||**Access**|
|---|---|---|---|---|---|
||**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Transmit|buffer data field 1 register 15|RSCAN0TMDF115|0000 0000H|<RSCAN0_base> + 10FCH|8, 16, 32|
|Transmit|buffer ID register 16|RSCAN0TMID16|0000 0000H|<RSCAN0_base> + 1100H|8, 16, 32|
|Transmit|buffer pointer register 16|RSCAN0TMPTR16|0000 0000H|<RSCAN0_base> + 1104H|8, 16, 32|
|Transmit|buffer data field 0 register 16|RSCAN0TMDF016|0000 0000H|<RSCAN0_base> + 1108H|8, 16, 32|
|Transmit|buffer data field 1 register 16|RSCAN0TMDF116|0000 0000H|<RSCAN0_base> + 110CH|8, 16, 32|
|Transmit|buffer ID register 17|RSCAN0TMID17|0000 0000H|<RSCAN0_base> + 1110H|8, 16, 32|
|Transmit|buffer pointer register 17|RSCAN0TMPTR17|0000 0000H|<RSCAN0_base> + 1114H|8, 16, 32|
|Transmit|buffer data field 0 register 17|RSCAN0TMDF017|0000 0000H|<RSCAN0_base> + 1118H|8, 16, 32|
|Transmit|buffer data field 1 register 17|RSCAN0TMDF117|0000 0000H|<RSCAN0_base> + 111CH|8, 16, 32|
|Transmit|buffer ID register 18|RSCAN0TMID18|0000 0000H|<RSCAN0_base> + 1120H|8, 16, 32|
|Transmit|buffer pointer register 18|RSCAN0TMPTR18|0000 0000H|<RSCAN0_base> + 1124H|8, 16, 32|
|Transmit|buffer data field 0 register 18|RSCAN0TMDF018|0000 0000H|<RSCAN0_base> + 1128H|8, 16, 32|
|Transmit|buffer data field 1 register 18|RSCAN0TMDF118|0000 0000H|<RSCAN0_base> + 112CH|8, 16, 32|
|Transmit|buffer ID register 19|RSCAN0TMID19|0000 0000H|<RSCAN0_base> + 1130H|8, 16, 32|
|Transmit|buffer pointer register 19|RSCAN0TMPTR19|0000 0000H|<RSCAN0_base> + 1134H|8, 16, 32|
|Transmit|buffer data field 0 register 19|RSCAN0TMDF019|0000 0000H|<RSCAN0_base> + 1138H|8, 16, 32|
|Transmit|buffer data field 1 register 19|RSCAN0TMDF119|0000 0000H|<RSCAN0_base> + 113CH|8, 16, 32|
|Transmit|buffer ID register 20|RSCAN0TMID20|0000 0000H|<RSCAN0_base> + 1140H|8, 16, 32|
|Transmit|buffer pointer register 20|RSCAN0TMPTR20|0000 0000H|<RSCAN0_base> + 1144H|8, 16, 32|
|Transmit|buffer data field 0 register 20|RSCAN0TMDF020|0000 0000H|<RSCAN0_base> + 1148H|8, 16, 32|
|Transmit|buffer data field 1 register 20|RSCAN0TMDF120|0000 0000H|<RSCAN0_base> + 114CH|8, 16, 32|
|Transmit|buffer ID register 21|RSCAN0TMID21|0000 0000H|<RSCAN0_base> + 1150H|8, 16, 32|
|Transmit|buffer pointer register 21|RSCAN0TMPTR21|0000 0000H|<RSCAN0_base> + 1154H|8, 16, 32|
|Transmit|buffer data field 0 register 21|RSCAN0TMDF021|0000 0000H|<RSCAN0_base> + 1158H|8, 16, 32|
|Transmit|buffer data field 1 register 21|RSCAN0TMDF121|0000 0000H|<RSCAN0_base> + 115CH|8, 16, 32|
|Transmit|buffer ID register 22|RSCAN0TMID22|0000 0000H|<RSCAN0_base> + 1160H|8, 16, 32|
|Transmit|buffer pointer register 22|RSCAN0TMPTR22|0000 0000H|<RSCAN0_base> + 1164H|8, 16, 32|
|Transmit|buffer data field 0 register 22|RSCAN0TMDF022|0000 0000H|<RSCAN0_base> + 1168H|8, 16, 32|
|Transmit|buffer data field 1 register 22|RSCAN0TMDF122|0000 0000H|<RSCAN0_base> + 116CH|8, 16, 32|
|Transmit|buffer ID register 23|RSCAN0TMID23|0000 0000H|<RSCAN0_base> + 1170H|8, 16, 32|
|Transmit|buffer pointer register 23|RSCAN0TMPTR23|0000 0000H|<RSCAN0_base> + 1174H|8, 16, 32|
|Transmit|buffer data field 0 register 23|RSCAN0TMDF023|0000 0000H|<RSCAN0_base> + 1178H|8, 16, 32|
|Transmit|buffer data field 1 register 23|RSCAN0TMDF123|0000 0000H|<RSCAN0_base> + 117CH|8, 16, 32|
|Transmit|buffer ID register 24|RSCAN0TMID24|0000 0000H|<RSCAN0_base> + 1180H|8, 16, 32|
|Transmit|buffer pointer register 24|RSCAN0TMPTR24|0000 0000H|<RSCAN0_base> + 1184H|8, 16, 32|
|Transmit|buffer data field 0 register 24|RSCAN0TMDF024|0000 0000H|<RSCAN0_base> + 1188H|8, 16, 32|
|Transmit|buffer data field 1 register 24|RSCAN0TMDF124|0000 0000H|<RSCAN0_base> + 118CH|8, 16, 32|
|Transmit|buffer ID register 25|RSCAN0TMID25|0000 0000H|<RSCAN0_base> + 1190H|8, 16, 32|
|Transmit|buffer pointer register 25|RSCAN0TMPTR25|0000 0000H|<RSCAN0_base> + 1194H|8, 16, 32|
|Transmit|buffer data field 0 register 25|RSCAN0TMDF025|0000 0000H|<RSCAN0_base> + 1198H|8, 16, 32|
|Transmit|buffer data field 1 register 25|RSCAN0TMDF125|0000 0000H|<RSCAN0_base> + 119CH|8, 16, 32|
|Transmit|buffer ID register 26|RSCAN0TMID26|0000 0000H|<RSCAN0_base> + 11A0H|8, 16, 32|
|Transmit|buffer pointer register 26|RSCAN0TMPTR26|0000 0000H|<RSCAN0_base> + 11A4H|8, 16, 32|
|Transmit|buffer data field 0 register 26|RSCAN0TMDF026|0000 0000H|<RSCAN0_base> + 11A8H|8, 16, 32|
|Transmit|buffer data field 1 register 26|RSCAN0TMDF126|0000 0000H|<RSCAN0_base> + 11ACH|8, 16, 32|
|Transmit|buffer ID register 27|RSCAN0TMID27|0000 0000H|<RSCAN0_base> + 11B0H|8, 16, 32|
|Transmit|buffer pointer register 27|RSCAN0TMPTR27|0000 0000H|<RSCAN0_base> + 11B4H|8, 16, 32|

**Table 21.10 List of RS-CAN Module Registers (12/12)**

||||||**Access**|
|---|---|---|---|---|---|
||**Register Name**|**Symbol**|**After Reset**|**Address**|**Size**|
|Transmit|buffer data field 0 register 27|RSCAN0TMDF027|0000 0000H|<RSCAN0_base> + 11B8H|8, 16, 32|
|Transmit|buffer data field 1 register 27|RSCAN0TMDF127|0000 0000H|<RSCAN0_base> + 11BCH|8, 16, 32|
|Transmit|buffer ID register 28|RSCAN0TMID28|0000 0000H|<RSCAN0_base> + 11C0H|8, 16, 32|
|Transmit|buffer pointer register 28|RSCAN0TMPTR28|0000 0000H|<RSCAN0_base> + 11C4H|8, 16, 32|
|Transmit|buffer data field 0 register 28|RSCAN0TMDF028|0000 0000H|<RSCAN0_base> + 11C8H|8, 16, 32|
|Transmit|buffer data field 1 register 28|RSCAN0TMDF128|0000 0000H|<RSCAN0_base> + 11CCH|8, 16, 32|
|Transmit|buffer ID register 29|RSCAN0TMID29|0000 0000H|<RSCAN0_base> + 11D0H|8, 16, 32|
|Transmit|buffer pointer register 29|RSCAN0TMPTR29|0000 0000H|<RSCAN0_base> + 11D4H|8, 16, 32|
|Transmit|buffer data field 0 register 29|RSCAN0TMDF029|0000 0000H|<RSCAN0_base> + 11D8H|8, 16, 32|
|Transmit|buffer data field 1 register 29|RSCAN0TMDF129|0000 0000H|<RSCAN0_base> + 11DCH|8, 16, 32|
|Transmit|buffer ID register 30|RSCAN0TMID30|0000 0000H|<RSCAN0_base> + 11E0H|8, 16, 32|
|Transmit|buffer pointer register 30|RSCAN0TMPTR30|0000 0000H|<RSCAN0_base> + 11E4H|8, 16, 32|
|Transmit|buffer data field 0 register 30|RSCAN0TMDF030|0000 0000H|<RSCAN0_base> + 11E8H|8, 16, 32|
|Transmit|buffer data field 1 register 30|RSCAN0TMDF130|0000 0000H|<RSCAN0_base> + 11ECH|8, 16, 32|
|Transmit|buffer ID register 31|RSCAN0TMID31|0000 0000H|<RSCAN0_base> + 11F0H|8, 16, 32|
|Transmit|buffer pointer register 31|RSCAN0TMPTR31|0000 0000H|<RSCAN0_base> + 11F4H|8, 16, 32|
|Transmit|buffer data field 0 register 31|RSCAN0TMDF031|0000 0000H|<RSCAN0_base> + 11F8H|8, 16, 32|
|Transmit|buffer data field 1 register 31|RSCAN0TMDF131|0000 0000H|<RSCAN0_base> + 11FCH|8, 16, 32|
|Transmit|history access register 0|RSCAN0THLACC0|0000 0000H|<RSCAN0_base> + 1800H|8, 16, 32|
|Transmit|history access register 1|RSCAN0THLACC1|0000 0000H|<RSCAN0_base> + 1804H|8, 16, 32|

**Table 21.11 Transmit Buffer p Allocated to Each Channel**

||**CANm**|
|---|---|
|Transmit buffer<br>p|Transmit buffer 16m + 0|
||Transmit buffer 16m + 1|
||Transmit buffer 16m + 2|
||Transmit buffer 16m + 3|
||Transmit buffer 16m + 4|
||Transmit buffer 16m + 5|
||Transmit buffer 16m + 6|
||Transmit buffer 16m + 7|
||Transmit buffer 16m + 8|
||Transmit buffer 16m + 9|
||Transmit buffer 16m + 10|
||Transmit buffer 16m + 11|
||Transmit buffer 16m + 12|
||Transmit buffer 16m + 13|
||Transmit buffer 16m + 14|
||Transmit buffer 16m + 15|

**Table 21.12 Transmit/Receive FIFO Buffer k Allocated to Each Channel**

||**CANm**|
|---|---|
|Transmit/receive FIFO buffer<br>k|Transmit/receive FIFO buffer 3m + 0|
||Transmit/receive FIFO buffer 3m + 1|
||Transmit/receive FIFO buffer 3m + 2|

**Table 21.13 Transmit Buffer p Linked to the Transmit/Receive FIFO Buffer by the Setting of Bits CFTML[3:0]**

|**Setting of Bits CFTML[3:0]**|**Transmit Buffer p Linked to the Transmit/Receive FIFO Buffer**|
|---|---|
|0000B|Transmit buffer 16m + 0|
|0001B|Transmit buffer 16m + 1|
|0010B|Transmit buffer 16m + 2|
|0011B|Transmit buffer 16m + 3|
|0100B|Transmit buffer 16m + 4|
|0101B|Transmit buffer 16m + 5|
|0110B|Transmit buffer 16m + 6|
|0111B|Transmit buffer 16m + 7|
|1000B|Transmit buffer 16m + 8|
|1001B|Transmit buffer 16m + 9|
|1010B|Transmit buffer 16m + 10|
|1011B|Transmit buffer 16m + 11|
|1100B|Transmit buffer 16m + 12|
|1101B|Transmit buffer 16m + 13|
|1110B|Transmit buffer 16m + 14|
|1111B|Transmit buffer 16m + 15|

**Table 21.14 Transmit Buffer p Allocated to the Transmit Queue of Each Channel**

|**Setting of Bits TXQDC[3:0]**|**Transmit Buffer p Allocated to the Transmit Queue**|
|---|---|
|0000B|Setting prohibited|
|0001B|Setting prohibited|
|0010B|Transmit buffer 16m + 15 to 16m + 13|
|0011B|Transmit buffer 16m + 15 to 16m + 12|
|0100B|Transmit buffer 16m + 15 to 16m + 11|
|0101B|Transmit buffer 16m + 15 to 16m + 10|
|0110B|Transmit buffer 16m + 15 to 16m + 9|
|0111B|Transmit buffer 16m + 15 to 16m + 8|
|1000B|Transmit buffer 16m + 15 to 16m + 7|
|1001B|Transmit buffer 16m + 15 to 16m + 6|
|1010B|Transmit buffer 16m + 15 to 16m + 5|
|1011B|Transmit buffer 16m + 15 to 16m + 4|
|1100B|Transmit buffer 16m + 15 to 16m + 3|
|1101B|Transmit buffer 16m + 15 to 16m + 2|
|1110B|Transmit buffer 16m + 15 to 16m + 1|
|1111B|Transmit buffer 16m + 15 to 16m + 0|

## 21.3.1 RSCAN0CmCFG — Channel Configuration Register (m = 0 or 1)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0000H+ (m * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—|—|—|—|SJW[1:0]||—||TSEG2[2:0]|||TSEG1[3:0]|||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|—|||||BRP[9:0]||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 21.15 RSCAN0CmCFG register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 26|Reserved|These bits are always read as 0. The write value should always be 0.|
|25, 24|SJW[1:0]|Resynchronization Jump Width Control|
|||b25  b24|
|||0    0: 1 Tq|
|||0    1: 2 Tq|
|||1    0: 3 Tq|
|||1    1: 4 Tq|
|23|Reserved|This bit is always read as 0. The write value should always be 0.|
|22 to 20|TSEG2[2:0]|Time Segment 2 Control|
|||b22  b21  b20|
|||0    0    0: Setting prohibited|
|||0    0    1: 2 Tq|
|||0    1    0: 3 Tq|
|||0    1    1: 4 Tq|
|||1    0    0: 5 Tq|
|||1    0    1: 6 Tq|
|||1    1    0: 7 Tq|
|||1    1    1: 8 Tq|
|19 to 16|TSEG1[3:0]|Time Segment 1 Control|
|||b19  b18  b17  b16|
|||0    0    0    0: Setting prohibited|
|||0    0    0    1: Setting prohibited|
|||0    0    1    0: Setting prohibited|
|||0    0    1    1: 4 Tq|
|||0    1    0    0: 5 Tq|
|||0    1    0    1: 6 Tq|
|||0    1    1    0: 7 Tq|
|||0    1    1    1: 8 Tq|
|||1    0    0    0: 9 Tq|
|||1    0    0    1: 10 Tq|
|||1    0    1    0: 11 Tq|
|||1    0    1    1: 12 Tq|
|||1    1    0    0: 13 Tq|
|||1    1    0    1: 14 Tq|
|||1    1    1    0: 15 Tq|
|||1    1    1    1: 16 Tq|
|15 to 10|Reserved|These bits are always read as 0. The write value should always be 0.|
|9 to 0|BRP[9:0]|Prescaler Division Ratio Set|
|||When these bits are set to P (0 to 1023), the baud rate prescaler divides fCAN|
|||by P + 1.|

Modify the RSCAN0CmCFG register in channel reset mode or channel halt mode. Set this register before requesting a transition to channel communication mode or channel wait mode. For a description of the bit timing parameters and settings, see Section 21.10.1, Initial Settings .

## SJW[1:0] Bits

These bits are used to specify a Tq value for the resynchronization jump width. Allowed values are 1 Tq to 4 Tq, inclusive.

Set a value less than or equal to the value of the TSEG2 bits.

## TSEG2[2:0] Bits

These bits are used to specify a Tq value for the length of phase buffer segment 2 (PHASE_SEG2). Allowed values are 2 Tq to 8 Tq, inclusive.

Set a value smaller than the value of the TSEG1 bits.

## TSEG1[3:0] Bits

These bits are used to specify a Tq value for the total length of the propagation time segment (PROP_SEG) and phase buffer segment 1 (PHASE_SEG1).

Allowed values are 4 Tq to 16 Tq, inclusive.

## BRP[9:0] Bits

The CANmTq (fCANTQm) clock is calculated by dividing the CAN clock (fCAN) by the baud rate prescaler, ((BRP[9:0]) + 1). One clock cycle of the CANmTq clock is 1 Time Quantum (Tq).

## 21.3.2 RSCAN0CmCTR — Channel Control Register (m = 0 or 1)

|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0004H+ (m * 0010H)<br>**Initial value:**<br>0000 0005H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>CTMS[1:0]<br>CTME<br>ERRD<br>BOM[1:0]<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>ALIE<br>BLIE<br>OLIE<br>BORIE<br>BOEIE<br>EPIE<br>EWIE<br>BEIE<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R|20<br>19<br>18<br>17<br>16|20<br>19<br>18<br>17<br>16|20<br>19<br>18<br>17<br>16|20<br>19<br>18<br>17<br>16|20<br>19<br>18<br>17<br>16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|CTMS[1:0]||CTME|ERRD|BOM[1:0]||—|—|—|—|TAIE|
|||||||0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>10<br>9<br>8<br>7<br>6<br>5||||||0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R/W<br>4<br>3<br>2<br>1<br>0|||||
||ALIE|BLIE|OLIE|BORIE|BOEIE|EPIE|EWIE|BEIE|—|—|—|—|RTBO|CSLPR|CHMDC[1:0]||
|||||||0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R<br>R<br>R||||||0<br>0<br>1<br>0<br>1<br>R<br>R/W<br>R/W<br>R/W<br>R/W|||||

**Table 21.16 RSCAN0CmCTR register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 27|Reserved|These bits are always read as 0. The write value should always be 0.|
|26, 25|CTMS[1:0]|Communication Test Mode Select|
|||b26  b25|
|||0    0: Standard test mode|
|||0    1: Listen-only mode|
|||1    0: Self-test mode 0 (external loopback mode)|
|||1    1: Self-test mode 1 (internal loopback mode)|
|24|CTME|Communication Test Mode Enable|
|||0: Communication test mode is disabled.|
|||1: Communication test mode is enabled.|
|23|ERRD|Error Display Mode Select|
|||0: Error flags are displayed only for the first error information after bits 14 to 8|
|||in RSCAN0CmERFL are all cleared.|
|||1: Error flags for all error information are displayed.|
|22, 21|BOM[1:0]|Bus Off Recovery Mode Select|
|||b22  b21|
|||0    0: ISO11898-1 compliant|
|||0    1: Entry to channel halt mode automatically at bus-off entry|
|||1    0: Entry to channel halt mode automatically at bus-off end|
|||1    1: Entry to channel halt mode (during bus-off recovery period) by program|
|||request|
|20 to 17|Reserved|These bits are always read as 0. The write value should always be 0.|
|16|TAIE|Transmit Abort Interrupt Enable|
|||0: Transmit abort interrupt is disabled.|
|||1: Transmit abort interrupt is enabled.|
|15|ALIE|Arbitration Lost Interrupt Enable|
|||0: Arbitration lost interrupt is disabled.|
|||1: Arbitration lost interrupt is enabled.|
|14|BLIE|Bus Lock Interrupt Enable|
|||0: Bus lock interrupt is disabled.|
|||1: Bus lock interrupt is enabled.|
|13|OLIE|Overload Frame Transmit Interrupt Enable|
|||0: Overload frame transmit interrupt is disabled.|
|||1: Overload frame transmit interrupt is enabled.|
|12|BORIE|Bus Off Recovery Interrupt Enable|
|||0: Bus off recovery interrupt is disabled.|
|||1: Bus off recovery interrupt is enabled.|

**Table 21.16 RSCAN0CmCTR register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|11|BOEIE|Bus Off Entry Interrupt Enable|
|||0: Bus off entry interrupt is disabled.|
|||1: Bus off entry interrupt is enabled.|
|10|EPIE|Error Passive Interrupt Enable|
|||0: Error passive interrupt is disabled.|
|||1: Error passive interrupt is enabled.|
|9|EWIE|Error Warning Interrupt Enable|
|||0: Error warning interrupt is disabled.|
|||1: Error warning interrupt is enabled.|
|8|BEIE|Bus Error Interrupt Enable|
|||0: Bus error interrupt is disabled.|
|||1: Bus error interrupt is enabled.|
|7 to 4|Reserved|These bits are always read as 0. The write value should always be 0.|
|3|RTBO|Forcible Return from Bus-off|
|||When this bit is set to 1, forcible return from the bus off state is made. This bit is|
|||always read as 0.|
|2|CSLPR|Channel Stop Mode|
|||0: Other than channel stop mode|
|||1: Channel stop mode|
|1, 0|CHMDC[1:0]|Mode Select|
|||b1   b0|
|||0    0: Channel communication mode|
|||0    1: Channel reset mode|
|||1    0: Channel halt mode|
|||1    1: Setting prohibited|

## CTMS[1:0] Bits

These bits are used to select a communication test mode. Modify these bits in channel halt mode only. These bits are set to 0 in channel reset mode.

## CTME Bit

Setting this bit to 1 enables communication test mode. Modify these bits in channel halt mode. This bit is set to 0 in channel reset mode.

## ERRD Bit

This bit is used to control the display mode of bits 14 to 8 in the RSCAN0CmERFL register. When this bit is clear to 0, only the flags of the first error are set to 1. If two or more errors occur in the first error, all the flags of the detected errors are set to 1.

When this bit is set to 1, all the flags of errors that have occurred are set to 1 regardless of the error occurrence order.

Modify this bit only in channel reset mode or channel halt mode.

## BOM[1:0] Bits

These bits are used to select the bus off recovery mode of the RS-CAN module.

When the BOM[1:0] bits are set to 00B, return from the bus off state to the error active state is compliant with the CAN specifications. That is, the RS-CAN module reenters the CAN communication (error active state) after 11 consecutive recessive bits are detected 128 times. A bus off recovery interrupt request is generated at the time of return from the bus off state. Even if the CHMDC[1:0] bits are set to 10B (channel halt mode) before recessive bits are detected 128 times, the RS-CAN module does not transition to channel halt mode until recessive bits are detected 128 times.

When the RS-CAN module reaches the bus off state when the BOM[1:0] bits are set to 01B, the CHMDC[1:0] bits in the RSCAN0CmCTR register (m = 0 or 1) are set to 10B and the RS-CAN module transitions to channel halt mode. No bus off recovery interrupt request is generated at the time of return from the bus off state and the TEC[7:0] and REC[7:0] bits in the RSCAN0CmSTS register are cleared to 00H.

When the RS-CAN module reaches the bus off state when the BOM[1:0] bits are set to 10B, the CHMDC[1:0] bits are set to 10B and the RS-CAN module transitions to channel halt mode after return from the bus off state (11 consecutive recessive bits are detected 128 times). A bus off recovery interrupt request is generated at the time of return from the bus off state and the TEC[7:0] and REC[7:0] bits are cleared to 00H.

When the BOM[1:0] bits are set to 11B and the CHMDC[1:0] bits are set to 10B while the RS-CAN module is in the bus off state, the RS-CAN module transitions to channel halt mode. No bus off recovery interrupt request is generated at the time of return from the bus off state and the TEC[7:0] and REC[7:0] bits are cleared to 00H. However, if 11 consecutive recessive bits are detected 128 times and the RS-CAN module has recovered to the error active state from the bus off state before the CHMDC[1:0] bits are set to 10B, a bus off recovery interrupt request is generated.

If the CPU requests a transition to channel reset mode at the same time as the RS-CAN module transition to channel halt mode (at bus off entry when the BOM[1:0] bits are 01B or at bus off end when the BOM[1:0] bits are 10B), the CPU’s request takes precedence. Modify the BOM bits only in channel reset mode.

## TAIE Bit

When transmit abort of the transmit buffer is completed with the TAIE bit set to 1, an interrupt request is generated. Modify this bit only in channel reset mode.

## ALIE Bit

When the ALF flag in the RSCAN0CmERFL register is set to 1 with the ALIE bit set to 1, an error interrupt request is generated. Modify this bit only in channel reset mode.

## BLIE Bit

When the BLF flag in the RSCAN0CmERFL register is set to 1 with the BLIE bit set to 1, an error interrupt request is generated. Modify this bit only in channel reset mode.

## OLIE Bit

When the OVLF flag in the RSCAN0CmERFL register is set to 1 with the OLIE bit set to 1, an error interrupt request is generated. Modify this bit only in channel reset mode.

## BORIE Bit

When the BORF flag in the RSCAN0CmERFL register is set to 1 with the BORIE bit set to 1, an error interrupt request is generated. Modify this bit only in channel reset mode.

## BOEIE Bit

When the BOEF flag in the RSCAN0CmERFL register is set to 1 with the BOEIE bit set to 1, an error interrupt request is generated. Modify this bit only in channel reset mode.

## EPIE Bit

When the EPF flag in the RSCAN0CmERFL register is set to 1 with the EPIE bit set to 1, an error interrupt request is generated. Modify this bit only in channel reset mode.

## EWIE Bit

When the EWF flag in the RSCAN0CmERFL register is set to 1 with the EWIE bit set to 1, an error interrupt request is generated. Modify this bit only in channel reset mode.

## BEIE Bit

When the BEF flag in the RSCAN0CmERFL register is set to 1 with the BEIE bit set to 1, an error interrupt request is generated. Modify this bit only in channel reset mode.

## RTBO Bit

Setting this bit to 1 in the bus off state forcibly returns the state from the bus off state to the error active state. This bit is automatically cleared to 0. Setting this bit to 1 clears the TEC[7:0] and REC[7:0] bits in the RSCAN0CmSTS register to 00H and also clears the BOSTS flag in the RSCAN0CmSTS register to 0 (not in bus off state). The other registers remain unchanged. No bus off recovery interrupt request is generated upon return from the bus off state in this case. Use this bit only when the BOM[1:0] bits in the RSCAN0CmCTR register are 00B (ISO11898-1 compliant).

A delay of up to 1 CAN bit time occurs after the RTBO bit is set to 1 until the RSCAN module transitions to the error active state. Set this bit to 1 in channel communication mode.

## CSLPR Bit

Setting this bit to 1 places the channel into channel stop mode.

Clearing this bit to 0 makes the channel exit channel stop mode.

Modify this bit from 0 to 1 only in channel reset mode.

## CHMDC[1:0] Bits

These bits are used to select a channel mode (channel communication mode, channel reset mode, or channel halt mode). For details, see Section 21.5.2, Channel Modes . Setting the CSLPR bit to 1 in channel reset mode allows transition to channel stop mode. Do not set the CHMDC[1:0] bits to 11B. When the CAN module has automatically transitioned to channel halt mode based on the setting of the BOM[1:0] bits, the CHMDC[1:0] bits automatically become 10B.

## 21.3.3 RSCAN0CmSTS — Channel Status Register (m = 0 or 1)

|**Access:**|**Access:**|Can be|read in 8-, 16-, and 32-bit units|read in 8-, 16-, and 32-bit units|read in 8-, 16-, and 32-bit units|read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0008H+ (m * 0010H)|||||||||||||||
|**Initial value:**||0000 0005H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||TEC[7:0]||||||||REC[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|—|—|—|COMST<br>S|RECST<br>S|TRMST<br>S|BOSTS|EPSTS|CSLPST<br>S|CHLTST<br>S|CRSTS<br>TS|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|1|0|1|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 21.17 RSCAN0CmSTS register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 24|TEC[7:0]|The transmit error counter (TEC) can be read.|
|23|to 16|REC[7:0]|The receive error counter (REC) can be read.|
|15|to 8|Reserved|These bits are always read as 0.|
|7||COMSTS|Communication Status Flag|
||||0: Communication is not ready.|
||||1: Communication is ready.|
|6||RECSTS|Receive Status Flag|
||||0: Bus idle, in transmission or bus off state|
||||1: In reception|
|5||TRMSTS|Transmit Status Flag|
||||0: Bus idle or in reception|
||||1: In transmission or bus off state|
|4||BOSTS|Bus Off Status Flag|
||||0: Not in bus off state|
||||1: In bus off state|
|3||EPSTS|Error Passive Status Flag|
||||0: Not in error passive state|
||||1: In error passive state|
|2||CSLPSTS|Channel Stop Status Flag|
||||0: Not in channel stop mode|
||||1: In channel stop mode|
|1||CHLTSTS|Channel Halt Status Flag|
||||0: Not in channel halt mode|
||||1: In channel halt mode|
|0||CRSTSTS|Channel Reset Status Flag|
||||0: Not in channel reset mode|
||||1: In channel reset mode|

## TEC[7:0] Bits

These bits contain the transmit error counter value. For transmit error counter increment/decrement conditions, see the CAN specification (ISO11898-1).

These bits are cleared to 0 in channel reset mode.

## REC[7:0] Bits

These bits contain the receive error counter value. For receive error counter increment/decrement conditions, see the CAN specifications (ISO11898-1).

These bits are cleared to 0 in channel reset mode.

## COMSTS Flag

This bit indicates that communication is ready.

This flag becomes 1 when the CAN module has detected 11 consecutive recessive bits after it has transitioned from channel reset mode or channel halt mode to channel communication mode. This flag is cleared to 0 in channel reset mode or channel halt mode.

## RECSTS Flag

This flag is set to 1 when reception has started, and is cleared to 0 when the bus has become idle or transmission has started.

## TRMSTS Flag

This flag is set to 1 when transmission has started, and is cleared to 0 when the bus has become idle or reception has started. This flag remains 1 in the bus off state.

## BOSTS Flag

This flag is set to 1 when the bus off state (TEC[7:0] > 255) is entered. It is cleared to 0 when the CAN module has exited the bus off state.

## EPSTS Flag

This flag is set to 1 when the RS-CAN module has entered the error passive state ((128  TEC[7:0]  255) or (128  REC[7:0])), It is cleared to 0 when the RS-CAN module has exited the error passive state or has entered channel reset mode.

## CSLPSTS Flag

This flag is set to 1 when the CAN module has transitioned to channel stop mode, and is cleared to 0 when the CAN module has returned from channel stop mode.

## CHLTSTS Flag

This flag is set to 1 when the CAN module has transitioned to channel halt mode, and is cleared to 0 when the CAN module has returned from channel halt mode.

## CRSTSTS Flag

This flag is set to 1 when the CAN module has transitioned to channel reset mode, and is cleared to 0 when the CAN module has transitioned to channel communication mode or channel halt mode. This flag remains 1 when the CAN module transitions from channel reset mode to channel stop mode.

## 21.3.4 RSCAN0CmERFL — Channel Error Flag Register (m = 0 or 1)

||**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**|||<RSCAN0_base> + 000CH+ (m||||* 0010H)|||||||||||
|**Initial value:**|||0000|0000H||||||||||||||
|Bit|31||30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—||||||||CRCREG[14:0]|||||||||
|Initial value|0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15||14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—||ADERR|B0ERR|B1ERR|CERR|AERR|FERR|SERR|ALF|BLF|OVLF|BORF|BOEF|EPF|EWF|BEF|
|Initial value|0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|R/W*1|

Note 1. The only effective value for writing to this flag bit is 0, which clears the bit. Otherwise writing to the bit results in retention of its state.

**Table 21.18 RSCAN0CmERFL register contents (1/2)**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31||Reserved|This bit is always read as 0. The write value should always be 0.|
|30|to 16|CRCREG[14:0]|CRC Calculation Data|
||||A CRC value calculated based on the transmit message or receive message is|
||||indicated.|
|15||Reserved|This bit is always read as 0. The write value should always be 0.|
|14||ADERR|ACK Delimiter Error Flag|
||||0: No ACK delimiter error is detected.|
||||1: ACK delimiter error is detected.|
|13||B0ERR|Dominant Bit Error Flag|
||||0: No dominant bit error is detected.|
||||1: Dominant bit error is detected.|
|12||B1ERR|Recessive Bit Error Flag|
||||0: No recessive bit error is detected.|
||||1: Recessive bit error is detected.|
|11||CERR|CRC Error Flag|
||||0: No CRC error is detected.|
||||1: CRC error is detected.|
|10||AERR|ACK Error Flag|
||||0: No ACK error is detected.|
||||1: ACK error is detected.|
|9||FERR|Form Error Flag|
||||0: No form error is detected.|
||||1: Form error is detected.|
|8||SERR|Stuff Error Flag|
||||0: No stuff error is detected.|
||||1: Stuff error is detected.|
|7||ALF|Arbitration-lost Flag|
||||0: No arbitration-lost is detected.|
||||1: Arbitration-lost is detected.|
|6||BLF|Dominant Lock Flag|
||||0: No dominant lock is detected.|
||||1: Dominant lock is detected.|

**Table 21.18 RSCAN0CmERFL register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|5|OVLF|Overload Flag|
|||0: No overload is detected.|
|||1: Overload is detected.|
|4|BORF|Bus Off Recovery Flag|
|||0: No bus off recovery is detected.|
|||1: Bus off recovery is detected.|
|3|BOEF|Bus Off Entry Flag|
|||0: No bus off entry is detected.|
|||1: Bus off entry is detected.|
|2|EPF|Error Passive Flag|
|||0: No error passive is detected.|
|||1: Error passive is detected.|
|1|EWF|Error Warning Flag|
|||0: No error warning is detected.|
|||1: Error warning is detected.|
|0|BEF|Protocol Error Flag|
|||0: No protocol error is detected.|
|||1: Protocol error is detected.|

See the CAN specification (ISO11898-1) for a description of error occurrence conditions. To clear each flag of this register, the program must write a 0 to the corresponding bit. These flags cannot be set to 1 by the program. If any of these error occurs at the same time that the program writes 0 to the flag, the flag is still set to 1. The channel reset mode transition clears all of these flags to 0. If the ERRD bit in the RSCAN0CmCTR register is set to 0 (ie, only the flags from the first error event are displayed) and an error related to bits 14 to 8 of RSCAN0CmERFL is detected, the flag bits are only set by the error event if bits 14 to 8 were all 0 at the time the error occurred.

## CRCREG[14:0] Flag

When the CTME bit in the RSCAN0CmCTR register is set to 1 (communication test mode is enabled), the CRC value calculated based on the transmit or receive message can be read. When the CTME bit is set to 0 (communication test mode is disabled), these bits are always read as 0.

## ADERR Flag

This flag is set to 1 when a form error has been detected in the ACK delimiter during transmission.

## B0ERR Flag

This flag is set to 1 when a recessive bit has been detected though a dominant bit was transmitted.

## B1ERR Flag

This flag is set to 1 when a dominant bit has been detected though a recessive bit was transmitted.

## CERR Flag

This flag is set to 1 when a CRC error has been detected.

## AERR Flag

This flag is set to 1 when an ACK error has been detected.

## FERR Flag

This flag is set to 1 when a form error has been detected.

## SERR Flag

This flag is set to 1 when a stuff error has been detected.

## ALF Flag

This flag is set to 1 when an arbitration-lost has been detected.

## BLF Flag

This flag is set to 1 when 32 consecutive dominant bits have been detected on the CAN bus in channel communication mode. After that, dominant lock can be detected again if any of the following conditions is met.

- a recessive bit is detected after the BLF bit has been cleared from 1 to 0.

- the CAN module transitions to channel reset mode and returns to channel communication mode after the BLF bit has been cleared from 1 to 0.

## OVLF Flag

This flag is set to 1 when the overload frame transmit condition has been detected when performing reception or transmission.

## BORF Flag

This flag is set to 1 when 11 consecutive recessive bits have been detected 128 times and the CAN module returns from the bus off state. However, this flag is not set to 1 if the CAN module returns from the bus off state in any of the following ways before 11 consecutive recessive bits are detected 128 times.

- The CHMDC[1:0] bits in the RSCAN0CmCTR register are set to 01B (channel reset mode).

- The RTBO bit in the RSCAN0CmCTR register is set to 1 (forcible return from the bus off state is made).

- The BOM[1:0] bits in the RSCAN0CmCTR register are set to 01B (transition to channel halt mode at bus off entry).

- The CHMDC[1:0] bits in the RSCAN0CmCTR register are set to 10B (channel halt mode) before 11 consecutive recessive bits are detected 128 times with the BOM[1:0] bits set to 11B (transition to channel halt mode upon a request from the program during bus off).

## BOEF Flag

This flag is set to 1 when the bus off state is reached (TEC[7:0] value > 255). This flag is also set to 1 if the bus off state is reached when the BOM[1:0] bits in the RSCAN0CmCTR register (m = 0 or 1) set to 01B (transition to channel halt mode at bus off entry).

## EPF Flag

This flag becomes 1 when the error passive state is reached (REC[7:0] or TEC[7:0] value > 127).

This flag becomes 1 only when the REC[7:0] or TEC[7:0] value first exceeds 127. Therefore, if the program writes 0 to this flag while the value of REC[7:0] or TEC[7:0] remains over 127, this bit is not set to 1 until both REC [7:0] and TEC[7:0] values become 127 or less and then the REC[7:0] or TEC[7:0] value exceeds 127 again.

## EWF Flag

This flag is set to 1 only when the REC[7:0] or TEC[7:0] value first exceeds 95. Therefore, if the program writes 0 to this flag while the value of REC[7:0] or TEC[7:0] remains over 95, this bit is not set to 1 until both REC [7:0] and TEC[7:0] values become 95 or less and then the REC[7:0] or TEC[7:0] value exceeds 95 again.

## BEF Flag

This flag is set to 1 when any one of the ADERR, B0ERR, B1ERR, CERR, AERR, FERR, and SERR flags in the RSCAN0CmERFL register is set to 1.

## 21.3.5 RSCAN0GCFG — Global Configuration Register

||**Access:**|Can be|read/written in 8-, 16-, and|read/written in 8-, 16-, and|read/written in 8-, 16-, and|32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0084H|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||||||ITRCP|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||TSBTCS[2:0]|||TSSS||TSP[3:0]|||—|—|—|DCS|MME|DRE|DCE|TPRI|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R/W|R/W|R/W|R/W|R/W|

**Table 21.19 RSCAN0GCFG register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 16|ITRCP[15:0]|Interval Timer Prescaler Set|
|||When these bits are set to M, the pclk is divided by M.|
|||Setting 0000His prohibited when the interval timer is in use.|
|15 to 13|TSBTCS[2:0]|Timestamp Clock Source Select|
|||b15  b14  b13|
|||0    0    0: Channel 0 bit time clock|
|||0    0    1: Channel 1 bit time clock|
|||0    1    0: Setting prohibited|
|||0    1    1: Setting prohibited|
|||1    0    0: Setting prohibited|
|||1    0    1: Setting prohibited|
|||1    1    0: Setting prohibited|
|||1    1    1: Setting prohibited|
|12|TSSS|Timestamp Source Select|
|||0: pclk/2*1|
|||1: Bit time clock|
|11 to 8|TSP[3:0]|Timestamp Clock Source Division|
|||b11  b10   b9    b8|
|||0    0    0    0: Not divided|
|||0    0    0    1: Divided by 2|
|||0    0    1    0: Divided by 4|
|||0    0    1    1: Divided by 8|
|||0    1    0    0: Divided by 16|
|||0    1    0    1: Divided by 32|
|||0    1    1    0: Divided by 64|
|||0    1    1    1: Divided by 128|
|||1    0    0    0: Divided by 256|
|||1    0    0    1: Divided by 512|
|||1    0    1    0: Divided by 1024|
|||1    0    1    1: Divided by 2048|
|||1    1    0    0: Divided by 4096|
|||1    1    0    1: Divided by 8192|
|||1    1    1    0: Divided by 16384|
|||1    1    1    1: Divided by 32768|
|7 to 5|Reserved|These bits are always read as 0. The write value should always be 0.|
|4|DCS|CAN Clock Source Select*2|
|||0: clkc|
|||1: clk_xincan|

**Table 21.19 RSCAN0GCFG register contents (2/2)**

|**Bit**|**Position**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|---|
|3|||MME|Mirror Function Enable|
|||||0: Mirror function is disabled.|
|||||1: Mirror function is enabled.|
|2|||DRE|DLC Replacement Enable|
|||||0: DLC replacement is disabled.|
|||||1: DLC replacement is enabled.|
|1|||DCE|DLC Check Enable|
|||||0: DLC check is disabled.|
|||||1: DLC check is enabled.|
|0|||TPRI|Transmit Priority Select|
|||||0: ID priority|
|||||1: Transmit buffer number priority|
|Note|1.|When specifying CKSCLK_ICANOSC as the timestamp counter count source, set bits TSBTCS[2:0] to|||
|||000B.|||
|Note|2.|For the setting of||the CAN clock frequency, see Table 21.6, Range of Operating Frequency Depending on|
|||the Transfer Rate and the Number of Channels in Use in this LSI.|||

Modify the RSCAN0GCFG register only in global reset mode.

## ITRCP[15:0] Bits

These bits are used to set a clock source division value of the interval timer for FIFO buffers. Refer to Section 21.7.3.1, Interval Transmission Function

## TSBTCS[2:0] Bits

When the TSSS bit is 1, these bits are used to select the channel of the bit time clock that will be the clock source of the timestamp counter.

## TSSS Bit

This bit is used to select a clock source of the timestamp counter.

## TSP[3:0] Bits

A clock obtained by dividing the clock source selected with the TSBTCS[2:0] bits and TSSS bit according to the TSP[3:0] bits is used as the timestamp counter count source.

## DCS Bit

When this bit is set to 0, clkc is used as the clock source of the CAN clock (fCAN).

When this bit is set to 1, clk_xincan is used as the clock source of the CAN clock (fCAN).

For the setting of the CAN clock frequency, see Table 21.6, Range of Operating Frequency Depending on the Transfer Rate and the Number of Channels in Use in this LSI .

## MME Bit

Setting this bit to 1 makes the mirror function available.

## DRE Bit

When the DRE bit is set to 1, the DLC value of the receive rule is stored in the buffer instead of the DLC value of the received message after the DLC value has passed through the DLC filter. In this case, a value of 00H is stored in each data byte beyond the first n bytes, where n is the DLC value of the receive rule.

The DLC replacement function is only available when the DCE bit is set to 1 (DLC check is enabled).

## DCE Bit

Setting this bit to 1 makes the DLC check function available. When disabling the DLC check function, set the GAFLDLC[3:0] bits in the RSCAN0GAFLP0j register to 0000B before clearing the DCE bit in the RSCAN0GCFG register to 0.

## TPRI Bit

This bit is used to set the transmit priority.

When this bit is set to 0, ID priority is selected and the transmit priority complies with the CAN bus arbitration rule (ISO11898-1 specifications). When this bit is set to 1, transmit buffer number priority is selected and the lowest transmit buffer number of those with pending messages has the highest priority.

While the transmit queue is in use, this bit should be set to 0.

## 21.3.6 RSCAN0GCTR — Global Control Register

||**Access:**|**Access:**|Can|be read/written in 8-, 16-, and 32-bit units|be read/written in 8-, 16-, and 32-bit units|be read/written in 8-, 16-, and 32-bit units|be read/written in 8-, 16-, and 32-bit units|be read/written in 8-, 16-, and 32-bit units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**||<RSCAN0_base> + 0088H|||||||||||||||
|**Initial value:**|||0000 0005H|||||||||||||||
|Bit|31||30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—||—|—|—|—|—|—|—|—|—|—|—|—|—|—|TSRST|
|Initial value|0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|
|Bit|15||14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—||—|—|—|—|THLEIE|MEIE|DEIE|—|—|—|—|—|GSLPR|GMDC[1:0]||
|Initial value|0||0|0|0|0|0|0|0|0|0|0|0|0|1|0|1|
|R/W|R||R|R|R|R|R/W|R/W|R/W|R|R|R|R|R|R/W|R/W|R/W|

**Table 21.20 RSCAN0GCTR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 17|Reserved|These bits are always read as 0. The write value should always be 0.|
|16|TSRST|Timestamp Counter Reset|
|||Setting the TSRST bit to 1 resets the timestamp counter. This bit is always read|
|||as 0.|
|15 to 11|Reserved|These bits are always read as 0. The write value should always be 0.|
|10|THLEIE|Transmit History Buffer Overflow Interrupt Enable|
|||0: Transmit history buffer overflow interrupt is disabled.|
|||1: Transmit history buffer overflow interrupt is enabled.|
|9|MEIE|FIFO Message Lost Interrupt Enable|
|||0: FIFO message lost interrupt is disabled.|
|||1: FIFO message lost interrupt is enabled.|
|8|DEIE|DLC Error Interrupt Enable|
|||0: DLC error interrupt is disabled.|
|||1: DLC error interrupt is enabled.|
|7 to 3|Reserved|These bits are always read as 0. The write value should always be 0.|
|2|GSLPR|Global Stop Mode|
|||0: Other than global stop mode|
|||1: Global stop mode|
|1, 0|GMDC[1:0]|Global Mode Select|
|||b1   b0|
|||0    0: Global operating mode|
|||0    1: Global reset mode|
|||1    0: Global test mode|
|||1    1: Setting prohibited|

## TSRST Bit

This bit is used to reset the timestamp counter. When this bit is set to 1, the RSCAN0GTSC register is cleared to 0000H.

## THLEIE Bit

When the THLEIE bit is set to 1 and the THLES flag in the RSCAN0GERFL register is set to 1, an interrupt request is generated. Modify this bit only in global reset mode.

## MEIE Bit

When the MEIE bit is set to 1 and the MES flag in the RSCAN0GERFL register is set to 1, an interrupt request is generated. Modify this bit only in global reset mode.

## DEIE Bit

When the DEIE bit is set to 1 and the DEF flag in the RSCAN0GERFL register is set to 1, an interrupt request is generated. Modify this bit only in global reset mode.

## GSLPR Bit

When the RSCAN module is in global reset mode, setting this bit to 1 places the RSCAN module into global stop mode.

Clearing this bit to 0 makes the RSCAN module leave from global stop mode.

Modify this bit only in global reset mode.

## GMDC[1:0] Bits

These bits are used to select the mode of entire RS-CAN module (global operating mode, global reset mode, or global test mode). For details, see Section 21.5.1, Global Modes . Setting the GSLPR bit to 1 when in global reset mode places the RS-CAN module into global stop mode.

## 21.3.7 RSCAN0GSTS — Global Status Register

||**Access:**|**Access:**||Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**|||<RSCAN0_base> + 008CH|||||||||||||||
|**Initial value:**||||0000 000DH|||||||||||||||
|Bit|31||30||29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—||—||—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0||0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R||R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15||14||13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—||—||—|—|—|—|—|—|—|—|—|—|GRAMI|GSLPS|GHLTST|GRSTS|
||||||||||||||||NIT|TS|S|TS|
|Initial value|0||0||0|0|0|0|0|0|0|0|0|0|1|1|0|1|
|R/W|R||R||R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 21.21 RSCAN0GSTS register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 4|Reserved|These bits are always read as 0.|
|3||GRAMINIT|CAN RAM Initialization Status Flag|
||||0: CAN RAM initialization is completed.|
||||1: CAN RAM initialization is ongoing.|
|2||GSLPSTS|Global Stop Status Flag|
||||0: Not in global stop mode|
||||1: In global stop mode|
|1||GHLTSTS|Global Test Status Flag|
||||0: Not in global test mode|
||||1: In global test mode|
|0||GRSTSTS|Global Reset Status Flag|
||||0: Not in global reset mode|
||||1: In global reset mode|

## GRAMINIT Flag

This flag indicates the initialization status of the CAN RAM.

This flag is set to 1 after this LSI has been reset, and is cleared to 0 when CAN RAM initialization is completed.

## GSLPSTS Flag

This flag is set to 1 when the CAN module has transitioned to global stop mode, and is cleared to 0 when the CAN module has returned from global stop mode.

## GHLTSTS Flag

This flag is set to 1 when the CAN module has transitioned to global test mode, and is cleared to 0 when the CAN module has exited global test mode.

## GRSTSTS Flag

This flag is set to 1 when the CAN module has transitioned to global reset mode, and is cleared to 0 when the CAN module has exited global reset mode. This flag remains 1 even when the CAN module has transitioned from global reset mode to global stop mode.

## 21.3.8 RSCAN0GERFL — Global Error Flag Register

|**Access:**|**Access:**|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|32-bit units|32-bit units||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0090H||||||||||||||||
|**Initial**|**value:**|0000 0000H||||||||||||||||
|Bit|31|30<br>29|28||27||26|25|24|23|22|21|20|19|18|17|16|
||—|—<br>—|—||—||—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0<br>0|0||0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R||R||R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14<br>13|12||11||10|9|8|7|6|5|4|3|2|1|0|
||—|—<br>—|—||—||—|—|—|—|—|—|—|—|THLES|MES|DEF|
|Initial value|0|0<br>0|0||0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R||R||R|R|R|R|R|R|R|R|R|R|R/W*1|

Note 1. The only effective value for writing to this flag bit is 0, which clears the bit. Otherwise writing to the bit results in retention of its state.

**Table 21.22 RSCAN0GERFL register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 29|Reserved|The read value is undefined. The write value should always be 0.|
|2||THLES|Transmit History Buffer Overflow Status Flag|
||||0: No transmit history buffer overflow has occurred.|
||||1: A transmit history buffer overflow has occurred.|
|1||MES|FIFO Message Lost Status Flag|
||||0: No FIFO message lost error has occurred.|
||||1: A FIFO message lost error has occurred.|
|0||DEF|DLC Error Flag|
||||0: No DLC error has occurred.|
||||1: A DLC error has occurred.|

All flags in the RSCAN0GERFL register are cleared to 0 in global reset mode.

## THLES Flag

The THLES flag is set to 1 when any one of the THLELT flags in the RSCAN0THLSTSm register (m = 0 or 1) is set to 1.

This flag is cleared to 0 when the THLELT flags of all channels are set to 0.

## MES Flag

The MES flag is set to 1 when any one of the RFMLT flags in the RSCAN0RFSTSx register (x = 0 to 7) or the CFMLT flags in the RSCAN0CFSTSk register (k = 0 to 5) is set to 1.

This flag is cleared to 0 when all RFMLT flags and CFMLT flags are set to 0.

## DEF Flag

The DEF flag is set to 1 when an error has been detected during the DLC check. The program can clear this flag by writing 0 to this bit.

## 21.3.9 RSCAN0GTINTSTS0 — Global TX Interrupt Status Register 0

|**Access:**|**Access:**|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|32-bit units|32-bit units|32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0460H||||||||||||||||
|**Initial value:**||0000 0000H||||||||||||||||
|Bit|31|30|29|28||27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—|—||—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R||R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12||11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|THIF1||CFTIF1|TQIF1|TAIF1|TSIF1|—|—|—|THIF0|CFTIF0|TQIF0|TAIF0|TSIF0|
|Initial value|0|0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R*1||R*1|R*1|R*1|R*1|R|R|R|R*1|R*1|R*1|R*1|R*1|

Note 1. This bit is automatically cleared in the global reset or channel reset mode.

## **Table 21.23 RSCAN0GTINTSTS0 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 13|Reserved|These bits are always read as 0. The write value should always be 0.|
|12|THIF1|Channel 1 transmit history interrupt status flag|
|||0: Transmit history interrupt is not requested.|
|||1: Transmit history interrupt is requested.|
|11|CFTIF1|Channel 1 transmit/receive FIFO transmit/gateway mode interrupt status flag|
|||0: Transmit/receive FIFO transmit/gateway mode interrupt is not requested.|
|||1: Transmit/receive FIFO transmit/gateway mode interrupt is requested.|
|10|TQIF1|Channel 1 transmit queue interrupt status flag|
|||0: Transmit queue interrupt is not requested.|
|||1: Transmit queue interrupt is requested.|
|9|TAIF1|Channel 1 transmit buffer abort interrupt status flag|
|||0: Transmit buffer transmit abort interrupt is not requested.|
|||1: Transmit buffer transmit abort interrupt is requested.|
|8|TSIF1|Channel 1 transmit buffer interrupt status flag|
|||0: Transmit buffer transmit complete interrupt is not requested.|
|||1: Transmit buffer transmit complete interrupt is requested.|
|7 to 5|Reserved|These bits are always read as 0. The write value should always be 0.|
|4|THIF0|Channel 0 transmit history interrupt status flag|
|||0: Transmit history interrupt is not requested.|
|||1: Transmit history interrupt is requested.|
|3|CFTIF0|Channel 0 transmit/receive FIFO transmit/gateway mode interrupt status flag|
|||0: Transmit/receive FIFO transmit/gateway mode interrupt is not requested.|
|||1: Transmit/receive FIFO transmit/gateway mode interrupt is requested.|
|2|TQIF0|Channel 0 transmit queue interrupt status flag|
|||0: Transmit queue interrupt is not requested.|
|||1: Transmit queue interrupt is requested.|
|1|TAIF0|Channel 0 transmit buffer abort interrupt status flag|
|||0: Transmit buffer transmit abort interrupt is not requested.|
|||1: Transmit buffer transmit abort interrupt is requested.|
|0|TSIF0|Channel 0 transmit buffer interrupt status flag|
|||0: Transmit buffer transmit complete interrupt is not requested.|
|||1: Transmit buffer transmit complete interrupt is requested.|

## TSIFm Bits

The TSIFm bit is set to 1 when the TMIE bit in the RSCAN0TMIECy register is set to 1 (transmit buffer interrupt enabled) and the TMTRF[1:0] flags in the RSCAN0TMSTSp register are set to 10B (transmit completed without abort request) or 11B (transmit completed with abort request).

When the TMTRF[1:0] flags are cleared to 00B under the condition that the TSIFm bit can be set to 1, this flag is cleared to 0. In addition, clearing the TMIE bit to 0 also clears this flag to 0.

## TAIFm Bits

The TAIFm bit is set to 1 when the TAIE bit in the RSCAN0CmCTR register is 1 (transmit abort interrupt enabled) and the TMTRF[1:0] flags in the RSCAN0TMSTSp register are set to 01B (transmit abort completed).

This flag is cleared to 0 when the TMTRF[1:0] flags are cleared to 00B after the transmit abort is completed.

## TQIFm Bits

When the TXQIE bit in the RSCAN0TXQCCm register is set to 1 (transmit queue interrupt enabled) and the TXQIF bit in the RSCAN0TXQSTSm register is set to 1 (transmit queue interrupt request), the TQIFm bit is set to 1.

When the TXQIF bit (transmit queue interrupt request) in the RSCAN0TXQSTSm register is cleared to 0, this bit is cleared to 0. This flag is also cleared to 0 when the TXQIE bit is cleared to 0.

## CFTIFm Bits

When the CFTXIE bit in the RSCAN0CFCCk register is set to 1 (transmit/receive FIFO buffer transmit interrupt enabled) and the CFTXIF bit in the RSCAN0CFSTSk register is set to 1 (transmit/ receive FIFO transmit interrupt request), the CFTIFm bit is set to 1.

When the CFTXIF bit is cleared to 0 under the condition that the CFTIFm bit can be set to 1, this bit is cleared to 0. This flag is also cleared to 0 when the CFTXIE bit is cleared to 0.

## THIFm Bits

When the THLIE bit in the RSCAN0THLCCm register is set to 1 (transmit history interrupt enabled) and the THLIF bit in the RSCAN0THLSTSm register is set to 1 (transmit history interrupt request), the THIFm bit is set to 1.

When the THLIF bit in the RSCAN0THLSTSm register is cleared to 0, this bit is cleared to 0. This flag is also cleared to 0 when the THLIE bit is cleared to 0.

## 21.3.10 RSCAN0GTSC — Global Timestamp Counter Register

**==> picture [481 x 189] intentionally omitted <==**

**----- Start of picture text -----**<br>
Access: Can be read in 8-, 16- and 32-bit units<br>Address: <RSCAN0_base> + 0094H<br>Initial value: 0000 0000H<br>Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>— — — — — — — — — — — — — — — —<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>Bit 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>TS[15:0]<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>**----- End of picture text -----**<br>

## **Table 21.24 RSCAN0GTSC register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|Reserved|These bits are always read as 0.|
|15|to 0|TS[15:0]|Timestamp Value|
||||The timestamp counter value can be read.|
||||Counter Value: 0000Hto FFFFH|

## TS[15:0] Bits

When the TS[15:0] bits are read, the read value shows the timestamp counter (16-bit free-running counter) value at that time. When the SOF is detected, the TS[15:0] value is captured and later stored in the receive buffer or the FIFO buffer. The timestamp counter is initialized in global reset mode.

The timestamp counter starts and stops counting differently, depending on the count source.

- When the TSSS bit in the RSCAN0GCFG register is 0 (pclk): The timestamp counter starts counting when the RSCAN module has transitioned to global operating mode.

   - This counter stops counting when the RSCAN module has transitioned to global stop mode or global test mode.

- When the TSSS bit is 1 (CANm bit time clock): The timestamp counter starts counting when the corresponding channel has transitioned to channel communication mode.

   - This counter stops counting when the corresponding channel has transitioned to channel reset mode or channel halt mode.

## 21.3.11 RSCAN0GAFLECTR — Receive Rule Entry Control Register

|**Access:**|**Access:**|Can be|read/written in 8-, 16-, and|read/written in 8-, 16-, and|read/written in 8-, 16-, and|32-bit units|32-bit units|32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0098H|||||||||||||||||
|**Initial**|**value:**|0000 0000H|||||||||||||||||
|Bit|31|30|29|28|27||26|25|24|23|22|21|20|19||18|17|16|
||—|—|—|—|—||—|—|—|—|—|—|—|—||—|—|—|
|Initial value|0|0|0|0|0||0|0|0|0|0|0|0|0||0|0|0|
|R/W|R|R|R|R|R||R|R|R|R|R|R|R|R||R|R|R|
|Bit|15|14|13|12|11||10|9|8|7|6|5|4|3||2|1|0|
||—|—|—|—|—||—|—|AFLDAE|—|—|—|||AFLPN[4:0]||||
|Initial value|0|0|0|0|0||0|0|0|0|0|0|0|0||0|0|0|
|R/W|R|R|R|R|R||R|R|R/W|R|R|R|R/W|R/W||R/W|R/W|R/W|

## **Table 21.25 RSCAN0GAFLECTR register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 9|Reserved|These bits are always read as 0. The write value should always be 0.|
|8|AFLDAE|Receive Rule Table Write Enable|
|||0: Receive rule table write is disabled.|
|||1: Receive rule table write is enabled.|
|7 to 5|Reserved|These bits are always read as 0. The write value should always be 0.|
|4 to 0|AFLPN[4:0]|Receive Rule Table Page Number Configuration|
|||A page number can be selected from a range of page 0 (00000B) to page 7|
|||(00111B).|

## AFLDAE Bit

Setting this bit to 0 disables the write to the receive rule table. After writes to the receive rule table are completed, set this bit to 0 to disable the write to the table. The receive rule table can be read regardless of the value of this bit.

Set the AFLDAE bit to 1 only in global reset mode.

## AFLPN[4:0] Bits

These bits are used to set the page number of the receive rule table. Sixteen receive rules can be set per page.

Set these bits to a value within the range of 00000B to 00111B.

## 21.3.12 RSCAN0GAFLCFG0 — Receive Rule Configuration Register 0

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 009CH|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||RNC0[7:0]||||||||RNC1[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 21.26 RSCAN0GAFLCFG0 register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 24|RNC0[7:0]|Number of Rules for Channel 0|
||||Set the number of receive rules exclusively used for channel 0.|
|23|to 16|RNC1[7:0]|Number of Rules for Channel 1|
||||Set the number of receive rules exclusively used for channel 1.|
|15|to 0|Reserved|These bits are always read as 0. The write value should always be 0.|

Modify the RSCAN0GAFLCFG0 register only in global reset mode.

Up to 64 x (number of channels) rules can be registered in the receive rule table as the entire unit. The number of receive rules per channel should meet the following conditions.

- The maximum number of rules per channel is 128.

- The total of the number of rules allocated to each channel is not larger than the number of rules that can be registered in the entire unit.

## RNC0[7:0] Bits

These bits are used to set the number of rules to be registered in the channel 0 receive rule table.

Set these bits to a value within the range of 00H to 80H.

## RNC1[7:0] Bits

These bits are used to set the number of rules to be registered in the channel 1 receive rule table.

Set these bits to a value within the range of 00H to 80H.

## 21.3.13 RSCAN0GAFLIDj — Receive Rule ID Register (j = 0 to 15)

|**Access:**|**Access:**|Can be|read/written in 8-, 16-, and 32-bit|read/written in 8-, 16-, and 32-bit|read/written in 8-, 16-, and 32-bit|read/written in 8-, 16-, and 32-bit|read/written in 8-, 16-, and 32-bit|units|||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0500H+ (j * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29||28|27|26|25<br>24|23|22|21|20|19|18|17|16|
||GAFLID<br>E|GAFLR<br>TR<br>GAFLLB|||||||GAFLID[28:16]||||||||
|Initial value|0|0|0||0|0|0|0<br>0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13||12|11|10|9<br>8|7|6|5|4|3|2|1|0|
|||||||||GAFLID[15:0]|||||||||
|Initial value|0|0|0||0|0|0|0<br>0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||**Table 21.27**|||**RSCAN0GAFLIDj register contents**||||||||||||
|||**Bit Position**|||**Bit Name**|||**Function**|||||||||
|||b31|||GAFLIDE|||IDE Select|||||||||
|||||||||0: Standard ID|||||||||
|||||||||1: Extended ID|||||||||
|||b30|||GAFLRTR|||RTR Select|||||||||
|||||||||0: Data frame|||||||||
|||||||||1: Remote frame|||||||||
|||b29|||GAFLLB|||Receive Rule Target Message Select|||||||||
|||||||||0: When a message transmitted from another|||||CAN node is received||||
|||||||||1: When the own|transmitted message|||is received|||||
|||b28|to b0||GAFLID[28:0]|||ID|||||||||
|||||||||Set the ID of the receive||rule.|||||||
|||||||||For the standard ID, set||the ID in bits b10 to b0|||and set bits b28 to b11 to 0.||||

Modify the RSCAN0GAFLIDj register when the AFLDAE bit in the RSCAN0GAFLECTR register is set to 1 (receive rule table write is enabled) in global reset mode.

## GAFLIDE Bit

This bit is used to select the ID format (standard ID or extended ID) of the receive rule. This bit is compared with the IDE bit in the received message during the acceptance filter processing.

## GAFLRTR Bit

This bit is used to select the frame format (data frame or remote frame) of the receive rule. This bit is compared with the RTR bit in the received message during the acceptance filter processing.

## GAFLLB Bit

When this bit is set to 0, data processing using the receive rule is performed when receiving messages transmitted from another CAN node.

When this bit is set to 1 when the mirror function is used, data processing using the receive rule is performed when the CAN node is receiving its own transmitted messages.

## GAFLID[28:0] Bits

These bits are used to set the ID field of the receive rule. The ID value set by these bits is compared with the ID of the received message during the acceptance filter processing.

## 21.3.14 RSCAN0GAFLMj — Receive Rule Mask Register (j = 0 to 15)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0504H+ (j * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||GAFLID<br>EM|GAFLR<br>TRM|—||||||GAFLIDM[28:16]||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||GAFLIDM[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 21.28 RSCAN0GAFLMj register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31||GAFLIDEM|IDE Mask|
||||0: The IDE bit is not compared.|
||||1: The IDE bit is compared.|
|30||GAFLRTRM|RTR Mask|
||||0: The RTR bit is not compared.|
||||1: The RTR bit is compared|
|29||Reserved|This bit is always read as 0. The write value should always be 0.|
|28|to 0|GAFLIDM[28:0]|ID Mask|
||||0: The corresponding ID bit is not compared.|
||||1: The corresponding ID bit is compared.|

Modify the RSCAN0GAFLMj register when the AFLDAE bit in the RSCAN0GAFLECTR register is set to 1 (receive rule table write is enabled) in global reset mode.

## GAFLIDEM Bit

When this bit is set to 1, filter processing is performed only for messages of the ID format specified by the GAFLIDE bit in the RSCAN0GAFLIDj register.

When this bit is cleared to 0, the IDs of all the receive messages and the specified IDs are regarded as matched. To set the GAFLIDEM bit to 0, set the GAFLIDM[28:0] bits to all 0 at the same time.

## GAFLRTRM Bit

This bit is used to mask the RTR bit of the receive rule.

## GAFLIDM[28:0] Bits

These bits are used to mask the corresponding ID bit of the receive rule.

## 21.3.15 RSCAN0GAFLP0j — Receive Rule Pointer 0 Register (j = 0 to 15)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0508H+ (j * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||GAFLDLC[3:0]||||||||GAFLPTR[11:0]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||GAFLR<br>MV|||GAFLRMDP[6:0]|||||—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R|R|R|R|R|R|R|R|

**Table 21.29 RSCAN0GAFLP0j register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 28|GAFLDLC[3:0]|Receive Rule DLC|
|||b31  b30  b29  b28|
|||0    0    0    0: DLC check is disabled.|
|||0    0    0    1: 1 data byte|
|||0    0    1    0: 2 data bytes|
|||0    0    1    1: 3 data bytes|
|||0    1    0    0: 4 data bytes|
|||0    1    0    1: 5 data bytes|
|||0    1    1    0: 6 data bytes|
|||0    1    1    1: 7 data bytes|
|||1    X    X    X: 8 data bytes|
|27 to 16|GAFLPTR[11:0]|Receive Rule Label|
|||Set the 12-bit label information.|
|15|GAFLRMV|Receive Buffer Enable|
|||0: No receive buffer is used.|
|||1: A receive buffer is used.|
|14 to 8|GAFLRMDP[6:0]|Receive Buffer Number Select|
|||Set the receive buffer number to store receive messages.|
|7 to 0|Reserved|These bits are always read as 0. The write value should always be 0.|

Modify the RSCAN0GAFLP0j register when the AFLDAE bit in the RSCAN0GAFLECTR register is set to 1 (receive rule table write is enabled) in global reset mode.

## GAFLDLC[3:0] Bits

These bits are used to set the minimum data length necessary for receiving messages. If the data length of a message that is being filtered is equal to or larger than the value set by the GAFLDLC[3:0] bits, the message passes the DLC check. Setting these bits to 0000B disables the DLC check function allowing messages with any data length to pass the DLC check.

## GAFLPTR[11:0] Bits

These bits are used to set a 12-bit label to be attached to messages that have passed through the filter. A label is attached when a message is stored in the receive buffer or the FIFO buffer.

## GAFLRMV Bit

When this bit is set to 1, receive messages that have passed through the filter are stored in the receive buffer selected by the GAFLRMDP[6:0] bits.

## GAFLRMDP[6:0] Bits

These bits are used to select the number of the receive buffer that stores receive messages that have passed through the filter when the GAFLRMV bit is set to 1. Set these bits to a value smaller than the value set by the NRXMB[7:0] bits in the RSCAN0RMNB register.

## 21.3.16 RSCAN0GAFLP1j — Receive Rule Pointer 1 Register (j = 0 to 15)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|32-bit units|32-bit units|32-bit units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 050CH+ (j * 0010H)|||||||||||||||
|**Initial**|**value:**|0000 0000H|||||||||||||||
|Bit|31|30<br>29|28|27||26|25|24|23|22|21|20|19|18|17|16|
||—|—<br>—|—|—||—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0<br>0|0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R|R||R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14<br>13|12|11||10|9|8|7|6|5|4|3|2|1|0|
||—|—|||||||GAFLFDP [13:0]||||||||
|Initial value|0|0<br>0|0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 21.30 RSCAN0GAFLP1j register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 14|Reserved|These bits are always read as 0. The write value should always be 0.|
|13|to 0|GAFLFDP [13:0]|FIFO Buffer z Select (z = 0 to 13)|
||||z = 0 to 7|
||||0: Receive FIFO buffer z is not selected.|
||||1: Receiver FIFO buffer z is selected.|
||||z = 8 to 13|
||||0: Transmit/receive FIFO buffer z-8 is not selected.|
||||1: Transmit/receive FIFO buffer z-8 is selected.|

Modify the RSCAN0GAFLP1j register when the AFLDAE bit in the RSCAN0GAFLECTR register is set to 1 (receive rule table write is enabled) in global reset mode.

## GAFLFDP [13:0] Bits

These bits are used to specify FIFO buffers that store receive messages that have passed through the filter. Up to eight FIFO buffers are selectable. However, when the GAFLRMV bit in the RSCAN0GAFLP0j register is set to 1 (a message is stored in the receive buffer), up to seven FIFO buffers can be selected.

Only receive FIFO buffers and the transmit/receive FIFO buffer for which the CFM[1:0] bits in the RSCAN0CFCCk register are set to 00B (receive mode) or 10B (gateway mode) are selectable.

## 21.3.17 RSCAN0RMNB — Receive Buffer Number Register

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|32-bit units|32-bit units|32-bit units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 00A4H|||||||||||||||
|**Initial**|**value:**|0000 0000H|||||||||||||||
|Bit|31|30<br>29|28|27||26|25|24|23|22|21|20|19|18|17|16|
||—|—<br>—|—|—||—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0<br>0|0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R|R||R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14<br>13|12|11||10|9|8|7|6|5|4|3|2|1|0|
||—|—<br>—|—|—||—|—|—||||NRXMB[7:0]|||||
|Initial value|0|0<br>0|0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R|R||R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 21.31 RSCAN0RMNB register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|Reserved|These bits are always read as 0. The write value should always be 0.|
|7 to 0|NRXMB[7:0]|Receive Buffer Number Configuration|
|||Set the number of receive buffers.|
|||Set a value of 0 to 31.|

Modify the RSCAN0RMNB register only in global reset mode.

## NRXMB[7:0] Bits

These bits are used to set the total number of receive buffers of the RS-CAN module. The maximum value is 16  (number of channels).

Setting these bits all to 0 makes receive buffers unavailable.

## 21.3.18 RSCAN0RMNDy — Receive Buffer New Data Register y (y = 0)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 00A8H+ (y * 0004H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||||RMNSq (q = y32 + 31 to y32 + 16 (y = 0))|||||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||RMNSq (q = y32 + 15 to y32 + 0 (y|||||= 0))||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 21.32 RSCAN0RMNDy register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|RMNSq|Receive Buffer Receive Complete Flag q (q = y32 + 31 to y32 + 16)|
||||0: There is no new message in receive buffer q.|
||||1: There is a new message in receive buffer q.|
|15|to 0|RMNSq|Receive Buffer Receive Complete Flag q (q = y32 + 15 to y32 + 0)|
||||0: There is no new message in receive buffer q.|
||||1: There is a new message in receive buffer q.|

Write 0 to the RSCAN0RMNDy register in global operating mode or global test mode.

## RMNSq Flags (q = 0 to 31)

Each RMNS flag is set to 1 when the processing for storing a message in the corresponding receive buffer starts.

To clear a flag to 0, the program must write 0 to the flag. Use a store instruction to write “0” to the flag and “1” to other flags. These bits cannot be set to 0 while a message is being stored. It takes ten clock cycles of pclk to store a message.

These flags are cleared to 0 in global reset mode.

## 21.3.19 RSCAN0RMIDq — Receive Buffer ID Register (q = 0 to 31)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0600H+ (q * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||RMIDE|RMRTR|—|||||||RMID[28:16]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||RMID[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.33 RSCAN0RMIDq register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31||RMIDE|Receive Buffer IDE|
||||0: Standard ID|
||||1: Extended ID|
|30||RMRTR|Receive Buffer RTR|
||||0: Data frame|
||||1: Remote frame|
|29||Reserved|This bit is always read as 0.|
|28|to 0|RMID[28:0]|Receive Buffer ID Data|
||||These bits contain the standard ID or extended ID of the received message.|
||||Read bits b10 to b0 for standard ID. Bits b28 to b11 are read as 0.|

## RMIDE Bit

This bit indicates the ID format (standard ID or extended ID) of the message stored in the receive buffer.

## RMRTR Bit

This bit indicates the frame format (data frame or remote frame) of the message stored in the receive buffer.

## RMID[28:0] Bits

These bits contain the ID of the message stored in the receive buffer.

## 21.3.20 RSCAN0RMPTRq — Receive Buffer Pointer Register (q = 0 to 31)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0604H+ (q * 0010H)|||||||||||||||
|**Initial**|**value:**|0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||RMDLC[3:0]||||||||RMPTR[11:0]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||RMTS[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.34 RSCAN0RMPTRq**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 28|RMDLC[3:0]|Receive Buffer DLC Data|
||||b31  b30  b29  b28|
||||0    0    0    0: 0 data bytes|
||||0    0    0    1: 1 data byte|
||||0    0    1    0: 2 data bytes|
||||0    0    1    1: 3 data bytes|
||||0    1    0    0: 4 data bytes|
||||0    1    0    1: 5 data bytes|
||||0    1    1    0: 6 data bytes|
||||0    1    1    1: 7 data bytes|
||||1    X    X    X: 8 data bytes|
|27|to 16|RMPTR[11:0]|Receive Buffer Label Data|
||||Label information of the received message.|
|15|to 0|RMTS[15:0]|Receive Buffer Timestamp Data|
||||Timestamp value of the received message.|

## RMDLC[3:0] Bits

These bits indicate the data length of the message stored in the receive buffer.

## RMPTR[11:0] Bits

These bits indicate the label information of the message stored in the receive buffer.

## RMTS[15:0] Bits

These bits indicate the timestamp value of the message stored in the receive buffer.

## 21.3.21 RSCAN0RMDF0q — Receive Buffer Data Field 0 Register (q = 0 to 31)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0608H+ (q * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||RMDB3[7:0]||||||||RMDB2[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||RMDB1[7:0]||||||||RMDB0[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.35 RSCAN0RMDF0q register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 24|RMDB3[7:0]|Receive Buffer Data Byte 3|
|23 to 16|RMDB2[7:0]|Receive Buffer Data Byte 2<br>Receive Buffer Data Byte 1|
|15 to 8|RMDB1[7:0]|Receive Buffer Data Byte 0|
|7 to 0|RMDB0[7:0]|Data for a message stored in the receive buffer can be read.|

When the RMDLC[3:0] value in the RSCAN0RMPTRq register is smaller than 1000B, data bytes for which no data is set are read as 00H.

## 21.3.22 RSCAN0RMDF1q — Receive Buffer Data Field 1 Register (q = 0 to 31)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 060CH+ (q * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||RMDB7[7:0]||||||||RMDB6[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||RMDB5[7:0]||||||||RMDB4[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.36 RSCAN0RMDF1q register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 24|RMDB7[7:0]|Receive Buffer Data Byte 7|
|23 to 16|RMDB6[7:0]|Receive Buffer Data Byte 6<br>Receive Buffer Data Byte 5|
|15 to 8|RMDB5[7:0]|Receive Buffer Data Byte 4|
|7 to 0|RMDB4[7:0]|Data for a message stored in the receive buffer can be read.|

When the RMDLC[3:0] value in the RSCAN0RMPTRq register is smaller than 1000B, data bytes for which no data is set are read as 00H.

## 21.3.23 RSCAN0RFCCx — Receive FIFO Buffer Configuration and Control Register (x = 0 to 7)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 00B8H+ (x * 0004H)||||||||||||||||
|**Initial value:**||0000 0000H||||||||||||||||
|Bit|31|30|29|28|27|26|25||24|23|22|21|20|19|18|17|16|
||—|—|—|—|—|—|—||—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0||0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R||R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9||8|7|6|5|4|3|2|1|0|
||RFIGCV[2:0]|||RFIM|—|RFDC[2:0]||||—|—|—|—|—|—|RFIE|RFE|
|Initial value|0|0|0|0|0|0|0||0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R|R/W|R/W||R/W|R|R|R|R|R|R|R/W|R/W|

**Table 21.37 RSCAN0RFCCx register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 16|Reserved|These bits are always read as 0. The write value should always be 0.|
|15 to 13|RFIGCV[2:0]|Receive FIFO Interrupt Request Timing Select|
|||b15  b14  b13|
|||0    0    0: When FIFO is 1/8 full.|
|||0    0    1: When FIFO is 2/8 full.|
|||0    1    0: When FIFO is 3/8 full.|
|||0    1    1: When FIFO is 4/8 full.|
|||1    0    0: When FIFO is 5/8 full.|
|||1    0    1: When FIFO is 6/8 full.|
|||1    1    0: When FIFO is 7/8 full.|
|||1    1    1: When FIFO is full.|
|12|RFIM|Receive FIFO Interrupt Source Select|
|||0: An interrupt occurs when the condition set by the RFIGCV[2:0] bits is met.|
|||1: An interrupt occurs each time a message has been received.|
|11|Reserved|This bit is always read as 0. The write value should always be 0.|
|10 to 8|RFDC[2:0]|Receive FIFO Buffer Depth Configuration|
|||b10   b9   b8|
|||0    0    0: 0 messages|
|||0    0    1: 4 messages|
|||0    1    0: 8 messages|
|||0    1    1: 16 messages|
|||1    0    0: 32 messages|
|||1    0    1: 48 messages|
|||1    1    0: 64 messages|
|||1    1    1: 128 messages|
|7 to 2|Reserved|These bits are always read as 0. The write value should always be 0.|
|1|RFIE|Receive FIFO Interrupt Enable|
|||0: Receive FIFO interrupt is disabled.|
|||1: Receive FIFO interrupt is enabled.|
|0|RFE|Receive FIFO Buffer Enable|
|||0: No receive FIFO buffer is used.|
|||1: Receive FIFO buffers are used.|

## RFIGCV[2:0] Bits

These bits are used to specify the number of received messages for generating a receive FIFO interrupt request when the RFIM bit is set to 0 with a fraction for the total number of buffers (the setting of RFDC[2:0]).

When the RFDC[2:0] bits are set to 001B (4 messages), set the RFIGCV[2:0] bits to 001B, 011B, 101B, or 111B (fractions which are even multiples of 1/4). Modify these bits only in global reset mode.

## RFIM Bit

This bit is used to select a FIFO interrupt source. Modify this bit only in global reset mode.

## RFDC[2:0] Bits

These bits are used to select the number of messages that can be stored in a single receive FIFO buffer. When these bits are set to 000B, no receive FIFO buffer should be used. Modify these bits only in global reset mode.

## RFIE Bit

Setting the RFIE bit to 1 enables receive FIFO interrupts. Modify this bit when the RFE bit set to 0 (no receive FIFO buffer is used).

## RFE Bit

Setting the RFE bit to 1 makes receive FIFO buffers available. Clearing this bit to 0 sets the RFEMP flag in the RSCAN0RFSTSx register to 1 (the receive FIFO buffer contains no unread message (buffer empty)). Modify this bit in global operating mode or global test mode.

## 21.3.24 RSCAN0RFSTSx — Receive FIFO Buffer Status Register (x = 0 to 7)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 00D8H+ (x * 0004H)||||||||||||||
|**Initial**|**value:**|0000 0001H||||||||||||||
|Bit|31|30<br>29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—|—<br>—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0<br>0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14<br>13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||RFMC[7:0]|||||—|—|—|—|RFIF|RFMLT|RFFLL|RFEMP|
|Initial value|0|0<br>0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W|R|R<br>R|R|R|R|R|R|R|R|R|R|R/W*1|R/W*1|R|R|

Note 1. The only effective value for writing to this flag bit is 0, which clears the bit. Otherwise writing to the bit results in retention of its state.

**Table 21.38 RSCAN0RFSTSx register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 16|Reserved|These bits are always read as 0. The write value should always be 0.|
|15 to 8|RFMC[7:0]|Receive FIFO Unread Message Counter|
|||The number of unread messages stored in the receive FIFO buffer is displayed.|
|7 to 4|Reserved|These bits are always read as 0. The write value should always be 0.|
|3|RFIF|Receive FIFO Interrupt Request Flag|
|||0: No receive FIFO interrupt request is present.|
|||1: A receive FIFO interrupt request is present.|
|2|RFMLT|Receive FIFO Message Lost Flag|
|||0: No receive FIFO message is lost.|
|||1: A receive FIFO message is lost.|
|1|RFFLL|Receive FIFO Buffer Full Status Flag|
|||0: The receive FIFO buffer is not full.|
|||1: The receive FIFO buffer is full.|
|0|RFEMP|Receive FIFO Buffer Empty Status Flag|
|||0: The receive FIFO buffer contains unread message.|
|||1: The receive FIFO buffer contains no unread message (buffer empty).|

## RFMC[7:0] Flag

This flag indicates the number of unread messages in the receive FIFO buffer. This flag becomes 00H when the RFE bit in the RSCAN0RFCCx register is set to 0.

## RFIF Flag

This flag is set to 1 when the receive FIFO interrupt request generation conditions set by the RFIGCV[2:0] bits and the RFIM bit in the RSCAN0RFCCx register are met. This flag is cleared to 0 in global reset mode or by writing 0 to this flag. Modify this bit in global operating mode or global test mode.

## RFMLT Flag

This flag is set to 1 when an attempt is made to store a new message while the receive FIFO buffer is full. In this case, the new message is discarded.

This flag is cleared to 0 in global reset mode or by writing 0 to this flag.

Modify this bit in global operating mode or global test mode.

## RFFLL Flag

This flag is set to 1 when the number of messages stored in the receive FIFO buffer matches the FIFO buffer depth set by the RFDC[2:0] bits in the RSCAN0RFCCx register.

If the number of messages stored in the receive FIFO buffer becomes smaller than the FIFO buffer depth set by the RFDC[2:0] bits, this flag is cleared to 0. This flag is also cleared to 0 when the RFE bit in the RSCAN0RFCCx register is set to 0 (no receive FIFO buffer is used) or in global reset mode.

## RFEMP Flag

This flag is set to 1 when all messages in the receive FIFO buffer have been read. This flag is also set to 1 when the RFE bit in the RSCAN0RFCCx register is 0 or in global reset mode.

This flag is cleared to 0 when even a single received message has been stored in the receive FIFO buffer.

## 21.3.25 RSCAN0RFPCTRx — Receive FIFO Buffer Pointer Control Register (x = 0 to 7)

**==> picture [481 x 189] intentionally omitted <==**

**----- Start of picture text -----**<br>
Access: Can be written in 8-, 16-, and 32-bit units<br>Address: <RSCAN0_base> + 00F8H + (x * 0004H)<br>Initial value: 0000 0000H<br>Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>— — — — — — — — — — — — — — — —<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>Bit 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>— — — — — — — — RFPC[7:0]<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R W W W W W W W W<br>**----- End of picture text -----**<br>

## **Table 21.39 RSCAN0RFPCTRx register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|Reserved|The write value should always be 0.|
|7 to 0|RFPC[7:0]|Receive FIFO Pointer Control|
|||When these bits are set to FFH, the read pointer moves to the next unread|
|||message in the receive FIFO buffer.|

## RFPC[7:0] Bits

When the RFPC[7:0] bits are set to FFH, the read pointer moves to the next unread message in the receive FIFO buffer. At this time, the RFMC[7:0] (receive FIFO unread message counter) value in the RSCAN0RFSTSx register is decremented. Read the RSCAN0RFID, RSCAN0RFPTR,

RSCAN0RFDF0, and RSCAN0RFDF1 registers to read messages in the receive FIFO buffer, and then write FFH to the RFPC[7:0] bits.

Write FFH to these bits when the RFE bit in the RSCAN0RFCCx register is set to 1 (receive FIFO buffers are used) and the RFEMP flag in the RSCAN0RFSTSx register is 0 (the receive FIFO buffer contains unread messages).

## 21.3.26 RSCAN0RFIDx — Receive FIFO Buffer Access ID Register (x = 0 to 7)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0E00H+ (x * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||RFIDE|RFRTR|—|||||||RFID[28:16]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||RFID[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.40 RSCAN0RFIDx register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31||RFIDE|Receive FIFO Buffer IDE|
||||0: Standard ID|
||||1: Extended ID|
|30||RFRTR|Receive FIFO Buffer RTR|
||||0: Data frame|
||||1: Remote frame|
|29||Reserved|This bit is always read as 0.|
|28|to 0|RFID[28:0]|Receive FIFO Buffer ID Data|
||||The standard ID or extended ID of received message can be read.|
||||Read bits b10 to b0 for standard ID. Bits b28 to b11 are read as 0.|

## RFIDE Bit

This bit indicates the ID format (standard ID or extended ID) of the message stored in the receive FIFO buffer.

## RFRTR Bit

This bit indicates the frame format (data frame or remote frame) of the message stored in the receive FIFO buffer.

## RFID[28:0] Bits

These bits indicate the ID of the message stored in the receive FIFO buffer.

## 21.3.27 RSCAN0RFPTRx — Receive FIFO Buffer Access Pointer Register (x = 0 to 7)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0E04H+ (x * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||RFDLC[3:0]||||||||RFPTR[11:0]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||RFTS[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.41 RSCAN0RFPTRx register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 28|RFDLC[3:0]|Receive FIFO Buffer DLC Data|
||||b31  b30  b29  b28|
||||0    0    0    0: 0 data bytes|
||||0    0    0    1: 1 data byte|
||||0    0    1    0: 2 data bytes|
||||0    0    1    1: 3 data bytes|
||||0    1    0    0: 4 data bytes|
||||0    1    0    1: 5 data bytes|
||||0    1    1    0: 6 data bytes|
||||0    1    1    1: 7 data bytes|
||||1    X    X    X: 8 data bytes|
|27|to 16|RFPTR[11:0]|Receive FIFO Buffer Label Data|
||||Label information of the received message can be read.|
|15|to 0|RFTS[15:0]|Receive FIFO Buffer Timestamp Data|
||||Timestamp value of the received message can be read.|

## RFDLC[3:0] Bits

These bits contain the data length of the message stored in the receive FIFO buffer.

## RFPTR[11:0] Bits

These bits contain the label information of the message stored in the receive FIFO buffer.

## RFTS[15:0] Bits

These bits contain the timestamp value of the message stored in the receive FIFO buffer.

## 21.3.28 RSCAN0RFDF0x — Receive FIFO Buffer Access Data Field 0 Register (x = 0 to 7)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0E08H+ (x * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||RFDB3[7:0]||||||||RFDB2[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||RFDB1[7:0]||||||||RFDB0[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.42 RSCAN0RFDF0x register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 24|RFDB3[7:0]|Receive FIFO Buffer Data Byte 3|
|23 to 16|RFDB2[7:0]|Receive FIFO Buffer Data Byte 2<br>Receive FIFO Buffer Data Byte 1|
|15 to 8|RFDB1[7:0]|Receive FIFO Buffer Data Byte 0|
|7 to 0|RFDB0[7:0]|Data for a message stored in the receive FIFO buffer can be read.|

When the RFDLC[3:0] value in the RSCAN0RFPTRx register is smaller than 1000B, data bytes for which no data is set are read as 00H.

## 21.3.29 RSCAN0RFDF1x — Receive FIFO Buffer Access Data Field 1 Register (x = 0 to 7)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0E0CH+ (x * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||RFDB7[7:0]||||||||RFDB6[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||RFDB5[7:0]||||||||RFDB4[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 21.43 RSCAN0RFDF1x register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 24|RFDB7[7:0]|Receive FIFO Buffer Data Byte 7|
|23 to 16|RFDB6[7:0]|Receive FIFO Buffer Data Byte 6<br>Receive FIFO Buffer Data Byte 5|
|15 to 8|RFDB5[7:0]|Receive FIFO Buffer Data Byte 4|
|7 to 0|RFDB4[7:0]|Data for a message stored in the receive FIFO buffer can be read.|

When the RFDLC[3:0] value in the RSCAN0RFPTRx register is smaller than 1000B, data bytes for which no data is set are read as 00H.

21.3.30 RSCAN0CFCCk — Transmit/receive FIFO buffer Configuration and Control Register k (k = 0 to 5)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0118H+ (k * 0004H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||CFITT[7:0]||||||CFTML[3:0]|||CFITR|CFITSS|CFM[1:0]||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||CFIGCV[2:0]|||CFIM|—||CFDC[2:0]||—|—|—|—|—|CFTXIE|CFRXIE|CFE|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R|R|R|R|R/W|R/W|R/W|

**Table 21.44 RSCAN0CFCCk register contents (1/2)**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 24|CFITT[7:0]|Set a message transmission interval.|
|||Set Value: 00Hto FFH|
|23 to 20|CFTML[3:0]|Transmit Buffer Link Configuration|
|||Set the transmit buffer number to be linked to the transmit/receive FIFO buffer.|
|19|CFITR|Transmit/Receive FIFO Interval Timer Resolution|
|||0: Clock dividing pclk by ((ITRCP [15:0] bits)|
|||1: Clock dividing pclk by ((ITRCP [15:0] bits10)|
|18|CFITSS|Transmit/Receive FIFO Interval Timer Clock Source Select|
|||0: Interval timer clock source selected by the CFITR bit|
|||1: Interval timer clock source is the bit time clock for the channel to which the|
|||FIFO is linked.|
|17, 16|CFM[1:0]|Transmit/Receive FIFO Mode Select|
|||b17  b16|
|||0    0: Receive mode|
|||0    1: Transmit mode|
|||1    0: Gateway mode|
|||1    1: Setting prohibited|
|15 to 13|CFIGCV[2:0]|Transmit/Receive FIFO Receive Interrupt Request Timing Select|
|||b15  b14  b13|
|||0    0    0: When FIFO is 1/8 full.|
|||0    0    1: When FIFO is 2/8 full.|
|||0    1    0: When FIFO is 3/8 full.|
|||0    1    1: When FIFO is 4/8 full.|
|||1    0    0: When FIFO is 5/8 full.|
|||1    0    1: When FIFO is 6/8 full.|
|||1    1    0: When FIFO is 7/8 full.|
|||1    1    1: When FIFO is full.|

**Table 21.44 RSCAN0CFCCk register contents (2/2)**

|**Bit Position**|**Bit Name**|**Function**|**Function**|
|---|---|---|---|
|b12|CFIM|Transmit/Receive FIFO Interrupt Source Select||
|||0:||
|||Receive mode/gateway mode||
||||When the number of received messages has met the condition set by the|
||||CFIGCV[2:0] bits, a FIFO receive interrupt request is generated.|
|||Transmit mode/gateway mode||
||||When the buffer becomes empty upon completion of message transmission,|
||||a FIFO transmit interrupt request is generated.|
|||1:||
|||Receive mode/gateway mode||
||||A FIFO receive interrupt request is generated each time a message has|
||||been received.|
|||Transmit mode/gateway mode||
||||A FIFO transmit interrupt request is generated each time a message has|
||||been transmitted.|
|b11|Reserved|This bit is always read as 0. The write value should always be 0.||
|b10 to b8|CFDC[2:0]|Transmit/Receive FIFO Buffer Depth Configuration||
|||b10   b9    b8||
|||0|0    0: 0 messages|
|||0|0    1: 4 messages|
|||0|1    0: 8 messages|
|||0|1    1: 16 messages|
|||1|0    0: 32 messages|
|||1|0    1: 48 messages|
|||1|1    0: 64 messages|
|||1|1    1: 128 messages|
|b7 to b3|Reserved|These bits are always read as 0. The write value should always be 0.||
|b2|CFTXIE|Transmit/Receive FIFO Transmit Interrupt Enable||
|||0:|Transmit/receive FIFO transmit interrupt is disabled.|
|||1:|Transmit/receive FIFO transmit interrupt is enabled.|
|b1|CFRXIE|Transmit/Receive FIFO Receive Interrupt Enable||
|||0:|Transmit/receive FIFO receive interrupt is disabled.|
|||1:|Transmit/receive FIFO receive interrupt is enabled.|
|b0|CFE|Transmit/Receive FIFO Buffer Enable||
|||0:|No transmit/receive FIFO buffer is used.|
|||1:|Transmit/receive FIFO buffers are used.|

## CFITT[7:0] Bits

These bits are used to set a message transmission interval when transmitting messages continuously from a transmit/receive FIFO buffer whose CFM[1:0] bits are set to 01B (transmit mode) or 10B (gateway mode).

Clear the CFE bit to 0 (no transmit/receive FIFO buffer is used) before modifying the CFITT[7:0] bits.

## CFTML[3:0] Bits

These bits are used to set the number of transmit buffer on the channel which will be linked to transmit/ receive FIFO buffer k when the CFM[1:0] bits are set to 01B (transmit mode) or 10B (gateway mode). There are three transmit/receive FIFO buffers per channel, so channel number m of FIFO buffer k is calculated as m = k/3 (integer division). The actual assigned transmit buffer number p linked to FIFO buffer k will be ((16  m) + CFTML[3:0]).

Refer to Table 21.11 and Table 21.12 , as for the relationship between transmit/receive FIFO buffer k and transmit buffer p.

Setting the CFDC[2:0] bits to 001B or more enables the setting of the CFTML[3:0] bits.

Do not link to any transmit buffer which is already allocated to a transmit queue on the identical channel or to another transmit/receive FIFO buffer. Modify these bits only in global reset mode.

## CFITR Bit

This bit is enabled when the CFITSS bit is 1.

When this bit is 0, the interval timer clock source is the pclk/2 clock divided by the value of the ITRCP[15:0] bits in the RSCAN0GCFG register.

When this bit is 1, the interval timer clock source is the pclk/2 clock divided by (the value of the ITRCP[15:0] bits in the RSCAN0GCFG register  10).

## CFITSS Bit

When this bit is 0, the clock selected by the CFITR bit is the count source of the interval timer.

When this bit is 1, the bit time clock of the channel to which the FIFO is linked is the count source of the interval timer.

## CFM[1:0] Bits

These bits are used to select transmit/receive FIFO mode. Modify these bits only in global reset mode.

## CFIGCV[2:0] Bits

These bits are used to specify the number of received messages for generating a transmit/receive FIFO receive interrupt request when the CFM[1:0] bits are set to 00B (receive mode) or 10B (gateway mode) and the CFIM bit is set to 0 with a fraction for the total number of buffers (the setting of CFDC[2:0]).

An interrupt request is generated when the number of stored messages reaches the specified ratio (in fraction) of the storable messages set with the CFDC[2:0] bits.

When the CFDC[2:0] bits are set to 001B (4 messages), set the CFIGCV[2:0] bits to 001B, 011B, 101B, or B'111.

Modify these bits only in global reset mode.

## CFIM Bit

This bit is used to select a transmit/receive FIFO interrupt source. Modify this bit only in global reset mode.

## CFDC[2:0] Bits

These bits are used to set the number of messages that can be stored in a single transmit/receive FIFO buffer. When these bits are set to 000B, do not use a transmit/receive FIFO buffer. Modify these bits only in global reset mode.

## CFTXIE Bit

When this bit is set to 1 and the CFTXIF flag in the RSCAN0CFSTSk register is set to 1, a transmit/ receive FIFO transmit interrupt request is generated.

Modify this bit with the CFE bit set to 0 (no transmit/receive FIFO buffer is used).

## CFRXIE Bit

When this bit is set to 1 and the CFRXIF flag in the RSCAN0CFSTSk register is set to 1, a transmit/ receive FIFO receive interrupt request is generated.

Modify this bit with the CFE bit set to 0.

## CFE Bit

Setting this bit to 1 makes transmit/receive FIFO buffers available.

When this bit is set to 0 in transmit mode or gateway mode, if a message in the transmit/receive FIFO buffer is being transmitted or will be transmitted next, the transmit/receive FIFO buffer becomes empty after completion of transmission of that message, or upon detection of a CAN bus error, or arbitrationlost. In other cases or in receive mode, the transmit/receive FIFO buffer becomes empty immediately.

This bit is cleared to 0 when the following conditions are met.

- Receive mode: Global reset mode

- Transmit mode or gateway mode: Channel reset mode Modify this bit in the following mode.

- Receive mode: Global operating mode or global test mode

- Transmit mode or gateway mode: Channel communication mode or channel halt mode

## 21.3.31 RSCAN0CFSTSk — Transmit/receive FIFO buffer Status Register (k = 0 to 5)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0178H+ (k * 0004H)|||||||||||||
|**Initial value:**||0000|0000H||||||||||||
|Bit|31|30|29<br>28<br>27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—<br>—<br>—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0<br>0<br>0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R<br>R<br>R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13<br>12<br>11|10|9|8|7|6|5|4|3|2|1|0|
||||CFMC[7:0]||||—|—|—|CFTXIF|CFRXIF|CFMLT|CFFLL|CFEMP|
|Initial value|0|0|0<br>0<br>0|0|0|0|0|0|0|0|0|0|0|1|
|R/W|R|R|R<br>R<br>R|R|R|R|R|R|R|R/W*1|R/W*1|R/W*1|R|R|
|||Note 1.<br>The only effective||value for writing||to this flag bit is 0, which clears the bit. Otherwise writing to the bit results|||||||||
||||in retention of its state.||||||||||||

**Table 21.45 RSCAN0CFSTSk register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 16|Reserved|These bits are always read as 0. The write value should always be 0.|
|15 to 8|CFMC[7:0]|Transmit/Receive FIFO Message Counter|
|||The number of messages stored in the transmit/receive FIFO buffer.|
|7 to 5|Reserved|These bits are always read as 0. The write value should always be 0.|
|4|CFTXIF|Transmit/Receive FIFO Transmit Interrupt Request Flag|
|||0: No transmit/receive FIFO transmit interrupt request is present.|
|||1: A transmit/receive FIFO transmit interrupt request is present.|
|3|CFRXIF|Transmit/Receive FIFO Receive Interrupt Request Flag|
|||0: No transmit/receive FIFO receive interrupt request is present.|
|||1: A transmit/receive FIFO receive interrupt request is present.|
|2|CFMLT|Transmit/Receive FIFO Message Lost Flag|
|||0: No transmit/receive FIFO message is lost.|
|||1: A transmit/receive FIFO message is lost.|
|1|CFFLL|Transmit/Receive FIFO Buffer Full Status Flag|
|||0: The transmit/receive FIFO buffer is not full.|
|||1: The transmit/receive FIFO buffer is full.|
|0|CFEMP|Transmit/Receive FIFO Buffer Empty Status Flag|
|||0: The transmit/receive FIFO buffer contains messages.|
|||1: The transmit/receive FIFO buffer contains no message (buffer empty).|

## CFMC[7:0] Bits

The CFMC[7:0] bits indicate the following values that depend on the setting of the CFM[1:0] bits in the RSCAN0CFCCk register.

- When CFM[1:0] value is 01B (transmit mode): Number of untransmitted messages in the buffer

- When CFM[1:0] value is 00B (receive mode): Number of unread received messages in the buffer

- When CFM[1:0] value is 10B (gateway mode): Number of untransmitted received messages in the buffer

These bits are cleared to 0 when any of the following conditions is met.

- When CFM[1:0] value is 00B: In global reset mode

- When CFM[1:0] value is 01B or 10B: In channel reset mode

## CFTXIF Flag

The CFTXIF flag is set to 1 when any of the following conditions is met.

- When the CFM[1:0] bits are set to 01B or 10B, and the factor selected by the CFIM bit in the RSCAN0CFCCk register occurs

The CFTXIF flag is cleared to 0 when any of the following conditions is met.

- When 0 is written to the CFTXIF flag

- When the CFM[1:0] bits are set to 00B: In global reset mode

- When the CFM[1:0] bits are set to 01B or 10B: In channel reset mode

Write 0 to this flag in global operating mode or global test mode.

## CFRXIF Flag

The CFRXIF flag is set to 1 when any of the following conditions is met.

- When the CFM[1:0] bits are set to 00B or 10B, and the factor selected by the CFIM bit in the RSCAN0CFCCk register occurs

The CFRXIF flag is cleared to 0 when any of the following conditions is met.

- When 0 is written to the CFRXIF flag

- When the CFM[1:0] bits are set to 00B: In global reset mode

- When the CFM[1:0] bits are set to 01B or 10B: In channel reset mode

Write 0 to this flag in global operating mode or global test mode.

## CFMLT Flag

The CFMLT flag is set to 1 when any of the following conditions is met.

- When an attempt is made to store a new message while the transmit/receive FIFO buffer is full. In this case, the new message is discarded.

The CFMLT flag is cleared to 0 when any of the following conditions is met.

- When 0 is written to the CFMLT flag

- When the CFM[1:0] bits are set to 00B: In global reset mode

- When the CFM[1:0] bits are set to 01B or 10B: In channel reset mode

Write 0 to this flag in global operating mode or global test mode

## CFFLL Flag

The CFFLL flag is set to 1 when any of the following conditions is met.

- When the number of messages stored in the transmit/receive FIFO buffer matches the FIFO buffer depth set by the CFDC[2:0] bits in the RSCAN0CFCCk register.

The CFFLL flag is cleared to 0 when any of the following conditions is met.

- When the number of messages stored in the transmit/receive FIFO buffer becomes smaller than the FIFO buffer depth set by the CFDC[2:0] bits.

- When the CFE bit in the RSCAN0CFCCk register is 0 (no transmit/receive FIFO buffer is used): When not in the transmit abort

- When the CFM[1:0] bits are set to 00B: In global reset mode

- When the CFM[1:0] bits are set to 01B or 10B: In channel reset mode

## CFEMP Flag

The CFEMP flag is set to 1 when any of the following conditions is met.

- When the CFM[1:0] bits are set to 00B or 10B: All messages have been read, or in global reset mode

- When the CFM[1:0] bits are set to 01B: All messages have been transmitted, or in channel reset mode

- When the CFE bit is 0 (no transmit/receive FIFO buffer is used): Not in the transmit abort

The CFEMP flag is cleared to 0 when any of the following conditions is met.

- When the CFM[1:0] bits are set to 00B: At least one received message has been stored in the transmit/receive FIFO buffer.

- When the CFM[1:0] bits are set to 01B or 10B: A value of FFH has been written to the RSCAN0CFPCTRk register after data was written to the RSCAN0CFIDk, RSCAN0CFPTRk, RSCAN0CFDF0k, and RSCAN0CFDF1k registers.

## 21.3.32 RSCAN0CFPCTRk — Transmit/receive FIFO buffer Pointer Control Register (k = 0 to 5)

**==> picture [481 x 189] intentionally omitted <==**

**----- Start of picture text -----**<br>
Access: Can be written in 8-, 16-, and 32-bit units<br>Address: <RSCAN0_base> + 01D8H + (k * 0004H)<br>Initial value: 0000 0000H<br>Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>— — — — — — — — — — — — — — — —<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>Bit 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>— — — — — — — — CFPC[7:0]<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R W W W W W W W W<br>**----- End of picture text -----**<br>

**Table 21.46 RSCAN0CFPCTRk register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|Reserved|The write value should always be 0.|
|7 to 0|CFPC[7:0]|Transmit/Receive FIFO Pointer Control|
|||Receive mode:|
|||Writing FFHto these bits moves the read pointer to the next unread|
|||message in the transmit/receive FIFO buffer.|
|||Transmit mode:|
|||Writing FFHto these bits moves the write pointer to the next stage of the|
|||transmit/receive FIFO buffer.|
|||Gateway mode:|
|||Setting prohibited|

CFPC[7:0] Bits

- Receive mode (CFM[1:0] value in the RSCAN0CFCCk register is 00B): Writing FFH to the CFPC[7:0] bits moves the read pointer to the next unread message in the transmit/receive FIFO buffer. At this time, the CFMC[7:0] value (transmit/receive FIFO message counter) in the RSCAN0CFSTSk register is decremented. Read the RSCAN0CFIDk, RSCAN0CFPTRk, RSCAN0CFDF0k, and RSCAN0CFDF1k registers to read messages from the transmit/receive FIFO buffer, and then write FFH to the CFPC[7:0] bits. Write FFH to these bits when the CFE bit in the RSCAN0CFCCk register is set to 1 (transmit/ receive FIFO buffers are used) and the CFEMP flag in the RSCAN0CFSTSk register is cleared to 0 (the transmit/receive FIFO buffer contains messages).

- Transmit mode (CFM[1:0] value in the RSCAN0CFCCk register is 01B): Writing FFH to the CFPC[7:0] bits stores the data written to the RSCAN0CFIDk, RSCAN0CFPTRk, RSCAN0CFDF0k, and RSCAN0CFDF1k registers in the transmit/receive FIFO buffer and moves the write pointer to the next stage of the transmit/receive FIFO buffer. At this time, the CFMC[7:0] value is incremented. Write transmit messages to the RSCAN0CFIDk, RSCAN0CFPTRk, RSCAN0CFDF0k, and RSCAN0CFDF1k registers before writing FFH to the CFPC[7:0] bits.

Write FFH to these bits when the CFE bit in the RSCAN0CFCCk register is set to 1 and the CFFLL flag in the RSCAN0CFSTSk register is cleared to 0 (the transmit/receive FIFO buffer is not full).

- Gateway mode (CFM[1:0] value in the RSCAN0CFCCk register is 10B): Setting prohibited

## 21.3.33 RSCAN0CFIDk — Transmit/receive FIFO buffer Access ID Register (k = 0 to 5)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0E80H+ (k *||||0010H)|||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||CFIDE|CFRTR|THLEN|||||||CFID[28:16]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||CFID[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 21.47 RSCAN0CFIDk register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31|CFIDE|Transmit/Receive FIFO Buffer IDE|
|||0: Standard ID|
|||1: Extended ID|
|b30|CFRTR|Transmit/Receive FIFO Buffer RTR|
|||0: Data frame|
|||1: Remote frame|
|b29|THLEN|Transmit History Data Store Enable|
|||This bit is valid only when the CFM[1:0] value is 01B(transmit mode).|
|||0: Transmit history data is not stored in the buffer.|
|||1: Transmit history data is stored in the buffer.|
|b28 to b0|CFID[28:0]|Transmit/Receive FIFO Buffer ID Data|
|||When CFM[1:0] value is B'01 (transmit mode):|
|||Set standard ID or extended ID. For standard ID, write an ID to bits b10 to|
|||b0 and write 0 to bits b28 to b11.|
|||When CFM[1:0] value is B'00 (receive mode):|
|||Standard ID or extended ID in the received message can be read. For|
|||standard ID, read bits b10 to b0. Bits b28 to b11 are read as 0.|

This register is writable only when the CFM[1:0] value in the RSCAN0CFCCk register is 01B (transmit mode). This register is readable only when the CFM[1:0] value is 00B (receive mode). This RSCAN0CFIDk register should not be read or written when the CFM[1:0] value is 10B (gateway mode).

## CFIDE Bit

This bit indicates the ID format (standard ID or extended ID) of the received message stored in the transmit/receive FIFO buffer when the CFM[1:0] value is 00B. When the CFM[1:0] value is 01B, these bits are used to set the ID format of the message to be transmitted from the transmit/receive FIFO buffer.

## CFRTR Bit

This bit indicates the data format (data frame or remote frame) of the received message stored in the transmit/receive FIFO buffer when the CFM[1:0] value is 00B. When the CFM[1:0] value is 01B, this bit is used to set the data format of the message to be transmitted from the transmit/receive FIFO buffer.

## THLEN Bit

When this bit is set to 1, the transmit history data (label information, buffer number, and buffer type) of transmit messages is stored in the transmit history buffer after transmission is completed.

This bit is enabled when the CFM[1:0] value is 01B (transmit mode).

## CFID[28:0] Bits

These bits contain the ID of the received message stored in the transmit/receive FIFO buffer when the CFM[1:0] value is 00B.

When the CFM[1:0] value is B'01, this bit is used to set the ID of the message to be transmitted from the transmit/receive FIFO buffer.

## 21.3.34 RSCAN0CFPTRk — Transmit/receive FIFO buffer Access Pointer Register (k = 0 to 5)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0E84H+ (k *||||0010H)|||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||CFDLC[3:0]||||||||CFPTR[11:0]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||CFTS[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 21.48 RSCAN0CFPTRk register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b28|CFDLC[3:0]|Transmit/Receive FIFO Buffer DLC Data|
|||b31  b30  b29  b28|
|||0    0    0    0: 0 data bytes|
|||0    0    0    1: 1 data byte|
|||0    0    1    0: 2 data bytes|
|||0    0    1    1: 3 data bytes|
|||0    1    0    0: 4 data bytes|
|||0    1    0    1: 5 data bytes|
|||0    1    1    0: 6 data bytes|
|||0    1    1    1: 7 data bytes|
|||1    X    X    X: 8 data bytes|
|b27 to b16|CFPTR[11:0]|Transmit/Receive FIFO Buffer Label Data|
|||When CFM[1:0] value is 01B(transmit mode):|
|||Set the label information to be stored in the transmit history buffer.|
|||Only bits CFPTR[7:0] are valid.|
|||When CFM[1:0] value is 00B(receive mode):|
|||The label information of the received message can be read.|
|b15 to b0|CFTS[15:0]|Transmit/Receive FIFO Buffer Timestamp Data|
|||These bits are valid only when the CFM[1:0] value is B'00 (receive mode).|
|||The timestamp value of the received message can be read.|

This register is writable only when the CFM[1:0] value in the RSCAN0CFCCk register is 01B (transmit mode). This register is readable only when the CFM[1:0] value is 00B (receive mode). This register should not be read or written when the CFM[1:0] value is 10B (gateway mode).

## CFDLC[3:0] Bits

These bits indicate the data length of the received message stored in the transmit/receive FIFO buffer when the CFM[1:0] value is 00B. When the CFM[1:0] value is 01B, these bits are used to set the data length of the message to be transmitted from the transmit/receive FIFO buffer. If the data length is set to 9 bytes or more, the actual transmit data defaults to 8 bytes.

## CFPTR[11:0] Bits

These bits indicate the label information attached to the received message stored in the transmit/receive FIFO buffer when the CFM[1:0] value is 00B. When the CFM[1:0] value is 01B, the CFPTR[7:0] value is stored in the transmit history buffer when message transmission has been completed.

## CFTS[15:0] Bits

These bits indicate the timestamp value of the message stored in the transmit/receive FIFO buffer.

These bits are valid when the CFM[1:0] value is 00B.

21.3.35 RSCAN0CFDF0k — Transmit/receive FIFO buffer Access Data Field 0 Register (k = 0 to 5)

||**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0E88H+ (k *||||0010H)|||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||CFDB3[7:0]||||||||CFDB2[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||CFDB1[7:0]||||||||CFDB0[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 21.49 RSCAN0CFDF0k register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b24|CFDB3[7:0]|Transmit/Receive FIFO Buffer Data Byte 3|
|b23 to b16|CFDB2[7:0]|Transmit/Receive FIFO Buffer Data Byte 2<br>Transmit/Receive FIFO Buffer Data Byte 1|
|b15 to b8|CFDB1[7:0]|Transmit/Receive FIFO Buffer Data Byte 0|
|b7 to b0|CFDB0[7:0]|When CFM[1:0] value is 01B(transmit mode):|
|||Set the transmit/receive FIFO buffer data.|
|||When CFM[1:0] value is 00B(receive mode):|
|||The message data stored in the transmit/receive FIFO buffer can be read.|

This register is writable only when the CFM[1:0] value in the RSCAN0CFCCk register is 01B (transmit mode). This register is readable only when the CFM[1:0] value is 00B (receive mode). When the CFDLC[3:0] value in the RSCAN0CFPTRk register is smaller than 1000B, data bytes for which no data is set are read as 00H. This register should not be read or written when the CFM[1:0] value is 10B (gateway mode).

21.3.36 RSCAN0CFDF1k — Transmit/receive FIFO buffer Access Data Field 1 Register (k = 0 to 5)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0E8CH+ (k * 0010H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||CFDB7[7:0]||||||||CFDB6[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||CFDB5[7:0]||||||||CFDB4[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 21.50 RSCAN0CFDF1k register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|b31 to b24|CFDB7[7:0]|Transmit/Receive FIFO Buffer Data Byte 7|
|b23 to b16|CFDB6[7:0]|Transmit/Receive FIFO Buffer Data Byte 6<br>Transmit/Receive FIFO Buffer Data Byte 5|
|b15 to b8|CFDB5[7:0]|Transmit/Receive FIFO Buffer Data Byte 4|
|b7 to b0|CFDB4[7:0]|When CFM[1:0] value is 01B(transmit mode):|
|||Set the transmit/receive FIFO buffer data.|
|||When CFM[1:0] value is 00B(receive mode):|
|||The message data stored in the transmit/receive FIFO buffer can be read.|

This register is writable only when the CFM[1:0] value in the RSCAN0CFCCk register is 01B (transmit mode). This register is readable only when the CFM[1:0] value is 00B (receive mode). When the CFDLC[3:0] value in the RSCAN0CFPTRk register is smaller than 1000B, data bytes for which no data is set are read as 00H. This register should not be read or written when the CFM[1:0] value is 10B (gateway mode).

## 21.3.37 RSCAN0FESTS — FIFO Empty Status Register

|**Access:**|**Access:**|Can be read in|Can be read in|8-, 16-, and|8-, 16-, and|8-, 16-, and|32-bit|units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0238H|||||||||||||||||
|**Initial value:**||007F FFFFH|||||||||||||||||
|Bit|31|30|29||28||27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—||—||—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0||0||0|0|0|0|0|1|1|1|1|1|1|1|
|R/W|R|R|R||R||R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13||12||11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|CF5EM||CF4EM|CF3EM||CF2EM|CF1EM|CF0EM|RF7EM|RF6EM|RF5EM|RF4EM|RF3EM|RF2EM|RF1EM|RF0EM|
||||P||P||P|P|P|P|P|P|P|P|P|P|P|P|
|Initial value|1|1|1||1||1|1|1|1|1|1|1|1|1|1|1|1|
|R/W|R|R|R||R||R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.51 RSCAN0FESTS register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 23|Reserved|These bits are always read as 0.|
|22|to 14|Reserved|These bits are always read as 1.|
|13||CF5EMP|Transmit/Receive FIFO Buffer Empty Status Flag|
|12||CF4EMP|0: Transmit/receive FIFO buffer k contains a message.<br>1: Transmit/receive FIFO buffer k contains no message.|
|11||CF3EMP|(k = 0 to 5)|
|10||CF2EMP||
|9||CF1EMP||
|8||CF0EMP||
|7||RF7EMP|Receive FIFO Buffer Empty Status Flag|
|6||RF6EMP|0: Receive FIFO buffer x contains an unread message.<br>1: Receive FIFO buffer x contains no unread message (buffer empty).|
|5||RF5EMP|(x = 0 to 7)|
|4||RF4EMP||
|3||RF3EMP||
|2||RF2EMP||
|1||RF1EMP||
|0||RF0EMP||

The RSCAN0FESTS register is set to 007F FFFFH in global reset mode.

## CFkEMP Flag (k = 0 to 5)

The CFkEMP flag is set to 1 when the CFEMP flag in the RSCAN0CFSTSk register is set to 1 (the transmit/receive FIFO buffer contains no message (buffer empty)). When the CFEMP flag is cleared to 0 (the transmit/receive FIFO buffer contains messages), the CFkEMP flag is cleared to 0.

## RFxEMP Flag (x = 0 to 7)

The RFxEMP flag is set to 1 when the RFEMP flag in the RSCAN0RFSTSx register is set to 1 (the receive FIFO buffer contains no unread message (buffer empty)). When the RFEMP flag is cleared to 0 (the receive FIFO buffer contains unread messages), the RFxEMP flag is cleared to 0.

## 21.3.38 RSCAN0FFSTS — FIFO Full Status Register

|**Access:**|**Access:**|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|32-bit|units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 023CH|||||||||||||||||
|**Initial value:**||0000|0000H||||||||||||||||
|Bit|31|30||29|28||27|26|25|24|23|22|21|20|19|18|17|16|
||—|—||—|—||—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R||R|R||R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14||13|12||11|10|9|8|7|6|5|4|3|2|1|0|
||—|—||CF5FLL|CF4FLL|CF3FLL||CF2FLL|CF1FLL|CF0FLL|RF7FLL|RF6FLL|RF5FLL|RF4FLL|RF3FLL|RF2FLL|RF1FLL|RF0FLL|
|Initial value|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R||R|R||R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.52 RSCAN0FFSTS register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 14|Reserved|These bits are always read as 0.|
|13||CF5FLL|Transmit/Receive FIFO Buffer Full Status Flag|
|12||CF4FLL|0: Transmit/receive buffer k is not full.<br>1: Transmit/receive buffer k is full.|
|11||CF3FLL|(k = 0 to 5)|
|10||CF2FLL||
|9||CF1FLL||
|8||CF0FLL||
|7||RF7FLL|Receive FIFO Buffer Full Status Flag|
|6||RF6FLL|0: Receive FIFO buffer x is not full.<br>1: Receive FIFO buffer x is full.|
|5||RF5FLL|(x = 0 to 7)|
|4||RF4FLL||
|3||RF3FLL||
|2||RF2FLL||
|1||RF1FLL||
|0||RF0FLL||

The RSCAN0FFSTS register is cleared to 0000 0000H in global reset mode.

## CFkFLL Flag (k = 0 to 5)

The CF k FLL flag is set to 1 when the CFFLL flag in the RSCAN0CFSTSk register is set to 1 (the transmit/receive FIFO buffer is full). When the CFFLL flag is cleared to 0 (the transmit/receive FIFO buffer is not full), the CFkFLL flag is cleared to 0.

## RFxFLL Flag (x = 0 to 7)

The RFxFLL flag is set to 1 when the RFFLL flag in the RSCAN0RFSTSx register is set to 1 (the receive FIFO buffer is full). When the RFFLL flag is cleared to 0 (the receive FIFO buffer is not full), the RFxFLL flag is cleared to 0.

## 21.3.39 RSCAN0FMSTS — FIFO Message Lost Status Register

|**Access:**|**Access:**|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|32-bit|units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0240H|||||||||||||||||
|**Initial value:**||0000|0000H||||||||||||||||
|Bit|31|30||29|28||27|26|25|24|23|22|21|20|19|18|17|16|
||—|—||—|—||—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R||R|R||R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14||13|12||11|10|9|8|7|6|5|4|3|2|1|0|
||—|—||CF5MLT|CF4MLT|CF3MLT||CF2MLT|CF1MLT|CF0MLT|RF7MLT|RF6MLT|RF5MLT|RF4MLT|RF3MLT|RF2MLT|RF1MLT|RF0MLT|
|Initial value|0|0||0|0||0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R||R|R||R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.53 RSCAN0FMSTS register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 14|Reserved|These bits are always read as 0.|
|13||CF5MLT|Transmit/Receive FIFO Buffer Message Lost Status Flag|
|12||CF4MLT|0: No transmit/receive FIFO buffer k message is lost.<br>1: A transmit/receive FIFO buffer k message is lost.|
|11||CF3MLT|(k = 0 to 5)|
|10||CF2MLT||
|9||CF1MLT||
|8||CF0MLT||
|7||RF7MLT|Receive FIFO Buffer Message Lost Status Flag|
|6||RF6MLT|0: No receive FIFO buffer x message is lost.<br>1: A receive FIFO buffer x message is lost.|
|5||RF5MLT|(x = 0 to 7)|
|4||RF4MLT||
|3||RF3MLT||
|2||RF2MLT||
|1||RF1MLT||
|0||RF0MLT||

The RSCAN0FMSTS register is cleared to 0000 0000H in global reset mode.

## CFkMLT Flag (k = 0 to 5)

The CFkMLT flag is set to 1 when the CFMLT flag in the RSCAN0CFSTSk register is set to 1 (a transmit/receive FIFO message is lost). When the CFMLT flag is cleared to 0, the CFkMLT flag is cleared to 0.

RFxMLT Flag (x = 0 to 7)

The RFxMLT flag is set to 1 when the RFMLT flag in the RSCAN0RFSTSx register is set to 1 (a receive FIFO message is lost). When the RFMLT flag is cleared to 0, the RFxMLT flag is cleared to 0.

## 21.3.40 RSCAN0RFISTS — Receive FIFO Buffer Interrupt Flag Status Register

|**Access:**|**Access:**|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|Can be read in 8-, 16-, and|32-bit|units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0244H||||||||||||||||
|**Initial value:**||0000 0000H||||||||||||||||
|Bit|31|30|29|28||27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—|—||—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R||R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12||11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—||—|—|—|—|RF7IF|RF6IF|RF5IF|RF4IF|RF3IF|RF2IF|RF1IF|RF0IF|
|Initial value|0|0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R||R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.54 RSCAN0RFISTS register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 8|Reserved|These bits are always read as 0.|
|7||RF7IF|Receive FIFO Buffer Interrupt Request Status Flag|
|6||RF6IF|0: No receive FIFO buffer x interrupt request is present.<br>1: A receive FIFO buffer x interrupt request is present.|
|5||RF5IF|(x = 0 to 7)|
|4||RF4IF||
|3||RF3IF||
|2||RF2IF||
|1||RF1IF||
|0||RF0IF||

The RSCAN0RFISTS register is cleared to 0000 0000H in global reset mode.

## RFxIF Flag (x = 0 to 7)

The RFxIF flag is set to 1 when the RFIF flag in the RSCAN0RFSTSx register is set to 1 (a receive FIFO interrupt request is present). When the RFIF flag is cleared to 0, the RFxIF flag is cleared to 0.

## 21.3.41 RSCAN0CFRISTS — Transmit/receive FIFO buffer Receive Interrupt Flag Status Register

**==> picture [481 x 189] intentionally omitted <==**

**----- Start of picture text -----**<br>
Access: Can be read in 8-, 16-, and 32-bit units<br>Address: <RSCAN0_base> + 0248H<br>Initial value: 0000 0000H<br>Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>— — — — — — — — — — — — — — — —<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>Bit 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>— — — — — — — — — — CF5RXIF CF4RXIF CF3RXIF CF2RXIF CF1RXIF CF0RXIF<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>**----- End of picture text -----**<br>

**Table 21.55 RSCAN0CFRISTS register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 6|Reserved|These bits are always read as 0.|
|5||CF5RXIF|Transmit/Receive FIFO Buffer Receive Interrupt Request Status Flag|
|4||CF4RXIF|0: No transmit/receive FIFO buffer k receive interrupt request is present.<br>1: A transmit/receive FIFO buffer k receive interrupt request is present.|
|3||CF3RXIF|(k = 0 to 5)|
|2||CF2RXIF||
|1||CF1RXIF||
|0||CF0RXIF||

The RSCAN0CFRISTS register is cleared to 0000 0000H in global reset mode.

## CFkRXIF Flag (k = 0 to 5)

The CFkRXIF flag is set to 1 when the CFRXIF flag in the RSCAN0CFSTSk register is set to 1 (a transmit/receive FIFO receive interrupt request is present). When the CFRXIF flag is cleared to 0, the CFkRXIF flag is cleared to 0.

## 21.3.42 RSCAN0CFTISTS — Transmit/receive FIFO buffer Transmit Interrupt Flag Status Register

**==> picture [481 x 189] intentionally omitted <==**

**----- Start of picture text -----**<br>
Access: Can be read in 8-, 16-, and 32-bit units<br>Address: <RSCAN0_base> + 024CH<br>Initial value: 0000 0000H<br>Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16<br>— — — — — — — — — — — — — — — —<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>Bit 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0<br>— — — — — — — — — — CF5TXIF CF4TXIF CF3TXIF CF2TXIF CF1TXIF CF0TXIF<br>Initial value 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0<br>R/W R R R R R R R R R R R R R R R R<br>**----- End of picture text -----**<br>

**Table 21.56 RSCAN0CFTISTS register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 6|Reserved|These bits are always read as 0.|
|5||CF5TXIF|Transmit/Receive FIFO Buffer Transmit Interrupt Request Status Flag|
|4||CF4TXIF|0: No transmit/receive FIFO buffer k transmit interrupt request is present.<br>1: A transmit/receive FIFO buffer k transmit interrupt request is present.|
|3||CF3TXIF|(k = 0 to 5)|
|2||CF2TXIF||
|1||CF1TXIF||
|0||CF0TXIF||

The RSCAN0CFTISTS register is cleared to 0000 0000H in global reset mode.

## CFkTXIF Flag (k = 0 to 5)

The CFkTXIF flag is set to 1 when the CFTXIF flag in the RSCAN0CFSTSk register is set to 1 (a transmit/receive FIFO transmit interrupt request is present). When the CFTXIF flag is cleared to 0, the CFkTXIF flag is cleared to 0.

## 21.3.43 RSCAN0TMCp — Transmit Buffer Control Register (p = 0 to 31)

**Access:** Can be read/written in 8-bit units **Address:** <RSCAN0_base> + 0250H + (01H  p) **Initial value:** 00H

|Bit<br>7<br>6<br>5<br>4<br>3<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R|Bit<br>7<br>6<br>5<br>4<br>3<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R|Bit<br>7<br>6<br>5<br>4<br>3<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R|Bit<br>7<br>6<br>5<br>4<br>3<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R|Bit<br>7<br>6<br>5<br>4<br>3<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R|Bit<br>7<br>6<br>5<br>4<br>3<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R|2<br>1<br>0|2<br>1<br>0|2<br>1<br>0|
|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|TMOM|TMTAR|TMTR|
|||||||0<br>0<br>0<br>R/W<br>R/W*1<br>R/W*1|||

Note 1. The only effective value for writing to this bit is 1, which sets the bit. Otherwise writing to the bit results in retention of its state.

**Table 21.57 RSCAN0TMCp register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 3|Reserved|These bits are always read as 0. The write value should always be 0.|
|2|TMOM|One-Shot Transmission Enable|
|||0: One-shot transmission is disabled.|
|||1: One-shot transmission is enabled.|
|1|TMTAR|Transmit Abort Request|
|||0: Transmit abort is not requested.|
|||1: Transmit abort is requested.|
|0|TMTR|Transmit Request|
|||0: Transmission is not requested.|
|||1: Transmission is requested.|

When the RSCAN0TMCp register meets any of the following conditions, set it to 00H.

- The RSCAN0TMCp register corresponds to the transmit buffer number selected by the CFTML[3:0] bits in the RSCAN0CFCCk register (p = m  16 + the value of CFTML[3:0] bits).

- The RSCAN0TMCp register corresponds to the transmit buffer allocated to the transmit queue by the TXQDC[3:0] bits in the RSCAN0TXQCCm register (m = 0 or 1) (p = (m × 16 + 15) to (m × 16 + 15 - the value of TXQDC[3:0] bits)).

Bits in the RSCAN0TMCp register are all cleared to 0 in channel reset mode. Modify the RSCAN0TMCp register in channel communication mode or channel halt mode.

## TMOM Bit

Setting this bit to 1 enables one-shot transmission. When transmission fails, retransmission defined in the CAN protocol is not performed.

Modify the TMOM bit when the TMTRM flag in the RSCAN0TMSTSp register is set to 0. Set the TMOM bit to 1 together with the TMTR bit.

## TMTAR Bit

Setting this bit to 1 generates a transmit abort request for the message stored in the transmit buffer. However, a message that is being transmitted or one that will be transmitted next cannot be aborted.

When the TMTAR bit can be set to 1 when TMTR bit is 1.

The TMTAR bit is cleared to 0 when any of the following conditions is met, but cannot be cleared by the program writing 0 to the bit.

- Transmission has been completed.

- Transmit abort has been completed.

- An error or arbitration loss has been detected.

If this bit becomes 0 at the same time as the program writes 1 to this bit, this bit becomes 0.

## TMTR Bit

Setting this bit to 1 transmits the message stored in the transmit buffer.

The TMTR bit is cleared to 0 when any of the following conditions is met, but cannot be cleared by the program writing 0 to the bit.

- Transmission has been completed.

- Transmit abort has been completed after the TMTAR bit was set to 1.

- An error or arbitration-lost has been detected with the TMOM bit set to 1.

Set the TMTR bit to 1 when the value of TMTRF[1:0] in the RSCAN0TMSTSp register is 00B.

## 21.3.44 RSCAN0TMSTSp — Transmit Buffer Status Register (p = 0 to 31)

|**Access:**<br>Can be read/written in 8-bit units<br>**Address:**<br><RSCAN0_base> + 02D0H+ (01H <br>**Initial value:**<br>00H<br>Bit<br>7<br>6<br>5<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-bit units<br>**Address:**<br><RSCAN0_base> + 02D0H+ (01H <br>**Initial value:**<br>00H<br>Bit<br>7<br>6<br>5<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-bit units<br>**Address:**<br><RSCAN0_base> + 02D0H+ (01H <br>**Initial value:**<br>00H<br>Bit<br>7<br>6<br>5<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-bit units<br>**Address:**<br><RSCAN0_base> + 02D0H+ (01H <br>**Initial value:**<br>00H<br>Bit<br>7<br>6<br>5<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R|p)<br>4<br>3<br>2<br>1<br>0|p)<br>4<br>3<br>2<br>1<br>0|p)<br>4<br>3<br>2<br>1<br>0|p)<br>4<br>3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|
||—|—|—|TMTARM|TMTRM|TMTRF[1:0]|TMTSTS|
|||||0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R||||

## **Table 21.58 RSCAN0TMSTSp register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 5|Reserved|These bits are always read as 0. The write value should always be 0.|
|4|TMTARM|Transmit Buffer Transmit Abort Request Status Flag|
|||0: No transmit abort request is present.|
|||1: A transmit abort request is present.|
|3|TMTRM|Transmit Buffer Transmit Request Status Flag|
|||0: No transmit request is present.|
|||1: A transmit request is present.|
|2, 1|TMTRF[1:0]|Transmit Buffer Transmit Result Status Flag|
|||b2    b1|
|||0    0: Transmission is in progress or no transmit request is present.|
|||0    1: Transmit abort has been completed.|
|||1    0: Transmission has been completed (without transmit abort request).|
|||1    1: Transmission has been completed (with transmit abort request).|
|0|TMTSTS|Transmit Buffer Transmit Status Flag|
|||0: Transmission is not in progress.|
|||1: Transmission is in progress.|

The RSCAN0TMSTSp register is cleared to all 0 in channel reset mode.

## TMTARM Flag

The TMTARM flag is set to 1 when the TMTAR bit in the RSCAN0TMCp register is set to 1. The TMTARM flag is set to 0 when the TMTAR bit in the RSCAN0TMCp register is set to 0.

## TMTRM Flag

The TMTRM flag is set to 1 when the TMTR bit in the RSCAN0TMCp register is set to 1. The TMTRM flag is set to 0 when the TMTR bit in the RSCAN0TMCp register is set to 0

## TMTRF[1:0] Flag

This flag indicates the result of transmission from the transmit buffer.

00B: Transmission is in progress or no transmit request is present.

01B: Transmission from the transmit buffer was aborted.

10B: Transmission has been completed with the TMTAR bit in the RSCAN0TMCp register set to 0 (transmit abort is not requested).

11B: Transmission has been completed with the TMTAR bit in the RSCAN0TMCp register set to 1 (transmit abort is requested).

Write 00B to the TMTRF[1:0] flag in channel communication mode or channel halt mode. Do not write any value other than 00B to this flag.

## TMTSTS Flag

This flag is set to 1 when transmission from the transmit buffer starts, and is cleared to 0 when transmission from the transmit buffer has been completed or terminated due to a bus error or arbitration lost.

## 21.3.45 RSCAN0TMTRSTSy — Transmit Buffer Transmit Request Status Register y (y = 0)

|**Access:**|**Access:**|Can be read|in 8-, 16-, and 32-bit units|in 8-, 16-, and 32-bit units|in 8-, 16-, and 32-bit units||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0350H+|||(y * 0004H)||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||||TMTRSTSp (p = y32 + 31 to y||||32 + 16 (y = 0))|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||TMTRSTSp (p||= y32 +|15 to y32 + 0 (y = 0))||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 21.59 RSCAN0TMTRSTSy register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|TMTRSTSp|Transmit Buffer Transmit Request Status Flag p (p = y32 + 31 to y32 + 16)|
||||0: No transmission is requested.|
||||1: Transmission is requested.|
|15|to 0|TMTRSTSp|Transmit Buffer Transmit Request Status Flag p (p = y32 + 15 to y32 + 0)|
||||0: No transmit request is present.|
||||1: A transmit request is present.|

TMTRSTSp Flags (p = 0 to 31)

These flags indicate the status of the TMTR bit in the RSCAN0TMCp register.

When the TMTR bit is set to 1 (transmission is requested), the corresponding TMTRSTSp flag is set to 1.

The corresponding TMTRSTSp flag is cleared to 0 when the TMTR bit is set to 0 (transmission is not requested) or in channel reset mode.

Table 21.60 shows the bit assignment.

**Table 21.60 TMTRSTSp Bit Assignment**

||**Bit**||**Channel**||**Transmit Buffer Number**|
|---|---|---|---|---|---|
|0||0||0||
|1||0||1||
|.||.||.||
|.||.||.||
|15||0||15||
|16||1||0||
|.||.||.||
|.||.||.||
|30||1||14||
|31||1||15||

## 21.3.46 RSCAN0TMTARSTSy — Transmit Buffer Transmit Abort Request Status Register y (y = 0)

|**Access:**|**Access:**|Can be read|in 8-, 16-, and 32-bit units|in 8-, 16-, and 32-bit units|in 8-, 16-, and 32-bit units||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0360H+ (y * 0004H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||||TMTARSTSp (p = y32|||+ 31 to y32 + 16||(y = 0))||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||TMTARSTSp (p||= y32 + 15 to y||32 + 0 (y = 0))|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 21.61 RSCAN0TMTARSTSy register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|TMTARSTSp|Transmit Buffer Transmit Abort Request Status Flag p (p = y32 + 31 to y32|
||||+ 16)|
||||0: No transmission abort is requested.|
||||1: Transmission abort is requested.|
|15|to 0|TMTARSTSp|Transmit Buffer Transmit Abort Request Status Flag p (p = y32 + 15 to y32|
||||+ 0)|
||||0: No transmit abort request is present.|
||||1: A transmit abort request is present.|

## TMTARSTSp Flags (p = 0 to 31)

These flags indicate the status of the TMTAR bit in the RSCAN0TMCp register.

When the TMTAR bit is set to 1 (transmit abort is requested), the corresponding TMTARSTSp flag is set to 1.

The corresponding TMTARSTSp flag is cleared to 0 when the TMTAR bit is set to 0 (transmit abort is not requested) or in channel reset mode.

Table 21.62 shows the bit assignment.

**Table 21.62 TMTARSTSp Bit Assignment**

||**Bit**||**Channel**||**Transmit Buffer Number**|
|---|---|---|---|---|---|
|0||0||0||
|1||0||1||
|.||.||.||
|.||.||.||
|15||0||15||
|16||1||0||
|.||.||.||
|.||.||.||
|30||1||14||
|31||1||15||

## 21.3.47 RSCAN0TMTCSTSy — Transmit Buffer Transmit Complete Status Register y (y = 0)

|**Access:**|**Access:**|Can be read|in 8-, 16-, and 32-bit units|in 8-, 16-, and 32-bit units|in 8-, 16-, and 32-bit units||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0370H+|||(y * 0004H)||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||||TMTCSTSp (p = y32 + 31 to y||||32 + 16 (y = 0))|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||TMTCSTSp (p||= y32 +|15 to y32 + 0 (y = 0))||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 21.63 RSCAN0TMTCSTSy register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|TMTCSTSp|Transmit Buffer Transmit Complete Status Flag p (p = y32 + 31 to y32 + 16)|
||||0: Transmission is not completed|
||||1: Transmission is completed|
|15|to 0|TMTCSTSp|Transmit Buffer Transmit Complete Status Flag p (p = y32 + 15 to y32 + 0)|
||||0: Transmission has not been completed.|
||||1: Transmission has been completed.|

## TMTCSTSp Flags (p = 0 to 31)

When the TMTRF[1:0] flag in the RSCAN0TMSTSp register is set to 10B (transmission has been completed (without transmit abort request)) or 11B (transmission has been completed (with transmit abort request)), the corresponding TMTCSTSp flag is set to 1.

A TMTCSTSp flag is cleared to 0 when the corresponding TMTRF[1:0] flag is set to 00B or in channel reset mode.

Table 21.64 shows the bit assignment.

**Table 21.64 TMTCSTSp Bit Assignment**

||**Bit**||**Channel**||**Transmit Buffer Number**|
|---|---|---|---|---|---|
|0||0||0||
|1||0||1||
|.||.||.||
|.||.||.||
|15||0||15||
|16||1||0||
|.||.||.||
|.||.||.||
|30||1||14||
|31||1||15||

## 21.3.48 RSCAN0TMTASTSy — Transmit Buffer Transmit Abort Status Register y (y = 0)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit|Can be read in 8-, 16-, and 32-bit|Can be read in 8-, 16-, and 32-bit|Can be read in 8-, 16-, and 32-bit|units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0380H+ (y *||||0004H)|||||||||||
|**Initial**|**value:**|0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||||TMTASTSp (p = y32 + 31 to y||||32 + 16 (y = 0))|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||TMTASTSp (p = y32 +|||15 to y32 + 0 (y = 0))||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

## **Table 21.65 RSCAN0TMTASTSy register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|TMTASTSp|Transmit Buffer Transmit Abort Status Flag p (p = y32 + 31 to y32 + 16)|
||||0: Transmission is not aborted|
||||1: Transmission is aborted|
|15|to 0|TMTASTSp|Transmit Buffer Transmit Abort Status Flag p (p = y32 + 15 to y32 + 0)|
||||0: Transmission is not aborted.|
||||1: Transmission is aborted.|

## TMTASTSp Flags (p = 0 to 31)

When the TMTRF[1:0] flag in the RSCAN0TMSTSp register is set to 01B (transmit abort has been completed), the corresponding TMTASTSp flag is set to 1.

A TMTASTSp flag is cleared to 0 when the corresponding TMTRF[1:0] flag is set to 00B or in channel reset mode.

Table 21.66 shows the bit assignment.

**Table 21.66 TMTASTSp Bit Assignment**

||**Bit**||**Channel**||**Transmit Buffer Number**|
|---|---|---|---|---|---|
|0||0||0||
|1||0||1||
|.||.||.||
|.||.||.||
|15||0||15||
|16||1||0||
|.||.||.||
|.||.||.||
|30||1||14||
|31||1||15||

21.3.49 RSCAN0TMIECy — Transmit Buffer Interrupt Enable Configuration Register y (y = 0)

|**Access:**|**Access:**|Can be|read/written|read/written|in 8-, 16-, and 32-bit units|in 8-, 16-, and 32-bit units|in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> +|||0390H|+ (y * 0004H)||||||||||||
|**Initial**|**value:**|0000 0000H||||||||||||||||
|Bit|31|30|29||28|27|26|25|24|23|22|21|20|19|18|17|16|
||||||||TMIEp|(p = y × 32 + 31 to y × 32 + 16 (y = 0))||||||||||
|Initial value|0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13||12|11|10|9|8|7|6|5|4|3|2|1|0|
||||||||TMIEp (p = y||× 32 + 15 to y × 32 + 0 (y = 0))|||||||||
|Initial value|0|0|0||0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 21.67 RSCAN0TMIECy register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|TMIEp|Transmit Buffer Interrupt Enable Bit p (p = y32 + 31 to y32 + 16)|
||||0: Transmit buffer interrupt is disabled|
||||1: Transmit buffer interrupt is enabled|
|15|to 0|TMIEp|Transmit Buffer Interrupt Enable Bit p (p = y32 + 15 to y32 + 0)|
||||0: Transmit buffer interrupt is disabled.|
||||1: Transmit buffer interrupt is enabled.|

## TMIEp Bits (p = 0 to 31)

When any of these bits is set to 1 and the corresponding transmission has been completed, a transmit buffer interrupt request is generated.

Modify these bits when the TMTRM flag in the corresponding RSCAN0TMSTSp register is 0 (no transmit request is present).

Write 0 to bits corresponding to transmit buffers linked to transmit/receive FIFO buffers or transmit buffers allocated to the transmit queue.

Table 21.68 shows the bit assignment.

**Table 21.68 TMIEp Bit Assignment**

||**Bit**||**Channel**||**Transmit Buffer Number**|
|---|---|---|---|---|---|
|0||0||0||
|1||0||1||
|.||.||.||
|.||.||.||
|15||0||15||
|16||1||0||
|.||.||.||
|.||.||.||
|30||1||14||
|31||1||15||

## 21.3.50 RSCAN0TMIDp — Transmit Buffer ID Register (p = 0 to 31)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 1000H+ (p *||||0010H)|||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||TMIDE|TMRTR|THLEN|||||||TMID[28:16]|||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||TMID[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

## **Table 21.69 RSCAN0TMIDp register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31||TMIDE|Transmit Buffer IDE|
||||0: Standard ID|
||||1: Extended ID|
|30||TMRTR|Transmit Buffer RTR|
||||0: Data frame|
||||1: Remote frame|
|29||THLEN|Transmit History Data Store Enable|
||||0: Transmit history data is not stored in the buffer.|
||||1: Transmit history data is stored in the buffer.|
|28|to 0|TMID[28:0]|Transmit Buffer ID Data|
||||Set standard ID or extended ID.|
||||For standard ID, write an ID to bits 10 to 0 and write 0 to bits 28 to 11.|

Modify this register when the TMTRM bit in the corresponding RSCAN0TMSTSp register is set to 0 (no transmit request is present). If this register is linked to a transmit/receive FIFO buffer, do not write data to this register. If this register is allocated to the transmit queue, only write data to a transmit buffer p (p = m  16 + 15) for the corresponding channel.

## TMIDE Bit

This bit is used to set the ID format of the message to be transmitted from the transmit buffer.

## TMRTR Bit

This bit is used to set the data format of the message to be transmitted from the transmit buffer.

## THLEN Bit

When this bit is set to 1, the transmit history data of the transmit message (the label information and the number and type of the transmit buffer) are stored in the transmit history buffer after transmission is completed.

## TMID[28:0] Bits

These bits are used to set the ID of the message to be transmitted from the transmit buffer.

## 21.3.51 RSCAN0TMPTRp — Transmit Buffer Pointer Register (p= 0 to 31)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 1004H+ (p * 0010H)||||||||||||||||
|**Initial value:**||0000 0000H||||||||||||||||
|Bit|31|30|29|28|27|26||25|24|23|22|21|20|19|18|17|16|
|||TMDLC[3:0]|||—|—||—|—||||TMPTR[7:0]|||||
|Initial value|0|0|0|0|0|0||0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R|R||R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10||9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|—||—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0||0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R||R|R|R|R|R|R|R|R|R|R|

## **Table 21.70 RSCAN0TMPTRp register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 28|TMDLC[3:0]|Transmit Buffer DLC Data|
||||b31 b30  b29  b28|
||||0    0    0    0: 0 data bytes|
||||0    0    0    1: 1 data byte|
||||0    0    1    0: 2 data bytes|
||||0    0    1    1: 3 data bytes|
||||0    1    0    0: 4 data bytes|
||||0    1    0    1: 5 data bytes|
||||0    1    1    0: 6 data bytes|
||||0    1    1    1: 7 data bytes|
||||1    X    X    X: 8 data bytes|
|27|to 24|Reserved|These bits are always read as 0. The write value should always be 0.|
|23|to 16|TMPTR[7:0]|Transmit Buffer Label Data|
||||Set the label information to be stored in the transmit history buffer.|
|15|to 0|Reserved|These bits are always read as 0. The write value should always be 0.|

Modify this register when the TMTRM bit in the corresponding RSCAN0TMSTSp register is set to 0 (no transmit request is present). If this register is linked to a transmit/receive FIFO buffer, do not write to this register. If this register is allocated to the transmit queue, only write to a transmit buffer p (p = m  16 + 15) for the corresponding channel.

## TMDLC[3:0] Bits

These bits are used to set the data length of the message to be transmitted from the transmit buffer when the TMRTR bit in the RSCAN0TMIDp register is set to 0 (data frame). If the data length is set to 9 bytes or more, the transmit data is 8 bytes long.

When the TMRTR bit is set to 1 (remote frame), set the data length of messages to be requested.

## TMPTR[7:0] Bits

When message transmission has been completed, the TMPTR[7:0] value is stored in the transmit history buffer.

## 21.3.52 RSCAN0TMDF0p — Transmit Buffer Data Field 0 Register (p = 0 to 31)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 1008H+ (p *||||0010H)|||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||TMDB3[7:0]||||||||TMDB2[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||TMDB1[7:0]||||||||TMDB0[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 21.71 RSCAN0TMDF0p register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 24|TMDB3[7:0]|Transmit Buffer Data Byte 3|
|23 to 16|TMDB2[7:0]|Transmit Buffer Data Byte 2<br>Transmit Buffer Data Byte 1|
|15 to 8|TMDB1[7:0]|Transmit Buffer Data Byte 0|
|7 to 0|TMDB0[7:0]|Set the transmit buffer data.|

Modify this register when the TMTRM bit in the corresponding RSCAN0TMSTSp register is set to 0 (no transmit request is present). If this register is linked to a transmit/receive FIFO buffer, do not write to this register. If this register is allocated to the transmit queue, only write to a transmit buffer p (p = m  16 + 15) for the corresponding channel.

## 21.3.53 RSCAN0TMDF1p — Transmit Buffer Data Field 1 Register (p = 0 to 31)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|Can be read/written in 8-, 16-, and 32-bit|units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 100CH+ (p *||||0010H)|||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|||||TMDB7[7:0]||||||||TMDB6[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||TMDB5[7:0]||||||||TMDB4[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

**Table 21.72 RSCAN0TMDF1p register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 24|TMDB7[7:0]|Transmit Buffer Data Byte 7|
|23 to 16|TMDB6[7:0]|Transmit Buffer Data Byte 6<br>Transmit Buffer Data Byte 5|
|15 to 8|TMDB5[7:0]|Transmit Buffer Data Byte 4|
|7 to 0|TMDB4[7:0]|Set the transmit buffer data.|

Modify this register when the TMTRM bit in the corresponding RSCAN0TMSTSp register is set to 0 (no transmit request is present). If this register is linked to a transmit/receive FIFO buffer, do not write to this register. If this register is allocated to the transmit queue, only write to a transmit buffer p (p = m  16 + 15) for the corresponding channel.

## 21.3.54 RSCAN0TXQCCm — Transmit Queue Configuration and Control Register (m = 0 or 1)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|32-bit units|32-bit units|32-bit units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 03A0H+ (m *|||0010H)||||||||||||
|**Initial**|**value:**|0000 0000H|||||||||||||||
|Bit|31|30<br>29|28|27||26|25|24|23|22|21|20|19|18|17|16|
||—|—<br>—|—|—||—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0<br>0|0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R|R||R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14<br>13|12|11||10|9|8|7|6|5|4|3|2|1|0|
||—|—<br>TXQIM|TXQIE|||TXQDC[3:0]|||—|—|—|—|—|—|—|TXQE|
|Initial value|0|0<br>0|0|0||0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R/W|R/W|R/W||R/W|R/W|R/W|R|R|R|R|R|R|R|R/W|

**Table 21.73 RSCAN0TXQCCm register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 14|Reserved|These bits are always read as 0. The write value should always be 0.|
|13|TXQIM|Transmit Queue Interrupt Source Select|
|||0: When the buffer becomes empty upon completion of message|
|||transmission, a transmit queue interrupt request is generated.|
|||1: A transmit queue interrupt request is generated each time a message has|
|||been transmitted.|
|12|TXQIE|Transmit Queue Interrupt Enable|
|||0: Transmit queue interrupt is disabled.|
|||1: Transmit queue interrupt is enabled.|
|11 to 8|TXQDC[3:0]|Transmit Queue Depth Configuration|
|||Setting these bits to g (g = 2 to 15) makes the (g + 1)-buffer transmit queue|
|||available.|
|||Setting these bits to 0 disables the transmit queue.|
|||Setting these bits to 1 is prohibited.|
|7 to 1|Reserved|These bits are always read as 0. The write value should always be 0.|
|0|TXQE|Transmit Queue Enable|
|||0: The transmit queue is not used.|
|||1: The transmit queue is used.|

## TXQIM Bit

This bit is used to select a transmit queue interrupt source. Modify this bit in channel reset mode.

## TXQIE Bit

When the TXQIE bit is set to 1 and the source selected by the TXQIM bit occurs, an interrupt request is generated.

Set the TXQE bit to 0 before modifying the TXQIE bit.

## TXQDC[3:0] Bits

These bits are used to specify the number of transmit buffers to be allocated to the transmit queues. Transmit buffers are allocated to transmit queues in descending order of buffer number, that is, from (m  16 + 15) to (m  16 + 0). For examples of how buffer allocation is done, see Figure 21.9 . Modify these bits only in channel reset mode.

## TXQE Bit

Setting this bit to 1 makes the transmit queue available. Modify this bit in channel communication mode or channel halt mode. This bit is cleared to 0 in channel reset mode.

Before setting the TXQE bit to 1, set the TXQDC[3:0] bits to 0010B or more.

## 21.3.55 RSCAN0TXQSTSm — Transmit Queue Status Register (m = 0 or 1)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units|Can be read/written in 8-, 16-, and 32-bit units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 03C0H+ (m * 0004H)||||||||||||||
|**Initial**|**value:**|0000 0001H||||||||||||||
|Bit|31|30<br>29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—|—<br>—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0<br>0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14<br>13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—<br>—|—|—|—|—|—|—|—|—|—|—|TXQIF|TXQFLL|TXQEM<br>P|
|Initial value|0|0<br>0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W|R|R<br>R|R|R|R|R|R|R|R|R|R|R|R/W*1|R|R|

Note 1. The only effective value for writing to this flag bit is 0, which clears the bit. Otherwise writing to the bit results in retention of its state.

**Table 21.74 RSCAN0TXQSTSm register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 3|Reserved|The read value is undefined. The write value should always be 0.|
|2||TXQIF|Transmit Queue Interrupt Request Flag|
||||0: No transmit queue interrupt request is present.|
||||1: A transmit queue interrupt request is present.|
|1||TXQFLL|Transmit Queue Full Status Flag|
||||0: The transmit queue is not full.|
||||1: The transmit queue is full.|
|0||TXQEMP|Transmit Queue Empty Status Flag|
||||0: The transmit queue contains messages.|
||||1: The transmit queue contains no message (transmit queue empty).|

## TXQIF Flag

The TXQIF flag is set to 1 when the event specified by the TXQIM bit in the RSCAN0TXQCCm register has occurred.

The TXQIF flag is cleared to 0 in channel reset mode or by writing 0 to this flag. This flag is not cleared to 0 by setting the TXQE bit in the RSCAN0TXQCCm register to 0 (the transmit queue is not used).

## TXQFLL Flag

The TXQFLL flag is set to 1 when the number of messages set for the transmit queue matches the transmit queue depth set by the TXQDC[3:0] bits in the RSCAN0TXQCCm register.

This flag is cleared to 0 in any of the following cases.

- The number of messages set for the transmit queue is smaller than the transmit queue depth set by the TXQDC[3:0] bits.

- In channel reset mode

## TXQEMP Flag

The TXQEMP flag is cleared to 0 when even a single message is pending in the transmit queue.

This flag is set to 1 in any of the following cases.

- The TXQE bit is set to 0 (the transmit queue is not used).

- The transmit queue becomes empty.

- In channel reset mode

## 21.3.56 RSCAN0TXQPCTRm — Transmit Queue Pointer Control Register (m = 0 or 1)

|**Access:**|**Access:**|Can be written in 8-, 16-, and 32-bit units|Can be written in 8-, 16-, and 32-bit units|Can be written in 8-, 16-, and 32-bit units|Can be written in 8-, 16-, and 32-bit units|Can be written in 8-, 16-, and 32-bit units|Can be written in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 03E0H+ (m * 0004H)||||||||||||||||
|**Initial value:**||0000 0001H||||||||||||||||
|Bit|31||30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15||14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—||—|—|—|—|—|—|—||||TXQPC[7:0]|||||
|Initial value|0||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R||R|R|R|R|R|R|R|W|W|W|W|W|W|W|W|

## **Table 21.75 RSCAN0TXQPCTRm register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|Reserved|The write value should always be 0.|
|7 to 0|TXQPC[7:0]|Transmit Queue Pointer Control|
|||Writing FFHto these bits moves the write pointer of the transmit queue to the|
|||next queue buffer.|
|||Set Value: FFH|

## TXQPC[7:0] Bits

Writing FFH to the TXQPC[7:0] bits moves the write pointer to the next transmit queue buffer and generates a transmit request of the message. Write transmit messages to the RSCAN0TMIDp, RSCAN0TMPTRp, RSCAN0TMDF0p, and RSCAN0TMDF1p registers (p = 15 and 31) before writing FFH to the TXQPC[7:0] bits.

Write FFH only when the TXQE bit in the RSCAN0TXQCCm register is set to 1 (the transmit queue is used) and the TXQFLL flag in the RSCAN0TXQSTSm register is set to 0 (not full).

## 21.3.57 RSCAN0THLCCm — Transmit History Configuration and Control Register (m = 0 or 1)

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|32-bit units|32-bit units||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0400H+ (m * 0004H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|THLDTE|THLIM|THLIE|—|—|—|—|—|—|—|THLE|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R/W|R/W|R/W|R|R|R|R|R|R|R|R/W|

**Table 21.76 RSCAN0THLCCm register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 11|Reserved|These bits are always read as 0. The write value should always be 0.|
|10|THLDTE|Transmit History Target Buffer Select|
|||0: Entry from transmit/receive FIFO buffers and transmit queue|
|||1: Entry from transmit buffers, transmit/receive FIFO buffers, and transmit|
|||queue|
|9|THLIM|Transmit History Interrupt Source Select|
|||0: When 12 sets of data have been stored in the transmit history buffer|
|||1: When a single set of transmit history data has been stored|
|8|THLIE|Transmit History Interrupt Enable|
|||0: Transmit history interrupt is disabled.|
|||1: Transmit history interrupt is enabled.|
|7 to 1|Reserved|These bits are always read as 0. The write value should always be 0.|
|0|THLE|Transmit History Buffer Enable|
|||0: Transmit history buffer is not used.|
|||1: Transmit history buffer is used.|

## THLDTE Bit

When this bit is set to 0, the transmit history data of messages transmitted from transmit/receive FIFO buffers and the transmit queue is stored in the transmit history buffer. When this bit is set to 1, the transmit history data of messages transmitted from transmit buffers, transmit/receive FIFO buffers, and the transmit queue is stored in the transmit history buffer.

Modify this bit only in channel reset mode.

## THLIM Bit

This bit is used to select a transmit history interrupt source.

Modify this bit only in channel reset mode.

## THLIE Bit

When the THLIE bit is set to 1 and the source selected by the THLIM bit has occurred, a transmit history interrupt request is generated. Modify the THLIE bit only when the THLE bit set to 0.

## THLE Bit

Setting this bit to 1 makes the transmit history buffer available. When data transmission from the buffer selected by the THLDTE bit has been completed, the transmit history data of transmit messages is stored in the transmit history buffer.

Modify this bit in channel communication mode or channel halt mode.

## 21.3.58 RSCAN0THLSTSm — Transmit History Status Register (m = 0 or 1)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit|Can be read in 8-, 16-, and 32-bit|Can be read in 8-, 16-, and 32-bit|Can be read in 8-, 16-, and 32-bit|units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0420H+ (m *||||0004H)|||||||||||
|**Initial value:**||0000 0001H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—||THLMC[4:0]||||—|—|—|—|THLIF|THLELT|THLFLL|THLEM<br>P|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R/W*1|R/W*1|R|R|

Note 1. The only effective value for writing to this flag bit is 0, which clears the bit. Otherwise writing to the bit results in retention of its state.

**Table 21.77 RSCAN0THLSTSm register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 13|Reserved|These bits are always read as 0. The write value should always be 0.|
|12 to 8|THLMC[4:0]|Transmit History Buffer Unread Data Counter|
|||These bits indicate the number of unread data sets stored in the transmit history|
|||buffer.|
|7 to 4|Reserved|These bits are always read as 0. The write value should always be 0.|
|3|THLIF|Transmit History Interrupt Request Flag|
|||0: No transmit history interrupt request is present.|
|||1: A transmit history interrupt request is present.|
|2|THLELT|Transmit History Buffer Overflow Flag|
|||0: Transmit history buffer overflow has not occurred.|
|||1: Transmit history buffer overflow has occurred.|
|1|THLFLL|Transmit history Buffer Full Status Flag|
|||0: Transmit history buffer is not full.|
|||1: Transmit history buffer is full.|
|0|THLEMP|Transmit History Buffer Empty Status Flag|
|||0: Transmit history buffer contains unread data.|
|||1: Transmit history buffer contains no unread data (buffer empty).|

## THLMC[4:0] Bits

These bits indicate the number of unread data sets stored in the transmit history buffer.

## THLIF Flag

The THLIF flag is set to 1 when the interrupt source specified with the THLIM bit in the RSCAN0THLCCm register occurs.

This flag is cleared to 0 in channel reset mode or by the program writing 0 to this flag.

## THLELT Flag

The THLELT flag is set to 1 when an attempt is made to store new transmit history data while the transmit history buffer is full. In this case, the new data is discarded. This flag becomes 0 in channel reset mode or by the program writing 0 to this flag.

## THLFLL Flag

The THLFLL flag is set to 1 when 16 data sets have been stored in the transmit history buffer, and is cleared to 0 when the number of data sets stored in the transmit history buffer has decreased to less than 16. This bit is also cleared to 0 in channel reset mode or when the THLE bit in the RSCAN0THLCCm register is set to 0 (transmit history buffer is not used).

## THLEMP Flag

The THLEMP flag is cleared to 0 when even a single set of transmit history data has been stored in the transmit history buffer.

This flag is set to 1 when all the data in the transmit history buffer has been read. This flag is also set to 1 in channel reset mode or when the THLE bit in the RSCAN0THLCCm register is set to 0 (transmit history buffer is not used).

## 21.3.59 RSCAN0THLACCm — Transmit History Access Register (m = 0 or 1)

|**Access:**|**Access:**|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|Can be read in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 1800H+ (m * 0004H)||||||||||||||
|**Initial**|**value:**|0000 0000H||||||||||||||
|Bit|31|30<br>29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—|—<br>—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0<br>0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14<br>13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||||TID[7:0]|||||—||BN[3:0]||||BT[2:0]||
|Initial value|0|0<br>0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R<br>R|R|R|R|R|R|R|R|R|R|R|R|R|R|

**Table 21.78 RSCAN0THLACCm register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 16|Reserved|These bits are always read as 0.|
|15 to 8|TID[7:0]|Label Data|
|||The label information of stored data can be read.|
|7|Reserved|This bit is always read as 0.|
|6 to 3|BN[3:0]|Buffer Number Data|
|||The buffer number of transmit source (transmit buffer, transmit/receive FIFO or|
|||transmit queue) can be read.|
|2 to 0|BT[2:0]|Buffer Type Data|
|||b2     b1    b0|
|||0    0    1: Transmit buffer|
|||0    1    0: Transmit FIFO buffer|
|||1    0    0: Transmit queue|

## TID[7:0] Bits

These bits indicate the label information of transmit history data stored in the transmit history buffer.

## BN[3:0] Bits

These bits indicate the transmit history data stored in the transmit history buffer.

## BT[2:0] Bits

These bits indicate the transmit history data stored in the transmit history buffer.

## 21.3.60 RSCAN0THLPCTRm — Transmit History Pointer Control Register (m = 0 or 1)

|**Access:**|**Access:**|Can be|written in 8-, 16-, and 32-bit units|written in 8-, 16-, and 32-bit units|written in 8-, 16-, and 32-bit units|written in 8-, 16-, and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 0440H+ (m * 0004H)|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—|—|—|—||||THLPC[7:0]|||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R|W|W|W|W|W|W|W|W|

## **Table 21.79 RSCAN0THLPCTRm register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|31 to 8|Reserved|The write value should always be 0.|
|7 to 0|THLPC[7:0]|Transmit History List Pointer Control|
|||Writing FFHto these bits moves the read pointer to the next unread data in the|
|||transmit history buffer.|
|||Set Value: FFH|

## THLPC[7:0] Bits

When the THLPC[7:0] bits are set to FFH, the read pointer moves to the next data in the transmit history buffer. At this time, the THLMC[4:0] (transmit history buffer unread data counter) value in the RSCAN0THLSTSm register is decremented. Write FFH to the THLPC[7:0] bits after reading from the RSCAN0THLACCm register.

Write FFH only when the THLE bit in the RSCAN0THLCCm register is set to 1 (transmit history buffer is used) and the THLEMP flag in the RSCAN0THLSTSm register is 0.

## 21.3.61 RSCAN0GTSTCFG — Global Test Configuration Register

|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|**Access:**<br>Can be read/written in 8-, 16-, and 32-bit units<br>**Address:**<br><RSCAN0_base> + 0468H<br>**Initial value:**<br>0000 0000H<br>Bit<br>31<br>30<br>29<br>28<br>27<br>26<br>25<br>24<br>23<br>22<br>21<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>Bit<br>15<br>14<br>13<br>12<br>11<br>10<br>9<br>8<br>7<br>6<br>5<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>—<br>Initial value<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|20<br>19<br>18<br>17<br>16|20<br>19<br>18<br>17<br>16|20<br>19<br>18<br>17<br>16|20<br>19<br>18<br>17<br>16|20<br>19<br>18<br>17<br>16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|||||||||||||0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>4<br>3<br>2<br>1<br>0|||||
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|C1ICBC<br>E|C0ICBC<br>E|
|||||||||||||0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R/W<br>R/W|||||

## **Table 21.80 RSCAN0GTSTCFG register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 2|Reserved|These bits are always read as 0. The write value should always be 0.|
|1||C1ICBCE|CAN1 Inter-Channel Communication Test Enable|
||||0: CAN1 inter-channel communication test is disabled.|
||||1: CAN1 inter-channel communication test is enabled.|
|0||C0ICBCE|CAN0 Inter-Channel Communication Test Enable|
||||0: CAN0 inter-channel communication test is disabled.|
||||1: CAN0 inter-channel communication test is enabled.|

Modify the RSCAN0GTSTCFG register only in global test mode.

## C1ICBCE Bit

Setting this bit to 1 enables the channel 1 inter-channel communication test.

## C0ICBCE Bit

Setting this bit to 1 enables the channel 0 inter-channel communication test.

## 21.3.62 RSCAN0GTSTCTR — Global Test Control Register

|**Access:**|**Access:**|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|Can be read/written in 8-, 16-, and|32-bit units|32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 046CH|||||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||||
|Bit|31|30|29|28|27||26||25|24|23|22|21|20|19|18|17|16|
||—|—|—|—|—||—||—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0||0||0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R||R||R|R|R|R|R|R|R|R|R|R|
|Bit|15|14|13|12|11||10||9|8|7|6|5|4|3|2|1|0|
||—|—|—|—|—||—||—|—|—|—|—|—|—|—|—|ICBCTM|
|||||||||||||||||||E|
|Initial value|0|0|0|0|0||0||0|0|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R||R||R|R|R|R|R|R|R|R|R|R/W|

## **Table 21.81 RSCAN0GTSTCTR register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 1|Reserved|These bits are always read as 0. The write value should always be 0.|
|0||ICBCTME|Communication Test between Channels Enable|
||||0: Communication test between channels disabled|
||||1: Communication test between channels enabled|

## ICBCTME Bit

When this bit is set to 1, a communication test is enabled between the channels for which the CmICBCE bit (m = 0 or 1) in the RSCAN0GTSTCFG register has been set to 1. Modify the ICBCTME bit only in global test mode.

## 21.3.63 RSCAN0GLOCKK — Global Lock Key Register

|**Access:**|**Access:**|Can be written in 16- and 32-bit units|Can be written in 16- and 32-bit units|Can be written in 16- and 32-bit units|Can be written in 16- and 32-bit units|Can be written in 16- and 32-bit units|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Address:**||<RSCAN0_base> + 047CH|||||||||||||||
|**Initial value:**||0000 0000H|||||||||||||||
|Bit|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
||—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|—|
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|
|Bit|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||LOCK[15:0]|||||||||
|Initial value|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|W*1|

Note 1. Writing to these bits is effective only when the RS-CAN module is in global test mode.

**Table 21.82 RSCAN0GLOCKK register contents**

|**Bit**|**Position**|**Bit Name**|**Function**|
|---|---|---|---|
|31|to 16|Reserved|When read, an undefined value is returned. The write value should be 0.|
|15|to 0|LOCK[15:0]|Lock Key|
||||These bits are key bits to release protection of test mode.|

The RSCAN0GLOCKK register releases protection of special test bits and is write-only.

## LOCK[15:0] Bits

Writing the protection release data to the LOCK[15:0] bits in succession enables writing 1 to the RTME bit in the RSCAN0GTSTCTR register.

After the protection has been released, writing to the I/O register area (<RSCAN0_base> + 0000H to <RSCAN0_base> + 04FFH) of the CAN (except the RAM) enables the protection again.

Reading from the I/O register area of the CAN or reading from/wring to other areas does not enable the protection.

## 21.4 Interrupt Sources

The RS-CAN module has 8 interrupts that are grouped into global interrupts and channel interrupts.

Global interrupts [2 sources: common among channels]:

- Receive FIFO interrupt [1 source: common among channels]

- Global error interrupt [1 source: common among channels]

Channel interrupts [6 sources: 3 sources  number of channels]:

- CANm transmit interrupt [1 source for each channel]

   - CANm transmit complete interrupt

   - CANm transmit abort interrupt

   - CANm transmit/receive FIFO transmit complete interrupt (in transmit mode, gateway mode)

   - CANm transmit history interrupt

   - CANm transmit queue Interrupt

- CANm transmit/receive FIFO receive complete interrupt (in transmit mode, gateway mode) [1 source for each channel]

- CANm error interrupt [1 source for each channel]

   - (m = 0 or 1)

When an interrupt request is generated, the corresponding interrupt request flag is set to 1 (interrupt request present). In that case, when the interrupt enable bit is set to 1 (enabling interrupts), an interrupt request is output from the RS-CAN module. (Generation of interrupts also depends on the interrupt control register settings of the interrupt controller.)

Setting the interrupt request flag to 0 (no interrupt request present) or setting the interrupt enable bit to 0 (disabling interrupts) clears the current interrupt request. The current interrupt request is still output until the interrupt request flag is cleared.

Table 21.83 lists the CAN interrupt sources. Figure 21.2 shows the CAN global interrupt block diagram. Figure 21.3 shows the CAN channel interrupt block diagram.

**Table 21.83 List of CAN Interrupt Sources**

||**Interrupt Source**<br>**Corresponding Interrupt Request Flag**<br>**Corresponding Interrupt Enable Bit**|**Interrupt Source**<br>**Corresponding Interrupt Request Flag**<br>**Corresponding Interrupt Enable Bit**|
|---|---|---|
|Global<br>interrupts|Receive<br>FIFO|Receive FIFO 0<br>RFIF in the RSCAN0RFSTS0 register<br>RFIE in the RSCAN0RFCC0 register|
|||Receive FIFO 1<br>RFIF in the RSCAN0RFSTS1 register<br>RFIE in the RSCAN0RFCC1 register|
|||Receive FIFO 2<br>RFIF in the RSCAN0RFSTS2 register<br>RFIE in the RSCAN0RFCC2 register|
|||Receive FIFO 3<br>RFIF in the RSCAN0RFSTS3 register<br>RFIE in the RSCAN0RFCC3 register|
|||Receive FIFO 4<br>RFIF in the RSCAN0RFSTS4 register<br>RFIE in the RSCAN0RFCC4 register|
|||Receive FIFO 5<br>RFIF in the RSCAN0RFSTS5 register<br>RFIE in the RSCAN0RFCC5 register|
|||Receive FIFO 6<br>RFIF in the RSCAN0RFSTS6 register<br>RFIE in the RSCAN0RFCC6 register|
|||Receive FIFO 7<br>RFIF in the RSCAN0RFSTS7 register<br>RFIE in the RSCAN0RFCC7 register|
||Global error|<br>DEF in the RSCAN0GERFL register<br><br>MES in the RSCAN0GERFL register<br><br>THLES in the RSCAN0GERFL register<br><br>DEIE in the RSCAN0GCTR register<br><br>MEIE in the RSCAN0GCTR register<br><br>THLEIE in the RSCAN0GCTR register|
|Channel<br>interrupts<br>(m = 0 or 1)|CANm<br>transmit|CANm transmit<br>complete<br>TMTRF[1:0] in the RSCAN0TMSTSp register<br>TMIE in the RSCAN0TMIECy register|
|||CANm transmit abort<br>TMTRF[1:0] in the RSCAN0TMSTSp register<br>TAIE in the RSCAN0CmCTR register|
|||CANm transmit/receive<br>FIFO transmit<br>CFTXIF in the RSCAN0CFSTSk register<br>CFTXIE in the RSCAN0CFCCk register|
|||CANm transmit queue<br>TXQIF in the RSCAN0TXQSTSm register<br>TXQIE in the RSCAN0TXQCCm register|
|||CANm transmit history<br>THLIF in the RSCAN0THLSTSm register<br>THLIE in the RSCAN0THLCCm register|
||CANm transmit/receive FIFO receive<br>CFRXIF in the RSCAN0CFSTSk register<br>CFRXIE in the RSCAN0CFCCk register||
||CANm error<br><br>BEF in the RSCAN0CmERFL register<br><br>ALF in the RSCAN0CmERFL register<br><br>BLF in the RSCAN0CmERFL register<br><br>OVLF in the RSCAN0CmERFL register<br><br>BORF in the RSCAN0CmERFL register<br><br>BOEF in the RSCAN0CmERFL register<br><br>EPF in the RSCAN0CmERFL register<br><br>EWF in the RSCAN0CmERFL register<br><br>BEIE in the RSCAN0CmCTR register<br><br>ALIE in the RSCAN0CmCTR register<br><br>BLIE in the RSCAN0CmCTR register<br><br>OLIE in the RSCAN0CmCTR register<br><br>BORIE in the RSCAN0CmCTR register<br><br>BOEIE in the RSCAN0CmCTR register<br><br>EPIE in the RSCAN0CmCTR register<br><br>EWIE in the RSCAN0CmCTR register||

**==> picture [376 x 194] intentionally omitted <==**

**----- Start of picture text -----**<br>
RSCAN0RFSTS0.RFIF<br>Receive FIFO interrupt request<br>RSCAN0RFCC0.RFIE<br>RSCAN0RFSTSx.RFIF<br>RSCAN0RFCCx.RFIE<br>RSCAN0GERFL.DEF<br>RSCAN0GCTR.DEIE Global error interrupt request<br>RSCAN0CFSTS0.CFMLT<br>RSCAN0GERFL.MES<br>RSCAN0CFSTSk.CFMLT<br>RSCAN0RFSTS0.RFMLT RSCAN0GCTR.MEIE<br>RSCAN0RFSTSx.RFMLT<br>RSCAN0THLSTS0.THLELT RSCAN0GERFL.THLES<br>RSCAN0THLSTSm.THLELT RSCAN0GCTR.THLEIE<br>**----- End of picture text -----**<br>

**Figure 21.2 CAN Global Interrupt Block Diagram**

**==> picture [374 x 357] intentionally omitted <==**

**----- Start of picture text -----**<br>
RSCAN0TMIECy.TMIEp<br>CANm channel transmit interrupt<br>RSCAN0TMSTSp.TMTRF0<br>RSCAN0TMSTSp.TMTRF1<br>RSCAN0CmCTR.TAIE<br>RSCAN0TXQSTSm.TXQIF<br>RSCAN0TXQCCm.TXQIE<br>RSCAN0THLSTSm.THLIF<br>RSCAN0THLCCm.THLIE<br>RSCAN0CFSTS0.CFTXIF<br>RSCAN0CFCC0.CFTXIE<br>RSCAN0CFSTSk.CFTXIF<br>RSCAN0CFCCk.CFTXIE<br>RSCAN0CFSTS0.CFRXIF<br>CANm transmit/receive FIFO buffer receive interrupt<br>RSCAN0CFCC0.CFRXIE<br>RSCAN0CFSTSk.CFRXIF<br>RSCAN0CFCCk.CFRXIE<br>RSCAN0CmERFL.BEF<br>RSCAN0CmCTR.BEIE<br>CANm channel error interrupt<br>RSCAN0CmERFL.EWF<br>RSCAN0CmCTR.EWIE<br>RSCAN0CmERFL.EPF<br>RSCAN0CmCTR.EPIE<br>RSCAN0CmERFL.BOEF<br>RSCAN0CmCTR.BOEIE<br>RSCAN0CmERFL.BORF<br>RSCAN0CmCTR.BORIE<br>RSCAN0CmERFL.OVLF<br>RSCAN0CmCTR.OLIE<br>RSCAN0CmERFL.BLF<br>RSCAN0CmCTR.BLIE<br>RSCAN0CmERFL.ALF<br>RSCAN0CmCTR.ALIE<br>**----- End of picture text -----**<br>

**Figure 21.3 CAN Channel Interrupt Block Diagram**

## 21.5 RSCAN Modes

The RS-CAN module has four global modes to control the entire RS-CAN module status and four channel modes to control individual channel status. Details of global modes are described in Section 21.5.1, Global Modes , and details of channel modes are described in Section 21.5.2, Channel Modes .

- Global stop mode: Stops the clocks of the entire module to achieve low power consumption.

- Global reset mode: Performs initial settings for the entire module.

- Global test mode: Performs test settings.

- Global operating mode: Makes the entire module operable.

- Channel stop mode: Stops the channel clock.

- Channel reset mode: Performs initial settings for the channels.

- Channel halt mode: Stops CAN communication and allows channel testing.

- Channel communication mode: Performs CAN communication.

## 21.5.1 Global Modes

Figure 21.4 shows the transitions of global modes.

**==> picture [413 x 181] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI reset<br>GSLPR = 0 GMDC[1:0] = 00B<br>Global operating<br>Global stop mode Global reset mode<br>mode<br>GSLPR = 1  GMDC[1:0] = 01B<br>Global test mode<br>GMDC[1:0] = 10B<br>GMDC[1:0] = 01B<br>GMDC[1:0] = 10 GMDC[1:0] = 00<br>B B<br>**----- End of picture text -----**<br>

**==> picture [191 x 10] intentionally omitted <==**

**----- Start of picture text -----**<br>
Figure 21.4 Transitions of Global Modes<br>**----- End of picture text -----**<br>

In some cases, global mode transitions also force channel mode transitions. Table 21.84 shows the channel mode transitions depending on the global mode setting dictated by the GMDC[1:0] bits and the GSLPR bit.

**Table 21.84 Transitions of Channel Modes Depending on Global Mode Setting (GMDC[1:0] and GSLPR Bits)**

|**Channel Mode**<br>**before Setting**|**Channel Mode after Setting**|
|---|---|
||**GMDC[1:0] = 00B**<br>**GSLPR = 0**<br>**(Global Operation)**<br>**GMDC[1:0] = 10B**<br>**GSLPR = 0**<br>**(Global Test)**<br>**GMDC[1:0] = 01B**<br>**GSLPR = 0**<br>**(Global Reset)**<br>**GMDC[1:0] = 01B**<br>**GSLPR = 1**<br>**(Global Stop)**|
|Channel<br>communication|Channel communication<br>Channel halt<br>Channel reset<br>Transition prohibited|
|Channel halt|Channel halt<br>Channel halt<br>Channel reset<br>Transition prohibited|
|Channel reset|Channel reset<br>Channel reset<br>Channel reset<br>Channel stop|
|Channel stop|Channel stop<br>Channel stop<br>Channel stop<br>Channel stop|

Note: GMDC[1:0], GSLPR: Bits in the RSCAN0GCTR register

Table 21.85 shows the global mode transition time.

**Table 21.85 Global Mode Transition Time**

|**Mode before Transition**|**Mode after Transition**||**Maximum Transition Time**|
|---|---|---|---|
|Global stop|Global reset|Three pclk cycles||
|Global reset|Global stop|Three pclk cycles||
|Global reset|Global test|Ten pclk cycles||
|Global reset|Global operating|Ten pclk cycles||
|Global test|Global reset|Three pclk cycles||
|Global test|Global operating|Three pclk cycles||
|Global operating|Global reset|Three pclk cycles||
|Global operating|Global test|Two CAN frames*1||

Note 1. CAN frame time of the lowest communication speed of the channels in use

## 21.5.1.1 Global Stop Mode

In global stop mode, clocks of the CAN do not run and therefore power consumption is reduced. CAN registers can be read, but writing data to them is prohibited. Register values are retained. Only the clock used by the CPU for writing to the GSLPR bit runs in this mode.

After this LSI is reset, the CAN module transitions to global stop mode. Setting the GSLPR bit in the RSCAN0GCTR register to 1 (in global stop mode) in global reset mode sets the CSLPR bit in each of the RSCAN0CmCTR register to 1 (channel stop mode). If all channels are forced to transition to channel stop mode, the CAN module transitions to global stop mode. The GSLPR bit should not be modified in global operating mode or global test mode.

## 21.5.1.2 Global Reset Mode

In global reset mode, RS-CAN module settings are performed. When the RS-CAN module transitions to global reset mode, some registers are initialized. Table 21.88 and Table 21.89 list the registers to be initialized.

Setting the GMDC[1:0] bits in the RSCAN0GCTR register to 01B sets the CHMDC[1:0] bits in each of the RSCAN0CmCTR registers (m = 0 or 1) to 01B (channel reset mode). If all channels are forced to transition to channel reset mode, the CAN module transitions to global reset mode. Channels that are already in channel reset mode or channel stop mode do not transition (because the CHMDC[1:0] bits have already been set to 01B).

## 21.5.1.3 Global Test Mode

In global test mode, settings for test-related registers are performed. When the CAN module transitions to global test mode, all CAN communications are disabled.

Setting the GMDC[1:0] bits in the RSCAN0GCTR register to 10B sets the CHMDC[1:0] bits in each of the RSCAN0CmCTR register to 10B (channel halt mode). If all channels are forced to transition to channel halt mode, the CAN module transitions to global test mode. Channels that are in channel stop mode, channel reset mode, or channel halt mode do not transition.

## 21.5.1.4 Global Operating Mode

The RS-CAN module operates in global operating mode.

When the GMDC[1:0] bits in the RSCAN0GCTR register are set to 00B, the RS-CAN module transitions to global operating mode.

## 21.5.2 Channel Modes

Figure 21.5 shows a channel mode state transition chart. Table 21.86 shows the channel mode transition time.

**==> picture [388 x 346] intentionally omitted <==**

**----- Start of picture text -----**<br>
This LSI reset<br>Channel stop mode<br>CSLPR = 0 CSLPR = 1<br>CHMDC[1:0] = 10B<br>Channel reset mode Channel halt mode<br>CHMDC[1:0] = 01B<br>CHMDC[1:0] = 00B CHMDC[1:0] = 01B CHMDC[1:0] = 00B CHMDC[1:0] = 10B<br>* [2]<br>Channel communication mode<br>Reception Transmission<br>BOSTS = 0 Arbitration lost BOSTS = 0<br>TRMSTS = 0 TRMSTS = 1 * [1]<br>RECSTS = 1 RECSTS = 0<br>COMSTS = 1 COMSTS = 1<br>11 consecutive recessive<br>SOF<br>bits have been detected<br>detected<br>128 times (BOM[1:0] bits<br>Reception  are set<br>completed to 00B) and transmission<br>TEC > 255 start<br>Idle Bus off<br>BOSTS = 0 BOSTS = 1<br>TRMSTS = 0 TRMSTS = 1<br>RECSTS = 0 11 consecutive recessive bits  RECSTS = 0<br>COMSTS = 1 have been detected 128 times  COMSTS =1<br>(BOM[1:0] bits are set to 00B)<br>Transmission start<br>Transmission completed<br>**----- End of picture text -----**<br>

CHMDC[1:0], CSLPR, BOM[1:0]: Bits in the RSCAN0CmCTR register (m = 0 or 1) BOSTS, TRMSTS, RECSTS, COMSTS: Bits in the RSCAN0CmSTS register

## Note 1. Timing of transition from bus off state to channel halt mode

- When BOM[1:0] = 01B: Transition to channel halt mode when TEC exceeds 255

- When BOM[1:0] = 10B: Transition to channel halt mode when 11 consecutive recessive bits have been detected 128 times

- When BOM[1:0] = 11B: Transition to channel halt mode when the CHMDC[1:0] bits are set to 10B

Note 2. While the CAN bus is locked at the dominant level, transition to channel halt mode is not made. In that case, enter channel reset mode.

## **Figure 21.5 Channel Mode State Transition Chart**

**Table 21.86 Channel Mode Transition Time**

|**Mode before Transition**|**Mode after Transition**|**Maximum Transition Time**|
|---|---|---|
|Channel stop|Channel reset|Three pclk cycles|
|Channel reset|Channel stop|Three pclk cycles|
|Channel reset|Channel halt|Three CANm bit times|
|Channel reset|Channel communication|Two CANm bit times|
|Channel halt|Channel reset|Three pclk cycles|
|Channel halt|Channel communication|Three CANm bit times|
|Channel communication|Channel reset|Three pclk cycles|
|Channel communication|Channel halt|Two CANm frames|

## 21.5.2.1 Channel Stop Mode

In channel stop mode, clocks are not supplied to channels and therefore power consumption is reduced. CAN registers can be read, but writing data to them is prohibited. Register values are retained.

Each channel enters channel stop mode after this LSI is reset. Channels also transition to channel stop mode when the CSLPR bit in the RSCAN0CmCTR register (m = 0 or 1) is set to 1 (channel stop mode) in channel reset mode. The CSLPR bit should not be modified in channel communication mode and channel halt mode.

## 21.5.2.2 Channel Reset Mode

In channel reset mode, channel settings are performed. When a channel transitions to channel reset mode, some channel-related registers are initialized. Table 21.88 lists the registers to be initialized.

When the CHMDC[1:0] bits in the RSCAN0CmCTR register are set to 01B (channel reset mode) during CAN communication, communication is terminated before it is completed and the channel transitions to channel reset mode. Table 21.87 shows the operation when the CHMDC[1:0] bits are set to 01B (channel reset mode) during CAN communication.

## 21.5.2.3 Channel Halt Mode

In channel halt mode, settings for test-related registers of channels are performed. When a channel transitions to channel halt mode, CAN communication of the channel stops.

Table 21.87 shows operation when the CHMDC[1:0] bits are set to 10B (channel halt mode) during CAN communication.

**Table 21.87 Operation a Channel Transitions to Channel Reset Mode/Channel Halt Mode**

|**Mode**|**During Reception**|**During Transmission**|**Bus Off State**|
|---|---|---|---|
|Channel reset|Transitions to channel reset|Transitions to channel reset|Transitions to channel reset mode before|
|(CHMDC[1:0] = 01B)|mode before reception is|mode before transmission is|bus off recovery.|
||completed.<asterisk>*<Super_|completed.<asterisk>*<Super_||
||A>1|A>1||
|Channel|Transitions to channel halt|Transitions to channel halt|[When BOM[1:0] = 00B]|
|halt<asterisk>*<Super|mode after reception is|mode after transmission is|Transitions to channel halt mode|
|_A>3|completed.<asterisk>*<Super_|completed.|(CHMDC[1:0] = 10B) only after bus off|
|(CHMDC[1:0] = 10B)|A>2||recovery.|
||||[When BOM[1:0] = 01B]|
||||Transitions to channel halt mode|
||||automatically when the condition for|
||||transition to bus off state is met.|
||||[When BOM[1:0] = 10B]|
||||Transitions to channel halt mode|
||||automatically after bus off recovery.|
||||[When BOM[1:0] = 11B]|
||||Transitions to channel halt mode|
||||immediately after the CHMDC[1:0] bits|
||||are set to 10Bbefore bus off recovery.|

Note 1. To allow transition to channel reset mode after communication is completed, set the CHMDC[1:0] bits to 10B and confirm that communication has been completed and transition to channel halt mode has been made, and then set the CHMDC[1:0] bits to 01B.

Note 2. While the CAN bus is locked at the dominant level, transition to channel halt mode is not made. In that case, enter channel reset mode. The CAN bus status can be confirmed with the BLF flag of the RSCAN0CmERFL register that becomes 1 when dominant lock is detected.

Note 3. When the transition from channel reset mode to channel wait mode is to be made, set the RSCAN0CmCFG register in channel reset mode and then shift to channel wait mode.

## 21.5.2.4 Channel Communication Mode

In channel communication mode, CAN communication is performed. Each channel has the following communication states during CAN communication.

 Idle : Neither reception nor transmission is in progress.  Reception : Receiving a message sent from another node.  Transmission : Transmitting a message.  Bus off : Isolated from CAN communication.

When the CHMDC[1:0] bits in the RSCAN0CmCTR register are set to 00B, the channel transitions to channel communication mode. After that, once 11 consecutive recessive bits have been detected, the COMSTS flag in the RSCAN0CmSTS register (m = 0 or 1) is set to 1 (communication is ready) and transmission and reception are enabled on the CAN network as an active node. At this time, transmission and reception of messages can be started.

## 21.5.2.5 Bus Off State

A channel transitions to the bus off state according to the transmit/receive error counter increment/ decrement rules of the CAN specifications.

The conditions for returning from the bus off state are determined by the BOM[1:0] bits in the RSCAN0CmCTR register.

- When BOM[1:0] = 00B:

   - Bus off recovery is compliant with the CAN specifications. After 11 consecutive recessive bits have been detected 128 times, a channel returns from the bus off state to the CAN communication ready state (error active state). At that time, the TEC[7:0] and REC[7:0] bits in the RSCAN0CmSTS register are initialized to 00H and the BORF flag in the RSCAN0CmERFL register is set to 1 (bus off recovery is detected). When the CHMDC[1:0] bits in the RSCAN0CmCTR register are set to B'10 (channel halt mode) in the bus off state, the channel transitions to channel halt mode after bus off recovery has been completed (11 consecutive recessive bits have been detected 128 times).

- When BOM[1:0] = 01B: When a channel transitions to the bus off state, the CHMDC[1:0] bits are set to 10B and the channel transitions to channel halt mode. At that time, the TEC[7:0] and REC[7:0] bits are initialized to 00H but the BORF flag is not set to 1.

- When BOM[1:0] = 10B: When a channel has transitioned to the bus off state, the CHMDC[1:0] bits are set to 10B. After bus off recovery has been completed (11 consecutive recessive bits have been detected 128 times), the channel transitions to channel halt mode. At that time, the TEC[7:0] and REC[7:0] bits are initialized to 00H and the BORF flag is set to 1.

- When BOM[1:0] = 11B:

   - When the CHMDC[1:0] bits are set to 10B in the bus off state, the channel transitions to channel halt mode before bus off recovery is completed. At that time, the TEC[7:0] and REC[7:0] bits are initialized to 00H but the BORF flag is not set to 1.

However, the BORF flag becomes 1 if a CAN module transitions to error active state (by detecting 128 times of 11 consecutive recessive bits) before CHMDC[1:0] bits are set to 10B.

If the RS-CAN module causes the channel to transition to channel halt mode simultaneously with a program write to the CHMDC[1:0] bits, the program write takes precedence. An automatic transition to channel halt mode when the BOM[1:0] bits are set to 01B or 10B is made only when the CHMDC[1:0] bits are 00B (channel communication mode). Furthermore, setting the RTBO bit in the RSCAN0CmCTR register to 1 allows a forced return from the bus off state. As soon as the RTBO bit is set to 1, the state changes to the error active state. After 11 consecutive recessive bits have been detected, the CAN module becomes ready for communication. In this case, the BORF flag is not set to 1 and the TEC[7:0] and REC[7:0] bits are initialized to 00H. Write 1 to the RTBO bit only when the BOM[1:0] value is 00B.

**Table 21.88 Registers Initialized in Global Reset Mode or Channel Reset Mode**

|**Register**|**Bit / Flag**|
|---|---|
|RSCAN0CmCTR register|CTMS[1:0], CTME, CHMDC[1:0]|
|RSCAN0CmSTS register|CHLTSTS, EPSTS, BOSTS, TRMSTS, RECSTS, COMSTS, REC[7:0], TEC[7:0]|
|RSCAN0CmERFL register|CRCREG[14:0], ADERR, B0ERR, B1ERR, CERR, AERR, FERR, SERR, ALF, BLF,|
||OVLF, BORF, BOEF, EPF, EWF, BEF|
|RSCAN0CFCCk register|When transmit/receive FIFO buffer is in transmit mode or gateway mode: CFE|
|RSCAN0CFSTSk register|When transmit/receive FIFO buffer is in transmit mode or gateway mode: CFMC[7:0],|
||CFFLL, CFEMP, CFMLT, CFRXIF, CFTXIF|
|RSCAN0CFTISTS register|CFkTXIF|
|RSCAN0TMCp register|TMOM, TMTAR, TMTR|
|RSCAN0TMSTSp register|TMTARM, TMTRM, TMTRF[1:0], TMTSTS|
|RSCAN0TMTRSTSy register|TMTRSTSp (Bits of corresponding channel are initialized in channel reset mode.)|
|RSCAN0TMTARSTSy register|TMTARSTSp (Bits of corresponding channel are initialized in channel reset mode.)|
|RSCAN0TMTCSTSy register|TMTCSTSp (Bits of corresponding channel are initialized in channel reset mode.)|
|RSCAN0TMTASTSy register|TMTASTSp (Bits of corresponding channel are initialized in channel reset mode.)|
|RSCAN0TXQCCm register|TXQE|
|RSCAN0TXQSTSm register|TXQIF, TXQFLL, TXQEMP|
|RSCAN0THLCCm register|THLE|
|RSCAN0THLSTSm register|THLMC[4:0], THLIF, THLELT, THLFLL, THLEMP|
|RSCAN0GTINTSTS0 register|TSIFm, TAIFm, TQIFm, CFTIFm, THIFm (m = 0 or 1)|

**Table 21.89 Registers Initialized Only in Global Reset Mode**

|**Register**|**Bit / Flag**|
|---|---|
|RSCAN0GSTS register|GHLTSTS|
|RSCAN0GERFL register|THLES, MES, DEF|
|RSCAN0GTSC register|TS[15:0]|
|RSCAN0RMNDy register|RMNSq|
|RSCAN0RFCCx register|RFE|
|RSCAN0RFSTSx register|RFMC[7:0], RFIF, RFMLT, RFFLL, RFEMP|
|RSCAN0CFCCk register|When transmit/receive FIFO buffer is in receive mode: CFE|
|RSCAN0CFSTSk register|When transmit/receive FIFO buffer is in receive mode: CFMC[7:0], CFFLL, CFEMP,|
||CFTXIF, CFRXIF, CFMLT|
|RSCAN0FESTS register|CFkEMP, RFxEMP|
|RSCAN0FFSTS register|CFkFLL, RFxFLL|
|RSCAN0FMSTS register|CFkMLT, RFxMLT|
|RSCAN0RFISTS register|RFxIF|
|RSCAN0CFRISTS register|CFkRXIF|
|RSCAN0GTSTCFG register|C0ICBCE, C1ICBCE|
|RSCAN0GTSTCTR register|ICBCTME|

## 21.6 Reception Function

There are two reception types.

- Reception by receive buffers: Zero to 31 receive buffers can be shared by all channels. Since messages stored in receive buffers are overwritten at each reception, the latest receive data can always be read.

- Reception by receive FIFO buffers and transmit/receive FIFO buffers (receive mode): Eight receive FIFO buffers can be shared by all channels and three dedicated transmit/receive FIFO buffers are provided for each channel. Messages of up to the number of buffer stages specified with the RFDC[2:0] and CFDC[2:0] bits can be stored in FIFO buffers and can be read sequentially from the oldest.

## 21.6.1 Data Processing Using the Receive Rule Table

Data processing using the receive rule table allows dispatching of selected messages to the specified buffer. Data processing includes acceptance filter processing, DLC filter processing, routing processing, label addition processing, and mirror function processing.

Up to 128 receive rules can be registered per channel and up to (64  number of channels) total receive rules can be registered in the entire module. (Up to 128 receive rules can be registered in this module that has two channels.) Set receive rules for each channel. Receive rules cannot be shared with other channels. If receive rules are not set, no messages can be received. Figure 21.6 illustrates how receive rules are registered.

**==> picture [464 x 273] intentionally omitted <==**

**----- Start of picture text -----**<br>
b8 b7 b6 b5 b4                                   b0<br>RSCAN0GAFLECTR register  DAEAFL AFLPN[4:0]<br>0 RSCAN0GAFLID0 to RSCAN0GAFLP10 registers Receive rule table<br>1 RSCAN0GAFLID1 to RSCAN0GAFLP11 registers<br>2 RSCAN0GAFLID2 to RSCAN0GAFLP12 registers Receive rule 0<br>3 RSCAN0GAFLID3 to RSCAN0GAFLP13 registers Page 0<br>4 RSCAN0GAFLID4 to RSCAN0GAFLP14 registers<br>56 RSCAN0GAFLID5 to RSCAN0GAFLP15 reRSCAN0GAFLID6 to RSCAN0GAFLP16 registersgisters •• Page 1 Channel 0 receive rules 0 to 60<br>7 RSCAN0GAFLID7 to RSCAN0GAFLP17 registers • 61 rules (RNC0[7:0] value)<br>8 RSCAN0GAFLID8 to RSCAN0GAFLP18 registers Page 2<br>9 RSCAN0GAFLID9 to RSCAN0GAFLP19 registers<br>10 RSCAN0GAFLID10 to RSCAN0GAFLP110 registers<br>11 RSCAN0GAFLID11 to RSCAN0GAFLP111 registers Page 3 Receive rule 60 Boundary is determined by<br>12 RSCAN0GAFLID12 to RSCAN0GAFLP112 registers Receive rule 0 the RNC0[7:0] bits.<br>1314 RSCAN0GAFLID13 to RSCAN0GAFLP113 reRSCAN0GAFLID14 to RSCAN0GAFLP114 reggistersisters Page 4<br>15 RSCAN0GAFLID15 to RSCAN0GAFLP115 registers Channel 1 receive rules 0 to 47<br>Page 5 48 rules (RNC1[7:0] value)<br>Page 6 Receive rule 47 Boundary is determined by<br>the RNC1[7:0] bits.<br>Page 7 Unused receive rule area<br>RNC0[7:0], RNC1[7:0]: Bits in the RSCAN0GAFLCFG0 register<br>Note: Receive rules for each channel are set in contiguous blocks.<br>It is not possible to configure channel 1 rules in the block reserved for channel 0 rules.<br>**----- End of picture text -----**<br>

**==> picture [293 x 10] intentionally omitted <==**

**----- Start of picture text -----**<br>
Figure 21.6 Entry of Receive Rules (for Setting Channel 0 and 1)<br>**----- End of picture text -----**<br>

Each receive rule consists of 16 bytes in the RSCAN0GAFLIDj, RSCAN0GAFLMj, RSCAN0GAFLP0j, and RSCAN0GAFLP1j registers (j = 0 to 15). The RSCAN0GAFLIDj register (j = 0 to 15) is used to set GAFLID, GAFLIDE bit, GAFLRTR bit, and the mirror function, the RSCAN0GAFLMj register is used to set mask, the RSCAN0GAFLP0j register is used to set label information to be added, DLC value, and storage receive buffer, and the RSCAN0GAFLP1j register is used to set storage FIFO buffer. Up to 16 receive rules can be set per page.

## 21.6.1.1 Acceptance Filter Processing

In the acceptance filter processing, the ID data, IDE bit, and RTR bit in a received message are compared with the ID data, IDE bit, and RTR bit set in the receive rule of the corresponding channel. When all these bits match, the message passes through the acceptance filter processing. The ID data, IDE bit, and RTR bit in the received message which correspond to the bits set to 0 (bits are not compared) in the RSCAN0GAFLMj register are not compared and are regarded as matched.

Check begins with the receive rule of the minimum number for the corresponding channel. When all the bits to be compared in a received message match the bits set in the receive rule or when all the receive rules are compared without any match, filter processing stops. If there is no matching receive rule, the received message is not stored in the receive buffer or FIFO buffer.

**==> picture [446 x 230] intentionally omitted <==**

**----- Start of picture text -----**<br>
Mask bit value<br>ID value in  0: Bits are not compared.<br>received  RSCAN0GAFLIDj RSCAN0GAFLMj  1: Bits are compared.<br>message (Receive rule ID register) (Receive rule mask register)<br>GAFL GAFL GAFL GAFL<br>GAFLID GAFLIDM<br>IDE RTR IDEM RTRM<br>Acceptance<br>determination<br>signal<br>j = 0 to 15 Acceptance determination signal<br>0: Does not pass the acceptance filter processing.<br>GAFLIDE, GAFLRTR, GAFLID: RSCAN0GAFLIDj register (Not stored in the buffer)<br>GAFLIDEM, GAFLRTRM, GAFLIDM: RSCAN0GAFLMj register 1: Passes the acceptance filter processing.<br>**----- End of picture text -----**<br>

**==> picture [186 x 10] intentionally omitted <==**

**----- Start of picture text -----**<br>
Figure 21.7 Acceptance Filter Function<br>**----- End of picture text -----**<br>

## 21.6.1.2 DLC Filter Processing

When the DCE bit in the RSCAN0GCFG register is set to 1 (DLC check is enabled), DLC filter processing is added to messages that passed through the acceptance filter processing. When the DLC value in a message is equal to or larger than the DLC value set in the receive rule, the message passes through the DLC filter processing.

When a message has passed through the DLC filter processing with the DRE bit in the RSCAN0GCFG register set to 0 (DLC replacement is disabled), the DLC value in the received message is stored in the buffer. In this case, all the data bytes in the received message are stored in the buffer.

When a message has passed through the DLC filter processing with the DRE bit in the RSCAN0GCFG register set to 1 (DLC replacement is enabled), the DLC value in the receive rule is stored in the buffer instead of the DLC value in the received message. In this case, a value of 00H is stored in each data byte beyond the number of bytes which is indicated by the DLC value in the receive rule.

When the DLC value in the received message is smaller than that in the receive rule, the message does not pass through the DLC filter processing. In this case, the message is not stored in the receive buffer or the FIFO buffer and the DEF flag in the RSCAN0GERFL register is set to 1 (a DLC error is present).

## 21.6.1.3 Routing Processing

Messages that passed through the acceptance filter processing and the DLC filter processing are stored in receive buffers, receive FIFO buffers, or transmit/receive FIFO buffers (set to receive mode or gateway mode). Message storage destination is set by the GAFLRMV and GAFLRMDP[6:0] bits in the RSCAN0GAFLP0j register (j = 0 to 15) and by the RSCAN0GAFLP1j register. Messages that passed through the acceptance filter processing and the DLC filter processing can be stored in up to eight buffers.

## 21.6.1.4 Label Addition Processing

It is possible to add 12-bit label information to messages that passed through the filter processing and store them in buffers. This label information is set in the GAFLPTR[11:0] bits in the RSCAN0GAFLP0j register.

## 21.6.1.5 Mirror Function Processing

The mirror function allows the CAN node to receive its own transmitted messages. The mirror function is made available by setting the MME bit in the RSCAN0GCFG register to 1 (mirror function is enabled).

When the mirror function is in use, receive rules for which the GAFLLB bit in the RSCAN0GAFLIDj register is set to 0 are used for data processing when receiving messages transmitted from other CAN nodes. When the CAN node is receiving its own transmitted messages, receive rules for which the GAFLLB bit is set to 1 are used for data processing.

## 21.6.1.6 Timestamp

The timestamp counter is a 16-bit free-running counter used for recording message receive time. The timestamp counter value is fetched at the start-of-frame (SOF) timing of a message and is then stored in a receive buffer or a FIFO buffer together with the message ID and data. Ether pclk or the CANm bit time clock (m = 0 or 1) may be selected as a timestamp counter clock source using the TSBTCS[2:0] and TSSS bits in the RSCAN0GCFG register. The timestamp counter count source is obtained by dividing the selected clock source by the TSP[3:0] value in the RSCAN0GCFG register.

When the CANm bit time clock is used as a clock source, the timestamp counter stops when the corresponding channel transitions to channel reset mode or channel halt mode. When the pclk is used as a clock source, the timestamp function is not affected by channel mode.

The timestamp counter value is reset to 0000H by setting the TSRST bit in the RSCAN0GCTR register to 1.

**==> picture [405 x 141] intentionally omitted <==**

**----- Start of picture text -----**<br>
TSSS bit TSP[3:0]<br>pclk 1/2 Divider Timestamp counter<br>(16 bits)<br>CAN0 bit time clock 000B<br>CAN1 bit time clock 001B<br>Bits TSBTCS[2:0]<br>TSBTCS[2:0], TSSS, TSP[3:0]: Bits in the RSCAN0GCFG register<br>Note: When specifying pclk/2 as the timestamp counter count source, set bits TSBTCS[2:0] to 000B.<br>**----- End of picture text -----**<br>

**Figure 21.8 Timestamp Function Block Diagram**

## 21.7 Transmission Functions

There are three types of transmission.

- Transmission using transmit buffers: Each channel has 16 buffers.

- Transmission using transmit/receive FIFO buffers (transmit mode): Each channel has three FIFO buffers. Up to 96 messages can be contained in a single FIFO buffer. Each FIFO buffer is used with a link to a transmit buffer. Only the message to be transmitted next in a FIFO buffer becomes the target of transmit priority determination. Messages are transmitted sequentially on a first-in, first-out basis.

- Transmission using transmit queues:

   - Up to 16 transmit buffers per channel can be allocated to the transmit queues. Transmit buffer ((16  m) + 15) is used as an access window of a corresponding channel. Transmit buffers are allocated to transmit queues in descending order of buffer number. All messages in transmit queues, which are targets of priority determination, are transmitted in the order of ID number.

Figure 21.9 shows the allocation of transmit queues and transmit/receive FIFO buffer link.

|Transmit buffer 0||Transmit buffer 0||Transmit/receive FIFO buffer 0||Transmit buffer 0|
|---|---|---|---|---|---|---|
|Transmit buffer 1||Transmit/receive FIFO buffer 0||Transmit buffer 1||Transmit buffer 1|
|Transmit buffer 2||Transmit buffer 2||Transmit buffer 2||Transmit buffer 2|
|Transmit buffer 3||Transmit/receive FIFO buffer 1||Transmit buffer 3||Transmit buffer 3|
|Transmit buffer 4||Transmit buffer 4||Transmit buffer 4||Transmit queue|
|Transmit buffer 5||Transmit buffer 5||Transmit/receive FIFO buffer 1||Transmit queue|
|Transmit buffer 6||Transmit buffer 6||Transmit buffer 6||Transmit queue|
|Transmit buffer 7||Transmit buffer 7||Transmit buffer 7||Transmit queue|
|Transmit buffer 8||Transmit buffer 8||Transmit buffer 8||Transmit queue|
|Transmit buffer 9||Transmit buffer 9||Transmit buffer 9||Transmit queue|
|Transmit buffer 10||Transmit buffer 10||Transmit buffer 10||Transmit queue|
|Transmit buffer 11||Transmit buffer 11||Transmit/receive FIFO buffer 2||Transmit queue|
|Transmit buffer 12||Transmit buffer 12||Transmit queue||Transmit queue|
|Transmit buffer 13||Transmit buffer 13||Transmit queue||Transmit queue|
|Transmit buffer 14||Transmit buffer 14||Transmit queue||Transmit queue|
|Transmit buffer 15||Transmit/receive FIFO buffer 2||Transmit queue||Transmit queue|
|Only transmit buffers are used<br>Transmit buffers and transmit/<br>receive FIFO buffers are used<br>(Transmit/receive FIFO<br>buffers are linked to transmit<br>buffers 1, 3, and 15)<br>Transmit buffers, transmit/<br>receive FIFO buffers, and a<br>transmit queue Is used<br>(Transmit/receive FIFO buffers<br>are linked to transmit buffers<br>0, 5, and 11; Four transmit<br>queue elements are allocated<br>to transmit buffers)<br>Transmit buffers and a<br>transmit queue is used (12<br>transmit queue elements<br>are allocated to transmit<br>buffers)|||||||

**Figure 21.9 Allocation of Transmit Queues and Transmit/Receive FIFO Buffer Links**

## 21.7.1 Transmit Priority Determination

If transmit requests are issued from multiple buffers or from the queue on the same channel, transmit priority is determined using one of the following methods.

The priority is determined by using one of the following methods.

- ID priority (TPRI bit = 0)

- Transmit buffer number priority (TPRI bit = 1)

All CAN channels use the setting of the TPRI bit in the RSCAN0GCFG register.

When the TPRI bit is set to 0, messages are transmitted according to the priority of stored message IDs. ID priority conforms to the CAN bus arbitration specification defined in the CAN specifications. All IDs of pending transmit messages are targets of priority determination, regardless of whether they are stored in transmit buffers, transmit/receive FIFO buffers (set to transmit mode or gateway mode), or the transmit queue. If even a single transmit queue is used, select ID priority. When transmit/receive FIFO buffers are used, the oldest message in a FIFO buffer becomes the target of priority determination. When a message is being transmitted from a transmit/receive FIFO buffer, the next message in the FIFO buffer becomes the target of priority determination. When a transmit queue is used, all messages in the transmit queue are targets of priority determination. If the same ID is set for two or more buffers, the buffer with the smaller buffer number takes precedence.

When the TPRI bit is set to 1, the message in the transmit buffer with the minimum buffer number among all buffers with a transmit request is transmitted first. When transmit/receive FIFO buffers are linked to transmit buffers, transmit priority is determined according to linked transmit buffer numbers.

When messages are retransmitted due to an arbitration-lost or an error, transmit priority determination is made again regardless of the TPRI bit.

## 21.7.2 Transmission Using Transmit Buffers

Setting the transmit request bit (TMTR bit in the RSCAN0TMCp register) in a transmit buffer to 1 (transmission is requested) allows transmission of data frames or remote frames.

The transmit result is shown by the TMTRF[1:0] flag in the corresponding RSCAN0TMSTSp register (p = 0 to 31). When transmit completes successfully, the TMTRF[1:0] flag is set to 10B (transmission has been completed (without transmit abort request)) or 11B (transmission has been completed (with transmit abort request)).

## 21.7.2.1 Transmit Abort Function

With respect to transmit buffers for which the TMTRM bit in the RSCAN0TMSTSp register is set to 1 (a transmit request is present), when the TMTAR bit in the RSCAN0TMCp register is set to 1 (transmit abort is requested), the transmit request is canceled. When transmit abort is completed, the TMTRF[1:0] flag in the RSCAN0TMSTSp register is set to 01B (transmit abort has been completed) and the transmit request is canceled (clearing the TMTRM bit to 0).

A message that is being transmitted or a message to be transmitted next according to the transmit priority determination cannot be aborted. However, when an arbitration-lost or an error occurs during transmission of a message for which the TMTAR bit is set to 1, retransmission is not performed.

## 21.7.2.2 One-Shot Transmission Function (Retransmission Disabling Function)

When the TMOM bit in the RSCAN0TMCp register is set to 1 (one-shot transmission is enabled), transmission is performed only once. Even if an arbitration-lost or an error occurs, retransmission is not performed.

The one-shot transmit result is shown by the TMTRF[1:0] flag in the corresponding RSCAN0TMSTSp register. When one-shot transmission completes successfully, the TMTRF[1:0] flag is set to 10B or 11B. When an arbitration-lost or an error occurs, the TMTRF[1:0] flag is set to 01B (transmit abort has been completed).

## 21.7.3 Transmission Using FIFO Buffers

Multiple messages can be stored in a single transmit/receive FIFO buffers, up to the number specified by the FIFO buffer depth, which is set by the CFDC[2:0] bits in the RSCAN0CFCCk register (k = 0 to 5). Messages are transmitted sequentially on a first-in, first-out basis.

Each transmit/receive FIFO buffer is linked to a transmit buffer selected by the CFTML[3:0] bits in the RSCAN0CFCCk register. When the CFE bit in the RSCAN0CFCCk register is set to 1 (transmit/ receive FIFO buffers are used), transmit/receive FIFO buffers become targets of transmit priority determination. Priority of only the next transmit message is determined in the FIFO buffer.

When the CFE bit is set to 0 (no transmit/receive FIFO buffer is used), the CFEMP flag is set to 1 (the transmit/receive FIFO buffer contains no message (buffer empty)) at the timing below.

- The transmit/receive FIFO buffer becomes empty immediately if the message in it is not being transmitted or is not to be transmitted next.

- The transmit/receive FIFO buffer becomes empty after transmission completion, CAN bus error detection, or arbitration-lost in the case that a message in it is being transmitted or to be transmitted next.

When the CFE bit is cleared to 0, all messages in transmit/receive FIFO buffers are lost and messages cannot be stored in FIFO buffers. Confirm that the CFEMP flag is set to 1 before setting the CFE bit to 1 again.

## 21.7.3.1 Interval Transmission Function

A message transmission interval time can be set to space the transmission of messages from the same FIFO buffer when using a transmit/receive FIFO buffer set to transmit mode or gateway mode.

Immediately after the first message has been transmitted successfully from the FIFO buffer with the CFE bit in the RSCAN0CFCCk register set to 1, the interval timer starts counting (after EOF7 of the CAN protocol). After that, when the interval time has passed, the next message is transmitted. The interval timer stops in channel reset mode or by clearing the CFE bit to 0.

The interval time is set by the CFITT[7:0] bits in the RSCAN0CFCCk register. When the interval timer is not used, set the CFITT[7:0] bits to 00H.

Select an interval timer count source using the CFITR and CFITSS bits in the RSCAN0CFCCk register. When the CFITR and CFITSS bits are set to 00B, the count source is obtained by dividing pclk/2 by the value of the ITRCP[15:0] bits. When the CFITR and CFITSS bits are set to 10B, the count source is obtained by dividing pclk/2 by (the value of the ITRCP[15:0] bits in the RSCAN0GCFG register  10). When the CFITR and CFITSS bits are set to x1B, the CANm bit time clock is used as a count source.

The interval time is calculated by the following equations where M is the value set to ITRCP[15:0] and N is the set CFITT[7:0] value.

- When CFITR and CFITSS = 00B (fPBA is the frequency of pclk):

   - 1  M  N

   - fPBA

- When CFITR and CFITSS = 10B:

1  M  10  N fPBA

- When CFITR and CFITSS = x1B (fCANBIT is the frequency of CANm bit time clock):

**==> picture [63 x 18] intentionally omitted <==**

Figure 21.10 shows the interval timer block diagram.

**==> picture [427 x 148] intentionally omitted <==**

**----- Start of picture text -----**<br>
Setting for each FIFO<br>ITRCP[15:0] CFITR, CFITSS CFITT[7:0]<br>pclk 1/2 Prescaler 00B Interval timer<br>1 10B (Setting range: 0 to 255)<br>10 x1B<br>Count enable signal<br>Setting of entire module CANm bit time clock<br>ITRCP[15:0]: Bits in the RSCAN0GCFG register<br>CFITR, CFITSS, CFITT[7:0] : Bits in the RSCAN0CFCCk register (m = 0 or 1, k = 0 to 5)<br>**----- End of picture text -----**<br>

**Figure 21.10 Interval Timer Block Diagram**

Figure 21.11 shows the interval timer timing diagram.

**==> picture [473 x 234] intentionally omitted <==**

**----- Start of picture text -----**<br>
H EOF INT<br>CAN bus<br>L<br>ACK SOF<br>Prescaler of<br>499 •  • 0 499  •  •  •  0 499  •  •  •  0 499  •  •  • 0 499 •  •  • 0 499 •  •  • 0 499  •  •  •  0 499 •  • 0<br>ITRCP[15:0]<br>1<br>Transmit complete signal<br>0<br>1<br>Count enable signal<br>0<br>Interval timer 0 10 9 8  •  •  •  •  •  1 0<br>1<br>FIFO transmit request<br>0 Transmit priority<br>determination and internal<br>processing<br>(1) (2) (3) (4)<br>Interval time (logical value) = 2/fPBA  (set ITRCP[15:0] value)  set CFITT[7:0] value<br>fPBA: Frequency of CKSCLK_ICAN<br>ITRCP[15:0]: Bits in the RSCAN0GCFG register (The set value is 500 in this figure.)<br>CFITT[7:0]: Bits in the RSCAN0CFCCk register (The set value is 10 in this figure.)<br>**----- End of picture text -----**<br>

## **Figure 21.11 Interval Timer Timing Chart**

- (1) The interval timer starts counting upon completion of transmission. Since the prescaler is not initialized at the time of transmission completion, the first interval time contains an error of up to one count of the interval timer.

- (2) The interval timer is decremented by the next count enable signal.

- (3) When the interval timer has decreased to 0, the transmit/receive FIFO buffer issues a transmit request.

- (4) The transmit/receive FIFO buffer is determined for the next transmission by the priority determination, it starts transmitting data. Transmission starts usually with a delay of three CANm bit time clock cycles or less from the issue of transmit request. If multiple internal processes (such as receive filter processing, message routing, and transmit priority determination) take place in all channels, a delay of up to 504 cycles of pclk may be generated.

## 21.7.4 Transmission Using Transmit Queues

Three to sixteen buffers are allocated to a transmit queue for each channel, and transmit buffer ((16  m) + 15) is used as an access window of a corresponding channel.

All messages in a transmit queue are targets of transmit priority determination and are transmitted in the ID priority order regardless of storage sequence. If two messages having the same ID are stored in a transmit queue, these messages are not always transmitted in the order of their storage in the transmit queue.

Setting the TXQE bit in the RSCAN0TXQCCm register to 0 disables transmit queues. When the TXQE bit is set to 0, the TXQEMP flag in the RSCAN0TXQSTSm register is set to 1 (the transmit queue contains no messages (transmit queue empty)) at the timing below.

- The transmit queue becomes empty immediately when no message in it is being transmitted or will be transmitted next.

- The transmit queue becomes empty after transmission completion, CAN bus error detection, or arbitration-lost when a message in it is being transmitted or will be transmitted next.

When the TXQE bit is cleared to 0, all messages in transmit queues are lost and messages cannot be stored in transmit queues. Confirm that the TXQEMP flag is set to 1 before setting the TXQE bit to 1 again.

## 21.7.5 Transmit History Function

Information about transmitted messages can be stored in the transmit history buffer. Each channel has a single transmit history buffer that can contain 16 sets of transmit history data.

A message transmit source buffer type can be selected by the THLDTE bit in the RSCAN0THLCCm register. The THLEN bit in the RSCAN0CFIDk register (k = 0 to 5) determines whether transmit history data is stored for each message.

The following information on a transmitted message will be stored in the transmission history buffer after the successful completion of transmission.

Storage of the transmission history data after the successful completion of transmission may take up to 144 cycles of pclk.

 Buffer type 001B: Transmit buffer 010B: Transmit/receive FIFO buffer 100B: Transmit queue

 Buffer number Number of source transmit buffer, transmit queue, or transmit/receive FIFO buffer. This number depends on buffer types. See Table 21.90 .

 Label data Label information of the transmit message

**Table 21.90 Transmit History Data Buffer Numbers**

|**Buffer type**|||||
|---|---|---|---|---|
|**Buffer No.**||**001B**|**010B**|**100B**|
|0000B|Transmit|buffer 16m + 0|Buffer numbers of the transmit|Buffer numbers of the transmit buffer|
|0001B|Transmit|buffer 16m + 1|buffer linked to the transmit/<br>receive FIFO buffer by the|allocated to the transmit queue that<br>performed transmission|
|0010B|Transmit|buffer 16m + 2|CFTML[3:0] bits in the||
|0011B|Transmit|buffer 16m + 3|RSCAN0CFCCk register<br>(k = 0 to 5)||
|0100B|Transmit|buffer 16m + 4|||
|0101B|Transmit|buffer 16m + 5|||
|0110B|Transmit|buffer 16m + 6|||
|0111B|Transmit|buffer 16m + 7|||
|1000B|Transmit|buffer 16m + 8|||
|1001B|Transmit|buffer 16m + 9|||
|1010B|Transmit|buffer 16m + 10|||
|1011B|Transmit|buffer 16m + 11|||
|1100B|Transmit|buffer 16m + 12|||
|1101B|Transmit|buffer 16m + 13|||
|1110B|Transmit|buffer 16m + 14|||
|1111B|Transmit|buffer 16m + 15|||

Label data is used to identify each message. Unique label data can be added to each message transmitted from a transmit buffer, transmit queue, or transmit/receive FIFO buffer.

Transmit history data can be read from the RSCAN0THLACCm register. If an attempt is made to store new transmit history data while the buffer is full, the buffer overflows and the new data is discarded.

## 21.8 Gateway Function

When a transmit/receive FIFO buffer is set to gateway mode, receive massages can be transmitted from an arbitrary channel without CPU intervention.

When a transmit/receive FIFO buffer for which the CFM[1:0] bits in the RSCAN0CFCCk register are set to 10B (gateway mode) is selected by the RSCAN0GAFLP1j register, messages that passed through the filter processing of the receive rule are stored in the specified transmit/receive FIFO buffer and are automatically transmitted from the buffer.

Messages stored in a transmit/receive FIFO buffer are transmitted sequentially on a first-in, first-out basis. Only the message to be transmitted next becomes the target of transmit priority determination.

Transmit/receive FIFO buffers in the gateway mode are disabled by setting the CFE bit in the RSCAN0CFCCk register to 0 and the CFEMP flag becomes 1 according to the timing below.

- The transmit/receive FIFO buffer becomes empty immediately when the oldest message in it is not being transmitted and will not to be transmitted next.

- The transmit/receive FIFO buffer becomes empty after transmission completion, CAN bus error detection, or arbitration-lost when the message in it is being transmitted or will be transmitted next.

When the CFE bit is cleared to 0, all messages in transmit/receive FIFO buffers are lost and messages can no longer be stored in transmit/receive FIFO buffers. Confirm that the CFEMP flag is set to 1 before setting the CFE bit to 1 again.

## 21.9 Test Function

The test function is classified into communication tests and global tests.

- Communication tests: Performed for each channel.

   - Standard test mode

   - Listen-only mode

   - Self-test mode 0 (external loopback mode)

   - Self-test mode 1 (internal loopback mode)

- Global tests: Performed for the entire module

– Inter-channel communication test

## 21.9.1 Standard Test Mode

Standard test mode allows CRC test.

## 21.9.2 Listen-Only Mode

Listen-only mode allows reception of data frames and remote frames. Only recessive bits are transmitted on the CAN bus, and the ACK bit, overload flag, and active error flag are not transmitted.

Listen-only mode is available for detecting the communication speed.

Do not make a transmit request from any buffer or queue in listen-only mode.

Figure 21.12 shows the connection when listen-only mode is selected.

**==> picture [233 x 149] intentionally omitted <==**

**----- Start of picture text -----**<br>
CANmTX CANmRX<br>Recessive level<br>CANmTX CANmRX<br>(internal) (internal)<br>m = 0 or 1 Transmits the ACK bit, overload flag,<br>and active error flag.<br>**----- End of picture text -----**<br>

**Figure 21.12 Connection when Listen-Only Mode is Selected**

## 21.9.3 Self-Test Mode (Loopback Mode)

In self-test mode, transmitted messages are compared with the receive rule of the own channel and the messages are stored in a buffer if they have passed through the filter processing. Messages transmitted from other CAN nodes are compared only with the receive rule for which the GAFLLB bit in the RSCAN0GAFLIDj register (j = 0 to 15) is set to 0 (when a message transmitted from another CAN node is received).

If the mirror function and self-test mode are both enabled, the self-test mode setting takes precedence.

## 21.9.3.1 Self-Test Mode 0 (External Loopback Mode)

Self-test mode 0 is used to perform a loopback test within a channel including the CAN transceiver.

In self-test mode 0, transmitted messages are handled as messages received through the CAN transceiver and are stored in a buffer. An ACK bit is generated to receive messages transmitted from the own CAN node.

Figure 21.13 shows the connection when self-test mode 0 is selected.

**==> picture [244 x 118] intentionally omitted <==**

**----- Start of picture text -----**<br>
CAN transceiver<br>CANmTX CANmRX<br>ACK<br>CANmTX CANmRX<br>(internal) (internal)<br>m = 0 or 1<br>**----- End of picture text -----**<br>

**Figure 21.13 Connection when Self-Test Mode 0 is Selected**

## 21.9.3.2 Self-Test Mode 1 (Internal Loopback Mode)

In self-test mode 1, transmitted messages are handled as received messages and are stored in a buffer. An ACK bit is generated to receive messages transmitted from the own CAN node.

In self-test mode 1, internal feedback from the internal CANmTX pin (m = 0 or 1) to the internal CANmRX pin is performed. The external CANmRX pin input is isolated. The external CANmTX pin outputs only recessive bits.

Figure 21.14 shows the connection when self-test mode 1 is selected.

**==> picture [244 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
CANmTX CANmRX<br>Recessive level<br>ACK<br>CANmTX CANmRX<br>(internal) (internal)<br>m = 0 or 1<br>**----- End of picture text -----**<br>

**Figure 21.14 Connection when Self-Test Mode 1 is Selected**

## 21.9.4 Inter-Channel Communication Test

The inter-channel communication test function allows communication test by internally connecting

CAN channels to each other. During this test, channels are isolated from the external CAN bus.

Before starting data transmission/reception in channel communication mode, make transmission/ reception settings for each channel.

Figure 21.15 shows the connection for inter-channel communication test.

**==> picture [197 x 94] intentionally omitted <==**

**----- Start of picture text -----**<br>
CAN0TX<br>CAN channel 0<br>CAN0RX<br>CAN1TX<br>CAN channel 1<br>CAN1RX<br>**----- End of picture text -----**<br>

**Figure 21.15 Connection for Inter-Channel Communication Test**

## 21.10 RS-CAN Setting Procedure

## 21.10.1 Initial Settings

The RS-CAN module initializes the CAN RAM after this LSI is reset. The RAM initialization time is 6082 cycles of pclk. The GRAMINIT flag in the RSCAN0GSTS register is set to 1 (CAN RAM initialization is ongoing) during the RAM initialization and is cleared to 0 (CAN RAM initialization is finished) when the initialization is completed. Make CAN settings after the GRAMINIT flag is cleared to 0. Figure 21.16 shows the CAN setting procedure after this LSI is reset.

**==> picture [374 x 511] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Is the GRAMINIT flag in the<br>RSCAN0GSTS register 0? No<br>Yes<br>Transition from global stop mode to<br>global reset mode<br>(Set GSLPR in the RSCAN0GCTR register to 0)<br>Transition from channel stop mode to<br>channel reset mode<br>(Set CSLPR in the RSCAN0CmCTR register to 0)<br>Clock<br>RSCAN0GCFG register setting Bit timing<br>Communication speed<br>Timestamp<br>Mirror function<br>RSCAN0CmCFG register setting DLC filter<br>Transmit priority<br>RSCAN0GAFLECTR, RSCAN0GAFLCFG0, RSCAN0GAFLCFG1,<br>Receive rule setting RSCAN0GAFLIDj, RSCAN0GAFLMj, RSCAN0GAFLP0j, and<br>RSCAN0GAFLP1j registers<br>Receive buffer, receive FIFO buffer, transmit/receive<br>Buffer setting FIFO buffer, transmit buffer, transmit queue, transmit<br>history buffer<br>RSCAN0GCTR register setting Global interrupt<br>RSCAN0CmCTR register setting Channel interrupt, bus off recovery, error indication<br>Interrupt setting Interrupt control register of interrupt controller<br>Interrupt control register of interrupt controller<br>Transition to global operating mode<br>(Set GMDC[1:0] in the RSCAN0GCTR register<br>to 00B)<br>Transition to channel communication mode<br>(Set CHMDC[1:0] in the RSCAN0CmCTR<br>register to 00B)<br>Notes 1: The following condition should be satisfied.<br>CAN clock = pclk/2<br>2:  For the setting of the CAN clock frequency, refer to<br>End Table 21.6, Range of Operating Frequency<br>Depending on the Transfer Rate and the Number of<br>Channels in Use in this LSI.<br>Remark: m = 0 or 1, j = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 21.16 CAN Setting Procedure after the this LSI is Reset**

## 21.10.1.1 Clock Setting

Set the CAN clock (fCAN) as a clock source of the RS-CAN module. Select the clk_xincan or clkc using the DCS bit in the RSCAN0GCFG register.

## 21.10.1.2 Bit Timing Setting

In the CAN protocol, one bit of a communication frame consists of three segments SS, TSEG1, and TSEG2. Two of the segments, TSEG1 and TSEG2, can be set by the RSCAN0CmCFG register for each channel. Sample point timing can be determined by setting these two segments. This timing can be adjusted in units of 1 Time Quantum (referred to as Tq hereinafter). 1 Tq is equal to one CANmTq clock cycle. The CANmTq clock is obtained by selecting the clock source with the DCS bit in the RSCAN0GCFG register and selecting the clock division ratio with the BRP[9:0] bits in the RSCAN0CmCFG register.

Figure 21.17 shows the bit timing chart. Table 21.91 shows an example of bit timing setting.

**==> picture [344 x 128] intentionally omitted <==**

**----- Start of picture text -----**<br>
Sample point (80%)<br>SS TSEG1 TSEG2<br>SJW SJW<br>80%<br>Sample point<br>SS = 1 Tq fixed<br>Set TSEG1 to a range of 4 Tq to 16 Tq<br>Set TSEG2 to a range of 2 Tq to 8 Tq<br>Set SJW to a range of 1 Tq to 4 Tq<br>Set SS + TSEG1 + TSEG2 to a range of 8 Tq to 25 Tq<br>TSEG1 > TSEG2 > SJW<br>**----- End of picture text -----**<br>

SS (synchronization segment):

The SS is a segment that performs synchronization by monitoring the edge from recessive to dominant bits in the Interframe Space.

- Interframe Space consists of Intermission, Suspend Transmission, and Bus Idle. All nodes can start transmission during Bus Idle.

- TSEG1 (Time segment 1):

- TSEG1 is a segment that absorbs physical delay on the CAN network. The physical delay on the CAN network is twice the total of the delay on the CAN bus, the delay in the input comparator, and the delay in the output driver.

- TSEG2 (Time segment 2):

- TSEG2 is a segment that compensates phase error due to an error in frequency.

- SJW (Resynchronization jump width)

The SJW is a length to extend or reduce the time segment to compensate for an error in phase due to phase error.

## **Figure 21.17 Bit Timing Chart**

**Table 21.91 Example of Bit Timing Setting**

|**1 Bit**|**Set Value (Tq)**|**Set Value (Tq)**|**Set Value (Tq)**|**Set Value (Tq)**|**Sample Point (%)**<br>**Note: See Figure 21.17.**|
|---|---|---|---|---|---|
||**SS**|**TSEG1**|**TSEG2**|**SJW**||
|8Tq|1|4|3|1|62.50|
||1|5|2|1|75.00|
|12Tq|1|8|3|1|75.00|
||1|9|2|1|83.33|
|16Tq|1|10|5|1|68.75|
||1|11|4|1|75.00|
|24Tq|1|14|9|1|62.50|
||1|15|8|1|66.66|

## 21.10.1.3 Communication Speed Setting

Set the CAN communication speed for each channel using the fCAN, baud rate prescaler division value (BRP[9:0] bits in the RSCAN0CmCFG register), and Tq count per bit time.

Figure 21.18 shows the CAN clock control block diagram, and Table 21.92 shows an example of the communication speed setting.

**==> picture [361 x 150] intentionally omitted <==**

**----- Start of picture text -----**<br>
BRP[9:0]<br>CKSCLK_ICANOSC 0 fCAN Baud rate prescaler fCANTQ0<br>1 1 / (P + 1)<br>clk_xincan DCS<br>P = 0 to 1023<br>BRP[9:0]<br>Baud rate prescaler fCANTQm<br>1 / (P + 1)<br>P = 0 to 1023<br>fCAN<br>Communication speed =<br>Baud rate prescaler division value × (Tq count of 1 bit time)<br>**----- End of picture text -----**<br>

**==> picture [145 x 46] intentionally omitted <==**

**----- Start of picture text -----**<br>
m = 0 or 1<br>DCS: Bit in the RSCAN0GCFG register<br>BRP[9:0]: Bits in the RSCAN0CmCFG register<br>fCAN: CAN clock<br>fCANTQm: CANm Tq clock<br>**----- End of picture text -----**<br>

## **Figure 21.18 CAN Clock Control Block Diagram**

**Table 21.92 Example of Communication Speed Setting**

|**fCAN**<br>**Communication speed**|**32MHz**|**24MHz**|**8MHz**|
|---|---|---|---|
|1Mbps|8Tq (4)<br>16Tq (2)|8Tq (3)<br>12Tq (2)<br>24Tq (1)|8Tq (1)|
|500Kbps|8Tq (8)<br>16Tq (4)|8Tq (6)<br>12Tq (4)<br>24Tq (2)|8Tq (2)<br>16Tq (1)|
|125Kbps|8Tq (32)<br>16Tq (16)|8Tq (24)<br>12Tq (16)<br>24Tq (8)|8Tq (8)<br>16Tq (4)|

Note: Values in ( ) are baud rate prescaler division values.

## 21.10.1.4 Receive Rule Setting

Receive rules can be set using receive rule-related registers.

Up to 16 receive rules can be registered per page. Specify pages 0 to 7 by the AFLPN[4:0] bits in the RSCAN0GAFLECTR register.

Set receive rule table write enable/disable using the AFLDAE bit.

Figure 21.19 shows the receive rule setting procedure.

**==> picture [288 x 378] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Set the number of receive rules by the<br>RNCm[7:0] bits in the<br>RSCAN0GAFLCFG0 register.<br>Set the AFLDAE bit in the<br>RSCAN0GAFLECTR register to 1 to enable<br>writing data<br>to the receive rule table.<br>Select a page to be set by the<br>AFLPN[4:0] bits in the<br>RSCAN0GAFLECTR register.<br>Set receive rules by the<br>RSCAN0GAFLIDj, RSCAN0GAFLMj,<br>RSCAN0GAFLP0j and<br>RSCAN0GAFLP1j registers.<br>j = 15 ?<br>No<br>Yes<br>Have setting for all pages<br>to be used been completed? No<br>Yes<br>Set the AFLDAE bit in the<br>RSCAN0GAFLECTR register to 0 to<br>disable writing data<br>to the receive rule table.<br>m = 0 or 1 End<br>j = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 21.19 Receive Rule Setting Procedure**

## 21.10.1.5 Buffer Setting

Set sizes and interrupt sources of buffers. For transmit/receive FIFO buffers that are set to transmit mode, set transmit buffers to be linked.

Figure 21.20 shows the buffer configuration. Figure 21.21 shows the buffer setting procedure.

**==> picture [373 x 416] intentionally omitted <==**

**----- Start of picture text -----**<br>
Receive buffer 0<br>Receive buffers<br>Receive buffer m  16 + 15<br>Receive FIFO 0<br>Receive FIFO 1<br>Receive FIFO 2<br>Receive FIFO 3<br>Receive FIFO buffers<br>Receive FIFO 4<br>Maximum 128 buffers Receive FIFO 5<br>Receive FIFO 6<br>Receive FIFO 7<br>Transmit/receive FIFO 0<br>CAN0 Transmit/receive FIFO 1<br>Transmit/receive FIFO 2<br>Transmit/receive<br>FIFO buffers<br>Transmit/receive FIFO 0<br>CANm Transmit/receive FIFO 1<br>Transmit/receive FIFO 2<br>Transmit buffer 0<br>CAN0<br>Transmit buffer 15<br>32 buffers fixed Transmit buffers<br>Transmit buffer 0<br>CANm<br>m = 0 or 1<br>Transmit buffer 15<br>Note: Receive buffers, receive FIFO buffers, transmit/receive FIFO buffers, and transmit buffers are located in<br>succession.<br>**----- End of picture text -----**<br>

**Figure 21.20 Buffer Configuration**

**==> picture [406 x 315] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Set receive buffer   Set the number of receive buffers (0 to 31) by the NRXMB[7:0] bits.<br>(the RSCAN0RMNB register)<br>Set receive FIFO buffer   Select receive interrupt request timing by the RFIGCV[2:0] bits.<br> Select an interrupt source by the RFIM bit.<br>(the RSCAN0RFCCx register)  Set the number of FIFO buffer stages by the RFDC[2:0] bits.<br> Set the number of transmit buffer to be linked by the CFTML[3:0] bits.<br> Select an interval timer count source by the CFITR and CFITSS bits.<br>Set transmit/receive FIFO buffer   Select a mode by the CFM[1:0] bits.<br>(the RSCAN0CFCCk register)  Select receive interrupt request timing by the CFIGCV[2:0] bits.<br> Select an interrupt source by the CFIM bit.<br> Set the number of FIFO buffer stages by the CFDC[2:0] bits.<br>Set transmit queue   Select an interrupt source by the TXQIM bit.<br>(the RSCAN0TXQCCm register)  Set the number of transmit queue stages by the TXQDC[3:0] bits.<br>Set transmit history buffer   Select a message transmit source buffer type by the THLDTE bit.<br>(the RSCAN0THLCCm register)  Select an interrupt source by the THLIM bit.<br> Enable receive FIFO interrupts by the RFIE bit in the RSCAN0RFCCx register.<br> Enable transmit/receive FIFO transmit interrupts by the CFTXIE bit in<br>the RSCAN0CFCCk register.<br> Enable transmit/receive FIFO receive interrupts by the CFRXIE bit in<br>Enable interrupt of buffer to be used the RSCAN0CFCCk register.<br> Enable transmit abort interrupts by the TAIE bit in the RSCAN0CmCTR register.<br> Enable transmit complete interrupts by the TMIE bit in the RSCAN0TMIEC0 register.<br> Enable transmit queue interrupts by the TXQIE bit in the RSCAN0TXQCCm register.<br> Enable transmit history interrupts by the THLIE bit in the RSCAN0THLCCm register.<br>k = 0 to 5 End<br>x = 0 to 7<br>m = 0 or 1<br>**----- End of picture text -----**<br>

**Figure 21.21 Buffer Setting Procedure**

## 21.10.2 Reception Procedure

## 21.10.2.1 Receive Buffer Reading Procedure

When the processing to store received messages in a receive buffer starts, the RMNSq flag in the RSCAN0RMNDy register (y = 0, q = 0 to 31) is set to 1 (receive buffer q contains a new message). Messages can be read from the RSCAN0RMIDq, RSCAN0RMPTRq, RSCAN0RMDF0q, and RSCAN0RMDF1q registers. If the next message has been received before the current message is read from the receive buffer, the message is overwritten. Figure 21.22 shows the receive buffer reading procedure.

**==> picture [294 x 259] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Has a new message been received? No<br>(Is the RMNSq flag in<br>the RSCAN0RMNDy register 1?)<br>Yes<br>Set the RMNSq flag in the RSCAN0RMNDy register to 0.<br>Read a message from the RSCAN0RMIDq,<br>RSCAN0RMPTRq, RSCAN0RMDF0q and<br>RSCAN0RMDF1q registers.<br>Are all RMNSq flags in<br>the RSCAN0RMNDy register 0?<br>No<br>Yes<br>y = 0 End<br>q = 0 to 31<br>**----- End of picture text -----**<br>

**Figure 21.22 Receive Buffer Reading Procedure**

**==> picture [433 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
CRC<br>H ID Control delimiter EOF INT ID Control EOF INT<br>CAN bus<br>L<br>SOF ACK SOF ACK<br>Acceptance  Routing and storage  Acceptance  Routing and storage<br>filter processing processing filter processing processing<br>1<br>RMNSq flag<br>0<br>(1) (2) (3) (4) (5) (6)<br>y = 0 Cleared by the program<br>q = 0 to 31<br>RMNSq: Flag in the RSCAN0RMNDy register<br>**----- End of picture text -----**<br>

**Figure 21.23 Receive Buffer Reception Timing Chart**

- (1) When the ID field in a message has been received, the acceptance filter processing starts.

- (2) When the message matches the receive rule of the corresponding channel and the message has been successfully received, the routing processing to transfer the message to the specified buffer starts. When the DCE bit in the RSCAN0GCFG register is set to 1 (DLC check is enabled), the DLC filter processing starts at this time.

- (3) When the message has passed through the DLC filter processing, the processing to store the message in the specified receive buffer starts.

   - When the message storage processing starts, the RMNSq flag in the corresponding the RSCAN0RMNDy register is set to 1 (receive buffer n contains a new message). If other channels are performing filter processing or transmit priority determination processing, the routing processing and the storage processing may be delayed.

- (4) When the ID field of the next message has been received, the acceptance filter processing starts.

- (5) When the message matches the receive rule of the corresponding channel and the message has been successfully received, the routing processing to transfer the message to the specified buffer starts. When the DCE bit in the RSCAN0GCFG register is set to 1 (DLC check is enabled), the DLC filter processing starts at this time.

- (6) When the corresponding RMNSq flag is cleared to 0 (receive buffer n contains no new message), this flag is set to 1 again when the message storage processing starts. Even if the RMNSq flag remains 1, a new message is overwritten to the receive buffer. The RMNSq flag should not be cleared to 0 during storage of messages.

## 21.10.2.2 FIFO Buffer Reading Procedure

When received messages have been stored in one or more receive FIFO buffers or a transmit/receive FIFO buffer that is set to receive mode or gateway mode, the corresponding message count display counter (RFMC[7:0] bits in the RSCAN0RFSTSx register (x = 0 to 7) or CFMC[7:0] bits in the RSCAN0CFSTSk register (k = 0 to 5)) is incremented. At this time, when the RFIE bit (receive FIFO interrupt is enabled) in the RSCAN0RFCCx register or the CFRXIE bit (transmit/receive FIFO receive interrupt is enabled) in the RSCAN0CFCCk register is set to 1, an interrupt request is generated. Received messages can be read from the RSCAN0RFIDx, RSCAN0RFPTRx, RSCAN0RFDF0x, and RSCAN0RFDF1x registers for receive FIFO buffers, or from the RSCAN0CFIDk, RSCAN0CFPTRk, RSCAN0CFDF0k, and RSCAN0CFDF1k registers for transmit/receive FIFO buffers. Messages in FIFO buffers can be read sequentially on a first-in, first-out basis.

When the message count display counter value matches the FIFO buffer depth (a value set by the RFDC[2:0] bits in the RSCAN0RFCCx register or the CFDC[2:0] bits in the RSCAN0CFCCk register), the RFFLL or CFFLL flag is set to 1 (the receive FIFO buffer is full).

When all messages have been read out of the FIFO buffer, the RFEMP flag in the RSCAN0RFSTSx register or the CFEMP flag in the RSCAN0CFSTSk register is set to 1 (the receive FIFO buffer contains no unread message (buffer empty)).

If the RFE bit or the CFE bit is cleared to 0 (no receive FIFO buffer is used) with the interrupt request flag (RFIF flag in the RSCAN0RFSTSx register or CFRXIF flag in the RSCAN0CFSTSk register) set to 1 (a receive FIFO interrupt request is present), the interrupt request flag is not automatically cleared to 0. The program must clear the interrupt request flag to 0.

**==> picture [340 x 219] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Is transmit/receive FIFO buffer empty? Yes<br>(Is CFEMP bit in the RSCAN0CFSTSk register 1?)<br>No<br>Read messages from the<br>RSCAN0CFIDk, RSCAN0CFPTRk,<br>RSCAN0CFDF0k and RSCAN0CFDF1k<br>registers.<br>Set the RSCAN0CFPCTRk register to FFH.<br>k = 0 to 5 End<br>**----- End of picture text -----**<br>

**Figure 21.24 Transmit/Receive FIFO Buffer Reading Procedure**

**==> picture [457 x 374] intentionally omitted <==**

**----- Start of picture text -----**<br>
CRC<br>H ID Control delimiter EOF INT ID Control EOF INT<br>CAN bus<br>L<br>SOF ACK SOF ACK<br>Acceptance  Routing and storage  Acceptance  Routing and storage<br>filter processing processing filter processing processing<br>[Transmit/receive FIFO buffer (receive mode)]<br>CFDC[2:0] bits 0 1<br>1<br>CFE bit<br>0<br>CFMC[7:0] bits 0 1 0 1<br>1<br>CFEMP flag<br>0<br>1<br>CFRXIF flag<br>0<br>Cleared by the program<br>[Receive FIFO buffer]<br>RFDC[2:0] bits 0 3<br>1<br>RFE bit<br>0<br>RFMC[7:0] bits 0 1<br>1<br>CFEMP flag<br>0<br>1<br>RFIF flag<br>0<br>(1) (2) (3) (4) (5) (6) (7)<br>k = 0 to 5, x = 0 to 7<br>CFDC[2:0], CFE: Bits in the RSCAN0CFCCk register<br>CFMC[7:0], CFEMP, CFRXIF: Flags in the RSCAN0CFSTSk register<br>RFDC[2:0], RFE: Bits in the RSCAN0RFCCx register<br>RFMC[7:0], CFEMP, RFIF: Flags in the RSCAN0RFSTSx register<br>**----- End of picture text -----**<br>

## **Figure 21.25 FIFO Buffer Reception Timing Chart**

- (1) When the ID field in a message has been received, the acceptance filter processing starts.

- (2) When the message matches the receive rule of the corresponding channel and the message has been successfully received, the routing processing to transfer the message to the specified buffer starts. When the DCE bit in the RSCAN0GCFG register is set to 1 (DLC check is enabled), the DLC filter processing starts at this time.

- (3) When the message has passed through the DLC filter processing and the CFE value in the RSCAN0CFCCk register is 1 (transmit/receive FIFO buffers are used) and the CFDC[2:0] value in the RSCAN0CFCCk register is 001B or more, the message is stored in the transmit/receive FIFO buffer that is set to receive mode. The CFMC[7:0] value in the RSCAN0CFSTSk register is incremented and becomes 01H. When the CFIM bit in the RSCAN0CFCCk register is set to 1 (a FIFO receive interrupt request is generated each time a message has been received), the CFRXIF flag in the RSCAN0CFSTSk register is set to 1 (a transmit/receive FIFO receive interrupt request is present). The CFRXIF flag can be reset to 0 by the program.

- (4) When the ID field of the next message has been received, the acceptance filter processing starts.

- (5) Read received messages from the RSCAN0CFIDk, RSCAN0CFPTRk, RSCAN0CFDF0k, and RSCAN0CFDF1k registers and write FFH to the RSCAN0CFPCTRk register. This causes the CFMC[7:0] bits in the RSCAN0CFSTSk register to be decremented. When CFMC[7:0] becomes 00H, the CFEMP flag in the RSCAN0CFSTSk register becomes 1 (the transmit/receive FIFO buffer contains no message (buffer empty)).

- (6) When the message matches the receive rule of the corresponding channel and the message has been successfully received, the routing processing to transfer the message to the specified buffer starts. When the DCE bit in the RSCAN0GCFG register is set to 1 (DLC check is enabled), the DLC filter processing starts at this time.

- (7) The message is stored in the transmit/receive FIFO buffer set in receive mode when the message has passed through the DLC filter process if the CFE bit is set to 1 (transmit/receive FIFO buffers are used), the RFE bit in the RSCAN0RFCCx register is set to 1, and the CFDC[2:0] bits are set to 001B or more. The CFMC[7:0] bit value is incremented by 1 to be 01H. When the CFIM bit is set to 1 (an interrupt occurs each time a message has been received), the CFRXIF flag is set to 1 (a transmit/receive FIFO receive interrupt request is present).

   - The message is stored in the receive FIFO buffer if the RFE bit in the RSCAN0RFCCx register is set to 1 (receive FIFO buffers are used), and the RFDC[2:0] bits in the RSCAN0RFCCx register are set to 001B or more. The RFMC[7:0] bits in the RSCAN0RFSTSx register are set to 01H by being incremented by 1. When the RFIM bit in the RSCAN0RFCCx register is set to 1 (an interrupt occurs each time a message has been received), the RFIF flag in the RSCAN0RFSTSx register is set to 1 (a receive FIFO interrupt request is present).

## 21.10.3 Transmission Procedure

## 21.10.3.1 Procedure for Transmission from Transmit Buffers

Figure 21.26 shows the procedure for transmission from transmit buffers.

Figure 21.27 shows a timing chart where messages are transmitted from two transmit buffers in the same channel and transmission has been successfully completed. Figure 21.28 shows a timing chart where messages are transmitted from two transmit buffers in the same channel and transmit abort has been completed.

**==> picture [263 x 129] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Store messages in transmit buffers<br>(the RSCAN0TMIDp, RSCAN0TMPTRp,<br>RSCAN0TMDF0p and RSCAN0TMDF1p registers).<br>Set the TMTR bit in the corresponding<br>RSCAN0TMCp register to 1<br>(requesting transmission).<br>p = 0 to 31 End<br>**----- End of picture text -----**<br>

**Figure 21.26 Procedure for Transmission from Transmit Buffers**

**==> picture [472 x 356] intentionally omitted <==**

**----- Start of picture text -----**<br>
Example of transmission from channel 0 transmit buffers a and b<br>Determine next  Determine next<br>transmit priority transmit priority<br>H<br>CAN bus<br>L<br>SOF CRC delimiter EOF INT SOF CRC delimiter EOF INT<br>[Transmit buffer a]<br>1<br>TMTR bit<br>0<br>1<br>TMTSTS flag<br>0<br>TMTRF[1:0] flag 00B 10B 00B<br>1<br>CAN0 transmit complete<br>interrupt request 0<br>CAN0 transmit abort  1<br>interrupt request 0<br>[Transmit buffer b] 1<br>TMTR bit<br>0<br>1<br>TMTSTS flag<br>0<br>TMTRF[1:0] flag 00B 10B<br>CAN0 transmit complete  1<br>interrupt request 0<br>CAN0 transmit abort  1<br>interrupt request 0<br>(1) (2) (3) (4)<br>a = 0 to 31, b = 0 to 31<br>TMTR: Bit in the RSCAN0TMCp register<br>TMTSTS, TMTRF[1:0]: Flags in the RSCAN0TMSTSp registers<br>**----- End of picture text -----**<br>

## **Figure 21.27 Transmit Buffer Transmission Timing Chart (Transmission Completed Successfully)**

- (1) When the TMTR bit in the RSCAN0TMCa register is set to 1 while the CAN bus is idle, the transmit priority determination processing starts to determine the highest-priority transmit buffer. If transmit buffer a is determined to be the highest-priority transmit buffer, the TMTSTS flag in the corresponding the RSCAN0TMCa register is set to 1 (transmission is in progress) and the CAN channel starts transmitting data.

- (2) When a transmit request from a buffer is present, the priority determination starts with the CRC delimiter for the next transmission.

- (3) When transmission completes successfully, the TMTRF[1:0] flag in the RSCAN0TMCa register is set to 10B (transmission has been completed (without transmit abort request)) and the TMTSTS flag and the TMTR bit in the RSCAN0TMCa register are cleared to 0. When the TMIEa value in the RSCAN0TMIEC0 register is 1 (transmit buffer interrupt is enabled), a CAN0 transmit complete interrupt request is generated. To clear the interrupt request, set the TMTRF[1:0] flag to 00B (transmission is in progress or no transmit request is present).

- (4) Before starting the next transmission, set the TMTRF[1:0] flag to 00B. Write the next message to the transmit buffer, and then set the TMTR bit to 1 (transmission is requested). The TMTR bit can be set to 1 only when the TMTRF[1:0] flag value is 00B.

If an arbitration-lost has occurred after transmission is started, the TMTSTS flag is cleared to 0. The transmit priority determination is reexecuted at the beginning of the CRC delimiter to search the highest-priority transmit buffer. If an error has occurred during transmission or after arbitration loss, the priority determination processing is reexecuted during transmission of an error frame.

The timing the TMTSTS flag is set to 1 is not always the start timing of SOF. The start timing of SOF can be delayed up to the start timing of the basic ID due to the synchronization logic implemented for PLL bypass.

**==> picture [475 x 402] intentionally omitted <==**

**----- Start of picture text -----**<br>
Example of transmission from channel 0 transmit buffers a and b<br>Determine next  Determine next  Determine next<br>transmit priority transmit priority transmit priority<br>H<br>CAN bus<br>L<br>SOF CRC delimiter EOF INT SOF CRC delimiter EOF INT<br>[Transmit buffer a]<br>1<br>TMTR bit<br>0<br>1<br>TMTAR bit<br>0<br>1<br>TMTSTS flag<br>0<br>TMTRF[1:0] flag 00B 11B 00B<br>1<br>CAN0 transmit complete<br>interrupt request 0<br>1<br>CAN0 transmit abort<br>interrupt request 0<br>[Transmit buffer b] 1<br>TMTR bit<br>0<br>1<br>TMTAR bit<br>0<br>1<br>TMTSTS flag<br>0<br>TMTRF[1:0] flag 00B 01B<br>1<br>CAN0 transmit<br>completeinterrupt request 0<br>1<br>CAN0 transmit abort<br>interrupt request 0<br>(1) (2) (3) (4) (5) (6)<br>a = 0 to 31, b = 0 to 31<br>TMTR, TMTAR: Bits in the RSCAN0TMCp register<br>TMTSTS, TMTRF[1:0]: Flags in the RSCAN0TMSTSp register<br>**----- End of picture text -----**<br>

**Figure 21.28 Transmit Buffer Transmission Timing Chart (Transmit Abort Completed)**

- (1) When the TMTR bit in the RSCAN0TMCa register is set to 1 while the CAN bus is idle, the transmit priority determination processing starts to determine the highest-priority transmit buffer. If transmit buffer a is determined to be the highest-priority transmit buffer, the TMTSTS flag in the corresponding RSCAN0TMCa register is set to 1 (transmission is in progress) and the CAN channel starts transmitting data.

- (2) When it is determined that the transmit buffer is used for the next transmission or transmission is in progress, message transmission is not aborted unless an error or arbitration loss occurs even if the TMTAR bit is set to 1 (transmit abort is requested).

- (3) The priority determination starts with the CRC delimiter for the next transmission. In this timing chart, buffer b is not selected as the next transmit buffer.

- (4) When transmission completes successfully, the TMTRF[1:0] flag in the RSCAN0TMCa register is set to 11B (transmission has been completed (with transmit abort request)) and the TMTSTS flag and the TMTR bit in the RSCAN0TMCa register are cleared to 0. When the TMIEa value in the RSCAN0TMIEC0 register is 1 (transmit buffer interrupt is enabled), a CAN0 transmit complete interrupt request is generated. To clear the interrupt request, set the TMTRF[1:0] flag to 00B (transmission is in progress or no transmit request is present).

- (5) While another CAN node is transmitting data on the CAN bus (TMTSTS flag = 0), if the TMTAR bit is set to 1 while the corresponding channel is determining transmit priority, the TMTR bit cannot be cleared to 0.

- (6) After the internal processing time has passed, the transmission is terminated and the TMTRF[1:0] flag is set to 01B. When the transmit buffer is not transmitting data and is not selected as the next transmit buffer and priority determination is not being made, an abort request is immediately accepted and the TMTRF[1:0] flag is set to 01B. At this time, the TMTR and TMTAR bits are cleared to 0. When transmit abort is completed with the TAIE bit in the RSCAN0CmCTR register set to 1 (transmit abort interrupt is enabled), an interrupt request is generated. To clear the interrupt request, set the TMTRF[1:0] flag to 00B.

If an arbitration loss has occurred after the CAN channel started transmission, the TMTSTS bit is cleared to 0. The transmit priority determination is reexecuted at the beginning of the CRC delimiter to find the highest-priority transmit buffer. If an error has occurred during transmission or after arbitration loss, the priority determination processing is reexecuted during transmission of an error frame.

## 21.10.3.2 Procedure for Transmission from Transmit/Receive FIFO Buffers

Figure 21.29 shows the procedure for transmission from transmit/receive FIFO buffers.

Figure 21.30 shows a timing chart where messages are transmitted from two transmit/receive FIFO buffers in the same channel and transmission has been successfully completed. Figure 21.31 shows a timing chart where messages are transmitted from two transmit/receive FIFO buffers in the same channel and transmit abort has been completed.

**==> picture [294 x 208] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Yes<br>Is transmit/receive FIFO buffer full?<br>(Is CFFLL flag in the RSCAN0CFSTSk register 1?)<br>No<br>Store messages in the RSCAN0CFIDk, RSCAN0CFPTRk,<br>RSCAN0CFDF0k and RSCAN0CFDF1k registers.<br>Set the RSCAN0CFPCTRk register to FFH.<br>k = 0 to 5 End<br>**----- End of picture text -----**<br>

**Figure 21.29 Procedure for Transmission from Transmit/Receive FIFO Buffers**

**==> picture [463 x 396] intentionally omitted <==**

**----- Start of picture text -----**<br>
Example of transmission from channel 0 transmit/receive<br>FIFO buffers a and b<br>CRC  CRC<br>H delimiter EOF INT delimiter EOF INT<br>CAN bus<br>L<br>SOF SOF<br>Determine next  Determine next  Determine next<br>transmit priority transmit priority transmit priority<br>[Transmit/receive FIFO buffer a]<br>CFDC[2:0] bits 0 1<br>1<br>CFE bit<br>0<br>CFMC[7:0] bits 0 1 2 1<br>1<br>CFEMP flag<br>0<br>1<br>CFTXIF flag<br>0<br>[Transmit/receive FIFO buffer b]<br>CFDC[2:0] bits 0 3<br>1<br>CFE bit<br>0<br>CFMC[7:0] bits 0 1 0<br>1<br>CFEMP flag<br>0<br>1<br>CFTXIF flag<br>0<br>CAN0 transmit/receive  1<br>FIFO transmit<br>interrupt request 0<br>(1) (2) (3) (4) (5)<br>a = 0 to 5, b = 0 to 5<br>CFDC[2:0],CFE: Bits in the RSCAN0CFCCk register<br>CFMC[7:0], CFEMP, CFTXIF: Flags in the RSCAN0CFSTSk register<br>**----- End of picture text -----**<br>

**Figure 21.30 Transmit/Receive FIFO Buffer Transmission Timing Chart (Transmission Completed Successfully)**

- (1) While the CAN bus is idle, when the CFE value in the RSCA0CFCCa register is 1 (transmit/receive FIFO buffers are used) and the CFDC[2:0] value in the RSCAN0CFCCa register is 001B (4 messages) or more and the CFMC[7:0] value in the RSCAN0CFSTSa register is 01H or more, the priority determination processing starts to determine the highest-priority transmit message. When the highest-priority transmit message has been determined, transmission of the message starts. In this figure, the message is transmitted from transmit/receive FIFO buffer a of channel 0.

- (2) When a transmit request from a buffer is present, the priority determination starts with the CRC delimiter for the next transmission.

- (3) When transmission completes successfully, the CFMC[7:0] value in the RSCAN0CFSTSa register is decremented. Setting the CFIM bit in the RSCAN0CFCCa register to 1 (a FIFO transmit interrupt request is generated each time a message has been transmitted) sets the CFTXIF flag in the RSCAN0CFSTSk register to 1 (a transmit/receive FIFO transmit interrupt request is present).

- (4) The program can clear the CFTXIF flag.

- (5) Message transmission from transmit/receive FIFO buffer b of channel 0 has been completed and the CFMC[7:0] value in the RSCAN0CFSTSb register is decremented. The CFMC[7:0] bits are cleared to 00H and therefore the CFEMP flag in the RSCAN0CFSTSk register is set to 1 (the transmit/receive FIFO buffer contains no message (buffer empty)).

Transmission is continued until the CFEMP flag is set to 1. It is possible to continuously store transmit messages in FIFO buffers until the CFFLL flag in the RSCAN0CFSTSa and RSCAN0CFSTSb register is set to 1 (the transmit/receive FIFO buffer is full).

**==> picture [461 x 393] intentionally omitted <==**

**----- Start of picture text -----**<br>
Example of transmission from channel 0 transmit/receive<br>FIFO buffers a and b<br>CRC  CRC<br>H delimiter EOF INT delimiter EOF INT<br>CAN bus<br>L<br>SOF SOF<br>Determine next  Determine next  Determine next<br>transmit priority transmit priority transmit priority<br>[Transmit/receive FIFO buffer a]<br>CFDC[2:0] bits 0 1<br>1<br>CFE bit<br>0<br>CFMC[7:0] bits 0 1 2 0<br>1<br>CFEMP flag<br>0<br>1<br>CFTXIF flag<br>0<br>[Transmit/receive FIFO buffer b]<br>CFDC[2:0] bits 0 3<br>1<br>CFE bit<br>0<br>CFMC[7:0] bits 0 1 2 3 0<br>1<br>CFEMP flag<br>0<br>1<br>CFTXIF flag<br>0<br>CAN0 transmit/receive  1<br>FIFO transmit<br>interrupt request 0<br>(1) (2) (3) (4) (5) (6)<br>a = 0 to 5, b = 0 to 5<br>CFDC[2:0], CFE: Bits in the RSCAN0CFCCk register<br>CFMC[7:0], CFEMP, CFTXIF: Flags in the RSCAN0CFSTSk register<br>**----- End of picture text -----**<br>

## **Figure 21.31 Transmit/Receive FIFO Buffer Transmission Timing Chart (Transmit Abort Completed)**

- (1) While the CAN bus is idle, when the CFE value in the RSCAN0CFCCa register (a = 0 to 5) is 1 (transmit/receive FIFO buffers are used) and the CFDC[2:0] value in the RSCAN0CFCCa register is 001B (4 messages) or more and the CFMC[7:0] value in the RSCAN0CFSTSa register is 01H or more, the priority determination processing starts to determine the highest-priority transmit message. When the highest-priority transmit message has been determined, transmission of the message starts. In this figure, the message is transmitted from transmit/receive FIFO buffer a of channel 0.

- (2) When transmission is in progress or it is determined that the transmit/receive FIFO buffer is used for the next transmission, message transmission is not aborted unless an error or arbitration loss occurs even if the CFE bit is set to 0 (no transmit/receive FIFO buffer is used).

- (3) When a transmit request from a buffer is present, the priority determination starts with the CRC delimiter for the next transmission. In this figure, transmit/receive FIFO buffer b is not selected as a buffer for the next transmission.

- (4) When transmit completes successfully, the CFMC[7:0] value is cleared to 00H. Setting the CFIM bit to 1 (a FIFO transmit interrupt request is generated each time a message has been transmitted) sets the CFTXIF flag in the RSCAN0CFSTSa register to 1 (a transmit/receive FIFO transmit interrupt request is present). The program can clear the CFTXIF flag.

- (5) If another CAN node on the CAN bus is transmitting data (not from transmit/receive FIFO buffer b), transmit/receive FIFO buffers cannot be disabled immediately even if the CFE bit in the RSCAN0CFCCb register is cleared to 0 (no transmit/receive FIFO buffer is used) during transmit priority determination. (The CFEMP flag in the RSCAN0CFSTSb register is not set to 1 (the transmit/receive FIFO buffer contains no message (buffer empty)) immediately.)

- (6) After the internal processing time has passed, transmit/receive FIFO buffers are disabled and the CFMC[7:0] bits in the RSCAN0CFSTSb register are cleared to 00H and the CFEMP flag is set to 1. When the transmit/receive FIFO buffer is not transmitting data and is not selected as the next transmit buffer and priority determination is not in progress, the transmit/receive FIFO buffer is immediately disabled. (The CFMC[7:0] bits are cleared to 00H and the CFEMP flag is set to 1.)

## 21.10.3.3 Procedure for Transmission from the Transmit Queue

Figure 21.32 shows the procedure for transmission from the transmit queue.

**==> picture [318 x 200] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Is transmit queue full? Yes<br>(Is TXQFLL flag in the RSCAN0TXQSTSm<br>register 1?)<br>No<br>Store messages in access windows<br>(the RSCAN0TMIDp, RSCAN0TMPTRp, RSCAN0TMDF0p<br>and RSCAN0TMDF1p registers).<br>Set the RSCAN0TXQPCTRm register to FFH.<br>p = m × 16 + 15 End<br>m = 0 or 1<br>**----- End of picture text -----**<br>

**Figure 21.32 Procedure for Transmission from the Transmit Queue**

## 21.10.3.4 Transmit History Buffer Reading Procedure

Transmit history data can be read from the RSCAN0THLACCm register. The next data can be accessed by writing FFH to the corresponding RSCAN0THLPCTRm register (m = 0 or 1) after reading a set of data. Figure 21.33 shows the transmit history buffer reading procedure.

**==> picture [314 x 214] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Is transmit history buffer empty? Yes<br> (Is THLEMP bit in the RSCAN0THLSTSm<br>register 1?)<br>No<br>Read transmit history data<br>from the RSCAN0THLACCm register.<br>Set the RSCAN0THLPCTRm register to FFH.<br>m = 0 or 1<br>End<br>**----- End of picture text -----**<br>

**Figure 21.33 Transmit History Buffer Reading Procedure**

## 21.10.4 Test Settings

## 21.10.4.1 Self-Test Mode Setting Procedure

Self-test mode allows communication test on a channel basis by enabling a CAN node to receive its own transmitted messages.

Figure 21.34 shows the self-test mode setting procedure.

**==> picture [372 x 468] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Set the CHMDC[1:0] bits  Channel halt mode<br>in the RSCAN0CmCTR register to 10B.<br>Is CHLTSTS flag in the RSCAN0CmSTS register 1<br>(in channel halt mode)? No<br>Yes<br>Set CTME bit in the RSCAN0CmCTR register to 1. Communication test mode is enabled.<br>Set the CTMS[1:0] bits to 10B or 11B. Self-test mode 0 (10B) or 1 (11B) is selected.<br>Set the CHMDC[1:0] bits<br>in the RSCAN0CmCTR register to 00B. Channel communication mode<br>Are all CSLPSTS, CHLTSTS, and CRSTSTS<br>flags in the RSCAN0CmSTS register 0? No<br>Yes<br>Perform self-test in channel m.<br>Set the CHMDC[1:0] bits  Channel halt mode<br>in the RSCAN0CmCTR register to 10B.<br>Is CHLTSTS flag in the RSCAN0CmSTS register 1<br>(in channel halt mode)? No<br>Yes<br>Set CTME bit in the RSCAN0CmCTR register to 0. Communication test mode disabled.<br>Set the CTMS[1:0] bits to 00B. Standard test mode<br>m = 0 or 1 End<br>**----- End of picture text -----**<br>

**Figure 21.34 Self-Test Mode Setting Procedure**

## 21.10.4.2 Inter-Channel Communication Test Setting Procedure

Communication testing can be performed by transmitting and receiving data between different channels.

Figure 21.35 shows the inter-channel communication test setting procedure.

**==> picture [360 x 559] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Set the GMDC[1:0] bits in the RSCAN0GCTR register to 10B. Global test mode<br>Is the GHLTSTS flag in<br>the RSCAN0GSTS register set to 1<br>(global test mode)? No<br>Yes<br>Set the C0ICBCE bit in the RSCAN0GTSTCFG register to 1. Enable inter-channel communication test for channel 0.<br>Set the C1ICBCE bit in the RSCAN0GTSTCFG register to 1. Enable inter-channel communication test for channel 1.<br>Set the ICBCTME bit in the RSCAN0GTSTCTR register to 1. Enable inter-channel communication test.<br>Set channels 0 and 1 for transmission and reception.<br>Set GMDC[1:0] bits in the RSCAN0GCTR register to 00B. Global operating mode<br>Is the value of the<br>RSCAN0GSTS register 00H<br>(global operating mode)?  No<br>Yes<br>Channel<br>Set CHMDC[1:0] bits in the RSCAN0CmCTR register to 00B. communication mode<br>Set both channels 0 and 1<br>to channel communication<br>Are the CSLPSTS,  mode.<br>CHLTSTS and CRSTSTS flags in the<br>RSCAN0CmSTS register all 0? No<br>Yes<br>Perform communication testing by transmitting and<br>receiving data between channel 0 and 1.<br>Set GMDC[1:0] bits in the RSCAN0GCTR register to 00B.<br>Is the GHLTSTS flag in<br>the RSCAN0GSTS register set to 1<br>(global test mode)? No<br>Yes<br>Set the C0ICBCE bit in the RSCAN0GTSTCFG register to 0. Disable inter-channel communication test.<br>Set the C1ICBCE bit in the RSCAN0GTSTCFG register to 0. Disable inter-channel communication test for channel 0.<br>Set the ICBCTME bit in the RSCAN0GTSTCTR register to 0. Disable inter-channel communication test for channel 1.<br>End<br>m = 0 or 1<br>**----- End of picture text -----**<br>

**Figure 21.35 Inter-Channel Communication Test Setting Procedure(Example of Communication Test between Channel 0 and Channel 1)**

## 21.11 Notes on the RS-CAN Module

- When changing a global mode, check the GSLPSTS, GHLTSTS, and GRSTSTS flags in the RSCAN0GSTS register for transitions. When changing a channel mode, check the CSLPSTS, CHLTSTS, and CRSTSTS flags in the RSCAN0CmSTS register (m = 0 or 1) for transitions.

- The acceptance filter processing checks receive rules sequentially in ascending order from the minimum rule number. If the same ID, IDE bit, or RTR bit value is set for multiple receive rules, the minimum number of receive rule is used for the acceptance filter processing. If the message does not pass through the subsequent DLC filter processing, the data processing is terminated without returning to the acceptance filter processing and the message is not stored in the buffer.

- When linking transmit buffers to transmit/receive FIFO buffers or allocating transmit buffers to transmit queues, set the control register (RSCAN0TMCp) of the corresponding transmit buffer to 00H. The status register (RSCAN0TMSTSp) of the corresponding transmit buffer should not be used. Flags in other status registers (registers RSCAN0TMTRSTS0, RSCAN0TMTARSTS0, RSCAN0TMTCSTS0, and RSCAN0TMTASTS0), which correspond to transmit buffers linked to transmit/receive FIFO buffers or allocated to transmit queues remain unchanged. Set the enable bit in the corresponding interrupt enable register (the RSCAN0TMIEC0 register) to 0 (transmit buffer interrupt is disabled).

- Transmit buffers that are linked to transmit/receive FIFO buffers must not bet allocated to transmit queues.

- Only a single transmit/receive FIFO buffer can be linked to a transmit buffer. Do not link two or more transmit/receive FIFO buffers to transmit buffers of the same number.

- When the CANm bit time clock is selected as a timestamp counter clock source, the timestamp counter stops when the corresponding channel has transitioned to channel reset mode or channel halt mode.

- In case of an attempt to store a new received message when the receive FIFO buffer and the transmit/receive FIFO buffer are full, the new message is discarded. If you wish to store a new transmit message in the transmit/receive FIFO buffer or the transmit queue, check that the transmit/receive FIFO buffer or the transmit queue is not full.

- The values of unused receive buffer registers (RSCAN0RMIDq, RSCAN0RMPTRq, RSCAN0RMDF0q, and RSCAN0RMDF1q registers), receive FIFO buffer access registers (RSCAN0RFIDx, RSCAN0RFPTRx, RSCAN0RFDF0x, and RSCAN0RFDF1x registers), and transmit/receive FIFO buffer access registers (RSCAN0CFIDk, RSCAN0CFPTRk, RSCAN0CFDF0k, and RSCAN0CFDF1k registers) are undefined when the RS-CAN module transitions to global operation mode or global test mode after exiting from global reset mode.
