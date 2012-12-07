
CPP = g++
CFLAGS = -Wall -Wextra -Werror

nnList: nnList.cpp
	$(CPP) $(CFLAGS) -o nnList nnList.cpp
	
map_test: nnList_mapTime.cpp
	$(CPP) $(CFLAGS) -o map_test nnList_mapTime.cpp
	
list_test: nnList_listTime.cpp
	$(CPP) $(CFLAGS) -o list_test nnList_listTime.cpp

clean:
	rm -f *.o;
	rm -f nnList;
	rm -f *~;
