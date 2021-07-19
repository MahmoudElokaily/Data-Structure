#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main() {
    PriorityQueue<int>p;
    p.insert(5);
    p.insert(10);
    p.insert(3);
    p.insert(7);
    p.remove();
    p.clear();
    cout<<p.top()<<endl;
    p.Display();
    return 0;
}