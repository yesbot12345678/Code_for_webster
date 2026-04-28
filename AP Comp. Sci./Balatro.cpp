#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Jokers[] = 
{
        "joker", "greedy joker", "lusty Joker", "wrathful joker", "gluttonus joker", "jolly joker", 
        "zany joker", "mad joker", "crazy joker", "droll joker", "sly joker", "wily joker", "clever joker", "devious joker", 
        "crafty joker", "half joker", "joker stencil", "four fingers", "mime", "credit card", "cerimonial dagger", "banner",
        "mystic summit", "marble joker", "loyalty card", "8 ball", "misprint", "dusk", "raised fist", "chaos the clown",
        "fibonacci", "steel joker", "scary face", "abstract joker", "delayed gratification", "scholar", "business card",
        "supernova", "ride the bus", "space joker", "hack","pareidolia", "gros michel", "even steven", "odd tom",
        "egg", "burglar", "blackboard", "runner", "ice cream", "dna", "splash", "blue joker", "sixth sense", "constellation",
        "hiker", "faceless joker", "green joker", "superpostion", "to do list", "cavendish", "card sharp", "red card",
        "madness", "square joker", "seance", "riff-raff", "vampire", "shortcut", "hologram", "vagabond", "baron", "cloud 9",
        "rocket", "obelisk", "midas mask", "luchador", "photograph", "gift card", "turtle bean", "erosion", "reserveed parking",
        "mail-in rebate", "to the moon", "hallucination", "fortune", "juggler", "drunkard", "stone joker", "golden joker",
        "lucky cat", "basebal card", "bull", "diet cola", "trading card", "flash card", "popcorn", "spare trousers", 
        "ancient joker", "ramen", "walkie talkie", "seltzer", "castle", "smiley face", "campfire", "godlen ticket", "mr. bones",
        "acrobat", "sock and buskin", "swasbuckler", "troubadour", "certificate", "smeared joker", "throwback", "hanging chad",
        "rough gem", "bloodstone", "arrowhead", "onyx agate", "glass joker", "showman", "flower pot", "blueprint", "wee joker",
        "merry andy", "oops! all 6s", "the idol", "seeing double", "matador", "hit the road", "the duo", "the trio", "the family",
        "the order", "the tribe", "stuntman", "invisible joker", "brainstorm", "satellite", "shoot the moon", "driver's license",
        "cartomancer", "astronomer", "brunt joker", "bootstraps", "canio", "triboulet", "yorick", "chicot", "perkeo" 
};

string decks[] = 
{
        "red", "blue", "yellow", "green", "black", "magic", "nebula", "ghost", "abandoned", "checkered", "zodiac", "painted", "anaglyph", "plasma", "erratic"
};

string vouchers_base[] = 
{
        "overstock", "clearance sale", "hone", "reroll surplus", "crystal ball", "telescope", "grabber", "wasteful", "tarrot merchant", "planet merchant", 
         "seed money", "blank", "magic trick", "hieroglyph", "director's cut", "paint brush"
};

string vouchers_upgrade[] = 
{
        "overstock plus", "liquidation", "glow up", "reroll glut", "omen globe", "observatory", "nacho tong", "recyclomancy", "tarrot tycoon", "planet tycoon", 
        "money tree", "antomatter", "illusion", "petroglyph", "retcon", "palette"
};

string base_blinds[] = 
{
        "small", "big"
};

string boss_blinds[] = 
{
        "hook", "ox", "house", "wall", "wheel", "arm", "club", "fish", "psychic", "goad", "water", "window", "manacle", "eye", "mouth", "plant",
        "serpent", "pillar", "needle", "head", "tooth", "flint", "mark"
};

string ante8[] = 
{
        "amber acorn", "verdant leaf", "violet vessel", "crimson heart", "cerulean bell"
};

string tags[] = 
{
        "uncommon", "rare", "negative", "foil", "holographic", "polychome", "invesment", "voucher", "boss", "standard", "charm", "meteor",
        "buffoon", "handy", "garbage", "etheral", "coupon", "double", "juggle", "d6", "top-up", "speed", "orbital", "economy"
};

string booster_packs[] = 
{
        "arcana","arcana","arcana","arcana","jumbo arcana","jumbo arcana","mega arcana","mega arcana",
        "celestial","celestial","celestial","celestial","jumbo celestial","jumbo celestial","mega celestial","mega celestial",
        "standard","standard","standard","standard","jumbo standard","jumbo standard","mega standard","mega standard",
        "buffoon","buffoon","jumbo buffoon","mega buffoon",
        "spectral","spectral","jumbo spectral","mega spectral"
};

string tarrot[] = 
{
        "fool", "magician", "high priestess", "empress", "emperor", "hierophant", "lovers", "chariot", "justice", "hermit",
        "wheel of fortune", "strength", "hanged man", "death", "temperance", "devil", "tower", "star", "moon", "sun", "judgement", "world"
};

string planet[] = 
{
        "murcury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto", "planet x", " ceres", "eris"
};

string spectral[] = 
{
        "familiar", "grim", "incantation", "tailsman", "aura", "wraith", "sigil", "ouija", "ectoplasm", "immolate", "ankh",
        "deja vu", "hex", "terance", "medium", "cryptid", "soul", "black hole"
};

string edditions[] = 
{
        "base", "foil", "holographic", "polychrome", "negative"
};

string seals[] = 
{
        "gold", "red", "blue", "purple"
};

string enhancements[] = 
{
        "bonus", "mult", "wild", "glass", "steel", "stone", "gold", "lucky"
};


void Print_Shop(){
        vector<string> Shop(20, string(100, "[]"));
        for (int i = 0; i < 20; i++){
            for (int j = 0; j < 100; j++){
                cout << Shop[i][j];
            }
            cout << endl;
        }
}

int main(){

    Print_Shop();
    return 0;
}

void Print_Blind_Select(){
        
}

void Print_In_Game(){
        
}