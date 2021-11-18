#include <iostream>
#include <vector>
#include <queue>

std::pair<int, int> arr[2000000];
std::pair<int, int> edges[1000000];

int _search(int index, int current_x, int depth){
    if (arr[1000000 + current_x].first == -1 || (arr[1000000 + current_x].first != -1 && arr[1000000 + current_x].second > depth)){
        arr[1000000 + current_x].first = index;
        arr[1000000 + current_x].second = depth;
    }
    if(edges[index].first != -1){
        _search(edges[index].first, current_x - 1, depth + 1);
    }
    if(edges[index].second != -1){
        _search(edges[index].second, current_x + 1, depth + 1);
    }
}

int main(){
    for(int i = 0; i < 2000000; i++){
        arr[i] = std::pair<int, int>(-1, -1);
    }

    int N; std::cin >> N;
    int left = 0; int right = 0;
    for(int i = 0; i < N; i++){
        std::cin >> left; std::cin >> right;
        edges[i] = std::pair<int, int>(left, right);
    }

    _search(0, 0, 0);

    for(int i = 0; i < 2000000; i++){
        if(arr[i].first != -1){
            printf("%d ", arr[i].first);
        }
    }

    printf("\n");

    return 0;
}

