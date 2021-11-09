#include <iostream>

struct Node{
    Node* previous = nullptr;
    Node* next = nullptr;
    int data;
    int position;

    Node(int data, int position){
        this->data = data;
        this->position = position;
    }
};

Node* _map[200000];

class LinkedList{
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int _size = 0;

    Node* add(int data, int position){
        Node* temp = new Node(data, position);

        if(head == nullptr){
            head = temp;
            tail = temp;
        }

        else if(_size == 1){
            head->next = temp;
            temp->previous = head;
            tail = temp;
        }
        else{
            Node* temp_tail = tail;
            tail = temp;
            tail->previous = temp_tail;
            temp_tail->next = tail;
        }

        _size ++;

        return temp;

    }

    void print(){
        if(_size == 1)
            std::cout << head->data << std::endl;
        else if(_size > 1){
            Node* temp = head;
            while(temp != nullptr){
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
    }

    Node* shoot(int position, int data, int llpos){
        if(_size == 0){
            printf("Game Over\n");
            return nullptr;
        }
        else if(_size == 1 && position == 0){
            Node* new_node = new Node(data, llpos);
            head->next = new_node;
            new_node->previous = head;
            tail = new_node;
            _size ++;
            printf("0\n");
            return new_node;
        }

        else{

            Node* current = _map[position];

            Node* new_node = new Node(data, llpos);
            if(current->next != nullptr){
                new_node->next = current->next;
                current->next = new_node;
                new_node->previous = current;
                new_node->next->previous = new_node;
            }
            else{
                tail = new_node;
                new_node->next = current->next;
                current->next = new_node;
                new_node->previous = current;
            }

            _size ++;

            bool first = 1;
            int total_killed = 0;
            while (true){
                //print();

                int left_counter = 0; bool reached_head = 0;
                int right_counter = 0; bool reached_tail = 0;
                Node* temp_left;
                Node* temp_right;

                if(first == 1){
                    temp_left = new_node->previous;
                    temp_right = new_node->next;
                }
                else{
                    temp_left = new_node;
                    temp_right = new_node->next;
                }

                if(temp_left == nullptr)
                    reached_head = 1;
                if(temp_right == nullptr)
                    reached_tail = 1;


                while(temp_left != nullptr){
                    if(temp_left->data == new_node->data){
                        left_counter ++;
                        if(temp_left->previous == nullptr){
                            reached_head = 1;
                            break;
                        }
                    }
                    else
                        break;
                    temp_left = temp_left->previous;
                }

                while(temp_right != nullptr){
                    if(temp_right->data == new_node->data){
                        right_counter++;
                        if(temp_right->next == nullptr){
                            reached_tail = 1;
                            break;
                        }
                    }
                    else
                        break;
                    temp_right = temp_right->next;
                }

                int total_counter = left_counter + right_counter;
                if(first == 1)
                    total_counter ++;

                if(total_counter >= 3){
                    if(reached_head == 1 && reached_tail == 1){
                        printf("%d\n", total_killed + _size);
                        _size = 0;
                        return nullptr;
                    }
                    if(reached_head == 1){
                        head = temp_right;
                        head->previous = nullptr;
                        total_killed += total_counter;
                        _size -= total_counter;
                    }
                    else if(reached_tail == 1){
                        tail = temp_left;
                        temp_left->next = nullptr;
                        total_killed += total_counter;
                        _size -= total_counter;

                    }
                    else{
                        temp_left->next = temp_right;
                        temp_right->previous = temp_left;
                        total_killed += total_counter;
                        _size -= total_counter;
                    }

                }
                else{
                    return new_node;

                }
                //std::cout << left_counter << " " << reached_head << std::endl;
                //std::cout << right_counter << " " << reached_tail << std::endl;

            if(reached_head == 1 || reached_tail == 1)
                break;
            if(temp_left->data != temp_right->data)
                break;
            new_node = temp_left;
            first = 0;
            }

            printf("%d\n", total_killed);

            return nullptr;

        }
    }



};

int main(){
    LinkedList LL;


    // INPUT
    int N; std::cin >> N;
    int in;

    for(int i = 0; i < N; i++){
        std::cin >> in;
        _map[i] = LL.add(in, i);
    }

    int Q; std::cin >> Q;
    int pos, data;

    for(int i = 0; i < Q; i++){
        std::cin >> pos; std::cin >> data;
        _map[N+i] = LL.shoot(pos, data, N + i);
    }



    if(LL._size > 0)
        LL.print();
    else{
        printf("-1");
    }

    return 0;
}
