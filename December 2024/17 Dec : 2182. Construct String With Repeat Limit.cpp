class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        
        // Step 2: Use a max heap (priority queue) to sort characters by lexicographical order
        priority_queue<pair<char, int>> maxHeap;
        for (auto& it : freq) {
            maxHeap.push({it.first, it.second}); // {char, frequency}
        }
        
        string result = "";  // Resultant string
        while (!maxHeap.empty()) {
            // Get the largest available character
            auto [ch1, freq1] = maxHeap.top();
            maxHeap.pop();
            
            int useCount = min(freq1, repeatLimit); // Use up to 'repeatLimit' times
            result.append(useCount, ch1);          // Append the character to the result
            
            freq1 -= useCount; // Remaining frequency of ch1
            
            // If the repeat limit is hit and there are more characters of 'ch1' remaining
            if (freq1 > 0) {
                if (maxHeap.empty()) break; // If no alternative characters exist, stop
                
                // Get the next largest character
                auto [ch2, freq2] = maxHeap.top();
                maxHeap.pop();
                
                result += ch2; // Append one instance of the next largest character
                freq2--;       // Decrease its frequency
                
                // Put both characters back into the heap if they have remaining frequencies
                if (freq2 > 0) maxHeap.push({ch2, freq2});
                maxHeap.push({ch1, freq1});
            }
        }
        
        return result;
    }
};
