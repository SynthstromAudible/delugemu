# 10. Multi-Function Timer Pulse Unit 2

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 342–526. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This LSI has an on-chip multi-function timer pulse unit 2 that comprises five 16-bit timer channels.

## 10.1 Features

- Maximum 16 pulse input/output lines

- Selection of eight counter input clocks for each channel

- The following operations can be set:

   - Waveform output at compare match

   - Input capture function

   - Counter clear operation

   - Multiple timer counters (TCNT) can be written to simultaneously

   - Simultaneous clearing by compare match and input capture is possible

   - Register simultaneous input/output is possible by synchronous counter operation

   - A maximum 12-phase PWM output is possible in combination with synchronous operation

- Buffer operation settable for channels 0, 3, and 4

- Phase counting mode settable independently for each of channels 1 and 2

- Cascade connection operation

- Fast access via internal 16-bit bus

- 25 interrupt sources

- Automatic transfer of register data

- A/D converter start trigger can be generated

- Module standby mode can be settable

- A total of six-phase waveform output, which includes complementary PWM output, and positive and negative phases of reset PWM output by interlocking operation of channels 3 and 4, is possible.

- AC synchronous motor (brushless DC motor) drive mode using complementary PWM output and reset PWM output is settable by interlocking operation of channels 0, 3, and 4, and the selection of two types of waveform outputs (chopping and level) is possible.

- In complementary PWM mode, interrupts at the crest and trough of the counter value and A/D converter start triggers can be skipped.

**Table 10.1 Functions of Multi-Function Timer Pulse Unit 2**

|**Item**<br>**Channel 0**<br>**Channel 1**<br>**Channel 2**<br>**Channel 3**<br>**Channel 4**|**Item**<br>**Channel 0**<br>**Channel 1**<br>**Channel 2**<br>**Channel 3**<br>**Channel 4**|
|---|---|
|Count clock<br>P0/1<br>P0/4<br>P0/16<br>P0/64<br>TCLKA<br>TCLKB<br>TCLKC<br>TCLKD<br>P0/1<br>P0/4<br>P0/16<br>P0/64<br>P0/256<br>TCLKA<br>TCLKB<br>P0/1<br>P0/4<br>P0/16<br>P0/64<br>P0/1024<br>TCLKA<br>TCLKB<br>TCLKC<br>P0/1<br>P0/4<br>P0/16<br>P0/64<br>P0/256<br>P0/1024<br>TCLKA<br>TCLKB<br>P0/1<br>P0/4<br>P0/16<br>P0/64<br>P0/256<br>P0/1024<br>TCLKA<br>TCLKB||
|General registers<br>TGRA_0<br>TGRB_0<br>TGRE_0<br>TGRA_1<br>TGRB_1<br>TGRA_2<br>TGRB_2<br>TGRA_3<br>TGRB_3<br>TGRA_4<br>TGRB_4||
|General registers/ buffer<br>registers<br>TGRC_0<br>TGRD_0<br>TGRF_0<br>—<br>—<br>TGRC_3<br>TGRD_3<br>TGRC_4<br>TGRD_4||
|I/O pins<br>TIOC0A<br>TIOC0B<br>TIOC0C<br>TIOC0D<br>TIOC1A<br>TIOC1B<br>TIOC2A<br>TIOC2B<br>TIOC3A<br>TIOC3B<br>TIOC3C<br>TIOC3D<br>TIOC4A<br>TIOC4B<br>TIOC4C<br>TIOC4D||
|Counter clear function<br>TGR compare<br>match or input<br>capture<br>TGR compare<br>match or input<br>capture<br>TGR compare<br>match or input<br>capture<br>TGR compare<br>match or input<br>capture<br>TGR compare<br>match or input<br>capture||
|Compare<br>match<br>output|0 output<br><br><br><br><br>|
||1 output<br><br><br><br><br>|
||Toggle<br>output<br><br><br><br><br>|
|Input capture function<br><br><br><br><br>||
|Synchronous operation<br><br><br><br><br>||
|PWM mode 1<br><br><br><br><br>||
|PWM mode 2<br><br><br><br>—<br>—||
|Complementary PWM<br>mode<br>—<br>—<br>—<br><br>||
|Reset PWM mode<br>—<br>—<br>—<br><br>||
|AC synchronous motor<br>drive mode<br><br>—<br>—<br><br>||
|Phase counting<br>mode<br>—<br><br><br>—<br>—||
|Buffer operation<br><br>—<br>—<br><br>||
|Activation of direct<br>memory access controller<br>TGR compare<br>match or input<br>capture<br>TGR compare<br>match or input<br>capture<br>TGR compare<br>match or input<br>capture<br>TGR compare<br>match or input<br>capture<br>TGR compare<br>match or input<br>capture and TCNT<br>overflow or<br>underflow||
|A/D converter start trigger<br>TGRA_0 compare<br>match or input<br>capture<br>TGRE_0 compare<br>match<br>TGRA_1 compare<br>match or input<br>capture<br>TGRA_2 compare<br>match or input<br>capture<br>TGRA_3 compare<br>match or input<br>capture<br>TGRA_4 compare<br>match or input<br>capture<br>TCNT_4 underflow<br>(trough) in<br>complementary<br>PWM mode||

|**Item**|**Channel 0**|**Channel 1**|**Channel 2**|**Channel 3**|**Channel 4**|
|---|---|---|---|---|---|
|Interrupt sources|7 sources|4 sources|4 sources|5 sources|5 sources|
||Compare match|Compare match|Compare match|Compare match|Compare match|
||or input capture|or input capture|or input capture|or input capture|or input capture|
||0A|1A|2A|3A|4A|
||Compare match|Compare match|Compare match|Compare match|Compare match|
||or input capture|or input capture|or input capture|or input capture|or input capture|
||0B|1B|2B|3B|4B|
||Compare match|Overflow|Overflow|Compare match|Compare match|
||or input capture|Underflow|Underflow|or input capture|or input capture|
||0C|||3C|4C|
||Compare match|||Compare match|Compare match|
||or input capture|||or input capture|or input capture|
||0D|||3D|4D|
||Compare match|||Overflow|Overflow or|
||0E||||underflow|
||Compare match|||||
||0F|||||
||Overflow|||||
|A/D converter start|—|—|—|—|A/D converter|
|request delaying function|||||start request at a|
||||||match between|
||||||TADCORA_4 and|
||||||TCNT_4|
||||||A/D converter|
||||||start request at a|
||||||match between|
||||||TADCORB_4 and|
||||||TCNT_4|
|Interrupt skipping function|—|—|—|Skips TGRA_3|Skips TCIV_4|
|||||compare match|interrupts|
|||||interrupts||

[Legend] : Available : Not available

Figure 10.1 shows a block diagram.

**==> picture [329 x 450] intentionally omitted <==**

**----- Start of picture text -----**<br>
Interrupt request signals<br>Channel 3: TGIA_3<br>Input/output pins   TGIB_3<br>Channel 3: TIOC3A   TGIC_3<br> TIOC3B   TGID_3<br> TIOC3C   TCIV_3<br> TIOC3D Channel 4: TGIA_4<br>Channel 4: TIOC4A   TGIB_4<br> TIOC4B   TGIC_4<br> TIOC4C   TGID_4<br> TIOC4D   TCIV_4<br>Clock input<br>Internal clock:      P0φ/1<br> P0φ/4 Peripheral  bus<br> P0φ/16<br>P0φ/64<br>P0φ/256 A/D converter conversion<br>P0φ/1024 start signal<br>External clock:  TCLKA<br> TCLKB<br> TCLKC<br> TCLKD<br>Interrupt request signals<br>Channel 0: TGIA_0<br>Input/output pins   TGIB_0<br>Channel 0: TIOC0A   TGIC_0<br>  TIOC0B   TGID_0<br>  TIOC0C TGIE_0<br>  TIOC0D TGIF_0<br>Channel 1: TIOC1A   TCIV_0<br>  TIOC1B Channel 1: TGIA_1<br>Channel 2: TIOC2A   TGIB_1<br>  TIOC2B   TCIV_1<br>  TCIU_1<br>Channel 2: TGIA_2<br>  TGIB_2<br>  TCIV_2<br>  TCIU_2<br>[Legend]<br>TSTR:   Timer start register  TCDR:    Timer cycle data register<br>TSYR:   Timer synchronous register  TCBR:    Timer cycle buffer register<br>TCR:     Timer control register  TDDR:    Timer dead time data register<br>TMDR:  Timer mode register  TGRA:    Timer general register A<br>TIOR:    Timer I/O control register  TGRB:    Timer general register B<br>TIORH:  Timer I/O control register H  TGRC:    Timer general register C<br>TIORL:  Timer I/O control register L  TGRD:    Timer general register D<br>TIER:     Timer interrupt enable register  TGRE:    Timer general register E<br>TGCR:   Timer gate control register  TGRF:    Timer general register F<br>TOER:   Timer output master enable register<br>TOCR:   Timer output control register<br>TSR:      Timer status register<br>TCNT:   Timer counter<br>TCNTS: Timer subcounter<br>TMDR TIORL TSR<br>Channel 3 TCNT TGRA TGRB TGRC TGRD<br>TCR TIORH TIER<br>4 TMDR TIORL TSR<br>Channel  TCNT TGRA TGRB TGRC TGRD<br>TCR TIORH TIER<br>Control logic for channels 3 and 4<br>TOCR TGCR<br>TCNTS TCDR TCBR TDDR<br>TOER<br>TSYR<br>Common Control logic BUS I/F<br>TSTR Module data bus<br>2 TMDR TSR<br>Channel  TCNT TGRA TGRB<br>TCR TIOR TIER<br>1 TMDR TSR<br>Channel  TCNT TGRA TGRB<br>TCR TIOR TIER<br>Control logic for channels 0 to 2<br>0 TMDR TIORL TSR<br>Channel  TCNT TGRA TGRB TGRC TGRD TGRE TGRF<br>TCR TIORH TIER<br>**----- End of picture text -----**<br>

**Figure 10.1 Block Diagram**

## 10.2 Input/Output Pins

Table 10.2 shows the pin configuration

## **Table 10.2 Pin Configuration**

|**Channel**|**Pin Name**<br>**I/O**<br>**Function**|
|---|---|
|Common|TCLKA<br>Input<br>External clock A input pin (Channel 1 phase counting mode A phase input)|
||TCLKB<br>Input<br>External clock B input pin (Channel 1 phase counting mode B phase input)|
||TCLKC<br>Input<br>External clock C input pin (Channel 2 phase counting mode A phase input)|
||TCLKD<br>Input<br>External clock D input pin (Channel 2 phase counting mode B phase input)|
|0|TIOC0A<br>I/O<br>TGRA_0 input capture input/output compare output/PWM output pin|
||TIOC0B<br>I/O<br>TGRB_0 input capture input/output compare output/PWM output pin|
||TIOC0C<br>I/O<br>TGRC_0 input capture input/output compare output/PWM output pin|
||TIOC0D<br>I/O<br>TGRD_0 input capture input/output compare output/PWM output pin|
|1|TIOC1A<br>I/O<br>TGRA_1 input capture input/output compare output/PWM output pin|
||TIOC1B<br>I/O<br>TGRB_1 input capture input/output compare output/PWM output pin|
|2|TIOC2A<br>I/O<br>TGRA_2 input capture input/output compare output/PWM output pin|
||TIOC2B<br>I/O<br>TGRB_2 input capture input/output compare output/PWM output pin|
|3|TIOC3A<br>I/O<br>TGRA_3 input capture input/output compare output/PWM output pin|
||TIOC3B<br>I/O<br>TGRB_3 input capture input/output compare output/PWM output pin|
||TIOC3C<br>I/O<br>TGRC_3 input capture input/output compare output/PWM output pin|
||TIOC3D<br>I/O<br>TGRD_3 input capture input/output compare output/PWM output pin|
|4|TIOC4A<br>I/O<br>TGRA_4 input capture input/output compare output/PWM output pin|
||TIOC4B<br>I/O<br>TGRB_4 input capture input/output compare output/PWM output pin|
||TIOC4C<br>I/O<br>TGRC_4 input capture input/output compare output/PWM output pin|
||TIOC4D<br>I/O<br>TGRD_4 input capture input/output compare output/PWM output pin|

Note: For the pin configuration in complementary PWM mode, see Table 10.52 in section 10.4.8, Complementary PWM Mode.

## 10.3 Register Descriptions

Table 10.3 shows the register configuration. To distinguish registers in each channel, an underscore and the channel number are added as a suffix to the register name; TCR for channel 0 is expressed as TCR_0.

## **Table 10.3 Register Configuration**

|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial value**<br>**Address**<br>**Access**<br>**Size**|
|---|---|
|0|Timer control register_0<br>TCR_0<br>R/W<br>H'00<br>H'FCFF0300<br>8|
||Timer mode register_0<br>TMDR_0<br>R/W<br>H'00<br>H'FCFF0301<br>8|
||Timer I/O control register H_0<br>TIORH_0<br>R/W<br>H'00<br>H'FCFF0302<br>8|
||Timer I/O control register L_0<br>TIORL_0<br>R/W<br>H'00<br>H'FCFF0303<br>8|
||Timer interrupt enable register_0<br>TIER_0<br>R/W<br>H'00<br>H'FCFF0304<br>8|
||Timer status register_0<br>TSR_0<br>R/W<br>H'C0<br>H'FCFF0305<br>8|
||Timer counter_0<br>TCNT_0<br>R/W<br>H'0000<br>H'FCFF0306<br>16|
||Timer general register A_0<br>TGRA_0<br>R/W<br>H'FFFF<br>H'FCFF0308<br>16|
||Timer general register B_0<br>TGRB_0<br>R/W<br>H'FFFF<br>H'FCFF030A<br>16|
||Timer general register C_0<br>TGRC_0<br>R/W<br>H'FFFF<br>H'FCFF030C<br>16|
||Timer general register D_0<br>TGRD_0<br>R/W<br>H'FFFF<br>H'FCFF030E<br>16|
||Timer general register E_0<br>TGRE_0<br>R/W<br>H'FFFF<br>H'FCFF0320<br>16|
||Timer general register F_0<br>TGRF_0<br>R/W<br>H'FFFF<br>H'FCFF0322<br>16|
||Timer interrupt enable register 2_0<br>TIER2_0<br>R/W<br>H'00<br>H'FCFF0324<br>8|
||Timer status register 2_0<br>TSR2_0<br>R/W<br>H'C0<br>H'FCFF0325<br>8|
||Timer buffer operation transfer mode register_0<br>TBTM_0<br>R/W<br>H'00<br>H'FCFF0326<br>8|
|1|Timer control register_1<br>TCR_1<br>R/W<br>H'00<br>H'FCFF0380<br>8|
||Timer mode register_1<br>TMDR_1<br>R/W<br>H'00<br>H'FCFF0381<br>8|
||Timer I/O control register_1<br>TIOR_1<br>R/W<br>H'00<br>H'FCFF0382<br>8|
||Timer interrupt enable register_1<br>TIER_1<br>R/W<br>H'00<br>H'FCFF0384<br>8|
||Timer status register_1<br>TSR_1<br>R/W<br>H'C0<br>H'FCFF0385<br>8|
||Timer counter_1<br>TCNT_1<br>R/W<br>H'0000<br>H'FCFF0386<br>16|
||Timer general register A_1<br>TGRA_1<br>R/W<br>H'FFFF<br>H'FCFF0388<br>16|
||Timer general register B_1<br>TGRB_1<br>R/W<br>H'FFFF<br>H'FCFF038A<br>16|
||Timer input capture control register<br>TICCR<br>R/W<br>H'00<br>H'FCFF0390<br>8|
|2|Timer control register_2<br>TCR_2<br>R/W<br>H'00<br>H'FCFF0000<br>8|
||Timer mode register_2<br>TMDR_2<br>R/W<br>H'00<br>H'FCFF0001<br>8|
||Timer I/O control register_2<br>TIOR_2<br>R/W<br>H'00<br>H'FCFF0002<br>8|
||Timer interrupt enable register_2<br>TIER_2<br>R/W<br>H'00<br>H'FCFF0004<br>8|
||Timer status register_2<br>TSR_2<br>R/W<br>H'C0<br>H'FCFF0005<br>8|
||Timer counter_2<br>TCNT_2<br>R/W<br>H'0000<br>H'FCFF0006<br>16|
||Timer general register A_2<br>TGRA_2<br>R/W<br>H'FFFF<br>H'FCFF0008<br>16|
||Timer general register B_2<br>TGRB_2<br>R/W<br>H'FFFF<br>H'FCFF000A<br>16|
|3|Timer control register_3<br>TCR_3<br>R/W<br>H'00<br>H'FCFF0200<br>8|
||Timer mode register_3<br>TMDR_3<br>R/W<br>H'00<br>H'FCFF0202<br>8|
||Timer I/O control register H_3<br>TIORH_3<br>R/W<br>H'00<br>H'FCFF0204<br>8|
||Timer I/O control register L_3<br>TIORL_3<br>R/W<br>H'00<br>H'FCFF0205<br>8|
||Timer interrupt enable register_3<br>TIER_3<br>R/W<br>H'00<br>H'FCFF0208<br>8|
||Timer status register_3<br>TSR_3<br>R/W<br>H'C0<br>H'FCFF022C<br>8|
||Timer counter_3<br>TCNT_3<br>R/W<br>H'0000<br>H'FCFF0210<br>16|
||Timer general register A_3<br>TGRA_3<br>R/W<br>H'FFFF<br>H'FCFF0218<br>16|
||Timer general register B_3<br>TGRB_3<br>R/W<br>H'FFFF<br>H'FCFF021A<br>16|

|**Channel**|**Register Name**<br>**Abbreviation**<br>**R/W**<br>**Initial value**<br>**Address**<br>**Access**<br>**Size**|
|---|---|
|3|Timer general register C_3<br>TGRC_3<br>R/W<br>H'FFFF<br>H'FCFF0224<br>16|
||Timer general register D_3<br>TGRD_3<br>R/W<br>H'FFFF<br>H'FCFF0226<br>16|
||Timer buffer operation transfer mode register_3<br>TBTM_3<br>R/W<br>H'00<br>H'FCFF0238<br>8|
|4|Timer control register_4<br>TCR_4<br>R/W<br>H'00<br>H'FCFF0201<br>8|
||Timer mode register_4<br>TMDR_4<br>R/W<br>H'00<br>H'FCFF0203<br>8|
||Timer I/O control register H_4<br>TIORH_4<br>R/W<br>H'00<br>H'FCFF0206<br>8|
||Timer I/O control register L_4<br>TIORL_4<br>R/W<br>H'00<br>H'FCFF0207<br>8|
||Timer interrupt enable register_4<br>TIER_4<br>R/W<br>H'00<br>H'FCFF0209<br>8|
||Timer status register_4<br>TSR_4<br>R/W<br>H'C0<br>H'FCFF022D<br>8|
||Timer counter_4<br>TCNT_4<br>R/W<br>H'0000<br>H'FCFF0212<br>16|
||Timer general register A_4<br>TGRA_4<br>R/W<br>H'FFFF<br>H'FCFF021C<br>16|
||Timer general register B_4<br>TGRB_4<br>R/W<br>H'FFFF<br>H'FCFF021E<br>16|
||Timer general register C_4<br>TGRC_4<br>R/W<br>H'FFFF<br>H'FCFF0228<br>16|
||Timer general register D_4<br>TGRD_4<br>R/W<br>H'FFFF<br>H'FCFF022A<br>16|
||Timer buffer operation transfer mode register_4<br>TBTM_4<br>R/W<br>H'00<br>H'FCFF0239<br>8|
||Timer A/D converter start request control register<br>TADCR<br>R/W<br>H'0000<br>H'FCFF0240<br>16|
||Timer A/D converter start request cycle set register<br>A_4<br>TADCORA_4<br>R/W<br>H'FFFF<br>H'FCFF0244<br>16|
||Timer A/D converter start request cycle set register<br>B_4<br>TADCORB_4<br>R/W<br>H'FFFF<br>H'FCFF0246<br>16|
||Timer A/D converter start request cycle set buffer<br>register A_4<br>TADCOBRA_4<br>R/W<br>H'FFFF<br>H'FCFF0248<br>16|
||Timer A/D converter start request cycle set buffer<br>register B_4<br>TADCOBRB_4<br>R/W<br>H'FFFF<br>H'FCFF024A<br>16|
|Common|Timer start register<br>TSTR<br>R/W<br>H'00<br>H'FCFF0280<br>8|
||Timer synchronous register<br>TSYR<br>R/W<br>H'00<br>H'FCFF0281<br>8|
||Timer read/write enable register<br>TRWER<br>R/W<br>H'01<br>H'FCFF0284<br>8|
|Common<br>to 3 and<br>4|<br>Timer output master enable register<br>TOER<br>R/W<br>H'C0<br>H'FCFF020A<br>8|
||Timer output control register 1<br>TOCR1<br>R/W<br>H'00<br>H'FCFF020E<br>8|
||Timer output control register 2<br>TOCR2<br>R/W<br>H'00<br>H'FCFF020F<br>8|
||Timer gate control register<br>TGCR<br>R/W<br>H80<br>H'FCFF020D<br>8|
||Timer cycle data register<br>TCDR<br>R/W<br>H'FFFF<br>H'FCFF0214<br>16|
||Timer dead time data register<br>TDDR<br>R/W<br>H'FFFF<br>H'FCFF0216<br>16|
||Timer subcounter<br>TCNTS<br>R<br>H'0000<br>H'FCFF0220<br>16|
||Timer cycle buffer register<br>TCBR<br>R/W<br>H'FFFF<br>H'FCFF0222<br>16|
||Timer interrupt skipping set register<br>TITCR<br>R/W<br>H'00<br>H'FCFF0230<br>8|
||Timer interrupt skipping counter<br>TITCNT<br>R<br>H'00<br>H'FCFF0231<br>8|
||Timer buffer transfer set register<br>TBTER<br>R/W<br>H'00<br>H'FCFF0232<br>8|
||Timer dead time enable register<br>TDER<br>R/W<br>H'01<br>H'FCFF0234<br>8|
||Timer waveform control register<br>TWCR<br>R/W<br>H'00<br>H'FCFF0260<br>8|
||Timer output level buffer register<br>TOLBR<br>R/W<br>H'00<br>H'FCFF0236<br>8|

## 10.3.1 Timer Control Register (TCR)

The TCR registers are 8-bit readable/writable registers that control the TCNT operation for each channel. This module has a total of five TCR registers, one each for channels 0 to 4. TCR register settings should be conducted only when TCNT operation is stopped.

||||Bit:|7|6<br>5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|
||||||CCLR[2:0]<br>CKEG[1:0]<br>TPSC[2:0]|||
|||Initial|value:|0|0<br>0<br>0<br>0<br>0<br>0|0||
||||R/W:|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**|||
|7 to 5|CCLR[2:0]|000|R/W||Counter Clear 0 to 2|||
||||||These bits select the TCNT counter clearing source. See Table 10.4 and Table|||
||||||10.5 for details.|||
|4, 3|CKEG[1:0]|00|R/W||Clock Edge 0 and 1|||
||||||These bits select the input clock edge. When the input clock is counted using|||
||||||both edges, the input clock period is halved||(e.g. P0/4 both edges = P0/2|
||||||rising edge). If phase counting mode is used on channels 1 and 2, this setting is|||
||||||ignored and the phase counting mode|setting has priority. Internal clock edge||
||||||selection is valid when the input clock|is P0/4 or slower. When P0/1, or the||
||||||overflow/underflow of another channel is selected for the input clock, although|||
||||||values can be written, counter operation compiles with the initial value.|||
||||||00: Count at rising edge|||
||||||01: Count at falling edge|||
||||||1x: Count at both edges|||
|2 to 0|TPSC[2:0]|000|R/W||Time Prescaler 0 to 2|||
||||||These bits select the TCNT counter clock. The clock source can be selected|||
||||||independently for each channel. See Table 10.6 to Table 10.9 for details.|||

[Legend]

x: Don't care

## **Table 10.4 CCLR0 to CCLR2 (Channels 0, 3, and 4)**

|**Channel**|**Bit 7**<br>**CCLR2**|**Bit 6**<br>**CCLR1**|**Bit 5**<br>**CCLR0**<br>**Description**|
|---|---|---|---|
|0, 3, 4|0|0|0<br>TCNT clearing disabled|
||||1<br>TCNT cleared by TGRA compare match/input capture|
|||1|0<br>TCNT cleared by TGRB compare match/input capture|
||||1<br>TCNT cleared by counter clearing for another channel performing synchronous<br>clearing/synchronous operation*1|
||1|0|0<br>TCNT clearing disabled|
||||1<br>TCNT cleared by TGRC compare match/input capture*2|
|||1|0<br>TCNT cleared by TGRD compare match/input capture*2|
||||1<br>TCNT cleared by counter clearing for another channel performing synchronous<br>clearing/synchronous operation*1|

Note 1. Synchronous operation is set by setting the SYNC bit in TSYR to 1.

Note 2. When TGRC or TGRD is used as a buffer register, TCNT is not cleared because the buffer register setting has priority, and compare match/input capture does not occur.

**Table 10.5 CCLR0 to CCLR2 (Channels 1 and 2)**

|**Channel**<br>**Bit 7**<br>**Reserved*2**|**Bit 6**<br>**CCLR1**|**Bit 5**<br>**CCLR0**<br>**Description**|
|---|---|---|
|1, 2<br>0|0|0<br>TCNT clearing disabled|
|||1<br>TCNT cleared by TGRA compare match/input capture|
||1|0<br>TCNT cleared by TGRB compare match/input capture|
|||1<br>TCNT cleared by counter clearing for another channel performing synchronous<br>clearing/synchronous operation*1|

Note 1. Synchronous operation is selected by setting the SYNC bit in TSYR to 1. Note 2. Bit 7 is reserved in channels 1 and 2. It is always read as 0 and cannot be modified.

**Table 10.6 TPSC0 to TPSC2 (Channel 0)**

|**Channel**|**Bit 2**<br>**TPSC2**|**Bit 1**<br>**TPSC1**|**Bit 0**<br>**TPSC0**<br>**Description**|
|---|---|---|---|
|0|0|0|0<br>Internal clock: counts on P0/1|
||||1<br>Internal clock: counts on P0/4|
|||1|0<br>Internal clock: counts on P0/16|
||||1<br>Internal clock: counts on P0/64|
||1|0|0<br>External clock: counts on TCLKA pin input|
||||1<br>External clock: counts on TCLKB pin input|
|||1|0<br>External clock: counts on TCLKC pin input|
||||1<br>External clock: counts on TCLKD pin input|

**Table 10.7 TPSC0 to TPSC2 (Channel 1)**

|**Channel**|**Bit 2**<br>**TPSC2**|**Bit 1**<br>**TPSC1**|**Bit 0**<br>**TPSC0**<br>**Description**|
|---|---|---|---|
|1|0|0|0<br>Internal clock: counts on P0/1|
||||1<br>Internal clock: counts on P0/4|
|||1|0<br>Internal clock: counts on P0/16|
||||1<br>Internal clock: counts on P0/64|
||1|0|0<br>External clock: counts on TCLKA pin input|
||||1<br>External clock: counts on TCLKB pin input|
|||1|0<br>Internal clock: counts on P0/256|
||||1<br>Counts on TCNT_2 overflow/underflow|

Note: This setting is ignored when channel 1 is in phase counting mode.

## **Table 10.8 TPSC0 to TPSC2 (Channel 2)**

|**Channel**|**Bit 2**<br>**TPSC2**|**Bit 1**<br>**TPSC1**|**Bit 0**<br>**TPSC0**<br>**Description**|
|---|---|---|---|
|2|0|0|0<br>Internal clock: counts on P0/1|
||||1<br>Internal clock: counts on P0/4|
|||1|0<br>Internal clock: counts on P0/16|
||||1<br>Internal clock: counts on P0/64|
||1|0|0<br>External clock: counts on TCLKA pin input|
||||1<br>External clock: counts on TCLKB pin input|
|||1|0<br>External clock: counts on TCLKC pin input|
||||1<br>Internal clock: counts on P0/1024|

Note: This setting is ignored when channel 2 is in phase counting mode.

**Table 10.9 TPSC0 to TPSC2 (Channels 3 and 4)**

|**Channel**|**Bit 2**<br>**TPSC2**|**Bit 1**<br>**TPSC1**|**Bit 0**<br>**TPSC0**<br>**Description**|
|---|---|---|---|
|3, 4|0|0|0<br>Internal clock: counts on P0/1|
||||1<br>Internal clock: counts on P0/4|
|||1|0<br>Internal clock: counts on P0/16|
||||1<br>Internal clock: counts on P0/64|
||1|0|0<br>Internal clock: counts on P0/256|
||||1<br>Internal clock: counts on P0/1024|
|||1|0<br>External clock: counts on TCLKA pin input|
||||1<br>External clock: counts on TCLKB pin input|

## 10.3.2 Timer Mode Register (TMDR)

The TMDR registers are 8-bit readable/writable registers that are used to set the operating mode of each channel. This module has five TMDR registers, one each for channels 0 to 4. TMDR register settings should be changed only when TCNT operation is stopped.

||||Bit:||7|6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||||-|BFE<br>BFB<br>BFA<br>MD[3:0]||
|||Initial|value:||0|0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:||R|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7|—|0|R|||Reserved||
|||||||This bit is always read as 0. The write value should always be 0.||
|6|BFE|0|R/W|||Buffer Operation E||
|||||||Specifies whether TGRE_0 and TGRF_0 are to operate in the normal way or to||
|||||||be used together for buffer operation.||
|||||||TGRF compare match is generated when TGRF is used as the buffer register.||
|||||||In channels 1 to 4, this bit is reserved. It is always read as 0 and the write value||
|||||||should always be 0.||
|||||||0: TGRE_0 and TGRF_0 operate normally||
|||||||1: TGRE_0 and TGRF_0 used together for buffer operation||
|5|BFB|0|R/W|||Buffer Operation B||
|||||||Specifies whether TGRB is to operate in the normal way, or TGRB and TGRD||
|||||||are to be used together for buffer operation. When TGRD is used as a buffer||
|||||||register, TGRD input capture/output compare is not generated in a mode other||
|||||||than complementary PWM. In channels 1 and 2, which have no TGRD, bit 5 is||
|||||||reserved. It is always read as 0 and cannot be modified.||
|||||||0: TGRB and TGRD operate normally||
|||||||1: TGRB and TGRD used together for buffer operation||
|4|BFA|0|R/W|||Buffer Operation A||
|||||||Specifies whether TGRA is to operate in the normal way, or TGRA and TGRC||
|||||||are to be used together for buffer operation. When TGRC is used as a buffer||
|||||||register, TGRC input capture/output compare is not generated in a mode other||
|||||||than complementary PWM. TGRC compare match is generated when in||
|||||||complementary PWM mode. When compare match for channel 4 occurs during||
|||||||the Tb period in complementary PWM mode, TGFC is set. Therefore, set the||
|||||||TGIEC bit in the timer interrupt enable register 4 (TIER_4) to 0.||
|||||||In channels 1 and 2, which have no TGRC, bit 4 is reserved. It is always read as||
|||||||0 and cannot be modified.||
|||||||0: TGRA and TGRC operate normally||
|||||||1: TGRA and TGRC used together for buffer operation||
|3 to 0|MD[3:0]|0000|R/W|||Modes 0 to 3||
|||||||These bits are used to set the timer operating mode.||
|||||||See Table 10.10 for details.||

**Table 10.10 Setting of Operation Mode by Bits MD0 to MD3**

|**Bit 3**<br>**MD3**|**Bit 2**<br>**MD2**|**Bit 1**<br>**MD1**|**Bit 0**<br>**MD0**<br>**Description**|
|---|---|---|---|
|0|0|0|0<br>Normal operation|
||||1<br>Setting prohibited|
|||1|0<br>PWM mode 1|
||||1<br>PWM mode 2*1|
||1|0|0<br>Phase counting mode 1*2|
||||1<br>Phase counting mode 2*2|
|||1|0<br>Phase counting mode 3*2|
||||1<br>Phase counting mode 4*2|
|1|0|0|0<br>Reset synchronous PWM mode*3|
||||1<br>Setting prohibited|
|||1|X<br>Setting prohibited|
||1|0|0<br>Setting prohibited|
||||1<br>Complementary PWM mode 1 (transmit at crest)*3|
|||1|0<br>Complementary PWM mode 2 (transmit at trough)*3|
||||1<br>Complementary PWM mode 3 (transmit at crest and trough)*3|

[Legend]

X: Don't care

Note 1. PWM mode 2 cannot be set for channels 3 and 4.

Note 2. Phase counting mode cannot be set for channels 0, 3, and 4.

Note 3. Reset synchronous PWM mode, complementary PWM mode can only be set for channel 3. When channel 3 is set to reset synchronous PWM mode or complementary PWM mode, the channel 4 settings become ineffective and automatically conform to the channel 3 settings. However, do not set channel 4 to reset synchronous PWM mode or complementary PWM mode. Reset synchronous PWM mode and complementary PWM mode cannot be set for channels 0, 1, and 2.

## 10.3.3 Timer I/O Control Register (TIOR)

The TIOR registers are 8-bit readable/writable registers that control the TGR registers. This module has a total of eight TIOR registers, two each for channels 0, 3, and 4, one each for channels 1 and 2.

TIOR should be set while TMDR is set in normal operation, PWM mode, or phase counting mode.

The initial output specified by TIOR is valid when the counter is stopped (the CST bit in TSTR is cleared to 0). Note also that, in PWM mode 2, the output at the point at which the counter is cleared to 0 is specified.

When TGRC or TGRD is designated for buffer operation, this setting is invalid and the register operates as a buffer register.

- TIORH_0, TIOR_1, TIOR_2, TIORH_3, TIORH_4

