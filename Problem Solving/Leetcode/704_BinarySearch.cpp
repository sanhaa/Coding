class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1, low = 0;
        int mid = 0;
        
        while(low <= high){
            mid = (low + high)>>1; // divide by 2

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
};

// main
