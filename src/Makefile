# Makefile For YSASA

all: install


install:
	mkdir -p ../bin
	g++ -O3 -o ../bin/YSASA `pwd`/YSASA.cpp -lboost_program_options -lboost_filesystem


debug:
	mkdir -p ../bin
	g++ -g -o ../bin/YSASA `pwd`/YSASA.cpp -lboost_program_options -lboost_filesystem


clean:
	rm -f ../bin/YSASA
