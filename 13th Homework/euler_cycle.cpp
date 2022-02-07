#include <iostream>
#include<bits/stdc++.h>

void generate_graph(std::unordered_map<int, std::vector<int>>& graph, int E){
    int a, b;
    for(int i = 0; i < E; i++){
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int start, std::unordered_map<int, std::vector<int>>& graph, std::unordered_map<int, bool>& visited){
    if(visited[start] == 0){
        visited[start] = 1;

        for(auto el : graph[start]){
            dfs(el, graph, visited);
        }
    }
}

bool connected(std::unordered_map<int, std::vector<int>>& graph){

    std::unordered_map<int, bool> visited;

    int start = (*graph.begin()).first;

    dfs(start, graph, visited);

    for(auto map_pair : graph){
        if(visited[map_pair.first] != 1)
            return 0;
    }

    return 1;
}

int main() {
    int Q;
    std:: cin >> Q;

    for(int i = 0; i < Q; i++){
        int V, E;
        std::cin >> V >> E;
        std::unordered_map<int, std::vector<int>> graph;
        generate_graph(graph, E);

        int odds_count = 0;

        if(connected(graph) == 0 || V != graph.size()){
            printf("none\n");
            continue;
        }

        for(auto map_pair : graph){
            if(map_pair.second.size() % 2 == 1)
                odds_count ++;
        }

        if(odds_count == 0)
            printf("ecycle\n");

        else if(odds_count == 2)
            printf("epath\n");

        else
            printf("none\n");
    }


    return 0;
}
