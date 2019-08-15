public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String S = in.next();

        try{
            int myInt = Integer.parseInt(S);
            System.out.println(myInt);
        }catch(Exception e){
            System.out.println("Bad String");
        }

    }
}