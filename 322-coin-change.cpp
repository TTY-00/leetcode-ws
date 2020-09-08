#include <iostream>
#include <vector>

using namespace std;


// class Solution {
// public:
    
//     int coinChange(vector<int>& coins, int amount){
//         vector<int> rem(amount + 1);
//         return sub_coinchange(coins, amount, rem);
//     }

//     int sub_coinchange(vector<int>& coins, int amount, vector<int>& rem) {
//         cout << "amout: " << amount << " " << rem[amount] << " " << INT32_MAX << endl;
//         int min_res = INT32_MAX;
        
//         if(amount < 0){
//             return -1;
//         }
//         if(amount == 0){
//             return 0;
//         }

//         if (rem[amount] != 0) return rem[amount];



//         for(int i: coins){
//             if(i <= amount){
//                 int tmp = sub_coinchange(coins, amount - i, rem);
//                 // cout << "tmp: " << tmp << endl;

//                 if(tmp != -1){
//                     min_res = min(tmp + 1, min_res);
//                 }
//             }
//         }

//         rem[amount] = min_res == INT32_MAX ? -1 : min_res;

//         return rem[amount];
//     }
// };



int main(){
    Solution sol;

    // vector<int> coins({3, 7, 405, 436});
    // int amount = 8839;

    vector<int> coins({1, 2, 5});
    int amount = 11;


    cout << sol.coinChange(coins, amount) << endl;
    return 0;
}