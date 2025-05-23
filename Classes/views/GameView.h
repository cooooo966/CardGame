#pragma once
#include"cocos2d.h"

class GameView : public cocos2d::Scene {
public:
    static GameView* create();
    virtual bool init();

    cocos2d::Node* getPlayFieldArea() const { return _playFieldArea; }
    cocos2d::Node* getHandCardArea() const { return _handCardArea; }

    cocos2d::Node* getPlayFieldView() const { return _playFieldView; }
    cocos2d::Node* getLeftStackCardView() const { return _leftStackCardView; }
    cocos2d::Node* getRightStackCardView() const { return _rightStackCardView; }

    bool addChildToScene(Node* view,const cocos2d::Vec2& position,const float scale=1.0f,const cocos2d::Vec2& anchorPoint= cocos2d::Vec2::ZERO);
    bool addPlayFieldViewToScene(Node* view, const cocos2d::Vec2& position, const float scale = 1.0f, const cocos2d::Vec2& anchorPoint = cocos2d::Vec2::ZERO);
    bool addLeftStackCardViewToScene(Node* view, const cocos2d::Vec2& position, const float scale = 1.0f, const cocos2d::Vec2& anchorPoint = cocos2d::Vec2::ZERO);
    bool addRightStackCardViewToScene(Node* view, const cocos2d::Vec2& position, const float scale = 1.0f, const cocos2d::Vec2& anchorPoint = cocos2d::Vec2::ZERO);

private:
    cocos2d::Node* _playFieldView = nullptr;
    cocos2d::Node* _leftStackCardView = nullptr;
    cocos2d::Node* _rightStackCardView = nullptr;

    cocos2d::Node* _playFieldArea = nullptr;
    cocos2d::Node* _handCardArea = nullptr;
};