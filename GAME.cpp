#include "Game.h"
#include "Actor.h"
#include "Dxlib.h"
#include "iter.h"
#include "fps.h"
#include "Drop.h"

bool Game::Initialize()
{
    if (DxLib_Init() == -1) {

        return false;
    }

    Actor* a;
    for (int i = 0; i < PuzSize; i++) {
        for (int j = 0; j < PuzSize; j++) {

            a = new Drop(this);
            a->SetPosition(VECTOR2(a->GetScale() * (j + 1), a->GetScale() * (i + 1)));
        }
    }


    fps::initDeltaTime();

    return true;
}

void Game::RunLoop()
{
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown()
{
    while (!mActors.empty()) {

        delete mActors.back();
    }

    DxLib_End();
}

void Game::AddActor(Actor* actor)
{
    if (mUpdatingActors) {
        
        mPendingActors.emplace_back(actor);
    }
    else {

        mActors.emplace_back(actor);
    }
}

void Game::RemoveActor(Actor* actor)
{
    auto iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end()) {

        auto iter_end = mActors.end() - 1;
        iter_swap(iter, iter_end);
        mActors.pop_back();
    }
}

void Game::AddSprite(SpriteComponent* sprite)
{
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (; iter != mSprites.end(); iter++) {

        if (myDrawOrder < (*iter)->GetDrawOrder()) {

            break;
        }
    }

    mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}

void Game::ProcessInput()
{
    mUpdatingActors = true;
    for (auto actor : mActors) {

        actor->ProcessInput();
    }

    mUpdatingActors = false;
}

void Game::UpdateGame()
{
    fps::setDeltaTime();

    mUpdatingActors = true;
    for (auto actor : mActors) {

        actor->Update();
    }

    mUpdatingActors = false;

    for (auto pending : mPendingActors) {

        mActors.emplace_back(pending);
    }

    mPendingActors.clear();

    std::vector<class Actor*> deadActors;
    for (auto actor : mActors) {

        if (actor->GetState() == Actor::EDead) {

            deadActors.emplace_back(actor);
        }
    }

    for (auto actor : deadActors) {

        delete actor;
    }
}

void Game::GenerateOutput()
{
    for (auto sprite : mSprites) {

        sprite->Draw();
    }
    ScreenFlip();
}

void Game::AddScore(int score)
{
    mScore += score;
}

void Game::AddDrop(Drop* drop)
{
    mDrops.emplace_back();
}

void Game::RemoveDrop(Drop* drop)
{
    mDrops.pop_back();
}


