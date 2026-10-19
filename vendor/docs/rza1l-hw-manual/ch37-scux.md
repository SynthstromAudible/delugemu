# 37. SCUX

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 1977–2090. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

The SCUX consists of sampling converters, digital volume units, and a mixer. It is connected to the SSIF module to have an interface with external modules.

## 37.1 Features

## (1) [SRC]  Sampling Rate Conversion

- [1]

- Asynchronous or synchronous sampling rate conversion is possible

- [2]

- Sampling rate (synchronous mode) Input [KHz]: 8, 11.025, 12, 16, 22.05, 24, 32, 44.1, 48, 64, 88.2, or 96 is selectable Output [KHz]: 8, 16, 24, 32, 44.1, 48, or 96 is selectable

- [2]

- Sampling rate (asynchronous mode) Input/output [KHz]: 1 to 96

- Supported bit sizes are 16 bits and 24 bits

- Sound quality:  132 dB or less *[3]

- [4]

- 1, 2, 4, 6, or 8 channels are supported

- DMA transfer with on-chip memory or external memory and direct transfer with the SSIF module are possible

- Note 1. The synchronous mode can be selected only when the SCUX is connected to the FFD and FFU modules. For details, refer to section 37.4.5.

- Note 2. The selectable sampling rates depend on the number of used channels and rate ratio. For details, refer to section 37.3.22 and section 37.4.7.

- Note 3. The data format is a 24-bit value.

- Note 4. The number of selectable channels depends on the sampling rate and route. For details, refer to section 37.4.7.

## (2) [DVU]  Digital Volume and Mute Functions

- Digital volume, volume ramp, and zero cross mute are provided as functions to adjust the volume

- The digital volume is set as a 24-bit fixed-point value within the range from a multiple of 0 to 8 (mute,  120 to 18 dB)

- Volume ramp can be used to perform soft mute, fade in, fade out, and volume change as desired

- The ramp time of volume ramp can be changed and set within the sampling range of 2[0] to 2[23]

- Zero cross mute turns the sound mute at the zero cross point of audio data

- Direct transfer with the SSIF module and transfer with the mixer are possible

## (3) [MIX]  Mixer

- Data of two to four source systems can be mixed (added together) into one system

- The ratio to add the sources can be set

- The ratio can be changed dynamically

- Volume ramp enables mixing to be performed (ramp time is variable)

- Only direct transfer with the SSIF module is possible

Figure 37.1 shows a block diagram of the SCUX.

**==> picture [455 x 546] intentionally omitted <==**

**----- Start of picture text -----**<br>
Peripheral bus<br>SCUX Interrupt/<br>CIM RCIM DMA transfer request<br>AUDIO_CLK<br>MLB_CLK<br>RFFD RIPC  R2SRC ROPC RFFU  RDVU  RMIX AUDIO_X1,X2<br>AUDIO_XOUT2<br>AUDIO_XOUT3<br>FFD0_0* FFU0_0* USB<br>IPC0_0 OPC0_0<br>(8ch) (8ch)<br>2SRC0_0 SSIF0<br>SRC0 DVU0_0<br>SSIF3<br>FFD0_1* FFU0_1*<br>IPC0_1 SRC1 OPC0_1<br>(8ch) (8ch)<br>DVU0_1<br>SSIF1<br>MIX<br>SSIF2<br>FFD0_2* FFU0_2*<br>(2ch) IPC0_2 OPC0_2 (2ch)<br>2SRC0_1<br>SRC2 DVU0_2<br>FFD0_3* FFU0_3*<br>(2ch) SRC3 OPC0_3 (2ch)<br>IPC0_3<br>DVU0_3 MTU2<br>[Legend]<br>CIM  : CPU Interface Module  MIX  : Mixer  RMIX : Register for MIX<br>FFD0_n  : FIFO DOWN  RCIM : Register for CIM  (n=0,1,2,3 m=0,1)<br>IPC0_n  : Input Pass Control  RFFD : Register for FFD Note: *  FFD0_0, FFD0_1, FFU0_0, or FFU0_1 is a<br>SRCn  : Sampling Rate Converter  RIPC : Register for IPC 256-stage FIFO (supports up to 8 channels).<br>2SRC0_m : 2 × SRC  R2SRC : Register for 2SRC FFD0_2, FFD0_3, FFU0_2, or FFU0_3 is a<br>OPC0_n  : Output Pass Control  ROPC : Register for OPC 64-stage FIFO (supports up to 2 channels).<br>FFU0_n  : FIFO UP  RFFU : Register for FFU When the route of FFD0_2, FFD0_3, FFU0_2, or<br>DVU0_n  : Digital Volume Unit  RDVU : Register for DVU FFU0_3 is used, SRC2 and SRC3 support up to<br>two channels.<br>**----- End of picture text -----**<br>

**Figure 37.1 Block Diagram of SCUX**

## 37.2 Input/Output Pins

## **Table 37.1 Pin Configuration**

|**Name**|**I/O**|**Function**|
|---|---|---|
|AUDIO_CLK|Input|External clock for audio|
|||Can be used in generating the sampling timing.|
|MLB_CLK*1|Input|External clock for MLB|
|||Can be used in generating the sampling timing.|
|AUDIO_X1|Input|Crystal resonator/external clock for audio|
|AUDIO_X2|Output|Can be used in generating the sampling timing.|
|AUDIO_XOUT2|Output|Output clock of AUDIO_X1 divided into two|
|||(Output is toggled once per cycle of the AUDIO_X1 clock.)|
|AUDIO_XOUT3|Output|Output clock of AUDIO_X1 divided into three|
|||(Output is toggled once every 1.5 cycles of the AUDIO_X1 clock.)|

Note 1. Since the RZ/A1LU and RZ/A1LC do not have a MLB_CLK external pin, a fixed value (0) is input as the signal in this module.

## 37.3 Register Descriptions

Table 37.2 shows the register configuration.

**Table 37.2 Register Configuration**

|**Table 37.2**|**Register Configuration**|
|---|---|
|**Block**<br>**Name**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|IPC0_0|IPC0_0 initialization register<br>IPCIR_IPC0_0<br>R/W<br>H'00000001<br>H'E8208000<br>32|
||IPC0_0 pass select register<br>IPSLR_IPC0_0<br>R/W<br>H'00000000<br>H'E8208004<br>32|
|IPC0_1|IPC0_1 initialization register<br>IPCIR_IPC0_1<br>R/W<br>H'00000001<br>H'E8208100<br>32|
||IPC0_1 pass select register<br>IPSLR_IPC0_1<br>R/W<br>H'00000000<br>H'E8208104<br>32|
|IPC0_2|IPC0_2 initialization register<br>IPCIR_IPC0_2<br>R/W<br>H'00000001<br>H'E8208200<br>32|
||IPC0_2 pass select register<br>IPSLR_IPC0_2<br>R/W<br>H'00000000<br>H'E8208204<br>32|
|IPC0_3|IPC0_3 initialization register<br>IPCIR_IPC0_3<br>R/W<br>H'00000001<br>H'E8208300<br>32|
||IPC0_3 pass select register<br>IPSLR_IPC0_3<br>R/W<br>H'00000000<br>H'E8208304<br>32|
|OPC0_0|OPC0_0 initialization register<br>OPCIR_OPC0_0<br>R/W<br>H'00000001<br>H'E8208400<br>32|
||OPC0_0 pass select register<br>OPSLR_OPC0_0<br>R/W<br>H'00000000<br>H'E8208404<br>32|
|OPC0_1|OPC0_1 initialization register<br>OPCIR_OPC0_1<br>R/W<br>H'00000001<br>H'E8208500<br>32|
||OPC0_1 pass select register<br>OPSLR_OPC0_1<br>R/W<br>H'00000000<br>H'E8208504<br>32|
|OPC0_2|OPC0_2 initialization register<br>OPCIR_OPC0_2<br>R/W<br>H'00000001<br>H'E8208600<br>32|
||OPC0_2 pass select register<br>OPSLR_OPC0_2<br>R/W<br>H'00000000<br>H'E8208604<br>32|
|OPC0_3|OPC0_3 initialization register<br>OPCIR_OPC0_3<br>R/W<br>H'00000001<br>H'E8208700<br>32|
||OPC0_3 pass select register<br>OPSLR_OPC0_3<br>R/W<br>H'00000000<br>H'E8208704<br>32|
|FFD0_0|FFD0_0 FIFO download initialization register<br>FFDIR_FFD0_0<br>R/W<br>H'00000001<br>H'E8208800<br>32|
||FFD0_0 FIFO download audio information<br>register<br>FDAIR_FFD0_0<br>R/W<br>H'00000000<br>H'E8208804<br>32|
||FFD0_0 FIFO download request size register<br>DRQSR_FFD0_0<br>R/W<br>H'00000000<br>H'E8208808<br>32|
||FFD0_0 FIFO download pass register<br>FFDPR_FFD0_0<br>R/W<br>H'00000000<br>H'E820880C<br>32|
||FFD0_0 FIFO download boot register<br>FFDBR_FFD0_0<br>R/W<br>H'00000000<br>H'E8208810<br>32|
||FFD0_0 FIFO download event mask register<br>DEVMR_FFD0_0<br>R/W<br>H'00000000<br>H'E8208814<br>32|
||FFD0_0 FIFO download event clear register<br>DEVCR_FFD0_0<br>R/W*1<br>H'00000000<br>H'E820881C<br>32|
|FFD0_1|FFD0_1 FIFO download initialization register<br>FFDIR_FFD0_1<br>R/W<br>H'00000001<br>H'E8208900<br>32|
||FFD0_1 FIFO download audio information<br>register<br>FDAIR_FFD0_1<br>R/W<br>H'00000000<br>H'E8208904<br>32|
||FFD0_1 FIFO download request size register<br>DRQSR_FFD0_1<br>R/W<br>H'00000000<br>H'E8208908<br>32|
||FFD0_1 FIFO download pass register<br>FFDPR_FFD0_1<br>R/W<br>H'00000000<br>H'E820890C<br>32|
||FFD0_1 FIFO download boot register<br>FFDBR_FFD0_1<br>R/W<br>H'00000000<br>H'E8208910<br>32|
||FFD0_1 FIFO download event mask register<br>DEVMR_FFD0_1<br>R/W<br>H'00000000<br>H'E8208914<br>32|
||FFD0_1 FIFO download event clear register<br>DEVCR_FFD0_1<br>R/W*1<br>H'00000000<br>H'E820891C<br>32|
|FFD0_2|FFD0_2 FIFO download initialization register<br>FFDIR_FFD0_2<br>R/W<br>H'00000001<br>H'E8208A00<br>32|
||FFD0_2 FIFO download audio information<br>register<br>FDAIR_FFD0_2<br>R/W<br>H'00000000<br>H'E8208A04<br>32|
||FFD0_2 FIFO download request size register<br>DRQSR_FFD0_2<br>R/W<br>H'00000000<br>H'E8208A08<br>32|
||FFD0_2 FIFO download pass register<br>FFDPR_FFD0_2<br>R/W<br>H'00000000<br>H'E8208A0C<br>32|
||FFD0_2 FIFO download boot register<br>FFDBR_FFD0_2<br>R/W<br>H'00000000<br>H'E8208A10<br>32|
||FFD0_2 FIFO download event mask register<br>DEVMR_FFD0_2<br>R/W<br>H'00000000<br>H'E8208A14<br>32|
||FFD0_2 FIFO download event clear register<br>DEVCR_FFD0_2<br>R/W*1<br>H'00000000<br>H'E8208A1C<br>32|

**Table 37.2 Register Configuration**

|**Table 37.2**|**Register Configuration**|
|---|---|
|**Block**<br>**Name**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|FFD0_3|FFD0_3 FIFO download initialization register<br>FFDIR_FFD0_3<br>R/W<br>H'00000001<br>H'E8208B00<br>32|
||FFD0_3 FIFO download audio information<br>register<br>FDAIR_FFD0_3<br>R/W<br>H'00000000<br>H'E8208B04<br>32|
||FFD0_3 FIFO download request size register<br>DRQSR_FFD0_3<br>R/W<br>H'00000000<br>H'E8208B08<br>32|
||FFD0_3 FIFO download pass register<br>FFDPR_FFD0_3<br>R/W<br>H'00000000<br>H'E8208B0C<br>32|
||FFD0_3 FIFO download boot register<br>FFDBR_FFD0_3<br>R/W<br>H'00000000<br>H'E8208B10<br>32|
||FFD0_3 FIFO download event mask register<br>DEVMR_FFD0_3<br>R/W<br>H'00000000<br>H'E8208B14<br>32|
||FFD0_3 FIFO download event clear register<br>DEVCR_FFD0_3<br>R/W*1<br>H'00000000<br>H'E8208B1C<br>32|
|FFU0_0|FFU0_0 FIFO upload initialization register<br>FFUIR_FFU0_0<br>R/W<br>H'00000001<br>H'E8208C00<br>32|
||FFU0_0 FIFO upload audio information<br>register<br>FUAIR_FFU0_0<br>R/W<br>H'00000000<br>H'E8208C04<br>32|
||FFU0_0 FIFO upload request size register<br>URQSR_FFU0_0<br>R/W<br>H'00000000<br>H'E8208C08<br>32|
||FFU0_0 FIFO upload pass register<br>FFUPR_FFU0_0<br>R/W<br>H'00000000<br>H'E8208C0C<br>32|
||FFU0_0 FIFO upload event mask register<br>UEVMR_FFU0_0<br>R/W<br>H'00000000<br>H'E8208C10<br>32|
||FFU0_0 FIFO upload event clear register<br>UEVCR_FFU0_0<br>R/W*1<br>H'00000000<br>H'E8208C18<br>32|
|FFU0_1|FFU0_1 FIFO upload initialization register<br>FFUIR_FFU0_1<br>R/W<br>H'00000001<br>H'E8208D00<br>32|
||FFU0_1 FIFO upload audio information<br>register<br>FUAIR_FFU0_1<br>R/W<br>H'00000000<br>H'E8208D04<br>32|
||FFU0_1 FIFO upload request size register<br>URQSR_FFU0_1<br>R/W<br>H'00000000<br>H'E8208D08<br>32|
||FFU0_1 FIFO upload pass register<br>FFUPR_FFU0_1<br>R/W<br>H'00000000<br>H'E8208D0C<br>32|
||FFU0_1 FIFO upload event mask register<br>UEVMR_FFU0_1<br>R/W<br>H'00000000<br>H'E8208D10<br>32|
||FFU0_1 FIFO upload event clear register<br>UEVCR_FFU0_1<br>R/W*1<br>H'00000000<br>H'E8208D18<br>32|
|FFU0_2|FFU0_2 FIFO upload initialization register<br>FFUIR_FFU0_2<br>R/W<br>H'00000001<br>H'E8208E00<br>32|
||FFU0_2 FIFO upload audio information<br>register<br>FUAIR_FFU0_2<br>R/W<br>H'00000000<br>H'E8208E04<br>32|
||FFU0_2 FIFO upload request size register<br>URQSR_FFU0_2<br>R/W<br>H'00000000<br>H'E8208E08<br>32|
||FFU0_2 FIFO upload pass register<br>FFUPR_FFU0_2<br>R/W<br>H'00000000<br>H'E8208E0C<br>32|
||FFU0_2 FIFO upload event mask register<br>UEVMR_FFU0_2<br>R/W<br>H'00000000<br>H'E8208E10<br>32|
||FFU0_2 FIFO upload event clear register<br>UEVCR_FFU0_2<br>R/W*1<br>H'00000000<br>H'E8208E18<br>32|
|FFU0_3|FFU0_3 FIFO upload initialization register<br>FFUIR_FFU0_3<br>R/W<br>H'00000001<br>H'E8208F00<br>32|
||FFU0_3 FIFO upload audio information<br>register<br>FUAIR_FFU0_3<br>R/W<br>H'00000000<br>H'E8208F04<br>32|
||FFU0_3 FIFO upload request size register<br>URQSR_FFU0_3<br>R/W<br>H'00000000<br>H'E8208F08<br>32|
||FFU0_3 FIFO upload pass register<br>FFUPR_FFU0_3<br>R/W<br>H'00000000<br>H'E8208F0C<br>32|
||FFU0_3 FIFO upload event mask register<br>UEVMR_FFU0_3<br>R/W<br>H'00000000<br>H'E8208F10<br>32|
||FFU0_3 FIFO upload event clear register<br>UEVCR_FFU0_3<br>R/W*1<br>H'00000000<br>H'E8208F18<br>32|

**Table 37.2 Register Configuration**

|**Table 37.2**|**Register Configuration**|
|---|---|
|**Block**<br>**Name**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|2SRC0_0<br>(SRC0)|2SRC0_0 initialization register 0<br>SRCIR0_2SRC0_0<br>R/W<br>H'00000001<br>H'E8209000<br>32|
||2SRC0_0 audio information register 0<br>SADIR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209004<br>32|
||2SRC0_0 bypass register 0<br>SRCBR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209008<br>32|
||2SRC0_0 IFS control register 0<br>IFSCR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E820900C<br>32|
||2SRC0_0 IFS value setting register 0<br>IFSVR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209010<br>32|
||2SRC0_0 control register 0<br>SRCCR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209014<br>32|
||2SRC0_0 minimum FS setting register 0<br>MNFSR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209018<br>32|
||2SRC0_0 buffer size setting register 0<br>BFSSR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E820901C<br>32|
||2SRC0_0 SCU2 status register 0<br>SC2SR0_2SRC0_0<br>R<br>H'00000000<br>H'E8209020<br>32|
||2SRC0_0 wait time setting register 0<br>WATSR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209024<br>32|
||2SRC0_0 event mask register 0<br>SEVMR0_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209028<br>32|
||2SRC0_0 event clear register 0<br>SEVCR0_2SRC0_0<br>R/W*1<br>H'00000000<br>H'E8209030<br>32|
|2SRC0_0<br>(SRC1)|2SRC0_0 initialization register 1<br>SRCIR1_2SRC0_0<br>R/W<br>H'00000001<br>H'E8209034<br>32|
||2SRC0_0 audio information register 1<br>SADIR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209038<br>32|
||2SRC0_0 bypass register 1<br>SRCBR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E820903C<br>32|
||2SRC0_0 IFS control register 1<br>IFSCR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209040<br>32|
||2SRC0_0 IFS value setting register 1<br>IFSVR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209044<br>32|
||2SRC0_0 control register 1<br>SRCCR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209048<br>32|
||2SRC0_0 minimum FS setting register 1<br>MNFSR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E820904C<br>32|
||2SRC0_0 buffer size setting register 1<br>BFSSR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209050<br>32|
||2SRC0_0 SCU2 status register 1<br>SC2SR1_2SRC0_0<br>R<br>H'00000000<br>H'E8209054<br>32|
||2SRC0_0 wait time setting register 1<br>WATSR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E8209058<br>32|
||2SRC0_0 event mask register 1<br>SEVMR1_2SRC0_0<br>R/W<br>H'00000000<br>H'E820905C<br>32|
||2SRC0_0 event clear register 1<br>SEVCR1_2SRC0_0<br>R/W*1<br>H'00000000<br>H'E8209064<br>32|
||2SRC0_0 initialization register RIF<br>SRCIRR_2SRC0_0<br>R/W<br>H'00000001<br>H'E8209068<br>32|
|2SRC0_1<br>(SRC2)|2SRC0_1 initialization register 0<br>SRCIR0_2SRC0_1<br>R/W<br>H'00000001<br>H'E8209100<br>32|
||2SRC0_1 audio information register 0<br>SADIR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209104<br>32|
||2SRC0_1 bypass register 0<br>SRCBR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209108<br>32|
||2SRC0_1 IFS control register 0<br>IFSCR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E820910C<br>32|
||2SRC0_1 IFS value setting register 0<br>IFSVR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209110<br>32|
||2SRC0_1 control register 0<br>SRCCR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209114<br>32|
||2SRC0_1 minimum FS setting register 0<br>MNFSR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209118<br>32|
||2SRC0_1 buffer size setting register 0<br>BFSSR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E820911C<br>32|
||2SRC0_1 SCU2 status register 0<br>SC2SR0_2SRC0_1<br>R<br>H'00000000<br>H'E8209120<br>32|
||2SRC0_1 wait time setting register 0<br>WATSR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209124<br>32|
||2SRC0_1 event mask register 0<br>SEVMR0_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209128<br>32|
||2SRC0_1 event clear register 0<br>SEVCR0_2SRC0_1<br>R/W*1<br>H'00000000<br>H'E8209130<br>32|

**Table 37.2 Register Configuration**

|**Table 37.2**|**Register Configuration**|
|---|---|
|**Block**<br>**Name**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|2SRC0_1<br>(SRC3)|2SRC0_1 initialization register 1<br>SRCIR1_2SRC0_1<br>R/W<br>H'00000001<br>H'E8209134<br>32|
||2SRC0_1 audio information register 1<br>SADIR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209138<br>32|
||2SRC0_1 bypass register 1<br>SRCBR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E820913C<br>32|
||2SRC0_1 IFS control register 1<br>IFSCR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209140<br>32|
||2SRC0_1 IFS value setting register 1<br>IFSVR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209144<br>32|
||2SRC0_1 control register 1<br>SRCCR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209148<br>32|
||2SRC0_1 minimum FS setting register 1<br>MNFSR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E820914C<br>32|
||2SRC0_1 buffer size setting register 1<br>BFSSR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209150<br>32|
||2SRC0_1 SCU2 status register 1<br>SC2SR1_2SRC0_1<br>R<br>H'00000000<br>H'E8209154<br>32|
||2SRC0_1 wait time setting register 1<br>WATSR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E8209158<br>32|
||2SRC0_1 event mask register 1<br>SEVMR1_2SRC0_1<br>R/W<br>H'00000000<br>H'E820915C<br>32|
||2SRC0_1 event clear register 1<br>SEVCR1_2SRC0_1<br>R/W*1<br>H'00000000<br>H'E8209164<br>32|
||2SRC0_1 initialization register RIF<br>SRCIRR_2SRC0_1<br>R/W<br>H'00000001<br>H'E8209168<br>32|
|DVU0_0|DVU0_0 initialization register<br>DVUIR_DVU0_0<br>R/W<br>H'00000001<br>H'E8209200<br>32|
||DVU0_0 audio information register<br>VADIR_DVU0_0<br>R/W<br>H'00000000<br>H'E8209204<br>32|
||DVU0_0 bypass register<br>DVUBR_DVU0_0<br>R/W<br>H'00000000<br>H'E8209208<br>32|
||DVU0_0 control register<br>DVUCR_DVU0_0<br>R/W<br>H'00000000<br>H'E820920C<br>32|
||DVU0_0 zero cross mute control register<br>ZCMCR_DVU0_0<br>R/W<br>H'00000000<br>H'E8209210<br>32|
||DVU0_0 volume ramp control register<br>VRCTR_DVU0_0<br>R/W<br>H'00000000<br>H'E8209214<br>32|
||DVU0_0 volume ramp period register<br>VRPDR_DVU0_0<br>R/W<br>H'00000000<br>H'E8209218<br>32|
||DVU0_0 volume ramp decibel register<br>VRDBR_DVU0_0<br>R/W<br>H'00000000<br>H'E820921C<br>32|
||DVU0_0 volume ramp wait time register<br>VRWTR_DVU0_0<br>R/W<br>H'00000000<br>H'E8209220<br>32|
||DVU0_0 volume value setting 0 register<br>VOL0R_DVU0_0<br>R/W<br>H'00000000<br>H'E8209224<br>32|
||DVU0_0 volume value setting 1 register<br>VOL1R_DVU0_0<br>R/W<br>H'00000000<br>H'E8209228<br>32|
||DVU0_0 volume value setting 2 register<br>VOL2R_DVU0_0<br>R/W<br>H'00000000<br>H'E820922C<br>32|
||DVU0_0 volume value setting 3 register<br>VOL3R_DVU0_0<br>R/W<br>H'00000000<br>H'E8209230<br>32|
||DVU0_0 volume value setting 4 register<br>VOL4R_DVU0_0<br>R/W<br>H'00000000<br>H'E8209234<br>32|
||DVU0_0 volume value setting 5 register<br>VOL5R_DVU0_0<br>R/W<br>H'00000000<br>H'E8209238<br>32|
||DVU0_0 volume value setting 6 register<br>VOL6R_DVU0_0<br>R/W<br>H'00000000<br>H'E820923C<br>32|
||DVU0_0 volume value setting 7 register<br>VOL7R_DVU0_0<br>R/W<br>H'00000000<br>H'E8209240<br>32|
||DVU0_0 enable register<br>DVUER_DVU0_0<br>R/W<br>H'00000000<br>H'E8209244<br>32|
||DVU0_0 status register<br>DVUSR_DVU0_0<br>R<br>H'00000000<br>H'E8209248<br>32|
||DVU0_0 event mask register<br>VEVMR_DVU0_0<br>R/W<br>H'00000000<br>H'E820924C<br>32|
||DVU0_0 event clear register<br>VEVCR_DVU0_0<br>R/W*1<br>H'00000000<br>H'E8209254<br>32|

**Table 37.2 Register Configuration**

|**Table 37.2**|**Register Configuration**|
|---|---|
|**Block**<br>**Name**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|DVU0_1|DVU0_1 initialization register<br>DVUIR_DVU0_1<br>R/W<br>H'00000001<br>H'E8209300<br>32|
||DVU0_1 audio information register<br>VADIR_DVU0_1<br>R/W<br>H'00000000<br>H'E8209304<br>32|
||DVU0_1 bypass register<br>DVUBR_DVU0_1<br>R/W<br>H'00000000<br>H'E8209308<br>32|
||DVU0_1 control register<br>DVUCR_DVU0_1<br>R/W<br>H'00000000<br>H'E820930C<br>32|
||DVU0_1 zero cross mute control register<br>ZCMCR_DVU0_1<br>R/W<br>H'00000000<br>H'E8209310<br>32|
||DVU0_1 volume ramp control register<br>VRCTR_DVU0_1<br>R/W<br>H'00000000<br>H'E8209314<br>32|
||DVU0_1 volume ramp period register<br>VRPDR_DVU0_1<br>R/W<br>H'00000000<br>H'E8209318<br>32|
||DVU0_1 volume ramp decibel register<br>VRDBR_DVU0_1<br>R/W<br>H'00000000<br>H'E820931C<br>32|
||DVU0_1 volume ramp wait time register<br>VRWTR_DVU0_1<br>R/W<br>H'00000000<br>H'E8209320<br>32|
||DVU0_1 volume value setting 0 register<br>VOL0R_DVU0_1<br>R/W<br>H'00000000<br>H'E8209324<br>32|
||DVU0_1 volume value setting 1 register<br>VOL1R_DVU0_1<br>R/W<br>H'00000000<br>H'E8209328<br>32|
||DVU0_1 volume value setting 2 register<br>VOL2R_DVU0_1<br>R/W<br>H'00000000<br>H'E820932C<br>32|
||DVU0_1 volume value setting 3 register<br>VOL3R_DVU0_1<br>R/W<br>H'00000000<br>H'E8209330<br>32|
||DVU0_1 volume value setting 4 register<br>VOL4R_DVU0_1<br>R/W<br>H'00000000<br>H'E8209334<br>32|
||DVU0_1 volume value setting 5 register<br>VOL5R_DVU0_1<br>R/W<br>H'00000000<br>H'E8209338<br>32|
||DVU0_1 volume value setting 6 register<br>VOL6R_DVU0_1<br>R/W<br>H'00000000<br>H'E820933C<br>32|
||DVU0_1 volume value setting 7 register<br>VOL7R_DVU0_1<br>R/W<br>H'00000000<br>H'E8209340<br>32|
||DVU0_1 enable register<br>DVUER_DVU0_1<br>R/W<br>H'00000000<br>H'E8209344<br>32|
||DVU0_1 status register<br>DVUSR_DVU0_1<br>R<br>H'00000000<br>H'E8209348<br>32|
||DVU0_1 event mask register<br>VEVMR_DVU0_1<br>R/W<br>H'00000000<br>H'E820934C<br>32|
||DVU0_1 event clear register<br>VEVCR_DVU0_1<br>R/W*1<br>H'00000000<br>H'E8209354<br>32|
|DVU0_2|DVU0_2 initialization register<br>DVUIR_DVU0_2<br>R/W<br>H'00000001<br>H'E8209400<br>32|
||DVU0_2 audio information register<br>VADIR_DVU0_2<br>R/W<br>H'00000000<br>H'E8209404<br>32|
||DVU0_2 bypass register<br>DVUBR_DVU0_2<br>R/W<br>H'00000000<br>H'E8209408<br>32|
||DVU0_2 control register<br>DVUCR_DVU0_2<br>R/W<br>H'00000000<br>H'E820940C<br>32|
||DVU0_2 zero cross mute control register<br>ZCMCR_DVU0_2<br>R/W<br>H'00000000<br>H'E8209410<br>32|
||DVU0_2 volume ramp control register<br>VRCTR_DVU0_2<br>R/W<br>H'00000000<br>H'E8209414<br>32|
||DVU0_2 volume ramp period register<br>VRPDR_DVU0_2<br>R/W<br>H'00000000<br>H'E8209418<br>32|
||DVU0_2 volume ramp decibel register<br>VRDBR_DVU0_2<br>R/W<br>H'00000000<br>H'E820941C<br>32|
||DVU0_2 volume ramp wait time register<br>VRWTR_DVU0_2<br>R/W<br>H'00000000<br>H'E8209420<br>32|
||DVU0_2 volume value setting 0 register<br>VOL0R_DVU0_2<br>R/W<br>H'00000000<br>H'E8209424<br>32|
||DVU0_2 volume value setting 1 register<br>VOL1R_DVU0_2<br>R/W<br>H'00000000<br>H'E8209428<br>32|
||DVU0_2 volume value setting 2 register<br>VOL2R_DVU0_2<br>R/W<br>H'00000000<br>H'E820942C<br>32|
||DVU0_2 volume value setting 3 register<br>VOL3R_DVU0_2<br>R/W<br>H'00000000<br>H'E8209430<br>32|
||DVU0_2 volume value setting 4 register<br>VOL4R_DVU0_2<br>R/W<br>H'00000000<br>H'E8209434<br>32|
||DVU0_2 volume value setting 5 register<br>VOL5R_DVU0_2<br>R/W<br>H'00000000<br>H'E8209438<br>32|
||DVU0_2 volume value setting 6 register<br>VOL6R_DVU0_2<br>R/W<br>H'00000000<br>H'E820943C<br>32|
||DVU0_2 volume value setting 7 register<br>VOL7R_DVU0_2<br>R/W<br>H'00000000<br>H'E8209440<br>32|
||DVU0_2 enable register<br>DVUER_DVU0_2<br>R/W<br>H'00000000<br>H'E8209444<br>32|
||DVU0_2 status register<br>DVUSR_DVU0_2<br>R<br>H'00000000<br>H'E8209448<br>32|
||DVU0_2 event mask register<br>VEVMR_DVU0_2<br>R/W<br>H'00000000<br>H'E820944C<br>32|
||DVU0_2 event clear register<br>VEVCR_DVU0_2<br>R/W*1<br>H'00000000<br>H'E8209454<br>32|

**Table 37.2 Register Configuration**

|**Table 37.2**|**Register Configuration**|
|---|---|
|**Block**<br>**Name**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|DVU0_3|DVU0_3 initialization register<br>DVUIR_DVU0_3<br>R/W<br>H'00000001<br>H'E8209500<br>32|
||DVU0_3 audio information register<br>VADIR_DVU0_3<br>R/W<br>H'00000000<br>H'E8209504<br>32|
||DVU0_3 bypass register<br>DVUBR_DVU0_3<br>R/W<br>H'00000000<br>H'E8209508<br>32|
||DVU0_3 control register<br>DVUCR_DVU0_3<br>R/W<br>H'00000000<br>H'E820950C<br>32|
||DVU0_3 zero cross mute control register<br>ZCMCR_DVU0_3<br>R/W<br>H'00000000<br>H'E8209510<br>32|
||DVU0_3 volume ramp control register<br>VRCTR_DVU0_3<br>R/W<br>H'00000000<br>H'E8209514<br>32|
||DVU0_3 volume ramp period register<br>VRPDR_DVU0_3<br>R/W<br>H'00000000<br>H'E8209518<br>32|
||DVU0_3 volume ramp decibel register<br>VRDBR_DVU0_3<br>R/W<br>H'00000000<br>H'E820951C<br>32|
||DVU0_3 volume ramp wait time register<br>VRWTR_DVU0_3<br>R/W<br>H'00000000<br>H'E8209520<br>32|
||DVU0_3 volume value setting 0 register<br>VOL0R_DVU0_3<br>R/W<br>H'00000000<br>H'E8209524<br>32|
||DVU0_3 volume value setting 1 register<br>VOL1R_DVU0_3<br>R/W<br>H'00000000<br>H'E8209528<br>32|
||DVU0_3 volume value setting 2 register<br>VOL2R_DVU0_3<br>R/W<br>H'00000000<br>H'E820952C<br>32|
||DVU0_3 volume value setting 3 register<br>VOL3R_DVU0_3<br>R/W<br>H'00000000<br>H'E8209530<br>32|
||DVU0_3 volume value setting 4 register<br>VOL4R_DVU0_3<br>R/W<br>H'00000000<br>H'E8209534<br>32|
||DVU0_3 volume value setting 5 register<br>VOL5R_DVU0_3<br>R/W<br>H'00000000<br>H'E8209538<br>32|
||DVU0_3 volume value setting 6 register<br>VOL6R_DVU0_3<br>R/W<br>H'00000000<br>H'E820953C<br>32|
||DVU0_3 volume value setting 7 register<br>VOL7R_DVU0_3<br>R/W<br>H'00000000<br>H'E8209540<br>32|
||DVU0_3 enable register<br>DVUER_DVU0_3<br>R/W<br>H'00000000<br>H'E8209544<br>32|
||DVU0_3 status register<br>DVUSR_DVU0_3<br>R<br>H'00000000<br>H'E8209548<br>32|
||DVU0_3 event mask register<br>VEVMR_DVU0_3<br>R/W<br>H'00000000<br>H'E820954C<br>32|
||DVU0_3 event clear register<br>VEVCR_DVU0_3<br>R/W*1<br>H'00000000<br>H'E8209554<br>32|
|MIX|MIX0_0 initialization register<br>MIXIR_MIX0_0<br>R/W<br>H'00000001<br>H'E8209600<br>32|
||MIX0_0 audio information register<br>MADIR_MIX0_0<br>R/W<br>H'00000000<br>H'E8209604<br>32|
||MIX0_0 bypass register<br>MIXBR_MIX0_0<br>R/W<br>H'00000000<br>H'E8209608<br>32|
||MIX0_0 mode register<br>MIXMR_MIX0_0<br>R/W<br>H'00000000<br>H'E820960C<br>32|
||MIX0_0 volume period register<br>MVPDR_MIX0_0<br>R/W<br>H'00000000<br>H'E8209610<br>32|
||MIX0_0 decibel A register<br>MDBAR_MIX0_0<br>R/W<br>H'00000000<br>H'E8209614<br>32|
||MIX0_0 decibel B register<br>MDBBR_MIX0_0<br>R/W<br>H'00000000<br>H'E8209618<br>32|
||MIX0_0 decibel C register<br>MDBCR_MIX0_0<br>R/W<br>H'00000000<br>H'E820961C<br>32|
||MIX0_0 decibel D register<br>MDBDR_MIX0_0<br>R/W<br>H'00000000<br>H'E8209620<br>32|
||MIX0_0 decibel enable register<br>MDBER_MIX0_0<br>R/W<br>H'00000000<br>H'E8209624<br>32|
||MIX0_0 status register<br>MIXSR_MIX0_0<br>R<br>H'00000000<br>H'E8209628<br>32|

