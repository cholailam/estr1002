#include <stdio.h>

int main(){
    
    int length;

    scanf("%d", & length);

    printf("  ^YY\n");
    printf(" {OO >\n");
    printf("(\"\"  |\n");

    for (int i = 1; i <= length; i++){
        
        for (int j = 1; j <= 2+i; j++){
            printf(" ");
        }
        
        printf("\\  \\");
        
        if (i == length)
            printf(" -----");

        printf("\n");

    }

    for (int a = 1; a <= length+2; a++)
        printf(" ");
    printf("(         )\\\n");

    for (int b = 1; b <= length+3; b++)
        printf(" ");
    printf("\\_______/  \\\n");

    for (int c = 1; c <= length+4; c++)
        printf(" ");
    printf("|-| |-|    }\n");

    for (int d = 1; d <= length+4; d++)
        printf(" ");
    printf("|_| |_|\n");



    return 0;
}
