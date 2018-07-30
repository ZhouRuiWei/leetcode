/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

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
            if(nums[i] >= 0)// if the first is nonnegative. then it is over
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
                    while (j < k && nums[j] == nums[j + 1]) j++;//delete same results
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