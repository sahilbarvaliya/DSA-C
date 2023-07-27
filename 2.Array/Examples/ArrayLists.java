import java.util.ArrayList;

public class ArrayLists {
    public static void main(String[] args) {
        
        // Syntex
        ArrayList<Integer> numbers = new ArrayList<>();

        // Add
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        
        // Get
        System.out.println("get: "+numbers.get(0));
        
        // Set
        numbers.set(1, 100);
        numbers.add(30);
        
        // Remove
        numbers.remove(numbers.size() - 1);
        numbers.remove(0);

        // Print
        System.out.println("print: "+numbers);

        // Size
        System.out.println("size: " +numbers.size());

        // Loop
        for (int i = 0; i < numbers.size(); ++i) {
            System.out.print(" "+numbers.get(i));
        }
        System.out.println();
        // Contains
        System.out.println("Contains: " + numbers.contains(10));

        // Index of
        System.out.println("Index of: " + numbers.indexOf(100));

        // Clear
        numbers.clear();

        // Is Empty
        System.out.println("Empty: " + numbers.isEmpty());


    }
}
