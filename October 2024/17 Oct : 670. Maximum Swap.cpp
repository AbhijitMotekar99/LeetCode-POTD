class Solution {
public:
    int maximumSwap(int num) {
        string numstr = to_string(num);
        int n = numstr.size();

        int rightmost[n];
        rightmost[n-1] = n-1;

        for(int i = n-2;i >= 0; --i){
            if(numstr[i] > numstr[rightmost[i+1]]){
                rightmost[i] = i;
            }else{
                rightmost[i] = rightmost[i+1];
            }
        }

         for (int i = 0; i < n; ++i) {
            if (numstr[i] != numstr[rightmost[i]]) {
                swap(numstr[i], numstr[rightmost[i]]);
                break;
            }
        }

        return stoi(numstr);

    }
};
