/*
solution:
it is always not easy to figure out the loop limit, to use < or <=.
in this specific example, use i < s.size() / 2.

*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i++){
            swap(s[i], s[s.size() - i - 1]);
        }        
    }
};