#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList{
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

public:
    Node *head, *tail;
};

void solve(LinkedList& num1, LinkedList& num2){
    std::string ans = "";
    int carry = 0;
    Node* current_first = num1.head;
    Node* current_second = num2.head;
    while(current_first && current_second){
        int current = 0;
        current = (current_first->data + current_second->data + carry) % 10;
        carry = (current_first->data + current_second->data + carry) / 10;

        ans += ('0' + current);


        current_first = current_first->next;
        current_second = current_second->next;
    }

    while(current_first){
        int current;
        current = (current_first->data + carry) % 10;
        carry = (current_first->data + carry) / 10;

        ans += ('0' + current);

        current_first = current_first->next;
    }

    while(current_second){
        int current;
        current = (current_second->data + carry) % 10;
        carry = (current_second->data + carry) / 10;

        ans += ('0' + current);

        current_second = current_second->next;
    }

    if(carry == 1)
        printf("1");

    for(int i = ans.size() - 1; i >= 0; i--){
        std::cout << ans[i];
        //std::cout << std::endl;
    }




}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}
