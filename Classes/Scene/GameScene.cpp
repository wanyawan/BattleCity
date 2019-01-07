//
//  GameScene.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/10/11.
//

#import "GameScene.h"
#import "PlayerTank.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

GameScene* GameScene::createWithPhysics()
{
    GameScene *scene = new (std::nothrow) GameScene();
    if (scene && scene->initWithPhysics())
    {
        scene->autorelease();
        return scene;
    } else {
        delete scene;
        scene = nullptr;
        return nullptr;
    }
}

bool GameScene::initWithPhysics()
{
    bool result = Scene::initWithPhysics();
    if (result) {
        PhysicsWorld *world = this->getPhysicsWorld();
        //Debug Mask
        world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
        world->setGravity(Vec2(0.0f, 0.0f));
//        world->setAutoStep(false);
//        world->scheduleOnce
        layoutSubviews();
    }
    return result;
}

void GameScene::layoutSubviews()
{
    _mapLayer = GameMapLayer::create();
    this->addChild(_mapLayer);
    auto playerTank = PlayerTank::create(0);
    this->addChild(playerTank);
}


void GameScene::onEnterTransitionDidFinish() {
//    ActionInterval *forwardBy = MoveBy::create(4, Vec2(0, 300));
//    //    ActionInterval *backBy = forwardBy->reverse();
//    Action *action = Repeat::create(dynamic_cast<FiniteTimeAction *>(Sequence::create(forwardBy, NULL)), 4);
//    playerTank->runAction(action);
}

