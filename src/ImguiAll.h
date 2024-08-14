#pragma once
#include "Imgui/imconfig.h"
#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx11.h"
#include "Imgui/imgui_impl_win32.h"
#include "Imgui/imgui_internal.h"
#include "Imgui/imstb_rectpack.h"
#include "Imgui/imstb_textedit.h"
#include "Imgui/imstb_truetype.h"

#include <d3d11.h>

#pragma comment(lib,"d3d11.lib")

#include <D3DX11.h>
#ifdef _DEBUG
#pragma comment(lib,"d3dx11d.lib")
#else
#pragma comment(lib,"d3dx11.lib")
#endif // DEBUG

//DX11加载图片  具体实现放在Main里了
ID3D11ShaderResourceView* DX11LoadTextureImageFromFile(ID3D11Device* pD3dDevice, const char* lpszFilePath);

void* LoadImageEx(const char* path);

//具体实现代码备份

//ID3D11ShaderResourceView* DX11LoadTextureImageFromFile(ID3D11Device* pD3dDevice, const char* lpszFilePath)
//{
//
//	ID3D11Texture2D* pTexture2D = NULL;
//	D3D11_TEXTURE2D_DESC dec;
//
//
//	HRESULT result;
//	D3DX11_IMAGE_LOAD_INFO loadInfo;
//	ZeroMemory(&loadInfo, sizeof(D3DX11_IMAGE_LOAD_INFO));
//	loadInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE;
//	loadInfo.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//	loadInfo.MipLevels = 0; //这时会产生最大的mipmaps层。 
//	loadInfo.MipFilter = D3DX11_FILTER_LINEAR;
//	result = D3DX11CreateTextureFromFileA(pD3dDevice, lpszFilePath
//		, &loadInfo, NULL, (ID3D11Resource**)(&pTexture2D), NULL);
//	pTexture2D->GetDesc(&dec);
//	if (result != S_OK)
//	{
//		return NULL;
//	}
//
//	ID3D11ShaderResourceView* pFontTextureView = NULL;
//
//	// Create texture view
//	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
//	ZeroMemory(&srvDesc, sizeof(srvDesc));
//	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
//	srvDesc.Texture2D.MipLevels = dec.MipLevels;
//	srvDesc.Texture2D.MostDetailedMip = 0;
//	pD3dDevice->CreateShaderResourceView(pTexture2D, &srvDesc, &pFontTextureView);
//
//
//	return pFontTextureView;
//}
//
//void* LoadImageEx(const char* path)
//{
//	return DX11LoadTextureImageFromFile(g_pd3dDevice, path);
//}