//Example Key:133457799BBCDFF1
//Example Text:0123456789ABCDEF
//Example Cipher:85E813540F0AB405
#include <stdio.h>
#include<stdlib.h>
////////////////////constants initialization
char ip[][8]={
{58 ,50 ,42, 34, 26, 18, 10, 2},
{60 ,52 ,44 ,36 ,28 ,20 ,12 ,4},
{62 ,54 ,46 ,38 ,30 ,22 ,14 ,6},
{64 ,56 ,48 ,40 ,32 ,24 ,16 ,8},
{57 ,49 ,41 ,33 ,25 ,17 ,9 ,1},
{59 ,51 ,43 ,35 ,27 ,19 ,11 ,3},
{61 ,53 ,45 ,37 ,29 ,21 ,13 ,5},
{63 ,55 ,47 ,39 ,31 ,23 ,15 ,7}
};

char ip_inverse[][8]={
{40 ,8 ,48 ,16 ,56 ,24 ,64 ,32},
{39 ,7 ,47 ,15 ,55 ,23 ,63 ,31},
{38 ,6 ,46 ,14 ,54 ,22 ,62 ,30},
{37 ,5 ,45 ,13 ,53 ,21 ,61 ,29},
{36 ,4 ,44 ,12 ,52 ,20 ,60 ,28},
{35 ,3 ,43 ,11 ,51 ,19 ,59 ,27},
{34 ,2 ,42 ,10 ,50 ,18 ,58 ,26},
{33 ,1 ,41 ,9 ,49 ,17 ,57 ,25}
};

char expansion[][6]={
{32 ,1 ,2 ,3 ,4 ,5},
{4 ,5 ,6 ,7 ,8 ,9},
{8 ,9 ,10 ,11 ,12 ,13},
{12 ,13 ,14 ,15 ,16 ,17},
{16 ,17 ,18 ,19 ,20 ,21},
{20 ,21 ,22 ,23 ,24 ,25},
{24 ,25 ,26 ,27 ,28 ,29},
{28 ,29 ,30 ,31 ,32 ,1}
};

char permutation_choice_1[][7]={
 {57 ,49 ,41 ,33 ,25 ,17 ,9},
 {1 ,58 ,50 ,42 ,34 ,26 ,18},
 {10 ,2 ,59 ,51 ,43 ,35 ,27},
 {19 ,11  ,3 ,60 ,52 ,44 ,36},
 {63 ,55 ,47 ,39 ,31 ,23 ,15},
 {7 ,62 ,54 ,46 ,38 ,30 ,22},
 {14 ,6 ,61 ,53 ,45 ,37 ,29},
 {21 ,13 ,5 ,28 ,20 ,12 ,4}
};

char permutation_choice_2[][6]={
{14 ,17 ,11 ,24 ,1 ,5},
{3 ,28 ,15 ,6 ,21 ,10},
{23 ,19 ,12 ,4 ,26 ,8},
{16 ,7 ,27 ,20 ,13 ,2},
{41 ,52 ,31 ,37 ,47 ,55},
{30 ,40 ,51 ,45 ,33 ,48},
{44 ,49 ,39 ,56 ,34 ,53},
{46 ,42 ,50 ,36 ,29 ,32}
};

