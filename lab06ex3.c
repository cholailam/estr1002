#include <stdio.h>
#include <ctype.h>


int main(){

    int single = 0, check = 0, flag = 0;
    char word[1005], anag[1005];

    fgets(word, 1005, stdin);
    fgets(anag, 1005, stdin);




    // convert all character in anag to lowercase
    while (anag[single] != '\0'){
        //printf("Convert [%c] ", anag[single]);
        anag[single] = tolower(anag[single]);
        //printf("to [%c]\n", anag[single]);
        single += 1;
    }

    single = 0;

    



    // find the existance of each character in word in anag
    // if not exist can confirm not anag
    // if exist can change it to '0'
    while (word[single] != '\0'){

        word[single] = tolower(word[single]);
        flag = 0;

        //printf("target: [%c]\n", word[single]);
        // find same character in anag
        if (word[single] != ' ' && word[single] != '\n'){
            while (anag[check] != '\0'){

                //printf("compare [%c]\n", anag[check]);
                if (anag[check] == word[single]){
                    anag[check] = '0';
                    flag = 1;
                    break;
                }
                check += 1;

            }
        } else flag = 1;


        // determine did we find the existance
        if (!flag)
            break;
        check = 0;
        single += 1;



    }

    if (!flag)
        printf("no");
    else printf("yes");
    
    return 0;

}
