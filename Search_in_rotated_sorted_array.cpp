class Solution {
public:
    int BinarySearch(vector<int>& nums, int s, int e, int tar){
        int start = s;
        int end = e;
        
        while(start<=end){
            int mid = (end-start)/2 + s;
            
            if(nums[mid] == tar){
                return mid;
            }
            else if(nums[mid] > tar){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return -1;
    } 
    
    int pivot(vector<int>& nums, int n){
        int s = 0;
        int e = n-1;
        
        while(s < e){
            int mid = (e-s)/2 + s;
            
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        
        return e;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int piv = pivot(nums, n);
        if(target >= nums[piv] && target <= nums[n-1]){
            return BinarySearch(nums, piv, n-1, target);
        }
        else if(target >= 0 && target <= nums[piv-1]){
            return BinarySearch(nums, 0, piv-1, target);
        }
        else{
            return -1;
        }
    }
