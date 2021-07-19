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
    cout<<st.getTop()<<endl;
    cout<<st.find(5)<<endl;
    cout<<st.size()<<endl;
    return 0;
}
