public class fibonacci {

  public static void main(String[] args) {
    int n = 15;
    // System.out.println(fib(n));
    System.out.println(fibo(n));
  }

  public static int fib(int n) {
    if (n == 0 || n == 1) return n;
    int[] dp = new int[n + 1];
    dp[0] = 0; // base case
    dp[1] = 1; // base case
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2]; // recurrence relation
    }
    return dp[n];
  }

  public static int fibo(int n) {
    int prev2 = 0;
    int prev1 = 1;
    int curr = 0;

    for (int i = 2; i <= n; i++) {
      curr = prev1 + prev2;
      prev2 = prev1;
      prev1 = curr;
    }

    return curr;
  }
}
