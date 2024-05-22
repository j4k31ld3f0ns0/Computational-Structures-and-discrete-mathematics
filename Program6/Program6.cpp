/*
Print out the truth table for the following proposition using the variables a, b, c, d, e.
The output should contain the header and 32 more lines for the table.
You should use capital a (A) for AND, and capital v (V) for OR in the output.

Proposition:
(( c V ~d ) A b ) A ~( d V a A e )

need to perform basic operations
AND - multiplication equivalent
OR - addition equivalent
NOT - just use the not symbol in the code
Parenthesis to dictate operator precedence.
*/

#include <iostream>
using namespace std;

bool calculate(bool a, bool b, bool c, bool d, bool e);

int main()
{
    cout << "a b c d e | answer" << endl;
    cout << "----------|-------" << endl;
    bool a = false;
    bool b = false;
    bool c = false;
    bool d = false;
    bool e = false;
    for (int A = 0; A < 2; A++) {
        for (int B = 0; B < 2; B++) {
            for (int C = 0; C < 2; C++) {
                for (int D = 0; D < 2; D++) {
                    for (int E = 0; E < 2; E++) {

                        if (A == 1) {
                            a = true;
                        }
                        else {
                            a = false;
                        }
                        if (B == 1) {
                            b = true;
                        }
                        else {
                            b = false;
                        }
                        if (C == 1) {
                            c = true;
                        }
                        else {
                            c = false;
                        }
                        if (D == 1) {
                            d = true;
                        }
                        else {
                            d = false;
                        }
                        if (E == 1) {
                            e = true;
                        }
                        else {
                            e = false;
                        }

                        bool ans = calculate(a, b, c, d, e);
                        cout << int(a) << " " << int(b) << " " << int(c) << " " << int(d) << " " << int(e) << " | " << int(ans) << endl;
                    }
                }
            }
        }
    }
}
bool calculate(bool a, bool b, bool c, bool d, bool e) {
    //Proposition:
    //((c V ~d) A b) A ~(d V a A e)
    return ((c || !d) && b) && !(d || a && e);
}

