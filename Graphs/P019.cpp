#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

long long bruteForce(const unordered_set<string> &dict, const string &start, const string &target)
{
    if (!dict.count(target))
        return 0;
    queue<pair<string, int>> q;
    q.push({start, 1});
    unordered_set<string> vis;
    vis.insert(start);
    long long minlen = 0, count = 0;
    while (!q.empty())
    {
        int sz = (int)q.size();
        unordered_set<string> local;
        while (sz--)
        {
            auto cur = q.front();
            q.pop();
            const string &w = cur.first;
            int d = cur.second;
            if (!minlen && w == target)
            {
                minlen = d;
                count++;
                continue;
            }
            if (minlen && d > minlen)
                continue;
            for (int i = 0; i < (int)w.size(); ++i)
            {
                string temp = w;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    temp[i] = c;
                    if (dict.count(temp) && !vis.count(temp))
                    {
                        q.push({temp, d + 1});
                        local.insert(temp);
                    }
                }
            }
        }
        for (const auto &s : local)
            vis.insert(s);
    }
    return count;
}

long long optimal(const unordered_set<string> &dict, const string &start, const string &target)
{
    if (!dict.count(target))
        return 0;
    unordered_map<string, int> dist;
    unordered_map<string, vector<string>> parents;
    queue<string> q;
    q.push(start);
    dist[start] = 1;

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        if (cur == target)
            break;
        for (int i = 0; i < (int)cur.size(); ++i)
        {
            string tmp = cur;
            for (char c = 'a'; c <= 'z'; ++c)
            {
                tmp[i] = c;
                if (dict.count(tmp))
                {
                    if (!dist.count(tmp))
                    {
                        dist[tmp] = dist[cur] + 1;
                        q.push(tmp);
                        parents[tmp].push_back(cur);
                    }
                    else if (dist[tmp] == dist[cur] + 1)
                    {
                        parents[tmp].push_back(cur);
                    }
                }
            }
        }
    }

    if (!dist.count(target))
        return 0;

    // recursive count of sequences using parents map (use std::function declared first)
    function<long long(const string &)> dfs;
    dfs = [&](const string &s) -> long long
    {
        if (s == start)
            return 1;
        long long res = 0;
        auto it = parents.find(s);
        if (it == parents.end())
            return 0;
        for (const string &p : it->second)
            res += dfs(p);
        return res;
    };

    return dfs(target);
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    unordered_set<string> dict;
    string w;
    for (int i = 0; i < n; ++i)
    {
        cin >> w;
        dict.insert(w);
    }
    string start, target;
    cin >> start >> target;
    cout << bruteForce(dict, start, target) << "\n";
    cout << optimal(dict, start, target) << "\n";
    return 0;
}
