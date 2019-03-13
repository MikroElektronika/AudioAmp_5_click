![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Audio_Amp_5 Click

- **CIC Prefix**  : AUDIOAMP5
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Dec 2018.

---

### Software Support

We provide a library for the Audio_Amp_5 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2716/audio-amp-5-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library performs the audio control of the Audio Amp 5 Click board.
This library consists of the special commands for audio output control, for example to mute/turn on the outputs, 
to select the desired output gain or mode.
For more details check documentation.

Key functions :

- ``` void audioamp5_enable( uint8_t state ) ``` - Function performs a shutdown or power up action, and on that way selects outputs to be muted or activated.
- ``` void audioamp5_modeSelect( uint8_t state ) ``` - Function puts a device to the desired mode.
- ``` void audioamp5_gainSelect( uint8_t state ) ``` - Function performs a desired gain selection.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO interface on the desired mikrobus selection
  and performs a device init configuration.
- Application Task - (code snippet) - Checks the entered command and, if the command is valid,
  performs a device configuration which the entered command determines.
Note : After each command for device configuration, the command for configuration updating will be executed.
When BD Mode (0) is selected, the VIN supply voltage threshold is 7.5V.
When Low-Idle-Current 1SPW Mode is selected, the VIN supply voltage threshold is 3.4V.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2716/audio-amp-5-click) page.

Other mikroE Libraries used in the example:

- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
