class Solution {
public:
    int maxScore(string s) {
        int maxscore = 0;
        int totalones = 0;
        int zerosleft = 0;

        for(char ch : s){
            if(ch == '1') totalones++;
        }

        int onesright = totalones;

        for(int i=0;i<s.size()-1;i++){
            if(s[i] == '0') zerosleft++;
            else{
                onesright--;
            }

            int score = zerosleft + onesright;

            maxscore = max(maxscore, score);
        }

        return maxscore;
    }
};
