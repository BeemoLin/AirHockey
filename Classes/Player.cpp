#include "Player.h"

Player::Player(void)
{
}

Player::~Player(void)
{
}

Rect Player::rect()
{
	Size size = getTexture()->getContentSize();
	return CCRectMake(-size.width / 2, -size.height / 2, size.width, size.height);
}

GameSprite* Player::spriteWithTexture(Texture2D* aTexture)
{
	Player* pPlayer = new Player();
	pPlayer->initWithTexture(aTexture);
	pPlayer->autorelease();

	return pPlayer;
}

bool Player::initWithTexture(Texture2D* aTexture)
{
	if (Sprite::initWithTexture(aTexture))
	{
		m_state = kPlayerStateUngrabbed;
	}

	return true;
}

void Player::onEnter()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getEventDispatcher()->
	CCSprite::onEnter();
}