CXX = g++
CXXFLAGS = -std=c++11 -g
OUTFNAME = FEA.out
INCLUDEPATH = ./include/
DEFINPFILE  = ./data/input.txt
DEFOUTFILE = ./data/output.txt


all: clean
	mkdir bin
	$(CXX) -I$(INCLUDEPATH) -o ./bin/$(OUTFNAME) ./src/*.cpp ./main/main.cpp  $(CXXFLAGS)
	
run: all
	./bin/$(OUTFNAME) $(DEFINPFILE) $(DEFOUTFILE) 1

clean:
	rm -rf ./bin
	rm -rf ./dist

run_test:
	$(CXX) -I$(INCLUDEPATH) -o ./bin/test ./src/*.cpp ./test/test.cpp $(CXXFLAGS)
	./bin/test

compress: clean 
	mkdir dist
	zip -r ./dist/AERO306_Nobles_FEA.zip .