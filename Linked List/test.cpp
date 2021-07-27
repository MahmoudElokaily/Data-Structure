#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList<int> l;
    l.insertAtBegin(10);
    l.insertAtBegin(12);
    l.insertAtBegin(15);
    l.insertAtBegin(20);
    l.insertAtEnd(8);
    l.insertAtEnd(3);
    l.insertAtEnd(1);
    l.insertAtPos(6,2);
    l.insertAtPos(8,0);
    l.insertAtPos(1,8);
    cout<<l.size()<<endl;
    l.removeFromBegin();
    l.removeFromLast();
    l.removeFromBegin();
    l.removeFromLast();
    l.erase(2);
    l.erase(0);
    cout<<l.size()<<endl;
    cout<<l.find(3)<<endl;
    l.reverse();
    l.Display();
    l.clear();
    return 0;
}