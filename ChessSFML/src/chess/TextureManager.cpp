#include "pch.h"
#include "TextureManager.h"

TextureManager::TextureManager() {};


std::map<std::string, sf::Texture> TextureManager::textures; 

void TextureManager::LoadTextures()
{
    LoadTexture("pawn", "../../Textures/white_pawn.png");
    //LoadTexture("rook", "../../Textures/tour.png");
    
}

void TextureManager::LoadTexture(const std::string& name, const std::string& filename)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
    {
        std::cerr << "Erreur : Impossible de charger " << filename << std::endl;
    }
    textures[name] = texture;  
}

sf::Texture& TextureManager::GetTexture(const std::string& name)
{
    return textures.at(name); 
}

TextureManager::~TextureManager() {};