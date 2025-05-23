#include "PlayFieldModel.h"
#include <algorithm>

void PlayFieldModel::removeCard(const CardModel* card) {
    auto it = std::find(_cards.begin(), _cards.end(), card);
    if (it != _cards.end()) {
        _cards.erase(it);
    }
}

PlayFieldModel* PlayFieldModel::create(const std::vector<CardModel*>& cards) {
    PlayFieldModel* ret = new PlayFieldModel();
    if (ret && ret->Init(cards)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool PlayFieldModel::Init(const std::vector<CardModel*>& cards) {
    _cards = cards;
    initCurHandCard();
    return true;
}

void PlayFieldModel::initCurHandCard() {
    if (!_cards.empty()) {
        int index = _cards.size() - 1;
        _curHandCard = _cards[index];
        removeCard(_curHandCard);
    }
}

bool PlayFieldModel::setCurHandCard(CardModel* card) {
    _curHandCard = card;
    return true;
}
