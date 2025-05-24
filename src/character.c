#include "../include/character.h"


struct character move(struct character character, struct position position) {

    character.position = position;

    return character;
};
