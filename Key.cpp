#include"key.h"

int NowKeyPressFrame[KeyKindMax];
int PreviousKeyPressFrame[KeyKindMax];

//初期化
void KeyInit() {

	for (int i = 0; i < KeyKindMax; i++) {

		NowKeyPressFrame[i] = 0;
		PreviousKeyPressFrame[i] = 0;
	}

	return;
}

//更新
void KeyUpdate() {

	//一時的に保持するキー情報
	char KeyState[KeyKindMax];

	//すべてのキー情報を一度に取得
	GetHitKeyStateAll(KeyState);

	//キー情報を更新
	for (int i = 0; i < KeyKindMax; i++) {

		PreviousKeyPressFrame[i] = NowKeyPressFrame[i];

		//現在、押されているとき
		if (KeyState[i] > 0) {
			//押されているフレーム数をカウントアップ

			NowKeyPressFrame[i]++;
		}

		else if (KeyState[i] == 0) {

			//押されていなければ、フレーム数をゼロクリア
			NowKeyPressFrame[i] = 0;
		}
	}

	return;
}

//特定のキーを押したか
bool KeyDown(int KEY_INPUT_) {

	if (NowKeyPressFrame[KEY_INPUT_] > 0) {

		return true;
	}
	{
		return false;
	}
}


bool KeyClick(int KEY_INPUT_) {

	if (NowKeyPressFrame[KEY_INPUT_] == 0 && PreviousKeyPressFrame[KEY_INPUT_] > 0) {

		return true;
	}
	{
		return false;
	}
}



//フレーム数で返る
int KeyPressFrame(int KEY_INPUT_) {

	return NowKeyPressFrame[KEY_INPUT_];
}