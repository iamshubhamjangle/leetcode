#include <bits/stdc++.h>
using namespace std;

void printVectorString(vector<string> &vs) {
    cout << "vector<string> = [";
    for(auto s: vs) cout << s << ",";
    cout << "]" << endl;
}

vector<string> stringSplitBy(string s, char splitBy) {
    int n = s.size();
    vector<string> res;
    string word = "";

    for(int i=0; i<=n; i++) {
        if(s[i] == ' ' || i == n) {
            res.push_back(word);
            word = "";
        } else {
            word += s[i];
        }
    }

    return res;
}

int main(){
    string s = "dog cat cat dog";
    vector<string> ans = stringSplitBy(s, ' ');
    printVectorString(ans);


    // vector<string> ans;
    // string word = "";

    // for(int i=0; i<=s.size(); i++) {
    //     if(s[i] == ' ' || i == s.size()) {
    //         ans.push_back(word);
    //         word = "";
    //     } else {
    //         word += s[i];
    //     }
    // }
    
    // printVectorString(ans);
    return 0;
}