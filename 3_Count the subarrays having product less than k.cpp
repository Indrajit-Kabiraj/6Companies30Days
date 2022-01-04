#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i=0,j=0,cnt=0;
        long long prod = 1LL;
        while(i<n && j<n){
            prod*=a[j];
            if(prod>=k){
                
                while(i<n && prod>=k){
                    prod/=a[i++];
                }
                j++;
                cnt+=(max(0,j-i-1));
                
            }
            else{
                j++;
                cnt+=(j-i-1);
            }
            // cout<<i<<" "<<j<<" "<<prod<<endl;
        }
        // cnt = cnt+((j-i-1)*(j-i))/2;
        for(int i=0;i<n;i++){
            if(a[i]<k)cnt++;
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends