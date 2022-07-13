#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*
assets:
https://coolsymbol.com/
https://lingojam.com/EnglishtoShakespearean
https://patorjk.com/software/taag/
*/

#define MAX 10000

void encryptera(char s[MAX],char x[1]){

    for (int i = 0; s[i]; i++)
    {
        printf("%d", s[i]);
    }
}

void decryptera(char ch[MAX]){
    int num = 0;

    for (int i = 7; i < strlen(ch); i++) {
        // Append the current digit
        num = num * 10 + (ch[i] - '0');
        // If num is within the required range
        if (num >= 32 && num <= 122) {
            // Convert num to char
            char chs = (char)num;
            printf("%c",chs);
            // Reset num to 0
            num = 0;
        }
    }
}

void morseDecode(char temp[MAX])
{
    int i=0,j=0,k=0,flag=0;
    char *alphamorse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                        "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
                        "...-",".--","-..-","-.--","--.."};
    char *nummorse[]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

    char morseCode[1000]={0},substr[1000][100]={0},c;

    temp += 7;

    strcpy(morseCode,temp);

    printf("%s", morseCode);

    printf("Type/Copy the above statement with spaces\n");
    gets(morseCode);

    while(morseCode[k]!='\0')//for splitting sentence
    {
        j=0;
        while(morseCode[k]!=' '&&morseCode[k]!='\0')
        {
            substr[i][j]=morseCode[k];
            k++;
            j++;
        }
        substr[i][j]='\0';
        i++;
        if(morseCode[k]!='\0')
        {
            k++;
        }
    }
    int len=i;
    for(i=0;i<len;i++)
    {
        for(j=0;j<25;j++)
        {
            if(!strcmp(alphamorse[j],substr[i]))//strcmp returns 0 if they are same
            {
                printf("%c",(j+97));
                break;
            }
        }
        for(j=0;j<9;j++)
        {
            if(!strcmp(nummorse[j],substr[i]))
            {
                printf("%d",j);
                break;
            }
        }
    }
    printf("\n");
}

void morseEncode(char input[MAX], char x[1])
{
    int i;
    char ch,temp[10],output[MAX];

    strcpy(output,"");

    for(i=0;i<strlen(input)-1; i++) {
        ch = input[i];
        if (ch == 'a')
        {
            strcpy(temp, ".- ");
        } else if (ch == 'b') {
            strcpy(temp, "-... ");
        } else if (ch == 'c') {
            strcpy(temp, "-.-. ");
        } else if (ch == 'd') {
            strcpy(temp, "-.. ");
        } else if (ch == 'e') {
            strcpy(temp, ". ");
        } else if (ch == 'f') {
            strcpy(temp, "..-. ");
        } else if (ch == 'g') {
            strcpy(temp, "--. ");
        } else if (ch == 'h') {
            strcpy(temp, ".... ");
        } else if (ch == 'i') {
            strcpy(temp, ".. ");
        } else if (ch == 'j') {
            strcpy(temp, ".--- ");
        } else if (ch == 'k') {
            strcpy(temp, "-.- ");
        } else if (ch == 'l') {
            strcpy(temp, ".-.. ");
        } else if (ch == 'm') {
            strcpy(temp, "-- ");
        } else if (ch == 'n') {
            strcpy(temp, "-. ");
        } else if (ch == 'o') {
            strcpy(temp, "--- ");
        } else if (ch == 'p') {
            strcpy(temp, ".--. ");
        } else if (ch == 'q') {
            strcpy(temp, "--.- ");
        } else if (ch == 'r') {
            strcpy(temp, ".-. ");
        } else if (ch == 's') {
            strcpy(temp, "... ");
        } else if (ch == 't') {
            strcpy(temp, "- ");
        } else if (ch == 'u') {
            strcpy(temp, "..- ");
        } else if (ch == 'v') {
            strcpy(temp, "...- ");
        } else if (ch == 'w') {
            strcpy(temp, ".-- ");
        } else if (ch == 'x') {
            strcpy(temp, "-..- ");
        } else if (ch == 'y') {
            strcpy(temp, "-.-- ");
        } else if (ch == 'z') {
            strcpy(temp, "--.. ");
        } else if (ch == '1') {
            strcpy(temp, ".---- ");
        } else if (ch == '2') {
            strcpy(temp, "..--- ");
        } else if (ch == '3') {
            strcpy(temp, "...-- ");
        } else if (ch == '4') {
            strcpy(temp, "....- ");
        } else if (ch == '5') {
            strcpy(temp, "..... ");
        } else if (ch == '6') {
            strcpy(temp, "-.... ");
        } else if (ch == '7') {
            strcpy(temp, "--... ");
        } else if (ch == '8') {
            strcpy(temp, "---.. ");
        } else if (ch == '9') {
            strcpy(temp, "----. ");
        } else if (ch == '0') {
            strcpy(temp, "----- ");
        } else if (ch == ' ') {
            strcpy(temp, "/");
        } else {
            break;
        }
        strcat(output, temp);
    }
    printf("%s0.-0Z%s\n",x,output);
}

