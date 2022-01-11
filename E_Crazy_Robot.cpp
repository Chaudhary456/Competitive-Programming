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

queue<pair<ll,ll>>q;
int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool isvalid(int x,int y){
    if(x>=0 &&x<n && y>=0 && y<m)return true;
    
    return false;
} 
void BFS(vector<int>arr[]){
    while(!q.empty()){
        int currX=q.front().F;
        int currY=q.front().S;
        q.pop();
        for(int i=0;i<4;i++){
            int newX=currX+dx[i];
            int newY=currY+dy[i];
            if(isvalid(newX,newY) && arr[newX][newY]==0){
                int cnt=0;
                for(int i=0;i<4;i++){
                    int newXX=newX+dx[i];
                    int newYY=newY+dy[i];
                    if(isvalid(newXX,newYY) && arr[newXX][newYY]==0){
                        cnt++;
                    }
                }
                if(cnt<=1){
                    arr[newX][newY]=1;
                    q.push({newX,newY});
                    // cout<<newX<<" "<<newY<<endl;
                }
            }
        }
    }
}
void solveTest(){
	char ch;
	cin>>n>>m;
	vector<int>arr[n];
	ll idx,idy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ch;
            if(ch=='#')arr[i].pb(-1);
            else if(ch=='L'){
                arr[i].pb(1);
                idx=i;
                idy=j;
            }
            else arr[i].pb(0);
        }
    }    
    
    q.push({idx,idy});
    BFS(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==idx && j==idy)cout<<"L";
            else if(arr[i][j]==1)cout<<"+";
            else if(arr[i][j]==-1)cout<<"#";
            else cout<<".";
        }cout<<"\n";
    }
    
    // cout<<"\n";
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