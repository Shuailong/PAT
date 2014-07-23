#include <stdio.h>

int main()
{
    char ch;
    char prevch;
    int wordcount = 0;

    prevch = ' ';
    do{
        scanf("%c", &ch);
        if(ch != ' '){
            ++wordcount;
        }
        if(ch == ' ' && prevch != ' '){
            printf("%d ", wordcount);
            wordcount = 0;
        }
        prevch = ch;
    }while(ch != '.');

    if(wordcount-1 != 0){
        printf("%d\n", wordcount-1);
    }
    else{
        printf("\n");
    }

    return 0;
}
    