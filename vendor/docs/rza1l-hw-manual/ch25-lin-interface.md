# 25. LIN Interface

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1287–1346. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This module is only incorporated in the RZ/A1L.

This section contains a generic description of the LIN Interface (RLIN3). The first part of this section describes all specific properties of this product, such as the register base addresses, etc. The remainder of the section describes the functions and registers of RLIN3.

## 25.1 Features

## 25.1.1 Channels

This LSI has following number of channels of the LIN Interface.

## **Table 25.1 Channels of RLIN3n**

|**LIN Interface**|**RZ/A1L**|
|---|---|
|Channels|1|
|Name|RLIN30|

## Index n

Throughout this section, the channel of the LIN Interface (RLIN3) is identified by the index “n” (n = 0), for example, RLN3nLMD for the LIN mode register.

## 25.1.2

## Register Addresses

The register base address of the LIN interface is listed in the following table.

All LIN interface register addresses are given as address offsets to the individual base address.

## **Table 25.2 Register Base Addresses**

|**Base Address Name**|**Base Address**|
|---|---|
|<RLIN30_base>|FCFE 9000H|

## 25.1.3 Clock Supply

The following clock is provided for the LIN interface.

## **Table 25.3 RLIN3n Clock Supply**

|**RLIN3n**|**Clock**|**Connected to**|
|---|---|---|
|RLIN3n|LIN Communication Clock Source|P0φ|

## 25.1.4 Interrupts and DMA

The LIN Interface can generate the following interrupt and DMA requests:

## **Table 25.4 RLIN3n Interrupt and DMA Requests**

|**RLIN3n signal**|**Function**|
|---|---|
|**RLIN30**||
|LIN0_INT_M|LIN0 interrupt|
|LIN0_INT_T|LIN0 transmission interrupt|
|LIN0_INT_R|LIN0 successful reception interrupt|
|LIN0_INT_S|LIN0 status error interrupt|

## 25.1.5 I/O Signals

The I/O signals of the LIN Interface are used for various purposes, as listed in Table 25.5 .

## **Table 25.5 RLIN3n I/O Signals**

|**Name**|**Function**|
|---|---|
|**RLIN30**||
|Port RLIN30RX|RLIN30 receive data input|
|Port RLIN30TX|RLIN30 transmit data output|

## 25.2 Function

The LIN Interface is a hardware LIN communication controller that supports LIN Specification Package Revision 1.3, 2.0, 2.1, 2.2, and SAEJ2602, and automatically performs frame communication and error determination.

The LIN master mode is only available.

## LIN master

- LIN reset mode

- LIN mode (LIN master mode)

   - LIN wake-up mode

   - LIN operation mode

- LIN self-test mode

Table 25.6 gives the LIN Interface specifications and Figure 25.1 shows a block diagram of the LIN Interface.

||**Table 25.6**<br>**LIN Interface Specifications**|
|---|---|
|**Item**|**Specifications**|
||Channel count<br>1|
|LIN<br>communication<br>function|Protocol<br>LIN Specification Package Revision 1.3, 2.0, 2.1, 2.2, and SAEJ2602|
||Variable frame<br>structure<br>Master<br>Break transmission width: 13 to 28 Tbits<br>Break delimiter transmission width: 1 to 4 Tbits<br>Transmission inter-byte space width (header): 0 to 7 Tbits (space between Sync field<br>and ID field)*1<br>Transmission response space width: 0 to 7 Tbits*1<br>Transmission inter-byte space width: 0 to 3 Tbits (space between data bytes in<br>response area)<br>Transmit wake-up width: 1 to 16 Tbits|
||Checksum<br>Automatic operation for both transmission and reception<br>Classic or enhanced selectable (for each frame)|
||Response field<br>data byte count<br>Variable from 0 to 8 bytes<br>Multi-byte (9 or more bytes) response transmission and reception also possible|
||Frame<br>communication<br>modes<br>Master<br>Mode in which header transmission and response transmission/reception is started<br>with a single transmission start request<br>Mode in which header transmission and response transmission are started with<br>separate transmission start requests (frame separate mode) (Setting of the frame<br>separate mode is prohibited in this product.)|
||Wake-up<br>transmission<br>and reception<br>LIN wake-up mode provided<br>Wake-up transmission (1 to 16 Tbits)<br>Wake-up reception<br>Low-level width of input signals measured|
||Status<br>Master<br>Successful frame/wake-up transmission<br>Successful header transmission<br>Successful frame/wake-up reception*2<br>Successful data 1 reception<br>Error detection<br>Operation mode<br>(LIN reset mode, LIN wake-up mode, LIN operation mode, LIN self-test mode)|
||Error status<br>Master<br>Bit error<br>Checksum error<br>Frame timeout error/response timeout error<br>Physical bus error<br>Framing error<br>Response preparation error|
||Baud rate<br>selection<br>Baud rate conforming to the LIN specifications generated using baud rate generator|
||Test mode<br>Self-test mode for user evaluation|
||Interrupt<br>function<br>Master<br>Successful header/frame/wake-up transmission<br>Successful frame/wake-up reception*2<br>Error detection|

Note 1. Since the same register is used for setting, the inter-byte space (header) = response space.

Note 2. For wake-up reception, the low level width of the input signal is indicated.

## 25.2.1 Block Diagram

**==> picture [383 x 143] intentionally omitted <==**

**----- Start of picture text -----**<br>
LIN communication  LINn baud rate generator<br>clock source<br>fa fb fc fd LINn registers<br>RLIN3nTX<br>LINn protocol controller<br>RLIN3nRX<br>LINn interrupt  LINn transmission interrupt LINn_INT_T<br>control circuit reception interruptLINn successful LINn_INT_R<br>LINn status interrupt LINn_INT_S<br>LIN interface module LINn interrupt LINn_INT_M<br>Data bus<br>**----- End of picture text -----**<br>

**Figure 25.1 LIN Interface Block Diagram**

## 25.2.2 Description of Blocks

- RLIN3nTX, RLIN3nRX: LIN Interface I/O pins

- LINn baud rate generator: Generates the LIN Interface communication clock signal.

- LINn registers: LIN Interface registers

- LINn interrupt controller: Controls interrupt requests generated by the LIN Interface

## 25.3 Registers

Table 25.7 lists the LIN Interface registers.

**Table 25.7 List of LIN Interface Registers**

|**Register Name**|**Symbol**|
|---|---|
|LIN wake-up baud rate selector register|RLN3nLWBR|
|LIN baud rate prescaler 0 register|RLN3nLBRP0|
|LIN baud rate prescaler 1 register|RLN3nLBRP1|
|LIN self-test control register|RLN3nLSTC|
|LIN mode register|RLN3nLMD|
|LIN break field configuration register|RLN3nLBFC|
|LIN space configuration register|RLN3nLSC|
|LIN wake-up configuration register|RLN3nLWUP|
|LIN interrupt enable register|RLN3nLIE|
|LIN error detection enable register|RLN3nLEDE|
|LIN control register|RLN3nLCUC|
|LIN transmission control register|RLN3nLTRC|
|LIN mode status register|RLN3nLMST|
|LIN status register|RLN3nLST|
|LIN error status register|RLN3nLEST|
|LIN data field configuration register|RLN3nLDFC|
|LIN ID buffer register|RLN3nLIDB|
|LIN checksum buffer register|RLN3nLCBR|
|LIN data buffer 1 register|RLN3nLDBR1|
|LIN data buffer 2 register|RLN3nLDBR2|
|LIN data buffer 3 register|RLN3nLDBR3|
|LIN data buffer 4 register|RLN3nLDBR4|
|LIN data buffer 5 register|RLN3nLDBR5|
|LIN data buffer 6 register|RLN3nLDBR6|
|LIN data buffer 7 register|RLN3nLDBR7|
|LIN data buffer 8 register|RLN3nLDBR8|

Note: When writing to a register not used, write 00H.

## 25.3.1 LIN Master Related Registers

## 25.3.1.1 RLN3nLWBR — LIN Wake-up Baud Rate Select Register

|||**Access:**|This|register can be read/written in 8-bit units.|register can be read/written in 8-bit units.|register can be read/written in 8-bit units.|||||
|---|---|---|---|---|---|---|---|---|---|---|
|||**Address:**|<RLIN3n_base> + 01H||||||||
|||**Initial value:**|00H||||||||
|Bit||7|6|5|4||3|2|1|0|
|||||NSPB[3:0]||||LPRS[2:0]||LWBR0|
|Initial value||0|0|0|0||0|0|0|0|
|R/W||R/W|R/W|R/W|R/W||R/W|R/W|R/W|R/W|
|**Table 25.8**|||**RLN3nLWBR register contents**||||||||

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 4|NSPB[3:0]|Bit Sampling Count Select|
|||b7      b4|
|||0 0 0 0: 16 sampling|
|||1 1 1 1: 16 sampling|
|||Settings other than the above are prohibited.|
|3 to 1|LPRS[2:0]|Prescaler Clock Select|
|||b3        b1|
|||0 0 0: 1/1|
|||0 0 1: 1/2|
|||Other than above: Setting prohibited|
|0|LWBR0|Wake-up Baud Rate Select|
|||0: In LIN wake-up mode, the clock specified by the LCKS bit setting in the|
|||RLN3nLMD register is used (when LIN1.3 is used).|
|||1: In LIN wake-up mode, the clock fa is used regardless of the setting of the|
|||LCKS bit in the RLN3nLMD register (when LIN2.x is used).|

Set the RLN3nLWBR register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

## NSPB[3:0] bits (bit sampling count select bits)

These bits select the number of sampling in one Tbit (reciprocal of the baud rate).

In LIN master mode, set these bits to 0000B or 1111B (16 sampling).

## LPRS[2:0] bits (prescaler clock select bits)

These bits select the frequency division ratio for the prescaler.

LWBR0 bit (wake-up baud rate select bit)

When LIN Specification Package Revision 1.3 is used, set the LWBR0 bit in the RLN3nLWBR register to 0. This allows the 2.5-Tbit or longer low-level width of the input signal to be measured. When LIN Specification Package Revision 2.x is used, set the LWBR0 bit to 1. Setting the LWBR0 bit to 1 selects fa as the LIN system clock (fLIN) during LIN wake-up mode regardless of the setting of the RLN3nLMD.LCKS bit (the LCKS bit is not changed). This allows the 2.5-Tbit or longer low-level width of the input signal to be measured.

Setting the baud rate to 19200 bps while fa is selected allows the 130 μs or longer low-level width of the input signal to be detected during LIN wake-up mode regardless of the setting of the RLN3nLMD.LCKS bit.

## 25.3.1.2 RLN3nLBRP0 — LIN Baud Rate Prescaler 0 Register

**Access:** This register can be read/written in 8-bit units. **Address:** <RLIN3n_base> + 02H **Initial value:** 00H Bit 7 6 5 4 3 2 1 0 LBRP0[7:0] Initial value 0 0 0 0 0 0 0 0 R/W R/W R/W R/W R/W R/W R/W R/W R/W

## **Table 25.9 RLN3nLBRP0 register contents**

**Bit Position Bit Name Function** 7 to 0 LBRP0[7:0] Assuming that the value set in this register is N (4 to 255), the baud rate prescaler divides the frequency of the prescaler clock by N + 1. Setting Range: 04H to FFH Note: Set the LPRS and LBRP0 bits so that the frequency of the prescaler clock becomes no more than that of the clock source for LIN communications divided by nine.

Set the RLN3nLBRP0 register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

The value set in this register is used to control the frequency of baud rate clock sources fa, fb, and fc.

Assuming that the value set in this register is N, baud rate prescaler 0 divides the frequency of the clock that is selected by the LPRS bits by N + 1.

## 25.3.1.3 RLN3nLBRP1 — LIN Baud Rate Prescaler 1 Register

**Access:** This register can be read/written in 8-bit units. **Address:** <RLIN3n_base> + 03H **Initial value:** 00H Bit 7 6 5 4 3 2 1 0 LBRP1[7:0] Initial value 0 0 0 0 0 0 0 0 R/W R/W R/W R/W R/W R/W R/W R/W R/W

## **Table 25.10 RLN3nLBRP1 register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 0|LBRP1[7:0]|Assuming that the value set in this register is M (4 to 255), the baud rate|
|||prescaler divides the frequency of the prescaler clock by M + 1.|
|||Setting Range: 04Hto FFH|
|||Note: Set the LPRS and LBRP1 bits so that the frequency of the prescaler clock|
|||becomes no more than that of the clock source for LIN communications|
|||divided by nine.|

Set the RLN3nLBRP1 register when the OMM0 bit in the RLN2uunLcMST register is 0B (in LIN reset mode).

The value set in this register is used to control the frequency of baud rate clock source fd.

