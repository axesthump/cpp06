#include <iostream>
#include <stdexcept>
#include <iomanip>

void convert(std::string const& ar) {
	{
		std::cout << "char: ";
		try {
			int res = std::stoi(ar);
			if (res >= -128 && res <= 127) {
				if (!isprint(res)) {
					std::cout << "Non displayable\n";
				} else {
					std::cout << "'" << static_cast<char>(res) << "'\n";
				}
			} else {
				std::cout << "impossible\n";
			}
		} catch (std::overflow_error& e) {
			std::cout << "impossible\n";
		}
	}
	{
		std::cout << "int: ";
		try {
			std::cout << std::stoi(ar) << std::endl;
		} catch (std::overflow_error& e) {
			std::cout << "impossible\n";
		}
	}
	{
		std::cout << "float: ";
		try {
			if (ar.find(".")) {
				std::cout << std::stof(ar) << "f\n";
			} else {
				std::cout << std::fixed << std::setprecision(1) << std::stof(ar) << "f\n";
			}
		} catch (std::overflow_error& e) {
			std::cout << "impossible\n";
		}
	}
	{
		std::cout << "double: ";
		try {
			if (ar.find(".")) {
				std::cout << std::stod(ar) << std::endl;
			} else {
				std::cout << std::fixed << std::setprecision(1) << std::stod(ar) << std::endl;
			}
		} catch (std::out_of_range &e) {
			std::cout << "impossible\n";
		}
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Invalid number of arguments\n";
	} else {
		std::string ar = argv[1];
		size_t none = std::string::npos;
		if (ar.length() == 1 && isprint(ar[0]) && !isdigit(ar[0])) {
			std::cout << "char: " << "'" << ar[0] << "'\n";
			std::cout << "int: " << static_cast<int>(ar[0]) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1)
					  << static_cast<float>(ar[0]) << "f\n";
			std::cout << "double: " << std::fixed << std::setprecision(1)
					  << static_cast<double>(ar[0]) << "\n";
		}
		else if (ar.find("inf") != none || ar.find("nan") != none) {
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: " << std::stof(ar) << "f\n";
			std::cout << "double: " << std::stod(ar) << std::endl;
		} else {
			convert(ar);
		}
	}
	return 0;
}
