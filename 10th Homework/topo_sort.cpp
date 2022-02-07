#include <iostream>
#include<bits/stdc++.h>

std::vector<int> graph[26];
int degree[26];

void topo_sort(){
    for(int i = 0; i < 26; i++){
        for(auto neighbour : graph[i]){
            if(degree[neighbour] == -1)
                degree[neighbour] = 1;
            else
                degree[neighbour]++;
        }

    }

    std::queue<int> q;

    for(int i = 0; i < 26; i++){
        if(degree[i] == 0)
            q.push(i);
    }

    while(q.size()){
        int current = q.front();
        q.pop();

        printf("%c ", current + 'a');

        for(auto neighbour : graph[current]){
            degree[neighbour]--;
            if(degree[neighbour] == 0)
                q.push(neighbour);
        }
    }
}

int main() {
    std::fill(degree, degree + 26, -1);

    int N; std::cin >> N;

    std::string last; std::cin >> last;
    std::string _new;

    for(int i = 1; i < N; i++){
        std::cin >> _new;

        int _size = std::min(last.size(), _new.size());

        for(int j = 0; j < _size; j++){
            if(last[j] != _new[j]){
                graph[last[j] - 'a'].push_back(_new[j] - 'a');
                degree[last[j] - 'a'] = 0;
                break;
            }
        }

        last = _new;
    }

    topo_sort();

    return 0;
}
