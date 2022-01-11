#include<bits/stdc++.h>
using namespace std;


int binarySearch(int arr[],int l,int r,int key)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(arr[m]==key)
        return m+1;
        else{
            if(key<arr[m])
            return binarySearch(arr,l,m-1,key);
            else
            return binarySearch(arr,m+1,r,key);
        }
    }
    else
    return -1;

}

int main(){
    int n,ele,p;
    cout<<"Enter the size of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element you want to search: ";
    cin>>ele;
    p=binarySearch(arr,0,n-1,ele);
    if(p==-1)cout<<"Element not found";
    else cout<<"Element present at: "<<p;
    cout<<endl;
    cout<<"Program executed successfully";

    return 0;
}