CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -I/usr/include/opencv4
LDFLAGS = -lopencv_core -lopencv_highgui

.PHONY: all clean

all: secuencial

secuencial: secuencial.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f secuencial
