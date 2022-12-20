/*
Keys_and_Rooms.cpp

https://leetcode.com/problems/keys-and-rooms/description/
*/

class Solution {
public:
	// TC: O(2N) SC: O(2N)
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<int> visited(n+1, 0);

        // push first element to queue
        q.push(0);

        // while(!q.empty()) visit each room
        while(!q.empty()) {
            int front = q.front(); q.pop();

            // visit the front room and read all keys, push to queue
            // mark the room as visited
            for(auto currRoomKey: rooms[front]) {
                if(!visited[currRoomKey])
                    q.push(currRoomKey);
            };
            visited[front] = 1;
        }

        // loop through visited rooms, if any is unvisited return false;
        for(int i=0; i<n; i++) {
            // cout << "Room " << i << " " << visited[i] << endl;
            if(!visited[i]) return false;
        }

        // at end return true if all rooms are visited.
        return true;
    }


    // // DFS
    // class Solution {
	//     void dfs(vector<vector<int>>& rooms, unordered_set<int> & keys, unordered_set<int> & visited, int curr) {
	//         visited.insert(curr);
	//         for (int k : rooms[curr]) keys.insert(k);
	//         for (int k : keys) if (visited.find(k) == visited.end()) dfs(rooms, keys, visited, k);
	//     }
	    
	// public:
	//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
	//         unordered_set<int> keys;
	//         unordered_set<int> visited;
	//         dfs(rooms, keys, visited, 0);
	//         return visited.size() == rooms.size();
	//     }
	// };
};