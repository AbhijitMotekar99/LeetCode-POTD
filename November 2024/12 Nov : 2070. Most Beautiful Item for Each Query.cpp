class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        // Create prefix max beauty array
        vector<pair<int, int>> beauty_by_price; // {price, max_beauty up to this price}
        int max_beauty = 0;
        for (auto& item : items) {
            int price = item[0], beauty = item[1];
            max_beauty = max(max_beauty, beauty);
            beauty_by_price.push_back({price, max_beauty});
        }
        
        // Process each query and answer based on binary search on beauty_by_price
        vector<int> result(queries.size());
        vector<pair<int, int>> query_with_index; // {query value, original index}
        for (int i = 0; i < queries.size(); i++) {
            query_with_index.push_back({queries[i], i});
        }
        // Sort queries to process them in increasing order of price
        sort(query_with_index.begin(), query_with_index.end());
        
        int j = 0;
        for (auto& [query, index] : query_with_index) {
            // Find the rightmost item price <= query
            while (j < beauty_by_price.size() && beauty_by_price[j].first <= query) {
                j++;
            }
            result[index] = j > 0 ? beauty_by_price[j - 1].second : 0;
        }
        
        return result;
    }
};
