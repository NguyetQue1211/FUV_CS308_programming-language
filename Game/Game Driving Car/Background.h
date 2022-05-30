#pragma once
#include "SpriteComponent.h"
#include <vector>
#include "Math.h"

class Background : public SpriteComponent
{
public:
    // Set draw order to default to lower (so it's in the background)
    Background(class Actor* owner, int drawOrder = 10);
    // Update/draw overridden from parent
    void Update(float deltaTime) override;
    void Draw(SDL_Renderer* renderer) override;
    // Set the textures used for the background
    void SetBGTextures(const std::vector<SDL_Texture*>& textures);
    // Get/set screen size and scroll speed
    void SetScreenSize(const Vector1& size) { mScreenSize = size; }
    void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
    float GetScrollSpeed() const { return mScrollSpeed; }
private:
    // Struct to encapsulate each bg image and its offset
    struct BGTexture
    {
        SDL_Texture* mTexture;
        Vector1 mOffset;
    };
    std::vector<BGTexture> mBGTextures;
    Vector1 mScreenSize;
    float mScrollSpeed;
};
