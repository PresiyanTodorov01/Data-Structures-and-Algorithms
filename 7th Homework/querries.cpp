#include <iostream>
#include <set>
#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    srand(time(NULL));
    int N; //std::cin >> N;
    int input;

    int highest_num = 0;
    int min_diff = INT_MAX;
    std::set<int> _set; _set.insert(0);
    std::set<int>::iterator it;
    std::set<int>::iterator previous;
    std::set<int>::iterator next;
    std::pair<std::set<int>::iterator,bool> ins;

    for(int i = 0; i < N; i++){
        std::cin >> input;
        ins = _set.insert(input);
        if(ins.second){
            it = ins.first;
            if(input > highest_num){
                previous = --it;
                ++it;
                highest_num = input;
                min_diff = std::min(min_diff, *it ^ *previous);
            }
            else{
                previous = --it;
                ++it;
                next = ++it;
                --it;
                min_diff = std::min(min_diff, std::min(*it ^ *previous, *it ^ *next));
            }
        }

        printf("%d\n", min_diff);
    }

    return 0;
}

/*int minXOR(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++){
            int num = arr[i] ^ arr[j];
            min_xor = std::min(min_xor, arr[i] ^ arr[j]);
            std::cout << num << std::endl;
        }

    return min_xor;
}*/
