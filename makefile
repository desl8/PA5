treasure_hunt: board.o cell.o empty_cell.o treasure_cell.o trap_cell.o helpers.o
	g++ -o treasure_hunt board.o cell.o empty_cell.o treasure_cell.o trap_cell.o helpers.o -g
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
helpers.o: helpers.cpp cell.h board.h
	g++ -c helpers.cpp -g
clean:
	rm *.o treasure_hunt