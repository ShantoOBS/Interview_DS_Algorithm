// Question Link : https://lightoj.com/problem/jane-and-the-frost-giants

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


int dx[]={0,0,+1,-1,+1,+1,-1,-1};
int dy[]={+1,-1,0,0,+1,-1,+1,-1};

const int mx=212;

char adj[mx][mx];
int levFire[mx][mx], levJan[mx][mx];

vector<pair<int,int>>temp;

int n,m;

void bfsFire(){
  
     for(int i=0;i<mx;i++){
       
       for(int j=0;j<mx;j++) levFire[i][j]=-1;
 
     }
     
     queue<pair<int,int>>q;
     
     for(auto u:temp){
         q.push(u);
         levFire[u.first][u.second]=0;
     }
     
     
     while(!q.empty()){
       
         int x=q.front().first;
         int y=q.front().second;
         
         q.pop();
         
         for(int i=0;i<4;i++){
           
             int x1=dx[i]+x;
             int y1=dy[i]+y;
             
             if(x1>=1 && x1<=n && y1>=1 && y1<=m && adj[x1][y1]!='#' && levFire[x1][y1]==-1){
               
                  levFire[x1][y1]=levFire[x][y]+1;
                 q.push({x1,y1});
             }
         }
     }
     
     
}


void bfsJanVai(int xs, int ys){
  
     for(int i=0;i<mx;i++){
       
       for(int j=0;j<mx;j++) levJan[i][j]=-1;
 
     }
     
     queue<pair<int,int>>q;
     
      q.push({xs,ys});
      
      levJan[xs][ys]=0;
      
     
     while(!q.empty()){
       
         int x=q.front().first;
         int y=q.front().second;
         
         q.pop();
         
         for(int i=0;i<4;i++){
           
             int x1=dx[i]+x;
             int y1=dy[i]+y;
             
             if(x1>=1 && x1<=n && y1>=1 && y1<=m && adj[x1][y1]!='#' && levFire[x1][y1]==-1 && levJan[x][y]+1<levFire[x1][y1]){
               
                 levJan[x1][y1]=levJan[x][y]+1;
                 q.push({x1,y1});
             }
         }
     }
}



inline void solve(){
 
     int t; cin>>t;
     
     for(int tt=1;tt<=t;tt++){
       
          cin>>n>>m;
          
          
          
          int x,y;
          
          
          for(int i=1;i<=n;i++){
            
               for(int j=1;j<=m;j++){
                 
                   cin>>adj[i][j];
                   
                   if(adj[i][j]=='J'){
                      x=i;
                      y=j;
                   }
                   
                   if(adj[i][j]=='F'){
                      
                       temp.emplace_back(i,j);
                   }
               }
          }
          
          bfsFire();
          bfsJanVai(x,y);
          
          int ans=LLONG_MAX;
          
          for(int i=1;i<=n;i++){
            
              if(levJan[i][1]!=-1)ans=min(ans,levJan[i][1]);
          }
          
           for(int i=1;i<=n;i++){
            
              if(levJan[i][m]!=-1)ans=min(ans,levJan[i][m]);
          }
          
           for(int i=1;i<=m;i++){
            
              if(levJan[1][i]!=-1)ans=min(ans,levJan[1][i]);
          }
          
           for(int i=1;i<=m;i++){
            
              if(levJan[n][i]!=-1)ans=min(ans,levJan[n][i]);
          }
          
          if(ans==LLONG_MAX){
             cout<<"case "<<tt<<": "<<"IMPOSSIBLE"<<endl;
              
          }else{
             cout<<"case "<<tt<<": "<<ans+1<<endl;
          }
          
          
          
         
     }
     
   

} 

// tc :
// sc :

int32_t main() {
    fastIO;
    
    solve();

    return 0;
}
