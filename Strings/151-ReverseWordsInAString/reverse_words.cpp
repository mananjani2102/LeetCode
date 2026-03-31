
// LeetCode 151 - Reverse Words in a String
// Approach: String Stream
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            if (i != 0) result += " ";
            result += words[i];
        }
        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.reverseWords("the sky is blue")  << endl; 
    cout << sol.reverseWords("  hello world  ")  << endl; 
    cout << sol.reverseWords("a good   example") << endl; 

    return 0;
}