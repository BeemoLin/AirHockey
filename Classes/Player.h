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

class Player : public GameSprite, public EventDispatcher
{
public:
	Player(void);
	virtual ~Player(void);

	Rect rect();
	bool initWithTexture(Texture2D* aTexture);

	bool containsTouchLocation(Touch* touch);

	virtual void onEnter() override;
	virtual void onExit() override;
	virtual std::string title() const override;
	virtual std::string subtitle() const override;

	static GameSprite* spriteWithTexture(Texture2D* aTexture);
private:
	PlayerState m_state;

	EventListenerCustom* _listener;
	EventListenerCustom* _listener2;
};
#endif