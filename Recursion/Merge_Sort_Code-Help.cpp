#include<bits/stdc++.h>
using namespace std;

void merg(int arr[],int s,int e){

    int mid=(s+e)/2;

    int len1=mid-s+1;

    int len2=e-mid;

    int arr1[len1],arr2[len2];

    int k=s;
    for(int i=0;i<len1;i++){
        arr1[i]=arr[k++];
    }
    k=mid+1;
     for(int i=0;i<len2;i++){
        arr2[i]=arr[k++];
    }

    int i=0,j=0;
    k=s;
    while(i<len1 &&j<len2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }


    }
    while(i<len1){
        arr[k++]=arr1[i++];
    }
    while(j<len2){
        arr[k++]=arr2[j++];
    }






}

void mergesort(int arr[],int s,int e){

    if(s>=e){
        return ;
    }

    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);

    merg(arr,s,e);


}


int main()
{

    int arr[]={44,54,3,100,2,1};

    int n=sizeof(arr)/sizeof(int);

    mergesort(arr,0,n-1);


    for(auto i:arr){
        cout<<i<<" ";
    }

}