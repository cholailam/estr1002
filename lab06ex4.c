#include <stdio.h>


int main(){

    int move, i = 0, start = -1, j = 0, count_vowel = 0, start_move = 0;
    char word[205], non_vowel[205], all_vowel[205];

    scanf("%s", word);
    scanf("%d", & move);


    // separate the characters to vowel and non-vowel
    while (word[i] != '\0'){

        //printf("[%c]\n", word[i]);
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || \
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'){


            count_vowel += 1;

            //printf("Vowel: [%c]\n", word[i]);
            all_vowel[i] = word[i];
            non_vowel[i] = '0';
    

        } else {

            //printf("non-vowel: [%c]\n", word[i]);
            non_vowel[i] = word[i];
            all_vowel[i] = '0';
            

        }

        i += 1;
    }
    all_vowel[i] = '\0';
    non_vowel[i] = '\0';


    //Last index of character in string = i
    i -= 1;



    // determine where is the first vowel to be printed out
    if (count_vowel > 0)
        move = move % count_vowel;
    if (move > 0)

        for (int k = 0; k <= i; k++){

            if (all_vowel[k] != '0')
                move -= 1;

            if (move == -1){
                start = k;
                break;
            }
            
        }
    else if (move < 0){

        for (int k = i; k >= 0; k--){

            if (all_vowel[k] != '0')
                move += 1;

            if (move == 0){
                start = k;
                break;
            }
            
        }
    } else 
        printf("%s", word);

    //printf("i: %d\n", i);

    //printf("start: %d\n", start);
    
    // Print out the characters
    while (j <= i && start != -1){

        //printf("non: [%c]\n", non_vowel[j]);
        //printf("vow: [%c]\n", all_vowel[start]);


        if (non_vowel[j] != '0')
            printf("%c", non_vowel[j]);
        
        else{
            printf("%c", all_vowel[start]);

            // move the start to the next vowel
            start = (start + 1) % (i + 1);
            while (all_vowel[start] == '0')
                start = (start + 1) % (i + 1);
            
        }
        j += 1;


        
    }



    //printf("[%c]", all_vowel[2]);
    return 0;

}
