#include<bits/stdc++.h>
using namespace std;

int bitmask;
char* characters;
int characters_count;
char* running;
int running_count;

void permutations() {
    int i;
    if (running_count == characters_count) {
        printf("%s\n", running);
    } else {
        for (i=0; i<characters_count; i++) {
            if ( ((bitmask>>i)&1) == 0 ) {
                running[running_count] = characters[i];
                bitmask |= (1<<i);
                // cout << "Bitmask start: " << bitmask << endl;
                running_count = running_count + 1;
                permutations();
                bitmask ^= ( 1 << i);
                // cout << "Bitmask now: " << bitmask << endl;
                // getchar();
                running_count = running_count - 1;
            }
        }
    }
}


int main() {
    int i;
    int cases;

    characters = (char*)malloc(sizeof(char)*30);
    scanf("%s", characters);
    characters_count = strlen(characters);
    // cout << characters_count << endl;

    running = (char*)malloc(sizeof(char)*30);
    memset(running, 0, 30);
    running_count = 0;

    permutations();

    free(characters);
    free(running);
}
