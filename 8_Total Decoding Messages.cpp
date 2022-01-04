#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution {
    int MOD = 1e9+7;
	public:
		int CountWays(string s){
		    int n = s.length();
		  //  cout<<n<<endl;
            int dp[n+1];
            for(int i=0;i<=n;i++)dp[i]=0;
            dp[n] = 1;
            for(int i= n-1;i>=0;i--){
                if(s[i]!='0'){
                    dp[i] = (dp[i]+dp[i+1])%MOD;
                }
                if(i<s.length()-1 && (s[i]=='1' || s[i] == '2' && s[i+1]<'7')){
                    dp[i]=(dp[i]+dp[i+2])%MOD;
                }

            }
            return dp[0];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends