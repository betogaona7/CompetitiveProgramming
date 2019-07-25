class Dictionary{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Map<String, Integer> dir = new HashMap<String, Integer>();
        for(int i = 0; i < n; i++){
            String name = in.next();
            int phone = in.nextInt();
            dir.put(name, phone);
        }
        while(in.hasNext()){
            String s = in.next();
            if(dir.get(s) != null){
                System.out.println(s+"="+dir.get(s));
            }else{
                System.out.println("Not found");
            }
            
        }
        in.close();
    }
}