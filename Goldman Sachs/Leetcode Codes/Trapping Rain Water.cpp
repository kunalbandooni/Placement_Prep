class Solution {
public:
    int trap(vector<int>& v) {
        int l=0;
        int r=v.size()-1;
        int sum=0;
        int lmax=0;
        int rmax=0;
        while(l<r)
        {
            if(v[l]<v[r])
            {
                if(v[l]<lmax)
                    sum+=(lmax-v[l]);
                else
                    lmax=v[l];
                l++;
            }
            else
            {
                if(v[r]<rmax)
                    sum+=(rmax-v[r]);
                else
                    rmax=v[r];
                r--;
                
            }
        }
        return sum;
    }
};
