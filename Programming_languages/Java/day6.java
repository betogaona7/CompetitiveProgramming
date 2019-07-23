public class Review{
    
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int test = scan.nextInt();
        while(test >= 0){
            String phrase = scan.nextLine();
            char[] arr = phrase.toCharArray();

            String even = "";
            String odd = "";
            for(int i = 0; i < phrase.length(); ++i){
                if(i%2 == 0){
                    even += arr[i];
                }else{
                    odd += arr[i];
                }
            }
            if(phrase.length() != 0){ 
                System.out.println(even + " " + odd);
            }
            test -= 1;
        }    
       
    }
}