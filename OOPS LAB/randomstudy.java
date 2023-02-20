import java.util.*;

public class randomstudy {

    static boolean palindrome(String s) {
        int mid = s.length() / 2;
        for (int i = 0; i < mid; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    void stringstudy(){
        String w1 = "Welcome";
        String w2 = "Welcome";
        
    }

    public static void main(String[] args) {
        String s,result ="";
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a String : ");
        s = sc.nextLine();
        sc.close();
        StringTokenizer strtok = new StringTokenizer(s);
        while(strtok.hasMoreTokens()){
            String curr = strtok.nextToken();
            // System.out.println(curr);
            if(palindrome(curr) && curr.length()!=1){
                result=result.concat(" *");
            }
            else{
                result=result.concat(curr + " ");
            }
        }
        System.out.println(result);
    }
}
