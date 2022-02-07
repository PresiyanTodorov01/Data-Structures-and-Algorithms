#include <iostream>
#include<bits/stdc++.h>

typedef unsigned long long int llu;
typedef unsigned int iu;
int mod = 1e9 + 7;

void generate_graph(int E, std::vector<std::pair<llu, iu>> graph []){
    int index1, index2, dist;
    for(int i = 0; i < E; i++){
        std::cin >> index1; std::cin >> index2; std::cin >> dist;
        graph[index1].push_back(std::make_pair(dist, index2));
    }

}

void dijkstra(int E, int V){
    std::vector<std::pair<llu, iu>> graph[V + 1];

    generate_graph(E, graph);

    int start_node = 1;

    std::set<std::pair<llu, iu>> available;
    available.insert(std::make_pair(0, start_node));

    llu arr_dist[V + 1]; arr_dist[start_node] = 0;
    int arr_counter[V + 1];
    for(int i = 1; i < V + 1; i++){
        if(i != start_node){
            arr_dist[i] = LLONG_MAX;
        }
        arr_counter[i] = 1;
    }

    while(available.size() != 0){
        auto current_node = *available.begin();
        iu current = current_node.second;
        available.erase(current_node);

        for(auto node : graph[current]){
            if(arr_dist[node.second] == arr_dist[current] + node.first){
                arr_counter[node.second] += arr_counter[current];
                arr_counter[node.second] %= mod;
            }
            if(arr_dist[node.second] > arr_dist[current] + node.first){
                available.erase(std::make_pair(arr_dist[node.second], node.second));
                arr_dist[node.second] = arr_dist[current] + node.first;
                arr_counter[node.second] = arr_counter[current];
                available.insert(std::make_pair(arr_dist[current] + node.first, node.second));
            }
        }

    }

    if(arr_dist[V] != LLONG_MAX)
        printf("%llu %d\n", arr_dist[V], arr_counter[V]);

    else
        printf("-1 0\n");

}

int main(){

    int n, m;

    std::cin >> n; std::cin >> m;
    dijkstra(m, n);


    return 0;
}
