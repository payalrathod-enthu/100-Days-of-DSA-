class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // Position to place next valid element
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];  // Overwrite with valid element
                k++;
            }
        }
        
        return k;  // Number of elements not equal to val
    }
};
