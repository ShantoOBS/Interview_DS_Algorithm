// Problem Link : https://codeforces.com/contest/1341/problem/D

#include <bits/stdc++.h>
using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);

#define int long long
#define all(v) v.begin(),v.end()
#define vl vector<int>
#define pb emplace_back
#define in(v) for(auto &k:v)cin>>k;

const int mx=2e3+123;

int dp[mx][mx];
string a[mx];

struct info{
    int i, c, ans;
    info(){};  // default constructor
    info(int i,int c,int ans):i(i),c(c),ans(ans){} // parameterized constructor
}dir[mx][mx];

string s[]={
    "1110111", "0010010", "1011101", "1011011", "0111010",
    "1101011", "1101111", "1010010", "1111111", "1111011"
};

int n,k;

int getValue(string s1, string s2){
    int cnt = 0;
    for(int i = 0; i < 7; i++){
        if(s1[i]=='0' && s2[i]=='1') return -1;
        if(s1[i]=='1' && s2[i]=='0') cnt++;
    }
    return cnt;
}

int fun(int i, int c){
    if(i == n) return c == k;
    if(dp[i][c] != -1) return dp[i][c];

    int res = 0;
    for(int j = 9; j >= 0; j--){
        int cost = getValue(s[j], a[i]);
        if(cost == -1) continue;
        if(cost + c <= k){
            int d = fun(i+1, cost + c);
            if(d == 1){
                res = 1;
                dir[i][c] = info(i+1, cost + c, j);  // ✅ Fixed here
                break;
            }
        }
    }
    return dp[i][c] = res;
}

void print(int i, int c){
    if(dir[i][c].ans == -1) return;
    cout << dir[i][c].ans;
    print(dir[i][c].i, dir[i][c].c);
}

inline void solve(){
    cin >> n >> k;

    for(int i = 0; i < mx; i++){
        for(int j = 0; j < mx; j++){
            dir[i][j] = info(-1, -1, -1);
        }
    }

    for(int i = 0; i < n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    if(fun(0, 0) == 1){
        print(0, 0);
    } else {
        cout << -1;
    }
    cout << endl;
}

// Time Complexity: O(n * k * 10 * 7) ≈ O(nk)
// Space Complexity: O(nk)

int32_t main() {
    fastIO;
    solve();
    return 0;
}
