#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

template <class T, class S, class C>
S& Container(priority_queue<T, S, C>& q) {
    struct HackedQueue : private priority_queue<T, S, C> {
        static S& Container(priority_queue<T, S, C>& q) {
            return q.*&HackedQueue::c;
        }
    };
    return HackedQueue::Container(q);
}


int main() {
    int N; std::cin >> N;
    int K; std::cin >> K;
    int t, l;

    int arr_output[K];

    for(int i = 0; i < K; i++){
        arr_output[i] = 0;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> heap_busy; //pair(finish_time, index)
    priority_queue<int, vector<int>, greater<int>> heap_bigger;//(index)
    priority_queue<int, vector<int>, greater<int>> heap_smaller;//(index, finish_time)

    for(int i = 0; i < K; i++){
        heap_bigger.push(i);
    }

    for(int i = 0; i < N; i++){
        if(heap_smaller.size() != 0 && heap_smaller.top() == i%K){
            heap_bigger.push(heap_smaller.top());
            heap_smaller.pop();
        }

        cin >> t; cin >> l;

        //Manage busy guys
        while(heap_busy.size() != 0){
            if(heap_busy.top().first <= t){
                pair<int, int> top = heap_busy.top();
                heap_busy.pop();
                if(top.second >= i % K){
                    heap_bigger.push(top.second);
                }
                else{
                    heap_smaller.push(top.second);
                }
            }
            else{
                break;
            }
        }

        printf("i: %d\n", i);
        vector<pair<int, int>>& copy1 = Container(heap_busy);
        printf("HEAP BUSY: ");
        for(size_t i = 0; i < copy1.size(); i++){
            printf("(%d, %d) ", copy1[i].second, copy1[i].first);
        }
        printf("\n");

        vector<int>& copy2 = Container(heap_bigger);
        printf("HEAP BIGGER: ");
        for(size_t i = 0; i < copy2.size(); i++){
            printf("%d ", copy2[i]);
        }
        printf("\n");

        vector<int>& copy3 = Container(heap_smaller);
        printf("HEAP SMALLER: ");
        for(size_t i = 0; i < copy3.size(); i++){
            printf("%d ", copy3[i]);
        }
        printf("\n");

        // Look into bigger indexes
        if(heap_bigger.size() != 0){

            int call_taker = heap_bigger.top();
            heap_bigger.pop();
            heap_busy.push(make_pair(t+l, call_taker));
            arr_output[call_taker]++;
        }

        //Look into smaller indexes
        else if(heap_smaller.size() != 0){
            int call_taker = heap_smaller.top();
            heap_smaller.pop();
            heap_busy.push(make_pair(t+l, call_taker));
            arr_output[call_taker]++;
        }


    }

    int biggest = -1;
    vector<int> out;
    for(int i = 0; i < K; i++){
        if(arr_output[i] > biggest){
            out.clear();
            out.push_back(i);
            biggest = arr_output[i];
        }
        else if(arr_output[i] == biggest){
            out.push_back(i);
        }
    }

    for(size_t i; i < out.size(); i++){
        printf("%d ", out[i]);
    }
}
