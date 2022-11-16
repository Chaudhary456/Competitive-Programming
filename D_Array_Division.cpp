/**
        @        @ 
 @@@@@    @@@@@     @@@@          @  @@@@  @@@@
  @  @  @  @  @  @  @  @         @@  @     @
  @  @  @  @  @  @  @  @        @@@@ @@@@  @@@@
  @  @  @  @  @  @  @  @          @     @  @  @
  @  @  @  @  @  @  @@@@@ @@@@@   @  @@@@  @@@@
                 @  
               @@@

**/

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
    ll n,sum=0,curr=0,x;
    cin>>n;
    ll arr[n+5];
    unordered_map<ll,int>first,second;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum&1){
        cout<<"NO";
        return;
    }else{
        sum=sum/2;
        first[arr[0]]++;
        for(int i=1;i<n;i++)second[arr[i]]++;
        
        for(int i=0;i<n;i++){
            curr=curr+arr[i];
            
            if(curr==sum){
                cout<<"YES";
                return;
            }else if(curr<sum){
                x=sum-curr;
                if(second[x]>0){
                    cout<<"YES";
                    return;
                }
            }else{
                x=curr-sum;
                if(first[x]>0){
                    cout<<"YES";
                    return;
                }
            }
            first[arr[i+1]]++;
            second[arr[i+1]]--;
        }
    
    }
    cout<<"NO";
    // cout<<"\n";
}   

int main(){
    fast;
    // ll t;
    // cin>>t;
    // for(int p=1;p<=t;p++){
        // cout<<"Case #"<<p<<":"<<" ";
        solveTest();
        
    // }
       
    return 0;
}