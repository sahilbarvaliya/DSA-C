public class SearchCharacterInString {

  public static void main(String[] args) {
    String str = "Hello World";
    char ch = 'o';
    System.out.println(
      "Character " +
      ch +
      " is present in string " +
      str +
      ": " +
      isPresent(str, ch)
    );
  }

  public static boolean isPresent(String str, char ch) {
    if (str == null || str.length() == 0) {
      return false;
    }

    for (int i = 0; i < str.length(); i++) {
      if (str.charAt(i) == ch) {
        return true;
      }
    }

    return false;
  }
}
