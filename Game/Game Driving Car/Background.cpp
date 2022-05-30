#include "Background.h"
#include "Actor.h"

Background::Background(class Actor* owner, int drawOrder)
    :SpriteComponent(owner, drawOrder)
    ,mScrollSpeed(0.0f)
{
}

void Background::Update(float deltaTime)
{
    SpriteComponent::Update(deltaTime);
    
    for (auto& background: mBGTextures)
        {
            background.mOffset.y -= mScrollSpeed*deltaTime;
            if (background.mOffset.y > 768)
                {
                    background.mOffset.y = -768;
                }
        }
}

void Background::Draw(SDL_Renderer* renderer)
{
    for (auto& background : mBGTextures)
        {
            SDL_Rect r;
            r.w = static_cast<int>(mScreenSize.x);
            r.h = static_cast<int>(mScreenSize.y);
            r.x = static_cast<int>(mOwner->GetPosition().x - r.w/2 + background.mOffset.x);
            r.y = static_cast<int>(mOwner->GetPosition().y - r.h/2 + background.mOffset.y);

//            Draw this background
            SDL_RenderCopy(renderer,background.mTexture,nullptr,&r);
        }
}

void Background::SetBGTextures(const std::vector<SDL_Texture *> &textures)
{
    int count = 0;
    for (auto tex: textures)
        {
            BGTexture temp;
            temp.mTexture = tex;
            temp.mOffset.x = 0;
            temp.mOffset.y -= count*(mScreenSize.y);
            mBGTextures.emplace_back(temp);
            count++;
        }
}
