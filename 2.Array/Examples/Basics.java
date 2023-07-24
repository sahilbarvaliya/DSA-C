public class Basics {

  public static void main(String[] args) {
    // 1. Declare an array of integers
    int[] numbers;

    // 2. Allocate memory for 5 integers
    numbers = new int[5];

    // 3. Initialize the first element
    numbers[0] = 10;

    // 4. Initialize the second element
    numbers[1] = 20;

    // 5. and so forth
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    // 6. Access elements of the array
    for (int i = 0; i < numbers.length; ++i) {
      System.out.println("Element at index " + i + " : " + numbers[i]);
    }
  }
}
