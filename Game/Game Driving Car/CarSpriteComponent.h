#pragma once
#include "SpriteComponent.h"
#include <vector>

class CarSpriteComponent : public SpriteComponent
{
public:
    CarSpriteComponent(class Actor* owner, int drawOrder = 100);
    void SetCarTextures(const std::vector<SDL_Texture*>& textures);
private:
    // All textures in the animation
    std::vector<SDL_Texture*> mCarTextures;
    // Current frame displayed
    float mCurrFrame;
};
