public class RotatedBinaryArray {
    public static void main(String[] args) {
        int[] nums = { 4, 5, 6, 7, 0, 1, 2 };
        int ans = rotatedBinarySearch(nums, 0);
        System.out.println(ans);
    }

    public static int rotatedBinarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            // left side is sorted
            if (arr[start] <= arr[mid]) {
                if (target >= arr[start] && target <= arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }

            }
            // right side is sorted
            else {
                if (target >= arr[mid] && target <= arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }

            }
        }
        return -1;
    }
}
