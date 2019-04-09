#include<bits/stdc++.h>
using namespace std;
vector<int> arr1; vector< vector<int> > arr2;vector<int> a_aksen;
vector<int> res; vector< vector<int> > res2;
int i , j, d, la,x,y,coeficient,totSize;
char rules;
vector< pair<int, int > > probs; 

int affectedByRules(int number){
    if(rules=='+') return number+coeficient;
    else if(rules=='-') return number-coeficient;
    else if(rules=='*') return number*coeficient;
    else if(rules=='/') return number/coeficient;
}

void arr1rul(){
    a_aksen.push_back(arr1[0]);
    cout << a_aksen[0] << " ";
    for(x=1; x<arr1.size();x++){
        a_aksen.push_back(affectedByRules(arr1[x-1]));
        cout << a_aksen[x] << " ";
    }
    cout << endl;
}

void oneD(){
    cout << "size?" << endl;
    cin >> i;la = i;
    while(la--){
        cin >> d; arr1.push_back(d);
    }
    arr1rul();
    res.push_back(arr1[0]);
    for(x=1;x<arr1.size(); x++){
        res.push_back(  a_aksen[x] -  arr1[x] );
    }    
    for(x=0;x<res.size(); x++){
        cout << res[x] << " ";
    }
    cout << endl;
}

void oneD_decode(){
    cout << "apa sequencenya?" << endl;
    int dd;char cc;
    while( scanf("%d%c", &dd, &cc)){
        arr1.push_back(dd);
        if(cc == '\n') break;
    }
    
    res.push_back(arr1[0]);

    for(x=1;x<arr1.size(); x++){

        res.push_back(  affectedByRules( res[x-1] -  arr1[x]) );
    }    
    cout << "Hasil => " ;
    for(x=0;x<res.size(); x++){
        cout << res[x] << " ";
    }
    cout << endl;
}

void updateProbabilities(int updateValue){
    for(int z=0;z<probs.size();z++){
        if(updateValue == probs[z].first){
            probs[z].second += 1;
            return;
        }
    }
    // nothing found, no return

    probs.push_back( make_pair( updateValue, 1 ) );
}

void twoD(){
    cout << "size?" << endl;
    cin >> i >> j;
    totSize = i*j;
    y = i;
    while(y--){
        x = j;
        vector<int> temp;
        while(x--){
            cin >> d;
            temp.push_back(d);
        }
        arr2.push_back(temp);
    }

    // process
    for(int a=0; a < arr2.size(); a++){
        vector<int> temp;
        temp.push_back(arr2[a][0]);
        for(int b=1; b<arr2[a].size(); b++ ){

            //ubah rumus disini
            //default : a[i,j] -= a[i,j-1]

            int hasilRumus =arr2[a][b]-arr2[a][b-1]; 

            temp.push_back( hasilRumus );
            updateProbabilities(hasilRumus);
        }
        res2.push_back(temp);
    }
    cout << "result" << endl;
    for(int a=0; a < arr2.size(); a++){
        for(int b=0; b<arr2[a].size(); b++ ){
            cout << res2[a][b] << ' ';
        }
        cout << endl;
    }
    // printing probabilities
    cout << "Entry\tOccurrs\tProbability" << endl;
    for(int a=0;a<probs.size();a++){
        cout << probs[a].first << "\t" << probs[a].second << " \t" << probs[a].second << "/" <<totSize << endl;
    }
}

void twoD_decode(){
    cout << "size?" << endl;
    cin >> i >> j;
    totSize = i*j;
    y = i;
    while(y--){
        x = j;
        vector<int> temp;
        while(x--){
            cin >> d;
            temp.push_back(d);
        }
        arr2.push_back(temp);
    }

    // process
    for(int a=0; a < arr2.size(); a++){
        vector<int> temp;
        temp.push_back(arr2[a][0]);
        for(int b=1; b<arr2[a].size(); b++ ){
            temp.push_back( temp[b-1] + arr2[a][b] );
        }
        res2.push_back(temp);
    }
    cout << "result" << endl;
    for(int a=0; a < arr2.size(); a++){
        for(int b=0; b<arr2[a].size(); b++ ){
            cout << res2[a][b] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int tc;
    cout << "2 dimensi atau 1 dimensi(2/1)?"<< endl;
    cin >> tc;
    if(tc!=2){
        cout << "rules?" << endl;
        cin >> rules;
        cin >> coeficient;
    }
    cout << "encode/decode(e/d)?"<< endl;
    char l;cin >> l;
    if(l=='e'){
        if(tc==1) oneD();
        else twoD();
    }
    else{
        if(tc==1) oneD_decode();
        else twoD_decode();
    }

	
}

