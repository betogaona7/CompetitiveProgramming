#include <stdio.h>
#include <iostream>


int main(){

    float a,b,c,d,e,average;

    std::cin >> a >> b >> c >> d;

    average = (a*2 + b*3 + c*4 + d*1)/(10.0);
    printf("Media: %.1f\n", average);

    if(average >= 5.0 && average < 7.0){
        std::cout << "Aluno em exame.\n";
        std::cin >> e;
        printf("Nota do exame: %.1f\n", e);
        if((average + e)/2.0 >= 5.0){
           	std::cout << "Aluno aprovado.\n";	
        }
        else{
            std::cout << "Aluno reprovado.\n";
        }
        printf("Media final: %.1f\n", (average + e)/2);
    }else{
    	 if(average >= 7.0){
            std::cout << "Aluno aprovado.\n";
    	 }
		else{
            std::cout << "Aluno reprovado.\n";
		}
    }
    return 0;
}