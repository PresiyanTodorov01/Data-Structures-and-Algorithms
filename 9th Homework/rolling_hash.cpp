#include<bits/stdc++.h>
#include <iostream>

const int p1 = 31;
const int mod1 = 1e9 + 7;
int powers1[1000000];

const int p2 = 37;
const int mod2 = 2e9 + 11;
int powers2[1000000];

void calculate_powers(){
    long long int current = 1;
    for(int i = 0; i < 100000; i++){
        powers1[i] = current;
        current = (current * p1) % mod1;
    }

    current = 1;
    for(int i = 0; i < 100000; i++){
        powers2[i] = current;
        current = (current * p2) % mod2;
    }
}

long long int calculate_hash(const std::string& str, int p, int mod, int* powers){
    long long int current_sum = 0;
    int current_pow = str.size() - 1;
    for(auto ch : str){
        current_sum += (ch - 'a' + 1) * (long long int)powers[current_pow];
        current_sum = current_sum % mod;
        current_pow--;
    }

    return current_sum;
}

long long int rolling_hash(const std::string& prev_str, long long int prev_hash, char next_char, int p, int mod, int* powers){

    long long next_hash = (prev_hash - (prev_str[0] - 'a' + 1) * (long long)powers[prev_str.size() - 1]) % mod;
    if(next_hash < 0)
        next_hash += mod;
    next_hash = (next_hash * p + (next_char - 'a' + 1)) % mod;

    return next_hash;
}

bool k_common(int k, const std::string& str1, const std::string& str2){
    std::unordered_map<long long, int> _map1;
    std::unordered_map<long long, int> _map2;

    std::string str = str1.substr(0, k);
    long long h1 = calculate_hash(str, p1, mod1, powers1);
    long long h2 = calculate_hash(str, p2, mod2, powers2);
    _map1[h1] = 1;
    _map2[h2] = 1;

    for(int i = k; i < str1.size(); i++)
    {
        h1 = rolling_hash(str, h1, str1[i], p1, mod1, powers1);
        h2 = rolling_hash(str, h2, str1[i], p2, mod2, powers2);

        str = str1.substr(i - k + 1, k);

        _map1[h1] = 1;
        _map2[h2] = 1;
    }

    str = str2.substr(0, k);
    h1 = calculate_hash(str, p1, mod1, powers1);
    h2 = calculate_hash(str, p2, mod2, powers2);

    if(_map1[h1] == 1 && _map2[h2] == 1)
        return 1;

    for(int i = k; i < str2.size(); i++)
    {
        h1 = rolling_hash(str, h1, str2[i], p1, mod1, powers1);
        h2 = rolling_hash(str, h2, str2[i], p2, mod2, powers2);

        str = str2.substr(i - k + 1, k);

        if(_map1[h1] == 1 && _map2[h2] == 1)
            return 1;

    }

    return 0;
}

int bs(const std::string& str1, const std::string& str2){
    int left = 0;
    int right = std::min(str1.size(), str2.size());
    while(right > left){
        int mid = (left + right) / 2;
        //printf("%d\n", mid);
        if(k_common(mid, str1, str2)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(k_common(right, str1, str2))
        return right;

    return right - 1;
}

int main(){
    calculate_powers();

    std::string str1; std::cin >> str1;
    std::string str2; std::cin >> str2;

    printf("%d\n", bs(str1, str2));
}
