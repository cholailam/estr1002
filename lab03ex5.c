#include <stdio.h>

int main(){
    
    int scientist, alien, guess, hundred, ten, single, convert;

    scanf("%d %d", &scientist, &alien);


    // extract the digits in alien
    hundred = alien / 100;
    ten = ( alien - ( hundred*100 ) )/ 10;
    single = alien - (hundred*100) - (ten*10);



    // find the maximum digit and initialize guess with the digit
    if (hundred >= ten){

        if (hundred >= single)
            guess = hundred;
        else guess = single;

    } else if (single >= hundred){

        if (single >= ten)
            guess = single;
        else guess = ten;

    } else guess = ten;
    
    


    // guess the number system
    convert = guess * guess * hundred + guess * ten + single;
    while (convert <= scientist && (hundred != 0 || ten != 0)){

        if (convert == scientist){
            printf("%d", guess);
            break;
        } 
        guess += 1;
        convert = guess * guess * hundred + guess * ten + single;
    }

    if (convert != scientist)
        printf("CHEATED");
    
    return 0;
}
