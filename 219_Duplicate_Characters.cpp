/*
Duplicate_Characters.cpp

can contain upper and lower case characters.

Input:
2
5
APPLE
6
BANANA

Output:
P 2
A 3
N 2

https://www.codingninjas.com/codestudio/problems/duplicate-characters_3189116?leftPanelTab=0

*/

vector<pair<char,int>> duplicate_char(string s, int n){
   vector<pair<char,int>>vp;
   int arr[256]={0};

   for(int i=0;i<s.size();i++) {
       arr[s[i]]++;
   }

   for(int i=0;i<256;i++) {
       if(arr[i]>1) {
           vp.push_back({i,arr[i]});
       }
   }

   return vp;
}