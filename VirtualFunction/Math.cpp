#include "Math.h"

Math::Math() : Norm(0) {}

Math::Math(const Math& other) : Norm(other.Norm) {}

Math::~Math() {}

double Math::Get_Norm() { return Norm; }