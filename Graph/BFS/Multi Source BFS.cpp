/*
    Company Tags                : Will be soon
    GfG Link                    : https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/
*/
//Approach-1 
//T.C :O(V+E)
//S.C :O(V+E)
---------------------------------------------------C++----------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;

int val[N][N];
int vis[N][N];
int lev[N][N];
int n, m;

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
    }
}

vector<pair<int,int>> movements = {
    {0,1}, {0,-1}, {-1,0}, {1,0},
    {1,1},{-1,-1},{1,-1},{-1,1}
};

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}

int bfs(){
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxi = max(maxi, val[i][j]);
        }
    }
    
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(val[i][j] == maxi){
                q.push({i,j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    
    int ans = 0;
    while(!q.empty()){
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;
        q.pop();
        
        for(auto movement : movements){
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            
            if(!isValid(child_x, child_y)) continue;
            if(vis[child_x][child_y]) continue;
            
            q.push({child_x, child_y});
            vis[child_x][child_y] = 1;
            lev[child_x][child_y] = lev[v_x][v_y] + 1;
            ans = max(ans, lev[child_x][child_y]);
        }
    }
    
    return ans;
}

void solve(){
    reset();
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> val[i][j];
    }
    cout << bfs() << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}







-----------------------------------------------------------------------------------Java----------------------------------------------------------
//T.C :O(V+E)
//S.C :O(V+E)
  
import java.util.*;

public class Main {
    static final int N = 1010;   // same as 1e3+10
    static final int INF = (int)1e9 + 10;

    static int[][] val = new int[N][N];
    static int[][] vis = new int[N][N];
    static int[][] lev = new int[N][N];
    static int n, m;

    static int[][] movements = {
        {0,1}, {0,-1}, {-1,0}, {1,0},
        {1,1}, {-1,-1}, {1,-1}, {-1,1}
    };

    static void reset() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                vis[i][j] = 0;
                lev[i][j] = INF;
            }
        }
    }

    static boolean isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    static int bfs() {
        int maxi = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                maxi = Math.max(maxi, val[i][j]);
            }
        }

        Queue<int[]> q = new LinkedList<>();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(val[i][j] == maxi) {
                    q.add(new int[]{i, j});
                    lev[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        int ans = 0;
        while(!q.isEmpty()) {
            int[] v = q.poll();
            int v_x = v[0], v_y = v[1];

            for(int[] move : movements) {
                int child_x = v_x + move[0];
                int child_y = v_y + move[1];

                if(!isValid(child_x, child_y)) continue;
                if(vis[child_x][child_y] == 1) continue;

                q.add(new int[]{child_x, child_y});
                vis[child_x][child_y] = 1;
                lev[child_x][child_y] = lev[v_x][v_y] + 1;
                ans = Math.max(ans, lev[child_x][child_y]);
            }
        }

        return ans;
    }

    static void solve(Scanner sc) {
        reset();
        n = sc.nextInt();
        m = sc.nextInt();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                val[i][j] = sc.nextInt();
            }
        }
        System.out.println(bfs());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            solve(sc);
        }
    }
}
