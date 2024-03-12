#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character
{
public:
	Character(int x, int y, int width, int height);
	~Character();

	int x;
	int y;
	int width;
	int height;
};



#endif