#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(){

    char line[205], word_index[205];
    int word;
    char* token;
    fgets(line, 205, stdin);
    fgets(word_index, 205, stdin);

    //printf("[%c]\n", word_index[2]);

    token = strtok(word_index, " ");
    
    while (token != NULL){
        //printf("[%s]\n", token);
        word = atoi(token);
        printf("%c", tolower( line[word -1] ));
        token = strtok(NULL, " ");
    }
    

    return 0;

}
