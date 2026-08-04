class Solution {
public:
 bool BinarySearch(vector<int>& matrix, int target){
       int n=matrix.size();
       int low=0,high=n-1;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(matrix[mid]>target){
                high=mid-1;
            }
            else if(matrix[mid]<target){
                low=mid+1;
            }
            else{
                return true;
            }    
        }
        return false;;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //m*n matrix
        int m=matrix.size();
        int maxi=0;
        int ans=-1;
        for(int i=0; i<m; i++){
            int n=matrix[i].size();
            bool ans=BinarySearch(matrix[i],target);
            if(ans){
                return true;
            }
        }
        return false;
    }
};