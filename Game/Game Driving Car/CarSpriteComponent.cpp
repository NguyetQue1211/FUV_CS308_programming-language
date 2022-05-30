#include "CarSpriteComponent.h"
#include "Math.h"

CarSpriteComponent::CarSpriteComponent(Actor* owner, int drawOrder)
    :SpriteComponent(owner, drawOrder)
{
}

void CarSpriteComponent::SetCarTextures(const std::vector<SDL_Texture*>& textures)
{
    mCarTextures = textures;
    if (mCarTextures.size() > 0)
    {
        // Set the active texture to first frame
        mCurrFrame = 0.0f;
        SetTexture(mCarTextures[0]);
    }
}
