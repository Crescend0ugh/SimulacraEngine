//
// Created by avsom on 2/11/2024.
//

#include "../Public/SimulacraVulkanDebugUtils.h"

std::string SVulkanDebug::GetQueueDebugString(SVulkanQueue *Queue)
{
    std::string ReturnString;

    ReturnString += "Queue Family Index: " + std::to_string(Queue->GetFamilyIndex()) + "\n";
    ReturnString+= "Queue Index: " + std::to_string(Queue->GetQueueIndex()) + "\n" ;


    ReturnString.shrink_to_fit();
    return ReturnString;
}
