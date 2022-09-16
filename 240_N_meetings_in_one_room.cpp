/*
N_meetings_in_one_room.cpp

Input : N = 6, start[] = {1,3,0,5,8,5}, end[] =  {2,4,6,7,9,9}
Output: 4

Input : N = 3, start[] = {10, 12, 20}, end[] = {20, 25, 30}
Output: 1

https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

// class Solution{
// public:
//     static bool compare(pair<int,int>a, pair<int,int>b){
//         if(a.second==b.second) return a.first<b.first;
//         return a.second<b.second;
//     }
    
//     int maxMeetings(int start[], int end[], int n) {
//         vector<pair<int,int>>vect(n);
//         for(int i=0;i<n;i++){
//             vect[i]={start[i],end[i]};
//         }
//         sort(vect.begin(),vect.end(),compare);

//         int count=0;
//         int endtime=vect[0].second;
//         count=1;

//         for(int i=1;i<n;i++) {
//             if(vect[i].first > endtime){
//                 endtime=vect[i].second;
//                count++;
//             }
//         }

//         return count;
//    }
// };


//______________________________________________________
// 1. Greedy. TC: O(NlogN) SC: O(N)

struct meeting {
    int start;
    int end;
    int pos;
};
    
bool comparator(struct meeting m1, meeting m2) {
    if(m1.end < m2.end) return true;        // no swap
    else if(m1.end > m2.end) return false;  // swap
    else if(m1.pos < m2.pos) return true;   // no swap
    return false;                           // swap
}

class Solution {
public:
    int maxMeetings(int s[], int e[], int n) {
        struct meeting meet[n];
        for(int i=0; i<n; i++) {
            meet[i].start = s[i];
            meet[i].end   = e[i];
            meet[i].pos   = i+1;
        }

        sort(meet, meet+n, comparator);

        int count = 1;
        int lastMeetEndedAt = meet[0].end;

        for(int i=1; i<n; i++) {
            if(meet[i].start > lastMeetEndedAt) {
                // we can have a new meet
                lastMeetEndedAt = meet[i].end;
                count++;
            }
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}