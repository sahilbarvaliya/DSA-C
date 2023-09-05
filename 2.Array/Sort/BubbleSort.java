public class BubbleSort {

  // Sinking Sort or Exchange Sort
  // Time Complexity: O(n^2)
  // Space Complexity: O(1)

  public static void main(String[] args) {
    int[] arr = { 5, 4, 3, 2, 1 };
    bubbleSort(arr);
    for (int i : arr) {
      System.out.print(i + " ");
    }
  }

  public static void bubbleSort(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n; i++) {
      boolean swapped = false;
      for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr, j, j + 1);
          swapped = true;
        }
      }
      if (!swapped) break;
    }
  }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    
    }
}
