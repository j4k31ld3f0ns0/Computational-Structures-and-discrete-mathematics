/*
Monty Hall was a game show host years ago. 
The contestant would have 3 doors to choose from. 
One door had $$ and 2 had goats. 
The contestant would choose a door. Monty Hall would then show a door following these rules: Not a door the contestant chose, and not the winning door. 
Monty ALWAYS showed a goat. 
He'd then ask the contestant if he/she wanted to change doors. 
After the contestant made his/her final choice, Monty Hall would open the chosen door. 

Note, this is not “choose a new door”, it is simply switch or not switch.



Your job here is to simulate this. Make it automatic. 
Randomly choose the winning door. 
Then randomly choose one of the 3 doors as the contestant choice. 
Run this at least 100,000 times to calculate an accurate probability. 
You will be looking for the odds of winning if the contestant switches doors when given the opportunity. 
Also compute the probability of winning if he/she doesn't switch. 
In class, we will discuss the probability of each occurring and why. 
In your program, I'd like you to put in the comment section at the top your guesses as to the probability of winning if the contestant switches doors or not. 
Your grade will not depend on this number at all, so please be honest and type in your guess BEFORE running the program.

My Guess: I suspect that switching to the alternative door has a higher probability, just intuitively. I read a book with a section about explore/exploit algorithms and their probably for success, and while I didn't retain everything about them, it seems to me the grass is typically greener on the other side. <- i knew it my brain is huge
*/
#include <iostream>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    double switchedWR = 0;
    double stayedWR = 0;
    int totalIterations = 100000;
    double numWinsSwitched = 0;
    double numWinsStayed = 0;

    for (int i = 0; i < totalIterations; i++) {
        int chosenDoor = (rand() % 3);
        int winningDoor = (rand() % 3);
        bool isSwapping = (bool)(rand() % 2);

        //need to compute the door that is "revealed" first, and it cannot be the winning or chosen door
        int revealedDoor = 0;
        do {
            revealedDoor++;
        } while (revealedDoor == chosenDoor || revealedDoor == winningDoor);
        int swapOption = 0;
        do {
            swapOption++;
        } while (swapOption == revealedDoor || swapOption == chosenDoor);

        if (isSwapping) {
            chosenDoor = swapOption;
        }
        if (chosenDoor == winningDoor) {
            if (isSwapping) {
                numWinsSwitched++;
            }
            else {
                numWinsStayed++;
            }
        }
    }
    double totalWins = numWinsStayed + numWinsSwitched;
    switchedWR = (double)(numWinsSwitched / totalWins);
    stayedWR = (double)(numWinsStayed / totalWins);
    cout << "Switched Win Rate: " << switchedWR << endl;
    cout << "Stayed Win Rate: " << stayedWR << endl;
}
