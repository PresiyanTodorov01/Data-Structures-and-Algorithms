#include <iostream>
#include <vector>
#include <fstream>

int arr_left[2000000];
int arr_input[2000000];

void bridge_battle(int N, std::ofstream& file){

    int i = 0;
    int input;
    input = arr_input[i];
    while(input < 0){
        i++;
        file << input << " ";
        printf("%d ", input);
        input = arr_input[i];
    }
    int arr_left_size = 0;

    while(i < N){
        while(input >= 0 && i < N){
            arr_left[arr_left_size] = input;
            arr_left_size ++;
            i++;
            if(i == N){
                for(int i = 0; i < arr_left_size; i++){
                    file << arr_left[i] << " ";
                    printf("%d ", arr_left[i]);
                }
                arr_left_size = 0;
            }
            else{
                input = arr_input[i];
            }
        }
        while(input < 0 && i < N){

            if(arr_left_size == 0){
                file << input << " ";
                printf("%d ", input);
                i++;
                if(i != N)
                    input = arr_input[i];
            }
            else{
                int current_left = arr_left[arr_left_size - 1];
                if(current_left > -1 * input){
                    i++;
                    if(i != N)
                        input = arr_input[i];
                }
                else if(current_left == -1 * input){
                    i++;
                    arr_left_size --;
                    if(i != N)
                        input = arr_input[i];
                }
                else{
                    arr_left_size --;
                }
            }
        }

    }
}


const int MAX_NUM = 100;

int main(){
    std::ofstream file("test2.txt", std::ios::app);

    file << "\n";

    srand(time(NULL));
    int N = 100; //std::cin >> N;
    file << N << "\n";
    /*for(int i = 0; i < N; i++)
        std::cin >> arr_input[i];*/

    //arr_input[i] = rand() % (2*MAX_NUM) - MAX_NUM;

    for(int i = 0; i < N; i++){
        if(i % 10 >= 5){
            arr_input[i] = rand() % (MAX_NUM);
        }
        else{
            arr_input[i] = rand() % (MAX_NUM) - MAX_NUM;
        }
        printf("%d ", arr_input[i]);
        file << arr_input[i] << " ";
    }

    file << "\n";
    printf("\n");

    bridge_battle(N, file);

    file.close();

    return 0;
}


