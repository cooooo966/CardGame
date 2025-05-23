#pragma once
#include"models/PlayFieldModel.h"
#include"views/CardView.h"
#include"views/PlayFieldView.h"
#include"cocos2d.h"
#include"models/UndoModel.h"

class PlayFieldController:public cocos2d::Ref {
public:
    static PlayFieldController* create(PlayFieldModel* model=nullptr, UndoModel* undo=nullptr);
    bool init(PlayFieldModel* model=nullptr, UndoModel* undo = nullptr);
    void onCardClicked(CardView* cardView);
    void addCard(CardModel* card);
    void removeCard(CardModel* card);

    PlayFieldView* getView() const { return _view; }
    PlayFieldModel* getModel() const { return _model; }
    UndoModel* getUndo() const { return _undo; }

    //void onCardClicked(CardView* cardView);

private:
    PlayFieldModel* _model = nullptr;
    PlayFieldView* _view = nullptr;
    UndoModel* _undo = nullptr;
};
