// great question lots and lots of learnings 
// sorting does not really create a problem as we are concernedd with only the min and max not the idx of subsequence 
// power of 2 , r - l  because when we have a subsequence we need all the permutations of it 
// now there will be overflow if  r-l is too big so mod
// Whenever you see repeated powers like 2^k, 3^k, etc. inside loops, it is almost always a hint to precompute all powers first.
// Without precomputation:
// two pointers × exponentiation
// ≈ O(n log n)

// With precomputation:

// precompute powers → O(n)
// two pointers → O(n)
class Solution { 
public:
    const int MOD = 1e9 + 7;
    long long numSubseq(vector<int>& nums, int target) {

        int n = nums.size();
        int l = 0;
        int r = n - 1;
        long long cnt = 0;
        vector<long long > pow2(n);
        pow2[0] = 1;

        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        sort(nums.begin(), nums.end());
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                cnt = (cnt + pow2[r - l]) % MOD;
                // r++ ;
                l++;
            } else {
                r--;
            }
        }

        return cnt;
    }
};
