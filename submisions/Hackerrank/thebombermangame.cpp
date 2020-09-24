#include<bits/stdc++.h>
#define LL long long
#define lim 201
using namespace std;
int maze[lim][lim];
int R, C;
LL N;

void bombCell(int x, int y){
    maze[x][y]=0;
    //cout << "[BOMB " << x << ',' << y << "]" << endl;
    
    if(x+1 < C && maze[x+1][y]!=1 ) {
        maze[x+1][y] =0;
        //cout << "bombed x+1 at " << x+1 << ',' << y << endl;
    }
    if(x-1 >= 0){
         maze[x-1][y] =0;
        //cout << "bombed x-1 at " << x-1 << ',' << y << endl;
    }
    if(y+1 < R && maze[x][y+1]!=1) {
        maze[x][y+1] =0;
        //cout << "bombed y+1 at " << x << ',' << y+1 << endl;
    }
    if(y-1 >= 0) {
        maze[x][y-1] =0;
        //cout << "bombed y-1 at " << x << ',' << y-1 << endl;
    }
}

void reiterate(){
    for(int x=0;x<R;x++){
        for(int y=0;y<C;y++){
            if(maze[x][y]==1){
                bombCell(x,y);
            }
            else if(maze[x][y]>0){
                maze[x][y]--;
            }
        }
    }
}

void plantBomb(){
    for(int x=0;x<R;x++){
        for(int y=0;y<C;y++){
            if(maze[x][y]==0){
                maze[x][y]=3;
            }
            else if(maze[x][y]>0){
                maze[x][y]--;
            }
            else if(maze[x][y]==1){
                bombCell(x,y);
            }
        }
    }
}

void printResult()
{
    //cout<< 'X';
    //for(int y=0;y<C;y++) cout << y ;
    //cout << endl;
	for(int x=0;x<R;x++){
        //cout << x;
		for(int y=0;y<C;y++){
			cout << (maze[x][y] == 0 ? '.' : 'O');
		}
		cout << endl;
	}	
}

int main()
{
	char temp;
	cin >> R >> C >> N;
	
	for(int x=0;x<R;x++){
		for(int y=0;y<C;y++){
			cin >> temp;
			maze[x][y] = (temp == '.' ? 0 : 3);
		}
	}	
    
	int ptr=0;
    int mod = N % 5;
	for(int x=0;x<mod;x++)
	{
        ptr++;
        if(ptr==2){
            plantBomb();
            ptr=0;
        }
        else reiterate();
	}
	
    printResult();
	
}
