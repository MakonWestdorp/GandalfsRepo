DevTesting: testing.cpp UnitTest.cpp Shop.cpp Game.cpp Location.cpp BaseItem.cpp AttackItem.cpp BuffItem.cpp Entity.cpp Enemy.cpp Arena.cpp Forest.cpp Town.cpp Player.cpp Boss.cpp
	clang++ -Wall -std=c++11 testing.cpp UnitTest.cpp Shop.cpp Game.cpp Location.cpp BaseItem.cpp AttackItem.cpp BuffItem.cpp Entity.cpp Enemy.cpp Arena.cpp Forest.cpp Town.cpp Player.cpp Boss.cpp -o DevTesting
	./DevTesting
Game: main.cpp Boss.cpp Shop.cpp Game.cpp Location.cpp BaseItem.cpp AttackItem.cpp BuffItem.cpp Entity.cpp Enemy.cpp Arena.cpp Forest.cpp Town.cpp Player.cpp
	clang++ -Wall -std=c++11 main.cpp Boss.cpp Shop.cpp Game.cpp Location.cpp BaseItem.cpp AttackItem.cpp BuffItem.cpp Entity.cpp Enemy.cpp Arena.cpp Forest.cpp Town.cpp Player.cpp -o Game
	./Game
all: DevTesting Game
clear: rm -f Game DevTesting

