#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s{"Hello,(world)!"};
    stack<char> stk;
    bool flag = false;
    for (const auto &i : s) {
        if (i == '(') {
            flag = true;
            continue;
        }
        else if (i == ')') {
            flag = false;
        }
        if (flag) stk.push(i);
    }
    string rep;
    while (!stk.empty()) {
        rep.push_back(stk.top());
        stk.pop();
    }
    for (decltype(rep.size()) i = 0; i != rep.size() / 2; ++i) {
        char temp;
        temp = rep[i];
        rep[i] = rep[rep.size()-i-1];
        rep[rep.size()-i-1] = temp;
    }
    s.replace(s.find("("), rep.size()+2, rep);
    cout << s << endl;
    return 0;
}