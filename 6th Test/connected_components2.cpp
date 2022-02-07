#include <iostream>
#include<bits/stdc++.h>

void generate_graph(int E, std::vector<int> graph []){
    int index1, index2;
    for(int i = 0; i < E; i++){
        std::cin >> index1; std::cin >> index2;
        graph[index1].push_back(index2);
        graph[index2].push_back(index1);
    }
}

void bfs(int start, std::vector<int> graph [], bool visited[], int component){
    if(visited[start] == 0){
        visited[start] = 1;
        for(auto neighbour : graph[start]){
            bfs(neighbour, graph, visited, component);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int V, E, T;

    std::cin >> T;

    for(int i = 0; i < T; i++){
        std::cin >> V; std::cin >> E;

        std::vector<int> graph [V];
        bool visited[V];

        for(int i = 0; i < V; i++){
            visited[i] = 0;
        }
        generate_graph(E, graph);

        int component = 0;
        for(int i = 0; i < V; i++){
            if(visited[i] == 0){
                bfs(i, graph, visited, component);
                component++;
            }
        }

    printf("%d ", component);
    }

    return 0;
}
