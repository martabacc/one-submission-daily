#include <bits/stdc++.h>
#define MAX_SIZE 101
using namespace std;

int main() {

	int tc;

	cin >> tc;
	for(int t=0;t<tc;t++)
	{
	    int animalCount[MAX_SIZE] = {0};
        priority_queue<int> sizes;

	    int animals;
	    int size;
	    cin >> animals;

	    for(int x=0;x<animals;x++) {
	        cin >> size;
	        if(animalCount[size] == 0) {
	            sizes.push(-size);
	        }
	        animalCount[size]++;
	    }

	    //counting
	    int currentFood = 1;
	    int result = 0;
        while (!sizes.empty()) {
            int top = -sizes.top();

            result += (currentFood * animalCount[top]);

            currentFood++;
            sizes.pop();
        }

	    cout << "Case #"<< t+1 <<": " <<result << endl;
	}
    return 0;
}