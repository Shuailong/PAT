#include <stdio.h>
#include <string.h>

int main()
{
    char line[81];
    int i;

    gets(line);
    for(i = strlen(line)-2; i >= 0; --i){
        putchar(line[i]);
    }
    putchar('\n');

    return 0;
}
