class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    bool is_palindrome(string s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    void back_tracking(string s, int startIndex){
        if(startIndex >= s.size()){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(is_palindrome(s, startIndex, i)){
                string str= s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }else{
                continue;
            }
            back_tracking(s, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        back_tracking(s, 0);
        return result;
    }
};