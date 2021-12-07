#include<bits/stdc++.h>
#include <iostream>
#include <map>


int main(){
    int N; std::cin >> N;
    int t;
    int f;

    unsigned long long int current_time = 0;

    std::map<int, std::vector<int>> _map;
    std::priority_queue <int, std::vector<int>, std::greater<int> > heap;
    std::pair<std::map<int, std::vector<int>>::iterator, bool> ins;

    for(int i = 0; i < N; i++){
        std::cin >> t; std::cin >> f;
        ins = _map.insert(std::make_pair(t, std::vector<int>(f)));
        if(ins.second == 0){
            (*ins.first).second.push_back(f);
        }
    }

    while(_map.size() != 0 || heap.size() != 0){
        std::map<int, std::vector<int>>::iterator it = _map.begin();

        while(it != _map.end() && (*it).first < current_time){
            for(int i = 0; i < (*it).second.size(); i++){
                heap.push((*it).second[i]);
            }
            _map.erase(it++);
        }

        if(heap.size() == 0){
            int time = (*_map.begin()).first;
            heap.push(time);
            current_time = time;
        }

        else{
            current_time += heap.top();
            printf("%d ", heap.top());
            heap.pop();
        }
    }

    return 0;
}
