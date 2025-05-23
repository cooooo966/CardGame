#pragma once
#include<vector>
#include"CardModel.h"
#include"cocos2d.h"

class PlayFieldModel :public cocos2d::Ref {
public:
	const std::vector<CardModel*>& getCards() const { return _cards; }
	CardModel* getCurHandCard() const { return _curHandCard; }
	bool setCurHandCard(CardModel* card);

	void addCard(CardModel* card) { _cards.emplace_back(card); }
	void removeCard(const CardModel* card); // 可选实现

	static PlayFieldModel* create(const std::vector<CardModel*>& _cards = {});
	bool Init(const std::vector<CardModel*>& _cards = {});

	void initCurHandCard();

private:
	std::vector<CardModel*> _cards;
	CardModel* _curHandCard;
};
