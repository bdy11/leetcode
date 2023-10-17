/*
link:
https://leetcode.com/problems/binary-search/

notes:
the basic idea is to divide the range into half iteratively.
for this purpose, we have to define a interval starting from index left to index right.

before writing the code, you have to figure out what the boundary of the interval should be.
1. if we use [left, right], then
int left = 0;
int right = nums.size() - 1;
while(left <= right){
    int mid = left + (right - left) / 2;
    if(nums[mid] < target){
        left = mid + 1;
    }else if(nums[mid] > target){
        right = mid - 1;
    }else{
        return mid;
    }
}
2. if we use [left, right), then
int left = 0;
int right = nums.size();
while(left < right){
    int mid = left + (right - left) / 2;
    if(nums[mid] < target){
        left = mid + 1;
    }else if(nums[mid] > target){
        right = mid;
    }else{
        return mid;
    }
}

*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid;
            }
            else{
                return mid;
            }
        }

        return -1;
    }
};