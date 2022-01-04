#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s){     
  char x = s[0];
  int cnt=1;
  string res;
  for(int i=1;i<s.length();i++){
      if(s[i]==x)cnt++;
      else{
          res+=x;
          res+=(cnt+'0');
          cnt=1;
      }
      x = s[i];
  }
  res+=x;
  res+=(cnt+'0');
  return res;
}     
 
