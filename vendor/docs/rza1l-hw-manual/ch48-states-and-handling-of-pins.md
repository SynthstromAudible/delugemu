# 48. States and Handling of Pins

> Source: RZ/A1L Group, RZ/A1LU Group, RZ/A1LC Group User's Manual: Hardware (R01UH0437EJ0700 Rev.7.00, Sep 2024), PDF pages 2832–2840. Converted to Markdown; figures are omitted — consult the PDF for diagrams and timing charts.

This section describes pin states in each operating mode and how to handle pins.

## 48.1 Pin States

Table 48.1 shows the pin states in each operating mode.

As for the input/output functions, input buffers are listed on the upper column and output buffers on the lower column.

## **Table 48.1 Pin States**

|**Table 48.1**|**Pin States**|**Pin States**|**Pin States**||||||||
|---|---|---|---|---|---|---|---|---|---|---|
||**Pin Function**|||||**Pin State**|||||
|**Type**|**Pin Name**|||**Normal**<br>**State**<br>**(Other than**<br>**States at**<br>**Right)**|**Power-On**<br>**Reset*1**|**Pin State Retained*2**|||**Power-Down State**||
|||||||**EBUSKEEPE*3(Other**<br>**than States at Right)**||**Power-On**<br>**Reset*4**|**Deep**<br>**Standby**<br>**Mode**|**Software**<br>**Standby**<br>**Mode**|
|||||||**0**|**1**||||
|Clock|EXTAL*6|||I|I|I|||I/Z*5|I|
||XTAL*6|||O|O|O|||O/Z*5|O/Z*5|
||CKIO|Boot mode|0, 1|O/Z*7|O|O|O/Z*7||O/Z*7|O/Z*7|
||||Other than above|O/Z*7|O|O/Z*7|||O/Z*7|O/Z*7|
||AUDIO_CLK|||I|-|-|||I/Z*12|I|
||AUDIO_X1*6|||I|I|I|||Z|Z|
||AUDIO_X2*6|||O|O|O|||L|L|
||AUDIO_XOUT, AUDIO_XOUT2,<br>AUDIO_XOUT3|||O|-|O/Z*9*15|||O/Z*9*15|L/Z*9|
|System control|RES|||I|I|I|||I|I|
|Operating mode<br>control|MD_BOOT1, MD_BOOT0, MD_CLK,<br>MD_CLKS|||-|I|-|||-|-|
||BSCANP|||I|I|I|||I|I|
|Interrupts|NMI|||I|I|I|||I|I|
||IRQ0 (P6_7), IRQ1 (P2_9), IRQ2 (P2_7),<br>IRQ3 (P5_8, P7_3), IRQ4 (P5_9, P7_2),<br>IRQ5 (P2_2, P5_10, P7_9), IRQ6 (P7_6),<br>IRQ7 (P2_0)|||I|-|-|||I/Z*12|I|
||IRQ0 (other than P6_7),<br>IRQ1 (other than P2_9),<br>IRQ2 (other than P2_7),<br>IRQ3 (other than P5_8 and P7_3),<br>IRQ4 (other than P5_9 and P7_2),<br>IRQ5 (other than P2_2, P5_10, and P7_9),<br>IRQ6 (other than P7_6),<br>IRQ7 (other than P2_0)|||I|-|-|||Z|I|
|Bus state<br>controller|A25 to A21, A0|||O|-|O/Z*10|||O/Z*10|O/Z*10|
||A20 to A1|Boot mode|0|O|Z|O|O/Z*10||O/Z*10|O/Z*10|
||||Other than above|O|-|O/Z*10|||O/Z*10|O/Z*10|
||D0 to D7,<br>D11 to D15|Boot mode|0|I/Z|Z|I/Z||Z|Z|Z|
|||||O/Z|Z|O/Z|Z||Z|Z|
||||Other than above|I/Z|-|-|||Z|Z|
|||||O/Z|-|Z|||Z|Z|
||D8 (P5_8),<br>D9 (P5_9),<br>D10<br>(P5_10)|Boot mode|0|I/Z|Z|I/Z||Z|I/Z*12|I|
|||||O/Z|Z|O/Z|Z||Z|Z|
||||Other than above|I/Z|-|-|||I/Z*12|I|
|||||O/Z|-|Z|||Z|Z|
||D16 to D22, D24 to D31|||I/Z|-|-|||Z|Z|
|||||O/Z|-|Z|||Z|Z|
||D23 (P6_7)|||I/Z|-|-|||I/Z*12|I|
|||||O/Z|-|Z|||Z|Z|
||CS0<br>, RD|Boot mode|0|O|Z|O|H/Z*10||H/Z*10|H/Z*10|
||||Other than above|O|-|H/Z*10|||H/Z*10|H/Z*10|
||CS5<br> to CS1<br>, RD/WR<br>, BS<br>,<br>WE2<br>/DQMUL, WE1<br>/DQML<br>WE0<br>/DQMLL||WE3<br>/DQMUU/AH<br>,<br>U/WE<br>,|O|-|H/Z*10|||H/Z*10|H/Z*10|
||WAIT|||I|-|-|||Z|Z|

