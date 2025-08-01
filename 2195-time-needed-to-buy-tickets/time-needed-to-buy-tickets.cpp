class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = 0;
        for(int i=0;i<=k;i++) {
            if(tickets[i] > tickets[k])
                sum += tickets[k];
            else
                sum += tickets[i];
        }
        for(int i=k+1;i<tickets.size();i++) {
            if(tickets[i] >= tickets[k])
                sum += tickets[k]-1;
            else
                sum += tickets[i];
        }
        return sum;
    }
};