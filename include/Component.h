#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
    virtual ~Component() {}
    virtual void draw() const = 0;
    virtual void tick() const = 0;
};

#endif
