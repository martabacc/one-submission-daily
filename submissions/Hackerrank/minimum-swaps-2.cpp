#include<bits/stdc++.h>
using namespace std;

// Function returns the minimum number of swaps
// required to sort the array
// This method is taken from below post
// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
int minSwapsToSort(int arr[], int n)
{
    // Create an array of pairs where first
    // element is array element and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    // Sort the array by array element values to
    // get right position of every element as second
    // element of pair.
    sort(arrPos, arrPos + n);

    // To keep track of visited elements. Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);

    // Initialize result
    int ans = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }

        // Update answer by adding current cycle.
        ans += (cycle_size - 1);
    }

    // Return result
    return ans;
}

// method returns minimum number of swap to make
// array B same as array A
int minSwapToMakeArraySame(int a[], int b[], int n)
{
    // map to store position of elements in array B
    // we basically store element to index mapping.
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[b[i]] = i;

    // now we're storing position of array A elements
    // in array B.
    for (int i = 0; i < n; i++)
        b[i] = mp[a[i]];

    /* We can uncomment this section to print modified
      b array */
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;

    // returing minimum swap for sorting in modified
    // array B as final answer
    return minSwapsToSort(b, n);
}

int main(){
  int n;
  cin >> n;
  int arr[n], sorted[n];
  for(int x=0;x<n;x++){
    cin >> arr[x];
    sorted[x] = arr[x];
  }
  sort(sorted, sorted + n);

  cout << minSwapToMakeArraySame(arr, sorted, n) << endl;
  return 0;
}
