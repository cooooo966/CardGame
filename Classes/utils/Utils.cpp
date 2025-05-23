#include"Utils.h"

USING_NS_CC;

static int hexToInt(const std::string& s) {
    return std::stoi(s, nullptr, 16);
}

Color4B hexToColor4B(const std::string& hex, unsigned char alpha) {
    if (hex.size() != 7 || hex[0] != '#') return Color4B::WHITE;

    int r = hexToInt(hex.substr(1, 2));
    int g = hexToInt(hex.substr(3, 2));
    int b = hexToInt(hex.substr(5, 2));
    return Color4B(r, g, b, alpha);
}