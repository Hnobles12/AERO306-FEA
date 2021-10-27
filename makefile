CXX = g++
CXXFLAGS = -std=c++11 -g
OUTFNAME = FEA.out
INCLUDEPATH = ./include/


all:
	$(CXX) -I$(INCLUDEPATH) -o ./bin/$(OUTFNAME) ./src/*.cpp ./main/main.cpp  $(CXXFLAGS)
	
run: all
	./bin/$(OUTFNAME) ./data/data.txt ./data/output.txt 1

clean:
	rm -f ./bin/*
	rm -rf ./dist

run_test:
	$(CXX) -I$(INCLUDEPATH) -o ./bin/test ./src/*.cpp ./test/test.cpp $(CXXFLAGS)
	./bin/test

compress: clean 
	mkdir dist
	zip -r ./dist/AERO306_Nobles_FEA.zip .