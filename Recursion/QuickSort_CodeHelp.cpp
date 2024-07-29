#include<bits/stdc++.h>
using namespace std;

int par(int *arr,int s,int e){

   int pivot=arr[s];
   int c=0;
   for(int i=s+1;i<=e;i++){
    if(arr[i]<=pivot){
        c++;
    }

   }

   int k=s+c;
   swap(arr[k],arr[s]);

   int i=s,j=e;
   while(i<j){

    while(arr[i]<=pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }
    if(i<j){
        swap(arr[i++],arr[j--]);
    }

   }



   return k;



}


void quicksort(int *arr,int s,int e){



     if(s>=e)
        return ;



     int p=par(arr,s,e);

     quicksort(arr,s,p-1);
     quicksort(arr,p+1,e);




}


int main()
{

    int arr[]={4 ,3, 8,98,2, 5};
    int n=sizeof(arr)/sizeof(int);

    quicksort(arr,0,n-1);

     for(auto i:arr){
        cout<<i<<" ";
    }


}