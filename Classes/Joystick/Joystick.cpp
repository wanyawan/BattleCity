//
//  Joystick.cpp
//  tankDemo-mobile
//
//  Created by Alex on 2018/9/21.
//

#include "Joystick.h"
#include "Global.h"

USING_NS_CC;

//bool KeyUp = false;
//bool KeyRight = false;
//bool KeyDown = false;
//bool KeyLeft = false;
DirectionKeyState KeyDirection = DirectionKeyStateNotPressed;
bool KeySelect = false;
bool KeyStart = false;
bool KeyB = false;
bool KeyA = false;

static Joystick *s_joystick = nullptr;

enum KeyTag            // 虚拟手柄每个按钮精灵的tag
{
    kKeyUpTag,
    kKeyRightTag,
    kKeyDownTag,
    kKeyLeftTag,
    kKeySelectTag,
    kKeyStartTag,
    kKeyBTag,
    kKeyATag
};

Joystick::Joystick() {
}

Joystick::~Joystick() {
}

Joystick* Joystick::sharedInstance() {
    if (!s_joystick) {
        s_joystick = new (std::nothrow) Joystick();
        CCASSERT(s_joystick, "FATAL: Not enough memory");
        s_joystick->init();
    }
    return s_joystick;
}


//Joystick* Joystick::create() {
//    Joystick *joystick = new (std::nothrow) Joystick();
//    if (joystick && joystick->init())
//    {
//        joystick->autorelease();
//        return joystick;
//    } else {
//        delete joystick;
//        joystick = nullptr;
//        return nullptr;
//    }
//}

bool Joystick::init() {
    bool result = Layer::init();
    // super init 设置了contentSize
    setupJoystick();
    return result;
}

void Joystick::setupJoystick() {
    auto up = Sprite::create("key1.png");
    up->setOpacity(100);
    up->setPosition(90, 150);
    this->addChild(up, 0, kKeyUpTag);
    
    auto right = Sprite::create("key1.png");
    right->setOpacity(100);
    right->setRotation(90);
    right->setPosition(150, 90);
    this->addChild(right, 0, kKeyRightTag);
    
    auto down = Sprite::create("key1.png");
    down->setOpacity(100);
    down->setRotation(180);
    down->setPosition(90, 30);
    this->addChild(down, 0, kKeyDownTag);
    
    auto left = Sprite::create("key1.png");
    left->setOpacity(100);
    left->setRotation(270);
    left->setPosition(30, 90);
    this->addChild(left, 0, kKeyLeftTag);
    
    auto select = Sprite::create("key2.png");
    select->setOpacity(100);
    select->setPosition(SCREEN_CX - 35, 23);
    this->addChild(select, 0, kKeySelectTag);
    
    auto start = Sprite::create("key2.png");
    start->setOpacity(100);
    start->setPosition(SCREEN_CX + 35, 23);
    this->addChild(start, 0, kKeyStartTag);
    
    auto b = Sprite::create("key3.png");
    b->setOpacity(100);
    b->setPosition(SCREEN_WIDTH - 135, 40);
    this->addChild(b, 0, kKeyBTag);
    
    auto a = Sprite::create("key4.png");
    a->setOpacity(100);
    a->setPosition(SCREEN_WIDTH - 45, 40);
    this->addChild(a, 0, kKeyATag);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        this->setTouch(target, touch->getLocation(), true);
        return true;
    };
    touchListener->onTouchEnded = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        this->setTouch(target, touch->getStartLocation(), false);
    };
    touchListener->onTouchCancelled = touchListener->onTouchEnded;
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    
    auto keyboardEventListener = EventListenerKeyboard::create();
    keyboardEventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
        this->setKeyState(keyCode, true);
    };
    keyboardEventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
        this->setKeyState(keyCode, false);
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardEventListener, this);
}

void Joystick::setTouch(Sprite* target, Vec2 location, bool state)
{
    auto locationInNode = target->convertToNodeSpace(location);
    for (auto child : this->getChildren())
    {
        if (child->getBoundingBox().containsPoint(locationInNode))
        {
            auto tag = child->getTag();
            switch (tag)
            {
                case kKeyUpTag:
                    KeyDirection = state ? DirectionKeyStateUpPressed : DirectionKeyStateNotPressed;
                    break;
                case kKeyRightTag:
                    KeyDirection = state ? DirectionKeyStateRightPressed : DirectionKeyStateNotPressed;
                    break;
                case kKeyDownTag:
                    KeyDirection = state ? DirectionKeyStateDownPressed : DirectionKeyStateNotPressed;
                    break;
                case kKeyLeftTag:
                    KeyDirection = state ? DirectionKeyStateLeftPressed : DirectionKeyStateNotPressed;
                    break;
                case kKeySelectTag:
                    KeySelect = state;
                    break;
                case kKeyStartTag:
                    KeyStart = state;
                    break;
                case kKeyBTag:
                    KeyB = state;
                    break;
                case kKeyATag:
                    KeyA = state;
                    break;
            }
        }
    }
}

void Joystick::setKeyState(EventKeyboard::KeyCode keyCode, bool state)
{
    switch(keyCode)
    {
        case EventKeyboard::KeyCode::KEY_W:
            KeyDirection = state ? DirectionKeyStateUpPressed : DirectionKeyStateNotPressed;
            break;
        case EventKeyboard::KeyCode::KEY_S:
            KeyDirection = state ? DirectionKeyStateDownPressed : DirectionKeyStateNotPressed;
            break;
        case EventKeyboard::KeyCode::KEY_A:
            KeyDirection = state ? DirectionKeyStateLeftPressed : DirectionKeyStateNotPressed;
            break;
        case EventKeyboard::KeyCode::KEY_D:
            KeyDirection = state ? DirectionKeyStateRightPressed : DirectionKeyStateNotPressed;
            break;
        case EventKeyboard::KeyCode::KEY_V:
            KeySelect = state;
            break;
        case EventKeyboard::KeyCode::KEY_B:
            KeyStart = state;
            break;
        case EventKeyboard::KeyCode::KEY_J:
            KeyB = state;
            break;
        case EventKeyboard::KeyCode::KEY_K:
            KeyA = state;
            break;
        default:
            break;
    }
}




