#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char processStr(string s, long long k)
{
    k++;

    int n = s.length();
    vector<long long> lengths(n);
    long long current_len = 0;

    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z') {
            current_len++;
        } else if (ch == '*') {
            if (current_len > 0) current_len--;
        } else if (ch == '#') {
            if (current_len > 2e18) {
                current_len = 2e18;
            } else {
                current_len *= 2;
            }
        } else if (ch == '%') {
            
        }
        lengths[i] = current_len;
    }

    if (k > current_len) {
        return '.';
    }

    for (int i = n - 1; i >= 0; i--) {
        char ch = s[i];
        long long prev_len = (i == 0) ? 0 : lengths[i - 1];

        if (ch >= 'a' && ch <= 'z') {
            if (k == lengths[i]) {
                return ch;
            }
        } else if (ch == '*') {
            // no-op
        } else if (ch == '#') {
            if (k > prev_len) {
                k -= prev_len;
            }
        } else if (ch == '%') {
            k = current_len - k + 1;
        }

        current_len = prev_len;
    }

    return '.';
}
