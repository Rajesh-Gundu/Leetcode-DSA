class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        unordered_set<int>s;
        for(auto i : nums)
            s.insert(stoi(i,0,2));
        int ans = 0;
        for(int i=0;i<(1<<n);i++){
            if(!s.count(i)){
                ans = i;
                break;
            }
        }
        bitset<32>binary(ans);
        string res = binary.to_string();
        res = res.substr(32-n);
        return res;
    }
};