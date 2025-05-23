#pragma once
#include"cocos2d.h"
#include"models/StackCardModel.h"
#include"views/StackCardView.h"

class StackCardController:public cocos2d::Ref {
public:
    static StackCardController* create(StackCardModel* model = nullptr, CardDirectType cardDirect=CardDirectType::CDT_LEFT);
    bool init(StackCardModel* model = nullptr, CardDirectType cardDirect = CardDirectType::CDT_LEFT);
    void onCardClicked(CardView* cardView);
    void addCard(CardModel* card);
    void removeCard(CardModel* card);

    StackCardView* getView() const { return _view; }
    StackCardModel* getModel() const { return _model; }

private:
    StackCardModel* _model = nullptr;
    StackCardView* _view = nullptr;
};