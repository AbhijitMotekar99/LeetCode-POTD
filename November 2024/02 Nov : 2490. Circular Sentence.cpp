class Solution {
public:
    bool isCircularSentence(string sentence) {
        std::istringstream stream(sentence);
        std::string word, firstWord, lastWord;
        
        stream >> firstWord;
        lastWord = firstWord;
        
        while (stream >> word) {
            if (lastWord.back() != word.front()) {
                return false;
            }
            lastWord = word;
        }
        
        return lastWord.back() == firstWord.front();
    }
};
