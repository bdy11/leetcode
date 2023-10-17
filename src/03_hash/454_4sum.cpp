/*
454. 4Sum II
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
*/

/*
solution:
1. define an unordered_map, key is used to store sum of a and b, value counts for how many times the sums occurs.
2. iterate through nums1 and nums2, and count how many times a + b occurs and store it in unordered_map.
3. define count to store the return value
4. iterate through nums3 and nums4, and find - (a + b), if find -(a + b) in map, count increase accordingly.
5. return count
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int, int> map;
        int count = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                map[nums1[i] + nums2[j]]++;
            }
        }

        for(int k = 0; k < nums3.size(); k++){
            for(int l = 0; l < nums4.size(); l++){
                if(map.find(-nums3[k] - nums4[l])!= map.end()){
                    count += map[-nums3[k] - nums4[l]];
                }
            }
        }
        
        return count;
        
    }
};
