#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	BlockID c = createConcrete(COLOR_BLUE, true);
	locateConcrete(c, 10, 4, 10);

	return 0;
}