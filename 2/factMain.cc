// factMain.cc
#include <iostream>
#include "Chapter6.h"

int fact(int);

int main() {
    int num;
    std::cin >> num;
    std::cout << fact(num) << std::endl;
    return 0;
}