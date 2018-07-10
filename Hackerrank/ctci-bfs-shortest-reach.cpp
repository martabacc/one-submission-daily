#include<iostream>
#include<vector>
#include<queue>


#define LIMIT 1002
using namespace std;

int q, n, m, s, d1, d2;

struct Dot {
    vector<Dot *> edges;
    int distance;
} *graph[LIMIT];


void resetDot() {
    for (int x = 1; x <= n; x++) {
        graph[x]->edges.clear();
        graph[x]->distance = -1;
    }
}

void printDistance() {
    for (int x = 1; x <= n; x++) {
        if (x != s)
            cout << (graph[x]->distance > 0 ? graph[x]->distance * 6 : -1) << " ";
    }
    cout << endl;
}

int main() {
    for (int x = 1; x <= LIMIT; x++) {
        Dot *newDot = new Dot;
        graph[x] = newDot;
    }

    cin >> q;
    while (q--) {
        cin >> n >> m;
        resetDot();
        for (int x = 0; x < m; x++) {
            cin >> d1 >> d2;
            (graph[d1])->edges.push_back(graph[d2]);
            (graph[d2])->edges.push_back(graph[d1]);
        }
        cin >> s;
        queue<Dot *> bfs;
        bfs.push(graph[s]);
        graph[s]->distance = 0;

        while (!bfs.empty()) {
            Dot *now = bfs.front();
            bfs.pop();
            for (int x = 0; x < now->edges.size(); x++)
                if (now->edges[x]->distance == -1) {
                    bfs.push(now->edges[x]);
                    now->edges[x]->distance = now->distance + 1;
                }
        }

        printDistance();
    }

    return 0;
}