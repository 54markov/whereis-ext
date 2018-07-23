all: whereis-ext

whereis-ext: search-model search-controller search-view observer
	g++ -g -Wall -O2 -o whereis-ext main.cpp search-model.o search-controller.o search-view.o observer.o -std=c++17

search-model:
	g++ -g -Wall -c -o search-model.o search-model.cpp -std=c++17

search-controller:
	g++ -g -Wall -c -o search-controller.o search-controller.cpp -std=c++17

search-view:
	g++ -g -Wall -c -o search-view.o search-view.cpp -std=c++17

observer:
	g++ -g -Wall -c -o observer.o observer.cpp -std=c++17

clean:
	rm -f *.o whereis-ext
