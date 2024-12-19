class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int currmax = 0;
        int ans = 0;

        for(int i=0;i<arr.size();i++){
            currmax = max(currmax, arr[i]);

            if(currmax == i){
                ans++;
            }
        }

        return ans;
    }
};
