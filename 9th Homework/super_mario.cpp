#include <iostream>
#include <unordered_map>


int main() {
    int N; std::cin >> N;
    std::unordered_map<int, int> keys;
    int total_destroyed = 0;

    int in2;

    int keys_in[N];

    for(int i = 0; i < N; i++){
        std::cin >> keys_in[i];
    }

    for(int i = 0; i < N; i++){
        keys[keys_in[i]]++;

        std::cin >> in2;

        if(keys[in2] == 0)
            total_destroyed++;
        else
            keys[in2]--;
    }

    printf("%d\n", total_destroyed);
}
