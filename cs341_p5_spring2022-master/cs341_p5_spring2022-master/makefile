bruh2: tree.h tree.inl treenode.h driver.cpp licorIce.o
	g++ -o bruh2 driver.cpp licorIce.o

licorIce.o: licorIce.cpp licorIce.h
	g++  -c licorIce.cpp licorIce.h



valgrind:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt --leak-check=full ./bruh2








clean:
	rm -rf *.o bruh2