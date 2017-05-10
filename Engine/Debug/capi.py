from ctypes import *
capi = cdll.LoadLibrary('./cAPI.dll')

capi.scene_node_find.restype = c_int
capi.mesh_renderer_node_get_mesh.restype = c_char_p

def encode(str):
   return str.encode('utf-8')

class log:
   @staticmethod
   def debug( msg ):
      capi.log_debug( msg )
      
   @staticmethod
   def info( msg ):
      capi.log_info( msg )
      
   @staticmethod
   def warn( msg ):
      capi.log_warn( msg )
      
   @staticmethod
   def error( msg ):
      capi.log_error( msg )
      
   
class cppapi_object:
   def __init__( self, handle ):
      self.handle = handle
      
   def get_handle( self ):
      return self.handle
   
class scene_node(cppapi_object):
   def __init__( self, handle ):
      super(scene_node, self).__init__( handle )
      
   @staticmethod
   def find( name ):
      return scene_node( capi.scene_node_find( name ) )
   
class mesh_renderer_node:
   def __init__( self, handle ):
      self.handle = handle

   def set_mesh( self, mesh, async = False ):
      capi.mesh_renderer_node_set_mesh( self.handle, encode(mesh), async )
      
   def get_mesh( self ):
      return capi.mesh_renderer_node_get_mesh( self.handle )
      
   @staticmethod
   def find( name ):
      return mesh_renderer_node( capi.scene_node_find( encode(name) ) )
      
class application:
   @staticmethod
   def exit():
      capi.application_exit()
      
   @staticmethod
   def load_scene(name):
      capi.application_load_scene(encode(name))