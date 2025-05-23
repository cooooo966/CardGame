#pragma once
#include"cocos2d.h"
#include"models/PlayFieldModel.h"
#include"CardView.h"

class PlayFieldView : public cocos2d::Node {
public:
    static PlayFieldView* create(const PlayFieldModel* model);

    bool init(const PlayFieldModel* model);

    // ע�����ص������ĳ�� CardView ʱ����
    void setOnCardClickedCallback(const std::function<void(CardView*)>& callback);

    void refresh(); // ���²������п���
    void addCard(CardView* cardView);
    void removeCard(CardView* cardView);

private:
    const PlayFieldModel* _model = nullptr;
    std::vector<CardView*> _cardViews;
    CardView* _curHandCardView;

    std::function<void(CardView*)> _onCardClicked = nullptr;

    void createCardViews();

};
