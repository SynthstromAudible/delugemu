# Revision History

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2846–2867. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

Revision History RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User’s Manual: Hardware

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|1.00|Aug 30, 2013|―|First edition, issued|
|2.00|May 25, 2015|All|Erroneous pin names, register names, and bit names corrected|
|||1. Overview||
|||1-2 to<br>1-6|Table 1.1 RZ/A1L Features: Specification of CPU, IEBusTMcontroller, and capture engine unit corrected|
|||1-9|Figure 1.1 Pin Assignment of the 176-pin BGA (Upper Perspective View) corrected|
|||1-10|Figure 1.2 Pin Assignment of the 176-pin QFP (Top View) corrected|
|||1-11|Figure 1.3 Pin Assignment of the 208-pin QFP (Top View) corrected|
|||1-14, 1-<br>16, 1-<br>17|Table 1.3 Pin Functions:<br>Note added to TIOC0A, TIOC0B, TIOC0C, and TIOC0D, function of TIOC4A, TIOC4B, TIOC4C, and TIOC4D<br>corrected, function of REFRIN corrected, function of A/D converter corrected, and name of the symbol of general<br>I/O port corrected|
|||1-18, 1-<br>19, 1-<br>21|Table 1.4 List of Pins:<br>I/O of D31 to D0 corrected (I/O corrected to I(s)/O), I/O of WAIT<br>corrected (O corrected to I(s)), symbol of Port<br>function/dedicated function corrected (VBUSIN1 corrected to VBUS1, VBUSIN0 corrected to VBUS0)|
|||1-22|Figure 1.4 (2) Simplified Circuit Diagram (TTL AND Input Buffer) corrected|
|||2. CPU||
|||2-1|2.1 Features: Note 2 added|
|||4. Secondary Cache||
|||4-1|Table 4.1 Setting Values of Configuration Signals: Setting value of ASSOCIATIVITY corrected and note 2 corrected|
|||5. LSI Internal Bus||
|||5-2|Figure 5.2 North Main Bus Configuration corrected (write buffer added)|
|||5-7|Table 5.5 Address Map: "Upper" in the area name deleted|
|||5-12|5.8 AXI Protocol Control Signal: Body corrected|
|||5-13|5.9 Write Buffers: Body corrected|
|||6. Clock Pulse Generator||
|||6-3|(1) Crystal Oscillator: Description corrected|
|||6-5|Table 6.2 Input/Output Clock Frequency: Pin name corrected (MD_CLK0MD_CLK)|
|||6-7|6.4.1 Frequency Control Register (FRQCR): Description of CKOEN[1:0] bits corrected (Table 6.6 corrected to Table<br>6.7)|
|||6-15 to<br>6-19|6.10 Clock Signals: Newly added|
|||7. Interrupt Controller||
|||7-1|7.1 Features: Body corrected and ARM PrimeCell®generic interrupt controller (PL390) added|
|||7-3|7.3 Register Descriptions: Body corrected|
|||7-3,<br>7-12|Table 7.2 Register Configuration: Superscript "*3" added to the initial value of the interrupt controller type register<br>Table 7.2 Register Configuration: Note 1 corrected and Note 3 added|
|||7-15|7.3.3 IRQ Interrupt Request Register (IRQRR): Description of bits IRQ7F to IRQ0F corrected|
|||7-16|7.4 Interrupt Sources: Erroneous description corrected|
|||7-16|7.4.1 NMI Interrupt: Body corrected|
|||7-16|7.4.2 IRQ Interrupts: Body corrected|
|||7-17|7.4.3 On-Chip Peripheral Module Interrupts: Body corrected|
|||7-17|7.4.4 Pin Interrupts: Body corrected|
|||7-18|7.5 Interrupt IDs: Body corrected|
|||7-25|Table 7.3 List of Interrupt IDs: Entry under "ICDICFRn" for interrupt ID 240 corrected|
|||7-28|Table 7.3 List of Interrupt IDs: Request source names of LIN interface corrected|
|||7-35|7.6.1 Initial Settings: Body corrected|
|||7-37|7.6.2 Flow of Interrupt Operations: Body corrected|
|||7-39|7.8.3 Notes on Reading Interrupt ID Values from Interrupt Acknowledge Register (ICCIAR): Body corrected|

Revision History-1

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|8. Bus State Controller||
|||8-1|8.1 Features: Erroneous description of item 10 corrected|
|||8-4|Table 8.2 Address Map: Space of H'40000000 to H'407FFFFF corrected (OtherCS0 mirror)|
|||8-7|8.4.1 Common Control Register (CMNCR): Erroneous description of bits 28 and 24 corrected|
|||8-11|8.4.3 CSn Space Wait Control Register (CSnWCR) (n = 0 to 5): Description of HW[1:0] bits corrected|
|||8-34|8.4.10 Timeout Enable Register (TOENR): Erroneous description of CS5TOEN to CS0TOEN bits corrected|
|||8-77|Table 8.17 Relationship between Bus Width, Access Size, and Number of Bursts: Erroneous description in note 1<br>corrected|
|||8-78|8.5.8 SRAM Interface with Byte Selection: Body corrected|
|||8-86|Figure 8.40 Idle Cycle Conditions corrected|
|||9. Direct Memory Access Controller||
|||9-2|9.3 Register Configuration: Register name corrected (into TC) in (e) DMA Register Set|
|||9-15|9.4.7 Channel Status Register n (CHSTAT_n): Description of the DER bit corrected|
|||9-22|9.4.9 Channel Configuration Register n (CHCFG_n): Description of bits 2 to 0 corrected|
|||9-23|9.4.11 Channel Extension Register n (CHEXT_n): DPR[2:0] and SPR[2:0] bits added, and notes corrected|
|||9-25|9.4.14 DMA Control Register (DCTRL_0_7, DCTRL_8_15): LWPR and LDPR bits added|
|||9-32|9.4.25 DMA Extension Resource Selectors 0 to 7 (DMARS0 to DMARS7): Bit 14 of DMARS2 corrected|
|||9-34|9.5.1 Transfer Flow: Body corrected|
|||9-34|9.5.2 DMA Transfer Requests: Body in (1) Auto-Request Mode corrected|
|||9-34|9.5.2 DMA Transfer Requests: Body in (2) External Request Mode corrected|
|||9-37|Table 9.4 On-Chip Peripheral Module Requests: Setting of AM[2:0] for the serial sound interface channels 0 to 3<br>corrected|
|||9-44|Figure 9.5 Register Mode Setting Example 2 corrected|
|||9-47|9.6.3 Link Mode: Body of <Explanation of the link mode flow>, 8. Link end analysis in (1) Operation Flow corrected|
|||9-57|9.7.5 DMA Acknowledge Output Function: Erroneous description corrected|
|||9-68,<br>9-69|9.8.2 Setting Example 2 (Register Mode/Software Request) changed|
|||9-70, 9-<br>71|9.8.3 Setting Example 3 (Register Mode/Continuous Execution) changed|
|||9-73|Table 9.29 Descriptor Setting changed|
|||9-76|9.9.1 Divided Output of DACK0 and TEND0: Erroneous description corrected|
|||9-77|9.9.3 Atomic Access (ARLOCK[1:0] and AWLOCK[1:0]) added|
|||10. Multi-Function Timer Pulse Unit 2||
|||10-1|10.1 Features: The number of interrupt sources corrected (28 corrected to 25)|
|||10-5|Table 10.2 Pin Configuration: Note corrected|
|||10-12|Table 10.10 Setting of Operation Mode by Bits MD0 to MD3: Description corrected|
|||10-31|10.3.4 Timer Interrupt Enable Register (TIER): Description of TTGE and TTGE2 bits corrected|
|||10-36|10.3.6 Timer Buffer Operation Transfer Mode Register (TBTM): Description added to description of TTSE, TTSB,<br>and TTSA bits|
|||10-46|10.3.17 Timer Output Control Register 1 (TOCR1): Note 2 corrected|
|||10-54|10.3.23 Timer Cycle Data Register (TCDR): Body corrected|
|||10-55|10.3.25 Timer Interrupt Skipping Set Register (TITCR): Note corrected|
|||10-57|10.3.26 Timer Interrupt Skipping Counter (TITCNT): Body corrected and description of 4VCNT[2:0] bits corrected|
|||10-60|10.3.29 Timer Waveform Control Register (TWCR): Note corrected|
|||10-89|Figure 10.35 Procedure for Selecting Reset-Synchronized PWM Mode: Description of [6] and note corrected|
|||10-94|Figure 10.38 Example of Complementary PWM Mode Setting Procedure: Description of [9] corrected|
|||10-126|Figure 10.73 Example of Procedure for Specifying A/D Converter Start Request Delaying Function: Description of<br>[2] corrected|
|||10-154|10.8.2 Reset Start Operation: Body corrected|
|||11. OS Timer||
|||11-1|Table 11.2 Register Base Addresses corrected|

Revision History-2

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|11-2|11.2.1 Registers Overview: Table corrected|
|||11-5|Table 11.8 OSTMnTS register contents: Function of the OSTMnTS bit corrected (0: This setting has no effect.)|
|||11-6|Table 11.9 OSTMnTT register contents: Function of the OSTMnTT bit corrected (0: This setting has no effect.)|
|||11-7|11.3.1 Block Diagram added, and Figure 11.1 Block Diagram of OSTM added|
|||11-8|11.3.3 Generation of Interrupt Request: Body corrected, and Figure 11.2 Generating an Interrupt when Counting<br>Starts (in Interval Timer Mode) added|
|||11-9|11.3.4 Starting and Stopping the Timer: Description of Initializing deleted|
|||11-9 to<br>11-11|11.3.5.1 Basic Operation in Interval Timer Mode: Body corrected, Figure 11.3 Timing Diagram of OSTM in Interval<br>Timer Mode added, and Figure 11.4 Timing Diagram of Forced Restart in Interval Timer Mode added|
|||11-12|11.3.5.2 Operation when OSTMnCMP = 0000 0000H: Body corrected, and Figure 11.5 Timing Diagram when<br>OSTMnCMP = 0000 0000Hin Interval Timer Mode added|
|||11-13,<br>11-14|11.3.6.1 Basic Operation in Free-Running Comparison Mode: Body corrected, Figure 11.6 Timing Diagram of OSTM<br>in Free-Run Compare Mode added, and Table 11.11 OSTMTINT Generation Timing added|
|||11-14,<br>11-15|11.3.6.2 Operation when OSTMnCMP = 0000 0000Hadded, and Figure 11.7 Timing Diagram when OSTMnCMP =<br>0000 0000Hin Free-Run Compare Mode added|
|||12. Watchdog Timer||
|||12-1|12.1 Features: Body corrected|
|||12-5|12.3.3 Watchdog Reset Control/Status Register (WRCSR): Bit 5 corrected|
|||12-6|Figure 12.2 Writing to WTCNT and WTCSR: Addresses corrected|
|||12-6|12.3.4 (2) Writing to WRCSR: Body corrected|
|||12-6|Figure 12.3 Writing to WRCSR: Addresses corrected|
|||12-8|12.4.1 Canceling Software Standby Mode: Body corrected|
|||12-8|12.4.2 Using Watchdog Timer Mode: Body corrected|
|||14. Serial Communication Interface with FIFO||
|||14-19|14.3.9 FIFO Control Register (SCFCR): Description of MCE bit corrected|
|||15. Serial Communications Interface||
|||15-1|Table 15.1 Specifications of SCI: Specifications in "Clock source" under "Asynchronous mode" corrected|
|||15-2|Table 15.2 Input and Output Pins of the SCIs: Note corrected|
|||15-65|Table 15.18 Pin Configuration corrected|
|||16. Renesas Serial Peripheral Interface||
|||16-3|16.2 Input/Output Pins: Note corrected (RSPCK)|
|||16-8|16.3.4 Status Register (SPSR): Note added to the description of TEND bit|
|||16-28|Figure 16.10 MSB First Transfer (8-Bit Data): Note corrected|
|||17. SPI Multi I/O Bus Controller||
|||17-9|17.4.3 (1) Bit Rate: Calculation formula added|
|||17-9|Table 17.3 Relationship between SPBR[7:0] and BRDV[1:0] Settings: Description corrected|
|||18. I2C Bus Interface||
|||18-1|18.1.2 Register Base Addresses: Body corrected|
|||18-1|Table 18.3 Register Base Address corrected|
|||18-2|18.1.3 External I/O Signals: Title corrected|
|||18-2|Table 18.4 RIICn Pin Configuration corrected|
|||18-3|18.2.1 Functional Overview, Issuing and detecting conditions: Body corrected|
|||18-4|18.2.1 Functional Overview, Noise removal: Body corrected|
|||18-6|Figure 18.2 Connections to the External Circuit by the I/O Pins (I2C Bus Configuration Example):<br>Description corrected|
|||18-7 to<br>18-38|Bit position of each register corrected|
|||18-8|18.3.1 RIICnCR1 - I2C Bus Control Register 1: Body of IICRST Bit (I2C Bus Interface Internal Reset) corrected|
|||18-9|Table 18.6 RIIC Resets corrected|
|||18-9|18.3.1 RIICnCR1 - I2C Bus Control Register 1: Body of ICE Bit (I2C Bus Interface Enable) corrected|
|||18-11,<br>18-12|18.3.2 RIICnCR2 - I2C Bus Control Register 2: Body and cautions of RS Bit (Restart Condition Issuance Request)<br>and body of TRS Bit (Transmit/Receive Mode) corrected|

