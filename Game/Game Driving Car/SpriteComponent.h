#pragma once
#include "Component.h"
#include "SDL.h"

class SpriteComponent: public Component
{
public:
    SpriteComponent(class Actor* owner, int drawOrder = 100);
    ~SpriteComponent();
    
    virtual void Draw(SDL_Renderer* renderer);
    virtual void SetTexture(SDL_Texture* texture);
    
    int GetDrawOrder() const {return mDrawOrder;}
    int GetTexHeight() const {return mTexHeight;}
    int GetTexWidth() const {return mTexWidth;}
    inline float ToDegrees(float radians) { return radians * 180.0f / Pi;}
    
protected:
    SDL_Texture* mTexture;
    int mDrawOrder;
    int mTexWidth;
    int mTexHeight;
    const float Pi = 3.1415926535f;
};

