#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

int bruteForce(unordered_set<string> dict, string start, string target){
    if(!dict.count(target)) return 0;
    // BFS naive (same as optimal but considered brute due to set ops)
    queue<pair<string,int>> q; q.push({start,1}); unordered_set<string> vis; vis.insert(start);
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        string w=cur.first; int d=cur.second;
        if(w==target) return d;
        for(int i=0;i<(int)w.size();i++){
            string temp=w;
            for(char c='a'; c<='z'; c++){
                temp[i]=c;
                if(dict.count(temp) && !vis.count(temp)){ vis.insert(temp); q.push({temp,d+1}); }
            }
        }
    }
    return 0;
}

int optimal(unordered_set<string> dict, string start, string target){
    if(!dict.count(target)) return 0;
    // Bidirectional BFS
    unordered_set<string> a,b,vis;
    a.insert(start); b.insert(target);
    int level=1;
    while(!a.empty() && !b.empty()){
        if(a.size()>b.size()) swap(a,b);
        unordered_set<string> next;
        for(auto &w: a){
            string cur=w;
            for(int i=0;i<(int)cur.size();i++){
                string temp=cur;
                for(char c='a'; c<='z'; c++){
                    temp[i]=c;
                    if(b.count(temp)) return level+1;
                    if(dict.count(temp) && !vis.count(temp)){ next.insert(temp); vis.insert(temp); }
                }
            }
        }
        a=move(next); level++;
    }
    return 0;
}

int main(){
    int n; if(!(cin>>n)) return 0;
    unordered_set<string> dict; string w;
    for(int i=0;i<n;i++){ cin>>w; dict.insert(w); }
    string start,target; cin>>start>>target;
    cout<<bruteForce(dict,start,target)<<"\n";
    cout<<optimal(dict,start,target)<<"\n";
    return 0;
}
