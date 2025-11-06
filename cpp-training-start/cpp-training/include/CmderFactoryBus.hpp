#pragma once
#include <functional>
#include <list>
#include <unordered_map>
#include "CommandBus.hpp"
namespace adas
{
    using CmderBus = std::function<void(PoseHandler& poseHandler)>;
    using CmderBusList = std::list<CmderBus>;
    class CmderFactoryBus final
    {
        public:
            CmderFactoryBus(void) = default;//noexcept  = default;
            ~ CmderFactoryBus(void) noexcept = default;//  = default;
            CmderFactoryBus(const CmderFactoryBus&) noexcept = delete;//  = delete;
            CmderFactoryBus& operator=(const CmderFactoryBus&) noexcept = delete;//  = delete;
        public:
            CmderBusList GetBusCmders(const std::string& commands) const noexcept;
        private:
            const std::unordered_map<char, CmderBus> cmderBusMap
            {
                {'M', MoveCommandBus()},
                {'L', TurnLeftCommandBus()},
                {'R', TurnRightCommandBus()},
                {'F', FastCommandBus()}, 
                {'B', ReverseCommandBus()}, 
            };
    };
}