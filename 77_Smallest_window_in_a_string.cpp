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
       if(mi==INT_MAX)
       {
           return "-1";
       }
       else
       {
           for(int i=start;i<=end;i++)
           {
               ans=ans+s[i];
           }
           return ans;
       }
       
       
       
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