public class FlooringOfNumber {
    public static void main(String[] args) {
        int[] numbers = { 10, 20, 30, 40, 50 };
        int target = 5;

        System.out.println("flooring of " + target + " is: " + flooring(numbers, target));
    }

    private static int flooring(int[] numbers, int target) {

        if(target < numbers[0]){
            return -1;
        }

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

        return numbers[start-1];
    }
}
