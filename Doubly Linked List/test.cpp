#include<iostream>
#include "doublyLinkedList.h"

using namespace std;
int main() {
    doublyLinkedList<int>l;
    l.insertAtPos(0,10);
    l.insertAtPos(1,20);
    l.insertAtPos(2,30);
    l.insertAtPos(3,40);
    l.insertFirst(5);
    l.insertLast(60);
    l.insertAtPos(5,50);
    l.removeFirst();
    l.removeLast();
    l.erase(2);
    cout<<l.size()<<endl;
    l.Display();
    return 0;
}

