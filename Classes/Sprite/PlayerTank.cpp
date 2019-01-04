//
//  PlayerTank.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/10/22.
//

#include "PlayerTank.h"
#include "Joystick.h"

PlayerTank::PlayerTank()
{
    _stepMax = 2;
    _speed = 1.5;
}

PlayerTank::~PlayerTank()
{
}

PlayerTank* PlayerTank::create(int type)
{
    PlayerTank *pRet = new PlayerTank();
    if (pRet && pRet->init(type))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool PlayerTank::init(int type)
{
    _level = 1;
    this->initWithSpriteFrameName("player1_1_1_1.png");
    this->scheduleUpdate();
    this->initPos();
    return Tank::init(type);
    //        _life = DataM::getInstance()->getPlayerLife();
//    bool bRet = false;
//    do
//    {
//        _type = type;
//        this->initWithSpriteFrameName("player1_1_1_1.png");
//        this->initPos();
//        this->setLevel(DataM::getInstance()->getPlayerLevel());
//        this->setShield(2.5f);
//        this->scheduleUpdate();
//        bRet = true;
//    }while(false);
//    return bRet;
    
}

void PlayerTank::initPos()
{
    this->setPos(getPos(25, 9), UP);
//    _onIce = false;
}

void PlayerTank::update(float dt)
{
    _dt = dt;
//    auto state = GameScene::getGameState();
//    if (state == kPause || state == kFail)
//    {
//        return;
//    }
//    _shootInterval += dt;
    
    
    switch (KeyDirection) {
        case DirectionKeyStateUpPressed:
            _direction == DirectionKeyStateUpPressed ? moveUp() : turnUp();
            break;
        case DirectionKeyStateDownPressed:
            _direction == DirectionKeyStateDownPressed ? moveDown() : turnDown();
            break;
        case DirectionKeyStateLeftPressed:
            _direction == DirectionKeyStateLeftPressed ? moveLeft() : turnLeft();
            break;
        case DirectionKeyStateRightPressed:
            _direction == DirectionKeyStateRightPressed ? moveRight() : turnRight();
            break;
        case DirectionKeyStateNotPressed:
        default:
            break;
    }
    
//    if(KeyDirection)
//    {
//        _move = true;
//        if(_direction == UP)
//        {
//            moveUp();
//            _inertia = 32;
//        }
//        else
//        {
//            turnUp();
//        }
//    }
//    else if(g_keyDown)
//    {
//        _move = true;
//        if(_direction == DOWN)
//        {
//            moveDown();
//            _inertia = 32;
//        }
//        else
//        {
//            turnDown();
//        }
//    }
//    else if(g_keyLeft)
//    {
//        _move = true;
//        if(_direction == LEFT)
//        {
//            moveLeft();
//            _inertia = 32;
//        }
//        else
//        {
//            turnLeft();
//        }
//    }
//    else if(g_keyRight)
//    {
//        _move = true;
//        if(_direction == RIGHT)
//        {
//            moveRight();
//            _inertia = 32;
//        }
//        else
//        {
//            turnRight();
//        }
//    }
//    else
//    {
//        _move = false;
//        trackSlip();
//    }
    
//    if (_moveAudioId != AudioM::INVALID_AUDIO_ID && _move == false)
//    {
//        this->stopMoveAudio();
//    }
//    else if (_moveAudioId == AudioM::INVALID_AUDIO_ID && _move == true)
//    {
//        this->playMoveAudio();
//    }
//
//    if(g_keyB || g_keyA)
//    {
//        if(g_keyB)
//        {
//            g_keyB = false;
//        }
//        if (_shootInterval > 0.1f)
//        {
//            _shootInterval = 0.0f;
//            if (shoot())
//            {
//                AudioM::play2d(A_BULLET);
//            }
//        }
//    }
    if(overlapCheck())
    {
        _newPos = _position;
    }
    if (collide())
    {
        _inertia = 0;
    }
    auto spriteFrameName = String::createWithFormat("player1_%d_%d_%d.png", _level, _direction, _step + 1)->getCString();
    auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
    this->setSpriteFrame(frame);
    this->setPosition(_newPos);
}
