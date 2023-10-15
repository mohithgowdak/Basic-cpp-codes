#include <iostream>
#include <vector>

using namespace std;

const int TOTAL_MISSIONARIES = 3;
const int TOTAL_CANNIBALS = 3;

struct State {
    int missionariesLeft;
    int cannibalsLeft;
    int missionariesRight;
    int cannibalsRight;
    bool boatLeft; // true for left, false for right
};

bool isSafe(int missionaries, int cannibals) {
    if ((missionaries >= 0 && missionaries <= TOTAL_MISSIONARIES) &&
        (cannibals >= 0 && cannibals <= TOTAL_CANNIBALS) &&
        (missionaries == 0 || missionaries >= cannibals))
        return true;
    return false;
}

void printState(State state) {
    cout << "Missionaries on the left: " << state.missionariesLeft << " Cannibals on the left: " << state.cannibalsLeft
         << " | ";
    cout << "Missionaries on the right: " << state.missionariesRight << " Cannibals on the right: " << state.cannibalsRight << " | ";
    if (state.boatLeft)
        cout << "Boat is on the left" << endl;
    else
        cout << "Boat is on the right" << endl;
}

bool isGoalState(State state) {
    return state.missionariesRight == TOTAL_MISSIONARIES && state.cannibalsRight == TOTAL_CANNIBALS;
}

bool isInitialState(State state) {
    return state.missionariesLeft == TOTAL_MISSIONARIES && state.cannibalsLeft == TOTAL_CANNIBALS &&
           state.missionariesRight == 0 && state.cannibalsRight == 0 && state.boatLeft == true;
}

bool isExplored(State state, vector<State> &explored) {
    for (const auto &s : explored) {
        if (s.missionariesLeft == state.missionariesLeft && s.cannibalsLeft == state.cannibalsLeft &&
            s.missionariesRight == state.missionariesRight && s.cannibalsRight == state.cannibalsRight &&
            s.boatLeft == state.boatLeft)
            return true;
    }
    return false;
}

void moveBoat(State &state, int missionaries, int cannibals) {
    if (state.boatLeft) {
        state.missionariesLeft -= missionaries;
        state.cannibalsLeft -= cannibals;
        state.missionariesRight += missionaries;
        state.cannibalsRight += cannibals;
    } else {
        state.missionariesLeft += missionaries;
        state.cannibalsLeft += cannibals;
        state.missionariesRight -= missionaries;
        state.cannibalsRight -= cannibals;
    }
    state.boatLeft = !state.boatLeft;
}

void solve(State currentState, vector<State> &explored) {
    if (isGoalState(currentState)) {
        printState(currentState);
        cout << "Solution found!" << endl;
        return;
    }
    if (!isInitialState(currentState)) {
        if (!isSafe(currentState.missionariesLeft, currentState.cannibalsLeft) ||
            !isSafe(currentState.missionariesRight, currentState.cannibalsRight))
            return;
    }
    if (isExplored(currentState, explored))
        return;

    explored.push_back(currentState);
    printState(currentState);

    // Generate all possible moves
    for (int m = 0; m <= 2; m++) {
        for (int c = 0; c <= 2; c++) {
            if (m + c > 0 && m + c <= 2) {
                if (currentState.boatLeft) {
                    moveBoat(currentState, m, c);
                    solve(currentState, explored);
                    moveBoat(currentState, -m, -c);
                } else {
                    moveBoat(currentState, m, c);
                    solve(currentState, explored);
                    moveBoat(currentState, -m, -c);
                }
            }
        }
    }
}

int main() {
    State initial = {3, 3, 0, 0, true};
    vector<State> explored;
    solve(initial, explored);
    return 0;
}
