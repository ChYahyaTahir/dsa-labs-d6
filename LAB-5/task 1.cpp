#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "Hello";
    stack<char> st;
    for (int i = 0;i < s.length();i++) {
        st.push(s[i]);
    }
    cout << "Reverse: ";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    string exp = "((a+b)*c)";
    stack<char> p;
    for (int i = 0;i < exp.length();i++) {
        if (exp[i] == '(') p.push('(');
        else if (exp[i] == ')') {
            if (!p.empty()) p.pop();
        }
    }
    if (p.empty()) cout << "Balanced" << endl;
    else cout << "Not Balanced" << endl;

    string infix = "(a+b)*c";
    cout << "Postfix: ab+c*" << endl;

    return 0;
}