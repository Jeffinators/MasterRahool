#include <iostream>
#include <string>
#include <vector>
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
		string perk1[] = { "Full Auto Trigger System", "Burst Fire", "Rangefinder", "Deadeye", "Bullet Hose", "Quickdraw", "Quiver", "Pellets", "No Land Beyond", "Explosive Rounds", "Charge Shot", "Trace Beam", "Danger Zone", "Melee Weapon", "Spray and Pray", "Charging Coils" };
		cout << weapontype[randnumb] << endl;
		cout << perk1[randnumb];
<<<<<<< HEAD
=======
		/*this is how I output the weapon type, might change all the weapon types to be variables them selves
		that will  then give you the associated perks with them but for now just the name works*/
>>>>>>> 07847c87fec95449d207437af8e6b4b6dfeb2758
	}
	for (int i = 0; i < numblegendary; i++) {
		randnumb = (rand() % 15);
		weapon = weapontype[randnumb];
		cout << weapontype[randnumb] << endl;
		string perk1[] = { "Full Auto Trigger System", "Burst Fire", "Rangefinder", "Deadeye", "Bullet Hose", "Quickdraw", "Quiver", "Pellets", "No Land Beyond", "Explosive Rounds", "Charge Shot", "Trace Beam", "Danger Zone", "Melee Weapon", "Spray and Pray", "Charging Coils", "Zen Moment", "High Caliber Rounds", "Dragonfly", "Outlaw", "Rampage", "Pulse Monitor", "Cluster Bomb", "Auto - loading Holster", "Lightweight Frame", "Assassin's Weapon", "Backup Plan", "Grave Robber", "Mechanized Autoloader", "Opening Shot", "Threat Detector", "Triple Tap" };
		for (int x = randnumb; x < 32; x++) {
			perk1[x] = perk1[x + 1];
		}
		randnumb = (rand() % 31);
		cout << perk1[randnumb] << endl;

	}
	return 0;
}