||||Bit:|7|6<br>5|4<br>3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|
||||||IOB[3:0]||IOA[3:0]||||
|||Initial|value:|0|0<br>0|0<br>0|0|0|0||
||||R/W:|R/W|R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W||
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 4|IOB[3:0]|0000|R/W||I/O Control|B0 to B3|||||
||||||Specify the|function of TGRB.|||||
||||||See the following tables.||||||
||||||TIORH_0:|Table 10.11|||||
||||||TIOR_1:|Table 10.13|||||
||||||TIOR_2:|Table 10.14|||||
||||||TIORH_3:|Table 10.15|||||
||||||TIORH_4:|Table 10.17|||||
|3 to 0|IOA[3:0]|0000|R/W||I/O Control|A0 to A3|||||
||||||Specify the|function of TGRA.|||||
||||||See the following tables.||||||
||||||TIORH_0:|Table 10.19|||||
||||||TIOR_1:|Table 10.21|||||
||||||TIOR_2:|Table 10.22|||||
||||||TIORH_3:|Table 10.23|||||
||||||TIORH_4:|Table 10.25|||||

- TIORL_0, TIORL_3, TIORL_4

||||Bit:|7|6<br>5|4<br>3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|
||||||IOD[3:0]||IOC[3:0]||||
|||Initial|value:|0|0<br>0|0<br>0|0|0|0||
||||R/W:|R/W|R/W<br>R/W|R/W<br>R/W|R/W|R/W|R/W||
|||**Initial**|||||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||||
|7 to 4|IOD[3:0]|0000|R/W||I/O Control|D0 to D3|||||
||||||Specify the|function of TGRD.|||||
||||||See the following tables.||||||
||||||TIORL_0:|Table 10.12|||||
||||||TIORL_3:|Table 10.16|||||
||||||TIORL_4:|Table 10.18|||||
|3 to 0|IOC[3:0]|0000|R/W||I/O Control|C0 to C3|||||
||||||Specify the|function of TGRC.|||||
||||||See the following tables.||||||
||||||TIORL_0:|Table 10.20|||||
||||||TIORL_3:|Table 10.24|||||
||||||TIORL_4:|Table 10.26|||||

**Table 10.11 TIORH_0 (Channel 0)**

|**Bit 7**<br>**IOB3**|**Bit 6**<br>**IOB2**|**Bit 5**<br>**IOB1**|**Bit 4**<br>**IOB0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRB_0 Function**|**TIOC0B Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|0|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|
||1|X|X||Capture input source is channel 1/count clock<br>Input capture at TCNT_1 count-up/count-down|

[Legend]

X: Don't care Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.12 TIORL_0 (Channel 0)**

|**Bit 7**<br>**IOD3**|**Bit 6**<br>**IOD2**|**Bit 5**<br>**IOD1**|**Bit 4**<br>**IOD0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRD_0 Function**|**TIOC0D Pin Function**|
|0|0|0|0|Output compare register*2|Output retained*1|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|0|0|0|Input capture register*2|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|
||1|X|X||Capture input source is channel 1/count clock<br>Input capture at TCNT_1 count-up/count-down|

[Legend]

X: Don't care

Note 1. After power-on reset, 0 is output until TIOR is set.

Note 2. When the BFB bit in TMDR_0 is set to 1 and TGRD_0 is used as a buffer register, this setting is invalid and input capture/output compare is not generated.

**Table 10.13 TIOR_1 (Channel 1)**

|**Bit 7**<br>**IOB3**|**Bit 6**<br>**IOB2**|**Bit 5**<br>**IOB1**|**Bit 4**<br>**IOB0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRB_1 Function**|**TIOC1B Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|0|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|
||1|X|X||Input capture at generation of TGRC_0 compare<br>match/input capture|

[Legend]

X: Don't care

Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.14 TIOR_2 (Channel 2)**

|**Bit 7**<br>**IOB3**|**Bit 6**<br>**IOB2**|**Bit 5**<br>**IOB1**|**Bit 4**<br>**IOB0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRB_2 Function**|**TIOC2B Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care

Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.15 TIORH_3 (Channel 3)**

|**Bit 7**<br>**IOB3**|**Bit 6**<br>**IOB2**|**Bit 5**<br>**IOB1**|**Bit 4**<br>**IOB0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRB_3 Function**|**TIOC3B Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.16 TIORL_3 (Channel 3)**

|**Bit 7**<br>**IOD3**|**Bit 6**<br>**IOD2**|**Bit 5**<br>**IOD1**|**Bit 4**<br>**IOD0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRD_3 Function**|**TIOC3D Pin Function**|
|0|0|0|0|Output compare register*2|Output retained*1|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register*2|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care

Note 1. After power-on reset, 0 is output until TIOR is set.

Note 2. When the BFB bit in TMDR_3 is set to 1 and TGRD_3 is used as a buffer register, this setting is invalid and input capture/output compare is not generated.

**Table 10.17 TIORH_4 (Channel 4)**

|**Bit 7**<br>**IOB3**|**Bit 6**<br>**IOB2**|**Bit 5**<br>**IOB1**|**Bit 4**<br>**IOB0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRB_4 Function**|**TIOC4B Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care

Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.18 TIORL_4 (Channel 4)**

|**Bit 7**<br>**IOD3**|**Bit 6**<br>**IOD2**|**Bit 5**<br>**IOD1**|**Bit 4**<br>**IOD0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRD_4 Function**|**TIOC4D Pin Function**|
|0|0|0|0|Output compare register*2|Output retained*1|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register*2|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care

Note 1. After power-on reset, 0 is output until TIOR is set.

Note 2. When the BFB bit in TMDR_4 is set to 1 and TGRD_4 is used as a buffer register, this setting is invalid and input capture/output compare is not generated.

**Table 10.19 TIORH_0 (Channel 0)**

|**Bit 3**<br>**IOA3**|**Bit 2**<br>**IOA2**|**Bit 1**<br>**IOA1**|**Bit 0**<br>**IOA0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRA_0 Function**|**TIOC0A Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|0|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|
||1|X|X||Capture input source is channel 1/count clock<br>Input capture at TCNT_1 count-up/count-down|

[Legend]

X: Don't care

Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.20 TIORL_0 (Channel 0)**

|**Bit 3**<br>**IOC3**|**Bit 2**<br>**IOC2**|**Bit 1**<br>**IOC1**|**Bit 0**<br>**IOC0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRC_0 Function**|**TIOC0C Pin Function**|
|0|0|0|0|Output compare register*2|Output retained*1|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|0|0|0|Input capture register*2|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|
||1|X|X||Capture input source is channel 1/count clock<br>Input capture at TCNT_1 count-up/count-down|

[Legend]

X: Don't care

Note 1. After power-on reset, 0 is output until TIOR is set.

Note 2. When the BFA bit in TMDR_0 is set to 1 and TGRC_0 is used as a buffer register, this setting is invalid and input capture/output compare is not generated.

**Table 10.21 TIOR_1 (Channel 1)**

|**Bit 3**<br>**IOA3**|**Bit 2**<br>**IOA2**|**Bit 1**<br>**IOA1**|**Bit 0**<br>**IOA0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRA_1 Function**|**TIOC1A Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|0|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|
||1|X|X||Input capture at generation of channel 0/TGRA_0<br>compare match/input capture|

[Legend]

X: Don't care

Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.22 TIOR_2 (Channel 2)**

|**Bit 3**<br>**IOA3**|**Bit 2**<br>**IOA2**|**Bit 1**<br>**IOA1**|**Bit 0**<br>**IOA0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRA_2 Function**|**TIOC2A Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.23 TIORH_3 (Channel 3)**

|**Bit 3**<br>**IOA3**|**Bit 2**<br>**IOA2**|**Bit 1**<br>**IOA1**|**Bit 0**<br>**IOA0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRA_3 Function**|**TIOC3A Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.24 TIORL_3 (Channel 3)**

|**Bit 3**<br>**IOC3**|**Bit 2**<br>**IOC2**|**Bit 1**<br>**IOC1**|**Bit 0**<br>**IOC0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRC_3 Function**|**TIOC3C Pin Function**|
|0|0|0|0|Output compare register*2|Output retained*1|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register*2|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care

Note 1. After power-on reset, 0 is output until TIOR is set.

Note 2. When the BFA bit in TMDR_3 is set to 1 and TGRC_3 is used as a buffer register, this setting is invalid and input capture/output compare is not generated.

**Table 10.25 TIORH_4 (Channel 4)**

|**Bit 3**<br>**IOA3**|**Bit 2**<br>**IOA2**|**Bit 1**<br>**IOA1**|**Bit 0**<br>**IOA0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRA_4 Function**|**TIOC4A Pin Function**|
|0|0|0|0|Output compare register|Output retained*|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care

Note: * After power-on reset, 0 is output until TIOR is set.

**Table 10.26 TIORL_4 (Channel 4)**

|**Bit 3**<br>**IOC3**|**Bit 2**<br>**IOC2**|**Bit 1**<br>**IOC1**|**Bit 0**<br>**IOC0**||**Description**|
|---|---|---|---|---|---|
|||||**TGRC_4 Function**|**TIOC4C Pin Function**|
|0|0|0|0|Output compare register*2|Output retained*1|
||||1||Initial output is 0<br>0 output at compare match|
|||1|0||Initial output is 0<br>1 output at compare match|
||||1||Initial output is 0<br>Toggle output at compare match|
||1|0|0||Output retained|
||||1||Initial output is 1<br>0 output at compare match|
|||1|0||Initial output is 1<br>1 output at compare match|
||||1||Initial output is 1<br>Toggle output at compare match|
|1|X|0|0|Input capture register*2|Input capture at rising edge|
||||1||Input capture at falling edge|
|||1|X||Input capture at both edges|

[Legend]

X: Don't care

Note 1. After power-on reset, 0 is output until TIOR is set.

Note 2. When the BFA bit in TMDR_4 is set to 1 and TGRC_4 is used as a buffer register, this setting is invalid and input capture/output compare is not generated.

## 10.3.4 Timer Interrupt Enable Register (TIER)

The TIER registers are 8-bit readable/writable registers that control enabling or disabling of interrupt requests for each channel. This module has six TIER registers, two for channel 0 and one each for channels 1 to 4.

- TIER_0, TIER_1, TIER_2, TIER_3, TIER_4

||||Bit:|7|6<br>5<br>4<br>3<br>2<br>1||0||
|---|---|---|---|---|---|---|---|---|
|||||TTGE|TTGE2 TCIEU<br>TCIEV<br>TGIED TGIEC<br>TGIEB|TGIEA|||
|||Initial|value:|0|0<br>0<br>0<br>0<br>0<br>0||0||
||||R/W:|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||||
|7|TTGE|0|R/W||A/D Conversion Start Request Enable||||
||||||Enables or disables generation of A/D conversion start requests by TGRA input||||
||||||capture/compare match.||||
||||||0: A/D converter start request generation disabled||||
||||||1: A/D converter start request generation enabled||||
|6|TTGE2|0|R/W||A/D Conversion Start Request Enable||2||
||||||Enables or disables generation of A/D conversion start requests by TCNT_4||||
||||||underflow (trough) in complementary|PWM||mode.|
||||||In channels 0 to 3, bit 6 is reserved. It||is always read as 0 and the write value||
||||||should always be 0.||||
||||||0: A/D conversion start request generation by TCNT_4 underflow (trough)||||
||||||disabled||||
||||||1: A/D conversion start request generation by TCNT_4 underflow (trough)||||
||||||enabled||||
|5|TCIEU|0|R/W||Underflow Interrupt Enable||||
||||||Enables or disables interrupt requests||(TCIU) by the TCFU flag when the TCFU||
||||||flag in TSR is set to 1 in channels 1 and 2.||||
||||||In channels 0, 3, and 4, bit 5 is reserved. It is always read as 0 and the write||||
||||||value should always be 0.||||
||||||0: Interrupt requests (TCIU) by TCFU disabled||||
||||||1: Interrupt requests (TCIU) by TCFU enabled||||
|4|TCIEV|0|R/W||Overflow Interrupt Enable||||
||||||Enables or disables interrupt requests||(TCIV) by the TCFV flag when the TCFV||
||||||flag in TSR is set to 1.||||
||||||0: Interrupt requests (TCIV) by TCFV disabled||||
||||||1: Interrupt requests (TCIV) by TCFV enabled||||
|3|TGIED|0|R/W||TGR Interrupt Enable D||||
||||||Enables or disables interrupt requests||(TGID) by the TGFD bit when the TGFD||
||||||bit in TSR is set to 1 in channels 0, 3,||and 4.||
||||||In channels 1 and 2, bit 3 is reserved.||It is always read as 0 and the write value||
||||||should always be 0.||||
||||||0: Interrupt requests (TGID) by TGFD||bit disabled||
||||||1: Interrupt requests (TGID) by TGFD||bit enabled||
|2|TGIEC|0|R/W||TGR Interrupt Enable C||||
||||||Enables or disables interrupt requests||(TGIC) by the TGFC bit when the TGFC||
||||||bit in TSR is set to 1 in channels 0, 3,||and 4.||
||||||In channels 1 and 2, bit 2 is reserved.||It is always read as 0 and the write value||
||||||should always be 0.||||
||||||0: Interrupt requests (TGIC) by TGFC||bit disabled||
||||||1: Interrupt requests (TGIC) by TGFC||bit enabled||
|1|TGIEB|0|R/W||TGR Interrupt Enable B||||
||||||Enables or disables interrupt requests||(TGIB) by the TGFB bit when the TGFB||
||||||bit in TSR is set to 1.||||
||||||0: Interrupt requests (TGIB) by TGFB bit disabled||||
||||||1: Interrupt requests (TGIB) by TGFB bit enabled||||

||||**Initial**||||||
|---|---|---|---|---|---|---|---|---|
|**Bit**||**Bit Name**|**Value**|**R/W**||**Description**|||
|0||TGIEA|0|R/W||TGR Interrupt Enable A|||
|||||||Enables or disables interrupt requests (TGIA) by the TGFA bit when the TGFA|||
|||||||bit in TSR is set to 1.|||
|||||||0: Interrupt requests (TGIA) by TGFA bit disabled|||
|||||||1: Interrupt requests (TGIA) by TGFA bit enabled|||
||TIER2_0||||||||
|||||Bit:|7|6<br>5<br>4<br>3<br>2<br>1|0||
||||||TTGE2|-<br>-<br>-<br>-<br>-<br>TGIEF|TGIEE||
||||Initial|value:|0|0<br>0<br>0<br>0<br>0<br>0|0||
|||||R/W:|R/W|R<br>R<br>R<br>R<br>R<br>R/W|R/W||
||||**Initial**||||||
|**Bit**||**Bit Name**|**Value**|**R/W**||**Description**|||
|7||TTGE2|0|R/W||A/D Converter Start Request Enable 2|||
|||||||Enables or disables generation of A/D converter start requests by compare|||
|||||||match between TCNT_0 and TGRE_0.|||
|||||||0: A/D converter start request generation by compare match between TCNT_0|||
|||||||and TGRE_0 disabled|||
|||||||1: A/D converter start request generation by compare match between TCNT_0|||
|||||||and TGRE_0 enabled|||
|6 to|2|—|All 0|R||Reserved|||
|||||||These bits are always read as 0. The write value should always be 0.|||
|1||TGIEF|0|R/W||TGR Interrupt Enable F|||
|||||||Enables or disables interrupt requests by compare match between TCNT_0 and|||
|||||||TGRF_0.|||
|||||||0: Interrupt requests (TGIF) by TGFE bit disabled|||
|||||||1: Interrupt requests (TGIF) by TGFE bit enabled|||
|0||TGIEE|0|R/W||TGR Interrupt Enable E|||
|||||||Enables or disables interrupt requests by compare match between TCNT_0 and|||
|||||||TGRE_0.|||
|||||||0: Interrupt requests (TGIE) by TGEE bit disabled|||
|||||||1: Interrupt requests (TGIE) by TGEE bit enabled|||

## 10.3.5 Timer Status Register (TSR)

The TSR registers are 8-bit readable/writable registers that indicate the status of each channel. This module has six TSR registers, two for channel 0 and one each for channels 1 to 4.

- TSR_0, TSR_1, TSR_2, TSR_3, TSR_4

|Bit:|7|6||5|4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|
||TCFD|-||TCFU|TCFV|TGFD|TGFC|TGFB|TGFA||
|Initial value:|1|1||0|0|0|0|0|0||
|R/W:|R|R|R/(W)*1R/(W)*1R/(W)*1R/(W)*1R/(W)*1R/(W)*1||||||||

