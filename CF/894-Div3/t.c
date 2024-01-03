#include <stdio.h>
#include <string.h>
 
void main()
{
    int count = 0, c = 0, i, j = 0, k, space = 0;
    char str[100], p[50][100], str1[20], ptr1[50][100], cmp[50];
    char C;
 
    scanf(" %[^\n]s", str);
    scanf(" %c", &C);
    for (i = 0;i < strlen(str);i++)
        if ((str[i] == ' ')||(str[i] == ',')||(str[i] == '.'))
            space++;

    for (i = 0, j = 0, k = 0;j < strlen(str);j++)
        if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46)) {    
            p[i][k] = '\0';
            i++;
            k = 0;
        }        
        else
             p[i][k++] = str[j];

    for (i = 0;i < space;i++)
        for (j = i + 1;j <= space;j++)
            if ((strcmp(p[i], p[j]) > 0)) {
                strcpy(cmp, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], cmp);
            }

    int flag = 0;
    for (i = 0;i <= space;i++) {
        if(p[i][0] == C) {
            flag = 1;
            printf("%s %d\n", p[i], i+1);
        }
    }

    if(flag == 0)
        printf("0");
}