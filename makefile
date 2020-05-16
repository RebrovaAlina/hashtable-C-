CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage

all: utest
utest: hashtable.o utest.o
        g++ -o utest hashtable.o utest.o ${CFLAGS}
utest.o: utest.cpp
  g++ -c utest.cpp ${CFLAGS}
hashtable.o: hashtable.cpp
  g++ -c hashtable.cpp ${CFLAGS}
clean:
  rm -rf *.o utest
