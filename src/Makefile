# Makefile For YSASA

all: install


install:
	g++ -O3 -o ../bin/YSASA `pwd`/YSASA.cpp -lboost_program_options -lboost_filesystem


debug:
	g++ -g -o ../bin/YSASA `pwd`/YSASA.cpp -lboost_program_options -lboost_filesystem


clean:
	rm ../bin/YSASA
