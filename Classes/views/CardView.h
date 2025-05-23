#pragma once
#include"cocos2d.h"
#include"models/CardModel.h"

class CardView : public cocos2d::Node {
public:
    static CardView* create(CardModel* model);
    bool init(CardModel* model);

    void setOnClickCallback(const std::function<void()>& callback);

    CardModel* getModel() const { return _model; }

private:
    CardModel* _model;
};