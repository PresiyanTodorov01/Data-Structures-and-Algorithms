#include <iostream>

void first_missing(int arr[], size_t players_count){
    int _max = 0;

    for(int i = 0; i < players_count; i++){
        if (arr[i] > _max)
            _max = arr[i];
    }

    if(_max == 0){
        std::cout << 1 << std::endl;
        return;
    }

    int taken[_max];
    for(int i = 0; i < _max; i++){
        taken[i] = 0;
    }

    for(int i = 0; i < players_count; i++){
        if (arr[i] > 0)
            taken[arr[i]] = 1;
    }

    bool found = 0;

    int i = 1;

    for(i;i < _max; i++){


        if(taken[i] == 0){
            std::cout << i << std::endl;
            found = 1;
            return;
        }
    }

    if(found == 0)
        std::cout << i + 1 << std::endl;
}

int main(){
    int players_count;
    std::cin >> players_count;
    int arr[players_count];
    for(int i = 0; i < players_count; i++){
        std::cin >> arr[i];
    }

    first_missing(arr, players_count);

    return 0;
}