## **Table 37.2 Register Configuration**

|**Table 37.2**|**Register Configuration**|
|---|---|
|**Block**<br>**Name**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial Value**<br>**Address**<br>**Access**<br>**Size**|
|CIM|Software reset register<br>SWRSR_CIM<br>R/W<br>H'00000001<br>H'E8209700<br>32|
||DMA control register<br>DMACR_CIM<br>R/W<br>H'00000000<br>H'E8209704<br>32|
||DMA transfer register for FFD0_0 RAM<br>DMATD0_CIM<br>W<br>—<br>H'E8209708<br>16,<br>32*2|
||DMA transfer register for FFD0_1 RAM<br>DMATD1_CIM<br>W<br>—<br>H'E820970C<br>16,<br>32*3|
||DMA transfer register for FFD0_2 RAM<br>DMATD2_CIM<br>W<br>—<br>H'E8209710<br>16,<br>32*4|
||DMA transfer register for FFD0_3 RAM<br>DMATD3_CIM<br>W<br>—<br>H'E8209714<br>16,<br>32*5|
||DMA transfer register for FFU0_0 RAM<br>DMATU0_CIM<br>R<br>—<br>H'E8209718<br>16,<br>32*6|
||DMA transfer register for FFU0_1 RAM<br>DMATU1_CIM<br>R<br>—<br>H'E820971C<br>16,<br>32*7|
||DMA transfer register for FFU0_2 RAM<br>DMATU2_CIM<br>R<br>—<br>H'E8209720<br>16,<br>32*8|
||DMA transfer register for FFU0_3 RAM<br>DMATU3_CIM<br>R<br>—<br>H'E8209724<br>16,<br>32*9|
||SSI route select register<br>SSIRSEL_CIM<br>R/W<br>H'00000000<br>H'E8209738<br>32|
||FFD0_0 timing select register<br>FDTSEL0_CIM<br>R/W<br>H'00000000<br>H'E820973C<br>32|
||FFD0_1 timing select register<br>FDTSEL1_CIM<br>R/W<br>H'00000000<br>H'E8209740<br>32|
||FFD0_2 timing select register<br>FDTSEL2_CIM<br>R/W<br>H'00000000<br>H'E8209744<br>32|
||FFD0_3 timing select register<br>FDTSEL3_CIM<br>R/W<br>H'00000000<br>H'E8209748<br>32|
||FFU0_0 timing select register<br>FUTSEL0_CIM<br>W<br>H'00000000<br>H'E820974C<br>32|
||FFU0_1 timing select register<br>FUTSEL1_CIM<br>W<br>H'00000000<br>H'E8209750<br>32|
||FFU0_2 timing select register<br>FUTSEL2_CIM<br>W<br>H'00000000<br>H'E8209754<br>32|
||FFU0_3 timing select register<br>FUTSEL3_CIM<br>W<br>H'00000000<br>H'E8209758<br>32|
||SSI pin mode register<br>SSIPMD_CIM<br>R/W<br>H'00000000<br>H'E820975C<br>32|
||SSI control register<br>SSICTRL_CIM<br>W<br>H'00000000<br>H'E8209760<br>32|
||SRC0 route select register<br>SRCRSEL0_CIM<br>R/W<br>H'76543210<br>H'E8209764<br>32|
||SRC1 route select register<br>SRCRSEL1_CIM<br>R/W<br>H'76543210<br>H'E8209768<br>32|
||SRC2 route select register<br>SRCRSEL2_CIM<br>R/W<br>H'76543210<br>H'E820976C<br>32|
||SRC3 route select register<br>SRCRSEL3_CIM<br>R/W<br>H'76543210<br>H'E8209770<br>32|
||MIX route select register<br>MIXRSEL_CIM<br>R/W<br>H'76543210<br>H'E8209774<br>32|

Note 1. Only 0 can be written to clear the flag. Writing 0 is ignored.

Note 2. Address H'E8209708 can be accessed in only 16-bit or 32-bit units.

Note 3. Address H'E820970C can be accessed in only 16-bit or 32-bit units.

Note 4. Address H'E8209710 can be accessed in only 16-bit or 32-bit units.

Note 5. Address H'E8209714 can be accessed in only 16-bit or 32-bit units. Note 6. Address H'E8209718 can be accessed in only 16-bit or 32-bit units. Note 7. Address H'E820971C can be accessed in only 16-bit or 32-bit units. Note 8. Address H'E8209720 can be accessed in only 16-bit or 32-bit units. Note 9. Address H'E8209724 can be accessed in only 16-bit or 32-bit units.

## 37.3.1 IPC0_n Initialization Register (IPCIR_IPC0_n) (n = 0, 1, 2, 3)

IPCIR_IPC0_n is a 32-bit readable/writable register that initializes the IPC internal circuit.

||||Bit:|31|30|||29|28|27|26|25|24||23|22|21|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-|-||-|-|-||-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0|0||0|0|0||0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R|R||R|R|R||R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9|8||7|6|5||4|3|2|1|0||
|||||-|-|||-|-|-|-|-|-||-|-|-||-|-|-|-|INIT||
||||Initial value:|0|0|||0|0|0|0|0|0||0|0|0||0|0|0|0|1||
||||R/W:|R|R|||R|R|R|R|R|R||R|R|R||R|R|R|R|R/W||
|||||||**Initial**|||||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**|||||||||||||
|31|to|1|—|||All||0||R||Reserved|||||||||||||
|||||||||||||These bits are always read as 0. The write|||||||||value|should always be 0.|||
|0|||INIT|||1||||R/W||Initialization|||||||||||||
|||||||||||||When this bit|||is set to 1,||the|IPC internal circuit is||||initialized. To cancel the|||
|||||||||||||initialization,|||set this bit||to 0|with it set to 1.|||||||
|||||||||||||0: Processing State|||||||||||||
|||||||||||||1: Initialization (sets the|||||initial||setting of other registers)||||||

## 37.3.2 IPC0_n Pass Select Register (IPSLR_IPC0_n) (n = 0, 1, 2, 3)

IPSLR_IPC0_n is a 32-bit readable/writable register that selects the input source and output destination of the input timing signal and audio data.

||Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-||-||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R|||
||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0|||
|||-|-||-|-|-|-|-<br>-<br>-<br>-|-|-|-|IPC_PASS_SEL|||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0|||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R/W|R/W|R/W|||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||
|31 to 3|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0. The write||||value|should always be 0.||||
|2 to 0|IPC_|||0|||R/W||IPC Pass Select|||||||||
||PASS_SEL||||||||These bits select the pass.|||||||||
||||||||||000: No operation|||||||||
||||||||||001: Input Timing Signal/Input Audio Data|||||||||
||||||||||: EXTERNAL(SSIF)|→ IPC → SRC (Async mode)||||||||
||||||||||010: Reserved|||||||||
||||||||||011: Input Timing Signal|||||||||
||||||||||: EXTERNAL → IPC → FFD/SRC|||||||||
||||||||||Input Audio Data|||||||||
||||||||||: FFD → IPC → SRC (Async mode)|||||||||
||||||||||100: Input Timing Signal/Input Audio Data|||||||||
||||||||||: FFD → IPC → SRC (Sync mode)|||||||||
||||||||||101 to 111: No operation|||||||||

## 37.3.3 OPC0_n Initialization Register (OPCIR_OPC0_n) (n = 0, 1, 2, 3)

OPCIR_OPC0_n is a 32-bit readable/writable register that initializes the OPC internal circuit.

||||Bit:|31|30|||29|28|27|26|25<br>24|23|22|21||20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-|-|-|-||-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0||0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R||R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8|7|6|5||4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-|-|-|-||-|-|-|-|INIT||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0||0|0|0|0|1||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R||R|R|R|R|R/W||
|||||||**Initial**|||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**|||||||||||
|31|to|1|—|||All||0||R||Reserved|||||||||||
|||||||||||||These bits are always read as|||||0. The write||value|should always be 0.|||
|0|||INIT|||1||||R/W||Initialization|||||||||||
|||||||||||||When this bit is set to 1, the OPC internal circuit is initialized. To cancel|||||||||||
|||||||||||||the initialization, set this bit to||||0 with||it set to 1.|||||
|||||||||||||0: Processing State|||||||||||
|||||||||||||1: Initialization (sets the|||initial|setting of other registers)|||||||

## 37.3.4 OPC0_n Pass Select Register (OPSLR_OPC0_n) (n = 0, 1, 2, 3)

OPSLR_OPC0_n is a 32-bit readable/writable register that selects the input source and output destination of the output timing signal and audio data.

||Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22|21|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|||-|-|-|-|-<br>-<br>-<br>-||-|-|-|-|-|-||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0||0|0|0|0|0|0||
||R/W:|R|R|||R|R|R|R|R<br>R<br>R<br>R||R|R|R|R|R|R||
||Bit:|15|14|||13|12|11|10|9<br>8<br>7<br>6||5|4|3|2|1|0||
|||-|-|||-|-|-|-|-<br>-<br>-<br>-||-|-|-|OPC_PASS_SEL||||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0||0|0|0|0|0|0||
||R/W:|R|R|||R|R|R|R|R<br>R<br>R<br>R||R|R|R|R/W|R/W|R/W||
|||||**Initial**|||||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**||**Description**|||||||||
|31 to 3|—|||All||0||R||Reserved|||||||||
|||||||||||These bits are always read as 0. The write|||||value|should always be 0.|||
|2 to 0|OPC_|||0||||R/W||OPC Pass Select|||||||||
||PASS_|||||||||These bits select the pass.|||||||||
||SEL|||||||||000: No operation|||||||||
|||||||||||001: Output Timing Signal|||||||||
|||||||||||: EXTERNAL → OPC → SRC/DVU|||||||||
|||||||||||Output Audio Data|||||||||
|||||||||||: SRC(Async mode) → OPC → DVU|||||||||
|||||||||||010: Reserved|||||||||
|||||||||||011: Output Timing Signal|||||||||
|||||||||||: EXTERNAL → OPC → FFU/SRC|||||||||
|||||||||||Output Audio Data|||||||||
|||||||||||: SRC(Async mode) → OPC → FFU|||||||||
|||||||||||100: Output Timing Signal||:|FFU → OPC → SRC||||||
|||||||||||Output Audio Data|||||||||
|||||||||||: SRC(Sync mode) →||OPC → FFU|||||||
|||||||||||101 to 111: No operation|||||||||

## 37.3.5 FFD0_n FIFO Download Initialization Register (FFDIR_FFD0_n) (n = 0, 1, 2, 3)

FFDIR_FFD0_n is a 32-bit readable/writable register that initializes the FFD internal circuit.

||||Bit:|31|30|||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|INIT||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|1||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R/W||
|||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**||||||||||
|31|to|1|—|||All||0||R||Reserved||||||||||
|||||||||||||These bits are always read as 0. The write||||||value|should always be 0.|||
|0|||INIT|||1||||R/W||Initialization||||||||||
|||||||||||||When this bit is set to 1, the FFD internal circuit is initialized. To cancel||||||||||
|||||||||||||the initialization, set this bit to||||0 with|it set to 1.|||||
|||||||||||||0: Processing State||||||||||
|||||||||||||1: Initialization (sets the|||initial|setting of other registers)||||||

## 37.3.6 FFD0_n FIFO Download Audio Information Register (FDAIR_FFD0_n) (n = 0, 1, 2, 3)

FDAIR_FFD0_n is a 32-bit readable/writable register that sets the number of FFD data channels.

||Bit:|31|30||29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-<br>-|-|-|-|-|-|-|-||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||Bit:|15|14||13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||-|-||-|-|-|-|-<br>-<br>-|-|-|-||CHNUM||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R|R|R|R|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||
|31 to 4|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0. The write|||||value|should always be 0.|||
|3 to 0|CHNUM|||All 0|||R/W||Number of Channels|||||||||
||||||||||These bits set the number of channels.|||||||||
||||||||||0000: Zero (None)|||||||||
||||||||||0001: 1 channel|||||||||
||||||||||0010: 2 channels*|||||||||
||||||||||0011: Reserved|||||||||
||||||||||0100: 4 channels*|||||||||
||||||||||0101: Reserved|||||||||
||||||||||0110: 6 channels*|||||||||
||||||||||0111: Reserved|||||||||
||||||||||1000: 8 channels*|||||||||
||||||||||1001 to 1111: Reserved|||||||||
||||||||||Note: * These bits are only settable for FFD0_0 and FFD0_1.||||||||Setting|
||||||||||these bits|in the|registers for||FFD0_2 and FFD0_3 is prohibited.|||||

## 37.3.7 FFD0_n FIFO Download Request Size Register (DRQSR_FFD0_n) (n = 0, 1, 2, 3)

DRQSR_FFD0_n is a 32-bit readable/writable register that sets the request size of data transfer requests.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|-|-|-|-||SIZE|||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 4|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|3 to 0|SIZE|All 0|R/W|Request Size|
|||||These bits set the PCM data size per request. The size must be less than|
|||||the FIFO size.|
|||||0000: 256 data. (FFD0_0,FFD0_1),|
|||||64 data. (FFD0_2,FFD0_3) *1|
|||||0001: 128 data. (FFD0_0,FFD0_1),|
|||||32 data. (FFD0_2,FFD0_3)|
|||||0010: 64 data. (FFD0_0,FFD0_1),|
|||||16 data. (FFD0_2,FFD0_3)|
|||||0011: 32 data. (FFD0_0,FFD0_1),|
|||||8 data. (FFD0_2,FFD0_3)|
|||||0100: 16 data. (FFD0_0,FFD0_1),|
|||||4 data. (FFD0_2,FFD0_3)|
|||||0101: 8 data. (FFD0_0,FFD0_1),|
|||||2 data. (FFD0_2,FFD0_3)|
|||||0110: 4 data. (FFD0_0,FFD0_1),|
|||||1 data. (FFD0_2,FFD0_3)|
|||||0111: 2 data. (FFD0_0,FFD0_1)*2|
|||||1000: 1 data. (FFD0_0,FFD0_1)*2|
|||||1001 to 1111: Reserved.|
|||||Notes:  1.  If the request size equals the FIFO size, the request size must|
|||||be a multiple of the number of channels so that the operation is|
|||||correct. For example, the request size and FIFO size are 256,|
|||||the number of channels can be set to 1, 2, 4, or 8. If the|
|||||number of channels is not set to any of the numbers, FIFO|
|||||overflow may occur.|
|||||2.  These bits are only settable for FFD0_0 and FFD0_1.|
|||||Setting these bits in the registers for FFD0_2 and FFD0_3 is|
|||||prohibited.|

## 37.3.8 FFD0_n FIFO Download Pass Register (FFDPR_FFD0_n) (n = 0, 1, 2, 3)

FFDPR_FFD0_n is a 32-bit readable/writable register that sets the input/output route of audio data.

||Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-||-||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0||0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R||R||
||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1||0||
|||-|-||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|PASS||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0||0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R/W|R/W|||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||
|31 to 2|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0. The write||||value|should always be 0.||||
|1, 0|PASS|||All 0|||R/W||Data Pass Select|||||||||
||||||||||These bits set the data pass of audio data.|||||||||
||||||||||00: No pass selected|||||||||
||||||||||01: CIM → FFD → IPC|(Async Mode) *1||||||||
||||||||||10: CIM → FFD → IPC|(Sync|Mode) *2|||||||
||||||||||11: Reserved|||||||||
||||||||||Notes: 1.- Async mode:|The FFD use external timing.||||||||
||||||||||2.- Sync mode: The FFD use|||the request which is||||generated by||
||||||||||SRC module.|Set Sync mode in|||SRC.|||||

## 37.3.9 FFD0_n FIFO Download Boot Register (FFDBR_FFD0_n) (n = 0, 1, 2, 3)

FFDBR_FFD0_n is a 32-bit readable/writable register that controls the starting and stopping of data requests sent to RFFD.

||||Bit:|31|30|||29|28|27|26|25<br>24|23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-|-<br>-|-|-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0<br>0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R<br>R|R|R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8|7<br>6|5|4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-|-<br>-|-|-|-|-|-|BOOT||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0<br>0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R<br>R|R|R|R|R|R|R/W||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**|||||||||
|31|to|1|—|||All||0||R||Reserved|||||||||
|||||||||||||These bits are always read as 0. The write|||||value|should always be 0.|||
|0|||BOOT|||0||||R/W||Data Request Start/Stop|||||||||
|||||||||||||This bit controls the start/stop|||of data request. This bit can be|||||set when|
|||||||||||||the PASS bits in the FFDPR register||||are set to B'01 or B'10. This bit|||||
|||||||||||||should be set after setting all FFD registers.|||||||||
|||||||||||||0: Stops the data request.|||||||||
|||||||||||||1: Starts the data request.|||||||||

## 37.3.10 FFD0_n FIFO Download Event Mask Register (DEVMR_FFD0_n) (n = 0, 1, 2, 3)

DEVMR_FFD0_n is a 32-bit readable/writable register that controls SCUFDIn interrupt requests.

||||Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||DEV|DEV||DEV|DEV|-|-|-<br>-<br>-<br>-|-|-|-|-|-|-||
|||||MUF|MOF||MOL|MIUF|||||||||||
||||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:|R/W|R/W||R/W|R/W|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R||
||||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||||DEV|-||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-|-||
|||||MRQ|||||||||||||||
||||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:|R/W|R||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R||
|||||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**||**Description**||||||||
|31|||DEVMUF|||0|||R/W||FFD Underflow Mask||||||||
||||||||||||This bit sets whether to|mask the interrupt|||request from the DEVCUF bit||||
||||||||||||in the DEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|30|||DEVMOF|||0|||R/W||FFD Overflow Mask||||||||
||||||||||||This bit sets whether to|mask the interrupt|||request from the DEVCOF bit||||
||||||||||||in the DEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|29|||DEVMOL|||0|||R/W||FFD Overlap Mask||||||||
||||||||||||This bit sets whether to|mask the interrupt|||request from the DEVCOL bit||||
||||||||||||in the DEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|28|||DEVMIUF|||0|||R/W||FFD Initialization Underflow Mask||||||||
||||||||||||This bit sets whether to|mask the interrupt request from the DEVCIUF bit|||||||
||||||||||||in the DEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|27|to|16|—|||All 0|||R||Reserved.||||||||
||||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|15|||DEVMRQ|||0|||R/W||FFD Request Packet Mask||||||||
||||||||||||This bit sets whether to|mask the interrupt|||request from the DEVCRQ bit||||
||||||||||||in the DEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|14|to|0|—|||All 0|||R||Reserved.||||||||
||||||||||||These bits are always read as 0. The write||||value|should always be 0.|||

## 37.3.11 FFD0_n FIFO Download Event Clear Register (DEVCR_FFD0_n) (n = 0, 1, 2, 3)

DEVCR_FFD0_n is a 32-bit readable/writable register that clears SCUFDIn interrupt requests. When an interrupt event is generated, the relevant bit in this register is automatically set to 1 and 1 is retained until 0 is written to that bit.

||||Bit:|31||30|29||28||27|26|25<br>24<br>23<br>22<br>21||20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||DEV||DEV|DEV||DEV||-|-|-<br>-<br>-<br>-<br>-||-|-|-|-|-||
|||||CUF||COF|COL||CIUF||||||||||||
||||Initial value:|0||0|0||0||0|0|0<br>0<br>0<br>0<br>0||0|0|0|0|0||
||||R/W:|R/(W)*1R/(W)*1R/(W)*1|||||R/(W)*1||R|R|R<br>R<br>R<br>R<br>R||R|R|R|R|R||
||||Bit:|15||14|13||12||11|10|9<br>8<br>7<br>6<br>5||4|3|2|1|0||
|||||DEV||-|-||-||-|-|-<br>-<br>-<br>-<br>-||-|-|-|-|-||
|||||CRQ|||||||||||||||||
||||Initial value:|0||0|0||0||0|0|0<br>0<br>0<br>0<br>0||0|0|0|0|0||
||||R/W:|R/(W)*1||R|R||R||R|R|R<br>R<br>R<br>R<br>R||R|R|R|R|R||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||||**R/W**||**Description**||||||||
|31|||DEVCUF|||0|||||R/(W)*1||FFD Underflow Clear||||||||
||||||||||||||This is an interrupt flag to indicate whether||||DPRAM underflow occurs.||||
||||||||||||||When it occurs and the first packet has already been written to DPRAM,||||||||
||||||||||||||this bit is set to 1.||||||||
||||||||||||||0: Clears the flag.||||||||
||||||||||||||1: Retains the flag.||||||||
|30|||DEVCOF|||0|||||R/(W)*1||FFD Overflow Clear||||||||
||||||||||||||This is an interrupt flag to indicate whether||||DPRAM overflow occurs.||||
||||||||||||||When it occurs, this bit is set to||1.||||||
||||||||||||||0: Clears the flag.||||||||
||||||||||||||1: Retains the flag.||||||||
|29|||DEVCOL|||0|||||R/(W)*1||FFD Overlap Clear||||||||
||||||||||||||This is an interrupt flag to indicate whether FFD overlap||||||occurs. When the||
||||||||||||||next read request occurs while FFD|||reads|data from DPRAM|||upon the|
||||||||||||||previous read request, the overflow occurs. When it occurs, this bit is set||||||||
||||||||||||||to 1.||||||||
||||||||||||||0: Clears the flag.||||||||
||||||||||||||1: Waiting.||||||||
|28|||DEVCIUF|||0|||||R/(W)*1||FFD Initialization Underflow Clear||||||||
||||||||||||||This is an interrupt flag to indicate whether||||DPRAM initialization||||
||||||||||||||underflow occurs. When it occurs and the first packet has not|||||||been|
||||||||||||||written to DPRAM, this bit is set to 1.||||||||
||||||||||||||0: Clears the flag.||||||||
||||||||||||||1: Retains the flag.||||||||
|27|to|16|—|||All 0|||||R||Reserved.||||||||
||||||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|15|||DEVCRQ|||0|||||R/(W)*1||FFD Request Packet Clear||||||||
||||||||||||||This is an interrupt flag to send||a request to write one packet in FFD, to||||||
||||||||||||||the CPU. When the request occurs, this bit is set|||||to 1.|||
||||||||||||||0: Clears the flag.||||||||
||||||||||||||1: Retains the flag.||||||||
|14|to|0|—|||All 0|||||R||Reserved.||||||||
||||||||||||||These bits are always read as 0. The write||||value|should always be 0.|||

Note 1. Readable/writable. When 0 is written, the bit is initialized. Writing 1 to the bit is ignored. Write 0 only to each bit corresponding to the interrupt source to be cleared; write 1 to other bits.

## 37.3.12 FFU0_n FIFO Upload Initialization Register (FFUIR_FFU0_n) (n = 0, 1, 2, 3)

FFUIR_FFU0_n is a 32-bit readable/writable register that initializes the FFU internal circuit.

||||Bit:|31|30|||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|INIT||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|1||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R/W||
|||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**||||||||||
|31|to|1|—|||All||0||R||Reserved||||||||||
|||||||||||||These bits are always read as 0. The write||||||value|should always be 0.|||
|0|||INIT|||1||||R/W||Initialization||||||||||
|||||||||||||When this bit is set to 1, the FFU internal circuit is initialized. To cancel||||||||||
|||||||||||||the initialization, set this bit to||||0 with|it set to 1.|||||
|||||||||||||0: Processing State||||||||||
|||||||||||||1: Initialization (sets the|||initial|setting of other registers)||||||

## 37.3.13 FFU0_n FIFO Upload Audio Information Register (FUAIR_FFU0_n) (n = 0, 1, 2, 3)

FUAIR_FFU0_n is a 32-bit readable/writable register that sets the number of FFU data channels.

||Bit:|31|30||29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-<br>-|-|-|-|-|-|-|-||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||Bit:|15|14||13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||-|-||-|-|-|-|-<br>-<br>-|-|-|-||CHNUM||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R|R|R|R|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||
|31 to 4|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0. The write|||||value|should always be 0.|||
|3 to 0|CHNUM|||All 0|||R/W||Number of Channels|||||||||
||||||||||These bits set the number of channels. For details, see|||||||below.||
||||||||||0000: Zero (None)|||||||||
||||||||||0001: 1 channel|||||||||
||||||||||0010: 2 channels*|||||||||
||||||||||0011: Reserved|||||||||
||||||||||0100: 4 channels*|||||||||
||||||||||0101: Reserved|||||||||
||||||||||0110: 6 channels*|||||||||
||||||||||0111: Reserved|||||||||
||||||||||1000: 8 channels*|||||||||
||||||||||1001 to 1111: Reserved|||||||||
||||||||||Note: *These bits|are only settable for FFU0_0 and FFU0_1. Setting||||||||
||||||||||these bits|in the registers for FFU0_2 and|||||FFU0_3 is prohibited.|||

## 37.3.14 FFU0_n FIFO Upload Request Size Register (URQSR_FFU0_n) (n = 0, 1, 2, 3)

URQSR_FFU0_n is a 32-bit readable/writable register that sets the request size of data transfer requests.

||Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-<br>-<br>-<br>-<br>-|-|-|-|-||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R|R|R|R|R||
||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|||-|-||-|-|-|-|-<br>-<br>-<br>-<br>-<br>-||SIZE||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R|R/W|R/W|R/W|R/W||
|||||**Initial**|||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**||||||
|31 to 4|—|||All 0|||R||Reserved||||||
||||||||||These bits are always read as 0. The write||value|should always be 0.|||
|3 to 0|SIZE|||All 0|||R/W||Request Size||||||
||||||||||These bits set the PCM data size per request. The size must be less than||||||
||||||||||the FIFO size.||||||
||||||||||0000: 256 data. (FFU0_0,FFU0_1),||||||
||||||||||64 data. (FFU0_2,FFU0_3) *1||||||
||||||||||0001: 128 data. (FFU0_0,FFU0_1),||||||
||||||||||32 data. (FFU0_2,FFU0_3)||||||
||||||||||0010: 64 data. (FFU0_0,FFU0_1),||||||
||||||||||16 data. (FFU0_2,FFU0_3)||||||
||||||||||0011: 32 data. (FFU0_0,FFU0_1),||||||
||||||||||8 data. (FFU0_2,FFU0_3)||||||
||||||||||0100: 16 data. (FFU0_0,FFU0_1),||||||
||||||||||4 data. (FFU0_2,FFU0_3)||||||
||||||||||0101: 8 data. (FFU0_0,FFU0_1),||||||
||||||||||2 data. (FFU0_2,FFU0_3)||||||
||||||||||0110: 4 data. (FFU0_0,FFU0_1),||||||
||||||||||1 data. (FFU0_2,FFU0_3)||||||
||||||||||0111: 2 data. (FFU0_0,FFU0_1)*2||||||
||||||||||1000: 1 data. (FFU0_0,FFU0_1)*2||||||
||||||||||1001 to 1111: Reserved.||||||
||||||||||Note 1. If the request size equals the FIFO size,|||the request size must|||
||||||||||be a multiple of the number|of channels||so that the operation is|||
||||||||||correct. For example, the request||size and FIFO size are 256,||||
||||||||||the number of channels can be set to 1,|||2, 4, or 8. If the number|||
||||||||||of channels is not set to any of the numbers, FIFO overflow may||||||
||||||||||occur.||||||
||||||||||Note 2. These bits are only settable for FFU0_0|||and FFU0_1.|||
||||||||||Setting these bits in the registers for FFU0_2 and FFU0_3 is||||||
||||||||||prohibited.||||||

## 37.3.15 FFU0_n FIFO Upload Pass Register (FFUPR_FFU0_n) (n = 0, 1, 2, 3)

FFUPR_FFU0_n is a 32-bit readable/writable register that sets the input/output route of audio data.

||Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-||-||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0||0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R||R||
||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1||0||
|||-|-||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|PASS||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0||0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R/W|R/W|||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||
|31 to 2|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0. The write value|||||should always be 0.||||
|1, 0|PASS|||All 0|||R/W||Data Pass Select|||||||||
||||||||||These bits set the data pass of audio data.|||||||||
||||||||||00: No pass selected|||||||||
||||||||||01: CIM ← FFU ← OPC (Async Mode) *1|||||||||
||||||||||10: CIM ← FFU ← OPC (Sync Mode) *2|||||||||
||||||||||11: Reserved|||||||||
||||||||||Notes: 1. Async mode:|The FFU use external timing.||||||||
||||||||||2. Sync mode: The FFU use|||the request which|||is|generated by||
||||||||||SRC module. Set Sync mode in||||SRC.|||||

## 37.3.16 FFU0_n FIFO Upload Event Mask Register (UEVMR_FFU0_n) (n = 0, 1, 2, 3)

UEVMR_FFU0_n is a 32-bit readable/writable register that controls SCUFUIn interrupt requests.

||||Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||UEV|UEV||UEV|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-|-||
|||||MUF|MOF||MOL||||||||||||
||||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:|R/W|R/W||R/W|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R||
||||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||||UEV|-||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-|-||
|||||MRQ|||||||||||||||
||||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:|R/W|R||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R||
|||||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**||**Description**||||||||
|31|||UEVMUF|||0|||R/W||FFU Underflow Mask||||||||
||||||||||||This bit sets whether to mask the interrupt request from the UEVCUF bit||||||||
||||||||||||in the UEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|30|||UEVMOF|||0|||R/W||FFU Overflow Mask||||||||
||||||||||||This bit sets whether to mask the interrupt request from the UEVCOF bit||||||||
||||||||||||in the UEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|29|||UEVMOL|||0|||R/W||FFU Overlap Mask||||||||
||||||||||||This bit sets whether to mask the interrupt request from the UEVCOL bit||||||||
||||||||||||in the UEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|28|to|16|—|||All 0|||R||Reserved.||||||||
||||||||||||These bits are always read as||0. The write||value|should always be 0.|||
|15|||UEVMRQ|||0|||R/W||FFU Request Packet Mask||||||||
||||||||||||This bit sets whether to mask the interrupt request from the UEVCRQ bit||||||||
||||||||||||in the UEVCR register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|14|to|0|—|||All 0|||R||Reserved.||||||||
||||||||||||These bits are always read as||0. The write||value|should always be 0.|||

## 37.3.17 FFU0_n FIFO Upload Event Clear Register (UEVCR_FFU0_n) (n = 0, 1, 2, 3)

UEVCR_FFU0_n is a 32-bit readable/writable register that clears SCUFUIn interrupt requests. When an interrupt event is generated, the relevant bit in this register is automatically set to 1 and 1 is retained until 0 is written to that bit.

