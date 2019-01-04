//
//  LoadingScene.h
//  tankDemo
//
//  Created by Alex on 2018/9/17.
//

#ifndef LoadingScene_h
#define LoadingScene_h

#include "cocos2d.h"

class LoadingScene : public cocos2d::Scene
{
public:
    LoadingScene();
    ~LoadingScene();
    static LoadingScene* create();
    virtual bool init();
    
    virtual void onEnterTransitionDidFinish();
    virtual void loadResourceCallback();
    
private:
    int loadFinishResCount = 0;
    static std::vector<std::string> needLoadPlists();
    static std::vector<std::string> needLoadImages();
};


#endif /* LoadingScene_h */
