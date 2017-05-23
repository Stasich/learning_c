//
// Created by stasich on 08.04.17.
//

#ifndef getch_stasich
#	define getch_stasich
#	if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int getch(void)
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
#	elif defined(_WIN32)
#		include <conio.h>
#	else
#		error getch is not available on the target system
#	endif
#endif //getch_stasich