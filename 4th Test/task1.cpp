#include <iostream>
#include <bits/stdc++.h>

int main() {
    int N; cin >> N;
    int t;

    unsigned long long int current_time = 0;

    struct cmp{
        bool operator () (std::pair<int, int> pair1, std::pair<int, int>pair2){
            return (pair1.first > pair2.first);
        }

    };

    pair<int, int> arr[N]; //start: pair(start, lines)
    priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> heap; //pair(lines, start)

    for (int i = 0; i < N; i++) {
        cin >> t;
        arr[i] = make_pair(i, t);
    }

    int current_i = 0;
    unsigned long long int min = INT_MAX;
    unsigned long long int max = 0;
    unsigned long long int waiting_time;

    while (current_i != N || heap.size() != 0) {

        while (current_i != N && arr[current_i].first <= current_time) {
            heap.push(make_pair(arr[current_i].second, arr[current_i].first));
            current_i++;
        }

        current_time += heap.top().first;

        waiting_time = current_time - heap.top().second;
        if(waiting_time > max)
            max = waiting_time;

        if(waiting_time < min)
            min = waiting_time;

        heap.pop();

    }

    printf("%llu %llu", min, max);

    return 0;
}
