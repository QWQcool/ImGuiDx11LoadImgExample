#include "ImguiAll.h" // ����imgui������ͷ�ļ�
#include <iostream>   // �����׼�����������
#include <string>     // �����ַ�����
#define ImageIndex 9 // ����ͼƬ������������ʾҪ���ص�ͼƬ����

static int sg_imageIndex = 0; // ����ȫ�ֱ��������ڴ洢��ǰ��ʾ��ͼƬ����

static void* sg_imageS[ImageIndex] = { nullptr }; // ����ȫ�����飬���ڴ洢���ص�ͼƬָ��

// ��ʼ��ͼƬ��������������ͼƬ���洢��sg_imageS������
void ImageInit()
{
	static bool imageLoaded = false; // ���徲̬�����������ж�ͼƬ�Ƿ��Ѽ���
	if (imageLoaded) // ���ͼƬ�Ѽ��أ�ֱ�ӷ���
	{
		return;
	}
	imageLoaded = true; // ����ͼƬ�Ѽ��ر�־Ϊtrue

	std::string imgPath = "./src/Image/"; // ����ͼƬ·��ǰ׺

	// ��������ͼƬ���������ض�Ӧ��ͼƬ
	for (int i = 0; i < ImageIndex; i++)
	{
		std::string imgIndex = imgPath + std::to_string(i + 1) + ".jpg"; // ����ͼƬ����·��
		sg_imageS[i] = LoadImageEx(imgIndex.c_str()); // ����ͼƬ���洢��������
	}
}

// ��ʾͼƬ��ʾ������
void ExampleImageLoad()
{
	ImVec2 center = ImGui::GetMainViewport()->GetCenter(); // ��ȡ���ӿ����ĵ�����

	// ���ô���λ�úʹ�С
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
	ImGui::SetNextWindowSize(ImVec2(960, 720));

	// ��ʼ����һ���µĴ���
	ImGui::Begin("ImageLoad", nullptr);

	// ����ImageInit��������ʼ��ͼƬ
	ImageInit();

	// ��ȡ���ڴ�С
	ImVec2 windowSize = ImGui::GetWindowSize();

	// ���ù��λ�ã�������������ť�����������л�ͼƬ
	ImGui::SetCursorPos(ImVec2(windowSize.x * 0.4f, windowSize.y * 0.04f));
	if (ImGui::Button("Up")) // ��������ϼ�ͷ��ť
	{
		sg_imageIndex--; // ͼƬ������1
		if (sg_imageIndex < 0) // ���ͼƬ����С��0
		{
			sg_imageIndex = ImageIndex - 1; // ��ͼƬ��������Ϊ���һ��ͼƬ������
		}
	}
	ImGui::SameLine(); // ͬ����ʾ��һ����ť
	if (ImGui::Button("Down")) // ��������¼�ͷ��ť
	{
		sg_imageIndex++; // ͼƬ������1
		sg_imageIndex %= ImageIndex; // ��ͼƬ����ȡģ��ȷ����������Ч��Χ��
	}

	// ����ͼƬλ�ò���ʾͼƬ
	ImGui::SetCursorPos(ImVec2(0, windowSize.y * 0.08f));
	ImGui::Image(sg_imageS[sg_imageIndex], ImVec2(windowSize.x * 1.0f, windowSize.y * 1.0f));

	// ���ù��λ�ã�����ӷָ��ߺ��ı�
	ImGui::SetCursorPos(ImVec2(0, windowSize.y * 0.1f));
	ImGui::SeparatorText(u8"ImageShow");

	// �������ڴ���
	ImGui::End();
}
