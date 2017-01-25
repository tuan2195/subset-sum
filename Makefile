CPPFLAGS=-std=c++11 -Wall -Werror

all: tool naive
	@echo Compilation succesful!

tool:
	g++ tool.cpp $(CPPFLAGS) -o tool

naive:
	g++ naive.cpp $(CPPFLAGS) -o naive

clean:
	rm -f tool naive *.out

examples: naive

