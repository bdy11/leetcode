class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int> (n , 0));
        int loopCount = n / 2;
        int count = 1;
        int offset = 1;
        int startX = 0;
        int startY = 0;
        while(loopCount--){
            int i = startX;
            int j = startY;
            for(; j < n - offset; j++){
                result[i][j] = count++;
            }
            for(; i < n - offset; i++){
                result[i][j] = count++;
            }
            for(; j > startX; j--){
                result[i][j] = count++;
            }
            for(; i > startY; i--){
                result[i][j] = count++;
            }
            startX++;
            startY++;
            offset++;
        }
        if(n % 2 != 0){
            result[n/2][n/2] = n*n;
        }
        return result;
        
    }
};