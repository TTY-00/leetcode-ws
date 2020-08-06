#include <iostream>
#include <vector>
// #include <>

using namespace std;

class Solution {
public:
    int find_pos(vector<int>& nums1, int num2, int left, int right){
        int l = left;
        int r = right;
        int p = (l + r) / 2;

        while(1){
            if(num2 <= nums1[l]) return l;
            if(num2 >= nums1[r]) return r + 1;

            if(num2 < nums1[p]){ 
                r = p - 1;
                p = (r + l) / 2;
            }
            else if(num2 > nums1[p]){ 
                l = p + 1;
                p = (r + l) / 2;
            }
            else if(num2 == nums1[p]){ return p + 1;}
        }

        return p;
    }

    double get_mid(vector<int>& nums){
        int len = nums.size();

        if(len % 2 == 0){
            return (double)(nums[len / 2] + nums[len / 2 - 1]) / 2;
        }
        else{
            return nums[len / 2];
        }
    }

    void merge(vector<int>& nums1, int nums1l, int nums1r, vector<int>& nums2, int nums2l, int nums2r){
        // cout << "\nmerge" << endl;
        // cout << "nums1l: " << nums1l << " nums1r: " << nums1r << " nums2l: " << nums2l << " nums2r: " << nums2r << endl;
        

        int m = (nums2l + nums2r) / 2;
        // cout << "nums2[m]: " << nums2[m] << " nums1l: " << nums1l << " nums1r: " << nums1r << endl;
        int p = find_pos(nums1, nums2[m], nums1l, nums1r);
        nums1.insert(nums1.begin() + p, nums2[m]);

        nums1r += 1;

        if(m < nums2r){
            merge(nums1, p, nums1r, nums2, m + 1, nums2r);
        }    
        if(m > nums2l){
            merge(nums1, nums1l, p, nums2, nums2l, m - 1);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        if(nums1.size() == 0) return get_mid(nums2);
        if(nums2.size() == 0) return get_mid(nums1);

        merge(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1);

        for(int i = 0; i < nums1.size(); i++){
            cout << nums1[i] << "," ;
        }
        cout << endl;
        return get_mid(nums1);
    }
};


int main(){
    Solution sol;
    // int nums1_l[8] = {1,2,3,5,6,7,8,9};
    // int nums1_l[1] = {0};
    // vector<int> nums1 (nums1_l, nums1_l + sizeof(nums1_l) / sizeof(nums1_l[0]));
    // int res = sol.find_pos(nums1, 10, 0, 0);

    int nums1_l[4] = {1,1,3,3};
    vector<int> nums1 (nums1_l, nums1_l + sizeof(nums1_l) / sizeof(nums1_l[0]));
    // int nums1_l[0] = {};
    // vector<int> nums1 (nums1_l, nums1_l + 0);

    int nums2_l[4] = {1,1,3,3};
    vector<int> nums2 (nums2_l, nums2_l + sizeof(nums2_l) / sizeof(nums2_l[0]));

    // int nums2_l[0] = {};
    // vector<int> nums2 (nums2_l, nums2_l + 0);

    double res = sol.findMedianSortedArrays(nums1, nums2);
    printf("\nres: %f\n", res);
    return 0;
}