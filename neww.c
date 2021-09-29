#include<stdio.h>
#include<string.h>

int main(){

    char str1[] = "Imnop", str2[] = "zdfgty", str3[] = "defg", str4[20];

    strcat(str2, strcat(str2, strcpy(str1, str2)));

    printf("%s\n", str2);

    return 0;
}