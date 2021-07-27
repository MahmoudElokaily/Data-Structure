#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.find(13)<<endl;
    cout<<st.find(10)<<endl;
    cout<<st.getTop()<<endl;
    st.Display();
    st.clear();
    st.Display();
    return 0;
}
