class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        while (k--) {
            int maxGifts = maxHeap.top();
            maxHeap.pop();
            int remaining = floor(sqrt(maxGifts));
            maxHeap.push(remaining);
        }
        
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }
        return totalGifts;
    }
};
