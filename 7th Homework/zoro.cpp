#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

std::string get_binary(int num){
    std::string binary_str = "";
    while(num != 0){
        binary_str += '0' + num % 2;
        num /= 2;
    }
    reverse(binary_str.begin(), binary_str.end());
    return binary_str;
}

int convert_to_int(std::string& binary_str){
    int num = 0;
    for(size_t i = 0; i < binary_str.size(); i++)
        num += int(binary_str[i] - '0') * pow(2, binary_str.size() - 1 - i);

    return num;
}

void generate_strings(char digit, std::string masks_binary[], int& _size, int depth){
    if(depth == 0){
        if(digit == '1'){
            masks_binary[0] = "1"; masks_binary[1] = "0"; _size = 2;
        }
        else{
            masks_binary[0] = "0"; _size = 1;
        }
    }
    else{
        if(digit == '1'){

            size_t s = _size;
            for(int i = s - 1; i >= 0; i--){

                masks_binary[_size++] = masks_binary[i] + '0';
                masks_binary[i] += '1';
            }
        }
        else{
            for(size_t i = 0; i < _size; i++){
                masks_binary[i] += '0';
            }
        }
    }
}

std::string arr[1000000];
int arr_output[1000000];

int main(){
    int N; std::cin >> N;
    std::string b_str;
    int input;

    for(int i = 0; i < N; i++){
        std::cin >> input;

        b_str = get_binary(input);

        int arr_size = 0;


        for(size_t i = 0; i < b_str.size(); i++){
            generate_strings(b_str[i], arr, arr_size, i);
        }

        for(int i = 0; i < arr_size; i++){
            arr_output[convert_to_int(arr[i])]++;
        }
    }

    int counter = 0;
    for(int i = 0; i < 1000000; i++){
        if(arr_output[i] != 0)
            counter ++;
    }

    std::cout << counter << std::endl;


    return 0;
}
