/*
    __audioamp5_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__audioamp5_driver.h"
#include "__audioamp5_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __AUDIOAMP5_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _AUDIOAMP5_SHDWN_MUTE_OUTPUTS      = 0x00;
const uint8_t _AUDIOAMP5_PWRUP_UNMUTE_OUTPUTS    = 0x01;
const uint8_t _AUDIOAMP5_BD_MODE                 = 0x00;
const uint8_t _AUDIOAMP5_1SPW_MODE               = 0x01;
const uint8_t _AUDIOAMP5_GAIN_20DB               = 0x00;
const uint8_t _AUDIOAMP5_GAIN_26DB               = 0x01;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __AUDIOAMP5_DRV_SPI__

void audioamp5_spiDriverInit(T_AUDIOAMP5_P gpioObj, T_AUDIOAMP5_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __AUDIOAMP5_DRV_I2C__

void audioamp5_i2cDriverInit(T_AUDIOAMP5_P gpioObj, T_AUDIOAMP5_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __AUDIOAMP5_DRV_UART__

void audioamp5_uartDriverInit(T_AUDIOAMP5_P gpioObj, T_AUDIOAMP5_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

void audioamp5_gpioDriverInit(T_AUDIOAMP5_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

void audioamp5_enable( uint8_t state )
{
    if (state)
    {
        hal_gpio_csSet( 1 );
    }
    else
    {
        hal_gpio_csSet( 0 );
    }
}

void audioamp5_modeSelect( uint8_t state )
{
    if (state)
    {
        hal_gpio_rstSet( 1 );
    }
    else
    {
        hal_gpio_rstSet( 0 );
    }
}

void audioamp5_gainSelect( uint8_t state )
{
    if (state)
    {
        hal_gpio_pwmSet( 1 );
    }
    else
    {
        hal_gpio_pwmSet( 0 );
    }
}

void audioamp5_configUpdate( void )
{
    audioamp5_enable( _AUDIOAMP5_SHDWN_MUTE_OUTPUTS );
    Delay_1ms();
    audioamp5_enable( _AUDIOAMP5_PWRUP_UNMUTE_OUTPUTS );
}

/* -------------------------------------------------------------------------- */
/*
  __audioamp5_driver.c

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