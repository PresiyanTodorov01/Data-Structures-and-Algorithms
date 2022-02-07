#include <iostream>
#include <bits/stdc++.h>

int arr_tree_nodes[(int)1e6];

int find(int i){
    if(arr_tree_nodes[i] == -1)
        return i;

    return arr_tree_nodes[i] = find(arr_tree_nodes[i]);
}

bool same_root(int first, int second){
    return(find(first) == find(second));
}

void dsu(int first, int second){
    int root1 = find(first);
    int root2 = find(second);

    if(root1 != root2)
        arr_tree_nodes[root1] = root2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);


    std::fill(arr_tree_nodes, arr_tree_nodes + (int)1e6, -1);

    int V, E; std::cin >> V >> E;

    int in1, in2;

    for(int i = 0; i < E; i++){
        std::cin >> in1 >> in2;
        dsu(in1, in2);
    }


    int Q, q_type; std::cin >> Q;

    for(int i = 0; i < Q; i++){
        std::cin >> q_type >> in1 >> in2;
        if(q_type == 1){
            printf("%d",same_root(in1, in2));
        }
        else{
            dsu(in1, in2);
        }
    }

    return 0;
}
