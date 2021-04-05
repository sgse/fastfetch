#include "FFstrbuf.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void ffStrbufInit(FFstrbuf* strbuf)
{
    ffStrbufInitA(strbuf, FASTFETCH_STRBUF_DEFAULT_ALLOC);
}

void ffStrbufInitCopy(FFstrbuf* strbuf, const FFstrbuf* src)
{
    ffStrbufInitA(strbuf, src->allocated);
    ffStrbufAppend(strbuf, src);
}

void ffStrbufInitS(FFstrbuf* strbuf, const char* value)
{
    ffStrbufInitAS(strbuf, FASTFETCH_STRBUF_DEFAULT_ALLOC, value);
}

void ffStrbufInitNS(FFstrbuf* strbuf, uint32_t length, const char* value)
{
    ffStrbufInitANS(strbuf, FASTFETCH_STRBUF_DEFAULT_ALLOC, length, value);
}

void ffStrbufInitC(FFstrbuf* strbuf, const char c)
{
    ffStrbufInitAC(strbuf, FASTFETCH_STRBUF_DEFAULT_ALLOC, c);
}

void ffStrbufInitA(FFstrbuf* strbuf, uint32_t allocate)
{
    if(allocate == 0)
    {
        fprintf(stderr, "ffStrbufInitA(): allocation size == 0");
        exit(701);
    }

    strbuf->allocated = allocate;
    strbuf->chars = (char*) malloc(sizeof(char) * strbuf->allocated);

    ffStrbufClear(strbuf);
}

void ffStrbufInitAS(FFstrbuf* strbuf, uint32_t allocate, const char* value)
{
    ffStrbufInitA(strbuf, allocate);
    ffStrbufAppendS(strbuf, value);
}

void ffStrbufInitANS(FFstrbuf* strbuf, uint32_t allocate, uint32_t length, const char* value)
{
    ffStrbufInitA(strbuf, allocate);
    ffStrbufAppendNS(strbuf, length, value);
}

void ffStrbufInitAC(FFstrbuf* strbuf, uint32_t allocate, const char c)
{
    ffStrbufInitA(strbuf, allocate);
    ffStrbufAppendC(strbuf, c);
}

void ffStrbufInitF(FFstrbuf* strbuf, const char* format, ...)
{
    ffStrbufInitA(strbuf, FASTFETCH_STRBUF_DEFAULT_ALLOC);
    va_list arguments;
    va_start(arguments, format);
    ffStrbufAppendVF(strbuf, format, arguments);
    va_end(arguments);
}

void ffStrbufInitVF(FFstrbuf* strbuf, const char* format, va_list arguments)
{
    ffStrbufInitA(strbuf, FASTFETCH_STRBUF_DEFAULT_ALLOC);
    ffStrbufAppendVF(strbuf, format, arguments);
}

void ffStrbufEnsureCapacity(FFstrbuf* strbuf, uint32_t allocate)
{
    if(strbuf->allocated >= allocate)
        return;
    strbuf->allocated = allocate;
    strbuf->chars = realloc(strbuf->chars, sizeof(char) * strbuf->allocated);
}

void ffStrbufEnsureFree(FFstrbuf* strbuf, uint32_t free)
{
    uint32_t allocate = strbuf->allocated;
    if(allocate < 2)
        allocate = 2;
    while((strbuf->length + free) > allocate)
        allocate *= 2;
    ffStrbufEnsureCapacity(strbuf, allocate);
}

void ffStrbufClear(FFstrbuf* strbuf)
{
    strbuf->chars[0] = '\0';
    strbuf->length = 0;
}

void ffStrbufSet(FFstrbuf* strbuf, const FFstrbuf* value)
{
    ffStrbufClear(strbuf);
    ffStrbufAppendNS(strbuf, value->length, value->chars);
}

void ffStrbufSetS(FFstrbuf* strbuf, const char* value)
{
    ffStrbufClear(strbuf);
    ffStrbufAppendS(strbuf, value);
}

void ffStrbufSetNS(FFstrbuf* strbuf, uint32_t length, const char* value)
{
    ffStrbufClear(strbuf);
    ffStrbufAppendNS(strbuf, length, value);
}

void ffStrbufSetC(FFstrbuf* strbuf, const char c)
{
    ffStrbufClear(strbuf);
    ffStrbufAppendC(strbuf, c);
}

void ffStrbufSetF(FFstrbuf* strbuf, const char* format, ...)
{
    ffStrbufClear(strbuf);
    va_list arguments;
    va_start(arguments, format);
    ffStrbufAppendVF(strbuf, format, arguments);
    va_end(arguments);
}

