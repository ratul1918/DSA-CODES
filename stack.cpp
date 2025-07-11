//using vector...

#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        if (!v.empty()) {
            v.pop_back();
        }
    }

    int top() {
        return v[v.size() - 1];
    }

    bool empty() {
        return v.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(15);
    s.push(20);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
