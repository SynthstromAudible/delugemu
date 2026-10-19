# 24. CD-ROM Decoder

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1241–1286. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This module is only incorporated in the RZ/A1L.

The CD-ROM decoder decodes streams of data transferred from the CD-DSP. When the medium is CD-DA *[1] , the data stream is not input to the CD-ROM decoder because it consists of PCM data. In the case of CD-ROM *[2] , the stream of data is input and the CD-ROM decoder performs sync code detection and maintenance, descrambling, ECC correction, and EDC checking, and outputs the resulting stream of data.

However, since the stream received by the CD-ROM decoder is assumed to consist of data from a CD-ROM transferred via the serial sound interface, the decoder does not bother with the subcodes defined in the CD-DA standard.

Note 1. Compliant with JIS S 8605 (Red Book) Note 2. Compliant with JIS X 6281 (Yellow Book)

## 24.1 Features

- Sync-code detection and maintenance

   - Detects sync codes from the CD-ROM and is capable of providing sync-code maintenance (automatic interpolation of sync codes) when the sync code cannot be detected because of defects such as scratches on the disc. Five sector-synchronization modes are supported: automatic sync maintenance mode, external sync mode, interpolated sync mode, and interpolated sync plus external sync mode.

- Descrambling

- ECC correction

P-parity-based correction, Q-parity-based correction, PQ correction, and QP correction are available.

PQ correction and QP correction can be applied repeatedly up to three times. This, however, depends on the speed of the CD. For example, three iterations are possible when the CD-ROM decoder is operating at 60 MHz with a double-speed CD drive.

Two buffers are provided due to the need for ECC correction. This allows parallel operation, where ECC correction is performed in one buffer while the data stream is being received in the other.

- EDC checking

The EDC is checked before and after ECC correction. An operating mode is available in which, if the result of preECC correction EDC checking indicates no errors, ECC correction is not performed regardless of the result of syndrome calculation.

- Data buffering control

   - The CD-ROM decoder outputs data to the buffer area in a specific format where the sync code is at the head of the data for each sector.

## 24.1.1 Formats Supported by CD-ROM Decoder

This module supports the five formats shown in Figure 24.1 .

**==> picture [389 x 128] intentionally omitted <==**

**----- Start of picture text -----**<br>
Mode0 Sync Header All 0<br>(12 bytes) (4 bytes)<br>Mode1 Sync Header Data (2048 bytes) EDC 0  P-parity Q-parity<br>(12 bytes) (4 bytes) (4 bytes) (8 bytes) (172 bytes) (104 bytes)<br>Mode2   Sync Header<br>Data (2336 bytes)<br>(not XA) (12 bytes) (4 bytes)<br>Mode2   Sync Header Sub-header EDC P-parity Q-parity<br>Form1 (12 bytes) (4 bytes) (8 bytes) Data (2048 bytes) (4 bytes) (172 bytes) (104 bytes)<br>Mode2   Sync Header Sub-header EDC<br>Form2 (12 bytes) (4 bytes) (8 bytes) Data (2324 bytes) (4 bytes)<br>**----- End of picture text -----**<br>

**Figure 24.1 Formats Supported by CD-ROM Decoder**

## 24.2 Block Diagrams

Figure 24.2 is a block diagram of the CD-ROM decoder functions of this LSI and the bus bridge for connection to the bus, that is, of the elements required to implement the CD-ROM decoder function.

**==> picture [483 x 373] intentionally omitted <==**

**----- Start of picture text -----**<br>
Internal bus<br>Bus bridge<br>Stream data Register data Stream data<br>Memory<br>EDC (2 buffers for ECC) EDC<br>Descrambler Memory<br>control<br>Sync code  Mode<br>detection/<br>determination<br>maintenance<br>ECC control<br>Syndrome<br>calculator<br>Timing<br>generation<br>Core of CD-ROM decoder<br>Interrupt and direct memory access controller activation control<br>Interrupt controller, direct memory access controller<br>Figure 24.2 Block Diagram<br>Stream data input control Stream data output control<br>**----- End of picture text -----**<br>

The core of the CD-ROM decoder executes a series of processing required for CD-ROM decoding, including descrambling, sync code detection, ECC correction (P- and Q-parity-based correction), and EDC checking. The core includes sufficient memory to hold two sectors of data.

Input data come from the internal bus and output data go out via the internal bus along a single line each, but the bus bridge logic sets up branches for the register access port and stream data port.

The stream data from the CD-DSP are transferred via the serial sound interface to the stream data input control block. They are then subjected to descrambling, ECC correction, and EDC checking as they pass through the CD-ROM decoder. After these processes, data from one sector are obtained. The data are subsequently transferred to the streamdata buffer via the stream-data output control block. Stream data can be transferred by either the direct memory access controller or the CPU.

Figure 24.3 is a block diagram of the bus-bridge logic.

Since the input stream is transferred over the serial sound interface, transfer is relatively slow. On the other hand, data from the output stream can be transferred at high speeds because they are already in the core of the CD-ROM decoder. Since the data for output are buffered in SDRAM or other memory, they must be transferred at high speeds in order to reduce the busy rate of the SDRAM. For this reason, the data for the output stream are read out before the CD-ROM decoder receives an output stream data read request from the internal bus. This allows the accumulation of streaming data in the registers of the bus bridge, so that the data are ready for immediate output to the internal bus upon a request from the internal bus. Accordingly, the reception of a request to read from registers other than the stream-data registers after the stream data has already been read out and stored in the register of the bus bridge is possible. To cope with this, the CD-ROM decoder is provided with separate intermediary registers for the output stream-data register and the other registers.

**==> picture [366 x 160] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input data from  Data for output to<br>the internal bus the internal bus<br>Buffer control signal for<br>the output stream-data section<br>Input  Register data  Register data  Output  Output stream-data<br>stream data (write) (read) stream data control signal<br>**----- End of picture text -----**<br>

**Figure 24.3 Schematic Diagram of the Bus Bridge**

Figure 24.4 is a schematic diagram of the stream-data input control block. The stream-data input controller contains logic that controls the stream of input data and a register that is used to change the control mode of the CD-ROM decoder.

The serial sound interface mode used to transfer the stream data may affect the order (through the endian setting) or lead to padding before the data is transferred. To handle the different arrangements of data appropriately, the stream-data input control block includes a register for changing the operating mode and generates signals to control the core of the CDROM decoder.

The data holding registers for the input stream consists of two 16-bit registers. The data holding registers are controlled according to the mode set in the control register. For example, controlling the order in which 16-bit data is supplied to the core of the CD-ROM decoder (sending the second 16-bytes first or vice versa). It is also possible to stop the supply of padding data to the core of the CD-ROM decoder.

**==> picture [254 x 234] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input stream data Register data<br>Register access controller<br>Select<br>16 bits<br>16 bits<br>Input stream controller<br>Core of CD-ROM decoder<br>**----- End of picture text -----**<br>

**Figure 24.4 Schematic Diagram of the Stream-Data Input Control Block**

Figure 24.5 is a schematic diagram of the stream-data output control block.

On recognizing that one sector of CD-ROM data is ready in the core of the CD-ROM decoder, this block ensures that the output stream-data register in the bus bridge section is empty and then starts to acquire the data for output from the core of the CD-ROM decoder.

**==> picture [218 x 219] intentionally omitted <==**

**----- Start of picture text -----**<br>
Output  Output stream-data<br>stream data control signal<br>Output stream-data<br>protocol controller<br>Core of CD-ROM decoder<br>**----- End of picture text -----**<br>

**Figure 24.5 Schematic Diagram of the Stream-Data Output Control Block**

This block has functions related to interrupts and direct memory access controller activation control such as suspending and masking of interrupts, turning interrupt flags off after they are read, asserting the activation signal to the direct

memory access controller, and negating the activation signal according to the detected amount of data that has been transferred.

## 24.3 Register Descriptions

This module has the following registers.

## **Table 24.1 Register Configuration**

|**Table 24.1**<br>**Register Configuration**||||||
|---|---|---|---|---|---|
||||**Initial**||**Access**|
|**Name**|**Abbreviation**|**R/W**|**Value**|**Address**|**Size**|
|Enable control register|CROMEN|R/W|H'00|0xE8005000|8|
|Sync code-based synchronization control register|CROMSY0|R/W|H'89|0xE8005001|8|
|Decoding mode control register|CROMCTL0|R/W|H'82|0xE8005002|8|
|EDC/ECC check control register|CROMCTL1|R/W|H'D1|0xE8005003|8|
|Automatic decoding stop control register|CROMCTL3|R/W|H'00|0xE8005005|8|
|Decoding option setting control register|CROMCTL4|R/W|H'00|0xE8005006|8|
|HEAD20 to HEAD22 representation control register|CROMCTL5|R/W|H'00|0xE8005007|8|
|Sync code status register|CROMST0|R|H'00|0xE8005008|8|
|Post-ECC header error status register|CROMST1|R|H'00|0xE8005009|8|
|Post-ECC subheader error status register|CROMST3|R|H'00|0xE800500B|8|
|Header/subheader validity check status register|CROMST4|R|H'00|0xE800500C|8|
|Mode determination and link sector detection status register|CROMST5|R|H'00|0xE800500D|8|
|ECC/EDC error status register|CROMST6|R|H'00|0xE800500E|8|
|Buffer status register|CBUFST0|R|H'00|0xE8005014|8|
|Decoding stoppage source status register|CBUFST1|R|H'00|0xE8005015|8|
|Buffer overflow status register|CBUFST2|R|H'00|0xE8005016|8|
|Pre-ECC correction header: minutes data register|HEAD00|R|H'00|0xE8005018|8|
|Pre-ECC correction header: seconds data register|HEAD01|R|H'00|0xE8005019|8|
|Pre-ECC correction header: frames (1/75 second) data register|HEAD02|R|H'00|0xE800501A|8|
|Pre-ECC correction header: mode data register|HEAD03|R|H'00|0xE800501B|8|
|Pre-ECC correction subheader: file number (byte 16) data register|SHEAD00|R|H'00|0xE800501C|8|
|Pre-ECC correction subheader: channel number (byte 17) data|SHEAD01|R|H'00|0xE800501D|8|
|register||||||
|Pre-ECC correction subheader: sub-mode (byte 18) data register|SHEAD02|R|H'00|0xE800501E|8|
|Pre-ECC correction subheader: data type (byte 19) data register|SHEAD03|R|H'00|0xE800501F|8|
|Pre-ECC correction subheader: file number (byte 20) data register|SHEAD04|R|H'00|0xE8005020|8|
|Pre-ECC correction subheader: channel number (byte 21) data|SHEAD05|R|H'00|0xE8005021|8|
|register||||||
|Pre-ECC correction subheader: sub-mode (byte 22) data register|SHEAD06|R|H'00|0xE8005022|8|
|Pre-ECC correction subheader: data type (byte 23) data register|SHEAD07|R|H'00|0xE8005023|8|
|Post-ECC correction header: minutes data register|HEAD20|R|H'00|0xE8005024|8|
|Post-ECC correction header: seconds data register|HEAD21|R|H'00|0xE8005025|8|
|Post-ECC correction header: frames (1/75 second) data register|HEAD22|R|H'00|0xE8005026|8|
|Post-ECC correction header: mode data register|HEAD23|R|H'00|0xE8005027|8|
|Post-ECC correction subheader: file number (byte 16) data|SHEAD20|R|H'00|0xE8005028|8|
|register||||||
|Post-ECC correction subheader: channel number (byte 17) data|SHEAD21|R|H'00|0xE8005029|8|
|register||||||
|Post-ECC correction subheader: sub-mode (byte 18) data register|SHEAD22|R|H'00|0xE800502A|8|
|Post-ECC correction subheader: data type (byte 19) data register|SHEAD23|R|H'00|0xE800502B|8|

## **Table 24.1 Register Configuration**

