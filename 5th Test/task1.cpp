#include <iostream>
#include <unordered_map>


int main() {
    int N; std::cin >> N;
    std::string arr[N];
    std::unordered_map<std::string, int> _map;
    std::string in;
    for(int i =0; i < N; i++){
        std::cin >> in;
        _map[in]++;
        arr[i] = in;
    }

    for(int i = 0; i < N; i++){
        printf("%d ", _map[arr[i]]);
    }

    return 0;
}

