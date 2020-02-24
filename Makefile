compilec:
	clear
	make compile

compiler:
	make compile run

compile:
	g++ -c src/class/*.cpp
	g++ *.o -o main.exe

test:
	./testRunner.sh

run:
	./main.exe src/storage/users.txt src/storage/items.txt src/storage/transactions.txt

user:
	g++ src/class/User.cpp 

item:
	g++ src/class/Item.cpp 