#include "Game.h"
#include "GrayCar.h"
#include "CarSpriteComponent.h"

GrayCar::GrayCar(Game* game)
    :Actor(game)
    ,mScrollSpeed(0.0f)
{
    // Create an animated sprite component
    CarSpriteComponent* car = new CarSpriteComponent(this);
    std::vector<SDL_Texture*> cartex = {game->GetTexture("/Users/phanque/Desktop/Game/Game/GrayCar.png")};
    car->SetCarTextures(cartex);
}

void GrayCar::UpdateActor(float deltaTime)
{
    Actor::UpdateActor(deltaTime);
    Vector1 pos = GetPosition();
    if (pos.y > 768)
    {
        pos.y = -100;
    } else {
        pos.y -= mScrollSpeed*deltaTime;
    }
    SetPosition(pos);
}
