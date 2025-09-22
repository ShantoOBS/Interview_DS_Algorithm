/*
   Problem link : https://www.interviewbit.com/problems/delete-edge/
   Company : will be soon 
*/

//T.C: O(V+E)
//S.C: O(V+E)

const long long MOD = 1000000007LL;

void dfs(int u, int p, const vector<vector<int>>& g, vector<long long>& sub, const vector<int>& A) {
    sub[u] = A[u-1]; // nodes are 1-based; A is 0-based
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u, g, sub, A);
        sub[u] += sub[v];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n = (int)A.size();
    vector<vector<int>> g(n+1);
    for (auto &e : B) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<long long> sub(n+1, 0);
    dfs(1, 0, g, sub, A);

    long long total = sub[1];
    long long max_raw = 0;
    for (int i = 2; i <= n; ++i) {
        long long p1 = sub[i];
        long long p2 = total - p1;
        long long raw = p1 * p2;       // compare raw product
        if (raw > max_raw) max_raw = raw;
    }

    return (int)(max_raw % MOD);
}
