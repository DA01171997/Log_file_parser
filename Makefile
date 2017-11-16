default: main.exe

main.o: main.cpp
	g++ -c main.cpp
main.exe: main.o
	g++ main.o -o main.exe
clean:
	rm -f main.o 

