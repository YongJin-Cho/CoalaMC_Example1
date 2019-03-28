#define _CRT_SECURE_NO_WARNINGS			// scanf의 보안 오류를 무시하기 위한 선언

#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

void fillBlockXYZ(BlockID block, int sx, int sy, int sz, int ex, int ey, int ez)
{
	for (int x = sx; x <= ex; x++) {
		for (int y = sy; y <= ey; y++) {
			for (int z = sz; z <= ez; z++) {
				locateBlock(block, x, y, z);
			}
		}
	}
}

void makeRoom(int sx, int sy, int sz, int ex, int ey, int ez)
{
	BlockID air = createBlock(BLOCK_AIR);
	fillBlockXYZ(air, sx, sy, sz, ex, ey, ez);

	const int torch_distance = 2;
	int torchY = sy + 2;
	if (torchY > ey) {
		torchY = ey;
	}

	TorchID torch = createTorch();
	for (int x = sx + 1; x < ex; x += torch_distance) {
		installTorch(torch, x, torchY, sz, FACING_SOUTH);
	}

	for (int x = ex - 1; x > sx; x -= torch_distance) {
		installTorch(torch, x, torchY, ez, FACING_NORTH);
	}

	for (int z = sz + 1; z < ez; z += torch_distance) {
		installTorch(torch, sx, torchY, z, FACING_EAST);
	}

	for (int z = ez - 1; z > sz; z -= torch_distance) {
		installTorch(torch, ex, torchY, z, FACING_WEST);
	}
}

#define SWAP(s,e)		{ int t = s; s = e; e = t; }
int main()
{
	int sx, sy, sz, ex, ey, ez;
	scanf("%d %d %d %d %d %d", &sx, &sy, &sz, &ex, &ey, &ez);

	if (sx > ex) SWAP(sx, ex);
	if (sy > ey) SWAP(sy, ey);
	if (sz > ez) SWAP(sz, ez);

	makeRoom(sx, sy, sz, ex, ey, ez);

	return 0;
}