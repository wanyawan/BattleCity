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

GameScene* GameScene::create()
{
    GameScene *scene = new (std::nothrow) GameScene();
    if (scene && scene->init())
    {
        scene->autorelease();
        return scene;
    } else {
        delete scene;
        scene = nullptr;
        return nullptr;
    }
}

bool GameScene::init()
{
    layoutSubviews();
    return Scene::init();
}

void GameScene::layoutSubviews()
{
    _mapLayer = GameMapLayer::create();
    this->addChild(_mapLayer);
    auto playerTank = PlayerTank::create(0);
    this->addChild(playerTank);
}


void GameScene::onEnterTransitionDidFinish() {
    
    
    
}

