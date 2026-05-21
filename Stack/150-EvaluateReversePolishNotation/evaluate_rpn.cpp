// LeetCode 150 - Evaluate Reverse Polish Notation
// Approach: Stack
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
                else if (token == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;

    vector<string> t1 = {"2", "1", "+", "3", "*"};
    cout << sol.evalRPN(t1) << endl; // 9

    vector<string> t2 = {"4", "13", "5", "/", "+"};
    cout << sol.evalRPN(t2) << endl; // 6

    vector<string> t3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << sol.evalRPN(t3) << endl; // 22

    return 0;
}
