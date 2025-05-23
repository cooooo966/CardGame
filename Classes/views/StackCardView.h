#pragma once
#include"cocos2d.h"
#include"CardView.h"
#include"models/StackCardModel.h"
#include"configs/CardConfig.h"

class StackCardView : public cocos2d::Node {
public:
    static StackCardView* create(const StackCardModel* model,const CardDirectType cardDirect= CardDirectType::CDT_LEFT);

    bool init(const StackCardModel* model, const CardDirectType cardDirect);

    // ע�����ص������ĳ�� CardView ʱ����
    //void setOnCardClickedCallback(const std::function<void(CardView*)>& callback);

    void refresh(); // ���²������п���
    void addCard(CardView* cardView);
    void removeCard(CardView* cardView);

private:
    const StackCardModel* _model = nullptr;
    std::vector<CardView*> _cardViews;

    std::function<void(CardView*)> _onCardClicked = nullptr;

    CardDirectType _cardDirect = CardDirectType::CDT_LEFT;

    void createCardViews();
};