**Table 48.1 Pin States**

|**Table 48.1**|**Pin States**|**Pin States**|**Pin States**||||||||
|---|---|---|---|---|---|---|---|---|---|---|
||**Pin Function**|||||**Pin State**|||||
|**Type**|**Pin Name**|||**Normal**<br>**State**<br>**(Other than**<br>**States at**<br>**Right)**|**Power-On**<br>**Reset*1**|**Pin State Retained*2**|||**Power-Down State**||
|||||||**EBUSKEEPE*3(Other**<br>**than States at Right)**||**Power-On**<br>**Reset*4**|**Deep**<br>**Standby**<br>**Mode**|**Software**<br>**Standby**<br>**Mode**|
|||||||**0**|**1**||||
|Bus state<br>controller|RAS<br>, CAS<br>, CKE|||O|-|O/Z*11|||O/Z*11|O/Z*11|
|Direct memory<br>access controller|DREQ0|||I|-|-|||Z|Z|
||DACK0, TEND0|||O|-|O/Z*9|||O/Z*9|O/Z*9|
|Multi-function<br>timer pulse unit 2|TCLKA, TCLKB, TCLKC, TCLKD|||I|-|-|||Z|Z|
||TIOC0C (P2_2), TIOC1A (P2_7, P7_9),<br>TIOC3A (P6_7), TIOC4A (P5_8), TIOC4B<br>(P5_9), TIOC4C (P5_10)|||I|-|-|||I/Z*12|I|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||TIOC0A, TIOC0B, TIOC0C (other than P2_2),<br>TIOC0D, TIOC1A (other than P2_7 and P7_9),<br>TIOC1B, TIOC2A, TIOC2B,<br>TIOC3A (other than P6_7), TIOC3B, TIOC3C,<br>TIOC3D, TIOC4A (other than P5_8), TIOC4D|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
|Watchdog timer|WDTOVF|||O|-|H|||H|H|
|Realtime clock|RTC_X1*6|||I/Z*13|I|I/Z*13|||I/Z*13|I/Z*13|
||RTC_X2*6|||O/Z*13|O|O/Z*13|||O/Z*13|O/Z*13|
|Serial<br>communication<br>interface with<br>FIFO|TxD0 to TxD4|||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||RxD0 to RxD4|||I|-|-|||Z|Z|
||SCK0 (P2_9), SCK3 (P7_9), CTS2<br>(P7_6)|||I|-|-|||I/Z*12|I|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SCK0 (other than P2_9), SCK1, SCK2,<br>SCK3(other than P7_9), SCK4,<br>RTS0<br> to RTS2<br>,<br>CTS0<br>, CTS1<br>, CTS2<br>(other than P7_6)|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
|Serial<br>communications<br>interface|SCI_TXD0, SCI_TXD1|||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SCI_RXD0, SCI_RXD1|||I|-|-|||Z|Z|
||SCI_CTS0<br>/RTS0<br>(P7_3)|||I|-|-|||I/Z*12|I|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SCI_SCK0, SCI_SCK1, SCI_CTS1<br>/RTS1|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
|Renesas serial<br>peripheral<br>interface|RSPCK0 to RSPCK2, SSL00, SSL10, SSL20,<br>MOSI0 to MOSI2, MISO0 to MISO2|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
|SPI multi I/O bus<br>controller|SPBCLK_0,<br>SPBSSL_0|Boot mode|1|O/Z|-|-|O/Z*9||O/Z*9|O/Z*9|
||||Other than above|O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SPBIO00_0, SPBIO10_0<br>Boot mode|||I|-|-|||Z|Z|
|||Boot mode|1|O/Z|-|-|O/Z*9||O/Z*9|O/Z*9|
||||Other than above|O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SPBIO20_0, SPBIO30_0, SPBIO01_0,<br>SPBIO11_0, SPBIO21_0, SPBIO31_0|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
|I2C bus interface|RIIC0SCL to RIIC3SCL,<br>RIIC0SDA to RIIC3SDA|||I|-|-|||Z|Z|
|||||L/Z|-|Z|||Z|Z|
|Serial sound<br>interface|SSITxD0, SSITxD1, SSITxD3|||O|-|O/Z*9|||O/Z*9|O/Z*9|
||SSIRxD3 (P6_7)|||I|-|-|||I/Z*12|I|
||SSIRxD0, SSIRxD1,<br>SSIRxD3 (other than P6_7)|||I|-|-|||Z|Z|
||SSIDATA2|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SSISCK3 (P2_7), SSIWS1 (P7_9), SSIWS3<br>(P2_9)|||I|-|-|||I/Z*12|I|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SSISCK0 to SSISCK2, SSISCK3 (other than<br>P2_7), SSIWS0, SSIWS1 (other than P7_9),<br>SSIWS2, SSIWS3 (other than P2_9)|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
|Media local<br>bus*16|MLB_CLK|||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||MLB_DAT, MLB_SIG|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|

