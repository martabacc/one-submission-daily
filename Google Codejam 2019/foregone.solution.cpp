// Example program
#include<string>
#include<stdint.h>
#include<iostream>
#include<array>
#include<sstream>
#include<vector>
using namespace std;

string arToStr(int int_array[], int size_of_array) {
  ostringstream oss("");
  for (int temp = 0; temp < size_of_array; temp++)
    oss << int_array[temp];
  return oss.str();
}

int main()
{
    int tc;
    cin >> tc;
    for(int y=0;y<tc;y++) {
        string num;
        cin >> num;
        int len = num.length();
        int arr1[len] = {0};
        int arr2[len] = {0};
        for(int x=0;x<len;x++) {
            arr1[x] = num[x] - '0';
        }
        
        for(int x=0;x<len;x++) {
            if(arr1[x] == 4) {
                // increment the other fucking one
                arr2[x]++;
                arr1[x]--;
            }
        }
       
        string num1 =  arToStr(arr1, len); 
        string num2 =  arToStr(arr2, len);
        cout << "Case #" << y+1 << " " << num << ": "<< stoi(num1) << " " << stoi(num2) << endl;
        
    }
    return 0;
}