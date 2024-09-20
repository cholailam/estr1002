#include <stdio.h>

int main(){
    
    int scientist, alien, guess, hundred, ten, single, convert;

    scanf("%d %d", &scientist, &alien);


    // extract the digits in alien
    hundred = alien / 100;
    ten = ( alien - ( hundred*100 ) )/ 10;
    single = alien - (hundred*100) - (ten*10);



    // find the maximum digit and initialize guess with the digit
    if ( (hundred >= ten) && (hundred >= single) )
        guess = hundred;

    else if ( (single >= hundred) && (single >= ten) )
        guess = single;

    else guess = ten;
    
    


    // guess the number system
    convert = guess * guess * hundred + guess * ten + single;
    while (convert <= scientist && (hundred != 0 || ten != 0) && (scientist != alien)){

        if (convert == scientist){
            printf("%d\n", guess);
            break;
        } 
        guess += 1;
        convert = guess * guess * hundred + guess * ten + single;
    }

    if (scientist == alien)
        printf("10\n");
    else if (convert != scientist)
        printf("CHEATED\n");

    
    return 0;
}
