CXX = g++

bin/main.out: bin/bubble-sort.o bin/main.o
	$(CXX) $^ -o $@

bin/main.o: main.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

bin/bubble-sort.o: bubble-sort.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

clean:
	rm -rf bin *.o main.out
