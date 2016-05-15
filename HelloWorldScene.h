#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

struct MovePath
{
	int mId;
	float mX;
	float mY;
};

class HelloWorld : public cocos2d::Layer
{
public:
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(HelloWorld);

private:
	std::map<int, MovePath> mMovePaths;
	TMXTiledMap * mTiledMap;
};

#endif // __HELLOWORLD_SCENE_H__
