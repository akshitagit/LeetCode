class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int globalMax = 0;
        int suffixMax = 0;
        int globalMin = 0;
        int suffixMin = 0;
        int total = 0;
        for (int i = 0; i < A.size(); ++ i) {
            total += A[i];
            suffixMax += A[i];
            if (suffixMax < 0) {
                suffixMax = 0;
            }
            globalMax = max(globalMax, suffixMax);
            
            suffixMin += A[i];
            if (suffixMin > 0) {
                suffixMin = 0;
            }
            globalMin = min(globalMin, suffixMin);
        }
        return globalMax > 0 ? max(globalMax, total - globalMin): *max_element(A.begin(), A.end());
    }
};
