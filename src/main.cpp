#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <glad/glad.h>

#include "../vendor/imgui_impl_glfw.h"
#include "../vendor/imgui_impl_opengl3.h"

#define GLSL_VERSION "#version 330"

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(600, 600, "Engram Decrypter",
                                          nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Could not create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Could not initialize GLAD" << std::endl;
        return -1;
    }

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = "imgui.ini";
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(GLSL_VERSION);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

		//Init all the variables for tables
		static int common = 0;
		static int legendary = 0;
		static int exotic = 0;
		static std::string weaponname;
		static std::string baseperk;
		static std::string legendaryperk;
		static std::string exoticperk;
		static std::vector<std::vector<std::string>> weapon_buffer;

		static const auto BUTTON_SIZE = ImVec2(120.f, 45.f);

		//The gui begins here
		//There's no auto resizing of windows for the popups, you can work it in if you want to :D 
		float width = ImGui::GetWindowWidth() / 1.35f;
		float height = ImGui::GetWindowHeight() / 1.25f;
		ImGui::SetNextWindowSize(ImVec2(width, height));
		ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2.f, ImGui::GetIO().DisplaySize.y / 2.f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
        ImGui::Begin("Engram Decrypter");
        {
			ImGui::InputInt("Common", &common);
			ImGui::InputInt("Legendary", &legendary);
			ImGui::InputInt("Exotic", &exotic);
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();
			if (ImGui::Button("Decrypt", BUTTON_SIZE)) {
				if ((common >= 0) && (legendary >= 0) && (exotic >= 0)) {
					int randnumb;
					std::string weapon;
					
					std::vector<std::string> perks_per_weapon;
					std::string weapontype[] = { "Auto Rifle", "Pulse Rifle", "Scout Rifle", "Bow", "Sub-machine Gun", "Sidearm", "Handcannon", "Shotgun", "Sniper", "Breech-Loaded Grenade Launcher", "Fusion Rifle", "Trace Rifle", "Rocket Launcher", "Gernade Launcher", "Sword", "Machine Gun", "Linear Fusion Rifel" };
					for (int i = 0; i < common; i++) {
						randnumb = (rand() % 15);
						weapon = weapontype[randnumb];
						std::string perk1[] = { "Full Auto Trigger System", "Burst Fire", "Rangefinder", "Quiver", "Bullet Hose", "Quickdraw", "Deadeye", "Pellets", "No Land Beyond", "Explosive Rounds", "Charge Shot", "Trace Beam", "Danger Zone", "Explosive Rounds", "Melee Weapon", "Spray and Pray", "Charging Coils" };
						perks_per_weapon.push_back(weapontype[randnumb]); 
						perks_per_weapon.push_back(perk1[randnumb]);
						weapon_buffer.push_back(perks_per_weapon);
						perks_per_weapon.clear();
					}
					for (int i = 0; i < legendary; i++) {
						int randnumb2;
						randnumb = (rand() % 15);
						weapon = weapontype[randnumb];
						std::string perk1[] = { "Full Auto Trigger System", "Burst Fire", "Rangefinder", "Quiver", "Bullet Hose", "Quickdraw", "Deadeye", "Pellets", "No Land Beyond", "Explosive Rounds", "Charge Shot", "Trace Beam", "Danger Zone", "Explosive Rounds", "Melee Weapon", "Spray and Pray", "Charging Coils" };
						perks_per_weapon.push_back(weapontype[randnumb]);
						perks_per_weapon.push_back(perk1[randnumb]);
						randnumb2 = (rand() % 32);
						while (randnumb2 == randnumb) {
							randnumb2 = (rand() % 25);
						}
						std::string perk2[] = { "Full Auto Trigger System", "Rangefinder", "Bullet Hose", "Quickdraw", "Deadeye", "Pellets", "No Land Beyond", "Explosive Rounds", "Explosive Rounds", "Spray and Pray", "Zen Moment", "High Caliber Rounds", "Dragonfly", "Outlaw", "Rampage", "Pulse Monitor", "Cluster Bomb", "Auto - loading Holster", "Lightweight Frame", "Assassin's Weapon", "Backup Plan", "Grave Robber", "Mechanized Autoloader", "Opening Shot", "Threat Detector", "Triple Tap" };
						perks_per_weapon.push_back(perk2[randnumb2]);
						weapon_buffer.push_back(perks_per_weapon);
						perks_per_weapon.clear();
					}
					ImGui::OpenPopup("Results");
				}
				else {
				ImGui::OpenPopup("Error");
				}
			}
			if (ImGui::BeginPopupModal("Results"))
			{
				for(std::vector<std::string> i : weapon_buffer){
					for(std::string x : i){
						ImGui::Text(x.c_str());
					}
				}
				if (ImGui::Button("OK")) {
					ImGui::CloseCurrentPopup();
				}
				ImGui::EndPopup();
			}
			if (ImGui::BeginPopupModal("Error"))
			{
				ImGui::Text("The numbers are out of bounds!");
				if (ImGui::Button("OK")) {
					ImGui::CloseCurrentPopup();
				}
				ImGui::EndPopup();
			}
        }
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
