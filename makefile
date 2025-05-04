treasure_hunt: main.o board.o cell.o emptycell.o treasurecell.o trapcell.o helpers.o
	g++ -o treasure_hunt main.o board.o cell.o emptycell.o treasurecell.o trapcell.o helpers.o -g
main.o: main.cpp
	g++ -c main.cpp -g
board.o: board.cpp board.h cell.h emptycell.h treasurecell.h trapcell.h
	g++ -c board.cpp -g
cell.o: cell.cpp cell.h
	g++ -c cell.cpp -g
emptycell.o: emptycell.cpp emptycell.h cell.h
	g++ -c emptycell.cpp -g
treasurecell.o: treasurecell.cpp treasurecell.h cell.h
	g++ -c treasurecell.cpp -g
trapcell.o: trapcell.cpp trapcell.h cell.h
	g++ -c trapcell.cpp -g
helpers.o: helpers.cpp helpers.h cell.h board.h
	g++ -c helpers.cpp -g
clean:
	rm *.o treasure_hunt