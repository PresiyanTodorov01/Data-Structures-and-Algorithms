#include <iostream>
#include <bits/stdc++.h>
#include <string>

void count_sort(short arr[], int N)
{
    short RANGE = 62;

    short output[N];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

short* arr = new short[10000000];

void million_dollar_team(){
    int N;

    std::cin >> N;
    std::string char_arr;
    std::cin >> char_arr;

    for(int i = 0; i < N; i++){
        if(char_arr[i] >= '0' && char_arr[i] <= '9'){
            arr[i] = int(char_arr[i]) - int('0') + 1;
        }

        else if(char_arr[i] >= 'a' && char_arr[i] <= 'z'){
            arr[i] = int(char_arr[i]) - int('a') + 11;
        }

        else if(char_arr[i] >= 'A' && char_arr[i] <= 'Z'){
            arr[i] = int(char_arr[i]) - int('A') + 37;
        }
    }

    count_sort(arr, N);

    int i = 0;

    while(i < N && arr[i] <= 10){
        std::cout << char(arr[i] - 1 + int('0'));
        i++;
    }

    while(i < N && arr[i] <= 36){
        std::cout << char(arr[i] - 1 + int('a') - 10);
        i++;
    }

    while(i < N){
        std::cout << char(arr[i] - 1 + int('A') - 36);
        i++;
    }

}

int main(){
    million_dollar_team();

    return 0;
}
