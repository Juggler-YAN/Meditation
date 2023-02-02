#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int i1, i2;
    while (cin >> i1 >> i2) {
        try {
            if (i2 == 0) {
                throw runtime_error("Divisor can't be 0!!!");
            }
            cout << i1/i2 << endl;
        }
        catch (runtime_error err) {
            cout << err.what() << endl;
            cout << "Try again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}