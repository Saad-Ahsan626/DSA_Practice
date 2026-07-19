#include<iostream>
#include<vector>
#include<string>

using namespace std;

string smallestSubsequence(string s) {
    int n = s.size();
    vector<int> lastIndex(26, -1);
    vector<bool> visited(26, false);
    string result;

    for (int i = 0; i < n; i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    for (int i = 0; i < n; i++) {
        if (visited[s[i] - 'a']) continue;

        while (!result.empty() && result.back() > s[i] && lastIndex[result.back() - 'a'] > i) {
            visited[result.back() - 'a'] = false;
            result.pop_back();
        }

        result.push_back(s[i]);
        visited[s[i] - 'a'] = true;
    }

    return result;
}