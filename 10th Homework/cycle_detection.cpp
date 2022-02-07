#include<bits/stdc++.h>
#include <iostream>

std::unordered_map<int, std::vector<int>> graph;
std::unordered_map<int, int> visited;

int E;

void generate_graph(){
    int in1, in2;
    for(int i = 0; i < E; i++){
        std::cin >> in1; std::cin >> in2;
        graph[in1 - 1].push_back(in2 - 1);
    }
}

void dfs(int start, bool& cyclic){
    visited[start] = 1;

    for(int neighbour : graph[start]){
        if(visited[neighbour] == 0){
            dfs(neighbour, cyclic);
        }
        else if(visited[neighbour] == 1)
            cyclic = 1;
    }

    visited[start] = 2;
}


bool solve(int N){
    graph = std::unordered_map<int, std::vector<int>>();
    visited = std::unordered_map<int, int>();

    generate_graph();

    bool cyclic = 0;

    for(auto pair : graph){
        if(visited[pair.first] == 0){
            dfs(pair.first, cyclic);
        }
    }

    if(cyclic)
        return 1;

    return 0;
}

int main() {
    int Q; std::cin >> Q;
    for(int i = 0; i < Q; i++){
        std::cin >> E;
        printf("%d ", solve(E));
    }

    return 0;
}
