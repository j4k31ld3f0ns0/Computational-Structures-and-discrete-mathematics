/*
Hard code at least 4 4x4 binary matrices and determine if they are symmetric, asymmetric, antisymmetric, reflexive or irreflexive (or none of course).

Print the matrices and something like:
Matrix A
A - symmetric, reflexive
Matrix B
B – reflexive
Matrix C
C – none
Matrix D
D – irreflexive, asymmetric

four boolean checks: isSymmetric, isAsymmetric, isAntisymmetric, isReflexive, isIrreflexive

all binary matrices are 4x4.
    meaning that the primary diagonal will be positions 00, 11, 22, 33, 44
    additionally, the transposed position can be considered just a "flip" of the position. 01 and 10 are transposed.
*/

#include <iostream>

using namespace std;

//function prototypes
void printResults(int matrix[][4]);
bool isSymmetric(int matrix[][4]);
bool isAsymmetric(int matrix[][4]);
bool isAntisymmetric(int matrix[][4]);
bool isReflexive(int matrix[][4]);
bool isIrreflexive(int matrix[][4]);

int main()
{
    int matrixA[4][4] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
    int matrixB[4][4] = {
        {0,0,1,0},
        {0,0,0,0},
        {1,0,0,1},
        {0,0,1,0}
    };
    int matrixC[4][4] = {
        {1,0,0,1},
        {0,0,0,0},
        {1,0,1,0},
        {0,0,1,0}
    };
    int matrixD[4][4] = {
        {0,1,1,1},
        {0,0,1,1},
        {0,0,0,1},
        {0,0,0,0}
    };
    cout << "Matrix A";
    printResults(matrixA);
    cout << "Matrix B";
    printResults(matrixB);
    cout << "Matrix C";
    printResults(matrixC);
    cout << "Matrix D";
    printResults(matrixD);
}
void printResults(int matrix[][4]) {
    bool isSomething = false;
    if (isSymmetric(matrix)) {
        cout << " is Symmetric";
        isSomething = true;
    }
    if (isAsymmetric(matrix)) {
        if (isSomething) {
            cout << ", is Asymmetric";
        }
        else {
            cout << " is Asymmetric";
        }
        isSomething = true;
    }
    if (isAntisymmetric(matrix)) {
        if (isSomething) {
            cout << ", is Antisymmetric";
        }
        else {
            cout << " is Antisymmetric";
        }
        isSomething = true;
    }
    if (isReflexive(matrix)) {
        if (isSomething) {
            cout << ", is Reflexive";
        }
        else {
            cout << " is Reflexive";
        }
        isSomething = true;
    }
    if (isIrreflexive(matrix)) {
        if (isSomething) {
            cout << ", is Irreflexive";
        }
        else {
            cout << " is Irreflexive";
        }
        isSomething = true;
    }
    if (isSomething == false) {
        " is nothing.";
    }
    cout << endl;
}
bool isSymmetric(int matrix[][4]) {
    //only care about transposed positions. There are 6 total transposed positions
    //01, 02, 03, 12, 13, 23 and their transpositions.
    //top left corner is considered 00.
    for (int i = 0; i < 6; i++) {
        int row = 10; 
        int col = 10;
        //switch statement to switch position to be one of the 6 transposed positions.
        switch (i) {
            case 0: //01
                row = 0;
                col = 1;
                break;
            case 1: //02
                row = 0;
                col = 2;
                break;
            case 2: //03
                row = 0;
                col = 3;
                break;
            case 3: //12
                row = 1;
                col = 2;
                break;
            case 4: //13
                row = 1;
                col = 3;
                break;
            case 5: //23
                row = 2;
                col = 3;
                break;
        }
        if (matrix[row][col] != matrix[col][row]) {
            return false;
        }
    }
    return true;
}
bool isAsymmetric(int matrix[][4]) { //if 1, transposed spot MUST be zero.
    bool irref = isIrreflexive(matrix);
    for (int i = 0; i < 6; i++) {
        int row = 10;
        int col = 10;
        //switch statement to switch position to be one of the 6 transposed positions.
        switch (i) {
        case 0: //01
            row = 0;
            col = 1;
            break;
        case 1: //02
            row = 0;
            col = 2;
            break;
        case 2: //03
            row = 0;
            col = 3;
            break;
        case 3: //12
            row = 1;
            col = 2;
            break;
        case 4: //13
            row = 1;
            col = 3;
            break;
        case 5: //23
            row = 2;
            col = 3;
            break;
        }
        if (matrix[row][col] == 1 && matrix[col][row] == 1) {
            return false;
        }
    }
    if (irref) { //if all transposed spots pass, and it is irreflexive, it is true.
        return true;
    }
    else { //otherwise, false.
        return false;
    }
}
bool isAntisymmetric(int matrix[][4]) {
    for (int i = 0; i < 6; i++) {
        int row = 10;
        int col = 10;
        //switch statement to switch position to be one of the 6 transposed positions.
        switch (i) {
        case 0: //01
            row = 0;
            col = 1;
            break;
        case 1: //02
            row = 0;
            col = 2;
            break;
        case 2: //03
            row = 0;
            col = 3;
            break;
        case 3: //12
            row = 1;
            col = 2;
            break;
        case 4: //13
            row = 1;
            col = 3;
            break;
        case 5: //23
            row = 2;
            col = 3;
            break;
        }
        if (matrix[row][col] == 1 && matrix[col][row] == 1) {
            return false;
        }
    }
    return true;
}
bool isReflexive(int matrix[][4]) {
    //only care about main diagonal
    for (int i = 0; i < 4; i++) {
        if (matrix[i][i] == 0) {
            return false;
        }
    }
    return true;
}
bool isIrreflexive(int matrix[][4]) {
    //only care about main diagonal
    for (int i = 0; i < 4; i++) {
        if (matrix[i][i] == 1) {
            return false;
        }
        return true;
    }
}
