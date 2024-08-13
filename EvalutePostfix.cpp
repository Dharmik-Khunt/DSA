#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

// Function to evaluate the postfix expression
int evaluatePostfix(string expression) {
    stack<int> st;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        // If the token is an operator, pop two operands from the stack
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            int result;

            // Perform the operation based on the token
            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "/") {
                result = operand1 / operand2;
            }

            // Push the result back onto the stack
            st.push(result);
        } else {
            // If the token is a number, convert it to an integer and push it onto the stack
            st.push(stoi(token));
        }
    }

    // The result of the postfix expression is the last element on the stack
    return st.top();
}

int main() {
    string expression;
    getline(cin, expression);  // Read the entire line containing the postfix expression

    int result = evaluatePostfix(expression);
    cout << result << endl;

    return 0;
}