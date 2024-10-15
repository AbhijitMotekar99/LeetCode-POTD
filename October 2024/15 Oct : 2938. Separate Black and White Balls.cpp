class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long steps = 0;
        int whiteball = 0;
        
        for(int i = n-1;i >= 0; --i){
            if(s[i] == '0'){
                whiteball++;
            }else{
                steps += whiteball; 
            }
        }

        return steps;
    }
};