**Table 48.1 Pin States**

|**Table 48.1**|**Pin States**||||||||
|---|---|---|---|---|---|---|---|---|
||**Pin Function**|||**Pin State**|||||
|**Type**|**Pin Name**|**Normal**<br>**State**<br>**(Other than**<br>**States at**<br>**Right)**|**Power-On**<br>**Reset*1**|**Pin State Retained*2**|||**Power-Down State**||
|||||**EBUSKEEPE*3(Other**<br>**than States at Right)**||**Power-On**<br>**Reset*4**|**Deep**<br>**Standby**<br>**Mode**|**Software**<br>**Standby**<br>**Mode**|
|||||**0**|**1**||||
|CAN interface|CAN0TX, CAN1TX|O|-|O/Z*9|||O/Z*9|O/Z*9|
||CAN0RX (P2_9, P5_8, P7_2),<br>CAN1RX (P2_2)|I|-|-|||I/Z*12|I|
||CAN1RX (other than P2_2), CAN_CLK|I|-|-|||Z|Z|
|IEBusTM<br>controller*16|IETxD|O|-|O/Z*9|||O/Z*9|O/Z*9|
||IERxD (P5_10)|I|-|-|||I/Z*12|I|
||IERxD (other than P5_10)|I|-|-|||Z|Z|
|Renesas SPDIF<br>interface|SPDIF_OUT|O|-|O/Z*9|||O/Z*9|O/Z*9|
||SPDIF_IN (P2_0)|I|-|-|||I/Z*12|I|
||SPDIF_IN (other than P2_0)|I|-|-|||Z|Z|
|LIN interface*16|RLIN30TX|O|-|O/Z*9|||O/Z*9|O/Z*9|
||RLIN30RX (P2_0, P6_7)|I|-|-|||I/Z*12|I|
|Ethernet<br>controller,<br>EthernetAVB*17|ET_TXER, ET_TXEN, ET_TXD3 to ET_TXD0,<br>ET_MDC|O|-|O/Z*9|||O/Z*9|O/Z*9|
||ET_TXCLK, ET_RXCLK, ET_RXDV,<br>ET_RXER, ET_RXD3 to ET_RXD0, ET_CRS,<br>ET_COL|I|-|-|||Z|Z|
||ET_MDIO|I|-|-|||Z|Z|
|||O|-|O/Z*9|||O/Z*9|O/Z*9|
|EthernetAVB*17|AVB_CAPTURE|I|-|-|||Z|Z|
||AVB_GPTP_EXTERN|I|-|-|||Z|Z|
|A/D converter|AN7 to AN0|I|-|-|||Z|Z|
||ADTRG|I|-|-|||Z|Z|
|USB2.0 host/<br>function module|DP0, DP1, DM0, DM1|I/Z|Z|I/Z|||Z|I/Z|
|||O/Z|Z|O/Z|||Z|O/Z|
||VBUS0, VBUS1|I|I|I|||I|I|
||REFRIN|I|I|I|||I|I|
||USB_X1*6|I|I|I|||Z|Z|
||USB_X2*6|O|O|O|||L|L|
|Video display<br>controller 5|LCD0_CLK|O|-|O/Z*9|||O/Z*9|O/Z*9|
||LCD0_DATA0 to LCD0_DATA23,<br>LCD0_TCON0 to LCD0_TCON6|O|-|O/Z*9|||O/Z*9|O/Z*9|
||LCD0_EXTCLK|I|-|-|||Z|Z|
||DV0_DATA6 (P7_2), DV0_DATA7 (P7_3),<br>DV0_VSYNC (P7_9)|I|-|-|||I/Z*12|I|
||DV0_CLK, DV0_DATA0 to DV0_DATA5,<br>DV0_DATA6 (other than P7_2),<br>DV0_DATA7 (other than P7_3),<br>DV0_DATA8 to DV0_DATA23, DV0_HSYNC|I|-|-|||Z|Z|
|Capture engine<br>unit|VIO_CLK, VIO_VD, VIO_HD, VIO_FLD,<br>VIO_D0 to VIO_D7|I|-|-|||Z|Z|

