#include <iostream>
#include <unordered_map>


int main() {
    int N; std::cin >> N;
    int arr[N];
    int in;
    std::unordered_map<int, int> _map;

    for(int i = 0; i < N; i++){
        std::cin >> in;
        _map[in]++;
        arr[i] = in;
    }

    int sum = 0;

    for(int i = 0; i < N; i++){
        if(_map[arr[i]] % 2 == 1){
            sum += arr[i];
        }
    }

    printf("%d\n", sum);

    return 0;
}
