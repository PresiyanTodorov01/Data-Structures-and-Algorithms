#include <iostream>
#include <bits/stdc++.h>

std::vector<int> graph[30];
bool visited[30];
char arr[30];

int generate_graph(int a, int b){
    int counter = 0;

    for(int i = 0; i < a * b; i++){
        if(arr[i] == 'x'){
            counter++;
            continue;
        }

        if(i % b != 0 && arr[i-1] != 'x')
            graph[i].push_back(i - 1);
        if(i % b != b - 1 && arr[i+1] != 'x')
            graph[i].push_back(i + 1);
        if(i - b >= 0 && arr[i-b] != 'x')
            graph[i].push_back(i - b);
        if(i + b < a * b && arr[i+b] != 'x')
            graph[i].push_back(i + b);
    }

    return counter;
}

void dfs(int start, int& counter, int depth, int size){
    visited[start] = 1;

    if(depth == size && arr[start] == 'e'){
        counter++;
    }

    for(auto neighb : graph[start]){
        if(visited[neighb] == 0){
            dfs(neighb, counter, depth + 1, size);
            visited[neighb] = 0;
        }
    }

}

int main()
{
    int a, b;
    std::cin >> a; std::cin >> b;

    int start = 0;

    for(int i = 0; i < a*b; i++){
        visited[i] = 0;

        std::cin >> arr[i];
        if(arr[i] == 's')
            start = i;
    }

    int x = generate_graph(a, b);

    int counter = 0;

    dfs(start, counter, 1, a*b - x);

    printf("%d\n", counter);

    return 0;
}
