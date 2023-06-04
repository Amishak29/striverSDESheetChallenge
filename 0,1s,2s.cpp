class Solution {

    void swap(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
    }

public:
    void sortColors(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int ind = i;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[ind]>nums[j]){
                    ind = j;
                }
            }
            swap(nums[i], nums[ind]);
        }
    }
};