#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

const int MAX_SIZE = 200001;
const int MAX_NUM = 200001;

int arr_main[MAX_SIZE];
int arr_count_sort[MAX_NUM] = {0};
long _map[MAX_SIZE];
long memo[MAX_SIZE][2];

void count_sort(int arr[], int _size){
    for(int i = 0; i < _size; i++){
        arr_count_sort[arr[i]] ++;
    }

    int arr_counter = 0;

    for(int i = 0; i < MAX_NUM; i++){
        if (arr_count_sort[i] > 0){
            for(int j = 0; j < arr_count_sort[i]; j++){
                arr[arr_counter] = i;
                arr_counter ++;
            }
        }

    }

}

int binary_search(int arr[], int _size, int num, int left, int right){
    if(left > right){
        return right;
    }

    long middle = (right + left)/2;

    if(arr[middle] == num){
        return middle;
    }

    else if(arr[middle] < num)
        return binary_search(arr, _size, num, middle + 1, right);

    else
        return binary_search(arr, _size, num, left, middle - 1);

}

void querry(int arr[], int _size ,int Pi, int Si){
    int index = binary_search(arr, _size, Pi, 0, _size - 1);

    if(index == -1){
        printf("%d\n", 0);
        return;
    }

    while(index != _size - 1 && arr[index] == arr[index + 1]){
        index ++;
    }

    if(Si >= _map[index]){
        printf("%d\n", index + 1);
        return;
    }

    int counter = 0;

    int start_index = index;

    long total = 0;

    while(total <= Si){
        if(memo[index][0] != -1){
            if(total + memo[index][1] <= Si){
                total += memo[index][1];
                counter += index - memo[index][0] + 1;
                index = memo[index][0] - 1;
            }
            else{
                total += arr[index];

                counter ++;
                index --;
            }
        }
        else{
            total += arr[index];

            counter ++;
            index --;
        }
    }
    if(memo[start_index][0] == -1 && start_index - index > 10 && start_index - index < 150000){
        memo[start_index][0] = index + 2;
        memo[start_index][1] = total - arr[index + 1];
    }
    else if(memo[start_index][0] > index + 10 && start_index - index < 150000){
        memo[start_index][0] = index + 2;
        memo[start_index][1] = total - arr[index + 1];
    }

    printf("%d\n", counter - 1);

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n = MAX_SIZE, m = MAX_SIZE, Pi, Si;
    std::cin >> n; std::cin >> m;

    for(int i = 0; i < n; i++){
        std::cin >> arr_main[i];

        memo[i][0] = -1;

    }

    std::sort(arr_main, arr_main + n);

    long total = 0;
    for(int i = 0; i < n; i++){
        total += arr_main[i];
        _map[i] = total;
    }

    for(int i = 0; i < m; i++){
        std::cin >> Si; std::cin >> Pi;
        querry(arr_main, n, Pi, Si);
    }

    return 0;

}
