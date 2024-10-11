#include <stdio.h>
#include <math.h>

int main(){

    char word[65], convert[65], digit = 0, repre = -1, exist = 0;
    unsigned long second = 0;

    scanf("%s", word);

    //convert[0] = '0';
    // assigning a value to each character 
    // count number of digit at the same time
    while (word[digit] != '\0'){

        //printf("repre: %d, [%c]\n", repre, word[digit]);
        // Let the 1st character to represent 1
        if (digit == 0){
            convert[1] = word[digit];
            repre = 1;
            //printf("Assign [1] to [%c]\n", word[digit]);
        }
        
        // Let the second non-repeting character to be 0
        else if (word[digit] != convert[1] && repre == 1){
            convert[0] = word[digit];
            repre = 2;
            //printf("Assign [0] to [%c]\n", word[digit]);

        //assign value to other non-repeting character
        } else if (repre > 1){

            //printf("repre: %d\n", repre);
            // find if the character appeared before
            for (int i = 0; i <= repre; i++){
                if (convert[i] == word[digit]){
                    exist = 1;
                    break;
                }
            }


            // if the character did not appeared before, assign value
            if (!exist){
                convert[repre] = word[digit];
                repre += 1;
                //printf("*Assign [%d] to [%c]\n", repre, word[digit]);
            }

        }
        digit += 1;
        exist = 0;
        
    }

    // add 1 to repre so repre can show the smallest possible base
    if (repre == 1)
        repre += 1;
    printf("repre: %d, digit: %d\n", repre, digit);

    // calculate the time before war
    for (int j = 0; j < digit; j++){

        // find which value does the character represent by convert
        for (int k = 0; k < repre; k++){

            if (word[j] == convert[k]){
                printf("%d * %d^%d\n", k, repre, digit - j - 1);
                second += k * pow(repre, digit - j - 1);
                break;
            }

        }
    }

    printf("%lu", second);
    return 0;

}
