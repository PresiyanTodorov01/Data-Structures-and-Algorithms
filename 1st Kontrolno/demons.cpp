#include <iostream>
#include <vector>
#include <map>

const int SIZE = 100;
const int MAX_NUM = 1000000000;

int memo[SIZE + 1] = {-1};

bool check_key(int memo[], int key)
{
    if (memo[key] == -1)
        return 0;

    return 1;
}

int dfs(int** can_beat, int index){
    //std::cout << index << std::endl;
    if(can_beat[index][0] == 0){
        return 1;
    }

    else if(check_key(memo, index) == 1){
        return memo[index];

    }

    else{
        int current_max = 0;
        for(int i = 0; i < can_beat[index][0]; i++){

            int curr = dfs(can_beat, can_beat[index][i + 1]);

            if(1 + curr > current_max)
                current_max = 1 + curr;
        }

        memo[index] = current_max;
        return current_max;
    }
}

void demons(std::pair<int, int>* arr, int** can_beat, int _size)
{
    int counter;

    for(int i = 0; i < _size; i++){
        for(int j = 0; j < _size; j++){
            if(arr[i].first > arr[j].first && arr[i].second > arr[j].second){
                can_beat[i + 1][0]++;
                counter = can_beat[i + 1][0];
                can_beat[i + 1][counter] = j + 1;
            }
        }

    }

    int _max = 0;
    int curr;

    for(int i = 1; i < _size + 1; i++){
        curr = dfs(can_beat, i);

        if (curr > _max)
            _max = curr;
    }

    std::cout << _max;
}


std::pair<int, int>* arr = new std::pair<int, int>[100005];

int main(){

    int n = SIZE; std::cin >> n;
    int in1; int in2;

    int** can_beat = new int*[n + 1];

    srand(time(NULL));

    for(int i = 0; i < n; i++){
        can_beat[i + 1] = new int[n];
        can_beat[i + 1][0] = 0;
        memo[i+1] = -1;
        //in1 = rand() % MAX_NUM;
        //in2 = rand() % MAX_NUM;
        std::cin >> in1; std::cin >> in2;
        arr[i] = std::pair<int, int>(in1, in2);
    }

    demons(arr, can_beat, n);
}
