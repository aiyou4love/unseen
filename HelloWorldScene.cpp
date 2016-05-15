#include "HelloWorldScene.h"

USING_NS_CC;

Scene * HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto listener_ = EventListenerTouchOneByOne::create();
	listener_->setSwallowTouches(true);
	listener_->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener_->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener_->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	EventDispatcher * eventDispatcher_ = Director::getInstance()->getEventDispatcher();
	eventDispatcher_->addEventListenerWithSceneGraphPriority(listener_, this);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache * spriteFrameCache_ = SpriteFrameCache::getInstance();
	spriteFrameCache_->addSpriteFramesWithFile("Themes/Theme1/BG0/BG1-hd.plist");
	spriteFrameCache_->addSpriteFramesWithFile("Themes/Theme1/BG1/BG-hd.plist");
	spriteFrameCache_->addSpriteFramesWithFile("Themes/Theme1/Items/Monsters01-hd.plist");

	SpriteFrame * bgImage_ = spriteFrameCache_->getSpriteFrameByName("BG1.png");
	Sprite * bgSprite_ = Sprite::createWithSpriteFrame(bgImage_);
	bgSprite_->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bgSprite_);

	SpriteFrame * pathImage_ = spriteFrameCache_->getSpriteFrameByName("Path.png");
	Sprite * pathSprite_ = Sprite::createWithSpriteFrame(pathImage_);
	pathSprite_->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(pathSprite_);

	mTiledMap = TMXTiledMap::create("Themes/Theme1/BG1/BGPath.tmx");
	this->addChild(mTiledMap);

	TMXObjectGroup * objectGroup_ = mTiledMap->getObjectGroup("PATH");

	int pathIndex_ = 1;
	char pathName_[20];
	
	memset(pathName_, 0, sizeof(pathName_));
	sprintf(pathName_, "PT%i", pathIndex_);
	ValueMap valueMap_ = objectGroup_->getObject(pathName_);
	while (valueMap_.size() > 0)
	{
		MovePath movePath_;
		movePath_.mId = pathIndex_;
		movePath_.mX = valueMap_["x"].asFloat();
		movePath_.mY = valueMap_["y"].asFloat();
		mMovePaths[pathIndex_] = movePath_;

		pathIndex_++;
		memset(pathName_, 0, sizeof(pathName_));
		sprintf(pathName_, "PT%i", pathIndex_);
		valueMap_ = objectGroup_->getObject(pathName_);
	}
    return true;
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{

	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{
}

void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
}
