#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList<int> l;
    l.insertAtBegin(10);
    l.insertAtBegin(20);
    l.insertAtEnd(30);
    l.insertAtPos(2,13);
    l.erase(2);
    l.insertAtPos(2,15);
    l.reverse();
    cout<<l.find(11)<<endl;
    l.Display();
    return 0;
}