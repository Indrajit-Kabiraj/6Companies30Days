#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    bool solve(string &res,int i,int n,vector<int>& vis,char last,string s){
        if(i == n)return true;
        // cout<<res.back()<<endl;
        for(int j=1;j<=9;j++){
            if(last == 'D'){
                if(res.back()>(j+'0') && !vis[j]){
                    vis[j] = 1;
                    res.push_back(j+'0');
                    if(solve(res,i+1,n,vis,s[i],s)){
                        return true;
                    }
                    vis[j] = 0;
                    res.pop_back();
                }
            }
            else{
                if(res.back()<(j+'0') && !vis[j]){
                    vis[j] = 1;
                    res.push_back(j+'0');
                    if(solve(res,i+1,n,vis,s[i],s)){
                        return true;
                    }
                    vis[j] = 0;
                    res.pop_back();
                }
            }
        }
        return false;
    }
    string printMinNumberForPattern(string s){
        string res;
        if(s[s.length()-1]=='D')s.push_back('D');
        else
            s.push_back('I');
        vector<int> vis(10,0);
        solve(res,0,s.length(),vis,'0',s);
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends