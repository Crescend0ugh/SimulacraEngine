//
// Created by avsom on 12/23/2023.
//

#pragma once

#include <memory>
#include <windows.h>
#include "../SimulacraWindow.h"

class SWindowsWindow : public SWindowBase
{

public:

    static std::string WindowClassName;


public:


    bool ShouldClose() override;

    SWindowsWindow();

    ~SWindowsWindow();

    void Init(HINSTANCE InHInstance);

    void  Move(int32 InX, int32 InY) override;

    void  Show() override;

    void  Hide() override;

    void  Minimize() override;

    void  Maximize() override;

    void* GetHandle() override;

    void GetSize(uint32 &Width, uint32 &Height) override;

    void Resize(int32 InX, int32 InY, int32 InWidth, int32 InHeight) override;

    void Restore() override;


private:

    HWND HWnd;

    float AspectRatio = 16.0f/9.0f;


};

typedef SWindowsWindow SWindow;

