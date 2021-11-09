#include <iostream>

bool binary_search(int arr[], int num, int left, int right){
    if(left > right)
        return false;

    long middle = (right + left)/2;

    if(arr[middle] == num){
        return true;
    }

    else if(arr[middle] < num)
        return binary_search(arr, num, middle + 1, right);

    else
        return binary_search(arr, num, left, middle - 1);

}

int main(){

    int arr[10] = {1, 5, 12, 15, 17, 25, 33, 37, 90, 100};

    std::cout << binary_search(arr, 16, 0, 9) << std::endl;

    return 0;


}
