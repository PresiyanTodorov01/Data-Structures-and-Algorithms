#include <iostream>
#include <string>
#include <vector>

void unique_lekcii(std::string& input){
    int arr_letters[255] = {0};
    int arr_last_indexes[255];
    std::vector<int> indexes;

    for(size_t i = 0; i < input.size(); i++){
        if(arr_letters[int(input[i])] == 0){
            indexes.push_back(i);
            arr_last_indexes[int(input[i])] = i;
            arr_letters[int(input[i])] ++;
        }
        else if(arr_letters[int(input[i])] == 1){
            int index = -1;
            for(int j = 0; j < indexes.size(); j++){
                if(indexes[j] == arr_last_indexes[int(input[i])]){
                    index = j;
                    break;
                }
            }
            indexes.erase(indexes.begin() + index);
            arr_letters[int(input[i])] ++;
        }
    }

    for(int j = 0; j < indexes.size(); j++)
        std::cout << indexes[j] << " ";

}

int main(){

    std::string input; std::cin >> input;

    unique_lekcii(input);

    return 0;
}
