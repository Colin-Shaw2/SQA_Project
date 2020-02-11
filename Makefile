compile:
	g++ src/class/Admin.cpp src/class/BuyStandard.cpp src/class/FullStandard.cpp src/class/Item.cpp src/class/SellStandard.cpp src/class/TransactionCodeMaker.cpp src/class/TransactionEnums.h src/class/User.cpp 

user:
	g++ src/class/User.cpp 

item:
	g++ src/class/Item.cpp 