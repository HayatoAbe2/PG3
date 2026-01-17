#include <thread>
#include <iostream>
#include <string>
#include <vector>

void Set(int i, std::vector<std::string>& vector) {
	vector[i - 1] = (std::string("thread " + std::to_string(i)));
}

int main() {
	std::vector<std::string> vec(3);

	std::thread th1(Set, 1, std::ref(vec));
	std::thread th2(Set, 2, std::ref(vec));
	std::thread th3(Set, 3, std::ref(vec));
	th1.join();
	th2.join();
	th3.join();

	for (auto& s : vec) {
		std::cout << s << std::endl;
	}

	return 0;
}