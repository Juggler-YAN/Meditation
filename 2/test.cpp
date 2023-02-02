#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    if (cin >> s) {
        string item, maxitem;
        unsigned int cnt = 1,
                     maxcnt = cnt;
        while (cin >> item) {
            if (item == s) {
                ++cnt;
            }
            else {
                if (cnt > maxcnt) {
                    maxcnt = cnt;
                    maxitem = s;
                }
                s = item;
                cnt = 1;
            }
        }
        if (cnt > maxcnt) {
            maxcnt = cnt;
            maxitem = s;
        }
        if (maxcnt > 1) {
            cout << maxitem << ":" << maxcnt << endl;
        }
        else {
            cout << "no repeat!!!" << endl;
        }
    }
    return 0;
}