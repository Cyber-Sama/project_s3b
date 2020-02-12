#ifndef INTERFACES_H
#define INTERFACES_H

inline void
invalidInputResponse(std::string &input),
startMenu(),
    newGameIntro(),
    boatIntro(),
    islandIntro(),
    statusUpdate(int &days, int &hours, int &minutes, int &ticks),
    updateTime(int &days, int &hours, int &minutes, int &ticks),
    displayTime(int &days, int &hours, int &minutes, int &ticks),
    //actionPrompt
        commandList(),
        gameMenu(),
        healthStatus(),
        abilitiesMenu(),
            attributes (
                int strength,
                int dexterity,
                int concentration,
                int intellect
            ),
            skills(),
        //examinePrompt
            examineZoneE_NE(),
                zoneE_NE_examineList(),
                examineTent(),
            examineZoneE_SE(),
                zoneE_SE_examineList(),
                examineColumnarBasalt(),
            examineGravelBeach(),
            examineLimestoneCliff(),
            examineOcean(),
        //grabLists
            grabListNullGeneric(),
            zoneE_NE_grabList(),
            zoneE_SE_grabList(),
        //digLists:
            zoneE_NE_digList(),
            zoneE_SE_digList(),
        debugTime(int &days, int &hours, int &minutes, int &ticks),
    outro(),
    launchSettings(std::string skipIntrosIndicator),
        startingAttributes(int &strength, int &dexterity, int &concentration, int &intellect);

void invalidInputResponse(std::string &input)
{ //Output Format Note: For the 64-char word wrap, add 26 to the total char's when calling this function
    std::cout << "\"" << input << "\" is not a valid input. ";
}

