

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

#include <iostream>
#include <Scenes/TestScene.h>
#include <Manager/GameManager.h>
#include <Manager/SceneManager.h>

using namespace CMake_OpenGL;

GameManager* GameManager::m_instance = nullptr;
SceneManager* SceneManager::m_instance = nullptr;

int main()
{
    TestScene testScene;
    testScene.SetName("Login");
    SceneManager::GetInstance()->AddScene(&testScene);

    SceneManager::GetInstance()->StartSceneManager("Login");
    return 0;
}
