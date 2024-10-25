class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        vector<string> res;
        string parent = "";

        for(const string& f : folder){
            if(parent.empty() || f.find(parent + "/") != 0){
                res.push_back(f);
                parent = f;
            }
        }

        return res;
    }
};
