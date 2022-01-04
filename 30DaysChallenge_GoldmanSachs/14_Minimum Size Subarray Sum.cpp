class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }
        int n=nums.size(),mn = nums.size()+1;
        for(int i=0;i<n;i++){
            if(nums[i]-target == 0){
                mn = min(mn,i+1);
            }
            else{
                if(nums[i]-target<0)continue;
                else{
                    int it = lower_bound(nums.begin(),nums.end(),nums[i]-target)-nums.begin();
                    if(nums[it] == nums[i]-target){
                        mn = min(mn,i-it);
                    }
                    else{
                        mn = min(mn,i-it+1);
                    }
                }
            }
        }
        if(mn == n+1)return 0;
        else
            return mn;
    }
};