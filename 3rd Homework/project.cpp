#include <iostream>
#include <algorithm>

int abs(int a, int b){
    if(a >= b)
        return a - b;
    return b - a;
}


int* arr1 = new int[100002];
int* arr2 = new int[100002];

int binary_search(int arr[], int _size, int num, int left, int right){
    if(left > right){
        if(right == -1)
            return arr[0];

        else if(left == _size)
            return arr[_size - 1];

        else{
            if(abs(num, arr[left]) >= abs(num, arr[right]))
                return arr[right];

            else
                return arr[left];
        }
    }

    long middle = (right + left)/2;

    if(arr[middle] == num){
        return num;
    }

    else if(arr[middle] < num)
        return binary_search(arr, _size, num, middle + 1, right);

    else
        return binary_search(arr, _size, num, left, middle - 1);

}

void projects(int n, int m, int arr_diff[], int arr_teams[]){
    std::sort(arr_diff, arr_diff + n - 1);

    for(int i = 0; i < m; i ++){
        std::cout << binary_search(arr_diff, n, arr_teams[i], 0, n - 1) << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n; std::cin >> m;
    for(int i = 0; i < n; i++){
        std::cin >> arr1[i];
    }

    for(int i = 0; i < m; i++){
        std::cin >> arr2[i];
    }

    projects(n, m, arr1, arr2);
}
