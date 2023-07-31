public class findTheElementInInfiniteArray {

  public static void main(String[] args) {
    int[] nums = {
      1,
      2,
      3,
      4,
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,
      17,
      18,
      19,
      20,
      100,
      200,
      300,
      400,
      500,
      600,
      700,
      800,
      900,
      1000,
      10000,
    };
    int target = 10;
    int ans = findElement(nums, target);
    System.out.println(ans);
  }

  public static int findElement(int[] arr, int target) {
    int start = 0;
    int end = 1;

    while (target > arr[end]) {
      int temp = end + 1;
      end = end + (end - start + 1) * 2;
      start = temp;
    }

    return binarySearch(arr, target, start, end);
  }

  public static int binarySearch(int[] arr, int target, int start, int end) {
    int mid = start + (end - start) / 2;

    while (start <= end) {
      if (arr[mid] == target) {
        return mid;
      } else if (arr[mid] < target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
      mid = start + (end - start) / 2;
    }
    return mid;
  }
}
