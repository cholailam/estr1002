#include <stdio.h>

int main(){
    
    int decimal;

    scanf("%d", &decimal);

    if (decimal >= 8){
        printf("1");
        decimal -= 8;
    } else printf("0");

    if (decimal >= 4){
        printf("1");
        decimal -= 4;
    } else printf("0");

    if (decimal >= 2){
        printf("1");
        decimal -= 2;
    } else printf("0");

    if (decimal >= 1){
        printf("1");
    } else printf("0");

    return 0;
}
