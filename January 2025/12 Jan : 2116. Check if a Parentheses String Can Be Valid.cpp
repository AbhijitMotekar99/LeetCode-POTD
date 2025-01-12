class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 != 0) return false;
        
        int open = 0,close = 0;
        for(int i = 0;i < s.size();i++){
            if(locked[i] == '0' || s[i] == '('){
                open++;
            }else{
                close++;
            }

            if(close > open) return false;
        }

        open = close = 0;
        for(int i = s.size()-1;i >= 0;i--){
            if(locked[i] == '0' || s[i] == ')'){
                close++;
            }else{
                open++;
            }

            if(open > close) return false;
        }

        return true;
    }
};
