#include "GAME.h"
#include "TITLE.h"
#include "PLAY.h"
#include "key.h"
#include "CONTAINER.h"


GAME::GAME()
{
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[PLAY_ID] = new PLAY(this);
	Scenes[RESULT_ID] = new RESULT(this);
	CurSceneId = TITLE_ID;
}

GAME::~GAME()
{
	for (int i = 0; i < NUM_SCENES; i++) {

		delete Scenes[i];
	}
}

void GAME::run()
{
	Container->load();
	Scenes[TITLE_ID]->create();

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		Scenes[CurSceneId]->proc();
		ScreenFlip();

		KeyUpdate();
	}
}

void GAME::changeScene(SCENE_ID sceneId)
{
	if (KeyClick(KEY_INPUT_A)) {

		CurSceneId = sceneId;
	}
}
