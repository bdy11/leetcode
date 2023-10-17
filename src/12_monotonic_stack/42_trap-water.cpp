/*
这道题需要创建两个数组，分别记录在i位置，左右两边出现过的最大元素的值。
i位置能接的雨水量，等于两侧最大高度取较小值，如果大于i位置本身高度，那么用两侧最大高度的较小值，减去i位置本身高度。
最后，对所有格子的雨水高度求和。
*/
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        leftMax[0] = height[0];
        rightMax[height.size() - 1] = height[height.size() - 1];
        for(int i = 1; i < height.size(); i++){
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        for(int j = height.size() - 2; j >= 0; j--){
            rightMax[j] = max(rightMax[j + 1], height[j]);
        }
        int sum = 0;
        for(int k = 0; k < height.size(); k++){
            if(min(leftMax[k], rightMax[k]) > height[k])
            sum += (min(leftMax[k], rightMax[k]) - height[k]);
        }
        return sum;
    }