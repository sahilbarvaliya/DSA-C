public class findFirstAndLastIndex {
    public static void main(String[] args) {
        int[] nums = {5,7,7,8,8,8,10};
        int target = 8;
        int[] ans = searchRange(nums,target);
        System.out.println(ans[0]+" "+ans[1]);
        
    }
    public static int[] searchRange(int[] nums, int target) {
        int[] ans = {-1,-1};
        if(nums.length == 0) return ans;
        int start = search(nums,target,true);
        int end = search(nums,target,false);

        ans[0]=start;
        ans[1]=end;
        return ans;
    }

    public static int search(int[] nums, int target, boolean startIndex){
        int ans = -1;
        int start = 0,end = nums.length-1;
        int mid = start + (end-start)/2;
        while(start <= end){
            if(target < nums[mid]){
                end = mid - 1;
            }else if(target > nums[mid]){
                start = mid + 1;
            }else {
                ans = mid;
                if(startIndex){
                    end = mid - 1;
                }else{
                    start=mid + 1; 
                }
            }
            mid = start + (end-start)/2;
        }

        return ans;
    }
}
