#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

	void update(float dt);

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(HelloWorld);

private:
	std::map<int, Vec2> mMovePoints;
	TMXTiledMap * mTiledMap;
	Sprite * mTowerSprite;
	Sprite * mBossSprite;
};

#endif // __HELLOWORLD_SCENE_H__
