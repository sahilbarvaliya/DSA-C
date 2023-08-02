public class peakOfTheMountain {

  public static void main(String[] args) {
    int[] nums = { 1, 2, 3, 4, 5, 3, 1 };
    int ans = peakOfTheMountainArr(nums);
    System.out.println(ans);
  }

  public static int peakOfTheMountainArr(int[] arr) {
    int start = 0;
    int end = arr.length - 1;

    while (start <= end) {
      int mid = start + (end - start) / 2;

      if (arr[mid] > arr[mid + 1]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }

      if (start == end) {
        return arr[start];
      }
    }
    return -1;
  }
}
