#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string reverseWords(string s) {
        string answer = "";
        int n = s.length();

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++)
        {
            string word = "";
            while(i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if(word.length() > 0)
            {
                answer += " " + word;
            }
        }

        return answer.substr(1);

    }