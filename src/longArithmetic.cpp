#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "longArithmetic.h"

longNumber::longNumber(int n) {
	if (n < base)
		num.push_back(n);
	else 
		while (n) {
			num.push_back(n % base);
			n /= base;
		}
}

std::string& operator>>(std::string& in, longNumber& obj) {
	obj.num.clear();
	std::string str;
	str=in;
	int i = 0;
	int size = (int)str.size();
	while (str[i] == '0')
		++i;
	if (i == size) {
		str = '0';
		size = 1;
	}
	else {
		str = str.substr(i);
		size = (int)str.size();
	}
	
	for (i = size; i > 0; i -= numOfZerosInBase) {
		if (i < numOfZerosInBase)
			obj.num.push_back(atoi(str.substr(0, i).c_str()));
		else obj.num.push_back(atoi(str.substr(i - numOfZerosInBase, numOfZerosInBase).c_str()));
	}
	return in;
}


void longNumber::delLeadingZeros() {
	if (num.size() != 1) {
		for (int i = (int)num.size() - 1; i > 0; --i) {
			if (num[i] != 0)
				break;
			num.pop_back();
		}
	}
}

std::string& operator<<(std::string& s, longNumber obj) {
	int size = (int)obj.num.size();
	s.clear();
	char buf[1024];
	sprintf(buf, "%d", obj.num[size - 1]);
	s+=std::string(buf);
	for (int i = size - 2; i >= 0; --i) {
		sprintf(buf,"%04d", obj.num[i]);
		s+=std::string(buf);
	}

	return s;
}

longNumber longNumber::operator+(const longNumber& right) const {
	int k = 0;
	int l, r;
	int sizeLeft = (int)num.size();
	int sizeRight = (int)right.num.size();
	int maxSize = std::max(sizeLeft, sizeRight);
	longNumber res;

	for (int i = 0; i < maxSize; ++i) {
		if (i < sizeLeft)
			l = num[i];
		else
			l = 0;
		if (i < sizeRight)
			r = right.num[i];
		else
			r = 0;
		res.num.push_back((l + r + k) % base);
		k = (l + r + k) / base;
	}
	if (k) res.num.push_back(k);
	return res;
}

longNumber longNumber::operator-(const longNumber& right) const {
	int k = 0;
	int l, r;
	int sizeLeft = (int)num.size();
	int sizeRight = (int)right.num.size();
	longNumber res;
	for (int i = 0; i < sizeLeft; ++i) {
		l = num[i];
		if (i < sizeRight) 
			r = right.num[i];
		else
			r = 0;
		int add = l - r + k;
		if (add < 0) {
			add += base;
			k = -1;
		}
		else
			k = 0;
		res.num.push_back(add % base);
		
	}
	res.delLeadingZeros();
	return res;
}

longNumber longNumber::operator*(const longNumber& right) const {
	int k = 0;
	int sizeLeft = (int)num.size();
	int sizeRight = (int)right.num.size();
	longNumber res;
	res.num.resize(sizeLeft + sizeRight);
	for (int i = 0; i < sizeLeft; ++i) {
		if (num[i] == 0) continue;
		k = 0;
		for (int j = 0; j < sizeRight; ++j) {
			res.num[i + j] += num[i] * right.num[j] + k;
			k = res.num[i + j] / base;
			res.num[i + j] %= base;
		}
		if (k > 0) res.num[i + sizeRight] = k;
	}
	res.delLeadingZeros();
	return res;
}

longNumber longNumber::operator/(const longNumber& right) const {
	int norm = base / (right.num.back() + 1);

	longNumber a = *this * norm;
	longNumber b = right * norm;
	longNumber res, r;
	int size_a = (int)a.num.size();
	int size_b = (int)b.num.size();

	res.num.resize(size_a);

	for (int i = size_a - 1; i >= 0; --i) {
		r = r * base + a.num[i];
		int s1;
		if ((int)r.num.size() > size_b)
			s1 = r.num[size_b];
		else
			s1 = 0;
		int s2;
		if ((int)r.num.size() > size_b - 1)
			s2 = r.num[size_b - 1];
		else
			s2 = 0;
		int d = (s1 * base + s2) / b.num.back();

		longNumber tmp = b * d;
		while (tmp.cmp(r) > 0) {
			tmp = tmp - b;
			--d;
		}

		r = r - tmp;
		res.num[i] = d;
	}

	res.delLeadingZeros();
	return res;
}

longNumber longNumber::operator^(const longNumber& right) const {
	/*longNumber res = 1;
	longNumber a = *this;
	longNumber n = right;
	while (n > 0) {
		if (n.num[0] & 1)
			res = res * a;
		a = a * a;
		n = n / 2;
	}*/
	return binPow(right);
}

longNumber longNumber::binPow(const longNumber& right) const{
	if (right == 0) 
		return 1;
	if (right.num[0] & 1)
		return *this * binPow(right - 1);
	else {
		longNumber c = binPow(right / 2);
		return c * c;
	}
}

bool longNumber::operator==(const longNumber& right) const {
	int sizeLeft = (int)num.size();
	int sizeRight = (int)right.num.size(), i;
	if (sizeLeft != sizeRight)
		return false;
	for (i = 0; i < sizeLeft; ++i)
		if (num[i] != right.num[i]) 
			return false;
	return true;
}

int longNumber::cmp(longNumber& obj) const{
	int sizeLeft = (int)num.size();
	int sizeRight = (int)obj.num.size();
	if (sizeLeft != sizeRight)
		return sizeLeft > sizeRight ? 1 : -1;
	for (int i = sizeLeft - 1; i >= 0; --i)
		if (num[i] != obj.num[i])
			return num[i] > obj.num[i] ? 1 : -1;
	return 0;
}
