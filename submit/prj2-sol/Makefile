all: nums seq-test

nums:
	g++ -o nums main.cc

seq-test: nums
	g++ -o nums seq-test.cc command.cc

clean:
	rm nums
