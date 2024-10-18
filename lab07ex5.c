#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// cslculste the total of index from start to end (without end) in line
int cal_score(int start, int end, char line[100005]){

    int score = 0;
    for (int i = start; i < end; i++){
        score += line[i] - 'a' + 1;
    }
    return score;

}


int find_pos(int start, char line[100005], int avg_score, int avg_pos, int length, int remain_part){

    int min_diff, current_diff, best_pos, current_pos, previous_diff = 26 * 100001;
    

    // initialize 


    best_pos = current_pos = start + avg_pos + 1;
    if (current_pos >= length){
        best_pos -= 1;
        current_pos -= 1;
    }
    //printf("Avg pos: %d\n", avg_pos);

    
    min_diff = previous_diff;
    current_diff = cal_score(start, current_diff, line) - avg_score; 



    while (previous_diff != current_diff && abs(min_diff) > abs(current_diff) ){
        //printf("Part [%d] Current_diff of pos %d: %d\n", remain_part, current_pos, current_diff);

        // check if current_diff is smaller than min_diff, so it is the better position
        if ( abs(min_diff) > abs(current_diff) ){
            best_pos = current_pos;
            min_diff = current_diff;
        }


        // check the current_diff to determine which side can have better position
        if (current_diff == 0)
            return current_pos;
        
        else if (current_diff < 0 && (current_pos + remain_part) <= length) // = calculated score is smaller than avg_score
            // can try try more letter
            current_pos += 1;           


        else if (current_diff > 0 && current_pos - 1 > start)
            // try fewer letter
            current_pos -= 1;       
        
        previous_diff = current_diff;
        current_diff = cal_score(start, current_pos, line) - avg_score;

        //printf("Part [%d] Current_diff of pos %d: %d\n\n", remain_part, current_pos, current_diff);    
    }
    //printf("Best pos: %d\n", best_pos);
    return best_pos;    

}



int main(){

    char line[100005];
    int partition, total_score, length = 0, avg_score, avg_pos, part_pos[100005], num_pos = 0, start_pos = 0, max_score = 0, check_score;
    // part_pos: stores the index of 1st letter in each partition
    // num_pos: index of 1st position assigned in part_pos
    // start_pos: starting position of each partition

    scanf("%s", line);
    scanf("%d", & partition);

    // find the largest index of line
    while (line[length] != '\0')
        length += 1;
    length -= 1;


    total_score = cal_score(0, length+1, line);
    //printf("Total: %d\n", total_score);

    avg_score = total_score / partition;
    avg_pos = (length + 1) / partition; 




    part_pos[num_pos] = 0;
    while (num_pos + 1 < partition){
        num_pos += 1;
        part_pos[num_pos] = find_pos(start_pos, line, avg_score +1, avg_pos, length, partition - num_pos);
        start_pos = part_pos[num_pos];    
    }
    part_pos[num_pos+1] = length+1;




    //for (int k = 0; k <= num_pos; k++)
      //  printf("=> %d\n", part_pos[k]);




    // find maximum score among partitioned word
    max_score = cal_score(part_pos[0], part_pos[1], line);
    for (int j = 1; j < partition; j++){

        //printf("current pos: %d\n", part_pos[j]);
        check_score = cal_score(part_pos[j], part_pos[j+1], line);
        //printf("check_score: %d\n", check_score);
        if (max_score < check_score)
            max_score = check_score;

    }
    printf("%d\n", max_score);

    return 0;

}
