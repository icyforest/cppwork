#pragma once
#include <functional>
#include <list>
#include <unordered_map>
#include "CommandCar.hpp"
namespace adas
{
    using CmderCar = std::function<void(PoseHandler& poseHandler)>;
    using CmderCarList = std::list<CmderCar>;
    
    class CmderFactoryCar final
    {
        public:
            CmderFactoryCar(void) = default;//noexcept  = default;
            ~ CmderFactoryCar(void) noexcept = default;//  = default;
            CmderFactoryCar(const CmderFactoryCar&) noexcept = delete;//  = delete;
            CmderFactoryCar& operator=(const CmderFactoryCar&) noexcept = delete;//  = delete;
        public:
            CmderCarList GetCarCmders(const std::string& commands) const noexcept;
        private:
            const std::unordered_map<char, CmderCar> cmderCarMap
            {
                {'M', MoveCommandCar()},
                {'L', TurnLeftCommandCar()},
                {'R', TurnRightCommandCar()},
                {'F', FastCommandCar()}, 
                {'B', ReverseCommandCar()}, 
            };
    };
}