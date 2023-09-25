//
// Created by avsom on 9/13/2023.
//
#include <stdint.h>

#ifndef SIMULACRAENGINE_RENDERBACKEND_H
#define SIMULACRAENGINE_RENDERBACKEND_H


/***
 * @brief A struct containing window parameters
 */
struct DisplayParams
{
    //Windowed width
    int WindowedX;

    //Windowed height
    int WindowedY;

    //Native screen height
    int Width;

    //Native screen width
    int Height;

    //Display frequency in Hz
    int DisplayHz;


};


class RenderBackend {

private:
    void Init();

    bool SetScreenParams();

    bool CreateWindowClasses();

    bool CreateGameWindow();
};


#endif //SIMULACRAENGINE_RENDERBACKEND_H
