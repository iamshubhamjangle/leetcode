/*
	Common elements between 3 array:

	Method 1: Using Hash Map using extra space of O (n1 + n2 + n3) and TC: O (n1 + n2 + n3)
	Method 2: Using Vector only and constant extra space and O (n1 + n2 + n3) TC: O (n1 + n2 + n3)

	Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
	Note: can you take care of the duplicates without using any additional Data Structure?

	Example 1:

	Input:
	n1 = 6; A = {1, 5, 10, 20, 40, 80}
	n2 = 5; B = {6, 7, 20, 80, 100}
	n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
	Output: 20 80
*/
#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    // Method 1: Using Hash Map using extra space of O (n1 + n2 + n3) and TC: O (n1 + n2 + n3)
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        unordered_map<int,int>m1,m2,m3;
        vector<int> v;
        for(int i=0;i<n1;i++) m1[A[i]]++;
        for(int i=0;i<n2;i++) m2[B[i]]++;
        for(int i=0;i<n3;i++) m3[C[i]]++;
       
        for(int i=0;i<n1;i++){
            if(m1[A[i]]>0 && m2[A[i]]>0 && m3[A[i]]>0 ) {
                v.push_back(A[i]);
                m1[A[i]]=0; //To make sure we dont consider duplicated from m1
            }
        }
        return v;
    }

	// Method 2: Most Optimal Approach using constant extra space and O (n1 + n2 + n3) Time Complexity
    vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
    {
        int i=0,j=0,k=0;
        vector<int> v;
        while(i<n1 and j<n2 and k<n3){
            if(a[i]==b[j] and b[j]==c[k]) 
            {
                v.push_back(a[i]);
                i++;j++;k++;
            }
            else if(a[i]<b[j]) i++;
            else if(b[j]<c[k]) j++;
            else k++;
            int xx = a[i-1];
            while(a[i]==xx) i++;
            int yy = b[j-1];
            while(b[j]==yy) j++;
            int zz = c[k-1];
            while(c[k]==zz) k++;
        }
        if(v.size()==0) return {-1};
        return v;
	}

};

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}