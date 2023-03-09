#include <stdio.h>
#include <unistd.h>
#include <iostream>

/*
    \33[2K erases the entire line your cursor is currently on.

    \033[A moves your cursor up one line, 
        but in the same column i.e. not to the start of the line.

    \r brings your cursor to the beginning of the line (\r is for 
        carriage return N.B. carriage returns do not include a 
        newline so cursor remains on the same line) but does not 
        erase anything.
*/

int main ()
{

    //write some input  
    fputs("hello\n",stdout);

    //wait one second to change line above
    sleep(5);

    //remove line
    fputs("\033[A\033[2K",stdout);
    rewind(stdout);

    //write new line
    fputs("bye",stdout);
    // std::cout << "\b";
    //fputs("\b",stdout);

    return 0;
}