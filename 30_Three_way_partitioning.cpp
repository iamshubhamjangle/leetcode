/* 
Three_way_partitioning

Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Input: n = 5, A[] = {1, 2, 3, 3, 4}, [a, b] = [1, 2]
Output: 1

Input: n = 3, A[] = {1, 2, 3}, [a, b] = [1, 3]
Output: 1

https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#
	- Method 1: sort the array O(N log N), space: O(1)
    - Method 2:  Using two pointer approach

*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{   
public:
	// Method 1: sort the array O(N log N), space: O(1)
    // void threeWayPartition(vector<int>& array,int a, int b) {
    // 	sort(array.begin(), array.end());
    // }

    // Method 2:  Using two pointer approach
   void threeWayPartition(vector<int>& arr,int a, int b) {
	   int s=0,m=0,e=arr.size()-1;
	   while(m<=e) {
	       if(arr[m]<a) swap(arr[s++],arr[m++]);
	       else if(arr[m]>=a && arr[m]<=b) m++;
	       else swap(arr[m],arr[e--]);
	   }
   }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        
        vector<int> array(N);
        unordered_map<int,int> ump;
        
        for(int i=0;i<N;i++){
            cin>>array[i];
            ump[array[i]]++;
        }
        
        int a,b;
        cin>>a>>b;
        
        vector<int> original = array;

        int k1=0,k2=0,k3=0;
        int kk1=0;int kk2=0;int kk3=0;
        
        for(int i=0; i<N; i++)
        {
            if(original[i]>b)
                k3++;
            else if(original[i]<=b and original[i]>=a)
                k2++;
            else if(original[i]<b)
                k1++;
        }
        
        Solution ob;
        ob.threeWayPartition(array,a,b);
      
        for(int i=0;i<k1;i++)
        {
            if(array[i]<b)
            kk1++;
        }
        
        for(int i=k1;i<k1+k2;i++)
        {
            if(array[i]<=b and array[i]>=a)
            kk2++;
            
        }
        
        for(int i=k1+k2;i<k1+k2+k3;i++)
        {
            if(array[i]>b)
            kk3++;
        }
        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3)
            ok = 1;
        
        for(int i=0;i<array.size();i++)
            ump[array[i]]--;
        
        for(int i=0;i<array.size();i++)
            if(ump[array[i]]!=0)
                ok=0;
        
        if(ok)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    }
    
    return 0;
}