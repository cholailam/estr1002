#include <stdio.h>
#include <math.h>


int main(){
    
    unsigned int number, max, current;
    scanf("%d", & number);

    max = sqrt(number);
    current = number;
    printf("%d: ", number);

    for (int i = 2; i <= max; i++){

        while (current % i == 0){
            
            printf("%d ", i);
            current /= i;

        }

    }

    if (current != 1)
        printf("%d", current);

    return 0;

}