void ffStrbufSetVF(FFstrbuf* strbuf, const char* format, va_list arguments)
{
    ffStrbufClear(strbuf);
    ffStrbufAppendVF(strbuf, format, arguments);
}

void ffStrbufAppend(FFstrbuf* strbuf, const FFstrbuf* value)
{
    ffStrbufAppendNS(strbuf, value->length, value->chars);
}

void ffStrbufAppendS(FFstrbuf* strbuf, const char* value)
{
    if(value == NULL)
        return;

    for(uint32_t i = 0; value[i] != '\0'; i++)
    {
        if(i % 16 == 0)
            ffStrbufEnsureFree(strbuf, 16);
        strbuf->chars[strbuf->length++] = value[i];
    }
    strbuf->chars[strbuf->length] = '\0';
}

void ffStrbufAppendNS(FFstrbuf* strbuf, uint32_t length, const char* value)
{
    if(value == NULL)
        return;

    ffStrbufEnsureFree(strbuf, length);

    for(uint32_t i = 0; i < length; i++)
    {
        if(value[i] == '\0')
            break;

        strbuf->chars[strbuf->length++] = value[i];
    }
    strbuf->chars[strbuf->length] = '\0';
}

void ffStrbufAppendC(FFstrbuf* strbuf, const char c)
{
    ffStrbufEnsureFree(strbuf, 1);
    strbuf->chars[strbuf->length++] = c;
    strbuf->chars[strbuf->length] = '\0';
}

void ffStrbufAppendF(FFstrbuf* strbuf, const char* format, ...)
{
    if(format == NULL)
        return;

    va_list arguments;
    va_start(arguments, format);
    ffStrbufAppendVF(strbuf, format, arguments);
    va_end(arguments);
}

void ffStrbufAppendVF(FFstrbuf* strbuf, const char* format, va_list arguments)
{
    if(format == NULL)
        return;

    va_list localArguments;
    va_copy(localArguments, arguments);

    ffStrbufEnsureFree(strbuf, 256);
    int written = vsnprintf(strbuf->chars + strbuf->length, strbuf->allocated - strbuf->length, format, localArguments);

    va_end(localArguments);

    if(strbuf->length + written >= strbuf->allocated)
    {
        ffStrbufEnsureCapacity(strbuf, strbuf->allocated * 2);
        ffStrbufAppendVF(strbuf, format, arguments); //Try again with larger buffer
    }
    else
    {
        strbuf->length += written;
        strbuf->chars[strbuf->length] = '\0';
    }
}

char ffStrbufGetC(FFstrbuf* strbuf, uint32_t index)
{
    if(index >= strbuf->length)
    {
        fprintf(stderr, "ffStrbufGetC(): to high index");
        exit(702);
    }

    return strbuf->chars[index];
}

void ffStrbufWriteTo(FFstrbuf* strbuf, FILE* file)
{
    fwrite(strbuf->chars, sizeof(char), strbuf->length, file);
}

void ffStrbufPutTo(FFstrbuf* strbuf, FILE* file)
{
    fwrite(strbuf->chars, sizeof(char), strbuf->length, file);
    fputc('\n', file);
}

int ffStrbufComp(FFstrbuf* strbuf, const FFstrbuf* comp)
{
    return ffStrbufCompNS(strbuf, comp->length, comp->chars);
}

int ffStrbufCompS(FFstrbuf* strbuf, const char* comp)
{
    return strcmp(strbuf->chars, comp);
}

int ffStrbufCompNS(FFstrbuf* strbuf, uint32_t length, const char* comp)
{
    return strncasecmp(strbuf->chars, comp, length);
}

int ffStrbufIgnCaseComp(FFstrbuf* strbuf, const FFstrbuf* comp)
{
    return ffStrbufIgnCaseCompNS(strbuf, comp->length, comp->chars);
}

int ffStrbufIgnCaseCompS(FFstrbuf* strbuf, const char* comp)
{
    return strcasecmp(strbuf->chars, comp);
}

int ffStrbufIgnCaseCompNS(FFstrbuf* strbuf, uint32_t length, const char* comp)
{
    return strncasecmp(strbuf->chars, comp, length);
}

void ffStrbufTrimLeft(FFstrbuf* strbuf, char c)
{
    uint32_t index = 0;
    while(strbuf->chars[index] == c && index < strbuf->length)
        ++index;

    if(index == 0)
        return;

    memmove(strbuf->chars, strbuf->chars + index, index);
    strbuf->length -= index;
}

void ffStrbufTrimRight(FFstrbuf* strbuf, char c)
{

    while(strbuf->length > 0 && strbuf->chars[strbuf->length - 1] == c)
        --strbuf->length;
    strbuf->chars[strbuf->length] = '\0';
}

