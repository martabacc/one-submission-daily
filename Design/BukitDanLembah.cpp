#include<cstdio>
#include<iostream>
using namespace std;


char bukitDanLembah[100][100];
bool isStillCounted[100][100];
int limitX, limitY;

bool isBukit(int x,int y){
    bool isOnBound = x < limitX && y < limitY && x >= 0 && y >= 0;
    return isOnBound && bukitDanLembah[x][y] == 'B';
}

void colonize(int x, int y){
    if(!isStillCounted[x][y]) return;
    isStillCounted[x][y] = false;

    bool yUp= isBukit(x,y+1);
    bool xUp = isBukit(x+1,y);
    bool yDown= isBukit(x,y-1);
    bool xDown = isBukit(x-1,y);

    if(xUp) colonize(x+1, y);
    if(yUp) colonize(x, y+1);
    if(yDown) colonize(x, y-1);
    if(xDown) colonize(x-1, y);
}

int main() {
    cin >> limitX >> limitY;
    int maxSum = 0;

    for(int x=0;x<limitX;x++)
        for(int y=0;y<limitY;y++) isStillCounted[x][y]=false;

    for(int x=0;x<limitX;x++)
        for(int y=0;y<limitY;y++){
            cin >> bukitDanLembah[x][y];
            isStillCounted[x][y] = true;
        }

    for(int x=0;x<limitX;x++)
        for(int y=0;y<limitY;y++){
            if(isBukit(x,y) && isStillCounted[x][y]) {
                maxSum++;
                colonize(x,y);
            }
        }

    cout << maxSum << endl;

    return 0;


}