Assuming that the value set in this register is M, baud rate prescaler 1 divides the frequency of the clock that is selected by the LPRS bits (prescaler clock select bits) by M + 1.

## 25.3.1.4 RLN3nLSTC — LIN Self-Test Control Register

||**Access:**|This register can be read/written|This register can be read/written|in 8-bit units.|||||
|---|---|---|---|---|---|---|---|---|
||**Address:**|<RLIN3n_base> + 04H|||||||
||**Initial value:**|00H|||||||
|Bit|7|6|5|4|3|2|1|0|
|||||—||||LSTM|
|Initial value|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R|R/W|

## **Table 25.11 RLN3nLSTC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 1|Reserved|Writing A7H, 58H, and 01Hsuccessively to the RLN3nLSTC register places the|
|||module into LIN self-test mode.|
|0|LSTM|LIN Self-Test Mode|
|||0: The module is not in LIN self-test mode|
|||1: The module is in LIN self-test mode.|

The RLN3nLSTC register cancels protection of LIN self-test mode.

Set the RLN3nLSTC register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

Writing A7H, 58H, and 01H successively to the RLN3nLSTC register places the module into LIN selftest mode.

When successive writing is completed thus placing LIN self-test mode to be entered, the LSTM bit is set to 1.

Do not write any other value during successive writing.

For making transition to LIN self-test mode, refer to Section 25.8, LIN Self-Test Mode .

When read, bits 6 to 1 return 000000B, and bit 7 returns an undefined value.

LSTM bit (LIN self test mode bit)

When transition to LIN self-test mode is completed, the LSTM bit is set to 1.

For leaving LIN self-test mode, refer to Section 25.8, LIN Self-Test Mode .

Writing 1 to this bit does not affect the value of the RLN3nLSTC register if it is not a part of successive writing of A7H, 58H, and 01H.

## 25.3.1.5 RLN3nLMD — LIN Mode Register

||**Access:**|**Access:**|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**||<RLIN3n_base> + 08H||||||||||
||**Initial value:**||00H||||||||||
|Bit|7||6|5|4||3||2|1||0|
||—||—|LRDNFS|LIOS|||LCKS[1:0]|||LMD[1:0]||
|Initial value|0||0|0|0||0||0|0||0|
|R/W|R||R|R/W|R/W||R/W||R/W|R/W||R/W|

**Table 25.12 RLN3nLMD register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7, 6|Reserved|When read, an initial value is returned. When written, write an initial value.|
|5|LRDNFS|LIN Reception Data Noise Filtering Disable|
|||0: The noise filter is enabled.|
|||1: The noise filter is disabled.|
|4|LIOS|LIN Interrupt Output Select|
|||0: LINn interrupt is used.|
|||1: LINn transmission interrupt, LINn successful reception interrupt, and LINn|
|||status error interrupt are used.|
|3, 2|LCKS[1:0]|LIN System Clock Select|
|||b3 b2|
|||0  0: fa (Clock generated by baud rate prescaler 0)|
|||0  1: fb (1/2 clock generated by baud rate prescaler 0)|
|||1  0: fc (1/8 clock generated by baud rate prescaler 0)|
|||1  1: fd (1/2 clock generated by baud rate prescaler 1)|
|1, 0|LMD[1:0]|LIN Mode Select|
|||b1 b0|
|||0  0: LIN master mode|

Set the RLN3nLMD register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

## LRDNFS bit (LIN reception data noise filtering disable bit)

The LRDNFS bit enables or disables the noise filter when receiving data.

With 0 set, the noise filter is enabled when receiving data.

With 1 set, the noise filter is disabled when receiving data.

LIOS bit (LIN interrupt output select bit)

The LIOS bit selects the number of interrupt outputs from the LIN Interface.

With 0 set, the LINn interrupt is generated from the LIN Interface.

With 1 set, the LINn transmission interrupt, LINn successful reception interrupt, and LINn status interrupt are generated from the LIN Interface.

For each interrupt source, refer to Section 25.4, Interrupt Sources .

## LCKS[1:0] bits (LIN system clock select bits)

The LCKS bits select the clock to be input to the protocol controller.

With 00B set, the protocol controller is provided with fa (clock generated by baud rate prescaler 0).

With 01B set, the protocol controller is provided with fb (1/2 clock generated by baud rate prescaler 0). With 10B set, the protocol controller is provided with fc (1/8 clock generated by baud rate prescaler 0). With 11B set, the protocol controller is provided with fd (1/2 clock generated by baud rate prescaler 1). With 1B is set in the LWBR0 bit in the RLN3nLWBR register (LIN 2.x is used), and the RLN3nLMST register is 01H (LIN wake-up mode), the protocol controller is provided with fa regardless of the setting of the bit (the LCKS bit is not changed).

## LMD[1:0] bits (LIN mode select bits)

The LMD bits select the LIN Interface mode.

To use the LIN Interface as an LIN master, set these bits to 00B.

## 25.3.1.6 RLN3nLBFC — LIN Break Field Configuration Register

||**Access:**|**Access:**|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**||<RLIN3n_base> + 09H|||||||||
||**Initial value:**||00H|||||||||
|Bit|7||6|5|4||3|2||1|0|
||—||—||BDT[1:0]||||BLT[3:0]|||
|Initial value|0||0|0|0||0|0||0|0|
|R/W|R||R|R/W|R/W||R/W|R/W||R/W|R/W|

## **Table 25.13 RLN3nLBFC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7, 6|Reserved|When read, an initial value is returned. When written, write an initial value.|
|5, 4|BDT[1:0]|Break Delimiter (High level) width select bit|
|||b5  b4|
|||0  0: 1 Tbit|
|||0  1: 2 Tbits|
|||1  0: 3 Tbits|
|||1  1: 4 Tbits|
|3 to 0|BLT[3:0]|Transmit Break (Low level) width select bit|
|||b3      b0|
|||0 0 0 0: 13 Tbits|
|||0 0 0 1: 14 Tbits|
|||0 0 1 0: 15 Tbits|
|||:|
|||1 1 1 0: 27 Tbits|
|||1 1 1 1: 28 Tbits|

Set the RLN3nLBFC register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

Some combinations of the set values result in the length of a frame exceeding the timeout time. Set the appropriate values in this register.

BDT[1:0] bit (Transmission Break Delimiter high level width setting bit)

This bit is used to set the break high **level** width of transmission frame header.

1 Tbit to 4 Tbits can be set.

BLT[3:0] bit (Transmission Break Low level width setting bit)

This BLT bits set the break low **level** width of transmission frame header.

13 Tbits to 28 Tbits can be set.

## 25.3.1.7 RLN3nLSC — LIN Space Configuration Register

**Access:** This register can be read/written in 8-bit units. **Address:** <RLIN3n_base> + 0AH **Initial value:** 00H

|Bit|7|6|5||4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|
||—|—||IBS[1:0]||—||IBHS[2:0]||
|Initial value|0|0|0||0|0|0|0|0|
|R/W|R|R|R/W||R/W|R|R/W|R/W|R/W|

## **Table 25.14 RLN3nLSC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7, 6|Reserved|When read, an initial value is returned. When written, write an initial value.|
|5, 4|IBS[1:0]|Inter-Byte Space Select|
|||b5 b4|
|||0  0: 0 Tbit|
|||0  1: 1 Tbit|
|||1  0: 2 Tbits|
|||1  1: 3 Tbits|
|3|Reserved|When read, an initial value is returned. When written, write an initial value.|
|2 to 0|IBHS[2:0]|Inter-Byte Space (Header)/Response Space Select|
|||b2   b0|
|||0 0 0: 0 Tbit|
|||0 0 1: 1 Tbit|
|||0 1 0: 2 Tbits|
|||0 1 1: 3 Tbits|
|||1 0 0: 4 Tbits|
|||1 0 1: 5 Tbits|
|||1 1 0: 6 Tbits|
|||1 1 1: 7 Tbits|

Set the RLN3nLSC register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

Some combinations of the set values result in the length of a frame or a response exceeding the timeout time. Set the appropriate values in this register.

## IBS[1:0] bits (inter-byte space select bits)

The IBS bits set the width of the inter-byte space of the transmission frame response field.

0 Tbit to 3 Tbits can be set.

These bits are enabled only during response transmission; these are disabled during response reception.

## IBHS[2:0] bits (inter-byte space (header)/response space select bits)

The IBHS bits set the width of the inter-byte space (header) of the transmission frame header field and the response space.

0 Tbit to 7 Tbits can be set.

The response space setting is enabled only during response transmission; setting is disabled during response reception.

The inter-byte space (header) is equal to the response space.

## 25.3.1.8 RLN3nLWUP — LIN Wake-up Configuration Register

||**Access:**|This|register can be read/written|in 8-bit units.|in 8-bit units.|||||
|---|---|---|---|---|---|---|---|---|---|
||**Address:**|<RLIN3n_base> + 0BH||||||||
||**Initial value:**|00H||||||||
|Bit|7|6|5|4||3|2|1|0|
||||WUTL[3:0]|||—|—|—|—|
|Initial value|0|0|0|0||0|0|0|0|
|R/W|R/W|R/W|R/W|R/W||R|R|R|R|

## **Table 25.15 RLN3nLWUP register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 4|WUTL[3:0]|Wake-up Transmission Low level Width Select|
|||b7      b4|
|||0 0 0 0: 1 Tbit|
|||0 0 0 1: 2 Tbits|
|||0 0 1 0: 3 Tbits|
|||0 0 1 1: 4 Tbits|
|||:|
|||1 1 0 0: 13 Tbits|
|||1 1 0 1: 14 Tbits|
|||1 1 1 0: 15 Tbits|
|||1 1 1 1: 16 Tbits|
|3 to 0|Reserved|When read, an initial value is returned. When written, write an initial value.|

Set the RLN3nLWUP register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

WUTL[3:0] bits (wake-up transmission low level width select bits)

The WUTL bits set the low level width of the wake-up signal transmission.

1 Tbit to 16 Tbits can be set.

While 1 is set in the LWBR0 bit in the RLN3nLWBR register (LIN 2.x is used), fa is selected as

the LIN system clock (fLIN) regardless of the setting of the RLN3nLMD.LCKS bit (the LCKS bit is not changed).

## 25.3.1.9 RLN3nLIE — LIN Interrupt Enable Register

||**Access:**|**Access:**|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|||||
|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**||<RLIN3n_base> + 0CH||||||||
||**Initial value:**||00H||||||||
|Bit|7||6|5|4||3|2|1|0|
||—||—|—|—||SHIE|ERRIE|FRCIE|FTCIE|
|Initial value|0||0|0|0||0|0|0|0|
|R/W|R||R|R|R||R/W|R/W|R/W|R/W|

**Table 25.16 RLN3nLIE register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 4|Reserved|When read, an initial value is returned. When written, write an initial value.|
|3|SHIE|Successful Header Transmission Interrupt Request Enable|
|||0: Disables successful header transmission interrupt request.|
|||1: Enables successful header transmission interrupt request.|
|2|ERRIE|Error Detection Interrupt Request Enable|
|||0: Disables error detection interrupt request.|
|||1: Enables error detection interrupt request.|
|1|FRCIE|Successful Frame/Wake-up Reception Interrupt Request Enable|
|||0: Disables successful frame/wake-up reception interrupt request.|
|||1: Enables successful frame/wake-up reception interrupt request.|
|0|FTCIE|Successful Frame/Wake-up Transmission Interrupt Request Enable|
|||0: Disables successful frame/wake-up transmission interrupt request.|
|||1: Enables successful frame/wake-up transmission interrupt request.|

Set the RLN3nLIE register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

SHIE bit (successful header transmission interrupt enable bit)

The SHIE bit enables or disables interrupt request upon successful transmission of a header.

With 0 set, the interrupt request for LINn transmission is not generated when the HTRC flag in the RLN3nLST register is set to 1.

With 1 set, the interrupt request for LINn transmission is generated when the HTRC flag in the RLN3nLST register is set to 1.

ERRIE bit (error detection interrupt request enable bit)

The ERRIE bit enables or disables interrupt request upon detection of an error.

With 0 set, the interrupt request for LINn status is not generated when the ERR flag in the RLN3nLST register is set to 1.

With 1 set, the interrupt request for LINn status is generated when the ERR flag in the RLN3nLST register is set to 1.

Interrupt sources can be the bit error, physical bus error, frame/response timeout error, framing error, checksum error, and response preparation error.

Detection of the bit error, physical bus error, frame/response timeout error, and framing error can be enabled or disabled using the RLN3nLEDE register.

FRCIE bit (successful frame/wake-up reception interrupt request enable bit)

The FRCIE bit enables or disables interrupt request upon successful reception of a frame or a wake-up signal (counting of low level width of the input signal).

With 0 set, the interrupt request for successful LINn reception is not generated when the FRC flag in the RLN3nLST register is set to 1.

