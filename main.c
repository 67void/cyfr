#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
assets:
https://coolsymbol.com/
https://lingojam.com/EnglishtoShakespearean
https://patorjk.com/software/taag/
*/

void de_caesar(char message[100000], int key)
{
    char ch;
    int i;

    for(i = 0; message[i] != '\0'; ++i)
        {
            ch = message[i];
            if(ch >= 'a' && ch <= 'z')
            {
                ch -= key;
                if(ch < 'a')
                {
                    ch = ch - 'z' + 'a' - 1;
                }
                message[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                ch -= key;
                if(ch < 'A')
                {
                        ch = ch - 'Z' + 'A' - 1;
                }
                message[i] = ch;
            }
        }
    printf("thy speech is be %s", message);
}

void de_vigenere(char message[100000], char let_key[10], int code)
{

    int len_msg = strlen(message), len_key = strlen(let_key), i, j, key;
    char nkey[len_msg], demsg[len_msg];
 
    // generating new key
    for(i = 0, j = 0; i < len_msg; ++i, ++j)
    {
        if(j == len_key)
            j = 0;
        nkey[i] = let_key[j];
    }
    nkey[i] = '\0';
    
    //decryption
    for(i = 0; i < len_msg; ++i)
        demsg[i] = (((message[i] - nkey[i]) + 26) % 26) + 'A';
 
    demsg[i] = '\0';

    printf("thy speech shall be - %s", demsg);
}

void de_rail_fence(char message[100000], int key, int code)
{
    int len_msg = strlen(message), i, j, k = -1, row = 0, col = 0, m = 0;
    char rail[key][len_msg];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < len_msg; ++j)
            rail[i][j] = '\n';
 
    for(i = 0; i < len_msg; ++i){
        rail[row][col++] = '*';
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < len_msg; ++j)
            if(rail[i][j] == '*')
                rail[i][j] = message[m++];
 
    row = col = 0;
    k = -1;
 
    printf("\nthy speech is be ");
 
    for(i = 0; i < len_msg; ++i){
        printf("%c", rail[row][col++]);
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
}

void reverse(char message[100000], int key, int code)
{
    int len, n;
    len = strlen(message);
    for(n=len-1; n>=0; n--) 
    {
        printf("%c", message[n]);
    }
    if(code == 8)
    {
        de_caesar(message, key);
    }
    if(code == 6)
    {
        de_rail_fence(message,key,code);
    }
}

void vig_reverse(char message[100000], char let_key[10], int code)
{
    int len, n;
    len = strlen(message);
    for(n=len-1; n>=0; n--) 
    {
        printf("%c", message[n]);
    }
    if(code == 6)
    {
        de_vigenere(message, let_key, code);
    }
}

void en_caesar(char message[100000], int key, int code)
{
    char ch;
    int i;

    for(i = 0; message[i] != '\0'; ++i)
        {
            ch = message[i];
            if(ch >= 'a' && ch <= 'z')
            {
                ch += key;
                if(ch > 'z')
                {
                    ch = ch - 'z' + 'a' - 1;
                }
                message[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                ch += key;
                if(ch > 'Z')
                {
                        ch = ch - 'Z' + 'A' - 1;
                }
                message[i] = ch;
            }
        }
    if(code == 1)
    {
        printf("thy speech shall be - %s", message);
    }
    else if(code == 8)
    {   
        code = 0;
        reverse(message,key,code);
    }
}

void affine(char message[100000], int key, int code)
{

}

void en_rail_fence(char message[100000], int key, int code)
{
    int len_msg = strlen(message), i, j, k = -1, row = 0, col = 0;
    char rail[key][len_msg];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < len_msg; ++j)
            rail[i][j] = '\n';
 
    for(i = 0; i < len_msg; ++i){
        rail[row][col++] = message[i];
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    if(code == 3)
    {
        printf("\nthy speech shall be - ");
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < len_msg; ++j)
            if(rail[i][j] != '\n')
                printf("%c", rail[i][j]);
    }
    else if(code ==6)
    {
        for(i = 0; i < key; ++i)
        for(j = 0; j < len_msg; ++j)
            if(rail[i][j] != '\n')
                printf("%c", rail[j][i]);
    }
            
}

void en_vigenere(char message[100000], char let_key[10], int code)
{

    int len_msg = strlen(message), len_key = strlen(let_key), i, j,key;
    char nkey[len_msg], enmsg[len_msg];
 
    // generating new key
    for(i = 0, j = 0; i < len_msg; ++i, ++j)
    {
        if(j == len_key)
            j = 0;
        nkey[i] = let_key[j];
    }
    nkey[i] = '\0';
    // encryption
    for(i = 0; i < len_msg; ++i)
        enmsg[i] = ((message[i] + nkey[i]) % 26) + 'A';
    enmsg[i] = '\0';

    if(code == 4)
    {
        printf("thy speech shall be - %s", enmsg);
    }
    else if(code == 5)
    {   
        code = 0;
        key = 0;
        reverse(enmsg,key,code);
    }
 
}

void main()
{
    char name[100], input_decode[100000], output_decode[100000], input_encode[100000], output_encode[100000], let_key[10];
    int eod, el,num_key, code;

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
    printf("》1 - Caesar《\n");
    printf("》2 - Affine《\n");
    printf("》3 - Rail-fence《\n");
    printf("》4 - Vigenere《\n");
    printf("》5 - Reverse Vigenere《\n");
    printf("》6 - Reverse Rail-fence《\n");
    printf("》7 - Reverse Affine《\n");
    printf("》8 - Reverse Caesar《\n");
    scanf("%d",&code);
    printf("|        ︾ what language doth thee ︾       |\n");
    printf("|       ︾ ❶ ASCII ❷ Binary ❸ Morse ➍ Plain Text ︾       |\n");
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
    
    case 4:
        printf("---------------Plain Text------------------\n");
        printf("|          ︾ ent'r thy speech ︾         \n|");
        scanf("%s", &input_encode);

        if(code == 1 || 8)
        { 
            printf("enter the key");
            scanf("%d", &num_key);
            en_caesar(input_encode,num_key,code);
        }
        if(code == 3 || 6)
        { 
            printf("enter the key");
            scanf("%d", &num_key);
            en_rail_fence(input_encode,num_key,code);
        }
        if(code == 4 || 5)
        {
            printf("enter the key");
            scanf("%s", &let_key);
            en_vigenere(input_encode,let_key,code);
        }
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
    printf("|ent'r thy decrypt code|\n");
    scanf("%d", &code);
    
    if(code==1)
    {
        printf("|ent'r key|\n");
        scanf("%d", &num_key);
        de_caesar(input_decode,num_key);
    }
    if(code == 8)
    {
        printf("|ent'r key|\n");
        scanf("%d", &num_key);
        reverse(input_decode, num_key, code);
    }
    if(code==4)
    {   
        printf("|ent'r key|\n");
        scanf("%s", &let_key);
        de_vigenere(input_decode,let_key,code);
    }
    if(code == 5)
    {
        printf("|ent'r key|\n");
        scanf("%s", &let_key);
        num_key = 0;
        vig_reverse(input_decode, let_key, code);
    }
    if(code==3)
    {
        printf("|ent'r key|\n");
        scanf("%d", &num_key);
        de_rail_fence(input_decode,num_key,code);
    }
    if(code == 6)
    {
        printf("|ent'r key|\n");
        scanf("%d", &num_key);
        reverse(input_decode, num_key, code);
    }
}
}