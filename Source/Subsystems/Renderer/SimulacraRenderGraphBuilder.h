//
// Created by avsom on 2/16/2024.
//

#pragma once

class SRenderGraphBuilder
{
public:

    static void CreateTexture();
    static void CreateBuffer();
    static void RegisterExternalBuffer();

    static void AddPass(const char* PassName);
    static void Get();


};

