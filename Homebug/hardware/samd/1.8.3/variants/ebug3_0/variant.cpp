/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number +  ZERO Board pin  |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital Low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          | A0               |  PA02  | FLASH_EN
 * | 1          | AREF             |  PA03  | VREFA
 * | 2          | A1               |  PB08  | GSM Power Off
 * | 3          | A2               |  PB09  | GSM Power On
 * | 4          | A3               |  PA04  | VREFB
 * | 5          | A4               |  PA05  | RX GSM SERCOM0.1
 * | 6          | ~8               |  PA06  | TX GSM SERCOM0.2
 * | 7          | ~9               |  PA07  | GSM Ring Indicator
 * | 8          | ~4               |  PA08  | RJ12 TX2 SERCOM2.0
 * | 9          | ~3               |  PA09  | RJ12 RX2 SERCOM2.1
 * | 10         | 1 <- TX          |  PA10  | Analog In
 * | 11         | 0 -> RX          |  PA11  | LED
 * | 12         | 4                |  PB10  | Expansion
 * | 13         | 3                |  PB11  | GSM Power Enable
 * | 14         | 1                |  PA12  | RJ12 TX1/I2C SDA SERCOM4.0
 * | 15         | ATN              |  PA13  | RJ12 RX1/I2C SCL SERCOM4.1
 * | 16         | 2                |  PA14  | Micro SD detect
 * | 17         | ~5               |  PA15  | USB ID
 * | 18         | ~11              |  PA16  | RS485 TX, I2C SDA, SERCOM1.0
 * | 19         | ~13              |  PA17  | RS485 RX, I2C SCL, SERCOM1.1
 * | 20         | ~10              |  PA18  | RS485 Enable
 * | 21         | ~12              |  PA19  | Relay
 * | 22         | ~6               |  PA20  | SPI MOSI - SERCOM3.2 - SD
 * | 23         | 7                |  PA21  | SPI CLK - SERCOM3.3 - SD
 * | 24         |                  |  PA22  | SPI MISO - SERCOM3.0 - SD
 * | 25         |                  |  PA23  | SPI SS - SERCOM3.1 - SD
 * | 26         |                  |  PB22  | SERCOM5.2 - Expansion
 * | 27         |                  |  PB23  | SERCOM5.3 - Expansion
 * | 28         |                  |  PA27  | Expansion
 * | 29         |                  |  PA28  | Expansion
 * | 30         | A5               |  PB02  | SERCOM5.0 - Expansion
 * | 31         |                  |  PB03  | SERCOM5.1 - Expansion
 *
 * | 32         |                  |  PA24  | USB-
 * | 33         |                  |  PA25  | USB+
*/

#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{

  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },         //0 LED, DAC
  { PORTA,  3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 },         //1 VREFA
  { PORTB,  8, PIO_ANALOG, (PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel2, PWM4_CH0, TC4_CH0, EXTERNAL_INT_8 },  //2 RS485 enable GPIO out
  { PORTB,  9, PIO_ANALOG, (PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel3, PWM4_CH1, TC4_CH1, EXTERNAL_INT_9 },  //3 GSM power on
  { PORTA,  4, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel4, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 },         //4 VREFB
  { PORTA,  5, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //5 SERCOM0.1
  { PORTA,  6, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //6 SERCOM0.2
  { PORTA,  7, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_7 },   //7 GSM power off
  { PORTA,  8, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //8 SERCOM2.0
  { PORTA,  9, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //9 SERCOM2.1
  { PORTA, 10, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel18, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },     //10 Analog in
  { PORTA, 11, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel19, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },     //11 Relay out
  { PORTB, 10, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 },    //12 gpio
  { PORTB, 11, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 },    //13 gpio
  { PORTA, 12, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //14 SERCOM4.0
  { PORTA, 13, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //15 SERCOM4.1
  { PORTA, 14, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14 },    //16 gpio
  { PORTA, 15, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_15 },            //17 gpio
  { PORTA, 16, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },   //18 SERCOM1.0
  { PORTA, 17, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },   //19 SERCOM1.1
  { PORTA, 18, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_NONE },          //20 none
  { PORTA, 19, PIO_TIMER_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, PWM0_CH3, TCC0_CH3, EXTERNAL_INT_NONE }, //21 gpio
  { PORTA, 20, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //22 SERCOM3.2
  { PORTA, 21, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //23 SERCOM3.3
  { PORTA, 22, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },   //24 SERCOM3.0
  { PORTA, 23, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },   //25 SERCOM3.1
  { PORTB, 22, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //26 SERCOM5.2
  { PORTB, 23, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //27 SERCOM5.3
  { PORTA, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 },    //28 gpio
  { PORTA, 28, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },         //29 USB host enable
  { PORTB,  2, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //30 SERCOM5.0
  { PORTB,  3, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  //31 SERCOM5.1
  
  // USB
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //32 USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, //33 USB/DP
  

} ;

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
    }
}

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart SerialGSM( &sercom0, PIN_SERIAL_GSM_RX, PIN_SERIAL_GSM_TX, PAD_SERIAL_GSM_RX, PAD_SERIAL_GSM_TX ) ;
Uart SerialRJ12A( &sercom4, PIN_SERIAL_RJ12A_RX, PIN_SERIAL_RJ12A_TX, PAD_SERIAL_RJ12A_RX, PAD_SERIAL_RJ12A_TX );
Uart SerialRJ12B( &sercom2, PIN_SERIAL_RJ12B_RX, PIN_SERIAL_RJ12B_TX, PAD_SERIAL_RJ12B_RX, PAD_SERIAL_RJ12B_TX );
Uart SerialRS485( &sercom1, PIN_SERIAL_RS485_RX, PIN_SERIAL_RS485_TX, PAD_SERIAL_RS485_RX, PAD_SERIAL_RS485_TX );


void SERCOM0_Handler()
{
  SerialGSM.IrqHandler();
}

void SERCOM2_Handler()
{
  SerialRJ12B.IrqHandler();
}

void SERCOM4_Handler()
{
  SerialRJ12A.IrqHandler();
}

void SERCOM1_Handler()
{
  SerialRS485.IrqHandler();
}