Note: 1. Writing 0 to this bit after reading it as 1 clears the flag and is the only allowed way.

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|TCFD|1|R|Count Direction Flag|
|||||Status flag that shows the direction in which TCNT counts in channels 1 to 4.|
|||||In channel 0, bit 7 is reserved. It is always read as 1 and the write value should|
|||||always be 1.|
|||||0: TCNT counts down|
|||||1: TCNT counts up|
|6|—|1|R|Reserved|
|||||This bit is always read as 1. The write value should always be 1.|
|5|TCFU|0|R/(W)*1|Underflow Flag|
|||||Status flag that indicates that TCNT underflow has occurred when channels 1|
|||||and 2 are set to phase counting mode. Only 0 can be written, for flag clearing.|
|||||In channels 0, 3, and 4, bit 5 is reserved. It is always read as 0 and the write|
|||||value should always be 0.|
|||||[Clearing condition]|
|||||When 0 is written to TCFU after reading TCFU = 1*2|
|||||[Setting condition]|
|||||When the TCNT value underflows (changes from H'0000 to H'FFFF)|
|4|TCFV|0|R/(W)*1|Overflow Flag|
|||||Status flag that indicates that TCNT overflow has occurred. Only 0 can be|
|||||written, for flag clearing.|
|||||[Clearing condition]|
|||||When 0 is written to TCFV after reading TCFV = 1*2|
|||||[Setting condition]|
|||||When the TCNT value overflows (changes from H'FFFF to H'0000)|
|||||In channel 4, when the TCNT_4 value underflows (changes from H'0001 to|
|||||H'0000) in complementary PWM mode, this flag is also set.|
|3|TGFD|0|R/(W)*1|Input Capture/Output Compare Flag D|
|||||Status flag that indicates the occurrence of TGRD input capture or compare|
|||||match in channels 0, 3, and 4.|
|||||Only 0 can be written, for flag clearing. In channels 1 and 2, bit 3 is reserved. It is|
|||||always read as 0 and the write value should always be 0.|
|||||[Clearing condition]|
|||||When 0 is written to TGFD after reading TGFD = 1*2|
|||||[Setting conditions]|
|||||When TCNT = TGRD and TGRD is functioning as output compare register|
|||||When TCNT value is transferred to TGRD by input capture signal and TGRD|
|||||is functioning as input capture register|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|2|TGFC|0|R/(W)*1|Input Capture/Output Compare Flag C|
|||||Status flag that indicates the occurrence of TGRC input capture or compare|
|||||match in channels 0, 3, and 4. Only 0 can be written, for flag clearing. In|
|||||channels 1 and 2, bit 2 is reserved. It is always read as 0 and the write value|
|||||should always be 0.|
|||||[Clearing condition]|
|||||When 0 is written to TGFC after reading TGFC = 1*2|
|||||[Setting conditions]|
|||||When TCNT = TGRC and TGRC is functioning as output compare register|
|||||When TCNT value is transferred to TGRC by input capture signal and TGRC|
|||||is functioning as input capture register|
|1|TGFB|0|R/(W)*1|Input Capture/Output Compare Flag B|
|||||Status flag that indicates the occurrence of TGRB input capture or compare|
|||||match. Only 0 can be written, for flag clearing.|
|||||[Clearing condition]|
|||||When 0 is written to TGFB after reading TGFB = 1*2|
|||||[Setting conditions]|
|||||When TCNT = TGRB and TGRB is functioning as output compare register|
|||||When TCNT value is transferred to TGRB by input capture signal and TGRB|
|||||is functioning as input capture register|
|0|TGFA|0|R/(W)*1|Input Capture/Output Compare Flag A|
|||||Status flag that indicates the occurrence of TGRA input capture or compare|
|||||match. Only 0 can be written, for flag clearing.|
|||||[Clearing conditions]|
|||||When the direct memory access controller is activated by TGIA interrupt|
|||||When 0 is written to TGFA after reading TGFA = 1*2|
|||||[Setting conditions]|
|||||When TCNT = TGRA and TGRA is functioning as output compare register|
|||||When TCNT value is transferred to TGRA by input capture signal and TGRA|
|||||is functioning as input capture register|

Note 1. Writing 0 to this bit after reading it as 1 clears the flag.

Note 2. If the next flag is set before TGFA is cleared to 0 after reading TGFA = 1, TGFA remains 1 even when 0 is written to. In this case, read TGFA = 1 again to clear TGFA to 0.

##  TSR2_0

|||Bit:|7|6|5|4|3|2|1||0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||-|-|-|-|-|-|TGFF||TGFE||
|||Initial value:|1|1|0|0|0|0|0||0||
|||R/W:|R|R|R|R|R|R|R/(W)*1||R/(W)*1||
|Note:|1.|Writing 0 to this bit after reading it as 1 clears the flag|||||||and is the only allowed way.||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7, 6|—|All 1|R|Reserved|
|||||These bits are always read as 1. The write value should always be 1.|
|5 to 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1|TGFF|0|R/(W)*1|Compare Match Flag F|
|||||Status flag that indicates the occurrence of compare match between TCNT_0|
|||||and TGRF_0.|
|||||[Clearing condition]|
|||||When 0 is written to TGFF after reading TGFF = 1*2|
|||||[Setting condition]|
|||||When TCNT_0 = TGRF_0 and TGRF_0 is functioning as compare register|
|0|TGFE|0|R/(W)*1|Compare Match Flag E|
|||||Status flag that indicates the occurrence of compare match between TCNT_0|
|||||and TGRE_0.|
|||||[Clearing condition]|
|||||When 0 is written to TGFE after reading TGFE = 1*2|
|||||[Setting condition]|
|||||When TCNT_0 = TGRE_0 and TGRE_0 is functioning as compare register|

Note 1. Writing 0 to this bit after reading it as 1 clears the flag.

Note 2. If the next flag is set before TGFA is cleared to 0 after reading TGFA = 1, TGFA remains 1 even when 0 is written to. In this case, read TGFA = 1 again to clear TGFA to 0.

## 10.3.6 Timer Buffer Operation Transfer Mode Register (TBTM)

The TBTM registers are 8-bit readable/writable registers that specify the timing for transferring data from the buffer register to the timer general register in PWM mode. This module has three TBTM registers, one each for channels 0, 3, and 4.

||||Bit:||7|6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||||-|-<br>-<br>-<br>-<br>TTSE<br>TTSB<br>TTSA||
|||Initial|value:||0|0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:||R|R<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7 to 3|—|All 0|R|||Reserved||
|||||||These bits are always read as 0. The write value should always be 0.||
|2|TTSE|0|R/W|||Timing Select E||
|||||||Specifies the timing for transferring data from TGRF_0 to TGRE_0 when they||
|||||||are used together for buffer operation.||
|||||||In channels 3 and 4, bit 2 is reserved. It is always read as 0 and the write value||
|||||||should always be 0. Do not set this bit to 1 when PWM mode is not selected in||
|||||||channel 0.||
|||||||0: When compare match E occurs in channel 0||
|||||||1: When TCNT_0 is cleared||
|1|TTSB|0|R/W|||Timing Select B||
|||||||Specifies the timing for transferring data from TGRD to TGRB in each channel||
|||||||when they are used together for buffer operation. Do not set this bit to 1 when||
|||||||PWM mode is not selected in any channels.||
|||||||0: When compare match B occurs in each channel||
|||||||1: When TCNT is cleared in each channel||
|0|TTSA|0|R/W|||Timing Select A||
|||||||Specifies the timing for transferring data from TGRC to TGRA in each channel||
|||||||when they are used together for buffer operation. Do not set this bit to 1 when||
|||||||PWM mode is not selected in any channels.||
|||||||0: When compare match A occurs in each channel||
|||||||1: When TCNT is cleared in each channel||

## 10.3.7 Timer Input Capture Control Register (TICCR)

TICCR is an 8-bit readable/writable register that specifies input capture conditions when TCNT_1 and TCNT_2 are cascaded. This module has one TICCR in channel 1.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||-|-|-|-|I2BE|I2AE|I1BE|I1AE|
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7 to 4|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|3|I2BE|0|R/W|Input Capture Enable|
|||||Specifies whether to include the TIOC2B pin in the TGRB_1 input capture|
|||||conditions.|
|||||0: Does not include the TIOC2B pin in the TGRB_1 input capture conditions|
|||||1: Includes the TIOC2B pin in the TGRB_1 input capture conditions|
|2|I2AE|0|R/W|Input Capture Enable|
|||||Specifies whether to include the TIOC2A pin in the TGRA_1 input capture|
|||||conditions.|
|||||0: Does not include the TIOC2A pin in the TGRA_1 input capture conditions|
|||||1: Includes the TIOC2A pin in the TGRA_1 input capture conditions|
|1|I1BE|0|R/W|Input Capture Enable|
|||||Specifies whether to include the TIOC1B pin in the TGRB_2 input capture|
|||||conditions.|
|||||0: Does not include the TIOC1B pin in the TGRB_2 input capture conditions|
|||||1: Includes the TIOC1B pin in the TGRB_2 input capture conditions|
|0|I1AE|0|R/W|Input Capture Enable|
|||||Specifies whether to include the TIOC1A pin in the TGRA_2 input capture|
|||||conditions.|
|||||0: Does not include the TIOC1A pin in the TGRA_2 input capture conditions|
|||||1: Includes the TIOC1A pin in the TGRA_2 input capture conditions|

## 10.3.8 Timer A/D Converter Start Request Control Register (TADCR)

TADCR is a 16-bit readable/writable register that enables or disables A/D converter start requests and specifies whether to link A/D converter start requests with interrupt skipping operation. This module has one TADCR in channel 4.

||Bit:|Bit:|15|14||13|12||11|10<br>9<br>8<br>7<br>6<br>5<br>4|3|2|1|0||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||BF[1:0]|||-|-||-|-<br>-<br>-<br>UT4AE DT4AE UT4BE DT4BE|ITA3AE|ITA4VE|ITB3AE|ITB4VE||
||Initial value:||0|0||0|0||0|0<br>0<br>0<br>0<br>0*<br>0<br>0*|0*|0*|0*|0*||
||R/W:||R/W|R/W||R|R||R|R<br>R<br>R<br>R/W<br>R/W<br>R/W<br>R/W|R/W|R/W|R/W|R/W||
|||||**Initial**||||||||||||
|**Bit**|**Bit Name**|||**Value**||||**R/W**||**Description**||||||
|15, 14|BF[1:0]|||00||||R/W||TADCOBRA_4/TADCOBRB_4 Transfer Timing Select||||||
|||||||||||Select the timing for transferring data from TADCOBRA_4 and TADCOBRB_4 to||||||
|||||||||||TADCORA_4 and TADCORB_4.||||||
|||||||||||For details, see Table 10.27.||||||
|13 to 8|—|||All||0||R||Reserved||||||
|||||||||||These bits are always read as 0. The write value should|||always be 0.|||
|7|UT4AE|||0||||R/W||Up-Count TRG4AN Enable||||||
|||||||||||Enables or disables A/D converter start requests (TRG4AN) during TCNT_4 up-||||||
|||||||||||count operation.||||||
|||||||||||0: A/D converter start requests (TRG4AN) disabled during TCNT_4 up-count||||||
|||||||||||operation||||||
|||||||||||1: A/D converter start requests (TRG4AN) enabled during TCNT_4 up-count||||||
|||||||||||operation||||||
|6|DT4AE|||0*||||R/W||Down-Count TRG4AN Enable||||||
|||||||||||Enables or disables A/D converter start requests (TRG4AN) during TCNT_4||||||
|||||||||||down-count operation.||||||
|||||||||||0: A/D converter start requests (TRG4AN) disabled during TCNT_4 down-count||||||
|||||||||||operation||||||
|||||||||||1: A/D converter start requests (TRG4AN) enabled during TCNT_4 down-count||||||
|||||||||||operation||||||
|5|UT4BE|||0||||R/W||Up-Count TRG4BN Enable||||||
|||||||||||Enables or disables A/D converter start requests (TRG4BN) during TCNT_4 up-||||||
|||||||||||count operation.||||||
|||||||||||0: A/D converter start requests (TRG4BN) disabled during TCNT_4 up-count||||||
|||||||||||operation||||||
|||||||||||1: A/D converter start requests (TRG4BN) enabled during TCNT_4 up-count||||||
|||||||||||operation||||||
|4|DT4BE|||0*||||R/W||Down-Count TRG4BN Enable||||||
|||||||||||Enables or disables A/D converter start requests (TRG4BN) during TCNT_4||||||
|||||||||||down-count operation.||||||
|||||||||||0: A/D converter start requests (TRG4BN) disabled during TCNT_4 down-count||||||
|||||||||||operation||||||
|||||||||||1: A/D converter start requests (TRG4BN) enabled during TCNT_4 down-count||||||
|||||||||||operation||||||
|3|ITA3AE|||0*||||R/W||TGIA_3 Interrupt Skipping Link Enable||||||
|||||||||||Select whether to link A/D converter start requests (TRG4AN) with TGIA_3||||||
|||||||||||interrupt skipping operation.||||||
|||||||||||0: Does not link with TGIA_3 interrupt skipping||||||
|||||||||||1: Links with TGIA_3 interrupt skipping||||||
|2|ITA4VE|||0*||||R/W||TCIV_4 Interrupt Skipping Link Enable||||||
|||||||||||Select whether to link A/D converter start requests (TRG4AN) with TCIV_4||||||
|||||||||||interrupt skipping operation.||||||
|||||||||||0: Does not link with TCIV_4 interrupt skipping||||||
|||||||||||1: Links with TCIV_4 interrupt skipping||||||

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|1|ITB3AE|0*|R/W|TGIA_3 Interrupt Skipping Link Enable|
|||||Select whether to link A/D converter start requests (TRG4BN) with TGIA_3|
|||||interrupt skipping operation.|
|||||0: Does not link with TGIA_3 interrupt skipping|
|||||1: Links with TGIA_3 interrupt skipping|
|0|ITB4VE|0*|R/W|TCIV_4 Interrupt Skipping Link Enable|
|||||Select whether to link A/D converter start requests (TRG4BN) with TCIV_4|
|||||interrupt skipping operation.|
|||||0: Does not link with TCIV_4 interrupt skipping|
|||||1: Links with TCIV_4 interrupt skipping|

Note 1. TADCR must not be accessed in eight bits; it should always be accessed in 16 bits.

Note 2. When interrupt skipping is disabled (the T3AEN and T4VEN bits in the timer interrupt skipping set register (TITCR) are cleared to 0 or the skipping count set bits (3ACOR and 4VCOR) in TITCR are cleared to 0), do not link A/D converter start requests with interrupt skipping operation (clear the ITA3AE, ITA4VE, ITB3AE, and ITB4VE bits in the timer A/D converter start request control register (TADCR) to 0).

Note 3. If link with interrupt skipping is enabled while interrupt skipping is disabled, A/D converter start requests will not be issued. Note: * Do not set to 1 when complementary PWM mode is not selected.

## **Table 10.27 Setting of Transfer Timing by Bits BF1 and BF0**

|**Bit 7**|**Bit 6**||
|---|---|---|
|**BF1**|**BF0**|**Description**|
|0|0|Does not transfer data from the cycle set buffer register to the cycle set register.|
|0|1|Transfers data from the cycle set buffer register to the cycle set register at the crest of the|
|||TCNT_4 count.*1|
|1|0|Transfers data from the cycle set buffer register to the cycle set register at the trough of the|
|||TCNT_4 count.*2|
|1|1|Transfers data from the cycle set buffer register to the cycle set register at the crest and|
|||trough of the TCNT_4 count.*2|

Note 1. Data is transferred from the cycle set buffer register to the cycle set register when the crest of the TCNT_4 count is reached in complementary PWM mode, when compare match occurs between TCNT_3 and TGRA_3 in reset-synchronized PWM mode, or when compare match occurs between TCNT_4 and TGRA_4 in PWM mode 1 or normal operation mode.

Note 2. These settings are prohibited when complementary PWM mode is not selected.

## 10.3.9 Timer A/D Converter Start Request Cycle Set Registers

## (TADCORA_4 and TADCORB_4)

TADCORA_4 and TADCORB_4 are 16-bit readable/writable registers. When the TCNT_4 count reaches the value in TADCORA_4 or TADCORB_4, a corresponding A/D converter start request will be issued.

TADCORA_4 and TADCORB_4 are initialized to H'FFFF.

Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 Initial value: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W Note: TADCORA_4 and TADCORB_4 must not be accessed in eight bits; they should always be accessed in 16 bits.

## 10.3.10 Timer A/D Converter Start Request Cycle Set Buffer Registers (TADCOBRA_4 and TADCOBRB_4)

TADCOBRA_4 and TADCOBRB_4 are 16-bit readable/writable registers. When the crest or trough of the TCNT_4 count is reached, these register values are transferred to TADCORA_4 and TADCORB_4, respectively.

TADCOBRA_4 and TADCOBRB_4 are initialized to H'FFFF.

|Bit:|Bit:|15|14||13|12|11|10<br>9|8|7<br>6|5|4|3|2|1||0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||||
|Initial value:||1|1||1|1|1|1<br>1|1|1<br>1|1|1|1|1|1||1|
|R/W:||R/W|R/W||R/W|R/W|R/W|R/W<br>R/W|R/W|R/W<br>R/W|R/W|R/W|R/W|R/W|R/W||R/W|
|Note:|TADCOBRA_4||||and TADCOBRB_4 must not be accessed in eight bits; they should|||||||always|be accessed in 16 bits.|||||

## 10.3.11 Timer Counter (TCNT)

The TCNT counters are 16-bit readable/writable counters. This module has five TCNT counters, one each for channels 0 to 4.

The TCNT counters must not be accessed in eight bits; they should always be accessed in 16 bits.

|Bit:|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||||
|Initial value:||0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|
|R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

Note: The TCNT counters must not be accessed in eight bits; they should always be accessed in 16 bits.

## 10.3.12 Timer General Register (TGR)

The TGR registers are 16-bit readable/writable registers. This module has eighteen TGR registers, six for channel 0, two each for channels 1 and 2, four each for channels 3 and 4.

TGRA, TGRB, TGRC, and TGRD function as either output compare or input capture registers. TGRC and TGRD for channels 0, 3, and 4 can also be designated for operation as buffer registers. TGR buffer register combinations are TGRA and TGRC, and TGRB and TGRD.

TGRE_0 and TGRF_0 function as compare registers. When the TCNT_0 count matches the TGRE_0 value, an A/D converter start request can be issued. TGRF can also be designated for operation as a buffer register. TGR buffer register combination is TGRE and TGRF.

|Bit:|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||||
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|
|R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

Note: The TGR registers must not be accessed in eight bits; they should always be accessed in 16 bits. TGR registers are initialized to H'FFFF.

## 10.3.13 Timer Start Register (TSTR)

TSTR is an 8-bit readable/writable register that selects operation/stoppage of TCNT for channels 0 to 4.

When setting the operating mode in TMDR or setting the count clock in TCR, first stop the TCNT counter.

||||Bit:|7|6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|
|||||CST4|CST3<br>-<br>-<br>-<br>CST2<br>CST1<br>CST0||
|||Initial|value:|0|0<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:|R/W|R/W<br>R<br>R<br>R<br>R/W<br>R/W<br>R/W||
|||**Initial**|||||
|**Bit**|**Bit Name**|**Value**|**R/W**||**Description**||
|7|CST4|0|R/W||Counter Start 4 and 3||
|6|CST3|0|R/W||These bits select operation or stoppage for|TCNT.|
||||||If 0 is written to the CST bit during operation with the TIOC pin designated for||
||||||output, the counter stops but the TIOC pin output compare output level is||
||||||retained. If TIOR is written to when the CST bit is cleared to 0, the pin output||
||||||level will be changed to the set initial output value.||
||||||0: TCNT_4 and TCNT_3 count operation is|stopped|
||||||1: TCNT_4 and TCNT_3 performs count operation||
|5 to 3|—|All 0|R||Reserved||
||||||These bits are always read as 0. The write value should always be 0.||
|2|CST2|0|R/W||Counter Start 2 to 0||
|1|CST1|0|R/W||These bits select operation or stoppage for|TCNT.|
||||||If 0 is written to the CST bit during operation with the TIOC pin designated for||
|0|CST0|0|R/W||output, the counter stops but the TIOC pin output compare output level is||
||||||retained. If TIOR is written to when the CST bit is cleared to 0, the pin output||
||||||level will be changed to the set initial output value.||
||||||0: TCNT_2 to TCNT_0 count operation is stopped||
||||||1: TCNT_2 to TCNT_0 performs count operation||

## 10.3.14 Timer Synchronous Register (TSYR)

TSYR is an 8-bit readable/writable register that selects independent operation or synchronous operation for the channel 0 to 4 TCNT counters. A channel performs synchronous operation when the corresponding bit in TSYR is set to 1.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||SYNC4|SYNC3|-|-|-|SYNC2|SYNC1|SYNC0|
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R|R|R|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|SYNC4|0|R/W|Timer Synchronous operation 4 and 3|
|6|SYNC3|0|R/W|These bits are used to select whether operation is independent of or|
|||||synchronized with other channels.|
|||||When synchronous operation is selected, the TCNT synchronous presetting of|
|||||multiple channels, and synchronous clearing by counter clearing on another|
|||||channel, are possible.|
|||||To set synchronous operation, the SYNC bits for at least two channels must be|
|||||set to 1. To set synchronous clearing, in addition to the SYNC bit , the TCNT|
|||||clearing source must also be set by means of bits CCLR0 to CCLR2 in TCR.|
|||||0: TCNT_4 and TCNT_3 operate independently (TCNT presetting/clearing is|
|||||unrelated to other channels)|
|||||1: TCNT_4 and TCNT_3 performs synchronous operation|
|||||TCNT synchronous presetting/synchronous clearing is possible|
|5 to 3|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|2|SYNC2|0|R/W|Timer Synchronous operation 2 to 0|
|1|SYNC1|0|R/W|These bits are used to select whether operation is independent of or|
|||||synchronized with other channels.|
|0|SYNC0|0|R/W|When synchronous operation is selected, the TCNT synchronous presetting of|
|||||multiple channels, and synchronous clearing by counter clearing on another|
|||||channel, are possible.|
|||||To set synchronous operation, the SYNC bits for at least two channels must be|
|||||set to 1. To set synchronous clearing, in addition to the SYNC bit, the TCNT|
|||||clearing source must also be set by means of bits CCLR0 to CCLR2 in TCR.|
|||||0: TCNT_2 to TCNT_0 operates independently (TCNT presetting /clearing is|
|||||unrelated to other channels)|
|||||1: TCNT_2 to TCNT_0 performs synchronous operation|
|||||TCNT synchronous presetting/synchronous clearing is possible|

## 10.3.15 Timer Read/Write Enable Register (TRWER)

TRWER is an 8-bit readable/writable register that enables or disables access to the registers and counters which have write-protection capability against accidental modification in channels 3 and 4.

||||Bit:||7|6<br>5<br>4|3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|---|
||||||-|-<br>-<br>-|-<br>-<br>-<br>RWE||
|||Initial|value:||0|0<br>0<br>0|0<br>0<br>0<br>1||
||||R/W:||R|R<br>R<br>R|R<br>R<br>R<br>R/W||
|||**Initial**|||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**|||
|7 to 1|—|All 0|R|||Reserved|||
|||||||These bits are always read as 0. The write value should always be 0.|||
|0|RWE|1|R/W|||Read/Write Enable|||
|||||||Enables or disables access to the registers||which have write-protection|
|||||||capability against|accidental modification.||
|||||||0: Disables read/write access to the registers|||
|||||||1: Enables read/write access to the registers|||
|||||||[Clearing condition]|||
|||||||When 0 is written to the RWE bit after reading|||
|||||||RWE = 1|||

- Registers and counters having write-protection capability against accidental modification 22 registers: TCR_3, TCR_4, TMDR_3, TMDR_4, TIORH_3, TIORH_4, TIORL_3, TIORL_4, TIER_3, TIER_4, TGRA_3, TGRA_4, TGRB_3, TGRB_4, TOER, TOCR1, TOCR2, TGCR, TCDR, TDDR, TCNT_3, and TCNT_4.

## 10.3.16 Timer Output Master Enable Register (TOER)

TOER is an 8-bit readable/writable register that enables/disables output settings for output pins TIOC4D, TIOC4C, TIOC3D, TIOC4B, TIOC4A, and TIOC3B. These pins do not output correctly if the TOER bits have not been set. Set TOER of CH3 and CH4 prior to setting TIOR of CH3 and CH4.

Make settings of the TOER while counting by the TCNT registers of channels 3 and 4 is stopped.

||||Bit:||7|6<br>5<br>4<br>3<br>2<br>1<br>0||
|---|---|---|---|---|---|---|---|
||||||-|-<br>OE4D<br>OE4C<br>OE3D<br>OE4B<br>OE4A<br>OE3B||
|||Initial|value:||1|1<br>0<br>0<br>0<br>0<br>0<br>0||
||||R/W:||R|R<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**Value**|**R/W**|||**Description**||
|7, 6|—|All 1|R|||Reserved||
|||||||These bits are always read as 1. The write value should always be 1.||
|5|OE4D|0|R/W|||Master Enable TIOC4D||
|||||||This bit enables/disables the TIOC4D pin output for this module.||
|||||||0: Output for this module is disabled (inactive level)*||
|||||||1: Output for this module is enabled||
|4|OE4C|0|R/W|||Master Enable TIOC4C||
|||||||This bit enables/disables the TIOC4C pin output for this module.||
|||||||0: Output for this module is disabled (inactive level)*||
|||||||1: Output for this module is enabled||
|3|OE3D|0|R/W|||Master Enable TIOC3D||
|||||||This bit enables/disables the TIOC3D pin output for this module.||
|||||||0: Output for this module is disabled (inactive level)*||
|||||||1: Output for this module is enabled||
|2|OE4B|0|R/W|||Master Enable TIOC4B||
|||||||This bit enables/disables the TIOC4B pin output for this module.||
|||||||0: Output for this module is disabled (inactive level)*||
|||||||1: Output for this module is enabled||
|1|OE4A|0|R/W|||Master Enable TIOC4A||
|||||||This bit enables/disables the TIOC4A pin output for this module.||
|||||||0: Output for this module is disabled (inactive level)*||
|||||||1: Output for this module is enabled||
|0|OE3B|0|R/W|||Master Enable TIOC3B||
|||||||This bit enables/disables the TIOC3B pin output for this module.||
|||||||0: Output for this module is disabled (inactive level)*||
|||||||1: Output for this module is enabled||

Note: * The inactive level is determined by the settings in timer output control registers 1 and 2 (TOCR1 and TOCR2). For details, refer to section 10.3.17, Timer Output Control Register 1 (TOCR1), and section 10.3.18, Timer Output Control Register 2 (TOCR2). Set these bits to 1 to enable output for this module in other than complementary PWM or resetsynchronized PWM mode. When these bits are set to 0, low level is output.

## 10.3.17 Timer Output Control Register 1 (TOCR1)

TOCR1 is an 8-bit readable/writable register that enables/disables PWM synchronized toggle output in complementary PWM mode/reset synchronized PWM mode, and controls output level inversion of PWM output.

||||Bit:|7|6<br>5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|
|||||-|PSYE<br>-<br>-<br>TOCL<br>TOCS<br>OLSN|OLSP||
|||Initial|value:|0|0<br>0<br>0<br>0<br>0<br>0|0||
||||R/W:|R|R/W<br>R<br>R<br>R/(W)*3 R/W<br>R/W|R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**value**|**R/W**||**Description**|||
|7|—|0|R||Reserved|||
||||||This bit is always read as 0. The write value should always be 0.|||
|6|PSYE|0|R/W||PWM Synchronous Output Enable|||
||||||This bit selects the enable/disable of|toggle|output synchronized with the PWM|
||||||period.|||
||||||0: Toggle output is disabled|||
||||||1: Toggle output is enabled|||
|5, 4|—|All 0|R||Reserved|||
||||||These bits are always read as 0. The write value should always be 0.|||
|3|TOCL|0|R/(W)*3||TOC Register Write Protection*1|||
||||||This bit selects the enable/disable of|write access to the TOCS, OLSN, and||
||||||OLSP bits in TOCR1.|||
||||||0: Write access to the TOCS, OLSN,|and OLSP bits is enabled||
||||||1: Write access to the TOCS, OLSN,|and OLSP bits is disabled||
|2|TOCS|0|R/W||TOC Select|||
||||||This bit selects either the TOCR1 or TOCR2 setting to be used for the output|||
||||||level in complementary PWM mode and reset-synchronized PWM mode.|||
||||||0: TOCR1 setting is selected|||
||||||1: TOCR2 setting is selected|||
|1|OLSN|0|R/W||Output Level Select N*2*4|||
||||||This bit selects the negative phase output level in reset-synchronized PWM|||
||||||mode/complementary PWM mode. See Table 10.28.|||
|0|OLSP|0|R/W||Output Level Select P*2|||
||||||This bit selects the positive phase output level in reset-synchronized PWM|||
||||||mode/complementary PWM mode. See Table 10.29.|||

Note 1. Setting the TOCL bit to 1 prevents accidental modification when the CPU goes out of control. Note 2. Clearing the TOCS bit to 0 makes this bit setting valid.

Note 3. After power-on reset, 1 can be written only once. After 1 has been written, 0 cannot be written.

Note 4. If the dead-time is not generated, the negative-phase output will be the exact inverse of the positive-phase output. Furthermore, set OLSP and OLSN to the same value.

**Table 10.28 Output Level Select Function**

|**Bit 1**<br>**OLSN**|**Function**|**Function**|
|---|---|---|
||**Initial Output**<br>**Active Level**|**Compare Match Output**|
|||**Up Count**<br>**Down Count**|
|0|High level<br>Low level|High level<br>Low level|
|1|Low level<br>High level|Low level<br>High level|

Note: The negative phase waveform initial output value changes to active level after elapse of the dead time after count start.

## **Table 10.29 Output Level Select Function**

|**Bit 0**<br>**OLSP**|**Function**|**Function**|
|---|---|---|
||**Initial Output**<br>**Active Level**|**Compare Match Output**|
|||**Up Count**<br>**Down Count**|
|0|High level<br>Low level|Low level<br>High level|
|1|Low level<br>High level|High level<br>Low level|

Figure 10.2 shows an example of complementary PWM mode output (1 phase) when OLSN = 1, OLSP = 1.

**==> picture [336 x 209] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_3, and<br>TCNT_4 values<br>TGRA_3<br>TCNT_3<br>TCNT_4<br>TGRA_4<br>TDDR<br>H'0000 Time<br>Compare match<br>output (up count)<br>Positive Initial Compare match<br>phase output output Active level output (down count)<br>Initial Compare match<br>output output (down count)<br>Negative phase output Active level output (up count)Compare match Active level<br>**----- End of picture text -----**<br>

**Figure 10.2 Complementary PWM Mode Output Level Example**

## 10.3.18 Timer Output Control Register 2 (TOCR2)

TOCR2 is an 8-bit readable/writable register that controls output level inversion of PWM output in complementary PWM mode and reset-synchronized PWM mode.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||BF[1:0]||OLS3N|OLS3P|OLS2N|OLS2P|OLS1N|OLS1P|
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**value**|**R/W**|**Description**|
|7, 6|BF[1:0]|00|R/W|TOLBR Buffer Transfer Timing Select|
|||||These bits select the timing for transferring data from TOLBR to TOCR2.|
|||||For details, see Table 10.30.|
|5|OLS3N|0|R/W|Output Level Select 3N*|
|||||This bit selects the output level on TIOC4D in reset-synchronized PWM mode/|
|||||complementary PWM mode. See Table 10.31.|
|4|OLS3P|0|R/W|Output Level Select 3P*|
|||||This bit selects the output level on TIOC4B in reset-synchronized PWM mode/|
|||||complementary PWM mode. See Table 10.32.|
|3|OLS2N|0|R/W|Output Level Select 2N*|
|||||This bit selects the output level on TIOC4C in reset-synchronized PWM mode/|
|||||complementary PWM mode. See Table 10.33.|
|2|OLS2P|0|R/W|Output Level Select 2P*|
|||||This bit selects the output level on TIOC4A in reset-synchronized PWM mode/|
|||||complementary PWM mode. See Table 10.34.|
|1|OLS1N|0|R/W|Output Level Select 1N*|
|||||This bit selects the output level on TIOC3D in reset-synchronized PWM mode/|
|||||complementary PWM mode. See Table 10.35.|
|0|OLS1P|0|R/W|Output Level Select 1P*|
|||||This bit selects the output level on TIOC3B in reset-synchronized PWM mode/|
|||||complementary PWM mode. See Table 10.36.|

Note: * Setting the TOCS bit in TOCR1 to 1 makes this bit setting valid.

If the dead-time is not generated, the negative-phase output will be the exact inverse of the positive-phase output. Furthermore, set OLSiP and OLSiN (i = 1, 2, 3) to the same value.

**Table 10.30 Setting of Bits BF1 and BF0**

|**Bit 7**<br>**Bit 6**<br>**BF1**<br>**BF0**|**Description**|
|---|---|
||**Complementary PWM Mode**<br>**Reset-Synchronized PWM Mode**|
|0<br>0|Does not transfer data from the buffer register<br>(TOLBR) to TOCR2.<br>Does not transfer data from the buffer register<br>(TOLBR) to TOCR2.|
|0<br>1|Transfers data from the buffer register (TOLBR) to<br>TOCR2 at the crest of the TCNT_4 count.<br>Transfers data from the buffer register (TOLBR) to<br>TOCR2 when TCNT_3/TCNT_4 is cleared|
|1<br>0|Transfers data from the buffer register (TOLBR) to<br>TOCR2 at the trough of the TCNT_4 count.<br>Setting prohibited|
|1<br>1|Transfers data from the buffer register (TOLBR) to<br>TOCR2 at the crest and trough of the TCNT_4<br>count.<br>Setting prohibited|

## **Table 10.31 TIOC4D Output Level Select Function**

|**Bit 5**<br>**OLS3N**|**Function**|**Function**|
|---|---|---|
||**Initial Output**<br>**Active Level**|**Compare Match Output**|
|||**Up Count**<br>**Down Count**|
|0|High level<br>Low level|High level<br>Low level|
|1|Low level<br>High level|Low level<br>High level|

Note: The negative phase waveform initial output value changes to the active level after elapse of the dead time after count start.

## **Table 10.32 TIOC4B Output Level Select Function**

|**Bit 4**<br>**OLS3P**|**Function**|**Function**|
|---|---|---|
||**Initial Output**<br>**Active Level**|**Compare Match Output**|
|||**Up Count**<br>**Down Count**|
|0|High level<br>Low level|Low level<br>High level|
|1|Low level<br>High level|High level<br>Low level|

## **Table 10.33 TIOC4C Output Level Select Function**

|**Bit 3**<br>**OLS2N**|**Function**|**Function**|
|---|---|---|
||**Initial Output**<br>**Active Level**|**Compare Match Output**|
|||**Up Count**<br>**Down Count**|
|0|High level<br>Low level|High level<br>Low level|
|1|Low level<br>High level|Low level<br>High level|

Note: The negative phase waveform initial output value changes to the active level after elapse of the dead time after count start.

## **Table 10.34 TIOC4A Output Level Select Function**

|**Bit 2**<br>**OLS2P**|**Function**|**Function**|
|---|---|---|
||**Initial Output**<br>**Active Level**|**Compare Match Output**|
|||**Up Count**<br>**Down Count**|
|0|High level<br>Low level|Low level<br>High level|
|1|Low level<br>High level|High level<br>Low level|

## **Table 10.35 TIOC3D Output Level Select Function**

|**Bit 1**<br>**OLS1N**|**Function**|**Function**|
|---|---|---|
||**Initial Output**<br>**Active Level**|**Compare Match Output**|
|||**Up Count**<br>**Down Count**|
|0|High level<br>Low level|High level<br>Low level|
|1|Low level<br>High level|Low level<br>High level|

Note: The negative phase waveform initial output value changes to the active level after elapse of the dead time after count start.

## **Table 10.36 TIOC4B Output Level Select Function**

|**Bit 0**<br>**OLS1P**|**Function**|**Function**|
|---|---|---|
||**Initial Output**<br>**Active Level**|**Compare Match Output**|
|||**Up Count**<br>**Down Count**|
|0|High level<br>Low level|Low level<br>High level|
|1|Low level<br>High level|High level<br>Low level|

## 10.3.19 Timer Output Level Buffer Register (TOLBR)

TOLBR is an 8-bit readable/writable register that functions as a buffer for TOCR2 and specifies the PWM output level in complementary PWM mode and reset-synchronized PWM mode.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||-|-|OLS3N|OLS3P|OLS2N|OLS2P|OLS1N|OLS1P|
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R|R|R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**value**|**R/W**|**Description**|
|7, 6|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|5|OLS3N|0|R/W|Specifies the buffer value to be transferred to the OLS3N bit in TOCR2.|
|4|OLS3P|0|R/W|Specifies the buffer value to be transferred to the OLS3P bit in TOCR2.|
|3|OLS2N|0|R/W|Specifies the buffer value to be transferred to the OLS2N bit in TOCR2.|
|2|OLS2P|0|R/W|Specifies the buffer value to be transferred to the OLS2P bit in TOCR2.|
|1|OLS1N|0|R/W|Specifies the buffer value to be transferred to the OLS1N bit in TOCR2.|
|0|OLS1P|0|R/W|Specifies the buffer value to be transferred to the OLS1P bit in TOCR2.|

Figure 10.3 shows an example of the PWM output level setting procedure in buffer operation.

**==> picture [359 x 134] intentionally omitted <==**

**----- Start of picture text -----**<br>
Set bit TOCS [1] [1]  Set bit TOCS in TOCR1 to 1 to enable the TOCR2 setting.<br>[2]  Use bits BF1 and BF0 in TOCR2 to select the TOLBR buffer<br>      transfer timing. Use bits OLS3N to OLS1N and OLS3P to OLS1P<br>      to specify the PWM output levels.<br>Set TOCR2 [2]<br>[3]  The TOLBR initial setting must be the same value as specified in<br>      bits OLS3N to OLS1N and OLS3P to OLS1P in TOCR2.<br>Set TOLBR [3]<br>**----- End of picture text -----**<br>

**Figure 10.3 PWM Output Level Setting Procedure in Buffer Operation**

## 10.3.20 Timer Gate Control Register (TGCR)

TGCR is an 8-bit readable/writable register that controls the waveform output necessary for brushless DC motor control in reset-synchronized PWM mode/complementary PWM mode. These register settings are ineffective for anything other than complementary PWM mode/reset-synchronized PWM mode.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||-|BDC|N|P|FB|WF|VF|UF|
|Initial value:|1|0|0|0|0|0|0|0|
|R/W:|R|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**value**|**R/W**|**Description**|
|7|—|1|R|Reserved|
|||||This bit is always read as 1. The write value should always be 1.|
|6|BDC|0|R/W|Brushless DC Motor|
|||||This bit selects whether to make the functions of this register (TGCR) effective|
|||||or ineffective.|
|||||0: Ordinary output|
|||||1: Functions of this register are made effective|
|5|N|0|R/W|Negative Phase Output (N) Control|
|||||This bit selects whether the level output or the reset-synchronized PWM/|
|||||complementary PWM output while the reverse pins (TIOC3D, TIOC4C, and|
|||||TIOC4D) are output.|
|||||0: Level output|
|||||1: Reset synchronized PWM/complementary PWM output|
|4|P|0|R/W|Positive Phase Output (P) Control|
|||||This bit selects whether the level output or the reset-synchronized PWM/|
|||||complementary PWM output while the positive pins (TIOC3B, TIOC4A, and|
|||||TIOC4B) are output.|
|||||0: Level output|
|||||1: Reset synchronized PWM/complementary PWM output|
|3|FB|0|R/W|External Feedback Signal Enable|
|||||This bit selects whether the switching of the output of the positive/negative|
|||||phase is carried out automatically with channel-0 TGRA, TGRB, TGRC input|
|||||capture signals or by writing 0 or 1 to bits 2 to 0 in TGCR.|
|||||0: Output switching is external input (Input sources are channel 0 TGRA, TGRB,|
|||||TGRC input capture signal)|
|||||1: Output switching is carried out by software (setting values of UF, VF, and WF|
|||||in TGCR).|
|2|WF|0|R/W|Output Phase Switch 2 to 0|
|1|VF|0|R/W|These bits set the positive phase/negative phase output phase on or off state.|
|||||The setting of these bits is valid only when the FB bit in this register is set to 1. In|
|0|UF|0|R/W|this case, the setting of bits 2 to 0 is a substitute for external input. See Table|
|||||10.37.|

## **Table 10.37 Output level Select Function**

|**Bit 2**|**Bit 1**|**Bit 0**<br>**UF**|**Function**|
|---|---|---|---|
||||**TIOC3B**<br>**TIOC4A**<br>**TIOC4B**<br>**TIOC3D**<br>**TIOC4C**<br>**TIOC4D**|
|**WF**|**VF**||**U Phase**<br>**V Phase**<br>**W Phase**<br>**U Phase**<br>**V Phase**<br>**W Phase**|
|0|0|0|OFF<br>OFF<br>OFF<br>OFF<br>OFF<br>OFF|
|||1|ON<br>OFF<br>OFF<br>OFF<br>OFF<br>ON|
||1|0|OFF<br>ON<br>OFF<br>ON<br>OFF<br>OFF|
|||1|OFF<br>ON<br>OFF<br>OFF<br>OFF<br>ON|
|1|0|0|OFF<br>OFF<br>ON<br>OFF<br>ON<br>OFF|
|||1|ON<br>OFF<br>OFF<br>OFF<br>ON<br>OFF|
||1|0|OFF<br>OFF<br>ON<br>ON<br>OFF<br>OFF|
|||1|OFF<br>OFF<br>OFF<br>OFF<br>OFF<br>OFF|

## 10.3.21 Timer Subcounter (TCNTS)

TCNTS is a 16-bit read-only counter that is used only in complementary PWM mode.

The initial value of TCNTS is H'0000.

|Bit:|Bit:|15|14|13|12|11|10|9|8|7||6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||||||
|Initial value:||0|0|0|0|0|0|0|0|0||0|0|0|0|0|0|0|
|R/W:||R|R|R|R|R|R|R|R|R||R|R|R|R|R|R|R|
|Note:<br>Accessing the TCNTS in 8-bit units is|||||||prohibited. Always access in||||16-bit units.||||||||

## 10.3.22 Timer Dead Time Data Register (TDDR)

TDDR is a 16-bit register, used only in complementary PWM mode that specifies the TCNT_3 and TCNT_4 counter offset values. In complementary PWM mode, when the TCNT_3 and TCNT_4 counters are cleared and then restarted, the TDDR register value is loaded into the TCNT_3 counter and the count operation starts.

The initial value of TDDR is H'FFFF.

|Bit:|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||||
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|
|R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|
|Note:<br>Accessing the TDDR in 8-bit units is prohibited. Always access in 16-bit units.||||||||||||||||||

## 10.3.23 Timer Cycle Data Register (TCDR)

TCDR is a 16-bit register used only in complementary PWM mode. Set half the PWM carrier cycle value (however, the value must also be at least twice the setting of TDDR plus 3) as the TCDR register value. This register is constantly compared with the TCNTS counter in complementary PWM mode, and when a match occurs, the TCNTS counter switches direction (decrement to increment).

The initial value of TCDR is H'FFFF.

Bit: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 Initial value: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 R/W: R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W R/W

Note: Accessing the TCDR in 8-bit units is prohibited. Always access in 16-bit units.

## 10.3.24 Timer Cycle Buffer Register (TCBR)

TCBR is a 16-bit register used only in complementary PWM mode. It functions as a buffer register for the TCDR register. The TCBR register values are transferred to the TCDR register with the transfer timing set in the TMDR register. The initial value of TCBR is H'FFFF.

|Bit:|Bit:|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||||
|Initial value:||1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|1|
|R/W:||R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|R/W|

Note: Accessing the TCBR in 8-bit units is prohibited. Always access in 16-bit units.

## 10.3.25 Timer Interrupt Skipping Set Register (TITCR)

TITCR is an 8-bit readable/writable register that enables or disables interrupt skipping and specifies the interrupt skipping count. This module has one TITCR.

||||Bit:|7|6<br>5<br>4<br>3<br>2<br>1|0||
|---|---|---|---|---|---|---|---|
|||||T3AEN|3ACOR[2:0]<br>T4VEN<br>4VCOR[2:0]|||
|||Initial|value:|0|0<br>0<br>0<br>0<br>0<br>0|0||
||||R/W:|R/W|R/W<br>R/W<br>R/W<br>R/W<br>R/W<br>R/W|R/W||
|||**Initial**||||||
|**Bit**|**Bit Name**|**value**|**R/W**||**Description**|||
|7|T3AEN|0|R/W||T3AEN|||
||||||Enables or disables TGIA_3 interrupt skipping.|||
||||||0: TGIA_3 interrupt skipping disabled|||
||||||1: TGIA_3 interrupt skipping enabled|||
|6 to 4|3ACOR[2:0]|000|R/W||These bits specify the TGIA_3 interrupt skipping count within the range from 0 to|||
||||||7.*|||
||||||For details, see Table 10.38.|||
|3|T4VEN|0|R/W||T4VEN|||
||||||Enables or disables TCIV_4 interrupt skipping.|||
||||||0: TCIV_4 interrupt skipping disabled|||
||||||1: TCIV_4 interrupt skipping enabled|||
|2 to 0|4VCOR[2:0]|000|R/W||These bits specify the TCIV_4 interrupt skipping count within the range from 0 to|||
||||||7.*|||
||||||For details, see Table 10.39.|||

Note: * When 0 is specified for the interrupt skipping count, no interrupt skipping will be performed. Before changing the interrupt skipping count, be sure to clear the T3AEN and T4VEN bits to 0 to clear the skipping counter (TITCNT).

**Table 10.38 Setting of Interrupt Skipping Count by Bits 3ACOR2 to 3ACOR0**

|**Bit 6**|**Bit 5**|**Bit 4**||
|---|---|---|---|
|**3ACOR2**|**3ACOR1**|**3ACOR0**|**Description**|
|0|0|0|Does not skip TGIA_3 interrupts.|
|0|0|1|Sets the TGIA_3 interrupt skipping count to 1.|
|0|1|0|Sets the TGIA_3 interrupt skipping count to 2.|
|0|1|1|Sets the TGIA_3 interrupt skipping count to 3.|
|1|0|0|Sets the TGIA_3 interrupt skipping count to 4.|
|1|0|1|Sets the TGIA_3 interrupt skipping count to 5.|
|1|1|0|Sets the TGIA_3 interrupt skipping count to 6.|
|1|1|1|Sets the TGIA_3 interrupt skipping count to 7.|

**Table 10.39 Setting of Interrupt Skipping Count by Bits 4VCOR2 to 4VCOR0**

|**Bit 2**|**Bit 1**|**Bit 0**||
|---|---|---|---|
|**4VCOR2**|**4VCOR1**|**4VCOR0**|**Description**|
|0|0|0|Does not skip TCIV_4 interrupts.|
|0|0|1|Sets the TCIV_4 interrupt skipping count to 1.|
|0|1|0|Sets the TCIV_4 interrupt skipping count to 2.|
|0|1|1|Sets the TCIV_4 interrupt skipping count to 3.|
|1|0|0|Sets the TCIV_4 interrupt skipping count to 4.|
|1|0|1|Sets the TCIV_4 interrupt skipping count to 5.|
|1|1|0|Sets the TCIV_4 interrupt skipping count to 6.|
|1|1|1|Sets the TCIV_4 interrupt skipping count to 7.|

## 10.3.26 Timer Interrupt Skipping Counter (TITCNT)

TITCNT is an 8-bit readable counter. This module has one TITCNT. TITCNT retains its value even after stopping the count operation of TCNT_3 and TCNT_4.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||-||3ACNT[2:0]||-||4VCNT[2:0]||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R|R|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|—|0|R|Reserved|
|||||This bit is always read as 0.|
|6 to 4|3ACNT[2:0]|000|R|TGIA_3 Interrupt Counter|
|||||While the T3AEN bit in TITCR is set to 1, the count in these bits is incremented|
|||||every time a TGIA_3 interrupt occurs.|
|||||[Clearing conditions]|
|||||When the 3ACNT2 to 3ACNT0 value in TITCNT matches the 3ACOR2 to|
|||||3ACOR0 value in TITCR|
|||||When the T3AEN bit in TITCR is cleared to 0|
|||||When the 3ACOR2 to 3ACOR0 bits in TITCR are cleared to 0|
|3|—|0|R|Reserved|
|||||This bit is always read as 0.|
|2 to 0|4VCNT[2:0]|000|R|TCIV_4 Interrupt Counter|
|||||While the T4VEN bit in TITCR is set to 1, the count in these bits is incremented|
|||||every time a TCIV_4 interrupt occurs.|
|||||[Clearing conditions]|
|||||When the 4VCNT2 to 4VCNT0 value in TITCNT matches the 4VCOR2 to|
|||||4VCOR0 value in TITCR|
|||||When the T4VEN bit in TITCR is cleared to 0|
|||||When the 4VCOR2 to 4VCOR0 bits in TITCR are cleared to 0|

Note: To clear the TITCNT, clear the bits T3AEN and T4VEN in TITCR to 0.

## 10.3.27 Timer Buffer Transfer Set Register (TBTER)

TBTER is an 8-bit readable/writable register that enables or disables transfer from the buffer registers* used in complementary PWM mode to the temporary registers and specifies whether to link the transfer with interrupt skipping operation. This module has one TBTER.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|BTE[1:0]||
|Initial value:|0|0|0|0|0|0|0|0|
|R/W:|R|R|R|R|R|R|R/W|R/W|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7 to 2|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|1, 0|BTE[1:0]|00|R/W|These bits enable or disable transfer from the buffer registers* used in|
|||||complementary PWM mode to the temporary registers and specify whether to|
|||||link the transfer with interrupt skipping operation.|
|||||For details, see Table 10.40.|

Note: * Applicable buffer registers: TGRC_3, TGRD_3, TGRC_4, TGRD_4, and TCBR

## **Table 10.40 Setting of Bits BTE1 and BTE0**

|**Bit 1**|**Bit 0**||
|---|---|---|
|**BTE1**|**BTE0**|**Description**|
|0|0|Enables transfer from the buffer registers to the temporary registers*1and does not link the transfer|
|||with interrupt skipping operation.|
|0|1|Disables transfer from the buffer registers to the temporary registers.|
|1|0|Links transfer from the buffer registers to the temporary registers with interrupt skipping operation.*2|
|1|1|Setting prohibited|

Note 1. Data is transferred according to the MD3 to MD0 bit setting in TMDR. For details, refer to section 10.4.8, Complementary PWM Mode.

Note 2. When interrupt skipping is disabled (the T3AEN and T4VEN bits are cleared to 0 in the timer interrupt skipping set register (TITCR) or the skipping count set bits (3ACOR and 4VCOR) in TITCR are cleared to 0)), be sure to disable link of buffer transfer with interrupt skipping (clear the BTE1 bit in the timer buffer transfer set register (TBTER) to 0). If link with interrupt skipping is enabled while interrupt skipping is disabled, buffer transfer will not be performed.

## 10.3.28 Timer Dead Time Enable Register (TDER)

