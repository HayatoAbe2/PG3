#pragma once
template <typename Type1, typename Type2>

class Compare {
public:
	Compare(Type1 a, Type2 b) : a(a), b(b) {};

	Type1 Min() {
		if (a < static_cast<Type1>(b)) {
			return a; 
		} else {
			return static_cast<Type1>(b);
		}
	}
private:
	Type1 a;
	Type2 b;
};
