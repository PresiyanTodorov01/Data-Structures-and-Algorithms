#include <iostream>
#include<bits/stdc++.h>

std::set<int> graph [1000000];

void generate_graph(int E){
    int a, b;
    for(int i = 0 ; i < E; i++){
        std::cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
}

std::vector<int> remove_leafs(std::vector<int>& leafs, int nodes_left){
    nodes_left = nodes_left - leafs.size();

    if(nodes_left == 0){
        return leafs;
    }

    std::vector<int> new_leafs;

    for(auto leaf : leafs){
        int node = (*(graph[leaf].begin()));
        graph[node].erase(leaf);
        if(graph[node].size() == 1)
            new_leafs.push_back(node);
    }

    return remove_leafs(new_leafs, nodes_left);
}

int main(){
    int V; std::cin >> V;
    generate_graph(V - 1);

    std::vector<int> leafs;

    for(int i = 0; i < V; i++){
        if(graph[i].size() == 1)
            leafs.push_back(i);
    }

    std::vector<int> ans = remove_leafs(leafs, V);
    std::sort(ans.begin(), ans.end());

    for(auto el : ans)
        printf("%d ", el);

    printf("\n");

    return 0;
}