TDER is an 8-bit readable/writable register that controls dead time generation in complementary PWM mode. This module has one TDER in channel 3. TDER must be modified only while TCNT stops.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||-|-|-|-|-|-|-|TDER|
|Initial value:|0|0|0|0|0|0|0|1|
|R/W:|R|R|R|R|R|R|R|R/(W)|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|TDER|1|R/(W)|Dead Time Enable|
|||||Specifies whether to generate dead time.|
|||||0: Does not generate dead time|
|||||1: Generates dead time*|
|||||[Clearing condition]|
|||||When 0 is written to TDER after reading TDER = 1|

Note: * TDDR must be set to 1 or a larger value.

## 10.3.29 Timer Waveform Control Register (TWCR)

TWCR is an 8-bit readable/writable register that controls the waveform when synchronous counter clearing occurs in TCNT_3 and TCNT_4 in complementary PWM mode and specifies whether to clear the counters at TGRA_3 compare match. The CCE bit and WRE bit in TWCR must be modified only while TCNT stops.

|Bit:|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|
||CCE|-|-|-|-|-|-|WRE|
|Initial value:|0*|0|0|0|0|0|0|0|
|R/W:|R/(W)|R|R|R|R|R|R|R/(W)|

|||**Initial**|||
|---|---|---|---|---|
|**Bit**|**Bit Name**|**Value**|**R/W**|**Description**|
|7|CCE|0*|R/(W)|Compare Match Clear Enable|
|||||Specifies whether to clear counters at TGRA_3 compare match in|
|||||complementary PWM mode.|
|||||0: Does not clear counters at TGRA_3 compare match|
|||||1: Clears counters at TGRA_3 compare match|
|||||[Setting condition]|
|||||When 1 is written to CCE after reading CCE = 0|
|6 to 1|—|All 0|R|Reserved|
|||||These bits are always read as 0. The write value should always be 0.|
|0|WRE|0|R/(W)|Initial Output Suppression Enable|
|||||Selects the waveform output when synchronous counter clearing occurs in|
|||||complementary PWM mode. The initial output is suppressed only when|
|||||synchronous clearing occurs within the Tb interval at the trough in|
|||||complementary PWM mode. When synchronous clearing occurs outside this|
|||||interval, the initial value specified in TOCR is output regardless of the WRE bit|
|||||setting. The initial value is also output when synchronous clearing occurs in the|
|||||Tb interval at the trough immediately after TCNT_3 and TCNT_4 start operation.|
|||||For the Tb interval at the trough in complementary PWM mode, see Figure|
|||||10.40.|
|||||0: Outputs the initial value specified in TOCR|
|||||1: Suppresses initial output|
|||||[Setting condition]|
|||||When 1 is written to WRE after reading WRE = 0|

Note: * Do not set to 1 when complementary PWM mode 1 is not selected.

## 10.3.30 Bus Master Interface

The timer counters (TCNT), general registers (TGR), timer subcounter (TCNTS), timer cycle buffer register (TCBR), timer dead time data register (TDDR), timer cycle data register (TCDR), timer A/D converter start request control register (TADCR), timer A/D converter start request cycle set registers (TADCOR), and timer A/D converter start request cycle set buffer registers (TADCOBR) are 16-bit registers. 16-bit read/writes is possible. 8-bit read/write is not possible. Always access in 16-bit units.

All registers other than the above registers are 8-bit registers. 8-bit read/writes is possible. 16-bit read/writes is not possible. Always access in 8-bit units.

## 10.4 Operation

## 10.4.1 Basic Functions

Each channel has a TCNT and TGR register. TCNT performs up-counting, and is also capable of free-running operation, cycle counting, and external event counting.

Each TGR can be used as an input capture register or output compare register.

Always select functions for external pins of this module using the general I/O ports.

## (1) Counter Operation

When one of bits CST0 to CST4 in TSTR is set to 1, the TCNT counter for the corresponding channel begins counting. TCNT can operate as a free-running counter, periodic counter, for example.

## (a) Example of Count Operation Setting Procedure

Figure 10.4 shows an example of the count operation setting procedure.

**==> picture [312 x 197] intentionally omitted <==**

**----- Start of picture text -----**<br>
Operation selection [1] Select the counter clock<br>with bits TPSC2 to TPSC0<br>in TCR. At the same time,<br>Select counter clock [1] select the input clock edge<br>with bits CKEG1 and<br>CKEG0 in TCR.<br>[2] For periodic counter<br>Periodic counter Free-running counter operation, select the TGR<br>to be used as the TCNT<br>clearing source with bits<br>Select counter clearing [2] CCLR2 to CCLR0 in TCR.<br>source<br>[3] Designate the TGR<br>selected in [2] as an output<br>Select output compare [3] compare register by means<br>register of TIOR.<br>[4] Set the periodic counter<br>Set period [4] cycle in the TGR selected<br>in [2].<br>Start count operation [5] [5] Set the CST bit in TSTR to<br>Start count operation [5]<br><Free-running counter> 1 to start the counter<br><Periodic  counter> operation.<br>**----- End of picture text -----**<br>

**Figure 10.4 Example of Counter Operation Setting Procedure**

## (b) Free-Running Count Operation and Periodic Count Operation:

Immediately after a reset, the TCNT counters of this module are all designated as free-running counters. When the relevant bit in TSTR is set to 1 the corresponding TCNT counter starts up-count operation as a free-running counter. When TCNT overflows (from H'FFFF to H'0000), the TCFV bit in TSR is set to 1. If the value of the corresponding TCIEV bit in TIER is 1 at this point, this module requests an interrupt. After overflow, TCNT starts counting up again from H'0000.

Figure 10.5 illustrates free-running counter operation.

**==> picture [291 x 118] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT value<br>H'FFFF<br>H'0000 Time<br>CST bit<br>TCFV<br>**----- End of picture text -----**<br>

**Figure 10.5 Free-Running Counter Operation**

When compare match is selected as the TCNT clearing source, the TCNT counter for the relevant channel performs periodic count operation. The TGR register for setting the period is designated as an output compare register, and counter clearing by compare match is selected by means of bits CCLR0 to CCLR2 in TCR. After the settings have been made, TCNT starts up-count operation as a periodic counter when the corresponding bit in TSTR is set to 1. When the count value matches the value in TGR, the TGF bit in TSR is set to 1 and TCNT is cleared to H'0000.

If the value of the corresponding TGIE bit in TIER is 1 at this point, this module requests an interrupt. After a compare match, TCNT starts counting up again from H'0000.

Figure 10.6 illustrates periodic counter operation.

