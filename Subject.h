#pragma once
class Subject {
public:
	Subject() {}
	~Subject() = default;

	int sum(int arg1, int arg2) {
		return arg1 + arg2;
	}

	int mult(int arg1, int arg2, int arg3) {
		return arg1 * arg2 * arg3;
	}

	int substraction(int arg1, int arg2, int arg3, int arg4) {
		return arg1 - arg2 - arg3 - arg4;
	}
};