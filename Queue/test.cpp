#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
   Queue<int>q;
   q.push(10);
   q.push(20);
   q.push(30);
   cout<<q.getFront()<<endl;
   cout<<q.find(10)<<endl;
   cout<<q.size()<<endl;
   q.pop();
   q.Display();
   q.pop();
   cout<<q.getFront()<<endl;
    return 0;
}
