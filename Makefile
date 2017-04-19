CPPFLAGS=-std=c++11 -Wall -Werror

all: tool naive greedy ampl dynamic
	@echo Compilation succesful!

tool: tool.cpp
	g++ tool.cpp $(CPPFLAGS) -o tool

naive: naive.cpp
	g++ naive.cpp $(CPPFLAGS) -o naive

greedy: greedy.cpp
	g++ greedy.cpp $(CPPFLAGS) -o greedy

ampl: ampl.cpp
	g++ ampl.cpp $(CPPFLAGS) -o ampl

dynamic: dynamic.cpp
	g++ dynamic.cpp $(CPPFLAGS) -o dynamic

clean:
	rm -f tool naive greedy *.out

examples: naive

