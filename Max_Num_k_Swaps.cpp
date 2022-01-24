
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string maxx;
    // bool maxxof(string s1,string s2){
    //     for(int i=0;i<s1.length();i++){
    //         if(s1[i]-'0'>s2[i]-'0')return false;
    //     }
    //     return true;
    // } 
    
    //// Test Cases: 3
    ///              23092
    ///              o/p: 93220
    
    ///              4
    ///              61892795431
    ///              o/p: 99876215431   
    
    void getmax(string str,int k,int curr){
        if(str>maxx){
            maxx=str;    
        }
        if(k==0){
            return;
        }
        char maxm = str[curr];
        for (int j = curr + 1; j < str.length(); j++) {
            if (str[j]>maxm)
                maxm=str[j];
        }
        
        if(maxm!=str[curr]){
            k--;
        }
        for(int j=str.length()-1;j>=curr;j--){
            if(str[j]== maxm){
                swap(str[curr],str[j]);
                getmax(str,k,curr+1);
                swap(str[curr],str[j]);
            }
        }
        
    }    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {   
        maxx=str;
        getmax(str,k,0);
       
        return maxx;
    }
};

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
