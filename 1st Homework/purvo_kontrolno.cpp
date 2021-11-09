#include <iostream>
#include <string>
#include <cstring>


void update_left_to_right(int arr[], size_t arr_size){
    for(int i = 0; i < arr_size; i++){
        if(arr[i] == -1 && i != arr_size - 1){
            int distance = 0;
            while(i < arr_size - 1 && arr[i+1] != -1){
                distance ++;
                i++;

                arr[i] = distance;

            }
        }

    }
}


void update_right_to_left(int arr[], size_t arr_size){
    for(int i = arr_size - 1; i >= 0; i--){
        if(arr[i] == -1 && i != 0){
            int distance = 0;
            while(i > 0 && arr[i-1] != -1){
                distance ++;
                i--;
                if(distance < arr[i] || arr[i] == 0){
                    arr[i] = distance;
                }

            }
        }

    }
}


void solve(std::string input_str, char input_char){
    const size_t str_size = input_str.size();

    int arr[str_size];

    for(int i = 0; i < str_size; i++){
        if(input_str[i] == input_char){
            arr[i] = -1;
        }

        else{
            arr[i] = 0;
        }
    }

    update_left_to_right(arr, str_size);

    update_right_to_left(arr, str_size);

    for(int i = 0; i < str_size; i++){
        if(arr[i] != -1)
            std::cout << arr[i] << " ";
        else
            std::cout << 0 << " ";
    }

    std::cout << std::endl;


}

int main(){
    std::string input_str;
    char input_char;
    std::cin >> input_str;
    std::cin >> input_char;

    solve(input_str, input_char);

    return 0;
}
