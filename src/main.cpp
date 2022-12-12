#include "raylib.h"
#include "header.h"

#include <iostream>

int main(int argc, char** argv) {
	int x = 5; int y = 10;

	Pong::Class object;
	int z = object.foo(x, y);

	std::cout << z << "\n";

	return 0;
}
