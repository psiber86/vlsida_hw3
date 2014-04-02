CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++0x

all: main.cpp 
	$(CC) $(CFLAGS) -O3 main.cpp -o cc 

clean:
	rm -f *_apr *~
