#pragma once

#include <typeindex>
#include <unordered_map>

#include <event/callback.hpp>
#include <event/event.hpp>

#include <iostream>

namespace ZG
{
    class EventDisptacher
    {
        public:
            virtual ~EventDisptacher() = default;

            template<typename T>
            void SubscribeEvent(WeakRef<EventCallback<T>> callback)
            {
                m_Callbacks[typeid(T)].emplace_back(callback);
            }

            template<typename T>
            void DispatchEvent(Ref<T> event)
            {
                // call valid callbacks and erase expired ones
                auto& vec = m_Callbacks[typeid(T)];
                auto iter = std::remove_if(vec.begin(), vec.end(), [event](WeakRef<EventHandler> weakRef)
                {
                    auto eventHandler = weakRef.lock();
                    if (!eventHandler) return true;
                    eventHandler->OnEvent(event);
                    return false;
                });
                vec.erase(iter, vec.end());
            }

        protected:
            std::unordered_map<std::type_index, std::vector<WeakRef<EventHandler>>> m_Callbacks;

    };
};