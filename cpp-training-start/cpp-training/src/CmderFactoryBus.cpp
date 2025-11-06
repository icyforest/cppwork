#include "CmderFactoryBus.hpp"
namespace adas
{
    CmderBusList CmderFactoryBus::GetBusCmders(const std::string& commands) const noexcept
    {
        CmderBusList Buscmders;
        for (const auto cmd : commands) 
        {
            const auto it = cmderBusMap.find(cmd);
            if (it != cmderBusMap.end()) {
                Buscmders.push_back(it->second);
            }
        }
        return Buscmders;
    }
}