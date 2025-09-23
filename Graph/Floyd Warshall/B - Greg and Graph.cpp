#include <bits/stdc++.h>
using namespace std;
long long d[1000][1000],ans[1000],i,j,n,x[1000],k;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>d[i][j];
	for(i=1;i<=n;i++) cin>>x[i];
	for(k=n;k>=1;k--){
    	for(i=1;i<=n;i++) for(j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][x[k]]+d[x[k]][j]);
    	for(i=k;i<=n;i++) for(j=k;j<=n;j++) ans[k]+=d[x[i]][x[j]];
    }
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
}
