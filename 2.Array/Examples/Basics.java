import java.util.Arrays;
import java.util.Scanner;

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
    // for (int i = 0; i < numbers.length; ++i) {
    //   System.out.println("Element at index " + i + " : " + numbers[i]);
    // }

    // 7 take input from user
    Scanner sc = new Scanner(System.in);
    int[] numbers2 = new int[5];

    // for (int i = 0; i < numbers2.length; ++i) {
    //   System.out.print("Enter a number: ");
    //   numbers2[i] = sc.nextInt();
    // }
    // sc.close();
    // 8. Print the array
    // for (int i = 0; i < numbers2.length; ++i) {
    //   System.out.println("Element at index " + i + " : " + numbers2[i]);
    // }

    // FOR EACH LOOP
    // for (int number : numbers2) {
    //   System.out.println(number);
    // }

    // ARRAY PRINT
    // System.out.println(Arrays.toString(numbers2));

    // Array of Objects
    String[] names = new String[5];

    // for (int i = 0; i < names.length; ++i) {
    //   System.out.print("Enter a name: ");
    //   names[i] = sc.next();
    // }
    // sc.close();

    // for (String name : names) {
    //   System.out.println(name);
    // }

    int[] arr = { 1, 2, 3, 4, 5 };
    change(arr);
    // System.out.println(Arrays.toString(arr));

    // 2D Array
    int[][] arr2d = new int[3][3];

    for (int i = 0; i < arr2d.length; ++i) {
      for (int j = 0; j < arr2d[i].length; ++j) {
        arr2d[i][j] = i + j;
      }
    }

    for (int[] row : arr2d) {
      System.out.println(Arrays.toString(row));
    }

    // Jagged Array
    int[][] jagged = {
        {1,2,3,4},
        {1,2,3},
        {1,2},
        {1}
    };

    for(int row = 0; row < jagged.length; ++row) {
      for(int col = 0; col < jagged[row].length; ++col) {
        System.out.print(jagged[row][col] + " ");
      }
      System.out.println();
    }
  }

  static void change(int[] arr) {
    arr[0] = 99;
  }
}
