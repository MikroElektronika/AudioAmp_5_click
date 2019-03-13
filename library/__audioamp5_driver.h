/*
    __audioamp5_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __audioamp5_driver.h
@brief    Audio_Amp_5 Driver
@mainpage Audio_Amp_5 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   AUDIOAMP5
@brief      Audio_Amp_5 Click Driver
@{

| Global Library Prefix | **AUDIOAMP5** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Dec 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _AUDIOAMP5_H_
#define _AUDIOAMP5_H_

/** 
 * @macro T_AUDIOAMP5_P
 * @brief Driver Abstract type 
 */
#define T_AUDIOAMP5_P    const uint8_t*

/** @defgroup AUDIOAMP5_COMPILE Compilation Config */              /** @{ */

//  #define   __AUDIOAMP5_DRV_SPI__                            /**<     @macro __AUDIOAMP5_DRV_SPI__  @brief SPI driver selector */
//  #define   __AUDIOAMP5_DRV_I2C__                            /**<     @macro __AUDIOAMP5_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __AUDIOAMP5_DRV_UART__                           /**<     @macro __AUDIOAMP5_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup AUDIOAMP5_VAR Variables */                           /** @{ */

extern const uint8_t _AUDIOAMP5_SHDWN_MUTE_OUTPUTS    ;
extern const uint8_t _AUDIOAMP5_PWRUP_UNMUTE_OUTPUTS  ;
extern const uint8_t _AUDIOAMP5_BD_MODE               ;
extern const uint8_t _AUDIOAMP5_1SPW_MODE             ;
extern const uint8_t _AUDIOAMP5_GAIN_20DB             ;
extern const uint8_t _AUDIOAMP5_GAIN_26DB             ;

                                                                       /** @} */
/** @defgroup AUDIOAMP5_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup AUDIOAMP5_INIT Driver Initialization */              /** @{ */

#ifdef   __AUDIOAMP5_DRV_SPI__
void audioamp5_spiDriverInit(T_AUDIOAMP5_P gpioObj, T_AUDIOAMP5_P spiObj);
#endif
#ifdef   __AUDIOAMP5_DRV_I2C__
void audioamp5_i2cDriverInit(T_AUDIOAMP5_P gpioObj, T_AUDIOAMP5_P i2cObj, uint8_t slave);
#endif
#ifdef   __AUDIOAMP5_DRV_UART__
void audioamp5_uartDriverInit(T_AUDIOAMP5_P gpioObj, T_AUDIOAMP5_P uartObj);
#endif

void audioamp5_gpioDriverInit(T_AUDIOAMP5_P gpioObj);
                                                                       /** @} */
/** @defgroup AUDIOAMP5_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Enable function
 *
 * @param[in] state  0 - Shutdown (Mute outputs), 1 - Power up (Unmute outputs)
 *
 * Function performs a shutdown or power up action, and on that way selects outputs to be muted or activated.
 */
void audioamp5_enable( uint8_t state );

/**
 * @brief Mode Selection function
 *
 * @param[in] state  0 - BD Mode, 1 - 1SPW Mode
 *
 * Function puts a device to the desired mode.
 */
void audioamp5_modeSelect( uint8_t state );

/**
 * @brief Gain Selection function
 *
 * @param[in] state  0 - 20dB, 1 - 26dB
 *
 * Function performs a desired gain selection.
 */
void audioamp5_gainSelect( uint8_t state );

/**
 * @brief Configuration Update function
 *
 * Function makes that desired configuration be updated.
 */
void audioamp5_configUpdate( void );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Audio_Amp_5_STM.c
    @example Click_Audio_Amp_5_TIVA.c
    @example Click_Audio_Amp_5_CEC.c
    @example Click_Audio_Amp_5_KINETIS.c
    @example Click_Audio_Amp_5_MSP.c
    @example Click_Audio_Amp_5_PIC.c
    @example Click_Audio_Amp_5_PIC32.c
    @example Click_Audio_Amp_5_DSPIC.c
    @example Click_Audio_Amp_5_AVR.c
    @example Click_Audio_Amp_5_FT90x.c
    @example Click_Audio_Amp_5_STM.mbas
    @example Click_Audio_Amp_5_TIVA.mbas
    @example Click_Audio_Amp_5_CEC.mbas
    @example Click_Audio_Amp_5_KINETIS.mbas
    @example Click_Audio_Amp_5_MSP.mbas
    @example Click_Audio_Amp_5_PIC.mbas
    @example Click_Audio_Amp_5_PIC32.mbas
    @example Click_Audio_Amp_5_DSPIC.mbas
    @example Click_Audio_Amp_5_AVR.mbas
    @example Click_Audio_Amp_5_FT90x.mbas
    @example Click_Audio_Amp_5_STM.mpas
    @example Click_Audio_Amp_5_TIVA.mpas
    @example Click_Audio_Amp_5_CEC.mpas
    @example Click_Audio_Amp_5_KINETIS.mpas
    @example Click_Audio_Amp_5_MSP.mpas
    @example Click_Audio_Amp_5_PIC.mpas
    @example Click_Audio_Amp_5_PIC32.mpas
    @example Click_Audio_Amp_5_DSPIC.mpas
    @example Click_Audio_Amp_5_AVR.mpas
    @example Click_Audio_Amp_5_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __audioamp5_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */