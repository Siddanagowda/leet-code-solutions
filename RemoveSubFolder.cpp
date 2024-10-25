class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        sort(folder.begin(),folder.end());
        for(const string& f:folder){
            if(result.empty()||f.find(result.back()+'/')!=0)
                result.push_back(f);
        }
        return result;
    }
};