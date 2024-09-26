#include <stdio.h>
#include <math.h>


int main(){
    
    unsigned int number, max, pass = 1;
    scanf("%d", & number);

    max = sqrt(number);

    for (int i = 2; i <= max; i++){

        if (number % i == 0){
            
            pass = 0;
            printf("no\n");
            break;
        }

    }

    if (pass)
        printf("yes");
        
    return 0;

}
