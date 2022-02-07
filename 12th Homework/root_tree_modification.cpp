#include <iostream>
#include<bits/stdc++.h>

typedef unsigned int iu;

struct Edge {
    iu from;
    iu to;
    iu weight;

    bool operator<(const Edge& compareWith) const {
        return (weight < compareWith.weight);
    }
};

int find(int i, int arr[]){
    if (arr[i] == -1)
        return i;

    return arr[i] = find(arr[i], arr);
}

bool same_root(iu first, iu second, int arr[]){
    return (find(first, arr) == find(second, arr));
}

void dsu(iu first, iu second, int arr[]){
    iu root1 = find(first, arr);
    iu root2 = find(second, arr);

    if(root1 != root2)
        arr[root1] = root2;
}

void dfs(const iu new_root, iu start, std::vector<iu> graph[], int arr[], bool visited[]){
    if(start != new_root)
        arr[start] = new_root;
    if(visited[start] == 0){
        visited[start] = 1;

        for(auto neighbour : graph[start]){
            dfs(new_root, neighbour, graph, arr, visited);
        }
    }
}

void remove_edge(iu V, Edge edge, std::vector<iu> graph[], int arr[]){
    graph[edge.from].erase(std::find(graph[edge.from].begin(), graph[edge.from].end(), edge.to));
    graph[edge.to].erase(std::find(graph[edge.to].begin(), graph[edge.to].end(), edge.from));

    bool visited[V + 1];
    std::fill(visited, visited + V + 1, 0);

    arr[edge.from] = -1;
    arr[edge.to] = -1;

    dfs(edge.from, edge.from, graph, arr, visited);
    dfs(edge.to, edge.to, graph, arr, visited);
}

int main(){
    int E = 5, V = 10;
    std::cin >> V; std::cin >> E;

    iu in1, in2, w;

    std::vector< Edge > _set (E);
    for(int i = 0; i < E; i++){
        std::cin >> in1 >> in2 >> w;
        _set[i] = {in1, in2, w};
    }
    std::sort(_set.begin(), _set.end());

    std::vector<iu> graph[V + 1];

    std::pair<iu, iu> ans = {0, INT_MAX}; // start, end

    int arr_tree_nodes[V + 1];
    std::fill(arr_tree_nodes, arr_tree_nodes + V + 1, -1);

    iu previous_end = 0;

    int _size = 0;

    for(int i = 0; i < E; i++){
        iu start = _set[i].weight;

        int j = i;

        while(_size != V - 1 && j != E){
            if(same_root(_set[j].from, _set[j].to, arr_tree_nodes) == 0){
                graph[_set[j].from].push_back(_set[j].to);
                graph[_set[j].to].push_back(_set[j].from);
                dsu(_set[j].from, _set[j].to, arr_tree_nodes);
                _size++;
            }
            j++;
        }

        if(j == E)
            break;

        j--;

        iu end = _set[j].weight;

        if(end < previous_end)
            end = previous_end;

        previous_end = end;

        if(end - start < ans.second - ans.first){
            ans.first = start;
            ans.second = end;
        }

        remove_edge(V, _set[i], graph, arr_tree_nodes);
        _size--;
    }

    printf("%u %u", ans.first, ans.second);

    return 0;

}
