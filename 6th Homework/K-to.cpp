#include <iostream>
#include <queue>

int arr[100000];

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int arrange (int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = (left - 1);

    for (int j = left; j < right; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}



int random_num_arrange(int arr[], int left, int right) {
    int pivot = rand() % (right - left) + left;
    swap(&arr[right], &arr[pivot]);
    return arrange(arr, left, right);
}

int quick_select_highest_knum = -1;

void quick_select_highest(int arr[], int p, int _size, int left, int right){
    int k = _size - p;
    if(left < right){
        int pivot = random_num_arrange(arr, left, right);

        if(pivot == k){
            quick_select_highest_knum = arr[pivot];
        }

        else if(pivot > k){
            quick_select_highest(arr, p, _size, left, pivot - 1);
        }
        else{
            quick_select_highest(arr, p, _size, pivot + 1, right);
        }
    }

    else if(left == right){
        quick_select_highest_knum = arr[left];
    }

}

struct Node{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int data) {
        this->data = data;
    }
};

class BinaryTree{
private:
    Node* root = nullptr;
    void pr_print(Node* current){
        std::queue<Node*> q;
        q.push(current);
            while(!q.empty()){
                Node* cur = q.front();
                printf("%d ", cur->data);
                q.pop();
                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }
    }

    Node* pr_add(Node* current, int data){
        if(current == nullptr){
            return new Node(data);
        }
        else if(current->data < data){
            current->right = pr_add(current->right, data);
        }
        else if(current->data > data){
            current->left = pr_add(current->left, data);
        }


        return current;
    }

    Node* find_min_value(Node* current){
        while(current->left != nullptr)
            current = current->left;

        return current;
    }

    Node* pr_remove(Node* current, int data){
        if(current == nullptr)
            return nullptr;

        else if(data < current->data){
            current->left = pr_remove(current->left, data);
        }
        else if(data > current->data){
            current->right = pr_remove(current->right, data);
        }
        else{
            if(current->left == nullptr && current->right == nullptr){
                free(current);
                return nullptr;
            }
            else if(current->left == nullptr){
                Node* temp = current->right;
                free(current);
                return temp;

            }
            else if(current->right == nullptr){
                Node* temp = current->left;
                free(current);
                return temp;
            }
            else{
                Node* temp = find_min_value(current->right);

                int temp_data = current->data;
                current->data = temp->data;
                temp->data = temp_data;

                current->right = pr_remove(current->right, temp_data);
            }
        }
    }

public:
    void add(int data){
        root = pr_add(root, data);
    }

    void print(){
        pr_print(root);
        printf("\n");
    }

    void remove(int data){
        pr_remove(root, data);
    }

};

int main(){
    BinaryTree BT;
    int K;
    int N; std::cin >> N; std::cin >> K;
    int input;
    for(int i = 0; i < N; i++){
        std::cin>>input;
        arr[i] = input;
        BT.add(input);
    }

    quick_select_highest(arr, K, N, 0, N - 1);

    BT.remove(quick_select_highest_knum);

    BT.print();

    return 0;
}
