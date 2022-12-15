#include <iostream>
#include "engine.h"
#include "Subject.h"



int main() {
	Engine engine;

	Subject subj;

	Wrapper wrap1(&subj, &Subject::sum, { {"arg1", 0}, {"arg2", 0} });
	Wrapper wrap2(&subj, &Subject::mult, { {"arg1", 0}, {"arg2", 0}, {"arg3", 0} });
	Wrapper wrap3(&subj, &Subject::substraction, { {"arg1", 0},{"arg2", 0},{"arg3", 0},{"arg4", 0} });

	try {
		engine.registerCommand(&wrap1, "sum");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << engine.execute("sum", { {"arg1", 1},{"arg2", 2} }) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << engine.execute("sum", { {"arg1", 3},{"arg2", 2} }) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		engine.registerCommand(&wrap2, "mult");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << engine.execute("mult", { {"arg1", 2},{"arg2", 3}, {"arg3", 4} }) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		engine.registerCommand(&wrap3, "substraction");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << engine.execute("substraction", { {"arg2", 1},{"arg1", 2}, {"arg3", 3},{"arg4", 4} }) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}