## **Table 48.1 Pin States**

|**Table 48.1**|**Pin States**|**Pin States**|**Pin States**||||||||
|---|---|---|---|---|---|---|---|---|---|---|
||**Pin Function**|||||**Pin State**|||||
|**Type**|**Pin Name**|||**Normal**<br>**State**<br>**(Other than**<br>**States at**<br>**Right)**|**Power-On**<br>**Reset*1**|**Pin State Retained*2**|||**Power-Down State**||
|||||||**EBUSKEEPE*3(Other**<br>**than States at Right)**||**Power-On**<br>**Reset*4**|**Deep**<br>**Standby**<br>**Mode**|**Software**<br>**Standby**<br>**Mode**|
|||||||**0**|**1**||||
|SD host interface|SD_CLK_0<br>(P3_3)|Boot mode|2|O|-|-|O/Z*9||O/Z*9|O/Z*9|
||||Other than above|O|-|O/Z*9|||O/Z*9|O/Z*9|
||SD_CLK_0 (other than P3_3)|||O|-|O/Z*9|||O/Z*9|O/Z*9|
||SD_CMD_0 (P3_2), SD_D0_0 (P3_4),<br>SD_D1_0 (P3_5), SD_D2_0 (P3_0), SD_D3_0<br>(P3_1)<br>Boot mode<br>2<br>Other than above|||I|-|-|||Z|Z|
|||Boot mode|2|O|-|-|O/Z*9||O/Z*9|O/Z*9|
||||Other than above|O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SD_CMD_0 (other than P3_2), SD_D0_0<br>(other than P3_4), SD_D1_0 (other than<br>P3_5), SD_D2_0 (other than P3_0), SD_D3_0<br>(other than P3_1)|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SD_CLK_1|||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SD_D0_1 (P7_3), SD_D1_1 (P7_2),<br>SD_D3_1 (P7_6)|||I|-|-|||I/Z*12|I|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SD_CMD_1, SD_D2_1|||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||SD_CD_0, SD_CD_1, SD_WP_0, SD_WP_1|||I|-|-|||Z|Z|
|MMC host<br>interface|MMC_CLK|Boot mode|3|O|-|-|O/Z*9||O/Z*9|O/Z*9|
||||Other than above|O|-|O/Z*9|||O/Z*9|O/Z*9|
||MMC_D0 (P7_3), MMC_D1 (P7_2), MMC_D3<br>(P7_6)<br>Boot mode<br>3<br>Other than above|||I|-|-|||I/Z*12|I|
|||Boot mode|3|O/Z|-|-|O/Z*9||O/Z*9|O/Z*9|
||||Other than above|O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||MMC_CMD,|MMC_D2||I|-|-|||Z|Z|
|||Boot mode|3|O/Z|-|-|O/Z*9||O/Z*9|O/Z*9|
||||Other than above|O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||MMC_D4 to|MMC_D7||I|-|-|||Z|Z|
|||||O/Z|-|O/Z*9|||O/Z*9|O/Z*9|
||MMC_CD|||I|-|-|||Z|Z|
|Ports|JP0_0, JP0_1, P0_0 to P0_3|||I/Z|-|-|||Z|Z|
||P1_8 to P1_15|||I/Z|Z|Z|||Z|Z|
||P1_0 to P1_7|||I/Z*8|Z|Z|||Z|Z|
|||||L/Z|Z|Z|||Z|Z|
||P2_0, P2_2, P2_7, P2_9, P5_8, P5_9, P5_10,<br>P6_7, P7_2, P7_3, P7_6, P7_9|||I|Z|Z|||I/Z*12|I|
|||||O/Z|Z|O/Z*9|||O/Z*9|O/Z*9|
||Other than above|||I/Z*8|Z|Z|||Z|Z|
|||||O/Z|Z|O/Z*9|||O/Z*9|O/Z*9|
|Debugger<br>interface|TDI|||I|I|I|||Z|I|
||TDO|||O/Z*14|O/Z*14|O/Z*14|||Z|O/Z*14|
||TMS/SWDIO|||I|I|I|||Z|I|
|||||O/Z|O/Z|O/Z|||Z|O/Z|
||TCK/SWDCLK|||I|I|I|||Z|I|
||TRST|||I|I|I|||Z|I|
||TRACEDATA3 to TRACEDATA0, TRACECLK,<br>TRACECTL|||O|-|O/Z*9|||O/Z*9|O/Z*9|

