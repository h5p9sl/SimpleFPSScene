#include <iostream>

#include "Engine/Window.hpp"

int main() {

    Window window("Simple FPS Scene");

    window.Show(true);

    while (window.IsOpen()) {
        WndEvent event;
        while (window.PollEvent(event)) {
            if (event == WndEvent::MSG_CLOSE) window.Close();
        }

        window.Render();
        Sleep(1);
    }

    return 0;
}