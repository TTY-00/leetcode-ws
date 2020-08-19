#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int l, r, m = 0;
        int len = s.length();


        for(l = 0; l < len; l++){
            for(m = l; m < len; m++){
                int is1 = 1;
                int is2 = 1;

                for(r = m; r <= m + m - l; r++){
                    if(r == len || s[r] != s[m - (r - m)]){
                        is1 = 0;
                        break;
                    }
                }

                if(is1 == 1){
                    res += 1;
                    cout << "s1: " << s.substr(l, (r - l)) << endl;
                }

                for(r = m + 1; r <= m + m - l + 1; r++){
                    if(r == len || s[r] != s[m - (r - m) + 1]){
                        is2 = 0;
                        break;
                    }
                }

                if(is2 == 1){
                    res += 1;
                    cout << "s2: " << s.substr(l, (r - l)) << endl;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    string s ("");
    sol.countSubstrings(s);
    return 0;
}