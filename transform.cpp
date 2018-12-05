/*
ID: jason.z2
PROG: transform
LANG: C++
*/

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

struct sqPattern {
public:
	sqPattern(int sz, std::string items) : size(sz) {
		pattern.resize(sz);
		int index = 0;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				pattern[i].push_back(items[index]);
				index++;
			}
	}

	sqPattern(sqPattern* pat) {
		size = pat->size;
		pattern = pat->pattern;
	}

	void rot90() {
		sqPattern temp(this);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				this->pattern[j][size - 1 - i] = temp.pattern[i][j];
			}
		}
	}

	void reflect() {
		sqPattern temp(this);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				this->pattern[size - 1 - i][j] = temp.pattern[i][j];
			}
		}
	}

	int size;
	std::vector<std::vector<char>> pattern;
};

inline bool operator==(const sqPattern& left, const sqPattern& right) {
	if (left.size == right.size) {
		for (int i = 0; i < left.size; i++)
			for (int j = 0; j < left.size; j++)
				if (left.pattern[i][j] != right.pattern[i][j]) return false;
		return true;
	}
	else return false;
}

int main() {

	int type;
	int size;
	std::string square1("");
	std::string square2("");
	std::ifstream input("transform.in");
	input >> size;

	for (int i = 0; i < size; i++) {
		std::string temp;
		input >> temp;
		square1 += temp;
	}
	for (int i = 0; i < size; i++) {
		std::string temp;
		input >> temp;
		square2 += temp;
	}

	input.close();

	sqPattern s1(size, square1);
	sqPattern s1Original(s1);
	sqPattern s1Original2(s1Original);
	sqPattern s2(size, square2);

	s1.rot90();
	if (s1 == s2) {
		type = 1;
		goto end;
	}

	s1.rot90();
	if (s1 == s2) {
		type = 2;
		goto end;
	}

	s1.rot90();
	if (s1 == s2) {
		type = 3;
		goto end;
	}

	s1Original2.reflect();
	if (s1Original2 == s2) {
		type = 4;
		goto end;
	}

	s1Original2.rot90();
	if (s1Original2 == s2) {
		type = 5;
		goto end;
	}

	s1Original2.rot90();
	if (s1Original2 == s2) {
		type = 5;
		goto end;
	}

	s1Original2.rot90();
	if (s1Original2 == s2) {
		type = 5;
		goto end;
	}

	if (s1Original == s2) {
		type = 6;
		goto end;
	}

	type = 7;
	goto end;

end:
	std::ofstream output("transform.out");
	output << type << "\n";
	output.close();
	return 0;
}
