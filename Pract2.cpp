#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int numStates, numSymbols, numAcceptStates;

    cout << "Enter number of states: ";
    cin >> numStates;

    cout << "Enter number of input symbols: ";
    cin >> numSymbols;

    vector<char> inputSymbols(numSymbols);
    cout << "Enter input symbols: ";
    for (int i = 0; i < numSymbols; ++i) {
        cin >> inputSymbols[i];
    }

    int startState;
    cout << "Enter start state: ";
    cin >> startState;

    cout << "Enter number of accepting states: ";
    cin >> numAcceptStates;

    vector<int> acceptStates(numAcceptStates);
    cout << "Enter accepting states: ";
    for (int i = 0; i < numAcceptStates; ++i) {
        cin >> acceptStates[i];
    }

    unordered_map<int, unordered_map<char, int>> transitionTable;
    int numTransitions;
    cout << "Enter number of transitions: ";
    cin >> numTransitions;

    cout << "Enter transitions in the format (fromState inputSymbol toState):" << endl;
    for (int i = 0; i < numTransitions; ++i) {
        int fromState, toState;
        char inputSymbol;
        cin >> fromState >> inputSymbol >> toState;
        transitionTable[fromState][inputSymbol] = toState;
    }

    string inputString;
    cout << "Enter input string: ";
    cin >> inputString;

    int currentState = startState;
    bool isValid = true;

    for (char ch : inputString) {
        if (transitionTable[currentState].find(ch) == transitionTable[currentState].end()) {
            isValid = false;
            break;
        }
        currentState = transitionTable[currentState][ch];
    }

    if (isValid) {
        isValid = false;
        for (int acceptState : acceptStates) {
            if (currentState == acceptState) {
                isValid = true;
                break;
            }
        }
    }

    if (isValid) {
        cout << "Valid String" << endl;
    }
    else {
        cout << "Invalid String" << endl;
    }
    return 0;
}