Revision History-3

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|18-14|Table 18.8 RIICnMR1 register contents: Note 1 corrected|
|||18-17|18.3.4 RIICnMR2 - I2C Bus Mode Register 2: Note 1 of SDDL[2:0] Bits (SDA Output Delay Setup Counter)<br>corrected (fmFm)|
|||18-19|18.3.5 RIICnMR3 - I2C Bus Mode Register 3: Body of NF[1:0] Bits (Noise Filter Stage Selection) corrected|
|||18-19|18.3.5 RIICnMR3 - I2C Bus Mode Register 3: Body of ACKBT Bit (Transmit Acknowledge) corrected|
|||18-20|18.3.5 RIICnMR3 - I2C Bus Mode Register 3: Name and body of SMBE Bit (SMBus Select) corrected|
|||18-29|18.3.9 RIICnSR1 - I2C Bus Status Register 1: Body of DID Flag (Device-ID Address Detection) and HOA Flag (Host<br>Address Detection) corrected|
|||18-31,<br>18-33|18.3.10 RIICnSR2 - I2C Bus Status Register 2: Body of TMOF Flag (Timeout), AL Flag (Arbitration-Lost), and RDRF<br>Flag (Receive Data Full) corrected|
|||18-35|Table 18.17 RIICnSARy register contents: Function of SVA[9:1] bits corrected|
|||18-36|18.3.11 RIICnSARy - I2C Slave Address Register y (y = 0 to 2): Name of SVA[9:1] Bits (7-Bit Address/10-Bit<br>Address Upper Bits) corrected|
|||18-37|18.3.12 RIICnBRL - I2C Bus Bit Rate Low-Level Register: Note 1 corrected ((Sm), (Fm))|
|||18-38,<br>18-39|18.3.13 RIICnBRH - I2C Bus Bit Rate High-Level Register: Description corrected|
|||18-39,<br>18-40|Table 18.20 Minimum Specifiable Value for RIICnBRL and RIICnBRH: Title and description corrected|
|||18-40|Table 18.21 Examples of RIICnBRH/RIICnBRL Settings for Transfer Rate (when RIICnFER.SCLE = 1 and<br>RIICnFER.NFE = 0) corrected|
|||18-40|Table 18.22 Examples of RIICnBRH/RIICnBRL Settings for Transfer Rate (when RIICnFER.SCLE = 1,<br>RIICnFER.NFE= 1, and Number of NF Stages = 4) corrected|
|||18-41|18.3.14 RIICnDRT - I2C Bus Transmit Data Register: Body corrected|
|||18-45|18.5.1 Communication Data Format: Body corrected|
|||18-45|Figure 18.3 I2C Bus Format corrected|
|||18-45|18.5.1 Communication Data Format: Description of A# added|
|||18-47,<br>18-48|18.5.3 Master Transmit Operation: Description of (3), (5), and (7) corrected, and caution added|
|||18-52|18.5.4 Master Receive Operation: Body corrected|
|||18-54|Figure 18.10 Example Flowchart for the Master Reception of 3 or More Bytes (7-Bit Address Format): Title corrected|
|||18-56|Figure 18.13 Master Receive Operation Timing (3) (when RDRFS = 0): Level of TRS and TDRE corrected|
|||18-57|Figure 18.14 Example Flowchart for the Master Reception of 1 or 2 Bytes (7-Bit Address Format) added|
|||18-58|18.5.5 Slave Transmit Operation: Description of (7) corrected and caution added|
|||18-59|Figure 18.15 Example of Slave Transmission Flowchart corrected|
|||18-64|18.6 SCL Synchronization Circuit: Body corrected|
|||18-65|Figure 18.22 SDA Output Delay Facility corrected|
|||18-66|18.8 Digital Noise-Filter Circuits: Body corrected|
|||18-69|18.9.2 Detection of the General Call Address: Body corrected|
|||18-70|18.9.3 Device-ID Address Detection: Body corrected|
|||18-71|Figure 18.28 AASy/DID Flag Set/Clear Timing during Reception of Device-ID corrected|
|||18-74|Figure 18.31 Suspension of Data Transfer when NACK is Received (NACKE = 1) corrected|
|||18-79|18.11.2 Function to Detect Loss of Arbitration during NACK Transmission (NALE Bit): Body corrected|
|||18-80|18.11.3 Slave Arbitration-Lost Detection (SALE Bit): Body corrected|
|||18-82|Figure 18.37 Start Condition/Restart Condition Issue Timing (ST and RS Bits) corrected|
|||18-83|Figure 18.38 Stop Condition Issue Timing (SP Bit): Erroneous description corrected (IIC)|
|||18-84|18.13.1 Timeout Function: Body and description of <1> to <3> corrected|
|||18-87|18.13.3 RIIC Reset and Internal Reset: Reference section corrected|
|||18-88|18.14 SMBus Operation: Body corrected|
|||18-90|18.15 Reset Function of RIIC: Title corrected|
|||18-90,<br>18-91|Table 18.24 RIIC Reset Functions: Title of the table and description corrected|

Revision History-4

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|19. Serial Sound Interface||
|||19-39|19.5.3 Limits on TDM mode and WS Continue Mode: Body corrected|
|||21. CAN Interface||
|||21-2|21.1.2 Register addresses: Body corrected|
|||21-2|Table 21.4 Register base address corrected|
|||21-8|Table 21.10 List of RS-CAN Module Registers (2/12): Name of transmit/receive FIFO buffer receive interrupt flag<br>status register and transmit/receive FIFO buffer transmission interrupt flag status register corrected|
|||21-18|Table 21.11 Transmit Buffer p Allocated to Each Channel: CANn corrected to CANm|
|||21-19|Table 21.12 Transmit/Receive FIFO Buffer k Allocated to Each Channel: CANn corrected to CANm|
|||21-24|21.3.2 RSCAN0CmCTR - Channel Control Register (m = 0 or 1): Erroneous description of OLIE bit corrected (OLF<br>corrected to OVLF)|
|||21-26|Table 21.17 RSCAN0CmSTS register contents: Function of TEC[7:0] bits corrected|
|||21-26|Table 21.17 RSCAN0CmSTS register contents: Function of REC[7:0] bits corrected|
|||21-27|21.3.3 RSCAN0CmSTS - Channel Status Register (m = 0 or 1): Body of EPSTS flag corrected|
|||21-52|21.3.18 RSCAN0RMNDy - Receive Buffer New Data Register y (y = 0): Body of RMNSq Flags (q = 0 to 31)<br>corrected|
|||21-53|21.3.21 RSCAN0RMIDq - Receive Buffer ID Register (q = 0 to 31): Name of RMIDE bit corrected|
|||21-87|21.3.43 RSCAN0TMCp - Transmit Buffer Control Register (p = 0 to 31): Body corrected|
|||21-102|Table 21.74 RSCAN0TXQSTSm register contents: Function of bits 31 to 3 corrected|
|||21-122|21.5.2.1 Channel Stop Mode: Body corrected (GSLPR bit corrected to CSLPR bit)|
|||21-142|Figure 21.16 CAN Setting Procedure after the this LSI is Reset corrected|
|||21-164|21.11 Notes on the RS-CAN Module: Description corrected|
|||22. IEBus Controller||
|||22-3|22.2.1 Function overview: Description of effective transmission speed corrected|
|||22-50|Table 22-29 Received control data and data written to the IEBBnDR register: Function of 5H corrected|
|||22-76|Note 1 corrected|
|||22-92|(c) Slave status transmission request processing flow example: Title corrected|
|||22-100|Figure 22-45 Master transmission (FIFO mode): Description corrected|
|||22-102|Figure 22-47 Master reception (FIFO mode): Description corrected|
|||22-106|Figure 22-51 Slave transmission (FIFO mode): When the control bit 3H or 7H is received: Description corrected|
|||22-107|Figure 22-52 Slave transmission (FIFO mode): When the control bit 0H or 6H is received (or when 4H or 5H is<br>received from the locked master while the unit is locked): Reference section corrected|
|||22-111|22.7.1 (3) Effective transmission speed: Description corrected|
|||22-112|Table 22-56 Transfer rate and maximum number of transfer bytes in each communication mode: Effective transfer<br>rate corrected|
|||22-119|Table 22-60 Control field ACK<br>signal response conditions (when the received control data is 0H, 3H, 4H, 5H, 6H, or<br>7H): Title corrected (H0H)|
|||22-123|22.7.6 (9) (b) Last acknowledge bit of the control field: Body corrected|
|||22-125|Figure 22-62 Slave status bit configuration: Note b) corrected|
|||24. CD-ROM Decoder||
|||24-6|Table 24.1 Register Configuration: Access size of CD-ROM decoder stream data input register corrected (R: 16, W:<br>16, 32)|
|||25. LIN Interface||
|||―|LIN slave mode deleted|
|||25-1|25. LIN Interface: Body corrected|
|||25-1|25.1 Features: Title corrected|
|||25-1|25.1.2 Register Addresses: Body corrected|
|||25-1|Table 25.2 Register Base Addresses corrected|
|||25-2|Table 25.4 RLIN3n  Interrupt and DMA Requests corrected|
|||25-3|25.2 Function: Body corrected|
|||25-4|Table 25.6 LIN Interface Specifications corrected (prohibition of the frame separated mode setting added)|
|||25-5|Figure 25.1 LIN Interface Block Diagram: n = 0, 1 deleted|

