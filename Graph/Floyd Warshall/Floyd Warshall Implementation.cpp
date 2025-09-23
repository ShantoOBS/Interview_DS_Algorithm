#include <bits/stdc++.h>
using namespace std;
const int N=503;
const int INF=1e9+7;

int dis[N][N];


int main() 
{
    for(int i=0;i<N;i++){
      
         for(int j=0;j<N;j++){
           
             if(i==j)dis[i][j]=1;
             else dis[i][j]=INF;
         }
    }
    
    int n,m; cin>>n>>m;
    
    
        for(int j=0;j<m;j++){
          
             int x,y,wt; cin>>x>>y>>wt;
             
              dis[x][y]=wt;
        }
    
    
    
    for(int k=1;k<=n;k++){
      
       for(int i=1;i<=n;i++){
         
           for(int j=1;j<=n;j++){
               
                if(dis[i][j]!=INF && dis[k][j]!=INF)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
           }
       }
      
        
    }
    
    for(int i=1;i<=n;i++){
      
        for(int j=1;j<=n;j++){
          if(dis[i][j]==INF)cout<<"INF";
          else cout<<dis[i][j];
          
          cout<<" ";
        }
        cout<<endl;
    }
    
    
}
