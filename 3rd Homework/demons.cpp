#include <iostream>
#include <bits/stdc++.h>
#include <vector>

int CeilIndex(std::vector<std::pair<int, int>>& v, int l, int r, std::pair<int, int>& key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m].first >= key.first && v[m].second >= key.second)
            r = m;
        else
            l = m;
    }

    return r;
}

int lis(std::vector<std::pair<int, int>>& v, int n)
{
    if (n== 0)
        return 0;

    std::vector<std::pair<int, int>> tail(v.size(), std::pair<int, int>(0, 0));
    int length = 1;

    tail[0] = v[0];
    for (size_t i = 1; i < n; i++) {

        if (v[i] < tail[0])
            tail[0] = v[i];

        else if (v[i].first > tail [length - 1].first && v[i].second > tail[length - 1].second)
            tail[length++] = v[i];

        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }

    return length;
}


void demons(std::vector<std::pair<int ,int>>& arr, int n){
    int lis_result;

    //merge_sort(arr, 0, 0, n - 1);
    std::sort(arr.begin(), arr.end(), [](auto &left, auto &right) {
    return left.second < right.second;
    });
    lis_result = lis(arr, n);

    std::cout << lis_result << std::endl;

}

std::vector<std::pair<int, int>> arr(100005);

int main(){

    int n; std::cin >> n;
    int in1; int in2;

    for(int i = 0; i < n; i++){
        std::cin >> in1; std::cin >> in2;
        arr[i] = std::pair<int, int>(in1, in2);
    }

    demons(arr, n);

    return 0;
}
