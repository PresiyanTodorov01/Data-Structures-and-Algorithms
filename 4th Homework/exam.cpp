#include <iostream>
#include <string>

struct Node{
    Node* previous = nullptr;
    Node* next = nullptr;
    int data;

    Node(int data){
        this->data = data;
    }
};

class LinkedList{
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* middle = nullptr;
    int _size = 0;

    void add(int data){
        Node* temp = new Node(data);

        if(head == nullptr){
            head = temp;
            tail = temp;
        }

        else if(_size == 1){
            head->next = temp;
            tail = temp;
            tail->previous = head;
            middle = head;
        }
        else{

            Node* temp_tail = tail;
            tail = temp;
            tail->previous = temp_tail;
            temp_tail->next = tail;

            if(_size % 2 == 1)
                middle = middle->next;
        }

        _size ++;
    }

    void gun(){
        if(_size == 1){
            Node* temp = head;
            delete temp;
            head = nullptr;
            tail = nullptr;
            middle = nullptr;
        }
        else{
            Node* temp = tail;
            tail->previous->next = nullptr;
            tail = tail->previous;
            delete temp;

            if(_size % 2 == 0 && _size > 3)
                middle = middle->previous;

        }

        _size --;
    }

    void print(){
        if(_size == 1)
            std::cout << head->data << std::endl;
        else if(_size > 1){
            Node* temp = head;
            while(temp != tail){
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("%d\n", tail->data);
        }
    }

    void milen(){
        if(_size == 1)
            return;
        else{

            Node* temp_head = head;
            head = middle->next;
            middle->next->previous = nullptr;
            middle->next = nullptr;
            tail->next = temp_head;
            temp_head->previous = tail;
            tail = middle;

            if(_size % 2 == 0)
                middle = temp_head->previous;

            else if(_size % 2 == 1)
                middle = temp_head -> previous -> previous;

        }
    }

};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    LinkedList LL = LinkedList();
    int N, add_num;
    std::cin >> N;
    std::string input;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        if(input == "add"){
            std::cin >> add_num;
            LL.add(add_num);
        }
        else if(input == "gun"){
            LL.gun();
        }

        else if(input == "milen"){
            LL.milen();
        }
    }

    /*for(int i = 1; i < 500000; i++){
        LL.add(i);

        }

    for(int i = 1; i < 500000; i++){
        LL.milen();
        }*/

    printf("%d\n", LL._size);
    LL.print();

    return 0;
}