Revision History-5

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|25-6|Table 25.7 List of LIN Interface Registers corrected (LIN master and LIN slave deleted)|
|||25-7 to<br>25-32|25.3.1 LIN Master Related Registers: Address and bit position of each register corrected|
|||25-7|Table 25.8 RLN3nLWBR register contents: Functions of LPRS[2:0] and LWBR0 bits corrected|
|||25-7|25.3.1.1 RLN3nLWBR - LIN Wake-up Baud Rate Select Register: Description of NSPB[3:0] bits (bit sampling count<br>select bits) and LWBR0 bit (wake-up baud rate select bit) corrected|
|||25-8|Table 25.9 RLN3nLBRP0 register contents: Function corrected (setting range corrected)|
|||25-8|25.3.1.2 RLN3nLBRP0 ― LIN Baud Rate Prescaler 0 Register: Body corrected|
|||25-8|Table 25.10 RLN3nLBRP1 register contents: Function corrected (setting range corrected)|
|||25-9|Table 25.11 RLN3nLSTC register contents: Function of reserved bits corrected|
|||25-9|25.3.1.4 RLN3nLSTC - LIN Self-Test Control Register: Body corrected|
|||25-10,<br>25-11|25.3.1.5 RLN3nLMD - LIN Mode Register: Description of LCKS[1:0] bits (LIN system clock select bits) corrected|
|||25-14|25.3.1.8 RLN3nLWUP - LIN Wake-up Configuration Register: Description of WUTL[3:0] bits (wake-up transmission<br>low level width select bits) corrected|
|||25-15|Table 25.16 RLN3nLIE register contents: Function of SHIE, ERRIE, FRCIE, and FTCIE bits corrected|
|||25-15,<br>25-16|25.3.1.9 RLN3nLIE - LIN Interrupt Enable Register: Description of SHIE bit (successful header transmission<br>interrupt enable bit), ERRIE bit (error detection interrupt request enable bit), FRCIE bit (successful frame/wake-up<br>reception interrupt request enable bit), and FTCIE bit (successful frame/wake-up transmission interrupt request<br>enable bit) corrected|
|||25-18|25.3.1.10 RLN3nLEDE -LIN Error Detection Enable Register: Description of PBERE bit (physical bus error detection<br>enable bit) corrected|
|||25-19|25.3.1.11 RLN3nLCUC - LIN Control Register: Description of OM1 bit (LIN mode select bit) corrected|
|||25-20|25.3.1.12 RLN3nLTRC - LIN Transmission Control Register: Description of RTS bit (response transmission/<br>reception start bit) and FTS bit (frame transmission/wake-up transmission/reception start bit) corrected|
|||25-20|Table 25.19  RLN3nLTRC register contents: Note added (prohibition of the frame separated mode setting) in the<br>RTS bit function|
|||25-22,<br>25-23|25.3.1.14 RLN3nLST - LIN Status Register: Body and description of HTRC flag (successful header transmission<br>flag), D1RC flag (successful data 1 reception flag), ERR flag (error detection flag), FRC flag (successful frame/<br>wake-up reception flag) and FTC flag (successful frame/wake-up transmission flag) corrected|
|||25-24,<br>25-25|25.3.1.15 RLN3nLEST - LIN Error Status Register: Body and description of RPER flag (response preparation error<br>flag), CSER flag (checksum error flag), FER flag (framing error flag), FTER flag (timeout error flag), PBER flag<br>(physical bus error flag), and BER flag (bit error flag) corrected|
|||25-26<br>to<br>25-28|25.3.1.16 RLN3nLDFC - LIN Data Field Configuration Register: Description of LSS bit (transmission/reception<br>continuation select bit), FSM bit (frame separate mode select bit), RFT bit (response field communication direction<br>select bit), and RFDL[3:0] bits (response field length select bits) corrected|
|||25-26|Table 25.23 RLN3nLDFC register contents: Note added (prohibition of the frame separated mode setting) in the<br>FSM bit function|
|||25-29|25.3.1.17 RLN3nLIDB ― LIN ID Buffer Register: Body corrected|
|||25-30|25.3.1.18 RLN3nLCBR - LIN Checksum Buffer Register: Access and body corrected|
|||25-32|25.3.1.19 RLN3nLDBRm - LIN Data Buffer m Register (m = 1 to 8): Description of For transmission of response data<br>of 9 bytes or more corrected|
|||25-34|Table 25.28 Transition Condition of Each Mode corrected|
|||25-38|Table 25.30 Transition Conditions of Operation Modes corrected|
|||25-40|Table 25.32 Processing in Response Transmission corrected|
|||25-41|Table 25.33 Processing in Response Reception corrected|
|||25-42|25.7.2.1 Data Transmission: Body corrected|
|||25-42|Figure 25.7 Example of Data Transmission Timing (LIN Master Mode) corrected|
|||25-43|Figure 25.8 Example of Data Reception Timing corrected|
|||25-46|25.7.3.3 Multi-Byte Response Transmission/Reception Function: Body corrected|
|||25-47|25.7.4.1 Wake-up Transmission: Body corrected|
|||25-48|25.7.4.2 Wake-up Reception: Body corrected|
|||25-48|25.7.4.3 Wakeup Collision added|
|||25-49|Table 25.34 Types of Statuses in LIN Master Mode corrected|
|||25-50,<br>25-51|Table 25.35 Types of Error Statuses in LIN Master Mode corrected|
|||25-50|25.7.6.1 LIN Master Mode (1) Types of Error Statuses: Body corrected|

Revision History-6

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|25-53|Figure 25.14 Connection in LIN Reset Mode and LIN Mode and Figure 25.15 Connection in LIN Self-Test Mode:<br>n = 0, 1 deleted|
|||25-54|25.8.1 Change to LIN Self-Test Mode: Description corrected|
|||25-55,<br>25-56|25.8.2 Transmission in LIN Master Self-Test Mode: Description corrected|
|||25-56,<br>25-57|25.8.3 Reception in LIN Master Self-Test Mode: Description corrected|
|||25-58|25.9 Baud Rate Generator: Body corrected|
|||25-58|Figure 25.16 Block Diagram of Baud Rate Generation in LIN Master Mode corrected|
|||25-58|25.9.1 LIN Master Mode: Title and body corrected|
|||―|Table 25.36 Examples of Baud Rate (19200, 10417, 9600, and 2400 bps) Generation in LIN<br>Master Mode deleted|
|||25-59|25.9.2 Noise Filter: Body corrected|
|||25-59|Figure 25.17 Configuration of Noise Filter corrected|
|||25-59|Figure 25.18 Example of Noise Filter Circuit corrected|
|||25-60|Figure 25.19 Determination of Received Data when Noise Filter is Used corrected|
|||26. Ethernet Controller||
|||26-15|26.3.9 CRC Error Frame Receive Counter Register (CEFCR) corrected|
|||26-15|26.3.10 Frame Receive Error Counter Register (FRECR) corrected|
|||26-16|26.3.11 Too-Short Frame Receive Counter Register (TSFRCR) corrected|
|||26-16|26.3.12 Too-Long Frame Receive Counter Register (TLFRCR) corrected|
|||26-17|26.3.13 Residual-Bit Frame Receive Counter Register (RFCR) corrected|
|||26-17|26.3.14 Multicast Address Frame Receive Counter Register (MAFCR) corrected|
|||26-55|26.4.1 (1) (b) Transmit Descriptor 1 (TD1): Description of TDL[15:0] bits corrected|
|||26-55|26.4.1 (1) (c) Transmit Descriptor 2 (TD2): Body corrected and description of TBA[31:0] bits corrected|
|||26-58|26.4.1 (2) (a) Receive Descriptor 0 (RD0): Description of RCSE bit corrected (Table 26.4 corrected to Table 26.3)|
|||26-59|26.4.1 (2) (b) Receive Descriptor 0 (RD0): Description of RBL[15:0] bits corrected|
|||26-60|Figure 26.5 Relationship between Transmit Descriptor and Transmit Buffer corrected|
|||27. A/D Converter||
|||27-19|Table 27.5 A/D Conversion Time (Single Mode) corrected|
|||27-22|27.6 Definitions of A/D Conversion Accuracy: Body corrected|
|||27-23|27.7.1 Module Standby Mode Setting: Body corrected|
|||28. USB2.0 Host/Function Module||
|||―|Erroneous description corrected: DxFIFO corrected to DnFIFO, DEVADDx corrected to DEVADDn, PIPExCTR<br>corrected to PIPEnCTR, PIPExTRE corrected to PIPEnTRE, PIPExTRN corrected to PIPEnTRN, PIPExCFG<br>corrected to PIPECFG|
|||28-3|Table 28.1 Pin Configuration: Function of REFRIN corrected|
|||28-11|28.3.1 System Configuration Control Register (SYSCFG0): Description of UCKSEL bit corrected|
|||28-18,<br>28-19|28.3.6 DMAn-FIFO Bus Configuration Registers (D0FBCFG, D1FBCFG): Description of DFACC[1:0] and TENDE<br>bits corrected|
|||28-20|28.3.7 FIFO Port Registers (CFIFO, D0FIFO, D1FIFO): Description of FIFOPORT[31:0] bits corrected|
|||28-23|28.3.8 (1) CFIFOSEL: Description of MBW[1:0], BIGEND, ISEL, and CURPIPE[3:0] bits corrected|
|||28-24,<br>28-25|29.3.8 (2) D0FIFOSEL, D1FIFOSEL: Description of DREQE and MBW[1:0] bits corrected|
|||28-44,<br>28-45|28.3.28 DCP Configuration Register (DCPCFG): Description of bits 7 and 8 added|
|||28-46|Table 28.10 Relationship between Transfer Mode Settings by CNTMD Bit and Timings at which Reading Data or<br>Transmitting Data from FIFO Buffer is Enabled added|
|||28-53|28.3.32 Pipe Configuration Register (PIPECFG): Description of TYPE[1:0] bits corrected|
|||28-56|Table 28.11 Relationship between Transfer Mode Settings by CNTMD Bit and Timings at which Reading Data or<br>Transmitting Data from FIFO Buffer is Enabled added|
|||28-70|28.3.37 PIPEn Transaction Counter Enable Registers (PIPEnTRE) (n = 1 to 5, 9, and A to F): Description of TRENB<br>bit corrected|
|||28-89|Table 28.19 Pipe Setting Items: Remarks of CNTMD and SHTNAK bits corrected|

Revision History-7

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|28-96|Table 28.19 Relationship between Transfer Mode Settings by CNTMD Bit and Timings at which Reading Data or<br>Transmitting Data from FIFO Buffer is Enabled deleted|
|||28-97|Table 28.21 FIFO Port Function Settings: Function of DREQE bit corrected|
|||28-98|Figure 28.6 Procedure for Pipe Switching during Access to the FIFO Port corrected|
|||30. Video Display Controller 5 (2): Input Controller||
|||30-17|Table 30.14 Timing of Delay for Output of Vertical Synchronization Signal corrected|
|||30-41,<br>30-42|The order of 30.2.9, 30.2.10, and 30.2.11 changed|
|||31. Video Display Controller 5 (3): Scaler||
|||31-23|Table 31.20 Settings for Field Determination Signal Control corrected|
|||31-26|Table 31.25 Frame Buffer Writing Mode Setting corrected|
|||31-27|Table 31.30 Frame Buffer Writing Control: Description corrected|
|||31-34|Table 31.37 Field Specification for Frame Buffer Reading corrected|
|||31-36|Table 31.38 Frame Buffer Control corrected|
|||31-51|31.2.17 Vertical Scaling Register (SC0_SCL0_DS6): Note corrected|
|||31-64|31.2.33 Frame Sub-Sampling Register (SC0_SCL1_WR5): Description of SC0_RES_WENB bit corrected|
|||31-71,<br>31-72|31.2.45 Pointer Buffer and Field Information Register (SC0_SCL1_PBUF_FLD): Description corrected|
|||31-74|31.2.49 Frame Buffer Control Register 1 (Graphics 0) (GR0_FLM1): Description of GR0_FLM_SEL [1:0] bits<br>corrected|
|||31-76|31.2.51 Frame Buffer Control Register 3 (Graphics 0) (GR0_FLM3): Description of GR0_FLD_NXT bit corrected|
|||31-88|31.3.1 Scaling Setting Example for 525i Video Input and VGA-Size (640 x 480) Video Output: Title corrected|
|||31-88|Table 31.40 Input and Output Angles for 525i Video Input and VGA-Size (640 x 480) Video Output: Title corrected<br>and output signal corrected (640 x 480)|
|||31-88|(2) Horizontal Scaling (Horizontal Scale Down, Scaling Filter: 2-Tap Linear): Body corrected|
|||31-88|(3) Horizontal Scaling (Horizontal Scale Up, Scaling Filter: 2-Tap Linear) deleted|
|||31-88|(3) Vertical Scaling (Vertical Scale Up, Scaling Filter: 2-Tap Linear): Body corrected|
|||34. Video Display Controller 5 (7): Output Controller||
|||34-6,<br>34-7|Table 34.5 Gamma Correction: Description corrected|
|||34-34<br>to<br>34-41|34.2.4 Area Setting Register G1 in Gamma Correction Block (GAM_G_AREA1) to 34.2.11 Area Setting Register G8<br>in Gamma Correction Block (GAM_G_AREA8): Description corrected|
|||34-45<br>to<br>34-52|34.2.14 Area Setting Register B1 in Gamma Correction Block (GAM_B_AREA1) to 34.2.21 Area Setting Register<br>B8 in Gamma Correction Block (GAM_B_AREA8): Description corrected|
|||34-56<br>to<br>34-63|34.2.24 Area Setting Register R1 in Gamma Correction Block (GAM_R_AREA1) to 34.2.31 Area Setting Register<br>R8 in Gamma Correction Block (GAM_R_AREA8): Description corrected|
|||36. Capture Engine Unit||
|||36-2|Table 36.1 Functional Overview of CEU corrected|
|||36-7|36.4.1 Capture Start Register (CAPSR): Note added|
|||36-13|36.4.3 Capture Interface Control Register (CAMCR): Description of JPG[1:0] bits corrected and note added to body|
|||36-18|36.4.6 Capture Interface Width Register (CAPWR): Description of VWDTH[11:0] and HWDTH[12:0] bits corrected|
|||36-36|36.4.17 Capture Bundle Destination Size Register (CBDSR): Description of CBVS[22:0] corrected|
|||36-36|36.4.17 (a) Image capture and data synchronous fetch: Body corrected|
|||36-49|Figure 36.47 Operating Status during Capturing: Erroneous description corrected (CSPSR.CE corrected to<br>CAPSR.CE)|
|||36-59|Table 36.11 Restrictions on CEU Input/Output Functions corrected|
|||37. SCUX||
|||37-2|Figure 37.1 Block Diagram of SCUX corrected (MTU2 added)|
|||37-3|Table 37.1 Pin Configuration: Function corrected|
|||37-15|37.3.9 FFD0_n FIFO Download Boot Register (FFDBR_FFD0_n) (n = 0, 1, 2, 3): Description of BOOT bit corrected|
|||37-16|37.3.10 FFD0_n FIFO Download Event Mask Register (DEVMR_FFD0_n) (n = 0, 1, 2, 3): Description of DEVMRQ<br>bit corrected|

