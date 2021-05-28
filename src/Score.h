#ifndef __CRAZY_CAR__SCORE_H__
#define __CRAZY_CAR__SCORE_H__

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

#endif