||||Bit:|31||30|29||28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||UEV||UEV|UEV||-|-|-|-<br>-<br>-|-|-|-|-|-|-|-||
|||||CUF||COF|COL||||||||||||||
||||Initial value:|0||0|0||0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:|R/(W)*1||R/(W)*1R/(W)*1|||R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||||Bit:|15||14|13||12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||||UEV||-|-||-|-|-|-<br>-<br>-|-|-|-|-|-|-|-||
|||||CRQ|||||||||||||||||
||||Initial value:|0||0|0||0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:|R/(W)*1||R|R||R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**|||||||||
|31|||UEVCUF|||0||||R/(W)*1||FFU Underflow Clear|||||||||
|||||||||||||This is a flag to indicate||whether DPRAM underflow occurs. When it|||||||
|||||||||||||occurs, this bit is set to 1.|||||||||
|||||||||||||0: Clears the flag.|||||||||
|||||||||||||1: Retains the flag.|||||||||
|30|||UEVCOF|||0||||R/(W)*1||FFU Overflow Clear|||||||||
|||||||||||||This is a flag to indicate||whether DPRAM overflow occurs. When it|||||||
|||||||||||||occurs, this bit is set to 1.|||||||||
|||||||||||||0: Clears the flag.|||||||||
|||||||||||||1: Retains the flag.|||||||||
|29|||UEVCOL|||0||||R/(W)*1||FFU Overlap Clear|||||||||
|||||||||||||This is a flag to indicate||whether DPRAM overlap occurs. When the next|||||||
|||||||||||||write request occurs while FFU writes data|||||upon the previous|||write|
|||||||||||||request, the overlap occurs. When it||||occurs, this||bit is set to 1.|||
|||||||||||||0: Clears the flag.|||||||||
|||||||||||||1: Retains the flag.|||||||||
|28|to|16|—|||All 0||||R||Reserved.|||||||||
|||||||||||||These bits are always read as|||0. The write||value|should always be 0.|||
|15|||UEVCRQ|||0||||R/(W)*1||FFU Request Packet Clear|||||||||
|||||||||||||This is an interrupt flag to send a request to read one packet from FFU, to|||||||||
|||||||||||||the CPU. When the request occurs, this bit is set||||||to 1.|||
|||||||||||||0: Clears the flag.|||||||||
|||||||||||||1: Retains the flag.|||||||||
|14|to|0|—|||All 0||||R||Reserved.|||||||||
|||||||||||||These bits are always read as|||0. The write||value|should always be 0.|||

Note 1. Readable/writable. When 0 is written, the bit is initialized. Writing 1 to the bit is ignored. Write 0 only to each bit corresponding to the interrupt source to be cleared; write 1 to other bits.

## 37.3.18 2SRC0_m Initialization Register p (SRCIRp_2SRC0_m) (m = 0, 1; p = 0, 1)

SRCIRp_2SRC0_m is a 32-bit readable/writable register that initializes the SRC internal circuit.

||||Bit:|31|30|||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|INIT||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|1||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R/W||
|||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**||||||||||
|31|to|1|—|||All||0||R||Reserved||||||||||
|||||||||||||These bits are always read as 0. The write||||||value|should always be 0.|||
|0|||INIT|||1||||R/W||Initialization||||||||||
|||||||||||||When this bit is set to 1, the SRC internal circuit is initialized. To cancel||||||||||
|||||||||||||the initialization, set this bit to||||0 with|it set to 1.|||||
|||||||||||||0: Processing State||||||||||
|||||||||||||1: Initialization (sets the|||initial|setting of other registers)||||||

## 37.3.19 2SRC0_m Audio Information Register p (SADIRp_2SRC0_m) (m = 0, 1; p = 0, 1)

SADIRp_2SRC0_m is a 32-bit readable/writable register that sets the bit length of data and the number of channels.

||Bit:|31|30||29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-<br>-|-|-|||OTBL||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R|R|R|R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14||13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||-|-||-|-|-|-|-<br>-<br>-|-|-|-||CHNUM||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R|R|R|R|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||
|31 to 21|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as|||0. The write||value|should|always be 0.||
|20 to 16|OTBL|||All 0|||R/W||Bit Length of Output Audio Data|||||||||
||||||||||00000: 24 bits|||||||||
||||||||||00001 to 00111: Reserved|||||||||
||||||||||01000: 16 bits|||||||||
||||||||||01001 to 11111: Reserved|||||||||
|15 to 4|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as|||0. The write||value|should|always be 0.||
|3 to 0|CHNUM|||All 0|||R/W||Number of Channels|||||||||
||||||||||These bits set the number of channels.|||||||||
||||||||||0000: Zero (None)|||||||||
||||||||||0001: 1 channel|||||||||
||||||||||0010: 2 channels|||||||||
||||||||||0011: Reserved|||||||||
||||||||||0100: 4 channels|||||||||
||||||||||0101: Reserved|||||||||
||||||||||0110: 6 channels|||||||||
||||||||||0111: Reserved|||||||||
||||||||||1000: 8 channels|||||||||
||||||||||1001 to 1111: Reserved|||||||||

## 37.3.20 2SRC0_m Bypass Register p (SRCBRp_2SRC0_m) (m = 0, 1; p = 0, 1)

SRCBRp_2SRC0_m is a 32-bit readable/writable register that sets the bypass mode.

||||Bit:|31|30|||29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-<br>-|-|-|-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-<br>-|-|-|-|-|-|-|BY||
||||||||||||||||||||PASS||
||||Initial value:|0|0|||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R/W||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**|||||||||
|31|to|1|—|||All||0||R||Reserved|||||||||
|||||||||||||These bits are always read as|||0. The write||value|should always be 0.|||
|0|||BYPASS|||0||||R/W||Bypass Mode|||||||||
|||||||||||||This bit controls the data pass|||of SRC. The bypass function is only used||||||
|||||||||||||in asynchronous SRC mode. Therefore, this bit must be set to|||||||||
|||||||||||||0 when synchronous SRC mode is used (bit SRCMD0 in|||||||||
|||||||||||||SRCCRp_2SRC0_m register is 1).|||||||||
|||||||||||||0: SRC function is used.|||||||||
|||||||||||||Input data is processed by SRC and then the result data is||||||||connected|
|||||||||||||to output data.|||||||||
|||||||||||||1: SRC function is not used.|||||||||
|||||||||||||Input data is directly connected to||||output data.|||||

## 37.3.21 2SRC0_m IFS Control Register p (IFSCRp_2SRC0_m) (m = 0, 1; p = 0, 1)

IFSCRp_2SRC0_m is a 32-bit readable/writable register that enables or disables usage of the initial value set by INTIFS.

||||Bit:|31|30|||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|INT||
|||||||||||||||||||||IFSEN||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R/W||
|||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**||||||||||
|31|to|1|—|||All||0||R||Reserved||||||||||
|||||||||||||These bits are always read as||||0. The write||value|should always be 0.|||
|0|||INTIFSEN|||0||||R/W||INTIFS Value Enable||||||||||
|||||||||||||This bit is enabled only in asynchronous SRC mode (bit SRCMD in||||||||||
|||||||||||||SRCCRp_2SRC0_m register is 0).||||||||||
|||||||||||||0: Disables|initial|value setting in IFSVR register.||||||||
|||||||||||||1: Enables|initial value setting|||in IFSVR register.||||||

## 37.3.22 2SRC0_m IFS Value Setting Register p (IFSVRp_2SRC0_m) (m = 0, 1; p = 0, 1)

IFSVRp_2SRC0_m is a 32-bit readable/writable register that sets the INTIFS value.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-||||||INTIFS|||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||INTIFS|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|28|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|27|to|0|INTIFS|All 0|R/W|Initial Value of FSI|
|||||||These bits set initial value of FSI. Set the input sampling rate and output|
|||||||sampling rate within the restricted range determined by the number of|
|||||||channels.|
|||||||Example:|
|||||||Fin = 32 kHz|
|||||||Fout = 44.1 kHz|
|||||||FSI = 222* 32000/44100 = 3043485 = 0x02E709D|

When using the SRC in asynchronous mode, INTIFS is given as the initial value of FSI, which is the sampling conversion function. Therefore, after setting the INTIFSEN bit in IFSCRp_2SRC0_m to 1, set the INTIFS bits to the desired value. The SRC automatically detects the input sampling frequency and output sampling frequency. Based on this, the FSI value is calculated so that the following equation is satisfied.

|_Fin_||_FSI_|
|---|---|---|
||≈||
|_Fout_||_FSO_|

## [Legend]

Fin: Input sampling frequency

Fout: Output sampling frequency FSI: Input sampling rate FSO: Output sampling rate (fixed value: 2[22 ] = 0x0400000)

When using the SRC in synchronous mode, the value set in INTIFS is used as the FSI value from beginning to end. The value set in INITFS is shown in Table 37.3 to Table 37.8 .

**Table 37.3 INITFS Setting (Delay Mode: Normal, Number of Channels: 1 or 2)**

|**Table 37.3**|**INITFS Setting (Delay Mode: Normal, Number of Channels: 1 or 2)**|
|---|---|
|**Input**<br>**Sampling**<br>**Rate [KHz]**|**Output Sampling Rate [KHz]**|
||**8**<br>**16**<br>**24**<br>**32**<br>**44.1**<br>**48**<br>**96**|
|8|0x0400000<br>0x0200000<br>0x0155555<br>0x0100000<br>0x00b9c27<br>0x00aaaaa<br>0x0055555|
|11.025|0x0583333<br>0x02c1999<br>0x01d6666<br>0x0160ccc<br>0x0100000<br>0x00eb333<br>0x0075999|
|12|0x0600000<br>0x0300000<br>0x0200000<br>0x0180000<br>0x0116a3b<br>0x0100000<br>0x0080000|
|16|0x0800000<br>0x0400000<br>0x02aaaaa<br>0x0200000<br>0x017384e<br>0x0155555<br>0x00aaaaa|
|22.05|0x0b06666<br>0x0583333<br>0x03acccc<br>0x02c1999<br>0x0200000<br>0x01d6666<br>0x00eb333|
|24|0x0c00000<br>0x0600000<br>0x0400000<br>0x0300000<br>0x022d476<br>0x0200000<br>0x0100000|
|32|0x1000000<br>0x0800000<br>0x0555555<br>0x0400000<br>0x02e709d<br>0x02aaaaa<br>0x0155555|
|44.1|0x160cccc<br>0x0b06666<br>0x0759999<br>0x0583333<br>0x0400000<br>0x03acccc<br>0x01d6666|
|48|0x1800000<br>0x0c00000<br>0x0800000<br>0x0600000<br>0x045a8ec<br>0x0400000<br>0x0200000|
|64|0x2000000<br>0x1000000<br>0x0aaaaaa<br>0x0800000<br>0x05ce13b<br>0x0555555<br>0x02aaaaa|
|88.2|Setting<br>prohibited*1<br>0x160cccc<br>0x0eb3333<br>0x0b06666<br>0x0800000<br>0x0759999<br>0x03acccc|
|96|Setting<br>prohibited*1<br>0x1800000<br>0x1000000<br>0x0c00000<br>0x08b51d9<br>0x0800000<br>0x0400000|

Note 1. This is because the setting is outside the specification of the SRC module. For details, see Table 37.22.

## **Table 37.4 INITFS Setting (Delay Mode: Normal, Number of Channels: 4)**

|**Table 37.4**|**INITFS Setting (Delay Mode: Normal, Number of Channels: 4)**|
|---|---|
|**Input**<br>**Sampling**<br>**Rate [KHz]**|**Output Sampling Rate [KHz]**|
||**8**<br>**16**<br>**24**<br>**32**<br>**44.1**<br>**48**<br>**96**|
|8|0x0400000<br>0x0200000<br>0x0155555<br>0x0100000<br>0x00b9c27<br>0x00aaaaa<br>0x0055555|
|11.025|0x0583333<br>0x02c1999<br>0x01d6666<br>0x0160ccc<br>0x0100000<br>0x00eb333<br>0x0075999|
|12|0x0600000<br>0x0300000<br>0x0200000<br>0x0180000<br>0x0116a3b<br>0x0100000<br>0x0080000|
|16|0x0800000<br>0x0400000<br>0x02aaaaa<br>0x0200000<br>0x017384e<br>0x0155555<br>0x00aaaaa|
|22.05|0x0b06666<br>0x0583333<br>0x03acccc<br>0x02c1999<br>0x0200000<br>0x01d6666<br>0x00eb333|
|24|0x0c00000<br>0x0600000<br>0x0400000<br>0x0300000<br>0x022d476<br>0x0200000<br>0x0100000|
|32|0x1000000<br>0x0800000<br>0x0555555<br>0x0400000<br>0x02e709d<br>0x02aaaaa<br>0x0155555|
|44.1|Setting<br>prohibited*1<br>0x0b06666<br>0x0759999<br>0x0583333<br>0x0400000<br>0x03acccc<br>0x01d6666|
|48|Setting<br>prohibited*1<br>0x0c00000<br>0x0800000<br>0x0600000<br>0x045a8ec<br>0x0400000<br>0x0200000|
|64|Setting<br>prohibited*1<br>0x1000000<br>0x0aaaaaa<br>0x0800000<br>0x05ce13b<br>0x0555555<br>0x02aaaaa|
|88.2|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0eb3333<br>0x0b06666<br>0x0800000<br>0x0759999<br>0x03acccc|
|96|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x1000000<br>0x0c00000<br>0x08b51d9<br>0x0800000<br>0x0400000|

Note 1. This is because the setting is outside the specification of the SRC module. For details, see Table 37.22.

**Table 37.5 INITFS Setting (Delay Mode: Normal, Number of Channels: 6)**

|**Table 37.5**|**INITFS Setting (Delay Mode: Normal, Number of Channels: 6)**|
|---|---|
|**Input**<br>**Sampling**<br>**Rate [KHz]**|**Output Sampling Rate [KHz]**|
||**8**<br>**16**<br>**24**<br>**32**<br>**44.1**<br>**48**<br>**96**|
|8|0x0400000<br>0x0200000<br>0x0155555<br>0x0100000<br>0x00b9c27<br>0x00aaaaa<br>Setting<br>prohibited*1|
|11.025|0x0583333<br>0x02c1999<br>0x01d6666<br>0x0160ccc<br>0x0100000<br>0x00eb333<br>Setting<br>prohibited*1|
|12|0x0600000<br>0x0300000<br>0x0200000<br>0x0180000<br>0x0116a3b<br>0x0100000<br>Setting<br>prohibited*1|
|16|0x0800000<br>0x0400000<br>0x02aaaaa<br>0x0200000<br>0x017384e<br>0x0155555<br>Setting<br>prohibited*1|
|22.05|Setting<br>prohibited*1<br>0x0583333<br>0x03acccc<br>0x02c1999<br>0x0200000<br>0x01d6666<br>Setting<br>prohibited*1|
|24|Setting<br>prohibited*1<br>0x0600000<br>0x0400000<br>0x0300000<br>0x022d476<br>0x0200000<br>Setting<br>prohibited*1|
|32|Setting<br>prohibited*1<br>0x0800000<br>0x0555555<br>0x0400000<br>0x02e709d<br>0x02aaaaa<br>Setting<br>prohibited*1|
|44.1|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0759999<br>0x0583333<br>0x0400000<br>0x03acccc<br>Setting<br>prohibited*1|
|48|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0800000<br>0x0600000<br>0x045a8ec<br>0x0400000<br>Setting<br>prohibited*1|
|64|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0aaaaaa<br>0x0800000<br>0x05ce13b<br>0x0555555<br>Setting<br>prohibited*1|
|88.2|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1|
|96|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1|

Note 1. This is because the setting is outside the specification of the SRC module. For details, see Table 37.22.

**Table 37.6 INITFS Setting (Delay Mode: Normal, Number of Channels: 8)**

|**Table 37.6**|**INITFS Setting (Delay Mode: Normal, Number of Channels: 8)**|
|---|---|
|**Input**<br>**Sampling**<br>**Rate [KHz]**|**Output Sampling Rate [KHz]**|
||**8**<br>**16**<br>**24**<br>**32**<br>**44.1**<br>**48**<br>**96**|
|8|0x0400000<br>0x0200000<br>0x0155555<br>0x0100000<br>0x00b9c27<br>0x00aaaaa<br>Setting<br>prohibited*1|
|11.025|0x0583333<br>0x02c1999<br>0x01d6666<br>0x0160ccc<br>0x0100000<br>0x00eb333<br>Setting<br>prohibited*1|
|12|0x0600000<br>0x0300000<br>0x0200000<br>0x0180000<br>0x0116a3b<br>0x0100000<br>Setting<br>prohibited*1|
|16|0x0800000<br>0x0400000<br>0x02aaaaa<br>0x0200000<br>0x017384e<br>0x0155555<br>Setting<br>prohibited*1|
|22.05|Setting<br>prohibited*1<br>0x0583333<br>0x03acccc<br>0x02c1999<br>0x0200000<br>0x01d6666<br>Setting<br>prohibited*1|
|24|Setting<br>prohibited*1<br>0x0600000<br>0x0400000<br>0x0300000<br>0x022d476<br>0x0200000<br>Setting<br>prohibited*1|
|32|Setting<br>prohibited*1<br>0x0800000<br>0x0555555<br>0x0400000<br>0x02e709d<br>0x02aaaaa<br>Setting<br>prohibited*1|
|44.1|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0759999<br>0x0583333<br>0x0400000<br>0x03acccc<br>Setting<br>prohibited*1|
|48|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0800000<br>0x0600000<br>0x045a8ec<br>0x0400000<br>Setting<br>prohibited*1|
|64|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1|
|88.2|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1|
|96|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1|

Note 1. This is because the setting is outside the specification of the SRC module. For details, see Table 37.22.

**Table 37.7 INITFS Setting (Delay Mode: Low Delay 1, Number of Channels: 1 or 2)**

|**Table 37.7**|**INITFS Setting (Delay Mode: Low Delay 1, Number of Channels: 1 or 2)**|
|---|---|
|**Input**<br>**Sampling**<br>**Rate [KHz]**|**Output Sampling Rate [KHz]**|
||**8**<br>**16**<br>**24**<br>**32**<br>**44.1**<br>**48**<br>**96**|
|8|0x0400000<br>0x0200000<br>0x0155555<br>0x0100000<br>0x00b9c27<br>0x00aaaaa<br>0x0055555|
|11.025|0x0583333<br>0x02c1999<br>0x01d6666<br>0x0160ccc<br>0x0100000<br>0x00eb333<br>0x0075999|
|12|0x0600000<br>0x0300000<br>0x0200000<br>0x0180000<br>0x0116a3b<br>0x0100000<br>0x0080000|
|16|0x0800000<br>0x0400000<br>0x02aaaaa<br>0x0200000<br>0x017384e<br>0x0155555<br>0x00aaaaa|
|22.05|Setting<br>prohibited*1<br>0x0583333<br>0x03acccc<br>0x02c1999<br>0x0200000<br>0x01d6666<br>0x00eb333|
|24|Setting<br>prohibited*1<br>0x0600000<br>0x0400000<br>0x0300000<br>0x022d476<br>0x0200000<br>0x0100000|
|32|Setting<br>prohibited*1<br>0x0800000<br>0x0555555<br>0x0400000<br>0x02e709d<br>0x02aaaaa<br>0x0155555|
|44.1|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0759999<br>0x0583333<br>0x0400000<br>0x03acccc<br>0x01d6666|
|48|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0800000<br>0x0600000<br>0x045a8ec<br>0x0400000<br>0x0200000|
|64|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0800000<br>0x05ce13b<br>0x0555555<br>0x02aaaaa|
|88.2|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0800000<br>0x0759999<br>0x03acccc|
|96|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0800000<br>0x0400000|

Note 1. This is because the setting is outside the specification of the SRC module. For details, see Table 37.22.

## **Table 37.8 INITFS Setting (Delay Mode: Low Delay 2, Number of Channels: 1 or 2)**

|**Table 37.8**|**INITFS Setting (Delay Mode: Low Delay 2, Number of Channels: 1 or 2)**|
|---|---|
|**Input**<br>**Sampling**<br>**Rate [KHz]**|**Output Sampling Rate [KHz]**|
||**8**<br>**16**<br>**24**<br>**32**<br>**44.1**<br>**48**<br>**96**|
|8|0x0400000<br>0x0200000<br>0x0155555<br>0x0100000<br>0x00b9c27<br>0x00aaaaa<br>0x0055555|
|11.025|Setting<br>prohibited*1<br>0x02c1999<br>0x01d6666<br>0x0160ccc<br>0x0100000<br>0x00eb333<br>0x0075999|
|12|Setting<br>prohibited*1<br>0x0300000<br>0x0200000<br>0x0180000<br>0x0116a3b<br>0x0100000<br>0x0080000|
|16|Setting<br>prohibited*1<br>0x0400000<br>0x02aaaaa<br>0x0200000<br>0x017384e<br>0x0155555<br>0x00aaaaa|
|22.05|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x03acccc<br>0x02c1999<br>0x0200000<br>0x01d6666<br>0x00eb333|
|24|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0400000<br>0x0300000<br>0x022d476<br>0x0200000<br>0x0100000|
|32|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0400000<br>0x02e709d<br>0x02aaaaa<br>0x0155555|
|44.1|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0400000<br>0x03acccc<br>0x01d6666|
|48|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0400000<br>0x0200000|
|64|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x02aaaaa|
|88.2|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x03acccc|
|96|Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>Setting<br>prohibited*1<br>0x0400000|

Note 1. This is because the setting is outside the specification of the SRC module. For details, see Table 37.22.

## 37.3.23 2SRC0_m Control Register p (SRCCRp_2SRC0_m) (m = 0, 1; p = 0, 1)

SRCCRp_2SRC0_m is a 32-bit readable/writable register that selects the low delay mode, and synchronous or asynchronous mode of the SRC.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|WATMD|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R/W|R|R|R|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|BUFMD|-|-|-|-|-|-|-|-|-|-|-|SRCMD|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|R|R|R|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 21|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|20|WATMD|0|R/W|Wait Time Control of SRC|
|||||0: Disables wait time control.|
|||||1: Enables wait time control.|
|19 to 17|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|16|—|0|R/W|The write value should always be 1.|
|15 to 13|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|12|BUFMD|0|R/W|Low Delay Mode|
|||||0: Disables low delay mode.|
|||||1: Enables low delay mode.|
|11 to 9|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|8|—|0|R/W|The write value should always be 1.|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|—|0|R/W|The write value should always be 1.|
|3 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|SRCMD|0|R/W|SRC Mode Select|
|||||0: Asynchronous SRC|
|||||1: Synchronous SRC|

## 37.3.24 2SRC0_m Minimum FS Setting Register p (MNFSRp_2SRC0_m) (m = 0, 1; p = 0, 1)

MNFSRp_2SRC0_m is a 32-bit readable/writable register that sets the minimum value of FS.

||||Bit:|31|30|29|28|27|26|25<br>24<br>23<br>22<br>21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|-|-|||MINFS|||||||
||||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:|R|R|R|R|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
||||Bit:|15|14|13|12|11|10|9<br>8<br>7<br>6<br>5|4|3|2|1|0||
|||||||||||MINFS|||||||
||||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0|0|0|0|0|0||
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||
||||||**Initial**||||||||||||
|**Bit**|||**Bit Name**||**Value**|||**R/W**||**Description**|||||||
|31|to|28|—||All 0|||R||Reserved|||||||
|||||||||||These bits are always read as 0. The write value||||should always be 0.|||
|27|to|0|MINFS||All 0|||R/W||Minimum Value of FS Ratio|||||||
|||||||||||These bits set the FS ratio to start fading out the||||output|data to mute||
|||||||||||under the situation that the input timing stops during SRC processing.|||||||
|||||||||||This setting value should be less than the|||value of IFSVRp_2SRC0_m||||
|||||||||||register.|||||||
|||||||||||Example:|||||||
|||||||||||Fin = 32kHz|||||||
|||||||||||Fout = 44.1kHz|||||||
|||||||||||FSI = 222* 32000/44100 = 3043485 = 0x02E709D|||||||
|||||||||||MINFS = FSI * 98% = 2982615 = 0x02D82D7|||||||
|||||||||||Set the ratio which is out of the range of the jitter.|||||||
|||||||||||(The recommended value is from 90 to 98 percent.)|||||||

## 37.3.25 2SRC0_m Buffer Size Setting Register p (BFSSRp_2SRC0_m) (m = 0, 1; p = 0, 1)

BFSSRp_2SRC0_m is a 32-bit readable/writable register that sets the buffer size. This register setting is valid only when SRCCRp_2SRC0_m.BUFMD = 1.

||Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|BUFDATA||||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|||-|-||-|-|-|-|-<br>-<br>-<br>-<br>-<br>-||BUFIN||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R|R/W|R/W|R/W|R/W||
|||||**Initial**|||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**||||||
|31 to 26|—|||All 0|||R||Reserved||||||
||||||||||These bits are always read as 0. The write||value|should|always be 0.||
|25 to 16|BUFDATA|||All 0|||R/W||Set the buffer size of 1 channel in DATA RAM.||||||
||||||||||Sets 0x80 for low delay mode 1.||||||
||||||||||Sets 0x40 for low delay mode 2.||||||
|15 to 4|—|||All 0|||R||Reserved||||||
||||||||||These bits are always read as 0. The write||value|should|always be 0.||
|3 to 0|BUFIN|||All 0|||R/W||Set the buffer size of 1 channel in INDATA||RAM.||||
||||||||||Sets 0x5 for low delay mode.||||||

## 37.3.26 2SRC0_m SCU2 Status Register p (SC2SRp_2SRC0_m) (m = 0, 1; p = 0, 1)

SC2SRp_2SRC0_m is a 32-bit read-only register that indicates the status of the SRC.

||Bit:|31|30|29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||SRCW<br>STS|SC2<br>MUTE|SC2STS|||||SC2FSI||||||||
||Initial value:|0|0|0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R|R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||Bit:|15|14|13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||||||||SC2FSI|||||||||
||Initial value:|0|0|0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R|R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||||**Initial**||||||||||||||
|**Bit**|**Bit Name**||**Value**|||**R/W**||**Description**|||||||||
|31|SRCWSTS||0|||R||Status of Wait Time Operation of SRC|||||||||
|||||||||0: Wait for count up to wait time|||||||||
|||||||||1: Reached to wait|time||||||||
|30|SC2MUTE||0|||R||SRC Mute Status|||||||||
|||||||||This bit is only used for debug.|||||||||
|||||||||0: SRC output data|is not fixed and it should be|||||muted. This happens|||
|||||||||when SRC cannot synchronize the input|||||sampling rate and output||||
|||||||||sampling rate.|||||||||
|||||||||1: SRC output data|is fixed.||||||||
|29, 28|SC2STS||All 0|||R||Status of SRC|||||||||
|||||||||00: SRC is reset.|||||||||
|||||||||01: SRC is initialized.|||||||||
|||||||||10: SRC is processing.|||||||||
|||||||||11: Reserved|||||||||
|27 to 0|SC2FSI||All 0|||R||Latest value of FSI|which is calculated by SRC||||||||

## 37.3.27 2SRC0_m Wait Time Setting Register p (WATSRp_2SRC0_m) (m = 0, 1; p = 0, 1)

WATSRp_2SRC0_m is a 32-bit readable/writable register that sets the wait time for data input to the SRC.

||||Bit:|31|30|29|28|27|26|25<br>24|23<br>22<br>21<br>20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|-|-|-|-|-<br>-|WTIME|||||
||||Initial value:|0|0|0|0|0|0|0<br>0|0<br>0<br>0<br>0<br>0|0|0|0||
||||R/W:|R|R|R|R|R|R|R<br>R|R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W||
||||Bit:|15|14|13|12|11|10|9<br>8|7<br>6<br>5<br>4<br>3|2|1|0||
|||||||||||WTIME||||||
||||Initial value:|0|0|0|0|0|0|0<br>0|0<br>0<br>0<br>0<br>0|0|0|0||
||||R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W<br>R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W||
||||||**Initial**|||||||||||
|**Bit**|||**Bit Name**||**Value**|||**R/W**||**Description**||||||
|31|to|24|—||All 0|||R||Reserved||||||
|||||||||||These bits are always read as 0. The write||value|should|always be 0.||
|23|to|0|WTIME||All 0|||R/W||These bits set the wait time when WATMD||bit of SRCCRp_2SRC0_m||||
|||||||||||register is 1. After the INIT bit of SRCIRp_2SRC0_m register is set to 0, 0||||||
|||||||||||data is stored into the SRC until the number of input data reaches to the||||||
|||||||||||setting value of these bits. The data input before|||the INIT bit is set to 0 is|||
|||||||||||discarded. After the number of input data reaches to the||||setting value,||
|||||||||||input data is stored into the SRC.||||||

## 37.3.28 2SRC0_m Event Mask Register p (SEVMRp_2SRC0_m) (m = 0, 1; p = 0, 1)

SEVMRp_2SRC0_m is a 32-bit readable/writable register that enables or disables SCUAIm interrupt requests. The name of the interrupt source corresponding to the interrupt request from SEVMRp_2SRC0_0 is SCUAI0 and that corresponding to the interrupt request from SEVMRp_2SRC0_1 is SCUAI1.

||||Bit:|31|30||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||EVMUF|EVMOF||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-|-||
||||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:|R/W|R/W||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R||
||||Bit:|15|14||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||||-|EVM||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-|-||
||||||WAIT||||||||||||||
||||Initial value:|0|0||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||||R/W:|R|R/W||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R||
||||||**Initial**||||||||||||||
|**Bit**|||**Bit Name**||**Value**||||**R/W**||**Description**||||||||
|31|||EVMUF||0||||R/W||SRC Underflow Mask||||||||
||||||||||||This bit sets whether to|mask the interrupt request from the EVCUF bit in|||||||
||||||||||||the SEVCRp_2SRC0_m register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|30|||EVMOF||0||||R/W||SRC Overflow Mask||||||||
||||||||||||This bit sets whether to|mask the EVCOF bit in the SEVCRp_2SRC0_m|||||||
||||||||||||register.||||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|29|to|15|—||All||0||R||Reserved||||||||
||||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|14|||EVMWAIT||0||||R/W||SRC Wait Time Mask||||||||
||||||||||||This bit sets whether to mask the interrupt request from||||||the EVCWAIT bit||
||||||||||||of SEVCRp_2SRC0_m|register.|||||||
||||||||||||0: Disables interrupts.||||||||
||||||||||||1: Enables interrupts.||||||||
|13|to|0|—||All||0||R||Reserved||||||||
||||||||||||These bits are always read as 0. The write||||value|should always be 0.|||

## 37.3.29 2SRC0_m Event Clear Register p (SEVCRp_2SRC0_m) (m = 0, 1; p = 0, 1)

SEVCRp_2SRC0_m is a 32-bit readable/writable register that clears SCUAIm interrupt requests. When an interrupt event is generated, the relevant bit in this register is automatically set to 1 and 1 is retained until 0 is written to that bit.

||||Bit:|31||30||29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||EVCUF||EVCOF||-|-|-|-|-<br>-<br>-|-|-|-|-|-|-|-||
||||Initial value:|0||0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:|R/(W)*1||R/(W)*1||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
||||Bit:|15||14||13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||||-||EVC||-|-|-|-|-<br>-<br>-|-|-|-|-|-|-|-||
|||||||WAIT|||||||||||||||
||||Initial value:|0||0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||||R/W:|R||R/(W)*1||R|R|R|R|R<br>R<br>R|R|R|R|R|R|R|R||
|||||||**Initial**|||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**|||||||||
|31|||EVCUF|||0||||R/(W)*1||SRC Underflow Clear|||||||||
|||||||||||||This is an interrupt flag to indicate whether|||||INDATA RAM underflow||||
|||||||||||||occurs. When it occurs,||this bit is set to 1.|||||||
|||||||||||||0: Clears the flag.|||||||||
|||||||||||||1: Retains the flag.|||||||||
|30|||EVCOF|||0||||R/(W)*1||SRC Overflow Clear|||||||||
|||||||||||||This is an interrupt flag to indicate whether INDATA RAM overflow occurs.|||||||||
|||||||||||||When it occurs, this bit is set to 1.|||||||||
|||||||||||||0: Clears the flag.|||||||||
|||||||||||||1: Retains the flag.|||||||||
|29|to|15|—|||All||0||R||Reserved|||||||||
|||||||||||||These bits are always read as 0. The write|||||value|should always be 0.|||
|14|||EVCWAIT|||0||||R/(W)*1||SRC Wait Time Clear|||||||||
|||||||||||||This is an interrupt flag to indicate whether|||||SRC has started processing||||
|||||||||||||after the wait time.|||||||||
|||||||||||||0: Clears the flag.|||||||||
|||||||||||||1: Retains the flag.|||||||||
|13|to|0|—|||All||0||R||Reserved|||||||||
|||||||||||||These bits are always read as 0. The write|||||value|should always be 0.|||

Note 1. Readable/writable. When 0 is written, the bit is initialized. Writing 1 to the bit is ignored. Write 0 only to each bit corresponding to the interrupt source to be cleared; write 1 to other bits.

## 37.3.30 2SRC0_m Initialization Register RIF (SRCIRR_2SRC0_m) (m = 0, 1)

SRCIRR_2SRC0_m is a 32-bit readable/writable register that initializes COEF-ROMIF which is mounted on 2SRC0_m.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|INIT|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||INIT|1|R/W|Initialization|
|||||||When this bit is set to 1, the COEF-ROMIF internal circuit is initialized. To|
|||||||cancel the initialization, set this bit to 0 with it set to 1.|
|||||||0: Processing State|
|||||||1: Initialization (sets the initial setting of other registers)|

## 37.3.31 DVU0_n Initialization Register (DVUIR_DVU0_n) (n = 0, 1, 2, 3)

DVUIR_DVU0_n is a 32-bit readable/writable register that initializes the DVU internal circuit.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|INIT|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|1|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||INIT|1|R/W|Initialization|
|||||||When this bit is set to 1, the DVU internal circuit is initialized. To cancel|
|||||||the initialization, set this bit to 0 with it set to 1.|
|||||||0: Processing State|
|||||||1: Initialization (sets the initial setting of other registers)|

## 37.3.32 DVU0_n Audio Information Register (VADIR_DVU0_n) (n = 0, 1, 2, 3)

VADIR_DVU0_n is a 32-bit readable/writable register that sets the bit length of data and the number of channels.

