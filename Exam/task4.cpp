#include <iostream>
#include <bits/stdc++.h>

unsigned long long int N;
int K;
std::vector<int> chefs;

unsigned long long int count_pancakes(unsigned long long time, unsigned long long target){
    unsigned long long int counter = 0;
    for(auto chef : chefs){
        counter += time / chef;
        if(counter >= target)
            return counter;
    }

    //printf("time: %d conter: %lld\n", time, counter);

    return counter;
}

unsigned long long bs(unsigned long long left, unsigned long long right, unsigned long long target){
    unsigned long long int mid;
    unsigned long long int last_found;
    while(left < right){
        mid = left / 2 + right / 2;
        //printf("%d %lld %d\n", left, mid, right);
        unsigned long long int count = count_pancakes(mid, target);
        if(count < target){
            left = mid + 1;
        }
        else{
            last_found = mid;
            right = mid - 1;
        }
    }

    mid = last_found;

    while(count_pancakes(mid, target) >= target)
        mid--;

    return mid + 1;
}

int main() {
    std::cin >> N >> K;
    int in;
    for(int i = 0 ; i < K; i++){
        std::cin >> in;
        chefs.push_back(in);
    }

    std::sort(chefs.begin(), chefs.end());

    printf("%llu\n", bs(0, LLONG_MAX * 2, N));

    return 0;
}
