#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string isPalindrome(string str) {
    int length = str.size();

    cout << "str: " << str << endl;
    if(length == 1) return str;
    if(str[0] != str[length-1]) return "";
    if(length == 2) return str;

    string ok = isPalindrome(str.substr(1, length-2));
    return ok.size() == 0 ? "" : str;
}

string lowercaseAndRemoveWhitespace(const string& str) {
    string result;
    for (char c : str) {
        // Convert character to lowercase
        char lowercaseChar = tolower(c);
        // If the character is not whitespace, append it to the result string
        if (!isspace(lowercaseChar)) {
            result.push_back(lowercaseChar);
        }
    }
    return result;
}

int main() {
    string input = "A man a plan a canal Panama";
    int longest = -1;
    string ass = "";

    string togo = lowercaseAndRemoveWhitespace(input);
    cout << togo.size() << endl;

    for(int a = 1; a <= togo.size(); a++) {
        for(int b = 0; b < a; b++) {
            string result = isPalindrome(togo.substr(b, a));
            cout << b << " " << a << " " << result << " " << longest <<  endl;
            if (int(result.size()) > longest) {
                ass = result;
                longest = result.size();
            }
        }
    }

    cout << ass << endl;
    return 0;
}