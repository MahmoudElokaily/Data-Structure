#include<iostream>

using namespace std;

template<class t>
struct Node {
    int item;
    Node* next;
    Node* prev;
};
template<class t>
class doublyLinkedList {
private:
    Node<t>* front;
    Node<t>* back;
    int length;
public:
    doublyLinkedList() {
        front = back = NULL;
        length = 0;
    }
    // Function to add elements at begin of List
    void insertFirst(int item)
    {
        Node<t>*newNode = new Node<t>;
        newNode->item = item;
        if (front == NULL) {
            front = back = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else {
            newNode->next = front;
            newNode->prev = NULL;
            front->prev = newNode;
            front = newNode;

        }
        ++length;
    }
    // Function to add elements at end of List
    void insertLast(t newItem) {
        Node<t>* newNode = new Node<t>;
        newNode->item = newItem;
        if (front == NULL) {
            front = back = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else {
            newNode->next = NULL;
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        ++length;
    }

    void insertAtPos(int pos, int item){
        if (pos < 0 || pos > length) {
            throw "Out Of Range!";
        }
        else if (pos == 0) {
            insertFirst(item);
        }
        else if (pos == length) {
            insertLast(item);
        }
        else
        {
            Node<t> *newNode = new Node<t>;
            newNode->item = item;
                Node<t> *cur = front;
                for (int i = 1; i < pos; i++) cur = cur->next;

                newNode->next = cur->next;
                newNode->prev = cur;
                cur->next->prev = newNode;
                cur->next = newNode;
                ++length;
            }
        }

    // Function to remove elements from begin
    void removeFirst()
    {
        if (front == NULL) {
            throw "List is already Empty!";
        }
        else if (length == 1)//first == last
        {
            delete front;
            front = back = NULL;
            --length;
        }
        else
        {
            Node<t>* temp = front;
            front = front->next;
            front->prev = NULL;
            delete temp;
            --length;
        }
    }

    // Function to delete item from end
    void removeLast(){
        if (front == NULL){
            throw "List is already Empty!";
        }
        else if (length == 1)//first == last
        {
            delete front;
            front = back = NULL;
            --length;
        }
        else
        {
            Node<t> *temp = back;
            back = back->prev;
            back->next = NULL;
            delete temp;
            --length;
        }
    }

    // Function to erase value by it is value
    void remove(t item){
        if (isEmpty()){
            throw "Empty List!";
        }
        else if (front->item == item){
            removeFirst();
        }
        else {
            Node<t>*cur = front->next;
            while (cur != NULL && cur->item != item) cur = cur->next;
            if (cur == NULL) {
                throw "item not Found";
            }
            else if (cur->next == NULL){
                removeLast();
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            --length;

        }
    }

    // Function to erase value by it is index
    void erase(int index){
        if (isEmpty()){
            throw "Empty List!";
        }
        else if (index > length || index < 0){
            throw "Out of range";
        }
        else if (index == 0){
            removeFirst();
        }
        else if (index == length){
            removeLast();
        }
        else {
            Node<t>*cur = front;
            for (int i=1;i<index;++i) cur = cur->next;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            --length;
        }

    }
    // Function to know size of list
    int size(){
        return length;
    }

    // Function to know List is Empty or no
    bool isEmpty(){
        return front == NULL;
    }

    // Function to print all elements
    void Display(){
        Node<t>* cur = front;
        while (cur != NULL){
            cout<<cur->item<<" ";
            cur =cur->next;
        }
        puts("");
    }

    void displayReverse(){
        Node<t>* cur = back;
        while (cur != NULL){
            cout<<cur->item<<" ";
            cur =cur->prev;
        }
        puts("");
    }

    // Function to clear List;
    void clear(){
        if (isEmpty()){
            throw "List is already Empty";
        }
        while (!isEmpty()){
            removeFirst();
        }
    }
};
int main() {
    doublyLinkedList<int>l;
    l.insertAtPos(0,10);
    l.insertAtPos(1,20);
    l.insertAtPos(2,30);
    l.insertAtPos(3,40);
    l.insertFirst(0);
    l.insertLast(60);
    l.removeLast();
    l.removeFirst();
    l.erase(4);
    l.remove(20);
    l.clear();
    cout<<l.size()<<endl;
    l.Display();
    l.displayReverse();
    return 0;
}

