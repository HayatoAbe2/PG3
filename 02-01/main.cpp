#include <stdio.h>
#include <Windows.h>

template <typename Type>

Type Min(Type a, Type b) {
	if (a - b <= 0) { return a; }
	return b;
}

int main() {
	SetConsoleOutputCP(65001);

	int a = 3; int b = 2;
	float c = 6.1f; float d = 8.75f;
	double e = 12.805; double f = 30.5;


	printf("int    : %d\nfloat  : %.3f\ndouble : %.3lf\n",
		Min<int>(a,b),Min<float>(c,d),Min<double>(e,f));
	
	return 0;
}