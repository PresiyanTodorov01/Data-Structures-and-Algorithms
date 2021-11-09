#include <iostream>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

const short HIGHEST_NUM = 100;
const short ARRAY_SIZE = 20;

int arrange (int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = (left - 1);

    for (int j = left; j < right; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

int random_num_arrange(int arr[], int left, int right) {
    int pivot = rand() % (right - left) + left;
    swap(&arr[right], &arr[pivot]);
    return arrange(arr, left, right);
}

void quick_sort(int arr[], int left, int right){
    if(left < right){
        int pivot = random_num_arrange(arr, left, right);

        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);

    }

}

int quick_select_lowest_knum = -1;
int quick_select_highest_knum = -1;

void quick_select_lowest(int arr[], int p, int left, int right){
    int k = p - 1;
    if(left < right){
        int pivot = random_num_arrange(arr, left, right);

        if(pivot == k){
            quick_select_lowest_knum = arr[pivot];
        }

        else if(pivot > k){
            quick_select_lowest(arr, p, left, pivot - 1);
        }
        else{
            quick_select_lowest(arr, p, pivot + 1, right);
        }
    }

    else if(left == right){
        quick_select_lowest_knum = arr[left];
    }

}

void quick_select_highest(int arr[], int p, int _size, int left, int right){
    int k = _size - p;
    if(left < right){
        int pivot = random_num_arrange(arr, left, right);

        if(pivot == k){
            quick_select_highest_knum = arr[pivot];
        }

        else if(pivot > k){
            quick_select_highest(arr, p, _size, left, pivot - 1);
        }
        else{
            quick_select_highest(arr, p, _size, pivot + 1, right);
        }
    }

    else if(left == right){
        quick_select_highest_knum = arr[left];
    }

}

// END QUICK SORT __________________________________________________________________________________________

void swap_pair(std::pair<int, int>* a, std::pair<int, int>* b)
{
    std::pair<int, int> t = *a;
    *a = *b;
    *b = t;
}

int pair_arrange (std::pair<int, int> arr[], int left, int right)
{
    int pivot = arr[right].first;
    int i = (left - 1);

    for (int j = left; j < right; j++)
    {

        if (arr[j].first <= pivot)
        {
            i++;
            swap_pair(&arr[i], &arr[j]);
        }
    }
    swap_pair(&arr[i + 1], &arr[right]);
    return i + 1;
}

int pair_random_num_arrange(std::pair<int, int> arr[], int left, int right) {
    int pivot = rand() % (right - left) + left;
    swap_pair(&arr[right], &arr[pivot]);
    return pair_arrange(arr, left, right);
}

int operations = 0;
int index = -1;

void pair_quick_search(std::pair<int, int> arr[], int num, int left, int right){
    if(left < right){
        operations ++;
        int pivot = pair_random_num_arrange(arr, left, right);

        if(arr[pivot].first == num){
            index = arr[pivot].second;
        }

        else if(arr[pivot].first < num)
            pair_quick_search(arr, num, pivot + 1, right);
        else
            pair_quick_search(arr, num, left, pivot - 1);
    }

    else if(left = right){
        index = arr[left].second;
    }

}

// END QUICK SEARCH ___________________________________________________________________________________

int main(){
    srand(time(NULL));

    int arr2[ARRAY_SIZE];

    for(int i = 0; i < ARRAY_SIZE; i++){
        arr2[i] = rand() % HIGHEST_NUM;
    }

    int k = 4;

    quick_select_lowest(arr2, k, 0, ARRAY_SIZE - 1);

    for(int i = 0; i < ARRAY_SIZE; i++){
        std::cout << arr2[i] << " ";
    }

    std::cout << std::endl;

    quick_select_highest(arr2, k, ARRAY_SIZE, 0, ARRAY_SIZE - 1);

    for(int i = 0; i < ARRAY_SIZE; i++){
        std::cout << arr2[i] << " ";
    }

    std::cout << k <<" lowest number is: " << quick_select_lowest_knum << std::endl;
    std::cout << k <<" highest number is: " << quick_select_highest_knum << std::endl;

    return 0;

}
