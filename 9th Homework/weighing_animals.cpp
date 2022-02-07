#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <map>
#include<bits/stdc++.h>

unsigned long long int get_combinations(int n){
    if(n < 3)
        return 0;

    if(n == 3)
        return 1;

    int br = n-2;
    unsigned long long int sum = 0;

    for(int i = 1; i <= n-2; i++){
        sum += br * i;
        br--;
    }

    return sum;
}

int main() {

    std::map<int, int> _map;
    std::unordered_map<int, long long int> available;
    std::unordered_map<int, unsigned long long int> map_count;

    int N; int K; std::cin >> N; std::cin >> K;
    int in;

    unsigned long long int count = 0;
    int counter = 0;

    if(K != 1){
        for(int i = 0; i < N; i++){
            std::cin >> in;

            available[in]++;

            if(in % K == 0){
                map_count[in] += available[in / K];
                if((in / K) % K == 0){
                    count += map_count[in / K];
                }
            }



        }
    }
    else{
        for(int i = 0; i < N; i++){
            std::cin >> in;
            _map[in]++;
        }

        for(auto it : _map){
            count += get_combinations(it.second);
        }
    }

    printf("%llu", count);

    return 0;
}
