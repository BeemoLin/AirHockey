/* === 初始畫面 === */
#include "GameLayer.h"
#include "Player.h"

USING_NS_CC;

/***/
GameLayer::GameLayer()
{
	// constructor
}

// 解構式
GameLayer::~GameLayer()
{
	// destructor
}

/*場景*/
Scene* GameLayer::createScene()
{
	Scene* scene = NULL;

	do
	{
		// 'scene' is an autorelease object
		scene = Scene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		GameLayer* layer = GameLayer::create();
		CC_BREAK_IF(! layer);
		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
	bool bRet = false;

	// create main loop
	do
	{
		//////////////////////////////
		// super init first
		/////////////////////////////
		CC_BREAK_IF(!Layer::init());

		Size visibleSize = Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();

		/////////////////////////////
		// 2. add a menu item with "X" image, which is clicked to quit the program
		//    you may modify it.

		// add a "close" icon to exit the progress. it's an autorelease object
		auto closeItem = MenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			CC_CALLBACK_1(GameLayer::menuCloseCallback, this));

		closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
			origin.y + closeItem->getContentSize().height / 2));

		// create menu, it's an autorelease object
		auto menu = Menu::create(closeItem, NULL);
		menu->setPosition(Point::ZERO);
		this->addChild(menu, 1);

		/////////////////////////////
		// 3. add your codes below...

		// add a label shows "Hello World"
		// create and initialize a label

		//auto label = LabelTTF::create("Hello World", "Arial", 24);

		//// position the label on the center of the screen
		//label->setPosition(Point(origin.x + visibleSize.width / 2,
		//	origin.y + visibleSize.height - label->getContentSize().height));

		//// add the label as a child to this layer
		//this->addChild(label, 1);

		_player1Score = 0;
		_player2Score = 0;

		_screenSize = Director::sharedDirector()->getWinSize();
		
		Sprite* court = Sprite::create("court.png");
		CC_BREAK_IF(!court);
		court->setPosition(Point(_screenSize.width * 0.5, _screenSize.height * 0.5));
		this->addChild(court, 0);

		// 建立Player

		Texture2D *pPlayerTexture = TextureCache::sharedTextureCache()->addImage("mallet.png");

		_player1 = (Player*)Player::spriteWithTexture(pPlayerTexture);
		CC_BREAK_IF(!_player1);
		_player1->setPosition(ccp(_player1->radius() * 2, _screenSize.height * 0.5));
		this->addChild(_player1, 0, kPlayer1Tag);

		// this->schedule(schedule_selector(GameLayer::onUpdate));
		bRet = true;
	} while (0);

	return bRet;
}

void GameLayer::update(float dt)
{
	
}

void GameLayer::menuCloseCallback(Object* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
