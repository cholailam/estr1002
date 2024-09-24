#include <stdio.h>

int main(){
    
    int number, power = 1000000, sum = 0;

    scanf("%d", & number);

    while (power >= 1){

        if (number/ power == 1)
            sum += 1;

        number -= (number/ power) * power;
        power /= 10;    
    }
    

            

    printf("%d", sum);

    return 0;
}
