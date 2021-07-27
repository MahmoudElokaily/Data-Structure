#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main() {
    PriorityQueue<int>p;
    p.insert(5);
    p.insert(10);
    p.insert(3);
    p.insert(7);
    p.insert(8);
    p.insert(3);
    p.remove();

    cout<<p.top()<<endl;
    cout<<p.size()<<endl;
    p.clear();
    p.Display();
    return 0;
}