void en_caesar(char message[MAX], int code, int key, char x[1]);
void en_rail_fence(char message[MAX], int code, int key,  char x[1]);
void en_vigenere(char message[MAX], int code, char key[10], char x[1]);

void de_caesar(char message[MAX]);
void de_rail_fence(char message[MAX]);
void de_vigenere(char message[MAX],char let_key[5]);

void de_rev_caesar(char message[MAX]);

void main() {

    char name[10], let_key[10], en_input[MAX], de_input[MAX];

    char x[1],yyyyy[5];
    int eod, num_key, code, zzzzz;

    printf("---------------------------------------------\n");
    printf("|    .::   .::      .::.::::::::.:::::::    |\n");
    printf("| .::   .:: .::    .:: .::      .::    .::  |\n");
    printf("|.::         .:: .::   .::      .::    .::  |\n");
    printf("|.::           .::     .::::::  .: .::      |\n");
    printf("|.::           .::     .::      .::  .::    |\n");
    printf("| .::   .::    .::     .::      .::    .::  |\n");
    printf("|   .::::      .::     .::      .::      .::|\n");
    printf("---------------------------------------------\n");
    printf("|           a ciphering machina             |\n");
    printf("---------------------------------------------\n");
    printf("|              ent'r thy nameth             |\n");
    printf("|     f'r the secrets thy heart desires     |\n");
    printf("---------------------------------------------\n");
    scanf("%s", &name);
    printf("                welcometh, %s.     \n", name);
    printf("|   how may i beest of s'rvice to thee?   |\n");
    printf("---------------------------------------------\n");
    printf("|       to 1 encode 'r to 2 decode?       |\n");
    printf("---------------------------------------------\n");
    scanf("%d", &eod);

    //encoding

    if (eod == 1) {
        printf("-------------------ENCODE--------------------\n");
        printf("|          what language doth thee         |\n");
        printf("|           wanteth t to beest in?         |\n");
        printf("|      how shalt i encave thy secrets?     |\n");
        printf("|                 A 1 - Caesar               |\n");
        printf("|              B 2 - Rail-fence              |\n");
        printf("|               C 3 - Vigenere               |\n");
        printf("|           D 4 - Reverse Vigenere           |\n");
        printf("|            E 5 - Reverse Caesar            |\n");
        printf("|            F 6 -     ASCII                 |\n");
        printf("|               G 7 - Morse                  |\n");
        printf("---------------------------------------------\n");
        scanf("%d", &code);
        printf("---------------------------------------------\n");
        printf("|ent'r the key as a numb'r (enter any no for Vigenere,ASCII,Morse)|\n");
        scanf("%d", &num_key);
        printf("---------------------------------------------\n");
        printf("|             ent'r thy speech            |\n");
        getchar();
        fgets(en_input, MAX, stdin);
        printf("---------------------------------------------\n");
        switch (code) {
            case 1:
                strcpy(x,"A");
                en_caesar(en_input,code, num_key,x);
                printf("---------------------------------------------\n");
                break;
            case 2:
                strcpy(x, "B");
                en_rail_fence(en_input,code,num_key, x);
                printf("\n---------------------------------------------\n");
                break;
            case 3:
                printf("Enter letter key (max 5 letters please)\n");
                scanf("%s", &let_key);
                strcpy(x, "C");
                en_vigenere(en_input,code,let_key,x);
                printf("\n---------------------------------------------\n");
                break;
            case 4:
                printf("Enter letter key\n");
                scanf("%s", &let_key);
                strcpy(x,"D");
                en_vigenere(en_input,code, let_key,x);
                printf("\n---------------------------------------------\n");
                break;

            case 5:
                strcpy(x,"E");
                en_caesar(en_input,code, num_key,x);
                printf("\n---------------------------------------------\n");
                break;
            case 6:
                strcpy(x,"F");
                encryptera(en_input,x);
                printf("\n---------------------------------------------\n");
                break;
            case 7:
                strcpy(x,"G");
                morseEncode(en_input,x);
                printf("\n---------------------------------------------\n");
                break;
            default:
                printf(" dareth mock me mere mortal? ");
                break;

        }
    }
    if(eod == 2){
        printf("-------------------DECODE--------------------\n");
        printf("|ent'r thy statement and i shalt bewray what lies beyond|\n");
        getchar();
        fgets(de_input,MAX, stdin);

        if(de_input[0]=='A'){
            de_caesar(de_input);
            printf("\n---------------------------------------------\n");
        }
        if(de_input[0]=='B'){

            de_rail_fence(de_input);
            printf("\n---------------------------------------------\n");
        }
        if(de_input[0]=='C'){
            char de_input_2[MAX];
            printf("Enter your coded text\n");
            // getchar();
            fgets(de_input_2,MAX, stdin);
            printf("Enter your coded key \n");
            // getchar();
            fgets(let_key,MAX, stdin);
            de_vigenere(de_input_2,let_key);
            printf("\n------------------------------------------\n");
        }
        if(de_input[0]=='D'){
            char de_input_2[MAX];
            printf("Enter your coded text\n");
            // getchar();
            fgets(de_input_2,MAX, stdin);
            printf("Enter your coded key \n");
            // getchar();
            fgets(let_key,MAX, stdin);
            de_vigenere(strrev(de_input_2),let_key);
            printf("\n------------------------------------------\n");
        }
        if(de_input[0]=='E'){
                de_rev_caesar(de_input);
                printf("%s", de_input);
                printf("\n---------------------------------------------\n");
            }
        if(de_input[0]=='F'){
                decryptera(de_input);
            }
        if(de_input[0]=='G'){
            morseDecode(de_input);
        }
        else{
                printf("u dareth mock me mere mortal?");
        }
    }
}

