// Program3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void PrintA(int timesRepeated);
void PrintB(int timesRepeated);
void PrintChar(char c, int timesRepeated);

int main()
{
    cout << "Start sequence generation\n\n";
    for (int x = 5; x > 0; x--) {
        PrintA(x);
    }
    cout << endl;

    cout << "\nsequence generated.\n";
}
void PrintA(int timesRepeated = 0) {

    PrintChar('a', timesRepeated);
    
    //print A implementation above here
    PrintB(timesRepeated);
}
void PrintB(int timesRepeated = 0) {
    //print A implementation below here
    PrintChar('b', timesRepeated);
}
void PrintChar(char c, int timesRepeated) {
    for (int x = 0; x < timesRepeated; x++) {
        cout << c;
    }
}
