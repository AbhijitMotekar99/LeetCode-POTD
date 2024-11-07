class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitcount(24, 0);

        for(int num : candidates){
            for(int i=0;i<24;i++){
                if(num & (1 << i)){
                    bitcount[i]++;
                }
            }
        }

        return *max_element(bitcount.begin(),bitcount.end());
    }
};
