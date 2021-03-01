#pragma once

#include <stack>
#include <memory>

#include <State.hpp>

namespace Engine
{
class StateMan
{
public:
    StateMan();
    ~StateMan();

    void add(std::unique_ptr<State> toAdd, bool replace = false);
    void popCurrent();
    void precessStateChange();
    std::unique_ptr<State>& getCurrent();
private:
    std::stack<std::unique_ptr<State>> m_stateStack;
    std::unique_ptr<State> m_newState;

    bool m_add, m_repalce, m_remove;
};
}