- [Legend]

I: Input

- O: Output

- H: High-level output

- L: Low-level output

- Z: High-impedance

- -: Condition under which the pin function is not selectable

|Note|1. Indicates the power-on reset by low-level input to the RES<br>pin. The pin states after a power-on reset by the watchdog timer|
|---|---|
||overflow is the same as the initial pin states at normal operation (see section 41, Ports).|
|Note|2. After the chip has been released from deep standby mode by the input on pins for canceling the standby mode such as NMI or|
||by the realtime clock alarm interrupt, the pins retain the state until the IOKEEP bit in the deep standby cancel source flag register|
||(DSFR) is cleared (see section 42, Power-Down Modes).|
|Note|3. The EBUSKEEPE bit in deep standby control register (DSTCR) (see section 42, Power-Down Modes).|
|Note|4. This LSI enters the power-on reset state for a certain period after recovery from deep standby control mode (see section 42,|
||Power-Down Modes).|
|Note|5. Depends on the setting of the RCKSEL bit in the realtime clock control register 5 (RCR5) (see section 13, Realtime Clock).|
|Note|6. When pins for the connection with a crystal resonator are not used, the input pins (EXTAL, RTC_X1, AUDIO_X1, and USB_X1)|
||must be fixed (pull-up/down resistor, power supply, or ground.) and the output pins (XTAL, RTC_X2, AUDIO_X2, and USB_X2)|
||must be open.|
|Note|7. Depends on the setting of the CKOEN bit in the frequency control register (FRQCR) of the clock pulse generator (see section 6,|
||Clock Pulse Generator).|
|Note|8. Depends on the setting of the PIPCnm bit in the port IP control register (PIPCn) of the general I/O ports.|
|Note|9. Depends on the setting of the HIZ bit in the standby control register 2 (STBCR2) (see section 42, Power-Down Modes).|
|Note|10.Depends on the setting of the HIZMEM bit in the common control register (CMNCR) of the bus state controller (see section 8,|
||Bus State Controller).|
|Note|11.Depends on the setting of the HIZCNT bit in the common control register (CMNCR) of the bus state controller (see section 8,|
||Bus State Controller).|
|Note|12.Depends on the setting of the corresponding bit in the deep standby cancel source select register (DSSSR) and the RCKSEL bit|
||in the realtime clock control register 5 (RCR5) (see section 42, Power-Down Modes).|
|Note|13.Depends on the setting of the RTCEN bit in the realtime clock control register 2 (RCR2) and the RCKSEL bit in the realtime clock|
||control register 5 (RCR5) (see section 13, Realtime Clock).|
|Note|14.O in serial wire debug (SWD) mode. In modes other than serial wire debug (SWD), Z when the TAP controller is neither the|
||Shift-DR nor Shift-IR state.|
|Note|15.When this is an output, the output is fixed to either the High or Low level. There is no oscillation.|
|Note|16.RZ/A1L only|
|Note|17.RZ/A1LU only|

## 48.2 Treatment of Unused Pins

How unused pins are to be handled is indicated below.

## **Table 48.2 Handling of Unused Pins (Except for Debugger Interface Pins)**

