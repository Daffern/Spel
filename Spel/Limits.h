
#ifndef _LIMITS_H_
#define _LIMITS_H_

class Limits{
public:
	static bool checkBounds(int pointX, int pointY, int x,int y, int width, int height){
		if (pointX>x && pointY>y && pointX<x+width && pointY<y+height)
			return true;
		else return false;
	}
};

#endif

//nei
