#include "Game.h"
#include "PlayerCar.h"
#include "CarSpriteComponent.h"
#include "InputComponent.h"

PlayerCar::PlayerCar(Game* game)
    :Actor(game)
{
    // Create an animated sprite component
    CarSpriteComponent* car = new CarSpriteComponent(this);
    std::vector<SDL_Texture*> cartex = {game->GetTexture("PlayerCar.png")};
    car->SetCarTextures(cartex);
    
    // Create an input component and set keys/speed
    InputComponent* ic = new InputComponent(this);
    ic->SetForwardKey(SDL_SCANCODE_DOWN);
    ic->SetBackKey(SDL_SCANCODE_UP);
    ic->SetRightKey(SDL_SCANCODE_RIGHT);
    ic->SetLeftKey(SDL_SCANCODE_LEFT);
    ic->SetClockwiseKey(SDL_SCANCODE_A);
    ic->SetCounterClockwiseKey(SDL_SCANCODE_D);
    ic->SetMaxVerticalSpeed(300.0f);
    ic->SetMaxAngularSpeed(Math::Pi/3);
    ic->SetMaxHorizontalSpeed(300.0f);
}
