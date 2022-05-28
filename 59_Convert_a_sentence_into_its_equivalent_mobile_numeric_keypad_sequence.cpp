/*
Convert_a_sentence_into_its_equivalent_mobile_numeric_keypad_sequence.cpp

Given a sentence in the form of a string in uppercase, 
convert it into its equivalent mobile numeric keypad sequence.

Input  : S = "GFG"
Output : 43334
Explanation: For 'G' press '4' one time.
For 'F' press '3' three times.

https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1#
	- Method 1: Using unordered_map .TC: O(N). SC: O(26)
	- Method 2: Using string array .TC: O(N). SC: O(26)
	- Method 3: use loop to create map. TC: O(N). SC: O(26)

*/

#include <bits/stdc++.h>
using namespace std;
// Method 1: Using unordered_map .TC: O(N). SC: O(26)
// string printSequence(string S) {
// 	unordered_map<char, int> um;

// 	um['A'] = 2;
// 	um['B'] = 22;
// 	um['C'] = 222;
// 	um['D'] = 3;
// 	um['E'] = 33;
// 	um['F'] = 333;
// 	um['G'] = 4;
// 	um['H'] = 44;
// 	um['I'] = 444;
// 	um['J'] = 5;
// 	um['K'] = 55;
// 	um['L'] = 555;
// 	um['M'] = 6;
// 	um['N'] = 66;
// 	um['O'] = 666;
// 	um['P'] = 7;
// 	um['Q'] = 77;
// 	um['R'] = 777;
// 	um['S'] = 7777;
// 	um['T'] = 8;
// 	um['U'] = 88;
// 	um['V'] = 888;
// 	um['W'] = 9;
// 	um['X'] = 99;
// 	um['Y'] = 999;
// 	um['Z'] = 9999;
// 	um[' '] = 0;

// 	string ans;

// 	for(int i=0; i<S.size(); i++) {
// 		 ans += to_string(um[S[i]]);
// 	}

// 	return ans;
// }

// Method 2: Using string array. TC: O(N). SC: O(26)
// string printSequence(string S){
//    string hash[26] = {"2","22","222","3","33","333","4","44","444","5","55",
//    "555","6","66","666","7","77","777","7777","8","88","888","9","99","999",
//    "9999"};
   
//    string ans{};
//    for(int i = 0; i < S.length(); i++){
//        if(S[i] == ' ') ans += "0";
//        else ans += hash[S[i]-65];
//    }

//    return (ans);
// }

// Method 3: use loop to create map. TC: O(N). SC: O(26)
string printSequence(string str) {
    unordered_map<char,string> mp;
    char l='A';
    mp[' ']="0";
    for(int i=2;i<10;i++){
        string s=to_string(i);
        for(int j=0;j<3;j++){
            mp[l++]=s;
            s+=to_string(i);
        }
        if(l=='S') mp[l++]="7777";
        if(l=='Z') mp[l]="9999";
    }
    string ans="";
    for(int i=0;i<str.size();i++){
        ans+=mp[str[i]];
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}