|**Table 24.1**<br>**Register Configuration**||||||
|---|---|---|---|---|---|
||||**Initial**||**Access**|
|**Name**|**Abbreviation**|**R/W**|**Value**|**Address**|**Size**|
|Post-ECC correction subheader: file number (byte 20) data|SHEAD24|R|H'00|0xE800502C|8|
|register||||||
|Post-ECC correction subheader: channel number (byte 21) data|SHEAD25|R|H'00|0xE800502D|8|
|register||||||
|Post-ECC correction subheader: sub-mode (byte 22) data register|SHEAD26|R|H'00|0xE800502E|8|
|Post-ECC correction subheader: data type (byte 23) data register|SHEAD27|R|H'00|0xE800502F|8|
|Automatic buffering setting control register|CBUFCTL0|R/W|H'04|0xE8005040|8|
|Automatic buffering start sector setting: minutes control register|CBUFCTL1|R/W|H'00|0xE8005041|8|
|Automatic buffering start sector setting: seconds control register|CBUFCTL2|R/W|H'00|0xE8005042|8|
|Automatic buffering start sector setting: frames control register|CBUFCTL3|R/W|H'00|0xE8005043|8|
|ISY interrupt source mask control register|CROMST0M|R/W|H'00|0xE8005045|8|
|CD-ROM decoder reset control register|ROMDECRST|R/W|H'00|0xE8005100|8|
|CD-ROM decoder reset status register|RSTSTAT|R|H'00|0xE8005101|8|
|Serial sound interface data control register|SSI|R/W|H'18|0xE8005102|8|
|Interrupt flag register|INTHOLD|R/W|H'00|0xE8005108|8|
|Interrupt source mask control register|INHINT|R/W|H'00|0xE8005109|8|
|CD-ROM decoder stream data input register|STRMDIN0|R/W|H'0000|0xE8005200|R: 16|
||||||W: 16, 32|
|CD-ROM decoder stream data input register|STRMDIN2|R/W|H'0000|0xE8005202|16|
|CD-ROM decoder stream data output register|STRMDOUT0|R|H'0000|0xE8005204|16|

## 24.3.1 Enable Control Register (CROMEN)

The enable control register (CROMEN) enables subcode processing and CD-ROM decoding, and stops CD-ROM decoding forcibly.

|||Bit:|7|6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|
||||SUBC_|CROM_|<br>CROM_||
||||EN|EN|STP<br>-<br>-<br>-<br>-<br>-||
|||Initial value:|0|0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**|||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||
|7|SUBC_EN|0|R/W||Subcode Processing Enable||
||||||This bit should be set and cleared simultaneously with CROM_EN. It is||
||||||automatically cleared when decoding|is automatically stopped due to an|
||||||abnormal condition or when CROM_STP = 1||
|6|CROM_EN|0|R/W||CD-ROM Decoding Enable||
||||||When this bit is set to 1, CD-ROM decoding starts after detection of a||
||||||valid sync code. When the bit is cleared to 0, decoding stops on||
||||||completion of the processing for the sector currently being decoded.||
||||||This bit is automatically cleared to 0 when the automatic decode-stopping||
||||||function woks or when CROM_STP =|1.|
|5|CROM_STP|0|R/W||Forcible Stop of CD-ROM Decoding||
||||||When this bit is set to 1, CD-ROM decoding is stopped immediately and||
||||||the SUBC_EN and CROM_EN bits are automatically reset to 0. Before||
||||||decoding can resume, this bit must be cleared to 0.||
|4 to 0|―|All 0|R/W||Reserved||
||||||These bits are always read as 0. The|write value should always be 0.|

## 24.3.2 Sync Code-Based Synchronization Control Register (CROMSY0)

The sync code-based synchronization control register (CROMSY0) selects the sync code maintenance function.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||SY_||SY_|SY_<br>-<br>-<br>-<br>-<br>-||
||||AUT||IEN|DEN||
|||Initial value:|1||0|0<br>0<br>1<br>0<br>0<br>1||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|SY_AUT|1|R/W|||Automatic CD-ROM Sync Code Maintenance Mode||
|||||||When this bit is set to 1, automatic sync maintenance (insertion of sync||
|||||||codes) is applied to obtain the CD-ROM sync codes. While this bit is set,||
|||||||the settings of the SY_IEN and SY_DEN bits are invalid.||
|6|SY_IEN|0|R/W|||Internal Sync Signal Enable||
|||||||Enables the internal sync signal that is produced by the counter in the||
|||||||CD-ROM decoder.||
|||||||When this bit is set to 1 while SY_AUT = 0, synchronization of the CD-||
|||||||ROM data is in interpolated mode, i.e. driven by the internal counter.||
|5|SY_DEN|0|R/W|||Synchronization with External Sync Code||
|||||||Selects constant monitoring for the sync code in the input data and bases||
|||||||synchronization solely on detection of|the code, regardless of the value of|
|||||||the internal counter.||
|||||||The setting of this bit is valid when SY_AUT = 0.||
|4|―|0|R/W|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|3|―|1|R/W|||Reserved||
|||||||This bit is always read as 1. The write value should always be 1.||
|2, 1|―|All 0|R/W|||Reserved||
|||||||These bits are always read as 0. The|write value should always be 0.|
|0|―|1|R/W|||Reserved||
|||||||This bit is always read as 1. The write value should always be 1.||

## **Table 24.2 Register Settings for Sync Code Maintenance Function**

|**SY_AUT**|**SY_IEN**|**SY_DEN**|**Operating Mode**|
|---|---|---|---|
|1|―|―|Automatic sync maintenance mode|
|0|0|1|External sync mode|
|0|1|0|Interpolated sync mode|
|0|1|1|Interpolated sync plus external sync|
||||mode|
|0|0|0|Setting prohibited|

## 24.3.3 Decoding Mode Control Register (CROMCTL0)

The decoding mode control register (CROMCTL0) enables/disables the various functions, selects criteria for mode or form determination, and specifies the sector type. The setting of this register becomes valid at the sector-to-sector transition.

|transition.||||||||
|---|---|---|---|---|---|---|---|
|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
||||MD_<br>DESC||-|MD_<br>AUTO<br>MD_<br>AUTOS1<br>MD_<br>AUTOS2<br>MD_SEC[2:0]||
|||Initial value:|1||0|0<br>0<br>0<br>0<br>1<br>0||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|MD_DESC|1|R/W|||Descrambling Function ON/OFF||
|||||||0: Disables descrambling function||
|||||||1: Enables descrambling function||
|6|―|0|R/W|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|5|MD_AUTO|0|R/W|||Automatic Mode/Form Detection ON/OFF||
|||||||0: OFF||
|||||||1: ON||
|||||||Detectable formats are Mode 0, Mode 1, Mode 2 (non-XA), Mode 2 Form||
|||||||1, and Mode 2 Form 2. If the mode and form cannot be detected, the||
|||||||mode and form of the previous sector is used. If the mode and form of the||
|||||||first sector after decoding starts is undetectable, the setting of the||
|||||||MD_SEC[2:0] bits is used as the initial value.||
|4|MD_AUTOS1|0|R/W|||Criteria for Mode Determination when|MD_AUTO = 1|
|||||||0: Mode determination is made only when the sync code is detected||
|||||||1: Mode determination is always made||
|||||||The setting of this bit is valid only when the MD_AUTO bit is 1. If the||
|||||||mode cannot be determined, the mode of the previous sector is used.||
|||||||When this bit is cleared to 0, mode determination is made only when the||
|||||||sync code is detected for the sector.||
|3|MD_AUTOS2|0|R/W|||Criteria for Mode 2 Form Determination when MD_AUTO = 1||
|||||||0: The sector is assumed to be non-XA if the two form code bytes in the||
|||||||subheader do not match||
|||||||1: No determination of XA or non-XA for the sector. The first form byte is||
|||||||regarded as valid. However, the two form bytes are compared, and the||
|||||||result is reflected in a status bit.||
|||||||The setting of this bit is valid only when the MD_AUTO bit is 1.||
|2 to 0|MD_SEC[2:0]|010|R/W|||Sector Type||
|||||||000: Setting prohibited||
|||||||001: Mode 0||
|||||||010: Mode 1||
|||||||011: Long (Mode 0, Mode 1, or Mode|2 with no EDC/ECC data)|
|||||||100: Setting prohibited||
|||||||101: Mode 2 Form 1||
|||||||110: Mode 2 Form 2||
|||||||111: Mode 2 with automatic form detection||
|||||||If the form cannot be determined when set to B'111, it is processed as||
|||||||Mode 2 not XA.||

## 24.3.4 EDC/ECC Check Control Register (CROMCTL1)

The EDC/ECC check control register (CROMCTL1) controls EDC/ECC checking. The setting of this register becomes valid at the sector-to-sector transition.

|||Bit:|7||6|5<br>4<br>3<br>2|1|0||
|---|---|---|---|---|---|---|---|---|---|
||||M2F2<br>EDC|||MD_DEC[2:0]<br>-<br>-|MD_PQREP[1:0]|||
|||Initial value:|1||1|0<br>1<br>0<br>0|0|1||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||
|7|M2F2EDC|1|R/W|||For Mode 2 Form 2, disables the EDC function for sectors where all bits||||
|||||||of the EDC are 0.||||
|||||||When this bit set to 1 and all bits of the EDC for a Mode 2 Form 2 sector||||
|||||||are 0, an IERR interrupt|is not|generated even if the result of EDC||
|||||||checking is ‘fail’.||||
|6 to 4|MD_DEC[2:0]|101|R/W|||EDC/ECC Checking Mode Select||||
|||||||000: No checking||||
|||||||001: EDC only||||
|||||||010: Q correction + EDC||||
|||||||011: P correction + EDC||||
|||||||100: QP correction + EDC||||
|||||||101: PQ correction + EDC||||
|||||||110: Setting prohibited||||
|||||||111: Setting prohibited||||
|3, 2|―|All 0|R/W|||Reserved||||
|||||||These bits are always read as||0. The|write value should always be 0.|
|1, 0|MD_PQREP[1:0]|01|R/W|||Number of Iterations of PQ or QP Correction||||
|||||||Number of correction iterations when PQ- or QP- correction is specified||||
|||||||by MD_DEC[2:0].||||
|||||||00: Setting prohibited||||
|||||||01: One iteration||||
|||||||10: Two iterations||||
|||||||11: Three iterations||||

## 24.3.5 Automatic Decoding Stop Control Register (CROMCTL3)

The automatic decoding stop control register (CROMCTL3) is used to select abnormal conditions on which decoding will be automatically stopped. When decoding is stopped in response to any of the selected conditions, an IBUF interrupt is generated and the condition is indicated in the CBUFST1 register. The setting of this register becomes valid at the sector-to-sector transition.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|---|
||||STP_||STP_|STP_<br>STP_|||
||||ECC||EDC|-<br>MD<br>MIN<br>-<br>-|-||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0|0||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7|STP_ECC|0|R/W|||When this bit is set to 1, decoding is stopped if an error is found to be not|||
|||||||correctable by ECC correction.|||
|6|STP_EDC|0|R/W|||When this bit is set to 1, decoding is stopped if post-ECC correction EDC|||
|||||||checking indicates an error.|||
|5|―|0|R/W|||Reserved|||
|||||||This bit is always read as 0. The write value should always be 0.|||
|4|STP_MD|0|R/W|||When this bit is set to 1, decoding is stopped if the sector has a mode or|||
|||||||form setting that does not match those of the immediately preceding|||
|||||||sector.|||
|3|STP_MIN|0|R/W|||When this bit is set to 1, decoding is stopped if a non-sequential minutes,|||
|||||||seconds, or frames (1 frame = 1/75 second) value is encountered.|||
|2 to 0|―|All 0|R/W|||Reserved|||
|||||||These bits are always read as 0. The||write value should always be 0.|

## 24.3.6 Decoding Option Setting Control Register (CROMCTL4)

