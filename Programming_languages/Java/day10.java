public class ToBinary {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        
        String bin = Integer.toBinaryString(n);
        int max = 1;
        int cont = 0;
        for(int i = 0; i < bin.length(); ++i){
            char c = bin.charAt(i);
            if(c == '1'){
                cont += 1;
            }else{
                cont = 0;
            }
            if(cont >= max){
                max = cont;
            }
        }
        System.out.println(max);
        scanner.close();
    }
}
