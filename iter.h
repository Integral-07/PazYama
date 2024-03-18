#pragma once
#include <vector>

void iter_swap(std::vector<class Actor*>::iterator& iter_1, std::vector<class Actor*>::iterator& iter_2){

	auto& temp = iter_1;
	iter_1 = iter_2;
	iter_2 = temp;

	return;
}

void iter_swap(std::vector<class SpriteComponent*>::iterator& iter_1, std::vector<class SpriteComponent*>::iterator& iter_2) {

	auto& temp = iter_1;
	iter_1 = iter_2;
	iter_2 = temp;

	return;
}