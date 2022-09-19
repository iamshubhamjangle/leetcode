/*
295_[KickStart]_Sort_the_Fabrics.cpp

A fabric is represented by three properties:

Color (CC), a string consisting of lowercase letters of the English alphabet, representing the color of the fabric.
Durability (DD), an integer representing the durability of the fabric.
Unique identifier (UU), an integer representing the ID of the fabric.
Ada and Charles work at the Kick Start fabric factory. Each day they receive NN fabrics, and one of them has to sort it. They sort it using the following criteria:

Ada sorts in lexicographically increasing order by color (CC).
Charles sorts in ascending order by durability (DD).
They break ties by sorting in ascending order by the unique identifier (UU).
Given NN fabrics, count the number of fabrics which end up in the same position regardless of whether Ada or Charles sort the

Round F 2022 - Kick Start 2022
*/

#include <bits/stdc++.h>
using namespace std;

bool sorti(pair<string,pair<int,int>> &x, pair<string,pair<int,int>>&y) {
    if(x.second.first != y.second.first)
        return (x.second.first < y.second.first);
    else
        return (x.second.second < y.second.second);
}

bool sortu(pair<string,pair<int,int>> &x, pair<string,pair<int,int>>&y) {
    if(x.first != y.first)
        return (x.first < y.first);
    else
        return (x.second.second < y.second.second);
}

int main() {

    int t;
    cin>>t;
    int te=t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        vector<pair<string,pair<int,int>>>v;
        vector<pair<string,pair<int,int>>>s;

        for(int i=0;i<n;i++)
        {
             string s;
             cin>>s;
             int x,y;
             cin>>x>>y;
             v.push_back({s,{x,y}});
        }

        s=v;

        sort(v.begin(),v.end(),sortu);
        sort(s.begin(),s.end(),sorti);

        for(int i=0;i<n;i++)
        {
            if(s[i]==v[i])
            ans++;
        }
        cout<<"Case #"<<te-t<<": "<<ans<<endl;
    }

    return 0;
}