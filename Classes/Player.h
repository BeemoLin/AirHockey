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

class Player : public GameSprite, public Layer
{
public:
	Player(void);
	virtual ~Player(void);

	Rect rect();
	bool initWithTexture(Texture2D* aTexture);

	bool containsTouchLocation(Touch* touch);

	// �Ƽg �qcocos2d::Layer�~�Ӫ�Ĳ���ƥ�
	virtual bool onTouchBegan(Touch* touch, Event* event) override;
	virtual void onTouchMoved(Touch* touch, Event* event) override;
	virtual void onTouchEnded(Touch* touch, Event* event) override;
	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();

	static GameSprite* spriteWithTexture(Texture2D* aTexture);
private:
	PlayerState m_state;
};
#endif