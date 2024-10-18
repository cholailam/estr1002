#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int binary_search(int target, int ordered_tm[10005], int size){

    int left = 0, right = size - 1, middle;

    while (left <= right){

        middle = (left + right) / 2;
        
        if (ordered_tm[middle] == target)
            return 1;
        else if (ordered_tm[middle] > target)
            right = middle - 1;
        else
            left = middle + 1;

    }
    return 0;
}

int cal_score(int start, int end, char line[100005]){

    int score = 0;
    for (int i = start; i <= end; i++){
        score += line[i] - 'a' + 1;
    }
    return score;

}


int find_pos(int start, char line[100005], int avg_score, int avg_pos){

    int min_diff, current_diff;
    min_diff = cal_score(start, avg_pos, line);

    while 
}

int main(){

    char line[100005];
    int partition, total_score, length = 0, avg_score, avg_pos, part_pos[100005];
    //part_pos: stores the index of 1st letter in each partition

    scanf("%s", line);
    scanf("%d", & partition);

    // find the largest index of line
    while (line[length] != '\0')
        length += 1;
    length -= 1;


    total_score = cal_score(0, length, line);
    printf("Total: %d\n", total_score);

    avg_score = total_score / partition;
    avg_pos = (length + 1) / partition; 

    part_pos[0] = 0;

    return 0;

}
