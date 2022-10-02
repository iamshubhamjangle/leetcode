/*
Longest_Uploaded_Prefix.cpp
*/

// class LUPrefix {
// public:
//     vector<int> prefix;
//     int size;
    
//     LUPrefix(int n) {
//         size = n;
//         prefix.resize(size+1);
//     }
    
//     void upload(int video) {
//         prefix[video] = 1;
//     }
    
//     int longest() {
//         int cnt = 0;
//         for(int i=1; i<=size; i++) {
//             if(prefix[i] == 1) cnt++;
//             else break;
//         }
//         return cnt;
//     }
// };

class LUPrefix { 
public: 
    vector<bool>vis; 
    int maxxx=1;
    
    LUPrefix(int n) { 
        vector<bool>a(n+2,false); 
        vis=a; 
        vis[0]=true; 
        maxxx=1; 
    } 
     
    void upload(int v) { 
        vis[v]=true; 
        while(vis[maxxx])maxxx++;      
    } 
     
    int longest() { 
        return maxxx-1; 
    } 
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */