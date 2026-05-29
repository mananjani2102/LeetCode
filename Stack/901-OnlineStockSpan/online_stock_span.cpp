// LeetCode 901 - Online Stock Span
// Approach: Monotonic Stack (price, span pairs)
// Time: O(1) amortized per call | Space: O(n)

#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner stockSpanner;

    cout << stockSpanner.next(100) << " "; // 1
    cout << stockSpanner.next(80) << " ";  // 1
    cout << stockSpanner.next(60) << " ";  // 1
    cout << stockSpanner.next(70) << " ";  // 2
    cout << stockSpanner.next(60) << " ";  // 1
    cout << stockSpanner.next(75) << " ";  // 4
    cout << stockSpanner.next(85) << endl; // 6

    return 0;
}
