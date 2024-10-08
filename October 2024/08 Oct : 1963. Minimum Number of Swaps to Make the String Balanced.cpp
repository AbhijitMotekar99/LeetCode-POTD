class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;
        int swaps = 0;

        for (char ch : s) {
            if (ch == ']') {
                if(imbalance == 0){
                    swaps++;
                    imbalance++;
                }else{
                    imbalance--;
                }
            } else {
                imbalance++;
            }

        }

        return swaps; 
    }
};
