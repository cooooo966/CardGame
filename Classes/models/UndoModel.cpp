#include"UndoModel.h"

USING_NS_CC;

UndoModel* UndoModel::create(const std::vector<UndoData>& cards) {
    UndoModel* ret = new UndoModel();
    if (ret && ret->Init(cards)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool UndoModel::Init(const std::vector<UndoData>& cards) {
    _undoStack = cards;
    return true;
}

void UndoModel::recordUndo(CardModel* moved, CardModel* replaced, const std::string& fromZone, const Vec2 origin) {
    UndoData data;
    data.movedCard = moved;     // È¥µô const ÐÞÊÎ·û
    data.replacedCard = replaced; // ÔÊÐíÎª¿Õ
    data.fromZone = fromZone;
    data.originalPosition = origin;

    _undoStack.push_back(data);
}

void UndoModel::removeUndo() {
    if (!_undoStack.empty()) {
        _undoStack.pop_back();
    }
}