||Bit:|31|30||29|28|27|26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-<br>-|-|-|||OTBL||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R|R|R|R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14||13|12|11|10|9<br>8<br>7|6|5|4|3|2|1|0||
|||-|-||-|-|-|-|-<br>-<br>-|-|-|-||CHNUM||||
||Initial value:|0|0||0|0|0|0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R<br>R|R|R|R|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**|||||||||
|31 to 21|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0. The write|||||value|should|always be 0.||
|20 to 16|OTBL|||All 0|||R/W||Bit Length of Output Audio Data.|||||||||
||||||||||00000: 24 bits|||||||||
||||||||||00001 to 00111: Reserved|||||||||
||||||||||01000: 16 bits|||||||||
||||||||||01001 to 11111: Reserved|||||||||
|15 to 4|—|||All 0|||R||Reserved|||||||||
||||||||||These bits are always read as 0. The write|||||value|should|always be 0.||
|3 to 0|CHNUM|||All 0|||R/W||Number of Channels|||||||||
||||||||||These bits set the number of channels.|||||||||
||||||||||0000: Zero (None)|||||||||
||||||||||0001: 1 channel|||||||||
||||||||||0010: 2 channels|||||||||
||||||||||0011: Reserved|||||||||
||||||||||0100: 4 channels|||||||||
||||||||||0101: Reserved|||||||||
||||||||||0110: 6 channels|||||||||
||||||||||0111: Reserved|||||||||
||||||||||1000: 8 channels|||||||||
||||||||||1001 to 1111: Reserved|||||||||

## 37.3.33 DVU0_n Bypass Register (DVUBR_DVU0_n) (n = 0, 1, 2, 3)

DVUBR_DVU0_n is a 32-bit readable/writable register that sets the bypass mode.

||||Bit:|31|30|||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|BY||
|||||||||||||||||||||PASS||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R/W||
|||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**||||||||||
|31|to|1|—|||All||0||R||Reserved||||||||||
|||||||||||||These bits are always read as 0. The write||||||value|should always be 0.|||
|0|||BYPASS|||0||||R/W||Bypass Mode||||||||||
|||||||||||||This bit controls the data pass of DVU.||||||||||
|||||||||||||0: DVU function is used.||||||||||
|||||||||||||Input data is processed by DVU and then the result data is|||||||||connected|
|||||||||||||to output data.||||||||||
|||||||||||||1: DVU function is not used.||||||||||
|||||||||||||Input data is directly connected to output data.||||||||||

## 37.3.34 DVU0_n Control Register (DVUCR_DVU0_n) (n = 0, 1, 2, 3)

DVUCR_DVU0_n is a 32-bit readable/writable register that selects the DVU mode.

||Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-|-||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R|||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R||
||Bit:|15|14|||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||-|-|||-|-|-|-|-<br>VVMD<br>-<br>-|-|VRMD|-|-|-|ZCMD||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R|||R|R|R|R|R<br>R/W<br>R<br>R|R|R/W|R|R|R|R/W||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**||**Description**||||||||
|31 to 9|—|||All||0||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|8|VVMD|||0||||R/W||Digital Volume Mode Select||||||||
|||||||||||This bit selects the digital volume function.||||||||
|||||||||||0: Disables the digital volume||function.||||||
|||||||||||1: Enables the digital volume function.||||||||
|7 to 5|—|||All||0||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|4|VRMD|||0||||R/W||Volume Ramp Mode Select||||||||
|||||||||||This bit selects the volume ramp function.||||||||
|||||||||||0: Disables the volume ramp function.||||||||
|||||||||||1: Enables the volume ramp function.||||||||
|3 to 1|—|||All||0||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|0|ZCMD|||0||||R/W||Zero Cross Mute Mode|Select|||||||
|||||||||||This bit selects the zero cross||mute function.||||||
|||||||||||0: Disables the zero cross mute function.||||||||
|||||||||||1: Enables the zero cross mute function.||||||||

## 37.3.35 DVU0_n Zero Cross Mute Control Register (ZCMCR_DVU0_n) (n = 0, 1, 2, 3)

ZCMCR_DVU0_n is a 32-bit readable/writable register that controls operation of the zero cross mute function for each channel.

||||Bit:||31|30|||29|28|27|26|25<br>24<br>23|22|21<br>20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|||-|-|-|-|-<br>-<br>-|-|-<br>-<br>-|-|-|-||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0|0|0<br>0<br>0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R|R|R<br>R<br>R|R|R|R||
||||Bit:||15|14|||13|12|11|10|9<br>8<br>7|6|5<br>4<br>3|2|1|0||
||||||-|-|||-|-|-|-|-<br>-<br>ZCEN7|ZCEN6|ZCEN5 ZCEN4 ZCEN3|ZCEN2|ZCEN1|ZCEN0||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0|0|0<br>0<br>0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R/W|R/W|R/W<br>R/W<br>R/W|R/W|R/W|R/W||
||||||||**Initial**|||||||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**|||||||
|31|to|8|—||||All||0||R||Reserved|||||||
||||||||||||||These bits are always read as 0. The write|||value should always be 0.||||
|7|||ZCEN7||||0||||R/W||Zero Cross Mute Enable for Channel 7|||||||
||||||||||||||This bit controls the operation of the zero cross mute function for channel|||||||
||||||||||||||7.|||||||
||||||||||||||0: Disables the operation of the zero cross|||mute function.||||
||||||||||||||1: Enables the operation the zero cross mute function.|||||||
|6|||ZCEN6||||0||||R/W||Zero Cross Mute Enable for Channel 6|||||||
||||||||||||||This bit controls the operation of the zero cross mute function for channel|||||||
||||||||||||||6.|||||||
||||||||||||||0: Disables the operation of the zero cross|||mute function.||||
||||||||||||||1: Enables the operation the zero cross mute function.|||||||
|5|||ZCEN5||||0||||R/W||Zero Cross Mute Enable for Channel 5|||||||
||||||||||||||This bit controls the operation of the zero cross mute function for channel|||||||
||||||||||||||5.|||||||
||||||||||||||0: Disables the operation of the zero cross|||mute function.||||
||||||||||||||1: Enables the operation the zero cross mute function.|||||||
|4|||ZCEN4||||0||||R/W||Zero Cross Mute Enable for Channel 4|||||||
||||||||||||||This bit controls the operation of the zero cross mute function for channel|||||||
||||||||||||||4.|||||||
||||||||||||||0: Disables the operation of the zero cross|||mute function.||||
||||||||||||||1: Enables the operation the zero cross mute function.|||||||
|3|||ZCEN3||||0||||R/W||Zero Cross Mute Enable for Channel 3|||||||
||||||||||||||This bit controls the operation of the zero cross mute function for channel|||||||
||||||||||||||3.|||||||
||||||||||||||0: Disables the operation of the zero cross|||mute function.||||
||||||||||||||1: Enables the operation the zero cross mute function.|||||||
|2|||ZCEN2||||0||||R/W||Zero Cross Mute Enable for Channel 2|||||||
||||||||||||||This bit controls the operation of the zero cross mute function for channel|||||||
||||||||||||||2.|||||||
||||||||||||||0: Disables the operation of the zero cross|||mute function.||||
||||||||||||||1: Enables the operation the zero cross mute function.|||||||
|1|||ZCEN1||||0||||R/W||Zero Cross Mute Enable for Channel 1|||||||
||||||||||||||This bit controls the operation of the zero cross mute function for channel|||||||
||||||||||||||1.|||||||
||||||||||||||0: Disables the operation of the zero cross|||mute function.||||
||||||||||||||1: Enables the operation the zero cross mute function.|||||||
|0|||ZCEN0||||0||||R/W||Zero Cross Mute Enable for Channel 0|||||||
||||||||||||||This bit controls the operation of the zero cross mute function for channel|||||||
||||||||||||||0.|||||||
||||||||||||||0: Disables the operation of the zero cross|||mute function.||||
||||||||||||||1: Enables the operation the zero cross mute function.|||||||

## 37.3.36 DVU0_n Volume Ramp Control Register (VRCTR_DVU0_n) (n = 0, 1, 2, 3)

VRCTR_DVU0_n is a 32-bit readable/writable register that controls operation of the volume ramp function.

||||Bit:||31|30|||29|28|27|26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|||-|-|-|-|-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-|-||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R|R||
||||Bit:||15|14|||13|12|11|10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1|0||
||||||-|-|||-|-|-|-|-<br>-<br>VREN7<br>VREN6 VREN5 VREN4 VREN3 VREN2 VREN1|VREN0||
||||Initial value:||0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0||
||||R/W:||R|R|||R|R|R|R|R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W||
||||||||**Initial**|||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**|||
|31|to|8|—||||All||0||R||Reserved|||
||||||||||||||These bits are always read as 0. The write value should always be 0.|||
|7|||VREN7||||0||||R/W||Volume Ramp Enable for Channel 7|||
||||||||||||||This bit controls the operation of the volume ramp function for||channel 7.|
||||||||||||||0: Disables the operation of the volume ramp function.|||
||||||||||||||1: Enables the operation of the volume ramp function.|||
|6|||VREN6||||0||||R/W||Volume Ramp Enable for Channel 6|||
||||||||||||||This bit controls the operation of the volume ramp function for||channel 6.|
||||||||||||||0: Disables the operation of the volume ramp function.|||
||||||||||||||1: Enables the operation of the volume ramp function.|||
|5|||VREN5||||0||||R/W||Volume Ramp Enable for Channel 5|||
||||||||||||||This bit controls the operation of the volume ramp function for||channel 5.|
||||||||||||||0: Disables the operation of the volume ramp function.|||
||||||||||||||1: Enables the operation of the volume ramp function.|||
|4|||VREN4||||0||||R/W||Volume Ramp Enable for Channel 4|||
||||||||||||||This bit controls the operation of the volume ramp function for||channel 4.|
||||||||||||||0: Disables the operation of the volume ramp function.|||
||||||||||||||1: Enables the operation of the volume ramp function.|||
|3|||VREN3||||0||||R/W||Volume Ramp Enable for Channel 3|||
||||||||||||||This bit controls the operation of the volume ramp function for||channel 3.|
||||||||||||||0: Disables the operation of the volume ramp function.|||
||||||||||||||1: Enables the operation of the volume ramp function.|||
|2|||VREN2||||0||||R/W||Volume Ramp Enable for Channel 2|||
||||||||||||||This bit controls the operation of the volume ramp function for||channel 2.|
||||||||||||||0: Disables the operation of the volume ramp function.|||
||||||||||||||1: Enables the operation of the volume ramp function.|||
|1|||VREN1||||0||||R/W||Volume Ramp Enable for Channel 1|||
||||||||||||||This bit controls the operation of the volume ramp function for||channel 1.|
||||||||||||||0: Disables the operation of the volume ramp function.|||
||||||||||||||1: Enables the operation of the volume ramp function.|||
|0|||VREN0||||0||||R/W||Volume Ramp Enable for Channel 0|||
||||||||||||||This bit controls the operation of the volume ramp function for||channel 0.|
||||||||||||||0: Disables the operation of the volume ramp function.|||
||||||||||||||1: Enables the operation of the volume ramp function.|||

## 37.3.37 DVU0_n Volume Ramp Period Register (VRPDR_DVU0_n) (n = 0, 1, 2, 3)

VRPDR_DVU0_n is a 32-bit readable/writable register that sets the ramp time of volume ramp.

||Bit:|31|30||29|28|27||26|25<br>24<br>23<br>22<br>21<br>20<br>19||18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-||-|-<br>-<br>-<br>-<br>-<br>-<br>-||-|-|-||
||Initial value:|0|0||0|0|0||0|0<br>0<br>0<br>0<br>0<br>0<br>0||0|0|0||
||R/W:|R|R||R|R|R||R|R<br>R<br>R<br>R<br>R<br>R<br>R||R|R|R||
||Bit:|15|14||13|12|11||10|9<br>8<br>7<br>6<br>5<br>4<br>3||2|1|0||
|||-|-||-|||VRPDUP<br>-<br>-<br>-|||VRPDDW|||||
||Initial value:|0|0||0|0|0||0|0<br>0<br>0<br>0<br>0<br>0<br>0||0|0|0||
||R/W:|R|R||R|R/W|R/W||R/W|R/W<br>R/W<br>R<br>R<br>R<br>R/W<br>R/W||R/W|R/W|R/W||
|||||**Initial**||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**||||||
|31 to 13|—|||All 0|||R|||Reserved||||||
|||||||||||These bits are always read as 0. The write||value|should always be 0.|||
|12 to 8|VRPDUP|||All 0|||R/W|||Volume Ramp Period for Volume Up||||||
|||||||||||00000:              1 [sample] (128 dB/1 step)||||||
|||||||||||00001:              2 [sample] (64 dB/1 step)||||||
|||||||||||00010:              4 [sample] (32 dB/1 step)||||||
|||||||||||00011:              8 [sample] (16 dB/1 step)||||||
|||||||||||00100:            16 [sample] (8 dB/1 step)||||||
|||||||||||00101:            32 [sample] (4 dB/1 step)||||||
|||||||||||00110:            64 [sample] (2 dB/1 step)||||||
|||||||||||00111:          128 [sample] (1 dB/1 step)||||||
|||||||||||01000:          256 [sample] (0.5 dB/1 step)||||||
|||||||||||01001:          512 [sample] (0.25 dB/1 step)||||||
|||||||||||01010:        1024 [sample] (0.125 dB/1 step)||||||
|||||||||||01011:        2048 [sample] (0.125 dB/2 steps)||||||
|||||||||||01100:        4096 [sample] (0.125 dB/4 steps)||||||
|||||||||||01101:        8192 [sample] (0.125 dB/8 steps)||||||
|||||||||||01110:      16384 [sample] (0.125 dB/16 steps)||||||
|||||||||||01111:      32768 [sample] (0.125 dB/32 steps)||||||
|||||||||||10000:      65536 [sample] (0.125 dB/64 steps)||||||
|||||||||||10001:    131072 [sample] (0.125 dB/128 steps)||||||
|||||||||||10010:    262144 [sample] (0.125 dB/256 steps)||||||
|||||||||||10011:    524288 [sample] (0.125 dB/512 steps)||||||
|||||||||||10100:  1048576 [sample] (0.125 dB/1024||steps)||||
|||||||||||10101:  2097152 [sample] (0.125 dB/2048||steps)||||
|||||||||||10110:  4194304 [sample] (0.125 dB/4096|steps)|||||
|||||||||||10111:  8388608 [sample] (0.125 dB/8192|steps)|||||
|||||||||||11000 to 11111: Reserved||||||
|7 to 5|—|||All 0|||R|||Reserved||||||
|||||||||||These bits are always read as 0. The write||value|should always be 0.|||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|4 to 0|VRPDDW|0|R/W|Volume Ramp Period for Volume Down|
|||||00000:              1 [sample] (-128 dB/1 step)|
|||||00001:              2 [sample] (-64 dB/1 step)|
|||||00010:              4 [sample] (-32 dB/1 step)|
|||||00011:              8 [sample] (-16 dB/1 step)|
|||||00100:            16 [sample] (-8 dB/1 step)|
|||||00101:            32 [sample] (-4 dB/1 step)|
|||||00110:            64 [sample] (-2 dB/1 step)|
|||||00111:          128 [sample] (-1 dB/1 step)|
|||||01000:          256 [sample] (-0.5 dB/1 step)|
|||||01001:          512 [sample] (-0.25 dB/1 step)|
|||||01010:        1024 [sample] (-0.125 dB/1 step)|
|||||01011:        2048 [sample] (-0.125 dB/2 steps)|
|||||01100:        4096 [sample] (-0.125 dB/4 steps)|
|||||01101:        8192 [sample] (-0.125 dB/8 steps)|
|||||01110:      16384 [sample] (-0.125 dB/16 steps)|
|||||01111:      32768 [sample] (-0.125 dB/32 steps)|
|||||10000:      65536 [sample] (-0.125 dB/64 steps)|
|||||10001:    131072 [sample] (-0.125 dB/128 steps)|
|||||10010:    262144 [sample] (-0.125 dB/256 steps)|
|||||10011:    524288 [sample] (-0.125 dB/512 steps)|
|||||10100:  1048576 [sample] (-0.125 dB/1024 steps)|
|||||10101:  2097152 [sample] (-0.125 dB/2048 steps)|
|||||10110:  4194304 [sample] (-0.125 dB/4096 steps)|
|||||10111:  8388608 [sample] (-0.125 dB/8192 steps)|
|||||11000 to 11111: Reserved|

## 37.3.38 DVU0_n Volume Ramp Decibel Register (VRDBR_DVU0_n) (n = 0, 1, 2, 3)

VRDBR_DVU0_n is a 32-bit readable/writable register that sets the gain level (decibel units) of volume ramp.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>VRDB|
|---|---|
|31 to 10<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|9 to 0<br>VRDB<br>All 0<br>R/W|Decibel of Volume Ramp<br>These bits set the decibel (gain level) of volume ramp. The value can be<br>selected from 1024 points in the range of f0 dB to -∞ dB at intervals of<br>0.125 dB.<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x000<br>1<br>0<br>......<br>......<br>......<br>......<br>......<br>......<br>0x091<br>0.125<br>-18.125<br>0x031<br>0.5<br>-6.125<br>......<br>......<br>......<br>......<br>......<br>......<br>0x3FE<br>4.1x10-7<br>-127.75<br>0x061<br>0.25<br>-12.125<br>0x3FF<br>0 (Mute)<br>-∞|

## 37.3.39 DVU0_n Volume Ramp Wait Time Register (VRWTR_DVU0_n) (n = 0, 1, 2, 3)

VRWTR_DVU0_n is a 32-bit readable/writable register that sets the wait time before executing the volume ramp function.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-||||VRWT|||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|||||||||VRWT|||||||||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|24|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|23|to|0|VRWT|All 0|R/W|Volume Ramp Wait Time|
|||||||These bits set the wait time before starting the volume ramp function|
|||||||when the setting of VRDBR register is changed. If the internal counter of|
|||||||the DVU logic reached to the value of these bits, the volume ramp|
|||||||function starts operating to change the volume to the value changed in|
|||||||the VRDBR register as a target.|

## 37.3.40 DVU0_n Volume Value Setting 0 Register (VOL0R_DVU0_n) (n = 0, 1, 2, 3)

VOL0R_DVU0_n is a 32-bit readable/writable register that sets the digital volume value of channel 0.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>VOLVAL0<br>VOLVAL0|
|---|---|
|31 to 24<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|23 to 0<br>VOLVAL0<br>All 0<br>R/W|Digital Volume Value for Channel 0<br>These bits set the digital volume of channel 0. The maximum value is<br>octupled gain (18 dB) and the minimum value is 0 (-∞ dB).<br>VOLVAL0[23]      : Sign bit<br>VOLVAL0[22:20] : Integer bits<br>VOLVAL0[19:0]   : Decimal bits<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x7F_FFFF<br>8<br>18<br>0x08_0000<br>0.5<br>-6<br>...<br>...<br>...<br>...<br>...<br>...<br>0x10_0000<br>1<br>0<br>0x00_0001<br>9.5x10-7<br>-120<br>...<br>...<br>...<br>0x00_0000<br>0<br>-∞|

## 37.3.41 DVU0_n Volume Value Setting 1 Register (VOL1R_DVU0_n) (n = 0, 1, 2, 3)

VOL1R_DVU0_n is a 32-bit readable/writable register that sets the digital volume value of channel 1.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>VOLVAL1<br>VOLVAL1|
|---|---|
|31 to 24<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|23 to 0<br>VOLVAL1<br>All 0<br>R/W|Digital Volume Value for Channel 1<br>These bits set the digital volume of channel 1. The maximum value is<br>octupled gain (18 dB) and the minimum value is 0 (-∞ dB).<br>VOLVAL1[23]    : Sign bit<br>VOLVAL1[22:20] : Integer bits<br>VOLVAL1[19:0]  : Decimal bits<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x7F_FFFF<br>8<br>18<br>0x08_0000<br>0.5<br>-6<br>...<br>...<br>...<br>...<br>...<br>...<br>0x10_0000<br>1<br>0<br>0x00_0001<br>9.5x10-7<br>-120<br>...<br>...<br>...<br>0x00_0000<br>0<br>-∞|

## 37.3.42 DVU0_n Volume Value Setting 2 Register (VOL2R_DVU0_n) (n = 0, 1, 2, 3)

VOL2R_DVU0_n is a 32-bit readable/writable register that sets the digital volume value of channel 2.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br><br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>VOLVAL2<br>VOLVAL2|
|---|---|
|31 to 24<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|23 to 0<br>VOLVAL2<br>All 0<br>R/W|Digital Volume Value for Channel 2<br>These bits set the digital volume of channel 2. The maximum value is<br>octupled gain (18 dB) and the minimum value is 0 (-∞ dB).<br>VOLVAL2[23]      : Sign bit<br>VOLVAL2[22:20] : Integer bits<br>VOLVAL2[19:0]   : Decimal bits<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x7F_FFFF<br>8<br>18<br>0x08_0000<br>0.5<br>-6<br>...<br>...<br>...<br>...<br>...<br>...<br>0x10_0000<br>1<br>0<br>0x00_0001<br>9.5x10-7<br>-120<br>...<br>...<br>...<br>0x00_0000<br>0<br>-∞|

## 37.3.43 DVU0_n Volume Value Setting 3 Register (VOL3R_DVU0_n) (n = 0, 1, 2, 3)

VOL3R_DVU0_n is a 32-bit readable/writable register that sets the digital volume value of channel 3.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>VOLVAL3<br>VOLVAL3|
|---|---|
|31 to 24<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|23 to 0<br>VOLVAL3<br>All 0<br>R/W|Digital Volume Value for Channel 3<br>These bits set the digital volume of channel 3. The maximum value is<br>octupled gain (18 dB) and the minimum value is 0 (-∞ dB).<br>VOLVAL3[23]      : Sign bit<br>VOLVAL3[22:20] : Integer bits<br>VOLVAL3[19:0]   : Decimal bits<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x7F_FFFF<br>8<br>18<br>0x08_0000<br>0.5<br>-6<br>...<br>...<br>...<br>...<br>...<br>...<br>0x10_0000<br>1<br>0<br>0x00_0001<br>9.5x10-7<br>-120<br>...<br>...<br>...<br>0x00_0000<br>0<br>-∞|

## 37.3.44 DVU0_n Volume Value Setting 4 Register (VOL4R_DVU0_n) (n = 0, 1, 2, 3)

VOL4R_DVU0_n is a 32-bit readable/writable register that sets the digital volume value of channel 4.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>VOLVAL4<br>VOLVAL4|
|---|---|
|31 to 24<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|23 to 0<br>VOLVAL4<br>All 0<br>R/W|Digital Volume Value for Channel 4<br>These bits set the digital volume of channel 4. The maximum value is<br>octupled gain (18 dB) and the minimum value is 0 (-∞ dB).<br>VOLVAL4[23]      : Sign bit<br>VOLVAL4[22:20] : Integer bits<br>VOLVAL4[19:0]   : Decimal bits<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x7F_FFFF<br>8<br>18<br>0x08_0000<br>0.5<br>-6<br>...<br>...<br>...<br>...<br>...<br>...<br>0x10_0000<br>1<br>0<br>0x00_0001<br>9.5x10-7<br>-120<br>...<br>...<br>...<br>0x00_0000<br>0<br>-∞|

## 37.3.45 DVU0_n Volume Value Setting 5 Register (VOL5R_DVU0_n) (n = 0, 1, 2, 3)

VOL5R_DVU0_n is a 32-bit readable/writable register that sets the digital volume value of channel 5.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>VOLVAL5<br>VOLVAL5|
|---|---|
|31 to 24<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|23 to 0<br>VOLVAL5<br>All 0<br>R/W|Digital Volume Value for Channel 5<br>These bits set the digital volume of channel 5. The maximum value is<br>octupled gain (18 dB) and the minimum value is 0 (-∞ dB).<br>VOLVAL5[23]      : Sign bit<br>VOLVAL5[22:20] : Integer bits<br>VOLVAL5[19:0]   : Decimal bits<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x7F_FFFF<br>8<br>18<br>0x08_0000<br>0.5<br>-6<br>...<br>...<br>...<br>...<br>...<br>...<br>0x10_0000<br>1<br>0<br>0x00_0001<br>9.5x10-7<br>-120<br>...<br>...<br>...<br>0x00_0000<br>0<br>-∞|

## 37.3.46 DVU0_n Volume Value Setting 6 Register (VOL6R_DVU0_n) (n = 0, 1, 2, 3)

VOL6R_DVU0_n is a 32-bit readable/writable register that sets the digital volume value of channel 6.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>VOLVAL6<br>VOLVAL6|
|---|---|
|31 to 24<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|23 to 0<br>VOLVAL6<br>All 0<br>R/W|Digital Volume Value for Channel 6<br>These bits set the digital volume of channel 6. The maximum value is<br>octupled gain (18 dB) and the minimum value is 0 (-∞ dB).<br>VOLVAL6[23]      : Sign bit<br>VOLVAL6[22:20] : Integer bits<br>VOLVAL6[19:0]   : Decimal bits<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x7F_FFFF<br>8<br>18<br>0x08_0000<br>0.5<br>-6<br>...<br>...<br>...<br>...<br>...<br>...<br>0x10_0000<br>1<br>0<br>0x00_0001<br>9.5x10-7<br>-120<br>...<br>...<br>...<br>0x00_0000<br>0<br>-∞|

## 37.3.47 DVU0_n Volume Value Setting 7 Register (VOL7R_DVU0_n) (n = 0, 1, 2, 3)

VOL7R_DVU0_n is a 32-bit readable/writable register that sets the digital volume value of channel 7.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>VOLVAL7<br>VOLVAL7|
|---|---|
|31 to 24<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|23 to 0<br>VOLVAL7<br>All 0<br>R/W|Digital Volume Value for Channel7<br>These bits set the digital volume of channel 7. The maximum value is<br>octupled gain (18 dB) and the minimum value is 0 (-∞ dB).<br>VOLVAL7[23]      : Sign bit<br>VOLVAL7[22:20] : Integer bits<br>VOLVAL7[19:0]   : Decimal bits<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x7F_FFFF<br>8<br>18<br>0x08_0000<br>0.5<br>-6<br>...<br>...<br>...<br>...<br>...<br>...<br>0x10_0000<br>1<br>0<br>0x00_0001<br>9.5x10-7<br>-120<br>...<br>...<br>...<br>0x00_0000<br>0<br>-∞|

## 37.3.48 DVU0_n Enable Register (DVUER_DVU0_n) (n = 0, 1, 2, 3)

DVUER_DVU0_n is a 32-bit readable/writable register that enables or disables the DVU register settings.

||||Bit:|31|30|||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|-||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:|15|14|||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||||-|-|||-|-|-|-|-<br>-|-|-|-|-|-|-|-|DVUEN||
||||Initial value:|0|0|||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R|||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R/W||
|||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**||||**R/W**||**Description**||||||||||
|31|to|1|—|||All||0||R||Reserved||||||||||
|||||||||||||These bits are always read as 0. The write||||||value|should always be 0.|||
|0|||DVUEN|||0||||R/W||DVU Register Setting Enable||||||||||
|||||||||||||This bit controls the setting of||||DVU registers (ZCMCR, VRCTR, VRPDR,||||||
|||||||||||||VRDBR, VOL0R,||VOL1R, VOL2R, VOL3R, VOL4R, VOL5R, VOL6R,||||||||
|||||||||||||and VOL7R).||||||||||
|||||||||||||0: Disables the setting of DVU registers.||||||||||
|||||||||||||1: Enables|the setting of DVU|||registers.||||||

## 37.3.49 DVU0_n Status Register (DVUSR_DVU0_n) (n = 0, 1, 2, 3)

DVUSR_DVU0_n is a 32-bit read-only register that indicates the status of zero cross mute and volume ramp.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|ZSTS7|ZSTS6|ZSTS5|ZSTS4|ZSTS3|ZSTS2|ZSTS1|ZSTS0|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|-|-|-|-|-||VRSTS||
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|31 to 24|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|23|ZSTS7|0|R|Zero Cross Mute Status of Channel 7|
|||||This bit indicates the zero cross mute status of channel 7.|
|||||0: Not in mute status|
|||||1: Mute status|
|22|ZSTS6|0|R|Zero Cross Mute Status of Channel 6|
|||||This bit indicates the zero cross mute status of channel 6.|
|||||0: Not in mute status|
|||||1: Mute status|
|21|ZSTS5|0|R|Zero Cross Mute Status of Channel 5|
|||||This bit indicates the zero cross mute status of channel 5.|
|||||0: Not in mute status|
|||||1: Mute status|
|20|ZSTS4|0|R|Zero Cross Mute Status of Channel 4|
|||||This bit indicates the zero cross mute status of channel 4.|
|||||0: Not in mute status|
|||||1: Mute status|
|19|ZSTS3|0|R|Zero Cross Mute Status of Channel 3|
|||||This bit indicates the zero cross mute status of channel 3.|
|||||0: Not in mute status|
|||||1: Mute status|
|18|ZSTS2|0|R|Zero Cross Mute Status of Channel 2|
|||||This bit indicates the zero cross mute status of channel 2.|
|||||0: Not in mute status|
|||||1: Mute status|
|17|ZSTS1|0|R|Zero Cross Mute Status of Channel 1|
|||||This bit indicates the zero cross mute status of channel 1.|
|||||0: Not in mute status|
|||||1: Mute status|
|16|ZSTS0|0|R|Zero Cross Mute Status of Channel 0|
|||||This bit indicates the zero cross mute status of channel 0.|
|||||0: Not in mute status|
|||||1: Mute status|
|15 to 3|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|2 to 0|VRSTS|All 0|R|Volume Ramp Status|
|||||These bits indicate the volume ramp status.|
|||||000: Mute status|
|||||001: Volume ramp down|
|||||010: Volume ramp up|
|||||011: Level of volume ramp is in the state of the value of VRDBR register|
|||||100: Volume of input data is maintained (Volume is not multiplied).|
|||||101 to 111: Reserved|

## 37.3.50 DVU0_n Event Mask Register (VEVMR_DVU0_n) (n = 0, 1, 2, 3)

VEVMR_DVU0_n is a 32-bit readable/writable register that enables or disables SCUDVIn interrupt requests.

||||Bit:|31||30|29|28|27|26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||VEVM||VEVM|VEVM|VEVM|VEVM|VEVM|VEVM<br>VEVM||||||
|||||ZCM7||ZCM6|ZCM5|ZCM4|ZCM3|ZCM2|ZCM1<br>ZCM0<br>-<br>-<br>-<br>-|-|-|-|-||
||||Initial value:|0||0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||||R/W:|R/(W)*1R/(W)*1R/(W)*1R/(W)*1R/(W)*1||||||R/(W)*1|R/(W)*1 R/(W)*1<br>R<br>R<br>R<br>R|R|R|R|R||
||||Bit:|15||14|13|12|11|10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|||||VEV||-|-|-|-|-|-<br>-<br>-<br>-<br>-<br>-|-|-|-|-||
|||||MVR|||||||||||||
||||Initial value:|0||0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||||R/W:|R/(W)*1||R|R|R|R|R|R<br>R<br>R<br>R<br>R<br>R|R|R|R|R||
|||||||**Initial**|||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**||**Description**||||||
|31|||VEVMZCM7|||0|||R/W||Zero Cross Mute Status Change Mask of Channel 7||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCZCM7||||
||||||||||||bit in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||
|30|||VEVMZCM6|||0|||R/W||Zero Cross Mute Status Change Mask of Channel 6||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCZCM6||||
||||||||||||bit in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||
|29|||VEVMZCM5|||0|||R/W||Zero Cross Mute Status Change Mask of Channel 5||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCZCM5||||
||||||||||||bit in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||
|28|||VEVMZCM4|||0|||R/W||Zero Cross Mute Status Change Mask of Channel 4||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCZCM4||||
||||||||||||bit in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||
|27|||VEVMZCM3|||0|||R/W||Zero Cross Mute Status Change Mask of Channel 3||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCZCM3||||
||||||||||||bit in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||
|26|||VEVMZCM2|||0|||R/W||Zero Cross Mute Status Change Mask of Channel 2||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCZCM2||||
||||||||||||bit in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||
|25|||VEVMZCM1|||0|||R/W||Zero Cross Mute Status Change Mask of Channel 1||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCZCM1||||
||||||||||||bit in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||
|24|||VEVMZCM0|||0|||R/W||Zero Cross Mute Status Change Mask of Channel 0||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCZCM0||||
||||||||||||bit in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||
|23|to|16|—|||All 0|||R||Reserved||||||
||||||||||||These bits are always read as 0. The write||value|should always be 0.|||
|15|||VEVMVR|||0|||R/W||Volume Ramp Status Change||||||
||||||||||||This bit sets whether to mask the interrupt||request from the VEVCVR bit||||
||||||||||||in the VEVCR_DVU0_n register.||||||
||||||||||||0: Disables interrupts.||||||
||||||||||||1: Enables interrupts.||||||

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|14|to|0|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

## 37.3.51 DVU0_n Event Clear Register (VEVCR_DVU0_n) (n = 0, 1, 2, 3)

VEVCR_DVU0_n is a 32-bit readable/writable register that clears SCUDVIn interrupt requests. When an interrupt event is generated, the relevant bit in this register is automatically set to 1 and 1 is retained until 0 is written to that bit.

