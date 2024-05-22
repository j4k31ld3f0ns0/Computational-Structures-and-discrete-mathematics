// Program4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Convert between bases manually.
Start with base 10 and convert to bases 8, 16, 2.
Do NOT use built-in conversion methods for the conversion.  You must do your own math to compute the values.
Input the value to be converted, and this should be the only input for this program.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ConvertToBase(int dividend, int base);
void ConvertToBase(int dividend, vector<int>& returnedValues, int base);
float pow(int power, int base);

int main()
{
    int input;
    cout << "Enter an integer to convert: ";
    cin >> input;
    
    string base8 = ConvertToBase(input, 8);
    string base16 = ConvertToBase(input, 16);
    string base2 = ConvertToBase(input, 2);
    cout << input << " in base 8 is: " << base8; 
    cout << endl;

    cout << input << " in base 16 is: " << base16;
    cout << endl;

    cout << input << " in base 2 is: " << base2;
    cout << endl;
}
string ConvertToBase(int dividend, int base) {
    vector<int> returnedValues;
    string finalValueString = "";

    ConvertToBase(dividend, returnedValues, base);

    //convert Vector to correct integer value, iterating backwards through vector
    int power = returnedValues.size();
    for (vector<int>::reverse_iterator i = returnedValues.rbegin(); i != returnedValues.rend(); ++i) {
       
        if (*i <= 10) {
            finalValueString.append(to_string(*i));
        }
        else if (*i <= 15) {
            switch (*i) {
            case 10:
                finalValueString.append("A");
                break;
            case 11:
                finalValueString.append("B");
                break;
            case 12:
                finalValueString.append("C");
                break;
            case 13:
                finalValueString.append("D");
                break;
            case 14:
                finalValueString.append("E");
                break;
            case 15:
                finalValueString.append("F");
                break;
            }
        }
        else if (*i > 15) {
            finalValueString = "Power too large. Not implemented.";
        }
    }

    return finalValueString;
}
void ConvertToBase(int dividend, vector<int> &returnedValues, int base) {
    if (dividend < base) { //determine if its the last one or not
        returnedValues.push_back(dividend);
        return;
    }
    else {
        int newDividend = dividend / base;
        int remainder = dividend % base;
        returnedValues.push_back(remainder);
        ConvertToBase(newDividend, returnedValues, base);
    }
}
float pow(int power, int base) { //only works on powers of two or greater. I ended up not needing this, but im proud of this implementation so im keeping it here >:)
    int finalValue = base;
    if (power >= 2) {
        for (int i = 1; i < power; i++) {
            finalValue = finalValue * base;

        }
        return finalValue;
    }
    else {
        if (power < 0) {
            //fractional powers
            for (int i = 1; i > power; i--) {
                finalValue = finalValue * ((float)(1 / finalValue));
            }
        }
        else if(power == 1) {
            return base;
        }
    }
}
 