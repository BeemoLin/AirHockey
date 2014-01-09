#ifndef _GAMESPRITE_H_
#define _GAMESPRITE_H_

#include "cocos2d.h"

USING_NS_CC;

class GameSprite : public cocos2d::Sprite
{
	CC_SYNTHESIZE(Point, _nextPosition, NextPosition);
	CC_SYNTHESIZE(Point, _vector, Vector);

	Size _screenSize;

	GameSprite(void);
	~GameSprite(void);
	float radius();
	static GameSprite* spriteWithTexture(Texture2D* aTexture);
	virtual void setPosition(const Point& pos);
};
#endif