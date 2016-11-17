#include <stdio.h>
#include <stdlib.h>
char **make_array(int num);
void show_word(char **word, int num);
int main(void)
{
    int num;
    char **ptd;
    printf("How many words do you wish to enter? ");
    scanf("%d", &num);
    while (getchar() != '\n')
        continue;
    ptd = make_array(num);
    show_word(ptd, num);
    return 0;
}

char **make_array(int num)
{
    int ct = 0;
    int co;
    int nub = 0;
    char **pt;
    char ch[100];
    char temp;
    printf("Enter %d words now:\n", num);
    pt = (char **)malloc(num * sizeof(char *));
    while (nub < num)
    {
        for (ct = 0;;ct++)
            {
                temp = getchar();
                if (temp == '\n' || temp == ' ')
                    break;
                else
            }
            printf("%d",ct);
        pt[nub] = (char *)malloc(ct * sizeof(char));
        for (co = 0; co < ct; co++)
        {   
             pt[nub][co]= ch[co];
            ch[co] = '\0';
        } 
        nub++; 
    }
    return pt;
}

void show_word(char **word, int num)
{
    int ct;
    printf("Here are your words:\n");
    for (ct = 0; ct < num; ct++)
        puts(word[ct]);
    for (ct = 0; ct < num; ct++)
        free(word[ct]);
    free(word);
}