Revision History-8

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|37-22|37.3.17 FFU0_n FIFO Upload Event Clear Register (UEVCR_FFU0_n) (n = 0, 1, 2, 3): Description of UEVCUF,<br>UEVCOF, and UEVCOL bits corrected|
|||37-70|37.3.68 FFD0_n Timing Select Register (FDTSELn_CIM) (n = 0, 1, 2, 3): Description of MTUSEL bit added and<br>description of SCKSEL bit corrected|
|||37-71|Figure 37.4 Configuration Diagram of Input Timing Signal Selector corrected|
|||37-72|37.3.69 FFU0_n Timing Select Register (FDTSELn_CIM) (n = 0, 1, 2, 3): Description of MTUSEL bit added and<br>description of SCKSEL bit corrected|
|||37-73|Figure 37.5 Configuration Diagram of Output Timing Signal Selector corrected|
|||37-87|Figure 37.7 Initial Setting Procedure of SCUX (2) corrected|
|||37-87|Figure 37.8 Initial Setting Procedure of SCUX (3) corrected|
|||37-88|Figure 37.9 Transfer Start Procedure and Stop Procedure of SCUX (1) corrected|
|||37-90|Figure 37.11 Transfer Start Procedure and Stop Procedure of SCUX (3) corrected|
|||37-95|37.4.5 Data Transfer Route: Body corrected|
|||37-101<br>to<br>37-103|Table 37.18 Input/Output Timing Setting (1) to Table 37.20 Input/Output Timing Setting (3) corrected, and notes<br>corrected|
|||37-109|Figure 37.16 Volume Ramp Operation: Note added to description of operation (2)|
|||37-112,<br>37-113|Figure 37.20 Volume Ramp Operation for 4-System Data corrected, and note added to description of operation (2)|
|||41. Ports||
|||41-1|41.1.2 Port group index n: Body corrected|
|||41-2|Table 41.3 Pin Function Configuration Overview corrected, note deleted, and caution added|
|||41-3|41.2.2 Pin Data Input/Output: Body corrected|
|||41-3|Table 41.4 PPRn.PPRnm Bit Read Values corrected, and note changed to caution|
|||41-4|41.3.1 Port Register (Pn): Body corrected|
|||41-5|41.3.2 Port Set and Reset Register (PSRn): Body corrected|
|||41-5|41.3.3 Port Pin Read Register (PPRn/JPPR0): Body corrected and function of PPRn[15:0] bits corrected|
|||41-6|41.3.4 Port Mode Register (PMn): Caution added and note corrected|
|||41-7|Table 41.6 Alternative Mode Selection corrected and note changed to caution|
|||41-8|41.3.8 Port NOT Register (PNOTn): Function of PNOTn[15:0] bits corrected|
|||41-9|41.3.9 Port Mode Set and Reset Register (PMSRn): Body corrected|
|||41-10|41.3.10 Port Mode Control Set and Reset Register (PMCSRn/JPMCSR0): Body corrected|
|||41-10|41.3.11 Port Function Control Additional Expansion Register (PFCAEn): Caution corrected|
|||41-11|41.3.12 Port Input Buffer Control Register (PIBCn): Title and body corrected, and description added to note|
|||41-11|41.3.13 Port Bidirection Control Register (PBDCn/JPBDC0): Title and body corrected, and note deleted|
|||41-12|Table 41.7 Alternative Functions for Which the PIPCn.PIPCnm Bit Should be Set to 0 corrected|
|||41-13|41.3.15 Serial Sound Interface Noise Canceler Control Register (SNCR): Bits 4 to 6 corrected|
|||41-14|Table 41.8 Number and Function of Ports: Pin name corrected|
|||41-14|41.5 JTAG Port 0 (JP0): Note changed to caution|
|||41-14|Table 41.10 Control Registers (JP0) corrected and note changed to caution|
|||41-15|Table 41.11 Pin Function (P0) corrected and note changed to caution|
|||41-15|Table 41.12 Control Registers (P0): Note changed to caution|
|||41-16|Table 41.13 Pin Function (P1) corrected and note changed to caution|
|||41-16|Table 41.14 Control Registers (P1) corrected and note changed to caution|
|||41-17|Table 41.16 Control Registers (P2): Note changed to caution|
|||41-18|Table 41.17 Pin Function (P3) corrected|
|||41-18|Table 41.18 Control Registers (P3) corrected and note changed to caution|
|||41-19|Table 41.20 Control Registers (P4): Note changed to caution|
|||41-20|Table 41.22 Control Registers (P5) corrected and note changed to caution|
|||41-22|Table 41.24 Control Registers (P6) corrected and caution added|
|||41-23|Table 41.25 Pin Function (P7) corrected|

Revision History-9

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|41-23|Table 41.26 Control Registers (P7): Note changed to caution|
|||41-24|Table 41.28 Control Registers (P8) corrected|
|||41-25|Table 41.30 Control Registers (P9): Note changed to caution|
|||41-27|Figure 41.2 Example Flow of Port Settings (in Port Mode) (a): Title corrected|
|||41-28|Figure 41.3 Example Flow of Port Settings (in Software I/O Control Alternative Mode) (b): Title corrected and note<br>changed to caution|
|||41-29|Figure 41.4 Example Flow of Port Settings (in Direct I/O Control Alternative Mode) (c) corrected and title corrected|
|||42. Power-Down Modes||
|||42-1|Figure 42.1 Transitions between Processing States corrected|
|||42-2|Table 42.1 States of Power-Down Modes: Transition Conditions corrected and note 6 added|
|||42-4|42.2.1 Standby Control Register 1 (STBCR1): Description of STBY and DEEP bits corrected|
|||42-5|42.2.2 Standby Control Register 2 (STBCR2): Description of HIZ bit corrected|
|||42-10|42.2.7 Standby Control Register 7 (STBCR7): Erroneous description of MSTP74 bit corrected|
|||42-12|42.2.9 Standby Control Register 9 (STBCR9): Description of MSTP93 bit corrected|
|||42-13|42.2.10 Standby Control Register 10 (STBCR10): Note 1 deleted|
|||42-23|42.2.20 Standby Acknowledge Register 1 (STBACK1): Title corrected and note 1 corrected|
|||42-24|42.2.21 Standby Acknowledge Register 2 (STBACK2): Note 1 corrected|
|||42-30|42.2.26 Deep Standby Cancel Source Flag Register (DSFR): Body corrected|
|||42-32|42.3.1 (1) Transition to Sleep Mode: Body corrected and not added|
|||42-32|42.3.1 (2) Canceling Sleep Mode: Body corrected|
|||42-33|42.3.2 (1) Transition to Software Standby Mode: Description corrected|
|||42-35|42.3.3 Software Standby Mode Application Example: Note added|
|||42-36|42.3.4 (1) Transition to Deep Standby Mode: Body corrected|
|||42-37|Figure 42.3 Flowchart of Transition to Deep Standby Mode corrected|
|||42-38|Figure 42.4 Flowchart of Canceling Deep Standby Mode: Description corrected|
|||42-40|42.3.5 Module Standby Function: Body corrected|
|||42-41|42.3.6 Software Reset added|
|||43. Debugger Interface||
|||43-7 to<br>43-10|Table 43.10 Correspondence between Pins of this LSI and Boundary Scan Registers corrected|
|||43-12|43.4 ICE Registers: Body corrected|
|||44. List of Registers||
|||44-2|Table 44.1 Register Addresses: Frequency control register 2 deleted|
|||44-31|Table 44.1 Register Addresses:<br>Access size of CD-ROM decoder stream data input register (STRMDIN0) corrected (16 (R/W), 32 (W))|
|||44-28|Table 44.1 Register Addresses:<br>Register name of transmit/receive FIFO buffer receive interrupt flag status<br>register and transmit/receive FIFO buffer transmit interrupt flag status register corrected|
|||44-3,<br>44-4,<br>44-51,<br>44-52,<br>44-53,<br>44-61|Table 44.1 Register Addresses:<br>Interrupt clear-enable registers 17 and 18, Interrupt set-pending registers 17 and 18, Port register_10, Port<br>register_11, Port set/reset register_10, Port set/reset register_11, Port pin read register_10, Port pin read<br>register_11, Port mode register_10, Port mode register_11, Port mode control register_10, Port mode control<br>register_11, Port function control register_10, Port function control register_11, Port function control expansion<br>register_10, Port function control expansion register_11, Port NOT register_10, Port NOT register_11, Port mode<br>set/reset register_10, Port mode set/reset register_11, Port mode control set/reset register_10, Port mode control<br>set/reset register_11, Port function control additional expansion register_10, Port function control additional<br>expansion register_11, Port input buffer control register_10, Port input buffer control register_11, Port bi-direction<br>control register_10, Port bi-direction control register_11, Port IP control register_10, Port IP control register_11, and<br>BSID register deleted|
|||44-69,<br>44-79,<br>44-88,<br>44-96,<br>44-97,<br>44-120,<br>44-121|Table 44.2 Register Bits:<br>Registers of bus state controller corrected, DCTRL_0_7 and DCTRL_8_15 registers corrected, RIICxMR1,<br>RIIC0SER, RIIC1SER, RIIC2SER, and RIIC3SER registers of I2C bus interface corrected, CEFCR0, FRECR0,<br>TSFRCR0, TLFRCR0, RFCR0, and MAFCR0 registers of Ethernet controller corrected, and DCPCFG_0 and<br>DCPCFG_1 registers of USB2.0 host/function module corrected|

Revision History-10

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|2.00|May 25, 2015|44-66,<br>44-120,<br>44-207|Table 44.2 Register Bits:<br>FRQCR2 register of clock pulse generator, all registers of LIN interface LIN slave, and BSID register of debugger<br>interface deleted|
|||44-208,<br>44-209|Table 44.3 Register States:<br>Register name (FRQCR2) deleted, module name of CAN interface corrected ((RS-CAN) deleted), and note 11<br>added|
|||45. Electrical Characteristics||
|||45-5|Table 45.2 DC Characteristics (3) [Except I2C Bus Interface, and USB 2.0 Host/Function Module-Related Pins]:<br>Note corrected|
|||45-8|Table 45.5 Clock Timing: Description of real time clock oscillation settling time (tROSC) corrected|
|||45-9|Figure 45.3 Power-On Oscillation Settling Time corrected|
|||45-18|Title of figure 45.13 corrected|
|||45-19|Title of figure 45.14 corrected|
|||45-43|Figure 45.41 Clock Timing corrected|
|||45-44|Figure 45.42 Transmission and Reception Timing (Master, CPHA = 0) corrected|
|||45-44|Figure 45.43 Transmission and Reception Timing (Master, CPHA = 1) corrected|
|||45-44|Figure 45.44 Transmission and Reception Timing (Slave, CPHA = 0) corrected|
|||45-45|Figure 45.45 Transmission and Reception Timing (Slave, CPHA = 1) corrected|
|||45-46|Table 45.14 SPI Multi I/O Bus Controller Timing corrected|
|||45-46|Figure 45.47 Transmission and Reception Timing (CPHAT = 0, CPHAR = 0) corrected|
|||45-47|Figure 45.48 Transmission and Reception Timing (CPHAT = 1, CPHAR = 1) corrected|
|||45-61|Table 45.25 Capture Engine Unit Module Signal Timing corrected|
|||45-61|Figure 45.74 Capture Engine Unit Module Signal Timing corrected|
|||46. States and Handling of Pins||
|||46-1|Table 46.1 Pin States corrected (clock and bus state controller)|
|||46-8|Figure 46.1 Example of Externally Allocated Capacitors in the Products in 208-Pin QFP Packages corrected|
|||46-9|Figure 46.2 Example of Externally Allocated Capacitors in the Products in 176-Pin QFP Packages corrected|
|||Appendix||
|||Appendix-1|Figure A.1 Dimensions of 176-Pin BGA Package corrected|
|3.00|Nov 30, 2016|All|RZ/A1LU and RZ/A1LC specification added|
|||1. Overview||
|||1-1|1.1 Features of This LSI: Body corrected|
|||1-2, 1-<br>4, 1-5,<br>1-6, 1-<br>7, 1-8|Table 1.1 Features of RZ/A1L, RZ/A1LU, and RZ/A1LC:<br>Title corrected.<br>Items of media local bus, IEBusTMcontroller, and CD-ROM decoder corrected.<br>Items and specification of LIN interface corrected.<br>EthernetAVB (RZ/A1LU only) and JPEG codec unit (RZ/A1LU only) added.<br>Specification of on-chip RAM and package corrected.|
|||1-9|Table 1.2 Product Lineup: RZ/A1LU and RZ/A1LC group added|
|||1-15,<br>1-16|Table 1.3 Pin Functions:<br>Symbol within the classification of "Renesas serial peripheral interface" corrected.<br>Classification of media local bus, IEBusTMcontroller, LIN interface, and Ethernet controller corrected.<br>EthernetAVB (RZ/A1LU only) added.|
|||1-19 to<br>1-23|Table 1.4 List of Pins: Table corrected, function 8 added, and notes 1 to 4 added|
|||2. CPU||
|||2-2|Table 2.1 Cortex-A9 Configuration Signal Settings: Error corrected|
|||3. Boot Mode||
|||3-4|Figure 3.1 Control Signals Output to the Serial Flash Memory Through SPI Communication Conversion corrected|
|||5. LSI Internal Bus||
|||5-2|Figure 5.2 North Main Bus Configuration: Notes 1 and 2 added|
|||5-3, 5-4|Table 5.2 List of Peripheral Buses:<br>Description of IEBus controller, LIN interface, media local bus, and CD-ROM decoder corrected.<br>Description of JPEG codec unit (RZ/A1LU only) added to peripheral bus 4.<br>Description of EthernetAVB (RZ/A1LU only) added to peripheral bus 6.|

