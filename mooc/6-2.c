#include <stdio.h>
#include <string.h>

int main()
{
    char line[41];
    int i;

    gets(line);
    for(i = 0; i < strlen(line)-1; ++i){
        if(line[i] >= 'a' && line[i] <= 'z'){
            putchar(line[i]-'a'+'A');
        }
        else if(line[i] >= 'A' && line[i] <= 'Z'){
            putchar(line[i]+'a'-'A');
        }
        else{
            putchar(line[i]);
        }
    }

    printf("\n");

    return 0;
}

