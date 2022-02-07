#include <iostream>
#include <bits/stdc++.h>

int arr_tree_nodes[(int)1e6];

int find(int i){
    if(arr_tree_nodes[i] == -1)
        return i;

    return arr_tree_nodes[i] = find(arr_tree_nodes[i]);
}

bool same_root(int first, int second){
    return(find(first) == find(second));
}

void dsu(int first, int second){
    int root1 = find(first);
    int root2 = find(second);

    if(root1 != root2)
        arr_tree_nodes[root1] = root2;
}

struct Edge{
    int index;
    int from, to;
    long long c1, c2;

    bool operator<(const Edge& other){
        if(this->c1 == other.c1){
            return (this->c2 > other.c2);
        }

        return (this->c1 < other.c1);
    }
};

void kruskal(std::vector<Edge>& edges, int V){
    int size = 0;
    for(auto edge : edges){
        if(!same_root(edge.from, edge.to)){
            dsu(edge.from, edge.to);
            printf("%d\n", edge.index);
            size++;
        }

        if(size == V - 1)
            break;
    }
}

int main(){
    std::fill(arr_tree_nodes, arr_tree_nodes + (int)1e6, -1);

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int V, E; std::cin >> V >> E;
    int from, to;
    long long c1, c2;

    std::vector<Edge> edges(E);

    for(int i = 0; i < E; i++){
        std::cin >> from >> to >> c1 >> c2;
        edges[i] = {i + 1, from ,to, c1, c2};
    }

    std::sort(edges.begin(), edges.end());

    kruskal(edges, V);

    return 0;
}
