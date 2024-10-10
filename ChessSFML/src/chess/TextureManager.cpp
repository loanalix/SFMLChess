#include "pch.h"
#include "TextureManager.h"

TextureManager::TextureManager() {};


std::map<std::string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture() {
    textures["white_pawn"].loadFromFile("../Textures/white_pawn.png");
    textures["black_pawn"].loadFromFile("../Textures/black_pawn.png");
}

sf::Texture& TextureManager::GetTexture(const std::string& name) {
    return textures[name];
}

TextureManager::~TextureManager() {};