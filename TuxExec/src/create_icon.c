#include <stdio.h>
#include <string.h>
#include "create_icon.h"

void create_icon(void)
{
    char icon[60];

    printf("Create your icon 0.01\n");
    printf("circle\n");
    printf("triangle\n");
    printf("square\n");
    printf("TuxExec Create Icons: ");
    fgets(icon, sizeof(icon), stdin);
    
    icon[strcspn(icon, "\n")] = '\0';
        
        if (strcmp(icon, "circle") == 0) {
           printf("   ooooo    \n");
           printf("  o     o   \n");
           printf(" o       o  \n");
           printf(" o       o  \n");
           printf("  o     o   \n");
           printf("   ooooo    \n");
        } else if (strcmp(icon, "triangle") == 0) {
               printf("     o    \n ");
               printf("    o o     \n");
               printf("   o   o    \n");
               printf("  o     o   \n");
               printf(" o       o \n");
           printf("ooooooooooo\n");
        } else if (strcmp(icon, "square") == 0) {
               printf("oooooooooo\n");
               printf("o        o\n");
               printf("o        o\n");
               printf("o        o\n");           
               printf("o        o\n");
           printf("oooooooooo\n");
        } else {
        printf("not found***\n");
    }
}
