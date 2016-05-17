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
	spriteFrameCache_->addSpriteFramesWithFile("Themes/Theme1/Items/Monsters02-hd.plist");
	spriteFrameCache_->addSpriteFramesWithFile("Themes/Towers/TBottle-hd.plist");

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
		Vec2 moveVec2_;
		moveVec2_.x = valueMap_["x"].asFloat();
		moveVec2_.y = valueMap_["y"].asFloat();
		mMovePoints[pathIndex_] = moveVec2_;

		pathIndex_++;
		memset(pathName_, 0, sizeof(pathName_));
		sprintf(pathName_, "PT%i", pathIndex_);
		valueMap_ = objectGroup_->getObject(pathName_);
	}
	Vector<SpriteFrame *> spriteFrames_;
	SpriteFrame * bossframe1_ = spriteFrameCache_->getSpriteFrameByName("land_pink01.png");
	SpriteFrame * bossframe2_ = spriteFrameCache_->getSpriteFrameByName("land_pink02.png");
	spriteFrames_.pushBack(bossframe1_);
	spriteFrames_.pushBack(bossframe2_);

	Animation * animation_ = Animation::createWithSpriteFrames(spriteFrames_, 0.2f);
	int speed_ = 60;

	Vector<FiniteTimeAction*> finiteTimeActions_;
	for (size_t i = 1; i < mMovePoints.size(); i++)
	{
		float duration_ = mMovePoints[i].distance(mMovePoints[i + 1]);
		duration_ /= speed_;
		MoveTo * moveTo_ = MoveTo::create(duration_, mMovePoints[i + 1]);
		finiteTimeActions_.pushBack(moveTo_);
	}
	Animate * animate_ = Animate::create(animation_);
	Repeat * repeat_ = Repeat::create(animate_, -1);
	Sequence * sequece_ = Sequence::create(finiteTimeActions_);
	Spawn * spawn_ = Spawn::create(sequece_, repeat_, nullptr);

	Sprite * mBossSprite = Sprite::createWithSpriteFrame(bossframe1_);
	mBossSprite->setPosition(mMovePoints[1]);
	mBossSprite->setAnchorPoint(Vec2(0.f, 0.5f));
	this->addChild(mBossSprite);

	mBossSprite->runAction(spawn_);
	
	Vector<SpriteFrame *> towerFrames_;
	SpriteFrame * towerFrame1_ = spriteFrameCache_->getSpriteFrameByName("Bottle11.png");
	SpriteFrame * towerFrame2_ = spriteFrameCache_->getSpriteFrameByName("Bottle12.png");
	SpriteFrame * towerFrame3_ = spriteFrameCache_->getSpriteFrameByName("Bottle13.png");
	towerFrames_.pushBack(towerFrame1_);
	towerFrames_.pushBack(towerFrame2_);
	towerFrames_.pushBack(towerFrame3_);

	Animation * towerAnimation_ = Animation::createWithSpriteFrames(towerFrames_, 0.2f);
	Animate * towerAnimate_ = Animate::create(towerAnimation_);

	Sprite * mTowerSprite = Sprite::createWithSpriteFrame(towerFrame1_);
	mTowerSprite->setPosition(Vec2(200.f, 300.f));
	this->addChild(mTowerSprite);

	mTowerSprite->runAction(CCRepeatForever::create(towerAnimate_));

	Vector<SpriteFrame *> bulletFrames_;
	SpriteFrame * bulletFrame1_ = spriteFrameCache_->getSpriteFrameByName("PBottle11.png");
	SpriteFrame * bulletFrame2_ = spriteFrameCache_->getSpriteFrameByName("PBottle12.png");
	SpriteFrame * bulletFrame3_ = spriteFrameCache_->getSpriteFrameByName("PBottle13.png");
	bulletFrames_.pushBack(bulletFrame1_);
	bulletFrames_.pushBack(bulletFrame2_);
	bulletFrames_.pushBack(bulletFrame3_);

	Animation * bulletAnimation_ = Animation::createWithSpriteFrames(bulletFrames_, 0.2f);
	Animate * bulletAnimate_ = Animate::create(bulletAnimation_);

	Sprite * bulletSprite_ = Sprite::createWithSpriteFrame(bulletFrame1_);
	bulletSprite_->setPosition(Vec2(200.f, 350.f));
	this->addChild(bulletSprite_);

	bulletSprite_->runAction(CCRepeatForever::create(bulletAnimate_));

	scheduleUpdate();

    return true;
}
http://blog.csdn.net/shun_fzll/article/details/34430045
void HelloWorld::update(float dt) 
{
	const Vec2& bossPoint_ = mBossSprite->getPosition();
	const Vec2& towerPoint_ = mTowerSprite->getPosition();
	float distance_ = bossPoint_.distance(towerPoint_);
	if (distance_ > 150) return;
	Vec2 vector_ = bossPoint_ - towerPoint_;
	vector_.normalize();
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
