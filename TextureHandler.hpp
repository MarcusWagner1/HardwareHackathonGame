#pragma once
#include "misc.hpp"
class TextureHandler
{
public:
	void LoadFiles(const vector<string>& fileNames)
	{
		for (const auto& fileName : fileNames)
		{
			cout << "Loading: textures/" + fileName + ".png" << "\n";
			Texture texture;
			if (!texture.loadFromFile("textures/" + fileName + ".png")) {
				std::cerr << "Failed to load texture!" << std::endl;
			}
			textures[fileName] = move(texture);
		}
	}
	static TextureHandler& getInstance()
	{
		static TextureHandler instance;
		return instance;
	}
	Texture& GetTexture(const string& textureName)
	{
		return textures[textureName];
	}
private:

	TextureHandler()
	{
		cout << "Created the Texture Handler Singleton Class!";
	}
	~TextureHandler()
	{
		cout << "Singleton instance destryoed!" << endl;
	}
	unordered_map<string,Texture> textures;

};