Revision History-11

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|3.00|Nov 30, 2016|5-5|Figure 5.3 South Main Bus Configuration: EthernetAVB added, and notes 1 and 2 added|
|||5-7, 5-<br>8, 5-9|Table 5.5 Address Map:<br>"Area" of address 0x6020_0000 to 0x602F_FFFF and address 0x2020_0000 to 0x202F_FFFF corrected.<br>Note 5 corrected.|
|||5-10|Figure 5.4 Address Remapping corrected|
|||5-10|5.5.2 Operation: Body corrected|
|||5-12|5.8.1 (3) Protection unit information (ARPROT[2:0], AWPROT[2:0]): Note added|
|||5-13|5.8.5 (4) Atomic access (ARLOCK[1:0], AWLOCK[1:0]): Note added|
|||5-14|Table 5.6 Register Configuration: Register name of AXI bus control register 5 corrected|
|||5-15|5.10.1 Remap Register (RMPR): Description of bit 1 (AXI128) corrected|
|||5-16|5.10.2 AXI Bus Control Register 0 (AXIBUSCTL0): Body corrected, description of bits 27 to 24 (JCUARCACHE[3:0])<br>and bits 19 to 16 (JCUAWCACHE[3:0]) added, and note added|
|||5-17|5.10.4 AXI Bus Control Register 5 (AXIBUSCTL5): Body corrected|
|||5-20|5.10.7 AXI Bus Response Error Interrupt Control Register 0 (AXIRERRCTL0): Description of bit 28 (JCURERREN)<br>added, and note added|
|||5-22|5.10.9 AXI Bus Response Error Status Register 0 (AXIRERRST0): Description of bits 31 and 30 (JCURRESP[1:0])<br>and bits 29 and 28 (JCUBRESP[1:0]) added, and note added|
|||5-24|5.10.11 AXI Bus Response Error Clear Register 0 (AXIRERRCLR0): Description of bit 30 (JCURRESPCLR) and bit<br>28 (JCUBRESPCLR) added, and note added|
|||6. Clock Pulse Generator||
|||6-3|6.1 (7) SSCG Circuit: Body corrected|
|||6-5|6.3 Clock Mode: Body corrected|
|||6-5|Table 6.3 Settable Frequency Ranges corrected|
|||6-12|6.7.1 Oscillation Stabilizing Time of the On-chip Crystal Oscillator: Body corrected|
|||6-12|6.7.2 Oscillation Stabilizing Time of the PLL circuit: Body corrected|
|||6-16|Figure 6.6 Audio and USB Clock Signals corrected|
|||6-16|Figure 6.7 Video Image Clock Signals corrected|
|||6-17|Figure 6.8 Clock Signals for Other Modules corrected|
|||6-18|Figure 6.9 Distribution of Internal Clock Signals (1) corrected|
|||6-19|Figure 6.10 Distribution of Internal Clock Signals (2) corrected|
|||7. Interrupt Controller||
|||7-2|Figure 7.1 Block Diagram corrected|
|||7-17|7.4.3 On-Chip Peripheral Module Interrupts: Body corrected|
|||7-22,<br>7-28,<br>7-29|Table 7.3 List of Interrupt IDs:<br>Module column of IEBusTMcontroller, CD-ROM decoder, media local bus, and LIN interface channel 0 corrected.<br>JPEG codec unit (RZ/A1LU only) assigned to interrupt ID 126 and 127.<br>EthernetAVB (RZ/A1LU only) assigned to interrupt ID 355 to 358.|
|||8. Bus State Controller||
|||8-5|Table 8.3 Initial States by Areas in Boot Modes 0 and 1 to 3: Note 1 corrected|
|||8-87|8.5.11 (3) On-Chip Peripheral Module Access: Body corrected|
|||9. Direct Memory Access Controller||
|||9-1|9.1 Features, Transfer requests: Body corrected|
|||9-31|9.4.25 DMA Extension Resource Selectors 0 to 7 (DMARS0 to DMARS7): Body corrected|
|||9-36 to<br>9-38|Table 9.4 On-Chip Peripheral Module Requests: “DMA Transfer Request Source” of IEBus™  controller, CD-ROM<br>decoder, media local bus, and LIN interface channel 0 corrected|
|||10. Multi-Function Timer Pulse Unit 2||
|||10-44,<br>10-68,<br>10-88,<br>10-95,<br>10-111,<br>10-147,<br>10-149,<br>10-152,<br>10-153|TCNT0, TCNT1, TCNT2, TCNT3, and TCNT4 have been respectively changed to TCNT_0, TCNT_1, TCNT_2,<br>TCNT_3, and TCNT_4.|
|||10-104|Figure 10.44 Example of Initial Output in Complementary PWM Mode (1) corrected|

Revision History-12

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|3.00|Nov 30, 2016|10-105|Figure 10.45 Example of Initial Output in Complementary PWM Mode (2) corrected|
|||12. Watchdog Timer||
|||12-1|Error in the body corrected|
|||12-8|12.4.1 Canceling Software Standby Mode: Body corrected|
|||13. Realtime Clock||
|||13-16|13.4.1 Initial Settings of Registers after Power-On and Oscillation Stabilization Time: Body corrected|
|||14. Serial Communication Interface with FIFO||
|||14-13|14.3.7 Serial Status Register (SCFSR): Description of bit 1 (RDF) corrected|
|||14-19|14.3.9 FIFO Control Register (SCFCR): Description of bits 10 to 8 (RSTRG[2:0]), bits 7 and 6 (RTRG[1:0]), and bits<br>5 and 4 (TTRG[1:0]) corrected|
|||14-33,<br>14-38|14.4.2 (3) Transmitting and Receiving Data: Body corrected|
|||15. Serial Communications Interface||
|||15-4|15.2.2 Receive Data Register (RDR): Body corrected|
|||16. Renesas Serial Peripheral Interface||
|||16-10|16.3.5 Data Register (SPDR): Body corrected|
|||16-12|16.3.9 Data Control Register (SPDCR): Description of bits 6 and 5 (SPLW1, SPLW0) corrected, and Note added|
|||17. SPI Multi I/O Bus Controller||
|||17-1|17.1 Features, Serial Flash Memory Interface: Body corrected|
|||17-2|Figure 17.1 Block Diagram corrected|
|||17-4|Table 17.2 Register Configuration corrected|
|||17-5,<br>17-6|17.4.1 Common Control Register (CMNCR): Description of bits 23 and 22 (MOIIO3[1:0]), bits 21 and 20<br>(MOIIO2[1:0]), bits 19 and 18 (MOIIO1[1:0]), bits 17 and 16 (MOIIO0[1:0]), bits 15 and 14 (IO3FV[1:0]),<br>bits 13 and 12 (IO2FV[1:0]), bits 9 and 8 (IO0FV[1:0]), bit 6 (CPHAT), and bit 5 (CPHAR) corrected|
|||17-22|17.4.14 SPI Mode Read Data Register 0 (SMRDR0): Description of bits 31 to 0 (RDATA0[31:0]) corrected|
|||17-22|17.4.15 SPI Mode Read Data Register 1 (SMRDR1): Description of bits 31 to 0 (RDATA1[31:0]) corrected|
|||17-23|17.4.16 SPI Mode Write Data Register 0 (SMWDR0): Description of bits 31 to 0 (WDATA0[31:0]) corrected|
|||17-23|17.4.17 SPI Mode Write Data Register 1 (SMWDR1): Description of bits 31 to 0 (WDATA1[31:0]) corrected|
|||17-25|17.4.19 SPI AC Input Characteristics Adjustment Register (CKDLY) (RZ/A1LU only) added|
|||17-27|17.4.21 Data Read DDR Enable Register (DRDRENR) (RZ/A1LU only) added|
|||17-29|17.4.23 SPI Mode DDR Enable Register (SMDRENR) (RZ/A1LU only) added|
|||17-30|17.4.24 SPI AC Output Characteristics Adjustment Register (SPODLY) (RZ/A1LU only) added|
|||17-32|17.5.3 32-bit Serial Flash Addresses: Error in note corrected (RBE bit in DRCR = 1)|
|||17-34|17.5.6 External Address Space Read Mode: Body corrected|
|||17-38|Figure 17.12 Example of Initial Setting Flow in External Address Space Read Mode corrected|
|||17-40|17.5.8 SPI Operating Mode: Body corrected|
|||17-41|Figure 17.16 Example of Initial Setting Flow in SPI Operating Mode corrected|
|||17-42|Figure 17.17 Example of a Data Transfer Setting Flow in SPI Operating Mode corrected|
|||17-43|17.5.9 (3) Data Transmission and Reception Timing: Body corrected|
|||17-43|Figure 17.18 SDR Transfer Format: Title corrected|
|||17-44|Figure 17.19 DDR Transfer Format (RZ/A1LU only) added|
|||17-45|Table 17.5 Data Registers: Error corrected (DRDMCR, SMDMCR)|
|||17-45|17.5.10 (2) Data Enable: Body corrected|
|||17-46|Figure 17.20 Data and Enable corrected|
|||17-50|Table 17.7 Pin Status (2) corrected|
|||17-51|Table 17.8 Pin Status (3) corrected|
|||18. I2C  Bus Interface||
|||18-37|18.3.12 RIICnBRL —  I2C Bus Bit Rate Low-Level Register: Body corrected|
|||18-38,<br>18-39|18.3.13 RIICnBRH — I2C  Bus Bit Rate High-Level Register: Calculation formulae of frequency and duty cycle<br>corrected, and note 1 added|
|||18-46|Figure 18.5 Example of RIIC Initialization Flowchart: Note 1 corrected|

