/*
Example for Audio_Amp_5 Click

    Date          : Dec 2018.
    Author        : Nemanja Medakovic

Test configuration TIVA :
    
    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO interface on the desired mikrobus selection
  and performs a device init configuration.
- Application Task - (code snippet) - Checks the entered command and, if the command is valid,
  performs a device configuration which the entered command determines.
Note : After each command for device configuration, the command for configuration updating will be executed.
When BD Mode (0) is selected, the VIN supply voltage threshold is 7.5V.
When Low-Idle-Current 1SPW Mode is selected, the VIN supply voltage threshold is 3.4V.

*/

#include "Click_Audio_Amp_5_types.h"
#include "Click_Audio_Amp_5_config.h"

uint8_t rxDat;

const uint8_t UART_RX_NOT_READY = 0;

void writeLegend()
{
    mikrobus_logWrite( "", _LOG_LINE );
    mikrobus_logWrite( "** m  - Mutes the outputs **", _LOG_LINE );
    mikrobus_logWrite( "** e  - Turns on the outputs **", _LOG_LINE );
    mikrobus_logWrite( "** 0  - BD Mode selection **", _LOG_LINE );
    mikrobus_logWrite( "** 1  - 1SPW Mode selection **", _LOG_LINE );
    mikrobus_logWrite( "** -  - 20dB gain selection **", _LOG_LINE );
    mikrobus_logWrite( "** +  - 26dB gain selection **", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    mikrobus_logWrite( "*** Initializing... ***", _LOG_LINE );

    Delay_ms( 200 );
}

void applicationInit()
{
    audioamp5_gpioDriverInit( (T_AUDIOAMP5_P)&_MIKROBUS1_GPIO );
    Delay_ms( 100 );
    
    audioamp5_enable( _AUDIOAMP5_PWRUP_UNMUTE_OUTPUTS );
    audioamp5_gainSelect( _AUDIOAMP5_GAIN_20DB );
    audioamp5_modeSelect( _AUDIOAMP5_BD_MODE );
    
    mikrobus_logWrite( "** Audio Amp 5 is initialized **", _LOG_LINE );
    Delay_ms( 500 );
    writeLegend();
}

void applicationTask()
{
    rxDat = UART_Rdy_Ptr();

    if (rxDat != UART_RX_NOT_READY)
    {
        rxDat = UART_Rd_Ptr();
        
        switch (rxDat)
        {
            case 'm' :
            {
                audioamp5_enable( _AUDIOAMP5_SHDWN_MUTE_OUTPUTS );
                mikrobus_logWrite( "** Outputs are muted **", _LOG_LINE );
            break;
            }
            case 'e' :
            {
                audioamp5_enable( _AUDIOAMP5_PWRUP_UNMUTE_OUTPUTS );
                mikrobus_logWrite( "** Outputs are enabled **", _LOG_LINE );
            break;
            }
            case '0' :
            {
                audioamp5_modeSelect( _AUDIOAMP5_BD_MODE );
                audioamp5_configUpdate();
                mikrobus_logWrite( "** BD Mode is selected **", _LOG_LINE );
            break;
            }
            case '1' :
            {
                audioamp5_modeSelect( _AUDIOAMP5_1SPW_MODE );
                audioamp5_configUpdate();
                mikrobus_logWrite( "** Low-Idle-Current 1SPW Mode is selected **", _LOG_LINE );
            break;
            }
            case '-' :
            {
                audioamp5_gainSelect( _AUDIOAMP5_GAIN_20DB );
                audioamp5_configUpdate();
                mikrobus_logWrite( "** Gain value is 20dB **", _LOG_LINE );
            break;
            }
            case '+' :
            {
                audioamp5_gainSelect( _AUDIOAMP5_GAIN_26DB );
                audioamp5_configUpdate();
                mikrobus_logWrite( "** Gain value is 26dB **", _LOG_LINE );
            break;
            }
            default :
            {
                writeLegend();
            break;
            }
        }
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