|**Pin Name**|**Handling**|
|---|---|
|NMI|Fix this pin at a high level (pull up or connect to a power supply).|
|DP1, DP0, DM1, DM0, VBUS1, VBUS0|- Connect these pins to USBDPVss (QFP package).|
||- Connect them to Vss (BGA package).|
|REFRIN|Connect this pin, via a 5.6 k20resistor, to USBAPVcc.|
|1.18-V power dedicated to the USB (USBAVcc, USBDVcc,|Supply power at 1.18 V.|
|USBUVcc)|Note: Products in BGA packages do not have pins USBDVcc and|
||USBUVcc.|
|3.3-V power dedicated to the USB (USBAPVcc, USBDPVcc)|Supply power at 3.3 V.|
||Note: Products in BGA packages do not have the USBDPVcc pin.|
|Dedicated USB ground (USBAPVss, USBDPVss, USBAVss,|Connect to ground.|
|USBDVss, USBUVss)|Note: Products in BGA packages do not have the dedicated USB|
||ground pins.|
|AVref|Connect this pin to AVcc.|
|Dedicated A/D power (AVcc)|Supply power at 3.3 V.|
|Dedicated A/D ground (AVss)|Connect to ground.|
|Dedicated input pins other than those listed above|Fix the level on the pins (pull them up or down, or connect them to|
||the power supply or ground level)*2.|
|Input/output pins other than those listed above|Make the input-pin settings and then fix the level (pull them up or|
||down)*2; alternatively, make the output-pin settings and leave the|
||pins open-circuit.|
|Dedicated output pins|Open-circuit|

Note 1. We recommend that the values of pull-up or pull-down resistors are in the range from 4.7 k to 100 k.

Note 2. By setting the ports in accord with section 41, Ports, setting of a fixed level can be made unnecessary for some pins. For details, see section 41.3.12, Port Input Buffer Control Register (PIBCn/JPIBC0).

## **Table 48.3 Handling of Debugger Interface Pins (when Emulator is not Used)**

||**Pin**<br>**Handling**|
|---|---|
||BSCANP<br>Fix this pin at a low level (pull down or connect to the ground<br>level).|
||TRST<br>*3<br>Fix this pin at a low level (pull down or connect to the ground<br>level).<br>Or connect to another pin which operates in the same manner as<br>the RES<br>pin|
||TCK, TMS, TDI<br>Fix the level on the pins (pull them up or down, or connect them to<br>the power supply or ground level).|
||TDO<br>Open-circuit|

- Note 1. When using the emulator, handle these pins as described in the manual for the emulator.

Note 2. We recommend that the values of pull-up or pull-down resistors are in the range from 4.7 k to 100 k.

Note 3. If the pin is not fixed to the low level, whether an emulator is or is not in use, the specifications in Table 43.13, Reset Signal Setting, or RES input rise time (tRSr) or RES negating hold time (tRSNH) in Table 47.6, Control Signal Timing, must be satisfied.

## 48.3 Handling of Pins in Deep Standby Mode

How pins are to be handled in deep standby mode is indicated below. For the states of pins in deep standby mode, refer to the corresponding items under section 48.1, Pin States . Handling of unused pins as described under section 48.2, Treatment of Unused Pins , also applies in deep standby mode.

## **Table 48.4 Handling of Pins in Deep Standby Mode**

|**Table 48.4**<br>**Handling of Pins in Deep Standby Mode**||
|---|---|
|**Pin**|**Handling**|
|1.2-V power (Vcc, USBDVcc, USBUVcc, USBAVcc, PLLVcc)|Supply power at 1.2 V.|
||Note: Products in BGA packages do not have pins USBDVcc and|
||USBUVcc.|
|3.3-V power (PVcc, AVcc, USBDPVcc, USBAPVcc)|Supply power at 3.3 V.|
||Note: Products in BGA packages do not have the USBDPVcc pin.|
|Ground (Vss, USBDVss, USBUVss, USBAVss, AVss USBDPVss,|Connect to ground.|
|USBAPVss)|Note: Products in BGA packages do not have the USBDVss,|
||USBAVss, USBUVss, USBDPVss, and USBAPVss pins.|
|VBUS1, VBUS0|Fix the level on this pin (pull it up or down, or connect it to the|
||power supply or ground level) or open circuit. However, note that|
||current as indicated in table 45.2, DC Characteristics (2) [Current|
||Consumption] will be drawn by the pin fixed to the high level.|
|REFRIN|Connect this pin to USBAPVss via 5.6 k± 1resistor (QFP|
||package).|
||Connect this pin to Vss via 5.6 kΩ ± 1% resistor (BGA package).|
|DP1, DP0, DM1, DM0|Fix the level on the pins (pull them up or down, or connect them to|
||the power supply or ground level) or open circuit.|
|EXTAL, RTC_X1, AUDIO_X1, USB_X1|Connect the pins to the crystal oscillator or the clock-input signal,|
||or to a fixed level (pull them up or down, or connect them to the|
||power supply or ground level)|
|XTAL, RTC_X2, AUDIO_X2, USB_X2|Connect the pins to the crystal oscillator or open circuit.|
|Dedicated input pins other than those listed above|Fix the level on the pins (pull them up or down, or connect them to|
||the power supply or ground level).|
|Input/output pins (other than those listed above) in the input state|Fix the level on the pins (pull them up or down).|
|Input/output pins (other than those listed above) in the high-|Fix the level on the pins (pull them up or down) or open circuit.|
|impedance state||
|Input/output pins (other than those listed above) in the output state|Open-circuit|
|Dedicated output pins other than those listed above|Open-circuit|

