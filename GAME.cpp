#include "Game.h"
#include "Actor.h"
#include "Dxlib.h"
#include "iter.h"
#include "fps.h"
#include "Drop.h"
#include "Selector.h"
#include <random>

bool Game::Initialize()
{
    if (DxLib_Init() == -1) {

        return false;
    }

    Drop* a;
    
    srand(time(NULL));
    for (int i = 0; i < PuzSize + 2; i++) {
        for (int j = 0; j < PuzSize + 2; j++) {

            if (i == 0 || i == PuzSize + 1 || j == 0 || j == PuzSize + 1) {

                auto a = new Drop(this, Drop::SENTINEL);
                a->SetPosition(VECTOR2(a->GetScaleW() * (j + 1), a->GetScaleH() * (i + 1)));
                a->SetPositionOnBoard(VECTOR2(i, j));
                mDrops.emplace_back(a);

                continue;
            }

            a = new Drop(this, rand() % Drop::NUM_DROPS);
            a->SetPosition(VECTOR2(a->GetScaleW() * (j + 1), a->GetScaleH() * (i + 1)));
            a->SetPositionOnBoard(VECTOR2(i, j));
            mDrops.emplace_back(a);
        }
    }

    auto sr = new Selector(this);
    sr->SetPosition(VECTOR2(0, 0));
    sr->SetScaleW(70);
    sr->SetScaleH(70);

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

void Game::DeleteDrop(Drop* drop)
{
    auto iter = std::find(mDrops.begin(), mDrops.end(), drop);
    if (iter != mDrops.end()) {

        //auto iter_end = mDrops.end() - 1;
        //iter_swap(iter, iter_end);
        //mDrops.pop_back();
        mDrops.erase(iter);
    }
}
