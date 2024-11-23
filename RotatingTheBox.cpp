class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> rotate(n, vector<char>(m, '.'));

        for(int i=0; i<m; i++){
            int bottom=n-1;
            for(int j=n-1; j>=0; j--){
                if (box[i][j]=='#'){
                    rotate[bottom][m-1-i]='#';
                    bottom--;
                }
                else if (box[i][j]=='*'){
                    rotate[j][m-1-i]='*';
                    bottom=j-1;
                }
            }
        }
        return rotate;
    }
};