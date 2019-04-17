src = $(shell ls *.cpp)


objs = $(src:%.cpp=%)

all:$(objs)

%:%.cpp
	g++ -o $@ $^

.PHONY: clean


clean:
	rm $(objs)

