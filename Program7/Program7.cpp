/*
    Input 2 numbers, n and r.  Compute and show the values of each permutation and combination,
    both with and without repeats.  Output should be the 4 numbers C(n,r) and P(n,r) for
    repeats and without repeats.  

    NOTE: when entering n and r, care should be taken with values above 8.  
    Try to figure out why and how to work around it, but don't worry about it for 
    the program.
    values above 8 introduce an overflow problem.
*/
#include <iostream>
using namespace std;

long permutations(bool hasRepeats, long n, long r, long iter = 0);
long combinations(bool hasRepeats, long n, long r);

int main()
{
    cout << "Program 7 Jake Ildefonso\n";
    long n = 0;
    long r = 0;
    cout << "Enter an integer for n: ";
    cin >> n;
    cout << "Enter an integer for r: ";
    cin >> r;


}
long permutations(bool hasRepeats, long n, long r, long iter = 1) {
    if (hasRepeats) { //n^r
        //just a bunch of for loops + recusion
        cout << "With repeats: " << endl;
        for (int i = 0; i < n; i++) {
            if (iter == r) {
                return 0;
            }
            cout << i;
            //recursive function call to print next permutations
            permutations(hasRepeats, n, r, (iter += 1));
            if (iter == 0) { //first recursion call. Print newline
                cout << endl;
            }
        }
        
    }
    else {
        //just a bunch of for loops utilizing a dictionary to eliminate specific items
    }
}
long combinations(bool hasRepeats, long n, long r) {
    if (hasRepeats) { //C(n+r-1,r)
        combinations(false, (n + r - 1), r);
    }
    else {

    }
}
