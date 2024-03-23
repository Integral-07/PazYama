#include "Game.h"
#include "Actor.h"
#include "Dxlib.h"
#include "iter.h"
#include "fps.h"
#include "Drop.h"
#include "Selector.h"
#include <random>
#include "Key.h"

bool Game::Initialize()
{
    if (DxLib_Init() == -1) {

        return false;
    }


    Drop* a;
    
    srand(time(NULL));

    std::vector<Drop*> temp_drop;
    for (int i = 0; i < PuzSize + 2; i++) {
        for (int j = 0; j < PuzSize + 2; j++) {

            if (i == 0 || i == PuzSize + 1 || j == 0 || j == PuzSize + 1) {

                auto a = new Drop(this, Drop::SENTINEL);
                a->SetPosition(VECTOR2(a->GetScaleW() * (j + 1), a->GetScaleH() * (i + 1)));
                a->SetPositionOnBoard(VECTOR2(i, j));
                mDrops[i][j] = Drop::SENTINEL;
                mDropsArray[i][j] = a;
                temp_drop.emplace_back(a);

                continue;
            }

            int kind = rand() % Drop::NUM_DROPS;
            a = new Drop(this, kind);
            a->SetPosition(VECTOR2(a->GetScaleW() * (j + 1), a->GetScaleH() * (i + 1)));
            a->SetPositionOnBoard(VECTOR2(i, j));
            //a->SetDirection(VECTOR2(0, 1));
            //a->SetSpeed(100);
            mDrops[i][j] = kind;
            mDropsArray[i][j] = a;
            temp_drop.emplace_back(a);
        }
    }

    

    auto sr = new Selector(this);

    mGameState = EPuz;//ETitle;

    fps::initDeltaTime();
    KeyInit();

    return true;
}

void Game::RunLoop()
{
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        ProcessInput();
        UpdateGame();
        GenerateOutput();

        KeyUpdate();
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
    if (mGameState == EPuz) {


        mUpdatingActors = true;
        for (auto actor : mActors) {

            actor->ProcessInput();
        }

        mUpdatingActors = false;

        KeyUpdate();
        if (KeyDown(KEY_INPUT_ESCAPE)) {

            mGameState = EPaused;
        }
    }
    else {

        if (KeyDown(KEY_INPUT_ESCAPE)) {

            mGameState = EPuz;
        }
    }
}

void Game::UpdateGame()
{
    fps::setDeltaTime();

    if (mGameState == EPuz || mGameState == EComb || mGameState == EFall) {


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

                auto iter = std::find(mActors.begin(), mActors.end(), actor);
                mActors.erase(iter);
            }
        }

        for (auto actor : deadActors) {

            delete actor;
        }
    }
    
    if(mGameState == EComb){
        /*
        bool flag = true;
        for (int i = 0; i < PuzSize + 2; i++) {
            for (int j = 0;j < PuzSize + 2;j++) {

                if (mDropsArray[i][j]->GetAlignedFlag() 
                    && mDropsArray[i][j]->GetKind() != Drop::NONE) {

                    //mDropsArray[i][j]->SetAlignedFlag(false);
                    flag = false;
                    break;
                }
            }
        }
        */
        //DrawFormatString(10, 10, GetColor(0, 255, 0), "%d", mGameState);

        if (KeyClick(KEY_INPUT_SPACE)) {

            mGameState = EFall;
        }
    }
    else if (mGameState == EFall) {

        if (KeyClick(KEY_INPUT_SPACE)) {

            mGameState = EPuz;
        }
    }
}

void Game::GenerateOutput()
{
    for (auto sprite : mSprites) {

        sprite->Draw();
    }

#if debug true
    DrawBox(0,0,40*PuzSize, 40*PuzSize, GetColor(255,255,255), true);
    for (int i = 0; i < PuzSize + 2; i++) {
        for (int j = 0;j < PuzSize + 2;j++) {

            DrawFormatString(j * 30, i * 30, GetColor(0, 0, 0), "%d", (int)mDropsArray[i][j]->GetKind());
        }
    }
#endif
    ScreenFlip();
}

void Game::AddScore(int score)
{
    mScore += score;
}

