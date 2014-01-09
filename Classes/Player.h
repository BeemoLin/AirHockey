#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

typedef enum tagPlayerState
{
	kPlayerStateGrabbed,
	kPlayerStateUngrabbed
}PlayerState;

class Player : public GameSprite
{
private:
	PlayerState m_state;
public:
	Player(void);
	virtual ~Player(void);

	Rect rect();
	bool initWithTexture(Texture2D* aTexture);

	bool containsTouchLocation(Touch* touch);

	static GameSprite* spriteWithTexture(Texture2D* aTexture);
};
#endif