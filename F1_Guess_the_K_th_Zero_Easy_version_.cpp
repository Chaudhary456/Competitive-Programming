#include<bits/stdc++.h>
#define ll long long 
#define Test int t; cin>>t; while(t--)
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define mod 1000000007
#define all(V) V.begin(),V.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


void solveTest(){
    ll n,k,t,ans,mid,L,R,sum,p;
    cin>>n>>t>>k;
    L=1,R=n;
    while(L<=R){
        mid=(L+R)/2;
        cout<<"? 1 "<<mid<<"\n";
        cout.flush();
        cin>>sum;
        p=mid-sum;
        
        if(p>=k){
            R=mid-1;
            ans=mid;
        }
        else{
            L=mid+1;
        } 
    }
    cout<<"! "<<ans;
    cout<<"\n";
}   

int main(){
    fast;
    // int t;
    // cin>>t;
    // for(int p=1;p<=t;p++){
        solveTest();
        
    // }
       
    return 0;
}