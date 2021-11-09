#include <iostream>
#include <vector>

struct Node{
    Node* previous = nullptr;
    Node* next = nullptr;
    int data;
    bool alive = 1;

    Node(int data){
        this->data = data;
    }
};

class LinkedList{
public:
    int size = 0;
    int round = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    std::vector<Node*> killers;

    void add(int data){
        Node* temp = new Node(data);

        if(head == nullptr){
            head = temp;
            tail = temp;
        }

        else if(size == 1){
            head->next = temp;
            tail = temp;
            tail->previous = head;
        }
        else{

            Node* temp_tail = tail;
            tail = temp;
            tail->previous = temp_tail;
            temp_tail->next = tail;
        }

        size ++;
    }

    bool play_round(){
        bool killed = 0;

        if(round == 0){
            Node* current = tail;
            Node* killer;
            while(current->previous != nullptr){

                if(current->data > current->previous->data){
                    killer = current->previous;
                    killers.push_back(killer);
                    current->alive = 0;

                    if(current->next != nullptr){
                        current->next->previous = killer;
                    }

                    killer->next = current->next;
                    killed = 1;

                    if(killer)
                        current = killer;
                    else
                        break;
                }

                else{
                    if(current->previous)
                        current = current->previous;
                    else
                        break;
                }
            }

        }
        else{
            Node* current;
            Node* killer;
            std::vector<int> indexes_to_erase;
            for(int i = 0; i < killers.size(); i++){
                killer = killers[i];
                current = killer->next;
                if(current != nullptr && current->data > killer->data){
                    current->alive = 0;

                    //remove person
                    if(current -> next)
                        current->next->previous = killer;
                    killer->next = current->next;
                    killed = 1;
                }
                else{
                    indexes_to_erase.push_back(i);
                }
            }


            for(int i = indexes_to_erase.size() - 1; i >= 0; i--){
                killers.erase(indexes_to_erase[i] + killers.begin());
            }
        }
        for(int i = killers.size() - 1; i >= 0; i--){
            if(killers[i] -> alive == 0){
                killers.erase(i + killers.begin());
            }
        }

        if(killed == 1)
            round++;
        return killed;
    }
};


int main(){
    LinkedList list = LinkedList();
    int N, input;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> input;
        list.add(input);
    }

    while(list.play_round()){}

    printf("%d\n", list.round);

    return 0;
}