char left_shifts[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
char right_shifts[16]={0,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

char s1[][16]={
            {14 ,4 ,13 ,1 ,2 ,15 ,11 ,8 ,3 ,10 ,6 ,12 ,5 ,9 ,0 ,7},
             {0 ,15  ,7 , 4 ,14  ,2 ,13  ,1 ,10  ,6 ,12 ,11 ,9 ,5 ,3 ,8},
             {4  ,1 ,14 , 8 ,13 , 6 , 2 ,11 ,15 ,12 , 9 , 7 , 3 ,10 , 5 , 0},
            {15, 12 , 8  ,2 , 4 , 9  ,1  ,7 , 5 ,11 , 3 ,14 ,10 , 0  ,6 ,13}
};
char s2[][16]={
            {15 , 1 , 8 ,14 , 6 ,11 , 3 , 4 , 9 , 7 , 2 ,13 ,12 , 0 , 5 ,10},
             {3 ,13 , 4 , 7 ,15  ,2 , 8 ,14 ,12  ,0  ,1 ,10  ,6  ,9 ,11  ,5},
             {0 ,14 , 7 ,11 ,10 , 4 ,13 , 1 , 5 , 8 ,12 , 6 , 9 , 3 , 2 ,15},
            {13  ,8 ,10 , 1 , 3 ,15 , 4 , 2, 11  ,6  ,7 ,12 , 0  ,5 ,14 , 9}
};
char s3[][16]={
            {10  ,0 , 9 ,14 , 6 , 3 ,15 , 5 , 1 ,13 ,12 , 7 ,11 , 4 , 2 , 8},
            {13 , 7 , 0 , 9 , 3 , 4 , 6 ,10 , 2 , 8 , 5 ,14, 12, 11, 15 , 1},
            {13  ,6  ,4  ,9 , 8 ,15 , 3 , 0 ,11,  1 , 2 ,12 , 5 ,10 ,14 , 7},
             {1 ,10 ,13 , 0  ,6  ,9  ,8  ,7  ,4 ,15 ,14 , 3 ,11  ,5 , 2, 12}
};
char s4[][16]={
             {7 ,13 ,14 , 3 , 0 , 6  ,9 ,10 , 1 , 2 , 8 , 5 ,11 ,12 , 4, 15},
            {13 , 8 ,11 , 5 , 6 ,15 , 0  ,3  ,4  ,7 , 2 ,12  ,1 ,10 ,14 , 9},
            {10  ,6 , 9 , 0, 12 ,11 , 7 ,13 ,15 , 1 , 3 ,14 , 5 , 2,  8,  4},
             {3 ,15 , 0 , 6 ,10 , 1 ,13 , 8  ,9 , 4  ,5 ,11 ,12 , 7 , 2 ,14}
};
///////////****************************KAPIL GAUTAM*****************/////////////////////////
char s5[][16]={
             {2 ,12 , 4 , 1 , 7 ,10 ,11 , 6,  8,  5 , 3 ,15 ,13 , 0 ,14 , 9},
            {14 ,11 , 2 ,12 , 4 , 7 ,13 , 1 , 5 , 0 ,15 ,10 , 3  ,9 , 8 , 6},
            {4 , 2 , 1 ,11 ,10 ,13 , 7 , 8 ,15 , 9 ,12 , 5 , 6,  3 , 0, 14},
            {11 , 8 ,12 , 7  ,1, 14 , 2 ,13 , 6, 15  ,0  ,9 ,10  ,4  ,5  ,3}
};
char s6[][16]={
            {12  ,1 ,10 ,15  ,9 , 2 , 6 , 8 , 0, 13 , 3 , 4 ,14 , 7 , 5 ,11},
            {10 ,15 , 4 , 2 , 7, 12  ,9  ,5 , 6 , 1, 13 ,14 , 0 ,11 , 3 , 8},
             {9 ,14 ,15 , 5 , 2 , 8, 12,  3 , 7 , 0,  4, 10 , 1 ,13 ,11 , 6},
             {4  ,3 , 2, 12  ,9  ,5 ,15 ,10, 11 ,14  ,1 , 7  ,6 , 0  ,8 ,13}
};
char s7[][16]={
             {4 ,11 , 2 ,14, 15,  0,  8 ,13 , 3 ,12 , 9 , 7 , 5 ,10 , 6 , 1},
            {13 , 0, 11 , 7 , 4 , 9 , 1 ,10, 14 , 3 , 5, 12 , 2, 15 , 8 , 6},
             {1  ,4 ,11, 13, 12,  3 , 7 ,14, 10, 15 , 6 , 8 , 0 , 5 , 9 , 2},
             {6, 11 ,13 , 8  ,1 , 4 ,10  ,7  ,9  ,5 , 0 ,15 ,14 , 2 , 3 ,12}
};
char s8[][16]={
            {13 , 2,  8,  4,  6, 15, 11,  1, 10,  9 , 3 ,14 , 5 , 0 ,12,  7},
             {1, 15, 13 , 8 ,10 , 3  ,7 , 4 ,12 , 5  ,6 ,11  ,0 ,14 , 9 , 2},
             {7 ,11 , 4 , 1 , 9, 12, 14,  2,  0 , 6 ,10 ,13 ,15 , 3 , 5,  8},
             {2 , 1 ,14  ,7  ,4 ,10 , 8 ,13 ,15 ,12  ,9 , 0  ,3 , 5  ,6, 11}
};
                                                                             
char final_permutation[][4]={
{ 16 , 7 ,20 ,21},
{29 ,12 ,28 ,17},
{ 1 ,15 ,23 ,26},
{ 5 ,18 ,31, 10},
{ 2 , 8, 24 ,14},
{32 ,27 , 3 , 9},
{19 ,13 ,30 , 6},
{22 ,11  ,4 ,25}
};
///////////////////////////Function assigns Binary Values
char * assign_binary(char a)
{
switch(a)
{
case '0':  return     "0000"   ;
case '1':  return     "0001"   ;
case '2':  return     "0010"   ;
case '3':  return     "0011"   ;
case '4':  return     "0100"   ;
case '5':  return     "0101"   ;
case '6':  return     "0110"   ;
case '7':  return     "0111"   ;
case '8':  return     "1000"   ;
case '9':  return     "1001"   ;
case 'a':  return     "1010"   ;
case 'b':  return     "1011"   ;
case 'c':  return     "1100"   ;
case 'd':  return     "1101"   ;
case 'e':  return     "1110"   ;
case 'f':  return     "1111"   ;
///////////////////////////For capital letters
case 'A':  return     "1010"   ;
case 'B':  return     "1011"   ;
case 'C':  return     "1100"   ;
case 'D':  return     "1101"   ;
case 'E':  return     "1110"   ;
case 'F':  return     "1111"   ;
default:{printf("\nNot a Hexadecimal Value");exit(0);}
}
}
////////////////////////////////Calculates String Length
int string_length(char * text){
int length=0,i=0;
for (i=0;text[i]!='\0';i++)
length++;
//printf("%d",length);
return length;
}
///////////////////////////////Calculates the xor of given bits
char xor_function(char a,char b){
if(a=='0' && b=='1') return '1';
else if(a=='1' && b=='1') return '0';
else if(a=='0' && b=='0') return '0';
else if(a=='1' && b=='0') return '1';
}
/////////////////////////////Gives the first and last bit of 6 bits
int first_last(char a,char b){
//printf("first_digit=%c\t,last_digit=%c\n",a,b);
if(a=='0' && b=='0') return 0;
else if(a=='0' && b=='1') return 1;
else if(a=='1' && b=='0') return 2;
else if(a=='1' && b=='1') return 3;
}
/////////////////////////////Gives the middle 4 bits of 6 bits
int middle_four(char *string,int x){
if(string[x]=='0'){
                        if(string[x+1]=='0')    {
                                                 if(string[x+2]=='0') {
                                                                        if(string[x+3]=='0') {
                                                                        //printf("middle_four=>0000");
                                                                        return 0;}
                                                                        else if(string[x+3]=='1')   {
                                                                        //printf("middle_four=>0001");
//////////****************************KAPIL GAUTAM*******/////////
                                                                        return 1;}}
                                                 else if (string[x+2]=='1'){
                                                                        if(string[x+3]=='0') {
                                                                        //printf("middle_four=>0010");
                                                                        return 2;}
                                                                        else if(string[x+3]=='1')   {
                                                                        //printf("middle_four=>0011");
                                                                        return 3;}}
                                                        }
                        else if(string[x+1]=='1'){
                                                 if(string[x+2]=='0') {
                                                                        if(string[x+3]=='0') {
                                                                        //printf("middle_four=>0100");
                                                                        return 4;}
                                                                        else if(string[x+3]=='1')   {
                                                                        //printf("middle_four=>0101");
                                                                        return 5;}}
                                                 else if (string[x+2]=='1'){
                                                                        if(string[x+3]=='0') {
                                                                        //printf("middle_four=>0110");
                                                                        return 6;}
                                                                        else if(string[x+3]=='1')   {
                                                                        //printf("middle_four=>0111");
                                                                        return 7;}}
                                                        }
                        }
else if(string[x]=='1'){
                        if(string[x+1]=='0')    {
                                                 if(string[x+2]=='0') {
                                                                        if(string[x+3]=='0') {
                                                                        //printf("middle_four=>1000");
                                                                        return 8;}
                                                                        else if(string[x+3]=='1')  {
                                                                        //printf("middle_four=>1001"); 
                                                                        return 9;}}
                                                 else if (string[x+2]=='1'){
                                                                        if(string[x+3]=='0') {
                                                                        //printf("middle_four=>1010");
                                                                        return 10;}
                                                                        else if(string[x+3]=='1')   {
                                                                        //printf("middle_four=>1011");
                                                                        return 11;}}
                                                        }
                        else if(string[x+1]=='1'){
                                                 if(string[x+2]=='0') {
                                                                        if(string[x+3]=='0') {
                                                                        //printf("middle_four=>1100");
                                                                        return 12;}
                                                                        else if(string[x+3]=='1')   {
                                                                        //printf("middle_four=>1101");
                                                                        return 13;}}
                                                 else if (string[x+2]=='1'){
                                                                        if(string[x+3]=='0') {
                                                                        //printf("middle_four=>1110");
                                                                        return 14;}
                                                                        else if(string[x+3]=='1')   {
                                                                        //printf("middle_four=>1111");
                                                                        return 15;}}
                                                        }
                        }
}
///////////////////////////Converts decimal to Hexadecimal
char decimal_to_hexadecimal(int a){
//printf("a is=>%d\n",a);
switch(a){
case 0: return '0';
case 1: return '1';
case 2: return '2';
case 3: return '3';
case 4: return '4';
case 5: return '5';
case 6: return '6';
case 7: return '7';
case 8: return '8';
case 9: return '9';
case 10:return 'a';
case 11:return 'b';
case 12:return 'c';
case 13:return 'd';
case 14:return 'e';
case 15:return 'f';
default:{printf("\nNo Value Found\n");exit(0);}
}}
///////////////////////Power function
int power(int x, int y){
int mul=1,i;
for(i=0;i<y;i++)
mul=x*mul;
//printf("power is =>%d\n",mul);
return mul;
}
///////////////////////Converts binary to hexadecimal
char binary_to_hexadecimal(char *string){
int i,j,value=0,sum=0;                              //binary to decimal
for(i=3,j=0;i>=0 && j<4;i--,j++)
{value=(string[i]-48)*power(2,j);
//printf("value is =>%d\n",value);
sum=sum+value;
}
return decimal_to_hexadecimal(sum);             //decimal to hexadecimal
}
////////////////*********KAPIL GAUTAM********************///////////////////
///////////////////////////Converts decimal to binary
char *decimal_to_binary(int a){
//printf("a=>%d\n",a);
switch (a){
case 0: return "0000";
case 1: return "0001";
case 2: return "0010";
case 3: return "0011";
case 4: return "0100";
case 5: return "0101";
case 6: return "0110";
case 7: return "0111";
case 8: return "1000";
case 9: return "1001";
case 10: return "1010";
case 11: return "1011";
case 12: return "1100";
case 13: return "1101";
case 14: return "1110";
case 15: return "1111";
default:{printf("\nNo Value Found\n");exit(0);}
}
}
/////////////////////////////////////////Converts hexadecimal to binary
char *convert_hex_to_binary(char *hex_text){
int hex_length=string_length(hex_text);
char binary[(hex_length*4)+15*4+1];            //extra 15*4 for padding and +1 for null character
char temp_binary[4];

//Now Converting to binary
int i=0,k=0;
while(hex_text[i]!='\0')
{sprintf(temp_binary,"%s",assign_binary(hex_text[i]));
//printf("%s",binary);
int j=0;
while(temp_binary[j]!='\0')
{binary[k]=temp_binary[j];
j++;k++;}
i++;
}
binary[k]='\0';
int binary_length=string_length(binary);
printf("\nBinary Form of above Hexadecimal value.\n");
puts(binary);
printf("Length of Binary Form=%d\n",binary_length);
char *binary2=binary;
return binary2;
}
///////////////////////Converts string to binary
char * convert_string_to_binary(char *plain_text)
{
int i,j,k;i=j=k=0;
int plain_length;

//Converting to Hexadecimal form of the entered
plain_length=string_length(plain_text);
printf("Length of Plain Text=%d\n",plain_length);
char temp_convert[2];
char hex[(plain_length*2)+15+1];       //extra 15 for padding   //+1for null character
int hex_length;

for(i=0;i<plain_length;i++)
{
//printf("%c->%x\n",plain_text[i],plain_text[i]);
sprintf(temp_convert,"%x",plain_text[i]);
//printf("\nhex=%s",temp_convert);
j=0;
while(temp_convert[j]!='\0')
{hex[k]=temp_convert[j];
j++;k++;}
}
hex[k]='\0';
hex_length=string_length(hex);

//printf("hex_length=%d\nk=%d",hex_length,k);

while(hex_length%16!=0)
{
hex[hex_length]='0';
hex_length++;
}

//printf("hex_length=%d\n",hex_length);

hex[hex_length]='\0';
printf("\nHexadecimal Form of Entered Plain_text(after padding).\n");
puts(hex);
printf("Length of Hexadecimal Form=%d\n",hex_length);

char binary[(plain_length*2*4)+15*4+1];            //extra 15*4 for padding and +1 for null character
char temp_binary[4];

//Now Converting to binary
i=0;k=0;
while(hex[i]!='\0')
{sprintf(temp_binary,"%s",assign_binary(hex[i]));
//printf("%s",binary);
j=0;
while(temp_binary[j]!='\0')
/////////////*******KAPIL GAUTAM*********************////
j++;k++;}
i++;
}
binary[k]='\0';
int binary_length=string_length(binary);
printf("\nBinary Form of above Hexadecimal value.\n");
puts(binary);
printf("Length of Binary Form=%d\n",binary_length);
char *binary1=binary;
return binary1;
}

////////////////////////////////Convert binary to string
char * convert_binary_to_string(char *binary)
{
int i,j,k;i=j=k=0;
int binary_length;

//Converting to Hexadecimal form of the entered

binary_length=string_length(binary);
printf("\nLength of binary=%d\n",binary_length);

char temp_convert[4+1];//+1for null character
char hex[(binary_length/4)+(15+1)/4];       //extra 15 for padding   //+1for null character
int hex_length;
i=0;k=0;
while(binary[i]!='\0')
{for(j=0;j<4;j++)
{temp_convert[j]=binary[i];i++;}
temp_convert[j]='\0';
//printf("temp_convert=>%s\n",temp_convert);
hex[k]=binary_to_hexadecimal(temp_convert);
//printf("hex[%d]=>%c\n",k,hex[k]);
k++;}

hex[k]='\0';
hex_length=string_length(hex);
//printf("hex_length=%d\nk=%d",hex_length,k);

while(hex_length%16!=0)
{
hex[hex_length]='0';
hex_length++;
}
printf("Length of Hexadecimal Form=%d\n",k);
printf("Hexadecimal form is:\n");
puts(hex);
char *hex_text1=hex;
return hex_text1;
}







////////////////////////////////Decryption function
char *decryption(char* left_message,char* right_message,char *key_left,char *key_right,int shift,int round)
{
char new_left_message[32+1];                     //+1for null character
char new_right_message[32+1];                    //+1for null character
int i,j,k;i=j=k=0;
if(round>=0 && round<=15)
{
printf("\nIn round %d :\n",round);
printf("Left part of key is=>  ");puts(key_left);
printf("Right part of key is=> ");puts(key_right);

char temp_left_key,temp_right_key;
char temp1_left_key,temp1_right_key;

if(shift==1){
temp_left_key=key_left[27];
temp_right_key=key_right[27];
for(i=26;i>=0;i--)
{
key_left[i+1]=key_left[i];
key_right[i+1]=key_right[i];
printf("key_left[%d]=>%c\n",i,key_left[i]);
}
key_left[0]=temp_left_key;
key_right[0]=temp_right_key;
}
else if (shift==2){
temp_left_key=key_left[27];
temp_right_key=key_right[27];
temp1_left_key=key_left[26];
temp1_right_key=key_right[26];
for(i=25;i>=0;i--)
{
key_left[i+2]=key_left[i];
key_right[i+2]=key_right[i];
}
key_left[0]=temp1_left_key;
key_right[0]=temp1_right_key;
key_left[1]=temp_left_key;
key_right[1]=temp_right_key;
}
printf("\nIn round %d :\n",round);
printf("Left part of key is=>  ");puts(key_left);
printf("Right part of key is=> ");puts(key_right);
char whole_key[56+1];                           //+1for null character
k=0;
for(i=0;i<56;i++)
{if (i<28) {whole_key[k]=key_left[i];k++;}
else {whole_key[k]=key_right[i-28];k++;}
}
whole_key[k]='\0';
printf("Combined key  is=>     ");puts(whole_key);
//////////////////*******KAPIL GAUTAM*********///////
//////////////////////////////////////////Permutation choice 2
char permutated_2_key[48+1];          //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<6;j++)
{permutated_2_key[k]=whole_key[permutation_choice_2[i][j]-1];k++;
//printf("k=%d\n",k);
}
permutated_2_key[k]='\0';
printf("Second Permutation=>   ");puts(permutated_2_key);

i=0;
while(right_message[i]!='\0')
{new_left_message[i]=right_message[i];i++;
}
new_left_message[i]='\0';

////////////////////////////Expansion of the right part of message

char expansion_message[48+1];             //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<6;j++)
{expansion_message[k]=right_message[expansion[i][j]-1];k++;}
expansion_message[k]='\0';
printf("Exapansion Message=>   ");puts(expansion_message);


/////////////////XOR of permutated key and the expansion function
char xor[48+1];                      //+1for null character
i=0;
while(expansion_message[i]!='\0' && permutated_2_key[i]!='\0')
{xor[i]=xor_function(expansion_message[i],permutated_2_key[i]);i++;
}
xor[i]='\0';
printf(" XORed   Message =>    ");puts(xor);

///////////////////Substitution Boxes
char sbox1[4],sbox2[4],sbox3[4],sbox4[4],sbox5[4],sbox6[4],sbox7[4],sbox8[4];

for(i=0;i<48;i++)
{//printf("Initial i=>%d\n",i);
if(i<6){
sprintf(sbox1,"%s",decimal_to_binary(s1[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox1=>%s\t,i=>%d\n",sbox1,i);
}
else if(i>=6 &&i<12){
sprintf(sbox2,"%s",decimal_to_binary(s2[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox2=>%s\t,i=>%d\n",sbox2,i);
}
else if(i>=12 &&i<18){
sprintf(sbox3,"%s",decimal_to_binary(s3[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox3=>%s\t,i=>%d\n",sbox3,i);
}
else if(i>=18 &&i<24){
sprintf(sbox4,"%s",decimal_to_binary(s4[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox4=>%s\t,i=>%d\n",sbox4,i);
}
else if(i>=24 &&i<30){
sprintf(sbox5,"%s",decimal_to_binary(s5[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox5=>%s\t,i=>%d\n",sbox5,i);
}
else if(i>=30 &&i<36){
sprintf(sbox6,"%s",decimal_to_binary(s6[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox6=>%s\t,i=>%d\n",sbox6,i);
}
else if(i>=36 &&i<42){
sprintf(sbox7,"%s",decimal_to_binary(s7[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox7=>%s\t,i=>%d\n",sbox7,i);
}
else if(i>=42 &&i<48){
sprintf(sbox8,"%s",decimal_to_binary(s8[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox8=>%s\t,i=>%d\n",sbox8,i);
}
}

char new_xored[48+1];
k=0;
for(i=0;i<8;i++)
for(j=0;j<4;j++)
{switch(i){
case 0:{new_xored[k]=sbox1[j];k++;}break;
case 1:{new_xored[k]=sbox2[j];k++;}break;
case 2:{new_xored[k]=sbox3[j];k++;}break;
case 3:{new_xored[k]=sbox4[j];k++;}break;
case 4:{new_xored[k]=sbox5[j];k++;}break;
case 5:{new_xored[k]=sbox6[j];k++;}break;
case 6:{new_xored[k]=sbox7[j];k++;}break;
case 7:{new_xored[k]=sbox8[j];k++;}break;
}
}
new_xored[k]='\0';
printf(" After  S-Boxes  =>    ");puts(new_xored);
/////////////*********KAPIL GAUTAM*******************/////////////////
///////////////////////////Final Permutation
char permutation_new_xor[32+1];          //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<4;j++)
{permutation_new_xor[k]=new_xored[final_permutation[i][j]-1];k++;
//printf("k=%d\n",k);
}
permutation_new_xor[k]='\0';
printf("After permuted XOR =>  ");puts(permutation_new_xor);

/////////////////////////new_right_message=R 1 = L0 + f(R 0,K 1)


i=0;
while(left_message[i]!='\0')
{new_right_message[i]=xor_function(left_message[i],permutation_new_xor[i]);i++;
}
new_right_message[i]='\0';
printf("Left part of message=> ");puts(new_left_message);
printf("Right part of message=>");puts(new_right_message);

round++;
if(round<16)
decryption(new_left_message,new_right_message,key_left,key_right,right_shifts[round],round);

}

//////////////////////////After the 16th Round
//puts(new_left_message);
//puts(new_right_message);
///printf("round=>%d\n",round);
 if(round==16 ){
printf("\n\n");
char primitive_cipher[64+1] ;                      //+1for null character
for(i=0;i<64;i++)
{if(i<32) {primitive_cipher[i]=new_right_message[i];}
else {primitive_cipher[i]=new_left_message[i-32];}
}
primitive_cipher[i]='\0';
printf("Primitive Cipher =>    ");puts(primitive_cipher);


char cipher[64+1] ;                      //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<8;j++)
{cipher[k]=primitive_cipher[ip_inverse[i][j]-1];k++;}
cipher[k]='\0';
printf("  Cipher  Message=>    ");puts(cipher);

char *cipher1=cipher;


return cipher1;
}

}
//////////////////////////////////Intermediary function
intermediate_decryption(char * binary_form_plain_text){
int i=0,j=0,k=0;

////////////////////Get The Binary form of Key

char binary_form_key[64];   
char choose_key;
printf("Which Format your Input Key is:\n1.In English Language.\n2.Hexadecimal Form.\n");
choose_key=getchar();
switch(choose_key){
case '1':{char key[8];
                printf("Please Enter Your Encryption (8 characters)Key.\n");
                gets(key);gets(key);
                int key_length=string_length(key);
                if(key_length==8)
                {  
                 sprintf(binary_form_key,"%s",convert_string_to_binary(key));}
                 else {printf("Wrong number of input characters.\nYou have to enter 8 characters.\n");exit(0);}}break;
                
case '2':{char key[16];
                printf("Please Enter Your Encryption (16 Hexadecimal values)Key.\n");
                        gets(key);gets(key);
                int key_length=string_length(key);
                 if(key_length==16)
                {
                 sprintf(binary_form_key,"%s",convert_hex_to_binary(key));}
                 else {printf("Wrong number of input characters.\nYou have to enter 16 Hexadecimal values.\n");exit(0);}}break;
default: {printf("You have entered a wrong number.\n");main();}   }
 //////////////************KAPIL GAUTAM*****************////////////////////
////////////////////////////Working on key
/////////////////Permutation choice 1

char permuted_1_binary_form_key[56+1];          //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<7;j++)
{permuted_1_binary_form_key[k]=binary_form_key[permutation_choice_1[i][j]-1];k++;}
permuted_1_binary_form_key[k]='\0';
printf("\nFirst Permutation Binary Form.\n");puts(permuted_1_binary_form_key);

char left_permuted_1_binary_form_key[28+1];             //+1for null character
char right_permuted_1_binary_form_key[28+1];            //+1for null character
j=0;k=0;
for(i=0;i<56;i++)
{if(i<28) {left_permuted_1_binary_form_key[i]=permuted_1_binary_form_key[i];j=i;}
else {right_permuted_1_binary_form_key[i-28]=permuted_1_binary_form_key[i];k=i-28;}
}
left_permuted_1_binary_form_key[++j]='\0';
right_permuted_1_binary_form_key[++k]='\0';


printf("Left part of key  is=>  ");puts(left_permuted_1_binary_form_key);
printf("Right part of key is=>  ");puts(right_permuted_1_binary_form_key);


////////////////////Initial Permutation of Message
//puts(binary_form_plain_text);
char permutated_message[64+1];          //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<8;j++)
{permutated_message[k]=binary_form_plain_text[ip[i][j]-1];k++;}
permutated_message[k]='\0';
printf("Permutated Message=>   ");puts(permutated_message);

char new_left_message[32+1];             //+1for null character
char new_right_message[32+1];            //+1for null character
j=0;k=0;
for(i=0;i<64;i++)
{if(i<32) {new_left_message[i]=permutated_message[i];j=i;}
else {new_right_message[i-32]=permutated_message[i];k=i-32;}
}
new_left_message[++j]='\0';
new_right_message[++k]='\0';


printf("Left  message  is=>    ");puts(new_left_message);
printf("Right  message is=>    ");puts(new_right_message);



////////////////////The 16  Rounds Recursive Encryption Function
char *text;
text=decryption(new_left_message,new_right_message,left_permuted_1_binary_form_key,right_permuted_1_binary_form_key,right_shifts[0],0);
printf("\n");
printf("Decrypted Text=>%s",text);

char *test=convert_binary_to_string(text);

}







////////////////////////////////////////////////Encryption function
char *encryption(char* left_message,char* right_message,char *key_left,char *key_right,int shift,int round)
{
char new_left_message[32+1];                     //+1for null character
char new_right_message[32+1];                    //+1for null character
int i,j,k;i=j=k=0;
if(round>=0 && round<=15)
{
char temp_left_key,temp_right_key;
char temp1_left_key,temp1_right_key;

if(shift==1){
temp_left_key=key_left[0];
temp_right_key=key_right[0];
for(i=1;i<28;i++)
{
key_left[i-1]=key_left[i];
key_right[i-1]=key_right[i];
}
key_left[i-1]=temp_left_key;
key_right[i-1]=temp_right_key;
}
else if (shift==2){
temp_left_key=key_left[0];
temp_right_key=key_right[0];
temp1_left_key=key_left[1];
temp1_right_key=key_right[1];
for(i=2;i<28;i++)
{
key_left[i-2]=key_left[i];
key_right[i-2]=key_right[i];
}
key_left[i-1]=temp1_left_key;
key_right[i-1]=temp1_right_key;
key_left[i-2]=temp_left_key;
key_right[i-2]=temp_right_key;
}
printf("\nIn round %d :\n",round);
printf("Left part of key is=>  ");puts(key_left);
printf("Right part of key is=> ");puts(key_right);
char whole_key[56+1];                           //+1for null character
k=0;
for(i=0;i<56;i++)
{if (i<28) {whole_key[k]=key_left[i];k++;}
else {whole_key[k]=key_right[i-28];k++;}
}
whole_key[k]='\0';
printf("Combined key  is=>     ");puts(whole_key);
////////////////////******************KAPIL GAUTAM***********///////////
//////////////////////////////////Permutation choice 2
char permutated_2_key[48+1];          //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<6;j++)
{permutated_2_key[k]=whole_key[permutation_choice_2[i][j]-1];k++;
//printf("k=%d\n",k);
}
permutated_2_key[k]='\0';
printf("Second Permutation=>   ");puts(permutated_2_key);

i=0;
while(right_message[i]!='\0')
{new_left_message[i]=right_message[i];i++;
}
new_left_message[i]='\0';

///////////////////////Expansion of the right part of message

char expansion_message[48+1];             //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<6;j++)
{expansion_message[k]=right_message[expansion[i][j]-1];k++;}
expansion_message[k]='\0';
printf("Exapansion Message=>   ");puts(expansion_message);

///////////////////////XOR of permutated key and the expansion function
char xor[48+1];                      //+1for null character
i=0;
while(expansion_message[i]!='\0' && permutated_2_key[i]!='\0')
{xor[i]=xor_function(expansion_message[i],permutated_2_key[i]);i++;
}
xor[i]='\0';
printf(" XORed   Message =>    ");puts(xor);

////////////Substitution Boxes
char sbox1[4],sbox2[4],sbox3[4],sbox4[4],sbox5[4],sbox6[4],sbox7[4],sbox8[4];

for(i=0;i<48;i++)
{//printf("Initial i=>%d\n",i);
if(i<6){
sprintf(sbox1,"%s",decimal_to_binary(s1[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox1=>%s\t,i=>%d\n",sbox1,i);
}
else if(i>=6 &&i<12){
sprintf(sbox2,"%s",decimal_to_binary(s2[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox2=>%s\t,i=>%d\n",sbox2,i);
}
else if(i>=12 &&i<18){
sprintf(sbox3,"%s",decimal_to_binary(s3[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox3=>%s\t,i=>%d\n",sbox3,i);
}
else if(i>=18 &&i<24){
sprintf(sbox4,"%s",decimal_to_binary(s4[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox4=>%s\t,i=>%d\n",sbox4,i);
}
else if(i>=24 &&i<30){
sprintf(sbox5,"%s",decimal_to_binary(s5[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox5=>%s\t,i=>%d\n",sbox5,i);
}
else if(i>=30 &&i<36){
sprintf(sbox6,"%s",decimal_to_binary(s6[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox6=>%s\t,i=>%d\n",sbox6,i);
}
else if(i>=36 &&i<42){
sprintf(sbox7,"%s",decimal_to_binary(s7[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox7=>%s\t,i=>%d\n",sbox7,i);
}
else if(i>=42 &&i<48){
sprintf(sbox8,"%s",decimal_to_binary(s8[first_last(xor[i],xor[i+5])][middle_four(xor,i+1)]));i=i+5;
//printf("sbox8=>%s\t,i=>%d\n",sbox8,i);
}
}

char new_xored[48+1];
k=0;
for(i=0;i<8;i++)
for(j=0;j<4;j++)
{switch(i){
case 0:{new_xored[k]=sbox1[j];k++;}break;
case 1:{new_xored[k]=sbox2[j];k++;}break;
case 2:{new_xored[k]=sbox3[j];k++;}break;
case 3:{new_xored[k]=sbox4[j];k++;}break;
case 4:{new_xored[k]=sbox5[j];k++;}break;
case 5:{new_xored[k]=sbox6[j];k++;}break;
case 6:{new_xored[k]=sbox7[j];k++;}break;
case 7:{new_xored[k]=sbox8[j];k++;}break;
}
}
new_xored[k]='\0';
printf(" After  S-Boxes  =>    ");puts(new_xored);
///////////////////*********KAPIL GAUTAM*******************////////////////////////
/////////////////////////////////////////Final Permutation
char permutation_new_xor[32+1];          //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<4;j++)
{permutation_new_xor[k]=new_xored[final_permutation[i][j]-1];k++;
//printf("k=%d\n",k);
}
permutation_new_xor[k]='\0';
printf("After permuted XOR =>  ");puts(permutation_new_xor);

////////////////////new_right_message=R 1 = L0 + f(R 0,K 1)


i=0;
while(left_message[i]!='\0')
{new_right_message[i]=xor_function(left_message[i],permutation_new_xor[i]);i++;
}
new_right_message[i]='\0';
printf("Left part of message=> ");puts(new_left_message);
printf("Right part of message=>");puts(new_right_message);

round++;
if(round<16)
encryption(new_left_message,new_right_message,key_left,key_right,left_shifts[round],round);

}

/////////////////////////After the 16th Round
//puts(new_left_message);
//puts(new_right_message);
///printf("round=>%d\n",round);
 if(round==16 ){
printf("\n\n");
char primitive_cipher[64+1] ;                      //+1for null character
for(i=0;i<64;i++)
{if(i<32) {primitive_cipher[i]=new_right_message[i];}
else {primitive_cipher[i]=new_left_message[i-32];}
}
primitive_cipher[i]='\0';
printf("Primitive Cipher =>    ");puts(primitive_cipher);


char cipher[64+1] ;                      //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<8;j++)
{cipher[k]=primitive_cipher[ip_inverse[i][j]-1];k++;}
cipher[k]='\0';
printf("  Cipher  Message=>    ");puts(cipher);

char *cipher1=cipher;


return cipher1;
}

}

//////////////////////////////////Intermediary function
intermediate_encryption(char * binary_form_plain_text){
int i=0,j=0,k=0;


//////////////Get The Binary form of Key

char binary_form_key[64];   
char choose_key;
printf("Which Format your Input Key is:\n1.In English Language.\n2.Hexadecimal Form.\n");
choose_key=getchar();
switch(choose_key){
case '1':{char key[8];
                printf("Please Enter Your Encryption (8 characters)Key.\n");
                gets(key);gets(key);
                int key_length=string_length(key);
                if(key_length==8)
                {  
                 sprintf(binary_form_key,"%s",convert_string_to_binary(key));}
                 else {printf("Wrong number of input characters.\nYou have to enter 8 characters.\n");exit(0);}}break;
                
case '2':{char key[16];
                printf("Please Enter Your Encryption (16 Hexadecimal values)Key.\n");
                        gets(key);gets(key);
                int key_length=string_length(key);
                 if(key_length==16)
                {
                 sprintf(binary_form_key,"%s",convert_hex_to_binary(key));}
                 else {printf("Wrong number of input characters.\nYou have to enter 16 Hexadecimal values.\n");exit(0);}}break;
default: {printf("You have entered a wrong number.\n");main();}   }
 ////////////////////******KAPIL GAUTAM******************/////////////////////////////
///////////////////////////Working on key///////////////
////////////////////////Permutation choice 1

char permuted_1_binary_form_key[56+1];          //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<7;j++)
{permuted_1_binary_form_key[k]=binary_form_key[permutation_choice_1[i][j]-1];k++;}
permuted_1_binary_form_key[k]='\0';
printf("\nFirst Permutation Binary Form.\n");puts(permuted_1_binary_form_key);

char left_permuted_1_binary_form_key[28+1];             //+1for null character
char right_permuted_1_binary_form_key[28+1];            //+1for null character
j=0;k=0;
for(i=0;i<56;i++)
{if(i<28) {left_permuted_1_binary_form_key[i]=permuted_1_binary_form_key[i];j=i;}
else {right_permuted_1_binary_form_key[i-28]=permuted_1_binary_form_key[i];k=i-28;}
}
left_permuted_1_binary_form_key[++j]='\0';
right_permuted_1_binary_form_key[++k]='\0';


printf("Left part of key  is=>  ");puts(left_permuted_1_binary_form_key);
printf("Right part of key is=>  ");puts(right_permuted_1_binary_form_key);


/////////////////////Initial Permutation of Message
//puts(binary_form_plain_text);
char permutated_message[64+1];          //+1for null character
k=0;
for(i=0;i<8;i++)
for(j=0;j<8;j++)
{permutated_message[k]=binary_form_plain_text[ip[i][j]-1];k++;}
permutated_message[k]='\0';
printf("Permutated Message=>   ");puts(permutated_message);

char new_left_message[32+1];             //+1for null character
char new_right_message[32+1];            //+1for null character
j=0;k=0;
for(i=0;i<64;i++)
{if(i<32) {new_left_message[i]=permutated_message[i];j=i;}
else {new_right_message[i-32]=permutated_message[i];k=i-32;}
}
new_left_message[++j]='\0';
new_right_message[++k]='\0';


printf("Left  message  is=>    ");puts(new_left_message);
printf("Right  message is=>    ");puts(new_right_message);




////////////////////////The 16  Rounds Recursive Encryption Function
char *cipher;
cipher=encryption(new_left_message,new_right_message,left_permuted_1_binary_form_key,right_permuted_1_binary_form_key,left_shifts[0],0);
printf("\n");
printf("Encrypted Cipher=>%s",cipher);

char *test=convert_binary_to_string(cipher);

}

///////////////////////Main Function
main(){
int i=0,j=0,k=0;

char choose_encrypt_decrypt;
printf("\n1.Encrypt Message using DES.\n2.Decrypt Message using DES.\n");
choose_encrypt_decrypt=getchar();
switch(choose_encrypt_decrypt){
case '1':
{/*for(i=0;i<8;i++)
{for(j=0;j<6;j++)
printf("%d ",permutation_choice_2[i][j]);}
printf("\n");
*/

///////////////////Get The Binary form of Message
char choose;
printf("Which Format your Input Text is:\n1.In English Language.\n2.Hexadecimal Form.\n");getchar();
choose=getchar();
switch(choose){
case '1':{      char plain_text[100];
                
                printf("\nInput your Plain Text\n");
                gets(plain_text);gets(plain_text);
                int plain_length;
                plain_length=string_length(plain_text);
                char binary_form_plain_text[(plain_length*2*4)+15*4+1];           //extra 15*4 for padding

                sprintf(binary_form_plain_text,"%s",convert_string_to_binary(plain_text));
                intermediate_encryption(binary_form_plain_text);}break;
                
case '2':{      char hex_text[100];
                printf("Input your Hexadecimal Text\n");
                gets(hex_text);gets(hex_text);
                int hex_length;
                hex_length=string_length(hex_text);
                char binary_form_plain_text[(hex_length*4)+15*4+1];           //extra 15*4 for padding

                sprintf(binary_form_plain_text,"%s",convert_hex_to_binary(hex_text));
                intermediate_encryption(binary_form_plain_text);}break;
default: {printf("You have entered a wrong number.\n");main();}        }    }    break;
                
case '2':{     

/*for(i=0;i<8;i++)
{for(j=0;j<6;j++)
printf("%d ",permutation_choice_2[i][j]);}
printf("\n");
*/

///////////////////Get The Binary form of Message
char choose;
printf("Which Format your Cipher Text is:\n1.In English Language.\n2.Hexadecimal Form.\n");getchar();
choose=getchar();
switch(choose){
case '1':{      char cipher_text[100];
                
                printf("\nInput your Cipher Text\n");
                gets(cipher_text);gets(cipher_text);
                int cipher_length;
                cipher_length=string_length(cipher_text);
                char binary_form_cipher_text[(cipher_length*2*4)+15*4+1];           //extra 15*4 for padding

                sprintf(binary_form_cipher_text,"%s",convert_string_to_binary(cipher_text));
                intermediate_decryption(binary_form_cipher_text);}break;
                
case '2':{      char hex_text[100];
                printf("Input your Hexadecimal Text\n");
                gets(hex_text);gets(hex_text);
                int hex_length;
                hex_length=string_length(hex_text);
                char binary_form_plain_text[(hex_length*4)+15*4+1];           //extra 15*4 for padding

                sprintf(binary_form_plain_text,"%s",convert_hex_to_binary(hex_text));
                intermediate_decryption(binary_form_plain_text);}break;
default: {printf("You have entered a wrong number.\n");main();}        }  }      break;
default: {printf("You have entered a wrong number.\n");main();}        }        

}
/////////////////////////////**********************KAPIL GAUTAM*****//////////////////////
