# PostMsgToMainThread_Win32

1. Create a sub window;
2. Init thread routine;
3. Post message in thread routine;
4. Main thread will recv message in WndProc callback function due to Windows Message mechanism.
