pepitoperez : album
	./album
album : album.cpp
	c++ album.cpp -o album

clean:
	rm album 
