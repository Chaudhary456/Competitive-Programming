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

int dp[10001],inv[10001],arr[10001];

ll inv_mod(ll a,ll m){
    ll result = 1;
 
	while(m)
	{
		if(m & 1) result = (result * a) % mod;
 
		m >>= 1;
		a = (a * a) % mod;
	}
 
	return result;
}

void init(string s){
    ll p_i=1;
    ll prime=31;
    ll val=0;
    inv[0]=1;
    dp[0]=(s[0]-'a'+1);
    arr[0]=p_i;
    for(int i=1;i<s.size();i++){
        p_i=(p_i*prime)%mod;
        inv[i]=inv_mod(p_i,mod-2);
        arr[i]=p_i;
        dp[i]=(dp[i-1]+(s[i]-'a'+1)*p_i)%mod;
    }

}

int getHash(string s){
    ll p_i=1;
    ll prime=31;
    ll val=0;
    for(int i=0;i<s.size();i++){
        val=(val+(s[i]-'a'+1)*p_i)%mod;
        p_i=(p_i*prime)%mod;
    }
    return val;
}

ll substringHash(int L,int R){
    ll result=dp[R];
        if(L>0){
            result=(result-dp[L-1]+mod)%mod;
        }
        result=result%mod;

        return result;
}


int main(){
    fast;
    ll n,m,x,l,r,y,p,q;
    string s,ned;
    while(cin>>n){
        cin>>ned;
        cin>>s;
        init(s);
        x=getHash(ned);
        // for(ll i=0;i<s.size();i++)cout<<arr[i]<<" ";
        for(l=0,r=ned.size()-1;r<s.size();l++,r++){
            if((x*arr[l])%mod==substringHash(l,r)){
                cout<<l<<"\n";
            }
        }
        cout<<endl;
    
    }
       
    return 0;
}