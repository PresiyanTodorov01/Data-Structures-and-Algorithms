#include <iostream>
#include<bits/stdc++.h>

std::vector<int> matrix[2005][2005]; /// std::vector<dist>[from][to]

int main() {
    int V, E, K, Q;
    std::cin >> V >> E;
    int in1, in2, dist;
    for(int i = 0; i < E; i++){
        std::cin >> in1 >> in2 >> dist;
        matrix[in1][in2].push_back(dist);
    }

    std::cin >> K;
    std::set<int> unusable;

    for(int i = 0; i < K; i++){
        std::cin >> in1;
        unusable.insert(in1);
    }

    std::cin >> Q;

    std::string ans = "";

    int length;

    for(int i = 0; i < Q; i++){
        std::cin >> length;
        std::cin >> in1;

        bool main_found = 1;

        for(int i = 1; i < length; i++){

            std::cin >> in2;

            if(main_found == 0)
                continue;

            if(matrix[in1][in2].size() == 0){
                main_found = 0;
            }
            else{
                bool found = 0;
                for(auto len : matrix[in1][in2]){
                    if(unusable.find(len) == unusable.end()){
                        found = 1;
                        break;
                    }
                }

                if(found == 0){
                    main_found = 0;
                }
            }
            in1 = in2;
        }

        if(main_found == 1)
            ans += "1";
        else
            ans += "0";

    }

    std::cout << ans << std::endl;

    return 0;
}