Revision History-13

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|3.00|Nov 30, 2016|18-67|18.9.1 Slave-Address Match Detection: Body corrected|
|||18-68|Figure 18.25 AASy Flag Set Timing with 10-Bit Address Format Selected: Error of SDAn signal corrected|
|||18-72|18.9.4 Host Address Detection: Body corrected|
|||18-74|18.10.2 NACK Reception Transfer Suspension Function: Body corrected|
|||18-74|Figure 18.31 Suspension of Data Transfer when NACK is Received (NACKE = 1) corrected|
|||18-88|18.14 SMBus Operation: Body corrected|
|||19. Serial Sound Interface||
|||19-21|19.3.12 FC Status Register (SSIFCSR): Error in the table corrected|
|||20. Media Local Bus||
|||20-1|Description added|
|||21. CAN Interface||
|||21-6|Figure 21.1 RS-CAN Module Block Diagram corrected|
|||22. IEBus Controller||
|||22-1|Description added|
|||22-1|22.1 IEBB Features: Body corrected|
|||22-5|22.3.1 IEBBn register overview: Body corrected|
|||22-30|22.3.2 (14) IEBBnTMS - IEBBn transfer mode setting register: Body corrected|
|||24. CD-ROM Decoder||
|||24-1|Description added|
|||24-46|24.6.8 Note on Software Reset added|
|||25. LIN Interface||
|||25-1|Description added|
|||25-12|Table 25.13 RLN3nLBFC register contents: Error in the function column of bits 5 and 4 (BDT[1:0]) corrected|
|||25-13|Table 25.14 RLN3nLSC register contents: Error of the function column of bits 5 and 4 (IBS[1:0]) corrected|
|||25-36|25.6 LIN Reset Mode: Body corrected|
|||26. Ethernet Controller||
|||26-2|Figure 26.1 Configuration of ETHER corrected|
|||26-57,<br>26-58|26.4.1 (2) Receive Descriptor, (a) Receive Descriptor 0 (RD0): Description of bits 29 and 28 (RFP[1:0]) and bits 25<br>to 16 (RFS[9:0]) corrected|
|||26-59|26.4.1 (2) Receive Descriptor, (b) Receive Descriptor 1 (RD1): Description of bits 31 to 16 (RBL[15:0]) corrected|
|||26-61|26.4.1 (3) Descriptor and Transmit/Receive Buffer, (b) Reception: Body corrected|
|||26-61|Figure 26.6 Relationship between Receive Descriptor and Receive Buffer corrected|
|||26-69|Figure 26.11 Sample Reception Flowchart (Single-Frame/Single-Descriptor): Title and figure corrected|
|||26-70|26.4.3 (2) Reception Error Processing, (b) Receive FIFO Overflow: Error in the body corrected|
|||26-74|Table 26.5 List of ETHER Interrupts: Error in “Register and Bit” corrected (EESR0.TC)|
|||26-84|26.6.3 Software Reset added|
|||27. A/D Converter||
|||27-25|Figure 27.9 Example of Analog Input Circuit: Note deleted|
|||27-25|Table 27.8 Analog Input Pin Ratings: Note added|
|||30. Video Display Controller 5 (2): Input Controller||
|||30-24|Table 30.19 YCbCr/RGB Signal Reception Timing corrected|
|||31. Video Display Controller 5 (3): Scaler||
|||31-1|Figure 31.1 Functional Block Diagram of Scaler 0 corrected|
|||31-9|31.1.4 (2) Generating a Full-Screen Enable Signal: Body corrected|
|||31-27|Table 31.29 Frame Buffer Transfer Mode: Description corrected|
|||31-61|31.2.29 Writing Mode Register (SC0_SCL1_WR1): Description of bit 0 (SC0_RES_BST_MD) corrected|
|||31-74|31.2.49 Frame Buffer Control Register 1 (Graphics 0) (GR0_FLM1): Note corrected|
|||33. Video Display Controller 5 (5): Image Synthesizer||
|||33-22|33.1.14 Alpha Blending Calculation: Body corrected|

Revision History-14

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|3.00|Nov 30, 2016|33-27|Table 33.28 CLUT Table Configuration: Abbreviation corrected|
|||34. Video Display Controller 5 (7): Output Controller||
|||34-4|34.1.6 (2) Offset calculation formulas for each area: Calculation formula corrected|
|||34-34|34.2.4 Area Setting Register G1 in Gamma Correction Block (GAM_G_AREA1): Error corrected|
|||34-35|34.2.5 Area Setting Register G2 in Gamma Correction Block (GAM_G_AREA2): Error corrected|
|||34-45|34.2.14 Area Setting Register B1 in Gamma Correction Block (GAM_B_AREA1): Error corrected|
|||34-46|34.2.15 Area Setting Register B2 in Gamma Correction Block (GAM_B_AREA2): Error corrected|
|||34-56|34.2.24 Area Setting Register R1 in Gamma Correction Block (GAM_R_AREA1): Error corrected|
|||34-57|34.2.25 Area Setting Register R2 in Gamma Correction Block (GAM_R_AREA2): Error corrected|
|||36. Capture Engine Unit||
|||36-2|Table 36.1 Functional Overview of CEU: The description of "Binary data" within the classification of "Connectable<br>camera" corrected|
|||36-5|Figure 36.2 Register Plane Switching Timing (VD Polarity is High-Active in Data Enable Fetch Mode): Title corrected|
|||36-7|Body corrected|
|||36-12<br>to 36-<br>13|36.4.3 Capture Interface Control Register (CAMCR):<br>Body corrected.<br>Description of bit 27 (VDSEL), bit 26 (HDSEL), bit 25 (FLDSEL), and bit 24 (DSEL) added.<br>Description of bits 5 and 4 (JPG[1:0]) and bit 1 (VDPOL) corrected.<br>Note added.|
|||36-14|Body corrected|
|||36-15|Figure 36.14 Relationship between the VIO_VD and VIO_HD signals and the VD Interrupt when VD and HD are<br>High-Active (in Image Capture Mode or Data Synchronous Fetch Mode): Title corrected|
|||36-15|Figure 36.15 Relationship between the VIO_VD and VIO_HD signals and the VD Interrupt when VD and HD are<br>High-Active (in Image Capture Mode or Data Synchronous Fetch Mode) added|
|||36-47|36.4.22 Capture Event Flag Clear Register (CETCR): Description of bit 9 (VD) corrected|
|||36-59|36.5.1 (1) Clock Frequency: Body corrected|
|||36-60|36.5.4 Software Reset added|
|||37. SCUX||
|||37-3|Table 37.1 Pin Configuration: Note 1 added to MLB_CLK|
|||37-70|37.3.68 FFD0_n Timing Select Register (FDTSELn_CIM) (n = 0, 1, 2, 3): Description of bits 3 to 0 (SCKSEL)<br>corrected|
|||37-71|Figure 37.4 Configuration Diagram of Input Timing Signal Selector corrected|
|||37-72|37.3.69 FFU0_n Timing Select Register (FDTSELn_CIM) (n = 0, 1, 2, 3): Description of bits 3 to 0 (SCKSEL)<br>corrected|
|||37-73|Figure 37.5 Configuration Diagram of Output Timing Signal Selector corrected|
|||37-114|37.5 Usage Note added|
|||38. SD Host Interface||
|||38-1 to<br>38-56|Some specifications that don't require an NDA have been disclosed.|
|||39. MMC Host Interface||
|||39-42|39.8.3 Software Reset added|
|||40. On-Chip RAM||
|||40-1|40.1 Features: Body corrected|
|||40-1|Table 40.1 Address Spaces of On-Chip Large-Capacity RAM: Note added|
|||41. Ports||
|||41-12|Table 41.7 Alternative Functions for Which the PIPCn.PIPCnm Bit Should be Set to 0: SSITxD4 deleted|
|||41-13|41.3.15 Serial Sound Interface Noise Canceler Control Register (SNCR): Body corrected, description of bit 6<br>(ETSEL) added, and note added|
|||41-17|Table 41.15 Pin Function (P2): Table corrected, and note added|
|||41-19|Table 41.19 Pin Function (P4): Table corrected, and note added|
|||41-20|Table 41.21 Pin Function (P5): Table corrected, and note added|
|||41-21|Table 41.23 Pin Function (P6): Table corrected, and notes 1 to 3 added|
|||41-23|Table 41.25 Pin Function (P7): Table corrected, and notes 1 and 2 added|

Revision History-15

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|3.00|Nov 30, 2016|42. Power-Down Modes||
|||42-3|Table 42.2 Register Configuration corrected|
|||42-6|42.2.3 Standby Control Register 3 (STBCR3): Note 1 added to bit 7 (MSTP37) and bit 5 (MSTP35)|
|||42-9|42.2.6 Standby Control Register 6 (STBCR6): Description of bit 1 (MSTP61) added, and note 2 added to bit 1<br>(MSTP61)|
|||42-11|42.2.8 Standby Control Register 8 (STBCR8): Description of bit 2 (MSTP82) added, note 2 added to bit 3<br>(MSTP83), and note 3 added to bit 2 (MSTP82)|
|||42-13|42.2.10 Standby Control Register 10 (STBCR10): Note 1 added to bit 2 (MSTP102)|
|||42-15|42.2.12 Standby Control Register 12 (STBCR12): Note added|
|||42-17|42.2.14 Software Reset Control Register 2 (SWRSTCR2) added|
|||42-22|42.2.19 Standby Request Register 1 (STBREQ1): Description of bit 3 (STBRQ13) and bit 2 (STBRQ12) added, and<br>note 2 added to bit 3 (STBRQ13) and bit 2 (STBRQ12)|
|||42-23|42.2.20 Standby Request Register 2 (STBREQ2): Note 2 added to bit 7 (STBRQ27)|
|||42-24|42.2.21 Standby Acknowledge Register 1 (STBACK1): Description of bit 3 (STBAK13) and bit 2 (STBAK12) added,<br>and note 2 added to bit 3 (STBAK13) and bit 2 (STBAK12)|
|||42-25|42.2.22 Standby Acknowledge Register 2 (STBACK2): Note 2 added to bit 7 (STBAK27)|
|||42-34|42.3.2 (1) Transition to Software Standby Mode: Body corrected|
|||42-36|42.3.4 (1) Transition to Deep Standby Mode: Body corrected|
|||42-39|42.3.4 (2) Canceling Deep Standby Mode: Body corrected|
|||42-41|42.3.5 (1) Transition to Module Standby Function: Body corrected|
|||43-42|42.3.6 Software Reset: Body corrected|
|||42-42|42.3.7 Adjustment of XTAL Crystal Oscillator Gain: Body corrected|
|||42-43|42.4.3 Usage Notes Applying when the USB_X1 Pin is not to be Used added|
|||43. Debugger Interface||
|||43-5|Table 43.7 Pin Configuration: Function of the test data output (pin name: TDO) corrected, and note corrected|
|||43-6|Table 43.8 List of Registers of Boundary-Scan TAP Controller: Initial value of ID register (BSID) corrected, and notes<br>1 and 2 added|
|||43-11|43.3.4 ID Register (BSID): Initial value and description of bits 31 to 0 (DID[31:0]) corrected, and notes 1 and 2<br>added|
|||43-15|Table 43.12 Reset Signal Setting: Note 2 corrected, and note 3 added|
|||44. JPEG Codec Unit||
|||44-1 to<br>44-46|Added|
|||45. EthernetAVB||
|||45-1 to<br>45-198|Added|
|||46. List of Registers||
|||46-1 to<br>46-66|Table 46.1 Register Addresses:<br>Register addresses of SD host interface, JPEG codec unit, and EthernetAVB added.<br>Notes 1 and 2 added.|
|||46-67<br>to 46-<br>227|Table 46.2 Register Bits:<br>Bits of SD host interface, JPEG codec unit, and EthernetAVB added.<br>Notes 1 to 6 added.|
|||46-228,<br>46-229|Table 46.3 Register States:<br>Register states of SD host interface, JPEG codec unit, and EthernetAVB added.<br>Notes 12 and 13 added.|
|||47. Electrical Characteristics||
|||47-8|Table 47.5 Clock Timing: Table corrected, and note added|
|||47-9|Figure 47.3 Power-On Oscillation Settling Time corrected|
|||47-9|Figure 47.4 Oscillation Settling Time on Return from Standby (Return by Reset) corrected|
|||47-10|Figure 47.5 Oscillation Settling Time on Return from Standby (Return by NMI or IRQ) corrected|
|||47-10|Figure 47.6 On-chip Oscillation Circuit Oscillation Settling Time: Title and figure corrected|
|||47-11|Table 47.6 Control Signal Timing: Table corrected, and notes 1 and 2 added|
|||47-11|Figure 47.7 (1) Reset Input Timing 1: Title corrected|
|||47-11|Figure 47.7 (3) Reset Input Timing 2 added|

