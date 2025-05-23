#include "StackCardView.h"

USING_NS_CC;

StackCardView* StackCardView::create(const StackCardModel* model, const CardDirectType cardDirect) {
    StackCardView* view = new (std::nothrow) StackCardView();
    if (view && view->init(model,cardDirect)) {
        view->autorelease();
        return view;
    }
    CC_SAFE_DELETE(view);
    return nullptr;
}

bool StackCardView::init(const StackCardModel* model, const CardDirectType cardDirect) {
    if (!Node::init()) {
        return false;
    }

    _model = model;
    _cardDirect = cardDirect;

    createCardViews();

    return true;
}

void StackCardView::createCardViews() {
    // 清理旧视图
    for (auto cardView : _cardViews) {
        this->removeChild(cardView);
    }
    _cardViews.clear();

    // 根据 model 创建并添加 CardView
    const auto& cards = _model->getCards();
    for (size_t i = 0; i < cards.size(); ++i) {
        CardView* cardView = CardView::create(cards[i]);
        if (cardView) {
            // 设置卡牌位置（斜向下排布）
            float spacingX = _cardDirect == CardDirectType::CDT_LEFT ? -60.0f:60.0f; // 横向间距
            float spacingY = -200.0f; // 纵向间距（负数表示向下）
            cardView->setPosition(Vec2(i * spacingX, i * spacingY));

            this->addChild(cardView);
            _cardViews.push_back(cardView);

        }

        //// 设置点击事件
        //cardView->setOnClickCallback([this, cardView]() {
        //    if (_onCardClicked) {
        //        _onCardClicked(cardView);
        //    }
        //    });
    }
}

void StackCardView::refresh() {
    createCardViews();
}

void StackCardView::addCard(CardView* cardView) {
    _cardViews.push_back(cardView);
    this->addChild(cardView);
    refresh();
}

void StackCardView::removeCard(CardView* cardView) {
    auto it = std::find(_cardViews.begin(), _cardViews.end(), cardView);
    if (it != _cardViews.end()) {
        this->removeChild(cardView);
        _cardViews.erase(it);
        refresh();
    }
}

// 注意：需要补充 setOnCardClickedCallback 实现
// 放在 .cpp 文件尾部
//void PlayFieldView::setOnCardClickedCallback(const std::function<void(CardView*)>& callback) {
//    _onCardClicked = callback;
//}