With 1 set, the interrupt request for successful LINn reception is generated when the FRC flag in the RLN3nLST register is set to 1.

FTCIE bit (successful frame/wake-up transmission interrupt request enable bit)

The FTCIE bit enables or disables interrupt request upon successful transmission of a frame or a wakeup signal.

With 0 set, the interrupt request for LINn transmission is not generated when the FTC flag in the RLN3nLST register is set to 1.

With 1 set, the interrupt request for LINn transmission is generated when the FTC flag in the RLN3nLST register is set to 1.

## 25.3.1.10 RLN3nLEDE —LIN Error Detection Enable Register

**Access:** This register can be read/written in 8-bit units. **Address:** <RLIN3n_base> + 0DH **Initial value:** 00H

|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||LTES|—|—|—|FERE|FTERE|PBERE|BERE|
|Initial value|0|0|0|0|0|0|0|0|
|R/W|R/W|R|R|R|R/W|R/W|R/W|R/W|

## **Table 25.17 RLN3nLEDE register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7|LTES|Timeout Error Select|
|||0: Frame timeout error|
|||1: Response timeout error|
|6 to 4|Reserved|When read, an initial value is returned. When written, write an initial value.|
|3|FERE|Framing Error Detection Enable|
|||0: Disables framing error detection.|
|||1: Enables framing error detection.|
|2|FTERE|Timeout Error Detection Enable|
|||0: Disables frame/response timeout error detection.|
|||1: Enables frame/response timeout error detection.|
|1|PBERE|Physical Bus Error Detection Enable|
|||0: Disables physical bus error detection.|
|||1: Enables physical bus error detection.|
|0|BERE|Bit Error Detection Enable|
|||0: Disables bit error detection.|
|||1: Enables bit error detection.|

Set the RLN3nLEDE register when the OMM0 bit in the RLN3nLMST register is 0B (in LIN reset mode).

LTES bit (timeout error select bit)

The LTES bit selects the specific timeout function to be used.

With 0 set, the timeout function applies to frame timeout.

With 1 set, the timeout function applies to response timeout.

For details of the timeout error, refer to Section 25.7.6, Error Status .

FERE bit (framing error detection enable bit)

The FERE bit enables or disables detection of the framing error.

With 0 set, the framing error is not detected.

With 1 set, the framing error is detected.

When this bit is set to 1, the detection result is indicated in the FER flag in the RLN3nLEST register.

For details of the framing error, refer to Section 25.7.6, Error Status .

FTERE bit (timeout error detection enable bit)

The FTERE bit enables or disables detection of the frame timeout error or the response timeout error. With 0 set, the frame timeout error or response timeout error is not detected. With 1 set, the frame timeout error or response timeout error is detected. When this bit is set to 1, the detection result is indicated in the FTER flag in the RLN3nLEST register. With the LTES bit, either the frame timeout error or response timeout error can be selected. Do not use the timeout error if response data of 9 bytes or more is to be transmitted or received. For details of the timeout error, refer to Section 25.7.6, Error Status .

PBERE bit (physical bus error detection enable bit)

The PBERE bit enables or disables detection of the physical bus error.

With 0 set, the physical bus error is not detected. With 1 set, the physical bus error is detected.

When this bit is set to 1, the detection result is indicated in the PBER flag in the RLN3nLEST register. For details of the physical bus error, refer to Section 25.7.6, Error Status .

BERE bit (bit error detection enable bit)

The BERE bit enables or disables detection of the bit error. With 0 set, the bit error is not detected. With 1 set, the bit error is detected.

When this bit is set to 1, the detection result is indicated in the BER flag in the RLN3nLEST register. For details of the bit error, refer to Section 25.7.6, Error Status .

## 25.3.1.11 RLN3nLCUC — LIN Control Register

**Access:** This register can be read/written in 8-bit units. **Address:** <RLIN3n_base> + 0EH **Initial value:** 00H

|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|OM1|OM0|
|Initial value|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|

**Table 25.18 RLN3nLCUC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 2|Reserved|When read, an initial value is returned. When written, write an initial value.|
|1|OM1|LIN Mode Select|
|||0: LIN wake-up mode is caused.|
|||1: LIN operation mode is caused.|
|0|OM0|LIN Reset|
|||0: LIN reset mode is caused.|
|||1: LIN reset mode is canceled.|

Set the RLN3nLCUC register to 01H to cause a transition to LIN wake-up mode after canceling LIN reset mode, and set the register to 03H to cause a transition to LIN operation mode.

In LIN self-test mode, set the RLN3nLCUC register to 03h after a transition to LIN self-test mode is completed.

After a value is written to this register, confirm that the value written is actually indicated in the RLN3nLMST register before writing another value.

## OM1 bit (LIN mode select bit)

The OM1 bit selects the specific LIN operation mode (either LIN wake-up mode or LIN operation mode) after canceling LIN reset mode.

With 0 set, LIN wake-up mode is caused.

With 1 set, LIN operation mode is caused.

This bit is valid only when the OMM0 bit in the RLN3nLMST register is 1.

Writing a value to this bit is disabled while the FTS bit in the RLN3nLTRC register is 1.

## OM0 bit (LIN reset bit)

The OM0 bit selects either causing a transition to LIN reset mode or canceling LIN reset mode.

With 0 set, LIN reset mode is caused.

With 1 set, LIN reset mode is canceled.

## 25.3.1.12 RLN3nLTRC — LIN Transmission Control Register

**Access:** This register can be read/written in 8-bit units. **Address:** <RLIN3n_base> + 10H **Initial value:** 00H

|Bit|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||—|—|—|—|—|—|RTS|FTS|
|Initial value|0|0|0|0|0|0|0|0|
|R/W|R|R|R|R|R|R|R/W|R/W|

**Table 25.19 RLN3nLTRC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 2|Reserved|When read, an initial value is returned. When written, write an initial value.|
|1|RTS|Response Transmission/Reception Start|
|||0: Response transmission/reception is stopped in frame separate mode.|
|||1: Response transmission/reception is started in frame separate mode.|
|||Note: Setting of the frame separate mode is prohibited in this product.|
|0|FTS|Frame Transmission/wake-up Transmission /Reception Start|
|||0: Frame Transmission/wake-up transmission /reception is stopped.|
|||1: Frame Transmission/wake-up transmission reception is started.|

## RTS bit (response transmission/reception start bit)

Set the RTS bit to 1 in frame separate mode after header transmission is started (FTS bit is 1) and response transmission data is ready. Once set, this bit is automatically cleared to 0 upon completion of frame communication (including error detection) or transition to LIN reset mode.

Only 1 can be written to this bit; 0 cannot be written. To write 1 to this bit, write 02H to the RLN3nLTRC register using the store instruction.

Writing a value to this bit is disabled when the OMM0 bit of the RLN3nLMST register is 0B (in LIN reset mode).

Writing a value to this bit is disabled when the FTS bit is 0 (frame transmission or wake-up transmission/reception is halted).

When response data of 9 bytes or more is to be transmitted or received, set this bit to 1 each time a data group (variable from 0 to 8 bytes) is transmitted or received. Once set, this bit is automatically cleared to 0 upon completion of data group communication or transition to LIN reset mode.

## FTS bit (frame transmission/wake-up transmission/reception start bit)

Set the FTS bit to 1 to start frame transmission and reception.

Also set this bit to 1 to allow wake-up transmission and wake-up reception (counting of the low level width of the input signal).

Only 1 can be written to this bit; 0 cannot be written. Writing a value to this bit is disabled when the OMM0 bit of the RLN3nLMST register is 0B (in LIN reset mode).

This bit is set to 0 upon completion of frame or wake-up communication (including error detection) and transition to LIN reset mode.

## 25.3.1.13 RLN3nLMST — LIN Mode Status Register

||**Access:**|**Access:**|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|||||
|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**||<RLIN3n_base> + 11H||||||||
||**Initial value:**||00H||||||||
|Bit|7||6|5|4||3|2|1|0|
||—||—|—|—||—|—|OMM1|OMM0|
|Initial value|0||0|0|0||0|0|0|0|
|R/W|R||R|R|R||R|R|R|R|

**Table 25.20 RLN3nLMST register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 2|Reserved|When read, an initial value is returned. When written, write an initial value.|
|1|OMM1|LIN Mode Status Monitor|
|||0: The module is in LIN wake-up mode.|
|||1: The module is in LIN operation mode.|
|0|OMM0|LIN Reset Status Monitor|
|||0: The module is in LIN reset mode.|
|||1: The module is not in LIN reset mode.|

OMM1 bit (LIN mode status monitor)

The OMM1 bit indicate the current operating mode.

OMM0 bit (LIN reset status monitor)

The OMM0 bit indicates the current operating mode.

## 25.3.1.14 RLN3nLST — LIN Status Register

||**Access:**|**Access:**|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|||||
|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**||<RLIN3n_base> + 12H||||||||
||**Initial value:**||00H||||||||
|Bit|7||6|5|4||3|2|1|0|
||HTRC||D1RC|—|—||ERR|—|FRC|FTC|
|Initial value|0||0|0|0||0|0|0|0|
|R/W|R/W||R/W|R|R||R|R|R/W|R/W|

## **Table 25.21 RLN3nLST register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7|HTRC|Successful Header Transmission Flag|
|||0: Header transmission has not been completed.|
|||1: Header transmission has been completed.|
|6|D1RC|Successful Data 1 Reception Flag|
|||These bits are always read as 0. The write value should always be 0.|
|5, 4|Reserved|When read, an initial value is returned. When written, write an initial value.|
|3|ERR|Error Detection Flag|
|||0: No error has been detected.|
|||1: Error has been detected.|
|2|Reserved|When read, an initial value is returned. When written, write an initial value.|
|1|FRC|Successful Frame/Wake-up Reception Flag|
|||0: Frame or wake-up reception has not been completed.|
|||1: Frame or wake-up reception has been completed.|
|0|FTC|Successful Frame/Wake-up Transmission Flag|
|||0: Frame or wake-up transmission has not been completed.|
|||1: Frame or wake-up transmission has been completed.|

The RLN3nLST register is automatically cleared to 00H upon transition to LIN reset mode and start of the next communication (when the FTS bit of the RLN3nLTRC register is 1).

In LIN reset mode, this register cannot be written to. In LIN reset mode, the register retains 00H. To clear the specific bits in the register, write 0 to the bits to be cleared and write 1 to the other bits using the store instruction.

## HTRC flag (successful header transmission flag)

Only 0 can be written to the HTRC flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The HTRC flag is set to 1 upon completion of header transmission. Here, an interrupt request for LINn transmission is generated if the SHIE bit in the RLN3nLIE register is 1 (interrupt is enabled). To clear the bit to 0 before the next communication (when the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode.

## D1RC flag (successful data 1 reception flag)

Only 0 can be written to the D1RC flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The D1RC flag is set to 1 upon completion of data 1 reception. Here, an interrupt request is not generated. To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode.

When response data of 9 bytes or more is to be received, this bit is set to 1 each time data 1 of a data group (variable from 0 to 8 bytes) is received. Write 0 before starting reception of the next data group.

## ERR flag (error detection flag)

The ERR flag is set to 1 upon detection of an error (when the value of any of the flags of the RLN3nLEST registers is 1). Here, an interrupt request for LINn status is generated if the ERRIE bit in the RLN3nLIE register is 1 (interrupt is enabled). To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the RPER, CSER, FER, FTER, PBER, and BER flags in the RLN3nLEST register in LIN operation mode or LIN wake-up mode. This clears the ERR flag to 0.

## FRC flag (successful frame/wake-up reception flag)

Only 0 can be written to the FRC flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The FRC flag is set to 1 upon completion of frame or wake-up reception. Here, an interrupt request for successful LINn reception is generated if the FRCIE bit in the RLN3nLIE register is 1 (interrupt is enabled). To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode or LIN wake-up mode.

When response data of 9 bytes or more is to be received, this bit is set to 1 each time a data group (variable from 0 to 8 bytes) is received. Write 0 before starting reception of the next data group.

## FTC flag (successful frame/wake-up transmission flag)

Only 0 can be written to the FTC flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The FTC flag is set to 1 upon completion of frame or wake-up transmission. Here, an interrupt  request for LINn transmission is generated if the FTCIE bit in the RLN3nLIE register is 1 (interrupt is enabled). To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode or LIN wake-up mode.

When response data of 9 bytes or more is to be transmitted, this bit is set to 1 each time a data group (variable from 0 to 8 bytes) is transmitted. Write 0 before starting transmission of the next data group.

## 25.3.1.15 RLN3nLEST — LIN Error Status Register

||**Access:**|**Access:**|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|||||
|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**||<RLIN3n_base> + 13H||||||||
||**Initial value:**||00H||||||||
|Bit|7||6|5|4||3|2|1|0|
||RPER||—|CSER|—||FER|FTER|PBER|BER|
|Initial value|0||0|0|0||0|0|0|0|
|R/W|R/W||R|R/W|R||R/W|R/W|R/W|R/W|

## **Table 25.22 RLN3nLEST register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7|RPER|Response Preparation Error Flag|
|||0: Response preparation error has not been detected.|
|||1: Response preparation error has been detected.|
|6|Reserved|When read, an initial value is returned. When written, write an initial value.|
|5|CSER|Checksum Error Flag|
|||0: Checksum error has not been detected.|
|||1: checksum error has been detected.|
|4|Reserved|When read, an initial value is returned. When written, write an initial value.|
|3|FER|Framing Error Flag|
|||0: Framing error has not been detected.|
|||1: Framing error has been detected.|
|2|FTER|Timeout Error Flag|
|||0: Frame/response timeout error has not been detected.|
|||1: Frame/response timeout error has been detected.|
|1|PBER|Physical Bus Error Flag|
|||0: Physical bus error has not been detected.|
|||1: Physical bus error has been detected.|
|0|BER|Bit Error Flag|
|||0: Bit error has not been detected.|
|||1: Bit error has been detected.|

The RLN3nLEST register is automatically cleared to 00H upon transition to LIN reset mode and start of the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1).

