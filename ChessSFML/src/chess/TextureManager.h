#pragma once
#include "pch.h"


class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    static void LoadTextures();

    static sf::Texture& GetTexture(const std::string& name);

private:
    static std::map<std::string, sf::Texture> textures;

    static void LoadTexture(const std::string& name, const std::string& filename);
};