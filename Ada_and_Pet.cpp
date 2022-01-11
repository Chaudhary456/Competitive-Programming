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
    ll n,m,x,y,p,q,l,cnt=0,sum=0,ans,k,t;
    string s;
    cin>>s>>k;
    n=s.size();
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        int j=dp[i-1];
        while(j>0 && s[i]!=s[j])
            j=dp[j-1];
        if(s[i]==s[j])j++;

        dp[i]=j;    
    }

    l=dp[n-1];
    cout<<(k*n)-l*(k-1);


    cout<<"\n";
}   

int main(){
    fast;
    int t;
    cin>>t;
    for(int p=1;p<=t;p++){
        solveTest();
        
    }
       
    return 0;
}