#File: build.sh
#Group Charlie's Members: Abhyuday Vatsavai, Duy Do, Hasibullah Ziai, Jason Lieu
#Course: CPSC 254 Tue Thr 6:00
#Start Date: 11/16/2017 12:03AM -Duy Do 
#Date last Modified: 11/16/2017 12:21AM -Duy Do 
echo "***Remove old binary files.***"
rm *.o
rm *.exe

echo "***Run make.***"
make

echo "***Run main.exe.***"
./main.exe

echo "***Build script has terminated.***"