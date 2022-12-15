#include "login.h"
#include "uart.h"

unsigned char user[] = "user";
unsigned char password[] = "pass";
unsigned char error[] = "CHARACTER LENGTH EXCEEDED\n";
unsigned char user_prompt[] = "\nPlease enter username: ";
unsigned char pass_prompt[] = "\nPlease enter password: ";
unsigned char success_s[] = "\nSuccessful login\n";
unsigned char fail_s[] = "\nFailed to login\n";

/*
    Checks user input 
    @return 1 if user matches the one in file, 0 otherwise
    @param input string to be checked
*/
int checkUser(unsigned char input[])
{
    return checkString(input, user);
}

/*
    Checks password input 
    @return 1 if user matches the one in file, 0 otherwise
    @param input string to be checked
*/
int checkPass(unsigned char input[])
{
    return checkString(input, password);
}

//will announce that max of # characters was exceeded
void lengthError()
{
    for (int i = 0; i < 25; i++)
    {
        UART_write(error[i]);
    }
}

//Prompts the user to enter username
void userPrompt()
{
    for (int i = 0; i < 25; i++)
    {
        UART_write(user_prompt[i]);
    }
}

//Prompts the user to enter password
void passPrompt()
{
    for (int i = 0; i < 27; i++)
    {
        UART_write(pass_prompt[i]);
    }
}

/*
    Checks if two strings are the same 
    @return 1 if both inputs are equal, 0 otherwise
    @param a string to be checked
    @param b string to be checked
*/
int checkString(unsigned char a[], unsigned char b[])
{
    int wrong = 0;
    for (int i =0; i < 4; i++)
    {
        if (a[i] != b[i])
        {
            wrong = 1;
            break;
        }
    }
    return !wrong;
}

//informs the user his credentials are valid
void success()
{
    for (int i = 0; i < 19; i++)
    {
        UART_write(success_s[i]);
    }
    
}

//informs the user his credentials are invalid
void fail()
{
    for (int i = 0; i < 18; i++)
    {
        UART_write(fail_s[i]);
    }
}