In LIN reset mode, this register cannot be written to. In LIN reset mode, the register retains 00H.

When the FTS bit in the RLN3nLTRC register is 1 (frame transmission or wake-up transmission/ reception is started), do not write a value to this register. To clear the specific bits in the register, write 0 to the bits to be cleared and write 1 to the other bits using the store instruction.

## RPER flag (response preparation error flag)

Only 0 can be written to the RPER flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The RPER flag is set to 1 upon response preparation error detection. To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode.

## CSER flag (checksum error flag)

Only 0 can be written to the CSER flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The CSER flag is set to 1 upon checksum error detection. To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode.

## FER flag (framing error flag)

Only 0 can be written to the FER flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The FER flag is set to 1 upon frame timeout detection when the FERE bit of the RLN3nLEDE register is 1 (frame timeout detection enabled). To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode.

## FTER flag (timeout error flag)

Only 0 can be written to the FTER flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The FTER flag is set to 1 upon frame timeout error or response timeout error detection when the FTERE bit of the RLN3nLEDE register is 1 (frame/response timeout error detection enabled). To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode.

## PBER flag (physical bus error flag)

Only 0 can be written to the PBER flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The PBER flag is set to 1 upon physical bus error detection when the PBERE bit of the RLN3nLEDE register is 1 (physical bus error detection enabled). To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode or LIN wake-up mode.

## BER flag (bit error flag)

Only 0 can be written to the BER flag; when 1 is written, the bit retains the value that has been retained before 1 is written.

The BER flag is set to 1 upon bit error detection when the BERE bit of the RLN3nLEDE register is 1 (bit error detection enabled). To clear the bit to 0 before the next communication (when the value of the FTS bit of the RLN3nLTRC register is 1), write 0 to the bit in LIN operation mode or LIN wake-up mode.

## 25.3.1.16 RLN3nLDFC — LIN Data Field Configuration Register

||**Access:**|**Access:**|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.|This register can be read/written in 8-bit units.||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
||**Address:**||<RLIN3n_base> + 14H|||||||||
||**Initial value:**||00H|||||||||
|Bit|7||6|5|4||3|2||1|0|
||LSS||FSM|CSM|RFT||||RFDL[3:0]|||
|Initial value|0||0|0|0||0|0||0|0|
|R/W|R/W||R/W|R/W|R/W||R/W|R/W||R/W|R/W|

## **Table 25.23 RLN3nLDFC register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7|LSS|Transmission/Reception Continuation Select|
|||0: The data group to be transmitted/received next is the last one.|
|||1: The data group to be transmitted/received next is not the last one.|
|||(Checksum is not included.)|
|6|FSM|Frame Separate Mode Select|
|||0: Frame separate mode is not set.|
|||1: Frame separate mode is set.|
|||Note: Setting of the frame separate mode is prohibited in this product.|
|5|CSM|Checksum Select|
|||0: Classic checksum mode|
|||1: Enhanced checksum mode|
|4|RFT|Response Field Communication Direction Select|
|||0: Reception|
|||1: Transmission|
|3 to 0|RFDL[3:0]|Response Field Length Select|
|||b3     b0|
|||0 0 0 0: 0 byte (+ checksum)|
|||0 0 0 1: 1 byte (+ checksum)|
|||0 0 1 0: 2 bytes (+ checksum)|
|||:|
|||0 1 1 1: 7 bytes (+ checksum)|
|||1 0 0 0: 8 bytes (+ checksum)|
|||Settings other than the above are prohibited.|

## LSS bit (transmission/reception continuation select bit)

The LSS bit indicates that the data group to be transmitted or received next is not the last data group when response data of 9 bytes or more is to be transmitted or received. With 0 set, data and checksum are transmitted or received because the next data group to be transmitted or received is the last one.

With 1 set, only data is transmitted or received, and the checksum is not included because the next data group to be transmitted or received is not the last one.

Set the LSS bit only when the FSM bit is 1 (frame separate mode) and response data of 9 bytes or more is to be transmitted or received.

Set the LSS bit only when the RTS bit in the RLN3nLTRC is 0 (response transmit/receive is stopped).

FSM bit (frame separate mode select bit)

The FSM bit sets the response communication mode.

With 0 set, frame separate mode is not selected. In this case, after header transmission is started (the FTS bit in the RLN3nLTRC register is 1), response is transmitted/received without the RTS bit in the RLN3nLTRC register being set.

With 1 set, frame separate mode is selected. If the RTS bit of the RLN3nLTRC register is set to 1 during header transmission, response transmission is executed after header transmission is completed.

For response reception which is 8 bytes or less (the RFT bit is 0), set the FSM bit to 0. When causing a transition to LIN self-test mode, set this bit to 0 before transition. For details of frame separate mode, refer to Section 25.7.3.1, Transmission of LIN Frames . Set this bit when the FTS bit in the RLN3nLTRC register is 0 (frame transmission or wake-up transmission/reception is halted).

When response data of 9 bytes or more is to be transmitted or received, set the FSM bit to 1.

## CSM bit (checksum select bit)

The CSM bit sets the checksum mode. With 0 set, classic checksum mode is selected. With 1 set, enhanced checksum mode is selected. When the timeout error is used (the FTERE bit in the RLN3nLEDE register is 1), the specific timeout time depends on the setting of this bit. For details of the bit error, refer to Section 25.7.6, Error Status .

Set this bit when the FTS bit in the RLN3nLTRC register is 0 (frame transmission or wake-up transmission/reception is halted).

When response data of 9 bytes or more is to be transmitted or received, do not change the CSM bit setting after the first data group through the last data group.

During communication of response data of 9 bytes or more, only the last data group (the LSS bit is 0) includes the checksum, and no other groups (the LSS bit is 1) include the checksum.

## RFT bit (response field communication direction select bit)

The RFT bits set the direction of the response field/wake-up signal communication. With 0 set, reception is performed in the response field. In LIN wake-up mode, wake-up reception is performed (low level width of the input signal is counted). With 1 set, transmission is performed in the response field. In LIN wake-up mode, wake-up transmission is performed.

Set this bit when the FTS bit in the RLN3nLTRC register is 0 (frame transmission or wake-up transmission/reception is halted).

When response data of 9 bytes or more is to be transmitted or received, do not change the RFT bit setting after the first data group through the last data group.

## RFDL[3:0] bits (response field length select bits)

The RFDL bits set the length of the response field data. The data length can be 0 to 8 bytes excluding the checksum size.

To transmit response data with the FSM bit set to 0 (not frame separate mode), set the RFDL bits before header transmission (the FTS bit in the RLN3nLTRC register is 0).

To transmit response data with the FSM bit set to 1 (frame separate mode), set the RFDL bits before response transmission (the FTS bit in the RLN3nLTRC register is 0).

To receive response data, set the RFDL bits before header transmission (the FTS bit in the RLN3nLTRC register is 0).

When response data of 9 bytes or more is to be transmitted or received, set the RFDL bits before data group transmission/reception (RTS bit in the RLN3nLTRC register is 0).

Only the last data group (the LSS bit is 0) includes the checksum, and no other groups (the LSS bit is 1) include the checksum.

## 25.3.1.17 RLN3nLIDB — LIN ID Buffer Register

**Access:** This register can be read/written in 8-bit units. **Address:** <RLIN3n_base> + 15H **Initial value:** 00H

|Bit|7||6|5|4|3||2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||IDP[1:0]|||||ID[5:0]||||
|Initial value|0||0|0|0|0||0|0|0|
|R/W|R/W||R/W|R/W|R/W|R/W||R/W|R/W|R/W|

## **Table 25.24 RLN3nLIDB register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7|IDP1|Parity Setting (P1)|
|||Sets the parity bit (P1) to be transmitted in the ID field.|
|6|IDP0|Parity Setting (P0)|
|||Sets the parity bit (P0) to be transmitted in the ID field.|
|5 to 0|ID[5:0]|ID Setting|
|||Sets the 6-bit ID value to be transmitted in the ID field.|

Set the RLN3nLIDB register when the FTS bit in the RLN3nLTRC register is 0 (frame transmission or wake-up transmission/reception is halted).

In LIN self-test mode, this register operates as follows:

Write the value to be transmitted before communication. After completion of frame transmission/ reception (after loopback), the reversed value of the received value can be read.

For details about the LIN self-test mode, see Section 25.8, LIN Self-Test Mode .

## IIDP[1:0] bits (parity setting bits)

The IDP bits set the parity bits (P0 and P1) to be transmitted in the ID field of the LIN frame (IDP0 for P0 and IDP1 for P1). Since parity is not automatically calculated, set the calculation result. Note that if the erroneous result is set, it is transmitted as is.

## ID[5:0] bits (ID setting bits)

The ID bit sets the 6-bit ID value to be transmitted in the ID field of the LIN frame.

## 25.3.1.18 RLN3nLCBR — LIN Checksum Buffer Register

|||**Access:**|**Access:**|This register can only be read in 8-bit|This register can only be read in 8-bit|This register can only be read in 8-bit|units. In LIN self-test mode, this register can be read/written|units. In LIN self-test mode, this register can be read/written|units. In LIN self-test mode, this register can be read/written|in 8-bit|
|---|---|---|---|---|---|---|---|---|---|---|
|||||units.|||||||
|||**Address:**||<RLIN3n_base> + 16H|||||||
|||**Initial value:**||00H|||||||
|Bit||7||6|5|4|3|2|1|0|
||||||||CKSM[7:0]||||
|Initial value||0||0|0|0|0|0|0|0|
|R/W||R/W||R/W|R/W|R/W|R/W|R/W|R/W|R/W|
||**Table 25.25**|||**RLN3nLCBR register contents**|||||||
|||**Bit Position**|**Bit Name**||**Function**||||||
|||7 to 0|CKSM[7:0]||Holds the checksum value transmitted or received.||||||

In LIN mode, this register operates as follows:

- When the RFT bit in the RLN3nLDFC register is 1 (transmission): The value transmitted can be read from the register. Read the value after transmission is completed.

Writing to this register is invalid.

- When the RFT bit in the RLN3nLDFC register is 0 (reception): The value received can be read from the register. Read the value after reception is completed. Writing to this register is invalid.

In LIN self-test mode, this register operates as follows:

- When the RFT bit in the RLN3nLDFC register is 1 (transmission): After completion of the frame transmission (after loopback), the reversed value of the received value can be read.

- When the RFT bit in the RLN3nLDFC register is 0 (reception): Write the value to be received before communication. After completion of frame transmission/ reception (after loopback), the reversed value of the received value can be read. For details about the LIN self-test mode, see Section 25.8, LIN Self-Test Mode .

Set the RLN3nLCBR register when the FTS bit in the RLN3nLTRC register is 0 (frame transmission or wake-up transmission/reception is halted).

When response data of 9 bytes or more is to be transmitted or received, the checksum is appended only to the last data group; this register is not updated for the other data groups.

## 25.3.1.19 RLN3nLDBRm — LIN Data Buffer m Register (m = 1 to 8)

**Access:** This register can be read/written in 8-bit units. **Address:** RLN3nLDBR1: <RLIN3n_base> + 18H RLN3nLDBR2: <RLIN3n_base> + 19H RLN3nLDBR3: <RLIN3n_base> + 1AH RLN3nLDBR4: <RLIN3n_base> + 1BH RLN3nLDBR5: <RLIN3n_base> + 1CH RLN3nLDBR6: <RLIN3n_base> + 1DH RLN3nLDBR7: <RLIN3n_base> + 1EH RLN3nLDBR8: <RLIN3n_base> + 1FH **Initial value:** 00H Bit 7 6 5 4 3 2 1 0 LDB[7:0] Initial value 0 0 0 0 0 0 0 0 R/W R/W R/W R/W R/W R/W R/W R/W R/W

