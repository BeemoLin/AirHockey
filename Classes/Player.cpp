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

bool Player::onTouchBegan(Touch *touch, Event *event)
{
	if (m_state != kPlayerStateUngrabbed)
	{
		return false;
	}

	if (!containsTouchLocation(touch))
	{
		return false;
	}
	return true;
}

void Player::onTouchMoved(Touch *touch, Event *event)
{
	this->setPosition(this->getPosition() + touch->getDelta());
}

void Player::onTouchEnded(Touch *touch, Event *event)
{
}

void Player::touchDelegateRetain()
{
	this->retain();
}

void Player::touchDelegateRelease()
{
	this->release();
}
