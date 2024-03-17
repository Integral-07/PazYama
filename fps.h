#pragma once
#include "DxLib.h"

namespace fps {

	float DeltaTime;
	DeltaOp deltaOp;

	struct DeltaOp {

	private:
		long long Time;
		long long NowTime;

	public:

		void initDeltaTime();
		void setDeltaTime();
	};

	void DeltaOp::initDeltaTime() {

		DeltaTime = 0.000001f;
		Time = GetNowHiPerformanceCount();
		return;
	}

	void DeltaOp::setDeltaTime() {

		NowTime = GetNowHiPerformanceCount();
		DeltaTime = (NowTime - Time) / 1000000.0f;
		Time = NowTime;
		return;
	}
}