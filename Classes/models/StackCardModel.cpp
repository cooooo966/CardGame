#include"StackCardModel.h"
#include<algorithm>

void StackCardModel::removeCard(const CardModel* card) {
    auto it = std::find(_cards.begin(), _cards.end(), card);
    if (it != _cards.end()) {
        _cards.erase(it);
    }
}

StackCardModel* StackCardModel::create(const std::vector<CardModel*>& cards) {
    StackCardModel* ret = new StackCardModel();
    if (ret && ret->Init(cards)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool StackCardModel::Init(const std::vector<CardModel*>& cards) {
    _cards = cards;
    return true;
}