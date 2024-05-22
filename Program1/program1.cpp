#include <utility>
using namespace std;
int main() {
    int A[] = {1,3,5,6,8};
    int B[] = {2,3,4,7,9};
    pair
    for(int a : A) {

    }

    //resulting arrays
    //A U B Array is C, A-B is D.
    int C[] = {};
    int D[] = {};
    int counter = 0;
    //A U B
    for (int a : A) {
        for (int b : B) {
            if(a != b) {
                C[counter] = b;
                counter++;
            }
            if(a != b) {
                C[counter] = a;
                counter++;
            }
        }
    }
    //union contains elements within array C.

    //A-B
    for(int a : A) {
        for (int b : B) {
            if(a == b) {
                if(a == b) {
                    
                }
            }
        }
    }
}