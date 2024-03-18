#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);                         //ウィンドウモードに設定
	SetOutApplicationLogValidFlag(FALSE);           //log.txtの非出力
	SetGraphMode(GameWidth, GameHeight, GameColor); //解像度
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