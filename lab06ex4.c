#include <stdio.h>


int main(){

    int move, i = 0, start = -1, j = 0;
    char word[205], non_vowel[205], all_vowel[205];

    scanf("%s", word);
    scanf("%d", & move);


    // separate the characters to vowel and non-vowel
    while (word[i] != '\0'){

        //printf("[%c]\n", word[i]);
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || \
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'){


            // determine where is the first vowel 
            if (start == -1)
                start = i;

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



    start = start + move + i - 1;
    // Print out the characters
    while (j <= i){

        if (non_vowel[j] != '\0')
            printf("%c", non_vowel[j]);
        else {



        }
        j += 1;
    }



    //printf("[%c]", all_vowel[2]);
    return 0;

}
