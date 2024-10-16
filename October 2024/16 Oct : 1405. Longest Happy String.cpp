class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
         priority_queue<pair<int, char>> maxHeap;
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        string result;

        while (!maxHeap.empty()) {
            auto [count, charToAdd] = maxHeap.top();
            maxHeap.pop();

            // If the last two characters in the result are the same as charToAdd
            // We need to check the next character in the heap
            if (result.size() >= 2 && result[result.size() - 1] == charToAdd && result[result.size() - 2] == charToAdd) {
                // If there's no other character left to add, we break
                if (maxHeap.empty()) break;

                // Get the next character
                auto [nextCount, nextChar] = maxHeap.top();
                maxHeap.pop();

                // Add the next character
                result += nextChar;
                nextCount--;

                // If there are more of the next character left, push it back to the heap
                if (nextCount > 0) maxHeap.push({nextCount, nextChar});

                // Push back the original character since we didn't use it
                maxHeap.push({count, charToAdd});
            } else {
                // We can add the characterToAdd
                int toAdd = min(count, 2); // we can add at most 2 of the same character
                result += string(toAdd, charToAdd);
                count -= toAdd;

                // If there are more of charToAdd left, push it back to the heap
                if (count > 0) maxHeap.push({count, charToAdd});
            }
        }

        return result;
    }
};
