class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return arr[0];
        int lo = 0;
        int hi = n-1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(mid%2 == 0) {
                if(mid+1 < n && arr[mid] == arr[mid+1]) {
                    lo = mid + 1;
                }
                else if(mid-1 >= 0 && arr[mid] == arr[mid-1]) {
                    hi = mid - 1;
                }
                else 
                    return arr[mid];
            }
            else {
                if(mid-1 >= 0 && arr[mid] == arr[mid-1]) {
                    lo = mid + 1;
                }
                else if(mid+1 < n && arr[mid] == arr[mid+1]) {
                    hi = mid - 1;
                }
                else 
                    return arr[mid];
            }
        }
        return -1;
    }
};