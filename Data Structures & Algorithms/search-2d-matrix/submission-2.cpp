class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo=0, hi=matrix.size()-1;
        int row=-1;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(target>=matrix[mid][0]) {
                row=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        if(row==-1) return false;
        lo=0;
        hi=matrix[0].size()-1;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(matrix[row][mid]==target) return true;
            else if (matrix[row][mid]>target) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};
