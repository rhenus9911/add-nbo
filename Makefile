#Makefile
all: add-nbo

add-nbo: thousand.bin five-hundred.bin add-nbo.cpp
	g++ -o add-nbo add-nbo.cpp

thousand.bin: echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin

five-hundred.bin: echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin


