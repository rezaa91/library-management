#include <stdio.h>
#include <stdlib.h>

#include "main_menu.h"

void display_main_menu()
{
    printf("----------LIBRARY MANAGEMENT SYSTEM----------\n\n");

    fprintf(stdout, "\t1. read all\n\
        2. add book\n\
        3. remove book\n\
        4. edit book\n");

    printf("\n---------------------------------------------\n");
}
