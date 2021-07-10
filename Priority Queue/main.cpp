#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5;
template<class t>
class PriorityQueue{
private:
    int length;
    t PQ[N];
public:
    PriorityQueue(){
        length = 0;
        PQ[N];
    }

    // Function to Know PriorityQueue is empty or not
    bool isEmpty(){
        return length == 0;
    }

    // Function to add element in PriorityQueue
    void insert(t newItem){
        PQ[length++] = newItem;
        sort(PQ,PQ+length,greater<>());
    }


    // Function to delete element in PriorityQueue
    void remove(){
        if (isEmpty()){
            throw "PriorityQueue is already Empty!";
        }
        else {
            PQ[0] = 0;
            sort(PQ,PQ+length,greater<>());
            --length;
        }
    }

    // Function to Display all elements in PriorityQueue
    void Display(){
        for (int i=0;i<length;++i){
            cout<<PQ[i]<<" ";
        }
        puts("");
    }

    // Function to know size of PriorityQueue
    int size(){
        return length;
    }

    // Function to retun top element in PriorityQueue
    t top(){
        if (isEmpty()){
            throw "PriorityQueue is already Empty";
        }
        else {
            return PQ[0];
        }
    }

    // Function to clear PriorityQueue
    void clear(){
        length = 0;
    }
};
int main() {
    PriorityQueue<int>p;
    p.insert(5);
    p.insert(10);
    p.insert(3);
    p.insert(7);
    p.clear();
    cout<<p.size()<<endl;
    cout<<p.top()<<endl;
    p.Display();
    return 0;
}
