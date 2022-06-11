/*
Smallest_window_in_a_string_containing_all_the_characters_of_another_string

Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Input:
S = "timetopractice"
P = "toc"
Output: toprac

Input:
S = "zoomlazapzo"
P = "oza"
Output: apzo

<<<<<<< HEAD
https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#
    // Method 1: Sliding window technique. TC: O(N), SC: O(N)


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    // Method 1: Sliding window technique. TC: O(N), SC: O(N)
    string smallestWindow (string s, string t) {
        int m[256] = { 0 };
     
        // Answer
        int ans = INT_MAX; // length of ans
        int start = 0; // starting index of ans
        int count = 0;
       
        // creating map
        for (int i = 0; i < t.length(); i++) {
            if (m[t[i]] == 0)
                count++;
            m[t[i]]++;
        }
     
        // References of Window
        int i = 0;
        int j = 0;
     
        // Traversing the window
        while (j < s.length()) {
            // Calculations
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
     
            // Condition matching
            if (count == 0) {
                while (count == 0) {
                    // Sorting ans
                    if (ans > j - i + 1) {
                        ans = min(ans, j - i + 1);
                        start = i;
                    }
                    // Sliding I
                    // Calculation for removing I
     
                    m[s[i]]++;
                    if (m[s[i]] > 0)
                        count++;
     
                    i++;
                }
            }
            j++;
        }
     
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "-1";
    }
};


// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends


/*
=======
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
>>>>>>> 8efd1f843c7e7e5da77a292dd0f093ab72bf9f90
    string smallestWindow (string s, string p)
   {
       // Your code here
       unordered_map<char,int>mp;
       
       for(int i=0;i<p.size();i++)
       {
           mp[p[i]]++;
       }
       
       int mi=INT_MAX;
       
       int i=0,j=0;
       // storing the all uniques words present in p
       int cnt=mp.size();
       
       int start,end;
       while(j<s.size())
       {
           mp[s[j]]--;
           
           // if we found all character present in p of type 1 decrease the cnt by 1
           if(mp[s[j]]==0)
           {
               cnt--;
           }
           
           // if all char found 
           if(cnt==0)
           {
               // start deleting from start till we can(means unique words 0)
               while(cnt==0)
               {
                   // minimization of window size
                   if(j-i+1<mi)
                   {
                       mi=j-i+1;
                       start=i;
                       end=j;
                   }
                   
                   mp[s[i]]++;
                   
                   if(mp[s[i]]==1)
                   {
                       cnt++;
                   }
                   i++;
               }
           }
           
           j++;
       }
       
       string ans="";
<<<<<<< HEAD
       if(mi==INT_MAX) {
           return "-1";
       }
       else {
=======
       if(mi==INT_MAX)
       {
           return "-1";
       }
       else
       {
>>>>>>> 8efd1f843c7e7e5da77a292dd0f093ab72bf9f90
           for(int i=start;i<=end;i++)
           {
               ans=ans+s[i];
           }
           return ans;
       }
<<<<<<< HEAD
   }
};
*/
=======
       
       
       
   }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
>>>>>>> 8efd1f843c7e7e5da77a292dd0f093ab72bf9f90
