all: integral run

integral:
	/opt/nec/ve/bin/nc++ -o $@ -Iinclude src/main.cpp

run:
	./integral 1 3000 4000
