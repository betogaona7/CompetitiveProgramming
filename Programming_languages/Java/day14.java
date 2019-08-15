class Difference {
  	private int[] elements;
  	public int maximumDifference;

    Difference(int [] elements){
        this.elements = elements;
    }
    
	void computeDifference(){
        Arrays.sort(elements);
        int prev = elements[0];
        this.maximumDifference = 0;
        for(int i = 1; i < elements.length; ++i){
            if(Math.abs(elements[i] - prev) > this.maximumDifference){
                this.maximumDifference = Math.abs(elements[i]-prev);
            } 
        }   
    }
}