// sanju.laitonjam@zycus.com


// "Student":{"Name":"John","Age":"15"},"Class":"10"
// 3
// Student.Name Student.Age Class

#include<bits/stdc++.h>
using namespace std;

vector<string> solve (string text, int Q, vector<string> queries) {
   // Write your code here
   unordered_map<string, string> um;

   for(auto i: text) {
    if(i == '"') {
        
    }
   }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    string text;
    cin >> text;
    int Q;
    cin >> Q;
    vector<string> queries(Q);
    for(int i_queries = 0; i_queries < Q; i_queries++)
    {
        cin >> queries[i_queries];
    }

    vector<string> out_;
    out_ = solve(text, Q, queries);
    for(int i_out_ = 0; i_out_ < out_.size(); i_out_++)
    {
        cout << out_[i_out_] << "\n";
    }
}