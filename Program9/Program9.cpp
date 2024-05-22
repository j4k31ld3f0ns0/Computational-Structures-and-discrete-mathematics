/*
Matrix multiplication/addition programming problem.  Only allow 2x2, 2x3, 3x2, and 3x3 matrices.  
Hard code a matrix of each size to use in the calculations.  
This program should use human input to determine which matrices to use (M and N) and whether to use addition or multiplication (the whole list of possibilities is too big).

Print out M, N, and the results for the choice.  These are NOT binary matrices.

Personal Notes:
two matrices, M and N
*/
#include <iostream>
using namespace std;

int main()
{
    
}
class matrix {
    int rows = 0;
    int columns = 0;
    
    matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        if()
    }
    bool canBeAddedTo(matrix n) {
        if (n.rows == this->rows && n.columns == this->columns) {
            return true;
        }
        else {
            return false;
        }
    }
    bool canBeMultipliedTo(matrix n) {
        if (this->columns == n.rows) {
            return true;
        }
        else {
            return false;
        }
    }
};
