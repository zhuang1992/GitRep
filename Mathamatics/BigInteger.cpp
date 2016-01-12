#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
//#include <assert.h>
#include <algorithm>
using namespace std;
string oneDigitMulti(string first, char multi);
string multiply(string first, string second, int magnifier);
class BigInteger {
private:
	int* num;
	int digit;
	bool symbol;
	bool divideDone(int* first, int st, int fdigit, int *second, int sdigit) {
		BigInteger a(first + st, fdigit - st);
		BigInteger b(second, sdigit);
		return a < b;
	}
public:
	BigInteger():digit(0), symbol(true) {
		num = new int[1];
		num[0] = 0;
	}
	BigInteger(const BigInteger& a):symbol(true){
		digit = a.digit;
		if (digit != 0) {
			num = new int[digit];
			for (int i = 0; i < digit; i++) {
				num[i] = a.num[i];
			}
			this->symbol = a.symbol;
		}
		else {
			num = new int[1];
			num[0] = 0;
		}
	}
	BigInteger(string str) :symbol(true) {
		if (str[0] == '-') {
			symbol = false;
			str.erase(0, 1);
		}
		int st = str.find_first_not_of('0');
		if (st != -1) {
			str = str.substr(st);
			digit = str.length();
			num = new int[str.length()];
			for (int i = 0; i < str.length(); i++) {
				num[i] = int(str[i] - '0');
			}
		}else { //This number is 0
			digit = 0; 
			num = new int[1];
			num[0] = 0;
		}		
	}
	
	BigInteger(int* num_, int digit_) :symbol(true) {
		int st = 0;
		while (st < digit_ && num_[st] == 0) {
			st++;
		}
		digit = digit_-st;
		if (digit == 0) {
			num = new int[1];
			num[0] = 0;
		}else {
			num = new int[digit];
			for (int i = 0; i < digit; i++) {
				num[i] = num_[i + st];
			}
		}		
	}
	int getDigit() {
		return digit;
	}
	int getIthDigit(int i) {
		return num[i];
	}
	bool getSymbol() {
		return symbol;
	}
	bool isZero()const {
		return digit == 0;
	}
	string toString()const{
		string str = getAboslute();
		if (!this->isZero() && !symbol) {
			str = '-' + str;
		}
		return str;
	}
	string getAboslute()const {
		if (this->isZero()) {
			return "0";
		}
		string str = "";
		for (int i = 0; i < digit; i++) {
			str = str + char(num[i] + '0');
		}
		return str;
	}
	void setSymbol(bool sym) {
		this->symbol = sym;
	}
	
