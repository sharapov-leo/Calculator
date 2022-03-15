#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class longNumber {
	std::vector<int> num;
public:
	longNumber() {}
	longNumber(int n);

	longNumber operator+(const longNumber& right) const;
	longNumber operator-(const longNumber& right) const;
	longNumber operator*(const longNumber& right) const;
	longNumber operator/(const longNumber& right) const;
	longNumber operator^(const longNumber& right) const;

	friend std::string& operator>>(std::string& in, longNumber& obj);
	friend std::string& operator<<(std::string& out, longNumber obj);

	bool operator==(const longNumber& right) const;
	int cmp(longNumber& obj) const;
	void delLeadingZeros();
	longNumber binPow(const longNumber& right) const;
};

const int base = 10000;
const int numOfZerosInBase = 4;

std::string& operator>>(std::string& in, longNumber& obj);
std::string& operator<<(std::string& s, longNumber obj);