Note: We recommend that the values of pull-up or pull-down resistors are in the range from 4.7 k to 100 k.

## 48.4 Recommended Combination of Bypass Capacitor

Mount a multilayer ceramic capacitor between a pair of the power supply pins as a bypass capacitor. These capacitors must be placed as close as the power supply pins of the LSI. The capacitance of the capacitors should be used 0.1  F to 0.33  F (recommended values). For details of the capacitor related to the crystal resonator, see section 6, Clock Pulse Generator .

Figure 48.1 and Figure 48.2 are examples of the externally allocated capacitor in the products in 208-pin and 176-pin QFP packages, respectively.

**==> picture [472 x 414] intentionally omitted <==**

**----- Start of picture text -----**<br>
157 P3_15<br>158 P2_6 AVref 104<br>159 P2_7 AVss 103<br>160 P2_8 AVcc 102<br>161 P2_9 P1_15 101<br>162 Vss P1_14 100<br>163 USB_X1 P1_13 99<br>164 USB_X2 P1_12 98<br>165 USBDPVcc P1_11 97<br>166 USBDPVss P1_10 96<br>167 DM1 P1_9 95<br>168 DP1 P1_8 94<br>169 VBUS1 PVcc 93<br>170 USBDVcc RES 92<br>171 USBDVss Vss 91<br>172 USBDPVcc NMI 90<br>173 USBDPVss Vss 89<br>174 DM0 Vss 88<br>175 DP0 XTAL 87<br>176 VBUS0 EXTAL 86<br>177 USBDVcc PLLVcc 85<br>178 USBDVss RTC_X2 84<br>179 REFRIN RTC_X1 83<br>180 USBAPVss P0_3 82<br>181 USBAPVcc 208-pin QFP P0_2 81<br>182 USBAVcc P0_1 80<br>183 USBAVss P0_0 79<br>184 USBUVcc PVcc 78<br>185 USBUVss Vss 77<br>186 Vss P2_3 76<br>187 Vss Top view P2_2 75<br>188 P4_0 Vcc 74<br>189 P4_1 P9_1 73<br>190 P4_2 P9_0 72<br>191 P4_3 P8_15 71<br>192 P8_0 P8_14 70<br>193 Vss P2_1 69<br>194 P8_1 P2_0 68<br>195 PVcc PVcc 67<br>196 P4_4 P8_13 66<br>197 P4_5 Vss 65<br>198 P8_2 P8_12 64<br>199 P8_3 P7_11 63<br>200 P8_4 P7_10 62<br>201 P8_5 P7_9 61<br>202 P4_6 P7_8 60<br>203 Vss P7_7 59<br>204 P4_7 PVcc 58<br>205 P5_0 P7_6 57<br>206 PVcc P7_5 56<br>207 P5_1 P7_4 55<br>208 P5_2 Vss 54<br>P7_3 53<br>156 155 154 153 152 151 150 149 148 147 146 145 144 143 142 141 140 139 138 137 136 135 134 133 132 131 130 129 128 127 126 125 124 123 122 121 120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105<br>P1_7 P1_6 P1_5 P1_4 P1_3 P1_2 P1_1 P1_0 P3_14 PVcc P3_13 Vss P3_12 Vcc P3_11 P3_10 Vss P3_9 P3_8 P9_5 PVcc P9_4 Vss P3_7 P3_6 P3_5 PVcc P9_3 Vss P9_2 P3_4 PVcc P3_3 Vss P3_2 Vcc P3_1 P3_0 Vss TCK TMS JP0_0 JP0_1TRST P2_5 Vcc P2_4 Vss AUDIO_X2 AUDIO_X1 PVcc BSCANP<br>1 P5_3 2 P5_4 3 P5_5 4 P5_6 5 P5_7 6 P5_8 7 Vcc 8 P5_9 9 Vss P5_1010 11PVcc P5_1112 P5_1213 P5_1314 P5_1415 P5_1516 P6_017 18Vss P6_119 P6_220 21Vcc P6_322 23Vss P6_424 25PVcc P6_526 P8_627 P8_728 P8_829 P8_930 P6_631 P6_732 P6_833 34Vss P8_1035 36PVcc P8_1137 P6_938 39Vss P6_1040 P6_1141 42Vcc P6_1243 Vss44 CKIO45 P6_1346 PVcc47 P6_1448 P6_1549 P7_050 P7_151 P7_252<br>**----- End of picture text -----**<br>

