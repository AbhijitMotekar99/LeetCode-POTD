class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1; 
        int n = searchWord.length();
        stringstream ss(sentence); 
        string word;

        while (ss >> word) {
            if (word.substr(0, n) == searchWord) {
                return index;
            }
            index++;
        }
        
        return -1;
    }
};
