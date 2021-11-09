#include <iostream>
#include <unistd.h>

//NOT GOOD ALGO

const int SIZE = 100;

int arr_main[SIZE][3];
int arr_ind[SIZE][2];

int abs(int num1, int num2){
    if (num1 >= num2)
        return num1 - num2;

    return num2 - num1;
}

void merge_sorted_index_arr(int arr[][2], int left1, int right1, int left2, int right2){

    int _size = right1 - left1 + (right2 - left2) + 2;

    int temp[_size][2];


    int counter = 0;
    int i = left1; int j = left2;

    while(true){
        if(i == right1 + 1 && j == right2 + 1)
            break;

        if(i == right1 + 1){
            temp[counter][0] = arr[j][0];
            temp[counter][1] = arr[j][1];
            j++;
        }

        else if(j == right2 + 1){
            temp[counter][0] = arr[i][0];
            temp[counter][1] = arr[i][1];
            i++;
        }

        else if(arr[i][1] > arr[j][1]){
            temp[counter][0] = arr[j][0];
            temp[counter][1] = arr[j][1];
            j++;
        }

        else if(arr[i][1] == arr[j][1]){

            if(abs(arr_main[arr[i][0]][1], arr_main[arr[i][0]][2]) < abs(arr_main[arr[j][0]][1], arr_main[arr[j][0]][2])){
                temp[counter][0] = arr[j][0];
                temp[counter][1] = arr[j][1];
                j++;
            }

            else{
                temp[counter][0] = arr[i][0];
                temp[counter][1] = arr[i][1];
                i++;
            }
        }



        else{
            temp[counter][0] = arr[i][0];
            temp[counter][1] = arr[i][1];
            i++;
        }

        counter ++;
    }

    for(int i = 0; i < _size; i++){
        arr[i + left1][0] = temp[i][0];
        arr[i + left1][1] = temp[i][1];
    }

}

void merge_sort_index_arr(int arr[][2], int left, int right){
    if(left < right){
        int center = (right - left) / 2 + left;

        merge_sort_index_arr(arr, left, center);
        merge_sort_index_arr(arr, center + 1, right);

        merge_sorted_index_arr(arr, left, center, center + 1, right);
    }
}

void merge_sorted(int arr[][3], int compare_by_index, int left1, int right1, int left2, int right2){

    int _size = right1 - left1 + (right2 - left2) + 2;

    int temp[_size][3];


    int counter = 0;
    int i = left1; int j = left2;

    while(true){
        if(i == right1 + 1 && j == right2 + 1)
            break;

        if(i == right1 + 1){
            temp[counter][0] = arr[j][0];
            temp[counter][1] = arr[j][1];
            temp[counter][2] = arr[j][2];
            j++;
        }

        else if(j == right2 + 1){
            temp[counter][0] = arr[i][0];
            temp[counter][1] = arr[i][1];
            temp[counter][2] = arr[i][2];
            i++;
        }

        else if(arr[i][compare_by_index] > arr[j][compare_by_index]){
            temp[counter][0] = arr[j][0];
            temp[counter][1] = arr[j][1];
            temp[counter][2] = arr[j][2];
            j++;
        }

        else if(arr[i][compare_by_index] == arr[j][compare_by_index]){
            int next_comparison = 1;
            if(compare_by_index == 1)
                next_comparison = 2;

            if(arr[i][next_comparison] > arr[j][next_comparison]){
                temp[counter][0] = arr[j][0];
                temp[counter][1] = arr[j][1];
                temp[counter][2] = arr[j][2];
                j++;
            }

            else{
                temp[counter][0] = arr[i][0];
                temp[counter][1] = arr[i][1];
                temp[counter][2] = arr[i][2];
                i++;
            }
        }



        else{
            temp[counter][0] = arr[i][0];
            temp[counter][1] = arr[i][1];
            temp[counter][2] = arr[i][2];
            i++;
        }

        counter ++;
    }

    for(int i = 0; i < _size; i++){
        arr[i + left1][0] = temp[i][0];
        arr[i + left1][1] = temp[i][1];
        arr[i + left1][2] = temp[i][2];
    }

}

void merge_sort(int arr[][3], int compare_by_index, int left, int right){
    if(left < right){
        int center = (right - left) / 2 + left;

        merge_sort(arr, compare_by_index, left, center);
        merge_sort(arr, compare_by_index, center + 1, right);

        merge_sorted(arr, compare_by_index, left, center, center + 1, right);
    }

}

void demons2(){
    merge_sort(arr_main, 1, 0, SIZE - 1);

    for(int i = 0; i < SIZE; i++)
        arr_ind[arr_main[i][0]][1] += i;

    merge_sort(arr_main, 2, 0, SIZE - 1);

    for(int i = 0; i < SIZE; i++)
        arr_ind[arr_main[i][0]][1] += i;

    merge_sort(arr_main, 0, 0, SIZE - 1);

    merge_sort_index_arr(arr_ind, 0, SIZE - 1);

    int counter = 1;
    int current_monster = SIZE - 1;
    int i = SIZE - 1;

    while(i >= 0){
        int ind1 = arr_ind[current_monster][0];
        int ind2 = arr_ind[i][0];

        int our_att = arr_main[ind1][1];
        int our_def = arr_main[ind1][2];


        int enemy_att = arr_main[ind2][1];
        int enemy_def = arr_main[ind2][2];


        if(our_att > enemy_att && our_def > enemy_def){
            counter ++;
            printf("Monster(%d, %d) %d kills monster(%d,%d) %d\n", our_att, our_def, current_monster, enemy_att, enemy_def, i);
            current_monster = i;
        }
        i--;
    }

    std::cout << counter;
}

int main(){
    srand(time(NULL));

    int n = SIZE;
    for(int i = 0; i < SIZE; i++){
        arr_ind[i][0] = i;
        arr_main[i][0] = i; arr_main[i][1] = rand() % SIZE + 1; arr_main[i][2] = rand() % SIZE + 1;
    }

    demons2();



    return 0;
}
