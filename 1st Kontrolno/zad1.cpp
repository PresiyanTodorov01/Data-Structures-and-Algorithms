#include <iostream>

int seen[80000];

void solution(){
    int N; std::cin >> N;
    int num;

    for(int i = 0; i < 80000; i++){
        seen[i] = 0;
    }

    for(int i = 0; i < N; i++){
        std::cin >> num;
        seen[num] ++;
    }

    for(int i = 0; i < 80000; i++){
        if(seen[i] > 0){
            std::cout << i << " ";
        }
    }
}

int main(){

    solution();


    return 0;
}
