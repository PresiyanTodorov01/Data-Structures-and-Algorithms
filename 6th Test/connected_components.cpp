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

void bfs(int start, std::vector<int> graph [], bool visited[], int component, int connected[]){
    if(visited[start] == 0){
        visited[start] = 1;
        connected[start] = component;
        for(auto neighbour : graph[start]){
            bfs(neighbour, graph, visited, component, connected);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int V, E, Q;

    std::cin >> V; std::cin >> E;

    std::vector<int> graph [V + 1];
    bool visited[V + 1];
    int connected[V + 1];
    for(int i = 0; i < V + 1; i++){
        visited[i] = 0;
    }
    generate_graph(E, graph);

    int component = 0;
    for(int i = 0; i < V + 1; i++){
        if(visited[i] == 0){
            bfs(i, graph, visited, component, connected);
            component++;
        }
    }

    std::cin >> Q;
    int in1, in2;

    for(int i = 0; i < Q; i++){
        std::cin >> in1; std::cin >> in2;

        if(connected[in1] == connected[in2])
            printf("1 ");
        else
            printf("0 ");
    }



    return 0;
}
