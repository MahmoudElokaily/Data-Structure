#include<iostream>
#include "doublyLinkedList.h"

using namespace std;
int main() {
    doublyLinkedList<int>l;
    l.insertFirst(5);
    l.insertFirst(10);
    l.insertFirst(15);
    l.insertFirst(20);
    l.insertLast(25);
    l.insertLast(30);
    l.insertLast(35);
    l.insertAtPos(1,8);
    l.insertAtPos(4,9);
    l.insertAtPos(9,17);
//    l.insertAtPos(18,5);
    cout<<l.size()<<endl;
    l.removeFirst();
    l.removeLast();
    l.removeFirst();
    l.removeLast();
    cout<<l.size()<<endl;
    l.remove(10);
    l.erase(2);
    l.erase(0);
    cout<<l.size()<<endl;
    l.erase(2);
    l.insertAtPos(0,8);
    l.erase(1);
    l.insertFirst(5);
    l.insertLast(12);
    l.erase(2);
    l.erase(1);
    l.displayReverse();
    l.Display();
    return 0;
}

