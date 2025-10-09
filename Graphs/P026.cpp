#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> bruteForce(int V, vector<vector<int>>& adj){
    // nodes not part of any cycle via DFS detection per node (expensive)
    vector<int> safe;
    for(int i=0;i<V;i++){
        vector<int> vis(V,0), rec(V,0);
        function<int(int)> dfs=[&](int u)->int{
            vis[u]=1; rec[u]=1;
            for(int v: adj[u]){
                if(!vis[v]){ if(dfs(v)) return 1; }
                else if(rec[v]) return 1;
            }
            rec[u]=0; return 0;
        };
        if(!dfs(i)) safe.push_back(i);
    }
    sort(safe.begin(), safe.end());
    return safe;
}

vector<int> optimal(int V, vector<vector<int>>& adj){
    vector<vector<int>> rev(V);
    vector<int> outdeg(V,0);
    for(int u=0;u<V;u++){ for(int v:adj[u]){ rev[v].push_back(u); outdeg[u]++; } }
    queue<int> q; vector<int> vis(V,0), res;
    for(int i=0;i<V;i++) if(outdeg[i]==0) q.push(i);
    while(!q.empty()){ int u=q.front(); q.pop(); vis[u]=1; res.push_back(u);
        for(int v: rev[u]) if(--outdeg[v]==0) q.push(v);
    }
    sort(res.begin(), res.end()); return res;
}

int main(){
    int V,E; if(!(cin>>V>>E)) return 0;
    vector<vector<int>> adj(V); for(int i=0;i<E;i++){ int u,v; cin>>u>>v; adj[u].push_back(v); }
    auto b=bruteForce(V,adj); for(size_t i=0;i<b.size();i++) cout<<b[i]<<(i+1==b.size()?"\n":" ");
    auto o=optimal(V,adj); for(size_t i=0;i<o.size();i++) cout<<o[i]<<(i+1==o.size()?"\n":" ");
    return 0;
}
