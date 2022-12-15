#include "gpio.h"
#include "uart.h"
#include "login.h"

int main()
{
    setupUART();
    setupGPIO();
    unsigned char in;
    unsigned char input[4];            //allow max of 4 characters per input
    unsigned int char_count = 0;
    unsigned int state = 0, button = 0, uflag = 0, pflag = 0;

    //Ensure LEDs are OFF
    setLED(GPIO_RED_LED, OFF);
    setLED(GPIO_GREEN_LED, OFF);
    userPrompt();
    while(1)
    {
        in = UART_read();
        button = !checkBot(GPIO_2);

        //make sure input is not empty
        if (in != '\0')         
        {
            switch (state)
            {
            //reading username
            case 0:
                if (char_count == 4)
                {
                    uflag = checkUser(input);
                    char_count = 0; 
                    passPrompt();
                    state++; break;
                }            
                else
                {
                    input[char_count] = in;
                    UART_write(in);
                    char_count++; break;
                }
            //reading password
            case 1:
                if (char_count == 4)
                {
                    pflag = checkPass(input);
                    char_count = 0;
                    state++; break;
                }
                else
                {
                    input[char_count] = in;
                    char_count++;
                    UART_write(in);
                    break;
                }
                break;
            //check if credentials were valid
            case 2:
                if (pflag&&uflag == 1) 
                {
                    success();
                    setLED(GPIO_RED_LED, OFF);
                    setLED(GPIO_GREEN_LED, ON);
                    pflag=0; uflag=0; state=0;       //reset flags and state to initial condition
                    break;
                }
                else 
                {
                    fail();
                    setLED(GPIO_GREEN_LED, OFF);
                    setLED(GPIO_RED_LED, ON);
                    pflag=0; uflag=0; state=0;       //reset flags and state to initial condition
                    break;
                }
                break;
            default:
                break;
            }
        }
        delay(100);
    }
return 0; 
}