void de_caesar(char message[MAX]) {
    char ch;
    char temp[MAX];
    int i, key_two ,len, temp_len;

    len = strlen(message);
    len -= 7;
    strcpy(temp, message);
    temp_len = strlen(temp);
    temp[temp_len-len] = '\0';

    if(strcmp(temp, "A00001Z") == 0) {
        key_two = 1;
    }
    else if(strcmp(temp, "A00002Z") == 0){
        key_two = 2;
    }
    else if(strcmp(temp, "A00003Z") == 0){
        key_two = 3;
    }
    else if(strcmp(temp, "A00004Z") == 0){
        key_two = 4;
    }
    else if(strcmp(temp, "A00005Z") == 0){
        key_two = 5;
    }
    else if(strcmp(temp, "A00006Z") == 0){
        key_two = 6;
    }
    else if(strcmp(temp, "A00007Z") == 0){
        key_two = 7;
    }
    else if(strcmp(temp, "A00008Z") == 0){
        key_two = 8;
    }
    else if(strcmp(temp, "A00009Z") == 0){
        key_two = 9;
    }
    else if(strcmp(temp, "A00010Z") == 0){
        key_two = 10;
    }
    else if(strcmp(temp, "A00011Z") == 0){
        key_two = 11;
    }
    else if(strcmp(temp, "A00012Z") == 0){
        key_two = 12;
    }
    else if(strcmp(temp, "A00013Z") == 0){
        key_two = 13;
    }
    else if(strcmp(temp, "A00014Z") == 0){
        key_two = 14;
    }
    else if(strcmp(temp, "A00015Z") == 0){
        key_two = 15;
    }
    else if(strcmp(temp, "A00016Z") == 0){
        key_two = 16;
    }
    else if(strcmp(temp, "A00017Z") == 0){
        key_two = 17;
    }
    else if(strcmp(temp, "A00018Z") == 0){
        key_two = 18;
    }
    else if(strcmp(temp, "A00019Z") == 0){
        key_two = 19;
    }
    else if(strcmp(temp, "A00020Z") == 0){
        key_two = 20;
    }
    else if(strcmp(temp, "A00021Z") == 0){
        key_two = 21;
    }
    else if(strcmp(temp, "A00022Z") == 0){
        key_two = 22;
    }
    else if(strcmp(temp, "A00023Z") == 0){
        key_two = 23;
    }
    else if(strcmp(temp, "A00024Z") == 0){
        key_two = 24;
    }
    else if(strcmp(temp, "A00025Z") == 0) {
        key_two = 25;
    }
    else{
        printf("u dareth mock me mere mortal?");
    }


    for(i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch -= key_two;
            if(ch < 'a')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch -= key_two;
            if(ch < 'A')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }

    message += 7;

    printf("thy speech is be %s \n", message);


}

