class Student extends Person{
	int[] testScores;

    Student(String firstName, String lastName, int id, int[] scores){
        super(firstName, lastName, id);
        this.testScores = scores;
    }
   

    char calculate(){
        int sum = 0;
        for(int i = 0; i < testScores.length; ++i){
            sum += testScores[i];
        }
        float result = sum/testScores.length;
        if(result >= 90 && result <= 100){
            return 'O';
        }else if(result >= 80 && result < 90){
            return 'E';
        }else if(result >= 70 && result < 80){
            return 'A';
        }else if(result >= 55 && result < 70){
            return 'P';
        }else if(result >= 40 && result < 55){
            return 'D';
        }else{
            return 'T';
        }
    }
}