
CPP = g++
CFLAGS = -Wall -Wextra -Werror


nnList: nnList.cpp
	$(CPP) $(CFLAGS) -o nnList nnList.cpp

clean:
	rm -f *.o;
	rm -f nnList;
	rm -f *~;
