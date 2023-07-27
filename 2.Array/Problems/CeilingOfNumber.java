public class CeilingOfNumber {
    public static void main(String[] args) {
        int[] numbers = { 10, 20, 30, 40, 50 };
        int target = 25;

        System.out.println("Ceiling of " + target + " is: " + ceiling(numbers, target));
    }

    private static int ceiling(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length-1;
        int mid = start - (start-end)/2;

        while (start <= end) {
            if (numbers[mid] == target ) {
                return numbers[mid];
            }else if (numbers[mid] > target) {
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            mid = start - (start-end)/2;
        }

        return numbers[start];
    }
}
