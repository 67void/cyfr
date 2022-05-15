#include<stdio.h>

/*
#include "file.c"   this is the format for using modules
assets:
https://coolsymbol.com/
https://lingojam.com/EnglishtoShakespearean
https://patorjk.com/software/taag/
43
*/

void main()
{
    char name[100], code[1], input_decode[100000], output_decode[100000], input_encode[100000], output_encode[100000];
    int eod, el;

printf("---------------------------------------------\n");          
printf("|          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡶⢶⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀       ⠀|\n");
printf("|          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀       ⠀⠀|\n");
printf("|          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⣇⣸⣧⣀⠀⠀⠀⠀⠀⠀⠀       ⠀⠀⠀|\n");
printf("|         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢩⡿⢿⡍⠉⠀⠀⠀⠀⠀       ⠀⠀⠀⠀⠀ |\n");
printf("|          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⠈⢿⣆⠀⠀⠀⠀⠀⠀       ⠀⠀⠀⠀|\n");
printf("|          ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣥⣤⣤⣬⣿⣦⠀⠀⠀⠀       ⠀⠀⠀⠀⠀|\n");
printf("|          ⠀⠀⠀⠀⠀⠀⠀⠀⣼⡿⠋⠁⢰⡆⠈⠙⢿⣧⠀⠀⠀       ⠀⠀⠀⠀⠀|\n");
printf("|          ⠀⠀⠀⠀⠀⠀⢀⣾⠟⣷⣄⠀⠸⠇⠀⣠⣾⠻⣷⡀⠀⠀⠀       ⠀⠀⠀|\n");
printf("|          ⢀⡀⠀⠀⠀⢠⣾⠋⠀⠀⠙⠛⠿⠿⠛⠋⠀⠀⠙⣷⡄⠀⠀⠀⢀⡀       |\n");
printf("|          ⠈⠻⣦⣤⣤⣿⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣼⣿⣤⣤⣴⠟⠁       |\n");
printf("|          ⠀⠀⠀⣰⣿⣉⣉⣉⣉⣹⣏⣉⣉⣉⣉⣹⣏⣉⣉⣉⣉⣿⣆⠀⠀⠀       |\n");
printf("|          ⠀⠀⣴⡟⠉⢹⣿⠉⠉⠉⠉⠉⢻⡟⠉⠉⠉⠉⠉⣿⡏⠉⢻⣦⠀       ⠀|\n");
printf("|          ⠀⠐⠛⠛⠛⠛⠛⠛⢻⣿⠛⠛⠛⠛⠛⠛⠻⣿⠛⠛⠛⠛⠛⠛⠂⠀       |\n");
printf("|          ⠀⠀⠀⠀⠀⠀⣤⣤⣸⡏⠀⠀⠀⠀⠀⠀⠀⣿⣤⣤⠀⠀       ⠀⠀⠀ |\n");
printf("|          ⠀⠀⠀⠀⠀⠀⠈⠉⠙⠁⠀⠀⠀⠀⠀⠀⠀⠙⠉⠁⠀⠀       ⠀⠀⠀⠀|\n");
printf("---------------------------------------------\n");
printf("|    .::   .::      .::.::::::::.:::::::    |\n");
printf("| .::   .:: .::    .:: .::      .::    .::  |\n");
printf("|.::         .:: .::   .::      .::    .::  |\n");
printf("|.::           .::     .::::::  .: .::      |\n");
printf("|.::           .::     .::      .::  .::    |\n");
printf("| .::   .::    .::     .::      .::    .::  |\n");
printf("|   .::::      .::     .::      .::      .::|\n");
printf("---------------------------------------------\n");
printf("|         ♗ a ciphering machina ♝           |\n");
printf("---------------------------------------------\n");
printf("|          ︾ ent'r thy nameth ︾           |\n");
printf("|  ︾ f'r the secrets thy heart desires ︾  |\n");
printf("---------------------------------------------\n");
scanf("%s", &name);
printf("              》 welcometh, %s.《    \n", name);
printf("| ︾ how may i beest of s'rvice to thee? ︾ |\n");    
printf("---------------------------------------------\n");
printf("|     ︾ to ❶ encode 'r to ❷ decode? ︾     |\n");
printf("---------------------------------------------\n");
scanf("%d",&eod);
if(eod == 1)
{
    printf("-------------------ENCODE--------------------\n");
    printf("|        ︾ what language doth thee ︾       |\n");
    printf("|        ︾  wanteth t to beest in? ︾       |\n");
    printf("|    ︾ how shalt i encave thy secrets? ︾   |\n");
    
    printf("》Ⓐ - caesar cipher and the variations (substituiton of letters by n number of letters up or down)《\n");
    printf("》Ⓑ - 《\n");
    printf("》Ⓒ - 《\n");
    printf("》Ⓓ - 《\n");
    printf("》Ⓔ - 《\n");
    printf("》Ⓖ - 《\n");
    printf("》Ⓗ - 《\n");
    printf("》Ⓘ - 《\n");
    printf("》Ⓙ - 《\n");
    printf("》Ⓚ - 《\n");
    printf("》Ⓛ - 《\n");
    printf("》Ⓜ - 《\n");
    printf("》Ⓝ - 《\n");
    printf("》Ⓞ - 《\n");
    printf("》Ⓟ - 《\n");
    printf("》Ⓠ - 《\n");
    printf("》Ⓡ - 《\n");
    printf("》Ⓢ - 《\n");
    printf("》Ⓣ - 《\n");
    printf("》Ⓤ - 《\n");
    printf("》Ⓥ - 《\n");
    printf("》Ⓦ - 《\n");
    printf("》Ⓧ - 《\n");
    printf("》Ⓨ - 《\n");
    printf("》Ⓩ - 《\n");
    scanf("%s",&code);
    printf("|        ︾ what language doth thee ︾       |\n");
    printf("|       ︾ ❶ ASCII ❷ Binary ❸ Morse ︾       |\n");
    scanf("%d", &el);
    switch(el)
    {
    case 1:
        printf("-------------------ASCII-------------------\n");
        printf("|          ︾ ent'r thy speech ︾         |\n");
        scanf("%s", &input_encode);
        break; 
    case 2:
        printf("------------------BINARY-------------------\n");
        printf("|          ︾ ent'r thy speech ︾         |\n");
        scanf("%s", &input_encode);
        break;
    case 3:
        printf("------------------MORSE--------------------\n");
        printf("|          ︾ ent'r thy speech ︾         |\n");
        scanf("%s", &input_encode);
        break;
    default:
        printf("thee dareth fig me, m're m'rtal?\n");
    }
}



else if (eod == 2)
{
    printf("-------------------DECODE--------------------\n");
    printf("|ent'r thy statement and i shalt bewray what lies beyond|\n");
    scanf("%s", &input_decode);
}
}