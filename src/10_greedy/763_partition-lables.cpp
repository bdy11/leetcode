class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash [26] = {0}; // i 为字符，hash[i]为字符出现的最后位置
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a'] = i; //统计每个字符串最后出现的位置
        }
        vector<int> result;
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++){
            right = max(right, hash[s[i] - 'a']);
            if(i == right){
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};