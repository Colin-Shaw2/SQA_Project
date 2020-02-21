compilec:
	clear
	make compile

compiler:
	make compile run

compile:
	g++ -c src/class/main.cpp src/class/Admin.cpp src/class/BuyStandard.cpp src/class/FullStandard.cpp src/class/Item.cpp src/class/SellStandard.cpp src/class/TransactionCodeMaker.cpp src/class/TransactionEnums.h src/class/User.cpp
	g++ *.o -o main.exe

run:
	./main.exe src/storage/items.txt src/storage/users.txt src/storage/transactions.txt

user:
	g++ src/class/User.cpp 

item:
	g++ src/class/Item.cpp 