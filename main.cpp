//Game To-Do List:
//* Add inventory system
//* Add debug tool for spawning items
//* Write examination details
//  * ocean
//  * columnarBasalt

//Output Format Guidelines:
//* There is a manually-added word-wrap that follows a limit of 64 chars per line
//* Spaces are added after every line, in case copy-paste formatting ignores line breaks
//* Line breaks are added before every output that immediately follows an input EXCEPT input error messages
//* Line breaks are added before every "goto startMenu;" expression

//Coding Guidelines:
//* Whenever time is added, it must be preceded by "updateTime(days, hours, minutes, ticks);" so it can queue the resting prompt when past hour 20

#include <cstdlib>
#include <iostream>
#include <string>

#include "interfaces.h"

int main() {
    //Interface Variables
        std::string input;
        std::string skipIntrosIndicator = "On";
        bool skipIntros = true; //DEBUG NOTE: Turn skip intros off again before release

    //Environmental Variables
        //Time Variables
            int days, hours, minutes, ticks;
            const int deadlineDay = 15;
        
        //Zone Variable
            std::string zone; //Available zones: "E-NE", "E-SE"

        //"Examination Memory" Flags:    -allows player to re-examine areas without costing time
            bool zoneE_NE_examined, zoneE_SE_examined, tent_examined, pitLatrine_examined, 
            gravelBeach_examined, limestoneCliff_examined, ocean_examined, columnarBasalt_examined;

        //Grab Option Flags    -enables player to grab certain items after examining their respective area
            bool limestoneCliff_grabOptions;

    #include "objects.h"

    //Player Attributes
        int
        strength      = 15,
        dexterity     = 15,
        concentration = 15,
        intellect     = 15;

    startMenu:
        //Environmental Initializers
            zone = "E-NE";
            days = 1, hours = 6, minutes = 0, ticks = 0;

        //"Examination Memory" Initializers
            zoneE_NE_examined = zoneE_SE_examined = tent_examined = pitLatrine_examined = 
            gravelBeach_examined = limestoneCliff_examined = ocean_examined = columnarBasalt_examined = 
            false;

        //Grab Option Initializers
            limestoneCliff_grabOptions = false;

    startMenu();
    // 1 = New Game
    // 2 = Launch Settings
    // 0 = Quit Game
    for(;;) {
        getline (std::cin, input);
        if (input == "1") {
            if (skipIntros == false) {
                newGameIntro();
                for(;;) {
                    getline (std::cin, input);
                    if (input == "1") {
                        boatIntro();
                        for(;;) {
                            getline (std::cin, input);
                            if (input == "1") {
                                islandIntro();
                                goto newGamePrompt;
                            }
                            else {
                                invalidInputResponse(input);
                                std::cout
                                << "Please enter 1 to continue to the \n"
                                << "campsite: ";
                                continue;
                            }
                        }
                    }
                    else {
                        invalidInputResponse(input);
                        std::cout
                        << "Please enter 1 to continue to your \n"
                        << "trip to the island: ";
                        continue;
                    }
                }
            }
            newGamePrompt:
            std::cout << std::endl
            << "When you're ready to start your first morning, enter 1: ";
            for(;;) {
                getline (std::cin, input);
                if (input == "1") {
                    statusUpdate(days, hours, minutes, ticks);
                    actionPrompt:
                    for(;;) {
                        while (hours >= 6 && hours < 20) { //"Day Time" conditional - queues resting prompt when exceeded
                            while (days < deadlineDay) { //"Deadline" conditional - queues outro prompt when exceeded
                                std::cout << "\n"
                                << "Enter a command: ";
                                getline (std::cin, input);
                                //Main Inputs
                                if (input == "help" || input == "?") {
                                    commandList();
                                    continue;
                                }
                                else if (input == "menu" || input == "gm") {
                                    gameMenu:
                                    gameMenu();
                                    // 1 = Return to Game
                                    // 0 = Quit to Start Menu
                                    for(;;) {
                                        getline (std::cin, input);
                                        if (input == "1")
                                            goto actionPrompt;
                                        else if (input == "0") {
                                            std::cout << "\n"
                                            << "Are you sure you want to quit? All progress will be lost. \n"
                                            << "Enter q to quit or c to cancel back to the game menu: ";
                                            for(;;) {
                                                getline (std::cin, input);
                                                if (input == "q") {
                                                    std::cout << "\n";
                                                    goto startMenu;
                                                }
                                                else if (input == "c")
                                                    goto gameMenu;
                                                else {
                                                    invalidInputResponse(input);
                                                    std::cout
                                                    << "Please enter either q to quit to the \n"
                                                    << "start menu or c to cancel back to the game menu: ";
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            invalidInputResponse(input);
                                            std::cout << "Please enter either 1 or 0: ";
                                            continue;
                                        }
                                    }
                                }
                                else if (input == "status" || input == "s") {
                                    statusUpdate(days, hours, minutes, ticks);
                                    continue;
                                }
                                else if (input == "abilities" || input == "a") {
                                    abilitiesMenu:
                                    abilitiesMenu();
                                    // 1 = Attributes
                                    // 2 = Skills
                                    // 0 = *cancel*
                                    for(;;) {
                                        getline (std::cin, input);
                                        if (input == "1") {
                                            attributes
                                            (
                                                strength,
                                                dexterity,
                                                concentration,
                                                intellect
                                            );
                                            goto abilitiesMenu;
                                        }
                                        else if (input == "2") {
                                            skills();
                                            goto abilitiesMenu;
                                        }
                                        else if (input == "0")
                                            goto actionPrompt;
                                        else {
                                            invalidInputResponse(input);
                                            std::cout << "Please enter either 1, 2 or 0: ";
                                            continue;
                                        }
                                    }
                                }
                                else if (input == "examine" || input == "e") {
                                    if (zone == "E-NE") {
                                        if (zoneE_NE_examined == false) {
                                            std::cout << "\n"
                                            << "Would you like to examine the current zone: campsite? y/n: ";
                                            for(;;) {
                                                getline (std::cin, input);
                                                if (input == "y") {
                                                    ticks += 4; updateTime(days, hours, minutes, ticks);
                                                    zoneE_NE_examined = true;
                                                    examineZoneE_NE();
                                                    break;
                                                }
                                                else if (input == "n")
                                                    goto actionPrompt;
                                                else {
                                                    invalidInputResponse(input);
                                                    std::cout << "Enter y to examine or n to cancel: "; continue;
                                                }
                                            }
                                        }
                                        zoneE_NE_examineList:
                                        zoneE_NE_examineList();
                                        // Examine List
                                        // 1 = Zone: campsite
                                        // 2 = tent
                                        // 3 = gravel beach
                                        // 4 = limestone cliff
                                        // 5 = ocean
                                        // 0 = *cancel*
                                        for(;;) {
                                            getline (std::cin, input);
                                            if (input == "1") {
                                                examineZoneE_NE();
                                                goto zoneE_NE_examineList;
                                            }
                                            if (input == "2") {
                                                if (tent_examined == false) {
                                                    ticks += 6; updateTime(days, hours, minutes, ticks);
                                                    tent_examined = true;
                                                    examineTent();
                                                    goto zoneE_NE_examineList;
                                                }
                                                else if (tent_examined == true) {
                                                    examineTent();
                                                    goto zoneE_NE_examineList;
                                                }
                                            }
                                            if (input == "3") {
                                                if (gravelBeach_examined == false) {
                                                    ticks += 3; updateTime(days, hours, minutes, ticks);
                                                    gravelBeach_examined = true;
                                                    examineGravelBeach();
                                                    goto zoneE_NE_examineList;
                                                }
                                                else if (gravelBeach_examined == true) {
                                                    examineGravelBeach();
                                                    goto zoneE_NE_examineList;
                                                }
                                            }
                                            if (input == "4") {
                                                if (limestoneCliff_examined == false) {
                                                    ticks += 3; updateTime(days, hours, minutes, ticks);
                                                    limestoneCliff_examined = true;
                                                    limestoneCliff_grabOptions = true;
                                                    examineLimestoneCliff();
                                                    goto zoneE_SE_examineList;
                                                }
                                                else if (limestoneCliff_examined == true) {
                                                    examineLimestoneCliff();
                                                    goto zoneE_SE_examineList;
                                                }
                                            }
                                            if (input == "5") {
                                                if (ocean_examined == false) {
                                                    ticks += 2; updateTime(days, hours, minutes, ticks);
                                                    ocean_examined = true;
                                                    examineOcean();
                                                    goto zoneE_NE_examineList;
                                                }
                                                else if (ocean_examined == true) {
                                                    examineOcean();
                                                    goto zoneE_NE_examineList;
                                                }
                                            }
                                            if (input == "0")
                                                goto actionPrompt;
                                            else {
                                                invalidInputResponse(input);
                                                std::cout 
                                                << "Please enter a number between 1-5 or \n"
                                                << "enter 0 to cancel back to the action prompt: ";
                                                continue;
                                            }
                                        }
                                    }
                                    else if (zone == "E-SE") {
                                        if (zoneE_SE_examined == false)
                                        {
                                            std::cout << "\n"
                                            << "Would you like to examine the current zone: southern beach? \n"
                                            << "y/n: ";
                                            for(;;) {
                                                getline (std::cin, input);
                                                if (input == "y") {
                                                    ticks += 2; updateTime(days, hours, minutes, ticks);
                                                    zoneE_SE_examined = true;
                                                    examineZoneE_SE();
                                                    break;
                                                }
                                                else if (input == "n")
                                                    goto actionPrompt;
                                                else {
                                                    invalidInputResponse(input);
                                                    std::cout << "Enter y to examine or n to cancel: "; continue;
                                                }
                                            }
                                        }
                                        zoneE_SE_examineList:
                                        zoneE_SE_examineList();
                                        // 1 = Zone: southern beach
                                        // 2 = gravel beach
                                        // 3 = limestone cliff
                                        // 4 = ocean
                                        // 5 = columnar basalt
                                        // 0 = *cancel*
                                        for(;;) {
                                            getline (std::cin, input);
                                            if (input == "1") {
                                                examineZoneE_SE();
                                                goto zoneE_SE_examineList;
                                            }
                                            if (input == "2") {
                                                if (gravelBeach_examined == false) {
                                                    ticks += 3; updateTime(days, hours, minutes, ticks);
                                                    gravelBeach_examined = true;
                                                    examineGravelBeach();
                                                    goto zoneE_SE_examineList;
                                                }
                                                else if (gravelBeach_examined == true) {
                                                    examineGravelBeach();
                                                    goto zoneE_SE_examineList;
                                                }
                                            }
                                            if (input == "3") {
                                                if (limestoneCliff_examined == false) {
                                                    ticks += 3; updateTime(days, hours, minutes, ticks);
                                                    limestoneCliff_examined = true;
                                                    limestoneCliff_grabOptions = true;
                                                    examineLimestoneCliff();
                                                    goto zoneE_SE_examineList;
                                                }
                                                else if (limestoneCliff_examined == true) {
                                                    examineLimestoneCliff();
                                                    goto zoneE_SE_examineList;
                                                }
                                            }
                                            if (input == "4") {
                                                if (ocean_examined == false) {
                                                    ticks += 2; updateTime(days, hours, minutes, ticks);
                                                    ocean_examined = true;
                                                    examineOcean();
                                                    goto zoneE_SE_examineList;
                                                }
                                                else if (ocean_examined == true) {
                                                    examineOcean();
                                                    goto zoneE_SE_examineList;
                                                }
                                            }
                                            if (input == "5") {
                                                if (columnarBasalt_examined == false) {
                                                    ticks += 3; updateTime(days, hours, minutes, ticks);
                                                    columnarBasalt_examined = true;
                                                    examineColumnarBasalt();
                                                    goto zoneE_SE_examineList;
                                                }
                                                else if (columnarBasalt_examined == true) {
                                                    examineColumnarBasalt();
                                                    goto zoneE_SE_examineList;
                                                }
                                            }
                                            else if (input == "0")
                                                goto actionPrompt;
                                            else {
                                                invalidInputResponse(input);
                                                std::cout 
                                                << "Please enter a number between 1-5 or \n"
                                                << "enter 0 to cancel back to the action prompt: ";
                                                continue;
                                            }
                                        }
                                    }
                                }
                                else if (input == "grab" || input == "g") { //NOTE: The current grab system is a placeholder and needs to be changed in the future {
                                    if (zone == "E-NE")
                                    {
                                        if (limestoneCliff_grabOptions == false) {
                                            std::cout << "\n"
                                            << "It appears that there's nothing more you need to take from the \n"
                                            << "campsite that you don't already possess. You can try searching \n"
                                            << "the wilderness for materials to pick up. \n";
                                            continue;
                                        }
                                        else if (limestoneCliff_grabOptions == true) {
                                            zoneE_NE_grabList();
                                            // 1 = small limestone rock
                                            // 2 = flint chunk
                                            // 0 = *cancel*
                                            for (;;) {
                                                getline (std::cin, input);
                                                if (input == "0")
                                                    goto actionPrompt;
                                                else {
                                                    std::cout << "\n"
                                                    << "The grab feature is still in development. You will be returned \n"
                                                    << "to the action prompt. \n";
                                                    goto actionPrompt;
                                                }
                                            }
                                        }
                                    }
                                    else if (zone == "E-SE") {
                                        if (limestoneCliff_grabOptions == false) {
                                            grabListNullGeneric();
                                            continue;
                                        }
                                        if (limestoneCliff_grabOptions == true) {
                                            zoneE_SE_grabList();
                                            // 1 = small limestone rock
                                            // 2 = flint chunk
                                            // 0 = *cancel*
                                            for (;;) {
                                                getline (std::cin, input);
                                                if (input == "0")
                                                    goto actionPrompt;
                                                else {
                                                    std::cout << "\n"
                                                    << "The grab feature is still in development. You will be returned \n"
                                                    << "to the action prompt. \n";
                                                    goto actionPrompt;
                                                }
                                            }
                                        }
                                    }
                                }
                                else if (input == "dig" || input == "d") {
                                    if (zone == "E-NE")
                                    {
                                        zoneE_NE_digList:
                                        zoneE_NE_digList();
                                        // 1 = gravel beach
                                        // 2 = limestone cliff
                                        // 0 = *cancel*
                                        for(;;) {
                                            getline (std::cin, input);
                                            if (input == "1") {
                                                ticks += 4; updateTime(days, hours, minutes, ticks);
                                                std::cout << "\n"
                                                << "You bend down and start digging through the gravel with your \n"
                                                << "hands. It doesn't take long before the surface gravel reveals \n"
                                                << "even larger and more immovable rocks. Your digging doesn't \n"
                                                << "appear to have any use. \n";
                                                goto zoneE_NE_digList;
                                            }
                                            else if (input == "0")
                                                goto actionPrompt;
                                            else {
                                                std::cout << "\n"
                                                << "Sorry, the dig feature is still in development. \n"
                                                << "You will be returned to the action prompt. \n";
                                                goto actionPrompt;
                                            }
                                        }
                                    }
                                    if (zone == "E-SE") {
                                        zoneE_SE_digList:
                                        zoneE_SE_digList();
                                        // 1 = gravel beach
                                        // 2 = limestone cliff
                                        // 3 = columnar basalt
                                        // 0 = *cancel*
                                        for(;;) {
                                            getline (std::cin, input);
                                            if (input == "1") {
                                                ticks += 4; updateTime(days, hours, minutes, ticks);
                                                std::cout << "\n"
                                                << "You bend down and start digging through the gravel with your \n"
                                                << "hands. It doesn't take long before the surface gravel reveals \n"
                                                << "even larger and more immovable rocks. Your digging doesn't \n"
                                                << "appear to have any use. \n";
                                                goto zoneE_SE_digList;
                                            }
                                            else if (input == "0")
                                                goto actionPrompt;
                                            else {
                                                std::cout << "\n"
                                                << "Sorry, the dig feature is still in development. \n"
                                                << "You will be returned to the action prompt. \n";
                                                goto actionPrompt;
                                            }
                                        }
                                    }
                                }
                                else if (input == "travel" || input == "t") {
                                    if (zone == "E-NE")
                                    {
                                        std::cout << "\n"
                                        << "Would you like to travel to the south side of the gravel beach? \n"
                                        << "It is about half a minute's travel. y/n: ";
                                        for(;;) {
                                            getline (std::cin, input);
                                            if (input == "y") {
                                                ticks += 5; updateTime(days, hours, minutes, ticks);
                                                zone = "E-SE";
                                                std::cout << "\n"
                                                << "You are now at the southern end of the gravel beach. \n";
                                                goto actionPrompt;
                                            }
                                            else if (input == "n")
                                                goto actionPrompt;
                                            else {
                                                invalidInputResponse(input);
                                                std::cout
                                                << "Please enter either y \n"
                                                << "to take a minute to travel to the southern side of the gravel \n"
                                                << "beach or n to cancel: ";
                                                continue;
                                            }
                                        }
                                    }
                                    if (zone == "E-SE") {
                                        std::cout << "\n"
                                        << "Would you like to travel back to the campsite? \n"
                                        << "It is about half a minute's travel. y/n: ";
                                        for(;;) {
                                            getline (std::cin, input);
                                            if (input == "y") {
                                                ticks += 5; updateTime(days, hours, minutes, ticks);
                                                zone = "E-NE";
                                                std::cout << "\n"
                                                << "You are now at the campsite. \n";
                                                goto actionPrompt;
                                            }
                                            else if (input == "n")
                                                goto actionPrompt;
                                            else {
                                                invalidInputResponse(input);
                                                std::cout
                                                << "Please enter either y \n"
                                                << "to take a minute to travel back to the campsite or n to \n"
                                                << "cancel: ";
                                                continue;
                                            }
                                        }
                                    }
                                }
                                //Alternative Inputs
                                else if (input == "check" || input == "look" || input == "observe" || input == "search" || input == "view") {
                                    std::cout << "\n"
                                    << "It seems like you are trying to observe your surroundings. Try \n"
                                    << "using the \"examine\" command. \n";
                                    continue;
                                }
                                else if (input == "climb") {
                                    std::cout << "\n"
                                    << "Sorry, climbing is not a feature in this game. If you want to \n"
                                    << "view the possible areas to travel to, try the \"travel\" \n"
                                    << "command. \n";
                                    continue;
                                }
                                else if (input == "move" || input == "run" || input == "walk") {
                                    std::cout << "\n"
                                    << "It seems like you are trying to move to another location. \n"
                                    << "Try the \"travel\" command. \n";
                                    continue;
                                }
                                else if (input == "mine") {
                                    std::cout << "\n"
                                    << "If you want to try mining something, try the \"dig\" command. \n";
                                    continue;
                                }
                                else if (input == "map") {
                                    std::cout << "\n"
                                    << "You don't have a map. \n";
                                    continue;
                                }
                                else if (input == "attack" || input == "hit") {
                                    std::cout << "\n"
                                    << "Does this look like a combat RPG to you? If you want to try to \n"
                                    << "\"" << input << "\" an object, go for the \"dig\" command. \n";
                                    continue;
                                }
                                else if (input == "rest" || input == "sleep") {
                                    std::cout << "\n"
                                    << "You can't rest here. \n";
                                    continue;
                                }
                                else if (input == "equipment" || input == "backpack" || input == "bag" || input == "inv") {
                                    std::cout << "\n"
                                    << "It seems like you are trying to access your inventory. Try the \n"
                                    << "\"inventory\" or \"i\" command. \n";
                                    continue;
                                }
                                //Debug Inputs
                                else if (input == "db_t") {
                                    debugTime:
                                    debugTime(days, hours, minutes, ticks);
                                    // 1 = Days
                                    // 2 = Hours
                                    // 3 = Minutes
                                    // 4 = Ticks
                                    // 0 = *cancel*
                                    for(;;) {
                                        getline (std::cin, input);
                                        if (input == "1") {
                                            std::cout << "\nEnter a number to adjust the days: ";
                                            std::cin >> days;
                                            goto debugTime;
                                        }
                                        else if (input == "2") {
                                            std::cout << "\nEnter a number to adjust the hours: ";
                                            std::cin >> hours;
                                            goto debugTime;
                                        }
                                        else if (input == "3") {
                                            std::cout << "\nEnter a number to adjust the minutes: ";
                                            std::cin >> minutes;
                                            goto debugTime;
                                        }
                                        else if (input == "4") {
                                            std::cout << "\nEnter a number to adjust the ticks: ";
                                            std::cin >> ticks;
                                            goto debugTime;
                                        }
                                        else if (input == "0")
                                            goto actionPrompt;
                                    }
                                }
                                //Invalid Input
                                else {
                                    invalidInputResponse(input);
                                    std::cout
                                    << "Enter \"help\" for a list of commands. \n";
                                    continue;
                                }
                            }
                            //Endgame Prompt
                            std::cout << "\n"
                            << "Suddenly, an incoming call is picked up on your radiophone. \n"
                            << "Enter 1 to answer back: ";
                            for(;;) {
                                getline (std::cin, input);
                                if (input == "1") {
                                    outro();
                                    for(;;) {
                                        getline (std::cin, input);
                                        if (input == "1") {
                                            std::cout << "\n";
                                            goto startMenu;
                                        }
                                        else {
                                            invalidInputResponse(input);
                                            std::cout
                                            << "Please enter 1 to quit to the Start \n"
                                            << "Menu: ";
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    invalidInputResponse(input);
                                    std::cout << "Please enter 1 to answer the call: ";
                                    continue;
                                }
                            }
                        }
                        //Resting Prompt
                        std::cout << "\n"
                        << "It's getting late. Time for you to head back to camp and call \n"
                        << "it a night. \n"
                        << "\n"
                        << "Enter 1 to continue to the next morning: ";
                        for(;;) {
                            getline (std::cin, input);
                            if (input == "1") {
                                zone = "E-NE";
                                days += 1; hours = 6; minutes = 0; ticks = 0;
                                std::cout << "\n"
                                << "You wake up and embrace the cool morning air... ";
                                statusUpdate(days, hours, minutes, ticks);
                                goto actionPrompt;
                            }
                            else {
                                invalidInputResponse(input);
                                std::cout
                                << "Please enter 1 to continue to the \n"
                                << "next morning: ";
                                continue;
                            }
                        }
                    }
                }
                else {
                    invalidInputResponse(input);
                    std::cout
                    << "Please enter 1 to start your first \n"
                    << "morning: ";
                    continue;
                }
            }
        }
        else if (input == "2") {
            launchSettings:
            launchSettings(skipIntrosIndicator);
            // a = Toggle Skip Intros
            // b = Starting Attributes
            // z = Return to Start Menu
            for(;;) {
                getline (std::cin, input);
                if (input == "a") {
                    if (skipIntros == false) {
                        skipIntros = true;
                        skipIntrosIndicator = "On";
                    }
                    else if (skipIntros == true) {
                        skipIntros = false;
                        skipIntrosIndicator = "Off";
                    }
                    std::cout << "\n"
                    << "Skip intros has been set to: " << skipIntrosIndicator << "\n";
                    goto launchSettings;
                }
                else if (input == "b") {
                    startingAttributes(strength, dexterity, concentration, intellect);
                    for(;;) {
                        getline (std::cin, input);
                        if (input == "0")
                            goto launchSettings;
                        else {
                            std::cout << "\n"
                            << "Sorry, the attributes settings are in development. \n"
                            << "You will be returned to Launch Settings. \n";
                            goto launchSettings;
                        }
                    }
                }
                else if (input == "z") {
                    std::cout << "\n";
                    goto startMenu;
                }
                else {
                    invalidInputResponse(input);
                    std::cout << "Please enter either a, b or z: ";
                    continue;
                }
            }
        }
        else if (input == "0") {
            std::cout << "\n";
            return 0;
        }
        else {
            invalidInputResponse(input);
            std::cout << "Please enter either 1, 2 or 0: ";
            continue;
        }
    }
}
