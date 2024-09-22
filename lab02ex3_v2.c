#include <stdio.h>

int main(){
    
    int binary, decimal = 0, thousand, hundred, ten, one;

    scanf("%d", &binary);

    one = binary % 10;
    ten = ( (binary - one) % 100 ) / 10;
    hundred = ( (binary - one - ten) % 1000 ) / 100;
    thousand = ( (binary - one - ten - hundred) % 10000 ) / 1000;

    decimal = thousand * 2 * 2 * 2 + hundred * 2 * 2 + ten * 2 + one;

    printf("%d", decimal);

    
    return 0;
}
