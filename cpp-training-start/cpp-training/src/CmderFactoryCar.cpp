#include "CmderFactoryCar.hpp"
namespace adas
{
    CmderCarList CmderFactoryCar::GetCarCmders(const std::string& commands) const noexcept
    {
        CmderCarList Carcmders;
        for (const auto cmd : commands) 
        {
            const auto it = cmderCarMap.find(cmd);
            if (it != cmderCarMap.end()) {
                Carcmders.push_back(it->second);
            }
        }
        return Carcmders;
    }
}