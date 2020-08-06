#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int max(int a, int b){
        return (a > b) ? a : b;
    }

    void count(vector<int>& nums, int* maxs, int i){
        maxs[i] = max(nums[i] + maxs[i + 2], maxs[i + 1]);

        printf("[*] max %d: %d\n", i, maxs[i]);
    }

    int rob(vector<int>& nums) {
        int nums_len = nums.size();
        int* maxs =(int*) malloc((nums_len + 2) * sizeof(int));
        memset(maxs, 0, nums_len + 2);

        for(int i = nums.size() - 1; i >= 0; i--){
            count(nums, maxs, i);
        }

        int res = max(maxs[0], maxs[1]);
        return res;
    }
};

int main(){
    // int nums_l[100] = {2,7,9,3,1,2,7,9,3,1,2,7,9,3,1,2,7,9,3,12,7,9,3,1,2,7,9,3,12,7,9,3,1,2,7,9,3,12,7,9,3,1,2,7,9,3,12,7,9,3,1,2,7,9,3,12,7,9,3,1,2,7,9,3,12,7,9,3,1,2,7,9,3,12,7,9,3,1,2,7,9,3,12,7,9,3,1,2,7,9,3,1};
    // int nums_l[4] = {2, 1, 1, 2};
    int nums_l[1] = {1};
    vector<int> nums(nums_l, nums_l + sizeof(nums_l) / sizeof(nums[0]));

    Solution s;
    int res = s.rob(nums);

    printf("[+] res: %d", res);
    return 0;
}