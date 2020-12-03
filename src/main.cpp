#include <iostream>
#include <string>

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
				if ((common < 9 && common > 1) && (legendary < 9 && legendary > 1) && (exotic < 9 && exotic > 1)) {
					//On successful non-out of bounds numbers the code is executed 
					//whatever you're doing 
					ImGui::OpenPopup("Results");
				}
				else {
				ImGui::OpenPopup("Error");
				}
			}
			if (ImGui::BeginPopupModal("Results"))
			{
				std::string result = std::to_string(common + legendary + exotic);
				ImGui::Text(result.c_str());
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
