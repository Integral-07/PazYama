#pragma once
#include "TITLE.h"
#include "PLAY.h"
#include "DROP.h"

class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		//PLAY::DATA play;

		DROP::DATA drop;
	};
	DATA Data;

public:
	void load();
	void setData();
	TITLE::DATA& title() { return Data.title; }
	DROP::DATA& drop() { return Data.drop; }
};