## **Table 25.26 RLN3nLDBRm (m = 1 to 8) register contents**

|**Bit Position**|**Bit Name**|**Function**|
|---|---|---|
|7 to 0|LDB[7:0]|Sets the data to be transmitted or allows the received data to be read.|
|||Setting Range: 00Hto FFH|

## For response transmission:

The LDBRn registers set the data to be transmitted in the response field. Use these registers with the following settings.

- RFT in RLN3nLDFC register is 1 (transmission)

- FSM in RLN3nLDFC register is 0 (not frame separate mode)

- FTS bit in RLN3nLTRC register is 0 (frame transmission or wake-up transmission/reception is halted)

## or

- RFT in RLN3nLDFC register is 1 (transmission)

- FSM in RLN3nLDFC register is 1 (frame separate mode)

- RTS in RLN3nLTRC register is 0 (response transmission/reception is halted)

For response reception:

The LDBRn registers hold the data received in the response field.

The received data is overwritten. If an error is detected, the data up to the byte in which the error was detected are stored in the register. Do not read these registers when the FTS bit is 1 (frame transmission or wake-up transmission/reception is started)

For transmission of response data of 9 bytes or more:

Use the LDBRn registers with the following settings.

- RFT in RLN3nLDFC register is 1 (transmission)

- FSM in RLN3nLDFC register is 1 (frame separate mode)

- RTS in RLN3nLTRC register is 0 (response transmission/reception is halted)

For reception of response data of 9 bytes or more:

Do not read these registers when the RTS bit is 1 (response transmission/reception is started).

In LIN self-test mode, these registers operate as follows:

Write the value to be transmitted before communication. After completion of frame transmission/ reception (after loopback), the reversed value of the received value can be read.

For details about the LIN self-test mode, see Section 25.8, LIN Self-Test Mode .

## 25.4 Interrupt Sources

The LIN Interface generates four types of interrupt requests.

- LINn transmission interrupt

- LINn successful reception interrupt

- LINn status interrupt

- LINn interrupt

Setting the LIOS bit in the RLN3nLMD register to 0 allows to perform logical OR operation on all of the interrupt sources, outputting the interrupt request from the LINn interrupt.

Setting the LIOS bit in the RLN3nLMD register to 1 allows to output the LINn transmission interrupt, LINn successful reception interrupt, or LINn status interrupt depending on the interrupt request.

Table 25.27 lists the sources for each interrupt.

**Table 25.27 Interrupt Sources**

||**LIOS bit in RLN3nLMD register is 0**<br>**LIOS bit in RLN3nLMD register is 1**|
|---|---|
||**LINn Interrupt**<br>**LINn Transmission**<br>**Interrupt**<br>**LINn**<br>**Successful**<br>**Reception**<br>**Interrupt**<br>**LINn Status Interrupt**|
|LIN mode<br>LIN<br>master<br>mode|Successful frame transmission<br>Successful frame reception<br>Successful wake-up transmission<br>Successful wake-up reception<br>Successful header transmission<br>Bit error<br>Physical bus error<br>Frame/response timeout error<br>Framing error<br>Checksum error<br>Response preparation error<br>Successful frame<br>transmission<br>Successful wake-<br>up transmission<br>Successful<br>header<br>transmission<br>Successful<br>wake-up<br>reception<br>Successful<br>wake-up<br>reception<br>Bit error<br>Physical bus error<br>Frame/response<br>timeout error<br>Framing error<br>Checksum error<br>Response<br>preparation error|

Each interrupt request is output when the corresponding bit in the RLN3nLIE register is 1 (interrupt is enabled) and the corresponding flag in the RLN3nLST register is 1.

## 25.5 Modes

The LIN Interface provides the following three modes, depending upon the specific function to be performed:

- LIN reset mode

- LIN mode (LIN master mode)

- LIN self-test mode

The supply of clocks to the LIN Interface is stopped in LIN reset mode, which reduces power consumption.

Figure 25.2 shows mode transitions. Table 25.28 describes mode transition conditions. Table 25.29 lists operations available in each mode.

**==> picture [327 x 237] intentionally omitted <==**

**----- Start of picture text -----**<br>
Power-on reset<br>(2)<br>LIN mode<br>LIN reset mode ● LIN master mode<br>(1)<br>(6)<br>(5)<br>LIN self-test mode<br>**----- End of picture text -----**<br>

**Figure 25.2 Mode Transitions**

**Table 25.28 Transition Condition of Each Mode**

||**Mode transition**|||**Transition condition**|
|---|---|---|---|---|
|1|LIN reset mode|→|LIN mode|RLN3nLMD.LMD = 00Band|
||||(LIN master mode)|RLN3nLCUC.OM1, OM0 = 01Bor 11B|
|2|LIN mode|→|LIN reset mode|RLN3nLCUC.OM0 = 0B|
|5|LIN reset mode|→|LIN self-test mode|See Section 25.8, LIN Self-Test Mode.|
|6|LIN self-test mode|→|LIN reset mode|See Section 25.8, LIN Self-Test Mode.|

**Table 25.29 Operations Available in Each Mode**

|**LIN mode**||
|---|---|
|**LIN master mode**|**LIN self-test mode**|
|Header transmission|Self test|
|Response transmission||
|Response reception||
|Wake-up transmission||
|Wake-up reception||
|Error detection||

Whether a transition has been caused to LIN reset mode or LIN mode can be verified by reading the LMD bits in the RLN3nLMD register or the OMM0 bit in the RLN3nLMST register.

For a description of the LIN self-test mode, see Section 25.8, LIN Self-Test Mode.

## 25.6 LIN Reset Mode

Setting the OM0 bit in the RLN3nLCUC register to 0 (LIN reset mode) causes a transition to LIN reset mode. The change to LIN reset mode can be verified by determining that the OMM0 bit in the RLN3nLMST register has been set to 0 (LIN reset mode). In this mode, the LIN communication function is halted.

When a DMA channel is activated by a LIN transfer request at the time of a transition to LIN reset mode, stop the channel.

For stopping a DMA channel, see Section 9., Direct Memory Access Controller .

From LIN reset mode, transitions to LIN mode and LIN self-test mode can be made.

When the mode changes to LIN reset mode, the following registers are initialized to their reset values, and as long as LIN reset mode is in effect, they retain their initial values.

- RLN3nLTRC register

- RLN3nLST register

- RLN3nLEST register

The following registers retain their previous values even when a transition to LIN reset mode is made:

- RLN3nLWBR register

- RLN3nLBRP0 register

- RLN3nLBRP1 register

- RLN3nLMD register

- RLN3nLBFC register

- RLN3nLSC register

- RLN3nLWUP register

- RLN3nLIE register

- RLN3nLEDE register

- RLN3nLDFC register

- RLN3nLIDB register

- RLN3nLCBR register

- RLN3nLDBRm register (m = 1 to 8)

## 25.7 LIN Mode

LIN mode can operate in the LIN master mode.

In LIN master mode, the following operations can be performed: header transmission, response transmission, response reception, wake-up transmission, wake-up reception, and error detection. In LIN reset mode, setting the LMD bits in the RLN3nLMD register to 00B (LIN master mode) and the OM1 and OM0 bits in the RLN3nLCUC register to either 01B or 11B sets LIN master mode, turning the OMM1 and OMM0 bits in the RLN3nLMST register to either 01B to 11B.

The LIN mode provides the following two operation modes:

- LIN operation mode

- LIN wake-up mode

Figure 25.3 shows the transition of operation modes. Table 25.30 describes the transition conditions of operation modes.

**==> picture [375 x 225] intentionally omitted <==**

**----- Start of picture text -----**<br>
LIN reset mode LIN mode<br>- LIN master mode<br>(3)<br>LIN operation<br>mode<br>(1)<br>(4) (5)<br>(2)<br>LIN wake-up<br>mode<br>**----- End of picture text -----**<br>

**Figure 25.3 Transition of Operation Modes**

**Table 25.30 Transition Conditions of Operation Modes**

||**Operation mode transition**||**Transition condition**|
|---|---|---|---|
|(1)|LIN reset mode|→LIN mode|RLN3nLMD.LMD = 00Band|
|||- LIN operation mode|RLN3nLCUC.OM1, OM0 = 11B|
|(2)|LIN reset mode|→LIN mode|RLN3nLMD.LMD = 00Band|
|||- LIN wake-up mode|RLN3nLCUC.OM1, OM0 = 01B|
|(3)|LIN mode|→LIN reset mode|RLN3nLCUC.OM0 = 0B|
||-LIN operation mode|||
||-LIN wake-up mode|||
|(4)|LIN mode|→LIN mode|RLN3nLCUC.OM1, OM0 = 01B|
|*1|-LIN operation mode|- LIN wake-up mode||
|(5)|LIN mode|→LIN mode|RLN3nLCUC.OM1, OM0 = 11B|
|*1|-LIN wake-up mode|- LIN operation mode||

Note 1. Transition between LIN operation mode and LIN wake-up mode cannot be made when communication is going on (when the FTS bit in the RLN3nLTRC register is 1).

## (1) LIN Operation Mode

In LIN operation mode, frame processing (header transmission, header reception, response transmission, response reception, and error detection) can be performed.

During a transition from LIN reset mode to LIN mode, setting the OM1 and OM0 bits in the RLN3nLCUC register to 11B changes the mode to LIN operation mode, changing the OMM1 and OMM0 bits in the RLN3nLMST register to 11B. Communication settings should be performed after the RLN3nLMST register has become 11B.

- (2) LIN Wake-up Mode

In LIN wake-up mode, wake-up signal processing (wake-up transmission, wake-up reception, and error detection) can be performed.

During a transition from LIN reset mode to LIN mode, setting the OM1 and OM0 bits in the RLN3nLCUC register to 01B changes the mode to LIN wake-up mode, changing the OMM1 and OMM0 bits in the RLN3nLMST register to 01B. Communication settings should be performed after the RLN3nLMST register has become 01B.

## 25.7.1 LIN Master Mode

## 25.7.1.1 Header Transmission

Figure 25.4 shows the operation of the LIN Interface (LIN master mode) in header transmission. Table 25.31 provides processing in header transmission.

**==> picture [396 x 110] intentionally omitted <==**

**----- Start of picture text -----**<br>
Header Response<br>Break delimiter Inter-byte space (header) Response space<br>Break ID + parity Data 1<br>Break field Sync field ID field<br>(1) (2) (3) (4) (5) (6) (7)<br>**----- End of picture text -----**<br>

**Figure 25.4 Operation in Header Transmission**

**Table 25.31 Processing in Header Transmission**

|**Software processing**|**LIN Interface processing**|
|---|---|
|(1)<br>Sets a baud rate<br>Sets noise filter ON/OFF<br>Enables interrupt<br>Enables error detection<br>Sets frame configuration parameters<br>Changes the LIN Interface to the LIN master mode: LIN<br>operation mode<br>Sets information on the frame to be transmitted (ID,<br>parity, data length, response direction, Checksum<br>method, and transmission data)|Waits for the setting of the FTS bit in the<br>RLN3nLTRC register by software (idle)|
|(2)<br>Sets the FTS bit in the RLN3nLTRC register to 1 (frame<br>transmission or wake-up transmission/reception started)|Transmits a break.|
|(3)<br>Waits for an interrupt request<br>(4)<br>(5)<br>(6)<br>(7)|Transmits a break delimiter.|
||Transmits a sync field (55h).|
||Transmits an inter-byte space (header).|
||Transmits an ID field.|
||Sets a successful header transmission flag.|

Note: For information about error detection, refer to Section 25.7.6, Error Status.

## 25.7.1.2 Response Transmission

Figure 25.5 shows the operation of the LIN Interface (LIN master mode) in response transmission. Table 25.32 provides processing in response transmission.

**==> picture [400 x 122] intentionally omitted <==**

**----- Start of picture text -----**<br>
Header Response<br>Response space Inter-byte space Inter-frame space<br>ID + parity Data 1 Data 2 Checksum<br>Data field Data field Checksum<br>(1) (2) (3)(4) (5) (6) (7)<br>Interrupt<br>**----- End of picture text -----**<br>

**Figure 25.5 Operation in Response Transmission**

**Table 25.32 Processing in Response Transmission**

