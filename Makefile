#File: Makefile
#Group Charlie's Members: Abhyuday Vatsavai, Duy Do, Hasibullah Ziai, Jason Lieu
#Course: CPSC 254 Tue Thr 6:00
#Start Date: 11/15/2017 -Duy Do
#Date last Modified: 11/16/2017 12:03PM -Duy Do 
default: main.exe

main.o: main.cpp
	g++ -c main.cpp
main.exe: main.o
	g++ main.o -o main.exe
clean:
	rm -f main.o 

