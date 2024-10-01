class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remCount(k,0);

        for(int num : arr){
            int rem = ((num % k) + k) % k;
            remCount[rem]++;
        }

        if(remCount[0] % 2 != 0) return false;

        for(int i=1;i<=k/2;i++){
            if(remCount[i] != remCount[k-i]){
                return false;
            }
        }

        return true;
    }
};
