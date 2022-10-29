class Solution {
public:
    int destroyTargets(vector<int>& a, int d) {
            sort(a.begin(),a.end());
         map<int,int>m;
            for(int i=0;i<a.size();i++)
            {
                    int x = a[i]/d;
                    x = a[i]-xd;
                    if(x==0) x=d;
                    m[x]++;

            }
            int mx=-1;
            for(auto i: m)
            {
                    if(i.second>mx)
                            mx = i.second;
            }
           set<int>ans;
            for(auto i : m)
            {
                    if(i.second==mx)
                            ans.insert(i.first);
            }
            int mn = INT_MAX;
             for(int i=0;i<a.size();i++)
            {
                    int x = a[i]/d;
                    x = a[i]-xd;
                    if(x==0) x=d;

                    if(ans.find(x)!=ans.end())
                    {
                            if(mn>a[i])
                                    mn =a[i];
                    }

            }

            return(mn);
    }
};