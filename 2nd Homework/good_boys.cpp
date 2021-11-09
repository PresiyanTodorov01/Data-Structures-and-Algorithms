#include <iostream>

void merge_sorted(double arr[], int arr_indexes[], int arr_points[], int left1, int right1, int left2, int right2){

    int _size = right1 - left1 + (right2 - left2) + 2;

    double temp[_size];
    int temp_indexes[_size];
    int temp_points[_size];

    int counter = 0;
    int i = left1; int j = left2;

    while(true){
        if(i == right1 + 1 && j == right2 + 1)
            break;

        if(i == right1 + 1){
            temp[counter] = arr[j];
            temp_indexes[counter] = arr_indexes[j];
            temp_points[counter] = arr_points[j];
            j++;
        }

        else if(j == right2 + 1){
            temp[counter] = arr[i];
            temp_indexes[counter] = arr_indexes[i];
            temp_points[counter] = arr_points[i];
            i++;
        }

        else if(arr[i] > arr[j]){
            temp[counter] = arr[j];
            temp_indexes[counter] = arr_indexes[j];
            temp_points[counter] = arr_points[j];
            j++;
        }

        else if(arr[i] == arr[j]){
            if(arr_points[i] < arr_points[j]){
                temp[counter] = arr[i];
                temp_indexes[counter] = arr_indexes[i];
                temp_points[counter] = arr_points[i];
                i++;
            }
            else{
                temp[counter] = arr[j];
                temp_indexes[counter] = arr_indexes[j];
                temp_points[counter] = arr_points[j];
                j++;
            }
        }

        else{
            temp[counter] = arr[i];
            temp_indexes[counter] = arr_indexes[i];
            temp_points[counter] = arr_points[i];
            i++;
        }

        counter ++;
    }

    for(int i = 0; i < _size; i++){
        arr[i + left1] = temp[i];
        arr_indexes[i + left1] = temp_indexes[i];
        arr_points[i + left1] = temp_points[i];
    }

}

void merge_sort(double arr[], int arr_indexes[], int arr_p[], int left, int right){
    if(left < right){
        int center = (right - left) / 2 + left;

        merge_sort(arr, arr_indexes, arr_p, left, center);
        merge_sort(arr, arr_indexes, arr_p, center + 1, right);

        merge_sorted(arr, arr_indexes, arr_p, left, center, center + 1, right);
    }

}

int* arr_Xi = new int[200000];
double* arr_points = new double[200000];
int* arr_ind = new int[200000];

void points(){
    int N; std::cin >> N;

    int points_x;
    double points_Y;

    for(int i = 0; i < N; i++){
        std::cin >> points_x;
        std::cin >> points_Y;

        double points_total = points_x * points_x / points_Y;

        arr_Xi[i] = points_x;
        arr_points[i] = points_total;
        arr_ind[i] = i;

    }

    merge_sort(arr_points, arr_ind, arr_Xi, 0, N - 1);

    for(int i = N - 1; i >= 0; i--){
        std::cout << arr_ind[i] + 1 << " ";
    }
}

int main(){
    points();

    return 0;
}
