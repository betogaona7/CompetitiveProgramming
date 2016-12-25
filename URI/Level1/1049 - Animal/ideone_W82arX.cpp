#include <iostream>


int main() {
	std::string word1, word2, word3;
	std:: cin>> word1 >> word2 >> word3;
	
	if(word1 == "vertebrado"){
		if(word2 == "ave"){
			if(word3 == "carnivoro"){
				std::cout << "aguia\n";
			}else if(word3 == "onivoro"){
				std::cout << "pomba\n";
			}
		}else if (word2=="mamifero"){
			if(word3 == "onivoro"){
				std::cout << "homem\n";
			}else if(word3 == "herbivoro"){
				std::cout << "vaca\n";	
			}
		}
	}else if(word1 == "invertebrado"){
		if(word2 == "inseto"){
			if(word3 == "hematofago"){
				std::cout << "pulga\n";
			}else if(word3 == "herbivoro"){
				std::cout << "lagarta\n";
			}
		}else if(word2 == "anelideo"){
			if(word3 == "hematofago"){
				std::cout << "sanguessuga\n";
			}else if (word3 == "onivoro"){
				std::cout << "minhoca\n";
			}
		}
	}
	return 0;
}