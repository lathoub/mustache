#pragma once

#include "defs.h"

#include "namespace.h"

BEGIN_EXPRESS_NAMESPACE

/// @brief 
class mustache
{
private:
    /// @brief
    /// @return
    static signed int find(const char *line, const char *ss, const int from, const int to)
    {
        int w = 0;
        int j = 0;
        for (auto i = from; i < to; i++)
        {
            if (line[i] == ss[j])
            {
                j++;
                w = i;
            }
            else if (w > 0)
                break; // optimization: stop after equality is found
        }

        return (2 == j) ? w : -1;
    }

    /// @brief
    static void renderLine(EthernetClient &client, const char *line, int from, const int to, locals_t &locals)
    {
        while (from < to)
        {
            auto index = find(line, "{{", from, to);
            if (index < 1)
                break;

            client.write(line + from, index - from - 1);

            from = index + 1;

            index = find(line, "}}", from, to);
            if (index < 1)
                return; // TODO do error handling (no closing found), error in template

            char key_[15]; // TODO arbitraty length
            strncpy(key_, line + from, index - from - 1);
            key_[index - from - 1] = '\0';

            client.print(locals[key_]);

            from = index + 1;
        }

        if (from < to)
            client.write(line + from, to - from);
    }

public:
    /// @brief
    static void renderFile(EthernetClient &client, locals_t &locals, const char *f)
    {
        size_t i = 0;
        size_t start = 0;
        while (f[start + i] != '\0')
        {
            while (f[start + i] != '\n' && f[start + i] != '\0')
                i++;

            renderLine(client, f, start, start + i, locals);

            if (f[start + i] == '\0')
                break;

            start += i + 1;
            i = 0;
        }
    }

public:
};

/// @brief
/// @return
static RenderEngineCallback mustacheExpress()
{
    return mustache::renderFile;
}

END_EXPRESS_NAMESPACE
