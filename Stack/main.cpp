#include <iostream>

using namespace std;

template<class t>

struct Node{
    t value;
    Node* nxt;
};

template<class t>
class Stack{
private:
    int length;
    Node<t>* top;
public:
    Stack(){
        top = NULL;
        length = 0;
    }
    void push(t newItem){
        // to add new elements in stack
        Node<t>* newNode = new Node<t>;
        newNode->value = newItem;
        newNode->nxt = top;
        top = newNode;
        ++length;
    }

    bool isEmpty(){
        // if answer is 1 this mean the stack have elements otherwise stack is empty
        // you can choose ant one of them , and both are working
//        return !length;
        return top == NULL;
    }

    int size(){
        // return size of stack
        return length;
    }


    t getTop(){
        // return elements in top
        if (isEmpty()){
            throw "Stack is Empty!\n";
        }
        else {
            return top->value;
        }
    }

    void pop(){
        // delete element from top
        if (isEmpty()){
            puts("Stack is already empty");
        }
        else {
            Node<t>* temp = top;
            top =top->nxt;
            temp->nxt = NULL;
            delete temp;
            --length;
        }
    }

    void Display(){
        // to print elements in stack
        Node<t>* cur = top;
        while (cur != NULL){
            cout<<cur->value<<" ";
            cur = cur->nxt;
        }
        puts("");
    }

    void clear(){
        // to remove all elements in stack
        while (top != NULL){
            pop();
        }
    }

    bool find(t element){
        // to know this element i search in stack or not
        Node<t>* cur = top;
        while (cur->value != element && cur != NULL){
           cur = cur->nxt;
        }
        if (cur == NULL){
            return 0;
        }
        else {
            return 1;
        }
    }
};


int main(){
    Stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
//    st.clear();
//    cout<<st.getTop()<<endl;
    st.Display();
    return 0;
}