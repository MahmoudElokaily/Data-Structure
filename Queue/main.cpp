#include <iostream>

using namespace std;
template<class t>
struct Node{
    t value;
    Node* nxt;
};

template<class t>
class Queue{
private:
    int length;
    Node<t>* front,*rear;
public:
    Queue(){
        length = 0;
        front = rear = NULL;
    }

    // Function to push new elements in front
    void push(t newElement){
        Node<t>* newNode = new Node<t>;
        newNode->value = newElement;
        if (isEmpty()){
            newNode->nxt = front;
            front = rear = newNode;
        }
        else {
            rear->nxt = newNode;
            newNode->nxt = NULL;
            rear = newNode;
        }
        ++length;
    }

    // Function to delete element from front
    void pop(){
        if (isEmpty()){
            throw "Queue is already Empty!";
        }
        else {
            Node<t>* temp = front;
            front = front->nxt;
            temp->nxt = NULL;
            delete temp;
            --length;
        }
    }

    // Function to show all elements in queue
    void Display(){
        Node<t>* cur = front;
        while (cur != NULL){
            cout<<cur->value<<" ";
            cur = cur->nxt;
        }
        puts("");
    }

    // Function to check queue is Empty or not
    bool isEmpty(){
        return front == NULL;
    }

    // Function to know size of queue
    int size(){
        return length;
    }

    // Function to delete all elements in queue
    void clear(){
        while (front != NULL){
            pop();
        }
    }

    // Function to know element in queue or not
    bool find(t element){
        Node<t>* cur = front;
        while (cur != NULL && cur->value != element){
            cur = cur ->nxt;
        }
        if (cur == NULL){
            return 0;
        }
        else {
            return 1;
        }
    }

    // Function to return the first element in queue
    t getFront(){
        if (front == NULL){
           throw "Queue is Empty!";
        }
        else {
            return front->value;
        }
    }
};

int main()
{
   Queue<int>q;
   q.push(10);
   q.push(20);
   q.push(30);
   q.pop();
   q.pop();
   q.pop();
   cout<<q.getFront()<<endl;
    return 0;
}
