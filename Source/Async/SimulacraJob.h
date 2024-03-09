//
// Created by avsom on 3/7/2024.
//

#pragma once


typedef void SEntryPoint(void *Params);

enum class EPriority
{
    LOW,
    NORMAL,
    HIGH,
    CRITICAL
};

struct SCounter
{
};

SCounter *AllocCounter();

void FreeCounter(SCounter *Counter);


struct SJobDeclaration
{
    SEntryPoint *EntryPoint;
    void        *Params;
    EPriority Priority;
    SCounter *Counter;
};

void KickJob(const SJobDeclaration &Decl);

void KickJobs(int Count, const SJobDeclaration *Decls);

void WaitForCounter();

void KickJobAndWait(const SJobDeclaration &Decl);

void KickJobsAndWait(int Count, const SJobDeclaration *Decls);



