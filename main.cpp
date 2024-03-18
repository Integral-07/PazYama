#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);                         //�E�B���h�E���[�h�ɐݒ�
	SetOutApplicationLogValidFlag(FALSE);           //log.txt�̔�o��
	SetGraphMode(GameWidth, GameHeight, GameColor); //�𑜓x
	SetWindowSize(GameWidth, GameHeight);
	SetMainWindowText(GameTitle);
	SetAlwaysRunFlag(TRUE);

	Game game;
	bool success = game.Initialize();

	if (success) {

		game.RunLoop();
	}
	game.Shutdown();


	return 0;
}