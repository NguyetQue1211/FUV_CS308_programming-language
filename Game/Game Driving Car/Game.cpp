#include "Game.h"
#include "SDL2_image/SDL_image.h"
#include "Background.h"
#include "PlayerCar.h"
#include "GrayCar.h"

#include "iostream"
using namespace std;

Game::Game()
:mWindow(nullptr)
,mRenderer(nullptr)
,mIsRunning(true)
,mUpdatingActors(false)
{

}

bool Game::Initialize()
{
    // Initialize SDL
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    // Create an SDL Window
    mWindow = SDL_CreateWindow("Driving Car", 100, 100, 1024, 768, 0);

    if (!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    // Create SDL renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!mRenderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }
    
    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
        return false;
    }
    
    //Initialize SDL_mixer
    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        SDL_Log("SDL_mixer could not initialize! SDL_mixer Error: %s", Mix_GetError());
        return false;
    }
    
    LoadData();

    mTicksCount = SDL_GetTicks();
    
    return true;
}


void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput()
{
    SDL_Event event;
    //While application is running
    while( SDL_PollEvent( &event ) != 0 )
    {
        //User requests quit
        if( event.type == SDL_QUIT )
        {
            mIsRunning = false;
            break;
        }
        //Handle key press
        else if( event.type == SDL_KEYDOWN )
        {
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                if (!Mix_Playing(-1))
                    Mix_PlayChannel(-1, mMusic, 0);
            }
            break;
        }
    }
    
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if (keyState[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
    }
    
    mUpdatingActors = true;
    for (auto actor : mActors)
    {
        actor->ProcessInput(keyState);
    }
    mUpdatingActors = false;
}

void Game::UpdateGame()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
    
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }
    mTicksCount = SDL_GetTicks();

    // Update all actors
    mUpdatingActors = true;
    for (auto actor : mActors)
    {
        actor->Update(deltaTime);
    }
    mUpdatingActors = false;

    // Move any pending actors to mActors
    for (auto pending : mPendingActors)
    {
        mActors.emplace_back(pending);
    }
    mPendingActors.clear();
    
    std::vector<Actor*> deadActors;
    for (auto actor : mActors)
    {
        if (actor->GetState() == Actor::EDead)
        {
            deadActors.emplace_back(actor);
        }
    }

    // Delete dead actors (which removes them from mActors)
    for (auto actor : deadActors)
    {
        delete actor;
    }

}

void Game::GenerateOutput()
{
    
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
        
    // Draw all sprite components
    for (auto sprite : mSprites)
    {
        sprite->Draw(mRenderer);
    }

    SDL_RenderPresent(mRenderer);
    
}

void Game::LoadData()
{
    mPlayerCar = new PlayerCar(this);
    mPlayerCar->SetPosition(Vector1(400.0f, 650));
    mPlayerCar->SetScale(0.3f);
    
    mGrayCar1 = new GrayCar(this);
    mGrayCar1->SetPosition(Vector1(250.0f, -100));
    mGrayCar1->SetScale(0.3f);
    mGrayCar1->SetScrollSpeed(-1000.0f);

    mGrayCar2 = new GrayCar(this);
    mGrayCar2->SetPosition(Vector1(600.0f, -100));
    mGrayCar2->SetScale(0.3f);
    mGrayCar2->SetScrollSpeed(-700.0f);

    mGrayCar3 = new GrayCar(this);
    mGrayCar3->SetPosition(Vector1(750.0f, -100));
    mGrayCar3->SetScale(0.3f);
    mGrayCar3->SetScrollSpeed(-800.0f);
    
    mGrayCar4 = new GrayCar(this);
    mGrayCar4->SetPosition(Vector1(400.0f, -100));
    mGrayCar4->SetScale(0.3f);
    mGrayCar4->SetScrollSpeed(-750.0f);

    Actor* temp = new Actor(this);
    temp->SetPosition(Vector1(512.0f, 384.0f));
    Background* bg = new Background(temp);
    bg->SetScreenSize(Vector1(1024.0f, 768.0f));
    std::vector<SDL_Texture*> bgtexs = {GetTexture("background.png"),
        GetTexture("background1.png")
    };
    bg->SetBGTextures(bgtexs);
    bg->SetScrollSpeed(-200.0f);
    
    //Load music
    mMusic = Mix_LoadWAV("background.wav");
}

void Game::UnloadData()
{
    while (!mActors.empty())
        {
            delete mActors.back();
        }

        // Destroy textures
        for (auto i : mTextures)
        {
            SDL_DestroyTexture(i.second);
        }
        mTextures.clear();
}

SDL_Texture* Game::GetTexture(const std::string &fileName)
{
    SDL_Texture* tex = nullptr;
    auto iter = mTextures.find(fileName);
    if (iter != mTextures.end())
        {
            tex = iter->second;
        }
    else {
        SDL_Surface* surf = IMG_Load(fileName.c_str());
        if (!surf)
            {
                SDL_Log("Failed to load texture file %s", fileName.c_str());
                return nullptr;
            }
        SDL_SetColorKey(surf,SDL_TRUE,SDL_MapRGB(surf->format,0xFF,0,0xFF));
        tex = SDL_CreateTextureFromSurface(mRenderer, surf);
        SDL_FreeSurface(surf);
        if (!tex)
            {
                SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
                return nullptr;
            }
        
        mTextures.emplace(fileName.c_str(), tex);
        mTextures.emplace(fileName, tex);
    }
    return tex;
}

void Game::Shutdown()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::AddActor(Actor* actor)
{
    if (mUpdatingActors)
        {
            mPendingActors.emplace_back(actor);
        }
    else {
        mActors.emplace_back(actor);
    }
}

void Game::RemoveActor(Actor* actor)
{
    //pass
    auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
    if (iter != mPendingActors.end())
        {
            // Swap to end of vector and pop off (avoid erase copies)
            std::iter_swap(iter, mPendingActors.end() - 1);
            mPendingActors.pop_back();
        }

        // Is it in actors?
    iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end())
        {
            // Swap to end of vector and pop off (avoid erase copies)
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
        }
}

void Game::AddSprite(SpriteComponent* sprite)
{
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (;iter != mSprites.end(); ++iter)
        {
            if (myDrawOrder < (*iter)->GetDrawOrder())
                {
                    break;
                }
        }
    //Inserts element before position of iterator
    mSprites.insert(iter, sprite);
};

void Game::RemoveSprite(SpriteComponent* sprite)
{
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}

