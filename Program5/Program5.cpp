/*
Print the truth table for any 2 variable propositional function.  

Ask 3 questions:
Question 1- Do you want to use And or Or?
Question 2- Do you want to NOT p?
Question 3- Do you want to NOT q?
Use: V (or), A (and), ~ (not)

Output:
3 column truth table: p, q, answer.  <- all 4 COLUMNS for truth table
Other intermediate columns are optional.

Output (after the questions) should be 5 lines long:
     Column headers, 4 lines for the table. <- all 4 ROWS for truth table
*/


#include <iostream>
#include <string>
#include <tuple>
using namespace std;

bool calculateAnswer(bool p, bool q, bool hasAnd, bool hasOr, bool notP, bool notQ);

int main()
{
    bool hasAnd = false;
    bool hasOr = false;
    bool hasNotP = false;
    bool hasNotQ = false;
    string input;
    
    cout << "Do you want to use And or Or? (V for Or, A for And): ";
    cin >> input;
    switch (input[0]) {
    case 'v':
    case 'V':
        hasOr = true;
        break;
    case 'a':
    case 'A':
        hasAnd = true;
    }

    cout << "Do you want to NOT p? (Y for yes/N for no):";
    cin >> input;
    switch (input[0]) {
    case 'y':
    case 'Y':
        hasNotP = true;
        break;
    default:
        hasNotP = false;
    }

    cout << "Do you want to NOT q? (Y for yes/N for no):";
    cin >> input;
    switch (input[0]) {
    case 'y':
    case 'Y':
        hasNotQ = true;
        break;
    default:
        hasNotQ = false;
    }
    

    //populate truth table

    cout << " p q | answer";
    cout << endl;
    cout << "-------------";
    cout << endl;
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
            bool pBool;
            bool qBool;
            if (p == 0) {
                pBool = false;
            }
            else {
                pBool = true;
            }
            if (q == 0) {
                qBool = false;
            }
            else {
                qBool = true;
            }
            cout << " ";
            cout << p;
            cout << " ";
            cout << q;
            cout << " | ";
            cout << int(calculateAnswer(pBool, qBool, hasAnd, hasOr, hasNotP, hasNotQ));
            cout << endl;
        }
    }
    
}

bool calculateAnswer(bool p, bool q, bool hasAnd, bool hasOr, bool notP, bool notQ) {
    if (notP) {
        p = !p;
    }
    if (notQ) {
        q = !q;
    }
    if (hasAnd) {
        return (p && q);
    }
    if (hasOr) {
        return (p || q);
    }
    return false; //should not reach this point with correct input
}
