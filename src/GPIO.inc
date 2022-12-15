.equ GPIO_OUTPUT_EN,  0x008     # Enable Output to selected pins 
.equ GPIO_OUTPUT_VAL, 0x00C     # Set Output Value 
.equ GPIO_OUTPUT_XOR, 0x040     # inverse logic on selected pins 
.equ GPIO_INPUT_EN,   0x04      # Set Input enable for selected pins 
.equ GPIO_INPUT_VAL,  0x00      # Read Input value of selected pins 
.equ GPIO_INPUT_PULUP, 0x10     # enable pull up  
 
.equ GPIO_2,         0x40000  # pin 2
.equ GPIO_4,         0x100000 # pin 4
.equ GPIO_7,         0x800000 # pin 7
.equ GPIO_8,         0x01     # pin 8


.equ GPIO_17,       0x800  # pin17
.equ GPIO_18,       0x1000 # pin18 
.equ GPIO_19,       0x2000 # pin19

.equ GPIO_RGB_PINS,   0x680000   # All 3 LED's bit offset  
.equ GPIO_RED_LED,    0x400000   # Red LED offset 
.equ GPIO_BLUE_LED,   0x200000   # Blue LED offset 
.equ GPIO_GREEN_LED,  0x080000   # Green LED offset

.equ OUTPUT, GPIO_GREEN_LED|GPIO_RED_LED      # only allow red and green LEDS
.equ INPUT,  GPIO_2