#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include "../../Application/SimulacraApplication.h"
#include "../../Application/Windows/SimulacraWindowsApplication.h"
#include "../../RHI/Vulkan/Public/SimulacraVulkanRHI.h"
#include "../Globals.h"
#include <thread>

#include <ctime>


void StupidFunction()
{
    for(int i = 0; i < 10000000; i++)
    {
        void* StupidLocalVariable = malloc(1024*4);
        free(StupidLocalVariable);
    }

    std::cout << "Done stupid work\n";

}

int main()
{
    std::cout << "Stuff\n";
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{



    SApplication Application = SWindowsApplication();
    SVulkanRHI       *RHI         = new SVulkanRHI();



    AllocConsole();
    freopen_s((FILE **) stdout, "CONOUT$", "w", stdout);

    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";

    RHI->Init();
    while (!ShouldExitEngine)
    {
        Application.PumpMessages();
        RHI->DrawFrame();
    }

    std::cout << "Works\n";




    return 0;
}