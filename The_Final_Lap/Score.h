#pragma once
#include <string>
using namespace std;
class CScore
{
private:
	int Score;
	string Name;
public:
	int RSc();
	string RNn();
	CScore(void);
	void Input();
	~CScore(void);
};

