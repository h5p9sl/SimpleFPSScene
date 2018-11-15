#include <iostream>

#include "Engine/Window.hpp"

int main() {

    Window window("Simple FPS Scene");

    while (window.IsOpen()) {
        WndEvent event;
        while (window.PollEvent(event)) {
            if (event == WndEvent::MSG_CLOSE) window.Close();
        }

        

    }

    return 0;
}