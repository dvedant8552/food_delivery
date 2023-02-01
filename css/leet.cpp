#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> adj[n];
        map<pair<int,int>,int>cost;
        vector<int>dist(n,INT_MAX);

        for(vector<int>x:flights)
        {
            adj[x[0]].push_back(x[1]);
            cost[{x[0],x[1]}]=x[2];
        }

        int lev=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        q.push({-1,-1});

        while(!q.empty())
        {
            int a=q.front().first;
            int b=q.front().second;

            if(a==-1 && b==-1){
                q.push(q.front());
                q.pop();
                lev++;
                if(lev==k) break;
            }

            
        }
    
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

    }
};

class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> adj[n];
        map<pair<int,int>,int>cost;
        vector<int>dist(n,INT_MAX);

        for(vector<int>x:flights)
        {
            adj[x[0]].push_back(x[1]);
            cost[{x[0],x[1]}]=x[2];
        }

        int lev=0;
        queue<pair<int,int>>q;
        q.push({src,0});
       

        while(!q.empty() && lev<=k)
        {
            int sz=q.size();
            
            while(sz--)
            {
                 int a=q.front().first;
                 int b=q.front().second;
                
                q.pop();
                
                for(int x:adj[a])
                {
                    if(b+cost[{a,x}]>=dist[x]) continue;
                    dist[x]=min(b+cost[{a,x}],dist[x]);
                    q.push({x,dist[x]});
                }

            }
           
            lev++;
        }
    
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

    }
};










             
int main()
{
   
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);            
 
return 0;
}