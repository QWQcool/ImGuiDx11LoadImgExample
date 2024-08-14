#include "ImguiAll.h" // 引入imgui的所有头文件
#include <iostream>   // 引入标准输入输出流库
#include <string>     // 引入字符串库
#define ImageIndex 9 // 定义图片索引常量，表示要加载的图片数量

static int sg_imageIndex = 0; // 定义全局变量，用于存储当前显示的图片索引

static void* sg_imageS[ImageIndex] = { nullptr }; // 定义全局数组，用于存储加载的图片指针

// 初始化图片函数，加载所有图片并存储在sg_imageS数组中
void ImageInit()
{
	static bool imageLoaded = false; // 定义静态变量，用于判断图片是否已加载
	if (imageLoaded) // 如果图片已加载，直接返回
	{
		return;
	}
	imageLoaded = true; // 设置图片已加载标志为true

	std::string imgPath = "./src/Image/"; // 定义图片路径前缀

	// 遍历所有图片索引，加载对应的图片
	for (int i = 0; i < ImageIndex; i++)
	{
		std::string imgIndex = imgPath + std::to_string(i + 1) + ".jpg"; // 构建图片完整路径
		sg_imageS[i] = LoadImageEx(imgIndex.c_str()); // 加载图片并存储在数组中
	}
}

// 显示图片的示例函数
void ExampleImageLoad()
{
	ImVec2 center = ImGui::GetMainViewport()->GetCenter(); // 获取主视口中心点坐标

	// 设置窗口位置和大小
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
	ImGui::SetNextWindowSize(ImVec2(960, 720));

	// 开始创建一个新的窗口
	ImGui::Begin("ImageLoad", nullptr);

	// 调用ImageInit函数，初始化图片
	ImageInit();

	// 获取窗口大小
	ImVec2 windowSize = ImGui::GetWindowSize();

	// 设置光标位置，并创建两个按钮，用于上下切换图片
	ImGui::SetCursorPos(ImVec2(windowSize.x * 0.4f, windowSize.y * 0.04f));
	if (ImGui::Button("Up")) // 如果按下上箭头按钮
	{
		sg_imageIndex--; // 图片索引减1
		if (sg_imageIndex < 0) // 如果图片索引小于0
		{
			sg_imageIndex = ImageIndex - 1; // 将图片索引设置为最后一个图片的索引
		}
	}
	ImGui::SameLine(); // 同行显示下一个按钮
	if (ImGui::Button("Down")) // 如果按下下箭头按钮
	{
		sg_imageIndex++; // 图片索引加1
		sg_imageIndex %= ImageIndex; // 对图片索引取模，确保索引在有效范围内
	}

	// 设置图片位置并显示图片
	ImGui::SetCursorPos(ImVec2(0, windowSize.y * 0.08f));
	ImGui::Image(sg_imageS[sg_imageIndex], ImVec2(windowSize.x * 1.0f, windowSize.y * 1.0f));

	// 设置光标位置，并添加分隔线和文本
	ImGui::SetCursorPos(ImVec2(0, windowSize.y * 0.1f));
	ImGui::SeparatorText(u8"ImageShow");

	// 结束窗口创建
	ImGui::End();
}
