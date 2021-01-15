#include <iostream>
#include "base64.h"

using namespace std;

int main() {
    string len;

    cout << "Enter message to encode: ";
    getline(cin, len);
    cout << base64_encode(len);
    cout << endl;
    cout << endl;

    cout << "Enter message to decode: ";
    getline(cin, s);
    cout << base64_decode(s);
    cout << endl;
}
