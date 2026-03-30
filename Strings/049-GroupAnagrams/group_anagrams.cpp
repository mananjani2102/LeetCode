// LeetCode 049 - Group Anagrams
// Approach: HashMap + Sorting
// Time: O(n * k log k) | Space: O(n * k)

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;
        vector<vector<string>> result;

        for (string word : strs) {
            string temp = word;
            sort(temp.begin(), temp.end());
            anagram[temp].push_back(word);
        }

        for (auto& it : anagram) {
            result.push_back(it.second);
        }

        return result;
    }
};

void printResult(vector<vector<string>>& res) {
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << "\"" << res[i][j] << "\"";
            if (j + 1 < res[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < res.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<string> s1 = {"eat","tea","tan","ate","nat","bat"};
    auto r1 = sol.groupAnagrams(s1);
    printResult(r1); 

    vector<string> s2 = {""};
    auto r2 = sol.groupAnagrams(s2);
    printResult(r2); 

    vector<string> s3 = {"a"};
    auto r3 = sol.groupAnagrams(s3);
    printResult(r3);  

    return 0;
}