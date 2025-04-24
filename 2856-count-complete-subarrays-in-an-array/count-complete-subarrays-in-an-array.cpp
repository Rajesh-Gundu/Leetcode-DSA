class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> u;
        for (auto& num : nums) {
            u.insert(num);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> cur;

            for (int j = i; j < n; j++) {
                cur.insert(nums[j]);
                if (cur.size() == u.size()) {
                    cnt += (n - j);
                    break;
                }

            }
        }
        return cnt;
    }
};