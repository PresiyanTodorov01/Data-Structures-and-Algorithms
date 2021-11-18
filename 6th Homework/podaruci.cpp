#include <iostream>
#include <vector>

int arr[1000000];
std::vector<int> edges[1000000];

int _search(int index){
    int total = edges[index].size();
    for(int i = 0; i < edges[index].size(); i++){
        total += _search(edges[index][i]);
    }

    arr[index] = total;
    return total;

}

int main(){
    int N; std::cin >> N;
    int x = 0; int y = 0;
    while(x < N - 1 && y < N - 1){
        std::cin >> x; std::cin >> y;
        edges[x].push_back(y);
    }

    _search(0);

    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