||||Bit:|31||30|29|28|27|26|25<br>24<br>23||22<br>21<br>20<br>19<br>18<br>17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||VEVC||VEVC|VEVC|VEVC|VEVC|VEVC|VEVC<br>VEVC|||||
|||||ZCM7||ZCM6|ZCM5|ZCM4|ZCM3|ZCM2|ZCM1<br>ZCM0<br>-||-<br>-<br>-<br>-<br>-<br>-|-||
||||Initial value:|0||0|0|0|0|0|0<br>0<br>0||0<br>0<br>0<br>0<br>0<br>0|0||
||||R/W:|R/(W)*1||R/(W)*1R/(W)*1R/(W)*1R/(W)*1R/(W)*1|||||R/(W)*1R/(W)*1<br>R||R<br>R<br>R<br>R<br>R<br>R|R||
||||Bit:|15||14|13|12|11|10|9<br>8<br>7||6<br>5<br>4<br>3<br>2<br>1|0||
|||||VEV||-|-|-|-|-|-<br>-<br>-||-<br>-<br>-<br>-<br>-<br>-|-||
|||||CVR||||||||||||
||||Initial value:|0||0|0|0|0|0|0<br>0<br>0||0<br>0<br>0<br>0<br>0<br>0|0||
||||R/W:|R/(W)*1||R|R|R|R|R|R<br>R<br>R||R<br>R<br>R<br>R<br>R<br>R|R||
|||||||**Initial**||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**||**Description**|||||
|31|||VEVCZCM7|||0|||R/(W)*1||Zero Cross Mute Status Change Clear of Channel 7|||||
||||||||||||This is an interrupt||flag to indicate whether the zero cross mute status|||
||||||||||||change of channel||7 occurs. When it occurs, this bit is set to 1.|||
||||||||||||0: Clears the flag.|||||
||||||||||||1: Retains the flag.|||||
|30|||VEVCZCM6|||0|||R/(W)*1||Zero Cross Mute Status Change Clear of Channel 6|||||
||||||||||||This is an interrupt||flag to indicate whether the zero cross mute status|||
||||||||||||change of channel||6 occurs. When it occurs, this bit is set to 1.|||
||||||||||||0: Clears the flag.|||||
||||||||||||1: Retains the flag.|||||
|29|||VEVCZCM5|||0|||R/(W)*1||Zero Cross Mute Status Change Clear of Channel 5|||||
||||||||||||This is an interrupt||flag to indicate whether the zero cross mute status|||
||||||||||||change of channel||5 occurs. When it occurs, this bit is set to 1.|||
||||||||||||0: Clears the flag.|||||
||||||||||||1: Retains the flag.|||||
|28|||VEVCZCM4|||0|||R/(W)*1||Zero Cross Mute Status Change Clear of Channel 4|||||
||||||||||||This is an interrupt||flag to indicate whether the zero cross mute status|||
||||||||||||change of channel||4 occurs. When it occurs, this bit is set to 1.|||
||||||||||||0: Clears the flag.|||||
||||||||||||1: Retains the flag.|||||
|27|||VEVCZCM3|||0|||R/(W)*1||Zero Cross Mute Status Change Clear of Channel 3|||||
||||||||||||This is an interrupt||flag to indicate whether the zero cross mute status|||
||||||||||||change of channel||3 occurs. When it occurs, this bit is set to 1.|||
||||||||||||0: Clears the flag.|||||
||||||||||||1: Retains the flag.|||||
|26|||VEVCZCM2|||0|||R/(W)*1||Zero Cross Mute Status Change Clear of Channel 2|||||
||||||||||||This is an interrupt||flag to indicate whether the zero cross mute status|||
||||||||||||change of channel||2 occurs. When it occurs, this bit is set to 1.|||
||||||||||||0: Clears the flag.|||||
||||||||||||1: Retains the flag.|||||
|25|||VEVCZCM1|||0|||R/(W)*1||Zero Cross Mute Status Change Clear of Channel 1|||||
||||||||||||This is an interrupt||flag to indicate whether the zero cross mute status|||
||||||||||||change of channel||1 occurs. When it occurs, this bit is set to 1.|||
||||||||||||0: Clears the flag.|||||
||||||||||||1: Retains the flag.|||||
|24|||VEVCZCM0|||0|||R/(W)*1||Zero Cross Mute Status Change Clear of Channel 0|||||
||||||||||||This is an interrupt||flag to indicate whether the zero cross mute status|||
||||||||||||change of channel||0 occurs. When it occurs, this bit is set to 1.|||
||||||||||||0: Clears the flag.|||||
||||||||||||1: Retains the flag.|||||
|23|to|16|—|||All 0|||R||Reserved|||||
||||||||||||These bits are always read as 0. The write value should always be 0.|||||

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|15|||VEVCVR|0|R/(W)*1|Volume Ramp Status Change Clear|
|||||||This is an interrupt flag to judge volume ramp mute occurs or not. When it|
|||||||occurs, this bit is set to 1.|
|||||||0: Clears the flag.|
|||||||1: Retains the flag.|
|14|to|0|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|

Note 1. Readable/writable. When 0 is written, the bit is initialized. Writing 1 to the bit is ignored. Write 0 only to each bit corresponding to the interrupt source to be cleared; write 1 to other bits.

## 37.3.52 MIX0_0 Initialization Register (MIXIR_MIX0_0)

MIXIR_MIX0_0 is a 32-bit readable/writable register that initializes the MIX internal circuit.

||||Bit:||31|30|||29|28|27|26|25|24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||-|-|||-|-|-|-|-|-|-|-|-|-|-|-|-|-||
||||Initial value:||0|0|||0|0|0|0|0|0|0|0|0|0|0|0|0|0||
||||R/W:||R|R|||R|R|R|R|R|R|R|R|R|R|R|R|R|R||
||||Bit:||15|14|||13|12|11|10|9|8|7|6|5|4|3|2|1|0||
||||||-|-|||-|-|-|-|-|-|-|-|-|-|-|-|-|INIT||
||||Initial value:||0|0|||0|0|0|0|0|0|0|0|0|0|0|0|0|1||
||||R/W:||R|R|||R|R|R|R|R|R|R|R|R|R|R|R|R|R/W||
||||||||**Initial**|||||||||||||||||
|**Bit**|||**Bit Name**||||**Value**||||**R/W**||**Description**|||||||||||
|31|to|1|—||||All||0||R||Reserved|||||||||||
||||||||||||||These bits are always read as|||||0. The write||value should always be 0.||||
|0|||INIT||||1||||R/W||Initialization|||||||||||
||||||||||||||When this bit is set to 1,||||the MIX internal circuit is initialized. To cancel the|||||||
||||||||||||||initialization, set this bit to 0 with it set to 1.|||||||||||
||||||||||||||0: Processing State|||||||||||
||||||||||||||1: Initialization (sets the||||initial setting of other registers)|||||||

## 37.3.53 MIX0_0 Audio Information Register (MADIR_MIX0_0)

MADIR_MIX0_0 is a 32-bit readable/writable register that sets the number of channels.

||Bit:|31|30||29|28|27||26|25<br>24<br>23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-||-|-<br>-<br>-|-|-|-|-|-|-|-||
||Initial value:|0|0||0|0|0||0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R||R|R<br>R<br>R|R|R|R|R|R|R|R||
||Bit:|15|14||13|12|11||10|9<br>8<br>7|6|5|4|3|2|1|0||
|||-|-||-|-|-||-|-<br>-<br>-|-|-|-||CHNUM||||
||Initial value:|0|0||0|0|0||0|0<br>0<br>0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R||R|R<br>R<br>R|R|R|R|R/W|R/W|R/W|R/W||
|||||**Initial**|||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**|||||||||
|31 to 4|—|||All 0|||R|||Reserved|||||||||
|||||||||||These bits are always read as 0. The write value||||||should always be 0.|||
|3 to 0|CHNUM|||All 0|||R/W|||Number of Channels|||||||||
|||||||||||These bits set the number of channels.|||||||||
|||||||||||0000: Zero (None)|||||||||
|||||||||||0001: 1 channel|||||||||
|||||||||||0010: 2 channels|||||||||
|||||||||||0011: Reserved|||||||||
|||||||||||0100: 4 channels|||||||||
|||||||||||0101: Reserved|||||||||
|||||||||||0110: 6 channels|||||||||
|||||||||||0111: Reserved|||||||||
|||||||||||1000: 8 channels|||||||||
|||||||||||1001 to 1111: Reserved|||||||||

## 37.3.54 MIX0_0 Bypass Register (MIXBR_MIX0_0)

MIXBR_MIX0_0 is a 32-bit readable/writable register that sets the bypass mode.

||Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|BPSYS|||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R|||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R/W|R/W||
||Bit:|15|14|||13|12|11|10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||-|-|||-|-|-|-|-<br>-<br>-<br>-|-|-|-|-|-|BY||
|||||||||||||||||PASS||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R|||R|R|R|R|R<br>R<br>R<br>R|R|R|R|R|R|R/W||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**||**Description**||||||||
|31 to 18|—|||All||0||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|17, 16|BPSYS|||All||0||R/W||Bypass System Select||||||||
|||||||||||This bit selects the input data output|||from the MIX module when the|||||
|||||||||||BYPASS bit is set to 1.||||||||
|||||||||||00: Input data of system A||||||||
|||||||||||01: Input data of system B||||||||
|||||||||||10: Input data of system C||||||||
|||||||||||11: Input data of system D||||||||
|15 to 1|—|||All||0||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|0|BYPASS|||0||||R/W||Bypass Mode||||||||
|||||||||||This bit controls the data pass of MIX function.||||||||
|||||||||||0: MIX function is used.||||||||
|||||||||||Input data is processed by MIX and then the result data is connected||||||||
|||||||||||to output data.||||||||
|||||||||||1: SRC function is not used.||||||||
|||||||||||Input data is connected to output data according to the BPSYS bits.||||||||

## 37.3.55 MIX0_0 Mode Register (MIXMR_MIX0_0)

MIXMR_MIX0_0 is a 32-bit readable/writable register that selects the MIX mode.

||||Bit:|31|30||29|28|27||26|25<br>24|23|22|21||20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-||-|-|-||-|-<br>-|-|-|-||-|-|-|-|-||
||||Initial value:|0|0||0|0|0||0|0<br>0|0|0|0||0|0|0|0|0||
||||R/W:|R|R||R|R|R||R|R<br>R|R|R|R||R|R|R|R|R||
||||Bit:|15|14||13|12|11||10|9<br>8|7|6|5||4|3|2|1|0||
|||||-|-||-|-|-||-|-<br>-|-|-|-||-|-|-|-|MIX||
||||||||||||||||||||||MODE||
||||Initial value:|0|0||0|0|0||0|0<br>0|0|0|0||0|0|0|0|0||
||||R/W:|R|R||R|R|R||R|R<br>R|R|R|R||R|R|R|R|R/W||
|||||||**Initial**|||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**|||**Description**|||||||||||
|31|to|1|—|||All 0|||R|||Reserved|||||||||||
|||||||||||||These bits|are always read as||||0. The write value|||should always be 0.|||
|0|||MIXMODE|||0|||R/W|||MIX mode|||||||||||
|||||||||||||This bit sets the mix mode.|||||||||||
|||||||||||||0: Selects volume step mixer.|||||||||||
|||||||||||||1: Selects volume ramp mixer.|||||||||||

## 37.3.56 MIX0_0 Volume Period Register (MVPDR_MIX0_0)

MVPDR_MIX0_0 is a 32-bit readable/writable register that sets the ramp time of volume ramp.

||Bit:|31|30||29|28|27||26|25<br>24<br>23<br>22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-||-|-<br>-<br>-<br>-|-|-|-|-|-|-||
||Initial value:|0|0||0|0|0||0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R||R|R<br>R<br>R<br>R|R|R|R|R|R|R||
||Bit:|15|14||13|12|11||10|9<br>8<br>7<br>6|5|4|3|2|1|0||
|||-|-||-|-|||MXPDUP<br>-<br>-||-|-||MXPDDW||||
||Initial value:|0|0||0|0|0||0|0<br>0<br>0<br>0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R/W||R/W|R/W<br>R/W<br>R<br>R|R|R|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**|||**Description**||||||||
|31 to 12|—|||All 0|||R|||Reserved||||||||
|||||||||||These bits are always read as 0. The write value|||||should always be 0.|||
|11 to 8|MXPDUP|||0|||R/W|||Volume Up Period||||||||
|||||||||||These bits set the decibel which changes per sample during volume up.||||||||
|||||||||||This setting is used when the||MIXMODE bit in the MIXMR register is set||||||
|||||||||||to 1.||||||||
|||||||||||0000: 128 dB/1 sample||||||||
|||||||||||0001: 64 dB/1 sample||||||||
|||||||||||0010: 32 dB/1 sample||||||||
|||||||||||0011: 16 dB/1 sample||||||||
|||||||||||0100: 8 dB/1 sample||||||||
|||||||||||0101: 4 dB/1 sample||||||||
|||||||||||0110: 2 dB/1 sample||||||||
|||||||||||0111: 1 dB/1 sample||||||||
|||||||||||1000: 0.5 dB/1 sample||||||||
|||||||||||1001: 0.25 dB/1 sample||||||||
|||||||||||1010: 0.125 dB/1 sample||||||||
|||||||||||1011 to 1111: Reserved||||||||
|7 to 4|—|||All 0|||R|||Reserved||||||||
|||||||||||These bits are always read as 0. The write value|||||should always be 0.|||
|3 to 0|MXPDDW|||0|||R/W|||Volume Down Period||||||||
|||||||||||These bits set the decibel which changes per sample during volume||||||||
|||||||||||down. This setting is used when the|||MIXMODE bit in the MIXMR register|||||
|||||||||||is set to 1.||||||||
|||||||||||0000: -128 dB/1 sample||||||||
|||||||||||0001: -64 dB/1 sample||||||||
|||||||||||0010: -32 dB/1 sample||||||||
|||||||||||0011: -16 dB/1 sample||||||||
|||||||||||0100: -8 dB/1 sample||||||||
|||||||||||0101: -4 dB/1 sample||||||||
|||||||||||0110: -2 dB/1 sample||||||||
|||||||||||0111: -1 dB/1 sample||||||||
|||||||||||1000: -0.5 dB/1 sample||||||||
|||||||||||1001: -0.25 dB/1 sample||||||||
|||||||||||1010: -0.125 dB/1 sample||||||||
|||||||||||1011 to 1111: Reserved||||||||

## 37.3.57 MIX0_0 Decibel A Register (MDBAR_MIX0_0)

MDBAR_MIX0_0 is a 32-bit readable/writable register that sets the gain level (decibel units) of system A.

||Bit:|31|30||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-|-|-|-|-|-|-|-|-||
||Initial value:|0|0||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||Bit:|15|14||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||-|-||-|-|-|-||||MIXDBA|||||||
||Initial value:|0|0||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W||
|||||**Initial**|||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**||||||||||
|31 to 10|—|||All 0|||R||Reserved||||||||||
||||||||||These bits are always read as 0. The write||||||value|should always be 0.|||
|9 to 0|MIXDBA|||All 0|||R/W||dDecibel of System A||||||||||
||||||||||These bits set the decibel (gain level) of volume ramp. The value can be||||||||||
||||||||||selected from 1024 points in the range of f0 dB to -∞ dB at intervals of||||||||||
||||||||||0.125 dB.||||||||||

|0.125 dB.||||||
|---|---|---|---|---|---|
|**Setting**|||**Setting**|||
|**Value**|**Time**|**Gain[dB]**|**Value**|**Time**|**Gain[dB]**|
|0x000|1|0|......|......|......|
|......|......|......|0x091|0.125|-18.125|
|0x031|0.5|-6.125|......|......|......|
|......|......|......|0x3FE|4.1x10-7|-127.75|
|0x061|0.25|-12.125|0x3FF|0 (Mute)|-∞|

## 37.3.58 MIX0_0 Decibel B Register (MDBBR_MIX0_0)

MDBBR_MIX0_0 is a 32-bit readable/writable register that sets the gain level (decibel units) of system B.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br><br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>MIXDBB|
|---|---|
|31 to 10<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|9 to 0<br>MIXDBB<br>All 0<br>R/W|Decibel of System B<br>These bits set the decibel (gain level) of volume ramp. The value can be<br>selected from 1024 points in the range of f0 dB to -∞ dB at intervals of<br>0.125 dB.<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x000<br>1<br>0<br>......<br>......<br>......<br>......<br>......<br>......<br>0x091<br>0.125<br>-18.125<br>0x031<br>0.5<br>-6.125<br>......<br>......<br>......<br>......<br>......<br>......<br>0x3FE<br>4.1x10-7<br>-127.75<br>0x061<br>0.25<br>-12.125<br>0x3FF<br>0 (Mute)<br>-∞|

## 37.3.59 MIX0_0 Decibel C Register (MDBCR_MIX0_0)

MDBCR_MIX0_0 is a 32-bit readable/writable register that sets the gain level (decibel units) of system C.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>MIXDBC|
|---|---|
|31 to 10<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|9 to 0<br>MIXDBC<br>All 0<br>R/W|Decibel of System C<br>These bits set the decibel (gain level) of volume ramp. The value can be<br>selected from 1024 points in the range of f0 dB to -∞ dB at intervals of<br>0.125 dB.<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x000<br>1<br>0<br>......<br>......<br>......<br>......<br>......<br>......<br>0x091<br>0.125<br>-18.125<br>0x031<br>0.5<br>-6.125<br>......<br>......<br>......<br>......<br>......<br>......<br>0x3FE<br>4.1x10-7<br>-127.75<br>0x061<br>0.25<br>-12.125<br>0x3FF<br>0 (Mute)<br>-∞|

## 37.3.60 MIX0_0 Decibel D Register (MDBDR_MIX0_0)

MDBDR_MIX0_0 is a 32-bit readable/writable register that sets the gain level (decibel units) of system D.

|**Bit**<br>**Bit Name**<br>**Initial**<br>**Value**<br>**R/W**<br>31<br>30<br>29<br>28<br>27<br>26<br>15<br>14<br>13<br>12<br>11<br>10<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br><br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>Bit:<br>Initial value:<br>R/W:<br>Bit:<br>Initial value:<br>R/W:|**Description**<br>25<br>24<br>23<br>22<br>21<br>20<br>19<br>18<br>17<br>16<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>R<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>0<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>-<br>MIXDBD|
|---|---|
|31 to 10<br>—<br>All 0<br>R|Reserved<br>These bits are always read as 0. The write value should always be 0.|
|9 to 0<br>MIXDBD<br>All 0<br>R/W|Decibel of System D<br>These bits set the decibel (gain level) of volume ramp. The value can be<br>selected from 1024 points in the range of f0 dB to -∞ dB at intervals of<br>0.125 dB.<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>**Setting**<br>**Value**<br>**Time**<br>**Gain[dB]**<br>0x000<br>1<br>0<br>......<br>......<br>......<br>......<br>......<br>......<br>0x091<br>0.125<br>-18.125<br>0x031<br>0.5<br>-6.125<br>......<br>......<br>......<br>......<br>......<br>......<br>0x3FE<br>4.1x10-7<br>-127.75<br>0x061<br>0.25<br>-12.125<br>0x3FF<br>0 (Mute)<br>-∞|

## 37.3.61 MIX0_0 Decibel Enable Register (MDBER_MIX0_0)

MDBER_MIX0_0 is a 32-bit readable/writable register that enable or disables the MIX decibel register settings.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|MIXDB|
|||||||||||||||||EN|
|Initial value:|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|to|1|—|All 0|R|Reserved|
|||||||These bits are always read as 0. The write value should always be 0.|
|0|||MIXDBEN|0|R/W|MIX Decibel Enable|
|||||||This bit controls the decibel dB set in MDBAR, MDBBR, MDBCR and|
|||||||MDBDR registers.|
|||||||0: Disables the setting of decibel.|
|||||||1: Enables the setting of decibel.|

## 37.3.62 MIX0_0 Status Register (MIXSR_MIX0_0)

MIXSR_MIX0_0 is a 32-bit read-only register that indicates the status of the MIX.

||Bit:|31|30||29|28|27|26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-||-|-|-|-|-<br>-|-|-|-|-|-|-|-|-||
||Initial value:|0|0||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
||Bit:|15|14||13|12|11|10|9<br>8|7|6|5|4|3|2|1|0||
|||-|-||-|-|-|-|-<br>-|-|-|-|-|-|-|MIXSTS|||
||Initial value:|0|0||0|0|0|0|0<br>0|0|0|0|0|0|0|0|0||
||R/W:|R|R||R|R|R|R|R<br>R|R|R|R|R|R|R|R|R||
|||||**Initial**|||||||||||||||
|**Bit**|**Bit Name**|||**Value**|||**R/W**||**Description**||||||||||
|31 to 2|—|||All 0|||R||Reserved||||||||||
||||||||||These bits are always read as 0. The write||||||value|should always be 0.|||
|1, 0|MIXSTS|||All 0|||R||MIX Status||||||||||
||||||||||This bit specifies the status of||||ramp process.||||||
||||||||||00: Ramp process is unchanged.||||||||||
||||||||||01: Ramp down||||||||||
||||||||||10: Ramp up||||||||||

## 37.3.63 Software Reset Register (SWRSR_CIM)

SWRSR_CIM is a 32-bit readable/writable register that initializes the SCUX internal circuit.

||||Bit:|31|30||29|28|27||26|25<br>24|23|22|21|20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-|-||-|-|-||-|-<br>-|-|-|-|-|-|-|-|-||
||||Initial value:|0|0||0|0|0||0|0<br>0|0|0|0|0|0|0|0|0||
||||R/W:|R|R||R|R|R||R|R<br>R|R|R|R|R|R|R|R|R||
||||Bit:|15|14||13|12|11||10|9<br>8|7|6|5|4|3|2|1|0||
|||||-|-||-|-|-||-|-<br>-|-|-|-|-|-|-|-|SWRST||
||||Initial value:|0|0||0|0|0||0|0<br>0|0|0|0|0|0|0|0|1||
||||R/W:|R|R||R|R|R||R|R<br>R|R|R|R|R|R|R|R|R/W||
|||||||**Initial**||||||||||||||||
|**Bit**|||**Bit Name**|||**Value**|||**R/W**|||**Description**||||||||||
|31|to|1|—|||All 0|||R|||Reserved||||||||||
|||||||||||||These bits|are always read as 0. The write value||||||should always be 0.|||
|0|||SWRST|||1|||R/W|||While this bit is set to 0, the SCUX internal circuit is reset. Registers||||||||||
|||||||||||||except this|register are||reset.|Therefore, they should be set again after||||||
|||||||||||||the reset is canceled.||||||||||
|||||||||||||0: The SCUX is reset.||||||||||
|||||||||||||1: The SCUX is operating.||||||||||

## 37.3.64 DMA Control Register (DMACR_CIM)

DMACR_CIM is a 32-bit readable/writable register that controls DMA execution.

||||Bit:|31||30||29|28|27||26|25<br>24<br>23<br>22<br>21<br>20<br>19<br>18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||-||-||-|-|-||-|-<br>-<br>-<br>-<br>-<br>-<br>-<br>-|-|-||
||||Initial value:|0||0||0|0|0||0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0|0||
||||R/W:|R||R||R|R|R||R|R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W||
||||Bit:|15||14||13|12|11||10|9<br>8<br>7<br>6<br>5<br>4<br>3<br>2|1|0||
|||||-||-||-|-|-||-|-<br>-<br>DMAM<br>DMAM<br>DMAM<br>DMAM<br>DMAM<br>DMAM|DMAM|DMAM||
||||||||||||||DFFU3<br>DFFU2<br>DFFU1<br>DFFU0<br>DFFD3<br>DFFD2|DFFD1|DFFD0||
||||Initial value:|0||0||0|0|0||0|0<br>0<br>0<br>0<br>0<br>0<br>0<br>0|0|0||
||||R/W:|R||R||R|R|R||R|R<br>R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W||
||||||||**Initial**||||||||||
|**Bit**|||**Bit Name**||||**Value**|||**R/W**|||**Description**||||
|31|to|24|—||||All 0|||R|||Reserved||||
||||||||||||||These bits are always read as 0. The write value|should always be 0.|||
|23|to|16|—||||All 0|||R/W|||Reserved||||
||||||||||||||The write value should always be 0.||||
|15|to|8|—||||All 0|||R|||Reserved||||
||||||||||||||These bits are always read as 0. The write value|should always be 0.|||
|7|||DMAMDFFU3||||0|||R/W|||FFU0_3 DMA Mode||||
||||||||||||||0: Disables DMA transfer to DMATD3_CIM.||||
||||||||||||||1: Enables DMA transfer to DMATD3_CIM.||||
||||||||||||||Note: When DMA transfer is enabled, disable packet requests sent to the||||
||||||||||||||interrupt controller. (Set the UEVMR_FFU0_3.UEVMRQ bit to 0.)||||
|6|||DMAMDFFU2||||0|||R/W|||FFU0_2 DMA Mode||||
||||||||||||||0: Disables DMA transfer to DMATD2_CIM.||||
||||||||||||||1: Enables DMA transfer to DMATD2_CIM.||||
||||||||||||||Note: When DMA transfer is enabled, disable packet requests sent to the||||
||||||||||||||interrupt controller. (Set the UEVMR_FFU0_2.UEVMRQ bit to 0.)||||
|5|||DMAMDFFU1||||0|||R/W|||FFU0_1 DMA Mode||||
||||||||||||||0: Disables DMA transfer to DMATD1_CIM.||||
||||||||||||||1: Enables DMA transfer to DMATD1_CIM.||||
||||||||||||||Note: When DMA transfer is enabled, disable packet requests sent to the||||
||||||||||||||interrupt controller. (Set the UEVMR_FFU0_1.UEVMRQ bit to 0.)||||
|4|||DMAMDFFU0||||0|||R/W|||FFU0_0 DMA Mode||||
||||||||||||||0: Disables DMA transfer to DMATD0_CIM.||||
||||||||||||||1: Enables DMA transfer to DMATD0_CIM.||||
||||||||||||||Note: When DMA transfer is enabled, disable packet requests sent to the||||
||||||||||||||interrupt controller. (Set the UEVMR_FFU0_0.UEVMRQ bit to 0.)||||
|3|||DMAMDFFD3||||0|||R/W|||FFD0_3 DMA Mode||||
||||||||||||||0: Disables DMA transfer to DMATD3_CIM.||||
||||||||||||||1: Enables DMA transfer to DMATD3_CIM.||||
||||||||||||||Note: When DMA transfer is enabled, disable packet requests sent to the||||
||||||||||||||interrupt controller. (Set the DEVMR_FFD0_3.DEVMRQ bit to 0.)||||
|2|||DMAMDFFD2||||0|||R/W|||FFD0_2 DMA Mode||||
||||||||||||||0: Disables DMA transfer to DMATD2_CIM.||||
||||||||||||||1: Enables DMA transfer to DMATD2_CIM.||||
||||||||||||||Note: When DMA transfer is enabled, disable packet requests sent to the||||
||||||||||||||interrupt controller. (Set the DEVMR_FFD0_2.DEVMRQ bit to 0.)||||
|1|||DMAMDFFD1||||0|||R/W|||FFD0_1 DMA Mode||||
||||||||||||||0: Disables DMA transfer to DMATD1_CIM.||||
||||||||||||||1: Enables DMA transfer to DMATD1_CIM.||||
||||||||||||||Note: When DMA transfer is enabled, disable packet requests sent to the||||
||||||||||||||interrupt controller. (Set the DEVMR_FFD0_1.DEVMRQ bit to 0.)||||
|0|||DMAMDFFD0||||0|||R/W|||FFD0_0 DMA Mode||||
||||||||||||||0: Disables DMA transfer to DMATD0_CIM.||||
||||||||||||||1: Enables DMA transfer to DMATD0_CIM.||||
||||||||||||||Note: When DMA transfer is enabled, disable packet requests sent to the||||
||||||||||||||interrupt controller. (Set the DEVMR_FFD0_0.DEVMRQ bit to 0.)||||

## 37.3.65 DMA Transfer Register for FFD0_n (DMATDn_CIM) (n = 0, 1, 2, 3)

DMATDn_CIM is a 32-bit register that stores the data to be transmitted to FFD0_n. The data written to DMATDn_CIM is automatically stored in FFD0_n. When the number of idle data bytes in FFD0_n becomes equal to or greater than the value set in DRQSR_FFD0_n.SIZE, a data transfer request is issued. When the DMA controller is used

(DMACR_CIM.DMAMDFFDn = 1), a transfer request for the number of counts set in DRQSR_FFD0_n.SIZE is sent to the DMA controller. When the interrupt controller is used (DEVMR_FFD0_n.DEVMRQ = 1), data is written in this register for the number of counts set in DRQSR_FFD0_n.SIZE.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|R/W:|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|R/W:|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|W|

In the SCUX internal block, audio data is handled in the 24-bit big endian format. When this register is accessed in 32-bit units, the lower eight bits are not used and only the upper 24 bits are used, as shown in Figure 37.2 . When the SCUX is used in 16-bit mode, the valid data needs to be located at the MSB of audio data. Therefore, when this register is accessed in 16-bit units, the written data is located in the upper 16 bits of audio data and the lower eight bits are fixed to 0 in the CIM block. When the SCUX is used in 16-bit mode and this register is accessed in 32-bit units, since bits [15:8] of the data to be written is passed to the FFD block without change, 0 should be written to bits [15:8].

|**Figure 37.2**<br>**Data Alignment of DMATDn_CIM**<br>DMATD<br>[31:24]<br>[23:16]<br>[15:8]<br>[7:0]<br>MSB       ↓<br>↓<br>↓         LSB<br>SCUX audio data<br>[23:16]<br>[15:8]<br>[7:0]<br>Not used<br>16-bit mode, 16-bit access to DMATD<br>SCUX audio data<br>Write data [15:8]<br>Write data [7:0]<br>Clamped to 0 in CIM<br>16-bit mode, 32-bit access to DMATD<br>SCUX audio data<br>Write data [31:24]<br>Valid data<br>Write data [23:16]<br>Valid data<br>Write data [15:8]<br>Write 0 to these bits|[31:24]|[23:16]|[15:8]|[7:0]|
|---|---|---|---|---|

## 37.3.66 DMA Transfer Register for FFU0_n (DMATUn_CIM) (n = 0, 1, 2, 3)

DMATUn_CIM is a 32-bit register that stores the data received from FFU0_n. When data is read from DMATUn_CIM, the next data is automatically transferred from FFU0_n. When the number of data bytes in FFU0_n becomes equal to or greater than the value set in URQSR_FFU0_n.SIZE, a data transfer request is issued. When the DMA controller is used (DMACR_CIM.DMAMDFFUn = 1), a transfer request for the number of counts set in URQSR_FFU0_n.SIZE is sent to the DMA controller. When the interrupt controller is used (UEVMR_FFU0_n.UEVMRQ = 1), data is read from this register for the number of counts set in URQSR_FFU0_n.SIZE.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Initial value:|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|R/W:|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|R|

When this register is accessed in 32-bit units, audio data is located in the upper 24 bits and the lower eight bits are always read as 0, as shown in Figure 37.3 . When this register is accessed in 16-bit units, the upper 16 bits of audio data are read as valid data. When the SCUX is used in 16-bit mode and this register is accessed in 32-bit units, the lower eight bits are always read as 0 and bits [15:8] of the read data are read as a value dependent on the internal operation result in the SRC.

|SCUX audio data<br>DMATU<br>16-bit mode, 16-bit ac<br>Read data[15:0]<br>16-bit mode, 32-bit ac<br>Read data[31:0]|[23:16]|[15:8]|[7:0]|[7:0]|
|---|---|---|---|---|
||[31:24]|[23:16]|[15:8]|[7:0]|
||cess to DMATU<br>Audio data [23:16]<br>Audio data [15:8]<br>cess to DMATU||||
||Audio data [23:16]|Audio data [15:8]|Depends on the<br>operation result*|All 0|

Note: * All 1 when the internal operation result of the SRC is 0x7FFFFF; otherwise, all 0.

Even when used in 16-bit mode, operation is performed in 24-bit units.

## **Figure 37.3 Data Alignment of DMATUn_CIM**

## 37.3.67 SSI Route Select Register (SSIRSEL_CIM)

SSIRSEL_CIM is a 32-bit readable/writable register that selects the SSIF channel to be connected to each SRC during direct transfer with the SSIF module. This register setting has no meaning when a route between the FFD or FFU module is selected. The IPSLR_IPC0_n and OPSLR_OPC0_n registers are used to select connection between the SSIF or FFD/ FFU module. The DVUBR_DVU0_n register is used to specify whether the DVU is used or not.

