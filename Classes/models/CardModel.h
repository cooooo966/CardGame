#pragma once
#include<string>
#include"configs/CardConfig.h"
#include"cocos2d.h"

class CardModel :public cocos2d::Ref
{
public:
	CardModel(CardSuitType suit = CST_NONE, CardFaceType cardFace = CFT_NONE);

	static CardModel* create(CardSuitType suit, CardFaceType face);
	//bool Init(CardSuitType suit, CardFaceType face);

	CardSuitType getSuit() const { return _suit; }
	CardFaceType getNumber() const { return _cardFace; }
	CardColorType getColor() const { return _color; }

	//���ڻ�ȡͼƬ·��
	std::string getSuitName() const;
	//���ڻ�ȡͼƬ·��
	std::string getCardFaceString() const;
	//���ڻ�ȡͼƬ·��
	std::string getCardColorString() const;

	// std::string toString() const;

	// ���л��ӿ�
	// std::string toJson() const;
	// static CardModel fromJson(const std::string& json);

private:
	CardSuitType _suit;
	CardFaceType _cardFace;
	CardColorType _color;
};