void de_rev_caesar(char message[MAX]){
    char ch;
    char temp[MAX];
    int i, key_two ,len, temp_len;

    printf("works");

    len = strlen(message);
    len -= 7;
    strcpy(temp, message);
    temp_len = strlen(temp);
    temp[temp_len-len] = '\0';

    if(strcmp(temp, "E00001Z") == 0) {
        key_two = 1;
    }
    else if(strcmp(temp, "E00002Z") == 0){
        key_two = 2;
    }
    else if(strcmp(temp, "E00003Z") == 0){
        key_two = 3;
    }
    else if(strcmp(temp, "E00004Z") == 0){
        key_two = 4;
    }
    else if(strcmp(temp, "E00005Z") == 0){
        key_two = 5;
    }
    else if(strcmp(temp, "E00006Z") == 0){
        key_two = 6;
    }
    else if(strcmp(temp, "E00007Z") == 0){
        key_two = 7;
    }
    else if(strcmp(temp, "E00008Z") == 0){
        key_two = 8;
    }
    else if(strcmp(temp, "E00009Z") == 0){
        key_two = 9;
    }
    else if(strcmp(temp, "E00010Z") == 0){
        key_two = 10;
    }
    else if(strcmp(temp, "E00011Z") == 0){
        key_two = 11;
    }
    else if(strcmp(temp, "E00012Z") == 0){
        key_two = 12;
    }
    else if(strcmp(temp, "E00013Z") == 0){
        key_two = 13;
    }
    else if(strcmp(temp, "E00014Z") == 0){
        key_two = 14;
    }
    else if(strcmp(temp, "E00015Z") == 0){
        key_two = 15;
    }
    else if(strcmp(temp, "E00016Z") == 0){
        key_two = 16;
    }
    else if(strcmp(temp, "E00017Z") == 0){
        key_two = 17;
    }
    else if(strcmp(temp, "E00018Z") == 0){
        key_two = 18;
    }
    else if(strcmp(temp, "E00019Z") == 0){
        key_two = 19;
    }
    else if(strcmp(temp, "E00020Z") == 0){
        key_two = 20;
    }
    else if(strcmp(temp, "E00021Z") == 0){
        key_two = 21;
    }
    else if(strcmp(temp, "E00022Z") == 0){
        key_two = 22;
    }
    else if(strcmp(temp, "E00023Z") == 0){
        key_two = 23;
    }
    else if(strcmp(temp, "E00024Z") == 0){
        key_two = 24;
    }
    else if(strcmp(temp, "E00025Z") == 0) {
        key_two = 25;
    }
    else{
        printf("u dareth mock me mere mortal?");
    }

    strcpy(message, strrev(message));

    for(i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch -= key_two;
            if(ch < 'a')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch -= key_two;
            if(ch < 'A')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }

    message += 7;

    printf("thy speech is be %s \n", message);

}

