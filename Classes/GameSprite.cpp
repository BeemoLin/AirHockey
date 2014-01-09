#include "GameSprite.h"

USING_NS_CC;

GameSprite::GameSprite(void)
{
	_screenSize = Director::sharedDirector()->getWinSize();
}

GameSprite::~GameSprite(void)
{
}

float GameSprite::radius()
{
	return getTexture()->getContentSize().width * 0.5f;
}

GameSprite* GameSprite::spriteWithTexture(Texture2D* aTexture)
{
	GameSprite* pSprite = new GameSprite();

	pSprite->initWithTexture(aTexture);
	pSprite->autorelease();

	return pSprite;
}

void GameSprite::setPosition(const Point& pos)
{
	Sprite::setPosition(pos);
	if (!_nextPosition.equals(pos))
	{
		_nextPosition = pos;
	}
}