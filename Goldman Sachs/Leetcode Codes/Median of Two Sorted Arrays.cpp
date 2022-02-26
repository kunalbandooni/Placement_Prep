class Solution {
    double median(vector<int> a){
        if(a.size()%2!=0)
            return (double)a[a.size()/2];
        double z=a[a.size()/2] + a[a.size()/2-1];
        return z/2;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i<n and j<m){
            if(nums1[i]<nums2[j])
                a.push_back(nums1[i++]);
            else
                a.push_back(nums2[j++]);
        }
        while(i<n)
            a.push_back(nums1[i++]);
        while(j<m)
            a.push_back(nums2[j++]);
        double z=median(a);
        return z;
    }
};