|**Software processing**|**LIN Interface processing**|
|---|---|
|(1)<br>(When in frame separate mode)<br>Sets the RTS bit in the RLN3nLTRC<br>register to 1 (response transmission/<br>reception started)<br>(When not in frame separate mode)<br>Waits for an interrupt request|(When in frame separate mode)<br>Waits for the setting of the RTS bit in the RLN3nLTRC register<br>to 1 by software.<br>When the bit is set to 1, sends a response space.<br>(When not in frame separate mode)<br>Sends a response space.|
|(2)<br>Waits for an interrupt request<br>(3)<br>(4)<br>(5)<br>(6)|Transmits the data 1.|
||Transmits an inter-byte space.|
||Transmits the data 2.<br>Transmits an inter-byte space<br>Transmits the data 3.<br>Transmits an inter-byte space<br>(Repeats the transmission of inter-byte spaces as many times as<br>the data length specified in bits RFDL[3:0] in the RFC register.)<br>:<br>:|
||Transmits the checksum.|
||Sets a successful frame/wake-up transmission flag.<br>Sets the FTS bit in the RLN3nLTRC register to 0 (frame<br>transmission or wake-up transmission/reception stopped)<br>(When in frame separate mode), and the RTS bit in the<br>RLN3nLTRC register to 0 (response transmission/reception<br>stopped).|
|(7)<br>Processing after communication<br>Checks the RLN3nLST register, and<br>clears flags.|Idle|

Note: For information about error detection, refer to Section 25.7.6, Error Status.

## 25.7.1.3 Response Reception

Figure 25.6 shows the operation of the LIN Interface (LIN master mode) on response reception. Table 25.33 provides processing in response reception.

