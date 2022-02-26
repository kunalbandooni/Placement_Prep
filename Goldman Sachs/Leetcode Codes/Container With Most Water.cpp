class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int maxi=0;
        int i=0,j=height.size()-1;
        while(i<j){
            if(height[i]>height[j]){
                maxi=max(maxi,(j-i)*height[j--]);
            }
            else{
                maxi=max(maxi,(j-i)*height[i++]);
            }
        }
        return maxi;
    }
};
