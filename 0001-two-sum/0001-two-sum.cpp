class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){            //instead of finding two num rearrage that as single num;
            int x = target - nums[i];    //target = x+y; we can rearrange as x = target -y;
            if(mp.find(x) != mp.end()){      //checking ele in hash or not;
                ans.push_back(mp[x]);       
                ans.push_back(i);           //pushing answers;
            }
            mp[nums[i]] = i; //Marking visited in Hash;
        }
        return ans;
    }
};