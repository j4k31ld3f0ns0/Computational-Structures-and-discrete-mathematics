// Program1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
using namespace std;

int main()
{
    int A[] = { 1,3,5,6,8 };
    int B[] = { 2,3,4,7,9 };


    cout << "A is [";
    for (char c: A) {
        cout << c << " ";
    }
    cout << "] " << endl;
    cout << "B is [";
    for (char c : B) {
        cout << c << " ";
    }
    cout << "] " << endl;

    //resulting arrays
    //A U B Array is C, A-B is D.
    int C[10];
    int D[5];
    int counter = 0;
    //A U B
    for (int a : A) {
        for (int b : B) {//adds all B elements
            if (a != b) { //element in A is not in B, add to result array
                C[counter] = b;
                counter++;
            }
            else if (a == b) {
                C[counter] = a;
                
            }
        }
        
    }
    counter = 0;
    //A-B
    for (int a : A) {
        for (int b : B) {
            if (a != b) {
                D[counter] = a;
            }
        }
    }
}