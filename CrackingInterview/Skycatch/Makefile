
output: problema1.o problema2.o 
	g++ problema1.o -o problema1
	g++ problema2.o -o problema2
	rm *.o

problema1.o: problema1.cpp
	g++ -c problema1.cpp

problema2.o: problema2.cpp
	g++ -c problema2.cpp

test:
	./problema1 < test1.txt
	./problema2 < test2.txt