**==> picture [399 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
Header Response<br>Response space Inter-byte space Inter-frame space<br>ID + parity Data 1 Data 2 Checksum<br>Data field Data field Checksum<br>(1) (2) (3) (4) (5) (6)<br>Interrupt<br>**----- End of picture text -----**<br>

**Figure 25.6 Operation in Response Reception**

**Table 25.33 Processing in Response Reception**

|**Software processing**|**LIN Interface processing**|
|---|---|
|(1)<br>Waits for an interrupt request (no<br>processing).|Waits for detection of a start bit.|
|(2)<br>Waits for an interrupt request.<br>(3)<br>(4)<br>(5)|Receives the data 1 when the start bit is detected.|
||Sets the successful data 1 reception flag.|
||Receives the data 2 when the start bit is detected.<br>Receives the data 3 when the start bit is detected.<br>(Repeats the transmission of inter-byte spaces as many times as the<br>data length specified in bits RFDL[3:0] in the RLN3nLDFC register.)<br>:<br>:<br>Receives the checksum when the start bit is detected.|
||Determines the checksum.<br>Sets the successful frame/wake-up reception flag.<br>Sets the RTS bit in the RLN3nLTRC register to 0 (response<br>transmission/reception stopped).|
|(6)<br>Processing after<br>communication<br>Reads the received data.<br>Checks the RLN3nLST<br>register, and clears flags.|Idle|

Note: For information about error detection, refer to Section 25.7.6, Error Status.

## 25.7.2 Data Transmission/Reception

## 25.7.2.1 Data Transmission

One bit of data is transmitted per 1 Tbit.

The data that is transmitted returns to the reception data input pin via the LIN transceiver. The received data and the transmitted data is compared bit by bit, and the results are stored in the BER flag in the RLN3nLEST register (see Section 25.7.6, Error Status ).

In LIN mater mode, 1 Tbit is generated to be 16 fLIN, and thus the sampling point for received data is at the 13th clock cycle (81.25% position).

Figure 25.7 shows an example of data transmission timing.

**==> picture [394 x 221] intentionally omitted <==**

**----- Start of picture text -----**<br>
RLIN3nTX ST Data (8 bits) SP ST Data (8 bits) SP<br>Byte field<br>ST D0 D1 D2 D3 D4 D5 D6 D7 SP<br>Start bit Data (8 bits) Stop bit<br>fLIN<br>(Internal signal) 1 Tbit = 16 fLIN<br>Dn-1 Dn Dn+1<br>RLIN3nTX<br>Physical layer delay<br>RLIN3nRX Dn-1 Dn<br>Sampling point for<br>bit error detection<br>Synchronized RLIN3nRX Dn-1 Dn<br>13/16Tbit<br>**----- End of picture text -----**<br>

**Figure 25.7 Example of Data Transmission Timing (LIN Master Mode)**

## 25.7.2.2 Data Reception

Data reception is performed by using the synchronized RLIN3nRX signal (an internal signal) that is the input from the RLIN3nRX pin synchronized with prescaler clock.

The byte field is synchronized at the falling edge of the start bit for the synchronized RLIN3nRX signal. After the falling edge is detected, sampling is performed again a specified period of time later, and the falling edge is recognized as a start bit if the synchronized RLIN3nRX signal is low level. The falling edge is not recognized as a start bit if the RLIN3nRX signal after the clearing of the resetting is low-level-fixed or if a high level is detected on re-sampling.

After the start bit is detected, the system samples 1 bit per Tbit.

The LIN Interface has a noise filter function with respect to reception data. If the LRDNFS bit in the RLN3nLMD register is 0, the LIN Interface uses a noise filter, and for a sampling value the value determined by a 3-sampling majority rule on prescaler clocks is used. If the LRDNFS bit in the RLN3nLMD register is 1, the LIN Interface does not use a noise filter, and for a sampling value the value of the synchronized RLIN3nRX value at the sampling position is used as is.

Figure 25.8 shows an example of data reception timing.

**==> picture [388 x 175] intentionally omitted <==**

**----- Start of picture text -----**<br>
Byte field<br>RLIN3nRX ST D0 D1 D2 D3 D4 D5 D6 D7 SP<br>Start bit Data (8 bits) Stop bit<br>RLIN3nRX (Enlarged) Start bit D0 D1<br>Prescaler clock<br>(internal signal)<br>0.5 Tbit 1 Tbit (= 16 fLIN) 1 Tbit (= 16 fLIN)<br>Synchronized RLIN3nRX Start bit D0 D1<br>(internal signal)<br>Falling edge  Confirmed to be  Bit 0 is read 1  After that, data bit is<br>detection low 0.5 Tbit after  Tbit after confirmation  read every Tbit.<br>falling edge detection.  of a low level.<br>**----- End of picture text -----**<br>

**Figure 25.8 Example of Data Reception Timing**

## 25.7.3 Transmission/Reception Data Buffering

This section explains the buffer processing that takes place when the LIN Interface sends or receives data continuously.

## 25.7.3.1 Transmission of LIN Frames

For an 8-byte transmission, the contents stored in registers RLN3nLDBR1 to RLN3nLDBR8 are sequentially transmitted to data areas 1 to 8 of the LIN frame. In the case of a 4-bytes transmission, the contents stored in registers RLN3nLDBR1 to RLN3nLDBR4 are transmitted to data areas 1 to 4 of the LIN frame, but the contents of registers RLN3nLDBR5 to RLN3nLDBR8 are not transmitted. The transmitted checksum data is stored in the RLN3nLCBR register.

Figure 25.9 depicts the LIN transmission processing and the required buffer.

**==> picture [392 x 203] intentionally omitted <==**

**----- Start of picture text -----**<br>
Buffer<br>RLN3nLDBR1 register<br>RLN3nLDBR2 register<br>RLN3nLDBR3 register<br>RLN3nLDBR4 register<br>RLN3nLDBR5 register<br>RLN3nLDBR6 register<br>RLN3nLDBR7 register<br>RLN3nLDBR8 register<br>RLN3nLCBR register<br>Data 1 Data 2 Data 8 Checksum<br>Header Response<br>Frame<br>**----- End of picture text -----**<br>

## **Figure 25.9 LIN Transmission Processing and Required Buffer**

## (1) Frame Separate Mode

Setting the FSM bit in the RLN3nLDFC register to 1 turns on the frame separate mode.

In frame separate mode, a header and a response are transmitted when prompted by separate transmission start requests.

When the transmission of a header is finished, the HTRC flag in the RLN3nLST register turns 1 (successful header transmission).

Use frame separate mode when sending or receiving response data of 9 bytes or greater in LIN master mode.

## 25.7.3.2 Reception of LIN Frames

For an 8-byte reception, the contents of data areas 1 to 8 of the LIN frame is stored in registers RLN3nRLN3nLDBR1 to RLN3nLDBR8, respectively, upon receipt of a stop bit. In the case of a 4- byte reception, the contents of data areas 1 to 4 of the LIN frame are stored in registers RLN3nLDBR1 to RLN3nLDBR4, respectively; however, no data is stored in registers RLN3nLDBR5 to RLN3nLDBR8. Also, the received checksum data is stored in the RLN3nLCBR register.

Figure 25.10 depicts the LIN reception processing and the required buffer.

**==> picture [392 x 207] intentionally omitted <==**

**----- Start of picture text -----**<br>
Frame<br>Header Response<br>Data 1 Data 2 Data 8 Checksum<br>Buffer<br>RLN3nLDBR1 register<br>RLN3nLDBR2 register<br>RLN3nLDBR3 register<br>RLN3nLDBR4 register<br>RLN3nLDBR5 register<br>RLN3nLDBR6 register<br>RLN3nLDBR7 register<br>RLN3nLDBR8 register<br>RLN3nLCBR register<br>**----- End of picture text -----**<br>

**Figure 25.10 LIN Reception Processing and Required Buffer**

- (1) Reception of Data 1

When the reception of the first byte of data is finished, the D1RC flag in the RLN3nLST register turns 1 (successful data 1 reception).

## 25.7.3.3 Multi-Byte Response Transmission/Reception Function

Normally in LIN communications, a response is 9 bytes or less including a checksum field; however, responses in 10 bytes or greater can also be sent and received.

In such a case, the bit error, framing error, response preparation error detection, and auto checksum functions are enabled.

If the data length is greater than 8 bytes, the LSS bit in RLN3nLDFC register should be set to 1 (indicating that the next data group to be sent or received is not the final data group) in the first data group (variable in 0 to 8 bytes) before sending or receiving the data group. After the transmission or reception, the user should determine whether the next data group is the final data group. If it is the final data group, the LSS bit should be set to 0 (indicating that the next data group to be sent or received is the final data group, and a checksum should be appended to the final data group.

By changing the RFDL bit in RLN3nLDFC register settings when the RTS bit in RLN3nLTRC register is 0, the user can change the data length for each data group.

When performing multi-byte response transmission/reception in LIN master mode, set the FSM bit in RLN3nLDFC register in the RLN3nLDFC register to 1 (frame separate mode).

## 25.7.4 Wake-up Transmission/Reception

The wake-up transmission/reception can be used in LIN wake-up mode.

## 25.7.4.1 Wake-up Transmission

In LIN wake-up mode, setting the RCDS bit in the RLN3nLDFC register to 1 (transmission) and the FTS bit in the RLN3nLTRC register to 1 (header reception or wake-up transmission/reception started) causes a wake-up signal to be output from the output pin. The low level width of the wake-up signal should be set using the WUTL[3:0] bits in the RLN3nLWUP register.

However, if the LWBR0 bit of the RLN3nLWBR register is 1 (LIN2.x use), the LIN system clock (fLIN) becomes low level width at fa regardless of the setting of the LCKS bit of the RLN3nLMD register.

By setting the baud rate to 19200 bps while fa is selected and the WUTL[3:0] bits of the RLN3nLWUP register to 0100B (5 Tbits), 260 μs low width can be output in LIN wake-up mode regardless of the setting of the LCKS bit of the RLN3nLMD register.

If a wake-up low is output without any bit error, the FTC flag in the RLN3nLST register turns 1 (successful frame response or wake-up transmission); when the FTCIE bit in the RLN3nLIE register is 1 (successful frame response/wakeup transmission interrupt enabled), an interrupt request is generated.

If RLN3nLEDE.BERE is set and a bit error is detected, wake-up transmission is canceled and the BER flag in the RLN3nLEST register is set to 1 (bit error detection).

When RLN3nLEDE.PBERE is set, set RLN3nLEST.PBER flag to 1 (physical bus error detection) at the same time of a bit error.

Figure 25.11 shows the wake-up transmission timing.

**==> picture [406 x 66] intentionally omitted <==**

**----- Start of picture text -----**<br>
RLIN3nTX<br>Low width configuration (1 to 16 Tbits)<br>FTC bit in RLIN3nLST registe r<br>**----- End of picture text -----**<br>

**Figure 25.11 Wake-up Transmission Timing**

## 25.7.4.2 Wake-up Reception

The detection of a wake-up involves the use of an input signal low level width count function.

The input signal low level width count function measures the low width of the input signal to the RLIN3nTX pin, using the same sampling point as data reception. The function can measure the input signal low level width of 2.5 Tbits of fLIN or greater.

By setting the LWBR0 bit in the RLN3nLWBR register, operation is executed without changing the baud rate generator setting at a transition between LIN operation mode and LIN wake-up mode.

When LIN Specification Package Revision 1.3 is used, set the LWBR0 bit in the RLN3nLWBR register to 0. When LIN Specification Package Revision 2.x is used, set the LWBR0 bit to 1. Setting the LWBR0 bit to 1 selects the LIN system clock (fLIN) to fa regardless of the setting of the LCKS bit in the RLN3nLMD register. (The LCKS bit is not changed). By setting the baud rate to 19200 bps while fa is selected, the 130 μs or longer low-level width of the input signal to be measured regardless of the setting of the LCKS bit in the RLN3nLMD register.

When using the wake-up reception function, in LIN wake-up mode set the RFT bit in the RLN3nLDFC register to 0 (response reception), and then the FTS bit in the RLN3nLTRC register to 1 (frame transmission (header reception) or wake-up transmission/reception started).

When the low level width to be measured is reached, the FRC flag in the RLN3nLST register turns 1 (successful frame response/wake-up reception). If the FRCIE bit in the RLN3nLIE register is 1 (successful frame response or wake-up reception interrupt enabled), an interrupt request for successful LINn reception is generated.

**==> picture [399 x 165] intentionally omitted <==**

**----- Start of picture text -----**<br>
RLIN3nRX<br>FRC bit in RLN3nLST<br>Wake-up detection width<br>(2.5Tbits)<br>FRC bit set timing in RLN3nLST<br>                                  (3.0Tbits)<br>**----- End of picture text -----**<br>

**Figure 25.12 Input Signal Low level Count Function**

## 25.7.4.3 Wakeup Collision

If the master node and the slave node transmit wakeup signals simultaneously, a collision will occur on the LIN bus, though a collision of wakeup signals is not detected in the LIN interface.

## 25.7.5 Status

During LIN mode operation, the LIN Interface can detect seven types of statuses.

The four statuses, successful frame/wake-up transmission, successful frame/wake-up reception, error detection, successful header transmission/header reception, can generate interrupt requests.

Table 25.34 shows the types of statuses available in LIN master mode.

## **Table 25.34 Types of Statuses in LIN Master Mode**

|||||**Operation mode**|**Operation mode**|||
|---|---|---|---|---|---|---|---|
|||||**capable of status**||**Corresponding**||
|**Status**|**Status set condition**|**Status clear condition**||**detection**||**bit**|**Interrupt**|
|Reset|After the OM0 bit in the RLN3nLCUC|After the OM0 bit in the||All modes||OMM0 bit in|―|
||register is set to LIN reset mode|RLN3nLCUC register is set to 0||||RLN3nLMST||
||(OM0 = 0), if the LIN Interface enters|(LIN|reset mode is canceled), if LIN|||register||
||LIN reset mode.|reset mode is canceled.||||||
|Operation|After the OM1 bit in the RLN3nLCUC|After the OM1 bit in the|||LIN operation mode|OMM1 bit in|―|
|mode|register is set to LIN operation mode,<br>if actually the LIN Interface enters|RLN3nLCUC register is set to LIN<br>wake-up mode, if actually the LIN|||LIN wake-up mode|RLN3nLMST<br>register||
||LIN operation mode.|Interface enters LIN wake-up mode.||||||
|Frame/wake-up|When a frame (header transmission||When another communication||LIN operation mode|FTC flag in|√|
|transmission<br>end|+ response transmission), a wake-<br>up signal, or a data group is||is started (When the FTS bit in<br>the RLN3nLTRC register is set)||LIN wake-up mode|RLN3nLST<br>register||
||transmitted successfully.||When cleared by software|||||
||||After transition to LIN reset|||||
||||mode|||||
|Frame/wake-up|When a frame (header transmission||When another communication||LIN operation mode|FRC flag in|√|
|reception end|+ response reception), a wake-up<br>signal, or a data group is received||is started (When the FTS bit in<br>the RLN3nLTRC register is set)||LIN wake-up mode|RLN3nLST<br>register||
||successfully.||When cleared by software|||||
||||After transition to LIN reset|||||
||||mode|||||
|Error detection|If any of the RPER flag, CSER flag,||When another communication||LIN operation mode|ERR flag in|√|
||FER flag, FTER flag, PBER flag, and<br>BER flags in the RLN3nLEST||is started (When the FTS bit in<br>the RLN3nLTRC register is set)||LIN wake-up mode|RLN3nLST<br>register||
||register turns 1 (error detected).||When cleared by software|||||
||||After transition to LIN reset|||||
||||mode|||||
|Data 1|The RFT bit in the RLN3nLDFC||When another communication|LIN operation mode||D1RC flag in|―|
|reception end|register is 0 (reception) and the first||is started (When the FTS bit in|||RLN3nLST||
||byte of the response field or the first||the RLN3nLTRC register is set)|||register||
||byte of each data group is<br>received.*2|<br>|When cleared by software<br>After transition to LIN reset|||||
||||mode|||||
|Header|When a header field is transmitted||When another communication|LIN operation mode||HTRC flag in|√|
|transmission|successfully.||is started|||RLN3nLST||
|end|||When cleared by software|||register||
||||After transition to LIN reset|||||
||||mode|||||

Note 1. In LIN operation mode, the ERR flag in the RLN3nLST register is cleared to 0 by writing 0 to the RPER flag, CSER flag, FER flag, FER flag, FTER flag, PBER flag or BER flags in the RLN3nLEST register.

Note 2. Not detected when the RFDL [3:0] bits in the RLN3nLDFC register are 0000B (0-byte + checksum).

## 25.7.6 Error Status

## 25.7.6.1 LIN Master Mode

## (1) Types of Error Statuses

The LIN Interface can detect six types of error statuses in LIN master mode. The condition of these error statuses can be checked by means of the corresponding bits in the RLN3nLEST register.

All error statuses represent interrupt events.

Table 25.35 shows the types of error statuses .

## **Table 25.35 Types of Error Statuses in LIN Master Mode**

|||||**Enable/**||
|---|---|---|---|---|---|
|||**Operation mode capable**|**Commu**|**disable**|**Corresponding**|
|**Status**|**Error detection condition**|**of error detection**|**nication**|**detection**|**bit**|
|Bit error|The transmitted data and the data on the LIN|LIN operation mode|Cancel|√|BER flag in|
||bus monitored by the receive pin do not match<br>*1*2|LIN wake-up mode|||RLN3nLEST<br>register|
|Physical|LIN bus is detected to be high level when|LIN operation mode|Cancel|√|PBER flag in|
|bus error|sending a break<br>LIN bus is detected to be low level when|LIN wake-up mode|||RLN3nLEST<br>register|
||sending a break delimiter|||||
||LIN bus is detected to be high level when|||||
||sending a wake-up|||||
|Timeout|A frame or response transmission/reception|LIN operation mode|Cancel|√|FTER flag in|
|error|does not terminate within a given time*3||||RLN3nLEST|
||||||register|
|Framing|In response field reception, a stop bit of each|LIN operation mode|Cancel|√|FER flag in|
|error|data byte is low level||||RLN3nLEST|
||||||register|
|Checksum|In response field reception, the result of|LIN operation mode|—|×|CSER flag in|
|error|checksum test gives an error||||RLN3nLEST|
||||||register|
|Response|One of the following conditions occurs in frame|LIN operation mode|Cancel|×|RPER flag in|
|preparation|separate mode during a multi-byte response||||RLN3nLEST|
|error|reception:||||register|
||The first reception data byte is received after|||||
||completion of header transmission but|||||
||before a response transmission/reception|||||
||request is set|||||
||The first reception data byte is received after|||||
||the completion of previous data group|||||
||reception before a transmission/reception|||||
||request for another data group is sett|||||

Note 1. If a bit error is detected, the process is canceled after a stop bit is sent. If a bit error is detected in a nondata area, such as an inter-byte space, the transmission is canceled immediately after that area. If a bit error is detected during the transmission of a wake-up, the transmission of the wake-up is canceled after the error-causing bit is sent.

Note 2. In a multi-byte response transmission, bit errors are detected also between data groups.

Note 3. The timeout time depends on the response field data length (the RFDL [3:0] bits in the RLN3nLDFC register) and the checksum selection (the CSM bit in the RLN3nLDFC register), and this can be calculated according to the following formula.

When the setting of the FSM bit in the RLN3nLDFC register is 1 (i.e., frame separation mode), the timeout time is that for eight bytes until the RTS bit of the RLN3nLTRC register is set. Once the RTS bit is set, the timeout time is re-set to the time based on the response field data length (the RFDL[3:0] bits in the RLN3nLDFC register).

[Frame timeout]

On classic selection (when the CSM bit in RLN3nLDFC is 0): Timeout time = 49 + (number of data bytes + 1) × 14 [Tbit]

On enhanced selection (when the CSM bit in RLN3nLDFC is 1): Timeout time = 48 + (number of data bytes + 1) × 14 [Tbit]

The aforementioned timeout time is a time greater than the TFRAME_MAX of LIN Specification Package Revision 1.3 on classic selection, or the TFRAME_MAX of LIN Specification Package Revision 2.x on enhanced selection.

[Response timeout] Timeout time = (number of data bytes + 1) × 14 [Tbit] When an error is detected, time-out error detection function stops.

The error status is cleared when the next communication is started (when the FTS bit in the RLN3nLTRC register is set), by software, or at a transition to LIN reset mode.

- (2) Target Time Area for LIN Error Detection

Figure 25.13 shows the time domain in which the LIN Interface in master mode performs monitoring for error detection.

**==> picture [390 x 322] intentionally omitted <==**

**----- Start of picture text -----**<br>
<Frame transmission/reception><br>Frame<br>Header Response<br>Break field Sync field ID field Data 1 Data 2 Data 8 Checksum<br>Bit error In transmission only<br>Only in<br>transmission of<br>Physical bus error break field and  break delimiter<br>Only in reception<br>Checksum error checksum mode with enhance  In reception only<br>selected<br>Frame timeout error<br>Response timeout error<br>Framing error<br>Only stop bit in reception<br>Response preparation error<br><Wake-up transmission><br>Wake-up<br>Bit error<br>Physical bus error<br>**----- End of picture text -----**<br>

**Figure 25.13 Target Time Area for LIN Error Detection (LIN Master Mode)**

## 25.8 LIN Self-Test Mode

When the LIN interface enters the LIN self-test mode, RLIN3nTX and RLIN3nRX are  disconnected from external pins and RLIN3nTX and RLIN3nRX are connected in the LIN  interface. Therefore, the frame transmitted from RLIN3nTX is looped back to RLIN3nRX.

The LIN self-test mode can perform tests exclusively in LIN mode.

The self-test can be performed in the following two types.

- LIN master self-test mode (transmission): Header transmission and response transmission

- LIN master self-test mode (reception): Header transmission and response reception

In LIN self-test mode, the operate is at the fastest baud rate, regardless of the setting of the baud rate generator,

Regardless of the setting of the baud rate related registers, the baud rate operates at the LIN communication clock source/16 [bps]. (The NSPB bits in the RLN3nLWBR register should be set to 0000B or 1111B.)

(The LPRS bits in the RLN3nLWBR register should be set to 000B.)

In addition, in LIN self-mode, the following functions are not supported.

- LIN wake-up mode

- Frame separate mode

- Multi-byte response transmission/reception

- Frame/response timeout error

**==> picture [279 x 154] intentionally omitted <==**

**----- Start of picture text -----**<br>
Internal RLIN3nTX<br>RLIN3nTX pin<br>LIN controller<br>Input to or output from LIN transceiver<br>RLIN3nRX pin<br>Internal RLIN3nRX<br>**----- End of picture text -----**<br>

**Figure 25.14 Connection in LIN Reset Mode and LIN Mode**

**==> picture [279 x 154] intentionally omitted <==**

**----- Start of picture text -----**<br>
Internal RLIN3nTX<br>RLIN3nTX pin<br>LIN controller Input to or output from LIN transceiver<br>RLIN3nRX pin<br>Internal RLIN3nRX<br>**----- End of picture text -----**<br>

**Figure 25.15 Connection in LIN Self-Test Mode**

## 25.8.1 Change to LIN Self-Test Mode

Writing to the RLN3nLSTC register makes a transition to the LIN self-test mode.

When the LSTM bit in the RLN3nLSTC register is set to 1, the shift to the LIN self-test mode is checked.

When changing to LIN self-test mode, be sure to execute a specific sequence. In that sequence,

information must be written three times consecutively to the LIN self-test control register, as follows:

- Change to LIN reset mode

   - Set the OM0 bit in the RLN3nLCUC register to 0 (LIN reset mode).

   - Read the OMM0 bit in the RLN3nLMST register; verify that it is 0 (LIN reset mode).

- Select a LIN mode

LMD bits in RLN3nLMD = 00B (LIN master mode)

- 1st write: RLN3nLSTC register = 1010 0111B (A7H)

- 2nd write: RLN3nLSTC register = 0101 1000B (58H)

- 3rd write: RLN3nLSTC register = 0000 0001B (01H)

- Verify the transition to LIN self-test mode

Read the LSTM bit in the RLN3nLSTC register; verify that it is 1 (LIN self-test mode).

If the key of the first write (A7H) is written twice by mistake, the transition to LIN self-test mode is canceled. The above sequence should be retried from the step of first write. In addition, if a write to another LIN-related register is performed during transition to LIN self-test mode (three consecutive write operations to the RLN3nLSTC register), the transition is also canceled.

## 25.8.2 Transmission in LIN Master Self-Test Mode

To execute a self-test on LIN master transmission, perform the procedure below:

- Set the baud rate, noise filter, and interrupt output related registers. RLN3nLWBR register = 0000000xB RLN3nLBRP0 register = xxxxxxxxB *[1] RLN3nLBRP1 register = xxxxxxxxB *[1] RLN3nLMD register = 00xxxx00B *[1]

- Set the interrupt enable and error enable related registers. RLN3nLIE register = 0000xxxxB *[2] RLN3nLEDE register = x000x0xxB

- Set the break field and space related registers. RLN3nLBFC register = 00xxxxxxB RLN3nLSC register = 00xx0xxxB

- Cancel the LIN reset mode. Write 11B to the OM1 and OM0 bits in the RLN3nLCUC register, and check that the OMM1 and OMM0 bits in the RLN3nLMST register are 11B.

- Set the transmit frame related registers. RLN3nLDFC register = 00x1xxxxB RLN3nLIDB register = xxxxxxxxB

   - RLN3nLDRB1 to RLN3nLDRB8 registers = xxxxxxxxB

- Header transmission → response transmission started Set the FTS bit in the RLN3nLTRC register to 1 (frame transmission or wake-up transmission/ reception started).

   - The LIN master self-test mode (transmission) is executed. In this mode, interrupts are generated, and status and error status are also updated. The checksum is automatically calculated by the LIN interface. To suspend the LIN master self-test mode (transmission) being executed, write 0 (LIN reset mode) to the OM0 bit in the RLN3nLCUC register for transition to LIN reset mode.

- When the transmission is completed, the reversed value of the looped-back frame data is stored in the RLN3nLIDB, RLN3nLDBRm (m = 1 to 8), and RLN3nLCBR registers (the data is reversed before being stored because the transmitted value should be compared with the looped-back value). Then, the FTS bit in the RLN3nLTRC register is cleared.

- If the transmission fails to complete due to an error, the applicable error flag is set and the FTS bit in the RLN3nLTRC register is cleared.

Note: x: Don’t care

- Note 1. The following register settings are not reflected to the operation of the LIN self-test mode: the RLN3nLBRP0 register, the RLN3nLBRP1 register,  and the LCKS bit in the RLN3nLMD register. Therefore, those settings are not necessary.

- Note 2. When the successful header transmission interrupt and the successful frame transmission interrupt are used in the same interrupt processing, if the software processing of the successful header transmission interrupt is not completed before the generation of the successful frame transmission interrupt, the SHIE bit in the RLN3nLIE register should not be set to 1 (successful header transmission interrupt enabled). The time required from the set of the successful header transmission flag to the set of the successful frame/wake-up transmission flag is calculated by the following formula.

10 × (number of data bytes + 1) [Tbit]

1 Tbit = LIN communication clock source × 16

## 25.8.3 Reception in LIN Master Self-Test Mode

To execute a self-test on LIN master reception, perform the procedure below:

- Set the baud rate, noise filter, and interrupt output related registers. RLN3nLWBR register = 0000000xB RLN3nLBRP0 register = xxxxxxxxB *[1] RLN3nLBRP1 register = xxxxxxxxB *[1] RLN3nLMD register = 00xxxx00B *[1]

- Set the interrupt enable and error enable related registers. RLN3nLIE register = 0000xxxxB *[2] RLN3nLEDE register = x000x0xxB

- Set the break field and space related registers. RLN3nLBFC register = 00xxxxxxB RLN3nLSC register = 00xx0xxxB *[1]

- Cancel the LIN reset mode. Write 11B to the OM1 and OM0 bits in the RLN3nLCUC register, and check that the OMM1 and OMM0 bits in the RLN3nLMST register are 11B.

- Set the reception frame related registers. RLN3nLDFC register = 00x0xxxxB *[3] RLN3nLIDB register = xxxxxxxxB RLN3nLDBR1 to RLN3nLDBR8 registers = xxxxxxxxB

RLN3nCBR register = xxxxxxxxB

Since the checksum value to be transmitted is not automatically calculated, set the calculation value to the RLN3nLCBR register. If an incorrect checksum is set at this time, the checksum error can be tested.

- Header transmission → response reception started Set the FTS bit in the RLN3nLTRC register to 1 (frame transmission or wake-up transmission/ reception started).

The LIN master self-test mode (reception) is executed. In this mode, interrupts are generated, and status and error status are also updated. To suspend the LIN master self-test mode (reception) being executed, write 0 (LIN reset mode) to the OM0 bit in the RLN3nLCUC register for transition to LIN reset mode.

- When the reception is completed, the reversed value of the looped-back frame data is stored in the RLN3nLIDB, RLN3nLDBRm (m = 1 to 8), and RLN3nLCBR registers (the data is reversed before being stored because the set value should be compared with the looped-back value). Then, the FTS bit in the RLN3nLTRC register is cleared.

- If the reception fails to complete due to an error, the applicable error flag is set and the FTS bit in the RLN3nLTRC register is cleared.

Note: x: Don’t care

- Note 1. The following register settings are not reflected to the operation of the LIN self-test mode: the RLN3nLBRP0 register, the RLN3nLBRP1 register, the LCKS bit in the RLN3nLMD register, and the IBS bit in the RLN3nLSC register. Therefore, those settings are not necessary.

   - Note 2. When the successful header transmission interrupt and the successful frame reception interrupt are used in the same interrupt processing, if the software processing of the successful header transmission interrupt is not completed before the generation of the successful frame reception interrupt, the SHIE bit in the RLN3nLIE register should not be set to 1 (successful header transmission interrupt enabled).

      - The time required from the set of the successful header transmission flag to the set of the successful frame/wake-up reception flag is calculated by the following formula.

      - 10 × (number of data bytes + 1) [Tbit]

      - 1 Tbit = LIN communication clock source × 16

   - Note 3. When the reception is in self-test mode, be sure to set the response field length (RFDL bits) to at least 1 byte.

- 25.8.4 Terminating LIN Self-Test Mode

To terminate LIN self-test mode, perform the procedure below:

- Write 0 (LIN reset mode) to the OM0 bit in the RLN3nLCUC register. If the OMM1 and OMM0 bits in the RLN3nLMST register are not 11B, write 11B to the OM1 and OM0 bits in the RLN3nLCUC register. After confirming that the OMM1 and OMM0 bits in the RLN3nLMST register have turned 11B, change to LIN reset mode.

- Verify the cancelation of LIN self-test mode. Read the LSTM bit in the RLN3nLSTC register; confirm that it is not 0 (not in LIN self-test)

- Verify the transition to LIN reset mode.

Read the OMM0 bit in the RLN3nLMST register; verify that it is 0 (LIN reset mode).

## 25.9 Baud Rate Generator

The prescaler clock is obtained by frequency-dividing the LIN communication clock source by the prescaler, and the LIN system clock (fLIN) is obtained by frequency-dividing the prescaler clock by the baud rate generator. The clock obtained by frequency-dividing the LIN system clock (fLIN) by the number of samples is the baud rate. The reciprocal of this baud rate is called the bit time (Tbit).

The LIN Interface has two kinds of baud rate generators. The baud rate generators switch over according to the mode used.

## 25.9.1 LIN Master Mode

Figure 25.16 shows a block diagram of baud rate generation in LIN master mode.

**==> picture [389 x 168] intentionally omitted <==**

**----- Start of picture text -----**<br>
LIN baud rate<br>prescaler 0  fa<br>Prescaler clock (RLN3nLBRP0 register) fLIN<br>*2<br>1/2<br>LIN communication clock source*1 Prescaler (LPRS[2:0] bits) 1/8 fb Bit sampling 1/16 (NSPB[3:0] bits) Baud rate<br>fc<br>LIN baud rate<br>prescaler 1  1/2 fd<br>(RLN3nLBRP1 register)<br>*3<br>Baud rate generator<br>**----- End of picture text -----**<br>

LCKS[1:0] bits in RLN3nLMD register

Note 1. For the LIN communication clock source, refer to **section 6, Clock Pulse Generator** . Note 2. When the value in RLN3nLBRP0 register is N (N = 0 to 255), the clock frequency is divided by N + 1. Note 3. When the value in RLN3nLBRP1 register is M (M = 0 to 255), the clock frequency is divided by M + 1.

## **Figure 25.16 Block Diagram of Baud Rate Generation in LIN Master Mode**

By setting the RLN3nLBRP0 register so that fa is 307200 Hz (= 19200 × 16), the resulting bit rates are fa = 19200 × 16, fb = 9600 × 16 and fc = 2400 × 16. These bit rates are frequency-divided by 16 in the bit timing generator, enabling bit rates of 19200 bps, 9600 bps and 2400 bps to be generated. Also, by setting the RLN3nLBRP1 register so that fd is 166672 Hz (= 10417 × 16), the resulting bit rate is fd = 10417 × 16. This bit rate is frequency-divided by 16 in the bit timing generator, enabling 10417 bps to be generated.

The equation for calculating the baud rate is given below.

Baud rate of LIN master

- = {Frequency of LIN communication clock source} × (RLN3nLWBR.LPRS[2:0] selection clock) ÷ (RLN3nLBRP0 + 1) ÷ 16 [bps] (When fa is selected for fLIN)

- = {Frequency of LIN communication clock source} × (RLN3nLWBR.LPRS[2:0] selection clock) ÷ (RLN3nLBRP0 + 1) ÷ 2 ÷ 16 [bps] (When fb is selected for fLIN)

- = {Frequency of LIN communication clock source} × (RLN3nLWBR.LPRS[2:0] selection clock)

- ÷ (RLN3nLBRP0 + 1) ÷ 8 ÷ 16 [bps] (When fc is selected for fLIN)

- = {Frequency of LIN communication clock source} × (RLN3nLWBR.LPRS[2:0] selection clock) ÷ (RLN3nLBRP1 + 1) ÷ 2 ÷ 16 [bps] (When fd is selected for fLIN)

## 25.9.2 Noise Filter

The LIN Interface has a noise filter for reducing erroneous receiving of data due to noise. By setting the LRDNFS bit in the RLN3nLMD register to 0 (to use the noise filter), the noise filter is activated. The noise filter samples the level of the synchronized RLIN3nRX with the prescaler clock, and outputs the sampling value determined by a 3-sampling majority rule. The value of each bit of the receive data is determined based on the noise filter output.

Figure 25.17 shows the configuration of the noise filter, Figure 25.18 an example of a noise filter circuit, and Figure 25.19 the determination of the received data when the noise filter is used.

**==> picture [412 x 431] intentionally omitted <==**

**----- Start of picture text -----**<br>
Sampling clock<br>Prescaler clock<br>Noise filter output<br>LRDNFS bit in<br>RLN3nLMD register<br>Noise filter 0<br>Synchronized RLIN3nRX (3-sampling<br>majority circuit)<br>1<br>Figure 25.17 Configuration of Noise Filter<br>Noise filter<br>Synchronized<br>RLIN3nRX<br>FF1<br>Majority  Noise filter output<br>circuit<br>FF2<br>Prescaler clock<br>**----- End of picture text -----**<br>

**Figure 25.18 Example of Noise Filter Circuit**

**==> picture [396 x 348] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start Bit Bit Bit Bit Bit Bit Bit Bit Stop<br>Bit 0 1 2 3 4 5 6 7 Bit<br>RLIN3nRX<br>Start<br>Bit<br>Synchronized RLIN3nRX Start<br>(internal signal) Bit<br>Signal 1 for decision<br>by majority of 3 sampling Start<br>[FF1 output signal] Bit<br>(internal signal)<br>by majority of 3 sampling Signal 2 for decision  Start<br>[FF2 output signal] Bit<br>(internal signal)<br>Start<br>Noise filter output Bit<br>Prescaler clock<br>[Determination of data while noise filter is enabled]<br>Start<br>Noise filter output Bit<br>Sampling clock<br>Sampling point<br>[Determination of data while noise filter is disabled]<br>Start<br>Synchronized RLIN3nRX Bit<br>(internal signal)<br>Sampling clock<br>Sampling point<br>**----- End of picture text -----**<br>

**Figure 25.19 Determination of Received Data when Noise Filter is Used**
