#pragma once
#include "../../util.h"
#include <windows.h>
#include <DXGI1_2.h>
#include <d3d11.h>

class D3DClass
{
public:
	D3D_DRIVER_TYPE         m_type = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL       m_feature = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*           m_pd3dDevice = nullptr;
	ID3D11DeviceContext*    m_Context = nullptr;
	IDXGISwapChain*         m_SwapChain = nullptr;
	ID3D11RenderTargetView* m_RenderTargetView = nullptr;
	D3DClass();
	HRESULT D3DInit(HWND hwnd, ID3D11Device* f_pd3dDevice, D3D_DRIVER_TYPE f_type, D3D_FEATURE_LEVEL f_feature, ID3D11DeviceContext* f_Context, IDXGISwapChain* f_swap, ID3D11RenderTargetView* f_RenderTargetView);
	virtual ~D3DClass();
 
};

