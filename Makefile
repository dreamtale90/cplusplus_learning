SOURCE = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %, $(SOURCE))

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = -lpthread

all:$(TARGETS)

$(TARGETS):%:%.cpp
	$(CXX) $< $(CXXFLAGS) $(LDFLAGS) -o $@

.PHONY:clean all

clean:
	@-rm -rf $(TARGETS)
