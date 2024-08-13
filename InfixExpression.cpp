#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to determine precedence of operators
int precedence(char c) {
    if(c == '+' || c == '-') {
        return 1;
    }
    if(c == '*' || c == '/') {
        return 2;
    }
    if(c == '^') {
        return 3;
    }
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for(char c : s) {
        // If the character is an operand, add it to the output
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        // If the character is '(', push it to the stack
        else if(c == '(') {
            st.push(c);
        }
        // If the character is ')', pop and output from the stack 
        // until an '(' is encountered
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();  // pop the '('
        }
        // If an operator is encountered
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the operators from the stack
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string expression;
    cin >> expression;

    string postfix = infixToPostfix(expression);
    cout << postfix << endl;

    return 0;
}