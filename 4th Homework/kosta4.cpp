#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class MyListNode
{
public:
    int data;
    MyListNode* next;
    MyListNode* previous;
    MyListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};
class MyList
{
public:
    MyListNode* head;
    MyListNode* tail;
    int size;
    MyList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
   void Add(int data)
   {
       MyListNode* newNode = new MyListNode(data);
       newNode->previous = this->tail;
       if (!this->head)
       {
           this->head = newNode;
       }
       else
       {
           this->tail->next = newNode;
       }

       this->tail = newNode;
       this->size++;
   }
   void Gun()
   {
       if (this->size==1||this->size==0)
       {
           this->head = nullptr;
           this->tail = nullptr;
       }
       else
       {
       this->tail = this->tail->previous;
       this->tail->next = nullptr;
       }
       this->size--;
       this->size >= 0 ? size : 0;
   }
   void Milen()
   {
       int itemsToGet = size / 2;
       if (this->size==0||this->size==1)
       {

       }
       else if (this->size==2)
       {
           MyListNode* currentHead = this->head;
           this->head = this->tail;
           this->tail = currentHead;
           this->head->next=this->tail;
           this->tail->previous = this->head;
           this->head->previous = nullptr;
           this->tail->next = nullptr;
       }
       else if (this->size==3)
       {
           MyListNode* currentHead = this->head;
           MyListNode* currentTail = this->tail;
           this->tail->next = currentHead;
           this->head = currentHead->next;
           this->head->previous = nullptr;
           this->tail = currentHead;
           this->tail->next = nullptr;
           this->tail->previous = currentTail;
       }
       else
       {
           MyListNode* newNodeStart = this->head;
           MyListNode* newNodeEnd = newNodeStart->next;
           for (size_t i = 0; i < itemsToGet - 1;i++)
           {
               newNodeEnd = newNodeEnd->next;
           }
           this->head = newNodeEnd->next;
           this->head->previous = nullptr;
           newNodeStart->previous = this->tail;
           newNodeEnd->next = nullptr;
           this->tail->next = newNodeStart;
           this->tail = newNodeEnd;
       }
   }
   void Print()
   {
       MyListNode* current = this->head;
       cout << this->size << endl;
       while (current!=nullptr)
       {
           printf("%d ", current->data);
           current = current->next;
       }
       delete[] current;
   }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int commands = 0;
    MyList list;
    string input;
    cin >> commands;
    int number = 0;
    for (size_t i = 0; i < commands; i++)
    {
        cin>>input;
        if (input=="add")
        {
            cin >> number;
            list.Add(number);
        }
        else if (input=="milen")
        {
            list.Milen();
        }
        else
        {
            list.Gun();
        }
    }
    list.Print();
}
