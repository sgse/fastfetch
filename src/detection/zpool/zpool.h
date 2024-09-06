#pragma once

#include "fastfetch.h"

typedef struct FFZpoolResult
{
    FFstrbuf name;
    FFstrbuf state;
    uint64_t used;
    uint64_t total;
    uint64_t version;
    uint64_t fragmentation;
} FFZpoolResult;

const char* ffDetectZpool(FFlist* result /* list of FFZpoolResult */);
