#include <iostream>

using namespace std;
template<class t>
struct Node{
    t value;
    Node* nxt;
};

template<class t>
class LinkedList{
private:
    Node<t>*front,*back;
    int length;
public:
    LinkedList(){
        length = 0;
        front = back = NULL;
    }

    // Function to insert in begin
    void insertAtBegin(t newItem){
        try {
            Node<t> *newNode = new Node<t>;
            newNode->value = newItem;
            if (front == NULL) {
                newNode->nxt = NULL;
                front = back = newNode;
            } else {
                newNode->nxt = front;
                front = newNode;
            }
            ++length;
        }
        catch (exception e){
            throw "Linked List is Full";
        }
    }

    // Function to insert in begin
    void insertAtEnd(t newItem){
        try {
            Node<t> *newNode = new Node<t>;
            newNode->value = newItem;
            if (front == NULL) {
                newNode->nxt = NULL;
                front = back = newNode;
            } else {
                back->nxt = newNode;
                newNode->nxt = NULL;
                back = newNode;
            }
            ++length;
        }
        catch (exception e){
            throw "Linked List is Full";
        }
    }

    // Function to insert item in position
    void insertAtPos(int pos,t newItem){
        try {
            if (pos > length || pos < 0) {
                throw "out of range";
            } else {
                if (pos == 0) {
                    insertAtBegin(newItem);
                } else if (pos == length) {
                    insertAtEnd(newItem);
                } else {
                    Node<t> *newNode = new Node<t>;
                    newNode->value = newItem;
                    Node<t> *cur = front;
                    for (int i = 1; i < pos; ++i) {
                        cur = cur->nxt;
                    }
                    newNode->nxt = cur->nxt;
                    cur->nxt = newNode;
                    ++length;
                }
            }
        }
        catch (exception e){
            throw "Linked List is Full";
        }
    }

    // Function to delete element from begin
    void removeFromBegin(){
        if(isEmpty()){
            throw "Linked List is already Empty!";
        }
        else if (length == 1){
            front = back = NULL;
            --length;
        }
        else {
            Node<t>*temp = front;
            front = front->nxt;
            temp->nxt = NULL;
            delete temp;
            --length;
        }
    }

    // Function to remove from last
    void removeFromLast(){
        if (isEmpty()){
            throw "LinKed List is already Empty!";
        }
        else if (length == 1){
            front = back = NULL;
            --length;
        }
        else {
            Node<t>*cur = front->nxt,*prev = front;
            while (cur != back){
                prev = cur;
                cur = cur->nxt;
            }
            prev->nxt = NULL;
            back = prev;
            delete cur;
            --length;
        }
    }

    // Function to remove element at position
    void erase(int index){
        if (index < 0 || index > length){
            throw "out of Range";
        }
        else {
            if (index == 0){
                removeFromBegin();
            }
            else if (index == length){
                removeFromLast();
            }
            else {
                Node<t>* cur = front->nxt,*prev = front;
                for (int i=1;i<index;++i) cur = cur->nxt;
                prev->nxt = cur->nxt;
                delete cur;
                --length;
            }
        }
    }

    // Function to know size of Linked List
    int size(){
        return length;
    }

    // Function to check if Linked List have elements or not
    bool isEmpty(){
        return front == NULL;
    }

    // Function to Display all items in LinkedList
    void Display(){
        Node<t>* cur = front;
        while (cur != NULL){
            cout<<cur->value<<" ";
            cur = cur->nxt;
        }
        puts("");
    }

    // Function to delete all Elements in Linked List
    void clear(){
        while (front != NULL){
            removeFromBegin();
        }
    }

    // Function to tell us the elment in Linked List or not
    int find(t element){
        Node<t>* cur = front;
        for (int i=1;i<=length;++i){
            if (cur->value == element){
                return i;
            }
            cur = cur->nxt;
        }
        return -1;
    }

    // Function to reverse all elements
    void reverse(){
        Node<t>*cur = front,*pre = NULL,*next = front->nxt;
        while (next != NULL){
            next = cur->nxt;
            cur->nxt = pre;
            pre = cur;
            cur = next;
        }
        back = front;
        front = pre;
    }
};

int main(){
    LinkedList<int> l;
    l.insertAtBegin(10);
    l.insertAtBegin(20);
    l.insertAtEnd(30);
    l.insertAtPos(2,15);
    cout<<l.size()<<endl;
    l.insertAtPos(4,50);
    l.insertAtPos(5,120);
    cout<<l.find(20)<<endl;
    cout<<l.size()<<endl;
    l.reverse();
    l.Display();
    return 0;
}