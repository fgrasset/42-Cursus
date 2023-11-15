#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Incospicuous Red-brick Wall")
{

}

BrickWall::~BrickWall()
{

}

BrickWall	*BrickWall::clone() const
{
	return (new BrickWall());
}
