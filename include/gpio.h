#define DELAY           200 
#define ON              0x01 
#define OFF             0x00 

//Built-in LEDs offsets
#define GPIO_RED_LED         0x400000   //Built-in red LED
#define GPIO_GREEN_LED       0x080000   //Built-in green LED

//GPIO pins offsets
#define GPIO_2             0x40000         //Pin 2
#define GPIO_4             0x100000        //Pin 4
#define GPIO_7             0x800000        //Pin 7
#define GPIO_8             0x01            //Pin 8


void setupGPIO();
/*
    Sets the state of a given GPIO address 
    @return 0 if there was an error, 1 otherwise
    @param adr Offset of the GPIO pin
    @param state Desired state for the GPIO pin (1 or 0)
*/
int setLED(int adr, int state);
/*
    Delays the program by given time
    @param ms Amount of time in milliseconds
*/
void delay(int ms);
/*
    Checks the state of a given GPIO address 
    @return The state of the pin
    @param adr Offset of the GPIO pin
*/
int checkBot(int adr);
