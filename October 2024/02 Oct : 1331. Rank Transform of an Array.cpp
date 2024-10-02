class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};

        vector<int> sorted = arr;
        sort(sorted.begin(),sorted.end());

        unordered_map<int,int> rankmap;
        int rank = 1;

        for(int num : sorted){
            if(rankmap.find(num) == rankmap.end()){
                rankmap[num] = rank;
                rank++;
            }
        }

        vector<int>result(arr.size());
        for(int i=0;i<result.size();i++){
            result[i] = rankmap[arr[i]];
        }

        return result;
    }
};
