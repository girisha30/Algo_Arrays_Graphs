#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

string bruteForce(int N, int K, vector<string> &words)
{
    // naive: build edges same as optimal
    vector<vector<int>> adj(K);
    vector<int> indeg(K, 0);
    for (int i = 0; i < N - 1; i++)
    {
        string a = words[i], b = words[i + 1];
        int L = min(a.size(), b.size());
        for (int j = 0; j < L; j++)
            if (a[j] != b[j])
            {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                indeg[b[j] - 'a']++;
                break;
            }
    }
    // Kahn
    string res;
    queue<int> q;
    for (int i = 0; i < K; i++)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back('a' + u);
        for (int v : adj[u])
            if (--indeg[v] == 0)
                q.push(v);
    }
    return res;
}

string optimal(int N, int K, vector<string> &words)
{
    return bruteForce(N, K, words); // same here (problem small)
}

int main()
{
    int N, K;
    if (!(cin >> N >> K))
        return 0;
    vector<string> words(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];
    cout << bruteForce(N, K, words) << "\n";
    cout << optimal(N, K, words) << "\n";
    return 0;
}
