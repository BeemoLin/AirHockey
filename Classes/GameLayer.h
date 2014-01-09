#ifndef __GameLayer_H__
#define __GameLayer_H__

#define GOAL_WIDTH 400

#include "cocos2d.h"
#include "Player.h"

enum
{
	kPlayer1Tag,
	kPlayer2Tag
};

USING_NS_CC;

class GameLayer : public cocos2d::Layer
{
protected:
	
	Player* _player1;
	Player* _player2;

	Size _screenSize;

	int _player1Score;
	int _player2Score;

	void playerScore(int player);
public:
	GameLayer();

	~GameLayer();

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void update(float dt);

	// a selector callback
	void menuCloseCallback(Object* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(GameLayer);
};

#endif // __GameLayer_H__
