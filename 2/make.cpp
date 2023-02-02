#include <iostream>
#include <fstream>

using namespace std;

#define N "19"
#define NUM 26


int main() {
    string name = string("chapter") + string(N) + string(".md");
    ofstream ofs(name);
    ofs << string("# Chapter ") + string(N) << endl;
    ofs << endl;
    for (int i = 1; i <= NUM; ++i) {
        ofs << string("### Q") + to_string(i) << endl;
        ofs << endl;
        ofs << string("```c++") << endl;
        ofs << endl;
        ofs << string("```");
        if (i != NUM) {
            ofs << endl;
            ofs << endl;
        }
    }
    ofs.close();
    return 0;
}