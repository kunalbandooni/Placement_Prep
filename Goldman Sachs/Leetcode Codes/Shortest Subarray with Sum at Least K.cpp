class Solution {
    int min(int a,int b){
        return a<b?a:b;
    }
public:
    int shortestSubarray(vector<int> v, int K) {
        // this part is required because 
          //  overflow test case didn't passed :')
        vector<long long int> A;
        for(int i=0;i<v.size();i++)
            A.push_back(v[i]);
      
        int N = A.size(), res = N + 1;
        deque<long> d;
        for (int i = 0; i < N; i++) {
            if (i > 0)
                A[i] += A[i - 1];
            if (A[i] >= K)
                res = min(res, i + 1);
            while (d.size() > 0 && A[i] - A[d.front()] >= K)
                res = min(res, i - d.front()), d.pop_front();
            while (d.size() > 0 && A[i] <= A[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};
