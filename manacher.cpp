// Manacher algorithm 

#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1

int P[SIZE * 2];

// transform string interspersing # charachters
string convertToNewString(const string &s){
    string newString = "@";
    for (int i=0; i < s.size(); i++){
        newString += "#" + s.substr(i, 1);
    }
    newString += "$";
    return newString;
}

string longestPalindromeSubstring(const string &s){
    string Q = convertToNewString(s);
    int c = 0, r = 0; // current center, right limit

    for(int i = 1; i < Q.size() - 1; i++){
        // find the corresponding letter in the palindrome substring
        int iMirror = c - (i - c);
        if(r > 1){
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while(Q[i + 1 + P[i]] == Q[i - 1 - P[i]]) {
            P[i]++;
        }

        // update c, r in case if the palindrome centered
        // at i expands past r
        if(i + P[i] > r) {
            c = i; // next center = i
            r = i + P[i];
        }
    }

    // find the longest palindrome length in p
    int maxPalindrome = 0;
    int centerIndex = 0;

    for(int i = 1; i < Q.size() - 1; i++) {
        if(P[i] > maxPalindrome){
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr((centerIndex -1 - maxPalindrome) / 2, maxPalindrome);
}



int main() {
string s = "neveroddoreven\n";
cout << longestPalindromeSubstring(s);
}