	BigInteger operator+(BigInteger& bi) {
		int* first = num;
		int* second = bi.num;
		int idx1 = digit-1;
		int idx2 = bi.digit-1;
		int carry = 0;
		string rst = "";
		while (idx1 >= 0 || idx2 >= 0) {
			int a, b;
			if (idx1 < 0)a = 0;
			else a = first[idx1];
			if (idx2 < 0)b = 0;
			else b = second[idx2];
			int sum = a + b + carry;
			carry = sum / 10;
			sum = sum % 10;
			rst = (char)('0' + sum) + rst;
			idx1--;
			idx2--;
		}		
		if (carry == 1) {
			rst = '1' + rst;
		}
		return rst;
	}
	BigInteger operator-(BigInteger& bi) {
		BigInteger bigger, smaller;
		bool isNegative = false;
		if (bi < *this || bi == *this) {
			bigger = *this;
			smaller = bi;
		}
		else {
			bigger = bi;
			smaller = *this;
			isNegative = true;
		}
		int* first, *second;
		first = bigger.num;
		second = smaller.num;
		int idx1 = bigger.digit-1;
		int idx2 = smaller.digit-1;

		int borrow = 0;
		string rst;
		while (idx1 >= 0 || idx2 >= 0) {
			int a, b;
			if (idx1 < 0)a = 0;
			else a = first[idx1];
			if (idx2 < 0)b = 0;
			else b = second[idx2];
			int sum = a - b + borrow;
			borrow = sum < 0 ? -1 : 0;
			sum = sum < 0 ? sum + 10 : sum;
			rst = (char)('0' + sum) + rst;
			idx1--;
			idx2--;
		}		
		//assert(borrow != -1);
		if (isNegative) {
			rst = '-' + rst;
		}
		return (rst);
	}
	BigInteger operator*(BigInteger& bi) {
		BigInteger first, second;
		if (bi < *this) {
			first = *this;
			second = bi;
		}
		else {
			first = bi;
			second = *this;
		}
		string mf = this->getAboslute();
		string ms = bi.getAboslute();
		string rst = multiply(mf, ms, 0);
		BigInteger ans(rst);
		bool symbol = !(this->symbol ^ bi.symbol);
		ans.setSymbol(symbol);
		return ans;
	}
	BigInteger operator/(BigInteger& bi) {
		bool symbol = !(this->symbol ^ bi.symbol);		
		if (*this < bi) {
			BigInteger rst("0");
			rst.setSymbol(symbol);
			return rst;;
		}
		if (*this == bi) {
			BigInteger rst("1");
			rst.setSymbol(symbol);
			return rst;
		}
		BigInteger first = *this;
		BigInteger second = bi;

		int st = 0;
		string res = "";
		int end = 1;
		BigInteger left;
		do {
			if (first.num[st] == 0) {
				res = res + '0';
				st++;
				end = st+1;
				continue;
			}
			BigInteger temp(first.num + st, end - st);
			if (temp < second) {
				res = res + '0';
				end++;
				continue;
			}
			int tres = 0;
			while (second < temp || second == temp) {
				temp = temp - bi;
				tres++;
			}
			res += char(tres + '0');
			st = end - temp.digit;
			for (int i = 0; i < temp.digit; i++) {
				first.num[st + i] = temp.getIthDigit(i);
			}
			end = max(end+1, st+1);
		} while (end <= first.digit);		
		BigInteger ans(res);
		ans.setSymbol(symbol);
		return ans;
	}
	bool operator<(const BigInteger& bi)const {
		if (this->symbol ^ bi.symbol == 1) {
			return this->symbol;
		}
		bool symbol = this->symbol;
		if (digit != bi.digit) {
			return (digit < bi.digit) ^ (!symbol);
		}
		for (int i = 0; i < digit; i++) {
			if (num[i] != bi.num[i]) {
				return (num[i] < bi.num[i]) ^ (!symbol);
			}
		}
		return false;
	}	
	bool operator==(const BigInteger& bi)const {
		return !(*this < bi || bi < *this);
	}
	BigInteger& operator=(const BigInteger& bi) {
		digit = bi.digit;
		num = new int[digit];
		for (int i = 0; i < digit; i++) {
			num[i] = bi.num[i];
		}
		symbol = bi.symbol;
		return *this;
	}
	BigInteger& operator=(const string str){
		BigInteger temp(str);
		digit = temp.digit;
		num = new int[digit];
		for (int i = 0; i < digit; i++) {
			num[i] = temp.num[i];
		}
		symbol = temp.symbol;
		return *this;
	}
	friend ostream& operator<<(ostream &o, const BigInteger& bi) {
		return o << bi.toString();
	}
	~BigInteger() {
		delete[] num;
	}
};

string oneDigitMulti(string first, char multi) {
	string rst = "";
	int carry = 0;
	for (int i = first.length() - 1; i >= 0; i--) {
		int prod = (first.at(i) - '0') * (multi - '0') + carry;
		carry = prod / 10;
		rst = (char)(prod % 10 + '0') + rst;
	}
	if (carry != 0) {
		rst = (char)(carry + '0') + rst;
	}
	return rst;
}
string multiply(string first, string second, int magnifier) {
	if (second.length() == 0) {
		return "0";
	}
	if (second.length() == 1) {
		return oneDigitMulti(first, second[0]) + string(magnifier, '0');
	}
	int len = second.length();
	BigInteger fp = multiply(first, second.substr(0, len / 2), magnifier + len - len / 2);
	BigInteger sp = multiply(first, second.substr(len / 2), magnifier);
	return (fp + sp).toString();
}

int main() {
	//BigInteger b1("87894123467984512789");
	//BigInteger b2("5684");
	//string rst = (b1/b2).toString();
	//cout << rst << endl;
	string first, second;
	char op;
	cin >> first;
	cin >> op;
	cin >> second;
	BigInteger bi1(first);
	BigInteger bi2(second);
	switch (op) {
	case '+':
		cout << bi1 + bi2 << endl;
		break;
	case '-':
		cout << bi1 - bi2 << endl;
		break;
	case '*':
		cout << bi1 * bi2 << endl;
		break;
	case '/':
		cout << bi1 / bi2 << endl;
		break;
	}
	//system("pause");
}