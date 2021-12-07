#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    int t;
    int f;

    unsigned long long int current_time = 0;
    unsigned long long int total_waiting_time = 0;

    pair<int, int> arr[N]; //start: pair(start, lines)
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > heap; //pair(lines, start)

    for (int i = 0; i < N; i++) {
        cin >> t; cin >> f;
        arr[i] = make_pair(f, t);
    }

    sort(arr, arr + N);

    int current_i = 0;

    while (current_i != N || heap.size() != 0) {

        while (current_i != N && arr[current_i].first <= current_time) {
            heap.push(make_pair(arr[current_i].second, arr[current_i].first));
            current_i++;
        }

        if (heap.size() == 0) {
            int time = arr[current_i].first;
            heap.push(make_pair(arr[current_i].second, arr[current_i].first));
            current_i++;
            current_time = time;
        }

        else {
            current_time += heap.top().first;
            total_waiting_time += current_time - heap.top().second;
            heap.pop();
        }
    }

    printf("%d\n", total_waiting_time/N);

    return 0;
}
