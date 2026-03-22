// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int* Sort(int* left, int* right, int s1, int s2){
    int* joined = new int[s1+s2];
    int i=0,j=0,k=0;
    while(i<s1 && j<s2){
        if(left[i]<right[j])joined[k++] = left[i++];
        else joined[k++] = right[j++];
    }
    while(i<s1)joined[k++] = left[i++];
    while(j<s2)joined[k++] = right[j++];
    return joined;
    
}
int* merge(int * arr, int size){
    if(size<=1)return arr;
    int mid = size/2;
    int* left = new int[mid];
    int* right = new int[size-mid];
    for(int ind=0;ind<mid;ind++){
        left[ind] = arr[ind];
    }
    int itr = 0;
    for(int i=mid;i<size;i++)right[itr++] = arr[i];
    left = merge(left,mid);
    right  = merge(right,size-mid);
    return Sort(left,right,mid,size-mid);
}
int main(){
    int n;
    cin>>n;
    int* arr =  new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    arr = merge(arr,n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}