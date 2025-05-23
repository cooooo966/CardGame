#include "PlayFieldView.h"

USING_NS_CC;

PlayFieldView* PlayFieldView::create(const PlayFieldModel* model) {
    PlayFieldView* view = new (std::nothrow) PlayFieldView();
    if (view && view->init(model)) {
        view->autorelease();
        return view;
    }
    CC_SAFE_DELETE(view);
    return nullptr;
}

bool PlayFieldView::init(const PlayFieldModel* model) {
    if (!Node::init()) {
        return false;
    }

    _model = model;

    createCardViews();

    return true;
}

void PlayFieldView::createCardViews() {
    // 清理旧视图
    for (auto cardView : _cardViews) {
        this->removeChild(cardView);
    }
    if (_curHandCardView) {
        this->removeChild(_curHandCardView);
    }
    _cardViews.clear();
    _curHandCardView = nullptr;

    // 根据 model 创建并添加 CardView
    const auto& cards = _model->getCards();
    for (size_t i = 0; i < cards.size(); ++i) {
        CardView* cardView = CardView::create(cards[i]);
        if (cardView) {
            // 设置卡牌位置（横向排布）
            float spacing = 130.0f;
            cardView->setPosition(Vec2(i * spacing, 0));
            this->addChild(cardView);
            _cardViews.push_back(cardView);

            // 设置点击事件
            cardView->setOnClickCallback([this, cardView]() {
                if (_onCardClicked) {
                    _onCardClicked(cardView);
                }
               });
        }

    }

    if (_model->getCurHandCard()) {
        CardView* cardView = CardView::create(_model->getCurHandCard());
        cardView->setPosition(Vec2(500, 0));
        this->addChild(cardView);
        _curHandCardView = cardView;
    }
}

void PlayFieldView::refresh() {
    createCardViews();
}

void PlayFieldView::addCard(CardView* cardView) {
    _cardViews.push_back(cardView);
    this->addChild(cardView);
    refresh();
}

void PlayFieldView::removeCard(CardView* cardView) {
    auto it = std::find(_cardViews.begin(), _cardViews.end(), cardView);
    if (it != _cardViews.end()) {
        this->removeChild(cardView);
        _cardViews.erase(it);
        refresh();
    }
}

// 注意：需要补充 setOnCardClickedCallback 实现
// 放在 .cpp 文件尾部
void PlayFieldView::setOnCardClickedCallback(const std::function<void(CardView*)>& callback) {
    _onCardClicked = callback;
}
