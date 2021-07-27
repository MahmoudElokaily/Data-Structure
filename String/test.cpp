#include <iostream>
#include "string.h"

using namespace std;

int main() {
    String s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    s.push_back('d');
    s.push_back('e');
    s.push_back('m');
    s.push_back('n');
    s.substr(0,5);
    s.Display();
//    cout<<s.size()<<endl;
//    s.swapString();
//    s.Display();
    return 0;
}
