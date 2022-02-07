#include <iostream>
#include<bits/stdc++.h>

//graph: INDEX:PAIR(DIST, INDEX) !!

typedef unsigned long long int llu;
typedef unsigned int iu;

struct Tunnel{
    iu index2;
    iu weight;
    iu dist;
};

void generate_graph(int E, std::vector<Tunnel> graph [], iu & _max){
    iu index1, index2, weight ,dist;
    for(int i = 0; i < E; i++){
        std::cin >> index1; std::cin >> index2; std::cin >> weight; std::cin >> dist;
        if(weight > _max)
            _max = weight;
        graph[index1].push_back({index2, weight, dist});
    }

}

int dijkstra(int E, int V, std::vector<Tunnel> graph [], iu _max){
    int start_node = 1;

    std::priority_queue<std::pair<llu, iu>, std::vector<std::pair<llu, iu>>, std::greater<std::pair<llu, iu>> > available;
    available.push(std::make_pair(0, start_node));

    bool visited[V + 1];
    llu arr_dist[V + 1]; arr_dist[start_node] = 0;
    for(int i = 1; i < V + 1; i++){
        visited[i] = 0;
        if(i != start_node){
            arr_dist[i] = LLONG_MAX;
        }
    }

    while(available.size() != 0){
        auto current_node = available.top();
        iu current = current_node.second;
        available.pop();

        if(visited[current] == 1)
            continue;

        visited[current] = 1;

        //if(current == V)
          //  break;

        for(auto node : graph[current]){
            //printf("%u\n", node.weight);
            if(arr_dist[node.index2] > arr_dist[current] + node.dist && node.weight <= _max){
                arr_dist[node.index2] = arr_dist[current] + node.dist;
                available.emplace(arr_dist[current] + node.dist, node.index2);
            }
        }

    }

    if(arr_dist[V] > 4e9)
        return INT_MAX;
    return (int)arr_dist[V];
}

int bs(int E, int V, int max_kg, std::vector<Tunnel> graph [], int K){
    int left = 0;
    int right = max_kg;
    int last_success = -1;
    while(right > left){
        int mid = (left + right) / 2;

        if(K >= dijkstra(E, V, graph, mid)){
            right = mid - 1;
            last_success = mid;
        }
        else{
            left = mid + 1;
        }
    }

    if(left == right)
    {
        if(K >= dijkstra(E, V, graph, left) && left < last_success)
            return left;

    }

    if(last_success == -1){
        if(K >= dijkstra(E, V, graph, max_kg))
            return max_kg;
    }
    return last_success;
}


int main(){

    int E, V, K;
    std::cin >> V; std::cin >> E; std::cin >> K;
    iu max_kg = 0;
    std::vector<Tunnel> graph[V + 1];
    generate_graph(E, graph, max_kg);

    printf("%d\n", bs(E, V, max_kg, graph, K));


    return 0;
}
