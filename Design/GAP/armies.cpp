#include<bits/stdc++.h>

using namespace std;

#define LIMIT 101
#define loopThrough(limit) for(int x=0; x<limit ; x++)
#define PROBLEMATIC_AREA '@'
#define loopTwiceThrough(xLimit, yLimit) for(int x=0; x<xLimit; x++) for(int y=0; y<yLimit; y++)

struct Position {
    int x, y;
};
struct Army {
    char name;
    Position position;
    bool isConquered;
    vector<char> contester;
};

int width, height, contested;
char land[LIMIT][LIMIT], temp;
vector <Army> armies;
bool delete_dp[LIMIT][LIMIT];
map<char, int> areas;
map<char, bool> isSavedBefore;
priority_queue<int> winners;

void resetIteratorDelete() {
    loopTwiceThrough(LIMIT, LIMIT) delete_dp[x][y] = true;
}


void printLand(){
    for(int x=0;x<height;x++){
        for(int y=0;y<width; y++){
            cout << land[x][y];
        }
        cout << endl;
    }
}

void initiateVariables() {
    map<char, bool> newSavedBefore;
    priority_queue<int> newSortedWinner;
    map<char, int> newAreas;
    isSavedBefore = newSavedBefore;
    winners = newSortedWinner;
    areas = newAreas;
    contested = 0;
    armies.clear();
}

void incrementFaction(Army army) {
    areas[army.name]++;
    if (!isSavedBefore[army.name]) {
        isSavedBefore[army.name] = true;
        winners.push(-((int) army.name));
    }
}

bool isEmpty(Position pos) {
    return land[pos.x][pos.y] == '.';
}

bool isEnemy(char name, Position pos) {
    return (int) land[pos.x][pos.y] > 96 && (int) land[pos.x][pos.y] <= 122 && land[pos.x][pos.y] != name;
}

bool isAlly(char name, Position pos) {
    return (int) land[pos.x][pos.y] > 96 && (int) land[pos.x][pos.y] <= 122 && land[pos.x][pos.y] == name;
}

bool isFaction(Position pos) {
    return (int) land[pos.x][pos.y] > 96 && (int) land[pos.x][pos.y] <= 122;
}

bool isMountain(Position pos) {
    return land[pos.x][pos.y] == '#';
}

Position createPosition(int x, int y) {
    Position pos = {x, y};
    return pos;
}

vector <Position> getAdjacents(int row, int column) {
    vector <Position> results;
    if (row - 1 >= 0)
        results.push_back(createPosition(row - 1, column));
    if (row + 1 < height)
        results.push_back(createPosition(row + 1, column));
    if (column + 1 < width)
        results.push_back(createPosition(row, column + 1));
    if (column - 1 >= 0)
        results.push_back(createPosition(row, column - 1));
    return results;
}

void conquer(Position position) {
    loopThrough(armies.size()) {
        Position armyPosition = armies[x].position;
        if (position.x == armyPosition.x && position.y == armyPosition.y) {
            cout <<  << ' GOT CONQUERED!' << endl;
            armies[x].isConquered = true;
            return;
        }
    }
    cout << "GAK NEMU" << endl;
}

void setAsContestedArea(char name, int x, int y) {
    vector <Position> adjacents = getAdjacents(x, y);
    delete_dp[x][y] = false;
    loopThrough(adjacents.size()) {
        Position pos = adjacents[x];
        if (delete_dp[pos.x][pos.y] && !isMountain(pos)) {
            if (!isEmpty(pos) || isEnemy(name, pos)) {
                cout << "WEWE" << endl;
                conquer(pos);
            }
            setAsContestedArea(name, pos.x, pos.y);
        }
    }
}

bool checkSurrounding(char name, int x, int y) {
    vector <Position> adjacents = getAdjacents(x, y);
    bool isNotContested = true;
    loopThrough(adjacents.size()) {
        Position pos = adjacents[x];
        if (isEmpty(pos)) {
//            cout << x << " " << y << " is empty" << endl;
            land[pos.x][pos.y] = name;
            isNotContested = isNotContested && checkSurrounding(name, pos.x, pos.y);
        } else if (isEnemy(name, pos)) {
//            cout << name << " has enemy: " << land[pos.x][pos.y] << endl;
            isNotContested = false;
            resetIteratorDelete();
            setAsContestedArea(name, pos.x, pos.y);
        } else if (isAlly(name, pos)) {
//            cout << name << " has ally: " << land[pos.x][pos.y] << endl;
            conquer(pos);
        }
    }
    return isNotContested;
}

void investigateArea() {
    int armiesCount = armies.size();
    loopThrough(armiesCount) {
        Army army = armies[x];
        if (!army.isConquered) {
            bool isAbsoluteWinner = checkSurrounding(army.name, army.position.x, army.position.y);
            if (isAbsoluteWinner) {
                cout << "WIN " << army.name << " (x: " << army.position.x << ") (y: " << army.position.y << ")"
                     << endl;
                incrementFaction(army);
            } else {
                cout << "Wew conquered!" << army.name << " (x: " << army.position.x << ") (y: " << army.position.y << ")"
                     << endl;
                contested++;
            }
        } else {
            cout << "NOT COUNTED: " << army.name << " (x: " << army.position.x << ") (y: " << army.position.y << ")"
                 << endl;
        }
        printLand();
//        getchar();

    }
}

int main() {

    ofstream outputFile("out_armies.txt");
    ifstream inFile("in2.txt");
    string line;
    if (inFile.is_open()) {
        cout << "Start reading file" << endl;
        int TC;
        inFile >> TC;
        for (int tc = 0; tc < TC; tc++) {
            cout << "Running testcase " << tc + 1 << endl;
            initiateVariables();
            inFile >> height >> width;
            loopTwiceThrough(height, width) {
                    inFile >> land[x][y];
                    if (land[x][y] != '#' && land[x][y] != '.') {
                        Position position = {x, y};
                        Army army = {land[x][y], position};
                        army.isConquered = false;
                        armies.push_back(army);
                    }
                }

            investigateArea();

            int winningArmyCount = winners.size();

            outputFile << "Case " << tc + 1 << endl;

            while (!winners.empty()) {
                char winnerName = -winners.top();
                winners.pop();
                int winnerAreas = areas[(char) (winnerName)];
                outputFile << winnerName << ' ' << winnerAreas << endl;
            }

            outputFile << "contested " << contested << endl;
        }
    }

}
