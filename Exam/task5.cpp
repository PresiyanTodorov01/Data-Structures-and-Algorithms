#include <iostream>
#include <bits/stdc++.h>


std::vector<int> graph[(int)1e6];
int memo[(int)1e6];

void add_edge(int from, int to){
    graph[from].push_back(to);
}

int find(int start){
    if(memo[start] != -1)
        return memo[start];

    int sum = 0;

    for(auto neighbour : graph[start]){
        sum += neighbour + find(neighbour);
    }

    memo[start] = sum;

    return sum;
}

int main() {
    std::fill(memo, memo + (int)1e6, -1);
    int E, Q; std::cin >> E >> Q;
    int in1, in2;
    for(int i = 0; i < E; i++){
        std::cin >> in1 >> in2;
        add_edge(in1, in2);
    }

    for(int i = 0; i < Q; i++){
        std::cin >> in1;
        printf("%d\n", find(in1));
    }

    return 0;
}

