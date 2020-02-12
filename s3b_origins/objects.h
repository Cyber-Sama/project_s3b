#ifndef OBJECTS_H
#define OBJECTS_H

//Object Declarations:
    enum mt
    {
        mt_gas,
        mt_liquid,
        mt_solid_uncons,
        mt_solid_rigid,
        mt_solid_fibrous,
        mt_solid_plastic,
        mt_solid_elastic
    };
    enum ct
    {
        ct_none,
        ct_scooper_porous,
        ct_scooper_nonPorous,
        ct_container_porous,
        ct_container_sealed
    };
    struct object
    {
        std::string name;
        std::string description;
        //Material Specs:
            mt materialType;
            float absoluteHardness;
    };
        struct terrain : public object{};
        struct item : public object
        {
        //Item Specs:
            float weight;
            ct containerType;
            float carryingCapacity;
        };
            struct tool : public item
            {
                //Tool Specs:
                    unsigned int baseDamage;
                    unsigned int condition;
            };

//Object Database:
    //Terrain:
        terrain flintNodules;
            flintNodules.name = "flint nodules";
            flintNodules.description = 
                "This area of rock has a light gray, chalky texture with chunks \n"
                "of a slightly glossy, smooth, dark gray material in it. \n";
            //Material Specs:
                flintNodules.materialType = mt_solid_rigid;
                flintNodules.absoluteHardness = 55;
    //Items:
        item backpack;
            backpack.name = "backpack";
            backpack.description = 
                "[insert backpack examination details here] \n";
            //Material Specs:
                backpack.materialType = mt_solid_plastic;
                backpack.absoluteHardness = 5;
                //Item Specs:
                    backpack.weight = 0;
                    backpack.containerType = ct_container_porous;
                        backpack.carryingCapacity = 25;
        //Rocks:
            item limestoneRockSmall;
                limestoneRockSmall.name = "small limestone rock";
                limestoneRockSmall.description = 
                "This rock spans only about 8cm in diameter and fits in the palm \n"
                "of your hand. Its edges are highly jagged. It is dull gray in \n"
                "color and has a chalky texture. \n";
                //Material Specs:
                    limestoneRockSmall.materialType = mt_solid_rigid;
                    limestoneRockSmall.absoluteHardness = 12;
                    //Item Specs:
                        limestoneRockSmall.weight = 0.65;
                        limestoneRockSmall.containerType = ct_none;
            //Flint:
                item flintShardSmall;
                    flintShardSmall.name = "small flint shard";
                    flintShardSmall.description = 
                    "A small piece of flint, no more than 4cm in length. It is dark gray in \n"
                    "color and has a glossy texture that emphasizes the dull, shallow ridges \n"
                    "cascading across its surface. \n";
                    //Material Specs:
                        flintShardSmall.materialType = mt_solid_rigid;
                        flintShardSmall.absoluteHardness = 100;
                        //Item Specs:
                            flintShardSmall.weight = 0.03;
                            flintShardSmall.containerType = ct_none;
                item flintShardLarge;
                    flintShardSmall.name = "large flint shard";
                    flintShardSmall.description = 
                    "A piece of flint around 8cm in length. It is dark gray in color and has \n"
                    "a glossy texture that emphasizes the dull, shallow ridges cascading \n"
                    "across its surface. \n";
                    //Material Specs:
                        flintShardLarge.materialType = mt_solid_rigid;
                        flintShardLarge.absoluteHardness = 100;
                        //Item Specs:
                            flintShardLarge.weight = 0.08;
                            flintShardSmall.containerType = ct_none;
                item flintChunk;
                    flintChunk.name = "flint chunk";
                    flintChunk.description = 
                    "A crude chunk of flint about 12cm in diameter. It is dark gray in color \n"
                    "and has a glossy texture that emphasizes the protruding and jagged \n"
                    "ridges that cascade across its surface. Its seems rather suitable for \n"
                    "etching blades out of it. \n";
                    //Material Specs:
                        flintChunk.materialType = mt_solid_rigid;
                        flintChunk.absoluteHardness = 100;
                        //Item Specs:
                            flintChunk.weight = 3;
                            flintShardSmall.containerType = ct_none;
        //Tools:
            tool handaxe;
                handaxe.name = "handaxe";
                handaxe.description = 
                    "A fairly sizable tool just over 10cm in length. It has a \n"
                    "tapered edge forming a crude but sharp wedge. It is dark gray \n"
                    "in color and has a glossy texture that emphasizes the \n"
                    "intricate, shallow ridges that cascade across its surface. \n";
                //Material Specs:
                    handaxe.materialType = mt_solid_rigid;
                    handaxe.absoluteHardness = 100;
                    //Item Specs:
                        handaxe.weight = 2.4;
                        handaxe.containerType = ct_none;
                        //Tool Specs:
                            handaxe.baseDamage = 1;

#endif
