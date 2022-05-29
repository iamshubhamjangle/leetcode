/*
Count_occurences_of_a_given_word_in_a_2-d_array.cpp

Find the number of occurrences of a given search word in  a 2d-Array 
of characters where the word can go up, down, left, right and around 90 degree bends.

Input: 
R = 4, C = 5
mat = {{S,N,B,S,N},
       {B,A,K,E,A},
       {B,K,B,B,K},
       {S,E,B,S,E}}
target = SNAKES
Output: 3

Input:
R = 3, C = 3 
mat = {{c,a,t},
       {a,t,c},
       {c,t,a}}
target = cat
Output: 5

https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1/
    - Method 1: loop 2d array and search in all direction. TC: O(N*N). SC: O(1)
    - ref: https://www.youtube.com/watch?v=ZYeVllg0D7E
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(int i, int j, int idx, string s, int size, vector<vector<char>> mat, int m, int n) {
        int found = 0;

        if(i>=0 && j>=0 && i<m && j<n && s[idx] == mat[i][j]) {
            char temp = s[idx];     // saved to reinsert it at end
            mat[i][j] = 0;          // making current zero to avoid considering same element twice

            idx++;
            if(idx == size) {       // have we found all chars
                found = 1;
            } else {                // search all direction
                found += solve(i+1, j, idx, s, size, mat, m, n);
                found += solve(i-1, j, idx, s, size, mat, m, n);
                found += solve(i, j+1, idx, s, size, mat, m, n);
                found += solve(i, j-1, idx, s, size, mat, m, n);
            }

            mat[i][j] = temp;       // backtrack
        }
        return found;
    }

    int findOccurrence(vector<vector<char>> &mat, string target){
        int size = target.size();   // input word size
        int m = mat.size();         // rows
        int n = mat[0].size();      // columns
        int ans = 0;                // To count no of found words
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans += solve(i, j, 0, target, size, mat, m, n);
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}