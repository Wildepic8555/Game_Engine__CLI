#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h> // For select()

//This was Made by AI

/**
 * Reads a single key press immediately, or returns 'e' if no key is pressed
 * within approximately 1/60th of a second (16.67 ms).
 *
 * @return The character pressed, or 'e' on timeout/no key pressed.
 */
int getKey() {
    char c = '1';
    struct termios oldt, newt;
    int fd = STDIN_FILENO;

    // 1. Save old terminal settings and set raw mode
    tcgetattr(fd, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    newt.c_cc[VMIN] = 0; // VMIN = 0 is required for select to work correctly
    newt.c_cc[VTIME] = 0; // Set VTIME = 0 (non-blocking)

    tcsetattr(fd, TCSANOW, &newt);

    // --- Using select() for 1/60th second timeout (16667 microseconds) ---

    // Set up the file descriptor set to watch STDIN (fd 0)
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    // Define the timeout structure (16,667 microseconds)
    struct timeval timeout;
    timeout.tv_sec = 0;             // 0 seconds
    timeout.tv_usec = 16667;        // ~16.67 milliseconds (1/60th s)

    // Wait for input on STDIN (fd) up to the timeout
    int select_result = select(fd + 1, &readfds, NULL, NULL, &timeout);

    // 2. Read character only if select indicated input is ready
    if (select_result > 0 && FD_ISSET(fd, &readfds)) {
        // Input is available, perform a non-blocking read
        // It will read 1 character or return 0 if something changed between select/read
        read(fd, &c, 1);
    }

    // 3. Restore old terminal settings
    tcsetattr(fd, TCSANOW, &oldt);

    // A key was pressed. 'c' holds the key.
    return c;
}