#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string input;
    std::string wieldedTool;
    std::string targetMaterial;

    //Object Declarations
        struct object {
            std::string name;
            std::string description;
            //Material Specs
                std::string materialType; //Available MT's: Rigid Solid, Plastic Solid
                float absoluteHardness;
        };
            struct terrain : public object{};
            struct item : public object {
            //Item Specs
                float weight;
                std::string containerType; //Available CT's: None, Porous Container, Sealed Container
                float carryingCapacity;
            };
                struct tool : public item {
                    //Tool Specs
                        unsigned int baseDamage;
                        unsigned int condition;
                        //Strike Type Ratings
                            unsigned int pierceDamageRating;
                            unsigned int bluntDamageRating;
                            unsigned int chopDamageRating;
                            unsigned int sliceDamageRating;
                };
    //Object Database
        //Terrain
            //Rocks
                terrain limestone;
                    limestone.name = "limestone";
                    limestone.description = "... \n";
                    //Material Properties
                        limestone.materialType = "Rigid Solid";
                        limestone.absoluteHardness = 12;
                terrain basalt;
                    basalt.name = "basalt";
                    basalt.description = "... \n";
                    //Material Properties
                        basalt.materialType = "Rigid Solid";
                        basalt.absoluteHardness = 80;
        //Items
            //Tools
                tool handaxe;
                handaxe.name = "handaxe";
                handaxe.description = 
                    "A fairly sizable tool just over 10cm in length. It has a \n"
                    "tapered edge forming a crude but sharp wedge. It is dark gray \n"
                    "in color and has a glossy texture that emphasizes the \n"
                    "intricate, shallow ridges that cascade across its surface. \n";
                //Material Specs
                    handaxe.materialType = "Rigid Solid";
                    handaxe.absoluteHardness = 100;
                    //Item Specs
                        handaxe.weight = 2.4;
                        handaxe.containerType = "None";
                        //Tool Specs
                            handaxe.baseDamage = 1;
    //Material Damage Formulas
        struct toolDamageMultiplier {
            float damage;
            float baseDamage;
            float strikeTypeDamage;
            //Hardness Damage Multiplier
                float hardnessDamage;
                float hardnessDecimalFraction;
                float targetMaterialHardness;
                float wieldedToolHardness;
            float hardnessDamageEquation(float &hardnessDamage) {
                std::pow (hardnessDamage = 2.25, ( -(targetMaterialHardness/wieldedToolHardness) + 1) );
                return hardnessDamage;
            }
            float toolDamageEquation(float &damage) {
                damage = baseDamage * strikeTypeDamage * hardnessDamage;
                return damage;
            }
        };

    startMenu:
    std::cout
    << "S3B Striking System Tester \n"
    << "Enter 1 to begin. \n"
    << "Enter 0 to quit. \n"
    << "Enter a number: ";
    for(;;) {
        getline (std::cin, input);
        if (input == "1") {
            selectTool:
            std::cout << "\n"
            << "Select a tool to wield... \n"
            << "1) " << handaxe.name << "\n"
            << "0) *quit to start* \n"
            << "Enter a number: ";
            for(;;) {
                getline (std::cin, input);
                if (input == "1") {
                    wieldedTool = handaxe.name;
                    std::cout << "\n"
                    << "Select a target material to strike... \n"
                    << "1) " << limestone.name << " \n"
                    << "2) " << basalt.name << " \n"
                    << "0) *go back* \n"
                    << "Enter a number: ";
                    for(;;) {
                        getline (std::cin, input);
                        if (input == "0")
                            goto selectTool;
                        else
                            continue;
                    }
                }
                else if (input == "0") {
                    std::cout << std::endl;
                    goto startMenu;
                }
                else
                    continue;
            }
        }
        else if (input == "0") {
            std::cout << std::endl;
            return 0;
        }
        else
            continue;
    }
}
