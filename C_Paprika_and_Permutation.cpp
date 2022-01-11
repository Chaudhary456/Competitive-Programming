#include<bits/stdc++.h>
#define ll long long int
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
    
    long long n,f=1,cc=0;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    map<int,int>mp;
    vector<int>v1,v2;
    for(int i=0;i<n;i++){
        if(arr[i]<=n && mp[arr[i]]==0){
            mp[arr[i]]++;
        }
        else{
            v2.pb(arr[i]);
        }
    }
    
    for(int i=1;i<=n;i++){
        if(mp[i]==0){
            v1.pb(i);
        }
    }
    for(int i=0;i<v1.size();i++){
        if(v2[i]<v1[i]*2+1){
            f=0;
            break;
        }
        else cc++;
    }
    if(f==1)cout<<cc;
    else cout<<-1;
    cout<<"\n";
    
}   

int main(){
    fast;
    ll t;
    cin>>t;
    for(int p=1;p<=t;p++){
        // cout<<"Case #"<<p<<":"<<" ";
        solveTest();
        
    }
       
    return 0;
}