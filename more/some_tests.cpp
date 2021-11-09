#include <iostream>
#include <map>

bool check_key(std::map<int, int> m, int key)
{
    if (m.count(key) == 0)
        return 0;

    return 1;
}

int arr[500000][2];

void check_keys_map_arr(){
    for(int i = 0; i < 500000; i++){
        arr[i][0] = -1;

    }

    for(int i = 0; i < 500000; i++){
        arr[i][1] = 200;
        arr[i][0] = i;
    }

    for(int i = 0; i < 200000; i++){
        if (arr[i][rand() % 500000] != -1)
            int a = 10;

    }


}

void check_keys_map(){
    std::map<int, int> _map;

    for(int i = 0; i < 500000; i++)
        _map[i] = 200;

    for(int i = 0; i < 20000; i++)
        check_key(_map, rand() % 1000000);

}


int main(){
    srand(time(NULL));

    check_keys_map_arr();


    return 0;

}
