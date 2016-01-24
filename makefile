PROGS := Main 

all: $(PROGS)


Character.o: Character.cpp Character.hpp
	g++ -c -std=c++0x Character.cpp 

Room.o: Room.cpp Room.hpp
	g++ -c -std=c++0x  Room.cpp 

Aqua.o: Aqua.cpp Aqua.hpp
	g++ -c -std=c++0x  Aqua.cpp

Bar.o: Bar.cpp Bar.hpp
	g++ -c -std=c++0x  Bar.cpp

Cave.o: Cave.cpp Cave.hpp
	g++ -c -std=c++0x  Cave.cpp

Roof.o: Roof.cpp Roof.hpp
	g++ -c -std=c++0x  Roof.cpp

Slide.o: Slide.cpp Slide.hpp
	g++ -c -std=c++0x  Slide.cpp

Main: Character.o Room.o Aqua.o Bar.o Cave.o RegRoom.hpp Roof.o Slide.o Main.cpp
	g++ -g -O2 -std=c++0x Character.o Room.o Aqua.o Bar.o Cave.o RegRoom.hpp Roof.o Slide.o Main.cpp -o Main


clean:
	rm -f $(PROGS) *.o *~
