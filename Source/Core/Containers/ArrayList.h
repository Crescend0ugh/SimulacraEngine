//
// Created by avsom on 10/23/2023.
//

#ifndef SIMULACRAENGINE_ARRAYLIST_H
#define SIMULACRAENGINE_ARRAYLIST_H

template <typename T>
class SArrayList
{
    SArrayList(int NumberOfElements);

    SArrayList();

    T* GetData();


    
private:
    T* P;

};

#endif //SIMULACRAENGINE_ARRAYLIST_H

