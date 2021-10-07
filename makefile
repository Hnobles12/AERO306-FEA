CXX = g++
CXXFLAGS = -std=c++11
OUTFNAME = FEA.out


all:
	$(CXX) -o ./bin/$(OUTFNAME) ./src/*.cpp  $(CXXFLAGS)
	
run: all
	./bin/$(OUTFNAME)

clean:
	rm -f ./bin/*