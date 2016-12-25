#include <iostream>

int main()
{
    int a, b, aux;
    std::cin >> a >> b;

    if(a > b){
        aux = (a%b);
    }else{
        aux = (b%a);
    }

    if(aux == 0){
        std::cout << "Sao Multiplos\n";
    }else{
        std::cout << "Nao sao Multiplos\n";
    }
    return 0;
}