void de_rail_fence(char message[MAX]){

    char temp[MAX];
    int  key_two ,len, temp_len, len_2;

    len = strlen(message);
    len -= 7;
    strcpy(temp, message);
    temp_len = strlen(temp);
    temp[temp_len-len] = '\0';

    if(strcmp(temp, "B00001Z") == 0) {
        key_two = 1;
    }
    else if(strcmp(temp, "B00002Z") == 0){
        key_two = 2;
    }
    else if(strcmp(temp, "B00003Z") == 0){
        //  printf("ket works");
        key_two = 3;
    }
    else if(strcmp(temp, "B00004Z") == 0){
        key_two = 4;
    }
    else if(strcmp(temp, "B00005Z") == 0){
        key_two = 5;
    }
    else if(strcmp(temp, "B00006Z") == 0){
        key_two = 6;
    }
    else if(strcmp(temp, "B00007Z") == 0){
        key_two = 7;
    }
    else if(strcmp(temp, "B00008Z") == 0){
        key_two = 8;
    }
    else if(strcmp(temp, "B00009Z") == 0){
        key_two = 9;
    }
    else if(strcmp(temp, "B00010Z") == 0){
        key_two = 10;
    }
    else if(strcmp(temp, "B00011Z") == 0){
        key_two = 11;
    }
    else if(strcmp(temp, "B00012Z") == 0){
        key_two = 12;
    }
    else if(strcmp(temp, "B00013Z") == 0){
        key_two = 13;
    }
    else if(strcmp(temp, "B00014Z") == 0){
        key_two = 14;
    }
    else if(strcmp(temp, "B00015Z") == 0){
        key_two = 15;
    }
    else if(strcmp(temp, "B00016Z") == 0){
        key_two = 16;
    }
    else if(strcmp(temp, "B00017Z") == 0){
        key_two = 17;
    }
    else if(strcmp(temp, "B00018Z") == 0){
        key_two = 18;
    }
    else if(strcmp(temp, "B00019Z") == 0){
        key_two = 19;
    }
    else if(strcmp(temp, "B00020Z") == 0){
        key_two = 20;
    }
    else if(strcmp(temp, "B00021Z") == 0){
        key_two = 21;
    }
    else if(strcmp(temp, "B00022Z") == 0){
        key_two = 22;
    }
    else if(strcmp(temp, "B00023Z") == 0){
        key_two = 23;
    }
    else if(strcmp(temp, "B00024Z") == 0){
        key_two = 24;
    }
    else if(strcmp(temp, "B00025Z") == 0){
        key_two = 25;
    }
    else{
        printf("u dareth mock me mere mortal?");
    }

    message += 7;

    len = strlen(message)-1;

    int i, j, k = -1, row = 0, col = 0, m = 0;
    char rail[key_two][len];

    for(i = 0; i < key_two; ++i)
        for(j = 0; j < len; ++j)
            rail[i][j] = '\n';

    for(i = 0; i < len; ++i){
        rail[row][col++] = '*';

        if(row == 0 || row == key_two-1)
            k= k * (-1);

        row = row + k;
    }

    for(i = 0; i < key_two; ++i)
        for(j = 0; j < len; ++j)
            if(rail[i][j] == '*')
                rail[i][j] = message[m++];

    row = col = 0;
    k = -1;

    printf("\nthy speech is be \n");

    for(i = 0; i < len; ++i){
        printf("%c", rail[row][col++]);

        if(row == 0 || row == key_two-1)
            k= k * (-1);

        row = row + k;
    }
}

