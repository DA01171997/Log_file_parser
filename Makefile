#File: Makefile
#Author: Duy Do
#Author's email: duy.ado@fullerton.edu
#Author's Github: https://github.com/DA01171997
#Course: CPSC 254 Tue Thr 6:00
#Start Date: 11/15/2017 
#Date last Modified: 11/15/2017 11:32PM 
default: main.exe

main.o: main.cpp
	g++ -c main.cpp
main.exe: main.o
	g++ main.o -o main.exe
clean:
	rm -f main.o 