|||Bit:|31|30||29|29|28|27|26|25<br>24<br>23<br>22<br>21|20<br>19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||SISEL3||||SISEL2||SISEL1||SISEL0<br>-<br>-<br>-|-<br>-|-|-|-||
|||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0|0<br>0|0|0|0||
|||R/W:|R/W|R/W||R/W||R/W|R/W|R/W|R/W<br>R/W<br>R<br>R<br>R/W|R/W<br>R|R|R/W|R/W||
|||Bit:|15|14||13||12|11|10|9<br>8<br>7<br>6<br>5|4<br>3|2|1|0||
||||-|-|||SOSEL3||-|-|SOSEL2<br>-<br>-<br>SOSEL1<br>-||-|SOSEL0|||
|||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0|0<br>0|0|0|0||
|||R/W:|R|R||R/W||R/W|R|R|R/W<br>R/W<br>R<br>R<br>R/W|R/W<br>R|R|R/W|R/W||
||||||**Initial**||||||||||||
|**Bit**||**Bit Name**|||**Value**||||**R/W**||**Description**||||||
|31,|30|SISEL3|||00||||R/W||SRC3 SSIF Input Select||||||
||||||||||||These bits select the input route of SRC3.||||||
||||||||||||00: Uses the input from SSIF2.||||||
||||||||||||01, 10, 11: Setting prohibited||||||
||||||||||||Note: When the route from the FFD module is selected||||by the||
||||||||||||IPSLR_IPC0_3 register, this bit setting has no meaning.||||||
|29,|28|SISEL2|||00||||R/W||SRC2 SSIF Input Select||||||
||||||||||||These bits select the input route of SRC2.||||||
||||||||||||00: Uses the input from SSIF1.||||||
||||||||||||01, 10, 11: Setting prohibited||||||
||||||||||||Note: When the route from the FFD module is selected||||by the||
||||||||||||IPSLR_IPC0_2 register, this bit setting has no meaning.||||||
|27,|26|SISEL1|||00||||R/W||SRC1 SSIF Input Select||||||
||||||||||||These bits select the input route of SRC1.||||||
||||||||||||00: Uses the input from SSIF3.||||||
||||||||||||01, 10, 11: Setting prohibited||||||
||||||||||||Note: When the route from the FFD module is selected||||by the||
||||||||||||IPSLR_IPC0_1 register, this bit setting has no meaning.||||||
|25,|24|SISEL0|||00||||R/W||SRC0 SSIF Input Select||||||
||||||||||||These bits select the input route of SRC0.||||||
||||||||||||00: Uses the input from SSIF0.||||||
||||||||||||01: Uses the input from SSIF012.*||||||
||||||||||||10, 11: Setting prohibited||||||
||||||||||||Note: When the route from the FFD module is selected||||by the||
||||||||||||IPSLR_IPC0_0 register, this bit setting has no meaning.||||||
||||||||||||* These bits can be set to|01 only when the SSI1PMD and SSI2PMD|||||
||||||||||||bits of the SSIPMD_CIM register are both set to 01 or 10.||||||
|23,|22|—|||All||0||R||Reserved||||||
||||||||||||These bits are always read as 0. The write||value|should always be 0.|||
|21,|20|—|||All||0||R/W||Reserved||||||
||||||||||||The write value should always be 0.||||||
|19,|18|—|||All||0||R||Reserved||||||
||||||||||||These bits are always read as 0. The write||value|should always be 0.|||
|17,|16|—|||All||0||R/W||Reserved||||||
||||||||||||The write value should always be 0.||||||
|15,|14|—|||All||0||R||Reserved||||||
||||||||||||These bits are always read as 0. The write||value|should always be 0.|||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|13, 12|SOSEL3|00|R/W|SSIF3 Output Select|
|||||These bits select the output route to SSIF3.|
|||||00: Uses the output from SRC1 (DVU0_1).*1|
|||||01: Uses the output from SRC0 (DVU0_0).*2|
|||||10: Uses the output from MIX.|
|||||11: Setting prohibited|
|||||Notes:1.When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_1 register, this bit setting has no meaning.|
|||||2.When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_0 register, this bit setting has no meaning.|
|11, 10|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|9, 8|SOSEL2|00|R/W|SSIF2 Output Select|
|||||These bits select the output route to SSIF2.|
|||||00: Uses the output from SRC3 (DVU0_3).*1|
|||||01: Uses the output from SRC0 (DVU0_0).*2,*4|
|||||10: Uses the output from SRC1 (DVU0_1).*3,*4|
|||||11: Uses the output from MIX.*4|
|||||Notes:1.When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_3 register, this bit setting has no meaning.|
|||||2.When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_0 register, this bit setting has no meaning.|
|||||3.When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_1 register, this bit setting has no meaning.|
|||||4.Valid only when SSIPMD_CIM.SSI012EN = 1.|
|7, 6|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|5, 4|SOSEL1|00|R/W|SSIF1 Output Select|
|||||These bits select the output route to SSIF1.|
|||||00: Uses the output from SRC2 (DVU0_2).*1|
|||||01: Uses the output from SRC0 (DVU0_0).*2,*4|
|||||10: Uses the output from SRC1 (DVU0_1).*3,*4|
|||||11: Uses the output from MIX.*4|
|||||Notes:1. When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_2 register, this bit setting has no meaning.|
|||||2. When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_0 register, this bit setting has no meaning.|
|||||3. When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_1 register, this bit setting has no meaning.|
|||||4. Valid only when SSIPMD_CIM.SSI012EN = 1.|
|3, 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1, 0|SOSEL0|00|R/W|SSIF0 Output Select|
|||||These bits select the output route to SSIF0.|
|||||00: Uses the output from SRC0 (DVU0_0).*1|
|||||01: Uses the output from SRC1 (DVU0_1).*2|
|||||10: Uses the output from MIX.|
|||||11: Setting prohibited.|
|||||Notes:1. When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_0 register, this bit setting has no meaning.|
|||||2. When the route to the FFU module is selected by the|
|||||OPSLR_OPC0_1 register, this bit setting has no meaning.|

## 37.3.68 FFD0_n Timing Select Register (FDTSELn_CIM) (n = 0, 1, 2, 3)

FDTSELn_CIM is a 32-bit readable/writable register that selects the input timing signal to be used in SRCn (n = 0, 1, 2, 3) when asynchronous mode is selected. This register setting is used only when the route with the FFD module is selected.

|selected.|||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22<br>21<br>20||19|18|17|16||
|||-|-|||-|-|-||SCKDIV|||||||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0||0|0|0|0||
||R/W:|R|R|||R|R|R|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W||R/W|R/W|R/W||
||Bit:|15|14|||13|12|11|10|9<br>8<br>7<br>6<br>5<br>4||3|2|1|0||
|||-|-|||-|-|-|-|-<br>DIVEN<br>-<br>-<br>-<br>MTUSEL|||SCKSEL||||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0||0|0|0|0||
||R/W:|R|R|||R|R|R|R|R<br>R/W<br>R<br>R<br>R<br>R/W|R/W||R/W|R/W|R/W||
|||||**Initial**|||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**||**Description**|||||||
|31 to 27|—|||All||0||R||Reserved|||||||
|||||||||||These bits are always read as 0. The||write|value|should always be 0.|||
|26 to 16|SCKDIV|||All||0||R/W||Division Ratio|||||||
|||||||||||These bits specify the ratio for dividing the|||input clock specified in the||||
|||||||||||SCKSEL bits to generate the timing signal.|||||||
|||||||||||Note: Always write 0 to bit 16. (Writing 1 to|||bit 16|is ignored.)|||
|||||||||||When all of these bits are set to 0, the division ratio is 1.|||||||
|||||||||||Only the input clock selected by||SCKSEL[3] = 0 will be divided. The|||||
|||||||||||WS signal selected by SCKSEL[3] =|||1 will not be divided.||||
|||||||||||The DIVEN bit must be set to 0||before changing|||these bits.||
|15 to 9|—|||All||0||R||Reserved|||||||
|||||||||||These bits are always read as 0. The||write|value|should always be 0.|||
|8|DIVEN|||0||||R/W||Division Enable|||||||
|||||||||||Frequency division starts the moment||1 is written to this bit.|||||
|||||||||||1: Starts frequency division.|||||||
|||||||||||0: Outputs 0.|||||||
|7 to 5|—|||All||0||R||Reserved|||||||
|||||||||||These bits are always read as 0. The||write|value|should always be 0.|||
|4|MTUSEL|||0||||R/W||MTU Select|||||||
|||||||||||This bit selects the clock signal specified by setting the|||||SCKSEL bits to||
|||||||||||0101 from the multi-function timer pulse unit 2.|||||||
|||||||||||0: Uses TIOC3A.|||||||
|||||||||||1: Uses TIOC4A|||||||
|3 to 0|SCKSEL|||All||0||R/W||Clock Select|||||||
|||||||||||These bits select the clock that is used in generating the timing signal.|||||||
|||||||||||0000: Uses AUDIO_CLK.|||||||
|||||||||||0001: Uses the AUDIO_X1 input.|||||||
|||||||||||0010: Uses MLB_CLK.|||||||
|||||||||||0011: Uses USB_X1.|||||||
|||||||||||0100: Uses the peripheral clock 1 (P1) divided into 2.|||||||
|||||||||||0101: Uses the signal specified by the MTUSEL bit.|||||||
|||||||||||0110 and 0111: Setting prohibited|||||||
|||||||||||1000: Uses the WS signal of SSIF0.|||||||
|||||||||||1001: Uses the WS signal of SSIF1.|||||||
|||||||||||1010: Uses the WS signal of SSIF2.|||||||
|||||||||||1011: Uses the WS signal of SSIF3.|||||||
|||||||||||1100 to 1111: Setting prohibited|||||||
|||||||||||Note: The DIVEN bit must be set to 0||before changing these bits.|||||

The input timing signal selector has the configuration shown in Figure 37.4 .

**==> picture [280 x 138] intentionally omitted <==**

**----- Start of picture text -----**<br>
AUDIO_CLK SCKDIV<br>AUDIO_X1<br>MLB_CLK<br>USB_X1 Divider<br>P1φ Division<br>by 2<br>SSIWS0 Used as the input timing<br>signal in SCUX<br>SSIWS1<br>DIVEN<br>SSIWS2<br>SCKSEL[2:0] SSIWS3<br>TIOC3A<br>TIOC4A<br>SCKSEL[3]<br>SCKSEL[2:0]<br>MTUSEL<br>**----- End of picture text -----**<br>

**Figure 37.4 Configuration Diagram of Input Timing Signal Selector**

## 37.3.69 FFU0_n Timing Select Register (FDTSELn_CIM) (n = 0, 1, 2, 3)

FUTSELn_CIM is a 32-bit writable register that selects the output timing signal to be used in SRCn (n = 0, 1, 2, 3) when asynchronous mode is selected. This register setting is used when the route with the FFU module is selected or when output to the MIX is selected.

||Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22<br>21<br>20||19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|||-|-|-||SCKDIV|||||||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0||0|0|0|0||
||R/W:|-|-|||-|-|-|W|W<br>W<br>W<br>W<br>W<br>W||W|W|W|W||
||Bit:|15|14|||13|12|11|10|9<br>8<br>7<br>6<br>5<br>4||3|2|1|0||
|||-|-|||-|-|-|-|-<br>DIVEN<br>-<br>-<br>-<br>MTUSEL|||SCKSEL||||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0<br>0<br>0||0|0|0|0||
||R/W:|-|-|||-|-|-|-|-<br>W<br>-<br>-<br>-<br>W||W|W|W|W||
|||||**Initial**|||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**||**Description**|||||||
|31 to 27|—|||All||0||—||Reserved|||||||
|||||||||||The write value should always be 0.|||||||
|26 to 16|SCKDIV|||All||0||W||Division Ratio|||||||
|||||||||||These bits specify the ratio for dividing the|||input clock specified in the||||
|||||||||||SCKSEL bits to generate the timing signal.|||||||
|||||||||||Note: Always write 0 in bit 16. (Writing 1 to bit 16 is ignored.)|||||||
|||||||||||When all of these bits are set to||0, the division ratio is 1.|||||
|||||||||||Only the input clock selected by||SCKSEL[3] = 0 will be divided. The|||||
|||||||||||WS signal selected by SCKSEL[3] =|||1 will not be divided.||||
|||||||||||The DIVEN bit must be set to 0 before changing these bits.|||||||
|15 to 9|—|||All||0||—||Reserved|||||||
|||||||||||The write value should always be 0.|||||||
|8|DIVEN|||0||||W||Division Enable|||||||
|||||||||||Frequency division starts the moment||1 is written||to this bit.|||
|||||||||||1: Starts frequency division.|||||||
|||||||||||0: Outputs 0.|||||||
|7 to 5|—|||All||0||—||Reserved|||||||
|||||||||||The write value should always be 0.|||||||
|4|MTUSEL|||0||||W||MTU Select|||||||
|||||||||||This bit selects the clock signal specified by setting the SCKSEL bits to|||||||
|||||||||||0101 from the multi-function timer pulse unit 2.|||||||
|||||||||||0: Uses TIOC3A.|||||||
|||||||||||1: Uses TIOC4A.|||||||
|3 to 0|SCKSEL|||All||0||W||Clock Select|||||||
|||||||||||These bits select the clock that is used in generating the timing signal.|||||||
|||||||||||0000: Uses AUDIO_CLK.|||||||
|||||||||||0001: Uses AUDIO_X1 input.|||||||
|||||||||||0010: Uses MLB_CLK.|||||||
|||||||||||0011: Uses USB_X1.|||||||
|||||||||||0100: Uses the peripheral clock 1 (P1) divided into 2.|||||||
|||||||||||0101: Uses the signal specified by the MTUSEL bit.|||||||
|||||||||||0110 and 0111: Setting prohibited|||||||
|||||||||||1000: Uses the WS signal of SSIF0.|||||||
|||||||||||1001: Uses the WS signal of SSIF1.|||||||
|||||||||||1010: Uses the WS signal of SSIF2.|||||||
|||||||||||1011: Uses the WS signal of SSIF3.|||||||
|||||||||||1100 to 1111: Setting prohibited|||||||
|||||||||||Note: The DIVEN bit must be set to 0 before changing these bits.|||||||

The output timing signal selector has the configuration shown in Figure 37.5 .

**==> picture [281 x 138] intentionally omitted <==**

**----- Start of picture text -----**<br>
AUDIO_CLK SCKDIV<br>AUDIO_X1<br>MLB_CLK<br>USB_X1 Divider<br>P1φ Division<br>by 2<br>SSIWS0 Used as the output timing<br>signal in SCUX<br>SSIWS1<br>DIVEN<br>SSIWS2<br>SCKSEL[2:0] SSIWS3<br>TIOC3A<br>TIOC4A<br>SCKSEL[3]<br>SCKSEL[2:0]<br>MTUSEL<br>**----- End of picture text -----**<br>

**Figure 37.5 Configuration Diagram of Output Timing Signal Selector**

## 37.3.70 SSI Pin Mode Register (SSIPMD_CIM)

SSIPMD_CIM is a 32-bit readable/writable register that sets the pin mode of the SSIF.

||Bit:|31|30|||29|28|27|26|25<br>24<br>23<br>22||21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|-|||-|-|-|-|-<br>-<br>-<br>-||-<br>-|SSI3|SSI2|SSI1|SSI0||
||||||||||||||CKS|CKS|CKS|CKS||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0||0<br>0|0|0|0|0||
||R/W:|R|R|||R|R|R|R|R<br>R<br>R<br>R||R/W<br>R/W|R/W|R/W|R/W|R/W||
||Bit:|15|14|||13|12|11|10|9<br>8<br>7<br>6||5<br>4|3|2|1|0||
|||SSI3PMD||||-|-|-|-|-<br>-<br>-<br>-||-<br>SSI<br>012EN|SSI2PMD||SSI1PMD|||
||Initial value:|0|0|||0|0|0|0|0<br>0<br>0<br>0||0<br>0|0|0|0|0||
||R/W:|R/W|R/W|||R|R/W|R/W|R/W|R/W<br>R/W<br>R<br>R||R<br>R/W|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**||**Description**||||||||
|31 to 22|—|||All||0||R||Reserved||||||||
|||||||||||These bits are always read as 0. The write||||value|should always be 0.|||
|21, 20|—|||All||0||R/W||Reserved||||||||
|||||||||||The write value should always be 0.||||||||
|19|SSI3CKS|||0||||R/W||SSIF3 Clock Select||||||||
|||||||||||This bit selects the clock||to be connected to the AUDIO_CLK|||||pin of the|
|||||||||||SSIF3 module.||||||||
|||||||||||0: Selects the AUDIO_CLK input.||||||||
|||||||||||1: Selects the MLB_CLK input.||||||||
|||||||||||Note: When selecting AUDIO_CLK or MLB_CLK|||||as the oversampling|||
|||||||||||clock of the SSIF3||module, SSICR3.CKS = 1 must also|||||be set in|
|||||||||||the SSIF3 module.||||||||
|18|SSI2CKS|||0||||R/W||SSIF2 Clock Select||||||||
|||||||||||This bit selects the clock||to be connected to the AUDIO_CLK|||||pin of the|
|||||||||||SSIF2 module.||||||||
|||||||||||0: Selects the AUDIO_CLK input.||||||||
|||||||||||1: Selects the MLB_CLK input.||||||||
|||||||||||Note: When selecting AUDIO_CLK or MLB_CLK|||||as the oversampling|||
|||||||||||clock of the SSIF2||module, SSICR2.CKS = 1 must also|||||be set in|
|||||||||||the SSIF2 module.||||||||
|17|SSI1CKS|||0||||R/W||SSIF1 Clock Select||||||||
|||||||||||This bit selects the clock||to be connected to the AUDIO_CLK|||||pin of the|
|||||||||||SSIF1 module.||||||||
|||||||||||0: Selects the AUDIO_CLK input.||||||||
|||||||||||1: Selects the MLB_CLK input.||||||||
|||||||||||Note: When selecting AUDIO_CLK or MLB_CLK|||||as the oversampling|||
|||||||||||clock of the SSIF1||module, SSICR1.CKS = 1 must also|||||be set in|
|||||||||||the SSIF1 module.||||||||
|16|SSI0CKS|||0||||R/W||SSIF0 Clock Select||||||||
|||||||||||This bit selects the clock||to be connected to the AUDIO_CLK|||||pin of the|
|||||||||||SSIF0 module.||||||||
|||||||||||0: Selects the AUDIO_CLK input.||||||||
|||||||||||1: Selects the MLB_CLK input.||||||||
|||||||||||Note: When selecting AUDIO_CLK or MLB_CLK|||||as the oversampling|||
|||||||||||clock of the SSIF0||module, SSICR0.CKS = 1 must also|||||be set in|
|||||||||||the SSIF0 module.||||||||
|15, 14|SSI3PMD|||00||||R/W||SSIF3 Pin Mode||||||||
|||||||||||These bits select connection of the SSISCK3 and SSIWS3 pins.||||||||
|||||||||||00: The pins are used independently.||||||||
|||||||||||01: The SSIF0 pins are|used in common. Both SSIF0 and SSIF3 are|||||||
|||||||||||slaves.||||||||
|||||||||||10: The SSIF0 pins are|used in common. SSIF0 is the master||||||and SSIF3|
|||||||||||is the slave.||||||||
|||||||||||11: Setting prohibited||||||||
|13|—|||All||0||R/W||Reserved||||||||
|||||||||||This bits is always read|as 0. The write value should always be 0.|||||||
|12 to 8|—|||All||0||R/W||Reserved||||||||
|||||||||||The write value should always be 0.||||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7 to 5|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|4|SSI012EN|0|R/W|SSIF012 Enable|
|||||This bit selects whether the three modules SSIF0, SSIF1, and SSIF2 are|
|||||used to provide six channels at transmission.|
|||||0: Not handled as six channels.|
|||||1: Handled as six channels.|
|||||Note: This bit can be set to 1 only when the SSI1PMD and SSI2PMD bits|
|||||of this register are both set to 01 or 10.|
|||||Usage of six channels at reception can be specified by|
|||||SSIRSEL_CIM.SISEL0.|
|3, 2|SSI2PMD|00|R/W|SSIF2 Pin Mode|
|||||These bits select connection of the SSISCK2 and SSIWS2 pins.|
|||||00: The pins are used independently.|
|||||01: The SSIF0 pins are used in common. Both SSIF0 and SSIF2 are|
|||||slaves.|
|||||10: The SSIF0 pins are used in common. SSIF0 is the master and SSIF2|
|||||is the slave.|
|||||11: Setting prohibited|
|1, 0|SSI1PMD|00|R/W|SSIF1 Pin Mode|
|||||These bits select connection of the SSISCK1 and SSIWS1 pins.|
|||||00: The pins are used independently.|
|||||01: The SSIF0 pins are used in common. Both SSIF0 and SSIF1 are|
|||||slaves.|
|||||10: The SSIF0 pins are used in common. SSIF0 is the master and SSIF1|
|||||is the slave.|
|||||11: Setting prohibited|

## 37.3.71 SSI Control Register (SSICTRL_CIM)

SSIPCTRL_CIM is a 32-bit readable/writable register that controls connection with the SSIF module and starting and stopping of the module.

||Bit:|31|30|29|28|27|26|25<br>24<br>23<br>22<br>21<br>20|19|18|17|16||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||-|SSI3TX|-|-|-|SSI3RX|-<br>-<br>-<br>-<br>-<br>-|-|-|-|-||
||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:|-|W|W|W|-|W|W<br>W<br>-<br>-<br>-<br>-|-|-|-|W||
||Bit:|15|14|13|12|11|10|9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|||-|SSI0TX|SSI1TX|SSI2TX|-|SSI0RX|SSI1RX SSI2RX<br>-<br>-<br>-<br>-|-|-|SSI<br>012TEN|SSI<br>012REN||
||Initial value:|0|0|0|0|0|0|0<br>0<br>0<br>0<br>0<br>0|0|0|0|0||
||R/W:|-|W|W|W|-|W|W<br>W<br>-<br>-<br>-<br>-|-|-|W|W||
||||**Initial**|||||||||||
|**Bit**|**Bit Name**||**Value**|||**R/W**||**Description**||||||
|31|—||0|||—||Reserved||||||
|||||||||The write value should always be 0.||||||
|30|SSI3TX||0|||W||SSIF3 Direct Transmission||||||
|||||||||0: Disables direct transmission to SSIF3.||||||
|||||||||1: Enables direct transmission to SSIF3.||||||
|29, 28|—||All 0|||W||Reserved||||||
|||||||||The write value should always be 0.||||||
|27|—||0|||—||Reserved||||||
|||||||||The write value should always be 0.||||||
|26|SSI3RX||0|||W||SSIF3 Direct Reception||||||
|||||||||0: Disables direct reception from SSIF3.||||||
|||||||||1: Enables direct reception from SSIF3.||||||
|25, 24|—||All 0|||W||Reserved||||||
|||||||||The write value should always be 0.||||||
|23 to 18|—||All 0|||—||Reserved||||||
|||||||||The write value should always be 0.||||||
|17, 16|—||All 0|||W||Reserved||||||
|||||||||The write value should always be 0.||||||
|15|—||0|||—||Reserved||||||
|||||||||The write value should always be 0.||||||
|14|SSI0TX||0|||W||SSIF0 Direct Transmission||||||
|||||||||0: Disables direct transmission to SSIF0.||||||
|||||||||1: Enables direct transmission to SSIF0.||||||
|13|SSI1TX||0|||W||SSIF1 Direct Transmission||||||
|||||||||0: Disables direct transmission to SSIF1.||||||
|||||||||1: Enables direct transmission to SSIF1.||||||
|12|SSI2TX||0|||W||SSIF2 Direct Transmission||||||
|||||||||0: Disables direct transmission to SSIF2.||||||
|||||||||1: Enables direct transmission to SSIF2.||||||
|11|—||0|||—||Reserved||||||
|||||||||The write value should always be 0.||||||
|10|SSI0RX||0|||W||SSIF0 Direct Reception||||||
|||||||||0: Disables direct reception from SSIF0.||||||
|||||||||1: Enables direct reception from SSIF0.||||||
|9|SSI1RX||0|||W||SSIF1 Direct Reception||||||
|||||||||0: Disables direct reception from SSIF1.||||||
|||||||||1: Enables direct reception from SSIF1.||||||
|8|SSI2RX||0|||W||SSIF2 Direct Reception||||||
|||||||||0: Disables direct reception from SSIF2.||||||
|||||||||1: Enables direct reception from SSIF2.||||||
|7 to 2|—||All 0|||—||Reserved||||||
|||||||||The write value should always be 0.||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|1|SSI012TEN|0|W|SSIF012 Transmission Enable|
|||||This bit specifies transmission in three modules SSIF0, SSIF1, and|
|||||SSIF2 to be started or stopped simultaneously.|
|||||0: Stops transmission in SSIF0, SSIF1, and SSIF2.|
|||||1: Starts transmission in SSIF0, SSIF1, and SSIF2.|
|||||Note: This function can be used only when SSIPMD_CIM.SSI012EN = 1.|
|||||When SSIPMD_CIM.SSI012EN = 0, SSIF modules should be|
|||||controlled using SSICRn.TEN.|
|||||This bit must be set to 0 when performing direct transmission to|
|||||SSIF0, SSIF1, or SSIF2.|
|0|SSI012REN|0|W|SSIF012 Reception Enable|
|||||This bit specifies reception in three modules SSIF0, SSIF1, and SSIF2 to|
|||||be started or stopped simultaneously.|
|||||0: Stops reception in SSIF0, SSIF1, and SSIF2.|
|||||1: Starts reception in SSIF0, SSIF1, and SSIF2.|
|||||Note: This function can be used only when SSIRSEL_CIM.SISEL0 = 01.|
|||||When SSIRSEL_CIM.SISEL0 = 00, SSIF modules should be|
|||||controlled using SSICRn.REN.|
|||||This bit must be set to 0 when performing direct reception from|
|||||SSIF0, SSIF1, or SSIF2.|

## 37.3.72 SRCn Route Select Register (SRCRSELn_CIM) (n = 0, 1, 2, 3)

SRCRSEL_CIM is a 32-bit readable/writable register that sets the route for the data that is input to the SRC.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-||PLACE7||-||PLACE6||-||PLACE5||-||PLACE4||
|Initial value:|0|1|1|1|0|1|1|0|0|1|0|1|0|1|0|0|
|R/W:|R|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-||PLACE3||-||PLACE2||-||PLACE1||-||PLACE0||
|Initial value:|0|0|1|1|0|0|1|0|0|0|0|1|0|0|0|0|
|R/W:|R|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|30|to|28|PLACE7|111|R/W|Place 7|
|||||||Stream data is rearranged before it is input to the SRC.|
|||||||These bits select data on the input side to be output to place 7 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 7 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 7 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 7 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 7 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 7 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 7 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 7 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 7 on the output|
|||||||side.|
|||||||Note: This bit setting is used when eight channels are set. When six or|
|||||||less channels are set, set these bits to the same value as the initial|
|||||||value.|
|27|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|26|to|24|PLACE6|110|R/W|Place 6|
|||||||Stream data is rearranged before it is input to the SRC.|
|||||||These bits select data on the input side to be output to place 6 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 6 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 6 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 6 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 6 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 6 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 6 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 6 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 6 on the output|
|||||||side.|
|||||||Note: This bit setting is used when eight channels are set. When six or|
|||||||less channels are set, set these bits to the same value as the initial|
|||||||value.|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|23|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|22|to|20|PLACE5|101|R/W|Place 5|
|||||||Stream data is rearranged before it is input to the SRC.|
|||||||These bits select data on the input side to be output to place 5 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 5 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 5 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 5 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 5 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 5 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 5 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 5 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 5 on the output|
|||||||side.|
|||||||Note: This bit setting is used when six or more channels are set. When|
|||||||four or less channels are set, set these bits to the same value as|
|||||||the initial value.|
|19|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|18|to|16|PLACE4|100|R/W|Place 4|
|||||||Stream data is rearranged before it is input to the SRC.|
|||||||These bits select data on the input side to be output to place 4 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 4 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 4 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 4 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 4 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 4 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 4 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 4 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 4 on the output|
|||||||side.|
|||||||Note: This bit setting is used when six or more channels are set. When|
|||||||four or less channels are set, set these bits to the same value as|
|||||||the initial value.|
|15|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|14|to|12|PLACE3|011|R/W|Place 3|
|||||||Stream data is rearranged before it is input to the SRC.|
|||||||These bits select data on the input side to be output to place 3 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 3 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 3 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 3 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 3 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 3 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 3 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 3 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 3 on the output|
|||||||side.|
|||||||Note: This bit setting is used when four or more channels are set. When|
|||||||two or less channels are set, set these bits to the same value as|
|||||||the initial value.|
|11|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|10|to|8|PLACE2|010|R/W|Place 2|
|||||||Stream data is rearranged before it is input to the SRC.|
|||||||These bits select data on the input side to be output to place 2 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 2 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 2 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 2 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 2 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 2 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 2 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 2 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 2 on the output|
|||||||side.|
|||||||Note: This bit setting is used when four or more channels are set. When|
|||||||two or less channels are set, set these bits to the same value as|
|||||||the initial value.|
|7|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|6 to 4|PLACE1|001|R/W|Place 1|
|||||Stream data is rearranged before it is input to the SRC.|
|||||These bits select data on the input side to be output to place 1 on the|
|||||output side.|
|||||000: Data at place 0 on the input side is output to place 1 on the output|
|||||side.|
|||||001: Data at place 1 on the input side is output to place 1 on the output|
|||||side.|
|||||010: Data at place 2 on the input side is output to place 1 on the output|
|||||side.|
|||||011: Data at place 3 on the input side is output to place 1 on the output|
|||||side.|
|||||100: Data at place 4 on the input side is output to place 1 on the output|
|||||side.|
|||||101: Data at place 5 on the input side is output to place 1 on the output|
|||||side.|
|||||110: Data at place 6 on the input side is output to place 1 on the output|
|||||side.|
|||||111: Data at place 7 on the input side is output to place 1 on the output|
|||||side.|
|3|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|2 to 0|PLACE0|000|R/W|Place 0|
|||||Stream data is rearranged before it is input to the SRC.|
|||||These bits select data on the input side to be output to place 0 on the|
|||||output side.|
|||||000: Data at place 0 on the input side is output to place 0 on the output|
|||||side.|
|||||001: Data at place 1 on the input side is output to place 0 on the output|
|||||side.|
|||||010: Data at place 2 on the input side is output to place 0 on the output|
|||||side.|
|||||011: Data at place 3 on the input side is output to place 0 on the output|
|||||side.|
|||||100: Data at place 4 on the input side is output to place 0 on the output|
|||||side.|
|||||101: Data at place 5 on the input side is output to place 0 on the output|
|||||side.|
|||||110: Data at place 6 on the input side is output to place 0 on the output|
|||||side.|
|||||111: Data at place 7 on the input side is output to place 0 on the output|
|||||side.|

## 37.3.73 MIX Route Select Register (MIXRSEL_CIM)

MIXRSEL_CIM is a 32-bit readable/writable register that sets the route for the data that is output from the MIX.

|Bit:|31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||-||PLACE7||-||PLACE6||-||PLACE5||-||PLACE4||
|Initial value:|0|1|1|1|0|1|1|0|0|1|0|1|0|1|0|0|
|R/W:|R|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W|R/W|
|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
||-||PLACE3||-||PLACE2||-||PLACE1||-||PLACE0||
|Initial value:|0|0|1|1|0|0|1|0|0|0|0|1|0|0|0|0|
|R/W:|R|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W|R/W|R|R/W|R/W|R/W|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|31|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|30|to|28|PLACE7|111|R/W|Place 7|
|||||||Stream data is rearranged after it is output from the MIX.|
|||||||These bits select data on the input side to be output to place 7 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 7 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 7 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 7 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 7 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 7 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 7 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 7 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 7 on the output|
|||||||side.|
|||||||Note: This bit setting is used when eight channels are set. When six or|
|||||||less channels are set, set these bits to the same value as the initial|
|||||||value.|
|27|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|26|to|24|PLACE6|110|R/W|Place 6|
|||||||Stream data is rearranged after it is output from the MIX.|
|||||||These bits select data on the input side to be output to place 6 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 6 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 6 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 6 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 6 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 6 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 6 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 6 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 6 on the output|
|||||||side.|
|||||||Note: This bit setting is used when eight channels are set. When six or|
|||||||less channels are set, set these bits to the same value as the initial|
|||||||value.|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|23|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|22|to|20|PLACE5|101|R/W|Place 5|
|||||||Stream data is rearranged after it is output from the MIX.|
|||||||These bits select data on the input side to be output to place 5 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 5 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 5 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 5 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 5 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 5 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 5 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 5 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 5 on the output|
|||||||side.|
|||||||Note: This bit setting is used when six or more channels are set. When|
|||||||four or less channels are set, set these bits to the same value as|
|||||||the initial value.|
|19|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|18|to|16|PLACE4|100|R/W|Place 4|
|||||||Stream data is rearranged after it is output from the MIX.|
|||||||These bits select data on the input side to be output to place 4 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 4 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 4 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 4 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 4 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 4 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 4 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 4 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 4 on the output|
|||||||side.|
|||||||Note: This bit setting is used when six or more channels are set. When|
|||||||four or less channels are set, set these bits to the same value as|
|||||||the initial value.|
|15|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|

