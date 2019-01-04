//
//  Joystick.h
//  tankDemo
//
//  Created by Alex on 2018/9/21.
//

#ifndef Joystick_h
#define Joystick_h

#include "cocos2d.h"

//enum Direction    // 方向
//{
//    UP = 1,        // 上
//    RIGHT,        // 右
//    DOWN,        // 下
//    LEFT        // 左
//};

enum DirectionKeyState
{
    DirectionKeyStateNotPressed = 0,
    DirectionKeyStateUpPressed = 1,         // 上（W键）
    DirectionKeyStateRightPressed = 2,      // 右（D键）
    DirectionKeyStateDownPressed = 3,       // 下（S键）
    DirectionKeyStateLeftPressed = 4,      // 左（A键）
};

extern DirectionKeyState KeyDirection; //方向键
//extern bool KeyUp;        // 上（W键）
//extern bool KeyRight;     // 右（D键）
//extern bool KeyDown;        // 下（S键）
//extern bool KeyLeft;        // 左（A键）
extern bool KeySelect;    // 选择（V键）
extern bool KeyStart;        // 开始（B键）
extern bool KeyB;            // B按钮（J键）
extern bool KeyA;            // A按钮（K键）

class Joystick : public cocos2d::Layer {
    
public:
    Joystick();
    ~Joystick();
    static Joystick* sharedInstance();
    virtual bool init();
    
private:
    void setupJoystick();
    /* 设置触摸（虚拟手柄） */
    void setTouch(cocos2d::Sprite* target, cocos2d::Vec2 location, bool state);
//    /* 设置按键状态（键盘） */
    void setKeyState(cocos2d::EventKeyboard::KeyCode keyCode, bool state);
    
//    bool g_keyUp = false;        // 上（W键）
//    bool g_keyRight = false;     // 右（D键）
//    bool g_keyDown = false;        // 下（S键）
//    bool g_keyLeft = false;        // 左（A键）
//    bool g_keySelect = false;    // 选择（V键）
//    bool g_keyStart = false;        // 开始（B键）
//    bool g_keyB = false;            // B按钮（J键）
//    bool g_keyA = false;            // A按钮（K键）
};


#endif /* Joystick_h */
