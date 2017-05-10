#include "../launcher/main.h"


#include "../cAPI/capi.h"

#include "../core/multi_thread.hpp"
#include <thread>

#include <Python.h>

int main( int argc, char** argv ) {
	launcher_thread();

	std::this_thread::sleep_for( std::chrono::seconds( 3 ) );


	//Py_Initialize();
	//PyRun_SimpleString("from ctypes import *\ncapi = cdll.LoadLibrary('E:/vs14prjbkp/Engine/Debug/cAPI.dll')\nmr = capi.scene_node_find('n1'.encode())\ncapi.mesh_renderer_node_set_mesh.argtypes = [c_longlong, c_char_p, c_bool]\ncapi.mesh_renderer_node_set_mesh(mr, 'a'.encode(), False)");
	//Py_Finalize();





	long long h = scene_node_find( "n1" );
	long long trh = scene_node_get_transform( h );
	prvec< 3 >::strc r;
	r.d[ 0 ] = 1.0f;
	r.d[ 1 ] = 0.0f;
	r.d[ 2 ] = 0.0f;
	transform_translate( trh, r, 0 );

	std::this_thread::sleep_for( std::chrono::seconds( 2 ) );

}

#ifndef _DEBUG
int __stdcall WinMain( HINSTANCE hin, HINSTANCE prev, LPSTR lp, int cmd ) {
	return main( 1, &lp );
}
#endif // ~_DEBUG