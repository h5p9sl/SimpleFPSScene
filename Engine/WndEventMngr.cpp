#include "WndEventMngr.hpp"

std::vector<WndEventMngr::WindowEventInfo> WndEventMngr::EventQueue;

LRESULT CALLBACK WndEventMngr::GlobalWindowProc(
  HWND   hwnd,
  UINT   uMsg,
  WPARAM wParam,
  LPARAM lParam
)
{
  WndEvent eventmsg = TranslateToEvent(uMsg);

  if (eventmsg != WndEvent::ERROR_TYPE) {
    puts("Pushing WndEvent onto event queue.");
    WindowEventInfo event;
    event.event = eventmsg;
    event.hwnd = hwnd;
    WndEventMngr::EventQueue.push_back(event);
    return 1l;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

WndEvent WndEventMngr::TranslateToEvent(UINT msg)
{
  WndEvent event;
  switch (msg) {
  case WM_CLOSE:
    event = WndEvent::MSG_CLOSE;
    break;
  default:
    event = WndEvent::ERROR_TYPE;
    break;
  }

  return event;
}