Revision History-16

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|3.00|Nov 30, 2016|47-12|Figure 47.7 (4) Reset Input Timing 3 added|
|||47-47|Table 47.14 SPI Multi I/O Bus Controller Timing: Table corrected, and note 2 added|
|||47-48|Figure 47.47 SDR Transfer Format Transmission and Reception Timing (CPHAT = 0, CPHAR = 0): Title and figure<br>corrected|
|||47-48|Figure 47.48 SDR Transfer Format Transmission and Reception Timing (CPHAT = 1, CPHAR = 1): Title and figure<br>corrected|
|||47-49|Figure 47.49 DDR Transfer Format Transmission and Reception Timing (CPHAT = 0, CPHAR = 0) (RZ/A1LU only)<br>added|
|||47-49|Figure 47.50 DDR Transfer Format Transmission and Reception Timing (CPHAT = 1, CPHAR = 1) (RZ/A1LU only)<br>added|
|||47-49|Figure 47.51 Timing for Switching the Buffers on and off (CPHAT = 0, CPHAR = 0) corrected|
|||47-49|Figure 47.52 Timing for Switching the Buffers on and off (CPHAT = 1, CPHAR = 1) corrected|
|||47-51|Table 47.16 Serial Sound Interface Timing: Table corrected, and note added|
|||47-54|47.4.13 Media Local Bus Timing: Description added|
|||47-56|47.4.15 Ethernet Controller and EthernetAVB Timing: Title corrected, and description added|
|||47-56|Table 47.19 Ethernet Controller and EthernetAVB Timing: Title and table corrected, and note added|
|||47-57|Figure 47.65 gPTP Timer External Clock Timing added|
|||47-58|Figure 47.66 Timer Capture Signal Timing added|
|||47-62|Table 47.24 Video Display Controller 5 Timing: Table corrected, and notes 1 and 2 added|
|||47-64|Table 47.25 Capture Engine Unit Module Signal Timing corrected|
|||47-65|Figure 47.78 (1) Capture Engine Unit Module Signal Timing when Data is Captured at the Rising Edges of VIO_CLK<br>: Title and figure corrected|
|||47-65|Figure 47.78 (2) Capture Engine Unit Module Signal Timing when Data is Captured at the Falling Edges of<br>VIO_CLK (RZ/A1LU and RZ/A1LC Only) added|
|||47-69|47.4.23 AC Characteristics Measurement Conditions: Body corrected|
|||48. States and Handling of Pins||
|||48-2,<br>48-3,<br>48-4,<br>48-5|Table 48.1 Pin States: Table corrected, [Legend] corrected, notes 2 and 14 corrected, and notes 16 and 17 added|
|||48-6|Table 48.2 Handling of Unused Pins (Except for Debugger Interface Pins): Note 2 added|
|||48-6|Table 48.3 Handling of Debugger Interface Pins (when Emulator is not Used): Note 3 added|
|4.00|Mar 19. 2018|All|Trademarks of Arm changed|
|||1. Overview||
|||1-3|Table 1.1 Features of RZ/A1L, RZ/A1LU, and RZ/A1LC: Specification of SPI multi I/O bus controller corrected|
|||1-4|Table 1.1 Features of RZ/A1L, RZ/A1LU, and RZ/A1LC: Specification of media local bus (RZ/A1L only) corrected|
|||1-8|Table 1.1 Features of RZ/A1L, RZ/A1LU, and RZ/A1LC: “233-pin BGA” added to specification of Package|
|||1-9|Table 1.2 Product Lineup: R7S721031VCBG and R7S721031VLBG added to the RZ/A1LU group|
|||1-13|Figure 1.4 Pin Assignment of the 233-pin BGA (Upper Perspective View): Newly added|
|||1-16|Table 1.3 Pin Functions: I/O column of the RTS2<br>to RTS0<br>and CTS2<br>to CTS0<br>pins in the serial communication<br>interface with FIFO corrected|
|||1-19|Table 1.3 Pin Functions: Symbol of capture engine unit corrected|
|||1-20<br>to<br>1-24|Table 1.4 List of Pins: Column “233 BGA” and note on pins to which the PVcc, Vcc, and Vss functions can be<br>allocated on 233-pin BGA products added|
|||2. CPU||
|||2-2|Table 2.1 Cortex-A9 Configuration Signal Settings: Setting value of CLUSTERID signal corrected|
|||6. Clock Pulse Generator||
|||6-20|6.11 Usage Note added and 6.11.1 Notes on the SSCG added|
|||7. Interrupt Controller||
|||7-36|Figure 7.2 Flow of Initial Settings: Description corrected|
|||7-40|7.8.2 Notes on Selecting IRQ Interrupt Pin Functions: Body corrected|
|||7-41|7.8.4 Notes on Using IRQ Pins as Triggers for Release from Standby when Software Standby is in Use: Newly<br>added|

Revision History-17

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|4.00|Mar 19. 2018|8. Bus State Controller||
|||8-27|8.4.4 SDRAM Control Register (SDCR): Description of bit 10 (RMODE) corrected|
|||16. Renesas Serial Peripheral Interface||
|||16-12|Table 16.3 Relationship between SPBR and BRDV1 and BRDV0 Settings:  Note 1 added|
|||18. I2C Bus Interface||
|||18-40|Table 18.21 Examples of RIICnBRH/RIICnBRL Settings for Transfer Rate (when RIICnFER.SCLE = 1 and<br>RIICnFER.NFE = 0): Description corrected|
||||Table 18.22 Examples of RIICnBRH/RIICnBRL Settings for Transfer Rate (when RIICnFER.SCLE = 1,<br>RIICnFER.NFE= 1, and Number of NF Stages = 4): Description corrected|
|||20. Media Local Bus||
|||20-1|20.1 Features: Body corrected|
|||20-2|20.3 Register Description: Body corrected|
|||20-2|Table 20.2 Register Configuration: Note 1 corrected|
|||25. LIN Interface||
|||25-31|25.3.1.19 RLN3nLDBRm — LIN Data Buffer m Register (m = 1 to 8): Description under "For response reception"<br>corrected|
|||26. Ethernet Controller||
|||26-4|Table 26.2 Register Configuration: CAM entry table specification enable register (common), CAM entry table POST<br>1 register, CAM entry table POST 2 register, CAM entry table POST 3 register, and CAM entry table POST 4 register<br>added|
|||26-22|26.3.21 CAM Entry Table Specification Enable Register (Common) (TSU_FWSLC): Newly added|
|||26-27|26.3.25 CAM Entry Table POST 1 Register (TSU_POST1): Newly added|
|||26-28|26.3.26 CAM Entry Table POST 2 Register (TSU_POST2): Newly added|
|||26-29|26.3.27 CAM Entry Table POST 3 Register (TSU_POST3): Newly added|
|||26-30|26.3.28 CAM Entry Table POST 4 Register (TSU_POST4): Newly added|
|||26-66|26.4.1 (2) (b) Receive Descriptor 1 (RD1): Descriptions of bits 31 to 16 (RBL[15:0]) and bits 15 to 0 (RDL[15:0])<br>corrected|
|||26-93|Figure 26.23 Data Subject to Checksum Calculation and Figure 26.24 Data after Checksum Data Addition:<br>Corrected|
|||29. Video Display Controller 5 (1): Overview||
|||29-1|Table 29.1 Features of Video Display Controller 5: Function of operating frequency corrected|
|||31. Video Display Controller 5 (3): Scaler||
|||31-23|Table 31.22 Control of Interrupt on Specified Image Line before Scaling-down, and Reading of Current Image<br>line before Scaling-down: Description of the SC_RES_LINE[10:0] bits of the SC_SCL0_INT register corrected|
|||31-46|31.2.11 Interrupt Control Register (SC0_SCL0_INT): Description of bits 10 to 0 (SC0_RES_LINE[10:0]) corrected|
|||33. Video Display Controller 5 (5): Image Synthesizer||
|||33-22|33.1.15 CLUT Table: Body corrected|
|||33-23|33.1.16 Multiplication Processing with Current Alpha at Alpha Blending in Rectangular Area: Body corrected|
|||35. Video Display Controller 5 (8):System Controller||
|||35-1|Table 35.1 Interrupt Signals: Function of the INT_STA 9 bit of the S0_WLINE request source corrected|
|||35-2|Table 35.2 Interrupt Clear/Hold Settings: Description of the INT_STA9 bit of the SYSCNT_INT2 register corrected|
|||35-3|Table 35.3 Interrupt Output On/Off Settings: Description of the INT_OUT9_ON bit of the SYSCNT_INT5 register<br>corrected|
|||35-9|35.2.2 Interrupt Control Register 2 (SYSCNT_INT2): Description of bit 4 (INT_STA9) corrected|
|||35-11|35.2.4 Interrupt Control Register 5 (SYSCNT_INT5): Description of bit 4 (INT_OUT9_ON) corrected|
|||37. SCUX||
|||37-66|37.3.65 DMA Transfer Register for FFD0_n (DMATDn_CIM) (n = 0, 1, 2, 3): Body corrected|
|||37-67|37.3.66 DMA Transfer Register for FFU0_n (DMATUn_CIM) (n = 0, 1, 2, 3): Body corrected|
|||42. Power-Down Modes||
|||42-21|42.2.18 CPU Status Register (CPUSTS): Description of bit 7 to 5 and bit 3 to 0 corrected|
|||42-24|42.2.21 Standby Acknowledge Register 1 (STBACK1): Descriptions of bits 7, 6, 4, and 1 corrected|
|||42-25|42.2.22 Standby Acknowledge Register 2 (STBACK2): Description of bits 4 to 0 corrected|

Revision History-18

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|4.00|Mar 19. 2018|42-44|42.4.4 Notes on Using IRQ Pins as Triggers for Release from Standby when Software Standby is in Use: Newly<br>added|
|||43. Debugger Interface||
|||43-12|Table 43.11 Configuration of ICE Registers: Initial value of mode reset control register (ICEREGMDRSTCTL)<br>corrected|
||||43.4.1 Mode Reset Control Register (ICEREGMDRSTCTL): Initial value and description of bits 15 to 13 corrected|
||||43.4.1 Mode Reset Control Register (ICEREGMDRSTCTL): Initial value and description of bits 11 to 9 corrected|
|||45. EthernetAVB||
|||45-199|Figure 45.69 Data Subject to Checksum Calculation and Figure 45.70 Data after Checksum Data Addition:<br>Corrected|
|||46. List of Registers||
|||46-11|Table 46.1 Register Addresses: Address of CPU interface implementer identification register (ICCIIDR) corrected|
|||46-33|Table 46.1 Register Addresses: CAM entry table specification enable register (common) (TSU_FWSLC), CAM entry<br>table POST 1 register (TSU_POST1), CAM entry table POST 2 register (TSU_POST2), CAM entry table POST 3<br>register (TSU_POST3), and CAM entry table POST 4 register (TSU_POST4) added|
|||46-128|Table 46.2 Register Bits: TSU_FWSLC, TSU_POST1, TSU_POST2, TSU_POST3, and  TSU_POST4 registers<br>added|
|||46-231|Table 46.3 Register States: SDIR*7register of the debugger interface module and note 7 deleted|
|||47. Electrical Characteristics||
|||47-8|Table 47.5 Clock Timing: Figures for reference of on-chip PLL circuit oscillation settling time, on-chip oscillation<br>circuit oscillation settling time (other than above), and mode hold time corrected|
||||Table 47.5 Clock Timing:SSCG stabilizing time added|
|||47-9|Figure 47.4 SSCG Stabilizing Time: Newly added|
|||47-10|Figure 47.5 (1) Oscillation Stabilizing Time on Return from Standby (Return by Reset) and Figure 47.5 (2) Oscillation<br>Stabilizing Time on Return from Standby (Return by NMI or IRQ): Figure numbers corrected|
|||47-11|Table 47.6 Control Signal Timing: Figures for reference of RES<br>pulse width and TRST<br>pulse width corrected|
||||Table 47.6 Control Signal Timing: Figures for reference of NMI pulse width, IRQ pulse width, and TINT pulse width<br>corrected|
|||47-68|47.4.20 SD Host Interface Timing: Newly added|
|||Appendix||
|||Appendix-1<br>to<br>Appendix-3|Package Dimensions A.1, A.2, A.3: Corrected|
|||Appendix-4|Package Dimensions A.4: Newly added|
|5.00|Mar 19. 2020|1. Overview||
|||1-13|Figure 1.4 Pin Assignment of the 233-pin BGA: The pin names on location C11 and C12 were corrected.|
|||3. Boot Mode||
|||3-4|Figure 3.1 Control Signals Output to the Serial Flash Memory Through SPI Communication Conversion: Corrected|
|||9. Direct Memory Access Controller||
|||9-55|Table 9.18 Setting for Detection of External Pin Request: LVL, HIEN, and LOEN in the header were corrected.|
|||9-57|Table 9.19 DACK0 Output Timing Setting: AM[2], AM[1:0], and REQD in the header were corrected.|
|||11. OS Timer||
|||11-10|Figure 11.3 Timing Diagram of OSTM in Interval Timer Mode: Corrected|
|||11-13|Figure 11.6 Timing Diagram of OSTM in Free-Run Compare Mode: Corrected|
|||16. Renesas Serial Peripheral Interface||
|||16-2|Figure 16.1 Block Diagram (for One Channel): A typo in the register name for SPCKD was corrected.|
|||18. I2C Bus Interface||
|||18-3|18.2.1 Functional Overview: The description for the SCL clock was corrected.|
|||18-22|18.3.6 RIICnFER ― I2C Bus Function Enable Register: The description for the NACKE bit was corrected.|
|||18-23,<br>18-24|18.3.7 RIICnSER ― I2C Bus Status Enable Register: SAR0E, SAR1E, SAR2E, and SARyE were corrected.|
|||18-28|18.3.9 RIICnSR1 ― I2C Bus Status Register 1: Corrections for SARyE|
|||18-35,<br>18-36|18.3.11 RIICnSARy ― I2C Slave Address Register y: Corrections for SARyE|

