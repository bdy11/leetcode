#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
using namespace std;

int main() {
    // output should be 11110101
    uint8_t a = 0b01011111;
    cout << a<< endl;;
    uint8_t b = a;
    b = b << 4;   // 0b11110000;
    a = a >> 4;   // 0b00000101
    cout << a <<endl;
    a = a | b;
    int c;
    cout << a;
    return 0;
}