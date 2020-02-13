

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

#include <iostream>
#include <Scenes/TestScene.h>
#include <Scenes/TitleScene.h>
#include <Manager/GameManager.h>
#include <Manager/SceneManager.h>

using namespace baba_is_GUI;

GameManager* GameManager::m_instance = nullptr;
SceneManager* SceneManager::m_instance = nullptr;

int main()
{
    TestScene testScene;
    TitleScene titleScene;
    titleScene.SetName("Title");
    testScene.SetName("Test");
    SceneManager::GetInstance()->AddScene(&titleScene);
    SceneManager::GetInstance()->AddScene(&testScene);

    SceneManager::GetInstance()->StartSceneManager("Title");
    return 0;
}
