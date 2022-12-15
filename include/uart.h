void setupUART(); 
/*
    Reads one character from the UART 
    @returns The character that was read
*/
unsigned char UART_read();
/*
    Writes one character to the UART
    @param output Character to write
*/
void UART_write(unsigned char output);