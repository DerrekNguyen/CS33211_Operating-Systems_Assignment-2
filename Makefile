all: build
	./banker

build: clean
	g++ ./code/banker.cpp -o banker

clean:
	rm -f banker