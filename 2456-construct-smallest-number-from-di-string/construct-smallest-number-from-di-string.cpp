class Solution {
public:
    string smallestNumber(string pattern) {
        vector<int> v;
       string ans;
       int num = 1;
       for(int i=0;i<=pattern.length();i++){
         v.push_back(num);
         num++;
         if(i == pattern.length() || pattern[i] == 'I')
            while(!v.empty()){
                ans += to_string(v.back());
                v.pop_back();
            }
       }
       return ans;
    }
};