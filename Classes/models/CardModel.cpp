#include"CardModel.h"

CardModel::CardModel(CardSuitType suit, CardFaceType cardFace)
	:_suit(suit),_cardFace(cardFace)
{
    if (_suit == CardSuitType::CST_CLUBS || _suit == CardSuitType::CST_SPADES) {
        _color = CardColorType::CCT_BLACK;
    }
    else {
        _color = CardColorType::CCT_RED;
    }
}

CardModel* CardModel::create(CardSuitType suit, CardFaceType face) {
    CardModel* ret = new CardModel(suit, face);
    if (ret) {
        ret->autorelease();  
        return ret;
    }
    delete ret;
    return nullptr;
}

std::string CardModel::getSuitName() const{
    switch (_suit) {
        case CardSuitType::CST_HEARTS: return "heart";
        case CardSuitType::CST_DIAMONDS: return "diamond";
        case CardSuitType::CST_CLUBS: return "club";
        case CardSuitType::CST_SPADES: return "spade";
    }
    return "UNKNOWN";
}

/*
* @TODO:¿¨Ãæ×ª×Ö·û´®
*/
std::string CardModel::getCardFaceString() const{
    static const char* faceStrings[] = {
        "A", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "J", "Q", "K"
    };

    if (_cardFace > CFT_NONE && _cardFace < CFT_NUM_CARD_FACE_TYPES) {
        return faceStrings[_cardFace];
    }
    return "UNKNOWN";
}

std::string CardModel::getCardColorString() const {
    switch (_color) {
    case CardColorType::CCT_RED: return "red";
    case CardColorType::CCT_BLACK: return "black";
    }
    return "UNKNOWN";
}