#pragma once

#ifndef PREFABLOADER_H
#define PREFABLOADER_H

#include <memory>
#include <string>
#include <vector>
#include "includeLUA.h"

class GameObject;

class PrefabLoader
{
public:
	~PrefabLoader();

	/// <summary>
	/// Returns the instance of PrefabLoader, or nullptr if it doesnt exist yet
	/// </summary>
	static PrefabLoader* getInstance();

	/// <summary>
	/// Creates the PrefabLoader singleton instance if its not already created
	/// </summary>
	static void CreateInstance();

	PrefabLoader& operator=(const PrefabLoader&) = delete;
	PrefabLoader(PrefabLoader& other) = delete;

	GameObject* loadPrefab(std::string path, int howMany);

	void loadPoolPrefab(std::string path, int howMany, std::vector<GameObject*> &mainPool, std::vector<GameObject*> &inactivePool);
private:
	/// <summary>
	/// Contructor of the class
	/// </summary>
	PrefabLoader();

	bool loadPrefabFile();

	static std::unique_ptr<PrefabLoader> instance;

	lua_State* _LuaVM;

	std::string _filePath;
};

#endif /*PrefabLoader.h*/