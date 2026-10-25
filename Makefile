CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic
TARGET = codon_database.run
OBJECTS = main.o CodonClass.o

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

main.o: main.cpp CodonClass.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

CodonClass.o: CodonClass.cpp CodonClass.h
	$(CXX) $(CXXFLAGS) -c CodonClass.cpp -o CodonClass.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)