**Figure 48.1 Example of Externally Allocated Capacitors in the Products in 208-Pin QFP Packages**

**==> picture [449 x 395] intentionally omitted <==**

**----- Start of picture text -----**<br>
133 P3_15 AVref 88<br>134 P2_6 AVss 87<br>135 P2_7 AVcc 86<br>136 P2_8 P1_15 85<br>137 P2_9 P1_14 84<br>138 Vss P1_13 83<br>139 USB_X1 P1_12 82<br>140 USB_X2 P1_11 81<br>141 USBDPVcc P1_10 80<br>142 USBDPVss P1_9 79<br>143 DM1 P1_8 78<br>144 DP1 PVcc 77<br>145 VBUS1 RES 76<br>146 USBDVcc Vss 75<br>147 USBDVss NMI 74<br>148 USBDPVcc Vss 73<br>149 USBDPVss Vss 72<br>150 DM0 XTAL 71<br>151 DP0 EXTAL 70<br>152 VBUS0 PLLVcc 69<br>153 USBDVcc RTC_X2 68<br>154 USBDVss RTC_X1 67<br>156155 REFRINUSBAPVss 176-pin QFP P0_3P0_2 6566<br>157 USBAPVcc P0_1 64<br>158 USBAVcc P0_0 63<br>159 USBAVss PVcc 62<br>160 USBUVcc Vss 61<br>161 USBUVss Top view P2_3 60<br>162 Vss P2_2 59<br>163 Vss Vcc 58<br>164 P4_0 P2_1 57<br>165 P4_1 P2_0 56<br>166 P4_2 P7_11 55<br>167 P4_3 P7_10 54<br>168 P4_4 P7_9 53<br>169 P4_5 P7_8 52<br>170 P4_6 P7_7 51<br>171 Vss PVcc 50<br>172 P4_7 P7_6 49<br>173 P5_0 P7_5 48<br>174 PVcc P7_4 47<br>175 P5_1 Vss 46<br>176 P5_2 P7_3 45<br>132 131 130 129 128 127 126 125 124 123 122 121 120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105 104 103 102 101 100 99 98 97 96 95 94 93 92 91 90 89<br>P1_7 P1_6 P1_5 P1_4 P1_3 P1_2 P1_1 P1_0 P3_14 PVcc P3_13 Vss P3_12 Vcc P3_11 P3_10 Vss P3_9 P3_8 P3_7 P3_6 P3_5 P3_4 PVcc P3_3 Vss P3_2 Vcc P3_1 P3_0 Vss TCK TMS JP0_0 JP0_1 TRST P2_5 Vcc P2_4 Vss AUDIO_X2 AUDIO_X1 PVcc BSCANP<br>1 P5_3 2 P5_4 3 P5_5 4 P5_6 5 P5_7 6 P5_8 7 Vcc 8 P5_9 9 Vss P5_1010 11PVcc P5_1112 P5_1213 P5_1314 P5_1415 P5_1516 P6_017 18Vss P6_119 P6_220 21Vcc P6_322 23Vss P6_424 25PVcc P6_526 P6_627 P6_728 P6_829 P6_930 31Vss P6_1032 P6_1133 34Vcc P6_1235 36Vss CKIO37 P6_1338 39PVcc P6_1440 P6_1541 P7_042 P7_143 P7_244<br>**----- End of picture text -----**<br>

**Figure 48.2 Example of Externally Allocated Capacitors in the Products in 176-Pin QFP Packages**
