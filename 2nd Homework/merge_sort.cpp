#include <iostream>
#include <unistd.h>
#include <time.h>

int inversions = 0;

void merge_sorted(int arr[], int left1, int right1, int left2, int right2){

    int _size = right1 - left1 + (right2 - left2) + 2;
    int temp[_size];

    int counter = 0;
    int i = left1; int j = left2;

    while(true){
        if(i == right1 + 1 && j == right2 + 1)
            break;

        if(i == right1 + 1){
            temp[counter] = arr[j];
            j++;
        }

        else if(j == right2 + 1){
            temp[counter] = arr[i];
            i++;

            inversions += (j - left2);
        }

        else if(arr[i] > arr[j]){
            temp[counter] = arr[j];
            j++;
        }

        else{
            temp[counter] = arr[i];
            i++;

            inversions += (j - left2);
        }

        counter ++;
    }

    for(int i = 0; i < _size; i++){
        arr[i + left1] = temp[i];
    }

}

void merge_sort(int arr[], int left, int right){
    if(left < right){
        int center = (right - left) / 2 + left;

        merge_sort(arr, left, center);
        merge_sort(arr, center + 1, right);

        merge_sorted(arr, left, center, center + 1, right);
    }

}

// works (easy)

const int ARRAY_SIZE = 5;
const int MAX_NUM = 10000;

int main(){
    srand(time(NULL));

    int arr[ARRAY_SIZE];

    for(int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % MAX_NUM;

    for(int i = 0; i < ARRAY_SIZE; i++)
        std::cout << arr[i] << " ";

    merge_sort(arr, 0, ARRAY_SIZE - 1);

    std::cout << "Inversions: " << inversions << std::endl;

    for(int i = 0; i < ARRAY_SIZE; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    return 0;
}
