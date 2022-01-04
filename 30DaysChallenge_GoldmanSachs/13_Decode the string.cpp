// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int cov(string t){
        int res = 0;
        for(int i=0;i<t.length();i++){
            res = (res)*10 + t[i]-'0';
        }
        // cout<<"res "<<res<<endl;
        return res;
    }
    string decodedString(string s) {
        stack<int> st1;
        st1.push(-1);
        stack<string> st2;
        st2.push("NO");
        string res;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                string num;
                int j = i;
                while(s[j]>='0' && s[j]<='9'){
                    num+=s[j];
                    // cout<<s[j]<<"s[j] "<<endl;
                    j++;
                }
                i = j-1;
                // cout<<num<<endl;
                st1.push(cov(num));
            }
            else{
                if(s[i]==']'){
                    string t;
                    while(st2.top()!="st" && st2.top()!="NO"){
                        string x = st2.top();
                        // cout<<"X: "<<x<<endl;
                        st2.pop();
                        t+=x;
                    }
                    
                    int k = st1.top();
                    st1.pop();
                    string g = t;
                    // cout<<t<< " " <<k<<endl;
                    for(int j=1;j<k;j++){
                        t+=g;
                    }
                    st2.pop();
                    // cout<<t<<endl;
                    // cout<<st2.top()
                    if(st2.top()=="NO"){
                        reverse(t.begin(),t.end());
                        res+=t;
                    }
                    else{
                        st2.push(t);
                    }
                }
                else if(s[i]=='['){
                    st2.push("st");
                }
                else{
                    string k;
                    k+=s[i];
                    // cout<<"K: "<<k<<endl;
                    st2.push(k);
                }
            }
        }
        string left;
        while(st2.top()!="NO"){
            string kk = st2.top();
            st2.pop();
            left+=kk;
        }
        reverse(left.begin(),left.end());
        // cout<<st1.top()<<endl;;
        if(st1.top()!=-1){
            string ke = left;
            for(int i=1;i<st1.top();i++){
                left+=ke;
            }
        }
        res+=left;
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends