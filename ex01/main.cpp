#include <iostream>
#include <time.h>
#include <cstdlib>

struct Data {
	std::string s1;
	int 		n;
	std::string s2;
};

void* serialize(void) {
	char *ser = new char[20];
	char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (int i = 0; i < 8; ++i) {
		ser[i] = chars[rand() % 62];
	}
	*reinterpret_cast<int *>(ser + 8) = rand();
	for (int i = 12; i < 20; ++i) {
		ser[i] = chars[rand() % 62];
	}
	return ser;
}

Data * deserialize(void *ptr) {
	Data *data = new Data();
	char *ser = static_cast<char *>(ptr);
	data->s1.assign(ser, 8);
	data->s1 += '\0';
	data->n = *reinterpret_cast<int *>(ser + 8);
	data->s2.assign(ser + 12, 8);
	data->s2 += '\0';
	return data;
}

void printSer(char *ser) {
	std::cout << "Ser:" << std::endl;
	for (int i = 0; i < 8; ++i) {
		std::cout << ser[i];
	}
	std::cout << std::endl;
	std::cout << (*reinterpret_cast<int *>(ser + 8));
	std::cout << std::endl;
	for (int i = 12; i < 20; ++i) {
		std::cout << ser[i];
	}
	std::cout << std::endl;
}

int main() {
	Data *data;
	char *ser;

	std::srand(time(NULL));
	ser = static_cast<char *>(serialize());
	printSer(ser);
	data = deserialize(ser);
	std::cout << "Dser:" << std::endl;
	std::cout << data->s1 << std::endl << data->n << std::endl << data->s2 << std::endl;
	return 0;
}
