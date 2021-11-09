#include <iostream>
#include <string>

void merge_sorted(std::string arr[], int arr_indexes[], int left1, int right1, int left2, int right2){

    int _size = right1 - left1 + (right2 - left2) + 2;
    std::string temp[_size];
    int temp_indexes[_size];

    int counter = 0;
    int i = left1; int j = left2;

    while(true){
        if(i == right1 + 1 && j == right2 + 1)
            break;

        if(i == right1 + 1){
            temp[counter] = arr[j];
            temp_indexes[counter] = arr_indexes[j];
            j++;
        }

        else if(j == right2 + 1){
            temp[counter] = arr[i];
            temp_indexes[counter] = arr_indexes[i];
            i++;
        }

        else if(arr[i] > arr[j]){
            temp[counter] = arr[j];
            temp_indexes[counter] = arr_indexes[j];
            j++;
        }

        else{
            temp[counter] = arr[i];
            temp_indexes[counter] = arr_indexes[i];
            i++;
        }

        counter ++;
    }

    for(int i = 0; i < _size; i++){
        arr[i + left1] = temp[i];
        arr_indexes[i + left1] = temp_indexes[i];
    }

}

void merge_sort(std::string arr[], int arr_indexes[], int left, int right){
    if(left < right){
        int center = (right - left) / 2 + left;

        merge_sort(arr, arr_indexes, left, center);
        merge_sort(arr, arr_indexes, center + 1, right);

        merge_sorted(arr, arr_indexes, left, center, center + 1, right);
    }

}

std::string convert_timestamp(std::string& timestamp){
    std::string temp; temp += timestamp[0]; temp += timestamp[1];
    std::string hours = temp;

    temp = ""; temp += timestamp[3]; temp += timestamp[4];
    std::string minutes = temp;

    temp = ""; temp += timestamp[6]; temp += timestamp[7];
    std::string secs = temp;

    temp = ""; temp += timestamp[9]; temp += timestamp[10];
    std::string days = temp;

    temp = ""; temp += timestamp[12]; temp += timestamp[13];
    std::string months = temp;

    temp = ""; for(int i = 15; i < timestamp.size(); i++){
        temp += timestamp[i];
    }
    std::string years = temp;

    return years + "." + months + "." + days + "." + hours + "." + minutes + "." + secs;

}

std::string* arr_timestamps = new std::string[200000];
int* arr_ind = new int[200000];

void logging(){
    int N; std::cin >> N;
    std::string input;
    std::getline(std::cin, input);

    for(int i = 0; i < N; i++){
        std::getline(std::cin, input);

        arr_timestamps[i] = convert_timestamp(input);
        arr_ind[i] = i;

    }

    merge_sort(arr_timestamps, arr_ind, 0, N - 1);

    for(int i = 0; i < N; i++){
        std::cout << arr_ind[i] + 1 << std::endl;
    }
}

int main(){
    logging();

    return 0;

}
