/*
Write a program to generate a hash value of any word or sentence.Enter a “sentence” that
may be as small as a single word.Then compute a hash of the “sentence” using the numeric
value of each letter(A = a = 1, Z = z = 26, space = 31).Use 31 as the hash function.

Your program might give these results
input     output   why(not part of output)
abc       6        (1 + 2 + 3) % 31
zabc      1        (26 + 1 + 2 + 3) % 31

Whitespace is considered a +0

*/


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    int numericValue = 0;
    int hash = 0;
    cout << "Enter a sentence: ";
    getline(cin, sentence);     

    for (char c : sentence) {
        switch (c) {
        case 'a':
        case 'A':
            numericValue = numericValue + 1;
            break;
        case 'b':
        case 'B':
            numericValue = numericValue + 2;
            break;
        case 'c':
        case 'C':
            numericValue = numericValue + 3;
            break;
        case 'd':
        case 'D':
            numericValue = numericValue + 4;
            break;
        case 'e':
        case 'E':
            numericValue = numericValue + 5;
            break;
        case 'f':
        case 'F':
            numericValue = numericValue + 6;
            break;
        case 'g':
        case 'G':
            numericValue = numericValue + 7;
            break;
        case 'h':
        case 'H':
            numericValue = numericValue + 8;
            break;
        case 'i':
        case 'I':
            numericValue = numericValue + 9;
            break;
        case 'j':
        case 'J':
            numericValue = numericValue + 10;
            break;
        case 'k':
        case 'K':
            numericValue = numericValue + 11;
            break;
        case 'l':
        case 'L':
            numericValue = numericValue + 12;
            break;
        case 'm':
        case 'M':
            numericValue = numericValue + 13;
            break;
        case 'n':
        case 'N':
            numericValue = numericValue + 14;
            break;
        case 'o':
        case 'O':
            numericValue = numericValue + 15;
            break;
        case 'p':
        case 'P':
            numericValue = numericValue + 16;
            break;
        case 'q':
        case 'Q':
            numericValue = numericValue + 17;
            break;
        case 'r':
        case 'R':
            numericValue = numericValue + 18;
            break;
        case 's':
        case 'S':
            numericValue = numericValue + 19;
            break;
        case 't':
        case 'T':
            numericValue = numericValue + 20;
            break;
        case 'u':
        case 'U':
            numericValue = numericValue + 21;
            break;
        case 'v':
        case 'V':
            numericValue = numericValue + 22;
            break;
        case 'w':
        case 'W':
            numericValue = numericValue + 23;
            break;
        case 'x':
        case 'X':
            numericValue = numericValue + 24;
            break;
        case 'y':
        case 'Y':
            numericValue = numericValue + 25;
            break;
        case 'z':
        case 'Z':
            numericValue = numericValue + 26;
            break;
        }
    }
    hash = numericValue % 31;
    cout << ("The hash of " + sentence + " is " + to_string(hash));
}
