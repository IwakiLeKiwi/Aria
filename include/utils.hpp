#ifndef UTILS_HPP
    #define UTILS_HPP

    #include <string>
    #include <unordered_map>
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

        namespace MINECRAFT {

            namespace MINECRAFT_VERSION {
                // Minecraft versions supported
                const std::string MIN_SUPPORTED_MINECRAFT_VERSION = "1.8.9";
                const std::string MAX_SUPPORTED_MINECRAFT_VERSION = "1.20.1";

                // All minecraft versions supported
                const std::string MC_1_8_9  = "1.8.9";
                const std::string MC_1_12_2 = "1.12.2";
                const std::string MC_1_14_4 = "1.14.4";
                const std::string MC_1_15_2 = "1.15.2";
                const std::string MC_1_16_5 = "1.16.5";
                const std::string MC_1_17_1 = "1.17.1";
                const std::string MC_1_18_2 = "1.18.2";
                const std::string MC_1_19_4 = "1.19.4";
                const std::string MC_1_20_1 = "1.20.1";
            }

            namespace JAVA_VERSION {
                const std::string JAVA_8  = "apt-get install -y openjdk-8-jre-headless";
                const std::string JAVA_11 = "apt-get install -y openjdk-11-jre-headless";
                const std::string JAVA_16 = "apt-get install -y openjdk-16-jre-headless";
                const std::string JAVA_17 = "apt-get install -y openjdk-17-jre-headless";
                const std::string JAVA_20 = "apt-get install -y openjdk-20-jre-headless";
            }
        }

        // Function to get the corresponding Java version for a Minecraft version
        inline std::string getJavaVersionForMinecraft(const std::string& minecraftVersion) {
            if (minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_8_9 || 
                minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_12_2) {
                return MINECRAFT::JAVA_VERSION::JAVA_8;
            } else if (minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_14_4 || 
                    minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_15_2 || 
                    minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_16_5) {
                return MINECRAFT::JAVA_VERSION::JAVA_11;
            } else if (minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_17_1) {
                return MINECRAFT::JAVA_VERSION::JAVA_16;
            } else if (minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_18_2 || 
                    minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_19_4) {
                return MINECRAFT::JAVA_VERSION::JAVA_17;
            } else if (minecraftVersion == MINECRAFT::MINECRAFT_VERSION::MC_1_20_1) {
                return MINECRAFT::JAVA_VERSION::JAVA_20;
            } else {
                // Handle unsupported Minecraft versions
                return "Unsupported Minecraft Version";
            }
        }
    }

#endif