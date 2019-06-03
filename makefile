run: main.cpp NameSurferEntry.o NameSurferDataBase.o single_node.o linked_list.o
	g++ -std=c++11 main.cpp NameSurferEntry.o NameSurferDataBase.o single_node.o linked_list.o
NameSurferEntry.o:NameSurferEntry.cpp NameSurferEntry.h
	g++ -std=c++11 -c NameSurferEntry.cpp
linked_list.o:linked_list.cpp linked_list.h 
	g++ -std=c++11 -c linked_list.cpp
NameSurferDataBase.o:NameSurferDataBase.cpp NameSurferDataBase.h
	g++ -std=c++11 -c NameSurferDataBase.cpp
single_node.o:single_node.cpp single_node.h
	g++ -std=c++11 -c single_node.cpp

clean:
	rm *.o a.out
