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
    ll n,m,x,y,a,b,w,p,q,cnt=0,sum=0,ans,k,t;
    cin>>n;
    ll dp[n+1][n+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)
            cin>>dp[i][j];
    }
    cin>>k;
    while(k--){
        sum=0;
        cin>>a>>b>>w;
        dp[a][b]=dp[b][a]=min(dp[a][b],w);
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][a]+w+dp[b][j]);
                dp[i][j]=min(dp[i][j],dp[i][b]+w+dp[a][j]);
                sum+=dp[i][j];
            }
        }
        cout<<sum/2<<" ";
    }


    // cout<<"\n";
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