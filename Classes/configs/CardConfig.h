#pragma once

//栈卡牌排列方向
enum CardDirectType
{
    CDT_NONE = -1,
    CDT_LEFT,      //左下
    CDT_RIGHT,     //右下
    CDT_LANDSCAPE, //横向
    CDT_CARD_DIRECT_TYPES
};

// 花色类型
enum CardSuitType
{
    CST_NONE = -1,
    CST_CLUBS,      // 梅花
    CST_DIAMONDS,   // 方块
    CST_HEARTS,     // 红桃
    CST_SPADES,     // 黑桃
    CST_NUM_CARD_SUIT_TYPES
};

// 卡牌颜色
enum CardColorType
{
    CCT_NONE = -1,
    CCT_RED,      // 红色
    CCT_BLACK,   // 黑色
    CST_NUM_CARD_Color_TYPES
};

// 正面类型
enum CardFaceType
{
    CFT_NONE = -1,
    CFT_ACE,
    CFT_TWO,
    CFT_THREE,
    CFT_FOUR,
    CFT_FIVE,
    CFT_SIX,
    CFT_SEVEN,
    CFT_EIGHT,
    CFT_NINE,
    CFT_TEN,
    CFT_JACK,
    CFT_QUEEN,
    CFT_KING,
    CFT_NUM_CARD_FACE_TYPES
};
