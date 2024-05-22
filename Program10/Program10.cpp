/*
    Ask for user input for a series of ordered pairs comprised of integers.  
    Print out the relation, the domain, and range.  The output should be properly
    formatted, though if you have a trailing "," it's not a big deal.  Output should
    look similar to the following:

    Relation = {(1,2), (2,1), (3,2), (4, 5)}
    Domain = {1, 2, 3, 4}
    Range = {1, 2, 5}
*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

class orderedPair {
public:
    int x;
    int y;
    orderedPair(int x, int y) {
        this->x = x;
        this->y = y;
    }
    string printPair() {
        string output;
        output = ("(" + to_string(this->x) + "," + to_string(this->y) + ")");
        return output;
    }
};

int main()
{
    bool moreNumbers = true;
    list<orderedPair> pairs;
    cout << "How many pairs are you entering?: ";
    int numPairs;
    cin >> numPairs;
    for (int i = 0; i < numPairs; i++) {
        int x;
        int y;
        cout << "Enter the two numbers for the pair separated by a space: ";
        cin >> x;
        cin >> y;
        orderedPair newPair = orderedPair(x, y);
        pairs.push_back(newPair);
    }
    bool isFirst = true;
    cout << "relation: {";
    for (orderedPair currentPair : pairs) {
        if (!isFirst) {
            cout << ", ";
        }
        cout << currentPair.printPair();
        isFirst = false;
    }
    isFirst = true;
    cout << "}" << endl;
    cout << "domain: {";
    for (orderedPair currentPair : pairs) {
        if (!isFirst) {
            cout << ", ";
        }
        cout << currentPair.x;
        isFirst = false;
    }
    cout << "}" << endl;
    isFirst = true;
    cout << "Range: {";
    for (orderedPair currentPair : pairs) {
        if (!isFirst) {
            cout << ", ";
        }
        cout << currentPair.y;
        isFirst = false;
    }
    cout << "}" << endl;
}   