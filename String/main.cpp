#include <iostream>

using namespace std;
const int N = 1e5 + 100;

class String{
private:
    int length;
    char str[N];
public:
    String(){
        length = 0;
        str[N];
    }

    // Function to push char at end of string
    void push_back(char s){
        str[length++] = s;
    }

    // Function to delete char from end
    void pop_back(){
        if (isEmpty()){
            throw "string is already Empty!";
        }
        else {
            --length;
        }
    }

    // Function to know string is empty or not
    bool isEmpty(){
        return length == 0;
    }

    // Function to Know size of string
    int size(){
        return length;
    }

    // Function to swap all string
    void swapString() {
        if (!isEmpty()) {
            for (int i = 1, j = length;i<=j;++i,j--){
                swap(i,j);
            }
        }
    }

    // Function to swap 2 char in string
    void swap(int f,int e){
        --f,--e;
        if (f > length || e > length){
            throw "out of range";
        }
        else {
            char temp = str[f];
            str[f] = str[e];
            str[e] = temp;
        }
    }

    // Function to get last element
    char back(){
        return str[length];
    }

    // Function to get first element
    char front(){
        return str[0];
    }

    // Function to get sub strung from string
    void substr(int l,int r){
        --l,--r;
        if (l > length || r > length || l > r){
            throw "Erorr!";
        }
        else {
            for (int i=l;i<=r;++i){
                cout<<str[i];
            }
            puts("");
        }
    }


    // Function to display string
    void Display(){
        for (int i=0;i<length;++i){
            cout<<str[i];
        }
        puts("");
    }
};
int main() {
    String s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    s.push_back('d');
    s.pop_back();
    cout<<s.size()<<endl;
    s.Display();
    return 0;
}
