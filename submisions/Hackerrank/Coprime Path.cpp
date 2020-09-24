
/*
 * Hackerrank
 * Coprime Paths(80)
 * https://www.hackerrank.com/challenges/coprime-paths/problem
 *
 * Preparation for August's Contest
 */

#include<iostream>
#include<vector>

#define ll long long
using namespace std;
int n, q;
ll temp, edgeFrom, edgeTo, qFrom, qTo;
vector<pair<ll,ll> > queries;

typedef struct Node{
    ll index;
    vector<ll> edges;
} ;

vector<Node *> Graph;

int main() {
    cin >> n >> q;
    for (int x = 0; x < n; x++) {
        cin >> temp;
        auto *tempNode = new Node;
        tempNode->index = temp;
        Graph.push_back(tempNode);
    }

    for (int paths = 0; paths < n - 1; paths++) {
        cin >> edgeFrom >> edgeTo;
        Graph[edgeFrom]->edges.push_back(edgeTo);
        Graph[edgeTo]->edges.push_back(edgeFrom);
    }

    for(int x=0;x<q;x++){
        cin >> qFrom >> qTo;
        queries.emplace_back(make_pair(qFrom, qTo));
    }

    for (int x=0;x<Graph.size();x++) {
        cout << "AAA" << endl;
        Node *currentNode = Graph[x];
        cout << currentNode->index << " ";
        for (int y = 0; y < currentNode->edges.size(); y++) cout << currentNode->edges[y] << " ";
        cout << endl;
    }
    cout << "AAA" << endl;

    return 0;


}