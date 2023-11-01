/*
这道题适合用map来解决。
首先用map来统计每个出现的数字出现的次数。
然后需要将其排序。unordered_map不支持直接排序，所以创建一个vector，将map里的数据转存到vector里。
然后对vector里的pair按照第二个值的大小从大到小排序。排序需要借助cmp函数，注意要cmp函数的参数要pass by reference。
排好序后，取前k个pair的第一个值，返回。
*/

class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int,int> &b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for(auto num : nums){
            myMap[num]++;
        }
        std::vector<std::pair<int, int>> vectorMap(myMap.begin(), myMap.end());
        std::sort(vectorMap.begin(), vectorMap.end(), cmp);
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(vectorMap[i].first);
        }
        return result;
    }
};