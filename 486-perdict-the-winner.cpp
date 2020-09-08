#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    
    int max(int a1, int a2){
        return a1 > a2 ? a1 : a2;
    }

    int min(int a1, int a2){
        return a1 < a2 ? a1 : a2;
    }

    int get_score(vector<int>& nums, int start, int len, int who){
        if(len == 1){
            return nums[start] * who;
        }

        int s1 = nums[start] * who + get_score(nums, start + 1, len - 1, - who);
        int s2 = nums[start + len - 1] * who + get_score(nums, start, len - 1, - who);

        return max(s1 * who, s2 * who) * who;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int res = get_score(nums, 0, nums.size(), 1);

        return res >= 0 ? 1 : 0;
    }
};


int main(){
    int nums_a[7] = {0,0,7,6,5,6,1};
    vector<int> nums(nums_a, nums_a + sizeof(nums_a) / sizeof(int));

    Solution sol;

    bool res = sol.PredictTheWinner(nums);

    cout << "[+] res: " << res << endl;

    return 0;
}