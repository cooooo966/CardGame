#pragma once
#include"CardModel.h"
#include"cocos2d.h"

// 表示一条回退记录
struct UndoData {
    CardModel* movedCard;
    CardModel* replacedCard;
    cocos2d::Vec2 originalPosition;
    std::string fromZone;
};

class UndoModel:public cocos2d::Ref {
public:
    static UndoModel* create(const std::vector<UndoData>& _cards = {});
    bool Init(const std::vector<UndoData>& _cards = {});

    std::vector<UndoData> getUndoStack() const { return _undoStack; }

    void recordUndo(CardModel* moved, CardModel* replaced, const std::string& fromZone,const cocos2d::Vec2 origin);
    void removeUndo();

private:
    std::vector<UndoData> _undoStack;
};
