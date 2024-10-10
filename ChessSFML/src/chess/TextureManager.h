#pragma once
#include "pch.h"


class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    void LoadTexture();
    static sf::Texture& GetTexture(const std::string& name);

private:
    static std::map<std::string, sf::Texture> textures;
};