|||||**Initial**|||
|---|---|---|---|---|---|---|
|**Bit**|||**Bit Name**|**Value**|**R/W**|**Description**|
|14|to|12|PLACE3|011|R/W|Place 3|
|||||||Stream data is rearranged after it is output from the MIX.|
|||||||These bits select data on the input side to be output to place 3 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 3 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 3 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 3 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 3 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 3 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 3 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 3 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 3 on the output|
|||||||side.|
|||||||Note: This bit setting is used when four or more channels are set. When|
|||||||two or less channels are set, set these bits to the same value as|
|||||||the initial value.|
|11|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|
|10|to|8|PLACE2|010|R/W|Place 2|
|||||||Stream data is rearranged after it is output from the MIX.|
|||||||These bits select data on the input side to be output to place 2 on the|
|||||||output side.|
|||||||000: Data at place 0 on the input side is output to place 2 on the output|
|||||||side.|
|||||||001: Data at place 1 on the input side is output to place 2 on the output|
|||||||side.|
|||||||010: Data at place 2 on the input side is output to place 2 on the output|
|||||||side.|
|||||||011: Data at place 3 on the input side is output to place 2 on the output|
|||||||side.|
|||||||100: Data at place 4 on the input side is output to place 2 on the output|
|||||||side.|
|||||||101: Data at place 5 on the input side is output to place 2 on the output|
|||||||side.|
|||||||110: Data at place 6 on the input side is output to place 2 on the output|
|||||||side.|
|||||||111: Data at place 7 on the input side is output to place 2 on the output|
|||||||side.|
|||||||Note: This bit setting is used when four or more channels are set. When|
|||||||two or less channels are set, set these bits to the same value as the|
|||||||initial value.|
|7|||—|0|R|Reserved|
|||||||This bit is always read as 0. The write value should always be 0.|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|6 to 4|PLACE1|001|R/W|Place 1|
|||||Stream data is rearranged after it is output from the MIX.|
|||||These bits select data on the input side to be output to place 1 on the|
|||||output side.|
|||||000: Data at place 0 on the input side is output to place 1 on the output|
|||||side.|
|||||001: Data at place 1 on the input side is output to place 1 on the output|
|||||side.|
|||||010: Data at place 2 on the input side is output to place 1 on the output|
|||||side.|
|||||011: Data at place 3 on the input side is output to place 1 on the output|
|||||side.|
|||||100: Data at place 4 on the input side is output to place 1 on the output|
|||||side.|
|||||101: Data at place 5 on the input side is output to place 1 on the output|
|||||side.|
|||||110: Data at place 6 on the input side is output to place 1 on the output|
|||||side.|
|||||111: Data at place 7 on the input side is output to place 1 on the output|
|||||side.|
|3|—|0|R|Reserved|
|||||This bit is always read as 0. The write value should always be 0.|
|2 to 0|PLACE0|000|R/W|Place 0|
|||||Stream data is rearranged after it is output from the MIX.|
|||||These bits select data on the input side to be output to place 0 on the|
|||||output side.|
|||||000: Data at place 0 on the input side is output to place 0 on the output|
|||||side.|
|||||001: Data at place 1 on the input side is output to place 0 on the output|
|||||side.|
|||||010: Data at place 2 on the input side is output to place 0 on the output|
|||||side.|
|||||011: Data at place 3 on the input side is output to place 0 on the output|
|||||side.|
|||||100: Data at place 4 on the input side is output to place 0 on the output|
|||||side.|
|||||101: Data at place 5 on the input side is output to place 0 on the output|
|||||side.|
|||||110: Data at place 6 on the input side is output to place 0 on the output|
|||||side.|
|||||111: Data at place 7 on the input side is output to place 0 on the output|
|||||side.|

## 37.4 Operation

## 37.4.1 Initial Setting Procedure

Figure 37.6 to Figure 37.8 show the initial setting procedure of the SCUX. For details on register setting, refer to section 37.3, Register Descriptions .

## 37.4.2 Transfer Start Procedure and Stop Procedure

Figure 37.9 to Figure 37.11 show the transfer start procedure and stop procedure of the SCUX. For details on register setting, refer to section 37.3, Register Descriptions .

**==> picture [401 x 523] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start of setting<br>Use SSIFn?<br>(n = 0 to 5) NO<br>YES<br>SSIFn independent<br>transfer? NO<br>YES<br>See Figures 19.23, 19.24,<br>19.25, and 19.26 in Section<br>19 (SSIF Specifications)<br>Set the registers of the SSIFn to be used.<br>Set the SSIFn registers 1) SSITDMR<br>Notes: Set CONT = 1 in master mode.<br>Set the TDM bit for each SSIF to the same<br>value to handle three SSIF modules as six<br>channels.<br>2) SSICR (Set bits other than TEN and REN)<br>Notes: For details, see Section 19 (SSIF<br>Specifications).<br>Set the same value for each SSIF to to handle<br>three SSIF modules as six channels (except<br>the SCKD and SWSD bits).<br>1) SWRSR_CIM.SWRST = 0 (Sets the software reset)<br><1> Software reset 2) SWRSR_CIM.SWRST = 1 (Clears the software reset)<br>Note: Not required after a hardware reset.<br>1) FFDPR_FFD0_n, FFUPR_FFU0_n (n = 0, 1, 2, 3)<br><2> Set the transfer route 2) IPSLR_IPC0_n, OPSLR_OPC0_n (n = 0, 1, 2, 3)<br>3) SSIRSEL_CIM<br>Note: For 1) to 3), see Section 37.4.5.<br>4) SRCRSELn_CIM (n = 0, 1, 2, 3), MIXRSEL_CIM<br>Note: See Section 37.4.3.<br>5) SSICTRL_CIM<br>Note: Set bits other than SSI012TEN and SSI012REN.<br>· FDTSELn_CIM, FUTSELn_CIM (n = 0, 1, 2, 3)<br><3> Set the timing Note: See Section 37.4.6.<br>Set bits other than DIVEN.<br>· SSIPMD_CIM<br><4> Set the SSIF pins<br>Note: See Section 37.4.4.<br>Continues to (2)<br>SSIF setting<br>SCUX setting<br>**----- End of picture text -----**<br>

**Figure 37.6 Initial Setting Procedure of SCUX (1)**

**==> picture [324 x 404] intentionally omitted <==**

**----- Start of picture text -----**<br>
Continues from (1)<br>Use FFD0_n?<br>(n = 0, 1, 2, 3) NO<br>Set the registers of the FFD0_n to be used.<br>YES  1) FDAIR_FFD0_n, DRQSR_FFD0_n (n = 0, 1, 2, 3)<br>2) DEVMR_FFD0_n (n = 0, 1, 2, 3)<br><5> Set the FFD0_n registers     (Set the DEVMRQ bit to 0 at transfer by the DMAC and to 1 at<br>     transfer by an interrupt.)<br>Note: Set FFDBR_FFD0_n and FFDIR_FFD0_ at the transfer start.<br>Use FFU0_n?<br>(n = 0, 1, 2, 3) NO<br>Set the registers of the FFU0_n to be used.<br>YES  1) FUAIR_FFU0_n, URQSR_FFU0_n (n = 0, 1, 2, 3)<br>2) UEVMR_FFU0_n (n = 0, 1, 2, 3)<br><6> Set the FFU0_n registers     (Set the UEVMRQ bit to 0 at transfer by the DMAC<br>     and to 1 at transfer by an interrupt.)<br>Note: Set FFUIR_FFD0_n at the transfer start.<br>Use SRCn?<br>(n = 0, 1, 2, 3) NO<br>YES  Set the registers of the SRCn to be used.<In bypass mode><br>· SRCBRp_2SRC0_m (m = 0, 1; p = 0, 1)<br><7> Set the SRCn registers<br><Other than bypass mode><br>1) SADIRp_2SRC0_m, IFSCRp_2SRC0_m,<br>     IFSVRp_2SRC0_m, SRCCRp_2SRC0_m,<br>     MNFSRp_2SRC0_m, BFSSRp_2SRC0_m,<br>     WATSRp_2SRC0_m (m = 0, 1; p = 0, 1)<br>2) SEVMRp_2SRC0_m (m = 0, 1; p = 0, 1)<br>Note: Set SRCIRp_2SRC0_m and<br>          SRCIRR_2SRC0_m at the transfer start.<br>Use DVU0_n?<br>(n = 0, 1, 2, 3) NO  Set the registers of the DVU0_n to be used.<br>YES  <In bypass mode><br>· VADIR_DVU0_n, DVUBR_DVU0_n (n = 0, 1, 2, 3)<br><8> Set the DVUn registers <Other than bypass mode><br>1) VADIR_DVU0_n, DVUCR_DVU0_n,<br>    VRCTR_DVU0_n, VRPDR_DVU0_n,<br>    VRDBR_DVU0_n, VOL*R_DVU0_n,<br>    ZCMCR_DVU0_n, VRWTR_DVU0_n<br>    (n = 0, 1, 2, 3; * = 0 to 7)<br>2) VEVMR_DVU0_n (n = 0, 1, 2, 3)<br>Note: Set DVUIR_DVU0_n at the transfer start.<br>Continues to (3)<br>SCUX setting<br>**----- End of picture text -----**<br>

**Figure 37.7 Initial Setting Procedure of SCUX (2)**

**==> picture [292 x 199] intentionally omitted <==**

**----- Start of picture text -----**<br>
Continues from (2)<br>Use MIX?<br>NO<br>Set the registers of the MIX.<br>YES <In bypass mode><br>· MIXBR_MIX0_0<br><9> Set the MIX registers <Other than bypass mode><br>· MADIR_MIX0_0, MIXMR_MIX0_0, MVPDR_MIX0_0,<br>  MDBAR_MIX0_0, MDBBR_MIX0_0, MDBCR_MIX0_0,<br>  MDBDR_MIX0_0<br>Note: Set MIXIR_MIX0_0 at the transfer start.<br>Set up the interrupt controller<br>Note: See the interrupt<br>          controller specifications.<br>End of initial setting<br>SCUX setting<br>**----- End of picture text -----**<br>

**Figure 37.8 Initial Setting Procedure of SCUX (3)**

**==> picture [352 x 558] intentionally omitted <==**

**----- Start of picture text -----**<br>
Start<br>Transfer start setting<br>Perform transfer<br>using DMAC? NO<br>YES<br>Set up the DMAC<br>Note: See the DMAC<br>          specifications.<br>Enable DMA transfer<br>Note: Set DMACR_CIM.<br>When FFD is used, cancel initialization of the FFD and execute boot. (n = 0 to 3)<br>1) FFDIR_FFD0_n (INIT bit = 0)<br>Clear initialization of FFD  2) FFDBR_FFD0_n (BOOT bit = 1)<br>and start boot<br>Cancel initialization of the blocks to be used<br>Note: INIT bit = 0<br>Clear initialization of FFU,  SRC: Asynchronous mode<br>SRC, DVU, MIX, IPC, and OPC 1) FFUIR_FFU0_n, SRCIRp_2SRC0_m, SRCIRR_2SRC0_m,<br>DVUIR_DVU0_n, MIXIR_MIX0_0, (n = 0, 1, 2, 3 m = 0, 1, p = 0, 1)<br>2) IPCIR_IPC0_n (n = 0, 1, 2, 3)<br>3) OPCIR_OPC0_n (n = 0, 1, 2, 3)<br>SRC: Synchronous mode<br>1) FFUIR_FFU0_n (n = 0, 1, 2, 3)<br>2) IPCIR_IPC0_n (n = 0, 1, 2, 3)<br>3) OPCIR_OPC0_n (n = 0, 1, 2, 3)<br>4) SRCIRp_2SRC0_m, SRCIRR_2SRC0_m, (m = 0, 1, p = 0, 1)<br>Set transmission and  When using SSIFn (n = 1 to 3) as the input (reception) and using the SSIFm<br>(m = 0) signal from the master for SSIFn (SSIPMD_CIM.SSInPMD = 2'b10)<br>reception to start<br>1) Set reception to start<br>• SSICRn.REN = 1<br> (n = 1 to 3)<br>2) Set transmission to start<br>• SSICTRL_CIM.SSI*TEN = 1 or SSICRm.TEN = 1<br> (* = 012, m = 0)<br>When using SSIFm (m = 0, 3) as the input (reception) and output<br>(transmission) and using SSIFm in full duplex mode<br>1) Set transmission and reception to start<br>• SSICRm.TEN = 1, SSICRm.REN = 1 (m = 0, 3)<br>Other cases<br> 1) Set transmission to start<br>When SSIF is used<br>• SSICTRL_CIM.SSI*TEN = 1 or SSICRn.TEN = 1<br> (* = 012, n = 0 to 3)<br>When FFU is used (asynchronous)<br>• FUTSELn_CIM.DIVEN = 1 (Uses the divider)<br>2)  Set reception to start<br>When SSIF is used<br>• SSICTRL_CIM.SSI*REN = 1 or SSICRn.REN = 1<br> (* = 012, n = 0 to 3)<br>When FFD is used (asynchronous)<br>• FDTSELn_CIM.DIVEN=1 (Uses the divider)<br>Wait for an interrupt  <1><br>Continues to (2)<br>Transfer start setting<br>**----- End of picture text -----**<br>

**Figure 37.9 Transfer Start Procedure and Stop Procedure of SCUX (1)**

**==> picture [308 x 389] intentionally omitted <==**

**----- Start of picture text -----**<br>
Continues from (1)<br>SRC interrupt? Interrupt by wait? Go to <1> in (1)<br>YES YES<br>NO  NO<br>Go to <1> in (3)<br>YES<br>DVU interrupt? Go to <1> in (1)<br>NO<br>FFD interrupt? YES Data write request? YES<br>NO  NO  Write data to DMATDn_CIM<br>Go to <1> in (3) for the requested size<br>Go to <1> in (1)<br>FFU interrupt? Data read request? YES<br>NO  NO  Read data from DMATUn_CIM<br>Go to <1> in (3) for the requested size<br>Go to <1> in (1)<br>Change the DVU parameters?<br>NO<br>Change the register settings of the DVU0_n to be used.<br>YES  1) DVUER_DVU0_0.DVUEN = 0<br>2) ZCMCR_DVU0_n setting<br>3) VRPDR_DVU0_n, VRDBR_DVU0_n, and VRWTR_DVU0_n<br>Change the DVU parameters     settings (n = 0, 1, 2, 3)<br>4) VOL*R_DVU0_n (n = 0, 1, 2, 3; * = 0 to 7) setting<br>5) DVUER_DVU0_0.DVUEN = 1<br>Change the MIX parameters?<br>NO<br>YES Change the register settings of the MIX.<br>1) MDBER_MIX0_0.MIXDBEN = 0<br>2) MDBAR_MIX0_0, MDBBR_MIX0_0, MDBCR_MIX0_0,<br>Change the MIX parameters     and MDBDR_MIX0_0 settings<br>3) MDBER_MIX0_0.MIXDBEN = 1<br>Transfer finished? NO  Go to <1> in (1)<br>YES<br>Continues to (3)<br>Transfer in progress<br>**----- End of picture text -----**<br>

**Figure 37.10 Transfer Start Procedure and Stop Procedure of SCUX (2)**

**==> picture [333 x 462] intentionally omitted <==**

**----- Start of picture text -----**<br>
Continues from (2)<br><1><br>Flush the internal<br>memory data? NO<br>YES When SSIF is used<br>· SSITDMRn.RXDMUTE = 1 (n = 0 to 3)<br>When FFD is used<br>Input the dummy data · Input the necessary zero data.<br>Output of necessary<br>data completed? NO<br>YES<br>When SSIF is used<br>· SSICTRL_CIM.SSI*TEN = 0 or SSICRn.TEN = 0<br>(* = 012; n = 0 to 3)<br>· OPCIR_OPC0_n.INIT = 1 (n = 0 to 3)<br>Set transmission to stop When FFU is used (n = 0 to 3)<br>· FUTSELn_CIM.DIVEN = 0 (uses the divider)<br>· OPCIR_OPC0_n.INIT = 1<br>· DMACR_CIM.DMAMDFFUn = 0 (uses a DMA transfer)<br>· DMA stops (uses a DMA transfer)<br>· UEVCR_FFU0_n.UEVCRQ = 0 (when UEVMR_FFU0_n.UEVMRQ = 1)<br>· FFUIR_FFU0_n.INIT = 1<br>When SSIF is used<br>· SSICTRL_CIM.SSI*REN = 0 or SSICRn.REN = 0<br>· SSITDMRn.RXDMUTE = 0<br>Set reception to stop (* = 012; n = 0 to 3)<br>· IPCIR_IPC0_n.INIT = 1 (n = 0 to 3)<br>When FFD is used (n = 0 to 3)<br>· FDTSELn_CIM.DIVEN = 0 (uses the divider)<br>· IPCIR_IPC0_n.INIT = 1<br>· FFDBR_FFD0_n.BOOT = 0<br>· DMACR_CIM.DMAMDFFDn = 0 (uses a DMA transfer)<br>· DMA stops (uses a DMA transfer)<br>· DEVCR_FFD0_n.DEVCRQ = 0 (when DEVMR_FFD0_n.DEVMRQ = 1)<br>· FFDIR_FFD0_n.INIT = 1<br>Initialize the used blocks.<br>Initialize SRC, DVU, and MIX Note: INIT bit = 1<br>· SRCIRp_2SRC0_m, SRCIRR_2SRC0_m, DVUIR_DVU0_n,<br>  MIXIR_MIX0_0 (n = 0, 1, 2, 3; m = 0, 1; p = 0, 1)<br>Confirm the SSIF idle state When SSIF is used<br>· Read SSISRn.IIRQ for confirmation (n = 0 to 3)<br>Resume transfer?<br>NO<br>YES<br>Return to transfer start setting* Software reset ·  SWRSR_CIM.SWRST = 0<br>End<br>Note  * When the FFD/FFU used once is reused without executing software reset, the number of times to write to/read from the FFD/FFU previously<br> should be set to the integral multiple of the number of FIFO stages.<br>Transfer stop setting<br>**----- End of picture text -----**<br>

**Figure 37.11 Transfer Start Procedure and Stop Procedure of SCUX (3)**

## 37.4.3 Data Rearrangement for Each Channel

Data can be rearranged independently for each channel in the SCUX. Data rearrangement can be performed immediately before input to the SRC and immediately after output from the MIX. Table 37.9 to Table 37.11 show definition of data places. Data rearrangement immediately before the SRC is performed as described in section 37.3.72, SRCn Route Select Register (SRCRSELn_CIM) (n = 0, 1, 2, 3) . Data rearrangement immediately after the MIX is performed as described in section 37.3.73, MIX Route Select Register (MIXRSEL_CIM) .

**Table 37.9 Definition of Data Places (1)**

|SSIF<br>Stereo (2 ch)|SSIWS0<br>SSIDATA0||Place 1|Place 1|Place 1|||||
|---|---|---|---|---|---|---|---|---|---|
|||||||||||
|||Place 0|Place 1|||||||
|||||||||||
|SSIF<br>Stereo3 (6 ch)|SSIWS0<br>SSIDATA0<br>SSIDATA1<br>SSIDATA2||Place 1<br>Place 3<br>Place 5|||||||
|||||||||||
|||Place 0|Place 1|||||||
|||||||||||
|||Place 2|Place 3|||||||
|||||||||||
|||Place 4|Place 5|||||||
|||||||||||
|SSIF<br>TDM (6 ch)|SSIWS0<br>SSIDATA0|||||Place 4<br>Place 5||||
|||||||||||
|||||||||||
|||Place 0|Place 1|Place 2|Place 3|Place 4|Place 5|||
|||||||||||
|SSIF<br>Multichannel (8 ch)|SSIWS0<br>SSIDATA0|||||Place 4<br>Place 5<br>Place 6<br>Place 7||||
|||||||||||
|||Place 0|Place 1|Place 2|Place 3|Place 4|Place 5|Place 6|Place 7|
|||||||||||

**Table 37.10 Definition of Data Places (2)**

|FFD0_n<br>DMATDn_CIM<br>32-bit access (2 ch)|1st write data<br>2nd write data<br>3rd write data<br>4th write data|31                      8<br>7         0<br>Place 0<br>0<br>Place 1<br>0<br>Place 0<br>0<br>Place 1<br>0|
|---|---|---|
|FFD0_n<br>DMATDn_CIM<br>16-bit access (2 ch)|1st write data<br>2nd write data<br>3rd write data<br>4th write data|31                     16<br>15       0<br>Place 0<br>0<br>Place 1<br>0<br>Place 0<br>0<br>Place 1<br>0|
|FFD0_n<br>DMATDn_CIM 32-bit<br>access (8 ch)|1st write data<br>2nd write data<br>3rd write data<br>4th write data<br>5th write data<br>6th write data<br>7th write data<br>8th write data|31                      8<br>7         0<br>Place 0<br>0<br>Place 1<br>0<br>Place 2<br>0<br>Place 3<br>0<br>Place 4<br>0<br>Place 5<br>0<br>Place 6<br>0<br>Place 7<br>0|
|FFU0_n<br>DMATUn_CIM 32-bit<br>access (2 ch)|1st read data<br>2nd read data<br>3rd read data<br>4th read data|31                      8<br>7         0<br>Place 0<br>0<br>Place 1<br>0<br>Place 0<br>0<br>Place 1<br>0|

**Table 37.11 Definition of Data Places (3)**

|FFU0_n<br>DMATUn_CIM 16-bit<br>access (2 ch)|1st read data<br>2nd read data<br>3rd read data<br>4th read data|31                     16<br>15       0<br>Place 0<br>-<br>Place 1<br>-<br>Place 0<br>-<br>Place 1<br>-|
|---|---|---|
|FFU0_n<br>DMATUn_CIM 32-bit<br>access (8 ch)|1st read data<br>2nd read data<br>3rd read data<br>4th read data<br>5th read data<br>6th read data<br>7th read data<br>8th read data|31                      8<br>7         0<br>Place 0<br>0<br>Place 1<br>0<br>Place 2<br>0<br>Place 3<br>0<br>Place 4<br>0<br>Place 5<br>0<br>Place 6<br>0<br>Place 7<br>0|

## 37.4.4 Pin Connection Specifications of SSIF

SSIF0 to SSIF3 can be operated in synchronization with the same SSISCK and SSIWS signals. The AUDIO_CLK input to the SSIF can be selected between external pins AUDIO_CLK and MLB_CLK. These settings are made as described in section 37.3.70, SSI Pin Mode Register (SSIPMD_CIM) . Figure 37.12 shows the pin connection specifications of each SSIF module.

**==> picture [285 x 231] intentionally omitted <==**

**----- Start of picture text -----**<br>
SSIPMD_CIM.SSI0CKS<br>SSIF0 AUDIO_CLK<br>audio_clk<br>MLB_CLK<br>sck_en/ws_en<br> sck_op/ws_op SSISCK0/SSIWS0<br>sck_ip/ws_ip<br>SSIPMD_CIM.<br>SSIF1 SSI1CKS<br>audio_clk<br>sck_en/ws_en<br> sck_op/ws_op SSISCK1/SSIWS1<br>sck_ip/ws_ip<br>SSIPMD_CIM.<br>SSIF2 SSI2CKS<br>audio_clk SSIPMD_CIM.SSI1PMD<br>sck_en/ws_en<br> sck_op/ws_op SSISCK2/SSIWS2<br>sck_ip/ws_ip<br>SSIPMD_CIM.<br>SSIF3 SSI3CKS<br>audio_clk SSIPMD_CIM.SSI2PMD<br>sck_en/ws_en<br> sck_op/ws_op SSISCK3/SSIWS3<br>sck_ip/ws_ip<br>SSIPMD_CIM.SSI3PMD<br>**----- End of picture text -----**<br>

**Figure 37.12 Pin Connection Specifications of SSIF**

## 37.4.5 Data Transfer Route

Table 37.12 to Table 37.14 list the data transfer routes that can be selected by the SCUX. Table 37.15 to Table 37.17 show the necessary register settings for selecting each transfer route.

The 2SRC0_m bypass register p and DVU0_n bypass register should be set appropriately to bypass the SRC and DVU, respectively.

## **Table 37.12 Data Transfer Routes (1)**

|**Route**|**No.**|**SSIF (SRC)**|**FFD**|**SRC + DVU**|**MIX**|**SSIF (DST)**|**FFU**|
|---|---|---|---|---|---|---|---|
|SSIFSRCSSIF|1|SSIF0|—|SRC0*1+ DVU0_0|—|SSIF0|—|
||2|SSIF0|—|SRC0*1+ DVU0_0|—|SSIF3|—|
||3|Reserved||||||
||4|SSIF3|—|SRC1*1+ DVU0_1|—|SSIF3|—|
||5|SSIF3|—|SRC1*1+ DVU0_1|—|SSIF0|—|
||6|Reserved||||||
||7|Reserved||||||
||8|Reserved||||||
||9|Reserved||||||
||10|Reserved||||||
|SSIFSRCFFU|1|SSIF0|—|SRC0*1|—|—|FFU0_0|
||2|SSIF012 (6 ch)|—|SRC0*1|—|—|FFU0_0|
||3|SSIF3|—|SRC1*1|—|—|FFU0_1|
||4|Reserved||||||
||5|SSIF1|—|SRC2*1|—|—|FFU0_2|
||6|Reserved||||||
||7|SSIF2|—|SRC3*1|—|—|FFU0_3|
||8|Reserved||||||

Note 1. Selectable only in asynchronous mode. Not selectable in synchronous mode.

**Table 37.13 Data Transfer Routes (2)**

|**Route**|**No.**|**SSIF (SRC)**|**FFD**|**SRC + DVU**|**MIX**|**SSIF (DST)**|**FFU**|
|---|---|---|---|---|---|---|---|
|SSIFSRCMIX<br>SSIF|1|SSIF0|—|SRC0*1+ DVU0_0|MIX|SSIF0|—|
||2|SSIF0|—|SRC0*1+ DVU0_0|MIX|SSIF3|—|
||3|Reserved||||||
||4|SSIF3|—|SRC1*1+ DVU0_1|MIX|SSIF3|—|
||5|SSIF3|—|SRC1*1+ DVU0_1|MIX|SSIF0|—|
||6|SSIF3|—|SRC1*1+ DVU0_1|MIX|SSIF012 (6 ch)|—|
||7|SSIF1|—|SRC2*1+ DVU0_2|MIX|SSIF0|—|
||8|SSIF1|—|SRC2*1+ DVU0_2|MIX|SSIF3|—|
||9|Reserved||||||
||10|Reserved||||||
||11|Reserved||||||
||12|Reserved||||||
||13|SSIF2|—|SRC3*1+ DVU0_3|MIX|SSIF0|—|
||14|SSIF2|—|SRC3*1+ DVU0_3|MIX|SSIF3|—|
||15|Reserved||||||
||16|Reserved||||||
||17|Reserved||||||
||18|Reserved||||||
|FFDSRCSSIF|1|—|FFD0_0|SRC0*1+ DVU0_0|—|SSIF0|—|
||2|—|FFD0_0|SRC0*1+ DVU0_0|—|SSIF012 (6 ch)|—|
||3|—|FFD0_0|SRC0*1+ DVU0_0|—|SSIF3|—|
||4|Reserved||||||
||5|—|FFD0_1|SRC1*1+ DVU0_1|—|SSIF3|—|
||6|Reserved||||||
||7|—|FFD0_1|SRC1*1+ DVU0_1|—|SSIF0|—|
||8|—|FFD0_1|SRC1*1+ DVU0_1|—|SSIF012 (6 ch)|—|
||9|—|FFD0_2|SRC2*1+ DVU0_2|—|SSIF1|—|
||10|Reserved||||||
||11|—|FFD0_3|SRC3*1+ DVU0_3|—|SSIF2|—|
||12|Reserved||||||

Note 1. Selectable only in asynchronous mode. Not selectable in synchronous mode.

**Table 37.14 Data Transfer Routes (3)**

|**Route**|**No.**|**SSIF (SRC)**|**FFD**|**SRC+DVU**|**MIX**|**SSIF (DST)**|**FFU**|
|---|---|---|---|---|---|---|---|
|FFDSRC<br>FFU|1|—|FFD0_0|SRC0 (Sync)|||FFU0_0|
||2|—|FFD0_0|SRC0 (Async)|||FFU0_0|
||3|—|FFD0_1|SRC1 (Sync)|||FFU0_1|
||4|—|FFD0_1|SRC1 (Async)|||FFU0_1|
||5|—|FFD0_2|SRC2 (Sync)|||FFU0_2|
||6|—|FFD0_2|SRC2 (Async)|||FFU0_2|
||7|—|FFD0_3|SRC3 (Sync)|||FFU0_3|
||8|—|FFD0_3|SRC3 (Async)|||FFU0_3|
|FFDSRC<br>MIXSSIF|1|—|FFD0_0|SRC0*1+ DVU0_0|MIX|SSIF0|—|
||2|—|FFD0_0|SRC0*1+ DVU0_0|MIX|SSIF012 (6 ch)|—|
||3|—|FFD0_0|SRC0*1+ DVU0_0|MIX|SSIF3|—|
||4|Reserved||||||
||5|—|FFD0_1|SRC1*1+ DVU0_1|MIX|SSIF0|—|
||6|—|FFD0_1|SRC1*1+ DVU0_1|MIX|SSIF012 (6 ch)|—|
||7|—|FFD0_1|SRC1*1+ DVU0_1|MIX|SSIF3|—|
||8|Reserved||||||
||9|—|FFD0_2|SRC2*1+ DVU0_2|MIX|SSIF0|—|
||10|—|FFD0_2|SRC2*1+ DVU0_2|MIX|SSIF012 (6 ch)|—|
||11|—|FFD0_2|SRC2*1+ DVU0_2|MIX|SSIF3|—|
||12|Reserved||||||
||13|—|FFD0_3|SRC3*1+ DVU0_3|MIX|SSIF0|—|
||14|—|FFD0_3|SRC3*1+ DVU0_3|MIX|SSIF012 (6 ch)|—|
||15|—|FFD0_3|SRC3*1+ DVU0_3|MIX|SSIF3|—|
||16|Reserved||||||

Note 1. Selectable only in asynchronous mode. Not selectable in synchronous mode.

**Table 37.15 Route Select Register Settings (1)**

|Route|No.|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|IPSLR_IPC0_n|OPSLR_OPC0<br>_n|FFDPR_FFD0<br>_n|FFUPR_FFU0<br>_n|SSIPMD_CIM|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||SISEL3|SISEL2|SISEL1|SISEL0|SOSEL3|SOSEL2|SOSEL1|SOSEL0|IPC_PASS_<br>SEL|OPC_PASS_<br>SEL|PASS|PASS|SSI012EN|
|SSIF<br>SRC<br>SSIF|1|-|-|-|00|-|-|-|00|001|001|00|00|0|
||2|-|-|-|00|01|-|-|-|001|001|00|00|0|
||3|Reserved|||||||||||||
||4|-|-|00|-|00|-|-|-|001|001|00|00|0|
||5|-|-|00|-|-|-|-|01|001|001|00|00|0|
||6|Reserved|||||||||||||
||7|Reserved|||||||||||||
||8|Reserved|||||||||||||
||9|Reserved|||||||||||||
||10|Reserved|||||||||||||
|SSIF<br>SRC<br>FFU|1|-|-|-|00|-|-|-|-|001|011|00|01|0|
||2|-|-|-|01|-|-|-|-|001|011|00|01|0|
||3|-|-|00|-|-|-|-|-|001|011|00|01|0|
||4||||||||||||||
||5|-|00|-|-|-|-|-|-|001|011|00|01|0|
||6||||||||||||||
||7|00|-|-|-|-|-|-|-|001|011|00|01|0|
||8|Reserved|||||||||||||

**Table 37.16 Route Select Register Settings (2)**

|Route|No.|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|IPSLR_IPC0_n|OPSLR_OPC0<br>_n|FFDPR_FFD0<br>_n|FFUPR_FFU0<br>_n|SSIPMD_CIM|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||SISEL3|SISEL2|SISEL1|SISEL0|SOSEL3|SOSEL2|SOSEL1|SOSEL0|IPC_PASS_<br>SEL|OPC_PASS_<br>SEL|PASS|PASS|SSI012EN|
|SSIF<br>SRC<br>MIX<br> <br>SSI|1|-|-|-|00|-|-|-|10|001|001|00|00|0|
||2|-|-|-|00|10|-|-|-|001|001|00|00|0|
||3|Reserved|||||||||||||
||4|-|-|00|-|10|-|-|-|001|001|00|00|0|
||5|-|-|00|-|-|-|-|10|001|001|00|00|0|
||6|-|-|00|-|-|11|11|10|001|001|00|00|1|
||7|-|00|-|-|-|-|-|10|001|001|00|00|0|
||8|-|00|-|-|10|-|-|-|001|001|00|00|0|
||9|Reserved|||||||||||||
||10|Reserved|||||||||||||
||11|Reserved|||||||||||||
||12|Reserved|||||||||||||
||13|00|-|-|-|-|-|-|10|001|001|00|00|0|
||14|00|-|-|-|10|-|-|-|001|001|00|00|0|
||15|Reserved|||||||||||||
||16|Reserved|||||||||||||
||17|Reserved|||||||||||||
||18|Reserved|||||||||||||
|FFD<br> SRC<br>SSIF|1|-|-|-|-|-|-|-|00|011|001|01|00|0|
||2|-|-|-|-|-|01|01|00|011|001|01|00|1|
||3|-|-|-|-|01|-|-|-|011|001|01|00|0|
||4|Reserved|||||||||||||
||5|-|-|-|-|00|-|-|-|011|001|01|00|0|
||6|Reserved|||||||||||||
||7|-|-|-|-|-|-|-|01|011|001|01|00|0|
||8|-|-|-|-|-|10|10|01|011|001|01|00|1|
||9|-|-|-|-|-|-|00|-|011|001|01|00|0|
||10|Reserved|||||||||||||
||11|-|-|-|-|-|00|-|-|011|001|01|00|0|
||12|Reserved|||||||||||||

**Table 37.17 Route Select Register Settings (3)**

