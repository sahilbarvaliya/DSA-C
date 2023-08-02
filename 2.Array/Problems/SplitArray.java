public class SplitArray {

  public static void main(String[] args) {
    int[] nums = { 1,4,4 };
    int ans = splitArray(nums, 3);
    System.out.println(ans);
  }

  public static int splitArray(int[] arr, int target) {
    int start = 0, end = 0;

    for (int i = 0; i < arr.length; i++) {
      start = Math.max(start, arr[i]);
      end += arr[i];
    }

    while (start < end) {
      int mid = start + (end - start) / 2;

      int sum = 0;
      int pieces = 1;

      for (int num : arr) {
        if (sum + num > mid) {
          sum = num;
          pieces++;
        } else {
          sum += num;
        }
      }

      if (pieces > target) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return end;
  }
}
