class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int n = word.size();

        for(int i=0;i<n;){
            char currchar = word[i];
            int count = 0;
            
           while(i < n && word[i] == currchar){
            count++;
            i++;
           }

           while(count > 9){
            res += "9" + string(1,currchar);
            count -= 9;
           }

           res += to_string(count) + currchar;
        }
        return res;
    }
};
