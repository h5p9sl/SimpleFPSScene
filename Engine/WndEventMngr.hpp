#ifndef WindowProc_hpp
#define WindowProc_hpp

#include <Windows.h>
#include <vector>
#include <stdio.h> // For debugging

enum WndEvent : unsigned
{
    ERROR_TYPE,
    MSG_CLOSE,
};

// NOTE: Creating a namespace to hold all these static
// function and variables may not be the best solution.
// but for now, this is what I will do.
// Hopefully there will be no repercussions :P
namespace WndEventMngr
{
    struct WindowEventInfo {
        WndEvent event;
        HWND hwnd;
    };

    // Used for translating Window messages into 'WndEvent' types
    WndEvent TranslateToEvent(UINT msg);

    // Our WindowProc function
    LRESULT CALLBACK GlobalWindowProc(
        HWND   hwnd,
        UINT   uMsg,
        WPARAM wParam,
        LPARAM lParam
    );
    
    // A list of messages to be retrieved & processed later
    extern std::vector<WindowEventInfo> EventQueue;
};

#endif