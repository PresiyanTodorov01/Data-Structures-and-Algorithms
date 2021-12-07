#include <iostream>
#include <bits/stdc++.h>
#include <set>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;std::cin >> N;
    int arr_input[N];
    int arr_output[N];
    int k; std::cin >> k;
    int input;
    std::set<int> _set;
    std::set<int>::iterator it;
    std::pair<std::set<int>::iterator,bool> ins;

    for(int i = 0; i < N; i++){
        std::cin >> input;
        arr_input[i] = input;
    }

    for(int i = N - 1; i >= 0; i--){
        ins = _set.insert(arr_input[i]);
        it = ins.first;

        while(it != _set.end()){
            it++;
            if(k >= *it - arr_input[i]){
                if(arr_input[i] - *it != 0)
                    arr_output[*it] = i;
            }
            else{
                break;
            }
        }
    }

    for (auto iter : _set){
        arr_output[iter] = -1;
    }

    for(int i = 0; i < N; i++){
        printf("%d ", arr_output[i]);
    }

    return 0;
}
