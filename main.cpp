#include <iostream>
#include <string>
using namespace std;
int main()
{
	int numbcommon = 1;
	int numblegendary = 2;
	int randnumb;
	string weapon;
	string weapontype[] = { "Auto Rifle", "Scout Rifle", "Bow", "Sub-machine Gun", "Sidearm", "Handcannon", "Shotgun", "Sniper", "Breech-Loaded Grenade Launcher", "Fusion Rifle", "Trace Rifle", "Rocket Launcher", "Gernade Launcher", "Sword", "Machine Gun", "Linear Fusion Rifel" };
	
	for (int i = 0; i < numbcommon; i++) {
		randnumb = (rand() % 15);
		weapon = weapontype[randnumb];
		cout << weapontype[randnumb] << endl;
	}
	return 0;
}