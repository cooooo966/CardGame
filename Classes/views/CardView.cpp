#include "CardView.h"

USING_NS_CC;

CardView* CardView::create(CardModel* model) {
    CardView* ret = new (std::nothrow) CardView();
    if (ret && ret->init(model)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    ret = nullptr;
    return nullptr;
}

bool CardView::init(CardModel* model) {
    if (!Node::init()) return false;
    _model = model;

    // ±³¾°Í¼
    auto bg = Sprite::create("res/card_general.png");
    if (!bg) {
        CCLOG("CardView ¼ÓÔØ card_general.png Ê§°Ü£¡");
        return false;
    }

    this->addChild(bg);
    this->setContentSize(bg->getContentSize());

    // »¨É«Í¼
    std::string suitImg = "res/suits/" + model->getSuitName() + ".png";
    auto suitSprite = Sprite::create(suitImg);
    suitSprite->setPosition(Vec2(50, 100));
    this->addChild(suitSprite);

    //// Êý×ÖÍ¼
    std::string cardFace = model->getCardFaceString();
    std::string color = model->getCardColorString();
    std::string bigCardFaceImg = "res/number/big_" + color + "_" + cardFace + ".png";
    std::string smallCardFaceImg = "res/number/small_" + color + "_" + cardFace + ".png";
    auto bigCardFaceSprite = Sprite::create(bigCardFaceImg);
    bigCardFaceSprite->setPosition(Vec2(0, -20));
    this->addChild(bigCardFaceSprite);
    auto smallCardFaceSprite = Sprite::create(smallCardFaceImg);
    smallCardFaceSprite->setPosition(Vec2(-50, 100));
    this->addChild(smallCardFaceSprite);

    return true;
}

void CardView::setOnClickCallback(const std::function<void()>& callback) {
    CCLOG("CardView touched");
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this, callback](Touch* touch, Event* event) {
        Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
        Size size = this->getContentSize();
        Rect rect = Rect(0, 0, size.width, size.height);

        if (rect.containsPoint(locationInNode)) {
            callback();
            return true;
        }
        return false;
    };
    listener->setSwallowTouches(true); // ¿ÉÑ¡£º·ÀÖ¹´©Í¸
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}