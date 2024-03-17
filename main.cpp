#include "GAME.h"

#define GameWidth 1000
#define GameHeight 1000
#define GameTitle "PazYama"
#define GameColor 32

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);                         //ウィンドウモードに設定
	SetOutApplicationLogValidFlag(FALSE);           //log.txtの非出力
	SetGraphMode(GameWidth, GameHeight, GameColor); //解像度
	SetWindowSize(GameWidth, GameHeight);
	SetMainWindowText(GameTitle);
	SetAlwaysRunFlag(TRUE);

	//SetWindowIconID();
	if (DxLib_Init() == -1) {

		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK); //ダブルバッファリング
	SetBackgroundColor(100, 100, 100);

	GAME game;
	game.run();

	DxLib_End();
	return 0;
}