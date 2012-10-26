/* Ein ganz schlechtes C++-Programm (weil es von dem im System
 * verwendeten Zeichensatz abhaengt, statt ctype.h zu benutzen).
 */

#include <iostream>

using namespace std;

main() {
    char c;
    while (cin.get(c)) {
        if (c >= 'A' && c <= 'Z') {
            cout << char(c+32);
        } else if (c >= 'a' && c <= 'z') {
            cout << char(c-32);
        } else {
            cout << c;
        }
    }    
}
