#include <iostream>
#include<bits/stdc++.h>


int main() {
    int N; std::cin >> N;
    int in;
    std::vector<int> arr(N);
    std::unordered_map<int, int> _map;
    for(int i = 0; i < N; i++){
        std::cin >> in;
        arr[i] = in;
        _map[in]++;
    }
    for(int i = 0; i < N; i++){
        if(_map[arr[i]] == 1)
            printf("%d ", arr[i]);
    }
    for(int i = 0; i < N; i++){
        if(_map[arr[i]] > 1){
            printf("%d ", arr[i]);
            _map[arr[i]] = -1;
        }

    }
    return 0;
}
