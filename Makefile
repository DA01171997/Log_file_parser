#File: Makefile
#Group Charlie's Members: Abhyuday Vatsavai, Duy Do, Hasibullah Ziai, Jason Lieu
#Course: CPSC 254 Tue Thr 6:00
#Start Date: 11/15/2017 -Duy Do
#Date last Modified: 11/22/2017 5:47PM -Duy Do 
default: main.exe

Line.o: Line.cpp
	g++ -c Line.cpp
main.o: main.cpp Line.o
	g++ -c main.cpp
main.exe: main.o Line.o
	g++ main.o Line.o -o main.exe
clean:
	rm *.o *.exe 

