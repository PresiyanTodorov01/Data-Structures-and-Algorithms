#include <iostream>

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
        }

        else if(arr[i] > arr[j]){
            temp[counter] = arr[j];
            j++;
        }

        else{
            temp[counter] = arr[i];
            i++;
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

long long cheap_gifts(){
    long long result = 0;

    int arr_size; std::cin >> arr_size;
    int arr[arr_size];
    for(int i = 0; i < arr_size; i++){
        std::cin >> arr[i];
    }

    int employee_count; std::cin >> employee_count;

    merge_sort(arr, 0 , arr_size - 1);

    for(int i = 0; i < employee_count; i++){
        result += arr[i];
    }

    return result;

}

int main() {

    long long result = cheap_gifts();

    std::cout << result << std::endl;

    return 0;
}
