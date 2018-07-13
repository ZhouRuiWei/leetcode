class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i!= n-2;i++)
        {
            if(nums[i] >= 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = 0 - nums[i];
            int j = i+1, k = n-1;
            while(j < k)
            {
                if(nums[j]+nums[k] == target)
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                }
                else
                    if(nums[j]+nums[k] < target)
                        j++;
                    else
                        k--;
            }

        }
        return result;
    }
};