void ffStrbufTrim(FFstrbuf* strbuf, char c)
{
    ffStrbufTrimRight(strbuf, c);
    ffStrbufTrimLeft(strbuf, c);
}

static bool strbufRemoveTest(FFstrbuf* strbuf, uint32_t i, const char* substr)
{
    uint32_t k;
    for(k = 0; substr[k] != '\0'; k++)
    {
        if(i + k > strbuf->length)
            return false;

        if(strbuf->chars[i + k] != substr[k])
            return false;
    }

    memmove(&strbuf->chars[i], &strbuf->chars[i + k], strbuf->length - i - k);
    strbuf->length -= k;
    strbuf->chars[strbuf->length] = '\0';
    return true;
}

void ffStrbufRemoveStrings(FFstrbuf* strbuf, uint32_t numStrings, ...)
{
    const char* strings[numStrings];

    va_list argp;
    va_start(argp, numStrings);

    for(uint32_t i = 0; i < numStrings; i++)
        strings[i] = va_arg(argp, const char*);

    va_end(argp);

    for(uint32_t i = 0; i < strbuf->length; i++)
    {
        for(uint32_t k = 0; k < numStrings; k++)
            while(strbufRemoveTest(strbuf, i, strings[k]));
    }
}

uint32_t ffStrbufFirstIndexAfterC(FFstrbuf* strbuf, uint32_t start, const char c)
{
    for(uint32_t i = start; i < strbuf->length; i++)
    {
        if(strbuf->chars[i] == c)
            return i;
    }
    return strbuf->length;
}

uint32_t ffStrbufFirstIndexC(FFstrbuf* strbuf, const char c)
{
    return ffStrbufFirstIndexAfterC(strbuf, 0, c);
}

uint32_t ffStrbufLastIndexC(FFstrbuf* strbuf, const char c)
{
    //We need to loop one higher than the actual index, because uint32_t is guranteed to be >= 0, so this statement would always be true
    for(uint32_t i = strbuf->length; i > 0; i--)
    {
        if(strbuf->chars[i - 1] == c)
            return i - 1;
    }
    return strbuf->length;
}

void ffStrbufSubstrBefore(FFstrbuf* strbuf, uint32_t index)
{
    if(strbuf->length <= index)
        return;

    strbuf->length = index;
    strbuf->chars[strbuf->length] = '\0';
}

void ffStrbufSubstrBeforeFirstC(FFstrbuf* strbuf, const char c)
{
    ffStrbufSubstrBefore(strbuf, ffStrbufFirstIndexC(strbuf, c));
}

bool ffStrbufStartsWith(FFstrbuf* strbuf, FFstrbuf* start)
{
    return ffStrbufStartsWithNS(strbuf, start->length, start->chars);
}

void ffStrbufSubstrAfter(FFstrbuf* strbuf, uint32_t index)
{
    if(index >= strbuf->length)
    {
        ffStrbufClear(strbuf);
        return;
    }

    memmove(strbuf->chars, strbuf->chars + index + 1, strbuf->length - index - 1);
    strbuf->length -= (index + 1);
    strbuf->chars[strbuf->length] = '\0';
}

void ffStrbufSubstrAfterLastC(FFstrbuf* strbuf, const char c)
{
    uint32_t index = ffStrbufLastIndexC(strbuf, c);
    if(index < strbuf->length)
        ffStrbufSubstrAfter(strbuf, index);
}

static inline bool testSame(FFstrbuf* strbuf, uint32_t i, const char* str)
{
    if(i > strbuf->length)
        return false;

    if(strbuf->chars[i] != str[i])
        return false;

    return true;
}

bool ffStrbufStartsWithS(FFstrbuf* strbuf, const char* start)
{
    for(uint32_t i = 0; start[i] != '\0'; i++)
    {
        if(!testSame(strbuf, i, start))
            return false;
    }
    return true;
}

bool ffStrbufStartsWithNS(FFstrbuf* strbuf, uint32_t length, const char* start)
{
    for(uint32_t i = 0; i < length; i++)
    {
        if(!testSame(strbuf, i, start))
            return false;
    }
    return true;
}

void ffStrbufRecalculateLength(FFstrbuf* strbuf)
{
    for(strbuf->length = 0; strbuf->chars[strbuf->length] != '\0'; ++strbuf->length);
}

void ffStrbufDestroy(FFstrbuf* strbuf)
{
    free(strbuf->chars);
    strbuf->allocated = 0;
    strbuf->chars = NULL;
    strbuf->length = 0;
}
