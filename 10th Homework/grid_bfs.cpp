#include <iostream>
#include<bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N; std::cin >> M;
    int graph[N][M];
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M; j++)
            graph[i][j] = 0;
    }
    int T, K, in1, in2;
    std::cin >> T; std::cin >> K;

    std::queue<std::pair<int, int>> q;

    for(int i = 0; i < K; i++){
        std::cin >> in1; std::cin >> in2;
        q.push({in1 - 1, in2 - 1});
        graph[in1 - 1][in2 - 1] = 1;
    }

    int counter = K;

    for(int i = 0; i < T; i++){
        std::queue<std::pair<int, int>> new_q;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.first > 0 && graph[curr.first - 1][curr.second] == 0){
                new_q.push({curr.first - 1, curr.second});
                counter++;
                graph[curr.first - 1][curr.second] = 1;
            }

            if(curr.first < N - 1 && graph[curr.first + 1][curr.second] == 0){
                new_q.push({curr.first + 1, curr.second});
                counter++;
                graph[curr.first + 1][curr.second] = 1;
            }

            if(curr.second > 0 && graph[curr.first][curr.second - 1] == 0){
                new_q.push({curr.first, curr.second - 1});
                counter++;
                graph[curr.first][curr.second - 1] = 1;
            }

            if(curr.second < M - 1 && graph[curr.first][curr.second + 1] == 0){
                new_q.push({curr.first, curr.second + 1});
                counter++;
                graph[curr.first][curr.second + 1] = 1;
            }



        }

        q = new_q;
    }

    printf("%d\n", N*M - counter);

    return 0;
}
