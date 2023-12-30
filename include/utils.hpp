#ifndef __COLORS__HPP__
    #define __COLORS__HPP__

    #include <string>
    #include "config.h"

    using namespace std;

    /* --------------------------------------------------------------------------- */

    namespace Utils {

        namespace Colors {
            // Reset
            const string RESET = "\u001b[0m"; // Text Reset
            
            // Regular Colors
            const string BLACK = "\u001b[30;1m";   // BLACK
            const string RED = "\u001b[31;1m";     // RED
            const string GREEN = "\u001b[32;1m";   // GREEN
            const string YELLOW = "\u001b[33;1m";  // YELLOW
            const string BLUE = "\u001b[34;1m";    // BLUE
            const string PURPLE = "\u001b[35;1m";  // PURPLE
            const string CYAN = "\u001b[36;1m";    // CYAN
            const string WHITE = "\u001b[37;1m";   // WHITE

            // Bold
            const string BLACK_BOLD = "\033[1;30m";  // BLACK
            const string RED_BOLD = "\033[1;31m";    // RED
            const string GREEN_BOLD = "\033[1;32m";  // GREEN
            const string YELLOW_BOLD = "\033[1;33m"; // YELLOW
            const string BLUE_BOLD = "\033[1;34m";   // BLUE
            const string PURPLE_BOLD = "\033[1;35m"; // PURPLE
            const string CYAN_BOLD = "\033[1;36m";   // CYAN
            const string WHITE_BOLD = "\033[1;37m";  // WHITE

            // Underline
            const string BLACK_UNDERLINED = "\033[4;30m";  // BLACK
            const string RED_UNDERLINED = "\033[4;31m";    // RED
            const string GREEN_UNDERLINED = "\033[4;32m";  // GREEN
            const string YELLOW_UNDERLINED = "\033[4;33m"; // YELLOW
            const string BLUE_UNDERLINED = "\033[4;34m";   // BLUE
            const string PURPLE_UNDERLINED = "\033[4;35m"; // PURPLE
            const string CYAN_UNDERLINED = "\033[4;36m";   // CYAN
            const string WHITE_UNDERLINED = "\033[4;37m";  // WHITE

            // Background
            const string BLACK_BACKGROUND = "\033[40m";  // BLACK
            const string RED_BACKGROUND = "\033[41m";    // RED
            const string GREEN_BACKGROUND = "\033[42m";  // GREEN
            const string YELLOW_BACKGROUND = "\033[43m"; // YELLOW
            const string BLUE_BACKGROUND = "\033[44m";   // BLUE
            const string PURPLE_BACKGROUND = "\033[45m"; // PURPLE
            const string CYAN_BACKGROUND = "\033[46m";   // CYAN
            const string WHITE_BACKGROUND = "\033[47m";  // WHITE

            // High Intensity
            const string BLACK_BRIGHT = "\033[0;90m";  // BLACK
            const string RED_BRIGHT = "\033[0;91m";    // RED
            const string GREEN_BRIGHT = "\033[0;92m";  // GREEN
            const string YELLOW_BRIGHT = "\033[0;93m"; // YELLOW
            const string BLUE_BRIGHT = "\033[0;94m";   // BLUE
            const string PURPLE_BRIGHT = "\033[0;95m"; // PURPLE
            const string CYAN_BRIGHT = "\033[0;96m";   // CYAN
            const string WHITE_BRIGHT = "\033[0;97m";  // WHITE

            // Bold High Intensity
            const string BLACK_BOLD_BRIGHT = "\033[1;90m"; // BLACK
            const string RED_BOLD_BRIGHT = "\033[1;91m";   // RED
            const string GREEN_BOLD_BRIGHT = "\033[1;92m"; // GREEN
            const string YELLOW_BOLD_BRIGHT = "\033[1;93m";// YELLOW
            const string BLUE_BOLD_BRIGHT = "\033[1;94m";  // BLUE
            const string PURPLE_BOLD_BRIGHT = "\033[1;95m";// PURPLE
            const string CYAN_BOLD_BRIGHT = "\033[1;96m";  // CYAN
            const string WHITE_BOLD_BRIGHT = "\033[1;97m"; // WHITE

            // High Intensity backgrounds
            const string BLACK_BACKGROUND_BRIGHT = "\033[0;100m";// BLACK
            const string RED_BACKGROUND_BRIGHT = "\033[0;101m";// RED
            const string GREEN_BACKGROUND_BRIGHT = "\033[0;102m";// GREEN
            const string YELLOW_BACKGROUND_BRIGHT = "\033[0;103m";// YELLOW
            const string BLUE_BACKGROUND_BRIGHT = "\033[0;104m";// BLUE
            const string PURPLE_BACKGROUND_BRIGHT = "\033[0;105m"; // PURPLE
            const string CYAN_BACKGROUND_BRIGHT = "\033[0;106m";  // CYAN
            const string WHITE_BACKGROUND_BRIGHT = "\033[0;107m";   // WHITE
        }

        namespace MINECRAFT_VERSION {
            // Minecraft versions supported
            const string MIN_MINECRAFT_VERSION = "1.8.9";
            const string MAX_MINECRAFT_VERSION = "1.20.1";

            // All minecraft versions supported
            const string MC1_8_9 = "1.8.9";
            const string MC1_12_2 = "1.12.2";
            const string MC1_14_4 = "1.14.4";
            const string MC1_15_2 = "1.15.2";
            const string MC1_16_5 = "1.16.5";
            const string MC1_17_1 = "1.17.1";
            const string MC1_18_2 = "1.18.2";
            const string MC1_19_4 = "1.19.4";
            const string MC1_20_1 = "1.20.1";
        }
    }

#endif