#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
        ull un[n+5];
        memset(un,0,sizeof(un));
        un[0] = 1;
        ull pt1 = 1,pa=0,pb=0,pc=0,mn2=2,mn3=3,mn5=5,now;
        // s.insert(1);
        while(n-->1){
            now = min({mn2,mn3,mn5});
            un[pt1] = now;
            if(now == mn2){
                mn2 = un[++pa]*2;
            }
            if(now == mn3){
                mn3 = un[++pb]*3;
            }
            if(now == mn5){
                mn5 = un[++pc]*5;
            }
            pt1++;
        }
        // cout<<s.size()<<endl;
        return now;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends