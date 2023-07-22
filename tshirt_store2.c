/*** Name: Ahmed Ghoneim..
 * This program is an updated version of project 9, It contains the same coding except that it
 * is now split into several files in order to easily update and maintanance the code.
 * Also, a makefile is used in order to create an output for the user.
 * ***/


//including Header files
#include"tshirt.h"
#include"read_line.h"

//main function
int main() {
char code;
struct tshirt *inventory = NULL;
help();
printf("\n");
for (;;) {

printf("Enter operation code: ");
scanf(" %c", &code);
while(getchar() != '\n')
;

switch (code) {
case 'a':
inventory = add_to_inventory(inventory);
break;
case 'h':
help();
break;
case 'o':
search_by_organization(inventory);
break;
case 's':
search_by_size(inventory);
break;
case 'p':
print_inventory(inventory);
break;
case 'q':
clear_inventory(inventory);
return 0;
default:
printf("Illegal operation code!\n");
}
printf("\n");
}
}

