#include<iostream>
#include<limits>
#include<stack>

using namespace std;


class MinStack {
private:
    stack<int> s;
    int minElement;

public:
    MinStack() {
        minElement = numeric_limits<int>::max();
    }

    void push(int x) {
        if (x < minElement) {
            minElement = x;
        }
        s.push(x);
    }

    void pop() {
        if (s.top() == minElement) {
            s.pop();
            minElement = numeric_limits<int>::max();
            stack<int> temp = s;
            while (!temp.empty()) {
                if (temp.top() < minElement) {
                    minElement = temp.top();
                }
                temp.pop();
            }
        } else {
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minElement;
    }
};

