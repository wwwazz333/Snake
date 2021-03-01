#include "StateMan.hpp"

Engine::StateMan::StateMan() : m_add(false), m_repalce(false), m_remove(false)
{

}
Engine::StateMan::~StateMan()
{

}

void Engine::StateMan::add(std::unique_ptr<State> toAdd, bool replace){
    m_add = true;
    m_newState = std::move(toAdd);

    m_repalce = replace;

}
void Engine::StateMan::popCurrent(){
    m_remove = true;
}
void Engine::StateMan::precessStateChange(){
    if(m_remove && (!m_stateStack.empty())){
        m_stateStack.pop();
        if(!m_stateStack.empty()){
            m_stateStack.top()->start();
        }
        m_remove = false;
    }
    if(m_add){
        if(m_repalce && (!m_stateStack.empty())){
            m_stateStack.pop();
            m_repalce = false;
        }
        if(!m_stateStack.empty()){
            m_stateStack.top()->pause();
        }
        m_stateStack.push(std::move(m_newState));
        m_stateStack.top()->init();
        m_stateStack.top()->start();
        m_add = false; 
    }
}
std::unique_ptr<Engine::State>& Engine::StateMan::getCurrent(){
    return m_stateStack.top();
}

