class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string k,res;
        int mx = 0;
        for(int i=0;i<str2.length();i++){
            k+=str2[i];
            // if(k.length()>(str1.length()+1)/2){
            //     return res;
            // }
            if(str1.length()%k.length()!=0)continue;
            else{
                int len = str1.length()/k.length();
                string s,t;
                for(int i=0;i<len;i++){
                    s+=k;
                }
                int len1 = str2.length()/k.length();
                for(int i=0;i<len1;i++){
                    t+=k;
                }
                if(s==str1 && t==str2){
                    if(k==str2){
                        cout<<k<<endl;
                    }
                    res = k;
                }
            }
        }
        return res;
    }
};