Revision History-19

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|5.00|Mar 19. 2020|18-66|Figure 18.23 Block Diagram of Digital Noise Filter Circuit: Corrected|
|||18-67|18.9.1 Slave-Address Match Detection: Corrections for SARyE|
|||18-86|18.13.2 Extra SCL Clock Cycle Output Function: Body corrected|
|||18-86|Figure 18.40 Extra SCL Clock Cycle Output Function (CLO Bit): Corrected|
|||25. LIN Interface||
|||25-52|25.8 LIN Self-Test Mode: Body corrected|
|||25-55|25.8.2 Transmission in LIN Master Self-Test Mode<br>Settings for the baud rate, noise filter, and interrupt output related registers: The setting of the RLN3nLWBR register<br>was corrected and *1was deleted.|
|||25-55|25.8.2 Transmission in LIN Master Self-Test Mode<br>Settings for the interrupt enable and error enable related registers: *2was added to the setting of the RLN3nLIE<br>register.|
|||25-55|25.8.2 Transmission in LIN Master Self-Test Mode: Note 1 was corrected.|
|||25-56|25.8.3 Reception in LIN Master Self-Test Mode<br>Settings for the baud rate, noise filter, and interrupt output related registers: The setting of the RLN3nLWBR register<br>was corrected and *1was deleted.|
|||25-56|25.8.3 Reception in LIN Master Self-Test Mode<br>Settings for the interrupt enable and error enable related registers: *2was added to the setting of the RLN3nLIE<br>register.|
|||25-56|25.8.3 Reception in LIN Master Self-Test Mode: Note 1 was corrected.|
|||29. Video Display Controller 5 (1): Overview||
|||29-1|Table 29.1 Features of Video Display Controller 5<br>Input video image specification: The specification of the 8-bit input conforming to ITU-R BT.656 extended standard<br>was corrected.|
|||29-3|Figure 29.1 Video Display Controller 5 Former Stage Block Diagram: Note (*) was added.|
|||29-3|Figure 29.2 Video Display Controller 5 Middle Stage Block Diagram: Note (*) was added.|
|||30. Video Display Controller 5 (2): Input Controller||
|||30-33|Table 30.27 Register Configuration of Input Controller: The table title was corrected.|
|||30-33|Table 30.28 Register Configuration of Image Quality Adjustment Block: The table title was corrected.|
|||31. Video Display Controller 5 (3): Scaler||
|||31-19|Table 31.16 Horizontal Scale Up Control: The description for the SC_SCL0_US4 register was corrected.|
|||31-20|Table 31.17 Vertical Scale Up Control: The description for the SC_SCL0_US4 register was corrected.|
|||31-56|31.2.22 Scaling-Up Control Block Input Size Register (SC0_SCL0_US4)<br>Bit function table: The descriptions for the SC0_RES_IN_VW[10:0] and SC0_RES_IN_HW[10:0] bits were<br>corrected.|
|||32. Video Display Controller 5 (4): Image Quality Improver||
|||32-11,<br>32-12|Table 32.10 Image Quality Improver Register Configuration: The table title was corrected.|
|||34. Video Display Controller 5 (7): Output Controller||
|||34-26<br>to<br>34-29|Table 34.23 Gamma Correction Block Register Configuration: The table title was corrected.|
|||34-29|Table 34.24 TCON Block Register Configuration: The table title was corrected.|
|||34-30|Table 34.25 Output Controller Register Configuration: The table title was corrected.|
|||37. SCUX||
|||37-95|Table 37.12 Data Transfer Routes (1)<br>Route SSIF→SRC→FFU: The module names from No. 5 through 8 were corrected.|
|||38. SD Host Interface||
|||38-1|The description regarding non-disclosure agreement was deleted.|
|||(Rev.4.00)|38.1.4 SD Card Hardware Interface: Deleted|
|||38-7|38.2.3 Data STOP Register (SD_STOP)<br>Bit function table: The description for the STP bit was corrected.|
|||38-20|38.2.16 SDIO Mode Control Register (SDIO_MODE)<br>Bit function table: The description for the IOABT bit was corrected.|
|||38-27|Figure 38.5 The figure title was corrected to Reading from SD_BUF0.|
|||(Rev.4.00)|38.3.1 SD I/F, (2) Command Issue Timing within the Command Sequence: Deleted|

Revision History-20

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|5.00|Mar 19. 2020|(Rev.4.00)|38.3.1 SD I/F, (3) SDIO Interrupt: Deleted|
|||(Rev.4.00)|38.4.1 Card Detect: Deleted|
|||38-34|38.4.1 Command without Data Transfer, (2) Operation Example: Deleted|
|||38-36|38.4.2 Single Block Read, (2) Operation Example: Deleted|
|||38-38|38.4.3 Single Block Write, (2) Operation Example: Deleted|
|||38-40|38.4.4 Multiple Block Read, (2) Operation Example: Deleted|
|||38-42|38.4.5 Multiple Block Write, (2) Operation Example: Deleted|
|||38-44|38.4.6 IO_RW_DIRECT Command (CMD52), (2) Operation Example: Deleted|
|||38-46|38.4.7 IO_RW_EXTENDED Command (CMD53/Multiple Block Read), (2) Operation Example: Deleted|
|||38-48|38.4.8 IO_RW_EXTENDED Command (CMD53/Multiple Block Write), (2) Operation Example: Deleted|
|||(Rev.4.00)|38.6 Electrical Characteristics: Deleted|
|||43. Debugger Interface||
|||43-7|43.3.3 Boundary Scan Register (SDBSR): Body corrected|
|||43-7 to<br>47-10|Table 43.10 Correspondence between the Pins of the RZ/A1L and RZ/A1LC Group Products and the Boundary<br>Scan Register Bits: The table title was corrected.|
|||43-11<br>to<br>43-14|Table 43.11 Correspondence between the Pins of the RZ/A1LU Group Products and the Boundary Scan Register<br>Bits: Added|
|||46. List of Registers||
|||46-103,<br>46-104|Table 58.2 Register Bits: I2C bus interface<br>RIIC0SER, RIIC1SER, RIIC2SER, and RIIC3SER registers: The names of bits 2 to 0 were corrected.|
|||47. Electrical Characteristics||
|||47-2|Table 47.2 DC Characteristics (1) [Common Items]: The description of Three-state leakage current was corrected.|
|||47-3|Table 47.2 DC Characteristics (2) [Current Consumption]: The typical values of Current consumption in normal<br>operation were corrected.|
|||47-5|Table 47.2 DC Characteristics (4) [I2C Bus Interface Related Pins*]:  Note was corrected.|
|6.00|Jan 29, 2021|3. Boot Mode||
|||3-1|3. Boot Mode: Body corrected and note 1 added|
|||6. Clock Pulse Generator||
|||6-15|Figure 6.5 Clock Signals for the System and Realtime Clock: Description of peripheral clocks 0C and 1C added|
|||9. Direct Memory Access Controller||
|||9-36|Table 9.4 On-Chip Peripheral Module Requests: Setting of the TM bit in the CHCFG_n register for the A/D converter<br>corrected|
|||9-38|Table 9.4 On-Chip Peripheral Module Requests: DMA transfer request signals of I2C bus interface channels 0 to 3<br>corrected|
|||26. Ethernet Controller||
|||26-64|26.4.1 Descriptors and Descriptor List, (a) Receive Descriptor 0 (RD0): Description of bit 27 (RFE) corrected|
|||27. A/D Converter||
|||27-21|27.5 Interrupt Sources and DMA Transfer Request, (a) ADI Interrupt: Body corrected|
|7.00|Sep. 30, 2024|1. Overview||
|||1-7, 1-8|Table 1.1 Features of RZ/A1L, RZ/A1LU, and RZ/A1LC: “233-pin” added to specification of General I/O ports, and<br>PLQP0208KD-A and notes 1 and 2 added to specification of Package|
|||1-9|Table 1.2 Product Lineup: PLQP0208KD-A and notes 1 and 2 added|
|||1-19|Table 1.3 Pin Functions: Symbol and function of General I/O ports corrected (208-pin QFP→208-pin and 233-<br>pin)|
|||6. Clock Pulse Generator||
|||6-2|Figure 6.1 Block Diagram: Note added|
|||6-15|Figure 6.5 Clock Signals for the System and Realtime Clock: Note added|
|||6-16|Figure 6.6 Audio and USB Clock Signals: Note added|
|||12. Watchdog Timer||
|||12-8|12.4.1 Canceling Software Standby Mode: Note 1 added|

Revision History-21

|Rev.|Date|Description|Description|
|---|---|---|---|
|||Page|Summary|
|7.00|Sep. 30, 2024|16. Renesas Serial Peripheral Interface||
|||16-19|16.3.15 Buffer Data Count Setting Register (SPBFDR): Function of bits 5 to 0 (R[5:0]) corrected (SPTX→SPRX)|
|||18. I2C Bus Interface||
|||18-1|Table 18.1 Channels of RIIC: Table headers corrected, and “233-Pins” added|
|||18-33|18.3.10 RIICnSR2 — I2C Bus Status Register 2, RDRF Flag (Receive Data Full), [Setting conditions]: Description<br>of Master receive mode corrected (the RIICnCR2.TRS bit is set to 1→the RIICnCR2.TRS bit is set to 0)|
|||34. Video Display Controller 5 (7): Output Controller||
|||34-87|Table 34.28 Setting Example of Data System: OUT_PIXEL_INV_ON and OUT_SUM_MOVE[4:0] bits deleted|
|||36. Capture Engine Unit||
|||36-2|Table 36.1 Functional Overview of CEU: Note added to the Note column for Size|
|||36-19|36.4.6 Capture Interface Width Register (CAPWR): Notes 1 and 2 added to description of bits 12 to 0<br>(HWDTH[12:0])|
|||36-20|Table 36.6 Unit for Setting Fetch (Capture) Cycle Width: Notes 1 and 2 added|
|||36-29|36.4.11 Capture Filter Size Clip Register (CFSZR): Note added to description of bits 11 to 0 (HFCLP[11:0])|
|||36-31|36.4.12 Capture Destination Width Register (CDWDR): Note added to description of bits 12 to 0 (CHDW[12:0])|
|||36-32|36.4.13 Capture Data Address Y Register (CDAYR): Notes 1 and 2 added to bits 31 to 0 (CAYR[31:0])|
|||36-33|36.4.14 Capture Data Address C Register (CDACR): Note added to description of bits 31 to 0 (CACR[31:0])|
|||36-35|36.4.15 Capture Data Bottom-Field Address Y Register (CDBYR): Note added to description of bits 31 to 0<br>(CBYR[31:0])|
|||36-36|36.4.16 Capture Data Bottom-Field Address C Register (CDBCR): Note added to description of bits 31 to 0<br>(CBCR[31:0])|
|||36-53|36.4.25 Capture Data Address Y Register 2 (CDAYR2): Notes 1 and 2 added to description of bits 31 to 0<br>(CAYR2[31:0])|
|||36-55|36.4.26 Capture Data Address C Register 2 (CDACR2): Note added to description of bits 31 to 0 (CACR2[31:0])|
|||36-57|36.4.27 Capture Data Bottom-Field Address Y Register 2 (CDBYR2): Note added to description of bits 31 to 0<br>(CBYR2[31:0])|
|||36-58|36.4.28 Capture Data Bottom-Field Address C Register 2 (CDBCR2): Note added to description of bits 31 to 0<br>(CBCR2[31:0])|
|||36-61|Table 36.11 Restrictions on CEU Input/Output Functions: Notes added to restrictions for External module<br>interface (capture horizontal size in image capture, capture horizontal size in data fetch) and restrictions for<br>Memory output (output address, horizontal size of the destination image (memory), number of horizontal output<br>pixels (= horizontal clipping size))|
|||41. Ports||
|||41-1|41.1 Features: Body corrected (208-pin package→208-pin and 233-pin packages)|
|||41-1|Table 41.1 Port Group: Package corrected|
|||41-14|Table 41.8 Number and Function of Ports: Notes for Port 8 and Port 9 corrected|
|||42. Power-Down Modes||
|||42-39|Figure 42.4 Flowchart of Canceling Deep Standby Mode: Note corrected, and reference marks added|
|||Appendix||
|||Appendix-3|Figure A.3 Dimensions of 208-Pin QFP Package (PLQP0208KB-A): Title corrected|
|||Appendix-4|Figure A.4 Dimensions of 208-Pin QFP Package (PLQP0208KD-A) added|

Revision History-22
