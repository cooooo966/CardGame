#include "GameView.h"
#include"configs/AppConfig.h"
#include"utils/Utils.h"
#include"CardView.h"
#include"models/CardModel.h"
USING_NS_CC;

GameView* GameView::create() {
    GameView* ret = new (std::nothrow) GameView();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool GameView::init() {
    if (!Scene::init()) return false;

    _playFieldArea = LayerColor::create(hexToColor4B(STACK_CARD_AREA_COLOR), STACK_CARD_AREA_SIZE_WIDTH, STACK_CARD_AREA_SIZE_HEIGHT);
    _playFieldArea->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    _playFieldArea->setPosition(Vec2(0, 420));
    this->addChild(_playFieldArea,-2);

    _handCardArea = LayerColor::create(hexToColor4B(PLAY_FIELD_AREA_COLOR), PLAY_FIELD_AREA_SIZE_WIDTH, PLAY_FIELD_AREA_SIZE_HEIGHT);
    _handCardArea->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    _handCardArea->setPosition(Vec2(0, 0));
    this->addChild(_handCardArea,-2);

    /*
    _card = CardView::create(new CardModel(CST_SPADES, CFT_FIVE));
    _card->setPosition(Vec2(1000, 1000));
    this->addChild(_card);
    */
    return true;
}

bool GameView::addChildToScene(Node* view, const cocos2d::Vec2& position, const float scale, const cocos2d::Vec2& anchorPoint) {

    if (view) {
        this->addChild(view); // 添加到场景节点树
        view->setAnchorPoint(anchorPoint);
        view->setPosition(position);
        view->setScale(scale);
        return true;
    }
    return false;
}

bool GameView::addPlayFieldViewToScene(Node* view, const cocos2d::Vec2& position, const float scale, const cocos2d::Vec2& anchorPoint) {
    _playFieldView = view;
    return addChildToScene(view, position, scale, anchorPoint);
}

bool GameView::addLeftStackCardViewToScene(Node* view, const cocos2d::Vec2& position, const float scale, const cocos2d::Vec2& anchorPoint) {
    _leftStackCardView = view;
    return addChildToScene(view, position, scale, anchorPoint);
}

bool GameView::addRightStackCardViewToScene(Node* view, const cocos2d::Vec2& position, const float scale, const cocos2d::Vec2& anchorPoint) {
    _rightStackCardView = view;
    return addChildToScene(view, position, scale, anchorPoint);
}