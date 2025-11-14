typedef pair<int,int> P;
class Solution {
    void solve(int lo,int mid,int hi,vector<P>& nums,vector<int>& ans) {
        int i = lo;
        int j = mid + 1;
        while(i <= mid) {
            while(j <= hi && nums[j].first < nums[i].first)
                j++;
            
            ans[nums[i].second] += j-mid-1;  
            i++;
        }
    }

    void merge(int lo,int mid,int hi,vector<P>& nums) {
        int n1 = mid - lo + 1;
        int n2 = hi - mid;
        vector<P> left(n1);
        vector<P> right(n2);
        for(int i=0;i<n1;i++) {
            left[i] = nums[i+lo];
        }
        for(int i=0;i<n2;i++) {
            right[i] = nums[i+mid+1];
        }

        int i = 0;
        int j = 0;
        int k = lo;
        while(i < n1 && j < n2) {
            if(left[i].first <= right[j].first) {
                nums[k++] = left[i++];
            }
            else {
                nums[k++] = right[j++];
            }
        }

        while(i < n1) {
            nums[k++] = left[i++];
        }

        while(j < n2) {
            nums[k++] = right[j++];
        }
    }


    void mergesort(int lo,int hi,vector<P>& nums,vector<int>& ans) {
        if(lo >= hi)    
            return;
        
        int mid = lo + (hi-lo)/2;
        mergesort(lo,mid,nums,ans);
        mergesort(mid+1,hi,nums,ans);
        solve(lo,mid,hi,nums,ans);
        merge(lo,mid,hi,nums);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<P> num(n);
        for(int i=0;i<n;i++) {
            num[i] = {nums[i],i};
        }
        mergesort(0,n-1,num,ans);
        return ans;
    }
};