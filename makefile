target: upload main.o concreate.o getSetting.o switch_oper.o
	g++ -o upload main.o concreate.o getSetting.o switch_oper.o

main.o: main.cpp
	g++ -c main.cpp

concreate.o: concreate.cpp concreate.hpp
	g++ -c concreate.cpp

getSetting.o: getSetting.cpp getSetting.hpp
	g++ -c getSetting.cpp

switch_oper.o: switch_oper.cpp switch_oper.hpp
	g++ -c switch_oper.cpp

clean:
	rm *.o