void de_vigenere(char message[MAX], char let_key[]){

    int len_msg = strlen(message), len_key = strlen(let_key), i, j, key;
    char nkey[len_msg], demsg[len_msg];


    // generating new key
    for(i = 0, j = 0; i < len_msg; ++i, ++j)
    {
        if(j == len_key)
            j = 0;
        nkey[i] = let_key[j];
    }
    nkey[i] = "/0";

    //decryption
    for(i = 0; i < len_msg; ++i)
        demsg[i] = (((message[i] - nkey[i]) + 26) % 26) + 'A';

    demsg[i] = '\0';

    printf("thy speech shall be - %s", demsg);
}

void en_caesar(char message[MAX], int code, int key,char x[1]) {
    char ch;
    char www[3];
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
    if(code == 1) {
        if(key>0 && key<10)
        {
            printf("thy speech shall be - %s0000%dZ %s \n", x,key,message);
        }
        else{
            printf("thy speech shall be - %s000%dZ %s \n", x,key,message);
        }

    }
    else if(code == 5) {
        message = strrev(message);
        if(key>0 && key<10)
        {
            printf("thy speech shall be - %s0000%dZ %s \n", x,key,message);
        }
        else{
            printf("thy speech shall be - %s000%dZ %s \n", x,key,message);
        }
    }

}

void en_rail_fence(char message[MAX], int code, int key, char x[1]) {
    int len_msg = strlen(message), i, j, k = -1, row = 0, col = 0;
    char rail[key][len_msg];
    char temp[len_msg];

    for (i = 0; i < key; ++i)
        for (j = 0; j < len_msg; ++j)
            rail[i][j] = '\n';

    for (i = 0; i < len_msg; ++i) {
        rail[row][col++] = message[i];

        if (row == 0 || row == key - 1)
            k = k * (-1);

        row = row + k;
    }

    printf("\nthy speech shall be - ");
    if (key == 3) {
        for (i = 0; i < key; ++i)
            for (j = 0; j < len_msg; ++j)
                if (rail[i][j] != '\n')
                    printf("%c", rail[i][j]);
    }
}

void en_vigenere(char message[MAX], int code, char key[5],char x[1]) {

    int len_msg = strlen(message), len_key = strlen(key), i, j;
    char nkey[len_msg], enmsg[len_msg];


    // generating new key
    for (i = 0, j = 0; i < len_msg; ++i, ++j) {
        if (j == len_key)
            j = 0;
        nkey[i] = key[j];
    }
    nkey[i] = '\0';
    // encryption
    for (i = 0; i < len_msg; ++i)
        enmsg[i] = ((message[i] + nkey[i]) % 26) + 'A';
    enmsg[i] = '\0';
    enmsg[strlen(enmsg) - 1] = '\0';

    if (code == 3) {
        if (len_key == 1) {
            printf("thy speech shall be - %s0000%sZ %s", x, key, enmsg);
        }
        else if (len_key == 2) {
            printf("thy speech shall be - %s000%sZ %s", x, key, enmsg);
        }
        else if (len_key == 3) {
            printf("thy speech shall be - %s00%sZ %s", x, key, enmsg);
        }
        else if (len_key == 4) {
            printf("thy speech shall be - %s0%sZ %s", x, key, enmsg);
        }
        else if (len_key == 5) {
            printf("thy speech shall be - %s%sZ %s", x,key,enmsg);
        }
    }
    else if(code ==4){
        if (len_key == 1) {
            printf("thy speech shall be - %s0000%sZ%s", x, key, strrev(enmsg));
        }
        else if (len_key == 2) {
            printf("thy speech shall be - %s000%sZ%s", x, key, strrev(enmsg));
        }
        else if (len_key == 3) {
            printf("thy speech shall be - %s00%sZ%s", x, key, strrev(enmsg));
        }
        else if (len_key == 4) {
            printf("thy speech shall be - %s0%sZ%s", x, key, strrev(enmsg));
        }
        else if (len_key == 5) {
            printf("thy speech shall be - %s%sZ%s", x,key,strrev(enmsg));
        }
    }

}
