#include <iostream>
#include "string.h"

using namespace std;

int main() {
    string s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    s.push_back('d');
    s.pop_back();
    cout<<s.size()<<endl;
    s.Display();
    return 0;
}
