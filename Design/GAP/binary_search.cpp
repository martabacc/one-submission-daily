#include <bits/stdc++.h>
using namespace std;
#define LIMIT 10000
#define loopThrough(limit) for(int x=0; x<limit ; x++)

int binary_search(int* array, int value, int low, int high) {
    int mid;

    if (high ==low&&array[(low+high)/2]!=value) {
        return -1;
    } else {
        mid = (low + high)/2;
        // cout << "LOW: " << low << " MID: " << mid << " HIGH: " << low << endl;
        if (array[mid] > value) {
            // cout << "Swap left " << endl;
            return binary_search(array, value, low, mid);
        } else if (array[mid] < value) {
            // cout << "Swap right "<< endl;
            return binary_search(array, value, mid+1, high);
        } else {
          return mid;
        }

    }
}

int main() {

    ofstream outputFile("binary_testcases/out.txt");
    ifstream inFile("binary_testcases/in.txt");
    int i, query, answer, qc;
    int array[LIMIT];
    string line;
    if (inFile.is_open()) {
        cout << "Start reading file" << endl;
        // Insert into BT
        loopThrough(LIMIT) {
          inFile >> array[x];
          // cout << array[x] << ' ';
        }
        // cout << endl;
        // Query time!
        // cout << "Number of query: ";
        // cin >> qc;
        loopThrough(LIMIT) {
          // cin >> query;
          inFile >> query;
          // cout << query;
          answer = binary_search(array, query, 0, LIMIT-1);
          outputFile << answer << endl;
          // cout << answer << endl;
        }
        cout << "Finish reading file, exiting..." << endl;
        inFile.close();
        outputFile.close();
    }

    return 0;

}
