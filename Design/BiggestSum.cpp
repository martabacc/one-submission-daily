#include<cstdio>
#include<iostream>
#define LIM 100
using namespace std;
int regionCounter[LIM][LIM];
int tinggi, lebar;
char peta[LIM][LIM];


int max(int a, int b) {
    return a > b ? a : b;
}
int apakahBukit(char titik){
    return titik == 'B' ? 1 : 0;
}

int isANewTeritory(int x, int y, char titik){
    if(x==0 && y==0) return apakahBukit(titik);
    if(y==0){
        return apakahBukit(peta[x-1][y]);
    }
    if( x==0 )
        return apakahBukit(peta[x][y-1]);

    return apakahBukit(peta[x-1][y-1]) && apakahBukit(peta[x][y-1]) && apakahBukit(peta[x-1][y]);
}

int main() {
    cin >> tinggi >> lebar;
    char tempTitik;
    int sumTeritori;


    for(int x=0;x<tinggi;x++)
        for(int y=0;y<lebar;y++){
            regionCounter[x][y] = 0;
            cin >> peta[x][y];
        }

    for(int x=0;x<tinggi;x++)
        for(int y=0;y<lebar;y++){
            regionCounter[x][y] = isANewTeritory(x,y,tempTitik);
            if()
        }

    cout << "Jumlah perbukitan = " << sumTeritori << endl;



}