|Route|No.|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|SSIRSEL_CIM|IPSLR_IPC0_n|OPSLR_OPC0<br>_n|FFDPR_FFD0<br>_n|FFUPR_FFU0<br>_n|SSIPMD_CIM|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||SISEL3|SISEL2|SISEL1|SISEL0|SOSEL3|SOSEL2|SOSEL1|SOSEL0|IPC_PASS_<br>SEL|OPC_PASS_<br>SEL|PASS|PASS|SSI012EN|
|FFDSRC<br>FFU|1|-|-|-|-|-|-|-|-|100|100|10|10|0|
||2|-|-|-|-|-|-|-|-|011|011|01|01|0|
||3|-|-|-|-|-|-|-|-|100|100|10|10|0|
||4|-|-|-|-|-|-|-|-|011|011|01|01|0|
||5|-|-|-|-|-|-|-|-|100|100|10|10|0|
||6|-|-|-|-|-|-|-|-|011|011|01|01|0|
||7|-|-|-|-|-|-|-|-|100|100|10|10|0|
||8|-|-|-|-|-|-|-|-|011|011|01|01|0|
|FFDSRC<br>MIXSSIF|1|-|-|-|-|-|-|-|10|011|001|01|00|0|
||2|-|-|-|-|-|11|11|10|011|001|01|00|1|
||3|-|-|-|-|10|-|-|-|011|001|01|00|0|
||4|Reserved|||||||||||||
||5|-|-|-|-|-|-|-|10|011|001|01|00|0|
||6|-|-|-|-|-|11|11|10|011|001|01|00|1|
||7|-|-|-|-|10|-|-|-|011|001|01|00|0|
||8|Reserved|||||||||||||
||9|-|-|-|-|-|-|-|10|011|001|01|00|0|
||10|||||-|11|11|10|011|001|01|00|1|
||11|||||10|-|-|-|011|001|01|00|0|
||12|Reserved|||||||||||||
||13|||||-|-|-|10|011|001|01|00|0|
||14|||||-|11|11|10|011|001|01|00|1|
||15|||||10|-|-|-|011|001|01|00|0|
||16|Reserved|||||||||||||

## 37.4.6 Input Timing Signal and Output Timing Signal

The input timing signal and output timing signal need to be set when using the SRC or MIX. Table 37.18 to Table 37.20 show the input/output timing setting necessary for each transfer route in Table 37.12 to Table 37.14 . When direct connection between the SRC and SSIF is selected, the WS signal of the relevant SSIF is automatically selected regardless of the setting of the FFD0_n/FFU0_n timing select register. When direct connection between the MIX and SSIF is selected, set the prescribed value in the FFU0_n timing select register. When connection between the FFD and SRC or connection between the SRC and FFU is selected, a desired value can be set in the FFD0_n/FFU0_n timing select register and timing signals corresponding to the setting are used.

## **Table 37.18 Input/Output Timing Setting (1)**

|Route|No.|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||SSICTRL_CIM||||FDTSELn_<br>CIM|Input Timing<br>Signal|SSICTRL_CIM||||FUTSELn_<br>CIM|Output<br>Timing Signal|
|||SSI3RX|SSI2RX|SSI1RX|SSI0RX|||SSI3TX|SSI2TX|SSI1TX|SSI0TX|||
|SSIFSRC<br>SSIF|1|—|—|—|1|Setting unnecessary|SSIWS0*1|0*2|—|—|1|Setting unnecessary|SSIWS0*1|
||2|—|—|—|1|Setting unnecessary|SSIWS0*1|1|—|—|0*2|Setting unnecessary|SSIWS3*1|
||3|Reserved||||||||||||
||4|1|—|—|—|Setting unnecessary|SSIWS3*1|1|—|—|0*2|Setting unnecessary|SSIWS3*1|
||5|1|—|—|—|Setting unnecessary|SSIWS3*1|0*2|—|—|1|Setting unnecessary|SSIWS0*1|
||6|Reserved||||||||||||
||7|Reserved||||||||||||
||8|Reserved||||||||||||
||9|Reserved||||||||||||
||10|Reserved||||||||||||
|SSIFSRC<br>FFU|1|—|—|—|1|Setting unnecessary|SSIWS0*1|0*2|—|—|0*2|Arbitrary|←|
||2|—|—|—|1|Setting unnecessary|SSIWS0*1|0*2|—|—|0*2|Arbitrary|←|
||3|1|—|—|—|Setting unnecessary|SSIWS3*1|0*2|—|—|0*2|Arbitrary|←|
||4|Reserved||||||||||||
||5|—|—|1|—|Setting unnecessary|SSIWS1*1|—|—|0|—|Arbitrary|←|
||6|Reserved||||||||||||
||7|—|1|—|—|Setting unnecessary|SSIWS2*1|—|0*2|—|—|Arbitrary|←|
||8|Reserved||||||||||||

Note 1. Automatically selected regardless of the FDTSELn_CIM and FUTSELn_CIM settings.

Note 2. When connection to an SRCm for a given route is not being selected by the SOSELn bits of register SSIRSEL_CIM, SSInTX may be set to 1 (m = 0 to 3; n = 0 to 3).

**Table 37.19 Input/Output Timing Setting (2)**

|Route|No.|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||SSICTRL_CIM||||FDTSELn_CIM|Input Timing<br>Signal|SSICTRL_CIM||||FUTSELn_CIM|Output Timing<br>Signal|
|||SSI3RX|SSI2RX|SSI1RX|SSI0RX|||SSI3TX|SSI2TX|SSI1TX|SSI0TX|||
|SSIFSRC<br>MIXSSIF|1|—|—|—|1|Setting unnecessary|SSIWS0*1|0*3|—|—|1|SCKSEL: 1000|SSIWS0|
||2|—|—|—|1|Setting unnecessary|SSIWS0*1|1|—|—|0*3|SCKSEL: 1011|SSIWS3|
||3|Reserved||||||||||||
||4|1|—|—|—|Setting unnecessary|SSIWS3*1|1|—|—|0*3|SCKSEL: 1011|SSIWS3|
||5|1|—|—|—|Setting unnecessary|SSIWS3*1|0*3|—|—|1|SCKSEL: 1000|SSIWS0|
||6|1|—|—|—|Setting unnecessary|SSIWS3*1|0*3|—|—|1|SCKSEL: 1000|SSIWS0|
||7|—|—|1|—|Setting unnecessary|SSIWS1*1|0*4|—|0*2|1|SCKSEL: 1000|SSIWS0|
||8|—|—|1|—|Setting unnecessary|SSIWS1*1|1|—|0*2|0*4|SCKSEL: 1011|SSIWS3|
||9|Reserved||||||||||||
||10|Reserved||||||||||||
||11|Reserved||||||||||||
||12|Reserved||||||||||||
||13|—|1|—|—|Setting unnecessary|SSIWS2*1|0*4|0*2|—|1|SCKSEL: 1000|SSIWS0|
||14|—|1|—|—|Setting unnecessary|SSIWS2*1|1|0*2|—|0*4|SCKSEL: 1011|SSIWS3|
||15|Reserved||||||||||||
||16|Reserved||||||||||||
||17|Reserved||||||||||||
||18|Reserved||||||||||||
|FFDSRC<br>SSIF|1|—|—|—|0|Arbitrary|←|0*2|—|—|1|Setting unnecessary|SSIWS0*1|
||2|—|—|—|0|Arbitrary|←|0*2|—|—|1|Setting unnecessary|SSIWS0*1|
||3|—|—|—|0|Arbitrary|←|1|—|—|0*2|Setting unnecessary|SSIWS3*1|
||4|Reserved||||||||||||
||5|0|—|—|—|Arbitrary|←|1|—|—|0*2|Setting unnecessary|SSIWS3*1|
||6|Reserved||||||||||||
||7|0|—|—|—|Arbitrary|←|0*2|—|—|1|Setting unnecessary|SSIWS0*1|
||8|0|—|—|—|Arbitrary|←|0*2|—|—|1|Setting unnecessary|SSIWS0*1|
||9|—|—|0|—|Arbitrary|←|—|—|1|—|Setting unnecessary|SSIWS1*1|
||10|Reserved||||||||||||
||11|—|0|—|—|Arbitrary|←|—|1|—|—|Setting unnecessary|SSIWS2*1|
||12|Reserved||||||||||||

Note 1. Automatically selected regardless of the FDTSELn_CIM and FUTSELn_CIM settings.

Note 2. When connection to an SRCm for a given route is not being selected by the SOSELn bits of register SSIRSEL_CIM, SSInTX may be set to 1 (m = 0 to 3; n = 0 to 3).

Note 3. When connection to SRCm and MIX for a given route is not being selected by the SOSELn bits of register SSIRSEL_CIM, SSInTX may be set to 1 (m = 0 to 3; n = 0, 3).

Note 4. When connection to a MIX for a given route is not being selected by the SOSELn bits of register SSIRSEL_CIM, SSInTX may be set to 1 (n = 0, 3).

**Table 37.20 Input/Output Timing Setting (3)**

|Route|No.|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Input Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|Output Timing Setting|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||SSICTRL_CIM||||FDTSELn_CIM|Input Timing<br>Signal|SSICTRL_CIM||||FUTSELn_CIM|Output Timing<br>Signal|
|||SSI3RX|SSI2RX|SSI1RX|SSI0RX|||SSI3TX|SSI2TX|SSI1TX|SSI0TX|||
|FFDSRC<br>FFU|1|—|—|—|—|—|Unnecessary|—|—|—|—|—|Unnecessary|
||2|—|—|—|0|Arbitrary|←|0*2|—|—|0*2|Arbitrary|←|
||3|—|—|—|—|—|Unnecessary|—|—|—|—|—|Unnecessary|
||4|0|—|—|—|Arbitrary|←|0*2|—|—|0*2|Arbitrary|←|
||5|—|—|—|—|—|Unnecessary|—|—|—|—|—|Unnecessary|
||6|—|—|0|—|Arbitrary|←|—|—|0*2|—|Arbitrary|←|
||7|—|—|—|—|—|Unnecessary|—|—|—|—|—|Unnecessary|
||8|—|0|—|—|Arbitrary|←|—|0*2|—|—|Arbitrary|←|
|FFDSRC<br>MIXSSIF|1|—|—|—|0|Arbitrary|←|0*3|—|—|1|SCKSEL: 1000|SSIWS0|
||2|—|—|—|0|Arbitrary|←|0*3|—|—|1|SCKSEL: 1000|SSIWS0|
||3|—|—|—|0|Arbitrary|←|1|—|—|0*3|SCKSEL: 1011|SSIWS3|
||4|||||||Reserved||||||
||5|0|—|—|—|Arbitrary|←|0*3|—|—|1|SCKSEL: 1000|SSIWS0|
||6|0|—|—|—|Arbitrary|←|0*3|—|—|1|SCKSEL: 1000|SSIWS0|
||7|0|—|—|—|Arbitrary|←|1|—|—|0*3|SCKSEL: 1011|SSIWS3|
||8|||||||Reserved||||||
||9|—|—|0|—|Arbitrary|←|0*4|—|0*2|1|SCKSEL: 1000|SSIWS0|
||10|—|—|0|—|Arbitrary|←|0*4|—|0*2|1|SCKSEL: 1000|SSIWS0|
||11|—|—|0|—|Arbitrary|←|1|—|0*2|0*4|SCKSEL: 1011|SSIWS3|
||12|||||||Reserved||||||
||13|—|0|—|—|Arbitrary|←|0*4|0*2|—|1|SCKSEL: 1000|SSIWS0|
||14|—|0|—|—|Arbitrary|←|0*4|0*2|—|1|SCKSEL: 1000|SSIWS0|
||15|—|0|—|—|Arbitrary|←|1|0*2|—|0*4|SCKSEL: 1011|SSIWS3|
||16|||||||Reserved||||||

Note 1. Automatically selected regardless of the FDTSELn_CIM and FUTSELn_CIM settings. Note 2. When connection to an SRCm for a given route is not being selected by the SOSELn bits of register SSIRSEL_CIM, SSInTX may be set to 1 (m = 0 to 3; n = 0 to 3). Note 3. When connection to SRCm and MIX for a given route is not being selected by the SOSELn bits of register SSIRSEL_CIM, SSInTX may be set to 1 (m = 0 to 3; n = 0, 3).

Note 4. When connection to a MIX for a given route is not being selected by the SOSELn bits of register SSIRSEL_CIM, SSInTX may be set to 1 (n = 0, 3).

## 37.4.7 2SRC (SRC) Block

The 2SRC block consists of two SRCs (Sampling Rate Converters) which implement the sampling rate conversion function. Each SRC has two modes allowing either synchronous or asynchronous sampling rate conversion to be performed.

- [1]

- Asynchronous or synchronous sampling rate conversion is possible

- [2]

- Sampling rate (synchronous mode) Input [KHz]: 8, 11.025, 12, 16, 22.05, 24, 32, 44.1, 48, 64, 88.2, or 96 is selectable Output [KHz]: 8, 16, 24, 32, 44.1, 48, or 96 is selectable

- [2]

- Sampling rate (asynchronous mode) Input/output [KHz]: 1 to 96

- The supported number of bits is 16 bits and 24 bits

- Sound quality:  132 dB or less *[3]

- [4]

- Supports 1, 2, 4, 6, or 8 channels

- DMA transfer with on-chip memory or external memory and direct transfer with the SSIF module are possible

Note 1. The synchronous mode can be selected only when the SCUX is connected to the FFD and FFU modules. Note 2. The selectable sampling rates depend on the number of used channels and rate ratio. Note 3. The data format is a 24-bit value. Note 4. The number of selectable channels depends on the sampling rate and route.

Figure 37.13 shows a block diagram of the 2SRC (SRC) block. Input audio data indicates the data before executing the SRC function and output audio data indicates the data after executing the SRC function.

In synchronous SRC mode, the 2SRC (SRC) block outputs the input request signal to the FFD block and outputs the output request signal to the FFU block. In asynchronous SRC mode, the 2SRC (SRC) block receives the input timing signal and output timing signal from an external module and automatically detects the input sampling rate and output sampling rate from these timing signals.

Each SRC in the 2SRC (SRC) block can simultaneously process audio data for a maximum of eight channels. However, the maximum sampling rate that can be handled depends on the number of channels used. When SRC2 or SRC3 is used by the route from the FFD or the route to the FFU, the maximum number of processable channels is two. The number of channels is set by SADIRp_2SRC0_m.CHNUM. When not in bypass mode (SRCBRp_2SRC0_m.BYPASS = 0), unused channels always output 0 after initialization (SRCIRp_2SRC0_m.INIT = 1) unless the CHNUM setting is changed. In bypass mode, the input audio data is output one cycle later in all channels regardless of the CHNUM setting.

The bit width of output audio data can be set to 16 bits or 24 bits by SADIRp_2SRC0_m.OTBL. For input audio data, audio data with the same bit width as the OTBL bit setting in Table 37.21 should be input.

**==> picture [392 x 284] intentionally omitted <==**

**----- Start of picture text -----**<br>
2SRC<br>SRC0/SRC2<br>INDATA RAM  DATA RAM<br>256 words × 24 bits 1024 words × 24 bits<br>Input request signal Output request signal<br>FFD* Input timing signal Output timing signal FFU*<br>IPC Control and operation unit OPC<br>Input audio data Output audio data<br>Input timing  24 bits × 8 ch 24 bits × 8 ch Output timing<br>signal signal<br>Input audio data COEF-ROM<br>24 bits × 8 ch 32768 words × 24 bits Output audio data24 bits × 8 ch<br>Input request signal Output request signal<br>FFD* Input timing signal Output timing signal FFU*<br>IPC Control and operation unit OPC<br>Input audio data Output audio data<br>Input timing  24 bits × 8 ch 24 bits × 8 ch Output timing<br>signal signal<br>Input audio data INDATA RAM  DATA RAM  Output audio data<br>24 bits × 8 ch 256 words × 24 bits 1024 words × 24 bits 24 bits × 8 ch<br>SRC1/SRC3<br>Note:  Up to eight channels for FFD0_0, FFD0_1, FFU0_0, and FFU0_1, and up to two channels for FFD0_2, FFD0_3, FFU0_2, and FFU0_3.<br>**----- End of picture text -----**<br>

**Figure 37.13 Block Diagram of 2SRC Block**

## **Table 37.21 Combinations of Bit Width of Input/Output Audio Data**

|**SADIRp_2SRC0_m.OTBL**|**Bit Width of Input Audio Data**|**Bit Width of Output Audio Data**|
|---|---|---|
|00000 = 24 bits|24 bits|24 bits|
|01000 = 16 bits|16 bits|16 bits|

Table 37.22 shows the functions of the 2SRC (SRC) block.

**Table 37.22 2SRC (SRC) Block Functions**

|Item|Performance|Performance|Performance|Performance|Performance|Performance|
|---|---|---|---|---|---|---|
|Type of SRC|Asynchronous SRC/synchronous SRC||||||
|Operation frequency|66 MHz||||||
|Delay mode|Normal||||Low delay 1|Low delay 2|
|Channel number|1 or 2|4|6|8|1 or 2|1 or 2|
|Sampling rate of<br>input source|8k to 96k<br>[Hz]|8k to 96k<br>[Hz]|8k to 66k<br>[Hz]|8k to 49k<br>[Hz]|8k to 96k<br>[Hz]|8k to 96k<br>[Hz]|
|Sampling rate of<br>output source|8k to 96k<br>[Hz]|8k to 96k<br>[Hz]|8k to 66k<br>[Hz]|8k to 49k<br>[Hz]|8k to 96k<br>[Hz]|8k to 96k<br>[Hz]|
|Ratio of input and<br>output sampling rate<br>(FSO/FSI)|16 to 0.125<br>[time]|16 to 0.25<br>[time]|16 to 0.375<br>[time]|16 to 0.5<br>[time]|16 to 0.5<br>[time]|16 to 1<br>[time]|
|Sound quality|132 dB||||||

Table 37.23 shows the latency of the 2SRC (SRC) block.

**Table 37.23 2SRC (SRC) Block Latency**

|Item|Bypass|Normal|Normal|Normal|Normal|Normal|Low Delay 1|Low Delay 1|Low Delay 2|Low Delay 2|
|---|---|---|---|---|---|---|---|---|---|---|
|Channel number|Any|1|2|4|6|8|1|2|1|2|
|Processing delay|0|641|321|161|102|81|81|81|49|49|
|Logic delay|1|3|3|3|3|3|3|3|3|3|
|Output delay|Output delay [sample] = (Processing delay) * (FSO/FSI ratio) + (Logic delay)||||||||||

## 37.4.8 DVU Block

The DVU block is used to control volume and mute. This block can simultaneously process data for a maximum of eight channels.

- Digital volume, volume ramp, and zero cross mute are provided as functions to adjust the volume

- The digital volume is set as a 24-bit fixed-point value within the range from a multiple of 0 to 8 (mute,  120 to 18 dB)

- Volume ramp can be used to perform soft mute, fade in, fade out, and volume change as desired

- The ramp time of volume ramp can be changed and set within the sampling range of 2[0] to 2[23]

- Zero cross mute turns the sound mute at the zero cross point of audio data

- Direct transfer with the SSIF module and transfer with the mixer are possible

The number of channels is set by VADIR_DVU0_n.CHNUM. For unused channels, the input data that is input to the corresponding channels is output one cycle later. In bypass mode, the input data is output one cycle later in all channels regardless of the CHNUM setting.

Figure 37.14 shows the processing image of the DVU block.

**==> picture [286 x 57] intentionally omitted <==**

**----- Start of picture text -----**<br>
Volume ramp<br>Input data Zero cross mute - Soft mute Digital volume Output data<br>- Fade in<br>- Fade out<br>- Volume up<br>- Volume down<br>**----- End of picture text -----**<br>

**Figure 37.14 Processing Image of DVU Block**

Table 37.24 shows the functions of the DVU block.

**Table 37.24 DVU Block Functions**

|**Item**|**Performance**|
|---|---|
|Digital volume|Range:120 dB to 18 dB|
||(9.510-7-time to 8-time)|
|Volume ramp|Volume ramp use for many kinds of operation (soft mute, fade in, fade out, volume change by ramp)|
||Ramp time: 20/fso to 223/fso|
||Example:|
||(          1/fso:128 dB/1 step)|
||(          2/fso:64 dB/1 step)|
||(          4/fso:32 dB/1 step)|
||∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙|
||(      128/fso:1 dB/1 step)|
||(      256/fso:0.5 dB/1 step)|
||(      512/fso:0.25 dB/1 step)|
||(    1024/fso:0.125 dB/1 step)|
||(    2048/fso:0.125 dB/2 steps)|
||(    4096/fso:0.125 dB/4 steps)|
||∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙|
||( 8388608/fso:0.125 dB/8192 steps)|
|Zero cross mute|Mute the signal at zero cross point|

Figure 37.15 shows the image of digital volume operation.

**==> picture [436 x 251] intentionally omitted <==**

**----- Start of picture text -----**<br>
DVUBR_DVU0_n.BYPASS = 0<br>DVUCR_DVU0_n.VVMD = 1 (digital volume mode)<br>VOL0R_DVU0_n.VOLVALm (m = arbitrary value from 0 to 7): 24'H10_0000 (0 dB) → 24'H05_0F45 (-10 dB)<br>(1) (2) (3) (4)<br>Input data<br>8388606<br>0<br>-8388606<br>Output data<br>8388606<br>0<br>-8388606<br>**----- End of picture text -----**<br>

**Figure 37.15 Digital Volume Operation**

## **Operation**

- (1) In the initialized state (DVUIR_DVU0_n.INIT = 1), set the VVMD bit in DVUCR_DVU0_n to 1 (digital volume mode) and the VOLVALm bit in VOL0R_DVU0_n to 24'H10_0000 (0 dB). Until the initialized state is cleared, the DVU does not start operation and its output data is 0.

- (2) When the initialized state is cleared (DVUIR_DVU0_n.INIT = 0), the DVU starts operation. Since the VOLVALm bit is set to 0 dB, the output data is the same size as the input data.

- (3) Set the DVUEN bit in DVUER_DVU0_n to 0 and the VOLVAL0 bit in VOL0R_DVU0_n to 24'H05_0F45 (-10 dB).

- (4) The setting to the VOLVAL0 bit in (3) is enabled by setting the DVUEN bit in DVUER_DVU0_n to 1. The output data is the value obtained by attenuating the input data by -10 dB.

Figure 37.16 shows the image of volume ramp operation.

**==> picture [339 x 325] intentionally omitted <==**

**----- Start of picture text -----**<br>
DVUBR_DVU0_n.BYPASS = 0<br>DVUCR_DVU0_n.VRMD = 1 (volume ramp mode)<br>VRWTR_DVU0_n.VRWT = 24’H00_113A (4410 samples, ramp down)<br>VRWTR_DVU0_n.VRWT = 24’H00_0000 (0 samples, ramp up)<br>VRPDR_DVU0_n.VRPDUP = 5’H0C (0.125 dB/4 steps)<br>VRPDR_DVU0_n.VRPDDW = 5’H0F (0.125 dB/32 steps)<br>At ramp down: 0 dB → -12.5 dB, at ramp up: -12.5 dB → 0 dB<br>Sampling rate: 44.1 kHz<br>(1) (3) (7)<br>(5) (6) (9)<br>Input data<br>8388606<br>0<br>-8388606<br>Output data<br>8388606<br>0<br>-8388606<br>(2) (4) (8)<br>**----- End of picture text -----**<br>

**Figure 37.16 Volume Ramp Operation**

## **Operation**

- (1) In the initialized state (DVUIR_DVU0_n.INIT = 1), set the VRMD bit in DVUCR_DVU0_n to 1 (volume ramp mode) and the VRENm (m: arbitrary value from 0 to 7) bit in VRCTR_DVU0_n to 1. Until the initialized state is cleared, the DVU does not start operation and its output data is 0.

- (2) When the initialized state is cleared (DVUIR_DVU0_n.INIT = 0), the DVU starts operation.

   - Note: Changes to the settings of the VRDB bit of the VRDBR_DVU0_n register made in the INIT state rapidly become applicable on release from the INIT state (independently of the setting of VRWTR_DVU0_n and VRPDR_DVU0_n).

- (3) Set the DVUEN bit in DVUER_DVU0_n to 0, the VRPDDW bit in VRPDR_DVU0_n to 5'H0F (0.125 dB/32 steps), the VRDB bit in VRDBR_DVU0_n to 10'H064 (-12.5 dB), and the VRWT bit in VRWTR_DVU0_n to 24'H00_113A (4410 samples).

- (4) The setting in (3) is enabled by setting the DVUEN bit in DVUER_DVU0_n to 1.

- (5) The VDU waits to start the volume ramp operation for 4410/44100 = 0.1 second because the sampling rate is set to 44.1 kHz with VRWTR_DVU0_n.VRWT = 24'H00_113A (4410 samples).

- (6) The VDU starts volume ramp operation after the wait time in (5). The output data is the value obtained by attenuating the input data by -12.5 dB after 12.5 × 32/0.125 = 3200 steps because the VRPDDW bit in VRPDR_DVU0_n is set to 5'H0F (0.125 dB/32 steps) according to 0d B to -12.5 dB ramp down.

- (7) Set the DVUEN bit in DVUER_DVU0_n to 0, the VRPDUP bit in VRPDR_DVU0_n to 5'H0C (0.125 dB/4 steps), the VRDB bit in VRDBR_DVU0_n to 10'H000 (0 dB), and the VRWT bit in VRWTR_DVU0_n to 24'H00_0000 (0 sample).

- (8) The setting in (7) is enabled by setting the DVUEN bit in DVUER_DVU0_n to 1.

- (9) The VDU starts volume ramp operation without delay because the VRWT bit in VRWTR_DVU0_n is set to 24'H00_0000 (0 sample).

The output data is the same size as the input data after 12.5 × 4/0.125 = 400 steps because the VRPDUP bit in VRPDR_DVU0_n is set to 5'H0C (0.125 dB/4 steps) according to -12.5 dB to 0 dB ramp up.

Table 37.25 shows the latency of the DVU block.

## **Table 37.25 DVU Block Latency**

|**Item**|**Bypass**|**DVU Operation**|
|---|---|---|
|Output delay|1|2|

## 37.4.9 MIX Block

The MIX block is used to mix (add together) the input audio data from a maximum of four systems into one system. Each system can simultaneously process data for a maximum of eight channels.

- Data of two to four source systems can be mixed (added together) into one system

- The ratio to add the sources can be set

- The ratio can be changed dynamically

- Volume ramp enables mixing to be performed (ramp time is variable)

- Only direct transfer with the SSIF module is possible

The number of channels is set by MADIR_MIX0_0.CHNUM. When not in bypass mode (MIXBR_MIX0_0.BYPASS = 0), unused channels always output 0 after initialization (MIXIR_MIX0_0.INIT = 1) unless the CHNUM setting is changed. In bypass mode, the input data is output one cycle later in all channels regardless of the CHNUM setting. Figure 37.17 shows a block diagram of the MIX block.

**==> picture [302 x 229] intentionally omitted <==**

**----- Start of picture text -----**<br>
MIXMR_MIX0_0.MIXMODE<br>MDBAR_MIX0_0.MIXDBA<br>MDBBR_MIX0_0.MIXDBB Volume<br>MDBCR_MIX0_0.MIXDBC coefficient<br>MDBDR_MIX0_0.MIXDBD<br>Input data A (DVU0_0) <0 ch>: × Coef A + Output data <0 ch>:<br>Input data A (DVU0_0) <7 ch>: × Coef A + Output data <7 ch>:<br>Input data B (DVU0_1) <0 ch><br>: × Coef B<br>:<br>Input data B (DVU0_1) <7 ch><br>× Coef B<br>Input data C (DVU0_2) <0 ch><br>: × Coef C<br>:<br>Input data C (DVU0_2) <7 ch><br>× Coef C<br>Input data D (DVU0_3) <0 ch><br>: × Coef D<br>:<br>Input data D (DVU0_3) <7 ch><br>× Coef D<br>**----- End of picture text -----**<br>

**Figure 37.17 Block Diagram of MIX Block**

Table 37.26 shows the functions of the MIX block.

## **Table 37.26 MIX Block Functions**

|**Table 37.26**<br>**MIX Block**|**Functions**|
|---|---|
|**Item**|**Performance**|
|Volume step mixer|Mix the data of four systems into one system.|
||The volume of each system can be adjusted by step change.|
|Volume ramp mixer|Mix the data of four systems into one system.|
||The volume of each system can be adjusted by ramp.|

Figure 37.18 shows the image of volume step operation for 1-system data. This figure explains about the operation when the volume is changed from 0 dB to  dB. The volume can change the target dB for one step each. In the case of the volume step mixer, the volume of four systems can be adjusted at each step change (one sample).

Figure 37.19 shows the image of volume ramp operation for 1-system data. This figure explains about the operation when the volume is changed from 0 dB to  dB. The volume can be changed by 0.125-dB/step each and it takes 1024 samples to reach  dB in the maximum case for each system. In the case of the volume ramp mixer, the volume of four

systems can be adjusted at each ramp. In addition, the volume ramp mixer has a mechanism to reduce the noise. If the direction of volume is different among the four systems, it operates from the volume-down systems and after that operates on the volume-up systems automatically. In the case of the same direction, it changes the volume at the same timing.

**==> picture [173 x 94] intentionally omitted <==**

**----- Start of picture text -----**<br>
The point where the value<br>changes to -∞ dB<br>0 dB<br>-∞ dB<br>0 dB<br>1 sample<br>**----- End of picture text -----**<br>

**Figure 37.18 Volume Step Operation**

**==> picture [208 x 92] intentionally omitted <==**

**----- Start of picture text -----**<br>
The point where the value   The point where<br>starts to change to -∞ dB -∞ dB is reached<br>0 dB<br>-∞ dB<br>0 dB<br>1024 samples<br>**----- End of picture text -----**<br>

**Figure 37.19 Volume Ramp Operation**

Figure 37.20 shows the image of volume ramp operation for 4-system data.

**==> picture [353 x 579] intentionally omitted <==**

**----- Start of picture text -----**<br>
MIXBR_MIX0_0.BYPASS = 0<br>MIXMR_MIX0_0.MIXMODE = 1 (volume ramp mode)<br>MVPDR_MIX0_0.MXPDUP = 4'HA (0.125 dB/1 sample)<br>MVPDR_MIX0_0.MXPDDW = 4'HA (0.125 dB/1 sample)<br>At ramp down: 0 dB → -25 dB, at ramp up: 25 dB → 0 dB<br>(1) (3) (6)<br>(5) (8)<br>8388606<br>[Input data A] 0<br>-8388606<br>8388606<br>[Input data B] 0<br>-8388606<br>8388606<br>[Input data C] 0<br>-8388606<br>8388606<br>[Input data D] 0<br>-8388606<br>8388606<br>[Output data] 0<br>-8388606<br>(2) (4) (7)<br>**----- End of picture text -----**<br>

**Figure 37.20 Volume Ramp Operation for 4-System Data**

## **Operation**

- (1) In the initialized state (MIXIR_MIX0_0.INIT = 1), set the MIXMODE bit in MIXMR_MIX0_0 to 1 (volume ramp mode) and the MXPDDW bit in MVPDR_MIX0_0 to 4'HA (0.125 dB/1 sample). Until the initialized state is cleared, the MIX does not start operation and its output data is 0.

- (2) When the initialized state is cleared (MIXIR_MIX0_0.INIT = 0), the MIX starts operation. Note: Changes to the settings of the MIXDBA bits of the MDBAR_MIX0_0 register, MIXDBB bits of the MDBBR_MIX0_0 register, MIXDBC bits of the MDBCR_MIX0_0 register, and MIXDBD bits of the MDBDR_MIX0_0 register made in the INIT state rapidly become applicable on release from the INIT state (independently of the setting of MVPDR_MIX0_0).

- (3) Set as follows: MDBER_MIX0_0.MIXDBEN = 0 MDBAR_MIX0_0.MIXDBA = 10'H0C8 (-25 dB) MDBBR_MIX0_0.MIXDBB = 10'H0C8 (-25 dB) MDBCR_MIX0_0.MIXDBC = 10'H0C8 (-25 dB) MDBDR_MIX0_0.MIXDBD = 10'H0C8 (-25 dB)

- (4) The setting in (3) is enabled by setting the MIXDBEN bit in MDBER_MIX0_0 to 1.

- (5) The output data is the value obtained by attenuating and mixing the input data of each system by -25 dB after 25/ 0.125 = 200 steps because the MXPDDW bit in MVPDR_MIX0_0 is set to 4'HA (0.125 dB/1 sample) according to 0 dB to -25 dB ramp down for each system.

- (6) Set as follows: MDBER_MIX0_0.MIXDBEN = 0 MDBAR_MIX0_0.MIXDBA = 10'H000 (0 dB) MDBBR_MIX0_0.MIXDBB = 10'H000 (0 dB) MDBCR_MIX0_0.MIXDBC = 10'H000 (0 dB) MDBDR_MIX0_0.MIXDBD = 10'H000 (0 dB)

- (7) The setting in (6) is enabled by setting the MIXDBEN bit in MDBER_MIX0_0 to 1.

- (8) The output data is the value obtained by boosting and mixing the input data of each system by 25 dB after 25/0.125 = 200 steps because the MXPDUP bit in MVPDR_MIX0_0 is set to 4'HA (0.125 dB/1 sample) according to -25 dB to 0 dB ramp up for each system.

Table 37.27 shows the latency of the MIX block.

## **Table 37.27 MIX Block Latency**

|**Item**|**Bypass**|**MIX Operation**|
|---|---|---|
|Output delay|1|2|

## 37.5 Usage Note

## 37.5.1 Software Reset

When initializing the internal circuits of this module by clearing the SWRST bit in the SWRSR_CIM register or setting the INIT bit in the IPCIR_IPC0_n, OPCIR_OPC0_n, FFDIR_FFD0_n, FFUIR_FFU0_n, SRCIRp_2SRC0_m, SRCIRR_2SRC0_m, DVUIR_DVU0_n, or MIXIR_MIX0_0 register, be sure to follow the procedures specified in section 37.4.1, Initial Setting Procedure or section 37.4.2, Transfer Start Procedure and Stop Procedure .
