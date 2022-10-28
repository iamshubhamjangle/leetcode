/*
Image_Overlap.cpp

https://leetcode.com/problems/image-overlap/
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int, int>, int>m;
        int siz = (int)img1.size();
        int ans =0 ;
        for(int i=0; i<siz ; ++i){
            for(int j=0; j<siz ; ++j){
                for(int k =0 ; k<siz ; ++k){
                    for(int l=0 ; l<siz ; ++l){
                        if(img1[i][j] & img2[k][l]) ans = max(ans, ++m[make_pair(i-k, j-l)] ) ;
                    }
                }
                
            }
        }
        return ans;
    }
};