The decoding option setting control register (CROMCTL4) enables/disables buffering control at link block detection, specifies the information indicated by the status register, and controls the ECC correction mode. The setting of this register becomes valid at the sector-to-sector transition.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||-||LINK2|-<br>ER0SEL<br>NO_ECC<br>-<br>-<br>-||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|―|0|R/W|||Reserved||
|||||||Either 0 or 1 can be written to this bit. When it is read, the value written||
|||||||will be read.||
|6|LINK2|0|R/W|||Link Block Detection Condition||
|||||||0: The block is regarded as a link block when either run-out 1 or 2 and||
|||||||both run-in 3 and 4 have been detected.||
|||||||1: The block is regarded as a link block when two out of run-out 1 and 2||
|||||||and “link” have been detected.||
|||||||The condition for setting of the LINK_ON bit in CROMST5 is decoding of||
|||||||the link sector.||
|5|―|0|R/W|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|4|ER0SEL|0|R/W|||CD-ROM Data-Related Status Register Setting Condition||
|||||||0: Information is on the sector being decoded.||
|||||||1: Information is on the latest sector that has been buffered.||
|||||||This condition affects the information|given by bits 5 to 0 in the|
|||||||CROMST0 register, bits 7 to 1 in the CROMST4 and CROMST5||
|||||||registers, and HEAD00 to HEAD02.||
|3|NO_ECC|0|R/W|||ECC correction mode when the result of the EDC check before ECC||
|||||||correction was ‘pass’||
|||||||When this bit is set to 1, ECC correction is not performed if the result of||
|||||||pre-ECC correction EDC checking is|a ‘pass’, regardless of the results of|
|||||||syndrome calculation.||
|2 to 0|―|All 0|R/W|||Reserved||
|||||||These bits are always read as 0. The write value should always be 0.||

## 24.3.7 HEAD20 to HEAD22 Representation Control Register (CROMCTL5)

The HEAD20 to HEAD22 representation control register (CROMCTL5) specifies the representation mode for HEAD20 to HEAD22.

|||Bit:|7||6|5<br>4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|
||||-||-|-<br>-|-|-|-|MSF_||
|||||||||||LBA_SEL||
|||Initial value:|0||0|0<br>0|0|0|0|0||
|||R/W:|R/W||R/W|R/W<br>R/W|R/W|R/W|R/W|R/W||
|||**Initial**||||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||||
|7 to 1|―|All 0|R/W|||Reserved||||||
|||||||These bits are always read as 0. The|||||write value should always be 0.|
|0|MSF_LBA_SEL|0|R/W|||HEAD20 to|HEAD22 Representation Mode|||||
|||||||0: Header MSF is||represented in BCD (decimal) as is||||
|||||||1: Total sector number is represented|||||in HEX (hexadecimal)|

## 24.3.8 Sync Code Status Register (CROMST0)

The sync code status register (CROMST0) indicates various status information in sync code maintenance modes.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
|||||||ST_<br>ST_<br>ST_<br>ST_<br>ST_<br>ST_||
||||-||-|SYIL<br>SYNO<br>BLKS<br>BLKL<br>SECS<br>SECL||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R||R|R<br>R<br>R<br>R<br>R<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7, 6|―|All 0|R|||Reserved||
|||||||These bits are always read as 0 and cannot be modified.||
|5|ST_SYIL|0|R|||Indicates that a sync code was detected at a position where the value in||
|||||||the word counter (used to measure intervals between sync codes) was||
|||||||not correct, but the sync code was ignored and not taken into account in||
|||||||synchronization.||
|||||||This bit is only valid in automatic sync maintenance mode and||
|||||||interpolated sync mode.||
|4|ST_SYNO|0|R|||Indicates that a sync code has not been detected despite the word||
|||||||counter having reached the final value, and synchronization has been||
|||||||continued with the aid of an interpolated sync code.||
|||||||This bit is only valid in automatic sync maintenance mode and||
|||||||interpolated sync mode.||
|3|ST_BLKS|0|R|||Indicates that a sync code was detected at a position where the value in||
|||||||the word counter was not correct, and the sync code was used in||
|||||||synchronization.||
|||||||This bit is only valid in automatic sync maintenance mode and external||
|||||||sync mode.||
|2|ST_BLKL|0|R|||Indicates that a sync code has not been detected despite the word||
|||||||counter having reached the final value, and the period of the sector has||
|||||||been prolonged.||
|||||||This bit is only valid in external sync mode.||
|1|ST_SECS|0|R|||Indicates that a sector has been processed as a short sector with the aid||
|||||||of interpolated sync codes. If this bit is set to 1, stop decoding||
|||||||immediately and retry the procedure starting from the sector prior to the||
|||||||sector currently being decoded.||
|0|ST_SECL|0|R|||Indicates that a sector has been processed as a long sector with the aid||
|||||||of interpolated sync codes. If this bit is set to 1, stop decoding||
|||||||immediately and retry the procedure starting from two sectors prior to the||
|||||||sector currently being decoded.||

## 24.3.9 Post-ECC Header Error Status Register (CROMST1)

The post-ECC header error status register (CROMST1) indicates error status in the post-ECC header.

|||Bit:|7||6|5<br>4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||ER2_|ER2_|ER2_|ER2_||
||||-||-|-<br>-|HEAD0|HEAD1|HEAD2|HEAD3||
|||Initial value:|0||0|0<br>0|0|0|0|0||
|||R/W:|R||R|R<br>R|R|R|R|R||
|||**Initial**||||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||||
|7 to 4|―|All 0|R|||Reserved||||||
|||||||These bits are always read as 0 and cannot be modified.||||||
|3|ER2_HEAD0|0|R|||Indicates an error||in the minutes field|||of the header after ECC correction.|
|2|ER2_HEAD1|0|R|||Indicates an error||status|in the|seconds field of the header after ECC||
|||||||correction.||||||
|1|ER2_HEAD2|0|R|||Indicates an error||in the frames (1 frame = 1/75 second) field of the||||
|||||||header after ECC||correction.||||
|0|ER2_HEAD3|0|R|||Indicates an error||in the mode field of|||the header after ECC correction.|

## 24.3.10 Post-ECC Subheader Error Status Register (CROMST3)

The post-ECC subheader error status register (CROMST3) indicates error status in the post-ECC subheader.

|||Bit:|7||6|5<br>4<br>3<br>2|1<br>0||
|---|---|---|---|---|---|---|---|---|
||||ER2_||ER2_|ER2_<br>ER2_<br>ER2_<br>ER2_|ER2_<br>ER2_||
||||SHEAD0||SHEAD1|SHEAD2<br>SHEAD3<br>SHEAD4<br>HEAD5|HEAD6<br>HEAD7||
|||Initial value:|0||0|0<br>0<br>0<br>0|0<br>0||
|||R/W:|R||R|R<br>R<br>R<br>R|R<br>R||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7|ER2_SHEAD0|0|R|||Indicates that the subheader (file number) still has an error after ECC|||
|||||||correction.|||
|||||||Indicates the error of the SHEAD20 register.|||
|6|ER2_SHEAD1|0|R|||Indicates that the subheader (channel number) still has an error after|||
|||||||ECC correction.|||
|||||||Indicates the error of the SHEAD21 register.|||
|5|ER2_SHEAD2|0|R|||Indicates that the subheader (sub-mode) still has an error after ECC|||
|||||||correction.|||
|||||||Indicates the error of the SHEAD22 register.|||
|4|ER2_SHEAD3|0|R|||Indicates that the subheader (data type) still has an error after ECC|||
|||||||correction.|||
|||||||Indicates the error of the SHEAD23 register.|||
|3|ER2_SHEAD4|0|R|||Indicates that the subheader (file number) still has an error after ECC|||
|||||||correction.|||
|||||||Indicates the error of the SHEAD24 register.|||
|2|ER2_SHEAD5|0|R|||Indicates that the subheader (channel number) still has an error after|||
|||||||ECC correction.|||
|||||||Indicates the error of the SHEAD25 register.|||
|1|ER2_SHEAD6|0|R|||Indicates that the subheader (sub-mode) still has an error after ECC|||
|||||||correction.|||
|||||||Indicates the error of the SHEAD26 register.|||
|0|ER2_SHEAD7|0|R|||Indicates that the subheader (data type) still has an error after ECC|||
|||||||correction.|||
|||||||Indicates the error of the SHEAD27 register.|||

## 24.3.11 Header/Subheader Validity Check Status Register (CROMST4)

The header/subheader validity check status register (CROMST4) indicates errors relating to the automatic mode determination or form determination for Mode 2.

|||Bit:|7|6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|
||||NG_MD|NG_<br>MDCMP1|NG_<br>MDCMP2<br>NG_<br>MDCMP3<br>NG_<br>MDCMP4<br>NG_<br>MDDEF<br>NG_<br>MDTIM1<br>NG_<br>MDTIM2||
|||Initial value:|0|0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R|R|R<br>R<br>R<br>R<br>R<br>R||
|||**Initial**|||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||
|7|NG_MD|0|R||Indicates that the sector mode could not be determined according to the||
||||||automatic mode determination criteria.||
|6|NG_MDCMP1|0|R||Indicates a mismatch between the file number bytes (bytes 16 and 20)||
||||||during the form determination for Mode 2.||
|5|NG_MDCMP2|0|R||Indicates a mismatch between the channel number bytes (bytes 17 and||
||||||21) during the form determination for Mode 2.||
|4|NG_MDCMP3|0|R||Indicates a mismatch between the sub-mode bytes (bytes 18 and 22)||
||||||during the form determination for Mode 2.||
|3|NG_MDCMP4|0|R||Indicates a mismatch between the data-type bytes (bytes 19 and 23)||
||||||during the form determination for Mode 2.||
|2|NG_MDDEF|0|R||Indicates that the mode and form differ from those of the previous sector.||
|1|NG_MDTIM1|0|R||Indicates that the minutes, seconds, or frames (1 frame = 1/75 second)||
||||||value is out of sequence.||
||||||In the continuity check for the next and subsequent sectors, the updated||
||||||values will be used.||
|0|NG_MDTIM2|0|R||Indicates that the minutes, seconds, or frames (1 frame = 1/75 second)||
||||||value was not a BCD value.||
||||||Specifically, this bit means that any half-byte was beyond the range for||
||||||BCD (i.e. was A to F), HEAD01 was greater than H’59, or HEAD02 was||
||||||greater than H'74.||
||||||In the continuity check for the next and subsequent sectors, interpolated||
||||||values will be used.||

## 24.3.12 Mode Determination and Link Sector Detection Status Register (CROMST5)

The mode determination and link sector detection status register (CROMST5) indicates the result of automatic mode determination and link block detection.

|||Bit:|7|6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|
||||ST_AMD[2:0]||ST_MDX LINK_ON<br>LINK_<br>DET<br>LINK_<br>SDET<br>LINK_<br>OUT1||
|||Initial value:|0|0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R|R|R<br>R<br>R<br>R<br>R<br>R||
|||**Initial**|||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||
|7 to 5|ST_AMD[2:0]|000|R||Result of Automatic Mode Determination||
||||||These bits indicate the result of mode|determination when the automatic|
||||||mode determination function is used.||
||||||000: Automatic mode determination function is not used||
||||||001: Mode 0||
||||||010: Mode 1||
||||||011:||
||||||100: Mode 2 not XA||
||||||101: Mode 2 Form 1||
||||||110: Mode 2 Form 2||
||||||111:||
|4|ST_MDX|0|R||Indicates that, when the mode has been manually set rather than||
||||||automatically determined, the mode setting disagrees with the mode as||
||||||recognized by the logic. In this case, the manually set value takes priority.||
|3|LINK_ON|0|R||This bit is set to 1 when a link block was recognized in link block||
||||||determination.||
||||||For the criteria for link block determination, refer to the LINK2 bit in the||
||||||CROMCTL4 register.||
|2|LINK_DET|0|R||Indicates that a link block (run-out 1 to run-in 4) was detected.||
||||||Since detection is based on the data before ECC correction, LINK_DET||
||||||may also be set to 1 if data erroneously happens to contain the same||
||||||code as a link block.||
|1|LINK_SDET|0|R||Indicates that a link block was detected within seven sectors after the||
||||||start of decoding.||
|0|LINK_OUT1|0|R||Indicates that the sector after ECC correction has been identified as a||
||||||run-out 1 sector.||
||||||This bit is only valid when an IERR interrupt is not generated (i.e. when||
||||||ECC correction was successful).||

