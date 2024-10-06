class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        
        long long totalSkillSum = 0;
        for (int s : skill) {
            totalSkillSum += s;
        }
        
        int n = skill.size();
        int teamSize = n / 2;
        
        if (totalSkillSum % teamSize != 0) {
            return -1;  
        }
        
        int targetSkillPerTeam = totalSkillSum / teamSize;
        long long totalChemistry = 0;
        
        for (int i = 0; i < teamSize; ++i) {
            int player1 = skill[i];
            int player2 = skill[n - 1 - i];
            
            if (player1 + player2 != targetSkillPerTeam) {
                return -1;
            }
            
            totalChemistry += (long long) player1 * player2;
        }
        
        return totalChemistry;
    }
};
