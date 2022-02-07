#include<bits/stdc++.h>
#include <iostream>

void add_edge(int from, int to, std::vector<int> graph[]){
    graph[from].push_back(to);
    graph[to].push_back(from);
}


void bfs(int start, std::vector<int> graph[], std::vector<int>& ans){
    std::queue<int> q;
    int level = 1;

    bool visited[(int)1e6];
    std::fill(visited, visited + (int)1e6, 0);
    visited[start] = 1;

    q.push(start);
    q.push(-1);

    while(q.size() != 1){
        int current = q.front();
        q.pop();

        if(current == -1){
            level++;
            q.push(-1);
            continue;
        }

        for(auto neighbour : graph[current]){
            if(!visited[neighbour]){
                ans[neighbour] = 6 * level;
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
}

int main() {
    int Q; std::cin >> Q;
    int V, E;
    for(int i = 0; i < Q; i++){
        std::cin >> V >> E;
        int in1, in2;
        std::vector<int> graph[V + 1];
        std::vector<int> ans(V + 1);
        std::fill(ans.begin(), ans.end(), -1);
        for(int i = 0; i < E; i++){
            std::cin >> in1 >> in2;
            add_edge(in1, in2, graph);
        }

        std::cin >> in1;

        bfs(in1, graph, ans);


        for(int i = 1; i < V + 1; i++){
            if(i != in1)
                printf("%d ", ans[i]);
        }

        printf("\n");

    }

    return 0;
}