## 24.3.13 ECC/EDC Error Status Register (CROMST6)

The ECC/EDC error status register (CROMST6) indicates ECC processing error or EDC check error before/after ECC correction.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||ST_||-|ST_<br>ST_<br>ST_<br>ST_<br>ST_<br>ST_||
||||ERR|||ECCABT<br>ECCNG<br>ECCP<br>ECCQ<br>EDC1<br>EDC2||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R||R|R<br>R<br>R<br>R<br>R<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|ST_ERR|0|R|||Indicates that the decoded block after|ECC correction contains any error|
|||||||(even in a single byte).||
|6|―|0|R|||Reserved||
|||||||This bit is always read as 0 and cannot be modified.||
|5|ST_ECCABT|0|R|||Indicates that ECC processing was discontinued.||
|||||||This bit is set to 1 when a transition from sector to sector occurs while||
|||||||ECC correction is in progress. This does not indicate a problem for ECC||
|||||||correction if the BUF_NG bit in the CBUFST2 register is 0 at the same||
|||||||time. Whether or not this is so depends on the timing of the sector||
|||||||transition.||
|4|ST_ECCNG|0|R|||Indicates that error correction was not possible.||
|||||||This bit is also set to 1 on detection of a short sector.||
|3|ST_ECCP|0|R|||Indicates that P-parity errors were not corrected in ECC correction.||
|||||||This bit is only valid when synchronization is normal (the sector is neither||
|||||||short nor long).||
|||||||This bit is set to 1 when the result of syndrome calculation for P parity is||
|||||||other than all 0s.||
|2|ST_ECCQ|0|R|||Indicates that Q-parity errors were not corrected in ECC correction.||
|||||||This bit is only valid when synchronization is normal (the sector is neither||
|||||||short nor long).||
|||||||This bit is set to 1 when the result of syndrome calculation for Q parity is||
|||||||other than all 0s.||
|1|ST_EDC1|0|R|||Indicates that the result of the EDC check before ECC correction was||
|||||||‘fail’.||
|||||||This bit is also set to 1 if a short sector is encountered while EDC is||
|||||||enabled.||
|0|ST_EDC2|0|R|||Indicates that the result of the EDC check after ECC correction was ‘fail’.||

## 24.3.14 Buffer Status Register (CBUFST0)

The buffer status register (CBUFST0) indicates that the system is searching for the first sector to be buffered, or that buffering is in progress.

|||Bit:|7||6|5<br>4<br>3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|
||||BUF_||BUF_||||||
||||REF||ACT|-<br>-<br>-|-|-|-||
|||Initial value:|0||0|0<br>0<br>0|0|0|0||
|||R/W:|R||R|R<br>R<br>R|R|R|R||
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||||
|7|BUF_REF|0|R|||Indicates that the search for the first sector to be buffered is in progress.|||||
|||||||This bit is only valid when the automatic buffering function is used|||||
|||||||(CBUF_AUT = 1).|||||
|6|BUF_ACT|0|R|||Indicates that buffering is in progress.|||||
|5 to 0|―|All 0|R|||Reserved|||||
|||||||These bits are always read as 0 and cannot be modified.|||||

## 24.3.15 Decoding Stoppage Source Status Register (CBUFST1)

The decoding stoppage source status register (CBUFST1) indicates that decoding/buffering has been stopped due to some errors.

A bit in this register can only be set when the corresponding bit in the CROMCTL3 register is set to 1.

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||BUF_||BUF_|BUF_<br>BUF_||
||||ECC||EDC|-<br>MD<br>MIN<br>-<br>-<br>-||
|||Initial value:|0||0|0<br>0<br>0<br>0<br>0<br>0||
|||R/W:|R||R|R<br>R<br>R<br>R<br>R<br>R||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|BUF_ECC|0|R|||Indicates that decoding and buffering|have been stopped because of an|
|||||||error that is not correctable by using the ECC.||
|6|BUF_EDC|0|R|||Indicates that decoding and buffering|have been stopped because the|
|||||||post-ECC correction EDC check indicated an error.||
|5|―|0|R|||Reserved||
|||||||This bit is always read as 0 and cannot be modified.||
|4|BUF_MD|0|R|||Indicates that decoding and buffering|have been stopped because the|
|||||||current sector is in a mode or form differing from that of the previous||
|||||||sector.||
|3|BUF_MIN|0|R|||Indicates that decoding and buffering|have been stopped because a non-|
|||||||sequential minutes, seconds, or frames (1 frame = 1/75 second) value||
|||||||has been encountered.||
|2 to 0|―|All 0|R|||Reserved||
|||||||These bits are always read as 0 and cannot be modified.||

## 24.3.16 Buffer Overflow Status Register (CBUFST2)

The buffer overflow status register (CBUFST2) indicates that a sector-to-sector transition occurred before data transfer to the buffer is completed.

|the buffer|is completed.||||||||
|---|---|---|---|---|---|---|---|---|
|||Bit:|7||6|5<br>4|3<br>2<br>1<br>0||
||||BUF_||||||
||||NG||-|-<br>-|-<br>-<br>-<br>-||
|||Initial value:|0||0|0<br>0|0<br>0<br>0<br>0||
|||R/W:|R||R|R<br>R|R<br>R<br>R<br>R||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7|BUF_NG|0|R|||Indicates that a sector-to-sector transition has occurred before the data|||
|||||||transfer to the buffer is completed. This bit is set to 1 when the data of a|||
|||||||third sector|are input while data for the output stream from the CD-ROM||
|||||||decoder remains unread. No interrupt is generated. Once this bit has|||
|||||||been set to|1, its value will not recover unless it is reset by the||
|||||||LOGICRST bit in the ROMDECRST register.|||
|6 to 0|―|All 0|R|||Reserved|||
|||||||These bits are always read as 0 and cannot be modified.|||

## 24.3.17 Pre-ECC Correction Header: Minutes Data Register (HEAD00)

