#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
   Queue<int>q;
   q.push(10);
   q.push(20);
   q.push(30);
   q.pop();
   cout<<q.find(25)<<endl;
   q.pop();
   cout<<q.size()<<endl;
   q.Display();
   q.clear();
   q.Display();
    return 0;
}
