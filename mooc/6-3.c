#include <stdio.h>

int main()
{
    char ch;
    char prevch;
    int wordcount = 0;
    int flag = 0;

    prevch = ' ';
    do{
        scanf("%c", &ch);
        if(ch != ' '){
            ++wordcount;
        }
        if(flag && ch == ' ' && prevch != ' '){
            printf(" ");
        }
        if(ch == ' ' && prevch != ' '){
            printf("%d", wordcount);
            flag = 1;
            wordcount = 0;
        }
        prevch = ch;
    }while(ch != '.');

    if(flag && wordcount-1 != 0){
        printf(" ");
    }
    if(wordcount-1 != 0){
        printf("%d\n", wordcount-1);
    }
    else{
        printf("\n");
    }

    return 0;
}
    