The pre-ECC correction header: minutes data register (HEAD00) indicates the minutes value in the header before ECC correction.

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||HEAD00[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|HEAD00[7:0]|All 0|R||Minutes Value in|||Header|before|ECC Correction|

## 24.3.18 Pre-ECC Correction Header: Seconds Data Register (HEAD01)

The pre-ECC correction header: seconds data register (HEAD01) indicates the seconds value in the header before ECC correction.

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||HEAD01[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|HEAD01[7:0]|All 0|R||Seconds Value in|||Header|before|ECC Correction|

## 24.3.19 Pre-ECC Correction Header: Frames (1/75 Second) Data Register (HEAD02)

The pre-ECC correction header: frames (1/75 second) data register (HEAD02) indicates the frames value (1 frame = 1/75 second) in the header before ECC correction.

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||HEAD02[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|HEAD02[7:0]|All 0|R||Frames Value (1|||frame = 1/75||second) in Header before ECC Correction|

## 24.3.20 Pre-ECC Correction Header: Mode Data Register (HEAD03)

The pre-ECC correction header: mode data register (HEAD03) indicates the mode value in the header before ECC correction.

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||HEAD03[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|HEAD03[7:0]|All 0|R||Mode|Value|in Header||before|ECC Correction|

## 24.3.21 Pre-ECC Correction Subheader: File Number (Byte 16) Data Register (SHEAD00)

The pre-ECC correction subheader: file number (byte 16) data register (SHEAD00) indicates the file number value in the subheader before ECC correction (byte 16).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD00[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD00[7:0]|All 0|R||Indicates file||number value in the subheader before ECC correction (byte||||
||||||16).||||||
||||||For|sectors not in||Mode 2, this register contains the byte of data at the|||
||||||corresponding position.||||||

## 24.3.22 Pre-ECC Correction Subheader: Channel Number (Byte 17) Data Register (SHEAD01)

The pre-ECC correction subheader: channel number (byte 17) data register (SHEAD01) indicates the channel number value in the subheader before ECC correction (byte 17).

|||Bit:|7|6|5<br>4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||||||SHEAD01[7:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0|
|||R/W:|R|R|R<br>R<br>R|R|R|R|
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||
|7 to 0|SHEAD01[7:0]|All 0|R||Indicates channel|number value in the subheader before ECC correction|||
||||||(byte 17).||||
||||||For sectors not in|Mode 2, this register contains the byte of data at the|||
||||||corresponding position.||||

## 24.3.23 Pre-ECC Correction Subheader: Sub-Mode (Byte 18) Data Register (SHEAD02)

The pre-ECC correction subheader: sub-mode (byte 18) data register (SHEAD02) indicates the sub-mode value in the subheader before ECC correction (byte 18).

|||Bit:|7|6|5|4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD02[7:0]||||
|||Initial value:|0|0|0|0<br>0|0|0|0|
|||R/W:|R|R|R|R<br>R|R|R|R|
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|7 to 0|SHEAD02[7:0]|All 0|R||Indicates sub-mode value in the subheader before ECC correction (byte|||||
||||||18).|||||
||||||For|sectors not in Mode 2, this|||register contains the byte of data at the|
||||||corresponding position.|||||

## 24.3.24 Pre-ECC Correction Subheader: Data Type (Byte 19) Data Register (SHEAD03)

The pre-ECC correction subheader: data type (byte 19) data register (SHEAD03) indicates the data type value in the subheader before ECC correction (byte 19).

|||Bit:|7|6|5|4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD03[7:0]||||
|||Initial value:|0|0|0|0<br>0|0|0|0|
|||R/W:|R|R|R|R<br>R|R|R|R|
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|7 to 0|SHEAD03[7:0]|All 0|R||Indicates data type value|||in the subheader before ECC correction (byte||
||||||19).|||||
||||||For|sectors not in Mode 2, this register contains the byte of data at the||||
||||||corresponding position.|||||

## 24.3.25 Pre-ECC Correction Subheader: File Number (Byte 20) Data Register (SHEAD04)

The pre-ECC correction subheader: file number (byte 20) data register (SHEAD04) indicates the file number value in the subheader before ECC correction (byte 20).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD04[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD04[7:0]|All 0|R||Indicates file||number value in the subheader before ECC correction (byte||||
||||||20).||||||
||||||For|sectors not in||Mode 2, this register contains the byte of data at the|||
||||||corresponding position.||||||

## 24.3.26 Pre-ECC Correction Subheader: Channel Number (Byte 21) Data Register (SHEAD05)

The pre-ECC correction subheader: channel number (byte 21) data register (SHEAD05) indicates the channel number

value in the subheader before ECC correction (byte 21).

|||Bit:|7|6|5<br>4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||||||SHEAD05[7:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0|
|||R/W:|R|R|R<br>R<br>R|R|R|R|
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||
|7 to 0|SHEAD05[7:0]|All 0|R||Indicates channel|number value in the subheader before ECC correction|||
||||||(byte 21).||||
||||||For sectors not in|Mode 2, this register contains the byte of data at the|||
||||||corresponding position.||||

## 24.3.27 Pre-ECC Correction Subheader: Sub-Mode (Byte 22) Data Register (SHEAD06)

The pre-ECC correction subheader: sub-mode (byte 22) data register (SHEAD06) indicates the sub-mode value in the subheader before ECC correction (byte 22).

|||Bit:|7|6|5|4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD06[7:0]||||
|||Initial value:|0|0|0|0<br>0|0|0|0|
|||R/W:|R|R|R|R<br>R|R|R|R|
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|7 to 0|SHEAD06[7:0]|All 0|R||Indicates sub-mode value in the subheader before ECC correction (Byte|||||
||||||22).|||||
||||||For|sectors not in Mode 2, this|||register contains the byte of data at the|
||||||corresponding position.|||||

## 24.3.28 Pre-ECC Correction Subheader: Data Type (Byte 23) Data Register (SHEAD07)

The pre-ECC correction subheader: data type (byte 23) data register (SHEAD07) indicates the data type value in the subheader before ECC correction (byte 23).

|||Bit:|7|6|5|4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD07[7:0]||||
|||Initial value:|0|0|0|0<br>0|0|0|0|
|||R/W:|R|R|R|R<br>R|R|R|R|
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|7 to 0|SHEAD07[7:0]|All 0|R||Indicates data type value|||in the subheader before ECC correction (Byte||
||||||23).|||||
||||||For|sectors not in Mode 2, this register contains the byte of data at the||||
||||||corresponding position.|||||

## 24.3.29 Post-ECC Correction Header: Minutes Data Register (HEAD20)

The post-ECC correction header: minutes data register (HEAD20) indicates the minutes value in the header after ECC correction.

|||Bit:|7|6|5<br>4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|
||||||HEAD20[7:0]|||||
|||Initial value:|0|0|0<br>0|0|0|0|0|
|||R/W:|R|R|R<br>R|R|R|R|R|
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|7 to 0|HEAD20[7:0]|All 0|R||Indicates minutes||value in the header after ECC correction.|||
||||||When MSF_LBA_SEL =|||1, this register indicates the first byte (1/3) of the||
||||||total number|of sectors calculated from M, S, and F.||||

## 24.3.30 Post-ECC Correction Header: Seconds Data Register (HEAD21)

The post-ECC correction header: seconds data register (HEAD21) indicates the seconds value in the header after ECC correction.

|||Bit:|7|6|5<br>4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||||||HEAD21[7:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0|
|||R/W:|R|R|R<br>R<br>R|R|R|R|
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||
|7 to 0|HEAD21[7:0]|All 0|R||Indicates seconds value||in the|header after ECC correction.|
||||||When MSF_LBA_SEL =||1, this|register indicates the second byte (2/3) of|
||||||the total number of sectors calculated from M, S, and F.||||

## 24.3.31 Post-ECC Correction Header: Frames (1/75 Second) Data Register (HEAD22)

The post-ECC correction header: frames (1/75 second) data register (HEAD22) indicates the frames value (1 frame = 1/ 75 seconds) in the header after ECC correction.

|||Bit:|7|6|5<br>4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||||||HEAD22[7:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0|
|||R/W:|R|R|R<br>R<br>R|R|R|R|
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||
|7 to 0|HEAD22[7:0]|All 0|R||Indicates frames value in the header after ECC correction.||||
||||||When MSF_LBA_SEL =||1, this register indicates the third byte (3/3) of||
||||||the total number of sectors calculated from M, S, and F.||||

## 24.3.32 Post-ECC Correction Header: Mode Data Register (HEAD23)

The post-ECC correction header: mode data register (HEAD23) indicates the mode value in the header after ECC correction.

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||HEAD23[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|HEAD23[7:0]|All 0|R||Indicates mode|||value in the header after ECC correction.|||

## 24.3.33 Post-ECC Correction Subheader: File Number (Byte 16) Data Register (SHEAD20)

The post-ECC correction subheader: file number (byte 16) data register (SHEAD20) indicates the file number value in the subheader after ECC correction (byte 16).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD20[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD20[7:0]|All 0|R||Indicates file||number value||in the subheader after ECC correction (byte||
||||||16).||||||

## 24.3.34 Post-ECC Correction Subheader: Channel Number (Byte 17) Data Register (SHEAD21)

The post-ECC correction subheader: channel number (byte 17) data register (SHEAD21) indicates the channel number value in the subheader after ECC correction (byte 17).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD21[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD21[7:0]|All 0|R||Indicates channel|||number|value|in the subheader after ECC correction|
||||||(byte|17).|||||

## 24.3.35 Post-ECC Correction Subheader: Sub-Mode (Byte 18) Data Register (SHEAD22)

The post-ECC correction subheader: sub-mode (byte 18) data register (SHEAD22) indicates the sub-mode value in the subheader after ECC correction (byte 18).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD22[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD22[7:0]|All 0|R||Indicates sub-mode|||value|in the subheader after ECC correction (byte||
||||||18).||||||

## 24.3.36 Post-ECC Correction Subheader: Data Type (Byte 19) Data Register (SHEAD23)

The post-ECC correction subheader: data type (byte 19) data register (SHEAD23) indicates the data type value in the subheader after ECC correction (byte 19).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD23[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD23[7:0]|All 0|R||Indicates data type|||value|in the|subheader after ECC correction (byte 19).|

## 24.3.37 Post-ECC Correction Subheader: File Number (Byte 20) Data Register (SHEAD24)

The post-ECC correction subheader: file number (byte 20) data register (SHEAD24) indicates the file number value in the subheader after ECC correction (byte 20).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD24[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD24[7:0]|All 0|R||Indicates file||number value||in the subheader after ECC correction (byte||
||||||20).||||||

## 24.3.38 Post-ECC Correction Subheader: Channel Number (Byte 21) Data Register (SHEAD25)

The post-ECC correction subheader: channel number (byte 21) data register (SHEAD25) indicates the channel number value in the subheader after ECC correction (byte 21).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD25[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD25[7:0]|All 0|R||Indicates channel|||number|value|in the subheader after ECC correction|
||||||(byte|21).|||||

## 24.3.39 Post-ECC Correction Subheader: Sub-Mode (Byte 22) Data Register (SHEAD26)

The post-ECC correction subheader: sub-mode (byte 22) data register (SHEAD26) indicates the sub-mode value in the subheader after ECC correction (byte 22).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD26[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD26[7:0]|All 0|R||Indicates sub-mode|||value|in the subheader after ECC correction (byte||
||||||22).||||||

## 24.3.40 Post-ECC Correction Subheader: Data Type (Byte 23) Data Register (SHEAD27)

The post-ECC correction subheader: data type (byte 23) data register (SHEAD27) indicates the data type value in the subheader after ECC correction (byte 23).

|||Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
|||||||SHEAD27[7:0]|||||
|||Initial value:|0|0|0|0|0|0|0|0|
|||R/W:|R|R|R|R|R|R|R|R|
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 0|SHEAD27[7:0]|All 0|R||Indicates data type|||value|in the|subheader after ECC correction (byte 23).|

## 24.3.41 Automatic Buffering Setting Control Register  (CBUFCTL0)

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||CBUF_<br>AUT||CBUF_<br>EN|-<br>CBUF_MD[1:0]<br>CBUF_<br>TS<br>CBUF_<br>Q<br>-||
|||Initial value:|0||0|0<br>0<br>0<br>1<br>0<br>0||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|CBUF_AUT|0|R/W|||Automatic Buffering Function ON/OFF||
|||||||When this bit is to be set or cleared while CROM_EN = 1, CBUF_EN||
|||||||should also be set or cleared simultaneously. Otherwise, the validity of||
|||||||the status indications in CBUFST0, CBUFST1 and CBUFST2 cannot be||
|||||||guaranteed.||
|||||||0: Automatic buffering is OFF.||
|||||||1: Automatic buffering is ON.||
|6|CBUF_EN|0|R/W|||Buffering to Buffer RAM Enable||
|||||||This bit turns on/off buffering in both automatic and manual buffering||
|||||||modes. In manual buffering mode, set this bit after generation of the ISEC||
|||||||interrupt. This bit is automatically reset when automatic buffering stops.||
|||||||0: Buffering is OFF.||
|||||||1: Buffering is ON.||
|5|―|0|R/W|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|4, 3|CBUF_MD[1:0]|00|R/W|||Start-sector detection mode when the automatic buffering function is in||
|||||||use||
|||||||00: The header values for the previous and current sectors must be in||
|||||||sequence.||
|||||||01: The header value detected in the|current sector must be in sequence|
|||||||with the interpolated value.||
|||||||10: A current sector with any header value is OK.||
|||||||11: Start-sector detection is based on the interpolated value even if the||
|||||||current sector is not detected.||
|2|CBUF_TS|1|R/W|||CBUFCTL1 to CBUFCTL3 Setting Mode||
|||||||0: CBUFCTL1 to CBUFCTL3: BCD (in decimal)||
|||||||1: Total number of sectors (in hexadecimal)||
|1|CBUF_Q|0|R/W|||Q-channel code buffering data specification in the case of a CRC error in||
|||||||the Q-channel code||
|||||||0: The values for the last sector for which the CRC returned a correct||
|||||||result are buffered.||
|||||||1: The erroneous data is buffered as is.||
|||||||Note: Since subcodes are not input with this LSI, always set this bit to 1.||
|0|―|0|R/W|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||

## 24.3.42 Automatic Buffering Start Sector Setting: Minutes Control Register (CBUFCTL1)

The automatic buffering start sector setting: minutes control register (CBUFCTL1) indicates the minutes value in the header for the first sector to be buffered.

|||Bit:|7|6|5<br>4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|
||||||BS_MIN[7:0]|||||
|||Initial value:|0|0|0<br>0|0|0|0|0|
|||R/W:|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|7 to 0|BS_MIN[7:0]|All 0|R/W||Indicates setting of the|||minutes|value in the header for the first sector to|
||||||be buffered.|||||

## 24.3.43 Automatic Buffering Start Sector Setting: Seconds Control Register (CBUFCTL2)

The automatic buffering start sector setting: seconds control register (CBUFCTL2) indicates the seconds value in the header for the first sector to be buffered.

|||Bit:|7|6|5<br>4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|
||||||BS_SEC[7:0]|||||
|||Initial value:|0|0|0<br>0|0|0|0|0|
|||R/W:|R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||||
|7 to 0|BS_SEC[7:0]|All 0|R/W||Indicates setting of the|||seconds|value in the header for the first sector to|
||||||be buffered.|||||

## 24.3.44 Automatic Buffering Start Sector Setting: Frames Control Register (CBUFCTL3)

The automatic buffering start sector setting: frames control register (CBUFCTL3) indicates the frames (1 frame = 1/75 second) value in the header for the first sector to be buffered.

|||Bit:|7|6|5<br>4<br>3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||||||BS_FRM[7:0]||||
|||Initial value:|0|0|0<br>0<br>0|0|0|0|
|||R/W:|R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W|
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||
|7 to 0|BS_FRM[7:0]|All 0|R/W||Indicates setting of the frames|||(1 frame = 1/75 second) value in the|
||||||header for the first sector to be|||buffered.|

## 24.3.45 ISY Interrupt Source Mask Control Register (CROMST0M)

The ISY interrupt source mask control register (CROMST0M) masks the ISY interrupt sources specified by the bits in the sync code status register (CROMST0).

|||Bit:|7||6|5<br>4|3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|
||||-||-|ST_<br>ST_|ST_<br>ST_<br>ST_<br>ST_||
|||||||SYILM<br>SYNOM|BLKSM<br>BLKLM<br>SECSM<br>SECLM||
|||Initial value:|0||0|0<br>0|0<br>0<br>0<br>0||
|||R/W:|R/W||R/W|R/W<br>R/W|R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7, 6|―|All 0|R/W|||Reserved|||
|||||||These bits are always read as 0. The||write value should always be 0.|
|5|ST_SYILM|0|R/W|||ISY interrupt ST_SYIL (bit 5 in the CROMST0 register) source mask|||
|4|ST_SYNOM|0|R/W|||ISY interrupt ST_SYNO (bit 4 in the CROMST0 register) source mask|||
|3|ST_BLKSM|0|R/W|||ISY interrupt ST_BLKS (bit 3 in the CROMST0 register) source mask|||
|2|ST_BLKLM|0|R/W|||ISY interrupt ST_BLKL (bit 2 in the CROMST0 register) source mask|||
|1|ST_SECSM|0|R/W|||ISY interrupt ST_SECS (bit 1 in the CROMST0 register) source mask|||
|0|ST_SECLM|0|R/W|||ISY interrupt ST_SECL (bit 0 in the CROMST0 register) source mask|||

## 24.3.46 CD-ROM Decoder Reset Control Register (ROMDECRST)

The CD-ROM decoder reset control register (ROMDECRST) resets the random logic of the CD-ROM decoder and clears the RAM in the CD-ROM decoder.

|||Bit:|7||6|5<br>4<br>3<br>2|1|0||
|---|---|---|---|---|---|---|---|---|---|
||||LOGI||RAM|-<br>-<br>-<br>-|-|-||
||||CRST||RST|||||
|||Initial value:|0||0|0<br>0<br>0<br>0|0|0||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||
|7|LOGICRST|0|R/W|||CD-ROM Decoder Random Logic Reset Signal||||
|||||||A reset signal is output while this bit is set to 1.||||
|6|RAMRST|0|R/W|||CD-ROM Decoder RAM|Clearing Signal|||
|||||||Refer to the RAMCLRST bit in||the RSTSTAT register to confirm that RAM||
|||||||clearing is complete.||||
|5 to 0|―|All 0|R/W|||Reserved||||
|||||||These bits are always read as||0. The|write value should always be 0.|

Note: • Before setting LOGICRST to 1, make sure that the RAMRST bit is cleared to 0 and then write B'10000000 to this register.

## 24.3.47 CD-ROM Decoder Reset Status Register (RSTSTAT)

The CD-ROM decoder reset status register (RSTSTAT) indicates that the RAM in the CD-ROM decoder has been cleared.

|cleared.||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|||Bit:|7||6|5<br>4|3|2|1|0||
||||RAM||-|-<br>-|-|-|-|-||
||||CLRST|||||||||
|||Initial value:|0||0|0<br>0|0|0|0|0||
|||R/W:|R||R|R<br>R|R|R|R|R||
|||**Initial**||||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||||
|7|RAMCLRST|0|R|||This bit is set to 1 on completion of RAM clearing after the RAMRST bit in||||||
|||||||ROMDECRST is set to 1. The bit is cleared by writing a 0 to the RAMRST||||||
|||||||bit.||||||
|6 to 0|―|All 0|R|||Reserved||||||
|||||||These bits are always read as 0 and cannot be modified.||||||

## 24.3.48 Serial Sound Interface Data Control Register (SSI)

The serial sound interface data control register (SSI) provides various settings related to the data stream. For the operation corresponding to the setting of this register, refer to section 24.4.1, Endian Conversion for Data in the Input Stream .

|||Bit:|7||6|5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||BYTEND||BITEND|BUFEND0[1:0]<br>BUFEND1[1:0]<br>-<br>-||
|||Initial value:|0||0|0<br>1<br>1<br>0<br>0<br>0||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|BYTEND|0|R/W|||Specifies the endian of input data from the serial sound interface.||
|||||||When this bit is set to 1, byte 0 and byte 1 in STRMDIN0 are swapped.||
|||||||This is the same for STRMDIN2.||
|6|BITEND|0|R/W|||Specifies treatment of the bit order of the input data from the serial sound||
|||||||interface.||
|||||||When this bit is set to 1, the bits within each byte are rearranged to place||
|||||||them in reverse order, bit 0bit 7 to|bit 7bit 0.|
|5, 4|BUFEND0[1:0]|01|R/W|||These bits select whether to change the order of 16-bit units of data||
|||||||transferred from the serial sound interface or suppress the stream data.||
|||||||In the serial sound interface, either “padding mode” or “non-padding||
|||||||mode” is selectable. In non-padding mode, each 32 bits of data||
|||||||transferred from the serial sound interface are transferred as CD-ROM||
|||||||data. Since the CD-ROM decoder has two 16-bit input data registers, the||
|||||||order of the 16-bit data can be swapped within the 32 bits. On the other||
|||||||hand, in padding mode each 32 bits of data transferred from the serial||
|||||||sound interface includes padding. Since the padding has no meaning, it||
|||||||should be kept out of the input stream to the decoder. This suppression||
|||||||can be specified by the setting of this|register.|
|||||||The CD-ROM decoder handles data as a stream of 16-bit data, and this||
|||||||register controls which 16-bit portion of each 32 bits of data transferred||
|||||||from the serial sound interface should be input first.||
|||||||00: The 16 bits of stream data that would otherwise be processed first is||
|||||||discarded.||
|||||||01: The higher-order 16 bits of each 32 bits of data received from the||
|||||||serial sound interface are placed first in the stream to the decoder.||
|||||||10: The lower-order 16 bits of each 32|bits of data received from the serial|
|||||||sound interface are placed first in the stream to the decoder.||
|||||||11: Setting prohibited||
|3, 2|BUFEND1[1:0]|10|R/W|||These bits select whether to change the order of 16-bit units of data||
|||||||transferred from the serial sound interface or suppress the stream data.||
|||||||In the serial sound interface, either “padding mode” or “non-padding||
|||||||mode” is selectable. In non-padding mode, each 32 bits of data||
|||||||transferred from the serial sound interface are transferred as CD-ROM||
|||||||data. Since the CD-ROM decoder has two 16-bit input data registers, the||
|||||||order of the 16-bit data can be swapped within the 32 bits. On the other||
|||||||hand, in padding mode each 32 bits of data transferred from the serial||
|||||||sound interface includes padding. Since the padding has no meaning, it||
|||||||should be kept out of the input stream to the decoder. This suppression||
|||||||can be specified by the setting of this|register.|
|||||||The CD-ROM decoder handles data as a stream of 16-bit data, and this||
|||||||register controls which 16-bit portion of each 32 bits of data transferred||
|||||||from the serial sound interface should be input second.||
|||||||00: The 16 bits of stream data that would otherwise be processed second||
|||||||is discarded.||
|||||||01: The higher-order 16 bits of each 32 bits of data received from the||
|||||||serial sound interface are placed second in the stream to the decoder.||
|||||||10: The higher-order 16 bits of each 32 bits of data received from the||
|||||||serial sound interface are placed second in the stream to the decoder.||
|||||||11: Setting prohibited||
|1, 0|―|All 0|R/W|||Reserved||
|||||||These bits are always read as 0. The|write value should always be 0.|

## 24.3.49 Interrupt Flag Register (INTHOLD)

The interrupt flag register (INTHOLD) consists of various interrupt flags.

|||Bit:|7||6|5<br>4<br>3<br>2|1|0||
|---|---|---|---|---|---|---|---|---|---|
||||ISEC||ITARG|ISY<br>IERR<br>IBUF<br>IREADY|-|-||
|||Initial value:|0||0|0<br>0<br>0<br>0|0|0||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W||
|||**Initial**||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||||
|7|ISEC|0|R/W|||ISEC Interrupt Flag||||
|||||||Writing 0 to this bit is only possible after 1 has been read from it.||||
|6|ITARG|0|R/W|||ITARG Interrupt Flag||||
|||||||Writing 0 to this bit is only possible after 1 has been read from it.||||
|5|ISY|0|R/W|||ISY Interrupt Flag||||
|||||||Writing 0 to this bit is only possible after 1 has been read from it.||||
|4|IERR|0|R/W|||IERR Interrupt Flag||||
|||||||Writing 0 to this bit is only possible after 1 has been read from it.||||
|3|IBUF|0|R/W|||IBUF Interrupt Flag||||
|||||||Writing 0 to this bit is only possible after 1 has been read from it.||||
|2|IREADY|0|R/W|||IREADY Interrupt Flag||||
|||||||Writing 0 to this bit is only possible after 1 has been read from it.||||
|1, 0|―|All 0|R/W|||Reserved||||
|||||||These bits are always read as 0. The|||write value should always be 0.|

## 24.3.50 Interrupt Source Mask Control Register (INHINT)

The interrupt source mask control register (INHINT) controls masking of various interrupt requests in the CD-ROM decoder.

|decoder.|||||||||
|---|---|---|---|---|---|---|---|---|
|||Bit:|7||6|5<br>4<br>3<br>2|1<br>0||
||||INH||INH|INH<br>INH<br>INH<br>INH|PREINH<br>PREINH||
||||ISEC||ITARG|ISY<br>IERR<br>IBUF<br>IREADY|REQDM<br>IREADY||
|||Initial value:|0||0|0<br>0<br>0<br>0|0<br>0||
|||R/W:|R/W||R/W|R/W<br>R/W<br>R/W<br>R/W|R/W<br>R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7|INHISEC|0|R/W|||ISEC Interrupt Mask|||
|||||||When set to 1, inhibits ISEC interrupt||requests.|
|6|INHITARG|0|R/W|||ITARG Interrupt Mask|||
|||||||When set to 1, inhibits ITARG interrupt requests.|||
|5|INHISY|0|R/W|||ISY Interrupt Mask|||
|||||||When set to 1, inhibits ISY interrupt requests.|||
|4|INHIERR|0|R/W|||IERR Interrupt Mask|||
|||||||When set to 1, inhibits IERR interrupt||requests.|
|3|INHIBUF|0|R/W|||IBUF Interrupt Mask|||
|||||||When set to 1, inhibits IBUF interrupt requests.|||
|2|INHIREADY|0|R/W|||IREADY Interrupt Mask|||
|||||||When set to 1, inhibits IREADY interrupt requests.|||
|1|PREINHREQDM|0|R/W|||Inhibits setting of the DMA-transfer-request interrupt source flag for the|||
|||||||output data stream.|||
|||||||When this bit is set to 1,|the DMA-transfer-request interrupt source is not||
|||||||retained.|||
|0|PREINHIREADY|0|R/W|||Inhibits setting of the IREADY interrupt flag.|||
|||||||When this bit is set to 1,|the IREADY interrupt source is not retained.||

## 24.3.51 CD-ROM Decoder Stream Data Input Register (STRMDIN0)

The CD-ROM decoder stream data input register (STRMDIN0) holds the higher 2 bytes (from MSB) of the 4 bytes of data that is to be input to the CD-ROM decoder.

||||Bit:|15|14|13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||STRMDIN[31:16]|||||||
||||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**|||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**|||||||
|15|to|0|STRMDIN[31:16]|||All 0||R/W||Indicates the higher 2 bytes (from MSB) of the||||4-bytes of data that is to be|||
|||||||||||input to the CD-ROM decoder.|||||||
|||||||||||The CD-ROM decoder|has a 4-byte wide data window as a data input||||||
|||||||||||register to handle the data input||to this register as a stream data. The|||||
|||||||||||amount of data for one|sector is|2352|bytes.||||

## 24.3.52 CD-ROM Decoder Stream Data Input Register (STRMDIN2)

The CD-ROM decoder stream data input register (STRMDIN2) holds the lower 2 bytes (from LSB) of the 4 bytes of data that is to be input to the CD-ROM decoder.

||||Bit:|15|14|13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||STRMDIN[15:0]|||||||
||||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|||||||**Initial**|||||||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**|||||||
|15|to|0|STRMDIN[15:0]|||All 0||R/W||Indicates the lower 2 bytes (from LSB) of the||||4-bytes of data that is to be|||
|||||||||||input to the CD-ROM decoder.|||||||
|||||||||||The CD-ROM decoder|has a 4-byte wide data window as a data input||||||
|||||||||||register to handle the data input||to this register as a stream data. The|||||
|||||||||||amount of data for one|sector is|2352|bytes.||||

## 24.3.53 CD-ROM Decoder Stream Data Output Register (STRMDOUT0)

The CD-ROM decoder stream data output register (STRMDOUT0) holds 2 bytes that is to be output from the CD-ROM decoder.

||||Bit:|15|14|13|12|11|10|9<br>8<br>7<br>6<br>5<br>4|3<br>2<br>1<br>0|
|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||STRMDOUT[15:0]||
||||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0<br>0<br>0<br>0|
||||R/W:|R|R|R|R|R|R|R<br>R<br>R<br>R<br>R<br>R|R<br>R<br>R<br>R|
|||||||**Initial**||||||
|**Bit**|||**Bit Name**|||**Value**||**R/W**||**Description**||
|15|to|0|STRMDOUT|||H'0000||R||Indicates 2 bytes that are to be output from the CD-ROM decoder.||
||||[15:0]|||||||The CD-ROM decoder has a 2-byte wide data window or set of registers||
|||||||||||for the output of decoded data. Every|time the relevant register is|
|||||||||||accessed, further data of access size are output sequentially in the output||
|||||||||||format that is separately defined. The|amount of data for one sector is|
|||||||||||2768 bytes. Always read 2768 bytes.||

## 24.4 Operation

## 24.4.1 Endian Conversion for Data in the Input Stream

Stream data must be input to the core of the CD-ROM decoder in order according to the CD-ROM data format specifications. In some systems, however, the order of the data from the serial sound interface may have to be changed or the data will have been padded before transfer. To cope with this, the stream data input control section is capable of swapping the order of the data and preventing the input of padding data to the core of the CD-ROM decoder. These functions are controlled through the serial sound interface data control register (SSI).

Figure 24.6 shows a case where the upper and lower 16 bits of the data, consisting of padding data plus the first 2 bytes of sync code, that is, H'000000FF, are swapped (H'00FF0000) and input to the CD-ROM decoder as the stream data.

**==> picture [316 x 180] intentionally omitted <==**

**----- Start of picture text -----**<br>
STRMDIN0 BUFEND0[1:0] = 01<br>H'00FF<br>H'00FF<br>H'00FF<br>Core of CD-ROM decoder<br>STRMDIN2<br>H'0000<br>BUFEND1[1:0] = 00<br>BYTEND = 0<br>H'FF<br>H'00<br>H'00<br>H'00<br>**----- End of picture text -----**<br>

**Figure 24.6 Example of Padded Stream Data Control by the SSI Register**

Figure 24.7 shows a case of input stream data that has no padding (H'12345678). The upper and lower 16 bits of data are swapped (H'56781234) for input to the CD-ROM decoder.

**==> picture [316 x 173] intentionally omitted <==**

**----- Start of picture text -----**<br>
STRMDIN0 BUFEND0[1:0] = 10<br>H'5678 H'1234 is input first.<br>H'1234 H'5678 is input next.<br>H'1234 H'5678<br>Core of CD-ROM decoder<br>STRMDIN2<br>H'5678<br>H'1234<br>BUFEND1[1:0] = 01<br>BYTEND = 0<br>H'78<br>H'56<br>H'34<br>H'012<br>**----- End of picture text -----**<br>

**Figure 24.7 Example of Non-Padded Stream Data Control by the SSI Register**

## 24.4.2 Sync Code Maintenance Function

Each sector of CD-ROM data consists of 2352 bytes starting with H'00FFFFFFFFFFFFFFFFFFFF00 (sync code). However, a scratch on the disc or some other factor might lead to erroneous recognition of the sync code sequence at the wrong time. Conversely, a sync code might not be detected at a point where it should be detected. As a solution to these problems, the CD-ROM decoder of this LSI has a sync-code maintenance function, which operates to ignore sync codes detected at abnormal times and maintain the appearance of the sync code at the expected times when it is not actually detected on the disc.

The operating modes of the sync-code maintenance function are listed below. For details on the settings, refer to section 24.3.2, Sync Code-Based Synchronization Control Register (CROMSY0) , and Table 24.2 .

- Automatic sync maintenance mode

- External sync mode

- Interpolated sync mode

- Interpolated sync plus external sync mode

## (1) Automatic Sync Maintenance Mode

In automatic sync maintenance mode, the sync code is ignored if detected within the one-sector (2352-byte) period. Furthermore, if a sync code is not detected at the point where a next sector should start, sync code maintenance is applied. If synchronization timing has changed, re-synchronization is performed at the point where a sync code is detected within 2352 bytes after the change.

Therefore, this mode is effective in rejecting abnormal sync patterns and following changes in synchronization timing. Note, however, that this mode cannot achieve synchronization with the first sector after a change to the synchronization timing.

Figure 24.8 shows operation in the case of normal sync-code detection, Figure 24.9 shows a case where a sync code is detected before a current one-sector period has elapsed, and Figure 24.10 shows the case where the actual sync code is only detected some time after a full one-sector period has elapsed.

**==> picture [483 x 268] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input data Sector 1 Sector 2 Sector 3 Sector 4 Sector 5 Sector 6<br>Sync code detection<br>Output data Sector 1 Sector 2 Sector 3 Sector 4 Sector 6<br>Figure 24.8 Operation in Automatic Sync Maintenance Mode (Normal Timing)<br>Abnormal sector<br>Input data Sector 1 Sector 3 Sector 4 Sector 5 Sector 6<br>Sync code<br>detection<br>Re-synchronization<br>Ignore Maintain Ignore Maintain<br>Output data Sector 1 Sector 5<br>Abnormal  Abnormal Abnormal<br>sector  sector sector<br>**----- End of picture text -----**<br>

**Figure 24.9 Operation in Automatic Sync Maintenance Mode (When an Abnormally Short Sector is Encountered)**

**==> picture [373 x 128] intentionally omitted <==**

**----- Start of picture text -----**<br>
Abnormal sector<br>Input data Sector 1 Sector 3 Sector 4 Sector 5<br>Sync code<br>detection<br>Maintain Ignore Maintain Re-synchronization<br>Sector 1 Sector 4<br>Output data<br>Abnormal  Abnormal<br>sector sector<br>**----- End of picture text -----**<br>

**Figure 24.10 Operation in Automatic Sync Maintenance Mode (When an Abnormally Long Sector is Encountered)**

## (2) External Sync Mode

In external sync mode, synchronization is always based on the sync codes in the incoming data. Even if the next sync code is not detected at the 2352nd byte, decoding does not proceed until the next sync code is detected. Accordingly, this mode is effective in that it strictly follows the external synchronization timing. Note, however, that decoding will not be performed normally when the sync-code pattern is input with abnormal timing. Figure 24.11 shows the operation in external sync mode.

**==> picture [373 x 113] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input data Abnormal sector<br>Sync code  Sector 1 Sector 3 Sector 4 Sector 5<br>detection<br>Output data Sector 1 Sector 3 Sector 4<br>Abnormal<br>sector<br>**----- End of picture text -----**<br>

**Figure 24.11 Operation in External Sync Mode**

## (3) Interpolated Sync Mode

In interpolated sync mode, synchronization is always driven by the internal counter after a sync code pattern has been detected at the start of decoding. Accordingly, this mode is effective when the sync patterns have been damaged. However, decoding becomes incorrect after a change to the synchronization timing, since the change in timing is not followed.

Figure 24.12 shows the operation in interpolated sync mode.

**==> picture [373 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
Abnormal sector<br>Input data Sector 1 Sector 3 Sector 4 Sector 5<br>Sync code<br>detection<br>Maintain Ignore Maintain Ignore Maintain Ignore Maintain<br>Sector 1<br>Output data<br>Abnormal  Abnormal  Abnormal  Abnormal<br>sector sector sector sector<br>**----- End of picture text -----**<br>

**Figure 24.12 Operation in Interpolated Sync Mode**

## (4) Interpolated Sync Plus External Sync Mode

In interpolated sync plus external sync mode, synchronization is based on the detected sync code patterns as long as they are present, and if a sync pattern is not detected at the 2352nd byte, the sync code maintenance is applied. Synchronization in this mode is more quickly responsive to changes in synchronization timing than synchronization in the automatic sync maintenance mode.

However, decoding still becomes incorrect when a sync pattern is input with abnormal timing.

Figure 24.13 and Figure 24.14 show the operation in interpolated sync plus external sync mode in the cases of abnormally short and long sectors, respectively.

**==> picture [483 x 316] intentionally omitted <==**

**----- Start of picture text -----**<br>
Abnormal sector<br>Input data Sector 1 Sector 3 Sector 4 Sector 5 Sector 6<br>Sync code<br>detection<br>Maintain<br>Output data Sector 1 Sector 3 Sector 4 Sector 5<br>Abnormal<br>sector<br>Figure 24.13 Operation in Interpolated Sync Plus External Sync Mode<br>(When an Abnormally Short Sector is Encountered)<br>Abnormal sector<br>Input data Sector 1 Sector 3 Sector 4 Sector 5<br>Sync code<br>detection<br>Maintain<br>Sector 1 Sector 3 Sector 4<br>Output data<br>Abnormal  Abnormal<br>sector sector<br>**----- End of picture text -----**<br>

**Figure 24.14 Operation in Interpolated Sync Plus External Sync Mode (When an Abnormally Long Sector is Encountered)**

## 24.4.3 Error Correction

The CD-ROM decoder handles data in the formats containing information relevant to error correction, including the EDC, P parity, and Q parity. The CD-ROM decoder includes the following functions for use in error correction.

- Syndrome calculation

- ECC correction

- EDC checking

## (1) Syndrome Calculation

After the data of a sector in Mode 1 or Form 1 of Mode 2 has been input, the ECC is used in correction if any error is detected (the result of syndrome calculation is non-zero). After correction, the results of syndrome operation for the corrected data are output to bits ST_ECCP (P parity) and ST_ECCQ (Q parity) in the CROMST6 register, respectively.

## (2) ECC correction and EDC Checking

For CD-ROM format data that contains EDC, P-parity, and Q-parity fields, the CD-ROM decoder performs EDC checking and ECC correction. Supported correction modes are P correction, Q correction, PQ correction (P correction followed by Q correction), and QP correction (Q correction followed by P correction). In PQ and QP correction modes, up to three iterations of correction are possible (the number of iterations is limited by the playback speed). The EDC check is performed twice, before and after correction.

The mode of ECC correction and EDC checking is specified by bits MD_DEC[2:0] in the CROMCTL1 register. When the PQ or QP correction mode is selected, the number of iterations of correction is specified by bits MD_PQREP[1:0] in the CROMCTL1 register.

When the automatic mode/form detection function is in use, the sector mode determines whether or not ECC correction and EDC checking can be performed. For sectors in Mode 0 and Mode 2 (non-XA), which include neither parity bits nor EDC, ECC correction and EDC checking are not performed. For sectors in Form 2 of Mode 2, ECC correction is not performed.

## (a) ECC Correction

When ECC correction is in use and an error in a sector is identified as non-correctable, the CD-ROM decoder generates an IERR interrupt and sets the ST_ECCNG bit of the CROMST6 register to 1. The CD-ROM detector also sets this bit to 1 on detecting a short sector.

While the NO_ECC bit of the CROMCTL4 register is set to 1, a ‘pass’ result in pre-ECC correction EDC checking makes the CD-ROM decoder skip ECC correction, regardless of the results of the syndrome operation.

## (b) EDC Checking

When EDC checking is in use, checking is in line with the specified or detected sector mode and form, depending on whether or not automatic sector mode and form detection is selected.

The results of EDC checking before and after correction are reflected in the ST_EDC1 and ST_EDC2 bits of the CROMST6 register, respectively. If EDC checking after ECC correction indicates that an error remains, an IERR interrupt is generated.

## 24.4.4 Automatic Decoding Stop Function

Decoding can be stopped automatically in response to an error during the decoding of CD-ROM data.

The possible conditions for automatically stopping the decoding process are listed below. The applicable conditions are specified in the CROMCTL3 register.

- An error is found to be not correctable by ECC correction.

- Post-ECC correction EDC checking indicates that an error remains.

- A change of the sector mode or form

- A non-sequential MSF (minutes, seconds, frames (1/75 second)) value

When automatic stopping is set up and any of the above conditions is encountered in a certain sector, the decoding is stopped after the results of decoding for that sector have been output.

After decoding has been stopped in response to a condition specified in the CROMCTL3 register, the condition can be identified by reading the CBUFST1 register.

The CD-ROM decoder has buffer space for two sectors. If input of the data stream continues and the output stream of data is not read, the CD-ROM decoder stops at the point where the data of a third sector starts to be input. At this time, the BUF_NG bit in the CBUFST2 register is set to 1, but no interrupt is generated. Once the BUF_NG bit in the CBUFST2 register has been set to 1, recovery can only be accomplished by using the LOGICRST bit in the ROMDECRST register to reset the CD-ROM decoder function. When the LOGICRST bit in the ROMDECRST register is set to 1, a reset signal is output and any registers in which settings have been made are cleared to their initial values.

## 24.4.5 Buffering Format

Figure 24.15 shows the format of the output data stream produced by CD-ROM decoding.

A 2-byte-wide window register STRMDOUT0 is provided for the output. When this window register is accessed after decoding of a CD-ROM sector has finished, the bytes of data are output in order from the sync code.

**==> picture [210 x 299] intentionally omitted <==**

**----- Start of picture text -----**<br>
Sync code 12 bytes<br>Header 4 bytes<br>Subheader 8 bytes<br>Data 2048 bytes<br>EDC 4 bytes<br>ECC<br>276 bytes<br>Erasure 294 bytes<br>H'00 Block error 2 bytes<br>Reserved 108 bytes<br>H'0000 2 bytes<br>H'0000 2 bytes<br>Status (See next page) 2 bytes<br>H'0000 2 bytes<br>Reserved 2 bytes<br>Storage flag 2 bytes<br>2768 bytes<br>**----- End of picture text -----**<br>

**Figure 24.15 Output Data Stream Format**

The meanings of bits in the two-byte status field shown in Figure 24.15 are given below. The values of the non-assigned bits are undefined.

||||**Status**|**Status**|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**15**|**14**<br>**13**<br>**12**<br>**11**<br>**10**|**9**|**8**|**7**|**6**|**5**|**4**|**3**|**2**||**1**||**0**||
|PERR|QERR<br>EDCE<br>—<br>—<br>—|—|—|SD||SY|FM[2:0]|||HD||—||—|
|[Legend]|||||||||||||||
|PERR:|Indicates that a P-parity error remains.||||||||||||||
|QERR:|Indicates that a Q-parity error remains.||||||||||||||
|EDCE:|Indicates that a remaining error was detected in||post-ECC correction EDC checking.||||||||||||
|SD:|Indicates that a short sector was encountered.||||||||||||||
|SY:|Indicates that a sync code was interpolated.||||||||||||||
|FM:|Indicates the data format.||||||||||||||
||001: Mode 0||||||||||||||
||010: Mode 1||||||||||||||
||011: Long (format with no EDC and ECC)||||||||||||||
||100: Mode 2 (non-XA)||||||||||||||
||101: Mode 2 Form 1||||||||||||||
||110: Mode 2 Form 2||||||||||||||
|HD:|Header continuity (minutes, seconds, and frames (1|||frame =|1/75|second) are non-sequential)|||||||||

The value of the storage flag field in Figure 24.15 is incremented every time the data for one sector are output. The value starts at H'0000 and wraps back around to H'0000 after it reaches H'FFFF. Note that the upper byte and lower byte in the storage flag are swapped.

## 24.4.6 Target-Sector Buffering Function

In the CD-ROM decoder, the sector for output can be designated in two ways: automatic buffering, where the CD-ROM decoder itself detects the presence of target sector that has been set beforehand, and manual buffering, where the target sector for output is designated by software and the software also recognizes the sectors buffered in the CD-ROM decoder.

The following describes the procedures for setting the registers in the CD-ROM decoder to set up automatic or manual buffering.

## (1) Setting Up Automatic Buffering

Figure 24.16 shows an example of setting up the automatic buffering. Set the relevant CD-ROM decoder registers and start input of the data stream; the CD-ROM decoder then detects the target sector and starts the output of the stream data.

**==> picture [345 x 254] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start of automatic buffering setup<br>Set both the CBUF_AUT and<br>CBUF_EN bits in CBUFCTL0 to 1 [1] [1] Turn on the automatic buffering function and<br>enable buffering in the buffer RAM.<br>[2] Set the minutes value of the target sector.<br>Set CBUFCTL1 [2]<br>[3] Set the seconds value of the target sector.<br>[4] Set the frame value of the target sector.<br>Set CBUFCTL2 [3]<br>[5] Enable subcode processing and CD-ROM decoding.<br>Set CBUFCTL3 [4]<br>Set both the SUBC_EN and<br>CROM_EN bits in CROMEN to 1 [5]<br>End of automatic buffering setup<br>**----- End of picture text -----**<br>

**Figure 24.16 Example of Setting Up Automatic Buffering**

## (2) Setting Up Manual Buffering

Figure 24.17 shows an example of setting up manual buffering. Each time an ISEC interrupt is generated, the software checks whether or not the sector is the target sector and starts buffering when the target sector is found.

**==> picture [307 x 326] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start of automatic buffering setup<br>Clear both the CBUF_AUT and<br>CBUF_EN bits in CBUFCTL0 to 0 [1] [1] Turn off the automatic buffering function<br>and disable buffering in the buffer RAM.<br>Set both the SUBC_EN and<br>CROM_EN bits in CROMEN to 1 [2] [3] Start input of the data stream.<br>Generation of an ISEC interrupt [3]<br>Read HEAD02, etc.<br>No<br>Target sector?<br>Yes<br>Set the CBUF_EN bit<br>in CBUFCTL0 to 1<br>End of manual buffering setup<br>**----- End of picture text -----**<br>

[2] Enable subcode processing and CD-ROM decoding.

**Figure 24.17 Example of Setting Up Manual Buffering**

## 24.5 Interrupt Sources

## 24.5.1 Interrupt and DMA Transfer Request Signals

Table 24.3 lists the interrupt signals and DMA transfer request signal generated by the CD-ROM decoder, along with the meanings and the modules to which the signals are connected.

**Table 24.3 Interrupt and DMA Transfer Request Signals**

|**Name**|**Condition**|**Connected To**|
|---|---|---|
|ISEC|Transition from sector to sector|Interrupt controller|
|ITARG|Access to a CD-ROM sector that is not the expected target sector|Interrupt controller|
|ISY|A sync code from the CD-ROM with abnormal timing|Interrupt controller|
|IERR|An error that was not correctable by ECC correction or an error indicated by EDC|Interrupt controller|
||checking after ECC correction||
|IBUF|State changes in data transfer to the buffer|Interrupt controller|
|IREADY|Request for data transfer to the buffer for CD-ROM|Interrupt controller|
|DMA transfer request|Request for data transfer to the buffer for CD-ROM|Direct memory access|
|||controller|

## (1) ISEC Interrupt

This interrupt is generated when the sync code indicates a transition from sector to sector.

## (2) ITARG Interrupt

This interrupt is generated when the stream data transferred from the CD-DSP is not the data of the target sector. The CD-ROM decoder checks the time data in the subcode. In correct operation, data transfer is expected to start slightly before the target sector. An ITARG interrupt is generated in the following cases.

- When data of a sector preceding the target sector by quite a few sectors have been transferred

- When data of a sector that comes after the target sector have been transferred

For the generation of this interrupt, ITARG is detected from the subcode. However, this interrupt has no meaning in this LSI because CD-ROM data are transferred from the serial sound interface.

## (3) ISY Interrupt

This interrupt can be generated in the following cases.

- When a sync code was detected at a position where the value in the word counter (counter for checking sync code intervals) was not correct and the sync code was ignored

- When a sync code has not been detected although the word counter has reached the final value and a sync code has been interpolated (for sync maintenance)

- When a sync code was detected at a position where the value in the word counter (counter for checking sync code intervals) was not correct and the sync code was used in resynchronization

- When a sync code has not been detected although the word counter has reached the final value, so the period taken up by the sector has been prolonged

- When the sector has been processed as a short sector with the aid of interpolated sync codes

- When the sector has been processed as a long sector with the aid of interpolated sync codes

## (4) IERR Interrupt

This interrupt is generated in the following cases.

- When ECC correction was incapable of correcting an error

- When ECC correction was OK but the subsequent EDC check indicated an error

## (5) IBUF Interrupt

This interrupt is generated when the following transitions occur.

- Data transfer to the buffer  Data transfer complete (searching for data for the next transfer)

- Data for transfer to the buffer are being searched for  Data transfer started

## (6) IREADY Interrupt

This interrupt is generated when decoding of data for one sector is completed. This interrupt should be used to start the CPU buffering stream data for output to SDRAM.

## (7) DMA Transfer Request

The source of direct memory access controller activation is the same as that of IREADY. An interrupt request is generated when output stream data for one sector becomes ready, and after the 2768 bytes of data shown in figure 24.15 have been transferred, the request signal is negated. This is because a certain amount of time is required before the output data for the next sector is ready, so the transfer request from the direct memory access controller should be turned off between transfers.

## 24.5.2 Timing of Status Registers Updates

The status information registers of the CD-ROM decoder are updated on each ISEC interrupt. The sector for which information is reflected in the status registers is selected by the ER0SEL bit of the CROMCTL4 register.

## 24.6 Usage Notes

## 24.6.1 Stopping and Resuming Buffering Alone during Decoding

When the data of the output stream are not being read out but operation of the CD-ROM decoder has continued until the buffers are full, the BUF_NG bit in the CBUFST2 register is set to 1; after that, the CD-ROM decoder becomes incapable of operation.

To stop buffering alone, clear the CBUF_EN bit in the CBUFCTL0 register to 0. If the automatic buffering function is in use, clear the CBUF_AUT bit in the CBUFCTL0 register to 0 at the same time. In this case, the sectors currently in the buffers must be read out.

To resume automatic buffering, set the CBUF_AUT and CBUF_EN bits in the CBUFCTL0 register to 1 at the same time.

## 24.6.2 Setting Sync Code Status Register (CROMST0)

1. When the ST_SECS bit in the CROMST0 register becomes 1, stop decoding immediately and retry from one sector before the sector that was being decoded.

2. When the ST_SECL bit in the CROMST0 register becomes 1, stop decoding immediately and retry from two sectors before the sector that was being decoded.

## 24.6.3 Link Blocks

The CD-ROM decoder uses the header information before ECC correction to detect link blocks. Accordingly, an input data stream that contains an error may be erroneously detected as a link block. To prevent this, the following measures should be implemented in software.

- During buffering (BUF_ACT = 1 in the CBUFST0 register), check the LINK_OUT1 bit in the CROMST5 register on each ISEC interrupt. If it is set to 1, check to see if an IERR interrupt has also occurred; if an IERR interrupt has not occurred, save the MFS values from the HEAD20 to HEAD23 registers. If an IERR interrupt has occurred, do not save the MSF values.

- Perform the following processing for seven sectors (indicated by ISEC being generated seven times) after finding that the LINK_OUT1 bit has been set to 1.

- In either of cases 1 and 2 below,

   1. LINK_ON = 1 (in the CROMST5 register) is confirmed at each ISEC interrupt, and LINK_ON = 1 is detected again within the subsequent two-sector period

   2. LINK_ON = 1 was not detected at any ISEC interrupt

forcibly stop decoding, set the CROMSY0 register to place the decoder in external sync mode, and retry decoding by specifying the MSF value stored as described above + 7 (immediately after a link block) as the MSF value for the target sector.

The start sector address will be the address where RUN_OUT is stored + 7.

## 24.6.4 Stopping and Resuming CD-DSP Operation

When stopping and then resuming the stream data input to the CD-ROM decoder, if the input data stream does not stop immediately before a sync code and is then resumed, the CD-ROM decoder may recognize the data as incorrect. This happens because the system holds the data up to the point where input was stopped and the data that is input from the point of resumption at the same time. Take care on this point when stopping and then resuming input.

## 24.6.5 Note on Clearing the IREADY Flag

To clear the IREADY flag to 0 in interrupt processing etc., be sure to read one sector of data (2768 bytes) beforehand. If the IREADY flag is cleared to 0 before reading of one sector of data is complete, decoding of the subsequent sectors will not be possible. For recovery from this situation, write 1 to the LOGICRST bit in the CD-ROM decoder reset control register (ROMDECRST), and then clear the bit to 0.

## 24.6.6 Note on Stream Data Transfer (1)

If reading of the output data stream is slower than writing of the input data stream, the buffer of the CD-ROM decoder will overflow. This causes the CD-ROM decoder to abnormally stop.

When DMA transfer is in use, ensure that reading of the output data stream is faster than writing of the input data stream by making settings as listed below.

- Set a larger transfer size for reading of the output data stream than for writing of the input data stream.

- Give reading of the output data stream higher priority than writing of the input data stream.

- Set a smaller interval count for reading of the output data stream than for writing of the input data stream.

When the CPU handles transfer, ensure that reading of the output data stream is faster than writing of the input data stream by taking similar measures to those in the case of DMA transfer.

## 24.6.7 Note on Stream Data Transfer (2)

When reading the stream data, be sure to use either the direct memory access controller or the CPU. If both the direct memory access controller and the CPU are used for reading, the stream data may not be recognized as being in the CDROM format.

## 24.6.8 Note on Software Reset

For transitions to the software reset state by the LOGICRST bit in the ROMDECRST register, see section 42.3.6, Software Reset . However, where the procedure refers to the SRST bit, read this as the LOGICRST bit.
