#ifndef BABA_IS_GUI_SCENE_H
#define BABA_IS_GUI_SCENE_H

#include <imgui/imgui.h>

#include <string>

namespace baba_is_GUI
{
    class Scene
    {
    public:
        Scene() = default;
        virtual ~Scene() = default;

        virtual void Start() = 0;

        virtual void Input() = 0;

        virtual void Update() = 0;
        
        virtual void Render() = 0;

        virtual void Finish() = 0;

        void SetName(std::string name)
        {
            m_name = name;
        }

        std::string GetName() const
        {
            return m_name;
        }

    protected:
        std::string m_name;
    };
}

#endif