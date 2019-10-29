class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {0, 0};
    }

    // hash map
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int diff = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; i++){
            diff = target - nums[i];
            
            if(map.find(diff) != map.end()){
                return {map[diff], i};
            }
            
            map[nums[i]] = i; 
        }
        
        return {0, 0};
    }
};