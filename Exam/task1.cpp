#include <bits/stdc++.h>
#include <iostream>

std::unordered_map<std::string, int> ans;

using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M; std::cin >> N >> M;
    std::string in;
    for(int i = 0; i < N; i++){

        std::string str = "";
        for(int j = 0; j < M; j++){
            std::cin >> in;
            str += in;
        }
        ans[str]++;
    }
    int counter = 0;
    for(auto _pair : ans){
        if(_pair.second == 1)
            counter++;
    }

    printf("%d\n", counter);

    return 0;
}
