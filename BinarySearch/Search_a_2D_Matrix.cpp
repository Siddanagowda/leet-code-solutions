class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m=matrix.size(),n=matrix[0].size();
            int i=0;
            while(i<m){
                if(target<=matrix[i][n-1]){
                    return binarySearch(matrix[i],target);
                }
                i++;
            }
            return false;
        }
        bool binarySearch(vector<int>& mat,int target){
            int left=0,right=mat.size()-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(mat[mid]==target) return true;
                else if(mat[mid]>target) right=mid-1;
                else left=mid+1;
            }
            return false;
        }
    };