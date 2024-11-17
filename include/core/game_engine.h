#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "game_object.h"
#include "components/material.h"
#include "components/transform.h"
#include "scene.h"

#define _USE_SCENE_

class GameEngine
{
private:
    std::string name;
    std::vector<std::shared_ptr<Scene>> scenes;
    int currSceneIdx = 0;

    void TestInit2()
    {
        auto scene = std::make_shared<Scene>();
        size_t n = 3;
        glm::vec3 pos[n] = {
            {0.0f, -1.0f, 0.0f},
            {-2.0f, -1.0f, -3.0f},
            {2.0f, -1.0f, -3.0f}
        };
        for (int i = 0; i < n; i++)
        {
            scene->AddModel();
            const auto& obj = scene->GetModels().at(i);

            std::dynamic_pointer_cast<Transform>(obj->components.at(0))->position = pos[i];
        }

        auto light = std::make_shared<GameObject>();
        auto lightTransform = std::make_shared<Transform>(
            glm::vec3()
        );

        scenes.push_back(scene);
    }

public:
    std::vector<std::shared_ptr<Scene>>& GetScenes() { return scenes; }
    std::shared_ptr<Scene>& GetCurrScene() { return scenes[currSceneIdx]; }
    GameEngine()
    {
        TestInit2();
    }
};

#ifndef _USE_SCENE_
class GameEngine {
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    int randomID = 0;
    std::string modelPath = "../resources/models/";
public:

    std::shared_ptr<GameObject> selectedGameObj = nullptr;

    void AddObjectToVerticesMap(std::shared_ptr<GameObject> gameObject);

    void TestInit()
    {
        auto bunnyObj = std::make_shared<GameObject>();
        auto bunnyTransform = std::make_shared<Transform>();

        bunnyObj->components.push_back(bunnyTransform);

        gameObjects.push_back(bunnyObj);
    }

    void TestInit2()
    {
        size_t n = 3;
        glm::vec3 pos[n] = {
            {0.0f, -1.0f, 0.0f},
            {-2.0f, -1.0f, -3.0f},
            {2.0f, -1.0f, -3.0f}
        };
        for (int i = 0; i < n; i++)
        {
            auto bunnyObj = std::make_shared<GameObject>();
            auto bunnyTransform = std::make_shared<Transform>(pos[i]);

            bunnyObj->components.push_back(bunnyTransform);

            gameObjects.push_back(bunnyObj);

        }

    }

    void TestInit3() {
        size_t n = 3;
        glm::vec3 pos[n] = {
            {0.0f, -1.0f, 0.0f},
            {-2.0f, -1.0f, -3.0f},
            {2.0f, -1.0f, -3.0f}
        };
        for (int i = 0; i < n; i++)
        {
            auto bunnyObj = std::make_shared<GameObject>();
            auto bunnyName = std::string("bunny" + std::to_string(randomID++));
            auto bunnyTransform = std::make_shared<Transform>(pos[i]);
            auto bunnyMaterial = std::make_shared<Material>();

            bunnyObj->name = bunnyName;
            bunnyObj->components.push_back(bunnyTransform);
            bunnyObj->components.push_back(bunnyMaterial);

            gameObjects.push_back(bunnyObj);
        }
    }

    void TestInit4()
    {

    }

    void AddGameObject(std::shared_ptr<GameObject>& gameObject)
    {
        gameObjects.push_back(gameObject);
    }

    void AddGameObject(){
        glm::vec3 pos= {0.0f, 0.0f, 0.0f};

        auto bunnyObj = std::make_shared<GameObject>();
        auto bunnyName = std::string("bunny" + std::to_string(randomID++));
        auto bunnyTransform = std::make_shared<Transform>(pos);
        auto bunnyMaterial = std::make_shared<Material>();

        bunnyObj->name = bunnyName;
        bunnyObj->components.push_back(bunnyTransform);
        bunnyObj->components.push_back(bunnyMaterial);

        AddGameObject(bunnyObj);

    };

    // Test Constructor
    GameEngine()
    {
        TestInit3();
    }

    const std::vector<std::shared_ptr<GameObject>>& GetGameObjects() { return gameObjects; }

};
#endif
