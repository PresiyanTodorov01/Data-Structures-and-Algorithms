#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int bs_index(std::vector<std::pair<int, int>>& v, int left, int right, std::pair<int, int>& key)
{
    while (left < right) {
        int mid = left + (right - left) / 2;
        if(v[mid].second == key.second)
            return -1;
        else if (v[mid].second > key.second)
            right = mid;
        else
            left = mid + 1;
    }

    return right;
}

int LongestIncreasingSubsequenceLength(std::vector<std::pair<int, int>>& v)
{
    if (v.size() == 0)
        return 0;

    else if(v.size() == 1)
        return 1;

    std::vector<std::pair<int, int>> tail(v.size(), std::pair<int, int>(0, 0));
    std::vector<std::pair<int, int>> tail_beginning;
    std::vector<std::pair<int, int>> head;

    int i = 0;

    bool defeated = 0;

    while(true){

        for(int j = 0; j < tail_beginning.size(); j++){
            if(v[i].first > tail_beginning[j].first && v[i].second > tail_beginning[j].second){
                defeated = 1;
                tail[0] = tail_beginning[tail_beginning.size() - 1];
                tail[1] = v[i];
                break;
            }
        }

        if(defeated == 1){
            break;
        }

        if(tail_beginning.size() == 0)
            tail_beginning.push_back(v[i]);

        else if(v[i].second < tail_beginning[tail_beginning.size() - 1].second)
            tail_beginning.push_back(v[i]);

        i++;

        if(i >= v.size())
            break;
    }

    if(defeated == 0)
        return 1;

    int length = 2;

    i++;

    while(i < v.size()) {

        /*std::cout << "i: " << i << " Tail: ";
        for(int j = 0; j < length; j++){
            std::cout << "(" << tail[j].first << ", " << tail[j].second << ") ";
        }
        std::cout <<"\n"; */

        bool found = 0;

        if(head.size() != 0){
            for(int j = head.size() - 1; j >= 0; j--){
                if(v[i].first > head[j].first && v[i].second > head[j].second){
                    tail[length++] = v[i];
                    head.clear();
                    found = 1;
                    i++;
                }
            }

        }

        if(found == 1)
            continue;

        if (v[i].first > tail [length - 1].first && v[i].second > tail[length - 1].second)
            tail[length++] = v[i];

        else{
            int ind = bs_index(tail, 0, length - 1, v[i]);
            //std::cout << "IND: " << ind << std::endl;
            if(ind == 0)
                tail[ind] = v[i];
            else if(ind == length - 1){
                head.push_back(tail[length - 1]);
                tail[ind] = v[i];
            }
            else if(ind != -1 && tail[ind - 1].first < v[i].first)
                tail[ind] = v[i];
        }

        i++;

    }

    return length;
}

const int SIZE = 100000;

int main(){

    srand(time(NULL));

    int n = SIZE; std::cin >> n;
    int in1; int in2;

    std::vector<std::pair<int, int>> v;

    //std::ofstream in("filename", std::ios_base::out);

    for(int i = 0; i < n; i++){
        std::cin >> in1; std::cin >> in2;
        //in1 = rand() % SIZE; in2 = rand() % SIZE;
        v.push_back(std::pair<int, int>(in1, in2));
        //in << v[i].first << " " << v[i].second << "\n";
    }



    std::sort(v.begin(), v.end());

    std::cout << LongestIncreasingSubsequenceLength(v) << '\n';

    return 0;
}
