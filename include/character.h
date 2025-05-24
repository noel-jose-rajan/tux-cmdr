#ifndef CHARACTER_H
#define CHARACTER_H

struct position {
    int x;
    int y;
};

struct character {
    struct position position;
};

// Function declaration (note the semicolon and correct spelling)
struct character move(struct character character, struct position position);

#endif // CHARACTER_H