**==> picture [290 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT value Counter cleared by TGR<br>compare match<br>TGR<br>H'0000 Time<br>CST bit<br>Flag cleared by software or<br>DMAC activation<br>TGF<br>**----- End of picture text -----**<br>

**Figure 10.6 Periodic Counter Operation**

## (2) Waveform Output by Compare Match

This module can perform 0, 1, or toggle output from the corresponding output pin using compare match.

## (a) Example of Setting Procedure for Waveform Output by Compare Match

Figure 10.7 shows an example of the setting procedure for waveform output by compare match.

**==> picture [271 x 171] intentionally omitted <==**

**----- Start of picture text -----**<br>
Output selection [1] Select initial value 0 output or 1 output,<br>and compare match output value 0<br>output, 1 output, or toggle output, by<br>means of TIOR.  The set initial value is<br>output at the TIOC pin until the first<br>Select waveform output [1]<br>mode compare match occurs.<br>[2] Set the timing for compare match<br>generation in TGR.<br>[3] Set the CST bit in TSTR to 1 to start the<br>Set output timing [2] count operation.<br>Start count operation [3]<br><Waveform output><br>**----- End of picture text -----**<br>

**Figure 10.7 Example of Setting Procedure for Waveform Output by Compare Match**

## (b) Examples of Waveform Output Operation:

Figure 10.8 shows an example of 0 output/1 output.

In this example TCNT has been designated as a free-running counter, and settings have been made such that 1 is output by compare match A, and 0 is output by compare match B. When the set level and the pin level coincide, the pin level does not change.

**==> picture [307 x 108] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT value<br>H'FFFF<br>TGRA<br>TGRB<br>H'0000 Time<br>No change No change<br>1 output<br>TIOCA<br>TIOCB No change No change 0 output<br>**----- End of picture text -----**<br>

**Figure 10.8 Example of 0 Output/1 Output Operation**

## Figure 10.9 shows an example of toggle output.

In this example, TCNT has been designated as a periodic counter (with counter clearing on compare match B), and settings have been made such that the output is toggled by both compare match A and compare match B.

**==> picture [316 x 105] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT value<br>Counter cleared by TGRB compare match<br>H'FFFF<br>TGRB<br>TGRA<br>H'0000 Time<br>Toggle output<br>TIOCB<br>TIOCA Toggle output<br>**----- End of picture text -----**<br>

**Figure 10.9 Example of Toggle Output Operation**

## (3) Input Capture Function

The TCNT value can be transferred to TGR on detection of the TIOC pin input edge.

Rising edge, falling edge, or both edges can be selected as the detected edge. For channels 0 and 1, it is also possible to specify another channel's counter input clock or compare match signal as the input capture source.

Note: When another channel's counter input clock is used as the input capture input for channels 0 and 1, P0/1 should not be selected as the counter input clock used for input capture input. Input capture will not be generated if P0/ 1 is selected.

## (a) Example of Input Capture Operation Setting Procedure

Figure 10.10 shows an example of the input capture operation setting procedure.

**==> picture [286 x 125] intentionally omitted <==**

**----- Start of picture text -----**<br>
[1] Designate TGR as an input capture<br>Input selection<br>register by means of TIOR, and select<br>rising edge, falling edge, or both edges<br>as the input capture source and input<br>signal edge.<br>Select input capture input [1]<br>[2] Set the CST bit in TSTR to 1 to start<br>the count operation.<br>Start count [2]<br><Input capture operation><br>**----- End of picture text -----**<br>

**Figure 10.10 Example of Input Capture Operation Setting Procedure**

## (b) Example of Input Capture Operation

Figure 10.11 shows an example of input capture operation.

In this example both rising and falling edges have been selected as the TIOCA pin input capture input edge, the falling edge has been selected as the TIOCB pin input capture input edge, and counter clearing by TGRB input capture has been designated for TCNT.

**==> picture [298 x 206] intentionally omitted <==**

**----- Start of picture text -----**<br>
Counter cleared by TIOCB<br>TCNT value<br>input (falling edge)<br>H'0180<br>H'0160<br>H'0010<br>H'0005<br>H'0000 Time<br>TIOCA<br>TGRA H'0005 H'0160 H'0010<br>TIOCB<br>TGRB H'0180<br>**----- End of picture text -----**<br>

**Figure 10.11 Example of Input Capture Operation**

## 10.4.2 Synchronous Operation

In synchronous operation, the values in a number of TCNT counters can be rewritten simultaneously (synchronous presetting). Also, a number of TCNT counters can be cleared simultaneously by making the appropriate setting in TCR (synchronous clearing).

Synchronous operation enables TGR to be incremented with respect to a single time base.

Channels 0 to 4 can all be designated for synchronous operation.

## (1) Example of Synchronous Operation Setting Procedure

Figure 10.12 shows an example of the synchronous operation setting procedure.

**==> picture [333 x 307] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronous operation<br>selection<br>Set synchronous<br>[1]<br>operation<br>Synchronous presetting Synchronous clearing<br>Set TCNT [2]<br>Clearing No<br>source generation<br>channel?<br>Yes<br>Select counter Set synchronous<br>[3] [4]<br>clearing source counter clearing<br>Start count [5] Start count [5]<br><Synchronous presetting> <Counter clearing> <Synchronous clearing><br>[1] Set to 1 the SYNC bits in TSYR corresponding to the channels to be designated for synchronous<br>operation.<br>[2] When the TCNT counter of any of the channels designated for synchronous operation is written to,<br>the same value is simultaneously written to the other TCNT counters.<br>[3] Use bits CCLR2 to CCLR0 in TCR to specify TCNT clearing by input capture/output compare, etc.<br>[4] Use bits CCLR2 to CCLR0 in TCR to designate synchronous clearing for the counter clearing source.<br>[5] Set to 1 the CST bits in TSTR for the relevant channels, to start the count operation.<br>**----- End of picture text -----**<br>

**Figure 10.12 Example of Synchronous Operation Setting Procedure**

## (2) Example of Synchronous Operation

Figure 10.13 shows an example of synchronous operation.

In this example, synchronous operation and PWM mode 1 have been designated for channels 0 to 2, TGRB_0 compare match has been set as the channel 0 counter clearing source, and synchronous clearing has been set for the channel 1 and 2 counter clearing source.

Three-phase PWM waveforms are output from pins TIOC0A, TIOC1A, and TIOC2A. At this time, synchronous presetting, and synchronous clearing by TGRB_0 compare match, are performed for channel 0 to 2 TCNT counters, and the data set in TGRB_0 is used as the PWM cycle.

For details of PWM modes, see section 10.4.5, PWM Modes .

**==> picture [301 x 173] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronous clearing by TGRB_0 compare match<br>TCNT_0 to TCNT_2<br>values<br>TGRB_0<br>TGRB_1<br>TGRA_0<br>TGRB_2<br>TGRA_1<br>TGRA_2<br>H'0000 Time<br>TIOC0A<br>TIOC1A<br>TIOC2A<br>**----- End of picture text -----**<br>

**Figure 10.13 Example of Synchronous Operation**

## 10.4.3 Buffer Operation

Buffer operation, provided for channels 0, 3, and 4, enables TGRC and TGRD to be used as buffer registers. In channel 0, TGRF can also be used as a buffer register.

Buffer operation differs depending on whether TGR has been designated as an input capture register or as a compare match register.

Note: TGRE_0 cannot be designated as an input capture register and can only operate as a compare match register.

Table 10.41 shows the register combinations used in buffer operation.

## **Table 10.41 Register Combinations in Buffer Operation**

|**Channel**|**Timer General Register**<br>**Buffer Register**|
|---|---|
|0|TGRA_0<br>TGRC_0|
||TGRB_0<br>TGRD_0|
||TGRE_0<br>TGRF_0|
|3|TGRA_3<br>TGRC_3|
||TGRB_3<br>TGRD_3|
|4|TGRA_4<br>TGRC_4|
||TGRB_4<br>TGRD_4|

- When TGR is an output compare register

   - When a compare match occurs, the value in the buffer register for the corresponding channel is transferred to the timer general register.

This operation is illustrated in Figure 10.14 .

**==> picture [271 x 58] intentionally omitted <==**

**----- Start of picture text -----**<br>
Compare match signal<br>Buffer Timer general Comparator TCNT<br>register register<br>**----- End of picture text -----**<br>

**Figure 10.14 Compare Match Buffer Operation**

- When TGR is an input capture register

   - When input capture occurs, the value in TCNT is transferred to TGR and the value previously held in the timer general register is transferred to the buffer register.

   - This operation is illustrated in Figure 10.15 .

**==> picture [267 x 56] intentionally omitted <==**

**----- Start of picture text -----**<br>
Input capture<br>signal<br>Buffer Timer general TCNT<br>register register<br>**----- End of picture text -----**<br>

**Figure 10.15 Input Capture Buffer Operation**

## (1) Example of Buffer Operation Setting Procedure

Figure 10.16 shows an example of the buffer operation setting procedure.

**==> picture [290 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
[1] Designate TGR as an input capture register or<br>Buffer operation<br>output compare register by means of TIOR.<br>[2] Designate TGR for buffer operation with bits<br>Select TGR function [1] BFA and BFB in TMDR.<br>[3] Set the CST bit in TSTR to 1 start the count<br>operation.<br>Set buffer operation [2]<br>Start count [3]<br><Buffer operation><br>**----- End of picture text -----**<br>

**Figure 10.16 Example of Buffer Operation Setting Procedure**

## (2) Examples of Buffer Operation

## (a) When TGR is an output compare register

Figure 10.17 shows an operation example in which PWM mode 1 has been designated for channel 0, and buffer operation has been designated for TGRA and TGRC. The settings used in this example are TCNT clearing by compare match B, 1 output at compare match A, and 0 output at compare match B. In this example, the TTSA bit in TBTM is cleared to 0.

As buffer operation has been set, when compare match A occurs the output changes and the value in buffer register TGRC is simultaneously transferred to timer general register TGRA. This operation is repeated each time that compare match A occurs.

For details of PWM modes, see section 10.4.5, PWM Modes .

**==> picture [306 x 154] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT value<br>TGRB_0 H'0450 H'0520<br>H'0200<br>TGRA_0<br>H'0000 Time<br>TGRC_0 H'0200 H'0450 H'0520<br>Transfer<br>TGRA_0 H'0200 H'0450<br>TIOCA<br>**----- End of picture text -----**<br>

**Figure 10.17 Example of Buffer Operation (1)**

## (b) When TGR is an input capture register

Figure 10.18 shows an operation example in which TGRA has been designated as an input capture register, and buffer operation has been designated for TGRA and TGRC.

Counter clearing by TGRA input capture has been set for TCNT, and both rising and falling edges have been selected as the TIOCA pin input capture input edge.

As buffer operation has been set, when the TCNT value is stored in TGRA upon the occurrence of input capture A, the value previously stored in TGRA is simultaneously transferred to TGRC.

**==> picture [300 x 173] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT value<br>H'0F07<br>H'09FB<br>H'0532<br>H'0000 Time<br>TIOCA<br>TGRA H'0532 H'0F07 H'09FB<br>TGRC H'0532 H'0F07<br>**----- End of picture text -----**<br>

**Figure 10.18 Example of Buffer Operation (2)**

## (3) Selecting Timing for Transfer from Buffer Registers to Timer General Registers in Buffer Operation

The timing for transfer from buffer registers to timer general registers can be selected in PWM mode 1 or 2 for channel 0 or in PWM mode 1 for channels 3 and 4 by setting the buffer operation transfer mode registers (TBTM_0, TBTM_3, and TBTM_4). Either compare match (initial setting) or TCNT clearing can be selected for the transfer timing. TCNT clearing as transfer timing is one of the following cases.

- When TCNT overflows (H'FFFF to H'0000)

- When H'0000 is written to TCNT during counting

- When TCNT is cleared to H'0000 under the condition specified in the CCLR2 to CCLR0 bits in TCR

## Note: TBTM must be modified only while TCNT stops.

Figure 10.19 shows an operation example in which PWM mode 1 is designated for channel 0 and buffer operation is designated for TGRA_0 and TGRC_0. The settings used in this example are TCNT_0 clearing by compare match B, 1 output at compare match A, and 0 output at compare match B. The TTSA bit in TBTM_0 is set to 1.

**==> picture [342 x 168] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_0 value<br>TGRB_0<br>H'0520<br>H'0450<br>H'0200<br>TGRA_0<br>H'0000 Time<br>TGRC_0 H'0200 H'0450 H'0520<br>Transfer<br>TGRA_0 H'0200 H'0450 H'0520<br>TIOCA<br>**----- End of picture text -----**<br>

**Figure 10.19 Example of Buffer Operation When TCNT_0 Clearing is Selected for TGRC_0 to TGRA_0 Transfer Timing**

## 10.4.4 Cascaded Operation

In cascaded operation, two 16-bit counters for different channels are used together as a 32-bit counter.

This function works by counting the channel 1 counter clock upon overflow/underflow of TCNT_2 as set in bits TPSC0 to TPSC2 in TCR.

Underflow occurs only when the lower 16-bit TCNT is in phase-counting mode.

Table 10.42 shows the register combinations used in cascaded operation.

Note: When phase counting mode is set for channel 1, the counter clock setting is invalid and the counters operates independently in phase counting mode.

## **Table 10.42 Cascaded Combinations**

|**Combination**|**Upper 16 Bits**|**Lower 16 Bits**|
|---|---|---|
|Channels 1 and 2|TCNT_1|TCNT_2|

For simultaneous input capture of TCNT_1 and TCNT_2 during cascaded operation, additional input capture input pins can be specified by the input capture control register (TICCR). The condition for input capture is the detection of an edge in the signal obtained from the logical OR of the signal on the main input pin and the signal on the additional input pin. For details, see (4), Cascaded Operation Example (c). For input capture in cascade connection, refer to section 10.7.22, Simultaneous Capture of TCNT_1 and TCNT_2 in Cascade Connection .

Table 10.43 show the TICCR setting and input capture input pins.

## **Table 10.43 TICCR Setting and Input Capture Input Pins**

|**Target Input Capture**|**TICCR Setting**<br>**Input Capture Input Pins**|
|---|---|
|Input capture from TCNT_1 to TGRA_1|I2AE bit = 0 (initial value)<br>TIOC1A|
||I2AE bit = 1<br>TIOC1A, TIOC2A|
|Input capture from TCNT_1 to TGRB_1|I2BE bit = 0 (initial value)<br>TIOC1B|
||I2BE bit = 1<br>TIOC1B, TIOC2B|
|Input capture from TCNT_2 to TGRA_2|I1AE bit = 0 (initial value)<br>TIOC2A|
||I1AE bit = 1<br>TIOC2A, TIOC1A|
|Input capture from TCNT_2 to TGRB_2|I1BE bit = 0 (initial value)<br>TIOC2B|
||I1BE bit = 1<br>TIOC2B, TIOC1B|

## (1) Example of Cascaded Operation Setting Procedure

Figure 10.20 shows an example of the setting procedure for cascaded operation.

**==> picture [291 x 97] intentionally omitted <==**

**----- Start of picture text -----**<br>
Cascaded operation [1] Set bits TPSC2 to TPSC0 in the channel 1<br>TCR to B'111 to select TCNT_2 overflow/<br>underflow counting.<br>Set cascading [1] [2] Set the CST bit in TSTR for the upper and<br>lower channel to 1 to start the count<br>operation.<br>Start count [2]<br><Cascaded operation><br>**----- End of picture text -----**<br>

**Figure 10.20 Cascaded Operation Setting Procedure**

## (2) Cascaded Operation Example (a)

Figure 10.21 illustrates the operation when TCNT_2 overflow/underflow counting has been set for TCNT_1 and phase counting mode has been designated for channel 2.

TCNT_1 is incremented by TCNT_2 overflow and decremented by TCNT_2 underflow.

**==> picture [336 x 91] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCLKC<br>TCLKD<br>TCNT_2 FFFD FFFE FFFF 0000 0001 0002 0001 0000 FFFF<br>TCNT_1 0000 0001 0000<br>**----- End of picture text -----**<br>

**Figure 10.21 Cascaded Operation Example (a)**

## (3) Cascaded Operation Example (b)

Figure 10.22 illustrates the operation when TCNT_1 and TCNT_2 have been cascaded and the I2AE bit in TICCR has been set to 1 to include the TIOC2A pin in the TGRA_1 input capture conditions. In this example, the IOA0 to IOA3 bits in TIOR_1 have selected the TIOC1A rising edge for the input capture timing while the IOA0 to IOA3 bits in TIOR_2 have selected the TIOC2A rising edge for the input capture timing.

Under these conditions, the rising edge of both TIOC1A and TIOC2A is used for the TGRA_1 input capture condition. For the TGRA_2 input capture condition, the TIOC2A rising edge is used.

**==> picture [370 x 221] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_2 value<br>H'FFFF<br>H'C256<br>H'6128<br>H'0000 Time<br>TCNT_1 H'0512 H'0513 H'0514<br>TIOC1A<br>TIOC2A<br>TGRA_1 H'0512 H'0513<br>TGRA_2 H'C256<br>As I1AE in TICCR is 0, data is not captured in TGRA_2 at the TIOC1A input timing.<br>**----- End of picture text -----**<br>

**Figure 10.22 Cascaded Operation Example (b)**

## (4) Cascaded Operation Example (c)

Figure 10.23 illustrates the operation when TCNT_1 and TCNT_2 have been cascaded and the I2AE and I1AE bits in TICCR have been set to 1 to include the TIOC2A and TIOC1A pins in the TGRA_1 and TGRA_2 input capture conditions, respectively. In this example, the IOA0 to IOA3 bits in both TIOR_1 and TIOR_2 have selected both the rising and falling edges for the input capture timing. Under these conditions, the ORed result of TIOC1A and TIOC2A input is used for the TGRA_1 and TGRA_2 input capture conditions.

**==> picture [344 x 217] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_2 value<br>H'FFFF<br>H'C256<br>H'9192<br>H'6128<br>H'2064<br>H'0000 Time<br>TCNT_1 H'0512 H'0513 H'0514<br>TIOC1A<br>TIOC2A<br>When the high level is on either of the input pins, an edge on the other pin does not act<br>as an input-capture condition.<br>TGRA_1 H'0512 H'0513 H'0514<br>TGRA_2 H'6128 H'2064 H'C256 H'9192<br>**----- End of picture text -----**<br>

**Figure 10.23 Cascaded Operation Example (c)**

## (5) Cascaded Operation Example (d)

Figure 10.24 illustrates the operation when TCNT_1 and TCNT_2 have been cascaded and the I2AE bit in TICCR has been set to 1 to include the TIOC2A pin in the TGRA_1 input capture conditions. In this example, the IOA0 to IOA3 bits in TIOR_1 have selected TGRA_0 compare match or input capture occurrence for the input capture timing while the IOA0 to IOA3 bits in TIOR_2 have selected the TIOC2A rising edge for the input capture timing.

Under these conditions, as TIOR_1 has selected TGRA_0 compare match or input capture occurrence for the input capture timing, the TIOC2A edge is not used for TGRA_1 input capture condition although the I2AE bit in TICCR has been set to 1.

**==> picture [343 x 280] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_0 value Compare match between TCNT_0 and TGRA_0<br>TGRA_0<br>H'0000 Time<br>TCNT_2 value<br>H'FFFF<br>H'D000<br>H'0000 Time<br>TCNT_1 H'0512 H'0513<br>TIOC1A<br>TIOC2A<br>TGRA_1 H'0513<br>TGRA_2 H'D000<br>**----- End of picture text -----**<br>

**Figure 10.24 Cascaded Operation Example (d)**

## 10.4.5 PWM Modes

In PWM mode, PWM waveforms are output from the output pins. The output level can be selected as 0, 1, or toggle output in response to a compare match of each TGR.

TGR registers settings can be used to output a PWM waveform in the range of 0% to 100% duty.

Designating TGR compare match as the counter clearing source enables the period to be set in that register. All channels can be designated for PWM mode independently. Synchronous operation is also possible.

There are two PWM modes, as described below.

- PWM mode 1

PWM output is generated from the TIOCA and TIOCC pins by pairing TGRA with TGRB and TGRC with TGRD. The output specified by bits IOA0 to IOA3 and IOC0 to IOC3 in TIOR is output from the TIOCA and TIOCC pins at compare matches A and C, and the output specified by bits IOB0 to IOB3 and IOD0 to IOD3 in TIOR is output at compare matches B and D. The initial output value is the value set in TGRA or TGRC. If the set values of paired TGRs are identical, the output value does not change when a compare match occurs. In PWM mode 1, a maximum 8-phase PWM output is possible.

- PWM mode 2

PWM output is generated using one TGR as the cycle register and the others as duty registers. The output specified in TIOR is performed by means of compare matches. Upon counter clearing by a cycle register compare match, the output value of each pin is the initial value set in TIOR. If the set values of the cycle and duty registers are identical, the output value does not change when a compare match occurs.

In PWM mode 2, a maximum 8-phase PWM output is possible in combination use with synchronous operation.

The correspondence between PWM output pins and registers is shown in Table 10.44 .

## **Table 10.44 PWM Output Registers and Output Pins**

|**Channel**|**Registers**|**Output Pins**|**Output Pins**|
|---|---|---|---|
|||**PWM Mode 1**|**PWM Mode 2**|
|0|TGRA_0|TIOC0A|TIOC0A|
||TGRB_0||TIOC0B|
||TGRC_0|TIOC0C|TIOC0C|
||TGRD_0||TIOC0D|
|1|TGRA_1|TIOC1A|TIOC1A|
||TGRB_1||TIOC1B|
|2|TGRA_2|TIOC2A|TIOC2A|
||TGRB_2||TIOC2B|
|3|TGRA_3|TIOC3A|Cannot be set|
||TGRB_3||Cannot be set|
||TGRC_3|TIOC3C|Cannot be set|
||TGRD_3||Cannot be set|
|4|TGRA_4|TIOC4A|Cannot be set|
||TGRB_4||Cannot be set|
||TGRC_4|TIOC4C|Cannot be set|
||TGRD_4||Cannot be set|

Note: In PWM mode 2, PWM output is not possible for the TGR register in which the period is set.

## (1) Example of PWM Mode Setting Procedure

Figure 10.25 shows an example of the PWM mode setting procedure.

**==> picture [288 x 222] intentionally omitted <==**

**----- Start of picture text -----**<br>
[1] Select the counter clock with bits TPSC2 to<br>PWM mode<br>TPSC0 in TCR.  At the same time, select the<br>input clock edge with bits CKEG1 and<br>CKEG0 in TCR.<br>Select counter clock [1]<br>[2] Use bits CCLR2 to CCLR0 in TCR to select<br>the TGR to be used as the TCNT clearing<br>Select counter clearing [2] source.<br>source [3] Use TIOR to designate the TGR as an output<br>compare register, and select the initial value<br>and output value.<br>Select waveform [3] [4] Set the cycle in the TGR selected in [2], and<br>output level set the duty in the other TGR.<br>[5] Select the PWM mode with bits MD3 to MD0<br>Set TGR [4] in TMDR.<br>[6] Set the CST bit in TSTR to 1 to start the<br>count operation.<br>Set PWM mode [5]<br>Start count [6]<br><PWM mode><br>**----- End of picture text -----**<br>

**Figure 10.25 Example of PWM Mode Setting Procedure**

## (2) Examples of PWM Mode Operation

Figure 10.26 shows an example of PWM mode 1 operation.

In this example, TGRA compare match is set as the TCNT clearing source, 0 is set for the TGRA initial output value and output value, and 1 is set as the TGRB output value.

In this case, the value set in TGRA is used as the period, and the values set in the TGRB registers are used as the duty levels.

**==> picture [286 x 89] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT value Counter cleared by<br>TGRA compare match<br>TGRA<br>TGRB<br>H'0000 Time<br>TIOCA<br>**----- End of picture text -----**<br>

**Figure 10.26 Example of PWM Mode Operation (1)**

Figure 10.27 shows an example of PWM mode 2 operation.

In this example, synchronous operation is designated for channels 0 and 1, TGRB_1 compare match is set as the TCNT clearing source, and 0 is set for the initial output value and 1 for the output value of the other TGR registers (TGRA_0 to TGRD_0, TGRA_1), outputting a 5-phase PWM waveform.

In this case, the value set in TGRB_1 is used as the cycle, and the values set in the other TGRs are used as the duty levels.

**==> picture [344 x 213] intentionally omitted <==**

**----- Start of picture text -----**<br>
Counter cleared by<br>TCNT value TGRB_1 compare match<br>TGRB_1<br>TGRA_1<br>TGRD_0<br>TGRC_0<br>TGRB_0<br>TGRA_0<br>H'0000<br>Time<br>TIOC0A<br>TIOC0B<br>TIOC0C<br>TIOC0D<br>TIOC1A<br>**----- End of picture text -----**<br>

**Figure 10.27 Example of PWM Mode Operation (2)**

Figure 10.28 shows examples of PWM waveform output with 0% duty and 100% duty in PWM mode.

**==> picture [347 x 397] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT value<br>TGRB rewritten<br>TGRA<br>TGRB<br>TGRB rewritten<br>TGRB rewritten<br>H'0000 Time<br>TIOCA 0% duty<br>Output does not change when cycle register and duty register<br>compare matches occur simultaneously<br>TCNT value<br>TGRB rewritten<br>TGRA<br>TGRB rewritten<br>TGRB TGRB rewritten<br>H'0000 Time<br>100% duty<br>TIOCA<br>Output does not change when cycle register and duty<br>register compare matches occur simultaneously<br>TCNT value<br>TGRB rewritten<br>TGRA<br>TGRB rewritten<br>TGRB<br>TGRB rewritten<br>H'0000 Time<br>100% duty 0% duty<br>TIOCA<br>**----- End of picture text -----**<br>

**Figure 10.28 Example of PWM Mode Operation (3)**

## 10.4.6 Phase Counting Mode

In phase counting mode, the phase difference between two external clock inputs is detected and TCNT is incremented/ decremented accordingly. This mode can be set for channels 1 and 2.

When phase counting mode is set, an external clock is selected as the counter input clock and TCNT operates as an up/ down-counter regardless of the setting of bits TPSC0 to TPSC2 and bits CKEG0 and CKEG1 in TCR. However, the functions of bits CCLR0 and CCLR1 in TCR, and of TIOR, TIER, and TGR, are valid, and input capture/compare match and interrupt functions can be used.

This can be used for two-phase encoder pulse input.

If overflow occurs when TCNT is counting up, the TCFV flag in TSR is set; if underflow occurs when TCNT is counting down, the TCFU flag is set.

The TCFD bit in TSR is the count direction flag. Reading the TCFD flag reveals whether TCNT is counting up or down.

Table 10.45 shows the correspondence between external clock pins and channels.

## **Table 10.45 Phase Counting Mode Clock Input Pins**

|**Channels**|**External Clock Pins**|
|---|---|
||**A-Phase**<br>**B-Phase**|
|When channel 1 is set to phase counting mode|TCLKA<br>TCLKB|
|When channel 2 is set to phase counting mode|TCLKC<br>TCLKD|

## (1) Example of Phase Counting Mode Setting Procedure

Figure 10.29 shows an example of the phase counting mode setting procedure.

**==> picture [272 x 90] intentionally omitted <==**

**----- Start of picture text -----**<br>
[1] Select phase counting mode with bits<br>Phase counting mode MD3 to MD0 in TMDR.<br>[2] Set the CST bit in TSTR to 1 to start<br>Select phase counting [1] the count operation.<br>mode<br>Start count [2]<br><Phase counting mode><br>**----- End of picture text -----**<br>

**Figure 10.29 Example of Phase Counting Mode Setting Procedure**

## (2) Examples of Phase Counting Mode Operation

In phase counting mode, TCNT counts up or down according to the phase difference between two external clocks. There are four modes, according to the count conditions.

## (a) Phase counting mode 1

Figure 10.30 shows an example of phase counting mode 1 operation, and Table 10.46 summarizes the TCNT up/downcount conditions.

**==> picture [329 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCLKA (channel 1)<br>TCLKC (channel 2)<br>TCLKB (channel 1)<br>TCLKD (channel 2)<br>TCNT value<br>Up-count Down-count<br>Time<br>**----- End of picture text -----**<br>

**Figure 10.30 Example of Phase Counting Mode 1 Operation**

**Table 10.46 Up/Down-Count Conditions in Phase Counting Mode 1**

|**TCLKA (Channel 1)**|**TCLKA (Channel 1)**|**TCLKB (Channel 1)**|**TCLKB (Channel 1)**||
|---|---|---|---|---|
|**TCLKC (Channel 2)**||**TCLKD (Channel 2)**||**Operation**|
|High level||||Up-count|
|Low level|||||
|||Low level|||
|||High level|||
|High level||||Down-count|
|Low level|||||
|||High level|||
|||Low level|||

[Legend]

:Rising edge :Falling edge

## (b) Phase counting mode 2

Figure 10.31 shows an example of phase counting mode 2 operation, and Table 10.47 summarizes the TCNT up/downcount conditions.

**==> picture [332 x 121] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCLKA (channel 1)<br>TCLKC (channel 2)<br>TCLKB (channel 1)<br>TCLKD (channel 2)<br>TCNT value<br>Up-count Down-count<br>Time<br>**----- End of picture text -----**<br>

**Figure 10.31 Example of Phase Counting Mode 2 Operation**

**Table 10.47 Up/Down-Count Conditions in Phase Counting Mode 2**

|**TCLKA (Channel 1)**<br>**TCLKC (Channel 2)**<br>**TCLKB (Channel 1)**<br>**TCLKD (Channel 2)**<br>**Operation**|**TCLKA (Channel 1)**<br>**TCLKC (Channel 2)**<br>**TCLKB (Channel 1)**<br>**TCLKD (Channel 2)**<br>**Operation**|
|---|---|
|<br>'||
|High level<br>Dont care||
|Low level<br>Don't care||
|<br>'||
|Low level<br>Dont care||
|<br>||
||High level<br>Up-count|
|High level<br>Don't care||
|<br>'||
|Low level<br>Dont care||
|<br>'||
|High level<br>Dont care||
|<br>||
||Low level<br>Down-count|

[Legend]

:Rising edge :Falling edge

## (c) Phase counting mode 3

Figure 10.32 shows an example of phase counting mode 3 operation, and Table 10.48 summarizes the TCNT up/downcount conditions.

**==> picture [326 x 134] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCLKA (channel 1)<br>TCLKC (channel 2)<br>TCLKB (channel 1)<br>TCLKD (channel 2)<br>TCNT value<br>Down-count<br>Up-count<br>Time<br>**----- End of picture text -----**<br>

**Figure 10.32 Example of Phase Counting Mode 3 Operation**

## **Table 10.48 Up/Down-Count Conditions in Phase Counting Mode 3**

|**TCLKA (Channel 1)**<br>**TCLKC (Channel 2)**<br>**TCLKB (Channel 1)**<br>**TCLKD (Channel 2)**<br>**Operation**|**TCLKA (Channel 1)**<br>**TCLKC (Channel 2)**<br>**TCLKB (Channel 1)**<br>**TCLKD (Channel 2)**<br>**Operation**|**TCLKA (Channel 1)**<br>**TCLKC (Channel 2)**<br>**TCLKB (Channel 1)**<br>**TCLKD (Channel 2)**<br>**Operation**|
|---|---|---|
|<br>'|||
|High level<br>Dont care|||
|<br>'|||
|Low level||Dont care|
|<br>'|||
|Low level<br>Dont care|||
|<br>|||
||High level<br>Up-count||
|<br>|||
|High level||Down-count|
|<br>'|||
|Low level<br>Dont care|||
|<br>'|||
|High level<br>Dont care|||
|Low level<br>Don't care|||

[Legend]

:Rising edge :Falling edge

## (d) Phase counting mode 4

Figure 10.33 shows an example of phase counting mode 4 operation, and Table 10.49 summarizes the TCNT up/downcount conditions.

**==> picture [327 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCLKA (channel 1)<br>TCLKC (channel 2)<br>TCLKB (channel 1)<br>TCLKD (channel 2)<br>TCNT value<br>Down-count<br>Up-count<br>Time<br>**----- End of picture text -----**<br>

**Figure 10.33 Example of Phase Counting Mode 4 Operation**

**Table 10.49 Up/Down-Count Conditions in Phase Counting Mode 4**

|**TCLKA (Channel 1)**<br>**TCLKC (Channel 2)**<br>**TCLKB (Channel 1)**<br>**TCLKD (Channel 2)**<br>**Operation**|**TCLKA (Channel 1)**<br>**TCLKC (Channel 2)**<br>**TCLKB (Channel 1)**<br>**TCLKD (Channel 2)**<br>**Operation**|
|---|---|
|High level<br>Up-count<br>Low level||
|Low level<br>Don't care<br>High level||
|High level<br>Down-count<br>Low level||
|High level<br>Don't care<br>||
||Low level|

[Legend]

:Rising edge

:Falling edge

## (3) Phase Counting Mode Application Example

Figure 10.34 shows an example in which channel 1 is in phase counting mode, and channel 1 is coupled with channel 0 to input servo motor 2-phase encoder pulses in order to detect position or speed.

Channel 1 is set to phase counting mode 1, and the encoder pulse A-phase and B-phase are input to TCLKA and TCLKB.

Channel 0 operates with TCNT counter clearing by TGRC_0 compare match; TGRA_0 and TGRC_0 are used for the compare match function and are set with the speed control period and position control period. TGRB_0 is used for input capture, with TGRB_0 and TGRD_0 operating in buffer mode. The channel 1 counter input clock is designated as the TGRB_0 input capture source, and the pulse widths of 2-phase encoder 4-multiplication pulses are detected.

TGRA_1 and TGRB_1 for channel 1 are designated for input capture, and channel 0 TGRA_0 and TGRC_0 compare matches are selected as the input capture source and store the up/down-counter values for the control periods.

This procedure enables the accurate detection of position and speed.

**==> picture [331 x 268] intentionally omitted <==**

**----- Start of picture text -----**<br>
Channel 1<br>TCLKA Edge<br>detection TCNT_1<br>TCLKB circuit<br>TGRA_1<br>(speed period capture)<br>TGRB_1<br>(position period capture)<br>TCNT_0<br>TGRA_0 +<br>(speed control period) -<br>TGRC_0 +<br>(position control period) -<br>TGRB_0 (pulse width capture)<br>TGRD_0 (buffer operation)<br>Channel 0<br>**----- End of picture text -----**<br>

**Figure 10.34 Phase Counting Mode Application Example**

## 10.4.7 Reset-Synchronized PWM Mode

In the reset-synchronized PWM mode, three-phase output of positive and negative PWM waveforms that share a common wave transition point can be obtained by combining channels 3 and 4.

When set for reset-synchronized PWM mode, the TIOC3B, TIOC3D, TIOC4A, TIOC4C, TIOC4B, and TIOC4D pins function as PWM output pins and TCNT_3 functions as an upcounter.

Table 10.50 shows the PWM output pins used. Table 10.51 shows the settings of the registers.

## **Table 10.50 Output Pins for Reset-Synchronized PWM Mode**

|**Channel**|**Output Pin**<br>**Description**|
|---|---|
|3|TIOC3B<br>PWM output pin 1|
||TIOC3D<br>PWM output pin 1' (negative-phase waveform of PWM output 1)|
|4|TIOC4A<br>PWM output pin 2|
||TIOC4C<br>PWM output pin 2' (negative-phase waveform of PWM output 2)|
||TIOC4B<br>PWM output pin 3|
||TIOC4D<br>PWM output pin 3' (negative-phase waveform of PWM output 3)|

## **Table 10.51 Register Settings for Reset-Synchronized PWM Mode**

|**Register**|**Description of Setting**|
|---|---|
|TCNT_3|Initial setting of H'0000|
|TCNT_4|Initial setting of H'0000|
|TGRA_3|Set count cycle for TCNT_3|
|TGRB_3|Sets the turning point for PWM waveform output by the TIOC3B and TIOC3D pins|
|TGRA_4|Sets the turning point for PWM waveform output by the TIOC4A and TIOC4C pins|
|TGRB_4|Sets the turning point for PWM waveform output by the TIOC4B and TIOC4D pins|

## (1) Procedure for Selecting the Reset-Synchronized PWM Mode

Figure 10.35 shows an example of procedure for selecting the reset synchronized PWM mode.

**==> picture [304 x 384] intentionally omitted <==**

**----- Start of picture text -----**<br>
[1]  Clear the CST3 and CST4 bits in the TSTR<br>Reset-synchronized<br>PWM mode       to 0 to halt the counting of TCNT. The<br>      reset-synchronized PWM mode must be set<br>      up while TCNT_3 and TCNT_4 are halted.<br>Stop counting [1]<br>[2]  Set bits TPSC2-TPSC0 and CKEG1 and<br>      CKEG0 in the TCR_3 to select the counter<br>Select counter clock and       clock and clock edge for channel 3. Set bits<br>counter clear source [2]       CCLR2-CCLR0 in the TCR_3 to select TGRA<br>      compare-match as a counter clear source.<br>Brushless DC motor  [3]  When performing brushless DC motor control,<br>control setting [3]       set bit BDC in the timer gate control register<br>      (TGCR) and set the feedback signal input source<br>      and output chopping or gate signal direct output.<br>Set TCNT [4]<br>[4]  Reset TCNT_3 and TCNT_4 to H'0000.<br>Set TGR [5] [5]  TGRA_3 is the period register. Set the waveform<br>      period value in TGRA_3. Set the transition timing<br>      of the PWM output waveforms in TGRB_3,<br>      TGRA_4, and TGRB_4. Set times within the<br>PWM cycle output enabling,<br>[6]       compare-match range of TCNT_3.<br>PWM output level setting<br>X ≤ TGRA_3 (X: set value).<br>Set reset-synchronized<br>PWM mode [7] [6]  Select enabling/disabling of toggle output<br>      synchronized with the PWM cycle using bit PSYE<br>      in the timer output control register 1 (TOCR1), and set<br>Enable waveform output [8]       the PWM output level with bits OLSP and OLSN.<br>      When specifying the PWM output level by using TOLBR<br>      as a buffer for TOCR2, see figure 10.3.<br>PFC setting [9]<br>[7]  Set bits MD3-MD0 in TMDR_3 to B'1000 to select<br>      the reset-synchronized PWM mode. Do not set to TMDR_4.<br>Start count operation [10]<br>[8]  Set the enabling/disabling of the PWM waveform output<br>      pin in TOER.<br>Reset-synchronized PWM mode<br>[9]  Set the port control register and the port I/O register.<br>[10]  Set the CST3 bit in the TSTR to 1 to start the count<br>      operation.<br>Note: The output waveform starts to toggle operation at the point of<br>          TCNT_3 = TGRA_3 = X by setting X = TGRA_3, i.e., cycle = duty.<br>**----- End of picture text -----**<br>

**Figure 10.35 Procedure for Selecting Reset-Synchronized PWM Mode**

## (2) Reset-Synchronized PWM Mode Operation

Figure 10.36 shows an example of operation in the reset-synchronized PWM mode. TCNT_3 and TCNT_4 operate as upcounters. The counter is cleared when a TCNT_3 and TGRA_3 compare-match occurs, and then begins incrementing from H'0000. The PWM output pin output toggles with each occurrence of a TGRB_3, TGRA_4, TGRB_4 comparematch, and upon counter clears.

**==> picture [332 x 231] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_3 and TCNT_4<br>values<br>TGRA_3<br>TGRB_3<br>TGRA_4<br>TGRB_4<br>H'0000<br>Time<br>TIOC3B<br>TIOC3D<br>TIOC4A<br>TIOC4C<br>TIOC4B<br>TIOC4D<br>**----- End of picture text -----**<br>

**Figure 10.36 Reset-Synchronized PWM Mode Operation Example (When TOCR’s OLSN = 1 and OLSP = 1)**

## 10.4.8 Complementary PWM Mode

In the complementary PWM mode, three-phase output of non-overlapping positive and negative PWM waveforms can be obtained by combining channels 3 and 4. PWM waveforms without non-overlapping interval are also available.

In complementary PWM mode, TIOC3B, TIOC3D, TIOC4A, TIOC4B, TIOC4C, and TIOC4D pins function as PWM output pins, the TIOC3A pin can be set for toggle output synchronized with the PWM period. TCNT_3 and TCNT_4 function as up/down counters.

Table 10.52 shows the PWM output pins used. Table 10.53 shows the settings of the registers used.

**Table 10.52 Output Pins for Complementary PWM Mode**

|**Channel**|**Output Pin**<br>**Description**|
|---|---|
|3|TIOC3A<br>Toggle output synchronized with PWM period (or I/O port)|
||TIOC3B<br>PWM output pin 1|
||TIOC3C<br>I/O port*|
||TIOC3D<br>PWM output pin 1'<br>(non-overlapping negative-phase waveform of PWM output 1; PWM output without<br>non-overlapping interval is also available)|
|4|TIOC4A<br>PWM output pin 2|
||TIOC4B<br>PWM output pin 3|
||TIOC4C<br>PWM output pin 2'<br>(non-overlapping negative-phase waveform of PWM output 2; PWM output without<br>non-overlapping interval is also available)|
||TIOC4D<br>PWM output pin 3'<br>(non-overlapping negative-phase waveform of PWM output 3; PWM output without<br>non-overlapping interval is also available)|

Note: * Avoid setting the TIOC3C pin as a timer I/O pin in the complementary PWM mode.

**Table 10.53 Register Settings for Complementary PWM Mode**

|**Channel**|**Counter/Register**<br>**Description**<br>**Read/Write from CPU**|
|---|---|
|3|TCNT_3<br>Start of up-count from value set in dead time register<br>Maskable by TRWER setting*|
||TGRA_3<br>Set TCNT_3 upper limit value (1/2 carrier cycle + dead<br>time)<br>Maskable by TRWER setting*|
||TGRB_3<br>PWM output 1 compare register<br>Maskable by TRWER setting*|
||TGRC_3<br>TGRA_3 buffer register<br>Always readable/writable|
||TGRD_3<br>PWM output 1/TGRB_3 buffer register<br>Always readable/writable|
|4|TCNT_4<br>Up-count start, initialized to H'0000<br>Maskable by TRWER setting*|
||TGRA_4<br>PWM output 2 compare register<br>Maskable by TRWER setting*|
||TGRB_4<br>PWM output 3 compare register<br>Maskable by TRWER setting*|
||TGRC_4<br>PWM output 2/TGRA_4 buffer register<br>Always readable/writable|
||TGRD_4<br>PWM output 3/TGRB_4 buffer register<br>Always readable/writable|
|Timer dead time data register (TDDR)<br>Set TCNT_4 and TCNT_3 offset value (dead time value)<br>Maskable by TRWER setting*||
|Timer cycle data register (TCDR)<br>Set TCNT_4 upper limit value (1/2 carrier cycle)<br>Maskable by TRWER setting*||
|Timer cycle buffer register (TCBR)<br>TCDR buffer register<br>Always readable/writable||
|Subcounter (TCNTS)<br>Subcounter for dead time generation<br>Read-only||
|Temporary register 1 (TEMP1)<br>PWM output 1/TGRB_3 temporary register<br>Not readable/writable||
|Temporary register 2 (TEMP2)<br>PWM output 2/TGRA_4 temporary register<br>Not readable/writable||
|Temporary register 3 (TEMP3)<br>PWM output 3/TGRB_4 temporary register<br>Not readable/writable||

Note: * Access can be enabled or disabled according to the setting of bit 0 (RWE) in TRWER (timer read/write enable register).

**==> picture [344 x 390] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGRC_3 TCBR<br>TDDR TGRA_3 TCDR<br>PWM cycle<br>Comparator Match output<br>signal PWM output 1<br>PWM output 2<br>TCNT_3 TCNTS TCNT_4 PWM output 3<br>PWM output 4<br>PWM output 5<br>Comparator<br>Match<br>PWM output 6<br>signal<br>TGRD_3 TGRC_4 TGRD_4<br>: Registers that can always be read or written from the CPU<br>: Registers that can be read or written from the CPU<br>  (but for which access disabling can be set by TRWER)<br>: Registers that cannot be read or written from the CPU<br>  (except for TCNTS, which can only be read)<br>TGRA_3 compare- match interrupt TCNT_4 underflow  interrupt<br>Output controller<br>Temp 1 TGRB_3 Temp 2 TGRA_4 Temp 3 TGRB_4<br>**----- End of picture text -----**<br>

**Figure 10.37 Block Diagram of Channels 3 and 4 in Complementary PWM Mode**

## (1) Example of Complementary PWM Mode Setting Procedure

An example of the complementary PWM mode setting procedure is shown in Figure 10.38 .

||||[1]  Clear bits CST3 and CST4 in the timer start register|
|---|---|---|---|
|Complementary PWM mode|||(TSTR) to 0, and halt timer counter (TCNT) operation.|
||||Perform complementary PWM mode setting when|
||||TCNT_3 and TCNT_4 are stopped.|
|Stop count operation||[1]|[2]  Set the same counter clock and clock edge for channels|
||||3 and 4 with bits TPSC2-TPSC0 and bits CKEG1 and|
||||CKEG0 in the timer control register (TCR). Use bits|
|Counter clock, counter clear<br>source selection||[2]|CCLR2-CCLR0 to set synchronous clearing only when<br>restarting by a synchronous clear from another channel|
||||during complementary PWM mode operation.|
|Brushless DC motor control<br>setting||[3]|[3]  When performing brushless DC motor control, set bit BDC<br>in the timer gate control register (TGCR) and set the|
||||feedback signal input source and output chopping or gate|
||||signal direct output.|
|TCNT setting||[4]||
||||[4]  Set the dead time in TCNT_3. Set TCNT_4 to H'0000.|
|Inter-channel synchronization<br>setting||[5]|[5]  Set only when restarting by a synchronous clear from<br>another channel during complementary PWM mode<br>operation. In this case, synchronize the channel generating|
||||the synchronous clear with channels 3 and 4 using the timer|
|TGR setting||[6]|synchro register (TSYR).|
||||[6]  Set the output PWM duty in the duty registers (TGRB_3,|
|Enable/disable dead time<br>generation||[7]|TGRA_4, TGRB_4) and buffer registers (TGRD_3, TGRC_4,<br>TGRD_4). Set the same initial value in each corresponding<br>TGR.|
|Dead time, carrier cycle<br>setting||[8]|[7]  This setting is necessary only when no dead time should be<br>generated. Make appropriate settings in the timer dead time|
||||enable register (TDER) so that no dead time is generated.|
|PWM cycle output enabling,<br>PWM output level setting||[9]|[8]  Set the dead time in the dead time register (TDDR), 1/2 the<br>carrier cycle in the timer cycle data register (TCDR) and|
||||timer cycle buffer register (TCBR), and 1/2 the carrier cycle|
|Complementary PWM mode<br>setting||[10]|plus the dead time in TGRA_3 and TGRC_3. When no dead<br>time generation is selected, set 1 in TDDR and 1/2 the carrier|
||||cycle + 1 in TGRA_3 and TGRC_3.|
|Enable waveform output||[11]|[9]  Select enabling/disabling of toggle output synchronized with<br>the PWM cycle using bit PSYE in the timer output control<br>register 1 (TOCR1), and set the PWM output level with bits OLSP|
||||and OLSN. When specifying the PWM output level by using|
|Start count operation<br>PFC setting||[12]|TOLBR as a buffer for TOCR2, see figure 10.3.|
||||[10]  Select complementary PWM mode in timer mode register 3<br>(TMDR_3). Do not set in TMDR_4.|
|Start count operation||[13]||
||||[11]  Set enabling/disabling of PWM waveform output pin output in|
||||the timer output master enable register (TOER).|
|<Complementary PWM mode>|||[12]  Set the port control register and the port I/O register.|
||||[13]  Set bits CST3 and CST4 in TSTR to 1 simultaneously to start|
||||the count operation.|

**Figure 10.38 Example of Complementary PWM Mode Setting Procedure**

## (2) Outline of Complementary PWM Mode Operation

In complementary PWM mode, 6-phase PWM output is possible. Figure 10.39 illustrates counter operation in complementary PWM mode, and Figure 10.40 shows an example of complementary PWM mode operation.

## (a) Counter Operation

In complementary PWM mode, three counters—TCNT_3, TCNT_4, and TCNTS—perform up/down-count operations.

TCNT_3 is automatically initialized to the value set in TDDR when complementary PWM mode is selected and the CST bit in TSTR is 0.

When the CST bit is set to 1, TCNT_3 counts up to the value set in TGRA_3, then switches to down-counting when it matches TGRA_3. When the TCNT_3 value matches TDDR, the counter switches to up-counting, and the operation is repeated in this way.

TCNT_4 is initialized to H'0000.

When the CST bit is set to 1, TCNT_4 counts up in synchronization with TCNT_3, and switches to down-counting when it matches TCDR. On reaching H'0000, TCNT_4 switches to up-counting, and the operation is repeated in this way.

TCNTS is a read-only counter. It need not be initialized.

When TCNT_3 matches TCDR during TCNT_3 and TCNT_4 up/down-counting, down-counting is started, and when TCNTS matches TCDR, the operation switches to up-counting. When TCNTS matches TGRA_3, it is cleared to H'0000. When TCNT_4 matches TDDR during TCNT_3 and TCNT_4 down-counting, up-counting is started, and when TCNTS matches TDDR, the operation switches to down-counting. When TCNTS reaches H'0000, it is set with the value in TGRA_3.

TCNTS is compared with the compare register and temporary register in which the PWM duty is set during the count operation only.

**==> picture [385 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_3<br>Counter value TCNT_4<br>TCNTS<br>TGRA_3<br>TCDR<br>TCNT_3<br>TCNT_4<br>TCNTS<br>TDDR<br>H'0000<br>Time<br>**----- End of picture text -----**<br>

**Figure 10.39 Complementary PWM Mode Counter Operation**

## (b) Register Operation

In complementary PWM mode, nine registers are used, comprising compare registers, buffer registers, and temporary registers. Figure 10.40 shows an example of complementary PWM mode operation.

The registers which are constantly compared with the counters to perform PWM output are TGRB_3, TGRA_4, and TGRB_4. When these registers match the counter, the value set in bits OLSN and OLSP in the timer output control register (TOCR) is output.

The buffer registers for these compare registers are TGRD_3, TGRC_4, and TGRD_4.

Between a buffer register and compare register there is a temporary register. The temporary registers cannot be accessed by the CPU.

Data in a compare register is changed by writing the new data to the corresponding buffer register. The buffer registers can be read or written at any time.

The data written to a buffer register is constantly transferred to the temporary register in the Ta interval. Data is not transferred to the temporary register in the Tb interval. Data written to a buffer register in this interval is transferred to the temporary register at the end of the Tb interval.

The value transferred to a temporary register is transferred to the compare register when TCNTS for which the Tb interval ends matches TGRA_3 when counting up, or H'0000 when counting down. The timing for transfer from the temporary register to the compare register can be selected with bits MD3 to MD0 in the timer mode register (TMDR). Figure 10.40 shows an example in which the mode is selected in which the change is made in the trough.

In the Tb interval (Tb1 in Figure 10.40 ) in which data transfer to the temporary register is not performed, the temporary register has the same function as the compare register, and is compared with the counter. In this interval, therefore, there are two compare match registers for one-phase output, with the compare register containing the pre-change data, and the temporary register containing the new data. In this interval, the three counters—TCNT_3, TCNT_4, and TCNTS—and two registers—compare register and temporary register—are compared, and PWM output controlled accordingly.

**==> picture [404 x 441] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transfer from temporary  Transfer from temporary<br>register to compare register register to compare register<br>Tb2 Ta Tb1 Ta Tb2 Ta<br>TGRA_3<br>TCNTS<br>TCDR<br>TCNT_3<br>TGRA_4 TCNT_4<br>TGRC_4<br>TDDR<br>H'0000<br>Buffer register<br>TGRC_4 H'6400 H'0080<br>Temporary register<br>TEMP2 H'6400 H'0080<br>Compare register<br>TGRA_4 H'6400 H'0080<br>Output waveform<br>Output waveform<br>(Output waveform is active-low)<br>**----- End of picture text -----**<br>

**Figure 10.40 Example of Complementary PWM Mode Operation**

## (c) Initialization

In complementary PWM mode, there are six registers that must be initialized. In addition, there is a register that specifies whether to generate dead time (it should be used only when dead time generation should be disabled).

Before setting complementary PWM mode with bits MD3 to MD0 in the timer mode register (TMDR), the following initial register values must be set.

TGRC_3 operates as the buffer register for TGRA_3, and should be set with 1/2 the PWM carrier cycle + dead time Td. The timer cycle buffer register (TCBR) operates as the buffer register for the timer cycle data register (TCDR), and should be set with 1/2 the PWM carrier cycle. Set dead time Td in the timer dead time data register (TDDR).

When dead time is not needed, the TDER bit in the timer dead time enable register (TDER) should be cleared to 0, TGRC_3 and TGRA_3 should be set to 1/2 the PWM carrier cycle + 1, and TDDR should be set to 1.

Set the respective initial PWM duty values in buffer registers TGRD_3, TGRC_4, and TGRD_4.

The values set in the five buffer registers excluding TDDR are transferred simultaneously to the corresponding compare registers when complementary PWM mode is set.

Set TCNT_4 to H'0000 before setting complementary PWM mode.

## **Table 10.54 Registers and Counters Requiring Initialization**

|**Register/Counter**|**Set Value**|
|---|---|
|TGRC_3|1/2 PWM carrier cycle + dead time Td (1/2 PWM carrier cycle + 1 when dead time|
||generation is disabled by TDER)|
|TDDR|Dead time Td (1 when dead time generation is disabled by TDER)|
|TCBR|1/2 PWM carrier cycle|
|TGRD_3, TGRC_4, TGRD_4|Initial PWM duty value for each phase|
|TCNT_4|H'0000|

Note: The TGRC_3 set value must be the sum of 1/2 the PWM carrier cycle set in TCBR and dead time Td set in TDDR. When dead time generation is disabled by TDER, TGRC_3 must be set to 1/2 the PWM carrier cycle + 1.

## (d) PWM Output Level Setting

In complementary PWM mode, the PWM pulse output level is set with bits OLSN and OLSP in timer output control register 1 (TOCR1) or bits OLS1P to OLS3P and OLS1N to OLS3N in timer output control register 2 (TOCR2).

The output level can be set for each of the three positive phases and three negative phases of 6-phase output.

Complementary PWM mode should be cleared before setting or changing output levels.

## (e) Dead Time Setting

In complementary PWM mode, PWM pulses are output with a non-overlapping relationship between the positive and negative phases. This non-overlap time is called the dead time.

The non-overlap time is set in the timer dead time data register (TDDR). The value set in TDDR is used as the TCNT_3 counter start value, and creates non-overlap between TCNT_3 and TCNT_4. Complementary PWM mode should be cleared before changing the contents of TDDR.

## (f) Dead Time Suppressing

Dead time generation is suppressed by clearing the TDER bit in the timer dead time enable register (TDER) to 0. TDER can be cleared to 0 only when 0 is written to it after reading TDER = 1.

TGRA_3 and TGRC_3 should be set to 1/2 PWM carrier cycle + 1 and the timer dead time data register (TDDR) should be set to 1.

By the above settings, PWM waveforms without dead time can be obtained. Figure 10.41 shows an example of operation without dead time.

**==> picture [395 x 379] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transfer from temporary register  Transfer from temporary register<br>to compare register to compare register<br>Ta Tb1 Ta Tb2 Ta<br>TGRA_3=TCDR+1<br>TCNTS<br>TCDR<br>TCNT_3<br>TCNT_4<br>TGRA_4<br>TGRC_4<br>TDDR=1<br>H'0000<br>Buffer register TGRC_4 Data1 Data2<br>Temporary register TEMP2 Data1 Data2<br>Compare register TGRA_4 Data1 Data2<br>Output waveform<br>Output waveform<br>Output waveform is active-low.<br>**----- End of picture text -----**<br>

**Figure 10.41 Example of Operation without Dead Time**

## (g) PWM Cycle Setting

In complementary PWM mode, the PWM pulse cycle is set in two registers—TGRA_3, in which the TCNT_3 upper limit value is set, and TCDR, in which the TCNT_4 upper limit value is set. The settings should be made so as to achieve the following relationship between these two registers:

With dead time: TGRA_3 setting = TCDR setting + TDDR setting TCDR setting > (twice the TDDR setting) + 2 Without dead time: TGRA_3 setting = TCDR setting + 1 TCDR setting > 4

The TGRA_3 and TCDR settings are made by setting the values in buffer registers TGRC_3 and TCBR. The values set in TGRC_3 and TCBR are transferred simultaneously to TGRA_3 and TCDR in accordance with the transfer timing selected with bits MD3 to MD0 in the timer mode register (TMDR).

The updated PWM cycle is reflected from the next cycle when the data update is performed at the crest, and from the current cycle when performed in the trough. Figure 10.42 illustrates the operation when the PWM cycle is updated at the crest.

See (h) Register Data Updating, for the method of updating the data in each buffer register.

**==> picture [331 x 171] intentionally omitted <==**

**----- Start of picture text -----**<br>
Counter value TGRC_3 TGRA_3<br>update update<br>TCNT_3<br>TGRA_3 TCNT_4<br>Time<br>**----- End of picture text -----**<br>

**Figure 10.42 Example of PWM Cycle Updating**

## (h) Register Data Updating

In complementary PWM mode, the buffer register is used to update the data in a compare register. The update data can be written to the buffer register at any time. There are five PWM duty and carrier cycle registers that have buffer registers and can be updated during operation.

There is a temporary register between each of these registers and its buffer register. When subcounter TCNTS is not counting, if buffer register data is updated, the temporary register value is also rewritten. Transfer is not performed from buffer registers to temporary registers when TCNTS is counting; in this case, the value written to a buffer register is transferred after TCNTS halts.

The temporary register value is transferred to the compare register at the data update timing set with bits MD3 to MD0 in the timer mode register (TMDR). Figure 10.43 shows an example of data updating in complementary PWM mode. This example shows the mode in which data updating is performed at both the counter crest and trough.

When rewriting buffer register data, a write to TGRD_4 must be performed at the end of the update. Data transfer from the buffer registers to the temporary registers is performed simultaneously for all five registers after the write to TGRD_4.

A write to TGRD_4 must be performed after writing data to the registers to be updated, even when not updating all five registers, or when updating the TGRD_4 data. In this case, the data written to TGRD_4 should be the same as the data prior to the write operation.

**==> picture [280 x 472] intentionally omitted <==**

**----- Start of picture text -----**<br>
Time<br>data6<br>data6<br>data6<br>: Compare register : Buffer register<br>Transfer from  temporary register  to compare register<br>data4<br>data5<br>Transfer from  temporary register  to compare register data5<br>data4<br>data4<br>Transfer from  temporary register  to compare register<br>data3<br>Transfer from  temporary register  to compare register<br>data3 data3<br>data2<br>Transfer from  temporary register  to compare register<br>data2 data2<br>data1<br>data1 data1<br>Transfer from  temporary register  to compare register<br>Data update timing: counter crest and trough Counter value TGRA_3 TGRC_4 TGRA_4 H'0000 BR Temp_R GR<br>**----- End of picture text -----**<br>

**Figure 10.43 Example of Data Update in Complementary PWM Mode**

## (i) Initial Output in Complementary PWM Mode

In complementary PWM mode, the initial output is determined by the setting of bits OLSN and OLSP in timer output control register 1 (TOCR1) or bits OLS1N to OLS3N and OLS1P to OLS3P in timer output control register 2 (TOCR2).

This initial output is the PWM pulse non-active level, and is output from when complementary PWM mode is set with the timer mode register (TMDR) until TCNT_4 exceeds the value set in the dead time register (TDDR). Figure 10.44 shows an example of the initial output in complementary PWM mode.

An example of the waveform when the initial PWM duty value is smaller than the TDDR value is shown in Figure 10.45 .

**==> picture [384 x 316] intentionally omitted <==**

**----- Start of picture text -----**<br>
Timer output control register settings<br>OLSN bit: 0 (initial output: high; active level: low)<br>OLSP bit: 0 (initial output: high; active level: low)<br>TCNT_3 and TCNT_4 values<br>TCNT_3<br>TCNT_4<br>TGRA_4<br>TDDR<br>Time<br>Initial output Dead time<br>Positive phase<br>output Active level<br>Negative phase Active level<br>output<br>Complementary  TCNT_3 and TCNT_4 count start<br>PWM mode (TSTR setting)<br>(TMDR setting)<br>**----- End of picture text -----**<br>

**Figure 10.44 Example of Initial Output in Complementary PWM Mode (1)**

**==> picture [383 x 316] intentionally omitted <==**

**----- Start of picture text -----**<br>
Timer output control register settings<br>OLSN bit: 0 (initial output: high; active level: low)<br>OLSP bit: 0 (initial output: high; active level: low)<br>TCNT_3 and TCNT_4 values<br>TCNT_3<br>TCNT_4<br>TDDR<br>TGRA_4<br>Time<br>Initial output<br>Positive phase<br>Active level<br>output<br>Negative phase<br>output<br>Complementary  TCNT_3 and TCNT_4 count start<br>PWM mode (TSTR setting)<br>(TMDR setting)<br>**----- End of picture text -----**<br>

**Figure 10.45 Example of Initial Output in Complementary PWM Mode (2)**

## (j) Complementary PWM Mode PWM Output Generation Method

In complementary PWM mode, 3-phase output is performed of PWM waveforms with a non-overlap time between the positive and negative phases. This non-overlap time is called the dead time.

A PWM waveform is generated by output of the output level selected in the timer output control register in the event of a compare-match between a counter and compare register. While TCNTS is counting, compare register and temporary register values are simultaneously compared to create consecutive PWM pulses from 0 to 100%. The relative timing of on and off compare-match occurrence may vary, but the compare-match that turns off each phase takes precedence to secure the dead time and ensure that the positive phase and negative phase on times do not overlap. Figure 10.46 to Figure 10.48 show examples of waveform generation in complementary PWM mode.

The positive phase/negative phase off timing is generated by a compare-match with the solid-line counter, and the on timing by a compare-match with the dotted-line counter operating with a delay of the dead time behind the solid-line counter. In the T1 period, compare-match **a** that turns off the negative phase has the highest priority, and comparematches occurring prior to **a** are ignored. In the T2 period, compare-match **c** that turns off the positive phase has the highest priority, and compare-matches occurring prior to **c** are ignored.

In normal cases, compare-matches occur in the order **a**  **b**  **c**  **d** (or **c**  **d**  **a'**  **b'** ), as shown in figure 10.46.

If compare-matches deviate from the **a**  **b**  **c**  **d** order, since the time for which the negative phase is off is less than twice the dead time, the figure shows the positive phase is not being turned on. If compare-matches deviate from the **c**  **d**  **a'**  **b'** order, since the time for which the positive phase is off is less than twice the dead time, the figure shows the negative phase is not being turned on.

If compare-match **c** occurs first following compare-match **a** , as shown in Figure 10.47 , compare-match **b** is ignored, and the negative phase is turned on by compare-match **d** . This is because turning off of the positive phase has priority due to the occurrence of compare-match **c** (positive phase off timing) before compare-match **b** (positive phase on timing) (consequently, the waveform does not change since the positive phase goes from off to off).

Similarly, in the example in Figure 10.48 , compare-match **a'** with the new data in the temporary register occurs before compare-match **c** , but other compare-matches occurring up to **c** , which turns off the positive phase, are ignored. As a result, the negative phase is not turned on.

Thus, in complementary PWM mode, compare-matches at turn-off timings take precedence, and turn-on timing compare-matches that occur before a turn-off timing compare-match are ignored.

**==> picture [326 x 194] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 period T2 period T1 period<br>TGRA_3<br>c d<br>TCDR<br>a b<br>a' b'<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>**----- End of picture text -----**<br>

**Figure 10.46 Example of Complementary PWM Mode Waveform Output (1)**

**==> picture [361 x 218] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 period T2 period T1 period<br>TGRA_3<br>c d<br>TCDR<br>a b<br>a b<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>**----- End of picture text -----**<br>

**Figure 10.47 Example of Complementary PWM Mode Waveform Output (2)**

**==> picture [329 x 199] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 period T2 period T1 period<br>TGRA_3<br>TCDR<br>a b<br>TDDR<br>c d<br>a' b'<br>H'0000<br>Positive phase<br>Negative phase<br>**----- End of picture text -----**<br>

**Figure 10.48 Example of Complementary PWM Mode Waveform Output (3)**

**==> picture [323 x 196] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 period T2 period T1 period<br>c d<br>TGRA_3<br>TCDR<br>a b<br>a' b'<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>**----- End of picture text -----**<br>

**Figure 10.49 Example of Complementary PWM Mode 0% and 100% Waveform Output (1)**

**==> picture [330 x 196] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 period T2 period T1 period<br>TGRA_3<br>TCDR<br>a b<br>a b<br>TDDR<br>H'0000<br>c d<br>Positive phase<br>Negative phase<br>**----- End of picture text -----**<br>

**Figure 10.50 Example of Complementary PWM Mode 0% and 100% Waveform Output (2)**

**==> picture [324 x 198] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 period T2 period T1 period<br>c d<br>TGRA_3<br>TCDR<br>a b<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>**----- End of picture text -----**<br>

**Figure 10.51 Example of Complementary PWM Mode 0% and 100% Waveform Output (3)**

**==> picture [329 x 200] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 period T2 period T1 period<br>TGRA_3<br>TCDR<br>a b<br>TDDR<br>H'0000<br>c  b' d  a'<br>Positive phase<br>Negative phase<br>**----- End of picture text -----**<br>

**Figure 10.52 Example of Complementary PWM Mode 0% and 100% Waveform Output (4)**

**==> picture [326 x 199] intentionally omitted <==**

**----- Start of picture text -----**<br>
T1 period T2 period T1 period<br>c a d b<br>TGRA_3<br>TCDR<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>**----- End of picture text -----**<br>

**Figure 10.53 Example of Complementary PWM Mode 0% and 100% Waveform Output (5)**

## (k) Complementary PWM Mode 0% and 100% Duty Output

In complementary PWM mode, 0% and 100% duty cycles can be output as required. Figure 10.49 to Figure 10.53 show output examples.

100% duty output is performed when the compare register value is set to H'0000. The waveform in this case has a positive phase with a 100% on-state. 0% duty output is performed when the compare register value is set to the same value as TGRA_3. The waveform in this case has a positive phase with a 100% off-state.

On and off compare-matches occur simultaneously, but if a turn-on compare-match and turn-off compare-match for the same phase occur simultaneously, both compare-matches are ignored and the waveform does not change.

## (l) Toggle Output Synchronized with PWM Cycle

In complementary PWM mode, toggle output can be performed in synchronization with the PWM carrier cycle by setting the PSYE bit to 1 in the timer output control register (TOCR). An example of a toggle output waveform is shown in Figure 10.54 .

This output is toggled by a compare-match between TCNT_3 and TGRA_3 and a compare-match between TCNT_4 and H'0000.

The output pin for this toggle output is the TIOC3A pin. The initial output is 1.

**==> picture [339 x 185] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGRA_3<br>TCNT_3<br>TCNT_4<br>H'0000<br>Toggle output<br> TIOC3A pin<br>**----- End of picture text -----**<br>

**Figure 10.54 Example of Toggle Output Waveform Synchronized with PWM Output**

## (m) Counter Clearing by Another Channel

In complementary PWM mode, by setting a mode for synchronization with another channel by means of the timer synchronous register (TSYR), and selecting synchronous clearing with bits CCLR2 to CCLR0 in the timer control register (TCR), it is possible to have TCNT_3, TCNT_4, and TCNTS cleared by another channel.

## Figure 10.55 illustrates the operation.

Use of this function enables counter clearing and restarting to be performed by means of an external signal.

**==> picture [395 x 249] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNTS<br>TGRA_3<br>TCDR<br>TCNT_3<br>TCNT_4<br>TDDR<br>H'0000<br>Channel 1<br>Input capture A<br>TCNT_1<br>Synchronous counter clearing by channel 1 input capture A<br>**----- End of picture text -----**<br>

**Figure 10.55 Counter Clearing Synchronized with Another Channel**

## (n) Output Waveform Control at Synchronous Counter Clearing in Complementary PWM Mode

Setting the WRE bit in TWCR to 1 suppresses initial output when synchronous counter clearing occurs in the Tb interval at the trough in complementary PWM mode and controls abrupt change in duty cycle at synchronous counter clearing.

Initial output suppression is applicable only when synchronous clearing occurs in the Tb interval at the trough as indicated by (10) or (11) in Figure 10.56 . When synchronous clearing occurs outside that interval, the initial value specified by the OLS bits in TOCR is output. Even in the Tb interval at the trough, if synchronous clearing occurs in the initial value output period (indicated by (1) in Figure 10.56 ) immediately after the counters start operation, initial value output is not suppressed.

When using the initial output suppression function, make sure to set compare registers TGRB_3, TGRA_4, and TGRB_4 to a value twice or more the setting of dead time data register TDDR. If synchronous clearing occurs with the compare registers set to a value less than twice the setting of TDDR, the PWM output dead time may be too short (or nonexistent) or illegal active-level PWM negative-phase output may occur during the initial output suppression interval. For details, see section 10.7.23, Notes on Output Waveform Control During Synchronous Counter Clearing in Complementary PWM Mode .

**==> picture [400 x 258] intentionally omitted <==**

**----- Start of picture text -----**<br>
Counter start<br>Tb interval Tb interval Tb interval<br>TGRA_3<br>TCDR TCNT_3<br>TGRB_3<br>TCNT_4<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>Output waveform is active-low<br>(1) (2) (3) (4) (5) (6) (7) (8) (9) (10) (11)<br>**----- End of picture text -----**<br>

**Figure 10.56 Timing for Synchronous Counter Clearing**

- Example of Procedure for Setting Output Waveform Control at Synchronous Counter Clearing in Complementary PWM Mode

An example of the procedure for setting output waveform control at synchronous counter clearing in complementary PWM mode is shown in Figure 10.57 .

**==> picture [283 x 182] intentionally omitted <==**

**----- Start of picture text -----**<br>
Output waveform control at  [1] Clear bits CST3 and CST4 in the timer<br>synchronous counter clearing start register (TSTR) to 0, and halt timer<br>counter (TCNT) operation. Perform<br>TWCR setting while TCNT_3 and<br>TCNT_4 are stopped.<br>Stop count operation [1]<br>[2] Read bit WRE in TWCR and then write 1<br>to it to suppress initial value output at<br>Set TWCR and  counter clearing.<br>[2]<br>complementary PWM mode<br>[3] Set bits CST3 and CST4 in TSTR to 1 to<br>start count operation.<br>Start count operation [3]<br>Output waveform control at<br> synchronous counter clearing<br>**----- End of picture text -----**<br>

**Figure 10.57 Example of Procedure for Setting Output Waveform Control at Synchronous Counter Clearing in Complementary PWM Mode**

- Examples of Output Waveform Control at Synchronous Counter Clearing in Complementary PWM Mode Figure 10.58 to Figure 10.61 show examples of output waveform control in which this module operates in complementary PWM mode and synchronous counter clearing is generated while the WRE bit in TWCR is set to 1. In the examples shown in Figure 10.58 to Figure 10.61 , synchronous counter clearing occurs at timing (3), (6), (8), and (11) shown in Figure 10.56 , respectively.

**==> picture [394 x 217] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronous clearing Bit WRE = 1<br>TGRA_3<br>TCDR<br>TGRB_3<br>TCNT_3<br>(MTU2)<br>TCNT_4<br>(MTU2)<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>Output waveform is active-low.<br>**----- End of picture text -----**<br>

**Figure 10.58 Example of Synchronous Clearing in Dead Time during Up-Counting (Timing (3) in Figure 10.56; Bit WRE of TWCR is 1)**

**==> picture [393 x 216] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronous clearing Bit WRE = 1<br>TGRA_3<br>TCDR<br>TGRB_3<br>TCNT_3<br>(MTU2)<br>TCNT_4<br>(MTU2)<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>Output waveform is active-low.<br>**----- End of picture text -----**<br>

**Figure 10.59 Example of Synchronous Clearing in Interval Tb at Crest (Timing (6) in Figure 10.56; Bit WRE of TWCR is 1)**

**==> picture [394 x 217] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronous clearing Bit WRE = 1<br>TGRA_3<br>TCDR<br>TGRB_3<br>TCNT_3<br>(MTU2)<br>TCNT_4<br>(MTU2)<br>TDDR<br>H'0000<br>Positive phase<br>Negative phase<br>Output waveform is active-low.<br>**----- End of picture text -----**<br>

**Figure 10.60 Example of Synchronous Clearing in Dead Time during Down-Counting (Timing (8) in Figure 10.56; Bit WRE of TWCR is 1)**

**==> picture [394 x 217] intentionally omitted <==**

**----- Start of picture text -----**<br>
Bit WRE = 1 Synchronous clearing<br>TGRA_3<br>TCDR<br>TGRB_3<br>TCNT_3<br>(MTU2)<br>TCNT_4<br>(MTU2)<br>TDDR<br>H'0000<br>Positive phase<br>Initial value output is suppressed.<br>Negative phase<br>Output waveform is active-low.<br>**----- End of picture text -----**<br>

**Figure 10.61 Example of Synchronous Clearing in Interval Tb at Trough (Timing (11) in Figure 10.56; Bit WRE of TWCR is 1)**

## (o) Counter Clearing by TGRA_3 Compare Match

In complementary PWM mode, by setting the CCE bit in the timer waveform control register (TWCR), it is possible to have TCNT_3, TCNT_4, and TCNTS cleared by TGRA_3 compare match.

## Figure 10.62 illustrates an operation example.

Note 1. Use this function only in complementary PWM mode 1 (transfer at crest)

- Note 2. Do not specify synchronous clearing by another channel (do not set the SYNC0 to SYNC4 bits in the timer synchronous register (TSYR) to 1).

- Note 3. Do not set the PWM duty value to H'0000.

Note 4. Do not set the PSYE bit in timer output control register 1 (TOCR1) to 1.

**==> picture [345 x 221] intentionally omitted <==**

**----- Start of picture text -----**<br>
Counter cleared<br>by TGRA_3 compare match<br>TGRA_3<br>TCDR<br>TGRB_3<br>TDDR<br>H'0000<br>Output waveform<br>Output waveform<br>Output waveform is active-high.<br>**----- End of picture text -----**<br>

**Figure 10.62 Example of Counter Clearing Operation by TGRA_3 Compare Match**

## (p) Example of AC Synchronous Motor (Brushless DC Motor) Drive Waveform Output

In complementary PWM mode, a brushless DC motor can easily be controlled using the timer gate control register (TGCR). Figure 10.63 to Figure 10.66 show examples of brushless DC motor drive waveforms created using TGCR.

When output phase switching for a 3-phase brushless DC motor is performed by means of external signals detected with a Hall element, etc., clear the FB bit in TGCR to 0. In this case, the external signals indicating the polarity position are input to channel 0 timer input pins TIOC0A, TIOC0B, and TIOC0C (set with the general I/O ports). When an edge is detected at pin TIOC0A, TIOC0B, or TIOC0C, the output on/off state is switched automatically.

When the FB bit is 1, the output on/off state is switched when the UF, VF, or WF bit in TGCR is cleared to 0 or set to 1. The drive waveforms are output from the complementary PWM mode 6-phase output pins. With this 6-phase output, in the case of on output, it is possible to use complementary PWM mode output and perform chopping output by setting the N bit or P bit to 1. When the N bit or P bit is 0, level output is selected.

The 6-phase output active level (on output level) can be set with the OLSN and OLSP bits in the timer output control register (TOCR) regardless of the setting of the N and P bits.

|External input<br>TIOC0A pin<br>TIOC0B pin<br>TIOC0C pin<br>TIOC3B pin<br>TIOC3D pin<br>TIOC4A pin<br>TIOC4C pin<br>TIOC4B pin<br>TIOC4D pin<br>6-phase output<br>**When BDC = 1, N = 0, P = 0, FB = 0, output active level = high**|||||||||||
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||

**Figure 10.63 Example of Output Phase Switching by External Input (1)**

**==> picture [303 x 203] intentionally omitted <==**

**----- Start of picture text -----**<br>
External input TIOC0A pin<br>TIOC0B pin<br>TIOC0C pin<br>6-phase output TIOC3B pin<br>TIOC3D pin<br>TIOC4A pin<br>TIOC4C pin<br>TIOC4B pin<br>TIOC4D pin<br>When BDC = 1, N = 1, P = 1, FB = 0, output active level = high<br>**----- End of picture text -----**<br>

**Figure 10.64 Example of Output Phase Switching by External Input (2)**

**==> picture [282 x 187] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGCR UF bit<br>VF bit<br>WF bit<br>6-phase output TIOC3B pin<br>TIOC3D pin<br>TIOC4A pin<br>TIOC4C pin<br>TIOC4B pin<br>TIOC4D pin<br>When BDC = 1, N = 0, P = 0, FB = 1, output active level = high<br>**----- End of picture text -----**<br>

**Figure 10.65 Example of Output Phase Switching by Means of UF, VF, WF Bit Settings (1)**

**==> picture [302 x 202] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGCR UF bit<br>VF bit<br>WF bit<br>6-phase output TIOC3B pin<br>TIOC3D pin<br>TIOC4A pin<br>TIOC4C pin<br>TIOC4B pin<br>TIOC4D pin<br>When BDC = 1, N = 1, P = 1, FB = 1, output active level = high<br>**----- End of picture text -----**<br>

**Figure 10.66 Example of Output Phase Switching by Means of UF, VF, WF Bit Settings (2)**

## (q) A/D Converter Start Request Setting

In complementary PWM mode, an A/D converter start request can be issued using a TGRA_3 compare-match, TCNT_4 underflow (trough), or compare-match on a channel other than channels 3 and 4.

When start requests using a TGRA_3 compare-match are specified, A/D conversion can be started at the crest of the TCNT_3 count.

A/D converter start requests can be set by setting the TTGE bit to 1 in the timer interrupt enable register (TIER). To issue an A/D converter start request at a TCNT_4 underflow (trough), set the TTGE2 bit in TIER_4 to 1.

## (3) Interrupt Skipping in Complementary PWM Mode

Interrupts TGIA_3 (at the crest) and TCIV_4 (at the trough) in channels 3 and 4 can be skipped up to seven times by making settings in the timer interrupt skipping set register (TITCR).

Transfers from a buffer register to a temporary register or a compare register can be skipped in coordination with interrupt skipping by making settings in the timer buffer transfer register (TBTER). For the linkage with buffer registers, refer to description (c), Buffer Transfer Control Linked with Interrupt Skipping, below.

A/D converter start requests generated by the A/D converter start request delaying function can also be skipped in coordination with interrupt skipping by making settings in the timer A/D converter request control register (TADCR). For the linkage with the A/D converter start request delaying function, refer to section 10.4.9, A/D Converter Start Request Delaying Function .

The setting of the timer interrupt skipping setting register (TITCR) must be done while the TGIA_3 and TCIV_4 interrupt requests are disabled by the settings of TIER_3 and TIER_4 along with under the conditions in which TGFA_3 and TCFV_4 flag settings by compare match never occur. Before changing the skipping count, be sure to clear the T3AEN and T4VEN bits to 0 to clear the skipping counter.

## (a) Example of Interrupt Skipping Operation Setting Procedure

Figure 10.67 shows an example of the interrupt skipping operation setting procedure. Figure 10.68 shows the periods during which interrupt skipping count can be changed.

**==> picture [305 x 169] intentionally omitted <==**

**----- Start of picture text -----**<br>
[1] Set bits T3AEN and T4VEN in the timer interrupt<br>Interrupt skipping skipping set register (TITCR) to 0 to clear the<br>skipping counter.<br>[2] Specify the interrupt skipping count within the<br>Clear interrupt skipping counter [1] range from 0 to 7 times in bits 3ACOR2 to<br>3ACOR0 and 4VCOR2 to 4VCOR0 in TITCR, and<br>enable interrupt skipping through bits T3AEN and<br>T4VEN.<br>Set skipping count and<br>[2]<br>enable interrupt skipping Note: The setting of TITCR must be done while the<br>TGIA_3 and TCIV_4 interrupt requests are<br>disabled by the settings of TIER_3<br>and TIER_4 along with under the conditions in<br><Interrupt skipping> which TGFA_3 and TCFV_4 flag settings by<br>compare match never occur.<br>         Before changing the skipping count, be sure to<br>clear the T3AEN and T4VEN bits to 0 to clear<br>the skipping counter.<br>**----- End of picture text -----**<br>

**Figure 10.67 Example of Interrupt Skipping Operation Setting Procedure**

**==> picture [359 x 141] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_3<br>TCNT_4<br>Period during which  Period during which  Period during which  Period during which<br>changing skipping count  changing skipping count  changing skipping count  changing skipping count<br>can be performed can be performed can be performed can be performed<br>**----- End of picture text -----**<br>

**Figure 10.68 Periods during which Interrupt Skipping Count can be Changed**

## (b) Example of Interrupt Skipping Operation

Figure 10.69 shows an example of TGIA_3 interrupt skipping in which the interrupt skipping count is set to three by the 3ACOR bit and the T3AEN bit is set to 1 in the timer interrupt skipping set register (TITCR).

**==> picture [359 x 111] intentionally omitted <==**

**----- Start of picture text -----**<br>
Interrupt skipping period Interrupt skipping period<br>TGIA_3 interrupt<br>flag set signal<br>Skipping counter 00 01 02 03 00 01 02 03<br>TGFA_3 flag<br>**----- End of picture text -----**<br>

**Figure 10.69 Example of Interrupt Skipping Operation**

## (c) Buffer Transfer Control Linked with Interrupt Skipping

In complementary PWM mode, whether to transfer data from a buffer register to a temporary register and whether to link the transfer with interrupt skipping can be specified with the BTE1 and BTE0 bits in the timer buffer transfer set register (TBTER).

Figure 10.70 shows an example of operation when buffer transfer is suppressed (BTE1 = 0 and BTE0 = 1). While this setting is valid, data is not transferred from the buffer register to the temporary register.

Figure 10.71 shows an example of operation when buffer transfer is linked with interrupt skipping (BTE1 = 1 and BET0 = 0). While this setting is valid, data is not transferred from the buffer register to the temporary register outside the buffer transfer-enabled period. Depending on the rewrite timing from the interrupt generation to the buffer register, there are two types of the transfer timing such as from the buffer register to the temporary register and from the temporary register to the general register.

Note that the buffer transfer-enabled period depends on the T3AEN and T4VEN bit settings in the timer interrupt skipping set register (TITCR). Figure 10.72 shows the relationship between the T3AEN and T4VEN bit settings in TITCR and buffer transfer-enabled period.

Note: This function must always be used in combination with interrupt skipping. When interrupt skipping is disabled (the T3AEN and T4VEN bits in the timer interrupt skipping set register (TITCR) are cleared to 0 or the skipping count set bits (3ACOR and 4VCOR) in TITCR are cleared to 0), make sure that buffer transfer is not linked with interrupt skipping (clear the BTE1 bit in the timer buffer transfer set register (TBTER) to 0). If buffer transfer is linked with interrupt skipping while interrupt skipping is disabled, buffer transfer is never performed.

**==> picture [365 x 316] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_3<br>TCNT_4<br>data1<br>Bit BTE0 in TBTER<br>Bit BTE1 in TBTER<br>Buffer register Data1 Data2<br>(1) (3)<br>Temporary register Data* Data2<br>(2)<br>General register Data* Data2<br>Buffer transfer is suppressed<br>[Legend]<br>(1) No data is transferred from the buffer register to the temporary register in the buffer transfer-disabled period<br>     (bits BTE1 and BTE0 in TBTER are set to 0 and 1, respectively).<br>(2) Data is transferred from the temporary register to the general register even in the buffer transfer-disabled period.<br>(3) After buffer transfer is enabled, data is transferred from the buffer register to the temporary register.<br>Note: *   When buffer transfer at the crest is selected.<br>**----- End of picture text -----**<br>

## **Figure 10.70 Example of Operation when Buffer Transfer is Suppressed (BTE1 = 0 and BTE0 = 1)**

**==> picture [326 x 462] intentionally omitted <==**

**----- Start of picture text -----**<br>
(1)When rewriting the buffer register within 1 carrier cycle from TGIA_3 interrupt<br>TGIA_3 interrupt generation TGIA_3 interrupt generation<br>TCNT_3<br>TCNT_4<br>Buffer register rewrite timing Buffer register rewrite timing<br>Buffer transfer-<br>enabled period<br>TITCR[6:4] 2<br>TITCNT[6:4] 0 1 2 0 1<br>Buffer register Data Data1 Data2<br>Temporary register Data Data1 Data2<br>General register Data Data1 Data2<br>(2)When rewriting the buffer register after passing 1 carrier cycle from TGIA_3 interrupt<br>TGIA_3 interrupt generation TGIA_3 interrupt generation<br>TCNT_3<br>TCNT_4<br>Buffer register rewrite timing<br>Buffer transfer-<br>enabled period<br>TITCR[6:4] 2<br>TITCNT[6:4] 0 1 2 0 1<br>Buffer register Data Data1<br>Temporary register Data Data1<br>General register Data Data1<br>Note: * The MD bits 3 to 0 = 1101 in TMDR_3, buffer transfer at the crest is selected.<br> The skipping count is set to two.<br> T3AEN and T4VEN are set to 1 and 0.<br>**----- End of picture text -----**<br>

**Figure 10.71 Example of Operation when Buffer Transfer is Linked with Interrupt Skipping (BTE1 = 1 and BTE0 = 0)**

**==> picture [393 x 241] intentionally omitted <==**

**----- Start of picture text -----**<br>
Skipping counter 3ACNT 0 1 2 3 0 1 2 3 0<br>Skipping counter 4VCNT 0 1 2 3 0 1 2 3<br>Buffer transfer-enabled period<br>(T3AEN is set to 1)<br>Buffer transfer-enabled period<br>(T4VEN is set to 1)<br>Buffer transfer-enabled period<br>(T3AEN and T4VEN are set to 1)<br>Note:  *  The MD bits 3 to 0 = 1111 in TMDR_3, buffer transfer at the crest and the<br>  trough is selected.<br>  The skipping count is set to three.<br>  T3AEN and T4VEN are set to 1.<br>**----- End of picture text -----**<br>

**Figure 10.72 Relationship between Bits T3AEN and T4VEN in TITCR and Buffer Transfer-Enabled Period**

## (4) Complementary PWM Mode Output Protection Function

Complementary PWM mode output has the following protection function.

## (a) Register and counter miswrite prevention function

With the exception of the buffer registers, which can be rewritten at any time, access by the CPU can be enabled or disabled for the mode registers, control registers, compare registers, and counters used in complementary PWM mode by means of the RWE bit in the timer read/write enable register (TRWER). The applicable registers are some (21 in total) of the registers in channels 3 and 4 shown in the following:

- TCR_3 and TCR_4, TMDR_3 and TMDR_4, TIORH_3 and TIORH_4, TIORL_3 and TIORL_4, TIER_3 and TIER_4, TCNT_3 and TCNT_4, TGRA_3 and TGRA_4, TGRB_3 and TGRB_4, TOER, TOCR, TGCR, TCDR, and TDDR.

This function enables miswriting due to CPU runaway to be prevented by disabling CPU access to the mode registers, control registers, and counters. When the applicable registers are read in the access-disabled state, undefined values are returned. Writing to these registers is ignored.

## 10.4.9 A/D Converter Start Request Delaying Function

A/D converter start requests can be issued in channel 4 by making settings in the timer A/D converter start request control register (TADCR), timer A/D converter start request cycle set registers (TADCORA_4 and TADCORB_4), and timer A/D converter start request cycle set buffer registers (TADCOBRA_4 and TADCOBRB_4).

The A/D converter start request delaying function compares TCNT_4 with TADCORA_4 or TADCORB_4, and when their values match, the function issues a respective A/D converter start request (TRG4AN or TRG4BN).

A/D converter start requests (TRG4AN and TRG4BN) can be skipped in coordination with interrupt skipping by setting the ITA3AE, ITA4VE, ITB3AE, and ITB4VE bits in TADCR.

- Example of Procedure for Specifying A/D Converter Start Request Delaying Function Figure 10.73 shows an example of procedure for specifying the A/D converter start request delaying function.

||||[1] Set the cycle in the timer A/D converter start request cycle|
|---|---|---|---|
|A/D converter|start request||buffer register (TADCOBRA_4 or TADCOBRB_4) and timer|
|delaying|function||A/D converter start request cycle register (TADCORA_4 or|
||||TADCORB_4). (The same initial value must be specified in|
||||the cycle buffer register and cycle register.)|
|Set A/D converter|start request cycle|[1]|[2] Use bits BF1 and BF2 in the timer A/D converter start<br>request control register (TADCR) to specify the timing of|
||||transfer from the timer A/D converter start request cycle|
|•Set the timing of transfer<br>from cycle set buffer register<br>•Set linkage with interrupt skipping<br>•Enable A/D converter start<br>request delaying function||[2]|buffer register to A/D converter start request cycle register.<br>•Specify whether to link with interrupt skipping through bits<br>ITA3AE, ITA4VE, ITB3AE, and ITB4VE.<br>•Use bits UT4AE, DT4AE, UT4BE, and DT4BE to enable<br>A/D conversion start requests (TRG4AN or TRG4BN).|
||||Notes: 1. Perform TADCR setting while TCNT_4 is stopped.|
||||2. Do not set BF1 to 1 when complementary PWM mode|
||||is not selected.|
|A/D converter<br>delaying|start request<br>function||3. Do not set ITA3AE, ITA4VE, ITB3AE, ITB4VE,<br>DT4AE, or DT4BE to 1 when complementary PWM|
||||mode is not selected.|

**Figure 10.73 Example of Procedure for Specifying A/D Converter Start Request Delaying Function**

- Basic Operation Example of A/D Converter Start Request Delaying Function Figure 10.74 shows a basic example of A/D converter request signal (TRG4AN) operation when the trough of TCNT_4 is specified for the buffer transfer timing and an A/D converter start request signal is output during TCNT_4 down-counting.

**==> picture [380 x 155] intentionally omitted <==**

**----- Start of picture text -----**<br>
Transfer from cycle buffer  Transfer from cycle buffer  Transfer from cycle buffer<br>register to cycle register register to cycle register register to cycle register<br>TADCORA_4<br>TCNT_4<br>TADCOBRA_4<br>A/D converter start request<br>(TRG4AN) (Complementary PWM mode)<br>**----- End of picture text -----**<br>

**Figure 10.74 Basic Example of A/D Converter Start Request Signal (TRG4AN) Operation**

- Buffer Transfer

   - The data in the timer A/D converter start request cycle set registers (TADCORA_4 and TADCORB_4) is updated by writing data to the timer A/D converter start request cycle set buffer registers (TADCOBRA_4 and TADCOBRB_4). Data is transferred from the buffer registers to the respective cycle set registers at the timing selected with the BF1 and BF0 bits in the timer A/D converter start request control register (TADCR_4).

- A/D Converter Start Request Delaying Function Linked with Interrupt Skipping

   - A/D converter start requests (TRG4AN and TRG4BN) can be issued in coordination with interrupt skipping by making settings in the ITA3AE, ITA4VE, ITB3AE, and ITB4VE bits in the timer A/D converter start request control register (TADCR).

Figure 10.75 shows an example of A/D converter start request signal (TRG4AN) operation when TRG4AN output is enabled during TCNT_4 up counting and down counting and A/D converter start requests are linked with interrupt skipping.

Figure 10.76 shows another example of A/D converter start request signal (TRG4AN) operation when TRG4AN output is enabled during TCNT_4 up counting and A/D converter start requests are linked with interrupt skipping.

Note: This function must be used in combination with interrupt skipping. When interrupt skipping is disabled (the T3AEN and T4VEN bits in the timer interrupt skipping set register (TITCR) are cleared to 0 or the skipping count set bits (3ACOR and 4VCOR) in TITCR are cleared to 0), make sure that A/D converter start requests are not linked with interrupt skipping (clear the ITA3AE, ITA4VE, ITB3AE, and ITB4VE bits in the timer A/D converter start request control register (TADCR) to 0).

**==> picture [401 x 260] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_4<br>TADCORA_4<br>TGIA_3 interrupt<br> skipping counter 00 01 02 00 01<br>TCIV_4 interrupt 00 01 02 00 01<br> skipping counter<br>TGIA_3 A/D request-enabled<br> period<br>TCIV_4 A/D request-enabled<br> period<br>A/D converter start request (TRG4AN)<br>When linked with TGIA_3 and TCIV_4<br>interrupt skipping<br>When linked with TGIA_3<br>interrupt skipping<br>When linked with TCIV_4<br>interrupt skipping (UT4AE/DT4AE = 1)<br>Note: *    When the interrupt skipping count is set to two.<br>**----- End of picture text -----**<br>

**Figure 10.75 Example of A/D Converter Start Request Signal (TRG4AN) Operation Linked with Interrupt Skipping**

**==> picture [401 x 260] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT_4<br>TADCORA_4<br>TGIA_3 interrupt<br> skipping counter 00 01 02 00 01<br>TCIV_4 interrupt 00 01 02 00 01<br> skipping counter<br>TGIA_3 A/D request-enabled<br> period<br>TCIV_4 A/D request-enabled<br> period<br>A/D converter start request (TRG4AN)<br>When linked with TGIA_3 and TCIV_4<br>interrupt skipping<br>When linked with TGIA_3<br>interrupt skipping<br>When linked with TCIV_4<br>interrupt skipping UT4AE = 1<br>DT4AE = 0<br>Note: *    When the interrupt skipping count is set to two.<br>**----- End of picture text -----**<br>

**Figure 10.76 Example of A/D Converter Start Request Signal (TRG4AN) Operation Linked with Interrupt Skipping**

## 10.4.10 TCNT Capture at Crest and/or Trough in Complementary PWM Operation

The TCNT value is captured in TGR at either the crest or trough or at both the crest and trough during complementary PWM operation. The timing for capturing in TGR can be selected by TIOR.

Figure 10.77 shows an example in which TCNT is used as a free-running counter without being cleared, and the TCNT value is captured in TGR at the specified timing (either crest or trough, or both crest and trough).

**==> picture [399 x 222] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGRA_4<br>Tdead<br>Upper arm signal<br>Lower arm signal<br>Inverter output monitor signal<br>Tdelay<br>Dead time delay signal<br>Up-count/down-count signal (udflg)<br>TCNT[15:0] 3DE7 3E5B 3ED3 3F37 3FAF<br>TGR[15:0] 3DE7 3E5B 3ED3 3F37 3FAF<br>**----- End of picture text -----**<br>

**Figure 10.77 TCNT Capturing at Crest and/or Trough in Complementary PWM Operation**

## 10.5 Interrupt Sources

## 10.5.1 Interrupt Sources and Priorities

This module has three kinds of interrupt sources; TGR input capture/compare match, TCNT overflow, and TCNT underflow. Each interrupt source has its own status flag and enable/disabled bit, allowing the generation of interrupt request signals to be enabled or disabled individually.

When an interrupt request is generated, the corresponding status flag in TSR is set to 1. If the corresponding enable/ disable bit in TIER is set to 1 at this time, an interrupt is requested. The interrupt request is cleared by clearing the status flag to 0.

Relative channel priorities can be changed by the interrupt controller, however the priority order within a channel is fixed. For details, see section 7, Interrupt Controller .

## Table 10.55 lists the interrupt sources of this module.

## **Table 10.55 Interrupts of Multi-Function Timer Pulse Unit 2**

|**Channel**|**Name**<br>**Interrupt Source**<br>**Interrupt Flag**<br>**Activation of**<br>**Direct Memory**<br>**Access**<br>**Controller**<br>**Priority**|
|---|---|
|0|TGIA_0<br>TGRA_0 input capture/compare match<br>TGFA_0<br>Possible<br>High<br>TGIB_0<br>TGRB_0 input capture/compare match<br>TGFB_0<br>Not possible<br>TGIC_0<br>TGRC_0 input capture/compare match<br>TGFC_0<br>Not possible<br>TGID_0<br>TGRD_0 input capture/compare match<br>TGFD_0<br>Not possible<br>TCIV_0<br>TCNT_0 overflow<br>TCFV_0<br>Not possible<br>TGIE_0<br>TGRE_0 compare match<br>TGFE_0<br>Not possible<br>TGIF_0<br>TGRF_0 compare match<br>TGFF_0<br>Not possible<br>TGIA_1<br>TGRA_1 input capture/compare match<br>TGFA_1<br>Possible<br>TGIB_1<br>TGRB_1 input capture/compare match<br>TGFB_1<br>Not possible<br>TCIV_1<br>TCNT_1 overflow<br>TCFV_1<br>Not possible<br>TCIU_1<br>TCNT_1 underflow<br>TCFU_1<br>Not possible<br>TGIA_2<br>TGRA_2 input capture/compare match<br>TGFA_2<br>Possible<br>TGIB_2<br>TGRB_2 input capture/compare match<br>TGFB_2<br>Not possible<br>TCIV_2<br>TCNT_2 overflow<br>TCFV_2<br>Not possible<br>TCIU_2<br>TCNT_2 underflow<br>TCFU_2<br>Not possible<br>TGIA_3<br>TGRA_3 input capture/compare match<br>TGFA_3<br>Possible<br>TGIB_3<br>TGRB_3 input capture/compare match<br>TGFB_3<br>Not possible<br>TGIC_3<br>TGRC_3 input capture/compare match<br>TGFC_3<br>Not possible<br>TGID_3<br>TGRD_3 input capture/compare match<br>TGFD_3<br>Not possible<br>TCIV_3<br>TCNT_3 overflow<br>TCFV_3<br>Not possible<br>TGIA_4<br>TGRA_4 input capture/compare match<br>TGFA_4<br>Possible<br>TGIB_4<br>TGRB_4 input capture/compare match<br>TGFB_4<br>Not possible<br>TGIC_4<br>TGRC_4 input capture/compare match<br>TGFC_4<br>Not possible<br>TGID_4<br>TGRD_4 input capture/compare match<br>TGFD_4<br>Not possible<br>TCIV_4<br>TCNT_4 overflow/underflow<br>TCFV_4<br>Not possible<br>Low|
|1||
|2||
|3||
|4||

Note: This table shows the initial state immediately after a reset. The relative channel priorities can be changed by the interrupt controller.

## (1) Input Capture/Compare Match Interrupt

An interrupt is requested if the TGIE bit in TIER is set to 1 when the TGF flag in TSR is set to 1 by the occurrence of a TGR input capture/compare match on a particular channel. The interrupt request is cleared by clearing the TGF flag to 0. This module has eighteen input capture/compare match interrupts, six for channel 0, four each for channels 3 and 4, and two each for channels 1 and 2. The TGFE_0 and TGFF_0 flags in channel 0 are not set by the occurrence of an input capture.

## (2) Overflow Interrupt

An interrupt is requested if the TCIEV bit in TIER is set to 1 when the TCFV flag in TSR is set to 1 by the occurrence of TCNT overflow on a channel. The interrupt request is cleared by clearing the TCFV flag to 0. This module has five overflow interrupts, one for each channel.

## (3) Underflow Interrupt

An interrupt is requested if the TCIEU bit in TIER is set to 1 when the TCFU flag in TSR is set to 1 by the occurrence of TCNT underflow on a channel. The interrupt request is cleared by clearing the TCFU flag to 0. This module has two underflow interrupts, one each for channels 1 and 2.

## 10.5.2 Activation of Direct Memory Access Controller

The direct memory access controller can be activated by the TGRA input capture/compare match interrupt in each channel. For details, see section 9, Direct Memory Access Controller .

In this module, a total of five TGRA input capture/compare match interrupts can be used as direct memory access controller activation sources, one each for channels 0 to 4.

## 10.5.3 A/D Converter Activation

The A/D converter can be activated by one of the following three methods in this module. Table 10.56 shows the relationship between interrupt sources and A/D converter start request signals.

## (1) A/D Converter Activation by TGRA Input Capture/Compare Match or at TCNT_4 Trough in Complementary PWM Mode

The A/D converter can be activated by the occurrence of a TGRA input capture/compare match in each channel. In addition, if complementary PWM operation is performed while the TTGE2 bit in TIER_4 is set to 1, the A/D converter can be activated at the trough of TCNT_4 count (TCNT_4 = H'0000).

A/D converter start request signal TRGAN is issued to the A/D converter under either one of the following conditions.

- When the TGFA flag in TSR is set to 1 by the occurrence of a TGRA input capture/compare match on a particular channel while the TTGE bit in TIER is set to 1

- When the TCNT_4 count reaches the trough (TCNT_4 = H'0000) during complementary PWM operation while the TTGE2 bit in TIER_4 is set to 1

When either condition is satisfied, if A/D converter start signal TRGAN from this module is selected as the trigger in the A/D converter, A/D conversion will start.

## (2) A/D Converter Activation by Compare Match between TCNT_0 and TGRE_0

The A/D converter can be activated by generating A/D converter start request signal TRG0N when a compare match occurs between TCNT_0 and TGRE_0 in channel 0.

When the TGFE flag in TSR2_0 is set to 1 by the occurrence of a compare match between TCNT_0 and TGRE_0 in channel 0 while the TTGE2 bit in TIER2_0 is set to 1, A/D converter start request TGR0N is issued to the A/D converter. If A/D converter start signal TGR0N from this module is selected as the trigger in the A/D converter, A/D conversion will start.

## (3) A/D Converter Activation by A/D Converter Start Request Delaying Function

The A/D converter can be activated by generating A/D converter start request signal TRG4AN or TRG4BN when the TCNT_4 count matches the TADCORA or TADCORB value if the UT4AE, DT4AE, UT4BE, or DT4BE bit in the A/D converter start request control register (TADCR) is set to 1. For details, refer to section 10.4.9, A/D Converter Start Request Delaying Function .

A/D conversion will start if A/D converter start signal TRG4AN from this module is selected as the trigger in the A/D converter when TRG4AN is generated or if TRG4BN from this module is selected as the trigger in the A/D converter when TRG4BN is generated.

## **Table 10.56 Interrupt Sources and A/D Converter Start Request Signals**

|**Target Registers**<br>**Interrupt Source**|**A/D Converter Start Request Signal**|
|---|---|
|TGRA_0 and TCNT_0<br>Input capture/compare match<br>TGRA_1 and TCNT_1<br>TGRA_2 and TCNT_2<br>TGRA_3 and TCNT_3<br>TGRA_4 and TCNT_4|TRGAN|
|TCNT_4<br>TCNT_4 Trough in complementary PWM mode||
|TGRE_0 and TCNT_0<br>Compare match<br>TADCORA and TCNT_4<br>TADCORB and TCNT_4|TRG0N|
||TRG4AN|
||TRG4BN|

## 10.6 Operation Timing

## 10.6.1 Input/Output Timing

## (1) TCNT Count Timing

Figure 10.78 shows TCNT count timing in internal clock operation, and Figure 10.79 shows TCNT count timing in external clock operation (normal mode), and Figure 10.80 shows TCNT count timing in external clock operation (phase counting mode).

**==> picture [393 x 87] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>Internal clock Falling edge Rising edge<br>TCNT input<br>clock<br>TCNT N - 1 N N + 1<br>**----- End of picture text -----**<br>

**Figure 10.78 Count Timing in Internal Clock Operation**

**==> picture [385 x 83] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>External clock Falling edge Rising edge<br>TCNT input<br>clock<br>TCNT N - 1 N N + 1<br>**----- End of picture text -----**<br>

**Figure 10.79 Count Timing in External Clock Operation**

**==> picture [382 x 93] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>External  Rising edge Falling edge<br>clock<br>TCNT input<br>clock<br>TCNT N - 1 N N - 1<br>**----- End of picture text -----**<br>

**Figure 10.80 Count Timing in External Clock Operation (Phase Counting Mode)**

## (2) Output Compare Output Timing

A compare match signal is generated in the final state in which TCNT and TGR match (the point at which the count value matched by TCNT is updated). When a compare match signal is generated, the output value set in TIOR is output at the output compare output pin (TIOC pin). After a match between TCNT and TGR, the compare match signal is not generated until the TCNT input clock is generated.

Figure 10.81 shows output compare output timing (normal mode and PWM mode) and Figure 10.82 shows output compare output timing (complementary PWM mode and reset synchronous PWM mode).

**==> picture [288 x 150] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNT input<br>clock<br>TCNT N N + 1<br>N<br>TGR<br>Compare<br>match signal<br>TIOC pin<br>**----- End of picture text -----**<br>

**Figure 10.81 Output Compare Output Timing (Normal Mode/PWM Mode)**

**==> picture [330 x 171] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNT input<br>clock<br>TCNT N N + 1<br>TGR N<br>Compare<br>match signal<br>TIOC pin<br>**----- End of picture text -----**<br>

**Figure 10.82 Output Compare Output Timing (Complementary PWM Mode/Reset Synchronous PWM Mode)**

## (3) Input Capture Signal Timing

Figure 10.83 shows input capture signal timing.

**==> picture [289 x 120] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>Input capture<br>input<br>Input capture<br>signal<br>TCNT N N + 1 N + 2<br>TGR N N + 2<br>**----- End of picture text -----**<br>

**Figure 10.83 Input Capture Input Signal Timing**

## (4) Timing for Counter Clearing by Compare Match/Input Capture

Figure 10.84 shows the timing when counter clearing on compare match is specified, and Figure 10.85 shows the timing when counter clearing on input capture is specified.

**==> picture [287 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>Compare<br>match signal<br>Counter<br>clear signal<br>TCNT N H'0000<br>TGR N<br>**----- End of picture text -----**<br>

**Figure 10.84 Counter Clear Timing (Compare Match)**

**==> picture [289 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>Input capture<br>signal<br>Counter clear<br>signal<br>TCNT N H'0000<br>TGR N<br>**----- End of picture text -----**<br>

**Figure 10.85 Counter Clear Timing (Input Capture)**

## (5) Buffer Operation Timing

Figure 10.86 to Figure 10.88 show the timing in buffer operation.

**==> picture [287 x 125] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNT n n + 1<br>Compare<br>match buffer<br>signal<br>TGRA, n N<br>TGRB<br>TGRC, N<br>TGRD<br>**----- End of picture text -----**<br>

**Figure 10.86 Buffer Operation Timing (Compare Match)**

**==> picture [288 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>Input capture<br>signal<br>TCNT N N + 1<br>TGRA, n N N + 1<br>TGRB<br>TGRC,<br>n N<br>TGRD<br>**----- End of picture text -----**<br>

**Figure 10.87 Buffer Operation Timing (Input Capture)**

**==> picture [329 x 172] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNT n H'0000<br>TCNT clear<br>signal<br>Buffer transfer<br>signal<br>TGRA, TGRB,<br>TGRE n N<br>TGRC, TGRD,<br>N<br>TGRF<br>**----- End of picture text -----**<br>

**Figure 10.88 Buffer Transfer Timing (when TCNT Cleared)**

## (6) Buffer Transfer Timing (Complementary PWM Mode)

Figure 10.89 to Figure 10.91 show the buffer transfer timing in complementary PWM mode.

**==> picture [330 x 173] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNTS H'0000<br>TGRD_4<br>write signal<br>Temporary register<br>transfer signal<br>Buffer<br>register n N<br>Temporary  n N<br>register<br>**----- End of picture text -----**<br>

**Figure 10.89 Transfer Timing from Buffer Register to Temporary Register (TCNTS Stop)**

**==> picture [324 x 150] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNTS P - x P H'0000<br>TGRD_4<br>write signal<br>Buffer<br>n N<br>register<br>Temporary  n N<br>register<br>**----- End of picture text -----**<br>

**Figure 10.90 Transfer Timing from Buffer Register to Temporary Register (TCNTS Operating)**

**==> picture [324 x 140] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNTS P − 1 P H'0000<br>Buffer transfer<br>signal<br>Temporary<br>N<br>register<br>Compare  n N<br>register<br>**----- End of picture text -----**<br>

**Figure 10.91 Transfer Timing from Temporary Register to Compare Register**

## 10.6.2 Interrupt Signal Timing

(1) TGF Flag Setting Timing in Case of Compare Match Figure 10.92 shows the timing for setting of the TGF flag in TSR on compare match, and TGI interrupt request signal timing.

**==> picture [288 x 176] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNT input<br>clock<br>TCNT N N + 1<br>TGR N<br>Compare<br>match signal<br>TGF flag<br>TGI interrupt<br>**----- End of picture text -----**<br>

**Figure 10.92 TGI Interrupt Timing (Compare Match)**

(2) TGF Flag Setting Timing in Case of Input Capture Figure 10.93 shows the timing for setting of the TGF flag in TSR on input capture, and TGI interrupt request signal timing.

**==> picture [289 x 148] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>Input capture<br>signal<br>TCNT N<br>TGR N<br>TGF flag<br>TGI interrupt<br>**----- End of picture text -----**<br>

**Figure 10.93 TGI Interrupt Timing (Input Capture)**

## (3) TCFV Flag/TCFU Flag Setting Timing

Figure 10.94 shows the timing for setting of the TCFV flag in TSR on overflow, and TCIV interrupt request signal timing.

Figure 10.95 shows the timing for setting of the TCFU flag in TSR on underflow, and TCIU interrupt request signal timing.

**==> picture [300 x 160] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNT input<br>clock<br>TCNT<br>H'FFFF H'0000<br>(overflow)<br>Overflow<br>signal<br>TCFV flag<br>TCIV interrupt<br>**----- End of picture text -----**<br>

**Figure 10.94 TCIV Interrupt Setting Timing**

**==> picture [291 x 151] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNT<br>input clock<br>TCNT<br>H'0000 H'FFFF<br>(underflow)<br>Underflow<br>signal<br>TCFU flag<br>TCIU interrupt<br>**----- End of picture text -----**<br>

**Figure 10.95 TCIU Interrupt Setting Timing**

## (4) Status Flag Clearing Timing

After a status flag is read as 1 by the CPU, it is cleared by writing 0 to it. When the direct memory access controller is activated, the flag is cleared automatically. Figure 10.96 shows the timing for status flag clearing by the CPU, and Figure 10.97 shows the timing for status flag clearing by the direct memory access controller.

**==> picture [289 x 149] intentionally omitted <==**

**----- Start of picture text -----**<br>
TSR write cycle<br>T1 T2<br>P0φ<br>Address TSR address<br>Write signal<br>Status flag<br>Interrupt<br>request signal<br>**----- End of picture text -----**<br>

**Figure 10.96 Timing for Status Flag Clearing by CPU**

**==> picture [356 x 152] intentionally omitted <==**

**----- Start of picture text -----**<br>
Direct memory  Direct memory<br>access controller access controller<br>read cycle write cycle<br>P0φ, Bφ<br>Address Source address Destinationaddress<br>Status flag<br>Interrupt<br>request signal<br>Flag clear<br>signal<br>**----- End of picture text -----**<br>

**Figure 10.97 Timing for Status Flag Clearing by Direct Memory Access Controller Activation**

## 10.7 Usage Notes

## 10.7.1 Module Standby Mode Setting

Operation of this module can be disabled or enabled using the standby control register. The initial setting is for the operation to be halted. Register access is enabled by clearing module standby mode. For details, refer to section 42, Power-Down Modes .

## 10.7.2 Input Clock Restrictions

The input clock pulse width must be at least 1.5 states in the case of single-edge detection, and at least 2.5 states in the case of both-edge detection. This module will not operate properly at narrower pulse widths.

In phase counting mode, the phase difference and overlap between the two input clocks must be at least 1.5 states, and the pulse width must be at least 2.5 states. Figure 10.98 shows the input clock conditions in phase counting mode.

**==> picture [334 x 131] intentionally omitted <==**

**----- Start of picture text -----**<br>
Phase Phase<br>differ- differ-<br>Overlap ence Overlap ence Pulse width Pulse width<br>TCLKA<br>(TCLKC)<br>TCLKB<br>(TCLKD)<br>Pulse width Pulse width<br>Notes: Phase difference and overlap : 1.5 states or more<br>Pulse width : 2.5 states or more<br>**----- End of picture text -----**<br>

**Figure 10.98 Phase Difference, Overlap, and Pulse Width in Phase Counting Mode**

## 10.7.3 Caution on Period Setting

When counter clearing on compare match is set, TCNT is cleared in the final state in which it matches the TGR value (the point at which the count value matched by TCNT is updated). Consequently, the actual counter frequency is given by the following formula:

**==> picture [61 x 26] intentionally omitted <==**

Where f: Counter frequency P0  : Peripheral clock operating frequency N: TGR set value

## 10.7.4 Contention between TCNT Write and Clear Operations

If the counter clear signal is generated in the T2 state of a TCNT write cycle, TCNT clearing takes precedence and the TCNT write is not performed.

Figure 10.99 shows the timing in this case.

**==> picture [284 x 136] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT write cycle<br>T1 T2<br>P0φ<br>Address TCNT address<br>Write signal<br>Counter clear<br>signal<br>TCNT N H'0000<br>**----- End of picture text -----**<br>

**Figure 10.99 Contention between TCNT Write and Clear Operations**

## 10.7.5 Contention between TCNT Write and Increment Operations

If incrementing occurs in the T2 state of a TCNT write cycle, the TCNT write takes precedence and TCNT is not incremented.

Figure 10.100 shows the timing in this case.

**==> picture [280 x 151] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT write cycle<br>T1 T2<br>P0φ<br>Address TCNT address<br>Write signal<br>TCNT input<br>clock<br>TCNT N M<br>TCNT write data<br>**----- End of picture text -----**<br>

**Figure 10.100 Contention between TCNT Write and Increment Operations**

## 10.7.6 Contention between TGR Write and Compare Match

If a compare match occurs in the T2 state of a TGR write cycle, the TGR write is executed and the compare match signal is also generated.

Figure 10.101 shows the timing in this case.

**==> picture [281 x 165] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGR write cycle<br>T1 T2<br>P0φ<br>Address TGR address<br>Write signal<br>Compare<br>match signal<br>TCNT N N + 1<br>TGR N M<br>TGR write data<br>**----- End of picture text -----**<br>

**Figure 10.101 Contention between TGR Write and Compare Match**

## 10.7.7 Contention between Buffer Register Write and Compare Match

If a compare match occurs in the T2 state of a TGR write cycle, the data that is transferred to TGR by the buffer operation is the data after write.

Figure 10.102 shows the timing in this case.

**==> picture [321 x 204] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGR write cycle<br>T1 T2<br>P0φ<br>Address Buffer register<br>address<br>Write signal<br>Compare match<br>signal<br>Compare match<br>buffer signal<br>Buffer register write data<br>Buffer register N M<br>TGR N<br>**----- End of picture text -----**<br>

**Figure 10.102 Contention between Buffer Register Write and Compare Match**

## 10.7.8 Contention between Buffer Register Write and TCNT Clear

When the buffer transfer timing is set at the TCNT clear by the buffer transfer mode register (TBTM), if TCNT clear occurs in the T2 state of a TGR write cycle, the data that is transferred to TGR by the buffer operation is the data before write.

Figure 10.103 shows the timing in this case.

**==> picture [321 x 203] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGR write cycle<br>T1 T2<br>P0φ<br>Address Buffer register<br>address<br>Write signal<br>TCNT clear<br>signal<br>Buffer transfer<br>signal<br>Buffer register write data<br>Buffer register N M<br>TGR N<br>**----- End of picture text -----**<br>

**Figure 10.103 Contention between Buffer Register Write and TCNT Clear**

## 10.7.9 Contention between TGR Read and Input Capture

If an input capture signal is generated in the T1 state of a TGR read cycle, the data that is read will be the data in the buffer before input capture transfer.

Figure 10.104 shows the timing in this case.

**==> picture [284 x 152] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGR read cycle<br>T1 T2<br>P0φ<br>Address TGR address<br>Read signal<br>Input capture<br>signal<br>TGR N M<br>Internal data<br>bus N<br>**----- End of picture text -----**<br>

**Figure 10.104 Contention between TGR Read and Input Capture**

## 10.7.10 Contention between TGR Write and Input Capture

If an input capture signal is generated in the T2 state of a TGR write cycle, the input capture operation takes precedence and the write to TGR is not performed.

Figure 10.105 shows the timing in this case.

**==> picture [283 x 148] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGR write cycle<br>T1 T2<br>P0φ<br>Address TGR address<br>Write signal<br>Input capture<br>signal<br>TCNT M<br>TGR M<br>**----- End of picture text -----**<br>

**Figure 10.105 Contention between TGR Write and Input Capture**

## 10.7.11 Contention between Buffer Register Write and Input Capture

If an input capture signal is generated in the T2 state of a buffer register write cycle, the buffer operation takes precedence and the write to the buffer register is not performed.

Figure 10.106 shows the timing in this case.

**==> picture [284 x 174] intentionally omitted <==**

**----- Start of picture text -----**<br>
Buffer register write cycle<br>T1 T2<br>P0φ<br>Address Buffer registeraddress<br>Write signal<br>Input capture<br>signal<br>TCNT N<br>TGR M N<br>Buffer register M<br>**----- End of picture text -----**<br>

**Figure 10.106 Contention between Buffer Register Write and Input Capture**

## 10.7.12 TCNT_2 Write and Overflow/Underflow Contention in Cascade Connection

With timer counters TCNT_1 and TCNT_2 in a cascade connection, when a contention occurs during TCNT_1 count (during a TCNT_2 overflow/underflow) in the T2 state of the TCNT_2 write cycle, the write to TCNT_2 is conducted, and the TCNT_1 count signal is disabled. At this point, if there is match with TGRA_1 and the TCNT_1 value, a compare signal is issued. Furthermore, when the TCNT_1 count clock is selected as the input capture source of channel 0, TGRA_0 to D_0 carry out the input capture operation. In addition, when the compare match/input capture is selected as the input capture source of TGRB_1, TGRB_1 carries out input capture operation. The timing is shown in Figure 10.107 .

For cascade connections, be sure to synchronize settings for channels 1 and 2 when setting TCNT clearing.

**==> picture [296 x 367] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT write cycle<br>T1 T2<br>P0φ<br>Address TCNT_2 address<br>Write signal<br>TCNT_2 H'FFFE H'FFFF N N + 1<br>TCNT_2 write data<br>TGRA_2 to<br>TGRB_2 H'FFFF<br>Ch2 compare-<br>match signal A/B<br>TCNT_1 input  Disabled<br>clock<br>TCNT_1 M<br>TGRA_1 M<br>Ch1 compare-<br>match signal A<br>TGRB_1 N M<br>Ch1 input capture<br>signal B<br>TCNT_0 P<br>TGRA_0 to<br>Q P<br>TGRD_0<br>Ch0 input capture<br>signal A to D<br>**----- End of picture text -----**<br>

**Figure 10.107 TCNT_2 Write and Overflow/Underflow Contention with Cascade Connection**

## 10.7.13 Counter Value during Complementary PWM Mode Stop

When counting operation is suspended with TCNT_3 and TCNT_4 in complementary PWM mode, TCNT_3 has the timer dead time register (TDDR) value, and TCNT_4 is held at H'0000.

When restarting complementary PWM mode, counting begins automatically from the initialized state. This explanatory diagram is shown in Figure 10.108 .

When counting begins in another operating mode, be sure that TCNT_3 and TCNT_4 are set to the initial values.

**==> picture [296 x 191] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGRA_3<br>TCDR<br>TCNT_3<br>TCNT_4<br>TDDR<br>H'0000<br>Complementary PWM  Complementary PWM<br>mode operation mode operation<br>Counter  Complementary<br>operation stop PWM restart<br>**----- End of picture text -----**<br>

**Figure 10.108 Counter Value during Complementary PWM Mode Stop**

## 10.7.14 Buffer Operation Setting in Complementary PWM Mode

In complementary PWM mode, conduct rewrites by buffer operation for the PWM cycle setting register (TGRA_3), timer cycle data register (TCDR), and duty setting registers (TGRB_3, TGRA_4, and TGRB_4).

In complementary PWM mode, channel 3 and channel 4 buffers operate in accordance with bit settings BFA and BFB of TMDR_3. When TMDR_3's BFA bit is set to 1, TGRC_3 functions as a buffer register for TGRA_3. At the same time, TGRC_4 functions as the buffer register for TGRA_4, and TCBR functions as the TCDR's buffer register.

## 10.7.15 Reset Sync PWM Mode Buffer Operation and Compare Match Flag

When setting buffer operation for reset sync PWM mode, set the BFA and BFB bits of TMDR_4 to 0. The TIOC4C pin will be unable to produce its waveform output if the BFA bit of TMDR_4 is set to 1.

In reset sync PWM mode, the channel 3 and channel 4 buffers operate in accordance with the BFA and BFB bit settings of TMDR_3. For example, if the BFA bit of TMDR_3 is set to 1, TGRC_3 functions as the buffer register for TGRA_3. At the same time, TGRC_4 functions as the buffer register for TGRA_4.

The TGFC bit and TGFD bit of TSR_3 and TSR_4 are not set when TGRC_3 and TGRD_3 are operating as buffer registers.

Figure 10.109 shows an example of operations for TGR_3, TGR_4, TIOC3, and TIOC4, with TMDR_3's BFA and BFB bits set to 1, and TMDR_4's BFA and BFB bits set to 0.

**==> picture [319 x 241] intentionally omitted <==**

**----- Start of picture text -----**<br>
TGRA_3 Buffer transfer with<br>TCNT_3 compare match A3<br>Point a<br>TGRC_3 TGRA_3,<br>TGRC_3<br>TGRB_3, TGRA_4,<br>TGRB_4<br>Point b<br>TGRD_3, TGRC_4, TGRB_3, TGRD_3,<br>TGRD_4 TGRA_4, TGRC_4,<br>TGRB_4, TGRD_4<br>H'0000<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>TIOC4A<br>TIOC4C<br>TIOC4B<br>TIOC4D<br>TGFC Not set<br>TGFD Not set<br>**----- End of picture text -----**<br>

**Figure 10.109 Buffer Operation and Compare-Match Flags in Reset Synchronous PWM Mode**

## 10.7.16 Overflow Flags in Reset Synchronous PWM Mode

When set to reset synchronous PWM mode, TCNT_3 and TCNT_4 start counting when the CST3 bit of TSTR is set to 1. At this point, TCNT_4's count clock source and count edge obey the TCR_3 setting.

In reset synchronous PWM mode, with cycle register TGRA_3's set value at H'FFFF, when specifying TGR3A comparematch for the counter clear source, TCNT_3 and TCNT_4 count up to H'FFFF, then a compare-match occurs with TGRA_3, and TCNT_3 and TCNT_4 are both cleared. At this point, TSR's overflow flag TCFV bit is not set.

Figure 10.110 shows a TCFV bit operation example in reset synchronous PWM mode with a set value for cycle register TGRA_3 of H'FFFF, when a TGRA_3 compare-match has been specified without synchronous setting for the counter clear source.

**==> picture [311 x 155] intentionally omitted <==**

**----- Start of picture text -----**<br>
Counter cleared by compare match 3A<br>TGRA_3<br>(H'FFFF)<br>TCNT_3 = TCNT_4<br>H'0000<br>TCFV_3 Not set<br>TCFV_4 Not set<br>**----- End of picture text -----**<br>

**Figure 10.110 Reset Synchronous PWM Mode Overflow Flag**

## 10.7.17 Contention between Overflow/Underflow and Counter Clearing

If overflow/underflow and counter clearing occur simultaneously, the TCFV/TCFU flag in TSR is not set and TCNT clearing takes precedence.

Figure 10.111 shows the operation timing when a TGR compare match is specified as the clearing source, and when H'FFFF is set in TGR.

**==> picture [257 x 148] intentionally omitted <==**

**----- Start of picture text -----**<br>
P0φ<br>TCNT input<br>clock<br>TCNT H'FFFF H'0000<br>Counter clear<br>signal<br>TGF<br>TCFV Disabled<br>**----- End of picture text -----**<br>

**Figure 10.111 Contention between Overflow and Counter Clearing**

## 10.7.18 Contention between TCNT Write and Overflow/Underflow

If there is an up-count or down-count in the T2 state of a TCNT write cycle, and overflow/underflow occurs, the TCNT write takes precedence and the TCFV/TCFU flag in TSR is not set.

Figure 10.112 shows the operation timing when there is contention between TCNT write and overflow.

**==> picture [228 x 134] intentionally omitted <==**

**----- Start of picture text -----**<br>
TCNT write cycle<br>T1 T2<br>P0φ<br>Address TCNT address<br>Write signal<br>TCNT write data<br>TCNT H'FFFF M<br>Disabled<br>TCFV flag<br>**----- End of picture text -----**<br>

## **Figure 10.112 Contention between TCNT Write and Overflow**

## 10.7.19 Cautions on Transition from Normal Operation or PWM Mode 1 to Reset-Synchronized PWM Mode

When making a transition from channel 3 or 4 normal operation or PWM mode 1 to reset-synchronized PWM mode, if the counter is halted with the output pins (TIOC3B, TIOC3D, TIOC4A, TIOC4C, TIOC4B, TIOC4D) in the high-level state, followed by the transition to reset-synchronized PWM mode and operation in that mode, the initial pin output will not be correct.

When making a transition from normal operation to reset-synchronized PWM mode, write H'11 to registers TIORH_3, TIORL_3, TIORH_4, and TIORL_4 to initialize the output pins to low level output, then set an initial register value of H'00 before making the mode transition.

When making a transition from PWM mode 1 to reset-synchronized PWM mode, first switch to normal operation, then initialize the output pins to low level output and set an initial register value of H'00 before making the transition to resetsynchronized PWM mode.

## 10.7.20 Output Level in Complementary PWM Mode and Reset-Synchronized PWM Mode

When channels 3 and 4 are in complementary PWM mode or reset-synchronized PWM mode, the PWM waveform output level is set with the OLSP and OLSN bits in the timer output control register (TOCR). In the case of complementary PWM mode or reset-synchronized PWM mode, TIOR should be set to H'00.

## 10.7.21 Interrupts in Module Standby Mode

If module standby mode is entered when an interrupt has been requested, it will not be possible to clear the CPU interrupt source or the direct memory access controller activation source. Interrupts should therefore be disabled before entering module standby mode.

## 10.7.22 Simultaneous Capture of TCNT_1 and TCNT_2 in Cascade Connection

When timer counters 1 and 2 (TCNT_1 and TCNT_2) are operated as a 32-bit counter in cascade connection, the cascade counter value cannot be captured successfully even if input-capture input is simultaneously done to TIOC1A and TIOC2A or to TIOC1B and TIOC2B. This is because the input timing of TIOC1A and TIOC2A or of TIOC1B and TIOC2B may not be the same when external input-capture signals to be input into TCNT_1 and TCNT_2 are taken in synchronization with the internal clock. For example, TCNT_1 (the counter for upper 16 bits) does not capture the countup value by overflow from TCNT_2 (the counter for lower 16 bits) but captures the count value before the count-up. In this case, the values of TCNT_1 = H'FFF1 and TCNT_2 = H'0000 should be transferred to TGRA_1 and TGRA_2 or to TGRB_1 and TGRB_2, but the values of TCNT_1 = H'FFF0 and TCNT_2 = H'0000 are erroneously transferred.

## 10.7.23 Notes on Output Waveform Control During Synchronous Counter Clearing in Complementary PWM Mode

In complementary PWM mode, when output waveform control during synchronous counter clearing is enabled (WRE in the TWCR register set to 1), the following problems may occur when condition (1) or condition (2), below, is satisfied.

- Dead time for the PWM output pins may be too short (or nonexistent).

- Active-level output from the PWM negative-phase pins may occur outside the correct active-level output interval

- Condition (1): When synchronous clearing occurs in the PWM output dead time interval within initial output suppression interval (10) ( Figure 10.113 ).

- Condition (2): When synchronous clearing occurs within initial output suppression interval (10) or (11) and TGRB_3  TDDR, TGRA_4  TDDR, or TGRB_4  TDDR is true ( Figure 10.114 )

**==> picture [363 x 262] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronous clearing<br>(10) (11) (10) (11)<br>TGRA_3<br>TCNT_3<br>Tb interval Tb interval<br>TCNT_4<br>TGR<br>TDDR<br>0<br>PWM output<br>(positive phase)<br>PWM output  TDDR<br>(negative phase)<br>Shortened dead time<br>Initial output suppression<br>Dead time<br>Note:  PWM output is low-active.<br>**----- End of picture text -----**<br>

## **Figure 10.113 Condition (1) Synchronous Clearing Example**

**==> picture [399 x 274] intentionally omitted <==**

**----- Start of picture text -----**<br>
Synchronous clearing<br>(10) (11) (10) (11)<br>TGRA_3<br>TCNT_3<br>Tb interval Tb interval<br>TCNT_4<br>TDDR<br>TGR<br>0<br>PWM output<br>(positive phase)<br>PWM output<br>(negative phase)<br>Active-level output occurs at synchronous clearing<br>Nonexistent<br>even though no active-level output interval has been set.<br>dead time<br>Initial output suppression<br>Dead time<br>Note:  PWM output is low-active.<br>**----- End of picture text -----**<br>

**Figure 10.114 Condition (2) Synchronous Clearing Example**

The following workaround can be used to avoid these problems.

When using synchronous clearing, make sure to set compare registers TGRB_3, TGRA_4, and TGRB_4 to a value twice or more the setting of dead time data register TDDR.

## 10.8 Output Pin Initialization for Multi-Function Timer Pulse Unit 2

## 10.8.1 Operating Modes

This module has the following six operating modes. Waveform output is possible in all of these modes.

- Normal mode (channels 0 to 4)

- PWM mode 1 (channels 0 to 4)

- PWM mode 2 (channels 0 to 2)

- Phase counting modes 1 to 4 (channels 1 and 2)

- Complementary PWM mode (channels 3 and 4)

- Reset-synchronized PWM mode (channels 3 and 4)

The output pin initialization method for each of these modes is described in this section.

## 10.8.2 Reset Start Operation

The output pins of this module (TIOC*) are initialized low by a power-on reset or in deep standby mode. Since the pin functions are selected using the general I/O ports, when the general I/O port is set, the pin states at that point are output to the ports. When this module output is selected by the general I/O port immediately after a reset, the initial output level, low, is output directly at the port. When the active level is low, the system will operate at this point, and therefore the general

I/O port setting should be made after the initialization of the output pins is completed.

Note: Channel number and port notation are substituted for * .

## 10.8.3 Operation in Case of Re-Setting Due to Error during Operation, etc.

If an error occurs during operation of this module, the module output should be cut by the system. Cutoff is performed by switching the pin output to port output with the general I/O port and outputting the inverse of the active level. The pin initialization procedures for re-setting due to an error during operation, etc., and the procedures for restarting in a different mode after re-setting, are shown below.

This module has six operating modes, as stated above. There are thus 36 mode transition combinations, but some transitions are not available with certain channel and mode combinations. Possible mode transition combinations are shown in Table 10.57 .

## **Table 10.57 Mode Transition Combinations**

|**Before**|**After**|
|---|---|
||**Normal**<br>**PWM1**<br>**PWM2**<br>**PCM**<br>**CPWM**<br>**RPWM**|
|Normal|(1)<br>(2)<br>(3)<br>(4)<br>(5)<br>(6)|
|PWM1|(7)<br>(8)<br>(9)<br>(10)<br>(11)<br>(12)|
|PWM2|(13)<br>(14)<br>(15)<br>(16)<br>None<br>None|
|PCM|(17)<br>(18)<br>(19)<br>(20)<br>None<br>None|
|CPWM|(21)<br>(22)<br>None<br>None<br>(23) (24)<br>(25)|
|RPWM|(26)<br>(27)<br>None<br>None<br>(28)<br>(29)|

[Legend] Normal: Normal mode PWM1: PWM mode 1 PWM2: PWM mode 2 PCM: Phase counting modes 1 to 4 CPWM: Complementary PWM mode RPWM: Reset-synchronized PWM mode

## 10.8.4 Overview of Initialization Procedures and Mode Transitions in Case of Error during Operation, etc.

- When making a transition to a mode (Normal, PWM1, PWM2, PCM) in which the pin output level is selected by the timer I/O control register (TIOR) setting, initialize the pins by means of a TIOR setting.

- In PWM mode 1, since a waveform is not output to the TIOC*B (TIOC *D) pin, setting TIOR will not initialize the pins. If initialization is required, carry it out in normal mode, then switch to PWM mode 1.

- In PWM mode 2, since a waveform is not output to the cycle register pin, setting TIOR will not initialize the pins. If initialization is required, carry it out in normal mode, then switch to PWM mode 2.

- In normal mode or PWM mode 2, if TGRC and TGRD operate as buffer registers, setting TIOR will not initialize the buffer register pins. If initialization is required, clear buffer mode, carry out initialization, then set buffer mode again.

- In PWM mode 1, if either TGRC or TGRD operates as a buffer register, setting TIOR will not initialize the TGRC pin. To initialize the TGRC pin, clear buffer mode, carry out initialization, then set buffer mode again.

- When making a transition to a mode (CPWM, RPWM) in which the pin output level is selected by the timer output control register (TOCR) setting, switch to normal mode and perform initialization with TIOR, then restore TIOR to its initial value, and temporarily disable channel 3 and 4 output with the timer output master enable register (TOER). Then operate the unit in accordance with the mode setting procedure (TOCR setting, TMDR setting, TOER setting).

## Note: Channel number is substituted for * indicated in this article.

Pin initialization procedures are described below for the numbered combinations in Table 10.57 . The active level is assumed to be low.

## (1) Operation when Error Occurs during Normal Mode Operation, and Operation is Restarted in Normal Mode

Figure 10.115 shows an explanatory diagram of the case where an error occurs in normal mode and operation is restarted in normal mode after re-setting.

**==> picture [398 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(normal) (1) (1 init (MTU2) (1)  occurs (PORT) (0) (normal) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

## **Figure 10.115 Error Occurrence in Normal Mode, Recovery in Normal Mode**

1. After a reset, the module output is low and ports are in the high-impedance state.

2. After a reset, the TMDR setting is for normal mode.

3. For channels 3 and 4, enable output with TOER before initializing the pins with TIOR.

4. Initialize the pins with TIOR. (The example shows initial high output, with low output on compare-match occurrence.)

5. Set the multi-function timer pulse unit 2 output with the general I/O port.

6. The count operation is started by TSTR.

7. Output goes low on compare-match occurrence.

8. An error occurs.

9. Set port output with the general I/O port and output the inverse of the active level.

10. The count operation is stopped by TSTR.

11. Not necessary when restarting in normal mode.

12. Initialize the pins with TIOR.

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

- (2) Operation when Error Occurs during Normal Mode Operation, and Operation is Restarted in PWM Mode 1

Figure 10.116 shows an explanatory diagram of the case where an error occurs in normal mode and operation is restarted in PWM mode 1 after re-setting.

**==> picture [408 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(normal) (1) (1 init (MTU2) (1) occurs (PORT) (0) (PWM1) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B Not initialized (TIOC*B)<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.116 Error Occurrence in Normal Mode, Recovery in PWM Mode 1**

- 1 to 10 are the same as in Figure 10.115 .

11. Set PWM mode 1.

12. Initialize the pins with TIOR. (In PWM mode 1, the TIOC*B side is not initialized. If initialization is required, initialize in normal mode, and then switch to PWM mode 1.)

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

- (3) Operation when Error Occurs during Normal Mode Operation, and Operation is Restarted in PWM Mode 2

Figure 10.117 shows an explanatory diagram of the case where an error occurs in normal mode and operation is restarted in PWM mode 2 after re-setting.

**==> picture [423 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(normal) (1) (1 init (MTU2) (1) occurs (PORT) (0) (PWM2) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A Not initialized (cycle register)<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.117 Error Occurrence in Normal Mode, Recovery in PWM Mode 2**

- 1 to 10 are the same as in Figure 10.115 .

11. Set PWM mode 2.

12. Initialize the pins with TIOR. (In PWM mode 2, the cycle register pins are not initialized. If initialization is required, initialize in normal mode, and then switch to PWM mode 2.)

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

Note: PWM mode 2 can only be set for channels 0 to 2, and therefore TOER setting is not necessary.

- (4) Operation when Error Occurs during Normal Mode Operation, and Operation is Restarted in Phase Counting Mode

Figure 10.118 shows an explanatory diagram of the case where an error occurs in normal mode and operation is restarted in phase counting mode after re-setting.

**==> picture [416 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(normal) (1) (1 init (MTU2) (1) occurs (PORT) (0) (PCM) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.118 Error Occurrence in Normal Mode, Recovery in Phase Counting Mode**

- 1 to 10 are the same as in Figure 10.115 .

11. Set phase counting mode.

12. Initialize the pins with TIOR.

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

Note: Phase counting mode can only be set for channels 1 and 2, and therefore TOER setting is not necessary.

- (5) Operation when Error Occurs during Normal Mode Operation, and Operation is Restarted in Complementary PWM Mode

Figure 10.119 shows an explanatory diagram of the case where an error occurs in normal mode and operation is restarted in complementary PWM mode after re-setting.

**==> picture [415 x 125] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 (16) (17) (18)<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TIOR TIOR TOER TOCR TMDR TOER PFC TSTR<br>(normal) (1) (1 init (MTU2) (1) occurs (PORT) (0) (0 init (disabled) (0) (CPWM) (1) (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.119 Error Occurrence in Normal Mode, Recovery in Complementary PWM Mode**

1 to 10 are the same as in Figure 10.115 .

11. Initialize the normal mode waveform generation section with TIOR.

12. Disable operation of the normal mode waveform generation section with TIOR.

13. Disable channel 3 and 4 output with TOER.

14. Select the complementary PWM output level and cyclic output enabling/disabling with TOCR.

15. Set complementary PWM.

16. Enable channel 3 and 4 output with TOER.

17. Set the multi-function timer pulse unit 2 output with the general I/O port.

18. Operation is restarted by TSTR.

- (6) Operation when Error Occurs during Normal Mode Operation, and Operation is Restarted in Reset-Synchronized PWM Mode

Figure 10.120 shows an explanatory diagram of the case where an error occurs in normal mode and operation is restarted in reset-synchronized PWM mode after re-setting.

**==> picture [426 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TIOR TIOR TOER TOCR TMDR TOER PFC TSTR<br>(normal) (1) (1 init (MTU2) (1) occurs (PORT) (0) (0 init (disabled) (0) (RPWM) (1) (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.120 Error Occurrence in Normal Mode, Recovery in Reset-Synchronized PWM Mode**

1 to 13 are the same as in Figure 10.115 .

14. Select the reset-synchronized PWM output level and cyclic output enabling/disabling with TOCR.

15. Set reset-synchronized PWM.

16. Enable channel 3 and 4 output with TOER.

17. Set the multi-function timer pulse unit 2 output with the general I/O port.

18. Operation is restarted by TSTR.

## (7) Operation when Error Occurs during PWM Mode 1 Operation, and Operation is Restarted in Normal Mode

Figure 10.121 shows an explanatory diagram of the case where an error occurs in PWM mode 1 and operation is restarted in normal mode after re-setting.

**==> picture [401 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PWM1) (1) (1 init (MTU2) (1) occurs (PORT) (0) (normal) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B Not initialized (TIOC*B)<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

## **Figure 10.121 Error Occurrence in PWM Mode 1, Recovery in Normal Mode**

1. After a reset, the module output is low and ports are in the high-impedance state.

2. Set PWM mode 1.

3. For channels 3 and 4, enable output with TOER before initializing the pins with TIOR.

4. Initialize the pins with TIOR. (The example shows initial high output, with low output on compare-match occurrence. In PWM mode 1, the TIOC*B side is not initialized.)

5. Set the multi-function timer pulse unit 2 output with the general I/O port.

6. The count operation is started by TSTR.

7. Output goes low on compare-match occurrence.

8. An error occurs.

9. Set port output with the general I/O port and output the inverse of the active level.

10. The count operation is stopped by TSTR.

11. Set normal mode.

12. Initialize the pins with TIOR.

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

- (8) Operation when Error Occurs during PWM Mode 1 Operation, and Operation is Restarted in PWM Mode 1

Figure 10.122 shows an explanatory diagram of the case where an error occurs in PWM mode 1 and operation is restarted in PWM mode 1 after re-setting.

**==> picture [405 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PWM1) (1) (1 init (MTU2) (1) occurs (PORT) (0) (PWM1) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B Not initialized (TIOC*B) Not initialized (TIOC*B)<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.122 Error Occurrence in PWM Mode 1, Recovery in PWM Mode 1**

- 1 to 10 are the same as in Figure 10.121 .

11. Not necessary when restarting in PWM mode 1.

12. Initialize the pins with TIOR. (In PWM mode 1, the TIOC*B side is not initialized.)

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

- (9) Operation when Error Occurs during PWM Mode 1 Operation, and Operation is Restarted in PWM Mode 2

Figure 10.123 shows an explanatory diagram of the case where an error occurs in PWM mode 1 and operation is restarted in PWM mode 2 after re-setting.

**==> picture [421 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PWM1) (1) (1 init (MTU2) (1) occurs (PORT) (0) (PWM2) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A Not initialized (cycle register)<br>TIOC*B Not initialized (TIOC*B)<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.123 Error Occurrence in PWM Mode 1, Recovery in PWM Mode 2**

- 1 to 10 are the same as in Figure 10.121 .

11. Set PWM mode 2.

12. Initialize the pins with TIOR. (In PWM mode 2, the cycle register pins are not initialized.)

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

Note: PWM mode 2 can only be set for channels 0 to 2, and therefore TOER setting is not necessary.

- (10) Operation when Error Occurs during PWM Mode 1 Operation, and Operation is Restarted in Phase Counting Mode

Figure 10.124 shows an explanatory diagram of the case where an error occurs in PWM mode 1 and operation is restarted in phase counting mode after re-setting.

**==> picture [402 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PWM1) (1) (1 init (MTU2) (1) occurs (PORT) (0) (PCM) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B Not initialized (TIOC*B)<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.124 Error Occurrence in PWM Mode 1, Recovery in Phase Counting Mode**

- 1 to 10 are the same as in Figure 10.121 .

11. Set phase counting mode.

12. Initialize the pins with TIOR.

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

Note: Phase counting mode can only be set for channels 1 and 2, and therefore TOER setting is not necessary.

- (11) Operation when Error Occurs during PWM Mode 1 Operation, and Operation is Restarted in Complementary PWM Mode

Figure 10.125 shows an explanatory diagram of the case where an error occurs in PWM mode 1 and operation is restarted in complementary PWM mode after re-setting.

**==> picture [408 x 112] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR TIOR TOER TOCR TMDR TOER PFC TSTR<br>(PWM1) (1) (1 init (MTU2) (1) occurs (PORT) (0) (normal) (0 init (disabled) (0) (CPWM) (1) (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC3A<br>TIOC3B Not initialized (TIOC3B)<br>TIOC3D Not initialized (TIOC3D)<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.125 Error Occurrence in PWM Mode 1, Recovery in Complementary PWM Mode**

## 1 to 10 are the same as in Figure 10.121 .

11. Set normal mode for initialization of the normal mode waveform generation section.

12. Initialize the PWM mode 1 waveform generation section with TIOR.

13. Disable operation of the PWM mode 1 waveform generation section with TIOR.

14. Disable channel 3 and 4 output with TOER.

15. Select the complementary PWM output level and cyclic output enabling/disabling with TOCR.

16. Set complementary PWM.

17. Enable channel 3 and 4 output with TOER.

18. Set the multi-function timer pulse unit 2 output with the general I/O port.

19. Operation is restarted by TSTR.

- (12) Operation when Error Occurs during PWM Mode 1 Operation, and Operation is Restarted in Reset-Synchronized PWM Mode

Figure 10.126 shows an explanatory diagram of the case where an error occurs in PWM mode 1 and operation is restarted in reset-synchronized PWM mode after re-setting.

**==> picture [409 x 113] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19<br>RESET TMDR TOER TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR TIOR TOER TOCR TMDR TOER PFC TSTR<br>(PWM1) (1) (1 init (MTU2) (1) occurs (PORT) (0) (normal) (0 init(disabled) (0) (RPWM) (1) (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC3A<br>TIOC3B Not initialized (TIOC3B)<br>TIOC3D Not initialized (TIOC3D)<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.126 Error Occurrence in PWM Mode 1, Recovery in Reset-Synchronized PWM Mode**

- 1 to 14 are the same as in Figure 10.125 .

15. Select the reset-synchronized PWM output level and cyclic output enabling/disabling with TOCR.

16. Set reset-synchronized PWM.

17. Enable channel 3 and 4 output with TOER.

18. Set the multi-function timer pulse unit 2 output with the general I/O port.

19. Operation is restarted by TSTR.

- (13) Operation when Error Occurs during PWM Mode 2 Operation, and Operation is Restarted in Normal Mode

Figure 10.127 shows an explanatory diagram of the case where an error occurs in PWM mode 2 and operation is restarted in normal mode after re-setting.

**==> picture [382 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TMDR TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PWM2) (1 init (MTU2) (1) occurs (PORT) (0) (normal) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A Not initialized (cycle register)<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.127 Error Occurrence in PWM Mode 2, Recovery in Normal Mode**

1. After a reset, the module output is low and ports are in the high-impedance state.

2. Set PWM mode 2.

3. Initialize the pins with TIOR. (The example shows initial high output, with low output on compare-match occurrence. In PWM mode 2, the cycle register pins are not initialized. In the example, TIOC *A is the cycle register.)

4. Set the multi-function timer pulse unit 2 output with the general I/O port.

5. The count operation is started by TSTR.

6. Output goes low on compare-match occurrence.

7. An error occurs.

8. Set port output with the general I/O port and output the inverse of the active level.

9. The count operation is stopped by TSTR.

10. Set normal mode.

11. Initialize the pins with TIOR.

12. Set the multi-function timer pulse unit 2 output with the general I/O port.

13. Operation is restarted by TSTR.

- (14) Operation when Error Occurs during PWM Mode 2 Operation, and Operation is Restarted in PWM Mode 1

Figure 10.128 shows an explanatory diagram of the case where an error occurs in PWM mode 2 and operation is restarted in PWM mode 1 after re-setting.

**==> picture [384 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TMDR TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PWM2) (1 init (MTU2) (1) occurs (PORT) (0) (PWM1) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A Not initialized (cycle register)<br>TIOC*B Not initialized (TIOC*B)<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.128 Error Occurrence in PWM Mode 2, Recovery in PWM Mode 1**

- 1 to 9 are the same as in Figure 10.127 .

10. Set PWM mode 1.

11. Initialize the pins with TIOR. (In PWM mode 1, the TIOC*B side is not initialized.)

12. Set the multi-function timer pulse unit 2 output with the general I/O port.

13. Operation is restarted by TSTR.

- (15) Operation when Error Occurs during PWM Mode 2 Operation, and Operation is Restarted in PWM Mode 2

Figure 10.129 shows an explanatory diagram of the case where an error occurs in PWM mode 2 and operation is restarted in PWM mode 2 after re-setting.

**==> picture [400 x 124] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TMDR TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PWM2) (1 init (MTU2) (1) occurs (PORT) (0) (PWM2) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A Not initialized (cycle register) Not initialized (cycle register)<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.129 Error Occurrence in PWM Mode 2, Recovery in PWM Mode 2**

## 1 to 9 are the same as in Figure 10.127 .

10. Not necessary when restarting in PWM mode 2.

11. Initialize the pins with TIOR. (In PWM mode 2, the cycle register pins are not initialized.)

12. Set the multi-function timer pulse unit 2 output with the general I/O port.

13. Operation is restarted by TSTR.

- (16) Operation when Error Occurs during PWM Mode 2 Operation, and Operation is Restarted in Phase Counting Mode

Figure 10.130 shows an explanatory diagram of the case where an error occurs in PWM mode 2 and operation is restarted in phase counting mode after re-setting.

**==> picture [381 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TMDR TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PWM2) (1 init (MTU2) (1) occurs (PORT) (0) (PCM) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A Not initialized (cycle register)<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.130 Error Occurrence in PWM Mode 2, Recovery in Phase Counting Mode**

- 1 to 9 are the same as in Figure 10.127 .

10. Set phase counting mode.

11. Initialize the pins with TIOR.

12. Set the multi-function timer pulse unit 2 output with the general I/O port.

13. Operation is restarted by TSTR.

- (17) Operation when Error Occurs during Phase Counting Mode Operation, and Operation is Restarted in Normal Mode

Figure 10.131 shows an explanatory diagram of the case where an error occurs in phase counting mode and operation is restarted in normal mode after re-setting.

**==> picture [373 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TMDR TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PCM) (1 init (MTU2) (1) occurs (PORT) (0) (normal) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

## **Figure 10.131 Error Occurrence in Phase Counting Mode, Recovery in Normal Mode**

1. After a reset, the module output is low and ports are in the high-impedance state.

2. Set phase counting mode.

3. Initialize the pins with TIOR. (The example shows initial high output, with low output on compare-match occurrence.)

4. Set the multi-function timer pulse unit 2 output with the general I/O port.

5. The count operation is started by TSTR.

6. Output goes low on compare-match occurrence.

7. An error occurs.

8. Set port output with the general I/O port and output the inverse of the active level.

9. The count operation is stopped by TSTR.

10. Set in normal mode.

11. Initialize the pins with TIOR.

12. Set the multi-function timer pulse unit 2 output with the general I/O port.

13. Operation is restarted by TSTR.

- (18) Operation when Error Occurs during Phase Counting Mode Operation, and Operation is Restarted in PWM Mode 1

Figure 10.132 shows an explanatory diagram of the case where an error occurs in phase counting mode and operation is restarted in PWM mode 1 after re-setting.

**==> picture [386 x 121] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TMDR TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PCM) (1 init (MTU2) (1) occurs (PORT) (0) (PWM1) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B Not initialized (TIOC*B)<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.132 Error Occurrence in Phase Counting Mode, Recovery in PWM Mode 1**

- 1 to 9 are the same as in Figure 10.131 .

10. Set PWM mode 1.

11. Initialize the pins with TIOR. (In PWM mode 1, the TIOC *B side is not initialized.)

12. Set the multi-function timer pulse unit 2 output with the general I/O port.

13. Operation is restarted by TSTR.

- (19) Operation when Error Occurs during Phase Counting Mode Operation, and Operation is Restarted in PWM Mode 2

Figure 10.133 shows an explanatory diagram of the case where an error occurs in phase counting mode and operation is restarted in PWM mode 2 after re-setting.

**==> picture [399 x 123] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TMDR TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PCM) (1 init (MTU2) (1) occurs (PORT) (0) (PWM2) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A Not initialized (cycle register)<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.133 Error Occurrence in Phase Counting Mode, Recovery in PWM Mode 2**

- 1 to 9 are the same as in Figure 10.131 .

10. Set PWM mode 2.

11. Initialize the pins with TIOR. (In PWM mode 2, the cycle register pins are not initialized.)

12. Set the multi-function timer pulse unit 2 output with the general I/O port.

13. Operation is restarted by TSTR.

- (20) Operation when Error Occurs during Phase Counting Mode Operation, and Operation is Restarted in Phase Counting Mode

Figure 10.134 shows an explanatory diagram of the case where an error occurs in phase counting mode and operation is restarted in phase counting mode after re-setting.

**==> picture [377 x 122] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TMDR TIOR PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(PCM) (1 init (MTU2) (1) occurs (PORT) (0) (PCM) (1 init (MTU2) (1)<br>0 out) 0 out)<br>MTU2 module output<br>TIOC*A<br>TIOC*B<br>Port output<br>PEn High-Z<br>PEn High-Z<br>n = 0 to 15<br>**----- End of picture text -----**<br>

**Figure 10.134 Error Occurrence in Phase Counting Mode, Recovery in Phase Counting Mode**

- 1 to 9 are the same as in Figure 10.131 .

10. Not necessary when restarting in phase counting mode.

11. Initialize the pins with TIOR.

12. Set the multi-function timer pulse unit 2 output with the general I/O port.

13. Operation is restarted by TSTR.

## (21) Operation when Error Occurs during Complementary PWM Mode Operation, and Operation is Restarted in Normal Mode

Figure 10.135 shows an explanatory diagram of the case where an error occurs in complementary PWM mode and operation is restarted in normal mode after re-setting.

|MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|||||||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
||||Hig|h-Z||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
||||Hig|h-Z||||||||||||||||
|||||||||||||||||||||
|||||||||||||||||||||
||||Hig|h-Z||||||||||||||||
|||||||||||||||||||||

## **Figure 10.135 Error Occurrence in Complementary PWM Mode, Recovery in Normal Mode**

1. After a reset, the module output is low and ports are in the high-impedance state.

2. Select the complementary PWM output level and cyclic output enabling/disabling with TOCR.

3. Set complementary PWM.

4. Enable channel 3 and 4 output with TOER.

5. Set the multi-function timer pulse unit 2 output with the general I/O port.

6. The count operation is started by TSTR.

7. The complementary PWM waveform is output on compare-match occurrence.

8. An error occurs.

9. Set port output with the general I/O port and output the inverse of the active level.

10. The count operation is stopped by TSTR. (This module outputs the same value as the complementary PWM output initial value.)

11. Set normal mode. (This module outputs a low-level signal.)

12. Initialize the pins with TIOR.

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

- (22) Operation when Error Occurs during Complementary PWM Mode Operation, and Operation is Restarted in PWM Mode 1

Figure 10.136 shows an explanatory diagram of the case where an error occurs in complementary PWM mode and operation is restarted in PWM mode 1 after re-setting.

**==> picture [405 x 138] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TOCR TMDR TOER PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(CPWM) (1) (MTU2) (1) occurs (PORT) (0) (PWM1) (1 init (MTU2) (1)<br>0 out)<br>MTU2 module output<br>TIOC3A<br>TIOC3B Not initialized (TIOC3B)<br>TIOC3D Not initialized (TIOC3D)<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.136 Error Occurrence in Complementary PWM Mode, Recovery in PWM Mode 1**

- 1 to 10 are the same as in Figure 10.135 .

11. Set PWM mode 1. (This module outputs a low-level signal.)

12. Initialize the pins with TIOR. (In PWM mode 1, the TIOC *B side is not initialized.)

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

## (23) Operation when Error Occurs during Complementary PWM Mode Operation, and Operation is Restarted in Complementary PWM Mode

Figure 10.137 shows an explanatory diagram of the case where an error occurs in complementary PWM mode and operation is restarted in complementary PWM mode after re-setting (when operation is restarted using the cycle and duty settings at the time the counter was stopped).

|MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(CPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>PFC<br>(MTU2)<br>12<br>TSTR<br>(1)<br>13<br>Match|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||Hig|h-Z|||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||Hig|h-Z|||||||||||||||||||
||||||||||||||||||||||||
||||||||||||||||||||||||
||||Hig|h-Z|||||||||||||||||||
||||||||||||||||||||||||

**Figure 10.137 Error Occurrence in Complementary PWM Mode, Recovery in Complementary PWM Mode**

1 to 10 are the same as in Figure 10.135 .

11. Set the multi-function timer pulse unit 2 output with the general I/O port.

12. Operation is restarted by TSTR.

13. The complementary PWM waveform is output on compare-match occurrence.

- (24) Operation when Error Occurs during Complementary PWM Mode Operation, and Operation is Restarted in Complementary PWM Mode

Figure 10.138 shows an explanatory diagram of the case where an error occurs in complementary PWM mode and operation is restarted in complementary PWM mode after re-setting (when operation is restarted using completely new cycle and duty settings).

**==> picture [415 x 126] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17<br>RESET TOCR TMDR TOER PFC TSTR Match Error  PFC TSTR TMDR TOER TOCR TMDR TOER PFC TSTR<br>(CPWM) (1) (MTU2) (1) occurs (PORT) (0) (normal) (0) (CPWM) (1) (MTU2) (1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.138 Error Occurrence in Complementary PWM Mode, Recovery in Complementary PWM Mode**

1 to 10 are the same as in Figure 10.135 .

11. Set normal mode and make new settings. (This module outputs a low-level signal.)

12. Disable channel 3 and 4 output with TOER.

13. Select the complementary PWM mode output level and cyclic output enabling/disabling with TOCR.

14. Set complementary PWM.

15. Enable channel 3 and 4 output with TOER.

16. Set the multi-function timer pulse unit 2 output with the general I/O port.

17. Operation is restarted by TSTR.

- (25) Operation when Error Occurs during Complementary PWM Mode Operation, and Operation is Restarted in Reset-Synchronized PWM Mode

Figure 10.139 shows an explanatory diagram of the case where an error occurs in complementary PWM mode and operation is restarted in reset-synchronized PWM mode.

**==> picture [415 x 127] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17<br>RESET TOCR TMDR TOER PFC TSTR Match Error  PFC TSTR TMDR TOER TOCR TMDR TOER PFC TSTR<br>(CPWM) (1) (MTU2) (1) occurs(PORT) (0) (normal) (0) (RPWM) (1) (MTU2) (1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.139 Error Occurrence in Complementary PWM Mode, Recovery in Reset-Synchronized PWM Mode**

- 1 to 10 are the same as in Figure 10.135 .

11. Set normal mode. (This module outputs a low-level signal.)

12. Disable channel 3 and 4 output with TOER.

13. Select the reset-synchronized PWM mode output level and cyclic output enabling/disabling with TOCR.

14. Set reset-synchronized PWM.

15. Enable channel 3 and 4 output with TOER.

16. Set the multi-function timer pulse unit 2 output with the general I/O port.

17. Operation is restarted by TSTR.

## (26) Operation when Error Occurs during Reset-Synchronized PWM Mode Operation, and Operation is Restarted in Normal Mode

Figure 10.140 shows an explanatory diagram of the case where an error occurs in reset-synchronized PWM mode and operation is restarted in normal mode after re-setting.

|MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TMDR<br>(normal)<br>12<br>TIOR<br>(1 init<br>0 out)<br>13<br>PFC<br>(MTU2)<br>14<br>TSTR<br>(1)|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||High|-Z|||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||High|-Z|||||||||||||||
||||||||||||||||||||
||||||||||||||||||||
||||High|-Z|||||||||||||||
||||||||||||||||||||

## **Figure 10.140 Error Occurrence in Reset-Synchronized PWM Mode, Recovery in Normal Mode**

1. After a reset, the module output is low and ports are in the high-impedance state.

2. Select the reset-synchronized PWM output level and cyclic output enabling/disabling with TOCR.

3. Set reset-synchronized PWM.

4. Enable channel 3 and 4 output with TOER.

5. Set the multi-function timer pulse unit 2 output with the general I/O port.

6. The count operation is started by TSTR.

7. The reset-synchronized PWM waveform is output on compare-match occurrence.

8. An error occurs.

9. Set port output with the general I/O port and output the inverse of the active level.

10. The count operation is stopped by TSTR. (This module outputs the same value as the reset-synchronized PWM output initial value.)

11. Set normal mode. (The positive phase output from this module is low, and negative phase output is high.)

12. Initialize the pins with TIOR.

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

## (27) Operation when Error Occurs during Reset-Synchronized PWM Mode Operation, and Operation is Restarted in PWM Mode 1

Figure 10.141 shows an explanatory diagram of the case where an error occurs in reset-synchronized PWM mode and operation is restarted in PWM mode 1 after re-setting.

**==> picture [406 x 138] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13 14<br>RESET TOCR TMDR TOER PFC TSTR Match Error  PFC TSTR TMDR TIOR PFC TSTR<br>(RPWM) (1) (MTU2) (1) occurs (PORT) (0) (PWM1) (1 init (MTU2) (1)<br>0 out)<br>MTU2 module output<br>TIOC3A<br>TIOC3B Not initialized (TIOC3B)<br>TIOC3D Not initialized (TIOC3D)<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.141 Error Occurrence in Reset-Synchronized PWM Mode, Recovery in PWM Mode 1**

## 1 to 10 are the same as in Figure 10.140 .

11. Set PWM mode 1. (The positive phase output from this module is low, and negative phase output is high.)

12. Initialize the pins with TIOR. (In PWM mode 1, the TIOC *B side is not initialized.)

13. Set the multi-function timer pulse unit 2 output with the general I/O port.

14. Operation is restarted by TSTR.

## (28) Operation when Error Occurs during Reset-Synchronized PWM Mode Operation, and Operation is Restarted in Complementary PWM Mode

Figure 10.142 shows an explanatory diagram of the case where an error occurs in reset-synchronized PWM mode and operation is restarted in complementary PWM mode after re-setting.

|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|1<br>RESET<br>2<br>TOCR<br>3<br>TMDR<br>(RPWM)<br>5<br>PFC<br>(MTU2)<br>4<br>TOER<br>(1)<br>6<br>TSTR<br>(1)<br>7<br>Match<br>8<br>Error<br>occurs<br>9<br>PFC<br>(PORT)<br>10<br>TSTR<br>(0)<br>11<br>TOER<br>(0)<br>12<br>TOCR<br>13<br>TMDR<br>(CPWM)<br>14<br>TOER<br>(1)<br>15<br>PFC<br>(MTU2)<br>16<br>TSTR<br>(1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE9<br>PE8<br>PE11<br>High-Z<br>High-Z<br>High-Z|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||
||||||||||||

**Figure 10.142 Error Occurrence in Reset-Synchronized PWM Mode, Recovery in Complementary PWM Mode**

- 1 to 10 are the same as in Figure 10.140 .

11. Disable channel 3 and 4 output with TOER.

12. Select the complementary PWM output level and cyclic output enabling/disabling with TOCR.

13. Set complementary PWM. (The cyclic output pin of this module outputs a low-level signal.)

14. Enable channel 3 and 4 output with TOER.

15. Set the multi-function timer pulse unit 2 output with the general I/O port.

16. Operation is restarted by TSTR.

## (29) Operation when Error Occurs during Reset-Synchronized PWM Mode Operation, and Operation is Restarted in Reset-Synchronized PWM Mode

Figure 10.143 shows an explanatory diagram of the case where an error occurs in reset-synchronized PWM mode and operation is restarted in reset-synchronized PWM mode after re-setting.

**==> picture [385 x 138] intentionally omitted <==**

**----- Start of picture text -----**<br>
1 2 3 4 5 6 7 8 9 10 11 12 13<br>RESET TOCR TMDR TOER PFC TSTR Match Error  PFC TSTR PFC TSTR Match<br>(RPWM) (1) (MTU2) (1) occurs (PORT) (0) (MTU2) (1)<br>MTU2 module output<br>TIOC3A<br>TIOC3B<br>TIOC3D<br>Port output<br>PE8 High-Z<br>PE9 High-Z<br>PE11 High-Z<br>**----- End of picture text -----**<br>

**Figure 10.143 Error Occurrence in Reset-Synchronized PWM Mode, Recovery in Reset-Synchronized PWM Mode**

- 1 to 10 are the same as in Figure 10.140 .

11. Set the multi-function timer pulse unit 2 output with the general I/O port.

12. Operation is restarted by TSTR.

13. The reset-synchronized PWM waveform is output on compare-match occurrence.
