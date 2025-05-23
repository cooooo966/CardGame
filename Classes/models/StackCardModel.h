#pragma once
#include<vector>
#include"CardModel.h"
#include"cocos2d.h"

class StackCardModel:public cocos2d::Ref {
public:
	const std::vector<CardModel*>& getCards() const { return _cards; }

	void addCard(CardModel* card) { _cards.emplace_back(card); }
	void removeCard(const CardModel* card); // 可选实现

	static StackCardModel* create(const std::vector<CardModel*>& _cards = {});
	bool Init(const std::vector<CardModel*>& _cards = {});

private:
	std::vector<CardModel*> _cards;
};