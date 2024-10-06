class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = splitSentence(sentence1);
        vector<string> words2 = splitSentence(sentence2);
        
        if (words1.size() < words2.size()) {
            swap(words1, words2);
        }
        
        int n1 = words1.size(), n2 = words2.size();
        int i = 0, j = 0;
        
        // Compare from the start
        while (i < n2 && words1[i] == words2[i]) {
            i++;
        }
        
        while (j < n2 && words1[n1 - 1 - j] == words2[n2 - 1 - j]) {
            j++;
        }
        
        return i + j >= n2;
    }
    
private:
    vector<string> splitSentence(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
