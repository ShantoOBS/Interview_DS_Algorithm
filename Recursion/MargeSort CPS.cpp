#include<bits/stdc++.h>
using namespace std;
int arr[] = {3, 2, 4, 1, 8, 5, 6, 2};

void marge(int l,int mid,int r){
 
    int p=l;
    int q=mid+1;
    int len=r-l+1;
    
    vector<int>v(len);
    int k=0;
    
    for(int i=l;i<=r;i++){
        
        if(p>mid){
            v[k++]=arr[q++];
        }
        else if(q>r){
              v[k++]=arr[p++];
        }
        else if(arr[p]<=arr[q]){
            v[k++]=arr[p++];
            
        }
        else{
           v[k++]=arr[q++];
        }
    }
    k=0;
    for(int i=l;i<=r;i++){
        arr[i]=v[k++];
    }
}

void margeSort(int l,int r){
    
    if(l==r)return  ;
    
    int mid=(l+r)/2;
    margeSort(l,mid);
    margeSort(mid+1,r);
    marge(l,mid,r);
    
}
int main(){
    
    
    
    margeSort(0,8);
    
    for(auto i:arr){
        cout<<i<<" ";
    }
}