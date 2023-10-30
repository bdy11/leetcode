class Solution {
public:
    int getSumOfSquares(int n){
        int ret = 0;
        while(n > 0){
            ret += pow(n % 10, 2);
            n /= 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        unordered_set<int> nums;
        nums.insert(n);
        while(n != 1){
            n = getSumOfSquares(n);
            if(nums.find(n) != nums.end()){
                return false;
                break;
            }
            else{
                nums.insert(n);
            }
        }
        return true;
    }
};