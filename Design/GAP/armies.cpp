#include<bits/stdc++.h>

using namespace std;

#define LIMIT 101
#define loopThrough(limit) for(int x=0; x<limit ; x++)
#define loopTwiceThrough(xLimit, yLimit) for(int x=0; x<xLimit; x++) for(int y=0; y<yLimit; y++)

struct Position {
    int x, y;
};
struct Army {
    char name;
    Position position;
    vector<char> contester;
};

int width, height, contested;
char land[LIMIT][LIMIT], temp;
bool isArmy[LIMIT][LIMIT];
bool isConquered[LIMIT][LIMIT];
vector <Army> armies;
//bool delete_dp[LIMIT][LIMIT];
map<char, int> areas;
map<char, bool> isSavedBefore;
priority_queue<int> winners;

void printLand(){
    cout << '@';
    for(int x=0;x<width;x++){
        cout << x%10 ;
    }
    cout << endl;
    for(int x=0;x<height;x++){
        cout << x;
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
    memset(isArmy, false, sizeof isArmy);
    memset(isConquered, false, sizeof isConquered);
}

void incrementFaction(Army army) {
    areas[army.name]++;
    if (!isSavedBefore[army.name]) {
        isSavedBefore[army.name] = true;
        winners.push(-((int) army.name));
    }
//    cout << "INCREMENTING: " <<  army.name << ' ' << areas[army.name] << endl;
}

bool isEmpty(Position pos) {
    return land[pos.x][pos.y] == '.';
}

bool isEnemy(char name, Position pos) {
    return (int) land[pos.x][pos.y] > 96 && (int) land[pos.x][pos.y] <= 122 && land[pos.x][pos.y] != name;
}

bool isFaction(char name) {
    return (int)name > 96 && (int)name <= 122;
}

bool isAlly(char name, Position pos) {
    return (int) land[pos.x][pos.y] > 96 && (int) land[pos.x][pos.y] <= 122 && land[pos.x][pos.y] == name;
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

void conquer(Position p) {
//    cout << "Conquering: " << land[p.x][p.y] << " (x: " << p.x << ") (y: " << p.y << "). ";
    if(!isConquered[p.x][p.y]){
        isConquered[p.x][p.y] = true;
        loopThrough(armies.size()) {
            Position a_pos = armies[x].position;
            if (p.x == a_pos.x && p.y == a_pos.y) {
//                cout << endl << "We got him: " << a_pos.x << ',' << a_pos.y << ' ' << armies[x].name << endl;
                isConquered[p.x][p.y] = true;
                return;
            }
        }
    }
//    else { cout << "[ALREADY CONQUERED]" << endl; }
}

void setAsContestedArea(char name, int xx, int yy) {
    vector <Position> adjacents = getAdjacents(xx, yy);
    isConquered[xx][yy] = true;
    loopThrough(adjacents.size()) {
        Position pos = adjacents[x];
        if (!isConquered[pos.x][pos.y] && !isMountain(pos)) {
            if (isFaction(name)) {
                conquer(pos);
            }
            setAsContestedArea(name, pos.x, pos.y);
        }
    }
}

bool checkSurrounding(char name, int xx, int yy) {
    vector <Position> adjacents = getAdjacents(xx, yy);
    bool isNotContested = true;
    loopThrough(adjacents.size()) {
        Position pos = adjacents[x];
        if (isEmpty(pos)) {
            land[pos.x][pos.y] = name;
            isNotContested = isNotContested && checkSurrounding(name, pos.x, pos.y);
        } else if (isEnemy(name, pos)  && !isConquered[pos.x][pos.y] ) {
            isNotContested = false;
            setAsContestedArea(name, xx, yy);
        } else if (isAlly(name, pos) && !isConquered[pos.x][pos.y]) {
//            cout << "[Is ally] " <<  name << " (x: " << pos.x << ") (y: " << pos.y << ")" << endl;
            conquer(pos);
            isNotContested = isNotContested && checkSurrounding(name, pos.x, pos.y);
        }
    }
    return isNotContested;
}

void investigateArea() {
    int armiesCount = armies.size();
    loopThrough(armiesCount) {
        Army army = armies[x];
        if (!isConquered[army.position.x][army.position.y]) {
//            cout << "[Investigating] " <<  army.name << " (x: " << army.position.x << ") (y: " << army.position.y << ")" << endl;
            bool isAbsoluteWinner = checkSurrounding(army.name, army.position.x, army.position.y);
            if (isAbsoluteWinner) {
                incrementFaction(army);
            } else {
//                cout << "CONTESTED " <<  army.name << " (x: " << army.position.x << ") (y: " << army.position.y << ")";
                contested++;
//                cout << "[COUNT] "  << contested << endl;
            }
        } else {
//            cout << "[Not Counted] " <<  army.name << " (x: " << army.position.x << ") (y: " << army.position.y << ")" << endl;
        }
//        printLand();
//        getchar();
    }
}

int main() {

    ofstream outputFile("out_armies.txt");
    ifstream inFile("in3.txt");
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
                    Position position = {x, y};
                    Army army = {land[x][y], position};
                    if (isFaction(land[x][y])) {
                        isArmy[x][y] = true;
                        armies.push_back(army);
                    }
                }

            investigateArea();

            int winningArmyCount = winners.size();

            outputFile << "Case " << tc + 1 << ":" << endl;

            while (!winners.empty()) {
                char winnerName = -winners.top();
                winners.pop();
                int winnerAreas = areas[(char) (winnerName)];
                outputFile << winnerName << ' ' << winnerAreas << endl;
            }

            outputFile << "contested " << contested << endl;
        }
        cout << "Finish reading file, exiting..." << endl;
        inFile.close();
        outputFile.close();
    }

    return 0;

}
