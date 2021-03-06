/*
    EasyHook - The reinvention of Windows API hooking
 
    Copyright (C) 2010 EasyHook

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

    Please visit http://www.codeplex.com/easyhook for more information
    about the project and latest updates.
*/

#ifndef _HOSTCONTROL_H_
#define _HOSTCONTROL_H_

#include "CLRstdafx.h"

//
// Implementation of IHostControl
// - Provides methods for configuring the loading of assemblies, and for determining which hosting interfaces the host supports.
//
class HostControl : public IHostControl
{
public:
	//
	// IHostControl
  //
	HRESULT STDMETHODCALLTYPE GetHostManager( 
								REFIID riid,
								void **ppObject);

        
  HRESULT STDMETHODCALLTYPE SetAppDomainManager( 
								DWORD dwAppDomainID,
								IUnknown *pUnkAppDomainManager);
  
  //
	// IUnknown
  //
	virtual HRESULT STDMETHODCALLTYPE	QueryInterface(const IID &iid, void **ppv);
	virtual ULONG STDMETHODCALLTYPE		AddRef();
	virtual ULONG STDMETHODCALLTYPE		Release();

	HostControl();
	HostControl(IHostAssemblyManager *pHostAssemblyManager);

	virtual ~HostControl();

private:
	long m_cRef;
	IHostAssemblyManager *m_pHostAssemblyManager;

};

#endif