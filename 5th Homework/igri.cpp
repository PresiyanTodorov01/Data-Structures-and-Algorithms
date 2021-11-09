#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>

struct Node{
    Node* previous_optimization = nullptr;
    Node* next_optimization = nullptr;
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
        }
        else{

            Node* temp_tail = tail;
            tail = temp;
            tail->previous = temp_tail;
            temp_tail->next = tail;
        }

        _size ++;
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

    void print(std::ofstream& file){
        if(_size == 1)
            std::cout << head->data << std::endl;
        else if(_size > 1){
            Node* temp = tail;
            while(temp != head){
                file << temp->data << " ";
                temp = temp->previous;
            }
            file << head -> data << " ";
        }
    }

    bool remove(){
        bool removed = 0;

        std::vector<int> killers;

        Node* current = tail;
        Node* temp;
        Node* first_not_removal;

        int not_removed_streak = 0;

        while(current->previous != nullptr){

            if(current -> previous_optimization != nullptr && current != current -> previous_optimization){
                current = current -> previous_optimization;
                not_removed_streak = 0;
                continue;
            }

            //sleep(1);
            //std::cout << "Current data: " << current -> data << std::endl;
            if(current->data > current->previous->data){
                temp = current->previous;

                killers.push_back(current->previous->data);

                if(current == tail){
                    tail = current -> previous;
                }

                else{
                    current->next->previous = temp;
                    temp->next = current->next;
                }
                if(current -> next_optimization != nullptr && current -> next_optimization != current){
                    current -> next -> next_optimization = current -> next_optimization;
                    current -> next_optimization -> previous_optimization = current -> next;
                }

                removed = 1;
                if(temp != nullptr)
                    current = temp;
                else{break;}

                if(not_removed_streak >= 3){
                    first_not_removal->previous_optimization = temp -> next;
                    temp -> next -> next_optimization = first_not_removal;
                }

                not_removed_streak = 0;
            }

            else{
                if(not_removed_streak == 0)
                    first_not_removal = current;
                not_removed_streak++;
                current = current->previous;
            }
        }

        if(not_removed_streak >= 3){
            first_not_removal->previous_optimization = current;
            current -> next_optimization = first_not_removal;
        }

        if(killers.size() != 0){
            printf("killers: ");
            for(size_t i = 0; i < killers.size(); i++){
                printf("%d ", killers[i]);
            }
            printf("\n");
        }

        return removed;
    }
};

const int MAX = 50;

int main(){
    std::ofstream file("CYCLE", std::ios::app);
    srand(time(NULL));
    LinkedList LL = LinkedList();
    int N = MAX, input;

    file << "\n" << N << "\n";

    for(int i = 0; i < N; i++){
        input = rand() % MAX;
        //std::cin >> input;
        file << input << " ";
        LL.add(input);
    }

    file << "\n";

    file.close();

    LL.print();

    int counter = 0;

    while(LL.remove() == 1){
        std::cout << "After removal: ";
        LL.print();
        counter ++;
    }

    printf("%d\n", counter);

    //file << counter << "\n";

    //LL.print(file);

    //file.close();


    return 0;
}
