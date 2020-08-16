#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int color  = image[sr][sc];
        if(color == newColor) return image;

        queue<pair<int, int> > que;
        que.emplace(sr, sc);

        int x  = image.size(); int y = image[0].size();

        while(!que.empty()){
            int xx = que.front().first;
            int yy = que.front().second;
            que.pop();

            image[xx][yy] = newColor;
            for(int i = 0; i < 4; i++){
                int nx = xx + dx[i];
                int ny = yy + dy[i];

                if(nx >= 0 && nx < x && ny >= 0 && ny < y && image[nx][ny] == color){
                    que.emplace(nx, ny);
                }
            }
        }
        
        return image;
    }
};

int main(){
    vector<vector<int> > image = {{1,1,1},{1,1,0},{1,0,1}};
    // std::vector<int> image = {1,2,3};
    int sr = 1;
    int sc = 1;
    int newColor = 2;

    Solution sol;
    sol.floodFill(image, sr, sc, newColor);

    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image[i].size(); j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}