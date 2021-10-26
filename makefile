CXX = g++
CXXFLAGS = -std=c++11
OUTFNAME = FEA.out
INCLUDEPATH = ./include/


all:
	$(CXX) -I$(INCLUDEPATH) -o ./bin/$(OUTFNAME) ./src/*.cpp ./main/main.cpp  $(CXXFLAGS)
	
run: all
	./bin/$(OUTFNAME)

clean:
	rm -f ./bin/*

run_test:
	$(CXX) -I$(INCLUDEPATH) -o ./bin/test ./src/*.cpp ./test/test.cpp $(CXXFLAGS)
	./bin/test