void startMenu() {
    std::cout
    << "Welcome to S3B: Origins! \n"
    << "1) New Game \n"
    << "2) Launch Settings \n"
    << "0) Quit Game \n"
    << "Enter a number: ";
}
    void newGameIntro() {
        std::cout << "\n"
        << "New Game Intro: \n"
        << "You are part of a survivalist research team that is currently \n"
        << "devoted to learning about the so-called Stone Age culture. This \n"
        << "has led to an experiment where researchers will be setting camp \n"
        << "in the wilderness to practice the art of primitive crafting. \n"
        << "\n"
        << "With great luck, your team has learned about a largely unknown \n"
        << "island, unofficially named \"Lima Island,\" that seems perfect \n"
        << "for the experiment. You have been designated to camp on the \n"
        << "eastern side of the island for half a month to practice crafting \n"
        << "one of the Stone Age's most common tools, the handaxe. \n"
        << std::endl
        << "Enter 1 to continue to your boat trip: ";
    }
    void boatIntro() {
        std::cout << "\n"
        << "Boat Intro: \n"
        << "Your team has secured a trip on a charter boat. After days of \n"
        << "planning and packing, your team sets out. You endure the long \n"
        << "and boring ride, which spans nearly two weeks. Fortunately, \n"
        << "your previous work on the team has earned you much experience \n"
        << "on the sea, so the sea sickness and cramped living conditions \n"
        << "were quite manageable. \n"
        << "\n"
        << "Finally, The captain announces that the island is in sight. You \n"
        << "step out to the bow with some of the crew to face the calm, \n"
        << "morning air, spending the next half-hour or so viewing the \n"
        << "approaching island. You can see the eastern side, where you \n"
        << "will be camping. It contains a massive cliffside met with a \n"
        << "barren gravel beach at its base. On the southern edge is a  \n"
        << "massive, cascading mound of jagged columnar basalt protruding \n"
        << "from the gravel. As the boat inches closer, The crew gets ready.\n"
        << std::endl
        << "Enter 1 to continue to the island: ";
    }
    void islandIntro() {
        std::cout << "\n"
        << "Island Intro: \n"
        << "The crew has arranged to drop you off and set camp while they \n"
        << "go set anchor at a safer spot on the island. A motorized skiff \n"
        << "is prepared to bring you, the supplies and some helpers to \n"
        << "shore. After several trips over and back, you and your small \n"
        << "group unload the last items and get ready to set camp. \n"
        << "\n"
        << "You and your group hustle in tandem to unpack the supplies and \n"
        << "pitch the tent, burning through much of the daylight hours. \n"
        << "Finally, as dusk approaches, your group take some last measures \n"
        << "to ensure that the campsite is finished before taking off in \n"
        << "the skiff back to the boat. A radiophone has been left with you \n"
        << "so you can contact the boat when you're ready to leave. \n"
        << "\n"
        << "As you settle down, you observe the campsite, which consists of \n"
        << "nothing more than a small canvas tent. There are enough \n"
        << "supplies here to last you at least two weeks here. As night \n"
        << "drifts in, you call it a hard day's work and begin to rest for \n"
        << "your big first day tomorrow. \n";
    }
    void statusUpdate(int &days, int &hours, int &minutes, int &ticks) {
        std::cout << "\n"
        << "You are wielding: nothing \n"; //This is where your currently equipped item will be displayed
        displayTime(days, hours, minutes, ticks);
    }
    void updateTime(int &days, int &hours, int &minutes, int &ticks) {
        while (ticks >= 12) {++minutes; ticks -= 12;}
        while (minutes >= 60) {++hours; minutes -= 60;}
        while (hours >= 24) {++days; hours -= 24;}
    }
    void displayTime(int &days, int &hours, int &minutes, int &ticks) {
        updateTime(days, hours, minutes, ticks);
        if (minutes >= 10) {
            std::cout << "You are on day " << days << "; The current time is: " << hours << ":" << minutes << " \n";
        }
        else {
            std::cout << "You are on day " << days << "; The current time is: " << hours << ":0" << minutes << " \n";
        }
    }
    //actionPrompt
        void commandList() {
            std::cout << "\n"
            << "Command List: \n"
            << "\"help\"/\"?\"        - Displays a list of available commands \n"
            << "\"menu\"/\"gm\"       - Opens the game menu \n"
            << "\"status\"/\"s\"      - Displays your current status \n"
            //<< "\"health\"/\"h\"      - Opens the health status menu \n"
            << "\"abilities\"/\"a\"   - Lets you access your attributes, skills and \n"
            << "    talent tree \n"
            //<< "\"inventory\"/\"i\"   - Opens your inventory to view your items and \n"
            //<< "    containers \n"
            //<< "\"craft\"/\"c\"       - Opens a list of craftable items \n"
            << "\"examine\"/\"e\"     - Uncovers details to your surroundings \n"
            << "\"grab\"/\"g\"        - Allows you to pick up and carry items \n"
            << "\"dig\"/\"d\"         - Opens a list of objects to dig/mine \n"
            << "\"travel\"/\"t\"      - Travel to the other side of the beach \n";
        }
        void gameMenu() {
            std::cout << "\n"
            << "Game Menu: \n"
            << "1) Return to Game \n"
            << "0) Quit to Start Menu \n"
            << "Enter a number: ";
        } /*
        void healthStatus() {
            std::cout << "\n"
            << "Health Status Menu: \n"
            << "* Health: 50/50 \n" //Health system to be added
            << "* Energy: 1000/1000 \n" //Energy system to be added
            << "* Body Temperature: 37 Degrees C \n" //Temperature system to be added
            << "\n"
            << "You have no health conditions. \n"; //This is where the list of health conditions will be displayed, if any
        } */
        void abilitiesMenu() {
            std::cout << "\n"
            << "Abilities Menu: \n"
            << "1) Attributes \n"
            << "2) Skills \n"
            << "0) *cancel* \n"
            << "Enter a number: ";
        }
            void attributes (
                int strength,
                int dexterity,
                int concentration,
                int intellect
            ) {
                std::cout << "\n"
                << "Attributes: \n"
                << "* Strength:      " << strength << " \n"
                << "* Dexterity:     " << dexterity << " \n"
                << "* Concentration: " << concentration << " \n"
                << "* Intellect:     " << intellect << " \n";
            }
            void skills() {
                std::cout << "\n"
                << "Crafting Skills: \n"
                << "* Knapping: lvl 0 \n";
            }
        //examinePrompt
            void examineZoneE_NE() {
                std::cout << "\n"
                << "Before you is your personally built campsite. The only thing \n"
                << "breaking the flatness of the beach is a small olive drab tent. \n"
                << "The tent stands just over 5 meters away from the rocks along \n"
                << "the cliffside to the west and about 12 meters from the drop-off \n"
                << "to the north, providing plenty of space away from the tides. \n"
                << "This setup is just about as minimalist as it can get. \n";
            }
                void zoneE_NE_examineList() {
                    std::cout << "\n"
                    << "Choose an object to examine: \n"
                    << "1) Zone: campsite \n"
                    << "2) tent \n"
                    << "3) gravel beach \n"
                    << "4) limestone cliff \n"
                    << "5) ocean \n"
                    << "0) *cancel* \n"
                    << "Enter a number: ";
                }
                void examineTent() {
                    std::cout << "\n"
                    << "The tent is composed of a thick, olive drab canvas, held up \n"
                    << "by some aluminum alloy poles and sockets, which merge at the \n"
                    << "top to form a shallow pyramid shape for the roof. The corners \n"
                    << "were driven into the gravel about half a meter for extra \n"
                    << "support. The tent is remarkably compact, bearing the dimensions \n"
                    << "of only around 3x4x4m. \n"
                    << "\n"
                    << "The interior, by contrast, appears much more homely, sporting a \n"
                    << "cot, a propane heater, two 150L water dispensers and two \n"
                    << "bedpans. Standing near a wall is a small metal bookshelf, \n"
                    << "supplied with numerous non-fiction pieces supporting the \n"
                    << "various subjects of your research team. Underneath the cot are \n"
                    << "two large duffle bags, containing your food rations, spare \n"
                    << "clothes, and some basic first-aid and hygiene supplies. The \n"
                    << "whole setup emits a general air of military-esque efficiency. \n";
                }
            void examineZoneE_SE() {
                std::cout << "\n"
                << "This end of the beach seems nearly identical to the other end, \n"
                << "the only noticable exception is the massive mound of columnar \n"
                << "basalt protruding from the southern edge of the beach. The \n"
                << "limestone cliff stands to the west, and the ocean, to the east. \n"
                << "This place has an obvious plainness to it. The campsite stands \n"
                << "more than 50m away. \n";
            }
                void zoneE_SE_examineList() {
                    std::cout << "\n"
                    << "Choose an object to examine: \n"
                    << "1) Zone: southern beach \n"
                    << "2) gravel beach \n"
                    << "3) limestone cliff\n"
                    << "4) ocean \n"
                    << "5) columnar basalt \n"
                    << "0) *cancel* \n"
                    << "Enter a number: ";
                }
                void examineColumnarBasalt() {
                    std::cout << "\n"
                    << "[columnar basalt examination text yet to be added] \n";
                }
            void examineGravelBeach() {
                std::cout << "\n"
                << "You find yourself standing on a huge mass of gravel, stretching \n"
                << "over 80m across and roughly 30m wide. There is hardly any slope \n"
                << "until it touches the shoreline, where the gravel steeply curves \n"
                << "downward into the ocean as a drop-off. The gravel has varying \n"
                << "shades of gray pebbles, mostly consisting of limestone. \n";
            }
            void examineLimestoneCliff() {
                std::cout << "\n"
                << "To the west is a massive limestone cliff, reaching up to around \n"
                << "30m tall, sloping slightly inward. Both ends of the cliff arc \n"
                << "several meters past the gravel beach and into deep waters, \n"
                << "denying any passage around. Peaking over its edge is some \n"
                << "brush and grass, the only traces of life. \n"
                << "\n"
                << "The cliff has a pale monotone of a light gray with a very \n"
                << "jagged and chalky texture. Its only break from plainness are \n"
                << "the large, flat specks of flint scattered across its surface. \n"
                << "The base of the cliff has large chunks of weathered limestone. \n"
                << "\n"
                << "GRAB OPTIONS: There are bits of small limestone rocks and flint \n"
                << "at the base of the cliff. \n";
            }
            void examineOcean() {
                std::cout << "\n"
                    << "[ocean examination text yet to be added] \n";
            }
        //grabLists
            void grabListNullGeneric() {
                std::cout << "\n"
                << "There is nothing you know of here for you to pick up. Try the \n"
                << "\"examine\" command to discover nearby items. \n";
            }
            void zoneE_NE_grabList() {
                std::cout << "\n"
                << "Choose an item to grab: \n"
                << "1) limestone rock (limestone cliff) \n"
                << "2) flint chunk (limestone cliff) \n"
                << "0) *cancel* \n"
                << "Enter a number: ";
            }
            void zoneE_SE_grabList() {
                std::cout << "\n"
                << "Choose an item to grab: \n"
                << "1) limestone rock (limestone cliff) \n"
                << "2) flint chunk (limestone cliff) \n"
                << "0) *cancel* \n"
                << "Enter a number: ";
            }
        //digLists
            void zoneE_NE_digList() {
                std::cout << "\n"
                << "Choose an area to dig: \n"
                << "1) gravel beach \n"
                << "2) limestone cliff \n"
                << "0) *cancel* \n"
                << "Enter a number: ";
            }
            void zoneE_SE_digList() {
                std::cout << "\n"
                << "Choose an area to dig: \n"
                << "1) gravel beach \n"
                << "2) limestone cliff \n"
                << "3) columnar basalt \n"
                << "0) *cancel* \n"
                << "Enter a number: ";
            }
        void debugTime(int &days, int &hours, int &minutes, int &ticks) {
            std::cout << "\n"
            << "** DEBUG TOOL - SET TIME ** \n";
            displayTime(days, hours, minutes, ticks);
            std::cout
            << "Choose a unit of time to modify... \n"
            << "1) Days \n"
            << "2) Hours \n"
            << "3) Minutes \n"
            << "4) Ticks (5 secs.) \n"
            << "0) *cancel* \n"
            << "Enter a number: ";
        }
    void outro() {
        std::cout << "\n"
        << "It's a crewmember on the other end. They tell you your time is \n"
        << "up and that they're on their way to pick you up. \n"
        << "\n"
        << "Before long, the boat pulls in from around the corner and \n"
        << "deploys a few crewmembers on the skiff. It is time to pack up. \n"
        << "\n"
        << "...And so goes the first team experiment. Thank you for playing!\n"
        << "\n"
        << "Enter 1 to quit to the Start Menu: ";
    }
    void launchSettings(std::string skipIntrosIndicator) {
        std::cout << "\n"
        << "Launch Settings: \n"
        << "a) Toggle Skip Intros: " << skipIntrosIndicator << "\n"
        << "b) Starting Attributes \n"
        << "z) Return to Start Menu \n"
        << "Enter a letter: ";
    }
        void startingAttributes(int &strength, int &dexterity, int &concentration, int &intellect) {
            std::cout << "\n"
            << "Difficulty Rating: 140/160 \n"
            << "Choose an attribute to modify: \n"
            << "1) Strength      - " << strength << " \n"
            << "2) Dexterity     - " << dexterity << " \n"
            << "3) Concentration - " << concentration << " \n"
            << "4) Intellect     - " << intellect << " \n"
            << "9) Reset attributes to Default \n"
            << "0) Return to Launch Settings \n"
            << "Enter a number: ";
        }

#endif
